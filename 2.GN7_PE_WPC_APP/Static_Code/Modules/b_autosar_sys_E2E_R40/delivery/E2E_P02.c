/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P02.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : To implement specification of E2E Profile 2 driver            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date           By              Description                        **
********************************************************************************
** 1.2.5    09-Aug-2022    Seungjin Noh    Change made as per #36855          **
** 1.2.4    23-Dec-2021    Gongbin Lim     Change made as per #33551          **
** 1.2.3    22-Jul-2020    Gongbin Lim     Change made as per #24829          **
** 1.2.2    24-Oct-2018    Gongbin Lim     Change made as per #14435          **
** 1.2.1    18-Jun-2018    Gongbin Lim     Change made as per #12704          **
** 1.2.0    22-Mar-2018    Gongbin Lim     Changes made as per #11718         **
** 1.1.3    07-Dec-2016    Seongmin Kim    Changes made as per #6489, #6490,  **
**                                           and #6886                        **
** 1.1.2    04-Oct-2016    Seongmin Kim    Changes made as per #6006 and #6159**
** 1.1.1    19-Jul-2016    Seongmin Kim    Change made as per #5576           **
** 1.1.0    05-Apr-2016    Hoi-Min Kim     Changes made as per #3543, #3554,  **
**                         Seongmin Kim      #4296, #4342, #4346, #4391, and  **
**                                           #4560                            **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include file for Profile 2 implementation */
#include "E2E_P02.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P02_C_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P02_C_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P02_C_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P02_C_SW_MAJOR_VERSION                    (1)
#define E2E_P02_C_SW_MINOR_VERSION                    (2)
#define E2E_P02_C_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_P02_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E_P02.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_P02_C_AR_RELEASE_MINOR_VERSION)
#error "E2E_P02.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_P02_C_AR_RELEASE_REVISION_VERSION)
#error "E2E_P02.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_P02_C_SW_MAJOR_VERSION)
#error "E2E_P02.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_P02_C_SW_MINOR_VERSION)
#error "E2E_P02.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_P02_C_SW_PATCH_VERSION)
#error "E2E_P02.c : Mismatch in Patch Version"
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define E2E_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
** Function Name        : E2E_P02CheckStatus                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function check status of received data.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Counter, Config                                     **
**                                                                            **
** InOut Parameters     : State                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
static FUNC(void, E2E_CODE) E2E_P02CheckStatus (
  P2CONST(E2E_P02ConfigType, AUTOMATIC, E2E_VAR) Config,
  P2VAR(E2E_P02ReceiverStateType, AUTOMATIC, E2E_VAR) State,
  VAR(uint8, AUTOMATIC) Counter)
{
  VAR(uint8, AUTOMATIC) LucDeltaCounter;

  /* Check whether the data received is the first data */
  if (E2E_TRUE == State->WaitForFirstData)
  {
    /* Change the status of the first data flag to FALSE */
    State->WaitForFirstData = E2E_FALSE;

    /* Reset the MaxDeltaCounter */
    State->MaxDeltaCounter = Config->MaxDeltaCounterInit;

    /* Update the LastValidCounter with the currently received counter values */
    State->LastValidCounter = Counter;

    /* Set the status to E2E_P02STATUS_INITIAL */
    State->Status = E2E_P02STATUS_INITIAL;
  } /* End of if (E2E_TRUE == State->WaitForFirstData) */
  else
  {
    /*
     * Find the difference in counter value from the received one and the
     * last valid counter received
     */
    if (Counter >= (State->LastValidCounter))
    {
      LucDeltaCounter = Counter - (State->LastValidCounter);
    }
    else
    {
      LucDeltaCounter = (E2E_P02_CNT_LIMIT + Counter) - 
        (State->LastValidCounter);
    }

    /*
     * If there are no difference in counter value then the data is
     * repeated
     */
    if (E2E_ZERO == LucDeltaCounter)
    {
      State->Status = E2E_P02STATUS_REPEATED;
    }
    /* If the difference is one then a new data is avaialble */
    else if (E2E_ONE == LucDeltaCounter)
    {
      /* Reset the Delta counter */
      State->MaxDeltaCounter = Config->MaxDeltaCounterInit;

      /* Update the last valid counter with the current counter value */
      State->LastValidCounter = Counter;

      /* Update the lost data count to Zero */
      State->LostData = E2E_ZERO;

      /* Set the status to E2E_P02STATUS_OK */
      State->Status = E2E_P02STATUS_OK;
    }
    /* If the difference is more than ONE then some data is lost */
    else if (LucDeltaCounter <= State->MaxDeltaCounter)
    {
      /* Reset the Delta counter */
      State->MaxDeltaCounter = Config->MaxDeltaCounterInit;

      /* Update the last valid counter with the current counter value */
      State->LastValidCounter = Counter;

      /* Update the lost data count */
      State->LostData = LucDeltaCounter - E2E_ONE;

      /* Set the status to E2E_P02STATUS_OKSOMELOST */
      State->Status = E2E_P02STATUS_OKSOMELOST;
    }
    /* Check If the difference is more than the allowed value */
    else
    {
      /* Update the status to indicate that the data sequence is not correct */
      State->Status = E2E_P02STATUS_WRONGSEQUENCE;
    }
  } /* End of else */
} /* End of E2E_P02CheckStatus (
   * P2VAR(E2E_P02ConfigType, AUTOMATIC, E2E_VAR) Config,
   * P2VAR(E2E_P02ReceiverStateType, AUTOMATIC, E2E_VAR) State,
   * VAR(uint8, AUTOMATIC) Counter)
   */

/*******************************************************************************
** Function Name        : E2E_P02Protect                                      **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function shall write counter in Data,and       **
**                        finally compute CRC over DataID and Data and write  **
**                        CRC in data. And then it shall increment the        **
**                        counter.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Config                                              **
**                                                                            **
** InOut Parameters     : State, Data                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P02Protect (
  P2CONST(E2E_P02ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
  P2VAR(E2E_P02SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
{
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValP02Protect;
  VAR(uint8, AUTOMATIC) LucCRCP02Protect;

  LddReturnValP02Protect = E2E_E_OK;

  /* Check for the invalid input parameters */
  if ((NULL_PTR == Config) || (NULL_PTR == State) || (NULL_PTR == Data))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddReturnValP02Protect = E2E_E_INPUTERR_NULL;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if ((E2E_P02_MIN_DATA_LENGTH_LIMIT > Config->DataLength) ||
           (E2E_P02_MAX_DATA_LENGTH_LIMIT < Config->DataLength) ||
           (E2E_P02_CNT_MAX < Config->MaxDeltaCounterInit))
  {
    /* if MaxDeltaCounterInit value exceeds 0x0F
     * and datalength is more than E2E_P02_MAX_DATA_LENGTH_LIMIT
     */
    LddReturnValP02Protect = E2E_E_INPUTERR_WRONG;
  }
  else if (E2E_ZERO_BYTE != ((Config->DataLength) % E2E_DIVIDE_BY_EIGHT))
  {
    LddReturnValP02Protect = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    /* Update the State Counter */
    if (E2E_P02_CNT_MAX > State->Counter)
    {
      State->Counter++;
    }
    else
    {
      State->Counter = E2E_ZERO;
    }

    /* Update the Counter Byte */
    Data[E2E_BYTE_ONE] = (Data[E2E_BYTE_ONE] & E2E_HIGH_NIBBLE_MASK) |
      (uint8)(State->Counter & E2E_LOW_NIBBLE_MASK);

    /* Calculate the CRC for the Data and the counter and update the CRC byte */
    LucCRCP02Protect = Crc_CalculateCRC8H2F(
      (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &Data[E2E_BYTE_ONE],
      (uint32)(((uint32)Config->DataLength / (uint32)E2E_DIVIDE_BY_EIGHT) -
      (uint32)E2E_BYTE_ONE), E2E_P02_CRC_INIT_VALUE, E2E_TRUE);

    /* Calculate the CRC for the DataId and update the CRC byte */
    LucCRCP02Protect = Crc_CalculateCRC8H2F(
      (P2CONST(uint8, AUTOMATIC, E2E_CONST))
      &(Config->DataIDList[State->Counter]), (uint32)E2E_BYTE_ONE,
      LucCRCP02Protect, E2E_FALSE);

    Data[E2E_ZERO] = LucCRCP02Protect;
  } /* End of if-elseif-else */
  return (LddReturnValP02Protect);
} /* End of E2E_P02Protect (
   * P2VAR(E2E_P02ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
   * P2VAR(E2E_P02SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
   */

/*******************************************************************************
** Function Name        : E2E_P02Check                                        **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : This function shall check counter, CRC over         **
**                        received data and determine the check status.       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Config, Data                                        **
**                                                                            **
** InOut Parameters     : State                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
**                                                 E2E_P02CheckStatus         **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P02Check (
  P2CONST(E2E_P02ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
  P2VAR(E2E_P02ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
{
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValP02Check;
  VAR(uint8, AUTOMATIC) LucCounterval;
  VAR(uint8, AUTOMATIC) LucCRCP02Check;

  LddReturnValP02Check = E2E_E_OK;

  /* Check for the invalid input parameters */
  if ((NULL_PTR == Config) || (NULL_PTR == State) || (NULL_PTR == Data))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddReturnValP02Check = E2E_E_INPUTERR_NULL;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if ((E2E_P02_MIN_DATA_LENGTH_LIMIT > Config->DataLength) ||
           (E2E_P02_MAX_DATA_LENGTH_LIMIT < Config->DataLength) ||
           (E2E_P02_CNT_MAX < Config->MaxDeltaCounterInit))
  {
    /* if MaxDeltaCounterInit value exceeds 0x0F
     * and datalength is more than E2E_P02_MAX_DATA_LENGTH_LIMIT
     */
    LddReturnValP02Check = E2E_E_INPUTERR_WRONG;
  }
  else if (E2E_ZERO_BYTE != ((Config->DataLength) % E2E_DIVIDE_BY_EIGHT))
  {
    LddReturnValP02Check = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    if (E2E_P02_CNT_MAX > State->MaxDeltaCounter)
    {
      State->MaxDeltaCounter++;
    }
    else
    {
    }
    /* Check for the availability of New Data */
    if (E2E_TRUE == State->NewDataAvailable)
    {
      /* Get the counter value from the Received data bytes */
      LucCounterval = (Data[E2E_BYTE_ONE] & E2E_LOW_NIBBLE_MASK);

      /*
       * Calculate the CRC for the Data and the counter and update the
       * CRC byte
       */
      LucCRCP02Check = Crc_CalculateCRC8H2F(
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &Data[E2E_BYTE_ONE],
        (uint32)(((uint32)Config->DataLength / (uint32)E2E_DIVIDE_BY_EIGHT) -
        (uint32)E2E_BYTE_ONE), E2E_P02_CRC_INIT_VALUE, E2E_TRUE);

      /* Calculate the CRC for the DataId and update the CRC byte */
      LucCRCP02Check = Crc_CalculateCRC8H2F(
        (P2CONST(uint8, AUTOMATIC, E2E_CONST))
        &(Config->DataIDList[LucCounterval]), (uint32)E2E_BYTE_ONE,
        LucCRCP02Check, E2E_FALSE);

      /*
       * check the CRC present in the Received data and the calculated CRC are
       * equal
       */
      if (Data[E2E_ZERO] == LucCRCP02Check)
      {
        E2E_P02CheckStatus(Config, State, LucCounterval);
      }
      else
      {
        /* Update the status to indicate the received data is not correct */
        State->Status = E2E_P02STATUS_WRONGCRC;
      }
    } /* End of if (E2E_TRUE == State->NewDataAvailable) */
    else
    {
      /* Update the status to indicate that the there are no new data */
      State->Status = E2E_P02STATUS_NONEWDATA;
    }
  } /* End of else-elseif-else */
  return (LddReturnValP02Check);
} /* End of E2E_P02Check (
   * P2VAR(E2E_P02ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
   * P2VAR(E2E_P02ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
   */

#define E2E_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

