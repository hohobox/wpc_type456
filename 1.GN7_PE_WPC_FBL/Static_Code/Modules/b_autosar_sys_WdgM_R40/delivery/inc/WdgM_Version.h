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
**  SRC-MODULE: WdgM_Version.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Header for WdgM_Version.c                                     **
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
** 1.2.21    17-Jul-2023   JH.Kim       Redmine #41337                        **
** 1.2.20    23-Aug-2022   GB.Lim       Redmine #37185                        **
** 1.2.19    20-Jul-2022   YH.Han       Redmine #36757                        **
** 1.2.18    14-Dec-2021   YH.Han       Redmine #33438                        **
** 1.2.14    15-Mar-2019   YH.Han       Redmine #16479, #16411                **
** 1.0.4     03-Feb-2015   Sinil        1. Update version infos from common   **
**                                      published version                     **
** 1.0.3     21-Oct-2014   Sinil        1. Update                             **
**                                      WDGM_VERSION_SW_PATCH_VERSION         **
** 1.0.2     30-Sep-2014   Sinil        1. Remove Det precompiler option      **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef WDGM_VERSION_H
#define WDGM_VERSION_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define WDGM_VERSION_AR_RELEASE_MAJOR_VERSION    WDGM_AR_RELEASE_MAJOR_VERSION
#define WDGM_VERSION_AR_RELEASE_MINOR_VERSION    WDGM_AR_RELEASE_MINOR_VERSION
#define WDGM_VERSION_AR_RELEASE_REVISION_VERSION WDGM_AR_RELEASE_REVISION_VERSION

/* Software Version Information */
#define WDGM_VERSION_SW_MAJOR_VERSION     WDGM_SW_MAJOR_VERSION
#define WDGM_VERSION_SW_MINOR_VERSION     WDGM_SW_MINOR_VERSION
#define WDGM_VERSION_SW_PATCH_VERSION     WDGM_SW_PATCH_VERSION

/*Version information of WdgIf module */
#define WDGM_WDGIF_AR_RELEASE_MAJOR_VERSION        4
#define WDGM_WDGIF_AR_RELEASE_MINOR_VERSION        0

/*Version information of Mcu module */
#define WDGM_MCU_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_MCU_AR_RELEASE_MINOR_VERSION_L        0
#define WDGM_MCU_AR_RELEASE_MINOR_VERSION_U        8

/*Version information of Det module */
#define WDGM_DET_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_DET_AR_RELEASE_MINOR_VERSION          0

/*Version information of Dem module */
#define WDGM_DEM_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_DEM_AR_RELEASE_MINOR_VERSION          0

/* Version information of RTE module */
#define WDGM_RTE_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_RTE_AR_RELEASE_MINOR_VERSION          0

/*Version information of BswM module */
#define WDGM_BSWM_AR_RELEASE_MAJOR_VERSION         4
#define WDGM_BSWM_AR_RELEASE_MINOR_VERSION         0

/* polyspace-begin MISRA-C3:2.5 [Not a defect]
                      "below macros are used according to user configuration"
 */
/*Version information of Os module */
#define WDGM_OS_AR_RELEASE_MAJOR_VERSION           4
#define WDGM_OS_AR_RELEASE_MINOR_VERSION_L         0
#define WDGM_OS_AR_RELEASE_MINOR_VERSION_U         4
/* polyspace-end<MISRA-C3:2.5 */

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/

#endif /* WDGM_VERSION_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
