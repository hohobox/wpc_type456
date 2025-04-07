/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Header for global data types and function prototypes          **
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
** 1.1.3    22-Dec-2016    Seongmin Kim    Changes made as per #6490 and #6886**
** 1.1.0    08-Mar-2016    Seongmin Kim    Changes made as per #3554, #4296,  **
**                                           and #4342                        **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/
#ifndef E2E_H
#define E2E_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Standard types header file */
#include "Std_Types.h"
#include "E2E_Version.h"
#include "E2E_Types.h"
#include "Crc.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_H_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_H_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_H_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_H_SW_MAJOR_VERSION                    (1)
#define E2E_H_SW_MINOR_VERSION                    (2)
#define E2E_H_SW_PATCH_VERSION                    (5)
/*******************************************************************************
**                      Macro definitions                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define E2E_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, E2E_CODE) E2E_GetVersionInfo (
  P2VAR(Std_VersionInfoType, AUTOMATIC, E2E_APPL_DATA) VersionInfo);

extern FUNC(uint8, E2E_CODE) E2E_UpdateCounter (VAR(uint8, AUTOMATIC) Counter);

extern FUNC(uint8, E2E_CODE) E2E_CRC8u8 (P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8u16 (P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8u32 (P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8u8Array (
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8u16Array (
  P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8u32Array (
  P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu8 (P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu16 (P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu32 (P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC)  E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu8Array (
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu16Array (
  P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue);

extern FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu32Array (
  P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue);

#define E2E_STOP_SEC_CODE
#include "MemMap.h"

#endif /* E2E_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

