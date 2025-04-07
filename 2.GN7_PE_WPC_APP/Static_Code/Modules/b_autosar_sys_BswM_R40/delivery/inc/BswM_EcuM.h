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
**  FILE-NAME : BswM_EcuM.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  PURPOSE   : Providing interface to EcuM                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision  Date          By            Description                          **
********************************************************************************
** 2.7.9     03-Aug-2022   Joochan Kim   Modify copyright comment             **
** 2.7.3     07-Sep-2021   Junho Cho     Redmine #31864                       **
** 2.5.2     22-Jul-2016   Sanghoon Bae  Redmine #5583                        **
** 2.1.0     27-Sep-2014   Daejun Park   Redmine #1214                        **
** 1.0.0     04-Mar-2013   Daejun Park   Initial version                      **
*******************************************************************************/

#ifndef BSWM_ECUM_H
#define BSWM_ECUM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM.h"
#include "ComStack_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define BSWM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState
  (EcuM_StateType CurrentState);

extern FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup
  (EcuM_WakeupSourceType source, EcuM_WakeupStatusType state);
#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BSWM_ECUM_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
