/*
 * File: App_Model_private.h
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

#ifndef RTW_HEADER_App_Model_private_h_
#define RTW_HEADER_App_Model_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "App_Model.h"
#include "App_Model_types.h"
#include "Rte_Type.h"

extern void App_Mod_FAN_LPConditionJdg_Init(uint8 *rty_FAN_LPConditionFlag_write);
extern void App_Mo_FAN_LPConditionJdg_Reset(uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW);
extern void App_Model_FAN_LPConditionJdg(uint16 rtu_FAN_PWM, uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW);
extern void MainControl_LPConditionJdg_Init(uint8 *rty_WPCMain_LPConditionFlag_wri);
extern void MainControl_LPConditionJd_Reset(uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW);
extern void App__MainControl_LPConditionJdg(WPCStatus rtu_WPCStatus, uint16 rtu_b_Timer_PhoneReminderCheck, uint16 rtu_b_Timer_PhoneWarningCheck, uint16 rtu_b_Timer_WarningComplete, uint8
  *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW);
extern void Ap_NFC_Mode_LPConditionJdg_Init(uint8 *rty_NFCMode_LPConditionFlag_wri);
extern void A_NFC_Mode_LPConditionJdg_Reset(uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW);
extern void App_Mod_NFC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW);
extern void OverCurrent_LPConditionJdg_Init(uint8 *rty_OverCurrent_LPConditionFlag);
extern void OverCurrent_LPConditionJd_Reset(uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW);
extern void App__OverCurrent_LPConditionJdg(Bool rtu_b_CurrentFault, uint8 rtu_b_Timer_OvrCurr, uint16 rtu_b_Timer_ReOvrCurr, uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T
  *localDW);
extern void OverTempDetect_LPCondition_Init(uint8 *rty_OverTempDetect_LPConditionF);
extern void OverTempDetect_LPConditio_Reset(uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW);
extern void A_OverTempDetect_LPConditionJdg(Bool rtu_b_TemperatureFault, uint8 rtu_b_Timer_OverTemp, uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW);
extern void App_M_SMKLF_LPConditionJdg_Init(uint8 *rty_SMKLF_LPConditionFlag_write);
extern void App__SMKLF_LPConditionJdg_Reset(uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW);
extern void App_Model_SMKLF_LPConditionJdg(Bool rtu_b_LFState, uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW);
extern void TempSnsrErrDetect_LPCondit_Init(uint8 *rty_TempSnsrError_LPConditionFl);
extern void TempSnsrErrDetect_LPCondi_Reset(uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW);
extern void TempSnsrErrDetect_LPConditionJd(Bool rtu_b_TempSensorFault, uint8 rtu_b_Timer_TempSensor_Check, uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW);
extern void Ap_WPC_Mode_LPConditionJdg_Init(uint8 *rty_WPCMode_LPConditionFlag_wri);
extern void A_WPC_Mode_LPConditionJdg_Reset(uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW);
extern void App_Mod_WPC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW);
extern void App_Model_AppInit_DataRead_Init(void);
extern void App_Model_AppInit_DataRead(const IDT_NvM_STR *rtu_R_NvM_Data);

#endif                                 /* RTW_HEADER_App_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
