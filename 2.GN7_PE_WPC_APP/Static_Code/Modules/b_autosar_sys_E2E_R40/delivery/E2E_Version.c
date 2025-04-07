/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_Version.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Provision of Version information Check                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date           By              Description                        **
********************************************************************************
** 1.2.5    09-Aug-2022    Seungjin Noh    Change made as per #36855          **
** 1.2.4    23-Dec-2021    Gongbin Lim     Change made as per #33551          **
** 1.2.3    05-Aug-2020    Gongbin Lim     Change made as per #25018          **
** 1.2.2    24-Oct-2018    Gongbin Lim     Change made as per #14435          **
** 1.2.1    18-Jun-2018    Gongbin Lim     Change made as per #12704          **
** 1.2.0    22-Mar-2018    Gongbin Lim     Changes made as per #11718         **
** 1.1.0    03-Mar-2016    Seongmin Kim    Change made as per #4296           **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2E_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_VERSION_C_AR_RELEASE_MAJOR_VERSION           (4)
#define E2E_VERSION_C_AR_RELEASE_MINOR_VERSION           (2)
#define E2E_VERSION_C_AR_RELEASE_REVISION_VERSION        (2)

/* FILE VERSION INFORMATION */
#define E2E_VERSION_C_SW_MAJOR_VERSION                   (1)
#define E2E_VERSION_C_SW_MINOR_VERSION                   (2)
#define E2E_VERSION_C_SW_PATCH_VERSION                   (5)
#define CRC_AR_RELEASE_MAJOR_VERSION                     (4)
#define CRC_AR_RELEASE_MINOR_VERSION                     (0)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E_Version.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "E2E_Version.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "E2E_Version.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_VERSION_C_SW_MAJOR_VERSION)
#error "E2E_Version.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_VERSION_C_SW_MINOR_VERSION)
#error "E2E_Version.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_VERSION_C_SW_PATCH_VERSION)
#error "E2E_Version.c : Mismatch in Patch Version"
#endif

/* CRC Version Check */
#if (E2E_CRC_AR_MAJOR_VERSION != CRC_AR_RELEASE_MAJOR_VERSION)
#error "CRC.h : Mismatch in Specification Major Version"
#endif

#if (E2E_CRC_AR_MINOR_VERSION != CRC_AR_RELEASE_MINOR_VERSION)
#error "CRC.h : Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Dummy Function is added for Tasking Compiler Warning */
void E2E_Dummy(void);
void E2E_Dummy(void)
{

}
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

