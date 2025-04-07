/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_Ram.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : Global Ram Variables for CanNM                                **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date         By                  Description                     **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.3.1.0   24-May-2023   SM Kwon           #40495                           **
** 2.5.0.0   04-Nov-2023   JW Oh             #41382                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"                /* CANNM APIs header file */
#include "CanNm_Internal.h"       /* CANNM Internal functions header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_RAM_C_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_RAM_C_AR_RELEASE_MINOR_VERSION    0
#define CANNM_RAM_C_AR_RELEASE_REVISION_VERSION 3

/* CanNm software version information */
#define CANNM_RAM_C_SW_MAJOR_VERSION            2
#define CANNM_RAM_C_SW_MINOR_VERSION            5
#define CANNM_RAM_C_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CANNM_AR_RELEASE_MAJOR_VERSION != CANNM_RAM_C_AR_RELEASE_MAJOR_VERSION)
#error "CanNm_Ram.c : Mismatch in Specification Major Version"
#endif

#if (CANNM_AR_RELEASE_MINOR_VERSION != CANNM_RAM_C_AR_RELEASE_MINOR_VERSION)
#error "CanNm_Ram.c : Mismatch in Specification Minor Version"
#endif

#if (CANNM_AR_RELEASE_REVISION_VERSION !=\
     CANNM_RAM_C_AR_RELEASE_REVISION_VERSION)
#error "CanNm_Ram.c : Mismatch in Specification Revision Version"
#endif

#if (CANNM_SW_MAJOR_VERSION != CANNM_RAM_C_SW_MAJOR_VERSION)
#error "CanNm_Ram.c : Mismatch in Software Major Version"
#endif

#if (CANNM_SW_MINOR_VERSION != CANNM_RAM_C_SW_MINOR_VERSION)
#error "CanNm_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define CANNM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Variable to hold CANNM Initialization Status */
VAR(boolean, CANNM_VAR) CanNm_GblInitStatus;
#define CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
#define CANNM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

/* [Change Wait Bus Sleep Timer API] 
 * Declaration of CanNm_GulUserRequestTWaitBusSleepTime
 */
VAR(CanNm_LTimeType, CANNM_VAR) CanNm_GulUserRequestTWaitBusSleepTime;

#define CANNM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"
#endif

#define CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(uint8, CANNM_VAR) CanNm_GaaEIRA[CANNM_MAX_PN_INFO_LENGTH];
#define CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(CanNm_TimeType, CANNM_VAR) CanNm_GaaPnEIRATimer[(CANNM_MAX_PN_INFO_LENGTH * 8U)];
#define CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* definition for static channel configuration information for the selected variant*/
P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) CanNm_GpStaticChannel;
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* definition for static channel configuration information for the selected variant*/
P2CONST(uint8, AUTOMATIC, CANNM_CONST) CanNm_GpPnMaskByte;
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
