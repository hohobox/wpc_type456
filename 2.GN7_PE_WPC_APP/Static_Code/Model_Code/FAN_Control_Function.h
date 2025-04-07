/*
 * File: FAN_Control_Function.h
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

#ifndef RTW_HEADER_FAN_Control_Function_h_
#define RTW_HEADER_FAN_Control_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S21>/FAN_Control_13th' */
typedef struct {
  uint8 is_active_c10_FAN_Control_lib; /* '<S21>/FAN_Control_13th' */
} DW_FAN_Control_13th_App_Model_T;

extern void App_Model_FAN_Control_13th_Init(uint16 *rty_FAN_PWM);
extern void App_Mode_FAN_Control_13th_Reset(uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW);
extern void App_Model_FAN_Control_13th(Bool rtu_b_FANModeCmd, uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW);
extern void App_M_FAN_Control_Function_Init(uint16 *rty_FAN_PWM);
extern uint16 App_Model_FAN_Control_Function(Bool rtu_PostProcessIn);
extern void App_FAN_Control_Function_h_Init(uint16 *rty_FAN_PWM);
extern void Ap_FAN_Control_Function_a_Reset(uint16 *rty_FAN_PWM);
extern void App_Mode_FAN_Control_Function_h(Bool rtu_PostProcessIn, uint16 *rty_FAN_PWM);

#endif                                 /* RTW_HEADER_FAN_Control_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
