/*
 * File: IndyOutputControl_Function.c
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
#include "IndyOutputControl_Function.h"
#include "App_Model_types.h"
#include <math.h>
#include "App_Model.h"

/* Forward declaration for local functions */
static void App_Model_Bright_Error_Control(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const App_Model_M,
  B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW);

/* Forward declaration for local functions */
static void App_Model_Bright_Control1(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW);
static void App_Model_Bright_Control2(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW);
static void App_Model_Bright_Control3(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW);

/* Forward declaration for local functions */
static void WPC_IND_Output_Control_Fun_d4ue(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue);

/* Forward declaration for local functions */
static void enter_internal_c420_IndyOutputC(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue);

/* Forward declaration for local functions */
static void App_M_Bright_Error_Control_l0v0(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const
  App_Model_M, B_Amber_IND_with_Animati_m1ud_T *localB, DW_Amber_IND_with_Animat_lfth_T *localDW);

/* Forward declaration for local functions */
static void App_Model_Bright_Control1_nxxz(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW);
static void App_Model_Bright_Control2_htmw(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW);
static void App_Model_Bright_Control3_cofb(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW);

/* Forward declaration for local functions */
static void App_M_Bright_Error_Control_nftz(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animati_atgr_T *localB,
  DW_Amber_IND_with_Animat_pevs_T *localDW);

/* Forward declaration for local functions */
static void App_Model_Bright_Control1_iwev(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC, DW_Green_IND_with_Animat_pmuj_T *localDW);
static void App_Model_Bright_Control2_ob3u(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC, DW_Green_IND_with_Animat_pmuj_T *localDW);
static void App_Model_Bright_Control3_f2e3(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC, DW_Green_IND_with_Animat_pmuj_T *localDW);

/*
 * System initialize for atomic system:
 *    '<S93>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S141>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S45>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S283>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S331>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S235>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S521>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S556>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S486>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S715>/Amber_IND_Control_Function_Flow_Graph'
 *    ...
 */
void Amber_IND_Control_Function_Init(uint16 *rty_Var_AmberIND, DW_Amber_IND_Control_Function_T *localDW)
{
  localDW->is_active_c323_IndyOutputContro = 0U;
  *rty_Var_AmberIND = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S93>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S141>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S45>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S283>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S331>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S235>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S521>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S556>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S486>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S715>/Amber_IND_Control_Function_Flow_Graph'
 *    ...
 */
void Amber_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_AmberINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_AmberIND, DW_Amber_IND_Control_Function_T *localDW)
{
  /* Chart: '<S93>/Amber_IND_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c323_IndyOutputContro == 0U) {
    localDW->is_active_c323_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_AmberIND = Off;

    /* 1 */
    if ((uint32)rtu_Input_OPT_b_AmberINDCmd == On) {
      *rty_Var_AmberIND = rtu_Var_BrightMaxValue;
    } else {
      *rty_Var_AmberIND = Off;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_Input_OPT_b_AmberINDCmd == On) {
    *rty_Var_AmberIND = rtu_Var_BrightMaxValue;
  } else {
    *rty_Var_AmberIND = Off;
  }

  /* End of Chart: '<S93>/Amber_IND_Control_Function_Flow_Graph' */
}

/*
 * System initialize for function-call system:
 *    '<S95>/FadeIn'
 *    '<S143>/FadeIn'
 *    '<S47>/FadeIn'
 *    '<S285>/FadeIn'
 *    '<S333>/FadeIn'
 *    '<S237>/FadeIn'
 *    '<S717>/FadeIn'
 *    '<S765>/FadeIn'
 *    '<S669>/FadeIn'
 */
void App_Model_FadeIn_Init(DW_FadeIn_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S103>/Delay Input1'
   *
   * Block description for '<S103>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S101>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S95>/FadeIn'
 *    '<S143>/FadeIn'
 *    '<S47>/FadeIn'
 *    '<S285>/FadeIn'
 *    '<S333>/FadeIn'
 *    '<S237>/FadeIn'
 *    '<S717>/FadeIn'
 *    '<S765>/FadeIn'
 *    '<S669>/FadeIn'
 */
void App_Model_FadeIn_Reset(DW_FadeIn_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S103>/Delay Input1'
   *
   * Block description for '<S103>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S101>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S95>/FadeIn'
 *    '<S143>/FadeIn'
 *    '<S47>/FadeIn'
 *    '<S285>/FadeIn'
 *    '<S333>/FadeIn'
 *    '<S237>/FadeIn'
 *    '<S717>/FadeIn'
 *    '<S765>/FadeIn'
 *    '<S669>/FadeIn'
 */
void App_Model_FadeIn(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger, float64 rtu_pass, uint16 *rty_y_FadeIn, DW_FadeIn_App_Model_T *localDW)
{
  float64 rtb_Add1_pswn;
  float64 rtb_Switch5_bl1g;
  float64 rtb_Switch_d4e2;

  /* Switch: '<S101>/Switch' incorporates:
   *  Switch: '<S101>/Switch1'
   */
  if (rtu_Trigger > 0) {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S101>/Constant2'
     *  DataTypeConversion: '<S101>/Data Type Conversion'
     *  Product: '<S101>/Divide'
     */
    rtb_Switch_d4e2 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);

    /* Sum: '<S101>/Add1' incorporates:
     *  UnitDelay: '<S101>/Unit Delay'
     */
    rtb_Add1_pswn = localDW->UnitDelay_DSTATE;
  } else {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S101>/Constant1'
     */
    rtb_Switch_d4e2 = 0.0;

    /* Sum: '<S101>/Add1' incorporates:
     *  Constant: '<S101>/Constant3'
     */
    rtb_Add1_pswn = 0.0;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Sum: '<S101>/Add1' */
  rtb_Add1_pswn += rtb_Switch_d4e2;

  /* Switch: '<S101>/Switch3' incorporates:
   *  DataTypeConversion: '<S101>/Data Type Conversion'
   *  Logic: '<S101>/AND'
   *  RelationalOperator: '<S103>/FixPt Relational Operator'
   *  UnitDelay: '<S103>/Delay Input1'
   *
   * Block description for '<S103>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger != 0) && (rtu_pass != 0.0)) {
    /* DataTypeConversion: '<S101>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S101>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* DataTypeConversion: '<S101>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S101>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = rtb_Add1_pswn;
  }

  /* End of Switch: '<S101>/Switch3' */

  /* Switch: '<S101>/Switch5' */
  if (rtu_pass > 0.0) {
    /* Switch: '<S101>/Switch5' incorporates:
     *  DataTypeConversion: '<S101>/Data Type Conversion'
     */
    rtb_Switch5_bl1g = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S101>/Switch5' incorporates:
     *  UnitDelay: '<S101>/Unit Delay'
     */
    rtb_Switch5_bl1g = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S101>/Switch5' */

  /* Switch: '<S101>/Switch2' incorporates:
   *  Constant: '<S101>/Constant4'
   *  Switch: '<S104>/Switch2'
   */
  if (rtu_Trigger > 0) {
    /* Switch: '<S104>/Switch2' incorporates:
     *  Constant: '<S101>/Constant4'
     *  DataTypeConversion: '<S101>/Data Type Conversion'
     *  RelationalOperator: '<S104>/LowerRelop1'
     *  RelationalOperator: '<S104>/UpperRelop'
     *  Switch: '<S104>/Switch'
     */
    if (rtb_Switch5_bl1g > (float64)rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch5_bl1g < (float64)((uint16)0U)) {
      /* Switch: '<S104>/Switch' incorporates:
       *  Constant: '<S101>/Constant4'
       */
      *rty_y_FadeIn = ((uint16)0U);
    } else {
      *rty_y_FadeIn = (uint16)rtb_Switch5_bl1g;
    }
  } else {
    *rty_y_FadeIn = ((uint16)0U);
  }

  /* End of Switch: '<S101>/Switch2' */
  /* Update for UnitDelay: '<S103>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S101>/Data Type Conversion'
   *
   * Block description for '<S103>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S95>/FadeOut'
 *    '<S143>/FadeOut'
 *    '<S47>/FadeOut'
 *    '<S717>/FadeOut'
 *    '<S765>/FadeOut'
 *    '<S669>/FadeOut'
 */
void App_Model_FadeOut_Init(DW_FadeOut_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S105>/Delay Input1'
   *
   * Block description for '<S105>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S109>/Delay Input2'
   *
   * Block description for '<S109>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S95>/FadeOut'
 *    '<S143>/FadeOut'
 *    '<S47>/FadeOut'
 *    '<S717>/FadeOut'
 *    '<S765>/FadeOut'
 *    '<S669>/FadeOut'
 */
void App_Model_FadeOut_Reset(DW_FadeOut_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S105>/Delay Input1'
   *
   * Block description for '<S105>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S109>/Delay Input2'
   *
   * Block description for '<S109>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S95>/FadeOut'
 *    '<S143>/FadeOut'
 *    '<S47>/FadeOut'
 *    '<S717>/FadeOut'
 *    '<S765>/FadeOut'
 *    '<S669>/FadeOut'
 */
void App_Model_FadeOut_Enable(DW_FadeOut_App_Model_T *localDW)
{
  localDW->FadeOut_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S95>/FadeOut'
 *    '<S143>/FadeOut'
 *    '<S47>/FadeOut'
 *    '<S717>/FadeOut'
 *    '<S765>/FadeOut'
 *    '<S669>/FadeOut'
 */
void App_Model_FadeOut(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_mldy;
  float64 rtb_Switch4_fque;
  float64 rtu_pass_0;
  uint16 rtb_Switch9_ih0y;
  if (localDW->FadeOut_RESET_ELAPS_T) {
    localDW->FadeOut_ELAPS_T[0] = 0U;
    localDW->FadeOut_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut_ELAPS_T[0] = FadeOut_ELAPS_T_tmp - localDW->FadeOut_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut_PREV_T[1];
    if (localDW->FadeOut_PREV_T[0] > FadeOut_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut_RESET_ELAPS_T = false;

  /* Switch: '<S102>/Switch' incorporates:
   *  DataTypeConversion: '<S102>/Data Type Conversion7'
   *  Switch: '<S102>/Switch5'
   */
  if (rtu_Trigger_FO > 0) {
    /* Switch: '<S106>/Switch4' incorporates:
     *  Constant: '<S102>/Constant5'
     *  DataTypeConversion: '<S102>/Data Type Conversion7'
     *  Product: '<S102>/Divide'
     */
    rtb_Switch4_fque = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    rtb_Switch9_ih0y = rtu_preValue;
  } else {
    /* Switch: '<S106>/Switch4' incorporates:
     *  Constant: '<S102>/Constant4'
     */
    rtb_Switch4_fque = (float64)((uint16)0U);
    rtb_Switch9_ih0y = rtu_Var_BrightMaxValue;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Sum: '<S102>/Add1' */
  rtb_Add1_mldy = (float64)rtb_Switch9_ih0y - rtb_Switch4_fque;

  /* SampleTimeMath: '<S109>/sample time'
   *
   * About '<S109>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S109>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S102>/Data Type Conversion7'
   *  DataTypeConversion: '<S106>/Data Type Conversion2'
   *  SampleTimeMath: '<S109>/sample time'
   *
   * About '<S109>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_fque = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S102>/Switch8' incorporates:
   *  Constant: '<S102>/Constant2'
   *  DataTypeConversion: '<S102>/Data Type Conversion7'
   *  Logic: '<S102>/AND'
   *  RelationalOperator: '<S105>/FixPt Relational Operator'
   *  Switch: '<S102>/Switch7'
   *  UnitDelay: '<S105>/Delay Input1'
   *
   * Block description for '<S105>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger_FO != 0) && (rtu_pass != 0.0)) {
    rtb_Add1_mldy = (float64)rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger_FO > 0) {
    /* Switch: '<S108>/Switch2' incorporates:
     *  Constant: '<S102>/Constant2'
     *  RelationalOperator: '<S108>/LowerRelop1'
     *  RelationalOperator: '<S108>/UpperRelop'
     *  Switch: '<S108>/Switch'
     */
    if (rtb_Add1_mldy > (float64)rtu_preValue) {
      /* Switch: '<S102>/Switch7' */
      rtb_Add1_mldy = (float64)rtu_preValue;
    } else if (rtb_Add1_mldy < (float64)((uint16)0U)) {
      /* Switch: '<S108>/Switch' incorporates:
       *  Constant: '<S102>/Constant2'
       *  Switch: '<S102>/Switch7'
       */
      rtb_Add1_mldy = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S108>/Switch2' */
  } else {
    rtb_Add1_mldy = (float64)((uint16)0U);
  }

  /* End of Switch: '<S102>/Switch8' */

  /* Sum: '<S109>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S109>/Delay Input2'
   *
   * Block description for '<S109>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S109>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_mldy -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S106>/Switch4' incorporates:
   *  DataStoreRead: '<S106>/Data Store Read'
   *  DataTypeConversion: '<S102>/Data Type Conversion7'
   *  DataTypeConversion: '<S106>/Data Type Conversion2'
   *  DataTypeConversion: '<S106>/Data Type Conversion6'
   *  UnaryMinus: '<S106>/Unary Minus'
   *  UnaryMinus: '<S106>/Unary Minus2'
   */
  if (rtu_pass > 0.0) {
    rtu_pass_0 = -((float64)Par_AutoBrightLevel091);
  } else {
    rtu_pass_0 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S106>/Switch4' */

  /* Product: '<S109>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S109>/sample time'
   *
   * About '<S109>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime *= rtu_pass_0;

  /* Switch: '<S110>/Switch2' incorporates:
   *  RelationalOperator: '<S110>/LowerRelop1'
   *  RelationalOperator: '<S110>/UpperRelop'
   *  Switch: '<S110>/Switch'
   */
  if (rtb_Add1_mldy > rtb_Switch4_fque) {
    rtb_Add1_mldy = rtb_Switch4_fque;
  } else if (rtb_Add1_mldy < elapseTime) {
    /* Switch: '<S110>/Switch' */
    rtb_Add1_mldy = elapseTime;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S110>/Switch2' */

  /* Sum: '<S109>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S109>/Delay Input2'
   *
   * Block description for '<S109>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S109>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add1_mldy;

  /* Switch: '<S106>/Switch9' */
  if (rtu_pass > 0.0) {
    /* Switch: '<S106>/Switch9' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion7'
     */
    rtb_Switch9_ih0y = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S106>/Switch9' incorporates:
     *  DataTypeConversion: '<S106>/Data Type Conversion1'
     *  UnitDelay: '<S109>/Delay Input2'
     *
     * Block description for '<S109>/Delay Input2':
     *
     *  Store in Global RAM
     */
    rtb_Switch9_ih0y = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S106>/Switch9' */

  /* Switch: '<S102>/Switch1' incorporates:
   *  Constant: '<S102>/Constant7'
   *  Switch: '<S107>/Switch2'
   */
  if (rtu_Trigger_FO > 0) {
    /* Switch: '<S107>/Switch2' incorporates:
     *  Constant: '<S102>/Constant7'
     *  DataTypeConversion: '<S102>/Data Type Conversion7'
     *  RelationalOperator: '<S107>/LowerRelop1'
     *  RelationalOperator: '<S107>/UpperRelop'
     *  Switch: '<S107>/Switch'
     */
    if (rtb_Switch9_ih0y > rtu_Var_BrightMaxValue) {
      *rty_y_FadeOut = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch9_ih0y < ((uint16)0U)) {
      /* Switch: '<S107>/Switch' incorporates:
       *  Constant: '<S102>/Constant7'
       */
      *rty_y_FadeOut = ((uint16)0U);
    } else {
      *rty_y_FadeOut = rtb_Switch9_ih0y;
    }
  } else {
    *rty_y_FadeOut = ((uint16)0U);
  }

  /* End of Switch: '<S102>/Switch1' */

  /* Update for UnitDelay: '<S105>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S102>/Data Type Conversion7'
   *
   * Block description for '<S105>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Error_Control(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const App_Model_M,
  B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localDW->pass = 0.0;
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S95>/FadeIn' */
    /* FcnTrigRst = FadeOut(Var_BrightMaxValue,Var_AmberINDwithAnimation,0,0); */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }
  } else {
    switch (rtu_Input_INT_WPCIndCmdState) {
     case WPCIndCmdState__ErrorOn:
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S95>/FadeIn' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      break;

     case WPCIndCmdState__ErrorFadeIn:
      if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 1.0)) {
        localDW->pass = 1.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 1.0;

        /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S95>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      } else {
        localDW->pass = 0.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 0.0;

        /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S95>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = localB->Switch2;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  if ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeOut) {
    if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 2.0)) {
      localDW->pass = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S95>/FadeIn' */
      localB->Var_BrightMaxValue_gb0o = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 0;
      localB->pass_ckkq = 1.0;

      /* Outputs for Function Call SubSystem: '<S95>/FadeOut' */
      App_Model_FadeOut(App_Model_M, localB->Var_BrightMaxValue_gb0o, localB->preValue, localB->Trigger_FO, localB->pass_ckkq, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S95>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
    } else {
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S95>/FadeIn' */
      localB->Var_BrightMaxValue_gb0o = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 1;
      localB->pass_ckkq = 0.0;

      /* Outputs for Function Call SubSystem: '<S95>/FadeOut' */
      App_Model_FadeOut(App_Model_M, localB->Var_BrightMaxValue_gb0o, localB->preValue, localB->Trigger_FO, localB->pass_ckkq, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S95>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = localB->Switch1;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S715>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S763>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S667>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_C_Init(uint16 *rty_Var_AmberINDwithAnimation, DW_Amber_IND_with_Animation_C_T *localDW)
{
  localDW->is_active_c425_IndyOutputContro = 0U;
  localDW->pass = 0.0;
  *rty_Var_AmberINDwithAnimation = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S95>/FadeIn' */
  App_Model_FadeIn_Init(&localDW->FadeIn);

  /* End of SystemInitialize for SubSystem: '<S95>/FadeIn' */

  /* SystemInitialize for Function Call SubSystem: '<S95>/FadeOut' */
  App_Model_FadeOut_Init(&localDW->FadeOut);

  /* End of SystemInitialize for SubSystem: '<S95>/FadeOut' */
}

/*
 * Enable for atomic system:
 *    '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S715>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S763>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S667>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_Enable(DW_Amber_IND_with_Animation_C_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S95>/FadeIn' */
  App_Model_FadeIn_Reset(&localDW->FadeIn);

  /* End of SystemReset for SubSystem: '<S95>/FadeIn' */

  /* SystemReset for Function Call SubSystem: '<S95>/FadeOut' */
  App_Model_FadeOut_Reset(&localDW->FadeOut);

  /* End of SystemReset for SubSystem: '<S95>/FadeOut' */

  /* Enable for Function Call SubSystem: '<S95>/FadeOut' */
  App_Model_FadeOut_Enable(&localDW->FadeOut);

  /* End of Enable for SubSystem: '<S95>/FadeOut' */
}

/*
 * Output and update for atomic system:
 *    '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S715>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S763>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S667>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if ((uint32)localDW->is_active_c425_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c425_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S95>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S95>/FadeIn' */
    localB->Var_BrightMaxValue_gb0o = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_AmberINDwithAnimation;
    localB->Trigger_FO = 0;
    localB->pass_ckkq = 0.0;

    /* Outputs for Function Call SubSystem: '<S95>/FadeOut' */
    App_Model_FadeOut(App_Model_M, localB->Var_BrightMaxValue_gb0o, localB->preValue, localB->Trigger_FO, localB->pass_ckkq, &localB->Switch1, &localDW->FadeOut);

    /* End of Outputs for SubSystem: '<S95>/FadeOut' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    if ((uint32)rtu_b_SyncAmber == Off) {
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Var_AmberINDwithAnimation = (uint16)0.0;
        } else {
          *rty_Var_AmberINDwithAnimation = 0U;
        }
      } else {
        *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
      }

      /* 1 */
    } else if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
                WPCIndCmdState__ErrorFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default)) {
      App_Model_Bright_Error_Control(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);

      /* Not used in Amber LED */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
  } else if ((uint32)rtu_b_SyncAmber == Off) {
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    /* 1 */
  } else if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
              WPCIndCmdState__ErrorFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default)) {
    App_Model_Bright_Error_Control(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);

    /* Not used in Amber LED */
  } else if (0.0 < 65536.0) {
    if (0.0 >= 0.0) {
      *rty_Var_AmberINDwithAnimation = (uint16)0.0;
    } else {
      *rty_Var_AmberINDwithAnimation = 0U;
    }
  } else {
    *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
  }

  /* End of Chart: '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for atomic system:
 *    '<S93>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S283>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S521>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S715>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_F_Init(uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Control_F_T *localDW)
{
  localDW->is_active_c333_IndyOutputContro = 0U;
  *rty_Var_BrightMaxValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S93>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S283>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S521>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S715>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_Functi(Bool rtu_Input_DetentOut, RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue,
  DW_Bright_Max_Value_Control_F_T *localDW)
{
  /* Chart: '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c333_IndyOutputContro == 0U) {
    localDW->is_active_c333_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_BrightMaxValue = rtu_RheoLevelValue;

    /* 1 */
    if ((uint32)rtu_Input_RheostatOption == On) {
      if ((uint32)rtu_Input_DetentOut == On) {
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
    } else if ((uint32)rtu_Input_RheostatOption == Off) {
      if ((uint32)rtu_Input_b_IntTailOn == On) {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
      } else {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
    } else {
      /* no actions */
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_Input_RheostatOption == On) {
    if ((uint32)rtu_Input_DetentOut == On) {
      *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
    } else {
      *rty_Var_BrightMaxValue = rtu_RheoLevelValue;
    }
  } else if ((uint32)rtu_Input_RheostatOption == Off) {
    if ((uint32)rtu_Input_b_IntTailOn == On) {
      /* 2 */
      *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
    } else {
      /* 2 */
      *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
    }
  } else {
    /* no actions */
  }

  /* End of Chart: '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
}

/*
 * System initialize for atomic system:
 *    '<S93>/Green_IND_Control_Function_Flow_Graph'
 *    '<S141>/Green_IND_Control_Function_Flow_Graph'
 *    '<S45>/Green_IND_Control_Function_Flow_Graph'
 *    '<S283>/Green_IND_Control_Function_Flow_Graph'
 *    '<S331>/Green_IND_Control_Function_Flow_Graph'
 *    '<S235>/Green_IND_Control_Function_Flow_Graph'
 *    '<S521>/Green_IND_Control_Function_Flow_Graph'
 *    '<S556>/Green_IND_Control_Function_Flow_Graph'
 *    '<S486>/Green_IND_Control_Function_Flow_Graph'
 *    '<S715>/Green_IND_Control_Function_Flow_Graph'
 *    ...
 */
void Green_IND_Control_Function_Init(uint16 *rty_Var_GreenIND, DW_Green_IND_Control_Function_T *localDW)
{
  localDW->is_active_c337_IndyOutputContro = 0U;
  *rty_Var_GreenIND = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S93>/Green_IND_Control_Function_Flow_Graph'
 *    '<S141>/Green_IND_Control_Function_Flow_Graph'
 *    '<S45>/Green_IND_Control_Function_Flow_Graph'
 *    '<S283>/Green_IND_Control_Function_Flow_Graph'
 *    '<S331>/Green_IND_Control_Function_Flow_Graph'
 *    '<S235>/Green_IND_Control_Function_Flow_Graph'
 *    '<S521>/Green_IND_Control_Function_Flow_Graph'
 *    '<S556>/Green_IND_Control_Function_Flow_Graph'
 *    '<S486>/Green_IND_Control_Function_Flow_Graph'
 *    '<S715>/Green_IND_Control_Function_Flow_Graph'
 *    ...
 */
void Green_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_GreenINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_GreenIND, DW_Green_IND_Control_Function_T *localDW)
{
  /* Chart: '<S93>/Green_IND_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c337_IndyOutputContro == 0U) {
    localDW->is_active_c337_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_GreenIND = Off;

    /* 1 */
    if ((uint32)rtu_Input_OPT_b_GreenINDCmd == On) {
      *rty_Var_GreenIND = rtu_Var_BrightMaxValue;
    } else {
      *rty_Var_GreenIND = Off;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_Input_OPT_b_GreenINDCmd == On) {
    *rty_Var_GreenIND = rtu_Var_BrightMaxValue;
  } else {
    *rty_Var_GreenIND = Off;
  }

  /* End of Chart: '<S93>/Green_IND_Control_Function_Flow_Graph' */
}

/*
 * System initialize for function-call system:
 *    '<S98>/FadeIn1'
 *    '<S146>/FadeIn1'
 *    '<S50>/FadeIn1'
 *    '<S288>/FadeIn1'
 *    '<S336>/FadeIn1'
 *    '<S240>/FadeIn1'
 *    '<S720>/FadeIn1'
 *    '<S768>/FadeIn1'
 *    '<S672>/FadeIn1'
 */
void App_Model_FadeIn1_Init(DW_FadeIn1_App_Model_T *localDW)
{
  /* InitializeConditions for Switch: '<S111>/Switch1' incorporates:
   *  UnitDelay: '<S111>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S117>/Delay Input1'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S98>/FadeIn1'
 *    '<S146>/FadeIn1'
 *    '<S50>/FadeIn1'
 *    '<S288>/FadeIn1'
 *    '<S336>/FadeIn1'
 *    '<S240>/FadeIn1'
 *    '<S720>/FadeIn1'
 *    '<S768>/FadeIn1'
 *    '<S672>/FadeIn1'
 */
void App_Model_FadeIn1_Reset(DW_FadeIn1_App_Model_T *localDW)
{
  /* InitializeConditions for Switch: '<S111>/Switch1' incorporates:
   *  UnitDelay: '<S111>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S117>/Delay Input1'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S98>/FadeIn1'
 *    '<S146>/FadeIn1'
 *    '<S50>/FadeIn1'
 *    '<S288>/FadeIn1'
 *    '<S336>/FadeIn1'
 *    '<S240>/FadeIn1'
 *    '<S720>/FadeIn1'
 *    '<S768>/FadeIn1'
 *    '<S672>/FadeIn1'
 */
void App_Model_FadeIn1(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger1, float64 rtu_pass1, uint16 *rty_y_FadeIn1, DW_FadeIn1_App_Model_T *localDW)
{
  float64 rtb_Switch3_j1uu;

  /* Switch: '<S111>/Switch' */
  if (rtu_Trigger1 > 0) {
    /* Switch: '<S111>/Switch3' incorporates:
     *  Constant: '<S111>/Constant2'
     *  DataTypeConversion: '<S111>/Data Type Conversion'
     *  Product: '<S111>/Divide'
     */
    rtb_Switch3_j1uu = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
  } else {
    /* Switch: '<S111>/Switch3' incorporates:
     *  Constant: '<S111>/Constant1'
     */
    rtb_Switch3_j1uu = 0.0;
  }

  /* End of Switch: '<S111>/Switch' */
  /* Switch: '<S111>/Switch1' incorporates:
   *  Constant: '<S111>/Constant3'
   */
  if (rtu_Trigger1 <= 0) {
    localDW->UnitDelay_DSTATE = 0.0;
  }

  /* Switch: '<S111>/Switch3' incorporates:
   *  Sum: '<S111>/Add1'
   */
  rtb_Switch3_j1uu += localDW->UnitDelay_DSTATE;

  /* Switch: '<S111>/Switch3' incorporates:
   *  DataTypeConversion: '<S111>/Data Type Conversion'
   *  Logic: '<S111>/AND'
   *  RelationalOperator: '<S117>/FixPt Relational Operator'
   *  UnitDelay: '<S117>/Delay Input1'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger1 != 0) && (rtu_pass1 != 0.0)) {
    /* Switch: '<S111>/Switch1' incorporates:
     *  DataTypeConversion: '<S111>/Data Type Conversion1'
     */
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S111>/Switch1' incorporates:
     *  DataTypeConversion: '<S111>/Data Type Conversion1'
     */
    localDW->UnitDelay_DSTATE = rtb_Switch3_j1uu;
  }

  /* End of Switch: '<S111>/Switch3' */

  /* Switch: '<S111>/Switch5' */
  if (rtu_pass1 > 0.0) {
    /* Switch: '<S111>/Switch5' incorporates:
     *  DataTypeConversion: '<S111>/Data Type Conversion'
     */
    rtb_Switch3_j1uu = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S111>/Switch5' incorporates:
     *  UnitDelay: '<S111>/Unit Delay'
     */
    rtb_Switch3_j1uu = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S111>/Switch5' */

  /* Switch: '<S111>/Switch2' incorporates:
   *  Constant: '<S111>/Constant4'
   *  Switch: '<S118>/Switch2'
   */
  if (rtu_Trigger1 > 0) {
    /* Switch: '<S118>/Switch2' incorporates:
     *  Constant: '<S111>/Constant4'
     *  DataTypeConversion: '<S111>/Data Type Conversion'
     *  RelationalOperator: '<S118>/LowerRelop1'
     *  RelationalOperator: '<S118>/UpperRelop'
     *  Switch: '<S118>/Switch'
     */
    if (rtb_Switch3_j1uu > (float64)rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn1 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch3_j1uu < (float64)((uint16)0U)) {
      /* Switch: '<S118>/Switch' incorporates:
       *  Constant: '<S111>/Constant4'
       */
      *rty_y_FadeIn1 = ((uint16)0U);
    } else {
      *rty_y_FadeIn1 = (uint16)rtb_Switch3_j1uu;
    }
  } else {
    *rty_y_FadeIn1 = ((uint16)0U);
  }

  /* End of Switch: '<S111>/Switch2' */

  /* Update for UnitDelay: '<S117>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S111>/Data Type Conversion'
   *
   * Block description for '<S117>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S98>/FadeOut1'
 *    '<S146>/FadeOut1'
 *    '<S50>/FadeOut1'
 *    '<S288>/FadeOut1'
 *    '<S336>/FadeOut1'
 *    '<S240>/FadeOut1'
 *    '<S720>/FadeOut1'
 *    '<S768>/FadeOut1'
 *    '<S672>/FadeOut1'
 */
void App_Model_FadeOut1_Init(DW_FadeOut1_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S123>/Delay Input1'
   *
   * Block description for '<S123>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S127>/Delay Input2'
   *
   * Block description for '<S127>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S98>/FadeOut1'
 *    '<S146>/FadeOut1'
 *    '<S50>/FadeOut1'
 *    '<S288>/FadeOut1'
 *    '<S336>/FadeOut1'
 *    '<S240>/FadeOut1'
 *    '<S720>/FadeOut1'
 *    '<S768>/FadeOut1'
 *    '<S672>/FadeOut1'
 */
void App_Model_FadeOut1_Reset(DW_FadeOut1_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S123>/Delay Input1'
   *
   * Block description for '<S123>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S127>/Delay Input2'
   *
   * Block description for '<S127>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S98>/FadeOut1'
 *    '<S146>/FadeOut1'
 *    '<S50>/FadeOut1'
 *    '<S288>/FadeOut1'
 *    '<S336>/FadeOut1'
 *    '<S240>/FadeOut1'
 *    '<S720>/FadeOut1'
 *    '<S768>/FadeOut1'
 *    '<S672>/FadeOut1'
 */
void App_Model_FadeOut1_Enable(DW_FadeOut1_App_Model_T *localDW)
{
  localDW->FadeOut1_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S98>/FadeOut1'
 *    '<S146>/FadeOut1'
 *    '<S50>/FadeOut1'
 *    '<S288>/FadeOut1'
 *    '<S336>/FadeOut1'
 *    '<S240>/FadeOut1'
 *    '<S720>/FadeOut1'
 *    '<S768>/FadeOut1'
 *    '<S672>/FadeOut1'
 */
void App_Model_FadeOut1(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger1_FO, float64 rtu_pass1, uint16 *rty_y_FadeOut1,
  DW_FadeOut1_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_decd;
  float64 rtb_Switch4_dzra;
  float64 rtu_pass1_0;
  uint16 rtb_Switch9_cqst;
  if (localDW->FadeOut1_RESET_ELAPS_T) {
    localDW->FadeOut1_ELAPS_T[0] = 0U;
    localDW->FadeOut1_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut1_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut1_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut1_ELAPS_T[0] = FadeOut1_ELAPS_T_tmp - localDW->FadeOut1_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut1_PREV_T[1];
    if (localDW->FadeOut1_PREV_T[0] > FadeOut1_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut1_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut1_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut1_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut1_RESET_ELAPS_T = false;

  /* Switch: '<S114>/Switch' incorporates:
   *  DataTypeConversion: '<S114>/Data Type Conversion7'
   *  Switch: '<S114>/Switch5'
   */
  if (rtu_Trigger1_FO > 0) {
    /* Switch: '<S124>/Switch4' incorporates:
     *  Constant: '<S114>/Constant5'
     *  DataTypeConversion: '<S114>/Data Type Conversion7'
     *  Product: '<S114>/Divide'
     */
    rtb_Switch4_dzra = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    rtb_Switch9_cqst = rtu_preValue;
  } else {
    /* Switch: '<S124>/Switch4' incorporates:
     *  Constant: '<S114>/Constant4'
     */
    rtb_Switch4_dzra = (float64)((uint16)0U);
    rtb_Switch9_cqst = rtu_Var_BrightMaxValue;
  }

  /* End of Switch: '<S114>/Switch' */

  /* Sum: '<S114>/Add1' */
  rtb_Add1_decd = (float64)rtb_Switch9_cqst - rtb_Switch4_dzra;

  /* SampleTimeMath: '<S127>/sample time'
   *
   * About '<S127>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut1_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut1_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S127>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S114>/Data Type Conversion7'
   *  DataTypeConversion: '<S124>/Data Type Conversion2'
   *  SampleTimeMath: '<S127>/sample time'
   *
   * About '<S127>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_dzra = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S114>/Switch8' incorporates:
   *  Constant: '<S114>/Constant2'
   *  DataTypeConversion: '<S114>/Data Type Conversion7'
   *  Logic: '<S114>/AND'
   *  RelationalOperator: '<S123>/FixPt Relational Operator'
   *  Switch: '<S114>/Switch7'
   *  UnitDelay: '<S123>/Delay Input1'
   *
   * Block description for '<S123>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger1_FO != 0) && (rtu_pass1 != 0.0)) {
    rtb_Add1_decd = (float64)rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger1_FO > 0) {
    /* Switch: '<S126>/Switch2' incorporates:
     *  Constant: '<S114>/Constant2'
     *  RelationalOperator: '<S126>/LowerRelop1'
     *  RelationalOperator: '<S126>/UpperRelop'
     *  Switch: '<S126>/Switch'
     */
    if (rtb_Add1_decd > (float64)rtu_preValue) {
      /* Switch: '<S114>/Switch7' */
      rtb_Add1_decd = (float64)rtu_preValue;
    } else if (rtb_Add1_decd < (float64)((uint16)0U)) {
      /* Switch: '<S126>/Switch' incorporates:
       *  Constant: '<S114>/Constant2'
       *  Switch: '<S114>/Switch7'
       */
      rtb_Add1_decd = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S126>/Switch2' */
  } else {
    rtb_Add1_decd = (float64)((uint16)0U);
  }

  /* End of Switch: '<S114>/Switch8' */

  /* Sum: '<S127>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S127>/Delay Input2'
   *
   * Block description for '<S127>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S127>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_decd -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S124>/Switch4' incorporates:
   *  DataStoreRead: '<S124>/Data Store Read'
   *  DataTypeConversion: '<S114>/Data Type Conversion7'
   *  DataTypeConversion: '<S124>/Data Type Conversion2'
   *  DataTypeConversion: '<S124>/Data Type Conversion6'
   *  UnaryMinus: '<S124>/Unary Minus'
   *  UnaryMinus: '<S124>/Unary Minus2'
   */
  if (rtu_pass1 > 0.0) {
    rtu_pass1_0 = -((float64)Par_AutoBrightLevel091);
  } else {
    rtu_pass1_0 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S124>/Switch4' */

  /* Product: '<S127>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S127>/sample time'
   *
   * About '<S127>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime *= rtu_pass1_0;

  /* Switch: '<S128>/Switch2' incorporates:
   *  RelationalOperator: '<S128>/LowerRelop1'
   *  RelationalOperator: '<S128>/UpperRelop'
   *  Switch: '<S128>/Switch'
   */
  if (rtb_Add1_decd > rtb_Switch4_dzra) {
    rtb_Add1_decd = rtb_Switch4_dzra;
  } else if (rtb_Add1_decd < elapseTime) {
    /* Switch: '<S128>/Switch' */
    rtb_Add1_decd = elapseTime;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S128>/Switch2' */

  /* Sum: '<S127>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S127>/Delay Input2'
   *
   * Block description for '<S127>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S127>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add1_decd;

  /* Switch: '<S124>/Switch9' */
  if (rtu_pass1 > 0.0) {
    /* Switch: '<S124>/Switch9' incorporates:
     *  DataTypeConversion: '<S114>/Data Type Conversion7'
     */
    rtb_Switch9_cqst = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S124>/Switch9' incorporates:
     *  DataTypeConversion: '<S124>/Data Type Conversion1'
     *  UnitDelay: '<S127>/Delay Input2'
     *
     * Block description for '<S127>/Delay Input2':
     *
     *  Store in Global RAM
     */
    rtb_Switch9_cqst = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S124>/Switch9' */

  /* Switch: '<S114>/Switch1' incorporates:
   *  Constant: '<S114>/Constant7'
   *  Switch: '<S125>/Switch2'
   */
  if (rtu_Trigger1_FO > 0) {
    /* Switch: '<S125>/Switch2' incorporates:
     *  Constant: '<S114>/Constant7'
     *  DataTypeConversion: '<S114>/Data Type Conversion7'
     *  RelationalOperator: '<S125>/LowerRelop1'
     *  RelationalOperator: '<S125>/UpperRelop'
     *  Switch: '<S125>/Switch'
     */
    if (rtb_Switch9_cqst > rtu_Var_BrightMaxValue) {
      *rty_y_FadeOut1 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch9_cqst < ((uint16)0U)) {
      /* Switch: '<S125>/Switch' incorporates:
       *  Constant: '<S114>/Constant7'
       */
      *rty_y_FadeOut1 = ((uint16)0U);
    } else {
      *rty_y_FadeOut1 = rtb_Switch9_cqst;
    }
  } else {
    *rty_y_FadeOut1 = ((uint16)0U);
  }

  /* End of Switch: '<S114>/Switch1' */

  /* Update for UnitDelay: '<S123>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S114>/Data Type Conversion7'
   *
   * Block description for '<S123>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S98>/FadeIn2'
 *    '<S146>/FadeIn2'
 *    '<S50>/FadeIn2'
 *    '<S288>/FadeIn2'
 *    '<S336>/FadeIn2'
 *    '<S240>/FadeIn2'
 *    '<S720>/FadeIn2'
 *    '<S768>/FadeIn2'
 *    '<S672>/FadeIn2'
 */
void App_Model_FadeIn2_Init(DW_FadeIn2_App_Model_T *localDW)
{
  /* InitializeConditions for Switch: '<S112>/Switch1' incorporates:
   *  UnitDelay: '<S112>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S119>/Delay Input1'
   *
   * Block description for '<S119>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S98>/FadeIn2'
 *    '<S146>/FadeIn2'
 *    '<S50>/FadeIn2'
 *    '<S288>/FadeIn2'
 *    '<S336>/FadeIn2'
 *    '<S240>/FadeIn2'
 *    '<S720>/FadeIn2'
 *    '<S768>/FadeIn2'
 *    '<S672>/FadeIn2'
 */
void App_Model_FadeIn2_Reset(DW_FadeIn2_App_Model_T *localDW)
{
  /* InitializeConditions for Switch: '<S112>/Switch1' incorporates:
   *  UnitDelay: '<S112>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S119>/Delay Input1'
   *
   * Block description for '<S119>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S98>/FadeIn2'
 *    '<S146>/FadeIn2'
 *    '<S50>/FadeIn2'
 *    '<S288>/FadeIn2'
 *    '<S336>/FadeIn2'
 *    '<S240>/FadeIn2'
 *    '<S720>/FadeIn2'
 *    '<S768>/FadeIn2'
 *    '<S672>/FadeIn2'
 */
void App_Model_FadeIn2(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger2, float64 rtu_pass2, uint16 *rty_y_FadeIn2, DW_FadeIn2_App_Model_T *localDW)
{
  float64 rtb_Switch3_lzr3;

  /* Switch: '<S112>/Switch' */
  if (rtu_Trigger2 > 0) {
    /* Switch: '<S112>/Switch3' incorporates:
     *  Constant: '<S112>/Constant2'
     *  DataTypeConversion: '<S112>/Data Type Conversion'
     *  Product: '<S112>/Divide'
     */
    rtb_Switch3_lzr3 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
  } else {
    /* Switch: '<S112>/Switch3' incorporates:
     *  Constant: '<S112>/Constant1'
     */
    rtb_Switch3_lzr3 = 0.0;
  }

  /* End of Switch: '<S112>/Switch' */
  /* Switch: '<S112>/Switch1' incorporates:
   *  Constant: '<S112>/Constant3'
   */
  if (rtu_Trigger2 <= 0) {
    localDW->UnitDelay_DSTATE = 0.0;
  }

  /* Switch: '<S112>/Switch3' incorporates:
   *  Sum: '<S112>/Add1'
   */
  rtb_Switch3_lzr3 += localDW->UnitDelay_DSTATE;

  /* Switch: '<S112>/Switch3' incorporates:
   *  DataTypeConversion: '<S112>/Data Type Conversion'
   *  Logic: '<S112>/AND'
   *  RelationalOperator: '<S119>/FixPt Relational Operator'
   *  UnitDelay: '<S119>/Delay Input1'
   *
   * Block description for '<S119>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger2 != 0) && (rtu_pass2 != 0.0)) {
    /* Switch: '<S112>/Switch1' incorporates:
     *  DataTypeConversion: '<S112>/Data Type Conversion1'
     */
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S112>/Switch1' incorporates:
     *  DataTypeConversion: '<S112>/Data Type Conversion1'
     */
    localDW->UnitDelay_DSTATE = rtb_Switch3_lzr3;
  }

  /* End of Switch: '<S112>/Switch3' */

  /* Switch: '<S112>/Switch5' */
  if (rtu_pass2 > 0.0) {
    /* Switch: '<S112>/Switch5' incorporates:
     *  DataTypeConversion: '<S112>/Data Type Conversion'
     */
    rtb_Switch3_lzr3 = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S112>/Switch5' incorporates:
     *  UnitDelay: '<S112>/Unit Delay'
     */
    rtb_Switch3_lzr3 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S112>/Switch5' */

  /* Switch: '<S112>/Switch2' incorporates:
   *  Constant: '<S112>/Constant4'
   *  Switch: '<S120>/Switch2'
   */
  if (rtu_Trigger2 > 0) {
    /* Switch: '<S120>/Switch2' incorporates:
     *  Constant: '<S112>/Constant4'
     *  DataTypeConversion: '<S112>/Data Type Conversion'
     *  RelationalOperator: '<S120>/LowerRelop1'
     *  RelationalOperator: '<S120>/UpperRelop'
     *  Switch: '<S120>/Switch'
     */
    if (rtb_Switch3_lzr3 > (float64)rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn2 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch3_lzr3 < (float64)((uint16)0U)) {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S112>/Constant4'
       */
      *rty_y_FadeIn2 = ((uint16)0U);
    } else {
      *rty_y_FadeIn2 = (uint16)rtb_Switch3_lzr3;
    }
  } else {
    *rty_y_FadeIn2 = ((uint16)0U);
  }

  /* End of Switch: '<S112>/Switch2' */

  /* Update for UnitDelay: '<S119>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S112>/Data Type Conversion'
   *
   * Block description for '<S119>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S98>/FadeOut2'
 *    '<S146>/FadeOut2'
 *    '<S50>/FadeOut2'
 *    '<S288>/FadeOut2'
 *    '<S336>/FadeOut2'
 *    '<S240>/FadeOut2'
 *    '<S720>/FadeOut2'
 *    '<S768>/FadeOut2'
 *    '<S672>/FadeOut2'
 */
void App_Model_FadeOut2_Init(DW_FadeOut2_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S129>/Delay Input1'
   *
   * Block description for '<S129>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S133>/Delay Input2'
   *
   * Block description for '<S133>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S98>/FadeOut2'
 *    '<S146>/FadeOut2'
 *    '<S50>/FadeOut2'
 *    '<S288>/FadeOut2'
 *    '<S336>/FadeOut2'
 *    '<S240>/FadeOut2'
 *    '<S720>/FadeOut2'
 *    '<S768>/FadeOut2'
 *    '<S672>/FadeOut2'
 */
void App_Model_FadeOut2_Reset(DW_FadeOut2_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S129>/Delay Input1'
   *
   * Block description for '<S129>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S133>/Delay Input2'
   *
   * Block description for '<S133>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S98>/FadeOut2'
 *    '<S146>/FadeOut2'
 *    '<S50>/FadeOut2'
 *    '<S288>/FadeOut2'
 *    '<S336>/FadeOut2'
 *    '<S240>/FadeOut2'
 *    '<S720>/FadeOut2'
 *    '<S768>/FadeOut2'
 *    '<S672>/FadeOut2'
 */
void App_Model_FadeOut2_Enable(DW_FadeOut2_App_Model_T *localDW)
{
  localDW->FadeOut2_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S98>/FadeOut2'
 *    '<S146>/FadeOut2'
 *    '<S50>/FadeOut2'
 *    '<S288>/FadeOut2'
 *    '<S336>/FadeOut2'
 *    '<S240>/FadeOut2'
 *    '<S720>/FadeOut2'
 *    '<S768>/FadeOut2'
 *    '<S672>/FadeOut2'
 */
void App_Model_FadeOut2(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger2_FO, float64 rtu_pass2, uint16 *rty_y_FadeOut2,
  DW_FadeOut2_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_eskf;
  float64 rtb_Switch4_jj5n;
  float64 rtu_pass2_0;
  uint16 rtb_Switch9_lgmx;
  if (localDW->FadeOut2_RESET_ELAPS_T) {
    localDW->FadeOut2_ELAPS_T[0] = 0U;
    localDW->FadeOut2_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut2_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut2_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut2_ELAPS_T[0] = FadeOut2_ELAPS_T_tmp - localDW->FadeOut2_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut2_PREV_T[1];
    if (localDW->FadeOut2_PREV_T[0] > FadeOut2_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut2_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut2_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut2_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut2_RESET_ELAPS_T = false;

  /* Switch: '<S115>/Switch' incorporates:
   *  DataTypeConversion: '<S115>/Data Type Conversion7'
   *  Switch: '<S115>/Switch5'
   */
  if (rtu_Trigger2_FO > 0) {
    /* Switch: '<S130>/Switch4' incorporates:
     *  Constant: '<S115>/Constant5'
     *  DataTypeConversion: '<S115>/Data Type Conversion7'
     *  Product: '<S115>/Divide'
     */
    rtb_Switch4_jj5n = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    rtb_Switch9_lgmx = rtu_preValue;
  } else {
    /* Switch: '<S130>/Switch4' incorporates:
     *  Constant: '<S115>/Constant4'
     */
    rtb_Switch4_jj5n = (float64)((uint16)0U);
    rtb_Switch9_lgmx = rtu_Var_BrightMaxValue;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Sum: '<S115>/Add1' */
  rtb_Add1_eskf = (float64)rtb_Switch9_lgmx - rtb_Switch4_jj5n;

  /* SampleTimeMath: '<S133>/sample time'
   *
   * About '<S133>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut2_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut2_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S133>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S115>/Data Type Conversion7'
   *  DataTypeConversion: '<S130>/Data Type Conversion2'
   *  SampleTimeMath: '<S133>/sample time'
   *
   * About '<S133>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_jj5n = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S115>/Switch8' incorporates:
   *  Constant: '<S115>/Constant2'
   *  DataTypeConversion: '<S115>/Data Type Conversion7'
   *  Logic: '<S115>/AND'
   *  RelationalOperator: '<S129>/FixPt Relational Operator'
   *  Switch: '<S115>/Switch7'
   *  UnitDelay: '<S129>/Delay Input1'
   *
   * Block description for '<S129>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger2_FO != 0) && (rtu_pass2 != 0.0)) {
    rtb_Add1_eskf = (float64)rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger2_FO > 0) {
    /* Switch: '<S132>/Switch2' incorporates:
     *  Constant: '<S115>/Constant2'
     *  RelationalOperator: '<S132>/LowerRelop1'
     *  RelationalOperator: '<S132>/UpperRelop'
     *  Switch: '<S132>/Switch'
     */
    if (rtb_Add1_eskf > (float64)rtu_preValue) {
      /* Switch: '<S115>/Switch7' */
      rtb_Add1_eskf = (float64)rtu_preValue;
    } else if (rtb_Add1_eskf < (float64)((uint16)0U)) {
      /* Switch: '<S132>/Switch' incorporates:
       *  Constant: '<S115>/Constant2'
       *  Switch: '<S115>/Switch7'
       */
      rtb_Add1_eskf = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S132>/Switch2' */
  } else {
    rtb_Add1_eskf = (float64)((uint16)0U);
  }

  /* End of Switch: '<S115>/Switch8' */

  /* Sum: '<S133>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S133>/Delay Input2'
   *
   * Block description for '<S133>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S133>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_eskf -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S130>/Switch4' incorporates:
   *  DataStoreRead: '<S130>/Data Store Read'
   *  DataTypeConversion: '<S115>/Data Type Conversion7'
   *  DataTypeConversion: '<S130>/Data Type Conversion2'
   *  DataTypeConversion: '<S130>/Data Type Conversion6'
   *  UnaryMinus: '<S130>/Unary Minus'
   *  UnaryMinus: '<S130>/Unary Minus2'
   */
  if (rtu_pass2 > 0.0) {
    rtu_pass2_0 = -((float64)Par_AutoBrightLevel091);
  } else {
    rtu_pass2_0 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S130>/Switch4' */

  /* Product: '<S133>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S133>/sample time'
   *
   * About '<S133>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime *= rtu_pass2_0;

  /* Switch: '<S134>/Switch2' incorporates:
   *  RelationalOperator: '<S134>/LowerRelop1'
   *  RelationalOperator: '<S134>/UpperRelop'
   *  Switch: '<S134>/Switch'
   */
  if (rtb_Add1_eskf > rtb_Switch4_jj5n) {
    rtb_Add1_eskf = rtb_Switch4_jj5n;
  } else if (rtb_Add1_eskf < elapseTime) {
    /* Switch: '<S134>/Switch' */
    rtb_Add1_eskf = elapseTime;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S134>/Switch2' */

  /* Sum: '<S133>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S133>/Delay Input2'
   *
   * Block description for '<S133>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S133>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add1_eskf;

  /* Switch: '<S130>/Switch9' */
  if (rtu_pass2 > 0.0) {
    /* Switch: '<S130>/Switch9' incorporates:
     *  DataTypeConversion: '<S115>/Data Type Conversion7'
     */
    rtb_Switch9_lgmx = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S130>/Switch9' incorporates:
     *  DataTypeConversion: '<S130>/Data Type Conversion1'
     *  UnitDelay: '<S133>/Delay Input2'
     *
     * Block description for '<S133>/Delay Input2':
     *
     *  Store in Global RAM
     */
    rtb_Switch9_lgmx = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S130>/Switch9' */

  /* Switch: '<S115>/Switch1' incorporates:
   *  Constant: '<S115>/Constant7'
   *  Switch: '<S131>/Switch2'
   */
  if (rtu_Trigger2_FO > 0) {
    /* Switch: '<S131>/Switch2' incorporates:
     *  Constant: '<S115>/Constant7'
     *  DataTypeConversion: '<S115>/Data Type Conversion7'
     *  RelationalOperator: '<S131>/LowerRelop1'
     *  RelationalOperator: '<S131>/UpperRelop'
     *  Switch: '<S131>/Switch'
     */
    if (rtb_Switch9_lgmx > rtu_Var_BrightMaxValue) {
      *rty_y_FadeOut2 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch9_lgmx < ((uint16)0U)) {
      /* Switch: '<S131>/Switch' incorporates:
       *  Constant: '<S115>/Constant7'
       */
      *rty_y_FadeOut2 = ((uint16)0U);
    } else {
      *rty_y_FadeOut2 = rtb_Switch9_lgmx;
    }
  } else {
    *rty_y_FadeOut2 = ((uint16)0U);
  }

  /* End of Switch: '<S115>/Switch1' */

  /* Update for UnitDelay: '<S129>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S115>/Data Type Conversion7'
   *
   * Block description for '<S129>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S98>/FadeIn3'
 *    '<S146>/FadeIn3'
 *    '<S50>/FadeIn3'
 *    '<S288>/FadeIn3'
 *    '<S336>/FadeIn3'
 *    '<S240>/FadeIn3'
 *    '<S720>/FadeIn3'
 *    '<S768>/FadeIn3'
 *    '<S672>/FadeIn3'
 */
void App_Model_FadeIn3_Init(DW_FadeIn3_App_Model_T *localDW)
{
  /* InitializeConditions for Switch: '<S113>/Switch1' incorporates:
   *  UnitDelay: '<S113>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S98>/FadeIn3'
 *    '<S146>/FadeIn3'
 *    '<S50>/FadeIn3'
 *    '<S288>/FadeIn3'
 *    '<S336>/FadeIn3'
 *    '<S240>/FadeIn3'
 *    '<S720>/FadeIn3'
 *    '<S768>/FadeIn3'
 *    '<S672>/FadeIn3'
 */
void App_Model_FadeIn3_Reset(DW_FadeIn3_App_Model_T *localDW)
{
  /* InitializeConditions for Switch: '<S113>/Switch1' incorporates:
   *  UnitDelay: '<S113>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S98>/FadeIn3'
 *    '<S146>/FadeIn3'
 *    '<S50>/FadeIn3'
 *    '<S288>/FadeIn3'
 *    '<S336>/FadeIn3'
 *    '<S240>/FadeIn3'
 *    '<S720>/FadeIn3'
 *    '<S768>/FadeIn3'
 *    '<S672>/FadeIn3'
 */
void App_Model_FadeIn3(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger3, float64 rtu_pass3, uint16 *rty_y_FadeIn3, DW_FadeIn3_App_Model_T *localDW)
{
  float64 rtb_Switch3_c4ck;

  /* Switch: '<S113>/Switch' */
  if (rtu_Trigger3 > 0) {
    /* Switch: '<S113>/Switch3' incorporates:
     *  Constant: '<S113>/Constant2'
     *  DataTypeConversion: '<S113>/Data Type Conversion'
     *  Product: '<S113>/Divide'
     */
    rtb_Switch3_c4ck = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
  } else {
    /* Switch: '<S113>/Switch3' incorporates:
     *  Constant: '<S113>/Constant1'
     */
    rtb_Switch3_c4ck = 0.0;
  }

  /* End of Switch: '<S113>/Switch' */
  /* Switch: '<S113>/Switch1' incorporates:
   *  Constant: '<S113>/Constant3'
   */
  if (rtu_Trigger3 <= 0) {
    localDW->UnitDelay_DSTATE = 0.0;
  }

  /* Switch: '<S113>/Switch3' incorporates:
   *  Sum: '<S113>/Add1'
   */
  rtb_Switch3_c4ck += localDW->UnitDelay_DSTATE;

  /* Switch: '<S113>/Switch3' incorporates:
   *  DataTypeConversion: '<S113>/Data Type Conversion'
   *  Logic: '<S113>/AND'
   *  RelationalOperator: '<S121>/FixPt Relational Operator'
   *  UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3 != 0) && (rtu_pass3 != 0.0)) {
    /* Switch: '<S113>/Switch1' incorporates:
     *  DataTypeConversion: '<S113>/Data Type Conversion1'
     */
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S113>/Switch1' incorporates:
     *  DataTypeConversion: '<S113>/Data Type Conversion1'
     */
    localDW->UnitDelay_DSTATE = rtb_Switch3_c4ck;
  }

  /* End of Switch: '<S113>/Switch3' */

  /* Switch: '<S113>/Switch5' */
  if (rtu_pass3 > 0.0) {
    /* Switch: '<S113>/Switch5' incorporates:
     *  DataTypeConversion: '<S113>/Data Type Conversion'
     */
    rtb_Switch3_c4ck = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S113>/Switch5' incorporates:
     *  UnitDelay: '<S113>/Unit Delay'
     */
    rtb_Switch3_c4ck = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S113>/Switch5' */

  /* Switch: '<S113>/Switch2' incorporates:
   *  Constant: '<S113>/Constant4'
   *  Switch: '<S122>/Switch2'
   */
  if (rtu_Trigger3 > 0) {
    /* Switch: '<S122>/Switch2' incorporates:
     *  Constant: '<S113>/Constant4'
     *  DataTypeConversion: '<S113>/Data Type Conversion'
     *  RelationalOperator: '<S122>/LowerRelop1'
     *  RelationalOperator: '<S122>/UpperRelop'
     *  Switch: '<S122>/Switch'
     */
    if (rtb_Switch3_c4ck > (float64)rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn3 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch3_c4ck < (float64)((uint16)0U)) {
      /* Switch: '<S122>/Switch' incorporates:
       *  Constant: '<S113>/Constant4'
       */
      *rty_y_FadeIn3 = ((uint16)0U);
    } else {
      *rty_y_FadeIn3 = (uint16)rtb_Switch3_c4ck;
    }
  } else {
    *rty_y_FadeIn3 = ((uint16)0U);
  }

  /* End of Switch: '<S113>/Switch2' */

  /* Update for UnitDelay: '<S121>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S113>/Data Type Conversion'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S98>/FadeOut3'
 *    '<S146>/FadeOut3'
 *    '<S50>/FadeOut3'
 *    '<S720>/FadeOut3'
 *    '<S768>/FadeOut3'
 *    '<S672>/FadeOut3'
 */
void App_Model_FadeOut3_Init(DW_FadeOut3_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S135>/Delay Input1'
   *
   * Block description for '<S135>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S139>/Delay Input2'
   *
   * Block description for '<S139>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S98>/FadeOut3'
 *    '<S146>/FadeOut3'
 *    '<S50>/FadeOut3'
 *    '<S720>/FadeOut3'
 *    '<S768>/FadeOut3'
 *    '<S672>/FadeOut3'
 */
void App_Model_FadeOut3_Reset(DW_FadeOut3_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S135>/Delay Input1'
   *
   * Block description for '<S135>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S139>/Delay Input2'
   *
   * Block description for '<S139>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S98>/FadeOut3'
 *    '<S146>/FadeOut3'
 *    '<S50>/FadeOut3'
 *    '<S720>/FadeOut3'
 *    '<S768>/FadeOut3'
 *    '<S672>/FadeOut3'
 */
void App_Model_FadeOut3_Enable(DW_FadeOut3_App_Model_T *localDW)
{
  localDW->FadeOut3_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S98>/FadeOut3'
 *    '<S146>/FadeOut3'
 *    '<S50>/FadeOut3'
 *    '<S720>/FadeOut3'
 *    '<S768>/FadeOut3'
 *    '<S672>/FadeOut3'
 */
void App_Model_FadeOut3(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_l5tj;
  float64 rtb_Switch4_bvf1;
  float64 rtu_pass3_0;
  uint16 rtb_Switch9_jute;
  if (localDW->FadeOut3_RESET_ELAPS_T) {
    localDW->FadeOut3_ELAPS_T[0] = 0U;
    localDW->FadeOut3_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut3_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut3_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut3_ELAPS_T[0] = FadeOut3_ELAPS_T_tmp - localDW->FadeOut3_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut3_PREV_T[1];
    if (localDW->FadeOut3_PREV_T[0] > FadeOut3_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut3_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut3_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut3_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut3_RESET_ELAPS_T = false;

  /* Switch: '<S116>/Switch' incorporates:
   *  DataTypeConversion: '<S116>/Data Type Conversion7'
   *  Switch: '<S116>/Switch5'
   */
  if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S136>/Switch4' incorporates:
     *  Constant: '<S116>/Constant5'
     *  DataTypeConversion: '<S116>/Data Type Conversion7'
     *  Product: '<S116>/Divide'
     */
    rtb_Switch4_bvf1 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    rtb_Switch9_jute = rtu_preValue;
  } else {
    /* Switch: '<S136>/Switch4' incorporates:
     *  Constant: '<S116>/Constant4'
     */
    rtb_Switch4_bvf1 = (float64)((uint16)0U);
    rtb_Switch9_jute = rtu_Var_BrightMaxValue;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Sum: '<S116>/Add1' */
  rtb_Add1_l5tj = (float64)rtb_Switch9_jute - rtb_Switch4_bvf1;

  /* SampleTimeMath: '<S139>/sample time'
   *
   * About '<S139>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut3_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut3_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S139>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S116>/Data Type Conversion7'
   *  DataTypeConversion: '<S136>/Data Type Conversion2'
   *  SampleTimeMath: '<S139>/sample time'
   *
   * About '<S139>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_bvf1 = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S116>/Switch8' incorporates:
   *  Constant: '<S116>/Constant2'
   *  DataTypeConversion: '<S116>/Data Type Conversion7'
   *  Logic: '<S116>/AND'
   *  RelationalOperator: '<S135>/FixPt Relational Operator'
   *  Switch: '<S116>/Switch7'
   *  UnitDelay: '<S135>/Delay Input1'
   *
   * Block description for '<S135>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3_FO != 0) && (rtu_pass3 != 0.0)) {
    rtb_Add1_l5tj = (float64)rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S138>/Switch2' incorporates:
     *  Constant: '<S116>/Constant2'
     *  RelationalOperator: '<S138>/LowerRelop1'
     *  RelationalOperator: '<S138>/UpperRelop'
     *  Switch: '<S138>/Switch'
     */
    if (rtb_Add1_l5tj > (float64)rtu_preValue) {
      /* Switch: '<S116>/Switch7' */
      rtb_Add1_l5tj = (float64)rtu_preValue;
    } else if (rtb_Add1_l5tj < (float64)((uint16)0U)) {
      /* Switch: '<S138>/Switch' incorporates:
       *  Constant: '<S116>/Constant2'
       *  Switch: '<S116>/Switch7'
       */
      rtb_Add1_l5tj = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S138>/Switch2' */
  } else {
    rtb_Add1_l5tj = (float64)((uint16)0U);
  }

  /* End of Switch: '<S116>/Switch8' */

  /* Sum: '<S139>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S139>/Delay Input2'
   *
   * Block description for '<S139>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S139>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_l5tj -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S136>/Switch4' incorporates:
   *  DataStoreRead: '<S136>/Data Store Read'
   *  DataTypeConversion: '<S116>/Data Type Conversion7'
   *  DataTypeConversion: '<S136>/Data Type Conversion2'
   *  DataTypeConversion: '<S136>/Data Type Conversion6'
   *  UnaryMinus: '<S136>/Unary Minus'
   *  UnaryMinus: '<S136>/Unary Minus2'
   */
  if (rtu_pass3 > 0.0) {
    rtu_pass3_0 = -((float64)Par_AutoBrightLevel091);
  } else {
    rtu_pass3_0 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S136>/Switch4' */

  /* Product: '<S139>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S139>/sample time'
   *
   * About '<S139>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime *= rtu_pass3_0;

  /* Switch: '<S140>/Switch2' incorporates:
   *  RelationalOperator: '<S140>/LowerRelop1'
   *  RelationalOperator: '<S140>/UpperRelop'
   *  Switch: '<S140>/Switch'
   */
  if (rtb_Add1_l5tj > rtb_Switch4_bvf1) {
    rtb_Add1_l5tj = rtb_Switch4_bvf1;
  } else if (rtb_Add1_l5tj < elapseTime) {
    /* Switch: '<S140>/Switch' */
    rtb_Add1_l5tj = elapseTime;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S140>/Switch2' */

  /* Sum: '<S139>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S139>/Delay Input2'
   *
   * Block description for '<S139>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S139>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add1_l5tj;

  /* Switch: '<S136>/Switch9' */
  if (rtu_pass3 > 0.0) {
    /* Switch: '<S136>/Switch9' incorporates:
     *  DataTypeConversion: '<S116>/Data Type Conversion7'
     */
    rtb_Switch9_jute = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S136>/Switch9' incorporates:
     *  DataTypeConversion: '<S136>/Data Type Conversion1'
     *  UnitDelay: '<S139>/Delay Input2'
     *
     * Block description for '<S139>/Delay Input2':
     *
     *  Store in Global RAM
     */
    rtb_Switch9_jute = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S136>/Switch9' */

  /* Switch: '<S116>/Switch1' incorporates:
   *  Constant: '<S116>/Constant7'
   *  Switch: '<S137>/Switch2'
   */
  if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S137>/Switch2' incorporates:
     *  Constant: '<S116>/Constant7'
     *  DataTypeConversion: '<S116>/Data Type Conversion7'
     *  RelationalOperator: '<S137>/LowerRelop1'
     *  RelationalOperator: '<S137>/UpperRelop'
     *  Switch: '<S137>/Switch'
     */
    if (rtb_Switch9_jute > rtu_Var_BrightMaxValue) {
      *rty_y_FadeOut3 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch9_jute < ((uint16)0U)) {
      /* Switch: '<S137>/Switch' incorporates:
       *  Constant: '<S116>/Constant7'
       */
      *rty_y_FadeOut3 = ((uint16)0U);
    } else {
      *rty_y_FadeOut3 = rtb_Switch9_jute;
    }
  } else {
    *rty_y_FadeOut3 = ((uint16)0U);
  }

  /* End of Switch: '<S116>/Switch1' */

  /* Update for UnitDelay: '<S135>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S116>/Data Type Conversion7'
   *
   * Block description for '<S135>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control1(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    localDW->pass1 = 0.0;

    /* Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut  ||... */
  } else if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
              WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn)) {
    /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    localDW->pass1 = 0.0;
  } else if ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) {
    if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 1.0)) {
      localDW->pass1 = 1.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 1.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_cs5u;
      localB->Var_BrightMaxValue_pd5c = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_fccy = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_pd5c, localB->preValue, localB->Trigger1_FO, localB->pass1_fccy, &localB->Switch1_odey, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S98>/FadeOut1' */
    } else {
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_cs5u;
      localB->Var_BrightMaxValue_pd5c = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_fccy = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_pd5c, localB->preValue, localB->Trigger1_FO, localB->pass1_fccy, &localB->Switch1_odey, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S98>/FadeOut1' */
      localDW->pass1 = 0.0;
    }
  } else {
    /* no actions */
  }

  if ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 2.0)) {
      localDW->pass1 = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
      localB->Var_BrightMaxValue_pd5c = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_fccy = 1.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_pd5c, localB->preValue, localB->Trigger1_FO, localB->pass1_fccy, &localB->Switch1_odey, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S98>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_pd5c = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 1;
      localB->pass1_fccy = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_pd5c, localB->preValue, localB->Trigger1_FO, localB->pass1_fccy, &localB->Switch1_odey, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S98>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch1_odey;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
      localDW->pass1 = 0.0;
    }
  }
}

/* Function for Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control2(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    localDW->pass2 = 0.0;
  } else if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
              WPCIndCmdState__3rdChrgOn)) {
    localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    localDW->pass2 = 0.0;
  } else if ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) {
    if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 1.0)) {
      localDW->pass2 = 1.0;
      localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 1.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_gauv;
      localB->Var_BrightMaxValue_agl2 = rtu_Var_BrightMaxValue;
      localB->preValue_f2d1 = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_a01e = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_agl2, localB->preValue_f2d1, localB->Trigger2_FO, localB->pass2_a01e, &localB->Switch1_dv4w, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S98>/FadeOut2' */
    } else {
      localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_gauv;
      localB->Var_BrightMaxValue_agl2 = rtu_Var_BrightMaxValue;
      localB->preValue_f2d1 = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_a01e = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_agl2, localB->preValue_f2d1, localB->Trigger2_FO, localB->pass2_a01e, &localB->Switch1_dv4w, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S98>/FadeOut2' */
      localDW->pass2 = 0.0;
    }
  } else {
    /* no actions */
  }

  if ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 2.0)) {
      localDW->pass2 = 2.0;
      localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
      localB->Var_BrightMaxValue_agl2 = rtu_Var_BrightMaxValue;
      localB->preValue_f2d1 = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_a01e = 1.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_agl2, localB->preValue_f2d1, localB->Trigger2_FO, localB->pass2_a01e, &localB->Switch1_dv4w, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S98>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_agl2 = rtu_Var_BrightMaxValue;
      localB->preValue_f2d1 = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 1;
      localB->pass2_a01e = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_agl2, localB->preValue_f2d1, localB->Trigger2_FO, localB->pass2_a01e, &localB->Switch1_dv4w, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S98>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch1_dv4w;
      localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
      localDW->pass2 = 0.0;
    }
  }
}

/* Function for Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control3(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }

    localDW->pass3 = 0.0;
  } else {
    switch (rtu_Input_INT_WPCIndCmdState) {
     case WPCIndCmdState__3rdChrgOn:
      localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
      localDW->pass3 = 0.0;
      break;

     case WPCIndCmdState__3rdChrgFadeIn:
      if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 1.0)) {
        localDW->pass3 = 1.0;
        localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 1.0;

        /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_g0z4 = rtu_Var_BrightMaxValue;
        localB->preValue_j1fr = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_j1af = 0.0;

        /* Outputs for Function Call SubSystem: '<S98>/FadeOut3' */
        App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g0z4, localB->preValue_j1fr, localB->Trigger3_FO, localB->pass3_j1af, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S98>/FadeOut3' */
      } else {
        localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 0.0;

        /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_g0z4 = rtu_Var_BrightMaxValue;
        localB->preValue_j1fr = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_j1af = 0.0;

        /* Outputs for Function Call SubSystem: '<S98>/FadeOut3' */
        App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g0z4, localB->preValue_j1fr, localB->Trigger3_FO, localB->pass3_j1af, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S98>/FadeOut3' */
        localDW->pass3 = 0.0;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  if ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 2.0)) {
      localDW->pass3 = 2.0;
      localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
      localB->Var_BrightMaxValue_g0z4 = rtu_Var_BrightMaxValue;
      localB->preValue_j1fr = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 0;
      localB->pass3_j1af = 1.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut3' */
      App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g0z4, localB->preValue_j1fr, localB->Trigger3_FO, localB->pass3_j1af, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S98>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_g0z4 = rtu_Var_BrightMaxValue;
      localB->preValue_j1fr = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 1;
      localB->pass3_j1af = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeOut3' */
      App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g0z4, localB->preValue_j1fr, localB->Trigger3_FO, localB->pass3_j1af, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S98>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = localB->Switch1;
      localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
      localDW->pass3 = 0.0;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S715>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S763>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S667>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_C_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, DW_Green_IND_with_Animation_C_T *localDW)
{
  localDW->is_active_c427_IndyOutputContro = 0U;
  localDW->pass1 = 0.0;
  localDW->pass2 = 0.0;
  localDW->pass3 = 0.0;
  *rty_Var_GreenINDwithAnimation1 = 0U;
  *rty_Var_GreenINDwithAnimation2 = 0U;
  *rty_Var_GreenINDwithAnimation3 = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S98>/FadeIn1' */
  App_Model_FadeIn1_Init(&localDW->FadeIn1);

  /* End of SystemInitialize for SubSystem: '<S98>/FadeIn1' */

  /* SystemInitialize for Function Call SubSystem: '<S98>/FadeOut1' */
  App_Model_FadeOut1_Init(&localDW->FadeOut1);

  /* End of SystemInitialize for SubSystem: '<S98>/FadeOut1' */

  /* SystemInitialize for Function Call SubSystem: '<S98>/FadeIn2' */
  App_Model_FadeIn2_Init(&localDW->FadeIn2);

  /* End of SystemInitialize for SubSystem: '<S98>/FadeIn2' */

  /* SystemInitialize for Function Call SubSystem: '<S98>/FadeOut2' */
  App_Model_FadeOut2_Init(&localDW->FadeOut2);

  /* End of SystemInitialize for SubSystem: '<S98>/FadeOut2' */

  /* SystemInitialize for Function Call SubSystem: '<S98>/FadeIn3' */
  App_Model_FadeIn3_Init(&localDW->FadeIn3);

  /* End of SystemInitialize for SubSystem: '<S98>/FadeIn3' */

  /* SystemInitialize for Function Call SubSystem: '<S98>/FadeOut3' */
  App_Model_FadeOut3_Init(&localDW->FadeOut3);

  /* End of SystemInitialize for SubSystem: '<S98>/FadeOut3' */
}

/*
 * Enable for atomic system:
 *    '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S715>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S763>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S667>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_Enable(DW_Green_IND_with_Animation_C_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S98>/FadeIn1' */
  App_Model_FadeIn1_Reset(&localDW->FadeIn1);

  /* End of SystemReset for SubSystem: '<S98>/FadeIn1' */

  /* SystemReset for Function Call SubSystem: '<S98>/FadeOut1' */
  App_Model_FadeOut1_Reset(&localDW->FadeOut1);

  /* End of SystemReset for SubSystem: '<S98>/FadeOut1' */

  /* Enable for Function Call SubSystem: '<S98>/FadeOut1' */
  App_Model_FadeOut1_Enable(&localDW->FadeOut1);

  /* End of Enable for SubSystem: '<S98>/FadeOut1' */

  /* SystemReset for Function Call SubSystem: '<S98>/FadeIn2' */
  App_Model_FadeIn2_Reset(&localDW->FadeIn2);

  /* End of SystemReset for SubSystem: '<S98>/FadeIn2' */

  /* SystemReset for Function Call SubSystem: '<S98>/FadeOut2' */
  App_Model_FadeOut2_Reset(&localDW->FadeOut2);

  /* End of SystemReset for SubSystem: '<S98>/FadeOut2' */

  /* Enable for Function Call SubSystem: '<S98>/FadeOut2' */
  App_Model_FadeOut2_Enable(&localDW->FadeOut2);

  /* End of Enable for SubSystem: '<S98>/FadeOut2' */

  /* SystemReset for Function Call SubSystem: '<S98>/FadeIn3' */
  App_Model_FadeIn3_Reset(&localDW->FadeIn3);

  /* End of SystemReset for SubSystem: '<S98>/FadeIn3' */

  /* SystemReset for Function Call SubSystem: '<S98>/FadeOut3' */
  App_Model_FadeOut3_Reset(&localDW->FadeOut3);

  /* End of SystemReset for SubSystem: '<S98>/FadeOut3' */

  /* Enable for Function Call SubSystem: '<S98>/FadeOut3' */
  App_Model_FadeOut3_Enable(&localDW->FadeOut3);

  /* End of Enable for SubSystem: '<S98>/FadeOut3' */
}

/*
 * Output and update for atomic system:
 *    '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S715>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S763>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S667>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if ((uint32)localDW->is_active_c427_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c427_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_cs5u, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S98>/FadeIn1' */
    localB->Var_BrightMaxValue_pd5c = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_GreenINDwithAnimation1;
    localB->Trigger1_FO = 0;
    localB->pass1_fccy = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeOut1' */
    App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_pd5c, localB->preValue, localB->Trigger1_FO, localB->pass1_fccy, &localB->Switch1_odey, &localDW->FadeOut1);

    /* End of Outputs for SubSystem: '<S98>/FadeOut1' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /* 1. In the case of 1st LED */
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /*  ||Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);

      /* 2. In the case of 1st LED, Abnormal */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_pwkg = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_pwkg, localB->Trigger2, localB->pass2, &localB->Switch2_gauv, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S98>/FadeIn2' */
    localB->Var_BrightMaxValue_agl2 = rtu_Var_BrightMaxValue;
    localB->preValue_f2d1 = *rty_Var_GreenINDwithAnimation2;
    localB->Trigger2_FO = 0;
    localB->pass2_a01e = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeOut2' */
    App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_agl2, localB->preValue_f2d1, localB->Trigger2_FO, localB->pass2_a01e, &localB->Switch1_dv4w, &localDW->FadeOut2);

    /* End of Outputs for SubSystem: '<S98>/FadeOut2' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /* 1. In the case of 2nd LED */
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || ((uint32)
         rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);

      /* 2. In the case of 2nd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_cemj = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_cemj, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S98>/FadeIn3' */
    localB->Var_BrightMaxValue_g0z4 = rtu_Var_BrightMaxValue;
    localB->preValue_j1fr = *rty_Var_GreenINDwithAnimation3;
    localB->Trigger3_FO = 0;
    localB->pass3_j1af = 0.0;

    /* Outputs for Function Call SubSystem: '<S98>/FadeOut3' */
    App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g0z4, localB->preValue_j1fr, localB->Trigger3_FO, localB->pass3_j1af, &localB->Switch1, &localDW->FadeOut3);

    /* End of Outputs for SubSystem: '<S98>/FadeOut3' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }

    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);

      /* 2. In the case of 3rd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1. In the case of 1st LED */
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /*  ||Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);

      /* 2. In the case of 1st LED, Abnormal */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 2nd LED */
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || ((uint32)
         rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);

      /* 2. In the case of 2nd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);

      /* 2. In the case of 3rd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }
  }

  /* End of Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for atomic system:
 *    '<S93>/IND_Output_Control_Function_Flow_Graph'
 *    '<S141>/IND_Output_Control_Function_Flow_Graph'
 *    '<S715>/IND_Output_Control_Function_Flow_Graph'
 *    '<S763>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Functio_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT,
  DW_IND_Output_Control_Functio_T *localDW)
{
  localDW->is_active_c428_IndyOutputContro = 0U;
  *rty_Output_AmberIND_OUT = 0U;
  *rty_Output_GreenIND_OUT = 0U;
  *rty_Output_GreenIND2_OUT = 0U;
  *rty_Output_GreenIND3_OUT = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S93>/IND_Output_Control_Function_Flow_Graph'
 *    '<S141>/IND_Output_Control_Function_Flow_Graph'
 *    '<S715>/IND_Output_Control_Function_Flow_Graph'
 *    '<S763>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Function_Flo(WPCIndCmdState rtu_Input_INT_WPCIndCmdState, WPCIndUSMState rtu_Var_INT_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Functio_T *localDW)
{
  /* Chart: '<S93>/IND_Output_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c428_IndyOutputContro == 0U) {
    localDW->is_active_c428_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Output_GreenIND_OUT = (uint16)0.0;
        *rty_Output_GreenIND2_OUT = (uint16)0.0;
        *rty_Output_GreenIND3_OUT = (uint16)0.0;
        *rty_Output_AmberIND_OUT = (uint16)0.0;
      } else {
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = 0U;
      }
    } else {
      *rty_Output_GreenIND_OUT = MAX_uint16_T;
      *rty_Output_GreenIND2_OUT = MAX_uint16_T;
      *rty_Output_GreenIND3_OUT = MAX_uint16_T;
      *rty_Output_AmberIND_OUT = MAX_uint16_T;
    }

    /* Ref_Off */
    /* 1 */
    if ((uint32)rtu_Var_INT_WPCIndUSMState == WPCIndUSMState__Type2) {
      if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
           WPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut) || ((uint32)
           rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
           WPCIndCmdState__2ndChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)
           rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
           WPCIndCmdState__ChrgFadeOut3_2)) {
        /* 231010 */
        /* Green IND Light */
        *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
        *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
        *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
        if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            *rty_Output_AmberIND_OUT = (uint16)0.0;
          } else {
            *rty_Output_AmberIND_OUT = 0U;
          }
        } else {
          *rty_Output_AmberIND_OUT = MAX_uint16_T;
        }
      } else if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
                  WPCIndCmdState__ErrorFadeOut)) {
        /* Amber IND light */
        if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            *rty_Output_GreenIND_OUT = (uint16)0.0;
            *rty_Output_GreenIND2_OUT = (uint16)0.0;
            *rty_Output_GreenIND3_OUT = (uint16)0.0;
          } else {
            *rty_Output_GreenIND_OUT = 0U;
            *rty_Output_GreenIND2_OUT = 0U;
            *rty_Output_GreenIND3_OUT = 0U;
          }
        } else {
          *rty_Output_GreenIND_OUT = MAX_uint16_T;
          *rty_Output_GreenIND2_OUT = MAX_uint16_T;
          *rty_Output_GreenIND3_OUT = MAX_uint16_T;
        }

        *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
      } else if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Output_GreenIND_OUT = (uint16)0.0;
          *rty_Output_GreenIND2_OUT = (uint16)0.0;
          *rty_Output_GreenIND3_OUT = (uint16)0.0;
          *rty_Output_AmberIND_OUT = (uint16)0.0;
        } else {
          *rty_Output_GreenIND_OUT = 0U;
          *rty_Output_GreenIND2_OUT = 0U;
          *rty_Output_GreenIND3_OUT = 0U;
          *rty_Output_AmberIND_OUT = 0U;
        }
      } else {
        *rty_Output_GreenIND_OUT = MAX_uint16_T;
        *rty_Output_GreenIND2_OUT = MAX_uint16_T;
        *rty_Output_GreenIND3_OUT = MAX_uint16_T;
        *rty_Output_AmberIND_OUT = MAX_uint16_T;

        /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
           Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
      }
    } else {
      *rty_Output_GreenIND_OUT = rtu_Var_GreenIND;
      *rty_Output_GreenIND2_OUT = rtu_Var_GreenIND;
      *rty_Output_GreenIND3_OUT = rtu_Var_GreenIND;
      *rty_Output_AmberIND_OUT = rtu_Var_AmberIND;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_Var_INT_WPCIndUSMState == WPCIndUSMState__Type2) {
    if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut) || ((uint32)
         rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__2ndChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__ChrgFadeOut3_2)) {
      /* 231010 */
      /* Green IND Light */
      *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
      *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
      *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Output_AmberIND_OUT = (uint16)0.0;
        } else {
          *rty_Output_AmberIND_OUT = 0U;
        }
      } else {
        *rty_Output_AmberIND_OUT = MAX_uint16_T;
      }
    } else if (((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPCIndCmdState ==
                WPCIndCmdState__ErrorFadeOut)) {
      /* Amber IND light */
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Output_GreenIND_OUT = (uint16)0.0;
          *rty_Output_GreenIND2_OUT = (uint16)0.0;
          *rty_Output_GreenIND3_OUT = (uint16)0.0;
        } else {
          *rty_Output_GreenIND_OUT = 0U;
          *rty_Output_GreenIND2_OUT = 0U;
          *rty_Output_GreenIND3_OUT = 0U;
        }
      } else {
        *rty_Output_GreenIND_OUT = MAX_uint16_T;
        *rty_Output_GreenIND2_OUT = MAX_uint16_T;
        *rty_Output_GreenIND3_OUT = MAX_uint16_T;
      }

      *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Output_GreenIND_OUT = (uint16)0.0;
        *rty_Output_GreenIND2_OUT = (uint16)0.0;
        *rty_Output_GreenIND3_OUT = (uint16)0.0;
        *rty_Output_AmberIND_OUT = (uint16)0.0;
      } else {
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = 0U;
      }
    } else {
      *rty_Output_GreenIND_OUT = MAX_uint16_T;
      *rty_Output_GreenIND2_OUT = MAX_uint16_T;
      *rty_Output_GreenIND3_OUT = MAX_uint16_T;
      *rty_Output_AmberIND_OUT = MAX_uint16_T;

      /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
         Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
    }
  } else {
    *rty_Output_GreenIND_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND2_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND3_OUT = rtu_Var_GreenIND;
    *rty_Output_AmberIND_OUT = rtu_Var_AmberIND;
  }

  /* End of Chart: '<S93>/IND_Output_Control_Function_Flow_Graph' */
}

/* Function for Chart: '<S93>/WPC_IND_Output_Control_Function' */
static void WPC_IND_Output_Control_Fun_d4ue(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue)
{
  /*  Step0  */
  /*  Step1  */
  /*  Step2  */
  /*  Step3  */
  /*  Step4  */
  /*  Step5  */
  /*  Step6  */
  /*  Step7  */
  /*  Step8  */
  /*  Step9  */
  /*  Step10  */
  /*  Step11  */
  /*  Step12  */
  /*  Step13  */
  /*  Step14  */
  /*  Step15  */
  /*  Step16  */
  /*  Step17  */
  /*  Step18  */
  /*  Step19  */
  /*  Step20  */
  /*  Step21  */
  switch (rtu_Input_RheoStatLevel) {
   case 0x0:
    /*  Step0  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel00;
    break;

   case 0x1:
    /*  Step1  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel01;
    break;

   case 0x2:
    /*  Step2  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel02;
    break;

   case 0x3:
    /*  Step3  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel03;
    break;

   case 0x4:
    /*  Step4  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel04;
    break;

   case 0x5:
    /*  Step5  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel05;
    break;

   case 0x6:
    /*  Step6  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel06;
    break;

   case 0x7:
    /*  Step7  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel07;
    break;

   case 0x8:
    /*  Step8  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel08;
    break;

   case 0x9:
    /*  Step9  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel09;
    break;

   case 0xA:
    /*  Step10  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel10;
    break;

   case 0xB:
    /*  Step11  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel11;
    break;

   case 0xC:
    /*  Step12  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel12;
    break;

   case 0xD:
    /*  Step13  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel13;
    break;

   case 0xE:
    /*  Step14  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel14;
    break;

   case 0xF:
    /*  Step15  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel15;
    break;

   case 0x10:
    /*  Step16  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel16;
    break;

   case 0x11:
    /*  Step17  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel17;
    break;

   case 0x12:
    /*  Step18  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel18;
    break;

   case 0x13:
    /*  Step19  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel19;
    break;

   case 0x14:
    /*  Step20  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel20;
    break;

   case 0x15:
    /*  Step21  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel21;
    break;

   default:
    /*  Default  */
    /*  Step0  */
    *rty_RheoLevelValue = Par_RheostatBrightLevel00;
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S93>/WPC_IND_Output_Control_Function'
 *    '<S141>/WPC_IND_Output_Control_Function'
 *    '<S283>/WPC_IND_Output_Control_Function'
 *    '<S331>/WPC_IND_Output_Control_Function'
 *    '<S521>/RWPC_IND_Output_Control_Function'
 *    '<S556>/RWPC_IND_Output_Control_Function'
 *    '<S715>/WPC_IND_Output_Control_Function'
 *    '<S763>/WPC_IND_Output_Control_Function'
 */
void WPC_IND_Output_Control_Fun_Init(uint16 *rty_RheoLevelValue, DW_WPC_IND_Output_Control_Fun_T *localDW)
{
  localDW->is_active_c343_IndyOutputContro = 0U;
  *rty_RheoLevelValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S93>/WPC_IND_Output_Control_Function'
 *    '<S141>/WPC_IND_Output_Control_Function'
 *    '<S283>/WPC_IND_Output_Control_Function'
 *    '<S331>/WPC_IND_Output_Control_Function'
 *    '<S521>/RWPC_IND_Output_Control_Function'
 *    '<S556>/RWPC_IND_Output_Control_Function'
 *    '<S715>/WPC_IND_Output_Control_Function'
 *    '<S763>/WPC_IND_Output_Control_Function'
 */
void WPC_IND_Output_Control_Function(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue, DW_WPC_IND_Output_Control_Fun_T *localDW)
{
  /* Chart: '<S93>/WPC_IND_Output_Control_Function' */
  if ((uint32)localDW->is_active_c343_IndyOutputContro == 0U) {
    localDW->is_active_c343_IndyOutputContro = 1U;
    WPC_IND_Output_Control_Fun_d4ue(rtu_Input_RheoStatLevel, rty_RheoLevelValue);
  } else {
    WPC_IND_Output_Control_Fun_d4ue(rtu_Input_RheoStatLevel, rty_RheoLevelValue);
  }

  /* End of Chart: '<S93>/WPC_IND_Output_Control_Function' */
}

/*
 * System initialize for action system:
 *    '<S28>/RheoStatIndyOutputControl_Type1'
 *    '<S645>/RheoStatIndyOutputControl_Type1'
 */
void RheoStatIndyOutputControl__Init(B_RheoStatIndyOutputControl_T_T *localB, DW_RheoStatIndyOutputControl__T *localDW)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT_gpwj;
  uint16 rtb_Output_GreenIND_OUT_a403;
  uint16 rtb_Output_GreenIND2_OUT_bmd1;
  uint16 rtb_Output_GreenIND3_OUT_deok;
  uint16 rtb_Var_GreenIND_i0tx;
  uint16 rtb_Var_AmberIND_ajdj;

  /* SystemInitialize for Chart: '<S93>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&localB->RheoLevelValue, &localDW->sf_WPC_IND_Output_Control_Funct);

  /* SystemInitialize for Chart: '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_Init(&localB->Var_BrightMaxValue, &localDW->sf_Bright_Max_Value_Control_Fun);

  /* SystemInitialize for Chart: '<S93>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_i0tx, &localDW->sf_Green_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S93>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_ajdj, &localDW->sf_Amber_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_C_Init(&localB->Var_GreenINDwithAnimation1, &localB->Var_GreenINDwithAnimation2, &localB->Var_GreenINDwithAnimation3, &localDW->sf_Green_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_C_Init(&localB->Var_AmberINDwithAnimation, &localDW->sf_Amber_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S93>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Functio_Init(&rtb_Output_AmberIND_OUT_gpwj, &rtb_Output_GreenIND_OUT_a403, &rtb_Output_GreenIND2_OUT_bmd1, &rtb_Output_GreenIND3_OUT_deok,
    &localDW->sf_IND_Output_Control_Function_);
}

/*
 * Enable for action system:
 *    '<S28>/RheoStatIndyOutputControl_Type1'
 *    '<S645>/RheoStatIndyOutputControl_Type1'
 */
void RheoStatIndyOutputContro_Enable(DW_RheoStatIndyOutputControl__T *localDW)
{
  /* Enable for Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_Enable(&localDW->sf_Green_IND_with_Animation_Con);

  /* Enable for Chart: '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_Enable(&localDW->sf_Amber_IND_with_Animation_Con);
}

/*
 * Output and update for action system:
 *    '<S28>/RheoStatIndyOutputControl_Type1'
 *    '<S645>/RheoStatIndyOutputControl_Type1'
 */
void RheoStatIndyOutputControl_Type1(RT_MODEL_App_Model_T * const App_Model_M, WPCIndUSMState rtu_IND_WPCIndUSMState, RheostatOption rtu_C_RheostatOption, Bool rtu_C_b_IntTailOn, Bool rtu_C_DetentOut,
  C_RheoStatLevel rtu_C_RheoStatLevel, Bool rtu_b_GreenINDCmd, Bool rtu_b_AmberINDCmd, WPCIndCmdState rtu_INT_WPCIndCmdState, Bool rtu_b_SyncAmber, uint16 *rty_P_GreenIND_OUT, uint16
  *rty_P_GreenIND2_OUT, uint16 *rty_P_GreenIND3_OUT, uint16 *rty_P_AmberIND_OUT, B_RheoStatIndyOutputControl_T_T *localB, DW_RheoStatIndyOutputControl__T *localDW)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT_gpwj;
  uint16 rtb_Output_GreenIND_OUT_a403;
  uint16 rtb_Output_GreenIND2_OUT_bmd1;
  uint16 rtb_Output_GreenIND3_OUT_deok;
  uint16 rtb_Var_GreenIND_i0tx;
  uint16 rtb_Var_AmberIND_ajdj;

  /* Chart: '<S93>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Function(rtu_C_RheoStatLevel, &localB->RheoLevelValue, &localDW->sf_WPC_IND_Output_Control_Funct);

  /* Chart: '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_Functi(rtu_C_DetentOut, rtu_C_RheostatOption, rtu_C_b_IntTailOn, localB->RheoLevelValue, &localB->Var_BrightMaxValue, &localDW->sf_Bright_Max_Value_Control_Fun);

  /* Chart: '<S93>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Flow(rtu_b_GreenINDCmd, localB->Var_BrightMaxValue, &rtb_Var_GreenIND_i0tx, &localDW->sf_Green_IND_Control_Function_F);

  /* Chart: '<S93>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Flow(rtu_b_AmberINDCmd, localB->Var_BrightMaxValue, &rtb_Var_AmberIND_ajdj, &localDW->sf_Amber_IND_Control_Function_F);

  /* Chart: '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_Contro(App_Model_M, localB->Var_BrightMaxValue, rtu_INT_WPCIndCmdState, &localB->Var_GreenINDwithAnimation1, &localB->Var_GreenINDwithAnimation2,
    &localB->Var_GreenINDwithAnimation3, &localB->sf_Green_IND_with_Animation_Con, &localDW->sf_Green_IND_with_Animation_Con);

  /* Chart: '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_Contro(App_Model_M, localB->Var_BrightMaxValue, rtu_b_SyncAmber, rtu_INT_WPCIndCmdState, &localB->Var_AmberINDwithAnimation, &localB->sf_Amber_IND_with_Animation_Con,
    &localDW->sf_Amber_IND_with_Animation_Con);

  /* Chart: '<S93>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Function_Flo(rtu_INT_WPCIndCmdState, rtu_IND_WPCIndUSMState, rtb_Var_GreenIND_i0tx, rtb_Var_AmberIND_ajdj, localB->Var_GreenINDwithAnimation2, localB->Var_GreenINDwithAnimation3,
    localB->Var_GreenINDwithAnimation1, localB->Var_AmberINDwithAnimation, &rtb_Output_AmberIND_OUT_gpwj, &rtb_Output_GreenIND_OUT_a403, &rtb_Output_GreenIND2_OUT_bmd1, &rtb_Output_GreenIND3_OUT_deok,
    &localDW->sf_IND_Output_Control_Function_);

  /* SignalConversion generated from: '<S43>/P_AmberIND_OUT' */
  *rty_P_AmberIND_OUT = rtb_Output_AmberIND_OUT_gpwj;

  /* SignalConversion generated from: '<S43>/P_GreenIND2_OUT' */
  *rty_P_GreenIND2_OUT = rtb_Output_GreenIND2_OUT_bmd1;

  /* SignalConversion generated from: '<S43>/P_GreenIND3_OUT' */
  *rty_P_GreenIND3_OUT = rtb_Output_GreenIND3_OUT_deok;

  /* SignalConversion generated from: '<S43>/P_GreenIND_OUT' */
  *rty_P_GreenIND_OUT = rtb_Output_GreenIND_OUT_a403;
}

/*
 * System initialize for atomic system:
 *    '<S141>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S331>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S556>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S763>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Cont_abam_Init(uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_nvtj_T *localDW)
{
  localDW->is_active_c356_IndyOutputContro = 0U;
  *rty_Var_BrightMaxValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S141>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S331>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S556>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S763>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_F_bk5u(RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_nvtj_T
  *localDW)
{
  /* Chart: '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c356_IndyOutputContro == 0U) {
    localDW->is_active_c356_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_BrightMaxValue = Off;

    /* 1 */
    switch (rtu_Input_RheostatOption) {
     case RheostatOption_On:
      if ((uint32)rtu_Input_b_IntTailOn == On) {
        *rty_Var_BrightMaxValue = rtu_RheoLevelValue;
      } else {
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;

     case RheostatOption_Off:
      if ((uint32)rtu_Input_b_IntTailOn == On) {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
      } else {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;

     default:
      /* no actions */
      break;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1 */
    switch (rtu_Input_RheostatOption) {
     case RheostatOption_On:
      if ((uint32)rtu_Input_b_IntTailOn == On) {
        *rty_Var_BrightMaxValue = rtu_RheoLevelValue;
      } else {
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;

     case RheostatOption_Off:
      if ((uint32)rtu_Input_b_IntTailOn == On) {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
      } else {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  /* End of Chart: '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
}

/*
 * System initialize for action system:
 *    '<S28>/RheoStatIndyOutputControl_Type2'
 *    '<S645>/RheoStatIndyOutputControl_Type2'
 */
void RheoStatIndyOutputCon_dc24_Init(B_RheoStatIndyOutputCont_h4yx_T *localB, DW_RheoStatIndyOutputCon_gpfz_T *localDW)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT_enci;
  uint16 rtb_Output_GreenIND_OUT_griu;
  uint16 rtb_Output_GreenIND2_OUT_ljox;
  uint16 rtb_Output_GreenIND3_OUT_myvy;
  uint16 rtb_Var_GreenIND_krbh;
  uint16 rtb_Var_AmberIND_j0tc;

  /* SystemInitialize for Chart: '<S141>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&localB->RheoLevelValue, &localDW->sf_WPC_IND_Output_Control_Funct);

  /* SystemInitialize for Chart: '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Cont_abam_Init(&localB->Var_BrightMaxValue, &localDW->sf_Bright_Max_Value_Control_Fun);

  /* SystemInitialize for Chart: '<S141>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_krbh, &localDW->sf_Green_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S141>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_j0tc, &localDW->sf_Amber_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_C_Init(&localB->Var_GreenINDwithAnimation1, &localB->Var_GreenINDwithAnimation2, &localB->Var_GreenINDwithAnimation3, &localDW->sf_Green_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_C_Init(&localB->Var_AmberINDwithAnimation, &localDW->sf_Amber_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S141>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Functio_Init(&rtb_Output_AmberIND_OUT_enci, &rtb_Output_GreenIND_OUT_griu, &rtb_Output_GreenIND2_OUT_ljox, &rtb_Output_GreenIND3_OUT_myvy,
    &localDW->sf_IND_Output_Control_Function_);
}

/*
 * Enable for action system:
 *    '<S28>/RheoStatIndyOutputControl_Type2'
 *    '<S645>/RheoStatIndyOutputControl_Type2'
 */
void RheoStatIndyOutputC_jyjj_Enable(DW_RheoStatIndyOutputCon_gpfz_T *localDW)
{
  /* Enable for Chart: '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_Enable(&localDW->sf_Green_IND_with_Animation_Con);

  /* Enable for Chart: '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_Enable(&localDW->sf_Amber_IND_with_Animation_Con);
}

/*
 * Output and update for action system:
 *    '<S28>/RheoStatIndyOutputControl_Type2'
 *    '<S645>/RheoStatIndyOutputControl_Type2'
 */
void RheoStatIndyOutputControl_Type2(RT_MODEL_App_Model_T * const App_Model_M, WPCIndUSMState rtu_IND_WPCIndUSMState, RheostatOption rtu_C_RheostatOption, Bool rtu_b_IntTailOn, C_RheoStatLevel
  rtu_C_RheoStatLevel, Bool rtu_b_GreenINDCmd, Bool rtu_b_AmberINDCmd, WPCIndCmdState rtu_INT_WPCIndCmdState, Bool rtu_b_SyncAmber, uint16 *rty_P_GreenIND_OUT, uint16 *rty_P_GreenIND2_OUT, uint16
  *rty_P_GreenIND3_OUT, uint16 *rty_P_AmberIND_OUT, B_RheoStatIndyOutputCont_h4yx_T *localB, DW_RheoStatIndyOutputCon_gpfz_T *localDW)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT_enci;
  uint16 rtb_Output_GreenIND_OUT_griu;
  uint16 rtb_Output_GreenIND2_OUT_ljox;
  uint16 rtb_Output_GreenIND3_OUT_myvy;
  uint16 rtb_Var_GreenIND_krbh;
  uint16 rtb_Var_AmberIND_j0tc;

  /* Chart: '<S141>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Function(rtu_C_RheoStatLevel, &localB->RheoLevelValue, &localDW->sf_WPC_IND_Output_Control_Funct);

  /* Chart: '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_bk5u(rtu_C_RheostatOption, rtu_b_IntTailOn, localB->RheoLevelValue, &localB->Var_BrightMaxValue, &localDW->sf_Bright_Max_Value_Control_Fun);

  /* Chart: '<S141>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Flow(rtu_b_GreenINDCmd, localB->Var_BrightMaxValue, &rtb_Var_GreenIND_krbh, &localDW->sf_Green_IND_Control_Function_F);

  /* Chart: '<S141>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Flow(rtu_b_AmberINDCmd, localB->Var_BrightMaxValue, &rtb_Var_AmberIND_j0tc, &localDW->sf_Amber_IND_Control_Function_F);

  /* Chart: '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_Contro(App_Model_M, localB->Var_BrightMaxValue, rtu_INT_WPCIndCmdState, &localB->Var_GreenINDwithAnimation1, &localB->Var_GreenINDwithAnimation2,
    &localB->Var_GreenINDwithAnimation3, &localB->sf_Green_IND_with_Animation_Con, &localDW->sf_Green_IND_with_Animation_Con);

  /* Chart: '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_Contro(App_Model_M, localB->Var_BrightMaxValue, rtu_b_SyncAmber, rtu_INT_WPCIndCmdState, &localB->Var_AmberINDwithAnimation, &localB->sf_Amber_IND_with_Animation_Con,
    &localDW->sf_Amber_IND_with_Animation_Con);

  /* Chart: '<S141>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Function_Flo(rtu_INT_WPCIndCmdState, rtu_IND_WPCIndUSMState, rtb_Var_GreenIND_krbh, rtb_Var_AmberIND_j0tc, localB->Var_GreenINDwithAnimation2, localB->Var_GreenINDwithAnimation3,
    localB->Var_GreenINDwithAnimation1, localB->Var_AmberINDwithAnimation, &rtb_Output_AmberIND_OUT_enci, &rtb_Output_GreenIND_OUT_griu, &rtb_Output_GreenIND2_OUT_ljox, &rtb_Output_GreenIND3_OUT_myvy,
    &localDW->sf_IND_Output_Control_Function_);

  /* SignalConversion generated from: '<S44>/P_AmberIND_OUT' */
  *rty_P_AmberIND_OUT = rtb_Output_AmberIND_OUT_enci;

  /* SignalConversion generated from: '<S44>/P_GreenIND2_OUT' */
  *rty_P_GreenIND2_OUT = rtb_Output_GreenIND2_OUT_ljox;

  /* SignalConversion generated from: '<S44>/P_GreenIND3_OUT' */
  *rty_P_GreenIND3_OUT = rtb_Output_GreenIND3_OUT_myvy;

  /* SignalConversion generated from: '<S44>/P_GreenIND_OUT' */
  *rty_P_GreenIND_OUT = rtb_Output_GreenIND_OUT_griu;
}

/*
 * System initialize for atomic system:
 *    '<S45>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S235>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S486>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S667>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Cont_issq_Init(uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_cwb0_T *localDW)
{
  localDW->is_active_c415_IndyOutputContro = 0U;
  *rty_Var_BrightMaxValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S45>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S235>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S486>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S667>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_F_nqis(Bool rtu_Input_DetentOut, uint16 rtu_AutoBrightValue, uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_cwb0_T *localDW)
{
  /* Chart: '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c415_IndyOutputContro == 0U) {
    localDW->is_active_c415_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_BrightMaxValue = rtu_AutoBrightValue;

    /* 1 */
    if ((uint32)rtu_Input_DetentOut == On) {
      *rty_Var_BrightMaxValue = Par_AutoBrightLevel091;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_Input_DetentOut == On) {
    *rty_Var_BrightMaxValue = Par_AutoBrightLevel091;
  } else {
    *rty_Var_BrightMaxValue = rtu_AutoBrightValue;
  }

  /* End of Chart: '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
}

/* Function for Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
static void enter_internal_c420_IndyOutputC(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue)
{
  /* Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  /*  Transition run once at reset */
  *rty_AutoBrightValue = Par_AutoBrightLevel013;

  /* 1.  */
  switch (rtu_Input_AutoBrightLevel) {
   case Step2:
    *rty_AutoBrightValue = Par_AutoBrightLevel002;
    break;

   case Step3:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel003;
    break;

   case Step4:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel004;
    break;

   case Step5:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel005;
    break;

   case Step6:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel006;
    break;

   case Step7:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel007;
    break;

   case Step8:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel008;
    break;

   case Step9:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel009;
    break;

   case Step10:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel010;
    break;

   case Step11:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel011;
    break;

   case Step12:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel012;
    break;

   case Step13:
    /* 1.  */
    break;

   case Step14:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel014;
    break;

   case Step15:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel015;
    break;

   case Step16:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel016;
    break;

   case Step17:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel017;
    break;

   case Step18:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel018;
    break;

   case Step19:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel019;
    break;

   case Step20:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel020;
    break;

   case Step21:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel021;
    break;

   case Step22:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel022;
    break;

   case Step23:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel023;
    break;

   case Step24:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel024;
    break;

   case Step25:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel025;
    break;

   case Step26:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel026;
    break;

   case Step27:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel027;
    break;

   case Step28:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel028;
    break;

   case Step29:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel029;
    break;

   case Step30:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel030;
    break;

   case Step31:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel031;
    break;

   case Step32:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel032;
    break;

   case Step33:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel033;
    break;

   case Step34:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel034;
    break;

   case Step35:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel035;
    break;

   case Step36:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel036;
    break;

   case Step37:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel037;
    break;

   case Step38:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel038;
    break;

   case Step39:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel039;
    break;

   case Step40:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel040;
    break;

   case Step41:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel041;
    break;

   case Step42:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel042;
    break;

   case Step43:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel043;
    break;

   case Step44:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel044;
    break;

   case Step45:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel045;
    break;

   case Step46:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel046;
    break;

   case Step47:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel047;
    break;

   case Step48:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel048;
    break;

   case Step49:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel049;
    break;

   case Step50:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel050;
    break;

   case Step51:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel051;
    break;

   case Step52:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel052;
    break;

   case Step53:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel053;
    break;

   case Step54:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel054;
    break;

   case Step55:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel055;
    break;

   case Step56:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel056;
    break;

   case Step57:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel057;
    break;

   case Step58:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel058;
    break;

   case Step59:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel059;
    break;

   case Step60:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel060;
    break;

   case Step61:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel061;
    break;

   case Step62:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel062;
    break;

   case Step63:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel063;
    break;

   case Step64:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel064;
    break;

   case Step65:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel065;
    break;

   case Step66:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel066;
    break;

   case Step67:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel067;
    break;

   case Step68:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel068;
    break;

   case Step69:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel069;
    break;

   case Step70:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel070;
    break;

   case Step71:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel071;
    break;

   case Step72:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel072;
    break;

   case Step73:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel073;
    break;

   case Step74:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel074;
    break;

   case Step75:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel075;
    break;

   case Step76:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel076;
    break;

   case Step77:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel077;
    break;

   case Step78:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel078;
    break;

   case Step79:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel079;
    break;

   case Step80:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel080;
    break;

   case Step81:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel081;
    break;

   case Step82:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel082;
    break;

   case Step83:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel083;
    break;

   case Step84:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel084;
    break;

   case Step85:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel085;
    break;

   case Step86:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel086;
    break;

   case Step87:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel087;
    break;

   case Step88:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel088;
    break;

   case Step89:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel089;
    break;

   case Step90:
    /* 1.  */
    *rty_AutoBrightValue = Par_AutoBrightLevel090;
    break;

   default:
    /* 1.  */
    if ((uint32)rtu_Input_AutoBrightLevel >= Step91) {
      *rty_AutoBrightValue = Par_AutoBrightLevel091;
    } else {
      /* Old Value */
    }
    break;
  }

  /* End of Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
}

/*
 * System initialize for atomic system:
 *    '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S235>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S486>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S667>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 */
void WPC_IND_Output_With_Auto_B_Init(uint16 *rty_AutoBrightValue, DW_WPC_IND_Output_With_Auto_B_T *localDW)
{
  localDW->is_active_c420_IndyOutputContro = 0U;
  *rty_AutoBrightValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S235>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S486>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S667>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 */
void WPC_IND_Output_With_Auto_Bright(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue, DW_WPC_IND_Output_With_Auto_B_T *localDW)
{
  /* Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  if ((uint32)localDW->is_active_c420_IndyOutputContro == 0U) {
    localDW->is_active_c420_IndyOutputContro = 1U;
    enter_internal_c420_IndyOutputC(rtu_Input_AutoBrightLevel, rty_AutoBrightValue);
  } else {
    /*  Transition run every task on system operation */
    /* 1.  */
    switch (rtu_Input_AutoBrightLevel) {
     case Step2:
      *rty_AutoBrightValue = Par_AutoBrightLevel002;
      break;

     case Step3:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel003;
      break;

     case Step4:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel004;
      break;

     case Step5:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel005;
      break;

     case Step6:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel006;
      break;

     case Step7:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel007;
      break;

     case Step8:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel008;
      break;

     case Step9:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel009;
      break;

     case Step10:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel010;
      break;

     case Step11:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel011;
      break;

     case Step12:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel012;
      break;

     case Step13:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel013;
      break;

     case Step14:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel014;
      break;

     case Step15:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel015;
      break;

     case Step16:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel016;
      break;

     case Step17:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel017;
      break;

     case Step18:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel018;
      break;

     case Step19:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel019;
      break;

     case Step20:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel020;
      break;

     case Step21:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel021;
      break;

     case Step22:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel022;
      break;

     case Step23:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel023;
      break;

     case Step24:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel024;
      break;

     case Step25:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel025;
      break;

     case Step26:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel026;
      break;

     case Step27:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel027;
      break;

     case Step28:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel028;
      break;

     case Step29:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel029;
      break;

     case Step30:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel030;
      break;

     case Step31:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel031;
      break;

     case Step32:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel032;
      break;

     case Step33:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel033;
      break;

     case Step34:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel034;
      break;

     case Step35:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel035;
      break;

     case Step36:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel036;
      break;

     case Step37:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel037;
      break;

     case Step38:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel038;
      break;

     case Step39:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel039;
      break;

     case Step40:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel040;
      break;

     case Step41:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel041;
      break;

     case Step42:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel042;
      break;

     case Step43:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel043;
      break;

     case Step44:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel044;
      break;

     case Step45:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel045;
      break;

     case Step46:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel046;
      break;

     case Step47:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel047;
      break;

     case Step48:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel048;
      break;

     case Step49:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel049;
      break;

     case Step50:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel050;
      break;

     case Step51:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel051;
      break;

     case Step52:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel052;
      break;

     case Step53:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel053;
      break;

     case Step54:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel054;
      break;

     case Step55:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel055;
      break;

     case Step56:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel056;
      break;

     case Step57:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel057;
      break;

     case Step58:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel058;
      break;

     case Step59:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel059;
      break;

     case Step60:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel060;
      break;

     case Step61:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel061;
      break;

     case Step62:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel062;
      break;

     case Step63:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel063;
      break;

     case Step64:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel064;
      break;

     case Step65:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel065;
      break;

     case Step66:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel066;
      break;

     case Step67:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel067;
      break;

     case Step68:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel068;
      break;

     case Step69:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel069;
      break;

     case Step70:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel070;
      break;

     case Step71:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel071;
      break;

     case Step72:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel072;
      break;

     case Step73:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel073;
      break;

     case Step74:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel074;
      break;

     case Step75:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel075;
      break;

     case Step76:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel076;
      break;

     case Step77:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel077;
      break;

     case Step78:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel078;
      break;

     case Step79:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel079;
      break;

     case Step80:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel080;
      break;

     case Step81:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel081;
      break;

     case Step82:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel082;
      break;

     case Step83:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel083;
      break;

     case Step84:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel084;
      break;

     case Step85:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel085;
      break;

     case Step86:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel086;
      break;

     case Step87:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel087;
      break;

     case Step88:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel088;
      break;

     case Step89:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel089;
      break;

     case Step90:
      /* 1.  */
      *rty_AutoBrightValue = Par_AutoBrightLevel090;
      break;

     default:
      /* 1.  */
      if ((uint32)rtu_Input_AutoBrightLevel >= Step91) {
        *rty_AutoBrightValue = Par_AutoBrightLevel091;
      } else {
        /* Old Value */
      }
      break;
    }
  }

  /* End of Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
}

/*
 * System initialize for action system:
 *    '<S28>/AutoBrightIndyOutputControl_Type3'
 *    '<S645>/AutoBrightIndyOutputControl_Type3'
 */
void AutoBrightIndyOutputContro_Init(B_AutoBrightIndyOutputControl_T *localB, DW_AutoBrightIndyOutputContro_T *localDW)
{
  /* local block i/o variables */
  uint16 rtb_Var_GreenIND_eeal;
  uint16 rtb_Var_AmberIND_fx13;

  /* SystemInitialize for Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  WPC_IND_Output_With_Auto_B_Init(&localB->AutoBrightValue, &localDW->sf_WPC_IND_Output_With_Auto_Bri);

  /* SystemInitialize for Chart: '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Cont_issq_Init(&localB->Var_BrightMaxValue, &localDW->sf_Bright_Max_Value_Control_Fun);

  /* SystemInitialize for Chart: '<S45>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_fx13, &localDW->sf_Amber_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_C_Init(&localB->Var_AmberINDwithAnimation, &localDW->sf_Amber_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S45>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_eeal, &localDW->sf_Green_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_C_Init(&localB->Var_GreenINDwithAnimation1, &localB->Var_GreenINDwithAnimation2, &localB->Var_GreenINDwithAnimation3, &localDW->sf_Green_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S45>/IND_Output_Control_Function_Flow_Graph' */
  localDW->is_active_c419_IndyOutputContro = 0U;
}

/*
 * Enable for action system:
 *    '<S28>/AutoBrightIndyOutputControl_Type3'
 *    '<S645>/AutoBrightIndyOutputControl_Type3'
 */
void AutoBrightIndyOutputCont_Enable(DW_AutoBrightIndyOutputContro_T *localDW)
{
  /* Enable for Chart: '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_Enable(&localDW->sf_Amber_IND_with_Animation_Con);

  /* Enable for Chart: '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_Enable(&localDW->sf_Green_IND_with_Animation_Con);
}

/*
 * Output and update for action system:
 *    '<S28>/AutoBrightIndyOutputControl_Type3'
 *    '<S645>/AutoBrightIndyOutputControl_Type3'
 */
void AutoBrightIndyOutputControl_Typ(RT_MODEL_App_Model_T * const App_Model_M, WPCIndUSMState rtu_IND_WPCIndUSMState, C_AutoBrightLevel rtu_C_AutoBrightLevel, Bool rtu_C_DetentOut, Bool
  rtu_b_GreenINDCmd, Bool rtu_b_AmberINDCmd, WPCIndCmdState rtu_INT_WPCIndCmdState, Bool rtu_b_SyncAmber, uint16 *rty_P_GreenIND_OUT, uint16 *rty_P_GreenIND2_OUT, uint16 *rty_P_GreenIND3_OUT, uint16
  *rty_P_AmberIND_OUT, B_AutoBrightIndyOutputControl_T *localB, DW_AutoBrightIndyOutputContro_T *localDW)
{
  /* local block i/o variables */
  uint16 rtb_Var_GreenIND_eeal;
  uint16 rtb_Var_AmberIND_fx13;

  /* Chart: '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  WPC_IND_Output_With_Auto_Bright(rtu_C_AutoBrightLevel, &localB->AutoBrightValue, &localDW->sf_WPC_IND_Output_With_Auto_Bri);

  /* Chart: '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_nqis(rtu_C_DetentOut, localB->AutoBrightValue, &localB->Var_BrightMaxValue, &localDW->sf_Bright_Max_Value_Control_Fun);

  /* Chart: '<S45>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Flow(rtu_b_AmberINDCmd, localB->Var_BrightMaxValue, &rtb_Var_AmberIND_fx13, &localDW->sf_Amber_IND_Control_Function_F);

  /* Chart: '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_Contro(App_Model_M, localB->Var_BrightMaxValue, rtu_b_SyncAmber, rtu_INT_WPCIndCmdState, &localB->Var_AmberINDwithAnimation, &localB->sf_Amber_IND_with_Animation_Con,
    &localDW->sf_Amber_IND_with_Animation_Con);

  /* Chart: '<S45>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Flow(rtu_b_GreenINDCmd, localB->Var_BrightMaxValue, &rtb_Var_GreenIND_eeal, &localDW->sf_Green_IND_Control_Function_F);

  /* Chart: '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_Contro(App_Model_M, localB->Var_BrightMaxValue, rtu_INT_WPCIndCmdState, &localB->Var_GreenINDwithAnimation1, &localB->Var_GreenINDwithAnimation2,
    &localB->Var_GreenINDwithAnimation3, &localB->sf_Green_IND_with_Animation_Con, &localDW->sf_Green_IND_with_Animation_Con);

  /* Chart: '<S45>/IND_Output_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c419_IndyOutputContro == 0U) {
    localDW->is_active_c419_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    /* Ref_Off */
    /* 1 */
    if ((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) {
      /* Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut ||...Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut ||...Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||... */
      if (((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn)
          || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_INT_WPCIndCmdState ==
           WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)
           rtu_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut)) {
        /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
        /*  ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
        /* Green IND Light */
        *rty_P_GreenIND_OUT = localB->Var_GreenINDwithAnimation1;

        /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
        *rty_P_GreenIND2_OUT = localB->Var_GreenINDwithAnimation2;

        /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
        *rty_P_GreenIND3_OUT = localB->Var_GreenINDwithAnimation3;
        if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
            *rty_P_AmberIND_OUT = (uint16)0.0;
          } else {
            /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
            *rty_P_AmberIND_OUT = 0U;
          }
        } else {
          /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
          *rty_P_AmberIND_OUT = MAX_uint16_T;
        }
      } else if (((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_INT_WPCIndCmdState ==
                  WPCIndCmdState__ErrorFadeOut)) {
        /* Amber IND light */
        if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
            *rty_P_GreenIND_OUT = (uint16)0.0;

            /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
            *rty_P_GreenIND2_OUT = (uint16)0.0;

            /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
            *rty_P_GreenIND3_OUT = (uint16)0.0;
          } else {
            /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
            *rty_P_GreenIND_OUT = 0U;

            /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
            *rty_P_GreenIND2_OUT = 0U;

            /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
            *rty_P_GreenIND3_OUT = 0U;
          }
        } else {
          /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
          *rty_P_GreenIND_OUT = MAX_uint16_T;

          /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
          *rty_P_GreenIND2_OUT = MAX_uint16_T;

          /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
          *rty_P_GreenIND3_OUT = MAX_uint16_T;
        }

        /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
        *rty_P_AmberIND_OUT = localB->Var_AmberINDwithAnimation;
      } else if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
          *rty_P_GreenIND_OUT = (uint16)0.0;

          /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
          *rty_P_GreenIND2_OUT = (uint16)0.0;

          /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
          *rty_P_GreenIND3_OUT = (uint16)0.0;

          /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
          *rty_P_AmberIND_OUT = (uint16)0.0;
        } else {
          /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
          *rty_P_GreenIND_OUT = 0U;

          /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
          *rty_P_GreenIND2_OUT = 0U;

          /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
          *rty_P_GreenIND3_OUT = 0U;

          /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
          *rty_P_AmberIND_OUT = 0U;
        }
      } else {
        /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
        *rty_P_GreenIND_OUT = MAX_uint16_T;

        /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
        *rty_P_GreenIND2_OUT = MAX_uint16_T;

        /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
        *rty_P_GreenIND3_OUT = MAX_uint16_T;

        /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
        *rty_P_AmberIND_OUT = MAX_uint16_T;

        /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
           Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
      }
    } else {
      /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
      *rty_P_GreenIND_OUT = rtb_Var_GreenIND_eeal;

      /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
      *rty_P_GreenIND2_OUT = rtb_Var_GreenIND_eeal;

      /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
      *rty_P_GreenIND3_OUT = rtb_Var_GreenIND_eeal;

      /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
      *rty_P_AmberIND_OUT = rtb_Var_AmberIND_fx13;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) {
    /* Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut ||...Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut ||...Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||... */
    if (((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__Default) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) ||
        ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_INT_WPCIndCmdState ==
         WPCIndCmdState__2ndChrgOn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)
         rtu_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut)) {
      /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
      /*  ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      /* Green IND Light */
      *rty_P_GreenIND_OUT = localB->Var_GreenINDwithAnimation1;

      /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
      *rty_P_GreenIND2_OUT = localB->Var_GreenINDwithAnimation2;

      /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
      *rty_P_GreenIND3_OUT = localB->Var_GreenINDwithAnimation3;
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
          *rty_P_AmberIND_OUT = (uint16)0.0;
        } else {
          /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
          *rty_P_AmberIND_OUT = 0U;
        }
      } else {
        /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
        *rty_P_AmberIND_OUT = MAX_uint16_T;
      }
    } else if (((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || ((uint32)rtu_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_INT_WPCIndCmdState ==
                WPCIndCmdState__ErrorFadeOut)) {
      /* Amber IND light */
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
          *rty_P_GreenIND_OUT = (uint16)0.0;

          /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
          *rty_P_GreenIND2_OUT = (uint16)0.0;

          /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
          *rty_P_GreenIND3_OUT = (uint16)0.0;
        } else {
          /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
          *rty_P_GreenIND_OUT = 0U;

          /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
          *rty_P_GreenIND2_OUT = 0U;

          /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
          *rty_P_GreenIND3_OUT = 0U;
        }
      } else {
        /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
        *rty_P_GreenIND_OUT = MAX_uint16_T;

        /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
        *rty_P_GreenIND2_OUT = MAX_uint16_T;

        /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
        *rty_P_GreenIND3_OUT = MAX_uint16_T;
      }

      /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
      *rty_P_AmberIND_OUT = localB->Var_AmberINDwithAnimation;
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
        *rty_P_GreenIND_OUT = (uint16)0.0;

        /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
        *rty_P_GreenIND2_OUT = (uint16)0.0;

        /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
        *rty_P_GreenIND3_OUT = (uint16)0.0;

        /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
        *rty_P_AmberIND_OUT = (uint16)0.0;
      } else {
        /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
        *rty_P_GreenIND_OUT = 0U;

        /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
        *rty_P_GreenIND2_OUT = 0U;

        /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
        *rty_P_GreenIND3_OUT = 0U;

        /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
        *rty_P_AmberIND_OUT = 0U;
      }
    } else {
      /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
      *rty_P_GreenIND_OUT = MAX_uint16_T;

      /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
      *rty_P_GreenIND2_OUT = MAX_uint16_T;

      /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
      *rty_P_GreenIND3_OUT = MAX_uint16_T;

      /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
      *rty_P_AmberIND_OUT = MAX_uint16_T;

      /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
         Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
    }
  } else {
    /* SignalConversion generated from: '<S42>/P_GreenIND_OUT' */
    *rty_P_GreenIND_OUT = rtb_Var_GreenIND_eeal;

    /* SignalConversion generated from: '<S42>/P_GreenIND2_OUT' */
    *rty_P_GreenIND2_OUT = rtb_Var_GreenIND_eeal;

    /* SignalConversion generated from: '<S42>/P_GreenIND3_OUT' */
    *rty_P_GreenIND3_OUT = rtb_Var_GreenIND_eeal;

    /* SignalConversion generated from: '<S42>/P_AmberIND_OUT' */
    *rty_P_AmberIND_OUT = rtb_Var_AmberIND_fx13;
  }

  /* End of Chart: '<S45>/IND_Output_Control_Function_Flow_Graph' */
}

/* System initialize for atomic system: '<S22>/IndyOutputControl_Function' */
void IndyOutputControl_Function_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_jb4v, uint16 *rty_IndyOutput_Sig_ilyk, uint16 *rty_IndyOutput_Sig_dfmq)
{
  /* Start for SwitchCase: '<S28>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_dr1k = -1;

  /* SystemInitialize for IfAction SubSystem: '<S28>/RheoStatIndyOutputControl_Type1' */
  RheoStatIndyOutputControl__Init(&App_Model_B.RheoStatIndyOutputControl__egcm, &App_Model_DW.RheoStatIndyOutputControl__egcm);

  /* End of SystemInitialize for SubSystem: '<S28>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for IfAction SubSystem: '<S28>/RheoStatIndyOutputControl_Type2' */
  RheoStatIndyOutputCon_dc24_Init(&App_Model_B.RheoStatIndyOutputControl__pago, &App_Model_DW.RheoStatIndyOutputControl__pago);

  /* End of SystemInitialize for SubSystem: '<S28>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for IfAction SubSystem: '<S28>/AutoBrightIndyOutputControl_Type3' */
  AutoBrightIndyOutputContro_Init(&App_Model_B.AutoBrightIndyOutputContro_jouy, &App_Model_DW.AutoBrightIndyOutputContro_jouy);

  /* End of SystemInitialize for SubSystem: '<S28>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Merge generated from: '<S28>/Merge' */
  *rty_IndyOutput_Sig = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S28>/Merge' */
  *rty_IndyOutput_Sig_jb4v = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S28>/Merge' */
  *rty_IndyOutput_Sig_ilyk = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S28>/Merge' */
  *rty_IndyOutput_Sig_dfmq = ((uint16)0U);
}

/* Disable for atomic system: '<S22>/IndyOutputControl_Function' */
void IndyOutputControl_Funct_Disable(void)
{
  /* Disable for SwitchCase: '<S28>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_dr1k = -1;
}

/* Output and update for atomic system: '<S22>/IndyOutputControl_Function' */
void App__IndyOutputControl_Function(INDContType rtu_PostProcessIn, WPCIndUSMState rtu_PostProcessIn_jb4v, RheostatOption rtu_PostProcessIn_ilyk, Bool rtu_PostProcessIn_dfmq, Bool
  rtu_PostProcessIn_f2vh, C_RheoStatLevel rtu_PostProcessIn_k42s, Bool rtu_PostProcessIn_jn04, Bool rtu_PostProcessIn_ppii, WPCIndCmdState rtu_PostProcessIn_dzkt, Bool rtu_PostProcessIn_omf3,
  C_AutoBrightLevel rtu_PostProcessIn_boj3, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_jb4v, uint16 *rty_IndyOutput_Sig_ilyk, uint16 *rty_IndyOutput_Sig_dfmq)
{
  sint8 rtPrevAction;

  /* SwitchCase: '<S28>/Switch Case' */
  rtPrevAction = App_Model_DW.SwitchCase_ActiveSubsystem_dr1k;
  App_Model_DW.SwitchCase_ActiveSubsystem_dr1k = -1;
  switch (rtu_PostProcessIn) {
   case INDConType1:
    App_Model_DW.SwitchCase_ActiveSubsystem_dr1k = 0;
    break;

   case INDConType2:
    App_Model_DW.SwitchCase_ActiveSubsystem_dr1k = 1;
    break;

   case INDConType3:
    App_Model_DW.SwitchCase_ActiveSubsystem_dr1k = 2;
    break;

   default:
    /* no actions */
    break;
  }

  switch (App_Model_DW.SwitchCase_ActiveSubsystem_dr1k) {
   case 0:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_dr1k != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S28>/RheoStatIndyOutputControl_Type1' incorporates:
       *  ActionPort: '<S43>/ActionPort'
       */
      /* Enable for SwitchCase: '<S28>/Switch Case' */
      RheoStatIndyOutputContro_Enable(&App_Model_DW.RheoStatIndyOutputControl__egcm);

      /* End of Enable for SubSystem: '<S28>/RheoStatIndyOutputControl_Type1' */
    }

    /* Outputs for IfAction SubSystem: '<S28>/RheoStatIndyOutputControl_Type1' incorporates:
     *  ActionPort: '<S43>/ActionPort'
     */
    RheoStatIndyOutputControl_Type1(App_Model_M, rtu_PostProcessIn_jb4v, rtu_PostProcessIn_ilyk, rtu_PostProcessIn_dfmq, rtu_PostProcessIn_f2vh, rtu_PostProcessIn_k42s, rtu_PostProcessIn_jn04,
      rtu_PostProcessIn_ppii, rtu_PostProcessIn_dzkt, rtu_PostProcessIn_omf3, rty_IndyOutput_Sig, rty_IndyOutput_Sig_jb4v, rty_IndyOutput_Sig_ilyk, rty_IndyOutput_Sig_dfmq,
      &App_Model_B.RheoStatIndyOutputControl__egcm, &App_Model_DW.RheoStatIndyOutputControl__egcm);

    /* End of Outputs for SubSystem: '<S28>/RheoStatIndyOutputControl_Type1' */
    break;

   case 1:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_dr1k != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S28>/RheoStatIndyOutputControl_Type2' incorporates:
       *  ActionPort: '<S44>/ActionPort'
       */
      /* Enable for SwitchCase: '<S28>/Switch Case' */
      RheoStatIndyOutputC_jyjj_Enable(&App_Model_DW.RheoStatIndyOutputControl__pago);

      /* End of Enable for SubSystem: '<S28>/RheoStatIndyOutputControl_Type2' */
    }

    /* Outputs for IfAction SubSystem: '<S28>/RheoStatIndyOutputControl_Type2' incorporates:
     *  ActionPort: '<S44>/ActionPort'
     */
    RheoStatIndyOutputControl_Type2(App_Model_M, rtu_PostProcessIn_jb4v, rtu_PostProcessIn_ilyk, rtu_PostProcessIn_dfmq, rtu_PostProcessIn_k42s, rtu_PostProcessIn_jn04, rtu_PostProcessIn_ppii,
      rtu_PostProcessIn_dzkt, rtu_PostProcessIn_omf3, rty_IndyOutput_Sig, rty_IndyOutput_Sig_jb4v, rty_IndyOutput_Sig_ilyk, rty_IndyOutput_Sig_dfmq, &App_Model_B.RheoStatIndyOutputControl__pago,
      &App_Model_DW.RheoStatIndyOutputControl__pago);

    /* End of Outputs for SubSystem: '<S28>/RheoStatIndyOutputControl_Type2' */
    break;

   case 2:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_dr1k != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S28>/AutoBrightIndyOutputControl_Type3' incorporates:
       *  ActionPort: '<S42>/ActionPort'
       */
      /* Enable for SwitchCase: '<S28>/Switch Case' */
      AutoBrightIndyOutputCont_Enable(&App_Model_DW.AutoBrightIndyOutputContro_jouy);

      /* End of Enable for SubSystem: '<S28>/AutoBrightIndyOutputControl_Type3' */
    }

    /* Outputs for IfAction SubSystem: '<S28>/AutoBrightIndyOutputControl_Type3' incorporates:
     *  ActionPort: '<S42>/ActionPort'
     */
    AutoBrightIndyOutputControl_Typ(App_Model_M, rtu_PostProcessIn_jb4v, rtu_PostProcessIn_boj3, rtu_PostProcessIn_f2vh, rtu_PostProcessIn_jn04, rtu_PostProcessIn_ppii, rtu_PostProcessIn_dzkt,
      rtu_PostProcessIn_omf3, rty_IndyOutput_Sig, rty_IndyOutput_Sig_jb4v, rty_IndyOutput_Sig_ilyk, rty_IndyOutput_Sig_dfmq, &App_Model_B.AutoBrightIndyOutputContro_jouy,
      &App_Model_DW.AutoBrightIndyOutputContro_jouy);

    /* End of Outputs for SubSystem: '<S28>/AutoBrightIndyOutputControl_Type3' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S28>/Switch Case' */
}

/*
 * System initialize for function-call system:
 *    '<S285>/FadeOut'
 *    '<S333>/FadeOut'
 *    '<S237>/FadeOut'
 */
void App_Model_FadeOut_ppnc_Init(DW_FadeOut_App_Model_f2o5_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S295>/Delay Input1'
   *
   * Block description for '<S295>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S299>/Delay Input2'
   *
   * Block description for '<S299>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S285>/FadeOut'
 *    '<S333>/FadeOut'
 *    '<S237>/FadeOut'
 */
void App_Model_FadeOut_adke_Reset(DW_FadeOut_App_Model_f2o5_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S295>/Delay Input1'
   *
   * Block description for '<S295>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S299>/Delay Input2'
   *
   * Block description for '<S299>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S285>/FadeOut'
 *    '<S333>/FadeOut'
 *    '<S237>/FadeOut'
 */
void App_Model_FadeOut_bcra_Enable(DW_FadeOut_App_Model_f2o5_T *localDW)
{
  localDW->FadeOut_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S285>/FadeOut'
 *    '<S333>/FadeOut'
 *    '<S237>/FadeOut'
 */
void App_Model_FadeOut_dxzi(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_f2o5_T *localDW)
{
  float64 rtb_Add1;
  float64 rtb_deltariselimit;
  float64 rtb_sampletime;
  float64 rtu_pass_0;
  uint16 rtb_Switch9;
  if (localDW->FadeOut_RESET_ELAPS_T) {
    localDW->FadeOut_ELAPS_T[0] = 0U;
    localDW->FadeOut_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut_ELAPS_T[0] = FadeOut_ELAPS_T_tmp - localDW->FadeOut_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut_PREV_T[1];
    if (localDW->FadeOut_PREV_T[0] > FadeOut_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S299>/sample time' incorporates:
   *  Constant: '<S292>/Constant5'
   *  DataTypeConversion: '<S292>/Data Type Conversion7'
   *  Product: '<S292>/Divide'
   *
   * About '<S299>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_sampletime = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);

  /* Switch: '<S292>/Switch5' incorporates:
   *  Constant: '<S292>/Constant4'
   *  DataTypeConversion: '<S292>/Data Type Conversion7'
   *  Switch: '<S292>/Switch'
   */
  if (rtu_Trigger_FO > 0) {
    rtb_Switch9 = rtu_preValue;
    rtb_deltariselimit = rtb_sampletime;
  } else {
    rtb_Switch9 = rtu_Var_BrightMaxValue;
    rtb_deltariselimit = (float64)((uint16)0U);
  }

  /* End of Switch: '<S292>/Switch5' */

  /* Sum: '<S292>/Add1' */
  rtb_Add1 = (float64)rtb_Switch9 - rtb_deltariselimit;

  /* SampleTimeMath: '<S299>/sample time'
   *
   * About '<S299>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_sampletime = (((float64)localDW->FadeOut_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S299>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S292>/Data Type Conversion7'
   *  DataTypeConversion: '<S296>/Data Type Conversion2'
   */
  rtb_deltariselimit = (float64)rtu_Var_BrightMaxValue * rtb_sampletime;

  /* Switch: '<S292>/Switch8' incorporates:
   *  Constant: '<S292>/Constant2'
   *  DataTypeConversion: '<S292>/Data Type Conversion7'
   *  Logic: '<S292>/AND'
   *  RelationalOperator: '<S295>/FixPt Relational Operator'
   *  Switch: '<S292>/Switch7'
   *  UnitDelay: '<S295>/Delay Input1'
   *
   * Block description for '<S295>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger_FO != 0) && (rtu_pass != 0.0)) {
    rtb_Add1 = (float64)rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger_FO > 0) {
    /* Switch: '<S298>/Switch2' incorporates:
     *  Constant: '<S292>/Constant2'
     *  RelationalOperator: '<S298>/LowerRelop1'
     *  RelationalOperator: '<S298>/UpperRelop'
     *  Switch: '<S298>/Switch'
     */
    if (rtb_Add1 > (float64)rtu_preValue) {
      /* Switch: '<S292>/Switch7' */
      rtb_Add1 = (float64)rtu_preValue;
    } else if (rtb_Add1 < (float64)((uint16)0U)) {
      /* Switch: '<S298>/Switch' incorporates:
       *  Constant: '<S292>/Constant2'
       *  Switch: '<S292>/Switch7'
       */
      rtb_Add1 = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S298>/Switch2' */
  } else {
    rtb_Add1 = (float64)((uint16)0U);
  }

  /* End of Switch: '<S292>/Switch8' */

  /* Sum: '<S299>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S299>/Delay Input2'
   *
   * Block description for '<S299>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S299>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1 -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S296>/Switch4' incorporates:
   *  DataStoreRead: '<S296>/Data Store Read'
   *  DataTypeConversion: '<S292>/Data Type Conversion7'
   *  DataTypeConversion: '<S296>/Data Type Conversion2'
   *  DataTypeConversion: '<S296>/Data Type Conversion6'
   *  UnaryMinus: '<S296>/Unary Minus'
   *  UnaryMinus: '<S296>/Unary Minus2'
   */
  if (rtu_pass > 0.0) {
    rtu_pass_0 = -((float64)Par_AutoBrightLevel091);
  } else {
    rtu_pass_0 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S296>/Switch4' */

  /* Product: '<S299>/delta fall limit' */
  rtb_sampletime *= rtu_pass_0;

  /* Switch: '<S300>/Switch2' incorporates:
   *  RelationalOperator: '<S300>/LowerRelop1'
   *  RelationalOperator: '<S300>/UpperRelop'
   *  Switch: '<S300>/Switch'
   */
  if (rtb_Add1 > rtb_deltariselimit) {
    rtb_Add1 = rtb_deltariselimit;
  } else if (rtb_Add1 < rtb_sampletime) {
    /* Switch: '<S300>/Switch' */
    rtb_Add1 = rtb_sampletime;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S300>/Switch2' */

  /* Sum: '<S299>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S299>/Delay Input2'
   *
   * Block description for '<S299>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S299>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add1;

  /* Switch: '<S296>/Switch9' */
  if (rtu_pass > 0.0) {
    /* Switch: '<S296>/Switch9' incorporates:
     *  DataTypeConversion: '<S292>/Data Type Conversion7'
     */
    rtb_Switch9 = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S296>/Switch9' incorporates:
     *  DataTypeConversion: '<S296>/Data Type Conversion1'
     *  UnitDelay: '<S299>/Delay Input2'
     *
     * Block description for '<S299>/Delay Input2':
     *
     *  Store in Global RAM
     */
    rtb_Switch9 = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S296>/Switch9' */

  /* Switch: '<S292>/Switch1' incorporates:
   *  Constant: '<S292>/Constant7'
   *  Switch: '<S297>/Switch2'
   */
  if (rtu_Trigger_FO > 0) {
    /* Switch: '<S297>/Switch2' incorporates:
     *  Constant: '<S292>/Constant7'
     *  DataTypeConversion: '<S292>/Data Type Conversion7'
     *  RelationalOperator: '<S297>/LowerRelop1'
     *  RelationalOperator: '<S297>/UpperRelop'
     *  Switch: '<S297>/Switch'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      *rty_y_FadeOut = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch9 < ((uint16)0U)) {
      /* Switch: '<S297>/Switch' incorporates:
       *  Constant: '<S292>/Constant7'
       */
      *rty_y_FadeOut = ((uint16)0U);
    } else {
      *rty_y_FadeOut = rtb_Switch9;
    }
  } else {
    *rty_y_FadeOut = ((uint16)0U);
  }

  /* End of Switch: '<S292>/Switch1' */

  /* Update for UnitDelay: '<S295>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S292>/Data Type Conversion7'
   *
   * Block description for '<S295>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_M_Bright_Error_Control_l0v0(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const
  App_Model_M, B_Amber_IND_with_Animati_m1ud_T *localB, DW_Amber_IND_with_Animat_lfth_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localDW->pass = 0.0;
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S285>/FadeIn' */
    /* FcnTrigRst = FadeOut(Var_BrightMaxValue,Var_AmberINDwithAnimation,0,0); */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }
  } else {
    switch (rtu_Input_INT_WPC2IndCmdState) {
     case WPC2IndCmdState__ErrorOn:
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S285>/FadeIn' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      break;

     case WPC2IndCmdState__ErrorFadeIn:
      if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 1.0)) {
        localDW->pass = 1.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 0;
        localB->pass = 1.0;

        /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S285>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      } else {
        localDW->pass = 0.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 0.0;

        /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S285>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = localB->Switch2;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  if ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut) {
    if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 2.0)) {
      localDW->pass = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S285>/FadeIn' */
      localB->Var_BrightMaxValue_jldw = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 0;
      localB->pass_m4he = 1.0;

      /* Outputs for Function Call SubSystem: '<S285>/FadeOut' */
      App_Model_FadeOut_dxzi(App_Model_M, localB->Var_BrightMaxValue_jldw, localB->preValue, localB->Trigger_FO, localB->pass_m4he, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S285>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
    } else {
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S285>/FadeIn' */
      localB->Var_BrightMaxValue_jldw = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 1;
      localB->pass_m4he = 0.0;

      /* Outputs for Function Call SubSystem: '<S285>/FadeOut' */
      App_Model_FadeOut_dxzi(App_Model_M, localB->Var_BrightMaxValue_jldw, localB->preValue, localB->Trigger_FO, localB->pass_m4he, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S285>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = localB->Switch1;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S331>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S235>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animat_oufc_Init(uint16 *rty_Var_AmberINDwithAnimation, DW_Amber_IND_with_Animat_lfth_T *localDW)
{
  localDW->is_active_c345_IndyOutputContro = 0U;
  localDW->pass = 0.0;
  *rty_Var_AmberINDwithAnimation = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S285>/FadeIn' */
  App_Model_FadeIn_Init(&localDW->FadeIn);

  /* End of SystemInitialize for SubSystem: '<S285>/FadeIn' */

  /* SystemInitialize for Function Call SubSystem: '<S285>/FadeOut' */
  App_Model_FadeOut_ppnc_Init(&localDW->FadeOut);

  /* End of SystemInitialize for SubSystem: '<S285>/FadeOut' */
}

/*
 * Enable for atomic system:
 *    '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S331>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S235>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Anim_cncj_Enable(DW_Amber_IND_with_Animat_lfth_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S285>/FadeIn' */
  App_Model_FadeIn_Reset(&localDW->FadeIn);

  /* End of SystemReset for SubSystem: '<S285>/FadeIn' */

  /* SystemReset for Function Call SubSystem: '<S285>/FadeOut' */
  App_Model_FadeOut_adke_Reset(&localDW->FadeOut);

  /* End of SystemReset for SubSystem: '<S285>/FadeOut' */

  /* Enable for Function Call SubSystem: '<S285>/FadeOut' */
  App_Model_FadeOut_bcra_Enable(&localDW->FadeOut);

  /* End of Enable for SubSystem: '<S285>/FadeOut' */
}

/*
 * Output and update for atomic system:
 *    '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S331>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S235>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_C_m52k(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animati_m1ud_T *localB, DW_Amber_IND_with_Animat_lfth_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if ((uint32)localDW->is_active_c345_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c345_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S285>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S285>/FadeIn' */
    localB->Var_BrightMaxValue_jldw = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_AmberINDwithAnimation;
    localB->Trigger_FO = 0;
    localB->pass_m4he = 0.0;

    /* Outputs for Function Call SubSystem: '<S285>/FadeOut' */
    App_Model_FadeOut_dxzi(App_Model_M, localB->Var_BrightMaxValue_jldw, localB->preValue, localB->Trigger_FO, localB->pass_m4he, &localB->Switch1, &localDW->FadeOut);

    /* End of Outputs for SubSystem: '<S285>/FadeOut' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    if ((uint32)rtu_b_SyncAmber == Off) {
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Var_AmberINDwithAnimation = (uint16)0.0;
        } else {
          *rty_Var_AmberINDwithAnimation = 0U;
        }
      } else {
        *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
      }

      /* 1 */
    } else if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
                WPC2IndCmdState__ErrorFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default)) {
      App_M_Bright_Error_Control_l0v0(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);

      /* Not used in Amber LED */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
  } else if ((uint32)rtu_b_SyncAmber == Off) {
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    /* 1 */
  } else if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
              WPC2IndCmdState__ErrorFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default)) {
    App_M_Bright_Error_Control_l0v0(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);

    /* Not used in Amber LED */
  } else if (0.0 < 65536.0) {
    if (0.0 >= 0.0) {
      *rty_Var_AmberINDwithAnimation = (uint16)0.0;
    } else {
      *rty_Var_AmberINDwithAnimation = 0U;
    }
  } else {
    *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
  }

  /* End of Chart: '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for function-call system:
 *    '<S288>/FadeOut3'
 *    '<S336>/FadeOut3'
 *    '<S240>/FadeOut3'
 */
void App_Model_FadeOut3_nmq3_Init(DW_FadeOut3_App_Model_icri_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S325>/Delay Input1'
   *
   * Block description for '<S325>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S329>/Delay Input2'
   *
   * Block description for '<S329>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S288>/FadeOut3'
 *    '<S336>/FadeOut3'
 *    '<S240>/FadeOut3'
 */
void App_Model_FadeOut3_pmzl_Reset(DW_FadeOut3_App_Model_icri_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S325>/Delay Input1'
   *
   * Block description for '<S325>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = ((uint16)0U);

  /* InitializeConditions for UnitDelay: '<S329>/Delay Input2'
   *
   * Block description for '<S329>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S288>/FadeOut3'
 *    '<S336>/FadeOut3'
 *    '<S240>/FadeOut3'
 */
void App_Model_FadeOut3_l4ud_Enable(DW_FadeOut3_App_Model_icri_T *localDW)
{
  localDW->FadeOut3_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S288>/FadeOut3'
 *    '<S336>/FadeOut3'
 *    '<S240>/FadeOut3'
 */
void App_Model_FadeOut3_ig5d(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_icri_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1;
  float64 rtb_UkYk1_lg2q;
  float64 rtb_deltariselimit;
  uint16 rtb_Switch9;
  if (localDW->FadeOut3_RESET_ELAPS_T) {
    localDW->FadeOut3_ELAPS_T[0] = 0U;
    localDW->FadeOut3_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut3_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut3_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut3_ELAPS_T[0] = FadeOut3_ELAPS_T_tmp - localDW->FadeOut3_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut3_PREV_T[1];
    if (localDW->FadeOut3_PREV_T[0] > FadeOut3_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut3_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut3_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut3_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut3_RESET_ELAPS_T = false;

  /* Switch: '<S306>/Switch' incorporates:
   *  DataTypeConversion: '<S306>/Data Type Conversion7'
   *  Switch: '<S306>/Switch5'
   */
  if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S326>/Switch4' incorporates:
     *  Constant: '<S306>/Constant5'
     *  DataTypeConversion: '<S306>/Data Type Conversion7'
     *  Product: '<S306>/Divide'
     */
    rtb_Add1 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    rtb_Switch9 = rtu_preValue;
  } else {
    /* Switch: '<S326>/Switch4' incorporates:
     *  Constant: '<S306>/Constant4'
     */
    rtb_Add1 = (float64)((uint16)0U);
    rtb_Switch9 = rtu_Var_BrightMaxValue;
  }

  /* End of Switch: '<S306>/Switch' */

  /* Sum: '<S306>/Add1' */
  rtb_Add1 = (float64)rtb_Switch9 - rtb_Add1;

  /* Switch: '<S306>/Switch7' */
  if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S328>/Switch2' incorporates:
     *  Constant: '<S306>/Constant2'
     *  RelationalOperator: '<S328>/LowerRelop1'
     *  RelationalOperator: '<S328>/UpperRelop'
     *  Switch: '<S328>/Switch'
     */
    if (rtb_Add1 > (float64)rtu_preValue) {
      /* Switch: '<S326>/Switch4' */
      rtb_Add1 = (float64)rtu_preValue;
    } else if (rtb_Add1 < (float64)((uint16)0U)) {
      /* Switch: '<S328>/Switch' incorporates:
       *  Constant: '<S306>/Constant2'
       *  Switch: '<S326>/Switch4'
       */
      rtb_Add1 = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S328>/Switch2' */
  } else {
    /* Switch: '<S326>/Switch4' incorporates:
     *  Constant: '<S306>/Constant2'
     */
    rtb_Add1 = (float64)((uint16)0U);
  }

  /* End of Switch: '<S306>/Switch7' */
  /* SampleTimeMath: '<S329>/sample time'
   *
   * About '<S329>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut3_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut3_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S329>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S306>/Data Type Conversion7'
   *  DataTypeConversion: '<S326>/Data Type Conversion2'
   *  SampleTimeMath: '<S329>/sample time'
   *
   * About '<S329>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltariselimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S306>/Switch8' incorporates:
   *  DataTypeConversion: '<S306>/Data Type Conversion7'
   *  Logic: '<S306>/AND'
   *  RelationalOperator: '<S325>/FixPt Relational Operator'
   *  UnitDelay: '<S325>/Delay Input1'
   *
   * Block description for '<S325>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3_FO != 0) && (rtu_pass3 != 0.0)) {
    rtb_Add1 = (float64)rtu_Var_BrightMaxValue;
  }

  /* End of Switch: '<S306>/Switch8' */

  /* Sum: '<S329>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S329>/Delay Input2'
   *
   * Block description for '<S329>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S329>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_UkYk1_lg2q = rtb_Add1 - localDW->DelayInput2_DSTATE;

  /* Switch: '<S326>/Switch4' */
  if (rtu_pass3 > 0.0) {
    /* Switch: '<S326>/Switch4' incorporates:
     *  DataStoreRead: '<S326>/Data Store Read'
     *  DataTypeConversion: '<S326>/Data Type Conversion6'
     *  UnaryMinus: '<S326>/Unary Minus2'
     */
    rtb_Add1 = -((float64)Par_AutoBrightLevel091);
  } else {
    /* Switch: '<S326>/Switch4' incorporates:
     *  DataTypeConversion: '<S306>/Data Type Conversion7'
     *  DataTypeConversion: '<S326>/Data Type Conversion2'
     *  UnaryMinus: '<S326>/Unary Minus'
     */
    rtb_Add1 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S326>/Switch4' */

  /* Product: '<S329>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S329>/sample time'
   *
   * About '<S329>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Add1 *= elapseTime;

  /* Switch: '<S330>/Switch2' incorporates:
   *  RelationalOperator: '<S330>/LowerRelop1'
   *  RelationalOperator: '<S330>/UpperRelop'
   *  Switch: '<S330>/Switch'
   */
  if (rtb_UkYk1_lg2q > rtb_deltariselimit) {
    rtb_UkYk1_lg2q = rtb_deltariselimit;
  } else if (rtb_UkYk1_lg2q < rtb_Add1) {
    /* Switch: '<S330>/Switch' */
    rtb_UkYk1_lg2q = rtb_Add1;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S330>/Switch2' */

  /* Sum: '<S329>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S329>/Delay Input2'
   *
   * Block description for '<S329>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S329>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_UkYk1_lg2q;

  /* Switch: '<S326>/Switch9' */
  if (rtu_pass3 > 0.0) {
    /* Switch: '<S326>/Switch9' incorporates:
     *  DataTypeConversion: '<S306>/Data Type Conversion7'
     */
    rtb_Switch9 = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S326>/Switch9' incorporates:
     *  DataTypeConversion: '<S326>/Data Type Conversion1'
     *  UnitDelay: '<S329>/Delay Input2'
     *
     * Block description for '<S329>/Delay Input2':
     *
     *  Store in Global RAM
     */
    rtb_Switch9 = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S326>/Switch9' */

  /* Switch: '<S306>/Switch1' incorporates:
   *  Constant: '<S306>/Constant7'
   *  Switch: '<S327>/Switch2'
   */
  if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S327>/Switch2' incorporates:
     *  Constant: '<S306>/Constant7'
     *  DataTypeConversion: '<S306>/Data Type Conversion7'
     *  RelationalOperator: '<S327>/LowerRelop1'
     *  RelationalOperator: '<S327>/UpperRelop'
     *  Switch: '<S327>/Switch'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      *rty_y_FadeOut3 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch9 < ((uint16)0U)) {
      /* Switch: '<S327>/Switch' incorporates:
       *  Constant: '<S306>/Constant7'
       */
      *rty_y_FadeOut3 = ((uint16)0U);
    } else {
      *rty_y_FadeOut3 = rtb_Switch9;
    }
  } else {
    *rty_y_FadeOut3 = ((uint16)0U);
  }

  /* End of Switch: '<S306>/Switch1' */

  /* Update for UnitDelay: '<S325>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S306>/Data Type Conversion7'
   *
   * Block description for '<S325>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control1_nxxz(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    localDW->pass1 = 0.0;

    /* Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut  ||... */
  } else if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)
              rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
              WPC2IndCmdState__3rdChrgOn)) {
    /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    localDW->pass1 = 0.0;
  } else if ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) {
    if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 1.0)) {
      localDW->pass1 = 1.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 1.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_kpl0;
      localB->Var_BrightMaxValue_hgto = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_nzqq = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_hgto, localB->preValue, localB->Trigger1_FO, localB->pass1_nzqq, &localB->Switch1_hri5, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S288>/FadeOut1' */
    } else {
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_kpl0;
      localB->Var_BrightMaxValue_hgto = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_nzqq = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_hgto, localB->preValue, localB->Trigger1_FO, localB->pass1_nzqq, &localB->Switch1_hri5, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S288>/FadeOut1' */
      localDW->pass1 = 0.0;
    }
  } else {
    /* no actions */
  }

  if ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 2.0)) {
      localDW->pass1 = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
      localB->Var_BrightMaxValue_hgto = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_nzqq = 1.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_hgto, localB->preValue, localB->Trigger1_FO, localB->pass1_nzqq, &localB->Switch1_hri5, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S288>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_hgto = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 1;
      localB->pass1_nzqq = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_hgto, localB->preValue, localB->Trigger1_FO, localB->pass1_nzqq, &localB->Switch1_hri5, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S288>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch1_hri5;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
      localDW->pass1 = 0.0;
    }
  }
}

/* Function for Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control2_htmw(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    localDW->pass2 = 0.0;
  } else if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)
              rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn)) {
    localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    localDW->pass2 = 0.0;
  } else if ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) {
    if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 1.0)) {
      localDW->pass2 = 1.0;
      localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 1.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_lswb;
      localB->Var_BrightMaxValue_pkpq = rtu_Var_BrightMaxValue;
      localB->preValue_p1ys = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_l0mx = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_pkpq, localB->preValue_p1ys, localB->Trigger2_FO, localB->pass2_l0mx, &localB->Switch1_mhph, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S288>/FadeOut2' */
    } else {
      localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_lswb;
      localB->Var_BrightMaxValue_pkpq = rtu_Var_BrightMaxValue;
      localB->preValue_p1ys = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_l0mx = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_pkpq, localB->preValue_p1ys, localB->Trigger2_FO, localB->pass2_l0mx, &localB->Switch1_mhph, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S288>/FadeOut2' */
      localDW->pass2 = 0.0;
    }
  } else {
    /* no actions */
  }

  if ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 2.0)) {
      localDW->pass2 = 2.0;
      localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
      localB->Var_BrightMaxValue_pkpq = rtu_Var_BrightMaxValue;
      localB->preValue_p1ys = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_l0mx = 1.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_pkpq, localB->preValue_p1ys, localB->Trigger2_FO, localB->pass2_l0mx, &localB->Switch1_mhph, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S288>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_pkpq = rtu_Var_BrightMaxValue;
      localB->preValue_p1ys = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 1;
      localB->pass2_l0mx = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_pkpq, localB->preValue_p1ys, localB->Trigger2_FO, localB->pass2_l0mx, &localB->Switch1_mhph, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S288>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch1_mhph;
      localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
      localDW->pass2 = 0.0;
    }
  }
}

/* Function for Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control3_cofb(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW)
{
  if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }

    localDW->pass3 = 0.0;
  } else {
    switch (rtu_Input_INT_WPC2IndCmdState) {
     case WPC2IndCmdState__3rdChrgOn:
      localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
      localDW->pass3 = 0.0;
      break;

     case WPC2IndCmdState__3rdChrgFadeIn:
      if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 1.0)) {
        localDW->pass3 = 1.0;
        localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 1.0;

        /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_ppql = rtu_Var_BrightMaxValue;
        localB->preValue_hdix = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_ms0p = 0.0;

        /* Outputs for Function Call SubSystem: '<S288>/FadeOut3' */
        App_Model_FadeOut3_ig5d(App_Model_M, localB->Var_BrightMaxValue_ppql, localB->preValue_hdix, localB->Trigger3_FO, localB->pass3_ms0p, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S288>/FadeOut3' */
      } else {
        localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 0.0;

        /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_ppql = rtu_Var_BrightMaxValue;
        localB->preValue_hdix = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_ms0p = 0.0;

        /* Outputs for Function Call SubSystem: '<S288>/FadeOut3' */
        App_Model_FadeOut3_ig5d(App_Model_M, localB->Var_BrightMaxValue_ppql, localB->preValue_hdix, localB->Trigger3_FO, localB->pass3_ms0p, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S288>/FadeOut3' */
        localDW->pass3 = 0.0;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  if ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 2.0)) {
      localDW->pass3 = 2.0;
      localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
      localB->Var_BrightMaxValue_ppql = rtu_Var_BrightMaxValue;
      localB->preValue_hdix = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 0;
      localB->pass3_ms0p = 1.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut3' */
      App_Model_FadeOut3_ig5d(App_Model_M, localB->Var_BrightMaxValue_ppql, localB->preValue_hdix, localB->Trigger3_FO, localB->pass3_ms0p, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S288>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_ppql = rtu_Var_BrightMaxValue;
      localB->preValue_hdix = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 1;
      localB->pass3_ms0p = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeOut3' */
      App_Model_FadeOut3_ig5d(App_Model_M, localB->Var_BrightMaxValue_ppql, localB->preValue_hdix, localB->Trigger3_FO, localB->pass3_ms0p, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S288>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = localB->Switch1;
      localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
      localDW->pass3 = 0.0;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S331>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S235>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animat_mbvj_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, DW_Green_IND_with_Animat_eu5k_T *localDW)
{
  localDW->is_active_c349_IndyOutputContro = 0U;
  localDW->pass1 = 0.0;
  localDW->pass2 = 0.0;
  localDW->pass3 = 0.0;
  *rty_Var_GreenINDwithAnimation1 = 0U;
  *rty_Var_GreenINDwithAnimation2 = 0U;
  *rty_Var_GreenINDwithAnimation3 = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S288>/FadeIn1' */
  App_Model_FadeIn1_Init(&localDW->FadeIn1);

  /* End of SystemInitialize for SubSystem: '<S288>/FadeIn1' */

  /* SystemInitialize for Function Call SubSystem: '<S288>/FadeOut1' */
  App_Model_FadeOut1_Init(&localDW->FadeOut1);

  /* End of SystemInitialize for SubSystem: '<S288>/FadeOut1' */

  /* SystemInitialize for Function Call SubSystem: '<S288>/FadeIn2' */
  App_Model_FadeIn2_Init(&localDW->FadeIn2);

  /* End of SystemInitialize for SubSystem: '<S288>/FadeIn2' */

  /* SystemInitialize for Function Call SubSystem: '<S288>/FadeOut2' */
  App_Model_FadeOut2_Init(&localDW->FadeOut2);

  /* End of SystemInitialize for SubSystem: '<S288>/FadeOut2' */

  /* SystemInitialize for Function Call SubSystem: '<S288>/FadeIn3' */
  App_Model_FadeIn3_Init(&localDW->FadeIn3);

  /* End of SystemInitialize for SubSystem: '<S288>/FadeIn3' */

  /* SystemInitialize for Function Call SubSystem: '<S288>/FadeOut3' */
  App_Model_FadeOut3_nmq3_Init(&localDW->FadeOut3);

  /* End of SystemInitialize for SubSystem: '<S288>/FadeOut3' */
}

/*
 * Enable for atomic system:
 *    '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S331>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S235>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Anim_c1ni_Enable(DW_Green_IND_with_Animat_eu5k_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S288>/FadeIn1' */
  App_Model_FadeIn1_Reset(&localDW->FadeIn1);

  /* End of SystemReset for SubSystem: '<S288>/FadeIn1' */

  /* SystemReset for Function Call SubSystem: '<S288>/FadeOut1' */
  App_Model_FadeOut1_Reset(&localDW->FadeOut1);

  /* End of SystemReset for SubSystem: '<S288>/FadeOut1' */

  /* Enable for Function Call SubSystem: '<S288>/FadeOut1' */
  App_Model_FadeOut1_Enable(&localDW->FadeOut1);

  /* End of Enable for SubSystem: '<S288>/FadeOut1' */

  /* SystemReset for Function Call SubSystem: '<S288>/FadeIn2' */
  App_Model_FadeIn2_Reset(&localDW->FadeIn2);

  /* End of SystemReset for SubSystem: '<S288>/FadeIn2' */

  /* SystemReset for Function Call SubSystem: '<S288>/FadeOut2' */
  App_Model_FadeOut2_Reset(&localDW->FadeOut2);

  /* End of SystemReset for SubSystem: '<S288>/FadeOut2' */

  /* Enable for Function Call SubSystem: '<S288>/FadeOut2' */
  App_Model_FadeOut2_Enable(&localDW->FadeOut2);

  /* End of Enable for SubSystem: '<S288>/FadeOut2' */

  /* SystemReset for Function Call SubSystem: '<S288>/FadeIn3' */
  App_Model_FadeIn3_Reset(&localDW->FadeIn3);

  /* End of SystemReset for SubSystem: '<S288>/FadeIn3' */

  /* SystemReset for Function Call SubSystem: '<S288>/FadeOut3' */
  App_Model_FadeOut3_pmzl_Reset(&localDW->FadeOut3);

  /* End of SystemReset for SubSystem: '<S288>/FadeOut3' */

  /* Enable for Function Call SubSystem: '<S288>/FadeOut3' */
  App_Model_FadeOut3_l4ud_Enable(&localDW->FadeOut3);

  /* End of Enable for SubSystem: '<S288>/FadeOut3' */
}

/*
 * Output and update for atomic system:
 *    '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S331>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S235>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_C_eqpi(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if ((uint32)localDW->is_active_c349_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c349_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_kpl0, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S288>/FadeIn1' */
    localB->Var_BrightMaxValue_hgto = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_GreenINDwithAnimation1;
    localB->Trigger1_FO = 0;
    localB->pass1_nzqq = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeOut1' */
    App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_hgto, localB->preValue, localB->Trigger1_FO, localB->pass1_nzqq, &localB->Switch1_hri5, &localDW->FadeOut1);

    /* End of Outputs for SubSystem: '<S288>/FadeOut1' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /* 1. In the case of 1st LED */
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1_nxxz(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);

      /* 2. In the case of 1st LED, Abnormal */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_mmam = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_mmam, localB->Trigger2, localB->pass2, &localB->Switch2_lswb, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S288>/FadeIn2' */
    localB->Var_BrightMaxValue_pkpq = rtu_Var_BrightMaxValue;
    localB->preValue_p1ys = *rty_Var_GreenINDwithAnimation2;
    localB->Trigger2_FO = 0;
    localB->pass2_l0mx = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeOut2' */
    App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_pkpq, localB->preValue_p1ys, localB->Trigger2_FO, localB->pass2_l0mx, &localB->Switch1_mhph, &localDW->FadeOut2);

    /* End of Outputs for SubSystem: '<S288>/FadeOut2' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /* 1. In the case of 2nd LED */
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || ((uint32)
         rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2_htmw(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);

      /* 2. In the case of 2nd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_erul = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_erul, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S288>/FadeIn3' */
    localB->Var_BrightMaxValue_ppql = rtu_Var_BrightMaxValue;
    localB->preValue_hdix = *rty_Var_GreenINDwithAnimation3;
    localB->Trigger3_FO = 0;
    localB->pass3_ms0p = 0.0;

    /* Outputs for Function Call SubSystem: '<S288>/FadeOut3' */
    App_Model_FadeOut3_ig5d(App_Model_M, localB->Var_BrightMaxValue_ppql, localB->preValue_hdix, localB->Trigger3_FO, localB->pass3_ms0p, &localB->Switch1, &localDW->FadeOut3);

    /* End of Outputs for SubSystem: '<S288>/FadeOut3' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }

    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3_cofb(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);

      /* 2. In the case of 3rd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1. In the case of 1st LED */
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1_nxxz(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);

      /* 2. In the case of 1st LED, Abnormal */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 2nd LED */
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || ((uint32)
         rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2_htmw(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);

      /* 2. In the case of 2nd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3_cofb(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);

      /* 2. In the case of 3rd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }
  }

  /* End of Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for atomic system:
 *    '<S283>/IND_Output_Control_Function_Flow_Graph'
 *    '<S331>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Fu_bpei_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT,
  DW_IND_Output_Control_Fu_pb2o_T *localDW)
{
  localDW->is_active_c351_IndyOutputContro = 0U;
  *rty_Output_AmberIND_OUT = 0U;
  *rty_Output_GreenIND_OUT = 0U;
  *rty_Output_GreenIND2_OUT = 0U;
  *rty_Output_GreenIND3_OUT = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S283>/IND_Output_Control_Function_Flow_Graph'
 *    '<S331>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Functio_kj3y(WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, WPCIndUSMState rtu_Input_C_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Fu_pb2o_T *localDW)
{
  /* Chart: '<S283>/IND_Output_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c351_IndyOutputContro == 0U) {
    localDW->is_active_c351_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Output_GreenIND_OUT = (uint16)0.0;
        *rty_Output_GreenIND2_OUT = (uint16)0.0;
        *rty_Output_GreenIND3_OUT = (uint16)0.0;
        *rty_Output_AmberIND_OUT = (uint16)0.0;
      } else {
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = 0U;
      }
    } else {
      *rty_Output_GreenIND_OUT = MAX_uint16_T;
      *rty_Output_GreenIND2_OUT = MAX_uint16_T;
      *rty_Output_GreenIND3_OUT = MAX_uint16_T;
      *rty_Output_AmberIND_OUT = MAX_uint16_T;
    }

    /* Ref_Off */
    /* 1 */
    if ((uint32)rtu_Input_C_WPCIndUSMState == WPCIndUSMState__Type2) {
      if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
           WPC2IndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut) ||
          ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
           WPC2IndCmdState__2ndChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) ||
          ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || ((uint32)
           rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2)) {
        /* 231010 */
        /* Green IND Light */
        *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
        *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
        *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
        if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            *rty_Output_AmberIND_OUT = (uint16)0.0;
          } else {
            *rty_Output_AmberIND_OUT = 0U;
          }
        } else {
          *rty_Output_AmberIND_OUT = MAX_uint16_T;
        }
      } else if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || ((uint32)
                  rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut)) {
        /* Amber IND light */
        if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            *rty_Output_GreenIND_OUT = (uint16)0.0;
            *rty_Output_GreenIND2_OUT = (uint16)0.0;
            *rty_Output_GreenIND3_OUT = (uint16)0.0;
          } else {
            *rty_Output_GreenIND_OUT = 0U;
            *rty_Output_GreenIND2_OUT = 0U;
            *rty_Output_GreenIND3_OUT = 0U;
          }
        } else {
          *rty_Output_GreenIND_OUT = MAX_uint16_T;
          *rty_Output_GreenIND2_OUT = MAX_uint16_T;
          *rty_Output_GreenIND3_OUT = MAX_uint16_T;
        }

        *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
      } else if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Output_GreenIND_OUT = (uint16)0.0;
          *rty_Output_GreenIND2_OUT = (uint16)0.0;
          *rty_Output_GreenIND3_OUT = (uint16)0.0;
          *rty_Output_AmberIND_OUT = (uint16)0.0;
        } else {
          *rty_Output_GreenIND_OUT = 0U;
          *rty_Output_GreenIND2_OUT = 0U;
          *rty_Output_GreenIND3_OUT = 0U;
          *rty_Output_AmberIND_OUT = 0U;
        }
      } else {
        *rty_Output_GreenIND_OUT = MAX_uint16_T;
        *rty_Output_GreenIND2_OUT = MAX_uint16_T;
        *rty_Output_GreenIND3_OUT = MAX_uint16_T;
        *rty_Output_AmberIND_OUT = MAX_uint16_T;

        /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
           Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
      }
    } else {
      *rty_Output_GreenIND_OUT = rtu_Var_GreenIND;
      *rty_Output_GreenIND2_OUT = rtu_Var_GreenIND;
      *rty_Output_GreenIND3_OUT = rtu_Var_GreenIND;
      *rty_Output_AmberIND_OUT = rtu_Var_AmberIND;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if ((uint32)rtu_Input_C_WPCIndUSMState == WPCIndUSMState__Type2) {
    if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut) ||
        ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__2ndChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) ||
        ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__ChrgFadeOut3_2)) {
      /* 231010 */
      /* Green IND Light */
      *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
      *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
      *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Output_AmberIND_OUT = (uint16)0.0;
        } else {
          *rty_Output_AmberIND_OUT = 0U;
        }
      } else {
        *rty_Output_AmberIND_OUT = MAX_uint16_T;
      }
    } else if (((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_WPC2IndCmdState ==
                WPC2IndCmdState__ErrorFadeOut)) {
      /* Amber IND light */
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Output_GreenIND_OUT = (uint16)0.0;
          *rty_Output_GreenIND2_OUT = (uint16)0.0;
          *rty_Output_GreenIND3_OUT = (uint16)0.0;
        } else {
          *rty_Output_GreenIND_OUT = 0U;
          *rty_Output_GreenIND2_OUT = 0U;
          *rty_Output_GreenIND3_OUT = 0U;
        }
      } else {
        *rty_Output_GreenIND_OUT = MAX_uint16_T;
        *rty_Output_GreenIND2_OUT = MAX_uint16_T;
        *rty_Output_GreenIND3_OUT = MAX_uint16_T;
      }

      *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Output_GreenIND_OUT = (uint16)0.0;
        *rty_Output_GreenIND2_OUT = (uint16)0.0;
        *rty_Output_GreenIND3_OUT = (uint16)0.0;
        *rty_Output_AmberIND_OUT = (uint16)0.0;
      } else {
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = 0U;
      }
    } else {
      *rty_Output_GreenIND_OUT = MAX_uint16_T;
      *rty_Output_GreenIND2_OUT = MAX_uint16_T;
      *rty_Output_GreenIND3_OUT = MAX_uint16_T;
      *rty_Output_AmberIND_OUT = MAX_uint16_T;

      /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
         Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
    }
  } else {
    *rty_Output_GreenIND_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND2_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND3_OUT = rtu_Var_GreenIND;
    *rty_Output_AmberIND_OUT = rtu_Var_AmberIND;
  }

  /* End of Chart: '<S283>/IND_Output_Control_Function_Flow_Graph' */
}

/* System initialize for atomic system: '<S217>/IndyOutputControl_Function' */
void IndyOutputControl_Fun_flyb_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_gx5p, uint16 *rty_IndyOutput_Sig_lzzp, uint16 *rty_IndyOutput_Sig_mowe)
{
  /* local block i/o variables */
  uint16 rtb_Var_GreenIND;
  uint16 rtb_Var_AmberIND;
  uint16 rtb_Output_AmberIND_OUT_kmuj;
  uint16 rtb_Output_GreenIND_OUT_ajrb;
  uint16 rtb_Output_GreenIND2_OUT_feyz;
  uint16 rtb_Output_GreenIND3_OUT_o4yp;
  uint16 rtb_Var_GreenIND_oxhd;
  uint16 rtb_Var_AmberIND_cfut;
  uint16 rtb_Output_AmberIND_OUT_nihg;
  uint16 rtb_Output_GreenIND_OUT_i05n;
  uint16 rtb_Output_GreenIND2_OUT_kbfp;
  uint16 rtb_Output_GreenIND3_OUT_e3of;
  uint16 rtb_Var_GreenIND_a2me;
  uint16 rtb_Var_AmberIND_om2i;

  /* Start for SwitchCase: '<S223>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_esff = -1;

  /* SystemInitialize for IfAction SubSystem: '<S223>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for Chart: '<S283>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue_avqh, &App_Model_DW.sf_WPC_IND_Output_Control_Funct);

  /* SystemInitialize for Chart: '<S283>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_Init(&App_Model_B.Var_BrightMaxValue_cvna, &App_Model_DW.sf_Bright_Max_Value_Control_Fun);

  /* SystemInitialize for Chart: '<S283>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_a2me, &App_Model_DW.sf_Green_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S283>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_om2i, &App_Model_DW.sf_Amber_IND_Control_Function_F);

  /* SystemInitialize for Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animat_mbvj_Init(&App_Model_B.Var_GreenINDwithAnimation1_ipos, &App_Model_B.Var_GreenINDwithAnimation2_jpud, &App_Model_B.Var_GreenINDwithAnimation3_hk0a,
    &App_Model_DW.sf_Green_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animat_oufc_Init(&App_Model_B.Var_AmberINDwithAnimation_mnvc, &App_Model_DW.sf_Amber_IND_with_Animation_Con);

  /* SystemInitialize for Chart: '<S283>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Fu_bpei_Init(&rtb_Output_AmberIND_OUT_nihg, &rtb_Output_GreenIND_OUT_i05n, &rtb_Output_GreenIND2_OUT_kbfp, &rtb_Output_GreenIND3_OUT_e3of,
    &App_Model_DW.sf_IND_Output_Control_Function_);

  /* End of SystemInitialize for SubSystem: '<S223>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for IfAction SubSystem: '<S223>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for Chart: '<S331>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue_ops4, &App_Model_DW.sf_WPC_IND_Output_Control__euq0);

  /* SystemInitialize for Chart: '<S331>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Cont_abam_Init(&App_Model_B.Var_BrightMaxValue_cf3c, &App_Model_DW.sf_Bright_Max_Value_Contro_kmim);

  /* SystemInitialize for Chart: '<S331>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_oxhd, &App_Model_DW.sf_Green_IND_Control_Funct_ey0v);

  /* SystemInitialize for Chart: '<S331>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_cfut, &App_Model_DW.sf_Amber_IND_Control_Funct_la4n);

  /* SystemInitialize for Chart: '<S331>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animat_mbvj_Init(&App_Model_B.Var_GreenINDwithAnimation1_had1, &App_Model_B.Var_GreenINDwithAnimation2_ibwd, &App_Model_B.Var_GreenINDwithAnimation3_azas,
    &App_Model_DW.sf_Green_IND_with_Animatio_pcgu);

  /* SystemInitialize for Chart: '<S331>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animat_oufc_Init(&App_Model_B.Var_AmberINDwithAnimation_bkry, &App_Model_DW.sf_Amber_IND_with_Animatio_fwm4);

  /* SystemInitialize for Chart: '<S331>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Fu_bpei_Init(&rtb_Output_AmberIND_OUT_kmuj, &rtb_Output_GreenIND_OUT_ajrb, &rtb_Output_GreenIND2_OUT_feyz, &rtb_Output_GreenIND3_OUT_o4yp,
    &App_Model_DW.sf_IND_Output_Control_Func_jlqz);

  /* End of SystemInitialize for SubSystem: '<S223>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for IfAction SubSystem: '<S223>/AutoBrightIndyOutputControl_Type3' */
  /* SystemInitialize for Chart: '<S235>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  WPC_IND_Output_With_Auto_B_Init(&App_Model_B.AutoBrightValue_g21i, &App_Model_DW.sf_WPC_IND_Output_With_Auto_Bri);

  /* SystemInitialize for Chart: '<S235>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Cont_issq_Init(&App_Model_B.Var_BrightMaxValue_gten, &App_Model_DW.sf_Bright_Max_Value_Contro_af1k);

  /* SystemInitialize for Chart: '<S235>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND, &App_Model_DW.sf_Amber_IND_Control_Funct_ixgd);

  /* SystemInitialize for Chart: '<S235>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animat_oufc_Init(&App_Model_B.Var_AmberINDwithAnimation_i4hy, &App_Model_DW.sf_Amber_IND_with_Animatio_awb4);

  /* SystemInitialize for Chart: '<S235>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND, &App_Model_DW.sf_Green_IND_Control_Funct_bsnb);

  /* SystemInitialize for Chart: '<S235>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animat_mbvj_Init(&App_Model_B.Var_GreenINDwithAnimation1_nlnx, &App_Model_B.Var_GreenINDwithAnimation2_pkuj, &App_Model_B.Var_GreenINDwithAnimation3_i05v,
    &App_Model_DW.sf_Green_IND_with_Animatio_dcdw);

  /* SystemInitialize for Chart: '<S235>/IND_Output_Control_Function_Flow_Graph' */
  App_Model_DW.is_active_c426_IndyOutputContro = 0U;

  /* End of SystemInitialize for SubSystem: '<S223>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Merge generated from: '<S223>/Merge' */
  *rty_IndyOutput_Sig = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S223>/Merge' */
  *rty_IndyOutput_Sig_gx5p = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S223>/Merge' */
  *rty_IndyOutput_Sig_lzzp = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S223>/Merge' */
  *rty_IndyOutput_Sig_mowe = ((uint16)0U);
}

/* Disable for atomic system: '<S217>/IndyOutputControl_Function' */
void IndyOutputControl__gkc5_Disable(void)
{
  /* Disable for SwitchCase: '<S223>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_esff = -1;
}

/* Output and update for atomic system: '<S217>/IndyOutputControl_Function' */
void IndyOutputControl_Function_nrso(INDContType rtu_PostProcessIn, WPC2IndCmdState rtu_PostProcessIn_gx5p, WPCIndUSMState rtu_PostProcessIn_lzzp, Bool rtu_PostProcessIn_mowe, Bool
  rtu_PostProcessIn_f2vy, Bool rtu_PostProcessIn_kr5d, RheostatOption rtu_PostProcessIn_bizt, Bool rtu_PostProcessIn_mkqp, Bool rtu_PostProcessIn_fg01, C_RheoStatLevel rtu_PostProcessIn_jxih,
  C_AutoBrightLevel rtu_PostProcessIn_cr0j, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_gx5p, uint16 *rty_IndyOutput_Sig_lzzp, uint16 *rty_IndyOutput_Sig_mowe)
{
  /* local block i/o variables */
  uint16 rtb_Var_GreenIND;
  uint16 rtb_Var_AmberIND;
  uint16 rtb_Output_AmberIND_OUT_kmuj;
  uint16 rtb_Output_GreenIND_OUT_ajrb;
  uint16 rtb_Output_GreenIND2_OUT_feyz;
  uint16 rtb_Output_GreenIND3_OUT_o4yp;
  uint16 rtb_Var_GreenIND_oxhd;
  uint16 rtb_Var_AmberIND_cfut;
  uint16 rtb_Output_AmberIND_OUT_nihg;
  uint16 rtb_Output_GreenIND_OUT_i05n;
  uint16 rtb_Output_GreenIND2_OUT_kbfp;
  uint16 rtb_Output_GreenIND3_OUT_e3of;
  uint16 rtb_Var_GreenIND_a2me;
  uint16 rtb_Var_AmberIND_om2i;
  sint8 rtPrevAction;

  /* SwitchCase: '<S223>/Switch Case' */
  rtPrevAction = App_Model_DW.SwitchCase_ActiveSubsystem_esff;
  App_Model_DW.SwitchCase_ActiveSubsystem_esff = -1;
  switch (rtu_PostProcessIn) {
   case INDConType1:
    App_Model_DW.SwitchCase_ActiveSubsystem_esff = 0;
    break;

   case INDConType2:
    App_Model_DW.SwitchCase_ActiveSubsystem_esff = 1;
    break;

   case INDConType3:
    App_Model_DW.SwitchCase_ActiveSubsystem_esff = 2;
    break;

   default:
    /* no actions */
    break;
  }

  switch (App_Model_DW.SwitchCase_ActiveSubsystem_esff) {
   case 0:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_esff != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S223>/RheoStatIndyOutputControl_Type1' incorporates:
       *  ActionPort: '<S233>/ActionPort'
       */
      /* Enable for SwitchCase: '<S223>/Switch Case' incorporates:
       *  Chart: '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Green_IND_with_Anim_c1ni_Enable(&App_Model_DW.sf_Green_IND_with_Animation_Con);
      Amber_IND_with_Anim_cncj_Enable(&App_Model_DW.sf_Amber_IND_with_Animation_Con);

      /* End of Enable for SubSystem: '<S223>/RheoStatIndyOutputControl_Type1' */
    }

    /* Outputs for IfAction SubSystem: '<S223>/RheoStatIndyOutputControl_Type1' incorporates:
     *  ActionPort: '<S233>/ActionPort'
     */
    /* Chart: '<S283>/WPC_IND_Output_Control_Function' */
    WPC_IND_Output_Control_Function(rtu_PostProcessIn_jxih, &App_Model_B.RheoLevelValue_avqh, &App_Model_DW.sf_WPC_IND_Output_Control_Funct);

    /* Chart: '<S283>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Functi(rtu_PostProcessIn_kr5d, rtu_PostProcessIn_bizt, rtu_PostProcessIn_mkqp, App_Model_B.RheoLevelValue_avqh, &App_Model_B.Var_BrightMaxValue_cvna,
      &App_Model_DW.sf_Bright_Max_Value_Control_Fun);

    /* Chart: '<S283>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_fg01, App_Model_B.Var_BrightMaxValue_cvna, &rtb_Var_GreenIND_a2me, &App_Model_DW.sf_Green_IND_Control_Function_F);

    /* Chart: '<S283>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_mowe, App_Model_B.Var_BrightMaxValue_cvna, &rtb_Var_AmberIND_om2i, &App_Model_DW.sf_Amber_IND_Control_Function_F);

    /* Chart: '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_C_eqpi(App_Model_M, App_Model_B.Var_BrightMaxValue_cvna, rtu_PostProcessIn_gx5p, &App_Model_B.Var_GreenINDwithAnimation1_ipos, &App_Model_B.Var_GreenINDwithAnimation2_jpud,
      &App_Model_B.Var_GreenINDwithAnimation3_hk0a, &App_Model_B.sf_Green_IND_with_Animation_Con, &App_Model_DW.sf_Green_IND_with_Animation_Con);

    /* Chart: '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_C_m52k(App_Model_M, App_Model_B.Var_BrightMaxValue_cvna, rtu_PostProcessIn_f2vy, rtu_PostProcessIn_gx5p, &App_Model_B.Var_AmberINDwithAnimation_mnvc,
      &App_Model_B.sf_Amber_IND_with_Animation_Con, &App_Model_DW.sf_Amber_IND_with_Animation_Con);

    /* Chart: '<S283>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Functio_kj3y(rtu_PostProcessIn_gx5p, rtu_PostProcessIn_lzzp, rtb_Var_GreenIND_a2me, rtb_Var_AmberIND_om2i, App_Model_B.Var_GreenINDwithAnimation2_jpud,
      App_Model_B.Var_GreenINDwithAnimation3_hk0a, App_Model_B.Var_GreenINDwithAnimation1_ipos, App_Model_B.Var_AmberINDwithAnimation_mnvc, &rtb_Output_AmberIND_OUT_nihg, &rtb_Output_GreenIND_OUT_i05n,
      &rtb_Output_GreenIND2_OUT_kbfp, &rtb_Output_GreenIND3_OUT_e3of, &App_Model_DW.sf_IND_Output_Control_Function_);

    /* SignalConversion generated from: '<S233>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_mowe = rtb_Output_AmberIND_OUT_nihg;

    /* SignalConversion generated from: '<S233>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_gx5p = rtb_Output_GreenIND2_OUT_kbfp;

    /* SignalConversion generated from: '<S233>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_lzzp = rtb_Output_GreenIND3_OUT_e3of;

    /* SignalConversion generated from: '<S233>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_i05n;

    /* End of Outputs for SubSystem: '<S223>/RheoStatIndyOutputControl_Type1' */
    break;

   case 1:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_esff != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S223>/RheoStatIndyOutputControl_Type2' incorporates:
       *  ActionPort: '<S234>/ActionPort'
       */
      /* Enable for SwitchCase: '<S223>/Switch Case' incorporates:
       *  Chart: '<S331>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S331>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Green_IND_with_Anim_c1ni_Enable(&App_Model_DW.sf_Green_IND_with_Animatio_pcgu);
      Amber_IND_with_Anim_cncj_Enable(&App_Model_DW.sf_Amber_IND_with_Animatio_fwm4);

      /* End of Enable for SubSystem: '<S223>/RheoStatIndyOutputControl_Type2' */
    }

    /* Outputs for IfAction SubSystem: '<S223>/RheoStatIndyOutputControl_Type2' incorporates:
     *  ActionPort: '<S234>/ActionPort'
     */
    /* Chart: '<S331>/WPC_IND_Output_Control_Function' */
    WPC_IND_Output_Control_Function(rtu_PostProcessIn_jxih, &App_Model_B.RheoLevelValue_ops4, &App_Model_DW.sf_WPC_IND_Output_Control__euq0);

    /* Chart: '<S331>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_F_bk5u(rtu_PostProcessIn_bizt, rtu_PostProcessIn_mkqp, App_Model_B.RheoLevelValue_ops4, &App_Model_B.Var_BrightMaxValue_cf3c, &App_Model_DW.sf_Bright_Max_Value_Contro_kmim);

    /* Chart: '<S331>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_fg01, App_Model_B.Var_BrightMaxValue_cf3c, &rtb_Var_GreenIND_oxhd, &App_Model_DW.sf_Green_IND_Control_Funct_ey0v);

    /* Chart: '<S331>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_mowe, App_Model_B.Var_BrightMaxValue_cf3c, &rtb_Var_AmberIND_cfut, &App_Model_DW.sf_Amber_IND_Control_Funct_la4n);

    /* Chart: '<S331>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_C_eqpi(App_Model_M, App_Model_B.Var_BrightMaxValue_cf3c, rtu_PostProcessIn_gx5p, &App_Model_B.Var_GreenINDwithAnimation1_had1, &App_Model_B.Var_GreenINDwithAnimation2_ibwd,
      &App_Model_B.Var_GreenINDwithAnimation3_azas, &App_Model_B.sf_Green_IND_with_Animatio_pcgu, &App_Model_DW.sf_Green_IND_with_Animatio_pcgu);

    /* Chart: '<S331>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_C_m52k(App_Model_M, App_Model_B.Var_BrightMaxValue_cf3c, rtu_PostProcessIn_f2vy, rtu_PostProcessIn_gx5p, &App_Model_B.Var_AmberINDwithAnimation_bkry,
      &App_Model_B.sf_Amber_IND_with_Animatio_fwm4, &App_Model_DW.sf_Amber_IND_with_Animatio_fwm4);

    /* Chart: '<S331>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Functio_kj3y(rtu_PostProcessIn_gx5p, rtu_PostProcessIn_lzzp, rtb_Var_GreenIND_oxhd, rtb_Var_AmberIND_cfut, App_Model_B.Var_GreenINDwithAnimation2_ibwd,
      App_Model_B.Var_GreenINDwithAnimation3_azas, App_Model_B.Var_GreenINDwithAnimation1_had1, App_Model_B.Var_AmberINDwithAnimation_bkry, &rtb_Output_AmberIND_OUT_kmuj, &rtb_Output_GreenIND_OUT_ajrb,
      &rtb_Output_GreenIND2_OUT_feyz, &rtb_Output_GreenIND3_OUT_o4yp, &App_Model_DW.sf_IND_Output_Control_Func_jlqz);

    /* SignalConversion generated from: '<S234>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_mowe = rtb_Output_AmberIND_OUT_kmuj;

    /* SignalConversion generated from: '<S234>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_gx5p = rtb_Output_GreenIND2_OUT_feyz;

    /* SignalConversion generated from: '<S234>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_lzzp = rtb_Output_GreenIND3_OUT_o4yp;

    /* SignalConversion generated from: '<S234>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_ajrb;

    /* End of Outputs for SubSystem: '<S223>/RheoStatIndyOutputControl_Type2' */
    break;

   case 2:
    {
      uint16 rtb_Output_AmberIND_OUT;
      uint16 rtb_Output_GreenIND2_OUT;
      uint16 rtb_Output_GreenIND3_OUT;
      uint16 rtb_Output_GreenIND_OUT;
      if (App_Model_DW.SwitchCase_ActiveSubsystem_esff != rtPrevAction) {
        /* Enable for IfAction SubSystem: '<S223>/AutoBrightIndyOutputControl_Type3' incorporates:
         *  ActionPort: '<S232>/ActionPort'
         */
        /* Enable for SwitchCase: '<S223>/Switch Case' incorporates:
         *  Chart: '<S235>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
         *  Chart: '<S235>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
         */
        Amber_IND_with_Anim_cncj_Enable(&App_Model_DW.sf_Amber_IND_with_Animatio_awb4);
        Green_IND_with_Anim_c1ni_Enable(&App_Model_DW.sf_Green_IND_with_Animatio_dcdw);

        /* End of Enable for SubSystem: '<S223>/AutoBrightIndyOutputControl_Type3' */
      }

      /* Outputs for IfAction SubSystem: '<S223>/AutoBrightIndyOutputControl_Type3' incorporates:
       *  ActionPort: '<S232>/ActionPort'
       */
      /* Chart: '<S235>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
      WPC_IND_Output_With_Auto_Bright(rtu_PostProcessIn_cr0j, &App_Model_B.AutoBrightValue_g21i, &App_Model_DW.sf_WPC_IND_Output_With_Auto_Bri);

      /* Chart: '<S235>/Bright_Max_Value_Control_Function_Flow_Graph' */
      Bright_Max_Value_Control_F_nqis(rtu_PostProcessIn_kr5d, App_Model_B.AutoBrightValue_g21i, &App_Model_B.Var_BrightMaxValue_gten, &App_Model_DW.sf_Bright_Max_Value_Contro_af1k);

      /* Chart: '<S235>/Amber_IND_Control_Function_Flow_Graph' */
      Amber_IND_Control_Function_Flow(rtu_PostProcessIn_mowe, App_Model_B.Var_BrightMaxValue_gten, &rtb_Var_AmberIND, &App_Model_DW.sf_Amber_IND_Control_Funct_ixgd);

      /* Chart: '<S235>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
      Amber_IND_with_Animation_C_m52k(App_Model_M, App_Model_B.Var_BrightMaxValue_gten, rtu_PostProcessIn_f2vy, rtu_PostProcessIn_gx5p, &App_Model_B.Var_AmberINDwithAnimation_i4hy,
        &App_Model_B.sf_Amber_IND_with_Animatio_awb4, &App_Model_DW.sf_Amber_IND_with_Animatio_awb4);

      /* Chart: '<S235>/Green_IND_Control_Function_Flow_Graph' */
      Green_IND_Control_Function_Flow(rtu_PostProcessIn_fg01, App_Model_B.Var_BrightMaxValue_gten, &rtb_Var_GreenIND, &App_Model_DW.sf_Green_IND_Control_Funct_bsnb);

      /* Chart: '<S235>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
      Green_IND_with_Animation_C_eqpi(App_Model_M, App_Model_B.Var_BrightMaxValue_gten, rtu_PostProcessIn_gx5p, &App_Model_B.Var_GreenINDwithAnimation1_nlnx,
        &App_Model_B.Var_GreenINDwithAnimation2_pkuj, &App_Model_B.Var_GreenINDwithAnimation3_i05v, &App_Model_B.sf_Green_IND_with_Animatio_dcdw, &App_Model_DW.sf_Green_IND_with_Animatio_dcdw);

      /* Chart: '<S235>/IND_Output_Control_Function_Flow_Graph' */
      if ((uint32)App_Model_DW.is_active_c426_IndyOutputContro == 0U) {
        App_Model_DW.is_active_c426_IndyOutputContro = 1U;

        /*  Transition run once at reset */
        /* Ref_Off */
        /* 1 */
        if ((uint32)rtu_PostProcessIn_lzzp == WPCIndUSMState__Type2) {
          /* Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut ||...Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut ||...Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||... */
          if (((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__Default) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_gx5p ==
               WPC2IndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)
               rtu_PostProcessIn_gx5p == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_gx5p ==
               WPC2IndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ChrgFadeOut)) {
            /*  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
            /* Green IND Light */
            rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1_nlnx;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2_pkuj;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3_i05v;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_gx5p ==
                      WPC2IndCmdState__ErrorFadeOut)) {
            /* Amber IND light */
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_GreenIND_OUT = (uint16)0.0;
                rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
                rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              } else {
                rtb_Output_GreenIND_OUT = 0U;
                rtb_Output_GreenIND2_OUT = 0U;
                rtb_Output_GreenIND3_OUT = 0U;
              }
            } else {
              rtb_Output_GreenIND_OUT = MAX_uint16_T;
              rtb_Output_GreenIND2_OUT = MAX_uint16_T;
              rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            }

            rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation_i4hy;
          } else if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            rtb_Output_AmberIND_OUT = MAX_uint16_T;

            /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
               Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
          }
        } else {
          rtb_Output_GreenIND_OUT = rtb_Var_GreenIND;
          rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND;
          rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND;
          rtb_Output_AmberIND_OUT = rtb_Var_AmberIND;
        }

        /*  Transition run every task on system operation */
        /* 1 */
      } else if ((uint32)rtu_PostProcessIn_lzzp == WPCIndUSMState__Type2) {
        /* Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut ||...Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut ||...Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||... */
        if (((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__Default) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_gx5p ==
             WPC2IndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__2ndChrgFadeIn) || ((uint32)
             rtu_PostProcessIn_gx5p == WPC2IndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_gx5p ==
             WPC2IndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ChrgFadeOut)) {
          /*  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
          /* Green IND Light */
          rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1_nlnx;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2_pkuj;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3_i05v;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_gx5p == WPC2IndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_gx5p ==
                    WPC2IndCmdState__ErrorFadeOut)) {
          /* Amber IND light */
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          }

          rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation_i4hy;
        } else if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            rtb_Output_GreenIND_OUT = (uint16)0.0;
            rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
          } else {
            rtb_Output_GreenIND_OUT = 0U;
            rtb_Output_GreenIND2_OUT = 0U;
            rtb_Output_GreenIND3_OUT = 0U;
            rtb_Output_AmberIND_OUT = 0U;
          }
        } else {
          rtb_Output_GreenIND_OUT = MAX_uint16_T;
          rtb_Output_GreenIND2_OUT = MAX_uint16_T;
          rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          rtb_Output_AmberIND_OUT = MAX_uint16_T;

          /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
             Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
        }
      } else {
        rtb_Output_GreenIND_OUT = rtb_Var_GreenIND;
        rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND;
        rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND;
        rtb_Output_AmberIND_OUT = rtb_Var_AmberIND;
      }

      /* End of Chart: '<S235>/IND_Output_Control_Function_Flow_Graph' */

      /* SignalConversion generated from: '<S232>/P_AmberIND_OUT' */
      *rty_IndyOutput_Sig_mowe = rtb_Output_AmberIND_OUT;

      /* SignalConversion generated from: '<S232>/P_GreenIND2_OUT' */
      *rty_IndyOutput_Sig_gx5p = rtb_Output_GreenIND2_OUT;

      /* SignalConversion generated from: '<S232>/P_GreenIND3_OUT' */
      *rty_IndyOutput_Sig_lzzp = rtb_Output_GreenIND3_OUT;

      /* SignalConversion generated from: '<S232>/P_GreenIND_OUT' */
      *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT;

      /* End of Outputs for SubSystem: '<S223>/AutoBrightIndyOutputControl_Type3' */
    }
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S223>/Switch Case' */
}

/*
 * System initialize for function-call system:
 *    '<S523>/FadeIn'
 *    '<S558>/FadeIn'
 *    '<S488>/FadeIn'
 */
void App_Model_FadeIn_doz4_Init(DW_FadeIn_App_Model_prxo_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S529>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S531>/Delay Input1'
   *
   * Block description for '<S531>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S523>/FadeIn'
 *    '<S558>/FadeIn'
 *    '<S488>/FadeIn'
 */
void App_Model_FadeIn_pvaj_Reset(DW_FadeIn_App_Model_prxo_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S529>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S531>/Delay Input1'
   *
   * Block description for '<S531>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S523>/FadeIn'
 *    '<S558>/FadeIn'
 *    '<S488>/FadeIn'
 */
void App_Model_FadeIn_ptpu(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger, float64 rtu_pass, uint16 *rty_y_FadeIn, DW_FadeIn_App_Model_prxo_T *localDW)
{
  float64 rtb_Switch3;
  uint16 rtb_Switch5;

  /* Switch: '<S529>/Switch' incorporates:
   *  Constant: '<S529>/Constant1'
   *  Switch: '<S529>/Switch1'
   */
  if (rtu_Trigger > 0) {
    /* Switch: '<S529>/Switch3' incorporates:
     *  Constant: '<S529>/Constant2'
     *  DataTypeConversion: '<S529>/Data Type Conversion'
     *  Product: '<S529>/Divide'
     */
    rtb_Switch3 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);

    /* Switch: '<S529>/Switch6' */
    if (rtu_pass > 0.0) {
      /* Switch: '<S529>/Switch1' incorporates:
       *  Constant: '<S529>/Constant5'
       */
      localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);
    }

    /* End of Switch: '<S529>/Switch6' */
  } else {
    rtb_Switch3 = (float64)((uint16)0U);

    /* Switch: '<S529>/Switch1' incorporates:
     *  Constant: '<S529>/Constant1'
     */
    localDW->UnitDelay3_DSTATE = rtb_Switch3;
  }

  /* End of Switch: '<S529>/Switch' */

  /* Switch: '<S529>/Switch3' incorporates:
   *  Sum: '<S529>/Add1'
   */
  rtb_Switch3 += localDW->UnitDelay3_DSTATE;

  /* Switch: '<S529>/Switch3' incorporates:
   *  DataTypeConversion: '<S529>/Data Type Conversion'
   *  Logic: '<S529>/AND'
   *  RelationalOperator: '<S531>/FixPt Relational Operator'
   *  UnitDelay: '<S531>/Delay Input1'
   *
   * Block description for '<S531>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger != 0) && (rtu_pass != 0.0)) {
    /* DataTypeConversion: '<S529>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S529>/Unit Delay3'
     */
    localDW->UnitDelay3_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    /* DataTypeConversion: '<S529>/Data Type Conversion1' incorporates:
     *  UnitDelay: '<S529>/Unit Delay3'
     */
    localDW->UnitDelay3_DSTATE = rtb_Switch3;
  }

  /* End of Switch: '<S529>/Switch3' */

  /* Switch: '<S529>/Switch5' */
  if (rtu_pass > 0.0) {
    /* Switch: '<S529>/Switch5' incorporates:
     *  DataTypeConversion: '<S529>/Data Type Conversion'
     */
    rtb_Switch5 = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S529>/Switch5' incorporates:
     *  UnitDelay: '<S529>/Unit Delay3'
     */
    rtb_Switch5 = (uint16)localDW->UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S529>/Switch5' */

  /* Switch: '<S529>/Switch2' incorporates:
   *  Constant: '<S529>/Constant4'
   *  Switch: '<S532>/Switch2'
   */
  if (rtu_Trigger > 0) {
    /* Switch: '<S532>/Switch2' incorporates:
     *  Constant: '<S529>/Constant4'
     *  DataTypeConversion: '<S529>/Data Type Conversion'
     *  RelationalOperator: '<S532>/LowerRelop1'
     *  RelationalOperator: '<S532>/UpperRelop'
     *  Switch: '<S532>/Switch'
     */
    if (rtb_Switch5 > rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch5 < ((uint16)0U)) {
      /* Switch: '<S532>/Switch' incorporates:
       *  Constant: '<S529>/Constant4'
       */
      *rty_y_FadeIn = ((uint16)0U);
    } else {
      *rty_y_FadeIn = rtb_Switch5;
    }
  } else {
    *rty_y_FadeIn = ((uint16)0U);
  }

  /* End of Switch: '<S529>/Switch2' */

  /* Update for UnitDelay: '<S531>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S529>/Data Type Conversion'
   *
   * Block description for '<S531>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S523>/FadeOut'
 *    '<S558>/FadeOut'
 *    '<S488>/FadeOut'
 */
void App_Model_FadeOut_dnmv_Init(DW_FadeOut_App_Model_m1tn_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S533>/Delay Input1'
   *
   * Block description for '<S533>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S530>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S523>/FadeOut'
 *    '<S558>/FadeOut'
 *    '<S488>/FadeOut'
 */
void App_Model_FadeOut_hpxk_Reset(DW_FadeOut_App_Model_m1tn_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S533>/Delay Input1'
   *
   * Block description for '<S533>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S530>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S523>/FadeOut'
 *    '<S558>/FadeOut'
 *    '<S488>/FadeOut'
 */
void App_Model_FadeOut_gvzk(uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut, DW_FadeOut_App_Model_m1tn_T *localDW)
{
  /* Switch: '<S530>/Switch6' incorporates:
   *  DataTypeConversion: '<S530>/Data Type Conversion'
   *  Logic: '<S530>/AND'
   *  RelationalOperator: '<S533>/FixPt Relational Operator'
   *  Switch: '<S530>/Switch4'
   *  Switch: '<S530>/Switch5'
   *  Switch: '<S530>/Switch8'
   *  UnitDelay: '<S533>/Delay Input1'
   *
   * Block description for '<S533>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtu_pass > 0.0) {
    /* Switch: '<S530>/Switch6' incorporates:
     *  DataTypeConversion: '<S530>/Data Type Conversion'
     */
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger_FO != 0) && (rtu_pass != 0.0)) {
    /* Switch: '<S530>/Switch6' incorporates:
     *  DataTypeConversion: '<S530>/Data Type Conversion'
     *  Switch: '<S530>/Switch5'
     */
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    float64 rtb_Switch4_ion0;
    float64 rtb_Switch8;
    if (rtu_Trigger_FO > 0) {
      /* Switch: '<S530>/Switch4' incorporates:
       *  Constant: '<S530>/Constant8'
       *  DataTypeConversion: '<S530>/Data Type Conversion'
       *  Product: '<S530>/Divide2'
       *  Switch: '<S530>/Switch5'
       */
      rtb_Switch4_ion0 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);

      /* Switch: '<S530>/Switch8' incorporates:
       *  MinMax: '<S530>/Max'
       *  Switch: '<S530>/Switch5'
       *  UnitDelay: '<S530>/Unit Delay'
       */
      rtb_Switch8 = fmax(localDW->UnitDelay_DSTATE, (float64)rtu_preValue);
    } else {
      /* Switch: '<S530>/Switch4' incorporates:
       *  Constant: '<S530>/Constant2'
       *  Switch: '<S530>/Switch5'
       */
      rtb_Switch4_ion0 = (float64)((uint16)0U);

      /* Switch: '<S530>/Switch8' incorporates:
       *  DataTypeConversion: '<S530>/Data Type Conversion'
       *  Switch: '<S530>/Switch5'
       */
      rtb_Switch8 = (float64)rtu_Var_BrightMaxValue;
    }

    /* Switch: '<S530>/Switch6' incorporates:
     *  Sum: '<S530>/Add13'
     *  Switch: '<S530>/Switch5'
     */
    localDW->UnitDelay_DSTATE = rtb_Switch8 - rtb_Switch4_ion0;
  }

  /* End of Switch: '<S530>/Switch6' */

  /* Switch: '<S534>/Switch2' incorporates:
   *  Constant: '<S530>/Constant1'
   *  DataTypeConversion: '<S530>/Data Type Conversion'
   *  RelationalOperator: '<S534>/LowerRelop1'
   *  RelationalOperator: '<S534>/UpperRelop'
   *  Switch: '<S534>/Switch'
   *  UnitDelay: '<S530>/Unit Delay'
   */
  if (localDW->UnitDelay_DSTATE > (float64)rtu_Var_BrightMaxValue) {
    localDW->UnitDelay_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else if (localDW->UnitDelay_DSTATE < (float64)((uint16)0U)) {
    /* Switch: '<S534>/Switch' incorporates:
     *  Constant: '<S530>/Constant1'
     *  UnitDelay: '<S530>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = (float64)((uint16)0U);
  } else {
    /* no actions */
  }

  /* End of Switch: '<S534>/Switch2' */

  /* Switch: '<S530>/Switch7' */
  if (rtu_Trigger_FO > 0) {
    /* DataTypeConversion: '<S530>/Data Type Conversion9' incorporates:
     *  UnitDelay: '<S530>/Unit Delay'
     */
    *rty_y_FadeOut = (uint16)localDW->UnitDelay_DSTATE;
  } else {
    /* DataTypeConversion: '<S530>/Data Type Conversion9' incorporates:
     *  Constant: '<S530>/Constant1'
     */
    *rty_y_FadeOut = ((uint16)0U);
  }

  /* End of Switch: '<S530>/Switch7' */

  /* Update for UnitDelay: '<S533>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S530>/Data Type Conversion'
   *
   * Block description for '<S533>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
static void App_M_Bright_Error_Control_nftz(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animati_atgr_T *localB,
  DW_Amber_IND_with_Animat_pevs_T *localDW)
{
  if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__Default) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S523>/FadeIn' */
    App_Model_FadeIn_ptpu(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S523>/FadeIn' */
    localB->Var_BrightMaxValue_bq5h = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_AmberINDwithAnimation;
    localB->Trigger_FO = 0;
    localB->pass_n2fm = 0.0;

    /* Outputs for Function Call SubSystem: '<S523>/FadeOut' */
    App_Model_FadeOut_gvzk(localB->Var_BrightMaxValue_bq5h, localB->preValue, localB->Trigger_FO, localB->pass_n2fm, &localB->DataTypeConversion9, &localDW->FadeOut);

    /* End of Outputs for SubSystem: '<S523>/FadeOut' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    localDW->pass = 0.0;
  } else {
    switch (rtu_Input_INT_RWPCIndCmdState) {
     case RWPCIndCmdState__ErrorOn:
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S523>/FadeIn' */
      App_Model_FadeIn_ptpu(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S523>/FadeIn' */
      localB->Var_BrightMaxValue_bq5h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 0;
      localB->pass_n2fm = 0.0;

      /* Outputs for Function Call SubSystem: '<S523>/FadeOut' */
      App_Model_FadeOut_gvzk(localB->Var_BrightMaxValue_bq5h, localB->preValue, localB->Trigger_FO, localB->pass_n2fm, &localB->DataTypeConversion9, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S523>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      localDW->pass = 0.0;
      break;

     case RWPCIndCmdState__ErrorFadeIn:
      if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 1.0)) {
        localDW->pass = 1.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 1.0;

        /* Outputs for Function Call SubSystem: '<S523>/FadeIn' */
        App_Model_FadeIn_ptpu(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S523>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = localB->Switch2;
      } else {
        localB->Var_BrightMaxValue_bq5h = rtu_Var_BrightMaxValue;
        localB->preValue = *rty_Var_AmberINDwithAnimation;
        localB->Trigger_FO = 0;
        localB->pass_n2fm = 0.0;

        /* Outputs for Function Call SubSystem: '<S523>/FadeOut' */
        App_Model_FadeOut_gvzk(localB->Var_BrightMaxValue_bq5h, localB->preValue, localB->Trigger_FO, localB->pass_n2fm, &localB->DataTypeConversion9, &localDW->FadeOut);

        /* End of Outputs for SubSystem: '<S523>/FadeOut' */
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 0.0;

        /* Outputs for Function Call SubSystem: '<S523>/FadeIn' */
        App_Model_FadeIn_ptpu(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S523>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = localB->Switch2;
        localDW->pass = 0.0;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  if ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut) {
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 2.0)) {
      localDW->pass = 2.0;
      localB->Var_BrightMaxValue_bq5h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 1;
      localB->pass_n2fm = 1.0;

      /* Outputs for Function Call SubSystem: '<S523>/FadeOut' */
      App_Model_FadeOut_gvzk(localB->Var_BrightMaxValue_bq5h, localB->preValue, localB->Trigger_FO, localB->pass_n2fm, &localB->DataTypeConversion9, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S523>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = localB->DataTypeConversion9;
    } else {
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S523>/FadeIn' */
      App_Model_FadeIn_ptpu(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S523>/FadeIn' */
      localB->Var_BrightMaxValue_bq5h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 1;
      localB->pass_n2fm = 0.0;

      /* Outputs for Function Call SubSystem: '<S523>/FadeOut' */
      App_Model_FadeOut_gvzk(localB->Var_BrightMaxValue_bq5h, localB->preValue, localB->Trigger_FO, localB->pass_n2fm, &localB->DataTypeConversion9, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S523>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = localB->DataTypeConversion9;
      localDW->pass = 0.0;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S556>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S486>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 */
void Amber_IND_with_Animat_crfg_Init(uint16 *rty_Var_AmberINDwithAnimation, DW_Amber_IND_with_Animat_pevs_T *localDW)
{
  localDW->is_active_c436_IndyOutputContro = 0U;
  localDW->pass = 0.0;
  *rty_Var_AmberINDwithAnimation = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S523>/FadeIn' */
  App_Model_FadeIn_doz4_Init(&localDW->FadeIn);

  /* End of SystemInitialize for SubSystem: '<S523>/FadeIn' */

  /* SystemInitialize for Function Call SubSystem: '<S523>/FadeOut' */
  App_Model_FadeOut_dnmv_Init(&localDW->FadeOut);

  /* End of SystemInitialize for SubSystem: '<S523>/FadeOut' */
}

/*
 * Enable for atomic system:
 *    '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S556>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S486>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 */
void Amber_IND_with_Anim_ddyk_Enable(DW_Amber_IND_with_Animat_pevs_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S523>/FadeIn' */
  App_Model_FadeIn_pvaj_Reset(&localDW->FadeIn);

  /* End of SystemReset for SubSystem: '<S523>/FadeIn' */

  /* SystemReset for Function Call SubSystem: '<S523>/FadeOut' */
  App_Model_FadeOut_hpxk_Reset(&localDW->FadeOut);

  /* End of SystemReset for SubSystem: '<S523>/FadeOut' */
}

/*
 * Output and update for atomic system:
 *    '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S556>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S486>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
 */
void Amber_IND_with_Animation_C_lyja(uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation,
  B_Amber_IND_with_Animati_atgr_T *localB, DW_Amber_IND_with_Animat_pevs_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c436_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c436_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S523>/FadeIn' */
    App_Model_FadeIn_ptpu(localB->Var_BrightMaxValue, localB->Trigger, localB->pass, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S523>/FadeIn' */
    localB->Var_BrightMaxValue_bq5h = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_AmberINDwithAnimation;
    localB->Trigger_FO = 0;
    localB->pass_n2fm = 0.0;

    /* Outputs for Function Call SubSystem: '<S523>/FadeOut' */
    App_Model_FadeOut_gvzk(localB->Var_BrightMaxValue_bq5h, localB->preValue, localB->Trigger_FO, localB->pass_n2fm, &localB->DataTypeConversion9, &localDW->FadeOut);

    /* End of Outputs for SubSystem: '<S523>/FadeOut' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    if ((uint32)rtu_b_SyncAmber == Off) {
      if (0.0 < 65536.0) {
        if (0.0 >= 0.0) {
          *rty_Var_AmberINDwithAnimation = (uint16)0.0;
        } else {
          *rty_Var_AmberINDwithAnimation = 0U;
        }
      } else {
        *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
      }

      /* 1 */
    } else if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
                RWPCIndCmdState__ErrorFadeOut) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__Default)) {
      App_M_Bright_Error_Control_nftz(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_AmberINDwithAnimation, localB, localDW);

      /* Not used in Amber LED */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
  } else if ((uint32)rtu_b_SyncAmber == Off) {
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_AmberINDwithAnimation = (uint16)0.0;
      } else {
        *rty_Var_AmberINDwithAnimation = 0U;
      }
    } else {
      *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
    }

    /* 1 */
  } else if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
              RWPCIndCmdState__ErrorFadeOut) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__Default)) {
    App_M_Bright_Error_Control_nftz(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_AmberINDwithAnimation, localB, localDW);

    /* Not used in Amber LED */
  } else if (0.0 < 65536.0) {
    if (0.0 >= 0.0) {
      *rty_Var_AmberINDwithAnimation = (uint16)0.0;
    } else {
      *rty_Var_AmberINDwithAnimation = 0U;
    }
  } else {
    *rty_Var_AmberINDwithAnimation = MAX_uint16_T;
  }

  /* End of Chart: '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
}

/*
 * System initialize for function-call system:
 *    '<S526>/FadeIn1'
 *    '<S561>/FadeIn1'
 *    '<S491>/FadeIn1'
 */
void App_Model_FadeIn1_keed_Init(DW_FadeIn1_App_Model_b0rw_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S541>/Delay Input1'
   *
   * Block description for '<S541>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S535>/Switch1' incorporates:
   *  UnitDelay: '<S535>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S526>/FadeIn1'
 *    '<S561>/FadeIn1'
 *    '<S491>/FadeIn1'
 */
void App_Model_FadeIn1_ed0b_Reset(DW_FadeIn1_App_Model_b0rw_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S541>/Delay Input1'
   *
   * Block description for '<S541>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S535>/Switch1' incorporates:
   *  UnitDelay: '<S535>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S526>/FadeIn1'
 *    '<S561>/FadeIn1'
 *    '<S491>/FadeIn1'
 */
void App_Model_FadeIn1_gjxk(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger1, float64 rtu_pass1, uint16 *rty_y_FadeIn1, DW_FadeIn1_App_Model_b0rw_T *localDW)
{
  uint16 rtb_Switch5;

  /* Switch: '<S535>/Switch3' incorporates:
   *  DataTypeConversion: '<S535>/Data Type Conversion'
   *  Logic: '<S535>/AND'
   *  RelationalOperator: '<S541>/FixPt Relational Operator'
   *  Switch: '<S535>/Switch'
   *  Switch: '<S535>/Switch1'
   *  UnitDelay: '<S541>/Delay Input1'
   *
   * Block description for '<S541>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger1 != 0) && (rtu_pass1 != 0.0)) {
    /* Switch: '<S535>/Switch1' incorporates:
     *  Switch: '<S535>/Switch3'
     */
    localDW->UnitDelay3_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    float64 rtb_Switch_mvl2;
    if (rtu_Trigger1 > 0) {
      /* Switch: '<S535>/Switch6' incorporates:
       *  Switch: '<S535>/Switch1'
       */
      if (rtu_pass1 > 0.0) {
        /* Switch: '<S535>/Switch1' incorporates:
         *  Constant: '<S535>/Constant5'
         */
        localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);
      }

      /* End of Switch: '<S535>/Switch6' */

      /* Switch: '<S535>/Switch' incorporates:
       *  Constant: '<S535>/Constant2'
       *  Product: '<S535>/Divide'
       */
      rtb_Switch_mvl2 = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    } else {
      /* Switch: '<S535>/Switch1' incorporates:
       *  Constant: '<S535>/Constant3'
       *  Switch: '<S535>/Switch'
       */
      localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);

      /* Switch: '<S535>/Switch' */
      rtb_Switch_mvl2 = localDW->UnitDelay3_DSTATE;
    }

    /* Switch: '<S535>/Switch1' incorporates:
     *  Sum: '<S535>/Add1'
     *  Switch: '<S535>/Switch3'
     */
    localDW->UnitDelay3_DSTATE += rtb_Switch_mvl2;
  }

  /* End of Switch: '<S535>/Switch3' */

  /* Switch: '<S535>/Switch5' */
  if (rtu_pass1 > 0.0) {
    /* Switch: '<S535>/Switch5' incorporates:
     *  DataTypeConversion: '<S535>/Data Type Conversion'
     */
    rtb_Switch5 = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S535>/Switch5' incorporates:
     *  UnitDelay: '<S535>/Unit Delay3'
     */
    rtb_Switch5 = (uint16)localDW->UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S535>/Switch5' */

  /* Switch: '<S535>/Switch2' incorporates:
   *  Constant: '<S535>/Constant4'
   *  Switch: '<S542>/Switch2'
   */
  if (rtu_Trigger1 > 0) {
    /* Switch: '<S542>/Switch2' incorporates:
     *  Constant: '<S535>/Constant4'
     *  DataTypeConversion: '<S535>/Data Type Conversion'
     *  RelationalOperator: '<S542>/LowerRelop1'
     *  RelationalOperator: '<S542>/UpperRelop'
     *  Switch: '<S542>/Switch'
     */
    if (rtb_Switch5 > rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn1 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch5 < ((uint16)0U)) {
      /* Switch: '<S542>/Switch' incorporates:
       *  Constant: '<S535>/Constant4'
       */
      *rty_y_FadeIn1 = ((uint16)0U);
    } else {
      *rty_y_FadeIn1 = rtb_Switch5;
    }
  } else {
    *rty_y_FadeIn1 = ((uint16)0U);
  }

  /* End of Switch: '<S535>/Switch2' */

  /* Update for UnitDelay: '<S541>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S535>/Data Type Conversion'
   *
   * Block description for '<S541>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S526>/FadeOut1'
 *    '<S561>/FadeOut1'
 *    '<S491>/FadeOut1'
 */
void App_Model_FadeOut1_c3qa_Init(DW_FadeOut1_App_Model_pelm_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S547>/Delay Input2'
   *
   * Block description for '<S547>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S526>/FadeOut1'
 *    '<S561>/FadeOut1'
 *    '<S491>/FadeOut1'
 */
void App_Model_FadeOut1_lxyd_Reset(DW_FadeOut1_App_Model_pelm_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S547>/Delay Input2'
   *
   * Block description for '<S547>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S526>/FadeOut1'
 *    '<S561>/FadeOut1'
 *    '<S491>/FadeOut1'
 */
void App_Model_FadeOut1_e32b_Enable(DW_FadeOut1_App_Model_pelm_T *localDW)
{
  localDW->FadeOut1_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S526>/FadeOut1'
 *    '<S561>/FadeOut1'
 *    '<S491>/FadeOut1'
 */
void App_Model_FadeOut1_cr24(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger1_FO, float64 rtu_pass1, uint16 *rty_y_FadeOut1, const
  ConstB_FadeOut1_App_Mode_lif3_T *localC, DW_FadeOut1_App_Model_pelm_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add13_b3ym;
  float64 rtb_Switch4_hcdb;
  float64 rtb_sampletime;
  if (localDW->FadeOut1_RESET_ELAPS_T) {
    localDW->FadeOut1_ELAPS_T[0] = 0U;
    localDW->FadeOut1_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut1_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut1_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut1_ELAPS_T[0] = FadeOut1_ELAPS_T_tmp - localDW->FadeOut1_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut1_PREV_T[1];
    if (localDW->FadeOut1_PREV_T[0] > FadeOut1_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut1_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut1_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut1_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut1_RESET_ELAPS_T = false;

  /* Switch: '<S538>/Switch4' */
  if (rtu_pass1 > 0.0) {
    /* Switch: '<S538>/Switch4' incorporates:
     *  DataStoreRead: '<S538>/Data Store Read'
     *  DataTypeConversion: '<S538>/Data Type Conversion6'
     *  UnaryMinus: '<S538>/Unary Minus1'
     */
    rtb_Switch4_hcdb = -((float64)Par_AutoBrightLevel091);
  } else {
    /* Switch: '<S538>/Switch4' incorporates:
     *  DataTypeConversion: '<S538>/Data Type Conversion'
     *  UnaryMinus: '<S538>/Unary Minus'
     */
    rtb_Switch4_hcdb = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S538>/Switch4' */
  /* Switch: '<S538>/Switch1' */
  if (rtu_Trigger1_FO > 0) {
    /* SampleTimeMath: '<S547>/sample time' incorporates:
     *  Constant: '<S538>/Constant8'
     *  Product: '<S538>/Divide2'
     *
     * About '<S547>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_sampletime = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
  } else {
    /* SampleTimeMath: '<S547>/sample time' incorporates:
     *  Constant: '<S538>/Constant'
     *
     * About '<S547>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_sampletime = (float64)((uint16)0U);
  }

  /* End of Switch: '<S538>/Switch1' */

  /* Sum: '<S538>/Add13' */
  rtb_Add13_b3ym = (float64)rtu_preValue - rtb_sampletime;

  /* SampleTimeMath: '<S547>/sample time'
   *
   * About '<S547>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut1_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut1_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S547>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S538>/Data Type Conversion'
   *  SampleTimeMath: '<S547>/sample time'
   *
   * About '<S547>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_sampletime = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S538>/Switch2' incorporates:
   *  Constant: '<S538>/Constant2'
   *  Switch: '<S538>/Switch7'
   */
  if (rtu_pass1 > 0.0) {
    rtb_Add13_b3ym = localC->DataTypeConversion5;
  } else if (rtu_Trigger1_FO > 0) {
    /* Switch: '<S548>/Switch2' incorporates:
     *  Constant: '<S538>/Constant2'
     *  RelationalOperator: '<S548>/LowerRelop1'
     *  RelationalOperator: '<S548>/UpperRelop'
     *  Switch: '<S548>/Switch'
     */
    if (rtb_Add13_b3ym > (float64)rtu_preValue) {
      /* Switch: '<S538>/Switch7' */
      rtb_Add13_b3ym = (float64)rtu_preValue;
    } else if (rtb_Add13_b3ym < (float64)((uint16)0U)) {
      /* Switch: '<S548>/Switch' incorporates:
       *  Constant: '<S538>/Constant2'
       *  Switch: '<S538>/Switch7'
       */
      rtb_Add13_b3ym = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S548>/Switch2' */
  } else {
    rtb_Add13_b3ym = (float64)((uint16)0U);
  }

  /* End of Switch: '<S538>/Switch2' */

  /* Sum: '<S547>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S547>/Delay Input2'
   *
   * Block description for '<S547>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S547>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add13_b3ym -= localDW->DelayInput2_DSTATE;

  /* Product: '<S547>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S547>/sample time'
   *
   * About '<S547>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_hcdb *= elapseTime;

  /* Switch: '<S549>/Switch2' incorporates:
   *  RelationalOperator: '<S549>/LowerRelop1'
   *  RelationalOperator: '<S549>/UpperRelop'
   *  Switch: '<S549>/Switch'
   */
  if (rtb_Add13_b3ym > rtb_sampletime) {
    rtb_Add13_b3ym = rtb_sampletime;
  } else if (rtb_Add13_b3ym < rtb_Switch4_hcdb) {
    /* Switch: '<S549>/Switch' */
    rtb_Add13_b3ym = rtb_Switch4_hcdb;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S549>/Switch2' */

  /* Sum: '<S547>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S547>/Delay Input2'
   *
   * Block description for '<S547>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S547>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add13_b3ym;

  /* Switch: '<S538>/Switch3' */
  if (rtu_pass1 > 0.0) {
    /* DataTypeConversion: '<S538>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<S538>/Data Type Conversion'
     *  Switch: '<S538>/Switch3'
     */
    *rty_y_FadeOut1 = rtu_Var_BrightMaxValue;
  } else {
    /* DataTypeConversion: '<S538>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<S538>/Data Type Conversion1'
     *  Switch: '<S538>/Switch3'
     *  UnitDelay: '<S547>/Delay Input2'
     *
     * Block description for '<S547>/Delay Input2':
     *
     *  Store in Global RAM
     */
    *rty_y_FadeOut1 = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S538>/Switch3' */
}

/*
 * System initialize for function-call system:
 *    '<S526>/FadeIn2'
 *    '<S561>/FadeIn2'
 *    '<S491>/FadeIn2'
 */
void App_Model_FadeIn2_kjhn_Init(DW_FadeIn2_App_Model_ph3h_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S543>/Delay Input1'
   *
   * Block description for '<S543>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S536>/Switch1' incorporates:
   *  UnitDelay: '<S536>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S526>/FadeIn2'
 *    '<S561>/FadeIn2'
 *    '<S491>/FadeIn2'
 */
void App_Model_FadeIn2_d1tk_Reset(DW_FadeIn2_App_Model_ph3h_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S543>/Delay Input1'
   *
   * Block description for '<S543>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S536>/Switch1' incorporates:
   *  UnitDelay: '<S536>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S526>/FadeIn2'
 *    '<S561>/FadeIn2'
 *    '<S491>/FadeIn2'
 */
void App_Model_FadeIn2_jdzr(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger2, float64 rtu_pass2, uint16 *rty_y_FadeIn2, DW_FadeIn2_App_Model_ph3h_T *localDW)
{
  uint16 rtb_Switch5;

  /* Switch: '<S536>/Switch3' incorporates:
   *  DataTypeConversion: '<S536>/Data Type Conversion'
   *  Logic: '<S536>/AND'
   *  RelationalOperator: '<S543>/FixPt Relational Operator'
   *  Switch: '<S536>/Switch'
   *  Switch: '<S536>/Switch1'
   *  UnitDelay: '<S543>/Delay Input1'
   *
   * Block description for '<S543>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger2 != 0) && (rtu_pass2 != 0.0)) {
    /* Switch: '<S536>/Switch1' incorporates:
     *  Switch: '<S536>/Switch3'
     */
    localDW->UnitDelay3_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    float64 rtb_Switch_a2ag;
    if (rtu_Trigger2 > 0) {
      /* Switch: '<S536>/Switch6' incorporates:
       *  Switch: '<S536>/Switch1'
       */
      if (rtu_pass2 > 0.0) {
        /* Switch: '<S536>/Switch1' incorporates:
         *  Constant: '<S536>/Constant5'
         */
        localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);
      }

      /* End of Switch: '<S536>/Switch6' */

      /* Switch: '<S536>/Switch' incorporates:
       *  Constant: '<S536>/Constant2'
       *  Product: '<S536>/Divide'
       */
      rtb_Switch_a2ag = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    } else {
      /* Switch: '<S536>/Switch1' incorporates:
       *  Constant: '<S536>/Constant3'
       *  Switch: '<S536>/Switch'
       */
      localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);

      /* Switch: '<S536>/Switch' */
      rtb_Switch_a2ag = localDW->UnitDelay3_DSTATE;
    }

    /* Switch: '<S536>/Switch1' incorporates:
     *  Sum: '<S536>/Add1'
     *  Switch: '<S536>/Switch3'
     */
    localDW->UnitDelay3_DSTATE += rtb_Switch_a2ag;
  }

  /* End of Switch: '<S536>/Switch3' */

  /* Switch: '<S536>/Switch5' */
  if (rtu_pass2 > 0.0) {
    /* Switch: '<S536>/Switch5' incorporates:
     *  DataTypeConversion: '<S536>/Data Type Conversion'
     */
    rtb_Switch5 = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S536>/Switch5' incorporates:
     *  UnitDelay: '<S536>/Unit Delay3'
     */
    rtb_Switch5 = (uint16)localDW->UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S536>/Switch5' */

  /* Switch: '<S536>/Switch2' incorporates:
   *  Constant: '<S536>/Constant4'
   *  Switch: '<S544>/Switch2'
   */
  if (rtu_Trigger2 > 0) {
    /* Switch: '<S544>/Switch2' incorporates:
     *  Constant: '<S536>/Constant4'
     *  DataTypeConversion: '<S536>/Data Type Conversion'
     *  RelationalOperator: '<S544>/LowerRelop1'
     *  RelationalOperator: '<S544>/UpperRelop'
     *  Switch: '<S544>/Switch'
     */
    if (rtb_Switch5 > rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn2 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch5 < ((uint16)0U)) {
      /* Switch: '<S544>/Switch' incorporates:
       *  Constant: '<S536>/Constant4'
       */
      *rty_y_FadeIn2 = ((uint16)0U);
    } else {
      *rty_y_FadeIn2 = rtb_Switch5;
    }
  } else {
    *rty_y_FadeIn2 = ((uint16)0U);
  }

  /* End of Switch: '<S536>/Switch2' */

  /* Update for UnitDelay: '<S543>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S536>/Data Type Conversion'
   *
   * Block description for '<S543>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S526>/FadeOut2'
 *    '<S561>/FadeOut2'
 *    '<S491>/FadeOut2'
 */
void App_Model_FadeOut2_mud4_Init(DW_FadeOut2_App_Model_bhad_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S550>/Delay Input2'
   *
   * Block description for '<S550>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S526>/FadeOut2'
 *    '<S561>/FadeOut2'
 *    '<S491>/FadeOut2'
 */
void App_Model_FadeOut2_jnvs_Reset(DW_FadeOut2_App_Model_bhad_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S550>/Delay Input2'
   *
   * Block description for '<S550>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S526>/FadeOut2'
 *    '<S561>/FadeOut2'
 *    '<S491>/FadeOut2'
 */
void App_Model_FadeOut2_lnni_Enable(DW_FadeOut2_App_Model_bhad_T *localDW)
{
  localDW->FadeOut2_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S526>/FadeOut2'
 *    '<S561>/FadeOut2'
 *    '<S491>/FadeOut2'
 */
void App_Model_FadeOut2_annl(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger2_FO, float64 rtu_pass2, uint16 *rty_y_FadeOut2, const
  ConstB_FadeOut2_App_Mode_g3pr_T *localC, DW_FadeOut2_App_Model_bhad_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add13_jqis;
  float64 rtb_Switch4_igm1;
  float64 rtb_sampletime;
  if (localDW->FadeOut2_RESET_ELAPS_T) {
    localDW->FadeOut2_ELAPS_T[0] = 0U;
    localDW->FadeOut2_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut2_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut2_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut2_ELAPS_T[0] = FadeOut2_ELAPS_T_tmp - localDW->FadeOut2_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut2_PREV_T[1];
    if (localDW->FadeOut2_PREV_T[0] > FadeOut2_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut2_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut2_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut2_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut2_RESET_ELAPS_T = false;

  /* Switch: '<S539>/Switch4' */
  if (rtu_pass2 > 0.0) {
    /* Switch: '<S539>/Switch4' incorporates:
     *  DataStoreRead: '<S539>/Data Store Read'
     *  DataTypeConversion: '<S539>/Data Type Conversion6'
     *  UnaryMinus: '<S539>/Unary Minus1'
     */
    rtb_Switch4_igm1 = -((float64)Par_AutoBrightLevel091);
  } else {
    /* Switch: '<S539>/Switch4' incorporates:
     *  DataTypeConversion: '<S539>/Data Type Conversion'
     *  UnaryMinus: '<S539>/Unary Minus'
     */
    rtb_Switch4_igm1 = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S539>/Switch4' */
  /* Switch: '<S539>/Switch1' */
  if (rtu_Trigger2_FO > 0) {
    /* SampleTimeMath: '<S550>/sample time' incorporates:
     *  Constant: '<S539>/Constant8'
     *  Product: '<S539>/Divide2'
     *
     * About '<S550>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_sampletime = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
  } else {
    /* SampleTimeMath: '<S550>/sample time' incorporates:
     *  Constant: '<S539>/Constant'
     *
     * About '<S550>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_sampletime = (float64)((uint16)0U);
  }

  /* End of Switch: '<S539>/Switch1' */

  /* Sum: '<S539>/Add13' */
  rtb_Add13_jqis = (float64)rtu_preValue - rtb_sampletime;

  /* SampleTimeMath: '<S550>/sample time'
   *
   * About '<S550>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut2_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut2_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S550>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S539>/Data Type Conversion'
   *  SampleTimeMath: '<S550>/sample time'
   *
   * About '<S550>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_sampletime = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S539>/Switch2' incorporates:
   *  Constant: '<S539>/Constant2'
   *  Switch: '<S539>/Switch7'
   */
  if (rtu_pass2 > 0.0) {
    rtb_Add13_jqis = localC->DataTypeConversion5;
  } else if (rtu_Trigger2_FO > 0) {
    /* Switch: '<S551>/Switch2' incorporates:
     *  Constant: '<S539>/Constant2'
     *  RelationalOperator: '<S551>/LowerRelop1'
     *  RelationalOperator: '<S551>/UpperRelop'
     *  Switch: '<S551>/Switch'
     */
    if (rtb_Add13_jqis > (float64)rtu_preValue) {
      /* Switch: '<S539>/Switch7' */
      rtb_Add13_jqis = (float64)rtu_preValue;
    } else if (rtb_Add13_jqis < (float64)((uint16)0U)) {
      /* Switch: '<S551>/Switch' incorporates:
       *  Constant: '<S539>/Constant2'
       *  Switch: '<S539>/Switch7'
       */
      rtb_Add13_jqis = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S551>/Switch2' */
  } else {
    rtb_Add13_jqis = (float64)((uint16)0U);
  }

  /* End of Switch: '<S539>/Switch2' */

  /* Sum: '<S550>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S550>/Delay Input2'
   *
   * Block description for '<S550>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S550>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add13_jqis -= localDW->DelayInput2_DSTATE;

  /* Product: '<S550>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S550>/sample time'
   *
   * About '<S550>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_igm1 *= elapseTime;

  /* Switch: '<S552>/Switch2' incorporates:
   *  RelationalOperator: '<S552>/LowerRelop1'
   *  RelationalOperator: '<S552>/UpperRelop'
   *  Switch: '<S552>/Switch'
   */
  if (rtb_Add13_jqis > rtb_sampletime) {
    rtb_Add13_jqis = rtb_sampletime;
  } else if (rtb_Add13_jqis < rtb_Switch4_igm1) {
    /* Switch: '<S552>/Switch' */
    rtb_Add13_jqis = rtb_Switch4_igm1;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S552>/Switch2' */

  /* Sum: '<S550>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S550>/Delay Input2'
   *
   * Block description for '<S550>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S550>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add13_jqis;

  /* Switch: '<S539>/Switch3' */
  if (rtu_pass2 > 0.0) {
    /* DataTypeConversion: '<S539>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<S539>/Data Type Conversion'
     *  Switch: '<S539>/Switch3'
     */
    *rty_y_FadeOut2 = rtu_Var_BrightMaxValue;
  } else {
    /* DataTypeConversion: '<S539>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<S539>/Data Type Conversion1'
     *  Switch: '<S539>/Switch3'
     *  UnitDelay: '<S550>/Delay Input2'
     *
     * Block description for '<S550>/Delay Input2':
     *
     *  Store in Global RAM
     */
    *rty_y_FadeOut2 = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S539>/Switch3' */
}

/*
 * System initialize for function-call system:
 *    '<S526>/FadeIn3'
 *    '<S561>/FadeIn3'
 *    '<S491>/FadeIn3'
 */
void App_Model_FadeIn3_i1ka_Init(DW_FadeIn3_App_Model_bxni_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S545>/Delay Input1'
   *
   * Block description for '<S545>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S537>/Switch1' incorporates:
   *  UnitDelay: '<S537>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S526>/FadeIn3'
 *    '<S561>/FadeIn3'
 *    '<S491>/FadeIn3'
 */
void App_Model_FadeIn3_hl4u_Reset(DW_FadeIn3_App_Model_bxni_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S545>/Delay Input1'
   *
   * Block description for '<S545>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S537>/Switch1' incorporates:
   *  UnitDelay: '<S537>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S526>/FadeIn3'
 *    '<S561>/FadeIn3'
 *    '<S491>/FadeIn3'
 */
void App_Model_FadeIn3_kzku(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger3, float64 rtu_pass3, uint16 *rty_y_FadeIn3, DW_FadeIn3_App_Model_bxni_T *localDW)
{
  uint16 rtb_Switch5;

  /* Switch: '<S537>/Switch3' incorporates:
   *  DataTypeConversion: '<S537>/Data Type Conversion'
   *  Logic: '<S537>/AND'
   *  RelationalOperator: '<S545>/FixPt Relational Operator'
   *  Switch: '<S537>/Switch'
   *  Switch: '<S537>/Switch1'
   *  UnitDelay: '<S545>/Delay Input1'
   *
   * Block description for '<S545>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((float64)rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3 != 0) && (rtu_pass3 != 0.0)) {
    /* Switch: '<S537>/Switch1' incorporates:
     *  Switch: '<S537>/Switch3'
     */
    localDW->UnitDelay3_DSTATE = (float64)rtu_Var_BrightMaxValue;
  } else {
    float64 rtb_Switch_oucg;
    if (rtu_Trigger3 > 0) {
      /* Switch: '<S537>/Switch6' incorporates:
       *  Switch: '<S537>/Switch1'
       */
      if (rtu_pass3 > 0.0) {
        /* Switch: '<S537>/Switch1' incorporates:
         *  Constant: '<S537>/Constant5'
         */
        localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);
      }

      /* End of Switch: '<S537>/Switch6' */

      /* Switch: '<S537>/Switch' incorporates:
       *  Constant: '<S537>/Constant2'
       *  Product: '<S537>/Divide'
       */
      rtb_Switch_oucg = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
    } else {
      /* Switch: '<S537>/Switch1' incorporates:
       *  Constant: '<S537>/Constant3'
       *  Switch: '<S537>/Switch'
       */
      localDW->UnitDelay3_DSTATE = (float64)((uint16)0U);

      /* Switch: '<S537>/Switch' */
      rtb_Switch_oucg = localDW->UnitDelay3_DSTATE;
    }

    /* Switch: '<S537>/Switch1' incorporates:
     *  Sum: '<S537>/Add1'
     *  Switch: '<S537>/Switch3'
     */
    localDW->UnitDelay3_DSTATE += rtb_Switch_oucg;
  }

  /* End of Switch: '<S537>/Switch3' */

  /* Switch: '<S537>/Switch5' */
  if (rtu_pass3 > 0.0) {
    /* Switch: '<S537>/Switch5' incorporates:
     *  DataTypeConversion: '<S537>/Data Type Conversion'
     */
    rtb_Switch5 = rtu_Var_BrightMaxValue;
  } else {
    /* Switch: '<S537>/Switch5' incorporates:
     *  UnitDelay: '<S537>/Unit Delay3'
     */
    rtb_Switch5 = (uint16)localDW->UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S537>/Switch5' */

  /* Switch: '<S537>/Switch2' incorporates:
   *  Constant: '<S537>/Constant4'
   *  Switch: '<S546>/Switch2'
   */
  if (rtu_Trigger3 > 0) {
    /* Switch: '<S546>/Switch2' incorporates:
     *  Constant: '<S537>/Constant4'
     *  DataTypeConversion: '<S537>/Data Type Conversion'
     *  RelationalOperator: '<S546>/LowerRelop1'
     *  RelationalOperator: '<S546>/UpperRelop'
     *  Switch: '<S546>/Switch'
     */
    if (rtb_Switch5 > rtu_Var_BrightMaxValue) {
      *rty_y_FadeIn3 = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch5 < ((uint16)0U)) {
      /* Switch: '<S546>/Switch' incorporates:
       *  Constant: '<S537>/Constant4'
       */
      *rty_y_FadeIn3 = ((uint16)0U);
    } else {
      *rty_y_FadeIn3 = rtb_Switch5;
    }
  } else {
    *rty_y_FadeIn3 = ((uint16)0U);
  }

  /* End of Switch: '<S537>/Switch2' */

  /* Update for UnitDelay: '<S545>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S537>/Data Type Conversion'
   *
   * Block description for '<S545>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = (float64)rtu_Var_BrightMaxValue;
}

/*
 * System initialize for function-call system:
 *    '<S526>/FadeOut3'
 *    '<S561>/FadeOut3'
 *    '<S491>/FadeOut3'
 */
void App_Model_FadeOut3_m2ax_Init(DW_FadeOut3_App_Model_hstr_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S553>/Delay Input2'
   *
   * Block description for '<S553>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * System reset for function-call system:
 *    '<S526>/FadeOut3'
 *    '<S561>/FadeOut3'
 *    '<S491>/FadeOut3'
 */
void App_Model_FadeOut3_dv1c_Reset(DW_FadeOut3_App_Model_hstr_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S553>/Delay Input2'
   *
   * Block description for '<S553>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S526>/FadeOut3'
 *    '<S561>/FadeOut3'
 *    '<S491>/FadeOut3'
 */
void App_Model_FadeOut3_gnna_Enable(DW_FadeOut3_App_Model_hstr_T *localDW)
{
  localDW->FadeOut3_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S526>/FadeOut3'
 *    '<S561>/FadeOut3'
 *    '<S491>/FadeOut3'
 */
void App_Model_FadeOut3_n4kz(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3, const
  ConstB_FadeOut3_App_Mode_n4dx_T *localC, DW_FadeOut3_App_Model_hstr_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add13_g5ry;
  float64 rtb_Switch4_bbke;
  float64 rtb_sampletime;
  if (localDW->FadeOut3_RESET_ELAPS_T) {
    localDW->FadeOut3_ELAPS_T[0] = 0U;
    localDW->FadeOut3_ELAPS_T[1] = 0U;
  } else {
    uint32 FadeOut3_ELAPS_T_tmp;
    uint32 elapseT_H;
    FadeOut3_ELAPS_T_tmp = App_Model_M->Timing.clockTick0;
    localDW->FadeOut3_ELAPS_T[0] = FadeOut3_ELAPS_T_tmp - localDW->FadeOut3_PREV_T[0];
    elapseT_H = App_Model_M->Timing.clockTickH0 - localDW->FadeOut3_PREV_T[1];
    if (localDW->FadeOut3_PREV_T[0] > FadeOut3_ELAPS_T_tmp) {
      elapseT_H--;
    }

    localDW->FadeOut3_ELAPS_T[1] = elapseT_H;
  }

  localDW->FadeOut3_PREV_T[0] = App_Model_M->Timing.clockTick0;
  localDW->FadeOut3_PREV_T[1] = App_Model_M->Timing.clockTickH0;
  localDW->FadeOut3_RESET_ELAPS_T = false;

  /* Switch: '<S540>/Switch4' */
  if (rtu_pass3 > 0.0) {
    /* Switch: '<S540>/Switch4' incorporates:
     *  DataStoreRead: '<S540>/Data Store Read'
     *  DataTypeConversion: '<S540>/Data Type Conversion6'
     *  UnaryMinus: '<S540>/Unary Minus1'
     */
    rtb_Switch4_bbke = -((float64)Par_AutoBrightLevel091);
  } else {
    /* Switch: '<S540>/Switch4' incorporates:
     *  DataTypeConversion: '<S540>/Data Type Conversion'
     *  UnaryMinus: '<S540>/Unary Minus'
     */
    rtb_Switch4_bbke = -((float64)rtu_Var_BrightMaxValue);
  }

  /* End of Switch: '<S540>/Switch4' */
  /* Switch: '<S540>/Switch1' */
  if (rtu_Trigger3_FO > 0) {
    /* SampleTimeMath: '<S553>/sample time' incorporates:
     *  Constant: '<S540>/Constant8'
     *  Product: '<S540>/Divide2'
     *
     * About '<S553>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_sampletime = (float64)rtu_Var_BrightMaxValue / (float64)((uint16)100U);
  } else {
    /* SampleTimeMath: '<S553>/sample time' incorporates:
     *  Constant: '<S540>/Constant'
     *
     * About '<S553>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_sampletime = (float64)((uint16)0U);
  }

  /* End of Switch: '<S540>/Switch1' */

  /* Sum: '<S540>/Add13' */
  rtb_Add13_g5ry = (float64)rtu_preValue - rtb_sampletime;

  /* SampleTimeMath: '<S553>/sample time'
   *
   * About '<S553>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (((float64)localDW->FadeOut3_ELAPS_T[0] * 0.01) + ((float64)localDW->FadeOut3_ELAPS_T[1] * 4.294967296E+7)) * 1.0;

  /* Product: '<S553>/delta rise limit' incorporates:
   *  DataTypeConversion: '<S540>/Data Type Conversion'
   *  SampleTimeMath: '<S553>/sample time'
   *
   * About '<S553>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_sampletime = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S540>/Switch2' incorporates:
   *  Constant: '<S540>/Constant2'
   *  Switch: '<S540>/Switch7'
   */
  if (rtu_pass3 > 0.0) {
    rtb_Add13_g5ry = localC->DataTypeConversion5;
  } else if (rtu_Trigger3_FO > 0) {
    /* Switch: '<S554>/Switch2' incorporates:
     *  Constant: '<S540>/Constant2'
     *  RelationalOperator: '<S554>/LowerRelop1'
     *  RelationalOperator: '<S554>/UpperRelop'
     *  Switch: '<S554>/Switch'
     */
    if (rtb_Add13_g5ry > (float64)rtu_preValue) {
      /* Switch: '<S540>/Switch7' */
      rtb_Add13_g5ry = (float64)rtu_preValue;
    } else if (rtb_Add13_g5ry < (float64)((uint16)0U)) {
      /* Switch: '<S554>/Switch' incorporates:
       *  Constant: '<S540>/Constant2'
       *  Switch: '<S540>/Switch7'
       */
      rtb_Add13_g5ry = (float64)((uint16)0U);
    } else {
      /* no actions */
    }

    /* End of Switch: '<S554>/Switch2' */
  } else {
    rtb_Add13_g5ry = (float64)((uint16)0U);
  }

  /* End of Switch: '<S540>/Switch2' */

  /* Sum: '<S553>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S553>/Delay Input2'
   *
   * Block description for '<S553>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S553>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add13_g5ry -= localDW->DelayInput2_DSTATE;

  /* Product: '<S553>/delta fall limit' incorporates:
   *  SampleTimeMath: '<S553>/sample time'
   *
   * About '<S553>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch4_bbke *= elapseTime;

  /* Switch: '<S555>/Switch2' incorporates:
   *  RelationalOperator: '<S555>/LowerRelop1'
   *  RelationalOperator: '<S555>/UpperRelop'
   *  Switch: '<S555>/Switch'
   */
  if (rtb_Add13_g5ry > rtb_sampletime) {
    rtb_Add13_g5ry = rtb_sampletime;
  } else if (rtb_Add13_g5ry < rtb_Switch4_bbke) {
    /* Switch: '<S555>/Switch' */
    rtb_Add13_g5ry = rtb_Switch4_bbke;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S555>/Switch2' */

  /* Sum: '<S553>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S553>/Delay Input2'
   *
   * Block description for '<S553>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S553>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_Add13_g5ry;

  /* Switch: '<S540>/Switch3' */
  if (rtu_pass3 > 0.0) {
    /* DataTypeConversion: '<S540>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<S540>/Data Type Conversion'
     *  Switch: '<S540>/Switch3'
     */
    *rty_y_FadeOut3 = rtu_Var_BrightMaxValue;
  } else {
    /* DataTypeConversion: '<S540>/Data Type Conversion4' incorporates:
     *  DataTypeConversion: '<S540>/Data Type Conversion1'
     *  Switch: '<S540>/Switch3'
     *  UnitDelay: '<S553>/Delay Input2'
     *
     * Block description for '<S553>/Delay Input2':
     *
     *  Store in Global RAM
     */
    *rty_y_FadeOut3 = (uint16)localDW->DelayInput2_DSTATE;
  }

  /* End of Switch: '<S540>/Switch3' */
}

/* Function for Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
static void App_Model_Bright_Control1_iwev(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC, DW_Green_IND_with_Animat_pmuj_T *localDW)
{
  if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
       RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn)) {
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeIn1' */
    App_Model_FadeIn1_gjxk(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_mawl, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S526>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    localDW->pass1 = 0.0;
  } else if ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn) {
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 1.0)) {
      localDW->pass1 = 1.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 1.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeIn1' */
      App_Model_FadeIn1_gjxk(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_mawl, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S526>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_mawl;
    } else {
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeIn1' */
      App_Model_FadeIn1_gjxk(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_mawl, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S526>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_mawl;
      localB->Var_BrightMaxValue_bbx1 = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_ijju = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut1' */
      App_Model_FadeOut1_cr24(App_Model_M, localB->Var_BrightMaxValue_bbx1, localB->preValue, localB->Trigger1_FO, localB->pass1_ijju, &localB->DataTypeConversion4_lorm, &localC->FadeOut1,
        &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S526>/FadeOut1' */
      localDW->pass1 = 0.0;
    }
  } else {
    /* no actions */
  }

  if ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 2.0)) {
      localDW->pass1 = 2.0;
      localB->Var_BrightMaxValue_bbx1 = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 1;
      localB->pass1_ijju = 1.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut1' */
      App_Model_FadeOut1_cr24(App_Model_M, localB->Var_BrightMaxValue_bbx1, localB->preValue, localB->Trigger1_FO, localB->pass1_ijju, &localB->DataTypeConversion4_lorm, &localC->FadeOut1,
        &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S526>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = localB->DataTypeConversion4_lorm;
    } else {
      localB->Var_BrightMaxValue_bbx1 = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 1;
      localB->pass1_ijju = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut1' */
      App_Model_FadeOut1_cr24(App_Model_M, localB->Var_BrightMaxValue_bbx1, localB->preValue, localB->Trigger1_FO, localB->pass1_ijju, &localB->DataTypeConversion4_lorm, &localC->FadeOut1,
        &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S526>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = localB->DataTypeConversion4_lorm;
      localDW->pass1 = 0.0;
    }
  }
}

/* Function for Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
static void App_Model_Bright_Control2_ob3u(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC, DW_Green_IND_with_Animat_pmuj_T *localDW)
{
  if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
       RWPCIndCmdState__3rdChrgOn)) {
    localB->Var_BrightMaxValue_eerv = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeIn2' */
    App_Model_FadeIn2_jdzr(localB->Var_BrightMaxValue_eerv, localB->Trigger2, localB->pass2, &localB->Switch2_acm4, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S526>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    localDW->pass2 = 0.0;
  } else if ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) {
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 1.0)) {
      localDW->pass2 = 1.0;
      localB->Var_BrightMaxValue_eerv = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 1.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeIn2' */
      App_Model_FadeIn2_jdzr(localB->Var_BrightMaxValue_eerv, localB->Trigger2, localB->pass2, &localB->Switch2_acm4, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S526>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_acm4;
    } else {
      localB->Var_BrightMaxValue_eerv = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeIn2' */
      App_Model_FadeIn2_jdzr(localB->Var_BrightMaxValue_eerv, localB->Trigger2, localB->pass2, &localB->Switch2_acm4, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S526>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_acm4;
      localB->Var_BrightMaxValue_ihru = rtu_Var_BrightMaxValue;
      localB->preValue_kulh = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_pugk = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut2' */
      App_Model_FadeOut2_annl(App_Model_M, localB->Var_BrightMaxValue_ihru, localB->preValue_kulh, localB->Trigger2_FO, localB->pass2_pugk, &localB->DataTypeConversion4_idq1, &localC->FadeOut2,
        &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S526>/FadeOut2' */
      localDW->pass2 = 0.0;
    }
  } else {
    /* no actions */
  }

  if ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 2.0)) {
      localDW->pass2 = 2.0;
      localB->Var_BrightMaxValue_ihru = rtu_Var_BrightMaxValue;
      localB->preValue_kulh = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 1;
      localB->pass2_pugk = 1.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut2' */
      App_Model_FadeOut2_annl(App_Model_M, localB->Var_BrightMaxValue_ihru, localB->preValue_kulh, localB->Trigger2_FO, localB->pass2_pugk, &localB->DataTypeConversion4_idq1, &localC->FadeOut2,
        &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S526>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = localB->DataTypeConversion4_idq1;
    } else {
      localB->Var_BrightMaxValue_ihru = rtu_Var_BrightMaxValue;
      localB->preValue_kulh = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 1;
      localB->pass2_pugk = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut2' */
      App_Model_FadeOut2_annl(App_Model_M, localB->Var_BrightMaxValue_ihru, localB->preValue_kulh, localB->Trigger2_FO, localB->pass2_pugk, &localB->DataTypeConversion4_idq1, &localC->FadeOut2,
        &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S526>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = localB->DataTypeConversion4_idq1;
      localDW->pass2 = 0.0;
    }
  }
}

/* Function for Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
static void App_Model_Bright_Control3_f2e3(uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const
  App_Model_M, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC, DW_Green_IND_with_Animat_pmuj_T *localDW)
{
  switch (rtu_Input_INT_RWPCIndCmdState) {
   case RWPCIndCmdState__3rdChrgOn:
    localB->Var_BrightMaxValue_dv1t = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeIn3' */
    App_Model_FadeIn3_kzku(localB->Var_BrightMaxValue_dv1t, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S526>/FadeIn3' */
    *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
    localDW->pass3 = 0.0;
    break;

   case RWPCIndCmdState__3rdChrgFadeIn:
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 1.0)) {
      localDW->pass3 = 1.0;
      localB->Var_BrightMaxValue_dv1t = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 1;
      localB->pass3 = 1.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeIn3' */
      App_Model_FadeIn3_kzku(localB->Var_BrightMaxValue_dv1t, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S526>/FadeIn3' */
      *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
    } else {
      localB->Var_BrightMaxValue_dv1t = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 1;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeIn3' */
      App_Model_FadeIn3_kzku(localB->Var_BrightMaxValue_dv1t, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S526>/FadeIn3' */
      *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
      localB->Var_BrightMaxValue_ezuy = rtu_Var_BrightMaxValue;
      localB->preValue_mb0b = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 0;
      localB->pass3_gtdo = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut3' */
      App_Model_FadeOut3_n4kz(App_Model_M, localB->Var_BrightMaxValue_ezuy, localB->preValue_mb0b, localB->Trigger3_FO, localB->pass3_gtdo, &localB->DataTypeConversion4, &localC->FadeOut3,
        &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S526>/FadeOut3' */
      localDW->pass3 = 0.0;
    }
    break;

   default:
    /* no actions */
    break;
  }

  if ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut) {
    if ((((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 2.0)) {
      localDW->pass3 = 2.0;
      localB->Var_BrightMaxValue_ezuy = rtu_Var_BrightMaxValue;
      localB->preValue_mb0b = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 1;
      localB->pass3_gtdo = 1.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut3' */
      App_Model_FadeOut3_n4kz(App_Model_M, localB->Var_BrightMaxValue_ezuy, localB->preValue_mb0b, localB->Trigger3_FO, localB->pass3_gtdo, &localB->DataTypeConversion4, &localC->FadeOut3,
        &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S526>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = localB->DataTypeConversion4;
    } else {
      localB->Var_BrightMaxValue_ezuy = rtu_Var_BrightMaxValue;
      localB->preValue_mb0b = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 1;
      localB->pass3_gtdo = 0.0;

      /* Outputs for Function Call SubSystem: '<S526>/FadeOut3' */
      App_Model_FadeOut3_n4kz(App_Model_M, localB->Var_BrightMaxValue_ezuy, localB->preValue_mb0b, localB->Trigger3_FO, localB->pass3_gtdo, &localB->DataTypeConversion4, &localC->FadeOut3,
        &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S526>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = localB->DataTypeConversion4;
      localDW->pass3 = 0.0;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S556>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S486>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 */
void Green_IND_with_Animat_dqaz_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, DW_Green_IND_with_Animat_pmuj_T *localDW)
{
  localDW->is_active_c439_IndyOutputContro = 0U;
  localDW->pass1 = 0.0;
  localDW->pass2 = 0.0;
  localDW->pass3 = 0.0;
  *rty_Var_GreenINDwithAnimation1 = 0U;
  *rty_Var_GreenINDwithAnimation2 = 0U;
  *rty_Var_GreenINDwithAnimation3 = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S526>/FadeIn1' */
  App_Model_FadeIn1_keed_Init(&localDW->FadeIn1);

  /* End of SystemInitialize for SubSystem: '<S526>/FadeIn1' */

  /* SystemInitialize for Function Call SubSystem: '<S526>/FadeOut1' */
  App_Model_FadeOut1_c3qa_Init(&localDW->FadeOut1);

  /* End of SystemInitialize for SubSystem: '<S526>/FadeOut1' */

  /* SystemInitialize for Function Call SubSystem: '<S526>/FadeIn2' */
  App_Model_FadeIn2_kjhn_Init(&localDW->FadeIn2);

  /* End of SystemInitialize for SubSystem: '<S526>/FadeIn2' */

  /* SystemInitialize for Function Call SubSystem: '<S526>/FadeOut2' */
  App_Model_FadeOut2_mud4_Init(&localDW->FadeOut2);

  /* End of SystemInitialize for SubSystem: '<S526>/FadeOut2' */

  /* SystemInitialize for Function Call SubSystem: '<S526>/FadeIn3' */
  App_Model_FadeIn3_i1ka_Init(&localDW->FadeIn3);

  /* End of SystemInitialize for SubSystem: '<S526>/FadeIn3' */

  /* SystemInitialize for Function Call SubSystem: '<S526>/FadeOut3' */
  App_Model_FadeOut3_m2ax_Init(&localDW->FadeOut3);

  /* End of SystemInitialize for SubSystem: '<S526>/FadeOut3' */
}

/*
 * Enable for atomic system:
 *    '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S556>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S486>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 */
void Green_IND_with_Anim_cp3n_Enable(DW_Green_IND_with_Animat_pmuj_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S526>/FadeIn1' */
  App_Model_FadeIn1_ed0b_Reset(&localDW->FadeIn1);

  /* End of SystemReset for SubSystem: '<S526>/FadeIn1' */

  /* SystemReset for Function Call SubSystem: '<S526>/FadeOut1' */
  App_Model_FadeOut1_lxyd_Reset(&localDW->FadeOut1);

  /* End of SystemReset for SubSystem: '<S526>/FadeOut1' */

  /* Enable for Function Call SubSystem: '<S526>/FadeOut1' */
  App_Model_FadeOut1_e32b_Enable(&localDW->FadeOut1);

  /* End of Enable for SubSystem: '<S526>/FadeOut1' */

  /* SystemReset for Function Call SubSystem: '<S526>/FadeIn2' */
  App_Model_FadeIn2_d1tk_Reset(&localDW->FadeIn2);

  /* End of SystemReset for SubSystem: '<S526>/FadeIn2' */

  /* SystemReset for Function Call SubSystem: '<S526>/FadeOut2' */
  App_Model_FadeOut2_jnvs_Reset(&localDW->FadeOut2);

  /* End of SystemReset for SubSystem: '<S526>/FadeOut2' */

  /* Enable for Function Call SubSystem: '<S526>/FadeOut2' */
  App_Model_FadeOut2_lnni_Enable(&localDW->FadeOut2);

  /* End of Enable for SubSystem: '<S526>/FadeOut2' */

  /* SystemReset for Function Call SubSystem: '<S526>/FadeIn3' */
  App_Model_FadeIn3_hl4u_Reset(&localDW->FadeIn3);

  /* End of SystemReset for SubSystem: '<S526>/FadeIn3' */

  /* SystemReset for Function Call SubSystem: '<S526>/FadeOut3' */
  App_Model_FadeOut3_dv1c_Reset(&localDW->FadeOut3);

  /* End of SystemReset for SubSystem: '<S526>/FadeOut3' */

  /* Enable for Function Call SubSystem: '<S526>/FadeOut3' */
  App_Model_FadeOut3_gnna_Enable(&localDW->FadeOut3);

  /* End of Enable for SubSystem: '<S526>/FadeOut3' */
}

/*
 * Output and update for atomic system:
 *    '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S556>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 *    '<S486>/Green_IND_with_Animation_Control_Function_Flow_Graph'
 */
void Green_IND_with_Animation_C_j0ur(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T *localC,
  DW_Green_IND_with_Animat_pmuj_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c439_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c439_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeIn1' */
    App_Model_FadeIn1_gjxk(localB->Var_BrightMaxValue, localB->Trigger1, localB->pass1, &localB->Switch2_mawl, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S526>/FadeIn1' */
    localB->Var_BrightMaxValue_bbx1 = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_GreenINDwithAnimation1;
    localB->Trigger1_FO = 0;
    localB->pass1_ijju = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeOut1' */
    App_Model_FadeOut1_cr24(App_Model_M, localB->Var_BrightMaxValue_bbx1, localB->preValue, localB->Trigger1_FO, localB->pass1_ijju, &localB->DataTypeConversion4_lorm, &localC->FadeOut1,
      &localDW->FadeOut1);

    /* End of Outputs for SubSystem: '<S526>/FadeOut1' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /* 1. In the case of 1st LED */
    if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
         RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut)) {
      App_Model_Bright_Control1_iwev(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localC, localDW);

      /* 2. In the case of 1st LED, Abnormal */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_eerv = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeIn2' */
    App_Model_FadeIn2_jdzr(localB->Var_BrightMaxValue_eerv, localB->Trigger2, localB->pass2, &localB->Switch2_acm4, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S526>/FadeIn2' */
    localB->Var_BrightMaxValue_ihru = rtu_Var_BrightMaxValue;
    localB->preValue_kulh = *rty_Var_GreenINDwithAnimation2;
    localB->Trigger2_FO = 0;
    localB->pass2_pugk = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeOut2' */
    App_Model_FadeOut2_annl(App_Model_M, localB->Var_BrightMaxValue_ihru, localB->preValue_kulh, localB->Trigger2_FO, localB->pass2_pugk, &localB->DataTypeConversion4_idq1, &localC->FadeOut2,
      &localDW->FadeOut2);

    /* End of Outputs for SubSystem: '<S526>/FadeOut2' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /* 1. In the case of 2nd LED */
    if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
         RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut)) {
      App_Model_Bright_Control2_ob3u(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localC, localDW);

      /* 2. In the case of 2nd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_dv1t = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeIn3' */
    App_Model_FadeIn3_kzku(localB->Var_BrightMaxValue_dv1t, localB->Trigger3, localB->pass3, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S526>/FadeIn3' */
    localB->Var_BrightMaxValue_ezuy = rtu_Var_BrightMaxValue;
    localB->preValue_mb0b = *rty_Var_GreenINDwithAnimation3;
    localB->Trigger3_FO = 0;
    localB->pass3_gtdo = 0.0;

    /* Outputs for Function Call SubSystem: '<S526>/FadeOut3' */
    App_Model_FadeOut3_n4kz(App_Model_M, localB->Var_BrightMaxValue_ezuy, localB->preValue_mb0b, localB->Trigger3_FO, localB->pass3_gtdo, &localB->DataTypeConversion4, &localC->FadeOut3,
      &localDW->FadeOut3);

    /* End of Outputs for SubSystem: '<S526>/FadeOut3' */
    if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }

    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
         RWPCIndCmdState__ChrgFadeOut)) {
      App_Model_Bright_Control3_f2e3(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localC, localDW);

      /* 2. In the case of 3rd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1. In the case of 1st LED */
    if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
         RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn) || ((uint32)
         rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut)) {
      App_Model_Bright_Control1_iwev(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localC, localDW);

      /* 2. In the case of 1st LED, Abnormal */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation1 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation1 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation1 = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 2nd LED */
    if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
         RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__ChrgFadeOut)) {
      App_Model_Bright_Control2_ob3u(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localC, localDW);

      /* 2. In the case of 2nd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation2 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation2 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation2 = MAX_uint16_T;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if (((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_Input_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_Input_INT_RWPCIndCmdState ==
         RWPCIndCmdState__ChrgFadeOut)) {
      App_Model_Bright_Control3_f2e3(rtu_Var_BrightMaxValue, rtu_Input_INT_RWPCIndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localC, localDW);

      /* 2. In the case of 3rd LED Off */
    } else if (0.0 < 65536.0) {
      if (0.0 >= 0.0) {
        *rty_Var_GreenINDwithAnimation3 = (uint16)0.0;
      } else {
        *rty_Var_GreenINDwithAnimation3 = 0U;
      }
    } else {
      *rty_Var_GreenINDwithAnimation3 = MAX_uint16_T;
    }
  }

  /* End of Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
}

/* System initialize for atomic system: '<S462>/IndyOutputControl_Function' */
void IndyOutputControl_Fun_g554_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_e2b1, uint16 *rty_IndyOutput_Sig_czfa, uint16 *rty_IndyOutput_Sig_a1tj)
{
  /* local block i/o variables */
  uint16 rtb_Var_GreenIND_ier0;
  uint16 rtb_Var_AmberIND_ephh;
  uint16 rtb_Var_GreenIND_idpa;
  uint16 rtb_Var_AmberIND_adpn;
  uint16 rtb_Var_GreenIND_ivag;
  uint16 rtb_Var_AmberIND_ckco;

  /* Start for SwitchCase: '<S468>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_nijk = -1;

  /* SystemInitialize for IfAction SubSystem: '<S468>/RheoStatIndyOutputControl_Type1' */
  /* SystemInitialize for Chart: '<S521>/RWPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue_iq1i, &App_Model_DW.sf_RWPC_IND_Output_Control_Func);

  /* SystemInitialize for Chart: '<S521>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_Init(&App_Model_B.Var_BrightMaxValue_oq2v, &App_Model_DW.sf_Bright_Max_Value_Contro_lish);

  /* SystemInitialize for Chart: '<S521>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_ivag, &App_Model_DW.sf_Green_IND_Control_Funct_olhn);

  /* SystemInitialize for Chart: '<S521>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_ckco, &App_Model_DW.sf_Amber_IND_Control_Funct_j25s);

  /* SystemInitialize for Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  Green_IND_with_Animat_dqaz_Init(&App_Model_B.Var_GreenINDwithAnimation1_eax3, &App_Model_B.Var_GreenINDwithAnimation2_aupy, &App_Model_B.Var_GreenINDwithAnimation3_b1o4,
    &App_Model_DW.sf_Green_IND_with_Animatio_j0ur);

  /* SystemInitialize for Chart: '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  Amber_IND_with_Animat_crfg_Init(&App_Model_B.Var_AmberINDwithAnimation_beel, &App_Model_DW.sf_Amber_IND_with_Animatio_lyja);

  /* SystemInitialize for Chart: '<S521>/IND_Output_Control_Function_Flow_Graph' */
  App_Model_DW.is_active_c440_IndyOutputContro = 0U;

  /* End of SystemInitialize for SubSystem: '<S468>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for IfAction SubSystem: '<S468>/RheoStatIndyOutputControl_Type2' */
  /* SystemInitialize for Chart: '<S556>/RWPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue, &App_Model_DW.sf_RWPC_IND_Output_Control_hkex);

  /* SystemInitialize for Chart: '<S556>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Cont_abam_Init(&App_Model_B.Var_BrightMaxValue_cvbp, &App_Model_DW.sf_Bright_Max_Value_Contro_khg4);

  /* SystemInitialize for Chart: '<S556>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_idpa, &App_Model_DW.sf_Green_IND_Control_Funct_apml);

  /* SystemInitialize for Chart: '<S556>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_adpn, &App_Model_DW.sf_Amber_IND_Control_Funct_pa3s);

  /* SystemInitialize for Chart: '<S556>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  Green_IND_with_Animat_dqaz_Init(&App_Model_B.Var_GreenINDwithAnimation1_aldj, &App_Model_B.Var_GreenINDwithAnimation2_maqt, &App_Model_B.Var_GreenINDwithAnimation3_l2c4,
    &App_Model_DW.sf_Green_IND_with_Animatio_fvsz);

  /* SystemInitialize for Chart: '<S556>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  Amber_IND_with_Animat_crfg_Init(&App_Model_B.Var_AmberINDwithAnimation_fe5d, &App_Model_DW.sf_Amber_IND_with_Animatio_fpng);

  /* SystemInitialize for Chart: '<S556>/IND_Output_Control_Function_Flow_Graph' */
  App_Model_DW.is_active_c447_IndyOutputContro = 0U;

  /* End of SystemInitialize for SubSystem: '<S468>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for IfAction SubSystem: '<S468>/AutoBrightIndyOutputControl_Type3' */
  /* SystemInitialize for Chart: '<S486>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  WPC_IND_Output_With_Auto_B_Init(&App_Model_B.AutoBrightValue, &App_Model_DW.sf_WPC_IND_Output_With_Aut_ntnc);

  /* SystemInitialize for Chart: '<S486>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Cont_issq_Init(&App_Model_B.Var_BrightMaxValue, &App_Model_DW.sf_Bright_Max_Value_Contro_ejc2);

  /* SystemInitialize for Chart: '<S486>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_ier0, &App_Model_DW.sf_Green_IND_Control_Funct_jrgr);

  /* SystemInitialize for Chart: '<S486>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_ephh, &App_Model_DW.sf_Amber_IND_Control_Funct_db4r);

  /* SystemInitialize for Chart: '<S486>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  Green_IND_with_Animat_dqaz_Init(&App_Model_B.Var_GreenINDwithAnimation1, &App_Model_B.Var_GreenINDwithAnimation2, &App_Model_B.Var_GreenINDwithAnimation3,
    &App_Model_DW.sf_Green_IND_with_Animatio_kxvh);

  /* SystemInitialize for Chart: '<S486>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  Amber_IND_with_Animat_crfg_Init(&App_Model_B.Var_AmberINDwithAnimation, &App_Model_DW.sf_Amber_IND_with_Animatio_lfg4);

  /* SystemInitialize for Chart: '<S486>/IND_Output_Control_Function_Flow_Graph' */
  App_Model_DW.is_active_c259_IndyOutputContro = 0U;

  /* End of SystemInitialize for SubSystem: '<S468>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Merge generated from: '<S468>/Merge' */
  *rty_IndyOutput_Sig = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S468>/Merge' */
  *rty_IndyOutput_Sig_e2b1 = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S468>/Merge' */
  *rty_IndyOutput_Sig_czfa = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S468>/Merge' */
  *rty_IndyOutput_Sig_a1tj = ((uint16)0U);
}

/* Disable for atomic system: '<S462>/IndyOutputControl_Function' */
void IndyOutputControl__n4jw_Disable(void)
{
  /* Disable for SwitchCase: '<S468>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_nijk = -1;
}

/* Output and update for atomic system: '<S462>/IndyOutputControl_Function' */
void IndyOutputControl_Function_bnu5(INDContType rtu_PostProcessIn, RWPCIndCmdState rtu_PostProcessIn_e2b1, C_WPCWarning rtu_PostProcessIn_czfa, WPCIndUSMState rtu_PostProcessIn_a1tj, Bool
  rtu_PostProcessIn_jr04, Bool rtu_PostProcessIn_ec5f, Bool rtu_PostProcessIn_jvxw, RheostatOption rtu_PostProcessIn_fhfw, Bool rtu_PostProcessIn_ijyl, Bool rtu_PostProcessIn_mall, C_RheoStatLevel
  rtu_PostProcessIn_muku, C_AutoBrightLevel rtu_PostProcessIn_js3h, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_e2b1, uint16 *rty_IndyOutput_Sig_czfa, uint16 *rty_IndyOutput_Sig_a1tj)
{
  /* local block i/o variables */
  uint16 rtb_Var_GreenIND_ier0;
  uint16 rtb_Var_AmberIND_ephh;
  uint16 rtb_Var_GreenIND_idpa;
  uint16 rtb_Var_AmberIND_adpn;
  uint16 rtb_Var_GreenIND_ivag;
  uint16 rtb_Var_AmberIND_ckco;
  sint8 rtPrevAction;

  /* SwitchCase: '<S468>/Switch Case' */
  rtPrevAction = App_Model_DW.SwitchCase_ActiveSubsystem_nijk;
  App_Model_DW.SwitchCase_ActiveSubsystem_nijk = -1;
  switch (rtu_PostProcessIn) {
   case INDConType1:
    App_Model_DW.SwitchCase_ActiveSubsystem_nijk = 0;
    break;

   case INDConType2:
    App_Model_DW.SwitchCase_ActiveSubsystem_nijk = 1;
    break;

   case INDConType3:
    App_Model_DW.SwitchCase_ActiveSubsystem_nijk = 2;
    break;

   default:
    /* no actions */
    break;
  }

  switch (App_Model_DW.SwitchCase_ActiveSubsystem_nijk) {
   case 0:
    {
      uint16 rtb_Output_AmberIND_OUT;
      uint16 rtb_Output_GreenIND2_OUT;
      uint16 rtb_Output_GreenIND3_OUT;
      uint16 rtb_Output_GreenIND_OUT;
      if (App_Model_DW.SwitchCase_ActiveSubsystem_nijk != rtPrevAction) {
        /* Enable for IfAction SubSystem: '<S468>/RheoStatIndyOutputControl_Type1' incorporates:
         *  ActionPort: '<S484>/ActionPort'
         */
        /* Enable for SwitchCase: '<S468>/Switch Case' incorporates:
         *  Chart: '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
         *  Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph'
         */
        Green_IND_with_Anim_cp3n_Enable(&App_Model_DW.sf_Green_IND_with_Animatio_j0ur);
        Amber_IND_with_Anim_ddyk_Enable(&App_Model_DW.sf_Amber_IND_with_Animatio_lyja);

        /* End of Enable for SubSystem: '<S468>/RheoStatIndyOutputControl_Type1' */
      }

      /* Outputs for IfAction SubSystem: '<S468>/RheoStatIndyOutputControl_Type1' incorporates:
       *  ActionPort: '<S484>/ActionPort'
       */
      /* Chart: '<S521>/RWPC_IND_Output_Control_Function' */
      WPC_IND_Output_Control_Function(rtu_PostProcessIn_muku, &App_Model_B.RheoLevelValue_iq1i, &App_Model_DW.sf_RWPC_IND_Output_Control_Func);

      /* Chart: '<S521>/Bright_Max_Value_Control_Function_Flow_Graph' */
      Bright_Max_Value_Control_Functi(rtu_PostProcessIn_jvxw, rtu_PostProcessIn_fhfw, rtu_PostProcessIn_ijyl, App_Model_B.RheoLevelValue_iq1i, &App_Model_B.Var_BrightMaxValue_oq2v,
        &App_Model_DW.sf_Bright_Max_Value_Contro_lish);

      /* Chart: '<S521>/Green_IND_Control_Function_Flow_Graph' */
      Green_IND_Control_Function_Flow(rtu_PostProcessIn_mall, App_Model_B.Var_BrightMaxValue_oq2v, &rtb_Var_GreenIND_ivag, &App_Model_DW.sf_Green_IND_Control_Funct_olhn);

      /* Chart: '<S521>/Amber_IND_Control_Function_Flow_Graph' */
      Amber_IND_Control_Function_Flow(rtu_PostProcessIn_jr04, App_Model_B.Var_BrightMaxValue_oq2v, &rtb_Var_AmberIND_ckco, &App_Model_DW.sf_Amber_IND_Control_Funct_j25s);

      /* Chart: '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
      Green_IND_with_Animation_C_j0ur(App_Model_M, App_Model_B.Var_BrightMaxValue_oq2v, rtu_PostProcessIn_e2b1, &App_Model_B.Var_GreenINDwithAnimation1_eax3,
        &App_Model_B.Var_GreenINDwithAnimation2_aupy, &App_Model_B.Var_GreenINDwithAnimation3_b1o4, &App_Model_B.sf_Green_IND_with_Animatio_j0ur, &App_Model_ConstB.sf_Green_IND_with_Animatio_j0ur,
        &App_Model_DW.sf_Green_IND_with_Animatio_j0ur);

      /* Chart: '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
      Amber_IND_with_Animation_C_lyja(App_Model_B.Var_BrightMaxValue_oq2v, rtu_PostProcessIn_ec5f, rtu_PostProcessIn_e2b1, &App_Model_B.Var_AmberINDwithAnimation_beel,
        &App_Model_B.sf_Amber_IND_with_Animatio_lyja, &App_Model_DW.sf_Amber_IND_with_Animatio_lyja);

      /* Chart: '<S521>/IND_Output_Control_Function_Flow_Graph' */
      if ((uint32)App_Model_DW.is_active_c440_IndyOutputContro == 0U) {
        App_Model_DW.is_active_c440_IndyOutputContro = 1U;

        /*  Transition run once at reset */
        /* Ref_Off */
        /* 1 */
        if ((uint32)rtu_PostProcessIn_a1tj == WPCIndUSMState__Type2) {
          if ((uint32)rtu_PostProcessIn_czfa == Charging_Complete) {
            rtb_Output_GreenIND_OUT = App_Model_B.Var_BrightMaxValue_oq2v;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_BrightMaxValue_oq2v;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_BrightMaxValue_oq2v;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__Default) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgFadeIn) ||
                     ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgFadeOut)) {
            /* Green IND Light */
            rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1_eax3;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2_aupy;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3_b1o4;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__ErrorFadeOut)) {
            /* Amber IND light */
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_GreenIND_OUT = (uint16)0.0;
                rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
                rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              } else {
                rtb_Output_GreenIND_OUT = 0U;
                rtb_Output_GreenIND2_OUT = 0U;
                rtb_Output_GreenIND3_OUT = 0U;
              }
            } else {
              rtb_Output_GreenIND_OUT = MAX_uint16_T;
              rtb_Output_GreenIND2_OUT = MAX_uint16_T;
              rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            }

            rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation_beel;
          } else if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            rtb_Output_AmberIND_OUT = MAX_uint16_T;

            /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
               Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
          }
        } else {
          rtb_Output_GreenIND_OUT = rtb_Var_GreenIND_ivag;
          rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND_ivag;
          rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND_ivag;
          rtb_Output_AmberIND_OUT = rtb_Var_AmberIND_ckco;
        }

        /*  Transition run every task on system operation */
        /* 1 */
      } else if ((uint32)rtu_PostProcessIn_a1tj == WPCIndUSMState__Type2) {
        if ((uint32)rtu_PostProcessIn_czfa == Charging_Complete) {
          rtb_Output_GreenIND_OUT = App_Model_B.Var_BrightMaxValue_oq2v;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_BrightMaxValue_oq2v;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_BrightMaxValue_oq2v;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__Default) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)
                    rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgFadeOut)) {
          /* Green IND Light */
          rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1_eax3;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2_aupy;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3_b1o4;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__ErrorFadeOut)) {
          /* Amber IND light */
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          }

          rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation_beel;
        } else if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            rtb_Output_GreenIND_OUT = (uint16)0.0;
            rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
          } else {
            rtb_Output_GreenIND_OUT = 0U;
            rtb_Output_GreenIND2_OUT = 0U;
            rtb_Output_GreenIND3_OUT = 0U;
            rtb_Output_AmberIND_OUT = 0U;
          }
        } else {
          rtb_Output_GreenIND_OUT = MAX_uint16_T;
          rtb_Output_GreenIND2_OUT = MAX_uint16_T;
          rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          rtb_Output_AmberIND_OUT = MAX_uint16_T;

          /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
             Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
        }
      } else {
        rtb_Output_GreenIND_OUT = rtb_Var_GreenIND_ivag;
        rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND_ivag;
        rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND_ivag;
        rtb_Output_AmberIND_OUT = rtb_Var_AmberIND_ckco;
      }

      /* End of Chart: '<S521>/IND_Output_Control_Function_Flow_Graph' */

      /* SignalConversion generated from: '<S484>/P_AmberIND_OUT' */
      *rty_IndyOutput_Sig_a1tj = rtb_Output_AmberIND_OUT;

      /* SignalConversion generated from: '<S484>/P_GreenIND2_OUT' */
      *rty_IndyOutput_Sig_e2b1 = rtb_Output_GreenIND2_OUT;

      /* SignalConversion generated from: '<S484>/P_GreenIND3_OUT' */
      *rty_IndyOutput_Sig_czfa = rtb_Output_GreenIND3_OUT;

      /* SignalConversion generated from: '<S484>/P_GreenIND_OUT' */
      *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT;

      /* End of Outputs for SubSystem: '<S468>/RheoStatIndyOutputControl_Type1' */
    }
    break;

   case 1:
    {
      uint16 rtb_Output_AmberIND_OUT;
      uint16 rtb_Output_GreenIND2_OUT;
      uint16 rtb_Output_GreenIND3_OUT;
      uint16 rtb_Output_GreenIND_OUT;
      if (App_Model_DW.SwitchCase_ActiveSubsystem_nijk != rtPrevAction) {
        /* Enable for IfAction SubSystem: '<S468>/RheoStatIndyOutputControl_Type2' incorporates:
         *  ActionPort: '<S485>/ActionPort'
         */
        /* Enable for SwitchCase: '<S468>/Switch Case' incorporates:
         *  Chart: '<S556>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
         *  Chart: '<S556>/Green_IND_with_Animation_Control_Function_Flow_Graph'
         */
        Green_IND_with_Anim_cp3n_Enable(&App_Model_DW.sf_Green_IND_with_Animatio_fvsz);
        Amber_IND_with_Anim_ddyk_Enable(&App_Model_DW.sf_Amber_IND_with_Animatio_fpng);

        /* End of Enable for SubSystem: '<S468>/RheoStatIndyOutputControl_Type2' */
      }

      /* Outputs for IfAction SubSystem: '<S468>/RheoStatIndyOutputControl_Type2' incorporates:
       *  ActionPort: '<S485>/ActionPort'
       */
      /* Chart: '<S556>/RWPC_IND_Output_Control_Function' */
      WPC_IND_Output_Control_Function(rtu_PostProcessIn_muku, &App_Model_B.RheoLevelValue, &App_Model_DW.sf_RWPC_IND_Output_Control_hkex);

      /* Chart: '<S556>/Bright_Max_Value_Control_Function_Flow_Graph' */
      Bright_Max_Value_Control_F_bk5u(rtu_PostProcessIn_fhfw, rtu_PostProcessIn_ijyl, App_Model_B.RheoLevelValue, &App_Model_B.Var_BrightMaxValue_cvbp, &App_Model_DW.sf_Bright_Max_Value_Contro_khg4);

      /* Chart: '<S556>/Green_IND_Control_Function_Flow_Graph' */
      Green_IND_Control_Function_Flow(rtu_PostProcessIn_mall, App_Model_B.Var_BrightMaxValue_cvbp, &rtb_Var_GreenIND_idpa, &App_Model_DW.sf_Green_IND_Control_Funct_apml);

      /* Chart: '<S556>/Amber_IND_Control_Function_Flow_Graph' */
      Amber_IND_Control_Function_Flow(rtu_PostProcessIn_jr04, App_Model_B.Var_BrightMaxValue_cvbp, &rtb_Var_AmberIND_adpn, &App_Model_DW.sf_Amber_IND_Control_Funct_pa3s);

      /* Chart: '<S556>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
      Green_IND_with_Animation_C_j0ur(App_Model_M, App_Model_B.Var_BrightMaxValue_cvbp, rtu_PostProcessIn_e2b1, &App_Model_B.Var_GreenINDwithAnimation1_aldj,
        &App_Model_B.Var_GreenINDwithAnimation2_maqt, &App_Model_B.Var_GreenINDwithAnimation3_l2c4, &App_Model_B.sf_Green_IND_with_Animatio_fvsz, &App_Model_ConstB.sf_Green_IND_with_Animatio_fvsz,
        &App_Model_DW.sf_Green_IND_with_Animatio_fvsz);

      /* Chart: '<S556>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
      Amber_IND_with_Animation_C_lyja(App_Model_B.Var_BrightMaxValue_cvbp, rtu_PostProcessIn_ec5f, rtu_PostProcessIn_e2b1, &App_Model_B.Var_AmberINDwithAnimation_fe5d,
        &App_Model_B.sf_Amber_IND_with_Animatio_fpng, &App_Model_DW.sf_Amber_IND_with_Animatio_fpng);

      /* Chart: '<S556>/IND_Output_Control_Function_Flow_Graph' */
      if ((uint32)App_Model_DW.is_active_c447_IndyOutputContro == 0U) {
        App_Model_DW.is_active_c447_IndyOutputContro = 1U;

        /*  Transition run once at reset */
        /* Ref_Off */
        /* 1 */
        if ((uint32)rtu_PostProcessIn_a1tj == WPCIndUSMState__Type2) {
          if ((uint32)rtu_PostProcessIn_czfa == Charging_Complete) {
            rtb_Output_GreenIND_OUT = App_Model_B.Var_BrightMaxValue_cvbp;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_BrightMaxValue_cvbp;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_BrightMaxValue_cvbp;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__Default) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgFadeIn) ||
                     ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgFadeOut)) {
            /* Green IND Light */
            rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1_aldj;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2_maqt;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3_l2c4;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__ErrorFadeOut)) {
            /* Amber IND light */
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_GreenIND_OUT = (uint16)0.0;
                rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
                rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              } else {
                rtb_Output_GreenIND_OUT = 0U;
                rtb_Output_GreenIND2_OUT = 0U;
                rtb_Output_GreenIND3_OUT = 0U;
              }
            } else {
              rtb_Output_GreenIND_OUT = MAX_uint16_T;
              rtb_Output_GreenIND2_OUT = MAX_uint16_T;
              rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            }

            rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation_fe5d;
          } else if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            rtb_Output_AmberIND_OUT = MAX_uint16_T;

            /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
               Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
          }
        } else {
          rtb_Output_GreenIND_OUT = rtb_Var_GreenIND_idpa;
          rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND_idpa;
          rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND_idpa;
          rtb_Output_AmberIND_OUT = rtb_Var_AmberIND_adpn;
        }

        /*  Transition run every task on system operation */
        /* 1 */
      } else if ((uint32)rtu_PostProcessIn_a1tj == WPCIndUSMState__Type2) {
        if ((uint32)rtu_PostProcessIn_czfa == Charging_Complete) {
          rtb_Output_GreenIND_OUT = App_Model_B.Var_BrightMaxValue_cvbp;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_BrightMaxValue_cvbp;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_BrightMaxValue_cvbp;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__Default) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)
                    rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgFadeOut)) {
          /* Green IND Light */
          rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1_aldj;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2_maqt;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3_l2c4;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__ErrorFadeOut)) {
          /* Amber IND light */
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          }

          rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation_fe5d;
        } else if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            rtb_Output_GreenIND_OUT = (uint16)0.0;
            rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
          } else {
            rtb_Output_GreenIND_OUT = 0U;
            rtb_Output_GreenIND2_OUT = 0U;
            rtb_Output_GreenIND3_OUT = 0U;
            rtb_Output_AmberIND_OUT = 0U;
          }
        } else {
          rtb_Output_GreenIND_OUT = MAX_uint16_T;
          rtb_Output_GreenIND2_OUT = MAX_uint16_T;
          rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          rtb_Output_AmberIND_OUT = MAX_uint16_T;

          /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
             Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
        }
      } else {
        rtb_Output_GreenIND_OUT = rtb_Var_GreenIND_idpa;
        rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND_idpa;
        rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND_idpa;
        rtb_Output_AmberIND_OUT = rtb_Var_AmberIND_adpn;
      }

      /* End of Chart: '<S556>/IND_Output_Control_Function_Flow_Graph' */

      /* SignalConversion generated from: '<S485>/P_AmberIND_OUT' */
      *rty_IndyOutput_Sig_a1tj = rtb_Output_AmberIND_OUT;

      /* SignalConversion generated from: '<S485>/P_GreenIND2_OUT' */
      *rty_IndyOutput_Sig_e2b1 = rtb_Output_GreenIND2_OUT;

      /* SignalConversion generated from: '<S485>/P_GreenIND3_OUT' */
      *rty_IndyOutput_Sig_czfa = rtb_Output_GreenIND3_OUT;

      /* SignalConversion generated from: '<S485>/P_GreenIND_OUT' */
      *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT;

      /* End of Outputs for SubSystem: '<S468>/RheoStatIndyOutputControl_Type2' */
    }
    break;

   case 2:
    {
      uint16 rtb_Output_AmberIND_OUT;
      uint16 rtb_Output_GreenIND2_OUT;
      uint16 rtb_Output_GreenIND3_OUT;
      uint16 rtb_Output_GreenIND_OUT;
      if (App_Model_DW.SwitchCase_ActiveSubsystem_nijk != rtPrevAction) {
        /* Enable for IfAction SubSystem: '<S468>/AutoBrightIndyOutputControl_Type3' incorporates:
         *  ActionPort: '<S483>/ActionPort'
         */
        /* Enable for SwitchCase: '<S468>/Switch Case' incorporates:
         *  Chart: '<S486>/Amber_IND_with_Animation_Control_Function_Flow_Graph'
         *  Chart: '<S486>/Green_IND_with_Animation_Control_Function_Flow_Graph'
         */
        Green_IND_with_Anim_cp3n_Enable(&App_Model_DW.sf_Green_IND_with_Animatio_kxvh);
        Amber_IND_with_Anim_ddyk_Enable(&App_Model_DW.sf_Amber_IND_with_Animatio_lfg4);

        /* End of Enable for SubSystem: '<S468>/AutoBrightIndyOutputControl_Type3' */
      }

      /* Outputs for IfAction SubSystem: '<S468>/AutoBrightIndyOutputControl_Type3' incorporates:
       *  ActionPort: '<S483>/ActionPort'
       */
      /* Chart: '<S486>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
      WPC_IND_Output_With_Auto_Bright(rtu_PostProcessIn_js3h, &App_Model_B.AutoBrightValue, &App_Model_DW.sf_WPC_IND_Output_With_Aut_ntnc);

      /* Chart: '<S486>/Bright_Max_Value_Control_Function_Flow_Graph' */
      Bright_Max_Value_Control_F_nqis(rtu_PostProcessIn_jvxw, App_Model_B.AutoBrightValue, &App_Model_B.Var_BrightMaxValue, &App_Model_DW.sf_Bright_Max_Value_Contro_ejc2);

      /* Chart: '<S486>/Green_IND_Control_Function_Flow_Graph' */
      Green_IND_Control_Function_Flow(rtu_PostProcessIn_mall, App_Model_B.Var_BrightMaxValue, &rtb_Var_GreenIND_ier0, &App_Model_DW.sf_Green_IND_Control_Funct_jrgr);

      /* Chart: '<S486>/Amber_IND_Control_Function_Flow_Graph' */
      Amber_IND_Control_Function_Flow(rtu_PostProcessIn_jr04, App_Model_B.Var_BrightMaxValue, &rtb_Var_AmberIND_ephh, &App_Model_DW.sf_Amber_IND_Control_Funct_db4r);

      /* Chart: '<S486>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
      Green_IND_with_Animation_C_j0ur(App_Model_M, App_Model_B.Var_BrightMaxValue, rtu_PostProcessIn_e2b1, &App_Model_B.Var_GreenINDwithAnimation1, &App_Model_B.Var_GreenINDwithAnimation2,
        &App_Model_B.Var_GreenINDwithAnimation3, &App_Model_B.sf_Green_IND_with_Animatio_kxvh, &App_Model_ConstB.sf_Green_IND_with_Animatio_kxvh, &App_Model_DW.sf_Green_IND_with_Animatio_kxvh);

      /* Chart: '<S486>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
      Amber_IND_with_Animation_C_lyja(App_Model_B.Var_BrightMaxValue, rtu_PostProcessIn_ec5f, rtu_PostProcessIn_e2b1, &App_Model_B.Var_AmberINDwithAnimation,
        &App_Model_B.sf_Amber_IND_with_Animatio_lfg4, &App_Model_DW.sf_Amber_IND_with_Animatio_lfg4);

      /* Chart: '<S486>/IND_Output_Control_Function_Flow_Graph' */
      if ((uint32)App_Model_DW.is_active_c259_IndyOutputContro == 0U) {
        App_Model_DW.is_active_c259_IndyOutputContro = 1U;

        /*  Transition run once at reset */
        /* Ref_Off */
        /* 1 */
        if ((uint32)rtu_PostProcessIn_a1tj == WPCIndUSMState__Type2) {
          if ((uint32)rtu_PostProcessIn_czfa == Charging_Complete) {
            rtb_Output_GreenIND_OUT = App_Model_B.Var_BrightMaxValue;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_BrightMaxValue;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_BrightMaxValue;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__Default) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgFadeIn) ||
                     ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgFadeOut)) {
            /* Green IND Light */
            rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1;
            rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2;
            rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3;
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_AmberIND_OUT = (uint16)0.0;
              } else {
                rtb_Output_AmberIND_OUT = 0U;
              }
            } else {
              rtb_Output_AmberIND_OUT = MAX_uint16_T;
            }
          } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                      RWPCIndCmdState__ErrorFadeOut)) {
            /* Amber IND light */
            if (0.0 < 65536.0) {
              if (0.0 >= 0.0) {
                rtb_Output_GreenIND_OUT = (uint16)0.0;
                rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
                rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              } else {
                rtb_Output_GreenIND_OUT = 0U;
                rtb_Output_GreenIND2_OUT = 0U;
                rtb_Output_GreenIND3_OUT = 0U;
              }
            } else {
              rtb_Output_GreenIND_OUT = MAX_uint16_T;
              rtb_Output_GreenIND2_OUT = MAX_uint16_T;
              rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            }

            rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation;
          } else if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
            rtb_Output_AmberIND_OUT = MAX_uint16_T;

            /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
               Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
          }
        } else {
          rtb_Output_GreenIND_OUT = rtb_Var_GreenIND_ier0;
          rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND_ier0;
          rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND_ier0;
          rtb_Output_AmberIND_OUT = rtb_Var_AmberIND_ephh;
        }

        /*  Transition run every task on system operation */
        /* 1 */
      } else if ((uint32)rtu_PostProcessIn_a1tj == WPCIndUSMState__Type2) {
        if ((uint32)rtu_PostProcessIn_czfa == Charging_Complete) {
          rtb_Output_GreenIND_OUT = App_Model_B.Var_BrightMaxValue;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_BrightMaxValue;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_BrightMaxValue;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__Default) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgOff) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__1stChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__1stChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgFadeIn) || ((uint32)
                    rtu_PostProcessIn_e2b1 == RWPCIndCmdState__2ndChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__3rdChrgFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__3rdChrgOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ChrgFadeOut)) {
          /* Green IND Light */
          rtb_Output_GreenIND_OUT = App_Model_B.Var_GreenINDwithAnimation1;
          rtb_Output_GreenIND2_OUT = App_Model_B.Var_GreenINDwithAnimation2;
          rtb_Output_GreenIND3_OUT = App_Model_B.Var_GreenINDwithAnimation3;
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_AmberIND_OUT = (uint16)0.0;
            } else {
              rtb_Output_AmberIND_OUT = 0U;
            }
          } else {
            rtb_Output_AmberIND_OUT = MAX_uint16_T;
          }
        } else if (((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorOn) || ((uint32)rtu_PostProcessIn_e2b1 == RWPCIndCmdState__ErrorFadeIn) || ((uint32)rtu_PostProcessIn_e2b1 ==
                    RWPCIndCmdState__ErrorFadeOut)) {
          /* Amber IND light */
          if (0.0 < 65536.0) {
            if (0.0 >= 0.0) {
              rtb_Output_GreenIND_OUT = (uint16)0.0;
              rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
              rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            } else {
              rtb_Output_GreenIND_OUT = 0U;
              rtb_Output_GreenIND2_OUT = 0U;
              rtb_Output_GreenIND3_OUT = 0U;
            }
          } else {
            rtb_Output_GreenIND_OUT = MAX_uint16_T;
            rtb_Output_GreenIND2_OUT = MAX_uint16_T;
            rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          }

          rtb_Output_AmberIND_OUT = App_Model_B.Var_AmberINDwithAnimation;
        } else if (0.0 < 65536.0) {
          if (0.0 >= 0.0) {
            rtb_Output_GreenIND_OUT = (uint16)0.0;
            rtb_Output_GreenIND2_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_GreenIND3_OUT = rtb_Output_GreenIND_OUT;
            rtb_Output_AmberIND_OUT = rtb_Output_GreenIND_OUT;
          } else {
            rtb_Output_GreenIND_OUT = 0U;
            rtb_Output_GreenIND2_OUT = 0U;
            rtb_Output_GreenIND3_OUT = 0U;
            rtb_Output_AmberIND_OUT = 0U;
          }
        } else {
          rtb_Output_GreenIND_OUT = MAX_uint16_T;
          rtb_Output_GreenIND2_OUT = MAX_uint16_T;
          rtb_Output_GreenIND3_OUT = MAX_uint16_T;
          rtb_Output_AmberIND_OUT = MAX_uint16_T;

          /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
             Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
        }
      } else {
        rtb_Output_GreenIND_OUT = rtb_Var_GreenIND_ier0;
        rtb_Output_GreenIND2_OUT = rtb_Var_GreenIND_ier0;
        rtb_Output_GreenIND3_OUT = rtb_Var_GreenIND_ier0;
        rtb_Output_AmberIND_OUT = rtb_Var_AmberIND_ephh;
      }

      /* End of Chart: '<S486>/IND_Output_Control_Function_Flow_Graph' */

      /* SignalConversion generated from: '<S483>/P_AmberIND_OUT' */
      *rty_IndyOutput_Sig_a1tj = rtb_Output_AmberIND_OUT;

      /* SignalConversion generated from: '<S483>/P_GreenIND2_OUT' */
      *rty_IndyOutput_Sig_e2b1 = rtb_Output_GreenIND2_OUT;

      /* SignalConversion generated from: '<S483>/P_GreenIND3_OUT' */
      *rty_IndyOutput_Sig_czfa = rtb_Output_GreenIND3_OUT;

      /* SignalConversion generated from: '<S483>/P_GreenIND_OUT' */
      *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT;

      /* End of Outputs for SubSystem: '<S468>/AutoBrightIndyOutputControl_Type3' */
    }
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S468>/Switch Case' */
}

/* System initialize for atomic system: '<S639>/IndyOutputControl_Function' */
void IndyOutputControl_Fun_fbjd_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_m0cm, uint16 *rty_IndyOutput_Sig_hewm, uint16 *rty_IndyOutput_Sig_nd1o)
{
  /* Start for SwitchCase: '<S645>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for IfAction SubSystem: '<S645>/RheoStatIndyOutputControl_Type1' */
  RheoStatIndyOutputControl__Init(&App_Model_B.RheoStatIndyOutputControl__ks1j, &App_Model_DW.RheoStatIndyOutputControl__ks1j);

  /* End of SystemInitialize for SubSystem: '<S645>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for IfAction SubSystem: '<S645>/RheoStatIndyOutputControl_Type2' */
  RheoStatIndyOutputCon_dc24_Init(&App_Model_B.RheoStatIndyOutputControl__lkwv, &App_Model_DW.RheoStatIndyOutputControl__lkwv);

  /* End of SystemInitialize for SubSystem: '<S645>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for IfAction SubSystem: '<S645>/AutoBrightIndyOutputControl_Type3' */
  AutoBrightIndyOutputContro_Init(&App_Model_B.AutoBrightIndyOutputContro_ikmb, &App_Model_DW.AutoBrightIndyOutputContro_ikmb);

  /* End of SystemInitialize for SubSystem: '<S645>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Merge generated from: '<S645>/Merge' */
  *rty_IndyOutput_Sig = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S645>/Merge' */
  *rty_IndyOutput_Sig_m0cm = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S645>/Merge' */
  *rty_IndyOutput_Sig_hewm = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S645>/Merge' */
  *rty_IndyOutput_Sig_nd1o = ((uint16)0U);
}

/* Disable for atomic system: '<S639>/IndyOutputControl_Function' */
void IndyOutputControl__i523_Disable(void)
{
  /* Disable for SwitchCase: '<S645>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<S639>/IndyOutputControl_Function' */
void IndyOutputControl_Function_ds32(INDContType rtu_PostProcessIn, WPCIndUSMState rtu_PostProcessIn_m0cm, RheostatOption rtu_PostProcessIn_hewm, Bool rtu_PostProcessIn_nd1o, Bool
  rtu_PostProcessIn_fhw1, C_RheoStatLevel rtu_PostProcessIn_nuol, Bool rtu_PostProcessIn_iuww, Bool rtu_PostProcessIn_e0kb, WPCIndCmdState rtu_PostProcessIn_date, Bool rtu_PostProcessIn_heya,
  C_AutoBrightLevel rtu_PostProcessIn_b0mg, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_m0cm, uint16 *rty_IndyOutput_Sig_hewm, uint16 *rty_IndyOutput_Sig_nd1o)
{
  sint8 rtPrevAction;

  /* SwitchCase: '<S645>/Switch Case' */
  rtPrevAction = App_Model_DW.SwitchCase_ActiveSubsystem;
  App_Model_DW.SwitchCase_ActiveSubsystem = -1;
  switch (rtu_PostProcessIn) {
   case INDConType1:
    App_Model_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case INDConType2:
    App_Model_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   case INDConType3:
    App_Model_DW.SwitchCase_ActiveSubsystem = 2;
    break;

   default:
    /* no actions */
    break;
  }

  switch (App_Model_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    if (App_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S645>/RheoStatIndyOutputControl_Type1' incorporates:
       *  ActionPort: '<S665>/ActionPort'
       */
      /* Enable for SwitchCase: '<S645>/Switch Case' */
      RheoStatIndyOutputContro_Enable(&App_Model_DW.RheoStatIndyOutputControl__ks1j);

      /* End of Enable for SubSystem: '<S645>/RheoStatIndyOutputControl_Type1' */
    }

    /* Outputs for IfAction SubSystem: '<S645>/RheoStatIndyOutputControl_Type1' incorporates:
     *  ActionPort: '<S665>/ActionPort'
     */
    RheoStatIndyOutputControl_Type1(App_Model_M, rtu_PostProcessIn_m0cm, rtu_PostProcessIn_hewm, rtu_PostProcessIn_nd1o, rtu_PostProcessIn_fhw1, rtu_PostProcessIn_nuol, rtu_PostProcessIn_iuww,
      rtu_PostProcessIn_e0kb, rtu_PostProcessIn_date, rtu_PostProcessIn_heya, rty_IndyOutput_Sig, rty_IndyOutput_Sig_m0cm, rty_IndyOutput_Sig_hewm, rty_IndyOutput_Sig_nd1o,
      &App_Model_B.RheoStatIndyOutputControl__ks1j, &App_Model_DW.RheoStatIndyOutputControl__ks1j);

    /* End of Outputs for SubSystem: '<S645>/RheoStatIndyOutputControl_Type1' */
    break;

   case 1:
    if (App_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S645>/RheoStatIndyOutputControl_Type2' incorporates:
       *  ActionPort: '<S666>/ActionPort'
       */
      /* Enable for SwitchCase: '<S645>/Switch Case' */
      RheoStatIndyOutputC_jyjj_Enable(&App_Model_DW.RheoStatIndyOutputControl__lkwv);

      /* End of Enable for SubSystem: '<S645>/RheoStatIndyOutputControl_Type2' */
    }

    /* Outputs for IfAction SubSystem: '<S645>/RheoStatIndyOutputControl_Type2' incorporates:
     *  ActionPort: '<S666>/ActionPort'
     */
    RheoStatIndyOutputControl_Type2(App_Model_M, rtu_PostProcessIn_m0cm, rtu_PostProcessIn_hewm, rtu_PostProcessIn_nd1o, rtu_PostProcessIn_nuol, rtu_PostProcessIn_iuww, rtu_PostProcessIn_e0kb,
      rtu_PostProcessIn_date, rtu_PostProcessIn_heya, rty_IndyOutput_Sig, rty_IndyOutput_Sig_m0cm, rty_IndyOutput_Sig_hewm, rty_IndyOutput_Sig_nd1o, &App_Model_B.RheoStatIndyOutputControl__lkwv,
      &App_Model_DW.RheoStatIndyOutputControl__lkwv);

    /* End of Outputs for SubSystem: '<S645>/RheoStatIndyOutputControl_Type2' */
    break;

   case 2:
    if (App_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S645>/AutoBrightIndyOutputControl_Type3' incorporates:
       *  ActionPort: '<S664>/ActionPort'
       */
      /* Enable for SwitchCase: '<S645>/Switch Case' */
      AutoBrightIndyOutputCont_Enable(&App_Model_DW.AutoBrightIndyOutputContro_ikmb);

      /* End of Enable for SubSystem: '<S645>/AutoBrightIndyOutputControl_Type3' */
    }

    /* Outputs for IfAction SubSystem: '<S645>/AutoBrightIndyOutputControl_Type3' incorporates:
     *  ActionPort: '<S664>/ActionPort'
     */
    AutoBrightIndyOutputControl_Typ(App_Model_M, rtu_PostProcessIn_m0cm, rtu_PostProcessIn_b0mg, rtu_PostProcessIn_fhw1, rtu_PostProcessIn_iuww, rtu_PostProcessIn_e0kb, rtu_PostProcessIn_date,
      rtu_PostProcessIn_heya, rty_IndyOutput_Sig, rty_IndyOutput_Sig_m0cm, rty_IndyOutput_Sig_hewm, rty_IndyOutput_Sig_nd1o, &App_Model_B.AutoBrightIndyOutputContro_ikmb,
      &App_Model_DW.AutoBrightIndyOutputContro_ikmb);

    /* End of Outputs for SubSystem: '<S645>/AutoBrightIndyOutputControl_Type3' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S645>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
