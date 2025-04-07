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
#ifndef NML_TYPES_H
#define NML_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h" /* Standard types header file  */
#include "Rte_ComM_Type.h"
#include "Nml_Cfg.h"
#include "Mcu.h"
#include "Nm.h"
/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/
#define NML_ENABLE     (0x01u)
#define NML_DISABLE    (0x00u)

#define NML_FLAG_ON    (0x01u)
#define NML_FLAG_OFF   (0x00u)

#define NML_TRUE     (1u)
#define NML_FALSE    (0u)


#define NML_ZERO      (0x00)
#define NML_ONE       (0x01)
#define NML_TWO       (0x02)
#define NML_THREE     (0x03)
#define NML_FOUR      (0x04)
#define NML_EIGHT     (0x08)

#define NML_UINT8_MIN  (uint8)0x00u
#define NML_UINT8_MAX  (uint8)0xFFu
#define NML_UINT16_MIN (uint16)0x0000u
#define NML_UINT16_MAX (uint16)0xFFFFu
#define NML_UINT32_MIN (uint32)0x00000000u
#define NML_UINT32_MAX (uint32)0xFFFFFFFFu

#define NML_COMMODE_NO_COM         0x00u
#define NML_COMMODE_SILENT_COM     0x01u
#define NML_COMMODE_FULL_COM       0x02u
#define NML_COMMODE_NOT_DEFINED    0xFFu

#define NML_PNCMODE_REQUESTED      0x00u
#define NML_PNCMODE_READY_SLEEP    0x01u
#define NML_PNCMODE_PREPARE_SLEEP  0x02u
#define NML_PNCMODE_NO_COM         0x03u
#define NML_PNCMODE_NOT_DEFINED    0xFFu


#define NML_CANNM_NOT_CONNECT              0xFFu
#define NML_NM_TIMER_EXPIRED               (uint16)0x0000u
#define NML_NM_NOT_MATCHED_RMTIME          0x01u
#define NML_NM_NOT_MATCHED_NWTIME          0x02u
#define NML_NM_NOT_MATCHED_WBSTIME         0x04u
#define NML_NM_NOT_MATCHED_CANNM_NW_REQED  0x08u
#define NML_NM_NOT_MATCHED_COMM_NW_REQED   0x10u
#define NML_NM_NOT_MATCHED_UDPNM_NW_REQED  0x20u



/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*
 * This shall be used to handle NML state
 * */

typedef enum
{
  NML_STATE_NORMAL,
  NML_STATE_APP_TRIGGERED,
  NML_STATE_COMM_TRIGGERED,
  NML_STATE_BOTH_TRIGGERED,
  NML_STATE_NOT_DEFINED = 0xFF
} Nml_StateType;


typedef enum
{
  NML_INTERNAL_INTERFACES,
  NML_LIBDATASERIALIZE,
  NML_LIBDATADESERIALIZE,
  NML_LIBINITDATASERIALIZE,
  NML_SETLOGLCM,
  NML_API_NOT_DEFINED = 0x10 /* it's bitshift for 2byte, 16bit */
} Nml_ApiIndexType;


typedef enum
{
  NML_START_PATTERN,
  NML_DATA_ALIVE_CYCLE,
  NML_DATA_ERROR,
  NML_DATA_NML_VERSION,
  NML_DATA_EAET,
  NML_DATA_RVCCM,
  NML_DATA_CMC,
  NML_DATA_MCU_RESET_REASON,
  NML_DATA_WAKEUP_SOURCE,
  NML_END_PATTERN,
  NML_DATA_CH_NUM,
  NML_DATA_LAST_CH_MODE, 
  NML_DATA_LAST
} Nml_DataSerializeIndexType;


#if (NML_MEASURE_TIME == STD_ON)
/* It has a MCU dependency, in this configuration, Target MCU is TC39x */
typedef uint32      Nml_Reg32;

/* polyspace-begin MISRA-C3:19.2 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */
typedef volatile union
{
  struct
  {
    /* const */ Nml_Reg32 STM            : 32; /* System Timer Bits [31:0] */
  } B;
  sint32 I;
  uint32 U;


} NML_STM0_TIM0_type;
/* polyspace-end MISRA-C3:19.2 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */

/* polyspace-begin MISRA-C3:D4.9 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */
/* polyspace-begin MISRA-C3:11.4 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */
#define NML_STM0_TIM0 (*( NML_STM0_TIM0_type *) 0xf0001010u)
#define NML_GET_TIMESTAMP()   (NML_STM0_TIM0.U)
/* polyspace-end MISRA-C3:D4.9 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */
/* polyspace-end MISRA-C3:11.4 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */

#endif /* #if (NML_MEASURE_TIME == STD_ON) */

typedef struct
{
	Nml_DataSerializeIndexType  logDataType;
	uint16                      startIndex;
	uint16                      dataSize;
}Nml_RDBI_DataFormatType;


typedef struct
{
	Nml_StateType     prevNmlState;
	Nml_StateType     curNmlState;
}Nml_StateMachineType;

typedef struct
{
	uint8 major;
	uint8 minor;
	uint8 patch;
	uint8 asr;
}Nml_VersionType;


typedef struct
{
    uint8 hour;
    uint8 min;
    uint8 sec;
    uint8 ms;
}Nml_TimeType;


typedef struct
{
	uint8         mappedUsrIdx;
	uint8         mappedUsrCnt;
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
	uint8         mappedPncIdx;
	uint8         mappedPncCnt;
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
	uint16        mappedPncIdx;
	uint16        mappedPncCnt;
#else /* Other variant */
    #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 

	boolean          isPncCh;
	ComM_ModeType    requestedHighMode;
	uint8            curComMode;
	boolean          isReqVsCurComModeMatched;
	uint8            canNmIndex;                /* For CanNm - CanNm index to access CanNm_xxx array data */
	uint8            udpNmIndex;                /* For UdpNm - UdpNm index to access UdpNm_xxx array data */
	uint16           repeatMsgTime;
	uint16           nmTimeOutTime;
	uint16           waitBusSleeptime;
	boolean          nmNwRequested;
	Nm_StateType     prevNmState;
	Nm_StateType     curNmState;
	uint8            NmStateMatched;
	uint16           targetElapsedCnt;
	uint8            nmModeStatus;
	uint8            nmNextModeState;
	uint8			 nmPrevModeStatus;
}Nml_ChannelDataType; /*   */



/*****************************************************
 * Types to be stored in NvM
 * ***************************************************/
typedef struct
{
	uint8  doNotRun;
	uint8  exceedNvMSize;
	uint8  infoNvmSrvId;
	uint8  infoNvmReqResult;
	uint16 indexOverApi;
	uint16 aliveCycle;
}Nml_ErrorType;

typedef struct
{
	Nml_TimeType       detectionTime; /* 4byte , arrange 1st for unnecessary padding */
	uint16             aliveCycle;
	NetworkHandleType  chIndex;
	uint8              detectionCnt;
}Nml_LogCMCRamDataType; /* CMC : Crazy Mode Changes */

typedef struct
{
	Nml_TimeType       detectionTime;  /* 4byte , arrange 1st for unnecessary padding */
	Nm_StateType       prevNmState;    /* 4byte in Tasking, arrange 1st for unnecessary padding */
	Nm_StateType       curNmState;     /* 4byte in Tasking, arrange 1st for unnecessary padding */
	uint16             repeatMsgTime;
	uint16             nmTimeOutTime;
	uint16             aliveCycle;
	uint16             waitBusSleeptime;
	NetworkHandleType  chIndex;
	ComM_ModeType      chMode;
	ComM_ModeType      requestedHighMode;
	boolean            nmNwRequested;
	uint8              nmStateNotMatchedReason;
	uint8              detectionCnt;
}Nml_LogRVCCMRamDataType; /* RVCM : Requested Vs Current Com Mode */

typedef struct
{
	uint32 wakeupSource;
	uint8  wakeupSourceOrder[NML_WAKEUP_SOURCE_ORDER_SIZE];
	Nml_TimeType  wakeupSourceTime[NML_WAKEUP_SOURCE_ORDER_SIZE];
	uint16 aliveCycle[NML_WAKEUP_SOURCE_ORDER_SIZE];
}Nml_LogWakeupSourceType;

typedef struct
{
	Mcu_ResetType mcuResetType;
	uint16        aliveCycle;
}Nml_LogMcuResetType;

typedef struct
{
	ComM_ModeType chMode;
	uint8         prevNmState; /* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align */
	uint8         curNmState;  /* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align  */
}Nml_LogLCMType;

/* below variable should be the number of variables in Nml_LogLCMType */
#define NML_LCM_CONTENTS_COUNT 3u


/*****************************************************
 * Types for run-time measurement
 * ***************************************************/
#if (NML_MEASURE_TIME == STD_ON)
typedef struct
{
	uint32  min_us;
	uint32  max_us;
	uint32  avg_us;
	uint32  run_us;
}Nml_RunTimeMeasureType; /*   */
#endif /* #if (NML_MEASURE_TIME == STD_ON) */


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/



#endif /* NML_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
