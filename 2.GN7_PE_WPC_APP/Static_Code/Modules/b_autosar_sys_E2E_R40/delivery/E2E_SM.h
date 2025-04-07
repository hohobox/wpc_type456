/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E_SM.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : Header for E2E State Machine driver                           **
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
** 1.1.5    18-Jul-2017  Gongbin Lim     Changes made as per #8045            **
** 1.1.5    17-May-2017  Gongbin Lim     Changes made as per #8045            **
*******************************************************************************/
#ifndef E2E_SM_H
#define E2E_SM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include for E2E External API's */
#include "E2E.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_SM_H_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_SM_H_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_SM_H_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_SM_H_SW_MAJOR_VERSION                    (1)
#define E2E_SM_H_SW_MINOR_VERSION                    (2)
#define E2E_SM_H_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Macro Definitions                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*
 * Structure E2E_SMStateType contains state of the protection of a communication
 * channel.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */
 
typedef enum
{
  /* 
   * Communication functioning properly according to E2E, data can be used.
   */
  E2E_SM_VALID = 0x0,
  
  /* 
   * State before E2E_SMCheckInit() is invoked, data cannot be used.
   */
  E2E_SM_DEINIT = 0x1,
  
  /*
   * No data from the sender is available since the initialization,
   * data cannot be used.
   */
  E2E_SM_NODATA = 0x2,
  
  /*
   * There has been some data received since startup, but it is not yet
   * possible use it, data cannot be used.
   */
  E2E_SM_INIT = 0x3,
  
  /*
   * Communication not functioning properly, data cannot be used.
   */
  E2E_SM_INVALID = 0x4,
  
  /*
   * reserved for runtime errors (shall not be ued for any state in future)
   */
  reserved = 0x07
} E2E_SMStateType;

/*
 * Structure E2E_SMConfigType contains configuration of communication channel
 * for exchanging data.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */

typedef struct
{
  /* 
   Size of the monitoring window for the state machine.
   */
  uint8 WindowSize;
 
  /* 
   * Minimal number of checks in which ProfileStatus equal to E2E_P_OK was
   * determined within the last WindowSize checks (for the state E2E_SM_INIT)
   * required to change to state E2E_SM_VALID.
   */
  uint8 MinOkStateInit;
  
  /* 
   * Maximal number of checks in which ProfileStatus equal to E2E_P_ERROR was
   * determined, within the last WindowSize checks (for the state E2E_SM_INIT). 
   */
  uint8 MaxErrorStateInit;
  
  /* 
   * Minimal number of checks in which ProfileStatus equal to E2E_P_OK was
   * determined within the last WindowSize checks (for the state E2E_SM_VALID)
   * required to keep in state E2E_SM_VALID.
   */
  uint8 MinOkStateValid;
  
  /*
   * Maximal number of checks in which ProfileStatus equal to E2E_P_ERROR was
   * determined, within the last WindowSize checks (for the state E2E_SM_VALID)
   .
   */
  uint8 MaxErrorStateValid;
  
  /*
   * Minimum number of checks in which ProfileStatus equal to E2E_P_OK was
   * determined within the last WindowSize checks (for the state E2E_SM_INVALID)
   * required to change to state E2E_SM_VALID.
   */
  uint8 MinOkStateInvalid;
  
  /*
   * Maximal number of checks in which ProfileStatus equal to E2E_P_ERROR was
   * determined, within the last WindowSize checks (for the state E2E_SM_INVALID)
   .
   */
  uint8 MaxErrorStateInvalid;
} E2E_SMConfigType;

/*
 * Structure E2E_SMCheckStateType contains state of the protection of a
 * communication channel.
 * Since this is E2E library so others vendors also can use this so here HYUNDAI
 * AUTOEVER coding style is not follwed.
 */
typedef struct
{
  /* 
   * Pointer to an array, in which the ProfileStatus-es of the last E2Echecks
   * are stored. The array size shall be WindowSize
   */ 
  P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) ProfileStatusWindow;
  
  /*
   * Index in the array, at which the next ProfileStatus is to be written.
   */
  uint8 WindowTopIndex;
  
  /*
   * Count of checks in which ProfileStatus equal to E2E_P_OK was determined,
   * within the last WindowSize checks.
   */
  uint8 OkCount;
  
  /*
   * Count of checks in which ProfileStatus equal to E2E_P_ERROR was determined,
   * within the last WindowSize checks.
   */
  uint8 ErrorCount;
  
  /*
   * The current state in the state machine. The value is not explicitly used in
   * the pseudocode of the state machine, because it is expressed in UML as UML
   * states.
   */
  E2E_SMStateType SMState;
} E2E_SMCheckStateType;

/*******************************************************************************
**                      E2E State Machine types                               **
*******************************************************************************/

/*******************************************************************************
**          Function Prototypes for E2E State Machine                         **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, E2E_CODE) E2E_SMCheck (
  VAR(E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr
  );

extern FUNC(Std_ReturnType, E2E_CODE) E2E_SMCheckInit (
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
  );

/*
static FUNC(void, E2E_CODE) E2E_SMAddStatus (
  VAR(E2E_PCheckStatusType, AUTOMATIC) ProfileStatus,
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
  );

static FUNC(void, E2E_CODE) E2E_SMClearStatus (
  P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
  P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
  );
*/
  
#define E2E_STOP_SEC_CODE
#include "MemMap.h"

#endif /* E2E_SM_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

