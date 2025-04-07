/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm.h                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : Main header file for CanNm.c                                  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date        By                Description                        **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.3.0.0   10-May-2022   Jaeho Yang        #35336                           **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.2.7.0   07-Oct-2022   Jaeho Yang        #37628                           **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.3.1.0   02-Jun-2023   SM Kwon           #40495                           **
** 2.4.0.0   22-Aug-2023   JW Oh             #40502                           **
** 2.5.0.0   04-Nov-2023   JW Oh             #41382                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

#ifndef CANNM_H
#define CANNM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_Cfg.h"            /* Configuration header file */
#include "NmStack_Types.h"        /* Nm Interface type definitions header */
#include "ComStack_Types.h"       /* Com Interface type definitions header */
#include "CanNm_PCTypes.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define CANNM_H_AR_RELEASE_MAJOR_VERSION         4
#define CANNM_H_AR_RELEASE_MINOR_VERSION         0
#define CANNM_H_AR_RELEASE_REVISION_VERSION      3

/* CANNM software version information */
#define CANNM_H_SW_MAJOR_VERSION            2
#define CANNM_H_SW_MINOR_VERSION            5
#define CANNM_H_SW_PATCH_VERSION            1
/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
#define CANNM_INSTANCE_ID                     0U

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANNM_UNUSED(x)                        do { \
                                                    if((uint32)(x) != \
                                                    (uint32)0) {} \
                                                  } while(0)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANNM_UNUSED_PTR(x)                    do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)

#define CanNm_Memcpy                           memcpy
#define CanNm_Memset                           memset


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define CANNM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANNM_CODE) CanNm_Init
  (CONSTP2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) cannmConfigPtr);

extern FUNC(void, CANNM_CODE) CanNm_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, CANNM_APPL_DATA) cannmVersioninfo);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_PassiveStartUp
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRequest
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRelease
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_DisableCommunication
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_DisableCommunication_TimerisNotStopped
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_EnableCommunication
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_EnableCommunication_TimerisNotStarted
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetNetworkRequestReason
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONST(uint8, CANNM_APPL_CONST) nmNetworkRequestReason);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetNetworkRequestReason
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) pNmNetworkRequestReason);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetUserData
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2CONST(uint8, AUTOMATIC, CANNM_APPL_CONST) nmUserDataPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetUserData
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetLocalNodeIdentifier
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetNodeIdentifier
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_RepeatMessageRequest
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetPduData
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(uint8,AUTOMATIC, CANNM_APPL_DATA) nmPduDataPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetState
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(Nm_StateType, AUTOMATIC, CANNM_APPL_DATA) nmStatePtr,
   CONSTP2VAR(Nm_ModeType, AUTOMATIC, CANNM_APPL_DATA) nmModePtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_RequestBusSynchronization
  (VAR(NetworkHandleType, CANNM_VAR) nmChannelHandle);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_CheckRemoteSleepIndication
  (CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
   CONSTP2VAR(boolean, AUTOMATIC, CANNM_APPL_DATA) nmRemoteSleepIndPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_Transmit
  (PduIdType CanTxPduId, P2CONST(PduInfoType, AUTOMATIC,CANNM_APPL_CONST) PduInfoPtr);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetSleepReadyBit
  (VAR(NetworkHandleType, CANNM_VAR) nmChannelHandle,
   VAR(boolean, CANNM_VAR) nmSleepReadyBit);

extern FUNC(void, CANNM_CODE) CanNm_DeInit(void);

#if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
extern FUNC(void, CANNM_CODE) CanNm_ChangeTWaitBusSleep(
	CONST(uint32, CANNM_CONST) TwaitBusSleep);
#endif

#define CANNM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANNM_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
