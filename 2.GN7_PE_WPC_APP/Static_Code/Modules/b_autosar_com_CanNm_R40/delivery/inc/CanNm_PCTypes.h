/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_PCTypes.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : File conatins structure defination                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date         By                Description                       **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.1.0.1   27-Nov-2020   Sanghoon Kim      #25246                           **
** 2.1.1.0   28-Jan-2021   Sanghoon Kim      #28031                           **
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.3.1.0   24-May-2023   SM Kwon           #40495, 40496                    **
** 2.5.0.0   04-Nov-2023   JW Oh             #41382                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

#ifndef CANNM_PCTYPES_H
#define CANNM_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_Cfg.h"            /* CanNm Configuration header file */
#include "SchM_CanNm.h"           /* CanNm Schm functions header file */
#include "CanIf.h"               /* Canif header file*/
#include "Nm_Cbk.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_PCTYPES_AR_RELEASE_MAJOR_VERSION       4
#define CANNM_PCTYPES_AR_RELEASE_MINOR_VERSION       0
#define CANNM_PCTYPES_AR_RELEASE_REVISION_VERSION    3


/* File version information */
#define CANNM_PCTYPES_SW_MAJOR_VERSION            2
#define CANNM_PCTYPES_SW_MINOR_VERSION            5
#define CANNM_PCTYPES_SW_PATCH_VERSION            1

/*******************************************************************************
**                      MACRO Definitions                                     **
*******************************************************************************/

/* Time for which the NM shall stay in the Prepare-bus Sleep mode before
 *   transiting into the Bus-Sleep mode */

/* Macros for numerical Values */
#define CANNM_MAX_PDU_SIZE                     (uint8) 0x08
#define CANNM_ZERO                             (uint8) 0x00
#define CANNM_ONE                              (uint8) 0x01
#define CANNM_SEVEN                            (uint8) 0x07
#define CANNM_EIGHT                            (uint8) 0x08

/* Macros for boolean Values */
#define CANNM_FALSE                            (boolean) 0x00
#define CANNM_TRUE                             (boolean) 0x01

/* Macro for initial data */
#define CANNM_INITIAL_DATA                     (uint8) 0x00

/* CanNm intermediate channel state and mode status mask */
#define CANNM_STATE_MASK                       (uint8) 0x0F
#define CANNM_NETWORK_STATE_MASK               (uint8) 0x1F
#define CANNM_MODE_MASK                        (uint8) 0x02
#define CANNM_INTERMED_STATE_MASK              (uint8) 0xC0
#define CANNM_PREVIOUS_STATE_MASK              (uint8) 0x3F

/* [Change Wait Bus Sleep Timer API] 
 * Declaration of CanNm Large Time Type for supporting 18 hours(64,800,000 msec)
 */
#if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
/* CanNm Large TimeType */
typedef uint32 CanNm_LTimeType;
#endif
/* end of Change Wait Bus Sleep Timer API */


/*CanNm Modes and states */
typedef enum {
  CANNM_STATE_UNINIT = 0x00,
  CANNM_BUS_SLEEP_MODE,
  CANNM_PREPAREBUS_SLEEP_MODE,
  CANNM_READY_SLEEP_STATE,
  CANNM_NORMAL_OPERATION_STATE,
  CANNM_REPEAT_MESSAGE_STATE
} CanNm_ModeState;

/*CanNm Modes and states */
typedef enum {
  CANNM_TX_STATE_READY = 0x00,
  CANNM_TX_STATE_WAIT_CONFIRM,
} CanNm_TxState;

typedef enum {
  NM_STATE_UNDEFINED,
  NM_STATE_NS_RMS,
  NM_STATE_NS_RSS,
  NM_STATE_RMS_BSM,
  NM_STATE_RMS_PBSM,
  NM_STATE_RMS_NS,
  NM_STATE_RMS_RSS,
  NM_STATE_RSS_RMS,
  NM_STATE_RSS_NS,
  NM_STATE_PBSM_RSS,
  NM_STATE_BSM_PBSM
} NM_STATE;

typedef enum {
  CANNM_INIT_SID = 0x00,
  CANNM_PASSIVE_STARTUP_SID = 0x01,
  CANNM_NETWORK_REQUEST_SID = 0x02,
  CANNM_NETWORK_RELEASE_SID = 0x03,
  CANNM_SET_USERDATA_SID = 0x04,
  CANNM_GET_USERDATA_SID = 0x05,
  CANNM_GET_NODEIDENTIFIER_SID = 0x06,
  CANNM_GET_LOCALNODEIDENTIFIER_SID = 0x07,
  CANNM_REPEAT_MESSAGEREQUEST_SID = 0x08,
  CANNM_GET_PDUDATA_SID = 0x0a,
  CANNM_GET_STATE_SID = 0x0b,
  CANNM_DISABLE_COMMUNICATION_SID = 0x0c,
  CANNM_ENABLE_COMMUNICATION_SID = 0x0d,
  CANNM_DEINIT_SID = 0x10,
  CANNM_MAINFUNCTION_SID = 0x13,
  CANNM_CONFIRM_PNAVAILABILITY_SID = 0x16,
  CANNM_SET_SLEEP_READYBIT_SID = 0x17,
  CANNM_TX_CONFIRMATION_SID = 0x40,
  CANNM_TRIGGER_TRANSMIT_SID = 0x41,
  CANNM_RX_INDICATION_SID = 0x42,
  CANNM_TRANSMIT_SID = 0x49,
  CANNM_REQUEST_BUSSYNCHRONIZATION_SID = 0xc0,
  CANNM_CHECK_REMOTESLEEPINDICATION_SID = 0xd0,
  CANNM_GET_VERSIONINFO_SID = 0xf1
} CANNM_SERVICE_ID;

/* DET Error Codes */
typedef enum {
  CANNM_E_UNINIT = 0x01,
  CANNM_E_INVALID_CHANNEL = 0x02,
  CANNM_E_INVALID_PDUID = 0x03,
  CANNM_E_NET_START_IND = 0x04,
  CANNM_E_INIT_FAILED = 0x05,
  CANNM_E_NETWORK_TIMEOUT = 0x11,
  CANNM_E_PARAM_POINTER = 0x12,
  CANNM_E_NOT_IN_BUS_SLEEP = 0x13,
  CANNM_E_INVALID_REQUEST = 0x20
} CANNM_ERROR_CODE;


typedef enum {
  CANNM_RX_HANDLING_METHOD_IGNORE = 0x00,
  CANNM_RX_HANDLING_METHOD_PROCESS_WITH_PARTIAL_NETWORK,
  CANNM_RX_HANDLING_METHOD_PROCESS_WITHOUT_PARTIAL_NETWORK
} CANNM_RX_HANDLING_METHOD;

/*CanNm Transmission mode */
#define CANNM_EXPECT_TXCONFIRM                 (uint8) 0x10
#define CANNM_RESET_EXPECT_TXCONFIRM           (uint8) 0xEF
#define CANNM_RX_STATUS_MASK                   (uint8) 0x01
#define CANNM_TXCONFIRM_STATUS                 (uint8) 0x80
#define CANNM_RESET_NOTIFYSTATUS               (uint8) 0x7E

/* Macro for repeat msg and network request */
#define CANNM_NW_REQ                           (uint8) 0x40
#define CANNM_REPTMSG_BIT                      (uint8) 0x01
#define CANNM_ACTWKP_BIT                       (uint8) 0x10
#define CANNM_SETSLEEP_BIT                     (uint8) 0x08
#define CANNM_PNI_BIT                          (uint8) 0x40

/* Macro for repeat msg and network request mask */
#define CANNM_RESET_REPEAT_MSG_REQ             (uint8) 0xDF
#define CANNM_RESET_NW_REQ                     (uint8) 0xBF
#define CANNM_IMM_PDU_PRESENT                  (uint8) 0x80
#define CANNM_RESET_IMM_PDU                    (uint8) 0x7F

/*Macro for Partial Networking*/
#define CANNM_PN_BIT_ENABLED_MASK              (uint8) 0x40

#define CANNM_SLEEP_READY_BIT                  (uint8) 0x08

#define CANNM_MAX_PN_INFO_LENGTH                63U

#define CANNM_MAX_PDU_INFO_LENGTH               64U

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* The following structure contains Pre-Compile time configuration required for CANNM module */

/* polyspace-begin MISRA2012:D4.8 [Not a defect:Low] "No Impact of this rule violation" */

typedef struct
{
  /* [Change Wait Bus Sleep Timer API]
   * ddWaitBusSleepTime should support maximum 18 hours => 64,800,000 msec
   * if support change T_WaitBusSleep
   * This should be uint32(CanNm_LTimeType) not uint16(CanNm_TimeType)
   */
  #if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
  CanNm_LTimeType ddWaitBusSleepTime;
  #else
  /* Time for which the NM shall stay in the Prepare-bus Sleep mode before
   *   transiting into the Bus-Sleep mode 
   */
  CanNm_TimeType ddWaitBusSleepTime;
  #endif

  /* NM Timeout time for NM PDUs */
  CanNm_TimeType ddNtwkTimeOutTime;

  /* Timeout time for Repeat message state */
  CanNm_TimeType ddRepeatMsgTime;

  /* Timeout time for Remote Sleep Indication */
  CanNm_TimeType ddRemoteSleepIndTime;

  /* Node specific bus cycle time in the periodic transmission mode with bus
   *   load reduction */
  CanNm_TimeType ddMsgRedTime;

  /* Period of NM Message */
  CanNm_TimeType ddMsgCycleTime;

  /* Time offset in the periodic transmission mode */
  CanNm_TimeType ddMsgCycleOffset;

  /* Transmission Timeout time of NM-message */
  CanNm_TimeType ddMsgTimeOutTime;

  /* Period of Immediate NM Message */
  CanNm_TimeType ddImmMsgCycleTime;

  /* Partial Networking NM PDU cycle time (CanNmPnResetTime) */
  CanNm_TimeType ddPnResetTime;

  /* L-PDU handle of the NM PDU to be transmitted by CanIf_Transmit */
  PduIdType ddTxPduId;

  /* Represent CarWakeup Byte position and Bit position
   *                                       (CanNmCarWakeUpBytePosition)  */
  uint8 ucCarWakeupByte;

  /* CanNm Car WakeUp Node ID (CanNmCarWakeUpFilterNodeId) */
  uint8 ucCarWkpNodeId;

  /* CanNm Car WakeUp Mask based on CarWakeup bit(CanNmCarWakeUpBitPosition) */
  uint8 ucCarWakeupMask;

  /* Number of Nm messages to be transmitted by ddImmMsgCycleTime*/
  uint8 ucNoOfImmediateNmTx;

  /* Length of the data contained in the NM PDU */
  uint8 ucUserDataLength;

  /* Length of the Nm PDU */
  uint8 ucPduLength;

  /* Position of the source node identifier within the NM PDU */
  uint8 ucPduNidPosition;

  /* Index of the user data array */
  uint8 ucDataArrayIndex;

  /* Position of the control bit vector within the NM PDU */
  uint8 ucPduCbvPosition;

  /* CanNm Channel Node ID */
  uint8 ucNodeId;

  /* L-PDU handle of the NM PDU to be referred by Com Module */
  PduIdType ddComTxPduId;

  /* Channel handle to be passed to the upper layer (NM Interface) */
  NetworkHandleType ddNmChannelHandle;

  /* Bus load reduction active for a particular NM channel */
  boolean blBusLoadRedActive;

  boolean blActiveWakeupBitEnabled;

  PduIdType ddPnEraRxNSduHandleId;

  boolean blAllNmMessagesKeepAwake;

  boolean blPnEnabled;

  boolean blPnEraCalcEnabled;

  boolean blCarWakeUpRxEnabled;

  boolean blCarWakeUpFilterEnabled;

  boolean blPnHandleMultipleNetworkRequests;

  boolean blNodeIdEnabled;

  boolean blPduRTriggerTransmit;

  boolean blCanIfTriggerTransmit;

  PduIdType ddCanNmTransmitHandleId;

  PduIdType ddPduRTriggerTransmitHandleId;

  PduIdType ddCanNmTxConfirmationHandleId;

  PduIdType ddPduRCanNmTxConfirmationHandleId;

  PduIdType ddPduRCanNmRxIndicationEraHandleId;

  /* Position of the Nm State within the NM PDU */
  uint8 ucPduNmStatePosition;

  /* Position of the Network Request Reason within the NM PDU */
  uint8 ucPduNetworkRequestReasonPosition;

  /* Initial value of each byte of user data within the NM PDU */
  uint8 ucUserDataInitValue;
} CanNm_StaticChannel;

/* polyspace-end MISRA2012:D4.8 [Not a defect:Low] "No Impact of this rule violation" */

typedef struct
{
   PduIdType ddCanNmRxPduId;
   uint32 ulCanNmChannelIndex;
} CanNm_RxPdu;

typedef struct
{
   PduIdType ddCanNmTxPduId;
   uint32 ulCanNmChannelIndex;
} CanNm_TxPdu;

/* Structure for CanNm_PduPosition Type*/
typedef enum
{
  CANNM_PDU_BYTE_0 = 0x00,
  CANNM_PDU_BYTE_1 = 0x01,
  CANNM_PDU_OFF = 0xFF
} CanNm_PduPositionType;

/* polyspace-begin MISRA2012:D4.8 [Not a defect:Low] "No Impact of this rule violation" */
typedef struct
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) pCanNmStaticChannel;
  P2CONST(uint8, AUTOMATIC, CANNM_CONST) pCanNmPnFilterMaskByte;
} CanNm_ConfigType;
/* polyspace-end MISRA2012:D4.8 [Not a defect:Low] "No Impact of this rule violation" */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config[];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(STD_OFF == CANNM_VARIANT_POSTBUILD_NODEID)
#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* extern definition for Channel configuration information array(for all active channels) */
extern CONST(CanNm_StaticChannel, CANNM_CONST) CanNm_GaaStaticChannel[CANNM_NUMBER_OF_CHANNELS];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanNm_TxPdu, CANNM_CONST) CanNm_GaaTxPdu[CANNM_NUMBER_OF_TX_PDU];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, CANNM_CONST) CanNm_GaaDiscreteDlctoDataLength[CANNM_EIGHT];
#define CANNM_STOP_SEC_CONST_8
#include "MemMap.h"

#define CANNM_START_SEC_CONST_32
#include "MemMap.h"
extern CONST(uint32, CANNM_CONST) CanNm_GulTxPduSize;
#define CANNM_STOP_SEC_CONST_32
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanNm_RxPdu, CANNM_CONST) CanNm_GaaRxPdu[CANNM_NUMBER_OF_RX_PDU];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_32
#include "MemMap.h"
extern CONST(uint32, CANNM_CONST) CanNm_GulRxPduSize;
#define CANNM_STOP_SEC_CONST_32
#include "MemMap.h"

#define CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
extern VAR(uint8, CANNM_VAR) CanNm_GaaEIRA[CANNM_MAX_PN_INFO_LENGTH];
#define CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
extern VAR(CanNm_TimeType, CANNM_VAR) CanNm_GaaPnEIRATimer[(CANNM_MAX_PN_INFO_LENGTH * 8U)];
#define CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                     Function Prototypes                                    **
*******************************************************************************/
#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_RemoteSleepIndication) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_RemoteSleepCancellation) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_CarWakeUpIndication) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_RepeatMessageIndication) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_CoordReadyToSleepIndication) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_CoordReadyToSleepCancellation) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_PduRxIndication) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_StateChangeNotification)
  (CONST(NetworkHandleType, CANNM_CONST), CONST(Nm_StateType, CANNM_CONST), CONST(Nm_StateType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnNm_TxTimeoutException) (CONST(NetworkHandleType, CANNM_CONST));

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnCanSM_TxTimeoutException) (NetworkHandleType Channel);

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

extern P2FUNC(void, NM_CODE, pfnPduR_CanNmRxIndication) (PduIdType IfRxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_DATA) PduInfoPtr);

#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#endif /* CANNM_PCTYPES_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
