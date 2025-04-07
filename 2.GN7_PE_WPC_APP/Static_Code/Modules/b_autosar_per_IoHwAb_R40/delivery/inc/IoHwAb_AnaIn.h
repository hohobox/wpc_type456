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
**  SRC-MODULE: IoHwAb_AnaIn.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for AnaIn                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By         Description                             **
********************************************************************************
** 1.15.0.2  09-Sep-2021   Yangjin    #31974                                  **
** 1.8.1     08-May-2020   Yangjin    #23096                                  **
** 1.5.0     28-Aug-2019   Yangjin    #18753                                  **
** 1.0.6     08-Aug-2018   Jongyoung  #13075                                  **
** 1.0.5     05-Jun-2015   Jongyoung  1.Misra-C coding Rule adaption          **
**                                      Duplicated Extern declaration (8.8)   **
** 1.0.4     24-Mar-2015   Jongyoung  1.Add function return value to the      **
**                                      IoHwAb_AnaInConvCompleted             **
** 1.0.3     24-Feb-2015   Jongyoung  1.Bug fix from                          **
**                                      IoHwAb_AnaInReadDirect                **
**                                      IoHwAb_AnaInDirReadDirect             **
**                                      Able to work in ISR                   **
**                                    2.Add IoHwAb_AnaInConvCompleted func    **
** 1.0.2     27-Sep-2014   Jongyoung  1.Polyspace result Adaption             **
** 1.0.1     07-Apr-2014   Sinil        Task ID : 853                         **
**                                      Update IoHwAb_AnaInDirReadDirect      **
** 1.0.0     07-Mar-2014   Sinil        Initial version                       **
*******************************************************************************/

#ifndef IOHWAB_ANAIN_H
#define IOHWAB_ANAIN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IOHWAB_USE_ANA_IN == STD_ON)

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_AnaInInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_AnaInConvertStart(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_AnaInConvertStop(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_AnaInFilter(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvertAllChannels(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_AnaInAdcAllGrNf(uint8 GroupId);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_IN == STD_ON) */

#if ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON))
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint16, IOHWAB_CODE)IoHwAb_AnaInFirstOrderFiltering(
  uint16 FiltValue, uint16 RawValue, uint8 Gain);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON)) */

#endif /* IOHWAB_ANAIN_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
