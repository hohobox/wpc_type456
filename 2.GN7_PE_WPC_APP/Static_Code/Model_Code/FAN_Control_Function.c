/*
 * File: FAN_Control_Function.c
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

#include "rtwtypes.h"
#include "FAN_Control_Function.h"
#include "App_Model_types.h"
#include "App_Model.h"

/* Named constants for Chart: '<S30>/FAN_USM1_Control' */
#define App_Model_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define App_Model_IN_WPCUSM_SetGuest   ((uint8)1U)
#define App_Model_IN_WPCUSM_SetOne     ((uint8)2U)
#define App_Model_IN_WPCUSM_SetThree   ((uint8)3U)
#define App_Model_IN_WPCUSM_SetTwo     ((uint8)4U)

/* Named constants for Chart: '<S225>/FAN_USM2_Control' */
#define App_Mod_IN_WPCUSM_SetGuest_mvsp ((uint8)1U)
#define App_Mod_IN_WPCUSM_SetThree_lkwo ((uint8)3U)
#define App_Model_IN_WPCUSM_SetOne_l11h ((uint8)2U)
#define App_Model_IN_WPCUSM_SetTwo_pbxu ((uint8)4U)

/* Forward declaration for local functions */
static void App_Function_ProfileThreeWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);
static void App_Function_ProfileGuestWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);
static void App_M_Function_ProfileOneWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);
static void App_M_Function_ProfileTwoWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);

/* Forward declaration for local functions */
static void Ap_Function_ProfileThreeWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq);
static void Ap_Function_ProfileGuestWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq);
static void App__Function_ProfileOneWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq);
static void App__Function_ProfileTwoWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq);

/*
 * System initialize for atomic system:
 *    '<S26>/FAN_Control_13th'
 *    '<S221>/FAN_Control_13th'
 *    '<S466>/FAN_Control_13th'
 *    '<S643>/FAN_Control_13th'
 */
void App_Model_FAN_Control_13th_Init(uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW)
{
  localDW->is_active_c10_FAN_Control_lib = 0U;
  *rty_FAN_PWM = 0U;
}

/*
 * System reset for atomic system:
 *    '<S26>/FAN_Control_13th'
 *    '<S221>/FAN_Control_13th'
 *    '<S466>/FAN_Control_13th'
 *    '<S643>/FAN_Control_13th'
 */
void App_Mode_FAN_Control_13th_Reset(uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW)
{
  localDW->is_active_c10_FAN_Control_lib = 0U;
  *rty_FAN_PWM = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S26>/FAN_Control_13th'
 *    '<S221>/FAN_Control_13th'
 *    '<S466>/FAN_Control_13th'
 *    '<S643>/FAN_Control_13th'
 */
void App_Model_FAN_Control_13th(Bool rtu_b_FANModeCmd, uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW)
{
  /* Chart: '<S26>/FAN_Control_13th' */
  if ((uint32)localDW->is_active_c10_FAN_Control_lib == 0U) {
    localDW->is_active_c10_FAN_Control_lib = 1U;
    *rty_FAN_PWM = ((uint16)0U);
    if ((uint32)rtu_b_FANModeCmd == On) {
      *rty_FAN_PWM = Par_FANValueLow;
    }
  } else if ((uint32)rtu_b_FANModeCmd == On) {
    *rty_FAN_PWM = Par_FANValueLow;
  } else {
    *rty_FAN_PWM = ((uint16)0U);
  }

  /* End of Chart: '<S26>/FAN_Control_13th' */
}

/*
 * System initialize for atomic system:
 *    '<S30>/FAN_Out1Control'
 *    '<S470>/FAN_OutRControl'
 *    '<S647>/FAN_Out1Control'
 */
void App_Model_FAN_Out1Control_Init(uint16 *rty_WPC_FAN_PWM, DW_FAN_Out1Control_App_Model_T *localDW)
{
  localDW->is_active_c14_FAN_Control_lib = 0U;
  *rty_WPC_FAN_PWM = 0U;
}

/*
 * System reset for atomic system:
 *    '<S30>/FAN_Out1Control'
 *    '<S470>/FAN_OutRControl'
 *    '<S647>/FAN_Out1Control'
 */
void App_Model_FAN_Out1Control_Reset(uint16 *rty_WPC_FAN_PWM, DW_FAN_Out1Control_App_Model_T *localDW)
{
  localDW->is_active_c14_FAN_Control_lib = 0U;
  *rty_WPC_FAN_PWM = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S30>/FAN_Out1Control'
 *    '<S470>/FAN_OutRControl'
 *    '<S647>/FAN_Out1Control'
 */
void App_Model_FAN_Out1Control(uint16 rtu_USMFAN_PWM, Bool rtu_b_FANModeCmd, uint16 *rty_WPC_FAN_PWM, DW_FAN_Out1Control_App_Model_T *localDW)
{
  /* Chart: '<S30>/FAN_Out1Control' */
  if ((uint32)localDW->is_active_c14_FAN_Control_lib == 0U) {
    localDW->is_active_c14_FAN_Control_lib = 1U;
    *rty_WPC_FAN_PWM = ((uint16)0U);
    if ((uint32)rtu_b_FANModeCmd == On) {
      *rty_WPC_FAN_PWM = rtu_USMFAN_PWM;

      /* FAN_PWM = Par_FANValueLow */
    }
  } else if ((uint32)rtu_b_FANModeCmd == On) {
    *rty_WPC_FAN_PWM = rtu_USMFAN_PWM;

    /* FAN_PWM = Par_FANValueLow */
  } else {
    *rty_WPC_FAN_PWM = ((uint16)0U);
  }

  /* End of Chart: '<S30>/FAN_Out1Control' */
}

/* Function for Chart: '<S30>/FAN_USM1_Control' */
static void App_Function_ProfileThreeWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileThreeWPCFanUSM_App = LowDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_High)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
    *rty_FANDutyRatioSta = HighDuty;
    m_ProfileThreeWPCFanUSM_App = HighDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_Low)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileThreeWPCFanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileThreeWPCFanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
      *rty_FANDutyRatioSta = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      m_ProfileThreeWPCFanUSM_App = LowDuty;
      break;
    }
  }
}

/* Function for Chart: '<S30>/FAN_USM1_Control' */
static void App_Function_ProfileGuestWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileGuestWPCFanUSM_App = LowDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_High)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
    *rty_FANDutyRatioSta = HighDuty;
    m_ProfileGuestWPCFanUSM_App = HighDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_Low)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileGuestWPCFanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPCFanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
      *rty_FANDutyRatioSta = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      m_ProfileGuestWPCFanUSM_App = LowDuty;
      break;
    }
  }
}

/* Function for Chart: '<S30>/FAN_USM1_Control' */
static void App_M_Function_ProfileOneWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileOneWPCFanUSM_App = LowDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_High)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
    *rty_FANDutyRatioSta = HighDuty;
    m_ProfileOneWPCFanUSM_App = HighDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_Low)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileOneWPCFanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileOneWPCFanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
      *rty_FANDutyRatioSta = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      m_ProfileOneWPCFanUSM_App = LowDuty;
      break;
    }
  }
}

/* Function for Chart: '<S30>/FAN_USM1_Control' */
static void App_M_Function_ProfileTwoWPCUSM(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  /* 1. */
  if ((localDW->C_USMReset_prev != localDW->C_USMReset_start) && ((uint32)localDW->C_USMReset_start == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileTwoWPCFanUSM_App = LowDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_High)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
    *rty_FANDutyRatioSta = HighDuty;
    m_ProfileTwoWPCFanUSM_App = HighDuty;

    /* 1. */
  } else if ((localDW->FANSpeedSet_prev != localDW->FANSpeedSet_start) && ((uint32)localDW->FANSpeedSet_start == FANSpd_Low)) {
    *rty_USM_WPCFAN_PWM = Par_FANValueLow;
    *rty_FANDutyRatioSta = LowDuty;
    m_ProfileTwoWPCFanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPCFanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueHigh;
      *rty_FANDutyRatioSta = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *rty_USM_WPCFAN_PWM = Par_FANValueLow;
      *rty_FANDutyRatioSta = LowDuty;
      m_ProfileTwoWPCFanUSM_App = LowDuty;
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S30>/FAN_USM1_Control'
 *    '<S647>/FAN_USM1_Control'
 */
void App_Model_FAN_USM1_Control_Init(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  localDW->is_USMSettingControl = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c13_FAN_Control_lib = 0U;
  localDW->CurProfile = ProfileC_ProfileIDRValueDefault;
  *rty_USM_WPCFAN_PWM = 0U;
  *rty_FANDutyRatioSta = LowDuty;
  localDW->C_USMReset_prev = USMDefault;
  localDW->C_USMReset_start = USMDefault;
  localDW->FANSpeedSet_prev = FANSpd_Low;
  localDW->FANSpeedSet_start = FANSpd_Low;
}

/*
 * System reset for atomic system:
 *    '<S30>/FAN_USM1_Control'
 *    '<S647>/FAN_USM1_Control'
 */
void App_Mode_FAN_USM1_Control_Reset(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  localDW->is_USMSettingControl = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c13_FAN_Control_lib = 0U;
  localDW->CurProfile = ProfileC_ProfileIDRValueDefault;
  *rty_USM_WPCFAN_PWM = 0U;
  *rty_FANDutyRatioSta = LowDuty;
  localDW->C_USMReset_prev = USMDefault;
  localDW->C_USMReset_start = USMDefault;
  localDW->FANSpeedSet_prev = FANSpd_Low;
  localDW->FANSpeedSet_start = FANSpd_Low;
}

/*
 * Output and update for atomic system:
 *    '<S30>/FAN_USM1_Control'
 *    '<S647>/FAN_USM1_Control'
 */
void App_Model_FAN_USM1_Control(C_ProfileIDRValue rtu_C_ProfileIDRValue, C_ProfileIDRValue rtu_C_AVN_ProfileIDRValue, FANSpeed rtu_FANSpeedSet, C_USMReset rtu_C_USMReset, uint16 *rty_USM_WPCFAN_PWM,
  FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW)
{
  localDW->C_USMReset_prev = localDW->C_USMReset_start;
  localDW->C_USMReset_start = rtu_C_USMReset;
  localDW->FANSpeedSet_prev = localDW->FANSpeedSet_start;
  localDW->FANSpeedSet_start = rtu_FANSpeedSet;

  /* Chart: '<S30>/FAN_USM1_Control' */
  if ((uint32)localDW->is_active_c13_FAN_Control_lib == 0U) {
    localDW->C_USMReset_prev = rtu_C_USMReset;
    localDW->FANSpeedSet_prev = rtu_FANSpeedSet;
    localDW->is_active_c13_FAN_Control_lib = 1U;
    localDW->CurProfile = Profile1;

    /* 1. */
    switch (rtu_C_ProfileIDRValue) {
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
      switch (rtu_C_AVN_ProfileIDRValue) {
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
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne;
      App_M_Function_ProfileOneWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
      break;

     case Profile2:
      /* 2 */
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo;
      App_M_Function_ProfileTwoWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
      break;

     case Profile3:
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetThree;
      App_Function_ProfileThreeWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
      break;

     default:
      /* 4 */
      localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetGuest;
      App_Function_ProfileGuestWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
      break;
    }
  } else {
    /* 1. */
    switch (rtu_C_ProfileIDRValue) {
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
      switch (rtu_C_AVN_ProfileIDRValue) {
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
     case App_Model_IN_WPCUSM_SetGuest:
      /* 1. */
      switch (localDW->CurProfile) {
       case Profile1:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne;
        App_M_Function_ProfileOneWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile2:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo;
        App_M_Function_ProfileTwoWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetThree;
        App_Function_ProfileThreeWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       default:
        App_Function_ProfileGuestWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;
      }
      break;

     case App_Model_IN_WPCUSM_SetOne:
      /* 1. */
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetGuest;
        App_Function_ProfileGuestWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile2:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo;
        App_M_Function_ProfileTwoWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetThree;
        App_Function_ProfileThreeWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       default:
        App_M_Function_ProfileOneWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;
      }
      break;

     case App_Model_IN_WPCUSM_SetThree:
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetGuest;
        App_Function_ProfileGuestWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile1:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne;
        App_M_Function_ProfileOneWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile2:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetTwo;
        App_M_Function_ProfileTwoWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       default:
        App_Function_ProfileThreeWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;
      }
      break;

     default:
      /* case IN_WPCUSM_SetTwo: */
      /* 1. */
      switch (localDW->CurProfile) {
       case Guest:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetGuest;
        App_Function_ProfileGuestWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile1:
        /* 2. */
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetOne;
        App_M_Function_ProfileOneWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       case Profile3:
        localDW->is_USMSettingControl = App_Model_IN_WPCUSM_SetThree;
        App_Function_ProfileThreeWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;

       default:
        App_M_Function_ProfileTwoWPCUSM(rty_USM_WPCFAN_PWM, rty_FANDutyRatioSta, localDW);
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S30>/FAN_USM1_Control' */
}

/* System initialize for atomic system: '<S22>/FAN_Control_Function' */
void App_M_FAN_Control_Function_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_dttb)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM;

  /* SystemInitialize for Chart: '<S26>/FAN_Control_13th' */
  App_Model_FAN_Control_13th_Init(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th);

  /* SystemInitialize for Chart: '<S30>/FAN_USM1_Control' */
  App_Model_FAN_USM1_Control_Init(&App_Model_B.USM_WPCFAN_PWM_ovj1, rty_FANOut_Sig_dttb, &App_Model_DW.sf_FAN_USM1_Control);

  /* SystemInitialize for Chart: '<S30>/FAN_Out1Control' */
  App_Model_FAN_Out1Control_Init(&rtb_WPC_FAN_PWM, &App_Model_DW.sf_FAN_Out1Control);
}

/* System reset for atomic system: '<S22>/FAN_Control_Function' */
void App__FAN_Control_Function_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_dttb)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM;

  /* SystemReset for Chart: '<S26>/FAN_Control_13th' */
  App_Mode_FAN_Control_13th_Reset(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th);

  /* SystemReset for Chart: '<S30>/FAN_USM1_Control' */
  App_Mode_FAN_USM1_Control_Reset(&App_Model_B.USM_WPCFAN_PWM_ovj1, rty_FANOut_Sig_dttb, &App_Model_DW.sf_FAN_USM1_Control);

  /* SystemReset for Chart: '<S30>/FAN_Out1Control' */
  App_Model_FAN_Out1Control_Reset(&rtb_WPC_FAN_PWM, &App_Model_DW.sf_FAN_Out1Control);
}

/* Output and update for atomic system: '<S22>/FAN_Control_Function' */
void App_Model_FAN_Control_Function(Bool rtu_PostProcessIn, C_ProfileIDRValue rtu_PostProcessIn_dttb, C_ProfileIDRValue rtu_PostProcessIn_nvoj, FANSpeed rtu_PostProcessIn_g4ca, C_USMReset
  rtu_PostProcessIn_ch2y, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_dttb)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM;

  /* Chart: '<S26>/FAN_Control_13th' */
  App_Model_FAN_Control_13th(rtu_PostProcessIn, rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th);

  /* Chart: '<S30>/FAN_USM1_Control' */
  App_Model_FAN_USM1_Control(rtu_PostProcessIn_dttb, rtu_PostProcessIn_nvoj, rtu_PostProcessIn_g4ca, rtu_PostProcessIn_ch2y, &App_Model_B.USM_WPCFAN_PWM_ovj1, rty_FANOut_Sig_dttb,
    &App_Model_DW.sf_FAN_USM1_Control);

  /* Chart: '<S30>/FAN_Out1Control' */
  App_Model_FAN_Out1Control(App_Model_B.USM_WPCFAN_PWM_ovj1, rtu_PostProcessIn, &rtb_WPC_FAN_PWM, &App_Model_DW.sf_FAN_Out1Control);
}

/* Function for Chart: '<S225>/FAN_USM2_Control' */
static void Ap_Function_ProfileThreeWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_fxjk != App_Model_DW.C_USMReset_start_cjxb) && ((uint32)App_Model_DW.C_USMReset_start_cjxb == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileThreeWPC2FanUSM_App = LowDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_High)) {
    *USM_WPC2FAN_PWM = Par_FANValueHigh;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = HighDuty;
    m_ProfileThreeWPC2FanUSM_App = HighDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_Low)) {
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileThreeWPC2FanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileThreeWPC2FanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *USM_WPC2FAN_PWM = Par_FANValueHigh;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      m_ProfileThreeWPC2FanUSM_App = LowDuty;
      break;
    }
  }
}

/* Function for Chart: '<S225>/FAN_USM2_Control' */
static void Ap_Function_ProfileGuestWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_fxjk != App_Model_DW.C_USMReset_start_cjxb) && ((uint32)App_Model_DW.C_USMReset_start_cjxb == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileGuestWPC2FanUSM_App = LowDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_High)) {
    *USM_WPC2FAN_PWM = Par_FANValueHigh;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = HighDuty;
    m_ProfileGuestWPC2FanUSM_App = HighDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_Low)) {
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileGuestWPC2FanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileGuestWPC2FanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *USM_WPC2FAN_PWM = Par_FANValueHigh;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      m_ProfileGuestWPC2FanUSM_App = LowDuty;
      break;
    }
  }
}

/* Function for Chart: '<S225>/FAN_USM2_Control' */
static void App__Function_ProfileOneWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_fxjk != App_Model_DW.C_USMReset_start_cjxb) && ((uint32)App_Model_DW.C_USMReset_start_cjxb == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileOneWPC2FanUSM_App = LowDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_High)) {
    *USM_WPC2FAN_PWM = Par_FANValueHigh;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = HighDuty;
    m_ProfileOneWPC2FanUSM_App = HighDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_Low)) {
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileOneWPC2FanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileOneWPC2FanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *USM_WPC2FAN_PWM = Par_FANValueHigh;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      m_ProfileOneWPC2FanUSM_App = LowDuty;
      break;
    }
  }
}

/* Function for Chart: '<S225>/FAN_USM2_Control' */
static void App__Function_ProfileTwoWPC2USM(uint16 *USM_WPC2FAN_PWM, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* 1. */
  if ((App_Model_DW.C_USMReset_prev_fxjk != App_Model_DW.C_USMReset_start_cjxb) && ((uint32)App_Model_DW.C_USMReset_start_cjxb == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileTwoWPC2FanUSM_App = LowDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_High)) {
    *USM_WPC2FAN_PWM = Par_FANValueHigh;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = HighDuty;
    m_ProfileTwoWPC2FanUSM_App = HighDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev_jrjz != App_Model_DW.FANSpeedSet_start_a3w2) && ((uint32)App_Model_DW.FANSpeedSet_start_a3w2 == FANSpd_Low)) {
    *USM_WPC2FAN_PWM = Par_FANValueLow;

    /* Chart: '<S225>/FAN_USM2_Control' */
    *rty_FANOut_Sig_plxq = LowDuty;
    m_ProfileTwoWPC2FanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_ProfileTwoWPC2FanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      *USM_WPC2FAN_PWM = Par_FANValueHigh;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      *USM_WPC2FAN_PWM = Par_FANValueLow;

      /* Chart: '<S225>/FAN_USM2_Control' */
      *rty_FANOut_Sig_plxq = LowDuty;
      m_ProfileTwoWPC2FanUSM_App = LowDuty;
      break;
    }
  }
}

/* System initialize for atomic system: '<S217>/FAN_Control_Function' */
void FAN_Control_Function_hj2b_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* SystemInitialize for Chart: '<S221>/FAN_Control_13th' */
  App_Model_FAN_Control_13th_Init(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_pjrm);

  /* SystemInitialize for Chart: '<S225>/FAN_USM2_Control' */
  App_Model_DW.is_USMSettingControl_fvz0 = 0;
  App_Model_DW.is_active_c16_FAN_Control_lib = 0U;
  App_Model_DW.CurProfile_bp2h = ProfileC_ProfileIDRValueDefault;
  *rty_FANOut_Sig_plxq = LowDuty;
  App_Model_DW.C_USMReset_prev_fxjk = USMDefault;
  App_Model_DW.C_USMReset_start_cjxb = USMDefault;
  App_Model_DW.FANSpeedSet_prev_jrjz = FANSpd_Low;
  App_Model_DW.FANSpeedSet_start_a3w2 = FANSpd_Low;

  /* SystemInitialize for Chart: '<S225>/FAN_Out2Control' */
  App_Model_DW.is_active_c15_FAN_Control_lib = 0U;
}

/* System reset for atomic system: '<S217>/FAN_Control_Function' */
void FAN_Control_Function_mo3f_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_frqx;

  /* SystemReset for Chart: '<S221>/FAN_Control_13th' */
  App_Mode_FAN_Control_13th_Reset(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_pjrm);

  /* SystemReset for Chart: '<S225>/FAN_USM2_Control' */
  App_Model_DW.is_USMSettingControl_fvz0 = 0;
  App_Model_DW.is_active_c16_FAN_Control_lib = 0U;
  App_Model_DW.CurProfile_bp2h = ProfileC_ProfileIDRValueDefault;
  *rty_FANOut_Sig_plxq = LowDuty;
  App_Model_DW.C_USMReset_prev_fxjk = USMDefault;
  App_Model_DW.C_USMReset_start_cjxb = USMDefault;
  App_Model_DW.FANSpeedSet_prev_jrjz = FANSpd_Low;
  App_Model_DW.FANSpeedSet_start_a3w2 = FANSpd_Low;

  /* SystemReset for Chart: '<S225>/FAN_Out2Control' */
  App_Model_DW.is_active_c15_FAN_Control_lib = 0U;
  rtb_WPC_FAN_PWM_frqx = 0U;
}

/* Output and update for atomic system: '<S217>/FAN_Control_Function' */
void App_M_FAN_Control_Function_kz0x(Bool rtu_PostProcessIn, C_ProfileIDRValue rtu_PostProcessIn_plxq, C_ProfileIDRValue rtu_PostProcessIn_f20n, FANSpeed rtu_PostProcessIn_jgez, C_USMReset
  rtu_PostProcessIn_prn1, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_plxq)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_frqx;
  uint16 USM_WPC2FAN_PWM;

  /* Chart: '<S221>/FAN_Control_13th' */
  App_Model_FAN_Control_13th(rtu_PostProcessIn, rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_pjrm);

  /* Chart: '<S225>/FAN_USM2_Control' */
  App_Model_DW.C_USMReset_prev_fxjk = App_Model_DW.C_USMReset_start_cjxb;
  App_Model_DW.C_USMReset_start_cjxb = rtu_PostProcessIn_prn1;
  App_Model_DW.FANSpeedSet_prev_jrjz = App_Model_DW.FANSpeedSet_start_a3w2;
  App_Model_DW.FANSpeedSet_start_a3w2 = rtu_PostProcessIn_jgez;
  if ((uint32)App_Model_DW.is_active_c16_FAN_Control_lib == 0U) {
    App_Model_DW.C_USMReset_prev_fxjk = rtu_PostProcessIn_prn1;
    App_Model_DW.FANSpeedSet_prev_jrjz = rtu_PostProcessIn_jgez;
    App_Model_DW.is_active_c16_FAN_Control_lib = 1U;
    App_Model_DW.CurProfile_bp2h = Profile1;

    /* 1. */
    switch (rtu_PostProcessIn_plxq) {
     case Profile1:
      break;

     case Profile2:
      /* 1. */
      App_Model_DW.CurProfile_bp2h = Profile2;
      break;

     case Profile3:
      /* 1. */
      App_Model_DW.CurProfile_bp2h = Profile3;
      break;

     case Guest:
      /* 1. */
      App_Model_DW.CurProfile_bp2h = Guest;
      break;

     default:
      /* 1. */
      switch (rtu_PostProcessIn_f20n) {
       case Profile1:
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_bp2h = Profile2;
        break;

       case Profile3:
        /* 1. */
        App_Model_DW.CurProfile_bp2h = Profile3;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_bp2h = Guest;
        break;

       default:
        /* no actions */
        break;
      }
      break;
    }

    /* 1 */
    switch (App_Model_DW.CurProfile_bp2h) {
     case Profile1:
      App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetOne_l11h;
      App__Function_ProfileOneWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
      break;

     case Profile2:
      /* 2 */
      App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetTwo_pbxu;
      App__Function_ProfileTwoWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
      break;

     case Profile3:
      App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetThree_lkwo;
      Ap_Function_ProfileThreeWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
      break;

     default:
      /* 4 */
      App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetGuest_mvsp;
      Ap_Function_ProfileGuestWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
      break;
    }
  } else {
    /* 1. */
    switch (rtu_PostProcessIn_plxq) {
     case Profile1:
      App_Model_DW.CurProfile_bp2h = Profile1;
      break;

     case Profile2:
      /* 1. */
      App_Model_DW.CurProfile_bp2h = Profile2;
      break;

     case Profile3:
      /* 1. */
      App_Model_DW.CurProfile_bp2h = Profile3;
      break;

     case Guest:
      /* 1. */
      App_Model_DW.CurProfile_bp2h = Guest;
      break;

     default:
      /* 1. */
      switch (rtu_PostProcessIn_f20n) {
       case Profile1:
        App_Model_DW.CurProfile_bp2h = Profile1;
        break;

       case Profile2:
        /* 1. */
        App_Model_DW.CurProfile_bp2h = Profile2;
        break;

       case Profile3:
        /* 1. */
        App_Model_DW.CurProfile_bp2h = Profile3;
        break;

       case Guest:
        /* 1. */
        App_Model_DW.CurProfile_bp2h = Guest;
        break;

       default:
        /* no actions */
        break;
      }
      break;
    }

    switch (App_Model_DW.is_USMSettingControl_fvz0) {
     case App_Mod_IN_WPCUSM_SetGuest_mvsp:
      /* 1. */
      switch (App_Model_DW.CurProfile_bp2h) {
       case Profile1:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetOne_l11h;
        App__Function_ProfileOneWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile2:
        /* 2. */
        App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetTwo_pbxu;
        App__Function_ProfileTwoWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile3:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetThree_lkwo;
        Ap_Function_ProfileThreeWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       default:
        Ap_Function_ProfileGuestWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;
      }
      break;

     case App_Model_IN_WPCUSM_SetOne_l11h:
      /* 1. */
      switch (App_Model_DW.CurProfile_bp2h) {
       case Guest:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetGuest_mvsp;
        Ap_Function_ProfileGuestWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile2:
        /* 2. */
        App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetTwo_pbxu;
        App__Function_ProfileTwoWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile3:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetThree_lkwo;
        Ap_Function_ProfileThreeWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       default:
        App__Function_ProfileOneWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;
      }
      break;

     case App_Mod_IN_WPCUSM_SetThree_lkwo:
      switch (App_Model_DW.CurProfile_bp2h) {
       case Guest:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetGuest_mvsp;
        Ap_Function_ProfileGuestWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile1:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetOne_l11h;
        App__Function_ProfileOneWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile2:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetTwo_pbxu;
        App__Function_ProfileTwoWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       default:
        Ap_Function_ProfileThreeWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;
      }
      break;

     default:
      /* case IN_WPCUSM_SetTwo: */
      /* 1. */
      switch (App_Model_DW.CurProfile_bp2h) {
       case Guest:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetGuest_mvsp;
        Ap_Function_ProfileGuestWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile1:
        /* 2. */
        App_Model_DW.is_USMSettingControl_fvz0 = App_Model_IN_WPCUSM_SetOne_l11h;
        App__Function_ProfileOneWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       case Profile3:
        App_Model_DW.is_USMSettingControl_fvz0 = App_Mod_IN_WPCUSM_SetThree_lkwo;
        Ap_Function_ProfileThreeWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;

       default:
        App__Function_ProfileTwoWPC2USM(&USM_WPC2FAN_PWM, rty_FANOut_Sig_plxq);
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S225>/FAN_USM2_Control' */

  /* Chart: '<S225>/FAN_Out2Control' */
  if ((uint32)App_Model_DW.is_active_c15_FAN_Control_lib == 0U) {
    App_Model_DW.is_active_c15_FAN_Control_lib = 1U;
    rtb_WPC_FAN_PWM_frqx = ((uint16)0U);
    if ((uint32)rtu_PostProcessIn == On) {
      rtb_WPC_FAN_PWM_frqx = USM_WPC2FAN_PWM;

      /* FAN_PWM = Par_FANValueLow */
    }
  } else if ((uint32)rtu_PostProcessIn == On) {
    rtb_WPC_FAN_PWM_frqx = USM_WPC2FAN_PWM;

    /* FAN_PWM = Par_FANValueLow */
  } else {
    rtb_WPC_FAN_PWM_frqx = ((uint16)0U);
  }

  /* End of Chart: '<S225>/FAN_Out2Control' */
}

/* System initialize for atomic system: '<S462>/FAN_Control_Function' */
void FAN_Control_Function_iqwo_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_gxyj)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_f0es;

  /* SystemInitialize for Chart: '<S466>/FAN_Control_13th' */
  App_Model_FAN_Control_13th_Init(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_fd3h);

  /* SystemInitialize for Chart: '<S470>/FAN_USMR_Control' */
  App_Model_DW.is_active_c18_FAN_Control_lib = 0U;
  App_Model_B.USM_RWPCFAN_PWM = 0U;
  *rty_FANOut_Sig_gxyj = LowDuty;
  App_Model_DW.C_USMReset_prev_ci4c = USMDefault;
  App_Model_DW.C_USMReset_start_km5r = USMDefault;
  App_Model_DW.FANSpeedSet_prev = FANSpd_Low;
  App_Model_DW.FANSpeedSet_start = FANSpd_Low;

  /* SystemInitialize for Chart: '<S470>/FAN_OutRControl' */
  App_Model_FAN_Out1Control_Init(&rtb_WPC_FAN_PWM_f0es, &App_Model_DW.sf_FAN_OutRControl);
}

/* System reset for atomic system: '<S462>/FAN_Control_Function' */
void FAN_Control_Function_h0nw_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_gxyj)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_f0es;

  /* SystemReset for Chart: '<S466>/FAN_Control_13th' */
  App_Mode_FAN_Control_13th_Reset(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_fd3h);

  /* SystemReset for Chart: '<S470>/FAN_USMR_Control' */
  App_Model_DW.is_active_c18_FAN_Control_lib = 0U;
  App_Model_B.USM_RWPCFAN_PWM = 0U;
  *rty_FANOut_Sig_gxyj = LowDuty;
  App_Model_DW.C_USMReset_prev_ci4c = USMDefault;
  App_Model_DW.C_USMReset_start_km5r = USMDefault;
  App_Model_DW.FANSpeedSet_prev = FANSpd_Low;
  App_Model_DW.FANSpeedSet_start = FANSpd_Low;

  /* SystemReset for Chart: '<S470>/FAN_OutRControl' */
  App_Model_FAN_Out1Control_Reset(&rtb_WPC_FAN_PWM_f0es, &App_Model_DW.sf_FAN_OutRControl);
}

/* Output and update for atomic system: '<S462>/FAN_Control_Function' */
void App_M_FAN_Control_Function_nnca(FANSpeed rtu_PostProcessIn, C_USMReset rtu_PostProcessIn_gxyj, Bool rtu_PostProcessIn_lhw0, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_gxyj)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_f0es;

  /* Chart: '<S466>/FAN_Control_13th' */
  App_Model_FAN_Control_13th(rtu_PostProcessIn_lhw0, rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_fd3h);

  /* Chart: '<S470>/FAN_USMR_Control' */
  App_Model_DW.C_USMReset_prev_ci4c = App_Model_DW.C_USMReset_start_km5r;
  App_Model_DW.C_USMReset_start_km5r = rtu_PostProcessIn_gxyj;
  App_Model_DW.FANSpeedSet_prev = App_Model_DW.FANSpeedSet_start;
  App_Model_DW.FANSpeedSet_start = rtu_PostProcessIn;
  if ((uint32)App_Model_DW.is_active_c18_FAN_Control_lib == 0U) {
    App_Model_DW.C_USMReset_prev_ci4c = rtu_PostProcessIn_gxyj;
    App_Model_DW.FANSpeedSet_prev = rtu_PostProcessIn;
    App_Model_DW.is_active_c18_FAN_Control_lib = 1U;

    /* 1. */
  } else if ((App_Model_DW.C_USMReset_prev_ci4c != App_Model_DW.C_USMReset_start_km5r) && ((uint32)App_Model_DW.C_USMReset_start_km5r == USMReset)) {
    /* CaseReset: LowDuty(Default) */
    App_Model_B.USM_RWPCFAN_PWM = Par_FANValueLow;
    *rty_FANOut_Sig_gxyj = LowDuty;
    m_RWPCFanUSM_App = LowDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev != App_Model_DW.FANSpeedSet_start) && ((uint32)App_Model_DW.FANSpeedSet_start == FANSpd_High)) {
    App_Model_B.USM_RWPCFAN_PWM = Par_FANValueHigh;
    *rty_FANOut_Sig_gxyj = HighDuty;
    m_RWPCFanUSM_App = HighDuty;

    /* 1. */
  } else if ((App_Model_DW.FANSpeedSet_prev != App_Model_DW.FANSpeedSet_start) && ((uint32)App_Model_DW.FANSpeedSet_start == FANSpd_Low)) {
    App_Model_B.USM_RWPCFAN_PWM = Par_FANValueLow;
    *rty_FANOut_Sig_gxyj = LowDuty;
    m_RWPCFanUSM_App = LowDuty;
  } else {
    /* 1. */
    switch (m_RWPCFanUSM_App) {
     case HighDuty:
      /* NvM High Case */
      App_Model_B.USM_RWPCFAN_PWM = Par_FANValueHigh;
      *rty_FANOut_Sig_gxyj = HighDuty;
      break;

     case LowDuty:
      /* 1. */
      /* NvM Low Case */
      App_Model_B.USM_RWPCFAN_PWM = Par_FANValueLow;
      *rty_FANOut_Sig_gxyj = LowDuty;
      break;

     default:
      /* Reserved/Invalid Case: LowDuty(Default) */
      App_Model_B.USM_RWPCFAN_PWM = Par_FANValueLow;
      *rty_FANOut_Sig_gxyj = LowDuty;
      m_RWPCFanUSM_App = LowDuty;
      break;
    }
  }

  /* End of Chart: '<S470>/FAN_USMR_Control' */

  /* Chart: '<S470>/FAN_OutRControl' */
  App_Model_FAN_Out1Control(App_Model_B.USM_RWPCFAN_PWM, rtu_PostProcessIn_lhw0, &rtb_WPC_FAN_PWM_f0es, &App_Model_DW.sf_FAN_OutRControl);
}

/* System initialize for atomic system: '<S639>/FAN_Control_Function' */
void FAN_Control_Function_gebo_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_pqgs)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_kcat;

  /* SystemInitialize for Chart: '<S643>/FAN_Control_13th' */
  App_Model_FAN_Control_13th_Init(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_no3p);

  /* SystemInitialize for Chart: '<S647>/FAN_USM1_Control' */
  App_Model_FAN_USM1_Control_Init(&App_Model_B.USM_WPCFAN_PWM, rty_FANOut_Sig_pqgs, &App_Model_DW.sf_FAN_USM1_Control_cyh3);

  /* SystemInitialize for Chart: '<S647>/FAN_Out1Control' */
  App_Model_FAN_Out1Control_Init(&rtb_WPC_FAN_PWM_kcat, &App_Model_DW.sf_FAN_Out1Control_oo14);
}

/* System reset for atomic system: '<S639>/FAN_Control_Function' */
void FAN_Control_Function_a5e3_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_pqgs)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_kcat;

  /* SystemReset for Chart: '<S643>/FAN_Control_13th' */
  App_Mode_FAN_Control_13th_Reset(rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_no3p);

  /* SystemReset for Chart: '<S647>/FAN_USM1_Control' */
  App_Mode_FAN_USM1_Control_Reset(&App_Model_B.USM_WPCFAN_PWM, rty_FANOut_Sig_pqgs, &App_Model_DW.sf_FAN_USM1_Control_cyh3);

  /* SystemReset for Chart: '<S647>/FAN_Out1Control' */
  App_Model_FAN_Out1Control_Reset(&rtb_WPC_FAN_PWM_kcat, &App_Model_DW.sf_FAN_Out1Control_oo14);
}

/* Output and update for atomic system: '<S639>/FAN_Control_Function' */
void App_M_FAN_Control_Function_h0dg(Bool rtu_PostProcessIn, C_ProfileIDRValue rtu_PostProcessIn_pqgs, C_ProfileIDRValue rtu_PostProcessIn_l0vi, FANSpeed rtu_PostProcessIn_g45y, C_USMReset
  rtu_PostProcessIn_od5b, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_pqgs)
{
  /* local block i/o variables */
  uint16 rtb_WPC_FAN_PWM_kcat;

  /* Chart: '<S643>/FAN_Control_13th' */
  App_Model_FAN_Control_13th(rtu_PostProcessIn, rty_FANOut_Sig, &App_Model_DW.sf_FAN_Control_13th_no3p);

  /* Chart: '<S647>/FAN_USM1_Control' */
  App_Model_FAN_USM1_Control(rtu_PostProcessIn_pqgs, rtu_PostProcessIn_l0vi, rtu_PostProcessIn_g45y, rtu_PostProcessIn_od5b, &App_Model_B.USM_WPCFAN_PWM, rty_FANOut_Sig_pqgs,
    &App_Model_DW.sf_FAN_USM1_Control_cyh3);

  /* Chart: '<S647>/FAN_Out1Control' */
  App_Model_FAN_Out1Control(App_Model_B.USM_WPCFAN_PWM, rtu_PostProcessIn, &rtb_WPC_FAN_PWM_kcat, &App_Model_DW.sf_FAN_Out1Control_oo14);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
