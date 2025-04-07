/*
 * File: WPC_PhoneLeftDetectingControl_Function.c
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
#include "WPC_PhoneLeftDetectingControl_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S186>/WPC_PhoneLeftDetectingControlFunction' */
#define App_M_IN_MultiCardDetection_Off ((uint8)1U)
#define App_M_IN_ProtectionBlinking_Off ((uint8)1U)
#define App_Mo_IN_MultiCardDetection_On ((uint8)2U)
#define App_Mo_IN_ProtectionBlinking_On ((uint8)2U)
#define App_Model_CALL_EVENT_a         (-1)
#define App_Model_IN_NO_ACTIVE_CHILD_g ((uint8)0U)
#define event_CancelTimer_ProtectionBli (0)
#define event_StartTimer_ProtectionBlin (1)

/* Forward declaration for local functions */
static void App_Model_ProtectionBlinking(DW_WPC_PhoneLeftDetectingCont_T *localDW);

/* Function for Chart: '<S186>/WPC_PhoneLeftDetectingControlFunction' */
static void App_Model_ProtectionBlinking(DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  switch (localDW->is_ProtectionBlinking) {
   case App_M_IN_ProtectionBlinking_Off:
    if (localDW->sfEvent == event_StartTimer_ProtectionBlin) {
      localDW->is_ProtectionBlinking = App_Mo_IN_ProtectionBlinking_On;
    }
    break;

   case App_Mo_IN_ProtectionBlinking_On:
    {
      switch (localDW->sfEvent) {
       case event_CancelTimer_ProtectionBli:
        localDW->is_ProtectionBlinking = App_M_IN_ProtectionBlinking_Off;
        localDW->Timer_ProtectionBlinking = 0U;
        break;

       case event_StartTimer_ProtectionBlin:
        localDW->Timer_ProtectionBlinking = 0U;
        localDW->is_ProtectionBlinking = App_Mo_IN_ProtectionBlinking_On;
        break;

       default:
        {
          uint32 qY;
          qY = localDW->Timer_ProtectionBlinking + /*MW:OvSatOk*/ 1U;
          if (localDW->Timer_ProtectionBlinking + 1U < localDW->Timer_ProtectionBlinking) {
            qY = MAX_uint32_T;
          }

          localDW->Timer_ProtectionBlinking = qY;
        }
        break;
      }
    }
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S186>/WPC_PhoneLeftDetectingControlFunction'
 *    '<S366>/WPC_PhoneLeftDetectingControlFunction'
 */
void WPC_PhoneLeftDetectingCont_Init(Bool *rty_b_CardProtection, DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_a;
  *rty_b_CardProtection = Off;
}

/*
 * System reset for atomic system:
 *    '<S186>/WPC_PhoneLeftDetectingControlFunction'
 *    '<S366>/WPC_PhoneLeftDetectingControlFunction'
 */
void WPC_PhoneLeftDetectingCon_Reset(Bool *rty_b_CardProtection, DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_a;
  localDW->is_active_MultiCardDetecting = 0U;
  localDW->is_MultiCardDetecting = App_Model_IN_NO_ACTIVE_CHILD_g;
  localDW->is_active_ProtectionBlinking = 0U;
  localDW->is_ProtectionBlinking = App_Model_IN_NO_ACTIVE_CHILD_g;
  localDW->is_active_c3_WPC_PhoneLeftDetec = 0U;
  localDW->Timer_ProtectionBlinking = 0U;
  *rty_b_CardProtection = Off;
  localDW->CardProtectionResult_prev = CardPro_Default;
  localDW->CardProtectionResult_start = CardPro_Default;
}

/*
 * Output and update for atomic system:
 *    '<S186>/WPC_PhoneLeftDetectingControlFunction'
 *    '<S366>/WPC_PhoneLeftDetectingControlFunction'
 */
void WPC_PhoneLeftDetectingControlFu(CardProtection rtu_CardProtectionResult, Bool *rty_b_CardProtection, DW_WPC_PhoneLeftDetectingCont_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_a;
  localDW->CardProtectionResult_prev = localDW->CardProtectionResult_start;
  localDW->CardProtectionResult_start = rtu_CardProtectionResult;

  /* Chart: '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  if (localDW->is_active_c3_WPC_PhoneLeftDetec == 0U) {
    localDW->CardProtectionResult_prev = rtu_CardProtectionResult;
    localDW->is_active_c3_WPC_PhoneLeftDetec = 1U;
    localDW->is_active_ProtectionBlinking = 1U;
    localDW->is_ProtectionBlinking = App_M_IN_ProtectionBlinking_Off;
    localDW->Timer_ProtectionBlinking = 0U;
    localDW->is_active_MultiCardDetecting = 1U;
    localDW->is_MultiCardDetecting = App_M_IN_MultiCardDetection_Off;
    *rty_b_CardProtection = Off;
    localDW->sfEvent = event_CancelTimer_ProtectionBli;
    App_Model_ProtectionBlinking(localDW);
    localDW->sfEvent = -1;
  } else {
    if (localDW->is_active_ProtectionBlinking != 0U) {
      App_Model_ProtectionBlinking(localDW);
    }

    if (localDW->is_active_MultiCardDetecting != 0U) {
      switch (localDW->is_MultiCardDetecting) {
       case App_M_IN_MultiCardDetection_Off:
        *rty_b_CardProtection = Off;

        /* 1. */
        if (rtu_CardProtectionResult == CardPro_Prohibit) {
          localDW->is_MultiCardDetecting = App_Mo_IN_MultiCardDetection_On;
          *rty_b_CardProtection = On;
          localDW->sfEvent = event_StartTimer_ProtectionBlin;
          if (localDW->is_active_ProtectionBlinking != 0U) {
            App_Model_ProtectionBlinking(localDW);
          }

          localDW->sfEvent = -1;
        }
        break;

       case App_Mo_IN_MultiCardDetection_On:
        *rty_b_CardProtection = On;
        if ((localDW->CardProtectionResult_prev != localDW->CardProtectionResult_start) && (localDW->CardProtectionResult_start == CardPro_Prohibit)) {
          localDW->sfEvent = event_CancelTimer_ProtectionBli;
          if (localDW->is_active_ProtectionBlinking != 0U) {
            App_Model_ProtectionBlinking(localDW);
          }

          localDW->is_MultiCardDetecting = App_Mo_IN_MultiCardDetection_On;
          *rty_b_CardProtection = On;
          localDW->sfEvent = event_StartTimer_ProtectionBlin;
          if (localDW->is_active_ProtectionBlinking != 0U) {
            App_Model_ProtectionBlinking(localDW);
          }

          localDW->sfEvent = -1;

          /* 1. */
        } else if (((localDW->CardProtectionResult_start == CardPro_Default) || (localDW->CardProtectionResult_start == CardPro_Allow)) && (localDW->Timer_ProtectionBlinking >= 400U)) {
          /* 4s] */
          localDW->sfEvent = event_CancelTimer_ProtectionBli;
          if (localDW->is_active_ProtectionBlinking != 0U) {
            App_Model_ProtectionBlinking(localDW);
          }

          localDW->is_MultiCardDetecting = App_M_IN_MultiCardDetection_Off;
          *rty_b_CardProtection = Off;
          localDW->sfEvent = event_CancelTimer_ProtectionBli;
          if (localDW->is_active_ProtectionBlinking != 0U) {
            App_Model_ProtectionBlinking(localDW);
          }

          localDW->sfEvent = -1;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S186>/WPC_PhoneLeftDetectingControlFunction' */
}

/* System initialize for atomic system: '<S18>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingCo_f_Init(Bool *rty_b_CardProtection)
{
  /* SystemInitialize for Chart: '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  WPC_PhoneLeftDetectingCont_Init(rty_b_CardProtection, &App_Model_DW.sf_WPC_PhoneLeftDetectingContro);
}

/* Output and update for atomic system: '<S18>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingControl_F(CardProtection rtu_PreProcessIn, Bool *rty_b_CardProtection)
{
  /* Chart: '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  WPC_PhoneLeftDetectingControlFu(rtu_PreProcessIn, rty_b_CardProtection, &App_Model_DW.sf_WPC_PhoneLeftDetectingContro);
}

/* System initialize for atomic system: '<S203>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingCo_h_Init(Bool *rty_b_CardProtection)
{
  /* SystemInitialize for Chart: '<S366>/WPC_PhoneLeftDetectingControlFunction' */
  WPC_PhoneLeftDetectingCont_Init(rty_b_CardProtection, &App_Model_DW.sf_WPC_PhoneLeftDetectingCont_k);
}

/* System reset for atomic system: '<S203>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingC_f_Reset(Bool *rty_b_CardProtection)
{
  /* SystemReset for Chart: '<S366>/WPC_PhoneLeftDetectingControlFunction' */
  WPC_PhoneLeftDetectingCon_Reset(rty_b_CardProtection, &App_Model_DW.sf_WPC_PhoneLeftDetectingCont_k);
}

/* Output and update for atomic system: '<S203>/WPC_PhoneLeftDetectingControl_Function' */
void WPC_PhoneLeftDetectingControl_k(CardProtection rtu_PreProcessIn, Bool *rty_b_CardProtection)
{
  /* Chart: '<S366>/WPC_PhoneLeftDetectingControlFunction' */
  WPC_PhoneLeftDetectingControlFu(rtu_PreProcessIn, rty_b_CardProtection, &App_Model_DW.sf_WPC_PhoneLeftDetectingCont_k);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
