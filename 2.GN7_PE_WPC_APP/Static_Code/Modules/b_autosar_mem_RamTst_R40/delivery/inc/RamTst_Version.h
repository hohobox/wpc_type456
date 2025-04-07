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
**  SRC-MODULE: RamTst_Version.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR RAM Test                                              **
**                                                                            **
**  PURPOSE   : C header for RamTst_Version                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By     Description                                 **
********************************************************************************
** 1.0.0     07-Jun-2013   CY Song          Initial Version                   **
*******************************************************************************/

#ifndef RAMTST_VERSION_H
#define RAMTST_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "RamTst.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define RAMTST_VERSION_AR_RELEASE_MAJOR_VERSION RAMTST_AR_RELEASE_MAJOR_VERSION
#define RAMTST_VERSION_AR_RELEASE_MINOR_VERSION RAMTST_AR_RELEASE_MINOR_VERSION
#define RAMTST_VERSION_AR_RELEASE_REVISION_VERSION \
  RAMTST_AR_RELEASE_REVISION_VERSION

/* RamTst Software Version Information */
#define RAMTST_VERSION_SW_MAJOR_VERSION RAMTST_SW_MAJOR_VERSION
#define RAMTST_VERSION_SW_MINOR_VERSION RAMTST_SW_MINOR_VERSION

/* Det Software Version Information */
#if(RAMTST_DEV_ERROR_DETECT == STD_ON)
#define RAMTST_DET_AR_RELEASE_MAJOR_VERSION 4
#define RAMTST_DET_AR_RELEASE_MINOR_VERSION 0
#endif

#endif /* RAMTST_VERSION_H */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
