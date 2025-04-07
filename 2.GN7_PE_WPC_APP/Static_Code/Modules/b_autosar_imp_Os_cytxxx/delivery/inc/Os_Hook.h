/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Hook.h                                                     **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS Improvement Code                                   **
**                                                                            **
**  PURPOSE   : Header file for Os Hook containing the declaration of error   **
**              information                                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.1.3     23-Feb-2023    JC.Kim        Redmine #39008                      **
** 1.0.0     18-Feb-2020    MJ.Woo        Redmine #20864                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:D4.5 [Not a Defect] "Declare a name _VAR because it is same with VAR" */

#ifndef OS_HOOK_H
#define OS_HOOK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "Os_ErrorExternal.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define SZ_OSERROR 8
#define MASK_OSERROR_BUF 0x7
#define OS_FAULT_STRUCT1_BASE 0x40210100UL
#define OS_FAULT_STRUCT1_REG ((volatile OS_FAULT_STRUCT*)OS_FAULT_STRUCT1_BASE)

/** OS Error code redefine for easy to see in debugger */
typedef enum
{
  _E_OK = E_OK,
  _E_OS_ACCESS = E_OS_ACCESS,       /* Access to the service/object denied */
  _E_OS_CALLEVEL = E_OS_CALLEVEL,   /* Access to the service from
                                       the ISR is not permitted */
  _E_OS_ID = E_OS_ID,               /* Object ID is invalid */
  _E_OS_LIMIT = E_OS_LIMIT,         /* Limit of services/objects exceeded */
  _E_OS_NOFUNC = E_OS_NOFUNC,       /* The object is not used,
                                       service rejected */
  _E_OS_RESOURCE = E_OS_RESOURCE,   /* Task still occupies resource */
  _E_OS_STATE = E_OS_STATE,         /* The state of the object is not correct
                                       for the required service */
  _E_OS_VALUE = E_OS_VALUE,         /* Value outside of the admissible limit */
  _E_OS_SERVICEID = E_OS_SERVICEID, /* Service can not be called */
  _E_OS_ILLEGAL_ADDRESS = E_OS_ILLEGAL_ADDRESS, /* An invalid address is given
                                                  as a parameter to a service */
  _E_OS_MISSINGEND = E_OS_MISSINGEND,   /* Tasks terminates without a
                                          TerminateTask() or ChainTask() call */
  _E_OS_DISABLEDINT = E_OS_DISABLEDINT, /* A service of the OS is called inside
                                           an interrupt disable/enable pair */
  _E_OS_CORE = E_OS_CORE,          /* The OS API is not allowed between cores */
  _E_OS_INTERFERENCE_DEADLOCK = E_OS_INTERFERENCE_DEADLOCK, /* The spinlock
                                      referred by the parameter SpinlockID is
                             already occupied by a TASK/ISR2 on the same core */
  _E_OS_NESTING_DEADLOCK = E_OS_NESTING_DEADLOCK, /* A TASK tries to occupy the
                                    spinlock while holding a different spinlock
                                           in a way that may cause a deadlock */
  _E_OS_SPINLOCK = E_OS_SPINLOCK,  /* This error means de-scheduling with
                                                           occupied spinlock. */
  _E_OS_PARAM_POINTER = E_OS_PARAM_POINTER, /* A pointer argument of an API is
                                                                 NULL pointer */
  _E_OS_STACKFAULT = E_OS_STACKFAULT,       /* A stack fault detected via
                                                   stack monitoring by the OS */
  _E_OS_PROTECTION_MEMORY = E_OS_PROTECTION_MEMORY, /* A memory access
                                                         violation occurred */
  _E_OS_PROTECTION_TIME = E_OS_PROTECTION_TIME, /* A Task/Category 2 ISR exceeds
                                                    its execution time budget */
  _E_OS_PROTECTION_LOCKED = E_OS_PROTECTION_LOCKED, /* A Task/Category 2 ISR
                                                          blocks for too long */
  _E_OS_PROTECTION_EXCEPTION = E_OS_PROTECTION_EXCEPTION,  /* A trap occurred */
  _E_OS_PROTECTION_ARRIVAL = E_OS_PROTECTION_ARRIVAL, /* A Task/Category 2 ISR
                                                        arrives before its
                                                        timeframe has expired */
  /* Implementation specific error codes */
  _E_OS_SYS_ALARM_INUSE = E_OS_SYS_ALARM_INUSE,/* Counter interrupt is nested */
  _E_OS_SYS_RAMECC = E_OS_SYS_RAMECC, /* An ECC error has occurred on the RAM */
  _E_OS_SYS_DFLASHECC = E_OS_SYS_DFLASHECC, /* An ECC error has occurred
                                                            on the Data Flash */
  _E_OS_SYS_PFLASHECC = E_OS_SYS_PFLASHECC, /* An ECC error has occurred
                                                         on the Program Flash */
  _E_OS_SYS_CORE_IS_DOWN = E_OS_SYS_CORE_IS_DOWN, /* This error code means that
                                              the core is shutting down state */
  _E_OS_SYS_PANIC = E_OS_SYS_PANIC,       /* OS fatal error: Assertion failed */
  _E_OS_SYS_NMI = E_OS_SYS_NMI,           /* This error code means that
                                                        NMI handling is fault */
  _E_OS_SYS_INTERCOREMSG = E_OS_SYS_INTERCOREMSG, /* A problem occurred during
                                           the inter-core API request process */
} Os_ErrorValueType;

/** OS Service id redefine for easy to see in debugger */
typedef enum
{
  _StartOS = OSServiceId_StartOS,
  _ShutdownOS = OSServiceId_ShutdownOS,
  _GetActiveApplicationMode = OSServiceId_GetActiveApplicationMode,

  /* memory protection services */
  _CallTrustedFunction = OSServiceId_CallTrustedFunction,
  _CheckISRMemoryAccess = OSServiceId_CheckISRMemoryAccess,
  _CheckTaskMemoryAccess = OSServiceId_CheckTaskMemoryAccess,

  /* OS-Application services */
  _GetApplicationID = OSServiceId_GetApplicationID,
  _CheckObjectAccess = OSServiceId_CheckObjectAccess,
  _CheckObjectOwnership = OSServiceId_CheckObjectOwnership,
  _TerminateApplication = OSServiceId_TerminateApplication,
  _AllowAccess = OSServiceId_AllowAccess,
  _GetApplicationState = OSServiceId_GetApplicationState,

  _ShutdownAllCores = OSServiceId_ShutdownAllCores,

  /* task management services */
  _ActivateTask = OSServiceId_ActivateTask,
  _TerminateTask = OSServiceId_TerminateTask,
  _ChainTask = OSServiceId_ChainTask,
  _Schedule = OSServiceId_Schedule,
  _GetTaskID = OSServiceId_GetTaskID,
  _GetTaskState = OSServiceId_GetTaskState,

  /* interrupt handling services */
  _ResumeAllInterrupts = OSServiceId_ResumeAllInterrupts,
  _SuspendAllInterrupts = OSServiceId_SuspendAllInterrupts,
  _ResumeOSInterrupts = OSServiceId_ResumeOSInterrupts,
  _SuspendOSInterrupts = OSServiceId_SuspendOSInterrupts,
  _EnableAllInterrupts = OSServiceId_EnableAllInterrupts,
  _DisableAllInterrupts = OSServiceId_DisableAllInterrupts,
  _GetISRID = OSServiceId_GetISRID,

  /* resource management services */
  _GetResource = OSServiceId_GetResource,
  _ReleaseResource = OSServiceId_ReleaseResource,

  /* event control services */
  _SetEvent = OSServiceId_SetEvent,
  _ClearEvent = OSServiceId_ClearEvent,
  _GetEvent = OSServiceId_GetEvent,
  _WaitEvent = OSServiceId_WaitEvent,

  /* counter services */
  _IncrementCounter = OSServiceId_IncrementCounter,
  _GetCounterValue = OSServiceId_GetCounterValue,
  _GetElapsedValue = OSServiceId_GetElapsedValue,
  /* alarms services */
  _GetAlarmBase = OSServiceId_GetAlarmBase,
  _GetAlarm = OSServiceId_GetAlarm,
  _SetRelAlarm = OSServiceId_SetRelAlarm,
  _SetAbsAlarm = OSServiceId_SetAbsAlarm,
  _CancelAlarm = OSServiceId_CancelAlarm,

  /* schedule table services */
  _StartScheduleTableAbs = OSServiceId_StartScheduleTableAbs,
  _StartScheduleTableRel = OSServiceId_StartScheduleTableRel,
  _StopScheduleTable = OSServiceId_StopScheduleTable,
  _NextScheduleTable = OSServiceId_NextScheduleTable,
  _SyncScheduleTable = OSServiceId_SyncScheduleTable,
  _SetScheduleTableAsync = OSServiceId_SetScheduleTableAsync,
  _GetScheduleTableStatus = OSServiceId_GetScheduleTableStatus,
  _StartScheduleTableSynchron = OSServiceId_StartScheduleTableSynchron,

  /* multi-core services */
  _GetSpinlock = OSServiceId_GetSpinlock,
  _TryToGetSpinlock = OSServiceId_TryToGetSpinlock,
  _ReleaseSpinlock = OSServiceId_ReleaseSpinlock,
  _GetCoreID = OSServiceId_GetCoreID,
  _StartCore = OSServiceId_StartCore,

  /* No API service (e.g. Stack Monitoring) */
  _NoAPI = OS_INVALID_VALUE,
} Os_ErrorApiType;

/** FAULT STRUCT Driver errors redefine for easy to see in debugger */
typedef enum 
{
    _E_OS_SYSFLT_CPUSS_MPU_VIO_0                         = 0x0000u,    /**< CM0+ MPU/SMPU violation */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_1                         = 0x0001u,    /**< CRYPTO MPU/SMPU violation */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_2                         = 0x0002u,    /**< DW0 MPU/SMPU violation */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_3                         = 0x0003u,    /**< DW1 MPU/SMPU violation */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_4                         = 0x0004u,    /**< Bus master #4 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_5                         = 0x0005u,    /**< Bus master #5 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_9                         = 0x0009u,    /**< Bus master #9 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_10                        = 0x000Au,    /**< Bus master #10 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_13                        = 0x000Du,    /**< Bus master #13 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_14                        = 0x000Eu,    /**< Bus master #14 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_MPU_VIO_15                        = 0x000Fu,    /**< Bus master #15 MPU/SMPU violation (when used) */
    _E_OS_SYSFLT_CPUSS_CM7_1_TCM_C_ECC                   = 0x0010u,    /**< Correctable ECC error in CM7_1 TCM memory. See CM7_0_TCM_C_ECC descripption. */
    _E_OS_SYSFLT_CPUSS_CM7_1_TCM_NC_ECC                  = 0x0011u,    /**< Non Correctable ECC error in CM7_1 TCM memory. See CM7_0_TCM_C_ECC descripption. */
    _E_OS_SYSFLT_CPUSS_CM7_0_CACHE_C_ECC                 = 0x0012u,    /**< Correctable ECC error in CM7_0 Cache memories
                                                                            DATA0[16:2]: location information: Tag/Data SRAM, Way, Index and  line Offset, see CM7 UGRM IEBR0/DEBR0 description for details. 
                                                                            DATA0[31]: 0=Instruction cache, 1= Data cache */
    _E_OS_SYSFLT_CPUSS_CM7_0_CACHE_NC_ECC                = 0x0013u,    /**< Non Correctable ECC error in CM7_0 Cache memories. See CM7_0_CACHE_C_ECC descripption */
    _E_OS_SYSFLT_CPUSS_CM7_1_CACHE_C_ECC                 = 0x0014u,    /**< Correctable ECC error in CM7_1 Cache memories. See CM7_0_CACHE_C_ECC descripption. */
    _E_OS_SYSFLT_CPUSS_CM7_1_CACHE_NC_ECC                = 0x0015u,    /**< Non Correctable ECC error in CM7_1 Cache memories. See CM7_0_CACHE_C_ECC descripption. */
    _E_OS_SYSFLT_PERI_MS_VIO_4                           = 0x0019u,    /**< Peripheral interconnect, master interface 4 PPU. See MS_PPU_0 description. */
    _E_OS_SYSFLT_PERI_PERI_C_ECC                         = 0x001Au,    /**< Peri protection SRAM correctable ECC violation */
    _E_OS_SYSFLT_PERI_PERI_NC_ECC                        = 0x001Bu,    /**< Peri protection SRAM non-correctable ECC violation */
    _E_OS_SYSFLT_PERI_MS_VIO_0                           = 0x001Cu,    /**< CM0+ Peripheral Master Interface PPU violation */
    _E_OS_SYSFLT_PERI_MS_VIO_1                           = 0x001Du,    /**< CM7_0 Peripheral Master Interface PPU violation */
    _E_OS_SYSFLT_PERI_MS_VIO_2                           = 0x001Eu,    /**< CM7_1 Peripheral Master Interface PPU violation */
    _E_OS_SYSFLT_PERI_MS_VIO_3                           = 0x001Fu,    /**< DW0 Peripheral Master Interface PPU violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_0                        = 0x0020u,    /**< Peripheral group #0 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_1                        = 0x0021u,    /**< Peripheral group #1 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_2                        = 0x0022u,    /**< Peripheral group #2 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_3                        = 0x0023u,    /**< Peripheral group #3 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_4                        = 0x0024u,    /**< Peripheral group #4 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_5                        = 0x0025u,    /**< Peripheral group #5 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_6                        = 0x0026u,    /**< Peripheral group #6 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_8                        = 0x0028u,    /**< Peripheral group #8 violation */
    _E_OS_SYSFLT_PERI_GROUP_VIO_9                        = 0x0029u,    /**< Peripheral group #9 violation */
    _E_OS_SYSFLT_CPUSS_FLASHC_MAIN_BUS_ERR               = 0x0030u,    /**< Flash controller main flash bus error */
    _E_OS_SYSFLT_CPUSS_FLASHC_MAIN_C_ECC                 = 0x0031u,    /**< Flash controller main flash correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FLASHC_MAIN_NC_ECC                = 0x0032u,    /**< Flash controller main flash non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FLASHC_WORK_BUS_ERR               = 0x0033u,    /**< Flash controller work flash bus error */
    _E_OS_SYSFLT_CPUSS_FLASHC_WORK_C_ECC                 = 0x0034u,    /**< Flash controller work flash correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FLASHC_WORK_NC_ECC                = 0x0035u,    /**< Flash controller work flash non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FLASHC_CM0_CA_C_ECC               = 0x0036u,    /**< Flash controller CM0+ cache correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FLASHC_CM0_CA_NC_ECC              = 0x0037u,    /**< Flash controller CM0+ cache non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_CM7_0_TCM_C_ECC                   = 0x0038u,    /**< Correctable ECC error in CM7_0 TCM memory
                                                                            DATA0[23:2]: Violating address.
                                                                            DATA1[7:0]: Syndrome of code word (at address offset 0x0).
                                                                            DATA1[31:30]: 0= ITCM, 2=D0TCM, 3=D1TCM */
    _E_OS_SYSFLT_CPUSS_CM7_0_TCM_NC_ECC                  = 0x0039u,    /**< Non Correctable ECC error in CM7_0 TCM memory. See CM7_0_TCM_C_ECC descripption. */
    _E_OS_SYSFLT_CPUSS_RAMC0_C_ECC                       = 0x003Au,    /**< System SRAM 0 correctable ECC error:
                                                                            DATA0[31:0]: Violating address.
                                                                            DATA1[6:0]: Syndrome of 32-bit SRAM code word. */
    _E_OS_SYSFLT_CPUSS_RAMC0_NC_ECC                      = 0x003Bu,    /**< System memory controller 0 non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_RAMC1_C_ECC                       = 0x003Cu,    /**< System memory controller 1 correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_RAMC1_NC_ECC                      = 0x003Du,    /**< System memory controller 1 non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_RAMC2_C_ECC                       = 0x003Eu,    /**< System memory controller 2 correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_RAMC2_NC_ECC                      = 0x003Fu,    /**< System memory controller 2 non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_CRYPTO_C_ECC                      = 0x0040u,    /**< Crypto memory correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_CRYPTO_NC_ECC                     = 0x0041u,    /**< Crypto memory non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_DW0_C_ECC                         = 0x0046u,    /**< DataWire 0 SRAM 1 correctable ECC error:
                                                                            DATA0[11:0]: Violating DW SRAM address (word address, assuming byte addressible).
                                                                            DATA1[6:0]: Syndrome of 32-bit SRAM code word. */
    _E_OS_SYSFLT_CPUSS_DW0_NC_ECC                        = 0x0047u,    /**< Datawire0 memory non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_DW1_C_ECC                         = 0x0048u,    /**< Datawire1 memory correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_DW1_NC_ECC                        = 0x0049u,    /**< Datawire1 memory non-correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FM_SRAM_C_ECC                     = 0x004Au,    /**< Flash code storage sram memory correctable ECC violation */
    _E_OS_SYSFLT_CPUSS_FM_SRAM_NC_ECC                    = 0x004Bu,    /**< Flash code storage sram memory non-correctable ECC violation */
    _E_OS_SYSFLT_CANFD_0_CAN_C_ECC                       = 0x0050u,    /**< CAN0 message buffer correctable ECC violation */
    _E_OS_SYSFLT_CANFD_0_CAN_NC_ECC                      = 0x0051u,    /**< CAN0 message buffer non-correctable ECC violation */
    _E_OS_SYSFLT_CANFD_1_CAN_C_ECC                       = 0x0052u,    /**< CAN1 message buffer correctable ECC violation */
    _E_OS_SYSFLT_CANFD_1_CAN_NC_ECC                      = 0x0053u,    /**< CAN1 message buffer non-correctable ECC violation */
    _E_OS_SYSFLT_SRSS_FAULT_CSV                          = 0x005Au,    /**< SRSS Clock SuperVisor (CSV) violation detected. Multiple CSV can detect a violation at the same time.
                                                                            DATA0[15:0]: clk_hf* root CSV violation flags.
                                                                            DATA0[24]: clk_ref CSV violation flag (reference clock for clk_hf CSVs)
                                                                            DATA0[25]: clk_lf CSV violation flag
                                                                            DATA0[26]: clk_hvilo CSV violation flag */
    _E_OS_SYSFLT_SRSS_FAULT_SSV                          = 0x005Bu,    /**< SRSS Clock SuperVisor (CSV) violation detected. Multiple CSV can detect a violation at the same time.
                                                                            DATA0[0]: BOD on VDDA
                                                                            DATA[1]: OVD on VDDA
                                                                            DATA[16]: LVD/HVD #1
                                                                            DATA0[17]: LVD/HVD #2 */
    _E_OS_SYSFLT_SRSS_FAULT_MCWDT0                       = 0x005Cu,    /**< Fault output for MCWDT0 (all sub-counters) */
    _E_OS_SYSFLT_SRSS_FAULT_MCWDT1                       = 0x005Du,    /**< Fault output for MCWDT1 (all sub-counters) */
    _E_OS_SYSFLT_SRSS_FAULT_MCWDT2                       = 0x005Eu,    /**< Fault output for MCWDT2 (all sub-counters) */
	  _E_OS_SYSFLT_NO_FAULT
} OS_FaultStructErrorType;

/** This structure is defined for member variable of union OS_FAULT_STRUCT_INTR */
typedef struct
{
  uint32 OS_u1FAULT:1;
  uint32 OS_RESERVED:31;
} OS_FAULT_STRUCT_INTR_field;

/** This structure is defined for member variable of union OS_FAULT_STRUCT_STATUS */
typedef struct
{
  uint32 OS_u7IDX:7;
  uint32 OS_RESERVED:24;
  uint32 OS_u1VALID:1;
} OS_FAULT_STRUCT_STATUS_field;

/* polyspace-begin MISRA-C3:19.2 [Not a defect:Low] "These unions are used for debugging purposes only" */
/** This union is defined for first parameter of OS API */
typedef union
{
  AlarmType OsAlarmId;
  ApplicationType OsApplicationId;
  CounterType OsCounterId;
  ResourceType OsResourceId;
  TaskType OsTaskId;
  ScheduleTableType OsScheduleTableId;
  ScheduleTableType OsScheduleTableId_From;
  TrustedFunctionIndexType OsTrustedFunctionIndexId;
  EventMaskType OsMask;
  SpinlockIdType OsSpinlockId;
} Os_ParamBlockType1;

/** This union is defined for second parameter of OS API */
typedef union
{
  ScheduleTableType OsScheduleTableId_To;
  TickType OsValue;
  P2VAR(void, AUTOMATIC, OS_VAR) OsTrustedFunctionParams;
  RestartType OsRestartOption;
  EventMaskType OsMaskParam2;
  TickType OsIncrement;
  TickType OsOffset;
  TickType OsStart;
} Os_ParamBlockType2;

/** This union is defined for third parameter of OS API */
typedef union
{
  TickType OsCycle;
} Os_ParamBlockType3;

/** This union is defined for member variable of structure OS_FAULT_STRUCT */
typedef union
{
  uint32 OS_u32Register;
  OS_FAULT_STRUCT_INTR_field OS_stcField;
  uint8 OS_au8Byte[4];
  uint16 OS_au16Halfword[2];
} OS_FAULT_STRUCT_INTR;

/** This union is defined for member variable of structure OS_FAULT_STRUCT */
typedef union
{
  uint32 OS_u32Register;
  OS_FAULT_STRUCT_STATUS_field OS_stcField;
  uint8 OS_au8Byte[4];
  uint16 OS_au16Halfword[2];
} OS_FAULT_STRUCT_STATUS;
/* polyspace-end MISRA-C3:19.2 */

/** This structure is defined for OS error information type */
typedef struct
{
  Os_ErrorApiType enApi;       /**< OS API name */
  Os_ErrorValueType enErrorNo; /**< Error reason */
  Os_ParamBlockType1 unPar1;   /**< OS API first parameter */
  Os_ParamBlockType2 unPar2;   /**< OS API second parameter */
  Os_ParamBlockType3 unPar3;   /**< OS API third parameter */
} Os_ErrorType;

/** This structure is defined for Fault structures */
typedef struct
{
  uint32 OS_RESERVED0[3];
  OS_FAULT_STRUCT_STATUS OS_unSTATUS;      /**< 0x0000000C Fault status */
  uint32 OS_RESERVED1[44];
  OS_FAULT_STRUCT_INTR OS_unINTR;          /**< 0x000000C0 Interrupt */
  uint32 OS_RESERVED2[15];
} OS_FAULT_STRUCT;                         /**< Size = 256 (0x100) */

#define OS_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
extern VAR(uint32, OS_VAR) GulOsErrorCount;
extern VAR(uint32, OS_VAR) GulOsErrorLastPosition;
extern VAR(uint32, OS_VAR) Os_GulOsLimitError;
extern VAR(uint32, OS_VAR) Os_GulOsStackFaultError;
#define OS_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Os_ErrorType, OS_VAR) GucOsError[SZ_OSERROR];
#define OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, OS_CODE) Os_UpdateOsErrorInfo(StatusType LddError);
extern FUNC(void, OS_CALLOUT_CODE) AppCallbackOnSystemError(StatusType ErrorId);
extern FUNC(void, OS_CODE) Os_PreFaultStructureInitCallout(void);
#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* OS_HOOK_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-end MISRA-C3:D4.5 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

