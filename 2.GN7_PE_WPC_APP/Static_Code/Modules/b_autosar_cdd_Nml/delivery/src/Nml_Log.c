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
#include "Nml_Log.h"
#include "Nml_Ram.h"
#include "Nml_Lib.h"
#include "Nml_InternalIf.h"
#if (NML_TEST == STD_ON)
	#include "Nml_Test.h"
#endif /* #if (NML_DEBUG == STD_ON) */

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

#if (STD_ON == NML_USE)
/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint8   Nml_LogCMCBeginCnt[NML_COMM_TOTAL_CHANNELS];
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint8   Nml_WakeupSourceIndex;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This gThis global variable is used only in this file. There is no use of this variable other filelobal variable is used only in this file. There is no use of this variable other file" */
boolean Nml_IsWakeupSource;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This gThis global variable is used only in this file. There is no use of this variable other filelobal variable is used only in this file. There is no use of this variable other file" */
#endif /* #if (STD_ON == NML_USE) */

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

#if (STD_ON == NML_USE)
/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint16 Nml_LogCMCCheckCnt;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
#endif /* #if (STD_ON == NML_USE) */

#define NML_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define NML_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if (STD_ON == NML_USE)
/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint32  Nml_WakeupSource;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
#endif /* #if (STD_ON == NML_USE) */
#define NML_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"


/*******************************************************************************
**                      Local Function Declaration                            **
*******************************************************************************/

#define NML_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == NML_USE)
void Nml_LogInitCMCRamData(void);
void Nml_LogInitRVCCMRamData(void);
void Nml_LogInitWUSMRamData(void);
void Nml_LogInitLCMRamData(void);
void Nml_LogIncreaseDetectionCnt(uint8* detectionCnt);

#endif /* #if (STD_ON == NML_USE) */

#define NML_STOP_SEC_CODE
#include "MemMap.h"




#define NML_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                     Local Function Definitions                             **
*******************************************************************************/
#if (STD_ON == NML_USE)

void Nml_LogInitCMCRamData(void)
{

	Nml_LogCMCRamData.chIndex            = NML_UINT8_MAX;
	Nml_LogCMCRamData.aliveCycle         = NML_UINT16_MIN;
	Nml_LogCMCRamData.detectionCnt       = NML_UINT8_MIN;
	Nml_LogCMCRamData.detectionTime.hour = NML_UINT8_MAX;
	Nml_LogCMCRamData.detectionTime.min  = NML_UINT8_MAX;
	Nml_LogCMCRamData.detectionTime.sec  = NML_UINT8_MAX;
	Nml_LogCMCRamData.detectionTime.ms   = NML_UINT8_MAX;
}

void Nml_LogInitRVCCMRamData(void)
{

	Nml_LogRVCCMRamData.chIndex                  = NML_UINT8_MAX;
	Nml_LogRVCCMRamData.chMode                   = NML_COMMODE_NO_COM;
	Nml_LogRVCCMRamData.requestedHighMode        = NML_COMMODE_NO_COM;
	Nml_LogRVCCMRamData.prevNmState              = NM_STATE_UNINIT;
	Nml_LogRVCCMRamData.curNmState               = NM_STATE_UNINIT;
	Nml_LogRVCCMRamData.repeatMsgTime            = NML_UINT16_MIN;
	Nml_LogRVCCMRamData.nmTimeOutTime            = NML_UINT16_MIN;
	Nml_LogRVCCMRamData.waitBusSleeptime         = NML_UINT16_MIN;
	Nml_LogRVCCMRamData.nmNwRequested            = NML_FALSE;
	Nml_LogRVCCMRamData.nmStateNotMatchedReason  = NML_UINT8_MIN;
	Nml_LogRVCCMRamData.detectionCnt             = NML_UINT8_MIN;
	Nml_LogRVCCMRamData.aliveCycle               = NML_UINT16_MIN;
	Nml_LogRVCCMRamData.detectionTime.hour       = NML_UINT8_MAX;
	Nml_LogRVCCMRamData.detectionTime.min        = NML_UINT8_MAX;
	Nml_LogRVCCMRamData.detectionTime.sec        = NML_UINT8_MAX;
	Nml_LogRVCCMRamData.detectionTime.ms         = NML_UINT8_MAX;
}

void Nml_LogInitWUSMRamData(void)
{
	uint8 i = 0;

	Nml_WakeupSource      = NML_UINT32_MIN;
	Nml_WakeupSourceIndex = NML_UINT8_MIN;

	Nml_LogWakeupSource.wakeupSource = NML_UINT32_MIN;

	Nml_IsWakeupSource = NML_FALSE;
	for (i=0; i<NML_WAKEUP_SOURCE_ORDER_SIZE; i++)
	{
		Nml_LogWakeupSource.wakeupSourceOrder[i]     = NML_UINT8_MIN;
		Nml_LogWakeupSource.aliveCycle[i]            = NML_UINT16_MIN;
		Nml_LogWakeupSource.wakeupSourceTime[i].hour = NML_UINT8_MAX;
		Nml_LogWakeupSource.wakeupSourceTime[i].min  = NML_UINT8_MAX;
		Nml_LogWakeupSource.wakeupSourceTime[i].sec  = NML_UINT8_MAX;
		Nml_LogWakeupSource.wakeupSourceTime[i].ms   = NML_UINT8_MAX;
	}
}

void Nml_LogInitLCMRamData(void)
{
	uint8 i = 0;

	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		Nml_LogLCMRamData[i].chMode      = NML_COMMODE_NO_COM;
		Nml_LogLCMRamData[i].prevNmState = (uint8)NM_STATE_UNINIT;/* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align */
		Nml_LogLCMRamData[i].curNmState  = (uint8)NM_STATE_UNINIT;/* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align */
	}
}

void Nml_LogIncreaseDetectionCnt(uint8 *detectionCnt)
{
	if ((*detectionCnt) < NML_UINT8_MAX)
	{
		(*detectionCnt)++;
	}
	else
	{
		/* Keep max detection counter, already reached MAX counter */
	}
}

void Nml_LogFuncWUSInternal(void)
{
	uint8 i;
	uint32 temp;
	uint8 wakeupSourceIdBit = 0x00;



	if (NML_TRUE == Nml_IsWakeupSource)
	{
		Nml_IsWakeupSource = NML_FALSE;
		temp = Nml_WakeupSource;

		Nml_LogWakeupSource.wakeupSource = (Nml_LogWakeupSource.wakeupSource | temp);

		for (i=0; i<NML_WAKEUP_SOURCE_VARIALBE_BIT_SIZE; i++)
		{
			if (NML_WAKEUP_SOURCE_ORDER == ((temp >> i) & NML_WAKEUP_SOURCE_ORDER))
			{
				if (Nml_WakeupSourceIndex < NML_WAKEUP_SOURCE_ORDER_SIZE)
				{
					wakeupSourceIdBit = i;
					Nml_LogWakeupSource.wakeupSourceOrder[Nml_WakeupSourceIndex] = wakeupSourceIdBit;
					Nml_LogWakeupSource.wakeupSourceTime[Nml_WakeupSourceIndex]  = Nml_LibGetTime();
					Nml_LogWakeupSource.aliveCycle[Nml_WakeupSourceIndex] = Nml_AliveCycle;
					Nml_WakeupSourceIndex++;
				}
				else
				{

				}

				if (Nml_WakeupSourceIndex >= NML_WAKEUP_SOURCE_ORDER_SIZE)
				{
					Nml_WakeupSourceIndex = 0x00;
				}
				else
				{

				}
			}
			else
			{

			}
		}
		Nml_SetLogWakeupSource();
	}
	else
	{
		/* Do not run if wakeup source is same as previous */
	}

}

#endif /* #if (STD_ON == NML_USE) */



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Nml_xxxx                             **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : xxx                                                 **
**                        xxx                                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
**  Re-entrancy         : Re-entrant                                          **
**                                                                            **
** Input Parameters     : xx,                                                 **
**                        xx                                                  **
**                                                                            **
** Output Parameters    : xx                                                  **
**                                                                            **
** Return parameter     : E_OK/E_NOT_OK                                       **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : xx                            **
**                                              xx                            **
**                        Function(s) invoked : xx                            **
*******************************************************************************/

#if (STD_ON == NML_USE)

void Nml_LogInit(void)
{
#if (NML_DEBUG == STD_ON)
	Nml_DebugInit();
#endif /* #if (NML_DEBUG == STD_ON) */

	Nml_LogInitCMCRamData();
	Nml_LogInitRVCCMRamData();
	Nml_LogInitWUSMRamData();
	Nml_LogInitLCMRamData();
}

void Nml_LogFuncCMC(void)
{
	uint8  i = 0;

	/* Loop to find out the number of channel changes */
	for (i = 0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		if (Nml_CurComModeChangeCnt[i] >= NML_FUNC_CMC_DETECTION_COUNT)
		{
			Nml_LogCMCRamData.chIndex       = i;
			Nml_LogCMCRamData.aliveCycle    = Nml_AliveCycle;
			Nml_LogCMCRamData.detectionTime = Nml_LibGetTime();
			Nml_LogIncreaseDetectionCnt(&Nml_LogCMCRamData.detectionCnt);
			Nml_SetLogCmc();
            #if (NML_NVM_WRITE_USED == STD_ON)
				if (Nml_IsNeedToWriteNvM[NML_DATA_CMC] == NML_FLAG_OFF)
				{
				Nml_IsNeedToWriteNvM[NML_DATA_CMC] = NML_FLAG_ON;
				}
				else
				{
				/* Do not write request NvM to prevent many NvM write if many detection */
				}
            #endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/
		}
		else
		{

		}
		Nml_CurComModeChangeCnt[i] = 0x00;
	}
}
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] ""To make code easy to read and to maintain"" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:CALLING [Justified:Unset] "Kind of library function, Total 10 funcs are called this function for CanNm 5 state and UdpNm 5 state, If making separate func, there will be duplicated" */
void Nml_LogFuncRVCCM(uint8 chIndex, uint8 nmStateNotMatchedReason)
/* polyspace-end CODE-METRIC:CALLING [Justified:Unset] "Kind of library function, Total 10 funcs are called this function for CanNm 5 state and UdpNm 5 state, If making separate func, there will be duplicated" */
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] ""To make code easy to read and to maintain"" */
{

#if (NML_DET == STD_ON)
	if ((0x00 == Nml_Error.doNotRun) && (chIndex < NML_COMM_TOTAL_CHANNELS))
	{
#endif /* #if (NML_DET == STD_ON) */
		/* Set current information into RVCCM Log RAM Data */
		Nml_LogRVCCMRamData.chIndex                  = chIndex;
		Nml_LogRVCCMRamData.chMode                   = Nml_GetChDataCurComMode(chIndex);
		Nml_LogRVCCMRamData.requestedHighMode        = Nml_GetChDataRequestedHighMode(chIndex);
		Nml_LogRVCCMRamData.prevNmState              = Nml_GetPrevNmState(chIndex);
		Nml_LogRVCCMRamData.curNmState               = Nml_GetCurNmState(chIndex);
		Nml_LogRVCCMRamData.repeatMsgTime            = Nml_GetNmRepeatMsgTime(chIndex);
		Nml_LogRVCCMRamData.nmTimeOutTime            = Nml_GetNmTimeOutTime(chIndex);
		Nml_LogRVCCMRamData.waitBusSleeptime         = Nml_GetNmWaitBusSleeptime(chIndex);
		Nml_LogRVCCMRamData.nmNwRequested            = Nml_GetNmNwRequested(chIndex);
		Nml_LogRVCCMRamData.nmStateNotMatchedReason  = nmStateNotMatchedReason;
		Nml_LogRVCCMRamData.detectionTime            = Nml_LibGetTime();
		Nml_LogRVCCMRamData.aliveCycle               = Nml_AliveCycle;
		Nml_LogIncreaseDetectionCnt(&Nml_LogRVCCMRamData.detectionCnt);
		
		/* Set RVCCM RAM data into NvM Buffer */
		Nml_SetLogRvccm();

		/* Set NvM Write request flag */
		#if (NML_NVM_WRITE_USED == STD_ON)
			if (Nml_IsNeedToWriteNvM[NML_DATA_RVCCM] == NML_FLAG_OFF)
			{
				Nml_IsNeedToWriteNvM[NML_DATA_RVCCM] = NML_FLAG_ON;
			}
			else
			{
				/* Do not write request NvM to prevent many NvM write if many detection */
			}
        #endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

#if (NML_DET == STD_ON)
	}
#endif /* #if (NML_DET == STD_ON) */
}


void Nml_LogFuncEAET(void)
{
#if (NML_DET == STD_ON)
	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_SetLogEaet();

#if (NML_DET == STD_ON)
	}
#endif /* #if (NML_DET == STD_ON) */
}


void Nml_LogFuncLCM(uint8 chIndex)
{

#if (NML_DET == STD_ON)
	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */


	    Nml_LogLCMRamData[chIndex].chMode      = Nml_CurComMode[chIndex];
		Nml_LogLCMRamData[chIndex].prevNmState = (uint8)Nml_GetPrevNmState(chIndex); /* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align */
		Nml_LogLCMRamData[chIndex].curNmState  = (uint8)Nml_GetCurNmState(chIndex);  /* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align */

		Nml_SetLogChNum();
		Nml_SetLogLcm();

#if (NML_DET == STD_ON)
	}
#endif /* #if (NML_DET == STD_ON) */
}

#endif /* #if (STD_ON == NML_USE) */

void Nml_LogFuncWUS(uint32 wakeupSource)
{
#if (STD_ON == NML_USE)
	Nml_IsWakeupSource = NML_TRUE;
	Nml_WakeupSource   = (Nml_WakeupSource | wakeupSource);
#endif /* #if (STD_ON == NML_USE) */
}


#define NML_STOP_SEC_CODE
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
