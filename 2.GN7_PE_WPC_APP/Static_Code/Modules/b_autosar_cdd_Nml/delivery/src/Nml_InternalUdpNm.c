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
#include "Nml_InternalUdpNm.h"
#include "Nml_Log.h"

#if (STD_ON == NML_UDPNM_USED)

	#include "UdpNm_Version.h"

    #if ((UDPNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_1) || (UDPNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0))
        /* R40 
		   UdpNm v1.0.0 ~ v1.0.3 : 4.1.1 (Minor version 1)
		   UdpNm v1.0.4 ~ v1.1.0 : 4.0.1 (Minor version 0)
		   UdpNm v1.1.1 ~ As of Now      (Minor version 1)
		*/
		#include "UdpNm_Ram.h"
		#include "UdpNm_PCTypes.h"


    #elif (UDPNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_4)
		#include "UdpNm_Globals.h"
		#include "UdpNm_IntTypes.h"
    #else
        /* Other variant */
        #error "Nml only support R44 or R40"
    #endif
#endif /* #if (STD_ON == NML_UDPNM_USED) */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (STD_ON == NML_UDPNM_USED)
    #if ((UDPNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_1) || (UDPNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0))
        /* R40 */
        #define Nml_UdpNm_ArrDefaultChannel     UdpNm_GaaDefaultChannel
        #define Nml_UdpNm_Channel               UdpNm_GaaChannel
        /* Defined in UdpeNm_Cfg.h file to get total number of UdpNm chnnels */
        #define NML_UDPNM_NUMBER_OF_CHANNELS    UDPNM_NUMBER_OF_CHANNELS
		/* Defined in UdpNm_PCTypes.h file to get total number of UdpNm chnnels */
        #define NML_UDPNM_NETWORK_REQUEST           UDPNM_NETWORK_REQUEST
        #define NML_UDPNM_NETWORK_RELEASE           UDPNM_NETWORK_RELEASE

		#define NmChannelHandle				ddNmChannelHandle
		#define RepeatMessageTime          ddRepeatMsgTime
		#define TimeOutTime           	   ddNtwkTimeOutTime
		#define WaitBusSleepTime           ddWaitBusSleepTime
		#define	TxStatusBits				ucTxStatusBits
		#define ModeStatus                  ucModeStatus
		#define PrevModeStatus				ddPrevModeStatus

    #elif (UDPNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_4)
        /* R44 */
        /* Defined in UdpNm_Cfg.c file for configuration data */
        #define Nml_UdpNm_ArrDefaultChannel     UdpNm_ArrDefaultChannel
        #define Nml_UdpNm_Channel               UdpNm_ArrChannel
        /* Defined in UdpeNm_Cfg.h file to get total number of UdpNm chnnels */
        #define NML_UDPNM_NUMBER_OF_CHANNELS    UDPNM_NUMBER_OF_CHANNELS
        #define NML_UDPNM_NETWORK_REQUEST           UDPNM_NETWORK_REQUEST
        #define NML_UDPNM_NETWORK_RELEASE           UDPNM_NETWORK_RELEASE
    #else
        /* Other variant */
        #error "Nml only support R44 or R40"
    #endif
#endif /* #if (STD_ON == NML_UDPNM_USED) */


/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/

/*******************************************************************************
**                      External Global Data                                  **
*******************************************************************************/

/*******************************************************************************
**                      File Global Data                                      **
*******************************************************************************/


/*******************************************************************************
**                      Local Function Declaration                            **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == NML_UDPNM_USED)
void Nml_ChkUdpNmNormal(uint8 prmChIdx);
void Nml_ChkUdpNmReadySleep(uint8 prmChIdx);
void Nml_ChkUdpNmRepeatMsg(uint8 prmChIdx);
void Nml_ChkUdpNmPreBusSleep(uint8 prmChIdx);
void Nml_ChkUdpNmBusSleep(uint8 prmChIdx);
#endif /* #if (STD_ON == NML_UDPNM_USED) */

#define NML_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

#define NML_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
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
#if (STD_ON == NML_UDPNM_USED)
void Nml_SetUdpNmChannelData(void)
{
  #if (STD_ON == NML_USE)
    uint8 i;
    NetworkHandleType commChIndex;

    for (i=0; i<NML_UDPNM_NUMBER_OF_CHANNELS; i++)
    {
      commChIndex = Nml_UdpNm_ArrDefaultChannel[i].NmChannelHandle;
      Nml_SetUdpNmIndex(commChIndex, i);
    }
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */

#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_GetUdpNmData(void)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
{
#if (STD_ON == NML_USE)
    uint8 i;
    uint8 udpNmIndex;
    uint16 tempTime;
    uint8 tmpUdpNmModeStatus;
    uint8 tempUdpNmNwRequested;
    uint8 tmpUdpNmPrevModeStatus;

    for(i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
    {
        udpNmIndex = Nml_GetUdpNmIndex(i);
        if ((udpNmIndex != NML_UINT8_MAX) && (udpNmIndex < NML_UDPNM_NUMBER_OF_CHANNELS))
        {
            tempTime = Nml_UdpNm_Channel[udpNmIndex].RepeatMessageTime;
            Nml_SetNmRepeatMsgTime(i, tempTime);

            tempTime = Nml_UdpNm_Channel[udpNmIndex].TimeOutTime;
            Nml_SetNmTimeOutTime(i, tempTime);

            tempTime = Nml_UdpNm_Channel[udpNmIndex].WaitBusSleepTime;
            Nml_SetNmWaitBusSleeptime(i, tempTime);

            tempUdpNmNwRequested = Nml_UdpNm_Channel[udpNmIndex].TxStatusBits & NML_UDPNM_NETWORK_REQUEST;
            if(tempUdpNmNwRequested > 0)
            {
              Nml_SetNmNwRequested(i, NML_TRUE);
            }
            else
            {
              Nml_SetNmNwRequested(i, NML_FALSE);
            }

            tmpUdpNmModeStatus = (uint8)Nml_UdpNm_Channel[udpNmIndex].ModeStatus;
            Nml_SetNmModeStatus(i, tmpUdpNmModeStatus);

            tmpUdpNmPrevModeStatus = (uint8)Nml_UdpNm_Channel[udpNmIndex].PrevModeStatus;
            Nml_SetNmPrevModeStatus(i, tmpUdpNmPrevModeStatus);
        }
        else
        {

        }
    }
#endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */


#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:LEVEL [Justified:Unset] "For defensive coding and call 5 funcs according to the 5 Nm State to make easy to read code" */
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_ChkUdpNmState(void)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
/* polyspace-end CODE-METRIC:LEVEL [Justified:Unset] "For defensive coding and call 5 funcs according to the 5 Nm State to make easy to read code" */
{
  #if (STD_ON == NML_USE)
  /* Need to write this code */
	uint8 i;
	uint8 udpNmIndex;
	Nm_StateType tempCurNmState;

	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		udpNmIndex = Nml_GetUdpNmIndex(i);
		if ((udpNmIndex != NML_UINT8_MAX) && (udpNmIndex < NML_UDPNM_NUMBER_OF_CHANNELS))
		{
			tempCurNmState        = Nml_GetCurNmState(i);

			if (NM_STATE_NORMAL_OPERATION == tempCurNmState)
			{
				Nml_ChkUdpNmNormal(i);
			}
			else if (NM_STATE_READY_SLEEP == tempCurNmState)
			{
				Nml_ChkUdpNmReadySleep(i);
			}
			else if (NM_STATE_REPEAT_MESSAGE == tempCurNmState)
			{
				Nml_ChkUdpNmRepeatMsg(i);
			}
			else if (NM_STATE_PREPARE_BUS_SLEEP == tempCurNmState)
			{
				Nml_ChkUdpNmPreBusSleep(i);
			}
			else if (NM_STATE_BUS_SLEEP == tempCurNmState)
			{
				Nml_ChkUdpNmBusSleep(i);
			}
			else
			{
				/* NM_STATE_SYNCHRONIZE */
			}
		}
		else
		{

		}
	}

  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */


#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_ChkUdpNmNormal(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempUdpNmNwRequested       = 0x00;
	uint8 i =0x00;
	uint8  tmpUdpNmModeStatus    = 0x00;
	uint8  tmpUdpNmPrevModeStatus    = 0x00;
	
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempUdpNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpUdpNmModeStatus    = Nml_GetNmModeStatus(i);
	tmpUdpNmPrevModeStatus    = Nml_GetNmPrevModeStatus(i);
	/* 241004_KCLim_01 : Get PrevModeStatus to detect state transition done */
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   >  NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED) && \
		(tempUdpNmNwRequested  == NML_TRUE)                
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_UdpNormalDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime  == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempUdpNmNwRequested  == NML_FALSE)           {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_UDPNM_NW_REQED;}
		else { /* Do nothing */ }
		
		if (Nml_UdpNormalDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
            /* 241004_KCLim_02 : Compare status stablized condition - (PrevModeStatus != ModeStatus)  */
			if (tmpUdpNmPrevModeStatus != tmpUdpNmModeStatus)
			{
				/* 241004_KCLim_03 : Use Nml_UdpNormalDetectCnt variable instead of Nml_CanNormalDetectCnt(This is only for CanNm) */
				Nml_UdpNormalDetectCnt++;				
			}
			else
			{
				/* Nothing, UdpNm knows that next mode shall be changed */
			}			
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_UdpNormalDetectCnt   = NML_UINT8_MIN;
		}
		
	}
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */




#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_ChkUdpNmReadySleep(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempUdpNmNwRequested       = 0x00;
	uint8 i =0x00;
	uint8  tmpUdpNmModeStatus    = 0x00;
	uint8  tmpUdpNmPrevModeStatus    = 0x00;

	/* polyspace-begin DEFECT:ALMOST_DUPLICATED_CODE [Not a defect:Unset] "5 funcs are handled in 1 function, but detected code Metric (Maximum function called number), That's why many part of duplicated code part are made." */
	/* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempUdpNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpUdpNmModeStatus    = Nml_GetNmModeStatus(i);
	tmpUdpNmPrevModeStatus    = Nml_GetNmPrevModeStatus(i);
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   >  NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED) && \
		 (tempUdpNmNwRequested  == NML_FALSE)               
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_UdpRssDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime  == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempUdpNmNwRequested  == NML_TRUE)            {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_UDPNM_NW_REQED;}
		else { /* Do nothing */ }


		if (Nml_UdpRssDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpUdpNmPrevModeStatus != tmpUdpNmModeStatus)
			{
				Nml_UdpRssDetectCnt++;				
			}
			else
			{
				/* Nothing, UdpNm knows that next mode shall be changed */
			}	
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_UdpRssDetectCnt   = NML_UINT8_MIN;
		}
	}
	/* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	/* polyspace-end DEFECT:ALMOST_DUPLICATED_CODE [Not a defect:Unset] "5 funcs are handled in 1 function, but detected code Metric (Maximum function called number), That's why many part of duplicated code part are made." */
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */

#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_ChkUdpNmRepeatMsg(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 i =0x00;
	uint8  tmpUdpNmModeStatus    = 0x00;
	uint8  tmpUdpNmPrevModeStatus    = 0x00;
	
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tmpUdpNmModeStatus    = Nml_GetNmModeStatus(i);
	tmpUdpNmPrevModeStatus    = Nml_GetNmPrevModeStatus(i);
	
	if ( (tempRepeatMessageTime >  NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   >  NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED)  \
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_UdpRmsDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime   == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  >  NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (Nml_UdpRmsDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpUdpNmPrevModeStatus != tmpUdpNmModeStatus)
			{
				Nml_UdpRmsDetectCnt++;				
			}
			else
			{
				/* Nothing, UdpNm knows that next mode shall be changed */
			}	
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_UdpRmsDetectCnt   = NML_UINT8_MIN;
		}
	}

  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */

#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_ChkUdpNmPreBusSleep(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempUdpNmNwRequested       = 0x00;
	uint8 i =0x00;
	uint8  tmpUdpNmModeStatus    = 0x00;
	uint8  tmpUdpNmPrevModeStatus    = 0x00;
	
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempUdpNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpUdpNmModeStatus    = Nml_GetNmModeStatus(i);
	tmpUdpNmPrevModeStatus    = Nml_GetNmPrevModeStatus(i);
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   == NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  >  NML_NM_TIMER_EXPIRED) && \
		 (tempUdpNmNwRequested  == NML_FALSE)               
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_UdpPbsDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime   > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempUdpNmNwRequested  == NML_TRUE)            {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_UDPNM_NW_REQED;}
		else { /* Do nothing */ }

		if (Nml_UdpPbsDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpUdpNmPrevModeStatus != tmpUdpNmModeStatus)
			{
				Nml_UdpPbsDetectCnt++;
			}
			else
			{
				/* Nothing, UdpNm knows that next mode shall be changed */
			}	
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_UdpPbsDetectCnt   = NML_UINT8_MIN;
		}
	}
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */

#if (STD_ON == NML_UDPNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
void Nml_ChkUdpNmBusSleep(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "Including getting UdpNm variables API to make data consistency" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000; /* 2.0.5_HF1 : Remove duplicated semicolon */
	uint16 tempNtwkTimeOutTime       = 0x0000; /* 2.0.5_HF1 : Remove duplicated semicolon */
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempUdpNmNwRequested       = 0x00;   /* 2.0.5_HF1 : Remove duplicated semicolon */
	uint8 i =0x00;
	uint8  tmpUdpNmModeStatus    = 0x00;
	uint8  tmpUdpNmPrevModeStatus    = 0x00;
	
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempUdpNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpUdpNmModeStatus    = Nml_GetNmModeStatus(i);
	tmpUdpNmPrevModeStatus    = Nml_GetNmPrevModeStatus(i);
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   == NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED) && \
		 (tempUdpNmNwRequested  == NML_FALSE)               
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_UdpBusSleppDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime   > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempUdpNmNwRequested  == NML_TRUE)            {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_UDPNM_NW_REQED;}
		else { /* Do nothing */ }

		if (Nml_UdpBusSleppDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpUdpNmPrevModeStatus != tmpUdpNmModeStatus)
			{
				Nml_UdpBusSleppDetectCnt++;
			}
			else
			{
				/* Nothing, UdpNm knows that next mode shall be changed */
			}				
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_UdpBusSleppDetectCnt   = NML_UINT8_MIN;
		}
	}
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_UDPNM_USED) */


#define NML_STOP_SEC_CODE
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

