/*
 * File: Jdg_DualOrder.c
 *
 * Code generated for Simulink model 'App_Model'.
 *
 * Model version                  : 1.649
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 13 10:28:43 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "App_Model_types.h"
#include "Jdg_DualOrder.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S384>/DWPC1_LED_Sync_Indy' */
#define App_Model_IN_SyncTriggerOff    ((uint8)1U)
#define App_Model_IN_SyncTriggerOn     ((uint8)2U)

/* Named constants for Chart: '<S384>/DWPC1_Amber_Sync_Chart' */
#define App_Model_IN_SyncTriggerOff_f  ((uint8)1U)
#define App_Model_IN_SyncTriggerOn_b   ((uint8)2U)

/*
 * System initialize for atomic system:
 *    '<S384>/DWPC1_LED_Sync_Indy'
 *    '<S384>/DWPC2_LED_Sync_Indy'
 */
void App_Mo_DWPC1_LED_Sync_Indy_Init(Bool *rty_b_SyncLED)
{
  *rty_b_SyncLED = Off;
}

/*
 * Output and update for atomic system:
 *    '<S384>/DWPC1_LED_Sync_Indy'
 *    '<S384>/DWPC2_LED_Sync_Indy'
 */
void App_Model_DWPC1_LED_Sync_Indy(Bool rtu_b_BlinkState, Bool rtu_b_CmdLEDSync, BlinkState rtu_BlinkState, Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW)
{
  localDW->b_BlinkState_prev = localDW->b_BlinkState_start;
  localDW->b_BlinkState_start = rtu_b_BlinkState;
  localDW->b_CmdLEDSync_prev = localDW->b_CmdLEDSync_start;
  localDW->b_CmdLEDSync_start = rtu_b_CmdLEDSync;
  localDW->BlinkState_prev = localDW->BlinkState_start;
  localDW->BlinkState_start = rtu_BlinkState;

  /* Chart: '<S384>/DWPC1_LED_Sync_Indy' */
  if (localDW->is_active_c10_Jdg_DualSyncOrder == 0U) {
    localDW->b_BlinkState_prev = rtu_b_BlinkState;
    localDW->b_CmdLEDSync_prev = rtu_b_CmdLEDSync;
    localDW->BlinkState_prev = rtu_BlinkState;
    localDW->is_active_c10_Jdg_DualSyncOrder = 1U;
    localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOff;
    *rty_b_SyncLED = Off;
  } else if (localDW->is_SyncTrigger == App_Model_IN_SyncTriggerOff) {
    Bool tmp;
    *rty_b_SyncLED = Off;
    tmp = localDW->b_BlinkState_start;
    if (((localDW->b_BlinkState_prev != tmp) && (tmp == On)) || (rtu_b_BlinkState == On)) {
      /* DefaultCondtionAdd_SideEffect */
      localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOn;
      *rty_b_SyncLED = On;
    }
  } else {
    Bool tmp;

    /* case IN_SyncTriggerOn: */
    *rty_b_SyncLED = On;
    tmp = localDW->b_CmdLEDSync_start;
    if (((localDW->b_CmdLEDSync_prev != tmp) && (tmp == Off)) || ((localDW->BlinkState_prev != localDW->BlinkState_start) && (localDW->BlinkState_start == BlinkComplete))) {
      localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOff;
      *rty_b_SyncLED = Off;
    }
  }

  /* End of Chart: '<S384>/DWPC1_LED_Sync_Indy' */
}

/* System initialize for atomic system: '<S10>/Jdg_DualOrder' */
void App_Model_Jdg_DualOrder_Init(uint8 *rty_JdgDualOrder, uint8 *rty_JdgDualOrder_l, PreSyncAct *rty_JdgDualOrder_j, PreSyncAct *rty_JdgDualOrder_f, Bool *rty_JdgDualOrder_g, Bool *rty_JdgDualOrder_p,
  Bool *rty_JdgDualOrder_jt, Bool *rty_JdgDualOrder_h, Bool *rty_JdgDualOrder_c, Bool *rty_JdgDualOrder_e, Bool *rty_JdgDualOrder_k)
{
  /* SystemInitialize for Chart: '<S383>/Change_INT_NfcOnThePad' */
  App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
  App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
  App_Model_DW.NfcOnThePad_1_prev = OnThePad_Off;
  App_Model_DW.NfcOnThePad_1_start = OnThePad_Off;
  App_Model_DW.NfcOnThePad_2_prev = OnThePad_Off;
  App_Model_DW.NfcOnThePad_2_start = OnThePad_Off;

  /* SystemInitialize for Chart: '<S383>/Jdg_DualWPC_Onthepad' */
  *rty_JdgDualOrder_c = Off;
  *rty_JdgDualOrder_e = Off;
  *rty_JdgDualOrder_k = Off;

  /* SystemInitialize for Chart: '<S383>/Jdg_LPCDWakeUpOrder' */
  *rty_JdgDualOrder_l = 0U;

  /* SystemInitialize for Chart: '<S383>/Jdg_NFCDetectOrder' */
  *rty_JdgDualOrder = 0U;

  /* SystemInitialize for Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
  *rty_JdgDualOrder_j = PreSyncAct__Off;

  /* SystemInitialize for Chart: '<S385>/IND_Animation_Priority_Flow_Graph1' incorporates:
   *  Chart: '<S385>/IND_Animation_Priority_Flow_Graph'
   */
  *rty_JdgDualOrder_f = PreSyncAct__Off;

  /* SystemInitialize for Chart: '<S384>/DWPC1_Amber_Sync_Chart' incorporates:
   *  Chart: '<S383>/Jdg_DualWPC_Onthepad'
   */
  *rty_JdgDualOrder_g = Off;

  /* SystemInitialize for Chart: '<S384>/DWPC1_LED_Sync_Indy' */
  App_Mo_DWPC1_LED_Sync_Indy_Init(rty_JdgDualOrder_p);

  /* SystemInitialize for Chart: '<S384>/DWPC2_Amber_Sync_Chart' incorporates:
   *  Chart: '<S383>/Jdg_DualWPC_Onthepad'
   */
  *rty_JdgDualOrder_jt = Off;

  /* SystemInitialize for Chart: '<S384>/DWPC2_LED_Sync_Indy' */
  App_Mo_DWPC1_LED_Sync_Indy_Init(rty_JdgDualOrder_h);
}

/* Output and update for atomic system: '<S10>/Jdg_DualOrder' */
void App_Model_Jdg_DualOrder(WPCStatus rtu_DWPC1, WPCIndCmdState rtu_DWPC1_l, C_WPCIndSyncVal rtu_DWPC1_j, Bool rtu_DWPC1_f, BlinkState rtu_DWPC1_g, WPCStatus rtu_DWPC2, WPC2IndCmdState rtu_DWPC2_j,
  WPC2IndSyncVal rtu_DWPC2_h, Bool rtu_DWPC2_c, BlinkState rtu_DWPC2_e, OnThePad rtu_Input_Data, OnThePad rtu_Input_Data_c, OnThePad rtu_Input_Data_a, OnThePad rtu_Input_Data_j, OnThePad
  rtu_Input_Data_h, OnThePad rtu_Input_Data_o, Bool rtu_Input_Data_p, Bool rtu_Input_Data_m, LC_WPC_NFCDetection rtu_Input_Data_l, LC_WPC_NFCDetection rtu_Input_Data_d, RWPCIndSyncVal
  rtu_Input_Data_a3, uint8 *rty_JdgDualOrder, uint8 *rty_JdgDualOrder_l, PreSyncAct *rty_JdgDualOrder_j, PreSyncAct *rty_JdgDualOrder_f, Bool *rty_JdgDualOrder_g, Bool *rty_JdgDualOrder_p, Bool
  *rty_JdgDualOrder_jt, Bool *rty_JdgDualOrder_h, Bool *rty_JdgDualOrder_c, Bool *rty_JdgDualOrder_e, Bool *rty_JdgDualOrder_k)
{
  Bool tmp_2;
  Bool tmp_3;
  Bool tmp_6;
  Bool tmp_7;
  WPCStatus tmp_1;
  WPCStatus tmp_4;
  WPCStatus tmp_5;

  /* Chart: '<S383>/Change_INT_NfcOnThePad' */
  App_Model_DW.NfcOnThePad_1_prev = App_Model_DW.NfcOnThePad_1_start;
  App_Model_DW.NfcOnThePad_1_start = rtu_Input_Data;
  App_Model_DW.NfcOnThePad_2_prev = App_Model_DW.NfcOnThePad_2_start;
  App_Model_DW.NfcOnThePad_2_start = rtu_Input_Data_c;
  if (App_Model_DW.is_active_c30_Jdg_DualSyncOrder == 0U) {
    OnThePad tmp;
    OnThePad tmp_0;
    App_Model_DW.NfcOnThePad_1_prev = rtu_Input_Data;
    App_Model_DW.NfcOnThePad_2_prev = rtu_Input_Data_c;
    App_Model_DW.is_active_c30_Jdg_DualSyncOrder = 1U;
    App_Model_B.INT_NfcOnThePad_1 = rtu_Input_Data;
    if (rtu_DWPC1 == PICCMode) {
      /* ||OPT_WPCStatus_2 == PICCMode */
      tmp = App_Model_DW.NfcOnThePad_1_start;
      tmp_0 = App_Model_DW.NfcOnThePad_1_prev;
      if ((tmp_0 != tmp) && (tmp == OnThePad_Off)) {
        App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
      } else if ((tmp_0 != tmp) && (tmp == OnThePad_On)) {
        App_Model_B.INT_NfcOnThePad_1 = OnThePad_On;
      }
    }

    App_Model_B.INT_NfcOnThePad_2 = rtu_Input_Data_c;

    /* [OPT_WPCStatus_1 == PICCMode ||... */
    if (rtu_DWPC2 == PICCMode) {
      tmp = App_Model_DW.NfcOnThePad_2_start;
      tmp_0 = App_Model_DW.NfcOnThePad_2_prev;
      if ((tmp_0 != tmp) && (tmp == OnThePad_Off)) {
        App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
      } else if ((tmp_0 != tmp) && (tmp == OnThePad_On)) {
        App_Model_B.INT_NfcOnThePad_2 = OnThePad_On;
      }
    }
  } else {
    OnThePad tmp;
    OnThePad tmp_0;
    if (rtu_DWPC1 == PICCMode) {
      /* ||OPT_WPCStatus_2 == PICCMode */
      tmp = App_Model_DW.NfcOnThePad_1_start;
      tmp_0 = App_Model_DW.NfcOnThePad_1_prev;
      if ((tmp_0 != tmp) && (tmp == OnThePad_Off)) {
        App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
      } else if ((tmp_0 != tmp) && (tmp == OnThePad_On)) {
        App_Model_B.INT_NfcOnThePad_1 = OnThePad_On;
      }
    } else {
      App_Model_B.INT_NfcOnThePad_1 = rtu_Input_Data;
    }

    /* [OPT_WPCStatus_1 == PICCMode ||... */
    if (rtu_DWPC2 == PICCMode) {
      tmp = App_Model_DW.NfcOnThePad_2_start;
      tmp_0 = App_Model_DW.NfcOnThePad_2_prev;
      if ((tmp_0 != tmp) && (tmp == OnThePad_Off)) {
        App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
      } else if ((tmp_0 != tmp) && (tmp == OnThePad_On)) {
        App_Model_B.INT_NfcOnThePad_2 = OnThePad_On;
      }
    } else {
      App_Model_B.INT_NfcOnThePad_2 = rtu_Input_Data_c;
    }
  }

  /* End of Chart: '<S383>/Change_INT_NfcOnThePad' */

  /* Chart: '<S383>/Jdg_DualWPC_Onthepad' */
  if (App_Model_DW.is_active_c23_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.is_active_c23_Jdg_DualSyncOrder = 1U;
    *rty_JdgDualOrder_c = Off;
    if ((App_Model_B.INT_NfcOnThePad_1 == OnThePad_Off) && (App_Model_B.INT_NfcOnThePad_2 == OnThePad_Off)) {
      *rty_JdgDualOrder_c = On;
    } else {
      *rty_JdgDualOrder_c = Off;
    }

    *rty_JdgDualOrder_e = Off;

    /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
    if (((rtu_Input_Data_a == OnThePad_Off) && (rtu_Input_Data_j == OnThePad_Off)) || ((rtu_DWPC1 == ModeOff) && (rtu_Input_Data_j == OnThePad_Off)) || ((rtu_DWPC2 == ModeOff) && (rtu_Input_Data_a ==
          OnThePad_Off))) {
      /* USM WPC2 OFF, WPC1 O */
      *rty_JdgDualOrder_e = On;
    } else {
      *rty_JdgDualOrder_e = Off;
    }

    *rty_JdgDualOrder_k = Off;

    /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
    if (((rtu_Input_Data_h == OnThePad_Off) && (rtu_Input_Data_o == OnThePad_Off)) || ((rtu_DWPC1 == ModeOff) && (rtu_Input_Data_o == OnThePad_Off)) || ((rtu_DWPC2 == ModeOff) && (rtu_Input_Data_h ==
          OnThePad_Off))) {
      /* USM WPC2 OFF, WPC1 O */
      *rty_JdgDualOrder_k = On;
    } else {
      *rty_JdgDualOrder_k = Off;
    }
  } else {
    if ((App_Model_B.INT_NfcOnThePad_1 == OnThePad_Off) && (App_Model_B.INT_NfcOnThePad_2 == OnThePad_Off)) {
      *rty_JdgDualOrder_c = On;
    } else {
      *rty_JdgDualOrder_c = Off;
    }

    /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
    if (((rtu_Input_Data_a == OnThePad_Off) && (rtu_Input_Data_j == OnThePad_Off)) || ((rtu_DWPC1 == ModeOff) && (rtu_Input_Data_j == OnThePad_Off)) || ((rtu_DWPC2 == ModeOff) && (rtu_Input_Data_a ==
          OnThePad_Off))) {
      /* USM WPC2 OFF, WPC1 O */
      *rty_JdgDualOrder_e = On;
    } else {
      *rty_JdgDualOrder_e = Off;
    }

    /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
    if (((rtu_Input_Data_h == OnThePad_Off) && (rtu_Input_Data_o == OnThePad_Off)) || ((rtu_DWPC1 == ModeOff) && (rtu_Input_Data_o == OnThePad_Off)) || ((rtu_DWPC2 == ModeOff) && (rtu_Input_Data_h ==
          OnThePad_Off))) {
      /* USM WPC2 OFF, WPC1 O */
      *rty_JdgDualOrder_k = On;
    } else {
      *rty_JdgDualOrder_k = Off;
    }
  }

  /* End of Chart: '<S383>/Jdg_DualWPC_Onthepad' */

  /* Chart: '<S383>/LPCDWakeUp_Detect_DWPC_Priority' */
  App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s;
  App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s = rtu_Input_Data_p;
  App_Model_DW.Var_OPT_WPCStatus_1_prev_f = App_Model_DW.Var_OPT_WPCStatus_1_start_f;
  App_Model_DW.Var_OPT_WPCStatus_1_start_f = rtu_DWPC1;
  App_Model_DW.Var_OPT_WPCStatus_2_prev_c = App_Model_DW.Var_OPT_WPCStatus_2_start_a;
  App_Model_DW.Var_OPT_WPCStatus_2_start_a = rtu_DWPC2;
  App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s;
  App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s = rtu_Input_Data_m;
  if (App_Model_DW.is_active_c47_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p = rtu_Input_Data_p;
    App_Model_DW.Var_OPT_WPCStatus_1_prev_f = rtu_DWPC1;
    App_Model_DW.Var_OPT_WPCStatus_2_prev_c = rtu_DWPC2;
    App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p = rtu_Input_Data_m;
    App_Model_DW.is_active_c47_Jdg_DualSyncOrder = 1U;
    App_Model_B.Var_WPC1PreAct_b = Off;

    /* 1 */
    tmp_2 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p;
    tmp_3 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s;
    if ((tmp_2 != tmp_3) && (tmp_2 == Off) && (tmp_2 != tmp_3) && (rtu_DWPC1 == LPCDMode)) {
      App_Model_B.Var_WPC1PreAct_b = On;
    }

    App_Model_B.Var_WPC2PreAct_d = Off;

    /* 1 */
    tmp_2 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p;
    tmp_3 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s;
    if ((tmp_2 != tmp_3) && (tmp_2 == Off) && (tmp_2 != tmp_3) && (rtu_DWPC2 == LPCDMode)) {
      App_Model_B.Var_WPC2PreAct_d = On;
    }
  } else {
    /* 1 */
    tmp_2 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p;
    tmp_3 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s;
    if ((App_Model_B.Var_WPC1PreAct_b == Off) && ((tmp_2 != tmp_3) && (tmp_2 == Off)) && (tmp_2 != tmp_3) && (rtu_DWPC1 == LPCDMode)) {
      App_Model_B.Var_WPC1PreAct_b = On;
    } else {
      tmp_1 = App_Model_DW.Var_OPT_WPCStatus_1_prev_f;
      tmp_4 = App_Model_DW.Var_OPT_WPCStatus_2_start_a;
      tmp_5 = App_Model_DW.Var_OPT_WPCStatus_2_prev_c;
      if (((tmp_1 != App_Model_DW.Var_OPT_WPCStatus_1_start_f) && (tmp_1 == LPCDMode)) || ((tmp_5 != tmp_4) && (tmp_4 == LPCDMode)) || ((tmp_5 != tmp_4) && (tmp_5 == LPCDMode) && (rtu_DWPC1 !=
            LPCDMode))) {
        App_Model_B.Var_WPC1PreAct_b = Off;
      }
    }

    /* 1 */
    tmp_2 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p;
    tmp_3 = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s;
    if ((App_Model_B.Var_WPC2PreAct_d == Off) && ((tmp_2 != tmp_3) && (tmp_2 == Off)) && (tmp_2 != tmp_3) && (rtu_DWPC2 == LPCDMode)) {
      App_Model_B.Var_WPC2PreAct_d = On;
    } else {
      tmp_1 = App_Model_DW.Var_OPT_WPCStatus_2_prev_c;
      tmp_4 = App_Model_DW.Var_OPT_WPCStatus_1_start_f;
      tmp_5 = App_Model_DW.Var_OPT_WPCStatus_1_prev_f;
      if (((tmp_1 != App_Model_DW.Var_OPT_WPCStatus_2_start_a) && (tmp_1 == LPCDMode)) || ((tmp_5 != tmp_4) && (tmp_4 == LPCDMode)) || ((tmp_5 != tmp_4) && (tmp_5 == LPCDMode) && (rtu_DWPC2 !=
            LPCDMode))) {
        App_Model_B.Var_WPC2PreAct_d = Off;
      }
    }
  }

  /* End of Chart: '<S383>/LPCDWakeUp_Detect_DWPC_Priority' */

  /* Chart: '<S383>/Jdg_LPCDWakeUpOrder' */
  App_Model_DW.Var_WPC2PreAct_prev_p = App_Model_DW.Var_WPC2PreAct_start_j;
  App_Model_DW.Var_WPC2PreAct_start_j = App_Model_B.Var_WPC2PreAct_d;
  App_Model_DW.Var_WPC1PreAct_prev_a = App_Model_DW.Var_WPC1PreAct_start_i;
  App_Model_DW.Var_WPC1PreAct_start_i = App_Model_B.Var_WPC1PreAct_b;
  if (App_Model_DW.is_active_c24_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.Var_WPC2PreAct_prev_p = App_Model_B.Var_WPC2PreAct_d;
    App_Model_DW.Var_WPC1PreAct_prev_a = App_Model_B.Var_WPC1PreAct_b;
    App_Model_DW.is_active_c24_Jdg_DualSyncOrder = 1U;
    *rty_JdgDualOrder_l = 0U;

    /* Default */
    tmp_2 = App_Model_DW.Var_WPC2PreAct_start_j;
    tmp_3 = App_Model_DW.Var_WPC1PreAct_start_i;
    tmp_6 = App_Model_B.Var_WPC2PreAct_d;
    tmp_7 = App_Model_B.Var_WPC1PreAct_b;
    App_Model_DW.Var_WPC1PreAct_prev = App_Model_DW.Var_WPC1PreAct_prev_a;
    App_Model_DW.Var_WPC2PreAct_prev = App_Model_DW.Var_WPC2PreAct_prev_p;
    if (((tmp_7 == Off) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off))) || ((tmp_6 == Off) && ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off))) || ((tmp_6 == Off) &&
         (tmp_7 == Off))) {
      /* 240627_TaskAdj */
      *rty_JdgDualOrder_l = 0U;
    } else if (((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && (tmp_6 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off) && (tmp_7 == On)) ||
               ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On)))) {
      /* SameTimePutPhones */
      *rty_JdgDualOrder_l = 1U;

      /* WPC1_Lead */
    } else if (((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On) && (tmp_7 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off) && (tmp_6 == On))) {
      *rty_JdgDualOrder_l = 2U;

      /* WPC2_Lead */
    }
  } else {
    tmp_2 = App_Model_DW.Var_WPC2PreAct_start_j;
    tmp_3 = App_Model_DW.Var_WPC1PreAct_start_i;
    tmp_6 = App_Model_B.Var_WPC2PreAct_d;
    tmp_7 = App_Model_B.Var_WPC1PreAct_b;
    App_Model_DW.Var_WPC1PreAct_prev = App_Model_DW.Var_WPC1PreAct_prev_a;
    App_Model_DW.Var_WPC2PreAct_prev = App_Model_DW.Var_WPC2PreAct_prev_p;
    if (((tmp_7 == Off) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off))) || ((tmp_6 == Off) && ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off))) || ((tmp_6 == Off) &&
         (tmp_7 == Off))) {
      /* 240627_TaskAdj */
      *rty_JdgDualOrder_l = 0U;
    } else if (((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && (tmp_6 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off) && (tmp_7 == On)) ||
               ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On)))) {
      /* SameTimePutPhones */
      *rty_JdgDualOrder_l = 1U;

      /* WPC1_Lead */
    } else if (((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On) && (tmp_7 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off) && (tmp_6 == On))) {
      *rty_JdgDualOrder_l = 2U;

      /* WPC2_Lead */
    }
  }

  /* Chart: '<S383>/NFC_Detect_DWPC_Priority' */
  App_Model_DW.Var_NFCDetection_WPC1_prev = App_Model_DW.Var_NFCDetection_WPC1_start;
  App_Model_DW.Var_NFCDetection_WPC1_start = rtu_Input_Data_l;
  App_Model_DW.Var_OPT_WPCStatus_1_prev = App_Model_DW.Var_OPT_WPCStatus_1_start;
  App_Model_DW.Var_OPT_WPCStatus_1_start = rtu_DWPC1;
  App_Model_DW.Var_OPT_WPCStatus_2_prev = App_Model_DW.Var_OPT_WPCStatus_2_start;
  App_Model_DW.Var_OPT_WPCStatus_2_start = rtu_DWPC2;
  App_Model_DW.Var_NFCDetection_WPC2_prev = App_Model_DW.Var_NFCDetection_WPC2_start;
  App_Model_DW.Var_NFCDetection_WPC2_start = rtu_Input_Data_d;
  if (App_Model_DW.is_active_c46_Jdg_DualSyncOrder == 0U) {
    LC_WPC_NFCDetection tmp_8;
    LC_WPC_NFCDetection tmp_9;
    App_Model_DW.Var_NFCDetection_WPC1_prev = rtu_Input_Data_l;
    App_Model_DW.Var_OPT_WPCStatus_1_prev = rtu_DWPC1;
    App_Model_DW.Var_OPT_WPCStatus_2_prev = rtu_DWPC2;
    App_Model_DW.Var_NFCDetection_WPC2_prev = rtu_Input_Data_d;
    App_Model_DW.is_active_c46_Jdg_DualSyncOrder = 1U;
    App_Model_B.Var_WPC1PreAct = Off;

    /* 1 */
    tmp_8 = App_Model_DW.Var_NFCDetection_WPC1_prev;
    tmp_9 = App_Model_DW.Var_NFCDetection_WPC1_start;
    if ((tmp_8 != tmp_9) && (tmp_8 == NFCDetection_Off) && (tmp_8 != tmp_9) && (rtu_DWPC1 == NFCMode)) {
      App_Model_B.Var_WPC1PreAct = On;
    } else {
      /* %Only Jdg in NFCMode 240905 */
    }

    App_Model_B.Var_WPC2PreAct = Off;

    /* 1 */
    tmp_8 = App_Model_DW.Var_NFCDetection_WPC2_prev;
    tmp_9 = App_Model_DW.Var_NFCDetection_WPC2_start;
    if ((tmp_8 != tmp_9) && (tmp_8 == NFCDetection_Off) && (tmp_8 != tmp_9) && (rtu_DWPC2 == NFCMode)) {
      App_Model_B.Var_WPC2PreAct = On;
    } else {
      /* %Only Jdg in NFCMode 240905 */
    }
  } else {
    LC_WPC_NFCDetection tmp_8;
    LC_WPC_NFCDetection tmp_9;

    /* 1 */
    tmp_8 = App_Model_DW.Var_NFCDetection_WPC1_prev;
    tmp_9 = App_Model_DW.Var_NFCDetection_WPC1_start;
    if ((App_Model_B.Var_WPC1PreAct == Off) && ((tmp_8 != tmp_9) && (tmp_8 == NFCDetection_Off)) && (tmp_8 != tmp_9) && (rtu_DWPC1 == NFCMode)) {
      App_Model_B.Var_WPC1PreAct = On;
    } else {
      /* %Only Jdg in NFCMode 240905 */
      tmp_1 = App_Model_DW.Var_OPT_WPCStatus_1_prev;
      tmp_4 = App_Model_DW.Var_OPT_WPCStatus_2_start;
      tmp_5 = App_Model_DW.Var_OPT_WPCStatus_2_prev;
      if (((tmp_1 != App_Model_DW.Var_OPT_WPCStatus_1_start) && (tmp_1 == NFCMode)) || ((tmp_5 != tmp_4) && (tmp_4 == NFCMode)) || (rtu_DWPC1 != NFCMode) || ((tmp_5 != tmp_4) && (tmp_5 == NFCMode) &&
           (rtu_DWPC1 != NFCMode))) {
        App_Model_B.Var_WPC1PreAct = Off;
      }
    }

    /* 1 */
    tmp_8 = App_Model_DW.Var_NFCDetection_WPC2_prev;
    tmp_9 = App_Model_DW.Var_NFCDetection_WPC2_start;
    if ((App_Model_B.Var_WPC2PreAct == Off) && ((tmp_8 != tmp_9) && (tmp_8 == NFCDetection_Off)) && (tmp_8 != tmp_9) && (rtu_DWPC2 == NFCMode)) {
      App_Model_B.Var_WPC2PreAct = On;
    } else {
      /* %Only Jdg in NFCMode 240905 */
      tmp_1 = App_Model_DW.Var_OPT_WPCStatus_2_prev;
      tmp_4 = App_Model_DW.Var_OPT_WPCStatus_1_start;
      tmp_5 = App_Model_DW.Var_OPT_WPCStatus_1_prev;
      if (((tmp_1 != App_Model_DW.Var_OPT_WPCStatus_2_start) && (tmp_1 == NFCMode)) || ((tmp_5 != tmp_4) && (tmp_4 == NFCMode)) || (rtu_DWPC2 != NFCMode) || ((tmp_5 != tmp_4) && (tmp_5 == NFCMode) &&
           (rtu_DWPC2 != NFCMode))) {
        App_Model_B.Var_WPC2PreAct = Off;
      }
    }
  }

  /* End of Chart: '<S383>/NFC_Detect_DWPC_Priority' */

  /* Chart: '<S383>/Jdg_LPCDWakeUpOrder' incorporates:
   *  Chart: '<S383>/Jdg_NFCDetectOrder'
   */
  App_Model_DW.Var_WPC2PreAct_prev = App_Model_DW.Var_WPC2PreAct_start;

  /* Chart: '<S383>/Jdg_NFCDetectOrder' */
  App_Model_DW.Var_WPC2PreAct_start = App_Model_B.Var_WPC2PreAct;

  /* Chart: '<S383>/Jdg_LPCDWakeUpOrder' incorporates:
   *  Chart: '<S383>/Jdg_NFCDetectOrder'
   */
  App_Model_DW.Var_WPC1PreAct_prev = App_Model_DW.Var_WPC1PreAct_start;

  /* Chart: '<S383>/Jdg_NFCDetectOrder' */
  App_Model_DW.Var_WPC1PreAct_start = App_Model_B.Var_WPC1PreAct;
  if (App_Model_DW.is_active_c25_Jdg_DualSyncOrder == 0U) {
    /* Chart: '<S383>/Jdg_LPCDWakeUpOrder' */
    App_Model_DW.Var_WPC2PreAct_prev = App_Model_B.Var_WPC2PreAct;
    App_Model_DW.Var_WPC1PreAct_prev = App_Model_B.Var_WPC1PreAct;
    App_Model_DW.is_active_c25_Jdg_DualSyncOrder = 1U;
    *rty_JdgDualOrder = 0U;

    /* Default */
    tmp_2 = App_Model_DW.Var_WPC2PreAct_start;
    tmp_3 = App_Model_DW.Var_WPC1PreAct_start;
    tmp_6 = App_Model_B.Var_WPC1PreAct;
    tmp_7 = App_Model_B.Var_WPC2PreAct;
    if (((tmp_6 == Off) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off))) || ((tmp_7 == Off) && ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off))) || ((tmp_6 == Off) &&
         (tmp_7 == Off))) {
      *rty_JdgDualOrder = 0U;
    } else if (((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && (tmp_7 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off) && (tmp_6 == On)) ||
               ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On)))) {
      *rty_JdgDualOrder = 1U;

      /* WPC1_Lead */
    } else if (((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On) && (tmp_6 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off) && (tmp_7 == On))) {
      *rty_JdgDualOrder = 2U;

      /* WPC2_Lead */
    }
  } else {
    tmp_2 = App_Model_DW.Var_WPC2PreAct_start;
    tmp_3 = App_Model_DW.Var_WPC1PreAct_start;
    tmp_6 = App_Model_B.Var_WPC1PreAct;
    tmp_7 = App_Model_B.Var_WPC2PreAct;
    if (((tmp_6 == Off) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off))) || ((tmp_7 == Off) && ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off))) || ((tmp_6 == Off) &&
         (tmp_7 == Off))) {
      *rty_JdgDualOrder = 0U;
    } else if (((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && (tmp_7 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == Off) && (tmp_6 == On)) ||
               ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == On) && ((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On)))) {
      *rty_JdgDualOrder = 1U;

      /* WPC1_Lead */
    } else if (((App_Model_DW.Var_WPC2PreAct_prev != tmp_2) && (tmp_2 == On) && (tmp_6 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev != tmp_3) && (tmp_3 == Off) && (tmp_7 == On))) {
      *rty_JdgDualOrder = 2U;

      /* WPC2_Lead */
    }
  }

  /* Chart: '<S385>/IND_Animation_WPC2_Priority_Flow_Graph' */
  App_Model_DW.Input_INT_WPC2IndSyncVal_prev = App_Model_DW.Input_INT_WPC2IndSyncVal_start;
  App_Model_DW.Input_INT_WPC2IndSyncVal_start = rtu_DWPC2_h;
  if (App_Model_DW.is_active_c35_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.Input_INT_WPC2IndSyncVal_prev = rtu_DWPC2_h;
    App_Model_DW.is_active_c35_Jdg_DualSyncOrder = 1U;

    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
    App_Model_B.Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;

    /* 1 */
    if ((App_Model_DW.Input_INT_WPC2IndSyncVal_prev != App_Model_DW.Input_INT_WPC2IndSyncVal_start) && (App_Model_DW.Input_INT_WPC2IndSyncVal_prev == WPC2IndSyncVal__Default) &&
        (App_Model_DW.Input_INT_WPC2IndSyncVal_prev != App_Model_DW.Input_INT_WPC2IndSyncVal_start)) {
      /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
      App_Model_B.Var_WPC2PreSyncAct = WPC2PreSyncAct_On;
    } else {
      /* 1 */
    }

    /* 1 */
  } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && ((App_Model_DW.Input_INT_WPC2IndSyncVal_prev != App_Model_DW.Input_INT_WPC2IndSyncVal_start) &&
              (App_Model_DW.Input_INT_WPC2IndSyncVal_prev == WPC2IndSyncVal__Default)) && (App_Model_DW.Input_INT_WPC2IndSyncVal_prev != App_Model_DW.Input_INT_WPC2IndSyncVal_start)) {
    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
    App_Model_B.Var_WPC2PreSyncAct = WPC2PreSyncAct_On;

    /* 1 */
  } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((App_Model_DW.Input_INT_WPC2IndSyncVal_prev != App_Model_DW.Input_INT_WPC2IndSyncVal_start) &&
              (App_Model_DW.Input_INT_WPC2IndSyncVal_start == WPC2IndSyncVal__Default)) && (App_Model_DW.Input_INT_WPC2IndSyncVal_prev != App_Model_DW.Input_INT_WPC2IndSyncVal_start)) {
    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
    App_Model_B.Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;
  }

  /* End of Chart: '<S385>/IND_Animation_WPC2_Priority_Flow_Graph' */

  /* Chart: '<S385>/IND_Animation_RWPC_Priority_Flow_Graph' */
  App_Model_DW.Input_CAN_RWPCIndSyncVal_prev = App_Model_DW.Input_CAN_RWPCIndSyncVal_start;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_start = rtu_Input_Data_a3;
  if (App_Model_DW.is_active_c34_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.Input_CAN_RWPCIndSyncVal_prev = rtu_Input_Data_a3;
    App_Model_DW.is_active_c34_Jdg_DualSyncOrder = 1U;

    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
    App_Model_B.Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;

    /* 1 */
    if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && (App_Model_DW.Input_CAN_RWPCIndSyncVal_prev == RWPCIndSyncVal__Default) &&
        (App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start)) {
      /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
      App_Model_B.Var_RWPCPreSyncAct = RWPCPreSyncAct_On;
    } else {
      /* 1 */
    }

    /* 1 */
  } else if ((App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) &&
              (App_Model_DW.Input_CAN_RWPCIndSyncVal_prev == RWPCIndSyncVal__Default)) && (App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start)) {
    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
    App_Model_B.Var_RWPCPreSyncAct = RWPCPreSyncAct_On;

    /* 1 */
  } else if ((App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) &&
              (App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Default))) {
    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
    App_Model_B.Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;
  }

  /* End of Chart: '<S385>/IND_Animation_RWPC_Priority_Flow_Graph' */

  /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph' */
  if (App_Model_DW.is_active_c32_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.is_active_c32_Jdg_DualSyncOrder = 1U;
    *rty_JdgDualOrder_j = PreSyncAct__Off;

    /* 1 */
    if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
      *rty_JdgDualOrder_j = PreSyncAct__WPC2;

      /* 1 */
    } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_JdgDualOrder_j = PreSyncAct__RWPC;

      /* 1 */
    } else if ((*rty_JdgDualOrder_j == PreSyncAct__WPC2) && (App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_JdgDualOrder_j = PreSyncAct__WPC2RWPC;

      /* 1 */
    } else if ((*rty_JdgDualOrder_j == PreSyncAct__RWPC) && (App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_JdgDualOrder_j = PreSyncAct__RWPCWPC2;

      /* 1 */
    } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
      *rty_JdgDualOrder_j = PreSyncAct__Off;
    }

    /* 1 */
  } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
    *rty_JdgDualOrder_j = PreSyncAct__WPC2;

    /* 1 */
  } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_JdgDualOrder_j = PreSyncAct__RWPC;

    /* 1 */
  } else if ((*rty_JdgDualOrder_j == PreSyncAct__WPC2) && (App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_JdgDualOrder_j = PreSyncAct__WPC2RWPC;

    /* 1 */
  } else if ((*rty_JdgDualOrder_j == PreSyncAct__RWPC) && (App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_JdgDualOrder_j = PreSyncAct__RWPCWPC2;

    /* 1 */
  } else if ((App_Model_B.Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
    *rty_JdgDualOrder_j = PreSyncAct__Off;
  }

  /* Chart: '<S385>/IND_Animation_WPC_Priority_Flow_Graph' */
  App_Model_DW.Input_INT_WPCIndSyncVal_prev = App_Model_DW.Input_INT_WPCIndSyncVal_start;
  App_Model_DW.Input_INT_WPCIndSyncVal_start = rtu_DWPC1_j;
  if (App_Model_DW.is_active_c36_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.Input_INT_WPCIndSyncVal_prev = rtu_DWPC1_j;
    App_Model_DW.is_active_c36_Jdg_DualSyncOrder = 1U;

    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph1' */
    App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;

    /* 1 */
    if ((App_Model_DW.Input_INT_WPCIndSyncVal_prev != App_Model_DW.Input_INT_WPCIndSyncVal_start) && (App_Model_DW.Input_INT_WPCIndSyncVal_prev == WPCIndSyncVal__Default) &&
        (App_Model_DW.Input_INT_WPCIndSyncVal_prev != App_Model_DW.Input_INT_WPCIndSyncVal_start)) {
      /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph1' */
      App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_On;
    } else {
      /* 1 */
    }

    /* 1 */
  } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_Off) && ((App_Model_DW.Input_INT_WPCIndSyncVal_prev != App_Model_DW.Input_INT_WPCIndSyncVal_start) &&
              (App_Model_DW.Input_INT_WPCIndSyncVal_prev == WPCIndSyncVal__Default)) && (App_Model_DW.Input_INT_WPCIndSyncVal_prev != App_Model_DW.Input_INT_WPCIndSyncVal_start)) {
    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph1' */
    App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_On;

    /* 1 */
  } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && ((App_Model_DW.Input_INT_WPCIndSyncVal_prev != App_Model_DW.Input_INT_WPCIndSyncVal_start) &&
              (App_Model_DW.Input_INT_WPCIndSyncVal_start == WPCIndSyncVal__Default)) && (App_Model_DW.Input_INT_WPCIndSyncVal_prev != App_Model_DW.Input_INT_WPCIndSyncVal_start)) {
    /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph1' */
    App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;
  }

  /* End of Chart: '<S385>/IND_Animation_WPC_Priority_Flow_Graph' */

  /* Chart: '<S385>/IND_Animation_Priority_Flow_Graph1' */
  if (App_Model_DW.is_active_c33_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.is_active_c33_Jdg_DualSyncOrder = 1U;
    *rty_JdgDualOrder_f = PreSyncAct__Off;

    /* 1 */
    if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
      *rty_JdgDualOrder_f = PreSyncAct__WPC;

      /* 1 */
    } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_JdgDualOrder_f = PreSyncAct__RWPC;

      /* 1 */
    } else if ((*rty_JdgDualOrder_f == PreSyncAct__WPC) && (App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_JdgDualOrder_f = PreSyncAct__WPCRWPC;

      /* 1 */
    } else if ((*rty_JdgDualOrder_f == PreSyncAct__RWPC) && (App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_JdgDualOrder_f = PreSyncAct__RWPCWPC;

      /* 1 */
    } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
      *rty_JdgDualOrder_f = PreSyncAct__Off;
    }

    /* 1 */
  } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
    *rty_JdgDualOrder_f = PreSyncAct__WPC;

    /* 1 */
  } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_JdgDualOrder_f = PreSyncAct__RWPC;

    /* 1 */
  } else if ((*rty_JdgDualOrder_f == PreSyncAct__WPC) && (App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_JdgDualOrder_f = PreSyncAct__WPCRWPC;

    /* 1 */
  } else if ((*rty_JdgDualOrder_f == PreSyncAct__RWPC) && (App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_JdgDualOrder_f = PreSyncAct__RWPCWPC;

    /* 1 */
  } else if ((App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_Off) && (App_Model_B.Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
    *rty_JdgDualOrder_f = PreSyncAct__Off;
  }

  /* Chart: '<S384>/DWPC1_Amber_Sync_Chart' */
  App_Model_DW.Output_INT_WPCIndCmdState_prev = App_Model_DW.Output_INT_WPCIndCmdState_start;
  App_Model_DW.Output_INT_WPCIndCmdState_start = rtu_DWPC1_l;
  if (App_Model_DW.is_active_c6_Jdg_DualSyncOrder_ == 0U) {
    App_Model_DW.Output_INT_WPCIndCmdState_prev = rtu_DWPC1_l;
    App_Model_DW.is_active_c6_Jdg_DualSyncOrder_ = 1U;
    App_Model_DW.is_SyncTrigger_f = App_Model_IN_SyncTriggerOff_f;
    *rty_JdgDualOrder_g = Off;
  } else if (App_Model_DW.is_SyncTrigger_f == App_Model_IN_SyncTriggerOff_f) {
    WPCIndCmdState tmp_a;
    WPCIndCmdState tmp_b;
    *rty_JdgDualOrder_g = Off;
    tmp_a = App_Model_DW.Output_INT_WPCIndCmdState_prev;
    tmp_b = App_Model_DW.Output_INT_WPCIndCmdState_start;
    if (((tmp_a != tmp_b) && (tmp_a == WPCIndCmdState__ErrorOn)) || ((tmp_a != tmp_b) && (tmp_a == WPCIndCmdState__ErrorFadeOut)) || ((tmp_a != tmp_b) && (tmp_a == WPCIndCmdState__ErrorFadeIn))) {
      App_Model_DW.is_SyncTrigger_f = App_Model_IN_SyncTriggerOn_b;
      *rty_JdgDualOrder_g = On;
    }
  } else {
    WPCIndCmdState tmp_a;
    WPCIndCmdState tmp_b;

    /* case IN_SyncTriggerOn: */
    *rty_JdgDualOrder_g = On;

    /* hasChangedTo(Output_INT_WPCIndCmdState, WPCIndCmdState__3rdChrgFadeOut)||...hasChangedTo(Output_INT_WPCIndCmdState, WPCIndCmdState__2ndChrgFadeOut)||...hasChangedTo(Output_INT_WPCIndCmdState, WPCIndCmdState__1stChrgFadeOut)||... */
    tmp_a = App_Model_DW.Output_INT_WPCIndCmdState_start;
    tmp_b = App_Model_DW.Output_INT_WPCIndCmdState_prev;
    if (((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__ErrorOn)) || ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__ChrgFadeOut)) || ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__3rdChrgOn)) ||
        ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__3rdChrgFadeIn)) || ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__2ndChrgOn)) || ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__2ndChrgFadeIn)) ||
        ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__1stChrgOn)) || ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__1stChrgFadeIn)) || ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__ChrgOff)) ||
        ((tmp_b != tmp_a) && (tmp_a == WPCIndCmdState__Default))) {
      App_Model_DW.is_SyncTrigger_f = App_Model_IN_SyncTriggerOff_f;
      *rty_JdgDualOrder_g = Off;
    }
  }

  /* End of Chart: '<S384>/DWPC1_Amber_Sync_Chart' */

  /* Chart: '<S384>/DWPC1_LED_Sync_Indy' */
  App_Model_DWPC1_LED_Sync_Indy(rtu_DWPC1_f, *rty_JdgDualOrder_g, rtu_DWPC1_g, rty_JdgDualOrder_p, &App_Model_DW.sf_DWPC1_LED_Sync_Indy);

  /* Chart: '<S384>/DWPC2_Amber_Sync_Chart' */
  App_Model_DW.Output_INT_WPC2IndCmdState_prev = App_Model_DW.Output_INT_WPC2IndCmdState_star;
  App_Model_DW.Output_INT_WPC2IndCmdState_star = rtu_DWPC2_j;
  if (App_Model_DW.is_active_c11_Jdg_DualSyncOrder == 0U) {
    App_Model_DW.Output_INT_WPC2IndCmdState_prev = rtu_DWPC2_j;
    App_Model_DW.is_active_c11_Jdg_DualSyncOrder = 1U;
    App_Model_DW.is_SyncTrigger = App_Model_IN_SyncTriggerOff_f;
    *rty_JdgDualOrder_jt = Off;
  } else if (App_Model_DW.is_SyncTrigger == App_Model_IN_SyncTriggerOff_f) {
    WPC2IndCmdState tmp_c;
    WPC2IndCmdState tmp_d;
    *rty_JdgDualOrder_jt = Off;
    tmp_c = App_Model_DW.Output_INT_WPC2IndCmdState_prev;
    tmp_d = App_Model_DW.Output_INT_WPC2IndCmdState_star;
    if (((tmp_c != tmp_d) && (tmp_c == WPC2IndCmdState__ErrorOn)) || ((tmp_c != tmp_d) && (tmp_c == WPC2IndCmdState__ErrorFadeOut)) || ((tmp_c != tmp_d) && (tmp_c == WPC2IndCmdState__ErrorFadeIn))) {
      App_Model_DW.is_SyncTrigger = App_Model_IN_SyncTriggerOn_b;
      *rty_JdgDualOrder_jt = On;
    }
  } else {
    WPC2IndCmdState tmp_c;
    WPC2IndCmdState tmp_d;

    /* case IN_SyncTriggerOn: */
    *rty_JdgDualOrder_jt = On;

    /* hasChangedTo(Output_INT_WPC2IndCmdState, WPC2IndCmdState__3rdChrgFadeOut)||...hasChangedTo(Output_INT_WPC2IndCmdState, WPC2IndCmdState__2ndChrgFadeOut)||...hasChangedTo(Output_INT_WPC2IndCmdState, WPC2IndCmdState__1stChrgFadeOut)||... */
    tmp_c = App_Model_DW.Output_INT_WPC2IndCmdState_star;
    tmp_d = App_Model_DW.Output_INT_WPC2IndCmdState_prev;
    if (((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__ErrorOn)) || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__ChrgFadeOut)) || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__3rdChrgOn)) ||
        ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__3rdChrgFadeIn)) || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__2ndChrgOn)) || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__2ndChrgFadeIn))
        || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__1stChrgOn)) || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__1stChrgFadeIn)) || ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__ChrgOff)) ||
        ((tmp_d != tmp_c) && (tmp_c == WPC2IndCmdState__Default))) {
      App_Model_DW.is_SyncTrigger = App_Model_IN_SyncTriggerOff_f;
      *rty_JdgDualOrder_jt = Off;
    }
  }

  /* End of Chart: '<S384>/DWPC2_Amber_Sync_Chart' */

  /* Chart: '<S384>/DWPC2_LED_Sync_Indy' */
  App_Model_DWPC1_LED_Sync_Indy(rtu_DWPC2_c, *rty_JdgDualOrder_jt, rtu_DWPC2_e, rty_JdgDualOrder_h, &App_Model_DW.sf_DWPC2_LED_Sync_Indy);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
