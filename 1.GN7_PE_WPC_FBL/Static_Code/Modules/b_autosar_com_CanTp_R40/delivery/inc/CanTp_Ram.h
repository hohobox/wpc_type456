/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanTp_Ram.h                                                   **
**                                                                            **
**  TARGET    : ALL                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CANTP MODULE                                          **
**                                                                            **
**  PURPOSE   : Header file for CanTp_Ram.c                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.12.2    23-Aug-2022   DH Choi        Redmine #37190                      **
** 1.12.0    04-Jan-2022   SM Kwon        Redmine #33032                      **
** 1.10.1    15-Oct-2019   SM Kwon        Redmine #19629                      **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANTP_RAM_H
#define CANTP_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanTp_Cfg.h"            /* Configuration header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANTP_RAM_AR_RELEASE_MAJOR_VERSION    4
#define CANTP_RAM_AR_RELEASE_MINOR_VERSION    0
#define CANTP_RAM_AR_RELEASE_REVISION_VERSION 3

/* CANTP software version information */
#define CANTP_RAM_SW_MAJOR_VERSION            1
#define CANTP_RAM_SW_MINOR_VERSION            12
#define CANTP_RAM_SW_PATCH_VERSION            3

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANTP_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store CanTp Initialization status */
extern VAR(boolean, CANTP_VAR) CanTp_GblInitStatus;
#define CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#if (CANTP_RX_NSDU == STD_ON)
#define CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(uint8, CANTP_VAR) CanTp_GaaRxDl[CANTP_MAXNO_RX_SDU];
#define CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* CANTP_RAM_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/

