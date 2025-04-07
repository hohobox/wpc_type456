/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Version.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : C header for IpduM_Version                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.1.0     19-May-2022   HM Shin     Internal Redmine #34769                **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/
#ifndef IPDUM_VERSION_H
#define IPDUM_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "IpduM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define IPDUM_VERSION_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_VERSION_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_VERSION_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define IPDUM_VERSION_SW_MAJOR_VERSION            2
#define IPDUM_VERSION_SW_MINOR_VERSION            1

/* AUTOSAR Specification Version Information */
#define IPDUM_PDUR_AR_RELEASE_MAJOR_VERSION       4
#define IPDUM_PDUR_AR_RELEASE_MINOR_VERSION       0

#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
#define IPDUM_DET_AR_RELEASE_MAJOR_VERSION        4
#define IPDUM_DET_AR_RELEASE_MINOR_VERSION        0
#endif
#endif /* #if (IPDUM_ENABLE == STD_ON) */

#define IPDUM_RTE_AR_RELEASE_MAJOR_VERSION        4
#define IPDUM_RTE_AR_RELEASE_MINOR_VERSION        0

#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
#define IPDUM_COM_AR_RELEASE_MAJOR_VERSION        4
#define IPDUM_COM_AR_RELEASE_MINOR_VERSION        0
#endif
#endif /*#if (IPDUM_ENABLE == STD_ON)*/

#endif /* IPDUM_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

