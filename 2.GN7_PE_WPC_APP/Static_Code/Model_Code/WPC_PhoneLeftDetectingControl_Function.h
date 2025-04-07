/*
 * File: WPC_PhoneLeftDetectingControl_Function.h
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

#ifndef RTW_HEADER_WPC_PhoneLeftDetectingControl_Function_h_
#define RTW_HEADER_WPC_PhoneLeftDetectingControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S186>/WPC_PhoneLeftDetectingControlFunction' */
typedef struct {
  sint32 sfEvent;                      /* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  uint32 Timer_ProtectionBlinking;     /* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  uint8 is_active_c3_WPC_PhoneLeftDetec;/* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  uint8 is_MultiCardDetecting;         /* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  uint8 is_active_MultiCardDetecting;  /* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  uint8 is_ProtectionBlinking;         /* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  uint8 is_active_ProtectionBlinking;  /* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  CardProtection CardProtectionResult_prev;/* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
  CardProtection CardProtectionResult_start;/* '<S186>/WPC_PhoneLeftDetectingControlFunction' */
} DW_WPC_PhoneLeftDetectingCont_T;

extern void WPC_PhoneLeftDetectingCont_Init(Bool *rty_b_CardProtection, DW_WPC_PhoneLeftDetectingCont_T *localDW);
extern void WPC_PhoneLeftDetectingCon_Reset(Bool *rty_b_CardProtection, DW_WPC_PhoneLeftDetectingCont_T *localDW);
extern void WPC_PhoneLeftDetectingControlFu(CardProtection rtu_CardProtectionResult, Bool *rty_b_CardProtection, DW_WPC_PhoneLeftDetectingCont_T *localDW);
extern void WPC_PhoneLeftDetectingCo_f_Init(Bool *rty_b_CardProtection);
extern void WPC_PhoneLeftDetectingControl_F(CardProtection rtu_PreProcessIn, Bool *rty_b_CardProtection);
extern void WPC_PhoneLeftDetectingCo_h_Init(Bool *rty_b_CardProtection);
extern void WPC_PhoneLeftDetectingC_f_Reset(Bool *rty_b_CardProtection);
extern void WPC_PhoneLeftDetectingControl_k(CardProtection rtu_PreProcessIn, Bool *rty_b_CardProtection);

#endif                                 /* RTW_HEADER_WPC_PhoneLeftDetectingControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
