/*
 * File: WPC_MainControl_Function.h
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

#ifndef RTW_HEADER_WPC_MainControl_Function_h_
#define RTW_HEADER_WPC_MainControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

extern void A_WPC_MainControl_Function_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, uint16
  *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h, Bool *rty_MainOut_Sig_k);
extern void App_Mo_WPC_MainControl_Function(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m, Bool rtu_Main_InSig_l, C_WPCOnOffNvalueSet rtu_Main_InSig_g, Bool rtu_Main_InSig_gy, Bool rtu_Main_InSig_b, Bool
  rtu_Main_InSig_j, Bool rtu_Main_InSig_jy, DeviceState rtu_Main_InSig_a, WPCStatus rtu_Main_InSig_h, Bool rtu_Main_InSig_k, WPCIndUSMState rtu_Main_InSig_lz, Bool rtu_Main_InSig_h0, WPCIndCmdState
  rtu_Main_InSig_k1, Bool rtu_Main_InSig_f, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m, Bool *rty_MainOut_Sig_l, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_gy, uint16
  *rty_MainOut_Sig_b, uint16 *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_jy, Bool *rty_MainOut_Sig_a, BlinkState *rty_MainOut_Sig_h, Bool *rty_MainOut_Sig_k);
extern void WPC_MainControl_Function_g_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16
  *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k);
extern void WPC_MainControl_Functio_f_Reset(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16
  *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k);
extern void App__WPC_MainControl_Function_e(Bool rtu_Main_InSig, Bool rtu_Main_InSig_g, Bool rtu_Main_InSig_b, C_WPCOnOffNvalueSet rtu_Main_InSig_e, Bool rtu_Main_InSig_gc, Bool rtu_Main_InSig_j, Bool
  rtu_Main_InSig_n, Bool rtu_Main_InSig_nt, DeviceState rtu_Main_InSig_p, WPCStatus rtu_Main_InSig_po, Bool rtu_Main_InSig_k, WPCIndUSMState rtu_Main_InSig_nw, Bool rtu_Main_InSig_h, WPC2IndCmdState
  rtu_Main_InSig_n4, Bool rtu_Main_InSig_jg, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_g, Bool *rty_MainOut_Sig_b, Bool *rty_MainOut_Sig_e, Bool *rty_MainOut_Sig_gc, uint16
  *rty_MainOut_Sig_j, uint16 *rty_MainOut_Sig_n, uint16 *rty_MainOut_Sig_nt, Bool *rty_MainOut_Sig_p, BlinkState *rty_MainOut_Sig_po, Bool *rty_MainOut_Sig_k);

#endif                                 /* RTW_HEADER_WPC_MainControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
