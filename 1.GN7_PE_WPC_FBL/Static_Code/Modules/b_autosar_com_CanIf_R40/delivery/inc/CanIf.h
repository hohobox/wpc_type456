/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf.h                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service Ids     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
*******************************************************************************/
/*******************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 3.2.0    17-Jan-2025    Jh.Yang   #49837                                   **
** 3.1.1    08-Sep-2023    Jh.Yang   #42630                                   **
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.6    26-May-2023    Mu.Kim    #38439                                   **
** 3.0.3    15-Mar-2022    Sj.Kim    #34766                                   **
** 3.0.1    28-Dec-2021    Sj.Kim    #33378                                   **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.1    25-Nov-2020    Sj.Kim    #26002                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384                                   **
** 2.5.8    10-Jul-2019    Js.Lim    #18347                                   **
** 2.5.5    16-Jan-2018    Js.Lim    #10934                                   **
** 2.5.3    11-Sep-2017    Js.Lim    #9889                                    **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 2.2.6    12-Aug-2016    Kt.Kim    #5739                                    **
** 2.2.5    13-Jun-2016    Kt.Kim    #5139                                    **
** 2.2.4    05-Jan-2016    Kt.Kim    #3813                                    **
** 2.2.3    16-Dec-2015    Kt.Kim    Code fix for MISRA 14.2                  **
** 2.2.2    13-Jun-2015    Kt.Kim    #2724                                    **
** 2.1.0    29-May-2013    Kt.Kim    OsekNm Support                           **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef CANIF_H
#define CANIF_H

#include "ComStack_Types.h"     /* STANDARD Types Header File */
#include "CanIf_Cfg.h"          /* Configuration header file */
#include "CanIf_Types.h"        /* Type definition header file */
#include "CanIf_IntTypes.h"     /* Type definition header file */
#if (STD_ON == CANIF_AUTOEVER_CANTRCV_SUPPORT)
#include "CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_EXTENAL_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_WAKEUP_SUPPORT)
#include "EcuM.h"               /* EcuM header file */
#endif
#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"         /* PduR header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"          /* CanTp header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"          /* CanNm header file */
#endif
#if ((STD_ON == CANIF_TX_XCP_CALLBACK) || (STD_ON == CANIF_RX_XCP_CALLBACK))
#include "Xcp_Cbk.h"            /* Xcp header file */
#endif
#if ((STD_ON == CANIF_TX_J1939TP_CALLBACK) || \
                                          (STD_ON == CANIF_RX_J1939TP_CALLBACK))
#include "J1939Tp_Cbk.h"        /* J1939Tp header file */
#endif
/* #5139 */
#if ((STD_ON == CANIF_TX_J1939NM_CALLBACK) || \
                                          (STD_ON == CANIF_RX_J1939NM_CALLBACK))
#include "J1939Nm_Cbk.h"        /* J1939Nm header file */
#endif
#include "CanIf_UserInc.h"
#include "CanIf_Dbg.h"
#include <string.h>             /* For use memset */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_CANIF_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_CANIF_AR_RELEASE_MINOR_VERSION    0
#define CANIF_CANIF_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define CANIF_CANIF_SW_MAJOR_VERSION    3
#define CANIF_CANIF_SW_MINOR_VERSION    2


/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* Invalid CAN ID is reported using following error code */
#define CANIF_E_PARAM_CANID            ((uint8)10)

/* Invalid DLC is reported using following error code */
#define CANIF_E_PARAM_DLC              ((uint8)11)

/* Invalid HRH is reported using following error code */
#define CANIF_E_PARAM_HRH              ((uint8)12)

/* Invalid controller ID is reported using following error code */
#define CANIF_E_PARAM_CONTROLLER       ((uint8)14)

/* Invalid controller ID is reported using following error code */
#define CANIF_E_PARAM_CONTROLLERID     ((uint8)15)

/* Invalid wakeup source ID is reported using following error code*/
#define CANIF_E_PARAM_WAKEUPSOURCE     ((uint8)16)

/* Invalid mode request is reported using following error code */
#define CANIF_E_PARAM_TRCV             ((uint8)17)

/* Invalid pointer input is reported using following error code */
#define CANIF_E_PARAM_TRCVMODE         ((uint8)18)

/* API service called with wrong database addresss */
#define CANIF_E_PARAM_TRCVWAKEUPMODE   ((uint8)19)

/* API service used without module initialization */
#define CANIF_E_PARAM_CTRLMODE         ((uint8)21)

/* DET error used with parameter passed as null pointer */
#define CANIF_E_PARAM_POINTER          ((uint8)20)

/* DET error reported when module is unintialized */
#define CANIF_E_UNINIT                 ((uint8)30)

/* Not supported API request is reported using following error code */
#define CANIF_E_INVALID_TXPDUID        ((uint8)50)

/* Invalid Transceiver Id */
#define CANIF_E_INVALID_RXPDUID        ((uint8)60)

/* Invalid CAN Transceiver operation Mode */
#define CANIF_E_INVALID_DLC            ((uint8)61)

/* Invalid PDU Mode */
#define CANIF_E_PARAM_PDU_MODE         ((uint8)22)

/* Invalid LPDU*/
#define CANIF_E_PARAM_LPDU             ((uint8)13)

/* Invalid CAN Transceiver operation Mode */
#define CANIF_E_STOPPED                ((uint8)70)

/* Invalid Tx-Pdu ID is reported using following error code */
#define CANIF_E_NOT_SLEEP              ((uint8)71)

/* Macro to check whether wake up is disabled */
#define CANIF_WAKEUP_DISABLED          ((uint8)0x00)

/* Macro to check whether wake up is enabled */
#define CANIF_WAKEUP_ENABLED           ((uint8)0x01)

/* Macro to check for invalid value */
#define CANIF_INVALID                  ((PduIdType)0xffff)

/* Macro to check for invalid Controller/Tranceiver ID */
#define CANIF_INVALID_ID               ((uint8)0xff)

/* Macro for error id for transciever */
#define CANIF_E_TRANSCEIVER            ((uint8)91)

/* macro for invalid rxpduid */
#define CANIF_INVALID_RXPDUID          ((PduIdType)0xffff)

/* macro for gateway buffer state */
#define CANIF_GW_NOREQUEST   ((uint8)0x00)
#define CANIF_GW_STOPPED     ((uint8)0x01)
#define CANIF_GW_REQUESTED   ((uint8)0x02)
#define CANIF_GW_NOCOMM      ((uint8)0x03)
#define CANIF_GW_ERRVOL      ((uint8)0x04)

/* Macro for Cancellation unsed */
#define CANIF_AUTOEVER_AUTOSAR_CANCELLATION_USED (STD_OFF)

/*******************************************************************************
**                      Macro                                                 **
*******************************************************************************/
/* polyspace-begin MISRA-C3:D4.9 [Not a defect:Justified] "Use function like-macro for removing unused argument compiler warning" */

#if (STD_ON == CANIF_CANFD_SUPPORT)
#define CANIF_SDU_MAX_LENGTH \
  ((LpTxLpdu->ucCanIdType == CANIF_CANFD_EXTENDED_CANID_TYPE || \
    LpTxLpdu->ucCanIdType == CANIF_CANFD_STANDARD_CANID_TYPE) ? \
  CANIF_CANFD_MAX_LENGTH : CANIF_EIGHT)
#else
#define CANIF_SDU_MAX_LENGTH CANIF_EIGHT
#endif

#define CANIF_TXPDU_GW_STATUS(x) (CanIf_GaaTxPduGwStatus[(x)])
/* polyspace-end MISRA-C3:D4.9 [Not a defect:Justified] "Use function like-macro for removing unused argument compiler warning" */

/*******************************************************************************
**                      Service Id of API                                     **
*******************************************************************************/
	/* Instance ID */
#define CANIF_INSTANCE_ID                     ((uint8)0x00)
/* Service ID for CanIf_Init */
#define CANIF_INIT_SID                        ((uint8)0x01)
/* Service ID for CanIf_SetController */
#define CANIF_SET_CNTRL_MODE_SID              ((uint8)0x03)
/* Service ID for CanIf_GetControllerMode */
#define CANIF_GET_CNTRL_MODE_SID              ((uint8)0x04)
/* Service ID for CanIf_Transmit */
#define CANIF_TRANSMIT_SID                    ((uint8)0x05)
/* Service ID for CanIf_ReadRxPduData */
#define CANIF_READ_RXPDU_DATA_SID             ((uint8)0x06)
/* Service ID for CanIf_ReadTxNotifStatus */
#define CANIF_READ_TX_NOTIF_STATUS_SID        ((uint8)0x07)
/* Service ID for CanIf_ReadRxNotifStatus */
#define CANIF_READ_RX_NOTIF_STATUS_SID        ((uint8)0x08)
/* Service ID for CanIf_SetPduMode */
#define CANIF_SET_PDU_MODE_SID                ((uint8)0x09)
/* Service ID for CanIf_GetPduMode */
#define CANIF_GET_PDU_MODE_SID                ((uint8)0x0a)
/* Service ID for CanIf_VersionInfo */
#define CANIF_GET_VERSIONNFO_SID              ((uint8)0x0b)
/* Service ID for CanIf_SetDynamicTxId */
#define CANIF_SET_DYNAMIC_TXID_SID            ((uint8)0x0c)
/* Service ID for CanIf_SetTrcvMode */
#define CANIF_SET_TRCV_MODE_SID               ((uint8)0x0d)
/* Service ID for CanIf_GetTrcvMode */
#define CANIF_GET_TRCV_MODE_SID               ((uint8)0x0e)
/* Service ID for CanIf_GetTrcvWakeupReason */
#define CANIF_GET_TRCV_WAKEUPREASON_SID       ((uint8)0x0f)
/* Service ID for CanIf_SetTransceiverWakeupMode */
#define CANIF_SET_TRCV_WAKEUP_MODE_SID        ((uint8)0x10)
/* Service ID for CanIf_CheckWakeup */
#define CANIF_CHECK_WAKEUP_SID                ((uint8)0x11)
/* Service ID for CanIf_CheckValidation */
#define CANIF_CHECK_VALIDATION_SID            ((uint8)0x12)
/* Service ID for CanIf_TxConfirmation */
#define CANIF_TX_CONFIRMATION_SID             ((uint8)0x13)
/* Service ID for CanIf_RxIndication */
#define CANIF_RX_INDICATION_SID               ((uint8)0x14)
/* Service ID for CanIf_CancelTxConfirmation */
#define CANIF_CANCEL_TX_CONFRM_SID            ((uint8)0x15)
/* Service ID for CanIf_ControllerBusOff */
#define CANIF_CNTRL_BUS_OFF_SID               ((uint8)0x16)
/* Service ID for CanIf_ControllerModeIndication */
#define CANIF_CTRL_MODE_IND_SID               ((uint8)0x17)
/* Service ID for CanIf_CancelTransmit */
#define CANIF_CANCEL_TRANSMIT_SID             ((uint8)0x18)
/* Service ID for CanIf_GetTxConfirmationState */
#define CANIF_GET_TX_CONFIRM_STATE_SID        ((uint8)0x19)
/* Service ID for CanIf_ConfirmPnAvailability */
#define CANIF_CONFIRM_PN_AVAILIBILITY_SID     ((uint8)0x1a)
/* Service ID for CanIf_ChangeBaudrate */
#define CANIF_CHANGE_BAUD_RATE_SID            ((uint8)0x1b)
/* Service ID for CanIf_CheckBaudrate */
#define CANIF_CHECK_BAUD_RATE_SID             ((uint8)0x1c)
/* Service ID for CanIf_ClearTrcvWufFlag */
#define CANIF_CLEAR_TRCV_WUF_SID              ((uint8)0x1e)
/* Service ID for CanIf_CheckTrcvWakeFlag */
#define CANIF_CHECK_TRCV_WAKE_SID             ((uint8)0x1f)
/* Service ID for CanIf_ClearTrcvWufFlagIndication */
#define CANIF_CLEAR_TRCV_WAKE_FLAG_IND_SID    ((uint8)0x20)
/* Service ID for CanIf_CheckTrcvWakeFlagIndication */
#define CANIF_CHECK_TRCV_WAKE_FLAG_IND_SID    ((uint8)0x21)
/* Service ID for CanIf_TrcvModeIndication */
#define CANIF_TRCV_MODE_IND_SID               ((uint8)0x22)
/* Service ID for CanIf_SetBatteryVoltageMode */
#define CANIF_SET_BAT_VOL_MODE_SID            ((uint8)0x23)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_Init (P2CONST(CanIf_ConfigType, AUTOMATIC,
                                                   CANIF_APPL_CONST) ConfigPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode (
                       VAR(uint8, CANIF_VAR) ControllerId,
                       VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetControllerMode (
 VAR(uint8, CANIF_VAR) ControllerId,
 P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit (
                  VAR(PduIdType, CANIF_VAR) CanTxPduId,
                  P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANCEL_TRANSMIT_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit (
                                          VAR(PduIdType, CANIF_VAR) CanTxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_READRXPDU_DATA_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData (
                     VAR(PduIdType, CANIF_VAR) CanRxPduId,
                     P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_TX_LPDU) && (STD_ON == CANIF_READTXPDU_NOTIFY_STATUS_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus (
                                          VAR(PduIdType, CANIF_VAR) CanTxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(
                                          VAR(PduIdType, CANIF_VAR) CanRxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode (
                           VAR(uint8, CANIF_VAR) ControllerId,
                           VAR(CanIf_PduSetModeType, CANIF_VAR) PduModeRequest);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetPduMode (
            VAR(uint8, CANIF_VAR) ControllerId,
            P2VAR(CanIf_PduGetModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANIF_VERSION_INFO_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin MISRA-C3:D4.5 [Not a defect: Justified] "No Impact of this rule violation" */
extern FUNC(void, CANIF_CODE)CanIf_GetVersionInfo
           (P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA)VersionInfo);
/* polyspace-end MISRA-C3:D4.5 [Not a defect: Justified] "No Impact of this rule violation" */
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_TX_LPDU) && (STD_ON == CANIF_SETDYNAMICTXID_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE)CanIf_SetDynamicTxId (
                                           VAR(PduIdType, CANIF_VAR) CanTxPduId,
                                           VAR(Can_IdType, CANIF_VAR) CanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode (
                          VAR(uint8, CANIF_VAR) TransceiverId,
                          VAR(CanTrcv_TrcvModeType, CANIF_VAR) TransceiverMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
           (P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_VAR)TransceiverModePtr,
            VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason (
      VAR(uint8, CANIF_VAR) TransceiverId,
      P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_VAR)TrcvWuReasonPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode (
                     VAR(uint8, CANIF_VAR) TransceiverId,
                     VAR(CanTrcv_TrcvWakeupModeType, CANIF_VAR) TrcvWakeupMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup (
                            VAR(EcuM_WakeupSourceType, CANIF_VAR) WakeupSource);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_WAKEUP_CHECK_VALIDATION_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation (
                            VAR(EcuM_WakeupSourceType, CANIF_VAR) WakeupSource);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TXCONFIRM_POLLING_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_GetTxConfirmationState (
                                            VAR(uint8, CANIF_VAR) ControllerId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_403)
#if (STD_ON == CANIF_CHANGE_BAUDRATE_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckBaudrate (
                                            VAR(uint8, CANIF_VAR) ControllerId,
                                           CONST(uint16, CANIF_CONST) Baudrate);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ChangeBaudrate (
                                           VAR(uint8, CANIF_VAR) ControllerId,
                                           CONST(uint16, CANIF_CONST) Baudrate);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (STD_ON == CANIF_CHANGE_BAUDRATE_SUPPORT) */
#endif /* #if (CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_403) */

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_PN_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* internally used for Direct OSKEK NM */
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,CANIF_CODE) CanIf_ReadRxCanId
           (P2VAR(Can_IdType, AUTOMATIC, CANIF_APPL_DATA) CanIdPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBatteryVoltageMode(
        VAR(uint8, CANIF_VAR) ControllerId,
        VAR(CanIf_BatVolSetModeType, CANIF_VAR) BatteryVolMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"


#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ReadBusMsgCount (
                  VAR(uint8, CANIF_VAR) Controller,
                  P2VAR(CanIf_MsgType, AUTOMATIC, CANIF_APPL_VAR) MsgCnt);


#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif /* CANIF_H */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
