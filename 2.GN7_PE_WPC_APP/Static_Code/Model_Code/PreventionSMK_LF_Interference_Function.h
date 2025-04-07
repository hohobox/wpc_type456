/*
 * File: PreventionSMK_LF_Interference_Function.h
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

#ifndef RTW_HEADER_PreventionSMK_LF_Interference_Function_h_
#define RTW_HEADER_PreventionSMK_LF_Interference_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S184>/PreventionSMK_LF_Interference' */
typedef struct {
  sint32 sfEvent;                      /* '<S184>/PreventionSMK_LF_Interference' */
  uint16 Timer_LFOffCheck;             /* '<S184>/PreventionSMK_LF_Interference' */
  uint8 is_active_c3_PreventionOfSMK_LF;/* '<S184>/PreventionSMK_LF_Interference' */
  uint8 is_PreventionSMK_LF_Interferenc;/* '<S184>/PreventionSMK_LF_Interference' */
  uint8 is_active_PreventionSMK_LF_Inte;/* '<S184>/PreventionSMK_LF_Interference' */
  uint8 is_Tick_Timer_LFOffCheck;      /* '<S184>/PreventionSMK_LF_Interference' */
  uint8 is_active_Tick_Timer_LFOffCheck;/* '<S184>/PreventionSMK_LF_Interference' */
  Bool L_LFSearchingOn_IN_prev;        /* '<S184>/PreventionSMK_LF_Interference' */
  Bool L_LFSearchingOn_IN_start;       /* '<S184>/PreventionSMK_LF_Interference' */
  Bool C_LFSearchingOn_prev;           /* '<S184>/PreventionSMK_LF_Interference' */
  Bool C_LFSearchingOn_start;          /* '<S184>/PreventionSMK_LF_Interference' */
} DW_PreventionSMK_LF_Interfere_T;

extern void PreventionSMK_LF_Interfere_Init(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW);
extern void PreventionSMK_LF_Interfer_Reset(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW);
extern void A_PreventionSMK_LF_Interference(Bool rtu_C_SMKOption, Bool rtu_C_LFSearchingOn, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_C_RLDrSw, Bool rtu_C_RRDrSw, Bool rtu_L_LFSearchingOn_IN,
  WPCStatus rtu_WPCStatus, Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW);
extern void PreventionSMK_LF_Interfe_k_Init(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interference_F(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_a, Bool rtu_PreProcessIn_as, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_k, Bool
  rtu_PreProcessIn_al, Bool rtu_PreProcessIn_m, Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interfe_p_Init(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interf_m_Reset(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interference_c(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_g, Bool rtu_PreProcessIn_k, Bool rtu_PreProcessIn_d, Bool rtu_PreProcessIn_b, Bool
  rtu_PreProcessIn_c, Bool rtu_PreProcessIn_l, Bool *rty_b_LFState);

#endif                                 /* RTW_HEADER_PreventionSMK_LF_Interference_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
