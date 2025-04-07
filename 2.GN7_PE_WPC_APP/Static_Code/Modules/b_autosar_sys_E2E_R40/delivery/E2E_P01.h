/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P01.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Header for E2E Profile 1 driver                               **
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
** 1.1.3    07-Dec-2016    Seongmin Kim    Changes made as per #6489 and #6886**
** 1.1.2    12-Sep-2016    Seongmin Kim    Change made as per #6006           **
** 1.1.0    08-Mar-2016    Hoi-Min Kim     Changes made as per #3543, #4296,  **
**                         Seongmin Kim      and #4342                        **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/
#ifndef E2E_P01_H
#define E2E_P01_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include for E2E External API's */
#include "E2E.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P01_H_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P01_H_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P01_H_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P01_H_SW_MAJOR_VERSION                    (1)
#define E2E_P01_H_SW_MINOR_VERSION                    (2)
#define E2E_P01_H_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/* Maximum limit of counter value for E2E profile 1*/
#define  E2E_P01_CNT_LIMIT                          ((uint8)0x0F)

/* Maximum value of counter for E2E profile 1 */
#define  E2E_P01_CNT_MAX                            ((uint8)0x0E)

#define E2E_P01_CRC_XOR_VALUE                       ((uint8)0xFF)

#define E2E_P01_CRC_INIT_VALUE                      ((uint8)0xFF)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      E2E Profile 1 types                                   **
*******************************************************************************/

/*******************************************************************************
**          Function Prototypes for E2E Profile 1                             **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P01Protect (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
  P2VAR(E2E_P01SenderStateType, AUTOMATIC, E2E_APPL_DATA) State,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data);

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P01Check (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_APPL_DATA) Config,
  P2VAR(E2E_P01ReceiverStateType, AUTOMATIC, E2E_APPL_DATA) State,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) Data);

/*
static FUNC(uint8, E2E_CODE) E2E_P01CalculateCRC (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_VAR) Config,
  VAR(uint8, AUTOMATIC) Counter,
  P2VAR(uint8, AUTOMATIC, E2E_VAR) Data);

static FUNC(void, E2E_CODE) E2E_P01CheckStatus (
  P2CONST(E2E_P01ConfigType, AUTOMATIC, E2E_VAR) Config,
  P2VAR(E2E_P01ReceiverStateType, AUTOMATIC, E2E_VAR) State,
  VAR(uint8, AUTOMATIC) Counter);
*/

#define E2E_STOP_SEC_CODE
#include "MemMap.h"

#endif /* E2E_P01_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

