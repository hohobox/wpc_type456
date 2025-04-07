/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P11.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : To implement specification of E2E Profile 11 driver           **
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
** 1.2.0    22-Mar-2018    Gongbin Lim     Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include file for Profile 11 implementation */
#include "E2E_P11.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P11_C_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P11_C_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P11_C_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P11_C_SW_MAJOR_VERSION                    (1)
#define E2E_P11_C_SW_MINOR_VERSION                    (2)
#define E2E_P11_C_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_P11_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E_P11.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_P11_C_AR_RELEASE_MINOR_VERSION)
#error "E2E_P11.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_P11_C_AR_RELEASE_REVISION_VERSION)
#error "E2E_P11.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_P11_C_SW_MAJOR_VERSION)
#error "E2E_P11.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_P11_C_SW_MINOR_VERSION)
#error "E2E_P11.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_P11_C_SW_PATCH_VERSION)
#error "E2E_P11.c : Mismatch in Patch Version"
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
** Function Name        : E2E_P11CalculateCRC                                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function calculate CRC over received data.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ConfigPtr, DataPtr, Length                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC16         **
*******************************************************************************/
static FUNC(uint8, E2E_CODE) E2E_P11CalculateCRC (
  P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_VAR) ConfigPtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
  VAR(uint16, AUTOMATIC) Length)
{
  VAR(uint8, AUTOMATIC) LucCRCValue;
  VAR(uint8, AUTOMATIC) LucCRCData;
  VAR(uint16, AUTOMATIC) LusOffset;
  VAR(uint16, AUTOMATIC) LusLengthAftCrc = 0x0000U;

  LucCRCValue = E2E_ZERO;

  switch (ConfigPtr->DataIDMode)
  {
    case E2E_P11_DATAID_BOTH:

      /* Take LSB Byte for CRC calculation */
      LucCRCData = (uint8)((ConfigPtr->DataID) & E2E_BYTE_MASK);

      /* Calculate CRC for the LSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST))&LucCRCData, E2E_CRC_LENGTH_ONE,
        E2E_P11_CRC_INIT_VALUE, E2E_FALSE);

      /* Take MSB Byte for CRC calculation */
      LucCRCData = (uint8)(((ConfigPtr->DataID) >> E2E_SHIFT_BY_EIGHT) &
        E2E_BYTE_MASK);

      /* Calculate CRC for the MSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData, E2E_CRC_LENGTH_ONE,
        LucCRCValue, E2E_FALSE);

      break;

    case E2E_P11_DATAID_NIBBLE:

      /* Take LSB Byte for CRC calculation */
      LucCRCData = (uint8)((ConfigPtr->DataID) & E2E_BYTE_MASK);

      /* Calculate CRC for the LSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData,
        E2E_CRC_LENGTH_ONE, E2E_P11_CRC_INIT_VALUE, E2E_FALSE);

      /* Make 0x00 for CRC calculation */
      LucCRCData = E2E_ZERO;

      /* Calculate CRC for the LSB Byte */
      LucCRCValue = Crc_CalculateCRC8 (
        (P2CONST(uint8, AUTOMATIC, E2E_CONST)) &LucCRCData,
        E2E_CRC_LENGTH_ONE, LucCRCValue, E2E_FALSE);

      break;

/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Default switch clause exists for MISRA-C compliance. */
    default: /* Do nothing is AUTOSAR SPEC */

      break;
  } /* End of switch */
  
  /* Compute offset */
  LusOffset = ConfigPtr->CRCOffset / E2E_DIVIDE_BY_EIGHT;
  
  if (Length >= (LusOffset + E2E_HALF_WORD_ONE))
  {
    /* Data length after the position where CRC value exist */
    LusLengthAftCrc = (Length - LusOffset) - E2E_HALF_WORD_ONE;
	
    /* when E2E header does not exist in the beginning of the data */ 
    if (E2E_ZERO < LusOffset)
    {
      /* calculate CRC before CRC position */
      LucCRCValue = Crc_CalculateCRC8 (
        &DataPtr[0], (uint32)LusOffset, LucCRCValue, 
        E2E_FALSE);
      if (Length > (LusOffset + E2E_HALF_WORD_ONE))
      {
        /* calculate CRC after the CRC position */
        LucCRCValue = Crc_CalculateCRC8 (
          &DataPtr[LusOffset + E2E_HALF_WORD_ONE], (uint32)LusLengthAftCrc,
          LucCRCValue, E2E_FALSE);
      }
      else
      {
      }
    } /* End of if (E2E_ZERO < ConfigPtr->Offset) */
    else
    {
      /* calculate CRC for the CRC position */
      LucCRCValue = Crc_CalculateCRC8 (
        &DataPtr[1], (uint32)LusLengthAftCrc,
        LucCRCValue, E2E_FALSE);
    } /* End of else */
  }
  else
  {
    /* Do Nothing */
  }

  return (LucCRCValue);
} /* End of E2E_P11CalculateCRC (
   * P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_VAR) ConfigPtr,
   * P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
   * VAR(uint16, AUTOMATIC) Length)
   */

/*******************************************************************************
** Function Name        : E2E_P11Protect                                      **
**                                                                            **
** Service ID           : 0x3b                                                **
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
** Input Parameters     : ConfigPtr, Length                                   **
**                                                                            **
** InOut Parameters     : StatePtr, DataPtr                                   **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : E2E_P11CalculateCRC        **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P11Protect (
  P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
  VAR(uint16, AUTOMATIC) Length)
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  VAR(uint8, AUTOMATIC) LucNibbleByte;
  VAR(uint8, AUTOMATIC) LucCounterByte;
  VAR(uint16, AUTOMATIC) LusOffset;
  VAR(uint8, AUTOMATIC) LusCrcVal;
  
  LddRetVal = E2E_E_OK;

  /* Verify inputs of the protect function */
  if (
    (NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr) || (NULL_PTR == DataPtr))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if (((ConfigPtr->DataLength) / E2E_DIVIDE_BY_EIGHT) != Length)
  {
    LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else if ((NULL_PTR != DataPtr) && (Length < ((ConfigPtr->CRCOffset / E2E_DIVIDE_BY_EIGHT) + E2E_HALF_WORD_ONE)))
  {
	LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else
  {

    if (E2E_P11_DATAID_NIBBLE == (ConfigPtr->DataIDMode))
    {
      /* Calculate the pointer to Nibble Byte based on the DataIDNibble offset */
	  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
      LucNibbleByte = DataPtr[(ConfigPtr->DataIDNibbleOffset) / E2E_DIVIDE_BY_EIGHT];

      /* Check to find the Offset position of the nibble */
      if (E2E_HALF_WORD_ZERO == ((ConfigPtr->DataIDNibbleOffset) % E2E_DIVIDE_BY_EIGHT))
      {
        /* Update the nibble value in the lower nibble of the nibble byte */
        LucNibbleByte = (uint8)((LucNibbleByte & E2E_HIGH_NIBBLE_MASK) |
        ((uint8)((ConfigPtr->DataID) >> E2E_SHIFT_BY_EIGHT) & E2E_LOW_NIBBLE_MASK));
      } /* End of if E2E_HALF_WORD_ZERO == */
      else
      {
        /* Update the nibble value in the higher nibble of the nibble byte */
        LucNibbleByte = (uint8)((LucNibbleByte & E2E_LOW_NIBBLE_MASK) |
        ((uint8)((ConfigPtr->DataID) >> E2E_SHIFT_BY_FOUR) & E2E_HIGH_NIBBLE_MASK));
      } /* End of else */

      /* store the nibble value in data stream */
      DataPtr[(ConfigPtr->DataIDNibbleOffset) / E2E_DIVIDE_BY_EIGHT] = LucNibbleByte;
    }
    else
    {
    }

    /* Calculate the pointer to Counter Byte based on the counter offset */
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    LucCounterByte = DataPtr[(ConfigPtr->CounterOffset) / E2E_DIVIDE_BY_EIGHT];

    /* Check to find the Offset position of the counter */
    if (E2E_HALF_WORD_ZERO == ((ConfigPtr->CounterOffset) % E2E_DIVIDE_BY_EIGHT))
    {
      /* Update the counter value in the lower nibble of the counter byte */
      LucCounterByte = (uint8)((LucCounterByte & E2E_HIGH_NIBBLE_MASK) |
	  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
        ((StatePtr->Counter) & E2E_LOW_NIBBLE_MASK));
    } /* End of if E2E_HALF_WORD_ZERO == */
    else
    {
      /* Update the counter value in the higher nibble of the counter byte */
      LucCounterByte = (uint8)((LucCounterByte & E2E_LOW_NIBBLE_MASK) |
	  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
        ((uint8)((StatePtr->Counter) << E2E_SHIFT_BY_FOUR) & E2E_HIGH_NIBBLE_MASK));
    } /* End of else */

    /* store the counter value in data stream */
    DataPtr[(ConfigPtr->CounterOffset) / E2E_DIVIDE_BY_EIGHT] = LucCounterByte;
    
    /* Compute offset */
    LusOffset = ConfigPtr->CRCOffset / E2E_DIVIDE_BY_EIGHT;
    
    /* Compute CRC */
    LusCrcVal = E2E_P11CalculateCRC (
      ConfigPtr, (P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST))DataPtr, Length);
    
    /* Write CRC */
    DataPtr[LusOffset] = LusCrcVal;
    
    /* Increment Counter */
    StatePtr->Counter = (((StatePtr->Counter) + E2E_ONE) % E2E_P11_CNT_LIMIT);
  } /* End of if-elseif-else */
  return LddRetVal;
} /* End of E2E_P11Protect (
   * P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
   * P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
   * VAR(uint16, AUTOMATIC) Length)
   */

/*******************************************************************************
** Function Name        : E2E_P11ProtectInit                                  **
**                                                                            **
** Service ID           : 0x3c                                                **
**                                                                            **
** Description          : This function shall initializes the protection      **
**                        state.                                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : StatePtr                                            **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P11ProtectInit (
  P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  
  LddRetVal = E2E_E_OK;

  /* Verify inputs of the protect function */
  if (NULL_PTR == StatePtr)
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  else
  {
    /* Set Counter to 0 */
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    StatePtr->Counter = E2E_ZERO;
  } /* End of if-else */
  
  return LddRetVal;
} /* End of E2E_P11ProtectInit (
   * P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
   */

/*******************************************************************************
** Function Name        : E2E_P11Check                                        **
**                                                                            **
** Service ID           : 0x38                                                **
**                                                                            **
** Description          : This function shall check counter, CRC over         **
**                        received data and determine the check status.       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ConfigPtr, DataPtr, Length                          **
**                                                                            **
** InOut Parameters     : StatePtr                                            **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : E2E_P11CalculateCRC        **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P11Check (
  P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
  VAR(uint16, AUTOMATIC) Length)
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  VAR(uint8, AUTOMATIC) LucDeltaCnt;
  VAR(uint8, AUTOMATIC) LucRcvdCntrVal;
  VAR(uint8, AUTOMATIC) LucNibbleVal;
  VAR(uint8, AUTOMATIC) LusRcvdCrcVal;
  VAR(uint8, AUTOMATIC) LusCptdCrcVal;
  VAR(uint16, AUTOMATIC) LusOffset;
  VAR(uint16, AUTOMATIC) LusCounterOffset;
  VAR(uint16, AUTOMATIC) LusNibbleOffset;
  VAR(boolean, AUTOMATIC) NewDataAvailable;
  
  LddRetVal = E2E_E_OK;
  LusRcvdCrcVal = E2E_ZERO;
  LusCptdCrcVal = E2E_ZERO;
  LucNibbleVal = E2E_ZERO;
  LucRcvdCntrVal = E2E_ZERO;
  NewDataAvailable = E2E_FALSE;
  
  /* Verify inputs of the check function */
  if ((NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  } /* End of if ((NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr)) */
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  else if (((NULL_PTR == DataPtr) && (E2E_HALF_WORD_ZERO != Length)) ||
    ((NULL_PTR != DataPtr) && (E2E_HALF_WORD_ZERO == Length)))
  {
    LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if ((NULL_PTR != DataPtr) && (Length != ((ConfigPtr->DataLength) / E2E_DIVIDE_BY_EIGHT)))
  {
    LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else if ((NULL_PTR != DataPtr) && (Length < ((ConfigPtr->CRCOffset / E2E_DIVIDE_BY_EIGHT) + E2E_HALF_WORD_ONE)))
  {
	LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else
  {
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    if ((NULL_PTR != DataPtr) && (Length == ((ConfigPtr->DataLength) / E2E_DIVIDE_BY_EIGHT)))
    {
      NewDataAvailable = E2E_TRUE;
    }
    else
    /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
    }
  
    if (E2E_TRUE == NewDataAvailable)
    {
      /* Read Nibble */
	  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
      if (E2E_P11_DATAID_NIBBLE == ConfigPtr->DataIDMode)
      {
        LusNibbleOffset = ((ConfigPtr->DataIDNibbleOffset) / E2E_DIVIDE_BY_EIGHT);

        if (E2E_HALF_WORD_ZERO == ((ConfigPtr->DataIDNibbleOffset) % E2E_DIVIDE_BY_EIGHT))
        {
          /* Get the nibble value from the lower nibble of the nibble byte */
          LucNibbleVal = (DataPtr[LusNibbleOffset] & E2E_LOW_NIBBLE_MASK);
        } /* End of if E2E_HALF_WORD_ZERO == */
        else
        {
          /* Get the nibble value from the higher nibble of the nibble byte */
          LucNibbleVal = ((DataPtr[LusNibbleOffset] >> E2E_SHIFT_BY_FOUR) &
          E2E_LOW_NIBBLE_MASK);
        } /* End of else */
      }
      else
      {
      }
  
      /* Read Counter */
      LusCounterOffset = (ConfigPtr->CounterOffset) / E2E_DIVIDE_BY_EIGHT;

      if (E2E_HALF_WORD_ZERO == ((ConfigPtr->CounterOffset) % E2E_DIVIDE_BY_EIGHT))
      {
        /* Get the counter value from the lower nibble of the counter byte */
        LucRcvdCntrVal = DataPtr[LusCounterOffset] & E2E_LOW_NIBBLE_MASK;
      } /* End of if E2E_HALF_WORD_ZERO == */
      else
      {
        /* Get the counter value from the higher nibble of the counter byte */
        LucRcvdCntrVal = (DataPtr[LusCounterOffset] >> E2E_SHIFT_BY_FOUR) &
          E2E_LOW_NIBBLE_MASK;
      } /* End of else */
  
      /* Read CRC */
      LusOffset = (ConfigPtr->CRCOffset) / E2E_DIVIDE_BY_EIGHT;
      LusRcvdCrcVal = DataPtr[LusOffset];
  
      /* Compute CRC */
      LusCptdCrcVal = E2E_P11CalculateCRC (ConfigPtr, DataPtr, Length);
    }
    else
    /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
    }
      /* Do Checks */
    if (E2E_TRUE == NewDataAvailable)
    {
      /* CRC Check */
      if (LusRcvdCrcVal == LusCptdCrcVal)
      {
        /* Nibble Check */
		/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
        if ((ConfigPtr->DataIDMode == E2E_P11_DATAID_NIBBLE) && (LucNibbleVal != (uint8)(((ConfigPtr->DataID) >> E2E_SHIFT_BY_EIGHT) & E2E_LOW_NIBBLE_MASK)))
        {
	      /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          StatePtr->Status = E2E_P11STATUS_ERROR;
        }
        else
        {
          /* Compute Delta Counter */
		  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
          if (LucRcvdCntrVal >= StatePtr->Counter)
          {
            LucDeltaCnt = LucRcvdCntrVal - StatePtr->Counter;
          }
          /* when the received counter is less than the previous counter */
          else
          {
            LucDeltaCnt = 
              ((E2E_P11_CNT_MAX - StatePtr->Counter) + LucRcvdCntrVal) + E2E_ONE;
          }
          /* Counter Check */

          /* When the delta counter value is greater than max delta counter value */
          if (ConfigPtr->MaxDeltaCounter < LucDeltaCnt)
          {
            StatePtr->Status = E2E_P11STATUS_WRONGSEQUENCE;
          }
          /* When the delta counter value is zero */
          else if (E2E_ZERO == LucDeltaCnt)
          {
            StatePtr->Status = E2E_P11STATUS_REPEATED;
          }
          /* When the delta counter value is one */
          else if (E2E_ONE == LucDeltaCnt)
          {
            StatePtr->Status = E2E_P11STATUS_OK;
          }
          /* 
           * When the delta counter value is greater than one and 
           * equal to or less than the max delta counter
           */
          else
          {
            StatePtr->Status = E2E_P11STATUS_OKSOMELOST;
          }
          /* Update the counter value */
          StatePtr->Counter = LucRcvdCntrVal;
        }
      }
      else
      {
		/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
        StatePtr->Status = E2E_P11STATUS_ERROR;
      }
    }
    else
    /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
      /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
      StatePtr->Status = E2E_P11STATUS_NONEWDATA;
    }
  }
  /* return the error flag value */
  return LddRetVal;
} /* 
   * End of E2E_P11Check (
   * P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
   * P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
   * P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
   * VAR(uint16, AUTOMATIC) Length)
   */

/*******************************************************************************
** Function Name        : E2E_P11CheckInit                                    **
**                                                                            **
** Service ID           : 0x39                                                **
**                                                                            **
** Description          : This function shall initializes the check state.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : StatePtr                                            **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P11CheckInit (
  P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  
  LddRetVal = E2E_E_OK;

  /* Verify inputs of the protect function */
  if (NULL_PTR == StatePtr)
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  else
  {
    /* Set Counter to 0x0E */
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    StatePtr->Counter = E2E_P11_CNT_MAX;
    
    /* Set Status to E2E_P11STATUS_ERROR */
    StatePtr->Status = E2E_P11STATUS_ERROR;
  } /* End of if-else */
  
  return LddRetVal;
} /* End of E2E_P11CheckInit (
   * P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
   */

/*******************************************************************************
** Function Name        : E2E_P11MapStatusToSM                                **
**                                                                            **
** Service ID           : 0x3a                                                **
**                                                                            **
** Description          : This function shall maps the check status of        **
**                        Profile 11 to a generic check status, which can be  **
**                        used by E2E state machine check function. The E2E   **
**                        Profile 11 delivers a more fine-granular status, but**
**                        this is not relevant for the E2E state machine.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : CheckReturn, Status                                 **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : E2E_PCheckStatusType                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
FUNC(E2E_PCheckStatusType, E2E_CODE) E2E_P11MapStatusToSM (
  VAR(Std_ReturnType, AUTOMATIC) CheckReturn,
  VAR(E2E_P11CheckStatusType, AUTOMATIC) Status)
{
  VAR(E2E_PCheckStatusType, AUTOMATIC) LenCheckStatus;
  
  /* Verify inputs of the protect function */
  if (E2E_E_OK != CheckReturn)
  {
    LenCheckStatus = E2E_P_ERROR;
  }
  else
  {
    switch (Status)
    {
      case E2E_P11STATUS_OK: 
      case E2E_P11STATUS_OKSOMELOST:
        LenCheckStatus = E2E_P_OK;
        break;
        
      case E2E_P11STATUS_ERROR:
        LenCheckStatus = E2E_P_ERROR;
        break;
        
      case E2E_P11STATUS_REPEATED:
        LenCheckStatus = E2E_P_REPEATED;
        break;
        
      case E2E_P11STATUS_NONEWDATA:
        LenCheckStatus = E2E_P_NONEWDATA;
        break;
        
      case E2E_P11STATUS_WRONGSEQUENCE:
        LenCheckStatus = E2E_P_WRONGSEQUENCE;
        break;
        
      default:
        LenCheckStatus = E2E_P_ERROR;
        break;
    }
  } /* End of if-else */
  
  return LenCheckStatus;
} /* End of E2E_P11MapStatusToSM (
   * VAR(Std_ReturnType, AUTOMATIC) CheckReturn,
   * VAR(E2E_P11CheckStatusType, AUTOMATIC) Status)
   */

#define E2E_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
