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
**  SRC-MODULE: CtrlRam.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CtrlRam Module                                        **
**                                                                            **
**  PURPOSE   : Watchdog Manager API Functionality                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By          Description                         **
********************************************************************************
** 1.0.8       04-Aug-2022   YH.Han       Redmine #36978                      **
** 1.0.0       25-Jan-2013                Initial version                     **
*******************************************************************************/

#ifndef CTRLRAM_H
#define CTRLRAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CtrlRam_Cfg.h"          /* Configuration header file */
#include "CtrlRam_Config.h"          /* Configuration header file */


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/




/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* TODO : Temporary ID */
#define CTRLRAM_MODULE_ID                                    (uint16)77

/* Macro for Instance Id to be used for reporting Det error
*  "NM_E_HANDLE_UNDEF".
*/
#define CTRLRAM_INSTANCE_ID                      (uint8)0x00

/* API Service Ids */
#define CTRLRAM_MAINFUNCTION_SID               (uint8)0x10
#define CTRLRAM_GETSTATUS_SID                  (uint8)0x11



/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CTRLRAM_CODE) CtrlRam_Init (void);

#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CTRLRAM_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
