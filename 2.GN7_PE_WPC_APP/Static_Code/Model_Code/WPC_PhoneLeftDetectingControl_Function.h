/*
 * File: WPC_PhoneLeftDetectingControl_Function.h
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

#ifndef RTW_HEADER_WPC_PhoneLeftDetectingControl_Function_h_
#define RTW_HEADER_WPC_PhoneLeftDetectingControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
typedef struct {
  uint8 is_active_c1_WPC_PhoneLeftDetec;/* '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
} DW_WPC_PhoneLeftDetectingCont_T;

extern void WPC_PhoneLeftDetectingCont_Init(C_WPCWarning *rty_Output_PhoneLeftWarningWPCS, DW_WPC_PhoneLeftDetectingCont_T *localDW);
extern void WPC_PhoneLeftDetectingCon_Reset(C_WPCWarning *rty_Output_PhoneLeftWarningWPCS, DW_WPC_PhoneLeftDetectingCont_T *localDW);
extern void WPC_PhoneLeftDetectingControlFu(WPCStatus rtu_Input_OPT_WPCStatus, Bool rtu_Input_OPT_b_MultiCardDetect, C_WPCWarning *rty_Output_PhoneLeftWarningWPCS, DW_WPC_PhoneLeftDetectingCont_T
  *localDW);
extern void WPC_PhoneLeftDetectin_fcrj_Init(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetecti_esdl_Reset(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetectingControl_F(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetectin_ee2l_Init(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetecti_lukg_Reset(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetectingCont_k5ur(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn, C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetectin_nhlp_Init(void);
extern void WPC_PhoneLeftDetecti_grzc_Reset(void);
extern void WPC_PhoneLeftDetectingCont_e5zj(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn);
extern void WPC_PhoneLeftDetectin_l2ay_Init(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetecti_fmai_Reset(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);
extern void WPC_PhoneLeftDetectingCont_evze(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat);

#endif                                 /* RTW_HEADER_WPC_PhoneLeftDetectingControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
