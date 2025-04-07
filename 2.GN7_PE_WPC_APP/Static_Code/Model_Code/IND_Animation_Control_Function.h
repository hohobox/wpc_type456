/*
 * File: IND_Animation_Control_Function.h
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

#ifndef RTW_HEADER_IND_Animation_Control_Function_h_
#define RTW_HEADER_IND_Animation_Control_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
typedef struct {
  sint32 sfEvent;                      /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint32 Timer_INDPhaseState;          /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_active_c198_WPC_IND_Animatio;/* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPC_IND_Command_State_Contr;/* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_active_RWPC_IND_Command_Stat;/* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPCINDCmdState_Charging;   /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPCINDCmdState_Off;        /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPCINDCmdState_3rdSync;    /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPCINDCmdState_2ndSync;    /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPCINDCmdState_1stSync;    /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_RWPCINDCmdState_Error;      /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_INDPhaseState;              /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  uint8 is_active_INDPhaseState;       /* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPCIndSyncVal Input_CAN_RWPCIndSyncVal_prev;/* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPCIndSyncVal Input_CAN_RWPCIndSyncVal_start;/* '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
} DW_RWPC_IND_Command_State_Con_T;

extern void RWPC_IND_Command_State_Con_Init(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
extern void RWPC_IND_Command_State_Co_Reset(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
extern void RWPC_IND_Command_State_Control_(RWPCIndSyncVal rtu_Input_CAN_RWPCIndSyncVal, RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
extern void IND_Animation_Control_Func_Init(WPCIndUSMState *rty_INDUSM_Sig, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l);
extern void IND_Animation_Control_Function(WPC2IndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_p, C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState
  rtu_PostProcessIn_j, WPCIndUSMState rtu_PostProcessIn_k, Bool rtu_PostProcessIn_m, C_ProfileIDRValue rtu_PostProcessIn_d, C_ProfileIDRValue rtu_PostProcessIn_h, Bool rtu_PostProcessIn_d3,
  WPCAnimationNvalueSet rtu_PostProcessIn_hn, C_USMReset rtu_PostProcessIn_c, WPCIndUSMState *rty_INDUSM_Sig, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l);
extern void IND_Animation_Control_Fu_b_Init(WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);
extern void IND_Animation_Control_F_g_Reset(WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);
extern void IND_Animation_Control_Functio_i(C_WPCIndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_o, C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState
  rtu_PostProcessIn_n, WPCIndUSMState rtu_PostProcessIn_j, Bool rtu_PostProcessIn_nk, WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);

#endif                                 /* RTW_HEADER_IND_Animation_Control_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
