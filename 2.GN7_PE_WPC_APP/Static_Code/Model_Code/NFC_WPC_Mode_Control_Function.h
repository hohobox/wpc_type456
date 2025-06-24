/*
 * File: NFC_WPC_Mode_Control_Function.h
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

#ifndef RTW_HEADER_NFC_WPC_Mode_Control_Function_h_
#define RTW_HEADER_NFC_WPC_Mode_Control_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S189>/WPC_Mode_Control' */
typedef struct {
  uint8 is_active_c4_NFC_WPC_Mode_Contr;/* '<S195>/WPC_Mode_Control' */
  uint8 is_WpcNfcModeControl;          /* '<S195>/WPC_Mode_Control' */
} DW_WPC_Mode_Control_App_Model_T;

extern void App_Model_WPC_Mode_Control_Init(DW_WPC_Mode_Control_App_Model_T *localDW);
extern void App_Model_WPC_Mode_Control(Bool rtu_R_Local_L_IGN1_IN, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_R_Local_sbBatStateFault, WPCStatus *rty_WPC_Status, DW_WPC_Mode_Control_App_Model_T
  *localDW);
extern void NFC_WPC_Mode_Control_Funct_Init(WPCStatus *rty_WPCStatus);
extern void A_NFC_WPC_Mode_Control_Function(Bool rtu_PreProcessIn, LC_IAUWPCNFCcmd rtu_PreProcessIn_crbo, LC_IAUWPCNFCcmd rtu_PreProcessIn_p45h, Bool rtu_PreProcessIn_aaws, IAU_OwnerPhnRegRVal
  rtu_PreProcessIn_muxy, OwnerPairingAdvertisingReq rtu_PreProcessIn_ikas, C_WPCOnOffNvalueSet rtu_PreProcessIn_akvr, OnThePad rtu_PreProcessIn_etm5, LC_WPC_NFCDetection rtu_PreProcessIn_h3gr, Bool
  rtu_PreProcessIn_gvlh, Bool rtu_PreProcessIn_n1ix, WPCStatus rtu_PreProcessIn_hg1w, uint8 rtu_PreProcessIn_gomz, uint8 rtu_PreProcessIn_mc4r, Bool rtu_PreProcessIn_ksr2, C_WPCWarning
  rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_mgbl, Bool rtu_PreProcessIn_devb, Bool rtu_PreProcessIn_k524, WPCStatus *rty_WPCStatus);
extern void NFC_WPC_Mode_Control__dr2c_Init(WPCStatus *rty_WPC2Status);
extern void NFC_WPC_Mode_Control_Funct_mock(Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_cqtq, LC_IAUWPCNFCcmd rtu_PreProcessIn_eeym, C_WPCOnOffNvalueSet rtu_PreProcessIn_m2di, IAU_OwnerPhnRegRVal
  rtu_PreProcessIn_jp2a, OwnerPairingAdvertisingReq rtu_PreProcessIn_ltfm, OnThePad rtu_PreProcessIn_bfmr, LC_WPC_NFCDetection rtu_PreProcessIn_k3pf, Bool rtu_PreProcessIn_pjvj, Bool
  rtu_PreProcessIn_mbte, WPCStatus rtu_PreProcessIn_auml, uint8 rtu_PreProcessIn_p5um, uint8 rtu_PreProcessIn_cphf, Bool rtu_PreProcessIn_h4bs, C_WPCWarning rtu_PreProcessIn_aibk, Bool
  rtu_PreProcessIn_dwyv, LC_IAUWPCNFCcmd rtu_PreProcessIn_hld1, Bool rtu_PreProcessIn_jqrj, Bool rtu_PreProcessIn_ec0z, Bool rtu_PreProcessIn_pgeg, WPCStatus *rty_WPC2Status);
extern void NFC_WPC_Mode_Control__dxgm_Init(WPCStatus *rty_WPCStatus);
extern void NFC_WPC_Mode_Control_Funct_appg(Bool rtu_PreProcessIn, GearPosSta rtu_PreProcessIn_hg3k, C_WPCOnOffNvalueSet rtu_PreProcessIn_dwtr, Bool rtu_PreProcessIn_olfo, Bool rtu_PreProcessIn_fnvi,
  WPCStatus *rty_WPCStatus);
extern void NFC_WPC_Mode_Control__ovav_Init(WPCStatus *rty_WPCStatus);
extern void NFC_WPC_Mode_Control_Funct_fw4e(Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_atch, LC_IAUWPCNFCcmd rtu_PreProcessIn_ieah, LC_WPC_NFCDetection rtu_PreProcessIn_c42z, Bool
  rtu_PreProcessIn_pcj3, C_WPCOnOffNvalueSet rtu_PreProcessIn_hk4h, IAU_OwnerPhnRegRVal rtu_PreProcessIn_essy, OwnerPairingAdvertisingReq rtu_PreProcessIn_a10h, OnThePad rtu_PreProcessIn_gfq2,
  OnThePad rtu_PreProcessIn_a0oa, Bool rtu_PreProcessIn_mdz2, C_WPCWarning rtu_PreProcessIn_hjwo, OnThePad rtu_PreProcessIn_crop, Bool rtu_PreProcessIn_fbwq, Bool rtu_PreProcessIn_gi5q, Bool
  rtu_PreProcessIn_jhgz, WPCStatus *rty_WPCStatus);

#endif                                 /* RTW_HEADER_NFC_WPC_Mode_Control_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
