/*
 * File: OverCurrentDetecting_Function.h
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

#ifndef RTW_HEADER_OverCurrentDetecting_Function_h_
#define RTW_HEADER_OverCurrentDetecting_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S190>/OverCurrentDetecting3_8_LPC' */
typedef struct {
  sint32 sfEvent;                      /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint16 Timer_ReOvrCurr;              /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_active_c4_OverCurrentDetecti;/* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_OverCurrentDetecting;       /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_active_OverCurrentDetecting;/* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_CurrentMonitoring_On;       /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_CurrentMonitoring_FaultOff; /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_CurrentMonitoring_FaultOn;  /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_Tick_Timer_OvrCurr;         /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_active_Tick_Timer_OvrCurr;  /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_Tick_Timer_ReOvrCurr;       /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 is_active_Tick_Timer_ReOvrCurr;/* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 Timer_OvrCurr;                 /* '<S190>/OverCurrentDetecting3_8_LPC' */
  uint8 Counter_OverCurr;              /* '<S190>/OverCurrentDetecting3_8_LPC' */
} DW_OverCurrentDetecting3_8_LP_T;

extern void OverCurrentDetecting3_8_LP_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);
extern void OverCurrentDetecting3_8_L_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);
extern void App_OverCurrentDetecting3_8_LPC(uint16 rtu_CurrentCurr, WPCStatus rtu_WPCStatus, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr,
  DW_OverCurrentDetecting3_8_LP_T *localDW);
extern void OverCurrentDetecting_Funct_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_Func_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void A_OverCurrentDetecting_Function(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting__bnpf_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_kzza_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_Funct_i2cq(WPCStatus rtu_WPC2Status, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting__bh0g_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_lpsa_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_Funct_oslj(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting__ilt2_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_lftl_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);
extern void OverCurrentDetecting_Funct_obzl(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr);

#endif                                 /* RTW_HEADER_OverCurrentDetecting_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
