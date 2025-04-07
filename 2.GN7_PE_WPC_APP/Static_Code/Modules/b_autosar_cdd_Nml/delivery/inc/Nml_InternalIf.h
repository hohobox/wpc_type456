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
#ifndef NML_INTERNALIF_H
#define NML_INTERNALIF_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Ram.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (STD_ON == NML_USE)

#define NML_START_SEC_CODE
#include "MemMap.h"

extern void Nml_SetChDataRequestedHighMode(uint8 chIndex, ComM_ModeType requestedHighMode);
extern ComM_ModeType Nml_GetChDataRequestedHighMode(uint8 chIndex);
extern void Nml_SetChDataCurComMode(uint8 chIndex, uint8 curComMode);
extern uint8 Nml_GetChDataCurComMode(uint8 chIndex);
extern void Nml_SetChDataMappedUsrIdx(uint8 chIndex, uint8 mappedUsrIdx);
extern uint8 Nml_GetChDataMappedUsrIdx(uint8 chIndex);
extern void Nml_SetChDataMappedUsrCnt(uint8 chIndex, uint8 mappedUsrCnt);
extern uint8 Nml_GetChDataMappedUsrCnt(uint8 chIndex);
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
  extern void Nml_SetChDataMappedPncIdx(uint8 chIndex, uint8 mappedPncIdx);
  extern uint8 Nml_GetChDataMappedPncIdx(uint8 chIndex);
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
  extern void Nml_SetChDataMappedPncIdx(uint8 chIndex, uint16 mappedPncIdx);
  extern uint16 Nml_GetChDataMappedPncIdx(uint8 chIndex);
#else /* Other variant */
  #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */

#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
  extern void Nml_SetChDataMappedPncCnt(uint8 chIndex, uint8 mappedPncCnt);
  extern uint8 Nml_GetChDataMappedPncCnt(uint8 chIndex);
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
  extern void Nml_SetChDataMappedPncCnt(uint8 chIndex, uint16 mappedPncCnt);
  extern uint16 Nml_GetChDataMappedPncCnt(uint8 chIndex);
#else /* Other variant */
  #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 

extern void Nml_SetChDataTargetElapsedCnt(uint8 chIndex, uint16 targetElapsedCnt);
extern uint16 Nml_GetChDataTargetElapsedCnt(uint8 chIndex);
extern void Nml_SetChDataInhibit(uint8 chIndex, uint8 inhibit);
extern uint8 Nml_GetChDataInhibit(uint8 chIndex);
extern void Nml_SetChDataIsPncCh(uint8 chIndex, boolean isPncCh);
extern boolean Nml_GetChDataIsPncCh(uint8 chIndex);
extern void Nml_SetChDataIsComModeMatched(uint8 chIndex, boolean isReqVsCurComModeMatched);
extern boolean Nml_GetChDataIsComModeMatched(uint8 chIndex);
extern Nm_StateType Nml_GetPrevNmState(uint8 chIndex);
extern void Nml_SetNmState(uint8 chIndex, Nm_StateType nmState);
extern Nm_StateType Nml_GetCurNmState(uint8 chIndex);
extern void Nml_SetCanNmIndex(uint8 chIndex, uint8 canNmIndex);
extern uint8 Nml_GetCanNmIndex(uint8 chIndex);
extern void Nml_SetNmStateMatched(uint8 chIndex, uint8 NmStateMatched);
extern uint8 Nml_GetNmStateMatched(uint8 chIndex);
extern void Nml_SetNmRepeatMsgTime(uint8 chIndex, uint16 repeatMsgTime);
extern uint16 Nml_GetNmRepeatMsgTime(uint8 chIndex);
extern void Nml_SetNmTimeOutTime(uint8 chIndex, uint16 nmTimeOutTime);
extern uint16 Nml_GetNmTimeOutTime(uint8 chIndex);
extern void Nml_SetNmWaitBusSleeptime(uint8 chIndex, uint16 waitBusSleeptime);
extern uint16 Nml_GetNmWaitBusSleeptime(uint8 chIndex);
extern void Nml_SetNmNwRequested(uint8 chIndex, boolean nmNwRequested);
extern boolean Nml_GetNmNwRequested(uint8 chIndex);
extern void Nml_SetNmModeStatus(uint8 chIndex, uint8 nmModeStatus);
extern uint8 Nml_GetNmModeStatus(uint8 chIndex);
extern void Nml_SetNmNextModeState(uint8 chIndex, uint8 nmNextModeState);
extern uint8 Nml_GetNmNextModeState(uint8 chIndex);
extern void Nml_SetNmPrevModeStatus(uint8 chIndex, uint8 nmPrevModeStatus);
extern uint8 Nml_GetNmPrevModeStatus(uint8 chIndex);
extern void Nml_SetUdpNmIndex(uint8 chIndex, uint8 udpNmIndex);
extern uint8 Nml_GetUdpNmIndex(uint8 chIndex);

#define NML_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if (STD_ON == NML_USE) */


#endif /* NML_INTERNALIF_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
