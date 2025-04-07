/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: Wdg_76_Acw_Config.h                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTOEVER CUSTOM WDG                                   **
**                                                                            **
**  PURPOSE   : AUTOEVER Custom Watchdog const variable declarations for      **
**              making a library                                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.8.6     04-Jul-2023   JH.Kim       Redmine #41888                        **
** 1.8.5     20-Jul-2022   YH.Han       Redmine #36711                        **
** 1.8.2     18-Oct-2021   YH.Han       Redmine #32698                        **
** 1.7.0     10-Apr-2020   YH.Han       Redmine #22704                        **
** 1.1.0     17-Jul-2017   Kuksun       Redmine #8886                         **
** 1.0.4     28-Apr-2016   Sinil        Redmine #4744                         **
** 1.0.3     25-Apr-2016   Sinil        Redmine #4610                         **
** 1.0.0     02-Feb-2015   Sinil        Initial version                       **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.1 [Not a Defect] "see MEMMAP003 of AUTOSAR" */

#ifndef WDG_76_ACW_CONFIG_H
#define WDG_76_ACW_CONFIG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Wdg_76_Acw_Cfg.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#define WDG_76_ACW_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, WDG_76_ACW_CONST) Wdg_76_Acw_InstanceId;
#define WDG_76_ACW_STOP_SEC_CONST_8
#include "MemMap.h"

#define WDG_76_ACW_START_SEC_CONST_16
#include "MemMap.h"
extern CONST(uint16, WDG_76_ACW_CONST) Wdg_76_Acw_InitialTimeout;
#define WDG_76_ACW_STOP_SEC_CONST_16
#include "MemMap.h"

#define WDG_76_ACW_START_SEC_CONST_16
#include "MemMap.h"
extern CONST(uint16, WDG_76_ACW_CONST) Wdg_76_Acw_MaxTimeout;
#define WDG_76_ACW_STOP_SEC_CONST_16
#include "MemMap.h"

#if (WDG_76_ACW_EXTERNAL_MODULE_DIO == STD_ON)
#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dio_ChannelType, WDG_76_ACW_CONST) Wdg_76_Acw_DioChannel;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (WDG_76_ACW_EXTERNAL_MODULE_DIO == STD_ON) */

#if (WDG_76_ACW_EXTERNAL_MODULE_MPQ6411== STD_ON)
#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dio_ChannelType, WDG_76_ACW_CONST) Wdg_76_Acw_DioChannel;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dio_ChannelType, WDG_76_ACW_CONST) Wdg_76_Acw_DioModeChannel;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (WDG_76_ACW_EXTERNAL_MODULE_MPQ6411 == STD_ON) */


#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Gpt_ChannelType, WDG_76_ACW_CONST) Wdg_76_Acw_GptChannel;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(WdgIf_ModeType, WDG_76_ACW_CONST) Wdg_76_Acw_DefaultMode;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (WDG_76_ACW_DEM_ERROR_REPORT == STD_ON)
#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDG_76_ACW_E_DISABLE_REJECTED */
extern CONST(Dem_EventIdType, WDG_76_ACW_CONST) Wdg_76_Acw_GddEDisableRejected;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDG_76_ACW_E_MODE_FAILED */
extern CONST(Dem_EventIdType, WDG_76_ACW_CONST) Wdg_76_Acw_GddEModeFailed;
#define WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (WDG_76_ACW_DEM_ERROR_REPORT == STD_ON) */

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA-C3:20.1 */

#endif /* WDG_76_ACW_CONFIG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
