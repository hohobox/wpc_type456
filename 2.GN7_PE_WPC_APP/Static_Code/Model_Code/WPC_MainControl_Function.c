/*
 * File: WPC_MainControl_Function.c
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
#include "rtwtypes.h"
#include "WPC_MainControl_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
#define A_event_Cancel_Timer_CardINDBlk (2)
#define A_event_Start_Timer_AmberINDBlk (7)
#define Ap_event_Cancel_Timer_PhoneLeft (3)
#define Ap_event_Start_Timer_CardINDBlk (9)
#define App_M_IN_LeavingPhone_NoWarning ((uint8)1U)
#define App_Mod_IN_LeavingPhone_Warning ((uint8)2U)
#define App_Model_CALL_EVENT_j         (-1)
#define App_Model_IN_CardDetectError   ((uint8)1U)
#define App_Model_IN_NO_ACTIVE_CHILD_o ((uint8)0U)
#define App_Model_IN_Off_o             ((uint8)1U)
#define App_Model_IN_On_d              ((uint8)2U)
#define App_Model_IN_WPCMode_Disable   ((uint8)1U)
#define App_Model_IN_WPCMode_Enable    ((uint8)2U)
#define App_Model_IN_WPCMode_Init      ((uint8)3U)
#define App_Model_IN_WPCMode_NFC       ((uint8)1U)
#define App_Model_IN_WPCMode_Off       ((uint8)2U)
#define App_Model_IN_WPCMode_Run       ((uint8)1U)
#define App_Model_IN_WPCMode_Stop      ((uint8)2U)
#define App_Model_IN_WPCRun_Charging   ((uint8)1U)
#define App_Model_IN_WPCRun_FODError   ((uint8)3U)
#define App_Model_IN_WPCRun_Standby    ((uint8)4U)
#define App_Model_IN_WPCStop_NotTempErr ((uint8)2U)
#define App_Model_IN_WPCStop_TempErr   ((uint8)3U)
#define App__IN_WPCRun_ChargingComplete ((uint8)2U)
#define App_event_Start_Timer_PhoneLeft (10)
#define event_Cancel_Timer_AmberINDBlk (0)
#define event_Cancel_Timer_AmberINDBlk2 (1)
#define event_Cancel_Timer_PhoneReminde (4)
#define event_Cancel_Timer_PhoneWarning (5)
#define event_Cancel_Timer_WarningCompl (6)
#define event_Start_Timer_AmberINDBlk2 (8)
#define event_Start_Timer_PhoneReminder (11)
#define event_Start_Timer_PhoneWarningC (12)
#define event_Start_Timer_WarningComple (13)

/* Named constants for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
#define A_event_Start_Timer_PhoneLeft_d (10)
#define Ap_IN_WPCRun_ChargingComplete_g ((uint8)2U)
#define App_IN_LeavingPhone_NoWarning_n ((uint8)1U)
#define App_M_IN_LeavingPhone_Warning_k ((uint8)2U)
#define App_Mod_IN_WPCStop_NotTempErr_b ((uint8)2U)
#define App_Model_CALL_EVENT_de        (-1)
#define App_Model_IN_CardDetectError_o ((uint8)1U)
#define App_Model_IN_NO_ACTIVE_CHILD_ef ((uint8)0U)
#define App_Model_IN_Off_h             ((uint8)1U)
#define App_Model_IN_On_a              ((uint8)2U)
#define App_Model_IN_WPCMode_Disable_l ((uint8)1U)
#define App_Model_IN_WPCMode_Enable_o  ((uint8)2U)
#define App_Model_IN_WPCMode_Init_n    ((uint8)3U)
#define App_Model_IN_WPCMode_NFC_b     ((uint8)1U)
#define App_Model_IN_WPCMode_Off_i     ((uint8)2U)
#define App_Model_IN_WPCMode_Run_f     ((uint8)1U)
#define App_Model_IN_WPCMode_Stop_h    ((uint8)2U)
#define App_Model_IN_WPCRun_Charging_f ((uint8)1U)
#define App_Model_IN_WPCRun_FODError_g ((uint8)3U)
#define App_Model_IN_WPCRun_Standby_m  ((uint8)4U)
#define App_Model_IN_WPCStop_TempErr_f ((uint8)3U)
#define event_Cancel_Timer_AmberINDBl_d (1)
#define event_Cancel_Timer_AmberINDBl_j (0)
#define event_Cancel_Timer_CardINDBlk_b (2)
#define event_Cancel_Timer_PhoneLeft_p (3)
#define event_Cancel_Timer_PhoneRemin_l (4)
#define event_Cancel_Timer_PhoneWarni_a (5)
#define event_Cancel_Timer_WarningCom_g (6)
#define event_Start_Timer_AmberINDBlk_b (8)
#define event_Start_Timer_AmberINDBlk_g (7)
#define event_Start_Timer_CardINDBlk_g (9)
#define event_Start_Timer_PhoneRemind_i (11)
#define event_Start_Timer_PhoneWarnin_g (12)
#define event_Start_Timer_WarningComp_g (13)

/* Forward declaration for local functions */
static void App_M_Function_ChargingINDColor(WPCIndUSMState rtu_Main_InSig_lz, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g);
static void App_Mod_Tick_Timer_AmberINDBlk2(void);
static void App_Mode_Tick_Timer_AmberINDBlk(void);
static void App_Mode_Function_LEDErrorBlink(WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h);
static void App_M_exit_internal_WPCMode_Run(Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h);
static void App_Model_Tick_Timer_CardINDBlk(void);
static void App__Function_CardLEDErrorBlink(Bool rtu_Main_InSig_h0, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h);
static void App_enter_internal_WPCMode_Stop(Bool rtu_Main_InSig_gy, WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, Bool rtu_Main_InSig_f, C_WPCWarning *rty_MainOut_Sig, Bool
  *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h);
static void App_Model_WPCMode_Run(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m, Bool rtu_Main_InSig_l, Bool rtu_Main_InSig_gy, DeviceState rtu_Main_InSig_a, WPCIndUSMState rtu_Main_InSig_lz, Bool
  rtu_Main_InSig_h0, Bool rtu_Main_InSig_f, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, Bool *rty_MainOut_Sig_a,
  BlinkState *rty_MainOut_Sig_h);
static void App__exit_internal_WPCMode_Stop(Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h);
static void Ap_enter_atomic_WPCMode_Disable(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, BlinkState *rty_MainOut_Sig_h, Bool
  *rty_MainOut_Sig_k);
static void App_Model_Tick_Timer_PhoneLeft(void);
static void Ap_Tick_Timer_PhoneWarningCheck(uint16 *rty_MainOut_Sig_j);
static void A_Tick_Timer_PhoneReminderCheck(uint16 *rty_MainOut_Sig_b);
static void App__Tick_Timer_WarningComplete(uint16 *rty_MainOut_Sig_jy);
static void App_Model_Function_WPCWarning(C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_b, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, C_WPCWarning *rty_MainOut_Sig, uint16
  *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_k);
static void App_Mo_enter_atomic_WPCMode_NFC(uint16 *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy);
static void enter_internal_WPCMode_Disable(C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_b, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, WPCStatus rtu_Main_InSig_h, C_WPCWarning
  *rty_MainOut_Sig, uint16 *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_k);
static void App_Model_MainControl(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m, Bool rtu_Main_InSig_l, C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_gy, Bool rtu_Main_InSig_b, Bool
  rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, DeviceState rtu_Main_InSig_a, WPCStatus rtu_Main_InSig_h, WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, Bool rtu_Main_InSig_f, C_WPCWarning
  *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, uint16 *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16
  *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h, Bool *rty_MainOut_Sig_k);
static void enter_internal_Tick_Timer_Phone(void);
static void enter_internal_Tick_Timer_Pho_b(uint16 *rty_MainOut_Sig_j);
static void enter_internal_Tick_Timer_Pho_g(uint16 *rty_MainOut_Sig_b);
static void enter_internal_Tick_Timer_Warni(uint16 *rty_MainOut_Sig_jy);
static void enter_internal_Tick_Timer_Amber(void);
static void enter_internal_Tick_Timer_Amb_d(void);
static void enter_internal_Tick_Timer_CardI(void);

/* Forward declaration for local functions */
static void App_Function_ChargingINDColor_k(WPCIndUSMState rtu_Main_InSig_nw, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e);
static void App_M_Tick_Timer_AmberINDBlk2_l(void);
static void App_Mo_Tick_Timer_AmberINDBlk_h(void);
static void App_Mo_Function_LEDErrorBlink_l(WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po);
static void App_exit_internal_WPCMode_Run_p(Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po);
static void App_Mod_Tick_Timer_CardINDBlk_o(void);
static void Ap_Function_CardLEDErrorBlink_l(Bool rtu_Main_InSig_h, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po);
static void A_enter_internal_WPCMode_Stop_f(Bool rtu_Main_InSig_gc, WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, Bool rtu_Main_InSig_jg, C_WPCWarning *rty_MainOut_Sig, Bool
  *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po);
static void App_Model_WPCMode_Run_g(Bool rtu_Main_InSig, Bool rtu_Main_InSig_g, Bool rtu_Main_InSig_b, Bool rtu_Main_InSig_gc, DeviceState rtu_Main_InSig_p, WPCIndUSMState rtu_Main_InSig_nw, Bool
  rtu_Main_InSig_h, Bool rtu_Main_InSig_jg, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, Bool *rty_MainOut_Sig_p,
  BlinkState *rty_MainOut_Sig_po);
static void Ap_exit_internal_WPCMode_Stop_b(Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po);
static void enter_atomic_WPCMode_Disable_i(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, BlinkState *rty_MainOut_Sig_po, Bool
  *rty_MainOut_Sig_k);
static void App_Mode_Tick_Timer_PhoneLeft_k(void);
static void Tick_Timer_PhoneWarningCheck_f(uint16 *rty_MainOut_Sig_n);
static void Tick_Timer_PhoneReminderCheck_h(uint16 *rty_MainOut_Sig_j);
static void Ap_Tick_Timer_WarningComplete_a(uint16 *rty_MainOut_Sig_nt);
static void App_Model_Function_WPCWarning_k(C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, C_WPCWarning *rty_MainOut_Sig, uint16
  *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_k);
static void App__enter_atomic_WPCMode_NFC_f(uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt);
static void enter_internal_WPCMode_Disabl_g(C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, WPCStatus rtu_Main_InSig_po, C_WPCWarning
  *rty_MainOut_Sig, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_k);
static void App_Model_MainControl_k(Bool rtu_Main_InSig, Bool rtu_Main_InSig_g, Bool rtu_Main_InSig_b, C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_gc, Bool rtu_Main_InSig_j, Bool
  rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, DeviceState rtu_Main_InSig_p, WPCStatus rtu_Main_InSig_po, WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, Bool rtu_Main_InSig_jg, C_WPCWarning
  *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16
  *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k);
static void enter_internal_Tick_Timer_Pho_a(void);
static void enter_internal_Tick_Timer_Pho_n(uint16 *rty_MainOut_Sig_n);
static void enter_internal_Tick_Timer_Pho_p(uint16 *rty_MainOut_Sig_j);
static void enter_internal_Tick_Timer_War_n(uint16 *rty_MainOut_Sig_nt);
static void enter_internal_Tick_Timer_Amb_a(void);
static void enter_internal_Tick_Timer_Am_ar(void);
static void enter_internal_Tick_Timer_Car_g(void);

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_M_Function_ChargingINDColor(WPCIndUSMState rtu_Main_InSig_lz, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g)
{
  /* 1. */
  if (rtu_Main_InSig_lz == WPCIndUSMState__Type2) {
    *rty_MainOut_Sig_l = On;
    *rty_MainOut_Sig_g = Off;
  } else {
    *rty_MainOut_Sig_l = Off;
    *rty_MainOut_Sig_g = On;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Mod_Tick_Timer_AmberINDBlk2(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2_o) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == event_Start_Timer_AmberINDBlk2) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2_o = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == event_Cancel_Timer_AmberINDBlk2) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2_o = App_Model_IN_Off_o;
        App_Model_DW.Timer_AmberINDBlk2_p = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_AmberINDBlk2_p + 1;
        if (App_Model_DW.Timer_AmberINDBlk2_p + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2_p = (uint16)tmp;
        if (App_Model_DW.sfEvent_f == event_Start_Timer_AmberINDBlk2) {
          App_Model_DW.Timer_AmberINDBlk2_p = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Mode_Tick_Timer_AmberINDBlk(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk_b) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == A_event_Start_Timer_AmberINDBlk) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk_b = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == event_Cancel_Timer_AmberINDBlk) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk_b = App_Model_IN_Off_o;
        App_Model_DW.Timer_AmberINDBlk_i = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_AmberINDBlk_i + 1;
        if (App_Model_DW.Timer_AmberINDBlk_i + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk_i = (uint16)tmp;
        if (App_Model_DW.sfEvent_f == A_event_Start_Timer_AmberINDBlk) {
          App_Model_DW.Timer_AmberINDBlk_i = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Mode_Function_LEDErrorBlink(WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h)
{
  switch (rtu_Main_InSig_h0) {
   case Off:
    {
      /* ForFODError%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if ((*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_j >= 10)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
        *rty_MainOut_Sig_gy = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_j >= 10) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
        *rty_MainOut_Sig_gy = Off;

        /*  Non GFS  */
      } else if ((rtu_Main_InSig_lz == WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk2_o == App_Model_IN_Off_o)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOn;
        *rty_MainOut_Sig_g = On;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Start_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
      } else if ((rtu_Main_InSig_lz != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk_b == App_Model_IN_Off_o)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_MainOut_Sig_g = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Start_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h == BlinkOff) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) &&
                  (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_h = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_j++;
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Start_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h == BlinkOn) && (((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) &&
                   (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_start
        == WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_h = BlinkOff;
        *rty_MainOut_Sig_g = On;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Start_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz == WPCIndUSMState__Type2) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOn;
        *rty_MainOut_Sig_g = On;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Start_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz == WPCIndUSMState__Type2) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_j++;

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Start_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
      }
    }
    break;

   case On:
    {
      /* ForFODError%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if ((*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_j >= 10)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
        *rty_MainOut_Sig_gy = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_j >= 10) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
        *rty_MainOut_Sig_gy = Off;

        /*  Non GFS  */
      } else if ((rtu_Main_InSig_lz == WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk2_o == App_Model_IN_Off_o)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOn;
        *rty_MainOut_Sig_g = On;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Start_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
      } else if ((rtu_Main_InSig_lz != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk_b == App_Model_IN_Off_o)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_MainOut_Sig_g = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Start_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h == BlinkOff) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) &&
                  (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_h = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_j++;
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Start_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_h == BlinkOn) && (((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) &&
                   (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_start
        == WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_h = BlinkOff;
        *rty_MainOut_Sig_g = On;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Start_Timer_AmberINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz == WPCIndUSMState__Type2) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOn;
        *rty_MainOut_Sig_g = On;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Start_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_lz == WPCIndUSMState__Type2) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_h = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_j++;

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_MainOut_Sig_g = Off;
        t_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Start_Timer_AmberINDBlk2;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2();
        }

        App_Model_DW.sfEvent_f = t_previousEvent;
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_M_exit_internal_WPCMode_Run(Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h)
{
  if (App_Model_DW.is_WPCMode_Run_f == App_Model_IN_WPCRun_FODError) {
    sint32 b_previousEvent;
    *rty_MainOut_Sig_h = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_j = 0U;
    b_previousEvent = App_Model_DW.sfEvent_f;
    App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
    if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
      App_Mode_Tick_Timer_AmberINDBlk();
    }

    App_Model_DW.sfEvent_f = b_previousEvent;

    /*  Non GFS  */
    *rty_MainOut_Sig_gy = Off;
    App_Model_DW.is_WPCMode_Run_f = App_Model_IN_NO_ACTIVE_CHILD_o;
  } else {
    App_Model_DW.is_WPCMode_Run_f = App_Model_IN_NO_ACTIVE_CHILD_o;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Model_Tick_Timer_CardINDBlk(void)
{
  switch (App_Model_DW.is_Tick_Timer_CardINDBlk_d) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == Ap_event_Start_Timer_CardINDBlk) {
      App_Model_DW.is_Tick_Timer_CardINDBlk_d = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == A_event_Cancel_Timer_CardINDBlk) {
        App_Model_DW.is_Tick_Timer_CardINDBlk_d = App_Model_IN_Off_o;
        App_Model_DW.Timer_CardINDBlk_n = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_CardINDBlk_n + 1;
        if (App_Model_DW.Timer_CardINDBlk_n + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_CardINDBlk_n = (uint16)tmp;
        if (App_Model_DW.sfEvent_f == Ap_event_Start_Timer_CardINDBlk) {
          App_Model_DW.Timer_CardINDBlk_n = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App__Function_CardLEDErrorBlink(Bool rtu_Main_InSig_h0, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h)
{
  switch (rtu_Main_InSig_h0) {
   case Off:
    {
      /* ForCardError%WPC가 하나이거나 우선순위가 가장 높을경우 */
      if ((*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_j >= 2)) {
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_l = Off;
        *rty_MainOut_Sig_gy = Off;
      } else if (App_Model_DW.Counter_BlinkCnt_j > 2) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_l = Off;
        d_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Cancel_Timer_CardINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
          App_Model_Tick_Timer_CardINDBlk();
        }

        App_Model_DW.sfEvent_f = d_previousEvent;
        *rty_MainOut_Sig_gy = Off;
      } else if ((*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.is_Tick_Timer_CardINDBlk_d == App_Model_IN_Off_o)) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_h = BlinkOff;
        *rty_MainOut_Sig_l = Off;
        d_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = Ap_event_Start_Timer_CardINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
          App_Model_Tick_Timer_CardINDBlk();
        }

        App_Model_DW.sfEvent_f = d_previousEvent;
      } else if ((*rty_MainOut_Sig_h == BlinkOn) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        *rty_MainOut_Sig_h = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_j++;
        *rty_MainOut_Sig_l = Off;
      } else if ((*rty_MainOut_Sig_h == BlinkOff) && (((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) ||
                  ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_start == WPCIndCmdState__ErrorOn)))) {
        *rty_MainOut_Sig_h = BlinkOn;

        /* Counter_BlinkCnt ++; */
        *rty_MainOut_Sig_l = On;
      }
    }
    break;

   case On:
    {
      /* ForCardError%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      if ((*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_j >= 2)) {
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_l = Off;
        *rty_MainOut_Sig_gy = Off;
      } else if (App_Model_DW.Counter_BlinkCnt_j >= 2) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_h = BlinkComplete;
        *rty_MainOut_Sig_l = Off;
        d_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = A_event_Cancel_Timer_CardINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
          App_Model_Tick_Timer_CardINDBlk();
        }

        App_Model_DW.sfEvent_f = d_previousEvent;
        *rty_MainOut_Sig_gy = Off;
      } else if ((*rty_MainOut_Sig_h != BlinkComplete) && (App_Model_DW.is_Tick_Timer_CardINDBlk_d == App_Model_IN_Off_o)) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_h = BlinkOff;
        *rty_MainOut_Sig_l = Off;
        d_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = Ap_event_Start_Timer_CardINDBlk;
        if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
          App_Model_Tick_Timer_CardINDBlk();
        }

        App_Model_DW.sfEvent_f = d_previousEvent;
      } else if ((*rty_MainOut_Sig_h == BlinkOn) && ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        *rty_MainOut_Sig_h = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_j++;
        *rty_MainOut_Sig_l = Off;
      } else if ((*rty_MainOut_Sig_h == BlinkOff) && (((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) ||
                  ((App_Model_DW.WPCIndCmdState_prev != App_Model_DW.WPCIndCmdState_start) && (App_Model_DW.WPCIndCmdState_start == WPCIndCmdState__ErrorOn)))) {
        *rty_MainOut_Sig_h = BlinkOn;

        /* Counter_BlinkCnt ++; */
        *rty_MainOut_Sig_l = On;
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_enter_internal_WPCMode_Stop(Bool rtu_Main_InSig_gy, WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, Bool rtu_Main_InSig_f, C_WPCWarning *rty_MainOut_Sig, Bool
  *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h)
{
  /* 1. */
  if (rtu_Main_InSig_gy == On) {
    App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_WPCStop_TempErr;

    /* 240926 */
    *rty_MainOut_Sig_a = Off;
    *rty_MainOut_Sig = Charging_error;
    *rty_MainOut_Sig_h = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_j = 0U;
    App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
    *rty_MainOut_Sig_gy = On;
  } else if (rtu_Main_InSig_f == On) {
    /* CardDetect_Nidec] */
    App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_CardDetectError;
    *rty_MainOut_Sig = NFCCardDetected;
    *rty_MainOut_Sig_h = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_j = 0U;
    *rty_MainOut_Sig_g = Off;
    App__Function_CardLEDErrorBlink(rtu_Main_InSig_h0, rty_MainOut_Sig_l, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
    *rty_MainOut_Sig_gy = On;
  } else {
    App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_WPCStop_NotTempErr;

    /* 240926 */
    *rty_MainOut_Sig_a = Off;
    *rty_MainOut_Sig = WPCWarningOff;
    *rty_MainOut_Sig_g = Off;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Model_WPCMode_Run(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m, Bool rtu_Main_InSig_l, Bool rtu_Main_InSig_gy, DeviceState rtu_Main_InSig_a, WPCIndUSMState rtu_Main_InSig_lz, Bool
  rtu_Main_InSig_h0, Bool rtu_Main_InSig_f, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, Bool *rty_MainOut_Sig_a,
  BlinkState *rty_MainOut_Sig_h)
{
  /* 1. */
  if ((rtu_Main_InSig == On) || (rtu_Main_InSig_m == On) || (rtu_Main_InSig_l == On) || (rtu_Main_InSig_gy == On) || (rtu_Main_InSig_f == On)) {
    /* CardDetect_Nidec] */
    App_M_exit_internal_WPCMode_Run(rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
    App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Stop;
    *rty_MainOut_Sig_m = Off;
    *rty_MainOut_Sig_l = Off;

    /* b_ChargingEnable = Off */
    App_enter_internal_WPCMode_Stop(rtu_Main_InSig_gy, rtu_Main_InSig_lz, rtu_Main_InSig_h0, rtu_Main_InSig_f, rty_MainOut_Sig, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_gy,
      rty_MainOut_Sig_a, rty_MainOut_Sig_h);
  } else {
    switch (App_Model_DW.is_WPCMode_Run_f) {
     case App_Model_IN_WPCRun_Charging:
      *rty_MainOut_Sig_m = On;

      /* 1. */
      if ((rtu_Main_InSig_a == Standby) || (rtu_Main_InSig_a == Init)) {
        App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Standby;
        *rty_MainOut_Sig = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_MainOut_Sig_m = Off;
        *rty_MainOut_Sig_l = Off;
        *rty_MainOut_Sig_g = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_a) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_FODError;
          *rty_MainOut_Sig = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_MainOut_Sig_h = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_j = 0U;
          *rty_MainOut_Sig_m = Off;
          *rty_MainOut_Sig_l = Off;
          App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);

          /*  Non GFS  */
          *rty_MainOut_Sig_gy = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_f = App__IN_WPCRun_ChargingComplete;
          *rty_MainOut_Sig = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_MainOut_Sig_m = On;
          *rty_MainOut_Sig_l = On;
          *rty_MainOut_Sig_g = Off;
          break;

         default:
          App_M_Function_ChargingINDColor(rtu_Main_InSig_lz, rty_MainOut_Sig_l, rty_MainOut_Sig_g);
          break;
        }
      }
      break;

     case App__IN_WPCRun_ChargingComplete:
      *rty_MainOut_Sig_m = On;

      /* 1. */
      if ((rtu_Main_InSig_a == Standby) || (rtu_Main_InSig_a == Init)) {
        App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Standby;
        *rty_MainOut_Sig = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_MainOut_Sig_m = Off;
        *rty_MainOut_Sig_l = Off;
        *rty_MainOut_Sig_g = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_a) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_FODError;
          *rty_MainOut_Sig = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_MainOut_Sig_h = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_j = 0U;
          *rty_MainOut_Sig_m = Off;
          *rty_MainOut_Sig_l = Off;
          App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);

          /*  Non GFS  */
          *rty_MainOut_Sig_gy = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Charging;
          *rty_MainOut_Sig = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_MainOut_Sig_m = On;
          App_M_Function_ChargingINDColor(rtu_Main_InSig_lz, rty_MainOut_Sig_l, rty_MainOut_Sig_g);
          break;
        }
      }
      break;

     case App_Model_IN_WPCRun_FODError:
      {
        *rty_MainOut_Sig_m = Off;

        /* 1. */
        if ((rtu_Main_InSig_a == Standby) || (rtu_Main_InSig_a == Init)) {
          sint32 c_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          *rty_MainOut_Sig_h = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_j = 0U;
          c_previousEvent = App_Model_DW.sfEvent_f;
          App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
          if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
            App_Mode_Tick_Timer_AmberINDBlk();
          }

          App_Model_DW.sfEvent_f = c_previousEvent;

          /*  Non GFS  */
          *rty_MainOut_Sig_gy = Off;
          App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Standby;
          *rty_MainOut_Sig = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          *rty_MainOut_Sig_m = Off;
          *rty_MainOut_Sig_l = Off;
          *rty_MainOut_Sig_g = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_a) {
           case Charging:
            {
              sint32 c_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_MainOut_Sig_h = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_j = 0U;
              c_previousEvent = App_Model_DW.sfEvent_f;
              App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
              if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
                App_Mode_Tick_Timer_AmberINDBlk();
              }

              App_Model_DW.sfEvent_f = c_previousEvent;

              /*  Non GFS  */
              *rty_MainOut_Sig_gy = Off;
              App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Charging;
              *rty_MainOut_Sig = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_MainOut_Sig_m = On;
              App_M_Function_ChargingINDColor(rtu_Main_InSig_lz, rty_MainOut_Sig_l, rty_MainOut_Sig_g);
            }
            break;

           case Full_Charge:
            {
              sint32 c_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_MainOut_Sig_h = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_j = 0U;
              c_previousEvent = App_Model_DW.sfEvent_f;
              App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
              if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
                App_Mode_Tick_Timer_AmberINDBlk();
              }

              App_Model_DW.sfEvent_f = c_previousEvent;

              /*  Non GFS  */
              *rty_MainOut_Sig_gy = Off;
              App_Model_DW.is_WPCMode_Run_f = App__IN_WPCRun_ChargingComplete;
              *rty_MainOut_Sig = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_MainOut_Sig_m = On;
              *rty_MainOut_Sig_l = On;
              *rty_MainOut_Sig_g = Off;
            }
            break;

           default:
            App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
            break;
          }
        }
      }
      break;

     case App_Model_IN_WPCRun_Standby:
      *rty_MainOut_Sig_m = Off;

      /* 1. */
      switch (rtu_Main_InSig_a) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_FODError;
        *rty_MainOut_Sig = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        *rty_MainOut_Sig_h = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_j = 0U;
        *rty_MainOut_Sig_m = Off;
        *rty_MainOut_Sig_l = Off;
        App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);

        /*  Non GFS  */
        *rty_MainOut_Sig_gy = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Charging;
        *rty_MainOut_Sig = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        *rty_MainOut_Sig_m = On;
        App_M_Function_ChargingINDColor(rtu_Main_InSig_lz, rty_MainOut_Sig_l, rty_MainOut_Sig_g);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run_f = App__IN_WPCRun_ChargingComplete;
        *rty_MainOut_Sig = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        *rty_MainOut_Sig_m = On;
        *rty_MainOut_Sig_l = On;
        *rty_MainOut_Sig_g = Off;
        break;
      }
      break;
    }
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App__exit_internal_WPCMode_Stop(Bool *rty_MainOut_Sig_gy, BlinkState *rty_MainOut_Sig_h)
{
  switch (App_Model_DW.is_WPCMode_Stop_j) {
   case App_Model_IN_CardDetectError:
    {
      sint32 b_previousEvent;
      *rty_MainOut_Sig_h = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_j = 0U;
      b_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = A_event_Cancel_Timer_CardINDBlk;
      if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
        App_Model_Tick_Timer_CardINDBlk();
      }

      App_Model_DW.sfEvent_f = b_previousEvent;
      *rty_MainOut_Sig_gy = Off;
      App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_NO_ACTIVE_CHILD_o;
    }
    break;

   case App_Model_IN_WPCStop_TempErr:
    {
      sint32 b_previousEvent;
      *rty_MainOut_Sig_h = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_j = 0U;
      b_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
      if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
        App_Mode_Tick_Timer_AmberINDBlk();
      }

      App_Model_DW.sfEvent_f = b_previousEvent;

      /*  Non GFS  */
      *rty_MainOut_Sig_gy = Off;
      App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_NO_ACTIVE_CHILD_o;
    }
    break;

   default:
    App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_NO_ACTIVE_CHILD_o;
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void Ap_enter_atomic_WPCMode_Disable(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, BlinkState *rty_MainOut_Sig_h, Bool
  *rty_MainOut_Sig_k)
{
  sint32 b_previousEvent;
  *rty_MainOut_Sig = WPCWarningOff;
  *rty_MainOut_Sig_h = BlinkOff;
  App_Model_DW.Counter_BlinkCnt_j = 0U;
  *rty_MainOut_Sig_m = Off;
  *rty_MainOut_Sig_l = Off;
  *rty_MainOut_Sig_g = Off;
  *rty_MainOut_Sig_k = Off;
  b_previousEvent = App_Model_DW.sfEvent_f;
  App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
  if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
    App_Mode_Tick_Timer_AmberINDBlk();
  }

  App_Model_DW.sfEvent_f = b_previousEvent;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Model_Tick_Timer_PhoneLeft(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft_j) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == App_event_Start_Timer_PhoneLeft) {
      App_Model_DW.is_Tick_Timer_PhoneLeft_j = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == Ap_event_Cancel_Timer_PhoneLeft) {
        App_Model_DW.is_Tick_Timer_PhoneLeft_j = App_Model_IN_Off_o;
        App_Model_DW.Timer_PhoneLeft_k = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_PhoneLeft_k + 1;
        if (App_Model_DW.Timer_PhoneLeft_k + 1 > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft_k = (uint8)tmp;
        if (App_Model_DW.sfEvent_f == App_event_Start_Timer_PhoneLeft) {
          App_Model_DW.Timer_PhoneLeft_k = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void Ap_Tick_Timer_PhoneWarningCheck(uint16 *rty_MainOut_Sig_j)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarningChe_b) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == event_Start_Timer_PhoneWarningC) {
      App_Model_DW.is_Tick_Timer_PhoneWarningChe_b = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == event_Cancel_Timer_PhoneWarning) {
        App_Model_DW.is_Tick_Timer_PhoneWarningChe_b = App_Model_IN_Off_o;
        App_Model_DW.Timer_PhoneWarningCheck_j = 0U;
        *rty_MainOut_Sig_j = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_PhoneWarningCheck_j + 1;
        if (App_Model_DW.Timer_PhoneWarningCheck_j + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck_j = (uint16)tmp;
        *rty_MainOut_Sig_j = App_Model_DW.Timer_PhoneWarningCheck_j;
        if (App_Model_DW.sfEvent_f == event_Start_Timer_PhoneWarningC) {
          App_Model_DW.Timer_PhoneWarningCheck_j = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void A_Tick_Timer_PhoneReminderCheck(uint16 *rty_MainOut_Sig_b)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneReminderCh_i) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == event_Start_Timer_PhoneReminder) {
      App_Model_DW.is_Tick_Timer_PhoneReminderCh_i = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == event_Cancel_Timer_PhoneReminde) {
        App_Model_DW.is_Tick_Timer_PhoneReminderCh_i = App_Model_IN_Off_o;
        App_Model_DW.Timer_PhoneReminderCheck_i = 0U;
        *rty_MainOut_Sig_b = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_PhoneReminderCheck_i + 1;
        if (App_Model_DW.Timer_PhoneReminderCheck_i + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneReminderCheck_i = (uint16)tmp;
        *rty_MainOut_Sig_b = App_Model_DW.Timer_PhoneReminderCheck_i;
        if (App_Model_DW.sfEvent_f == event_Start_Timer_PhoneReminder) {
          App_Model_DW.Timer_PhoneReminderCheck_i = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App__Tick_Timer_WarningComplete(uint16 *rty_MainOut_Sig_jy)
{
  switch (App_Model_DW.is_Tick_Timer_WarningComplete_b) {
   case App_Model_IN_Off_o:
    if (App_Model_DW.sfEvent_f == event_Start_Timer_WarningComple) {
      App_Model_DW.is_Tick_Timer_WarningComplete_b = App_Model_IN_On_d;
    }
    break;

   case App_Model_IN_On_d:
    {
      if (App_Model_DW.sfEvent_f == event_Cancel_Timer_WarningCompl) {
        App_Model_DW.is_Tick_Timer_WarningComplete_b = App_Model_IN_Off_o;
        App_Model_DW.Timer_WarningComplete_f = 0U;
        *rty_MainOut_Sig_jy = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_WarningComplete_f + 1;
        if (App_Model_DW.Timer_WarningComplete_f + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete_f = (uint16)tmp;
        *rty_MainOut_Sig_jy = App_Model_DW.Timer_WarningComplete_f;
        if (App_Model_DW.sfEvent_f == event_Start_Timer_WarningComple) {
          App_Model_DW.Timer_WarningComplete_f = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Model_Function_WPCWarning(C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_b, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, C_WPCWarning *rty_MainOut_Sig, uint16
  *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_k)
{
  /* 1 */
  if ((rtu_Main_InSig_g == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck_j >= Par_PhoneCheckTime) && (rtu_Main_InSig_jy == Off)) || (App_Model_DW.Timer_PhoneLeft_k >= 50)) {
    sint32 c_previousEvent;
    *rty_MainOut_Sig = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    App_Model_DW.b_WarnClearEnable_o = Off;
    *rty_MainOut_Sig_k = Off;
    c_previousEvent = App_Model_DW.sfEvent_f;
    App_Model_DW.sfEvent_f = Ap_event_Cancel_Timer_PhoneLeft;
    if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
      App_Model_Tick_Timer_PhoneLeft();
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneWarning;
    if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
      Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneReminde;
    if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
      A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_WarningCompl;
    if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
      App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
    }

    App_Model_DW.sfEvent_f = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /* 1. */
    if ((App_Model_DW.b_WarnClearEnable_o == On) && ((App_Model_DW.b_WPCPhoneExist_prev_i != App_Model_DW.b_WPCPhoneExist_start_o) && (App_Model_DW.b_WPCPhoneExist_start_o == Off))) {
      c_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = App_event_Start_Timer_PhoneLeft;
      if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
        App_Model_Tick_Timer_PhoneLeft();
      }

      App_Model_DW.sfEvent_f = c_previousEvent;

      /* 1. */
    } else if ((App_Model_DW.is_Tick_Timer_PhoneLeft_j == App_Model_IN_On_d) && (rtu_Main_InSig_jy == On)) {
      c_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = Ap_event_Cancel_Timer_PhoneLeft;
      if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
        App_Model_Tick_Timer_PhoneLeft();
      }

      App_Model_DW.sfEvent_f = c_previousEvent;
    }

    /* 1. */
    if ((App_Model_DW.Timer_PhoneWarningCheck_j >= 10) && (App_Model_DW.Timer_PhoneWarningCheck_j <= Par_PhoneCheckTime) && (rtu_Main_InSig_jy == On)) {
      *rty_MainOut_Sig = Cellphoneonthepad;

      /* b_WPCWarn = Cellphoneonthepad 8차 LFRollBack */
      App_Model_DW.b_WarnClearEnable_o = On;
      c_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneWarning;
      if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
        Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
      }

      App_Model_DW.sfEvent_f = event_Start_Timer_PhoneReminder;
      if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
        A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
      }

      App_Model_DW.sfEvent_f = c_previousEvent;

      /* 5차 적용 */

      /* 1. */
    } else if ((App_Model_DW.Timer_PhoneReminderCheck_i >= 6000) && (App_Model_DW.b_WarnClearEnable_o == On) && (rtu_Main_InSig_jy == On)) {
      /* 1. */
      if ((rtu_Main_InSig_j == On) || (rtu_Main_InSig_b == On)) {
        App_Model_DW.b_WarnClearEnable_o = Off;
        *rty_MainOut_Sig = WPCWarningOff;
        *rty_MainOut_Sig_k = Off;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        c_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneReminde;
        if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
          A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
        }

        App_Model_DW.sfEvent_f = c_previousEvent;
      } else {
        /* 2. */
        *rty_MainOut_Sig = Cellphonereminder;

        /* b_WPCWarn = Cellphonereminder 8차 LFRollBack */
        c_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneReminde;
        if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
          A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
        }

        App_Model_DW.sfEvent_f = event_Start_Timer_WarningComple;
        if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
          App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
        }

        App_Model_DW.sfEvent_f = c_previousEvent;
      }

      /* 1. */
    } else if ((App_Model_DW.Timer_WarningComplete_f >= 50) && (App_Model_DW.b_WarnClearEnable_o == On) && (rtu_Main_InSig_jy == On)) {
      *rty_MainOut_Sig = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_DW.b_WarnClearEnable_o = Off;
      *rty_MainOut_Sig_k = Off;
      c_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = event_Cancel_Timer_WarningCompl;
      if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
        App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
      }

      App_Model_DW.sfEvent_f = c_previousEvent;
    }
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Mo_enter_atomic_WPCMode_NFC(uint16 *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy)
{
  sint32 b_previousEvent;
  App_Model_DW.b_WarnClearEnable_o = Off;
  b_previousEvent = App_Model_DW.sfEvent_f;
  App_Model_DW.sfEvent_f = Ap_event_Cancel_Timer_PhoneLeft;
  if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
    App_Model_Tick_Timer_PhoneLeft();
  }

  App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneWarning;
  if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
    Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
  }

  App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneReminde;
  if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
    A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
  }

  App_Model_DW.sfEvent_f = event_Cancel_Timer_WarningCompl;
  if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
    App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
  }

  App_Model_DW.sfEvent_f = b_previousEvent;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_WPCMode_Disable(C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_b, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, WPCStatus rtu_Main_InSig_h, C_WPCWarning
  *rty_MainOut_Sig, uint16 *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_k)
{
  /* 1. */
  if ((rtu_Main_InSig_h == NFCMode) || (rtu_Main_InSig_h == LPCDMode) || (rtu_Main_InSig_h == PICCMode)) {
    App_Model_DW.is_WPCMode_Disable_m = App_Model_IN_WPCMode_NFC;
    App_Mo_enter_atomic_WPCMode_NFC(rty_MainOut_Sig_b, rty_MainOut_Sig_j, rty_MainOut_Sig_jy);
  } else {
    App_Model_DW.is_WPCMode_Disable_m = App_Model_IN_WPCMode_Off;
    if ((App_Model_DW.L_IGN1_IN_prev_b != App_Model_DW.L_IGN1_IN_start_e) && (App_Model_DW.L_IGN1_IN_start_e == Off)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCMode_Off_k = App_Mod_IN_LeavingPhone_Warning;
      App_Model_DW.b_WarnClearEnable_o = Off;
      b_previousEvent = App_Model_DW.sfEvent_f;
      App_Model_DW.sfEvent_f = event_Start_Timer_PhoneWarningC;
      if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
        Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
      }

      App_Model_DW.sfEvent_f = b_previousEvent;
      App_Model_Function_WPCWarning(rtu_Main_InSig_g, rtu_Main_InSig_b, rtu_Main_InSig_j, rtu_Main_InSig_jy, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_j, rty_MainOut_Sig_jy,
        rty_MainOut_Sig_k);
      *rty_MainOut_Sig_k = On;
    } else {
      App_Model_DW.is_WPCMode_Off_k = App_M_IN_LeavingPhone_NoWarning;
    }
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void App_Model_MainControl(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m, Bool rtu_Main_InSig_l, C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_gy, Bool rtu_Main_InSig_b, Bool
  rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, DeviceState rtu_Main_InSig_a, WPCStatus rtu_Main_InSig_h, WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, Bool rtu_Main_InSig_f, C_WPCWarning
  *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, uint16 *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16
  *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h, Bool *rty_MainOut_Sig_k)
{
  switch (App_Model_DW.is_MainControl_i) {
   case App_Model_IN_WPCMode_Disable:
    {
      /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
      *rty_MainOut_Sig_m = Off;

      /* 1. */
      if (rtu_Main_InSig_h == WPCMode) {
        sint32 b_previousEvent;
        if (App_Model_DW.is_WPCMode_Disable_m == App_Model_IN_WPCMode_Off) {
          if (App_Model_DW.is_WPCMode_Off_k == App_Mod_IN_LeavingPhone_Warning) {
            /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
            *rty_MainOut_Sig = WPCWarningOff;
            *rty_MainOut_Sig_k = Off;
            App_Model_DW.is_WPCMode_Off_k = App_Model_IN_NO_ACTIVE_CHILD_o;
          } else {
            App_Model_DW.is_WPCMode_Off_k = App_Model_IN_NO_ACTIVE_CHILD_o;
          }

          App_Model_DW.is_WPCMode_Disable_m = App_Model_IN_NO_ACTIVE_CHILD_o;
        } else {
          App_Model_DW.is_WPCMode_Disable_m = App_Model_IN_NO_ACTIVE_CHILD_o;
        }

        App_Model_DW.b_WarnClearEnable_o = Off;
        b_previousEvent = App_Model_DW.sfEvent_f;
        App_Model_DW.sfEvent_f = Ap_event_Cancel_Timer_PhoneLeft;
        if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
          App_Model_Tick_Timer_PhoneLeft();
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneWarning;
        if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
          /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
          Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneReminde;
        if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
          /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
          A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
        }

        App_Model_DW.sfEvent_f = event_Cancel_Timer_WarningCompl;
        if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
          /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
          App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
        }

        App_Model_DW.sfEvent_f = b_previousEvent;
        App_Model_DW.is_MainControl_i = App_Model_IN_WPCMode_Enable;
        App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Stop;

        /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
        *rty_MainOut_Sig_m = Off;
        *rty_MainOut_Sig_l = Off;

        /* b_ChargingEnable = Off */
        App_enter_internal_WPCMode_Stop(rtu_Main_InSig_gy, rtu_Main_InSig_lz, rtu_Main_InSig_h0, rtu_Main_InSig_f, rty_MainOut_Sig, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_gy,
          rty_MainOut_Sig_a, rty_MainOut_Sig_h);
      } else {
        switch (App_Model_DW.is_WPCMode_Disable_m) {
         case App_Model_IN_WPCMode_NFC:
          /* 1. */
          if (rtu_Main_InSig_h == ModeOff) {
            App_Model_DW.is_WPCMode_Disable_m = App_Model_IN_WPCMode_Off;
            App_Model_DW.is_WPCMode_Off_k = App_M_IN_LeavingPhone_NoWarning;
          }
          break;

         case App_Model_IN_WPCMode_Off:
          /* 1. */
          if ((rtu_Main_InSig_h == NFCMode) || (rtu_Main_InSig_h == LPCDMode) || (rtu_Main_InSig_h == PICCMode)) {
            if (App_Model_DW.is_WPCMode_Off_k == App_Mod_IN_LeavingPhone_Warning) {
              /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
              *rty_MainOut_Sig = WPCWarningOff;
              *rty_MainOut_Sig_k = Off;
              App_Model_DW.is_WPCMode_Off_k = App_Model_IN_NO_ACTIVE_CHILD_o;
            } else {
              App_Model_DW.is_WPCMode_Off_k = App_Model_IN_NO_ACTIVE_CHILD_o;
            }

            App_Model_DW.is_WPCMode_Disable_m = App_Model_IN_WPCMode_NFC;

            /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
            App_Mo_enter_atomic_WPCMode_NFC(rty_MainOut_Sig_b, rty_MainOut_Sig_j, rty_MainOut_Sig_jy);
          } else if (App_Model_DW.is_WPCMode_Off_k == App_Mod_IN_LeavingPhone_Warning) {
            /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
            App_Model_Function_WPCWarning(rtu_Main_InSig_g, rtu_Main_InSig_b, rtu_Main_InSig_j, rtu_Main_InSig_jy, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_j, rty_MainOut_Sig_jy,
              rty_MainOut_Sig_k);
          }
          break;
        }
      }
    }
    break;

   case App_Model_IN_WPCMode_Enable:
    {
      /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
      /* 1. */
      if (rtu_Main_InSig_h != WPCMode) {
        switch (App_Model_DW.is_WPCMode_Enable_d) {
         case App_Model_IN_WPCMode_Run:
          App_M_exit_internal_WPCMode_Run(rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
          App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_NO_ACTIVE_CHILD_o;
          break;

         case App_Model_IN_WPCMode_Stop:
          App__exit_internal_WPCMode_Stop(rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
          App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_NO_ACTIVE_CHILD_o;
          break;
        }

        *rty_MainOut_Sig_a = Off;
        App_Model_DW.is_MainControl_i = App_Model_IN_WPCMode_Disable;
        Ap_enter_atomic_WPCMode_Disable(rty_MainOut_Sig, rty_MainOut_Sig_m, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_h, rty_MainOut_Sig_k);
        enter_internal_WPCMode_Disable(rtu_Main_InSig_g, rtu_Main_InSig_b, rtu_Main_InSig_j, rtu_Main_InSig_jy, rtu_Main_InSig_h, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_j,
          rty_MainOut_Sig_jy, rty_MainOut_Sig_k);
      } else {
        switch (App_Model_DW.is_WPCMode_Enable_d) {
         case App_Model_IN_WPCMode_Run:
          App_Model_WPCMode_Run(rtu_Main_InSig, rtu_Main_InSig_m, rtu_Main_InSig_l, rtu_Main_InSig_gy, rtu_Main_InSig_a, rtu_Main_InSig_lz, rtu_Main_InSig_h0, rtu_Main_InSig_f, rty_MainOut_Sig,
                                rty_MainOut_Sig_m, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_a, rty_MainOut_Sig_h);
          break;

         case App_Model_IN_WPCMode_Stop:
          {
            *rty_MainOut_Sig_m = Off;
            if ((rtu_Main_InSig_a == Full_Charge) && (rtu_Main_InSig == Off) && (rtu_Main_InSig_m == Off) && (rtu_Main_InSig_gy == Off) && (rtu_Main_InSig_l == Off) && (rtu_Main_InSig_f == Off)) {
              /* CardDetect_Nidec] */
              App__exit_internal_WPCMode_Stop(rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
              App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Run;
              *rty_MainOut_Sig_a = On;

              /* b_ROHMOperCmd = On /_ Non GFS _/ */
              App_Model_DW.is_WPCMode_Run_f = App__IN_WPCRun_ChargingComplete;
              *rty_MainOut_Sig = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_MainOut_Sig_m = On;
              *rty_MainOut_Sig_l = On;
              *rty_MainOut_Sig_g = Off;
            } else if ((rtu_Main_InSig_a == Charging) && (rtu_Main_InSig == Off) && (rtu_Main_InSig_m == Off) && (rtu_Main_InSig_gy == Off) && (rtu_Main_InSig_l == Off) && (rtu_Main_InSig_f == Off)) {
              /* CardDetect_Nidec] */
              App__exit_internal_WPCMode_Stop(rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
              App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Run;
              *rty_MainOut_Sig_a = On;

              /* b_ROHMOperCmd = On /_ Non GFS _/ */
              App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Charging;
              *rty_MainOut_Sig = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_MainOut_Sig_m = On;
              App_M_Function_ChargingINDColor(rtu_Main_InSig_lz, rty_MainOut_Sig_l, rty_MainOut_Sig_g);
            } else {
              switch (App_Model_DW.is_WPCMode_Stop_j) {
               case App_Model_IN_CardDetectError:
                {
                  if (rtu_Main_InSig_f == Off) {
                    sint32 b_previousEvent;

                    /* CardDetect_Nidec] */
                    *rty_MainOut_Sig_h = BlinkOff;
                    App_Model_DW.Counter_BlinkCnt_j = 0U;
                    b_previousEvent = App_Model_DW.sfEvent_f;
                    App_Model_DW.sfEvent_f = A_event_Cancel_Timer_CardINDBlk;
                    if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
                      App_Model_Tick_Timer_CardINDBlk();
                    }

                    App_Model_DW.sfEvent_f = b_previousEvent;
                    *rty_MainOut_Sig_gy = Off;
                    App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_NO_ACTIVE_CHILD_o;
                    App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Run;
                    *rty_MainOut_Sig_a = On;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Standby;
                    *rty_MainOut_Sig = WPCWarningOff;

                    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                    *rty_MainOut_Sig_m = Off;
                    *rty_MainOut_Sig_l = Off;
                    *rty_MainOut_Sig_g = Off;
                  } else {
                    App__Function_CardLEDErrorBlink(rtu_Main_InSig_h0, rty_MainOut_Sig_l, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
                  }
                }
                break;

               case App_Model_IN_WPCStop_NotTempErr:
                /* 1. */
                if (rtu_Main_InSig_gy == On) {
                  App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_WPCStop_TempErr;

                  /* 240926 */
                  *rty_MainOut_Sig_a = Off;
                  *rty_MainOut_Sig = Charging_error;
                  *rty_MainOut_Sig_h = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt_j = 0U;
                  App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
                  *rty_MainOut_Sig_gy = On;

                  /* 2. */
                } else if ((rtu_Main_InSig == Off) && (rtu_Main_InSig_m == Off) && (rtu_Main_InSig_l == Off)) {
                  App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_NO_ACTIVE_CHILD_o;
                  App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Run;
                  *rty_MainOut_Sig_a = On;

                  /* b_ROHMOperCmd = On /_ Non GFS _/ */
                  App_Model_DW.is_WPCMode_Run_f = App_Model_IN_WPCRun_Standby;
                  *rty_MainOut_Sig = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  *rty_MainOut_Sig_m = Off;
                  *rty_MainOut_Sig_l = Off;
                  *rty_MainOut_Sig_g = Off;
                } else if (rtu_Main_InSig_f == On) {
                  /* CardDetect_Nidec] */
                  App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_CardDetectError;
                  *rty_MainOut_Sig = NFCCardDetected;
                  *rty_MainOut_Sig_h = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt_j = 0U;
                  *rty_MainOut_Sig_g = Off;
                  App__Function_CardLEDErrorBlink(rtu_Main_InSig_h0, rty_MainOut_Sig_l, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
                  *rty_MainOut_Sig_gy = On;
                }
                break;

               case App_Model_IN_WPCStop_TempErr:
                {
                  /* 1. */
                  if (rtu_Main_InSig_gy == Off) {
                    sint32 b_previousEvent;
                    *rty_MainOut_Sig_h = BlinkOff;
                    App_Model_DW.Counter_BlinkCnt_j = 0U;
                    b_previousEvent = App_Model_DW.sfEvent_f;
                    App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
                    if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
                      App_Mode_Tick_Timer_AmberINDBlk();
                    }

                    App_Model_DW.sfEvent_f = b_previousEvent;

                    /*  Non GFS  */
                    *rty_MainOut_Sig_gy = Off;
                    App_Model_DW.is_WPCMode_Stop_j = App_Model_IN_WPCStop_NotTempErr;

                    /* 240926 */
                    *rty_MainOut_Sig_a = Off;
                    *rty_MainOut_Sig = WPCWarningOff;
                    *rty_MainOut_Sig_g = Off;
                  } else {
                    App_Mode_Function_LEDErrorBlink(rtu_Main_InSig_lz, rtu_Main_InSig_h0, rty_MainOut_Sig_g, rty_MainOut_Sig_gy, rty_MainOut_Sig_h);
                  }
                }
                break;
              }
            }
          }
          break;
        }
      }
    }
    break;

   case App_Model_IN_WPCMode_Init:
    /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
    *rty_MainOut_Sig_m = Off;

    /* 1. */
    if (rtu_Main_InSig_h != WPCMode) {
      App_Model_DW.is_MainControl_i = App_Model_IN_WPCMode_Disable;

      /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
      Ap_enter_atomic_WPCMode_Disable(rty_MainOut_Sig, rty_MainOut_Sig_m, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_h, rty_MainOut_Sig_k);
      enter_internal_WPCMode_Disable(rtu_Main_InSig_g, rtu_Main_InSig_b, rtu_Main_InSig_j, rtu_Main_InSig_jy, rtu_Main_InSig_h, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_j,
        rty_MainOut_Sig_jy, rty_MainOut_Sig_k);

      /* 2 */
    } else if (rtu_Main_InSig_h == WPCMode) {
      App_Model_DW.is_MainControl_i = App_Model_IN_WPCMode_Enable;
      App_Model_DW.is_WPCMode_Enable_d = App_Model_IN_WPCMode_Stop;

      /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
      *rty_MainOut_Sig_m = Off;
      *rty_MainOut_Sig_l = Off;

      /* b_ChargingEnable = Off */
      App_enter_internal_WPCMode_Stop(rtu_Main_InSig_gy, rtu_Main_InSig_lz, rtu_Main_InSig_h0, rtu_Main_InSig_f, rty_MainOut_Sig, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_gy,
        rty_MainOut_Sig_a, rty_MainOut_Sig_h);
    }
    break;
  }
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Phone(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft_j = App_Model_IN_Off_o;
  App_Model_DW.Timer_PhoneLeft_k = 0U;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Pho_b(uint16 *rty_MainOut_Sig_j)
{
  App_Model_DW.is_Tick_Timer_PhoneWarningChe_b = App_Model_IN_Off_o;
  App_Model_DW.Timer_PhoneWarningCheck_j = 0U;

  /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
  *rty_MainOut_Sig_j = 0U;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Pho_g(uint16 *rty_MainOut_Sig_b)
{
  App_Model_DW.is_Tick_Timer_PhoneReminderCh_i = App_Model_IN_Off_o;
  App_Model_DW.Timer_PhoneReminderCheck_i = 0U;

  /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
  *rty_MainOut_Sig_b = 0U;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Warni(uint16 *rty_MainOut_Sig_jy)
{
  App_Model_DW.is_Tick_Timer_WarningComplete_b = App_Model_IN_Off_o;
  App_Model_DW.Timer_WarningComplete_f = 0U;

  /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
  *rty_MainOut_Sig_jy = 0U;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Amber(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk_b = App_Model_IN_Off_o;
  App_Model_DW.Timer_AmberINDBlk_i = 0U;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Amb_d(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_o = App_Model_IN_Off_o;
  App_Model_DW.Timer_AmberINDBlk2_p = 0U;
}

/* Function for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_CardI(void)
{
  App_Model_DW.is_Tick_Timer_CardINDBlk_d = App_Model_IN_Off_o;
  App_Model_DW.Timer_CardINDBlk_n = 0U;
}

/* System initialize for atomic system: '<S13>/WPC_MainControl_Function' */
void A_WPC_MainControl_Function_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, uint16 *rty_MainOut_Sig_b,
  uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h, Bool *rty_MainOut_Sig_k)
{
  /* SystemInitialize for Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
  App_Model_DW.sfEvent_f = App_Model_CALL_EVENT_j;
  *rty_MainOut_Sig = WPCWarningOff;
  *rty_MainOut_Sig_m = Off;
  *rty_MainOut_Sig_l = Off;
  *rty_MainOut_Sig_g = Off;
  *rty_MainOut_Sig_gy = Off;
  *rty_MainOut_Sig_b = 0U;
  *rty_MainOut_Sig_j = 0U;
  *rty_MainOut_Sig_jy = 0U;
  *rty_MainOut_Sig_a = Off;
  *rty_MainOut_Sig_h = BlinkOff;
  *rty_MainOut_Sig_k = Off;
}

/* Output and update for atomic system: '<S13>/WPC_MainControl_Function' */
void App_Mo_WPC_MainControl_Function(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m, Bool rtu_Main_InSig_l, C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_gy, Bool rtu_Main_InSig_b, Bool
  rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, DeviceState rtu_Main_InSig_a, WPCStatus rtu_Main_InSig_h, Bool rtu_Main_InSig_k, WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, WPCIndCmdState
  rtu_Main_InSig_k1, Bool rtu_Main_InSig_f, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, uint16
  *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h, Bool *rty_MainOut_Sig_k)
{
  /* Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
  App_Model_DW.sfEvent_f = App_Model_CALL_EVENT_j;
  App_Model_DW.b_WPCPhoneExist_prev_i = App_Model_DW.b_WPCPhoneExist_start_o;
  App_Model_DW.b_WPCPhoneExist_start_o = rtu_Main_InSig_jy;
  App_Model_DW.WPCIndCmdState_prev = App_Model_DW.WPCIndCmdState_start;
  App_Model_DW.WPCIndCmdState_start = rtu_Main_InSig_k1;
  App_Model_DW.L_IGN1_IN_prev_b = App_Model_DW.L_IGN1_IN_start_e;
  App_Model_DW.L_IGN1_IN_start_e = rtu_Main_InSig_k;
  if (App_Model_DW.is_active_c53_MainControl_Lib == 0U) {
    App_Model_DW.b_WPCPhoneExist_prev_i = rtu_Main_InSig_jy;
    App_Model_DW.WPCIndCmdState_prev = rtu_Main_InSig_k1;
    App_Model_DW.L_IGN1_IN_prev_b = rtu_Main_InSig_k;
    App_Model_DW.is_active_c53_MainControl_Lib = 1U;
    App_Model_DW.is_active_MainControl_d = 1U;
    App_Model_DW.is_MainControl_i = App_Model_IN_WPCMode_Init;
    *rty_MainOut_Sig = WPCWarningOff;
    *rty_MainOut_Sig_h = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_j = 0U;
    App_Model_DW.b_WarnClearEnable_o = Off;
    *rty_MainOut_Sig_m = Off;
    *rty_MainOut_Sig_l = Off;
    *rty_MainOut_Sig_g = Off;
    *rty_MainOut_Sig_a = Off;
    *rty_MainOut_Sig_k = Off;
    App_Model_DW.sfEvent_f = Ap_event_Cancel_Timer_PhoneLeft;
    if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
      App_Model_Tick_Timer_PhoneLeft();
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneWarning;
    if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
      Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_PhoneReminde;
    if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
      A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_WarningCompl;
    if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
      App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
    }

    App_Model_DW.sfEvent_f = event_Cancel_Timer_AmberINDBlk;
    if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
      App_Mode_Tick_Timer_AmberINDBlk();
    }

    App_Model_DW.sfEvent_f = -1;
    App_Model_DW.is_active_Tick_Timer_PhoneLef_i = 1U;
    enter_internal_Tick_Timer_Phone();
    App_Model_DW.is_active_Tick_Timer_PhoneWar_p = 1U;
    enter_internal_Tick_Timer_Pho_b(rty_MainOut_Sig_j);
    App_Model_DW.is_active_Tick_Timer_PhoneRem_h = 1U;
    enter_internal_Tick_Timer_Pho_g(rty_MainOut_Sig_b);
    App_Model_DW.is_active_Tick_Timer_WarningC_c = 1U;
    enter_internal_Tick_Timer_Warni(rty_MainOut_Sig_jy);
    App_Model_DW.is_active_Tick_Timer_AmberIN_gz = 1U;
    enter_internal_Tick_Timer_Amber();
    App_Model_DW.is_active_Tick_Timer_AmberIND_e = 1U;
    enter_internal_Tick_Timer_Amb_d();
    App_Model_DW.is_active_Tick_Timer_CardINDB_d = 1U;
    enter_internal_Tick_Timer_CardI();
  } else {
    if (App_Model_DW.is_active_MainControl_d != 0U) {
      App_Model_MainControl(rtu_Main_InSig, rtu_Main_InSig_m, rtu_Main_InSig_l, rtu_Main_InSig_g, rtu_Main_InSig_gy, rtu_Main_InSig_b, rtu_Main_InSig_j, rtu_Main_InSig_jy, rtu_Main_InSig_a,
                            rtu_Main_InSig_h, rtu_Main_InSig_lz, rtu_Main_InSig_h0, rtu_Main_InSig_f, rty_MainOut_Sig, rty_MainOut_Sig_m, rty_MainOut_Sig_l, rty_MainOut_Sig_g, rty_MainOut_Sig_gy,
                            rty_MainOut_Sig_b, rty_MainOut_Sig_j, rty_MainOut_Sig_jy, rty_MainOut_Sig_a, rty_MainOut_Sig_h, rty_MainOut_Sig_k);
    }

    if (App_Model_DW.is_active_Tick_Timer_PhoneLef_i != 0U) {
      App_Model_Tick_Timer_PhoneLeft();
    }

    if (App_Model_DW.is_active_Tick_Timer_PhoneWar_p != 0U) {
      Ap_Tick_Timer_PhoneWarningCheck(rty_MainOut_Sig_j);
    }

    if (App_Model_DW.is_active_Tick_Timer_PhoneRem_h != 0U) {
      A_Tick_Timer_PhoneReminderCheck(rty_MainOut_Sig_b);
    }

    if (App_Model_DW.is_active_Tick_Timer_WarningC_c != 0U) {
      App__Tick_Timer_WarningComplete(rty_MainOut_Sig_jy);
    }

    if (App_Model_DW.is_active_Tick_Timer_AmberIN_gz != 0U) {
      App_Mode_Tick_Timer_AmberINDBlk();
    }

    if (App_Model_DW.is_active_Tick_Timer_AmberIND_e != 0U) {
      App_Mod_Tick_Timer_AmberINDBlk2();
    }

    if (App_Model_DW.is_active_Tick_Timer_CardINDB_d != 0U) {
      App_Model_Tick_Timer_CardINDBlk();
    }
  }

  /* End of Chart: '<S200>/WPC_MainControl4_CardSync_241007' */
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Function_ChargingINDColor_k(WPCIndUSMState rtu_Main_InSig_nw, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e)
{
  /* 1. */
  if (rtu_Main_InSig_nw == WPCIndUSMState__Type2) {
    *rty_MainOut_Sig_b = On;
    *rty_MainOut_Sig_e = Off;
  } else {
    *rty_MainOut_Sig_b = Off;
    *rty_MainOut_Sig_e = On;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_M_Tick_Timer_AmberINDBlk2_l(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == event_Start_Timer_AmberINDBlk_b) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_AmberINDBl_d) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_h;
        App_Model_DW.Timer_AmberINDBlk2 = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_AmberINDBlk2 + 1;
        if (App_Model_DW.Timer_AmberINDBlk2 + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2 = (uint16)tmp;
        if (App_Model_DW.sfEvent_m == event_Start_Timer_AmberINDBlk_b) {
          App_Model_DW.Timer_AmberINDBlk2 = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Mo_Tick_Timer_AmberINDBlk_h(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == event_Start_Timer_AmberINDBlk_g) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_AmberINDBl_j) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_h;
        App_Model_DW.Timer_AmberINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_AmberINDBlk + 1;
        if (App_Model_DW.Timer_AmberINDBlk + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk = (uint16)tmp;
        if (App_Model_DW.sfEvent_m == event_Start_Timer_AmberINDBlk_g) {
          App_Model_DW.Timer_AmberINDBlk = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Mo_Function_LEDErrorBlink_l(WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po)
{
  switch (rtu_Main_InSig_h) {
   case Off:
    {
      /* ForFODError%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if ((*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt >= 10)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_d;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
        *rty_MainOut_Sig_gc = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt >= 10) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_d;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
        *rty_MainOut_Sig_gc = Off;

        /*  Non GFS  */
      } else if ((rtu_Main_InSig_nw == WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk2 == App_Model_IN_Off_h)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOn;
        *rty_MainOut_Sig_e = On;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
      } else if ((rtu_Main_InSig_nw != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk == App_Model_IN_Off_h)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_MainOut_Sig_e = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) &&
                  (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_po = BlinkOn;
        App_Model_DW.Counter_BlinkCnt++;
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) &&
                   (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) &&
                   (App_Model_DW.WPC2IndCmdState_start == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_po = BlinkOff;
        *rty_MainOut_Sig_e = On;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOn;
        *rty_MainOut_Sig_e = On;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOff;
        App_Model_DW.Counter_BlinkCnt++;

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
      }
    }
    break;

   case On:
    {
      /* ForFODError%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if ((*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt >= 10)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_d;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
        *rty_MainOut_Sig_gc = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt >= 10) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_d;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
        *rty_MainOut_Sig_gc = Off;

        /*  Non GFS  */
      } else if ((rtu_Main_InSig_nw == WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk2 == App_Model_IN_Off_h)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOn;
        *rty_MainOut_Sig_e = On;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
      } else if ((rtu_Main_InSig_nw != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.is_Tick_Timer_AmberINDBlk == App_Model_IN_Off_h)) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_MainOut_Sig_e = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) &&
                  (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_po = BlinkOn;
        App_Model_DW.Counter_BlinkCnt++;
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw != WPCIndUSMState__Type2) && (*rty_MainOut_Sig_po == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) &&
                   (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) &&
                   (App_Model_DW.WPC2IndCmdState_start == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_MainOut_Sig_po = BlinkOff;
        *rty_MainOut_Sig_e = On;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mo_Tick_Timer_AmberINDBlk_h();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOn;
        *rty_MainOut_Sig_e = On;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;

        /* 1. */
      } else if ((rtu_Main_InSig_nw == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_MainOut_Sig_po = BlinkOff;
        App_Model_DW.Counter_BlinkCnt++;

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_MainOut_Sig_e = Off;
        t_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_AmberINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
          App_M_Tick_Timer_AmberINDBlk2_l();
        }

        App_Model_DW.sfEvent_m = t_previousEvent;
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_exit_internal_WPCMode_Run_p(Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po)
{
  if (App_Model_DW.is_WPCMode_Run == App_Model_IN_WPCRun_FODError_g) {
    sint32 b_previousEvent;
    *rty_MainOut_Sig_po = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    b_previousEvent = App_Model_DW.sfEvent_m;
    App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
    if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Mo_Tick_Timer_AmberINDBlk_h();
    }

    App_Model_DW.sfEvent_m = b_previousEvent;

    /*  Non GFS  */
    *rty_MainOut_Sig_gc = Off;
    App_Model_DW.is_WPCMode_Run = App_Model_IN_NO_ACTIVE_CHILD_ef;
  } else {
    App_Model_DW.is_WPCMode_Run = App_Model_IN_NO_ACTIVE_CHILD_ef;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Mod_Tick_Timer_CardINDBlk_o(void)
{
  switch (App_Model_DW.is_Tick_Timer_CardINDBlk) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == event_Start_Timer_CardINDBlk_g) {
      App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_CardINDBlk_b) {
        App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_Off_h;
        App_Model_DW.Timer_CardINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_CardINDBlk + 1;
        if (App_Model_DW.Timer_CardINDBlk + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_CardINDBlk = (uint16)tmp;
        if (App_Model_DW.sfEvent_m == event_Start_Timer_CardINDBlk_g) {
          App_Model_DW.Timer_CardINDBlk = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void Ap_Function_CardLEDErrorBlink_l(Bool rtu_Main_InSig_h, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po)
{
  switch (rtu_Main_InSig_h) {
   case Off:
    {
      /* ForCardError%WPC가 하나이거나 우선순위가 가장 높을경우 */
      if ((*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt >= 2)) {
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_b = Off;
        *rty_MainOut_Sig_gc = Off;
      } else if (App_Model_DW.Counter_BlinkCnt >= 2) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_b = Off;
        d_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_CardINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
          App_Mod_Tick_Timer_CardINDBlk_o();
        }

        App_Model_DW.sfEvent_m = d_previousEvent;
        *rty_MainOut_Sig_gc = Off;
      } else if ((*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.is_Tick_Timer_CardINDBlk == App_Model_IN_Off_h)) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_po = BlinkOff;
        *rty_MainOut_Sig_b = Off;
        d_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_CardINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
          App_Mod_Tick_Timer_CardINDBlk_o();
        }

        App_Model_DW.sfEvent_m = d_previousEvent;
      } else if ((*rty_MainOut_Sig_po == BlinkOn) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeIn)))
      {
        *rty_MainOut_Sig_po = BlinkOff;
        App_Model_DW.Counter_BlinkCnt++;
        *rty_MainOut_Sig_b = Off;
      } else if ((*rty_MainOut_Sig_po == BlinkOff) && (((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeOut))
                  || ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_start == WPC2IndCmdState__ErrorOn)))) {
        *rty_MainOut_Sig_po = BlinkOn;

        /* Counter_BlinkCnt ++; */
        *rty_MainOut_Sig_b = On;
      }
    }
    break;

   case On:
    {
      /* ForCardError%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      if ((*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt >= 2)) {
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_b = Off;
        *rty_MainOut_Sig_gc = Off;
      } else if (App_Model_DW.Counter_BlinkCnt >= 2) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_po = BlinkComplete;
        *rty_MainOut_Sig_b = Off;
        d_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_CardINDBlk_b;
        if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
          App_Mod_Tick_Timer_CardINDBlk_o();
        }

        App_Model_DW.sfEvent_m = d_previousEvent;
        *rty_MainOut_Sig_gc = Off;
      } else if ((*rty_MainOut_Sig_po != BlinkComplete) && (App_Model_DW.is_Tick_Timer_CardINDBlk == App_Model_IN_Off_h)) {
        sint32 d_previousEvent;
        *rty_MainOut_Sig_po = BlinkOff;
        *rty_MainOut_Sig_b = Off;
        d_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Start_Timer_CardINDBlk_g;
        if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
          App_Mod_Tick_Timer_CardINDBlk_o();
        }

        App_Model_DW.sfEvent_m = d_previousEvent;
      } else if ((*rty_MainOut_Sig_po == BlinkOn) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeIn)))
      {
        *rty_MainOut_Sig_po = BlinkOff;
        App_Model_DW.Counter_BlinkCnt++;
        *rty_MainOut_Sig_b = Off;
      } else if ((*rty_MainOut_Sig_po == BlinkOff) && (((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeOut))
                  || ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && (App_Model_DW.WPC2IndCmdState_start == WPC2IndCmdState__ErrorOn)))) {
        *rty_MainOut_Sig_po = BlinkOn;

        /* Counter_BlinkCnt ++; */
        *rty_MainOut_Sig_b = On;
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void A_enter_internal_WPCMode_Stop_f(Bool rtu_Main_InSig_gc, WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, Bool rtu_Main_InSig_jg, C_WPCWarning *rty_MainOut_Sig, Bool
  *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po)
{
  /* 1. */
  if (rtu_Main_InSig_gc == On) {
    App_Model_DW.is_WPCMode_Stop = App_Model_IN_WPCStop_TempErr_f;

    /* 240926 */
    *rty_MainOut_Sig_p = Off;
    *rty_MainOut_Sig = Charging_error;
    *rty_MainOut_Sig_po = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);

    /*  Non GFS  */
    *rty_MainOut_Sig_gc = On;
  } else if (rtu_Main_InSig_jg == On) {
    /* CardDetect_240207] */
    App_Model_DW.is_WPCMode_Stop = App_Model_IN_CardDetectError_o;
    *rty_MainOut_Sig = NFCCardDetected;
    *rty_MainOut_Sig_po = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    *rty_MainOut_Sig_e = Off;
    Ap_Function_CardLEDErrorBlink_l(rtu_Main_InSig_h, rty_MainOut_Sig_b, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
    *rty_MainOut_Sig_gc = On;
  } else {
    App_Model_DW.is_WPCMode_Stop = App_Mod_IN_WPCStop_NotTempErr_b;

    /* 240926 */
    *rty_MainOut_Sig_p = Off;
    *rty_MainOut_Sig = WPCWarningOff;
    *rty_MainOut_Sig_e = Off;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Model_WPCMode_Run_g(Bool rtu_Main_InSig, Bool rtu_Main_InSig_g, Bool rtu_Main_InSig_b, Bool rtu_Main_InSig_gc, DeviceState rtu_Main_InSig_p, WPCIndUSMState rtu_Main_InSig_nw, Bool
  rtu_Main_InSig_h, Bool rtu_Main_InSig_jg, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, Bool *rty_MainOut_Sig_p,
  BlinkState *rty_MainOut_Sig_po)
{
  /* 1. */
  if ((rtu_Main_InSig == On) || (rtu_Main_InSig_g == On) || (rtu_Main_InSig_b == On) || (rtu_Main_InSig_gc == On) || (rtu_Main_InSig_jg == On)) {
    /* CardDetect_240207] */
    App_exit_internal_WPCMode_Run_p(rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
    App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_h;
    *rty_MainOut_Sig_g = Off;
    *rty_MainOut_Sig_b = Off;

    /* b_ChargingEnable = Off */
    A_enter_internal_WPCMode_Stop_f(rtu_Main_InSig_gc, rtu_Main_InSig_nw, rtu_Main_InSig_h, rtu_Main_InSig_jg, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_gc,
      rty_MainOut_Sig_p, rty_MainOut_Sig_po);
  } else {
    switch (App_Model_DW.is_WPCMode_Run) {
     case App_Model_IN_WPCRun_Charging_f:
      *rty_MainOut_Sig_g = On;

      /* 1. */
      if ((rtu_Main_InSig_p == Standby) || (rtu_Main_InSig_p == Init)) {
        App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Standby_m;
        *rty_MainOut_Sig = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_MainOut_Sig_g = Off;
        *rty_MainOut_Sig_b = Off;
        *rty_MainOut_Sig_e = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_p) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_FODError_g;
          *rty_MainOut_Sig = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_MainOut_Sig_po = BlinkOff;
          App_Model_DW.Counter_BlinkCnt = 0U;
          *rty_MainOut_Sig_g = Off;
          *rty_MainOut_Sig_b = Off;
          App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);

          /*  Non GFS  */
          *rty_MainOut_Sig_gc = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run = Ap_IN_WPCRun_ChargingComplete_g;
          *rty_MainOut_Sig = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_MainOut_Sig_g = On;
          *rty_MainOut_Sig_b = On;
          *rty_MainOut_Sig_e = Off;
          break;

         default:
          App_Function_ChargingINDColor_k(rtu_Main_InSig_nw, rty_MainOut_Sig_b, rty_MainOut_Sig_e);
          break;
        }
      }
      break;

     case Ap_IN_WPCRun_ChargingComplete_g:
      *rty_MainOut_Sig_g = On;

      /* 1. */
      if ((rtu_Main_InSig_p == Standby) || (rtu_Main_InSig_p == Init)) {
        App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Standby_m;
        *rty_MainOut_Sig = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_MainOut_Sig_g = Off;
        *rty_MainOut_Sig_b = Off;
        *rty_MainOut_Sig_e = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_p) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_FODError_g;
          *rty_MainOut_Sig = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_MainOut_Sig_po = BlinkOff;
          App_Model_DW.Counter_BlinkCnt = 0U;
          *rty_MainOut_Sig_g = Off;
          *rty_MainOut_Sig_b = Off;
          App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);

          /*  Non GFS  */
          *rty_MainOut_Sig_gc = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Charging_f;
          *rty_MainOut_Sig = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_MainOut_Sig_g = On;
          App_Function_ChargingINDColor_k(rtu_Main_InSig_nw, rty_MainOut_Sig_b, rty_MainOut_Sig_e);
          break;
        }
      }
      break;

     case App_Model_IN_WPCRun_FODError_g:
      {
        *rty_MainOut_Sig_g = Off;

        /* 1. */
        if ((rtu_Main_InSig_p == Standby) || (rtu_Main_InSig_p == Init)) {
          sint32 c_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          *rty_MainOut_Sig_po = BlinkOff;
          App_Model_DW.Counter_BlinkCnt = 0U;
          c_previousEvent = App_Model_DW.sfEvent_m;
          App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
          if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
            App_Mo_Tick_Timer_AmberINDBlk_h();
          }

          App_Model_DW.sfEvent_m = c_previousEvent;

          /*  Non GFS  */
          *rty_MainOut_Sig_gc = Off;
          App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Standby_m;
          *rty_MainOut_Sig = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          *rty_MainOut_Sig_g = Off;
          *rty_MainOut_Sig_b = Off;
          *rty_MainOut_Sig_e = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_p) {
           case Charging:
            {
              sint32 c_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_MainOut_Sig_po = BlinkOff;
              App_Model_DW.Counter_BlinkCnt = 0U;
              c_previousEvent = App_Model_DW.sfEvent_m;
              App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
              if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Mo_Tick_Timer_AmberINDBlk_h();
              }

              App_Model_DW.sfEvent_m = c_previousEvent;

              /*  Non GFS  */
              *rty_MainOut_Sig_gc = Off;
              App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Charging_f;
              *rty_MainOut_Sig = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_MainOut_Sig_g = On;
              App_Function_ChargingINDColor_k(rtu_Main_InSig_nw, rty_MainOut_Sig_b, rty_MainOut_Sig_e);
            }
            break;

           case Full_Charge:
            {
              sint32 c_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_MainOut_Sig_po = BlinkOff;
              App_Model_DW.Counter_BlinkCnt = 0U;
              c_previousEvent = App_Model_DW.sfEvent_m;
              App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
              if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Mo_Tick_Timer_AmberINDBlk_h();
              }

              App_Model_DW.sfEvent_m = c_previousEvent;

              /*  Non GFS  */
              *rty_MainOut_Sig_gc = Off;
              App_Model_DW.is_WPCMode_Run = Ap_IN_WPCRun_ChargingComplete_g;
              *rty_MainOut_Sig = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_MainOut_Sig_g = On;
              *rty_MainOut_Sig_b = On;
              *rty_MainOut_Sig_e = Off;
            }
            break;

           default:
            App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
            break;
          }
        }
      }
      break;

     case App_Model_IN_WPCRun_Standby_m:
      *rty_MainOut_Sig_g = Off;

      /* 1. */
      switch (rtu_Main_InSig_p) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_FODError_g;
        *rty_MainOut_Sig = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        *rty_MainOut_Sig_po = BlinkOff;
        App_Model_DW.Counter_BlinkCnt = 0U;
        *rty_MainOut_Sig_g = Off;
        *rty_MainOut_Sig_b = Off;
        App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);

        /*  Non GFS  */
        *rty_MainOut_Sig_gc = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Charging_f;
        *rty_MainOut_Sig = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        *rty_MainOut_Sig_g = On;
        App_Function_ChargingINDColor_k(rtu_Main_InSig_nw, rty_MainOut_Sig_b, rty_MainOut_Sig_e);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run = Ap_IN_WPCRun_ChargingComplete_g;
        *rty_MainOut_Sig = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        *rty_MainOut_Sig_g = On;
        *rty_MainOut_Sig_b = On;
        *rty_MainOut_Sig_e = Off;
        break;
      }
      break;
    }
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void Ap_exit_internal_WPCMode_Stop_b(Bool *rty_MainOut_Sig_gc, BlinkState *rty_MainOut_Sig_po)
{
  switch (App_Model_DW.is_WPCMode_Stop) {
   case App_Model_IN_CardDetectError_o:
    {
      sint32 b_previousEvent;
      *rty_MainOut_Sig_po = BlinkOff;
      App_Model_DW.Counter_BlinkCnt = 0U;
      b_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = event_Cancel_Timer_CardINDBlk_b;
      if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
        App_Mod_Tick_Timer_CardINDBlk_o();
      }

      App_Model_DW.sfEvent_m = b_previousEvent;
      *rty_MainOut_Sig_gc = Off;
      App_Model_DW.is_WPCMode_Stop = App_Model_IN_NO_ACTIVE_CHILD_ef;
    }
    break;

   case App_Model_IN_WPCStop_TempErr_f:
    {
      sint32 b_previousEvent;
      *rty_MainOut_Sig_po = BlinkOff;
      App_Model_DW.Counter_BlinkCnt = 0U;
      b_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
      if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
        App_Mo_Tick_Timer_AmberINDBlk_h();
      }

      App_Model_DW.sfEvent_m = b_previousEvent;

      /*  Non GFS  */
      *rty_MainOut_Sig_gc = Off;
      App_Model_DW.is_WPCMode_Stop = App_Model_IN_NO_ACTIVE_CHILD_ef;
    }
    break;

   default:
    App_Model_DW.is_WPCMode_Stop = App_Model_IN_NO_ACTIVE_CHILD_ef;
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_atomic_WPCMode_Disable_i(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, BlinkState *rty_MainOut_Sig_po, Bool
  *rty_MainOut_Sig_k)
{
  sint32 b_previousEvent;
  *rty_MainOut_Sig = WPCWarningOff;
  *rty_MainOut_Sig_po = BlinkOff;
  App_Model_DW.Counter_BlinkCnt = 0U;
  *rty_MainOut_Sig_g = Off;
  *rty_MainOut_Sig_b = Off;
  *rty_MainOut_Sig_e = Off;
  *rty_MainOut_Sig_k = Off;
  b_previousEvent = App_Model_DW.sfEvent_m;
  App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
  if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
    App_Mo_Tick_Timer_AmberINDBlk_h();
  }

  App_Model_DW.sfEvent_m = b_previousEvent;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Mode_Tick_Timer_PhoneLeft_k(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == A_event_Start_Timer_PhoneLeft_d) {
      App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_PhoneLeft_p) {
        App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_Off_h;
        App_Model_DW.Timer_PhoneLeft = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_PhoneLeft + 1;
        if (App_Model_DW.Timer_PhoneLeft + 1 > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft = (uint8)tmp;
        if (App_Model_DW.sfEvent_m == A_event_Start_Timer_PhoneLeft_d) {
          App_Model_DW.Timer_PhoneLeft = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void Tick_Timer_PhoneWarningCheck_f(uint16 *rty_MainOut_Sig_n)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarningCheck) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == event_Start_Timer_PhoneWarnin_g) {
      App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_PhoneWarni_a) {
        App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_h;
        App_Model_DW.Timer_PhoneWarningCheck = 0U;
        *rty_MainOut_Sig_n = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_PhoneWarningCheck + 1;
        if (App_Model_DW.Timer_PhoneWarningCheck + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck = (uint16)tmp;
        *rty_MainOut_Sig_n = App_Model_DW.Timer_PhoneWarningCheck;
        if (App_Model_DW.sfEvent_m == event_Start_Timer_PhoneWarnin_g) {
          App_Model_DW.Timer_PhoneWarningCheck = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void Tick_Timer_PhoneReminderCheck_h(uint16 *rty_MainOut_Sig_j)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneReminderChec) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == event_Start_Timer_PhoneRemind_i) {
      App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_PhoneRemin_l) {
        App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_h;
        App_Model_DW.Timer_PhoneReminderCheck = 0U;
        *rty_MainOut_Sig_j = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_PhoneReminderCheck + 1;
        if (App_Model_DW.Timer_PhoneReminderCheck + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneReminderCheck = (uint16)tmp;
        *rty_MainOut_Sig_j = App_Model_DW.Timer_PhoneReminderCheck;
        if (App_Model_DW.sfEvent_m == event_Start_Timer_PhoneRemind_i) {
          App_Model_DW.Timer_PhoneReminderCheck = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void Ap_Tick_Timer_WarningComplete_a(uint16 *rty_MainOut_Sig_nt)
{
  switch (App_Model_DW.is_Tick_Timer_WarningComplete) {
   case App_Model_IN_Off_h:
    if (App_Model_DW.sfEvent_m == event_Start_Timer_WarningComp_g) {
      App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_On_a;
    }
    break;

   case App_Model_IN_On_a:
    {
      if (App_Model_DW.sfEvent_m == event_Cancel_Timer_WarningCom_g) {
        App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_Off_h;
        App_Model_DW.Timer_WarningComplete = 0U;
        *rty_MainOut_Sig_nt = 0U;
      } else {
        sint32 tmp;
        tmp = App_Model_DW.Timer_WarningComplete + 1;
        if (App_Model_DW.Timer_WarningComplete + 1 > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete = (uint16)tmp;
        *rty_MainOut_Sig_nt = App_Model_DW.Timer_WarningComplete;
        if (App_Model_DW.sfEvent_m == event_Start_Timer_WarningComp_g) {
          App_Model_DW.Timer_WarningComplete = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Model_Function_WPCWarning_k(C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, C_WPCWarning *rty_MainOut_Sig, uint16
  *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_k)
{
  /* 1 */
  if ((rtu_Main_InSig_e == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck >= Par_PhoneCheckTime) && (rtu_Main_InSig_nt == Off)) || (App_Model_DW.Timer_PhoneLeft >= 50)) {
    sint32 c_previousEvent;
    *rty_MainOut_Sig = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    App_Model_DW.b_WarnClearEnable = Off;
    *rty_MainOut_Sig_k = Off;
    c_previousEvent = App_Model_DW.sfEvent_m;
    App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneLeft_p;
    if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
      App_Mode_Tick_Timer_PhoneLeft_k();
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneWarni_a;
    if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneRemin_l;
    if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_WarningCom_g;
    if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
      Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
    }

    App_Model_DW.sfEvent_m = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /* 1. */
    if ((App_Model_DW.b_WarnClearEnable == On) && ((App_Model_DW.b_WPCPhoneExist_prev != App_Model_DW.b_WPCPhoneExist_start) && (App_Model_DW.b_WPCPhoneExist_start == Off))) {
      c_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = A_event_Start_Timer_PhoneLeft_d;
      if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
        App_Mode_Tick_Timer_PhoneLeft_k();
      }

      App_Model_DW.sfEvent_m = c_previousEvent;

      /* 1. */
    } else if ((App_Model_DW.is_Tick_Timer_PhoneLeft == App_Model_IN_On_a) && (rtu_Main_InSig_nt == On)) {
      c_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneLeft_p;
      if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
        App_Mode_Tick_Timer_PhoneLeft_k();
      }

      App_Model_DW.sfEvent_m = c_previousEvent;
    }

    /* 1. */
    if ((App_Model_DW.Timer_PhoneWarningCheck >= 10) && (App_Model_DW.Timer_PhoneWarningCheck <= Par_PhoneCheckTime) && (rtu_Main_InSig_nt == On)) {
      *rty_MainOut_Sig = Cellphoneonthepad;

      /* b_WPCWarn = Cellphoneonthepad 8차 LFRollBack */
      App_Model_DW.b_WarnClearEnable = On;
      c_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneWarni_a;
      if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
      }

      App_Model_DW.sfEvent_m = event_Start_Timer_PhoneRemind_i;
      if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
        Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
      }

      App_Model_DW.sfEvent_m = c_previousEvent;

      /* 5차 적용 */

      /* 1. */
    } else if ((App_Model_DW.Timer_PhoneReminderCheck >= 6000) && (App_Model_DW.b_WarnClearEnable == On) && (rtu_Main_InSig_nt == On)) {
      /* 1. */
      if ((rtu_Main_InSig_n == On) || (rtu_Main_InSig_j == On)) {
        App_Model_DW.b_WarnClearEnable = Off;
        *rty_MainOut_Sig = WPCWarningOff;
        *rty_MainOut_Sig_k = Off;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        c_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneRemin_l;
        if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
          Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
        }

        App_Model_DW.sfEvent_m = c_previousEvent;
      } else {
        /* 2. */
        *rty_MainOut_Sig = Cellphonereminder;

        /* b_WPCWarn = Cellphonereminder 8차 LFRollBack */
        c_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneRemin_l;
        if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
          Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
        }

        App_Model_DW.sfEvent_m = event_Start_Timer_WarningComp_g;
        if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
          Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
        }

        App_Model_DW.sfEvent_m = c_previousEvent;
      }

      /* 1. */
    } else if ((App_Model_DW.Timer_WarningComplete >= 50) && (App_Model_DW.b_WarnClearEnable == On) && (rtu_Main_InSig_nt == On)) {
      *rty_MainOut_Sig = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_DW.b_WarnClearEnable = Off;
      *rty_MainOut_Sig_k = Off;
      c_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = event_Cancel_Timer_WarningCom_g;
      if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
        Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
      }

      App_Model_DW.sfEvent_m = c_previousEvent;
    }
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App__enter_atomic_WPCMode_NFC_f(uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt)
{
  sint32 b_previousEvent;
  App_Model_DW.b_WarnClearEnable = Off;
  b_previousEvent = App_Model_DW.sfEvent_m;
  App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneLeft_p;
  if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
    App_Mode_Tick_Timer_PhoneLeft_k();
  }

  App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneWarni_a;
  if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
    Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
  }

  App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneRemin_l;
  if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
    Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
  }

  App_Model_DW.sfEvent_m = event_Cancel_Timer_WarningCom_g;
  if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
    Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
  }

  App_Model_DW.sfEvent_m = b_previousEvent;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_WPCMode_Disabl_g(C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_j, Bool rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, WPCStatus rtu_Main_InSig_po, C_WPCWarning
  *rty_MainOut_Sig, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_k)
{
  /* 1. */
  if ((rtu_Main_InSig_po == NFCMode) || (rtu_Main_InSig_po == LPCDMode) || (rtu_Main_InSig_po == PICCMode)) {
    App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_b;
    App__enter_atomic_WPCMode_NFC_f(rty_MainOut_Sig_j, rty_MainOut_Sig_n, rty_MainOut_Sig_nt);
  } else {
    App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_Off_i;
    if ((App_Model_DW.L_IGN1_IN_prev != App_Model_DW.L_IGN1_IN_start) && (App_Model_DW.L_IGN1_IN_start == Off)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCMode_Off = App_M_IN_LeavingPhone_Warning_k;
      App_Model_DW.b_WarnClearEnable = Off;
      b_previousEvent = App_Model_DW.sfEvent_m;
      App_Model_DW.sfEvent_m = event_Start_Timer_PhoneWarnin_g;
      if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
      }

      App_Model_DW.sfEvent_m = b_previousEvent;
      App_Model_Function_WPCWarning_k(rtu_Main_InSig_e, rtu_Main_InSig_j, rtu_Main_InSig_n, rtu_Main_InSig_nt, rty_MainOut_Sig, rty_MainOut_Sig_j, rty_MainOut_Sig_n, rty_MainOut_Sig_nt,
        rty_MainOut_Sig_k);
      *rty_MainOut_Sig_k = On;
    } else {
      App_Model_DW.is_WPCMode_Off = App_IN_LeavingPhone_NoWarning_n;
    }
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void App_Model_MainControl_k(Bool rtu_Main_InSig, Bool rtu_Main_InSig_g, Bool rtu_Main_InSig_b, C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_gc, Bool rtu_Main_InSig_j, Bool
  rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, DeviceState rtu_Main_InSig_p, WPCStatus rtu_Main_InSig_po, WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, Bool rtu_Main_InSig_jg, C_WPCWarning
  *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16
  *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k)
{
  switch (App_Model_DW.is_MainControl) {
   case App_Model_IN_WPCMode_Disable_l:
    {
      /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
      *rty_MainOut_Sig_g = Off;

      /* 1. */
      if (rtu_Main_InSig_po == WPCMode) {
        sint32 b_previousEvent;
        if (App_Model_DW.is_WPCMode_Disable == App_Model_IN_WPCMode_Off_i) {
          if (App_Model_DW.is_WPCMode_Off == App_M_IN_LeavingPhone_Warning_k) {
            /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
            *rty_MainOut_Sig = WPCWarningOff;
            *rty_MainOut_Sig_k = Off;
            App_Model_DW.is_WPCMode_Off = App_Model_IN_NO_ACTIVE_CHILD_ef;
          } else {
            App_Model_DW.is_WPCMode_Off = App_Model_IN_NO_ACTIVE_CHILD_ef;
          }

          App_Model_DW.is_WPCMode_Disable = App_Model_IN_NO_ACTIVE_CHILD_ef;
        } else {
          App_Model_DW.is_WPCMode_Disable = App_Model_IN_NO_ACTIVE_CHILD_ef;
        }

        App_Model_DW.b_WarnClearEnable = Off;
        b_previousEvent = App_Model_DW.sfEvent_m;
        App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneLeft_p;
        if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
          App_Mode_Tick_Timer_PhoneLeft_k();
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneWarni_a;
        if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
          /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
          Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneRemin_l;
        if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
          /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
          Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
        }

        App_Model_DW.sfEvent_m = event_Cancel_Timer_WarningCom_g;
        if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
          /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
          Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
        }

        App_Model_DW.sfEvent_m = b_previousEvent;
        App_Model_DW.is_MainControl = App_Model_IN_WPCMode_Enable_o;
        App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_h;

        /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
        *rty_MainOut_Sig_g = Off;
        *rty_MainOut_Sig_b = Off;

        /* b_ChargingEnable = Off */
        A_enter_internal_WPCMode_Stop_f(rtu_Main_InSig_gc, rtu_Main_InSig_nw, rtu_Main_InSig_h, rtu_Main_InSig_jg, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_gc,
          rty_MainOut_Sig_p, rty_MainOut_Sig_po);
      } else {
        switch (App_Model_DW.is_WPCMode_Disable) {
         case App_Model_IN_WPCMode_NFC_b:
          /* 1. */
          if (rtu_Main_InSig_po == ModeOff) {
            App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_Off_i;
            App_Model_DW.is_WPCMode_Off = App_IN_LeavingPhone_NoWarning_n;
          }
          break;

         case App_Model_IN_WPCMode_Off_i:
          /* 1. */
          if ((rtu_Main_InSig_po == NFCMode) || (rtu_Main_InSig_po == LPCDMode) || (rtu_Main_InSig_po == PICCMode)) {
            if (App_Model_DW.is_WPCMode_Off == App_M_IN_LeavingPhone_Warning_k) {
              /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
              *rty_MainOut_Sig = WPCWarningOff;
              *rty_MainOut_Sig_k = Off;
              App_Model_DW.is_WPCMode_Off = App_Model_IN_NO_ACTIVE_CHILD_ef;
            } else {
              App_Model_DW.is_WPCMode_Off = App_Model_IN_NO_ACTIVE_CHILD_ef;
            }

            App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_b;

            /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
            App__enter_atomic_WPCMode_NFC_f(rty_MainOut_Sig_j, rty_MainOut_Sig_n, rty_MainOut_Sig_nt);
          } else if (App_Model_DW.is_WPCMode_Off == App_M_IN_LeavingPhone_Warning_k) {
            /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
            App_Model_Function_WPCWarning_k(rtu_Main_InSig_e, rtu_Main_InSig_j, rtu_Main_InSig_n, rtu_Main_InSig_nt, rty_MainOut_Sig, rty_MainOut_Sig_j, rty_MainOut_Sig_n, rty_MainOut_Sig_nt,
              rty_MainOut_Sig_k);
          }
          break;
        }
      }
    }
    break;

   case App_Model_IN_WPCMode_Enable_o:
    {
      /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
      /* 1. */
      if (rtu_Main_InSig_po != WPCMode) {
        switch (App_Model_DW.is_WPCMode_Enable) {
         case App_Model_IN_WPCMode_Run_f:
          App_exit_internal_WPCMode_Run_p(rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
          App_Model_DW.is_WPCMode_Enable = App_Model_IN_NO_ACTIVE_CHILD_ef;
          break;

         case App_Model_IN_WPCMode_Stop_h:
          Ap_exit_internal_WPCMode_Stop_b(rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
          App_Model_DW.is_WPCMode_Enable = App_Model_IN_NO_ACTIVE_CHILD_ef;
          break;
        }

        *rty_MainOut_Sig_p = Off;
        App_Model_DW.is_MainControl = App_Model_IN_WPCMode_Disable_l;
        enter_atomic_WPCMode_Disable_i(rty_MainOut_Sig, rty_MainOut_Sig_g, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_po, rty_MainOut_Sig_k);
        enter_internal_WPCMode_Disabl_g(rtu_Main_InSig_e, rtu_Main_InSig_j, rtu_Main_InSig_n, rtu_Main_InSig_nt, rtu_Main_InSig_po, rty_MainOut_Sig, rty_MainOut_Sig_j, rty_MainOut_Sig_n,
          rty_MainOut_Sig_nt, rty_MainOut_Sig_k);
      } else {
        switch (App_Model_DW.is_WPCMode_Enable) {
         case App_Model_IN_WPCMode_Run_f:
          App_Model_WPCMode_Run_g(rtu_Main_InSig, rtu_Main_InSig_g, rtu_Main_InSig_b, rtu_Main_InSig_gc, rtu_Main_InSig_p, rtu_Main_InSig_nw, rtu_Main_InSig_h, rtu_Main_InSig_jg, rty_MainOut_Sig,
            rty_MainOut_Sig_g, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_p, rty_MainOut_Sig_po);
          break;

         case App_Model_IN_WPCMode_Stop_h:
          {
            *rty_MainOut_Sig_g = Off;
            if ((rtu_Main_InSig_p == Full_Charge) && (rtu_Main_InSig == Off) && (rtu_Main_InSig_g == Off) && (rtu_Main_InSig_gc == Off) && (rtu_Main_InSig_b == Off) && (rtu_Main_InSig_jg == Off)) {
              /* CardDetect_240207] */
              Ap_exit_internal_WPCMode_Stop_b(rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
              App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f;
              *rty_MainOut_Sig_p = On;

              /* b_ROHMOperCmd = On /_ Non GFS _/ */
              App_Model_DW.is_WPCMode_Run = Ap_IN_WPCRun_ChargingComplete_g;
              *rty_MainOut_Sig = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_MainOut_Sig_g = On;
              *rty_MainOut_Sig_b = On;
              *rty_MainOut_Sig_e = Off;
            } else if ((rtu_Main_InSig_p == Charging) && (rtu_Main_InSig == Off) && (rtu_Main_InSig_g == Off) && (rtu_Main_InSig_gc == Off) && (rtu_Main_InSig_b == Off) && (rtu_Main_InSig_jg == Off))
            {
              /* CardDetect_240207] */
              Ap_exit_internal_WPCMode_Stop_b(rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
              App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f;
              *rty_MainOut_Sig_p = On;

              /* b_ROHMOperCmd = On /_ Non GFS _/ */
              App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Charging_f;
              *rty_MainOut_Sig = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_MainOut_Sig_g = On;
              App_Function_ChargingINDColor_k(rtu_Main_InSig_nw, rty_MainOut_Sig_b, rty_MainOut_Sig_e);
            } else {
              switch (App_Model_DW.is_WPCMode_Stop) {
               case App_Model_IN_CardDetectError_o:
                {
                  if (rtu_Main_InSig_jg == Off) {
                    sint32 b_previousEvent;

                    /* CardDetect_240207] */
                    *rty_MainOut_Sig_po = BlinkOff;
                    App_Model_DW.Counter_BlinkCnt = 0U;
                    b_previousEvent = App_Model_DW.sfEvent_m;
                    App_Model_DW.sfEvent_m = event_Cancel_Timer_CardINDBlk_b;
                    if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
                      App_Mod_Tick_Timer_CardINDBlk_o();
                    }

                    App_Model_DW.sfEvent_m = b_previousEvent;
                    *rty_MainOut_Sig_gc = Off;
                    App_Model_DW.is_WPCMode_Stop = App_Model_IN_NO_ACTIVE_CHILD_ef;
                    App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f;
                    *rty_MainOut_Sig_p = On;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Standby_m;
                    *rty_MainOut_Sig = WPCWarningOff;

                    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                    *rty_MainOut_Sig_g = Off;
                    *rty_MainOut_Sig_b = Off;
                    *rty_MainOut_Sig_e = Off;
                  } else {
                    Ap_Function_CardLEDErrorBlink_l(rtu_Main_InSig_h, rty_MainOut_Sig_b, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
                  }
                }
                break;

               case App_Mod_IN_WPCStop_NotTempErr_b:
                /* 1. */
                if (rtu_Main_InSig_gc == On) {
                  App_Model_DW.is_WPCMode_Stop = App_Model_IN_WPCStop_TempErr_f;

                  /* 240926 */
                  *rty_MainOut_Sig_p = Off;
                  *rty_MainOut_Sig = Charging_error;
                  *rty_MainOut_Sig_po = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt = 0U;
                  App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);

                  /*  Non GFS  */
                  *rty_MainOut_Sig_gc = On;

                  /* 2. */
                } else if ((rtu_Main_InSig == Off) && (rtu_Main_InSig_g == Off) && (rtu_Main_InSig_b == Off)) {
                  /* b_ChargingEnable == On 8차 적용 삭제 */
                  App_Model_DW.is_WPCMode_Stop = App_Model_IN_NO_ACTIVE_CHILD_ef;
                  App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f;
                  *rty_MainOut_Sig_p = On;

                  /* b_ROHMOperCmd = On /_ Non GFS _/ */
                  App_Model_DW.is_WPCMode_Run = App_Model_IN_WPCRun_Standby_m;
                  *rty_MainOut_Sig = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  *rty_MainOut_Sig_g = Off;
                  *rty_MainOut_Sig_b = Off;
                  *rty_MainOut_Sig_e = Off;
                } else if (rtu_Main_InSig_jg == On) {
                  /* CardDetect_240207] */
                  App_Model_DW.is_WPCMode_Stop = App_Model_IN_CardDetectError_o;
                  *rty_MainOut_Sig = NFCCardDetected;
                  *rty_MainOut_Sig_po = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt = 0U;
                  *rty_MainOut_Sig_e = Off;
                  Ap_Function_CardLEDErrorBlink_l(rtu_Main_InSig_h, rty_MainOut_Sig_b, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
                  *rty_MainOut_Sig_gc = On;
                }
                break;

               case App_Model_IN_WPCStop_TempErr_f:
                {
                  /* 1. */
                  if (rtu_Main_InSig_gc == Off) {
                    sint32 b_previousEvent;
                    *rty_MainOut_Sig_po = BlinkOff;
                    App_Model_DW.Counter_BlinkCnt = 0U;
                    b_previousEvent = App_Model_DW.sfEvent_m;
                    App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
                    if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
                      App_Mo_Tick_Timer_AmberINDBlk_h();
                    }

                    App_Model_DW.sfEvent_m = b_previousEvent;

                    /*  Non GFS  */
                    *rty_MainOut_Sig_gc = Off;
                    App_Model_DW.is_WPCMode_Stop = App_Mod_IN_WPCStop_NotTempErr_b;

                    /* 240926 */
                    *rty_MainOut_Sig_p = Off;
                    *rty_MainOut_Sig = WPCWarningOff;
                    *rty_MainOut_Sig_e = Off;
                  } else {
                    App_Mo_Function_LEDErrorBlink_l(rtu_Main_InSig_nw, rtu_Main_InSig_h, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_po);
                  }
                }
                break;
              }
            }
          }
          break;
        }
      }
    }
    break;

   case App_Model_IN_WPCMode_Init_n:
    /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
    *rty_MainOut_Sig_g = Off;

    /* 1. */
    if (rtu_Main_InSig_po != WPCMode) {
      App_Model_DW.is_MainControl = App_Model_IN_WPCMode_Disable_l;

      /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
      enter_atomic_WPCMode_Disable_i(rty_MainOut_Sig, rty_MainOut_Sig_g, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_po, rty_MainOut_Sig_k);
      enter_internal_WPCMode_Disabl_g(rtu_Main_InSig_e, rtu_Main_InSig_j, rtu_Main_InSig_n, rtu_Main_InSig_nt, rtu_Main_InSig_po, rty_MainOut_Sig, rty_MainOut_Sig_j, rty_MainOut_Sig_n,
        rty_MainOut_Sig_nt, rty_MainOut_Sig_k);

      /* 2 */
    } else if (rtu_Main_InSig_po == WPCMode) {
      App_Model_DW.is_MainControl = App_Model_IN_WPCMode_Enable_o;
      App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_h;

      /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
      *rty_MainOut_Sig_g = Off;
      *rty_MainOut_Sig_b = Off;

      /* b_ChargingEnable = Off */
      A_enter_internal_WPCMode_Stop_f(rtu_Main_InSig_gc, rtu_Main_InSig_nw, rtu_Main_InSig_h, rtu_Main_InSig_jg, rty_MainOut_Sig, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_gc,
        rty_MainOut_Sig_p, rty_MainOut_Sig_po);
    }
    break;
  }
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Pho_a(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_Off_h;
  App_Model_DW.Timer_PhoneLeft = 0U;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Pho_n(uint16 *rty_MainOut_Sig_n)
{
  App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_h;
  App_Model_DW.Timer_PhoneWarningCheck = 0U;

  /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
  *rty_MainOut_Sig_n = 0U;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Pho_p(uint16 *rty_MainOut_Sig_j)
{
  App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_h;
  App_Model_DW.Timer_PhoneReminderCheck = 0U;

  /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
  *rty_MainOut_Sig_j = 0U;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_War_n(uint16 *rty_MainOut_Sig_nt)
{
  App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_Off_h;
  App_Model_DW.Timer_WarningComplete = 0U;

  /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
  *rty_MainOut_Sig_nt = 0U;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Amb_a(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_h;
  App_Model_DW.Timer_AmberINDBlk = 0U;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Am_ar(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_h;
  App_Model_DW.Timer_AmberINDBlk2 = 0U;
}

/* Function for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
static void enter_internal_Tick_Timer_Car_g(void)
{
  App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_Off_h;
  App_Model_DW.Timer_CardINDBlk = 0U;
}

/* System initialize for atomic system: '<S14>/WPC_MainControl_Function' */
void WPC_MainControl_Function_g_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16 *rty_MainOut_Sig_j,
  uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k)
{
  /* SystemInitialize for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
  App_Model_DW.sfEvent_m = App_Model_CALL_EVENT_de;
  *rty_MainOut_Sig = WPCWarningOff;
  *rty_MainOut_Sig_g = Off;
  *rty_MainOut_Sig_b = Off;
  *rty_MainOut_Sig_e = Off;
  *rty_MainOut_Sig_gc = Off;
  *rty_MainOut_Sig_j = 0U;
  *rty_MainOut_Sig_n = 0U;
  *rty_MainOut_Sig_nt = 0U;
  *rty_MainOut_Sig_p = Off;
  *rty_MainOut_Sig_po = BlinkOff;
  *rty_MainOut_Sig_k = Off;
}

/* System reset for atomic system: '<S14>/WPC_MainControl_Function' */
void WPC_MainControl_Functio_f_Reset(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16 *rty_MainOut_Sig_j,
  uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k)
{
  /* SystemReset for Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
  App_Model_DW.sfEvent_m = App_Model_CALL_EVENT_de;
  App_Model_DW.is_active_MainControl = 0U;
  App_Model_DW.is_MainControl = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_WPCMode_Disable = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_WPCMode_Off = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_WPCMode_Enable = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_WPCMode_Run = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_WPCMode_Stop = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_AmberINDBl = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_AmberIND_g = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_CardINDBlk = 0U;
  App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_PhoneLeft = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_PhoneRemin = 0U;
  App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_PhoneWarni = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_Tick_Timer_WarningCom = 0U;
  App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_NO_ACTIVE_CHILD_ef;
  App_Model_DW.is_active_c52_MainControl_Lib = 0U;
  App_Model_DW.b_WarnClearEnable = Off;
  App_Model_DW.Timer_AmberINDBlk = 0U;
  App_Model_DW.Timer_PhoneLeft = 0U;
  App_Model_DW.Timer_PhoneReminderCheck = 0U;
  App_Model_DW.Timer_PhoneWarningCheck = 0U;
  App_Model_DW.Timer_WarningComplete = 0U;
  App_Model_DW.Counter_BlinkCnt = 0U;
  App_Model_DW.Timer_AmberINDBlk2 = 0U;
  App_Model_DW.Timer_CardINDBlk = 0U;
  *rty_MainOut_Sig = WPCWarningOff;
  *rty_MainOut_Sig_g = Off;
  *rty_MainOut_Sig_b = Off;
  *rty_MainOut_Sig_e = Off;
  *rty_MainOut_Sig_gc = Off;
  *rty_MainOut_Sig_j = 0U;
  *rty_MainOut_Sig_n = 0U;
  *rty_MainOut_Sig_nt = 0U;
  *rty_MainOut_Sig_p = Off;
  *rty_MainOut_Sig_po = BlinkOff;
  *rty_MainOut_Sig_k = Off;
  App_Model_DW.b_WPCPhoneExist_prev = Off;
  App_Model_DW.b_WPCPhoneExist_start = Off;
  App_Model_DW.WPC2IndCmdState_prev = WPC2IndCmdState__Default;
  App_Model_DW.WPC2IndCmdState_start = WPC2IndCmdState__Default;
  App_Model_DW.L_IGN1_IN_prev = Off;
  App_Model_DW.L_IGN1_IN_start = Off;
}

/* Output and update for atomic system: '<S14>/WPC_MainControl_Function' */
void App__WPC_MainControl_Function_e(Bool rtu_Main_InSig, Bool rtu_Main_InSig_g, Bool rtu_Main_InSig_b, C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_gc, Bool rtu_Main_InSig_j, Bool
  rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, DeviceState rtu_Main_InSig_p, WPCStatus rtu_Main_InSig_po, Bool rtu_Main_InSig_k, WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, WPC2IndCmdState
  rtu_Main_InSig_n4, Bool rtu_Main_InSig_jg, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16
  *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k)
{
  /* Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
  App_Model_DW.sfEvent_m = App_Model_CALL_EVENT_de;
  App_Model_DW.b_WPCPhoneExist_prev = App_Model_DW.b_WPCPhoneExist_start;
  App_Model_DW.b_WPCPhoneExist_start = rtu_Main_InSig_nt;
  App_Model_DW.WPC2IndCmdState_prev = App_Model_DW.WPC2IndCmdState_start;
  App_Model_DW.WPC2IndCmdState_start = rtu_Main_InSig_n4;
  App_Model_DW.L_IGN1_IN_prev = App_Model_DW.L_IGN1_IN_start;
  App_Model_DW.L_IGN1_IN_start = rtu_Main_InSig_k;
  if (App_Model_DW.is_active_c52_MainControl_Lib == 0U) {
    App_Model_DW.b_WPCPhoneExist_prev = rtu_Main_InSig_nt;
    App_Model_DW.WPC2IndCmdState_prev = rtu_Main_InSig_n4;
    App_Model_DW.L_IGN1_IN_prev = rtu_Main_InSig_k;
    App_Model_DW.is_active_c52_MainControl_Lib = 1U;
    App_Model_DW.is_active_MainControl = 1U;
    App_Model_DW.is_MainControl = App_Model_IN_WPCMode_Init_n;
    *rty_MainOut_Sig = WPCWarningOff;
    *rty_MainOut_Sig_po = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    App_Model_DW.b_WarnClearEnable = Off;
    *rty_MainOut_Sig_g = Off;
    *rty_MainOut_Sig_b = Off;
    *rty_MainOut_Sig_e = Off;
    *rty_MainOut_Sig_p = Off;
    *rty_MainOut_Sig_k = Off;
    App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneLeft_p;
    if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
      App_Mode_Tick_Timer_PhoneLeft_k();
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneWarni_a;
    if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_PhoneRemin_l;
    if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_WarningCom_g;
    if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
      Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
    }

    App_Model_DW.sfEvent_m = event_Cancel_Timer_AmberINDBl_j;
    if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Mo_Tick_Timer_AmberINDBlk_h();
    }

    App_Model_DW.sfEvent_m = -1;
    App_Model_DW.is_active_Tick_Timer_PhoneLeft = 1U;
    enter_internal_Tick_Timer_Pho_a();
    App_Model_DW.is_active_Tick_Timer_PhoneWarni = 1U;
    enter_internal_Tick_Timer_Pho_n(rty_MainOut_Sig_n);
    App_Model_DW.is_active_Tick_Timer_PhoneRemin = 1U;
    enter_internal_Tick_Timer_Pho_p(rty_MainOut_Sig_j);
    App_Model_DW.is_active_Tick_Timer_WarningCom = 1U;
    enter_internal_Tick_Timer_War_n(rty_MainOut_Sig_nt);
    App_Model_DW.is_active_Tick_Timer_AmberINDBl = 1U;
    enter_internal_Tick_Timer_Amb_a();
    App_Model_DW.is_active_Tick_Timer_AmberIND_g = 1U;
    enter_internal_Tick_Timer_Am_ar();
    App_Model_DW.is_active_Tick_Timer_CardINDBlk = 1U;
    enter_internal_Tick_Timer_Car_g();
  } else {
    if (App_Model_DW.is_active_MainControl != 0U) {
      App_Model_MainControl_k(rtu_Main_InSig, rtu_Main_InSig_g, rtu_Main_InSig_b, rtu_Main_InSig_e, rtu_Main_InSig_gc, rtu_Main_InSig_j, rtu_Main_InSig_n, rtu_Main_InSig_nt, rtu_Main_InSig_p,
        rtu_Main_InSig_po, rtu_Main_InSig_nw, rtu_Main_InSig_h, rtu_Main_InSig_jg, rty_MainOut_Sig, rty_MainOut_Sig_g, rty_MainOut_Sig_b, rty_MainOut_Sig_e, rty_MainOut_Sig_gc, rty_MainOut_Sig_j,
        rty_MainOut_Sig_n, rty_MainOut_Sig_nt, rty_MainOut_Sig_p, rty_MainOut_Sig_po, rty_MainOut_Sig_k);
    }

    if (App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
      App_Mode_Tick_Timer_PhoneLeft_k();
    }

    if (App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningCheck_f(rty_MainOut_Sig_n);
    }

    if (App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCheck_h(rty_MainOut_Sig_j);
    }

    if (App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
      Ap_Tick_Timer_WarningComplete_a(rty_MainOut_Sig_nt);
    }

    if (App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Mo_Tick_Timer_AmberINDBlk_h();
    }

    if (App_Model_DW.is_active_Tick_Timer_AmberIND_g != 0U) {
      App_M_Tick_Timer_AmberINDBlk2_l();
    }

    if (App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
      App_Mod_Tick_Timer_CardINDBlk_o();
    }
  }

  /* End of Chart: '<S380>/WPC2_MainControl4_CardSync_241007' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
