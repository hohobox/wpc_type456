/*
 * File: USMSettingControl_Function.c
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
#include "USMSettingControl_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S197>/DWPC1_USMSettingControl2_5' */
#define App_Model_IN_WPCUSM_SetGuest   ((uint8)1U)
#define App_Model_IN_WPCUSM_SetOne     ((uint8)2U)
#define App_Model_IN_WPCUSM_SetTwo     ((uint8)3U)

/* Named constants for Chart: '<S377>/DWPC2_USMSettingControl2_5' */
#define App_Model_IN_WPC2USM_SetGuest  ((uint8)1U)
#define App_Model_IN_WPC2USM_SetOne    ((uint8)2U)
#define App_Model_IN_WPC2USM_SetTwo    ((uint8)3U)

/* Forward declaration for local functions */
static void App_M_Function_ProfileTwoWPCUSM(C_WPCOnOffNvalueSet *C_WPCRValue_h, C_WPCOnOffNvalueSet *WPCSWOption_f);
static void App_Function_ProfileGuestWPCUSM(C_WPCOnOffNvalueSet *C_WPCRValue_h, C_WPCOnOffNvalueSet *WPCSWOption_f);
static void App_M_Function_ProfileOneWPCUSM(C_WPCOnOffNvalueSet *C_WPCRValue_h, C_WPCOnOffNvalueSet *WPCSWOption_f);
static void App_Function_ProfileTwoWPCUSM_f(C_WPCOnOffNvalueSet *C_WPCRValue_g, C_WPCOnOffNvalueSet *WPCSWOption_j);
static void A_Function_ProfileGuestWPCUSM_g(C_WPCOnOffNvalueSet *C_WPCRValue_g, C_WPCOnOffNvalueSet *WPCSWOption_j);
static void App_Function_ProfileOneWPCUSM_e(C_WPCOnOffNvalueSet *C_WPCRValue_g, C_WPCOnOffNvalueSet *WPCSWOption_j);

/* Forward declaration for local functions */
static void App__Function_ProfileTwoWPC2USM(C_WPCOnOffNvalueSet *C_WPC2RValue_g, C_WPCOnOffNvalueSet *WPC2SWOption_i);
static void Ap_Function_ProfileGuestWPC2USM(C_WPCOnOffNvalueSet *C_WPC2RValue_g, C_WPCOnOffNvalueSet *WPC2SWOption_i);
static void App__Function_ProfileOneWPC2USM(C_WPCOnOffNvalueSet *C_WPC2RValue_g, C_WPCOnOffNvalueSet *WPC2SWOption_i);
static void Ap_Function_ProfileTwoWPC2USM_d(C_WPCOnOffNvalueSet *C_WPC2RValue_j, C_WPCOnOffNvalueSet *WPC2SWOption_o);
static void Function_ProfileGuestWPC2USM_i(C_WPCOnOffNvalueSet *C_WPC2RValue_j, C_WPCOnOffNvalueSet *WPC2SWOption_o);
static void Ap_Function_ProfileOneWPC2USM_n(C_WPCOnOffNvalueSet *C_WPC2RValue_j, C_WPCOnOffNvalueSet *WPC2SWOption_o);

/* Function for Chart: '<S197>/DWPC1_USMSettingControl2_5' */
static void App_M_Function_ProfileTwoWPCUSM(C_WPCOnOffNvalueSet *C_WPCRValue_h, C_WPCOnOffNvalueSet *WPCSWOption_f)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_k != App_Model_DW.C_USMReset_start_n) && (App_Model_DW.C_USMReset_start_n == USMReset)) {
    *C_WPCRValue_h = WPC_On;
    *WPCSWOption_f = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev_d != App_Model_DW.C_WPCOnOffNValueSet_start_b) && (App_Model_DW.C_WPCOnOffNValueSet_start_b == WPC_On)) {
    *C_WPCRValue_h = WPC_On;
    *WPCSWOption_f = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev_d != App_Model_DW.C_WPCOnOffNValueSet_start_b) && (App_Model_DW.C_WPCOnOffNValueSet_start_b == WPC_Off)) {
    *C_WPCRValue_h = WPC_Off;
    *WPCSWOption_f = WPC_Off;
    m_ProfileTwoWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue_h = WPC_On;
      *WPCSWOption_f = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue_h = WPC_Off;
      *WPCSWOption_f = WPC_Off;
      break;

     default:
      *C_WPCRValue_h = WPC_On;
      *WPCSWOption_f = WPC_On;
      m_ProfileTwoWPCUSM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S197>/DWPC1_USMSettingControl2_5' */
static void App_Function_ProfileGuestWPCUSM(C_WPCOnOffNvalueSet *C_WPCRValue_h, C_WPCOnOffNvalueSet *WPCSWOption_f)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_k != App_Model_DW.C_USMReset_start_n) && (App_Model_DW.C_USMReset_start_n == USMReset)) {
    *C_WPCRValue_h = WPC_On;
    *WPCSWOption_f = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev_d != App_Model_DW.C_WPCOnOffNValueSet_start_b) && (App_Model_DW.C_WPCOnOffNValueSet_start_b == WPC_On)) {
    *C_WPCRValue_h = WPC_On;
    *WPCSWOption_f = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev_d != App_Model_DW.C_WPCOnOffNValueSet_start_b) && (App_Model_DW.C_WPCOnOffNValueSet_start_b == WPC_Off)) {
    *C_WPCRValue_h = WPC_Off;
    *WPCSWOption_f = WPC_Off;
    m_ProfileGuestWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue_h = WPC_On;
      *WPCSWOption_f = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue_h = WPC_Off;
      *WPCSWOption_f = WPC_Off;
      break;

     default:
      *C_WPCRValue_h = WPC_On;
      *WPCSWOption_f = WPC_On;
      m_ProfileGuestWPCUSM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S197>/DWPC1_USMSettingControl2_5' */
static void App_M_Function_ProfileOneWPCUSM(C_WPCOnOffNvalueSet *C_WPCRValue_h, C_WPCOnOffNvalueSet *WPCSWOption_f)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_k != App_Model_DW.C_USMReset_start_n) && (App_Model_DW.C_USMReset_start_n == USMReset)) {
    *C_WPCRValue_h = WPC_On;
    *WPCSWOption_f = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev_d != App_Model_DW.C_WPCOnOffNValueSet_start_b) && (App_Model_DW.C_WPCOnOffNValueSet_start_b == WPC_On)) {
    *C_WPCRValue_h = WPC_On;
    *WPCSWOption_f = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev_d != App_Model_DW.C_WPCOnOffNValueSet_start_b) && (App_Model_DW.C_WPCOnOffNValueSet_start_b == WPC_Off)) {
    *C_WPCRValue_h = WPC_Off;
    *WPCSWOption_f = WPC_Off;
    m_ProfileOneWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue_h = WPC_On;
      *WPCSWOption_f = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue_h = WPC_Off;
      *WPCSWOption_f = WPC_Off;
      break;

     default:
      *C_WPCRValue_h = WPC_On;
      *WPCSWOption_f = WPC_On;
      m_ProfileOneWPCUSM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S196>/DWPC1_USMSettingControl3_5' */
static void App_Function_ProfileTwoWPCUSM_f(C_WPCOnOffNvalueSet *C_WPCRValue_g, C_WPCOnOffNvalueSet *WPCSWOption_j)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_h != App_Model_DW.C_USMReset_start_e) && (App_Model_DW.C_USMReset_start_e == USMReset)) {
    *C_WPCRValue_g = WPC_On;
    *WPCSWOption_j = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev != App_Model_DW.C_WPCOnOffNValueSet_start) && (App_Model_DW.C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue_g = WPC_On;
    *WPCSWOption_j = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev != App_Model_DW.C_WPCOnOffNValueSet_start) && (App_Model_DW.C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue_g = WPC_Off;
    *WPCSWOption_j = WPC_Off;
    m_ProfileTwoWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue_g = WPC_On;
      *WPCSWOption_j = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue_g = WPC_Off;
      *WPCSWOption_j = WPC_Off;
      break;

     default:
      *C_WPCRValue_g = WPC_On;
      *WPCSWOption_j = WPC_On;
      m_ProfileTwoWPCUSM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S196>/DWPC1_USMSettingControl3_5' */
static void A_Function_ProfileGuestWPCUSM_g(C_WPCOnOffNvalueSet *C_WPCRValue_g, C_WPCOnOffNvalueSet *WPCSWOption_j)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_h != App_Model_DW.C_USMReset_start_e) && (App_Model_DW.C_USMReset_start_e == USMReset)) {
    *C_WPCRValue_g = WPC_On;
    *WPCSWOption_j = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev != App_Model_DW.C_WPCOnOffNValueSet_start) && (App_Model_DW.C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue_g = WPC_On;
    *WPCSWOption_j = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev != App_Model_DW.C_WPCOnOffNValueSet_start) && (App_Model_DW.C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue_g = WPC_Off;
    *WPCSWOption_j = WPC_Off;
    m_ProfileGuestWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue_g = WPC_On;
      *WPCSWOption_j = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue_g = WPC_Off;
      *WPCSWOption_j = WPC_Off;
      break;

     default:
      *C_WPCRValue_g = WPC_On;
      *WPCSWOption_j = WPC_On;
      m_ProfileGuestWPCUSM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S196>/DWPC1_USMSettingControl3_5' */
static void App_Function_ProfileOneWPCUSM_e(C_WPCOnOffNvalueSet *C_WPCRValue_g, C_WPCOnOffNvalueSet *WPCSWOption_j)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_h != App_Model_DW.C_USMReset_start_e) && (App_Model_DW.C_USMReset_start_e == USMReset)) {
    *C_WPCRValue_g = WPC_On;
    *WPCSWOption_j = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev != App_Model_DW.C_WPCOnOffNValueSet_start) && (App_Model_DW.C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue_g = WPC_On;
    *WPCSWOption_j = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPCOnOffNValueSet_prev != App_Model_DW.C_WPCOnOffNValueSet_start) && (App_Model_DW.C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue_g = WPC_Off;
    *WPCSWOption_j = WPC_Off;
    m_ProfileOneWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue_g = WPC_On;
      *WPCSWOption_j = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue_g = WPC_Off;
      *WPCSWOption_j = WPC_Off;
      break;

     default:
      *C_WPCRValue_g = WPC_On;
      *WPCSWOption_j = WPC_On;
      m_ProfileOneWPCUSM_App = WPC_On;
      break;
    }
  }
}

/* System initialize for atomic system: '<S13>/USMSettingControl_Function' */
void USMSettingControl_Function_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_b)
{
  /* SystemInitialize for IfAction SubSystem: '<S19>/USMSettingControl_Non_NFC' */
  /* SystemInitialize for Chart: '<S197>/DWPC1_USMSettingControl2_5' */
  App_Model_DW.C_WPCOnOffNValueSet_prev_d = WPC_On;
  App_Model_DW.C_WPCOnOffNValueSet_start_b = WPC_On;

  /* SystemInitialize for IfAction SubSystem: '<S19>/USMSettingControl_NFC' */
  /* SystemInitialize for Chart: '<S196>/DWPC1_USMSettingControl3_5' incorporates:
   *  Chart: '<S197>/DWPC1_USMSettingControl2_5'
   */
  App_Model_DW.C_WPCOnOffNValueSet_prev = WPC_On;
  App_Model_DW.C_WPCOnOffNValueSet_start = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S19>/USMSettingControl_NFC' */
  /* End of SystemInitialize for SubSystem: '<S19>/USMSettingControl_Non_NFC' */

  /* SystemInitialize for Merge generated from: '<S19>/Merge' */
  *rty_USM_Sig = WPC_On;

  /* SystemInitialize for Merge generated from: '<S19>/Merge' */
  *rty_USM_Sig_b = WPC_On;
}

/* Output and update for atomic system: '<S13>/USMSettingControl_Function' */
void App__USMSettingControl_Function(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_b, C_USMReset rtu_InputSig_d, C_ProfileIDRValue rtu_InputSig_i, C_ProfileIDRValue rtu_InputSig_h,
  C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_b)
{
  /* SwitchCase: '<S19>/Switch Case' */
  switch (rtu_InputSig) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S19>/USMSettingControl_Non_NFC' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    /* Chart: '<S197>/DWPC1_USMSettingControl2_5' */
    App_Model_DW.C_USMReset_prev_k = App_Model_DW.C_USMReset_start_n;
    App_Model_DW.C_USMReset_start_n = rtu_InputSig_d;
    App_Model_DW.C_WPCOnOffNValueSet_prev_d = App_Model_DW.C_WPCOnOffNValueSet_start_b;
    App_Model_DW.C_WPCOnOffNValueSet_start_b = rtu_InputSig_b;
    if (App_Model_DW.is_active_c12_USMSettingControl == 0U) {
      App_Model_DW.C_USMReset_prev_k = rtu_InputSig_d;
      App_Model_DW.C_WPCOnOffNValueSet_prev_d = rtu_InputSig_b;
      App_Model_DW.is_active_c12_USMSettingControl = 1U;
      App_Model_DW.CurProfile_e = Guest;

      /* 1. */
      switch (rtu_InputSig_i) {
       case Profile1:
        App_Model_DW.CurProfile_e = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_e = Profile2;
        break;

       case Guest:
        /* 1. */
        break;
      }

      /* 1 */
      switch (App_Model_DW.CurProfile_e) {
       case Profile1:
        App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetOne;

        /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S197>/C_WPCRValue'
         */
        App_M_Function_ProfileOneWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetTwo;

        /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S197>/C_WPCRValue'
         */
        App_M_Function_ProfileTwoWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
        break;

       default:
        /* 3 */
        App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetGuest;

        /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S197>/C_WPCRValue'
         */
        App_Function_ProfileGuestWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
        break;
      }
    } else {
      /* 1. */
      switch (rtu_InputSig_i) {
       case Profile1:
        App_Model_DW.CurProfile_e = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_e = Profile2;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_e = Guest;
        break;
      }

      switch (App_Model_DW.is_USMSettingControl_j) {
       case App_Model_IN_WPCUSM_SetGuest:
        /* 1. */
        switch (App_Model_DW.CurProfile_e) {
         case Profile1:
          App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetOne;

          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_M_Function_ProfileOneWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetTwo;

          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_M_Function_ProfileTwoWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;

         default:
          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_Function_ProfileGuestWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;
        }
        break;

       case App_Model_IN_WPCUSM_SetOne:
        /* 1. */
        switch (App_Model_DW.CurProfile_e) {
         case Guest:
          App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetGuest;

          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_Function_ProfileGuestWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetTwo;

          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_M_Function_ProfileTwoWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;

         default:
          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_M_Function_ProfileOneWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;
        }
        break;

       default:
        /* case IN_WPCUSM_SetTwo: */
        /* 1. */
        switch (App_Model_DW.CurProfile_e) {
         case Guest:
          App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetGuest;

          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_Function_ProfileGuestWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;

         case Profile1:
          /* 2. */
          App_Model_DW.is_USMSettingControl_j = App_Model_IN_WPCUSM_SetOne;

          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_M_Function_ProfileOneWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;

         default:
          /* SignalConversion generated from: '<S197>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S197>/C_WPCRValue'
           */
          App_M_Function_ProfileTwoWPCUSM(rty_USM_Sig, rty_USM_Sig_b);
          break;
        }
        break;
      }
    }

    /* End of Chart: '<S197>/DWPC1_USMSettingControl2_5' */
    /* End of Outputs for SubSystem: '<S19>/USMSettingControl_Non_NFC' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S19>/USMSettingControl_NFC' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    /* Chart: '<S196>/DWPC1_USMSettingControl3_5' */
    App_Model_DW.C_USMReset_prev_h = App_Model_DW.C_USMReset_start_e;
    App_Model_DW.C_USMReset_start_e = rtu_InputSig_d;
    App_Model_DW.C_WPCOnOffNValueSet_prev = App_Model_DW.C_WPCOnOffNValueSet_start;
    App_Model_DW.C_WPCOnOffNValueSet_start = rtu_InputSig_b;
    if (App_Model_DW.is_active_c10_USMSettingControl == 0U) {
      App_Model_DW.C_USMReset_prev_h = rtu_InputSig_d;
      App_Model_DW.C_WPCOnOffNValueSet_prev = rtu_InputSig_b;
      App_Model_DW.is_active_c10_USMSettingControl = 1U;
      App_Model_DW.CurProfile_a = Guest;

      /* 1. */
      switch (rtu_InputSig_h) {
       case Profile1:
        App_Model_DW.CurProfile_a = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_a = Profile2;
        break;

       case Guest:
        /* 1. */
        break;

       default:
        /* 1. */
        switch (rtu_InputSig_i) {
         case Profile1:
          App_Model_DW.CurProfile_a = Profile1;
          break;

         case Profile2:
          /* 1. */
          App_Model_DW.CurProfile_a = Profile2;
          break;

         case Guest:
          /* 1. */
          break;
        }
        break;
      }

      /* 1 */
      switch (App_Model_DW.CurProfile_a) {
       case Profile1:
        App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetOne;

        /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S196>/C_WPCRValue'
         */
        App_Function_ProfileOneWPCUSM_e(rty_USM_Sig, rty_USM_Sig_b);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetTwo;

        /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S196>/C_WPCRValue'
         */
        App_Function_ProfileTwoWPCUSM_f(rty_USM_Sig, rty_USM_Sig_b);
        break;

       default:
        /* 3 */
        App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetGuest;

        /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S196>/C_WPCRValue'
         */
        A_Function_ProfileGuestWPCUSM_g(rty_USM_Sig, rty_USM_Sig_b);
        break;
      }
    } else {
      /* 1. */
      switch (rtu_InputSig_h) {
       case Profile1:
        App_Model_DW.CurProfile_a = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_a = Profile2;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_a = Guest;
        break;

       default:
        /* 1. */
        switch (rtu_InputSig_i) {
         case Profile1:
          App_Model_DW.CurProfile_a = Profile1;
          break;

         case Profile2:
          /* 1. */
          App_Model_DW.CurProfile_a = Profile2;
          break;

         case Guest:
          /* 1. */
          App_Model_DW.CurProfile_a = Guest;
          break;
        }
        break;
      }

      switch (App_Model_DW.is_USMSettingControl_p) {
       case App_Model_IN_WPCUSM_SetGuest:
        /* 1. */
        switch (App_Model_DW.CurProfile_a) {
         case Profile1:
          App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetOne;

          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          App_Function_ProfileOneWPCUSM_e(rty_USM_Sig, rty_USM_Sig_b);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetTwo;

          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          App_Function_ProfileTwoWPCUSM_f(rty_USM_Sig, rty_USM_Sig_b);
          break;

         default:
          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          A_Function_ProfileGuestWPCUSM_g(rty_USM_Sig, rty_USM_Sig_b);
          break;
        }
        break;

       case App_Model_IN_WPCUSM_SetOne:
        /* 1. */
        switch (App_Model_DW.CurProfile_a) {
         case Guest:
          App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetGuest;

          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          A_Function_ProfileGuestWPCUSM_g(rty_USM_Sig, rty_USM_Sig_b);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetTwo;

          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          App_Function_ProfileTwoWPCUSM_f(rty_USM_Sig, rty_USM_Sig_b);
          break;

         default:
          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          App_Function_ProfileOneWPCUSM_e(rty_USM_Sig, rty_USM_Sig_b);
          break;
        }
        break;

       default:
        /* case IN_WPCUSM_SetTwo: */
        /* 1. */
        switch (App_Model_DW.CurProfile_a) {
         case Guest:
          App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetGuest;

          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          A_Function_ProfileGuestWPCUSM_g(rty_USM_Sig, rty_USM_Sig_b);
          break;

         case Profile1:
          /* 2. */
          App_Model_DW.is_USMSettingControl_p = App_Model_IN_WPCUSM_SetOne;

          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          App_Function_ProfileOneWPCUSM_e(rty_USM_Sig, rty_USM_Sig_b);
          break;

         default:
          /* SignalConversion generated from: '<S196>/WPCSWOption' incorporates:
           *  SignalConversion generated from: '<S196>/C_WPCRValue'
           */
          App_Function_ProfileTwoWPCUSM_f(rty_USM_Sig, rty_USM_Sig_b);
          break;
        }
        break;
      }
    }

    /* End of Chart: '<S196>/DWPC1_USMSettingControl3_5' */
    /* End of Outputs for SubSystem: '<S19>/USMSettingControl_NFC' */
    break;
  }

  /* End of SwitchCase: '<S19>/Switch Case' */
}

/* Function for Chart: '<S377>/DWPC2_USMSettingControl2_5' */
static void App__Function_ProfileTwoWPC2USM(C_WPCOnOffNvalueSet *C_WPC2RValue_g, C_WPCOnOffNvalueSet *WPC2SWOption_i)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_f != App_Model_DW.C_USMReset_start_m) && (App_Model_DW.C_USMReset_start_m == USMReset)) {
    *C_WPC2RValue_g = WPC_On;
    *WPC2SWOption_i = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_p != App_Model_DW.C_WPC2OnOffNValueSet_start_m) && (App_Model_DW.C_WPC2OnOffNValueSet_start_m == WPC_On)) {
    *C_WPC2RValue_g = WPC_On;
    *WPC2SWOption_i = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_p != App_Model_DW.C_WPC2OnOffNValueSet_start_m) && (App_Model_DW.C_WPC2OnOffNValueSet_start_m == WPC_Off)) {
    *C_WPC2RValue_g = WPC_Off;
    *WPC2SWOption_i = WPC_Off;
    m_ProfileTwoWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_g = WPC_On;
      *WPC2SWOption_i = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_g = WPC_Off;
      *WPC2SWOption_i = WPC_Off;
      break;

     default:
      *C_WPC2RValue_g = WPC_On;
      *WPC2SWOption_i = WPC_On;
      m_ProfileTwoWPC2USM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S377>/DWPC2_USMSettingControl2_5' */
static void Ap_Function_ProfileGuestWPC2USM(C_WPCOnOffNvalueSet *C_WPC2RValue_g, C_WPCOnOffNvalueSet *WPC2SWOption_i)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_f != App_Model_DW.C_USMReset_start_m) && (App_Model_DW.C_USMReset_start_m == USMReset)) {
    *C_WPC2RValue_g = WPC_On;
    *WPC2SWOption_i = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_p != App_Model_DW.C_WPC2OnOffNValueSet_start_m) && (App_Model_DW.C_WPC2OnOffNValueSet_start_m == WPC_On)) {
    *C_WPC2RValue_g = WPC_On;
    *WPC2SWOption_i = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_p != App_Model_DW.C_WPC2OnOffNValueSet_start_m) && (App_Model_DW.C_WPC2OnOffNValueSet_start_m == WPC_Off)) {
    *C_WPC2RValue_g = WPC_Off;
    *WPC2SWOption_i = WPC_Off;
    m_ProfileGuestWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_g = WPC_On;
      *WPC2SWOption_i = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_g = WPC_Off;
      *WPC2SWOption_i = WPC_Off;
      break;

     default:
      *C_WPC2RValue_g = WPC_On;
      *WPC2SWOption_i = WPC_On;
      m_ProfileGuestWPC2USM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S377>/DWPC2_USMSettingControl2_5' */
static void App__Function_ProfileOneWPC2USM(C_WPCOnOffNvalueSet *C_WPC2RValue_g, C_WPCOnOffNvalueSet *WPC2SWOption_i)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_f != App_Model_DW.C_USMReset_start_m) && (App_Model_DW.C_USMReset_start_m == USMReset)) {
    *C_WPC2RValue_g = WPC_On;
    *WPC2SWOption_i = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_p != App_Model_DW.C_WPC2OnOffNValueSet_start_m) && (App_Model_DW.C_WPC2OnOffNValueSet_start_m == WPC_On)) {
    *C_WPC2RValue_g = WPC_On;
    *WPC2SWOption_i = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_p != App_Model_DW.C_WPC2OnOffNValueSet_start_m) && (App_Model_DW.C_WPC2OnOffNValueSet_start_m == WPC_Off)) {
    *C_WPC2RValue_g = WPC_Off;
    *WPC2SWOption_i = WPC_Off;
    m_ProfileOneWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_g = WPC_On;
      *WPC2SWOption_i = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_g = WPC_Off;
      *WPC2SWOption_i = WPC_Off;
      break;

     default:
      *C_WPC2RValue_g = WPC_On;
      *WPC2SWOption_i = WPC_On;
      m_ProfileOneWPC2USM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S376>/DWPC2_USMSettingControl3_5' */
static void Ap_Function_ProfileTwoWPC2USM_d(C_WPCOnOffNvalueSet *C_WPC2RValue_j, C_WPCOnOffNvalueSet *WPC2SWOption_o)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev != App_Model_DW.C_USMReset_start) && (App_Model_DW.C_USMReset_start == USMReset)) {
    *C_WPC2RValue_j = WPC_On;
    *WPC2SWOption_o = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && (App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue_j = WPC_On;
    *WPC2SWOption_o = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && (App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue_j = WPC_Off;
    *WPC2SWOption_o = WPC_Off;
    m_ProfileTwoWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_j = WPC_On;
      *WPC2SWOption_o = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_j = WPC_Off;
      *WPC2SWOption_o = WPC_Off;
      break;

     default:
      *C_WPC2RValue_j = WPC_On;
      *WPC2SWOption_o = WPC_On;
      m_ProfileTwoWPC2USM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S376>/DWPC2_USMSettingControl3_5' */
static void Function_ProfileGuestWPC2USM_i(C_WPCOnOffNvalueSet *C_WPC2RValue_j, C_WPCOnOffNvalueSet *WPC2SWOption_o)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev != App_Model_DW.C_USMReset_start) && (App_Model_DW.C_USMReset_start == USMReset)) {
    *C_WPC2RValue_j = WPC_On;
    *WPC2SWOption_o = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && (App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue_j = WPC_On;
    *WPC2SWOption_o = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && (App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue_j = WPC_Off;
    *WPC2SWOption_o = WPC_Off;
    m_ProfileGuestWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_j = WPC_On;
      *WPC2SWOption_o = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_j = WPC_Off;
      *WPC2SWOption_o = WPC_Off;
      break;

     default:
      *C_WPC2RValue_j = WPC_On;
      *WPC2SWOption_o = WPC_On;
      m_ProfileGuestWPC2USM_App = WPC_On;
      break;
    }
  }
}

/* Function for Chart: '<S376>/DWPC2_USMSettingControl3_5' */
static void Ap_Function_ProfileOneWPC2USM_n(C_WPCOnOffNvalueSet *C_WPC2RValue_j, C_WPCOnOffNvalueSet *WPC2SWOption_o)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev != App_Model_DW.C_USMReset_start) && (App_Model_DW.C_USMReset_start == USMReset)) {
    *C_WPC2RValue_j = WPC_On;
    *WPC2SWOption_o = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && (App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue_j = WPC_On;
    *WPC2SWOption_o = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && (App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue_j = WPC_Off;
    *WPC2SWOption_o = WPC_Off;
    m_ProfileOneWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_j = WPC_On;
      *WPC2SWOption_o = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_j = WPC_Off;
      *WPC2SWOption_o = WPC_Off;
      break;

     default:
      *C_WPC2RValue_j = WPC_On;
      *WPC2SWOption_o = WPC_On;
      m_ProfileOneWPC2USM_App = WPC_On;
      break;
    }
  }
}

/* System initialize for atomic system: '<S14>/USMSettingControl_Function' */
void USMSettingControl_Functi_i_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g)
{
  /* SystemInitialize for IfAction SubSystem: '<S204>/USMSettingControl_Non_NFC' */
  /* SystemInitialize for Chart: '<S377>/DWPC2_USMSettingControl2_5' */
  App_Model_DW.C_WPC2OnOffNValueSet_prev_p = WPC_On;
  App_Model_DW.C_WPC2OnOffNValueSet_start_m = WPC_On;

  /* SystemInitialize for IfAction SubSystem: '<S204>/USMSettingControl_NFC' */
  /* SystemInitialize for Chart: '<S376>/DWPC2_USMSettingControl3_5' incorporates:
   *  Chart: '<S377>/DWPC2_USMSettingControl2_5'
   */
  App_Model_DW.C_WPC2OnOffNValueSet_prev = WPC_On;
  App_Model_DW.C_WPC2OnOffNValueSet_start = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S204>/USMSettingControl_NFC' */
  /* End of SystemInitialize for SubSystem: '<S204>/USMSettingControl_Non_NFC' */

  /* SystemInitialize for Merge generated from: '<S204>/Merge' */
  *rty_USM_Sig = WPC_On;

  /* SystemInitialize for Merge generated from: '<S204>/Merge' */
  *rty_USM_Sig_g = WPC_On;
}

/* Output and update for atomic system: '<S14>/USMSettingControl_Function' */
void Ap_USMSettingControl_Function_h(Bool rtu_DWPC2_InputSig, C_WPCOnOffNvalueSet rtu_DWPC2_InputSig_g, C_USMReset rtu_DWPC2_InputSig_k, C_ProfileIDRValue rtu_DWPC2_InputSig_gy, C_ProfileIDRValue
  rtu_DWPC2_InputSig_e, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g)
{
  /* SwitchCase: '<S204>/Switch Case' */
  switch (rtu_DWPC2_InputSig) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S204>/USMSettingControl_Non_NFC' incorporates:
     *  ActionPort: '<S377>/Action Port'
     */
    /* Chart: '<S377>/DWPC2_USMSettingControl2_5' */
    App_Model_DW.C_USMReset_prev_f = App_Model_DW.C_USMReset_start_m;
    App_Model_DW.C_USMReset_start_m = rtu_DWPC2_InputSig_k;
    App_Model_DW.C_WPC2OnOffNValueSet_prev_p = App_Model_DW.C_WPC2OnOffNValueSet_start_m;
    App_Model_DW.C_WPC2OnOffNValueSet_start_m = rtu_DWPC2_InputSig_g;
    if (App_Model_DW.is_active_c11_USMSettingControl == 0U) {
      App_Model_DW.C_USMReset_prev_f = rtu_DWPC2_InputSig_k;
      App_Model_DW.C_WPC2OnOffNValueSet_prev_p = rtu_DWPC2_InputSig_g;
      App_Model_DW.is_active_c11_USMSettingControl = 1U;
      App_Model_DW.CurProfile_p = Guest;

      /* 1. */
      switch (rtu_DWPC2_InputSig_gy) {
       case Profile1:
        App_Model_DW.CurProfile_p = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_p = Profile2;
        break;

       case Guest:
        /* 1. */
        break;
      }

      /* 1 */
      switch (App_Model_DW.CurProfile_p) {
       case Profile1:
        App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetOne;

        /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S377>/C_WPC2RValue'
         */
        App__Function_ProfileOneWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetTwo;

        /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S377>/C_WPC2RValue'
         */
        App__Function_ProfileTwoWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
        break;

       default:
        /* 3 */
        App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetGuest;

        /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S377>/C_WPC2RValue'
         */
        Ap_Function_ProfileGuestWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
        break;
      }
    } else {
      /* 1. */
      switch (rtu_DWPC2_InputSig_gy) {
       case Profile1:
        App_Model_DW.CurProfile_p = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_p = Profile2;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_p = Guest;
        break;
      }

      switch (App_Model_DW.is_USMSettingControl_g) {
       case App_Model_IN_WPC2USM_SetGuest:
        /* 1. */
        switch (App_Model_DW.CurProfile_p) {
         case Profile1:
          App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetOne;

          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          App__Function_ProfileOneWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetTwo;

          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          App__Function_ProfileTwoWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;

         default:
          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          Ap_Function_ProfileGuestWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;
        }
        break;

       case App_Model_IN_WPC2USM_SetOne:
        /* 1. */
        switch (App_Model_DW.CurProfile_p) {
         case Guest:
          App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetGuest;

          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          Ap_Function_ProfileGuestWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetTwo;

          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          App__Function_ProfileTwoWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;

         default:
          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          App__Function_ProfileOneWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;
        }
        break;

       default:
        /* case IN_WPC2USM_SetTwo: */
        /* 1. */
        switch (App_Model_DW.CurProfile_p) {
         case Guest:
          App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetGuest;

          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          Ap_Function_ProfileGuestWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;

         case Profile1:
          /* 2. */
          App_Model_DW.is_USMSettingControl_g = App_Model_IN_WPC2USM_SetOne;

          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          App__Function_ProfileOneWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;

         default:
          /* SignalConversion generated from: '<S377>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S377>/C_WPC2RValue'
           */
          App__Function_ProfileTwoWPC2USM(rty_USM_Sig, rty_USM_Sig_g);
          break;
        }
        break;
      }
    }

    /* End of Chart: '<S377>/DWPC2_USMSettingControl2_5' */
    /* End of Outputs for SubSystem: '<S204>/USMSettingControl_Non_NFC' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S204>/USMSettingControl_NFC' incorporates:
     *  ActionPort: '<S376>/Action Port'
     */
    /* Chart: '<S376>/DWPC2_USMSettingControl3_5' */
    App_Model_DW.C_USMReset_prev = App_Model_DW.C_USMReset_start;
    App_Model_DW.C_USMReset_start = rtu_DWPC2_InputSig_k;
    App_Model_DW.C_WPC2OnOffNValueSet_prev = App_Model_DW.C_WPC2OnOffNValueSet_start;
    App_Model_DW.C_WPC2OnOffNValueSet_start = rtu_DWPC2_InputSig_g;
    if (App_Model_DW.is_active_c9_USMSettingControl_ == 0U) {
      App_Model_DW.C_USMReset_prev = rtu_DWPC2_InputSig_k;
      App_Model_DW.C_WPC2OnOffNValueSet_prev = rtu_DWPC2_InputSig_g;
      App_Model_DW.is_active_c9_USMSettingControl_ = 1U;
      App_Model_DW.CurProfile = Guest;

      /* 1. */
      switch (rtu_DWPC2_InputSig_e) {
       case Profile1:
        App_Model_DW.CurProfile = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile = Profile2;
        break;

       case Guest:
        /* 1. */
        break;

       default:
        /* 1. */
        switch (rtu_DWPC2_InputSig_gy) {
         case Profile1:
          App_Model_DW.CurProfile = Profile1;
          break;

         case Profile2:
          /* 1. */
          App_Model_DW.CurProfile = Profile2;
          break;

         case Guest:
          /* 1. */
          break;
        }
        break;
      }

      /* 1 */
      switch (App_Model_DW.CurProfile) {
       case Profile1:
        App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetOne;

        /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S376>/C_WPC2RValue'
         */
        Ap_Function_ProfileOneWPC2USM_n(rty_USM_Sig, rty_USM_Sig_g);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetTwo;

        /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S376>/C_WPC2RValue'
         */
        Ap_Function_ProfileTwoWPC2USM_d(rty_USM_Sig, rty_USM_Sig_g);
        break;

       default:
        /* 3 */
        App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetGuest;

        /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S376>/C_WPC2RValue'
         */
        Function_ProfileGuestWPC2USM_i(rty_USM_Sig, rty_USM_Sig_g);
        break;
      }
    } else {
      /* 1. */
      switch (rtu_DWPC2_InputSig_e) {
       case Profile1:
        App_Model_DW.CurProfile = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile = Profile2;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile = Guest;
        break;

       default:
        /* 1. */
        switch (rtu_DWPC2_InputSig_gy) {
         case Profile1:
          App_Model_DW.CurProfile = Profile1;
          break;

         case Profile2:
          /* 1. */
          App_Model_DW.CurProfile = Profile2;
          break;

         case Guest:
          /* 1. */
          App_Model_DW.CurProfile = Guest;
          break;
        }
        break;
      }

      switch (App_Model_DW.is_USMSettingControl) {
       case App_Model_IN_WPC2USM_SetGuest:
        /* 1. */
        switch (App_Model_DW.CurProfile) {
         case Profile1:
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetOne;

          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Ap_Function_ProfileOneWPC2USM_n(rty_USM_Sig, rty_USM_Sig_g);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetTwo;

          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Ap_Function_ProfileTwoWPC2USM_d(rty_USM_Sig, rty_USM_Sig_g);
          break;

         default:
          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2USM_i(rty_USM_Sig, rty_USM_Sig_g);
          break;
        }
        break;

       case App_Model_IN_WPC2USM_SetOne:
        /* 1. */
        switch (App_Model_DW.CurProfile) {
         case Guest:
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetGuest;

          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2USM_i(rty_USM_Sig, rty_USM_Sig_g);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetTwo;

          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Ap_Function_ProfileTwoWPC2USM_d(rty_USM_Sig, rty_USM_Sig_g);
          break;

         default:
          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Ap_Function_ProfileOneWPC2USM_n(rty_USM_Sig, rty_USM_Sig_g);
          break;
        }
        break;

       default:
        /* case IN_WPC2USM_SetTwo: */
        /* 1. */
        switch (App_Model_DW.CurProfile) {
         case Guest:
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetGuest;

          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2USM_i(rty_USM_Sig, rty_USM_Sig_g);
          break;

         case Profile1:
          /* 2. */
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPC2USM_SetOne;

          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Ap_Function_ProfileOneWPC2USM_n(rty_USM_Sig, rty_USM_Sig_g);
          break;

         default:
          /* SignalConversion generated from: '<S376>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S376>/C_WPC2RValue'
           */
          Ap_Function_ProfileTwoWPC2USM_d(rty_USM_Sig, rty_USM_Sig_g);
          break;
        }
        break;
      }
    }

    /* End of Chart: '<S376>/DWPC2_USMSettingControl3_5' */
    /* End of Outputs for SubSystem: '<S204>/USMSettingControl_NFC' */
    break;
  }

  /* End of SwitchCase: '<S204>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
