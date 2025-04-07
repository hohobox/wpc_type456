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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Ram.h" 
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

uint8         Nml_CurComMode[NML_COMM_TOTAL_CHANNELS];
uint8         Nml_CurComModeChangeCnt[NML_COMM_TOTAL_CHANNELS];
uint8         Nml_CmcTimerCnt;
ComM_ModeType Nml_RequestedComMode[NML_COMM_TOTAL_USERS];
boolean       Nml_IsReqComModeDectTimerRun;

uint8 Nml_CanNormalDetectCnt;
uint8 Nml_CanRssDetectCnt;
uint8 Nml_CanRmsDetectCnt;
uint8 Nml_CanPbsDetectCnt;
uint8 Nml_CanBusSleppDetectCnt;


/* 240927_KCLim - Use below variables for UdpNm RVCCM */
uint8 Nml_UdpNormalDetectCnt;
uint8 Nml_UdpRssDetectCnt;
uint8 Nml_UdpRmsDetectCnt;
uint8 Nml_UdpPbsDetectCnt;
uint8 Nml_UdpBusSleppDetectCnt;

/* 241024_KCLim - Need for RDBI data format */
uint8 Nml_ComMTotalChannel;

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

uint16  Nml_ReqComModeDectTimer;
uint16  Nml_CurComModeDetTimer[NML_COMM_TOTAL_CHANNELS];
uint16  Nml_AliveCycle;

#define NML_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define NML_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if (STD_ON == NML_USE)



#endif /* #if (STD_ON == NML_USE) */

#define NML_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#if (NML_MEASURE_TIME == STD_ON)
	Nml_RunTimeMeasureType Nml_Init_Runtime;
	Nml_RunTimeMeasureType Nml_Main_Runtime;
#endif /* #if (NML_MEASURE_TIME == STD_ON) */


	Nml_ErrorType Nml_Error;


#if (STD_ON == NML_USE)
	Nml_StateMachineType      Nml_StateMachine;
	Nml_ChannelDataType       Nml_ChannelData[NML_COMM_TOTAL_CHANNELS];
	Nml_LogCMCRamDataType     Nml_LogCMCRamData;
	Nml_LogRVCCMRamDataType   Nml_LogRVCCMRamData;
	Nml_LogWakeupSourceType   Nml_LogWakeupSource;
	Nml_VersionType           Nml_Version;
	Nml_LogMcuResetType       Nml_LogMcuResetReason;
	Nml_LogLCMType            Nml_LogLCMRamData[NML_COMM_TOTAL_CHANNELS];
#endif /* #if (STD_ON == NML_USE) */


Nml_RDBI_DataFormatType Nml_RDBI_DataFormat[NML_DATA_LAST] = 
{
  /* logDataType             , startIndex,   dataSize*/
  {NML_START_PATTERN         ,  0,                  4},
  {NML_DATA_ALIVE_CYCLE      ,  4,                  2},
  {NML_DATA_ERROR            ,  6,                  8},
  {NML_DATA_NML_VERSION      , 14,                  4},
  {NML_DATA_EAET             , 18,                  4},
  {NML_DATA_RVCCM            , 22,                 20},
  {NML_DATA_CMC              , 42,                  8},
  {NML_DATA_MCU_RESET_REASON , 50,                  4},
  {NML_DATA_WAKEUP_SOURCE    , 54,                 25},
  {NML_END_PATTERN           , 79,                  4},
  {NML_DATA_CH_NUM           , 83,                  1},
  {NML_DATA_LAST_CH_MODE     , 84,  NML_LCM_DATA_SIZE}
};


#define NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/



/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
