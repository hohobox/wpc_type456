/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_Ram.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : Provision for CanNm extern Variable                           **
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
** 2.1.0.1   27-Nov-2020   Sanghoon Kim      #25246                           **
** 2.1.1.0   28-Jan-2021   Sanghoon Kim      #28031                           **
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.3.1.0   24-May-2023   SM Kwon           #40495                           **
** 2.4.0.0   22-Aug-2023   JW Oh             #40502                           **
** 2.5.0.0   04-Nov-2023   JW Oh             #41382                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

#ifndef CANNM_RAM_H
#define CANNM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_PCTypes.h"        /* CanNm configuration header */
#include "NmStack_Types.h"        /* Nm Interface type definitions header */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_RAM_AR_RELEASE_MAJOR_VERSION      4
#define CANNM_RAM_AR_RELEASE_MINOR_VERSION      0
#define CANNM_RAM_AR_RELEASE_REVISION_VERSION   3

/* File version information */
#define CANNM_RAM_SW_MAJOR_VERSION            2
#define CANNM_RAM_SW_MINOR_VERSION            5
#define CANNM_RAM_SW_PATCH_VERSION            1

/*******************************************************************************
**                      MACRO Definitions                                     **
*******************************************************************************/
typedef enum {
  CANNM_NETWORK_TIMEOUT_TIMER_STATE_STOPPED = 0x00,
  CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING
} CANNM_NETWORK_TIMEOUT_TIMER_STATE;

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef struct
{
  CanNm_TimeType ddRemoteSleepIndTime;

  #if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
  /* [Change Wait Bus Sleep Timer API] 
   * ddWaitBusSleepTime should support maximum 18hours => 64,800,000
   * This should be uint32(CanNm_LTimeType) not uint16(CanNm_TimeType)
   */
  CanNm_LTimeType ddWaitBusSleepTime;
  #else
  CanNm_TimeType ddWaitBusSleepTime;
  #endif

  CanNm_TimeType ddRepeatMessageTime;

  /* NM Timeout time for NM PDUs */
  CanNm_TimeType ddNtwkTimeOutTime;

  CANNM_NETWORK_TIMEOUT_TIMER_STATE enNtwkTimeOutTimerState;

  /* Period of NM Message */
  CanNm_TimeType ddMsgCycleTime;
  CanNm_TimeType ddMsgTimeOutTime;

  uint8 aaRxUserData[CANNM_MAX_PDU_INFO_LENGTH];

  uint8 aaTxUserData[CANNM_MAX_PDU_INFO_LENGTH];

  /*ERA array containing PN bits*/
  uint8 aaERA[CANNM_MAX_PN_INFO_LENGTH];

  CanNm_TimeType aaERATimer[CANNM_MAX_PN_INFO_LENGTH * 8U];

  /* For all the States and the Modes*/
  CanNm_ModeState ddModeStatus;
  CanNm_ModeState ddNextModeState;

  /* No. of immediate NM Pdus */
  uint8 ucNoOfImmediateNmTx;

  /*Remote sleep detection*/
  boolean blRemoteSlpDetect;

  boolean blPnStatusBit;

  boolean blNetworkRequested;

  boolean blTxRepeatMessageRequested;

  boolean blCommunicationEnabled;

  boolean blTxActiveWakeUpBit;

  boolean blTxNmCoordinatorSleepReadyBit;

  boolean blBusLoadReductionEnabled;

  boolean blNmCoordReadyToSleepIndicationCalled;

  boolean blTransmissionRequestFailed;

  CanNm_TxState ddTxState;

  NM_STATE ddNmState;

  uint8 ucNetworkRequestReason;

  /* #40502 whether Nm Sleep Ready Bit in CBV is SET or UNSET */
  boolean blNmCoordinatorSlpRdyBtMsgReceived;

  /* #40502 whether Nm_CoordReadyToSleepCancellation() is called or not. */
  boolean blNmCoordReadyToCancellationCalled;

} CanNm_Channel;

#if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* definition for static channel configuration information for the selected variant*/
extern P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) CanNm_GpStaticChannel;
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* definition for static channel configuration information for the selected variant*/
extern P2CONST(uint8, AUTOMATIC, CANNM_CONST) CanNm_GpPnMaskByte;
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/* extern definitions */
#define CANNM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Variable to hold CANNM Initialization Status */
extern VAR(boolean, CANNM_VAR) CanNm_GblInitStatus;
#define CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* extern definition for Channel configuration information array
 *   (for all active channels)  */
extern CONST(NetworkHandleType, CANNM_CONST) CanNm_GddNumberOfChannels;

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
#define CANNM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

extern VAR(CanNm_LTimeType, CANNM_VAR) CanNm_GulUserRequestTWaitBusSleepTime;

#define CANNM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"
#endif

#define CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* extern definition for Channel configuration information array
 *   (for all active channels)  */
extern VAR(CanNm_Channel, CANNM_VAR_NOINIT)
                                    CanNm_GaaChannel[CANNM_NUMBER_OF_CHANNELS];

#define CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(PduIdType, CANNM_CONST) CanNm_PnEiraRxNSduHandleId;

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if(STD_OFF == CANNM_VARIANT_POSTBUILD_PNFILTERMASK)
#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Consists of the PN mask bytes of all the channels.
   Index of this array to be provided in CanNm_GaaStaticChannel for the respective channel */
extern CONST(uint8, CANNM_CONST) CanNm_GaaPnMaskByte[CANNM_PN_INFO_LENGTH];

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblDevErrorDetect;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_8
#include "MemMap.h"

extern CONST(uint8, CANNM_CONST) CanNm_GucPnInfoLength;

#define CANNM_STOP_SEC_CONST_8
#include "MemMap.h"

#define CANNM_START_SEC_CONST_8
#include "MemMap.h"

extern CONST(uint8, CANNM_CONST) CanNm_GucPnInfoOffset;

#define CANNM_STOP_SEC_CONST_8
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(PduIdType, CANNM_CONST) CanNm_GddLastNmChannelHandle;

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblGlobalPnSupport;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblPnEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblPnEraCalcEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblPnEiraCalcEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblComUserDataSupport;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblUserDataEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblPassiveModeEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblNodeDetectionEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblRemoteSleepIndEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblBusLoadReductionEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblCarWakeUpRxEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblCarWakeUpFilterEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblCoordinatorSyncSupport;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblRepeatMsgIndEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(NetworkHandleType, CANNM_CONST) CanNm_GddMinChannelId;

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblBusSynchronizationEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblImmediateRestartEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblVersionInfoApi;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblPduRxIndicationEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblStateChangeIndEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblComControlEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblImmediateTxConfEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define CANNM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, CANNM_CONST) CanNm_GblForcePnAvailabilityConfEnabled;

#define CANNM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"


#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(PduIdType, CANNM_CONST) CanNm_GddPduRCanNmRxIndicationEiraHandleId;

#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CANNM_RAM_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
