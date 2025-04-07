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
#include "Nml_InternalIf.h"
#include "Nml_Lib.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#if (STD_ON == NML_USE)

#define NML_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CpApp_xxxx                             **
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
void Nml_SetChDataRequestedHighMode(uint8 chIndex, ComM_ModeType requestedHighMode)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].requestedHighMode = requestedHighMode;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

ComM_ModeType Nml_GetChDataRequestedHighMode(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	ComM_ModeType temp=0x00;

	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].requestedHighMode;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */

	return temp;
}

void Nml_SetChDataCurComMode(uint8 chIndex, uint8 curComMode)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].curComMode = curComMode;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */

}

uint8 Nml_GetChDataCurComMode(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;

	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp=  Nml_ChannelData[chIndex].curComMode;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */

	return temp;
}

void Nml_SetChDataMappedUsrIdx(uint8 chIndex, uint8 mappedUsrIdx)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].mappedUsrIdx = mappedUsrIdx;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */

}

uint8 Nml_GetChDataMappedUsrIdx(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].mappedUsrIdx;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

void Nml_SetChDataMappedUsrCnt(uint8 chIndex, uint8 mappedUsrCnt)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].mappedUsrCnt = mappedUsrCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetChDataMappedUsrCnt(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].mappedUsrCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
void Nml_SetChDataMappedPncIdx(uint8 chIndex, uint8 mappedPncIdx)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].mappedPncIdx = mappedPncIdx;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetChDataMappedPncIdx(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].mappedPncIdx;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
void Nml_SetChDataMappedPncIdx(uint8 chIndex, uint16 mappedPncIdx)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].mappedPncIdx = mappedPncIdx;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint16 Nml_GetChDataMappedPncIdx(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint16 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].mappedPncIdx;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}
#else /* Other variant */
  #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 








#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
void Nml_SetChDataMappedPncCnt(uint8 chIndex, uint8 mappedPncCnt)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].mappedPncCnt = mappedPncCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetChDataMappedPncCnt(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].mappedPncCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
void Nml_SetChDataMappedPncCnt(uint8 chIndex, uint16 mappedPncCnt)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].mappedPncCnt = mappedPncCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint16 Nml_GetChDataMappedPncCnt(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint16 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].mappedPncCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

#else /* Other variant */
    #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 



void Nml_SetChDataTargetElapsedCnt(uint8 chIndex, uint16 targetElapsedCnt)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].targetElapsedCnt = targetElapsedCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint16 Nml_GetChDataTargetElapsedCnt(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint16 temp = 0x0000;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].targetElapsedCnt;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

void Nml_SetChDataIsPncCh(uint8 chIndex, boolean isPncCh)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].isPncCh = isPncCh;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

boolean Nml_GetChDataIsPncCh(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	boolean temp = NML_FALSE;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].isPncCh;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

void Nml_SetChDataIsComModeMatched(uint8 chIndex, boolean isReqVsCurComModeMatched)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

	Nml_ChannelData[chIndex].isReqVsCurComModeMatched = isReqVsCurComModeMatched;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

boolean Nml_GetChDataIsComModeMatched(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	boolean temp = NML_FALSE;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].isReqVsCurComModeMatched;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}



Nm_StateType Nml_GetPrevNmState(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	Nm_StateType tempState = NM_STATE_UNINIT;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		tempState = Nml_ChannelData[chIndex].prevNmState;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return tempState;

}

void Nml_SetNmState(uint8 chIndex, Nm_StateType nmState)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		if (Nml_ChannelData[chIndex].curNmState != nmState)
		{
			Nml_ChannelData[chIndex].prevNmState = Nml_ChannelData[chIndex].curNmState;
			Nml_ChannelData[chIndex].curNmState  = nmState;
		}
		else
		{

		}

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

Nm_StateType Nml_GetCurNmState(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	Nm_StateType tempState = NM_STATE_UNINIT;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		tempState = Nml_ChannelData[chIndex].curNmState;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return tempState;
}




void Nml_SetCanNmIndex(uint8 chIndex, uint8 canNmIndex)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].canNmIndex  = (uint8) canNmIndex;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetCanNmIndex(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00; /* 2.0.5_HF1 : Remove duplicated semicolon */
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].canNmIndex;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}


/* polyspace-begin CODE-METRIC:CALLING [Justified:Unset] "Kind of library function, Total 10 funcs are called this function for CanNm 5 state and UdpNm 5 state, If making separate func, there will be duplicated" */
void Nml_SetNmStateMatched(uint8 chIndex, uint8 NmStateMatched)
/* polyspace-end CODE-METRIC:CALLING [Justified:Unset] "Kind of library function, Total 10 funcs are called this function for CanNm 5 state and UdpNm 5 state, If making separate func, there will be duplicated" */
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].NmStateMatched  = NmStateMatched;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetNmStateMatched(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00; /* 2.0.5_HF1 : Remove duplicated semicolon */
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].NmStateMatched;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}




void Nml_SetNmRepeatMsgTime(uint8 chIndex, uint16 repeatMsgTime)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].repeatMsgTime  = repeatMsgTime;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}
/* polyspace-begin CODE-METRIC:CALLING [Justified:Low] "This is a kind of library function" */
uint16 Nml_GetNmRepeatMsgTime(uint8 chIndex)
/* polyspace-end CODE-METRIC:CALLING [Justified:Low] "This is a kind of library function" */
{
#if (NML_DET == STD_ON)
	uint16 temp = 0x00; /* 2.0.5_HF1 : Remove duplicated semicolon */
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].repeatMsgTime;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */

	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}


void Nml_SetNmTimeOutTime(uint8 chIndex, uint16 nmTimeOutTime)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].nmTimeOutTime  = nmTimeOutTime;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}
/* polyspace-begin CODE-METRIC:CALLING [Justified:Low] "This is a kind of library function" */
uint16 Nml_GetNmTimeOutTime(uint8 chIndex)
/* polyspace-end CODE-METRIC:CALLING [Justified:Low] "This is a kind of library function" */
{
#if (NML_DET == STD_ON)
	uint16 temp = 0x00; /* 2.0.5_HF1 : Remove duplicated semicolon */
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].nmTimeOutTime;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

void Nml_SetNmWaitBusSleeptime(uint8 chIndex, uint16 waitBusSleeptime)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].waitBusSleeptime  = waitBusSleeptime;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

/* polyspace-begin CODE-METRIC:CALLING [Justified:Low] "To make code easy to read and to maintain" */
uint16 Nml_GetNmWaitBusSleeptime(uint8 chIndex)
/* polyspace-end CODE-METRIC:CALLING [Justified:Low] "To make code easy to read and to maintain" */
{
#if (NML_DET == STD_ON)
	uint16 temp = 0x00; /* 2.0.5_HF1 : Remove duplicated semicolon */
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].waitBusSleeptime;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}


void Nml_SetNmNwRequested(uint8 chIndex, boolean nmNwRequested)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].nmNwRequested  = nmNwRequested;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}


boolean Nml_GetNmNwRequested(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	boolean temp = NML_FALSE;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].nmNwRequested;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}


void Nml_SetNmModeStatus(uint8 chIndex, uint8 nmModeStatus)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].nmModeStatus  = nmModeStatus;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

/* polyspace-begin CODE-METRIC:CALLING [Justified:Unset] "Kind of library function, Total 10 funcs are called this function for CanNm 5 state and UdpNm 5 state, If making separate func, there will be duplicated" */
uint8 Nml_GetNmModeStatus(uint8 chIndex)
/* polyspace-end CODE-METRIC:CALLING [Justified:Unset] "Kind of library function, Total 10 funcs are called this function for CanNm 5 state and UdpNm 5 state, If making separate func, there will be duplicated" */
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].nmModeStatus;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

void Nml_SetNmNextModeState(uint8 chIndex, uint8 nmNextModeState)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].nmNextModeState  = nmNextModeState;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetNmNextModeState(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].nmNextModeState;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}

void Nml_SetNmPrevModeStatus(uint8 chIndex, uint8 nmPrevModeStatus)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].nmPrevModeStatus  = nmPrevModeStatus;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetNmPrevModeStatus(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00;
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].nmPrevModeStatus;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}


void Nml_SetUdpNmIndex(uint8 chIndex, uint8 udpNmIndex)
{
#if (NML_DET == STD_ON)
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		Nml_ChannelData[chIndex].udpNmIndex  = (uint8)udpNmIndex;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
}

uint8 Nml_GetUdpNmIndex(uint8 chIndex)
{
#if (NML_DET == STD_ON)
	uint8 temp = 0x00; /* 2.0.5_HF1 : Remove duplicated semicolon */
	Nml_ChkIndexRangeOver(chIndex, NML_COMM_TOTAL_CHANNELS, NML_INTERNAL_INTERFACES);

	if (0x00 == Nml_Error.doNotRun)
	{
#endif /* #if (NML_DET == STD_ON) */

		temp = Nml_ChannelData[chIndex].udpNmIndex;

#if (NML_DET == STD_ON)
	}
	else
	{
		/* Do nothing if index is over the array range */
	}
#endif /* #if (NML_DET == STD_ON) */
	return temp;
}






#define NML_STOP_SEC_CODE
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#endif /* #if (STD_ON == NML_USE) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
