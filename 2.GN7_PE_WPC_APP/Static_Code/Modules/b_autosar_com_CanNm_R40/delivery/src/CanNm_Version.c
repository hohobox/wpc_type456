/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_Version.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : Provision of Version Information                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                    Description                  **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"                /* CanNm API Header File */
#include "CanNm_Version.h"        /* CanNm Version Information Header */
#include "Rte.h"                  /* Rte header */
#include "Nm.h"                   /* Nm header file */
#include "CanIf.h"                /* CanIf header file */
#include "PduR.h"                 /* PduR CallBack Functions Header File */
#include "Det.h"                  /* DET header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define CANNM_VERSION_C_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_VERSION_C_AR_RELEASE_MINOR_VERSION    0
#define CANNM_VERSION_C_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define CANNM_VERSION_C_SW_MAJOR_VERSION            2
#define CANNM_VERSION_C_SW_MINOR_VERSION            5
#define CANNM_VERSION_C_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/* CanNm Version Check */

#if (CANNM_AR_RELEASE_MAJOR_VERSION !=\
     CANNM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "CanNm_Version.c : Mismatch in Specification Major Version"
#endif

#if (CANNM_AR_RELEASE_MINOR_VERSION !=\
     CANNM_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "CanNm_Version.c : Mismatch in Specification Minor Version"
#endif

#if (CANNM_AR_RELEASE_REVISION_VERSION !=\
     CANNM_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "CanNm_Version.c : Mismatch in Specification Revision Version"
#endif

#if (CANNM_SW_MAJOR_VERSION != CANNM_VERSION_C_SW_MAJOR_VERSION)
#error "CanNm_Version.c : Mismatch in Software Major Version"
#endif

#if (CANNM_SW_MINOR_VERSION != CANNM_VERSION_C_SW_MINOR_VERSION)
#error "CanNm_Version.c : Mismatch in Software Minor Version"
#endif

#if (DET_AR_RELEASE_MAJOR_VERSION != CANNM_DET_AR_RELEASE_MAJOR_VERSION)
#error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_RELEASE_MINOR_VERSION != CANNM_DET_AR_RELEASE_MINOR_VERSION)
#error "Det.h : Mismatch in Specification Minor Version"
#endif

/* Rte version check */
#if (RTE_AR_RELEASE_MAJOR_VERSION != CANNM_RTE_AR_RELEASE_MAJOR_VERSION)
#error "Rte.h : Mismatch in Specification Major Version"
#endif

#if (RTE_AR_RELEASE_MINOR_VERSION != CANNM_RTE_AR_RELEASE_MINOR_VERSION)
#error "Rte.h : Mismatch in Specification Minor Version"
#endif

/* Nm version check */
#if (NM_AR_RELEASE_MAJOR_VERSION != CANNM_NM_AR_RELEASE_MAJOR_VERSION)
#error "Nm.h : Mismatch in Specification Major Version"
#endif

#if (NM_AR_RELEASE_MINOR_VERSION != CANNM_NM_AR_RELEASE_MINOR_VERSION)
#error "Nm.h : Mismatch in Specification Minor Version"
#endif

/* CanIf version check */
#if (CANIF_AR_RELEASE_MAJOR_VERSION != CANNM_CANIF_AR_RELEASE_MAJOR_VERSION)
#error "CanIf.h : Mismatch in Specification Major Version"
#endif

#if (CANIF_AR_RELEASE_MINOR_VERSION != CANNM_CANIF_AR_RELEASE_MINOR_VERSION)
#error "CanIf.h : Mismatch in Specification Minor Version"
#endif

/* PDUR version check */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != CANNM_PDUR_AR_RELEASE_MAJOR_VERSION)
#error "PduR.h : Mismatch in Specification Major Version"
#endif

#if (PDUR_AR_RELEASE_MINOR_VERSION != CANNM_PDUR_AR_RELEASE_MINOR_VERSION)
#error "PduR.h : Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
