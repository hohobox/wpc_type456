/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI MOTOR GROUP                                              **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: xxxxxxxxxxx.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Classic Platform Application                                  **
**                                                                            **
**  PURPOSE   : Log application for SWP                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** X.X.X     DD-MM-YYYY    name.family name                                   **
** 0.0.1     29-Nov-2022    KC.Lim        xxxxxxxxxxxxxx                      **
*******************************************************************************/
#ifndef NML_INTEGRATION_H
#define NML_INTEGRATION_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/

#define NML_LOGDATA_SIZE 200u /* fixed configuration */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"



#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

extern uint8 Nml_LogData[NML_LOGDATA_SIZE];

#define NML_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

extern void Nml_EcuM_LogDataCallout(uint32 wakeupSource);
extern Std_ReturnType Nml_RDBI_DataRead(uint8* Data);
extern Std_ReturnType Nml_RDBI_CondCheckRead(uint8* ErrorCode);

extern Std_ReturnType Nml_Callback_Nml_LogData_JobFinished(uint8 ServiceId, uint8 JobResult);

extern void Nml_SetNvMReqStatus(void);
extern uint8 Nml_GetNvMReqSrvId(void);
extern Std_ReturnType Nml_GetNvMReqStatus(void);
extern void Nml_InitSleepToWakeup(void);          /* [NML-3] Sleep/Wakeup Callout */
extern void Nml_DeInitToSleep(void);              /* [NML-3] Sleep/Wakeup Callout */
extern void Nml_PrepareSleep(void);
#define NML_STOP_SEC_CODE
#include "MemMap.h"


#endif /* NML_INTEGRATION_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
