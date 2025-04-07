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
**  SRC-MODULE: IoHwAb_DigIn.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : APIs implementation for IoHwAb module                         **
**              IoHwAb_DigInRead                                              **
**              IoHwAb_DigInReadRaw                                           **
**              IoHwAb_DigInReadDirect                                        **
**              IoHwAb_DigInWrite                                             **
**              IoHwAb_DigInFreeze                                            **
**              IoHwAb_DigInUnfreeze                                          **
**              IoHwAb_DigInIsFrozen                                          **
**              IoHwAb_DigInInit1                                             **
**              IoHwAb_DigInInit2                                             **
**              IoHwAb_DigInH2L                                               **
**              IoHwAb_DigInSampleLP                                          **
**              IoHwAb_DigInReadHwInputs                                      **
**              IoHwAb_DigInDebounce                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.15.3.0  08-Aug-2022   Yangjin    #35064                                  **
** 1.15.1    24-Dec-2021   Yangjin    #33411                                  **
** 1.15.0.2  09-Sep-2021   Yangjin    #31974                                  **
** 1.10.1    04-Aug-2020   Yangjin    #24902                                  **
** 1.0.7     12-DEC-2015   Jongyoung  1.Debounce logic bug fix (from RTRT)    **
** 1.0.6     16-SEP-2015   Jongyoung  1.MISRA-C Rule violation fix            **
** 1.0.5     25-Mar-2015   Jongyoung  1.Manage the single module version      **
** 1.0.2     27-Sep-2014   Jongyoung  1. Polyspace result Adaption            **
** 1.0.1     19-Sep-2014   Sinil      1. Remove #if releated to               **
**                                    IOHWAB_USE_DIG_IN_FAST                  **
** 1.0.0     07-Mar-2014   Sinil      Initial version                         **
*******************************************************************************/
/* polyspace-begin MISRA-C3:17.8 [Justified:Unset] "Not a defect" */
/* polyspace-begin MISRA-C3:11.5 [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] "It depends on the configuration to execute reversing by the polarity." */
/* polyspace-begin DEFECT:USELESS_IF [Justified:Low] "validated by test cases. It works as intended." */
/* polyspace-begin MISRA-C3:D4.14 [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-begin MISRA-C3:2.1 [Justified:Low] "It depends on the configuration." */
/* polyspace-begin MISRA-C3:14.3 [Justified:Low] "It depends on the configuration." */
/* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations>It depends on the configuration to execute reversing by the polarity.*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb_DigIn.h"
#include "IoHwAb_Config.h"
#include "HwResource.h"
#include "Rte_IoHwAb.h"
#if (IOHWAB_USE_MC33972 == STD_ON)
#include "IoHwAb_DigInMC33972.h"
#endif /* (IOHWAB_USE_MC33972 == STD_ON) */
#if (IOHWAB_USE_DIG_SUP_SWT == STD_ON)
#include "IoHwAb_InputSupply.h"
#endif /* (IOHWAB_USE_DIG_SUP_SWT == STD_ON) */
#include "SchM_IoHwAb.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (IOHWAB_USE_DIG_IN == STD_ON)
#define IOHWAB_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
VAR(uint8, IOHWAB_VAR) IoHwAb_DigInFilteringStart;
#define IOHWAB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */
/* polyspace-begin RTE:UNR [Not a defect:Unset] "Reachable code" */
/*******************************************************************************
**                      Function Prototypes                                  **
*******************************************************************************/
#if (IOHWAB_USE_DIG_IN == STD_ON)
static inline FUNC(IoHwAb_LevelType, IOHWAB_CODE) IoHwAb_DigInGetFiltVal(uint8 Buf);
static inline FUNC(IoHwAb_LevelType, IOHWAB_CODE) IoHwAb_DigInGetRawVal(uint8 Buf);
static inline FUNC(IoHwAb_LevelType, IOHWAB_CODE) IoHwAb_DigInGetFreezeVal(uint8 Buf);
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : IoHwAb_DigInGetFiltVal                              **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
static inline FUNC(IoHwAb_LevelType, IOHWAB_CODE) IoHwAb_DigInGetFiltVal(uint8 Buf)
{
    IoHwAb_LevelType LucValue = (Buf & IOHWAB_DIGIN_FILT_BIT_MASK) >> 4;
	return LucValue;
}
/*******************************************************************************
** Function Name        : IoHwAb_DigInGetRawVal                               **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
static inline FUNC(IoHwAb_LevelType, IOHWAB_CODE) IoHwAb_DigInGetRawVal(uint8 Buf)
{
    IoHwAb_LevelType LucValue = (Buf & IOHWAB_DIGIN_RAW_BIT_MASK) >> 5;
	return LucValue;
}
/*******************************************************************************
** Function Name        : IoHwAb_DigInGetFreezeVal                            **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
static inline FUNC(IoHwAb_LevelType, IOHWAB_CODE) IoHwAb_DigInGetFreezeVal(uint8 Buf)
{
    IoHwAb_LevelType LucValue = (Buf & IOHWAB_DIGIN_FREEZE_BIT_MASK) >> 6;
	return LucValue;
}
/*******************************************************************************
** Function Name        : IoHwAb_DigInRead                                    **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer                         **
**                        Function(s) invoked    :                            **
**                          IoHwAb_DigInGetFiltVal,                        **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInRead(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_LevelType, AUTOMATIC, IOHWAB_APPL_DATA) Level)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if ((Level != NULL_PTR) && (ChIdx < IoHwAb_GddNumDigInLgc))
  {
    *Level = IoHwAb_DigInGetFiltVal(IoHwAb_GaaDigInFiltBuffer[ChIdx]);
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInReadRaw                                 **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer                         **
**                        Function(s) invoked    :                            **
**                          IoHwAb_DigInGetRawVal,                         **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInReadRaw(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_LevelType, AUTOMATIC, IOHWAB_APPL_DATA) Level)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if ((Level != NULL_PTR) && ( ChIdx < IoHwAb_GddNumDigInLgc ))
  {
    *Level = IoHwAb_DigInGetRawVal(IoHwAb_GaaDigInFiltBuffer[ChIdx]);
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInReadDirect                              **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInInfos,                             **
**                          IoHwAb_GaaGenInfos                                **
**                        Function(s) invoked    :                            **
**                          Dio_ReadChannel                                   **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInReadDirect(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_LevelType, AUTOMATIC, IOHWAB_APPL_DATA) Level)
{
  if ( ChIdx < IoHwAb_GddNumDigInLgc )
  {
    IoHwAb_IndexType LucChRefIdx = IoHwAb_GaaDigInInfos[ChIdx].ddRefChIdx;

    if (Level != NULL_PTR)
    {
      if (Dio_ReadChannel(IoHwAb_GaaGenInfos[LucChRefIdx].ddDioChType) == STD_LOW)
      {
        if (IoHwAb_GaaGenInfos[LucChRefIdx].ucPolar == IOHWAB_POL_LOW)
        {
          *Level = IOHWAB_HIGH;
        }
        else
        {
          *Level = IOHWAB_LOW;
        }
      }
      else
      {
        if (IoHwAb_GaaGenInfos[LucChRefIdx].ucPolar == IOHWAB_POL_LOW)
        {
          *Level = IOHWAB_LOW;
        }
        else
        {
          *Level = IOHWAB_HIGH;
        }
      }
    }
  }
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInWrite                                   **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx, Level                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer,                        **
**                          IoHwAb_GaaDigInInfos                              **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInWrite(IoHwAb_IndexType ChIdx,
  IoHwAb_LevelType Level)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if ( ChIdx < IoHwAb_GddNumDigInLgc )
  {
    IoHwAb_GaaDigInFiltBuffer[ChIdx] &= IOHWAB_DIGIN_RESULT_COUNT_CLEAR_BIT_MASK;
    if (Level != 0)
    {
      IoHwAb_GaaDigInFiltBuffer[ChIdx]
        |= (IOHWAB_DIGIN_RESULT_SET_BIT_MASK
        | (IoHwAb_GaaDigInInfos[ChIdx].ucFiltConst & IOHWAB_DIGIN_COUNT_BIT_MASK));
    }
    else
    {
      IoHwAb_GaaDigInFiltBuffer[ChIdx]
        |= IoHwAb_GaaDigInInfos[ChIdx].ucFiltConst >> 4;
    }
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInFreeze                                  **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer                         **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInFreeze(IoHwAb_IndexType ChIdx)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if ( ChIdx < IoHwAb_GddNumDigInLgc )
  {
    IoHwAb_GaaDigInFiltBuffer[ChIdx] |= IOHWAB_DIGIN_FREEZE_BIT_MASK;
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInUnfreeze                                **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer                         **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInUnfreeze(IoHwAb_IndexType ChIdx)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if (ChIdx < IoHwAb_GddNumDigInLgc)
  {
    IoHwAb_GaaDigInFiltBuffer[ChIdx] &= IOHWAB_DIGIN_UNFREEZE_BIT_MASK;
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInIsFrozen                                **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : BufIdx, PortIdx, ChIdx                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Result                                              **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer                         **
**                        Function(s) invoked    :                            **
**                          IoHwAb_DigInGetFreezeVal,                      **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInIsFrozen(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_BoolType, AUTOMATIC, IOHWAB_APPL_DATA) DigInResult)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if ((DigInResult != NULL_PTR) && (ChIdx < IoHwAb_GddNumDigInLgc))
  {
    *DigInResult = (IoHwAb_DigInGetFreezeVal(IoHwAb_GaaDigInFiltBuffer[ChIdx]) == 0)
      ? IOHWAB_FALSE : IOHWAB_TRUE;
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInInit1                                   **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInRawBuffer,                         **
**                          IoHwAb_GaaDigInFiltBuffer                         **
**                        Function(s) invoked    :                            **
**                          bidigdir_ReadHWInputs                             **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInInit1(void)
{
  IoHwAb_IndexType LucIdx;
  IoHwAb_IndexType LucBufIdx;
  IoHwAb_IndexType LucShiftBit;

  /* acquisition of non multiplexed digital inputs   */
  IoHwAb_DigInReadHwInputs(FALSE);

  /* loop for updating all the inputs */
  for (LucIdx = 0U; LucIdx < IoHwAb_GddNumDigInLgc; LucIdx++)
  {
    LucBufIdx = LucIdx / 8U;
    LucShiftBit = LucIdx % 8U;

    /* check the raw value */
    if( (IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucRawBuffer 
      & ((uint8)(1U << LucShiftBit))) != 0U )
    {
      /* the raw value is 1 */
      /* update the counter 4 bits,bit R and bit F */
      IoHwAb_GaaDigInFiltBuffer[LucIdx] = 0x31U;
    }
    else
    {
      /* the raw value is 0 */
      /* update the counter 4 bits,bit R and bit F */
      IoHwAb_GaaDigInFiltBuffer[LucIdx] = 0x0EU;
    }
  }
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInInit2                                   **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer,                        **
**                          IoHwAb_GaaDigInInfos,                             **
**                          IoHwAb_DigInFilteringStart                        **
**                        Function(s) invoked    :                            **
**                          IoHwAb_InputSupplyDigitalControl,                 **
**                          IoHwAb_DigInGetFiltVal                         **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInInit2(void)
{
  IoHwAb_IndexType LucIdx;

  /* switch off switched battery for digital inputs */
  #if (IOHWAB_USE_DIG_SUP_SWT == STD_ON)
  IoHwAb_InputSupplyDigitalControl(TRUE, FALSE);
  #endif /* (IOHWAB_USE_DIG_SUP_SWT == STD_ON) */

  /* loop for updating all the inputs */
  for (LucIdx = 0; LucIdx < IoHwAb_GddNumDigInLgc; LucIdx++)
  {
    IoHwAb_GaaDigInFiltBuffer[LucIdx] &= 0xF0U;

    /* check the filtered value */
    if ( (IoHwAb_DigInGetFiltVal(IoHwAb_GaaDigInFiltBuffer[LucIdx])) != 0U )
    {
      /* the filtered value is 1 */
      /* update the counter 4 bits keep unchanged R and F bits*/
      IoHwAb_GaaDigInFiltBuffer[LucIdx]
        |= IoHwAb_GaaDigInInfos[LucIdx].ucFiltConst & IOHWAB_DIGIN_COUNT_BIT_MASK;
    }
    else
    {
      /* the filtered value is 0 */
      /* update only the 4 bits of the counter (bits R and F are already 0) */
      IoHwAb_GaaDigInFiltBuffer[LucIdx]
        |= IoHwAb_GaaDigInInfos[LucIdx].ucFiltConst >> 4;
    }
  }

  IoHwAb_DigInFilteringStart = FALSE;
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInH2L                                     **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer,                        **
**                          IoHwAb_GaaDigInInfos                              **
**                        Function(s) invoked    :                            **
**                          IoHwAb_DigInGetFiltVal,                        **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInH2L(void)
{
  IoHwAb_IndexType LucIdx;

  for (LucIdx = 0; LucIdx < IoHwAb_GddNumDigInLgc; LucIdx++)
  {
    /* service to protect from preemption and interrupts */
    SchM_Enter_IoHwAb_IoHwAbProtection();

    /* reset the counter value */
    IoHwAb_GaaDigInFiltBuffer[LucIdx] &= 0xF0U;

    if (IoHwAb_DigInGetFiltVal(IoHwAb_GaaDigInFiltBuffer[LucIdx]) != 0U )
    {
      /* set the counter to the maximum increment */
      IoHwAb_GaaDigInFiltBuffer[LucIdx]
        |= IoHwAb_GaaDigInInfos[LucIdx].ucFiltConst & IOHWAB_DIGIN_COUNT_BIT_MASK;
    }
    else
    {
      /* set the counter to the minimum decrement */
      IoHwAb_GaaDigInFiltBuffer[LucIdx]
        |= IoHwAb_GaaDigInInfos[LucIdx].ucFiltConst >> 4;
    }

    SchM_Exit_IoHwAb_IoHwAbProtection();
  }
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInSampleLP                                **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInFiltBuffer,                        **
**                          IoHwAb_GaaDigInRawBuffer                          **
**                        Function(s) invoked    :                            **
**                          IoHwAb_DigInGetFreezeVal,                      **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInSampleLP(void)
{
  IoHwAb_IndexType LucIdx;
  IoHwAb_IndexType LucBufIdx;
  uint8 LucShiftBit;
  IoHwAb_IndexType LucStartIdx = IoHwAb_GddNumDigInFastHigh;
  IoHwAb_IndexType LucEndIdx = LucStartIdx + IoHwAb_GddNumDigInSlow;

  for (LucIdx = LucStartIdx; LucIdx < LucEndIdx; LucIdx++)
  {
    LucBufIdx   = (IoHwAb_IndexType)(LucIdx / 8U);
    LucShiftBit = (uint8)(LucIdx % 8U);

    /* disable interrupts */
    SchM_Enter_IoHwAb_IoHwAbProtection();

    /* update only if bit 6 E/D is 0 */
    if (IoHwAb_DigInGetFreezeVal(IoHwAb_GaaDigInFiltBuffer[LucIdx]) == 0)
    {
      /* copy the raw data into the local mirror */
      if ( (IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucRawBuffer 
         & ((uint8)(1U << LucShiftBit)) ) != 0U )
      {
        IoHwAb_GaaDigInFiltBuffer[LucIdx] |= IOHWAB_DIGIN_RAW_BIT_MASK;
      }
      else
      {
        IoHwAb_GaaDigInFiltBuffer[LucIdx] &= (uint8)((uint8)0xFFU & ~((uint8)IOHWAB_DIGIN_RAW_BIT_MASK));
      }
    }
    /*  enable interrupts */
    SchM_Exit_IoHwAb_IoHwAbProtection();
  }
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInReadHwInputs                            **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInInfos,                             **
**                          IoHwAb_GaaGenInfos,                               **
**                          IoHwAb_GaaDigInRawBuffer                          **
**                        Function(s) invoked    :                            **
**                          Dio_ReadChannel,                                  **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInReadHwInputs(boolean blFast)
{
  IoHwAb_IndexType LucIdx;
  IoHwAb_IndexType LucEndIdx;
  IoHwAb_IndexType LucBufIdx;
  IoHwAb_IndexType LucChRefIdx;
  uint8 LucShiftBit;
  uint8 LucShiftValue;
  Dio_LevelType LddDioChValue;

  if (blFast != 0U)
  {
     LucEndIdx = IoHwAb_GddNumDigInFast;
  }
  else
  {
  #if (IOHWAB_USE_MC33972 == STD_ON)
    LucEndIdx = IoHwAb_GddNumDigInLgc - IoHwAb_GddNumDigInMC33972Lgc;
  #else /* (IOHWAB_USE_MC33972 == STD_ON) */
    LucEndIdx = IoHwAb_GddNumDigInLgc;
  #endif /* (IOHWAB_USE_MC33972 == STD_ON) */
  }

  /* loop to read all ports with digital inputs */
  for (LucIdx = 0; LucIdx < LucEndIdx; LucIdx++)
  {
    LucBufIdx     = (IoHwAb_IndexType)(LucIdx / 8U);
    LucShiftBit   = (uint8)(LucIdx % 8U);
    LucShiftValue = (uint8)(1U << LucShiftBit);
    LucChRefIdx   = IoHwAb_GaaDigInInfos[LucIdx].ddRefChIdx;

    /* service to protect from preemption and interrupts */
    SchM_Enter_IoHwAb_IoHwAbProtection();

    LddDioChValue = Dio_ReadChannel(IoHwAb_GaaGenInfos[LucChRefIdx].ddDioChType);

    IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucTempBuffer
      &= (uint8)(~(LucShiftValue));
    IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucRawBuffer
      &= (uint8)(~(LucShiftValue));

    if (LddDioChValue == 0)
    {
      if (IoHwAb_GaaGenInfos[LucChRefIdx].ucPolar == IOHWAB_POL_LOW)
      {
        IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucRawBuffer
          |= LucShiftValue;
      }
    }
    else
    {
      IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucTempBuffer
        |= LucShiftValue;
      if (IoHwAb_GaaGenInfos[LucChRefIdx].ucPolar == IOHWAB_POL_HIGH)
      {
        IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucRawBuffer
          |= LucShiftValue;
      }
    }

    /* service to exit the protected area */
    SchM_Exit_IoHwAb_IoHwAbProtection();
  }
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IoHwAb_DigInDebounce                                **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaDigInInfos,                             **
**                          IoHwAb_GaaGenInfos,                               **
**                          IoHwAb_GaaDigInRawBuffer                          **
**                        Function(s) invoked    :                            **
**                          Dio_ReadChannel,                                  **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
FUNC(void,IOHWAB_CODE)IoHwAb_DigInDebounce(IoHwAb_IndexType Idx,
  IoHwAb_IndexType NumFilt)
{
  uint8 LucDecInc;
  uint8 LucDecInc_4;
  IoHwAb_IndexType LucBufIdx;
  uint8 LucShiftBit;
  uint8 LucRawValue;
  uint8 LucTempFiltValue;
  uint16 LusIdx = Idx;
  uint16 LusNumFilt = NumFilt;
  boolean LblUpdate = FALSE;

  /* calculate the absolute index of the last input to process */
  LusNumFilt += LusIdx;

  /* loop to process all required inputs */
  for (; LusIdx < LusNumFilt; LusIdx++)
  {
    LucBufIdx = (IoHwAb_IndexType)(LusIdx / 8U);
    LucShiftBit = (uint8)(LusIdx % 8U);

    if ((IoHwAb_GaaDigInRawBuffer[LucBufIdx].ucRawBuffer & ((uint8)(1U << LucShiftBit))) != 0U)
    {
      LucRawValue = 1U;
    }
    else
    {
      LucRawValue = 0U;
    }
    /* This section decides if update process is necessary or not. */
    if (LucRawValue != IoHwAb_DigInGetFiltVal(IoHwAb_GaaDigInFiltBuffer[LusIdx])){
      LblUpdate = TRUE;
    }
    if (LucRawValue != IoHwAb_DigInGetRawVal(IoHwAb_GaaDigInFiltBuffer[LusIdx])){
      LblUpdate = TRUE;
    }

    /*update and process only if bit with the current raw value are different to bit with filtered value */
    if (LblUpdate == TRUE)
    {
      /* update and process only if bit 6 E/D is 0*/
      if (IoHwAb_DigInGetFreezeVal(IoHwAb_GaaDigInFiltBuffer[LusIdx]) == 0U)
      {
        /* initialization filtering or task filtering */
        if (IoHwAb_DigInFilteringStart != 0U)
        {
          /* initialization filtering */
          LucDecInc = 0x01U;
          LucDecInc_4 = 0x0EU;
        }
        else
        {
          /* task filtering */
          LucDecInc = IoHwAb_GaaDigInInfos[LusIdx].ucFiltConst & IOHWAB_DIGIN_COUNT_BIT_MASK;
          LucDecInc_4 = IoHwAb_GaaDigInInfos[LusIdx].ucFiltConst >> 4;
        }

        /* service to protect from preemption and interrupts */
        SchM_Enter_IoHwAb_IoHwAbProtection();

        /* copy the current counter into static mirror */
        LucTempFiltValue = IoHwAb_GaaDigInFiltBuffer[LusIdx];

        /* copy the raw data into the local mirror */
        if (LucRawValue != 0U)
        {
          /* this is an increment */
          /* set the raw bit to 1 */
          LucTempFiltValue |= IOHWAB_DIGIN_RAW_BIT_MASK;

          /* filter the data only if this is a filtered input for 0->1 transition */
          if ( LucDecInc_4 != 0U )
          {
            /* this is a filtered input */
            if (IoHwAb_DigInGetFiltVal(LucTempFiltValue) != 0U)
            {
              /* input already 1 */
              /* set the counter to the maximum increment */
              LucTempFiltValue &= 0xF0U;
              LucTempFiltValue |= LucDecInc;
            }
            else
            {
              /* input not 1 yet, increment the filter */
              LucTempFiltValue++;

              /* if bit 4 = 1, transition */
              if (IoHwAb_DigInGetFiltVal(LucTempFiltValue) != 0U)
              {
                /* set the counter to the maximum increment */
                LucTempFiltValue &= 0xF0U;
                LucTempFiltValue |= LucDecInc;
              }
            }
          }
          else
          {
            /* not filtered for 0->1 transition */
            /* set the F bit and the counter to the maximum increment */
            LucTempFiltValue &= 0xF0U;
            LucTempFiltValue |= (0x10U | LucDecInc);
          }/* filtered or not */
        }
        else
        {
          /* this is a decrement */
          LucTempFiltValue &= (uint8)((uint8)0xFFU & ~((uint8)IOHWAB_DIGIN_RAW_BIT_MASK));
          /* filter the data only if this is a filtered input */
          if(LucDecInc != 0U)
          {
            /* this is filtered for 1->0 transition */
            if (IoHwAb_DigInGetFiltVal(LucTempFiltValue) == 0U)
            {
              /* input already 0 */
              /* set the counter to the minimum decrement */
              LucTempFiltValue &= 0xF0U;
              LucTempFiltValue |= LucDecInc_4;
            }
            else
            {
              /* input not 0 yet, decrement the filter */
              LucTempFiltValue--;

              /* if bit 4 = 0, transition */
              if ( IoHwAb_DigInGetFiltVal(LucTempFiltValue) == 0U)
              {
                /* set the counter to the minimum decrement */
                LucTempFiltValue &= 0xF0U;
                LucTempFiltValue |= LucDecInc_4;
              }
            }
          }
          else
          {
            /* this is not filtered for 1->0 transition */
            /* reset the F bit and set the counter to the minimum decrement */
            LucTempFiltValue &= 0xE0U;
            LucTempFiltValue |= LucDecInc_4;
          }/* filtered or not */
        }/* increment or decrement */

        /* update the variable only if the byte is modified */
        if (IoHwAb_GaaDigInFiltBuffer[LusIdx] != LucTempFiltValue)
        {
          /* update the filtered input value */
          IoHwAb_GaaDigInFiltBuffer[LusIdx] = LucTempFiltValue;
        }

        /* service to exit the protected area */
        SchM_Exit_IoHwAb_IoHwAbProtection();
      }
    }
  }
}
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */
/* polyspace-end RTE:UNR [Not a defect:Unset] "Reachable code" */
/* polyspace-end MISRA-C3:17.8 [Justified:Unset] "Not a defect" */
/* polyspace-end MISRA-C3:11.5 [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-end DEFECT:DEAD_CODE [Justified:Low] "It depends on the configuration to execute reversing by the polarity." */
/* polyspace-end DEFECT:USELESS_IF [Justified:Low] "validated by test cases. It works as intended." */
/* polyspace-end MISRA-C3:D4.14 [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-end MISRA-C3:2.1 [Justified:Low] "It depends on the configuration." */
/* polyspace-end MISRA-C3:14.3 [Justified:Low] "It depends on the configuration." */
/* polyspace:end<CERT-C:MSC12-C:Not a defect:Justify with annotations>It depends on the configuration to execute reversing by the polarity.*/
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
