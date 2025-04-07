/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : ErrM.h                                                        **
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


#ifndef ERRM_H
#define ERRM_H
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
//#include "Rte_SWC_ErrM.h"
#include <stdint.h>         // uint8_t 선언 표준 헤더파일

#include "EcuInfo.h"

typedef enum {
  ERRM_NONE,
  ERRM_OS_ERROR,
  ERRM_DEM_EVENT_FAIL
} ErrM_ErrorType;


//#define SWC_ErrM_START_SEC_CODE
//#include "SWC_ErrM_MemMap.h"

extern void ErrM_OsErrorNotification(uint8_t ErrorId);

#if defined ( DEBUG_ErrM_Module_USE )

extern void ErrM_ErrorProcess(uint8_t ErrorId,   ErrM_ErrorType ErrorType);

extern uint8_t ErrM_Callback(uint8_t ErrorId, ErrM_ErrorType ErrorType);

//#define SWC_ErrM_STOP_SEC_CODE
//#include "SWC_ErrM_MemMap.h"

#endif

#endif
