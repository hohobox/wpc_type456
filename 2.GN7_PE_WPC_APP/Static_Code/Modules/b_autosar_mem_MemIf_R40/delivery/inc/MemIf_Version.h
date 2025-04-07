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
**  SRC-MODULE: MemIf_Version.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemIf Module                                          **
**                                                                            **
**  PURPOSE   : C header for MemIf_Version                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     07-Feb-2013   CY Song          Initial Version                   **
*******************************************************************************/
#ifndef MEMIF_VERSION_H
#define MEMIF_VERSION_H

/*******************************************************************************
**                    Include Section                                         **
*******************************************************************************/
#include "MemIf.h"

/* polyspace-begin MISRA-C3:2.5 [Justified:Low] "Not a defect(version number)" */

/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MEMIF_VERSION_AR_RELEASE_MAJOR_VERSION  MEMIF_AR_RELEASE_MAJOR_VERSION
#define MEMIF_VERSION_AR_RELEASE_MINOR_VERSION  MEMIF_AR_RELEASE_MINOR_VERSION
#define MEMIF_VERSION_AR_RELEASE_REVISION_VERSION \
  MEMIF_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MEMIF_VERSION_SW_MAJOR_VERSION  MEMIF_SW_MAJOR_VERSION
#define MEMIF_VERSION_SW_MINOR_VERSION  MEMIF_SW_MINOR_VERSION

/* polyspace-end MISRA-C3:2.5 [Justified:Low] "Not a defect(version number)" */

#endif /* end of MEMIF_VERSION_H */
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
