/*
 * File: USMSettingControl_Function.c
 *
 * Code generated for Simulink model 'App_Model'.
 *
 * Model version                  : 1.929
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Jun 20 10:50:52 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "USMSettingControl_Function.h"
#include "App_Model_types.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S205>/WPC_USMSettingControl2_M' */
#define App_Mod_IN_NO_ACTIVE_CHILD_bjbf ((uint8)0U)
#define App_Mod_IN_WPCUSM_SetGuest_kuit ((uint8)1U)
#define App_Mod_IN_WPCUSM_SetThree_l3id ((uint8)3U)
#define App_Model_IN_WPCUSM_SetOne_ks4t ((uint8)2U)
#define App_Model_IN_WPCUSM_SetTwo_pdke ((uint8)4U)

/* Named constants for Chart: '<S204>/WPC_USMSettingControl3_M' */
#define App_Mod_IN_NO_ACTIVE_CHILD_hiau ((uint8)0U)
#define App_Mod_IN_WPCUSM_SetGuest_k54k ((uint8)1U)
#define App_Mod_IN_WPCUSM_SetThree_niui ((uint8)3U)
#define App_Model_IN_WPCUSM_SetOne_jzk0 ((uint8)2U)
#define App_Model_IN_WPCUSM_SetTwo_khmn ((uint8)4U)

/* Named constants for Chart: '<S395>/WPC2_USMSettingControl2_M' */
#define App_Mod_IN_NO_ACTIVE_CHILD_grlm ((uint8)0U)
#define App_Mod_IN_WPCUSM_SetGuest_cioi ((uint8)1U)
#define App_Mod_IN_WPCUSM_SetThree_lxqi ((uint8)3U)
#define App_Model_IN_WPCUSM_SetOne_jo14 ((uint8)2U)
#define App_Model_IN_WPCUSM_SetTwo_i53u ((uint8)4U)

/* Forward declaration for local functions */
static void Function_ProfileThreeWPCUS_o2t0(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW);
static void Function_ProfileGuestWPCUS_p1mo(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW);
static void Function_ProfileOneWPCUSM_mpqh(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW);
static void Function_ProfileTwoWPCUSM_eblv(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW);

/* Forward declaration for local functions */
static void Function_ProfileThreeWPCUS_onmm(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW);
static void Function_ProfileGuestWPCUS_kst4(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW);
static void Function_ProfileOneWPCUSM_dftb(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW);
static void Function_ProfileTwoWPCUSM_frrx(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW);

/* Forward declaration for local functions */
static void Function_ProfileGuestWPC2U_en4t(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0);
static void Function_ProfileOneWPC2USM_jyjf(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0);
static void Function_ProfileThreeWPC2U_oo4x(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0);
static void Function_ProfileTwoWPC2USM_kdjh(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0);
static void Function_ProfileGuestWPC2U_lotx(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje);
static void Function_ProfileOneWPC2USM_cpnm(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje);
static void Function_ProfileThreeWPC2U_bv5c(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje);
static void Function_ProfileTwoWPC2USM_n0vz(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje);

/* Function for Chart: '<S205>/WPC_USMSettingControl2_M' */
static void Function_ProfileThreeWPCUS_o2t0(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileThreeWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileThreeWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileThreeWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileThreeWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileThreeWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S205>/WPC_USMSettingControl2_M' */
static void Function_ProfileGuestWPCUS_p1mo(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileGuestWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileGuestWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S205>/WPC_USMSettingControl2_M' */
static void Function_ProfileOneWPCUSM_mpqh(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileOneWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileOneWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S205>/WPC_USMSettingControl2_M' */
static void Function_ProfileTwoWPCUSM_eblv(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileTwoWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileTwoWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/*
 * System initialize for action system:
 *    '<S24>/USMSettingControl_Non_NFC'
 *    '<S641>/USMSettingControl_Non_NFC'
 */
void USMSettingControl_Non_NFC_Init(DW_USMSettingControl_Non_NFC__T *localDW)
{
  /* SystemInitialize for Chart: '<S205>/WPC_USMSettingControl2_M' */
  localDW->is_USMSettingControl = App_Mod_IN_NO_ACTIVE_CHILD_bjbf;
  localDW->is_active_c17_USMSettingControl = 0U;
  localDW->CurProfile = ProfileC_ProfileIDRValueDefault;
  localDW->C_USMReset_prev = USMDefault;
  localDW->C_USMReset_start = USMDefault;
  localDW->C_WPCOnOffNValueSet_prev = WPC_On;
  localDW->C_WPCOnOffNValueSet_start = WPC_On;
}

/*
 * Output and update for action system:
 *    '<S24>/USMSettingControl_Non_NFC'
 *    '<S641>/USMSettingControl_Non_NFC'
 */
void App_M_USMSettingControl_Non_NFC(C_WPCOnOffNvalueSet rtu_C_WPCOnOffNValueSet, C_USMReset rtu_C_USMReset, C_ProfileIDRValue rtu_C_CF_AVN_ProfileIDRValue, C_WPCOnOffNvalueSet *rty_C_WPCRValue,
  C_WPCOnOffNvalueSet *rty_WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW)
{
  /* Chart: '<S205>/WPC_USMSettingControl2_M' */
  localDW->C_USMReset_prev = localDW->C_USMReset_start;
  localDW->C_USMReset_start = rtu_C_USMReset;
  localDW->C_WPCOnOffNValueSet_prev = localDW->C_WPCOnOffNValueSet_start;
  localDW->C_WPCOnOffNValueSet_start = rtu_C_WPCOnOffNValueSet;
  if ((uint32)localDW->is_active_c17_USMSettingControl == 0U) {
    localDW->C_USMReset_prev = rtu_C_USMReset;
    localDW->C_WPCOnOffNValueSet_prev = rtu_C_WPCOnOffNValueSet;
    localDW->is_active_c17_USMSettingControl = 1U;
    localDW->CurProfile = Profile1;

    /* 1. */
    switch (rtu_C_CF_AVN_ProfileIDRValue) {
     case Profile1:
      break;

     case Profile2:
      /* 1. */
      localDW->CurProfile = Profile2;
      break;

     case Profile3:
      /* 1. */
      localDW->CurProfile = Profile3;
      break;

     case Guest:
      /* 1. */
      localDW->CurProfile = Guest;
      break;

     default:
      /* no actions */
      break;
    }

    /* 1 */
    switch (localDW->CurProfile) {
     case Profile1:
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_ks4t;

      /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S205>/C_WPCRValue'
       */
      Function_ProfileOneWPCUSM_mpqh(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;

     case Profile2:
      /* 2 */
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_pdke;

      /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S205>/C_WPCRValue'
       */
      Function_ProfileTwoWPCUSM_eblv(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;

     case Profile3:
      localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_l3id;

      /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S205>/C_WPCRValue'
       */
      Function_ProfileThreeWPCUS_o2t0(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;

     default:
      /* 4 */
      localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_kuit;

      /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S205>/C_WPCRValue'
       */
      Function_ProfileGuestWPCUS_p1mo(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;
    }
  } else {
    /* 1. */
    switch (rtu_C_CF_AVN_ProfileIDRValue) {
     case Profile1:
      localDW->CurProfile = Profile1;
      break;

     case Profile2:
      /* 1. */
      localDW->CurProfile = Profile2;
      break;

     case Profile3:
      /* 1. */
      localDW->CurProfile = Profile3;
      break;

     case Guest:
      /* 1. */
      localDW->CurProfile = Guest;
      break;

     default:
      /* no actions */
      break;
    }

    switch (localDW->is_USMSettingControl) {
     case App_Mod_IN_WPCUSM_SetGuest_kuit:
      /* 1. */
      switch (localDW->CurProfile) {
       case Profile1:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_ks4t;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_mpqh(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile2:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_pdke;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_eblv(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_l3id;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_o2t0(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_p1mo(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;

     case App_Model_IN_WPCUSM_SetOne_ks4t:
      /* 1. */
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_kuit;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_p1mo(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile2:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_pdke;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_eblv(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_l3id;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_o2t0(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_mpqh(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;

     case App_Mod_IN_WPCUSM_SetThree_l3id:
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_kuit;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_p1mo(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile1:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_ks4t;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_mpqh(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile2:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_pdke;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_eblv(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_o2t0(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;

     default:
      /* case IN_WPCUSM_SetTwo: */
      /* 1. */
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_kuit;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_p1mo(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile1:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_ks4t;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_mpqh(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_l3id;

        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_o2t0(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S205>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S205>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_eblv(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S205>/WPC_USMSettingControl2_M' */
}

/* Function for Chart: '<S204>/WPC_USMSettingControl3_M' */
static void Function_ProfileThreeWPCUS_onmm(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileThreeWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileThreeWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileThreeWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileThreeWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileThreeWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S204>/WPC_USMSettingControl3_M' */
static void Function_ProfileGuestWPCUS_kst4(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileGuestWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileGuestWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S204>/WPC_USMSettingControl3_M' */
static void Function_ProfileOneWPCUSM_dftb(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileOneWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileOneWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileOneWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S204>/WPC_USMSettingControl3_M' */
static void Function_ProfileTwoWPCUSM_frrx(C_WPCOnOffNvalueSet *C_WPCRValue, C_WPCOnOffNvalueSet *WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_On)) {
    *C_WPCRValue = WPC_On;
    *WPCSWOption = WPC_On;
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((localDW->C_WPCOnOffNValueSet_prev != localDW->C_WPCOnOffNValueSet_start) && ((uint32)localDW->C_WPCOnOffNValueSet_start == WPC_Off)) {
    *C_WPCRValue = WPC_Off;
    *WPCSWOption = WPC_Off;
    m_ProfileTwoWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPCUSM_App) {
     case WPC_On:
      *C_WPCRValue = WPC_On;
      *WPCSWOption = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      break;

     default:
      *C_WPCRValue = WPC_Off;
      *WPCSWOption = WPC_Off;
      m_ProfileTwoWPCUSM_App = WPC_Off;
      break;
    }
  }
}

/*
 * System initialize for action system:
 *    '<S24>/USMSettingControl_NFC'
 *    '<S641>/USMSettingControl_NFC'
 */
void App__USMSettingControl_NFC_Init(DW_USMSettingControl_NFC_App__T *localDW)
{
  /* SystemInitialize for Chart: '<S204>/WPC_USMSettingControl3_M' */
  localDW->is_USMSettingControl = App_Mod_IN_NO_ACTIVE_CHILD_hiau;
  localDW->is_active_c18_USMSettingControl = 0U;
  localDW->CurProfile = ProfileC_ProfileIDRValueDefault;
  localDW->C_USMReset_prev = USMDefault;
  localDW->C_USMReset_start = USMDefault;
  localDW->C_WPCOnOffNValueSet_prev = WPC_On;
  localDW->C_WPCOnOffNValueSet_start = WPC_On;
}

/*
 * Output and update for action system:
 *    '<S24>/USMSettingControl_NFC'
 *    '<S641>/USMSettingControl_NFC'
 */
void App_Model_USMSettingControl_NFC(C_WPCOnOffNvalueSet rtu_C_WPCOnOffNValueSet, C_USMReset rtu_C_USMReset, C_ProfileIDRValue rtu_C_IAU_ProfileIDRVal, C_ProfileIDRValue rtu_C_CF_AVN_ProfileIDRValue,
  C_WPCOnOffNvalueSet *rty_C_WPCRValue, C_WPCOnOffNvalueSet *rty_WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW)
{
  /* Chart: '<S204>/WPC_USMSettingControl3_M' */
  localDW->C_USMReset_prev = localDW->C_USMReset_start;
  localDW->C_USMReset_start = rtu_C_USMReset;
  localDW->C_WPCOnOffNValueSet_prev = localDW->C_WPCOnOffNValueSet_start;
  localDW->C_WPCOnOffNValueSet_start = rtu_C_WPCOnOffNValueSet;
  if ((uint32)localDW->is_active_c18_USMSettingControl == 0U) {
    localDW->C_USMReset_prev = rtu_C_USMReset;
    localDW->C_WPCOnOffNValueSet_prev = rtu_C_WPCOnOffNValueSet;
    localDW->is_active_c18_USMSettingControl = 1U;
    localDW->CurProfile = Profile1;

    /* 1. */
    switch (rtu_C_IAU_ProfileIDRVal) {
     case Profile1:
      break;

     case Profile2:
      /* 1. */
      localDW->CurProfile = Profile2;
      break;

     case Profile3:
      /* 1. */
      localDW->CurProfile = Profile3;
      break;

     case Guest:
      /* 1. */
      localDW->CurProfile = Guest;
      break;

     default:
      /* 1. */
      switch (rtu_C_CF_AVN_ProfileIDRValue) {
       case Profile1:
        break;

       case Profile2:
        /* 1. */
        localDW->CurProfile = Profile2;
        break;

       case Profile3:
        /* 1. */
        localDW->CurProfile = Profile3;
        break;

       case Guest:
        /* 1. */
        localDW->CurProfile = Guest;
        break;

       default:
        /* no actions */
        break;
      }
      break;
    }

    /* 1 */
    switch (localDW->CurProfile) {
     case Profile1:
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jzk0;

      /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S204>/C_WPCRValue'
       */
      Function_ProfileOneWPCUSM_dftb(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;

     case Profile2:
      /* 2 */
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_khmn;

      /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S204>/C_WPCRValue'
       */
      Function_ProfileTwoWPCUSM_frrx(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;

     case Profile3:
      localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_niui;

      /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S204>/C_WPCRValue'
       */
      Function_ProfileThreeWPCUS_onmm(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;

     default:
      /* 4 */
      localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_k54k;

      /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
       *  SignalConversion generated from: '<S204>/C_WPCRValue'
       */
      Function_ProfileGuestWPCUS_kst4(rty_C_WPCRValue, rty_WPCSWOption, localDW);
      break;
    }
  } else {
    /* 1. */
    switch (rtu_C_IAU_ProfileIDRVal) {
     case Profile1:
      localDW->CurProfile = Profile1;
      break;

     case Profile2:
      /* 1. */
      localDW->CurProfile = Profile2;
      break;

     case Profile3:
      /* 1. */
      localDW->CurProfile = Profile3;
      break;

     case Guest:
      /* 1. */
      localDW->CurProfile = Guest;
      break;

     default:
      /* 1. */
      switch (rtu_C_CF_AVN_ProfileIDRValue) {
       case Profile1:
        localDW->CurProfile = Profile1;
        break;

       case Profile2:
        /* 1. */
        localDW->CurProfile = Profile2;
        break;

       case Profile3:
        /* 1. */
        localDW->CurProfile = Profile3;
        break;

       case Guest:
        /* 1. */
        localDW->CurProfile = Guest;
        break;

       default:
        /* no actions */
        break;
      }
      break;
    }

    switch (localDW->is_USMSettingControl) {
     case App_Mod_IN_WPCUSM_SetGuest_k54k:
      /* 1. */
      switch (localDW->CurProfile) {
       case Profile1:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jzk0;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_dftb(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile2:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_khmn;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_frrx(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_niui;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_onmm(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_kst4(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;

     case App_Model_IN_WPCUSM_SetOne_jzk0:
      /* 1. */
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_k54k;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_kst4(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile2:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_khmn;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_frrx(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_niui;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_onmm(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_dftb(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;

     case App_Mod_IN_WPCUSM_SetThree_niui:
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_k54k;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_kst4(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile1:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jzk0;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_dftb(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile2:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_khmn;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_frrx(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_onmm(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;

     default:
      /* case IN_WPCUSM_SetTwo: */
      /* 1. */
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_k54k;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileGuestWPCUS_kst4(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile1:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jzk0;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileOneWPCUSM_dftb(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_niui;

        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileThreeWPCUS_onmm(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;

       default:
        /* SignalConversion generated from: '<S204>/WPCSWOption' incorporates:
         *  SignalConversion generated from: '<S204>/C_WPCRValue'
         */
        Function_ProfileTwoWPCUSM_frrx(rty_C_WPCRValue, rty_WPCSWOption, localDW);
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S204>/WPC_USMSettingControl3_M' */
}

/* System initialize for atomic system: '<S19>/USMSettingControl_Function' */
void USMSettingControl_Function_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_bklu)
{
  /* SystemInitialize for IfAction SubSystem: '<S24>/USMSettingControl_Non_NFC' */
  USMSettingControl_Non_NFC_Init(&App_Model_DW.USMSettingControl_Non_NFC);

  /* End of SystemInitialize for SubSystem: '<S24>/USMSettingControl_Non_NFC' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/USMSettingControl_NFC' */
  App__USMSettingControl_NFC_Init(&App_Model_DW.USMSettingControl_NFC);

  /* End of SystemInitialize for SubSystem: '<S24>/USMSettingControl_NFC' */

  /* SystemInitialize for Merge generated from: '<S24>/Merge' */
  *rty_USM_Sig = WPC_On;

  /* SystemInitialize for Merge generated from: '<S24>/Merge' */
  *rty_USM_Sig_bklu = WPC_On;
}

/* Output and update for atomic system: '<S19>/USMSettingControl_Function' */
void App__USMSettingControl_Function(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_bklu, C_USMReset rtu_InputSig_de4j, C_ProfileIDRValue rtu_InputSig_izcl, C_ProfileIDRValue rtu_InputSig_hvqe,
  C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_bklu)
{
  /* SwitchCase: '<S24>/Switch Case' */
  switch (rtu_InputSig) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S24>/USMSettingControl_Non_NFC' incorporates:
     *  ActionPort: '<S205>/ActionPort'
     */
    App_M_USMSettingControl_Non_NFC(rtu_InputSig_bklu, rtu_InputSig_de4j, rtu_InputSig_izcl, rty_USM_Sig, rty_USM_Sig_bklu, &App_Model_DW.USMSettingControl_Non_NFC);

    /* End of Outputs for SubSystem: '<S24>/USMSettingControl_Non_NFC' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S24>/USMSettingControl_NFC' incorporates:
     *  ActionPort: '<S204>/ActionPort'
     */
    App_Model_USMSettingControl_NFC(rtu_InputSig_bklu, rtu_InputSig_de4j, rtu_InputSig_hvqe, rtu_InputSig_izcl, rty_USM_Sig, rty_USM_Sig_bklu, &App_Model_DW.USMSettingControl_NFC);

    /* End of Outputs for SubSystem: '<S24>/USMSettingControl_NFC' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S24>/Switch Case' */
}

/* Function for Chart: '<S395>/WPC2_USMSettingControl2_M' */
static void Function_ProfileGuestWPC2U_en4t(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_obzw != App_Model_DW.C_USMReset_start_gxle) && ((uint32)App_Model_DW.C_USMReset_start_gxle == USMReset)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_On)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_Off)) {
    *C_WPC2RValue_jhot = WPC_Off;
    *WPC2SWOption_hju0 = WPC_Off;
    m_ProfileGuestWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_jhot = WPC_On;
      *WPC2SWOption_hju0 = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      break;

     default:
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      m_ProfileGuestWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S395>/WPC2_USMSettingControl2_M' */
static void Function_ProfileOneWPC2USM_jyjf(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_obzw != App_Model_DW.C_USMReset_start_gxle) && ((uint32)App_Model_DW.C_USMReset_start_gxle == USMReset)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_On)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_Off)) {
    *C_WPC2RValue_jhot = WPC_Off;
    *WPC2SWOption_hju0 = WPC_Off;
    m_ProfileOneWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_jhot = WPC_On;
      *WPC2SWOption_hju0 = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      break;

     default:
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      m_ProfileOneWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S395>/WPC2_USMSettingControl2_M' */
static void Function_ProfileThreeWPC2U_oo4x(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_obzw != App_Model_DW.C_USMReset_start_gxle) && ((uint32)App_Model_DW.C_USMReset_start_gxle == USMReset)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileThreeWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_On)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileThreeWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_Off)) {
    *C_WPC2RValue_jhot = WPC_Off;
    *WPC2SWOption_hju0 = WPC_Off;
    m_ProfileThreeWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileThreeWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_jhot = WPC_On;
      *WPC2SWOption_hju0 = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      break;

     default:
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      m_ProfileThreeWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S395>/WPC2_USMSettingControl2_M' */
static void Function_ProfileTwoWPC2USM_kdjh(C_WPCOnOffNvalueSet *C_WPC2RValue_jhot, C_WPCOnOffNvalueSet *WPC2SWOption_hju0)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_obzw != App_Model_DW.C_USMReset_start_gxle) && ((uint32)App_Model_DW.C_USMReset_start_gxle == USMReset)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_On)) {
    *C_WPC2RValue_jhot = WPC_On;
    *WPC2SWOption_hju0 = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 != App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc == WPC_Off)) {
    *C_WPC2RValue_jhot = WPC_Off;
    *WPC2SWOption_hju0 = WPC_Off;
    m_ProfileTwoWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue_jhot = WPC_On;
      *WPC2SWOption_hju0 = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      break;

     default:
      *C_WPC2RValue_jhot = WPC_Off;
      *WPC2SWOption_hju0 = WPC_Off;
      m_ProfileTwoWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S394>/WPC2_USMSettingControl3_M' */
static void Function_ProfileGuestWPC2U_lotx(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_lykt != App_Model_DW.C_USMReset_start_dato) && ((uint32)App_Model_DW.C_USMReset_start_dato == USMReset)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue = WPC_Off;
    *WPCSWOption_mcje = WPC_Off;
    m_ProfileGuestWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue = WPC_On;
      *WPCSWOption_mcje = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      break;

     default:
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      m_ProfileGuestWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S394>/WPC2_USMSettingControl3_M' */
static void Function_ProfileOneWPC2USM_cpnm(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_lykt != App_Model_DW.C_USMReset_start_dato) && ((uint32)App_Model_DW.C_USMReset_start_dato == USMReset)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileOneWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue = WPC_Off;
    *WPCSWOption_mcje = WPC_Off;
    m_ProfileOneWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileOneWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue = WPC_On;
      *WPCSWOption_mcje = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      break;

     default:
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      m_ProfileOneWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S394>/WPC2_USMSettingControl3_M' */
static void Function_ProfileThreeWPC2U_bv5c(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_lykt != App_Model_DW.C_USMReset_start_dato) && ((uint32)App_Model_DW.C_USMReset_start_dato == USMReset)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileThreeWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileThreeWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue = WPC_Off;
    *WPCSWOption_mcje = WPC_Off;
    m_ProfileThreeWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileThreeWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue = WPC_On;
      *WPCSWOption_mcje = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      break;

     default:
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      m_ProfileThreeWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* Function for Chart: '<S394>/WPC2_USMSettingControl3_M' */
static void Function_ProfileTwoWPC2USM_n0vz(C_WPCOnOffNvalueSet *C_WPC2RValue, C_WPCOnOffNvalueSet *WPCSWOption_mcje)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_lykt != App_Model_DW.C_USMReset_start_dato) && ((uint32)App_Model_DW.C_USMReset_start_dato == USMReset)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_On)) {
    *C_WPC2RValue = WPC_On;
    *WPCSWOption_mcje = WPC_On;
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_WPC2OnOffNValueSet_prev != App_Model_DW.C_WPC2OnOffNValueSet_start) && ((uint32)App_Model_DW.C_WPC2OnOffNValueSet_start == WPC_Off)) {
    *C_WPC2RValue = WPC_Off;
    *WPCSWOption_mcje = WPC_Off;
    m_ProfileTwoWPC2USM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPC2USM_App) {
     case WPC_On:
      *C_WPC2RValue = WPC_On;
      *WPCSWOption_mcje = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      break;

     default:
      *C_WPC2RValue = WPC_Off;
      *WPCSWOption_mcje = WPC_Off;
      m_ProfileTwoWPC2USM_App = WPC_Off;
      break;
    }
  }
}

/* System initialize for atomic system: '<S20>/USMSettingControl_Function' */
void USMSettingControl_Fun_dunh_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_gnez)
{
  /* SystemInitialize for IfAction SubSystem: '<S219>/USMSettingControl_Non_NFC' */
  /* SystemInitialize for Chart: '<S395>/WPC2_USMSettingControl2_M' */
  App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_NO_ACTIVE_CHILD_grlm;
  App_Model_DW.is_active_c19_USMSettingControl = 0U;
  App_Model_DW.CurProfile_atpd = ProfileC_ProfileIDRValueDefault;
  App_Model_DW.C_USMReset_prev_obzw = USMDefault;
  App_Model_DW.C_USMReset_start_gxle = USMDefault;
  App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 = WPC_On;
  App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S219>/USMSettingControl_Non_NFC' */

  /* SystemInitialize for IfAction SubSystem: '<S219>/USMSettingControl_NFC' */
  /* SystemInitialize for Chart: '<S394>/WPC2_USMSettingControl3_M' incorporates:
   *  Chart: '<S395>/WPC2_USMSettingControl2_M'
   */
  App_Model_DW.is_USMSettingControl = App_Mod_IN_NO_ACTIVE_CHILD_grlm;
  App_Model_DW.is_active_c20_USMSettingControl = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S219>/USMSettingControl_Non_NFC' */
  App_Model_DW.CurProfile = ProfileC_ProfileIDRValueDefault;
  App_Model_DW.C_USMReset_prev_lykt = USMDefault;
  App_Model_DW.C_USMReset_start_dato = USMDefault;
  App_Model_DW.C_WPC2OnOffNValueSet_prev = WPC_On;
  App_Model_DW.C_WPC2OnOffNValueSet_start = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S219>/USMSettingControl_Non_NFC' */
  /* End of SystemInitialize for SubSystem: '<S219>/USMSettingControl_NFC' */

  /* SystemInitialize for Merge generated from: '<S219>/Merge' */
  *rty_USM_Sig = WPC_On;

  /* SystemInitialize for Merge generated from: '<S219>/Merge' */
  *rty_USM_Sig_gnez = WPC_On;
}

/* Output and update for atomic system: '<S20>/USMSettingControl_Function' */
void USMSettingControl_Function_hux4(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_gnez, C_USMReset rtu_InputSig_knyt, C_ProfileIDRValue rtu_InputSig_gykk, C_ProfileIDRValue rtu_InputSig_es0h,
  C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_gnez)
{
  /* SwitchCase: '<S219>/Switch Case' */
  switch (rtu_InputSig) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S219>/USMSettingControl_Non_NFC' incorporates:
     *  ActionPort: '<S395>/ActionPort'
     */
    /* Chart: '<S395>/WPC2_USMSettingControl2_M' */
    App_Model_DW.C_USMReset_prev_obzw = App_Model_DW.C_USMReset_start_gxle;
    App_Model_DW.C_USMReset_start_gxle = rtu_InputSig_knyt;
    App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 = App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc;
    App_Model_DW.C_WPC2OnOffNValueSet_start_k0sc = rtu_InputSig_gnez;
    if ((uint32)App_Model_DW.is_active_c19_USMSettingControl == 0U) {
      App_Model_DW.C_USMReset_prev_obzw = rtu_InputSig_knyt;
      App_Model_DW.C_WPC2OnOffNValueSet_prev_kgo2 = rtu_InputSig_gnez;
      App_Model_DW.is_active_c19_USMSettingControl = 1U;
      App_Model_DW.CurProfile_atpd = Profile1;

      /* 1. */
      switch (rtu_InputSig_gykk) {
       case Profile1:
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_atpd = Profile2;
        break;

       case Profile3:
        /* 1. */
        App_Model_DW.CurProfile_atpd = Profile3;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_atpd = Guest;
        break;

       default:
        /* no actions */
        break;
      }

      /* 1 */
      switch (App_Model_DW.CurProfile_atpd) {
       case Profile1:
        App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetOne_jo14;

        /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S395>/C_WPC2RValue'
         */
        Function_ProfileOneWPC2USM_jyjf(rty_USM_Sig, rty_USM_Sig_gnez);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetTwo_i53u;

        /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S395>/C_WPC2RValue'
         */
        Function_ProfileTwoWPC2USM_kdjh(rty_USM_Sig, rty_USM_Sig_gnez);
        break;

       case Profile3:
        App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetThree_lxqi;

        /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S395>/C_WPC2RValue'
         */
        Function_ProfileThreeWPC2U_oo4x(rty_USM_Sig, rty_USM_Sig_gnez);
        break;

       default:
        /* 4 */
        App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetGuest_cioi;

        /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S395>/C_WPC2RValue'
         */
        Function_ProfileGuestWPC2U_en4t(rty_USM_Sig, rty_USM_Sig_gnez);
        break;
      }
    } else {
      /* 1. */
      switch (rtu_InputSig_gykk) {
       case Profile1:
        App_Model_DW.CurProfile_atpd = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_atpd = Profile2;
        break;

       case Profile3:
        /* 1. */
        App_Model_DW.CurProfile_atpd = Profile3;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_atpd = Guest;
        break;

       default:
        /* no actions */
        break;
      }

      switch (App_Model_DW.is_USMSettingControl_m50o) {
       case App_Mod_IN_WPCUSM_SetGuest_cioi:
        /* 1. */
        switch (App_Model_DW.CurProfile_atpd) {
         case Profile1:
          App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetOne_jo14;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_jyjf(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetTwo_i53u;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_kdjh(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile3:
          App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetThree_lxqi;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_oo4x(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_en4t(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;

       case App_Model_IN_WPCUSM_SetOne_jo14:
        /* 1. */
        switch (App_Model_DW.CurProfile_atpd) {
         case Guest:
          App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetGuest_cioi;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_en4t(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetTwo_i53u;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_kdjh(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile3:
          App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetThree_lxqi;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_oo4x(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_jyjf(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;

       case App_Mod_IN_WPCUSM_SetThree_lxqi:
        switch (App_Model_DW.CurProfile_atpd) {
         case Guest:
          App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetGuest_cioi;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_en4t(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile1:
          App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetOne_jo14;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_jyjf(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile2:
          App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetTwo_i53u;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_kdjh(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_oo4x(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;

       default:
        /* case IN_WPCUSM_SetTwo: */
        /* 1. */
        switch (App_Model_DW.CurProfile_atpd) {
         case Guest:
          App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetGuest_cioi;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_en4t(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile1:
          /* 2. */
          App_Model_DW.is_USMSettingControl_m50o = App_Model_IN_WPCUSM_SetOne_jo14;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_jyjf(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile3:
          App_Model_DW.is_USMSettingControl_m50o = App_Mod_IN_WPCUSM_SetThree_lxqi;

          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_oo4x(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S395>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S395>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_kdjh(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;
      }
    }

    /* End of Chart: '<S395>/WPC2_USMSettingControl2_M' */
    /* End of Outputs for SubSystem: '<S219>/USMSettingControl_Non_NFC' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S219>/USMSettingControl_NFC' incorporates:
     *  ActionPort: '<S394>/ActionPort'
     */
    /* Chart: '<S394>/WPC2_USMSettingControl3_M' */
    App_Model_DW.C_USMReset_prev_lykt = App_Model_DW.C_USMReset_start_dato;
    App_Model_DW.C_USMReset_start_dato = rtu_InputSig_knyt;
    App_Model_DW.C_WPC2OnOffNValueSet_prev = App_Model_DW.C_WPC2OnOffNValueSet_start;
    App_Model_DW.C_WPC2OnOffNValueSet_start = rtu_InputSig_gnez;
    if ((uint32)App_Model_DW.is_active_c20_USMSettingControl == 0U) {
      App_Model_DW.C_USMReset_prev_lykt = rtu_InputSig_knyt;
      App_Model_DW.C_WPC2OnOffNValueSet_prev = rtu_InputSig_gnez;
      App_Model_DW.is_active_c20_USMSettingControl = 1U;
      App_Model_DW.CurProfile = Profile1;

      /* 1. */
      switch (rtu_InputSig_es0h) {
       case Profile1:
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile = Profile2;
        break;

       case Profile3:
        /* 1. */
        App_Model_DW.CurProfile = Profile3;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile = Guest;
        break;

       default:
        /* 1. */
        switch (rtu_InputSig_gykk) {
         case Profile1:
          break;

         case Profile2:
          /* 1. */
          App_Model_DW.CurProfile = Profile2;
          break;

         case Profile3:
          /* 1. */
          App_Model_DW.CurProfile = Profile3;
          break;

         case Guest:
          /* 1. */
          App_Model_DW.CurProfile = Guest;
          break;

         default:
          /* no actions */
          break;
        }
        break;
      }

      /* 1 */
      switch (App_Model_DW.CurProfile) {
       case Profile1:
        App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jo14;

        /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S394>/C_WPC2RValue'
         */
        Function_ProfileOneWPC2USM_cpnm(rty_USM_Sig, rty_USM_Sig_gnez);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_i53u;

        /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S394>/C_WPC2RValue'
         */
        Function_ProfileTwoWPC2USM_n0vz(rty_USM_Sig, rty_USM_Sig_gnez);
        break;

       case Profile3:
        App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_lxqi;

        /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S394>/C_WPC2RValue'
         */
        Function_ProfileThreeWPC2U_bv5c(rty_USM_Sig, rty_USM_Sig_gnez);
        break;

       default:
        /* 4 */
        App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_cioi;

        /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
         *  SignalConversion generated from: '<S394>/C_WPC2RValue'
         */
        Function_ProfileGuestWPC2U_lotx(rty_USM_Sig, rty_USM_Sig_gnez);
        break;
      }
    } else {
      /* 1. */
      switch (rtu_InputSig_es0h) {
       case Profile1:
        App_Model_DW.CurProfile = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile = Profile2;
        break;

       case Profile3:
        /* 1. */
        App_Model_DW.CurProfile = Profile3;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile = Guest;
        break;

       default:
        /* 1. */
        switch (rtu_InputSig_gykk) {
         case Profile1:
          App_Model_DW.CurProfile = Profile1;
          break;

         case Profile2:
          /* 1. */
          App_Model_DW.CurProfile = Profile2;
          break;

         case Profile3:
          /* 1. */
          App_Model_DW.CurProfile = Profile3;
          break;

         case Guest:
          /* 1. */
          App_Model_DW.CurProfile = Guest;
          break;

         default:
          /* no actions */
          break;
        }
        break;
      }

      switch (App_Model_DW.is_USMSettingControl) {
       case App_Mod_IN_WPCUSM_SetGuest_cioi:
        /* 1. */
        switch (App_Model_DW.CurProfile) {
         case Profile1:
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jo14;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_cpnm(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_i53u;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_n0vz(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile3:
          App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_lxqi;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_bv5c(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_lotx(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;

       case App_Model_IN_WPCUSM_SetOne_jo14:
        /* 1. */
        switch (App_Model_DW.CurProfile) {
         case Guest:
          App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_cioi;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_lotx(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile2:
          /* 2. */
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_i53u;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_n0vz(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile3:
          App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_lxqi;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_bv5c(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_cpnm(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;

       case App_Mod_IN_WPCUSM_SetThree_lxqi:
        switch (App_Model_DW.CurProfile) {
         case Guest:
          App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_cioi;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_lotx(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile1:
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jo14;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_cpnm(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile2:
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo_i53u;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_n0vz(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_bv5c(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;

       default:
        /* case IN_WPCUSM_SetTwo: */
        /* 1. */
        switch (App_Model_DW.CurProfile) {
         case Guest:
          App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetGuest_cioi;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileGuestWPC2U_lotx(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile1:
          /* 2. */
          App_Model_DW.is_USMSettingControl = App_Model_IN_WPCUSM_SetOne_jo14;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileOneWPC2USM_cpnm(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         case Profile3:
          App_Model_DW.is_USMSettingControl = App_Mod_IN_WPCUSM_SetThree_lxqi;

          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileThreeWPC2U_bv5c(rty_USM_Sig, rty_USM_Sig_gnez);
          break;

         default:
          /* SignalConversion generated from: '<S394>/WPC2SWOption' incorporates:
           *  SignalConversion generated from: '<S394>/C_WPC2RValue'
           */
          Function_ProfileTwoWPC2USM_n0vz(rty_USM_Sig, rty_USM_Sig_gnez);
          break;
        }
        break;
      }
    }

    /* End of Chart: '<S394>/WPC2_USMSettingControl3_M' */
    /* End of Outputs for SubSystem: '<S219>/USMSettingControl_NFC' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S219>/Switch Case' */
}

/* System initialize for atomic system: '<S461>/USMSettingControl_Function' */
void USMSettingControl_Fun_o1by_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_eyil)
{
  /* SystemInitialize for Chart: '<S606>/USMSettingControlRWPC' */
  App_Model_DW.is_active_c6_USMSettingControl_ = 0U;
  *rty_USM_Sig = WPC_On;
  *rty_USM_Sig_eyil = WPC_On;
  App_Model_DW.C_USMReset_prev = USMDefault;
  App_Model_DW.C_USMReset_start = USMDefault;
  App_Model_DW.C_RWPCOnOffNValueSet_prev = WPC_On;
  App_Model_DW.C_RWPCOnOffNValueSet_start = WPC_On;
}

/* System reset for atomic system: '<S461>/USMSettingControl_Function' */
void USMSettingControl_Fu_p40r_Reset(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_eyil)
{
  /* SystemReset for Chart: '<S606>/USMSettingControlRWPC' */
  App_Model_DW.is_active_c6_USMSettingControl_ = 0U;
  *rty_USM_Sig = WPC_On;
  *rty_USM_Sig_eyil = WPC_On;
  App_Model_DW.C_USMReset_prev = USMDefault;
  App_Model_DW.C_USMReset_start = USMDefault;
  App_Model_DW.C_RWPCOnOffNValueSet_prev = WPC_On;
  App_Model_DW.C_RWPCOnOffNValueSet_start = WPC_On;
}

/* Output and update for atomic system: '<S461>/USMSettingControl_Function' */
void USMSettingControl_Function_gulk(C_WPCOnOffNvalueSet rtu_InputSig, C_USMReset rtu_InputSig_eyil, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_eyil)
{
  /* Chart: '<S606>/USMSettingControlRWPC' */
  App_Model_DW.C_USMReset_prev = App_Model_DW.C_USMReset_start;
  App_Model_DW.C_USMReset_start = rtu_InputSig_eyil;
  App_Model_DW.C_RWPCOnOffNValueSet_prev = App_Model_DW.C_RWPCOnOffNValueSet_start;
  App_Model_DW.C_RWPCOnOffNValueSet_start = rtu_InputSig;
  if ((uint32)App_Model_DW.is_active_c6_USMSettingControl_ == 0U) {
    App_Model_DW.C_USMReset_prev = rtu_InputSig_eyil;
    App_Model_DW.C_RWPCOnOffNValueSet_prev = rtu_InputSig;
    App_Model_DW.is_active_c6_USMSettingControl_ = 1U;

    /* 1. */
  } else if ((App_Model_DW.C_USMReset_prev != App_Model_DW.C_USMReset_start) && ((uint32)App_Model_DW.C_USMReset_start == USMReset)) {
    *rty_USM_Sig_eyil = WPC_On;
    *rty_USM_Sig = WPC_On;
    m_RWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_RWPCOnOffNValueSet_prev != App_Model_DW.C_RWPCOnOffNValueSet_start) && ((uint32)App_Model_DW.C_RWPCOnOffNValueSet_start == WPC_On)) {
    *rty_USM_Sig_eyil = WPC_On;
    *rty_USM_Sig = WPC_On;
    m_RWPCUSM_App = WPC_On;

    /* 1. */
  } else if ((App_Model_DW.C_RWPCOnOffNValueSet_prev != App_Model_DW.C_RWPCOnOffNValueSet_start) && ((uint32)App_Model_DW.C_RWPCOnOffNValueSet_start == WPC_Off)) {
    *rty_USM_Sig_eyil = WPC_Off;
    *rty_USM_Sig = WPC_Off;
    m_RWPCUSM_App = WPC_Off;
  } else {
    /* 1. */
    switch (m_RWPCUSM_App) {
     case WPC_On:
      *rty_USM_Sig_eyil = WPC_On;
      *rty_USM_Sig = WPC_On;
      break;

     case WPC_Off:
      /* 1. */
      *rty_USM_Sig_eyil = WPC_Off;
      *rty_USM_Sig = WPC_Off;
      break;

     default:
      *rty_USM_Sig_eyil = WPC_On;
      *rty_USM_Sig = WPC_On;
      m_RWPCUSM_App = WPC_On;
      break;
    }
  }

  /* End of Chart: '<S606>/USMSettingControlRWPC' */
}

/* System initialize for atomic system: '<S638>/USMSettingControl_Function' */
void USMSettingControl_Fun_j1sr_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g3ze)
{
  /* SystemInitialize for IfAction SubSystem: '<S641>/USMSettingControl_Non_NFC' */
  USMSettingControl_Non_NFC_Init(&App_Model_DW.USMSettingControl_Non_NFC_csw4);

  /* End of SystemInitialize for SubSystem: '<S641>/USMSettingControl_Non_NFC' */

  /* SystemInitialize for IfAction SubSystem: '<S641>/USMSettingControl_NFC'
   *
   * Block description for '<S641>/USMSettingControl_NFC':
   *  WPC충전 OnOff 결과값 판단, WPC SW판정
   */
  App__USMSettingControl_NFC_Init(&App_Model_DW.USMSettingControl_NFC_fuoe);

  /* End of SystemInitialize for SubSystem: '<S641>/USMSettingControl_NFC' */

  /* SystemInitialize for Merge generated from: '<S641>/Merge' */
  *rty_USM_Sig = WPC_On;

  /* SystemInitialize for Merge generated from: '<S641>/Merge' */
  *rty_USM_Sig_g3ze = WPC_On;
}

/* Output and update for atomic system: '<S638>/USMSettingControl_Function' */
void USMSettingControl_Function_k3rq(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_g3ze, C_USMReset rtu_InputSig_iwak, C_ProfileIDRValue rtu_InputSig_pnns, C_ProfileIDRValue rtu_InputSig_mf5g,
  C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g3ze)
{
  /* SwitchCase: '<S641>/Switch Case' */
  switch (rtu_InputSig) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S641>/USMSettingControl_Non_NFC' incorporates:
     *  ActionPort: '<S827>/ActionPort'
     */
    App_M_USMSettingControl_Non_NFC(rtu_InputSig_g3ze, rtu_InputSig_iwak, rtu_InputSig_pnns, rty_USM_Sig, rty_USM_Sig_g3ze, &App_Model_DW.USMSettingControl_Non_NFC_csw4);

    /* End of Outputs for SubSystem: '<S641>/USMSettingControl_Non_NFC' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S641>/USMSettingControl_NFC' incorporates:
     *  ActionPort: '<S826>/ActionPort'
     *
     * Block description for '<S641>/USMSettingControl_NFC':
     *  WPC충전 OnOff 결과값 판단, WPC SW판정
     */
    App_Model_USMSettingControl_NFC(rtu_InputSig_g3ze, rtu_InputSig_iwak, rtu_InputSig_mf5g, rtu_InputSig_pnns, rty_USM_Sig, rty_USM_Sig_g3ze, &App_Model_DW.USMSettingControl_NFC_fuoe);

    /* End of Outputs for SubSystem: '<S641>/USMSettingControl_NFC' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S641>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
