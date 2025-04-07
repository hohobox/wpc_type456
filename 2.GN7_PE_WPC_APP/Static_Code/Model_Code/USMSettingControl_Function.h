/*
 * File: USMSettingControl_Function.h
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

#ifndef RTW_HEADER_USMSettingControl_Function_h_
#define RTW_HEADER_USMSettingControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

extern void USMSettingControl_Function_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_b);
extern void App__USMSettingControl_Function(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_b, C_USMReset rtu_InputSig_d, C_ProfileIDRValue rtu_InputSig_i, C_ProfileIDRValue rtu_InputSig_h,
  C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_b);
extern void USMSettingControl_Functi_i_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g);
extern void Ap_USMSettingControl_Function_h(Bool rtu_DWPC2_InputSig, C_WPCOnOffNvalueSet rtu_DWPC2_InputSig_g, C_USMReset rtu_DWPC2_InputSig_k, C_ProfileIDRValue rtu_DWPC2_InputSig_gy,
  C_ProfileIDRValue rtu_DWPC2_InputSig_e, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g);

#endif                                 /* RTW_HEADER_USMSettingControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
