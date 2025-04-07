/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Tx.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Header file of CanIf_Tx.c                                     **
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
** 3.2.0    17-Jan-2025    Jh.Yang   #49837                                   **
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384                                   **
** 2.5.0    06-Dec-2016    Js.Lim    #7077                                    **
** 2.2.2    12-Feb-2016    Kt.Kim    #3813                                    **
** 2.2.1    17-Aug-2015    Kt.Kim    Cleared violation against MISRA 2.2/2.3  **
** 2.2.0    17-Jun-2013    Kt.Kim    Lib-Build Support                        **
**                                   Restore CANIF_TX_QUEUE define            **
** 2.1.0    30-May-2013    Kt.Kim    Lib-Build Support                        **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

#ifndef CANIF_TX_H
#define CANIF_TX_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"                  /* CanInterface header file */
#include "CanIf_Ram.h"              /* Ram header file */
#include "CanIf_IntTypes.h"         /* CanIf Internal Types header file */
#include "CanIf_Error.h"            /* CanIf DET Error file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_TX_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_TX_AR_RELEASE_MINOR_VERSION       0
#define CANIF_TX_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_TX_SW_MAJOR_VERSION    3
#define CANIF_TX_SW_MINOR_VERSION    2
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearTxQueue (
 P2CONST(CanIf_ControllerConfigType, AUTOMATIC, CANIF_CONST) LpStaticController);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_QueueTransmit (
                         P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)LpTxLpdu);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TxNotification (
                        P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if ((STD_ON == CANIF_TX_LPDU) && (STD_ON == CANIF_AUTOEVER_AUTOSAR_CANCELLATION_USED) && (STD_ON == CANIF_BASIC_CAN_TXPDU))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_TxQueueType, CANIF_CODE) CanIf_CheckQueueStatus (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)LpTxBuffer);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TxQueueHandling (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer,
                     VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif


#endif /* CANIF_TX_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
