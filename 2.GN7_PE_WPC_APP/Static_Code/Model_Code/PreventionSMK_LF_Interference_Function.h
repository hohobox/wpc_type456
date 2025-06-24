/*
 * File: PreventionSMK_LF_Interference_Function.h
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

#ifndef RTW_HEADER_PreventionSMK_LF_Interference_Function_h_
#define RTW_HEADER_PreventionSMK_LF_Interference_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S192>/PreventionSMK_LF_Interference' */
typedef struct {
  sint32 sfEvent;                      /* '<S192>/PreventionSMK_LF_Interference' */
  uint16 Timer_LFOffCheck;             /* '<S192>/PreventionSMK_LF_Interference' */
  uint8 is_active_c3_PreventionOfSMK_LF;/* '<S192>/PreventionSMK_LF_Interference' */
  uint8 is_PreventionSMK_LF_Interferenc;/* '<S192>/PreventionSMK_LF_Interference' */
  uint8 is_active_PreventionSMK_LF_Inte;/* '<S192>/PreventionSMK_LF_Interference' */
  uint8 is_Tick_Timer_LFOffCheck;      /* '<S192>/PreventionSMK_LF_Interference' */
  uint8 is_active_Tick_Timer_LFOffCheck;/* '<S192>/PreventionSMK_LF_Interference' */
  Bool L_LFSearchingOn_IN_prev;        /* '<S192>/PreventionSMK_LF_Interference' */
  Bool L_LFSearchingOn_IN_start;       /* '<S192>/PreventionSMK_LF_Interference' */
  Bool C_LFSearchingOn_prev;           /* '<S192>/PreventionSMK_LF_Interference' */
  Bool C_LFSearchingOn_start;          /* '<S192>/PreventionSMK_LF_Interference' */
} DW_PreventionSMK_LF_Interfere_T;

extern void PreventionSMK_LF_Interfere_Init(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW);
extern void PreventionSMK_LF_Interfer_Reset(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW);
extern void A_PreventionSMK_LF_Interference(Bool rtu_C_SMKOption, Bool rtu_C_LFSearchingOn, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_C_RLDrSw, Bool rtu_C_RRDrSw, Bool rtu_L_LFSearchingOn_IN,
  WPCStatus rtu_WPCStatus, Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW);
extern void PreventionSMK_LF_Inte_klhw_Init(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Int_jzga_Reset(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interference_F(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_a0qx, Bool rtu_PreProcessIn_asou, Bool rtu_PreProcessIn_pgig, Bool
  rtu_PreProcessIn_kksn, Bool rtu_PreProcessIn_alrb, Bool rtu_PreProcessIn_mt0u, Bool *rty_b_LFState);
extern void PreventionSMK_LF_Inte_ggwa_Init(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Int_ae1o_Reset(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interfere_c5sa(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_gmiy, Bool rtu_PreProcessIn_kncn, Bool rtu_PreProcessIn_dvpu, Bool
  rtu_PreProcessIn_b05j, Bool rtu_PreProcessIn_cxfs, Bool rtu_PreProcessIn_lonc, Bool *rty_b_LFState);
extern void PreventionSMK_LF_Inte_myco_Init(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Int_mhh2_Reset(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interfere_dgfk(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_au53, Bool rtu_PreProcessIn_h4gv, Bool rtu_PreProcessIn_lq5i, Bool
  rtu_PreProcessIn_okir, Bool rtu_PreProcessIn_jykw, Bool rtu_PreProcessIn_fswl, Bool *rty_b_LFState);
extern void PreventionSMK_LF_Inte_oour_Init(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Int_gbj0_Reset(Bool *rty_b_LFState);
extern void PreventionSMK_LF_Interfere_movb(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_kk5a, Bool rtu_PreProcessIn_o5yw, Bool rtu_PreProcessIn_e5bp, Bool
  rtu_PreProcessIn_epra, Bool rtu_PreProcessIn_exhh, Bool rtu_PreProcessIn_bzpc, Bool *rty_b_LFState);

#endif                                 /* RTW_HEADER_PreventionSMK_LF_Interference_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
