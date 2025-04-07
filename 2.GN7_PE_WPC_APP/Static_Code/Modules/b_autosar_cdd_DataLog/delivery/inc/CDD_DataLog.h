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
**  SRC-MODULE: CDD_DataLog.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : DataLog CDD                                                   **
**                                                                            **
**  PURPOSE   : Header file for DataLog                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.0.0     06-Apr-2023    MJ.Woo        JIRA CP44-789                       **
** 1.1.2     04-Aug-2022    YH.Han        Redmine #36976                      **
** 1.1.1     16-Dec-2021    MJ.Woo        Redmine #33425                      **
** 1.1.0     09-Jun-2021    MJ.Woo        Redmine #29944, #30055              **
** 1.0.0     17-Nov-2020    MJ.Woo        Redmine #25497                      **
*******************************************************************************/

#ifndef CDD_DATALOG_H
#define CDD_DATALOG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "ComM.h"
#include "EcuM.h"

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define DATALOG_MODULE_ID                    ((uint16)2048)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Instance ID for Det */
#define DATALOG_INSTANCE_ID                  0x00u
/* Service ID for DataLog_MainFunction */
#define DATALOG_MAINFUNCTION_SID             0x00u
/* Service ID for DataLog_ComMMode */
#define DATALOG_COMMODE_SID                  0x01u
/* Service ID for DataLog_SetSleepConditionLog */
#define DATALOG_SETSLEEPCONDITIONLOG_SID     0x06u

/* Det ErrorId */
#define DATALOG_E_SLEEP_DELAY                0x01u
#define DATALOG_E_WAKEUP_DELAY               0x02u
#define DATALOG_E_COMM_MODE                  0x03u
#define DATALOG_E_NVM_MODE                   0x04u
#define DATALOG_E_COMM_CHANNEL_OUT_OF_RANGE  0x05u

/* polyspace-begin MISRA2012:D4.9 [Justified:Low] "For unused parameter" */
#define DATALOG_UNUSED(x)                   do{if((uint32)(x) != 0u) {}}while(0)
/* polyspace-end MISRA2012:D4.9 */

/**
* @addtogroup DATALOG_ESDD_000
* @{ */
/** This is a limitation of DataLog, not ComM. The actual ComM Channel ID can
 *  be 32 or higher, but DataLog only uses up to 31. */
#define DATALOG_COMM_CHANNEL_ID_MAX 31u

/* These items set how long to wait and save logs when
 * "SLEEP transition delay / RUN transition delay after wakeup" occurs.
 * Indicates the number of times DataLog_MainFunction() is called. */
/** Criteria for determining that there is an issue with
 * delayed RUN transition after wakeup
 * Number of times MainFunction is called after wakeup until RUN transition */
#define DATALOG_DELAY_WAKEUP_LIMIT  5u
/** Criteria for determining that there is an issue with
 * delayed SLEEP transition after a SLEEP request
 * Number of times MainFunction is called after a SLEEP request
 * until the BswM Rule is passed */
#define DATALOG_DELAY_SLEEP_LIMIT   50u

/* Bits for Log Data
 *
 * | 31       16 | 15        4 |    3     |     2     |    1    |    0    |
 * | ----------- | ----------- | -------- | --------- | ------- | ------- |
 * | Custom Data | Reserved    | NvM Mode | ComM Mode | Wakeup  | Sleep   |
 * |             |             | Error    | Error     | Delayed | Delayed |
 * | 16bit       | 12bit       | 1bit     | 1bit      | 1bit    | 1bit    |
 */
/** SLEEP state transition is blocked */
#define DATALOG_ERROR_SLEEP_DELAY   0x00000001u
/** RUN state transition after wakeup is blocked */
#define DATALOG_ERROR_WAKEUP_DELAY  0x00000002u
/** Requesting SLEEP while not in COMM_NO_COMMUNICATION */
#define DATALOG_ERROR_COMM_MODE     0x00000004u
/** Requesting SLEEP in the NvM Low Power Prevent state */
#define DATALOG_ERROR_NVM_MODE      0x00000008u

/** This type indicates DataLog is initialized or not */
typedef enum
{
  DATALOG_INIT_NONE,         /**< DataLog is not initialized */
  DATALOG_INIT_COMPLETED,    /**< DataLog is initialized */
} DataLog_InitStatusType;

/** This type indicates Sleep and Wakeup sequence */
typedef enum
{
  DATALOG_SEQ_INIT,          /**< From Power On Reset to before ECU RUN */
  DATALOG_SEQ_SLEEP_REQ,     /**< SLEEP was requested */
  DATALOG_SEQ_SLEEP_DELAYED, /**< SLEEP was requested but not performed */
  DATALOG_SEQ_H2L,           /**< SLEEP condition of BswM has been passed */
  DATALOG_SEQ_L2H,           /**< Wakeup and getting out of SLEEP */
  DATALOG_SEQ_RUN_DELAYED,   /**< Wakeup but state transition to RUN fail */
  DATALOG_SEQ_RUN,           /**< Normal ECU RUN state */
} DataLog_SleepSeqType;

/** This type indicates EcuM Mode */
typedef enum
{
  DATALOG_ECUM_STARTUP,
  DATALOG_ECUM_STARTUP_ONE,
  DATALOG_ECUM_STARTUP_TWO,
  DATALOG_ECUM_STARTUP_THREE,
  DATALOG_ECUM_RUN,
  DATALOG_ECUM_POST_RUN,
  DATALOG_ECUM_SHUTDOWN,
  DATALOG_ECUM_PREP_SHUTDOWN,
  DATALOG_ECUM_SLEEP,
  DATALOG_ECUM_OFF,
  DATALOG_ECUM_RESET,
} DataLog_EcuMModeType;

typedef struct
{
  uint32 ComMMode;           /**< ComM Mode status
                                  - Bit position: Channel ID,
                                  - Value: 1 - FULL_COM or SILENT_COM, 0 - NO_COM */
  boolean LpAllowNvM;        /**< LowPowerAllow status of NvM
                                  - Value: TRUE - ALLOW, FALSE - PREVENT */
  DataLog_EcuMModeType EcuMMode; /**< ECU state */
  EcuM_WakeupSourceType WakeupEvent; /**< Source of Wakeup Event */
  boolean SleepOK;           /**< BswM SLEEP condition passed */
  boolean RunOK;             /**< ECU RUN mode status */
  boolean ViolationComMMode; /**< ComM Mode condition violation */
  boolean ViolationNvMMode;  /**< NvM condition violation */
  DataLog_SleepSeqType SleepSequence; /**< Current Sleep and Wakeup sequence */
  Mcu_ResetType ResetReason; /**< Reset Reason */
} DataLog_DataType;

/** @}  */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DATALOG_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
extern DataLog_DataType DataLog_Data;
#define DATALOG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DATALOG_RMBA_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
extern uint32 DataLog_NvLog;
#define DATALOG_RMBA_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define DATALOG_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint16, DATALOG_CODE) DataLog_GetCustomData(void);
extern FUNC(void, DATALOG_CODE) DataLog_SetCustomData(uint16 customData);
extern FUNC(uint32, DATALOG_CODE) DataLog_GetNvLog(void);
extern FUNC(void, DATALOG_CODE) DataLog_SetNvLog(uint32 nvlog);

extern FUNC(void, DATALOG_CODE) DataLog_SetSleepConditionLog(void);
extern FUNC(void, DATALOG_CODE) DataLog_SetSleepOKLog(void);
extern FUNC(void, DATALOG_CODE) DataLog_SetWakeupEventLog(void);
extern FUNC(void, DATALOG_CODE) DataLog_ComMMode(NetworkHandleType channel,
                                                            ComM_ModeType mode);
extern FUNC(void, DATALOG_CODE) DataLog_NvMLowPowerAllow(boolean allow);
extern FUNC(void, DATALOG_CODE) DataLog_EcuMMode(DataLog_EcuMModeType mode);
extern FUNC(DataLog_SleepSeqType, DATALOG_CODE) DataLog_GetSleepSequence(void);
extern FUNC(void, DATALOG_CODE) DataLog_SetSleepSequence(DataLog_SleepSeqType seq);
#define DATALOG_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CDD_DATALOG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
