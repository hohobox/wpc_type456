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
#include "Nml_Lib.h"
#include "Nml_Ram.h" 
#include "Nml_Cfg.h"
#include "Nml_Integration.h" /* for NvM data */
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "NvM_WriteBlock API used if NML_NVM_WRITE_USED" */
#include "NvM.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "NvM_WriteBlock API used if NML_NVM_WRITE_USED" */
#if (STD_ON == NML_DEBUG)
	#include "Nml_Test.h"
#endif /*#if (STD_ON == NML_DEBUG)*/

/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/
#define NML_LIB_CALL_PERIOD        NML_CALL_PERIOD /* Main function call period - unit ms */
#define NML_LIB_TIMER_MS_MAX       (1000/NML_LIB_CALL_PERIOD)
#define NML_LIB_TIMER_SEC_MAX      60
#define NML_LIB_TIMER_MIN_MAX      60
#define NML_LIB_TIMER_HOUR_MAX     (uint8)(24*7) /* 1 week max : 24hours X 7 days */




/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (STD_ON == NML_USE)

#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* Nml main function call periodic count to generate time stamp for HH:MM:SS:MS format */
/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint8 Nml_LibCallCnt;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint8 Nml_StoreExceedNvMSizeFlag;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
uint8 Nml_IsNeedNvMStore;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */
boolean Nml_IsFirstMainLoopAfterReset;
/* polyspace-end MISRA-C3:8.4 [Not a defect:Unset] "This global variable is used only in this file. There is no use of this variable other file" */

boolean Nml_IsFirstMainLoopAfterWakeUp;
boolean Nml_IsH2LTransition;
boolean Nml_IsEcuRequestSleep;
uint8 Nml_LibNvMWriteRetryCnt;
boolean Nml_IsNvMWriteDone;

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
/* Nml main function call periodic count to generate for ms format such as 0x00000000 ~ 0xFFFFFFFF ms unit
 * In this case, it can reduce calculating time stamp
 * */
uint16 Nml_LibCallCntTotal;

#define NML_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* To store internal time stamp for HH:MM:SS:MS format */
Nml_TimeType Nml_LibInternalTime;
uint8 Nml_Pattern[NML_PATTERN_SIZE] = {0xEDu, 0xEDu, 0xEDu, 0xEDu};

#if (NML_NVM_WRITE_USED == STD_ON)
	uint8 Nml_IsNeedToWriteNvM[NML_DATA_LAST];
	uint8 Nml_IsWriteNvMDone[NML_DATA_LAST];
#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

#define NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


#endif /* #if (STD_ON == NML_USE) */
/*******************************************************************************
**                      Local Function Declaration                            **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == NML_USE)
	/* List of functions for calculating internal timer (내부타이머) */
	void Nml_LibCheckCounter(void);
	void Nml_LibCalTime(void);
	void Nml_LibInitDataSerialize(void);
	void Nml_LibIncreaseAliveCycle(void);
	void Nml_LibStoreVersionInfo(void);
	void Nml_LibStorePattern(void);
	void Nml_LibStoreMcuResetReason(void);
    #if (NML_NVM_WRITE_USED == STD_ON)
	    void Nml_LibCondCheckNvMWrite(void);
        Std_ReturnType Nml_LibWriteNvM(void);
    #endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/	
#endif /* #if (STD_ON == NML_USE) */

#define NML_STOP_SEC_CODE
#include "MemMap.h"



#define NML_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
#if (STD_ON == NML_USE)

void Nml_LibCheckCounter(void)
{
	if (Nml_LibCallCnt < NML_UINT8_MAX)
	{
		Nml_LibCallCnt++;
	}
	else
	{
		Nml_LibCallCnt = NML_UINT8_MIN;
	}

	if (Nml_LibCallCntTotal < NML_UINT16_MAX)
	{
		Nml_LibCallCntTotal++;
	}
	else
	{
		Nml_LibCallCntTotal = NML_UINT16_MIN;
	}

}


void Nml_LibCalTime(void)
{
	/* SWP_CP_SRS_NML_0001 #565292 */
	/* Calculate ms to sec */
	if(NML_LIB_TIMER_MS_MAX == Nml_LibCallCnt)
	{
		Nml_LibCallCnt = NML_UINT8_MIN;
		Nml_LibInternalTime.ms = NML_UINT8_MIN;
		Nml_LibInternalTime.sec++;
	}
	else
	{
		/* Do nothing */
		Nml_LibInternalTime.ms++;
	}

	/* Calculate sec to min */
	if(NML_LIB_TIMER_SEC_MAX == Nml_LibInternalTime.sec)
	{
		Nml_LibInternalTime.sec = NML_UINT8_MIN;
		Nml_LibInternalTime.min++;
	}
	else
	{
		/* Do nothing */
	}

	/* Calculate min to hour */
	if(NML_LIB_TIMER_MIN_MAX == Nml_LibInternalTime.min)
	{
		Nml_LibInternalTime.min = NML_UINT8_MIN;
		if (Nml_LibInternalTime.hour < NML_LIB_TIMER_HOUR_MAX)
		{
			Nml_LibInternalTime.hour++;
		}
		else
		{
			/* Do nothing */
		}

	}
	else
	{
		/* Do nothing */
	}
}

void Nml_LibInitDataSerialize(void)
{
	uint8 i = 0x00;
	uint16 totalRequiredNvMSize = 0;

	i = (uint8)((uint8)NML_DATA_LAST-1);
	totalRequiredNvMSize = Nml_RDBI_DataFormat[i].startIndex + Nml_RDBI_DataFormat[i].dataSize;

	/* polyspace-begin DEFECT:DEAD_CODE [Not a defect:Unset] "polyspace-begin MISRA-C3:D4.9 [Not a defect:Unset] "No Impact of this rule violation (For safety reason)" */
	/* polyspace-begin MISRA-C3:2.1 [Not a defect:Unset] "No Impact of this rule violation (For safety reason)" */
	/* polyspace-begin MISRA-C3:14.3 [Not a defect:Unset] "No Impact of this rule violation (For safety reason)" */
	/* polyspace-begin CWE:561 [Justified:Unset] "This is predefined macro "size of NvM" from the NvM configuraiton, that's why this condition is always set to False" */
	if (totalRequiredNvMSize > (NML_LOGDATA_SIZE))
	/* polyspace-end CWE:561 [Justified:Unset] "This is predefined macro "size of NvM" from the NvM configuraiton, that's why this condition is always set to False" */
	{
		Nml_Error.exceedNvMSize    = 0x01;
		Nml_Error.doNotRun         = 0x01;
		Nml_Error.indexOverApi     = (uint16) NML_LIBINITDATASERIALIZE;
		Nml_StoreExceedNvMSizeFlag = 0x01;

	}
	else
	{
		Nml_Error.exceedNvMSize = 0x00;
		Nml_Error.doNotRun = 0x00;
		Nml_StoreExceedNvMSizeFlag = 0x00;
	}
	/* polyspace-end DEFECT:DEAD_CODE [Not a defect:Unset] "polyspace-begin MISRA-C3:D4.9 [Not a defect:Unset] "No Impact of this rule violation (For safety reason)" */
	/* polyspace-end MISRA-C3:2.1 [Not a defect:Unset] "No Impact of this rule violation (For safety reason)" */
	/* polyspace-end MISRA-C3:14.3 [Not a defect:Unset] "No Impact of this rule violation (For safety reason)" */

	Nml_IsNeedNvMStore = 0x01;
}

void Nml_LibIncreaseAliveCycle(void)
{

	Nml_GetLogAliveCycle();

	if (Nml_AliveCycle < NML_UINT16_MAX)
	{
		Nml_AliveCycle++;
	}
	else
	{
		/* Do not increase alivecycle
		   - This variable to be used to count NvM write counter
		   - If this reached to MAX 65535, then Nml shall not access NvM Write
		*/
	}
	Nml_SetLogAliveCycle();

	#if (NML_NVM_WRITE_USED == STD_ON)
		if (Nml_IsNeedToWriteNvM[NML_DATA_ALIVE_CYCLE] == NML_FLAG_OFF)
		{
		Nml_IsNeedToWriteNvM[NML_DATA_ALIVE_CYCLE] = NML_FLAG_ON;
		}
		else
		{
		/* Do not write request NvM to prevent many NvM write if many detection */
		}		
	#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/	


}

#if (NML_NVM_WRITE_USED == STD_ON)
 void Nml_LibCondCheckNvMWrite(void)
 {
	Std_ReturnType retNvMWriteReq = E_OK;

	if (Nml_LibNvMWriteRetryCnt < NML_NVM_WRITE_RETRY_MAX)
	{
		if ((Nml_IsH2LTransition == NML_TRUE) || (Nml_IsEcuRequestSleep ==NML_TRUE ))
		{
			/* Donot access NvM */			
		}
		else
		{
			/* Access NvM */
			retNvMWriteReq = Nml_LibWriteNvM();
		}
		
	}
	else
	{

	}
    

	if (E_NOT_OK == retNvMWriteReq)
	{
		if (Nml_LibNvMWriteRetryCnt<NML_NVM_WRITE_RETRY_MAX)
		{
			Nml_LibNvMWriteRetryCnt++;
		}
	}
 }
#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

void Nml_LibStoreVersionInfo(void)
{
	Nml_SetLogNmlVersion();
}

void Nml_LibStorePattern(void)
{
	Nml_SetLogStartPattern();
	Nml_SetLogEndPattern();
}

void Nml_LibStoreMcuResetReason(void)
{
	#if (NML_NVM_WRITE_USED == STD_ON)
         Nml_LogMcuResetType tmpLogMcuResetReason;
    #endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/
	
	Mcu_ResetType tempMcuReset;


	tempMcuReset = Mcu_GetResetReason();

	Nml_LogMcuResetReason.mcuResetType = tempMcuReset;
	/* KCLim_230621 : In case of Mcu reset, alive cycle value should be used previous value because it was done at previous alive cycle */
	if (Nml_AliveCycle>0)
	{
		Nml_LogMcuResetReason.aliveCycle = Nml_AliveCycle - 1 ;
	}
	else
	{
		Nml_LogMcuResetReason.aliveCycle   = Nml_AliveCycle;
	}

	#if (NML_NVM_WRITE_USED == STD_ON)
		Nml_GetLogMcuResetReason(&tmpLogMcuResetReason);
		if (Nml_LogMcuResetReason.mcuResetType != tmpLogMcuResetReason.mcuResetType)
		{
			if (Nml_IsNeedToWriteNvM[NML_DATA_MCU_RESET_REASON] == NML_FLAG_OFF)
			{
				Nml_IsNeedToWriteNvM[NML_DATA_MCU_RESET_REASON] = NML_FLAG_ON;
			}
			else
			{
				/* Do not write request NvM to prevent many NvM write if many detection */
			}
			
		}
		else
		{
			/* Same Mcu Reset reason, no need to store NvM */
		}
	#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/
	Nml_SetLogMcuResetReason();
}

#if (NML_NVM_WRITE_USED == STD_ON)
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:LEVEL [Justified:Low] "To make code easy to read and to maintain" */
Std_ReturnType Nml_LibWriteNvM(void)
/* polyspace-end CODE-METRIC:LEVEL [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
{
	uint8 i = 0x00;
	Std_ReturnType             funcRet   = E_OK; 
	Std_ReturnType             result    = E_OK; 
	NvM_RequestResultType      reqResult = 0x00;

	for (i=(uint8)NML_START_PATTERN; i<(uint8)NML_DATA_LAST; i++)
	{
		if (NML_FLAG_ON == Nml_IsNeedToWriteNvM[i])
		{
			/* Need to Write NvM */
			if (NML_NVM_WRITE_ALLOW_MAX > Nml_IsWriteNvMDone[i])
			{
				/* Never write NvM, Write NvM */

				if (Nml_IsNvMWriteDone == NML_FALSE )
				{
					result = NvM_GetErrorStatus(NML_NVM_BLOCK_ID, &reqResult);
				}
				else
				{
					/* if Nml_IsNvMWriteDone is True, NvM Write Done finished.*/
					result    = E_OK;
					reqResult = E_OK;
				}

				if ((E_OK == result) && (NVM_REQ_PENDING != reqResult))
				{
					if (Nml_AliveCycle < NML_UINT16_MAX)
					{
						if (Nml_IsNvMWriteDone == NML_FALSE )
						{
							result = NvM_WriteBlock(NML_NVM_BLOCK_ID, NML_NVM_BUFFER);
						}
						else
						{
							/* Do not need to Write NvM Again, each log data shall be stored one NvM Block */
							result = E_OK;
						}	
					}
					else
					{

					}
					
					if (result == E_OK)
					{
						Nml_IsNeedToWriteNvM[i] = NML_FLAG_OFF;
						Nml_IsNvMWriteDone = NML_TRUE;
						Nml_IsWriteNvMDone[i]++;
					}
					else
					{
						/* Error status in Nml_LogData NvM Block */
						funcRet   = E_NOT_OK; 
					}
				}
				else
				{
				    /* Error status in Nml_LogData NvM Block */
					funcRet   = E_NOT_OK; 
				}
			}
			else
			{
				/* Already write NvM */
			}

		}
		else
		{
			/* No need to write NvM */
		}
	}
	Nml_IsNvMWriteDone = NML_FALSE;

	return funcRet;
}
#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/	



#endif /* #if (STD_ON == NML_USE) */



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#if (STD_ON == NML_USE)
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
void Nml_LibInit(void)
{

#if (NML_NVM_WRITE_USED == STD_ON)
	uint8 i = 0x00;
#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

#if (NML_MEASURE_TIME == STD_ON)
	/* Tick for Nml_Init function */
	Nml_Init_Runtime.min_us = NML_UINT32_MAX;
	Nml_Init_Runtime.max_us = NML_UINT32_MAX;
	Nml_Init_Runtime.avg_us = NML_UINT32_MAX;
	Nml_Init_Runtime.run_us = NML_UINT32_MAX;

	
	/* Tick for Nml_Main function */
	Nml_Main_Runtime.min_us = NML_UINT32_MAX;
	Nml_Main_Runtime.max_us = NML_UINT32_MAX;
	Nml_Main_Runtime.avg_us = NML_UINT32_MAX;
	Nml_Main_Runtime.run_us = NML_UINT32_MAX;
#endif /* #if (NML_MEASURE_TIME == STD_ON) */

	Nml_Error.doNotRun          = NML_UINT8_MIN;
	Nml_Error.exceedNvMSize     = NML_UINT8_MIN;
	Nml_Error.indexOverApi      = NML_UINT16_MIN;
	Nml_Error.aliveCycle        = NML_UINT16_MIN;
	Nml_Error.infoNvmSrvId      = NML_UINT8_MAX;
	Nml_Error.infoNvmReqResult  = NML_UINT8_MAX;

	/* Init Internal Timer */
	Nml_LibInternalTime.hour = NML_UINT8_MIN;
	Nml_LibInternalTime.min  = NML_UINT8_MIN;
	Nml_LibInternalTime.sec  = NML_UINT8_MIN;
	Nml_LibInternalTime.ms   = NML_UINT8_MIN;

	/* Init Function call counter  */
	Nml_LibCallCnt = NML_UINT8_MIN;
	Nml_LibCallCntTotal = NML_UINT16_MIN;

	Nml_Version.major = NML_VERSION_MAJOR;
	Nml_Version.minor = NML_VERSION_MINOR;
	Nml_Version.patch = NML_VERSION_PATCH;
	Nml_Version.asr   = NML_VERSION_ASR;

	Nml_IsFirstMainLoopAfterReset = NML_TRUE;
	Nml_LibNvMWriteRetryCnt = NML_UINT8_MIN;
	Nml_IsNvMWriteDone = NML_UINT8_MIN;
	Nml_LogMcuResetReason.aliveCycle   = NML_UINT16_MIN;
	Nml_LogMcuResetReason.mcuResetType = MCU_RESET_UNDEFINED;

	#if (NML_NVM_WRITE_USED == STD_ON)
        for (i = 0; i < (uint8)NML_DATA_LAST; i++)
        {
            Nml_IsNeedToWriteNvM[i] = 0x00;
            Nml_IsWriteNvMDone[i]   = 0x00;
        }
	#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

	Nml_IsH2LTransition   = NML_FALSE;
	Nml_IsEcuRequestSleep = NML_FALSE;

	Nml_LibInitDataSerialize();
}
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_LibMain(void)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
	if (NML_TRUE == Nml_IsFirstMainLoopAfterReset)
	{
		Nml_IsFirstMainLoopAfterReset = NML_FALSE;
		Nml_LibIncreaseAliveCycle();
		Nml_LibStoreVersionInfo();
		Nml_LibStorePattern();
		Nml_LibStoreMcuResetReason();
		Nml_SetLogChNum();
		Nml_IsFirstMainLoopAfterWakeUp = NML_FALSE; /* To prevent double counting if Reset and Wakeup occurs concurrently */
	}
	else
	{

	}

	if (NML_TRUE == Nml_IsFirstMainLoopAfterWakeUp)
	{
		Nml_IsFirstMainLoopAfterWakeUp = NML_FALSE;
		Nml_LibIncreaseAliveCycle();
		Nml_SetLogChNum();
	}
	else
	{

	}

	Nml_LibCheckCounter();
	Nml_LibCalTime();

	if (Nml_StoreExceedNvMSizeFlag == 0x01)
	{
		Nml_SetLogNmlError();
		Nml_StoreExceedNvMSizeFlag = 0x00;
		#if (NML_NVM_WRITE_USED == STD_ON)
		if (Nml_IsNeedToWriteNvM[NML_DATA_ERROR] == NML_FLAG_OFF)
		{
			Nml_IsNeedToWriteNvM[NML_DATA_ERROR] = NML_FLAG_ON;
		}
		else
        {
          /* Do not write request NvM to prevent many NvM write if many detection */
        }
            
        #endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/
	}
	else
	{
		/* Do nothing, already stored NvM */
	}
 	
	#if (NML_NVM_WRITE_USED == STD_ON)
		Nml_LibCondCheckNvMWrite();
	#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/
}

Nml_TimeType Nml_LibGetTime(void)
{
	return Nml_LibInternalTime;
}

uint16 Nml_LibGetTimeCnt(void)
{
	return Nml_LibCallCntTotal;
}

Nml_TimeType Nml_LibGetDiffTime(Nml_TimeType startTime, Nml_TimeType endTime )
{
	Nml_TimeType tempTime;
	if(startTime.ms <= endTime.ms)
	{
		tempTime.ms = endTime.ms - startTime.ms;
	}
	else
	{
		tempTime.ms = NML_LIB_TIMER_MS_MAX - startTime.ms;
		tempTime.ms = tempTime.ms + endTime.ms;
	}

	if(startTime.sec <= endTime.sec)
	{
		tempTime.sec = endTime.sec - startTime.sec;
	}
	else
	{
		tempTime.sec = NML_LIB_TIMER_SEC_MAX - startTime.sec;
		tempTime.sec = tempTime.sec + endTime.sec;
	}

	if(startTime.min <= endTime.min)
	{
		tempTime.min = endTime.min - startTime.min;
	}
	else
	{
		tempTime.min = NML_LIB_TIMER_MIN_MAX - startTime.min;
		tempTime.min = tempTime.min + endTime.min;
	}

	if(startTime.hour <= endTime.hour)
	{
		tempTime.hour = endTime.hour - startTime.hour;
	}
	else
	{
		tempTime.hour = NML_LIB_TIMER_HOUR_MAX - startTime.hour;
		tempTime.hour = tempTime.hour + endTime.hour;
	}

	return tempTime;
}

uint32 Nml_LibGetDiffTimeCnt_U32(uint32 startCnt, uint32 EndCnt)
{
	uint32 tempCnt = 0x00;

	if (startCnt < EndCnt)
	{
		tempCnt = EndCnt - startCnt;
	}
	else
	{
		tempCnt = NML_UINT32_MAX - startCnt;
		tempCnt = tempCnt + EndCnt;
	}
	return tempCnt;	
}

uint16 Nml_LibSetTargetTimeCnt_U16(uint16 startCnt, uint16 targetCnt)
{
	uint16 retCnt = 0x0000;
	uint32 tempCnt = 0x00;

	tempCnt = (uint32)startCnt + (uint32)targetCnt;
	if (tempCnt > (uint32)NML_UINT16_MAX)
	{
		retCnt = NML_UINT16_MAX - startCnt;
		retCnt = retCnt + targetCnt;
	}
	else
	{
		retCnt = (uint16)tempCnt;
	}

	return retCnt;
}

uint16 Nml_LibGetDiffTimeCnt_U16(uint16 startCnt, uint16 EndCnt)
{
	uint16 tempCnt = 0x00;

	if (startCnt < EndCnt)
	{
		tempCnt = EndCnt - startCnt;
	}
	else
	{
		tempCnt = NML_UINT16_MAX - startCnt;
		tempCnt = tempCnt + EndCnt;
	}
	return tempCnt;
}

uint8 Nml_LibGetDiffTimeCnt_U8(uint8 startCnt, uint8 EndCnt)
{
	uint8 tempCnt = 0x00;

	if (startCnt < EndCnt)
	{
		tempCnt = EndCnt - startCnt;
	}
	else
	{
		tempCnt = NML_UINT8_MAX - startCnt;
		tempCnt = tempCnt + EndCnt;
	}
	return tempCnt;
}

#if (NML_MEASURE_TIME == STD_ON)
void Nml_LibBeginElapsedTick(uint32* startTime)
{
	*startTime = NML_GET_TIMESTAMP();

}

void Nml_LibEndElapsedTick(uint32* startTime, uint32* timeMin, uint32* timeMax, uint32* timeAvg, uint32* timeRun)
{
	uint32 endTime       = 0;
	uint32 startTempTime = 0;
	uint32 tempTime      = 0;

	endTime       = NML_GET_TIMESTAMP();
	startTempTime = (*startTime);

	if (startTempTime < endTime)
	{
		tempTime = endTime - startTempTime;
	}
	else
	{
		tempTime = NML_UINT32_MAX - startTempTime;
		tempTime = tempTime + endTime;
	}

	/* change unit from 10ns to 1us :
	 * ex) value 100 means 100 x 10ns (STM unit) = 1000ns  = 1us
	 *     value 100 means 100 / 100(NML_MEASURE_TIME_US)  = 1us*/
	tempTime = tempTime / NML_MEASURE_TIME_US;
	/* Set Run time */
	(*timeRun) = tempTime;

	/* Set Min time */
	if (tempTime < (*timeMin))
	{
		*timeMin = tempTime;
	}
	else
	{
		/* Do nothing */
	}

	/* Set Max time */
	if (tempTime > (*timeMax))
	{
		*timeMax = tempTime;
	}
	else
	{
		/* Do nothing */
	}

	/* TBD : think about avg time */
	*timeAvg = ((*timeMax) + (*timeMin)) / 2;

}
#endif /* #if (NML_MEASURE_TIME == STD_ON) */


#if (NML_DET == STD_ON)
/* polyspace-begin CODE-METRIC:CALLING [Justified:Unset] "This function is a kind of library function to check whether index is over or not before accessing array. This function required as a library to prevent memory corruption if index is over the array size." */
void Nml_ChkIndexRangeOver(uint8 userIndex, uint8 maxIndex, Nml_ApiIndexType apiIndex)
/* polyspace-end CODE-METRIC:CALLING [Justified:Unset] "This function is a kind of library function to check whether index is over or not before accessing array. This function required as a library to prevent memory corruption if index is over the array size." */
{

	if (userIndex >= maxIndex)
	{
		Nml_Error.indexOverApi = Nml_Error.indexOverApi | ((uint16)1 << (uint16)apiIndex);
		Nml_Error.doNotRun     = 0x01;
		Nml_Error.aliveCycle   = Nml_AliveCycle;
		Nml_SetLogNmlError();
		#if (NML_NVM_WRITE_USED == STD_ON)
			if (Nml_IsNeedToWriteNvM[NML_DATA_ERROR] == NML_FLAG_OFF)
			{
				Nml_IsNeedToWriteNvM[NML_DATA_ERROR] = NML_FLAG_ON;
			}
			else
			{
			/* Do not write request NvM to prevent many NvM write if many detection */
			}
        #endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/
	}
	else
	{
		/* Do nothing, no index over */
	}

}
#endif /* #if (NML_DET == STD_ON) */

#endif /* #if (STD_ON == NML_USE) */

#if (STD_ON == NML_USE)
void Nml_SetLogStartPattern(void)
{
	/* Simple is the best */
    NML_NVM_BUFFER[0] = Nml_Pattern[0];
	NML_NVM_BUFFER[1] = Nml_Pattern[1];
	NML_NVM_BUFFER[2] = Nml_Pattern[2];
	NML_NVM_BUFFER[3] = Nml_Pattern[3];
}

void Nml_GetLogStartPattern(void)
{
	/* Simple is the best */
    Nml_Pattern[0] = NML_NVM_BUFFER[0];
	Nml_Pattern[1] = NML_NVM_BUFFER[1];
	Nml_Pattern[2] = NML_NVM_BUFFER[2];
	Nml_Pattern[3] = NML_NVM_BUFFER[3];
}

void Nml_SetLogAliveCycle(void)
{
	uint16 tmpAliveCycle = 0x0000;

	tmpAliveCycle = (uint16)Nml_AliveCycle;
    NML_NVM_BUFFER[4] = (uint8)Nml_TransTwoByteToZero(tmpAliveCycle);
	NML_NVM_BUFFER[5] = (uint8)Nml_TransTwoByteToOne(tmpAliveCycle);
}

void Nml_GetLogAliveCycle(void)
{
	uint16 tmpTwoByte = 0x0000;
	uint8  tmpOneByte = 0x00;

	tmpOneByte = NML_NVM_BUFFER[4];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[5];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_AliveCycle = (uint16)tmpTwoByte;
}

void Nml_SetLogNmlError(void)
{
	Nml_ErrorType tmpError;

	tmpError = Nml_Error;

	NML_NVM_BUFFER[6]  = (uint8)tmpError.doNotRun;
	NML_NVM_BUFFER[7]  = (uint8)tmpError.exceedNvMSize;
	NML_NVM_BUFFER[8]  = (uint8)tmpError.infoNvmSrvId;
	NML_NVM_BUFFER[9]  = (uint8)tmpError.infoNvmReqResult;
	NML_NVM_BUFFER[10] = (uint8)Nml_TransTwoByteToZero(tmpError.indexOverApi);
	NML_NVM_BUFFER[11] = (uint8)Nml_TransTwoByteToOne(tmpError.indexOverApi);
	NML_NVM_BUFFER[12] = (uint8)Nml_TransTwoByteToZero(tmpError.aliveCycle);
	NML_NVM_BUFFER[13] = (uint8)Nml_TransTwoByteToOne(tmpError.aliveCycle);			
}

void Nml_GetLogNmlError(void)
{
	uint16 tmpTwoByte = 0x0000;
	uint8  tmpOneByte = 0x00;

    Nml_Error.doNotRun         = (uint8)NML_NVM_BUFFER[6];
    Nml_Error.exceedNvMSize    = (uint8)NML_NVM_BUFFER[7];
    Nml_Error.infoNvmSrvId     = (uint8)NML_NVM_BUFFER[8];
    Nml_Error.infoNvmReqResult = (uint8)NML_NVM_BUFFER[9];

	tmpOneByte = NML_NVM_BUFFER[10];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[11];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_Error.indexOverApi = (uint16)tmpTwoByte;

	tmpTwoByte = 0x0000; /* Clear buffer otherwise previous value shall be used */
	tmpOneByte = NML_NVM_BUFFER[12];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[13];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_Error.aliveCycle = (uint16)tmpTwoByte;
}

void Nml_SetLogNmlVersion(void)
{
	Nml_VersionType tmpVersion;

	tmpVersion = Nml_Version;

    NML_NVM_BUFFER[14] = (uint8)tmpVersion.major;
    NML_NVM_BUFFER[15] = (uint8)tmpVersion.minor;
    NML_NVM_BUFFER[16] = (uint8)tmpVersion.patch;
    NML_NVM_BUFFER[17] = (uint8)tmpVersion.asr  ;
}

void Nml_GetLogNmlVersion(void)
{
	Nml_Version.major = (uint8)NML_NVM_BUFFER[14];
	Nml_Version.minor = (uint8)NML_NVM_BUFFER[15];
	Nml_Version.patch = (uint8)NML_NVM_BUFFER[16];
	Nml_Version.asr   = (uint8)NML_NVM_BUFFER[17];
}

void Nml_SetLogEaet(void)
{
	Nml_TimeType tmpTime;

	tmpTime = Nml_LibInternalTime;

    NML_NVM_BUFFER[18] = (uint8)tmpTime.hour;
    NML_NVM_BUFFER[19] = (uint8)tmpTime.min ;
    NML_NVM_BUFFER[20] = (uint8)tmpTime.sec ;
    NML_NVM_BUFFER[21] = (uint8)tmpTime.ms  ;
}
void Nml_GetLogEaet(void)
{
    Nml_LibInternalTime.hour = (uint8)NML_NVM_BUFFER[18];
    Nml_LibInternalTime.min  = (uint8)NML_NVM_BUFFER[19];
    Nml_LibInternalTime.sec  = (uint8)NML_NVM_BUFFER[20];
    Nml_LibInternalTime.ms   = (uint8)NML_NVM_BUFFER[21];
}

void Nml_SetLogRvccm(void)
{
	Nml_LogRVCCMRamDataType tmpRVCCM;

	tmpRVCCM = Nml_LogRVCCMRamData;

	/* Simple is the best */
    NML_NVM_BUFFER[22] = (uint8)tmpRVCCM.detectionTime.hour;
	NML_NVM_BUFFER[23] = (uint8)tmpRVCCM.detectionTime.min ;
	NML_NVM_BUFFER[24] = (uint8)tmpRVCCM.detectionTime.sec ;
	NML_NVM_BUFFER[25] = (uint8)tmpRVCCM.detectionTime.ms  ;

	NML_NVM_BUFFER[26] = (uint8)tmpRVCCM.prevNmState;
	NML_NVM_BUFFER[27] = (uint8)tmpRVCCM.curNmState;

	NML_NVM_BUFFER[28] = (uint8)Nml_TransTwoByteToZero(tmpRVCCM.repeatMsgTime);
	NML_NVM_BUFFER[29] = (uint8)Nml_TransTwoByteToOne(tmpRVCCM.repeatMsgTime);

    NML_NVM_BUFFER[30] = (uint8)Nml_TransTwoByteToZero(tmpRVCCM.nmTimeOutTime);
    NML_NVM_BUFFER[31] = (uint8)Nml_TransTwoByteToOne(tmpRVCCM.nmTimeOutTime);

	NML_NVM_BUFFER[32] = (uint8)Nml_TransTwoByteToZero(tmpRVCCM.aliveCycle);
    NML_NVM_BUFFER[33] = (uint8)Nml_TransTwoByteToOne(tmpRVCCM.aliveCycle);

	NML_NVM_BUFFER[34] = (uint8)Nml_TransTwoByteToZero(tmpRVCCM.waitBusSleeptime);
    NML_NVM_BUFFER[35] = (uint8)Nml_TransTwoByteToOne(tmpRVCCM.waitBusSleeptime);

	NML_NVM_BUFFER[36] = (uint8)(tmpRVCCM.chIndex);

    NML_NVM_BUFFER[37] = (uint8)(tmpRVCCM.chMode);

    NML_NVM_BUFFER[38] = (uint8)(tmpRVCCM.requestedHighMode);

	NML_NVM_BUFFER[39] = (uint8)(tmpRVCCM.nmNwRequested);

	NML_NVM_BUFFER[40] = (uint8)(tmpRVCCM.nmStateNotMatchedReason);

	NML_NVM_BUFFER[41] = (uint8)(tmpRVCCM.detectionCnt);
}

void Nml_GetLogRvccm(void)
{
	uint16 tmpTwoByte = 0x0000;
	uint8 tmpOneByte = 0x00;

	/* Simple is the best */
     Nml_LogRVCCMRamData.detectionTime.hour = (uint8)NML_NVM_BUFFER[22];
     Nml_LogRVCCMRamData.detectionTime.min  = (uint8)NML_NVM_BUFFER[23];
     Nml_LogRVCCMRamData.detectionTime.sec  = (uint8)NML_NVM_BUFFER[24];
     Nml_LogRVCCMRamData.detectionTime.ms   = (uint8)NML_NVM_BUFFER[25];

     Nml_LogRVCCMRamData.prevNmState        = (Nm_StateType)NML_NVM_BUFFER[26];
     Nml_LogRVCCMRamData.curNmState         = (Nm_StateType)NML_NVM_BUFFER[27];

	tmpOneByte = NML_NVM_BUFFER[28];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[29];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogRVCCMRamData.repeatMsgTime = (uint16)tmpTwoByte;

	tmpTwoByte = 0x0000; /* Clear buffer otherwise previous value shall be used */
	tmpOneByte = NML_NVM_BUFFER[30];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[31];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogRVCCMRamData.nmTimeOutTime = (uint16)tmpTwoByte;

	tmpTwoByte = 0x0000; /* Clear buffer otherwise previous value shall be used */
	tmpOneByte = NML_NVM_BUFFER[32];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[33];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogRVCCMRamData.aliveCycle = (uint16)tmpTwoByte;

	tmpTwoByte = 0x0000; /* Clear buffer otherwise previous value shall be used */
	tmpOneByte = NML_NVM_BUFFER[34];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[35];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogRVCCMRamData.waitBusSleeptime = (uint16)tmpTwoByte;

     Nml_LogRVCCMRamData.chIndex                 = (NetworkHandleType)NML_NVM_BUFFER[36];

     Nml_LogRVCCMRamData.chMode                  = (ComM_ModeType)NML_NVM_BUFFER[37];

     Nml_LogRVCCMRamData.requestedHighMode       = (ComM_ModeType)NML_NVM_BUFFER[38];

     Nml_LogRVCCMRamData.nmNwRequested           = (boolean)NML_NVM_BUFFER[39];

     Nml_LogRVCCMRamData.nmStateNotMatchedReason = (uint8)NML_NVM_BUFFER[40];

     Nml_LogRVCCMRamData.detectionCnt            = (uint8)NML_NVM_BUFFER[41];
}

void Nml_SetLogCmc(void)
{
	Nml_LogCMCRamDataType tmpCMC;

	tmpCMC = Nml_LogCMCRamData;

    NML_NVM_BUFFER[42] = (uint8)tmpCMC.detectionTime.hour;
    NML_NVM_BUFFER[43] = (uint8)tmpCMC.detectionTime.min ;
    NML_NVM_BUFFER[44] = (uint8)tmpCMC.detectionTime.sec ;
    NML_NVM_BUFFER[45] = (uint8)tmpCMC.detectionTime.ms  ;
    NML_NVM_BUFFER[46] = (uint8)Nml_TransTwoByteToZero(tmpCMC.aliveCycle);
    NML_NVM_BUFFER[47] = (uint8)Nml_TransTwoByteToOne(tmpCMC.aliveCycle) ;
    NML_NVM_BUFFER[48] = (uint8)tmpCMC.chIndex;
    NML_NVM_BUFFER[49] = (uint8)tmpCMC.detectionCnt;
}
void Nml_GetLogCmc(void)
{
	uint16 tmpTwoByte = 0x0000;
	uint8 tmpOneByte = 0x00;

    Nml_LogCMCRamData.detectionTime.hour = (uint8)NML_NVM_BUFFER[42];
    Nml_LogCMCRamData.detectionTime.min  = (uint8)NML_NVM_BUFFER[43];
    Nml_LogCMCRamData.detectionTime.sec  = (uint8)NML_NVM_BUFFER[44];
    Nml_LogCMCRamData.detectionTime.ms   = (uint8)NML_NVM_BUFFER[45];

	tmpOneByte = NML_NVM_BUFFER[46];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[47];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogCMCRamData.aliveCycle = (uint16)tmpTwoByte;

	Nml_LogCMCRamData.chIndex      = (NetworkHandleType)NML_NVM_BUFFER[48];
	Nml_LogCMCRamData.detectionCnt = (uint8)NML_NVM_BUFFER[49];
}

void Nml_SetLogMcuResetReason(void)
{
	Nml_LogMcuResetType tmpMcuResetReason;

	tmpMcuResetReason = Nml_LogMcuResetReason;

    NML_NVM_BUFFER[50] = (uint8)Nml_TransTwoByteToZero(tmpMcuResetReason.mcuResetType);
    NML_NVM_BUFFER[51] = (uint8)Nml_TransTwoByteToOne(tmpMcuResetReason.mcuResetType);
    NML_NVM_BUFFER[52] = (uint8)Nml_TransTwoByteToZero(tmpMcuResetReason.aliveCycle);
    NML_NVM_BUFFER[53] = (uint8)Nml_TransTwoByteToOne(tmpMcuResetReason.aliveCycle);
}
void Nml_GetLogMcuResetReason(Nml_LogMcuResetType* mcuResetReason)
{
	uint16 tmpTwoByte = 0x0000;
	uint8 tmpOneByte = 0x00;

	tmpOneByte = NML_NVM_BUFFER[50];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[51];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	mcuResetReason->mcuResetType = (Mcu_ResetType)tmpTwoByte;

	tmpTwoByte = 0x0000; /* Clear buffer otherwise previous value shall be used */
	tmpOneByte = NML_NVM_BUFFER[52];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[53];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	mcuResetReason->aliveCycle = (uint16)tmpTwoByte;
}

void Nml_SetLogWakeupSource(void)
{
	Nml_LogWakeupSourceType tmpWakeupSource;

	tmpWakeupSource = Nml_LogWakeupSource;

    NML_NVM_BUFFER[54] = (uint8)Nml_TransFourByteToZero(tmpWakeupSource.wakeupSource);
    NML_NVM_BUFFER[55] = (uint8)Nml_TransFourByteToOne(tmpWakeupSource.wakeupSource);
    NML_NVM_BUFFER[56] = (uint8)Nml_TransFourByteToTwo(tmpWakeupSource.wakeupSource);
    NML_NVM_BUFFER[57] = (uint8)Nml_TransFourByteToThree(tmpWakeupSource.wakeupSource);

	NML_NVM_BUFFER[58] = (uint8)tmpWakeupSource.wakeupSourceOrder[0];
    NML_NVM_BUFFER[59] = (uint8)tmpWakeupSource.wakeupSourceOrder[1];
    NML_NVM_BUFFER[60] = (uint8)tmpWakeupSource.wakeupSourceOrder[2];

    NML_NVM_BUFFER[61] = (uint8)tmpWakeupSource.wakeupSourceTime[0].hour;
    NML_NVM_BUFFER[62] = (uint8)tmpWakeupSource.wakeupSourceTime[0].min ;
    NML_NVM_BUFFER[63] = (uint8)tmpWakeupSource.wakeupSourceTime[0].sec ;
    NML_NVM_BUFFER[64] = (uint8)tmpWakeupSource.wakeupSourceTime[0].ms  ;	

    NML_NVM_BUFFER[65] = (uint8)tmpWakeupSource.wakeupSourceTime[1].hour;
    NML_NVM_BUFFER[66] = (uint8)tmpWakeupSource.wakeupSourceTime[1].min ;
    NML_NVM_BUFFER[67] = (uint8)tmpWakeupSource.wakeupSourceTime[1].sec ;
    NML_NVM_BUFFER[68] = (uint8)tmpWakeupSource.wakeupSourceTime[1].ms  ;	

    NML_NVM_BUFFER[69] = (uint8)tmpWakeupSource.wakeupSourceTime[2].hour;
    NML_NVM_BUFFER[70] = (uint8)tmpWakeupSource.wakeupSourceTime[2].min ;
    NML_NVM_BUFFER[71] = (uint8)tmpWakeupSource.wakeupSourceTime[2].sec ;
    NML_NVM_BUFFER[72] = (uint8)tmpWakeupSource.wakeupSourceTime[2].ms  ;

    NML_NVM_BUFFER[73] = (uint8)Nml_TransTwoByteToZero(tmpWakeupSource.aliveCycle[0]);
    NML_NVM_BUFFER[74] = (uint8)Nml_TransTwoByteToOne(tmpWakeupSource.aliveCycle[0]);	

    NML_NVM_BUFFER[75] = (uint8)Nml_TransTwoByteToZero(tmpWakeupSource.aliveCycle[1]);
    NML_NVM_BUFFER[76] = (uint8)Nml_TransTwoByteToOne(tmpWakeupSource.aliveCycle[1]);	

    NML_NVM_BUFFER[77] = (uint8)Nml_TransTwoByteToZero(tmpWakeupSource.aliveCycle[2]);
    NML_NVM_BUFFER[78] = (uint8)Nml_TransTwoByteToOne(tmpWakeupSource.aliveCycle[2]);			
}
void Nml_GetLogWakeupSource(void)
{
	uint32 tmpFourByte = 0x00000000;
	uint16 tmpTwoByte  =     0x0000;
	uint8  tmpOneByte  =       0x00;

	tmpOneByte  = NML_NVM_BUFFER[54];
	tmpFourByte = Nml_TransZeroByteToFourByte(tmpFourByte, tmpOneByte);
	tmpOneByte  = NML_NVM_BUFFER[55];
	tmpFourByte = Nml_TransOneByteToFourByte(tmpFourByte, tmpOneByte);
	tmpOneByte  = NML_NVM_BUFFER[56];
	tmpFourByte = Nml_TransTowByteToFourByte(tmpFourByte, tmpOneByte);
	tmpOneByte  = NML_NVM_BUFFER[57];
	tmpFourByte = Nml_TransThreeByteToFourByte(tmpFourByte, tmpOneByte);
	Nml_LogWakeupSource.wakeupSource = (uint32)tmpFourByte;

    Nml_LogWakeupSource.wakeupSourceOrder[0] = (uint8)NML_NVM_BUFFER[58];
    Nml_LogWakeupSource.wakeupSourceOrder[1] = (uint8)NML_NVM_BUFFER[59];
    Nml_LogWakeupSource.wakeupSourceOrder[2] = (uint8)NML_NVM_BUFFER[60];

    Nml_LogWakeupSource.wakeupSourceTime[0].hour = (uint8)NML_NVM_BUFFER[61];
    Nml_LogWakeupSource.wakeupSourceTime[0].min  = (uint8)NML_NVM_BUFFER[62];
    Nml_LogWakeupSource.wakeupSourceTime[0].sec  = (uint8)NML_NVM_BUFFER[63];
    Nml_LogWakeupSource.wakeupSourceTime[0].ms   = (uint8)NML_NVM_BUFFER[64];	

    Nml_LogWakeupSource.wakeupSourceTime[1].hour = (uint8)NML_NVM_BUFFER[65];
    Nml_LogWakeupSource.wakeupSourceTime[1].min  = (uint8)NML_NVM_BUFFER[66];
    Nml_LogWakeupSource.wakeupSourceTime[1].sec  = (uint8)NML_NVM_BUFFER[67];
    Nml_LogWakeupSource.wakeupSourceTime[1].ms   = (uint8)NML_NVM_BUFFER[68];

    Nml_LogWakeupSource.wakeupSourceTime[2].hour = (uint8)NML_NVM_BUFFER[69];
    Nml_LogWakeupSource.wakeupSourceTime[2].min  = (uint8)NML_NVM_BUFFER[70];
    Nml_LogWakeupSource.wakeupSourceTime[2].sec  = (uint8)NML_NVM_BUFFER[71];
    Nml_LogWakeupSource.wakeupSourceTime[2].ms   = (uint8)NML_NVM_BUFFER[72];

	tmpOneByte = NML_NVM_BUFFER[73];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[74];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogWakeupSource.aliveCycle[0] = (uint16)tmpTwoByte;

	tmpOneByte = NML_NVM_BUFFER[75];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[76];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogWakeupSource.aliveCycle[1] = (uint16)tmpTwoByte;

	tmpOneByte = NML_NVM_BUFFER[77];
	tmpTwoByte = Nml_TransZeroByteToTwoByte(tmpTwoByte, tmpOneByte);
	tmpOneByte = NML_NVM_BUFFER[78];
	tmpTwoByte = Nml_TransOneByteToTwoByte(tmpTwoByte, tmpOneByte);
	Nml_LogWakeupSource.aliveCycle[2] = (uint16)tmpTwoByte;

}

void Nml_SetLogEndPattern(void)
{
	/* Simple is the best */
    NML_NVM_BUFFER[79] = Nml_Pattern[0];
	NML_NVM_BUFFER[80] = Nml_Pattern[1];
	NML_NVM_BUFFER[81] = Nml_Pattern[2];
	NML_NVM_BUFFER[82] = Nml_Pattern[3];
}
void Nml_GetLogEndPattern(void)
{
	/* Simple is the best */
    Nml_Pattern[0] = NML_NVM_BUFFER[79];
	Nml_Pattern[1] = NML_NVM_BUFFER[80];
	Nml_Pattern[2] = NML_NVM_BUFFER[81];
	Nml_Pattern[3] = NML_NVM_BUFFER[82];
}

void Nml_SetLogChNum(void)
{
	NML_NVM_BUFFER[83] = NML_COMM_TOTAL_CHANNELS;	
}
void Nml_GetLogChNum(void)
{
	Nml_ComMTotalChannel = NML_NVM_BUFFER[83];
}

void Nml_SetLogLcm(void)
{
	uint8 RDBI_DataFormat_Index    = 0x00;
	uint8 NvM_Buffer_LcmStartIndex = 0x00;
	uint8 NvM_Buffer_LcmEndIndex   = 0x00;
	uint8 i = 0x00;
	uint8 j = 0x00;
	uint8 errorIndexOverRange = 0x00;
	Nml_LogLCMType tmpLCMRamData[NML_COMM_TOTAL_CHANNELS];

	Nml_Memcpy(&tmpLCMRamData[0], & Nml_LogLCMRamData[0], (sizeof(Nml_LogLCMType) * NML_COMM_TOTAL_CHANNELS));

	RDBI_DataFormat_Index    = (uint8)((uint8)NML_DATA_LAST-1);
	NvM_Buffer_LcmStartIndex = (uint8)(Nml_RDBI_DataFormat[RDBI_DataFormat_Index].startIndex);
	NvM_Buffer_LcmEndIndex   = (uint8)(Nml_RDBI_DataFormat[RDBI_DataFormat_Index].startIndex + Nml_RDBI_DataFormat[RDBI_DataFormat_Index].dataSize);	

	
	if (NvM_Buffer_LcmEndIndex < NML_LOGDATA_SIZE)
	{
		i = NvM_Buffer_LcmStartIndex;
		/* final buffer index is in the range */
		do{
			if (j >= NML_COMM_TOTAL_CHANNELS)
			{
				/* Protection code - Index is over the range of array, do nothing to prevent memory corruption */
				errorIndexOverRange = 0x01;
			}
			else
			{
				NML_NVM_BUFFER[i] = (uint8)tmpLCMRamData[j].chMode;
				i++; /* move to next index of NvM Buffer */
				NML_NVM_BUFFER[i] = (uint8)tmpLCMRamData[j].prevNmState;
				i++; /* move to next index of NvM Buffer */
				NML_NVM_BUFFER[i] = (uint8)tmpLCMRamData[j].curNmState;
				i++; /* move to next index of NvM Buffer */
				j++; /* move to next array of LCM RAM Data */
			}
		}while(i < NvM_Buffer_LcmEndIndex);		
	}
	else
	{
		/* Protection code - Index is over the range of array, do nothing to prevent memory corruption */
		errorIndexOverRange = 0x01;
	}


	if (errorIndexOverRange > 0x00)
	{
		Nml_Error.indexOverApi = Nml_Error.indexOverApi | ((uint16)1 << (uint16)NML_SETLOGLCM);
		Nml_Error.doNotRun     = 0x01;
		Nml_Error.aliveCycle   = Nml_AliveCycle;
		Nml_SetLogNmlError();
	}
	else
	{

	}
}

#endif /* #if (STD_ON == NML_USE) */




#define NML_STOP_SEC_CODE
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
