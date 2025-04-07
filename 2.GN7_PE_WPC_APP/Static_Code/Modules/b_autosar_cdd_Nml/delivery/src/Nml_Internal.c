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
#include "Nml_Internal.h"
#include "Nml_Log.h"
#include "Nm.h"
#include "Nml_InternalUdpNm.h"

#if (STD_ON == NML_DEBUG)
	#include "Nml_Test.h"
#endif /*#if (STD_ON == NML_DEBUG)*/

#if (STD_ON == NML_CANNM_USED)
        /* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "Polyspace wrong-detection - If not included, CANNM_VERSION_AR_RELEASE_MINOR_VERSION cannot referred, it makes compile error" */
	#include "CanNm_Version.h" /*Jira - [NML-2] R44/R40 Compile Macro */
        /* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "Polyspace wrong-detection - If not included, CANNM_VERSION_AR_RELEASE_MINOR_VERSION cannot referred, it makes compile error" */
	#include "CanNm_Cfg.h" /* If it is included in Nml_Cfg.h file, there is compile error */
	#if (CANNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0) /* if R40 */
		#include "CanNm_Ram.h"
	#elif (CANNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_4)  /* if R44 */
		#include "CanNm_Globals.h"
	#else /* Other variant */
		#error "No CanNm Module R44 or R40"
	#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */
#endif /* #if (STD_ON == NML_CANNM_USED) */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (STD_ON == NML_CANNM_USED)
	#if (CANNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_0) /* if R40 */
		#define Nml_GaaCanNmChannels         CanNm_GaaChannel
		#define Nml_GaaCanNmStaticChannel    CanNm_GaaStaticChannel
		#define NML_CANNM_NUMBER_OF_CHANNELS CANNM_NUMBER_OF_CHANNELS
	#elif (CANNM_VERSION_AR_RELEASE_MINOR_VERSION == NML_REQUIRED_AR_RELEASE_MINOR_VERSION_4)  /* if R44 */
		#define Nml_GaaCanNmChannels         CanNm_ArrayChannel        /* [NML-5] change member variable name */
		#define Nml_GaaCanNmStaticChannel    CanNm_ArrayStaticChannel  /* [NML-5] change member variable name */
		#define NML_CANNM_NUMBER_OF_CHANNELS CANNM_NUMBER_OF_CHANNEL   /* [NML-5] change member variable name */
		#define ddRepeatMessageTime          repeatMessageTime         /* [NML-5] change member variable name */
		#define ddNtwkTimeOutTime            ntwkTimeOutTime           /* [NML-5] change member variable name */
		#define ddWaitBusSleepTime           waitBusSleepTime          /* [NML-5] change member variable name */
		#define blNetworkRequested           networkRequested          /* [NML-5] change member variable name */
		#define ddModeStatus                 modeStatus
		#define ddNextModeState              nextModeState
	#else /* Other variant */
		#error "No CanNm Module R44 or R40"
	#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */
#endif /* #if (STD_ON == NML_CANNM_USED) */


#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */


#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
    #define ucChannelUserIndex                 ChannelUserIndex         /* [NML-5] change member variable name */
	#define ucChannelUserCount                 ChannelUserCount         /* [NML-5] change member variable name */
	#define ucPncIndex                         PncIndex                 /* [NML-5] change member variable name */
	#define ucPncCount                         PncCount                 /* [NML-5] change member variable name */
	#define blChannelPnc                       ChannelPnc               /* [NML-5] change member variable name */

	#define ucUserCount                       UserCount               /* [NML-5] change member variable name */
	#define ucUserIndex                       UserIndex               /* [NML-5] change member variable name */
	#define ddNmChannelHandle                 comMChannelId               /* [NML-5] change member variable name */
	
#else /* Other variant */
	#error "No ComM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */




/*******************************************************************************
**                      External Global Data                                  **
*******************************************************************************/

#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


#define NML_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


#define NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
**                      File Global Data                                      **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define NML_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
/*******************************************************************************
**                      Local Function Declaration                            **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

void Nml_IsUpdatedReqOrCurComMode(void);
void Nml_SetChannelData(void);
void Nml_UpdateComModeInfo(void);
void Nml_ChkReqVsCurComMode(void);
void Nml_InitGlobalVariables(void);
void Nml_GetNmState(void);

#if (STD_ON == NML_CANNM_USED)
void Nml_GetCanNmData(void);
void Nml_ChkCanNmState(void);
void Nml_ChkCanNmNormal(uint8 prmChIdx);
void Nml_ChkCanNmReadySleep(uint8 prmChIdx);
void Nml_ChkCanNmRepeatMsg(uint8 prmChIdx);
void Nml_ChkCanNmPreBusSleep(uint8 prmChIdx);
void Nml_ChkCanNmBusSleep(uint8 prmChIdx);
#endif /* #if (STD_ON == NML_CANNM_USED) */


#define NML_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
void Nml_IsUpdatedReqOrCurComMode(void)
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
{
#if (STD_ON == NML_USE)
	uint8 i = 0x00;
	Nm_StateType tempCurNmState = NM_STATE_UNINIT;
	Nm_StateType tempPrevNmState = NM_STATE_UNINIT;


	/* 01 : Get requested comMode per User and cur comMode per channel then check whether is data changed */
	for (i=0; i<NML_COMM_TOTAL_USERS; i++)
	{
		if (Nml_RequestedComMode[i] != Nml_GaaRequestedComMode[i])
		{
			Nml_RequestedComMode[i] = Nml_GaaRequestedComMode[i];
		}
		else
		{

		}
	}

	/* 01 : Get current comMode per channels */
	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		tempCurNmState  = Nml_GetCurNmState(i);
		tempPrevNmState = Nml_GetPrevNmState(i);
		/* 240927_KCLim - Change type from Nm_StateType to uint8 for Tasking compiler, to prevent 4 byte align */
		if ((Nml_CurComMode[i] != Nml_GaaCurComMode[i]) || (Nml_LogLCMRamData[i].curNmState != (uint8)tempCurNmState) || (Nml_LogLCMRamData[i].prevNmState != (uint8)tempPrevNmState))
		{
			if (Nml_CurComMode[i] != Nml_GaaCurComMode[i])
			{
				/* Increase mode change counter if only mode changed */
				Nml_CurComMode[i]          = Nml_GaaCurComMode[i];
				Nml_CurComModeChangeCnt[i] = Nml_CurComModeChangeCnt[i] + 1;
			}
			else
			{
				/* do nothing : Mode is same, only state change */
			}
			Nml_LogFuncLCM(i);
		}
		else
		{

		}
	}
#endif /* #if (STD_ON == NML_USE) */
}


/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
void Nml_SetChannelData(void)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
#if (STD_ON == NML_USE)
	uint8 i = 0x00;
	uint8         mappedUsrIdx;
	uint8         mappedUsrCnt;
    #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
	uint8         mappedPncIdx; /*230518_KCLim : This variable only for PNC configuration enabled */
	uint8         mappedPncCnt; /*230518_KCLim : This variable only for PNC configuration enabled */
	#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
	uint16        mappedPncIdx; /*230518_KCLim : This variable only for PNC configuration enabled */
	uint16        mappedPncCnt; /*230518_KCLim : This variable only for PNC configuration enabled */
    #else /* Other variant */
      #error "No NvM Module R44 or R40"
    #endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 
	boolean       isPncCh;      /*230518_KCLim : This variable only for PNC configuration enabled */
#if ( (STD_ON == NML_CANNM_USED) || (STD_ON == NML_UDPNM_USED) )
	uint8 commChIndex;
#endif /* #if ( (STD_ON == NML_CANNM_USED) || (STD_ON == NML_UDPNM_USED) ) */


	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
#if ((STD_ON == NML_PNC_ON) && (STD_ON == NML_CAN_FR_ETH_ON))
		/* Set isPncCh */
		isPncCh = Nml_GaaChannels[i].blChannelPnc;
		Nml_SetChDataIsPncCh(i, isPncCh);

		/* polyspace-begin DEFECT:DEAD_CODE [Not a defect:Unset] "In side ComM_GaaChannels array, the value blChannelPnc could be 1 or 0 accoridng to the user configuration" */
		/* polyspace-begin MISRA-C3:2.1 [Not a defect:Unset] "In side ComM_GaaChannels array, the value blChannelPnc could be 1 or 0 accoridng to the user configuration" */
		/* polyspace-begin MISRA-C3:14.3 [Not a defect:Unset] "In side ComM_GaaChannels array, the value blChannelPnc could be 1 or 0 accoridng to the user configuration" */
		if (NML_TRUE == isPncCh)
		/* polyspace-end MISRA-C3:14.3 [Not a defect:Unset] "In side ComM_GaaChannels array, the value blChannelPnc could be 1 or 0 accoridng to the user configuration" */
		/* polyspace-end MISRA-C3:2.1 [Not a defect:Unset] "In side ComM_GaaChannels array, the value blChannelPnc could be 1 or 0 accoridng to the user configuration" */
		/* polyspace-end DEFECT:DEAD_CODE [Not a defect:Unset] "In side ComM_GaaChannels array, the value blChannelPnc could be 1 or 0 accoridng to the user configuration" */
		{
			if (Nml_GaaChannels[i].ucPncCount > 0)
			{
				/* Set mappedPncCnt */
				mappedPncCnt = Nml_GaaChannels[i].ucPncCount;
				Nml_SetChDataMappedPncCnt(i, mappedPncCnt);
				/* Set mappedPncIdx */
				mappedPncIdx = Nml_GaaChannels[i].ucPncIndex;
				Nml_SetChDataMappedPncIdx(i, mappedPncIdx);
			}
			else
			{
				/* This is not expected case */
			}
		}
	#if (STD_ON == NML_DIRECT_CHANNEL_ON)
		else
		{
			if (Nml_GaaChannels[i].ucChannelUserCount > 0)
			{
				/* Set mappedUsrCnt */
				mappedUsrCnt = Nml_GaaChannels[i].ucChannelUserCount;
				Nml_SetChDataMappedUsrCnt(i, mappedUsrCnt);

				/* Set mappedUsrIdx */
				mappedUsrIdx = Nml_GaaChannels[i].ucChannelUserIndex;
				Nml_SetChDataMappedUsrIdx(i, mappedUsrIdx);
			}
			else
			{
				/* This is not expected case */
			}
		}
	#endif /* #if (STD_ON == NML_DIRECT_CHANNEL_ON) */
#endif /* #if ((STD_ON == NML_PNC_ON) || (STD_ON == NML_CAN_FR_ETH_ON)) */


#if (STD_OFF == NML_PNC_ON)
		if (Nml_GaaChannels[i].ucChannelUserCount > 0)
		{
			/* Set mappedUsrCnt */
			mappedUsrCnt = Nml_GaaChannels[i].ucChannelUserCount;
			Nml_SetChDataMappedUsrCnt(i, mappedUsrCnt);

			/* Set mappedUsrIdx */
			mappedUsrIdx = Nml_GaaChannels[i].ucChannelUserIndex;
			Nml_SetChDataMappedUsrIdx(i, mappedUsrIdx);
		}
		else
		{
			/* This is not expected case */
		}
#endif /* #if (STD_OFF == NML_PNC_ON) */
	}

	#if (STD_ON == NML_CANNM_USED)
		for (i=0; i<NML_CANNM_NUMBER_OF_CHANNELS; i++)
		{
			commChIndex = Nml_GaaCanNmStaticChannel[i].ddNmChannelHandle;
			Nml_SetCanNmIndex(commChIndex, i);
		}
	#endif /* #if (STD_ON == NML_CANNM_USED) */

	#if (STD_ON == NML_UDPNM_USED)
		Nml_SetUdpNmChannelData();
	#endif /* #if (STD_ON == NML_CANNM_USED) */



	/* KCLim_2nd_Dev : mapping OsekNm, UdpNm*/

#endif /* #if (STD_ON == NML_USE) */
}
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_UpdateComModeInfo(void)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
#if (STD_ON == NML_USE)
	uint8 i = 0x00;

	uint8         mappedUsrIdx;
	uint8         mappedUsrCnt;
	uint8         userId;
	uint8         userIdx;
	ComM_ModeType tempComMode = NML_COMMODE_NO_COM;
	ComM_ModeType requestedHighComMode = NML_COMMODE_NO_COM;
	uint8         curComMode = NML_COMMODE_NO_COM;
	boolean       isPncCh;  /*230518_KCLim : This variable only for PNC configuration enabled */
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */	
	uint8         pncUsrCntForChannelToPncMapping; /*230518_KCLim : This variable only for PNC configuration enabled */
	uint8         pncUsrIdxForChannelToPncMapping; /*230518_KCLim : This variable only for PNC configuration enabled */
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
	uint16        pncUsrCntForChannelToPncMapping; /*230518_KCLim : This variable only for PNC configuration enabled */
	uint16        pncUsrIdxForChannelToPncMapping; /*230518_KCLim : This variable only for PNC configuration enabled */
#else /* Other variant */
  #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 

	uint8         pncUsrCntForGaaPncs; /*230518_KCLim : This variable only for PNC configuration enabled */
/*[NML-2] R40 uint8, R44 - uint16 */
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
	uint8         pncUsrIdxForGaaPncs; /*230518_KCLim : This variable only for PNC configuration enabled */
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
    uint16        pncUsrIdxForGaaPncs; /*230518_KCLim : This variable only for PNC configuration enabled */
#else /* Other variant */
  #error "No NvM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 



	uint8         pncUsrIdxForPncToUserMapping; /*230518_KCLim : This variable only for PNC configuration enabled */

	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{

		requestedHighComMode = NML_COMMODE_NO_COM;
#if ((STD_ON == NML_PNC_ON) && (STD_ON == NML_CAN_FR_ETH_ON))

		isPncCh = Nml_GetChDataIsPncCh(i);

		 /* If the Channel is associated  with a PNC: PNC Channel */
		if (NML_TRUE == isPncCh)
		{
			pncUsrCntForChannelToPncMapping = Nml_GetChDataMappedPncCnt(i);

			pncUsrIdxForChannelToPncMapping = Nml_GetChDataMappedPncIdx(i);

			
			while (NML_ZERO != pncUsrCntForChannelToPncMapping)
			{
				pncUsrIdxForGaaPncs = Nml_GaaChannelToPncMapping[pncUsrIdxForChannelToPncMapping];
				pncUsrCntForChannelToPncMapping--;
				pncUsrCntForGaaPncs = Nml_GaaPncs[pncUsrIdxForGaaPncs].ucUserCount;
				pncUsrIdxForPncToUserMapping = Nml_GaaPncs[pncUsrIdxForGaaPncs].ucUserIndex;
				while (NML_ZERO !=  pncUsrCntForGaaPncs)
				{
					pncUsrCntForGaaPncs--;

					userId = Nml_GaaPncToUserMapping[pncUsrIdxForPncToUserMapping];

					#if (COMM_USER_SEQUENTIAL == STD_OFF)
					userIdx = ComM_GaaUserMapArray[userId];
					#else
					userIdx = userId;
					#endif

					tempComMode = Nml_RequestedComMode[userIdx];
#if (STD_ON == NML_DEBUG)
					Nml_DebugSetUsrIdPerCh(i, userIdx);
#endif /*#if (STD_ON == NML_DEBUG)*/
					if (NML_COMMODE_NO_COM != tempComMode)
					{
						requestedHighComMode = tempComMode;
					}
					else
					{

					}
					pncUsrIdxForPncToUserMapping++;
				}
				pncUsrIdxForChannelToPncMapping++;
			}

			/* Set requestedHighMode */
			Nml_SetChDataRequestedHighMode(i, requestedHighComMode);

			/* Set curComMode */
			curComMode = Nml_CurComMode[i];
			Nml_SetChDataCurComMode(i, curComMode);

		} /* if (NML_TRUE == isPncCh) */ /* polyspace MISRA-C3:D4.4 [Justified:Low] "For readability of brace end" */
		#if (NML_DIRECT_CHANNEL_ON == STD_ON)
		/* Note: PNC is Enabled but, Channel is not part of PNC: Direct Channel */
		else
		{
			mappedUsrCnt = Nml_GetChDataMappedUsrCnt(i);

			mappedUsrIdx = Nml_GetChDataMappedUsrIdx(i);

			while (NML_ZERO != mappedUsrCnt)
			{
				mappedUsrCnt--;
				userId = Nml_GaaChannelToUserMapping[mappedUsrIdx];

				#if (COMM_USER_SEQUENTIAL == STD_OFF)
				userIdx = ComM_GaaUserMapArray[userId];
				#else /* if COMM_USER_SEQUENTIAL == OFF */
				/* Load the user in user index */
				userIdx = userId;
				#endif

				tempComMode = Nml_RequestedComMode[userIdx];
#if (STD_ON == NML_DEBUG)
					Nml_DebugSetUsrIdPerCh(i, userIdx);
#endif /*#if (STD_ON == NML_DEBUG)*/
				if (NML_COMMODE_NO_COM != tempComMode)
				{
					requestedHighComMode = tempComMode;
				}
				else
				{

				}
				mappedUsrIdx++;
			}
			/* Set requestedHighMode */
			Nml_SetChDataRequestedHighMode(i, requestedHighComMode);

			/* Set curComMode */
			curComMode = Nml_CurComMode[i];
			Nml_SetChDataCurComMode(i, curComMode);
		}
		#endif /* #if (NML_DIRECT_CHANNEL_ON == STD_ON) */
#endif /*#if ((STD_ON == NML_PNC_ON) || (STD_ON == NML_CAN_FR_ETH_ON)) */


#if (STD_OFF == NML_PNC_ON)
		mappedUsrCnt = Nml_GetChDataMappedUsrCnt(i);
		mappedUsrIdx = Nml_GetChDataMappedUsrIdx(i);

		while (mappedUsrCnt != NML_ZERO)
		{
			userId = Nml_GaaChannelToUserMapping[mappedUsrIdx];

			mappedUsrCnt--;

			#if (COMM_USER_SEQUENTIAL == STD_OFF)
			userIdx = ComM_GaaUserMapArray[userId];
			#else /* if COMM_USER_SEQUENTIAL == OFF */
			/* Load the user in user index */
			userIdx = userId;
			#endif

			tempComMode = Nml_RequestedComMode[userIdx];
#if (STD_ON == NML_DEBUG)
					Nml_DebugSetUsrIdPerCh(i, userIdx);
#endif /*#if (STD_ON == NML_DEBUG)*/
			if (NML_COMMODE_NO_COM != tempComMode)
			{
				requestedHighComMode = tempComMode;
			}
			else
			{

			}
			mappedUsrIdx++;
		}

		/* Set requestedHighMode */
		Nml_SetChDataRequestedHighMode(i, requestedHighComMode);

		/* Set curComMode */
		curComMode = Nml_CurComMode[i];
		Nml_SetChDataCurComMode(i, curComMode);

#endif /* #if (STD_OFF == NML_PNC_ON) */

	} /* for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++) */ /* polyspace MISRA-C3:D4.4 [Justified:Low] "For readability of brace end" */
#endif /* #if (STD_ON == NML_USE) */
}

void Nml_ChkReqVsCurComMode(void)
{
#if (STD_ON == NML_USE)
	uint8 i = 0x00;
	ComM_ModeType requestedHighComMode = NML_COMMODE_NO_COM;
	uint8         curComMode = NML_COMMODE_NO_COM;


	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		requestedHighComMode = Nml_GetChDataRequestedHighMode(i);
		curComMode = Nml_GetChDataCurComMode(i);

		if (requestedHighComMode == curComMode)
		{
			Nml_SetChDataIsComModeMatched(i, NML_TRUE);
		}
		else
		{
			Nml_SetChDataIsComModeMatched(i, NML_FALSE);
		}
	}
#endif /* #if (STD_ON == NML_USE) */
}

#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
void Nml_GetCanNmData(void)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
{
#if (STD_ON == NML_USE)
	uint8 i;
	uint8 canNmIndex;
	uint8 tempCanNmNwRequested;
	uint16 tempTime;
	uint8 tmpCanNmModeStatus;
	uint8 tmpCanNmNextModeState;


	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		canNmIndex = Nml_GetCanNmIndex(i);
		if ((canNmIndex != NML_UINT8_MAX) && (canNmIndex < NML_CANNM_NUMBER_OF_CHANNELS))
		{
			tempTime = Nml_GaaCanNmChannels[canNmIndex].ddRepeatMessageTime;
			Nml_SetNmRepeatMsgTime(i, tempTime);
			tempTime = Nml_GaaCanNmChannels[canNmIndex].ddNtwkTimeOutTime;
			Nml_SetNmTimeOutTime(i, tempTime);
			tempTime = Nml_GaaCanNmChannels[canNmIndex].ddWaitBusSleepTime;
			Nml_SetNmWaitBusSleeptime(i, tempTime);
			tempCanNmNwRequested = Nml_GaaCanNmChannels[canNmIndex].blNetworkRequested;
			Nml_SetNmNwRequested(i, tempCanNmNwRequested);			
			tmpCanNmModeStatus = (uint8)Nml_GaaCanNmChannels[canNmIndex].ddModeStatus;
			Nml_SetNmModeStatus(i, tmpCanNmModeStatus);			
			tmpCanNmNextModeState = (uint8)Nml_GaaCanNmChannels[canNmIndex].ddNextModeState;
			Nml_SetNmNextModeState(i, tmpCanNmNextModeState);
		}
		else
		{

		}
	}
#endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */


#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read, this implementation is according to the number of CanNm state and pre-required function call." */
/* polyspace-begin CODE-METRIC:LEVEL [Justified:Low] "To make code easy to read, this implementation is according to the number of CanNm state and pre-required function call." */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_ChkCanNmState(void)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read, this implementation is according to the number of CanNm state and pre-required function call." */
/* polyspace-end CODE-METRIC:LEVEL [Justified:Low] "To make code easy to read, this implementation is according to the number of CanNm state and pre-required function call." */
{
#if (STD_ON == NML_USE)
	uint8 i;          /* Index to access NML and ComM Array */
	uint8 canNmIndex; /* Index to access CanNm Array */
	Nm_StateType tempCurNmState;


	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		canNmIndex = Nml_GetCanNmIndex(i);

		/* If NML/COMM channel's canNmIndex value is below means this channel is CanNm */
		if ((canNmIndex != NML_UINT8_MAX) && (canNmIndex < NML_CANNM_NUMBER_OF_CHANNELS))
		{
			tempCurNmState        = Nml_GetCurNmState(i);

			if (NM_STATE_NORMAL_OPERATION == tempCurNmState)
			{
				Nml_ChkCanNmNormal(i);
			}
			else if (NM_STATE_READY_SLEEP == tempCurNmState)
			{
				Nml_ChkCanNmReadySleep(i);
			}
			else if (NM_STATE_REPEAT_MESSAGE == tempCurNmState)
			{
				Nml_ChkCanNmRepeatMsg(i);
			}
			else if (NM_STATE_PREPARE_BUS_SLEEP == tempCurNmState)
			{
				Nml_ChkCanNmPreBusSleep(i);
			}
			else if (NM_STATE_BUS_SLEEP == tempCurNmState)
			{
				Nml_ChkCanNmBusSleep(i);
			}
			else
			{
				/* NM_STATE_SYNCHRONIZE */
			}
		}
		else
		{
			/* It's not CanNm channel, Do nothing  */
		}
	}
#endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */


#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_ChkCanNmNormal(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempCanNmNwRequested       = 0x00;
	uint8 i =0x00;
	uint8  tmpCanNmModeStatus    = 0x00;
	uint8  tmpCanNmNextModeState = 0x00;
  /* polyspace-begin DEFECT:ALMOST_DUPLICATED_CODE [Not a defect:Unset] "5 funcs are handled in 1 function, but detected code Metric (Maximum function called number), That's why many part of duplicated code part are made." */	
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempCanNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpCanNmModeStatus    = Nml_GetNmModeStatus(i);
    tmpCanNmNextModeState = Nml_GetNmNextModeState(i);
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   >  NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED) && \
		 (tempCanNmNwRequested  == NML_TRUE)                \
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_CanNormalDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
	        /* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime  == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempCanNmNwRequested  == NML_FALSE)           {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_CANNM_NW_REQED;}
		else { /* Do nothing */ }
                /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */		
		if (Nml_CanNormalDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpCanNmModeStatus == tmpCanNmNextModeState)
			{
				Nml_CanNormalDetectCnt++;				
			}
			else
			{
				/* Nothing, CanNm knows that next mode shall be changed */
			}			
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_CanNormalDetectCnt   = NML_UINT8_MIN;
		}
		
	}
  /* polyspace-end DEFECT:ALMOST_DUPLICATED_CODE [Not a defect:Unset] "5 funcs are handled in 1 function, but detected code Metric (Maximum function called number), That's why many part of duplicated code part are made." */    
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */




#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_ChkCanNmReadySleep(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempCanNmNwRequested       = 0x00;
	uint8 i =0x00;
	uint8  tmpCanNmModeStatus    = 0x00;
	uint8  tmpCanNmNextModeState = 0x00;
	/* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempCanNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpCanNmModeStatus    = Nml_GetNmModeStatus(i);
    tmpCanNmNextModeState = Nml_GetNmNextModeState(i);	
	/* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   >  NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED) && \
		 (tempCanNmNwRequested  == NML_FALSE)               \
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_CanRssDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
	        /* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime  == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempCanNmNwRequested  == NML_TRUE)            {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_CANNM_NW_REQED;}
		else { /* Do nothing */ }
                /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */

		if (Nml_CanRssDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpCanNmModeStatus == tmpCanNmNextModeState)
			{
				Nml_CanRssDetectCnt++;				
			}
			else
			{
				/* Nothing, CanNm knows that next mode shall be changed */
			}	
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_CanRssDetectCnt   = NML_UINT8_MIN;
		}
	}

  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */

#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:CALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
void Nml_ChkCanNmRepeatMsg(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:CALLS [Justified:Unset] "To get CanNm data at once for data consistency" */
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 i =0x00;
	uint8  tmpCanNmModeStatus    = 0x00;
	uint8  tmpCanNmNextModeState = 0x00;	
	
	/* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tmpCanNmModeStatus    = Nml_GetNmModeStatus(i);
    tmpCanNmNextModeState = Nml_GetNmNextModeState(i);
        /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	
	if ( (tempRepeatMessageTime >  NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   >  NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED)  \
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_CanRmsDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
	        /* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime   == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  >  NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }
                /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		if (Nml_CanRmsDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpCanNmModeStatus == tmpCanNmNextModeState)
			{
				Nml_CanRmsDetectCnt++;				
			}
			else
			{
				/* Nothing, CanNm knows that next mode shall be changed */
			}	
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_CanRmsDetectCnt   = NML_UINT8_MIN;
		}
	}

  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */

#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_ChkCanNmPreBusSleep(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000;
	uint16 tempNtwkTimeOutTime       = 0x0000;
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempCanNmNwRequested       = 0x00;
	uint8 i =0x00;
	uint8  tmpCanNmModeStatus    = 0x00;
	uint8  tmpCanNmNextModeState = 0x00;	
	
	/* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempCanNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpCanNmModeStatus    = Nml_GetNmModeStatus(i);
    tmpCanNmNextModeState = Nml_GetNmNextModeState(i);
        /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   == NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  >  NML_NM_TIMER_EXPIRED) && \
		 (tempCanNmNwRequested  == NML_FALSE)               \
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_CanPbsDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
	        /* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime   > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime == NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempCanNmNwRequested  == NML_TRUE)            {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_CANNM_NW_REQED;}
		else { /* Do nothing */ }
                /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		if (Nml_CanPbsDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpCanNmModeStatus == tmpCanNmNextModeState)
			{
				Nml_CanPbsDetectCnt++;
			}
			else
			{
				/* Nothing, CanNm knows that next mode shall be changed */
			}	
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_CanPbsDetectCnt   = NML_UINT8_MIN;
		}
	}
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */

#if (STD_ON == NML_CANNM_USED)
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_ChkCanNmBusSleep(uint8 prmChIdx)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:VG [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "To make code easy to read and to maintain" */
{
  #if (STD_ON == NML_USE)
	uint8 tempNmStateNotMatchedReason = 0x00;
	uint16 tempRepeatMessageTime     = 0x0000; /* 2.0.5_HF1 : Remove duplicated semicolon */
	uint16 tempNtwkTimeOutTime       = 0x0000; /* 2.0.5_HF1 : Remove duplicated semicolon */
	uint16 tempWaitBusSleepTime      = 0x0000;
	uint8 tempCanNmNwRequested       = 0x00;   /* 2.0.5_HF1 : Remove duplicated semicolon */
	uint8 i =0x00;
	uint8  tmpCanNmModeStatus    = 0x00;
	uint8  tmpCanNmNextModeState = 0x00;	
	
	/* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	i = prmChIdx;
	tempRepeatMessageTime = Nml_GetNmRepeatMsgTime(i);
	tempNtwkTimeOutTime   = Nml_GetNmTimeOutTime(i);
	tempWaitBusSleepTime  = Nml_GetNmWaitBusSleeptime(i);
	tempCanNmNwRequested  = Nml_GetNmNwRequested(i);
	tmpCanNmModeStatus    = Nml_GetNmModeStatus(i);
    tmpCanNmNextModeState = Nml_GetNmNextModeState(i);
        /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
	
	if ( (tempRepeatMessageTime == NML_NM_TIMER_EXPIRED) && \
		 (tempNtwkTimeOutTime   == NML_NM_TIMER_EXPIRED) && \
		 (tempWaitBusSleepTime  == NML_NM_TIMER_EXPIRED) && \
		 (tempCanNmNwRequested  == NML_FALSE)               \
	)
	{
		Nml_SetNmStateMatched(i, NML_TRUE);
		Nml_CanBusSleppDetectCnt   = NML_UINT8_MIN;
	}
	else
	{
	        /* polyspace-begin DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		Nml_SetNmStateMatched(i, NML_FALSE);
		if (tempRepeatMessageTime > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_RMTIME;}
		else { /* Do nothing */ }

		if (tempNtwkTimeOutTime   > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_NWTIME;}
		else { /* Do nothing */ }

		if (tempWaitBusSleepTime  > NML_NM_TIMER_EXPIRED) {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_WBSTIME;}
		else { /* Do nothing */ }

		if (tempCanNmNwRequested  == NML_TRUE)            {tempNmStateNotMatchedReason |= NML_NM_NOT_MATCHED_CANNM_NW_REQED;}
		else { /* Do nothing */ }
                /* polyspace-end DEFECT:COPY_PASTE_ERROR [Not a defect:Unset] "The checking condition of transition of CanNm/UdpNm state are same. that's why code is similar" */
		if (Nml_CanBusSleppDetectCnt < NML_RVCCM_THRESHOLD_MAX)
		{
			if (tmpCanNmModeStatus == tmpCanNmNextModeState)
			{
				Nml_CanBusSleppDetectCnt++;
			}
			else
			{
				/* Nothing, CanNm knows that next mode shall be changed */
			}				
		}
		else
		{
			Nml_LogFuncRVCCM(i, tempNmStateNotMatchedReason);
			Nml_CanBusSleppDetectCnt   = NML_UINT8_MIN;
		}
	}
  #endif /* #if (STD_ON == NML_USE) */
}
#endif /* #if (STD_ON == NML_CANNM_USED) */




void Nml_InitGlobalVariables(void)
{
#if (STD_ON == NML_USE)
	uint8 i;

	for (i=0; i<NML_COMM_TOTAL_USERS; i++)
	{
		Nml_RequestedComMode[i] = NML_COMMODE_NO_COM;
	}

	for (i=0; i<NML_COMM_TOTAL_CHANNELS; i++)
	{
		Nml_CurComMode[i] = NML_COMMODE_NO_COM;

		Nml_ChannelData[i].mappedUsrIdx             = NML_UINT8_MAX;
		Nml_ChannelData[i].mappedUsrCnt             = NML_UINT8_MAX;
        #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
		    Nml_ChannelData[i].mappedPncIdx             = NML_UINT8_MAX;
		    Nml_ChannelData[i].mappedPncCnt             = NML_UINT8_MAX;
		#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
		    Nml_ChannelData[i].mappedPncIdx             = NML_UINT16_MAX;
		    Nml_ChannelData[i].mappedPncCnt             = NML_UINT16_MAX;
        #else /* Other variant */
            #error "No NvM Module R44 or R40"
        #endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */ 
		Nml_ChannelData[i].isPncCh                  = NML_FALSE;
		Nml_ChannelData[i].requestedHighMode        = NML_COMMODE_NO_COM;
		Nml_ChannelData[i].curComMode               = NML_COMMODE_NO_COM;
		Nml_ChannelData[i].isReqVsCurComModeMatched = NML_TRUE;
		Nml_ChannelData[i].canNmIndex               = NML_UINT8_MAX;
		Nml_ChannelData[i].udpNmIndex               = NML_UINT8_MAX;
		Nml_ChannelData[i].repeatMsgTime            = NML_UINT16_MIN;
		Nml_ChannelData[i].nmTimeOutTime            = NML_UINT16_MIN;
		Nml_ChannelData[i].waitBusSleeptime         = NML_UINT16_MIN;
		Nml_ChannelData[i].nmNwRequested            = NML_UINT8_MIN;
		Nml_ChannelData[i].prevNmState              = NM_STATE_UNINIT;
		Nml_ChannelData[i].curNmState               = NM_STATE_UNINIT;
		Nml_ChannelData[i].NmStateMatched           = (uint8)NML_TRUE;
		Nml_ChannelData[i].targetElapsedCnt         = NML_UINT16_MIN;
		Nml_ChannelData[i].nmModeStatus          = 0x00;
		Nml_ChannelData[i].nmNextModeState       = 0x00;

		Nml_CurComModeChangeCnt[i] = NML_UINT8_MIN;
		Nml_CurComModeDetTimer[i] = NML_UINT16_MIN;
	}


	Nml_IsReqComModeDectTimerRun  = NML_FALSE;
	Nml_ReqComModeDectTimer = NML_UINT16_MIN;
	Nml_CmcTimerCnt = NML_UINT8_MIN;
/* polyspace-begin DEFECT:DUPLICATED_CODE [Not a defect:Unset] "Separate variables are required for CanNm and UdpNm for RVCCM, CanNm and UdpNm channels are separated" */
/* polyspace-begin DEFECT:DUPLICATED_CODE [Not a defect:Unset] "2 funcs(Nml_InitSleepToWakeup, Nml_InitGlobalVariables) are called exclusively by wakeup and reset." */
	Nml_CanNormalDetectCnt   = NML_UINT8_MIN;
    Nml_CanRssDetectCnt      = NML_UINT8_MIN;
    Nml_CanRmsDetectCnt      = NML_UINT8_MIN;
    Nml_CanPbsDetectCnt      = NML_UINT8_MIN;
    Nml_CanBusSleppDetectCnt = NML_UINT8_MIN;

	Nml_UdpNormalDetectCnt   = NML_UINT8_MIN;
	Nml_UdpRssDetectCnt      = NML_UINT8_MIN;
	Nml_UdpRmsDetectCnt      = NML_UINT8_MIN;
	Nml_UdpPbsDetectCnt      = NML_UINT8_MIN;
	Nml_UdpBusSleppDetectCnt = NML_UINT8_MIN;

	Nml_ComMTotalChannel     = NML_COMM_TOTAL_CHANNELS;
/* polyspace-end DEFECT:DUPLICATED_CODE [Not a defect:Unset] "2 funcs(Nml_InitSleepToWakeup, Nml_InitGlobalVariables) are called exclusively by wakeup and reset." */	
/* polyspace-end DEFECT:DUPLICATED_CODE [Not a defect:Unset] "Separate variables are required for CanNm and UdpNm for RVCCM, CanNm and UdpNm channels are separated" */
	
#endif /* #if (STD_ON == NML_USE) */
}

void Nml_GetNmState(void)
{
#if (STD_ON == NML_USE)
	Std_ReturnType ret = E_OK;
	uint8 i = 0x00;
	Nm_StateType nmState;
	Nm_ModeType  nmMode;
	uint8 canNmIndex = 0x00;
	uint8 udpNmIndex = 0x00;

	for (i=0; i<COMM_TOTAL_CHANNELS; i++)
	{
		canNmIndex = Nml_GetCanNmIndex(i);
		udpNmIndex = Nml_GetUdpNmIndex(i);
		/* KCLim_230620
		 * - Check whether channels are connected Nm or not
		 * - It is reported by HAE that there is NM DET if channels are not connected Nm
		 * */
		if ((NML_UINT8_MAX != canNmIndex) || (NML_UINT8_MAX != udpNmIndex))
		{
			ret = Nm_GetState(i, &nmState, &nmMode);
			if (E_OK == ret)
			{
				Nml_SetNmState(i, nmState);
			}
			else
			{
				Nml_SetNmState(i, NM_STATE_UNINIT);
			}
		}
		else
		{
			/* Do not call Nm_GetState API, because it is not connected Nm */
		}

	}

#endif /* #if (STD_ON == NML_USE) */
}

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

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
void Nml_InternalInit(void)
{
	/* Init global variables */
	Nml_InitGlobalVariables();
	/* Set channel data from ComM_Cfg */
	Nml_SetChannelData();

}




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
/* polyspace-begin CODE-METRIC:CALLS [Justified:Low] "to make code easy to read and to maintain" */
/* polyspace-begin CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
void Nml_InternalMain(void)
/* polyspace-end CODE-METRIC:NCALLS [Justified:Low] "To make code easy to read and to maintain" */
/* polyspace-end CODE-METRIC:CALLS [Justified:Low] "to make code easy to read and to maintain" */
{
#if (STD_ON == NML_USE)

	if (Nml_CmcTimerCnt >= NML_FUNC_CMC_DETECTION_TIMECNT)
	{
		Nml_CmcTimerCnt = 0x00;
		Nml_LogFuncCMC();
	}
	else
	{
		Nml_CmcTimerCnt++;
	}

	Nml_GetNmState();
	Nml_IsUpdatedReqOrCurComMode();
	Nml_UpdateComModeInfo();
	Nml_ChkReqVsCurComMode();

#if (STD_ON == NML_CANNM_USED)
	Nml_GetCanNmData();
	Nml_ChkCanNmState();
#endif /* #if (STD_ON == NML_CANNM_USED) */

#if (STD_ON == NML_UDPNM_USED)
	Nml_GetUdpNmData();
	Nml_ChkUdpNmState();
#endif /* #if (STD_ON == NML_CANNM_USED) */


	Nml_LogFuncEAET();
	Nml_LogFuncWUSInternal();
#endif /* #if (STD_ON == NML_USE) */
}


#define NML_STOP_SEC_CODE
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
