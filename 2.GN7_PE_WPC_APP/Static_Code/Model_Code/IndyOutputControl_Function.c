/*
 * File: IndyOutputControl_Function.c
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

#include "rtwtypes.h"
#include "App_Model_types.h"
#include "IndyOutputControl_Function.h"
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
static void WPC_IND_Output_Control_Functi_d(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue);

/* Forward declaration for local functions */
static void enter_internal_c420_IndyOutputC(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue);

/* Forward declaration for local functions */
static void App_Mode_Bright_Error_Control_l(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const
  App_Model_M, B_Amber_IND_with_Animation__m_T *localB, DW_Amber_IND_with_Animation_l_T *localDW);

/* Forward declaration for local functions */
static void App_Model_Bright_Control1_n(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW);
static void App_Model_Bright_Control2_h(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW);
static void App_Model_Bright_Control3_c(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW);

/*
 * System initialize for atomic system:
 *    '<S85>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S133>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S37>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S265>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S313>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S217>/Amber_IND_Control_Function_Flow_Graph'
 */
void Amber_IND_Control_Function_Init(uint16 *rty_Var_AmberIND)
{
  *rty_Var_AmberIND = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S85>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S133>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S37>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S265>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S313>/Amber_IND_Control_Function_Flow_Graph'
 *    '<S217>/Amber_IND_Control_Function_Flow_Graph'
 */
void Amber_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_AmberINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_AmberIND, DW_Amber_IND_Control_Function_T *localDW)
{
  /* Chart: '<S85>/Amber_IND_Control_Function_Flow_Graph' */
  if (localDW->is_active_c323_IndyOutputContro == 0U) {
    localDW->is_active_c323_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_AmberIND = Off;

    /* 1 */
    if (rtu_Input_OPT_b_AmberINDCmd == On) {
      *rty_Var_AmberIND = rtu_Var_BrightMaxValue;
    } else {
      *rty_Var_AmberIND = Off;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if (rtu_Input_OPT_b_AmberINDCmd == On) {
    *rty_Var_AmberIND = rtu_Var_BrightMaxValue;
  } else {
    *rty_Var_AmberIND = Off;
  }

  /* End of Chart: '<S85>/Amber_IND_Control_Function_Flow_Graph' */
}

/*
 * System reset for function-call system:
 *    '<S87>/FadeIn'
 *    '<S135>/FadeIn'
 *    '<S39>/FadeIn'
 *    '<S267>/FadeIn'
 *    '<S315>/FadeIn'
 *    '<S219>/FadeIn'
 */
void App_Model_FadeIn_Reset(DW_FadeIn_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S95>/Delay Input1'
   *
   * Block description for '<S95>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S93>/Switch1' incorporates:
   *  UnitDelay: '<S93>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S87>/FadeIn'
 *    '<S135>/FadeIn'
 *    '<S39>/FadeIn'
 *    '<S267>/FadeIn'
 *    '<S315>/FadeIn'
 *    '<S219>/FadeIn'
 */
void App_Model_FadeIn(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger, float64 rtu_pass, uint16 *rty_y_FadeIn, DW_FadeIn_App_Model_T *localDW)
{
  float64 rtb_Switch_in;

  /* Switch: '<S93>/Switch3' incorporates:
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   *  Logic: '<S93>/AND'
   *  RelationalOperator: '<S95>/FixPt Relational Operator'
   *  Switch: '<S93>/Switch'
   *  Switch: '<S93>/Switch1'
   *  UnitDelay: '<S95>/Delay Input1'
   *
   * Block description for '<S95>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger != 0) && (rtu_pass != 0.0)) {
    /* Switch: '<S93>/Switch1' incorporates:
     *  UnitDelay: '<S93>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = rtu_Var_BrightMaxValue;
  } else {
    if (rtu_Trigger > 0) {
      /* Switch: '<S93>/Switch' incorporates:
       *  Constant: '<S93>/Constant2'
       *  Product: '<S93>/Divide'
       */
      rtb_Switch_in = (float64)rtu_Var_BrightMaxValue / 100.0;
    } else {
      /* Switch: '<S93>/Switch' incorporates:
       *  Constant: '<S93>/Constant1'
       */
      rtb_Switch_in = 0.0;

      /* Switch: '<S93>/Switch1' incorporates:
       *  Constant: '<S93>/Constant3'
       */
      localDW->UnitDelay_DSTATE = 0.0;
    }

    /* Switch: '<S93>/Switch1' incorporates:
     *  Sum: '<S93>/Add1'
     *  UnitDelay: '<S93>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE += rtb_Switch_in;
  }

  /* End of Switch: '<S93>/Switch3' */

  /* Switch: '<S93>/Switch2' incorporates:
   *  Constant: '<S93>/Constant4'
   */
  if (rtu_Trigger > 0) {
    /* Switch: '<S93>/Switch5' */
    if (rtu_pass > 0.0) {
      /* Switch: '<S93>/Switch5' incorporates:
       *  DataTypeConversion: '<S93>/Data Type Conversion'
       */
      rtb_Switch_in = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S93>/Switch5' incorporates:
       *  UnitDelay: '<S93>/Unit Delay'
       */
      rtb_Switch_in = localDW->UnitDelay_DSTATE;
    }

    /* End of Switch: '<S93>/Switch5' */

    /* Switch: '<S96>/Switch2' incorporates:
     *  DataTypeConversion: '<S93>/Data Type Conversion'
     *  RelationalOperator: '<S96>/LowerRelop1'
     *  RelationalOperator: '<S96>/UpperRelop'
     *  Switch: '<S96>/Switch'
     */
    if (rtb_Switch_in > rtu_Var_BrightMaxValue) {
      rtb_Switch_in = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch_in < 0.0) {
      /* Switch: '<S96>/Switch' incorporates:
       *  Constant: '<S93>/Constant4'
       */
      rtb_Switch_in = 0.0;
    }

    /* End of Switch: '<S96>/Switch2' */
    rtb_Switch_in = fmod(floor(rtb_Switch_in), 65536.0);
    *rty_y_FadeIn = (uint16)(rtb_Switch_in < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-rtb_Switch_in : (sint32)(uint16)rtb_Switch_in);
  } else {
    *rty_y_FadeIn = 0U;
  }

  /* End of Switch: '<S93>/Switch2' */

  /* Update for UnitDelay: '<S95>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   *
   * Block description for '<S95>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System reset for function-call system:
 *    '<S87>/FadeOut'
 *    '<S135>/FadeOut'
 *    '<S39>/FadeOut'
 */
void App_Model_FadeOut_Reset(DW_FadeOut_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S97>/Delay Input1'
   *
   * Block description for '<S97>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S101>/Delay Input2'
   *
   * Block description for '<S101>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S87>/FadeOut'
 *    '<S135>/FadeOut'
 *    '<S39>/FadeOut'
 */
void App_Model_FadeOut_Enable(DW_FadeOut_App_Model_T *localDW)
{
  localDW->FadeOut_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S87>/FadeOut'
 *    '<S135>/FadeOut'
 *    '<S39>/FadeOut'
 */
void App_Model_FadeOut(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_g;
  float64 rtb_deltafalllimit;
  if (localDW->FadeOut_RESET_ELAPS_T) {
    localDW->FadeOut_ELAPS_T = 0U;
  } else {
    localDW->FadeOut_ELAPS_T = App_Model_M->Timing.clockTick0 - localDW->FadeOut_PREV_T;
  }

  localDW->FadeOut_PREV_T = App_Model_M->Timing.clockTick0;
  localDW->FadeOut_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S101>/sample time'
   *
   * About '<S101>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (float64)localDW->FadeOut_ELAPS_T * 0.01;

  /* Switch: '<S102>/Switch2' incorporates:
   *  DataTypeConversion: '<S98>/Data Type Conversion2'
   *  Product: '<S101>/delta rise limit'
   *  SampleTimeMath: '<S101>/sample time'
   *
   * About '<S101>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltafalllimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S94>/Switch8' incorporates:
   *  Logic: '<S94>/AND'
   *  RelationalOperator: '<S97>/FixPt Relational Operator'
   *  Switch: '<S94>/Switch7'
   *  UnitDelay: '<S97>/Delay Input1'
   *
   * Block description for '<S97>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger_FO != 0) && (rtu_pass != 0.0)) {
    /* Switch: '<S94>/Switch8' */
    rtb_Add1_g = rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger_FO > 0) {
    /* Sum: '<S94>/Add1' incorporates:
     *  Constant: '<S94>/Constant5'
     *  Product: '<S94>/Divide'
     *  Switch: '<S94>/Switch'
     *  Switch: '<S94>/Switch5'
     *  Switch: '<S94>/Switch7'
     */
    rtb_Add1_g = (float64)rtu_preValue - (float64)rtu_Var_BrightMaxValue / 100.0;

    /* Switch: '<S100>/Switch2' incorporates:
     *  RelationalOperator: '<S100>/LowerRelop1'
     *  RelationalOperator: '<S100>/UpperRelop'
     *  Switch: '<S100>/Switch'
     *  Switch: '<S94>/Switch7'
     */
    if (rtb_Add1_g > rtu_preValue) {
      /* Switch: '<S94>/Switch8' incorporates:
       *  Switch: '<S100>/Switch2'
       */
      rtb_Add1_g = rtu_preValue;
    } else if (rtb_Add1_g < 0.0) {
      /* Switch: '<S100>/Switch' incorporates:
       *  Constant: '<S94>/Constant2'
       *  Switch: '<S100>/Switch2'
       *  Switch: '<S94>/Switch8'
       */
      rtb_Add1_g = 0.0;
    }

    /* End of Switch: '<S100>/Switch2' */
  } else {
    /* Switch: '<S94>/Switch8' incorporates:
     *  Constant: '<S94>/Constant2'
     *  Switch: '<S94>/Switch7'
     */
    rtb_Add1_g = 0.0;
  }

  /* End of Switch: '<S94>/Switch8' */

  /* Sum: '<S101>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S101>/Delay Input2'
   *
   * Block description for '<S101>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S101>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_g -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S102>/Switch2' incorporates:
   *  RelationalOperator: '<S102>/LowerRelop1'
   */
  if (rtb_Add1_g <= rtb_deltafalllimit) {
    /* Switch: '<S98>/Switch4' incorporates:
     *  DataStoreRead: '<S98>/Data Store Read'
     *  DataTypeConversion: '<S98>/Data Type Conversion2'
     *  DataTypeConversion: '<S98>/Data Type Conversion6'
     *  UnaryMinus: '<S98>/Unary Minus'
     *  UnaryMinus: '<S98>/Unary Minus2'
     */
    if (rtu_pass > 0.0) {
      rtb_deltafalllimit = -(float64)Par_AutoBrightLevel091;
    } else {
      rtb_deltafalllimit = -(float64)rtu_Var_BrightMaxValue;
    }

    /* End of Switch: '<S98>/Switch4' */

    /* Product: '<S101>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S101>/sample time'
     *
     * About '<S101>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_deltafalllimit *= elapseTime;

    /* Switch: '<S102>/Switch' incorporates:
     *  RelationalOperator: '<S102>/UpperRelop'
     */
    if (rtb_Add1_g >= rtb_deltafalllimit) {
      /* Switch: '<S102>/Switch2' */
      rtb_deltafalllimit = rtb_Add1_g;
    }

    /* End of Switch: '<S102>/Switch' */
  }

  /* End of Switch: '<S102>/Switch2' */

  /* Sum: '<S101>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S101>/Delay Input2'
   *
   * Block description for '<S101>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S101>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_deltafalllimit;

  /* Switch: '<S94>/Switch1' incorporates:
   *  Constant: '<S94>/Constant7'
   */
  if (rtu_Trigger_FO > 0) {
    uint16 rtb_Switch9;

    /* Switch: '<S98>/Switch9' */
    if (rtu_pass > 0.0) {
      /* Switch: '<S98>/Switch9' incorporates:
       *  DataTypeConversion: '<S98>/Data Type Conversion2'
       */
      rtb_Switch9 = rtu_Var_BrightMaxValue;
    } else {
      /* DataTypeConversion: '<S98>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S101>/Delay Input2'
       *
       * Block description for '<S101>/Delay Input2':
       *
       *  Store in Global RAM
       */
      elapseTime = fmod(floor(localDW->DelayInput2_DSTATE), 65536.0);

      /* Switch: '<S98>/Switch9' incorporates:
       *  DataTypeConversion: '<S98>/Data Type Conversion1'
       */
      rtb_Switch9 = (uint16)(elapseTime < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-elapseTime : (sint32)(uint16)elapseTime);
    }

    /* End of Switch: '<S98>/Switch9' */

    /* Switch: '<S99>/Switch2' incorporates:
     *  RelationalOperator: '<S99>/LowerRelop1'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      /* Switch: '<S99>/Switch2' */
      *rty_y_FadeOut = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S99>/Switch2' incorporates:
       *  Switch: '<S99>/Switch'
       */
      *rty_y_FadeOut = rtb_Switch9;
    }

    /* End of Switch: '<S99>/Switch2' */
  } else {
    *rty_y_FadeOut = 0U;
  }

  /* End of Switch: '<S94>/Switch1' */

  /* Update for UnitDelay: '<S97>/Delay Input1'
   *
   * Block description for '<S97>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Error_Control(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const App_Model_M,
  B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW)
{
  if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localDW->pass = 0.0;
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S87>/FadeIn' */
    /* FcnTrigRst = FadeOut(Var_BrightMaxValue,Var_AmberINDwithAnimation,0,0); */
    *rty_Var_AmberINDwithAnimation = 0U;
  } else {
    switch (rtu_Input_INT_WPCIndCmdState) {
     case WPCIndCmdState__ErrorOn:
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S87>/FadeIn' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      break;

     case WPCIndCmdState__ErrorFadeIn:
      if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 1.0)) {
        localDW->pass = 1.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 1.0;

        /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, 1, 1.0, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S87>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      } else {
        localDW->pass = 0.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 0.0;

        /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, 1, 0.0, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S87>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = localB->Switch2;
      }
      break;
    }
  }

  if (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeOut) {
    if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 2.0)) {
      localDW->pass = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S87>/FadeIn' */
      localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 0;
      localB->pass_c = 1.0;

      /* Outputs for Function Call SubSystem: '<S87>/FadeOut' */
      App_Model_FadeOut(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue, 0, 1.0, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S87>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
    } else {
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S87>/FadeIn' */
      localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 1;
      localB->pass_c = 0.0;

      /* Outputs for Function Call SubSystem: '<S87>/FadeOut' */
      App_Model_FadeOut(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue, 1, 0.0, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S87>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = localB->Switch1;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S133>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S37>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_C_Init(uint16 *rty_Var_AmberINDwithAnimation)
{
  *rty_Var_AmberINDwithAnimation = 0U;
}

/*
 * Enable for atomic system:
 *    '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S133>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S37>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_Enable(DW_Amber_IND_with_Animation_C_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S87>/FadeIn' */
  App_Model_FadeIn_Reset(&localDW->FadeIn);

  /* End of SystemReset for SubSystem: '<S87>/FadeIn' */

  /* SystemReset for Function Call SubSystem: '<S87>/FadeOut' */
  App_Model_FadeOut_Reset(&localDW->FadeOut);

  /* End of SystemReset for SubSystem: '<S87>/FadeOut' */

  /* Enable for Function Call SubSystem: '<S87>/FadeOut' */
  App_Model_FadeOut_Enable(&localDW->FadeOut);

  /* End of Enable for SubSystem: '<S87>/FadeOut' */
}

/*
 * Output and update for atomic system:
 *    '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S133>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S37>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if (localDW->is_active_c425_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c425_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S87>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S87>/FadeIn' */
    localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_AmberINDwithAnimation;
    localB->Trigger_FO = 0;
    localB->pass_c = 0.0;

    /* Outputs for Function Call SubSystem: '<S87>/FadeOut' */
    App_Model_FadeOut(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue, 0, 0.0, &localB->Switch1, &localDW->FadeOut);

    /* End of Outputs for SubSystem: '<S87>/FadeOut' */
    *rty_Var_AmberINDwithAnimation = 0U;
    if (rtu_b_SyncAmber == Off) {
      *rty_Var_AmberINDwithAnimation = 0U;

      /* 1 */
    } else if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPCIndCmdState ==
                WPCIndCmdState__ErrorFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default)) {
      App_Model_Bright_Error_Control(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);
    } else {
      /* Not used in Amber LED */
      *rty_Var_AmberINDwithAnimation = 0U;
    }

    /*  Transition run every task on system operation */
  } else if (rtu_b_SyncAmber == Off) {
    *rty_Var_AmberINDwithAnimation = 0U;

    /* 1 */
  } else if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeOut)
             || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default)) {
    App_Model_Bright_Error_Control(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);
  } else {
    /* Not used in Amber LED */
    *rty_Var_AmberINDwithAnimation = 0U;
  }

  /* End of Chart: '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for atomic system:
 *    '<S85>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S265>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_F_Init(uint16 *rty_Var_BrightMaxValue)
{
  *rty_Var_BrightMaxValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S85>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S265>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_Functi(Bool rtu_Input_DetentOut, RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue,
  DW_Bright_Max_Value_Control_F_T *localDW)
{
  /* Chart: '<S85>/Bright_Max_Value_Control_Function_Flow_Graph' */
  if (localDW->is_active_c333_IndyOutputContro == 0U) {
    localDW->is_active_c333_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_BrightMaxValue = rtu_RheoLevelValue;

    /* 1 */
    if (rtu_Input_RheostatOption == On) {
      if (rtu_Input_DetentOut == On) {
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
    } else if (rtu_Input_RheostatOption == Off) {
      if (rtu_Input_b_IntTailOn == On) {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
      } else {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if (rtu_Input_RheostatOption == On) {
    if (rtu_Input_DetentOut == On) {
      *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
    } else {
      *rty_Var_BrightMaxValue = rtu_RheoLevelValue;
    }
  } else if (rtu_Input_RheostatOption == Off) {
    if (rtu_Input_b_IntTailOn == On) {
      /* 2 */
      *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
    } else {
      /* 2 */
      *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
    }
  }

  /* End of Chart: '<S85>/Bright_Max_Value_Control_Function_Flow_Graph' */
}

/*
 * System initialize for atomic system:
 *    '<S85>/Green_IND_Control_Function_Flow_Graph'
 *    '<S133>/Green_IND_Control_Function_Flow_Graph'
 *    '<S37>/Green_IND_Control_Function_Flow_Graph'
 *    '<S265>/Green_IND_Control_Function_Flow_Graph'
 *    '<S313>/Green_IND_Control_Function_Flow_Graph'
 *    '<S217>/Green_IND_Control_Function_Flow_Graph'
 */
void Green_IND_Control_Function_Init(uint16 *rty_Var_GreenIND)
{
  *rty_Var_GreenIND = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S85>/Green_IND_Control_Function_Flow_Graph'
 *    '<S133>/Green_IND_Control_Function_Flow_Graph'
 *    '<S37>/Green_IND_Control_Function_Flow_Graph'
 *    '<S265>/Green_IND_Control_Function_Flow_Graph'
 *    '<S313>/Green_IND_Control_Function_Flow_Graph'
 *    '<S217>/Green_IND_Control_Function_Flow_Graph'
 */
void Green_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_GreenINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_GreenIND, DW_Green_IND_Control_Function_T *localDW)
{
  /* Chart: '<S85>/Green_IND_Control_Function_Flow_Graph' */
  if (localDW->is_active_c337_IndyOutputContro == 0U) {
    localDW->is_active_c337_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_GreenIND = Off;

    /* 1 */
    if (rtu_Input_OPT_b_GreenINDCmd == On) {
      *rty_Var_GreenIND = rtu_Var_BrightMaxValue;
    } else {
      *rty_Var_GreenIND = Off;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if (rtu_Input_OPT_b_GreenINDCmd == On) {
    *rty_Var_GreenIND = rtu_Var_BrightMaxValue;
  } else {
    *rty_Var_GreenIND = Off;
  }

  /* End of Chart: '<S85>/Green_IND_Control_Function_Flow_Graph' */
}

/*
 * System reset for function-call system:
 *    '<S90>/FadeIn1'
 *    '<S138>/FadeIn1'
 *    '<S42>/FadeIn1'
 *    '<S270>/FadeIn1'
 *    '<S318>/FadeIn1'
 *    '<S222>/FadeIn1'
 */
void App_Model_FadeIn1_Reset(DW_FadeIn1_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S109>/Delay Input1'
   *
   * Block description for '<S109>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S103>/Switch1' incorporates:
   *  UnitDelay: '<S103>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S90>/FadeIn1'
 *    '<S138>/FadeIn1'
 *    '<S42>/FadeIn1'
 *    '<S270>/FadeIn1'
 *    '<S318>/FadeIn1'
 *    '<S222>/FadeIn1'
 */
void App_Model_FadeIn1(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger1, float64 rtu_pass1, uint16 *rty_y_FadeIn1, DW_FadeIn1_App_Model_T *localDW)
{
  float64 rtb_Switch_h;

  /* Switch: '<S103>/Switch3' incorporates:
   *  DataTypeConversion: '<S103>/Data Type Conversion'
   *  Logic: '<S103>/AND'
   *  RelationalOperator: '<S109>/FixPt Relational Operator'
   *  Switch: '<S103>/Switch'
   *  Switch: '<S103>/Switch1'
   *  UnitDelay: '<S109>/Delay Input1'
   *
   * Block description for '<S109>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger1 != 0) && (rtu_pass1 != 0.0)) {
    /* Switch: '<S103>/Switch1' incorporates:
     *  UnitDelay: '<S103>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = rtu_Var_BrightMaxValue;
  } else {
    if (rtu_Trigger1 > 0) {
      /* Switch: '<S103>/Switch' incorporates:
       *  Constant: '<S103>/Constant2'
       *  Product: '<S103>/Divide'
       */
      rtb_Switch_h = (float64)rtu_Var_BrightMaxValue / 100.0;
    } else {
      /* Switch: '<S103>/Switch' incorporates:
       *  Constant: '<S103>/Constant1'
       */
      rtb_Switch_h = 0.0;

      /* Switch: '<S103>/Switch1' incorporates:
       *  Constant: '<S103>/Constant3'
       */
      localDW->UnitDelay_DSTATE = 0.0;
    }

    /* Switch: '<S103>/Switch1' incorporates:
     *  Sum: '<S103>/Add1'
     *  UnitDelay: '<S103>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE += rtb_Switch_h;
  }

  /* End of Switch: '<S103>/Switch3' */

  /* Switch: '<S103>/Switch2' incorporates:
   *  Constant: '<S103>/Constant4'
   */
  if (rtu_Trigger1 > 0) {
    /* Switch: '<S103>/Switch5' */
    if (rtu_pass1 > 0.0) {
      /* Switch: '<S103>/Switch5' incorporates:
       *  DataTypeConversion: '<S103>/Data Type Conversion'
       */
      rtb_Switch_h = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S103>/Switch5' incorporates:
       *  UnitDelay: '<S103>/Unit Delay'
       */
      rtb_Switch_h = localDW->UnitDelay_DSTATE;
    }

    /* End of Switch: '<S103>/Switch5' */

    /* Switch: '<S110>/Switch2' incorporates:
     *  DataTypeConversion: '<S103>/Data Type Conversion'
     *  RelationalOperator: '<S110>/LowerRelop1'
     *  RelationalOperator: '<S110>/UpperRelop'
     *  Switch: '<S110>/Switch'
     */
    if (rtb_Switch_h > rtu_Var_BrightMaxValue) {
      rtb_Switch_h = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch_h < 0.0) {
      /* Switch: '<S110>/Switch' incorporates:
       *  Constant: '<S103>/Constant4'
       */
      rtb_Switch_h = 0.0;
    }

    /* End of Switch: '<S110>/Switch2' */
    rtb_Switch_h = fmod(floor(rtb_Switch_h), 65536.0);
    *rty_y_FadeIn1 = (uint16)(rtb_Switch_h < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-rtb_Switch_h : (sint32)(uint16)rtb_Switch_h);
  } else {
    *rty_y_FadeIn1 = 0U;
  }

  /* End of Switch: '<S103>/Switch2' */

  /* Update for UnitDelay: '<S109>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S103>/Data Type Conversion'
   *
   * Block description for '<S109>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System reset for function-call system:
 *    '<S90>/FadeOut1'
 *    '<S138>/FadeOut1'
 *    '<S42>/FadeOut1'
 *    '<S270>/FadeOut1'
 *    '<S318>/FadeOut1'
 *    '<S222>/FadeOut1'
 */
void App_Model_FadeOut1_Reset(DW_FadeOut1_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S115>/Delay Input1'
   *
   * Block description for '<S115>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S119>/Delay Input2'
   *
   * Block description for '<S119>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S90>/FadeOut1'
 *    '<S138>/FadeOut1'
 *    '<S42>/FadeOut1'
 *    '<S270>/FadeOut1'
 *    '<S318>/FadeOut1'
 *    '<S222>/FadeOut1'
 */
void App_Model_FadeOut1_Enable(DW_FadeOut1_App_Model_T *localDW)
{
  localDW->FadeOut1_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S90>/FadeOut1'
 *    '<S138>/FadeOut1'
 *    '<S42>/FadeOut1'
 *    '<S270>/FadeOut1'
 *    '<S318>/FadeOut1'
 *    '<S222>/FadeOut1'
 */
void App_Model_FadeOut1(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger1_FO, float64 rtu_pass1, uint16 *rty_y_FadeOut1,
  DW_FadeOut1_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_m;
  float64 rtb_deltafalllimit;
  if (localDW->FadeOut1_RESET_ELAPS_T) {
    localDW->FadeOut1_ELAPS_T = 0U;
  } else {
    localDW->FadeOut1_ELAPS_T = App_Model_M->Timing.clockTick0 - localDW->FadeOut1_PREV_T;
  }

  localDW->FadeOut1_PREV_T = App_Model_M->Timing.clockTick0;
  localDW->FadeOut1_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S119>/sample time'
   *
   * About '<S119>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (float64)localDW->FadeOut1_ELAPS_T * 0.01;

  /* Switch: '<S120>/Switch2' incorporates:
   *  DataTypeConversion: '<S116>/Data Type Conversion2'
   *  Product: '<S119>/delta rise limit'
   *  SampleTimeMath: '<S119>/sample time'
   *
   * About '<S119>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltafalllimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S106>/Switch8' incorporates:
   *  Logic: '<S106>/AND'
   *  RelationalOperator: '<S115>/FixPt Relational Operator'
   *  Switch: '<S106>/Switch7'
   *  UnitDelay: '<S115>/Delay Input1'
   *
   * Block description for '<S115>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger1_FO != 0) && (rtu_pass1 != 0.0)) {
    /* Switch: '<S106>/Switch8' */
    rtb_Add1_m = rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger1_FO > 0) {
    /* Sum: '<S106>/Add1' incorporates:
     *  Constant: '<S106>/Constant5'
     *  Product: '<S106>/Divide'
     *  Switch: '<S106>/Switch'
     *  Switch: '<S106>/Switch5'
     *  Switch: '<S106>/Switch7'
     */
    rtb_Add1_m = (float64)rtu_preValue - (float64)rtu_Var_BrightMaxValue / 100.0;

    /* Switch: '<S118>/Switch2' incorporates:
     *  RelationalOperator: '<S118>/LowerRelop1'
     *  RelationalOperator: '<S118>/UpperRelop'
     *  Switch: '<S106>/Switch7'
     *  Switch: '<S118>/Switch'
     */
    if (rtb_Add1_m > rtu_preValue) {
      /* Switch: '<S106>/Switch8' incorporates:
       *  Switch: '<S118>/Switch2'
       */
      rtb_Add1_m = rtu_preValue;
    } else if (rtb_Add1_m < 0.0) {
      /* Switch: '<S118>/Switch' incorporates:
       *  Constant: '<S106>/Constant2'
       *  Switch: '<S106>/Switch8'
       *  Switch: '<S118>/Switch2'
       */
      rtb_Add1_m = 0.0;
    }

    /* End of Switch: '<S118>/Switch2' */
  } else {
    /* Switch: '<S106>/Switch8' incorporates:
     *  Constant: '<S106>/Constant2'
     *  Switch: '<S106>/Switch7'
     */
    rtb_Add1_m = 0.0;
  }

  /* End of Switch: '<S106>/Switch8' */

  /* Sum: '<S119>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S119>/Delay Input2'
   *
   * Block description for '<S119>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S119>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_m -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S120>/Switch2' incorporates:
   *  RelationalOperator: '<S120>/LowerRelop1'
   */
  if (rtb_Add1_m <= rtb_deltafalllimit) {
    /* Switch: '<S116>/Switch4' incorporates:
     *  DataStoreRead: '<S116>/Data Store Read'
     *  DataTypeConversion: '<S116>/Data Type Conversion2'
     *  DataTypeConversion: '<S116>/Data Type Conversion6'
     *  UnaryMinus: '<S116>/Unary Minus'
     *  UnaryMinus: '<S116>/Unary Minus2'
     */
    if (rtu_pass1 > 0.0) {
      rtb_deltafalllimit = -(float64)Par_AutoBrightLevel091;
    } else {
      rtb_deltafalllimit = -(float64)rtu_Var_BrightMaxValue;
    }

    /* End of Switch: '<S116>/Switch4' */

    /* Product: '<S119>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S119>/sample time'
     *
     * About '<S119>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_deltafalllimit *= elapseTime;

    /* Switch: '<S120>/Switch' incorporates:
     *  RelationalOperator: '<S120>/UpperRelop'
     */
    if (rtb_Add1_m >= rtb_deltafalllimit) {
      /* Switch: '<S120>/Switch2' */
      rtb_deltafalllimit = rtb_Add1_m;
    }

    /* End of Switch: '<S120>/Switch' */
  }

  /* End of Switch: '<S120>/Switch2' */

  /* Sum: '<S119>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S119>/Delay Input2'
   *
   * Block description for '<S119>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S119>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_deltafalllimit;

  /* Switch: '<S106>/Switch1' incorporates:
   *  Constant: '<S106>/Constant7'
   */
  if (rtu_Trigger1_FO > 0) {
    uint16 rtb_Switch9;

    /* Switch: '<S116>/Switch9' */
    if (rtu_pass1 > 0.0) {
      /* Switch: '<S116>/Switch9' incorporates:
       *  DataTypeConversion: '<S116>/Data Type Conversion2'
       */
      rtb_Switch9 = rtu_Var_BrightMaxValue;
    } else {
      /* DataTypeConversion: '<S116>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S119>/Delay Input2'
       *
       * Block description for '<S119>/Delay Input2':
       *
       *  Store in Global RAM
       */
      elapseTime = fmod(floor(localDW->DelayInput2_DSTATE), 65536.0);

      /* Switch: '<S116>/Switch9' incorporates:
       *  DataTypeConversion: '<S116>/Data Type Conversion1'
       */
      rtb_Switch9 = (uint16)(elapseTime < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-elapseTime : (sint32)(uint16)elapseTime);
    }

    /* End of Switch: '<S116>/Switch9' */

    /* Switch: '<S117>/Switch2' incorporates:
     *  RelationalOperator: '<S117>/LowerRelop1'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      /* Switch: '<S117>/Switch2' */
      *rty_y_FadeOut1 = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S117>/Switch2' incorporates:
       *  Switch: '<S117>/Switch'
       */
      *rty_y_FadeOut1 = rtb_Switch9;
    }

    /* End of Switch: '<S117>/Switch2' */
  } else {
    *rty_y_FadeOut1 = 0U;
  }

  /* End of Switch: '<S106>/Switch1' */

  /* Update for UnitDelay: '<S115>/Delay Input1'
   *
   * Block description for '<S115>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System reset for function-call system:
 *    '<S90>/FadeIn2'
 *    '<S138>/FadeIn2'
 *    '<S42>/FadeIn2'
 *    '<S270>/FadeIn2'
 *    '<S318>/FadeIn2'
 *    '<S222>/FadeIn2'
 */
void App_Model_FadeIn2_Reset(DW_FadeIn2_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S111>/Delay Input1'
   *
   * Block description for '<S111>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S104>/Switch1' incorporates:
   *  UnitDelay: '<S104>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S90>/FadeIn2'
 *    '<S138>/FadeIn2'
 *    '<S42>/FadeIn2'
 *    '<S270>/FadeIn2'
 *    '<S318>/FadeIn2'
 *    '<S222>/FadeIn2'
 */
void App_Model_FadeIn2(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger2, float64 rtu_pass2, uint16 *rty_y_FadeIn2, DW_FadeIn2_App_Model_T *localDW)
{
  float64 rtb_Switch_eg;

  /* Switch: '<S104>/Switch3' incorporates:
   *  DataTypeConversion: '<S104>/Data Type Conversion'
   *  Logic: '<S104>/AND'
   *  RelationalOperator: '<S111>/FixPt Relational Operator'
   *  Switch: '<S104>/Switch'
   *  Switch: '<S104>/Switch1'
   *  UnitDelay: '<S111>/Delay Input1'
   *
   * Block description for '<S111>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger2 != 0) && (rtu_pass2 != 0.0)) {
    /* Switch: '<S104>/Switch1' incorporates:
     *  UnitDelay: '<S104>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = rtu_Var_BrightMaxValue;
  } else {
    if (rtu_Trigger2 > 0) {
      /* Switch: '<S104>/Switch' incorporates:
       *  Constant: '<S104>/Constant2'
       *  Product: '<S104>/Divide'
       */
      rtb_Switch_eg = (float64)rtu_Var_BrightMaxValue / 100.0;
    } else {
      /* Switch: '<S104>/Switch' incorporates:
       *  Constant: '<S104>/Constant1'
       */
      rtb_Switch_eg = 0.0;

      /* Switch: '<S104>/Switch1' incorporates:
       *  Constant: '<S104>/Constant3'
       */
      localDW->UnitDelay_DSTATE = 0.0;
    }

    /* Switch: '<S104>/Switch1' incorporates:
     *  Sum: '<S104>/Add1'
     *  UnitDelay: '<S104>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE += rtb_Switch_eg;
  }

  /* End of Switch: '<S104>/Switch3' */

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S104>/Constant4'
   */
  if (rtu_Trigger2 > 0) {
    /* Switch: '<S104>/Switch5' */
    if (rtu_pass2 > 0.0) {
      /* Switch: '<S104>/Switch5' incorporates:
       *  DataTypeConversion: '<S104>/Data Type Conversion'
       */
      rtb_Switch_eg = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S104>/Switch5' incorporates:
       *  UnitDelay: '<S104>/Unit Delay'
       */
      rtb_Switch_eg = localDW->UnitDelay_DSTATE;
    }

    /* End of Switch: '<S104>/Switch5' */

    /* Switch: '<S112>/Switch2' incorporates:
     *  DataTypeConversion: '<S104>/Data Type Conversion'
     *  RelationalOperator: '<S112>/LowerRelop1'
     *  RelationalOperator: '<S112>/UpperRelop'
     *  Switch: '<S112>/Switch'
     */
    if (rtb_Switch_eg > rtu_Var_BrightMaxValue) {
      rtb_Switch_eg = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch_eg < 0.0) {
      /* Switch: '<S112>/Switch' incorporates:
       *  Constant: '<S104>/Constant4'
       */
      rtb_Switch_eg = 0.0;
    }

    /* End of Switch: '<S112>/Switch2' */
    rtb_Switch_eg = fmod(floor(rtb_Switch_eg), 65536.0);
    *rty_y_FadeIn2 = (uint16)(rtb_Switch_eg < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-rtb_Switch_eg : (sint32)(uint16)rtb_Switch_eg);
  } else {
    *rty_y_FadeIn2 = 0U;
  }

  /* End of Switch: '<S104>/Switch2' */

  /* Update for UnitDelay: '<S111>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S104>/Data Type Conversion'
   *
   * Block description for '<S111>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System reset for function-call system:
 *    '<S90>/FadeOut2'
 *    '<S138>/FadeOut2'
 *    '<S42>/FadeOut2'
 *    '<S270>/FadeOut2'
 *    '<S318>/FadeOut2'
 *    '<S222>/FadeOut2'
 */
void App_Model_FadeOut2_Reset(DW_FadeOut2_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S125>/Delay Input2'
   *
   * Block description for '<S125>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S90>/FadeOut2'
 *    '<S138>/FadeOut2'
 *    '<S42>/FadeOut2'
 *    '<S270>/FadeOut2'
 *    '<S318>/FadeOut2'
 *    '<S222>/FadeOut2'
 */
void App_Model_FadeOut2_Enable(DW_FadeOut2_App_Model_T *localDW)
{
  localDW->FadeOut2_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S90>/FadeOut2'
 *    '<S138>/FadeOut2'
 *    '<S42>/FadeOut2'
 *    '<S270>/FadeOut2'
 *    '<S318>/FadeOut2'
 *    '<S222>/FadeOut2'
 */
void App_Model_FadeOut2(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger2_FO, float64 rtu_pass2, uint16 *rty_y_FadeOut2,
  DW_FadeOut2_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_l;
  float64 rtb_deltafalllimit;
  if (localDW->FadeOut2_RESET_ELAPS_T) {
    localDW->FadeOut2_ELAPS_T = 0U;
  } else {
    localDW->FadeOut2_ELAPS_T = App_Model_M->Timing.clockTick0 - localDW->FadeOut2_PREV_T;
  }

  localDW->FadeOut2_PREV_T = App_Model_M->Timing.clockTick0;
  localDW->FadeOut2_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S125>/sample time'
   *
   * About '<S125>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (float64)localDW->FadeOut2_ELAPS_T * 0.01;

  /* Switch: '<S126>/Switch2' incorporates:
   *  DataTypeConversion: '<S122>/Data Type Conversion2'
   *  Product: '<S125>/delta rise limit'
   *  SampleTimeMath: '<S125>/sample time'
   *
   * About '<S125>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltafalllimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S107>/Switch8' incorporates:
   *  Logic: '<S107>/AND'
   *  RelationalOperator: '<S121>/FixPt Relational Operator'
   *  Switch: '<S107>/Switch7'
   *  UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger2_FO != 0) && (rtu_pass2 != 0.0)) {
    /* Switch: '<S107>/Switch8' */
    rtb_Add1_l = rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger2_FO > 0) {
    /* Sum: '<S107>/Add1' incorporates:
     *  Constant: '<S107>/Constant5'
     *  Product: '<S107>/Divide'
     *  Switch: '<S107>/Switch'
     *  Switch: '<S107>/Switch5'
     *  Switch: '<S107>/Switch7'
     */
    rtb_Add1_l = (float64)rtu_preValue - (float64)rtu_Var_BrightMaxValue / 100.0;

    /* Switch: '<S124>/Switch2' incorporates:
     *  RelationalOperator: '<S124>/LowerRelop1'
     *  RelationalOperator: '<S124>/UpperRelop'
     *  Switch: '<S107>/Switch7'
     *  Switch: '<S124>/Switch'
     */
    if (rtb_Add1_l > rtu_preValue) {
      /* Switch: '<S107>/Switch8' incorporates:
       *  Switch: '<S124>/Switch2'
       */
      rtb_Add1_l = rtu_preValue;
    } else if (rtb_Add1_l < 0.0) {
      /* Switch: '<S124>/Switch' incorporates:
       *  Constant: '<S107>/Constant2'
       *  Switch: '<S107>/Switch8'
       *  Switch: '<S124>/Switch2'
       */
      rtb_Add1_l = 0.0;
    }

    /* End of Switch: '<S124>/Switch2' */
  } else {
    /* Switch: '<S107>/Switch8' incorporates:
     *  Constant: '<S107>/Constant2'
     *  Switch: '<S107>/Switch7'
     */
    rtb_Add1_l = 0.0;
  }

  /* End of Switch: '<S107>/Switch8' */

  /* Sum: '<S125>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S125>/Delay Input2'
   *
   * Block description for '<S125>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S125>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_l -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S126>/Switch2' incorporates:
   *  RelationalOperator: '<S126>/LowerRelop1'
   */
  if (rtb_Add1_l <= rtb_deltafalllimit) {
    /* Switch: '<S122>/Switch4' incorporates:
     *  DataStoreRead: '<S122>/Data Store Read'
     *  DataTypeConversion: '<S122>/Data Type Conversion2'
     *  DataTypeConversion: '<S122>/Data Type Conversion6'
     *  UnaryMinus: '<S122>/Unary Minus'
     *  UnaryMinus: '<S122>/Unary Minus2'
     */
    if (rtu_pass2 > 0.0) {
      rtb_deltafalllimit = -(float64)Par_AutoBrightLevel091;
    } else {
      rtb_deltafalllimit = -(float64)rtu_Var_BrightMaxValue;
    }

    /* End of Switch: '<S122>/Switch4' */

    /* Product: '<S125>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S125>/sample time'
     *
     * About '<S125>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_deltafalllimit *= elapseTime;

    /* Switch: '<S126>/Switch' incorporates:
     *  RelationalOperator: '<S126>/UpperRelop'
     */
    if (rtb_Add1_l >= rtb_deltafalllimit) {
      /* Switch: '<S126>/Switch2' */
      rtb_deltafalllimit = rtb_Add1_l;
    }

    /* End of Switch: '<S126>/Switch' */
  }

  /* End of Switch: '<S126>/Switch2' */

  /* Sum: '<S125>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S125>/Delay Input2'
   *
   * Block description for '<S125>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S125>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_deltafalllimit;

  /* Switch: '<S107>/Switch1' incorporates:
   *  Constant: '<S107>/Constant7'
   */
  if (rtu_Trigger2_FO > 0) {
    uint16 rtb_Switch9;

    /* Switch: '<S122>/Switch9' */
    if (rtu_pass2 > 0.0) {
      /* Switch: '<S122>/Switch9' incorporates:
       *  DataTypeConversion: '<S122>/Data Type Conversion2'
       */
      rtb_Switch9 = rtu_Var_BrightMaxValue;
    } else {
      /* DataTypeConversion: '<S122>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S125>/Delay Input2'
       *
       * Block description for '<S125>/Delay Input2':
       *
       *  Store in Global RAM
       */
      elapseTime = fmod(floor(localDW->DelayInput2_DSTATE), 65536.0);

      /* Switch: '<S122>/Switch9' incorporates:
       *  DataTypeConversion: '<S122>/Data Type Conversion1'
       */
      rtb_Switch9 = (uint16)(elapseTime < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-elapseTime : (sint32)(uint16)elapseTime);
    }

    /* End of Switch: '<S122>/Switch9' */

    /* Switch: '<S123>/Switch2' incorporates:
     *  RelationalOperator: '<S123>/LowerRelop1'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      /* Switch: '<S123>/Switch2' */
      *rty_y_FadeOut2 = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S123>/Switch2' incorporates:
       *  Switch: '<S123>/Switch'
       */
      *rty_y_FadeOut2 = rtb_Switch9;
    }

    /* End of Switch: '<S123>/Switch2' */
  } else {
    *rty_y_FadeOut2 = 0U;
  }

  /* End of Switch: '<S107>/Switch1' */

  /* Update for UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System reset for function-call system:
 *    '<S90>/FadeIn3'
 *    '<S138>/FadeIn3'
 *    '<S42>/FadeIn3'
 *    '<S270>/FadeIn3'
 *    '<S318>/FadeIn3'
 *    '<S222>/FadeIn3'
 */
void App_Model_FadeIn3_Reset(DW_FadeIn3_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S113>/Delay Input1'
   *
   * Block description for '<S113>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Switch: '<S105>/Switch1' incorporates:
   *  UnitDelay: '<S105>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = 0.0;
}

/*
 * Output and update for function-call system:
 *    '<S90>/FadeIn3'
 *    '<S138>/FadeIn3'
 *    '<S42>/FadeIn3'
 *    '<S270>/FadeIn3'
 *    '<S318>/FadeIn3'
 *    '<S222>/FadeIn3'
 */
void App_Model_FadeIn3(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger3, float64 rtu_pass3, uint16 *rty_y_FadeIn3, DW_FadeIn3_App_Model_T *localDW)
{
  float64 rtb_Switch_gt;

  /* Switch: '<S105>/Switch3' incorporates:
   *  DataTypeConversion: '<S105>/Data Type Conversion'
   *  Logic: '<S105>/AND'
   *  RelationalOperator: '<S113>/FixPt Relational Operator'
   *  Switch: '<S105>/Switch'
   *  Switch: '<S105>/Switch1'
   *  UnitDelay: '<S113>/Delay Input1'
   *
   * Block description for '<S113>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3 != 0) && (rtu_pass3 != 0.0)) {
    /* Switch: '<S105>/Switch1' incorporates:
     *  UnitDelay: '<S105>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE = rtu_Var_BrightMaxValue;
  } else {
    if (rtu_Trigger3 > 0) {
      /* Switch: '<S105>/Switch' incorporates:
       *  Constant: '<S105>/Constant2'
       *  Product: '<S105>/Divide'
       */
      rtb_Switch_gt = (float64)rtu_Var_BrightMaxValue / 100.0;
    } else {
      /* Switch: '<S105>/Switch' incorporates:
       *  Constant: '<S105>/Constant1'
       */
      rtb_Switch_gt = 0.0;

      /* Switch: '<S105>/Switch1' incorporates:
       *  Constant: '<S105>/Constant3'
       */
      localDW->UnitDelay_DSTATE = 0.0;
    }

    /* Switch: '<S105>/Switch1' incorporates:
     *  Sum: '<S105>/Add1'
     *  UnitDelay: '<S105>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE += rtb_Switch_gt;
  }

  /* End of Switch: '<S105>/Switch3' */

  /* Switch: '<S105>/Switch2' incorporates:
   *  Constant: '<S105>/Constant4'
   */
  if (rtu_Trigger3 > 0) {
    /* Switch: '<S105>/Switch5' */
    if (rtu_pass3 > 0.0) {
      /* Switch: '<S105>/Switch5' incorporates:
       *  DataTypeConversion: '<S105>/Data Type Conversion'
       */
      rtb_Switch_gt = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S105>/Switch5' incorporates:
       *  UnitDelay: '<S105>/Unit Delay'
       */
      rtb_Switch_gt = localDW->UnitDelay_DSTATE;
    }

    /* End of Switch: '<S105>/Switch5' */

    /* Switch: '<S114>/Switch2' incorporates:
     *  DataTypeConversion: '<S105>/Data Type Conversion'
     *  RelationalOperator: '<S114>/LowerRelop1'
     *  RelationalOperator: '<S114>/UpperRelop'
     *  Switch: '<S114>/Switch'
     */
    if (rtb_Switch_gt > rtu_Var_BrightMaxValue) {
      rtb_Switch_gt = rtu_Var_BrightMaxValue;
    } else if (rtb_Switch_gt < 0.0) {
      /* Switch: '<S114>/Switch' incorporates:
       *  Constant: '<S105>/Constant4'
       */
      rtb_Switch_gt = 0.0;
    }

    /* End of Switch: '<S114>/Switch2' */
    rtb_Switch_gt = fmod(floor(rtb_Switch_gt), 65536.0);
    *rty_y_FadeIn3 = (uint16)(rtb_Switch_gt < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-rtb_Switch_gt : (sint32)(uint16)rtb_Switch_gt);
  } else {
    *rty_y_FadeIn3 = 0U;
  }

  /* End of Switch: '<S105>/Switch2' */

  /* Update for UnitDelay: '<S113>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S105>/Data Type Conversion'
   *
   * Block description for '<S113>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/*
 * System reset for function-call system:
 *    '<S90>/FadeOut3'
 *    '<S138>/FadeOut3'
 *    '<S42>/FadeOut3'
 */
void App_Model_FadeOut3_Reset(DW_FadeOut3_App_Model_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S127>/Delay Input1'
   *
   * Block description for '<S127>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S131>/Delay Input2'
   *
   * Block description for '<S131>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S90>/FadeOut3'
 *    '<S138>/FadeOut3'
 *    '<S42>/FadeOut3'
 */
void App_Model_FadeOut3_Enable(DW_FadeOut3_App_Model_T *localDW)
{
  localDW->FadeOut3_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S90>/FadeOut3'
 *    '<S138>/FadeOut3'
 *    '<S42>/FadeOut3'
 */
void App_Model_FadeOut3(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_c;
  float64 rtb_deltafalllimit;
  if (localDW->FadeOut3_RESET_ELAPS_T) {
    localDW->FadeOut3_ELAPS_T = 0U;
  } else {
    localDW->FadeOut3_ELAPS_T = App_Model_M->Timing.clockTick0 - localDW->FadeOut3_PREV_T;
  }

  localDW->FadeOut3_PREV_T = App_Model_M->Timing.clockTick0;
  localDW->FadeOut3_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S131>/sample time'
   *
   * About '<S131>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (float64)localDW->FadeOut3_ELAPS_T * 0.01;

  /* Switch: '<S132>/Switch2' incorporates:
   *  DataTypeConversion: '<S128>/Data Type Conversion2'
   *  Product: '<S131>/delta rise limit'
   *  SampleTimeMath: '<S131>/sample time'
   *
   * About '<S131>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltafalllimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S108>/Switch8' incorporates:
   *  Logic: '<S108>/AND'
   *  RelationalOperator: '<S127>/FixPt Relational Operator'
   *  Switch: '<S108>/Switch7'
   *  UnitDelay: '<S127>/Delay Input1'
   *
   * Block description for '<S127>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3_FO != 0) && (rtu_pass3 != 0.0)) {
    /* Switch: '<S108>/Switch8' */
    rtb_Add1_c = rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger3_FO > 0) {
    /* Sum: '<S108>/Add1' incorporates:
     *  Constant: '<S108>/Constant5'
     *  Product: '<S108>/Divide'
     *  Switch: '<S108>/Switch'
     *  Switch: '<S108>/Switch5'
     *  Switch: '<S108>/Switch7'
     */
    rtb_Add1_c = (float64)rtu_preValue - (float64)rtu_Var_BrightMaxValue / 100.0;

    /* Switch: '<S130>/Switch2' incorporates:
     *  RelationalOperator: '<S130>/LowerRelop1'
     *  RelationalOperator: '<S130>/UpperRelop'
     *  Switch: '<S108>/Switch7'
     *  Switch: '<S130>/Switch'
     */
    if (rtb_Add1_c > rtu_preValue) {
      /* Switch: '<S108>/Switch8' incorporates:
       *  Switch: '<S130>/Switch2'
       */
      rtb_Add1_c = rtu_preValue;
    } else if (rtb_Add1_c < 0.0) {
      /* Switch: '<S130>/Switch' incorporates:
       *  Constant: '<S108>/Constant2'
       *  Switch: '<S108>/Switch8'
       *  Switch: '<S130>/Switch2'
       */
      rtb_Add1_c = 0.0;
    }

    /* End of Switch: '<S130>/Switch2' */
  } else {
    /* Switch: '<S108>/Switch8' incorporates:
     *  Constant: '<S108>/Constant2'
     *  Switch: '<S108>/Switch7'
     */
    rtb_Add1_c = 0.0;
  }

  /* End of Switch: '<S108>/Switch8' */

  /* Sum: '<S131>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S131>/Delay Input2'
   *
   * Block description for '<S131>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S131>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_c -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S132>/Switch2' incorporates:
   *  RelationalOperator: '<S132>/LowerRelop1'
   */
  if (rtb_Add1_c <= rtb_deltafalllimit) {
    /* Switch: '<S128>/Switch4' incorporates:
     *  DataStoreRead: '<S128>/Data Store Read'
     *  DataTypeConversion: '<S128>/Data Type Conversion2'
     *  DataTypeConversion: '<S128>/Data Type Conversion6'
     *  UnaryMinus: '<S128>/Unary Minus'
     *  UnaryMinus: '<S128>/Unary Minus2'
     */
    if (rtu_pass3 > 0.0) {
      rtb_deltafalllimit = -(float64)Par_AutoBrightLevel091;
    } else {
      rtb_deltafalllimit = -(float64)rtu_Var_BrightMaxValue;
    }

    /* End of Switch: '<S128>/Switch4' */

    /* Product: '<S131>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S131>/sample time'
     *
     * About '<S131>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_deltafalllimit *= elapseTime;

    /* Switch: '<S132>/Switch' incorporates:
     *  RelationalOperator: '<S132>/UpperRelop'
     */
    if (rtb_Add1_c >= rtb_deltafalllimit) {
      /* Switch: '<S132>/Switch2' */
      rtb_deltafalllimit = rtb_Add1_c;
    }

    /* End of Switch: '<S132>/Switch' */
  }

  /* End of Switch: '<S132>/Switch2' */

  /* Sum: '<S131>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S131>/Delay Input2'
   *
   * Block description for '<S131>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S131>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_deltafalllimit;

  /* Switch: '<S108>/Switch1' incorporates:
   *  Constant: '<S108>/Constant7'
   */
  if (rtu_Trigger3_FO > 0) {
    uint16 rtb_Switch9;

    /* Switch: '<S128>/Switch9' */
    if (rtu_pass3 > 0.0) {
      /* Switch: '<S128>/Switch9' incorporates:
       *  DataTypeConversion: '<S128>/Data Type Conversion2'
       */
      rtb_Switch9 = rtu_Var_BrightMaxValue;
    } else {
      /* DataTypeConversion: '<S128>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S131>/Delay Input2'
       *
       * Block description for '<S131>/Delay Input2':
       *
       *  Store in Global RAM
       */
      elapseTime = fmod(floor(localDW->DelayInput2_DSTATE), 65536.0);

      /* Switch: '<S128>/Switch9' incorporates:
       *  DataTypeConversion: '<S128>/Data Type Conversion1'
       */
      rtb_Switch9 = (uint16)(elapseTime < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-elapseTime : (sint32)(uint16)elapseTime);
    }

    /* End of Switch: '<S128>/Switch9' */

    /* Switch: '<S129>/Switch2' incorporates:
     *  RelationalOperator: '<S129>/LowerRelop1'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      /* Switch: '<S129>/Switch2' */
      *rty_y_FadeOut3 = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S129>/Switch2' incorporates:
       *  Switch: '<S129>/Switch'
       */
      *rty_y_FadeOut3 = rtb_Switch9;
    }

    /* End of Switch: '<S129>/Switch2' */
  } else {
    *rty_y_FadeOut3 = 0U;
  }

  /* End of Switch: '<S108>/Switch1' */

  /* Update for UnitDelay: '<S127>/Delay Input1'
   *
   * Block description for '<S127>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control1(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_c, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = 0U;
    localDW->pass1 = 0.0;

    /* Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut  ||... */
  } else if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState ==
              WPCIndCmdState__2ndChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn)) {
    /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_c, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    localDW->pass1 = 0.0;
  } else if (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) {
    if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 1.0)) {
      localDW->pass1 = 1.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 1.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 1, 1.0, &localB->Switch2_c, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_c;
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_f = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue, 0, 0.0, &localB->Switch1_o, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S90>/FadeOut1' */
    } else {
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 1, 0.0, &localB->Switch2_c, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_c;
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_f = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue, 0, 0.0, &localB->Switch1_o, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S90>/FadeOut1' */
      localDW->pass1 = 0.0;
    }
  }

  if (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) {
    if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 2.0)) {
      localDW->pass1 = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_c, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_f = 1.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue, 0, 1.0, &localB->Switch1_o, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S90>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 1;
      localB->pass1_f = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue, 1, 0.0, &localB->Switch1_o, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S90>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch1_o;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_c, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
      localDW->pass1 = 0.0;
    }
  }
}

/* Function for Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control2(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 0, 0.0, &localB->Switch2_g, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = 0U;
    localDW->pass2 = 0.0;
  } else if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState ==
              WPCIndCmdState__3rdChrgOn)) {
    localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 0, 0.0, &localB->Switch2_g, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    localDW->pass2 = 0.0;
  } else if (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) {
    if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 1.0)) {
      localDW->pass2 = 1.0;
      localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 1.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 1, 1.0, &localB->Switch2_g, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_g;
      localB->Var_BrightMaxValue_a = rtu_Var_BrightMaxValue;
      localB->preValue_f = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_a = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_a, localB->preValue_f, 0, 0.0, &localB->Switch1_d, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S90>/FadeOut2' */
    } else {
      localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 1, 0.0, &localB->Switch2_g, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_g;
      localB->Var_BrightMaxValue_a = rtu_Var_BrightMaxValue;
      localB->preValue_f = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_a = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_a, localB->preValue_f, 0, 0.0, &localB->Switch1_d, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S90>/FadeOut2' */
      localDW->pass2 = 0.0;
    }
  }

  if (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) {
    if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 2.0)) {
      localDW->pass2 = 2.0;
      localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 0, 0.0, &localB->Switch2_g, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
      localB->Var_BrightMaxValue_a = rtu_Var_BrightMaxValue;
      localB->preValue_f = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_a = 1.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_a, localB->preValue_f, 0, 1.0, &localB->Switch1_d, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S90>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_a = rtu_Var_BrightMaxValue;
      localB->preValue_f = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 1;
      localB->pass2_a = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_a, localB->preValue_f, 1, 0.0, &localB->Switch1_d, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S90>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch1_d;
      localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 0, 0.0, &localB->Switch2_g, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
      localDW->pass2 = 0.0;
    }
  }
}

/* Function for Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control3(uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
    *rty_Var_GreenINDwithAnimation3 = 0U;
    localDW->pass3 = 0.0;
  } else {
    switch (rtu_Input_INT_WPCIndCmdState) {
     case WPCIndCmdState__3rdChrgOn:
      localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
      localDW->pass3 = 0.0;
      break;

     case WPCIndCmdState__3rdChrgFadeIn:
      if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 1.0)) {
        localDW->pass3 = 1.0;
        localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 1.0;

        /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 1, 1.0, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
        localB->preValue_j = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_j = 0.0;

        /* Outputs for Function Call SubSystem: '<S90>/FadeOut3' */
        App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue_j, 0, 0.0, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S90>/FadeOut3' */
      } else {
        localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 0.0;

        /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 1, 0.0, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
        localB->preValue_j = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_j = 0.0;

        /* Outputs for Function Call SubSystem: '<S90>/FadeOut3' */
        App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue_j, 0, 0.0, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S90>/FadeOut3' */
        localDW->pass3 = 0.0;
      }
      break;
    }
  }

  if (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) {
    if (((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 2.0)) {
      localDW->pass3 = 2.0;
      localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
      localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
      localB->preValue_j = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 0;
      localB->pass3_j = 1.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut3' */
      App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue_j, 0, 1.0, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S90>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
      localB->preValue_j = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 1;
      localB->pass3_j = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeOut3' */
      App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue_j, 1, 0.0, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S90>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = localB->Switch1;
      localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
      localDW->pass3 = 0.0;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S133>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S37>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_C_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3)
{
  *rty_Var_GreenINDwithAnimation1 = 0U;
  *rty_Var_GreenINDwithAnimation2 = 0U;
  *rty_Var_GreenINDwithAnimation3 = 0U;
}

/*
 * Enable for atomic system:
 *    '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S133>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S37>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_Enable(DW_Green_IND_with_Animation_C_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S90>/FadeIn1' */
  App_Model_FadeIn1_Reset(&localDW->FadeIn1);

  /* End of SystemReset for SubSystem: '<S90>/FadeIn1' */

  /* SystemReset for Function Call SubSystem: '<S90>/FadeOut1' */
  App_Model_FadeOut1_Reset(&localDW->FadeOut1);

  /* End of SystemReset for SubSystem: '<S90>/FadeOut1' */

  /* Enable for Function Call SubSystem: '<S90>/FadeOut1' */
  App_Model_FadeOut1_Enable(&localDW->FadeOut1);

  /* End of Enable for SubSystem: '<S90>/FadeOut1' */

  /* SystemReset for Function Call SubSystem: '<S90>/FadeIn2' */
  App_Model_FadeIn2_Reset(&localDW->FadeIn2);

  /* End of SystemReset for SubSystem: '<S90>/FadeIn2' */

  /* SystemReset for Function Call SubSystem: '<S90>/FadeOut2' */
  App_Model_FadeOut2_Reset(&localDW->FadeOut2);

  /* End of SystemReset for SubSystem: '<S90>/FadeOut2' */

  /* Enable for Function Call SubSystem: '<S90>/FadeOut2' */
  App_Model_FadeOut2_Enable(&localDW->FadeOut2);

  /* End of Enable for SubSystem: '<S90>/FadeOut2' */

  /* SystemReset for Function Call SubSystem: '<S90>/FadeIn3' */
  App_Model_FadeIn3_Reset(&localDW->FadeIn3);

  /* End of SystemReset for SubSystem: '<S90>/FadeIn3' */

  /* SystemReset for Function Call SubSystem: '<S90>/FadeOut3' */
  App_Model_FadeOut3_Reset(&localDW->FadeOut3);

  /* End of SystemReset for SubSystem: '<S90>/FadeOut3' */

  /* Enable for Function Call SubSystem: '<S90>/FadeOut3' */
  App_Model_FadeOut3_Enable(&localDW->FadeOut3);

  /* End of Enable for SubSystem: '<S90>/FadeOut3' */
}

/*
 * Output and update for atomic system:
 *    '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S133>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S37>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if (localDW->is_active_c427_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c427_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_c, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S90>/FadeIn1' */
    localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_GreenINDwithAnimation1;
    localB->Trigger1_FO = 0;
    localB->pass1_f = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeOut1' */
    App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue, 0, 0.0, &localB->Switch1_o, &localDW->FadeOut1);

    /* End of Outputs for SubSystem: '<S90>/FadeOut1' */
    *rty_Var_GreenINDwithAnimation1 = 0U;

    /* 1. In the case of 1st LED */
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn)
        || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /*  ||Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 1st LED, Abnormal */
      *rty_Var_GreenINDwithAnimation1 = 0U;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_pw = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_pw, 0, 0.0, &localB->Switch2_g, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S90>/FadeIn2' */
    localB->Var_BrightMaxValue_a = rtu_Var_BrightMaxValue;
    localB->preValue_f = *rty_Var_GreenINDwithAnimation2;
    localB->Trigger2_FO = 0;
    localB->pass2_a = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeOut2' */
    App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_a, localB->preValue_f, 0, 0.0, &localB->Switch1_d, &localDW->FadeOut2);

    /* End of Outputs for SubSystem: '<S90>/FadeOut2' */
    *rty_Var_GreenINDwithAnimation2 = 0U;

    /* 1. In the case of 2nd LED */
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 2nd LED Off */
      *rty_Var_GreenINDwithAnimation2 = 0U;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_c = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_c, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S90>/FadeIn3' */
    localB->Var_BrightMaxValue_g = rtu_Var_BrightMaxValue;
    localB->preValue_j = *rty_Var_GreenINDwithAnimation3;
    localB->Trigger3_FO = 0;
    localB->pass3_j = 0.0;

    /* Outputs for Function Call SubSystem: '<S90>/FadeOut3' */
    App_Model_FadeOut3(App_Model_M, localB->Var_BrightMaxValue_g, localB->preValue_j, 0, 0.0, &localB->Switch1, &localDW->FadeOut3);

    /* End of Outputs for SubSystem: '<S90>/FadeOut3' */
    *rty_Var_GreenINDwithAnimation3 = 0U;

    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 3rd LED Off */
      *rty_Var_GreenINDwithAnimation3 = 0U;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1. In the case of 1st LED */
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn)
        || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /*  ||Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut  ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 1st LED, Abnormal */
      *rty_Var_GreenINDwithAnimation1 = 0U;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 2nd LED */
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 2nd LED Off */
      *rty_Var_GreenINDwithAnimation2 = 0U;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff)) {
      /* ||Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeOut ||Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3(rtu_Var_BrightMaxValue, rtu_Input_INT_WPCIndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 3rd LED Off */
      *rty_Var_GreenINDwithAnimation3 = 0U;
    }
  }

  /* End of Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for atomic system:
 *    '<S85>/IND_Output_Control_Function_Flow_Graph'
 *    '<S133>/IND_Output_Control_Function_Flow_Graph'
 *    '<S37>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Functio_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT)
{
  *rty_Output_AmberIND_OUT = 0U;
  *rty_Output_GreenIND_OUT = 0U;
  *rty_Output_GreenIND2_OUT = 0U;
  *rty_Output_GreenIND3_OUT = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S85>/IND_Output_Control_Function_Flow_Graph'
 *    '<S133>/IND_Output_Control_Function_Flow_Graph'
 *    '<S37>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Function_Flo(WPCIndCmdState rtu_Input_INT_WPCIndCmdState, WPCIndUSMState rtu_Var_INT_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Functio_T *localDW)
{
  /* Chart: '<S85>/IND_Output_Control_Function_Flow_Graph' */
  if (localDW->is_active_c428_IndyOutputContro == 0U) {
    localDW->is_active_c428_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Output_GreenIND_OUT = 0U;
    *rty_Output_GreenIND2_OUT = 0U;
    *rty_Output_GreenIND3_OUT = 0U;
    *rty_Output_AmberIND_OUT = 0U;

    /* Ref_Off */
    /* 1 */
    if (rtu_Var_INT_WPCIndUSMState == WPCIndUSMState__Type2) {
      if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) ||
          (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState ==
           WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut) ||
          (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || (rtu_Input_INT_WPCIndCmdState ==
           WPCIndCmdState__3rdChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2)) {
        /* 231010 */
        /* Green IND Light */
        *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
        *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
        *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
        *rty_Output_AmberIND_OUT = 0U;
      } else if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPCIndCmdState ==
                  WPCIndCmdState__ErrorFadeOut)) {
        /* Amber IND light */
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
      } else {
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = 0U;

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
  } else if (rtu_Var_INT_WPCIndUSMState == WPCIndUSMState__Type2) {
    if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__Default) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgOff) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeIn) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__1stChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__2ndChrgFadeOut) ||
        (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || (rtu_Input_INT_WPCIndCmdState ==
         WPCIndCmdState__3rdChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ChrgFadeOut3_2)) {
      /* 231010 */
      /* Green IND Light */
      *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
      *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
      *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
      *rty_Output_AmberIND_OUT = 0U;
    } else if ((rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorOn) || (rtu_Input_INT_WPCIndCmdState == WPCIndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPCIndCmdState ==
                WPCIndCmdState__ErrorFadeOut)) {
      /* Amber IND light */
      *rty_Output_GreenIND_OUT = 0U;
      *rty_Output_GreenIND2_OUT = 0U;
      *rty_Output_GreenIND3_OUT = 0U;
      *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
    } else {
      *rty_Output_GreenIND_OUT = 0U;
      *rty_Output_GreenIND2_OUT = 0U;
      *rty_Output_GreenIND3_OUT = 0U;
      *rty_Output_AmberIND_OUT = 0U;

      /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
         Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
    }
  } else {
    *rty_Output_GreenIND_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND2_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND3_OUT = rtu_Var_GreenIND;
    *rty_Output_AmberIND_OUT = rtu_Var_AmberIND;
  }

  /* End of Chart: '<S85>/IND_Output_Control_Function_Flow_Graph' */
}

/* Function for Chart: '<S85>/WPC_IND_Output_Control_Function' */
static void WPC_IND_Output_Control_Functi_d(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue)
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
 *    '<S85>/WPC_IND_Output_Control_Function'
 *    '<S133>/WPC_IND_Output_Control_Function'
 *    '<S265>/WPC_IND_Output_Control_Function'
 *    '<S313>/WPC_IND_Output_Control_Function'
 */
void WPC_IND_Output_Control_Fun_Init(uint16 *rty_RheoLevelValue)
{
  *rty_RheoLevelValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S85>/WPC_IND_Output_Control_Function'
 *    '<S133>/WPC_IND_Output_Control_Function'
 *    '<S265>/WPC_IND_Output_Control_Function'
 *    '<S313>/WPC_IND_Output_Control_Function'
 */
void WPC_IND_Output_Control_Function(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue, DW_WPC_IND_Output_Control_Fun_T *localDW)
{
  /* Chart: '<S85>/WPC_IND_Output_Control_Function' */
  if (localDW->is_active_c343_IndyOutputContro == 0U) {
    localDW->is_active_c343_IndyOutputContro = 1U;
    WPC_IND_Output_Control_Functi_d(rtu_Input_RheoStatLevel, rty_RheoLevelValue);
  } else {
    WPC_IND_Output_Control_Functi_d(rtu_Input_RheoStatLevel, rty_RheoLevelValue);
  }

  /* End of Chart: '<S85>/WPC_IND_Output_Control_Function' */
}

/*
 * System initialize for atomic system:
 *    '<S133>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S313>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_i_Init(uint16 *rty_Var_BrightMaxValue)
{
  *rty_Var_BrightMaxValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S133>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S313>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_Func_b(RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Control_n_T
  *localDW)
{
  /* Chart: '<S133>/Bright_Max_Value_Control_Function_Flow_Graph' */
  if (localDW->is_active_c356_IndyOutputContro == 0U) {
    localDW->is_active_c356_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_BrightMaxValue = Off;

    /* 1 */
    switch (rtu_Input_RheostatOption) {
     case RheostatOption_On:
      if (rtu_Input_b_IntTailOn == On) {
        *rty_Var_BrightMaxValue = rtu_RheoLevelValue;
      } else {
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;

     case RheostatOption_Off:
      if (rtu_Input_b_IntTailOn == On) {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
      } else {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1 */
    switch (rtu_Input_RheostatOption) {
     case RheostatOption_On:
      if (rtu_Input_b_IntTailOn == On) {
        *rty_Var_BrightMaxValue = rtu_RheoLevelValue;
      } else {
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;

     case RheostatOption_Off:
      if (rtu_Input_b_IntTailOn == On) {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel10;
      } else {
        /* 2 */
        *rty_Var_BrightMaxValue = Par_RheostatBrightLevel21;
      }
      break;
    }
  }

  /* End of Chart: '<S133>/Bright_Max_Value_Control_Function_Flow_Graph' */
}

/*
 * System initialize for atomic system:
 *    '<S37>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S217>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_m_Init(uint16 *rty_Var_BrightMaxValue)
{
  *rty_Var_BrightMaxValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S37>/Bright_Max_Value_Control_Function_Flow_Graph'
 *    '<S217>/Bright_Max_Value_Control_Function_Flow_Graph'
 */
void Bright_Max_Value_Control_Func_n(Bool rtu_Input_DetentOut, uint16 rtu_AutoBrightValue, uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Control_c_T *localDW)
{
  /* Chart: '<S37>/Bright_Max_Value_Control_Function_Flow_Graph' */
  if (localDW->is_active_c415_IndyOutputContro == 0U) {
    localDW->is_active_c415_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Var_BrightMaxValue = rtu_AutoBrightValue;

    /* 1 */
    if (rtu_Input_DetentOut == On) {
      *rty_Var_BrightMaxValue = Par_AutoBrightLevel091;
    }

    /*  Transition run every task on system operation */
    /* 1 */
  } else if (rtu_Input_DetentOut == On) {
    *rty_Var_BrightMaxValue = Par_AutoBrightLevel091;
  } else {
    *rty_Var_BrightMaxValue = rtu_AutoBrightValue;
  }

  /* End of Chart: '<S37>/Bright_Max_Value_Control_Function_Flow_Graph' */
}

/* Function for Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
static void enter_internal_c420_IndyOutputC(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue)
{
  /* Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
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
    if (rtu_Input_AutoBrightLevel >= Step91) {
      *rty_AutoBrightValue = Par_AutoBrightLevel091;
    } else {
      /* Old Value */
    }
    break;
  }

  /* End of Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
}

/*
 * System initialize for atomic system:
 *    '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S217>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 */
void WPC_IND_Output_With_Auto_B_Init(uint16 *rty_AutoBrightValue)
{
  *rty_AutoBrightValue = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 *    '<S217>/WPC_IND_Output_With_Auto_Bright_Control_Function'
 */
void WPC_IND_Output_With_Auto_Bright(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue, DW_WPC_IND_Output_With_Auto_B_T *localDW)
{
  /* Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  if (localDW->is_active_c420_IndyOutputContro == 0U) {
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
      if (rtu_Input_AutoBrightLevel >= Step91) {
        *rty_AutoBrightValue = Par_AutoBrightLevel091;
      } else {
        /* Old Value */
      }
      break;
    }
  }

  /* End of Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
}

/* System initialize for atomic system: '<S17>/IndyOutputControl_Function' */
void IndyOutputControl_Function_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_j, uint16 *rty_IndyOutput_Sig_i, uint16 *rty_IndyOutput_Sig_d)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT;
  uint16 rtb_Output_GreenIND_OUT;
  uint16 rtb_Output_GreenIND2_OUT;
  uint16 rtb_Output_GreenIND3_OUT;
  uint16 rtb_Var_GreenIND;
  uint16 rtb_Var_AmberIND;
  uint16 rtb_Output_AmberIND_OUT_e;
  uint16 rtb_Output_GreenIND_OUT_g;
  uint16 rtb_Output_GreenIND2_OUT_l;
  uint16 rtb_Output_GreenIND3_OUT_m;
  uint16 rtb_Var_GreenIND_k;
  uint16 rtb_Var_AmberIND_j;
  uint16 rtb_Output_AmberIND_OUT_g;
  uint16 rtb_Output_GreenIND_OUT_a;
  uint16 rtb_Output_GreenIND2_OUT_b;
  uint16 rtb_Output_GreenIND3_OUT_d;
  uint16 rtb_Var_GreenIND_i;
  uint16 rtb_Var_AmberIND_a;

  /* Start for SwitchCase: '<S23>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* SystemInitialize for IfAction SubSystem: '<S23>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for Chart: '<S85>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue_m);

  /* SystemInitialize for Chart: '<S85>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_Init(&App_Model_B.Var_BrightMaxValue_pr);

  /* SystemInitialize for Chart: '<S85>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_i);

  /* SystemInitialize for Chart: '<S85>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_a);

  /* SystemInitialize for Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_C_Init(&App_Model_B.Var_GreenINDwithAnimation1_d, &App_Model_B.Var_GreenINDwithAnimation2_a, &App_Model_B.Var_GreenINDwithAnimation3_k);

  /* SystemInitialize for Chart: '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_C_Init(&App_Model_B.Var_AmberINDwithAnimation_f);

  /* SystemInitialize for Chart: '<S85>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Functio_Init(&rtb_Output_AmberIND_OUT_g, &rtb_Output_GreenIND_OUT_a, &rtb_Output_GreenIND2_OUT_b, &rtb_Output_GreenIND3_OUT_d);

  /* End of SystemInitialize for SubSystem: '<S23>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for IfAction SubSystem: '<S23>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for Chart: '<S133>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue_h);

  /* SystemInitialize for Chart: '<S133>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_i_Init(&App_Model_B.Var_BrightMaxValue_cw);

  /* SystemInitialize for Chart: '<S133>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_k);

  /* SystemInitialize for Chart: '<S133>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_j);

  /* SystemInitialize for Chart: '<S133>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_C_Init(&App_Model_B.Var_GreenINDwithAnimation1_m, &App_Model_B.Var_GreenINDwithAnimation2_nx, &App_Model_B.Var_GreenINDwithAnimation3_gx);

  /* SystemInitialize for Chart: '<S133>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_C_Init(&App_Model_B.Var_AmberINDwithAnimation_n);

  /* SystemInitialize for Chart: '<S133>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Functio_Init(&rtb_Output_AmberIND_OUT_e, &rtb_Output_GreenIND_OUT_g, &rtb_Output_GreenIND2_OUT_l, &rtb_Output_GreenIND3_OUT_m);

  /* End of SystemInitialize for SubSystem: '<S23>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for IfAction SubSystem: '<S23>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  WPC_IND_Output_With_Auto_B_Init(&App_Model_B.AutoBrightValue_m);

  /* SystemInitialize for Chart: '<S37>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_m_Init(&App_Model_B.Var_BrightMaxValue_p);

  /* SystemInitialize for Chart: '<S37>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND);

  /* SystemInitialize for Chart: '<S37>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_C_Init(&App_Model_B.Var_AmberINDwithAnimation_e);

  /* SystemInitialize for Chart: '<S37>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND);

  /* SystemInitialize for Chart: '<S37>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_C_Init(&App_Model_B.Var_GreenINDwithAnimation1_o, &App_Model_B.Var_GreenINDwithAnimation2_n, &App_Model_B.Var_GreenINDwithAnimation3_g);

  /* SystemInitialize for Chart: '<S37>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Functio_Init(&rtb_Output_AmberIND_OUT, &rtb_Output_GreenIND_OUT, &rtb_Output_GreenIND2_OUT, &rtb_Output_GreenIND3_OUT);

  /* End of SystemInitialize for SubSystem: '<S23>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Merge generated from: '<S23>/Merge' */
  *rty_IndyOutput_Sig = 0U;

  /* SystemInitialize for Merge generated from: '<S23>/Merge' */
  *rty_IndyOutput_Sig_j = 0U;

  /* SystemInitialize for Merge generated from: '<S23>/Merge' */
  *rty_IndyOutput_Sig_i = 0U;

  /* SystemInitialize for Merge generated from: '<S23>/Merge' */
  *rty_IndyOutput_Sig_d = 0U;
}

/* Disable for atomic system: '<S17>/IndyOutputControl_Function' */
void IndyOutputControl_Funct_Disable(void)
{
  /* Disable for SwitchCase: '<S23>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem_d = -1;
}

/* Output and update for atomic system: '<S17>/IndyOutputControl_Function' */
void App__IndyOutputControl_Function(INDContType rtu_PostProcessIn, Bool rtu_PostProcessIn_j, Bool rtu_PostProcessIn_i, WPCIndCmdState rtu_PostProcessIn_d, Bool rtu_PostProcessIn_f, RheostatOption
  rtu_PostProcessIn_k, Bool rtu_PostProcessIn_jn, Bool rtu_PostProcessIn_p, WPCIndUSMState rtu_PostProcessIn_dz, C_RheoStatLevel rtu_PostProcessIn_o, C_AutoBrightLevel rtu_PostProcessIn_b, uint16
  *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_j, uint16 *rty_IndyOutput_Sig_i, uint16 *rty_IndyOutput_Sig_d)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT;
  uint16 rtb_Output_GreenIND_OUT;
  uint16 rtb_Output_GreenIND2_OUT;
  uint16 rtb_Output_GreenIND3_OUT;
  uint16 rtb_Var_GreenIND;
  uint16 rtb_Var_AmberIND;
  uint16 rtb_Output_AmberIND_OUT_e;
  uint16 rtb_Output_GreenIND_OUT_g;
  uint16 rtb_Output_GreenIND2_OUT_l;
  uint16 rtb_Output_GreenIND3_OUT_m;
  uint16 rtb_Var_GreenIND_k;
  uint16 rtb_Var_AmberIND_j;
  uint16 rtb_Output_AmberIND_OUT_g;
  uint16 rtb_Output_GreenIND_OUT_a;
  uint16 rtb_Output_GreenIND2_OUT_b;
  uint16 rtb_Output_GreenIND3_OUT_d;
  uint16 rtb_Var_GreenIND_i;
  uint16 rtb_Var_AmberIND_a;
  sint8 rtPrevAction;

  /* SwitchCase: '<S23>/Switch Case' */
  rtPrevAction = App_Model_DW.SwitchCase_ActiveSubsystem_d;
  App_Model_DW.SwitchCase_ActiveSubsystem_d = -1;
  switch (rtu_PostProcessIn) {
   case INDConType1:
    App_Model_DW.SwitchCase_ActiveSubsystem_d = 0;
    break;

   case INDConType2:
    App_Model_DW.SwitchCase_ActiveSubsystem_d = 1;
    break;

   case INDConType3:
    App_Model_DW.SwitchCase_ActiveSubsystem_d = 2;
    break;
  }

  switch (App_Model_DW.SwitchCase_ActiveSubsystem_d) {
   case 0:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S23>/RheoStatIndyOutputControl_Type1' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Enable for SwitchCase: '<S23>/Switch Case' incorporates:
       *  Chart: '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Green_IND_with_Animation_Enable(&App_Model_DW.sf_Green_IND_with_Animation_Con);
      Amber_IND_with_Animation_Enable(&App_Model_DW.sf_Amber_IND_with_Animation_Con);

      /* End of Enable for SubSystem: '<S23>/RheoStatIndyOutputControl_Type1' */
    }

    /* Outputs for IfAction SubSystem: '<S23>/RheoStatIndyOutputControl_Type1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Chart: '<S85>/WPC_IND_Output_Control_Function' */
    WPC_IND_Output_Control_Function(rtu_PostProcessIn_o, &App_Model_B.RheoLevelValue_m, &App_Model_DW.sf_WPC_IND_Output_Control_Funct);

    /* Chart: '<S85>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Functi(rtu_PostProcessIn_f, rtu_PostProcessIn_k, rtu_PostProcessIn_jn, App_Model_B.RheoLevelValue_m, &App_Model_B.Var_BrightMaxValue_pr,
      &App_Model_DW.sf_Bright_Max_Value_Control_Fun);

    /* Chart: '<S85>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_p, App_Model_B.Var_BrightMaxValue_pr, &rtb_Var_GreenIND_i, &App_Model_DW.sf_Green_IND_Control_Function_F);

    /* Chart: '<S85>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_j, App_Model_B.Var_BrightMaxValue_pr, &rtb_Var_AmberIND_a, &App_Model_DW.sf_Amber_IND_Control_Function_F);

    /* Chart: '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_Contro(App_Model_M, App_Model_B.Var_BrightMaxValue_pr, rtu_PostProcessIn_d, &App_Model_B.Var_GreenINDwithAnimation1_d, &App_Model_B.Var_GreenINDwithAnimation2_a,
      &App_Model_B.Var_GreenINDwithAnimation3_k, &App_Model_B.sf_Green_IND_with_Animation_Con, &App_Model_DW.sf_Green_IND_with_Animation_Con);

    /* Chart: '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_Contro(App_Model_M, App_Model_B.Var_BrightMaxValue_pr, rtu_PostProcessIn_i, rtu_PostProcessIn_d, &App_Model_B.Var_AmberINDwithAnimation_f,
      &App_Model_B.sf_Amber_IND_with_Animation_Con, &App_Model_DW.sf_Amber_IND_with_Animation_Con);

    /* Chart: '<S85>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Function_Flo(rtu_PostProcessIn_d, rtu_PostProcessIn_dz, rtb_Var_GreenIND_i, rtb_Var_AmberIND_a, App_Model_B.Var_GreenINDwithAnimation2_a,
      App_Model_B.Var_GreenINDwithAnimation3_k, App_Model_B.Var_GreenINDwithAnimation1_d, App_Model_B.Var_AmberINDwithAnimation_f, &rtb_Output_AmberIND_OUT_g, &rtb_Output_GreenIND_OUT_a,
      &rtb_Output_GreenIND2_OUT_b, &rtb_Output_GreenIND3_OUT_d, &App_Model_DW.sf_IND_Output_Control_Function_);

    /* SignalConversion generated from: '<S35>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_d = rtb_Output_AmberIND_OUT_g;

    /* SignalConversion generated from: '<S35>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_j = rtb_Output_GreenIND2_OUT_b;

    /* SignalConversion generated from: '<S35>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_i = rtb_Output_GreenIND3_OUT_d;

    /* SignalConversion generated from: '<S35>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_a;

    /* End of Outputs for SubSystem: '<S23>/RheoStatIndyOutputControl_Type1' */
    break;

   case 1:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S23>/RheoStatIndyOutputControl_Type2' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* Enable for SwitchCase: '<S23>/Switch Case' incorporates:
       *  Chart: '<S133>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S133>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Green_IND_with_Animation_Enable(&App_Model_DW.sf_Green_IND_with_Animation_C_j);
      Amber_IND_with_Animation_Enable(&App_Model_DW.sf_Amber_IND_with_Animation_C_k);

      /* End of Enable for SubSystem: '<S23>/RheoStatIndyOutputControl_Type2' */
    }

    /* Outputs for IfAction SubSystem: '<S23>/RheoStatIndyOutputControl_Type2' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Chart: '<S133>/WPC_IND_Output_Control_Function' */
    WPC_IND_Output_Control_Function(rtu_PostProcessIn_o, &App_Model_B.RheoLevelValue_h, &App_Model_DW.sf_WPC_IND_Output_Control_Fun_b);

    /* Chart: '<S133>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Func_b(rtu_PostProcessIn_k, rtu_PostProcessIn_jn, App_Model_B.RheoLevelValue_h, &App_Model_B.Var_BrightMaxValue_cw, &App_Model_DW.sf_Bright_Max_Value_Control_F_b);

    /* Chart: '<S133>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_p, App_Model_B.Var_BrightMaxValue_cw, &rtb_Var_GreenIND_k, &App_Model_DW.sf_Green_IND_Control_Function_g);

    /* Chart: '<S133>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_j, App_Model_B.Var_BrightMaxValue_cw, &rtb_Var_AmberIND_j, &App_Model_DW.sf_Amber_IND_Control_Function_h);

    /* Chart: '<S133>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_Contro(App_Model_M, App_Model_B.Var_BrightMaxValue_cw, rtu_PostProcessIn_d, &App_Model_B.Var_GreenINDwithAnimation1_m, &App_Model_B.Var_GreenINDwithAnimation2_nx,
      &App_Model_B.Var_GreenINDwithAnimation3_gx, &App_Model_B.sf_Green_IND_with_Animation_C_j, &App_Model_DW.sf_Green_IND_with_Animation_C_j);

    /* Chart: '<S133>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_Contro(App_Model_M, App_Model_B.Var_BrightMaxValue_cw, rtu_PostProcessIn_i, rtu_PostProcessIn_d, &App_Model_B.Var_AmberINDwithAnimation_n,
      &App_Model_B.sf_Amber_IND_with_Animation_C_k, &App_Model_DW.sf_Amber_IND_with_Animation_C_k);

    /* Chart: '<S133>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Function_Flo(rtu_PostProcessIn_d, rtu_PostProcessIn_dz, rtb_Var_GreenIND_k, rtb_Var_AmberIND_j, App_Model_B.Var_GreenINDwithAnimation2_nx,
      App_Model_B.Var_GreenINDwithAnimation3_gx, App_Model_B.Var_GreenINDwithAnimation1_m, App_Model_B.Var_AmberINDwithAnimation_n, &rtb_Output_AmberIND_OUT_e, &rtb_Output_GreenIND_OUT_g,
      &rtb_Output_GreenIND2_OUT_l, &rtb_Output_GreenIND3_OUT_m, &App_Model_DW.sf_IND_Output_Control_Functio_j);

    /* SignalConversion generated from: '<S36>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_d = rtb_Output_AmberIND_OUT_e;

    /* SignalConversion generated from: '<S36>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_j = rtb_Output_GreenIND2_OUT_l;

    /* SignalConversion generated from: '<S36>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_i = rtb_Output_GreenIND3_OUT_m;

    /* SignalConversion generated from: '<S36>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_g;

    /* End of Outputs for SubSystem: '<S23>/RheoStatIndyOutputControl_Type2' */
    break;

   case 2:
    if (App_Model_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S23>/AutoBrightIndyOutputControl_Type3' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* Enable for SwitchCase: '<S23>/Switch Case' incorporates:
       *  Chart: '<S37>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S37>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Amber_IND_with_Animation_Enable(&App_Model_DW.sf_Amber_IND_with_Animation_C_f);
      Green_IND_with_Animation_Enable(&App_Model_DW.sf_Green_IND_with_Animation_C_o);

      /* End of Enable for SubSystem: '<S23>/AutoBrightIndyOutputControl_Type3' */
    }

    /* Outputs for IfAction SubSystem: '<S23>/AutoBrightIndyOutputControl_Type3' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* Chart: '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
    WPC_IND_Output_With_Auto_Bright(rtu_PostProcessIn_b, &App_Model_B.AutoBrightValue_m, &App_Model_DW.sf_WPC_IND_Output_With_Auto_Bri);

    /* Chart: '<S37>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Func_n(rtu_PostProcessIn_f, App_Model_B.AutoBrightValue_m, &App_Model_B.Var_BrightMaxValue_p, &App_Model_DW.sf_Bright_Max_Value_Control_F_n);

    /* Chart: '<S37>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_j, App_Model_B.Var_BrightMaxValue_p, &rtb_Var_AmberIND, &App_Model_DW.sf_Amber_IND_Control_Function_p);

    /* Chart: '<S37>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_Contro(App_Model_M, App_Model_B.Var_BrightMaxValue_p, rtu_PostProcessIn_i, rtu_PostProcessIn_d, &App_Model_B.Var_AmberINDwithAnimation_e,
      &App_Model_B.sf_Amber_IND_with_Animation_C_f, &App_Model_DW.sf_Amber_IND_with_Animation_C_f);

    /* Chart: '<S37>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_p, App_Model_B.Var_BrightMaxValue_p, &rtb_Var_GreenIND, &App_Model_DW.sf_Green_IND_Control_Function_b);

    /* Chart: '<S37>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_Contro(App_Model_M, App_Model_B.Var_BrightMaxValue_p, rtu_PostProcessIn_d, &App_Model_B.Var_GreenINDwithAnimation1_o, &App_Model_B.Var_GreenINDwithAnimation2_n,
      &App_Model_B.Var_GreenINDwithAnimation3_g, &App_Model_B.sf_Green_IND_with_Animation_C_o, &App_Model_DW.sf_Green_IND_with_Animation_C_o);

    /* Chart: '<S37>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Function_Flo(rtu_PostProcessIn_d, rtu_PostProcessIn_dz, rtb_Var_GreenIND, rtb_Var_AmberIND, App_Model_B.Var_GreenINDwithAnimation2_n, App_Model_B.Var_GreenINDwithAnimation3_g,
      App_Model_B.Var_GreenINDwithAnimation1_o, App_Model_B.Var_AmberINDwithAnimation_e, &rtb_Output_AmberIND_OUT, &rtb_Output_GreenIND_OUT, &rtb_Output_GreenIND2_OUT, &rtb_Output_GreenIND3_OUT,
      &App_Model_DW.sf_IND_Output_Control_Functio_i);

    /* SignalConversion generated from: '<S34>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_d = rtb_Output_AmberIND_OUT;

    /* SignalConversion generated from: '<S34>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_j = rtb_Output_GreenIND2_OUT;

    /* SignalConversion generated from: '<S34>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_i = rtb_Output_GreenIND3_OUT;

    /* SignalConversion generated from: '<S34>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT;

    /* End of Outputs for SubSystem: '<S23>/AutoBrightIndyOutputControl_Type3' */
    break;
  }

  /* End of SwitchCase: '<S23>/Switch Case' */
}

/*
 * System reset for function-call system:
 *    '<S267>/FadeOut'
 *    '<S315>/FadeOut'
 *    '<S219>/FadeOut'
 */
void App_Model_FadeOut_a_Reset(DW_FadeOut_App_Model_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S277>/Delay Input1'
   *
   * Block description for '<S277>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S281>/Delay Input2'
   *
   * Block description for '<S281>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S267>/FadeOut'
 *    '<S315>/FadeOut'
 *    '<S219>/FadeOut'
 */
void App_Model_FadeOut_a_Enable(DW_FadeOut_App_Model_f_T *localDW)
{
  localDW->FadeOut_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S267>/FadeOut'
 *    '<S315>/FadeOut'
 *    '<S219>/FadeOut'
 */
void App_Model_FadeOut_d(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_f_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_f;
  float64 rtb_deltafalllimit;
  if (localDW->FadeOut_RESET_ELAPS_T) {
    localDW->FadeOut_ELAPS_T = 0U;
  } else {
    localDW->FadeOut_ELAPS_T = App_Model_M->Timing.clockTick0 - localDW->FadeOut_PREV_T;
  }

  localDW->FadeOut_PREV_T = App_Model_M->Timing.clockTick0;
  localDW->FadeOut_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S281>/sample time'
   *
   * About '<S281>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (float64)localDW->FadeOut_ELAPS_T * 0.01;

  /* Switch: '<S282>/Switch2' incorporates:
   *  DataTypeConversion: '<S278>/Data Type Conversion2'
   *  Product: '<S281>/delta rise limit'
   *  SampleTimeMath: '<S281>/sample time'
   *
   * About '<S281>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltafalllimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S274>/Switch8' incorporates:
   *  Logic: '<S274>/AND'
   *  RelationalOperator: '<S277>/FixPt Relational Operator'
   *  Switch: '<S274>/Switch7'
   *  UnitDelay: '<S277>/Delay Input1'
   *
   * Block description for '<S277>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger_FO != 0) && (rtu_pass != 0.0)) {
    /* Switch: '<S274>/Switch8' */
    rtb_Add1_f = rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger_FO > 0) {
    /* Sum: '<S274>/Add1' incorporates:
     *  Constant: '<S274>/Constant5'
     *  Product: '<S274>/Divide'
     *  Switch: '<S274>/Switch'
     *  Switch: '<S274>/Switch5'
     *  Switch: '<S274>/Switch7'
     */
    rtb_Add1_f = (float64)rtu_preValue - (float64)rtu_Var_BrightMaxValue / 100.0;

    /* Switch: '<S280>/Switch2' incorporates:
     *  RelationalOperator: '<S280>/LowerRelop1'
     *  RelationalOperator: '<S280>/UpperRelop'
     *  Switch: '<S274>/Switch7'
     *  Switch: '<S280>/Switch'
     */
    if (rtb_Add1_f > rtu_preValue) {
      /* Switch: '<S274>/Switch8' incorporates:
       *  Switch: '<S280>/Switch2'
       */
      rtb_Add1_f = rtu_preValue;
    } else if (rtb_Add1_f < 0.0) {
      /* Switch: '<S280>/Switch' incorporates:
       *  Constant: '<S274>/Constant2'
       *  Switch: '<S274>/Switch8'
       *  Switch: '<S280>/Switch2'
       */
      rtb_Add1_f = 0.0;
    }

    /* End of Switch: '<S280>/Switch2' */
  } else {
    /* Switch: '<S274>/Switch8' incorporates:
     *  Constant: '<S274>/Constant2'
     *  Switch: '<S274>/Switch7'
     */
    rtb_Add1_f = 0.0;
  }

  /* End of Switch: '<S274>/Switch8' */

  /* Sum: '<S281>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S281>/Delay Input2'
   *
   * Block description for '<S281>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S281>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_f -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S282>/Switch2' incorporates:
   *  RelationalOperator: '<S282>/LowerRelop1'
   */
  if (rtb_Add1_f <= rtb_deltafalllimit) {
    /* Switch: '<S278>/Switch4' incorporates:
     *  DataStoreRead: '<S278>/Data Store Read'
     *  DataTypeConversion: '<S278>/Data Type Conversion2'
     *  DataTypeConversion: '<S278>/Data Type Conversion6'
     *  UnaryMinus: '<S278>/Unary Minus'
     *  UnaryMinus: '<S278>/Unary Minus2'
     */
    if (rtu_pass > 0.0) {
      rtb_deltafalllimit = -(float64)Par_AutoBrightLevel091;
    } else {
      rtb_deltafalllimit = -(float64)rtu_Var_BrightMaxValue;
    }

    /* End of Switch: '<S278>/Switch4' */

    /* Product: '<S281>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S281>/sample time'
     *
     * About '<S281>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_deltafalllimit *= elapseTime;

    /* Switch: '<S282>/Switch' incorporates:
     *  RelationalOperator: '<S282>/UpperRelop'
     */
    if (rtb_Add1_f >= rtb_deltafalllimit) {
      /* Switch: '<S282>/Switch2' */
      rtb_deltafalllimit = rtb_Add1_f;
    }

    /* End of Switch: '<S282>/Switch' */
  }

  /* End of Switch: '<S282>/Switch2' */

  /* Sum: '<S281>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S281>/Delay Input2'
   *
   * Block description for '<S281>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S281>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_deltafalllimit;

  /* Switch: '<S274>/Switch1' incorporates:
   *  Constant: '<S274>/Constant7'
   */
  if (rtu_Trigger_FO > 0) {
    uint16 rtb_Switch9;

    /* Switch: '<S278>/Switch9' */
    if (rtu_pass > 0.0) {
      /* Switch: '<S278>/Switch9' incorporates:
       *  DataTypeConversion: '<S278>/Data Type Conversion2'
       */
      rtb_Switch9 = rtu_Var_BrightMaxValue;
    } else {
      /* DataTypeConversion: '<S278>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S281>/Delay Input2'
       *
       * Block description for '<S281>/Delay Input2':
       *
       *  Store in Global RAM
       */
      elapseTime = fmod(floor(localDW->DelayInput2_DSTATE), 65536.0);

      /* Switch: '<S278>/Switch9' incorporates:
       *  DataTypeConversion: '<S278>/Data Type Conversion1'
       */
      rtb_Switch9 = (uint16)(elapseTime < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-elapseTime : (sint32)(uint16)elapseTime);
    }

    /* End of Switch: '<S278>/Switch9' */

    /* Switch: '<S279>/Switch2' incorporates:
     *  RelationalOperator: '<S279>/LowerRelop1'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      /* Switch: '<S279>/Switch2' */
      *rty_y_FadeOut = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S279>/Switch2' incorporates:
       *  Switch: '<S279>/Switch'
       */
      *rty_y_FadeOut = rtb_Switch9;
    }

    /* End of Switch: '<S279>/Switch2' */
  } else {
    *rty_y_FadeOut = 0U;
  }

  /* End of Switch: '<S274>/Switch1' */

  /* Update for UnitDelay: '<S277>/Delay Input1'
   *
   * Block description for '<S277>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Mode_Bright_Error_Control_l(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_AmberINDwithAnimation, RT_MODEL_App_Model_T * const
  App_Model_M, B_Amber_IND_with_Animation__m_T *localB, DW_Amber_IND_with_Animation_l_T *localDW)
{
  if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localDW->pass = 0.0;
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S267>/FadeIn' */
    /* FcnTrigRst = FadeOut(Var_BrightMaxValue,Var_AmberINDwithAnimation,0,0); */
    *rty_Var_AmberINDwithAnimation = 0U;
  } else {
    switch (rtu_Input_INT_WPC2IndCmdState) {
     case WPC2IndCmdState__ErrorOn:
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S267>/FadeIn' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      break;

     case WPC2IndCmdState__ErrorFadeIn:
      if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 1.0)) {
        localDW->pass = 1.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 0;
        localB->pass = 1.0;

        /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 1.0, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S267>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
      } else {
        localDW->pass = 0.0;
        localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
        localB->Trigger = 1;
        localB->pass = 0.0;

        /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
        App_Model_FadeIn(localB->Var_BrightMaxValue, 1, 0.0, &localB->Switch2, &localDW->FadeIn);

        /* End of Outputs for SubSystem: '<S267>/FadeIn' */
        *rty_Var_AmberINDwithAnimation = localB->Switch2;
      }
      break;
    }
  }

  if (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut) {
    if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass == 2.0)) {
      localDW->pass = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S267>/FadeIn' */
      localB->Var_BrightMaxValue_j = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 0;
      localB->pass_m = 1.0;

      /* Outputs for Function Call SubSystem: '<S267>/FadeOut' */
      App_Model_FadeOut_d(App_Model_M, localB->Var_BrightMaxValue_j, localB->preValue, 0, 1.0, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S267>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = rtu_Var_BrightMaxValue;
    } else {
      localDW->pass = 0.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger = 0;
      localB->pass = 0.0;

      /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
      App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

      /* End of Outputs for SubSystem: '<S267>/FadeIn' */
      localB->Var_BrightMaxValue_j = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_AmberINDwithAnimation;
      localB->Trigger_FO = 1;
      localB->pass_m = 0.0;

      /* Outputs for Function Call SubSystem: '<S267>/FadeOut' */
      App_Model_FadeOut_d(App_Model_M, localB->Var_BrightMaxValue_j, localB->preValue, 1, 0.0, &localB->Switch1, &localDW->FadeOut);

      /* End of Outputs for SubSystem: '<S267>/FadeOut' */
      *rty_Var_AmberINDwithAnimation = localB->Switch1;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S313>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S217>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_l_Init(uint16 *rty_Var_AmberINDwithAnimation)
{
  *rty_Var_AmberINDwithAnimation = 0U;
}

/*
 * Enable for atomic system:
 *    '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S313>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S217>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animati_l_Enable(DW_Amber_IND_with_Animation_l_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S267>/FadeIn' */
  App_Model_FadeIn_Reset(&localDW->FadeIn);

  /* End of SystemReset for SubSystem: '<S267>/FadeIn' */

  /* SystemReset for Function Call SubSystem: '<S267>/FadeOut' */
  App_Model_FadeOut_a_Reset(&localDW->FadeOut);

  /* End of SystemReset for SubSystem: '<S267>/FadeOut' */

  /* Enable for Function Call SubSystem: '<S267>/FadeOut' */
  App_Model_FadeOut_a_Enable(&localDW->FadeOut);

  /* End of Enable for SubSystem: '<S267>/FadeOut' */
}

/*
 * Output and update for atomic system:
 *    '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S313>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S217>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Amber_IND_with_Animation_Cont_m(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animation__m_T *localB, DW_Amber_IND_with_Animation_l_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if (localDW->is_active_c345_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c345_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger = 0;
    localB->pass = 0.0;

    /* Outputs for Function Call SubSystem: '<S267>/FadeIn' */
    App_Model_FadeIn(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2, &localDW->FadeIn);

    /* End of Outputs for SubSystem: '<S267>/FadeIn' */
    localB->Var_BrightMaxValue_j = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_AmberINDwithAnimation;
    localB->Trigger_FO = 0;
    localB->pass_m = 0.0;

    /* Outputs for Function Call SubSystem: '<S267>/FadeOut' */
    App_Model_FadeOut_d(App_Model_M, localB->Var_BrightMaxValue_j, localB->preValue, 0, 0.0, &localB->Switch1, &localDW->FadeOut);

    /* End of Outputs for SubSystem: '<S267>/FadeOut' */
    *rty_Var_AmberINDwithAnimation = 0U;
    if (rtu_b_SyncAmber == Off) {
      *rty_Var_AmberINDwithAnimation = 0U;

      /* 1 */
    } else if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
                WPC2IndCmdState__ErrorFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default)) {
      App_Mode_Bright_Error_Control_l(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);
    } else {
      /* Not used in Amber LED */
      *rty_Var_AmberINDwithAnimation = 0U;
    }

    /*  Transition run every task on system operation */
  } else if (rtu_b_SyncAmber == Off) {
    *rty_Var_AmberINDwithAnimation = 0U;

    /* 1 */
  } else if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
              WPC2IndCmdState__ErrorFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default)) {
    App_Mode_Bright_Error_Control_l(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_AmberINDwithAnimation, App_Model_M, localB, localDW);
  } else {
    /* Not used in Amber LED */
    *rty_Var_AmberINDwithAnimation = 0U;
  }

  /* End of Chart: '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System reset for function-call system:
 *    '<S270>/FadeOut3'
 *    '<S318>/FadeOut3'
 *    '<S222>/FadeOut3'
 */
void App_Model_FadeOut3_k_Reset(DW_FadeOut3_App_Model_i_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S307>/Delay Input1'
   *
   * Block description for '<S307>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S311>/Delay Input2'
   *
   * Block description for '<S311>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0;
}

/*
 * Enable for function-call system:
 *    '<S270>/FadeOut3'
 *    '<S318>/FadeOut3'
 *    '<S222>/FadeOut3'
 */
void App_Model_FadeOut3_b_Enable(DW_FadeOut3_App_Model_i_T *localDW)
{
  localDW->FadeOut3_RESET_ELAPS_T = true;
}

/*
 * Output and update for function-call system:
 *    '<S270>/FadeOut3'
 *    '<S318>/FadeOut3'
 *    '<S222>/FadeOut3'
 */
void App_Model_FadeOut3_i(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_i_T *localDW)
{
  float64 elapseTime;
  float64 rtb_Add1_j;
  float64 rtb_deltafalllimit;
  if (localDW->FadeOut3_RESET_ELAPS_T) {
    localDW->FadeOut3_ELAPS_T = 0U;
  } else {
    localDW->FadeOut3_ELAPS_T = App_Model_M->Timing.clockTick0 - localDW->FadeOut3_PREV_T;
  }

  localDW->FadeOut3_PREV_T = App_Model_M->Timing.clockTick0;
  localDW->FadeOut3_RESET_ELAPS_T = false;

  /* SampleTimeMath: '<S311>/sample time'
   *
   * About '<S311>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (float64)localDW->FadeOut3_ELAPS_T * 0.01;

  /* Switch: '<S312>/Switch2' incorporates:
   *  DataTypeConversion: '<S308>/Data Type Conversion2'
   *  Product: '<S311>/delta rise limit'
   *  SampleTimeMath: '<S311>/sample time'
   *
   * About '<S311>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deltafalllimit = (float64)rtu_Var_BrightMaxValue * elapseTime;

  /* Switch: '<S288>/Switch8' incorporates:
   *  Logic: '<S288>/AND'
   *  RelationalOperator: '<S307>/FixPt Relational Operator'
   *  Switch: '<S288>/Switch7'
   *  UnitDelay: '<S307>/Delay Input1'
   *
   * Block description for '<S307>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((rtu_Var_BrightMaxValue != localDW->DelayInput1_DSTATE) && (rtu_Trigger3_FO != 0) && (rtu_pass3 != 0.0)) {
    /* Switch: '<S288>/Switch8' */
    rtb_Add1_j = rtu_Var_BrightMaxValue;
  } else if (rtu_Trigger3_FO > 0) {
    /* Sum: '<S288>/Add1' incorporates:
     *  Constant: '<S288>/Constant5'
     *  Product: '<S288>/Divide'
     *  Switch: '<S288>/Switch'
     *  Switch: '<S288>/Switch5'
     *  Switch: '<S288>/Switch7'
     */
    rtb_Add1_j = (float64)rtu_preValue - (float64)rtu_Var_BrightMaxValue / 100.0;

    /* Switch: '<S310>/Switch2' incorporates:
     *  RelationalOperator: '<S310>/LowerRelop1'
     *  RelationalOperator: '<S310>/UpperRelop'
     *  Switch: '<S288>/Switch7'
     *  Switch: '<S310>/Switch'
     */
    if (rtb_Add1_j > rtu_preValue) {
      /* Switch: '<S288>/Switch8' incorporates:
       *  Switch: '<S310>/Switch2'
       */
      rtb_Add1_j = rtu_preValue;
    } else if (rtb_Add1_j < 0.0) {
      /* Switch: '<S310>/Switch' incorporates:
       *  Constant: '<S288>/Constant2'
       *  Switch: '<S288>/Switch8'
       *  Switch: '<S310>/Switch2'
       */
      rtb_Add1_j = 0.0;
    }

    /* End of Switch: '<S310>/Switch2' */
  } else {
    /* Switch: '<S288>/Switch8' incorporates:
     *  Constant: '<S288>/Constant2'
     *  Switch: '<S288>/Switch7'
     */
    rtb_Add1_j = 0.0;
  }

  /* End of Switch: '<S288>/Switch8' */

  /* Sum: '<S311>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S311>/Delay Input2'
   *
   * Block description for '<S311>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S311>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_Add1_j -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S312>/Switch2' incorporates:
   *  RelationalOperator: '<S312>/LowerRelop1'
   */
  if (rtb_Add1_j <= rtb_deltafalllimit) {
    /* Switch: '<S308>/Switch4' incorporates:
     *  DataStoreRead: '<S308>/Data Store Read'
     *  DataTypeConversion: '<S308>/Data Type Conversion2'
     *  DataTypeConversion: '<S308>/Data Type Conversion6'
     *  UnaryMinus: '<S308>/Unary Minus'
     *  UnaryMinus: '<S308>/Unary Minus2'
     */
    if (rtu_pass3 > 0.0) {
      rtb_deltafalllimit = -(float64)Par_AutoBrightLevel091;
    } else {
      rtb_deltafalllimit = -(float64)rtu_Var_BrightMaxValue;
    }

    /* End of Switch: '<S308>/Switch4' */

    /* Product: '<S311>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S311>/sample time'
     *
     * About '<S311>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_deltafalllimit *= elapseTime;

    /* Switch: '<S312>/Switch' incorporates:
     *  RelationalOperator: '<S312>/UpperRelop'
     */
    if (rtb_Add1_j >= rtb_deltafalllimit) {
      /* Switch: '<S312>/Switch2' */
      rtb_deltafalllimit = rtb_Add1_j;
    }

    /* End of Switch: '<S312>/Switch' */
  }

  /* End of Switch: '<S312>/Switch2' */

  /* Sum: '<S311>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S311>/Delay Input2'
   *
   * Block description for '<S311>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S311>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_deltafalllimit;

  /* Switch: '<S288>/Switch1' incorporates:
   *  Constant: '<S288>/Constant7'
   */
  if (rtu_Trigger3_FO > 0) {
    uint16 rtb_Switch9;

    /* Switch: '<S308>/Switch9' */
    if (rtu_pass3 > 0.0) {
      /* Switch: '<S308>/Switch9' incorporates:
       *  DataTypeConversion: '<S308>/Data Type Conversion2'
       */
      rtb_Switch9 = rtu_Var_BrightMaxValue;
    } else {
      /* DataTypeConversion: '<S308>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S311>/Delay Input2'
       *
       * Block description for '<S311>/Delay Input2':
       *
       *  Store in Global RAM
       */
      elapseTime = fmod(floor(localDW->DelayInput2_DSTATE), 65536.0);

      /* Switch: '<S308>/Switch9' incorporates:
       *  DataTypeConversion: '<S308>/Data Type Conversion1'
       */
      rtb_Switch9 = (uint16)(elapseTime < 0.0 ? (sint32)(uint16)-(sint16)(uint16)-elapseTime : (sint32)(uint16)elapseTime);
    }

    /* End of Switch: '<S308>/Switch9' */

    /* Switch: '<S309>/Switch2' incorporates:
     *  RelationalOperator: '<S309>/LowerRelop1'
     */
    if (rtb_Switch9 > rtu_Var_BrightMaxValue) {
      /* Switch: '<S309>/Switch2' */
      *rty_y_FadeOut3 = rtu_Var_BrightMaxValue;
    } else {
      /* Switch: '<S309>/Switch2' incorporates:
       *  Switch: '<S309>/Switch'
       */
      *rty_y_FadeOut3 = rtb_Switch9;
    }

    /* End of Switch: '<S309>/Switch2' */
  } else {
    *rty_y_FadeOut3 = 0U;
  }

  /* End of Switch: '<S288>/Switch1' */

  /* Update for UnitDelay: '<S307>/Delay Input1'
   *
   * Block description for '<S307>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtu_Var_BrightMaxValue;
}

/* Function for Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control1_n(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation1, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW)
{
  if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_k, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = 0U;
    localDW->pass1 = 0.0;

    /* Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut  ||... */
  } else if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
              WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn)) {
    /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_k, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
    *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    localDW->pass1 = 0.0;
  } else if (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) {
    if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 1.0)) {
      localDW->pass1 = 1.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 1.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 1, 1.0, &localB->Switch2_k, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_k;
      localB->Var_BrightMaxValue_h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_n = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_h, localB->preValue, 0, 0.0, &localB->Switch1_h, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S270>/FadeOut1' */
    } else {
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 1;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 1, 0.0, &localB->Switch2_k, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch2_k;
      localB->Var_BrightMaxValue_h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_n = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_h, localB->preValue, 0, 0.0, &localB->Switch1_h, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S270>/FadeOut1' */
      localDW->pass1 = 0.0;
    }
  }

  if (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) {
    if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass1 == 2.0)) {
      localDW->pass1 = 2.0;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_k, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
      localB->Var_BrightMaxValue_h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 0;
      localB->pass1_n = 1.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_h, localB->preValue, 0, 1.0, &localB->Switch1_h, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S270>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_h = rtu_Var_BrightMaxValue;
      localB->preValue = *rty_Var_GreenINDwithAnimation1;
      localB->Trigger1_FO = 1;
      localB->pass1_n = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut1' */
      App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_h, localB->preValue, 1, 0.0, &localB->Switch1_h, &localDW->FadeOut1);

      /* End of Outputs for SubSystem: '<S270>/FadeOut1' */
      *rty_Var_GreenINDwithAnimation1 = localB->Switch1_h;
      localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
      localB->Trigger1 = 0;
      localB->pass1 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
      App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_k, &localDW->FadeIn1);

      /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
      localDW->pass1 = 0.0;
    }
  }
}

/* Function for Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control2_h(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation2, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW)
{
  if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 0, 0.0, &localB->Switch2_l, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = 0U;
    localDW->pass2 = 0.0;
  } else if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
              WPC2IndCmdState__3rdChrgOn)) {
    localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 0, 0.0, &localB->Switch2_l, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
    *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    localDW->pass2 = 0.0;
  } else if (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) {
    if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 1.0)) {
      localDW->pass2 = 1.0;
      localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 1.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 1, 1.0, &localB->Switch2_l, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_l;
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue_p = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_l = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue_p, 0, 0.0, &localB->Switch1_m, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S270>/FadeOut2' */
    } else {
      localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 1;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 1, 0.0, &localB->Switch2_l, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch2_l;
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue_p = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_l = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue_p, 0, 0.0, &localB->Switch1_m, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S270>/FadeOut2' */
      localDW->pass2 = 0.0;
    }
  }

  if (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) {
    if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass2 == 2.0)) {
      localDW->pass2 = 2.0;
      localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 0, 0.0, &localB->Switch2_l, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue_p = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 0;
      localB->pass2_l = 1.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue_p, 0, 1.0, &localB->Switch1_m, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S270>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
      localB->preValue_p = *rty_Var_GreenINDwithAnimation2;
      localB->Trigger2_FO = 1;
      localB->pass2_l = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut2' */
      App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue_p, 1, 0.0, &localB->Switch1_m, &localDW->FadeOut2);

      /* End of Outputs for SubSystem: '<S270>/FadeOut2' */
      *rty_Var_GreenINDwithAnimation2 = localB->Switch1_m;
      localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
      localB->Trigger2 = 0;
      localB->pass2 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
      App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 0, 0.0, &localB->Switch2_l, &localDW->FadeIn2);

      /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
      localDW->pass2 = 0.0;
    }
  }
}

/* Function for Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
static void App_Model_Bright_Control3_c(uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation3, RT_MODEL_App_Model_T * const App_Model_M,
  B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW)
{
  if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
    localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
    *rty_Var_GreenINDwithAnimation3 = 0U;
    localDW->pass3 = 0.0;
  } else {
    switch (rtu_Input_INT_WPC2IndCmdState) {
     case WPC2IndCmdState__3rdChrgOn:
      localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
      localDW->pass3 = 0.0;
      break;

     case WPC2IndCmdState__3rdChrgFadeIn:
      if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 1.0)) {
        localDW->pass3 = 1.0;
        localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 1.0;

        /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 1, 1.0, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_pp = rtu_Var_BrightMaxValue;
        localB->preValue_h = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_m = 0.0;

        /* Outputs for Function Call SubSystem: '<S270>/FadeOut3' */
        App_Model_FadeOut3_i(App_Model_M, localB->Var_BrightMaxValue_pp, localB->preValue_h, 0, 0.0, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S270>/FadeOut3' */
      } else {
        localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
        localB->Trigger3 = 1;
        localB->pass3 = 0.0;

        /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
        App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 1, 0.0, &localB->Switch2, &localDW->FadeIn3);

        /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
        *rty_Var_GreenINDwithAnimation3 = localB->Switch2;
        localB->Var_BrightMaxValue_pp = rtu_Var_BrightMaxValue;
        localB->preValue_h = *rty_Var_GreenINDwithAnimation3;
        localB->Trigger3_FO = 0;
        localB->pass3_m = 0.0;

        /* Outputs for Function Call SubSystem: '<S270>/FadeOut3' */
        App_Model_FadeOut3_i(App_Model_M, localB->Var_BrightMaxValue_pp, localB->preValue_h, 0, 0.0, &localB->Switch1, &localDW->FadeOut3);

        /* End of Outputs for SubSystem: '<S270>/FadeOut3' */
        localDW->pass3 = 0.0;
      }
      break;
    }
  }

  if (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) {
    if (((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) && (localDW->Var_BrightMaxValue_prev != localDW->Var_BrightMaxValue_start)) || (localDW->pass3 == 2.0)) {
      localDW->pass3 = 2.0;
      localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
      localB->Var_BrightMaxValue_pp = rtu_Var_BrightMaxValue;
      localB->preValue_h = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 0;
      localB->pass3_m = 1.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut3' */
      App_Model_FadeOut3_i(App_Model_M, localB->Var_BrightMaxValue_pp, localB->preValue_h, 0, 1.0, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S270>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = rtu_Var_BrightMaxValue;
    } else {
      localB->Var_BrightMaxValue_pp = rtu_Var_BrightMaxValue;
      localB->preValue_h = *rty_Var_GreenINDwithAnimation3;
      localB->Trigger3_FO = 1;
      localB->pass3_m = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeOut3' */
      App_Model_FadeOut3_i(App_Model_M, localB->Var_BrightMaxValue_pp, localB->preValue_h, 1, 0.0, &localB->Switch1, &localDW->FadeOut3);

      /* End of Outputs for SubSystem: '<S270>/FadeOut3' */
      *rty_Var_GreenINDwithAnimation3 = localB->Switch1;
      localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
      localB->Trigger3 = 0;
      localB->pass3 = 0.0;

      /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
      App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

      /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
      localDW->pass3 = 0.0;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S313>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S217>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_m_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3)
{
  *rty_Var_GreenINDwithAnimation1 = 0U;
  *rty_Var_GreenINDwithAnimation2 = 0U;
  *rty_Var_GreenINDwithAnimation3 = 0U;
}

/*
 * Enable for atomic system:
 *    '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S313>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S217>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animati_k_Enable(DW_Green_IND_with_Animation_e_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S270>/FadeIn1' */
  App_Model_FadeIn1_Reset(&localDW->FadeIn1);

  /* End of SystemReset for SubSystem: '<S270>/FadeIn1' */

  /* SystemReset for Function Call SubSystem: '<S270>/FadeOut1' */
  App_Model_FadeOut1_Reset(&localDW->FadeOut1);

  /* End of SystemReset for SubSystem: '<S270>/FadeOut1' */

  /* Enable for Function Call SubSystem: '<S270>/FadeOut1' */
  App_Model_FadeOut1_Enable(&localDW->FadeOut1);

  /* End of Enable for SubSystem: '<S270>/FadeOut1' */

  /* SystemReset for Function Call SubSystem: '<S270>/FadeIn2' */
  App_Model_FadeIn2_Reset(&localDW->FadeIn2);

  /* End of SystemReset for SubSystem: '<S270>/FadeIn2' */

  /* SystemReset for Function Call SubSystem: '<S270>/FadeOut2' */
  App_Model_FadeOut2_Reset(&localDW->FadeOut2);

  /* End of SystemReset for SubSystem: '<S270>/FadeOut2' */

  /* Enable for Function Call SubSystem: '<S270>/FadeOut2' */
  App_Model_FadeOut2_Enable(&localDW->FadeOut2);

  /* End of Enable for SubSystem: '<S270>/FadeOut2' */

  /* SystemReset for Function Call SubSystem: '<S270>/FadeIn3' */
  App_Model_FadeIn3_Reset(&localDW->FadeIn3);

  /* End of SystemReset for SubSystem: '<S270>/FadeIn3' */

  /* SystemReset for Function Call SubSystem: '<S270>/FadeOut3' */
  App_Model_FadeOut3_k_Reset(&localDW->FadeOut3);

  /* End of SystemReset for SubSystem: '<S270>/FadeOut3' */

  /* Enable for Function Call SubSystem: '<S270>/FadeOut3' */
  App_Model_FadeOut3_b_Enable(&localDW->FadeOut3);

  /* End of Enable for SubSystem: '<S270>/FadeOut3' */
}

/*
 * Output and update for atomic system:
 *    '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S313>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 *    '<S217>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
 */
void Green_IND_with_Animation_Cont_e(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW)
{
  localDW->Var_BrightMaxValue_prev = localDW->Var_BrightMaxValue_start;
  localDW->Var_BrightMaxValue_start = rtu_Var_BrightMaxValue;

  /* Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  if (localDW->is_active_c349_IndyOutputContro == 0U) {
    localDW->Var_BrightMaxValue_prev = rtu_Var_BrightMaxValue;
    localDW->is_active_c349_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue = rtu_Var_BrightMaxValue;
    localB->Trigger1 = 0;
    localB->pass1 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn1' */
    App_Model_FadeIn1(localB->Var_BrightMaxValue, 0, 0.0, &localB->Switch2_k, &localDW->FadeIn1);

    /* End of Outputs for SubSystem: '<S270>/FadeIn1' */
    localB->Var_BrightMaxValue_h = rtu_Var_BrightMaxValue;
    localB->preValue = *rty_Var_GreenINDwithAnimation1;
    localB->Trigger1_FO = 0;
    localB->pass1_n = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeOut1' */
    App_Model_FadeOut1(App_Model_M, localB->Var_BrightMaxValue_h, localB->preValue, 0, 0.0, &localB->Switch1_h, &localDW->FadeOut1);

    /* End of Outputs for SubSystem: '<S270>/FadeOut1' */
    *rty_Var_GreenINDwithAnimation1 = 0U;

    /* 1. In the case of 1st LED */
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) ||
        (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1_n(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 1st LED, Abnormal */
      *rty_Var_GreenINDwithAnimation1 = 0U;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_m = rtu_Var_BrightMaxValue;
    localB->Trigger2 = 0;
    localB->pass2 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn2' */
    App_Model_FadeIn2(localB->Var_BrightMaxValue_m, 0, 0.0, &localB->Switch2_l, &localDW->FadeIn2);

    /* End of Outputs for SubSystem: '<S270>/FadeIn2' */
    localB->Var_BrightMaxValue_p = rtu_Var_BrightMaxValue;
    localB->preValue_p = *rty_Var_GreenINDwithAnimation2;
    localB->Trigger2_FO = 0;
    localB->pass2_l = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeOut2' */
    App_Model_FadeOut2(App_Model_M, localB->Var_BrightMaxValue_p, localB->preValue_p, 0, 0.0, &localB->Switch1_m, &localDW->FadeOut2);

    /* End of Outputs for SubSystem: '<S270>/FadeOut2' */
    *rty_Var_GreenINDwithAnimation2 = 0U;

    /* 1. In the case of 2nd LED */
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__3rdChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) ||
        (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2_h(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 2nd LED Off */
      *rty_Var_GreenINDwithAnimation2 = 0U;
    }

    /*  Transition run once at reset */
    localB->Var_BrightMaxValue_e = rtu_Var_BrightMaxValue;
    localB->Trigger3 = 0;
    localB->pass3 = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeIn3' */
    App_Model_FadeIn3(localB->Var_BrightMaxValue_e, 0, 0.0, &localB->Switch2, &localDW->FadeIn3);

    /* End of Outputs for SubSystem: '<S270>/FadeIn3' */
    localB->Var_BrightMaxValue_pp = rtu_Var_BrightMaxValue;
    localB->preValue_h = *rty_Var_GreenINDwithAnimation3;
    localB->Trigger3_FO = 0;
    localB->pass3_m = 0.0;

    /* Outputs for Function Call SubSystem: '<S270>/FadeOut3' */
    App_Model_FadeOut3_i(App_Model_M, localB->Var_BrightMaxValue_pp, localB->preValue_h, 0, 0.0, &localB->Switch1, &localDW->FadeOut3);

    /* End of Outputs for SubSystem: '<S270>/FadeOut3' */
    *rty_Var_GreenINDwithAnimation3 = 0U;

    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3_c(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 3rd LED Off */
      *rty_Var_GreenINDwithAnimation3 = 0U;
    }
  } else {
    /*  Transition run every task on system operation */
    /* 1. In the case of 1st LED */
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) ||
        (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut  ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control1_n(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation1, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 1st LED, Abnormal */
      *rty_Var_GreenINDwithAnimation1 = 0U;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 2nd LED */
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__3rdChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) ||
        (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control2_h(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation2, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 2nd LED Off */
      *rty_Var_GreenINDwithAnimation2 = 0U;
    }

    /*  Transition run every task on system operation */
    /* 1. In the case of 3rd LED, must be changed to bleow condion */
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff)) {
      /* ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeOut ||Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2]%23101 */
      App_Model_Bright_Control3_c(rtu_Var_BrightMaxValue, rtu_Input_INT_WPC2IndCmdState, rty_Var_GreenINDwithAnimation3, App_Model_M, localB, localDW);
    } else {
      /* 2. In the case of 3rd LED Off */
      *rty_Var_GreenINDwithAnimation3 = 0U;
    }
  }

  /* End of Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
}

/*
 * System initialize for atomic system:
 *    '<S265>/IND_Output_Control_Function_Flow_Graph'
 *    '<S313>/IND_Output_Control_Function_Flow_Graph'
 *    '<S217>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Funct_p_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT)
{
  *rty_Output_AmberIND_OUT = 0U;
  *rty_Output_GreenIND_OUT = 0U;
  *rty_Output_GreenIND2_OUT = 0U;
  *rty_Output_GreenIND3_OUT = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S265>/IND_Output_Control_Function_Flow_Graph'
 *    '<S313>/IND_Output_Control_Function_Flow_Graph'
 *    '<S217>/IND_Output_Control_Function_Flow_Graph'
 */
void IND_Output_Control_Function_F_k(WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, WPCIndUSMState rtu_Input_C_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Funct_p_T *localDW)
{
  /* Chart: '<S265>/IND_Output_Control_Function_Flow_Graph' */
  if (localDW->is_active_c351_IndyOutputContro == 0U) {
    localDW->is_active_c351_IndyOutputContro = 1U;

    /*  Transition run once at reset */
    *rty_Output_GreenIND_OUT = 0U;
    *rty_Output_GreenIND2_OUT = 0U;
    *rty_Output_GreenIND3_OUT = 0U;
    *rty_Output_AmberIND_OUT = 0U;

    /* Ref_Off */
    /* 1 */
    if (rtu_Input_C_WPCIndUSMState == WPCIndUSMState__Type2) {
      if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn)
          || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState ==
           WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut) ||
          (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || (rtu_Input_INT_WPC2IndCmdState ==
           WPC2IndCmdState__3rdChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2)) {
        /* 231010 */
        /* Green IND Light */
        *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
        *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
        *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
        *rty_Output_AmberIND_OUT = 0U;
      } else if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
                  WPC2IndCmdState__ErrorFadeOut)) {
        /* Amber IND light */
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
      } else {
        *rty_Output_GreenIND_OUT = 0U;
        *rty_Output_GreenIND2_OUT = 0U;
        *rty_Output_GreenIND3_OUT = 0U;
        *rty_Output_AmberIND_OUT = 0U;

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
  } else if (rtu_Input_C_WPCIndUSMState == WPCIndUSMState__Type2) {
    if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__Default) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgOff) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn) ||
        (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__2ndChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeOut) ||
        (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || (rtu_Input_INT_WPC2IndCmdState ==
         WPC2IndCmdState__3rdChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ChrgFadeOut3_2)) {
      /* 231010 */
      /* Green IND Light */
      *rty_Output_GreenIND_OUT = rtu_Var_GreenINDwithAnimation1;
      *rty_Output_GreenIND2_OUT = rtu_Var_GreenINDwithAnimation2;
      *rty_Output_GreenIND3_OUT = rtu_Var_GreenINDwithAnimation3;
      *rty_Output_AmberIND_OUT = 0U;
    } else if ((rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorOn) || (rtu_Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeIn) || (rtu_Input_INT_WPC2IndCmdState ==
                WPC2IndCmdState__ErrorFadeOut)) {
      /* Amber IND light */
      *rty_Output_GreenIND_OUT = 0U;
      *rty_Output_GreenIND2_OUT = 0U;
      *rty_Output_GreenIND3_OUT = 0U;
      *rty_Output_AmberIND_OUT = rtu_Var_AmberINDwithAnimation;
    } else {
      *rty_Output_GreenIND_OUT = 0U;
      *rty_Output_GreenIND2_OUT = 0U;
      *rty_Output_GreenIND3_OUT = 0U;
      *rty_Output_AmberIND_OUT = 0U;

      /* Ref is 'Off' but Just 'Off' declare cuase 'Build error'.
         Using  Parameter Value(Par_AutoBrightLevelOff) instead of 'Off' */
    }
  } else {
    *rty_Output_GreenIND_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND2_OUT = rtu_Var_GreenIND;
    *rty_Output_GreenIND3_OUT = rtu_Var_GreenIND;
    *rty_Output_AmberIND_OUT = rtu_Var_AmberIND;
  }

  /* End of Chart: '<S265>/IND_Output_Control_Function_Flow_Graph' */
}

/* System initialize for atomic system: '<S202>/IndyOutputControl_Function' */
void IndyOutputControl_Functi_d_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_g, uint16 *rty_IndyOutput_Sig_l, uint16 *rty_IndyOutput_Sig_m)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT_go;
  uint16 rtb_Output_GreenIND_OUT_d;
  uint16 rtb_Output_GreenIND2_OUT_j;
  uint16 rtb_Output_GreenIND3_OUT_b;
  uint16 rtb_Var_GreenIND_l;
  uint16 rtb_Var_AmberIND_b;
  uint16 rtb_Output_AmberIND_OUT_k;
  uint16 rtb_Output_GreenIND_OUT_aj;
  uint16 rtb_Output_GreenIND2_OUT_f;
  uint16 rtb_Output_GreenIND3_OUT_o;
  uint16 rtb_Var_GreenIND_o;
  uint16 rtb_Var_AmberIND_c;
  uint16 rtb_Output_AmberIND_OUT_n;
  uint16 rtb_Output_GreenIND_OUT_i;
  uint16 rtb_Output_GreenIND2_OUT_k;
  uint16 rtb_Output_GreenIND3_OUT_e;
  uint16 rtb_Var_GreenIND_a;
  uint16 rtb_Var_AmberIND_o;

  /* Start for SwitchCase: '<S208>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for IfAction SubSystem: '<S208>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for Chart: '<S265>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue_a);

  /* SystemInitialize for Chart: '<S265>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_F_Init(&App_Model_B.Var_BrightMaxValue_cv);

  /* SystemInitialize for Chart: '<S265>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_a);

  /* SystemInitialize for Chart: '<S265>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_o);

  /* SystemInitialize for Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_m_Init(&App_Model_B.Var_GreenINDwithAnimation1_i, &App_Model_B.Var_GreenINDwithAnimation2_j, &App_Model_B.Var_GreenINDwithAnimation3_h);

  /* SystemInitialize for Chart: '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_l_Init(&App_Model_B.Var_AmberINDwithAnimation_m);

  /* SystemInitialize for Chart: '<S265>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Funct_p_Init(&rtb_Output_AmberIND_OUT_n, &rtb_Output_GreenIND_OUT_i, &rtb_Output_GreenIND2_OUT_k, &rtb_Output_GreenIND3_OUT_e);

  /* End of SystemInitialize for SubSystem: '<S208>/RheoStatIndyOutputControl_Type1' */

  /* SystemInitialize for IfAction SubSystem: '<S208>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for Chart: '<S313>/WPC_IND_Output_Control_Function' */
  WPC_IND_Output_Control_Fun_Init(&App_Model_B.RheoLevelValue);

  /* SystemInitialize for Chart: '<S313>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_i_Init(&App_Model_B.Var_BrightMaxValue_c);

  /* SystemInitialize for Chart: '<S313>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_o);

  /* SystemInitialize for Chart: '<S313>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_c);

  /* SystemInitialize for Chart: '<S313>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_m_Init(&App_Model_B.Var_GreenINDwithAnimation1_h, &App_Model_B.Var_GreenINDwithAnimation2_i, &App_Model_B.Var_GreenINDwithAnimation3_a);

  /* SystemInitialize for Chart: '<S313>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_l_Init(&App_Model_B.Var_AmberINDwithAnimation_b);

  /* SystemInitialize for Chart: '<S313>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Funct_p_Init(&rtb_Output_AmberIND_OUT_k, &rtb_Output_GreenIND_OUT_aj, &rtb_Output_GreenIND2_OUT_f, &rtb_Output_GreenIND3_OUT_o);

  /* End of SystemInitialize for SubSystem: '<S208>/RheoStatIndyOutputControl_Type2' */

  /* SystemInitialize for IfAction SubSystem: '<S208>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Chart: '<S217>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  WPC_IND_Output_With_Auto_B_Init(&App_Model_B.AutoBrightValue);

  /* SystemInitialize for Chart: '<S217>/Bright_Max_Value_Control_Function_Flow_Graph' */
  Bright_Max_Value_Control_m_Init(&App_Model_B.Var_BrightMaxValue);

  /* SystemInitialize for Chart: '<S217>/Amber_IND_Control_Function_Flow_Graph' */
  Amber_IND_Control_Function_Init(&rtb_Var_AmberIND_b);

  /* SystemInitialize for Chart: '<S217>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Amber_IND_with_Animation_l_Init(&App_Model_B.Var_AmberINDwithAnimation);

  /* SystemInitialize for Chart: '<S217>/Green_IND_Control_Function_Flow_Graph' */
  Green_IND_Control_Function_Init(&rtb_Var_GreenIND_l);

  /* SystemInitialize for Chart: '<S217>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  Green_IND_with_Animation_m_Init(&App_Model_B.Var_GreenINDwithAnimation1, &App_Model_B.Var_GreenINDwithAnimation2, &App_Model_B.Var_GreenINDwithAnimation3);

  /* SystemInitialize for Chart: '<S217>/IND_Output_Control_Function_Flow_Graph' */
  IND_Output_Control_Funct_p_Init(&rtb_Output_AmberIND_OUT_go, &rtb_Output_GreenIND_OUT_d, &rtb_Output_GreenIND2_OUT_j, &rtb_Output_GreenIND3_OUT_b);

  /* End of SystemInitialize for SubSystem: '<S208>/AutoBrightIndyOutputControl_Type3' */

  /* SystemInitialize for Merge generated from: '<S208>/Merge' */
  *rty_IndyOutput_Sig = 0U;

  /* SystemInitialize for Merge generated from: '<S208>/Merge' */
  *rty_IndyOutput_Sig_g = 0U;

  /* SystemInitialize for Merge generated from: '<S208>/Merge' */
  *rty_IndyOutput_Sig_l = 0U;

  /* SystemInitialize for Merge generated from: '<S208>/Merge' */
  *rty_IndyOutput_Sig_m = 0U;
}

/* Disable for atomic system: '<S202>/IndyOutputControl_Function' */
void IndyOutputControl_Fun_e_Disable(void)
{
  /* Disable for SwitchCase: '<S208>/Switch Case' */
  App_Model_DW.SwitchCase_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<S202>/IndyOutputControl_Function' */
void Ap_IndyOutputControl_Function_n(INDContType rtu_PostProcessIn, Bool rtu_PostProcessIn_g, Bool rtu_PostProcessIn_l, WPC2IndCmdState rtu_PostProcessIn_m, Bool rtu_PostProcessIn_f, RheostatOption
  rtu_PostProcessIn_k, Bool rtu_PostProcessIn_b, Bool rtu_PostProcessIn_mk, WPCIndUSMState rtu_PostProcessIn_fg, C_RheoStatLevel rtu_PostProcessIn_j, C_AutoBrightLevel rtu_PostProcessIn_c, uint16
  *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_g, uint16 *rty_IndyOutput_Sig_l, uint16 *rty_IndyOutput_Sig_m)
{
  /* local block i/o variables */
  uint16 rtb_Output_AmberIND_OUT_go;
  uint16 rtb_Output_GreenIND_OUT_d;
  uint16 rtb_Output_GreenIND2_OUT_j;
  uint16 rtb_Output_GreenIND3_OUT_b;
  uint16 rtb_Var_GreenIND_l;
  uint16 rtb_Var_AmberIND_b;
  uint16 rtb_Output_AmberIND_OUT_k;
  uint16 rtb_Output_GreenIND_OUT_aj;
  uint16 rtb_Output_GreenIND2_OUT_f;
  uint16 rtb_Output_GreenIND3_OUT_o;
  uint16 rtb_Var_GreenIND_o;
  uint16 rtb_Var_AmberIND_c;
  uint16 rtb_Output_AmberIND_OUT_n;
  uint16 rtb_Output_GreenIND_OUT_i;
  uint16 rtb_Output_GreenIND2_OUT_k;
  uint16 rtb_Output_GreenIND3_OUT_e;
  uint16 rtb_Var_GreenIND_a;
  uint16 rtb_Var_AmberIND_o;
  sint8 rtPrevAction;

  /* SwitchCase: '<S208>/Switch Case' */
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
  }

  switch (App_Model_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    if (App_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S208>/RheoStatIndyOutputControl_Type1' incorporates:
       *  ActionPort: '<S215>/Action Port'
       */
      /* Enable for SwitchCase: '<S208>/Switch Case' incorporates:
       *  Chart: '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Green_IND_with_Animati_k_Enable(&App_Model_DW.sf_Green_IND_with_Animation_C_e);
      Amber_IND_with_Animati_l_Enable(&App_Model_DW.sf_Amber_IND_with_Animation_C_m);

      /* End of Enable for SubSystem: '<S208>/RheoStatIndyOutputControl_Type1' */
    }

    /* Outputs for IfAction SubSystem: '<S208>/RheoStatIndyOutputControl_Type1' incorporates:
     *  ActionPort: '<S215>/Action Port'
     */
    /* Chart: '<S265>/WPC_IND_Output_Control_Function' */
    WPC_IND_Output_Control_Function(rtu_PostProcessIn_j, &App_Model_B.RheoLevelValue_a, &App_Model_DW.sf_WPC_IND_Output_Control_Fun_o);

    /* Chart: '<S265>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Functi(rtu_PostProcessIn_f, rtu_PostProcessIn_k, rtu_PostProcessIn_b, App_Model_B.RheoLevelValue_a, &App_Model_B.Var_BrightMaxValue_cv,
      &App_Model_DW.sf_Bright_Max_Value_Control_F_l);

    /* Chart: '<S265>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_mk, App_Model_B.Var_BrightMaxValue_cv, &rtb_Var_GreenIND_a, &App_Model_DW.sf_Green_IND_Control_Function_a);

    /* Chart: '<S265>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_g, App_Model_B.Var_BrightMaxValue_cv, &rtb_Var_AmberIND_o, &App_Model_DW.sf_Amber_IND_Control_Function_m);

    /* Chart: '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_Cont_e(App_Model_M, App_Model_B.Var_BrightMaxValue_cv, rtu_PostProcessIn_m, &App_Model_B.Var_GreenINDwithAnimation1_i, &App_Model_B.Var_GreenINDwithAnimation2_j,
      &App_Model_B.Var_GreenINDwithAnimation3_h, &App_Model_B.sf_Green_IND_with_Animation_C_e, &App_Model_DW.sf_Green_IND_with_Animation_C_e);

    /* Chart: '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_Cont_m(App_Model_M, App_Model_B.Var_BrightMaxValue_cv, rtu_PostProcessIn_l, rtu_PostProcessIn_m, &App_Model_B.Var_AmberINDwithAnimation_m,
      &App_Model_B.sf_Amber_IND_with_Animation_C_m, &App_Model_DW.sf_Amber_IND_with_Animation_C_m);

    /* Chart: '<S265>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Function_F_k(rtu_PostProcessIn_m, rtu_PostProcessIn_fg, rtb_Var_GreenIND_a, rtb_Var_AmberIND_o, App_Model_B.Var_GreenINDwithAnimation2_j,
      App_Model_B.Var_GreenINDwithAnimation3_h, App_Model_B.Var_GreenINDwithAnimation1_i, App_Model_B.Var_AmberINDwithAnimation_m, &rtb_Output_AmberIND_OUT_n, &rtb_Output_GreenIND_OUT_i,
      &rtb_Output_GreenIND2_OUT_k, &rtb_Output_GreenIND3_OUT_e, &App_Model_DW.sf_IND_Output_Control_Functio_k);

    /* SignalConversion generated from: '<S215>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_m = rtb_Output_AmberIND_OUT_n;

    /* SignalConversion generated from: '<S215>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_g = rtb_Output_GreenIND2_OUT_k;

    /* SignalConversion generated from: '<S215>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_l = rtb_Output_GreenIND3_OUT_e;

    /* SignalConversion generated from: '<S215>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_i;

    /* End of Outputs for SubSystem: '<S208>/RheoStatIndyOutputControl_Type1' */
    break;

   case 1:
    if (App_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S208>/RheoStatIndyOutputControl_Type2' incorporates:
       *  ActionPort: '<S216>/Action Port'
       */
      /* Enable for SwitchCase: '<S208>/Switch Case' incorporates:
       *  Chart: '<S313>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S313>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Green_IND_with_Animati_k_Enable(&App_Model_DW.sf_Green_IND_with_Animation_C_p);
      Amber_IND_with_Animati_l_Enable(&App_Model_DW.sf_Amber_IND_with_Animation__fw);

      /* End of Enable for SubSystem: '<S208>/RheoStatIndyOutputControl_Type2' */
    }

    /* Outputs for IfAction SubSystem: '<S208>/RheoStatIndyOutputControl_Type2' incorporates:
     *  ActionPort: '<S216>/Action Port'
     */
    /* Chart: '<S313>/WPC_IND_Output_Control_Function' */
    WPC_IND_Output_Control_Function(rtu_PostProcessIn_j, &App_Model_B.RheoLevelValue, &App_Model_DW.sf_WPC_IND_Output_Control_Fun_e);

    /* Chart: '<S313>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Func_b(rtu_PostProcessIn_k, rtu_PostProcessIn_b, App_Model_B.RheoLevelValue, &App_Model_B.Var_BrightMaxValue_c, &App_Model_DW.sf_Bright_Max_Value_Control_F_k);

    /* Chart: '<S313>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_mk, App_Model_B.Var_BrightMaxValue_c, &rtb_Var_GreenIND_o, &App_Model_DW.sf_Green_IND_Control_Function_e);

    /* Chart: '<S313>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_g, App_Model_B.Var_BrightMaxValue_c, &rtb_Var_AmberIND_c, &App_Model_DW.sf_Amber_IND_Control_Function_l);

    /* Chart: '<S313>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_Cont_e(App_Model_M, App_Model_B.Var_BrightMaxValue_c, rtu_PostProcessIn_m, &App_Model_B.Var_GreenINDwithAnimation1_h, &App_Model_B.Var_GreenINDwithAnimation2_i,
      &App_Model_B.Var_GreenINDwithAnimation3_a, &App_Model_B.sf_Green_IND_with_Animation_C_p, &App_Model_DW.sf_Green_IND_with_Animation_C_p);

    /* Chart: '<S313>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_Cont_m(App_Model_M, App_Model_B.Var_BrightMaxValue_c, rtu_PostProcessIn_l, rtu_PostProcessIn_m, &App_Model_B.Var_AmberINDwithAnimation_b,
      &App_Model_B.sf_Amber_IND_with_Animation__fw, &App_Model_DW.sf_Amber_IND_with_Animation__fw);

    /* Chart: '<S313>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Function_F_k(rtu_PostProcessIn_m, rtu_PostProcessIn_fg, rtb_Var_GreenIND_o, rtb_Var_AmberIND_c, App_Model_B.Var_GreenINDwithAnimation2_i,
      App_Model_B.Var_GreenINDwithAnimation3_a, App_Model_B.Var_GreenINDwithAnimation1_h, App_Model_B.Var_AmberINDwithAnimation_b, &rtb_Output_AmberIND_OUT_k, &rtb_Output_GreenIND_OUT_aj,
      &rtb_Output_GreenIND2_OUT_f, &rtb_Output_GreenIND3_OUT_o, &App_Model_DW.sf_IND_Output_Control_Functi_jl);

    /* SignalConversion generated from: '<S216>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_m = rtb_Output_AmberIND_OUT_k;

    /* SignalConversion generated from: '<S216>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_g = rtb_Output_GreenIND2_OUT_f;

    /* SignalConversion generated from: '<S216>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_l = rtb_Output_GreenIND3_OUT_o;

    /* SignalConversion generated from: '<S216>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_aj;

    /* End of Outputs for SubSystem: '<S208>/RheoStatIndyOutputControl_Type2' */
    break;

   case 2:
    if (App_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S208>/AutoBrightIndyOutputControl_Type3' incorporates:
       *  ActionPort: '<S214>/Action Port'
       */
      /* Enable for SwitchCase: '<S208>/Switch Case' incorporates:
       *  Chart: '<S217>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       *  Chart: '<S217>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix'
       */
      Amber_IND_with_Animati_l_Enable(&App_Model_DW.sf_Amber_IND_with_Animation_C_a);
      Green_IND_with_Animati_k_Enable(&App_Model_DW.sf_Green_IND_with_Animation_C_d);

      /* End of Enable for SubSystem: '<S208>/AutoBrightIndyOutputControl_Type3' */
    }

    /* Outputs for IfAction SubSystem: '<S208>/AutoBrightIndyOutputControl_Type3' incorporates:
     *  ActionPort: '<S214>/Action Port'
     */
    /* Chart: '<S217>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
    WPC_IND_Output_With_Auto_Bright(rtu_PostProcessIn_c, &App_Model_B.AutoBrightValue, &App_Model_DW.sf_WPC_IND_Output_With_Auto_B_e);

    /* Chart: '<S217>/Bright_Max_Value_Control_Function_Flow_Graph' */
    Bright_Max_Value_Control_Func_n(rtu_PostProcessIn_f, App_Model_B.AutoBrightValue, &App_Model_B.Var_BrightMaxValue, &App_Model_DW.sf_Bright_Max_Value_Control_F_a);

    /* Chart: '<S217>/Amber_IND_Control_Function_Flow_Graph' */
    Amber_IND_Control_Function_Flow(rtu_PostProcessIn_g, App_Model_B.Var_BrightMaxValue, &rtb_Var_AmberIND_b, &App_Model_DW.sf_Amber_IND_Control_Function_i);

    /* Chart: '<S217>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Amber_IND_with_Animation_Cont_m(App_Model_M, App_Model_B.Var_BrightMaxValue, rtu_PostProcessIn_l, rtu_PostProcessIn_m, &App_Model_B.Var_AmberINDwithAnimation,
      &App_Model_B.sf_Amber_IND_with_Animation_C_a, &App_Model_DW.sf_Amber_IND_with_Animation_C_a);

    /* Chart: '<S217>/Green_IND_Control_Function_Flow_Graph' */
    Green_IND_Control_Function_Flow(rtu_PostProcessIn_mk, App_Model_B.Var_BrightMaxValue, &rtb_Var_GreenIND_l, &App_Model_DW.sf_Green_IND_Control_Functio_bs);

    /* Chart: '<S217>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
    Green_IND_with_Animation_Cont_e(App_Model_M, App_Model_B.Var_BrightMaxValue, rtu_PostProcessIn_m, &App_Model_B.Var_GreenINDwithAnimation1, &App_Model_B.Var_GreenINDwithAnimation2,
      &App_Model_B.Var_GreenINDwithAnimation3, &App_Model_B.sf_Green_IND_with_Animation_C_d, &App_Model_DW.sf_Green_IND_with_Animation_C_d);

    /* Chart: '<S217>/IND_Output_Control_Function_Flow_Graph' */
    IND_Output_Control_Function_F_k(rtu_PostProcessIn_m, rtu_PostProcessIn_fg, rtb_Var_GreenIND_l, rtb_Var_AmberIND_b, App_Model_B.Var_GreenINDwithAnimation2, App_Model_B.Var_GreenINDwithAnimation3,
      App_Model_B.Var_GreenINDwithAnimation1, App_Model_B.Var_AmberINDwithAnimation, &rtb_Output_AmberIND_OUT_go, &rtb_Output_GreenIND_OUT_d, &rtb_Output_GreenIND2_OUT_j, &rtb_Output_GreenIND3_OUT_b,
      &App_Model_DW.sf_IND_Output_Control_Functio_f);

    /* SignalConversion generated from: '<S214>/P_AmberIND_OUT' */
    *rty_IndyOutput_Sig_m = rtb_Output_AmberIND_OUT_go;

    /* SignalConversion generated from: '<S214>/P_GreenIND2_OUT' */
    *rty_IndyOutput_Sig_g = rtb_Output_GreenIND2_OUT_j;

    /* SignalConversion generated from: '<S214>/P_GreenIND3_OUT' */
    *rty_IndyOutput_Sig_l = rtb_Output_GreenIND3_OUT_b;

    /* SignalConversion generated from: '<S214>/P_GreenIND_OUT' */
    *rty_IndyOutput_Sig = rtb_Output_GreenIND_OUT_d;

    /* End of Outputs for SubSystem: '<S208>/AutoBrightIndyOutputControl_Type3' */
    break;
  }

  /* End of SwitchCase: '<S208>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
