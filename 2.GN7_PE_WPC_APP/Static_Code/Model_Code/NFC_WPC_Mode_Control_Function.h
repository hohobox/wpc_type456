/*
 * File: NFC_WPC_Mode_Control_Function.h
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

#ifndef RTW_HEADER_NFC_WPC_Mode_Control_Function_h_
#define RTW_HEADER_NFC_WPC_Mode_Control_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S181>/WPC_Mode_Control' */
typedef struct {
  uint8 is_active_c4_NFC_WPC_Mode_Contr;/* '<S187>/WPC_Mode_Control' */
  uint8 is_WpcNfcModeControl;          /* '<S187>/WPC_Mode_Control' */
} DW_WPC_Mode_Control_App_Model_T;

extern void App_Model_WPC_Mode_Control(Bool rtu_R_Local_L_IGN1_IN, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_R_Local_sbBatStateFault, WPCStatus *rty_WPC_Status, DW_WPC_Mode_Control_App_Model_T
  *localDW);
extern void NFC_WPC_Mode_Control_Funct_Init(WPCStatus *rty_WPCStatus);
extern void A_NFC_WPC_Mode_Control_Function(Bool rtu_PreProcessIn, LC_IAUWPCNFCcmd rtu_PreProcessIn_c, LC_IAUWPCNFCcmd rtu_PreProcessIn_p, Bool rtu_PreProcessIn_a, IAU_OwnerPhnRegRVal
  rtu_PreProcessIn_m, OwnerPairingAdvertisingReq rtu_PreProcessIn_i, C_WPCOnOffNvalueSet rtu_PreProcessIn_ak, OnThePad rtu_PreProcessIn_e, LC_WPC_NFCDetection rtu_PreProcessIn_h, Bool
  rtu_PreProcessIn_g, Bool rtu_PreProcessIn_n, WPCStatus rtu_PreProcessIn_hg, uint8 rtu_PreProcessIn_go, uint8 rtu_PreProcessIn_mc, Bool rtu_PreProcessIn_k, C_WPCWarning rtu_PreProcessIn_n5, Bool
  rtu_PreProcessIn_i2, Bool rtu_PreProcessIn_mg, Bool rtu_PreProcessIn_d, WPCStatus *rty_WPCStatus);
extern void NFC_WPC_Mode_Control_Fun_f_Init(WPCStatus *rty_WPC2Status);
extern void NFC_WPC_Mode_Control_Function_m(Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_c, LC_IAUWPCNFCcmd rtu_PreProcessIn_e, C_WPCOnOffNvalueSet rtu_PreProcessIn_m, IAU_OwnerPhnRegRVal
  rtu_PreProcessIn_j, OwnerPairingAdvertisingReq rtu_PreProcessIn_l, OnThePad rtu_PreProcessIn_b, LC_WPC_NFCDetection rtu_PreProcessIn_k, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_mb, WPCStatus
  rtu_PreProcessIn_a, uint8 rtu_PreProcessIn_p5, uint8 rtu_PreProcessIn_cp, Bool rtu_PreProcessIn_h, C_WPCWarning rtu_PreProcessIn_ai, Bool rtu_PreProcessIn_d, LC_IAUWPCNFCcmd rtu_PreProcessIn_hl,
  Bool rtu_PreProcessIn_jq, Bool rtu_PreProcessIn_ec, WPCStatus *rty_WPC2Status);

#endif                                 /* RTW_HEADER_NFC_WPC_Mode_Control_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
