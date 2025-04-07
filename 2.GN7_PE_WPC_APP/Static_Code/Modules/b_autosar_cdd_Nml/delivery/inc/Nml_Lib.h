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
#ifndef NML_LIB_H
#define NML_LIB_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Types.h"
#include "string.h" /* for memcpy and sizeof */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/
/* polyspace-begin MISRA-C3:D4.9 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */
/* polyspace-begin MISRA-C3:21.15 [Not a defect:Unset] "No Impact of this rule violation" */
#define Nml_Memcpy(dst, src, size)  (memcpy((dst),(src),(size)))
/* polyspace-end MISRA-C3:D4.9 [Not a defect:Unset] "No Impact of this rule violation (MCU Register)" */
/* polyspace-begin MISRA-C3:21.15 [Not a defect:Unset] "No Impact of this rule violation" */

/* Use this macro if 4 byte variable is needed into separted 1 byte */
#define Nml_TransFourByteToZero(FourByte)  ((FourByte)&0x000000FF)
#define Nml_TransFourByteToOne(FourByte)   (((FourByte)&0x0000FF00) >>  8u)
#define Nml_TransFourByteToTwo(FourByte)   (((FourByte)&0x00FF0000) >> 16u)
#define Nml_TransFourByteToThree(FourByte) (((FourByte)&0xFF000000) >> 24u)

/* Use this macro if Make 4 byte variable by combine each 1 byte */
#define Nml_TransZeroByteToFourByte(FourByte, OneByte)  ((OneByte&0x000000FF) | (FourByte))
#define Nml_TransOneByteToFourByte(FourByte, OneByte)   (((OneByte&0x000000FF) <<  8u) | (FourByte))
#define Nml_TransTowByteToFourByte(FourByte, OneByte)   (((OneByte&0x000000FF) << 16u) | (FourByte))
#define Nml_TransThreeByteToFourByte(FourByte, OneByte) (((OneByte&0x000000FF) << 24u) | (FourByte))


/* Use this macro if 2 byte variable is needed into separted 1 byte */
#define Nml_TransTwoByteToZero(TwoByte)    ((uint8)((TwoByte)&0x00FF))
#define Nml_TransTwoByteToOne(TwoByte)     ((uint8)(((TwoByte)&0xFF00) >>  8u))

/* se this macro if Make 2 byte variable by combine each 1 byte */
#define Nml_TransZeroByteToTwoByte(TwoByte, OneByte)    ((uint16)(OneByte&0x00FF) | (uint16)TwoByte)
#define Nml_TransOneByteToTwoByte(TwoByte, OneByte)     ((uint16)((OneByte&0x00FF) <<  8u) | (uint16)TwoByte)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (STD_ON == NML_USE)


#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

extern uint8 Nml_LibCallCnt;  /* [NML-3] Sleep/Wakeup Callout */
extern uint8 Nml_LibNvMWriteRetryCnt; /* [NML-7] NvM Write */
extern boolean Nml_IsFirstMainLoopAfterWakeUp;
extern boolean Nml_IsH2LTransition;
extern boolean Nml_IsEcuRequestSleep;
extern boolean Nml_IsNvMWriteDone;

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

extern uint16 Nml_LibCallCntTotal;

#define NML_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* polyspace-begin DEFECT:USELESS_PREPROC_CONDITION [Not a defect:Unset] "NML_USE can be configurable by User, it means this value could be STD_OFF or STD_ON." */
#if (STD_ON == NML_USE)
/* polyspace-end DEFECT:USELESS_PREPROC_CONDITION [Not a defect:Unset] "NML_USE can be configurable by User, it means this value could be STD_OFF or STD_ON." */
/* polyspace MISRA-C3:8.6 [Not a defect:Unset] "'230426_KCLim : This global variable is declared external only here." */
extern Nml_TimeType Nml_LibInternalTime;
extern uint8 Nml_Pattern[NML_PATTERN_SIZE];

#if (NML_NVM_WRITE_USED == STD_ON)
	extern uint8 Nml_IsNeedToWriteNvM[NML_DATA_LAST];
	extern uint8 Nml_IsWriteNvMDone[NML_DATA_LAST];
#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

#endif /* #if (STD_ON == NML_USE) */

#define NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#endif /* #if (STD_ON == NML_USE) */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == NML_USE)

	extern void Nml_LibInit(void);
	extern void Nml_LibMain(void);
	extern Nml_TimeType Nml_LibGetTime(void);
	extern Nml_TimeType Nml_LibGetDiffTime(Nml_TimeType startTime, Nml_TimeType endTime );
	extern uint16 Nml_LibGetTimeCnt(void);
	extern uint32 Nml_LibGetDiffTimeCnt_U32(uint32 startCnt, uint32 EndCnt);
	extern uint16 Nml_LibSetTargetTimeCnt_U16(uint16 startCnt, uint16 targetCnt);
	extern uint16 Nml_LibGetDiffTimeCnt_U16(uint16 startCnt, uint16 EndCnt);
	extern uint8  Nml_LibGetDiffTimeCnt_U8(uint8 startCnt, uint8 EndCnt);

	#if (NML_MEASURE_TIME == STD_ON)
	extern void Nml_LibBeginElapsedTick(uint32* startTime);
	extern void Nml_LibEndElapsedTick(uint32* startTime, uint32* timeMin, uint32* timeMax, uint32* timeAvg, uint32* timeRun);
	#endif /* #if (NML_MEASURE_TIME == STD_ON) */

	#if (NML_DET == STD_ON)
	extern void Nml_ChkIndexRangeOver(uint8 userIndex, uint8 maxIndex, Nml_ApiIndexType apiIndex);
	#endif /* #if (NML_DET == STD_ON) */
#endif /* #if (STD_ON == NML_USE) */



#if (STD_ON == NML_USE)
extern void Nml_SetLogStartPattern(void);
extern void Nml_GetLogStartPattern(void);

extern void Nml_SetLogAliveCycle(void);
extern void Nml_GetLogAliveCycle(void);

extern void Nml_SetLogNmlError(void);
extern void Nml_GetLogNmlError(void);

extern void Nml_SetLogNmlVersion(void);
extern void Nml_GetLogNmlVersion(void);

extern void Nml_SetLogEaet(void);
extern void Nml_GetLogEaet(void);

extern void Nml_SetLogRvccm(void);
extern void Nml_GetLogRvccm(void);

extern void Nml_SetLogCmc(void);
extern void Nml_GetLogCmc(void);

extern void Nml_SetLogMcuResetReason(void);
extern void Nml_GetLogMcuResetReason(Nml_LogMcuResetType* mcuResetReason);

extern void Nml_SetLogWakeupSource(void);
extern void Nml_GetLogWakeupSource(void);

extern void Nml_SetLogEndPattern(void);
extern void Nml_GetLogEndPattern(void);

extern void Nml_SetLogChNum(void);
extern void Nml_GetLogChNum(void);

extern void Nml_SetLogLcm(void);
/* Do need Nml_GetLogLcm function */

#endif /* #if (STD_ON == NML_USE) */



#define NML_STOP_SEC_CODE
#include "MemMap.h"

#endif /* NML_LIB_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
