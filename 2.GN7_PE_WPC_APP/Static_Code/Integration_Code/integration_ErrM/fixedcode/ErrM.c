/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : ErrM.c                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Error Management SWC                                  **
**                                                                            **
**  PURPOSE   : SWC Sample code for Error Management                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/


#include "ErrM.h"
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include "Std_Types.h"
#include "EcuInfo.h"

//#define SWC_ErrM_START_SEC_CODE
//#include "SWC_ErrM_MemMap.h"

/* ErrM_OsErrorNotification is invoked by Dem */
// FUNC(Std_ReturnType, SWC_ErrM_CODE) ErrM_DemEventNotification(
//   VAR(Dem_EventIdType, AUTOMATIC) EventId,
//   VAR(Dem_EventStatusExtendedType, AUTOMATIC) EventStatusOld,
//   VAR(Dem_EventStatusExtendedType, AUTOMATIC) EventStatusNew)
// {
//   if ((EventStatusNew & 0x01) == 0x01)
//   {
//     ErrM_ErrorProcess((uint16)EventId, ERRM_DEM_EVENT_FAIL);
//   }
//   return (E_OK);
// }

/* ErrM_OsErrorNotification is invoked by Os */
void ErrM_OsErrorNotification(uint8_t ErrorId)
{
  #if defined ( DEBUG_ErrM_Module_USE )
  ErrM_ErrorProcess(ErrorId, ERRM_OS_ERROR);
  #endif
}

#if defined ( DEBUG_ErrM_Module_USE )
void ErrM_ErrorProcess(uint8_t ErrorId,  ErrM_ErrorType ErrorType)
{
  uint8_t LddReturn;

  LddReturn = ErrM_Callback(ErrorId, ErrorType);
  if (LddReturn == E_NOT_OK)
  {
    /* Some Action */
  }
  else
  {
    /* No Action */
  }
}

//#define SWC_ErrM_STOP_SEC_CODE
//#include "SWC_ErrM_MemMap.h"
  #endif
