/*
 * File: WPC_PhoneLeftDetectingControl_Function.c
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
#include "WPC_PhoneLeftDetectingControl_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Forward declaration for local functions */
static uint8 App_M_safe_cast_to_C_WPCWarning(uint8 input);
static uint8 App_M_safe_cast_to_C_WPCWarning(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for C_WPCWarning (WPCWarningOff) */
  output = 0U;
  if (input <= 7U) {
    /* Set output value to input value if it is a member of C_WPCWarning */
    output = input;
  }

  return output;
}

/*
 * System initialize for atomic system:
 *    '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S384>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S596>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S816>/WPC_PhoneLeftDetectingControlFunction_FS23'
 */
void WPC_PhoneLeftDetectingCont_Init(C_WPCWarning *rty_Output_PhoneLeftWarningWPCS, DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  localDW->is_active_c1_WPC_PhoneLeftDetec = 0U;
  *rty_Output_PhoneLeftWarningWPCS = WPCWarningOff;
}

/*
 * System reset for atomic system:
 *    '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S384>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S596>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S816>/WPC_PhoneLeftDetectingControlFunction_FS23'
 */
void WPC_PhoneLeftDetectingCon_Reset(C_WPCWarning *rty_Output_PhoneLeftWarningWPCS, DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  localDW->is_active_c1_WPC_PhoneLeftDetec = 0U;
  *rty_Output_PhoneLeftWarningWPCS = WPCWarningOff;
}

/*
 * Output and update for atomic system:
 *    '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S384>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S596>/WPC_PhoneLeftDetectingControlFunction_FS23'
 *    '<S816>/WPC_PhoneLeftDetectingControlFunction_FS23'
 */
void WPC_PhoneLeftDetectingControlFu(WPCStatus rtu_Input_OPT_WPCStatus, Bool rtu_Input_OPT_b_MultiCardDetect, C_WPCWarning *rty_Output_PhoneLeftWarningWPCS, DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  /* Chart: '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  if ((uint32)localDW->is_active_c1_WPC_PhoneLeftDetec == 0U) {
    localDW->is_active_c1_WPC_PhoneLeftDetec = 1U;
    if (((uint32)rtu_Input_OPT_WPCStatus == WPCMode) && ((uint32)rtu_Input_OPT_b_MultiCardDetect == On)) {
      *rty_Output_PhoneLeftWarningWPCS = NFCCardDetected;
    } else {
      *rty_Output_PhoneLeftWarningWPCS = WPCWarningOff;
    }
  } else {
    *rty_Output_PhoneLeftWarningWPCS = (C_WPCWarning)App_M_safe_cast_to_C_WPCWarning(Off);
    if (((uint32)rtu_Input_OPT_WPCStatus == WPCMode) && ((uint32)rtu_Input_OPT_b_MultiCardDetect == On)) {
      *rty_Output_PhoneLeftWarningWPCS = NFCCardDetected;
    } else {
      *rty_Output_PhoneLeftWarningWPCS = WPCWarningOff;
    }
  }

  /* End of Chart: '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
}

/* System initialize for atomic system: '<S23>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectin_fcrj_Init(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* SystemInitialize for Chart: '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCont_Init(rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingContro);
}

/* System reset for atomic system: '<S23>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetecti_esdl_Reset(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* SystemReset for Chart: '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCon_Reset(rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingContro);
}

/* Output and update for atomic system: '<S23>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingControl_F(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* Chart: '<S194>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingControlFu(rtu_WPCStatus, rtu_PreProcessIn, rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingContro);
}

/* System initialize for atomic system: '<S218>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectin_ee2l_Init(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* SystemInitialize for Chart: '<S384>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCont_Init(rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_ni4i);
}

/* System reset for atomic system: '<S218>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetecti_lukg_Reset(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* SystemReset for Chart: '<S384>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCon_Reset(rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_ni4i);
}

/* Output and update for atomic system: '<S218>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingCont_k5ur(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn, C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* Chart: '<S384>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingControlFu(rtu_WPC2Status, rtu_PreProcessIn, rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_ni4i);
}

/* System initialize for atomic system: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectin_nhlp_Init(void)
{
  /* local block i/o variables */
  C_WPCWarning rtb_Output_PhoneLeftWarningWPCS;

  /* SystemInitialize for Chart: '<S596>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCont_Init(&rtb_Output_PhoneLeftWarningWPCS, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_fo5n);
}

/* System reset for atomic system: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetecti_grzc_Reset(void)
{
  /* local block i/o variables */
  C_WPCWarning rtb_Output_PhoneLeftWarningWPCS;

  /* SystemReset for Chart: '<S596>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCon_Reset(&rtb_Output_PhoneLeftWarningWPCS, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_fo5n);
}

/* Output and update for atomic system: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingCont_e5zj(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn)
{
  /* local block i/o variables */
  C_WPCWarning rtb_Output_PhoneLeftWarningWPCS;

  /* Chart: '<S596>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingControlFu(rtu_WPCStatus, rtu_PreProcessIn, &rtb_Output_PhoneLeftWarningWPCS, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_fo5n);
}

/* System initialize for atomic system: '<S640>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectin_l2ay_Init(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* SystemInitialize for Chart: '<S816>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCont_Init(rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_f5bl);
}

/* System reset for atomic system: '<S640>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetecti_fmai_Reset(C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* SystemReset for Chart: '<S816>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingCon_Reset(rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_f5bl);
}

/* Output and update for atomic system: '<S640>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingCont_evze(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, C_WPCWarning *rty_INT_PhoneLeftWarningWPCStat)
{
  /* Chart: '<S816>/WPC_PhoneLeftDetectingControlFunction_FS23' */
  WPC_PhoneLeftDetectingControlFu(rtu_WPCStatus, rtu_PreProcessIn, rty_INT_PhoneLeftWarningWPCStat, &App_Model_DW.sf_WPC_PhoneLeftDetectingC_f5bl);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
