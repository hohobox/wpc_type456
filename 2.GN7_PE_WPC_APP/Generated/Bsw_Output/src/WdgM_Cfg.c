/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**  FILE-NAME: WdgM_Cfg.c                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR Watchdog Manager Module                              **
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Generation Tool Information                           **
*******************************************************************************/
/*
**  Tool Version: 1.2.21                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            */

/*******************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:    Configuration\ECU\Ecud_Dem.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_WdgIf.arxml
 *                Configuration\ECU\Ecud_WdgM.arxml
 *                Configuration\ECU\Mcal\Ecud_Mcu.arxml
 * GENERATED ON: The time-stamp is removed
 */

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.1 [Not a Defect] "see MEMMAP003 of AUTOSAR" */
/* polyspace-begin MISRA-C3:2.2 [Not a Defect] "some macro provided by MCAL" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Cfg.h"
#include "WdgM_PCTypes.h"
#include "WdgM_GenExterns.h"
#include "WdgM_Version.h"
#include "Rte_WdgM.h"
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define WDGM_CFG_C_AR_RELEASE_MAJOR_VERSION                (4)
#define WDGM_CFG_C_AR_RELEASE_MINOR_VERSION                (0)
#define WDGM_CFG_C_AR_RELEASE_REVISION_VERSION             (3)
#define WDGM_CFG_C_SW_MAJOR_VERSION                        (1)
#define WDGM_CFG_C_SW_MINOR_VERSION                        (2)
#define WDGM_CFG_C_SW_PATCH_VERSION                        (21)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDGM_VERSION_AR_RELEASE_MAJOR_VERSION != \
  WDGM_CFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "WdgM_Cfg.c : Mismatch in Specification Major Version"
#endif

#if (WDGM_VERSION_AR_RELEASE_MINOR_VERSION != \
  WDGM_CFG_C_AR_RELEASE_MINOR_VERSION)
  #error "WdgM_Cfg.c : Mismatch in Specification Minor Version"
#endif

#if (WDGM_VERSION_AR_RELEASE_REVISION_VERSION != \
  WDGM_CFG_C_AR_RELEASE_REVISION_VERSION)
  #error "WdgM_Cfg.c : Mismatch in Specification Revision Version"
#endif

#if (WDGM_VERSION_SW_MAJOR_VERSION != WDGM_CFG_C_SW_MAJOR_VERSION)
  #error "WdgM_Cfg.c : Mismatch in Software Major Version"
#endif

#if (WDGM_VERSION_SW_MINOR_VERSION != WDGM_CFG_C_SW_MINOR_VERSION)
  #error "WdgM_Cfg.c : Mismatch in Software Minor Version"
#endif

#if (WDGM_VERSION_SW_PATCH_VERSION != WDGM_CFG_C_SW_PATCH_VERSION)
  #error "WdgM_Cfg.c : Mismatch in Software Patch Version"
#endif


/*******************************************************************************
**                      Internal variables                                    **
*******************************************************************************/

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(CounterType, WDGM_CONST) WdgM_GddOsCounter_0 = OsCounter_0;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Externs for Alive structures */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_AliveSupervisionType, WDGM_CONST) WdgM_GaaMode0AliveSupervision[WDGM_GAAMODE0ALIVESUPERVISION_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_AliveSupervisionType, WDGM_CONST) WdgM_GaaMode1AliveSupervision[WDGM_GAAMODE1ALIVESUPERVISION_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Externs for CheckPoint structures */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_CheckpointGraphType, WDGM_CONST) WdgM_GaaSE300Checkpoints[WDGM_GAASE300CHECKPOINTS_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_CheckpointGraphType, WDGM_CONST) WdgM_GaaSE400Checkpoints[WDGM_GAASE400CHECKPOINTS_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Externs for Dead line structures */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_DeadlineSupervisionType, WDGM_CONST) WdgM_GaaMode1DeadlineSupervision[WDGM_GAAMODE1DEADLINESUPERVISION_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Externs for External Graph structures */
/* Externs for External logic structures */

/* Externs for External graph map array structures */
/* Externs for Internal Map Array */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_CheckpointIdType, WDGM_CONST) WdgM_GaaIntLSGraphSE400MapArray[WDGM_GAAINTLSGRAPHSE400MAPARRAY_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Externs for LocalStatus structures */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_ActiveSEType, WDGM_CONST) WdgM_GaaMode0ActiveSE[WDGM_GAAMODE0ACTIVESE_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_ActiveSEType, WDGM_CONST) WdgM_GaaMode1ActiveSE[WDGM_GAAMODE1ACTIVESE_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Externs for Trigger structures */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_TriggerType, WDGM_CONST) WdgM_GaaMode0Trigger[WDGM_GAAMODE0TRIGGER_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(WdgM_TriggerType, WDGM_CONST) WdgM_GaaMode1Trigger[WDGM_GAAMODE1TRIGGER_TOTAL_COUNT];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(WdgM_ModePropertyType, WDGM_CONST) WdgM_GaaModes[WDGM_TOTAL_MODES] =
{
  /* Mode 0 - 0 */
  {
    /* *pAliveSupervisions */
    WdgM_GaaMode0AliveSupervision,

    /* *pDeadlineSupervisions */
    NULL_PTR,

    /* *pActiveSEList */
    WdgM_GaaMode0ActiveSE,

    /* *pTriggers */
    WdgM_GaaMode0Trigger,

    /* usWdgTrigBlockCount */
    0,

    /* usSupervisionCycle */
    1,

    /* usTotalAliveSupervisions */
    1,

    /* usTotalDeadlineSupervisions */
    0,

    /* ddTotalSEInMode */
    1,

    /* ucTotalTriggers */
    2
  },

  /* Mode 1 - 1 */
  {
    /* *pAliveSupervisions */
    WdgM_GaaMode1AliveSupervision,

    /* *pDeadlineSupervisions */
    WdgM_GaaMode1DeadlineSupervision,

    /* *pActiveSEList */
    WdgM_GaaMode1ActiveSE,

    /* *pTriggers */
    WdgM_GaaMode1Trigger,

    /* usWdgTrigBlockCount */
    2,

    /* usSupervisionCycle */
    1,

    /* usTotalAliveSupervisions */
    1,

    /* usTotalDeadlineSupervisions */
    1,

    /* ddTotalSEInMode */
    1,

    /* ucTotalTriggers */
    2
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(WdgM_SupervisedEntityType, WDGM_CONST)
  WdgM_GaaSupervisedEntity[WDGM_TOTAL_SES] =
{
  /* Supervised entity 0 - 0 */
  {
    /* *pCheckpoint */
    WdgM_GaaSE300Checkpoints,

    /* *pIntLSGraphMapArray */
    NULL_PTR,

    /* *pRteSwitchMode */
    Rte_Switch_mode_SE_Init_currentMode,

    /* ddTotalCheckpoints */
    3,

    /* ddSEId */
    300,

    /* *pCounterID */
    NULL_PTR,

    /* ddILSIndex */
    0x00,

    /* ucSupervisions */
    0x01
  },

  /* Supervised entity 1 - 1 */
  {
    /* *pCheckpoint */
    WdgM_GaaSE400Checkpoints,

    /* *pIntLSGraphMapArray */
    WdgM_GaaIntLSGraphSE400MapArray,

    /* *pRteSwitchMode */
    Rte_Switch_mode_SE_WdgMTest_currentMode,

    /* ddTotalCheckpoints */
    6,

    /* ddSEId */
    400,

    /* *pCounterID */
    &WdgM_GddOsCounter_0,

    /* ddILSIndex */
    0x00,

    /* ucSupervisions */
    0x07
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_AliveSupervisionType, WDGM_CONST) WdgM_GaaMode0AliveSupervision[WDGM_GAAMODE0ALIVESUPERVISION_TOTAL_COUNT] =
{
  /* AliveSupervisionType 0 - 0 */
  {
    /* ddSEId */
    300,

    /* ddSEArrayIndex */
    0,

    /* ddCheckpoint */
    0,

    /* ddExAliveIndications */
    1,

    /* ddSupervisionRefCycle */
    800,

    /* ucExAliveIndMaxMargin */
    0,

    /* ucExAliveIndMinMargin */
    0
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_AliveSupervisionType, WDGM_CONST) WdgM_GaaMode1AliveSupervision[WDGM_GAAMODE1ALIVESUPERVISION_TOTAL_COUNT] =
{
  /* AliveSupervisionType 0 - 0 */
  {
    /* ddSEId */
    400,

    /* ddSEArrayIndex */
    1,

    /* ddCheckpoint */
    0,

    /* ddExAliveIndications */
    10,

    /* ddSupervisionRefCycle */
    10,

    /* ucExAliveIndMaxMargin */
    3,

    /* ucExAliveIndMinMargin */
    5
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* static CONST(WdgM_DeadlineSupervisionType, WDGM_CONST) WdgM_GaaMode0DeadlineSupervision[WDGM_GAAMODE0DEADLINESUPERVISION_TOTAL_COUNT]; */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_DeadlineSupervisionType, WDGM_CONST) WdgM_GaaMode1DeadlineSupervision[WDGM_GAAMODE1DEADLINESUPERVISION_TOTAL_COUNT] =
{
  /* DeadlineSupervisionType 0 - 0 */
  {
    /* ddSEId */
    400,

    /* ddInitialCheckpoint */
    4,

    /* ddFinalCheckpoint */
    5,

    /* ulDeadlineMax */
    20,

    /* ulDeadlineMin */
    0
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* static CONST(WdgM_ExLogicalSupervisionType, WDGM_CONST) WdgM_GaaMode0ExLogicalSupervision[WDGM_GAAMODE0EXLOGICALSUPERVISION_TOTAL_COUNT]; */
/* static CONST(WdgM_ExLogicalSupervisionType, WDGM_CONST) WdgM_GaaMode1ExLogicalSupervision[WDGM_GAAMODE1EXLOGICALSUPERVISION_TOTAL_COUNT]; */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_TriggerType, WDGM_CONST) WdgM_GaaMode0Trigger[WDGM_GAAMODE0TRIGGER_TOTAL_COUNT] =
{
  /* Trigger 0 - 0 */
  {
    /* ddWdgIfMode */
    WDGIF_OFF_MODE,

    /* usWdgIfTimeout */
    500,

    /* ucWdgIfDeviceId */
    1
  },

  /* Trigger 1 - 1 */
  {
    /* ddWdgIfMode */
    WDGIF_SLOW_MODE,

    /* usWdgIfTimeout */
    500,

    /* ucWdgIfDeviceId */
    0
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_TriggerType, WDGM_CONST) WdgM_GaaMode1Trigger[WDGM_GAAMODE1TRIGGER_TOTAL_COUNT] =
{
  /* Trigger 0 - 0 */
  {
    /* ddWdgIfMode */
    WDGIF_OFF_MODE,

    /* usWdgIfTimeout */
    100,

    /* ucWdgIfDeviceId */
    1
  },

  /* Trigger 1 - 1 */
  {
    /* ddWdgIfMode */
    WDGIF_FAST_MODE,

    /* usWdgIfTimeout */
    100,

    /* ucWdgIfDeviceId */
    0
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_ActiveSEType, WDGM_CONST) WdgM_GaaMode0ActiveSE[WDGM_GAAMODE0ACTIVESE_TOTAL_COUNT] =
{
  /* ActiveSE 0 - 0 */
  {
    /* ddSEId */
    300,

    /* ddSEArrayIndex */
    0,

    /* ucFailedTolerance */
    0
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_ActiveSEType, WDGM_CONST) WdgM_GaaMode1ActiveSE[WDGM_GAAMODE1ACTIVESE_TOTAL_COUNT] =
{
  /* ActiveSE 0 - 0 */
  {
    /* ddSEId */
    400,

    /* ddSEArrayIndex */
    1,

    /* ucFailedTolerance */
    1
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_CheckpointGraphType, WDGM_CONST) WdgM_GaaSE300Checkpoints[WDGM_GAASE300CHECKPOINTS_TOTAL_COUNT] =
{
  /* Mapping of Checkpoint transitions 0 - 0 */
  {
    /* ddCpMapArrayIndex */
    0,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_BI
  },

  /* Mapping of Checkpoint transitions 1 - 1 */
  {
    /* ddCpMapArrayIndex */
    0,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_INITIAL
  },

  /* Mapping of Checkpoint transitions 2 - 2 */
  {
    /* ddCpMapArrayIndex */
    0,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_FINAL
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_CheckpointGraphType, WDGM_CONST) WdgM_GaaSE400Checkpoints[WDGM_GAASE400CHECKPOINTS_TOTAL_COUNT] =
{
  /* Mapping of Checkpoint transitions 0 - 0 */
  {
    /* ddCpMapArrayIndex */
    0,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_BI
  },

  /* Mapping of Checkpoint transitions 1 - 1 */
  {
    /* ddCpMapArrayIndex */
    0,

    /* ucMaxBranches */
    1,

    /* enCpType */
    WDGM_CP_INITIAL
  },

  /* Mapping of Checkpoint transitions 2 - 2 */
  {
    /* ddCpMapArrayIndex */
    1,

    /* ucMaxBranches */
    1,

    /* enCpType */
    WDGM_CP_BI
  },

  /* Mapping of Checkpoint transitions 3 - 3 */
  {
    /* ddCpMapArrayIndex */
    0,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_FINAL
  },

  /* Mapping of Checkpoint transitions 4 - 4 */
  {
    /* ddCpMapArrayIndex */
    2,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_BI
  },

  /* Mapping of Checkpoint transitions 5 - 5 */
  {
    /* ddCpMapArrayIndex */
    2,

    /* ucMaxBranches */
    0,

    /* enCpType */
    WDGM_CP_BI
  }
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* static CONST(WdgM_CheckpointIdType, WDGM_CONST) WdgM_GaaIntLSGraphSE300MapArray[WDGM_GAAINTLSGRAPHSE300MAPARRAY_TOTAL_COUNT]; */
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

static CONST(WdgM_CheckpointIdType, WDGM_CONST) WdgM_GaaIntLSGraphSE400MapArray[WDGM_GAAINTLSGRAPHSE400MAPARRAY_TOTAL_COUNT] =
{
  2,

  3
};

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_16
#include "MemMap.h"
/* Array for WdgM CallerIds */
CONST(uint16, WDGM_CONST) WdgM_GaaSetModeCallerId[WDGM_TOTAL_SET_MODE_API_CALLERS] = {
300};
#define WDGM_STOP_SEC_CONST_16
#include "MemMap.h"


#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
VAR(WdgM_ExAliveIndicationsCountType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaAliveIndicationStatus[WDGM_MAX_ALIVESUPERVISIONS];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
VAR(WdgM_DeadlineSupervisionStatusType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaDeadlineSupervisionStatus[WDGM_MAX_DEADLINESUPERVISIONS];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
VAR(WdgM_IntLogicalSupervisionStatusType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaIntLogicalSupervisionStatus[WDGM_MAX_INTLOGICALSUPERVISIONS];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA-C3:20.1 */
/* polyspace:end MISRA-C3:1.1 */
/* polyspace:end MISRA-C3:2.2 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
