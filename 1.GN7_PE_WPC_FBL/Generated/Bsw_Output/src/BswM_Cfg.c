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
**  FILE-NAME : BswM_Cfg.c                                                    **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.8.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_BswM.arxml
 *                Configuration\ECU\Ecud_Com.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_EcuM.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 * GENERATED ON: The time-stamp is removed
 */

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:10.3 [Justified:Medium] "An enum type is treated as one of the integral types by compiler" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_PCTypes.h"
#include "BswM_Rule.h"

#include "EcuM.h"
#include "ComM.h"
#include "SchM_BswM.h"
#include "ComM_EcuMBswM.h"
#include "Rte_BswM.h"
#include "Dcm.h"
#include "CanSM.h"
#include "Rte.h"
#include "KeyM.h"
#include "Crypto_76_HaeModule.h"
#include "Rte_Main.h"
#include "App_Hsm_Hae.h"
#include "WdgM.h"
#include "Dummy.h"


/*******************************************************************************
**                      Initialization Structure                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/* Structure for Bsw Mode Notification Property */
CONST(BswM_BswModeNotificationProperty, BSWM_CONST) BswM_GaaBswModeNotificationProperty[BSWM_TOTAL_PORTS_OF_BSW_MODE_NOTIFICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[2],

    /* ddTotalRules */
    0x0008U,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[10],

    /* ddTotalRules */
    0x0002U,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  2 - 2 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[12],

    /* ddTotalRules */
    0x000CU,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  3 - 3 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[24],

    /* ddTotalRules */
    0x0002U,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmModeRapidPowerShutDown_ENABLE_RAPIDPOWERSHUTDOWN,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  4 - 4 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[26],

    /* ddTotalRules */
    0x0001U,

    /* ddModeInitValue */
    (BswM_ModeDeclarationType)RTE_MODE_DcmEcuReset_NONE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};




/* Structure for CanSM Mode Indication Property */
CONST(BswM_CanSMIndicationProperty, BSWM_CONST) BswM_GaaCanSMIndicationProperty[BSWM_TOTAL_PORTS_OF_CANSM_INDICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[27],

    /* ddTotalRules */
    0x0005U,

    /* ddNetworkId */
    0x00U,

    /* ddModeInitValue */
    CANSM_BSWM_NO_COMMUNICATION,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};




/* Structure for ComM Mode Indication Property */
CONST(BswM_ComMIndicationProperty, BSWM_CONST) BswM_GaaComMIndicationProperty[BSWM_TOTAL_PORTS_OF_COMM_INDICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[32],

    /* ddTotalRules */
    0x0004U,

    /* ddNetworkId */
    0x00U,

    /* ddModeInitValue */
    COMM_NO_COMMUNICATION,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_ComMPNCIndicationProperty, BSWM_CONST) BswM_GaaComMPncIndicationProperty[BSWM_TOTAL_PORTS_OF_COMM_PNC_REQUEST]; */
/* CONST(BswM_DMControlType, BSWM_CONST) BswM_GaaDMControl[BSWM_NO_OF_DM_CONTROL]; */

/* Structure for Dcm Application Updated Indication Property */
CONST(BswM_DcmApplicationUpdatedProperty, BSWM_CONST) BswM_GaaDcmApplicationUpdatedProperty[BSWM_TOTAL_PORTS_OF_DCM_APPLICATION_UPDATED_INDICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[36],

    /* ddTotalRules */
    0x0002U,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_DcmCommunicationRequestProperty, BSWM_CONST) BswM_GaaDcmComRequestProperty[BSWM_TOTAL_PORTS_OF_DCM_COM_REQUEST]; */

/* Structure for EcuM State Indication Property */
CONST(BswM_EcuMIndicationProperty, BSWM_CONST) BswM_GaaEcuMIndicationProperty[BSWM_TOTAL_PORTS_OF_ECUM_INDICATION] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[38],

    /* ddTotalRules */
    0x0001U,

    /* ddModeInitValue */
    ECUM_STATE_STARTUP_ONE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_EcuMWakeupIndicationProperty, BSWM_CONST) BswM_GaaEcuMWakeupIndicationProperty[BSWM_TOTAL_PORTS_OF_ECUM_WAKEUP_SOURCE]; */
/* CONST(BswM_EthSMIndicationProperty, BSWM_CONST) BswM_GaaEthSMIndicationProperty[BSWM_TOTAL_PORTS_OF_ETHSM_INDICATION]; */
/* CONST(BswM_FrSMIndicationProperty, BSWM_CONST) BswM_GaaFrSMIndicationProperty[BSWM_TOTAL_PORTS_OF_FRSM_INDICATION]; */

/* Structure for Generic Request Property */
CONST(BswM_GenericRequestProperty, BSWM_CONST) BswM_GaaGenericRequestProperty[BSWM_TOTAL_PORTS_OF_GENERIC_REQUEST] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[39],

    /* ddTotalRules */
    0x000CU,

    /* usModeRequesterId */
    0x002AU,

    /* usRequestedModeMax */
    0x0190U,

    /* ddModeInitValue */
    (BswM_ModeType)BSWM_ECUSTATE_READY,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  1 - 1 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[51],

    /* ddTotalRules */
    0x0002U,

    /* usModeRequesterId */
    0x008CU,

    /* usRequestedModeMax */
    0x0001U,

    /* ddModeInitValue */
    (BswM_ModeType)CANSM_BSWM_BOR_COMPLETE,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  },

  /*  2 - 2 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[53],

    /* ddTotalRules */
    0x000AU,

    /* usModeRequesterId */
    0x012AU,

    /* usRequestedModeMax */
    0x0003U,

    /* ddModeInitValue */
    (BswM_ModeType)BSWM_SHUTDOWNTARGET_RUN,

    /* blModeInitValueStatus */
    BSWM_VALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_J1939DcmBroadcastStatusProperty, BSWM_CONST) BswM_GaaJ1939DcmBroadcastStatusProperty[BSWM_TOTAL_PORTS_OF_J1939DCM_BROADCAST_STATUS]; */
/* CONST(BswM_J1939NmIndicationProperty, BSWM_CONST) BswM_GaaJ1939NmIndicationProperty[BSWM_TOTAL_PORTS_OF_J1939NM_INDICATION]; */
/* CONST(BswM_LinSMIndicationProperty, BSWM_CONST) BswM_GaaLinSMIndicationProperty[BSWM_TOTAL_PORTS_OF_LINSM_INDICATION]; */
/* CONST(BswM_LinSMScheduleIndicationProperty, BSWM_CONST) BswM_GaaLinScheduleIndicationProperty[BSWM_TOTAL_PORTS_OF_LIN_SCHEDULE_INDICATION]; */
/* CONST(BswM_LinTpRequestProperty, BSWM_CONST) BswM_GaaLinTpModeRequestProperty[BSWM_TOTAL_PORTS_OF_LINTP_MODE_REQUEST]; */
/* CONST(BswM_NvMBlockModeIndicationProperty, BSWM_CONST) BswM_GaaNvMBlockModeIndicationProperty[BSWM_TOTAL_PORTS_OF_NVM_CURRENT_BLOCK_MODE]; */
/* CONST(BswM_NvMJobModeIndicationProperty, BSWM_CONST) BswM_GaaNvMJobModeIndicationProperty[BSWM_TOTAL_PORTS_OF_NVM_CURRENT_JOB_MODE]; */
/* CONST(BswM_PduGroupSwitchType, BSWM_CONST) BswM_GaaPduGroupSwitch[BSWM_NO_OF_PDU_GROUP_SWITCH]; */
/* CONST(BswM_PduRouterControlType, BSWM_CONST) BswM_GaaPduRouterControl[BSWM_NO_OF_PDUR_ROUTER_CONTROL]; */

/* Structure for Rule Property */
CONST(BswM_RuleInitPropertyType, BSWM_CONST) BswM_GaaRuleInitProperty[BSWM_TOTAL_RULES] =
{
  /* Rule 0 - 0 */
  {
    /* *pRuleFunction */
    Rule_ComModeNotification_BCAN_FULL_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 1 - 1 */
  {
    /* *pRuleFunction */
    Rule_ComModeNotification_BCAN_NO_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 2 - 2 */
  {
    /* *pRuleFunction */
    Rule_ComModeNotification_BCAN_SILENT_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 3 - 3 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_DISABLE_RX_ENABLE_TX_NORM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 4 - 4 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_DISABLE_RX_ENABLE_TX_NORM_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 5 - 5 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_ENABLE_RX_DISABLE_TX_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 6 - 6 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_ENABLE_RX_DISABLE_TX_NORM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 7 - 7 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_ENABLE_RX_DISABLE_TX_NORM_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 8 - 8 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_ENABLE_RX_TX_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 9 - 9 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_ENABLE_RX_TX_NORM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 10 - 10 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_ENABLE_RX_TX_NORM_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 11 - 11 */
  {
    /* *pRuleFunction */
    Rule_CanBorNotification_BCAN_COMPLETE,

    /* ucRuleInitState */
    BSWM_TRUE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 12 - 12 */
  {
    /* *pRuleFunction */
    Rule_CanBorNotification_BCAN_START,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 13 - 13 */
  {
    /* *pRuleFunction */
    Rule_CanStateNotification_BCAN_BUS_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 14 - 14 */
  {
    /* *pRuleFunction */
    Rule_CanStateNotification_BCAN_CHANGE_BAUDRATE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 15 - 15 */
  {
    /* *pRuleFunction */
    Rule_CanStateNotification_BCAN_FULL_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 16 - 16 */
  {
    /* *pRuleFunction */
    Rule_CanStateNotification_BCAN_NO_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 17 - 17 */
  {
    /* *pRuleFunction */
    Rule_CanStateNotification_BCAN_SILENT_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 18 - 18 */
  {
    /* *pRuleFunction */
    Rule_ComModeRequest_BCAN_FULL_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 19 - 19 */
  {
    /* *pRuleFunction */
    Rule_ComModeRequest_BCAN_NO_COM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 20 - 20 */
  {
    /* *pRuleFunction */
    Rule_DcmApplicationUpdatedNotification_APP_NOT_UPDATED,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 21 - 21 */
  {
    /* *pRuleFunction */
    Rule_DcmApplicationUpdatedNotification_APP_UPDATED,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 22 - 22 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_DISABLE_RX_DISABLE_TX_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 23 - 23 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_DISABLE_RX_TX_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 24 - 24 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_DISABLE_RX_TX_NORMAL,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 25 - 25 */
  {
    /* *pRuleFunction */
    Rule_DcmCommunicationControl_0_DCM_DISABLE_RX_TX_NORM_NM,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 26 - 26 */
  {
    /* *pRuleFunction */
    Rule_DcmControlDTCSetting_DISABLEDTCSETTING,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 27 - 27 */
  {
    /* *pRuleFunction */
    Rule_DcmControlDTCSetting_ENABLEDTCSETTING,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 28 - 28 */
  {
    /* *pRuleFunction */
    Rule_DcmModeRapidPowerShutDown_DISABLE_RAPIDPOWERSHUTDOWN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 29 - 29 */
  {
    /* *pRuleFunction */
    Rule_DcmModeRapidPowerShutDown_ENABLE_RAPIDPOWERSHUTDOWN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 30 - 30 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_DEFAULT_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 31 - 31 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_ECU_PROGRAMMING_MODE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 32 - 32 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_EXTENDED_DIAGNOSTIC_MODE,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 33 - 33 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_EXTENDED_DIAGNOSTIC_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 34 - 34 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_PROGRAMMING_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 35 - 35 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_QUIESCENT_CURRENT_DIAGNOSTIC_MODE_START,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 36 - 36 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_SAFETY_SYSTEM_DIAGNOSTIC_SESSION,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 37 - 37 */
  {
    /* *pRuleFunction */
    Rule_DiagnosticSessionNotification_SLEEP_MODE_START_REQUEST,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 38 - 38 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 39 - 39 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_RESET,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 40 - 40 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_RUN_From_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 41 - 41 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_RUN_From_STARTUP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 42 - 42 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_SHUTDOWN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 43 - 43 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 44 - 44 */
  {
    /* *pRuleFunction */
    Rule_EcuStateTo_STARTUP_TWO,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 45 - 45 */
  {
    /* *pRuleFunction */
    Rule_EcuState_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 46 - 46 */
  {
    /* *pRuleFunction */
    Rule_EcuState_RESET,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 47 - 47 */
  {
    /* *pRuleFunction */
    Rule_EcuState_RUN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 48 - 48 */
  {
    /* *pRuleFunction */
    Rule_EcuState_SHUTDOWN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 49 - 49 */
  {
    /* *pRuleFunction */
    Rule_EcuState_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 50 - 50 */
  {
    /* *pRuleFunction */
    Rule_EcuState_STARTUP_TWO,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 51 - 51 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_OFF,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 52 - 52 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_RESET,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 53 - 53 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_RUN,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  },

  /* Rule 54 - 54 */
  {
    /* *pRuleFunction */
    Rule_ShutdownTargetTo_SLEEP,

    /* ucRuleInitState */
    BSWM_FALSE,

    /* blNestedExecutionOnly */
    BSWM_FALSE
  }
};



/* CONST(BswM_Sd_ClientServiceCurrentStateProperty, BSWM_CONST) BswM_GaaSdClientServiceCurrentStateProperty[BSWM_TOTAL_PORTS_OF_SD_CLIENTSERVICE_CURRENTSTATE]; */
/* CONST(BswM_Sd_ConsumedEventGroupCurrentStateProperty, BSWM_CONST) BswM_GaaSdConsumedEventGroupCurrentStateProperty[BSWM_TOTAL_PORTS_OF_SD_CONSUMEDEVENTGROUP_CURRENTSTATE]; */
/* CONST(BswM_Sd_EventHandlerCurrentStateProperty, BSWM_CONST) BswM_GaaSdEventHandlerCurrentStateProperty[BSWM_TOTAL_PORTS_OF_SD_EVENTHANDLER_CURRENTSTATE]; */
/*CONST(BswM_SlaveCoreInfoType, BSWM_CONST) BswM_GaaStartSlaveCores[BSWM_NO_OF_START_SLAVE_CORES]; */
/*CONST(BswM_SlaveCoreInfoType, BSWM_CONST) BswM_GaaStopSlaveCores[BSWM_NO_OF_STOP_SLAVE_CORES]; */
/* CONST(BswM_SwcModeNotificationProperty, BSWM_CONST) BswM_GaaSwcModeNotificationProperty[BSWM_TOTAL_PORTS_OF_SWC_MODE_NOTIFICATION]; */

/* Structure for Swc Mode Request Property */
CONST(BswM_SwcModeRequestProperty, BSWM_CONST) BswM_GaaSwcModeRequestProperty[BSWM_TOTAL_PORTS_OF_SWC_MODE_REQUEST] =
{
  /*  0 - 0 */
  {
    /* *pRuleId */
    &BswM_GaaRuleIdList[0],

    /* ddTotalRules */
    0x0002U,

    /* blModeInitValueStatus */
    BSWM_INVALID,

    /* blRequestProcessing */
    BSWM_IMMEDIATE
  }
};



/* CONST(BswM_TriggerIpduSendType, BSWM_CONST) BswM_GaaTriggerIpduSend[BSWM_NO_OF_TRIGGER_IPDU_SEND]; */
/* CONST(BswM_WdgM_PartitionResetProperty, BSWM_CONST) BswM_GaaWdgMPartitionResetProperty[BSWM_TOTAL_PORTS_OF_WDGM_REQUEST_PARTITION_RESET]; */







/* Array for Total Rules of Mode Request Port */
CONST(BswM_RuleIdType, BSWM_CONST) BswM_GaaRuleIdList[BSWM_TOTAL_RULE_IDS] = {
   18,  19,  30,  31,  32,  33,  34,  35,  36,  37, 
   26,  27,   3,   4,   5,   6,   7,   8,   9,  10, 
   22,  23,  24,  25,  28,  29,  52,  13,  14,  15, 
   16,  17,   0,   1,   2,  43,  20,  21,  44,  38, 
   39,  40,  41,  42,  43,  45,  46,  47,  48,  49, 
   50,  11,  12,  38,  39,  40,  41,  42,  43,  51, 
   52,  53,  54
};




#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-end MISRA-C3:10.3 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
