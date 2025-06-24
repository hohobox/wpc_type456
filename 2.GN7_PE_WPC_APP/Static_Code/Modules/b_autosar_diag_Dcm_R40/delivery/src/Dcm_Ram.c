/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Global variable definitions                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                Description                      **
********************************************************************************
** 2.16.0.0  30-Apr-2025   Jihye Lee       #CP44STD-1072                      **
**                                                                            **
** 2.15.0.0  27-Nov-2024   Suyon Kim       #48863                             **
**                                                                            **
** 2.14.1.0  08-Nov-2024   Jihye Lee       #48743                             **
**                                                                            **
** 2.14.0.0  30-Sep-2024   Haewon Seo      #48771                             **
**                                                                            **
** 2.12.0.0  17-Apr-2024   Suyon Kim       #44568                             **
**                                                                            **
** 2.11.0.0  31-Jan-2024   Donghee Kwak    #44489                             **
**                                                                            **
** 2.10.0.0  28-Dec-2023   Suyon Kim       #42075                             **
**                                                                            **
** 2.9.0.0   27-11.2023    GS Ryu          #42519                             **
**                                                                            **
** 2.7.0     25-Jul-2022   Suyon Kim       #40261                             **
**                         EunKyung Kim    #40187                             **
**                                                                            **
** 2.6.1.0   13-Jan-2023   DanhTQ1         #35538, #38247                     **
**                                                                            **
** 2.5.1.0   12-Aug-2020   LanhLT          Fix UNECE #35929                   **
**                                                                            **
** 2.3.18.0  01-24-2022    KaHyun  .Kim    #34012                             **
**                                                                            **
** 2.3.14.0  09-11-2021    KaHyun  .Kim    #29539                             **
**                                                                            **
** 2.3.7.0   08-04-2021    EunKyung.Kim    #29178                             **
**                                                                            **
** 2.3.4.0   28-Jan-2021   EunKyung Kim    #27909, #27941                     **
**                                                                            **
** 2.3.2.0   05-Nov-2020   EunKyung Kim    #26432                             **
**                                                                            **
** 1.0.12    02-28-2020    EunKyung Kim      #21551                           **
**                                                                            **
** 1.0.11    11-25-2019    EunKyung Kim      #19580                           **
**                                                                            **
** 1.0.10    02-09-2019    EunKyung Kim      #18790                           **
**                                                                            **
** 1.0.9     23-07-2019    Y.S     Jeon      #17172                           **
**                                                                            **
** 1.0.8     16-07-2019    Y.S     Jeon      #2212                            **
**                                                                            **
** 1.0.7     12-06-2017    Jin     Jung      #5428                            **
**                                                                            **
** 1.0.6     15-02-2017    Jin     Jung      #5460                            **
**                                                                            **
** 1.0.5     14-10-2016    Jin     Jung      #2467                            **
**                                                                            **
** 1.0.4     03-03-2016    Sungeol Baek      #3754, RTRT reflection           **
**                                                                            **
** 1.0.3     10-08-2015    Youngjin Yun      #2977                            **
**                                                                            **
** 1.0.2     26-02-2015    Sungeol Baek      #2163                            **
**                                                                            **
** 1.0.1     26-02-2015    YoungJin Yun      #1044                            **
**                                                                            **
** 1.0.0     09-01-2013    Autron            Initial Version                  **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm.h"
#include "Dcm_Ram.h"
#include "Rte_Dcm.h"
#include "Dcm_DspMain.h"

#if(DCM_DEM_CONFIGURED == STD_ON)  
#include "Dem.h"
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Variables of 8-bit size                                                    **
*******************************************************************************/

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
  VAR(boolean, DCM_VAR) Dcm_TriggerCancelPendingOperation;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || (DCM_DSP_STOP_DIAG_SESSION_SERVICE== STD_ON))
/* Stores diagnostic session index */
  VAR(Dcm_DiagSessionStateType, DCM_VAR) Dcm_DiagSessionState;
#endif


  VAR(uint8, DCM_VAR) Dcm_GucReadLastDIDCount;

#if (DCM_ROUTINECONTROL_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR) Dcm_GucRoutineSubFunction;
#endif

  VAR(uint8, DCM_VAR) Dcm_GucPeriodicSID;

  VAR(uint32, DCM_VAR) Dcm_GulResBufferPosition;

#if(DCM_DSP_MAX_DID_SIZE != DCM_ZERO)
  VAR(uint8, DCM_VAR) Dcm_GaaDidReadSignalData[DCM_DSP_MAX_DID_SIZE];
#endif

  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpDIDSignalDataPtr;

#if((DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON) || \
 (DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON))
  VAR(uint8, DCM_VAR)Dcm_GucBlockSeqCounter;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR) Dcm_GucEventType;

  VAR(uint8, DCM_VAR) Dcm_GucEventState;

  VAR(uint8, DCM_VAR) Dcm_GucActiveWindowTime;
#endif

/* Global Variable to store SubNetValue for service 0x28 */
  VAR(uint8, DCM_VAR) Dcm_GucTranslationType;

  VAR(uint8, DCM_VAR) Dcm_GucAvailableDTCStatusMask;

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR)Dcm_GucMemAddrSizeBytes;

  VAR(uint8, DCM_VAR)Dcm_GucMemoryIdentifier;
#endif

  VAR(uint8, DCM_VAR)Dcm_GucDataForId;

/* Global variable to store protocol status */
  VAR(uint8, DCM_VAR) Dcm_GucProtocolIndex;

/* Array for WriteMemory Data values */
  VAR(uint8, DCM_VAR) Dcm_GaaWriteData[DCM_THIRTY_TWO];

/* Array for Present Date WriteMemory Data values */
  VAR(uint8, DCM_VAR) Dcm_GaaPresentDate[DCM_THREE];

/* Global pointer to store pointer to the request or response data */
  Dcm_MsgType Dcm_GpReqResData;

/* Global pointer to store WriteMemory data */
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpWriteData;

/* Global Variable to store the NRC */
  VAR(uint8, DCM_VAR) Dcm_GaaResponseBuf[DCM_THREE];

/* To store TID value */
  VAR(uint8, DCM_VAR) Dcm_GucTIDValue;

/* To store PID Count */
  VAR(uint8, DCM_VAR) Dcm_GucPIDCount;

/* To indicate ID belongs to Availability list */
  VAR(uint8, DCM_VAR) Dcm_GucAvlState;

/* Global Variable to store the PositionInDataRecordsizes in DynDID */
  VAR(uint8, DCM_VAR) Dcm_GucPosInDtaRec;

/* Global Variable to store the Memorysize in DynDID */
  VAR(uint8, DCM_VAR) Dcm_GucMemorysize;

/* Global Variable to store the TxBuffer Index in DynDID */
  VAR(uint8, DCM_VAR) Dcm_GucTxBufInd;

  VAR(uint8, DCM_VAR)Dcm_GucReadGlobal;

/* Global Variable to store the New Session Requested */
  VAR(uint8, DCM_VAR) Dcm_GucSecurSequChk;

/* Global Variable to store the jump to boot needed for new session requested */
  VAR(uint8, DCM_VAR) Dcm_GucSessionForBoot;

/* Global Variable to store Subfunction for service 0x10 */
  VAR(uint8, DCM_VAR) Dcm_GucSubFunValue;

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store record number */
  VAR(uint8, DCM_VAR) Dcm_GucRecordNumber;
#endif

#if(((DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON)) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global Variable to store Memory Identifier for 0x23 service */
  VAR(uint8, DCM_VAR) Dcm_GucRMBAMemoryIdentifier;
#endif

/* Global Variable to store number of Data Ids */
  VAR(uint8, DCM_VAR) Dcm_GucNumOfDataIds;

/* Global Variable to store current protocol priority */
  VAR(uint8, DCM_VAR) Dcm_GucPrtclPriority;

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || \
 (DCM_DSP_SECURITY_SERVICE == STD_ON))
/* Stores diagnostic service or security index */
  VAR(uint8, DCM_VAR) Dcm_GucDspStIndex;
#endif

/* Global variable to store the communication mode */
  VAR(uint8, DCM_VAR) Dcm_GaaCommMode[DCM_NO_OF_COMM_CHANNELS];

/* Global variable to store the Subfunction respective to the request*/
  VAR(uint8, DCM_VAR) Dcm_GucSubFunction;

/* Global variable to store the Periodic RXPDUID */
  VAR(uint8, DCM_VAR) Dcm_GucPeriodicRxPduId;

/* Global Variable to store session and security access count */
#if ((DCM_DSP_SECURITY_SERVICE == STD_ON)\
  && ((DCM_STANDARD_SUPPORT == DCM_ES96590_SUPPORT)\
  || (DCM_STANDARD_SUPPORT == DCM_QZN04_SUPPORT)))
  VAR(uint8, DCM_VAR) Dcm_GucFailedSecurityAccessCount;
#endif

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
/* Global Variable to store the RxPduId of Periodic request */
  VAR(uint8, DCM_VAR) Dcm_GucPIDValue;
#endif

#if(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
  VAR(uint8, DCM_VAR) Dcm_GucOBDMIDValue;
#endif

#if(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
  VAR(uint8, DCM_VAR) Dcm_GucTIDDValue;
#endif

#if((DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON) || \
(DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON))
/* Global Variable to store SubNetValue for service 0x28 */
  VAR(uint8, DCM_VAR) Dcm_GucSubNetValue;

/* Global Variable to store CommunicationModeType for service 0x28 */
  VAR(uint8, DCM_VAR) Dcm_GucCommunicationModeType;

/* Global Variable to store CommunicationModeType for service 0x28 */
  VAR(Dcm_CommunicationModeType, DCM_VAR) Dcm_GucComCtrlMode;
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR) Dcm_GucInOutParameter;
#endif
  VAR(uint8, DCM_VAR) Dcm_GucIDIndex;

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
 VAR(uint8, DCM_VAR) Dcm_GaaSeed[DCM_MAX_SECURITY_SEED_SIZE];
#endif

 VAR(uint8, DCM_VAR) Dcm_GaaPidSignalData[DCM_THIRTY_TWO];

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store record number */
  VAR(uint8, DCM_VAR) Dcm_GucNumofDTC;
#endif

#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Global Variable for number of identified events stored */
  VAR(uint8, DCM_VAR) Dcm_GucRoeSTRTIndex;

/* Global Variable to store the status of the ROE transmission */
  VAR(uint8, DCM_VAR) Dcm_GucResOnEventStatus;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
  VAR(uint8, DCM_VAR) Dcm_GucPreConfigRoeDidIndex;
#endif
#endif

VAR(uint8, DCM_VAR) Dcm_GaaMetaDataAdd[DCM_METADATA_ADD_LENGTH*2];

VAR(uint8, DCM_VAR) Dcm_GucFunctionalGroupIdentifier;

/* Trace: DCM_19792_56_11 */
VAR(uint8, DCM_VAR) Dcm_GucReadinessGroupIdentifier;
/* Trace: DCM_19792_1A_07 */
VAR(uint8, DCM_VAR) Dcm_GucExtendedDataRecordNumber;

/* Global variable to store the communication mode */
VAR(uint8, DCM_VAR) Dcm_GblFirstCallToMain;

VAR(Dcm_EcuStartModeType, DCM_VAR) Dcm_EcuStartMode;

#if (DCM_J1979_2_SUPPORT == STD_ON)
/* Trace: DCM_19792_56_11 */
VAR(uint8, DCM_VAR) Dcm_GucReadinessGroupIdentifier;
/* Trace: DCM_19792_1A_07 */
VAR(uint8, DCM_VAR) Dcm_GucExtendedDataRecordNumber;
#endif /* J19792 */

#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
/*******************************************************************************
** Variables of 16-bit size                                                   **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Global Variable to remember Maximum Number of response Pending */
  VAR(uint16, DCM_VAR) Dcm_GusMaxNoOfRespPend;

  VAR(uint16, DCM_VAR) Dcm_GusMaxNoOfForceRespPend;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GaaPeriodicID[DCM_DSP_MAX_PERIODIC_DID_SCHEDULED][DCM_TWO];

  VAR(uint16, DCM_VAR)Dcm_GaaActivePeriodicTimer[DCM_THREE];
#endif

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
    (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global pointer to store 16 bit Read Data */
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) Dcm_GpUint16Data;
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDataIdentifier;
#if((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
    (DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO))
 VAR(uint16, DCM_VAR) Dcm_GusRoeDidIndex;
#endif

/* Array for current timer values */
  VAR(uint32, DCM_VAR) Dcm_GaaTimer[DCM_MAX_TIMERS];

  VAR(uint16, DCM_VAR) Dcm_GusDIDBufIndex;

/* Global Variable to store Timer value */
  VAR(uint16, DCM_VAR) Dcm_GusTImerValue;

/* Global pointer to store pointer to the Data Id array */
  P2CONST(uint16, DCM_VAR, DCM_PRIVATE_CONST) Dcm_GpDataId;

  VAR(uint16, DCM_VAR) Dcm_GusDIDIndexVal;

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
    (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) || \
    (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Bug #2467 */
VAR(uint16, DCM_VAR) Dcm_GaaReadDid[DCM_ONE];
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDataPosition;

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GusRIDIndex;

  VAR(uint16, DCM_VAR) Dcm_GusRoutineIdentifier;

  VAR(uint16, DCM_VAR) Dcm_GusLastSignalLength;
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GusTempDIDsize;
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDidReadIndex;

  VAR(uint16, DCM_VAR) Dcm_GusReadDIDCount;

  VAR(uint16, DCM_VAR) Dcm_GusSignalDataLoc;

  VAR(uint16, DCM_VAR) Dcm_IndexOfDslPeriodicData;

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GusCurrentDataLength;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
/*******************************************************************************
** Variables of 32-bit size                                                   **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global pointer to store 32 bit Read Data */
  P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) Dcm_GpUint32Data;
#endif

/* Global Variable to store DTC value for 0x14 service */
  VAR(uint32, DCM_VAR) Dcm_GulDTCValue;

#if((DCM_PAGEDBUFFER_ENABLED == STD_ON) ||\
(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON))
/* Global Variable to store Memory Address for 0x23 service */
  VAR(uint32, DCM_VAR) Dcm_GulRMBAMemoryAddress;
  VAR(uint32, DCM_VAR) Dcm_GulRMBAMemorySize;
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
/* Global Variable to store Memory Address for 0x23 service */
  VAR(uint32, DCM_VAR) Dcm_GulWriteMemoryAddress;
  VAR(uint32, DCM_VAR) Dcm_GulWriteMemorySize;
#endif

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON))
  VAR(uint32, DCM_VAR)Dcm_GulDLMemAddress;

  VAR(uint32, DCM_VAR)Dcm_GulDLMemSize;
#endif

#if((DCM_REQUEST_UPLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON))
  VAR(uint32, DCM_VAR)Dcm_GulULMemAddress;

  VAR(uint32, DCM_VAR)Dcm_GulULMemSize;
#endif

/* Global Variable to store Memory Address */
  VAR(uint32, DCM_VAR) Dcm_GulMemoryAddress;

/* Global Variable to store Memory Size */
  VAR(uint32, DCM_VAR) Dcm_GulMemorySize;

/* Global Variable to store Channel Identifier associated to the received Pdu*/
  VAR(uint32, DCM_VAR) Dcm_GulChannelIdentifier;

  VAR(uint32, DCM_VAR) Dcm_GulNumOfBytesToBeTransfer;

  VAR(uint32, DCM_VAR) Dcm_GulNumOfBytes;

  VAR(uint32, DCM_VAR) Dcm_GulBlockLength;

/* To store Max Buffer configured value */
  VAR(uint32, DCM_VAR) Dcm_GulMaxBufValue;

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
  VAR(uint32, DCM_VAR) Dcm_GulTransferResponseLength;
#endif

  VAR(uint32, DCM_VAR) Dcm_GulFDCRespSize;

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store buffer size in case of paged processing */
  VAR(uint32, DCM_VAR) Dcm_GulBufferSize;
#endif

/* Global Variable to store DTC */
  VAR(Tun_DcmDword32, DCM_VAR) Dcm_GunDTC;
  
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"
/*******************************************************************************
** Variables of boolean                                                       **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
  VAR(boolean, DCM_VAR)Dcm_GblSendResponse;

  VAR(boolean, DCM_VAR)Dcm_GblPduRTransmitResponse;

/* sg.baek 022305 - Task #2163 in redmine */
  VAR(boolean, DCM_VAR)Dcm_GblReceiveRquest;

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store the status of the second request*/
  VAR(boolean, DCM_VAR) Dcm_GblSecDeclRequest;
#endif

#if((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
         (DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO))

  VAR(boolean, DCM_VAR)Dcm_GblNvmReadFlag;
#endif

  VAR(boolean, DCM_VAR)Dcm_GblDTCFDCPending;

  VAR(boolean, DCM_VAR)Dcm_ChangeSessionLvOnReset;

  VAR(boolean, DCM_VAR)Dcm_GblReset;

  VAR(boolean, DCM_VAR)Dcm_GblTheFirstRequest;

#if(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2VAR(boolean, AUTOMATIC, DCM_APPL_DATA) Dcm_GpDcmReadData;
#endif

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR_POWER_ON_INIT) Dcm_GblInitStatus;

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR) Dcm_GblDIDRangePresent;

  VAR(boolean, DCM_VAR) DCM_GblIsDIDInResp;

  VAR(boolean, DCM_VAR) Dcm_GblDIDNotSupportedSession;

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblDownLoadActive;
#endif

  VAR(boolean, DCM_VAR) Dcm_GblFaultDetectionCounter;

  VAR(boolean, DCM_VAR)Dcm_GblDownLoadPendingStatus;

  VAR(boolean, DCM_VAR)Dcm_GblProtocolEndianess;

  VAR(boolean, DCM_VAR)Dcm_GblDownLoadForceStatus;

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblUpLoadActive;
#endif

#if((DCM_TRANSFER_DATA_SERVICE == STD_ON) && \
  (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblReadFileActive;
  VAR(boolean, DCM_VAR)Dcm_GblWriteFileActive;
  VAR(boolean, DCM_VAR)Dcm_GblResumeFileActive;
#endif

#if((DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR) Dcm_GblTransferDataApiInvoked;
#endif

#if(DCM_TRANSFER_EXIT_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR) Dcm_GblTransferExitDataApiInvoked;
#endif

/* Global Variable to Store DID Reference Status */
  VAR(boolean, DCM_VAR)Dcm_GblDIDReferrenceStatus;

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || \
(DCM_ECURESET_SERVICE == STD_ON) ||\
(DCM_LINK_CONTROL_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR) Dcm_GblExecuteECUReset;
#endif

/* To indicate multiple record */
  VAR(boolean, DCM_VAR) Dcm_GblMultipleRecord;

  VAR(boolean, DCM_VAR) Dcm_GblTimerExpired;

/* Global Variable to store the status of the periodic transmission */
  VAR(boolean, DCM_VAR) Dcm_GblResOnPeriodicIdStatus;

/* Global Variable to store the status of the normal transmission */
  VAR(boolean, DCM_VAR) Dcm_GblNormalReq;

/*  Global variable to Store the number of Filter Dtc By Severity mask */
  VAR(boolean, DCM_VAR) Dcm_GblNumFilterDTCStatusBySevirtMask;

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR) Dcm_GblStart;

  VAR(boolean, DCM_VAR) Dcm_GblRespPendConfirmation;

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR) Dcm_GblStop;

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR) Dcm_GblDIDReferred;

  VAR(boolean, DCM_VAR) Dcm_GblDIDReferredIo;

  VAR(boolean, DCM_VAR) Dcm_GblDIDReferredCon;
#endif

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR)Dcm_GblBlockSeqCounterRepeated;
  VAR(boolean, DCM_VAR) Dcm_IsBlockSeqCounterRollOver;
  VAR(boolean, DCM_VAR) Dcm_GddTransDataPosRes;
#endif

#if(DCM_DSP_CONTROL_DTC_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR)Dcm_GblDTCSettingDisabled;
#endif

  VAR(boolean, DCM_VAR)Dcm_GblNegavieResStatus;
/*
 * Response pending on bootloader transition
 */
  VAR(boolean, DCM_VAR)Dcm_GblRspPenOnBtlTrans;

  VAR(boolean, DCM_VAR)Dcm_GblPosRspTransOnReset;

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON) || \
(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON) || \
(DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblAvailabilityPIDFlag;
#endif

#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Gobal Variable to store the requested serviceToRespondTo */
VAR(boolean, DCM_VAR) Dcm_GblRoeClearAll;

#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
/* Gobal Variable to store the requested serviceToRespondTo */
VAR(boolean, DCM_VAR) Dcm_GblRoeQueueOngoing;
#endif
#endif

#if ((DCM_READ_ITC_SERVICE_SUPPRT == STD_ON) ||\
     (DCM_CLEAR_ITC_SERVICE_SUPPRT == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_InternalTroubleCodeService;
#endif

#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
/* Global variable to indicate start restore security attempt counters from application */
VAR(boolean, DCM_VAR) Dcm_GblStartRestoreSecurityAttemptCounters;
#endif

#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/*******************************************************************************
** Variables of unspecified size that are Initialized in Dcm                  **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Added by AUTRON */
#if(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(Dcm_DidProcStateType, DCM_VAR) Dcm_DidProcState[1];
#endif

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
/* Added by AUTRON */
  VAR(Dcm_PeriodicDidProcStateType, DCM_VAR) Dcm_PeriodicDidProcState[1];
#endif

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
/* Added by AUTRON */
  VAR(Dcm_SecurityAccessStateType, DCM_VAR) Dcm_SecurityAccessState[1];

/* Global Variable to store security timer */
  VAR(Dcm_TimerInfoType, DCM_VAR) Dcm_GaaSecurityTimerInfo[DCM_SECURITY_TIMER_MAX_NUM];

/* Global Variable to store seperate security access counters each security levels */
  VAR(Dcm_SecurityLevStateType, DCM_VAR) Dcm_GaaSecLevState[
    DCM_NUM_OF_SECURITYLEVELCONFIG];
  VAR(Dcm_AttCounterControlType, DCM_VAR) Dcm_GddAttCounterControl;
#endif

/* Global Variable to store the value of Tx length and Rx data buffer  */
  VAR(PduInfoType, DCM_VAR) Dcm_GddTxMessageType;

/* Global Variable to store the value of Rx length and Rx data buffer  */
  VAR(PduInfoType, DCM_VAR) Dcm_GddRxMessageType;

  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_GpPerMsgContext;

  VAR(Dcm_ServiceForcePendingStatusType, DCM_VAR)
  Dcm_ServiceForcePendingStatus;

  VAR(Dcm_ServicePendingStatusType, DCM_VAR)
  Dcm_ServicePendingStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
  VAR(Dcm_MemServicePendingStatusType, DCM_VAR)\
                        Dcm_MemServicePendingStatus;

/* Global Variable to store the pointer to the current timing values */
  VAR(Dcm_TimerServerType, DCM_VAR) Dcm_GstCurrentTimingValue;

/* Global Variable to store the current security level */
  VAR(Dcm_SecLevelType, DCM_VAR) Dcm_GddSecurityLevel;

/* Global Variable of MsgContext Type */
  VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstMsgContext;

  VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstPerMsgContext;

/* Global Variable to store length of the request which is in progress */
  VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GaaReqLength[DCM_NUM_OF_PROTOCOLCONFIG];

  VAR(uint8, DCM_VAR) Dcm_GaaTesterPresentReqBuff[DCM_BUFSZ_TESTERPRESENT];

/* Global Variable to store Protocol Id */
  VAR(Dcm_ProtocolType, DCM_VAR) Dcm_GddProtocolId;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store page buffer status */
  VAR(Dcm_DspSerPgStatusType, DCM_VAR) Dcm_DspSerPgStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store the status of the timer */
  VAR(Dcm_ReqTimerFlagStatusType, DCM_VAR)
  Dcm_TimerReqFlagStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store the status of the transmission */
  VAR(Dcm_TxRespStatusType, DCM_VAR) Dcm_TxRespStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store the status of the protocol
and provide buffer for transmission */
  VAR(Dcm_PrtclTxBufStatusType, DCM_VAR) Dcm_PrtclTxBufStatus;

/* Global Variable to store the current session level */
  VAR(Dcm_SesCtrlType, DCM_VAR) Dcm_GddCurrentSession;

/* Global Variable to store the previous session */
  VAR(Dcm_SesCtrlType, DCM_VAR) Dcm_GddOldSession;

/* Global Variable to store negative response code */
  VAR(Dcm_NegativeResponseCodeType, DCM_VAR) Dcm_GddNegRespError;

/* Global Variable to store OpStatus */
  VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddGeneralOpStatus;

/* Global Variable to store DcmTxPduId */
  VAR(PduIdType, DCM_VAR) Dcm_GddDcmTxPduId;

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store DcmTxPduId of the second request*/
  VAR(PduIdType, DCM_VAR) Dcm_GddSecDeclTxPduId;
#endif

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store DcmTxPduId of the second request*/
  VAR(PduIdType, DCM_VAR) Dcm_GddSecDeclConfTxPduId;
#endif

/* Global Variable to store DcmDslTxConfirmationPduId */
  VAR(PduIdType, DCM_VAR) Dcm_GddDcmTxConfPduId;

#if((DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON) && \
     (DCM_PROTOCOL_TRANSTYPE2 == STD_ON))
  VAR(PduIdType, DCM_VAR) Dcm_GddDcmPeriodicTxConfPduId;
#endif

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store the response length pending in paged transmission*/
  VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddCurrentLength;
#endif

/* Global Variable to store the RxPduId */
  VAR(PduIdType, DCM_VAR) Dcm_GddRxPduId;

/* Global Variable to store the response length for the first page */
  VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddTxResponseLen;

/* Global Variable to store the request length from the request */
  VAR(PduLengthType, DCM_VAR) Dcm_GddTpSduLength;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
  VAR(PduIdType, DCM_VAR) Dcm_GddPIdRxPduId;
#endif

  VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddOpStatus;

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON))
  VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddCheckReadOpStatus;
#endif

#if(DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON)
  VAR(Dcm_CommunicationModeType, DCM_VAR)Dcm_GddCommunicationType;
#endif

#if((DCM_DSP_SECURITY_SERVICE == STD_ON) || \
(DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) || \
(DCM_ROUTINECONTROL_SERVICE == STD_ON))
  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
  VAR(Dcm_DspServiceProcessingStsType, DCM_VAR)
Dcm_DspServiceProcessingSts;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Global Variable to store the pointer to the MsgContext */
P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_GpRoeMsgContext;

/* Global Variable to store the response length pending in paged transmission*/
VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddRoeReqLength;
#endif

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpRoutineSignalInDataPtr;

  P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Dcm_GpRoutineSignalOutDataPtr;
#endif

  VAR(Dcm_ProgConditionsType, DCM_VAR) Dcm_GddProgConditions;

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstRoeMsgContext;

VAR(Dcm_RoeRequestInfo, DCM_VAR)
  Dcm_GddRoeRequestInfo[DCM_ROE_STRT_SIZE];

#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)

  VAR(Dcm_PreConfiguredRoe, DCM_VAR)
  Dcm_GddPreConfiguredDID[DCM_MAX_NO_OF_PRECONFIGURED_DID];

#endif
#if(DCM_ROE_QUEUE_ENABLED == STD_ON)

VAR(Dcm_RoeQueueProcessInfo, DCM_VAR) Dcm_GddRoeQueueProcessInfo;

VAR(Dcm_DslRoeQueueInfo, DCM_VAR)
  Dcm_GaaRoeQueueInfo[DCM_ROE_MAX_QUEUE_LENGTH];
#endif

VAR(PduIdType, DCM_VAR) Dcm_GddRoeRxPduId;

VAR(PduIdType, DCM_VAR) Dcm_GddStartRoeRxPduId;

/* Gobal Variable to store the requested serviceToRespondTo */
VAR(Dcm_RoeRetryProcessInfo, DCM_VAR) Dcm_GddRoeRetryProcessInfo;
#endif

VAR(Dcm_RequestContextType, DCM_VAR)  Dcm_RequestContext[DCM_NUM_OF_PROTOCOLCONFIG];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Added by youngjin.yun, 2015-01-02 */
#define DCM_START_SEC_CONST_8
#include "MemMap.h"

/* number of the entries of each data type */
CONST(uint8, DCM_CONST) 
  Dcm_SizeOfDataType[7] =
{
  1, /* DCM_DSP_DATA_TYPE_BOOLEAN 0 */
  2, /* DCM_DSP_DATA_TYPE_SINT16  1 */
  4, /* DCM_DSP_DATA_TYPE_SINT32  2 */
  1, /* DCM_DSP_DATA_TYPE_SINT8   3 */
  2, /* DCM_DSP_DATA_TYPE_UINT16  4 */
  4, /* DCM_DSP_DATA_TYPE_UINT32  5 */
  1, /* DCM_DSP_DATA_TYPE_UINT8   6 */
};

#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"


#define DCM_START_SEC_CONST_8
#include "MemMap.h"
#if defined (DCM_FBL_TYPE) && (DCM_FBL_TYPE == DCM_AUTOEVER_FBL_UNUSED)
#if(DCM_CSAC_CONFIGURED == STD_ON)
/* number of the entries of each data type */
CONST(uint8, DCM_CONST) Dcm_SecSerPublicKey[DCM_SEC_PUBLIC_KEY_LENGTH] = {
  0xB3U, 0x48U, 0xDFU, 0xD7U, 0xA1U, 0x77U, 0xF5U, 0xF1U, 0x9DU, 0x83U, 0xB2U, 0x9BU, 0x5CU, 0x70U, 0xC0U, 0xD5U, 
  0xCCU, 0x0CU, 0xFEU, 0x64U, 0x59U, 0x26U, 0xD5U, 0x5EU, 0x03U, 0x1AU, 0x9BU, 0x97U, 0xB3U, 0x00U, 0xEEU, 0x21U, 
  0xD1U, 0x1EU, 0x4EU, 0x2CU, 0x73U, 0x0FU, 0x41U, 0xACU, 0x03U, 0x7DU, 0x85U, 0xD9U, 0x9EU, 0xF4U, 0x7AU, 0x62U, 
  0x41U, 0x6CU, 0x9BU, 0x81U, 0x30U, 0x18U, 0xA6U, 0xCFU, 0x72U, 0x67U, 0xE8U, 0x85U, 0x57U, 0xC4U, 0xAEU, 0xF8U, 
  0x2AU, 0xFBU, 0xBAU, 0x6DU, 0x45U, 0x18U, 0x1AU, 0x0FU, 0x33U, 0x3BU, 0x14U, 0xF6U, 0x8AU, 0x3FU, 0x87U, 0x17U, 
  0x6DU, 0xFEU, 0x4AU, 0x56U, 0xF1U, 0x8DU, 0x0BU, 0xE7U, 0xADU, 0xCDU, 0xEEU, 0x87U, 0xB3U, 0x29U, 0xBEU, 0x4FU, 
  0x4AU, 0xEDU, 0x58U, 0x4EU, 0x40U, 0x60U, 0x3EU, 0xE9U, 0xA8U, 0x9DU, 0x57U, 0xF6U, 0x12U, 0x69U, 0x1DU, 0x21U, 
  0xCAU, 0x34U, 0xA8U, 0xA4U, 0xC1U, 0xB3U, 0x8FU, 0xCEU, 0x66U, 0x2FU, 0xCFU, 0x8FU, 0x72U, 0x46U, 0xD8U, 0xFCU, 
  0xEBU, 0xD5U, 0x63U, 0xC2U, 0xBCU, 0x0EU, 0x42U, 0x8BU, 0x4CU, 0x7FU, 0x78U, 0xE7U, 0x4FU, 0xCBU, 0x24U, 0xDCU, 
  0x1DU, 0xE3U, 0x4CU, 0x52U, 0xCEU, 0x0DU, 0x85U, 0x2EU, 0x6AU, 0xDEU, 0x4AU, 0x9DU, 0x3DU, 0xD7U, 0xCAU, 0x10U, 
  0x0FU, 0xC9U, 0x98U, 0x5AU, 0x80U, 0x9BU, 0x5EU, 0x9FU, 0x7CU, 0x17U, 0x59U, 0x02U, 0x19U, 0xAFU, 0xD9U, 0xB8U, 
  0x16U, 0xA0U, 0x85U, 0x89U, 0x90U, 0x4AU, 0x51U, 0x39U, 0xFDU, 0x0DU, 0xFDU, 0xF1U, 0x36U, 0x99U, 0x8CU, 0x64U, 
  0x21U, 0xF3U, 0x61U, 0x07U, 0x7AU, 0x9FU, 0xD9U, 0x33U, 0x9CU, 0x6AU, 0x4AU, 0x46U, 0xE3U, 0xCDU, 0xAEU, 0x00U, 
  0x4EU, 0x51U, 0xEAU, 0xE7U, 0x00U, 0x14U, 0xC0U, 0xEBU, 0xC0U, 0x10U, 0xBAU, 0xACU, 0xE8U, 0x6FU, 0xFFU, 0x29U, 
  0xD4U, 0x9FU, 0x61U, 0x43U, 0x2FU, 0x1EU, 0x07U, 0xFAU, 0x1FU, 0x5AU, 0x05U, 0xC7U, 0xF0U, 0x36U, 0x3EU, 0x94U, 
  0xB5U, 0xA6U, 0x1BU, 0x3FU, 0xBAU, 0x5DU, 0xAEU, 0xC7U, 0x33U, 0xB2U, 0x87U, 0x5CU, 0xE9U, 0xE5U, 0xF6U, 0xE1U
};
#endif
#endif
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
