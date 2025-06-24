/*
 * File: FAN_Control_Function.h
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

#ifndef RTW_HEADER_FAN_Control_Function_h_
#define RTW_HEADER_FAN_Control_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S26>/FAN_Control_13th' */
typedef struct {
  uint8 is_active_c10_FAN_Control_lib; /* '<S26>/FAN_Control_13th' */
} DW_FAN_Control_13th_App_Model_T;

/* Block states (default storage) for system '<S30>/FAN_Out1Control' */
typedef struct {
  uint8 is_active_c14_FAN_Control_lib; /* '<S30>/FAN_Out1Control' */
} DW_FAN_Out1Control_App_Model_T;

/* Block states (default storage) for system '<S30>/FAN_USM1_Control' */
typedef struct {
  uint8 is_active_c13_FAN_Control_lib; /* '<S30>/FAN_USM1_Control' */
  uint8 is_USMSettingControl;          /* '<S30>/FAN_USM1_Control' */
  C_ProfileIDRValue CurProfile;        /* '<S30>/FAN_USM1_Control' */
  FANSpeed FANSpeedSet_prev;           /* '<S30>/FAN_USM1_Control' */
  FANSpeed FANSpeedSet_start;          /* '<S30>/FAN_USM1_Control' */
  C_USMReset C_USMReset_prev;          /* '<S30>/FAN_USM1_Control' */
  C_USMReset C_USMReset_start;         /* '<S30>/FAN_USM1_Control' */
} DW_FAN_USM1_Control_App_Model_T;

extern void App_Model_FAN_Control_13th_Init(uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW);
extern void App_Mode_FAN_Control_13th_Reset(uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW);
extern void App_Model_FAN_Control_13th(Bool rtu_b_FANModeCmd, uint16 *rty_FAN_PWM, DW_FAN_Control_13th_App_Model_T *localDW);
extern void App_Model_FAN_Out1Control_Init(uint16 *rty_WPC_FAN_PWM, DW_FAN_Out1Control_App_Model_T *localDW);
extern void App_Model_FAN_Out1Control_Reset(uint16 *rty_WPC_FAN_PWM, DW_FAN_Out1Control_App_Model_T *localDW);
extern void App_Model_FAN_Out1Control(uint16 rtu_USMFAN_PWM, Bool rtu_b_FANModeCmd, uint16 *rty_WPC_FAN_PWM, DW_FAN_Out1Control_App_Model_T *localDW);
extern void App_Model_FAN_USM1_Control_Init(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);
extern void App_Mode_FAN_USM1_Control_Reset(uint16 *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);
extern void App_Model_FAN_USM1_Control(C_ProfileIDRValue rtu_C_ProfileIDRValue, C_ProfileIDRValue rtu_C_AVN_ProfileIDRValue, FANSpeed rtu_FANSpeedSet, C_USMReset rtu_C_USMReset, uint16
  *rty_USM_WPCFAN_PWM, FANDutyRatio *rty_FANDutyRatioSta, DW_FAN_USM1_Control_App_Model_T *localDW);
extern void App_M_FAN_Control_Function_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_dttb);
extern void App__FAN_Control_Function_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_dttb);
extern void App_Model_FAN_Control_Function(Bool rtu_PostProcessIn, C_ProfileIDRValue rtu_PostProcessIn_dttb, C_ProfileIDRValue rtu_PostProcessIn_nvoj, FANSpeed rtu_PostProcessIn_g4ca, C_USMReset
  rtu_PostProcessIn_ch2y, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_dttb);
extern void FAN_Control_Function_hj2b_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_plxq);
extern void FAN_Control_Function_mo3f_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_plxq);
extern void App_M_FAN_Control_Function_kz0x(Bool rtu_PostProcessIn, C_ProfileIDRValue rtu_PostProcessIn_plxq, C_ProfileIDRValue rtu_PostProcessIn_f20n, FANSpeed rtu_PostProcessIn_jgez, C_USMReset
  rtu_PostProcessIn_prn1, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_plxq);
extern void FAN_Control_Function_iqwo_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_gxyj);
extern void FAN_Control_Function_h0nw_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_gxyj);
extern void App_M_FAN_Control_Function_nnca(FANSpeed rtu_PostProcessIn, C_USMReset rtu_PostProcessIn_gxyj, Bool rtu_PostProcessIn_lhw0, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_gxyj);
extern void FAN_Control_Function_gebo_Init(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_pqgs);
extern void FAN_Control_Function_a5e3_Reset(uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_pqgs);
extern void App_M_FAN_Control_Function_h0dg(Bool rtu_PostProcessIn, C_ProfileIDRValue rtu_PostProcessIn_pqgs, C_ProfileIDRValue rtu_PostProcessIn_l0vi, FANSpeed rtu_PostProcessIn_g45y, C_USMReset
  rtu_PostProcessIn_od5b, uint16 *rty_FANOut_Sig, FANDutyRatio *rty_FANOut_Sig_pqgs);

#endif                                 /* RTW_HEADER_FAN_Control_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
