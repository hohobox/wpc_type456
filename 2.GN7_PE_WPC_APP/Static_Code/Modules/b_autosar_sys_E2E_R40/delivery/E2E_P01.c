/*******************************************************************************
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P01.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : To implement specification of E2E Profile 1 driver            **
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
** 1.1.2    20-Oct-2016    Seongmin Kim    Changes made as per #6006, #6007,  **
**                                           #6008, and #6159                 **
** 1.1.1    19-Jul-2016    Seongmin Kim    Change made as per #5576           **
** 1.1.0    05-Apr-2016    Hoi-Min Kim     Changes made as per #3543, #3554,  **
**                         Seongmin Kim      #4296, #4342, #4343, #4346,      **
**                                           and #4391                        **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include file for Profile 1 implementation */
#include "E2E_P01.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P01_C_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P01_C_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P01_C_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P01_C_SW_MAJOR_VERSION                    (1)
#define E2E_P01_C_SW_MINOR_VERSION                    (2)
#define E2E_P01_C_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_P01_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E_P01.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_P01_C_AR_RELEASE_MINOR_VERSION)
#error "E2E_P01.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_P01_C_AR_RELEASE_REVISION_VERSION)
#error "E2E_P01.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_P01_C_SW_MAJOR_VERSION)
#error "E2E_P01.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_P01_C_SW_MINOR_VERSION)
#error "E2E_P01.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_P01_C_SW_PATCH_VERSION)
#error "E2E_P01.c : Mismatch in Patch Version"
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
** Function Name        : E2E_P01CalculateCRC                                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function calculate CRC over received data.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Config, Counter, Data                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
static FUNC(uint8, E2E_CODE) E2E_P01CalculateCRC (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_VAR) Config,
  VAR(uint8, AUTOMATIC) Counter,
  P2VAR(uint8, AUTOMATIC, E2E_VAR) Data)
{
  VAR(uint16, AUTOMATIC) LusDataLength;
  VAR(uint8, AUTOMATIC) LucCRCValue;
  VAR(uint8, AUTOMATIC) LucCRCBytePos;
  VAR(uint8, AUTOMATIC) LucCRCData;
  VAR(uint16, AUTOMATIC) LusDataLengthAfterCrc;

  LucCRCValue = E2E_ZERO;
  LusDataLength = (Config->DataLength) / E2E_DIVIDE_BY_EIGHT;

  switch (Config->DataIDMode)
  {
    case E2E_P01_DATAID_BOTH:

      /* Take LSB Byte for CRC calculation */
      LucCRCData = (uint8)((Config->DataID) & E2E_BYTE_MASK);

      /* Calculate CRC for the LSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST))&LucCRCData, E2E_CRC_LENGTH_ONE,
        E2E_P01_CRC_INIT_VALUE, E2E_FALSE);

      /* Take MSB Byte for CRC calculation */
      LucCRCData = (uint8)(((Config->DataID) >> E2E_SHIFT_BY_EIGHT) &
        E2E_BYTE_MASK);

      /* Calculate CRC for the MSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData, E2E_CRC_LENGTH_ONE,
        LucCRCValue, E2E_FALSE);

      break;

    case E2E_P01_DATAID_LOW:

      /* Take LSB Byte for CRC calculation */
      LucCRCData = (uint8)((Config->DataID) & E2E_BYTE_MASK);

      /* Calculate CRC for the LSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData,
        E2E_CRC_LENGTH_ONE, E2E_P01_CRC_INIT_VALUE, E2E_FALSE);

      break;

    case E2E_P01_DATAID_ALT:

      if (E2E_ZERO == (Counter % E2E_TWO))
      {
        /* Take LSB Byte for CRC calculation */
        LucCRCData = (uint8)((Config->DataID) & E2E_BYTE_MASK);

        /* Calculate CRC for the LSB Byte */
        LucCRCValue = Crc_CalculateCRC8 (
          (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData,
          E2E_CRC_LENGTH_ONE, E2E_P01_CRC_INIT_VALUE, E2E_FALSE);
      } /* End of if (E2E_ZERO == (Counter % E2E_TWO)) */
      else
      {
        /* Take MSB Byte for CRC calculation */
        LucCRCData = (uint8)(((Config->DataID) >> E2E_SHIFT_BY_EIGHT) &
          E2E_BYTE_MASK);

        /* Calculate CRC for the MSB Byte */
        LucCRCValue = Crc_CalculateCRC8 (
          (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData,
          E2E_CRC_LENGTH_ONE, E2E_P01_CRC_INIT_VALUE, E2E_FALSE);
      } /* End of else */

      break;

/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Default switch clause exists for MISRA-C compliance. */
    default: /* Do nothing is AUTOSAR SPEC */

      break;
  } /* End of switch */

  /* Find the CRC Byte Position */
  LucCRCBytePos = (uint8)(Config->CRCOffset / E2E_DIVIDE_BY_EIGHT);

  /* Check if CRC Byte Position is not ZERO */
  if (E2E_ZERO < LucCRCBytePos)
  {
    /* Calculate the CRC for the Data Byte before the CRC Byte */
    LucCRCValue = Crc_CalculateCRC8 (
      (P2CONST(uint8, AUTOMATIC, E2E_CONST)) Data,
      (uint32)LucCRCBytePos, LucCRCValue, E2E_FALSE);
  } /* End of if (E2E_ZERO < LucCRCBytePos) */
  
  /* Check if the CRC byte postion is the last byte in the Data Stream */
  if (LucCRCBytePos < (uint8)(LusDataLength - E2E_HALF_WORD_ONE))
  {
	if (LusDataLength > ((uint16)LucCRCBytePos + E2E_HALF_WORD_ONE))
	{
      LusDataLengthAfterCrc = LusDataLength - (uint16)LucCRCBytePos - E2E_HALF_WORD_ONE;
      /* Calculate the CRC for the Data Byte after the CRC Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &Data[LucCRCBytePos + E2E_ONE],
        (uint32)LusDataLengthAfterCrc, LucCRCValue, E2E_FALSE);
	}  /* End of if (LucCRCBytePos < */
	else
	{
	}
  } 
    
  LucCRCValue = LucCRCValue ^ E2E_P01_CRC_XOR_VALUE;

  return (LucCRCValue);
} /* End of E2E_P01CalculateCRC (
   * P2VAR(E2E_P01ConfigType, AUTOMATIC, E2E_VAR) Config,
   * VAR(uint8, AUTOMATIC) Counter,
   * P2VAR(uint8, AUTOMATIC, E2E_VAR) Data)
   */

/*******************************************************************************
** Function Name        : E2E_P01CheckStatus                                  **
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
** Return value         : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
static FUNC(void, E2E_CODE) E2E_P01CheckStatus (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_VAR) Config,
  P2VAR(E2E_P01ReceiverStateType, AUTOMATIC, E2E_VAR) State,
  VAR(uint8, AUTOMATIC) Counter)
{
  VAR(uint8, AUTOMATIC) LucDeltaCounter;

  /* Check whether the data received is the first data */
  if (E2E_TRUE == State->WaitForFirstData)
  {
    /* Change the status of the first data flag to E2E_FALSE */
    State->WaitForFirstData = E2E_FALSE;

    /* Reset the MaxDeltaCounter */
    State->MaxDeltaCounter = Config->MaxDeltaCounterInit;

    /*
     * Update the LastValidCounter with the currently received
     * counter values
     */
    State->LastValidCounter = Counter;

    /* Set the status to E2E_P01STATUS_INITIAL */
    State->Status = E2E_P01STATUS_INITIAL;
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
      LucDeltaCounter = (E2E_P01_CNT_LIMIT + Counter) -
        (State->LastValidCounter);
    }

    /* If there are no difference in counter value then the data is repeated */
    if (E2E_ZERO == LucDeltaCounter)
    {
      State->Status = E2E_P01STATUS_REPEATED;
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

      /* Set the status to E2E_P01STATUS_OK */
      State->Status = E2E_P01STATUS_OK;
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

      /* Set the status to E2E_P01STATUS_OKSOMELOST */
      State->Status = E2E_P01STATUS_OKSOMELOST;
    }
    /* Check If the difference is more than the allowed value */
    else
    {
      /* Update the status to indicate that the data sequence is not correct */
      State->Status = E2E_P01STATUS_WRONGSEQUENCE;
    }
  } /* End of else */
} /* End of E2E_P01CheckStatus (
   * P2VAR(E2E_P01ConfigType, AUTOMATIC, E2E_VAR) Config,
   * P2VAR(E2E_P01ReceiverStateType, AUTOMATIC, E2E_VAR) State,
   * VAR(uint8, AUTOMATIC) Counter)
   */

/*******************************************************************************
** Function Name        : E2E_P01Protect                                      **
**                                                                            **
** Service ID           : 0x01                                                **
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
**                        Function(s) invoked    : E2E_P01CalculateCRC        **
*******************************************************************************/


FUNC(Std_ReturnType, E2E_CODE) E2E_P01Protect (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
  P2VAR(E2E_P01SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
{
  VAR(uint8, AUTOMATIC) LucCounterByte;
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValP01Protect;
  VAR(uint8, AUTOMATIC) LucCRCP01Protect;

  LddReturnValP01Protect = E2E_E_OK;

  /* Check for the invalid input parameters */
  if ((NULL_PTR == Config) || (NULL_PTR == State) || (NULL_PTR == Data))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddReturnValP01Protect = E2E_E_INPUTERR_NULL;
  }
  /* Check for the ranges of input parameters */
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if ((E2E_TWO < (uint8)(Config->DataIDMode)) ||
           (E2E_P01_MIN_DATA_LENGTH_LIMIT > Config->DataLength) ||
           (E2E_P01_MAX_DATA_LENGTH_LIMIT < Config->DataLength) ||
           (E2E_P01_CNT_MAX < Config->MaxDeltaCounterInit) ||
           (Config->CounterOffset > (Config->DataLength - E2E_BIT_FOUR)) ||
           (Config->CRCOffset > (Config->DataLength - E2E_BIT_EIGHT)))
  {
    LddReturnValP01Protect = E2E_E_INPUTERR_WRONG;
  }
  /* Check for alignment of input parameters */
  else if ((E2E_ZERO_BYTE != ((Config->CRCOffset) % E2E_DIVIDE_BY_EIGHT)) ||
           (E2E_ZERO_BYTE != ((Config->CounterOffset) % E2E_DIVIDE_BY_FOUR)) ||
           (E2E_ZERO_BYTE != ((Config->DataLength) % E2E_DIVIDE_BY_EIGHT)))
  {
    LddReturnValP01Protect = E2E_E_INPUTERR_WRONG;
  }
  /* Check whether high byte is used when DataIDMode is E2E_P01_DATAID_LOW */
  else if ((E2E_P01_DATAID_LOW == (Config->DataIDMode)) &&
           (E2E_P01_DATAID_LOW_LIMIT < (Config->DataID)))
  {
    LddReturnValP01Protect = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    /* Calculate the pointer to Counter Byte based on the counter offset */
    LucCounterByte = Data[(Config->CounterOffset) / E2E_DIVIDE_BY_EIGHT];

    /* Check to find the Offset position of the counter */
    if (E2E_HALF_WORD_ZERO == ((Config->CounterOffset) % E2E_DIVIDE_BY_EIGHT))
    {
      /* Update the counter value in the lower nibble of the counter byte */
      LucCounterByte = (uint8)((LucCounterByte & E2E_HIGH_NIBBLE_MASK) |
        ((State->Counter) & E2E_LOW_NIBBLE_MASK));
    } /* End of if E2E_HALF_WORD_ZERO == */
    else
    {
      /* Update the counter value in the higher nibble of the counter byte */
      LucCounterByte = (uint8)((LucCounterByte & E2E_LOW_NIBBLE_MASK) |
        ((uint8)((State->Counter) << E2E_SHIFT_BY_FOUR) & E2E_HIGH_NIBBLE_MASK));
    } /* End of else */

    /* store the counter value in data stream */
    Data[(Config->CounterOffset) / E2E_DIVIDE_BY_EIGHT] = LucCounterByte;
    
    /*
     * Call E2E_P01CalculateCRC to calculate the CRC of Data ID and
     * the Data Bytes and update the uint8     in the data stream
     */
    LucCRCP01Protect = E2E_P01CalculateCRC (Config, State->Counter, Data);

    Data[(Config->CRCOffset) / E2E_DIVIDE_BY_EIGHT] = LucCRCP01Protect;

    State->Counter = (((State->Counter) + E2E_ONE) % E2E_P01_CNT_LIMIT);
  } /* End of if-elseif-else */
  return (LddReturnValP01Protect);
} /* End of E2E_P01Protect (
   * P2VAR(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
   * P2VAR(E2E_P01SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
   */

/*******************************************************************************
** Function Name        : E2E_P01Check                                        **
**                                                                            **
** Service ID           : 0x02                                                **
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
**                        Function(s) invoked    : E2E_P01CalculateCRC        **
**                                                 E2E_P01CheckStatus         **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P01Check (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
  P2VAR(E2E_P01ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
{
  VAR(Std_ReturnType, AUTOMATIC) LddReturnValP01Check;
  VAR(uint16, AUTOMATIC) LusCounterOffset;
  VAR(uint8, AUTOMATIC) LucCounterVal;
  VAR(uint8, AUTOMATIC) LucCRCP01Check;
  VAR(uint8, AUTOMATIC) LucCRCReturn;

  LddReturnValP01Check = E2E_E_OK;

  /* Check for the invalid input parameters */
  if ((NULL_PTR == Config) || (NULL_PTR == State) || (NULL_PTR == Data))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddReturnValP01Check = E2E_E_INPUTERR_NULL;
  }
  /* Check for the ranges of input parameters */
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if ((E2E_TWO < (uint8)(Config->DataIDMode)) ||
           (E2E_P01_MIN_DATA_LENGTH_LIMIT > Config->DataLength) ||
           (E2E_P01_MAX_DATA_LENGTH_LIMIT < Config->DataLength) ||
           (E2E_P01_CNT_MAX < Config->MaxDeltaCounterInit) ||
           (Config->CounterOffset > (Config->DataLength - E2E_BIT_FOUR)) ||
           (Config->CRCOffset > (Config->DataLength - E2E_BIT_EIGHT)))
  {
    LddReturnValP01Check = E2E_E_INPUTERR_WRONG;
  }
  /* Check for alignment of input parameters */
  else if ((E2E_ZERO_BYTE != ((Config->CRCOffset) % E2E_DIVIDE_BY_EIGHT)) ||
           (E2E_ZERO_BYTE != ((Config->CounterOffset) % E2E_DIVIDE_BY_FOUR)) ||
           (E2E_ZERO_BYTE != ((Config->DataLength) % E2E_DIVIDE_BY_EIGHT)))
  {
    LddReturnValP01Check = E2E_E_INPUTERR_WRONG;
  }
  else if ((E2E_P01_DATAID_LOW == (Config->DataIDMode)) &&
           (E2E_P01_DATAID_LOW_LIMIT < (Config->DataID)))
  {
    LddReturnValP01Check = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    State->MaxDeltaCounter++;

    if (E2E_P01_CNT_MAX < (State->MaxDeltaCounter))
    {
      /* If MaxDeltaCounter counter value exceeds 0x0E */
      State->MaxDeltaCounter = E2E_P01_CNT_MAX;
    }
    else
    {
    }

    /* Check for the availability of New Data */
    if (E2E_TRUE == State->NewDataAvailable)
    {
      LusCounterOffset = (Config->CounterOffset) / E2E_DIVIDE_BY_EIGHT;

      if (E2E_HALF_WORD_ZERO == ((Config->CounterOffset) % E2E_DIVIDE_BY_EIGHT))
      {
        /* Get the counter value from the lower nibble of the counter byte */
        LucCounterVal = Data[LusCounterOffset] & E2E_LOW_NIBBLE_MASK;
      } /* End of if E2E_HALF_WORD_ZERO == */
      else
      {
        /* Get the counter value from the higher nibble of the counter byte */
        LucCounterVal = (Data[LusCounterOffset] >> E2E_SHIFT_BY_FOUR) &
          E2E_LOW_NIBBLE_MASK;
      } /* End of else */

      /* Get the uint8     from the Receved data bytes */
      LucCRCP01Check = Data[((Config->CRCOffset) / E2E_DIVIDE_BY_EIGHT)];
      
      /*
       * Calculate the CRC for the received data and check the CRC present in
       * the Received data and the calculated CRC are equal
       */
      LucCRCReturn = E2E_P01CalculateCRC(Config, LucCounterVal, Data);

      if (LucCRCReturn == LucCRCP01Check)
      {
        E2E_P01CheckStatus(Config, State, LucCounterVal);
      } /* End of if */
      else
      {
        /* Update the status to indicate the received data is not correct */
        State->Status = E2E_P01STATUS_WRONGCRC;
      }
    } /* End of if */
    else
    {
      /* Update the status to indicate that there are no new data */
      State->Status = E2E_P01STATUS_NONEWDATA;
    }
  } /* End of if-elseif-else */
  return (LddReturnValP01Check);
} /* End of E2E_P01Check (
   * P2VAR(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
   * P2VAR(E2E_P01ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
   */

#define E2E_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
