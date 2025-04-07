/*
 * File: NFC_WPC_Mode_Control_Function.c
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
#include "NFC_WPC_Mode_Control_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S187>/WPC_Mode_Control' */
#define App_Model_IN_OperationMode_OFF ((uint8)1U)
#define App_Model_IN_OperationMode_ON  ((uint8)2U)

/* Named constants for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
#define A_event_StartTimer_LPCDOffDelay (11)
#define A_event_StartTimer_PICCOffDelay (17)
#define App_IN_NFCSearchingOffDelay_Off ((uint8)1U)
#define App_M_IN_NFCSearchingTimeout_On ((uint8)2U)
#define App_Mo_IN_NFCTimeOutConfirm_Off ((uint8)1U)
#define App_Mo_IN_PhnLeftChattering_Off ((uint8)1U)
#define App_Mod_IN_NFCTimeOutConfirm_On ((uint8)2U)
#define App_Mod_IN_PICCLPCDOffDelay_Off ((uint8)1U)
#define App_Mod_IN_PhnLeftChattering_On ((uint8)2U)
#define App_Mode_IN_DeviceStateWait_Off ((uint8)1U)
#define App_Mode_IN_PICCLPCDOffDelay_On ((uint8)2U)
#define App_Model_CALL_EVENT_l         (-1)
#define App_Model_IN_DeviceStateWait_On ((uint8)2U)
#define App_Model_IN_LPCDOffDelay_Off  ((uint8)1U)
#define App_Model_IN_LPCDOffDelay_On   ((uint8)2U)
#define App_Model_IN_OperationMode_LPCD ((uint8)1U)
#define App_Model_IN_OperationMode_NFC ((uint8)2U)
#define App_Model_IN_OperationMode_Off ((uint8)3U)
#define App_Model_IN_OperationMode_Picc ((uint8)4U)
#define App_Model_IN_OperationMode_WPC ((uint8)5U)
#define App_Model_IN_PICCOffDelay_Off  ((uint8)1U)
#define App_Model_IN_PICCOffDelay_On   ((uint8)2U)
#define App_Model_IN_PhnLeftHolding_Off ((uint8)1U)
#define App_Model_IN_PhnLeftHolding_On ((uint8)2U)
#define App__IN_NFCSearchingOffDelay_On ((uint8)2U)
#define App__IN_NFCSearchingTimeout_Off ((uint8)1U)
#define event_CancelTimer_LPCDOffDelay (1)
#define event_CancelTimer_NFCSearchingO (2)
#define event_CancelTimer_NFCSearchingT (3)
#define event_CancelTimer_NFCTimeOutCon (4)
#define event_CancelTimer_PICCLPCDOffDe (6)
#define event_CancelTimer_PICCOffDelay (7)
#define event_CancelTimer_PhnLeftChatte (8)
#define event_StartTimer_NFCSearchingOf (12)
#define event_StartTimer_NFCSearchingTi (13)
#define event_StartTimer_NFCTimeOutConf (14)
#define event_StartTimer_PICCLPCDOffDel (16)
#define event_StartTimer_PhnLeftChatter (18)

/* Named constants for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
#define A_IN_NFCSearchingOffDelay_Off_f ((uint8)1U)
#define Ap_IN_NFCSearchingOffDelay_On_b ((uint8)2U)
#define Ap_IN_NFCSearchingTimeout_Off_f ((uint8)1U)
#define App_IN_NFCSearchingTimeout_On_g ((uint8)2U)
#define App_M_IN_NFCTimeOutConfirm_On_f ((uint8)2U)
#define App_M_IN_PICCLPCDOffDelay_Off_b ((uint8)1U)
#define App_M_IN_PhnLeftChattering_On_m ((uint8)2U)
#define App_Mo_IN_DeviceStateWait_Off_d ((uint8)1U)
#define App_Mo_IN_PICCLPCDOffDelay_On_b ((uint8)2U)
#define App_Mod_IN_DeviceStateWait_On_i ((uint8)2U)
#define App_Mod_IN_OperationMode_LPCD_c ((uint8)1U)
#define App_Mod_IN_OperationMode_Picc_o ((uint8)4U)
#define App_Mod_IN_PhnLeftHolding_Off_m ((uint8)1U)
#define App_Mode_IN_OperationMode_NFC_k ((uint8)2U)
#define App_Mode_IN_OperationMode_Off_l ((uint8)3U)
#define App_Mode_IN_OperationMode_WPC_i ((uint8)5U)
#define App_Mode_IN_PhnLeftHolding_On_h ((uint8)2U)
#define App_Model_CALL_EVENT_d         (-1)
#define App_Model_IN_LPCDOffDelay_Off_f ((uint8)1U)
#define App_Model_IN_LPCDOffDelay_On_m ((uint8)2U)
#define App_Model_IN_PICCOffDelay_Off_o ((uint8)1U)
#define App_Model_IN_PICCOffDelay_On_n ((uint8)2U)
#define App__IN_NFCTimeOutConfirm_Off_j ((uint8)1U)
#define App__IN_PhnLeftChattering_Off_d ((uint8)1U)
#define event_CancelTimer_LPCDOffDela_e (1)
#define event_CancelTimer_NFCSearchin_i (2)
#define event_CancelTimer_NFCSearchin_j (3)
#define event_CancelTimer_NFCTimeOutC_b (4)
#define event_CancelTimer_PICCLPCDOff_n (6)
#define event_CancelTimer_PICCOffDela_g (7)
#define event_CancelTimer_PhnLeftChat_a (8)
#define event_StartTimer_LPCDOffDelay_a (11)
#define event_StartTimer_NFCSearching_c (12)
#define event_StartTimer_NFCSearching_f (13)
#define event_StartTimer_NFCTimeOutCo_l (14)
#define event_StartTimer_PICCLPCDOffD_n (16)
#define event_StartTimer_PICCOffDelay_h (17)
#define event_StartTimer_PhnLeftChatt_k (18)

/* Forward declaration for local functions */
static void App_Model_NFCTimeOutConfirm(void);
static void App_Model_NFCSearchingOffDelay(void);
static void App_Model_LPCDOffDelay(void);
static void App_Model_NFCSearchingTimeout(void);
static void App_Model_PICCOffDelay(void);
static void A_exit_atomic_OperationMode_NFC(void);
static void App_Model_PICCLPCDOffDelay(void);
static void App_Mo_NFCSearchingOffDetection(void);
static void App_Model_NFCDetectionCheck(void);
static void enter_atomic_OperationMode_NFC(void);
static void App_Model_LPCDOff_Check(Bool rtu_PreProcessIn_a);
static void enter_atomic_OperationMode_LPCD(Bool rtu_PreProcessIn_a);
static void enter_atomic_OperationMode_Picc(void);
static void App_Model_PhnLeftChattering(void);
static void App_Mode_DrDoorPhnLeftHoldCheck(Bool rtu_PreProcessIn_a, Bool rtu_PreProcessIn_k, C_WPCWarning rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2);
static void enter_atomic_OperationMode_Off(Bool rtu_PreProcessIn_a, Bool rtu_PreProcessIn_k, C_WPCWarning rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2);
static void WPC_NFC_Mode_Control_Function_S(LC_IAUWPCNFCcmd rtu_PreProcessIn_c, Bool rtu_PreProcessIn_a, IAU_OwnerPhnRegRVal rtu_PreProcessIn_m, OwnerPairingAdvertisingReq rtu_PreProcessIn_i,
  C_WPCOnOffNvalueSet rtu_PreProcessIn_ak, OnThePad rtu_PreProcessIn_e, Bool rtu_PreProcessIn_g, Bool rtu_PreProcessIn_n, WPCStatus rtu_PreProcessIn_hg, Bool rtu_PreProcessIn_k, C_WPCWarning
  rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2, Bool rtu_PreProcessIn_mg);

/* Forward declaration for local functions */
static void App_Model_NFCTimeOutConfirm_e(void);
static void App_Mode_NFCSearchingOffDelay_g(void);
static void App_Model_LPCDOffDelay_h(void);
static void App_Model_NFCSearchingTimeout_i(void);
static void App_Model_PICCOffDelay_l(void);
static void exit_atomic_OperationMode_NFC_o(void);
static void App_Model_PICCLPCDOffDelay_d(void);
static void App__NFCSearchingOffDetection_a(void);
static void App_Model_NFCDetectionCheck_g(void);
static void enter_atomic_OperationMode_NF_m(void);
static void enter_atomic_OperationMode_Pi_h(void);
static void App_Model_LPCDOff_Check_o(Bool rtu_PreProcessIn_c);
static void enter_atomic_OperationMode_LP_l(Bool rtu_PreProcessIn_c);
static void App_Model_PhnLeftChattering_i(void);
static void App_Mo_DrDoorPhnLeftHoldCheck_k(Bool rtu_PreProcessIn_c, Bool rtu_PreProcessIn_h, C_WPCWarning rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d);
static void enter_atomic_OperationMode_Of_b(Bool rtu_PreProcessIn_c, Bool rtu_PreProcessIn_h, C_WPCWarning rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d);
static void WPC_NFC_Mode_Control_Function_j(Bool rtu_PreProcessIn_c, LC_IAUWPCNFCcmd rtu_PreProcessIn_e, C_WPCOnOffNvalueSet rtu_PreProcessIn_m, IAU_OwnerPhnRegRVal rtu_PreProcessIn_j,
  OwnerPairingAdvertisingReq rtu_PreProcessIn_l, OnThePad rtu_PreProcessIn_b, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_mb, WPCStatus rtu_PreProcessIn_a, Bool rtu_PreProcessIn_h, C_WPCWarning
  rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d, Bool rtu_PreProcessIn_jq);

/*
 * Output and update for action system:
 *    '<S181>/WPC_Mode_Control'
 *    '<S361>/WPC_Mode_Control'
 */
void App_Model_WPC_Mode_Control(Bool rtu_R_Local_L_IGN1_IN, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_R_Local_sbBatStateFault, WPCStatus *rty_WPC_Status, DW_WPC_Mode_Control_App_Model_T *localDW)
{
  /* Chart: '<S187>/WPC_Mode_Control' */
  if (localDW->is_active_c4_NFC_WPC_Mode_Contr == 0U) {
    localDW->is_active_c4_NFC_WPC_Mode_Contr = 1U;
    localDW->is_WpcNfcModeControl = App_Model_IN_OperationMode_OFF;

    /* SignalConversion generated from: '<S187>/WPC_Status' */
    *rty_WPC_Status = ModeOff;
  } else if (localDW->is_WpcNfcModeControl == App_Model_IN_OperationMode_OFF) {
    /* SignalConversion generated from: '<S187>/WPC_Status' */
    *rty_WPC_Status = ModeOff;

    /* 2. */
    if ((rtu_WPCSWOption == WPC_On) && (rtu_R_Local_L_IGN1_IN == On) && (rtu_R_Local_sbBatStateFault != On)) {
      /* Non_GFS */
      localDW->is_WpcNfcModeControl = App_Model_IN_OperationMode_ON;

      /* SignalConversion generated from: '<S187>/WPC_Status' */
      *rty_WPC_Status = WPCMode;
    }
  } else {
    /* SignalConversion generated from: '<S187>/WPC_Status' */
    /* case IN_OperationMode_ON: */
    *rty_WPC_Status = WPCMode;

    /* 1. */
    if ((rtu_R_Local_L_IGN1_IN == Off) || (rtu_WPCSWOption == WPC_Off) || (rtu_R_Local_sbBatStateFault == On)) {
      /* Non_GFS */
      localDW->is_WpcNfcModeControl = App_Model_IN_OperationMode_OFF;

      /* SignalConversion generated from: '<S187>/WPC_Status' */
      *rty_WPC_Status = ModeOff;
    }
  }

  /* End of Chart: '<S187>/WPC_Mode_Control' */
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_NFCTimeOutConfirm(void)
{
  switch (App_Model_DW.is_NFCTimeOutConfirm_a) {
   case App_Mo_IN_NFCTimeOutConfirm_Off:
    if (App_Model_DW.sfEvent_i == event_StartTimer_NFCTimeOutConf) {
      App_Model_DW.is_NFCTimeOutConfirm_a = App_Mod_IN_NFCTimeOutConfirm_On;
    }
    break;

   case App_Mod_IN_NFCTimeOutConfirm_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_NFCTimeOutCon:
        App_Model_DW.is_NFCTimeOutConfirm_a = App_Mo_IN_NFCTimeOutConfirm_Off;
        App_Model_DW.Timer_NFCTimeOutConfirm_f = 0U;
        break;

       case event_StartTimer_NFCTimeOutConf:
        App_Model_DW.Timer_NFCTimeOutConfirm_f = 0U;
        App_Model_DW.is_NFCTimeOutConfirm_a = App_Mod_IN_NFCTimeOutConfirm_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCTimeOutConfirm_f + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_NFCTimeOutConfirm_f + 1U < App_Model_DW.Timer_NFCTimeOutConfirm_f) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCTimeOutConfirm_f = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_NFCSearchingOffDelay(void)
{
  switch (App_Model_DW.is_NFCSearchingOffDelay_c) {
   case App_IN_NFCSearchingOffDelay_Off:
    if (App_Model_DW.sfEvent_i == event_StartTimer_NFCSearchingOf) {
      App_Model_DW.is_NFCSearchingOffDelay_c = App__IN_NFCSearchingOffDelay_On;
    }
    break;

   case App__IN_NFCSearchingOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_NFCSearchingO:
        App_Model_DW.is_NFCSearchingOffDelay_c = App_IN_NFCSearchingOffDelay_Off;
        App_Model_DW.Timer_NFCSearchingOffDelay_p = 0U;
        break;

       case event_StartTimer_NFCSearchingOf:
        App_Model_DW.Timer_NFCSearchingOffDelay_p = 0U;
        App_Model_DW.is_NFCSearchingOffDelay_c = App__IN_NFCSearchingOffDelay_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingOffDelay_p + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_NFCSearchingOffDelay_p + 1U < App_Model_DW.Timer_NFCSearchingOffDelay_p) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingOffDelay_p = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_LPCDOffDelay(void)
{
  switch (App_Model_DW.is_LPCDOffDelay_i) {
   case App_Model_IN_LPCDOffDelay_Off:
    if (App_Model_DW.sfEvent_i == A_event_StartTimer_LPCDOffDelay) {
      App_Model_DW.is_LPCDOffDelay_i = App_Model_IN_LPCDOffDelay_On;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Runni_f = true;
    }
    break;

   case App_Model_IN_LPCDOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_LPCDOffDelay:
        App_Model_DW.is_LPCDOffDelay_i = App_Model_IN_LPCDOffDelay_Off;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Runni_f = false;
        App_Model_DW.Timer_LPCDOffDelay_m = 0U;
        break;

       case A_event_StartTimer_LPCDOffDelay:
        App_Model_DW.Timer_LPCDOffDelay_m = 0U;
        App_Model_DW.is_LPCDOffDelay_i = App_Model_IN_LPCDOffDelay_On;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Runni_f = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPCDOffDelay_m + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_LPCDOffDelay_m + 1U < App_Model_DW.Timer_LPCDOffDelay_m) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPCDOffDelay_m = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_NFCSearchingTimeout(void)
{
  switch (App_Model_DW.is_NFCSearchingTimeout_e) {
   case App__IN_NFCSearchingTimeout_Off:
    if (App_Model_DW.sfEvent_i == event_StartTimer_NFCSearchingTi) {
      App_Model_DW.is_NFCSearchingTimeout_e = App_M_IN_NFCSearchingTimeout_On;
    }
    break;

   case App_M_IN_NFCSearchingTimeout_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_NFCSearchingT:
        App_Model_DW.is_NFCSearchingTimeout_e = App__IN_NFCSearchingTimeout_Off;
        App_Model_DW.Timer_NFCSearchingTimeout_e = 0U;
        break;

       case event_StartTimer_NFCSearchingTi:
        App_Model_DW.Timer_NFCSearchingTimeout_e = 0U;
        App_Model_DW.is_NFCSearchingTimeout_e = App_M_IN_NFCSearchingTimeout_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingTimeout_e + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_NFCSearchingTimeout_e + 1U < App_Model_DW.Timer_NFCSearchingTimeout_e) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingTimeout_e = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_PICCOffDelay(void)
{
  switch (App_Model_DW.is_PICCOffDelay_c) {
   case App_Model_IN_PICCOffDelay_Off:
    if (App_Model_DW.sfEvent_i == A_event_StartTimer_PICCOffDelay) {
      App_Model_DW.is_PICCOffDelay_c = App_Model_IN_PICCOffDelay_On;
    }
    break;

   case App_Model_IN_PICCOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_PICCOffDelay:
        App_Model_DW.is_PICCOffDelay_c = App_Model_IN_PICCOffDelay_Off;
        App_Model_DW.Timer_PICCOffDelay_m = 0U;
        break;

       case A_event_StartTimer_PICCOffDelay:
        App_Model_DW.Timer_PICCOffDelay_m = 0U;
        App_Model_DW.is_PICCOffDelay_c = App_Model_IN_PICCOffDelay_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCOffDelay_m + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_PICCOffDelay_m + 1U < App_Model_DW.Timer_PICCOffDelay_m) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCOffDelay_m = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void A_exit_atomic_OperationMode_NFC(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_i;
  App_Model_DW.sfEvent_i = event_CancelTimer_NFCTimeOutCon;
  if (App_Model_DW.is_active_NFCTimeOutConfirm_f != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_NFCSearchingO;
  if (App_Model_DW.is_active_NFCSearchingOffDela_c != 0U) {
    App_Model_NFCSearchingOffDelay();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_NFCSearchingT;
  if (App_Model_DW.is_active_NFCSearchingTimeout_b != 0U) {
    App_Model_NFCSearchingTimeout();
  }

  App_Model_DW.sfEvent_i = b_previousEvent;
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_PICCLPCDOffDelay(void)
{
  switch (App_Model_DW.is_PICCLPCDOffDelay_g) {
   case App_Mod_IN_PICCLPCDOffDelay_Off:
    if (App_Model_DW.sfEvent_i == event_StartTimer_PICCLPCDOffDel) {
      App_Model_DW.is_PICCLPCDOffDelay_g = App_Mode_IN_PICCLPCDOffDelay_On;
    }
    break;

   case App_Mode_IN_PICCLPCDOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_PICCLPCDOffDe:
        App_Model_DW.is_PICCLPCDOffDelay_g = App_Mod_IN_PICCLPCDOffDelay_Off;
        App_Model_DW.Timer_PICCLPCDOffDelay_o = 0U;
        break;

       case event_StartTimer_PICCLPCDOffDel:
        App_Model_DW.Timer_PICCLPCDOffDelay_o = 0U;
        App_Model_DW.is_PICCLPCDOffDelay_g = App_Mode_IN_PICCLPCDOffDelay_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCLPCDOffDelay_o + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_PICCLPCDOffDelay_o + 1U < App_Model_DW.Timer_PICCLPCDOffDelay_o) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCLPCDOffDelay_o = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Mo_NFCSearchingOffDetection(void)
{
  if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f != App_Model_DW.Input_IAUWPCNFCcmd_1_start_e) && (App_Model_DW.Input_IAUWPCNFCcmd_1_start_e == WPCNFCDeselect_Stop)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_StartTimer_NFCSearchingOf;
    if (App_Model_DW.is_active_NFCSearchingOffDela_c != 0U) {
      App_Model_NFCSearchingOffDelay();
    }

    App_Model_DW.sfEvent_i = c_previousEvent;
  } else if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f != App_Model_DW.Input_IAUWPCNFCcmd_1_start_e) && (App_Model_DW.Input_IAUWPCNFCcmd_1_start_e == WPCNFCPolling_Search)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_NFCSearchingO;
    if (App_Model_DW.is_active_NFCSearchingOffDela_c != 0U) {
      App_Model_NFCSearchingOffDelay();
    }

    App_Model_DW.sfEvent_i = c_previousEvent;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_NFCDetectionCheck(void)
{
  if (((App_Model_DW.Input_NFCDetection1_prev != App_Model_DW.Input_NFCDetection1_start) && (App_Model_DW.Input_NFCDetection1_start == On)) || ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f !=
        App_Model_DW.Input_IAUWPCNFCcmd_1_start_e) && (App_Model_DW.Input_IAUWPCNFCcmd_1_start_e == WPCNFCPolling_Search))) {
    sint32 b_previousEvent;
    b_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_NFCSearchingT;
    if (App_Model_DW.is_active_NFCSearchingTimeout_b != 0U) {
      App_Model_NFCSearchingTimeout();
    }

    App_Model_DW.sfEvent_i = b_previousEvent;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void enter_atomic_OperationMode_NFC(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_i;
  App_Model_DW.sfEvent_i = event_StartTimer_NFCTimeOutConf;
  if (App_Model_DW.is_active_NFCTimeOutConfirm_f != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_i = event_StartTimer_NFCSearchingTi;
  if (App_Model_DW.is_active_NFCSearchingTimeout_b != 0U) {
    App_Model_NFCSearchingTimeout();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_PICCLPCDOffDe;
  if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
    App_Model_PICCLPCDOffDelay();
  }

  App_Model_DW.sfEvent_i = b_previousEvent;
  App_Mo_NFCSearchingOffDetection();
  App_Model_NFCDetectionCheck();
  App_Model_B.Output_OPT_WPCStatus_m = NFCMode;
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_LPCDOff_Check(Bool rtu_PreProcessIn_a)
{
  if ((rtu_PreProcessIn_a == Off) && (!App_Model_DW.b_Timer_LPCDOffDelay_is_Runni_f)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = A_event_StartTimer_LPCDOffDelay;
    if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
      App_Model_LPCDOffDelay();
    }

    App_Model_DW.sfEvent_i = c_previousEvent;
  } else if (rtu_PreProcessIn_a == On) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_LPCDOffDelay;
    if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
      App_Model_LPCDOffDelay();
    }

    App_Model_DW.sfEvent_i = c_previousEvent;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void enter_atomic_OperationMode_LPCD(Bool rtu_PreProcessIn_a)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_i;
  App_Model_DW.sfEvent_i = event_CancelTimer_NFCTimeOutCon;
  if (App_Model_DW.is_active_NFCTimeOutConfirm_f != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_NFCSearchingO;
  if (App_Model_DW.is_active_NFCSearchingOffDela_c != 0U) {
    App_Model_NFCSearchingOffDelay();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_LPCDOffDelay;
  if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
    App_Model_LPCDOffDelay();
  }

  App_Model_DW.sfEvent_i = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus_m = LPCDMode;
  App_Model_LPCDOff_Check(rtu_PreProcessIn_a);
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void enter_atomic_OperationMode_Picc(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_i;
  App_Model_DW.sfEvent_i = A_event_StartTimer_PICCOffDelay;
  if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
    App_Model_PICCOffDelay();
  }

  App_Model_DW.sfEvent_i = event_StartTimer_PICCLPCDOffDel;
  if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
    App_Model_PICCLPCDOffDelay();
  }

  App_Model_DW.sfEvent_i = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus_m = PICCMode;
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Model_PhnLeftChattering(void)
{
  switch (App_Model_DW.is_PhnLeftChattering_a) {
   case App_Mo_IN_PhnLeftChattering_Off:
    if (App_Model_DW.sfEvent_i == event_StartTimer_PhnLeftChatter) {
      App_Model_DW.is_PhnLeftChattering_a = App_Mod_IN_PhnLeftChattering_On;
      App_Model_DW.b_Timer_PhnLeftChattering_is__o = true;
    }
    break;

   case App_Mod_IN_PhnLeftChattering_On:
    {
      switch (App_Model_DW.sfEvent_i) {
       case event_CancelTimer_PhnLeftChatte:
        App_Model_DW.is_PhnLeftChattering_a = App_Mo_IN_PhnLeftChattering_Off;
        App_Model_DW.b_Timer_PhnLeftChattering_is__o = false;
        App_Model_DW.Timer_PhnLeftChattering_c = 0U;
        break;

       case event_StartTimer_PhnLeftChatter:
        App_Model_DW.Timer_PhnLeftChattering_c = 0U;
        App_Model_DW.is_PhnLeftChattering_a = App_Mod_IN_PhnLeftChattering_On;
        App_Model_DW.b_Timer_PhnLeftChattering_is__o = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PhnLeftChattering_c + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_PhnLeftChattering_c + 1U < App_Model_DW.Timer_PhnLeftChattering_c) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PhnLeftChattering_c = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void App_Mode_DrDoorPhnLeftHoldCheck(Bool rtu_PreProcessIn_a, Bool rtu_PreProcessIn_k, C_WPCWarning rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2)
{
  if (((rtu_PreProcessIn_a == Off) && (rtu_PreProcessIn_n5 == WPCWarningOff) && (rtu_PreProcessIn_i2 == Off) && (((App_Model_DW.Input_b_DrvDrSw_prev_j != App_Model_DW.Input_b_DrvDrSw_start_l) &&
         (App_Model_DW.Input_b_DrvDrSw_start_l == On)) || ((App_Model_DW.Input_b_DrvDrSw_prev_j != App_Model_DW.Input_b_DrvDrSw_start_l) && (App_Model_DW.Input_b_DrvDrSw_start_l == Off)))) ||
      ((App_Model_DW.Timer_PhnLeftChattering_c >= 600U) || ((App_Model_DW.Input_PhnLeftChk_Enable_prev_o != App_Model_DW.Input_PhnLeftChk_Enable_start_m) &&
        (App_Model_DW.Input_PhnLeftChk_Enable_start_m == Off)))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete_b = On;
    d_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_PhnLeftChatte;
    if (App_Model_DW.is_active_PhnLeftChattering_p != 0U) {
      App_Model_PhnLeftChattering();
    }

    App_Model_DW.sfEvent_i = d_previousEvent;
  } else if ((!App_Model_DW.b_Timer_PhnLeftChattering_is__o) && (rtu_PreProcessIn_a == Off) && (rtu_PreProcessIn_n5 == Cellphoneonthepad) && (rtu_PreProcessIn_i2 == On) && (rtu_PreProcessIn_k == On))
  {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete_b = Off;
    d_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_StartTimer_PhnLeftChatter;
    if (App_Model_DW.is_active_PhnLeftChattering_p != 0U) {
      App_Model_PhnLeftChattering();
    }

    App_Model_DW.sfEvent_i = d_previousEvent;
  } else if (rtu_PreProcessIn_a == On) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete_b = Off;
    d_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_PhnLeftChatte;
    if (App_Model_DW.is_active_PhnLeftChattering_p != 0U) {
      App_Model_PhnLeftChattering();
    }

    App_Model_DW.sfEvent_i = d_previousEvent;
  }
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void enter_atomic_OperationMode_Off(Bool rtu_PreProcessIn_a, Bool rtu_PreProcessIn_k, C_WPCWarning rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_i;
  App_Model_DW.sfEvent_i = event_CancelTimer_NFCTimeOutCon;
  if (App_Model_DW.is_active_NFCTimeOutConfirm_f != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_NFCSearchingO;
  if (App_Model_DW.is_active_NFCSearchingOffDela_c != 0U) {
    App_Model_NFCSearchingOffDelay();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_LPCDOffDelay;
  if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
    App_Model_LPCDOffDelay();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_PICCOffDelay;
  if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
    App_Model_PICCOffDelay();
  }

  App_Model_DW.sfEvent_i = event_CancelTimer_PICCLPCDOffDe;
  if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
    App_Model_PICCLPCDOffDelay();
  }

  App_Model_B.Output_OPT_WPCStatus_m = ModeOff;
  App_Model_DW.sfEvent_i = event_CancelTimer_PhnLeftChatte;
  if (App_Model_DW.is_active_PhnLeftChattering_p != 0U) {
    App_Model_PhnLeftChattering();
  }

  App_Model_DW.sfEvent_i = b_previousEvent;
  App_Model_DW.Var_DrDoorPhnLftHoldComplete_b = Off;
  App_Mode_DrDoorPhnLeftHoldCheck(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);
}

/* Function for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
static void WPC_NFC_Mode_Control_Function_S(LC_IAUWPCNFCcmd rtu_PreProcessIn_c, Bool rtu_PreProcessIn_a, IAU_OwnerPhnRegRVal rtu_PreProcessIn_m, OwnerPairingAdvertisingReq rtu_PreProcessIn_i,
  C_WPCOnOffNvalueSet rtu_PreProcessIn_ak, OnThePad rtu_PreProcessIn_e, Bool rtu_PreProcessIn_g, Bool rtu_PreProcessIn_n, WPCStatus rtu_PreProcessIn_hg, Bool rtu_PreProcessIn_k, C_WPCWarning
  rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2, Bool rtu_PreProcessIn_mg)
{
  sint32 i_previousEvent;
  boolean guard1;
  boolean guard2;
  boolean guard3;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  switch (App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b) {
   case App_Model_IN_OperationMode_LPCD:
    {
      C_WPCOnOffNvalueSet tmp;
      App_Model_B.Output_OPT_WPCStatus_m = LPCDMode;

      /* 1 */
      tmp = App_Model_DW.Input_OPT_WPCSWOption_start_i;
      if (((rtu_PreProcessIn_ak == WPC_On) && (rtu_PreProcessIn_a == On) && (rtu_PreProcessIn_c != WPCNFCPolling_Search) && ((rtu_PreProcessIn_m == OwnerPhnReg__Enable) || (rtu_PreProcessIn_i !=
             OwnerPairingAdvertisingReq__StartEnable))) || ((App_Model_DW.Input_OPT_WPCSWOption_prev_k != tmp) && (tmp == WPC_On))) {
        i_previousEvent = App_Model_DW.sfEvent_i;
        App_Model_DW.sfEvent_i = event_CancelTimer_LPCDOffDelay;
        if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
          App_Model_LPCDOffDelay();
        }

        App_Model_DW.sfEvent_i = event_CancelTimer_PICCLPCDOffDe;
        if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
          App_Model_PICCLPCDOffDelay();
        }

        App_Model_DW.sfEvent_i = i_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_WPC;
        App_Model_B.Output_OPT_WPCStatus_m = WPCMode;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 ]%SWOff_Devided */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start_h;
        if ((rtu_PreProcessIn_hg == NFCMode) || ((App_Model_DW.INT_LPCDWakeUpOrder_prev_j != App_Model_DW.INT_LPCDWakeUpOrder_start_i) && (App_Model_DW.INT_LPCDWakeUpOrder_start_i == 2)) ||
            ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev_j != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) || ((rtu_PreProcessIn_a == On) && (rtu_PreProcessIn_i != OwnerPairingAdvertisingReq__StartEnable) &&
             (rtu_PreProcessIn_ak == WPC_Off) && (rtu_PreProcessIn_hg != PICCMode))) {
          /* Prevention of oscillation
             SWOffDevided */
          guard1 = true;
        } else {
          /* 3 */
          /* 4 */
          tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_e;
          if (((App_Model_DW.INT_LPCDWakeUpOrder_prev_j != App_Model_DW.INT_LPCDWakeUpOrder_start_i) && (App_Model_DW.INT_LPCDWakeUpOrder_start_i == 1)) || ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f
                != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) || ((App_Model_DW.Input_b_IGN1_IN_prev_n != App_Model_DW.Input_b_IGN1_IN_start_m) && (App_Model_DW.Input_b_IGN1_IN_start_m == On))) {
            /* SWOffDevided */
            i_previousEvent = App_Model_DW.sfEvent_i;
            App_Model_DW.sfEvent_i = event_CancelTimer_LPCDOffDelay;
            if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
              App_Model_LPCDOffDelay();
            }

            App_Model_DW.sfEvent_i = event_CancelTimer_PICCLPCDOffDe;
            if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
              App_Model_PICCLPCDOffDelay();
            }

            App_Model_DW.sfEvent_i = i_previousEvent;
            App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_NFC;
            enter_atomic_OperationMode_NFC();
          } else {
            WPCStatus tmp_1;

            /* 5 */
            tmp_1 = App_Model_DW.INT_OPT_WPCStatus_2_start;
            if ((rtu_PreProcessIn_a == Off) && ((App_Model_DW.Timer_LPCDOffDelay_m >= 6000U) || (App_Model_DW.Timer_PICCLPCDOffDelay_o >= 6000U) || ((App_Model_DW.INT_OPT_WPCStatus_2_prev != tmp_1) &&
                  (tmp_1 == ModeOff)))) {
              /* Simultaneously */
              guard1 = true;
            } else {
              /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
               *  ActionPort: '<S188>/Action Port'
               */
              /* SwitchCase: '<S181>/Switch Case' incorporates:
               *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
               */
              App_Model_LPCDOff_Check(rtu_PreProcessIn_a);

              /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
            }
          }
        }
      }
    }
    break;

   case App_Model_IN_OperationMode_NFC:
    {
      LC_IAUWPCNFCcmd tmp_0;
      App_Model_B.Output_OPT_WPCStatus_m = NFCMode;

      /* 1 */
      tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_e;
      if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) {
        A_exit_atomic_OperationMode_NFC();
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_NFC;
        enter_atomic_OperationMode_NFC();
      } else {
        /* 2%WPC2Lead, WPC1Follow or WPC2NFCOnly */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start_h;

        /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S188>/Action Port'
         */
        /* SwitchCase: '<S181>/Switch Case' incorporates:
         *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
         */
        if (((rtu_PreProcessIn_hg == NFCMode) && ((App_Model_DW.INT_NFCDetectOrder_prev_i != App_Model_DW.INT_NFCDetectOrder_start_l) && (App_Model_DW.INT_NFCDetectOrder_start_l == 2))) ||
            ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev_j != tmp_0) && (tmp_0 == WPCNFCPolling_Search))) {
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Off;
          App_Model_DW.tp_OperationMode_Off = 1U;
          enter_atomic_OperationMode_Off(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);

          /* 30.5s60s */
        } else if ((rtu_PreProcessIn_a == On) && (rtu_PreProcessIn_ak == WPC_On) && ((App_Model_DW.Timer_NFCSearchingOffDelay_p >= 50U) || (App_Model_DW.Timer_NFCTimeOutConfirm_f >= 6000U) ||
                    (App_Model_DW.Timer_NFCSearchingTimeout_e >= 150U))) {
          /* 1.5 */
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_WPC;
          App_Model_B.Output_OPT_WPCStatus_m = WPCMode;

          /* 4 */
        } else if (((rtu_PreProcessIn_a == Off) && (App_Model_DW.Timer_NFCSearchingOffDelay_p >= 50U)) || ((rtu_PreProcessIn_a == On) && (rtu_PreProcessIn_ak == WPC_Off) &&
                    (App_Model_DW.Timer_NFCSearchingOffDelay_p >= 50U))) {
          /* 0.5s */
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Picc;
          enter_atomic_OperationMode_Picc();

          /* 5 */
          /* 60.5s60s */
        } else if ((App_Model_DW.Timer_NFCSearchingOffDelay_p >= 50U) || (App_Model_DW.Timer_NFCTimeOutConfirm_f >= 6000U) || (App_Model_DW.Timer_NFCSearchingTimeout_e >= 150U)) {
          /* 1.5 */
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_LPCD;
          enter_atomic_OperationMode_LPCD(rtu_PreProcessIn_a);
        } else {
          App_Mo_NFCSearchingOffDetection();
          App_Model_NFCDetectionCheck();
        }

        /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
      }
    }
    break;

   case App_Model_IN_OperationMode_Off:
    {
      WPCStatus tmp_1;
      App_Model_B.Output_OPT_WPCStatus_m = ModeOff;

      /* 1 */
      tmp_1 = App_Model_DW.INT_OPT_WPCStatus_2_prev;

      /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S188>/Action Port'
       */
      /* SwitchCase: '<S181>/Switch Case' incorporates:
       *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
       */
      if (((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && (tmp_1 == NFCMode) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && (App_Model_DW.INT_OPT_WPCStatus_2_start == LPCDMode))) ||
          (((App_Model_DW.Var_DrDoorPhnLftHoldComplete__m != App_Model_DW.Var_DrDoorPhnLftHoldComplete_ml) && (App_Model_DW.Var_DrDoorPhnLftHoldComplete_ml == On)) || ((rtu_PreProcessIn_a == On) &&
            (rtu_PreProcessIn_i == OwnerPairingAdvertisingReq__StartEnable) && (rtu_PreProcessIn_ak == WPC_Off) && (rtu_PreProcessIn_hg == ModeOff)))) {
        /* WPC1ChangeOff2LPCD,WhenWPC2ChangeNFC2LPCD */
        /* BothOffModeStartEnable */
        App_Model_DW.tp_OperationMode_Off = 0U;
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_LPCD;
        enter_atomic_OperationMode_LPCD(rtu_PreProcessIn_a);

        /* 2 */
        /* 3 */
      } else if ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && (App_Model_DW.INT_OPT_WPCStatus_2_start == PICCMode)) {
        App_Model_DW.tp_OperationMode_Off = 0U;
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Picc;
        enter_atomic_OperationMode_Picc();

        /* 4 */
      } else if (rtu_PreProcessIn_c == WPCNFCPolling_Search) {
        App_Model_DW.tp_OperationMode_Off = 0U;
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_NFC;
        enter_atomic_OperationMode_NFC();

        /* 5 */
      } else if ((rtu_PreProcessIn_a == On) && (rtu_PreProcessIn_ak == WPC_On) && (rtu_PreProcessIn_hg != NFCMode)) {
        App_Model_DW.tp_OperationMode_Off = 0U;
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_WPC;
        App_Model_B.Output_OPT_WPCStatus_m = WPCMode;
      } else {
        App_Mode_DrDoorPhnLeftHoldCheck(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);
      }

      /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
    }
    break;

   case App_Model_IN_OperationMode_Picc:
    {
      App_Model_B.Output_OPT_WPCStatus_m = PICCMode;

      /* 1 */
      if (rtu_PreProcessIn_g == On) {
        /* NFC1 & 2 OnThePad_Off */
        /* PhnRemoveMode */
        i_previousEvent = App_Model_DW.sfEvent_i;
        App_Model_DW.sfEvent_i = event_CancelTimer_PICCOffDelay;
        if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
          App_Model_PICCOffDelay();
        }

        App_Model_DW.sfEvent_i = i_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_LPCD;

        /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S188>/Action Port'
         */
        /* SwitchCase: '<S181>/Switch Case' incorporates:
         *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
         */
        enter_atomic_OperationMode_LPCD(rtu_PreProcessIn_a);

        /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */

        /* 2 */
      } else if ((rtu_PreProcessIn_a == Off) && (App_Model_DW.Timer_PICCOffDelay_m >= 6000U)) {
        guard2 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 3 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_e;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) {
          /* PhnRemoveMode */
          i_previousEvent = App_Model_DW.sfEvent_i;
          App_Model_DW.sfEvent_i = event_CancelTimer_PICCOffDelay;
          if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
            App_Model_PICCOffDelay();
          }

          App_Model_DW.sfEvent_i = i_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_NFC;
          enter_atomic_OperationMode_NFC();

          /* 45sec */
        } else if ((rtu_PreProcessIn_a == On) && (rtu_PreProcessIn_ak == WPC_On) && ((rtu_PreProcessIn_e == OnThePad_On) || ((rtu_PreProcessIn_e == OnThePad_Default) &&
                     (App_Model_DW.Timer_PICCOffDelay_m >= 500U)) || (rtu_PreProcessIn_hg == WPCMode))) {
          /* TransitionMerge */
          /* PhnRemoveMode */
          i_previousEvent = App_Model_DW.sfEvent_i;
          App_Model_DW.sfEvent_i = event_CancelTimer_PICCOffDelay;
          if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
            App_Model_PICCOffDelay();
          }

          App_Model_DW.sfEvent_i = i_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_WPC;
          App_Model_B.Output_OPT_WPCStatus_m = WPCMode;
        } else {
          WPCStatus tmp_1;

          /* 5Simultenously ModeOff */
          tmp_1 = App_Model_DW.INT_OPT_WPCStatus_2_prev;
          if (((rtu_PreProcessIn_a == Off) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && (App_Model_DW.INT_OPT_WPCStatus_2_start == ModeOff))) || ((tmp_1 !=
                App_Model_DW.INT_OPT_WPCStatus_2_start) && (App_Model_DW.INT_OPT_WPCStatus_2_start == NFCMode)) || ((rtu_PreProcessIn_ak == WPC_Off) && ((rtu_PreProcessIn_hg == WPCMode) ||
                (App_Model_DW.Timer_PICCOffDelay_m >= 6000U)))) {
            /* WPCSWOffALL_Case */
            guard2 = true;
          } else {
            /* 6%WPCSWOption_Off Case */
          }
        }
      }
    }
    break;

   case App_Model_IN_OperationMode_WPC:
    {
      App_Model_B.Output_OPT_WPCStatus_m = WPCMode;

      /* 1 */
      if (rtu_PreProcessIn_hg == LPCDMode) {
        /* WhileWPC2isSWOff, WPC2MoveFromOFFtoLPCD */
        guard3 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_e;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f != tmp_0) && (tmp_0 == WPCNFCPolling_Search) && (rtu_PreProcessIn_hg != NFCMode)) {
          /* WaitingforNFCCom */
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_NFC;
          enter_atomic_OperationMode_NFC();

          /* 3%When WPC1&2 are Both ChargingOnThePad_Off || ObjectOnthePad_Off */
        } else if (((rtu_PreProcessIn_n == On) || (rtu_PreProcessIn_mg == On)) && ((rtu_PreProcessIn_m == OwnerPhnReg__Disable) || (rtu_PreProcessIn_m == OwnerPhnReg__Default) || (rtu_PreProcessIn_m ==
          OwnerPhnReg__Invalid)) && (rtu_PreProcessIn_i == OwnerPairingAdvertisingReq__StartEnable)) {
          App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Picc;
          enter_atomic_OperationMode_Picc();

          /* 4 */
        } else if ((rtu_PreProcessIn_a == Off) || (rtu_PreProcessIn_ak == WPC_Off) || (rtu_PreProcessIn_hg == NFCMode)) {
          /* PollingSearchDivided */
          guard3 = true;
        }
      }
    }
    break;
  }

  if (guard3) {
    App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Off;
    App_Model_DW.tp_OperationMode_Off = 1U;

    /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    /* SwitchCase: '<S181>/Switch Case' incorporates:
     *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
     */
    enter_atomic_OperationMode_Off(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);

    /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
  }

  if (guard2) {
    /* PhnRemoveMode */
    i_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_PICCOffDelay;
    if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
      App_Model_PICCOffDelay();
    }

    App_Model_DW.sfEvent_i = i_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Off;
    App_Model_DW.tp_OperationMode_Off = 1U;

    /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    /* SwitchCase: '<S181>/Switch Case' incorporates:
     *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
     */
    enter_atomic_OperationMode_Off(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);

    /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
  }

  if (guard1) {
    i_previousEvent = App_Model_DW.sfEvent_i;
    App_Model_DW.sfEvent_i = event_CancelTimer_LPCDOffDelay;
    if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
      App_Model_LPCDOffDelay();
    }

    App_Model_DW.sfEvent_i = event_CancelTimer_PICCLPCDOffDe;
    if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
      App_Model_PICCLPCDOffDelay();
    }

    App_Model_DW.sfEvent_i = i_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Off;
    App_Model_DW.tp_OperationMode_Off = 1U;

    /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S188>/Action Port'
     */
    /* SwitchCase: '<S181>/Switch Case' incorporates:
     *  Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9'
     */
    enter_atomic_OperationMode_Off(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);

    /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
  }
}

/* System initialize for atomic system: '<S18>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Funct_Init(WPCStatus *rty_WPCStatus)
{
  /* SystemInitialize for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' */
  /* SystemInitialize for Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
  App_Model_DW.sfEvent_i = App_Model_CALL_EVENT_l;
  App_Model_DW.Input_OPT_WPCSWOption_prev_k = WPC_On;
  App_Model_DW.Input_OPT_WPCSWOption_start_i = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S181>/WPC_NFCModeControl_compact' */

  /* SystemInitialize for Merge: '<S181>/Merge' */
  *rty_WPCStatus = ModeOff;
}

/* Output and update for atomic system: '<S18>/NFC_WPC_Mode_Control_Function' */
void A_NFC_WPC_Mode_Control_Function(Bool rtu_PreProcessIn, LC_IAUWPCNFCcmd rtu_PreProcessIn_c, LC_IAUWPCNFCcmd rtu_PreProcessIn_p, Bool rtu_PreProcessIn_a, IAU_OwnerPhnRegRVal rtu_PreProcessIn_m,
  OwnerPairingAdvertisingReq rtu_PreProcessIn_i, C_WPCOnOffNvalueSet rtu_PreProcessIn_ak, OnThePad rtu_PreProcessIn_e, LC_WPC_NFCDetection rtu_PreProcessIn_h, Bool rtu_PreProcessIn_g, Bool
  rtu_PreProcessIn_n, WPCStatus rtu_PreProcessIn_hg, uint8 rtu_PreProcessIn_go, uint8 rtu_PreProcessIn_mc, Bool rtu_PreProcessIn_k, C_WPCWarning rtu_PreProcessIn_n5, Bool rtu_PreProcessIn_i2, Bool
  rtu_PreProcessIn_mg, Bool rtu_PreProcessIn_d, WPCStatus *rty_WPCStatus)
{
  /* SwitchCase: '<S181>/Switch Case' */
  switch (rtu_PreProcessIn) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S181>/WPC_Mode_Control' incorporates:
     *  ActionPort: '<S187>/Action Port'
     */
    App_Model_WPC_Mode_Control(rtu_PreProcessIn_a, rtu_PreProcessIn_ak, rtu_PreProcessIn_d, rty_WPCStatus, &App_Model_DW.WPC_Mode_Control);

    /* End of Outputs for SubSystem: '<S181>/WPC_Mode_Control' */
    break;

   case On:
    {
      /* Outputs for IfAction SubSystem: '<S181>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S188>/Action Port'
       */
      /* Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */
      App_Model_DW.sfEvent_i = App_Model_CALL_EVENT_l;
      App_Model_DW.Input_NFCDetection1_prev = App_Model_DW.Input_NFCDetection1_start;
      App_Model_DW.Input_NFCDetection1_start = rtu_PreProcessIn_h;
      App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f = App_Model_DW.Input_IAUWPCNFCcmd_1_start_e;
      App_Model_DW.Input_IAUWPCNFCcmd_1_start_e = rtu_PreProcessIn_c;
      App_Model_DW.Input_b_DrvDrSw_prev_j = App_Model_DW.Input_b_DrvDrSw_start_l;
      App_Model_DW.Input_b_DrvDrSw_start_l = rtu_PreProcessIn_k;
      App_Model_DW.Input_PhnLeftChk_Enable_prev_o = App_Model_DW.Input_PhnLeftChk_Enable_start_m;
      App_Model_DW.Input_PhnLeftChk_Enable_start_m = rtu_PreProcessIn_i2;
      App_Model_DW.INT_OPT_WPCStatus_2_prev = App_Model_DW.INT_OPT_WPCStatus_2_start;
      App_Model_DW.INT_OPT_WPCStatus_2_start = rtu_PreProcessIn_hg;
      App_Model_DW.Var_DrDoorPhnLftHoldComplete__m = App_Model_DW.Var_DrDoorPhnLftHoldComplete_ml;
      App_Model_DW.Var_DrDoorPhnLftHoldComplete_ml = App_Model_DW.Var_DrDoorPhnLftHoldComplete_b;
      App_Model_DW.INT_LPCDWakeUpOrder_prev_j = App_Model_DW.INT_LPCDWakeUpOrder_start_i;
      App_Model_DW.INT_LPCDWakeUpOrder_start_i = rtu_PreProcessIn_go;
      App_Model_DW.Input_IAUWPCNFCcmd_2_prev_j = App_Model_DW.Input_IAUWPCNFCcmd_2_start_h;
      App_Model_DW.Input_IAUWPCNFCcmd_2_start_h = rtu_PreProcessIn_p;
      App_Model_DW.Input_b_IGN1_IN_prev_n = App_Model_DW.Input_b_IGN1_IN_start_m;
      App_Model_DW.Input_b_IGN1_IN_start_m = rtu_PreProcessIn_a;
      App_Model_DW.Input_OPT_WPCSWOption_prev_k = App_Model_DW.Input_OPT_WPCSWOption_start_i;
      App_Model_DW.Input_OPT_WPCSWOption_start_i = rtu_PreProcessIn_ak;
      App_Model_DW.INT_NFCDetectOrder_prev_i = App_Model_DW.INT_NFCDetectOrder_start_l;
      App_Model_DW.INT_NFCDetectOrder_start_l = rtu_PreProcessIn_mc;
      if (App_Model_DW.is_active_c40_NFC_WPC_Mode_Cont == 0U) {
        App_Model_DW.Input_NFCDetection1_prev = rtu_PreProcessIn_h;
        App_Model_DW.Input_IAUWPCNFCcmd_1_prev_f = rtu_PreProcessIn_c;
        App_Model_DW.Input_b_DrvDrSw_prev_j = rtu_PreProcessIn_k;
        App_Model_DW.Input_PhnLeftChk_Enable_prev_o = rtu_PreProcessIn_i2;
        App_Model_DW.INT_OPT_WPCStatus_2_prev = rtu_PreProcessIn_hg;
        App_Model_DW.INT_LPCDWakeUpOrder_prev_j = rtu_PreProcessIn_go;
        App_Model_DW.Input_IAUWPCNFCcmd_2_prev_j = rtu_PreProcessIn_p;
        App_Model_DW.Input_b_IGN1_IN_prev_n = rtu_PreProcessIn_a;
        App_Model_DW.Input_OPT_WPCSWOption_prev_k = rtu_PreProcessIn_ak;
        App_Model_DW.INT_NFCDetectOrder_prev_i = rtu_PreProcessIn_mc;
        App_Model_DW.is_active_c40_NFC_WPC_Mode_Cont = 1U;
        App_Model_DW.is_active_NFCTimeOutConfirm_f = 1U;
        App_Model_DW.is_NFCTimeOutConfirm_a = App_Mo_IN_NFCTimeOutConfirm_Off;
        App_Model_DW.Timer_NFCTimeOutConfirm_f = 0U;
        App_Model_DW.is_active_NFCSearchingOffDela_c = 1U;
        App_Model_DW.is_NFCSearchingOffDelay_c = App_IN_NFCSearchingOffDelay_Off;
        App_Model_DW.Timer_NFCSearchingOffDelay_p = 0U;
        App_Model_DW.is_active_DeviceStateWait_k = 1U;
        App_Model_DW.is_DeviceStateWait_c = App_Mode_IN_DeviceStateWait_Off;
        App_Model_DW.Timer_DeviceStateWait_f = 0U;
        App_Model_DW.is_active_LPCDOffDelay_j = 1U;
        App_Model_DW.is_LPCDOffDelay_i = App_Model_IN_LPCDOffDelay_Off;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Runni_f = false;
        App_Model_DW.Timer_LPCDOffDelay_m = 0U;
        App_Model_DW.is_active_NFCSearchingTimeout_b = 1U;
        App_Model_DW.is_NFCSearchingTimeout_e = App__IN_NFCSearchingTimeout_Off;
        App_Model_DW.Timer_NFCSearchingTimeout_e = 0U;
        App_Model_DW.is_active_PhnLeftHolding_m = 1U;
        App_Model_DW.is_PhnLeftHolding_f = App_Model_IN_PhnLeftHolding_Off;
        App_Model_DW.Timer_PhnLeftHolding_a = 0U;
        App_Model_DW.is_active_PICCOffDelay_k = 1U;
        App_Model_DW.is_PICCOffDelay_c = App_Model_IN_PICCOffDelay_Off;
        App_Model_DW.Timer_PICCOffDelay_m = 0U;
        App_Model_DW.is_active_WPC_NFC_Mode_Contro_j = 1U;

        /* Default */
        App_Model_DW.is_WPC_NFC_Mode_Control_Funct_b = App_Model_IN_OperationMode_Off;
        App_Model_DW.tp_OperationMode_Off = 1U;
        enter_atomic_OperationMode_Off(rtu_PreProcessIn_a, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2);
        App_Model_DW.is_active_PICCLPCDOffDelay_m = 1U;
        App_Model_DW.is_PICCLPCDOffDelay_g = App_Mod_IN_PICCLPCDOffDelay_Off;
        App_Model_DW.Timer_PICCLPCDOffDelay_o = 0U;
        App_Model_DW.is_active_PhnLeftChattering_p = 1U;
        App_Model_DW.is_PhnLeftChattering_a = App_Mo_IN_PhnLeftChattering_Off;
        App_Model_DW.b_Timer_PhnLeftChattering_is__o = false;
        App_Model_DW.Timer_PhnLeftChattering_c = 0U;
      } else {
        uint32 qY;
        if (App_Model_DW.is_active_NFCTimeOutConfirm_f != 0U) {
          App_Model_NFCTimeOutConfirm();
        }

        if (App_Model_DW.is_active_NFCSearchingOffDela_c != 0U) {
          App_Model_NFCSearchingOffDelay();
        }

        if (App_Model_DW.is_active_DeviceStateWait_k != 0U) {
          switch (App_Model_DW.is_DeviceStateWait_c) {
           case App_Mode_IN_DeviceStateWait_Off:
            break;

           case App_Model_IN_DeviceStateWait_On:
            qY = App_Model_DW.Timer_DeviceStateWait_f + /*MW:OvSatOk*/ 1U;
            if (App_Model_DW.Timer_DeviceStateWait_f + 1U < App_Model_DW.Timer_DeviceStateWait_f) {
              qY = MAX_uint32_T;
            }

            App_Model_DW.Timer_DeviceStateWait_f = qY;
            break;
          }
        }

        if (App_Model_DW.is_active_LPCDOffDelay_j != 0U) {
          App_Model_LPCDOffDelay();
        }

        if (App_Model_DW.is_active_NFCSearchingTimeout_b != 0U) {
          App_Model_NFCSearchingTimeout();
        }

        if (App_Model_DW.is_active_PhnLeftHolding_m != 0U) {
          switch (App_Model_DW.is_PhnLeftHolding_f) {
           case App_Model_IN_PhnLeftHolding_Off:
            break;

           case App_Model_IN_PhnLeftHolding_On:
            qY = App_Model_DW.Timer_PhnLeftHolding_a + /*MW:OvSatOk*/ 1U;
            if (App_Model_DW.Timer_PhnLeftHolding_a + 1U < App_Model_DW.Timer_PhnLeftHolding_a) {
              qY = MAX_uint32_T;
            }

            App_Model_DW.Timer_PhnLeftHolding_a = qY;
            break;
          }
        }

        if (App_Model_DW.is_active_PICCOffDelay_k != 0U) {
          App_Model_PICCOffDelay();
        }

        if (App_Model_DW.is_active_WPC_NFC_Mode_Contro_j != 0U) {
          WPC_NFC_Mode_Control_Function_S(rtu_PreProcessIn_c, rtu_PreProcessIn_a, rtu_PreProcessIn_m, rtu_PreProcessIn_i, rtu_PreProcessIn_ak, rtu_PreProcessIn_e, rtu_PreProcessIn_g,
            rtu_PreProcessIn_n, rtu_PreProcessIn_hg, rtu_PreProcessIn_k, rtu_PreProcessIn_n5, rtu_PreProcessIn_i2, rtu_PreProcessIn_mg);
        }

        if (App_Model_DW.is_active_PICCLPCDOffDelay_m != 0U) {
          App_Model_PICCLPCDOffDelay();
        }

        if (App_Model_DW.is_active_PhnLeftChattering_p != 0U) {
          App_Model_PhnLeftChattering();
        }
      }

      /* End of Chart: '<S188>/NFC_WPC_Mode_Control_MPPEPP_1_r9' */

      /* SignalConversion: '<S188>/Signal Conversion1' */
      *rty_WPCStatus = App_Model_B.Output_OPT_WPCStatus_m;

      /* End of Outputs for SubSystem: '<S181>/WPC_NFCModeControl_compact' */
    }
    break;
  }

  /* End of SwitchCase: '<S181>/Switch Case' */
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_NFCTimeOutConfirm_e(void)
{
  switch (App_Model_DW.is_NFCTimeOutConfirm) {
   case App__IN_NFCTimeOutConfirm_Off_j:
    if (App_Model_DW.sfEvent_o == event_StartTimer_NFCTimeOutCo_l) {
      App_Model_DW.is_NFCTimeOutConfirm = App_M_IN_NFCTimeOutConfirm_On_f;
    }
    break;

   case App_M_IN_NFCTimeOutConfirm_On_f:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_NFCTimeOutC_b:
        App_Model_DW.is_NFCTimeOutConfirm = App__IN_NFCTimeOutConfirm_Off_j;
        App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
        break;

       case event_StartTimer_NFCTimeOutCo_l:
        App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
        App_Model_DW.is_NFCTimeOutConfirm = App_M_IN_NFCTimeOutConfirm_On_f;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCTimeOutConfirm + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_NFCTimeOutConfirm + 1U < App_Model_DW.Timer_NFCTimeOutConfirm) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCTimeOutConfirm = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Mode_NFCSearchingOffDelay_g(void)
{
  switch (App_Model_DW.is_NFCSearchingOffDelay) {
   case A_IN_NFCSearchingOffDelay_Off_f:
    if (App_Model_DW.sfEvent_o == event_StartTimer_NFCSearching_c) {
      App_Model_DW.is_NFCSearchingOffDelay = Ap_IN_NFCSearchingOffDelay_On_b;
    }
    break;

   case Ap_IN_NFCSearchingOffDelay_On_b:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_NFCSearchin_i:
        App_Model_DW.is_NFCSearchingOffDelay = A_IN_NFCSearchingOffDelay_Off_f;
        App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
        break;

       case event_StartTimer_NFCSearching_c:
        App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
        App_Model_DW.is_NFCSearchingOffDelay = Ap_IN_NFCSearchingOffDelay_On_b;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingOffDelay + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_NFCSearchingOffDelay + 1U < App_Model_DW.Timer_NFCSearchingOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingOffDelay = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_LPCDOffDelay_h(void)
{
  switch (App_Model_DW.is_LPCDOffDelay) {
   case App_Model_IN_LPCDOffDelay_Off_f:
    if (App_Model_DW.sfEvent_o == event_StartTimer_LPCDOffDelay_a) {
      App_Model_DW.is_LPCDOffDelay = App_Model_IN_LPCDOffDelay_On_m;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Running = true;
    }
    break;

   case App_Model_IN_LPCDOffDelay_On_m:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_LPCDOffDela_e:
        App_Model_DW.is_LPCDOffDelay = App_Model_IN_LPCDOffDelay_Off_f;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Running = false;
        App_Model_DW.Timer_LPCDOffDelay = 0U;
        break;

       case event_StartTimer_LPCDOffDelay_a:
        App_Model_DW.Timer_LPCDOffDelay = 0U;
        App_Model_DW.is_LPCDOffDelay = App_Model_IN_LPCDOffDelay_On_m;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Running = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPCDOffDelay + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_LPCDOffDelay + 1U < App_Model_DW.Timer_LPCDOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPCDOffDelay = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_NFCSearchingTimeout_i(void)
{
  switch (App_Model_DW.is_NFCSearchingTimeout) {
   case Ap_IN_NFCSearchingTimeout_Off_f:
    if (App_Model_DW.sfEvent_o == event_StartTimer_NFCSearching_f) {
      App_Model_DW.is_NFCSearchingTimeout = App_IN_NFCSearchingTimeout_On_g;
    }
    break;

   case App_IN_NFCSearchingTimeout_On_g:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_NFCSearchin_j:
        App_Model_DW.is_NFCSearchingTimeout = Ap_IN_NFCSearchingTimeout_Off_f;
        App_Model_DW.Timer_NFCSearchingTimeout = 0U;
        break;

       case event_StartTimer_NFCSearching_f:
        App_Model_DW.Timer_NFCSearchingTimeout = 0U;
        App_Model_DW.is_NFCSearchingTimeout = App_IN_NFCSearchingTimeout_On_g;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingTimeout + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_NFCSearchingTimeout + 1U < App_Model_DW.Timer_NFCSearchingTimeout) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingTimeout = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_PICCOffDelay_l(void)
{
  switch (App_Model_DW.is_PICCOffDelay) {
   case App_Model_IN_PICCOffDelay_Off_o:
    if (App_Model_DW.sfEvent_o == event_StartTimer_PICCOffDelay_h) {
      App_Model_DW.is_PICCOffDelay = App_Model_IN_PICCOffDelay_On_n;
    }
    break;

   case App_Model_IN_PICCOffDelay_On_n:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_PICCOffDela_g:
        App_Model_DW.is_PICCOffDelay = App_Model_IN_PICCOffDelay_Off_o;
        App_Model_DW.Timer_PICCOffDelay = 0U;
        break;

       case event_StartTimer_PICCOffDelay_h:
        App_Model_DW.Timer_PICCOffDelay = 0U;
        App_Model_DW.is_PICCOffDelay = App_Model_IN_PICCOffDelay_On_n;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCOffDelay + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_PICCOffDelay + 1U < App_Model_DW.Timer_PICCOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCOffDelay = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void exit_atomic_OperationMode_NFC_o(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_o;
  App_Model_DW.sfEvent_o = event_CancelTimer_NFCTimeOutC_b;
  if (App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Model_NFCTimeOutConfirm_e();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_NFCSearchin_i;
  if (App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
    App_Mode_NFCSearchingOffDelay_g();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_NFCSearchin_j;
  if (App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
    App_Model_NFCSearchingTimeout_i();
  }

  App_Model_DW.sfEvent_o = b_previousEvent;
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_PICCLPCDOffDelay_d(void)
{
  switch (App_Model_DW.is_PICCLPCDOffDelay) {
   case App_M_IN_PICCLPCDOffDelay_Off_b:
    if (App_Model_DW.sfEvent_o == event_StartTimer_PICCLPCDOffD_n) {
      App_Model_DW.is_PICCLPCDOffDelay = App_Mo_IN_PICCLPCDOffDelay_On_b;
    }
    break;

   case App_Mo_IN_PICCLPCDOffDelay_On_b:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_PICCLPCDOff_n:
        App_Model_DW.is_PICCLPCDOffDelay = App_M_IN_PICCLPCDOffDelay_Off_b;
        App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
        break;

       case event_StartTimer_PICCLPCDOffD_n:
        App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
        App_Model_DW.is_PICCLPCDOffDelay = App_Mo_IN_PICCLPCDOffDelay_On_b;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCLPCDOffDelay + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_PICCLPCDOffDelay + 1U < App_Model_DW.Timer_PICCLPCDOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCLPCDOffDelay = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App__NFCSearchingOffDetection_a(void)
{
  if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != App_Model_DW.Input_IAUWPCNFCcmd_2_start) && (App_Model_DW.Input_IAUWPCNFCcmd_2_start == WPCNFCDeselect_Stop)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_StartTimer_NFCSearching_c;
    if (App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
      App_Mode_NFCSearchingOffDelay_g();
    }

    App_Model_DW.sfEvent_o = c_previousEvent;
  } else if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != App_Model_DW.Input_IAUWPCNFCcmd_2_start) && (App_Model_DW.Input_IAUWPCNFCcmd_2_start == WPCNFCPolling_Search)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_NFCSearchin_i;
    if (App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
      App_Mode_NFCSearchingOffDelay_g();
    }

    App_Model_DW.sfEvent_o = c_previousEvent;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_NFCDetectionCheck_g(void)
{
  if (((App_Model_DW.Input_NFCDetection2_prev != App_Model_DW.Input_NFCDetection2_start) && (App_Model_DW.Input_NFCDetection2_start == On)) || ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev !=
        App_Model_DW.Input_IAUWPCNFCcmd_2_start) && (App_Model_DW.Input_IAUWPCNFCcmd_2_start == WPCNFCPolling_Search))) {
    sint32 b_previousEvent;
    b_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_NFCSearchin_j;
    if (App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
      App_Model_NFCSearchingTimeout_i();
    }

    App_Model_DW.sfEvent_o = b_previousEvent;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void enter_atomic_OperationMode_NF_m(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_o;
  App_Model_DW.sfEvent_o = event_StartTimer_NFCTimeOutCo_l;
  if (App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Model_NFCTimeOutConfirm_e();
  }

  App_Model_DW.sfEvent_o = event_StartTimer_NFCSearching_f;
  if (App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
    App_Model_NFCSearchingTimeout_i();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_PICCLPCDOff_n;
  if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
    App_Model_PICCLPCDOffDelay_d();
  }

  App_Model_DW.sfEvent_o = b_previousEvent;
  App__NFCSearchingOffDetection_a();
  App_Model_NFCDetectionCheck_g();
  App_Model_B.Output_OPT_WPCStatus = NFCMode;
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void enter_atomic_OperationMode_Pi_h(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_o;
  App_Model_DW.sfEvent_o = event_StartTimer_PICCOffDelay_h;
  if (App_Model_DW.is_active_PICCOffDelay != 0U) {
    App_Model_PICCOffDelay_l();
  }

  App_Model_DW.sfEvent_o = event_StartTimer_PICCLPCDOffD_n;
  if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
    App_Model_PICCLPCDOffDelay_d();
  }

  App_Model_DW.sfEvent_o = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus = PICCMode;
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_LPCDOff_Check_o(Bool rtu_PreProcessIn_c)
{
  if ((rtu_PreProcessIn_c == Off) && (!App_Model_DW.b_Timer_LPCDOffDelay_is_Running)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_StartTimer_LPCDOffDelay_a;
    if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
      App_Model_LPCDOffDelay_h();
    }

    App_Model_DW.sfEvent_o = c_previousEvent;
  } else if (rtu_PreProcessIn_c == On) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_LPCDOffDela_e;
    if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
      App_Model_LPCDOffDelay_h();
    }

    App_Model_DW.sfEvent_o = c_previousEvent;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void enter_atomic_OperationMode_LP_l(Bool rtu_PreProcessIn_c)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_o;
  App_Model_DW.sfEvent_o = event_CancelTimer_NFCTimeOutC_b;
  if (App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Model_NFCTimeOutConfirm_e();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_NFCSearchin_i;
  if (App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
    App_Mode_NFCSearchingOffDelay_g();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_LPCDOffDela_e;
  if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
    App_Model_LPCDOffDelay_h();
  }

  App_Model_DW.sfEvent_o = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus = LPCDMode;
  App_Model_LPCDOff_Check_o(rtu_PreProcessIn_c);
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Model_PhnLeftChattering_i(void)
{
  switch (App_Model_DW.is_PhnLeftChattering) {
   case App__IN_PhnLeftChattering_Off_d:
    if (App_Model_DW.sfEvent_o == event_StartTimer_PhnLeftChatt_k) {
      App_Model_DW.is_PhnLeftChattering = App_M_IN_PhnLeftChattering_On_m;
      App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = true;
    }
    break;

   case App_M_IN_PhnLeftChattering_On_m:
    {
      switch (App_Model_DW.sfEvent_o) {
       case event_CancelTimer_PhnLeftChat_a:
        App_Model_DW.is_PhnLeftChattering = App__IN_PhnLeftChattering_Off_d;
        App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = false;
        App_Model_DW.Timer_PhnLeftChattering = 0U;
        break;

       case event_StartTimer_PhnLeftChatt_k:
        App_Model_DW.Timer_PhnLeftChattering = 0U;
        App_Model_DW.is_PhnLeftChattering = App_M_IN_PhnLeftChattering_On_m;
        App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PhnLeftChattering + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_PhnLeftChattering + 1U < App_Model_DW.Timer_PhnLeftChattering) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PhnLeftChattering = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void App_Mo_DrDoorPhnLeftHoldCheck_k(Bool rtu_PreProcessIn_c, Bool rtu_PreProcessIn_h, C_WPCWarning rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d)
{
  if (((rtu_PreProcessIn_c == Off) && (rtu_PreProcessIn_ai == WPCWarningOff) && (rtu_PreProcessIn_d == Off) && (((App_Model_DW.Input_b_DrvDrSw_prev != App_Model_DW.Input_b_DrvDrSw_start) &&
         (App_Model_DW.Input_b_DrvDrSw_start == On)) || ((App_Model_DW.Input_b_DrvDrSw_prev != App_Model_DW.Input_b_DrvDrSw_start) && (App_Model_DW.Input_b_DrvDrSw_start == Off)))) ||
      ((App_Model_DW.Timer_PhnLeftChattering >= 600U) || ((App_Model_DW.Input_PhnLeftChk_Enable_prev != App_Model_DW.Input_PhnLeftChk_Enable_start) && (App_Model_DW.Input_PhnLeftChk_Enable_start ==
         Off)))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete = On;
    d_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_PhnLeftChat_a;
    if (App_Model_DW.is_active_PhnLeftChattering != 0U) {
      App_Model_PhnLeftChattering_i();
    }

    App_Model_DW.sfEvent_o = d_previousEvent;
  } else if ((!App_Model_DW.b_Timer_PhnLeftChattering_is_Ru) && (rtu_PreProcessIn_c == Off) && (rtu_PreProcessIn_ai == Cellphoneonthepad) && (rtu_PreProcessIn_d == On) && (rtu_PreProcessIn_h == On)) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete = Off;
    d_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_StartTimer_PhnLeftChatt_k;
    if (App_Model_DW.is_active_PhnLeftChattering != 0U) {
      App_Model_PhnLeftChattering_i();
    }

    App_Model_DW.sfEvent_o = d_previousEvent;
  } else if (rtu_PreProcessIn_c == On) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete = Off;
    d_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_PhnLeftChat_a;
    if (App_Model_DW.is_active_PhnLeftChattering != 0U) {
      App_Model_PhnLeftChattering_i();
    }

    App_Model_DW.sfEvent_o = d_previousEvent;
  }
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void enter_atomic_OperationMode_Of_b(Bool rtu_PreProcessIn_c, Bool rtu_PreProcessIn_h, C_WPCWarning rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_o;
  App_Model_DW.sfEvent_o = event_CancelTimer_NFCTimeOutC_b;
  if (App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Model_NFCTimeOutConfirm_e();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_NFCSearchin_i;
  if (App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
    App_Mode_NFCSearchingOffDelay_g();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_LPCDOffDela_e;
  if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
    App_Model_LPCDOffDelay_h();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_PICCOffDela_g;
  if (App_Model_DW.is_active_PICCOffDelay != 0U) {
    App_Model_PICCOffDelay_l();
  }

  App_Model_DW.sfEvent_o = event_CancelTimer_PICCLPCDOff_n;
  if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
    App_Model_PICCLPCDOffDelay_d();
  }

  App_Model_B.Output_OPT_WPCStatus = ModeOff;

  /* OffLPCD_Check();%OffToLPCDforFollow */
  App_Model_DW.sfEvent_o = event_CancelTimer_PhnLeftChat_a;
  if (App_Model_DW.is_active_PhnLeftChattering != 0U) {
    App_Model_PhnLeftChattering_i();
  }

  App_Model_DW.sfEvent_o = b_previousEvent;
  App_Model_DW.Var_DrDoorPhnLftHoldComplete = Off;
  App_Mo_DrDoorPhnLeftHoldCheck_k(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);
}

/* Function for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
static void WPC_NFC_Mode_Control_Function_j(Bool rtu_PreProcessIn_c, LC_IAUWPCNFCcmd rtu_PreProcessIn_e, C_WPCOnOffNvalueSet rtu_PreProcessIn_m, IAU_OwnerPhnRegRVal rtu_PreProcessIn_j,
  OwnerPairingAdvertisingReq rtu_PreProcessIn_l, OnThePad rtu_PreProcessIn_b, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_mb, WPCStatus rtu_PreProcessIn_a, Bool rtu_PreProcessIn_h, C_WPCWarning
  rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d, Bool rtu_PreProcessIn_jq)
{
  sint32 i_previousEvent;
  boolean guard1;
  boolean guard2;
  boolean guard3;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  switch (App_Model_DW.is_WPC_NFC_Mode_Control_Functio) {
   case App_Mod_IN_OperationMode_LPCD_c:
    {
      C_WPCOnOffNvalueSet tmp;
      App_Model_B.Output_OPT_WPCStatus = LPCDMode;

      /* 1 */
      tmp = App_Model_DW.Input_OPT_WPCSWOption_start;
      if (((rtu_PreProcessIn_m == WPC_On) && (rtu_PreProcessIn_c == On) && (rtu_PreProcessIn_e != WPCNFCPolling_Search) && ((rtu_PreProcessIn_j == OwnerPhnReg__Enable) || (rtu_PreProcessIn_l !=
             OwnerPairingAdvertisingReq__StartEnable))) || ((App_Model_DW.Input_OPT_WPCSWOption_prev != tmp) && (tmp == WPC_On))) {
        i_previousEvent = App_Model_DW.sfEvent_o;
        App_Model_DW.sfEvent_o = event_CancelTimer_LPCDOffDela_e;
        if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
          App_Model_LPCDOffDelay_h();
        }

        App_Model_DW.sfEvent_o = event_CancelTimer_PICCLPCDOff_n;
        if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
          App_Model_PICCLPCDOffDelay_d();
        }

        App_Model_DW.sfEvent_o = i_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_WPC_i;
        App_Model_B.Output_OPT_WPCStatus = WPCMode;

        /* Output_WPC_NFCDetection = NFCDetection_Off; */
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 SWOff_Devided */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start;
        if ((rtu_PreProcessIn_a == NFCMode) || ((App_Model_DW.INT_LPCDWakeUpOrder_prev != App_Model_DW.INT_LPCDWakeUpOrder_start) && (App_Model_DW.INT_LPCDWakeUpOrder_start == 1)) ||
            ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) || ((rtu_PreProcessIn_c == On) && (rtu_PreProcessIn_l != OwnerPairingAdvertisingReq__StartEnable) &&
             (rtu_PreProcessIn_m == WPC_Off) && (rtu_PreProcessIn_a != PICCMode))) {
          /* Prevention of oscillation
             SWOffDevided */
          guard1 = true;
        } else {
          /* 3 */
          /* 4 */
          tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
          if (((App_Model_DW.INT_LPCDWakeUpOrder_prev != App_Model_DW.INT_LPCDWakeUpOrder_start) && (App_Model_DW.INT_LPCDWakeUpOrder_start == 2)) || ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0)
               && (tmp_0 == WPCNFCPolling_Search)) || ((App_Model_DW.Input_b_IGN1_IN_prev != App_Model_DW.Input_b_IGN1_IN_start) && (App_Model_DW.Input_b_IGN1_IN_start == On))) {
            /* SWOffDevided */
            i_previousEvent = App_Model_DW.sfEvent_o;
            App_Model_DW.sfEvent_o = event_CancelTimer_LPCDOffDela_e;
            if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
              App_Model_LPCDOffDelay_h();
            }

            App_Model_DW.sfEvent_o = event_CancelTimer_PICCLPCDOff_n;
            if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
              App_Model_PICCLPCDOffDelay_d();
            }

            App_Model_DW.sfEvent_o = i_previousEvent;
            App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_NFC_k;
            enter_atomic_OperationMode_NF_m();
          } else {
            WPCStatus tmp_1;

            /* 5 */
            tmp_1 = App_Model_DW.INT_OPT_WPCStatus_1_start;
            if ((rtu_PreProcessIn_c == Off) && ((App_Model_DW.Timer_LPCDOffDelay >= 6000U) || (App_Model_DW.Timer_PICCLPCDOffDelay >= 6000U) || ((App_Model_DW.INT_OPT_WPCStatus_1_prev != tmp_1) &&
                  (tmp_1 == ModeOff)))) {
              /* Simultaneously */
              guard1 = true;
            } else {
              /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
               *  ActionPort: '<S368>/Action Port'
               */
              /* SwitchCase: '<S361>/Switch Case' incorporates:
               *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
               */
              App_Model_LPCDOff_Check_o(rtu_PreProcessIn_c);

              /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
            }
          }
        }
      }
    }
    break;

   case App_Mode_IN_OperationMode_NFC_k:
    {
      LC_IAUWPCNFCcmd tmp_0;
      App_Model_B.Output_OPT_WPCStatus = NFCMode;

      /* 1 */
      tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
      if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) {
        exit_atomic_OperationMode_NFC_o();
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_NFC_k;
        enter_atomic_OperationMode_NF_m();
      } else {
        /* 2%WPC1Lead, WPC2Follow or WPC1NFCOnly */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start;

        /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S368>/Action Port'
         */
        /* SwitchCase: '<S361>/Switch Case' incorporates:
         *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
         */
        if (((rtu_PreProcessIn_a == NFCMode) && ((App_Model_DW.INT_NFCDetectOrder_prev != App_Model_DW.INT_NFCDetectOrder_start) && (App_Model_DW.INT_NFCDetectOrder_start == 1))) ||
            ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev != tmp_0) && (tmp_0 == WPCNFCPolling_Search))) {
          exit_atomic_OperationMode_NFC_o();
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_Off_l;
          enter_atomic_OperationMode_Of_b(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);

          /* 30.5s60s */
        } else if ((rtu_PreProcessIn_c == On) && (rtu_PreProcessIn_m == WPC_On) && ((App_Model_DW.Timer_NFCSearchingOffDelay >= 50U) || (App_Model_DW.Timer_NFCTimeOutConfirm >= 6000U) ||
                    (App_Model_DW.Timer_NFCSearchingTimeout >= 150U))) {
          /* 1.5 */
          exit_atomic_OperationMode_NFC_o();
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_WPC_i;
          App_Model_B.Output_OPT_WPCStatus = WPCMode;

          /* Output_WPC_NFCDetection = NFCDetection_Off; */

          /* 4 */
        } else if (((rtu_PreProcessIn_c == Off) && (App_Model_DW.Timer_NFCSearchingOffDelay >= 50U)) || ((rtu_PreProcessIn_c == On) && (rtu_PreProcessIn_m == WPC_Off) &&
                    (App_Model_DW.Timer_NFCSearchingOffDelay >= 50U))) {
          /* 0.5s */
          exit_atomic_OperationMode_NFC_o();
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_OperationMode_Picc_o;
          enter_atomic_OperationMode_Pi_h();

          /* 5 */
          /* 60.5s60s */
        } else if ((App_Model_DW.Timer_NFCSearchingOffDelay >= 50U) || (App_Model_DW.Timer_NFCTimeOutConfirm >= 6000U) || (App_Model_DW.Timer_NFCSearchingTimeout >= 150U)) {
          /* 1.5 */
          exit_atomic_OperationMode_NFC_o();
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_OperationMode_LPCD_c;
          enter_atomic_OperationMode_LP_l(rtu_PreProcessIn_c);
        } else {
          App__NFCSearchingOffDetection_a();
          App_Model_NFCDetectionCheck_g();
        }

        /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
      }
    }
    break;

   case App_Mode_IN_OperationMode_Off_l:
    {
      WPCStatus tmp_1;
      App_Model_B.Output_OPT_WPCStatus = ModeOff;

      /* 1 */
      tmp_1 = App_Model_DW.INT_OPT_WPCStatus_1_prev;

      /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S368>/Action Port'
       */
      /* SwitchCase: '<S361>/Switch Case' incorporates:
       *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
       */
      if (((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && (tmp_1 == NFCMode) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && (App_Model_DW.INT_OPT_WPCStatus_1_start == LPCDMode))) ||
          (((App_Model_DW.Var_DrDoorPhnLftHoldComplete_pr != App_Model_DW.Var_DrDoorPhnLftHoldComplete_st) && (App_Model_DW.Var_DrDoorPhnLftHoldComplete_st == On)) || ((rtu_PreProcessIn_c == On) &&
            (rtu_PreProcessIn_l == OwnerPairingAdvertisingReq__StartEnable) && (rtu_PreProcessIn_m == WPC_Off) && (rtu_PreProcessIn_a == ModeOff)))) {
        /* WPC2ChangeOff2LPCD,WhenWPC1ChangeNFC2LPCD */
        /* BothOffModeStartEnable */
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_OperationMode_LPCD_c;
        enter_atomic_OperationMode_LP_l(rtu_PreProcessIn_c);

        /* 2 */
        /* 3 */
      } else if ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && (App_Model_DW.INT_OPT_WPCStatus_1_start == PICCMode)) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_OperationMode_Picc_o;
        enter_atomic_OperationMode_Pi_h();

        /* 3 */
      } else if (rtu_PreProcessIn_e == WPCNFCPolling_Search) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_NFC_k;
        enter_atomic_OperationMode_NF_m();

        /* 5 */
      } else if ((rtu_PreProcessIn_c == On) && (rtu_PreProcessIn_m == WPC_On) && (rtu_PreProcessIn_a != NFCMode)) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_WPC_i;
        App_Model_B.Output_OPT_WPCStatus = WPCMode;

        /* Output_WPC_NFCDetection = NFCDetection_Off; */
      } else {
        /* OffLPCD_Check();%OffToLPCDforFollow */
        App_Mo_DrDoorPhnLeftHoldCheck_k(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);
      }

      /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
    }
    break;

   case App_Mod_IN_OperationMode_Picc_o:
    {
      App_Model_B.Output_OPT_WPCStatus = PICCMode;

      /* 1 */
      if (rtu_PreProcessIn_p == On) {
        /* NFC1 or 2 OnThePad_Off */
        /* PhnRemoveMode */
        i_previousEvent = App_Model_DW.sfEvent_o;
        App_Model_DW.sfEvent_o = event_CancelTimer_PICCOffDela_g;
        if (App_Model_DW.is_active_PICCOffDelay != 0U) {
          App_Model_PICCOffDelay_l();
        }

        App_Model_DW.sfEvent_o = i_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_OperationMode_LPCD_c;

        /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S368>/Action Port'
         */
        /* SwitchCase: '<S361>/Switch Case' incorporates:
         *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
         */
        enter_atomic_OperationMode_LP_l(rtu_PreProcessIn_c);

        /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */

        /* 2 */
      } else if ((rtu_PreProcessIn_c == Off) && (App_Model_DW.Timer_PICCOffDelay >= 6000U)) {
        guard2 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 3 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0) && (tmp_0 == WPCNFCPolling_Search)) {
          /* PhnRemoveMode */
          i_previousEvent = App_Model_DW.sfEvent_o;
          App_Model_DW.sfEvent_o = event_CancelTimer_PICCOffDela_g;
          if (App_Model_DW.is_active_PICCOffDelay != 0U) {
            App_Model_PICCOffDelay_l();
          }

          App_Model_DW.sfEvent_o = i_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_NFC_k;
          enter_atomic_OperationMode_NF_m();

          /* 45sec */
        } else if ((rtu_PreProcessIn_c == On) && (rtu_PreProcessIn_m == WPC_On) && ((rtu_PreProcessIn_b == OnThePad_On) || ((rtu_PreProcessIn_b == OnThePad_Default) && (App_Model_DW.Timer_PICCOffDelay
          >= 500U)) || (rtu_PreProcessIn_a == WPCMode))) {
          /* TransitionMerge */
          /* PhnRemoveMode */
          i_previousEvent = App_Model_DW.sfEvent_o;
          App_Model_DW.sfEvent_o = event_CancelTimer_PICCOffDela_g;
          if (App_Model_DW.is_active_PICCOffDelay != 0U) {
            App_Model_PICCOffDelay_l();
          }

          App_Model_DW.sfEvent_o = i_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_WPC_i;
          App_Model_B.Output_OPT_WPCStatus = WPCMode;

          /* Output_WPC_NFCDetection = NFCDetection_Off; */
        } else {
          WPCStatus tmp_1;

          /* Simultenously ModeOff */
          tmp_1 = App_Model_DW.INT_OPT_WPCStatus_1_prev;
          if (((rtu_PreProcessIn_c == Off) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && (App_Model_DW.INT_OPT_WPCStatus_1_start == ModeOff))) || ((tmp_1 !=
                App_Model_DW.INT_OPT_WPCStatus_1_start) && (App_Model_DW.INT_OPT_WPCStatus_1_start == NFCMode)) || ((rtu_PreProcessIn_m == WPC_Off) && ((rtu_PreProcessIn_a == WPCMode) ||
                (App_Model_DW.Timer_PICCOffDelay >= 6000U)))) {
            /* WPCSWOffALL_Case */
            guard2 = true;
          } else {
            /* 6%WPCSWOption_Off Case */
          }
        }
      }
    }
    break;

   case App_Mode_IN_OperationMode_WPC_i:
    {
      App_Model_B.Output_OPT_WPCStatus = WPCMode;

      /* 1 */
      if (rtu_PreProcessIn_a == LPCDMode) {
        /* WhileWPC1isSWOff, WPC1MoveFromOFFtoLPCD */
        guard3 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0) && (tmp_0 == WPCNFCPolling_Search) && (rtu_PreProcessIn_a != NFCMode)) {
          /* WaitingforNFCCom */
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_NFC_k;
          enter_atomic_OperationMode_NF_m();

          /* 3%When WPC1&2 are Both ChargingOnThePad_Off || ObjectOnthePad_Off */
        } else if (((rtu_PreProcessIn_mb == On) || (rtu_PreProcessIn_jq == On)) && ((rtu_PreProcessIn_j == OwnerPhnReg__Disable) || (rtu_PreProcessIn_j == OwnerPhnReg__Default) || (rtu_PreProcessIn_j ==
          OwnerPhnReg__Invalid)) && (rtu_PreProcessIn_l == OwnerPairingAdvertisingReq__StartEnable)) {
          App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_OperationMode_Picc_o;
          enter_atomic_OperationMode_Pi_h();

          /* 4 */
        } else if ((rtu_PreProcessIn_c == Off) || (rtu_PreProcessIn_m == WPC_Off) || (rtu_PreProcessIn_a == NFCMode)) {
          /* PollingSearchDivided */
          guard3 = true;
        }
      }
    }
    break;
  }

  if (guard3) {
    App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_Off_l;

    /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S368>/Action Port'
     */
    /* SwitchCase: '<S361>/Switch Case' incorporates:
     *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
     */
    enter_atomic_OperationMode_Of_b(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);

    /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
  }

  if (guard2) {
    /* PhnRemoveMode */
    i_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_PICCOffDela_g;
    if (App_Model_DW.is_active_PICCOffDelay != 0U) {
      App_Model_PICCOffDelay_l();
    }

    App_Model_DW.sfEvent_o = i_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_Off_l;

    /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S368>/Action Port'
     */
    /* SwitchCase: '<S361>/Switch Case' incorporates:
     *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
     */
    enter_atomic_OperationMode_Of_b(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);

    /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
  }

  if (guard1) {
    i_previousEvent = App_Model_DW.sfEvent_o;
    App_Model_DW.sfEvent_o = event_CancelTimer_LPCDOffDela_e;
    if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
      App_Model_LPCDOffDelay_h();
    }

    App_Model_DW.sfEvent_o = event_CancelTimer_PICCLPCDOff_n;
    if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
      App_Model_PICCLPCDOffDelay_d();
    }

    App_Model_DW.sfEvent_o = i_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_Off_l;

    /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S368>/Action Port'
     */
    /* SwitchCase: '<S361>/Switch Case' incorporates:
     *  Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9'
     */
    enter_atomic_OperationMode_Of_b(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);

    /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
  }
}

/* System initialize for atomic system: '<S203>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Fun_f_Init(WPCStatus *rty_WPC2Status)
{
  /* SystemInitialize for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' */
  /* SystemInitialize for Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
  App_Model_DW.sfEvent_o = App_Model_CALL_EVENT_d;
  App_Model_DW.Input_OPT_WPCSWOption_prev = WPC_On;
  App_Model_DW.Input_OPT_WPCSWOption_start = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S361>/WPC_NFCModeControl_compact' */

  /* SystemInitialize for Merge: '<S361>/Merge' */
  *rty_WPC2Status = ModeOff;
}

/* Output and update for atomic system: '<S203>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Function_m(Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_c, LC_IAUWPCNFCcmd rtu_PreProcessIn_e, C_WPCOnOffNvalueSet rtu_PreProcessIn_m, IAU_OwnerPhnRegRVal rtu_PreProcessIn_j,
  OwnerPairingAdvertisingReq rtu_PreProcessIn_l, OnThePad rtu_PreProcessIn_b, LC_WPC_NFCDetection rtu_PreProcessIn_k, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_mb, WPCStatus rtu_PreProcessIn_a,
  uint8 rtu_PreProcessIn_p5, uint8 rtu_PreProcessIn_cp, Bool rtu_PreProcessIn_h, C_WPCWarning rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d, LC_IAUWPCNFCcmd rtu_PreProcessIn_hl, Bool
  rtu_PreProcessIn_jq, Bool rtu_PreProcessIn_ec, WPCStatus *rty_WPC2Status)
{
  /* SwitchCase: '<S361>/Switch Case' */
  switch (rtu_PreProcessIn) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S361>/WPC_Mode_Control' incorporates:
     *  ActionPort: '<S367>/Action Port'
     */
    App_Model_WPC_Mode_Control(rtu_PreProcessIn_c, rtu_PreProcessIn_m, rtu_PreProcessIn_ec, rty_WPC2Status, &App_Model_DW.WPC_Mode_Control_l);

    /* End of Outputs for SubSystem: '<S361>/WPC_Mode_Control' */
    break;

   case On:
    {
      /* Outputs for IfAction SubSystem: '<S361>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S368>/Action Port'
       */
      /* Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */
      App_Model_DW.sfEvent_o = App_Model_CALL_EVENT_d;
      App_Model_DW.Input_NFCDetection2_prev = App_Model_DW.Input_NFCDetection2_start;
      App_Model_DW.Input_NFCDetection2_start = rtu_PreProcessIn_k;
      App_Model_DW.Input_IAUWPCNFCcmd_2_prev = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
      App_Model_DW.Input_IAUWPCNFCcmd_2_start = rtu_PreProcessIn_e;
      App_Model_DW.Input_b_DrvDrSw_prev = App_Model_DW.Input_b_DrvDrSw_start;
      App_Model_DW.Input_b_DrvDrSw_start = rtu_PreProcessIn_h;
      App_Model_DW.Input_PhnLeftChk_Enable_prev = App_Model_DW.Input_PhnLeftChk_Enable_start;
      App_Model_DW.Input_PhnLeftChk_Enable_start = rtu_PreProcessIn_d;
      App_Model_DW.INT_OPT_WPCStatus_1_prev = App_Model_DW.INT_OPT_WPCStatus_1_start;
      App_Model_DW.INT_OPT_WPCStatus_1_start = rtu_PreProcessIn_a;
      App_Model_DW.Var_DrDoorPhnLftHoldComplete_pr = App_Model_DW.Var_DrDoorPhnLftHoldComplete_st;
      App_Model_DW.Var_DrDoorPhnLftHoldComplete_st = App_Model_DW.Var_DrDoorPhnLftHoldComplete;
      App_Model_DW.INT_LPCDWakeUpOrder_prev = App_Model_DW.INT_LPCDWakeUpOrder_start;
      App_Model_DW.INT_LPCDWakeUpOrder_start = rtu_PreProcessIn_p5;
      App_Model_DW.Input_IAUWPCNFCcmd_1_prev = App_Model_DW.Input_IAUWPCNFCcmd_1_start;
      App_Model_DW.Input_IAUWPCNFCcmd_1_start = rtu_PreProcessIn_hl;
      App_Model_DW.Input_b_IGN1_IN_prev = App_Model_DW.Input_b_IGN1_IN_start;
      App_Model_DW.Input_b_IGN1_IN_start = rtu_PreProcessIn_c;
      App_Model_DW.Input_OPT_WPCSWOption_prev = App_Model_DW.Input_OPT_WPCSWOption_start;
      App_Model_DW.Input_OPT_WPCSWOption_start = rtu_PreProcessIn_m;
      App_Model_DW.INT_NFCDetectOrder_prev = App_Model_DW.INT_NFCDetectOrder_start;
      App_Model_DW.INT_NFCDetectOrder_start = rtu_PreProcessIn_cp;
      if (App_Model_DW.is_active_c41_NFC_WPC_Mode_Cont == 0U) {
        App_Model_DW.Input_NFCDetection2_prev = rtu_PreProcessIn_k;
        App_Model_DW.Input_IAUWPCNFCcmd_2_prev = rtu_PreProcessIn_e;
        App_Model_DW.Input_b_DrvDrSw_prev = rtu_PreProcessIn_h;
        App_Model_DW.Input_PhnLeftChk_Enable_prev = rtu_PreProcessIn_d;
        App_Model_DW.INT_OPT_WPCStatus_1_prev = rtu_PreProcessIn_a;
        App_Model_DW.INT_LPCDWakeUpOrder_prev = rtu_PreProcessIn_p5;
        App_Model_DW.Input_IAUWPCNFCcmd_1_prev = rtu_PreProcessIn_hl;
        App_Model_DW.Input_b_IGN1_IN_prev = rtu_PreProcessIn_c;
        App_Model_DW.Input_OPT_WPCSWOption_prev = rtu_PreProcessIn_m;
        App_Model_DW.INT_NFCDetectOrder_prev = rtu_PreProcessIn_cp;
        App_Model_DW.is_active_c41_NFC_WPC_Mode_Cont = 1U;
        App_Model_DW.is_active_NFCTimeOutConfirm = 1U;
        App_Model_DW.is_NFCTimeOutConfirm = App__IN_NFCTimeOutConfirm_Off_j;
        App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
        App_Model_DW.is_active_NFCSearchingOffDelay = 1U;
        App_Model_DW.is_NFCSearchingOffDelay = A_IN_NFCSearchingOffDelay_Off_f;
        App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
        App_Model_DW.is_active_DeviceStateWait = 1U;
        App_Model_DW.is_DeviceStateWait = App_Mo_IN_DeviceStateWait_Off_d;
        App_Model_DW.Timer_DeviceStateWait = 0U;
        App_Model_DW.is_active_LPCDOffDelay = 1U;
        App_Model_DW.is_LPCDOffDelay = App_Model_IN_LPCDOffDelay_Off_f;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Running = false;
        App_Model_DW.Timer_LPCDOffDelay = 0U;
        App_Model_DW.is_active_NFCSearchingTimeout = 1U;
        App_Model_DW.is_NFCSearchingTimeout = Ap_IN_NFCSearchingTimeout_Off_f;
        App_Model_DW.Timer_NFCSearchingTimeout = 0U;
        App_Model_DW.is_active_PhnLeftHolding = 1U;
        App_Model_DW.is_PhnLeftHolding = App_Mod_IN_PhnLeftHolding_Off_m;
        App_Model_DW.Timer_PhnLeftHolding = 0U;
        App_Model_DW.is_active_PICCOffDelay = 1U;
        App_Model_DW.is_PICCOffDelay = App_Model_IN_PICCOffDelay_Off_o;
        App_Model_DW.Timer_PICCOffDelay = 0U;
        App_Model_DW.is_active_WPC_NFC_Mode_Control_ = 1U;

        /* Default */
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mode_IN_OperationMode_Off_l;
        enter_atomic_OperationMode_Of_b(rtu_PreProcessIn_c, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d);
        App_Model_DW.is_active_PICCLPCDOffDelay = 1U;
        App_Model_DW.is_PICCLPCDOffDelay = App_M_IN_PICCLPCDOffDelay_Off_b;
        App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
        App_Model_DW.is_active_PhnLeftChattering = 1U;
        App_Model_DW.is_PhnLeftChattering = App__IN_PhnLeftChattering_Off_d;
        App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = false;
        App_Model_DW.Timer_PhnLeftChattering = 0U;
      } else {
        uint32 qY;
        if (App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
          App_Model_NFCTimeOutConfirm_e();
        }

        if (App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
          App_Mode_NFCSearchingOffDelay_g();
        }

        if (App_Model_DW.is_active_DeviceStateWait != 0U) {
          switch (App_Model_DW.is_DeviceStateWait) {
           case App_Mo_IN_DeviceStateWait_Off_d:
            break;

           case App_Mod_IN_DeviceStateWait_On_i:
            qY = App_Model_DW.Timer_DeviceStateWait + /*MW:OvSatOk*/ 1U;
            if (App_Model_DW.Timer_DeviceStateWait + 1U < App_Model_DW.Timer_DeviceStateWait) {
              qY = MAX_uint32_T;
            }

            App_Model_DW.Timer_DeviceStateWait = qY;
            break;
          }
        }

        if (App_Model_DW.is_active_LPCDOffDelay != 0U) {
          App_Model_LPCDOffDelay_h();
        }

        if (App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
          App_Model_NFCSearchingTimeout_i();
        }

        if (App_Model_DW.is_active_PhnLeftHolding != 0U) {
          switch (App_Model_DW.is_PhnLeftHolding) {
           case App_Mod_IN_PhnLeftHolding_Off_m:
            break;

           case App_Mode_IN_PhnLeftHolding_On_h:
            qY = App_Model_DW.Timer_PhnLeftHolding + /*MW:OvSatOk*/ 1U;
            if (App_Model_DW.Timer_PhnLeftHolding + 1U < App_Model_DW.Timer_PhnLeftHolding) {
              qY = MAX_uint32_T;
            }

            App_Model_DW.Timer_PhnLeftHolding = qY;
            break;
          }
        }

        if (App_Model_DW.is_active_PICCOffDelay != 0U) {
          App_Model_PICCOffDelay_l();
        }

        if (App_Model_DW.is_active_WPC_NFC_Mode_Control_ != 0U) {
          WPC_NFC_Mode_Control_Function_j(rtu_PreProcessIn_c, rtu_PreProcessIn_e, rtu_PreProcessIn_m, rtu_PreProcessIn_j, rtu_PreProcessIn_l, rtu_PreProcessIn_b, rtu_PreProcessIn_p,
            rtu_PreProcessIn_mb, rtu_PreProcessIn_a, rtu_PreProcessIn_h, rtu_PreProcessIn_ai, rtu_PreProcessIn_d, rtu_PreProcessIn_jq);
        }

        if (App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
          App_Model_PICCLPCDOffDelay_d();
        }

        if (App_Model_DW.is_active_PhnLeftChattering != 0U) {
          App_Model_PhnLeftChattering_i();
        }
      }

      /* End of Chart: '<S368>/NFC_WPC_Mode_Control_MPPEPP_2_r9' */

      /* SignalConversion: '<S368>/Signal Conversion1' */
      *rty_WPC2Status = App_Model_B.Output_OPT_WPCStatus;

      /* End of Outputs for SubSystem: '<S361>/WPC_NFCModeControl_compact' */
    }
    break;
  }

  /* End of SwitchCase: '<S361>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
