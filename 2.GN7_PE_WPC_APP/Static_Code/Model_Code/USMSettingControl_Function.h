/*
 * File: USMSettingControl_Function.h
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

#ifndef RTW_HEADER_USMSettingControl_Function_h_
#define RTW_HEADER_USMSettingControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S24>/USMSettingControl_Non_NFC' */
typedef struct {
  uint8 is_active_c17_USMSettingControl;/* '<S205>/WPC_USMSettingControl2_M' */
  uint8 is_USMSettingControl;          /* '<S205>/WPC_USMSettingControl2_M' */
  C_WPCOnOffNvalueSet C_WPCOnOffNValueSet_prev;/* '<S205>/WPC_USMSettingControl2_M' */
  C_WPCOnOffNvalueSet C_WPCOnOffNValueSet_start;/* '<S205>/WPC_USMSettingControl2_M' */
  C_ProfileIDRValue CurProfile;        /* '<S205>/WPC_USMSettingControl2_M' */
  C_USMReset C_USMReset_prev;          /* '<S205>/WPC_USMSettingControl2_M' */
  C_USMReset C_USMReset_start;         /* '<S205>/WPC_USMSettingControl2_M' */
} DW_USMSettingControl_Non_NFC__T;

/* Block states (default storage) for system '<S24>/USMSettingControl_NFC' */
typedef struct {
  uint8 is_active_c18_USMSettingControl;/* '<S204>/WPC_USMSettingControl3_M' */
  uint8 is_USMSettingControl;          /* '<S204>/WPC_USMSettingControl3_M' */
  C_WPCOnOffNvalueSet C_WPCOnOffNValueSet_prev;/* '<S204>/WPC_USMSettingControl3_M' */
  C_WPCOnOffNvalueSet C_WPCOnOffNValueSet_start;/* '<S204>/WPC_USMSettingControl3_M' */
  C_ProfileIDRValue CurProfile;        /* '<S204>/WPC_USMSettingControl3_M' */
  C_USMReset C_USMReset_prev;          /* '<S204>/WPC_USMSettingControl3_M' */
  C_USMReset C_USMReset_start;         /* '<S204>/WPC_USMSettingControl3_M' */
} DW_USMSettingControl_NFC_App__T;

extern void USMSettingControl_Non_NFC_Init(DW_USMSettingControl_Non_NFC__T *localDW);
extern void App_M_USMSettingControl_Non_NFC(C_WPCOnOffNvalueSet rtu_C_WPCOnOffNValueSet, C_USMReset rtu_C_USMReset, C_ProfileIDRValue rtu_C_CF_AVN_ProfileIDRValue, C_WPCOnOffNvalueSet *rty_C_WPCRValue,
  C_WPCOnOffNvalueSet *rty_WPCSWOption, DW_USMSettingControl_Non_NFC__T *localDW);
extern void App__USMSettingControl_NFC_Init(DW_USMSettingControl_NFC_App__T *localDW);
extern void App_Model_USMSettingControl_NFC(C_WPCOnOffNvalueSet rtu_C_WPCOnOffNValueSet, C_USMReset rtu_C_USMReset, C_ProfileIDRValue rtu_C_IAU_ProfileIDRVal, C_ProfileIDRValue
  rtu_C_CF_AVN_ProfileIDRValue, C_WPCOnOffNvalueSet *rty_C_WPCRValue, C_WPCOnOffNvalueSet *rty_WPCSWOption, DW_USMSettingControl_NFC_App__T *localDW);
extern void USMSettingControl_Function_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_bklu);
extern void App__USMSettingControl_Function(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_bklu, C_USMReset rtu_InputSig_de4j, C_ProfileIDRValue rtu_InputSig_izcl, C_ProfileIDRValue
  rtu_InputSig_hvqe, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_bklu);
extern void USMSettingControl_Fun_dunh_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_gnez);
extern void USMSettingControl_Function_hux4(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_gnez, C_USMReset rtu_InputSig_knyt, C_ProfileIDRValue rtu_InputSig_gykk, C_ProfileIDRValue
  rtu_InputSig_es0h, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_gnez);
extern void USMSettingControl_Fun_o1by_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_eyil);
extern void USMSettingControl_Fu_p40r_Reset(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_eyil);
extern void USMSettingControl_Function_gulk(C_WPCOnOffNvalueSet rtu_InputSig, C_USMReset rtu_InputSig_eyil, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_eyil);
extern void USMSettingControl_Fun_j1sr_Init(C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g3ze);
extern void USMSettingControl_Function_k3rq(Bool rtu_InputSig, C_WPCOnOffNvalueSet rtu_InputSig_g3ze, C_USMReset rtu_InputSig_iwak, C_ProfileIDRValue rtu_InputSig_pnns, C_ProfileIDRValue
  rtu_InputSig_mf5g, C_WPCOnOffNvalueSet *rty_USM_Sig, C_WPCOnOffNvalueSet *rty_USM_Sig_g3ze);

#endif                                 /* RTW_HEADER_USMSettingControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
