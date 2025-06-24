/*
 * File: PreventionSMK_LF_Interference_Function.c
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

#include "App_Model_types.h"
#include "PreventionSMK_LF_Interference_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S192>/PreventionSMK_LF_Interference' */
#define A_event_Cancel_Timer_LFOffCheck (0)
#define Ap_event_Start_Timer_LFOffCheck (1)
#define App_Mod_IN_NO_ACTIVE_CHILD_d5rp ((uint8)0U)
#define App_Model_CALL_EVENT_i1mb      (-1)
#define App_Model_IN_LFSearching_Off   ((uint8)1U)
#define App_Model_IN_LFSearching_On    ((uint8)2U)
#define App_Model_IN_Off_gzfl          ((uint8)1U)
#define App_Model_IN_On_ahv4           ((uint8)2U)

/* Forward declaration for local functions */
static void App_Model_Tick_Timer_LFOffCheck(DW_PreventionSMK_LF_Interfere_T *localDW);
static void enter_internal_Tick_Timer_LFOff(DW_PreventionSMK_LF_Interfere_T *localDW);

/* Function for Chart: '<S192>/PreventionSMK_LF_Interference' */
static void App_Model_Tick_Timer_LFOffCheck(DW_PreventionSMK_LF_Interfere_T *localDW)
{
  switch (localDW->is_Tick_Timer_LFOffCheck) {
   case App_Model_IN_Off_gzfl:
    if (localDW->sfEvent == (sint32)Ap_event_Start_Timer_LFOffCheck) {
      localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_On_ahv4;
    }
    break;

   case App_Model_IN_On_ahv4:
    {
      if (localDW->sfEvent == (sint32)A_event_Cancel_Timer_LFOffCheck) {
        localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_Off_gzfl;
        localDW->Timer_LFOffCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_LFOffCheck + 1;
        if (((sint32)localDW->Timer_LFOffCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_LFOffCheck = (uint16)tmp;
        if (localDW->sfEvent == (sint32)Ap_event_Start_Timer_LFOffCheck) {
          localDW->Timer_LFOffCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S192>/PreventionSMK_LF_Interference' */
static void enter_internal_Tick_Timer_LFOff(DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->is_Tick_Timer_LFOffCheck = App_Model_IN_Off_gzfl;
  localDW->Timer_LFOffCheck = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S192>/PreventionSMK_LF_Interference'
 *    '<S382>/PreventionSMK_LF_Interference'
 *    '<S594>/PreventionSMK_LF_Interference'
 *    '<S814>/PreventionSMK_LF_Interference'
 */
void PreventionSMK_LF_Interfere_Init(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_i1mb;
  localDW->is_active_PreventionSMK_LF_Inte = 0U;
  localDW->is_PreventionSMK_LF_Interferenc = App_Mod_IN_NO_ACTIVE_CHILD_d5rp;
  localDW->is_active_Tick_Timer_LFOffCheck = 0U;
  localDW->is_Tick_Timer_LFOffCheck = App_Mod_IN_NO_ACTIVE_CHILD_d5rp;
  localDW->is_active_c3_PreventionOfSMK_LF = 0U;
  localDW->Timer_LFOffCheck = 0U;
  *rty_b_LFState = Off;
  localDW->L_LFSearchingOn_IN_prev = Off;
  localDW->L_LFSearchingOn_IN_start = Off;
  localDW->C_LFSearchingOn_prev = Off;
  localDW->C_LFSearchingOn_start = Off;
}

/*
 * System reset for atomic system:
 *    '<S192>/PreventionSMK_LF_Interference'
 *    '<S382>/PreventionSMK_LF_Interference'
 *    '<S594>/PreventionSMK_LF_Interference'
 *    '<S814>/PreventionSMK_LF_Interference'
 */
void PreventionSMK_LF_Interfer_Reset(Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_i1mb;
  localDW->is_active_PreventionSMK_LF_Inte = 0U;
  localDW->is_PreventionSMK_LF_Interferenc = App_Mod_IN_NO_ACTIVE_CHILD_d5rp;
  localDW->is_active_Tick_Timer_LFOffCheck = 0U;
  localDW->is_Tick_Timer_LFOffCheck = App_Mod_IN_NO_ACTIVE_CHILD_d5rp;
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
 *    '<S192>/PreventionSMK_LF_Interference'
 *    '<S382>/PreventionSMK_LF_Interference'
 *    '<S594>/PreventionSMK_LF_Interference'
 *    '<S814>/PreventionSMK_LF_Interference'
 */
void A_PreventionSMK_LF_Interference(Bool rtu_C_SMKOption, Bool rtu_C_LFSearchingOn, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_C_RLDrSw, Bool rtu_C_RRDrSw, Bool rtu_L_LFSearchingOn_IN,
  WPCStatus rtu_WPCStatus, Bool *rty_b_LFState, DW_PreventionSMK_LF_Interfere_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_i1mb;
  localDW->L_LFSearchingOn_IN_prev = localDW->L_LFSearchingOn_IN_start;
  localDW->L_LFSearchingOn_IN_start = rtu_L_LFSearchingOn_IN;
  localDW->C_LFSearchingOn_prev = localDW->C_LFSearchingOn_start;
  localDW->C_LFSearchingOn_start = rtu_C_LFSearchingOn;

  /* Chart: '<S192>/PreventionSMK_LF_Interference' */
  if ((uint32)localDW->is_active_c3_PreventionOfSMK_LF == 0U) {
    localDW->L_LFSearchingOn_IN_prev = rtu_L_LFSearchingOn_IN;
    localDW->C_LFSearchingOn_prev = rtu_C_LFSearchingOn;
    localDW->is_active_c3_PreventionOfSMK_LF = 1U;
    localDW->is_active_Tick_Timer_LFOffCheck = 1U;
    enter_internal_Tick_Timer_LFOff(localDW);
    localDW->is_active_PreventionSMK_LF_Inte = 1U;
    localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_Off;
    localDW->sfEvent = (sint32)A_event_Cancel_Timer_LFOffCheck;
    App_Model_Tick_Timer_LFOffCheck(localDW);
    localDW->sfEvent = -1;
    *rty_b_LFState = Off;
  } else {
    if ((uint32)localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
      App_Model_Tick_Timer_LFOffCheck(localDW);
    }

    if ((uint32)localDW->is_active_PreventionSMK_LF_Inte != 0U) {
      boolean guard1;
      guard1 = false;
      switch (localDW->is_PreventionSMK_LF_Interferenc) {
       case App_Model_IN_LFSearching_Off:
        *rty_b_LFState = Off;

        /* 1  */
        if (((uint32)rtu_C_SMKOption == On) && ((uint32)rtu_WPCStatus == WPCMode) && (((uint32)rtu_C_DrvDrSw == On) || ((uint32)rtu_C_AstDrSw == On) || ((uint32)rtu_C_RLDrSw == On) || ((uint32)
              rtu_C_RRDrSw == On) || ((uint32)rtu_L_LFSearchingOn_IN == On) || ((uint32)rtu_C_LFSearchingOn == On))) {
          localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_On;
          localDW->sfEvent = (sint32)Ap_event_Start_Timer_LFOffCheck;
          if ((uint32)localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
            App_Model_Tick_Timer_LFOffCheck(localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_LFState = On;
        }
        break;

       case App_Model_IN_LFSearching_On:
        *rty_b_LFState = On;

        /* 1 */
        if (((uint32)rtu_WPCStatus != WPCMode) || ((uint32)rtu_C_SMKOption == Off)) {
          guard1 = true;

          /* 2  */
        } else if (((localDW->L_LFSearchingOn_IN_prev != localDW->L_LFSearchingOn_IN_start) && ((uint32)localDW->L_LFSearchingOn_IN_start == On)) || ((localDW->C_LFSearchingOn_prev !=
                     localDW->C_LFSearchingOn_start) && ((uint32)localDW->C_LFSearchingOn_start == On))) {
          localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_On;
          localDW->sfEvent = (sint32)Ap_event_Start_Timer_LFOffCheck;
          if ((uint32)localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
            App_Model_Tick_Timer_LFOffCheck(localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_LFState = On;

          /* 3 */
        } else if (((uint32)rtu_C_SMKOption == On) && ((uint32)rtu_C_DrvDrSw == Off) && ((uint32)rtu_C_AstDrSw == Off) && ((uint32)rtu_C_RLDrSw == Off) && ((uint32)rtu_C_RRDrSw == Off) &&
                   (localDW->Timer_LFOffCheck >= ((uint16)350U)) && ((uint32)rtu_L_LFSearchingOn_IN == Off) && ((uint32)rtu_C_LFSearchingOn == Off)) {
          guard1 = true;
        } else {
          /* no actions */
        }
        break;

       default:
        /* no actions */
        break;
      }

      if (guard1) {
        localDW->is_PreventionSMK_LF_Interferenc = App_Model_IN_LFSearching_Off;
        localDW->sfEvent = (sint32)A_event_Cancel_Timer_LFOffCheck;
        if ((uint32)localDW->is_active_Tick_Timer_LFOffCheck != 0U) {
          App_Model_Tick_Timer_LFOffCheck(localDW);
        }

        localDW->sfEvent = -1;
        *rty_b_LFState = Off;
      }
    }
  }

  /* End of Chart: '<S192>/PreventionSMK_LF_Interference' */
}

/* System initialize for atomic system: '<S23>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Inte_klhw_Init(Bool *rty_b_LFState)
{
  /* SystemInitialize for Chart: '<S192>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfere_Init(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interferenc);
}

/* System reset for atomic system: '<S23>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Int_jzga_Reset(Bool *rty_b_LFState)
{
  /* SystemReset for Chart: '<S192>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfer_Reset(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interferenc);
}

/* Output and update for atomic system: '<S23>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interference_F(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_a0qx, Bool rtu_PreProcessIn_asou, Bool rtu_PreProcessIn_pgig, Bool rtu_PreProcessIn_kksn,
  Bool rtu_PreProcessIn_alrb, Bool rtu_PreProcessIn_mt0u, Bool *rty_b_LFState)
{
  /* Chart: '<S192>/PreventionSMK_LF_Interference' */
  A_PreventionSMK_LF_Interference(rtu_PreProcessIn, rtu_PreProcessIn_a0qx, rtu_PreProcessIn_asou, rtu_PreProcessIn_pgig, rtu_PreProcessIn_kksn, rtu_PreProcessIn_alrb, rtu_PreProcessIn_mt0u,
    rtu_WPCStatus, rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interferenc);
}

/* System initialize for atomic system: '<S218>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Inte_ggwa_Init(Bool *rty_b_LFState)
{
  /* SystemInitialize for Chart: '<S382>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfere_Init(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_nvln);
}

/* System reset for atomic system: '<S218>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Int_ae1o_Reset(Bool *rty_b_LFState)
{
  /* SystemReset for Chart: '<S382>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfer_Reset(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_nvln);
}

/* Output and update for atomic system: '<S218>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interfere_c5sa(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_gmiy, Bool rtu_PreProcessIn_kncn, Bool rtu_PreProcessIn_dvpu, Bool rtu_PreProcessIn_b05j,
  Bool rtu_PreProcessIn_cxfs, Bool rtu_PreProcessIn_lonc, Bool *rty_b_LFState)
{
  /* Chart: '<S382>/PreventionSMK_LF_Interference' */
  A_PreventionSMK_LF_Interference(rtu_PreProcessIn, rtu_PreProcessIn_gmiy, rtu_PreProcessIn_kncn, rtu_PreProcessIn_dvpu, rtu_PreProcessIn_b05j, rtu_PreProcessIn_cxfs, rtu_PreProcessIn_lonc,
    rtu_WPC2Status, rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_nvln);
}

/* System initialize for atomic system: '<S463>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Inte_myco_Init(Bool *rty_b_LFState)
{
  /* SystemInitialize for Chart: '<S594>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfere_Init(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_fktv);
}

/* System reset for atomic system: '<S463>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Int_mhh2_Reset(Bool *rty_b_LFState)
{
  /* SystemReset for Chart: '<S594>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfer_Reset(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_fktv);
}

/* Output and update for atomic system: '<S463>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interfere_dgfk(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_au53, Bool rtu_PreProcessIn_h4gv, Bool rtu_PreProcessIn_lq5i, Bool rtu_PreProcessIn_okir,
  Bool rtu_PreProcessIn_jykw, Bool rtu_PreProcessIn_fswl, Bool *rty_b_LFState)
{
  /* Chart: '<S594>/PreventionSMK_LF_Interference' */
  A_PreventionSMK_LF_Interference(rtu_PreProcessIn, rtu_PreProcessIn_au53, rtu_PreProcessIn_h4gv, rtu_PreProcessIn_lq5i, rtu_PreProcessIn_okir, rtu_PreProcessIn_jykw, rtu_PreProcessIn_fswl,
    rtu_WPCStatus, rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_fktv);
}

/* System initialize for atomic system: '<S640>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Inte_oour_Init(Bool *rty_b_LFState)
{
  /* SystemInitialize for Chart: '<S814>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfere_Init(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_kwls);
}

/* System reset for atomic system: '<S640>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Int_gbj0_Reset(Bool *rty_b_LFState)
{
  /* SystemReset for Chart: '<S814>/PreventionSMK_LF_Interference' */
  PreventionSMK_LF_Interfer_Reset(rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_kwls);
}

/* Output and update for atomic system: '<S640>/PreventionSMK_LF_Interference_Function' */
void PreventionSMK_LF_Interfere_movb(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_kk5a, Bool rtu_PreProcessIn_o5yw, Bool rtu_PreProcessIn_e5bp, Bool rtu_PreProcessIn_epra,
  Bool rtu_PreProcessIn_exhh, Bool rtu_PreProcessIn_bzpc, Bool *rty_b_LFState)
{
  /* Chart: '<S814>/PreventionSMK_LF_Interference' */
  A_PreventionSMK_LF_Interference(rtu_PreProcessIn, rtu_PreProcessIn_kk5a, rtu_PreProcessIn_o5yw, rtu_PreProcessIn_e5bp, rtu_PreProcessIn_epra, rtu_PreProcessIn_exhh, rtu_PreProcessIn_bzpc,
    rtu_WPCStatus, rty_b_LFState, &App_Model_DW.sf_PreventionSMK_LF_Interf_kwls);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
