/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_SM.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : To implement specification of E2E State machine driver        **
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
** 1.1.5    18-Jul-2017  Gongbin Lim     Changes made as per #8045            **
** 1.1.5    18-May-2017  Gongbin Lim     Changes made as per #8045            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include file for State Machine implementation */
#include "E2E_SM.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_SM_C_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_SM_C_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_SM_C_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_SM_C_SW_MAJOR_VERSION                    (1)
#define E2E_SM_C_SW_MINOR_VERSION                    (2)
#define E2E_SM_C_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_SM_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E_SM.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_SM_C_AR_RELEASE_MINOR_VERSION)
#error "E2E_SM.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_SM_C_AR_RELEASE_REVISION_VERSION)
#error "E2E_SM.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_SM_C_SW_MAJOR_VERSION)
#error "E2E_SM.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_SM_C_SW_MINOR_VERSION)
#error "E2E_SM.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_SM_C_SW_PATCH_VERSION)
#error "E2E_SM.c : Mismatch in Patch Version"
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
** Function Name        : E2E_SMAddStatus                                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function shall process E2E_SMCheck's           **
**                        ProfileStatus.                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ProfileStatus, StatePtr, ConfigPtr                  **
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
static FUNC(void, E2E_CODE) E2E_SMAddStatus (
  VAR(E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
  )
{
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(uint8, AUTOMATIC) LucCount;

  /* Write ProfileStatus to ProfileStatusWindow */
  /* polyspace<RTE:IDP:Not a defect:Justify with annotations> Range check by E2E_SMCheck */
  StatePtr->ProfileStatusWindow[StatePtr->WindowTopIndex] = (uint8)ProfileStatus;
  
  /* Initialize Loop_Index value */
  LucIndex = E2E_ZERO;
  
  /* Initialize Count value */
  LucCount = E2E_ZERO;

  /* Check the number of elements in ProfileStatusWindow[] with values
   * E2E_P_OK
   */
  while (LucIndex < (ConfigPtr->WindowSize))
  {
    /* polyspace<RTE:IDP:Not a defect:Justify with annotations> Range check by while-condition */
    if ((VAR(uint8, AUTOMATIC))E2E_P_OK == (StatePtr->ProfileStatusWindow[LucIndex]))
    {
      LucCount++;
    }
    else
    {
    }
    LucIndex++;
  }
   
  /* Write the number of elements in ProfileStatusWindow[] with values
   * E2E_P_OK
   */
  StatePtr->OkCount = LucCount;
  
  /* Initialize Loop_Index value */
  LucIndex = E2E_ZERO;
  
  /* Initialize Count value */
  LucCount = E2E_ZERO;
  
 /* Check the number of elements in ProfileStatusWindow[] with values
  * E2E_P_ERROR
  */
  while (LucIndex < (ConfigPtr->WindowSize))
  {
    /* polyspace<RTE:IDP:Not a defect:Justify with annotations> Range check by while-condition */
    if ((VAR(uint8, AUTOMATIC))E2E_P_ERROR == (StatePtr->ProfileStatusWindow[LucIndex]))
    {
      LucCount++;
    }
    else
    {
    }
    LucIndex++;
  }
  
  /* Write the number of elements in ProfileStatusWindow[] with values
   * E2E_P_ERROR
   */
  StatePtr->ErrorCount = LucCount;
  
  /* Adjust WindowTopIndex */
  if ((StatePtr->WindowTopIndex) == ((ConfigPtr->WindowSize) - E2E_ONE))
  {
    StatePtr->WindowTopIndex = E2E_ZERO;
  }
  else
  {
    StatePtr->WindowTopIndex++;
  }
  /* End of if-else */
  
  return;
} /* 
   * End of E2E_SMAddStatus (
   * VAR(E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
   * P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
   * P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr)
   */

/*******************************************************************************
** Function Name        : E2E_SMClearStatus                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This function shall clear E2E_SMCheck's             **
**                        ProfileStatus.                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ProfileStatus, StatePtr , ConfigPtr                 **
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
static FUNC(void, E2E_CODE) E2E_SMClearStatus (
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
  )
{
  VAR(uint8, AUTOMATIC) LucIndex;
  LucIndex = E2E_ZERO;

  /* Clear each element of the ProfileStatusWindow[] array */
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  while (LucIndex < (ConfigPtr->WindowSize))
  {
  /* polyspace<RTE:IDP:Not a defect:Justify with annotations> Range check by whwile-condition */
    StatePtr->ProfileStatusWindow[LucIndex] = (VAR(uint8, AUTOMATIC))E2E_P_NOTAVAILABLE;
    LucIndex++;
  }
     
  /* Set OKCount to 0 */
  StatePtr->OkCount = E2E_ZERO;
  
  /* Set ErrorCount to 0 */
  StatePtr->ErrorCount = E2E_ZERO;
 
  /* Set WindowTopIndex to 0 */
  StatePtr->WindowTopIndex = E2E_ZERO;
  
  return;
} /* End of E2E_SMClearStatus (
   * P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
   * P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr)
   */

/*******************************************************************************
** Function Name        : E2E_SMCheck                                         **
**                                                                            **
** Service ID           : 0x30                                                **
**                                                                            **
** Description          : This function Checks the communication channel.     **
**                        It determines if the data can be used for           **
**                        safety-related application, based on history of     **
**                        checks performed by a corresponding E2E_P0XCheck()  **
**                        function.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ProfileStatus, ConfigPtr                            **
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
**                        Function(s) invoked    : E2E_SMAddStatus            **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_SMCheck (
  VAR(E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr
  )
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  LddRetVal = E2E_E_OK;
  
  /* Verify inputs of the function */
  if ((NULL_PTR == StatePtr) || (NULL_PTR == ConfigPtr))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if (NULL_PTR == (StatePtr->ProfileStatusWindow))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if ((StatePtr->WindowTopIndex) >= (ConfigPtr->WindowSize))
  {
    LddRetVal = E2E_E_INPUTERR_WRONG;
  }
  else
  {
    switch(StatePtr->SMState)
    {
      case E2E_SM_DEINIT:
      {
        LddRetVal = E2E_E_WRONGSTATE;
        break;
      } /* End case E2E_SM_DEINIT: */
    
      case E2E_SM_NODATA:
      {
        /* Check transition condition */
        if((ProfileStatus != E2E_P_ERROR) && (ProfileStatus != E2E_P_NONEWDATA))
        {
          /* Make transition */
          StatePtr->SMState = E2E_SM_INIT;
        }
        else
        {
        }
        break; 
      } /* End case E2E_SM_NODATA: */
    
      case E2E_SM_INIT:
      {
        /* Execute E2E_SMAddStatus() */
        E2E_SMAddStatus(ProfileStatus, StatePtr, ConfigPtr);
        
        /* Check transition condition */
        if(((StatePtr->ErrorCount) <= (ConfigPtr->MaxErrorStateInit)) &&
           ((StatePtr->OkCount) >= (ConfigPtr->MinOkStateInit)))
        {
          /* Make transition */
          StatePtr->SMState = E2E_SM_VALID;
        }
        /* Check transition condition */
        else if((StatePtr->ErrorCount) > (ConfigPtr->MaxErrorStateInit))
        {
          /* Make transition */
          StatePtr->SMState = E2E_SM_INVALID;
        }
        else
        {
        }
        break;
      }
  
      /* End case E2E_SM_INIT: */
    
      case E2E_SM_INVALID:
      {
        /* Execute E2ESMAddStatus() */
        E2E_SMAddStatus(ProfileStatus, StatePtr, ConfigPtr);
    
        /* Check transition condition */
        if(((StatePtr->ErrorCount) <= (ConfigPtr->MaxErrorStateInvalid)) &&
           ((StatePtr->OkCount) >= (ConfigPtr->MinOkStateInvalid)))
        {
          /* Make transition */
          StatePtr->SMState = E2E_SM_VALID;
        }
        else
        {
        }
        break;
      } /* End case E2E_SM_INVALID: */
    
      case E2E_SM_VALID:
      {
        /* Execute E2ESMAddStatus() */
        E2E_SMAddStatus(ProfileStatus, StatePtr, ConfigPtr);

        /* Check transition condition */
        if(((StatePtr->ErrorCount) <= (ConfigPtr->MaxErrorStateValid)) &&
           ((StatePtr->OkCount) >= (ConfigPtr->MinOkStateValid)))
        {
        }
        else
        {
          /* Make transition */
          StatePtr->SMState = E2E_SM_INVALID;
        }
      
        break;
      } /* End case E2E_SM_VALID: */
    
      default:
      {
        break;
      }
    }
  } /* End of if-else */
  
  return LddRetVal;
} /* End of E2E_SMCheck (
   * VAR(E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
   * P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
   * P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
   */

/*******************************************************************************
** Function Name        : E2E_SMCheckInit                                    **
**                                                                            **
** Service ID           : 0x31                                                **
**                                                                            **
** Description          : This function shall initializes the state machine.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ConfigPtr                                           **
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
**                        Function(s) invoked    : E2E_SMClearStatus          **
*******************************************************************************/
FUNC(Std_ReturnType, E2E_CODE) E2E_SMCheckInit (
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
  )
{
  VAR(Std_ReturnType, AUTOMATIC) LddRetVal;
  
  LddRetVal = E2E_E_OK;
  
  /* Verify inputs of the function */
  if ((NULL_PTR == StatePtr) || (NULL_PTR == ConfigPtr))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  /* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
  else if (NULL_PTR == (StatePtr->ProfileStatusWindow))
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  {
    LddRetVal = E2E_E_INPUTERR_NULL;
  }
  else
  {
    /* Do E2E_SMClearStatus() */
    E2E_SMClearStatus(StatePtr, ConfigPtr);
  
    StatePtr->SMState = E2E_SM_NODATA;

  } /* End of if-else */
  
  return LddRetVal;
} /* End of E2E_SMCheckInit (
   * P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
   * P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr)
   */

#define E2E_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
