/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Version.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Module Version information                 **
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "IpduM_Version.h"
#include "PduR_IpduM.h"
#include "SchM_IpduM.h"
#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
#include "Com.h"
#endif
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#endif /* #if (IPDUM_ENABLE == STD_ON) */
#include "Rte.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define IPDUM_VERSION_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_VERSION_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_VERSION_C_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define IPDUM_VERSION_C_SW_MAJOR_VERSION            2
#define IPDUM_VERSION_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != IPDUM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM_Version.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != IPDUM_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM_Version.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM_Version.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_VERSION_C_SW_MAJOR_VERSION)
#error "IpduM_Version.c : Mismatch in software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_VERSION_C_SW_MINOR_VERSION)
#error "IpduM_Version.c : Mismatch in software Minor Version"
#endif

#if (PDUR_AR_RELEASE_MAJOR_VERSION != IPDUM_PDUR_AR_RELEASE_MAJOR_VERSION)
#error "PduR.h : Mismatch in Specification Major Version"
#endif

#if (PDUR_AR_RELEASE_MINOR_VERSION != IPDUM_PDUR_AR_RELEASE_MINOR_VERSION)
#error "PduR.h : Mismatch in Specification Minor Version"
#endif

#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_RELEASE_MAJOR_VERSION != IPDUM_DET_AR_RELEASE_MAJOR_VERSION)
#error "Det.h : Mismatch in Specification Major Version"
#endif
#endif /*#if (IPDUM_ENABLE == STD_ON)*/

#if (DET_AR_RELEASE_MINOR_VERSION != IPDUM_DET_AR_RELEASE_MINOR_VERSION)
#error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (IPDUM_DEV_ERROR_DETECT == STD_ON) */

#if (RTE_AR_RELEASE_MAJOR_VERSION != IPDUM_RTE_AR_RELEASE_MAJOR_VERSION)
#error "Rte.h : Mismatch in Specification Major Version"
#endif

#if (RTE_AR_RELEASE_MINOR_VERSION != IPDUM_RTE_AR_RELEASE_MINOR_VERSION)
#error "Rte.h : Mismatch in Specification Minor Version"
#endif

#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
#if (COM_AR_RELEASE_MAJOR_VERSION != IPDUM_COM_AR_RELEASE_MAJOR_VERSION)
#error "Com.h : Mismatch in Specification Major Version"
#endif
#if (COM_AR_RELEASE_MINOR_VERSION != IPDUM_COM_AR_RELEASE_MINOR_VERSION)
#error "Com.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
#endif /*#if (IPDUM_ENABLE == STD_ON)*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


