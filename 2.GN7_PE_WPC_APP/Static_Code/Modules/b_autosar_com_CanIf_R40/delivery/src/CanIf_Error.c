/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Error.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : The file contains the Development Error Tracer code helping   **
**              to findout the error occurred within the CanIf module during  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 3.0.5    12-Aug-2022    Jh.Yang   #36027                                   **
** 3.0.2    21-Feb-2022    Sj.Kim    #34443                                   **
** 3.0.0    08-Nov-2021    Sj.Kim    Initial verison                          **
*******************************************************************************/
#ifndef CANIF_ERROR_C
#define CANIF_ERROR_C
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Error.h"              /* Header file for Error check */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:8.4 [Not a defect:Justified] "This function has visible prototype at definition" */

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"

/* This Error code is used when CanIf module is not initialized */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GlobalInitStatusError(
                          VAR(uint8, CANIF_VAR) ApiId)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;
  switch(CanIf_GblCanIfStatus)
  {
    case CANIF_UNINITIALISED:
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId, CANIF_E_UNINIT);
      LenStdRetVal = (uint8)E_NOT_OK;
      break;
    default:
      /* nothing */
      break;
  }
  return LenStdRetVal;
}

/* This Error code is used when controller id has invalid Id */

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ControllerRangeError(
                          VAR(uint8, CANIF_VAR) ApiId,
                          VAR(uint8, CANIF_VAR) ControllerId)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;
  if(ControllerId > CANIF_NO_OF_CONTROLLER)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId, CANIF_E_PARAM_CONTROLLERID);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  return LenStdRetVal;
}


/* This Error code is used when controller Mode is invalid or out of defined
   values or CANIF_CS_UNINIT */

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ControllerModeError(
                           VAR(uint8, CANIF_VAR) ApiId,
#if (CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440)
      VAR(Can_ControllerStateType, CANIF_VAR) ControllerMode)
#else
      VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode)
#endif
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;
  switch(ControllerMode)
  {
    case CANIF_CS_SLEEP:
      break;
    case CANIF_CS_STARTED:
      break;
    case CANIF_CS_STOPPED:
      break;
    case CANIF_CS_UNINIT:
    default:
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId, CANIF_E_PARAM_CTRLMODE);
      LenStdRetVal = (uint8)E_NOT_OK;
      break;
  }
  return LenStdRetVal;
}

#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
 /* This Error code is used when Transceiver ID is not defined */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_InvalidTrcvIdError(
                       VAR(uint8, CANIF_VAR) ApiId,
                       VAR(uint8, CANIF_VAR) TransceiverId)
{
  P2CONST(CanIf_TransceiverConfigType, AUTOMATIC, CANIF_CONST) LpCanTrcv;
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;

  LpCanTrcv = &CanIf_GaaCanTrcv[TransceiverId];

  if(LpCanTrcv->ucCanIfCanTrcvId != TransceiverId)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId, CANIF_E_PARAM_TRCV);
    LenStdRetVal = (uint8)E_NOT_OK;
  }

  return LenStdRetVal;
}
#endif



 /* This Error code is used when Transceiver ID is Invalid */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TrcvIdRangeError(
                           VAR(uint8, CANIF_VAR) ApiId,
                           VAR(uint8, CANIF_VAR) TransceiverId)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;

  if(TransceiverId >= (uint8)CANIF_NO_OF_TRANSCEIVER)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId, CANIF_E_PARAM_TRCV);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  return LenStdRetVal;
}

 /* This Error code is used when Pdu Mode is invalid */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_PduModeRequestError(
                            VAR(uint8, CANIF_VAR) ApiId,
                            VAR(CanIf_PduSetModeType, CANIF_VAR) PduModeRequest)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;

  switch(PduModeRequest)
  {
    case CANIF_SET_OFFLINE:
      break;
    case CANIF_SET_ONLINE:
      break;
    case CANIF_SET_RX_OFFLINE:
      break;
    case CANIF_SET_RX_ONLINE:
      break;
    case CANIF_SET_TX_OFFLINE:
      break;
    case CANIF_SET_TX_OFFLINE_ACTIVE:
      break;
    case CANIF_SET_TX_ONLINE:
      break;
    default:
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId,
                                               CANIF_E_PARAM_PDU_MODE);
      LenStdRetVal = (uint8)E_NOT_OK;
      break;
  }
  return LenStdRetVal;
}

/* This Error code is used TxPduId is out of range */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxIdRangeError(
                            VAR(uint8, CANIF_VAR) ApiId,
                            VAR(PduIdType, CANIF_VAR) CanTxPduId)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;

  if(CanTxPduId >= (PduIdType)CanIf_GddPrecompOpt.ddNumOfTxPdu)
  {
  	(void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId,
                                                  CANIF_E_INVALID_TXPDUID);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  return LenStdRetVal;
}

/* This Error code is used Lpdu is out of range */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_LpduRangeError(
                            VAR(uint8, CANIF_VAR) ApiId,
                            VAR(PduIdType, CANIF_VAR) CanTxPduId)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal = (uint8)E_OK;

  if(CanTxPduId >= (PduIdType)CanIf_GddPrecompOpt.ddNumOfTxPdu)
  {
  	(void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, ApiId,
                                                  CANIF_E_PARAM_LPDU);
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  return LenStdRetVal;
}

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (STD_ON == CANIF_DEV_ERROR_DETECT) */

/* polyspace-end MISRA-C3:8.4 [Not a defect:Justified] "This function has visible prototype at definition" */

#endif  /* CANIF_ERROR_H */
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
