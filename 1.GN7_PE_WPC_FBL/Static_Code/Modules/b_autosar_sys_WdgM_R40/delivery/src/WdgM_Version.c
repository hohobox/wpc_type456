/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
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
**  SRC-MODULE: WdgM_Version.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Watchdog Manager Module                               **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
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
** 1.2.20    23-Aug-2022   GB.Lim       Redmine #37185                        **
** 1.2.19    20-Jul-2022   YH.Han       Redmine #36757                        **
** 1.2.18    14-Dec-2021   YH.Han       Redmine #33438                        **
** 1.2.14    15-Mar-2019   YH.Han       Redmine #16479                        **
** 1.0.4     21-Oct-2014   Sinil        1. Change including                   **
** 1.0.3     03-Jan-2014   Sinil        TaskID:809                            **
**                                      1. Lines reordered                    **
**                                      2. Include header and error log       **
**                                      changed                               **
** 1.0.2     23-Dec-2013   Sinil        Add precondition for version check    **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Version.h"     /* WdgM version header file */
#include "WdgM.h"             /* WdgM module header file */
#include "WdgIf.h"            /* WdgIf version header file */
#include "Mcu.h"              /* Mcu module Header file */
#if(WDGM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* Det module Header file */
#endif
#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#include "Dem.h"              /* Dem version Header file */
#endif
#include "Rte.h"              /* Rte version header file */
#include "BswM.h"             /* BswM version header file */
#include "Os.h"               /* Os version header file */

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* WdgM version check */
#if (WDGM_AR_RELEASE_MAJOR_VERSION != \
  WDGM_VERSION_AR_RELEASE_MAJOR_VERSION)
  #error "WdgM.h : Mismatch in Specification Major Version"
#endif
#if (WDGM_AR_RELEASE_MINOR_VERSION != \
  WDGM_VERSION_AR_RELEASE_MINOR_VERSION)
  #error "WdgM.h : Mismatch in Specification Minor Version"
#endif
#if (WDGM_AR_RELEASE_REVISION_VERSION != \
  WDGM_VERSION_AR_RELEASE_REVISION_VERSION)
  #error "WdgM.h : Mismatch in Specification Revision Version"
#endif
#if (WDGM_SW_MAJOR_VERSION != WDGM_VERSION_SW_MAJOR_VERSION)
  #error "WdgM.h : Mismatch in Software Major Version"
#endif
#if (WDGM_SW_MINOR_VERSION != WDGM_VERSION_SW_MINOR_VERSION)
  #error "WdgM.h : Mismatch in Software Minor Version"
#endif
#if (WDGM_SW_PATCH_VERSION != WDGM_VERSION_SW_PATCH_VERSION)
  #error "WdgM.h : Mismatch in Software Patch Version"
#endif

/* WdgIf version check */
#if defined(WDGIF_AR_RELEASE_MAJOR_VERSION) \
  && defined(WDGIF_AR_RELEASE_MINOR_VERSION)
#if (WDGIF_AR_RELEASE_MAJOR_VERSION != WDGM_WDGIF_AR_RELEASE_MAJOR_VERSION)
  #error "WdgIf.h : Mismatch in Specification Major Version"
#endif
#if (WDGIF_AR_RELEASE_MINOR_VERSION != WDGM_WDGIF_AR_RELEASE_MINOR_VERSION)
  #error "WdgIf.h : Mismatch in Specification Minor Version"
#endif
#endif

/* Mcu version check */
#if defined(MCU_AR_RELEASE_MAJOR_VERSION) \
  && defined(MCU_AR_RELEASE_MINOR_VERSION)
#if (MCU_AR_RELEASE_MAJOR_VERSION != WDGM_MCU_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu.h : Mismatch in Specification Major Version"
#endif
#if (MCU_AR_RELEASE_MINOR_VERSION < WDGM_MCU_AR_RELEASE_MINOR_VERSION_L)
  #error "Mcu.h : Mismatch in Specification Minor Version"
#endif
#if (MCU_AR_RELEASE_MINOR_VERSION > WDGM_MCU_AR_RELEASE_MINOR_VERSION_U)
  #error "Mcu.h : Mismatch in Specification Minor Version"
#endif
#endif

/* DET Version check */
#if (WDGM_DEV_ERROR_DETECT == STD_ON)
#if defined(DET_AR_RELEASE_MAJOR_VERSION) \
  && defined(DET_AR_RELEASE_MINOR_VERSION)
#if (DET_AR_RELEASE_MAJOR_VERSION != WDGM_DET_AR_RELEASE_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif
#if (DET_AR_RELEASE_MINOR_VERSION != WDGM_DET_AR_RELEASE_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif
#endif /* #if(WDGM_DEV_ERROR_DETECT == STD_ON) */

/* DEM Version check */
#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#if defined(DEM_AR_RELEASE_MAJOR_VERSION) \
  && defined(DEM_AR_RELEASE_MINOR_VERSION)
#if (DEM_AR_RELEASE_MAJOR_VERSION != WDGM_DEM_AR_RELEASE_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif
#if (DEM_AR_RELEASE_MINOR_VERSION != WDGM_DEM_AR_RELEASE_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif
#endif
#endif /* #if(WDGM_DEM_ERROR_REPORT == STD_ON) */

/* RTE Version check */
#if defined(RTE_AR_RELEASE_MAJOR_VERSION) \
  && defined(RTE_AR_RELEASE_MINOR_VERSION)
#if (RTE_AR_RELEASE_MAJOR_VERSION != WDGM_RTE_AR_RELEASE_MAJOR_VERSION)
  #error "Rte.h : Mismatch in Rte Specification Major Version"
#endif
#if (RTE_AR_RELEASE_MINOR_VERSION != WDGM_RTE_AR_RELEASE_MINOR_VERSION)
  #error "Rte.h : Mismatch in Rte Specification Minor Version"
#endif
#endif

/* BswM version check */
#if defined(BSWM_AR_RELEASE_MAJOR_VERSION) \
  && defined(BSWM_AR_RELEASE_MINOR_VERSION)
#if (BSWM_AR_RELEASE_MAJOR_VERSION != WDGM_BSWM_AR_RELEASE_MAJOR_VERSION)
  #error "BswM.h : Mismatch in Specification Major Version"
#endif
#if (BSWM_AR_RELEASE_MINOR_VERSION != WDGM_BSWM_AR_RELEASE_MINOR_VERSION)
  #error "BswM.h : Mismatch in Specification Minor Version"
#endif
#endif

/* OS version check */
#if defined(OS_AR_RELEASE_MAJOR_VERSION) \
  && defined(OS_AR_RELEASE_MINOR_VERSION)
#if (OS_AR_RELEASE_MAJOR_VERSION != WDGM_OS_AR_RELEASE_MAJOR_VERSION)
  #error "Os.h : Mismatch in Specification Major Version"
#endif
#if (OS_AR_RELEASE_MINOR_VERSION < WDGM_OS_AR_RELEASE_MINOR_VERSION_L)
  #error "Os.h : Mismatch in Specification Minor Version"
#endif
#if (OS_AR_RELEASE_MINOR_VERSION > WDGM_OS_AR_RELEASE_MINOR_VERSION_U)
  #error "Os.h : Mismatch in Specification Minor Version"
#endif
#endif

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<MISRA-C3:1.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
