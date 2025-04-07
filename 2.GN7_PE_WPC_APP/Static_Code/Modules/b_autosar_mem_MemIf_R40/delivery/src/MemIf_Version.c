/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemIf_Version.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemIf Module                                          **
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
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     07-Feb-2013   CY Song          Initial Version                   **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "MemIf_Version.h"
 
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.5 [Justified:Low] "Not a defect(version number)" */

/* AUTOSAR specification version information */

#define MEMIF_VERSION_C_AR_RELEASE_MAJOR_VERSION  4
#define MEMIF_VERSION_C_AR_RELEASE_MINOR_VERSION  0
#define MEMIF_VERSION_C_AR_RELEASE_REVISION_VERSION  3

/* File version information */
#define MEMIF_VERSION_C_SW_MAJOR_VERSION  1
#define MEMIF_VERSION_C_SW_MINOR_VERSION  3

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (MEMIF_VERSION_SW_MAJOR_VERSION != MEMIF_VERSION_C_SW_MAJOR_VERSION)
  #error "NvM.c : Mismatch in Software Major Version"
#endif

#if (MEMIF_VERSION_SW_MINOR_VERSION != MEMIF_VERSION_C_SW_MINOR_VERSION)
  #error "NvM.c : Mismatch in Software Minor Version"
#endif

/* polyspace-end MISRA-C3:2.5 [Justified:Low] "Not a defect(version number)" */

/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
