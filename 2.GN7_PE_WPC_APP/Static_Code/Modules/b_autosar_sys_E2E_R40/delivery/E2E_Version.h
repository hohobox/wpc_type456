/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_Version.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : C header for E2E_Version                                      **
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
** 1.2.3    22-Jul-2020    Gongbin Lim     Change made as per #24829          **
** 1.2.1    18-Jun-2018    Gongbin Lim     Change made as per #12704          **
** 1.2.0    22-Mar-2018    Gongbin Lim     Changes made as per #11718         **
** 1.1.2    20-Oct-2016    Seongmin Kim    Changes made as per #6006, #6007,  **
**                                           #6008, #6009, #6158, and #6159   **
** 1.1.1    19-Jul-2016    Seongmin Kim    Change made as per #5576           **
** 1.1.0    03-Mar-2016    Seongmin Kim    Change made as per #4296           **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/
#ifndef E2E_VERSION_H
#define E2E_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION */
#define   E2E_AR_RELEASE_MAJOR_VERSION     (4)
#define   E2E_AR_RELEASE_MINOR_VERSION     (2)
#define   E2E_AR_RELEASE_REVISION_VERSION  (2)

/* CRC Major version number */
#define E2E_CRC_AR_MAJOR_VERSION           (4)

/* CRC Minor version number */
#define E2E_CRC_AR_MINOR_VERSION           (0)

/*
 * SOFTWARE VERSION INFORMATION
 * E2E software major version number
 */
#define E2E_SW_MAJOR_VERSION               (1)

/* E2E software minor version number */
#define E2E_SW_MINOR_VERSION               (2)

/* E2E software patch version */
#define E2E_SW_PATCH_VERSION               (5)

/* Module ID for the E2E */
#define E2E_MODULE_ID                      ((uint16)207)

/* Vendor ID for E2E */
#define E2E_VENDOR_ID                      ((uint16)39)

/* Instance ID for E2E */
#define E2E_INSTANCE_ID                    ((uint8)0)

/*******************************************************************************
**                      Macro definition                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* E2E_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

