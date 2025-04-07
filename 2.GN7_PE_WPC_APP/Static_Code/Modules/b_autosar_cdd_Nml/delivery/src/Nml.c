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
**                      Macro Definition                                      **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml.h" 
#include "Nml_Ram.h" 
#include "Nml_Lib.h"
#include "Nml_Log.h"
#include "Nml_Internal.h"
#if (STD_ON == NML_TEST)
#include "Nml_Test.h" /* included for RefApp role*/
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/




/*******************************************************************************
**                      Local Function Declaration                            **
*******************************************************************************/
void Nml_GetReqedCurComMode(void);
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* polyspace MISRA-C3:8.4 [Justified:Unset] "'230426_KCLim : This global variable is used only in this file. There is no use of this variable other file." */


#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"




/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

void Nml_Init(void)
{
#if (NML_MEASURE_TIME == STD_ON)
	uint32 startTime = 0;
	Nml_LibBeginElapsedTick(&startTime);
#endif /* #if (NML_MEASURE_TIME == STD_ON) */

#if (STD_ON == NML_USE)

	Nml_LibInit();
	/* polyspace MISRA-C3:8.5 [Not a defect:Unset] "'230426_KCLim : This function declared at only one file. no declaration in other files." */
    Nml_LogInit();

	#if (STD_ON == NML_TEST)
		Nml_TestAppInit();
	#endif

	Nml_InternalInit();

#endif /* #if (STD_ON == NML_USE) */

#if (NML_MEASURE_TIME == STD_ON)
	Nml_LibEndElapsedTick(&startTime, &Nml_Init_Runtime.min_us, &Nml_Init_Runtime.max_us, &Nml_Init_Runtime.avg_us, &Nml_Init_Runtime.run_us);
#endif /* #if (NML_MEASURE_TIME == STD_ON) */
}


void Nml_Main(void)
{
#if (NML_MEASURE_TIME == STD_ON)
	uint32 startTime = 0;
	Nml_LibBeginElapsedTick(&startTime);
#endif /* #if (NML_MEASURE_TIME == STD_ON) */

#if (STD_ON == NML_USE)

	#if (STD_ON == NML_TEST)
		Nml_TestAppMainPre();
	#endif /* #if (STD_ON == NML_TEST) */

	if (0x01 == Nml_Error.doNotRun)
	{
		/* Detect array index is over the range, do not run */
	}
	else
	{
		Nml_LibMain();
		Nml_InternalMain();
	}

	#if (STD_ON == NML_TEST)
		Nml_TestAppMainPost();
	#endif /* #if (STD_ON == NML_TEST) */

#endif /* #if (STD_ON == NML_USE) */

#if (NML_MEASURE_TIME == STD_ON)
	Nml_LibEndElapsedTick(&startTime, &Nml_Main_Runtime.min_us, &Nml_Main_Runtime.max_us, &Nml_Main_Runtime.avg_us, &Nml_Main_Runtime.run_us);
#endif /* #if (NML_MEASURE_TIME == STD_ON) */
}

void Nml_Shutdown(void)
{
#if (STD_ON == NML_USE)
	/* ToDo : Set Data of current elapsed time */
#endif /* #if (STD_ON == NML_USE) */
}




Nml_ErrorType Nml_GetError(void)
{
#if (STD_ON == NML_USE)
	return Nml_Error;
#else
	Nml_ErrorType Nml_Error_Dummy;
	Nml_Error_Dummy.doNotRun         = 0xFF;
	Nml_Error_Dummy.exceedNvMSize    = 0xFF;
	Nml_Error_Dummy.indexOverApi     = 0xFFFF;
	Nml_Error_Dummy.aliveCycle       = 0xFFFF;
	Nml_Error_Dummy.infoNvmSrvId     = 0xFF;
	Nml_Error_Dummy.infoNvmReqResult = 0xFF;
	return Nml_Error_Dummy;
#endif /* #if (STD_ON == NML_USE) */
}

/* polyspace-begin DEFECT:EXPENSIVE_RETURN_BY_VALUE [Justified:Unset] "Reason of struct variable return is that to prevent global variable change by pointer. this function shall be used by User to get Log data" */
Nml_LogCMCRamDataType Nml_GetCMCData(void)
/* polyspace-end DEFECT:EXPENSIVE_RETURN_BY_VALUE [Justified:Unset] "Reason of struct variable return is that to prevent global variable change by pointer. this function shall be used by User to get Log data" */
{
#if (STD_ON == NML_USE)
	return Nml_LogCMCRamData;
#else
	Nml_LogCMCRamDataType Nml_LogCMCRamData_Dummy;
	Nml_LogCMCRamData_Dummy.chIndex       = 0xFF;
	Nml_LogCMCRamData_Dummy.aliveCycle    = 0xFFFF;
	Nml_LogCMCRamData_Dummy.detectionCnt  = 0xFF;
	Nml_LogCMCRamData_Dummy.detectionTime.hour = 0xFF;
	Nml_LogCMCRamData_Dummy.detectionTime.min  = 0xFF;
	Nml_LogCMCRamData_Dummy.detectionTime.sec  = 0xFF;
	Nml_LogCMCRamData_Dummy.detectionTime.ms   = 0xFF;
	return Nml_LogCMCRamData_Dummy;
#endif /* #if (STD_ON == NML_USE) */
}
/* polyspace-begin DEFECT:EXPENSIVE_RETURN_BY_VALUE [Justified:Unset] "Reason of struct variable return is that to prevent global variable change by pointer. this function shall be used by User to get Log data" */
Nml_LogRVCCMRamDataType Nml_GetRVCCMData(void)
/* polyspace-end DEFECT:EXPENSIVE_RETURN_BY_VALUE [Justified:Unset] "Reason of struct variable return is that to prevent global variable change by pointer. this function shall be used by User to get Log data" */
{
#if (STD_ON == NML_USE)
	return Nml_LogRVCCMRamData;
#else
	Nml_LogRVCCMRamDataType Nml_LogRVCCMRamData_Dummy;
	Nml_LogRVCCMRamData_Dummy.chIndex            = 0xFF;
	Nml_LogRVCCMRamData_Dummy.chMode             = 0xFF;
	Nml_LogRVCCMRamData_Dummy.requestedHighMode  = 0xFF;
	Nml_LogRVCCMRamData_Dummy.detectionCnt       = 0xFF;
	Nml_LogRVCCMRamData_Dummy.aliveCycle         = 0xFFFF;
	Nml_LogRVCCMRamData_Dummy.detectionTime.hour = 0xFF;
	Nml_LogRVCCMRamData_Dummy.detectionTime.min  = 0xFF;
	Nml_LogRVCCMRamData_Dummy.detectionTime.sec  = 0xFF;
	Nml_LogRVCCMRamData_Dummy.detectionTime.ms   = 0xFF;
	return Nml_LogRVCCMRamData_Dummy;
#endif /* #if (STD_ON == NML_USE) */
}


Nml_TimeType Nml_GetEAETData(void)
{
#if (STD_ON == NML_USE)
	return Nml_LibInternalTime;
#else
	Nml_TimeType Nml_LibInternalTime_Dummy;
	Nml_LibInternalTime_Dummy.hour = 0xFF;
	Nml_LibInternalTime_Dummy.min  = 0xFF;
	Nml_LibInternalTime_Dummy.sec  = 0xFF;
	Nml_LibInternalTime_Dummy.ms   = 0xFF;
	return Nml_LibInternalTime_Dummy;
#endif /* #if (STD_ON == NML_USE) */
}

void Nml_GetLCMData(Nml_LogLCMType *LcmData)
{
#if (STD_ON == NML_USE)
	Nml_Memcpy(LcmData, & Nml_LogLCMRamData[0], (sizeof(Nml_LogLCMType) * NML_COMM_TOTAL_CHANNELS));
#else

#endif /* #if (STD_ON == NML_USE) */
}

#define NML_STOP_SEC_CODE
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
