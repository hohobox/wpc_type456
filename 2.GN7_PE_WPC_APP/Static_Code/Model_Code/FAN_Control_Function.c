/*
 * File: FAN_Control_Function.c
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
#include "FAN_Control_Function.h"
#include "App_Model_types.h"
#include "App_Model.h"

/*
 * System initialize for atomic system:
 *    '<S21>/FAN_Control_13th'
 *    '<S206>/FAN_Control_13th'
 */
void App_Model_FAN_Control_13th_Init(uint16 *rty_FAN_PWM)
{
  *rty_FAN_PWM = 0U;
}

/*
 * System reset for atomic system:
 *    '<S21>/FAN_Control_13th'
 *    '<S206>/FAN_Control_13th'
 */
void App_Mode_FAN_Control_13th_Reset(uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW)
{
  localDW->is_active_c10_FAN_Control_lib = 0U;
  *rty_FAN_PWM = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S21>/FAN_Control_13th'
 *    '<S206>/FAN_Control_13th'
 */
void App_Model_FAN_Control_13th(Bool rtu_b_FANModeCmd, uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW)
{
  /* Chart: '<S21>/FAN_Control_13th' */
  if (localDW->is_active_c10_FAN_Control_lib == 0U) {
    localDW->is_active_c10_FAN_Control_lib = 1U;
    *rty_FAN_PWM = 0U;
    if (rtu_b_FANModeCmd == On) {
      *rty_FAN_PWM = Par_FANValueLow;
    }
  } else if (rtu_b_FANModeCmd == On) {
    *rty_FAN_PWM = Par_FANValueLow;
  } else {
    *rty_FAN_PWM = 0U;
  }

  /* End of Chart: '<S21>/FAN_Control_13th' */
}

/* System initialize for atomic system: '<S17>/FAN_Control_Function' */
void App_M_FAN_Control_Function_Init(uint16 *rty_FAN_PWM)
{
  /* SystemInitialize for Chart: '<S21>/FAN_Control_13th' */
  App_Model_FAN_Control_13th_Init(rty_FAN_PWM);
}

/* Output and update for atomic system: '<S17>/FAN_Control_Function' */
uint16 App_Model_FAN_Control_Function(Bool rtu_PostProcessIn)
{
  uint16 rty_FAN_PWM_0;

  /* Chart: '<S21>/FAN_Control_13th' */
  App_Model_FAN_Control_13th(rtu_PostProcessIn, &rty_FAN_PWM_0, &App_Model_DW.sf_FAN_Control_13th);
  return rty_FAN_PWM_0;
}

/* System initialize for atomic system: '<S202>/FAN_Control_Function' */
void App_FAN_Control_Function_h_Init(uint16 *rty_FAN_PWM)
{
  /* SystemInitialize for Chart: '<S206>/FAN_Control_13th' */
  App_Model_FAN_Control_13th_Init(rty_FAN_PWM);
}

/* System reset for atomic system: '<S202>/FAN_Control_Function' */
void Ap_FAN_Control_Function_a_Reset(uint16 *rty_FAN_PWM)
{
  /* SystemReset for Chart: '<S206>/FAN_Control_13th' */
  App_Mode_FAN_Control_13th_Reset(rty_FAN_PWM, &App_Model_DW.sf_FAN_Control_13th_o);
}

/* Output and update for atomic system: '<S202>/FAN_Control_Function' */
void App_Mode_FAN_Control_Function_h(Bool rtu_PostProcessIn, uint16 *rty_FAN_PWM)
{
  /* Chart: '<S206>/FAN_Control_13th' */
  App_Model_FAN_Control_13th(rtu_PostProcessIn, rty_FAN_PWM, &App_Model_DW.sf_FAN_Control_13th_o);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
