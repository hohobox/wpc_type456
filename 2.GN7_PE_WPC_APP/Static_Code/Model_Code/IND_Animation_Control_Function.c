/*
 * File: IND_Animation_Control_Function.c
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

#include "App_Model_types.h"
#include "IND_Animation_Control_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
#define Ap_IN_RWPCINDCmdState_1stChrgOn ((uint8)2U)
#define Ap_IN_RWPCINDCmdState_2ndChrgOn ((uint8)2U)
#define Ap_IN_RWPCINDCmdState_3rdChrgOn ((uint8)2U)
#define Ap_IN_RWPCINDCmdState_ErrorOn_2 ((uint8)3U)
#define App_IN_RWPCINDCmdState_Charging ((uint8)1U)
#define App_IN_RWPCINDCmdState_ErrorOff ((uint8)1U)
#define App_Mo_IN_RWPCINDCmdState_Error ((uint8)3U)
#define App_Mode_IN_RWPCINDCmdState_Off ((uint8)4U)
#define App_Model_CALL_EVENT           (-1)
#define App_Model_IN_INDPhaseState_Off ((uint8)1U)
#define App_Model_IN_INDPhaseState_On  ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define App__IN_RWPCINDCmdState_1stSync ((uint8)1U)
#define App__IN_RWPCINDCmdState_2ndSync ((uint8)2U)
#define App__IN_RWPCINDCmdState_3rdSync ((uint8)3U)
#define App__IN_RWPCINDCmdState_Default ((uint8)2U)
#define App__IN_RWPCINDCmdState_ErrorOn ((uint8)2U)
#define IN_RWPCINDCmdState_1stChrgFadeI ((uint8)1U)
#define IN_RWPCINDCmdState_2ndChrgFadeI ((uint8)1U)
#define IN_RWPCINDCmdState_3rdChrgFadeI ((uint8)1U)
#define IN_RWPCINDCmdState_ChrgFadeOut ((uint8)1U)
#define event_CancelTimer_INDPhaseState (0)
#define event_StartTimer_INDPhaseState (1)

/* Named constants for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
#define Ap_event_CancelTimer_INDFadeOut (1)
#define App_IN_WPCINDAnimationError_Off ((uint8)1U)
#define App_IN_WPCINDAnimation_Charging ((uint8)1U)
#define App_M_event_StartTimer_INDLight (5)
#define App_Mo_IN_WPCINDAnimation_Error ((uint8)2U)
#define App_Mod_IN_WPCINDAnimation_Init ((uint8)3U)
#define App_Model_CALL_EVENT_ee        (-1)
#define App_Model_IN_INDFadeIn_Off     ((uint8)1U)
#define App_Model_IN_INDFadeIn_On      ((uint8)2U)
#define App_Model_IN_INDFadeOut_Off    ((uint8)1U)
#define App_Model_IN_INDFadeOut_On     ((uint8)2U)
#define App_Model_IN_INDLight_Off      ((uint8)1U)
#define App_Model_IN_INDLight_On       ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_k1 ((uint8)0U)
#define App__IN_WPCINDAnimationError_On ((uint8)2U)
#define App__event_CancelTimer_INDLight (2)
#define App__event_StartTimer_INDFadeIn (3)
#define App_event_CancelTimer_INDFadeIn (0)
#define App_event_StartTimer_INDFadeOut (4)
#define IN_WPCINDAnimationCharging_1stF ((uint8)1U)
#define IN_WPCINDAnimationCharging_1stO ((uint8)2U)
#define IN_WPCINDAnimationCharging_1stS ((uint8)1U)
#define IN_WPCINDAnimationCharging_2ndF ((uint8)1U)
#define IN_WPCINDAnimationCharging_2ndO ((uint8)2U)
#define IN_WPCINDAnimationCharging_2ndS ((uint8)2U)
#define IN_WPCINDAnimationCharging_3rdF ((uint8)1U)
#define IN_WPCINDAnimationCharging_3rdO ((uint8)2U)
#define IN_WPCINDAnimationCharging_3rdS ((uint8)3U)
#define IN_WPCINDAnimationCharging_Acti ((uint8)1U)
#define IN_WPCINDAnimationCharging_Off ((uint8)4U)
#define IN_WPCINDAnimationCharging_Pr_i ((uint8)4U)
#define IN_WPCINDAnimationCharging_Pr_p ((uint8)6U)
#define IN_WPCINDAnimationCharging_PreN ((uint8)2U)
#define IN_WPCINDAnimationCharging_PreR ((uint8)3U)
#define IN_WPCINDAnimationCharging_PreW ((uint8)5U)
#define IN_WPCINDAnimationError_PreNone ((uint8)3U)
#define IN_WPCINDAnimationError_PreRWPC ((uint8)4U)
#define IN_WPCINDAnimationError_PreRW_l ((uint8)5U)
#define IN_WPCINDAnimationError_PreWPC2 ((uint8)6U)
#define IN_WPCINDAnimationError_PreWP_f ((uint8)7U)

/* Named constants for Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
#define A_IN_INDAnimationUSM_NotApplied ((uint8)2U)
#define A_IN_INDAnimationUSM_ProfileOne ((uint8)2U)
#define A_IN_INDAnimationUSM_ProfileTwo ((uint8)3U)
#define App_Mo_IN_INDAnimationUSM_Guest ((uint8)1U)
#define App__IN_INDAnimationUSM_Applied ((uint8)1U)

/* Named constants for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
#define A_event_CancelTimer_INDFadeIn_g (0)
#define A_event_StartTimer_INDFadeOut_k (4)
#define Ap_IN_WPC2INDAnimationError_Off ((uint8)1U)
#define Ap_IN_WPC2INDAnimation_Charging ((uint8)1U)
#define Ap_event_CancelTimer_INDLight_b (2)
#define Ap_event_StartTimer_INDFadeIn_n (3)
#define App_IN_WPC2INDAnimationError_On ((uint8)2U)
#define App_M_IN_WPC2INDAnimation_Error ((uint8)2U)
#define App_Mo_IN_WPC2INDAnimation_Init ((uint8)3U)
#define App_Model_CALL_EVENT_ct        (-1)
#define App_Model_IN_INDFadeIn_Off_l   ((uint8)1U)
#define App_Model_IN_INDFadeIn_On_d    ((uint8)2U)
#define App_Model_IN_INDFadeOut_Off_e  ((uint8)1U)
#define App_Model_IN_INDFadeOut_On_e   ((uint8)2U)
#define App_Model_IN_INDLight2_Off     ((uint8)1U)
#define App_Model_IN_INDLight2_On      ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_kl ((uint8)0U)
#define App_event_StartTimer_INDLight_i (5)
#define IN_WPC2INDAnimationCharging_1_c ((uint8)1U)
#define IN_WPC2INDAnimationCharging_1_m ((uint8)2U)
#define IN_WPC2INDAnimationCharging_1st ((uint8)1U)
#define IN_WPC2INDAnimationCharging_2_a ((uint8)1U)
#define IN_WPC2INDAnimationCharging_2_j ((uint8)2U)
#define IN_WPC2INDAnimationCharging_2nd ((uint8)2U)
#define IN_WPC2INDAnimationCharging_3_k ((uint8)2U)
#define IN_WPC2INDAnimationCharging_3rd ((uint8)1U)
#define IN_WPC2INDAnimationCharging_Act ((uint8)1U)
#define IN_WPC2INDAnimationCharging_Off ((uint8)3U)
#define IN_WPC2INDAnimationCharging_P_m ((uint8)3U)
#define IN_WPC2INDAnimationCharging_P_n ((uint8)5U)
#define IN_WPC2INDAnimationCharging_P_o ((uint8)4U)
#define IN_WPC2INDAnimationCharging_Pre ((uint8)2U)
#define IN_WPC2INDAnimationCharging__n2 ((uint8)6U)
#define IN_WPC2INDAnimationError_PreNon ((uint8)3U)
#define IN_WPC2INDAnimationError_PreRWP ((uint8)4U)
#define IN_WPC2INDAnimationError_PreWPC ((uint8)5U)
#define IN_WPCINDAnimationCharging_3r_e ((uint8)4U)
#define IN_WPCINDAnimationError_PreRW_a ((uint8)6U)
#define IN_WPCINDAnimationError_PreWPC ((uint8)7U)
#define event_CancelTimer_INDFadeOut_n (1)

/* Forward declaration for local functions */
static void App_Model_INDPhaseState(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_1(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_2(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_3(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_C(DW_RWPC_IND_Command_State_Con_T *localDW);
static void App_Mo_RWPCINDCmdState_Charging(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_E(DW_RWPC_IND_Command_State_Con_T *localDW);

/* Forward declaration for local functions */
static void App_Model_INDLight(void);
static void App_Model_INDFadeIn(void);
static void exit_internal_WPCINDAnimationCh(void);
static void enter_internal_WPCINDAnimatio_a(WPC2IndCmdState rtu_PostProcessIn_j, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void exit_internal_WPCINDAnimation_d(void);
static void enter_atomic_WPCINDAnimationCha(WPCIndCmdState *rty_INDAnimation_Sig_l);
static void exit_internal_WPCINDAnimatio_d4(void);
static void App_Model_INDFadeOut(void);
static void enter_internal_WPCINDAnimatio_b(WPCIndCmdState *rty_INDAnimation_Sig_l);
static void enter_internal_WPCINDAnimatio_m(WPC2IndCmdState rtu_PostProcessIn_j, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void exit_internal_WPCINDAnimation_j(void);
static void App_Model_TypeCont(WPCIndUSMState rtu_PostProcessIn_k, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void WPCINDAnimationCharging_Active(C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState rtu_PostProcessIn_j, WPCIndUSMState rtu_PostProcessIn_k, C_WPCIndSyncVal
  *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void enter_internal_WPCINDAnimationC(WPC2IndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_p, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState rtu_PostProcessIn_j, C_WPCIndSyncVal
  *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void enter_atomic_WPCINDAnimationErr(C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void App_Model_INDErrorOnOut(WPCIndCmdState *rty_INDAnimation_Sig_l);
static void App_Model_WPCINDAnimation_Error(C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPCIndUSMState rtu_PostProcessIn_k, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *
  rty_INDAnimation_Sig_l);
static void IND_Animation_Sync_Control_Func(WPC2IndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_p, C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState
  rtu_PostProcessIn_j, WPCIndUSMState rtu_PostProcessIn_k, Bool rtu_PostProcessIn_m, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l);
static void App_Model_INDUSMProfileTwo(WPCIndUSMState *rty_INDUSM_Sig);
static void App_Model_INDUSMGuest(WPCIndUSMState *rty_INDUSM_Sig);
static void App_Model_INDUSMProfileOne(WPCIndUSMState *rty_INDUSM_Sig);

/* Forward declaration for local functions */
static void App_Model_INDLight_i(void);
static void App_Model_INDFadeIn_d(void);
static void exit_internal_WPC2INDAnimationC(void);
static void enter_internal_WPC2INDAnimati_d(WPCIndCmdState rtu_PostProcessIn_n, WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void exit_internal_WPC2INDAnimatio_c(void);
static void enter_atomic_WPC2INDAnimationCh(WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void enter_internal_WPC2INDAnimati_a(WPCIndCmdState rtu_PostProcessIn_n, WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void App_Model_INDFadeOut_g(void);
static void exit_internal_WPC2INDAnimatio_p(void);
static void App_Model_TypeCont_c(WPCIndUSMState rtu_PostProcessIn_j, WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void exit_internal_WPCINDAnimation_m(void);
static void enter_internal_WPC2INDAnimati_i(WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void WPC2INDAnimationCharging_Active(C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState rtu_PostProcessIn_n, WPCIndUSMState rtu_PostProcessIn_j, WPC2IndSyncVal
  *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void enter_internal_WPC2INDAnimation(C_WPCIndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_o, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState rtu_PostProcessIn_n, WPC2IndSyncVal
  *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void enter_atomic_WPC2INDAnimationEr(WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void App_Model_INDErrorOnOut_g(WPC2IndCmdState *rty_INDAnimation_Sig_o);
static void App_Mode_WPC2INDAnimation_Error(C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndUSMState rtu_PostProcessIn_j, WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *
  rty_INDAnimation_Sig_o);
static void IND_Animation_Sync_Control_Fu_d(C_WPCIndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_o, C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState
  rtu_PostProcessIn_n, WPCIndUSMState rtu_PostProcessIn_j, Bool rtu_PostProcessIn_nk, WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o);

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Model_INDPhaseState(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_INDPhaseState) {
   case App_Model_IN_INDPhaseState_Off:
    if (localDW->sfEvent == event_StartTimer_INDPhaseState) {
      localDW->is_INDPhaseState = App_Model_IN_INDPhaseState_On;
    }
    break;

   case App_Model_IN_INDPhaseState_On:
    {
      switch (localDW->sfEvent) {
       case event_CancelTimer_INDPhaseState:
        localDW->is_INDPhaseState = App_Model_IN_INDPhaseState_Off;
        localDW->Timer_INDPhaseState = 0U;
        break;

       case event_StartTimer_INDPhaseState:
        localDW->Timer_INDPhaseState = 0U;
        localDW->is_INDPhaseState = App_Model_IN_INDPhaseState_On;
        break;

       default:
        {
          uint32 qY;
          qY = localDW->Timer_INDPhaseState + /*MW:OvSatOk*/ 1U;
          if (localDW->Timer_INDPhaseState + 1U < localDW->Timer_INDPhaseState) {
            qY = MAX_uint32_T;
          }

          localDW->Timer_INDPhaseState = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_1(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_1stSync) {
   case IN_RWPCINDCmdState_1stChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_1stSync = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;

   case Ap_IN_RWPCINDCmdState_1stChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_1stSync = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;
  }
}

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_2(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_2ndSync) {
   case IN_RWPCINDCmdState_2ndChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_2ndSync = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;

   case Ap_IN_RWPCINDCmdState_2ndChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_2ndSync = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;
  }
}

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_3(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_3rdSync) {
   case IN_RWPCINDCmdState_3rdChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_3rdSync = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;

   case Ap_IN_RWPCINDCmdState_3rdChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_3rdSync = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;
  }
}

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_C(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_Charging) {
   case App__IN_RWPCINDCmdState_1stSync:
    exit_internal_RWPCINDCmdState_1(localDW);
    localDW->is_RWPCINDCmdState_Charging = App_Model_IN_NO_ACTIVE_CHILD;
    break;

   case App__IN_RWPCINDCmdState_2ndSync:
    exit_internal_RWPCINDCmdState_2(localDW);
    localDW->is_RWPCINDCmdState_Charging = App_Model_IN_NO_ACTIVE_CHILD;
    break;

   case App__IN_RWPCINDCmdState_3rdSync:
    exit_internal_RWPCINDCmdState_3(localDW);
    localDW->is_RWPCINDCmdState_Charging = App_Model_IN_NO_ACTIVE_CHILD;
    break;

   case App_Mode_IN_RWPCINDCmdState_Off:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_Off = App_Model_IN_NO_ACTIVE_CHILD;
      localDW->is_RWPCINDCmdState_Charging = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;
  }
}

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Mo_RWPCINDCmdState_Charging(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  /* 1 */
  if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndCmdState__Default)) {
    exit_internal_RWPCINDCmdState_C(localDW);
    localDW->is_RWPC_IND_Command_State_Contr = App__IN_RWPCINDCmdState_Default;
    *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;

    /* 1 */
  } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
    sint32 h_previousEvent;
    exit_internal_RWPCINDCmdState_C(localDW);
    localDW->is_RWPC_IND_Command_State_Contr = App_Mo_IN_RWPCINDCmdState_Error;

    /* 1 */
    localDW->is_RWPCINDCmdState_Error = App__IN_RWPCINDCmdState_ErrorOn;
    h_previousEvent = localDW->sfEvent;
    localDW->sfEvent = event_StartTimer_INDPhaseState;
    if (localDW->is_active_INDPhaseState != 0U) {
      App_Model_INDPhaseState(localDW);
    }

    localDW->sfEvent = h_previousEvent;
    *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
  } else {
    switch (localDW->is_RWPCINDCmdState_Charging) {
     case App__IN_RWPCINDCmdState_1stSync:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_1(localDW);
          localDW->is_RWPCINDCmdState_Charging = App_Mode_IN_RWPCINDCmdState_Off;

          /* 1 */
          localDW->is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFadeOut;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_1(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_2ndSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;
        } else {
          switch (localDW->is_RWPCINDCmdState_1stSync) {
           case IN_RWPCINDCmdState_1stChrgFadeI:
            {
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;

              /* 1. */
              if (localDW->Timer_INDPhaseState >= 100U) {
                sint32 h_previousEvent;
                h_previousEvent = localDW->sfEvent;
                localDW->sfEvent = event_CancelTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_1stSync = Ap_IN_RWPCINDCmdState_1stChrgOn;
                localDW->sfEvent = event_StartTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = h_previousEvent;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgOn;
              }
            }
            break;

           case Ap_IN_RWPCINDCmdState_1stChrgOn:
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgOn;
            break;
          }
        }
      }
      break;

     case App__IN_RWPCINDCmdState_2ndSync:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_2(localDW);
          localDW->is_RWPCINDCmdState_Charging = App_Mode_IN_RWPCINDCmdState_Off;

          /* 1 */
          localDW->is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFadeOut;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_2(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_3rdSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_3rdSync = IN_RWPCINDCmdState_3rdChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_2(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_1stSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else {
          switch (localDW->is_RWPCINDCmdState_2ndSync) {
           case IN_RWPCINDCmdState_2ndChrgFadeI:
            {
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;

              /* 1. */
              if (localDW->Timer_INDPhaseState >= 100U) {
                sint32 h_previousEvent;
                h_previousEvent = localDW->sfEvent;
                localDW->sfEvent = event_CancelTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_2ndSync = Ap_IN_RWPCINDCmdState_2ndChrgOn;
                localDW->sfEvent = event_StartTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = h_previousEvent;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__2ndChrgOn;
              }
            }
            break;

           case Ap_IN_RWPCINDCmdState_2ndChrgOn:
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__2ndChrgOn;
            break;
          }
        }
      }
      break;

     case App__IN_RWPCINDCmdState_3rdSync:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_3(localDW);
          localDW->is_RWPCINDCmdState_Charging = App_Mode_IN_RWPCINDCmdState_Off;

          /* 1 */
          localDW->is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFadeOut;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 2 230113 for UnexpectedSync */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_3(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_2ndSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_3(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_1stSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else {
          switch (localDW->is_RWPCINDCmdState_3rdSync) {
           case IN_RWPCINDCmdState_3rdChrgFadeI:
            {
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgFadeIn;

              /* 1. */
              if (localDW->Timer_INDPhaseState >= 100U) {
                sint32 h_previousEvent;
                h_previousEvent = localDW->sfEvent;
                localDW->sfEvent = event_CancelTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_3rdSync = Ap_IN_RWPCINDCmdState_3rdChrgOn;
                localDW->sfEvent = event_StartTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = h_previousEvent;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
              }
            }
            break;

           case Ap_IN_RWPCINDCmdState_3rdChrgOn:
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
            break;
          }
        }
      }
      break;

     case App_Mode_IN_RWPCINDCmdState_Off:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = event_CancelTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->is_RWPCINDCmdState_Off = App_Model_IN_NO_ACTIVE_CHILD;
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_1stSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrgFadeI;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else if (localDW->is_RWPCINDCmdState_Off == IN_RWPCINDCmdState_ChrgFadeOut) {
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_E(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_Error) {
   case App_IN_RWPCINDCmdState_ErrorOff:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_Error = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;

   case App__IN_RWPCINDCmdState_ErrorOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = event_CancelTimer_INDPhaseState;
      if (localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_Error = App_Model_IN_NO_ACTIVE_CHILD;
    }
    break;

   default:
    localDW->is_RWPCINDCmdState_Error = App_Model_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart'
 *    '<S211>/RWPC_IND_Command_State_Control_Function_State_Chart'
 */
void RWPC_IND_Command_State_Con_Init(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT;
  *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;
}

/*
 * System reset for atomic system:
 *    '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart'
 *    '<S211>/RWPC_IND_Command_State_Control_Function_State_Chart'
 */
void RWPC_IND_Command_State_Co_Reset(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT;
  localDW->is_active_INDPhaseState = 0U;
  localDW->is_INDPhaseState = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_active_RWPC_IND_Command_Stat = 0U;
  localDW->is_RWPC_IND_Command_State_Contr = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_RWPCINDCmdState_Charging = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_RWPCINDCmdState_1stSync = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_RWPCINDCmdState_2ndSync = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_RWPCINDCmdState_3rdSync = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_RWPCINDCmdState_Off = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_RWPCINDCmdState_Error = App_Model_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c198_WPC_IND_Animatio = 0U;
  localDW->Timer_INDPhaseState = 0U;
  *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;
  localDW->Input_CAN_RWPCIndSyncVal_prev = RWPCIndSyncVal__Default;
  localDW->Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;
}

/*
 * Output and update for atomic system:
 *    '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart'
 *    '<S211>/RWPC_IND_Command_State_Control_Function_State_Chart'
 */
void RWPC_IND_Command_State_Control_(RWPCIndSyncVal rtu_Input_CAN_RWPCIndSyncVal, RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT;
  localDW->Input_CAN_RWPCIndSyncVal_prev = localDW->Input_CAN_RWPCIndSyncVal_start;
  localDW->Input_CAN_RWPCIndSyncVal_start = rtu_Input_CAN_RWPCIndSyncVal;

  /* Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  if (localDW->is_active_c198_WPC_IND_Animatio == 0U) {
    localDW->Input_CAN_RWPCIndSyncVal_prev = rtu_Input_CAN_RWPCIndSyncVal;
    localDW->is_active_c198_WPC_IND_Animatio = 1U;
    localDW->is_active_INDPhaseState = 1U;
    localDW->is_INDPhaseState = App_Model_IN_INDPhaseState_Off;
    localDW->Timer_INDPhaseState = 0U;
    localDW->is_active_RWPC_IND_Command_Stat = 1U;

    /* 1 */
    localDW->is_RWPC_IND_Command_State_Contr = App__IN_RWPCINDCmdState_Default;
    *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;
  } else {
    if (localDW->is_active_INDPhaseState != 0U) {
      App_Model_INDPhaseState(localDW);
    }

    if (localDW->is_active_RWPC_IND_Command_Stat != 0U) {
      switch (localDW->is_RWPC_IND_Command_State_Contr) {
       case App_IN_RWPCINDCmdState_Charging:
        App_Mo_RWPCINDCmdState_Charging(rty_Var_RWPCIndCmdState, localDW);
        break;

       case App__IN_RWPCINDCmdState_Default:
        *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;

        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
          localDW->is_RWPC_IND_Command_State_Contr = App_IN_RWPCINDCmdState_Charging;
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_3rdSync;
          localDW->is_RWPCINDCmdState_3rdSync = Ap_IN_RWPCINDCmdState_3rdChrgOn;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = -1;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;

          /* 1 */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
          localDW->is_RWPC_IND_Command_State_Contr = App_Mo_IN_RWPCINDCmdState_Error;

          /* 1 */
          localDW->is_RWPCINDCmdState_Error = App__IN_RWPCINDCmdState_ErrorOn;
          localDW->sfEvent = event_StartTimer_INDPhaseState;
          if (localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = -1;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
        }
        break;

       case App_Mo_IN_RWPCINDCmdState_Error:
        {
          /* 1 */
          if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndCmdState__Default)) {
            exit_internal_RWPCINDCmdState_E(localDW);
            localDW->is_RWPC_IND_Command_State_Contr = App__IN_RWPCINDCmdState_Default;
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;

            /* 2 230113 for ReCharge */
          } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
            sint32 c_previousEvent;
            exit_internal_RWPCINDCmdState_E(localDW);
            localDW->is_RWPC_IND_Command_State_Contr = App_IN_RWPCINDCmdState_Charging;
            localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_3rdSync;
            localDW->is_RWPCINDCmdState_3rdSync = Ap_IN_RWPCINDCmdState_3rdChrgOn;
            c_previousEvent = localDW->sfEvent;
            localDW->sfEvent = event_StartTimer_INDPhaseState;
            if (localDW->is_active_INDPhaseState != 0U) {
              App_Model_INDPhaseState(localDW);
            }

            localDW->sfEvent = c_previousEvent;
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
          } else {
            switch (localDW->is_RWPCINDCmdState_Error) {
             case App_IN_RWPCINDCmdState_ErrorOff:
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;

              /* 1. */
              if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
                localDW->sfEvent = event_CancelTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_Error = App__IN_RWPCINDCmdState_ErrorOn;
                localDW->sfEvent = event_StartTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
              }
              break;

             case App__IN_RWPCINDCmdState_ErrorOn:
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;

              /* 1. */
              if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOff)) {
                localDW->sfEvent = event_CancelTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_Error = App_IN_RWPCINDCmdState_ErrorOff;
                localDW->sfEvent = event_StartTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
              } else if (localDW->Timer_INDPhaseState >= 100U) {
                localDW->sfEvent = event_CancelTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_RWPCINDCmdState_Error = Ap_IN_RWPCINDCmdState_ErrorOn_2;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
              }
              break;

             case Ap_IN_RWPCINDCmdState_ErrorOn_2:
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
              if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && (localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOff)) {
                localDW->is_RWPCINDCmdState_Error = App_IN_RWPCINDCmdState_ErrorOff;
                localDW->sfEvent = event_StartTimer_INDPhaseState;
                if (localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
              }
              break;
            }
          }
        }
        break;
      }
    }
  }

  /* End of Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDLight(void)
{
  switch (App_Model_DW.is_INDLight_a) {
   case App_Model_IN_INDLight_Off:
    if (App_Model_DW.sfEvent_oq == App_M_event_StartTimer_INDLight) {
      App_Model_DW.is_INDLight_a = App_Model_IN_INDLight_On;
    }
    break;

   case App_Model_IN_INDLight_On:
    {
      switch (App_Model_DW.sfEvent_oq) {
       case App__event_CancelTimer_INDLight:
        App_Model_DW.is_INDLight_a = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight_j = 0U;
        break;

       case App_M_event_StartTimer_INDLight:
        App_Model_DW.Timer_INDLight_j = 0U;
        App_Model_DW.is_INDLight_a = App_Model_IN_INDLight_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDLight_j + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_INDLight_j + 1U < App_Model_DW.Timer_INDLight_j) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDLight_j = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeIn(void)
{
  switch (App_Model_DW.is_INDFadeIn_j) {
   case App_Model_IN_INDFadeIn_Off:
    if (App_Model_DW.sfEvent_oq == App__event_StartTimer_INDFadeIn) {
      App_Model_DW.is_INDFadeIn_j = App_Model_IN_INDFadeIn_On;
    }
    break;

   case App_Model_IN_INDFadeIn_On:
    {
      switch (App_Model_DW.sfEvent_oq) {
       case App_event_CancelTimer_INDFadeIn:
        App_Model_DW.is_INDFadeIn_j = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_b = 0U;
        break;

       case App__event_StartTimer_INDFadeIn:
        App_Model_DW.Timer_INDFadeIn_b = 0U;
        App_Model_DW.is_INDFadeIn_j = App_Model_IN_INDFadeIn_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeIn_b + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_INDFadeIn_b + 1U < App_Model_DW.Timer_INDFadeIn_b) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeIn_b = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimationCh(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_1stS) {
   case IN_WPCINDAnimationCharging_1stF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
      if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_1stS = App_Model_IN_NO_ACTIVE_CHILD_k1;
    }
    break;

   case IN_WPCINDAnimationCharging_1stO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
      if (App_Model_DW.is_active_INDLight_j != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_1stS = App_Model_IN_NO_ACTIVE_CHILD_k1;
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnimatio_a(WPC2IndCmdState rtu_PostProcessIn_j, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* 1 */
  if ((rtu_PostProcessIn_j == WPC2IndCmdState__2ndChrgOn) || (App_Model_B.Var_RWPCIndCmdState_m == RWPCIndCmdState__2ndChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPCINDAnimationCharging_2ndS = IN_WPCINDAnimationCharging_2ndO;
    c_previousEvent = App_Model_DW.sfEvent_oq;
    App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oq = c_previousEvent;
    *rty_INDAnimation_Sig_l = WPCIndCmdState__2ndChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       [Var_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn] */
    App_Model_DW.is_WPCINDAnimationCharging_2ndS = IN_WPCINDAnimationCharging_2ndF;
    c_previousEvent = App_Model_DW.sfEvent_oq;
    App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
    if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
      App_Model_INDFadeIn();
    }

    App_Model_DW.sfEvent_oq = c_previousEvent;
    *rty_INDAnimation_Sig_l = WPCIndCmdState__2ndChrgFadeIn;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimation_d(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_2ndS) {
   case IN_WPCINDAnimationCharging_2ndF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
      if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_2ndS = App_Model_IN_NO_ACTIVE_CHILD_k1;
    }
    break;

   case IN_WPCINDAnimationCharging_2ndO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
      if (App_Model_DW.is_active_INDLight_j != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_2ndS = App_Model_IN_NO_ACTIVE_CHILD_k1;
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPCINDAnimationCha(WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oq;
  App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
  if (App_Model_DW.is_active_INDLight_j != 0U) {
    App_Model_INDLight();
  }

  /* CancelTimer추가 221219 */
  App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
  if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
    App_Model_INDFadeIn();
  }

  App_Model_DW.sfEvent_oq = b_previousEvent;
  *rty_INDAnimation_Sig_l = WPCIndCmdState__3rdChrgFadeIn;
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimatio_d4(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_3r_a) {
   case IN_WPCINDAnimationCharging_3rdF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
      if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3r_a = App_Model_IN_NO_ACTIVE_CHILD_k1;
    }
    break;

   case IN_WPCINDAnimationCharging_3rdO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
      if (App_Model_DW.is_active_INDLight_j != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3r_a = App_Model_IN_NO_ACTIVE_CHILD_k1;
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeOut(void)
{
  switch (App_Model_DW.is_INDFadeOut_c) {
   case App_Model_IN_INDFadeOut_Off:
    if (App_Model_DW.sfEvent_oq == App_event_StartTimer_INDFadeOut) {
      App_Model_DW.is_INDFadeOut_c = App_Model_IN_INDFadeOut_On;
    }
    break;

   case App_Model_IN_INDFadeOut_On:
    {
      switch (App_Model_DW.sfEvent_oq) {
       case Ap_event_CancelTimer_INDFadeOut:
        App_Model_DW.is_INDFadeOut_c = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_b = 0U;
        break;

       case App_event_StartTimer_INDFadeOut:
        App_Model_DW.Timer_INDFadeOut_b = 0U;
        App_Model_DW.is_INDFadeOut_c = App_Model_IN_INDFadeOut_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeOut_b + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_INDFadeOut_b + 1U < App_Model_DW.Timer_INDFadeOut_b) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeOut_b = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnimatio_b(WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oq;
  App_Model_DW.sfEvent_oq = App_event_StartTimer_INDFadeOut;
  if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
    App_Model_INDFadeOut();
  }

  App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
  if (App_Model_DW.is_active_INDLight_j != 0U) {
    App_Model_INDLight();
  }

  App_Model_DW.sfEvent_oq = b_previousEvent;

  /* 230328 */
  *rty_INDAnimation_Sig_l = WPCIndCmdState__ChrgFadeOut;

  /* 230328 */
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnimatio_m(WPC2IndCmdState rtu_PostProcessIn_j, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* 1 */
  if ((rtu_PostProcessIn_j == WPC2IndCmdState__1stChrgOn) || (App_Model_B.Var_RWPCIndCmdState_m == RWPCIndCmdState__1stChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPCINDAnimationCharging_1stS = IN_WPCINDAnimationCharging_1stO;
    c_previousEvent = App_Model_DW.sfEvent_oq;
    App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oq = c_previousEvent;
    *rty_INDAnimation_Sig_l = WPCIndCmdState__1stChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       [Var_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn ||Var_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut] */
    App_Model_DW.is_WPCINDAnimationCharging_1stS = IN_WPCINDAnimationCharging_1stF;
    c_previousEvent = App_Model_DW.sfEvent_oq;
    App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
    if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
      App_Model_INDFadeIn();
    }

    App_Model_DW.sfEvent_oq = c_previousEvent;
    *rty_INDAnimation_Sig_l = WPCIndCmdState__1stChrgFadeIn;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimation_j(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oq;
  App_Model_DW.sfEvent_oq = Ap_event_CancelTimer_INDFadeOut;
  if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
    App_Model_INDFadeOut();
  }

  App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
  if (App_Model_DW.is_active_INDLight_j != 0U) {
    App_Model_INDLight();
  }

  App_Model_DW.sfEvent_oq = b_previousEvent;
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_TypeCont(WPCIndUSMState rtu_PostProcessIn_k, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* 1 */
  if (rtu_PostProcessIn_k != WPCIndUSMState__Type2) {
    *rty_INDAnimation_Sig_l = WPCIndCmdState__ErrorFadeOut;
  } else {
    *rty_INDAnimation_Sig_l = WPCIndCmdState__ErrorFadeIn;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void WPCINDAnimationCharging_Active(C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState rtu_PostProcessIn_j, WPCIndUSMState rtu_PostProcessIn_k, C_WPCIndSyncVal
  *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_Acti) {
   case IN_WPCINDAnimationCharging_1stS:
    {
      /* 2. Transition start point move to 1stOn */
      if (App_Model_DW.Timer_INDLight_j >= 100U) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimationCh();
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_2ndS;
        *rty_INDAnimation_Sig = WPCIndSyncVal__2ndSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnimatio_a(rtu_PostProcessIn_j, rty_INDAnimation_Sig_l);
      } else if ((App_Model_DW.is_WPCINDAnimationCharging_1stS == IN_WPCINDAnimationCharging_1stF) && (App_Model_DW.Timer_INDFadeIn_b >= 100U)) {
        sint32 k_previousEvent;

        /* 1 */
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
        if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.is_WPCINDAnimationCharging_1stS = IN_WPCINDAnimationCharging_1stO;
        App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        *rty_INDAnimation_Sig_l = WPCIndCmdState__1stChrgOn;
      }
    }
    break;

   case IN_WPCINDAnimationCharging_2ndS:
    {
      /* 2.Transition start point move to 2ndOn */
      if (App_Model_DW.Timer_INDLight_j >= 100U) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimation_d();
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_3rdS;
        *rty_INDAnimation_Sig = WPCIndSyncVal__3rdSync;

        /* CancelTimer추가 221216 */
        App_Model_DW.is_WPCINDAnimationCharging_3r_a = IN_WPCINDAnimationCharging_3rdF;
        enter_atomic_WPCINDAnimationCha(rty_INDAnimation_Sig_l);
      } else if ((App_Model_DW.is_WPCINDAnimationCharging_2ndS == IN_WPCINDAnimationCharging_2ndF) && (App_Model_DW.Timer_INDFadeIn_b >= 100U)) {
        sint32 k_previousEvent;

        /* 1. */
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
        if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.is_WPCINDAnimationCharging_2ndS = IN_WPCINDAnimationCharging_2ndO;
        App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        *rty_INDAnimation_Sig_l = WPCIndCmdState__2ndChrgOn;
      }
    }
    break;

   case IN_WPCINDAnimationCharging_3rdS:
    {
      /* 2.  */
      if (App_Model_DW.Timer_INDLight_j >= 100U) {
        sint32 k_previousEvent;

        /* [Timer_INDFadeOut >= Par_INDFadeOutTime] */
        exit_internal_WPCINDAnimatio_d4();
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_Off;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;

        /* CancelTimer추가 230103 */
        *rty_INDAnimation_Sig = WPCIndSyncVal__Off;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnimatio_b(rty_INDAnimation_Sig_l);
      } else if ((App_Model_DW.is_WPCINDAnimationCharging_3r_a == IN_WPCINDAnimationCharging_3rdF) && (App_Model_DW.Timer_INDFadeIn_b >= 100U)) {
        sint32 k_previousEvent;

        /* 1. */
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
        if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.is_WPCINDAnimationCharging_3r_a = IN_WPCINDAnimationCharging_3rdO;
        App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        *rty_INDAnimation_Sig_l = WPCIndCmdState__3rdChrgOn;
      }
    }
    break;

   case IN_WPCINDAnimationCharging_Off:
    {
      /* 1 */
      if ((App_Model_DW.Timer_INDFadeOut_b >= 100U) && ((rtu_PostProcessIn_l == Charging_error) || (rtu_PostProcessIn_l == NFCCardDetected))) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimation_j();
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Model_IN_NO_ACTIVE_CHILD_k1;

        /* CancelTimer에서 StartTimer로 변경 221216 */
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_WPCINDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_k1;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_IND_Animation_Sync_Control_m = App_Mo_IN_WPCINDAnimation_Error;
        App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
        if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        *rty_INDAnimation_Sig = WPCIndSyncVal__ErrorOn;
        App_Model_TypeCont(rtu_PostProcessIn_k, rty_INDAnimation_Sig_l);

        /* 1 */
        switch (rtu_PostProcessIn_f) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWPC2;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRWPC;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRW_l;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWP_f;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
          break;
        }

        /* 3. */
      } else if (App_Model_DW.Timer_INDLight_j >= 100U) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimation_j();
        k_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_1stS;
        *rty_INDAnimation_Sig = WPCIndSyncVal__1stSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnimatio_m(rtu_PostProcessIn_j, rty_INDAnimation_Sig_l);
      }
    }
    break;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnimationC(WPC2IndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_p, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState rtu_PostProcessIn_j, C_WPCIndSyncVal
  *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* 1 */
  if ((((rtu_PostProcessIn_f == PreSyncAct__WPC2) || (rtu_PostProcessIn_f == PreSyncAct__WPC2RWPC)) && (rtu_PostProcessIn == WPC2IndSyncVal__3rdSync)) || (((rtu_PostProcessIn_f == PreSyncAct__RWPC) ||
        (rtu_PostProcessIn_f == PreSyncAct__RWPCWPC2)) && (rtu_PostProcessIn_p == RWPCIndSyncVal__3rdSync))) {
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_3rdS;
    *rty_INDAnimation_Sig = WPCIndSyncVal__3rdSync;

    /* CancelTimer추가 221216 */
    /* 1 */
    if ((rtu_PostProcessIn_j == WPC2IndCmdState__3rdChrgOn) || (App_Model_B.Var_RWPCIndCmdState_m == RWPCIndCmdState__3rdChrgOn)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3r_a = IN_WPCINDAnimationCharging_3rdO;
      b_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
      if (App_Model_DW.is_active_INDLight_j != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oq = b_previousEvent;
      *rty_INDAnimation_Sig_l = WPCIndCmdState__3rdChrgOn;
    } else {
      /* 2
         Var_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn ||
         Var_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn */
      App_Model_DW.is_WPCINDAnimationCharging_3r_a = IN_WPCINDAnimationCharging_3rdF;
      enter_atomic_WPCINDAnimationCha(rty_INDAnimation_Sig_l);
    }

    /* 2 */
  } else if ((((rtu_PostProcessIn_f == PreSyncAct__WPC2) || (rtu_PostProcessIn_f == PreSyncAct__WPC2RWPC)) && (rtu_PostProcessIn == WPC2IndSyncVal__2ndSync)) || (((rtu_PostProcessIn_f ==
                PreSyncAct__RWPC) || (rtu_PostProcessIn_f == PreSyncAct__RWPCWPC2)) && (rtu_PostProcessIn_p == RWPCIndSyncVal__2ndSync))) {
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_2ndS;
    *rty_INDAnimation_Sig = WPCIndSyncVal__2ndSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnimatio_a(rtu_PostProcessIn_j, rty_INDAnimation_Sig_l);

    /* 3 */
  } else if ((((rtu_PostProcessIn_f == PreSyncAct__WPC2) || (rtu_PostProcessIn_f == PreSyncAct__WPC2RWPC)) && ((rtu_PostProcessIn == WPC2IndSyncVal__1stSync) || (rtu_PostProcessIn ==
                WPC2IndSyncVal__ErrorOff))) || (((rtu_PostProcessIn_f == PreSyncAct__RWPC) || (rtu_PostProcessIn_f == PreSyncAct__RWPCWPC2)) && ((rtu_PostProcessIn_p == RWPCIndSyncVal__1stSync) ||
               (rtu_PostProcessIn_p == RWPCIndSyncVal__ErrorOff)))) {
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_1stS;
    *rty_INDAnimation_Sig = WPCIndSyncVal__1stSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnimatio_m(rtu_PostProcessIn_j, rty_INDAnimation_Sig_l);
  } else {
    sint32 b_previousEvent;

    /* 4 */
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_Off;
    b_previousEvent = App_Model_DW.sfEvent_oq;
    App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oq = b_previousEvent;

    /* CancelTimer추가 230103 */
    *rty_INDAnimation_Sig = WPCIndSyncVal__Off;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnimatio_b(rty_INDAnimation_Sig_l);
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPCINDAnimationErr(C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oq;
  App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
  if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
    App_Model_INDFadeIn();
  }

  App_Model_DW.sfEvent_oq = App_event_StartTimer_INDFadeOut;
  if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
    App_Model_INDFadeOut();
  }

  App_Model_DW.sfEvent_oq = b_previousEvent;
  *rty_INDAnimation_Sig = WPCIndSyncVal__ErrorOff;
  *rty_INDAnimation_Sig_l = WPCIndCmdState__ErrorFadeOut;
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDErrorOnOut(WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* 1 */
  if (App_Model_DW.Timer_INDFadeIn_b >= 100U) {
    *rty_INDAnimation_Sig_l = WPCIndCmdState__ErrorOn;
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_WPCINDAnimation_Error(C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPCIndUSMState rtu_PostProcessIn_k, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *
  rty_INDAnimation_Sig_l)
{
  if ((App_Model_DW.b_SyncAmber_prev_h != App_Model_DW.b_SyncAmber_start_h) && (App_Model_DW.b_SyncAmber_start_h == Off)) {
    sint32 h_previousEvent;
    switch (App_Model_DW.is_WPCINDAnimation_Error) {
     case App_IN_WPCINDAnimationError_Off:
      h_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = Ap_event_CancelTimer_INDFadeOut;
      if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
        App_Model_INDFadeOut();
      }

      App_Model_DW.sfEvent_oq = h_previousEvent;
      App_Model_DW.is_WPCINDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_k1;
      break;

     case App__IN_WPCINDAnimationError_On:
      h_previousEvent = App_Model_DW.sfEvent_oq;
      App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
      if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oq = h_previousEvent;
      App_Model_DW.is_WPCINDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_k1;
      break;

     default:
      App_Model_DW.is_WPCINDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_k1;
      break;
    }

    /* 231218
       Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
    h_previousEvent = App_Model_DW.sfEvent_oq;
    App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
    if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
      App_Model_INDFadeIn();
    }

    App_Model_DW.is_IND_Animation_Sync_Control_m = App_Mod_IN_WPCINDAnimation_Init;
    App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oq = h_previousEvent;
    *rty_INDAnimation_Sig = WPCIndSyncVal__Default;
    *rty_INDAnimation_Sig_l = WPCIndCmdState__Default;
  } else {
    switch (App_Model_DW.is_WPCINDAnimation_Error) {
     case App_IN_WPCINDAnimationError_Off:
      {
        /* 2 */
        if ((((rtu_PostProcessIn_k == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_b >= 100U)) || ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_b >= 50U)))
            && ((rtu_PostProcessIn_l == WPCWarningOff) || (rtu_PostProcessIn_l == PhoneCharging) || (rtu_PostProcessIn_l == Charging_Complete) || (rtu_PostProcessIn_l == Cellphoneonthepad) ||
                (rtu_PostProcessIn_l == Cellphonereminder) || (rtu_PostProcessIn_l == WarningInvalid))) {
          sint32 h_previousEvent;

          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_oq;
          App_Model_DW.sfEvent_oq = Ap_event_CancelTimer_INDFadeOut;
          if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
            App_Model_INDFadeOut();
          }

          App_Model_DW.is_WPCINDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_k1;

          /* 231218
             Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
          App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
          if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.is_IND_Animation_Sync_Control_m = App_Mod_IN_WPCINDAnimation_Init;
          App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
          if (App_Model_DW.is_active_INDLight_j != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oq = h_previousEvent;
          *rty_INDAnimation_Sig = WPCIndSyncVal__Default;
          *rty_INDAnimation_Sig_l = WPCIndCmdState__Default;
        } else if (((rtu_PostProcessIn_k == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_b >= 100U)) || ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && (rtu_PostProcessIn_l ==
                     Charging_error) && (App_Model_DW.Timer_INDFadeOut_b >= 50U)) || ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && (rtu_PostProcessIn_l == NFCCardDetected) &&
                    (App_Model_DW.Timer_INDFadeOut_b >= 100U))) {
          sint32 h_previousEvent;

          /* 231218 */
          h_previousEvent = App_Model_DW.sfEvent_oq;
          App_Model_DW.sfEvent_oq = Ap_event_CancelTimer_INDFadeOut;
          if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
            App_Model_INDFadeOut();
          }

          App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
          App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
          if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.sfEvent_oq = h_previousEvent;
          *rty_INDAnimation_Sig = WPCIndSyncVal__ErrorOn;
          *rty_INDAnimation_Sig_l = WPCIndCmdState__ErrorFadeIn;
        }
      }
      break;

     case App__IN_WPCINDAnimationError_On:
      {
        if (((rtu_PostProcessIn_k == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn_b >= 100U)) || ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && (rtu_PostProcessIn_l == Charging_error) &&
             (App_Model_DW.Timer_INDFadeIn_b >= 50U)) || ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && (rtu_PostProcessIn_l == NFCCardDetected) && (App_Model_DW.Timer_INDFadeIn_b >= 100U))) {
          sint32 h_previousEvent;

          /* 231218 */
          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_oq;
          App_Model_DW.sfEvent_oq = App_event_CancelTimer_INDFadeIn;
          if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.sfEvent_oq = h_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimationErr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
        }
      }
      break;

     case IN_WPCINDAnimationError_PreNone:
      /* 1 */
      if ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) || (App_Model_DW.Timer_INDFadeIn_b >= 100U)) {
        /* 231218 */
        App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
        enter_atomic_WPCINDAnimationErr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
      }
      break;

     case IN_WPCINDAnimationError_PreRWPC:
      {
        PreSyncAct tmp;
        tmp = App_Model_DW.Var_PreSyncAct_start_b;
        if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;

          /* 2 */
        } else if ((App_Model_DW.Timer_INDFadeIn_b >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__RWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p !=
                      App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__1stChrgFadeIn)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__2ndChrgFadeIn)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__3rdChrgFadeIn)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__ChrgFadeOut)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__ErrorFadeOut))))
        {
          App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimationErr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
        } else {
          App_Model_INDErrorOnOut(rty_INDAnimation_Sig_l);
        }
      }
      break;

     case IN_WPCINDAnimationError_PreRW_l:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_b;
        if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;

          /* 2 */
        } else if (rtu_PostProcessIn_f == PreSyncAct__WPC2) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWPC2;

          /* 3  */
        } else if ((App_Model_DW.Timer_INDFadeIn_b >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__RWPCWPC2) && (((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p !=
                      App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__1stChrgFadeIn)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__2ndChrgFadeIn)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__3rdChrgFadeIn)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__ChrgFadeOut)) ||
                    ((App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l) && (App_Model_DW.Var_INT_RWPCIndCmdState_start_l == RWPCIndCmdState__ErrorFadeOut))))
        {
          App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimationErr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
        } else {
          App_Model_INDErrorOnOut(rty_INDAnimation_Sig_l);
        }
      }
      break;

     case IN_WPCINDAnimationError_PreWPC2:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_b;
        if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;

          /* 2  */
        } else if (((App_Model_DW.Timer_INDFadeIn_b >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__WPC2) && (((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start)
          && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) || ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_prev
          != App_Model_DW.Var_INT_WPC2IndCmdState_start) && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) {
          App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimationErr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
        } else if ((rtu_PostProcessIn_k != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) &&
                    (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeIn))) {
          sint32 h_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
          h_previousEvent = App_Model_DW.sfEvent_oq;
          App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
          if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.sfEvent_oq = h_previousEvent;
          *rty_INDAnimation_Sig = WPCIndSyncVal__ErrorOn;
          *rty_INDAnimation_Sig_l = WPCIndCmdState__ErrorFadeIn;
        } else {
          App_Model_INDErrorOnOut(rty_INDAnimation_Sig_l);
        }
      }
      break;

     case IN_WPCINDAnimationError_PreWP_f:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_b;
        if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;

          /* 2 */
        } else if (rtu_PostProcessIn_f == PreSyncAct__RWPC) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRWPC;

          /* 3 */
        } else if ((App_Model_DW.Timer_INDFadeIn_b >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__WPC2RWPC) && (((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                      App_Model_DW.Var_INT_WPC2IndCmdState_start) && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                      App_Model_DW.Var_INT_WPC2IndCmdState_start) && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                      App_Model_DW.Var_INT_WPC2IndCmdState_start) && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                      App_Model_DW.Var_INT_WPC2IndCmdState_start) && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                      App_Model_DW.Var_INT_WPC2IndCmdState_start) && (App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) {
          App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimationErr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
        } else {
          App_Model_INDErrorOnOut(rty_INDAnimation_Sig_l);
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void IND_Animation_Sync_Control_Func(WPC2IndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_p, C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState
  rtu_PostProcessIn_j, WPCIndUSMState rtu_PostProcessIn_k, Bool rtu_PostProcessIn_m, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  switch (App_Model_DW.is_IND_Animation_Sync_Control_m) {
   case App_IN_WPCINDAnimation_Charging:
    {
      /* Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
      if (((App_Model_DW.WPCIndUSMState_prev_m != App_Model_DW.WPCIndUSMState_start_c) && (App_Model_DW.WPCIndUSMState_start_c == WPCIndUSMState__Type1)) || (rtu_PostProcessIn_l != PhoneCharging)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        if (App_Model_DW.is_WPCINDAnimation_Charging == IN_WPCINDAnimationCharging_Acti) {
          switch (App_Model_DW.is_WPCINDAnimationCharging_Acti) {
           case IN_WPCINDAnimationCharging_1stS:
            exit_internal_WPCINDAnimationCh();
            g_previousEvent = App_Model_DW.sfEvent_oq;
            App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
            if (App_Model_DW.is_active_INDLight_j != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oq = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Model_IN_NO_ACTIVE_CHILD_k1;
            break;

           case IN_WPCINDAnimationCharging_2ndS:
            exit_internal_WPCINDAnimation_d();
            g_previousEvent = App_Model_DW.sfEvent_oq;
            App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
            if (App_Model_DW.is_active_INDLight_j != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oq = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Model_IN_NO_ACTIVE_CHILD_k1;
            break;

           case IN_WPCINDAnimationCharging_3rdS:
            exit_internal_WPCINDAnimatio_d4();
            g_previousEvent = App_Model_DW.sfEvent_oq;
            App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
            if (App_Model_DW.is_active_INDLight_j != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oq = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Model_IN_NO_ACTIVE_CHILD_k1;
            break;

           case IN_WPCINDAnimationCharging_Off:
            exit_internal_WPCINDAnimation_j();
            g_previousEvent = App_Model_DW.sfEvent_oq;
            App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
            if (App_Model_DW.is_active_INDLight_j != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oq = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Model_IN_NO_ACTIVE_CHILD_k1;
            break;
          }

          /* CancelTimer에서 StartTimer로 변경 221216 */
          g_previousEvent = App_Model_DW.sfEvent_oq;
          App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
          if (App_Model_DW.is_active_INDLight_j != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oq = g_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_k1;
        } else {
          App_Model_DW.is_WPCINDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_k1;
        }

        g_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_IND_Animation_Sync_Control_m = App_Mod_IN_WPCINDAnimation_Init;
        App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = g_previousEvent;
        *rty_INDAnimation_Sig = WPCIndSyncVal__Default;
        *rty_INDAnimation_Sig_l = WPCIndCmdState__Default;
      } else {
        switch (App_Model_DW.is_WPCINDAnimation_Charging) {
         case IN_WPCINDAnimationCharging_Acti:
          WPCINDAnimationCharging_Active(rtu_PostProcessIn_l, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rtu_PostProcessIn_k, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
          break;

         case IN_WPCINDAnimationCharging_PreN:
          {
            /* 1 */
            if (App_Model_DW.Timer_INDLight_j >= 100U) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oq;
              App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
              if (App_Model_DW.is_active_INDLight_j != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oq = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(rtu_PostProcessIn, rtu_PostProcessIn_p, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
            }
          }
          break;

         case IN_WPCINDAnimationCharging_PreR:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b;
            if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if ((App_Model_DW.Timer_INDLight_j >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__RWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_p !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_star_n) || (App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oq;
              App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
              if (App_Model_DW.is_active_INDLight_j != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oq = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(rtu_PostProcessIn, rtu_PostProcessIn_p, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
            }
          }
          break;

         case IN_WPCINDAnimationCharging_Pr_i:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b;
            if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if (rtu_PostProcessIn_f == PreSyncAct__WPC2) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreW;

              /* 3  */
            } else if ((App_Model_DW.Timer_INDLight_j >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__RWPCWPC2) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_p !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_star_n) || (App_Model_DW.Var_INT_RWPCIndCmdState_prev_p != App_Model_DW.Var_INT_RWPCIndCmdState_start_l))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oq;
              App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
              if (App_Model_DW.is_active_INDLight_j != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oq = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(rtu_PostProcessIn, rtu_PostProcessIn_p, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
            }
          }
          break;

         case IN_WPCINDAnimationCharging_PreW:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b;
            if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;

              /* 2  */
            } else if ((App_Model_DW.Timer_INDLight_j >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__WPC2) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev !=
                         App_Model_DW.Input_CAN_WPC2IndSyncVal_start) || (App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oq;
              App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
              if (App_Model_DW.is_active_INDLight_j != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oq = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(rtu_PostProcessIn, rtu_PostProcessIn_p, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
            }
          }
          break;

         case IN_WPCINDAnimationCharging_Pr_p:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b;
            if ((App_Model_DW.Var_PreSyncAct_prev_n != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if (rtu_PostProcessIn_f == PreSyncAct__RWPC) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreR;

              /* 3 */
            } else if ((App_Model_DW.Timer_INDLight_j >= 100U) && (rtu_PostProcessIn_f == PreSyncAct__WPC2RWPC) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev !=
                         App_Model_DW.Input_CAN_WPC2IndSyncVal_start) || (App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oq;
              App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
              if (App_Model_DW.is_active_INDLight_j != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oq = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(rtu_PostProcessIn, rtu_PostProcessIn_p, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
            }
          }
          break;
        }
      }
    }
    break;

   case App_Mo_IN_WPCINDAnimation_Error:
    /* Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
    App_Model_WPCINDAnimation_Error(rtu_PostProcessIn_l, rtu_PostProcessIn_f, rtu_PostProcessIn_k, rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
    break;

   case App_Mod_IN_WPCINDAnimation_Init:
    {
      /* Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
      /* 2 */
      if ((rtu_PostProcessIn_l == PhoneCharging) && (rtu_PostProcessIn_k == WPCIndUSMState__Type2)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        App_Model_DW.is_IND_Animation_Sync_Control_m = App_IN_WPCINDAnimation_Charging;
        g_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App_M_event_StartTimer_INDLight;
        if (App_Model_DW.is_active_INDLight_j != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oq = g_previousEvent;
        *rty_INDAnimation_Sig = WPCIndSyncVal__3rdSync;
        *rty_INDAnimation_Sig_l = WPCIndCmdState__3rdChrgOn;

        /* 1
           [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC2)]%230102 */
        switch (rtu_PostProcessIn_f) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreW;
          break;

         case PreSyncAct__RWPC:
          /* 2
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPC)] */
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreR;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPCWPC2)]%230109 */
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Pr_i;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC2RWPC)] */
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Pr_p;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;
          break;
        }

        /* 3 */
      } else if (((rtu_PostProcessIn_l == Charging_error) || (rtu_PostProcessIn_l == NFCCardDetected)) && (rtu_PostProcessIn_m == On)) {
        sint32 g_previousEvent;
        App_Model_DW.is_IND_Animation_Sync_Control_m = App_Mo_IN_WPCINDAnimation_Error;
        g_previousEvent = App_Model_DW.sfEvent_oq;
        App_Model_DW.sfEvent_oq = App__event_StartTimer_INDFadeIn;
        if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.sfEvent_oq = g_previousEvent;
        *rty_INDAnimation_Sig = WPCIndSyncVal__ErrorOn;
        App_Model_TypeCont(rtu_PostProcessIn_k, rty_INDAnimation_Sig_l);

        /* 1 */
        switch (rtu_PostProcessIn_f) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWPC2;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRWPC;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRW_l;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWP_f;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
          break;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
static void App_Model_INDUSMProfileTwo(WPCIndUSMState *rty_INDUSM_Sig)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_WPCAnimationNvalueSet != App_Model_DW.Input_CAN_WPCAnimationNvalueS_n) && (App_Model_DW.Input_CAN_WPCAnimationNvalueS_n == WPCAnimationNvalueSet__Type1)) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type1;
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type1;

    /* 1 */
  } else if (((App_Model_DW.Input_CAN_WPCAnimationNvalueSet != App_Model_DW.Input_CAN_WPCAnimationNvalueS_n) && (App_Model_DW.Input_CAN_WPCAnimationNvalueS_n == WPCAnimationNvalueSet__Type2)) ||
             ((App_Model_DW.Input_b_USMReset_prev != App_Model_DW.Input_b_USMReset_start) && (App_Model_DW.Input_b_USMReset_start == On))) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type2;
  } else if ((m_WPCIndUSMState_ProfileTwo == WPCIndUSMState__Type2) || (m_WPCIndUSMState_ProfileTwo == WPCIndUSMState__Default)) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
  } else if (m_WPCIndUSMState_ProfileTwo == WPCIndUSMState__Type1) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type1;
  } else {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type2;

    /* 초기값 Type2로 설정. */
  }
}

/* Function for Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
static void App_Model_INDUSMGuest(WPCIndUSMState *rty_INDUSM_Sig)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_WPCAnimationNvalueSet != App_Model_DW.Input_CAN_WPCAnimationNvalueS_n) && (App_Model_DW.Input_CAN_WPCAnimationNvalueS_n == WPCAnimationNvalueSet__Type1)) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type1;
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type1;

    /* 1 */
  } else if (((App_Model_DW.Input_CAN_WPCAnimationNvalueSet != App_Model_DW.Input_CAN_WPCAnimationNvalueS_n) && (App_Model_DW.Input_CAN_WPCAnimationNvalueS_n == WPCAnimationNvalueSet__Type2)) ||
             ((App_Model_DW.Input_b_USMReset_prev != App_Model_DW.Input_b_USMReset_start) && (App_Model_DW.Input_b_USMReset_start == On))) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type2;
  } else if ((m_WPCIndUSMState_Guest == WPCIndUSMState__Type2) || (m_WPCIndUSMState_Guest == WPCIndUSMState__Default)) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
  } else if (m_WPCIndUSMState_Guest == WPCIndUSMState__Type1) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type1;
  } else {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type2;

    /* 초기값 Type2로 설정. */
  }
}

/* Function for Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
static void App_Model_INDUSMProfileOne(WPCIndUSMState *rty_INDUSM_Sig)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_WPCAnimationNvalueSet != App_Model_DW.Input_CAN_WPCAnimationNvalueS_n) && (App_Model_DW.Input_CAN_WPCAnimationNvalueS_n == WPCAnimationNvalueSet__Type1)) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type1;
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type1;

    /* 1 */
  } else if (((App_Model_DW.Input_CAN_WPCAnimationNvalueSet != App_Model_DW.Input_CAN_WPCAnimationNvalueS_n) && (App_Model_DW.Input_CAN_WPCAnimationNvalueS_n == WPCAnimationNvalueSet__Type2)) ||
             ((App_Model_DW.Input_b_USMReset_prev != App_Model_DW.Input_b_USMReset_start) && (App_Model_DW.Input_b_USMReset_start == On))) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type2;
  } else if ((m_WPCIndUSMState_ProfileOne == WPCIndUSMState__Type2) || (m_WPCIndUSMState_ProfileOne == WPCIndUSMState__Default)) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
  } else if (m_WPCIndUSMState_ProfileOne == WPCIndUSMState__Type1) {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type1;
  } else {
    /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    *rty_INDUSM_Sig = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type2;

    /* 초기값 Type2로 설정. */
  }
}

/* System initialize for atomic system: '<S17>/IND_Animation_Control_Function' */
void IND_Animation_Control_Func_Init(WPCIndUSMState *rty_INDUSM_Sig, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* SystemInitialize for Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPC_IND_Command_State_Con_Init(&App_Model_B.Var_RWPCIndCmdState_m, &App_Model_DW.sf_RWPC_IND_Command_State_Contr);

  /* SystemInitialize for Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
  App_Model_DW.sfEvent_oq = App_Model_CALL_EVENT_ee;
  *rty_INDAnimation_Sig = WPCIndSyncVal__Default;
  *rty_INDAnimation_Sig_l = WPCIndCmdState__Default;

  /* SystemInitialize for Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
  *rty_INDUSM_Sig = WPCIndUSMState__Default;
  App_Model_DW.Input_CAN_WPCAnimationNvalueSet = WPCAnimationNvalueSet__Type1;
  App_Model_DW.Input_CAN_WPCAnimationNvalueS_n = WPCAnimationNvalueSet__Type1;
}

/* Output and update for atomic system: '<S17>/IND_Animation_Control_Function' */
void IND_Animation_Control_Function(WPC2IndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_p, C_WPCWarning rtu_PostProcessIn_l, PreSyncAct rtu_PostProcessIn_f, WPC2IndCmdState
  rtu_PostProcessIn_j, WPCIndUSMState rtu_PostProcessIn_k, Bool rtu_PostProcessIn_m, C_ProfileIDRValue rtu_PostProcessIn_d, C_ProfileIDRValue rtu_PostProcessIn_h, Bool rtu_PostProcessIn_d3,
  WPCAnimationNvalueSet rtu_PostProcessIn_hn, C_USMReset rtu_PostProcessIn_c, WPCIndUSMState *rty_INDUSM_Sig, C_WPCIndSyncVal *rty_INDAnimation_Sig, WPCIndCmdState *rty_INDAnimation_Sig_l)
{
  /* Chart: '<S27>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPC_IND_Command_State_Control_(rtu_PostProcessIn_p, &App_Model_B.Var_RWPCIndCmdState_m, &App_Model_DW.sf_RWPC_IND_Command_State_Contr);

  /* Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
  App_Model_DW.sfEvent_oq = App_Model_CALL_EVENT_ee;
  App_Model_DW.Var_PreSyncAct_prev_n = App_Model_DW.Var_PreSyncAct_start_b;
  App_Model_DW.Var_PreSyncAct_start_b = rtu_PostProcessIn_f;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_p = App_Model_DW.Input_CAN_RWPCIndSyncVal_star_n;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_star_n = rtu_PostProcessIn_p;
  App_Model_DW.Var_INT_RWPCIndCmdState_prev_p = App_Model_DW.Var_INT_RWPCIndCmdState_start_l;
  App_Model_DW.Var_INT_RWPCIndCmdState_start_l = App_Model_B.Var_RWPCIndCmdState_m;
  App_Model_DW.Input_CAN_WPC2IndSyncVal_prev = App_Model_DW.Input_CAN_WPC2IndSyncVal_start;
  App_Model_DW.Input_CAN_WPC2IndSyncVal_start = rtu_PostProcessIn;
  App_Model_DW.Var_INT_WPC2IndCmdState_prev = App_Model_DW.Var_INT_WPC2IndCmdState_start;
  App_Model_DW.Var_INT_WPC2IndCmdState_start = rtu_PostProcessIn_j;
  App_Model_DW.WPCIndUSMState_prev_m = App_Model_DW.WPCIndUSMState_start_c;
  App_Model_DW.WPCIndUSMState_start_c = rtu_PostProcessIn_k;
  App_Model_DW.b_SyncAmber_prev_h = App_Model_DW.b_SyncAmber_start_h;
  App_Model_DW.b_SyncAmber_start_h = rtu_PostProcessIn_m;
  if (App_Model_DW.is_active_c197_WPC_IND_Animatio == 0U) {
    App_Model_DW.Var_PreSyncAct_prev_n = rtu_PostProcessIn_f;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_p = rtu_PostProcessIn_p;
    App_Model_DW.Var_INT_RWPCIndCmdState_prev_p = App_Model_B.Var_RWPCIndCmdState_m;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_prev = rtu_PostProcessIn;
    App_Model_DW.Var_INT_WPC2IndCmdState_prev = rtu_PostProcessIn_j;
    App_Model_DW.WPCIndUSMState_prev_m = rtu_PostProcessIn_k;
    App_Model_DW.b_SyncAmber_prev_h = rtu_PostProcessIn_m;
    App_Model_DW.is_active_c197_WPC_IND_Animatio = 1U;
    App_Model_DW.is_active_INDLight_j = 1U;
    App_Model_DW.is_INDLight_a = App_Model_IN_INDLight_Off;
    App_Model_DW.Timer_INDLight_j = 0U;
    App_Model_DW.is_active_IND_Animation_Sync__b = 1U;

    /* Default */
    App_Model_DW.is_IND_Animation_Sync_Control_m = App_Mod_IN_WPCINDAnimation_Init;
    App_Model_DW.sfEvent_oq = App__event_CancelTimer_INDLight;
    App_Model_INDLight();
    App_Model_DW.sfEvent_oq = -1;
    *rty_INDAnimation_Sig = WPCIndSyncVal__Default;
    *rty_INDAnimation_Sig_l = WPCIndCmdState__Default;
    App_Model_DW.is_active_INDFadeIn_o = 1U;
    App_Model_DW.is_INDFadeIn_j = App_Model_IN_INDFadeIn_Off;
    App_Model_DW.Timer_INDFadeIn_b = 0U;
    App_Model_DW.is_active_INDFadeOut_k = 1U;
    App_Model_DW.is_INDFadeOut_c = App_Model_IN_INDFadeOut_Off;
    App_Model_DW.Timer_INDFadeOut_b = 0U;
  } else {
    if (App_Model_DW.is_active_INDLight_j != 0U) {
      App_Model_INDLight();
    }

    if (App_Model_DW.is_active_IND_Animation_Sync__b != 0U) {
      IND_Animation_Sync_Control_Func(rtu_PostProcessIn, rtu_PostProcessIn_p, rtu_PostProcessIn_l, rtu_PostProcessIn_f, rtu_PostProcessIn_j, rtu_PostProcessIn_k, rtu_PostProcessIn_m,
        rty_INDAnimation_Sig, rty_INDAnimation_Sig_l);
    }

    if (App_Model_DW.is_active_INDFadeIn_o != 0U) {
      App_Model_INDFadeIn();
    }

    if (App_Model_DW.is_active_INDFadeOut_k != 0U) {
      App_Model_INDFadeOut();
    }
  }

  /* End of Chart: '<S27>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */

  /* Chart: '<S31>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
  if (App_Model_DW.is_active_c147_WPC_IND_Animatio == 0U) {
    App_Model_DW.is_active_c147_WPC_IND_Animatio = 1U;
    App_Model_B.CurProfile = Guest;

    /* 1 */
    switch (rtu_PostProcessIn_d) {
     case Profile1:
      App_Model_B.CurProfile = Profile1;
      break;

     case Profile2:
      /* 1 */
      App_Model_B.CurProfile = Profile2;
      break;

     case Guest:
      /* 1 */
      break;

     default:
      /* 1 */
      switch (rtu_PostProcessIn_h) {
       case Profile1:
        App_Model_B.CurProfile = Profile1;
        break;

       case Profile2:
        /* 1 */
        App_Model_B.CurProfile = Profile2;
        break;

       case Guest:
        /* 1 */
        break;
      }
      break;
    }
  } else {
    /* 1 */
    switch (rtu_PostProcessIn_d) {
     case Profile1:
      App_Model_B.CurProfile = Profile1;
      break;

     case Profile2:
      /* 1 */
      App_Model_B.CurProfile = Profile2;
      break;

     case Guest:
      /* 1 */
      App_Model_B.CurProfile = Guest;
      break;

     default:
      /* 1 */
      switch (rtu_PostProcessIn_h) {
       case Profile1:
        App_Model_B.CurProfile = Profile1;
        break;

       case Profile2:
        /* 1 */
        App_Model_B.CurProfile = Profile2;
        break;

       case Guest:
        /* 1 */
        App_Model_B.CurProfile = Guest;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S31>/IND_Animation_Profile_Decision_Function_Flow_Graph' */

  /* Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
  App_Model_DW.Input_CAN_WPCAnimationNvalueSet = App_Model_DW.Input_CAN_WPCAnimationNvalueS_n;
  App_Model_DW.Input_CAN_WPCAnimationNvalueS_n = rtu_PostProcessIn_hn;
  App_Model_DW.Input_b_USMReset_prev = App_Model_DW.Input_b_USMReset_start;
  App_Model_DW.Input_b_USMReset_start = rtu_PostProcessIn_c;
  if (App_Model_DW.is_active_c135_WPC_IND_Animatio == 0U) {
    App_Model_DW.Input_CAN_WPCAnimationNvalueSet = rtu_PostProcessIn_hn;
    App_Model_DW.Input_b_USMReset_prev = rtu_PostProcessIn_c;
    App_Model_DW.is_active_c135_WPC_IND_Animatio = 1U;
    if (rtu_PostProcessIn_d3 == Off) {
      App_Model_DW.is_IND_Animation_USM_Setting_Co = A_IN_INDAnimationUSM_NotApplied;
      *rty_INDUSM_Sig = WPCIndUSMState__Type1;
    } else {
      /* 2
         b_IndUSMOption == On */
      App_Model_DW.is_IND_Animation_USM_Setting_Co = App__IN_INDAnimationUSM_Applied;

      /* Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리
         Output_INT_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리 */
      /* 1 */
      switch (App_Model_B.CurProfile) {
       case Profile1:
        App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
        App_Model_INDUSMProfileOne(rty_INDUSM_Sig);
        break;

       case Profile2:
        /* 2 */
        App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
        App_Model_INDUSMProfileTwo(rty_INDUSM_Sig);
        break;

       default:
        App_Model_DW.is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
        App_Model_INDUSMGuest(rty_INDUSM_Sig);
        break;
      }
    }
  } else if (App_Model_DW.is_IND_Animation_USM_Setting_Co == App__IN_INDAnimationUSM_Applied) {
    if (rtu_PostProcessIn_d3 == Off) {
      App_Model_DW.is_INDAnimationUSM_Applied = App_Model_IN_NO_ACTIVE_CHILD_k1;
      App_Model_DW.is_IND_Animation_USM_Setting_Co = A_IN_INDAnimationUSM_NotApplied;
      *rty_INDUSM_Sig = WPCIndUSMState__Type1;
    } else {
      switch (App_Model_DW.is_INDAnimationUSM_Applied) {
       case App_Mo_IN_INDAnimationUSM_Guest:
        /* 1 */
        switch (App_Model_B.CurProfile) {
         case Profile1:
          App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
          App_Model_INDUSMProfileOne(rty_INDUSM_Sig);
          break;

         case Profile2:
          /* 2 */
          App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
          App_Model_INDUSMProfileTwo(rty_INDUSM_Sig);
          break;

         default:
          App_Model_INDUSMGuest(rty_INDUSM_Sig);
          break;
        }
        break;

       case A_IN_INDAnimationUSM_ProfileOne:
        /* 1 */
        switch (App_Model_B.CurProfile) {
         case Profile2:
          App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
          App_Model_INDUSMProfileTwo(rty_INDUSM_Sig);
          break;

         case Guest:
          /* 2 */
          App_Model_DW.is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
          App_Model_INDUSMGuest(rty_INDUSM_Sig);
          break;

         default:
          App_Model_INDUSMProfileOne(rty_INDUSM_Sig);
          break;
        }
        break;

       default:
        /* case IN_INDAnimationUSM_ProfileTwo: */
        /* 1 */
        switch (App_Model_B.CurProfile) {
         case Profile1:
          App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
          App_Model_INDUSMProfileOne(rty_INDUSM_Sig);
          break;

         case Guest:
          /* 2 */
          App_Model_DW.is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
          App_Model_INDUSMGuest(rty_INDUSM_Sig);
          break;

         default:
          App_Model_INDUSMProfileTwo(rty_INDUSM_Sig);
          break;
        }
        break;
      }
    }

    /* case IN_INDAnimationUSM_NotApplied: */
  } else if (rtu_PostProcessIn_d3 == On) {
    App_Model_DW.is_IND_Animation_USM_Setting_Co = App__IN_INDAnimationUSM_Applied;

    /* Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리
       Output_INT_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리 */
    /* 1 */
    switch (App_Model_B.CurProfile) {
     case Profile1:
      App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
      App_Model_INDUSMProfileOne(rty_INDUSM_Sig);
      break;

     case Profile2:
      /* 2 */
      App_Model_DW.is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
      App_Model_INDUSMProfileTwo(rty_INDUSM_Sig);
      break;

     default:
      App_Model_DW.is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
      App_Model_INDUSMGuest(rty_INDUSM_Sig);
      break;
    }
  }

  /* End of Chart: '<S31>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDLight_i(void)
{
  switch (App_Model_DW.is_INDLight) {
   case App_Model_IN_INDLight2_Off:
    if (App_Model_DW.sfEvent_j == App_event_StartTimer_INDLight_i) {
      App_Model_DW.is_INDLight = App_Model_IN_INDLight2_On;
    }
    break;

   case App_Model_IN_INDLight2_On:
    {
      switch (App_Model_DW.sfEvent_j) {
       case Ap_event_CancelTimer_INDLight_b:
        App_Model_DW.is_INDLight = App_Model_IN_INDLight2_Off;
        App_Model_DW.Timer_INDLight = 0U;
        break;

       case App_event_StartTimer_INDLight_i:
        App_Model_DW.Timer_INDLight = 0U;
        App_Model_DW.is_INDLight = App_Model_IN_INDLight2_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDLight + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_INDLight + 1U < App_Model_DW.Timer_INDLight) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDLight = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeIn_d(void)
{
  switch (App_Model_DW.is_INDFadeIn) {
   case App_Model_IN_INDFadeIn_Off_l:
    if (App_Model_DW.sfEvent_j == Ap_event_StartTimer_INDFadeIn_n) {
      App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_On_d;
    }
    break;

   case App_Model_IN_INDFadeIn_On_d:
    {
      switch (App_Model_DW.sfEvent_j) {
       case A_event_CancelTimer_INDFadeIn_g:
        App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_Off_l;
        App_Model_DW.Timer_INDFadeIn = 0U;
        break;

       case Ap_event_StartTimer_INDFadeIn_n:
        App_Model_DW.Timer_INDFadeIn = 0U;
        App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_On_d;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeIn + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_INDFadeIn + 1U < App_Model_DW.Timer_INDFadeIn) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeIn = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPC2INDAnimationC(void)
{
  switch (App_Model_DW.is_WPC2INDAnimationCharging_1st) {
   case IN_WPC2INDAnimationCharging_1_c:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
      if (App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_d();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Model_IN_NO_ACTIVE_CHILD_kl;
    }
    break;

   case IN_WPC2INDAnimationCharging_1_m:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
      if (App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_i();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Model_IN_NO_ACTIVE_CHILD_kl;
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnimati_d(WPCIndCmdState rtu_PostProcessIn_n, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* 1 */
  if ((rtu_PostProcessIn_n == WPCIndCmdState__2ndChrgOn) || (App_Model_B.Var_RWPCIndCmdState == RWPCIndCmdState__2ndChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPC2INDAnimationCharging_2nd = IN_WPC2INDAnimationCharging_2_j;
    c_previousEvent = App_Model_DW.sfEvent_j;
    App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    App_Model_DW.sfEvent_j = c_previousEvent;
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__2ndChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn ||
       Var_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn */
    App_Model_DW.is_WPC2INDAnimationCharging_2nd = IN_WPC2INDAnimationCharging_2_a;
    c_previousEvent = App_Model_DW.sfEvent_j;
    App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
    if (App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_d();
    }

    App_Model_DW.sfEvent_j = c_previousEvent;
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__2ndChrgFadeIn;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPC2INDAnimatio_c(void)
{
  switch (App_Model_DW.is_WPC2INDAnimationCharging_2nd) {
   case IN_WPC2INDAnimationCharging_2_a:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
      if (App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_d();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Model_IN_NO_ACTIVE_CHILD_kl;
    }
    break;

   case IN_WPC2INDAnimationCharging_2_j:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
      if (App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_i();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Model_IN_NO_ACTIVE_CHILD_kl;
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPC2INDAnimationCh(WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_j;
  App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
  if (App_Model_DW.is_active_INDLight != 0U) {
    App_Model_INDLight_i();
  }

  /* CancelTimer추가 221219 */
  App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
  if (App_Model_DW.is_active_INDFadeIn != 0U) {
    App_Model_INDFadeIn_d();
  }

  App_Model_DW.sfEvent_j = b_previousEvent;
  *rty_INDAnimation_Sig_o = WPC2IndCmdState__3rdChrgFadeIn;
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnimati_a(WPCIndCmdState rtu_PostProcessIn_n, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* 1 */
  if ((rtu_PostProcessIn_n == WPCIndCmdState__1stChrgOn) || (App_Model_B.Var_RWPCIndCmdState == RWPCIndCmdState__1stChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPC2INDAnimationCharging_1st = IN_WPC2INDAnimationCharging_1_m;
    c_previousEvent = App_Model_DW.sfEvent_j;
    App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    App_Model_DW.sfEvent_j = c_previousEvent;
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__1stChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn ||
       Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut ||
       Var_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn ||
       Var_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut] */
    App_Model_DW.is_WPC2INDAnimationCharging_1st = IN_WPC2INDAnimationCharging_1_c;
    c_previousEvent = App_Model_DW.sfEvent_j;
    App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
    if (App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_d();
    }

    App_Model_DW.sfEvent_j = c_previousEvent;
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__1stChrgFadeIn;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeOut_g(void)
{
  switch (App_Model_DW.is_INDFadeOut) {
   case App_Model_IN_INDFadeOut_Off_e:
    if (App_Model_DW.sfEvent_j == A_event_StartTimer_INDFadeOut_k) {
      App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_On_e;
    }
    break;

   case App_Model_IN_INDFadeOut_On_e:
    {
      switch (App_Model_DW.sfEvent_j) {
       case event_CancelTimer_INDFadeOut_n:
        App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_Off_e;
        App_Model_DW.Timer_INDFadeOut = 0U;
        break;

       case A_event_StartTimer_INDFadeOut_k:
        App_Model_DW.Timer_INDFadeOut = 0U;
        App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_On_e;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeOut + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_INDFadeOut + 1U < App_Model_DW.Timer_INDFadeOut) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeOut = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPC2INDAnimatio_p(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_j;
  App_Model_DW.sfEvent_j = event_CancelTimer_INDFadeOut_n;
  if (App_Model_DW.is_active_INDFadeOut != 0U) {
    App_Model_INDFadeOut_g();
  }

  App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
  if (App_Model_DW.is_active_INDLight != 0U) {
    App_Model_INDLight_i();
  }

  App_Model_DW.sfEvent_j = b_previousEvent;
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_TypeCont_c(WPCIndUSMState rtu_PostProcessIn_j, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* 1 */
  if (rtu_PostProcessIn_j != WPCIndUSMState__Type2) {
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__ErrorFadeOut;
  } else {
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__ErrorFadeIn;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimation_m(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_3rdS) {
   case IN_WPC2INDAnimationCharging_3rd:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
      if (App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_d();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Model_IN_NO_ACTIVE_CHILD_kl;
    }
    break;

   case IN_WPC2INDAnimationCharging_3_k:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
      if (App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_i();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Model_IN_NO_ACTIVE_CHILD_kl;
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnimati_i(WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  sint32 b_previousEvent;

  /* 1_230104_sync */
  b_previousEvent = App_Model_DW.sfEvent_j;
  App_Model_DW.sfEvent_j = A_event_StartTimer_INDFadeOut_k;
  if (App_Model_DW.is_active_INDFadeOut != 0U) {
    App_Model_INDFadeOut_g();
  }

  App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
  if (App_Model_DW.is_active_INDLight != 0U) {
    App_Model_INDLight_i();
  }

  App_Model_DW.sfEvent_j = b_previousEvent;

  /* 230328 */
  *rty_INDAnimation_Sig_o = WPC2IndCmdState__ChrgFadeOut;

  /* 230328 */
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void WPC2INDAnimationCharging_Active(C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState rtu_PostProcessIn_n, WPCIndUSMState rtu_PostProcessIn_j, WPC2IndSyncVal
  *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  switch (App_Model_DW.is_WPC2INDAnimationCharging_Act) {
   case IN_WPC2INDAnimationCharging_1st:
    {
      /* 2. Transition start point move to 1stOn */
      if (App_Model_DW.Timer_INDLight >= 100U) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnimationC();
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_2nd;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__2ndSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPC2INDAnimati_d(rtu_PostProcessIn_n, rty_INDAnimation_Sig_o);
      } else if ((App_Model_DW.is_WPC2INDAnimationCharging_1st == IN_WPC2INDAnimationCharging_1_c) && (App_Model_DW.Timer_INDFadeIn >= 100U)) {
        sint32 k_previousEvent;

        /* 1 */
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
        if (App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_d();
        }

        App_Model_DW.is_WPC2INDAnimationCharging_1st = IN_WPC2INDAnimationCharging_1_m;
        App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        *rty_INDAnimation_Sig_o = WPC2IndCmdState__1stChrgOn;
      }
    }
    break;

   case IN_WPC2INDAnimationCharging_2nd:
    {
      /* 2.Transition start point move to 2ndOn */
      if (App_Model_DW.Timer_INDLight >= 100U) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnimatio_c();
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPCINDAnimationCharging_3r_e;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__3rdSync;

        /* CancelTimer추가 221216 */
        App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPC2INDAnimationCharging_3rd;
        enter_atomic_WPC2INDAnimationCh(rty_INDAnimation_Sig_o);
      } else if ((App_Model_DW.is_WPC2INDAnimationCharging_2nd == IN_WPC2INDAnimationCharging_2_a) && (App_Model_DW.Timer_INDFadeIn >= 100U)) {
        sint32 k_previousEvent;

        /* 1. */
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
        if (App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_d();
        }

        App_Model_DW.is_WPC2INDAnimationCharging_2nd = IN_WPC2INDAnimationCharging_2_j;
        App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        *rty_INDAnimation_Sig_o = WPC2IndCmdState__2ndChrgOn;
      }
    }
    break;

   case IN_WPC2INDAnimationCharging_Off:
    {
      /* 1 */
      if ((App_Model_DW.Timer_INDFadeOut >= 100U) && ((rtu_PostProcessIn_f == Charging_error) || (rtu_PostProcessIn_f == NFCCardDetected))) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnimatio_p();
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Model_IN_NO_ACTIVE_CHILD_kl;

        /* CancelTimer에서 StartTimer로 변경 221216 */
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.is_WPC2INDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_kl;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.is_IND_Animation_Sync_Control_F = App_M_IN_WPC2INDAnimation_Error;
        App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
        if (App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_d();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__ErrorOn;
        App_Model_TypeCont_c(rtu_PostProcessIn_j, rty_INDAnimation_Sig_o);

        /* 1 */
        switch (rtu_PostProcessIn_a) {
         case PreSyncAct__WPC:
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreWPC;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreRW_a;
          break;

         case PreSyncAct__RWPCWPC:
          /* 3 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreRWP;
          break;

         case PreSyncAct__WPCRWPC:
          /* 4 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreWPC;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;
          break;
        }

        /* 3. */
      } else if (App_Model_DW.Timer_INDLight >= 100U) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnimatio_p();
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_1st;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__1stSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPC2INDAnimati_a(rtu_PostProcessIn_n, rty_INDAnimation_Sig_o);
      }
    }
    break;

   case IN_WPCINDAnimationCharging_3r_e:
    {
      /* 2.  */
      if (App_Model_DW.Timer_INDLight >= 100U) {
        sint32 k_previousEvent;

        /* [Timer_INDFadeOut >= Par_INDFadeOutTime] */
        exit_internal_WPCINDAnimation_m();
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_Off;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;

        /* CancelTimer추가 230103 */
        *rty_INDAnimation_Sig = WPC2IndSyncVal__Off;

        /* CancelTimer추가 221216 */
        enter_internal_WPC2INDAnimati_i(rty_INDAnimation_Sig_o);
      } else if ((App_Model_DW.is_WPCINDAnimationCharging_3rdS == IN_WPC2INDAnimationCharging_3rd) && (App_Model_DW.Timer_INDFadeIn >= 100U)) {
        sint32 k_previousEvent;

        /* 1. */
        k_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
        if (App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_d();
        }

        App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPC2INDAnimationCharging_3_k;
        App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = k_previousEvent;
        *rty_INDAnimation_Sig_o = WPC2IndCmdState__3rdChrgOn;
      }
    }
    break;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnimation(C_WPCIndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_o, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState rtu_PostProcessIn_n, WPC2IndSyncVal
  *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* 1 */
  if ((((rtu_PostProcessIn_a == PreSyncAct__WPC) || (rtu_PostProcessIn_a == PreSyncAct__WPCRWPC)) && (rtu_PostProcessIn == WPCIndSyncVal__3rdSync)) || (((rtu_PostProcessIn_a == PreSyncAct__RWPC) ||
        (rtu_PostProcessIn_a == PreSyncAct__RWPCWPC)) && (rtu_PostProcessIn_o == RWPCIndSyncVal__3rdSync))) {
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPCINDAnimationCharging_3r_e;
    *rty_INDAnimation_Sig = WPC2IndSyncVal__3rdSync;

    /* CancelTimer추가 221216 */
    /* 1 */
    if ((rtu_PostProcessIn_n == WPCIndCmdState__3rdChrgOn) || (App_Model_B.Var_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPC2INDAnimationCharging_3_k;
      b_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
      if (App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_i();
      }

      App_Model_DW.sfEvent_j = b_previousEvent;
      *rty_INDAnimation_Sig_o = WPC2IndCmdState__3rdChrgOn;
    } else {
      /* 2
         Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn ||
         Var_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn */
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPC2INDAnimationCharging_3rd;
      enter_atomic_WPC2INDAnimationCh(rty_INDAnimation_Sig_o);
    }

    /* 2 */
  } else if ((((rtu_PostProcessIn_a == PreSyncAct__WPC) || (rtu_PostProcessIn_a == PreSyncAct__WPCRWPC)) && (rtu_PostProcessIn == WPCIndSyncVal__2ndSync)) || (((rtu_PostProcessIn_a == PreSyncAct__RWPC)
    || (rtu_PostProcessIn_a == PreSyncAct__RWPCWPC)) && (rtu_PostProcessIn_o == RWPCIndSyncVal__2ndSync))) {
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_2nd;
    *rty_INDAnimation_Sig = WPC2IndSyncVal__2ndSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPC2INDAnimati_d(rtu_PostProcessIn_n, rty_INDAnimation_Sig_o);

    /* 3 */
  } else if ((((rtu_PostProcessIn_a == PreSyncAct__WPC) || (rtu_PostProcessIn_a == PreSyncAct__WPCRWPC)) && ((rtu_PostProcessIn == WPCIndSyncVal__1stSync) || (rtu_PostProcessIn ==
                WPCIndSyncVal__ErrorOff))) || (((rtu_PostProcessIn_a == PreSyncAct__RWPC) || (rtu_PostProcessIn_a == PreSyncAct__RWPCWPC)) && ((rtu_PostProcessIn_o == RWPCIndSyncVal__1stSync) ||
               (rtu_PostProcessIn_o == RWPCIndSyncVal__ErrorOff)))) {
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_1st;
    *rty_INDAnimation_Sig = WPC2IndSyncVal__1stSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPC2INDAnimati_a(rtu_PostProcessIn_n, rty_INDAnimation_Sig_o);
  } else {
    sint32 b_previousEvent;

    /* 4 */
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_Off;
    b_previousEvent = App_Model_DW.sfEvent_j;
    App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    App_Model_DW.sfEvent_j = b_previousEvent;

    /* CancelTimer추가 230103 */
    *rty_INDAnimation_Sig = WPC2IndSyncVal__Off;

    /* CancelTimer추가 221216 */
    enter_internal_WPC2INDAnimati_i(rty_INDAnimation_Sig_o);
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPC2INDAnimationEr(WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_j;
  App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
  if (App_Model_DW.is_active_INDFadeIn != 0U) {
    App_Model_INDFadeIn_d();
  }

  App_Model_DW.sfEvent_j = A_event_StartTimer_INDFadeOut_k;
  if (App_Model_DW.is_active_INDFadeOut != 0U) {
    App_Model_INDFadeOut_g();
  }

  App_Model_DW.sfEvent_j = b_previousEvent;
  *rty_INDAnimation_Sig = WPC2IndSyncVal__ErrorOff;
  *rty_INDAnimation_Sig_o = WPC2IndCmdState__ErrorFadeOut;
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDErrorOnOut_g(WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* 1 */
  if (App_Model_DW.Timer_INDFadeIn >= 100U) {
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__ErrorOn;
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Mode_WPC2INDAnimation_Error(C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndUSMState rtu_PostProcessIn_j, WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *
  rty_INDAnimation_Sig_o)
{
  if ((App_Model_DW.b_SyncAmber_prev != App_Model_DW.b_SyncAmber_start) && (App_Model_DW.b_SyncAmber_start == Off)) {
    sint32 h_previousEvent;
    switch (App_Model_DW.is_WPC2INDAnimation_Error) {
     case Ap_IN_WPC2INDAnimationError_Off:
      h_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = event_CancelTimer_INDFadeOut_n;
      if (App_Model_DW.is_active_INDFadeOut != 0U) {
        App_Model_INDFadeOut_g();
      }

      App_Model_DW.sfEvent_j = h_previousEvent;
      App_Model_DW.is_WPC2INDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_kl;
      break;

     case App_IN_WPC2INDAnimationError_On:
      h_previousEvent = App_Model_DW.sfEvent_j;
      App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
      if (App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_d();
      }

      App_Model_DW.sfEvent_j = h_previousEvent;
      App_Model_DW.is_WPC2INDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_kl;
      break;

     default:
      App_Model_DW.is_WPC2INDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_kl;
      break;
    }

    /* 231218
       Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
    h_previousEvent = App_Model_DW.sfEvent_j;
    App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
    if (App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_d();
    }

    App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mo_IN_WPC2INDAnimation_Init;
    App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    App_Model_DW.sfEvent_j = h_previousEvent;
    *rty_INDAnimation_Sig = WPC2IndSyncVal__Default;
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__Default;
  } else {
    switch (App_Model_DW.is_WPC2INDAnimation_Error) {
     case Ap_IN_WPC2INDAnimationError_Off:
      {
        /* 1 */
        if ((((rtu_PostProcessIn_j == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut >= 100U)) || ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut >= 50U))) &&
            ((rtu_PostProcessIn_f == WPCWarningOff) || (rtu_PostProcessIn_f == PhoneCharging) || (rtu_PostProcessIn_f == Charging_Complete) || (rtu_PostProcessIn_f == Cellphoneonthepad) ||
             (rtu_PostProcessIn_f == Cellphonereminder) || (rtu_PostProcessIn_f == WarningInvalid))) {
          sint32 h_previousEvent;

          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_j;
          App_Model_DW.sfEvent_j = event_CancelTimer_INDFadeOut_n;
          if (App_Model_DW.is_active_INDFadeOut != 0U) {
            App_Model_INDFadeOut_g();
          }

          App_Model_DW.is_WPC2INDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_kl;

          /* 231218
             Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
          App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
          if (App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_d();
          }

          App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mo_IN_WPC2INDAnimation_Init;
          App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
          if (App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_i();
          }

          App_Model_DW.sfEvent_j = h_previousEvent;
          *rty_INDAnimation_Sig = WPC2IndSyncVal__Default;
          *rty_INDAnimation_Sig_o = WPC2IndCmdState__Default;
        } else if (((rtu_PostProcessIn_j == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut >= 100U)) || ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && (rtu_PostProcessIn_f ==
                     Charging_error) && (App_Model_DW.Timer_INDFadeOut >= 50U)) || ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && (rtu_PostProcessIn_f == NFCCardDetected) &&
                    (App_Model_DW.Timer_INDFadeOut >= 100U))) {
          sint32 h_previousEvent;

          /* 231218 */
          h_previousEvent = App_Model_DW.sfEvent_j;
          App_Model_DW.sfEvent_j = event_CancelTimer_INDFadeOut_n;
          if (App_Model_DW.is_active_INDFadeOut != 0U) {
            App_Model_INDFadeOut_g();
          }

          App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
          App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
          if (App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_d();
          }

          App_Model_DW.sfEvent_j = h_previousEvent;
          *rty_INDAnimation_Sig = WPC2IndSyncVal__ErrorOn;
          *rty_INDAnimation_Sig_o = WPC2IndCmdState__ErrorFadeIn;
        }
      }
      break;

     case App_IN_WPC2INDAnimationError_On:
      {
        if (((rtu_PostProcessIn_j == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn >= 100U)) || ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && (rtu_PostProcessIn_f == Charging_error) &&
             (App_Model_DW.Timer_INDFadeIn >= 50U)) || ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && (rtu_PostProcessIn_f == NFCCardDetected) && (App_Model_DW.Timer_INDFadeIn >= 100U))) {
          sint32 h_previousEvent;

          /* 231218 */
          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_j;
          App_Model_DW.sfEvent_j = A_event_CancelTimer_INDFadeIn_g;
          if (App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_d();
          }

          App_Model_DW.sfEvent_j = h_previousEvent;
          App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
          enter_atomic_WPC2INDAnimationEr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
        }
      }
      break;

     case IN_WPC2INDAnimationError_PreNon:
      if ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) || (App_Model_DW.Timer_INDFadeIn >= 100U)) {
        /* 231218 */
        App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
        enter_atomic_WPC2INDAnimationEr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
      }
      break;

     case IN_WPC2INDAnimationError_PreRWP:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;

          /* 2 */
        } else if (rtu_PostProcessIn_a == PreSyncAct__WPC) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreWPC;

          /* 3  */
        } else if ((App_Model_DW.Timer_INDFadeIn >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__RWPCWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start)
          && (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeOut)))) {
          /* (hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__1stChrgFadeIn) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__2ndChrgFadeIn) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__3rdChrgFadeIn) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__ChrgFadeOut) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__ErrorFadeOut))]
             Fade 반대로 진입변경 시 */
          App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
          enter_atomic_WPC2INDAnimationEr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
        } else {
          App_Model_INDErrorOnOut_g(rty_INDAnimation_Sig_o);
        }
      }
      break;

     case IN_WPC2INDAnimationError_PreWPC:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;

          /* 2 */
        } else if (rtu_PostProcessIn_a == PreSyncAct__RWPC) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreRW_a;

          /* 3 */
        } else if ((App_Model_DW.Timer_INDFadeIn >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__WPCRWPC) && (((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
          (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) {
          /* (hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__1stChrgOn) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__2ndChrgOn) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__3rdChrgOn) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__ChrgFadeOut) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__ErrorFadeOut))]
             Fade 반대로 진입변경 시 */
          App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
          enter_atomic_WPC2INDAnimationEr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
        } else {
          App_Model_INDErrorOnOut_g(rty_INDAnimation_Sig_o);
        }
      }
      break;

     case IN_WPCINDAnimationError_PreRW_a:
      {
        PreSyncAct tmp;
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;

          /* 2 */
        } else if ((App_Model_DW.Timer_INDFadeIn >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__RWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
          (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) &&
                     (App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeOut)))) {
          /* (hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__1stChrgFadeOn) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__2ndChrgFadeOn) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__3rdChrgFadeOn) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__ChrgFadeOut) ||hasChangedTo(Var_INT_RWPCIndCmdState,RWPCIndCmdState__ErrorFadeOut))]
             Fade 반대로 진입변경 시 */
          App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
          enter_atomic_WPC2INDAnimationEr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
        } else {
          App_Model_INDErrorOnOut_g(rty_INDAnimation_Sig_o);
        }
      }
      break;

     case IN_WPCINDAnimationError_PreWPC:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;

          /* 2  */
        } else if (((App_Model_DW.Timer_INDFadeIn >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__WPC) && (((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                      (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) || ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
          App_Model_DW.Var_INT_WPCIndCmdState_start) && (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) {
          /* (hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__1stChrgOn) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__2ndChrgOn) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__3rdChrgOn) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__ChrgFadeOut) ||hasChangedTo(Var_INT_WPCIndCmdState,WPCIndCmdState__ErrorFadeOut))]
             Fade 반대로 진입변경 시 */
          /* 231218 */
          App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
          enter_atomic_WPC2INDAnimationEr(rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
        } else if ((rtu_PostProcessIn_j != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) &&
                    (App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeIn))) {
          sint32 h_previousEvent;
          App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
          h_previousEvent = App_Model_DW.sfEvent_j;
          App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
          if (App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_d();
          }

          App_Model_DW.sfEvent_j = h_previousEvent;
          *rty_INDAnimation_Sig = WPC2IndSyncVal__ErrorOn;
          *rty_INDAnimation_Sig_o = WPC2IndCmdState__ErrorFadeIn;
        } else {
          App_Model_INDErrorOnOut_g(rty_INDAnimation_Sig_o);
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void IND_Animation_Sync_Control_Fu_d(C_WPCIndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_o, C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState
  rtu_PostProcessIn_n, WPCIndUSMState rtu_PostProcessIn_j, Bool rtu_PostProcessIn_nk, WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  switch (App_Model_DW.is_IND_Animation_Sync_Control_F) {
   case Ap_IN_WPC2INDAnimation_Charging:
    {
      /* Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
      if (((App_Model_DW.WPCIndUSMState_prev != App_Model_DW.WPCIndUSMState_start) && (App_Model_DW.WPCIndUSMState_start == WPCIndUSMState__Type1)) || (rtu_PostProcessIn_f != PhoneCharging)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        if (App_Model_DW.is_WPC2INDAnimation_Charging == IN_WPC2INDAnimationCharging_Act) {
          switch (App_Model_DW.is_WPC2INDAnimationCharging_Act) {
           case IN_WPC2INDAnimationCharging_1st:
            exit_internal_WPC2INDAnimationC();
            g_previousEvent = App_Model_DW.sfEvent_j;
            App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
            if (App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_i();
            }

            App_Model_DW.sfEvent_j = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Model_IN_NO_ACTIVE_CHILD_kl;
            break;

           case IN_WPC2INDAnimationCharging_2nd:
            exit_internal_WPC2INDAnimatio_c();
            g_previousEvent = App_Model_DW.sfEvent_j;
            App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
            if (App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_i();
            }

            App_Model_DW.sfEvent_j = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Model_IN_NO_ACTIVE_CHILD_kl;
            break;

           case IN_WPC2INDAnimationCharging_Off:
            exit_internal_WPC2INDAnimatio_p();
            g_previousEvent = App_Model_DW.sfEvent_j;
            App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
            if (App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_i();
            }

            App_Model_DW.sfEvent_j = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Model_IN_NO_ACTIVE_CHILD_kl;
            break;

           case IN_WPCINDAnimationCharging_3r_e:
            exit_internal_WPCINDAnimation_m();
            g_previousEvent = App_Model_DW.sfEvent_j;
            App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
            if (App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_i();
            }

            App_Model_DW.sfEvent_j = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Model_IN_NO_ACTIVE_CHILD_kl;
            break;
          }

          /* CancelTimer에서 StartTimer로 변경 221216 */
          g_previousEvent = App_Model_DW.sfEvent_j;
          App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
          if (App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_i();
          }

          App_Model_DW.sfEvent_j = g_previousEvent;
          App_Model_DW.is_WPC2INDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_kl;
        } else {
          App_Model_DW.is_WPC2INDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_kl;
        }

        g_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mo_IN_WPC2INDAnimation_Init;
        App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = g_previousEvent;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__Default;
        *rty_INDAnimation_Sig_o = WPC2IndCmdState__Default;
      } else {
        switch (App_Model_DW.is_WPC2INDAnimation_Charging) {
         case IN_WPC2INDAnimationCharging_Act:
          WPC2INDAnimationCharging_Active(rtu_PostProcessIn_f, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
          break;

         case IN_WPC2INDAnimationCharging_Pre:
          {
            /* 1 */
            if (App_Model_DW.Timer_INDLight >= 100U) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j;
              App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
              if (App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_i();
              }

              App_Model_DW.sfEvent_j = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(rtu_PostProcessIn, rtu_PostProcessIn_o, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
            }
          }
          break;

         case IN_WPC2INDAnimationCharging_P_m:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2 */
            } else if ((App_Model_DW.Timer_INDLight >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__RWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_d !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_star_g) || (App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j;
              App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
              if (App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_i();
              }

              App_Model_DW.sfEvent_j = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(rtu_PostProcessIn, rtu_PostProcessIn_o, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
            }
          }
          break;

         case IN_WPC2INDAnimationCharging_P_o:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2 */
            } else if (rtu_PostProcessIn_a == PreSyncAct__WPC) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_P_n;

              /* 3  */
            } else if ((App_Model_DW.Timer_INDLight >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__RWPCWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_d !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_star_g) || (App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j;
              App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
              if (App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_i();
              }

              App_Model_DW.sfEvent_j = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(rtu_PostProcessIn, rtu_PostProcessIn_o, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
            }
          }
          break;

         case IN_WPC2INDAnimationCharging_P_n:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2  */
            } else if ((App_Model_DW.Timer_INDLight >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__WPC) && ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) ||
                        (App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j;
              App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
              if (App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_i();
              }

              App_Model_DW.sfEvent_j = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(rtu_PostProcessIn, rtu_PostProcessIn_o, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
            }
          }
          break;

         case IN_WPC2INDAnimationCharging__n2:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && (tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2 */
            } else if (rtu_PostProcessIn_a == PreSyncAct__RWPC) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_P_m;

              /* 3 */
            } else if ((App_Model_DW.Timer_INDLight >= 100U) && (rtu_PostProcessIn_a == PreSyncAct__WPCRWPC) && ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev !=
                         App_Model_DW.Input_CAN_WPCIndSyncVal_start) || (App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j;
              App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
              if (App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_i();
              }

              App_Model_DW.sfEvent_j = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(rtu_PostProcessIn, rtu_PostProcessIn_o, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
            }
          }
          break;
        }
      }
    }
    break;

   case App_M_IN_WPC2INDAnimation_Error:
    /* Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
    App_Mode_WPC2INDAnimation_Error(rtu_PostProcessIn_f, rtu_PostProcessIn_a, rtu_PostProcessIn_j, rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
    break;

   case App_Mo_IN_WPC2INDAnimation_Init:
    {
      /* Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
      /* 2 */
      if ((rtu_PostProcessIn_f == PhoneCharging) && (rtu_PostProcessIn_j == WPCIndUSMState__Type2)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        App_Model_DW.is_IND_Animation_Sync_Control_F = Ap_IN_WPC2INDAnimation_Charging;
        g_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = App_event_StartTimer_INDLight_i;
        if (App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_i();
        }

        App_Model_DW.sfEvent_j = g_previousEvent;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__3rdSync;
        *rty_INDAnimation_Sig_o = WPC2IndCmdState__3rdChrgOn;

        /* 1
           [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC)] */
        switch (rtu_PostProcessIn_a) {
         case PreSyncAct__WPC:
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_P_n;
          break;

         case PreSyncAct__RWPC:
          /* 2
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPC)] */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_P_m;
          break;

         case PreSyncAct__RWPCWPC:
          /* 3
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPCWPC)] */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_P_o;
          break;

         case PreSyncAct__WPCRWPC:
          /* 4
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPCRWPC)] */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging__n2;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;
          break;
        }

        /* 3 */
      } else if (((rtu_PostProcessIn_f == Charging_error) || (rtu_PostProcessIn_f == NFCCardDetected)) && (rtu_PostProcessIn_nk == On)) {
        sint32 g_previousEvent;
        App_Model_DW.is_IND_Animation_Sync_Control_F = App_M_IN_WPC2INDAnimation_Error;
        g_previousEvent = App_Model_DW.sfEvent_j;
        App_Model_DW.sfEvent_j = Ap_event_StartTimer_INDFadeIn_n;
        if (App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_d();
        }

        App_Model_DW.sfEvent_j = g_previousEvent;
        *rty_INDAnimation_Sig = WPC2IndSyncVal__ErrorOn;
        App_Model_TypeCont_c(rtu_PostProcessIn_j, rty_INDAnimation_Sig_o);

        /* 1 */
        switch (rtu_PostProcessIn_a) {
         case PreSyncAct__WPC:
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreWPC;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreRW_a;
          break;

         case PreSyncAct__RWPCWPC:
          /* 3 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreRWP;
          break;

         case PreSyncAct__WPCRWPC:
          /* 4 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreWPC;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;
          break;
        }
      }
    }
    break;
  }
}

/* System initialize for atomic system: '<S202>/IND_Animation_Control_Function' */
void IND_Animation_Control_Fu_b_Init(WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* SystemInitialize for Chart: '<S211>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPC_IND_Command_State_Con_Init(&App_Model_B.Var_RWPCIndCmdState, &App_Model_DW.sf_RWPC_IND_Command_State_Con_b);

  /* SystemInitialize for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
  App_Model_DW.sfEvent_j = App_Model_CALL_EVENT_ct;
  *rty_INDAnimation_Sig = WPC2IndSyncVal__Default;
  *rty_INDAnimation_Sig_o = WPC2IndCmdState__Default;
}

/* System reset for atomic system: '<S202>/IND_Animation_Control_Function' */
void IND_Animation_Control_F_g_Reset(WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* SystemReset for Chart: '<S211>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPC_IND_Command_State_Co_Reset(&App_Model_B.Var_RWPCIndCmdState, &App_Model_DW.sf_RWPC_IND_Command_State_Con_b);

  /* SystemReset for Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
  App_Model_DW.sfEvent_j = App_Model_CALL_EVENT_ct;
  App_Model_DW.is_active_INDFadeIn = 0U;
  App_Model_DW.is_INDFadeIn = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_active_INDFadeOut = 0U;
  App_Model_DW.is_INDFadeOut = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_active_INDLight = 0U;
  App_Model_DW.is_INDLight = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_active_IND_Animation_Sync_Co = 0U;
  App_Model_DW.is_IND_Animation_Sync_Control_F = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_WPC2INDAnimation_Charging = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_WPC2INDAnimation_Error = App_Model_IN_NO_ACTIVE_CHILD_kl;
  App_Model_DW.is_active_c200_WPC_IND_Animatio = 0U;
  App_Model_DW.Timer_INDLight = 0U;
  App_Model_DW.Timer_INDFadeIn = 0U;
  App_Model_DW.Timer_INDFadeOut = 0U;
  *rty_INDAnimation_Sig = WPC2IndSyncVal__Default;
  *rty_INDAnimation_Sig_o = WPC2IndCmdState__Default;
  App_Model_DW.Var_PreSyncAct_prev = PreSyncAct__Off;
  App_Model_DW.Var_PreSyncAct_start = PreSyncAct__Off;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_d = RWPCIndSyncVal__Default;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_star_g = RWPCIndSyncVal__Default;
  App_Model_DW.Var_INT_RWPCIndCmdState_prev = RWPCIndCmdState__Default;
  App_Model_DW.Var_INT_RWPCIndCmdState_start = RWPCIndCmdState__Default;
  App_Model_DW.Input_CAN_WPCIndSyncVal_prev = WPCIndSyncVal__Default;
  App_Model_DW.Input_CAN_WPCIndSyncVal_start = WPCIndSyncVal__Default;
  App_Model_DW.Var_INT_WPCIndCmdState_prev = WPCIndCmdState__Default;
  App_Model_DW.Var_INT_WPCIndCmdState_start = WPCIndCmdState__Default;
  App_Model_DW.WPCIndUSMState_prev = WPCIndUSMState__Default;
  App_Model_DW.WPCIndUSMState_start = WPCIndUSMState__Default;
  App_Model_DW.b_SyncAmber_prev = Off;
  App_Model_DW.b_SyncAmber_start = Off;
}

/* Output and update for atomic system: '<S202>/IND_Animation_Control_Function' */
void IND_Animation_Control_Functio_i(C_WPCIndSyncVal rtu_PostProcessIn, RWPCIndSyncVal rtu_PostProcessIn_o, C_WPCWarning rtu_PostProcessIn_f, PreSyncAct rtu_PostProcessIn_a, WPCIndCmdState
  rtu_PostProcessIn_n, WPCIndUSMState rtu_PostProcessIn_j, Bool rtu_PostProcessIn_nk, WPC2IndSyncVal *rty_INDAnimation_Sig, WPC2IndCmdState *rty_INDAnimation_Sig_o)
{
  /* Chart: '<S211>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  RWPC_IND_Command_State_Control_(rtu_PostProcessIn_o, &App_Model_B.Var_RWPCIndCmdState, &App_Model_DW.sf_RWPC_IND_Command_State_Con_b);

  /* Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
  App_Model_DW.sfEvent_j = App_Model_CALL_EVENT_ct;
  App_Model_DW.Var_PreSyncAct_prev = App_Model_DW.Var_PreSyncAct_start;
  App_Model_DW.Var_PreSyncAct_start = rtu_PostProcessIn_a;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_d = App_Model_DW.Input_CAN_RWPCIndSyncVal_star_g;
  App_Model_DW.Input_CAN_RWPCIndSyncVal_star_g = rtu_PostProcessIn_o;
  App_Model_DW.Var_INT_RWPCIndCmdState_prev = App_Model_DW.Var_INT_RWPCIndCmdState_start;
  App_Model_DW.Var_INT_RWPCIndCmdState_start = App_Model_B.Var_RWPCIndCmdState;
  App_Model_DW.Input_CAN_WPCIndSyncVal_prev = App_Model_DW.Input_CAN_WPCIndSyncVal_start;
  App_Model_DW.Input_CAN_WPCIndSyncVal_start = rtu_PostProcessIn;
  App_Model_DW.Var_INT_WPCIndCmdState_prev = App_Model_DW.Var_INT_WPCIndCmdState_start;
  App_Model_DW.Var_INT_WPCIndCmdState_start = rtu_PostProcessIn_n;
  App_Model_DW.WPCIndUSMState_prev = App_Model_DW.WPCIndUSMState_start;
  App_Model_DW.WPCIndUSMState_start = rtu_PostProcessIn_j;
  App_Model_DW.b_SyncAmber_prev = App_Model_DW.b_SyncAmber_start;
  App_Model_DW.b_SyncAmber_start = rtu_PostProcessIn_nk;
  if (App_Model_DW.is_active_c200_WPC_IND_Animatio == 0U) {
    App_Model_DW.Var_PreSyncAct_prev = rtu_PostProcessIn_a;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_prev_d = rtu_PostProcessIn_o;
    App_Model_DW.Var_INT_RWPCIndCmdState_prev = App_Model_B.Var_RWPCIndCmdState;
    App_Model_DW.Input_CAN_WPCIndSyncVal_prev = rtu_PostProcessIn;
    App_Model_DW.Var_INT_WPCIndCmdState_prev = rtu_PostProcessIn_n;
    App_Model_DW.WPCIndUSMState_prev = rtu_PostProcessIn_j;
    App_Model_DW.b_SyncAmber_prev = rtu_PostProcessIn_nk;
    App_Model_DW.is_active_c200_WPC_IND_Animatio = 1U;
    App_Model_DW.is_active_INDLight = 1U;
    App_Model_DW.is_INDLight = App_Model_IN_INDLight2_Off;
    App_Model_DW.Timer_INDLight = 0U;
    App_Model_DW.is_active_IND_Animation_Sync_Co = 1U;

    /* Default */
    App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mo_IN_WPC2INDAnimation_Init;
    App_Model_DW.sfEvent_j = Ap_event_CancelTimer_INDLight_b;
    App_Model_INDLight_i();
    App_Model_DW.sfEvent_j = -1;
    *rty_INDAnimation_Sig = WPC2IndSyncVal__Default;
    *rty_INDAnimation_Sig_o = WPC2IndCmdState__Default;
    App_Model_DW.is_active_INDFadeIn = 1U;
    App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_Off_l;
    App_Model_DW.Timer_INDFadeIn = 0U;
    App_Model_DW.is_active_INDFadeOut = 1U;
    App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_Off_e;
    App_Model_DW.Timer_INDFadeOut = 0U;
  } else {
    if (App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_i();
    }

    if (App_Model_DW.is_active_IND_Animation_Sync_Co != 0U) {
      IND_Animation_Sync_Control_Fu_d(rtu_PostProcessIn, rtu_PostProcessIn_o, rtu_PostProcessIn_f, rtu_PostProcessIn_a, rtu_PostProcessIn_n, rtu_PostProcessIn_j, rtu_PostProcessIn_nk,
        rty_INDAnimation_Sig, rty_INDAnimation_Sig_o);
    }

    if (App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_d();
    }

    if (App_Model_DW.is_active_INDFadeOut != 0U) {
      App_Model_INDFadeOut_g();
    }
  }

  /* End of Chart: '<S211>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
