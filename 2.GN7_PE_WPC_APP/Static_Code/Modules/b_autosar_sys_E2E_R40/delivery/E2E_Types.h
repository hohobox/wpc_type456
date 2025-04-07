/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Header for E2E Profile types                                  **
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
** 1.1.5    11-May-2017    Gongbin Lim     Changes made as per #8045          **
** 1.1.5    06-Feb-2017    Seongmin Kim    Changes made as per #7714          **
** 1.1.2    04-Oct-2016    Seongmin Kim    Changes made as per #6006, #6007,  **
**                                           and #6158                        **
** 1.1.1    19-Jul-2016    Seongmin Kim    Change made as per #5576           **
** 1.1.0    14-Mar-2016    Seongmin Kim    Changes made as per #4296, #4342,  **
**                                           #4344, and #4391                 **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/
#ifndef E2E_TYPES_H
#define E2E_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_TYPES_H_AR_RELEASE_MAJOR_VERSION         (4)
#define E2E_TYPES_H_AR_RELEASE_MINOR_VERSION         (2)
#define E2E_TYPES_H_AR_RELEASE_REVISION_VERSION      (2)

/* FILE VERSION INFORMATION */
#define E2E_TYPES_SW_MAJOR_VERSION                   (1)
#define E2E_TYPES_SW_MINOR_VERSION                   (2)
#define E2E_TYPES_SW_PATCH_VERSION                   (5)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Macro definitions                                     **
*******************************************************************************/
/* Macro for value 0x00 for uint8 */
#define E2E_ZERO                                    ((uint8)0x00)

/* Macro for value 0x00 of uint16 */
#define E2E_HALF_WORD_ZERO                          ((uint16)0x00)

/* Macro for value 0x01 for uint8 */
#define E2E_ONE                                     ((uint8)0x01)

/* Macro for value 0x01 for uint16 */
#define E2E_HALF_WORD_ONE                           ((uint16)0x01)

/* Macro for value 0x02 for uint8 */
#define E2E_TWO                                     ((uint8)0x02)

/* Macro for masking higher nibble */
#define E2E_HIGH_NIBBLE_MASK                        ((uint8)0xF0)

/* Macro for masking lower nibble */
#define E2E_LOW_NIBBLE_MASK                         ((uint8)0x0F)

/* Macro for masking whole byte */
#define E2E_BYTE_MASK                               ((uint16)0xFF)

/* Macro for masking whole byte */
#define E2E_HIGH_BYTE_MASK                          ((uint16)0xFF00)

/* Macro for shifting by 4 */
#define E2E_SHIFT_BY_FOUR                           ((uint8)0x04)

/* Macro for shifting by 8 */
#define E2E_SHIFT_BY_EIGHT                          ((uint16)0x08)

/* Macro for calculating CRC of lenght one */
#define E2E_CRC_LENGTH_ONE                          ((uint32)0x01)

/* Macro for calculating CRC of lenght two */
#define E2E_CRC_LENGTH_TWO                          ((uint32)0x02)

/* Macro for calculating CRC of lenght four */
#define E2E_CRC_LENGTH_FOUR                         ((uint32)0x04)

/* CRC position on zeroth byte */
#define E2E_ZERO_BYTE                               ((uint16)0x00)

/* Macro for dividing value by 4 */
#define E2E_DIVIDE_BY_FOUR                          ((uint16)0x04)

/* Macro for dividing value by 8 */
#define E2E_DIVIDE_BY_EIGHT                         ((uint16)0x08)

/* Macro for checking TRUE value */
#define E2E_TRUE                                    ((boolean)0x01)

/* Macro for checking FALSE value */
#define E2E_FALSE                                   ((boolean)0x00)

/* Macro for Byte one */
#define E2E_BYTE_ONE                                ((uint8)0x01)

/* Minimum data length for E2E Profile 1 */
#define E2E_P01_MIN_DATA_LENGTH_LIMIT               ((uint16)16)

/* Maximmum data length for E2E Profile 1 */
#define E2E_P01_MAX_DATA_LENGTH_LIMIT               ((uint16)240)

/* Minimum data length for E2E Profile 2 */
#define E2E_P02_MIN_DATA_LENGTH_LIMIT               ((uint16)16)

/* Maximmum data length for E2E Profile 2 */
#define E2E_P02_MAX_DATA_LENGTH_LIMIT               ((uint16)2048)

/* Counter value limit for E2E */
#define E2E_CNT_LIMIT                               ((uint8)0x0F)

/* DataId value limit for E2E Profile 1 */
#define E2E_P01_DATAID_LOW_LIMIT                    ((uint16)0xFF)

/* Macro for four bits */
#define E2E_BIT_FOUR                                ((uint8)0x04)

/* Macro for eight bits */
#define E2E_BIT_EIGHT                               ((uint8)0x08)

/* Function completed successfully */
#define E2E_E_OK                                    ((Std_ReturnType)0x00)

/* At least one input pointer is NULL */
#define E2E_E_INPUTERR_NULL                         ((Std_ReturnType)0x13)

/* At least one parameter is wrong */
#define E2E_E_INPUTERR_WRONG                        ((Std_ReturnType)0x17)

/* An internal library error has occured */
#define E2E_E_INTERR                                ((Std_ReturnType)0x19)

/* Any input parameter is invalid */
#define E2E_E_INVALID                               ((Std_ReturnType)0xFF)

/* Function executed in wrong state */
#define E2E_E_WRONGSTATE                            ((Std_ReturnType)0x1A)

/*******************************************************************************
**                      E2E Profile 1 types                                   **
*******************************************************************************/

/* Enum E2E_P01DataIDModeType contains DataIDMode for CRC calculation */
typedef enum
{
  /* CRC calculation should be done on both high and low bytes */
  E2E_P01_DATAID_BOTH = 0,

  /* CRC calculation should be done on either high or low byte */
  E2E_P01_DATAID_ALT = 1,

  /* CRC calculation should be done on low byte only */
  E2E_P01_DATAID_LOW = 2
} E2E_P01DataIDMode;

/*
 * Structure E2E_P01ConfigType contains configuration of transmitted data for
 * E2E_Profile1
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef struct
{
  /* Bit offset of Counter */
  uint16 CounterOffset;

  /* Bit offset of CRC */
  uint16 CRCOffset;

  /* A unique identifier, for protection against masquerading */
  uint16 DataID;

  /* Inclusion mode of ID in CRC computation */
  E2E_P01DataIDMode DataIDMode;

  /* Length of data, in bits */
  uint16 DataLength;

  /*
  ** Inital maximum allowed gap between two counter values of two consecutively
  ** received valid data
  */
  uint8 MaxDeltaCounterInit;
} E2E_P01ConfigType;

/*
 * Structure E2E_P01SenderStateType contains state of the sender for a Data
 * protected with E2E Profile 1.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef struct
{
  /* Counter to be used for protecting the next Data */
  uint8 Counter;
} E2E_P01SenderStateType;

/*
 * Enum E2E_P01ReceiverStatusType is for result of the verification of the Data
 * in E2E Profile 1, determined by the Check function.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef enum
{
  /* The new data has been received according to communication medium */
  E2E_P01STATUS_OK = 0x0,

  /*
   * The Check function has been invoked but no new Data is not available since
   * the last call
   */
  E2E_P01STATUS_NONEWDATA = 0x1,

  /*
   * The data has been received according to communication medium, but the CRC
   * is incorrect
   */
  E2E_P01STATUS_WRONGCRC = 0x2,

  /*
   * This is the first Data since the receiver's initialization or
   * reinitialization
   */
  E2E_P01STATUS_INITIAL = 0x4,

  /*
   * The new data has been received according to communication medium, the CRC
   * is correct, but the Counter is identical to the most recent Data
   * received
   */
  E2E_P01STATUS_REPEATED = 0x8,

  /*
   * some Data in the sequence have been probably lost since the last
   * correct/initial reception
   */
  E2E_P01STATUS_OKSOMELOST = 0x20,

  /*
   * The new data has been received according to communication medium, the CRC
   * is correct, but the Counter Delta is too big
   */
  E2E_P01STATUS_WRONGSEQUENCE = 0x40
} E2E_P01ReceiverStatusType;

/*
 * Structure E2E_P01ReceiverStateType contains State of the receiver for a Data
 * protected with E2E Profile 1.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef struct
{
  /* Counter value most recently received */
  uint8 LastValidCounter;

  /*
   * MaxDeltaCounter specifies the maximum allowed difference between two
   * counter values of consecutively received valid messages
   */
  uint8 MaxDeltaCounter;

  /*
   * If true means that no correct data has been yet received after the
   * receiver initialization or reinitialization
   */
  boolean WaitForFirstData;

  /*
   * Indicates to E2E Library that a new data is available for Library to be
   * checked
   */
  boolean NewDataAvailable;

  /* Number of data (messages) lost since reception of last valid one */
  uint8 LostData;

  /* Result of the verification of the Data, determined by the Check function */
  E2E_P01ReceiverStatusType Status;

} E2E_P01ReceiverStateType;

/*******************************************************************************
**                      E2E Profile 2 types                                   **
*******************************************************************************/

/*
 * Structure E2E_P02ConfigType contains configuration of transmitted data for
 * E2E_Profile2
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef struct
{
  /* Length of data, in bits */
  uint16 DataLength;

  /* Array of Data ID */
  uint8 DataIDList[16];

  /*
   * Initial maximum allowed gap between two counter values of two consecutively
   * received valid data
   */
  uint8 MaxDeltaCounterInit;
} E2E_P02ConfigType;

/*
 * Structure E2E_P02SenderStateType contains state of the sender for a Data
 * protected with E2E Profile 2.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef struct
{
  /* Counter to be used for protecting the next Data */
  uint8 Counter;
} E2E_P02SenderStateType;

/*
 * Enum E2E_P02ReceiverStatusType is for result of the verification of the Data
 * in E2E Profile 2, determined by the Check function.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef enum
{
  /* The new data has been received according to communication medium */
  E2E_P02STATUS_OK = 0x0,

  /*
   * The Check function has been invoked but no new Data is not available since
   * the last call
   */
  E2E_P02STATUS_NONEWDATA = 0x1,

  /*
   * The data has been received according to communication medium, but the CRC
   * is incorrect
   */
  E2E_P02STATUS_WRONGCRC = 0x2,

  /*
   * This is the first Data since the receiver's initialization or
   * reinitialization
   */
  E2E_P02STATUS_INITIAL = 0x4,

  /*
   * The new data has been received according to communication medium, the CRC
   * is correct, but the Counter is identical to the most recent Data received
   */
  E2E_P02STATUS_REPEATED = 0x8,

  /*
   * The new data has been received according to communication medium, the CRC
   * is correct, but the Counter Delta is too big
   */
  E2E_P02STATUS_OKSOMELOST = 0x20,

  /*
   * The new data has been received according to communication medium, the CRC
   * is correct, but the Counter Delta is too big
   */
  E2E_P02STATUS_WRONGSEQUENCE = 0x40
} E2E_P02ReceiverStatusType;

/*
 * Structure E2E_P02ReceiverStateType contains State of the receiver for a Data
 * protected with E2E Profile 2.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI AUTOEVER
 * coding style is not follwed
 */
typedef struct
{
  /* Counter value most recently received */
  uint8 LastValidCounter;

  /*
   * MaxDeltaCounter specifies the maximum allowed difference between two
   * counter values of consecutively received valid messages
   */
  uint8 MaxDeltaCounter;

  /*
   * If true means that no correct data has been yet received after the
   * receiver initialization or reinitialization
   */
  boolean WaitForFirstData;

  /*
   * Indicates to E2E Library that a new data is available for Library to be
   * checked
   */
  boolean NewDataAvailable;

  /* Number of data (messages) lost since reception of last valid one */
  uint8 LostData;

  /* Result of the verification of the Data, determined by the Check function */
  E2E_P02ReceiverStatusType Status;
} E2E_P02ReceiverStateType;

/*******************************************************************************
**                      E2E state machine types                               **
*******************************************************************************/
/* 
 * Enum E2E_P02ReceiverStatusType is Profile-independent status of the 
 * reception on one single Data in one cycle. 
 */
typedef enum
{
  /* 
   * OK: the checks of the Data in this cycle were successful (including counter
   * check).
   */
  E2E_P_OK = 0x00,
  
  /* Data has a repeated counter. */
  E2E_P_REPEATED = 0x01,
  
  /*
   * The checks of the Data in this cycle were successful, with the exception of 
   * counter jump, which changed more than the allowed delta.
   */
  E2E_P_WRONGSEQUENCE = 0x02,
  
  /* 
   * Error not related to counters occurred (e.g. wrong crc, wrong length, wrong
   * Data ID) or the return of the check function was not OK.
   */
  E2E_P_ERROR = 0x03,
  
  /* 
   * No value has been received yet (e.g. during initialization). This is used 
   * as the initialization value for the buffer, it is not returned by any E2E 
   * profile.
   */
  E2E_P_NOTAVAILABLE = 0x04,

  /* No new data is available. */
  E2E_P_NONEWDATA = 0x05
  
} E2E_PCheckStatusType;
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* E2E_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

