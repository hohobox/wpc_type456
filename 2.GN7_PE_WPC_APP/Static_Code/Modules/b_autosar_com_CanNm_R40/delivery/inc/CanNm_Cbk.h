/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_Cbk.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : Provision for Call back declaration and macro defination      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date        By                Description                        **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

#ifndef CANNM_CBK_H
#define CANNM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_Cfg.h"            /* CanNm Configuration header */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_CBK_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_CBK_AR_RELEASE_MINOR_VERSION    0
#define CANNM_CBK_AR_RELEASE_REVISION_VERSION 3

/* CANNM software version information */
#define CANNM_CBK_SW_MAJOR_VERSION            2
#define CANNM_CBK_SW_MINOR_VERSION            5
#define CANNM_CBK_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANNM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, CANNM_CODE) CanNm_TxConfirmation(PduIdType TxPduId);

extern FUNC(void, CANNM_CODE) CanNm_RxIndication(
  PduIdType RxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr);

extern FUNC(void, CANNM_CODE) CanNm_ConfirmPnAvailability(
  CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_TriggerTransmit(
  PduIdType TxPduId,
  P2VAR(PduInfoType, AUTOMATIC, CANNM_VAR) PduInfoPtr);

#define CANNM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANNM_CBK_H */

/*******************************************************************************
**                               END OF FILE                                  **
*******************************************************************************/
