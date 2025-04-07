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
**  SRC-MODULE: Wdg_76_Acw_Version.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTOEVER CUSTOM WDG                                   **
**                                                                            **
**  PURPOSE   : Header for Wdg_76_Acw_Version.c                               **
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
** 1.8.6     04-Jul-2023   JH.Kim       Redmine #41466, #41888                **
** 1.8.5     20-Jul-2022   YH.Han       Redmine #36711                        **
** 1.8.2     18-Oct-2021   YH.Han       Redmine #32698                        **
** 1.5.0     25-Apr-2019   YH.Han       Redmine #16478                        **
** 1.0.1     28-Apr-2016   Sinil        Redmine #4744                         **
** 1.0.0     02-Feb-2015   Sinil        Initial version                       **
*******************************************************************************/

#ifndef WDG_76_ACW_VERSION_H
#define WDG_76_ACW_VERSION_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Wdg_76_Acw_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define WDG_76_ACW_VERSION_AR_RELEASE_MAJOR_VERSION    WDG_76_ACW_AR_RELEASE_MAJOR_VERSION
#define WDG_76_ACW_VERSION_AR_RELEASE_MINOR_VERSION    WDG_76_ACW_AR_RELEASE_MINOR_VERSION
#define WDG_76_ACW_VERSION_AR_RELEASE_REVISION_VERSION WDG_76_ACW_AR_RELEASE_REVISION_VERSION

/* Software Version Information */
#define WDG_76_ACW_VERSION_SW_MAJOR_VERSION     WDG_76_ACW_SW_MAJOR_VERSION
#define WDG_76_ACW_VERSION_SW_MINOR_VERSION     WDG_76_ACW_SW_MINOR_VERSION
#define WDG_76_ACW_VERSION_SW_PATCH_VERSION     WDG_76_ACW_SW_PATCH_VERSION

/*Version information of Det module */
#define WDG_76_ACW_DET_AR_RELEASE_MAJOR_VERSION          4
#define WDG_76_ACW_DET_AR_RELEASE_MINOR_VERSION          0

/*Version information of Dem module */
#define WDG_76_ACW_DEM_AR_RELEASE_MAJOR_VERSION          4
#define WDG_76_ACW_DEM_AR_RELEASE_MINOR_VERSION          0

/*Version information of Dio module */
#define WDG_76_ACW_DIO_AR_RELEASE_MAJOR_VERSION          4
#define WDG_76_ACW_DIO_AR_RELEASE_MINOR_VERSION_L        0
#define WDG_76_ACW_DIO_AR_RELEASE_MINOR_VERSION_U        8

/* polyspace-begin MISRA-C3:2.5 [Not a Defect] 
                              "macro is used according to user configuration" */
/*Version information of Spi module */
#define WDG_76_ACW_SPI_AR_RELEASE_MAJOR_VERSION          4
#define WDG_76_ACW_SPI_AR_RELEASE_MINOR_VERSION          0
/* polyspace-end<MISRA-C3:2.5 */

/*Version information of Gpt module */
#define WDG_76_ACW_GPT_AR_RELEASE_MAJOR_VERSION          4
#define WDG_76_ACW_GPT_AR_RELEASE_MINOR_VERSION_L        0
#define WDG_76_ACW_GPT_AR_RELEASE_MINOR_VERSION_U        8

#endif /* WDG_76_ACW_VERSION_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
