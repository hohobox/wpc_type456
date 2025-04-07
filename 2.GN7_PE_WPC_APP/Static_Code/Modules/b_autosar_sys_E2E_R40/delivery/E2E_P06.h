/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P06.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Header for E2E Profile 6 driver                               **
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
** 1.2.2    24-Oct-2018    Gongbin Lim     Change made as per #14435          **
** 1.2.1    18-Jun-2018    Gongbin Lim     Change made as per #12704          **
** 1.2.0    22-Mar-2018    Gongbin Lim     Changes made as per #11718         **
** 1.1.5    07-Apr-2017  Gongbin Lim     Changes made as per #8044            **
*******************************************************************************/
#ifndef E2E_P06_H
#define E2E_P06_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include for E2E External API's */
#include "E2E.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P06_H_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P06_H_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P06_H_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P06_H_SW_MAJOR_VERSION                    (1)
#define E2E_P06_H_SW_MINOR_VERSION                    (2)
#define E2E_P06_H_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
/* Maximum value of counter for E2E profile 6 */
#define E2E_P06_CNT_MAX                             ((uint8)0xFF)

/* Counter offset */
#define E2E_P06_CNT_OFS                             ((uint16)0x04)

/* The offset value of high byte of Length */ 
#define E2E_P06_LEN_OFS_HIGH_BYTE                   ((uint16)0x02)

/* The offset value of low byte of Length */ 
#define E2E_P06_LEN_OFS_LOW_BYTE                    ((uint16)0x03)

/* The offset value of high byte of CRC */ 
#define E2E_P06_CRC_OFS_HIGH_BYTE                   ((uint16)0x0)

/* The offset value of low byte of CRC */ 
#define E2E_P06_CRC_OFS_LOW_BYTE                    ((uint16)0x1)

/* The start value for Crc calculation */
#define E2E_P06_CRC_START_VAL                       ((uint16)0xFFFF)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*
 * Structure E2E_P06ConfigType contains configuration of transmitted data for
 * E2E_Profile 6.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */
typedef struct
{
  /* 
   * Bit offset of the first bit of the E2E header from the beginning of the 
   * Data (bit numbering: bit 0 is the least important). The offset shall be
   * a multiple of 8 and 0 ≤ Offset ≤ MaxDataLength-(5*8).
   * Example: If Offset equals 8, then the high byte of the E2E Crc (16 bit) is
   * written to Byte 1, the low Byte is written to Byte 2.
   */
  uint16 Offset;

  /* 
   * Minimal Length of Data, in bits.
   * E2E checks that Length is ≥ MinDataLength.
   * The value shall be = 4096*8 (4kB) and shall be ≥ 5*8 
   */
  uint16 MinDataLength;
  
  /* 
   * Maximal Length of Data, in bits.
   * E2E checks that DataLength is ≤ MaxDataLength.
   * The value shall be = 4096*8 (4kB).
   * MaxDataLength shall be ≥ MinDataLength.
   */
  uint16 MaxDataLength;
  
  /* A system-unique identifier of the Data */
  uint16 DataID;
  
  /* 
   * Maximum allowed gap between two counter values of two consecutively
   * received valid Data. For example, if the receiver gets Data with counter 1
   * and MaxDeltaCounter is 3, then at the next reception the receiver can 
   * accept Counters with values 2, 3 or 4.
   */
  uint8 MaxDeltaCounter;
} E2E_P06ConfigType;

/*
 * Structure E2E_P06ProtectStateType contains state of the sender for a Data
 * protected with E2E Profile 6.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */
typedef struct
{
  /* 
   * Counter to be used for protecting the next Data. The initial value is 0,
   * which means that in the first cycle, Counter is 0. Each time
   * E2E_P06Protect() is called, it increments the counter up to 0xFF.
   * After the maximum value is reached, the next value is 0x0. The overflow
   * is not reported to the caller.
   */ 
  uint8 Counter;
} E2E_P06ProtectStateType;

/*
 * Enum E2E_P06CheckStatusType is for result of the verification of the Data
 * in E2E Profile 6, determined by the Check function.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed
 */
typedef enum
{
  /* 
   * OK: the checks of the Data in this cycle were successful (including counter
   * check, which was incremented by 1). 
   */
  E2E_P06STATUS_OK = 0x0,

  /* 
   * Error: the Check function has been invoked but no new Data is not available
   * since the last call, according to communication medium (e.g. RTE, COM). As
   * a result, no E2E checks of Data have been consequently executed.
   * 
   * This may be considered similar to E2E_P06STATUS_REPEATED.
   */
  E2E_P06STATUS_NONEWDATA = 0x1,

  /* 
   * Error: error not related to counters occurred (e.g. wrong crc, wrong 
   * length).
   */
  E2E_P06STATUS_ERROR = 0x7,

  /* 
   * Error: the checks of the Data in this cycle were successful, with the 
   * exception of the repetition.
   */
  E2E_P06STATUS_REPEATED = 0x8,

  /* 
   * OK: the checks of the Data in this cycle were successful (including counter
   * check, which was incremented within the allowed configured delta). 
   */
  E2E_P06STATUS_OKSOMELOST = 0x20,

  /* 
   * Error: the checks of the Data in this cycle were successful, with the
   * exception of counter jump, which changed more than the allowed delta.
   */ 
  E2E_P06STATUS_WRONGSEQUENCE = 0x40
} E2E_P06CheckStatusType;

/*
 * Structure E2E_P06CheckStateType contains State of the receiver for a Data
 * protected with E2E Profile 6.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed
 */
typedef struct
{
  /* 
   * Result of the verification of the Data in this cycle, determined by the
   * Check function.
   */
  E2E_P06CheckStatusType Status;

  /* Counter of the data in previous cycle. */
  uint8 Counter;
} E2E_P06CheckStateType;

/*******************************************************************************
**                      E2E Profile 6 types                                   **
*******************************************************************************/

/*******************************************************************************
**          Function Prototypes for E2E Profile 6                             **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P06Protect (
  P2CONST(E2E_P06ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_P06ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
  VAR(uint16, AUTOMATIC) Length);

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P06ProtectInit (
  P2VAR(E2E_P06ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);
  
extern FUNC(Std_ReturnType, E2E_CODE) E2E_P06Check (
  P2CONST(E2E_P06ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
  P2VAR(E2E_P06CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
  VAR(uint16, AUTOMATIC) Length);

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P06CheckInit (
  P2VAR(E2E_P06CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);
  
extern FUNC(E2E_PCheckStatusType, E2E_CODE) E2E_P06MapStatusToSM (
  VAR(Std_ReturnType, AUTOMATIC) CheckReturn,
  VAR(E2E_P06CheckStatusType, AUTOMATIC) Status);  

/*
static FUNC(uint16, E2E_CODE) E2E_P06CalculateCRC (
  P2CONST(E2E_P06ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
  VAR(uint16, AUTOMATIC) Length);
*/

#define E2E_STOP_SEC_CODE
#include "MemMap.h"

#endif /* E2E_P06_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

