/*
 * File: App_Model_private.h
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

#ifndef RTW_HEADER_App_Model_private_h_
#define RTW_HEADER_App_Model_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "App_Model_types.h"
#include "App_Model.h"
#include "Rte_Type.h"

extern void RWPC_IND_Command_State_Con_Init(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
extern void RWPC_IND_Command_State_Co_Reset(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
extern void RWPC_IND_Command_State_Control_(RWPCIndSyncVal rtu_Input_CAN_RWPCIndSyncVal, RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
extern void IND_Animation_Profile_Deci_Init(C_ProfileIDRValue *rty_CurProfile, DW_IND_Animation_Profile_Deci_T *localDW);
extern void IND_Animation_Profile_Dec_Reset(C_ProfileIDRValue *rty_CurProfile, DW_IND_Animation_Profile_Deci_T *localDW);
extern void IND_Animation_Profile_Decision_(C_ProfileIDRValue rtu_Input_ProfileIDRValue, C_ProfileIDRValue rtu_Input_AVN_ProfileIDRValue, C_ProfileIDRValue *rty_CurProfile,
  DW_IND_Animation_Profile_Deci_T *localDW);
extern void IND_Animation_USM_Setting__Init(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW);
extern void IND_Animation_USM_Setting_Reset(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW);
extern void IND_Animation_USM_Setting_Contr(Bool rtu_b_IndUSMOption, WPCAnimationNvalueSet rtu_Input_CAN_WPCAnimationNvalu, C_USMReset rtu_Input_b_USMReset, C_ProfileIDRValue rtu_CurProfile,
  WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW);
extern void App_Mo_DWPC1_LED_Sync_Indy_Init(Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW);
extern void App_M_DWPC1_LED_Sync_Indy_Reset(Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW);
extern void App_Model_DWPC1_LED_Sync_Indy(Bool rtu_b_BlinkState, Bool rtu_b_CmdLEDSync, BlinkState rtu_BlinkState, Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW);
extern void IND_Animation_Priority_Flo_Init(PreSyncAct *rty_Var_PreSyncAct, DW_IND_Animation_Priority_Flo_T *localDW);
extern void IND_Animation_Priority_Fl_Reset(PreSyncAct *rty_Var_PreSyncAct, DW_IND_Animation_Priority_Flo_T *localDW);
extern void IND_Animation_Priority_Flow_Gra(WPC2PreSyncAct rtu_Var_WPC2PreSyncAct, RWPCPreSyncAct rtu_Var_RWPCPreSyncAct, PreSyncAct *rty_Var_PreSyncAct, DW_IND_Animation_Priority_Flo_T *localDW);
extern void IND_Animation_RWPC_Priorit_Init(RWPCPreSyncAct *rty_Var_RWPCPreSyncAct, DW_IND_Animation_RWPC_Priorit_T *localDW);
extern void IND_Animation_RWPC_Priori_Reset(RWPCPreSyncAct *rty_Var_RWPCPreSyncAct, DW_IND_Animation_RWPC_Priorit_T *localDW);
extern void IND_Animation_RWPC_Priority_Flo(RWPCIndSyncVal rtu_Input_CAN_RWPCIndSyncVal, RWPCPreSyncAct *rty_Var_RWPCPreSyncAct, DW_IND_Animation_RWPC_Priorit_T *localDW);
extern void DoorOpenCloseStateFunction_Init(Bool *rty_b_AstDrSw, Bool *rty_b_DrvDrSw, Bool *rty_b_RLDrSw, Bool *rty_b_RRDrSw, DW_DoorOpenCloseStateFunction_T *localDW);
extern void DoorOpenCloseStateFunctio_Reset(Bool *rty_b_AstDrSw, Bool *rty_b_DrvDrSw, Bool *rty_b_RLDrSw, Bool *rty_b_RRDrSw, DW_DoorOpenCloseStateFunction_T *localDW);
extern void DoorOpenCloseStateFunctionFlowG(LatchTypeOption rtu_Input_Latch_TypeOption_DRV, Bool rtu_Input_b_AstDrSw, Bool rtu_Input_b_DrvDrSw, Bool rtu_Input_b_RLDrSw, Bool rtu_Input_b_RRDrSw, Bool
  rtu_Input_b_AstDrSw_SBCM, Bool rtu_Input_b_DrvDrSw_SBCM, Bool rtu_Input_b_RLDrSw_SBCM, Bool rtu_Input_b_RRDrSw_SBCM, Bool *rty_b_AstDrSw, Bool *rty_b_DrvDrSw, Bool *rty_b_RLDrSw, Bool *rty_b_RRDrSw,
  DW_DoorOpenCloseStateFunction_T *localDW);
extern void App_Mod_FAN_LPConditionJdg_Init(uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW);
extern void App_Mo_FAN_LPConditionJdg_Reset(uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW);
extern void App_Model_FAN_LPConditionJdg(uint16 rtu_FAN_PWM, uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW);
extern void MainControl_LPConditionJdg_Init(uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW);
extern void MainControl_LPConditionJd_Reset(uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW);
extern void App__MainControl_LPConditionJdg(WPCStatus rtu_WPCStatus, uint16 rtu_b_Timer_PhoneReminderCheck, uint16 rtu_b_Timer_PhoneWarningCheck, uint16 rtu_b_Timer_WarningComplete, uint16
  rtu_b_Timer_WarningTypeCheck, Bool rtu_b_PhnLeftChk_Enable, uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW);
extern void Ap_NFC_Mode_LPConditionJdg_Init(uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW);
extern void A_NFC_Mode_LPConditionJdg_Reset(uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW);
extern void App_Mod_NFC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW);
extern void OverCurrent_LPConditionJdg_Init(uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW);
extern void OverCurrent_LPConditionJd_Reset(uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW);
extern void App__OverCurrent_LPConditionJdg(Bool rtu_b_CurrentFault, uint8 rtu_b_Timer_OvrCurr, uint16 rtu_b_Timer_ReOvrCurr, uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T
  *localDW);
extern void OverTempDetect_LPCondition_Init(uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW);
extern void OverTempDetect_LPConditio_Reset(uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW);
extern void A_OverTempDetect_LPConditionJdg(Bool rtu_b_TemperatureFault, uint8 rtu_b_Timer_OverTemp, uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW);
extern void App_M_SMKLF_LPConditionJdg_Init(uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW);
extern void App__SMKLF_LPConditionJdg_Reset(uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW);
extern void App_Model_SMKLF_LPConditionJdg(Bool rtu_b_LFState, uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW);
extern void TempSnsrErrDetect_LPCondit_Init(uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW);
extern void TempSnsrErrDetect_LPCondi_Reset(uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW);
extern void TempSnsrErrDetect_LPConditionJd(Bool rtu_b_TempSensorFault, uint8 rtu_b_Timer_TempSensor_Check, uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW);
extern void App_USM_WPC_LPConditionJdg_Init(uint8 *rty_P_WPC_USM_LPConditionFlag_w, DW_USM_WPC_LPConditionJdg_App_T *localDW);
extern void Ap_USM_WPC_LPConditionJdg_Reset(uint8 *rty_P_WPC_USM_LPConditionFlag_w, DW_USM_WPC_LPConditionJdg_App_T *localDW);
extern void App_Mode_USM_WPC_LPConditionJdg(C_WPCOnOffNvalueSet rtu_m_ProfileGuestWPCUSM_App, C_WPCOnOffNvalueSet rtu_m_ProfileOneWPCUSM_App, C_WPCOnOffNvalueSet rtu_m_ProfileTwoWPCUSM_App, float64
  rtu_m_RWPCUSM_App, C_WPCOnOffNvalueSet rtu_m_ProfileThreeWPCUSM_App, uint8 *rty_P_WPC_USM_LPConditionFlag_w, DW_USM_WPC_LPConditionJdg_App_T *localDW);
extern void Ap_WPC_Mode_LPConditionJdg_Init(uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW);
extern void A_WPC_Mode_LPConditionJdg_Reset(uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW);
extern void App_Mod_WPC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW);
extern void App_Model_Amber_Sync_Indy_Init(Bool *rty_b_SyncAmber, DW_Amber_Sync_Indy_App_Model_T *localDW);
extern void App_Model_Amber_Sync_Indy_Reset(Bool *rty_b_SyncAmber, DW_Amber_Sync_Indy_App_Model_T *localDW);
extern void App_Model_Amber_Sync_Indy(Bool rtu_b_BlinkState, Bool rtu_b_CmdAmberSync, BlinkState rtu_BlinkState, Bool *rty_b_SyncAmber, DW_Amber_Sync_Indy_App_Model_T *localDW);
extern void IND_Animation_WPC2_Priorit_Init(WPC2PreSyncAct *rty_Var_WPC2PreSyncAct, DW_IND_Animation_WPC2_Priorit_T *localDW);
extern void IND_Animation_WPC2_Priori_Reset(WPC2PreSyncAct *rty_Var_WPC2PreSyncAct, DW_IND_Animation_WPC2_Priorit_T *localDW);
extern void IND_Animation_WPC2_Priority_Flo(WPC2IndSyncVal rtu_Input_CAN_WPC2IndSyncVal, WPC2PreSyncAct *rty_Var_WPC2PreSyncAct, DW_IND_Animation_WPC2_Priorit_T *localDW);
extern void App_Model_AppInit_DataRead_Init(void);
extern void App_Model_AppInit_DataRead(boolean rtu_Trigger, const IDT_NvM_STR *rtu_R_NvM_Data);

#endif                                 /* RTW_HEADER_App_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
