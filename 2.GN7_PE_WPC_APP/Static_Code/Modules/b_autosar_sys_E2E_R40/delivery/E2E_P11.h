/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_P11.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Header for E2E Profile 11 driver                              **
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
** 1.2.0    22-Mar-2018    Gongbin Lim     Initial Version                    **
*******************************************************************************/
#ifndef E2E_P11_H
#define E2E_P11_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include for E2E External API's */
#include "E2E.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_P11_H_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_P11_H_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_P11_H_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_P11_H_SW_MAJOR_VERSION                    (1)
#define E2E_P11_H_SW_MINOR_VERSION                    (2)
#define E2E_P11_H_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/
/* Maximum limit of counter value for E2E profile 11 */
#define  E2E_P11_CNT_LIMIT                          ((uint8)0x0F)

/* Maximum value of counter for E2E profile 11 */
#define  E2E_P11_CNT_MAX                            ((uint8)0x0E)

#define E2E_P11_CRC_INIT_VALUE                      ((uint8)0xFF)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Enum E2E_P11DataIDModeType contains DataIDMode for CRC calculation */
typedef enum
{
  /* CRC calculation should be done on both high and low bytes */
  E2E_P11_DATAID_BOTH = 0,

  /* CRC calculation should be done on low byte only */
  E2E_P11_DATAID_NIBBLE = 3
} E2E_P11DataIDMode;

/*
 * Structure E2E_P11ConfigType contains configuration of transmitted data for
 * E2E_Profile 11.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */
typedef struct
{
  /* 
   * Length of Data, in bits.
   *
   * The value shall be a multiple of 8 and shall be <= 240.
   */
  uint16 DataLength;
  
  /* A system-unique identifier of the Data */
  uint16 DataID;
  
  /* 
   * Maximum allowed gap between two counter values of two consecutively
   * received valid Data. For example, if the receiver gets Data with counter 1
   * and MaxDeltaCounter is 3, then at the next reception the receiver can 
   * accept Counters with values 2, 3 or 4.
   */
  uint8 MaxDeltaCounter;
  
  /* Inclusion mode of ID in CRC computation */
  E2E_P11DataIDMode DataIDMode;
  
  /* Bit offset of CRC in MSB first order. The offset shall be a multiple of 8. */
  uint16 CRCOffset;
  
  /* Bit offset of Counter in MSB first order. The offset shall be a multiple of 4. */
  uint16 CounterOffset;
  
  /* Bit offset of the low nibble of the high byte of Data ID. */
  uint16 DataIDNibbleOffset;
  
} E2E_P11ConfigType;

/*
 * Structure E2E_P11ProtectStateType contains state of the sender for a Data
 * protected with E2E Profile 11.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */
typedef struct
{
  /* 
   * Counter to be used for protecting the next Data. The initial value is 0,
   * which means that in the first cycle, Counter is 0. Each time
   * E2E_P11Protect() is called, it increments the counter up to 0xE.
   */ 
  uint8 Counter;
} E2E_P11ProtectStateType;

/*
 * Enum E2E_P05CheckStatusType is for result of the verification of the Data
 * in E2E Profile 5, determined by the Check function.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed
 */
typedef enum
{
  /* 
   * OK: the checks of the Data in this cycle were successful (including counter
   * check, which was incremented by 1). 
   */
  E2E_P11STATUS_OK = 0x0,

  /* 
   * Error: the Check function has been invoked but no new Data is not available
   * since the last call, according to communication medium (e.g. RTE, COM). As
   * a result, no E2E checks of Data have been consequently executed.
   * 
   * This may be considered similar to E2E_P11STATUS_REPEATED.
   */
  E2E_P11STATUS_NONEWDATA = 0x1,

  /* 
   * Error: error not related to counters occurred (e.g. wrong crc, wrong 
   * length).
   */
  E2E_P11STATUS_ERROR = 0x7,

  /* 
   * Error: the checks of the Data in this cycle were successful, with the 
   * exception of the repetition.
   */
  E2E_P11STATUS_REPEATED = 0x8,

  /* 
   * OK: the checks of the Data in this cycle were successful (including counter
   * check, which was incremented within the allowed configured delta). 
   */
  E2E_P11STATUS_OKSOMELOST = 0x20,

  /* 
   * Error: the checks of the Data in this cycle were successful, with the
   * exception of counter jump, which changed more than the allowed delta.
   */ 
  E2E_P11STATUS_WRONGSEQUENCE = 0x40
} E2E_P11CheckStatusType;

/*
 * Structure E2E_P11CheckStateType contains State of the receiver for a Data
 * protected with E2E Profile 11.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed
 */
typedef struct
{
  /* 
   * Result of the verification of the Data in this cycle, determined by the
   * Check function.
   */
  E2E_P11CheckStatusType Status;

  /* Counter of the data in previous cycle. */
  uint8 Counter;
} E2E_P11CheckStateType;

/*******************************************************************************
**                      E2E Profile 11 types                                  **
*******************************************************************************/

/*******************************************************************************
**          Function Prototypes for E2E Profile 11                            **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11Protect (
  P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
  VAR(uint16, AUTOMATIC) Length);

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11ProtectInit (
  P2VAR(E2E_P11ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);
  
extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11Check (
  P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
  P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
  VAR(uint16, AUTOMATIC) Length);

extern FUNC(Std_ReturnType, E2E_CODE) E2E_P11CheckInit (
  P2VAR(E2E_P11CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);
  
extern FUNC(E2E_PCheckStatusType, E2E_CODE) E2E_P11MapStatusToSM (
  VAR(Std_ReturnType, AUTOMATIC) CheckReturn,
  VAR(E2E_P11CheckStatusType, AUTOMATIC) Status);  

/*
static FUNC(uint8, E2E_CODE) E2E_P11CalculateCRC (
  P2CONST(E2E_P11ConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) DataPtr,
  VAR(uint16, AUTOMATIC) Length);
*/

#define E2E_STOP_SEC_CODE
#include "MemMap.h"

#endif /* E2E_P11_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

