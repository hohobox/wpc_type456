/*
 * File: PreventionSMK_LF_Interference_Function.c
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
#include "PreventionSMK_LF_Interference_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S184>/PreventionSMK_LF_Interference' */
#define A_event_Cancel_Timer_LFOffCheck (0)
#define Ap_event_Start_Timer_LFOffCheck (1)
#define App_Model_CALL_EVENT_n         (-1)
#define App_Model_IN_LFSearching_Off   ((uint8)1U)
#define App_Model_IN_LFSearching_On    ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_e ((uint8)0U)
#define App_Model_IN_Off_i             ((uint8)1U)
#define App_Model_IN_On_hs             ((uint8)2U)

/* Forward declaration for local functions */
static void App_Model_Tick_Timer_LFOffCheck(DW_PreventionSMK_LF_Interfere_T *localDW);
static void enter_internal_Tick_Timer_LFOff(DW_PreventionSMK_LF_Interfere_T *localDW);

/* Function for Chart: '<S184>/PreventionSMK_LF_Interference' */
static void App_Model_Tick_Timer_LFOffCheck(DW_PreventionSMK_LF_Interfere_T *localDW)
{
  switch (localDW->is_Tick_Timer_LFOffCheck) {
   case App_Model_IN_Off_i:
    if (localDW->sfEvent == Ap_event_Start_Timer_LFOffCheck) {
      localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_On_hs;
    }
    break;

   case App_Model_IN_On_hs:
    {
      if (localDW->sfEvent == A_event_Cancel_Timer_LFOffCheck) {
        localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_Off_i;
        localDW->Timer_LFOffCheck = 0U;
      } else {
        sint32 tmp;
        tmp = localDW->Timer_LFOffCheck + 1;
        if (localDW->Timer_LFOffCheck + 1 > 65535) {
          tmp = 65535;
        }

        localDW->Timer_LFOffCheck = (uint16)tmp;
        if (localDW->sfEvent == Ap_event_Start_Timer_LFOffCheck) {
          localDW->Timer_LFOffCheck = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S184>/PreventionSMK_LF_Interference' */
static void enter_internal_Tick_Timer_LFOff(DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_Off_i;
  localDW->Timer_LFOffCheck = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S184>/PreventionSMK_LF_Interference'
 *    '<S364>/PreventionSMK_LF_Interference'
 */
void PreventionSMK_LF_Interfere_Init(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_n;
  *rty_b_LFState = Off;
}

/*
 * System reset for atomic system:
 *    '<S184>/PreventionSMK_LF_Interference'
 *    '<S364>/PreventionSMK_LF_Interference'
 */
void PreventionSMK_LF_Interfer_Reset(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_n;
  localDW->is_active_PreventionSMK_LF_Inte = 0U;
  localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_NO_ACTIVE_CHILD_e;
  localDW->is_active_Tick_Timer_LFOffCheck = 0U;
  localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_NO_ACTIVE_CHILD_e;
  localDW->is_active_c3_PreventionOfSMK_LF = 0U;
  localDW->Timer_LFOffCheck = 0U;
  *rty_b_LFState = Off;
  localDW->L_LFSearchingOn_IN_prev = Off;
  localDW->L_LFSearchingOn_IN_start = Off;
  localDW->C_LFSearchingOn_prev = Off;
  localDW->C_LFSearchingOn_start = Off;
}

/*
 * Output and update for atomic system:
 *    '<S184>/PreventionSMK_LF_Interference'
 *    '<S364>/PreventionSMK_LF_Interference'
 */
void A_PreventionSMK_LF_Interference(Bool rtu_C_SMKOption, Bool rtu_C_LFSearchingOn, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_C_RLDrSw, Bool rtu_C_RRDrSw, Bool rtu_L_LFSearchingOn_IN,
  WPCStatus rtu_WPCStatus, Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_n;
  localDW->L_LFSearchingOn_IN_prev = localDW->L_LFSearchingOn_IN_start;
  localDW->L_LFSearchingOn_IN_start = rtu_L_LFSearchingOn_IN;
  localDW->C_LFSearchingOn_prev = localDW->C_LFSearchingOn_start;
  localDW->C_LFSearchingOn_start = rtu_C_LFSearchingOn;

  /* Chart: '<S184>/PreventionSMK_LF_Interference' */
  if (localDW->is_active_c3_PreventionOfSMK_LF == 0U) {
    localDW->L_LFSearchingOn_IN_prev = rtu_L_LFSearchingOn_IN;
    localDW->C_LFSearchingOn_prev = rtu_C_LFSearchingOn;
    localDW->is_active_c3_PreventionOfSMK_LF = 1U;
    localDW->is_active_Tick_Timer_LFOffCheck = 1U;
    enter_internal_Tick_Timer_LFOff(localDW);
    localDW->is_active_PreventionSMK_LF_Inte = 1U;
    localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_Off;
    localDW->sfEvent = A_event_Cancel_Timer_LFOffCheck;
    App_Model_Tick_Timer_LFOffCheck(localDW);
    localDW->sfEvent = -1;
    *rty_b_LFState = Off;
  } else {
    if (localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
      App_Model_Tick_Timer_LFOffCheck(localDW);
    }

    if (localDW->is_active_PreventionSMK_LF_Inte != 0U) {
      boolean guard1;
      guard1 = false;
      switch (localDW->is_PreventionSMK_LF_Interferenc) {
       case App_Model_IN_LFSearching_Off:
        *rty_b_LFState = Off;

        /* 1  */
        if ((rtu_C_SMKOption == On) && (rtu_WPCStatus == WPCMode) && ((rtu_C_DrvDrSw == On) || (rtu_C_AstDrSw == On) || (rtu_C_RLDrSw == On) || (rtu_C_RRDrSw == On) || (rtu_L_LFSearchingOn_IN == On) ||
             (rtu_C_LFSearchingOn == On))) {
          localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_On;
          localDW->sfEvent = Ap_event_Start_Timer_LFOffCheck;
          if (localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
            App_Model_Tick_Timer_LFOffCheck(localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_LFState = On;
        }
        break;

       case App_Model_IN_LFSearching_On:
        *rty_b_LFState = On;

        /* 1 */
        if ((rtu_WPCStatus != WPCMode) || (rtu_C_SMKOption == Off)) {
          guard1 = true;

          /* 2  */
        } else if (((localDW->L_LFSearchingOn_IN_prev != localDW->L_LFSearchingOn_IN_start) && (localDW->L_LFSearchingOn_IN_start == On)) || ((localDW->C_LFSearchingOn_prev !=
                     localDW->C_LFSearchingOn_start) && (localDW->C_LFSearchingOn_start == On))) {
          localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_On;
          localDW->sfEvent = Ap_event_Start_Timer_LFOffCheck;
          if (localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
            App_Model_Tick_Timer_LFOffCheck(localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_LFState = On;

          /* 3 */
        } else if ((rtu_C_SMKOption == On) && (rtu_C_DrvDrSw == Off) && (rtu_C_AstDrSw == Off) && (rtu_C_RLDrSw == Off) && (rtu_C_RRDrSw == Off) && (localDW->Timer_LFOffCheck >= 350) &&
                   (rtu_L_LFSearchingOn_IN == Off) && (rtu_C_LFSearchingOn == Off)) {
          guard1 = true;
        }
        break;
      }

      if (guard1) {
        localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_Off;
        localDW->sfEvent = A_event_Cancel_Timer_LFOffCheck;
        if (localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
          App_Model_Tick_Timer_LFOffCheck(localDW);
        }

        localDW->sfEvent = -1;
        *rty_b_LFState = Off;
      }
    }
  }

  /* End of Chart: '<S184>/PreventionSMK_LF_Interference' */
}

/* System initialize for atomic system: '<S18>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interfe_k_Init(Bool *rty_b_LFState)
{
  /* SystemInitialize for Chart: '<S184>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfere_Init(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interferenc);
}

/* Output and update for atomic system: '<S18>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interference_F(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_a, Bool rtu_PreProcessIn_as, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_k, Bool
  rtu_PreProcessIn_al, Bool rtu_PreProcessIn_m, Bool *rty_b_LFState)
{
  /* Chart: '<S184>/PreventionSMK_LF_Interference' */
  A_PreventionSMK_LF_Interference(rtu_PreProcessIn, rtu_PreProcessIn_a, rtu_PreProcessIn_as, rtu_PreProcessIn_p, rtu_PreProcessIn_k, rtu_PreProcessIn_al, rtu_PreProcessIn_m, rtu_WPCStatus,
    rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interferenc);
}

/* System initialize for atomic system: '<S203>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interfe_p_Init(Bool *rty_b_LFState)
{
  /* SystemInitialize for Chart: '<S364>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfere_Init(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interfere_n);
}

/* System reset for atomic system: '<S203>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interf_m_Reset(Bool *rty_b_LFState)
{
  /* SystemReset for Chart: '<S364>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfer_Reset(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interfere_n);
}

/* Output and update for atomic system: '<S203>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interference_c(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_g, Bool rtu_PreProcessIn_k, Bool rtu_PreProcessIn_d, Bool rtu_PreProcessIn_b, Bool
  rtu_PreProcessIn_c, Bool rtu_PreProcessIn_l, Bool *rty_b_LFState)
{
  /* Chart: '<S364>/PreventionSMK_LF_Interference' */
  A_PreventionSMK_LF_Interference(rtu_PreProcessIn, rtu_PreProcessIn_g, rtu_PreProcessIn_k, rtu_PreProcessIn_d, rtu_PreProcessIn_b, rtu_PreProcessIn_c, rtu_PreProcessIn_l, rtu_WPC2Status,
    rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interfere_n);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
