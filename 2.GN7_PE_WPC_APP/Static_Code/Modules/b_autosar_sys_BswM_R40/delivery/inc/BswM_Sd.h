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
**  FILE-NAME : BswM_Sd.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  PURPOSE   : Providing interface to Sd                                     **
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
** 2.7.0     11-Mar-2020   Junho Cho     Initial version                      **
*******************************************************************************/

#ifndef BSWM_SD_H
#define BSWM_SD_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Sd.h"

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
/* Extern for BswM_Sd_ClientServiceCurrentState */
extern FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState
 (uint16 SdClientServiceHandleId, Sd_ClientServiceCurrentStateType CurrentClientState);

/* Extern for BswM_Sd_ConsumedEventGroupCurrentState */
extern FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState
 (uint16 SdConsumedEventGroupHandleId, Sd_ConsumedEventGroupCurrentStateType ConsumedEventGroupState);

/* Extern for BswM_Sd_EventHandlerCurrentState */
extern FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState
 (uint16 SdEventHandlerHandleId, Sd_EventHandlerCurrentStateType EventHandlerStatus);
#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BSWM_SD_H */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
