/*
 * File: Jdg_DualOrder.h
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

#ifndef RTW_HEADER_Jdg_DualOrder_h_
#define RTW_HEADER_Jdg_DualOrder_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S384>/DWPC1_LED_Sync_Indy' */
typedef struct {
  uint8 is_active_c10_Jdg_DualSyncOrder;/* '<S384>/DWPC1_LED_Sync_Indy' */
  uint8 is_SyncTrigger;                /* '<S384>/DWPC1_LED_Sync_Indy' */
  Bool b_BlinkState_prev;              /* '<S384>/DWPC1_LED_Sync_Indy' */
  Bool b_BlinkState_start;             /* '<S384>/DWPC1_LED_Sync_Indy' */
  Bool b_CmdLEDSync_prev;              /* '<S384>/DWPC1_LED_Sync_Indy' */
  Bool b_CmdLEDSync_start;             /* '<S384>/DWPC1_LED_Sync_Indy' */
  BlinkState BlinkState_prev;          /* '<S384>/DWPC1_LED_Sync_Indy' */
  BlinkState BlinkState_start;         /* '<S384>/DWPC1_LED_Sync_Indy' */
} DW_DWPC1_LED_Sync_Indy_App_Mo_T;

extern void App_Mo_DWPC1_LED_Sync_Indy_Init(Bool *rty_b_SyncLED);
extern void App_Model_DWPC1_LED_Sync_Indy(Bool rtu_b_BlinkState, Bool rtu_b_CmdLEDSync, BlinkState rtu_BlinkState, Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW);
extern void App_Model_Jdg_DualOrder_Init(uint8 *rty_JdgDualOrder, uint8 *rty_JdgDualOrder_l, PreSyncAct *rty_JdgDualOrder_j, PreSyncAct *rty_JdgDualOrder_f, Bool *rty_JdgDualOrder_g, Bool
  *rty_JdgDualOrder_p, Bool *rty_JdgDualOrder_jt, Bool *rty_JdgDualOrder_h, Bool *rty_JdgDualOrder_c, Bool *rty_JdgDualOrder_e, Bool *rty_JdgDualOrder_k);
extern void App_Model_Jdg_DualOrder(WPCStatus rtu_DWPC1, WPCIndCmdState rtu_DWPC1_l, C_WPCIndSyncVal rtu_DWPC1_j, Bool rtu_DWPC1_f, BlinkState rtu_DWPC1_g, WPCStatus rtu_DWPC2, WPC2IndCmdState
  rtu_DWPC2_j, WPC2IndSyncVal rtu_DWPC2_h, Bool rtu_DWPC2_c, BlinkState rtu_DWPC2_e, OnThePad rtu_Input_Data, OnThePad rtu_Input_Data_c, OnThePad rtu_Input_Data_a, OnThePad rtu_Input_Data_j, OnThePad
  rtu_Input_Data_h, OnThePad rtu_Input_Data_o, Bool rtu_Input_Data_p, Bool rtu_Input_Data_m, LC_WPC_NFCDetection rtu_Input_Data_l, LC_WPC_NFCDetection rtu_Input_Data_d, RWPCIndSyncVal
  rtu_Input_Data_a3, uint8 *rty_JdgDualOrder, uint8 *rty_JdgDualOrder_l, PreSyncAct *rty_JdgDualOrder_j, PreSyncAct *rty_JdgDualOrder_f, Bool *rty_JdgDualOrder_g, Bool *rty_JdgDualOrder_p, Bool
  *rty_JdgDualOrder_jt, Bool *rty_JdgDualOrder_h, Bool *rty_JdgDualOrder_c, Bool *rty_JdgDualOrder_e, Bool *rty_JdgDualOrder_k);

#endif                                 /* RTW_HEADER_Jdg_DualOrder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
