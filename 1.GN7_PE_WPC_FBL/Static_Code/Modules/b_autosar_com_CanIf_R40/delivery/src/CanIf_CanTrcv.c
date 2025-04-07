/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_CanTrcv.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of Can Transceiver functionality                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
*******************************************************************************/

/*******************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.1    28-Dec-2021    Sj.Kim    #33378                                   **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.1    25-Nov-2020    Sj.Kim    #26002                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384                                   **
** 2.5.7    18-Oct-2018    Js.Lim    #14477                                   **
** 2.5.1    06-Apr-2017    Js.Lim    #8086                                    **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 1.0.3    12-Feb-2016    Kt.Kim    MISRA Justification                      **
** 1.0.2    25-Aug-2015    Kt.Kim    Improvement #2999                        **
**                                   Justification for Runtime Error          **
** 1.0.1    13-Jun-2015    Kt.Kim    Improvement #2724                        **
** 1.0.0    28-Mar-2013    Kt.Kim    Initial version                          **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"               /* CanIf header file */
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#include "CanIf_Trcv.h"          /* CanIf header file for trcv */
#include "CanIf_Ram.h"           /* CanIf RAM header file */
#include "CanIf_PCTypes.h"       /* Pre-compile time header file */
#include "CanSM_Cbk.h"           /* CanIf call back header file */
#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "CanIf_Error.h"         /* CanIf DET header file */
#endif
#include "CanIf_UserInc.h"       /* CanIf User Included header file */
#include "SchM_CanIf.h"          /* CanIf SchM header file */
#include "CanIf_Cbk.h"           /* CanIf Callback header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define CANIF_CANTRCV_C_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_CANTRCV_C_AR_RELEASE_MINOR_VERSION    0
#define CANIF_CANTRCV_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANIF_CANTRCV_C_SW_MAJOR_VERSION    3
#define CANIF_CANTRCV_C_SW_MINOR_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_CANTRCV_H_AR_RELEASE_MAJOR_VERSION != \
  CANIF_CANTRCV_C_AR_RELEASE_MAJOR_VERSION)
  #error "CANIF_CANTRCV.c : Mismatch in Specification Major Version"
#endif
#if (CANIF_CANTRCV_H_AR_RELEASE_MINOR_VERSION != \
  CANIF_CANTRCV_C_AR_RELEASE_MINOR_VERSION)
  #error "CANIF_CANTRCV.c : Mismatch in Specification Minor Version"
#endif
#if (CANIF_CANTRCV_H_AR_RELEASE_REVISION_VERSION != \
  CANIF_CANTRCV_C_AR_RELEASE_REVISION_VERSION)
  #error "CANIF_CANTRCV.c : Mismatch in Specification Revision Version"
#endif
#if (CANIF_CANTRCV_H_SW_MAJOR_VERSION != CANIF_CANTRCV_C_SW_MAJOR_VERSION)
  #error "CANIF_CANTRCV.c : Mismatch in Software Major Version"
#endif
#if (CANIF_CANTRCV_H_SW_MINOR_VERSION != CANIF_CANTRCV_C_SW_MINOR_VERSION)
  #error "CANIF_CANTRCV.c : Mismatch in Software Minor Version"
#endif

#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : CanIf_SetTrcvMode                                   **
**                                                                            **
** Service ID           : 0x0d                                                **
**                                                                            **
** Description          : This service requests actual state of CAN           **
**                        Transceiver Driver                                  **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Transceiver, TransceiverMode                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : CanIf module must be initialised                    **
**                                                                            **
** Remarks              : Global Variable(s)     : CanIf_GaaCanTrcv,          **
**                                                 CanIf_GaaOperMode          **
**                                                 CanIf_GaaCanTrcvDriver     **
**                                                 CanIf_GblCanIfStatus       **
**                        Function(s) invoked    : CanTrcv_SetOpMode,         **
**                                                 Det_ReportError            **
*******************************************************************************/
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode (
                           VAR(uint8, CANIF_VAR) TransceiverId,
                           VAR(CanTrcv_TrcvModeType, CANIF_VAR) TransceiverMode)

{
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  P2CONST(CanIf_CanTrcvDriver, AUTOMATIC, CANIF_CONST) LpCanTrcvDriver;
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(uint8, CANIF_VAR) LucCurrentOpMode;
  #endif/* #if (STD_ON == CANIF_DEV_ERROR_DETECT) */
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Get the pointer to corresponding Can Transceiver Channel structure  */
  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];
  #endif
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Initialize the Standard Return Value with E_OK */
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized  */
  /* polyspace +2 MISRA-C3:8.3 [Not a defect:Justified] "Declaration is matched" */
  /* polyspace +1 DEFECT:DECL_MISMATCH [Not a defect:Justified] "Declaration is matched" */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_SET_TRCV_MODE_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Id is out of range  */
  /* polyspace +2 MISRA-C3:8.3 [Not a defect:Justified] "Declaration is matched" */
  /* polyspace +1 DEFECT:DECL_MISMATCH [Not a defect:Justified] "Declaration is matched" */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_SET_TRCV_MODE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  
  /* Report to DET, if Transceiver Id is out of range  */
  switch(TransceiverMode)
  {
    case CANTRCV_TRCVMODE_STANDBY:
      break;
    case CANTRCV_TRCVMODE_NORMAL:
      break;
    case CANTRCV_TRCVMODE_SLEEP:
      break;
    default:
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, 
                              CANIF_SET_TRCV_MODE_SID, CANIF_E_PARAM_TRCVMODE);
      LenStdRetVal = (uint8)E_NOT_OK;
      break;
  }
  /* Polyspace Gray Code: for Checking TransceiverMode
                          As valid values of TransceiverMode are of enum type,
                          TransceiverMode can't have values other than defined
                          values. If such scenarios occurrs it will be taken
                          care by DET check  */
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Check if the Transceiver Id is present or not  */
  /* polyspace +2 MISRA-C3:8.3 [Not a defect:Justified] "Declaration is matched" */
  /* polyspace +1 DEFECT:DECL_MISMATCH [Not a defect:Justified] "Declaration is matched" */
  if((uint8)E_OK != CanIf_InvalidTrcvIdError(CANIF_SET_TRCV_MODE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_OK;
  }
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
  /* Get the current op mode of the Transceiver  */
  if(TransceiverId < CANIF_NO_OF_TRANSCEIVER)
  {
    /* polyspace<RTE: OBAI : Not a defect : No Action Planned > range is pre-defined */
    LucCurrentOpMode = CanIf_GaaOperMode[TransceiverId];
    /* Report to DET if current mode is not equal to Sleep and requested mode
    is in standby  */
    if (((uint8)E_OK == (LenStdRetVal)) &&
       (((uint8) CANTRCV_TRCVMODE_SLEEP == (LucCurrentOpMode)) &&
       ((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_STANDBY == (TransceiverMode))))
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_SET_TRCV_MODE_SID, 
                                                             CANIF_E_PARAM_TRCVMODE);
      LenStdRetVal = (uint8)E_NOT_OK;
    }
    /* Report to DET if current mode is not equal to standby and requested mode
    is in normal  */
    if (((uint8)E_OK == (LenStdRetVal)) &&
       (((uint8) CANTRCV_TRCVMODE_NORMAL == (LucCurrentOpMode)) &&
       ((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_SLEEP == (TransceiverMode))))
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_SET_TRCV_MODE_SID,
                                                    CANIF_E_PARAM_TRCVMODE);
      LenStdRetVal = (uint8)E_NOT_OK;
    }
  }
  else
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif /* #if (STD_ON == CANIF_DEV_ERROR_DETECT) */
  {
    #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
    /* Get the pointer to corresponding Can Transceiver Driver structure  */
    /* polyspace-begin MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
    /* polyspace +1 RTE:IDP [Not a defect: Justified] "Pointer is not outside its bounds." */
    LpCanTrcvDriver = &CanIf_GaaCanTrcvDriver[LpCanTrcv->ucCanTrcvDriverId];
    /* Invoke corresponding Driver function  */
	/* polyspace +1 RTE:COR [Not a defect Justified:Unset] "Pointer is not a NULL and valid" */
    LenStdRetVal = LpCanTrcvDriver->pCanTrcvSetOpMode(LpCanTrcv->ucCanTrcvId,
                                                               TransceiverMode);
    /* polyspace-end MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
    #else
    /* Invoke CanTrcv_SetOpMode function  */
    LenStdRetVal = CanTrcv_SetOpMode(TransceiverId, TransceiverMode);
    #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
    #if (STD_ON == CANIF_DEV_ERROR_DETECT)
    /* Store the current requested mode */
    CanIf_GaaOperMode[TransceiverId] = (uint8)TransceiverMode;
    #endif/* #if (STD_ON == CANIF_DEV_ERROR_DETECT) */
  }
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/* #if (STD_ON == CANIF_CANTRCV_SUPPORT) */
/*******************************************************************************
** Function Name        : CanIf_GetTrcvMode                                   **
**                                                                            **
** Service ID           : 0x0e                                                **
**                                                                            **
** Description          : This service returns actual state of CAN            **
**                        Transceiver Driver                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Transceiver                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : TransceiverModePtr                                  **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : CanIf module must be initialised                    **
**                                                                            **
** Remarks              : Global Variable(s) : CanIf_GaaCanTrcv,              **
**                                             CanIf_GaaCanTrcvDriver         **
**                                             CanIf_GblCanIfStatus           **
**                        Function(s) invoked: CanTrcv_GetOpMode              **
**                                             Det_ReportError                **
*******************************************************************************/
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
           (P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_VAR)TransceiverModePtr,
            VAR(uint8, CANIF_VAR) TransceiverId)
{
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  P2CONST(CanIf_CanTrcvDriver, AUTOMATIC, CANIF_CONST) LpCanTrcvDriver;
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Get the pointer to corresponding Can Transceiver Channel structure  */
  /* #14477 */
  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];
  #endif
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Initialize LenStdRetVal with E_OK  */
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized  */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_GET_TRCV_MODE_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Id is out of range  */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_GET_TRCV_MODE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Mode is Invalid  */
  if (TransceiverModePtr == NULL_PTR)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, 
                           CANIF_GET_TRCV_MODE_SID, CANIF_E_PARAM_POINTER);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Check if the Transceiver Id is present or not */
  if((uint8)E_OK != CanIf_InvalidTrcvIdError(CANIF_GET_TRCV_MODE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_OK;
  }
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif /* #if (STD_ON == CANIF_DEV_ERROR_DETECT) */
  {
    #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
    /* Get the pointer to corresponding Can Transceiver Driver structure  */
    LpCanTrcvDriver = &CanIf_GaaCanTrcvDriver[LpCanTrcv->ucCanTrcvDriverId];
    /* Invoke corresponding Driver function  */
    /* polyspace +3 MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
    /* polyspace +2 RTE:IDP [Not a defect: Justified] "Pointer is not outside its bounds." */
	/* polyspace +1 RTE:COR [Not a defect Justified:Unset] "Pointer is not a NULL and valid" */
    LenStdRetVal = LpCanTrcvDriver->pCanTrcvGetOpMode(LpCanTrcv->ucCanTrcvId,
                                                            TransceiverModePtr);
    #else
    /* Invoke CanTrcv_GetOpMode function  */
    LenStdRetVal = CanTrcv_GetOpMode(TransceiverId, TransceiverModePtr);
    #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  }
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/* #if (STD_ON == CANIF_CANTRCV_SUPPORT) */

/*******************************************************************************
** Function Name        : CanIf_GetTrcvWakeupReason                           **
**                                                                            **
** Service ID           : 0x0f                                                **
**                                                                            **
** Description          : This service returns the reason for the wake up     **
**                        that the CAN transceiver has detected.              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Transceiver                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : TrcvWuReasonPtr                                     **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : CanIf module must be initialised                    **
**                                                                            **
** Remarks              : Global Variable(s)     :    CanIf_GaaCanTrcv        **
**                                                    CanIf_GaaCanTrcvDriver  **
**                                                    CanIf_GblCanIfStatus    **
**                        Function(s) invoked    :    CanTrcv_GetBusWuReason  **
**                                                    Det_ReportError         **
*******************************************************************************/
#if (STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason (
       VAR(uint8, CANIF_VAR) TransceiverId,
       P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_VAR)TrcvWuReasonPtr)
{
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  P2CONST(CanIf_CanTrcvDriver, AUTOMATIC, CANIF_CONST) LpCanTrcvDriver;
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Get the pointer to corresponding Can Transceiver Channel structure  */
  /* #14477 */
  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];
  #endif

  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Initialize LenStdRetVal with E_OK  */
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized  */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_GET_TRCV_WAKEUPREASON_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Id is out of range  */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_GET_TRCV_WAKEUPREASON_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Wakeup reason is invalid  */
  if (TrcvWuReasonPtr == NULL_PTR)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, 
                       CANIF_GET_TRCV_WAKEUPREASON_SID, CANIF_E_PARAM_POINTER);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check for any development error  */
  if ((uint8)E_OK == LenStdRetVal)
  #endif /* #if (STD_ON == CANIF_DEV_ERROR_DETECT)  */
  {
    #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
    /* Get the pointer to corresponding Can Transceiver Driver structure  */
    LpCanTrcvDriver = &CanIf_GaaCanTrcvDriver[LpCanTrcv->ucCanTrcvDriverId];
    /* Invoke corresponding Driver function  */
    LenStdRetVal = LpCanTrcvDriver->pCanTrcvGetBusWuReason
                                      (LpCanTrcv->ucCanTrcvId, TrcvWuReasonPtr);
    #else
    /* Invoke CanTrcv_GetBusWuReason function  */
    LenStdRetVal = CanTrcv_GetBusWuReason(TransceiverId, TrcvWuReasonPtr);
    #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  }
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/* #if (STD_ON == CANIF_CANTRCV_SUPPORT) */

/*******************************************************************************
** Function Name        : CanIf_SetTrcvWakeupMode                             **
**                                                                            **
** Service ID           : 0x10                                                **
**                                                                            **
** Description          : This service enables, disables and clears the       **
**                        notification for wakeup events on the addressed     **
**                        transceiver.                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Transceiver, TrcvWakeupMode                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : CanIf module must be initialised                    **
**                                                                            **
** Remarks              : Global Variable(s)  : CanIf_GaaCanTrcv              **
**                                              CanIf_GaaCanTrcvDriver        **
**                                              CanIf_GblCanIfStatus          **
**                        Function(s) invoked : CanTrcv_SetWakeupMode         **
**                                              Det_ReportError               **
*******************************************************************************/
#if  (STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode (
                      VAR(uint8, CANIF_VAR) TransceiverId,
                      VAR(CanTrcv_TrcvWakeupModeType, CANIF_VAR) TrcvWakeupMode)

{
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  P2CONST(CanIf_CanTrcvDriver, AUTOMATIC, CANIF_CONST) LpCanTrcvDriver;
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Get the pointer to corresponding Can Transceiver Channel structure  */
  /* #14477 */
  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];
  #endif
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Initialize LenStdRetVal with E_OK  */
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized  */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_SET_TRCV_WAKEUP_MODE_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Id is out of range  */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_SET_TRCV_WAKEUP_MODE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Transceiver Wakeup mode is invalid  */
  if ((uint8)TrcvWakeupMode >  (uint8)CANIF_TRCV_WU_CLEAR)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, 
                    CANIF_SET_TRCV_WAKEUP_MODE_SID, CANIF_E_PARAM_TRCVWAKEUPMODE);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Polyspace Gray Code: for Checking TrcvWakeupMode
                          As valid values of TrcvWakeupMode are of enum type,
                          TrcvWakeupMode can't have values other than defined
                          values. If such scenarios occurrs it will be taken
                          care by DET check  */
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Check if the Transceiver Id is present or not  */
  if((uint8)E_OK != CanIf_InvalidTrcvIdError(CANIF_SET_TRCV_WAKEUP_MODE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_OK;
  }
  #endif/* #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) */
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif /* #if (STD_ON == CANIF_DEV_ERROR_DETECT)) */
  {
  	/* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Configuration Index is generated value based on Ecudescription" */
    if (CanIf_GaaTrcvMode[TransceiverId] != (uint8)TrcvWakeupMode)
    {
      #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
      /* Get the pointer to corresponding Can Transceiver Driver structure  */
      LpCanTrcvDriver = &CanIf_GaaCanTrcvDriver[LpCanTrcv->ucCanTrcvDriverId];
      /* Invoke corresponding Driver function  */
      LenStdRetVal = LpCanTrcvDriver->pCanTrcvSetWakeupMode
                                      (LpCanTrcv->ucCanTrcvId, TrcvWakeupMode);
      /* Store the Transceiver mode in CanIf_GaaTrcvMode array */
      CanIf_GaaTrcvMode[TransceiverId] = (uint8)TrcvWakeupMode;
      #else
      /* Invoke CanTrcv_SetWakeupMode function  */
      LenStdRetVal = CanTrcv_SetWakeupMode(TransceiverId, TrcvWakeupMode);
      /* Store the Transceiver mode in CanIf_GaaTrcvMode array */
      CanIf_GaaTrcvMode[CANIF_ZERO] = (uint8)TrcvWakeupMode;
      #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
    }
    else
    {
      /* Set return value to E_NOT_OK */
      LenStdRetVal = (uint8)E_NOT_OK;
    }
  }
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if (STD_ON == CANIF_CANTRCV_SUPPORT)*/

/*******************************************************************************
** Function Name        :  CanIf_ClearTrcvWufFlag                             **
**                                                                            **
** Service ID           :  0x1e                                               **
**                                                                            **
** Description          :  This service indicates that the Transceiver has    **
**                         cleared the WufFlag                                **
**                                                                            **
** Sync/Async           :  Asynchronous                                       **
**                                                                            **
** Re-entrancy          :  Re-entrant                                         **
**                                                                            **
** Input Parameters     :  Transceiver                                        **
**                                                                            **
** InOut Parameters     :  None                                               **
**                                                                            **
** Output Parameters    :  None                                               **
**                                                                            **
** Return parameter     :  None                                               **
**                                                                            **
** Preconditions        :  CanIf module must be initialised                   **
**                                                                            **
** Remarks              :  Global Variable(s) : CanIf_GaaCanTrcv              **
**                                              CanIf_GaaCanTrcvDriver        **
**                                              CanIf_GblCanIfStatus          **
**                         Function(s) invoked: CanTrcv_ClearTrcvWufFlag      **
**                                              Det_ReportError               **
*******************************************************************************/
#if ((STD_ON == CANIF_CANTRCV_SUPPORT) && (STD_ON == CANIF_PN_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag (
                                            VAR(uint8, CANIF_VAR) TransceiverId)

{
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  P2CONST(CanIf_CanTrcvDriver, AUTOMATIC, CANIF_CONST) LpCanTrcvDriver;
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Get the pointer to corresponding Can Transceiver Channel structure  */
  /* #14477 */
  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];
  #endif
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  LenStdRetVal = (uint8)E_OK;
  /* Check if CanIf is Initialised */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_CLEAR_TRCV_WUF_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check if TRANSCEIVERID is in range */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_CLEAR_TRCV_WUF_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif/*#if (STD_ON == CANIF_DEV_ERROR_DETECT)*/
  {
    #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
    /* Get the pointer to corresponding Can Transceiver Driver structure  */
    LpCanTrcvDriver = &CanIf_GaaCanTrcvDriver[LpCanTrcv->ucCanTrcvDriverId];
    /* Invoke corresponding Driver function  */
    LenStdRetVal = LpCanTrcvDriver->pClearTrcvWufFlag(LpCanTrcv->ucCanTrcvId);
    #else
    /* Invoke the CanTrcv_ClearTrcvWufFlag to clear the WUF flag */
    LenStdRetVal = CanTrcv_ClearTrcvWufFlag(TransceiverId);
    #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  }
  return (LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if ((STD_ON == CANIF_CANTRCV_SUPPORT) && (...)*/

/*******************************************************************************
** Function Name        :  CanIf_CheckTrcvWakeFlag                            **
**                                                                            **
** Service ID           :  0x1f                                               **
**                                                                            **
** Description          :  Request the CanIf module to check the wake flag    **
**                         of the designated CAN Transceiver                  **
**                                                                            **
** Sync/Async           :  Asynchronous                                       **
**                                                                            **
** Re-entrancy          :  Reentrant for different CAN Transceiver            **
**                                                                            **
** Input Parameters     :  Designated CAN Transceiver                         **
**                                                                            **
** InOut Parameters     :  None                                               **
**                                                                            **
** Output Parameters    :  None                                               **
**                                                                            **
** Return parameter     :  Std_ReturnType (E_OK or E_NOT_OK)                  **
**                                                                            **
** Preconditions        :  CanIf module must be initialised                   **
**                                                                            **
** Remarks              : Global Variable(s) : CanIf_GaaCanTrcv               **
**                                             CanIf_GaaCanTrcvDriver         **
**                                             CanIf_GblCanIfStatus           **
**                        Function(s) invoked: CanTrcv_CheckWakeFlag          **
**                                             Det_ReportError                **
*******************************************************************************/
#if ((STD_ON == CANIF_CANTRCV_SUPPORT) && (STD_ON == CANIF_PN_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag (
                                            VAR(uint8, CANIF_VAR) TransceiverId)
{
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  P2CONST(CanIf_CanTrcvDriver, AUTOMATIC, CANIF_CONST) LpCanTrcvDriver;
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
  /* Get the pointer to corresponding Can Transceiver Channel structure  */
  /* #14477 */
  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];
  #endif
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  LenStdRetVal = (uint8)E_OK;
  /* Check if CanIf is Initialised */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_CHECK_TRCV_WAKE_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check if TRANSCEIVERID is in range */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_CHECK_TRCV_WAKE_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif/*#if (STD_ON == CANIF_DEV_ERROR_DETECT)*/
  {
    #if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
    /* Get the pointer to corresponding Can Transceiver Driver structure  */
    LpCanTrcvDriver = &CanIf_GaaCanTrcvDriver[LpCanTrcv->ucCanTrcvDriverId];
    /* Invoke corresponding Driver function  */
    LenStdRetVal = LpCanTrcvDriver->pCheckWakeFlag(LpCanTrcv->ucCanTrcvId);
    #else
    /* Invoke CanTrcv_CheckWakeFlag function  */
    LenStdRetVal = CanTrcv_CheckWakeFlag(TransceiverId);
    #endif/*#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)*/
  }
  return (LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if ((STD_ON == CANIF_CANTRCV_SUPPORT) && (...))*/

/*******************************************************************************
** Function Name        :  CanIf_CheckTrcvWakeFlagIndication                  **
**                                                                            **
** Service ID           :  0x21                                               **
**                                                                            **
** Description          :  This service indicates the reason for the wake     **
**                         up that the CAN transceiver has detected.          **
**                                                                            **
** Sync/Async           :  Synchronous                                        **
**                                                                            **
** Re-entrancy          :  Reentrant                                          **
**                                                                            **
** Input Parameters     :  Transceiver                                        **
**                                                                            **
** InOut Parameters     :  None                                               **
**                                                                            **
** Output Parameters    :  None                                               **
**                                                                            **
** Return parameter     :  None                                               **
**                                                                            **
** Preconditions        :  CanIf module must be initialised                   **
**                                                                            **
** Remarks              :  Global Variable(s): CanIf_GblCanIfStatus           **
**                                                                            **
**                         Function(s) invoked: Det_ReportError               **
**                                              CanSM/Cdd_CheckTrcvWakeFlag   **
**                                              Indication                    **
*******************************************************************************/
#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication (
                                            VAR(uint8, CANIF_VAR) TransceiverId)
{
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  LenStdRetVal = (uint8)E_OK;
  /* Check if CanIf is Initialised */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_CHECK_TRCV_WAKE_FLAG_IND_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check if TRANSCEIVERID is in range */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_CHECK_TRCV_WAKE_FLAG_IND_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif/*#if (STD_ON == CANIF_DEV_ERROR_DETECT)*/
  {
    /* Invoking CanSM/Cdd_CheckTransceiverWakeFlagIndiction(TransceiverId) */
    CANIF_DISPATCH_USERCHECKTRCVWAKEFLAGINDICATION_NAME(TransceiverId);
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if ((STD_ON == CANIF_PN_SUPPORT) && (...))*/

/*******************************************************************************
** Function Name        :  CanIf_ClearTrcvWufFlagIndication                   **
**                                                                            **
** Service ID           :  0x20                                               **
**                                                                            **
** Description          :  This service indicates that the transceiver        **
**                         has cleared the WufFlag.                           **
**                                                                            **
** Sync/Async           :  Synchronous                                        **
**                                                                            **
** Re-entrancy          :  Re-entrant                                         **
**                                                                            **
** Input Parameters     :  Transceiver                                        **
**                                                                            **
** InOut Parameters     :  None                                               **
**                                                                            **
** Output Parameters    :  None                                               **
**                                                                            **
** Return parameter     :  None                                               **
**                                                                            **
** Preconditions        :  CanIf module must be initialised                   **
**                                                                            **
** Remarks              : Global Variable(s)  :  CanIf_GblCanIfStatus         **
**                        Function(s) invoked :  Det_ReportError,             **
**                                               CanSM/Cdd_ClearTrcvWufFlag   **
**                                               Indication                   **
*******************************************************************************/
#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(
                                            VAR(uint8, CANIF_VAR) TransceiverId)
{
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  LenStdRetVal = (uint8)E_OK;
  /* Check if CanIf is Initialised */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_CLEAR_TRCV_WAKE_FLAG_IND_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check if TRANSCEIVERID is in range */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_CLEAR_TRCV_WAKE_FLAG_IND_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Is any DET error invoked */
  if ((uint8)E_OK == LenStdRetVal)
  #endif/*#if (STD_ON == CANIF_DEV_ERROR_DETECT)*/
  {
    /* Invoking CanSM/Cdd_CheckTrcvWufFlagIndiction(TransceiverId) */
    CANIF_DISPATCH_USERCLEARTRCVWUFFLAGINDICATION_NAME(TransceiverId);
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if ((STD_ON == CANIF_PN_SUPPORT) && (...))*/

/*******************************************************************************
** Function Name        :  CanIf_ConfirmPnAvailability                        **
**                                                                            **
** Service ID           :  0x1c                                               **
**                                                                            **
** Description          :  This service indicates that the transceiver is     **
**                         running in PN communication mode                   **
**                                                                            **
** Sync/Async           :  Synchronous                                        **
**                                                                            **
** Re-entrancy          :  Re-entrant                                         **
**                                                                            **
** Input Parameters     :  Transceiver                                        **
**                                                                            **
** InOut Parameters     :  None                                               **
**                                                                            **
** Output Parameters    :  None                                               **
**                                                                            **
** Return parameter     :  None                                               **
**                                                                            **
** Preconditions        :  CanIf module must be initialised                   **
**                                                                            **
** Remarks              : Global Variable(s)  :  CanIf_GblCanIfStatus         **
**                        Function(s) invoked :  Det_ReportError,             **
**                                               CanSM/Cdd_ConfirmPn          **
**                                               Availability                 **
*******************************************************************************/
#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability (
                                            VAR(uint8, CANIF_VAR) TransceiverId)
{
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  LenStdRetVal = (uint8)E_OK;
  /* Check if CanIf is Initialised  */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_CONFIRM_PN_AVAILIBILITY_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check if TRANSCEIVERID is in range  */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_CONFIRM_PN_AVAILIBILITY_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  
  if ((uint8)E_OK == LenStdRetVal)
  #endif/*#if (STD_ON == CANIF_DEV_ERROR_DETECT)*/
  {
    /* Invoking CanSM/Cdd_ConfirmPnAvailability(TransceiverId) */
    CANIF_DISPATCH_USERCONFIRMPNAVAILABILITY_NAME(TransceiverId);
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if ((STD_ON == CANIF_PN_SUPPORT) && (...))*/

/*******************************************************************************
** Function Name        :  CanIf_TrcvModeIndication                           **
**                                                                            **
** Service ID           :  0x18                                               **
**                                                                            **
** Description          :  This service indicates that the transceiver        **
**                         mode has changed to TransceiverMode.               **
**                                                                            **
** Sync/Async           :  Synchronous                                        **
**                                                                            **
** Re-entrancy          :  Reentrant                                          **
**                                                                            **
** Input Parameters     :  Transceiver, TransceiverMode                       **
**                                                                            **
** InOut Parameters     :  None                                               **
**                                                                            **
** Output Parameters    :  None                                               **
**                                                                            **
** Return parameter     :  None                                               **
**                                                                            **
** Preconditions        :  CanIf module must be initialised                   **
**                                                                            **
** Remarks              :  Global Variable(s)  : CanIf_GblCanIfStatus         **
**                         Function(s) invoked : Det_ReportError,             **
**                                               CanSM/Cdd_TransceiverMode    **
**                                               Indication                   **
*******************************************************************************/
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication (
                           VAR(uint8, CANIF_VAR) TransceiverId,
                           VAR(CanTrcv_TrcvModeType, CANIF_VAR) TransceiverMode)
{
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;

  LenStdRetVal = (uint8)E_OK;
  /* Check if CanIf is Initialised */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_TRCV_MODE_IND_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check if TRANSCEIVERID is in range */
  if((uint8)E_OK != CanIf_TrcvIdRangeError(CANIF_TRCV_MODE_IND_SID, TransceiverId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Check for no development errors */
  if ((uint8)E_OK == LenStdRetVal)
  #endif/*#if (STD_ON == CANIF_DEV_ERROR_DETECT)*/
  {
    /* Invoking CanSM/Cdd_TrcvModeIndication(TransceiverId, TransceiverMode)*/
    CANIF_DISPATCH_USERTRCVMODEINDICATION_NAME(TransceiverId, TransceiverMode);
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif/*#if (STD_ON == CANIF_CANTRCV_SUPPORT)*/
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
