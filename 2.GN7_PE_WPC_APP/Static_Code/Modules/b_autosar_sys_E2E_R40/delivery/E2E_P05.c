/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P05.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : To implement specification of E2E Profile 5 driver            **
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
** 1.1.5    26-Jun-2017    Seongmin Kim    Changes made as per #7714          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include file for Profile 5 implementation */
#include "E2E_P05.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P05_C_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P05_C_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P05_C_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P05_C_SW_MAJOR_VERSION                    (1)
#define E2E_P05_C_SW_MINOR_VERSION                    (2)
#define E2E_P05_C_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_P05_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E_P05.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_P05_C_AR_RELEASE_MINOR_VERSION)
#error "E2E_P05.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_P05_C_AR_RELEASE_REVISION_VERSION)
#error "E2E_P05.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_P05_C_SW_MAJOR_VERSION)
#error "E2E_P05.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_P05_C_SW_MINOR_VERSION)
#error "E2E_P05.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_P05_C_SW_PATCH_VERSION)
#error "E2E_P05.c : Mismatch in Patch Version"
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
** Function Name        : E2E_P05CalculateCRC                                 **
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
static FUNC(uint16, E2E_CODE) E2E_P05CalculateCRC (
  P2CONST(E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
  VAR(uint16, AUTOMATIC) Length)
{
  VAR(uint16, AUTOMATIC) LusCRCValue = 0x0000U;
  VAR(uint16, AUTOMATIC) LusOffset;
  VAR(uint16, AUTOMATIC) LusLengthAftCrc = 0x0000U;
  VAR(uint8, AUTOMATIC) LucDataIDHighByte;
  VAR(uint8, AUTOMATIC) LucDataIDLowByte;
  
  /* Compute offset */
  LusOffset = ConfigPtr->Offset / E2E_DIVIDE_BY_EIGHT;
  
  if (Length >= (LusOffset + E2E_P05_CNT_OFS))
  {
    /* Data length after the position where CRC value exist */
    LusLengthAftCrc = (Length - LusOffset) - E2E_P05_CNT_OFS;
	
    /* when E2E header does not exist in the beginning of the data */ 
    if (E2E_ZERO < LusOffset)
    {
      /* calculate CRC before CRC position */
      LusCRCValue = Crc_CalculateCRC16 (
        &DataPtr[0], (uint32)LusOffset, E2E_P05_CRC_START_VAL, 
        E2E_TRUE);
    
      /* calculate CRC after the CRC position */
      LusCRCValue = Crc_CalculateCRC16 (
        &DataPtr[LusOffset + E2E_P05_CNT_OFS], (uint32)LusLengthAftCrc,
        LusCRCValue, E2E_FALSE);
    } /* End of if (E2E_ZERO < ConfigPtr->Offset) */
    else
    {
      /* calculate CRC for the CRC position */
      LusCRCValue = Crc_CalculateCRC16 (
        &DataPtr[LusOffset + E2E_P05_CNT_OFS], (uint32)LusLengthAftCrc,
        E2E_P05_CRC_START_VAL, E2E_TRUE);
    } /* End of else */
  }
  else
  {
      /* Do Nothing */
  }
  
  /* Get the value of low byte of Data ID */
  LucDataIDLowByte = (uint8)(ConfigPtr->DataID & E2E_BYTE_MASK);
  
  /* Calculate CRC for low byte of Data ID */
  LusCRCValue = Crc_CalculateCRC16 (
    &LucDataIDLowByte, (uint32)E2E_ONE, LusCRCValue, E2E_FALSE);
  
  /* Get the value of high byte of Data ID */
  LucDataIDHighByte = 
    (uint8)(((ConfigPtr->DataID) >> E2E_SHIFT_BY_EIGHT) & E2E_BYTE_MASK);
  
  /* Calculate CRC for high byte of Data ID */
  LusCRCValue = Crc_CalculateCRC16 (
    &LucDataIDHighByte, (uint32)E2E_ONE, LusCRCValue, E2E_FALSE);
  
  /* return the result value of CRC calculation */
  return LusCRCValue;
} /* End of E2E_P05CalculateCRC (
   * P2CONST(E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
   * P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
   * VAR(uint16, AUTOMATIC) Length)
   */

/*******************************************************************************
** Function Name        : E2E_P05Protect                                      **
**                                                                            **
** Service ID           : 0x26                                                **
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
**                        Function(s) invoked    : E2E_P05CalculateCRC        **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P05Protect (
  P2CONST(E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
  VAR(uint16, AUTOMATIC) Length)
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  VAR(uint16, AUTOMATIC) LusOffset;
  VAR(uint16, AUTOMATIC) LusCrcVal;
  
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
  else if ((NULL_PTR != DataPtr) && (Length < ((ConfigPtr->Offset / E2E_DIVIDE_BY_EIGHT) + E2E_P05_CNT_OFS)))
  {
	LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    /* Compute offset */
    LusOffset = ConfigPtr->Offset / E2E_DIVIDE_BY_EIGHT;
    
    /* Write Counter */
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    DataPtr[LusOffset + E2E_P05_CNT_OFS] = StatePtr->Counter;
    
    /* Compute CRC */
    LusCrcVal = E2E_P05CalculateCRC (
      ConfigPtr, (P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST))DataPtr, Length);
    
    /* Write CRC in little endian order */
    DataPtr[LusOffset + E2E_P05_CRC_OFS_HIGH_BYTE] = 
      (uint8)((LusCrcVal >> E2E_SHIFT_BY_EIGHT) & E2E_BYTE_MASK);

    DataPtr[LusOffset] = (uint8)(LusCrcVal & E2E_BYTE_MASK);
    
    /* Increment Counter */
    StatePtr->Counter++;
  } /* End of if-elseif-else */
  return LddRetVal;
} /* End of E2E_P05Protect (
   * P2CONST(E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
   * P2VAR(E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
   * VAR(uint16, AUTOMATIC) Length)
   */

/*******************************************************************************
** Function Name        : E2E_P05ProtectInit                                  **
**                                                                            **
** Service ID           : 0x27                                                **
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
FUNC(Std_ReturnType, E2E_CODE) E2E_P05ProtectInit (
  P2VAR(E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
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
} /* End of E2E_P05ProtectInit (
   * P2VAR(E2E_P05ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
   */

/*******************************************************************************
** Function Name        : E2E_P05Check                                        **
**                                                                            **
** Service ID           : 0x28                                                **
**                                                                            **
** Description          : This function shall check counter, CRC over         **
**                        received data and determine the check status.       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ConfigPtr, DataPtr                                  **
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
**                        Function(s) invoked    : E2E_P05CalculateCRC        **
**                                                 E2E_P05CheckStatus         **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_P05Check (
  P2CONST(E2E_P05ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
  VAR(uint16, AUTOMATIC) Length)
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  VAR(uint8, AUTOMATIC) LucDeltaCnt;
  VAR(uint8, AUTOMATIC) LucRcvdCntrVal;
  VAR(uint16, AUTOMATIC) LusOffset;
  VAR(uint16, AUTOMATIC) LusRcvdCrcHighByteVal;
  VAR(uint16, AUTOMATIC) LusRcvdCrcLowByteVal;
  VAR(uint16, AUTOMATIC) LusRcvdCrcVal;
  VAR(uint16, AUTOMATIC) LusCptdCrcVal;
  
  LddRetVal = E2E_E_OK;
  
  /* Verify inputs of the check function */
  if ((NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  } /* End of if ((NULL_PTR == ConfigPtr) || (NULL_PTR == StatePtr)) */
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  else if (((NULL_PTR == DataPtr) && (E2E_ZERO != Length)) ||
    ((NULL_PTR != DataPtr) && (E2E_ZERO == Length)))
  {
    LddRetVal = E2E_E_INPUTERR_WRONG;
  } /* 
     * End of else if ((NULL_PTR == DataPtr && E2E_ZERO != Length) ||
     * (NULL_PTR != DataPtr && E2E_ZERO == Length))
     */
  else if ((NULL_PTR != DataPtr) && 
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
      (((ConfigPtr->DataLength) / E2E_DIVIDE_BY_EIGHT) != Length))
  {
    LddRetVal = E2E_E_INPUTERR_WRONG;
  } /*
     * End of else if (NULL_PTR != DataPtr && 
     * (ConfigPtr->DataLength / E2E_DIVIDE_BY_EIGHT) != Length)
     */
  else if ((NULL_PTR != DataPtr) && (Length < ((ConfigPtr->Offset / E2E_DIVIDE_BY_EIGHT) + E2E_P05_CNT_OFS)))
  {
	LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    if (NULL_PTR == DataPtr)
	/* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
    {
	  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
      StatePtr->Status = E2E_P05STATUS_NONEWDATA;
    }
    else
    {
      /* Compute offset */
	  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
      LusOffset = (ConfigPtr->Offset) / E2E_DIVIDE_BY_EIGHT;
      
      /* Read Counter */
      LucRcvdCntrVal = DataPtr[LusOffset + E2E_P05_CNT_OFS];

      /* Read CRC */

      /* Get the high byte of CRC value on the received data */
      LusRcvdCrcHighByteVal = 
        ((uint16)(DataPtr[LusOffset + E2E_P05_CRC_OFS_HIGH_BYTE])) << 
        E2E_SHIFT_BY_EIGHT;
      
      /* Get the low byte of CRC value on the received data */
      LusRcvdCrcLowByteVal = (uint16)(DataPtr[LusOffset]);

      /* 
       * Get the CRC value from high and low byte of CRC position on received 
       * data 
       */
      LusRcvdCrcVal = 
        (LusRcvdCrcHighByteVal & E2E_HIGH_BYTE_MASK) |
        (LusRcvdCrcLowByteVal & E2E_BYTE_MASK);
        
      /* Compute CRC */
      LusCptdCrcVal = E2E_P05CalculateCRC (ConfigPtr, DataPtr, Length);

      /* Do checks */
      
      /* when the received counter is not equal to the computated counter */ 
      if (LusRcvdCrcVal != LusCptdCrcVal)
      {
		/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
        StatePtr->Status = E2E_P05STATUS_ERROR;
      } /* End of else if (LusRcvdCrcVal != LusCptdCrcVal) */
      else
      {
        /* Compute local variable Delta Counter */
        
        /* 
         * When the received counter is equal to or greater than the previous
         * counter       
         */
		/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
        if (LucRcvdCntrVal >= StatePtr->Counter)
        {
          LucDeltaCnt = LucRcvdCntrVal - StatePtr->Counter;
        }
        /* when the received counter is less than the previous counter */
        else
        {
          LucDeltaCnt = 
            ((E2E_P05_CNT_MAX - StatePtr->Counter) + LucRcvdCntrVal) + E2E_ONE;
        }
        
        /* When the delta counter value is greater than max delta counter value */
        if (ConfigPtr->MaxDeltaCounter < LucDeltaCnt)
        {
          StatePtr->Status = E2E_P05STATUS_WRONGSEQUENCE;
        }
        /* When the delta counter value is zero */
        else if (E2E_ZERO == LucDeltaCnt)
        {
          StatePtr->Status = E2E_P05STATUS_REPEATED;
        }
        /* When the delta counter value is one */
        else if (E2E_ONE == LucDeltaCnt)
        {
          StatePtr->Status = E2E_P05STATUS_OK;
        }
        /* 
         * When the delta counter value is greater than one and 
         * equal to or less than the max delta counter
         */
        else
        {
          StatePtr->Status = E2E_P05STATUS_OKSOMELOST;
        }

        /* Update the counter value */
        StatePtr->Counter = LucRcvdCntrVal;
      }
    }
  } /* End of else */
  
  /* return the error flag value */
  return LddRetVal;
} /* 
   * End of E2E_P05Check (
   * P2VAR(E2E_P05ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
   * P2VAR(E2E_P05ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
   * P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data)
   */

/*******************************************************************************
** Function Name        : E2E_P05CheckInit                                    **
**                                                                            **
** Service ID           : 0x29                                                **
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
FUNC(Std_ReturnType, E2E_CODE) E2E_P05CheckInit (
  P2VAR(E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
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
    /* Set Counter to 0xFF */
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    StatePtr->Counter = E2E_P05_CNT_MAX;
    
    /* Set Status to E2E_P05STATUS_ERROR */
    StatePtr->Status = E2E_P05STATUS_ERROR;
  } /* End of if-else */
  
  return LddRetVal;
} /* End of E2E_P05CheckInit (
   * P2VAR(E2E_P05CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
   */

/*******************************************************************************
** Function Name        : E2E_P05MapStatusToSM                                **
**                                                                            **
** Service ID           : 0x2a                                                **
**                                                                            **
** Description          : This function shall maps the check status of        **
**                        Profile 5 to a generic check status, which can be   **
**                        used by E2E state machine check function. The E2E   **
**                        Profile 5 delivers a more fine-granular status, but **
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
FUNC(E2E_PCheckStatusType, E2E_CODE) E2E_P05MapStatusToSM (
  VAR(Std_ReturnType, AUTOMATIC) CheckReturn,
  VAR(E2E_P05CheckStatusType, AUTOMATIC) Status)
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
      case E2E_P05STATUS_OK: 
      case E2E_P05STATUS_OKSOMELOST:
        LenCheckStatus = E2E_P_OK;
        break;
        
      case E2E_P05STATUS_ERROR:
        LenCheckStatus = E2E_P_ERROR;
        break;
        
      case E2E_P05STATUS_REPEATED:
        LenCheckStatus = E2E_P_REPEATED;
        break;
        
      case E2E_P05STATUS_NONEWDATA:
        LenCheckStatus = E2E_P_NONEWDATA;
        break;
        
      case E2E_P05STATUS_WRONGSEQUENCE:
        LenCheckStatus = E2E_P_WRONGSEQUENCE;
        break;
        
      default:
        LenCheckStatus = E2E_P_ERROR;
        break;
    }
  } /* End of if-else */
  
  return LenCheckStatus;
} /* End of E2E_P05MapStatusToSM (
   * VAR(Std_ReturnType, AUTOMATIC) CheckReturn,
   * VAR(E2E_P05CheckStatusType, AUTOMATIC) Status)
   */
   
#define E2E_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

