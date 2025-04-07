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
#ifndef NML_RAM_H
#define NML_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Types.h" 
#include "Rte_Type.h"

/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

extern uint8         Nml_CurComMode[NML_COMM_TOTAL_CHANNELS];
extern uint8         Nml_CurComModeChangeCnt[NML_COMM_TOTAL_CHANNELS];
extern uint8         Nml_CmcTimerCnt;
extern ComM_ModeType Nml_RequestedComMode[NML_COMM_TOTAL_USERS];
extern boolean       Nml_IsReqComModeDectTimerRun;

extern uint8 Nml_CanNormalDetectCnt;
extern uint8 Nml_CanRssDetectCnt;
extern uint8 Nml_CanRmsDetectCnt;
extern uint8 Nml_CanPbsDetectCnt;
extern uint8 Nml_CanBusSleppDetectCnt;

/* 240927_KCLim - Use below variables for UdpNm RVCCM */
extern uint8 Nml_UdpNormalDetectCnt;
extern uint8 Nml_UdpRssDetectCnt;
extern uint8 Nml_UdpRmsDetectCnt;
extern uint8 Nml_UdpPbsDetectCnt;
extern uint8 Nml_UdpBusSleppDetectCnt;

/* 241024_KCLim - Need for RDBI data format */
extern uint8 Nml_ComMTotalChannel;

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

extern uint16  Nml_ReqComModeDectTimer;
extern uint16  Nml_CurComModeDetTimer[NML_COMM_TOTAL_CHANNELS];
extern uint16  Nml_AliveCycle;

#define NML_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_32
#include "MemMap.h"




#define NML_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#if (NML_MEASURE_TIME == STD_ON)
	/* Tick for Nml_Init function */
	extern Nml_RunTimeMeasureType Nml_Init_Runtime;
	extern Nml_RunTimeMeasureType Nml_Main_Runtime;
#endif /* #if (NML_MEASURE_TIME == STD_ON) */


	extern Nml_ErrorType Nml_Error;


#if (STD_ON == NML_USE)
	extern Nml_StateMachineType    Nml_StateMachine;
	extern Nml_ChannelDataType     Nml_ChannelData[NML_COMM_TOTAL_CHANNELS];
	extern Nml_LogCMCRamDataType   Nml_LogCMCRamData;
	extern Nml_LogRVCCMRamDataType Nml_LogRVCCMRamData;
	extern Nml_LogWakeupSourceType Nml_LogWakeupSource;
	extern Nml_VersionType         Nml_Version;
	extern Nml_LogMcuResetType     Nml_LogMcuResetReason;
	extern Nml_LogLCMType          Nml_LogLCMRamData[NML_COMM_TOTAL_CHANNELS];
#endif /* #if (STD_ON == NML_USE) */

extern Nml_RDBI_DataFormatType Nml_RDBI_DataFormat[NML_DATA_LAST];


#define NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/



#endif /* NML_RAM_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
