/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Ram.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Global definitions                         **
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
#ifndef IPDUM_RAM_H
#define IPDUM_RAM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM_PCTypes.h"       /* Pre-compile time header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define IPDUM_RAM_AR_RELEASE_MAJOR_VERSION             4
#define IPDUM_RAM_AR_RELEASE_MINOR_VERSION             0
#define IPDUM_RAM_AR_RELEASE_REVISION_VERSION          3

/* Software Version Information */
#define IPDUM_RAM_SW_MAJOR_VERSION                     2
#define IPDUM_RAM_SW_MINOR_VERSION                     1
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define IPDUM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store Initialization status of IpduM */
extern VAR (boolean, IPDUM_VAR) IpduM_GblStatus;
#define IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#endif /* IPDUM_RAM_H */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
