/*
 * File: App_Model.c
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

#include "App_Model.h"
#include "App_Model_types.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "App_Model_private.h"
#include <string.h>
#include "IndyOutputControl_Function.h"
#include "TemperatureSensorErrorDetect_Function.h"
#include "PreventionSMK_LF_Interference_Function.h"
#include "USMSettingControl_Function.h"
#include "OverCurrentDetecting_Function.h"
#include "OverTemperatureDetecting_Function.h"
#include "WPC_PhoneLeftDetectingControl_Function.h"
#include "WPC_MainControl_Function.h"
#include "FAN_Control_Function.h"
#include "NFC_WPC_Mode_Control_Function.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
#define Ap_IN_RWPCINDCmdState_1stChrgOn ((uint8)2U)
#define Ap_IN_RWPCINDCmdState_2ndChrgOn ((uint8)2U)
#define Ap_IN_RWPCINDCmdState_3rdChrgOn ((uint8)2U)
#define Ap_IN_RWPCINDCmdState_ErrorOn_2 ((uint8)3U)
#define App_IN_RWPCINDCmdState_Charging ((uint8)1U)
#define App_IN_RWPCINDCmdState_ErrorOff ((uint8)1U)
#define App_Mo_IN_RWPCINDCmdState_Error ((uint8)3U)
#define App_Mod_IN_NO_ACTIVE_CHILD_aj0e ((uint8)0U)
#define App_Mode_IN_RWPCINDCmdState_Off ((uint8)4U)
#define App_Model_CALL_EVENT           (-1)
#define App_Model_IN_INDPhaseState_Off ((uint8)1U)
#define App_Model_IN_INDPhaseState_On  ((uint8)2U)
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

/* Named constants for Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
#define A_IN_INDAnimationUSM_NotApplied ((uint8)2U)
#define A_IN_INDAnimationUSM_ProfileOne ((uint8)2U)
#define A_IN_INDAnimationUSM_ProfileTwo ((uint8)3U)
#define App_Mo_IN_INDAnimationUSM_Guest ((uint8)1U)
#define App_Mod_IN_NO_ACTIVE_CHILD_a40j ((uint8)0U)
#define App__IN_INDAnimationUSM_Applied ((uint8)1U)

/* Named constants for Chart: '<S409>/DWPC1_LED_Sync_Indy' */
#define App_Mod_IN_NO_ACTIVE_CHILD_deuo ((uint8)0U)
#define App_Model_IN_SyncTriggerOff    ((uint8)1U)
#define App_Model_IN_SyncTriggerOn     ((uint8)2U)

/* Named constants for Chart: '<S438>/FAN_LPConditionJdg' */
#define App_Mod_IN_NO_ACTIVE_CHILD_n3cd ((uint8)0U)
#define App_Mode_IN_FAN_LPCondition_Off ((uint8)1U)
#define App_Model_IN_FAN_LPCondition_On ((uint8)2U)

/* Named constants for Chart: '<S438>/MainControl_LPConditionJdg' */
#define App_Mod_IN_Main_LPCondition_Off ((uint8)1U)
#define App_Mod_IN_NO_ACTIVE_CHILD_era3 ((uint8)0U)
#define App_Mode_IN_Main_LPCondition_On ((uint8)2U)

/* Named constants for Chart: '<S438>/NFC_Mode_LPConditionJdg' */
#define App_Mod_IN_NO_ACTIVE_CHILD_kt4t ((uint8)0U)
#define App_Mode_IN_NFC_LPCondition_Off ((uint8)1U)
#define App_Model_IN_NFC_LPCondition_On ((uint8)2U)

/* Named constants for Chart: '<S438>/OverCurrent_LPConditionJdg' */
#define A_IN_OverCurrent_LPCondition_On ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_dovo ((uint8)0U)
#define IN_OverCurrent_LPCondition_Off ((uint8)1U)

/* Named constants for Chart: '<S438>/OverTempDetect_LPConditionJdg' */
#define App_Mod_IN_NO_ACTIVE_CHILD_ixot ((uint8)0U)
#define IN_OverTempDetect_LPCondit_kkox ((uint8)2U)
#define IN_OverTempDetect_LPCondition_O ((uint8)1U)

/* Named constants for Chart: '<S438>/SMKLF_LPConditionJdg' */
#define App_Mo_IN_SMKLF_LPCondition_Off ((uint8)1U)
#define App_Mod_IN_NO_ACTIVE_CHILD_g1io ((uint8)0U)
#define App_Mod_IN_SMKLF_LPCondition_On ((uint8)2U)

/* Named constants for Chart: '<S438>/TempSnsrErrDetect_LPConditionJdg' */
#define App_Mod_IN_NO_ACTIVE_CHILD_hoib ((uint8)0U)
#define IN_TempSnsrErrDetect_LPCon_jdsz ((uint8)2U)
#define IN_TempSnsrErrDetect_LPConditio ((uint8)1U)

/* Named constants for Chart: '<S438>/USM_WPC_LPConditionJdg' */
#define App_Mod_IN_NO_ACTIVE_CHILD_jg03 ((uint8)0U)
#define App_Mode_IN_LPConditionHold_Off ((uint8)1U)
#define App_Model_CALL_EVENT_cjwd      (-1)
#define App_Model_IN_LPConditionHold_On ((uint8)2U)
#define App_Model_IN_LPCondition_Off   ((uint8)1U)
#define App_Model_IN_LPCondition_On    ((uint8)2U)
#define event_CancelTimer_LPConditionHo (0)
#define event_StartTimer_LPConditionHol (1)

/* Named constants for Chart: '<S438>/WPC_Mode_LPConditionJdg' */
#define App_Mod_IN_NO_ACTIVE_CHILD_jtms ((uint8)0U)
#define App_Mode_IN_WPC_LPCondition_Off ((uint8)1U)
#define App_Model_IN_WPC_LPCondition_On ((uint8)2U)

/* Named constants for Chart: '<S474>/Amber_Sync_Indy' */
#define App_Mod_IN_NO_ACTIVE_CHILD_eccj ((uint8)0U)
#define App_Mode_IN_SyncTriggerOff_put5 ((uint8)1U)
#define App_Model_IN_SyncTriggerOn_bjcu ((uint8)2U)

/* Named constants for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
#define Ap_event_CancelTimer_INDFadeOut (1)
#define App_IN_WPCINDAnimationError_Off ((uint8)1U)
#define App_IN_WPCINDAnimation_Charging ((uint8)1U)
#define App_M_event_StartTimer_INDLight (5)
#define App_Mo_IN_WPCINDAnimation_Error ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_k1rn ((uint8)0U)
#define App_Mod_IN_WPCINDAnimation_Init ((uint8)3U)
#define App_Model_CALL_EVENT_ee3d      (-1)
#define App_Model_IN_INDFadeIn_Off     ((uint8)1U)
#define App_Model_IN_INDFadeIn_On      ((uint8)2U)
#define App_Model_IN_INDFadeOut_Off    ((uint8)1U)
#define App_Model_IN_INDFadeOut_On     ((uint8)2U)
#define App_Model_IN_INDLight_Off      ((uint8)1U)
#define App_Model_IN_INDLight_On       ((uint8)2U)
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
#define IN_WPCINDAnimationCharging_PreN ((uint8)2U)
#define IN_WPCINDAnimationCharging_PreR ((uint8)3U)
#define IN_WPCINDAnimationCharging_PreW ((uint8)5U)
#define IN_WPCINDAnimationCharging_i0ou ((uint8)4U)
#define IN_WPCINDAnimationCharging_puay ((uint8)6U)
#define IN_WPCINDAnimationError_Pr_fbnk ((uint8)7U)
#define IN_WPCINDAnimationError_Pr_lvrx ((uint8)5U)
#define IN_WPCINDAnimationError_PreNone ((uint8)3U)
#define IN_WPCINDAnimationError_PreRWPC ((uint8)4U)
#define IN_WPCINDAnimationError_PreWPC2 ((uint8)6U)

/* Named constants for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
#define Ap_IN_WPC2INDAnimationError_Off ((uint8)1U)
#define Ap_IN_WPC2INDAnimation_Charging ((uint8)1U)
#define App_IN_WPC2INDAnimationError_On ((uint8)2U)
#define App_M_IN_WPC2INDAnimation_Error ((uint8)2U)
#define App_Mo_IN_WPC2INDAnimation_Init ((uint8)3U)
#define App_Model_IN_INDLight2_Off     ((uint8)1U)
#define App_Model_IN_INDLight2_On      ((uint8)2U)
#define IN_WPC2INDAnimationChargin_anqt ((uint8)1U)
#define IN_WPC2INDAnimationChargin_cxay ((uint8)1U)
#define IN_WPC2INDAnimationChargin_j0nd ((uint8)2U)
#define IN_WPC2INDAnimationChargin_kr45 ((uint8)2U)
#define IN_WPC2INDAnimationChargin_m5iw ((uint8)2U)
#define IN_WPC2INDAnimationChargin_mbhl ((uint8)3U)
#define IN_WPC2INDAnimationChargin_n2ho ((uint8)6U)
#define IN_WPC2INDAnimationChargin_nx4i ((uint8)5U)
#define IN_WPC2INDAnimationChargin_oaxc ((uint8)4U)
#define IN_WPC2INDAnimationCharging_1st ((uint8)1U)
#define IN_WPC2INDAnimationCharging_2nd ((uint8)2U)
#define IN_WPC2INDAnimationCharging_3rd ((uint8)1U)
#define IN_WPC2INDAnimationCharging_Act ((uint8)1U)
#define IN_WPC2INDAnimationCharging_Off ((uint8)3U)
#define IN_WPC2INDAnimationCharging_Pre ((uint8)2U)
#define IN_WPC2INDAnimationError_PreNon ((uint8)3U)
#define IN_WPC2INDAnimationError_PreRWP ((uint8)4U)
#define IN_WPC2INDAnimationError_PreWPC ((uint8)5U)
#define IN_WPCINDAnimationCharging_eq2h ((uint8)4U)
#define IN_WPCINDAnimationError_Pr_amfy ((uint8)6U)
#define IN_WPCINDAnimationError_PreWPC ((uint8)7U)

/* Named constants for Chart: '<S409>/DWPC1_Amber_Sync_Chart' */
#define App_Mode_IN_SyncTriggerOff_ffg4 ((uint8)1U)
#define App_Model_IN_SyncTriggerOn_bnd3 ((uint8)2U)

/* Named constants for Chart: '<S439>/USM_WPC2_LPCondition' */
#define App_IN_LPConditionHold_Off_kvlq ((uint8)1U)
#define App_Mod_IN_LPCondition_Off_gfto ((uint8)1U)
#define App_Mode_IN_LPCondition_On_nvlj ((uint8)2U)
#define App__IN_LPConditionHold_On_lcw3 ((uint8)2U)
#define event_CancelTimer_LPCondit_nxtu (0)
#define event_StartTimer_LPConditi_i0nb (1)

/* Named constants for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
#define Ap_IN_RWPCINDAnimationError_Off ((uint8)1U)
#define Ap_IN_RWPCINDAnimation_Charging ((uint8)1U)
#define App_IN_RWPCINDAnimationError_On ((uint8)2U)
#define App_M_IN_RWPCINDAnimation_Error ((uint8)2U)
#define App_Mo_IN_RWPCINDAnimation_Init ((uint8)3U)
#define IN_RWPCINDAnimationChargin_dxqc ((uint8)2U)
#define IN_RWPCINDAnimationChargin_hbnm ((uint8)3U)
#define IN_RWPCINDAnimationChargin_hln0 ((uint8)1U)
#define IN_RWPCINDAnimationChargin_iux5 ((uint8)1U)
#define IN_RWPCINDAnimationChargin_jfzc ((uint8)5U)
#define IN_RWPCINDAnimationChargin_k15v ((uint8)4U)
#define IN_RWPCINDAnimationChargin_lbn5 ((uint8)6U)
#define IN_RWPCINDAnimationChargin_oe45 ((uint8)2U)
#define IN_RWPCINDAnimationChargin_oo1y ((uint8)2U)
#define IN_RWPCINDAnimationChargin_orxo ((uint8)1U)
#define IN_RWPCINDAnimationCharging_1st ((uint8)1U)
#define IN_RWPCINDAnimationCharging_2nd ((uint8)2U)
#define IN_RWPCINDAnimationCharging_3rd ((uint8)3U)
#define IN_RWPCINDAnimationCharging_Act ((uint8)1U)
#define IN_RWPCINDAnimationCharging_Off ((uint8)4U)
#define IN_RWPCINDAnimationCharging_Pre ((uint8)2U)
#define IN_RWPCINDAnimationError_P_aelk ((uint8)7U)
#define IN_RWPCINDAnimationError_P_gplk ((uint8)6U)
#define IN_RWPCINDAnimationError_PreNon ((uint8)3U)
#define IN_RWPCINDAnimationError_PreRWP ((uint8)4U)
#define IN_RWPCINDAnimationError_PreWPC ((uint8)5U)

/* Named constants for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
#define Ap_IN_WPC2INDCmdState_1stChrgOn ((uint8)2U)
#define Ap_IN_WPC2INDCmdState_2ndChrgOn ((uint8)2U)
#define Ap_IN_WPC2INDCmdState_3rdChrgOn ((uint8)2U)
#define Ap_IN_WPC2INDCmdState_ErrorOn_2 ((uint8)3U)
#define App_IN_WPC2INDCmdState_Charging ((uint8)1U)
#define App_IN_WPC2INDCmdState_ErrorOff ((uint8)1U)
#define App_M_IN_INDPhaseState_Off_bpnu ((uint8)1U)
#define App_Mo_IN_INDPhaseState_On_bakn ((uint8)2U)
#define App_Mo_IN_WPC2INDCmdState_Error ((uint8)3U)
#define App_Mode_IN_WPC2INDCmdState_Off ((uint8)4U)
#define App__IN_WPC2INDCmdState_1stSync ((uint8)1U)
#define App__IN_WPC2INDCmdState_2ndSync ((uint8)2U)
#define App__IN_WPC2INDCmdState_3rdSync ((uint8)3U)
#define App__IN_WPC2INDCmdState_Default ((uint8)2U)
#define App__IN_WPC2INDCmdState_ErrorOn ((uint8)2U)
#define IN_WPC2INDCmdState_1stChrgFadeI ((uint8)1U)
#define IN_WPC2INDCmdState_2ndChrgFadeI ((uint8)1U)
#define IN_WPC2INDCmdState_3rdChrgFadeI ((uint8)1U)
#define IN_WPC2INDCmdState_ChrgFadeOut ((uint8)1U)
#define event_CancelTimer_INDPhase_h0ww (0)
#define event_StartTimer_INDPhaseS_a3lh (1)

/* Named constants for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
#define A_IN_WPCINDCmdState_ChrgFadeOut ((uint8)1U)
#define App_IN_WPCINDCmdState_1stChrgOn ((uint8)2U)
#define App_IN_WPCINDCmdState_2ndChrgOn ((uint8)2U)
#define App_IN_WPCINDCmdState_3rdChrgOn ((uint8)2U)
#define App_IN_WPCINDCmdState_ErrorOn_2 ((uint8)3U)
#define App_M_IN_WPCINDCmdState_1stSync ((uint8)1U)
#define App_M_IN_WPCINDCmdState_2ndSync ((uint8)2U)
#define App_M_IN_WPCINDCmdState_3rdSync ((uint8)3U)
#define App_M_IN_WPCINDCmdState_Default ((uint8)2U)
#define App_M_IN_WPCINDCmdState_ErrorOn ((uint8)2U)
#define App_Mod_IN_WPCIndCmdState_Error ((uint8)3U)
#define App_Model_IN_WPCINDCmdState_Off ((uint8)4U)
#define App__IN_WPCINDCmdState_Charging ((uint8)1U)
#define App__IN_WPCINDCmdState_ErrorOff ((uint8)1U)
#define IN_WPCINDCmdState_1stChrgFadeIn ((uint8)1U)
#define IN_WPCINDCmdState_2ndChrgFadeIn ((uint8)1U)
#define IN_WPCINDCmdState_3rdChrgFadeIn ((uint8)1U)

/* Named constants for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
#define A_IN_RWPCINDCmdState_Error_jh1y ((uint8)3U)
#define App_IN_RWPCINDCmdState_Off_e1rc ((uint8)4U)
#define IN_RWPCINDCmdState_1stChrg_civ2 ((uint8)2U)
#define IN_RWPCINDCmdState_1stChrg_ijou ((uint8)1U)
#define IN_RWPCINDCmdState_1stSync_lk43 ((uint8)1U)
#define IN_RWPCINDCmdState_2ndChrg_dutq ((uint8)2U)
#define IN_RWPCINDCmdState_2ndChrg_mmd3 ((uint8)1U)
#define IN_RWPCINDCmdState_2ndSync_mtfd ((uint8)2U)
#define IN_RWPCINDCmdState_3rdChrg_cla5 ((uint8)2U)
#define IN_RWPCINDCmdState_3rdChrg_heys ((uint8)1U)
#define IN_RWPCINDCmdState_3rdSync_mj1c ((uint8)3U)
#define IN_RWPCINDCmdState_Chargin_lczw ((uint8)1U)
#define IN_RWPCINDCmdState_ChrgFad_auyk ((uint8)1U)
#define IN_RWPCINDCmdState_Default_kpc4 ((uint8)2U)
#define IN_RWPCINDCmdState_ErrorOf_fcr1 ((uint8)1U)
#define IN_RWPCINDCmdState_ErrorOn_ajx4 ((uint8)2U)
#define IN_RWPCINDCmdState_ErrorOn_gzpb ((uint8)3U)

/* Exported block states */
uint16 Par_AutoBrightLevel001;         /* Simulink.Signal object 'Par_AutoBrightLevel001' */
uint16 Par_AutoBrightLevel002;         /* Simulink.Signal object 'Par_AutoBrightLevel002' */
uint16 Par_AutoBrightLevel003;         /* Simulink.Signal object 'Par_AutoBrightLevel003' */
uint16 Par_AutoBrightLevel004;         /* Simulink.Signal object 'Par_AutoBrightLevel004' */
uint16 Par_AutoBrightLevel005;         /* Simulink.Signal object 'Par_AutoBrightLevel005' */
uint16 Par_AutoBrightLevel006;         /* Simulink.Signal object 'Par_AutoBrightLevel006' */
uint16 Par_AutoBrightLevel007;         /* Simulink.Signal object 'Par_AutoBrightLevel007' */
uint16 Par_AutoBrightLevel008;         /* Simulink.Signal object 'Par_AutoBrightLevel008' */
uint16 Par_AutoBrightLevel009;         /* Simulink.Signal object 'Par_AutoBrightLevel009' */
uint16 Par_AutoBrightLevel010;         /* Simulink.Signal object 'Par_AutoBrightLevel010' */
uint16 Par_AutoBrightLevel011;         /* Simulink.Signal object 'Par_AutoBrightLevel011' */
uint16 Par_AutoBrightLevel012;         /* Simulink.Signal object 'Par_AutoBrightLevel012' */
uint16 Par_AutoBrightLevel013;         /* Simulink.Signal object 'Par_AutoBrightLevel013' */
uint16 Par_AutoBrightLevel014;         /* Simulink.Signal object 'Par_AutoBrightLevel014' */
uint16 Par_AutoBrightLevel015;         /* Simulink.Signal object 'Par_AutoBrightLevel015' */
uint16 Par_AutoBrightLevel016;         /* Simulink.Signal object 'Par_AutoBrightLevel016' */
uint16 Par_AutoBrightLevel017;         /* Simulink.Signal object 'Par_AutoBrightLevel017' */
uint16 Par_AutoBrightLevel018;         /* Simulink.Signal object 'Par_AutoBrightLevel018' */
uint16 Par_AutoBrightLevel019;         /* Simulink.Signal object 'Par_AutoBrightLevel019' */
uint16 Par_AutoBrightLevel020;         /* Simulink.Signal object 'Par_AutoBrightLevel020' */
uint16 Par_AutoBrightLevel021;         /* Simulink.Signal object 'Par_AutoBrightLevel021' */
uint16 Par_AutoBrightLevel022;         /* Simulink.Signal object 'Par_AutoBrightLevel022' */
uint16 Par_AutoBrightLevel023;         /* Simulink.Signal object 'Par_AutoBrightLevel023' */
uint16 Par_AutoBrightLevel024;         /* Simulink.Signal object 'Par_AutoBrightLevel024' */
uint16 Par_AutoBrightLevel025;         /* Simulink.Signal object 'Par_AutoBrightLevel025' */
uint16 Par_AutoBrightLevel026;         /* Simulink.Signal object 'Par_AutoBrightLevel026' */
uint16 Par_AutoBrightLevel027;         /* Simulink.Signal object 'Par_AutoBrightLevel027' */
uint16 Par_AutoBrightLevel028;         /* Simulink.Signal object 'Par_AutoBrightLevel028' */
uint16 Par_AutoBrightLevel029;         /* Simulink.Signal object 'Par_AutoBrightLevel029' */
uint16 Par_AutoBrightLevel030;         /* Simulink.Signal object 'Par_AutoBrightLevel030' */
uint16 Par_AutoBrightLevel031;         /* Simulink.Signal object 'Par_AutoBrightLevel031' */
uint16 Par_AutoBrightLevel032;         /* Simulink.Signal object 'Par_AutoBrightLevel032' */
uint16 Par_AutoBrightLevel033;         /* Simulink.Signal object 'Par_AutoBrightLevel033' */
uint16 Par_AutoBrightLevel034;         /* Simulink.Signal object 'Par_AutoBrightLevel034' */
uint16 Par_AutoBrightLevel035;         /* Simulink.Signal object 'Par_AutoBrightLevel035' */
uint16 Par_AutoBrightLevel036;         /* Simulink.Signal object 'Par_AutoBrightLevel036' */
uint16 Par_AutoBrightLevel037;         /* Simulink.Signal object 'Par_AutoBrightLevel037' */
uint16 Par_AutoBrightLevel038;         /* Simulink.Signal object 'Par_AutoBrightLevel038' */
uint16 Par_AutoBrightLevel039;         /* Simulink.Signal object 'Par_AutoBrightLevel039' */
uint16 Par_AutoBrightLevel040;         /* Simulink.Signal object 'Par_AutoBrightLevel040' */
uint16 Par_AutoBrightLevel041;         /* Simulink.Signal object 'Par_AutoBrightLevel041' */
uint16 Par_AutoBrightLevel042;         /* Simulink.Signal object 'Par_AutoBrightLevel042' */
uint16 Par_AutoBrightLevel043;         /* Simulink.Signal object 'Par_AutoBrightLevel043' */
uint16 Par_AutoBrightLevel044;         /* Simulink.Signal object 'Par_AutoBrightLevel044' */
uint16 Par_AutoBrightLevel045;         /* Simulink.Signal object 'Par_AutoBrightLevel045' */
uint16 Par_AutoBrightLevel046;         /* Simulink.Signal object 'Par_AutoBrightLevel046' */
uint16 Par_AutoBrightLevel047;         /* Simulink.Signal object 'Par_AutoBrightLevel047' */
uint16 Par_AutoBrightLevel048;         /* Simulink.Signal object 'Par_AutoBrightLevel048' */
uint16 Par_AutoBrightLevel049;         /* Simulink.Signal object 'Par_AutoBrightLevel049' */
uint16 Par_AutoBrightLevel050;         /* Simulink.Signal object 'Par_AutoBrightLevel050' */
uint16 Par_AutoBrightLevel051;         /* Simulink.Signal object 'Par_AutoBrightLevel051' */
uint16 Par_AutoBrightLevel052;         /* Simulink.Signal object 'Par_AutoBrightLevel052' */
uint16 Par_AutoBrightLevel053;         /* Simulink.Signal object 'Par_AutoBrightLevel053' */
uint16 Par_AutoBrightLevel054;         /* Simulink.Signal object 'Par_AutoBrightLevel054' */
uint16 Par_AutoBrightLevel055;         /* Simulink.Signal object 'Par_AutoBrightLevel055' */
uint16 Par_AutoBrightLevel056;         /* Simulink.Signal object 'Par_AutoBrightLevel056' */
uint16 Par_AutoBrightLevel057;         /* Simulink.Signal object 'Par_AutoBrightLevel057' */
uint16 Par_AutoBrightLevel058;         /* Simulink.Signal object 'Par_AutoBrightLevel058' */
uint16 Par_AutoBrightLevel059;         /* Simulink.Signal object 'Par_AutoBrightLevel059' */
uint16 Par_AutoBrightLevel060;         /* Simulink.Signal object 'Par_AutoBrightLevel060' */
uint16 Par_AutoBrightLevel061;         /* Simulink.Signal object 'Par_AutoBrightLevel061' */
uint16 Par_AutoBrightLevel062;         /* Simulink.Signal object 'Par_AutoBrightLevel062' */
uint16 Par_AutoBrightLevel063;         /* Simulink.Signal object 'Par_AutoBrightLevel063' */
uint16 Par_AutoBrightLevel064;         /* Simulink.Signal object 'Par_AutoBrightLevel064' */
uint16 Par_AutoBrightLevel065;         /* Simulink.Signal object 'Par_AutoBrightLevel065' */
uint16 Par_AutoBrightLevel066;         /* Simulink.Signal object 'Par_AutoBrightLevel066' */
uint16 Par_AutoBrightLevel067;         /* Simulink.Signal object 'Par_AutoBrightLevel067' */
uint16 Par_AutoBrightLevel068;         /* Simulink.Signal object 'Par_AutoBrightLevel068' */
uint16 Par_AutoBrightLevel069;         /* Simulink.Signal object 'Par_AutoBrightLevel069' */
uint16 Par_AutoBrightLevel070;         /* Simulink.Signal object 'Par_AutoBrightLevel070' */
uint16 Par_AutoBrightLevel071;         /* Simulink.Signal object 'Par_AutoBrightLevel071' */
uint16 Par_AutoBrightLevel072;         /* Simulink.Signal object 'Par_AutoBrightLevel072' */
uint16 Par_AutoBrightLevel073;         /* Simulink.Signal object 'Par_AutoBrightLevel073' */
uint16 Par_AutoBrightLevel074;         /* Simulink.Signal object 'Par_AutoBrightLevel074' */
uint16 Par_AutoBrightLevel075;         /* Simulink.Signal object 'Par_AutoBrightLevel075' */
uint16 Par_AutoBrightLevel076;         /* Simulink.Signal object 'Par_AutoBrightLevel076' */
uint16 Par_AutoBrightLevel077;         /* Simulink.Signal object 'Par_AutoBrightLevel077' */
uint16 Par_AutoBrightLevel078;         /* Simulink.Signal object 'Par_AutoBrightLevel078' */
uint16 Par_AutoBrightLevel079;         /* Simulink.Signal object 'Par_AutoBrightLevel079' */
uint16 Par_AutoBrightLevel080;         /* Simulink.Signal object 'Par_AutoBrightLevel080' */
uint16 Par_AutoBrightLevel081;         /* Simulink.Signal object 'Par_AutoBrightLevel081' */
uint16 Par_AutoBrightLevel082;         /* Simulink.Signal object 'Par_AutoBrightLevel082' */
uint16 Par_AutoBrightLevel083;         /* Simulink.Signal object 'Par_AutoBrightLevel083' */
uint16 Par_AutoBrightLevel084;         /* Simulink.Signal object 'Par_AutoBrightLevel084' */
uint16 Par_AutoBrightLevel085;         /* Simulink.Signal object 'Par_AutoBrightLevel085' */
uint16 Par_AutoBrightLevel086;         /* Simulink.Signal object 'Par_AutoBrightLevel086' */
uint16 Par_AutoBrightLevel087;         /* Simulink.Signal object 'Par_AutoBrightLevel087' */
uint16 Par_AutoBrightLevel088;         /* Simulink.Signal object 'Par_AutoBrightLevel088' */
uint16 Par_AutoBrightLevel089;         /* Simulink.Signal object 'Par_AutoBrightLevel089' */
uint16 Par_AutoBrightLevel090;         /* Simulink.Signal object 'Par_AutoBrightLevel090' */
uint16 Par_AutoBrightLevel091;         /* Simulink.Signal object 'Par_AutoBrightLevel091' */
uint16 Par_RheostatBrightLevel00;      /* Simulink.Signal object 'Par_RheostatBrightLevel00' */
uint16 Par_RheostatBrightLevel01;      /* Simulink.Signal object 'Par_RheostatBrightLevel01' */
uint16 Par_RheostatBrightLevel02;      /* Simulink.Signal object 'Par_RheostatBrightLevel02' */
uint16 Par_RheostatBrightLevel03;      /* Simulink.Signal object 'Par_RheostatBrightLevel03' */
uint16 Par_RheostatBrightLevel04;      /* Simulink.Signal object 'Par_RheostatBrightLevel04' */
uint16 Par_RheostatBrightLevel05;      /* Simulink.Signal object 'Par_RheostatBrightLevel05' */
uint16 Par_RheostatBrightLevel06;      /* Simulink.Signal object 'Par_RheostatBrightLevel06' */
uint16 Par_RheostatBrightLevel07;      /* Simulink.Signal object 'Par_RheostatBrightLevel07' */
uint16 Par_RheostatBrightLevel08;      /* Simulink.Signal object 'Par_RheostatBrightLevel08' */
uint16 Par_RheostatBrightLevel09;      /* Simulink.Signal object 'Par_RheostatBrightLevel09' */
uint16 Par_RheostatBrightLevel10;      /* Simulink.Signal object 'Par_RheostatBrightLevel10' */
uint16 Par_RheostatBrightLevel11;      /* Simulink.Signal object 'Par_RheostatBrightLevel11' */
uint16 Par_RheostatBrightLevel12;      /* Simulink.Signal object 'Par_RheostatBrightLevel12' */
uint16 Par_RheostatBrightLevel13;      /* Simulink.Signal object 'Par_RheostatBrightLevel13' */
uint16 Par_RheostatBrightLevel14;      /* Simulink.Signal object 'Par_RheostatBrightLevel14' */
uint16 Par_RheostatBrightLevel15;      /* Simulink.Signal object 'Par_RheostatBrightLevel15' */
uint16 Par_RheostatBrightLevel16;      /* Simulink.Signal object 'Par_RheostatBrightLevel16' */
uint16 Par_RheostatBrightLevel17;      /* Simulink.Signal object 'Par_RheostatBrightLevel17' */
uint16 Par_RheostatBrightLevel18;      /* Simulink.Signal object 'Par_RheostatBrightLevel18' */
uint16 Par_RheostatBrightLevel19;      /* Simulink.Signal object 'Par_RheostatBrightLevel19' */
uint16 Par_RheostatBrightLevel20;      /* Simulink.Signal object 'Par_RheostatBrightLevel20' */
uint16 Par_RheostatBrightLevel21;      /* Simulink.Signal object 'Par_RheostatBrightLevel21' */
uint16 m_AutoBrightLevelSet[91];       /* Simulink.Signal object 'm_AutoBrightLevelSet' */
uint16 m_RheostatBrightLevelSet[22];   /* Simulink.Signal object 'm_RheostatBrightLevelSet' */
FANDutyRatio m_ProfileGuestWPC2FanUSM_App;/* Simulink.Signal object 'm_ProfileGuestWPC2FanUSM_App' */
FANDutyRatio m_ProfileGuestWPCFanUSM_App;/* Simulink.Signal object 'm_ProfileGuestWPCFanUSM_App' */
FANDutyRatio m_ProfileOneWPC2FanUSM_App;/* Simulink.Signal object 'm_ProfileOneWPC2FanUSM_App' */
FANDutyRatio m_ProfileOneWPCFanUSM_App;/* Simulink.Signal object 'm_ProfileOneWPCFanUSM_App' */
FANDutyRatio m_ProfileThreeWPC2FanUSM_App;/* Simulink.Signal object 'm_ProfileThreeWPC2FanUSM_App' */
FANDutyRatio m_ProfileThreeWPCFanUSM_App;/* Simulink.Signal object 'm_ProfileThreeWPCFanUSM_App' */
FANDutyRatio m_ProfileTwoWPC2FanUSM_App;/* Simulink.Signal object 'm_ProfileTwoWPC2FanUSM_App' */
FANDutyRatio m_ProfileTwoWPCFanUSM_App;/* Simulink.Signal object 'm_ProfileTwoWPCFanUSM_App' */
FANDutyRatio m_RWPCFanUSM_App;         /* Simulink.Signal object 'm_RWPCFanUSM_App' */
C_WPCOnOffNvalueSet m_ProfileGuestWPC2USM_App;/* Simulink.Signal object 'm_ProfileGuestWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileGuestWPCUSM_App;/* Simulink.Signal object 'm_ProfileGuestWPCUSM_App' */
C_WPCOnOffNvalueSet m_ProfileOneWPC2USM_App;/* Simulink.Signal object 'm_ProfileOneWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileOneWPCUSM_App;/* Simulink.Signal object 'm_ProfileOneWPCUSM_App' */
C_WPCOnOffNvalueSet m_ProfileThreeWPC2USM_App;/* Simulink.Signal object 'm_ProfileThreeWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileThreeWPCUSM_App;/* Simulink.Signal object 'm_ProfileThreeWPCUSM_App' */
C_WPCOnOffNvalueSet m_ProfileTwoWPC2USM_App;/* Simulink.Signal object 'm_ProfileTwoWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileTwoWPCUSM_App;/* Simulink.Signal object 'm_ProfileTwoWPCUSM_App' */
C_WPCOnOffNvalueSet m_RWPCUSM_App;     /* Simulink.Signal object 'm_RWPCUSM_App' */
WPCIndUSMState m_WPCIndUSMState_Guest; /* Simulink.Signal object 'm_WPCIndUSMState_Guest' */
WPCIndUSMState m_WPCIndUSMState_ProfileOne;/* Simulink.Signal object 'm_WPCIndUSMState_ProfileOne' */
WPCIndUSMState m_WPCIndUSMState_ProfileTwo;/* Simulink.Signal object 'm_WPCIndUSMState_ProfileTwo' */

/* Block signals (default storage) */
B_App_Model_T App_Model_B;

/* Block states (default storage) */
DW_App_Model_T App_Model_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_App_Model_T App_Model_PrevZCX;

/* Real-time model */
static RT_MODEL_App_Model_T App_Model_M_;
RT_MODEL_App_Model_T *const App_Model_M = &App_Model_M_;

/* Forward declaration for local functions */
static void App_Model_INDPhaseState(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_1(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_2(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_3(DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_C(DW_RWPC_IND_Command_State_Con_T *localDW);
static void App_Mo_RWPCINDCmdState_Charging(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW);
static void exit_internal_RWPCINDCmdState_E(DW_RWPC_IND_Command_State_Con_T *localDW);

/* Forward declaration for local functions */
static void App_Model_INDUSMGuest(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW);
static void App_Model_INDUSMProfileOne(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW);
static void App_Model_INDUSMProfileTwo(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW);

/* Forward declaration for local functions */
static void App_Model_LPConditionHold(DW_USM_WPC_LPConditionJdg_App_T *localDW);
static void App_Model_LPConditionTimerCheck(DW_USM_WPC_LPConditionJdg_App_T *localDW);

/* Forward declaration for local functions */
static uint8 safe_cast_to_C_WPCOnOffNvalueSe(uint8 input);
static uint8 App_M_safe_cast_to_FANDutyRatio(uint8 input);
static uint8 App_safe_cast_to_WPCIndUSMState(uint8 input);

/* Forward declaration for local functions */
static void App_Model_INDLight(void);
static void App_Model_INDFadeIn(void);
static void exit_internal_WPCINDAnimationCh(void);
static void enter_internal_WPCINDAnima_asoc(void);
static void exit_internal_WPCINDAnimat_drkg(void);
static void enter_atomic_WPCINDAnimationCha(void);
static void exit_internal_WPCINDAnimat_d4ui(void);
static void App_Model_INDFadeOut(void);
static void enter_internal_WPCINDAnima_bs12(void);
static void exit_internal_WPCINDAnimat_jyb3(void);
static void enter_internal_WPCINDAnima_mdgj(void);
static void App_Model_TypeCont(void);
static void WPCINDAnimationCharging_Active(const PreSyncAct *INT_PreSyncAct_WPC1);
static void enter_internal_WPCINDAnimationC(const WPC2IndSyncVal *INT_WPC2IndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC1);
static void enter_atomic_WPCINDAnimationErr(void);
static void App_Model_INDErrorOnOut(void);
static void App_Model_WPCINDAnimation_Error(const PreSyncAct *INT_PreSyncAct_WPC1);
static void IND_Animation_Sync_Control_Func(const WPC2IndSyncVal *INT_WPC2IndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC1);
static void App_Model_INDLight_idce(void);
static void App_Model_INDFadeIn_dns5(void);
static void exit_internal_WPC2INDAnimationC(void);
static void enter_internal_WPC2INDAnim_dz4n(void);
static void exit_internal_WPC2INDAnima_cw2f(void);
static void enter_atomic_WPC2INDAnimationCh(void);
static void App_Model_INDFadeOut_gkqv(void);
static void exit_internal_WPC2INDAnima_pcyf(void);
static void enter_internal_WPC2INDAnim_amwe(void);
static void App_Model_TypeCont_cidw(void);
static void exit_internal_WPCINDAnimat_mg0m(void);
static void enter_internal_WPC2INDAnim_iqqg(void);
static void WPC2INDAnimationCharging_Active(const PreSyncAct *INT_PreSyncAct_WPC2);
static void enter_internal_WPC2INDAnimation(const C_WPCIndSyncVal *INT_WPCIndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC2);
static void enter_atomic_WPC2INDAnimationEr(void);
static void App_Model_INDErrorOnOut_gjix(void);
static void App_Mode_WPC2INDAnimation_Error(const PreSyncAct *INT_PreSyncAct_WPC2);
static void IND_Animation_Sync_Control_d4de(const C_WPCIndSyncVal *INT_WPCIndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC2);
static void App_Model_LPConditionHold_bgap(void);
static void App__LPConditionTimerCheck_lfzr(void);
static void App_Model_INDPhaseState_oafg(void);
static void exit_internal_WPC2INDCmdSt_imy0(void);
static void exit_internal_WPC2INDCmdSt_ia4u(void);
static void exit_internal_WPC2INDCmdSt_jbx0(void);
static void exit_internal_WPC2INDCmdSt_ovrz(void);
static void A_WPC2INDCmdState_Charging_k4jq(void);
static void exit_internal_WPC2INDCmdSt_arr1(void);
static void App_Model_INDPhaseState_mb0u(void);
static void exit_internal_RWPCINDCmdSt_bh2q(void);
static void exit_internal_RWPCINDCmdSt_hnbs(void);
static void exit_internal_RWPCINDCmdSt_bkxq(void);
static void exit_internal_RWPCINDCmdSt_cozl(void);
static void A_RWPCINDCmdState_Charging_irrl(void);
static void exit_internal_RWPCINDCmdSt_jszz(void);
static void App_Model_INDLight_lnkr(void);
static void App_Model_INDFadeIn_njia(void);
static void exit_internal_WPCINDAnimat_pscz(void);
static void enter_internal_WPCINDAnima_gdyx(void);
static void exit_internal_WPCINDAnimat_nyfq(void);
static void enter_atomic_WPCINDAnimati_gm3x(void);
static void exit_internal_WPCINDAnimat_pktw(void);
static void App_Model_INDFadeOut_ckyy(void);
static void enter_internal_WPCINDAnima_hvfj(void);
static void exit_internal_WPCINDAnimat_n0kq(void);
static void enter_internal_WPCINDAnima_om2u(void);
static void App_Model_TypeCont_aa4v(void);
static void WPCINDAnimationCharging_Ac_ecok(void);
static void enter_internal_WPCINDAnima_ddqo(void);
static void enter_atomic_WPCINDAnimati_aqrs(void);
static void App_Model_INDErrorOnOut_ee43(void);
static void App__WPCINDAnimation_Error_lqd0(void);
static void IND_Animation_Sync_Control_hzm0(void);
static void App_Model_INDPhaseState_jko2(void);
static void exit_internal_WPCINDCmdState_1s(void);
static void exit_internal_WPCINDCmdState_2n(void);
static void exit_internal_WPCINDCmdState_3r(void);
static void exit_internal_WPCINDCmdState_Ch(void);
static void App_Mod_WPCINDCmdState_Charging(void);
static void exit_internal_WPCIndCmdState_Er(void);
static void App_Model_INDPhaseState_pnuz(void);
static void exit_internal_WPC2INDCmdState_1(void);
static void exit_internal_WPC2INDCmdState_2(void);
static void exit_internal_WPC2INDCmdState_3(void);
static void exit_internal_WPC2INDCmdState_C(void);
static void App_Mo_WPC2INDCmdState_Charging(void);
static void exit_internal_WPC2INDCmdState_E(void);
static void App_Model_INDLight_jhwd(void);
static void App_Model_INDFadeIn_kcqh(void);
static void exit_internal_RWPCINDAnimationC(void);
static void enter_internal_RWPCINDAnim_jwkr(void);
static void exit_internal_RWPCINDAnima_a1gb(void);
static void enter_atomic_RWPCINDAnimationCh(void);
static void exit_internal_RWPCINDAnima_aoy1(void);
static void App_Model_INDFadeOut_iwqq(void);
static void enter_internal_RWPCINDAnim_f5rh(void);
static void exit_internal_RWPCINDAnima_mj5o(void);
static void enter_internal_RWPCINDAnim_bbox(void);
static void App_Model_TypeCont_ljmv(void);
static void RWPCINDAnimationCharging_Active(void);
static void enter_internal_RWPCINDAnimation(const C_WPCIndSyncVal *BCAN_RX_C_WPCIndSyncVal);
static void enter_atomic_RWPCINDAnimationEr(void);
static void App_Model_INDErrorOnOut_igbp(void);
static void App_Mode_RWPCINDAnimation_Error(void);
static void IND_Animation_Sync_Control_ftqp(const C_WPCIndSyncVal *BCAN_RX_C_WPCIndSyncVal);
static void App_Model_LPConditionHold_fjxw(void);
static void App__LPConditionTimerCheck_mlkd(void);
static uint8 safe_cast_to_C_WPCOnOffNvalueSe(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for C_WPCOnOffNvalueSet (WPC_On) */
  output = 2U;
  if (input <= 3U) {
    /* Set output value to input value if it is a member of C_WPCOnOffNvalueSet */
    output = input;
  }

  return output;
}

static uint8 App_M_safe_cast_to_FANDutyRatio(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for FANDutyRatio (LowDuty) */
  output = 1U;
  if (input <= 3U) {
    /* Set output value to input value if it is a member of FANDutyRatio */
    output = input;
  }

  return output;
}

static uint8 App_safe_cast_to_WPCIndUSMState(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for WPCIndUSMState (WPCIndUSMState__Default) */
  output = 0U;
  if (input <= 2U) {
    /* Set output value to input value if it is a member of WPCIndUSMState */
    output = input;
  }

  return output;
}

/* System initialize for trigger system: '<Root>/AppInit_DataRead' */
void App_Model_AppInit_DataRead_Init(void)
{
  /* SystemInitialize for Chart: '<S2>/AutoBrightLevel_Read' */
  App_Model_DW.is_active_c7_App_Model = 0U;

  /* SystemInitialize for Chart: '<S2>/RheostatBrightLevel_Read' */
  App_Model_DW.is_active_c1_App_Model = 0U;
  App_Model_PrevZCX.AppInit_DataRead_Trig_ZCE = ZERO_ZCSIG;
}

/* Output and update for trigger system: '<Root>/AppInit_DataRead' */
void App_Model_AppInit_DataRead(boolean rtu_Trigger, const IDT_NvM_STR *rtu_R_NvM_Data)
{
  sint32 i;

  /* Outputs for Triggered SubSystem: '<Root>/AppInit_DataRead' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  if (rtu_Trigger && ((uint32)App_Model_PrevZCX.AppInit_DataRead_Trig_ZCE != POS_ZCSIG)) {
    /* Chart: '<S2>/AutoBrightLevel_Read' */
    if ((uint32)App_Model_DW.is_active_c7_App_Model == 0U) {
      App_Model_DW.is_active_c7_App_Model = 1U;

      /* Outputs for Function Call SubSystem: '<S5>/AutoBrightLevelSet' */
      /* MultiPortSwitch: '<S8>/Index Vector2' */
      /* initialize */
      switch (rtu_R_NvM_Data->LedDutyTableOption) {
       case 0:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/Default_Standard'
         */
        (void)memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl0[0], 91U * sizeof(uint16));
        break;

       case 1:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/MX5_NEN_DL3PE'
         */
        (void)memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl1[0], 91U * sizeof(uint16));
        break;

       case 2:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/ME1'
         */
        (void)memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl2[0], 91U * sizeof(uint16));
        break;

       case 3:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/CL4'
         */
        (void)memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl3[0], 91U * sizeof(uint16));
        break;

       case 4:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/MVa'
         */
        (void)memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl4[0], 91U * sizeof(uint16));
        break;

       default:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/Default_Standard'
         */
        (void)memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl0[0], 91U * sizeof(uint16));
        break;
      }

      /* End of MultiPortSwitch: '<S8>/Index Vector2' */
      /* End of Outputs for SubSystem: '<S5>/AutoBrightLevelSet' */
      /* Assignment from DataMemory to Parameters */
      Par_AutoBrightLevel001 = m_AutoBrightLevelSet[0];
      Par_AutoBrightLevel002 = m_AutoBrightLevelSet[1];
      Par_AutoBrightLevel003 = m_AutoBrightLevelSet[2];
      Par_AutoBrightLevel004 = m_AutoBrightLevelSet[3];
      Par_AutoBrightLevel005 = m_AutoBrightLevelSet[4];
      Par_AutoBrightLevel006 = m_AutoBrightLevelSet[5];
      Par_AutoBrightLevel007 = m_AutoBrightLevelSet[6];
      Par_AutoBrightLevel008 = m_AutoBrightLevelSet[7];
      Par_AutoBrightLevel009 = m_AutoBrightLevelSet[8];
      Par_AutoBrightLevel010 = m_AutoBrightLevelSet[9];
      Par_AutoBrightLevel011 = m_AutoBrightLevelSet[10];
      Par_AutoBrightLevel012 = m_AutoBrightLevelSet[11];
      Par_AutoBrightLevel013 = m_AutoBrightLevelSet[12];
      Par_AutoBrightLevel014 = m_AutoBrightLevelSet[13];
      Par_AutoBrightLevel015 = m_AutoBrightLevelSet[14];
      Par_AutoBrightLevel016 = m_AutoBrightLevelSet[15];
      Par_AutoBrightLevel017 = m_AutoBrightLevelSet[16];
      Par_AutoBrightLevel018 = m_AutoBrightLevelSet[17];
      Par_AutoBrightLevel019 = m_AutoBrightLevelSet[18];
      Par_AutoBrightLevel020 = m_AutoBrightLevelSet[19];
      Par_AutoBrightLevel021 = m_AutoBrightLevelSet[20];
      Par_AutoBrightLevel022 = m_AutoBrightLevelSet[21];
      Par_AutoBrightLevel023 = m_AutoBrightLevelSet[22];
      Par_AutoBrightLevel024 = m_AutoBrightLevelSet[23];
      Par_AutoBrightLevel025 = m_AutoBrightLevelSet[24];
      Par_AutoBrightLevel026 = m_AutoBrightLevelSet[25];
      Par_AutoBrightLevel027 = m_AutoBrightLevelSet[26];
      Par_AutoBrightLevel028 = m_AutoBrightLevelSet[27];
      Par_AutoBrightLevel029 = m_AutoBrightLevelSet[28];
      Par_AutoBrightLevel030 = m_AutoBrightLevelSet[29];
      Par_AutoBrightLevel031 = m_AutoBrightLevelSet[30];
      Par_AutoBrightLevel032 = m_AutoBrightLevelSet[31];
      Par_AutoBrightLevel033 = m_AutoBrightLevelSet[32];
      Par_AutoBrightLevel034 = m_AutoBrightLevelSet[33];
      Par_AutoBrightLevel035 = m_AutoBrightLevelSet[34];
      Par_AutoBrightLevel036 = m_AutoBrightLevelSet[35];
      Par_AutoBrightLevel037 = m_AutoBrightLevelSet[36];
      Par_AutoBrightLevel038 = m_AutoBrightLevelSet[37];
      Par_AutoBrightLevel039 = m_AutoBrightLevelSet[38];
      Par_AutoBrightLevel040 = m_AutoBrightLevelSet[39];
      Par_AutoBrightLevel041 = m_AutoBrightLevelSet[40];
      Par_AutoBrightLevel042 = m_AutoBrightLevelSet[41];
      Par_AutoBrightLevel043 = m_AutoBrightLevelSet[42];
      Par_AutoBrightLevel044 = m_AutoBrightLevelSet[43];
      Par_AutoBrightLevel045 = m_AutoBrightLevelSet[44];
      Par_AutoBrightLevel046 = m_AutoBrightLevelSet[45];
      Par_AutoBrightLevel047 = m_AutoBrightLevelSet[46];
      Par_AutoBrightLevel048 = m_AutoBrightLevelSet[47];
      Par_AutoBrightLevel049 = m_AutoBrightLevelSet[48];
      Par_AutoBrightLevel050 = m_AutoBrightLevelSet[49];
      Par_AutoBrightLevel051 = m_AutoBrightLevelSet[50];
      Par_AutoBrightLevel052 = m_AutoBrightLevelSet[51];
      Par_AutoBrightLevel053 = m_AutoBrightLevelSet[52];
      Par_AutoBrightLevel054 = m_AutoBrightLevelSet[53];
      Par_AutoBrightLevel055 = m_AutoBrightLevelSet[54];
      Par_AutoBrightLevel056 = m_AutoBrightLevelSet[55];
      Par_AutoBrightLevel057 = m_AutoBrightLevelSet[56];
      Par_AutoBrightLevel058 = m_AutoBrightLevelSet[57];
      Par_AutoBrightLevel059 = m_AutoBrightLevelSet[58];
      Par_AutoBrightLevel060 = m_AutoBrightLevelSet[59];
      Par_AutoBrightLevel061 = m_AutoBrightLevelSet[60];
      Par_AutoBrightLevel062 = m_AutoBrightLevelSet[61];
      Par_AutoBrightLevel063 = m_AutoBrightLevelSet[62];
      Par_AutoBrightLevel064 = m_AutoBrightLevelSet[63];
      Par_AutoBrightLevel065 = m_AutoBrightLevelSet[64];
      Par_AutoBrightLevel066 = m_AutoBrightLevelSet[65];
      Par_AutoBrightLevel067 = m_AutoBrightLevelSet[66];
      Par_AutoBrightLevel068 = m_AutoBrightLevelSet[67];
      Par_AutoBrightLevel069 = m_AutoBrightLevelSet[68];
      Par_AutoBrightLevel070 = m_AutoBrightLevelSet[69];
      Par_AutoBrightLevel071 = m_AutoBrightLevelSet[70];
      Par_AutoBrightLevel072 = m_AutoBrightLevelSet[71];
      Par_AutoBrightLevel073 = m_AutoBrightLevelSet[72];
      Par_AutoBrightLevel074 = m_AutoBrightLevelSet[73];
      Par_AutoBrightLevel075 = m_AutoBrightLevelSet[74];
      Par_AutoBrightLevel076 = m_AutoBrightLevelSet[75];
      Par_AutoBrightLevel077 = m_AutoBrightLevelSet[76];
      Par_AutoBrightLevel078 = m_AutoBrightLevelSet[77];
      Par_AutoBrightLevel079 = m_AutoBrightLevelSet[78];
      Par_AutoBrightLevel080 = m_AutoBrightLevelSet[79];
      Par_AutoBrightLevel081 = m_AutoBrightLevelSet[80];
      Par_AutoBrightLevel082 = m_AutoBrightLevelSet[81];
      Par_AutoBrightLevel083 = m_AutoBrightLevelSet[82];
      Par_AutoBrightLevel084 = m_AutoBrightLevelSet[83];
      Par_AutoBrightLevel085 = m_AutoBrightLevelSet[84];
      Par_AutoBrightLevel086 = m_AutoBrightLevelSet[85];
      Par_AutoBrightLevel087 = m_AutoBrightLevelSet[86];
      Par_AutoBrightLevel088 = m_AutoBrightLevelSet[87];
      Par_AutoBrightLevel089 = m_AutoBrightLevelSet[88];
      Par_AutoBrightLevel090 = m_AutoBrightLevelSet[89];
      Par_AutoBrightLevel091 = m_AutoBrightLevelSet[90];
    }

    /* End of Chart: '<S2>/AutoBrightLevel_Read' */

    /* Chart: '<S2>/NvM_Read' */
    /* NvM Initial Value for SingleWPC(WPC/RWPC/DWPC1)
       Device0 WPCOnOffUSM */
    m_ProfileGuestWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileGuestWPCUSM);
    m_ProfileGuestWPCUSM_App = m_ProfileGuestWPC2USM_App;
    m_ProfileOneWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileOneWPCUSM);
    m_ProfileOneWPCUSM_App = m_ProfileOneWPC2USM_App;
    m_ProfileTwoWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileTwoWPCUSM);
    m_ProfileTwoWPCUSM_App = m_ProfileTwoWPC2USM_App;
    m_ProfileThreeWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileThreeWPCUSM);
    m_ProfileThreeWPCUSM_App = m_ProfileThreeWPC2USM_App;
    m_RWPCUSM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_RWPCUSM);

    /* Device0 WPCFANOnOffUSM */
    m_ProfileGuestWPCFanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[0].m_ProfileGuestFanUSM);
    m_ProfileOneWPCFanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[0].m_ProfileOneFanUSM);
    m_ProfileTwoWPCFanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[0].m_ProfileTwoFanUSM);
    m_ProfileThreeWPCFanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[0].m_ProfileThreeFanUSM);
    m_RWPCFanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[0].m_RWPCFanUSM);

    /* WPCIndUSM */
    m_WPCIndUSMState_Guest = (WPCIndUSMState)App_safe_cast_to_WPCIndUSMState(WPCAnimationNvalueSet__Default);
    m_WPCIndUSMState_ProfileOne = m_WPCIndUSMState_Guest;
    m_WPCIndUSMState_ProfileTwo = m_WPCIndUSMState_Guest;

    /* Reserved */
    if (((uint32)rtu_R_NvM_Data->WPC_NAME == DWPC) || ((uint32)rtu_R_NvM_Data->WPC_NAME == WPC2)) {
      /* NONE: 0 / WPC: 1 / WPC2: 2 / RWPC: 3 / DWPC: 4 */
      /* NvM Initial Value for SecondWPC(DWPC2/WPC2)
         Device1 WPCOnOffUSM */
      m_ProfileGuestWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileGuestWPCUSM);
      m_ProfileOneWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileOneWPCUSM);
      m_ProfileTwoWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileTwoWPCUSM);
      m_ProfileThreeWPC2USM_App = (C_WPCOnOffNvalueSet)safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileThreeWPCUSM);

      /* Device1 WPCFANOnOffUSM */
      m_ProfileGuestWPC2FanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[1].m_ProfileGuestFanUSM);
      m_ProfileOneWPC2FanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[1].m_ProfileOneFanUSM);
      m_ProfileTwoWPC2FanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[1].m_ProfileTwoFanUSM);
      m_ProfileThreeWPC2FanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[1].m_ProfileThreeFanUSM);
    } else {
      /* NvM Initial Value for Dummy. 실수입력+오동작 방지를 위해 Device0값 주입.
         Device1 WPCOnOffUSM */
      /* Device1 WPCFANOnOffUSM */
      m_ProfileGuestWPC2FanUSM_App = m_ProfileGuestWPCFanUSM_App;
      m_ProfileOneWPC2FanUSM_App = m_ProfileOneWPCFanUSM_App;
      m_ProfileTwoWPC2FanUSM_App = m_ProfileTwoWPCFanUSM_App;
      m_ProfileThreeWPC2FanUSM_App = (FANDutyRatio)App_M_safe_cast_to_FANDutyRatio(rtu_R_NvM_Data->Device[0].m_ProfileThreeFanUSM);
    }

    /* End of Chart: '<S2>/NvM_Read' */

    /* Chart: '<S2>/RheostatBrightLevel_Read' */
    if ((uint32)App_Model_DW.is_active_c1_App_Model == 0U) {
      App_Model_DW.is_active_c1_App_Model = 1U;

      /* Outputs for Function Call SubSystem: '<S7>/RheostatBrightLevelSet' */
      /* MultiPortSwitch: '<S9>/Index Vector2' */
      /* initialize */
      /* CAR_TYPE = 0;%temp */
      switch (rtu_R_NvM_Data->LedDutyTableOption) {
       case 0:
        /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
         *  Constant: '<S9>/Default_Standard'
         */
        for (i = 0; i < 22; i++) {
          m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl0[i];
        }
        break;

       case 1:
        /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
         *  Constant: '<S9>/Reserved1'
         */
        for (i = 0; i < 22; i++) {
          m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl1[i];
        }
        break;

       case 2:
        /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
         *  Constant: '<S9>/Reserved2'
         */
        for (i = 0; i < 22; i++) {
          m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl2[i];
        }
        break;

       case 3:
        /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
         *  Constant: '<S9>/Default_Standard'
         */
        for (i = 0; i < 22; i++) {
          m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl0[i];
        }
        break;

       case 4:
        /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
         *  Constant: '<S9>/Default_Standard'
         */
        for (i = 0; i < 22; i++) {
          m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl0[i];
        }
        break;

       default:
        /* MultiPortSwitch: '<S9>/Index Vector2' incorporates:
         *  Constant: '<S9>/Default_Standard'
         */
        for (i = 0; i < 22; i++) {
          m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl0[i];
        }
        break;
      }

      /* End of MultiPortSwitch: '<S9>/Index Vector2' */
      /* End of Outputs for SubSystem: '<S7>/RheostatBrightLevelSet' */
      /* Assignment from DataMemory to Parameters */
      Par_RheostatBrightLevel00 = m_RheostatBrightLevelSet[0];
      Par_RheostatBrightLevel01 = m_RheostatBrightLevelSet[1];
      Par_RheostatBrightLevel02 = m_RheostatBrightLevelSet[2];
      Par_RheostatBrightLevel03 = m_RheostatBrightLevelSet[3];
      Par_RheostatBrightLevel04 = m_RheostatBrightLevelSet[4];
      Par_RheostatBrightLevel05 = m_RheostatBrightLevelSet[5];
      Par_RheostatBrightLevel06 = m_RheostatBrightLevelSet[6];
      Par_RheostatBrightLevel07 = m_RheostatBrightLevelSet[7];
      Par_RheostatBrightLevel08 = m_RheostatBrightLevelSet[8];
      Par_RheostatBrightLevel09 = m_RheostatBrightLevelSet[9];
      Par_RheostatBrightLevel10 = m_RheostatBrightLevelSet[10];
      Par_RheostatBrightLevel11 = m_RheostatBrightLevelSet[11];
      Par_RheostatBrightLevel12 = m_RheostatBrightLevelSet[12];
      Par_RheostatBrightLevel13 = m_RheostatBrightLevelSet[13];
      Par_RheostatBrightLevel14 = m_RheostatBrightLevelSet[14];
      Par_RheostatBrightLevel15 = m_RheostatBrightLevelSet[15];
      Par_RheostatBrightLevel16 = m_RheostatBrightLevelSet[16];
      Par_RheostatBrightLevel17 = m_RheostatBrightLevelSet[17];
      Par_RheostatBrightLevel18 = m_RheostatBrightLevelSet[18];
      Par_RheostatBrightLevel19 = m_RheostatBrightLevelSet[19];
      Par_RheostatBrightLevel20 = m_RheostatBrightLevelSet[20];
      Par_RheostatBrightLevel21 = m_RheostatBrightLevelSet[21];
    }

    /* End of Chart: '<S2>/RheostatBrightLevel_Read' */
  }

  App_Model_PrevZCX.AppInit_DataRead_Trig_ZCE = rtu_Trigger ? ((ZCSigState)1) : ((ZCSigState)0);

  /* End of Outputs for SubSystem: '<Root>/AppInit_DataRead' */
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Model_INDPhaseState(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_INDPhaseState) {
   case App_Model_IN_INDPhaseState_Off:
    if (localDW->sfEvent == (sint32)event_StartTimer_INDPhaseState) {
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
          if ((localDW->Timer_INDPhaseState + 1U) < localDW->Timer_INDPhaseState) {
            qY = MAX_uint32_T;
          }

          localDW->Timer_INDPhaseState = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_1(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_1stSync) {
   case IN_RWPCINDCmdState_1stChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   case Ap_IN_RWPCINDCmdState_1stChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_2(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_2ndSync) {
   case IN_RWPCINDCmdState_2ndChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   case Ap_IN_RWPCINDCmdState_2ndChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_3(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_3rdSync) {
   case IN_RWPCINDCmdState_3rdChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   case Ap_IN_RWPCINDCmdState_3rdChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_C(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_Charging) {
   case App__IN_RWPCINDCmdState_1stSync:
    exit_internal_RWPCINDCmdState_1(localDW);
    localDW->is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    break;

   case App__IN_RWPCINDCmdState_2ndSync:
    exit_internal_RWPCINDCmdState_2(localDW);
    localDW->is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    break;

   case App__IN_RWPCINDCmdState_3rdSync:
    exit_internal_RWPCINDCmdState_3(localDW);
    localDW->is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    break;

   case App_Mode_IN_RWPCINDCmdState_Off:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
      localDW->is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Mo_RWPCINDCmdState_Charging(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  /* 1 */
  if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndCmdState__Default)) {
    exit_internal_RWPCINDCmdState_C(localDW);
    localDW->is_RWPC_IND_Command_State_Contr = App__IN_RWPCINDCmdState_Default;
    *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;

    /* 1 */
  } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
    sint32 h_previousEvent;
    exit_internal_RWPCINDCmdState_C(localDW);
    localDW->is_RWPC_IND_Command_State_Contr = App_Mo_IN_RWPCINDCmdState_Error;

    /* 1 */
    localDW->is_RWPCINDCmdState_Error = App__IN_RWPCINDCmdState_ErrorOn;
    h_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
    if ((uint32)localDW->is_active_INDPhaseState != 0U) {
      App_Model_INDPhaseState(localDW);
    }

    localDW->sfEvent = h_previousEvent;
    *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
  } else {
    switch (localDW->is_RWPCINDCmdState_Charging) {
     case App__IN_RWPCINDCmdState_1stSync:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_1(localDW);
          localDW->is_RWPCINDCmdState_Charging = App_Mode_IN_RWPCINDCmdState_Off;

          /* 1 */
          localDW->is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFadeOut;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_1(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_2ndSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
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
              if (localDW->Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = localDW->sfEvent;
                localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_1stSync = Ap_IN_RWPCINDCmdState_1stChrgOn;
                localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
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

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App__IN_RWPCINDCmdState_2ndSync:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_2(localDW);
          localDW->is_RWPCINDCmdState_Charging = App_Mode_IN_RWPCINDCmdState_Off;

          /* 1 */
          localDW->is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFadeOut;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_2(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_3rdSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_3rdSync = IN_RWPCINDCmdState_3rdChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_2(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_1stSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
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
              if (localDW->Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = localDW->sfEvent;
                localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_2ndSync = Ap_IN_RWPCINDCmdState_2ndChrgOn;
                localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
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

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App__IN_RWPCINDCmdState_3rdSync:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_3(localDW);
          localDW->is_RWPCINDCmdState_Charging = App_Mode_IN_RWPCINDCmdState_Off;

          /* 1 */
          localDW->is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFadeOut;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 2 230113 for UnexpectedSync */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_3(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_2ndSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdState_3(localDW);
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_1stSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrgFadeI;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
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
              if (localDW->Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = localDW->sfEvent;
                localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_3rdSync = Ap_IN_RWPCINDCmdState_3rdChrgOn;
                localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
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

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_Mode_IN_RWPCINDCmdState_Off:
      {
        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          h_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_1stSync;

          /* 1 */
          localDW->is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrgFadeI;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = h_previousEvent;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else if ((uint32)localDW->is_RWPCINDCmdState_Off == IN_RWPCINDCmdState_ChrgFadeOut) {
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;
        } else {
          /* no actions */
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdState_E(DW_RWPC_IND_Command_State_Con_T *localDW)
{
  switch (localDW->is_RWPCINDCmdState_Error) {
   case App_IN_RWPCINDCmdState_ErrorOff:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   case App__IN_RWPCINDCmdState_ErrorOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
      if ((uint32)localDW->is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState(localDW);
      }

      localDW->sfEvent = b_previousEvent;
      localDW->is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    }
    break;

   default:
    localDW->is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
    break;
  }
}

/*
 * System initialize for atomic system:
 *    '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart'
 *    '<S229>/RWPC_IND_Command_State_Control_Function_State_Chart'
 */
void RWPC_IND_Command_State_Con_Init(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT;
  localDW->is_active_INDPhaseState = 0U;
  localDW->is_INDPhaseState = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_active_RWPC_IND_Command_Stat = 0U;
  localDW->is_RWPC_IND_Command_State_Contr = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_active_c198_WPC_IND_Animatio = 0U;
  localDW->Timer_INDPhaseState = 0U;
  *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;
  localDW->Input_CAN_RWPCIndSyncVal_prev = RWPCIndSyncVal__Default;
  localDW->Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;
}

/*
 * System reset for atomic system:
 *    '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart'
 *    '<S229>/RWPC_IND_Command_State_Control_Function_State_Chart'
 */
void RWPC_IND_Command_State_Co_Reset(RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT;
  localDW->is_active_INDPhaseState = 0U;
  localDW->is_INDPhaseState = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_active_RWPC_IND_Command_Stat = 0U;
  localDW->is_RWPC_IND_Command_State_Contr = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_aj0e;
  localDW->is_active_c198_WPC_IND_Animatio = 0U;
  localDW->Timer_INDPhaseState = 0U;
  *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;
  localDW->Input_CAN_RWPCIndSyncVal_prev = RWPCIndSyncVal__Default;
  localDW->Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;
}

/*
 * Output and update for atomic system:
 *    '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart'
 *    '<S229>/RWPC_IND_Command_State_Control_Function_State_Chart'
 */
void RWPC_IND_Command_State_Control_(RWPCIndSyncVal rtu_Input_CAN_RWPCIndSyncVal, RWPCIndCmdState *rty_Var_RWPCIndCmdState, DW_RWPC_IND_Command_State_Con_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT;
  localDW->Input_CAN_RWPCIndSyncVal_prev = localDW->Input_CAN_RWPCIndSyncVal_start;
  localDW->Input_CAN_RWPCIndSyncVal_start = rtu_Input_CAN_RWPCIndSyncVal;

  /* Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
  if ((uint32)localDW->is_active_c198_WPC_IND_Animatio == 0U) {
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
    if ((uint32)localDW->is_active_INDPhaseState != 0U) {
      App_Model_INDPhaseState(localDW);
    }

    if ((uint32)localDW->is_active_RWPC_IND_Command_Stat != 0U) {
      switch (localDW->is_RWPC_IND_Command_State_Contr) {
       case App_IN_RWPCINDCmdState_Charging:
        App_Mo_RWPCINDCmdState_Charging(rty_Var_RWPCIndCmdState, localDW);
        break;

       case App__IN_RWPCINDCmdState_Default:
        *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;

        /* 1 */
        if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
          localDW->is_RWPC_IND_Command_State_Contr = App_IN_RWPCINDCmdState_Charging;
          localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_3rdSync;
          localDW->is_RWPCINDCmdState_3rdSync = Ap_IN_RWPCINDCmdState_3rdChrgOn;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = -1;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;

          /* 1 */
        } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
          localDW->is_RWPC_IND_Command_State_Contr = App_Mo_IN_RWPCINDCmdState_Error;

          /* 1 */
          localDW->is_RWPCINDCmdState_Error = App__IN_RWPCINDCmdState_ErrorOn;
          localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
          if ((uint32)localDW->is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState(localDW);
          }

          localDW->sfEvent = -1;
          *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
        } else {
          /* no actions */
        }
        break;

       case App_Mo_IN_RWPCINDCmdState_Error:
        {
          /* 1 */
          if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndCmdState__Default)) {
            exit_internal_RWPCINDCmdState_E(localDW);
            localDW->is_RWPC_IND_Command_State_Contr = App__IN_RWPCINDCmdState_Default;
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__Default;

            /* 2 230113 for ReCharge */
          } else if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
            sint32 c_previousEvent;
            exit_internal_RWPCINDCmdState_E(localDW);
            localDW->is_RWPC_IND_Command_State_Contr = App_IN_RWPCINDCmdState_Charging;
            localDW->is_RWPCINDCmdState_Charging = App__IN_RWPCINDCmdState_3rdSync;
            localDW->is_RWPCINDCmdState_3rdSync = Ap_IN_RWPCINDCmdState_3rdChrgOn;
            c_previousEvent = localDW->sfEvent;
            localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
            if ((uint32)localDW->is_active_INDPhaseState != 0U) {
              App_Model_INDPhaseState(localDW);
            }

            localDW->sfEvent = c_previousEvent;
            *rty_Var_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
          } else {
            switch (localDW->is_RWPCINDCmdState_Error) {
             case App_IN_RWPCINDCmdState_ErrorOff:
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;

              /* 1. */
              if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
                localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_Error = App__IN_RWPCINDCmdState_ErrorOn;
                localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
              }
              break;

             case App__IN_RWPCINDCmdState_ErrorOn:
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;

              /* 1. */
              if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOff)) {
                localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->is_RWPCINDCmdState_Error = App_IN_RWPCINDCmdState_ErrorOff;
                localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
              } else if (localDW->Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                localDW->sfEvent = (sint32)event_CancelTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_RWPCINDCmdState_Error = Ap_IN_RWPCINDCmdState_ErrorOn_2;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
              } else {
                /* no actions */
              }
              break;

             case Ap_IN_RWPCINDCmdState_ErrorOn_2:
              *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
              if ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOff)) {
                localDW->is_RWPCINDCmdState_Error = App_IN_RWPCINDCmdState_ErrorOff;
                localDW->sfEvent = (sint32)event_StartTimer_INDPhaseState;
                if ((uint32)localDW->is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState(localDW);
                }

                localDW->sfEvent = -1;
                *rty_Var_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }
        break;

       default:
        /* no actions */
        break;
      }
    }
  }

  /* End of Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
}

/*
 * System initialize for atomic system:
 *    '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph'
 *    '<S661>/IND_Animation_Profile_Decision_Function_Flow_Graph'
 */
void IND_Animation_Profile_Deci_Init(C_ProfileIDRValue *rty_CurProfile, DW_IND_Animation_Profile_Deci_T *localDW)
{
  localDW->is_active_c147_WPC_IND_Animatio = 0U;
  *rty_CurProfile = ProfileC_ProfileIDRValueDefault;
}

/*
 * System reset for atomic system:
 *    '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph'
 *    '<S661>/IND_Animation_Profile_Decision_Function_Flow_Graph'
 */
void IND_Animation_Profile_Dec_Reset(C_ProfileIDRValue *rty_CurProfile, DW_IND_Animation_Profile_Deci_T *localDW)
{
  localDW->is_active_c147_WPC_IND_Animatio = 0U;
  *rty_CurProfile = ProfileC_ProfileIDRValueDefault;
}

/*
 * Output and update for atomic system:
 *    '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph'
 *    '<S661>/IND_Animation_Profile_Decision_Function_Flow_Graph'
 */
void IND_Animation_Profile_Decision_(C_ProfileIDRValue rtu_Input_ProfileIDRValue, C_ProfileIDRValue rtu_Input_AVN_ProfileIDRValue, C_ProfileIDRValue *rty_CurProfile, DW_IND_Animation_Profile_Deci_T
  *localDW)
{
  /* Chart: '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
  if ((uint32)localDW->is_active_c147_WPC_IND_Animatio == 0U) {
    localDW->is_active_c147_WPC_IND_Animatio = 1U;
    *rty_CurProfile = Guest;

    /* 1 */
    switch (rtu_Input_ProfileIDRValue) {
     case Profile1:
      *rty_CurProfile = Profile1;
      break;

     case Profile2:
      /* 1 */
      *rty_CurProfile = Profile2;
      break;

     case Guest:
      /* 1 */
      *rty_CurProfile = Guest;
      break;

     default:
      /* 1 */
      switch (rtu_Input_AVN_ProfileIDRValue) {
       case Profile1:
        *rty_CurProfile = Profile1;
        break;

       case Profile2:
        /* 1 */
        *rty_CurProfile = Profile2;
        break;

       case Guest:
        /* 1 */
        *rty_CurProfile = Guest;
        break;

       default:
        /* no actions */
        break;
      }
      break;
    }
  } else {
    /* 1 */
    switch (rtu_Input_ProfileIDRValue) {
     case Profile1:
      *rty_CurProfile = Profile1;
      break;

     case Profile2:
      /* 1 */
      *rty_CurProfile = Profile2;
      break;

     case Guest:
      /* 1 */
      *rty_CurProfile = Guest;
      break;

     default:
      /* 1 */
      switch (rtu_Input_AVN_ProfileIDRValue) {
       case Profile1:
        *rty_CurProfile = Profile1;
        break;

       case Profile2:
        /* 1 */
        *rty_CurProfile = Profile2;
        break;

       case Guest:
        /* 1 */
        *rty_CurProfile = Guest;
        break;

       default:
        /* no actions */
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
}

/* Function for Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
static void App_Model_INDUSMGuest(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW)
{
  /* 1 */
  if ((localDW->Input_CAN_WPCAnimationNvalueSet != localDW->Input_CAN_WPCAnimationNval_nwem) && ((uint32)localDW->Input_CAN_WPCAnimationNval_nwem == WPCAnimationNvalueSet__Type1)) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type1;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type1;

    /* 1 */
  } else if (((localDW->Input_CAN_WPCAnimationNvalueSet != localDW->Input_CAN_WPCAnimationNval_nwem) && ((uint32)localDW->Input_CAN_WPCAnimationNval_nwem == WPCAnimationNvalueSet__Type2)) ||
             ((localDW->Input_b_USMReset_prev != localDW->Input_b_USMReset_start) && ((uint32)localDW->Input_b_USMReset_start == On))) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type2;
  } else if (((uint32)m_WPCIndUSMState_Guest == WPCIndUSMState__Type2) || ((uint32)m_WPCIndUSMState_Guest == WPCIndUSMState__Default)) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
  } else if ((uint32)m_WPCIndUSMState_Guest == WPCIndUSMState__Type1) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type1;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
  } else {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type2;

    /* 초기값 Type2로 설정. */
  }
}

/* Function for Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
static void App_Model_INDUSMProfileOne(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW)
{
  /* 1 */
  if ((localDW->Input_CAN_WPCAnimationNvalueSet != localDW->Input_CAN_WPCAnimationNval_nwem) && ((uint32)localDW->Input_CAN_WPCAnimationNval_nwem == WPCAnimationNvalueSet__Type1)) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type1;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type1;

    /* 1 */
  } else if (((localDW->Input_CAN_WPCAnimationNvalueSet != localDW->Input_CAN_WPCAnimationNval_nwem) && ((uint32)localDW->Input_CAN_WPCAnimationNval_nwem == WPCAnimationNvalueSet__Type2)) ||
             ((localDW->Input_b_USMReset_prev != localDW->Input_b_USMReset_start) && ((uint32)localDW->Input_b_USMReset_start == On))) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type2;
  } else if (((uint32)m_WPCIndUSMState_ProfileOne == WPCIndUSMState__Type2) || ((uint32)m_WPCIndUSMState_ProfileOne == WPCIndUSMState__Default)) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
  } else if ((uint32)m_WPCIndUSMState_ProfileOne == WPCIndUSMState__Type1) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type1;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
  } else {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type2;

    /* 초기값 Type2로 설정. */
  }
}

/* Function for Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
static void App_Model_INDUSMProfileTwo(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW)
{
  /* 1 */
  if ((localDW->Input_CAN_WPCAnimationNvalueSet != localDW->Input_CAN_WPCAnimationNval_nwem) && ((uint32)localDW->Input_CAN_WPCAnimationNval_nwem == WPCAnimationNvalueSet__Type1)) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type1;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type1;

    /* 1 */
  } else if (((localDW->Input_CAN_WPCAnimationNvalueSet != localDW->Input_CAN_WPCAnimationNval_nwem) && ((uint32)localDW->Input_CAN_WPCAnimationNval_nwem == WPCAnimationNvalueSet__Type2)) ||
             ((localDW->Input_b_USMReset_prev != localDW->Input_b_USMReset_start) && ((uint32)localDW->Input_b_USMReset_start == On))) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type2;
  } else if (((uint32)m_WPCIndUSMState_ProfileTwo == WPCIndUSMState__Type2) || ((uint32)m_WPCIndUSMState_ProfileTwo == WPCIndUSMState__Default)) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
  } else if ((uint32)m_WPCIndUSMState_ProfileTwo == WPCIndUSMState__Type1) {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type1;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
  } else {
    *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2;
    *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type2;
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type2;

    /* 초기값 Type2로 설정. */
  }
}

/*
 * System initialize for atomic system:
 *    '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart'
 *    '<S661>/IND_Animation_USM_Setting_Control_Function_State_Chart'
 */
void IND_Animation_USM_Setting__Init(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW)
{
  localDW->is_IND_Animation_USM_Setting_Co = App_Mod_IN_NO_ACTIVE_CHILD_a40j;
  localDW->is_INDAnimationUSM_Applied = App_Mod_IN_NO_ACTIVE_CHILD_a40j;
  localDW->is_active_c135_WPC_IND_Animatio = 0U;
  *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Default;
  *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Default;
  localDW->Input_CAN_WPCAnimationNvalueSet = WPCAnimationNvalueSet__Type1;
  localDW->Input_CAN_WPCAnimationNval_nwem = WPCAnimationNvalueSet__Type1;
  localDW->Input_b_USMReset_prev = USMDefault;
  localDW->Input_b_USMReset_start = USMDefault;
}

/*
 * System reset for atomic system:
 *    '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart'
 *    '<S661>/IND_Animation_USM_Setting_Control_Function_State_Chart'
 */
void IND_Animation_USM_Setting_Reset(WPCIndUSMState *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW)
{
  localDW->is_IND_Animation_USM_Setting_Co = App_Mod_IN_NO_ACTIVE_CHILD_a40j;
  localDW->is_INDAnimationUSM_Applied = App_Mod_IN_NO_ACTIVE_CHILD_a40j;
  localDW->is_active_c135_WPC_IND_Animatio = 0U;
  *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Default;
  *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Default;
  localDW->Input_CAN_WPCAnimationNvalueSet = WPCAnimationNvalueSet__Type1;
  localDW->Input_CAN_WPCAnimationNval_nwem = WPCAnimationNvalueSet__Type1;
  localDW->Input_b_USMReset_prev = USMDefault;
  localDW->Input_b_USMReset_start = USMDefault;
}

/*
 * Output and update for atomic system:
 *    '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart'
 *    '<S661>/IND_Animation_USM_Setting_Control_Function_State_Chart'
 */
void IND_Animation_USM_Setting_Contr(Bool rtu_b_IndUSMOption, WPCAnimationNvalueSet rtu_Input_CAN_WPCAnimationNvalu, C_USMReset rtu_Input_b_USMReset, C_ProfileIDRValue rtu_CurProfile, WPCIndUSMState
  *rty_Output_CAN_WPCIndUSMState, WPCIndUSMState *rty_Output_INT_WPCIndUSMState, DW_IND_Animation_USM_Setting__T *localDW)
{
  localDW->Input_CAN_WPCAnimationNvalueSet = localDW->Input_CAN_WPCAnimationNval_nwem;
  localDW->Input_CAN_WPCAnimationNval_nwem = rtu_Input_CAN_WPCAnimationNvalu;
  localDW->Input_b_USMReset_prev = localDW->Input_b_USMReset_start;
  localDW->Input_b_USMReset_start = rtu_Input_b_USMReset;

  /* Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
  if ((uint32)localDW->is_active_c135_WPC_IND_Animatio == 0U) {
    localDW->Input_CAN_WPCAnimationNvalueSet = rtu_Input_CAN_WPCAnimationNvalu;
    localDW->Input_b_USMReset_prev = rtu_Input_b_USMReset;
    localDW->is_active_c135_WPC_IND_Animatio = 1U;
    if ((uint32)rtu_b_IndUSMOption == Off) {
      localDW->is_IND_Animation_USM_Setting_Co = A_IN_INDAnimationUSM_NotApplied;
      *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Default;
      *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
    } else {
      /* 2
         b_IndUSMOption == On */
      localDW->is_IND_Animation_USM_Setting_Co = App__IN_INDAnimationUSM_Applied;

      /* Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리
         Output_INT_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리 */
      /* 1 */
      switch (rtu_CurProfile) {
       case Profile1:
        localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
        App_Model_INDUSMProfileOne(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
        break;

       case Profile2:
        /* 2 */
        localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
        App_Model_INDUSMProfileTwo(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
        break;

       default:
        localDW->is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
        App_Model_INDUSMGuest(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
        break;
      }
    }
  } else if ((uint32)localDW->is_IND_Animation_USM_Setting_Co == App__IN_INDAnimationUSM_Applied) {
    if ((uint32)rtu_b_IndUSMOption == Off) {
      localDW->is_INDAnimationUSM_Applied = App_Mod_IN_NO_ACTIVE_CHILD_a40j;
      localDW->is_IND_Animation_USM_Setting_Co = A_IN_INDAnimationUSM_NotApplied;
      *rty_Output_CAN_WPCIndUSMState = WPCIndUSMState__Default;
      *rty_Output_INT_WPCIndUSMState = WPCIndUSMState__Type1;
    } else {
      switch (localDW->is_INDAnimationUSM_Applied) {
       case App_Mo_IN_INDAnimationUSM_Guest:
        /* 1 */
        switch (rtu_CurProfile) {
         case Profile1:
          localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
          App_Model_INDUSMProfileOne(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;

         case Profile2:
          /* 2 */
          localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
          App_Model_INDUSMProfileTwo(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;

         default:
          App_Model_INDUSMGuest(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;
        }
        break;

       case A_IN_INDAnimationUSM_ProfileOne:
        /* 1 */
        switch (rtu_CurProfile) {
         case Profile2:
          localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
          App_Model_INDUSMProfileTwo(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;

         case Guest:
          /* 2 */
          localDW->is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
          App_Model_INDUSMGuest(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;

         default:
          App_Model_INDUSMProfileOne(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;
        }
        break;

       default:
        /* case IN_INDAnimationUSM_ProfileTwo: */
        /* 1 */
        switch (rtu_CurProfile) {
         case Profile1:
          localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
          App_Model_INDUSMProfileOne(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;

         case Guest:
          /* 2 */
          localDW->is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
          App_Model_INDUSMGuest(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;

         default:
          App_Model_INDUSMProfileTwo(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
          break;
        }
        break;
      }
    }

    /* case IN_INDAnimationUSM_NotApplied: */
  } else if ((uint32)rtu_b_IndUSMOption == On) {
    localDW->is_IND_Animation_USM_Setting_Co = App__IN_INDAnimationUSM_Applied;

    /* Output_CAN_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리
       Output_INT_WPCIndUSMState = WPCIndUSMState__Type2; %Animation Option시 초기 출력 설정%NvM입력값으로 출력 변경으로 주석처리 */
    /* 1 */
    switch (rtu_CurProfile) {
     case Profile1:
      localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileOne;
      App_Model_INDUSMProfileOne(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
      break;

     case Profile2:
      /* 2 */
      localDW->is_INDAnimationUSM_Applied = A_IN_INDAnimationUSM_ProfileTwo;
      App_Model_INDUSMProfileTwo(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
      break;

     default:
      localDW->is_INDAnimationUSM_Applied = App_Mo_IN_INDAnimationUSM_Guest;
      App_Model_INDUSMGuest(rty_Output_CAN_WPCIndUSMState, rty_Output_INT_WPCIndUSMState, localDW);
      break;
    }
  } else {
    /* no actions */
  }

  /* End of Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
}

/*
 * System initialize for atomic system:
 *    '<S409>/DWPC1_LED_Sync_Indy'
 *    '<S409>/DWPC2_LED_Sync_Indy'
 */
void App_Mo_DWPC1_LED_Sync_Indy_Init(Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW)
{
  localDW->is_SyncTrigger = App_Mod_IN_NO_ACTIVE_CHILD_deuo;
  localDW->is_active_c10_Jdg_DualSyncOrder = 0U;
  *rty_b_SyncLED = Off;
  localDW->b_BlinkState_prev = Off;
  localDW->b_BlinkState_start = Off;
  localDW->b_CmdLEDSync_prev = Off;
  localDW->b_CmdLEDSync_start = Off;
  localDW->BlinkState_prev = BlinkOff;
  localDW->BlinkState_start = BlinkOff;
}

/*
 * System reset for atomic system:
 *    '<S409>/DWPC1_LED_Sync_Indy'
 *    '<S409>/DWPC2_LED_Sync_Indy'
 */
void App_M_DWPC1_LED_Sync_Indy_Reset(Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW)
{
  localDW->is_SyncTrigger = App_Mod_IN_NO_ACTIVE_CHILD_deuo;
  localDW->is_active_c10_Jdg_DualSyncOrder = 0U;
  *rty_b_SyncLED = Off;
  localDW->b_BlinkState_prev = Off;
  localDW->b_BlinkState_start = Off;
  localDW->b_CmdLEDSync_prev = Off;
  localDW->b_CmdLEDSync_start = Off;
  localDW->BlinkState_prev = BlinkOff;
  localDW->BlinkState_start = BlinkOff;
}

/*
 * Output and update for atomic system:
 *    '<S409>/DWPC1_LED_Sync_Indy'
 *    '<S409>/DWPC2_LED_Sync_Indy'
 */
void App_Model_DWPC1_LED_Sync_Indy(Bool rtu_b_BlinkState, Bool rtu_b_CmdLEDSync, BlinkState rtu_BlinkState, Bool *rty_b_SyncLED, DW_DWPC1_LED_Sync_Indy_App_Mo_T *localDW)
{
  localDW->b_BlinkState_prev = localDW->b_BlinkState_start;
  localDW->b_BlinkState_start = rtu_b_BlinkState;
  localDW->b_CmdLEDSync_prev = localDW->b_CmdLEDSync_start;
  localDW->b_CmdLEDSync_start = rtu_b_CmdLEDSync;
  localDW->BlinkState_prev = localDW->BlinkState_start;
  localDW->BlinkState_start = rtu_BlinkState;

  /* Chart: '<S409>/DWPC1_LED_Sync_Indy' */
  if ((uint32)localDW->is_active_c10_Jdg_DualSyncOrder == 0U) {
    localDW->b_BlinkState_prev = rtu_b_BlinkState;
    localDW->b_CmdLEDSync_prev = rtu_b_CmdLEDSync;
    localDW->BlinkState_prev = rtu_BlinkState;
    localDW->is_active_c10_Jdg_DualSyncOrder = 1U;
    localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOff;
    *rty_b_SyncLED = Off;
  } else if ((uint32)localDW->is_SyncTrigger == App_Model_IN_SyncTriggerOff) {
    Bool tmp;
    *rty_b_SyncLED = Off;
    tmp = localDW->b_BlinkState_start;
    if (((localDW->b_BlinkState_prev != tmp) && ((uint32)tmp == On)) || ((uint32)rtu_b_BlinkState == On)) {
      /* DefaultCondtionAdd_SideEffect */
      localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOn;
      *rty_b_SyncLED = On;
    }
  } else {
    Bool tmp;

    /* case IN_SyncTriggerOn: */
    *rty_b_SyncLED = On;
    tmp = localDW->b_CmdLEDSync_start;
    if (((localDW->b_CmdLEDSync_prev != tmp) && ((uint32)tmp == Off)) || ((localDW->BlinkState_prev != localDW->BlinkState_start) && ((uint32)localDW->BlinkState_start == BlinkComplete))) {
      localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOff;
      *rty_b_SyncLED = Off;
    }
  }

  /* End of Chart: '<S409>/DWPC1_LED_Sync_Indy' */
}

/*
 * System initialize for atomic system:
 *    '<S410>/IND_Animation_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_Priority_Flow_Graph'
 */
void IND_Animation_Priority_Flo_Init(PreSyncAct *rty_Var_PreSyncAct, DW_IND_Animation_Priority_Flo_T *localDW)
{
  localDW->is_active_c32_Jdg_DualSyncOrder = 0U;
  *rty_Var_PreSyncAct = PreSyncAct__Off;
}

/*
 * System reset for atomic system:
 *    '<S410>/IND_Animation_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_Priority_Flow_Graph'
 */
void IND_Animation_Priority_Fl_Reset(PreSyncAct *rty_Var_PreSyncAct, DW_IND_Animation_Priority_Flo_T *localDW)
{
  localDW->is_active_c32_Jdg_DualSyncOrder = 0U;
  *rty_Var_PreSyncAct = PreSyncAct__Off;
}

/*
 * Output and update for atomic system:
 *    '<S410>/IND_Animation_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_Priority_Flow_Graph'
 */
void IND_Animation_Priority_Flow_Gra(WPC2PreSyncAct rtu_Var_WPC2PreSyncAct, RWPCPreSyncAct rtu_Var_RWPCPreSyncAct, PreSyncAct *rty_Var_PreSyncAct, DW_IND_Animation_Priority_Flo_T *localDW)
{
  /* Chart: '<S410>/IND_Animation_Priority_Flow_Graph' */
  if ((uint32)localDW->is_active_c32_Jdg_DualSyncOrder == 0U) {
    localDW->is_active_c32_Jdg_DualSyncOrder = 1U;
    *rty_Var_PreSyncAct = PreSyncAct__Off;

    /* 1 */
    if (((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
      *rty_Var_PreSyncAct = PreSyncAct__WPC2;

      /* 1 */
    } else if (((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_Var_PreSyncAct = PreSyncAct__RWPC;

      /* 1 */
    } else if (((uint32)(*rty_Var_PreSyncAct) == PreSyncAct__WPC2) && ((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_Var_PreSyncAct = PreSyncAct__WPC2RWPC;

      /* 1 */
    } else if (((uint32)(*rty_Var_PreSyncAct) == PreSyncAct__RWPC) && ((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
      *rty_Var_PreSyncAct = PreSyncAct__RWPCWPC2;

      /* 1 */
    } else if (((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
      *rty_Var_PreSyncAct = PreSyncAct__Off;
    } else {
      /* no actions */
    }

    /* 1 */
  } else if (((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
    *rty_Var_PreSyncAct = PreSyncAct__WPC2;

    /* 1 */
  } else if (((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_Var_PreSyncAct = PreSyncAct__RWPC;

    /* 1 */
  } else if (((uint32)(*rty_Var_PreSyncAct) == PreSyncAct__WPC2) && ((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_Var_PreSyncAct = PreSyncAct__WPC2RWPC;

    /* 1 */
  } else if (((uint32)(*rty_Var_PreSyncAct) == PreSyncAct__RWPC) && ((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_On) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_On)) {
    *rty_Var_PreSyncAct = PreSyncAct__RWPCWPC2;

    /* 1 */
  } else if (((uint32)rtu_Var_WPC2PreSyncAct == WPC2PreSyncAct_Off) && ((uint32)rtu_Var_RWPCPreSyncAct == RWPCPreSyncAct_Off)) {
    *rty_Var_PreSyncAct = PreSyncAct__Off;
  } else {
    /* no actions */
  }

  /* End of Chart: '<S410>/IND_Animation_Priority_Flow_Graph' */
}

/*
 * System initialize for atomic system:
 *    '<S410>/IND_Animation_RWPC_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_RWPC_Priority_Flow_Graph'
 */
void IND_Animation_RWPC_Priorit_Init(RWPCPreSyncAct *rty_Var_RWPCPreSyncAct, DW_IND_Animation_RWPC_Priorit_T *localDW)
{
  localDW->is_active_c34_Jdg_DualSyncOrder = 0U;
  *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;
  localDW->Input_CAN_RWPCIndSyncVal_prev = RWPCIndSyncVal__Default;
  localDW->Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;
}

/*
 * System reset for atomic system:
 *    '<S410>/IND_Animation_RWPC_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_RWPC_Priority_Flow_Graph'
 */
void IND_Animation_RWPC_Priori_Reset(RWPCPreSyncAct *rty_Var_RWPCPreSyncAct, DW_IND_Animation_RWPC_Priorit_T *localDW)
{
  localDW->is_active_c34_Jdg_DualSyncOrder = 0U;
  *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;
  localDW->Input_CAN_RWPCIndSyncVal_prev = RWPCIndSyncVal__Default;
  localDW->Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;
}

/*
 * Output and update for atomic system:
 *    '<S410>/IND_Animation_RWPC_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_RWPC_Priority_Flow_Graph'
 */
void IND_Animation_RWPC_Priority_Flo(RWPCIndSyncVal rtu_Input_CAN_RWPCIndSyncVal, RWPCPreSyncAct *rty_Var_RWPCPreSyncAct, DW_IND_Animation_RWPC_Priorit_T *localDW)
{
  localDW->Input_CAN_RWPCIndSyncVal_prev = localDW->Input_CAN_RWPCIndSyncVal_start;
  localDW->Input_CAN_RWPCIndSyncVal_start = rtu_Input_CAN_RWPCIndSyncVal;

  /* Chart: '<S410>/IND_Animation_RWPC_Priority_Flow_Graph' */
  if ((uint32)localDW->is_active_c34_Jdg_DualSyncOrder == 0U) {
    localDW->Input_CAN_RWPCIndSyncVal_prev = rtu_Input_CAN_RWPCIndSyncVal;
    localDW->is_active_c34_Jdg_DualSyncOrder = 1U;
    *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;

    /* 1 */
    if (((uint32)(*rty_Var_RWPCPreSyncAct) == RWPCPreSyncAct_Off) && ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)
          localDW->Input_CAN_RWPCIndSyncVal_prev == RWPCIndSyncVal__Default)) && (localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start)) {
      *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_On;

      /* 1 */
    } else if (((uint32)(*rty_Var_RWPCPreSyncAct) == RWPCPreSyncAct_On) && ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)
                 localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Default))) {
      *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;
    } else {
      /* no actions */
    }

    /* 1 */
  } else if (((uint32)(*rty_Var_RWPCPreSyncAct) == RWPCPreSyncAct_Off) && ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)
               localDW->Input_CAN_RWPCIndSyncVal_prev == RWPCIndSyncVal__Default)) && (localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start)) {
    *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_On;

    /* 1 */
  } else if (((uint32)(*rty_Var_RWPCPreSyncAct) == RWPCPreSyncAct_On) && ((localDW->Input_CAN_RWPCIndSyncVal_prev != localDW->Input_CAN_RWPCIndSyncVal_start) && ((uint32)
               localDW->Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Default))) {
    *rty_Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;
  } else {
    /* no actions */
  }

  /* End of Chart: '<S410>/IND_Animation_RWPC_Priority_Flow_Graph' */
}

/*
 * System initialize for atomic system:
 *    '<S427>/DoorOpenCloseStateFunctionFlowGraph'
 *    '<S613>/DoorOpenCloseStateFunctionFlowGraph'
 *    '<S840>/DoorOpenCloseStateFunctionFlowGraph'
 */
void DoorOpenCloseStateFunction_Init(Bool *rty_b_AstDrSw, Bool *rty_b_DrvDrSw, Bool *rty_b_RLDrSw, Bool *rty_b_RRDrSw, DW_DoorOpenCloseStateFunction_T *localDW)
{
  localDW->is_active_c5_App_Model = 0U;
  *rty_b_AstDrSw = Off;
  *rty_b_DrvDrSw = Off;
  *rty_b_RLDrSw = Off;
  *rty_b_RRDrSw = Off;
}

/*
 * System reset for atomic system:
 *    '<S427>/DoorOpenCloseStateFunctionFlowGraph'
 *    '<S613>/DoorOpenCloseStateFunctionFlowGraph'
 *    '<S840>/DoorOpenCloseStateFunctionFlowGraph'
 */
void DoorOpenCloseStateFunctio_Reset(Bool *rty_b_AstDrSw, Bool *rty_b_DrvDrSw, Bool *rty_b_RLDrSw, Bool *rty_b_RRDrSw, DW_DoorOpenCloseStateFunction_T *localDW)
{
  localDW->is_active_c5_App_Model = 0U;
  *rty_b_AstDrSw = Off;
  *rty_b_DrvDrSw = Off;
  *rty_b_RLDrSw = Off;
  *rty_b_RRDrSw = Off;
}

/*
 * Output and update for atomic system:
 *    '<S427>/DoorOpenCloseStateFunctionFlowGraph'
 *    '<S613>/DoorOpenCloseStateFunctionFlowGraph'
 *    '<S840>/DoorOpenCloseStateFunctionFlowGraph'
 */
void DoorOpenCloseStateFunctionFlowG(LatchTypeOption rtu_Input_Latch_TypeOption_DRV, Bool rtu_Input_b_AstDrSw, Bool rtu_Input_b_DrvDrSw, Bool rtu_Input_b_RLDrSw, Bool rtu_Input_b_RRDrSw, Bool
  rtu_Input_b_AstDrSw_SBCM, Bool rtu_Input_b_DrvDrSw_SBCM, Bool rtu_Input_b_RLDrSw_SBCM, Bool rtu_Input_b_RRDrSw_SBCM, Bool *rty_b_AstDrSw, Bool *rty_b_DrvDrSw, Bool *rty_b_RLDrSw, Bool *rty_b_RRDrSw,
  DW_DoorOpenCloseStateFunction_T *localDW)
{
  /* Chart: '<S427>/DoorOpenCloseStateFunctionFlowGraph' */
  if ((uint32)localDW->is_active_c5_App_Model == 0U) {
    localDW->is_active_c5_App_Model = 1U;
    *rty_b_DrvDrSw = Off;
    *rty_b_AstDrSw = Off;
    *rty_b_RLDrSw = Off;
    *rty_b_RRDrSw = Off;
    if ((uint32)rtu_Input_Latch_TypeOption_DRV == Latch_On) {
      *rty_b_DrvDrSw = rtu_Input_b_DrvDrSw_SBCM;
      *rty_b_AstDrSw = rtu_Input_b_AstDrSw_SBCM;
      *rty_b_RLDrSw = rtu_Input_b_RLDrSw_SBCM;
      *rty_b_RRDrSw = rtu_Input_b_RRDrSw_SBCM;
    } else {
      *rty_b_DrvDrSw = rtu_Input_b_DrvDrSw;
      *rty_b_AstDrSw = rtu_Input_b_AstDrSw;
      *rty_b_RLDrSw = rtu_Input_b_RLDrSw;
      *rty_b_RRDrSw = rtu_Input_b_RRDrSw;
    }
  } else if ((uint32)rtu_Input_Latch_TypeOption_DRV == Latch_On) {
    *rty_b_DrvDrSw = rtu_Input_b_DrvDrSw_SBCM;
    *rty_b_AstDrSw = rtu_Input_b_AstDrSw_SBCM;
    *rty_b_RLDrSw = rtu_Input_b_RLDrSw_SBCM;
    *rty_b_RRDrSw = rtu_Input_b_RRDrSw_SBCM;
  } else {
    *rty_b_DrvDrSw = rtu_Input_b_DrvDrSw;
    *rty_b_AstDrSw = rtu_Input_b_AstDrSw;
    *rty_b_RLDrSw = rtu_Input_b_RLDrSw;
    *rty_b_RRDrSw = rtu_Input_b_RRDrSw;
  }

  /* End of Chart: '<S427>/DoorOpenCloseStateFunctionFlowGraph' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/FAN_LPConditionJdg'
 *    '<S439>/FAN_LPConditionJdg'
 *    '<S625>/FAN_LPConditionJdg'
 *    '<S852>/FAN_LPConditionJdg'
 */
void App_Mod_FAN_LPConditionJdg_Init(uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW)
{
  localDW->is_FAN_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_n3cd;
  localDW->is_active_c43_LPConditionJdg_li = 0U;
  *rty_FAN_LPConditionFlag_write = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/FAN_LPConditionJdg'
 *    '<S439>/FAN_LPConditionJdg'
 *    '<S625>/FAN_LPConditionJdg'
 *    '<S852>/FAN_LPConditionJdg'
 */
void App_Mo_FAN_LPConditionJdg_Reset(uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW)
{
  localDW->is_FAN_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_n3cd;
  localDW->is_active_c43_LPConditionJdg_li = 0U;
  *rty_FAN_LPConditionFlag_write = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/FAN_LPConditionJdg'
 *    '<S439>/FAN_LPConditionJdg'
 *    '<S625>/FAN_LPConditionJdg'
 *    '<S852>/FAN_LPConditionJdg'
 */
void App_Model_FAN_LPConditionJdg(uint16 rtu_FAN_PWM, uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW)
{
  /* Chart: '<S438>/FAN_LPConditionJdg' */
  if ((uint32)localDW->is_active_c43_LPConditionJdg_li == 0U) {
    localDW->is_active_c43_LPConditionJdg_li = 1U;
    localDW->is_FAN_LPConditionChk_Chart = App_Mode_IN_FAN_LPCondition_Off;
    *rty_FAN_LPConditionFlag_write = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_FAN_LPConditionChk_Chart == App_Mode_IN_FAN_LPCondition_Off) {
    *rty_FAN_LPConditionFlag_write = 0U;
    if (rtu_FAN_PWM == ((uint16)0U)) {
      localDW->is_FAN_LPConditionChk_Chart = App_Model_IN_FAN_LPCondition_On;
      *rty_FAN_LPConditionFlag_write = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_FAN_LPCondition_On: */
    *rty_FAN_LPConditionFlag_write = 1U;
    if (rtu_FAN_PWM != ((uint16)0U)) {
      localDW->is_FAN_LPConditionChk_Chart = App_Mode_IN_FAN_LPCondition_Off;
      *rty_FAN_LPConditionFlag_write = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/FAN_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/MainControl_LPConditionJdg'
 *    '<S439>/MainControl_LPConditionJdg'
 *    '<S625>/MainControl_LPConditionJdg'
 *    '<S852>/MainControl_LPConditionJdg'
 */
void MainControl_LPConditionJdg_Init(uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW)
{
  localDW->is_Main_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_era3;
  localDW->is_active_c44_LPConditionJdg_li = 0U;
  *rty_WPCMain_LPConditionFlag_wri = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/MainControl_LPConditionJdg'
 *    '<S439>/MainControl_LPConditionJdg'
 *    '<S625>/MainControl_LPConditionJdg'
 *    '<S852>/MainControl_LPConditionJdg'
 */
void MainControl_LPConditionJd_Reset(uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW)
{
  localDW->is_Main_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_era3;
  localDW->is_active_c44_LPConditionJdg_li = 0U;
  *rty_WPCMain_LPConditionFlag_wri = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/MainControl_LPConditionJdg'
 *    '<S439>/MainControl_LPConditionJdg'
 *    '<S625>/MainControl_LPConditionJdg'
 *    '<S852>/MainControl_LPConditionJdg'
 */
void App__MainControl_LPConditionJdg(WPCStatus rtu_WPCStatus, uint16 rtu_b_Timer_PhoneReminderCheck, uint16 rtu_b_Timer_PhoneWarningCheck, uint16 rtu_b_Timer_WarningComplete, uint16
  rtu_b_Timer_WarningTypeCheck, Bool rtu_b_PhnLeftChk_Enable, uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW)
{
  /* Chart: '<S438>/MainControl_LPConditionJdg' */
  if ((uint32)localDW->is_active_c44_LPConditionJdg_li == 0U) {
    localDW->is_active_c44_LPConditionJdg_li = 1U;
    localDW->is_Main_LPConditionChk_Chart = App_Mod_IN_Main_LPCondition_Off;
    *rty_WPCMain_LPConditionFlag_wri = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_Main_LPConditionChk_Chart == App_Mod_IN_Main_LPCondition_Off) {
    *rty_WPCMain_LPConditionFlag_wri = 0U;
    if ((rtu_b_Timer_PhoneReminderCheck == 0U) && (rtu_b_Timer_PhoneWarningCheck == 0U) && (rtu_b_Timer_WarningComplete == 0U) && (rtu_b_Timer_WarningTypeCheck == 0U) && ((uint32)rtu_WPCStatus !=
         WPCMode) && ((uint32)rtu_b_PhnLeftChk_Enable == Off)) {
      localDW->is_Main_LPConditionChk_Chart = App_Mode_IN_Main_LPCondition_On;
      *rty_WPCMain_LPConditionFlag_wri = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_Main_LPCondition_On: */
    *rty_WPCMain_LPConditionFlag_wri = 1U;
    if ((rtu_b_Timer_PhoneReminderCheck > 0U) || (rtu_b_Timer_PhoneWarningCheck > 0U) || (rtu_b_Timer_WarningComplete > 0U) || (rtu_b_Timer_WarningTypeCheck > 0U) || ((uint32)rtu_WPCStatus == WPCMode)
        || ((uint32)rtu_b_PhnLeftChk_Enable == On)) {
      localDW->is_Main_LPConditionChk_Chart = App_Mod_IN_Main_LPCondition_Off;
      *rty_WPCMain_LPConditionFlag_wri = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/MainControl_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/NFC_Mode_LPConditionJdg'
 *    '<S439>/NFC_Mode_LPConditionJdg'
 *    '<S625>/NFC_Mode_LPConditionJdg'
 *    '<S852>/NFC_Mode_LPConditionJdg'
 */
void Ap_NFC_Mode_LPConditionJdg_Init(uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW)
{
  localDW->is_NFC_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_kt4t;
  localDW->is_active_c45_LPConditionJdg_li = 0U;
  *rty_NFCMode_LPConditionFlag_wri = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/NFC_Mode_LPConditionJdg'
 *    '<S439>/NFC_Mode_LPConditionJdg'
 *    '<S625>/NFC_Mode_LPConditionJdg'
 *    '<S852>/NFC_Mode_LPConditionJdg'
 */
void A_NFC_Mode_LPConditionJdg_Reset(uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW)
{
  localDW->is_NFC_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_kt4t;
  localDW->is_active_c45_LPConditionJdg_li = 0U;
  *rty_NFCMode_LPConditionFlag_wri = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/NFC_Mode_LPConditionJdg'
 *    '<S439>/NFC_Mode_LPConditionJdg'
 *    '<S625>/NFC_Mode_LPConditionJdg'
 *    '<S852>/NFC_Mode_LPConditionJdg'
 */
void App_Mod_NFC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW)
{
  /* Chart: '<S438>/NFC_Mode_LPConditionJdg' */
  if ((uint32)localDW->is_active_c45_LPConditionJdg_li == 0U) {
    localDW->is_active_c45_LPConditionJdg_li = 1U;
    localDW->is_NFC_LPConditionChk_Chart = App_Mode_IN_NFC_LPCondition_Off;
    *rty_NFCMode_LPConditionFlag_wri = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_NFC_LPConditionChk_Chart == App_Mode_IN_NFC_LPCondition_Off) {
    *rty_NFCMode_LPConditionFlag_wri = 0U;
    if (((uint32)rtu_WPCStatus != LPCDMode) && ((uint32)rtu_WPCStatus != NFCMode) && ((uint32)rtu_WPCStatus != PICCMode)) {
      localDW->is_NFC_LPConditionChk_Chart = App_Model_IN_NFC_LPCondition_On;
      *rty_NFCMode_LPConditionFlag_wri = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_NFC_LPCondition_On: */
    *rty_NFCMode_LPConditionFlag_wri = 1U;
    if (((uint32)rtu_WPCStatus == LPCDMode) || ((uint32)rtu_WPCStatus == NFCMode) || ((uint32)rtu_WPCStatus == PICCMode)) {
      localDW->is_NFC_LPConditionChk_Chart = App_Mode_IN_NFC_LPCondition_Off;
      *rty_NFCMode_LPConditionFlag_wri = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/NFC_Mode_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/OverCurrent_LPConditionJdg'
 *    '<S439>/OverCurrent_LPConditionJdg'
 *    '<S625>/OverCurrent_LPConditionJdg'
 *    '<S852>/OverCurrent_LPConditionJdg'
 */
void OverCurrent_LPConditionJdg_Init(uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW)
{
  localDW->is_OverCurrent_LPConditionChk_C = App_Mod_IN_NO_ACTIVE_CHILD_dovo;
  localDW->is_active_c46_LPConditionJdg_li = 0U;
  *rty_OverCurrent_LPConditionFlag = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/OverCurrent_LPConditionJdg'
 *    '<S439>/OverCurrent_LPConditionJdg'
 *    '<S625>/OverCurrent_LPConditionJdg'
 *    '<S852>/OverCurrent_LPConditionJdg'
 */
void OverCurrent_LPConditionJd_Reset(uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW)
{
  localDW->is_OverCurrent_LPConditionChk_C = App_Mod_IN_NO_ACTIVE_CHILD_dovo;
  localDW->is_active_c46_LPConditionJdg_li = 0U;
  *rty_OverCurrent_LPConditionFlag = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/OverCurrent_LPConditionJdg'
 *    '<S439>/OverCurrent_LPConditionJdg'
 *    '<S625>/OverCurrent_LPConditionJdg'
 *    '<S852>/OverCurrent_LPConditionJdg'
 */
void App__OverCurrent_LPConditionJdg(Bool rtu_b_CurrentFault, uint8 rtu_b_Timer_OvrCurr, uint16 rtu_b_Timer_ReOvrCurr, uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW)
{
  /* Chart: '<S438>/OverCurrent_LPConditionJdg' */
  if ((uint32)localDW->is_active_c46_LPConditionJdg_li == 0U) {
    localDW->is_active_c46_LPConditionJdg_li = 1U;
    localDW->is_OverCurrent_LPConditionChk_C = IN_OverCurrent_LPCondition_Off;
    *rty_OverCurrent_LPConditionFlag = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_OverCurrent_LPConditionChk_C == IN_OverCurrent_LPCondition_Off) {
    *rty_OverCurrent_LPConditionFlag = 0U;
    if (((uint32)rtu_b_CurrentFault == Off) && (rtu_b_Timer_OvrCurr == 0U) && (rtu_b_Timer_ReOvrCurr == 0U)) {
      localDW->is_OverCurrent_LPConditionChk_C = A_IN_OverCurrent_LPCondition_On;
      *rty_OverCurrent_LPConditionFlag = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_OverCurrent_LPCondition_On: */
    *rty_OverCurrent_LPConditionFlag = 1U;
    if (((uint32)rtu_b_CurrentFault == On) || (rtu_b_Timer_OvrCurr > 0U) || (rtu_b_Timer_ReOvrCurr > 0U)) {
      localDW->is_OverCurrent_LPConditionChk_C = IN_OverCurrent_LPCondition_Off;
      *rty_OverCurrent_LPConditionFlag = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/OverCurrent_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/OverTempDetect_LPConditionJdg'
 *    '<S439>/OverTempDetect_LPConditionJdg'
 *    '<S625>/OverTempDetect_LPConditionJdg'
 *    '<S852>/OverTempDetect_LPConditionJdg'
 */
void OverTempDetect_LPCondition_Init(uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW)
{
  localDW->is_OverTempDetect_LPConditionCh = App_Mod_IN_NO_ACTIVE_CHILD_ixot;
  localDW->is_active_c47_LPConditionJdg_li = 0U;
  *rty_OverTempDetect_LPConditionF = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/OverTempDetect_LPConditionJdg'
 *    '<S439>/OverTempDetect_LPConditionJdg'
 *    '<S625>/OverTempDetect_LPConditionJdg'
 *    '<S852>/OverTempDetect_LPConditionJdg'
 */
void OverTempDetect_LPConditio_Reset(uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW)
{
  localDW->is_OverTempDetect_LPConditionCh = App_Mod_IN_NO_ACTIVE_CHILD_ixot;
  localDW->is_active_c47_LPConditionJdg_li = 0U;
  *rty_OverTempDetect_LPConditionF = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/OverTempDetect_LPConditionJdg'
 *    '<S439>/OverTempDetect_LPConditionJdg'
 *    '<S625>/OverTempDetect_LPConditionJdg'
 *    '<S852>/OverTempDetect_LPConditionJdg'
 */
void A_OverTempDetect_LPConditionJdg(Bool rtu_b_TemperatureFault, uint8 rtu_b_Timer_OverTemp, uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW)
{
  /* Chart: '<S438>/OverTempDetect_LPConditionJdg' */
  if ((uint32)localDW->is_active_c47_LPConditionJdg_li == 0U) {
    localDW->is_active_c47_LPConditionJdg_li = 1U;
    localDW->is_OverTempDetect_LPConditionCh = IN_OverTempDetect_LPCondition_O;
    *rty_OverTempDetect_LPConditionF = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_OverTempDetect_LPConditionCh == IN_OverTempDetect_LPCondition_O) {
    *rty_OverTempDetect_LPConditionF = 0U;
    if (((uint32)rtu_b_TemperatureFault == Off) && (rtu_b_Timer_OverTemp == 0U)) {
      localDW->is_OverTempDetect_LPConditionCh = IN_OverTempDetect_LPCondit_kkox;
      *rty_OverTempDetect_LPConditionF = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_OverTempDetect_LPCondition_On: */
    *rty_OverTempDetect_LPConditionF = 1U;
    if (((uint32)rtu_b_TemperatureFault == On) || (rtu_b_Timer_OverTemp > 0U)) {
      localDW->is_OverTempDetect_LPConditionCh = IN_OverTempDetect_LPCondition_O;
      *rty_OverTempDetect_LPConditionF = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/OverTempDetect_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/SMKLF_LPConditionJdg'
 *    '<S439>/SMKLF_LPConditionJdg'
 *    '<S625>/SMKLF_LPConditionJdg'
 *    '<S852>/SMKLF_LPConditionJdg'
 */
void App_M_SMKLF_LPConditionJdg_Init(uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW)
{
  localDW->is_SMKLF_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_g1io;
  localDW->is_active_c48_LPConditionJdg_li = 0U;
  *rty_SMKLF_LPConditionFlag_write = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/SMKLF_LPConditionJdg'
 *    '<S439>/SMKLF_LPConditionJdg'
 *    '<S625>/SMKLF_LPConditionJdg'
 *    '<S852>/SMKLF_LPConditionJdg'
 */
void App__SMKLF_LPConditionJdg_Reset(uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW)
{
  localDW->is_SMKLF_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_g1io;
  localDW->is_active_c48_LPConditionJdg_li = 0U;
  *rty_SMKLF_LPConditionFlag_write = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/SMKLF_LPConditionJdg'
 *    '<S439>/SMKLF_LPConditionJdg'
 *    '<S625>/SMKLF_LPConditionJdg'
 *    '<S852>/SMKLF_LPConditionJdg'
 */
void App_Model_SMKLF_LPConditionJdg(Bool rtu_b_LFState, uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW)
{
  /* Chart: '<S438>/SMKLF_LPConditionJdg' */
  if ((uint32)localDW->is_active_c48_LPConditionJdg_li == 0U) {
    localDW->is_active_c48_LPConditionJdg_li = 1U;
    localDW->is_SMKLF_LPConditionChk_Chart = App_Mo_IN_SMKLF_LPCondition_Off;
    *rty_SMKLF_LPConditionFlag_write = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_SMKLF_LPConditionChk_Chart == App_Mo_IN_SMKLF_LPCondition_Off) {
    *rty_SMKLF_LPConditionFlag_write = 0U;
    if ((uint32)rtu_b_LFState == Off) {
      localDW->is_SMKLF_LPConditionChk_Chart = App_Mod_IN_SMKLF_LPCondition_On;
      *rty_SMKLF_LPConditionFlag_write = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_SMKLF_LPCondition_On: */
    *rty_SMKLF_LPConditionFlag_write = 1U;
    if ((uint32)rtu_b_LFState == On) {
      localDW->is_SMKLF_LPConditionChk_Chart = App_Mo_IN_SMKLF_LPCondition_Off;
      *rty_SMKLF_LPConditionFlag_write = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/SMKLF_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S439>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S625>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S852>/TempSnsrErrDetect_LPConditionJdg'
 */
void TempSnsrErrDetect_LPCondit_Init(uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW)
{
  localDW->is_TempSnsrErrDetect_LPConditio = App_Mod_IN_NO_ACTIVE_CHILD_hoib;
  localDW->is_active_c49_LPConditionJdg_li = 0U;
  *rty_TempSnsrError_LPConditionFl = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S439>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S625>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S852>/TempSnsrErrDetect_LPConditionJdg'
 */
void TempSnsrErrDetect_LPCondi_Reset(uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW)
{
  localDW->is_TempSnsrErrDetect_LPConditio = App_Mod_IN_NO_ACTIVE_CHILD_hoib;
  localDW->is_active_c49_LPConditionJdg_li = 0U;
  *rty_TempSnsrError_LPConditionFl = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S439>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S625>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S852>/TempSnsrErrDetect_LPConditionJdg'
 */
void TempSnsrErrDetect_LPConditionJd(Bool rtu_b_TempSensorFault, uint8 rtu_b_Timer_TempSensor_Check, uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW)
{
  /* Chart: '<S438>/TempSnsrErrDetect_LPConditionJdg' */
  if ((uint32)localDW->is_active_c49_LPConditionJdg_li == 0U) {
    localDW->is_active_c49_LPConditionJdg_li = 1U;
    localDW->is_TempSnsrErrDetect_LPConditio = IN_TempSnsrErrDetect_LPConditio;
    *rty_TempSnsrError_LPConditionFl = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_TempSnsrErrDetect_LPConditio == IN_TempSnsrErrDetect_LPConditio) {
    *rty_TempSnsrError_LPConditionFl = 0U;
    if (((uint32)rtu_b_TempSensorFault == Off) && (rtu_b_Timer_TempSensor_Check == 0U)) {
      localDW->is_TempSnsrErrDetect_LPConditio = IN_TempSnsrErrDetect_LPCon_jdsz;
      *rty_TempSnsrError_LPConditionFl = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_TempSnsrErrDetect_LPCondition_On: */
    *rty_TempSnsrError_LPConditionFl = 1U;
    if (((uint32)rtu_b_TempSensorFault == On) || (rtu_b_Timer_TempSensor_Check > 0U)) {
      localDW->is_TempSnsrErrDetect_LPConditio = IN_TempSnsrErrDetect_LPConditio;
      *rty_TempSnsrError_LPConditionFl = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/TempSnsrErrDetect_LPConditionJdg' */
}

/* Function for Chart: '<S438>/USM_WPC_LPConditionJdg' */
static void App_Model_LPConditionHold(DW_USM_WPC_LPConditionJdg_App_T *localDW)
{
  switch (localDW->is_LPConditionHold) {
   case App_Mode_IN_LPConditionHold_Off:
    if (localDW->sfEvent == (sint32)event_StartTimer_LPConditionHol) {
      localDW->is_LPConditionHold = App_Model_IN_LPConditionHold_On;
    }
    break;

   case App_Model_IN_LPConditionHold_On:
    {
      switch (localDW->sfEvent) {
       case event_CancelTimer_LPConditionHo:
        localDW->is_LPConditionHold = App_Mode_IN_LPConditionHold_Off;
        localDW->Timer_LPConditionHold = 0U;
        break;

       case event_StartTimer_LPConditionHol:
        localDW->Timer_LPConditionHold = 0U;
        localDW->is_LPConditionHold = App_Model_IN_LPConditionHold_On;
        break;

       default:
        {
          uint32 qY;
          qY = localDW->Timer_LPConditionHold + /*MW:OvSatOk*/ 1U;
          if ((localDW->Timer_LPConditionHold + 1U) < localDW->Timer_LPConditionHold) {
            qY = MAX_uint32_T;
          }

          localDW->Timer_LPConditionHold = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S438>/USM_WPC_LPConditionJdg' */
static void App_Model_LPConditionTimerCheck(DW_USM_WPC_LPConditionJdg_App_T *localDW)
{
  if ((localDW->m_ProfileGuestWPCUSM_App_prev != localDW->m_ProfileGuestWPCUSM_App_start) || (localDW->m_ProfileOneWPCUSM_App_prev != localDW->m_ProfileOneWPCUSM_App_start) ||
      (localDW->m_ProfileTwoWPCUSM_App_prev != localDW->m_ProfileTwoWPCUSM_App_start) || (localDW->m_ProfileThreeWPCUSM_App_prev != localDW->m_ProfileThreeWPCUSM_App_start) ||
      (localDW->m_RWPCUSM_App_prev != localDW->m_RWPCUSM_App_start)) {
    sint32 c_previousEvent;
    localDW->ECUResetEnable = 0U;
    c_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_StartTimer_LPConditionHol;
    if ((uint32)localDW->is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold(localDW);
    }

    localDW->sfEvent = c_previousEvent;
  } else if (localDW->Timer_LPConditionHold >= 100U) {
    sint32 c_previousEvent;

    /* 1s */
    localDW->ECUResetEnable = 1U;
    c_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_CancelTimer_LPConditionHo;
    if ((uint32)localDW->is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold(localDW);
    }

    localDW->sfEvent = c_previousEvent;
  } else {
    /* no actions */
  }
}

/*
 * System initialize for atomic system:
 *    '<S438>/USM_WPC_LPConditionJdg'
 *    '<S852>/USM_WPC_LPConditionJdg'
 */
void App_USM_WPC_LPConditionJdg_Init(uint8 *rty_P_WPC_USM_LPConditionFlag_w, DW_USM_WPC_LPConditionJdg_App_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_cjwd;
  localDW->is_active_LPConditionChk_Chart = 0U;
  localDW->is_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_jg03;
  localDW->is_active_LPConditionHold = 0U;
  localDW->is_LPConditionHold = App_Mod_IN_NO_ACTIVE_CHILD_jg03;
  localDW->is_active_c50_spestfoAI9xud8Ghi = 0U;
  localDW->ECUResetEnable = 0U;
  localDW->Timer_LPConditionHold = 0U;
  *rty_P_WPC_USM_LPConditionFlag_w = 0U;
  localDW->m_ProfileGuestWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileGuestWPCUSM_App_start = WPC_On;
  localDW->m_ProfileOneWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileOneWPCUSM_App_start = WPC_On;
  localDW->m_ProfileTwoWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileTwoWPCUSM_App_start = WPC_On;
  localDW->m_ProfileThreeWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileThreeWPCUSM_App_start = WPC_On;
}

/*
 * System reset for atomic system:
 *    '<S438>/USM_WPC_LPConditionJdg'
 *    '<S852>/USM_WPC_LPConditionJdg'
 */
void Ap_USM_WPC_LPConditionJdg_Reset(uint8 *rty_P_WPC_USM_LPConditionFlag_w, DW_USM_WPC_LPConditionJdg_App_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_cjwd;
  localDW->is_active_LPConditionChk_Chart = 0U;
  localDW->is_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_jg03;
  localDW->is_active_LPConditionHold = 0U;
  localDW->is_LPConditionHold = App_Mod_IN_NO_ACTIVE_CHILD_jg03;
  localDW->is_active_c50_spestfoAI9xud8Ghi = 0U;
  localDW->ECUResetEnable = 0U;
  localDW->Timer_LPConditionHold = 0U;
  *rty_P_WPC_USM_LPConditionFlag_w = 0U;
  localDW->m_ProfileGuestWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileGuestWPCUSM_App_start = WPC_On;
  localDW->m_ProfileOneWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileOneWPCUSM_App_start = WPC_On;
  localDW->m_ProfileTwoWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileTwoWPCUSM_App_start = WPC_On;
  localDW->m_ProfileThreeWPCUSM_App_prev = WPC_On;
  localDW->m_ProfileThreeWPCUSM_App_start = WPC_On;
}

/*
 * Output and update for atomic system:
 *    '<S438>/USM_WPC_LPConditionJdg'
 *    '<S852>/USM_WPC_LPConditionJdg'
 */
void App_Mode_USM_WPC_LPConditionJdg(C_WPCOnOffNvalueSet rtu_m_ProfileGuestWPCUSM_App, C_WPCOnOffNvalueSet rtu_m_ProfileOneWPCUSM_App, C_WPCOnOffNvalueSet rtu_m_ProfileTwoWPCUSM_App, float64
  rtu_m_RWPCUSM_App, C_WPCOnOffNvalueSet rtu_m_ProfileThreeWPCUSM_App, uint8 *rty_P_WPC_USM_LPConditionFlag_w, DW_USM_WPC_LPConditionJdg_App_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_cjwd;
  localDW->m_ProfileGuestWPCUSM_App_prev = localDW->m_ProfileGuestWPCUSM_App_start;
  localDW->m_ProfileGuestWPCUSM_App_start = rtu_m_ProfileGuestWPCUSM_App;
  localDW->m_ProfileOneWPCUSM_App_prev = localDW->m_ProfileOneWPCUSM_App_start;
  localDW->m_ProfileOneWPCUSM_App_start = rtu_m_ProfileOneWPCUSM_App;
  localDW->m_ProfileTwoWPCUSM_App_prev = localDW->m_ProfileTwoWPCUSM_App_start;
  localDW->m_ProfileTwoWPCUSM_App_start = rtu_m_ProfileTwoWPCUSM_App;
  localDW->m_ProfileThreeWPCUSM_App_prev = localDW->m_ProfileThreeWPCUSM_App_start;
  localDW->m_ProfileThreeWPCUSM_App_start = rtu_m_ProfileThreeWPCUSM_App;
  localDW->m_RWPCUSM_App_prev = localDW->m_RWPCUSM_App_start;
  localDW->m_RWPCUSM_App_start = rtu_m_RWPCUSM_App;

  /* Chart: '<S438>/USM_WPC_LPConditionJdg' */
  if ((uint32)localDW->is_active_c50_spestfoAI9xud8Ghi == 0U) {
    localDW->m_ProfileGuestWPCUSM_App_prev = rtu_m_ProfileGuestWPCUSM_App;
    localDW->m_ProfileOneWPCUSM_App_prev = rtu_m_ProfileOneWPCUSM_App;
    localDW->m_ProfileTwoWPCUSM_App_prev = rtu_m_ProfileTwoWPCUSM_App;
    localDW->m_ProfileThreeWPCUSM_App_prev = rtu_m_ProfileThreeWPCUSM_App;
    localDW->m_RWPCUSM_App_prev = rtu_m_RWPCUSM_App;
    localDW->is_active_c50_spestfoAI9xud8Ghi = 1U;
    localDW->is_active_LPConditionHold = 1U;
    localDW->is_LPConditionHold = App_Mode_IN_LPConditionHold_Off;
    localDW->Timer_LPConditionHold = 0U;
    localDW->is_active_LPConditionChk_Chart = 1U;
    localDW->is_LPConditionChk_Chart = App_Model_IN_LPCondition_Off;
    localDW->sfEvent = (sint32)event_StartTimer_LPConditionHol;
    App_Model_LPConditionHold(localDW);
    localDW->sfEvent = -1;
    *rty_P_WPC_USM_LPConditionFlag_w = 0U;

    /* Awake */
    localDW->ECUResetEnable = 0U;
  } else {
    if ((uint32)localDW->is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold(localDW);
    }

    if ((uint32)localDW->is_active_LPConditionChk_Chart != 0U) {
      switch (localDW->is_LPConditionChk_Chart) {
       case App_Model_IN_LPCondition_Off:
        *rty_P_WPC_USM_LPConditionFlag_w = 0U;
        if (localDW->ECUResetEnable == 1U) {
          localDW->sfEvent = (sint32)event_CancelTimer_LPConditionHo;
          if ((uint32)localDW->is_active_LPConditionHold != 0U) {
            App_Model_LPConditionHold(localDW);
          }

          localDW->sfEvent = -1;
          localDW->ECUResetEnable = 0U;
          localDW->is_LPConditionChk_Chart = App_Model_IN_LPCondition_On;
          *rty_P_WPC_USM_LPConditionFlag_w = 1U;

          /* SleepOK */
        } else {
          App_Model_LPConditionTimerCheck(localDW);
        }
        break;

       case App_Model_IN_LPCondition_On:
        *rty_P_WPC_USM_LPConditionFlag_w = 1U;
        if ((localDW->m_ProfileGuestWPCUSM_App_prev != localDW->m_ProfileGuestWPCUSM_App_start) || (localDW->m_ProfileOneWPCUSM_App_prev != localDW->m_ProfileOneWPCUSM_App_start) ||
            (localDW->m_ProfileTwoWPCUSM_App_prev != localDW->m_ProfileTwoWPCUSM_App_start) || (localDW->m_ProfileThreeWPCUSM_App_prev != localDW->m_ProfileThreeWPCUSM_App_start) ||
            (localDW->m_RWPCUSM_App_prev != localDW->m_RWPCUSM_App_start)) {
          localDW->is_LPConditionChk_Chart = App_Model_IN_LPCondition_Off;
          localDW->sfEvent = (sint32)event_StartTimer_LPConditionHol;
          if ((uint32)localDW->is_active_LPConditionHold != 0U) {
            App_Model_LPConditionHold(localDW);
          }

          localDW->sfEvent = -1;
          *rty_P_WPC_USM_LPConditionFlag_w = 0U;

          /* Awake */
          localDW->ECUResetEnable = 0U;
        }
        break;

       default:
        /* no actions */
        break;
      }
    }
  }

  /* End of Chart: '<S438>/USM_WPC_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S438>/WPC_Mode_LPConditionJdg'
 *    '<S439>/WPC_Mode_LPConditionJdg'
 *    '<S625>/WPC_Mode_LPConditionJdg'
 *    '<S852>/WPC_Mode_LPConditionJdg'
 */
void Ap_WPC_Mode_LPConditionJdg_Init(uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW)
{
  localDW->is_WPC_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_jtms;
  localDW->is_active_c51_LPConditionJdg_li = 0U;
  *rty_WPCMode_LPConditionFlag_wri = 0U;
}

/*
 * System reset for atomic system:
 *    '<S438>/WPC_Mode_LPConditionJdg'
 *    '<S439>/WPC_Mode_LPConditionJdg'
 *    '<S625>/WPC_Mode_LPConditionJdg'
 *    '<S852>/WPC_Mode_LPConditionJdg'
 */
void A_WPC_Mode_LPConditionJdg_Reset(uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW)
{
  localDW->is_WPC_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_jtms;
  localDW->is_active_c51_LPConditionJdg_li = 0U;
  *rty_WPCMode_LPConditionFlag_wri = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S438>/WPC_Mode_LPConditionJdg'
 *    '<S439>/WPC_Mode_LPConditionJdg'
 *    '<S625>/WPC_Mode_LPConditionJdg'
 *    '<S852>/WPC_Mode_LPConditionJdg'
 */
void App_Mod_WPC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW)
{
  /* Chart: '<S438>/WPC_Mode_LPConditionJdg' */
  if ((uint32)localDW->is_active_c51_LPConditionJdg_li == 0U) {
    localDW->is_active_c51_LPConditionJdg_li = 1U;
    localDW->is_WPC_LPConditionChk_Chart = App_Mode_IN_WPC_LPCondition_Off;
    *rty_WPCMode_LPConditionFlag_wri = 0U;

    /* Awake */
  } else if ((uint32)localDW->is_WPC_LPConditionChk_Chart == App_Mode_IN_WPC_LPCondition_Off) {
    *rty_WPCMode_LPConditionFlag_wri = 0U;
    if ((uint32)rtu_WPCStatus != WPCMode) {
      localDW->is_WPC_LPConditionChk_Chart = App_Model_IN_WPC_LPCondition_On;
      *rty_WPCMode_LPConditionFlag_wri = 1U;

      /* Sleep */
    }
  } else {
    /* case IN_WPC_LPCondition_On: */
    *rty_WPCMode_LPConditionFlag_wri = 1U;
    if ((uint32)rtu_WPCStatus == WPCMode) {
      localDW->is_WPC_LPConditionChk_Chart = App_Mode_IN_WPC_LPCondition_Off;
      *rty_WPCMode_LPConditionFlag_wri = 0U;

      /* Awake */
    }
  }

  /* End of Chart: '<S438>/WPC_Mode_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S474>/Amber_Sync_Indy'
 *    '<S652>/Amber_Sync_Indy'
 */
void App_Model_Amber_Sync_Indy_Init(Bool *rty_b_SyncAmber, DW_Amber_Sync_Indy_App_Model_T *localDW)
{
  localDW->is_SyncTrigger = App_Mod_IN_NO_ACTIVE_CHILD_eccj;
  localDW->is_active_c172_WPC_IND_Animatio = 0U;
  *rty_b_SyncAmber = Off;
  localDW->b_BlinkState_prev = Off;
  localDW->b_BlinkState_start = Off;
  localDW->b_CmdAmberSync_prev = Off;
  localDW->b_CmdAmberSync_start = Off;
  localDW->BlinkState_prev = BlinkOff;
  localDW->BlinkState_start = BlinkOff;
}

/*
 * System reset for atomic system:
 *    '<S474>/Amber_Sync_Indy'
 *    '<S652>/Amber_Sync_Indy'
 */
void App_Model_Amber_Sync_Indy_Reset(Bool *rty_b_SyncAmber, DW_Amber_Sync_Indy_App_Model_T *localDW)
{
  localDW->is_SyncTrigger = App_Mod_IN_NO_ACTIVE_CHILD_eccj;
  localDW->is_active_c172_WPC_IND_Animatio = 0U;
  *rty_b_SyncAmber = Off;
  localDW->b_BlinkState_prev = Off;
  localDW->b_BlinkState_start = Off;
  localDW->b_CmdAmberSync_prev = Off;
  localDW->b_CmdAmberSync_start = Off;
  localDW->BlinkState_prev = BlinkOff;
  localDW->BlinkState_start = BlinkOff;
}

/*
 * Output and update for atomic system:
 *    '<S474>/Amber_Sync_Indy'
 *    '<S652>/Amber_Sync_Indy'
 */
void App_Model_Amber_Sync_Indy(Bool rtu_b_BlinkState, Bool rtu_b_CmdAmberSync, BlinkState rtu_BlinkState, Bool *rty_b_SyncAmber, DW_Amber_Sync_Indy_App_Model_T *localDW)
{
  localDW->b_BlinkState_prev = localDW->b_BlinkState_start;
  localDW->b_BlinkState_start = rtu_b_BlinkState;
  localDW->b_CmdAmberSync_prev = localDW->b_CmdAmberSync_start;
  localDW->b_CmdAmberSync_start = rtu_b_CmdAmberSync;
  localDW->BlinkState_prev = localDW->BlinkState_start;
  localDW->BlinkState_start = rtu_BlinkState;

  /* Chart: '<S474>/Amber_Sync_Indy' */
  if ((uint32)localDW->is_active_c172_WPC_IND_Animatio == 0U) {
    localDW->b_BlinkState_prev = rtu_b_BlinkState;
    localDW->b_CmdAmberSync_prev = rtu_b_CmdAmberSync;
    localDW->BlinkState_prev = rtu_BlinkState;
    localDW->is_active_c172_WPC_IND_Animatio = 1U;
    localDW->is_SyncTrigger = App_Mode_IN_SyncTriggerOff_put5;
    *rty_b_SyncAmber = Off;
  } else if ((uint32)localDW->is_SyncTrigger == App_Mode_IN_SyncTriggerOff_put5) {
    Bool tmp;
    *rty_b_SyncAmber = Off;
    tmp = localDW->b_BlinkState_start;
    if ((localDW->b_BlinkState_prev != tmp) && ((uint32)tmp == On)) {
      localDW->is_SyncTrigger = App_Model_IN_SyncTriggerOn_bjcu;
      *rty_b_SyncAmber = On;
    }
  } else {
    Bool tmp;

    /* case IN_SyncTriggerOn: */
    *rty_b_SyncAmber = On;
    tmp = localDW->b_CmdAmberSync_start;
    if (((localDW->b_CmdAmberSync_prev != tmp) && ((uint32)tmp == Off)) || ((localDW->BlinkState_prev != localDW->BlinkState_start) && ((uint32)localDW->BlinkState_start == BlinkComplete))) {
      localDW->is_SyncTrigger = App_Mode_IN_SyncTriggerOff_put5;
      *rty_b_SyncAmber = Off;
    }
  }

  /* End of Chart: '<S474>/Amber_Sync_Indy' */
}

/*
 * System initialize for atomic system:
 *    '<S474>/IND_Animation_WPC2_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_WPC2_Priority_Flow_Graph'
 */
void IND_Animation_WPC2_Priorit_Init(WPC2PreSyncAct *rty_Var_WPC2PreSyncAct, DW_IND_Animation_WPC2_Priorit_T *localDW)
{
  localDW->is_active_c177_WPC_IND_Animatio = 0U;
  *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;
  localDW->Input_CAN_WPC2IndSyncVal_prev = WPC2IndSyncVal__Default;
  localDW->Input_CAN_WPC2IndSyncVal_start = WPC2IndSyncVal__Default;
}

/*
 * System reset for atomic system:
 *    '<S474>/IND_Animation_WPC2_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_WPC2_Priority_Flow_Graph'
 */
void IND_Animation_WPC2_Priori_Reset(WPC2PreSyncAct *rty_Var_WPC2PreSyncAct, DW_IND_Animation_WPC2_Priorit_T *localDW)
{
  localDW->is_active_c177_WPC_IND_Animatio = 0U;
  *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;
  localDW->Input_CAN_WPC2IndSyncVal_prev = WPC2IndSyncVal__Default;
  localDW->Input_CAN_WPC2IndSyncVal_start = WPC2IndSyncVal__Default;
}

/*
 * Output and update for atomic system:
 *    '<S474>/IND_Animation_WPC2_Priority_Flow_Graph'
 *    '<S652>/IND_Animation_WPC2_Priority_Flow_Graph'
 */
void IND_Animation_WPC2_Priority_Flo(WPC2IndSyncVal rtu_Input_CAN_WPC2IndSyncVal, WPC2PreSyncAct *rty_Var_WPC2PreSyncAct, DW_IND_Animation_WPC2_Priorit_T *localDW)
{
  localDW->Input_CAN_WPC2IndSyncVal_prev = localDW->Input_CAN_WPC2IndSyncVal_start;
  localDW->Input_CAN_WPC2IndSyncVal_start = rtu_Input_CAN_WPC2IndSyncVal;

  /* Chart: '<S474>/IND_Animation_WPC2_Priority_Flow_Graph' */
  if ((uint32)localDW->is_active_c177_WPC_IND_Animatio == 0U) {
    localDW->Input_CAN_WPC2IndSyncVal_prev = rtu_Input_CAN_WPC2IndSyncVal;
    localDW->is_active_c177_WPC_IND_Animatio = 1U;
    *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;

    /* 1 */
    if (((uint32)(*rty_Var_WPC2PreSyncAct) == WPC2PreSyncAct_Off) && ((localDW->Input_CAN_WPC2IndSyncVal_prev != localDW->Input_CAN_WPC2IndSyncVal_start) && ((uint32)
          localDW->Input_CAN_WPC2IndSyncVal_prev == WPC2IndSyncVal__Default)) && (localDW->Input_CAN_WPC2IndSyncVal_prev != localDW->Input_CAN_WPC2IndSyncVal_start)) {
      *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_On;

      /* 1 */
    } else if (((uint32)(*rty_Var_WPC2PreSyncAct) == WPC2PreSyncAct_On) && ((localDW->Input_CAN_WPC2IndSyncVal_prev != localDW->Input_CAN_WPC2IndSyncVal_start) && ((uint32)
                 localDW->Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__Default))) {
      *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;
    } else {
      /* no actions */
    }

    /* 1 */
  } else if (((uint32)(*rty_Var_WPC2PreSyncAct) == WPC2PreSyncAct_Off) && ((localDW->Input_CAN_WPC2IndSyncVal_prev != localDW->Input_CAN_WPC2IndSyncVal_start) && ((uint32)
               localDW->Input_CAN_WPC2IndSyncVal_prev == WPC2IndSyncVal__Default)) && (localDW->Input_CAN_WPC2IndSyncVal_prev != localDW->Input_CAN_WPC2IndSyncVal_start)) {
    *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_On;

    /* 1 */
  } else if (((uint32)(*rty_Var_WPC2PreSyncAct) == WPC2PreSyncAct_On) && ((localDW->Input_CAN_WPC2IndSyncVal_prev != localDW->Input_CAN_WPC2IndSyncVal_start) && ((uint32)
               localDW->Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__Default))) {
    *rty_Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;
  } else {
    /* no actions */
  }

  /* End of Chart: '<S474>/IND_Animation_WPC2_Priority_Flow_Graph' */
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDLight(void)
{
  switch (App_Model_DW.is_INDLight_ajwi) {
   case App_Model_IN_INDLight_Off:
    if (App_Model_DW.sfEvent_oqhy == (sint32)App_M_event_StartTimer_INDLight) {
      App_Model_DW.is_INDLight_ajwi = App_Model_IN_INDLight_On;
    }
    break;

   case App_Model_IN_INDLight_On:
    {
      switch (App_Model_DW.sfEvent_oqhy) {
       case App__event_CancelTimer_INDLight:
        App_Model_DW.is_INDLight_ajwi = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight_jkqo = 0U;
        break;

       case App_M_event_StartTimer_INDLight:
        App_Model_DW.Timer_INDLight_jkqo = 0U;
        App_Model_DW.is_INDLight_ajwi = App_Model_IN_INDLight_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDLight_jkqo + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDLight_jkqo + 1U) < App_Model_DW.Timer_INDLight_jkqo) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDLight_jkqo = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeIn(void)
{
  switch (App_Model_DW.is_INDFadeIn_jkbd) {
   case App_Model_IN_INDFadeIn_Off:
    if (App_Model_DW.sfEvent_oqhy == (sint32)App__event_StartTimer_INDFadeIn) {
      App_Model_DW.is_INDFadeIn_jkbd = App_Model_IN_INDFadeIn_On;
    }
    break;

   case App_Model_IN_INDFadeIn_On:
    {
      switch (App_Model_DW.sfEvent_oqhy) {
       case App_event_CancelTimer_INDFadeIn:
        App_Model_DW.is_INDFadeIn_jkbd = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_bp2v = 0U;
        break;

       case App__event_StartTimer_INDFadeIn:
        App_Model_DW.Timer_INDFadeIn_bp2v = 0U;
        App_Model_DW.is_INDFadeIn_jkbd = App_Model_IN_INDFadeIn_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeIn_bp2v + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeIn_bp2v + 1U) < App_Model_DW.Timer_INDFadeIn_bp2v) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeIn_bp2v = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimationCh(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_pkee) {
   case IN_WPCINDAnimationCharging_1stF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_pkee = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPCINDAnimationCharging_1stO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_pkee = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_asoc(void)
{
  /* DataTypeConversion: '<S430>/Data Type Conversion60' */
  /* 1 */
  if (((uint32)App_Model_B.INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)App_Model_B.Var_RWPCIndCmdState_mh2c == RWPCIndCmdState__2ndChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPCINDAnimationCharging_lvlw = IN_WPCINDAnimationCharging_2ndO;
    c_previousEvent = App_Model_DW.sfEvent_oqhy;
    App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oqhy = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__2ndChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       [Var_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn] */
    App_Model_DW.is_WPCINDAnimationCharging_lvlw = IN_WPCINDAnimationCharging_2ndF;
    c_previousEvent = App_Model_DW.sfEvent_oqhy;
    App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
      App_Model_INDLight();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
      App_Model_INDFadeIn();
    }

    App_Model_DW.sfEvent_oqhy = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__2ndChrgFadeIn;
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion60' */
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_drkg(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_lvlw) {
   case IN_WPCINDAnimationCharging_2ndF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_lvlw = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPCINDAnimationCharging_2ndO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_lvlw = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPCINDAnimationCha(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oqhy;
  App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
    App_Model_INDLight();
  }

  /* CancelTimer추가 221219 */
  App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
    App_Model_INDFadeIn();
  }

  App_Model_DW.sfEvent_oqhy = b_previousEvent;
  App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__3rdChrgFadeIn;
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_d4ui(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_aj4v) {
   case IN_WPCINDAnimationCharging_3rdF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_aj4v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPCINDAnimationCharging_3rdO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_aj4v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeOut(void)
{
  switch (App_Model_DW.is_INDFadeOut_crlr) {
   case App_Model_IN_INDFadeOut_Off:
    if (App_Model_DW.sfEvent_oqhy == (sint32)App_event_StartTimer_INDFadeOut) {
      App_Model_DW.is_INDFadeOut_crlr = App_Model_IN_INDFadeOut_On;
    }
    break;

   case App_Model_IN_INDFadeOut_On:
    {
      switch (App_Model_DW.sfEvent_oqhy) {
       case Ap_event_CancelTimer_INDFadeOut:
        App_Model_DW.is_INDFadeOut_crlr = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_bvej = 0U;
        break;

       case App_event_StartTimer_INDFadeOut:
        App_Model_DW.Timer_INDFadeOut_bvej = 0U;
        App_Model_DW.is_INDFadeOut_crlr = App_Model_IN_INDFadeOut_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeOut_bvej + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeOut_bvej + 1U) < App_Model_DW.Timer_INDFadeOut_bvej) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeOut_bvej = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_bs12(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oqhy;
  App_Model_DW.sfEvent_oqhy = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
    App_Model_INDFadeOut();
  }

  App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
    App_Model_INDLight();
  }

  App_Model_DW.sfEvent_oqhy = b_previousEvent;

  /* 230328 */
  App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ChrgFadeOut;

  /* 230328 */
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_jyb3(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oqhy;
  App_Model_DW.sfEvent_oqhy = (sint32)Ap_event_CancelTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
    App_Model_INDFadeOut();
  }

  App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
    App_Model_INDLight();
  }

  App_Model_DW.sfEvent_oqhy = b_previousEvent;
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_mdgj(void)
{
  /* DataTypeConversion: '<S430>/Data Type Conversion60' */
  /* 1 */
  if (((uint32)App_Model_B.INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)App_Model_B.Var_RWPCIndCmdState_mh2c == RWPCIndCmdState__1stChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPCINDAnimationCharging_pkee = IN_WPCINDAnimationCharging_1stO;
    c_previousEvent = App_Model_DW.sfEvent_oqhy;
    App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oqhy = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__1stChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       [Var_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn ||Var_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut] */
    App_Model_DW.is_WPCINDAnimationCharging_pkee = IN_WPCINDAnimationCharging_1stF;
    c_previousEvent = App_Model_DW.sfEvent_oqhy;
    App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
      App_Model_INDLight();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
      App_Model_INDFadeIn();
    }

    App_Model_DW.sfEvent_oqhy = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__1stChrgFadeIn;
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion60' */
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_TypeCont(void)
{
  /* DataTypeConversion: '<S430>/Data Type Conversion53' */
  /* 1 */
  if ((uint32)App_Model_B.INT_WPCIndUSMState != WPCIndUSMState__Type2) {
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeOut;
  } else {
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeIn;
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion53' */
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void WPCINDAnimationCharging_Active(const PreSyncAct *INT_PreSyncAct_WPC1)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_gru2) {
   case IN_WPCINDAnimationCharging_1stS:
    {
      /* 2. Transition start point move to 1stOn */
      if (App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimationCh();
        k_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oqhy = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_2ndS;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__2ndSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnima_asoc();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_pkee == IN_WPCINDAnimationCharging_1stF) {
        /* 1 */
        if (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.is_WPCINDAnimationCharging_pkee = IN_WPCINDAnimationCharging_1stO;
          App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oqhy = k_previousEvent;
          App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__1stChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPCINDAnimationCharging_2ndS:
    {
      /* 2.Transition start point move to 2ndOn */
      if (App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimat_drkg();
        k_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oqhy = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_3rdS;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__3rdSync;

        /* CancelTimer추가 221216 */
        App_Model_DW.is_WPCINDAnimationCharging_aj4v = IN_WPCINDAnimationCharging_3rdF;
        enter_atomic_WPCINDAnimationCha();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_lvlw == IN_WPCINDAnimationCharging_2ndF) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.is_WPCINDAnimationCharging_lvlw = IN_WPCINDAnimationCharging_2ndO;
          App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oqhy = k_previousEvent;
          App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__2ndChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPCINDAnimationCharging_3rdS:
    {
      /* 2.  */
      if (App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;

        /* [Timer_INDFadeOut >= Par_INDFadeOutTime] */
        exit_internal_WPCINDAnimat_d4ui();
        k_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_Off;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oqhy = k_previousEvent;

        /* CancelTimer추가 230103 */
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Off;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnima_bs12();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_aj4v == IN_WPCINDAnimationCharging_3rdF) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.is_WPCINDAnimationCharging_aj4v = IN_WPCINDAnimationCharging_3rdO;
          App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oqhy = k_previousEvent;
          App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__3rdChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPCINDAnimationCharging_Off:
    {
      /* Update for Merge generated from: '<S25>/Merge' incorporates:
       *  DataTypeConversion: '<S430>/Data Type Conversion68'
       */
      /* 1 */
      if ((App_Model_DW.Timer_INDFadeOut_bvej >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.C_WPCWarning_dbwe == Charging_error)) {
        sint32 k_previousEvent;

        /*  ||Input_WPCWarning == NFCCardDetected ) */
        exit_internal_WPCINDAnimat_jyb3();
        k_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

        /* CancelTimer에서 StartTimer로 변경 221216 */
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mo_IN_WPCINDAnimation_Error;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.sfEvent_oqhy = k_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
        App_Model_TypeCont();

        /* 1 */
        switch (*INT_PreSyncAct_WPC1) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreWPC2;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreRWPC;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3 */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_Pr_lvrx;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4 */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_Pr_fbnk;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreNone;
          break;
        }

        /* 3. */
      } else if (App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimat_jyb3();
        k_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oqhy = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_1stS;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__1stSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnima_mdgj();
      } else {
        /* no actions */
      }

      /* End of Update for Merge generated from: '<S25>/Merge' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnimationC(const WPC2IndSyncVal *INT_WPC2IndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC1)
{
  RWPCIndSyncVal tmp;

  /* DataTypeConversion: '<S427>/Data Type Conversion42' */
  /* 1 */
  tmp = App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt;

  /* DataTypeConversion: '<S430>/Data Type Conversion68' incorporates:
   *  DataTypeConversion: '<S430>/Data Type Conversion11'
   *  DataTypeConversion: '<S430>/Data Type Conversion60'
   */
  if (((((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) || ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2RWPC)) && ((uint32)(*INT_WPC2IndSyncVal) == WPC2IndSyncVal__3rdSync)) || ((((uint32)(*
          INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) || ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPCWPC2)) && ((uint32)tmp == RWPCIndSyncVal__3rdSync))) {
    App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_3rdS;
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__3rdSync;

    /* CancelTimer추가 221216 */
    /* 1 */
    if (((uint32)App_Model_B.INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || ((uint32)App_Model_B.Var_RWPCIndCmdState_mh2c == RWPCIndCmdState__3rdChrgOn)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_aj4v = IN_WPCINDAnimationCharging_3rdO;
      b_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
        App_Model_INDLight();
      }

      App_Model_DW.sfEvent_oqhy = b_previousEvent;
      App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__3rdChrgOn;
    } else {
      /* 2
         Var_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn ||
         Var_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn */
      App_Model_DW.is_WPCINDAnimationCharging_aj4v = IN_WPCINDAnimationCharging_3rdF;
      enter_atomic_WPCINDAnimationCha();
    }

    /* 2 */
  } else if (((((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) || ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2RWPC)) && ((uint32)(*INT_WPC2IndSyncVal) == WPC2IndSyncVal__2ndSync)) ||
             ((((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) || ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPCWPC2)) && ((uint32)tmp == RWPCIndSyncVal__2ndSync))) {
    App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_2ndS;
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__2ndSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnima_asoc();

    /* 3 */
  } else if (((((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) || ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2RWPC)) && (((uint32)(*INT_WPC2IndSyncVal) == WPC2IndSyncVal__1stSync) ||
               ((uint32)(*INT_WPC2IndSyncVal) == WPC2IndSyncVal__ErrorOff))) || ((((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) || ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPCWPC2)) &&
              (((uint32)tmp == RWPCIndSyncVal__1stSync) || ((uint32)tmp == RWPCIndSyncVal__ErrorOff)))) {
    App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_1stS;
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__1stSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnima_mdgj();
  } else {
    sint32 b_previousEvent;

    /* 4 */
    App_Model_DW.is_WPCINDAnimationCharging_gru2 = IN_WPCINDAnimationCharging_Off;
    b_previousEvent = App_Model_DW.sfEvent_oqhy;
    App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oqhy = b_previousEvent;

    /* CancelTimer추가 230103 */
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Off;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnima_bs12();
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion68' */
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPCINDAnimationErr(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oqhy;
  App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
    App_Model_INDFadeIn();
  }

  App_Model_DW.sfEvent_oqhy = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
    App_Model_INDFadeOut();
  }

  App_Model_DW.sfEvent_oqhy = b_previousEvent;
  App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOff;
  App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeOut;
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDErrorOnOut(void)
{
  /* 1 */
  if (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) {
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorOn;
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_WPCINDAnimation_Error(const PreSyncAct *INT_PreSyncAct_WPC1)
{
  if ((App_Model_DW.b_SyncAmber_prev_h2yl != App_Model_DW.b_SyncAmber_start_hpuj) && ((uint32)App_Model_DW.b_SyncAmber_start_hpuj == Off)) {
    sint32 h_previousEvent;
    switch (App_Model_DW.is_WPCINDAnimation_Error_fh0i) {
     case App_IN_WPCINDAnimationError_Off:
      h_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)Ap_event_CancelTimer_INDFadeOut;
      if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
        App_Model_INDFadeOut();
      }

      App_Model_DW.sfEvent_oqhy = h_previousEvent;
      App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     case App__IN_WPCINDAnimationError_On:
      h_previousEvent = App_Model_DW.sfEvent_oqhy;
      App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
        App_Model_INDFadeIn();
      }

      App_Model_DW.sfEvent_oqhy = h_previousEvent;
      App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     default:
      App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;
    }

    /* 231218
       Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
    h_previousEvent = App_Model_DW.sfEvent_oqhy;
    App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
      App_Model_INDFadeIn();
    }

    App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mod_IN_WPCINDAnimation_Init;
    App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
      App_Model_INDLight();
    }

    App_Model_DW.sfEvent_oqhy = h_previousEvent;
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
  } else {
    switch (App_Model_DW.is_WPCINDAnimation_Error_fh0i) {
     case App_IN_WPCINDAnimationError_Off:
      {
        C_WPCWarning tmp_1;
        WPCIndUSMState tmp_0;

        /* DataTypeConversion: '<S430>/Data Type Conversion53' */
        /* 2 */
        tmp_0 = App_Model_B.INT_WPCIndUSMState;

        /* Update for Merge generated from: '<S25>/Merge' */
        tmp_1 = App_Model_B.C_WPCWarning_dbwe;
        if (((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_bvej >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
              (App_Model_DW.Timer_INDFadeOut_bvej >= (uint32)((uint8)50U)))) && (((uint32)tmp_1 == WPCWarningOff) || ((uint32)tmp_1 == PhoneCharging) || ((uint32)tmp_1 == Charging_Complete) ||
             ((uint32)tmp_1 == Cellphoneonthepad) || ((uint32)tmp_1 == Cellphonereminder) || ((uint32)tmp_1 == WarningInvalid))) {
          sint32 h_previousEvent;

          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
            App_Model_INDFadeOut();
          }

          App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

          /* 231218
             Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
          App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mod_IN_WPCINDAnimation_Init;
          App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oqhy = h_previousEvent;
          App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
          App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
        } else if ((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_bvej >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
                    (App_Model_DW.Timer_INDFadeOut_bvej >= (uint32)((uint8)50U)))) {
          sint32 h_previousEvent;

          /* 231218 */
          h_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
            App_Model_INDFadeOut();
          }

          App_Model_DW.is_WPCINDAnimation_Error_fh0i = App__IN_WPCINDAnimationError_On;
          App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.sfEvent_oqhy = h_previousEvent;
          App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
          App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeIn;
        } else {
          /* Input_WPCWarning == Charging_error &&... */
        }
      }
      break;

     case App__IN_WPCINDAnimationError_On:
      {
        WPCIndUSMState tmp_0;

        /* DataTypeConversion: '<S430>/Data Type Conversion53' */
        tmp_0 = App_Model_B.INT_WPCIndUSMState;
        if ((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
             (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)50U)))) {
          sint32 h_previousEvent;

          /* 231218 */
          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
            App_Model_INDFadeIn();
          }

          App_Model_DW.sfEvent_oqhy = h_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimationErr();
        } else {
          /* Input_WPCWarning == Charging_error &&... */
        }
      }
      break;

     case IN_WPCINDAnimationError_PreNone:
      /* DataTypeConversion: '<S430>/Data Type Conversion53' */
      /* 1 */
      if (((uint32)App_Model_B.INT_WPCIndUSMState != WPCIndUSMState__Type2) || (App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U))) {
        /* 231218 */
        App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_IN_WPCINDAnimationError_Off;
        enter_atomic_WPCINDAnimationErr();
      }
      break;

     case IN_WPCINDAnimationError_PreRWPC:
      {
        PreSyncAct tmp;
        tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
        if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreNone;
        } else {
          WPCIndUSMState tmp_0;

          /* DataTypeConversion: '<S430>/Data Type Conversion53' */
          /* 2 */
          tmp_0 = App_Model_B.INT_WPCIndUSMState;

          /* DataTypeConversion: '<S430>/Data Type Conversion68' */
          if (((App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__1stChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc ==
                  RWPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) &&
                 ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 !=
                WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc ==
                 RWPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_IN_WPCINDAnimationError_Off;
            enter_atomic_WPCINDAnimationErr();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)
                       App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App__IN_WPCINDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
              App_Model_INDFadeIn();
            }

            App_Model_DW.sfEvent_oqhy = h_previousEvent;
            App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_Pr_lvrx:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
        if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreNone;

          /* DataTypeConversion: '<S430>/Data Type Conversion68' incorporates:
           *  DataTypeConversion: '<S430>/Data Type Conversion53'
           */
          /* 2 */
        } else if ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) {
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreWPC2;
        } else {
          WPCIndUSMState tmp_0;

          /* 3  */
          tmp_0 = App_Model_B.INT_WPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPCWPC2) && (((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__1stChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc ==
                  RWPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) &&
                 ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 !=
                WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc ==
                 RWPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_IN_WPCINDAnimationError_Off;
            enter_atomic_WPCINDAnimationErr();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc) && ((uint32)
                       App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc == RWPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App__IN_WPCINDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
              App_Model_INDFadeIn();
            }

            App_Model_DW.sfEvent_oqhy = h_previousEvent;
            App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_PreWPC2:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
        if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreNone;
        } else {
          WPCIndUSMState tmp_0;

          /* DataTypeConversion: '<S430>/Data Type Conversion53' */
          /* 2  */
          tmp_0 = App_Model_B.INT_WPCIndUSMState;

          /* DataTypeConversion: '<S430>/Data Type Conversion68' */
          if (((App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) && (((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 !=
                  App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__1stChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz ==
                  WPC2IndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)
                  App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) &&
                 ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 !=
                  App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 !=
                WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz ==
                 WPC2IndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_IN_WPCINDAnimationError_Off;
            enter_atomic_WPCINDAnimationErr();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)
                       App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App__IN_WPCINDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
              App_Model_INDFadeIn();
            }

            App_Model_DW.sfEvent_oqhy = h_previousEvent;
            App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_Pr_fbnk:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
        if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreNone;

          /* DataTypeConversion: '<S430>/Data Type Conversion68' incorporates:
           *  DataTypeConversion: '<S430>/Data Type Conversion53'
           */
          /* 2 */
        } else if ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) {
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreRWPC;
        } else {
          WPCIndUSMState tmp_0;

          /* 3 */
          tmp_0 = App_Model_B.INT_WPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn_bp2v >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2RWPC) && (((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 !=
                  App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__1stChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz ==
                  WPC2IndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)
                  App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) &&
                 ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 !=
                  App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 !=
                WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz ==
                 WPC2IndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_IN_WPCINDAnimationError_Off;
            enter_atomic_WPCINDAnimationErr();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz) && ((uint32)
                       App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz == WPC2IndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPCINDAnimation_Error_fh0i = App__IN_WPCINDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
              App_Model_INDFadeIn();
            }

            App_Model_DW.sfEvent_oqhy = h_previousEvent;
            App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut();
          }
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void IND_Animation_Sync_Control_Func(const WPC2IndSyncVal *INT_WPC2IndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC1)
{
  switch (App_Model_DW.is_IND_Animation_Sync_Cont_mfvz) {
   case App_IN_WPCINDAnimation_Charging:
    {
      /* Update for Merge generated from: '<S25>/Merge' incorporates:
       *  DataTypeConversion: '<S430>/Data Type Conversion68'
       */
      if (((App_Model_DW.WPCIndUSMState_prev_mwgm != App_Model_DW.WPCIndUSMState_start_cume) && ((uint32)App_Model_DW.WPCIndUSMState_start_cume == WPCIndUSMState__Type1)) || ((uint32)
           App_Model_B.C_WPCWarning_dbwe != PhoneCharging)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        if ((uint32)App_Model_DW.is_WPCINDAnimation_Chargin_kod1 == IN_WPCINDAnimationCharging_Acti) {
          switch (App_Model_DW.is_WPCINDAnimationCharging_gru2) {
           case IN_WPCINDAnimationCharging_1stS:
            exit_internal_WPCINDAnimationCh();
            g_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oqhy = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_2ndS:
            exit_internal_WPCINDAnimat_drkg();
            g_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oqhy = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_3rdS:
            exit_internal_WPCINDAnimat_d4ui();
            g_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oqhy = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_Off:
            exit_internal_WPCINDAnimat_jyb3();
            g_previousEvent = App_Model_DW.sfEvent_oqhy;
            App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
              App_Model_INDLight();
            }

            App_Model_DW.sfEvent_oqhy = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           default:
            /* no actions */
            break;
          }

          /* CancelTimer에서 StartTimer로 변경 221216 */
          g_previousEvent = App_Model_DW.sfEvent_oqhy;
          App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
            App_Model_INDLight();
          }

          App_Model_DW.sfEvent_oqhy = g_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        } else {
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        }

        g_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mod_IN_WPCINDAnimation_Init;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oqhy = g_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
        App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
      } else {
        switch (App_Model_DW.is_WPCINDAnimation_Chargin_kod1) {
         case IN_WPCINDAnimationCharging_Acti:
          WPCINDAnimationCharging_Active(INT_PreSyncAct_WPC1);
          break;

         case IN_WPCINDAnimationCharging_PreN:
          {
            /* 1 */
            if (App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oqhy;
              App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oqhy = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(INT_WPC2IndSyncVal, INT_PreSyncAct_WPC1);
            }
          }
          break;

         case IN_WPCINDAnimationCharging_PreR:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
            if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if ((App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_p_pwgh !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_s_nnsr) || (App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oqhy;
              App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oqhy = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(INT_WPC2IndSyncVal, INT_PreSyncAct_WPC1);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPCINDAnimationCharging_i0ou:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
            if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) {
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreW;

              /* 3  */
            } else if ((App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPCWPC2) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_p_pwgh !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_s_nnsr) || (App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg != App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oqhy;
              App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oqhy = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(INT_WPC2IndSyncVal, INT_PreSyncAct_WPC1);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPCINDAnimationCharging_PreW:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
            if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreN;

              /* 2  */
            } else if ((App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_c3v4 !=
                         App_Model_DW.Input_CAN_WPC2IndSyncVal_s_pfdf) || (App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oqhy;
              App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oqhy = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(INT_WPC2IndSyncVal, INT_PreSyncAct_WPC1);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPCINDAnimationCharging_puay:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_b2ke;
            if ((App_Model_DW.Var_PreSyncAct_prev_nho5 != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__RWPC) {
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreR;

              /* 3 */
            } else if ((App_Model_DW.Timer_INDLight_jkqo >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC1) == PreSyncAct__WPC2RWPC) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_c3v4 !=
                         App_Model_DW.Input_CAN_WPC2IndSyncVal_s_pfdf) || (App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 != App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_oqhy;
              App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
                App_Model_INDLight();
              }

              App_Model_DW.sfEvent_oqhy = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnimationC(INT_WPC2IndSyncVal, INT_PreSyncAct_WPC1);
            } else {
              /* no actions */
            }
          }
          break;

         default:
          /* no actions */
          break;
        }
      }
    }
    break;

   case App_Mo_IN_WPCINDAnimation_Error:
    App_Model_WPCINDAnimation_Error(INT_PreSyncAct_WPC1);
    break;

   case App_Mod_IN_WPCINDAnimation_Init:
    {
      C_WPCWarning tmp_0;

      /* Update for Merge generated from: '<S25>/Merge' */
      /* 2 */
      tmp_0 = App_Model_B.C_WPCWarning_dbwe;

      /* DataTypeConversion: '<S430>/Data Type Conversion53' incorporates:
       *  DataTypeConversion: '<S430>/Data Type Conversion65'
       *  DataTypeConversion: '<S430>/Data Type Conversion68'
       */
      if (((uint32)tmp_0 == PhoneCharging) && ((uint32)App_Model_B.INT_WPCIndUSMState == WPCIndUSMState__Type2)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_IN_WPCINDAnimation_Charging;
        g_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App_M_event_StartTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        App_Model_DW.sfEvent_oqhy = g_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__3rdSync;
        App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__3rdChrgOn;

        /* 1
           [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC2)]%230102 */
        switch (*INT_PreSyncAct_WPC1) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreW;
          break;

         case PreSyncAct__RWPC:
          /* 2
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPC)] */
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreR;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPCWPC2)]%230109 */
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_i0ou;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC2RWPC)] */
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_puay;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = IN_WPCINDAnimationCharging_PreN;
          break;
        }

        /* 2 */
      } else if (((uint32)tmp_0 == Charging_error) && ((uint32)App_Model_B.INT_b_SyncLED_WPC1 == On)) {
        sint32 g_previousEvent;
        App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mo_IN_WPCINDAnimation_Error;
        g_previousEvent = App_Model_DW.sfEvent_oqhy;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
          App_Model_INDFadeIn();
        }

        App_Model_DW.sfEvent_oqhy = g_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__ErrorOn;
        App_Model_TypeCont();

        /* 1 */
        switch (*INT_PreSyncAct_WPC1) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreWPC2;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreRWPC;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3 */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_Pr_lvrx;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4 */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_Pr_fbnk;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Error_fh0i = IN_WPCINDAnimationError_PreNone;
          break;
        }
      } else {
        /* no actions */
      }

      /* End of DataTypeConversion: '<S430>/Data Type Conversion53' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDLight_idce(void)
{
  switch (App_Model_DW.is_INDLight_jzsv) {
   case App_Model_IN_INDLight2_Off:
    if (App_Model_DW.sfEvent_j1hu == (sint32)App_M_event_StartTimer_INDLight) {
      App_Model_DW.is_INDLight_jzsv = App_Model_IN_INDLight2_On;
    }
    break;

   case App_Model_IN_INDLight2_On:
    {
      switch (App_Model_DW.sfEvent_j1hu) {
       case App__event_CancelTimer_INDLight:
        App_Model_DW.is_INDLight_jzsv = App_Model_IN_INDLight2_Off;
        App_Model_DW.Timer_INDLight_pm1y = 0U;
        break;

       case App_M_event_StartTimer_INDLight:
        App_Model_DW.Timer_INDLight_pm1y = 0U;
        App_Model_DW.is_INDLight_jzsv = App_Model_IN_INDLight2_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDLight_pm1y + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDLight_pm1y + 1U) < App_Model_DW.Timer_INDLight_pm1y) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDLight_pm1y = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeIn_dns5(void)
{
  switch (App_Model_DW.is_INDFadeIn_gyzm) {
   case App_Model_IN_INDFadeIn_Off:
    if (App_Model_DW.sfEvent_j1hu == (sint32)App__event_StartTimer_INDFadeIn) {
      App_Model_DW.is_INDFadeIn_gyzm = App_Model_IN_INDFadeIn_On;
    }
    break;

   case App_Model_IN_INDFadeIn_On:
    {
      switch (App_Model_DW.sfEvent_j1hu) {
       case App_event_CancelTimer_INDFadeIn:
        App_Model_DW.is_INDFadeIn_gyzm = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_kzsy = 0U;
        break;

       case App__event_StartTimer_INDFadeIn:
        App_Model_DW.Timer_INDFadeIn_kzsy = 0U;
        App_Model_DW.is_INDFadeIn_gyzm = App_Model_IN_INDFadeIn_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeIn_kzsy + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeIn_kzsy + 1U) < App_Model_DW.Timer_INDFadeIn_kzsy) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeIn_kzsy = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPC2INDAnimationC(void)
{
  switch (App_Model_DW.is_WPC2INDAnimationCharging_1st) {
   case IN_WPC2INDAnimationChargin_cxay:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
        App_Model_INDFadeIn_dns5();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPC2INDAnimationChargin_m5iw:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
        App_Model_INDLight_idce();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnim_dz4n(void)
{
  /* DataTypeConversion: '<S430>/Data Type Conversion9' */
  /* 1 */
  if (((uint32)App_Model_B.INT_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)App_Model_B.Var_RWPCIndCmdState == RWPCIndCmdState__2ndChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPC2INDAnimationCharging_2nd = IN_WPC2INDAnimationChargin_j0nd;
    c_previousEvent = App_Model_DW.sfEvent_j1hu;
    App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
      App_Model_INDLight_idce();
    }

    App_Model_DW.sfEvent_j1hu = c_previousEvent;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       Input_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn ||
       Var_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn */
    App_Model_DW.is_WPC2INDAnimationCharging_2nd = IN_WPC2INDAnimationChargin_anqt;
    c_previousEvent = App_Model_DW.sfEvent_j1hu;
    App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
      App_Model_INDLight_idce();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
      App_Model_INDFadeIn_dns5();
    }

    App_Model_DW.sfEvent_j1hu = c_previousEvent;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion9' */
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPC2INDAnima_cw2f(void)
{
  switch (App_Model_DW.is_WPC2INDAnimationCharging_2nd) {
   case IN_WPC2INDAnimationChargin_anqt:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
        App_Model_INDFadeIn_dns5();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPC2INDAnimationChargin_j0nd:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
        App_Model_INDLight_idce();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPC2INDAnimationCh(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_j1hu;
  App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
    App_Model_INDLight_idce();
  }

  /* CancelTimer추가 221219 */
  App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
    App_Model_INDFadeIn_dns5();
  }

  App_Model_DW.sfEvent_j1hu = b_previousEvent;
  App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgFadeIn;
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeOut_gkqv(void)
{
  switch (App_Model_DW.is_INDFadeOut_pilc) {
   case App_Model_IN_INDFadeOut_Off:
    if (App_Model_DW.sfEvent_j1hu == (sint32)App_event_StartTimer_INDFadeOut) {
      App_Model_DW.is_INDFadeOut_pilc = App_Model_IN_INDFadeOut_On;
    }
    break;

   case App_Model_IN_INDFadeOut_On:
    {
      switch (App_Model_DW.sfEvent_j1hu) {
       case Ap_event_CancelTimer_INDFadeOut:
        App_Model_DW.is_INDFadeOut_pilc = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_cnjl = 0U;
        break;

       case App_event_StartTimer_INDFadeOut:
        App_Model_DW.Timer_INDFadeOut_cnjl = 0U;
        App_Model_DW.is_INDFadeOut_pilc = App_Model_IN_INDFadeOut_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeOut_cnjl + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeOut_cnjl + 1U) < App_Model_DW.Timer_INDFadeOut_cnjl) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeOut_cnjl = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPC2INDAnima_pcyf(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_j1hu;
  App_Model_DW.sfEvent_j1hu = (sint32)Ap_event_CancelTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
    App_Model_INDFadeOut_gkqv();
  }

  App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
    App_Model_INDLight_idce();
  }

  App_Model_DW.sfEvent_j1hu = b_previousEvent;
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnim_amwe(void)
{
  /* DataTypeConversion: '<S430>/Data Type Conversion9' */
  /* 1 */
  if (((uint32)App_Model_B.INT_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)App_Model_B.Var_RWPCIndCmdState == RWPCIndCmdState__1stChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPC2INDAnimationCharging_1st = IN_WPC2INDAnimationChargin_m5iw;
    c_previousEvent = App_Model_DW.sfEvent_j1hu;
    App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
      App_Model_INDLight_idce();
    }

    App_Model_DW.sfEvent_j1hu = c_previousEvent;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       Input_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn ||
       Input_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut ||
       Var_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn ||
       Var_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut] */
    App_Model_DW.is_WPC2INDAnimationCharging_1st = IN_WPC2INDAnimationChargin_cxay;
    c_previousEvent = App_Model_DW.sfEvent_j1hu;
    App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
      App_Model_INDLight_idce();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
      App_Model_INDFadeIn_dns5();
    }

    App_Model_DW.sfEvent_j1hu = c_previousEvent;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion9' */
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_TypeCont_cidw(void)
{
  /* DataTypeConversion: '<S430>/Data Type Conversion53' */
  /* 1 */
  if ((uint32)App_Model_B.INT_WPCIndUSMState != WPCIndUSMState__Type2) {
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;
  } else {
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion53' */
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_mg0m(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_p2e5) {
   case IN_WPC2INDAnimationCharging_3rd:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
        App_Model_INDFadeIn_dns5();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_p2e5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPC2INDAnimationChargin_kr45:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
        App_Model_INDLight_idce();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_p2e5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnim_iqqg(void)
{
  sint32 b_previousEvent;

  /* 1_230104_sync */
  b_previousEvent = App_Model_DW.sfEvent_j1hu;
  App_Model_DW.sfEvent_j1hu = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
    App_Model_INDFadeOut_gkqv();
  }

  App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
    App_Model_INDLight_idce();
  }

  App_Model_DW.sfEvent_j1hu = b_previousEvent;

  /* 230328 */
  App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

  /* 230328 */
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void WPC2INDAnimationCharging_Active(const PreSyncAct *INT_PreSyncAct_WPC2)
{
  switch (App_Model_DW.is_WPC2INDAnimationCharging_Act) {
   case IN_WPC2INDAnimationCharging_1st:
    {
      /* 2. Transition start point move to 1stOn */
      if (App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnimationC();
        k_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.sfEvent_j1hu = k_previousEvent;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_2nd;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__2ndSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPC2INDAnim_dz4n();
      } else if ((uint32)App_Model_DW.is_WPC2INDAnimationCharging_1st == IN_WPC2INDAnimationChargin_cxay) {
        /* 1 */
        if (App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
            App_Model_INDFadeIn_dns5();
          }

          App_Model_DW.is_WPC2INDAnimationCharging_1st = IN_WPC2INDAnimationChargin_m5iw;
          App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
            App_Model_INDLight_idce();
          }

          App_Model_DW.sfEvent_j1hu = k_previousEvent;
          App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPC2INDAnimationCharging_2nd:
    {
      /* 2.Transition start point move to 2ndOn */
      if (App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnima_cw2f();
        k_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.sfEvent_j1hu = k_previousEvent;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPCINDAnimationCharging_eq2h;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__3rdSync;

        /* CancelTimer추가 221216 */
        App_Model_DW.is_WPCINDAnimationCharging_p2e5 = IN_WPC2INDAnimationCharging_3rd;
        enter_atomic_WPC2INDAnimationCh();
      } else if ((uint32)App_Model_DW.is_WPC2INDAnimationCharging_2nd == IN_WPC2INDAnimationChargin_anqt) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
            App_Model_INDFadeIn_dns5();
          }

          App_Model_DW.is_WPC2INDAnimationCharging_2nd = IN_WPC2INDAnimationChargin_j0nd;
          App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
            App_Model_INDLight_idce();
          }

          App_Model_DW.sfEvent_j1hu = k_previousEvent;
          App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPC2INDAnimationCharging_Off:
    {
      /* Update for Merge generated from: '<S220>/Merge' incorporates:
       *  DataTypeConversion: '<S430>/Data Type Conversion69'
       */
      /* 1 */
      if ((App_Model_DW.Timer_INDFadeOut_cnjl >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.C_WPC2Warning == Charging_error)) {
        sint32 k_previousEvent;

        /*  ||Input_WPC2Warning == NFCCardDetected ) */
        exit_internal_WPC2INDAnima_pcyf();
        k_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

        /* CancelTimer에서 StartTimer로 변경 221216 */
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.is_WPC2INDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_M_IN_WPC2INDAnimation_Error;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
          App_Model_INDFadeIn_dns5();
        }

        App_Model_DW.sfEvent_j1hu = k_previousEvent;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
        App_Model_TypeCont_cidw();

        /* 1 */
        switch (*INT_PreSyncAct_WPC2) {
         case PreSyncAct__WPC:
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreWPC;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_Pr_amfy;
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
      } else if (App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPC2INDAnima_pcyf();
        k_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.sfEvent_j1hu = k_previousEvent;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_1st;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__1stSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPC2INDAnim_amwe();
      } else {
        /* no actions */
      }

      /* End of Update for Merge generated from: '<S220>/Merge' */
    }
    break;

   case IN_WPCINDAnimationCharging_eq2h:
    {
      /* 2.  */
      if (App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;

        /* [Timer_INDFadeOut >= Par_INDFadeOutTime] */
        exit_internal_WPCINDAnimat_mg0m();
        k_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_Off;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.sfEvent_j1hu = k_previousEvent;

        /* CancelTimer추가 230103 */
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Off;

        /* CancelTimer추가 221216 */
        enter_internal_WPC2INDAnim_iqqg();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_p2e5 == IN_WPC2INDAnimationCharging_3rd) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
            App_Model_INDFadeIn_dns5();
          }

          App_Model_DW.is_WPCINDAnimationCharging_p2e5 = IN_WPC2INDAnimationChargin_kr45;
          App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
            App_Model_INDLight_idce();
          }

          App_Model_DW.sfEvent_j1hu = k_previousEvent;
          App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPC2INDAnimation(const C_WPCIndSyncVal *INT_WPCIndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC2)
{
  RWPCIndSyncVal tmp;

  /* DataTypeConversion: '<S427>/Data Type Conversion42' */
  /* 1 */
  tmp = App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt;

  /* DataTypeConversion: '<S430>/Data Type Conversion69' incorporates:
   *  DataTypeConversion: '<S430>/Data Type Conversion41'
   *  DataTypeConversion: '<S430>/Data Type Conversion9'
   */
  if (((((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) || ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPCRWPC)) && ((uint32)(*INT_WPCIndSyncVal) == WPCIndSyncVal__3rdSync)) || ((((uint32)
         (*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) || ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPCWPC)) && ((uint32)tmp == RWPCIndSyncVal__3rdSync))) {
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPCINDAnimationCharging_eq2h;
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__3rdSync;

    /* CancelTimer추가 221216 */
    /* 1 */
    if (((uint32)App_Model_B.INT_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)App_Model_B.Var_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_p2e5 = IN_WPC2INDAnimationChargin_kr45;
      b_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
        App_Model_INDLight_idce();
      }

      App_Model_DW.sfEvent_j1hu = b_previousEvent;
      App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
    } else {
      /* 2
         Input_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn ||
         Var_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn */
      App_Model_DW.is_WPCINDAnimationCharging_p2e5 = IN_WPC2INDAnimationCharging_3rd;
      enter_atomic_WPC2INDAnimationCh();
    }

    /* 2 */
  } else if (((((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) || ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPCRWPC)) && ((uint32)(*INT_WPCIndSyncVal) == WPCIndSyncVal__2ndSync)) ||
             ((((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) || ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPCWPC)) && ((uint32)tmp == RWPCIndSyncVal__2ndSync))) {
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_2nd;
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__2ndSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPC2INDAnim_dz4n();

    /* 3 */
  } else if (((((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) || ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPCRWPC)) && (((uint32)(*INT_WPCIndSyncVal) == WPCIndSyncVal__1stSync) || ((uint32)
                (*INT_WPCIndSyncVal) == WPCIndSyncVal__ErrorOff))) || ((((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) || ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPCWPC)) && (((uint32)
                tmp == RWPCIndSyncVal__1stSync) || ((uint32)tmp == RWPCIndSyncVal__ErrorOff)))) {
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_1st;
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__1stSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPC2INDAnim_amwe();
  } else {
    sint32 b_previousEvent;

    /* 4 */
    App_Model_DW.is_WPC2INDAnimationCharging_Act = IN_WPC2INDAnimationCharging_Off;
    b_previousEvent = App_Model_DW.sfEvent_j1hu;
    App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
      App_Model_INDLight_idce();
    }

    App_Model_DW.sfEvent_j1hu = b_previousEvent;

    /* CancelTimer추가 230103 */
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Off;

    /* CancelTimer추가 221216 */
    enter_internal_WPC2INDAnim_iqqg();
  }

  /* End of DataTypeConversion: '<S430>/Data Type Conversion69' */
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPC2INDAnimationEr(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_j1hu;
  App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
    App_Model_INDFadeIn_dns5();
  }

  App_Model_DW.sfEvent_j1hu = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
    App_Model_INDFadeOut_gkqv();
  }

  App_Model_DW.sfEvent_j1hu = b_previousEvent;
  App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOff;
  App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDErrorOnOut_gjix(void)
{
  /* 1 */
  if (App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) {
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorOn;
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Mode_WPC2INDAnimation_Error(const PreSyncAct *INT_PreSyncAct_WPC2)
{
  if ((App_Model_DW.b_SyncAmber_prev_lnzu != App_Model_DW.b_SyncAmber_start_bf1w) && ((uint32)App_Model_DW.b_SyncAmber_start_bf1w == Off)) {
    sint32 h_previousEvent;
    switch (App_Model_DW.is_WPC2INDAnimation_Error) {
     case Ap_IN_WPC2INDAnimationError_Off:
      h_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)Ap_event_CancelTimer_INDFadeOut;
      if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
        App_Model_INDFadeOut_gkqv();
      }

      App_Model_DW.sfEvent_j1hu = h_previousEvent;
      App_Model_DW.is_WPC2INDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     case App_IN_WPC2INDAnimationError_On:
      h_previousEvent = App_Model_DW.sfEvent_j1hu;
      App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
        App_Model_INDFadeIn_dns5();
      }

      App_Model_DW.sfEvent_j1hu = h_previousEvent;
      App_Model_DW.is_WPC2INDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     default:
      App_Model_DW.is_WPC2INDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;
    }

    /* 231218
       Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
    h_previousEvent = App_Model_DW.sfEvent_j1hu;
    App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
      App_Model_INDFadeIn_dns5();
    }

    App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_Mo_IN_WPC2INDAnimation_Init;
    App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
      App_Model_INDLight_idce();
    }

    App_Model_DW.sfEvent_j1hu = h_previousEvent;
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
  } else {
    switch (App_Model_DW.is_WPC2INDAnimation_Error) {
     case Ap_IN_WPC2INDAnimationError_Off:
      {
        C_WPCWarning tmp_0;
        WPCIndUSMState tmp;

        /* DataTypeConversion: '<S430>/Data Type Conversion53' */
        /* 1 */
        tmp = App_Model_B.INT_WPCIndUSMState;

        /* Update for Merge generated from: '<S220>/Merge' */
        tmp_0 = App_Model_B.C_WPC2Warning;
        if (((((uint32)tmp == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_cnjl >= (uint32)((uint8)100U))) || (((uint32)tmp != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_cnjl
               >= (uint32)((uint8)50U)))) && (((uint32)tmp_0 == WPCWarningOff) || ((uint32)tmp_0 == PhoneCharging) || ((uint32)tmp_0 == Charging_Complete) || ((uint32)tmp_0 == Cellphoneonthepad) ||
             ((uint32)tmp_0 == Cellphonereminder) || ((uint32)tmp_0 == WarningInvalid))) {
          sint32 h_previousEvent;

          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
            App_Model_INDFadeOut_gkqv();
          }

          App_Model_DW.is_WPC2INDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

          /* 231218
             Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
          App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
            App_Model_INDFadeIn_dns5();
          }

          App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_Mo_IN_WPC2INDAnimation_Init;
          App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
            App_Model_INDLight_idce();
          }

          App_Model_DW.sfEvent_j1hu = h_previousEvent;
          App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
          App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
        } else if ((((uint32)tmp == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_cnjl >= (uint32)((uint8)100U))) || (((uint32)tmp != WPCIndUSMState__Type2) &&
                    (App_Model_DW.Timer_INDFadeOut_cnjl >= (uint32)((uint8)50U)))) {
          sint32 h_previousEvent;

          /* 231218 */
          h_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
            App_Model_INDFadeOut_gkqv();
          }

          App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
          App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
            App_Model_INDFadeIn_dns5();
          }

          App_Model_DW.sfEvent_j1hu = h_previousEvent;
          App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
          App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
        } else {
          /* Input_WPC2Warning == Charging_error &&... */
        }
      }
      break;

     case App_IN_WPC2INDAnimationError_On:
      {
        WPCIndUSMState tmp;

        /* DataTypeConversion: '<S430>/Data Type Conversion53' */
        tmp = App_Model_B.INT_WPCIndUSMState;
        if ((((uint32)tmp == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U))) || (((uint32)tmp != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn_kzsy >=
              (uint32)((uint8)50U)))) {
          sint32 h_previousEvent;

          /* 231218 */
          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
            App_Model_INDFadeIn_dns5();
          }

          App_Model_DW.sfEvent_j1hu = h_previousEvent;
          App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
          enter_atomic_WPC2INDAnimationEr();
        } else {
          /* Input_WPC2Warning == Charging_error &&... */
        }
      }
      break;

     case IN_WPC2INDAnimationError_PreNon:
      /* DataTypeConversion: '<S430>/Data Type Conversion53' */
      if (((uint32)App_Model_B.INT_WPCIndUSMState != WPCIndUSMState__Type2) || (App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U))) {
        /* 231218 */
        App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
        enter_atomic_WPC2INDAnimationEr();
      }
      break;

     case IN_WPC2INDAnimationError_PreRWP:
      {
        PreSyncAct tmp_1;

        /* 1 */
        tmp_1 = App_Model_DW.Var_PreSyncAct_start_avlx;
        if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp_1) && ((uint32)tmp_1 == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;

          /* DataTypeConversion: '<S430>/Data Type Conversion69' incorporates:
           *  DataTypeConversion: '<S430>/Data Type Conversion53'
           */
          /* 2 */
        } else if ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreWPC;
        } else {
          WPCIndUSMState tmp;

          /* 3  */
          tmp = App_Model_B.INT_WPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPCWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__1stChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh ==
                  RWPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) &&
                 ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp != WPCIndUSMState__Type2)
               && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh ==
                 RWPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
            enter_atomic_WPC2INDAnimationEr();
          } else if (((uint32)tmp != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)
                       App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
              App_Model_INDFadeIn_dns5();
            }

            App_Model_DW.sfEvent_j1hu = h_previousEvent;
            App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_gjix();
          }
        }
      }
      break;

     case IN_WPC2INDAnimationError_PreWPC:
      {
        PreSyncAct tmp_1;

        /* 1 */
        tmp_1 = App_Model_DW.Var_PreSyncAct_start_avlx;
        if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp_1) && ((uint32)tmp_1 == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;

          /* DataTypeConversion: '<S430>/Data Type Conversion69' incorporates:
           *  DataTypeConversion: '<S430>/Data Type Conversion53'
           */
          /* 2 */
        } else if ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_Pr_amfy;
        } else {
          WPCIndUSMState tmp;

          /* 3 */
          tmp = App_Model_B.INT_WPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPCRWPC) && (((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp != WPCIndUSMState__Type2) &&
               ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
            enter_atomic_WPC2INDAnimationEr();
          } else if (((uint32)tmp != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)
                       App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
              App_Model_INDFadeIn_dns5();
            }

            App_Model_DW.sfEvent_j1hu = h_previousEvent;
            App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_gjix();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_Pr_amfy:
      {
        PreSyncAct tmp_1;
        tmp_1 = App_Model_DW.Var_PreSyncAct_start_avlx;
        if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp_1) && ((uint32)tmp_1 == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;
        } else {
          WPCIndUSMState tmp;

          /* DataTypeConversion: '<S430>/Data Type Conversion53' */
          /* 2 */
          tmp = App_Model_B.INT_WPCIndUSMState;

          /* DataTypeConversion: '<S430>/Data Type Conversion69' */
          if (((App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__1stChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh ==
                  RWPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) &&
                 ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp != WPCIndUSMState__Type2)
               && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh ==
                 RWPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
            enter_atomic_WPC2INDAnimationEr();
          } else if (((uint32)tmp != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh) && ((uint32)
                       App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh == RWPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
              App_Model_INDFadeIn_dns5();
            }

            App_Model_DW.sfEvent_j1hu = h_previousEvent;
            App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_gjix();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_PreWPC:
      {
        PreSyncAct tmp_1;

        /* 1 */
        tmp_1 = App_Model_DW.Var_PreSyncAct_start_avlx;
        if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp_1) && ((uint32)tmp_1 == PreSyncAct__Off)) {
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPC2INDAnimationError_PreNon;
        } else {
          WPCIndUSMState tmp;

          /* DataTypeConversion: '<S430>/Data Type Conversion53' */
          /* 2  */
          tmp = App_Model_B.INT_WPCIndUSMState;

          /* DataTypeConversion: '<S430>/Data Type Conversion69' */
          if (((App_Model_DW.Timer_INDFadeIn_kzsy >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) && (((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_INT_WPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp != WPCIndUSMState__Type2) &&
               ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) {
            /* 231218 */
            App_Model_DW.is_WPC2INDAnimation_Error = Ap_IN_WPC2INDAnimationError_Off;
            enter_atomic_WPC2INDAnimationEr();
          } else if (((uint32)tmp != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start) && ((uint32)
                       App_Model_DW.Var_INT_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPC2INDAnimation_Error = App_IN_WPC2INDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
              App_Model_INDFadeIn_dns5();
            }

            App_Model_DW.sfEvent_j1hu = h_previousEvent;
            App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_gjix();
          }
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void IND_Animation_Sync_Control_d4de(const C_WPCIndSyncVal *INT_WPCIndSyncVal, const PreSyncAct *INT_PreSyncAct_WPC2)
{
  switch (App_Model_DW.is_IND_Animation_Sync_Cont_jvqw) {
   case Ap_IN_WPC2INDAnimation_Charging:
    {
      /* Update for Merge generated from: '<S220>/Merge' incorporates:
       *  DataTypeConversion: '<S430>/Data Type Conversion69'
       */
      if (((App_Model_DW.WPCIndUSMState_prev_grnb != App_Model_DW.WPCIndUSMState_start_gcuc) && ((uint32)App_Model_DW.WPCIndUSMState_start_gcuc == WPCIndUSMState__Type1)) || ((uint32)
           App_Model_B.C_WPC2Warning != PhoneCharging)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        if ((uint32)App_Model_DW.is_WPC2INDAnimation_Charging == IN_WPC2INDAnimationCharging_Act) {
          switch (App_Model_DW.is_WPC2INDAnimationCharging_Act) {
           case IN_WPC2INDAnimationCharging_1st:
            exit_internal_WPC2INDAnimationC();
            g_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
              App_Model_INDLight_idce();
            }

            App_Model_DW.sfEvent_j1hu = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPC2INDAnimationCharging_2nd:
            exit_internal_WPC2INDAnima_cw2f();
            g_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
              App_Model_INDLight_idce();
            }

            App_Model_DW.sfEvent_j1hu = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPC2INDAnimationCharging_Off:
            exit_internal_WPC2INDAnima_pcyf();
            g_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
              App_Model_INDLight_idce();
            }

            App_Model_DW.sfEvent_j1hu = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_eq2h:
            exit_internal_WPCINDAnimat_mg0m();
            g_previousEvent = App_Model_DW.sfEvent_j1hu;
            App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
              App_Model_INDLight_idce();
            }

            App_Model_DW.sfEvent_j1hu = g_previousEvent;
            App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           default:
            /* no actions */
            break;
          }

          /* CancelTimer에서 StartTimer로 변경 221216 */
          g_previousEvent = App_Model_DW.sfEvent_j1hu;
          App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
            App_Model_INDLight_idce();
          }

          App_Model_DW.sfEvent_j1hu = g_previousEvent;
          App_Model_DW.is_WPC2INDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        } else {
          App_Model_DW.is_WPC2INDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        }

        g_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_Mo_IN_WPC2INDAnimation_Init;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.sfEvent_j1hu = g_previousEvent;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
        App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
      } else {
        switch (App_Model_DW.is_WPC2INDAnimation_Charging) {
         case IN_WPC2INDAnimationCharging_Act:
          WPC2INDAnimationCharging_Active(INT_PreSyncAct_WPC2);
          break;

         case IN_WPC2INDAnimationCharging_Pre:
          {
            /* 1 */
            if (App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j1hu;
              App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
                App_Model_INDLight_idce();
              }

              App_Model_DW.sfEvent_j1hu = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(INT_WPCIndSyncVal, INT_PreSyncAct_WPC2);
            }
          }
          break;

         case IN_WPC2INDAnimationChargin_mbhl:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_avlx;
            if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2 */
            } else if ((App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_p_dro5 !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_s_gr5w) || (App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j1hu;
              App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
                App_Model_INDLight_idce();
              }

              App_Model_DW.sfEvent_j1hu = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(INT_WPCIndSyncVal, INT_PreSyncAct_WPC2);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPC2INDAnimationChargin_oaxc:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_avlx;
            if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2 */
            } else if ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationChargin_nx4i;

              /* 3  */
            } else if ((App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPCWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_p_dro5 !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_s_gr5w) || (App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk != App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j1hu;
              App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
                App_Model_INDLight_idce();
              }

              App_Model_DW.sfEvent_j1hu = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(INT_WPCIndSyncVal, INT_PreSyncAct_WPC2);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPC2INDAnimationChargin_nx4i:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_avlx;
            if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2  */
            } else if ((App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPC) && ((App_Model_DW.Input_CAN_WPCIndSyncVal_pr_mlsp !=
                         App_Model_DW.Input_CAN_WPCIndSyncVal_st_kruf) || (App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j1hu;
              App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
                App_Model_INDLight_idce();
              }

              App_Model_DW.sfEvent_j1hu = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(INT_WPCIndSyncVal, INT_PreSyncAct_WPC2);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPC2INDAnimationChargin_n2ho:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_avlx;
            if ((App_Model_DW.Var_PreSyncAct_prev_gyza != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;

              /* 2 */
            } else if ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__RWPC) {
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationChargin_mbhl;

              /* 3 */
            } else if ((App_Model_DW.Timer_INDLight_pm1y >= (uint32)((uint8)100U)) && ((uint32)(*INT_PreSyncAct_WPC2) == PreSyncAct__WPCRWPC) && ((App_Model_DW.Input_CAN_WPCIndSyncVal_pr_mlsp !=
                         App_Model_DW.Input_CAN_WPCIndSyncVal_st_kruf) || (App_Model_DW.Var_INT_WPCIndCmdState_prev != App_Model_DW.Var_INT_WPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_j1hu;
              App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
                App_Model_INDLight_idce();
              }

              App_Model_DW.sfEvent_j1hu = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPC2INDAnimation(INT_WPCIndSyncVal, INT_PreSyncAct_WPC2);
            } else {
              /* no actions */
            }
          }
          break;

         default:
          /* no actions */
          break;
        }
      }
    }
    break;

   case App_M_IN_WPC2INDAnimation_Error:
    App_Mode_WPC2INDAnimation_Error(INT_PreSyncAct_WPC2);
    break;

   case App_Mo_IN_WPC2INDAnimation_Init:
    {
      C_WPCWarning tmp_0;

      /* Update for Merge generated from: '<S220>/Merge' */
      /* 2 */
      tmp_0 = App_Model_B.C_WPC2Warning;

      /* DataTypeConversion: '<S430>/Data Type Conversion53' incorporates:
       *  DataTypeConversion: '<S430>/Data Type Conversion67'
       *  DataTypeConversion: '<S430>/Data Type Conversion69'
       */
      if (((uint32)tmp_0 == PhoneCharging) && ((uint32)App_Model_B.INT_WPCIndUSMState == WPCIndUSMState__Type2)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = Ap_IN_WPC2INDAnimation_Charging;
        g_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App_M_event_StartTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        App_Model_DW.sfEvent_j1hu = g_previousEvent;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__3rdSync;
        App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;

        /* 1
           [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC)] */
        switch (*INT_PreSyncAct_WPC2) {
         case PreSyncAct__WPC:
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationChargin_nx4i;
          break;

         case PreSyncAct__RWPC:
          /* 2
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPC)] */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationChargin_mbhl;
          break;

         case PreSyncAct__RWPCWPC:
          /* 3
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__RWPCWPC)] */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationChargin_oaxc;
          break;

         case PreSyncAct__WPCRWPC:
          /* 4
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPCRWPC)] */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationChargin_n2ho;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPC2INDAnimation_Charging = IN_WPC2INDAnimationCharging_Pre;
          break;
        }

        /* 2 */
      } else if (((uint32)tmp_0 == Charging_error) && ((uint32)App_Model_B.INT_b_SyncLED_WPC2 == On)) {
        sint32 g_previousEvent;
        App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_M_IN_WPC2INDAnimation_Error;
        g_previousEvent = App_Model_DW.sfEvent_j1hu;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
          App_Model_INDFadeIn_dns5();
        }

        App_Model_DW.sfEvent_j1hu = g_previousEvent;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__ErrorOn;
        App_Model_TypeCont_cidw();

        /* 1 */
        switch (*INT_PreSyncAct_WPC2) {
         case PreSyncAct__WPC:
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_PreWPC;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPC2INDAnimation_Error = IN_WPCINDAnimationError_Pr_amfy;
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
      } else {
        /* no actions */
      }

      /* End of DataTypeConversion: '<S430>/Data Type Conversion53' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S439>/USM_WPC2_LPCondition' */
static void App_Model_LPConditionHold_bgap(void)
{
  switch (App_Model_DW.is_LPConditionHold_gkga) {
   case App_IN_LPConditionHold_Off_kvlq:
    if (App_Model_DW.sfEvent_px3u == (sint32)event_StartTimer_LPConditi_i0nb) {
      App_Model_DW.is_LPConditionHold_gkga = App__IN_LPConditionHold_On_lcw3;
    }
    break;

   case App__IN_LPConditionHold_On_lcw3:
    {
      switch (App_Model_DW.sfEvent_px3u) {
       case event_CancelTimer_LPCondit_nxtu:
        App_Model_DW.is_LPConditionHold_gkga = App_IN_LPConditionHold_Off_kvlq;
        App_Model_DW.Timer_LPConditionHold_n0a4 = 0U;
        break;

       case event_StartTimer_LPConditi_i0nb:
        App_Model_DW.Timer_LPConditionHold_n0a4 = 0U;
        App_Model_DW.is_LPConditionHold_gkga = App__IN_LPConditionHold_On_lcw3;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPConditionHold_n0a4 + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_LPConditionHold_n0a4 + 1U) < App_Model_DW.Timer_LPConditionHold_n0a4) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPConditionHold_n0a4 = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S439>/USM_WPC2_LPCondition' */
static void App__LPConditionTimerCheck_lfzr(void)
{
  if ((App_Model_DW.m_ProfileGuestWPC2USM_App_prev != App_Model_DW.m_ProfileGuestWPC2USM_App_start) || (App_Model_DW.m_ProfileOneWPC2USM_App_prev != App_Model_DW.m_ProfileOneWPC2USM_App_start) ||
      (App_Model_DW.m_ProfileTwoWPC2USM_App_prev != App_Model_DW.m_ProfileTwoWPC2USM_App_start) || (App_Model_DW.m_ProfileThreeWPC2USM_App_prev != App_Model_DW.m_ProfileThreeWPC2USM_App_start) ||
      (App_Model_DW.m_RWPCUSM_App_prev != App_Model_DW.m_RWPCUSM_App_start)) {
    sint32 c_previousEvent;
    App_Model_DW.ECUResetEnable_pyqo = 0U;
    c_previousEvent = App_Model_DW.sfEvent_px3u;
    App_Model_DW.sfEvent_px3u = (sint32)event_StartTimer_LPConditi_i0nb;
    if ((uint32)App_Model_DW.is_active_LPConditionHold_bwlz != 0U) {
      App_Model_LPConditionHold_bgap();
    }

    App_Model_DW.sfEvent_px3u = c_previousEvent;
  } else if (App_Model_DW.Timer_LPConditionHold_n0a4 >= 100U) {
    sint32 c_previousEvent;

    /* 1s */
    App_Model_DW.ECUResetEnable_pyqo = 1U;
    c_previousEvent = App_Model_DW.sfEvent_px3u;
    App_Model_DW.sfEvent_px3u = (sint32)event_CancelTimer_LPCondit_nxtu;
    if ((uint32)App_Model_DW.is_active_LPConditionHold_bwlz != 0U) {
      App_Model_LPConditionHold_bgap();
    }

    App_Model_DW.sfEvent_px3u = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void App_Model_INDPhaseState_oafg(void)
{
  switch (App_Model_DW.is_INDPhaseState) {
   case App_M_IN_INDPhaseState_Off_bpnu:
    if (App_Model_DW.sfEvent_et4h == (sint32)event_StartTimer_INDPhaseS_a3lh) {
      App_Model_DW.is_INDPhaseState = App_Mo_IN_INDPhaseState_On_bakn;
    }
    break;

   case App_Mo_IN_INDPhaseState_On_bakn:
    {
      switch (App_Model_DW.sfEvent_et4h) {
       case event_CancelTimer_INDPhase_h0ww:
        App_Model_DW.is_INDPhaseState = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState = 0U;
        break;

       case event_StartTimer_INDPhaseS_a3lh:
        App_Model_DW.Timer_INDPhaseState = 0U;
        App_Model_DW.is_INDPhaseState = App_Mo_IN_INDPhaseState_On_bakn;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDPhaseState + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDPhaseState + 1U) < App_Model_DW.Timer_INDPhaseState) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDPhaseState = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdSt_imy0(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_1stSync) {
   case IN_WPC2INDCmdState_1stChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case Ap_IN_WPC2INDCmdState_1stChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdSt_ia4u(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_2ndSync) {
   case IN_WPC2INDCmdState_2ndChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case Ap_IN_WPC2INDCmdState_2ndChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdSt_jbx0(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_3rdSync) {
   case IN_WPC2INDCmdState_3rdChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case Ap_IN_WPC2INDCmdState_3rdChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdSt_ovrz(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_Charging) {
   case App__IN_WPC2INDCmdState_1stSync:
    exit_internal_WPC2INDCmdSt_imy0();
    App_Model_DW.is_WPC2INDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App__IN_WPC2INDCmdState_2ndSync:
    exit_internal_WPC2INDCmdSt_ia4u();
    App_Model_DW.is_WPC2INDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App__IN_WPC2INDCmdState_3rdSync:
    exit_internal_WPC2INDCmdSt_jbx0();
    App_Model_DW.is_WPC2INDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App_Mode_IN_WPC2INDCmdState_Off:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      App_Model_DW.is_WPC2INDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void A_WPC2INDCmdState_Charging_k4jq(void)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndCmdState__Default)) {
    exit_internal_WPC2INDCmdSt_ovrz();
    App_Model_DW.is_WPC2_IND_Command_State_Contr = App__IN_WPC2INDCmdState_Default;
    App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;

    /* 1 */
  } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__ErrorOn)) {
    sint32 h_previousEvent;
    exit_internal_WPC2INDCmdSt_ovrz();
    App_Model_DW.is_WPC2_IND_Command_State_Contr = App_Mo_IN_WPC2INDCmdState_Error;

    /* 1 */
    App_Model_DW.is_WPC2INDCmdState_Error = App__IN_WPC2INDCmdState_ErrorOn;
    h_previousEvent = App_Model_DW.sfEvent_et4h;
    App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
    if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
      App_Model_INDPhaseState_oafg();
    }

    App_Model_DW.sfEvent_et4h = h_previousEvent;
    App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
  } else {
    switch (App_Model_DW.is_WPC2INDCmdState_Charging) {
     case App__IN_WPC2INDCmdState_1stSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_imy0();
          App_Model_DW.is_WPC2INDCmdState_Charging = App_Mode_IN_WPC2INDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_Off = IN_WPC2INDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_imy0();
          App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_2ndSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_2ndSync = IN_WPC2INDCmdState_2ndChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPC2INDCmdState_1stSync) {
           case IN_WPC2INDCmdState_1stChrgFadeI:
            {
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_et4h;
                App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState_oafg();
                }

                App_Model_DW.is_WPC2INDCmdState_1stSync = Ap_IN_WPC2INDCmdState_1stChrgOn;
                App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState_oafg();
                }

                App_Model_DW.sfEvent_et4h = h_previousEvent;
                App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgOn;
              }
            }
            break;

           case Ap_IN_WPC2INDCmdState_1stChrgOn:
            App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App__IN_WPC2INDCmdState_2ndSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_ia4u();
          App_Model_DW.is_WPC2INDCmdState_Charging = App_Mode_IN_WPC2INDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_Off = IN_WPC2INDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__3rdSync)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_ia4u();
          App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_3rdSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_3rdSync = IN_WPC2INDCmdState_3rdChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_ia4u();
          App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_1stSync = IN_WPC2INDCmdState_1stChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPC2INDCmdState_2ndSync) {
           case IN_WPC2INDCmdState_2ndChrgFadeI:
            {
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_et4h;
                App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState_oafg();
                }

                App_Model_DW.is_WPC2INDCmdState_2ndSync = Ap_IN_WPC2INDCmdState_2ndChrgOn;
                App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState_oafg();
                }

                App_Model_DW.sfEvent_et4h = h_previousEvent;
                App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgOn;
              }
            }
            break;

           case Ap_IN_WPC2INDCmdState_2ndChrgOn:
            App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App__IN_WPC2INDCmdState_3rdSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_jbx0();
          App_Model_DW.is_WPC2INDCmdState_Charging = App_Mode_IN_WPC2INDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_Off = IN_WPC2INDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

          /* 2 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_jbx0();
          App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_2ndSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_2ndSync = IN_WPC2INDCmdState_2ndChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdSt_jbx0();
          App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_1stSync = IN_WPC2INDCmdState_1stChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPC2INDCmdState_3rdSync) {
           case IN_WPC2INDCmdState_3rdChrgFadeI:
            {
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_et4h;
                App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState_oafg();
                }

                App_Model_DW.is_WPC2INDCmdState_3rdSync = Ap_IN_WPC2INDCmdState_3rdChrgOn;
                App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                  App_Model_INDPhaseState_oafg();
                }

                App_Model_DW.sfEvent_et4h = h_previousEvent;
                App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
              }
            }
            break;

           case Ap_IN_WPC2INDCmdState_3rdChrgOn:
            App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPC2INDCmdState_Off:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_prev != App_Model_DW.Input_CAN_WPC2IndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_start == WPC2IndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          h_previousEvent = App_Model_DW.sfEvent_et4h;
          App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.is_WPC2INDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
          App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_1stSync = IN_WPC2INDCmdState_1stChrgFadeI;
          App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
            App_Model_INDPhaseState_oafg();
          }

          App_Model_DW.sfEvent_et4h = h_previousEvent;
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
        } else if ((uint32)App_Model_DW.is_WPC2INDCmdState_Off == IN_WPC2INDCmdState_ChrgFadeOut) {
          App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;
        } else {
          /* no actions */
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdSt_arr1(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_Error) {
   case App_IN_WPC2INDCmdState_ErrorOff:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case App__IN_WPC2INDCmdState_ErrorOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_et4h;
      App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
        App_Model_INDPhaseState_oafg();
      }

      App_Model_DW.sfEvent_et4h = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    App_Model_DW.is_WPC2INDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Model_INDPhaseState_mb0u(void)
{
  switch (App_Model_DW.is_INDPhaseState_n5rr) {
   case App_M_IN_INDPhaseState_Off_bpnu:
    if (App_Model_DW.sfEvent_gpvl == (sint32)event_StartTimer_INDPhaseS_a3lh) {
      App_Model_DW.is_INDPhaseState_n5rr = App_Mo_IN_INDPhaseState_On_bakn;
    }
    break;

   case App_Mo_IN_INDPhaseState_On_bakn:
    {
      switch (App_Model_DW.sfEvent_gpvl) {
       case event_CancelTimer_INDPhase_h0ww:
        App_Model_DW.is_INDPhaseState_n5rr = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState_gnkj = 0U;
        break;

       case event_StartTimer_INDPhaseS_a3lh:
        App_Model_DW.Timer_INDPhaseState_gnkj = 0U;
        App_Model_DW.is_INDPhaseState_n5rr = App_Mo_IN_INDPhaseState_On_bakn;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDPhaseState_gnkj + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDPhaseState_gnkj + 1U) < App_Model_DW.Timer_INDPhaseState_gnkj) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDPhaseState_gnkj = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdSt_bh2q(void)
{
  switch (App_Model_DW.is_RWPCINDCmdState_1stSync) {
   case IN_RWPCINDCmdState_1stChrg_ijou:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDCmdState_1stChrg_civ2:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdSt_hnbs(void)
{
  switch (App_Model_DW.is_RWPCINDCmdState_2ndSync) {
   case IN_RWPCINDCmdState_2ndChrg_mmd3:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDCmdState_2ndChrg_dutq:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdSt_bkxq(void)
{
  switch (App_Model_DW.is_RWPCINDCmdState_3rdSync) {
   case IN_RWPCINDCmdState_3rdChrg_heys:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDCmdState_3rdChrg_cla5:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdSt_cozl(void)
{
  switch (App_Model_DW.is_RWPCINDCmdState_Charging) {
   case IN_RWPCINDCmdState_1stSync_lk43:
    exit_internal_RWPCINDCmdSt_bh2q();
    App_Model_DW.is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case IN_RWPCINDCmdState_2ndSync_mtfd:
    exit_internal_RWPCINDCmdSt_hnbs();
    App_Model_DW.is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case IN_RWPCINDCmdState_3rdSync_mj1c:
    exit_internal_RWPCINDCmdSt_bkxq();
    App_Model_DW.is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App_IN_RWPCINDCmdState_Off_e1rc:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      App_Model_DW.is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void A_RWPCINDCmdState_Charging_irrl(void)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndCmdState__Default)) {
    exit_internal_RWPCINDCmdSt_cozl();
    App_Model_DW.is_RWPC_IND_Command_State_Contr = IN_RWPCINDCmdState_Default_kpc4;
    App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;

    /* 1 */
  } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
    sint32 h_previousEvent;
    exit_internal_RWPCINDCmdSt_cozl();
    App_Model_DW.is_RWPC_IND_Command_State_Contr = A_IN_RWPCINDCmdState_Error_jh1y;

    /* 1 */
    App_Model_DW.is_RWPCINDCmdState_Error = IN_RWPCINDCmdState_ErrorOn_ajx4;
    h_previousEvent = App_Model_DW.sfEvent_gpvl;
    App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
    if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
      App_Model_INDPhaseState_mb0u();
    }

    App_Model_DW.sfEvent_gpvl = h_previousEvent;
    App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
  } else {
    switch (App_Model_DW.is_RWPCINDCmdState_Charging) {
     case IN_RWPCINDCmdState_1stSync_lk43:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_bh2q();
          App_Model_DW.is_RWPCINDCmdState_Charging = App_IN_RWPCINDCmdState_Off_e1rc;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFad_auyk;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_bh2q();
          App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_2ndSync_mtfd;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrg_mmd3;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;
        } else {
          switch (App_Model_DW.is_RWPCINDCmdState_1stSync) {
           case IN_RWPCINDCmdState_1stChrg_ijou:
            {
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_gnkj >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_gpvl;
                App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                  App_Model_INDPhaseState_mb0u();
                }

                App_Model_DW.is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrg_civ2;
                App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                  App_Model_INDPhaseState_mb0u();
                }

                App_Model_DW.sfEvent_gpvl = h_previousEvent;
                App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgOn;
              }
            }
            break;

           case IN_RWPCINDCmdState_1stChrg_civ2:
            App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case IN_RWPCINDCmdState_2ndSync_mtfd:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_hnbs();
          App_Model_DW.is_RWPCINDCmdState_Charging = App_IN_RWPCINDCmdState_Off_e1rc;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFad_auyk;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_hnbs();
          App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_3rdSync_mj1c;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_3rdSync = IN_RWPCINDCmdState_3rdChrg_heys;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_hnbs();
          App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_1stSync_lk43;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrg_ijou;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_RWPCINDCmdState_2ndSync) {
           case IN_RWPCINDCmdState_2ndChrg_mmd3:
            {
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_gnkj >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_gpvl;
                App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                  App_Model_INDPhaseState_mb0u();
                }

                App_Model_DW.is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrg_dutq;
                App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                  App_Model_INDPhaseState_mb0u();
                }

                App_Model_DW.sfEvent_gpvl = h_previousEvent;
                App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgOn;
              }
            }
            break;

           case IN_RWPCINDCmdState_2ndChrg_dutq:
            App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case IN_RWPCINDCmdState_3rdSync_mj1c:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_bkxq();
          App_Model_DW.is_RWPCINDCmdState_Charging = App_IN_RWPCINDCmdState_Off_e1rc;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_Off = IN_RWPCINDCmdState_ChrgFad_auyk;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

          /* 2 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_bkxq();
          App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_2ndSync_mtfd;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_2ndSync = IN_RWPCINDCmdState_2ndChrg_mmd3;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_RWPCINDCmdSt_bkxq();
          App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_1stSync_lk43;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrg_ijou;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_RWPCINDCmdState_3rdSync) {
           case IN_RWPCINDCmdState_3rdChrg_heys:
            {
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_gnkj >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_gpvl;
                App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                  App_Model_INDPhaseState_mb0u();
                }

                App_Model_DW.is_RWPCINDCmdState_3rdSync = IN_RWPCINDCmdState_3rdChrg_cla5;
                App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                  App_Model_INDPhaseState_mb0u();
                }

                App_Model_DW.sfEvent_gpvl = h_previousEvent;
                App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
              }
            }
            break;

           case IN_RWPCINDCmdState_3rdChrg_cla5:
            App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_IN_RWPCINDCmdState_Off_e1rc:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          h_previousEvent = App_Model_DW.sfEvent_gpvl;
          App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
          App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_1stSync_lk43;

          /* 1 */
          App_Model_DW.is_RWPCINDCmdState_1stSync = IN_RWPCINDCmdState_1stChrg_ijou;
          App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
            App_Model_INDPhaseState_mb0u();
          }

          App_Model_DW.sfEvent_gpvl = h_previousEvent;
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
        } else if ((uint32)App_Model_DW.is_RWPCINDCmdState_Off == IN_RWPCINDCmdState_ChrgFad_auyk) {
          App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;
        } else {
          /* no actions */
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_RWPCINDCmdSt_jszz(void)
{
  switch (App_Model_DW.is_RWPCINDCmdState_Error) {
   case IN_RWPCINDCmdState_ErrorOf_fcr1:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDCmdState_ErrorOn_ajx4:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gpvl;
      App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
        App_Model_INDPhaseState_mb0u();
      }

      App_Model_DW.sfEvent_gpvl = b_previousEvent;
      App_Model_DW.is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    App_Model_DW.is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDLight_lnkr(void)
{
  switch (App_Model_DW.is_INDLight) {
   case App_Model_IN_INDLight_Off:
    if (App_Model_DW.sfEvent_gygj == (sint32)App_M_event_StartTimer_INDLight) {
      App_Model_DW.is_INDLight = App_Model_IN_INDLight_On;
    }
    break;

   case App_Model_IN_INDLight_On:
    {
      switch (App_Model_DW.sfEvent_gygj) {
       case App__event_CancelTimer_INDLight:
        App_Model_DW.is_INDLight = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight = 0U;
        break;

       case App_M_event_StartTimer_INDLight:
        App_Model_DW.Timer_INDLight = 0U;
        App_Model_DW.is_INDLight = App_Model_IN_INDLight_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDLight + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDLight + 1U) < App_Model_DW.Timer_INDLight) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDLight = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeIn_njia(void)
{
  switch (App_Model_DW.is_INDFadeIn) {
   case App_Model_IN_INDFadeIn_Off:
    if (App_Model_DW.sfEvent_gygj == (sint32)App__event_StartTimer_INDFadeIn) {
      App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_On;
    }
    break;

   case App_Model_IN_INDFadeIn_On:
    {
      switch (App_Model_DW.sfEvent_gygj) {
       case App_event_CancelTimer_INDFadeIn:
        App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn = 0U;
        break;

       case App__event_StartTimer_INDFadeIn:
        App_Model_DW.Timer_INDFadeIn = 0U;
        App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeIn + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeIn + 1U) < App_Model_DW.Timer_INDFadeIn) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeIn = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_pscz(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_1stS) {
   case IN_WPCINDAnimationCharging_1stF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_njia();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_1stS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPCINDAnimationCharging_1stO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_lnkr();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_1stS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_gdyx(void)
{
  /* 1 */
  if (((uint32)App_Model_B.Var_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn) || ((uint32)App_Model_B.Var_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPCINDAnimationCharging_2ndS = IN_WPCINDAnimationCharging_2ndO;
    c_previousEvent = App_Model_DW.sfEvent_gygj;
    App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_lnkr();
    }

    App_Model_DW.sfEvent_gygj = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__2ndChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       [Var_INT_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn] */
    App_Model_DW.is_WPCINDAnimationCharging_2ndS = IN_WPCINDAnimationCharging_2ndF;
    c_previousEvent = App_Model_DW.sfEvent_gygj;
    App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_lnkr();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_njia();
    }

    App_Model_DW.sfEvent_gygj = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__2ndChrgFadeIn;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_nyfq(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_2ndS) {
   case IN_WPCINDAnimationCharging_2ndF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_njia();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_2ndS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPCINDAnimationCharging_2ndO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_lnkr();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_2ndS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPCINDAnimati_gm3x(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_gygj;
  App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
    App_Model_INDLight_lnkr();
  }

  /* CancelTimer추가 221219 */
  App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
    App_Model_INDFadeIn_njia();
  }

  App_Model_DW.sfEvent_gygj = b_previousEvent;
  App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__3rdChrgFadeIn;
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_pktw(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_3rdS) {
   case IN_WPCINDAnimationCharging_3rdF:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_njia();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_WPCINDAnimationCharging_3rdO:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_lnkr();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeOut_ckyy(void)
{
  switch (App_Model_DW.is_INDFadeOut) {
   case App_Model_IN_INDFadeOut_Off:
    if (App_Model_DW.sfEvent_gygj == (sint32)App_event_StartTimer_INDFadeOut) {
      App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_On;
    }
    break;

   case App_Model_IN_INDFadeOut_On:
    {
      switch (App_Model_DW.sfEvent_gygj) {
       case Ap_event_CancelTimer_INDFadeOut:
        App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut = 0U;
        break;

       case App_event_StartTimer_INDFadeOut:
        App_Model_DW.Timer_INDFadeOut = 0U;
        App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeOut + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeOut + 1U) < App_Model_DW.Timer_INDFadeOut) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeOut = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_hvfj(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_gygj;
  App_Model_DW.sfEvent_gygj = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
    App_Model_INDFadeOut_ckyy();
  }

  App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
    App_Model_INDLight_lnkr();
  }

  App_Model_DW.sfEvent_gygj = b_previousEvent;

  /* 230328 */
  App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ChrgFadeOut;

  /* 230328 */
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_WPCINDAnimat_n0kq(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_gygj;
  App_Model_DW.sfEvent_gygj = (sint32)Ap_event_CancelTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
    App_Model_INDFadeOut_ckyy();
  }

  App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
    App_Model_INDLight_lnkr();
  }

  App_Model_DW.sfEvent_gygj = b_previousEvent;
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_om2u(void)
{
  /* 1 */
  if (((uint32)App_Model_B.Var_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn) || ((uint32)App_Model_B.Var_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_WPCINDAnimationCharging_1stS = IN_WPCINDAnimationCharging_1stO;
    c_previousEvent = App_Model_DW.sfEvent_gygj;
    App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_lnkr();
    }

    App_Model_DW.sfEvent_gygj = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__1stChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       [Var_INT_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn ||Var_INT_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn ||Var_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut] */
    App_Model_DW.is_WPCINDAnimationCharging_1stS = IN_WPCINDAnimationCharging_1stF;
    c_previousEvent = App_Model_DW.sfEvent_gygj;
    App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_lnkr();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_njia();
    }

    App_Model_DW.sfEvent_gygj = c_previousEvent;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__1stChrgFadeIn;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_TypeCont_aa4v(void)
{
  /* DataTypeConversion: '<S843>/Data Type Conversion1' */
  /* 1 */
  if ((uint32)App_Model_B.INT_SWPCIndUSMState != WPCIndUSMState__Type2) {
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeOut;
  } else {
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
  }

  /* End of DataTypeConversion: '<S843>/Data Type Conversion1' */
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void WPCINDAnimationCharging_Ac_ecok(void)
{
  switch (App_Model_DW.is_WPCINDAnimationCharging_Acti) {
   case IN_WPCINDAnimationCharging_1stS:
    {
      /* 2. Transition start point move to 1stOn */
      if (App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimat_pscz();
        k_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.sfEvent_gygj = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_2ndS;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__2ndSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnima_gdyx();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_1stS == IN_WPCINDAnimationCharging_1stF) {
        /* 1 */
        if (App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_njia();
          }

          App_Model_DW.is_WPCINDAnimationCharging_1stS = IN_WPCINDAnimationCharging_1stO;
          App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_lnkr();
          }

          App_Model_DW.sfEvent_gygj = k_previousEvent;
          App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__1stChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPCINDAnimationCharging_2ndS:
    {
      /* 2.Transition start point move to 2ndOn */
      if (App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimat_nyfq();
        k_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.sfEvent_gygj = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_3rdS;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__3rdSync;

        /* CancelTimer추가 221216 */
        App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPCINDAnimationCharging_3rdF;
        enter_atomic_WPCINDAnimati_gm3x();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_2ndS == IN_WPCINDAnimationCharging_2ndF) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_njia();
          }

          App_Model_DW.is_WPCINDAnimationCharging_2ndS = IN_WPCINDAnimationCharging_2ndO;
          App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_lnkr();
          }

          App_Model_DW.sfEvent_gygj = k_previousEvent;
          App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__2ndChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPCINDAnimationCharging_3rdS:
    {
      /* 2.  */
      if (App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;

        /* [Timer_INDFadeOut >= Par_INDFadeOutTime] */
        exit_internal_WPCINDAnimat_pktw();
        k_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_Off;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.sfEvent_gygj = k_previousEvent;

        /* CancelTimer추가 230103 */
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Off;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnima_hvfj();
      } else if ((uint32)App_Model_DW.is_WPCINDAnimationCharging_3rdS == IN_WPCINDAnimationCharging_3rdF) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_njia();
          }

          App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPCINDAnimationCharging_3rdO;
          App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_lnkr();
          }

          App_Model_DW.sfEvent_gygj = k_previousEvent;
          App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_WPCINDAnimationCharging_Off:
    {
      /* Update for Merge generated from: '<S642>/Merge' */
      /* 1 */
      if ((App_Model_DW.Timer_INDFadeOut >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.C_WPCWarning_kjwv == Charging_error)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimat_n0kq();
        k_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

        /* CancelTimer에서 StartTimer로 변경 221216 */
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.is_WPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mo_IN_WPCINDAnimation_Error;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_njia();
        }

        App_Model_DW.sfEvent_gygj = k_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
        App_Model_TypeCont_aa4v();

        /* 1 */
        switch (App_Model_B.Var_PreSyncAct) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWPC2;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRWPC;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_Pr_lvrx;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_Pr_fbnk;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
          break;
        }

        /* 3. */
      } else if (App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_WPCINDAnimat_n0kq();
        k_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.sfEvent_gygj = k_previousEvent;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_1stS;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__1stSync;

        /* CancelTimer추가 221216 */
        enter_internal_WPCINDAnima_om2u();
      } else {
        /* no actions */
      }

      /* End of Update for Merge generated from: '<S642>/Merge' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_WPCINDAnima_ddqo(void)
{
  PreSyncAct tmp;
  RWPCIndSyncVal tmp_1;
  WPC2IndSyncVal tmp_0;

  /* 1 */
  tmp = App_Model_B.Var_PreSyncAct;

  /* DataTypeConversion: '<S840>/Data Type Conversion6' */
  tmp_0 = App_Model_B.BCAN_RX_C_WPC2IndSyncVal;

  /* DataTypeConversion: '<S840>/Data Type Conversion42' */
  tmp_1 = App_Model_B.BCAN_RX_C_RWPCIndSyncVal;
  if (((((uint32)tmp == PreSyncAct__WPC2) || ((uint32)tmp == PreSyncAct__WPC2RWPC)) && ((uint32)tmp_0 == WPC2IndSyncVal__3rdSync)) || ((((uint32)tmp == PreSyncAct__RWPC) || ((uint32)tmp ==
         PreSyncAct__RWPCWPC2)) && ((uint32)tmp_1 == RWPCIndSyncVal__3rdSync))) {
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_3rdS;
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__3rdSync;

    /* CancelTimer추가 221216 */
    /* 1 */
    if (((uint32)App_Model_B.Var_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn) || ((uint32)App_Model_B.Var_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgOn)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPCINDAnimationCharging_3rdO;
      b_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
        App_Model_INDLight_lnkr();
      }

      App_Model_DW.sfEvent_gygj = b_previousEvent;
      App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;
    } else {
      /* 2
         Var_INT_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn ||
         Var_INT_RWPCIndCmdState == RWPCIndCmdState__3rdChrgFadeIn */
      App_Model_DW.is_WPCINDAnimationCharging_3rdS = IN_WPCINDAnimationCharging_3rdF;
      enter_atomic_WPCINDAnimati_gm3x();
    }

    /* 2 */
  } else if (((((uint32)tmp == PreSyncAct__WPC2) || ((uint32)tmp == PreSyncAct__WPC2RWPC)) && ((uint32)tmp_0 == WPC2IndSyncVal__2ndSync)) || ((((uint32)tmp == PreSyncAct__RWPC) || ((uint32)tmp ==
                PreSyncAct__RWPCWPC2)) && ((uint32)tmp_1 == RWPCIndSyncVal__2ndSync))) {
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_2ndS;
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__2ndSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnima_gdyx();

    /* 3 */
  } else if (((((uint32)tmp == PreSyncAct__WPC2) || ((uint32)tmp == PreSyncAct__WPC2RWPC)) && (((uint32)tmp_0 == WPC2IndSyncVal__1stSync) || ((uint32)tmp_0 == WPC2IndSyncVal__ErrorOff))) || ((((uint32)
                tmp == PreSyncAct__RWPC) || ((uint32)tmp == PreSyncAct__RWPCWPC2)) && (((uint32)tmp_1 == RWPCIndSyncVal__1stSync) || ((uint32)tmp_1 == RWPCIndSyncVal__ErrorOff)))) {
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_1stS;
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__1stSync;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnima_om2u();
  } else {
    sint32 b_previousEvent;

    /* 4 */
    App_Model_DW.is_WPCINDAnimationCharging_Acti = IN_WPCINDAnimationCharging_Off;
    b_previousEvent = App_Model_DW.sfEvent_gygj;
    App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_lnkr();
    }

    App_Model_DW.sfEvent_gygj = b_previousEvent;

    /* CancelTimer추가 230103 */
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Off;

    /* CancelTimer추가 221216 */
    enter_internal_WPCINDAnima_hvfj();
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_WPCINDAnimati_aqrs(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_gygj;
  App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
    App_Model_INDFadeIn_njia();
  }

  App_Model_DW.sfEvent_gygj = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
    App_Model_INDFadeOut_ckyy();
  }

  App_Model_DW.sfEvent_gygj = b_previousEvent;
  App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOff;
  App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeOut;
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDErrorOnOut_ee43(void)
{
  /* 1 */
  if (App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) {
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorOn;
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App__WPCINDAnimation_Error_lqd0(void)
{
  if ((App_Model_DW.b_SyncAmber_prev != App_Model_DW.b_SyncAmber_start) && ((uint32)App_Model_DW.b_SyncAmber_start == Off)) {
    sint32 h_previousEvent;
    switch (App_Model_DW.is_WPCINDAnimation_Error) {
     case App_IN_WPCINDAnimationError_Off:
      h_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)Ap_event_CancelTimer_INDFadeOut;
      if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
        App_Model_INDFadeOut_ckyy();
      }

      App_Model_DW.sfEvent_gygj = h_previousEvent;
      App_Model_DW.is_WPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     case App__IN_WPCINDAnimationError_On:
      h_previousEvent = App_Model_DW.sfEvent_gygj;
      App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
        App_Model_INDFadeIn_njia();
      }

      App_Model_DW.sfEvent_gygj = h_previousEvent;
      App_Model_DW.is_WPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     default:
      App_Model_DW.is_WPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;
    }

    /* 231218
       Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
    h_previousEvent = App_Model_DW.sfEvent_gygj;
    App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
      App_Model_INDFadeIn_njia();
    }

    App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mod_IN_WPCINDAnimation_Init;
    App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
      App_Model_INDLight_lnkr();
    }

    App_Model_DW.sfEvent_gygj = h_previousEvent;
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
  } else {
    switch (App_Model_DW.is_WPCINDAnimation_Error) {
     case App_IN_WPCINDAnimationError_Off:
      {
        C_WPCWarning tmp_1;
        WPCIndUSMState tmp_0;

        /* DataTypeConversion: '<S843>/Data Type Conversion1' */
        /* 2 */
        tmp_0 = App_Model_B.INT_SWPCIndUSMState;

        /* Update for Merge generated from: '<S642>/Merge' */
        tmp_1 = App_Model_B.C_WPCWarning_kjwv;
        if (((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut >=
               (uint32)((uint8)50U)))) && (((uint32)tmp_1 == WPCWarningOff) || ((uint32)tmp_1 == PhoneCharging) || ((uint32)tmp_1 == Charging_Complete) || ((uint32)tmp_1 == Cellphoneonthepad) ||
             ((uint32)tmp_1 == Cellphonereminder) || ((uint32)tmp_1 == WarningInvalid))) {
          sint32 h_previousEvent;

          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
            App_Model_INDFadeOut_ckyy();
          }

          App_Model_DW.is_WPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

          /* 231218
             Output_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;%231218 */
          App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_njia();
          }

          App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mod_IN_WPCINDAnimation_Init;
          App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_lnkr();
          }

          App_Model_DW.sfEvent_gygj = h_previousEvent;
          App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
          App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
        } else if ((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut
          >= (uint32)((uint8)50U)))) {
          sint32 h_previousEvent;

          /* 231218 */
          h_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
            App_Model_INDFadeOut_ckyy();
          }

          App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
          App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_njia();
          }

          App_Model_DW.sfEvent_gygj = h_previousEvent;
          App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
          App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
        } else {
          /* no actions */
        }
      }
      break;

     case App__IN_WPCINDAnimationError_On:
      {
        WPCIndUSMState tmp_0;

        /* DataTypeConversion: '<S843>/Data Type Conversion1' */
        /* 1 */
        tmp_0 = App_Model_B.INT_SWPCIndUSMState;
        if ((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn >=
              (uint32)((uint8)50U)))) {
          sint32 h_previousEvent;

          /* 231218 */
          /* 240208 */
          h_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
            App_Model_INDFadeIn_njia();
          }

          App_Model_DW.sfEvent_gygj = h_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
          enter_atomic_WPCINDAnimati_aqrs();
        }
      }
      break;

     case IN_WPCINDAnimationError_PreNone:
      /* DataTypeConversion: '<S843>/Data Type Conversion1' */
      /* 1 */
      if (((uint32)App_Model_B.INT_SWPCIndUSMState != WPCIndUSMState__Type2) || (App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U))) {
        /* 231218 */
        App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
        enter_atomic_WPCINDAnimati_aqrs();
      }
      break;

     case IN_WPCINDAnimationError_PreRWPC:
      {
        PreSyncAct tmp;
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
        } else {
          WPCIndUSMState tmp_0;

          /* DataTypeConversion: '<S843>/Data Type Conversion1' */
          /* 2 */
          tmp_0 = App_Model_B.INT_SWPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct == PreSyncAct__RWPC) && (((App_Model_DW.Var_INT_RWPCIndCmdState_prev !=
                  App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_RWPCIndCmdState_prev
                  != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__2ndChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__3rdChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ChrgFadeOut)) ||
                ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeOut)))) ||
              (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)
                 App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
            enter_atomic_WPCINDAnimati_aqrs();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)
                       App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_gygj;
            App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
              App_Model_INDFadeIn_njia();
            }

            App_Model_DW.sfEvent_gygj = h_previousEvent;
            App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_ee43();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_Pr_lvrx:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
        } else {
          /* 2 */
          tmp = App_Model_B.Var_PreSyncAct;
          if ((uint32)tmp == PreSyncAct__WPC2) {
            App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWPC2;
          } else {
            WPCIndUSMState tmp_0;

            /* DataTypeConversion: '<S843>/Data Type Conversion1' */
            /* 3  */
            tmp_0 = App_Model_B.INT_SWPCIndUSMState;
            if (((App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__RWPCWPC2) && (((App_Model_DW.Var_INT_RWPCIndCmdState_prev !=
                    App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__1stChrgFadeIn)) ||
                  ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__2ndChrgFadeIn)) ||
                  ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__3rdChrgFadeIn)) ||
                  ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ChrgFadeOut)) ||
                  ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeOut))))
                || (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)
                   App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeOut)))) {
              App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
              enter_atomic_WPCINDAnimati_aqrs();
            } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start) && ((uint32)
                         App_Model_DW.Var_INT_RWPCIndCmdState_start == RWPCIndCmdState__ErrorFadeIn))) {
              sint32 h_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
              h_previousEvent = App_Model_DW.sfEvent_gygj;
              App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
              if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
                App_Model_INDFadeIn_njia();
              }

              App_Model_DW.sfEvent_gygj = h_previousEvent;
              App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
              App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
            } else {
              App_Model_INDErrorOnOut_ee43();
            }
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_PreWPC2:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
        } else {
          WPCIndUSMState tmp_0;

          /* DataTypeConversion: '<S843>/Data Type Conversion1' */
          /* 2  */
          tmp_0 = App_Model_B.INT_SWPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct == PreSyncAct__WPC2) && (((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                  App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_INT_WPC2IndCmdState_prev
                  != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__2ndChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__3rdChrgFadeIn)) ||
                ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ChrgFadeOut)) ||
                ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) ||
              (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)
                 App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
            enter_atomic_WPCINDAnimati_aqrs();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)
                       App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeIn))) {
            sint32 h_previousEvent;
            App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
            h_previousEvent = App_Model_DW.sfEvent_gygj;
            App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
              App_Model_INDFadeIn_njia();
            }

            App_Model_DW.sfEvent_gygj = h_previousEvent;
            App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_ee43();
          }
        }
      }
      break;

     case IN_WPCINDAnimationError_Pr_fbnk:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start;
        if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
        } else {
          /* 2 */
          tmp = App_Model_B.Var_PreSyncAct;
          if ((uint32)tmp == PreSyncAct__RWPC) {
            App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRWPC;
          } else {
            WPCIndUSMState tmp_0;

            /* DataTypeConversion: '<S843>/Data Type Conversion1' */
            /* 3 */
            tmp_0 = App_Model_B.INT_SWPCIndUSMState;
            if (((App_Model_DW.Timer_INDFadeIn >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__WPC2RWPC) && (((App_Model_DW.Var_INT_WPC2IndCmdState_prev !=
                    App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__1stChrgFadeIn)) ||
                  ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__2ndChrgFadeIn)) ||
                  ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__3rdChrgFadeIn)) ||
                  ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ChrgFadeOut)) ||
                  ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut))))
                || (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)
                   App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) {
              App_Model_DW.is_WPCINDAnimation_Error = App_IN_WPCINDAnimationError_Off;
              enter_atomic_WPCINDAnimati_aqrs();
            } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start) && ((uint32)
                         App_Model_DW.Var_INT_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeIn))) {
              sint32 h_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Error = App__IN_WPCINDAnimationError_On;
              h_previousEvent = App_Model_DW.sfEvent_gygj;
              App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
              if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
                App_Model_INDFadeIn_njia();
              }

              App_Model_DW.sfEvent_gygj = h_previousEvent;
              App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
              App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
            } else {
              App_Model_INDErrorOnOut_ee43();
            }
          }
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void IND_Animation_Sync_Control_hzm0(void)
{
  switch (App_Model_DW.is_IND_Animation_Sync_Control_F) {
   case App_IN_WPCINDAnimation_Charging:
    {
      /* Update for Merge generated from: '<S642>/Merge' */
      if (((App_Model_DW.WPCIndUSMState_prev != App_Model_DW.WPCIndUSMState_start) && ((uint32)App_Model_DW.WPCIndUSMState_start == WPCIndUSMState__Type1)) || ((uint32)App_Model_B.C_WPCWarning_kjwv !=
           PhoneCharging)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        if ((uint32)App_Model_DW.is_WPCINDAnimation_Charging == IN_WPCINDAnimationCharging_Acti) {
          switch (App_Model_DW.is_WPCINDAnimationCharging_Acti) {
           case IN_WPCINDAnimationCharging_1stS:
            exit_internal_WPCINDAnimat_pscz();
            g_previousEvent = App_Model_DW.sfEvent_gygj;
            App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_lnkr();
            }

            App_Model_DW.sfEvent_gygj = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_2ndS:
            exit_internal_WPCINDAnimat_nyfq();
            g_previousEvent = App_Model_DW.sfEvent_gygj;
            App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_lnkr();
            }

            App_Model_DW.sfEvent_gygj = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_3rdS:
            exit_internal_WPCINDAnimat_pktw();
            g_previousEvent = App_Model_DW.sfEvent_gygj;
            App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_lnkr();
            }

            App_Model_DW.sfEvent_gygj = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_WPCINDAnimationCharging_Off:
            exit_internal_WPCINDAnimat_n0kq();
            g_previousEvent = App_Model_DW.sfEvent_gygj;
            App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
              App_Model_INDLight_lnkr();
            }

            App_Model_DW.sfEvent_gygj = g_previousEvent;
            App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           default:
            /* no actions */
            break;
          }

          /* CancelTimer에서 StartTimer로 변경 221216 */
          g_previousEvent = App_Model_DW.sfEvent_gygj;
          App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
            App_Model_INDLight_lnkr();
          }

          App_Model_DW.sfEvent_gygj = g_previousEvent;
          App_Model_DW.is_WPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        } else {
          App_Model_DW.is_WPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        }

        g_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mod_IN_WPCINDAnimation_Init;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.sfEvent_gygj = g_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
        App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
      } else {
        switch (App_Model_DW.is_WPCINDAnimation_Charging) {
         case IN_WPCINDAnimationCharging_Acti:
          WPCINDAnimationCharging_Ac_ecok();
          break;

         case IN_WPCINDAnimationCharging_PreN:
          {
            /* 1 */
            if (App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_gygj;
              App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_lnkr();
              }

              App_Model_DW.sfEvent_gygj = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnima_ddqo();
            }
          }
          break;

         case IN_WPCINDAnimationCharging_PreR:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;

              /* 2 */
            } else if ((App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct == PreSyncAct__RWPC) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_p_eqk4 !=
                         App_Model_DW.Input_CAN_RWPCIndSyncVal_s_fuhd) || (App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_gygj;
              App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_lnkr();
              }

              App_Model_DW.sfEvent_gygj = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnima_ddqo();
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPCINDAnimationCharging_i0ou:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;
            } else {
              /* 2 */
              tmp = App_Model_B.Var_PreSyncAct;
              if ((uint32)tmp == PreSyncAct__WPC2) {
                App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreW;

                /* 3  */
              } else if ((App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__RWPCWPC2) && ((App_Model_DW.Input_CAN_RWPCIndSyncVal_p_eqk4 !=
                           App_Model_DW.Input_CAN_RWPCIndSyncVal_s_fuhd) || (App_Model_DW.Var_INT_RWPCIndCmdState_prev != App_Model_DW.Var_INT_RWPCIndCmdState_start))) {
                sint32 g_previousEvent;
                App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
                g_previousEvent = App_Model_DW.sfEvent_gygj;
                App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
                if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
                  App_Model_INDLight_lnkr();
                }

                App_Model_DW.sfEvent_gygj = g_previousEvent;

                /* CancelTimer추가 221216 */
                enter_internal_WPCINDAnima_ddqo();
              } else {
                /* no actions */
              }
            }
          }
          break;

         case IN_WPCINDAnimationCharging_PreW:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;

              /* 2  */
            } else if ((App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct == PreSyncAct__WPC2) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_ofvk !=
                         App_Model_DW.Input_CAN_WPC2IndSyncVal_s_hoel) || (App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
              g_previousEvent = App_Model_DW.sfEvent_gygj;
              App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
                App_Model_INDLight_lnkr();
              }

              App_Model_DW.sfEvent_gygj = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_WPCINDAnima_ddqo();
            } else {
              /* no actions */
            }
          }
          break;

         case IN_WPCINDAnimationCharging_puay:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start;
            if ((App_Model_DW.Var_PreSyncAct_prev != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;
            } else {
              /* 2 */
              tmp = App_Model_B.Var_PreSyncAct;
              if ((uint32)tmp == PreSyncAct__RWPC) {
                App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreR;

                /* 3 */
              } else if ((App_Model_DW.Timer_INDLight >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__WPC2RWPC) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_ofvk !=
                           App_Model_DW.Input_CAN_WPC2IndSyncVal_s_hoel) || (App_Model_DW.Var_INT_WPC2IndCmdState_prev != App_Model_DW.Var_INT_WPC2IndCmdState_start))) {
                sint32 g_previousEvent;
                App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_Acti;
                g_previousEvent = App_Model_DW.sfEvent_gygj;
                App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
                if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
                  App_Model_INDLight_lnkr();
                }

                App_Model_DW.sfEvent_gygj = g_previousEvent;

                /* CancelTimer추가 221216 */
                enter_internal_WPCINDAnima_ddqo();
              } else {
                /* no actions */
              }
            }
          }
          break;

         default:
          /* no actions */
          break;
        }
      }
    }
    break;

   case App_Mo_IN_WPCINDAnimation_Error:
    App__WPCINDAnimation_Error_lqd0();
    break;

   case App_Mod_IN_WPCINDAnimation_Init:
    {
      C_WPCWarning tmp_0;

      /* Update for Merge generated from: '<S642>/Merge' */
      /* 2 */
      tmp_0 = App_Model_B.C_WPCWarning_kjwv;

      /* DataTypeConversion: '<S843>/Data Type Conversion1' incorporates:
       *  DataTypeConversion: '<S843>/Data Type Conversion65'
       */
      if (((uint32)tmp_0 == PhoneCharging) && ((uint32)App_Model_B.INT_SWPCIndUSMState == WPCIndUSMState__Type2)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        App_Model_DW.is_IND_Animation_Sync_Control_F = App_IN_WPCINDAnimation_Charging;
        g_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App_M_event_StartTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        App_Model_DW.sfEvent_gygj = g_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__3rdSync;
        App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;

        /* 1
           [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC2)]%230102 */
        switch (App_Model_B.Var_PreSyncAct) {
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
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_i0ou;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4
             [hasChangedTo(Var_PreSyncAct, PreSyncAct__WPC2RWPC)] */
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_puay;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Charging = IN_WPCINDAnimationCharging_PreN;
          break;
        }

        /* 3 */
      } else if (((uint32)tmp_0 == Charging_error) && ((uint32)App_Model_B.INT_b_SyncAmber_SWPC == On)) {
        sint32 g_previousEvent;
        App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mo_IN_WPCINDAnimation_Error;
        g_previousEvent = App_Model_DW.sfEvent_gygj;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_njia();
        }

        App_Model_DW.sfEvent_gygj = g_previousEvent;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__ErrorOn;
        App_Model_TypeCont_aa4v();

        /* 1 */
        switch (App_Model_B.Var_PreSyncAct) {
         case PreSyncAct__WPC2:
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreWPC2;
          break;

         case PreSyncAct__RWPC:
          /* 2 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreRWPC;
          break;

         case PreSyncAct__RWPCWPC2:
          /* 3 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_Pr_lvrx;
          break;

         case PreSyncAct__WPC2RWPC:
          /* 4 */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_Pr_fbnk;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_WPCINDAnimation_Error = IN_WPCINDAnimationError_PreNone;
          break;
        }
      } else {
        /* no actions */
      }

      /* End of DataTypeConversion: '<S843>/Data Type Conversion1' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Model_INDPhaseState_jko2(void)
{
  switch (App_Model_DW.is_INDPhaseState_p4z4) {
   case App_M_IN_INDPhaseState_Off_bpnu:
    if (App_Model_DW.sfEvent_bqin == (sint32)event_StartTimer_INDPhaseS_a3lh) {
      App_Model_DW.is_INDPhaseState_p4z4 = App_Mo_IN_INDPhaseState_On_bakn;
    }
    break;

   case App_Mo_IN_INDPhaseState_On_bakn:
    {
      switch (App_Model_DW.sfEvent_bqin) {
       case event_CancelTimer_INDPhase_h0ww:
        App_Model_DW.is_INDPhaseState_p4z4 = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState_holq = 0U;
        break;

       case event_StartTimer_INDPhaseS_a3lh:
        App_Model_DW.Timer_INDPhaseState_holq = 0U;
        App_Model_DW.is_INDPhaseState_p4z4 = App_Mo_IN_INDPhaseState_On_bakn;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDPhaseState_holq + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDPhaseState_holq + 1U) < App_Model_DW.Timer_INDPhaseState_holq) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDPhaseState_holq = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPCINDCmdState_1s(void)
{
  switch (App_Model_DW.is_WPCINDCmdState_1stSync) {
   case IN_WPCINDCmdState_1stChrgFadeIn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case App_IN_WPCINDCmdState_1stChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPCINDCmdState_2n(void)
{
  switch (App_Model_DW.is_WPCINDCmdState_2ndSync) {
   case IN_WPCINDCmdState_2ndChrgFadeIn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case App_IN_WPCINDCmdState_2ndChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPCINDCmdState_3r(void)
{
  switch (App_Model_DW.is_WPCINDCmdState_3rdSync) {
   case IN_WPCINDCmdState_3rdChrgFadeIn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case App_IN_WPCINDCmdState_3rdChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPCINDCmdState_Ch(void)
{
  switch (App_Model_DW.is_WPCINDCmdState_Charging) {
   case App_M_IN_WPCINDCmdState_1stSync:
    exit_internal_WPCINDCmdState_1s();
    App_Model_DW.is_WPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App_M_IN_WPCINDCmdState_2ndSync:
    exit_internal_WPCINDCmdState_2n();
    App_Model_DW.is_WPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App_M_IN_WPCINDCmdState_3rdSync:
    exit_internal_WPCINDCmdState_3r();
    App_Model_DW.is_WPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App_Model_IN_WPCINDCmdState_Off:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      App_Model_DW.is_WPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void App_Mod_WPCINDCmdState_Charging(void)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndCmdState__Default)) {
    exit_internal_WPCINDCmdState_Ch();
    App_Model_DW.is_WPC_IND_Command_State_Contro = App_M_IN_WPCINDCmdState_Default;
    App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;

    /* 1 */
  } else if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__ErrorOn)) {
    sint32 h_previousEvent;
    exit_internal_WPCINDCmdState_Ch();
    App_Model_DW.is_WPC_IND_Command_State_Contro = App_Mod_IN_WPCIndCmdState_Error;

    /* 1 */
    App_Model_DW.is_WPCIndCmdState_Error = App_M_IN_WPCINDCmdState_ErrorOn;
    h_previousEvent = App_Model_DW.sfEvent_bqin;
    App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
    if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
      App_Model_INDPhaseState_jko2();
    }

    App_Model_DW.sfEvent_bqin = h_previousEvent;
    App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
  } else {
    switch (App_Model_DW.is_WPCINDCmdState_Charging) {
     case App_M_IN_WPCINDCmdState_1stSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_1s();
          App_Model_DW.is_WPCINDCmdState_Charging = App_Model_IN_WPCINDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_Off = A_IN_WPCINDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_1s();
          App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_2ndSync;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_2ndSync = IN_WPCINDCmdState_2ndChrgFadeIn;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__2ndChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPCINDCmdState_1stSync) {
           case IN_WPCINDCmdState_1stChrgFadeIn:
            {
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__1stChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_holq >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_bqin;
                App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                  App_Model_INDPhaseState_jko2();
                }

                App_Model_DW.is_WPCINDCmdState_1stSync = App_IN_WPCINDCmdState_1stChrgOn;
                App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                  App_Model_INDPhaseState_jko2();
                }

                App_Model_DW.sfEvent_bqin = h_previousEvent;
                App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__1stChrgOn;
              }
            }
            break;

           case App_IN_WPCINDCmdState_1stChrgOn:
            App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__1stChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_M_IN_WPCINDCmdState_2ndSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_2n();
          App_Model_DW.is_WPCINDCmdState_Charging = App_Model_IN_WPCINDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_Off = A_IN_WPCINDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__3rdSync)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_2n();
          App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_3rdSync;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_3rdSync = IN_WPCINDCmdState_3rdChrgFadeIn;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__3rdChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_2n();
          App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_1stSync = IN_WPCINDCmdState_1stChrgFadeIn;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPCINDCmdState_2ndSync) {
           case IN_WPCINDCmdState_2ndChrgFadeIn:
            {
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__2ndChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_holq >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_bqin;
                App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                  App_Model_INDPhaseState_jko2();
                }

                App_Model_DW.is_WPCINDCmdState_2ndSync = App_IN_WPCINDCmdState_2ndChrgOn;
                App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                  App_Model_INDPhaseState_jko2();
                }

                App_Model_DW.sfEvent_bqin = h_previousEvent;
                App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__2ndChrgOn;
              }
            }
            break;

           case App_IN_WPCINDCmdState_2ndChrgOn:
            App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__2ndChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_M_IN_WPCINDCmdState_3rdSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_3r();
          App_Model_DW.is_WPCINDCmdState_Charging = App_Model_IN_WPCINDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_Off = A_IN_WPCINDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ChrgFadeOut;

          /* 2 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__2ndSync)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_3r();
          App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_2ndSync;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_2ndSync = IN_WPCINDCmdState_2ndChrgFadeIn;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__2ndChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          exit_internal_WPCINDCmdState_3r();
          App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_1stSync = IN_WPCINDCmdState_1stChrgFadeIn;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPCINDCmdState_3rdSync) {
           case IN_WPCINDCmdState_3rdChrgFadeIn:
            {
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__3rdChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_holq >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_bqin;
                App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                  App_Model_INDPhaseState_jko2();
                }

                App_Model_DW.is_WPCINDCmdState_3rdSync = App_IN_WPCINDCmdState_3rdChrgOn;
                App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                  App_Model_INDPhaseState_jko2();
                }

                App_Model_DW.sfEvent_bqin = h_previousEvent;
                App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;
              }
            }
            break;

           case App_IN_WPCINDCmdState_3rdChrgOn:
            App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_Model_IN_WPCINDCmdState_Off:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPCIndSyncVal_prev != App_Model_DW.Input_CAN_WPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_WPCIndSyncVal_start == WPCIndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          h_previousEvent = App_Model_DW.sfEvent_bqin;
          App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.is_WPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
          App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPCINDCmdState_1stSync = IN_WPCINDCmdState_1stChrgFadeIn;
          App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
            App_Model_INDPhaseState_jko2();
          }

          App_Model_DW.sfEvent_bqin = h_previousEvent;
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__1stChrgFadeIn;
        } else if ((uint32)App_Model_DW.is_WPCINDCmdState_Off == A_IN_WPCINDCmdState_ChrgFadeOut) {
          App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ChrgFadeOut;
        } else {
          /* no actions */
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPCIndCmdState_Er(void)
{
  switch (App_Model_DW.is_WPCIndCmdState_Error) {
   case App__IN_WPCINDCmdState_ErrorOff:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCIndCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case App_M_IN_WPCINDCmdState_ErrorOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_bqin;
      App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
        App_Model_INDPhaseState_jko2();
      }

      App_Model_DW.sfEvent_bqin = b_previousEvent;
      App_Model_DW.is_WPCIndCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    App_Model_DW.is_WPCIndCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void App_Model_INDPhaseState_pnuz(void)
{
  switch (App_Model_DW.is_INDPhaseState_k14z) {
   case App_M_IN_INDPhaseState_Off_bpnu:
    if (App_Model_DW.sfEvent_fezm == (sint32)event_StartTimer_INDPhaseS_a3lh) {
      App_Model_DW.is_INDPhaseState_k14z = App_Mo_IN_INDPhaseState_On_bakn;
    }
    break;

   case App_Mo_IN_INDPhaseState_On_bakn:
    {
      switch (App_Model_DW.sfEvent_fezm) {
       case event_CancelTimer_INDPhase_h0ww:
        App_Model_DW.is_INDPhaseState_k14z = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState_h1ak = 0U;
        break;

       case event_StartTimer_INDPhaseS_a3lh:
        App_Model_DW.Timer_INDPhaseState_h1ak = 0U;
        App_Model_DW.is_INDPhaseState_k14z = App_Mo_IN_INDPhaseState_On_bakn;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDPhaseState_h1ak + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDPhaseState_h1ak + 1U) < App_Model_DW.Timer_INDPhaseState_h1ak) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDPhaseState_h1ak = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdState_1(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5) {
   case IN_WPC2INDCmdState_1stChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case Ap_IN_WPC2INDCmdState_1stChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdState_2(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v) {
   case IN_WPC2INDCmdState_2ndChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case Ap_IN_WPC2INDCmdState_2ndChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdState_3(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3) {
   case IN_WPC2INDCmdState_3rdChrgFadeI:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case Ap_IN_WPC2INDCmdState_3rdChrgOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdState_C(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc) {
   case App__IN_WPC2INDCmdState_1stSync:
    exit_internal_WPC2INDCmdState_1();
    App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App__IN_WPC2INDCmdState_2ndSync:
    exit_internal_WPC2INDCmdState_2();
    App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App__IN_WPC2INDCmdState_3rdSync:
    exit_internal_WPC2INDCmdState_3();
    App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;

   case App_Mode_IN_WPC2INDCmdState_Off:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void App_Mo_WPC2INDCmdState_Charging(void)
{
  /* 1 */
  if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndCmdState__Default)) {
    exit_internal_WPC2INDCmdState_C();
    App_Model_DW.is_WPC2_IND_Command_State__krzh = App__IN_WPC2INDCmdState_Default;
    App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;

    /* 1 */
  } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__ErrorOn)) {
    sint32 h_previousEvent;
    exit_internal_WPC2INDCmdState_C();
    App_Model_DW.is_WPC2_IND_Command_State__krzh = App_Mo_IN_WPC2INDCmdState_Error;

    /* 1 */
    App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App__IN_WPC2INDCmdState_ErrorOn;
    h_previousEvent = App_Model_DW.sfEvent_fezm;
    App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
    if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
      App_Model_INDPhaseState_pnuz();
    }

    App_Model_DW.sfEvent_fezm = h_previousEvent;
    App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
  } else {
    switch (App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc) {
     case App__IN_WPC2INDCmdState_1stSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_1();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mode_IN_WPC2INDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = IN_WPC2INDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__2ndSync))
        {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_1();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_2ndSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = IN_WPC2INDCmdState_2ndChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5) {
           case IN_WPC2INDCmdState_1stChrgFadeI:
            {
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_h1ak >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_fezm;
                App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                  App_Model_INDPhaseState_pnuz();
                }

                App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = Ap_IN_WPC2INDCmdState_1stChrgOn;
                App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                  App_Model_INDPhaseState_pnuz();
                }

                App_Model_DW.sfEvent_fezm = h_previousEvent;
                App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__1stChrgOn;
              }
            }
            break;

           case Ap_IN_WPC2INDCmdState_1stChrgOn:
            App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__1stChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App__IN_WPC2INDCmdState_2ndSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_2();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mode_IN_WPC2INDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = IN_WPC2INDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

          /* 1 */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__3rdSync))
        {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_2();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_3rdSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = IN_WPC2INDCmdState_3rdChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__3rdChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__1stSync))
        {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_2();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = IN_WPC2INDCmdState_1stChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v) {
           case IN_WPC2INDCmdState_2ndChrgFadeI:
            {
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_h1ak >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_fezm;
                App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                  App_Model_INDPhaseState_pnuz();
                }

                App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = Ap_IN_WPC2INDCmdState_2ndChrgOn;
                App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                  App_Model_INDPhaseState_pnuz();
                }

                App_Model_DW.sfEvent_fezm = h_previousEvent;
                App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__2ndChrgOn;
              }
            }
            break;

           case Ap_IN_WPC2INDCmdState_2ndChrgOn:
            App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__2ndChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App__IN_WPC2INDCmdState_3rdSync:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__Off)) {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_3();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mode_IN_WPC2INDCmdState_Off;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = IN_WPC2INDCmdState_ChrgFadeOut;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;

          /* 2 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__2ndSync))
        {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_3();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_2ndSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = IN_WPC2INDCmdState_2ndChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__2ndChrgFadeIn;

          /* 3 230113 for UnexpectedSync */
        } else if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__1stSync))
        {
          sint32 h_previousEvent;
          exit_internal_WPC2INDCmdState_3();
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = IN_WPC2INDCmdState_1stChrgFadeI;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
        } else {
          switch (App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3) {
           case IN_WPC2INDCmdState_3rdChrgFadeI:
            {
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__3rdChrgFadeIn;

              /* 1. */
              if (App_Model_DW.Timer_INDPhaseState_h1ak >= (uint32)((uint8)100U)) {
                sint32 h_previousEvent;
                h_previousEvent = App_Model_DW.sfEvent_fezm;
                App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                  App_Model_INDPhaseState_pnuz();
                }

                App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = Ap_IN_WPC2INDCmdState_3rdChrgOn;
                App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
                if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                  App_Model_INDPhaseState_pnuz();
                }

                App_Model_DW.sfEvent_fezm = h_previousEvent;
                App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
              }
            }
            break;

           case Ap_IN_WPC2INDCmdState_3rdChrgOn:
            App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPC2INDCmdState_Off:
      {
        /* 1 */
        if ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc != App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi) && ((uint32)App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi == WPC2IndSyncVal__1stSync)) {
          sint32 h_previousEvent;
          h_previousEvent = App_Model_DW.sfEvent_fezm;
          App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
          App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_1stSync;

          /* 1 */
          App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = IN_WPC2INDCmdState_1stChrgFadeI;
          App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
          if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
            App_Model_INDPhaseState_pnuz();
          }

          App_Model_DW.sfEvent_fezm = h_previousEvent;
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__1stChrgFadeIn;
        } else if ((uint32)App_Model_DW.is_WPC2INDCmdState_Off_mcf1 == IN_WPC2INDCmdState_ChrgFadeOut) {
          App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ChrgFadeOut;
        } else {
          /* no actions */
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
static void exit_internal_WPC2INDCmdState_E(void)
{
  switch (App_Model_DW.is_WPC2INDCmdState_Error_jb0a) {
   case App_IN_WPC2INDCmdState_ErrorOff:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case App__IN_WPC2INDCmdState_ErrorOn:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_fezm;
      App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
      if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
        App_Model_INDPhaseState_pnuz();
      }

      App_Model_DW.sfEvent_fezm = b_previousEvent;
      App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDLight_jhwd(void)
{
  switch (App_Model_DW.is_INDLight_kqsl) {
   case App_Model_IN_INDLight_Off:
    if (App_Model_DW.sfEvent_c1ob == (sint32)App_M_event_StartTimer_INDLight) {
      App_Model_DW.is_INDLight_kqsl = App_Model_IN_INDLight_On;
    }
    break;

   case App_Model_IN_INDLight_On:
    {
      switch (App_Model_DW.sfEvent_c1ob) {
       case App__event_CancelTimer_INDLight:
        App_Model_DW.is_INDLight_kqsl = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight_ewv0 = 0U;
        break;

       case App_M_event_StartTimer_INDLight:
        App_Model_DW.Timer_INDLight_ewv0 = 0U;
        App_Model_DW.is_INDLight_kqsl = App_Model_IN_INDLight_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDLight_ewv0 + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDLight_ewv0 + 1U) < App_Model_DW.Timer_INDLight_ewv0) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDLight_ewv0 = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeIn_kcqh(void)
{
  switch (App_Model_DW.is_INDFadeIn_n305) {
   case App_Model_IN_INDFadeIn_Off:
    if (App_Model_DW.sfEvent_c1ob == (sint32)App__event_StartTimer_INDFadeIn) {
      App_Model_DW.is_INDFadeIn_n305 = App_Model_IN_INDFadeIn_On;
    }
    break;

   case App_Model_IN_INDFadeIn_On:
    {
      switch (App_Model_DW.sfEvent_c1ob) {
       case App_event_CancelTimer_INDFadeIn:
        App_Model_DW.is_INDFadeIn_n305 = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_g1fs = 0U;
        break;

       case App__event_StartTimer_INDFadeIn:
        App_Model_DW.Timer_INDFadeIn_g1fs = 0U;
        App_Model_DW.is_INDFadeIn_n305 = App_Model_IN_INDFadeIn_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeIn_g1fs + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeIn_g1fs + 1U) < App_Model_DW.Timer_INDFadeIn_g1fs) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeIn_g1fs = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_RWPCINDAnimationC(void)
{
  switch (App_Model_DW.is_RWPCINDAnimationCharging_1st) {
   case IN_RWPCINDAnimationChargin_iux5:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
        App_Model_INDFadeIn_kcqh();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDAnimationChargin_dxqc:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
        App_Model_INDLight_jhwd();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_RWPCINDAnim_jwkr(void)
{
  /* 1 */
  if (((uint32)App_Model_B.Var_WPCIndCmdState == WPCIndCmdState__2ndChrgOn) || ((uint32)App_Model_B.Var_WPC2IndCmdState == WPC2IndCmdState__2ndChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_RWPCINDAnimationCharging_2nd = IN_RWPCINDAnimationChargin_oe45;
    c_previousEvent = App_Model_DW.sfEvent_c1ob;
    App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
      App_Model_INDLight_jhwd();
    }

    App_Model_DW.sfEvent_c1ob = c_previousEvent;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       Var_WPC2IndCmdState == WPC2IndCmdState__2ndChrgFadeIn ||
       Input_INT_RWPCIndCmdState == RWPCIndCmdState__2ndChrgFadeIn */
    App_Model_DW.is_RWPCINDAnimationCharging_2nd = IN_RWPCINDAnimationChargin_hln0;
    c_previousEvent = App_Model_DW.sfEvent_c1ob;
    App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
      App_Model_INDLight_jhwd();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
      App_Model_INDFadeIn_kcqh();
    }

    App_Model_DW.sfEvent_c1ob = c_previousEvent;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgFadeIn;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_RWPCINDAnima_a1gb(void)
{
  switch (App_Model_DW.is_RWPCINDAnimationCharging_2nd) {
   case IN_RWPCINDAnimationChargin_hln0:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
        App_Model_INDFadeIn_kcqh();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDAnimationChargin_oe45:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
        App_Model_INDLight_jhwd();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_RWPCINDAnimationCh(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_c1ob;
  App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
    App_Model_INDLight_jhwd();
  }

  /* CancelTimer추가 221219 */
  App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
    App_Model_INDFadeIn_kcqh();
  }

  App_Model_DW.sfEvent_c1ob = b_previousEvent;
  App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgFadeIn;
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_RWPCINDAnima_aoy1(void)
{
  switch (App_Model_DW.is_RWPCINDAnimationCharging_3rd) {
   case IN_RWPCINDAnimationChargin_orxo:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
        App_Model_INDFadeIn_kcqh();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_3rd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   case IN_RWPCINDAnimationChargin_oo1y:
    {
      sint32 b_previousEvent;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
        App_Model_INDLight_jhwd();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_3rd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDFadeOut_iwqq(void)
{
  switch (App_Model_DW.is_INDFadeOut_ps5o) {
   case App_Model_IN_INDFadeOut_Off:
    if (App_Model_DW.sfEvent_c1ob == (sint32)App_event_StartTimer_INDFadeOut) {
      App_Model_DW.is_INDFadeOut_ps5o = App_Model_IN_INDFadeOut_On;
    }
    break;

   case App_Model_IN_INDFadeOut_On:
    {
      switch (App_Model_DW.sfEvent_c1ob) {
       case Ap_event_CancelTimer_INDFadeOut:
        App_Model_DW.is_INDFadeOut_ps5o = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_ey0j = 0U;
        break;

       case App_event_StartTimer_INDFadeOut:
        App_Model_DW.Timer_INDFadeOut_ey0j = 0U;
        App_Model_DW.is_INDFadeOut_ps5o = App_Model_IN_INDFadeOut_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_INDFadeOut_ey0j + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_INDFadeOut_ey0j + 1U) < App_Model_DW.Timer_INDFadeOut_ey0j) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_INDFadeOut_ey0j = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_RWPCINDAnim_f5rh(void)
{
  sint32 b_previousEvent;

  /* 1_230104_sync */
  b_previousEvent = App_Model_DW.sfEvent_c1ob;
  App_Model_DW.sfEvent_c1ob = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
    App_Model_INDFadeOut_iwqq();
  }

  App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
    App_Model_INDLight_jhwd();
  }

  App_Model_DW.sfEvent_c1ob = b_previousEvent;

  /* 230328 */
  App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ChrgFadeOut;

  /* 230328 */
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void exit_internal_RWPCINDAnima_mj5o(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_c1ob;
  App_Model_DW.sfEvent_c1ob = (sint32)Ap_event_CancelTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
    App_Model_INDFadeOut_iwqq();
  }

  App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
  if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
    App_Model_INDLight_jhwd();
  }

  App_Model_DW.sfEvent_c1ob = b_previousEvent;
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_RWPCINDAnim_bbox(void)
{
  /* 1 */
  if (((uint32)App_Model_B.Var_WPCIndCmdState == WPCIndCmdState__1stChrgOn) || ((uint32)App_Model_B.Var_WPC2IndCmdState == WPC2IndCmdState__1stChrgOn)) {
    sint32 c_previousEvent;
    App_Model_DW.is_RWPCINDAnimationCharging_1st = IN_RWPCINDAnimationChargin_dxqc;
    c_previousEvent = App_Model_DW.sfEvent_c1ob;
    App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
      App_Model_INDLight_jhwd();
    }

    App_Model_DW.sfEvent_c1ob = c_previousEvent;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgOn;
  } else {
    sint32 c_previousEvent;

    /* 2
       Var_WPC2IndCmdState == WPC2IndCmdState__1stChrgFadeIn ||
       Var_WPC2IndCmdState == WPC2IndCmdState__ErrorFadeOut ||
       Input_INT_RWPCIndCmdState == RWPCIndCmdState__1stChrgFadeIn ||
       Input_INT_RWPCIndCmdState == RWPCIndCmdState__ErrorFadeOut] */
    App_Model_DW.is_RWPCINDAnimationCharging_1st = IN_RWPCINDAnimationChargin_iux5;
    c_previousEvent = App_Model_DW.sfEvent_c1ob;
    App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
      App_Model_INDLight_jhwd();
    }

    /* CancelTimer추가 221219 */
    App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
      App_Model_INDFadeIn_kcqh();
    }

    App_Model_DW.sfEvent_c1ob = c_previousEvent;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgFadeIn;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_TypeCont_ljmv(void)
{
  /* DataTypeConversion: '<S613>/Data Type Conversion5' */
  /* 1 */
  if ((uint32)App_Model_B.BCAN_RX_C_WPCIndUSMState != WPCIndUSMState__Type2) {
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
  } else {
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
  }

  /* End of DataTypeConversion: '<S613>/Data Type Conversion5' */
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void RWPCINDAnimationCharging_Active(void)
{
  switch (App_Model_DW.is_RWPCINDAnimationCharging_Act) {
   case IN_RWPCINDAnimationCharging_1st:
    {
      /* 2. Transition start point move to 1stOn */
      if (App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_RWPCINDAnimationC();
        k_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.sfEvent_c1ob = k_previousEvent;
        App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_2nd;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__2ndSync;

        /* CancelTimer추가 221216 */
        enter_internal_RWPCINDAnim_jwkr();
      } else if ((uint32)App_Model_DW.is_RWPCINDAnimationCharging_1st == IN_RWPCINDAnimationChargin_iux5) {
        /* 1 */
        if (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
            App_Model_INDFadeIn_kcqh();
          }

          App_Model_DW.is_RWPCINDAnimationCharging_1st = IN_RWPCINDAnimationChargin_dxqc;
          App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
            App_Model_INDLight_jhwd();
          }

          App_Model_DW.sfEvent_c1ob = k_previousEvent;
          App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__1stChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_RWPCINDAnimationCharging_2nd:
    {
      /* 2.Transition start point move to 2ndOn */
      if (App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_RWPCINDAnima_a1gb();
        k_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.sfEvent_c1ob = k_previousEvent;
        App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_3rd;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__3rdSync;

        /* CancelTimer추가 221216 */
        App_Model_DW.is_RWPCINDAnimationCharging_3rd = IN_RWPCINDAnimationChargin_orxo;
        enter_atomic_RWPCINDAnimationCh();
      } else if ((uint32)App_Model_DW.is_RWPCINDAnimationCharging_2nd == IN_RWPCINDAnimationChargin_hln0) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
            App_Model_INDFadeIn_kcqh();
          }

          App_Model_DW.is_RWPCINDAnimationCharging_2nd = IN_RWPCINDAnimationChargin_oe45;
          App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
            App_Model_INDLight_jhwd();
          }

          App_Model_DW.sfEvent_c1ob = k_previousEvent;
          App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__2ndChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_RWPCINDAnimationCharging_3rd:
    {
      /* 2.  */
      if (App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;

        /* [Timer_INDFadeOut >= Par_INDFadeOutTime] */
        exit_internal_RWPCINDAnima_aoy1();
        k_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_Off;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.sfEvent_c1ob = k_previousEvent;

        /* CancelTimer추가 230103 */
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Off;

        /* CancelTimer추가 221216 */
        enter_internal_RWPCINDAnim_f5rh();
      } else if ((uint32)App_Model_DW.is_RWPCINDAnimationCharging_3rd == IN_RWPCINDAnimationChargin_orxo) {
        /* 1. */
        if (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) {
          sint32 k_previousEvent;
          k_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
            App_Model_INDFadeIn_kcqh();
          }

          App_Model_DW.is_RWPCINDAnimationCharging_3rd = IN_RWPCINDAnimationChargin_oo1y;
          App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
            App_Model_INDLight_jhwd();
          }

          App_Model_DW.sfEvent_c1ob = k_previousEvent;
          App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
        }
      } else {
        /* no actions */
      }
    }
    break;

   case IN_RWPCINDAnimationCharging_Off:
    {
      /* Update for Merge generated from: '<S465>/Merge' */
      /* 1 */
      if ((App_Model_DW.Timer_INDFadeOut_ey0j >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.C_WPCWarning_epwi == Charging_error)) {
        sint32 k_previousEvent;
        exit_internal_RWPCINDAnima_mj5o();
        k_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

        /* CancelTimer에서 StartTimer로 변경 221216 */
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.is_RWPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_M_IN_RWPCINDAnimation_Error;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
          App_Model_INDFadeIn_kcqh();
        }

        App_Model_DW.sfEvent_c1ob = k_previousEvent;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
        App_Model_TypeCont_ljmv();

        /* 1 */
        switch (App_Model_B.Var_PreSyncAct_jsc5) {
         case PreSyncAct__WPC:
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreWPC;
          break;

         case PreSyncAct__WPC2:
          /* 2 */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreRWP;
          break;

         case PreSyncAct__WPC2WPC:
          /* 3 */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_P_gplk;
          break;

         case PreSyncAct__WPCWPC2:
          /* 4 */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_P_aelk;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreNon;
          break;
        }

        /* 3. */
      } else if (App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) {
        sint32 k_previousEvent;
        exit_internal_RWPCINDAnima_mj5o();
        k_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.sfEvent_c1ob = k_previousEvent;
        App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_1st;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__1stSync;

        /* CancelTimer추가 221216 */
        enter_internal_RWPCINDAnim_bbox();
      } else {
        /* no actions */
      }

      /* End of Update for Merge generated from: '<S465>/Merge' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_internal_RWPCINDAnimation(const C_WPCIndSyncVal *BCAN_RX_C_WPCIndSyncVal)
{
  WPC2IndSyncVal tmp;

  /* DataTypeConversion: '<S613>/Data Type Conversion9' */
  /* 1 */
  tmp = App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki;

  /* DataTypeConversion: '<S613>/Data Type Conversion6' */
  if (((((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) || ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPCWPC2)) && ((uint32)(*BCAN_RX_C_WPCIndSyncVal) ==
        WPCIndSyncVal__3rdSync)) || ((((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2) || ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2WPC)) && ((uint32)tmp ==
        WPC2IndSyncVal__3rdSync))) {
    App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_3rd;
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__3rdSync;

    /* CancelTimer추가 221216 */
    /* 1 */
    if (((uint32)App_Model_B.Var_WPCIndCmdState == WPCIndCmdState__3rdChrgOn) || ((uint32)App_Model_B.Var_WPC2IndCmdState == WPC2IndCmdState__3rdChrgOn)) {
      sint32 b_previousEvent;
      App_Model_DW.is_RWPCINDAnimationCharging_3rd = IN_RWPCINDAnimationChargin_oo1y;
      b_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
      if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
        App_Model_INDLight_jhwd();
      }

      App_Model_DW.sfEvent_c1ob = b_previousEvent;
      App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
    } else {
      /* 2
         Var_WPCIndCmdState == WPCIndCmdState__3rdChrgFadeIn ||
         Var_WPC2IndCmdState == WPC2IndCmdState__3rdChrgFadeIn */
      App_Model_DW.is_RWPCINDAnimationCharging_3rd = IN_RWPCINDAnimationChargin_orxo;
      enter_atomic_RWPCINDAnimationCh();
    }

    /* 2 */
  } else if (((((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) || ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPCWPC2)) && ((uint32)(*BCAN_RX_C_WPCIndSyncVal) ==
               WPCIndSyncVal__2ndSync)) || ((((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2) || ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2WPC)) && ((uint32)tmp ==
               WPC2IndSyncVal__2ndSync))) {
    App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_2nd;
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__2ndSync;

    /* CancelTimer추가 221216 */
    enter_internal_RWPCINDAnim_jwkr();

    /* 3 */
  } else if (((((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) || ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPCWPC2)) && (((uint32)(*BCAN_RX_C_WPCIndSyncVal) ==
                WPCIndSyncVal__1stSync) || ((uint32)(*BCAN_RX_C_WPCIndSyncVal) == WPCIndSyncVal__ErrorOff))) || ((((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2) || ((uint32)
                App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2WPC)) && (((uint32)tmp == WPC2IndSyncVal__1stSync) || ((uint32)tmp == WPC2IndSyncVal__ErrorOff)))) {
    App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_1st;
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__1stSync;

    /* CancelTimer추가 221216 */
    enter_internal_RWPCINDAnim_bbox();
  } else {
    sint32 b_previousEvent;

    /* 4 */
    App_Model_DW.is_RWPCINDAnimationCharging_Act = IN_RWPCINDAnimationCharging_Off;
    b_previousEvent = App_Model_DW.sfEvent_c1ob;
    App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
      App_Model_INDLight_jhwd();
    }

    App_Model_DW.sfEvent_c1ob = b_previousEvent;

    /* CancelTimer추가 230103 */
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Off;

    /* CancelTimer추가 221216 */
    enter_internal_RWPCINDAnim_f5rh();
  }

  /* End of DataTypeConversion: '<S613>/Data Type Conversion6' */
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void enter_atomic_RWPCINDAnimationEr(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_c1ob;
  App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
  if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
    App_Model_INDFadeIn_kcqh();
  }

  App_Model_DW.sfEvent_c1ob = (sint32)App_event_StartTimer_INDFadeOut;
  if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
    App_Model_INDFadeOut_iwqq();
  }

  App_Model_DW.sfEvent_c1ob = b_previousEvent;
  App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOff;
  App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Model_INDErrorOnOut_igbp(void)
{
  /* 1 */
  if (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) {
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorOn;
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void App_Mode_RWPCINDAnimation_Error(void)
{
  if ((App_Model_DW.b_SyncAmber_prev_eb5q != App_Model_DW.b_SyncAmber_start_hkgy) && ((uint32)App_Model_DW.b_SyncAmber_start_hkgy == Off)) {
    sint32 i_previousEvent;
    switch (App_Model_DW.is_RWPCINDAnimation_Error) {
     case Ap_IN_RWPCINDAnimationError_Off:
      i_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)Ap_event_CancelTimer_INDFadeOut;
      if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
        App_Model_INDFadeOut_iwqq();
      }

      App_Model_DW.sfEvent_c1ob = i_previousEvent;
      App_Model_DW.is_RWPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     case App_IN_RWPCINDAnimationError_On:
      i_previousEvent = App_Model_DW.sfEvent_c1ob;
      App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
      if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
        App_Model_INDFadeIn_kcqh();
      }

      App_Model_DW.sfEvent_c1ob = i_previousEvent;
      App_Model_DW.is_RWPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;

     default:
      App_Model_DW.is_RWPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
      break;
    }

    /* 231218
       Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn; */
    i_previousEvent = App_Model_DW.sfEvent_c1ob;
    App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
    if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
      App_Model_INDFadeIn_kcqh();
    }

    App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_Mo_IN_RWPCINDAnimation_Init;
    App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
    if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
      App_Model_INDLight_jhwd();
    }

    App_Model_DW.sfEvent_c1ob = i_previousEvent;
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
  } else {
    switch (App_Model_DW.is_RWPCINDAnimation_Error) {
     case Ap_IN_RWPCINDAnimationError_Off:
      {
        C_WPCWarning tmp_1;
        WPCIndUSMState tmp_0;

        /* DataTypeConversion: '<S613>/Data Type Conversion5' */
        /* 2Input_RWPCWarning != Charging_error]%231218 */
        tmp_0 = App_Model_B.BCAN_RX_C_WPCIndUSMState;

        /* Update for Merge generated from: '<S465>/Merge' */
        tmp_1 = App_Model_B.C_WPCWarning_epwi;
        if (((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_ey0j >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
              (App_Model_DW.Timer_INDFadeOut_ey0j >= (uint32)((sint32)((sint32)((uint8)100U) / 2))))) && (((uint32)tmp_1 == WPCWarningOff) || ((uint32)tmp_1 == PhoneCharging) || ((uint32)tmp_1 ==
              Charging_Complete) || ((uint32)tmp_1 == Cellphoneonthepad) || ((uint32)tmp_1 == Cellphonereminder) || ((uint32)tmp_1 == WarningInvalid))) {
          sint32 i_previousEvent;

          /* 240208 */
          i_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
            App_Model_INDFadeOut_iwqq();
          }

          App_Model_DW.is_RWPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;

          /* 231218
             Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn; */
          App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
            App_Model_INDFadeIn_kcqh();
          }

          App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_Mo_IN_RWPCINDAnimation_Init;
          App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
            App_Model_INDLight_jhwd();
          }

          App_Model_DW.sfEvent_c1ob = i_previousEvent;
          App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
          App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;

          /* 1 */
        } else if ((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeOut_ey0j >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
                    (App_Model_DW.Timer_INDFadeOut_ey0j >= (uint32)((uint8)50U)))) {
          sint32 i_previousEvent;

          /* 231218 */
          i_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)Ap_event_CancelTimer_INDFadeOut;
          if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
            App_Model_INDFadeOut_iwqq();
          }

          App_Model_DW.is_RWPCINDAnimation_Error = App_IN_RWPCINDAnimationError_On;
          App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
            App_Model_INDFadeIn_kcqh();
          }

          App_Model_DW.sfEvent_c1ob = i_previousEvent;
          App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
          App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
        } else {
          /* Input_WPCWarning == Charging_error &&... */
        }
      }
      break;

     case App_IN_RWPCINDAnimationError_On:
      {
        WPCIndUSMState tmp_0;

        /* DataTypeConversion: '<S613>/Data Type Conversion5' */
        /* 1 */
        tmp_0 = App_Model_B.BCAN_RX_C_WPCIndUSMState;
        if ((((uint32)tmp_0 == WPCIndUSMState__Type2) && (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
             (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)50U)))) {
          sint32 i_previousEvent;

          /* 231218 */
          /* 240208 */
          i_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)App_event_CancelTimer_INDFadeIn;
          if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
            App_Model_INDFadeIn_kcqh();
          }

          App_Model_DW.sfEvent_c1ob = i_previousEvent;
          App_Model_DW.is_RWPCINDAnimation_Error = Ap_IN_RWPCINDAnimationError_Off;
          enter_atomic_RWPCINDAnimationEr();
        } else {
          /* Input_RWPCWarning == Charging_error &&... */
        }
      }
      break;

     case IN_RWPCINDAnimationError_PreNon:
      /* DataTypeConversion: '<S613>/Data Type Conversion5' */
      /* 1 */
      if (((uint32)App_Model_B.BCAN_RX_C_WPCIndUSMState != WPCIndUSMState__Type2) || (App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U))) {
        /* 231218 */
        App_Model_DW.is_RWPCINDAnimation_Error = Ap_IN_RWPCINDAnimationError_Off;
        enter_atomic_RWPCINDAnimationEr();
      }
      break;

     case IN_RWPCINDAnimationError_PreRWP:
      {
        PreSyncAct tmp;
        tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
        if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreNon;
        } else {
          WPCIndUSMState tmp_0;

          /* DataTypeConversion: '<S613>/Data Type Conversion5' */
          /* 2 */
          tmp_0 = App_Model_B.BCAN_RX_C_WPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) && (((App_Model_DW.Var_WPC2IndCmdState_prev !=
                  App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                  App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                  App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                  App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                  App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
               ((App_Model_DW.Var_WPC2IndCmdState_prev != App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_RWPCINDAnimation_Error = Ap_IN_RWPCINDAnimationError_Off;
            enter_atomic_RWPCINDAnimationEr();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_WPC2IndCmdState_prev != App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start ==
            WPC2IndCmdState__ErrorFadeIn))) {
            sint32 i_previousEvent;
            App_Model_DW.is_RWPCINDAnimation_Error = App_IN_RWPCINDAnimationError_On;
            i_previousEvent = App_Model_DW.sfEvent_c1ob;
            App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
              App_Model_INDFadeIn_kcqh();
            }

            App_Model_DW.sfEvent_c1ob = i_previousEvent;
            App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_igbp();
          }
        }
      }
      break;

     case IN_RWPCINDAnimationError_PreWPC:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
        if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreNon;
        } else {
          WPCIndUSMState tmp_0;

          /* DataTypeConversion: '<S613>/Data Type Conversion5' */
          /* 2  */
          tmp_0 = App_Model_B.BCAN_RX_C_WPCIndUSMState;
          if (((App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) && (((App_Model_DW.Var_WPCIndCmdState_prev !=
                  App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                  App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                  App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                  App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                  App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
               ((App_Model_DW.Var_WPCIndCmdState_prev != App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) {
            App_Model_DW.is_RWPCINDAnimation_Error = Ap_IN_RWPCINDAnimationError_Off;
            enter_atomic_RWPCINDAnimationEr();
          } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_WPCIndCmdState_prev != App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start ==
                       WPCIndCmdState__ErrorFadeIn))) {
            sint32 i_previousEvent;
            App_Model_DW.is_RWPCINDAnimation_Error = App_IN_RWPCINDAnimationError_On;
            i_previousEvent = App_Model_DW.sfEvent_c1ob;
            App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
            if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
              App_Model_INDFadeIn_kcqh();
            }

            App_Model_DW.sfEvent_c1ob = i_previousEvent;
            App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
            App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
          } else {
            App_Model_INDErrorOnOut_igbp();
          }
        }
      }
      break;

     case IN_RWPCINDAnimationError_P_gplk:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
        if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreNon;
        } else {
          /* 2 */
          tmp = App_Model_B.Var_PreSyncAct_jsc5;
          if ((uint32)tmp == PreSyncAct__WPC) {
            App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreWPC;
          } else {
            WPCIndUSMState tmp_0;

            /* DataTypeConversion: '<S613>/Data Type Conversion5' */
            /* 3  */
            tmp_0 = App_Model_B.BCAN_RX_C_WPCIndUSMState;
            if (((App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__WPC2WPC) && (((App_Model_DW.Var_WPC2IndCmdState_prev !=
                    App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                    App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                    App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                    App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_WPC2IndCmdState_prev !=
                    App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
                 ((App_Model_DW.Var_WPC2IndCmdState_prev != App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start == WPC2IndCmdState__ErrorFadeOut)))) {
              App_Model_DW.is_RWPCINDAnimation_Error = Ap_IN_RWPCINDAnimationError_Off;
              enter_atomic_RWPCINDAnimationEr();
            } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_WPC2IndCmdState_prev != App_Model_DW.Var_WPC2IndCmdState_start) && ((uint32)App_Model_DW.Var_WPC2IndCmdState_start
              == WPC2IndCmdState__ErrorFadeIn))) {
              sint32 i_previousEvent;
              App_Model_DW.is_RWPCINDAnimation_Error = App_IN_RWPCINDAnimationError_On;
              i_previousEvent = App_Model_DW.sfEvent_c1ob;
              App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
              if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
                App_Model_INDFadeIn_kcqh();
              }

              App_Model_DW.sfEvent_c1ob = i_previousEvent;
              App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
              App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
            } else {
              App_Model_INDErrorOnOut_igbp();
            }
          }
        }
      }
      break;

     case IN_RWPCINDAnimationError_P_aelk:
      {
        PreSyncAct tmp;

        /* 1 */
        tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
        if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreNon;
        } else {
          /* 2 */
          tmp = App_Model_B.Var_PreSyncAct_jsc5;
          if ((uint32)tmp == PreSyncAct__WPC2) {
            App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreRWP;
          } else {
            WPCIndUSMState tmp_0;

            /* DataTypeConversion: '<S613>/Data Type Conversion5' */
            /* 3 */
            tmp_0 = App_Model_B.BCAN_RX_C_WPCIndUSMState;
            if (((App_Model_DW.Timer_INDFadeIn_g1fs >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__WPCWPC2) && (((App_Model_DW.Var_WPCIndCmdState_prev !=
                    App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__1stChrgFadeIn)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                    App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__2ndChrgFadeIn)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                    App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__3rdChrgFadeIn)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                    App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__ChrgFadeOut)) || ((App_Model_DW.Var_WPCIndCmdState_prev !=
                    App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) || (((uint32)tmp_0 != WPCIndUSMState__Type2) &&
                 ((App_Model_DW.Var_WPCIndCmdState_prev != App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start == WPCIndCmdState__ErrorFadeOut)))) {
              App_Model_DW.is_RWPCINDAnimation_Error = Ap_IN_RWPCINDAnimationError_Off;
              enter_atomic_RWPCINDAnimationEr();
            } else if (((uint32)tmp_0 != WPCIndUSMState__Type2) && ((App_Model_DW.Var_WPCIndCmdState_prev != App_Model_DW.Var_WPCIndCmdState_start) && ((uint32)App_Model_DW.Var_WPCIndCmdState_start ==
              WPCIndCmdState__ErrorFadeIn))) {
              sint32 i_previousEvent;
              App_Model_DW.is_RWPCINDAnimation_Error = App_IN_RWPCINDAnimationError_On;
              i_previousEvent = App_Model_DW.sfEvent_c1ob;
              App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
              if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
                App_Model_INDFadeIn_kcqh();
              }

              App_Model_DW.sfEvent_c1ob = i_previousEvent;
              App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
              App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
            } else {
              App_Model_INDErrorOnOut_igbp();
            }
          }
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
static void IND_Animation_Sync_Control_ftqp(const C_WPCIndSyncVal *BCAN_RX_C_WPCIndSyncVal)
{
  switch (App_Model_DW.is_IND_Animation_Sync_Cont_mjjk) {
   case Ap_IN_RWPCINDAnimation_Charging:
    {
      /* Update for Merge generated from: '<S465>/Merge' */
      if (((App_Model_DW.WPCIndUSMState_prev_nqvt != App_Model_DW.WPCIndUSMState_start_dh2i) && ((uint32)App_Model_DW.WPCIndUSMState_start_dh2i == WPCIndUSMState__Type1)) || ((uint32)
           App_Model_B.C_WPCWarning_epwi != PhoneCharging)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        if ((uint32)App_Model_DW.is_RWPCINDAnimation_Charging == IN_RWPCINDAnimationCharging_Act) {
          switch (App_Model_DW.is_RWPCINDAnimationCharging_Act) {
           case IN_RWPCINDAnimationCharging_1st:
            exit_internal_RWPCINDAnimationC();
            g_previousEvent = App_Model_DW.sfEvent_c1ob;
            App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
              App_Model_INDLight_jhwd();
            }

            App_Model_DW.sfEvent_c1ob = g_previousEvent;
            App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_RWPCINDAnimationCharging_2nd:
            exit_internal_RWPCINDAnima_a1gb();
            g_previousEvent = App_Model_DW.sfEvent_c1ob;
            App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
              App_Model_INDLight_jhwd();
            }

            App_Model_DW.sfEvent_c1ob = g_previousEvent;
            App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_RWPCINDAnimationCharging_3rd:
            exit_internal_RWPCINDAnima_aoy1();
            g_previousEvent = App_Model_DW.sfEvent_c1ob;
            App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
              App_Model_INDLight_jhwd();
            }

            App_Model_DW.sfEvent_c1ob = g_previousEvent;
            App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           case IN_RWPCINDAnimationCharging_Off:
            exit_internal_RWPCINDAnima_mj5o();
            g_previousEvent = App_Model_DW.sfEvent_c1ob;
            App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
            if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
              App_Model_INDLight_jhwd();
            }

            App_Model_DW.sfEvent_c1ob = g_previousEvent;
            App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
            break;

           default:
            /* no actions */
            break;
          }

          /* CancelTimer에서 StartTimer로 변경 221216 */
          g_previousEvent = App_Model_DW.sfEvent_c1ob;
          App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
          if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
            App_Model_INDLight_jhwd();
          }

          App_Model_DW.sfEvent_c1ob = g_previousEvent;
          App_Model_DW.is_RWPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        } else {
          App_Model_DW.is_RWPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        }

        g_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_Mo_IN_RWPCINDAnimation_Init;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.sfEvent_c1ob = g_previousEvent;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
        App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
      } else {
        switch (App_Model_DW.is_RWPCINDAnimation_Charging) {
         case IN_RWPCINDAnimationCharging_Act:
          RWPCINDAnimationCharging_Active();
          break;

         case IN_RWPCINDAnimationCharging_Pre:
          {
            /* 1 */
            if (App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) {
              sint32 g_previousEvent;
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_c1ob;
              App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
                App_Model_INDLight_jhwd();
              }

              App_Model_DW.sfEvent_c1ob = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_RWPCINDAnimation(BCAN_RX_C_WPCIndSyncVal);
            }
          }
          break;

         case IN_RWPCINDAnimationChargin_hbnm:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
            if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Pre;

              /* 2 */
            } else if ((App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_mhlo !=
              App_Model_DW.Input_CAN_WPC2IndSyncVal_s_mifz) || (App_Model_DW.Var_WPC2IndCmdState_prev != App_Model_DW.Var_WPC2IndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_c1ob;
              App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
                App_Model_INDLight_jhwd();
              }

              App_Model_DW.sfEvent_c1ob = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_RWPCINDAnimation(BCAN_RX_C_WPCIndSyncVal);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_RWPCINDAnimationChargin_k15v:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
            if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Pre;

              /* 2  */
            } else if ((App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) && ((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) && ((App_Model_DW.Input_CAN_WPCIndSyncVal_pr_jzlo !=
                         App_Model_DW.Input_CAN_WPCIndSyncVal_st_iach) || (App_Model_DW.Var_WPCIndCmdState_prev != App_Model_DW.Var_WPCIndCmdState_start))) {
              sint32 g_previousEvent;
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Act;
              g_previousEvent = App_Model_DW.sfEvent_c1ob;
              App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
              if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
                App_Model_INDLight_jhwd();
              }

              App_Model_DW.sfEvent_c1ob = g_previousEvent;

              /* CancelTimer추가 221216 */
              enter_internal_RWPCINDAnimation(BCAN_RX_C_WPCIndSyncVal);
            } else {
              /* no actions */
            }
          }
          break;

         case IN_RWPCINDAnimationChargin_jfzc:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
            if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Pre;
            } else {
              /* 2 */
              tmp = App_Model_B.Var_PreSyncAct_jsc5;
              if ((uint32)tmp == PreSyncAct__WPC) {
                App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationChargin_k15v;

                /* 3  */
              } else if ((App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__WPC2WPC) && ((App_Model_DW.Input_CAN_WPC2IndSyncVal_p_mhlo !=
                           App_Model_DW.Input_CAN_WPC2IndSyncVal_s_mifz) || (App_Model_DW.Var_WPC2IndCmdState_prev != App_Model_DW.Var_WPC2IndCmdState_start))) {
                sint32 g_previousEvent;
                App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Act;
                g_previousEvent = App_Model_DW.sfEvent_c1ob;
                App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
                if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
                  App_Model_INDLight_jhwd();
                }

                App_Model_DW.sfEvent_c1ob = g_previousEvent;

                /* CancelTimer추가 221216 */
                enter_internal_RWPCINDAnimation(BCAN_RX_C_WPCIndSyncVal);
              } else {
                /* no actions */
              }
            }
          }
          break;

         case IN_RWPCINDAnimationChargin_lbn5:
          {
            PreSyncAct tmp;

            /* 1 */
            tmp = App_Model_DW.Var_PreSyncAct_start_ntz3;
            if ((App_Model_DW.Var_PreSyncAct_prev_ojgc != tmp) && ((uint32)tmp == PreSyncAct__Off)) {
              App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Pre;
            } else {
              /* 2 */
              tmp = App_Model_B.Var_PreSyncAct_jsc5;
              if ((uint32)tmp == PreSyncAct__WPC2) {
                App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationChargin_hbnm;

                /* 3 */
              } else if ((App_Model_DW.Timer_INDLight_ewv0 >= (uint32)((uint8)100U)) && ((uint32)tmp == PreSyncAct__WPCWPC2) && ((App_Model_DW.Input_CAN_WPCIndSyncVal_pr_jzlo !=
                           App_Model_DW.Input_CAN_WPCIndSyncVal_st_iach) || (App_Model_DW.Var_WPCIndCmdState_prev != App_Model_DW.Var_WPCIndCmdState_start))) {
                sint32 g_previousEvent;
                App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Act;
                g_previousEvent = App_Model_DW.sfEvent_c1ob;
                App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
                if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
                  App_Model_INDLight_jhwd();
                }

                App_Model_DW.sfEvent_c1ob = g_previousEvent;

                /* CancelTimer추가 221216 */
                enter_internal_RWPCINDAnimation(BCAN_RX_C_WPCIndSyncVal);
              } else {
                /* no actions */
              }
            }
          }
          break;

         default:
          /* no actions */
          break;
        }
      }
    }
    break;

   case App_M_IN_RWPCINDAnimation_Error:
    App_Mode_RWPCINDAnimation_Error();
    break;

   case App_Mo_IN_RWPCINDAnimation_Init:
    {
      C_WPCWarning tmp_0;

      /* Update for Merge generated from: '<S465>/Merge' */
      /* 2 */
      tmp_0 = App_Model_B.C_WPCWarning_epwi;

      /* DataTypeConversion: '<S613>/Data Type Conversion5' incorporates:
       *  DataTypeConversion: '<S616>/Data Type Conversion67'
       */
      if (((uint32)tmp_0 == PhoneCharging) && ((uint32)App_Model_B.BCAN_RX_C_WPCIndUSMState == WPCIndUSMState__Type2)) {
        sint32 g_previousEvent;

        /* For AnimationTypeChange */
        App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = Ap_IN_RWPCINDAnimation_Charging;
        g_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App_M_event_StartTimer_INDLight;
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        App_Model_DW.sfEvent_c1ob = g_previousEvent;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__3rdSync;
        App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;

        /* 1 */
        switch (App_Model_B.Var_PreSyncAct_jsc5) {
         case PreSyncAct__WPC:
          App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationChargin_k15v;
          break;

         case PreSyncAct__WPC2:
          /* 2 */
          App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationChargin_hbnm;
          break;

         case PreSyncAct__WPC2WPC:
          /* 3 */
          App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationChargin_jfzc;
          break;

         case PreSyncAct__WPCWPC2:
          /* 4 */
          App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationChargin_lbn5;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_RWPCINDAnimation_Charging = IN_RWPCINDAnimationCharging_Pre;
          break;
        }

        /* 3 */
      } else if (((uint32)tmp_0 == Charging_error) && ((uint32)App_Model_B.INT_b_SyncAmber_RWPC == On)) {
        sint32 g_previousEvent;
        App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_M_IN_RWPCINDAnimation_Error;
        g_previousEvent = App_Model_DW.sfEvent_c1ob;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_StartTimer_INDFadeIn;
        if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
          App_Model_INDFadeIn_kcqh();
        }

        App_Model_DW.sfEvent_c1ob = g_previousEvent;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__ErrorOn;
        App_Model_TypeCont_ljmv();

        /* 1 */
        switch (App_Model_B.Var_PreSyncAct_jsc5) {
         case PreSyncAct__WPC:
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreWPC;
          break;

         case PreSyncAct__WPC2:
          /* 2 */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreRWP;
          break;

         case PreSyncAct__WPC2WPC:
          /* 3 */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_P_gplk;
          break;

         case PreSyncAct__WPCWPC2:
          /* 4 */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_P_aelk;
          break;

         default:
          /* 5
             Var_PreSyncAct == PreSyncAct__Off */
          App_Model_DW.is_RWPCINDAnimation_Error = IN_RWPCINDAnimationError_PreNon;
          break;
        }
      } else {
        /* no actions */
      }

      /* End of DataTypeConversion: '<S613>/Data Type Conversion5' */
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S625>/USM_WPC_LPConditionJdg' */
static void App_Model_LPConditionHold_fjxw(void)
{
  switch (App_Model_DW.is_LPConditionHold) {
   case App_IN_LPConditionHold_Off_kvlq:
    if (App_Model_DW.sfEvent_czwh == (sint32)event_StartTimer_LPConditi_i0nb) {
      App_Model_DW.is_LPConditionHold = App__IN_LPConditionHold_On_lcw3;
    }
    break;

   case App__IN_LPConditionHold_On_lcw3:
    {
      switch (App_Model_DW.sfEvent_czwh) {
       case event_CancelTimer_LPCondit_nxtu:
        App_Model_DW.is_LPConditionHold = App_IN_LPConditionHold_Off_kvlq;
        App_Model_DW.Timer_LPConditionHold = 0U;
        break;

       case event_StartTimer_LPConditi_i0nb:
        App_Model_DW.Timer_LPConditionHold = 0U;
        App_Model_DW.is_LPConditionHold = App__IN_LPConditionHold_On_lcw3;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPConditionHold + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_LPConditionHold + 1U) < App_Model_DW.Timer_LPConditionHold) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPConditionHold = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S625>/USM_WPC_LPConditionJdg' */
static void App__LPConditionTimerCheck_mlkd(void)
{
  if ((App_Model_DW.m_ProfileGuestWPCUSM_App_prev != App_Model_DW.m_ProfileGuestWPCUSM_App_start) || (App_Model_DW.m_ProfileOneWPCUSM_App_prev != App_Model_DW.m_ProfileOneWPCUSM_App_start) ||
      (App_Model_DW.m_ProfileTwoWPCUSM_App_prev != App_Model_DW.m_ProfileTwoWPCUSM_App_start) || (App_Model_DW.m_ProfileThreeWPCUSM_App_prev != App_Model_DW.m_ProfileThreeWPCUSM_App_start) ||
      (App_Model_DW.m_RWPCUSM_App_prev_bsqc != App_Model_DW.m_RWPCUSM_App_start_eznj)) {
    sint32 c_previousEvent;
    App_Model_DW.ECUResetEnable = 0U;
    c_previousEvent = App_Model_DW.sfEvent_czwh;
    App_Model_DW.sfEvent_czwh = (sint32)event_StartTimer_LPConditi_i0nb;
    if ((uint32)App_Model_DW.is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold_fjxw();
    }

    App_Model_DW.sfEvent_czwh = c_previousEvent;
  } else if (App_Model_DW.Timer_LPConditionHold >= 100U) {
    sint32 c_previousEvent;

    /* 1s */
    App_Model_DW.ECUResetEnable = 1U;
    c_previousEvent = App_Model_DW.sfEvent_czwh;
    App_Model_DW.sfEvent_czwh = (sint32)event_CancelTimer_LPCondit_nxtu;
    if ((uint32)App_Model_DW.is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold_fjxw();
    }

    App_Model_DW.sfEvent_czwh = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Model step function */
void Model_TE_Runnable(void)
{
  /* local block i/o variables */
  IDT_NvM_STR rtb_TmpSignalConversionAtR_NvM_;
  uint16 rtb_BCAN_RX_C_CLU_DisSpdVal_KPH;
  uint16 rtb_UART_WPC2_ChargingCurrent;
  uint16 rtb_FAN_PWM;
  uint16 rtb_BCAN_RX_C_CLU_DisSpdVa_fwgw;
  uint16 rtb_UART_WPC2_ChargingCurr_mg2z;
  uint16 rtb_FAN_PWM_eua1;
  uint16 rtb_BCAN_RX_C_CLU_DisSpdVa_dmz0;
  uint16 rtb_FAN_PWM_luhf;
  uint16 rtb_FAN_PWM_kvyy;
  sint16 rtb_UART_WPC2_CoilTempDegree;
  sint16 rtb_UART_WPC2_CoilTempDegr_k04h;
  uint8 rtb_LCAN_RX_LC_IAU_Status;
  uint8 rtb_WPCMode_LPConditionFlag_wri;
  uint8 rtb_TempSnsrError_LPConditionFl;
  uint8 rtb_SMKLF_LPConditionFlag_write;
  uint8 rtb_OverTempDetect_LPConditionF;
  uint8 rtb_OverCurrent_LPConditionFlag;
  uint8 rtb_NFCMode_LPConditionFlag_wri;
  uint8 rtb_WPCMain_LPConditionFlag_wri;
  uint8 rtb_FAN_LPConditionFlag_write;
  uint8 rtb_LCAN_RX_LC_IAU_Status_cdna;
  uint8 rtb_WPCMode_LPConditionFla_hka2;
  uint8 rtb_TempSnsrError_LPCondit_oh14;
  uint8 rtb_SMKLF_LPConditionFlag__j4w3;
  uint8 rtb_OverTempDetect_LPCondi_a4lc;
  uint8 rtb_OverCurrent_LPConditio_hfnx;
  uint8 rtb_NFCMode_LPConditionFla_ogfp;
  uint8 rtb_WPCMain_LPConditionFla_nrse;
  uint8 rtb_FAN_LPConditionFlag_wr_okst;
  uint8 rtb_LCAN_RX_LC_IAU_Status_b5da;
  uint8 rtb_WPCMode_LPConditionFla_pady;
  uint8 rtb_TempSnsrError_LPCondit_egth;
  uint8 rtb_SMKLF_LPConditionFlag__fnej;
  uint8 rtb_OverTempDetect_LPCondi_bvam;
  uint8 rtb_OverCurrent_LPConditio_p4qh;
  uint8 rtb_NFCMode_LPConditionFla_jmfo;
  uint8 rtb_WPCMain_LPConditionFla_cfn0;
  uint8 rtb_FAN_LPConditionFlag_wr_ddyr;
  uint8 rtb_WPCMode_LPConditionFla_e5bi;
  uint8 rtb_TempSnsrError_LPCondit_lcr4;
  uint8 rtb_SMKLF_LPConditionFlag__edfo;
  uint8 rtb_OverTempDetect_LPCondi_l4hp;
  uint8 rtb_OverCurrent_LPConditio_ivuq;
  uint8 rtb_NFCMode_LPConditionFla_i45m;
  uint8 rtb_WPCMain_LPConditionFla_g2vh;
  uint8 rtb_FAN_LPConditionFlag_wr_djmc;
  boolean rtb_R_CS_Mode_ApplicationInit;
  WPCType rtb_NvM_WPCType;
  WPCType rtb_NvM_WPCType_ge5s;
  WPCType rtb_NvM_WPCType_ccn1;
  WPCStatus rtb_INT_SWPCStatus;
  WPCStatus rtb_INT_RWPCStatus;
  WPCIndUSMState rtb_BCAN_RX_C_WPCIndUSMState;
  WPCIndUSMState rtb_BCAN_RX_C_WPCIndUSMSta_n1ki;
  WPCAnimationNvalueSet rtb_BCAN_RX_C_CF_Gway_WPCAnimat;
  WPCAnimationNvalueSet rtb_BCAN_RX_C_CF_Gway_RWPCAnima;
  WPC2IndSyncVal rtb_BCAN_RX_C_WPC2IndSyncVal;
  RheostatOption rtb_NvM_RheostatOption;
  RheostatOption rtb_NvM_RheostatOption_nwi3;
  RheostatOption rtb_NvM_RheostatOption_k44v;
  RWPCIndSyncVal rtb_BCAN_RX_C_RWPCIndSyncVal;
  OwnerPairingAdvertisingReq rtb_LCAN_RX_LC_OwnerPairingAdve;
  OnThePad rtb_NFC2_NfcOnThePad;
  OnThePad rtb_WCT2_ChargingOnthePad;
  OnThePad rtb_WCT2_ObjectOnthePad;
  OnThePad rtb_NFC1_NfcOnThePad;
  OnThePad rtb_NFC2_NfcOnThePad_ly4s;
  OnThePad rtb_WCT1_ChargingOnthePad;
  OnThePad rtb_WCT1_ObjectOnthePad;
  OnThePad rtb_WCT2_ChargingOnthePad_nsi0;
  OnThePad rtb_WCT2_ObjectOnthePad_nmu4;
  LatchTypeOption rtb_BCAN_Latch_TypeOption_DRV;
  LatchTypeOption rtb_BCAN_Latch_TypeOption__pu2k;
  LatchTypeOption rtb_BCAN_Latch_TypeOption__ngmo;
  LC_WPC_NFCDetection rtb_NFC2_LC_WPC_NFCDetection;
  LC_WPC_NFCDetection rtb_NFC1_LC_WPC_NFCDetection;
  LC_WPC_NFCDetection rtb_NFC2_LC_WPC_NFCDetecti_bfk2;
  LC_IAUWPCNFCcmd rtb_LCAN_RX_LC_WPC2_IAUWPCNFCcm;
  LC_IAUWPCNFCcmd rtb_LCAN_RX_LC_WPC_IAUWPCNFCcmd;
  LC_IAUWPCNFCcmd rtb_LCAN_RX_LC_WPC2_IAUWPC_ar2p;
  INDContType rtb_NvM_INDContType;
  INDContType rtb_NvM_INDContType_gaoc;
  INDContType rtb_NvM_INDContType_mlsp;
  IAU_OwnerPhnRegRVal rtb_LCAN_RX_LC_OwnerKey_Reg_Sta;
  FANSpeed rtb_BCAN_RX_C_FANSpeedSet;
  FANDutyRatio rtb_DataStoreRead2;
  FANDutyRatio rtb_DataStoreRead4;
  FANDutyRatio rtb_DataStoreRead5_f43h;
  FANDutyRatio rtb_DataStoreRead9;
  DeviceState rtb_UART_WPC2_DeviceState;
  DeviceState rtb_UART_WPC2_DeviceState_itii;
  C_WPCWarning rtb_INT_RWPCWarning;
  C_WPCOnOffNvalueSet rtb_BCAN_RX_C_WPC2OnOffNvalueSe;
  C_WPCOnOffNvalueSet rtb_DataStoreRead3;
  C_WPCOnOffNvalueSet rtb_DataStoreRead6_dtsz;
  C_WPCOnOffNvalueSet rtb_DataStoreRead7_esnu;
  C_WPCOnOffNvalueSet rtb_DataStoreRead8_cqkz;
  C_WPCOnOffNvalueSet rtb_BCAN_RX_C_WPCOnOffNvalueSet;
  C_WPCOnOffNvalueSet rtb_BCAN_RX_C_WPC2OnOffNva_lh4l;
  C_WPCOnOffNvalueSet rtb_BCAN_RX_C_RWPCOnOffNvalueSe;
  C_WPCOnOffNvalueSet rtb_DataStoreRead3_kbgw;
  C_WPCOnOffNvalueSet rtb_DataStoreRead6_kuqo;
  C_WPCOnOffNvalueSet rtb_DataStoreRead7_kjr0;
  C_WPCOnOffNvalueSet rtb_DataStoreRead8_pjyy;
  C_USMReset rtb_BCAN_RX_C_CLU_ClusterUSM;
  C_USMReset rtb_BCAN_RX_C_USMReset;
  C_USMReset rtb_BCAN_RX_C_CLU_ClusterU_loak;
  C_USMReset rtb_BCAN_RX_C_CLU_ClusterU_nv2a;
  C_ProfileIDRValue rtb_BCAN_RX_C_IAU_ProfileIDRVal;
  C_ProfileIDRValue rtb_BCAN_RX_C_CF_AVN_ProfileIDR;
  C_HEVEngOnState rtb_BCAN_RX_C_HCU_HevRdySta;
  C_HEVEngOnState rtb_BCAN_RX_C_HCU_HevRdySt_cani;
  C_HEVEngOnState rtb_BCAN_RX_C_HCU_HevRdySt_m21u;
  C_EngineState rtb_BCAN_RX_C_ENG_EngSta;
  C_EngineState rtb_BCAN_RX_C_ENG_EngSta_ob2c;
  C_EngineState rtb_BCAN_RX_C_ENG_EngSta_dbk1;
  Bool rtb_NvM_EVOpt;
  Bool rtb_ADC_BatSysStateFault;
  Bool rtb_Uds_m_NFCOption;
  Bool rtb_BCAN_RX_C_CLU_DtntOutSta;
  Bool rtb_BCAN_RX_C_Lamp_IntTailLmpOn;
  Bool rtb_BCAN_AstDrSw;
  Bool rtb_BCAN_DrvDrSw;
  Bool rtb_BCAN_RLDrSw;
  Bool rtb_BCAN_RRDrSw;
  Bool rtb_BCAN_AstDrSw_SBCM;
  Bool rtb_BCAN_DrvDrSw_SBCM;
  Bool rtb_BCAN_RLDrSw_SBCM;
  Bool rtb_BCAN_RRDrSw_SBCM;
  Bool rtb_NFC1_b_MultiCardDetectionSt;
  Bool rtb_NFC2_LPCD_Wakeup;
  Bool rtb_NFC2_b_MultiCardDetectionSt;
  Bool rtb_UART_WPC2_PhoneLeft;
  Bool rtb_UART_WPC2_Temp_SnsrError;
  Bool rtb_Uds_LPConditionFlag;
  Bool rtb_b_SyncAmber;
  Bool rtb_b_CmdAmberSync;
  Bool rtb_NvM_EVOpt_mj52;
  Bool rtb_ADC_BatSysStateFault_e4zi;
  Bool rtb_BCAN_RX_C_CLU_DtntOutS_hzdo;
  Bool rtb_BCAN_RX_C_Lamp_IntTail_eket;
  Bool rtb_BCAN_AstDrSw_mqsr;
  Bool rtb_BCAN_DrvDrSw_mxls;
  Bool rtb_BCAN_RLDrSw_is22;
  Bool rtb_BCAN_RRDrSw_hqit;
  Bool rtb_BCAN_AstDrSw_SBCM_n4f0;
  Bool rtb_BCAN_DrvDrSw_SBCM_pmk5;
  Bool rtb_BCAN_RLDrSw_SBCM_g1uf;
  Bool rtb_BCAN_RRDrSw_SBCM_j2dk;
  Bool rtb_NFC1_b_MultiCardDetect_p5dp;
  Bool rtb_INT_RWPC_b_PhnLeftChk_Enabl;
  Bool rtb_NFC1_LPCD_Wakeup;
  Bool rtb_NFC2_LPCD_Wakeup_npea;
  Bool rtb_NFC2_b_MultiCardDetect_gfij;
  Bool rtb_NvM_IndUSMOption;
  Bool rtb_UART_WPC2_PhoneLeft_i3nv;
  Bool rtb_UART_WPC2_Temp_SnsrErr_lnip;
  Bool rtb_Uds_LPConditionFlag_l0d5;
  Bool rtb_Uds_m_NFCOption_k4ut;
  Bool rtb_b_SyncAmber_jg2q;
  Bool rtb_b_CmdAmberSync_pbbn;
  Bool rtb_NvM_EVOpt_cmz4;
  Bool rtb_ADC_BatSysStateFault_ibda;
  Bool rtb_Uds_m_NFCOption_l1mx;
  Bool rtb_BCAN_RX_C_CLU_DtntOutS_gff4;
  Bool rtb_BCAN_RX_C_Lamp_IntTail_i0kk;
  Bool rtb_BCAN_AstDrSw_f1gi;
  Bool rtb_BCAN_DrvDrSw_oqpb;
  Bool rtb_BCAN_RLDrSw_bqn3;
  Bool rtb_BCAN_RRDrSw_dsi0;
  Bool rtb_BCAN_AstDrSw_SBCM_hsy4;
  Bool rtb_BCAN_DrvDrSw_SBCM_md2x;
  Bool rtb_BCAN_RLDrSw_SBCM_jzjl;
  Bool rtb_BCAN_RRDrSw_SBCM_dfpz;
  Bool rtb_NFC1_b_MultiCardDetect_daa0;
  Bool rtb_NFC2_b_MultiCardDetect_n4aq;
  Bool rtb_Uds_LPConditionFlag_f3pw;
  Bool rtb_b_SyncLED;
  Bool rtb_b_CmdLEDSync;
  Bool rtb_b_SyncLED_ipyt;
  Bool rtb_b_CmdLEDSync_go1s;
  IDT_ADC_STR rtb_TmpSignalConversionAtR_ADC_;
  IDT_CAN_RX_STR rtb_TmpSignalConversionAtR_CAN_;
  IDT_Model_STR rtb_BusCreator;
  IDT_NFC_STR rtb_TmpSignalConversionAtR_NFC_;
  IDT_UART_STR rtb_TmpSignalConversionAtR_UART;
  IDT_Uds_STR rtb_TmpSignalConversionAtR_Uds_;
  IDT_WCT_STR rtb_TmpSignalConversionAtR_WCT_;
  WPCIndUSMState Output_INT_WPCIndUSMState;

  /* SignalConversion generated from: '<Root>/In Bus Element' */
  (void)Rte_Read_R_ADC_ADC_STR(&rtb_TmpSignalConversionAtR_ADC_);

  /* SignalConversion generated from: '<Root>/In Bus Element6' */
  (void)Rte_Read_R_NvM_NvM_STR(&rtb_TmpSignalConversionAtR_NvM_);

  /* SignalConversion generated from: '<Root>/In Bus Element12' */
  (void)Rte_Read_R_Uds_Uds_STR(&rtb_TmpSignalConversionAtR_Uds_);

  /* SignalConversion generated from: '<Root>/Bus Element In2' */
  (void)Rte_Read_R_CAN_RX_CAN_RX_STR(&rtb_TmpSignalConversionAtR_CAN_);

  /* SignalConversion generated from: '<Root>/Bus Element In4' */
  (void)Rte_Read_R_NFC_NFC_STR(&rtb_TmpSignalConversionAtR_NFC_);

  /* SignalConversion generated from: '<Root>/Bus Element In6' */
  (void)Rte_Read_R_UART_UART_STR(&rtb_TmpSignalConversionAtR_UART);

  /* SignalConversion generated from: '<Root>/Bus Element In7' */
  (void)Rte_Read_R_WCT_WCT_STR(&rtb_TmpSignalConversionAtR_WCT_);

  /* Outputs for Atomic SubSystem: '<Root>/AppInit' */
  /* FunctionCaller: '<S1>/R_CS_Mode_ApplicationInit'
   *
   * Block description for '<S1>/R_CS_Mode_ApplicationInit':
   *  AppInitFlag && NvMInitFlag 완료 시, Application 구동 시작.
   */
  Rte_Call_R_CS_Mode_ApplicationInit(&rtb_R_CS_Mode_ApplicationInit);

  /* End of Outputs for SubSystem: '<Root>/AppInit' */

  /* Outputs for Triggered SubSystem: '<Root>/AppInit_DataRead' */
  App_Model_AppInit_DataRead(rtb_R_CS_Mode_ApplicationInit, &rtb_TmpSignalConversionAtR_NvM_);

  /* End of Outputs for SubSystem: '<Root>/AppInit_DataRead' */

  /* Outputs for Enabled SubSystem: '<Root>/App_Model_TE_Sys' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtb_R_CS_Mode_ApplicationInit) {
    sint32 c_previousEvent;
    C_WPCIndSyncVal tmp_c;
    C_WPCIndSyncVal tmp_d;
    WPC2IndSyncVal tmp_a;
    WPC2IndSyncVal tmp_b;
    WPCIndCmdState tmp_g;
    WPCIndCmdState tmp_h;
    WPCPreSyncAct tmp_e;
    App_Model_DW.App_Model_TE_Sys_MODE = true;

    /* Outputs for Enabled SubSystem: '<S3>/DualWPC' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    /* RelationalOperator: '<S12>/Compare' incorporates:
     *  Constant: '<S12>/Constant'
     *  DataTypeConversion: '<S3>/Data Type Conversion2'
     */
    if (rtb_TmpSignalConversionAtR_NvM_.WPC_NAME == (uint8)DWPC) {
      Bool rtb_NFC1_LPCD_Wakeup_o5zt;
      Bool rtb_NFC2_LPCD_Wakeup_ptyj;
      Bool tmp_6;
      Bool tmp_7;
      OnThePad rtb_WCT1_ChargingOnthePad_c3xl;
      OnThePad rtb_WCT1_ObjectOnthePad_a1dt;
      OnThePad rtb_WCT2_ChargingOnthePad_etx4;
      OnThePad rtb_WCT2_ObjectOnthePad_izrx;
      WPCStatus tmp_2;
      WPCStatus tmp_3;
      WPCStatus tmp_4;
      WPCStatus tmp_5;
      if (!App_Model_DW.DualWPC_MODE) {
        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay' */
        App_Model_DW.UnitDelay_DSTATE_d0ul = WPCIndUSMState__Default;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay2' */
        App_Model_DW.UnitDelay2_DSTATE = WPC2IndSyncVal__Default;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay4' */
        App_Model_DW.UnitDelay4_DSTATE_kskc = WPCIndCmdState__Default;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay5' */
        App_Model_DW.UnitDelay5_DSTATE = WPC2IndCmdState__Default;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay9' */
        App_Model_DW.UnitDelay9_DSTATE_afvw = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay10' */
        App_Model_DW.UnitDelay10_DSTATE_ijjh = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay13' */
        App_Model_DW.UnitDelay13_DSTATE = PreSyncAct__Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay15' */
        App_Model_DW.UnitDelay15_DSTATE_kgaf = WPCWarningOff;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay7' */
        App_Model_DW.UnitDelay7_DSTATE_m4bk = ModeOff;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay8' */
        App_Model_DW.UnitDelay8_DSTATE = ((uint8)0U);

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay17' */
        App_Model_DW.UnitDelay17_DSTATE = ((uint8)0U);

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay18' */
        App_Model_DW.UnitDelay18_DSTATE_ghv5 = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay20' */
        App_Model_DW.UnitDelay20_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay21' */
        App_Model_DW.UnitDelay21_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay6' */
        App_Model_DW.UnitDelay6_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay1' */
        App_Model_DW.UnitDelay1_DSTATE = WPCIndSyncVal__Default;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay11' */
        App_Model_DW.UnitDelay11_DSTATE_ibvb = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay12' */
        App_Model_DW.UnitDelay12_DSTATE_kt23 = Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay14' */
        App_Model_DW.UnitDelay14_DSTATE = PreSyncAct__Off;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay16' */
        App_Model_DW.UnitDelay16_DSTATE_fcip = WPCWarningOff;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay3' */
        App_Model_DW.UnitDelay3_DSTATE_lcrf = ModeOff;

        /* InitializeConditions for UnitDelay: '<S431>/Unit Delay19' */
        App_Model_DW.UnitDelay19_DSTATE_oefu = Off;

        /* SystemReset for Chart: '<S427>/DoorOpenCloseStateFunctionFlowGraph' */
        DoorOpenCloseStateFunctio_Reset(&App_Model_B.b_AstDrSw_c4ax, &App_Model_B.b_DrvDrSw_m4ht, &App_Model_B.b_RLDrSw_m3r3, &App_Model_B.b_RRDrSw_cbkj, &App_Model_DW.sf_DoorOpenCloseStateFunctionFl);

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S23>/TemperatureSensorErrorDetect_Function' */
        TemperatureSensorErr_h0ez_Reset(&App_Model_B.b_TempSensorFault_ahdl, &App_Model_B.b_Timer_TempSensor_Check_dej2);

        /* End of SystemReset for SubSystem: '<S23>/TemperatureSensorErrorDetect_Function' */

        /* SystemReset for Atomic SubSystem: '<S23>/PreventionSMK_LF_Interference_Function' */
        PreventionSMK_LF_Int_jzga_Reset(&App_Model_B.b_LFState_fv4t);

        /* End of SystemReset for SubSystem: '<S23>/PreventionSMK_LF_Interference_Function' */

        /* SystemReset for Atomic SubSystem: '<S23>/OverCurrentDetecting_Function' */
        OverCurrentDetecting_Func_Reset(&App_Model_B.b_CurrentFault_jcbo, &App_Model_B.b_Timer_OvrCurr_dt5l, &App_Model_B.b_Timer_ReOvrCurr_dylv);

        /* End of SystemReset for SubSystem: '<S23>/OverCurrentDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S23>/OverTemperatureDetecting_Function' */
        OverTemperatureDetecting__Reset(&App_Model_B.b_TemperatureFault_c04g, &App_Model_B.b_Timer_OverTemp_p3xh);

        /* End of SystemReset for SubSystem: '<S23>/OverTemperatureDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S23>/WPC_PhoneLeftDetectingControl_Function' */
        WPC_PhoneLeftDetecti_esdl_Reset(&App_Model_B.Output_PhoneLeftWarningWPC_jnov);

        /* End of SystemReset for SubSystem: '<S23>/WPC_PhoneLeftDetectingControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S19>/WPC_MainControl_Function' */
        WPC_MainControl_Function_Reset();

        /* End of SystemReset for SubSystem: '<S19>/WPC_MainControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S22>/FAN_Control_Function' */
        App__FAN_Control_Function_Reset(&rtb_FAN_PWM_kvyy, &App_Model_B.FANDutyRatioSta_lwkf);

        /* End of SystemReset for SubSystem: '<S22>/FAN_Control_Function' */

        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* SystemReset for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
        RWPC_IND_Command_State_Co_Reset(&App_Model_B.Var_RWPCIndCmdState_mh2c, &App_Model_DW.sf_RWPC_IND_Command_State_Contr);

        /* SystemReset for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
        App_Model_DW.is_active_INDFadeIn_oxbo = 0U;
        App_Model_DW.is_INDFadeIn_jkbd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDFadeOut_khxa = 0U;
        App_Model_DW.is_INDFadeOut_crlr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDLight_j5kt = 0U;
        App_Model_DW.is_INDLight_ajwi = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_IND_Animation_Sy_bgeh = 0U;
        App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_pkee = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_lvlw = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_aj4v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c197_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDLight_jkqo = 0U;
        App_Model_DW.Timer_INDFadeIn_bp2v = 0U;
        App_Model_DW.Timer_INDFadeOut_bvej = 0U;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
        App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
        App_Model_DW.Var_PreSyncAct_start_b2ke = PreSyncAct__Off;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_s_nnsr = RWPCIndSyncVal__Default;
        App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc = RWPCIndCmdState__Default;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_s_pfdf = WPC2IndSyncVal__Default;
        App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz = WPC2IndCmdState__Default;
        App_Model_DW.WPCIndUSMState_start_cume = WPCIndUSMState__Default;
        App_Model_DW.b_SyncAmber_start_hpuj = Off;

        /* SystemReset for Chart: '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
        IND_Animation_Profile_Dec_Reset(&App_Model_B.CurProfile_md3a, &App_Model_DW.sf_IND_Animation_Profile_Decisi);

        /* SystemReset for Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
        IND_Animation_USM_Setting_Reset(&App_Model_B.Output_CAN_WPCIndUSMState_kprv, &App_Model_B.Output_INT_WPCIndUSMState_bcrl, &App_Model_DW.sf_IND_Animation_USM_Setting_Co);

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC2_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S218>/TemperatureSensorErrorDetect_Function' */
        TemperatureSensorErr_hbvc_Reset(&App_Model_B.b_TempSensorFault_futc, &App_Model_B.b_Timer_TempSensor_Check_eer0);

        /* End of SystemReset for SubSystem: '<S218>/TemperatureSensorErrorDetect_Function' */

        /* SystemReset for Atomic SubSystem: '<S218>/PreventionSMK_LF_Interference_Function' */
        PreventionSMK_LF_Int_ae1o_Reset(&App_Model_B.b_LFState_kucz);

        /* End of SystemReset for SubSystem: '<S218>/PreventionSMK_LF_Interference_Function' */

        /* SystemReset for Atomic SubSystem: '<S218>/OverCurrentDetecting_Function' */
        OverCurrentDetecting_kzza_Reset(&App_Model_B.b_CurrentFault_kptm, &App_Model_B.b_Timer_OvrCurr_bvyp, &App_Model_B.b_Timer_ReOvrCurr_gm1e);

        /* End of SystemReset for SubSystem: '<S218>/OverCurrentDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S218>/OverTemperatureDetecting_Function' */
        OverTemperatureDetec_b014_Reset(&App_Model_B.b_TemperatureFault_fxyc, &App_Model_B.b_Timer_OverTemp_ce1w);

        /* End of SystemReset for SubSystem: '<S218>/OverTemperatureDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S218>/WPC_PhoneLeftDetectingControl_Function' */
        WPC_PhoneLeftDetecti_lukg_Reset(&App_Model_B.Output_PhoneLeftWarningWPC_i4ao);

        /* End of SystemReset for SubSystem: '<S218>/WPC_PhoneLeftDetectingControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S20>/WPC_MainControl_Function' */
        WPC_MainControl_Func_klre_Reset();

        /* End of SystemReset for SubSystem: '<S20>/WPC_MainControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S217>/FAN_Control_Function' */
        FAN_Control_Function_mo3f_Reset(&rtb_FAN_PWM_luhf, &App_Model_B.FANDutyRatioSta_acxf);

        /* End of SystemReset for SubSystem: '<S217>/FAN_Control_Function' */

        /* SystemReset for Atomic SubSystem: '<S217>/IND_Animation_Control_Function' */
        /* SystemReset for Chart: '<S229>/RWPC_IND_Command_State_Control_Function_State_Chart' */
        RWPC_IND_Command_State_Co_Reset(&App_Model_B.Var_RWPCIndCmdState, &App_Model_DW.sf_RWPC_IND_Command_State__b4zd);

        /* SystemReset for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_INDFadeIn_iojc = 0U;
        App_Model_DW.is_INDFadeIn_gyzm = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDFadeOut_jiqg = 0U;
        App_Model_DW.is_INDFadeOut_pilc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDLight_jxx1 = 0U;
        App_Model_DW.is_INDLight_jzsv = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_IND_Animation_Sy_mfd1 = 0U;
        App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_p2e5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c200_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDLight_pm1y = 0U;
        App_Model_DW.Timer_INDFadeIn_kzsy = 0U;
        App_Model_DW.Timer_INDFadeOut_cnjl = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
        App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
        App_Model_DW.Var_PreSyncAct_start_avlx = PreSyncAct__Off;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_s_gr5w = RWPCIndSyncVal__Default;
        App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh = RWPCIndCmdState__Default;
        App_Model_DW.Input_CAN_WPCIndSyncVal_st_kruf = WPCIndSyncVal__Default;
        App_Model_DW.Var_INT_WPCIndCmdState_start = WPCIndCmdState__Default;
        App_Model_DW.WPCIndUSMState_start_gcuc = WPCIndUSMState__Default;
        App_Model_DW.b_SyncAmber_start_bf1w = Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */
        /* End of SystemReset for SubSystem: '<S217>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC2_TE_sys' */

        /* SystemReset for Chart: '<S408>/Change_INT_NfcOnThePad' */
        App_Model_DW.is_active_c30_Jdg_DualSyncOrder = 0U;
        App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
        App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
        App_Model_DW.NfcOnThePad_1_start = OnThePad_Off;
        App_Model_DW.NfcOnThePad_2_start = OnThePad_Off;

        /* SystemReset for Chart: '<S408>/Jdg_DualWPC_Onthepad' */
        App_Model_DW.is_active_c23_Jdg_DualSyncOrder = 0U;

        /* SystemReset for Chart: '<S408>/LPCDWakeUp_Detect_DWPC_Priority' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_c47_Jdg_DualSyncOrder = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_B.Var_WPC1PreAct_bgn2 = Off;
        App_Model_B.Var_WPC2PreAct_dlkp = Off;
        App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s = Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */
        App_Model_DW.Var_OPT_WPCStatus_1_start_fipw = ModeOff;
        App_Model_DW.Var_OPT_WPCStatus_2_start_aclk = ModeOff;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s = Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S408>/Jdg_LPCDWakeUpOrder' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_c24_Jdg_DualSyncOrder = 0U;
        App_Model_B.LPCDWakeUpOrder = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_DW.Var_WPC2PreAct_start_j405 = Off;
        App_Model_DW.Var_WPC1PreAct_start_inrz = Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S408>/NFC_Detect_DWPC_Priority' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         *  Chart: '<S408>/LPCDWakeUp_Detect_DWPC_Priority'
         */
        App_Model_DW.is_active_c46_Jdg_DualSyncOrder = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_B.Var_WPC1PreAct = Off;
        App_Model_B.Var_WPC2PreAct = Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */
        App_Model_DW.Var_NFCDetection_WPC1_start = NFCDetection_Off;
        App_Model_DW.Var_OPT_WPCStatus_1_start = ModeOff;
        App_Model_DW.Var_OPT_WPCStatus_2_start = ModeOff;
        App_Model_DW.Var_NFCDetection_WPC2_start = NFCDetection_Off;

        /* SystemReset for Chart: '<S408>/Jdg_NFCDetectOrder' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_c25_Jdg_DualSyncOrder = 0U;
        App_Model_B.NFCDetectOrder = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_DW.Var_WPC2PreAct_start = Off;
        App_Model_DW.Var_WPC1PreAct_start = Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S410>/IND_Animation_WPC2_Priority_Flow_Graph' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_c35_Jdg_DualSyncOrder = 0U;
        App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_Off;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_DW.Input_INT_WPC2IndSyncVal_start = WPC2IndSyncVal__Default;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S410>/IND_Animation_RWPC_Priority_Flow_Graph' */
        IND_Animation_RWPC_Priori_Reset(&App_Model_B.Var_RWPCPreSyncAct_baek, &App_Model_DW.sf_IND_Animation_RWPC_Priority_);

        /* SystemReset for Chart: '<S410>/IND_Animation_Priority_Flow_Graph' */
        IND_Animation_Priority_Fl_Reset(&App_Model_B.Var_PreSyncAct_akzv, &App_Model_DW.sf_IND_Animation_Priority_Flow_);

        /* SystemReset for Chart: '<S410>/IND_Animation_WPC_Priority_Flow_Graph' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_c36_Jdg_DualSyncOrder = 0U;
        App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_Off;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_DW.Input_INT_WPCIndSyncVal_start = WPCIndSyncVal__Default;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S410>/IND_Animation_Priority_Flow_Graph1' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_active_c33_Jdg_DualSyncOrder = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__Off;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S409>/DWPC1_Amber_Sync_Chart' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_SyncTrigger_f0k2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c6_Jdg_DualSyncOrder_ = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        rtb_b_CmdLEDSync_go1s = Off;
        App_Model_DW.Output_INT_WPCIndCmdState__lcxt = WPCIndCmdState__Default;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S409>/DWPC1_LED_Sync_Indy' */
        App_M_DWPC1_LED_Sync_Indy_Reset(&rtb_b_SyncLED_ipyt, &App_Model_DW.sf_DWPC1_LED_Sync_Indy);

        /* SystemReset for Chart: '<S409>/DWPC2_Amber_Sync_Chart' incorporates:
         *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_SyncTrigger_c1fa = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c11_Jdg_DualSyncOrder = 0U;

        /* SystemReset for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
        rtb_b_CmdLEDSync = Off;
        App_Model_DW.Output_INT_WPC2IndCmdState_star = WPC2IndCmdState__Default;

        /* End of SystemReset for SubSystem: '<S22>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S16>/DWPC1_TE_sys' */

        /* SystemReset for Chart: '<S409>/DWPC2_LED_Sync_Indy' */
        App_M_DWPC1_LED_Sync_Indy_Reset(&rtb_b_SyncLED, &App_Model_DW.sf_DWPC2_LED_Sync_Indy);

        /* SystemReset for Chart: '<S438>/WPC_Mode_LPConditionJdg' */
        A_WPC_Mode_LPConditionJdg_Reset(&rtb_WPCMode_LPConditionFla_e5bi, &App_Model_DW.sf_WPC_Mode_LPConditionJdg);

        /* SystemReset for Chart: '<S438>/NFC_Mode_LPConditionJdg' */
        A_NFC_Mode_LPConditionJdg_Reset(&rtb_NFCMode_LPConditionFla_i45m, &App_Model_DW.sf_NFC_Mode_LPConditionJdg);

        /* SystemReset for Chart: '<S438>/MainControl_LPConditionJdg' */
        MainControl_LPConditionJd_Reset(&rtb_WPCMain_LPConditionFla_g2vh, &App_Model_DW.sf_MainControl_LPConditionJdg);

        /* SystemReset for Chart: '<S438>/SMKLF_LPConditionJdg' */
        App__SMKLF_LPConditionJdg_Reset(&rtb_SMKLF_LPConditionFlag__edfo, &App_Model_DW.sf_SMKLF_LPConditionJdg);

        /* SystemReset for Chart: '<S438>/TempSnsrErrDetect_LPConditionJdg' */
        TempSnsrErrDetect_LPCondi_Reset(&rtb_TempSnsrError_LPCondit_lcr4, &App_Model_DW.sf_TempSnsrErrDetect_LPConditio);

        /* SystemReset for Chart: '<S438>/OverTempDetect_LPConditionJdg' */
        OverTempDetect_LPConditio_Reset(&rtb_OverTempDetect_LPCondi_l4hp, &App_Model_DW.sf_OverTempDetect_LPConditionJd);

        /* SystemReset for Chart: '<S438>/OverCurrent_LPConditionJdg' */
        OverCurrent_LPConditionJd_Reset(&rtb_OverCurrent_LPConditio_ivuq, &App_Model_DW.sf_OverCurrent_LPConditionJdg);

        /* SystemReset for Chart: '<S438>/FAN_LPConditionJdg' */
        App_Mo_FAN_LPConditionJdg_Reset(&rtb_FAN_LPConditionFlag_wr_djmc, &App_Model_DW.sf_FAN_LPConditionJdg);

        /* SystemReset for Chart: '<S438>/USM_WPC_LPConditionJdg' */
        Ap_USM_WPC_LPConditionJdg_Reset(&App_Model_B.P_WPC_USM_LPConditionFlag__kp25, &App_Model_DW.sf_USM_WPC_LPConditionJdg);

        /* SystemReset for Chart: '<S439>/WPC_Mode_LPConditionJdg' */
        A_WPC_Mode_LPConditionJdg_Reset(&rtb_WPCMode_LPConditionFla_pady, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_lmx5);

        /* SystemReset for Chart: '<S439>/NFC_Mode_LPConditionJdg' */
        A_NFC_Mode_LPConditionJdg_Reset(&rtb_NFCMode_LPConditionFla_jmfo, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_gc1n);

        /* SystemReset for Chart: '<S439>/MainControl_LPConditionJdg' */
        MainControl_LPConditionJd_Reset(&rtb_WPCMain_LPConditionFla_cfn0, &App_Model_DW.sf_MainControl_LPCondition_kcum);

        /* SystemReset for Chart: '<S439>/SMKLF_LPConditionJdg' */
        App__SMKLF_LPConditionJdg_Reset(&rtb_SMKLF_LPConditionFlag__fnej, &App_Model_DW.sf_SMKLF_LPConditionJdg_esv2);

        /* SystemReset for Chart: '<S439>/TempSnsrErrDetect_LPConditionJdg' */
        TempSnsrErrDetect_LPCondi_Reset(&rtb_TempSnsrError_LPCondit_egth, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_c3yn);

        /* SystemReset for Chart: '<S439>/OverTempDetect_LPConditionJdg' */
        OverTempDetect_LPConditio_Reset(&rtb_OverTempDetect_LPCondi_bvam, &App_Model_DW.sf_OverTempDetect_LPCondit_ehj5);

        /* SystemReset for Chart: '<S439>/OverCurrent_LPConditionJdg' */
        OverCurrent_LPConditionJd_Reset(&rtb_OverCurrent_LPConditio_p4qh, &App_Model_DW.sf_OverCurrent_LPCondition_p2tn);

        /* SystemReset for Chart: '<S439>/FAN_LPConditionJdg' */
        App_Mo_FAN_LPConditionJdg_Reset(&rtb_FAN_LPConditionFlag_wr_ddyr, &App_Model_DW.sf_FAN_LPConditionJdg_gs2a);

        /* SystemReset for Chart: '<S439>/USM_WPC2_LPCondition' */
        App_Model_DW.is_active_LPConditionChk_C_kxfd = 0U;
        App_Model_DW.is_LPConditionChk_Chart_oepo = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_LPConditionHold_bwlz = 0U;
        App_Model_DW.is_LPConditionHold_gkga = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c11_LPConditionJdg_li = 0U;
        App_Model_DW.ECUResetEnable_pyqo = 0U;
        App_Model_DW.Timer_LPConditionHold_n0a4 = 0U;
        App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
        App_Model_DW.m_ProfileGuestWPC2USM_App_start = WPC_On;
        App_Model_DW.m_ProfileOneWPC2USM_App_start = WPC_On;
        App_Model_DW.m_ProfileTwoWPC2USM_App_start = WPC_On;
        App_Model_DW.m_ProfileThreeWPC2USM_App_start = WPC_On;
        App_Model_DW.DualWPC_MODE = true;
      }

      /* DataTypeConversion: '<S433>/Data Type Conversion45' */
      rtb_NvM_INDContType_mlsp = (INDContType)rtb_TmpSignalConversionAtR_NvM_.INDContType;

      /* DataTypeConversion: '<S433>/Data Type Conversion52' */
      rtb_NvM_RheostatOption_k44v = (RheostatOption)rtb_TmpSignalConversionAtR_NvM_.RheostatOption;

      /* DataTypeConversion: '<S433>/Data Type Conversion40' */
      App_Model_B.NvM_IndUSMOption_kile = (Bool)rtb_TmpSignalConversionAtR_NvM_.IndUSMOption;

      /* DataTypeConversion: '<S433>/Data Type Conversion2' */
      rtb_NvM_EVOpt_cmz4 = (Bool)rtb_TmpSignalConversionAtR_NvM_.EVOption;

      /* DataTypeConversion: '<S426>/Data Type Conversion' */
      App_Model_B.ADC_IGN1_IN_njed = (Bool)rtb_TmpSignalConversionAtR_ADC_.IGN1_IN;

      /* DataTypeConversion: '<S426>/Data Type Conversion8' */
      rtb_ADC_BatSysStateFault_ibda = (Bool)rtb_TmpSignalConversionAtR_ADC_.BatSysStateFault;

      /* DataTypeConversion: '<S435>/Data Type Conversion32' */
      rtb_Uds_m_NFCOption_l1mx = (Bool)rtb_TmpSignalConversionAtR_Uds_.m_NFCOption;

      /* DataTypeConversion: '<S427>/Data Type Conversion1' */
      App_Model_B.BCAN_RX_C_LFAnt_SrchSta_enma = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_LFAnt_SrchSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion16' */
      App_Model_B.BCAN_RX_RheoStatLevel_p5hv = (C_RheoStatLevel)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RheoStatLevel;

      /* DataTypeConversion: '<S427>/Data Type Conversion17' */
      rtb_BCAN_RX_C_CLU_DtntOutS_gff4 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DtntOutSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion18' */
      App_Model_B.BCAN_RX_C_WPCOnOffNvalueSe_ehax = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCOnOffNvalueSet;

      /* DataTypeConversion: '<S427>/Data Type Conversion43' */
      App_Model_B.BCAN_RX_C_CF_Gway_WPCAnima_litl = (WPCAnimationNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_Gway_WPCAnimationNvalueSet;

      /* DataTypeConversion: '<S427>/Data Type Conversion19' */
      App_Model_B.BCAN_RX_C_USMReset_n3bg = (C_USMReset)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USMReset;

      /* DataTypeConversion: '<S427>/Data Type Conversion20' */
      App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p = (C_ProfileIDRValue)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_IAU_ProfileIDRVal;

      /* DataTypeConversion: '<S427>/Data Type Conversion21' */
      App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko = (C_ProfileIDRValue)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_AVN_ProfileIDRValue;

      /* DataTypeConversion: '<S427>/Data Type Conversion50' */
      rtb_BCAN_RX_C_Lamp_IntTail_i0kk = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Lamp_IntTailLmpOnReq;

      /* DataTypeConversion: '<S427>/Data Type Conversion39' */
      App_Model_B.BCAN_RX_C_AutoBrightLevel_m1oc = (C_AutoBrightLevel)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_AutoBrightLevel;

      /* DataTypeConversion: '<S427>/Data Type Conversion10' */
      App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_a4ib = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_BCM_SmkOptTyp;

      /* DataTypeConversion: '<S427>/Data Type Conversion51' */
      rtb_BCAN_Latch_TypeOption__ngmo = (LatchTypeOption)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Latch_TypeOption_DRV;

      /* DataTypeConversion: '<S427>/Data Type Conversion13' */
      rtb_BCAN_AstDrSw_f1gi = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion12' */
      rtb_BCAN_DrvDrSw_oqpb = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion14' */
      rtb_BCAN_RLDrSw_bqn3 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion15' */
      rtb_BCAN_RRDrSw_dsi0 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion35' */
      rtb_BCAN_AstDrSw_SBCM_hsy4 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta_SBCM;

      /* DataTypeConversion: '<S427>/Data Type Conversion47' */
      rtb_BCAN_DrvDrSw_SBCM_md2x = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta_SBCM;

      /* DataTypeConversion: '<S427>/Data Type Conversion48' */
      rtb_BCAN_RLDrSw_SBCM_jzjl = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta_SBCM;

      /* DataTypeConversion: '<S427>/Data Type Conversion49' */
      rtb_BCAN_RRDrSw_SBCM_dfpz = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta_SBCM;

      /* Chart: '<S427>/DoorOpenCloseStateFunctionFlowGraph' */
      DoorOpenCloseStateFunctionFlowG(rtb_BCAN_Latch_TypeOption__ngmo, rtb_BCAN_AstDrSw_f1gi, rtb_BCAN_DrvDrSw_oqpb, rtb_BCAN_RLDrSw_bqn3, rtb_BCAN_RRDrSw_dsi0, rtb_BCAN_AstDrSw_SBCM_hsy4,
        rtb_BCAN_DrvDrSw_SBCM_md2x, rtb_BCAN_RLDrSw_SBCM_jzjl, rtb_BCAN_RRDrSw_SBCM_dfpz, &App_Model_B.b_AstDrSw_c4ax, &App_Model_B.b_DrvDrSw_m4ht, &App_Model_B.b_RLDrSw_m3r3,
        &App_Model_B.b_RRDrSw_cbkj, &App_Model_DW.sf_DoorOpenCloseStateFunctionFl);

      /* DataTypeConversion: '<S427>/Data Type Conversion42' */
      App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt = (RWPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RWPC_IndSyncVal;

      /* DataTypeConversion: '<S427>/Data Type Conversion7' */
      App_Model_B.BCAN_RX_C_GearPosSta_grgw = (GearPosSta)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_VCU_GearPosSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion8' */
      App_Model_B.BCAN_RX_C_FANSpeedSet_aqsp = (FANSpeed)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USM_FANSpeedSet;

      /* DataTypeConversion: '<S427>/Data Type Conversion25' */
      App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcm_h4rr = (LC_IAUWPCNFCcmd)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC_IAUWPCNFCcmd;

      /* DataTypeConversion: '<S427>/Data Type Conversion26' */
      App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd = (LC_IAUWPCNFCcmd)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC2_IAUWPCNFCcmd;

      /* DataTypeConversion: '<S427>/Data Type Conversion37' */
      App_Model_B.LCAN_RX_LC_OwnerKey_Reg_St_mn3f = (IAU_OwnerPhnRegRVal)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerKey_Reg_Status;

      /* DataTypeConversion: '<S427>/Data Type Conversion44' */
      App_Model_B.LCAN_RX_LC_OwnerPairingAdv_i0z3 = (OwnerPairingAdvertisingReq)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerPairingAdvertisingReq;

      /* DataTypeConversion: '<S432>/Data Type Conversion34' */
      App_Model_B.NFC1_LC_WPC_NFCDetection_g5w2 = (LC_WPC_NFCDetection)rtb_TmpSignalConversionAtR_NFC_.Device[0].NFCDetection;

      /* DataTypeConversion: '<S432>/Data Type Conversion1' */
      App_Model_B.NFC1_NfcOnThePad_m2d4 = (OnThePad)rtb_TmpSignalConversionAtR_NFC_.Device[0].NfcOnThePad;

      /* DataTypeConversion: '<S432>/Data Type Conversion83' */
      rtb_NFC1_b_MultiCardDetect_daa0 = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[0].MultiCardDetectionState;

      /* DataTypeConversion: '<S434>/Data Type Conversion29' */
      App_Model_B.UART_WPC1_PhoneLeft_lmgd = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].PhoneLeft;

      /* DataTypeConversion: '<S434>/Data Type Conversion36' */
      App_Model_B.UART_WPC1_DeviceState_par2 = (DeviceState)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].DeviceState;

      /* DataTypeConversion: '<S434>/Data Type Conversion31' */
      App_Model_B.UART_WPC1_ChargingCurrent_f2uu = rtb_TmpSignalConversionAtR_UART.Device_WCT[0].ChargingCurrent;

      /* DataTypeConversion: '<S434>/Data Type Conversion5' */
      App_Model_B.UART_WPC1_CoilTempDegree_lz1a = rtb_TmpSignalConversionAtR_UART.Device_WCT[0].CoilTempDegree;

      /* DataTypeConversion: '<S434>/Data Type Conversion6' */
      App_Model_B.UART_WPC1_Temp_SnsrError_n1or = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].TempSnsrError;

      /* DataTypeConversion: '<S430>/Data Type Conversion53' incorporates:
       *  UnitDelay: '<S431>/Unit Delay'
       */
      App_Model_B.INT_WPCIndUSMState = App_Model_DW.UnitDelay_DSTATE_d0ul;

      /* DataTypeConversion: '<S430>/Data Type Conversion9' incorporates:
       *  UnitDelay: '<S431>/Unit Delay4'
       */
      App_Model_B.INT_WPCIndCmdState = App_Model_DW.UnitDelay4_DSTATE_kskc;

      /* DataTypeConversion: '<S430>/Data Type Conversion60' incorporates:
       *  UnitDelay: '<S431>/Unit Delay5'
       */
      App_Model_B.INT_WPC2IndCmdState = App_Model_DW.UnitDelay5_DSTATE;

      /* DataTypeConversion: '<S430>/Data Type Conversion64' incorporates:
       *  UnitDelay: '<S431>/Unit Delay9'
       */
      App_Model_B.INT_b_CmdLEDSync_WPC1 = App_Model_DW.UnitDelay9_DSTATE_afvw;

      /* DataTypeConversion: '<S430>/Data Type Conversion65' incorporates:
       *  UnitDelay: '<S431>/Unit Delay10'
       */
      App_Model_B.INT_b_SyncLED_WPC1 = App_Model_DW.UnitDelay10_DSTATE_ijjh;

      /* DataTypeConversion: '<S430>/Data Type Conversion70' incorporates:
       *  UnitDelay: '<S431>/Unit Delay15'
       */
      App_Model_B.INT_WPCWarning = App_Model_DW.UnitDelay15_DSTATE_kgaf;

      /* DataTypeConversion: '<S430>/Data Type Conversion72' incorporates:
       *  UnitDelay: '<S431>/Unit Delay7'
       */
      App_Model_B.INT_WPC2Status = App_Model_DW.UnitDelay7_DSTATE_m4bk;

      /* DataTypeConversion: '<S430>/Data Type Conversion73' incorporates:
       *  UnitDelay: '<S431>/Unit Delay8'
       */
      App_Model_B.INT_Jgd_NFCDetectOrder = App_Model_DW.UnitDelay8_DSTATE;

      /* DataTypeConversion: '<S430>/Data Type Conversion74' incorporates:
       *  UnitDelay: '<S431>/Unit Delay17'
       */
      App_Model_B.INT_Jgd_LPCDWakeUpOrder = App_Model_DW.UnitDelay17_DSTATE;

      /* DataTypeConversion: '<S430>/Data Type Conversion78' incorporates:
       *  UnitDelay: '<S431>/Unit Delay18'
       */
      App_Model_B.INT_WPC1_b_PhnLeftChk_Enable = App_Model_DW.UnitDelay18_DSTATE_ghv5;

      /* DataTypeConversion: '<S430>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S431>/Unit Delay20'
       */
      App_Model_B.INT_Jdg_NfcOnthepad = App_Model_DW.UnitDelay20_DSTATE;

      /* DataTypeConversion: '<S430>/Data Type Conversion2' incorporates:
       *  UnitDelay: '<S431>/Unit Delay21'
       */
      App_Model_B.INT_Jdg_ChargingOnthepad = App_Model_DW.UnitDelay21_DSTATE;

      /* DataTypeConversion: '<S430>/Data Type Conversion3' incorporates:
       *  UnitDelay: '<S431>/Unit Delay6'
       */
      App_Model_B.INT_Jdg_ObjectOnthepad = App_Model_DW.UnitDelay6_DSTATE;

      /* Outputs for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
      /* Outputs for Atomic SubSystem: '<S19>/USMSettingControl_Function' */
      App__USMSettingControl_Function(rtb_Uds_m_NFCOption_l1mx, App_Model_B.BCAN_RX_C_WPCOnOffNvalueSe_ehax, App_Model_B.BCAN_RX_C_USMReset_n3bg, App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko,
        App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p, &App_Model_B.WPCRValue, &App_Model_B.WPCSWOption_oxhs);

      /* End of Outputs for SubSystem: '<S19>/USMSettingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S23>/NFC_WPC_Mode_Control_Function' */
      A_NFC_WPC_Mode_Control_Function(rtb_Uds_m_NFCOption_l1mx, App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcm_h4rr, App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd, App_Model_B.ADC_IGN1_IN_njed,
        App_Model_B.LCAN_RX_LC_OwnerKey_Reg_St_mn3f, App_Model_B.LCAN_RX_LC_OwnerPairingAdv_i0z3, App_Model_B.WPCSWOption_oxhs, App_Model_B.NFC1_NfcOnThePad_m2d4,
        App_Model_B.NFC1_LC_WPC_NFCDetection_g5w2, App_Model_B.INT_Jdg_NfcOnthepad, App_Model_B.INT_Jdg_ChargingOnthepad, App_Model_B.INT_WPC2Status, App_Model_B.INT_Jgd_LPCDWakeUpOrder,
        App_Model_B.INT_Jgd_NFCDetectOrder, App_Model_B.b_DrvDrSw_m4ht, App_Model_B.INT_WPCWarning, App_Model_B.INT_WPC1_b_PhnLeftChk_Enable, App_Model_B.INT_Jdg_ObjectOnthepad,
        App_Model_B.b_AstDrSw_c4ax, rtb_ADC_BatSysStateFault_ibda, &App_Model_B.WPCStatus_hv2c);

      /* End of Outputs for SubSystem: '<S23>/NFC_WPC_Mode_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S23>/TemperatureSensorErrorDetect_Function' */
      TemperatureSensorErrorDetect_Fu(App_Model_B.WPCStatus_hv2c, App_Model_B.UART_WPC1_Temp_SnsrError_n1or, App_Model_ConstB.Dum_WPC_Temp_SnsrError_ebfx, App_Model_ConstB.Dum_R_DIA_gb_DTCClearF_kqqc,
        &App_Model_B.b_TempSensorFault_ahdl, &App_Model_B.b_Timer_TempSensor_Check_dej2);

      /* End of Outputs for SubSystem: '<S23>/TemperatureSensorErrorDetect_Function' */

      /* Outputs for Atomic SubSystem: '<S23>/PreventionSMK_LF_Interference_Function' */
      PreventionSMK_LF_Interference_F(App_Model_B.WPCStatus_hv2c, App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_a4ib, App_Model_B.BCAN_RX_C_LFAnt_SrchSta_enma, App_Model_B.b_AstDrSw_c4ax,
        App_Model_B.b_DrvDrSw_m4ht, App_Model_B.b_RLDrSw_m3r3, App_Model_B.b_RRDrSw_cbkj, App_Model_ConstB.Dum_L_LFSearchingOn_IN_d0yb, &App_Model_B.b_LFState_fv4t);

      /* End of Outputs for SubSystem: '<S23>/PreventionSMK_LF_Interference_Function' */

      /* Outputs for Atomic SubSystem: '<S23>/OverCurrentDetecting_Function' */
      A_OverCurrentDetecting_Function(App_Model_B.WPCStatus_hv2c, App_Model_B.UART_WPC1_ChargingCurrent_f2uu, &App_Model_B.b_CurrentFault_jcbo, &App_Model_B.b_Timer_OvrCurr_dt5l,
        &App_Model_B.b_Timer_ReOvrCurr_dylv);

      /* End of Outputs for SubSystem: '<S23>/OverCurrentDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S23>/OverTemperatureDetecting_Function' */
      OverTemperatureDetecting_Functi(App_Model_B.WPCStatus_hv2c, App_Model_B.UART_WPC1_CoilTempDegree_lz1a, App_Model_ConstB.Dum_CoilTempDegree2_Co_klys, App_Model_ConstB.Dum_CoilTempDegree3_Co_e1ps,
        App_Model_B.UART_WPC1_DeviceState_par2, &App_Model_B.b_TemperatureFault_c04g, &App_Model_B.b_Timer_OverTemp_p3xh);

      /* End of Outputs for SubSystem: '<S23>/OverTemperatureDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S23>/WPC_PhoneLeftDetectingControl_Function' */
      WPC_PhoneLeftDetectingControl_F(App_Model_B.WPCStatus_hv2c, rtb_NFC1_b_MultiCardDetect_daa0, &App_Model_B.Output_PhoneLeftWarningWPC_jnov);

      /* End of Outputs for SubSystem: '<S23>/WPC_PhoneLeftDetectingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S19>/WPC_MainControl_Function' */
      App_Mo_WPC_MainControl_Function(rtb_Uds_m_NFCOption_l1mx, rtb_NvM_EVOpt_cmz4, App_Model_B.b_LFState_fv4t, App_Model_B.b_CurrentFault_jcbo, App_Model_B.b_TempSensorFault_ahdl,
        App_Model_B.WPCSWOption_oxhs, App_Model_B.b_TemperatureFault_c04g, App_Model_B.b_AstDrSw_c4ax, App_Model_B.b_DrvDrSw_m4ht, App_Model_B.UART_WPC1_PhoneLeft_lmgd,
        App_Model_B.UART_WPC1_DeviceState_par2, App_Model_B.WPCStatus_hv2c, App_Model_B.ADC_IGN1_IN_njed, App_Model_B.INT_WPCIndUSMState, App_Model_B.INT_b_CmdLEDSync_WPC1,
        App_Model_B.INT_WPCIndCmdState, App_Model_B.BCAN_RX_C_GearPosSta_grgw, App_Model_B.Output_PhoneLeftWarningWPC_jnov, &App_Model_B.C_WPCWarning_dbwe, &App_Model_B.b_FANModeCmd_jg30,
        &App_Model_B.b_GreenINDCmd_e5lz, &App_Model_B.b_AmberINDCmd_ldjg, &App_Model_B.b_BlinkState_duuz, &App_Model_B.b_Timer_PhoneReminderCheck_mh5z, &App_Model_B.b_Timer_PhoneWarningCheck_ajyk,
        &App_Model_B.b_Timer_WarningComplete_expw, &App_Model_B.b_ChargingEnable_f5ak, &App_Model_B.BlinkState_pber, &App_Model_B.b_PhnLeftChk_Enable_lemt, &App_Model_B.b_Timer_WarningTypeCheck_cenb);

      /* End of Outputs for SubSystem: '<S19>/WPC_MainControl_Function' */

      /* Outputs for Atomic SubSystem: '<S22>/FAN_Control_Function' */
      App_Model_FAN_Control_Function(App_Model_B.b_FANModeCmd_jg30, App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p, App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko, App_Model_B.BCAN_RX_C_FANSpeedSet_aqsp,
        App_Model_B.BCAN_RX_C_USMReset_n3bg, &rtb_FAN_PWM_kvyy, &App_Model_B.FANDutyRatioSta_lwkf);

      /* End of Outputs for SubSystem: '<S22>/FAN_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
      /* Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
      RWPC_IND_Command_State_Control_(App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt, &App_Model_B.Var_RWPCIndCmdState_mh2c, &App_Model_DW.sf_RWPC_IND_Command_State_Contr);

      /* Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
       *  DataTypeConversion: '<S427>/Data Type Conversion42'
       *  DataTypeConversion: '<S430>/Data Type Conversion11'
       *  DataTypeConversion: '<S430>/Data Type Conversion53'
       *  DataTypeConversion: '<S430>/Data Type Conversion60'
       *  DataTypeConversion: '<S430>/Data Type Conversion65'
       *  DataTypeConversion: '<S430>/Data Type Conversion68'
       *  UnitDelay: '<S431>/Unit Delay13'
       *  UnitDelay: '<S431>/Unit Delay14'
       *  UnitDelay: '<S431>/Unit Delay2'
       */
      App_Model_DW.sfEvent_oqhy = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Var_PreSyncAct_prev_nho5 = App_Model_DW.Var_PreSyncAct_start_b2ke;
      App_Model_DW.Var_PreSyncAct_start_b2ke = App_Model_DW.UnitDelay13_DSTATE;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_p_pwgh = App_Model_DW.Input_CAN_RWPCIndSyncVal_s_nnsr;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_s_nnsr = App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt;
      App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg = App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc;
      App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc = App_Model_B.Var_RWPCIndCmdState_mh2c;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_p_c3v4 = App_Model_DW.Input_CAN_WPC2IndSyncVal_s_pfdf;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_s_pfdf = App_Model_DW.UnitDelay2_DSTATE;
      App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 = App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz;
      App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz = App_Model_B.INT_WPC2IndCmdState;
      App_Model_DW.WPCIndUSMState_prev_mwgm = App_Model_DW.WPCIndUSMState_start_cume;
      App_Model_DW.WPCIndUSMState_start_cume = App_Model_B.INT_WPCIndUSMState;
      App_Model_DW.b_SyncAmber_prev_h2yl = App_Model_DW.b_SyncAmber_start_hpuj;
      App_Model_DW.b_SyncAmber_start_hpuj = App_Model_B.INT_b_SyncLED_WPC1;
      if ((uint32)App_Model_DW.is_active_c197_WPC_IND_Animatio == 0U) {
        App_Model_DW.Var_PreSyncAct_prev_nho5 = App_Model_DW.UnitDelay13_DSTATE;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_p_pwgh = App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt;
        App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg = App_Model_B.Var_RWPCIndCmdState_mh2c;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_p_c3v4 = App_Model_DW.UnitDelay2_DSTATE;
        App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 = App_Model_B.INT_WPC2IndCmdState;
        App_Model_DW.WPCIndUSMState_prev_mwgm = App_Model_B.INT_WPCIndUSMState;
        App_Model_DW.b_SyncAmber_prev_h2yl = App_Model_B.INT_b_SyncLED_WPC1;
        App_Model_DW.is_active_c197_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDLight_j5kt = 1U;
        App_Model_DW.is_INDLight_ajwi = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight_jkqo = 0U;
        App_Model_DW.is_active_IND_Animation_Sy_bgeh = 1U;

        /* Default */
        App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mod_IN_WPCINDAnimation_Init;
        App_Model_DW.sfEvent_oqhy = (sint32)App__event_CancelTimer_INDLight;
        App_Model_INDLight();
        App_Model_DW.sfEvent_oqhy = -1;
        App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
        App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
        App_Model_DW.is_active_INDFadeIn_oxbo = 1U;
        App_Model_DW.is_INDFadeIn_jkbd = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_bp2v = 0U;
        App_Model_DW.is_active_INDFadeOut_khxa = 1U;
        App_Model_DW.is_INDFadeOut_crlr = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_bvej = 0U;
      } else {
        if ((uint32)App_Model_DW.is_active_INDLight_j5kt != 0U) {
          App_Model_INDLight();
        }

        if ((uint32)App_Model_DW.is_active_IND_Animation_Sy_bgeh != 0U) {
          IND_Animation_Sync_Control_Func(&App_Model_DW.UnitDelay2_DSTATE, &App_Model_DW.UnitDelay13_DSTATE);
        }

        if ((uint32)App_Model_DW.is_active_INDFadeIn_oxbo != 0U) {
          App_Model_INDFadeIn();
        }

        if ((uint32)App_Model_DW.is_active_INDFadeOut_khxa != 0U) {
          App_Model_INDFadeOut();
        }
      }

      /* End of Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */

      /* Chart: '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
      IND_Animation_Profile_Decision_(App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p, App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko, &App_Model_B.CurProfile_md3a,
        &App_Model_DW.sf_IND_Animation_Profile_Decisi);

      /* Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
      IND_Animation_USM_Setting_Contr(App_Model_B.NvM_IndUSMOption_kile, App_Model_B.BCAN_RX_C_CF_Gway_WPCAnima_litl, App_Model_B.BCAN_RX_C_USMReset_n3bg, App_Model_B.CurProfile_md3a,
        &App_Model_B.Output_CAN_WPCIndUSMState_kprv, &App_Model_B.Output_INT_WPCIndUSMState_bcrl, &App_Model_DW.sf_IND_Animation_USM_Setting_Co);

      /* End of Outputs for SubSystem: '<S22>/IND_Animation_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S22>/IndyOutputControl_Function' */
      App__IndyOutputControl_Function(rtb_NvM_INDContType_mlsp, App_Model_B.INT_WPCIndUSMState, rtb_NvM_RheostatOption_k44v, rtb_BCAN_RX_C_Lamp_IntTail_i0kk, rtb_BCAN_RX_C_CLU_DtntOutS_gff4,
        App_Model_B.BCAN_RX_RheoStatLevel_p5hv, App_Model_B.b_GreenINDCmd_e5lz, App_Model_B.b_AmberINDCmd_ldjg, App_Model_B.INT_WPCIndCmdState, App_Model_B.INT_b_SyncLED_WPC1,
        App_Model_B.BCAN_RX_C_AutoBrightLevel_m1oc, &App_Model_B.P_GreenIND_OUT_c12b, &App_Model_B.P_GreenIND2_OUT_dniy, &App_Model_B.P_GreenIND3_OUT_oayi, &App_Model_B.P_AmberIND_OUT_j3u5);

      /* End of Outputs for SubSystem: '<S22>/IndyOutputControl_Function' */
      /* End of Outputs for SubSystem: '<S16>/DWPC1_TE_sys' */

      /* DataTypeConversion: '<S427>/Data Type Conversion4' */
      App_Model_B.BCAN_RX_C_WPC2OnOffNvalueSet = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2OnOffNvalueSet;

      /* DataTypeConversion: '<S432>/Data Type Conversion75' */
      App_Model_B.NFC2_LC_WPC_NFCDetection = (LC_WPC_NFCDetection)rtb_TmpSignalConversionAtR_NFC_.Device[1].NFCDetection;

      /* DataTypeConversion: '<S432>/Data Type Conversion2' */
      App_Model_B.NFC2_NfcOnThePad = (OnThePad)rtb_TmpSignalConversionAtR_NFC_.Device[1].NfcOnThePad;

      /* DataTypeConversion: '<S432>/Data Type Conversion82' */
      rtb_NFC2_b_MultiCardDetect_n4aq = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[1].MultiCardDetectionState;

      /* DataTypeConversion: '<S434>/Data Type Conversion47' */
      App_Model_B.UART_WPC2_PhoneLeft = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].PhoneLeft;

      /* DataTypeConversion: '<S434>/Data Type Conversion49' */
      App_Model_B.UART_WPC2_DeviceState = (DeviceState)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].DeviceState;

      /* DataTypeConversion: '<S434>/Data Type Conversion48' */
      App_Model_B.UART_WPC2_ChargingCurrent = rtb_TmpSignalConversionAtR_UART.Device_WCT[1].ChargingCurrent;

      /* DataTypeConversion: '<S434>/Data Type Conversion51' */
      App_Model_B.UART_WPC2_CoilTempDegree = rtb_TmpSignalConversionAtR_UART.Device_WCT[1].CoilTempDegree;

      /* DataTypeConversion: '<S434>/Data Type Conversion55' */
      App_Model_B.UART_WPC2_Temp_SnsrError = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].TempSnsrError;

      /* DataTypeConversion: '<S430>/Data Type Conversion66' incorporates:
       *  UnitDelay: '<S431>/Unit Delay11'
       */
      App_Model_B.INT_b_CmdLEDSync_WPC2 = App_Model_DW.UnitDelay11_DSTATE_ibvb;

      /* DataTypeConversion: '<S430>/Data Type Conversion67' incorporates:
       *  UnitDelay: '<S431>/Unit Delay12'
       */
      App_Model_B.INT_b_SyncLED_WPC2 = App_Model_DW.UnitDelay12_DSTATE_kt23;

      /* UnitDelay: '<S431>/Unit Delay14' incorporates:
       *  UnitDelay: '<S431>/Unit Delay13'
       */
      App_Model_DW.UnitDelay13_DSTATE = App_Model_DW.UnitDelay14_DSTATE;

      /* DataTypeConversion: '<S430>/Data Type Conversion71' incorporates:
       *  UnitDelay: '<S431>/Unit Delay16'
       */
      App_Model_B.INT_WPC2Warning = App_Model_DW.UnitDelay16_DSTATE_fcip;

      /* DataTypeConversion: '<S430>/Data Type Conversion63' incorporates:
       *  UnitDelay: '<S431>/Unit Delay3'
       */
      App_Model_B.INT_WPCStatus = App_Model_DW.UnitDelay3_DSTATE_lcrf;

      /* DataTypeConversion: '<S430>/Data Type Conversion79' incorporates:
       *  UnitDelay: '<S431>/Unit Delay19'
       */
      App_Model_B.INT_WPC2_b_PhnLeftChk_Enable = App_Model_DW.UnitDelay19_DSTATE_oefu;

      /* Outputs for Atomic SubSystem: '<S16>/DWPC2_TE_sys' */
      /* Outputs for Atomic SubSystem: '<S20>/USMSettingControl_Function' */
      USMSettingControl_Function_hux4(rtb_Uds_m_NFCOption_l1mx, App_Model_B.BCAN_RX_C_WPC2OnOffNvalueSet, App_Model_B.BCAN_RX_C_USMReset_n3bg, App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko,
        App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p, &App_Model_B.WPC2RValue, &App_Model_B.WPC2SWOption);

      /* End of Outputs for SubSystem: '<S20>/USMSettingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S218>/NFC_WPC_Mode_Control_Function' */
      NFC_WPC_Mode_Control_Funct_mock(rtb_Uds_m_NFCOption_l1mx, App_Model_B.ADC_IGN1_IN_njed, App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd, App_Model_B.WPC2SWOption,
        App_Model_B.LCAN_RX_LC_OwnerKey_Reg_St_mn3f, App_Model_B.LCAN_RX_LC_OwnerPairingAdv_i0z3, App_Model_B.NFC2_NfcOnThePad, App_Model_B.NFC2_LC_WPC_NFCDetection, App_Model_B.INT_Jdg_NfcOnthepad,
        App_Model_B.INT_Jdg_ChargingOnthepad, App_Model_B.INT_WPCStatus, App_Model_B.INT_Jgd_LPCDWakeUpOrder, App_Model_B.INT_Jgd_NFCDetectOrder, App_Model_B.b_DrvDrSw_m4ht,
        App_Model_B.INT_WPC2Warning, App_Model_B.INT_WPC2_b_PhnLeftChk_Enable, App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcm_h4rr, App_Model_B.INT_Jdg_ObjectOnthepad, App_Model_B.b_AstDrSw_c4ax,
        rtb_ADC_BatSysStateFault_ibda, &App_Model_B.WPC2Status);

      /* End of Outputs for SubSystem: '<S218>/NFC_WPC_Mode_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S218>/TemperatureSensorErrorDetect_Function' */
      TemperatureSensorErrorDete_hhj5(App_Model_B.WPC2Status, App_Model_B.UART_WPC2_Temp_SnsrError, App_Model_ConstB.Dum_WPC_Temp_SnsrError_ebfx, App_Model_ConstB.Dum_R_DIA_gb_DTCClearF_kqqc,
        &App_Model_B.b_TempSensorFault_futc, &App_Model_B.b_Timer_TempSensor_Check_eer0);

      /* End of Outputs for SubSystem: '<S218>/TemperatureSensorErrorDetect_Function' */

      /* Outputs for Atomic SubSystem: '<S218>/PreventionSMK_LF_Interference_Function' */
      PreventionSMK_LF_Interfere_c5sa(App_Model_B.WPC2Status, App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_a4ib, App_Model_B.BCAN_RX_C_LFAnt_SrchSta_enma, App_Model_B.b_AstDrSw_c4ax, App_Model_B.b_DrvDrSw_m4ht,
        App_Model_B.b_RLDrSw_m3r3, App_Model_B.b_RRDrSw_cbkj, App_Model_ConstB.Dum_L_LFSearchingOn_IN_d0yb, &App_Model_B.b_LFState_kucz);

      /* End of Outputs for SubSystem: '<S218>/PreventionSMK_LF_Interference_Function' */

      /* Outputs for Atomic SubSystem: '<S218>/OverCurrentDetecting_Function' */
      OverCurrentDetecting_Funct_i2cq(App_Model_B.WPC2Status, App_Model_B.UART_WPC2_ChargingCurrent, &App_Model_B.b_CurrentFault_kptm, &App_Model_B.b_Timer_OvrCurr_bvyp,
        &App_Model_B.b_Timer_ReOvrCurr_gm1e);

      /* End of Outputs for SubSystem: '<S218>/OverCurrentDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S218>/OverTemperatureDetecting_Function' */
      OverTemperatureDetecting_F_aewx(App_Model_B.WPC2Status, App_Model_B.UART_WPC2_CoilTempDegree, App_Model_ConstB.Dum_CoilTempDegree2_Co_klys, App_Model_ConstB.Dum_CoilTempDegree3_Co_e1ps,
        App_Model_B.UART_WPC2_DeviceState, &App_Model_B.b_TemperatureFault_fxyc, &App_Model_B.b_Timer_OverTemp_ce1w);

      /* End of Outputs for SubSystem: '<S218>/OverTemperatureDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S218>/WPC_PhoneLeftDetectingControl_Function' */
      WPC_PhoneLeftDetectingCont_k5ur(App_Model_B.WPC2Status, rtb_NFC2_b_MultiCardDetect_n4aq, &App_Model_B.Output_PhoneLeftWarningWPC_i4ao);

      /* End of Outputs for SubSystem: '<S218>/WPC_PhoneLeftDetectingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S20>/WPC_MainControl_Function' */
      A_WPC_MainControl_Function_e3ud(App_Model_B.b_LFState_kucz, App_Model_B.b_CurrentFault_kptm, App_Model_B.b_TempSensorFault_futc, App_Model_B.WPC2SWOption, App_Model_B.b_TemperatureFault_fxyc,
        App_Model_B.b_AstDrSw_c4ax, App_Model_B.b_DrvDrSw_m4ht, App_Model_B.UART_WPC2_PhoneLeft, App_Model_B.UART_WPC2_DeviceState, App_Model_B.WPC2Status, App_Model_B.ADC_IGN1_IN_njed,
        App_Model_B.INT_WPCIndUSMState, App_Model_B.INT_b_CmdLEDSync_WPC2, App_Model_B.INT_WPC2IndCmdState, App_Model_B.BCAN_RX_C_GearPosSta_grgw, App_Model_B.Output_PhoneLeftWarningWPC_i4ao,
        rtb_Uds_m_NFCOption_l1mx, rtb_NvM_EVOpt_cmz4, &App_Model_B.C_WPC2Warning, &App_Model_B.b_FANModeCmd_e52k, &App_Model_B.b_GreenINDCmd_pkht, &App_Model_B.b_AmberINDCmd_lyff,
        &App_Model_B.b_BlinkState_ly2p, &App_Model_B.b_Timer_PhoneReminderCheck_mflq, &App_Model_B.b_Timer_PhoneWarningCheck_o0i3, &App_Model_B.b_Timer_WarningComplete_ghdo,
        &App_Model_B.b_ChargingEnable_lkuy, &App_Model_B.BlinkState_nwlq, &App_Model_B.b_PhnLeftChk_Enable_m2kv, &App_Model_B.b_Timer_WarningTypeCheck_i40f);

      /* End of Outputs for SubSystem: '<S20>/WPC_MainControl_Function' */

      /* Outputs for Atomic SubSystem: '<S217>/FAN_Control_Function' */
      App_M_FAN_Control_Function_kz0x(App_Model_B.b_FANModeCmd_e52k, App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p, App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko, App_Model_B.BCAN_RX_C_FANSpeedSet_aqsp,
        App_Model_B.BCAN_RX_C_USMReset_n3bg, &rtb_FAN_PWM_luhf, &App_Model_B.FANDutyRatioSta_acxf);

      /* End of Outputs for SubSystem: '<S217>/FAN_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S217>/IND_Animation_Control_Function' */
      /* Chart: '<S229>/RWPC_IND_Command_State_Control_Function_State_Chart' */
      RWPC_IND_Command_State_Control_(App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt, &App_Model_B.Var_RWPCIndCmdState, &App_Model_DW.sf_RWPC_IND_Command_State__b4zd);

      /* Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
       *  DataTypeConversion: '<S427>/Data Type Conversion42'
       *  DataTypeConversion: '<S430>/Data Type Conversion41'
       *  DataTypeConversion: '<S430>/Data Type Conversion53'
       *  DataTypeConversion: '<S430>/Data Type Conversion67'
       *  DataTypeConversion: '<S430>/Data Type Conversion69'
       *  DataTypeConversion: '<S430>/Data Type Conversion9'
       *  UnitDelay: '<S431>/Unit Delay1'
       *  UnitDelay: '<S431>/Unit Delay13'
       *  UnitDelay: '<S431>/Unit Delay14'
       */
      App_Model_DW.sfEvent_j1hu = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Var_PreSyncAct_prev_gyza = App_Model_DW.Var_PreSyncAct_start_avlx;
      App_Model_DW.Var_PreSyncAct_start_avlx = App_Model_DW.UnitDelay13_DSTATE;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_p_dro5 = App_Model_DW.Input_CAN_RWPCIndSyncVal_s_gr5w;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_s_gr5w = App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt;
      App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk = App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh;
      App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh = App_Model_B.Var_RWPCIndCmdState;
      App_Model_DW.Input_CAN_WPCIndSyncVal_pr_mlsp = App_Model_DW.Input_CAN_WPCIndSyncVal_st_kruf;
      App_Model_DW.Input_CAN_WPCIndSyncVal_st_kruf = App_Model_DW.UnitDelay1_DSTATE;
      App_Model_DW.Var_INT_WPCIndCmdState_prev = App_Model_DW.Var_INT_WPCIndCmdState_start;
      App_Model_DW.Var_INT_WPCIndCmdState_start = App_Model_B.INT_WPCIndCmdState;
      App_Model_DW.WPCIndUSMState_prev_grnb = App_Model_DW.WPCIndUSMState_start_gcuc;
      App_Model_DW.WPCIndUSMState_start_gcuc = App_Model_B.INT_WPCIndUSMState;
      App_Model_DW.b_SyncAmber_prev_lnzu = App_Model_DW.b_SyncAmber_start_bf1w;
      App_Model_DW.b_SyncAmber_start_bf1w = App_Model_B.INT_b_SyncLED_WPC2;
      if ((uint32)App_Model_DW.is_active_c200_WPC_IND_Animatio == 0U) {
        App_Model_DW.Var_PreSyncAct_prev_gyza = App_Model_DW.UnitDelay13_DSTATE;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_p_dro5 = App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt;
        App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk = App_Model_B.Var_RWPCIndCmdState;
        App_Model_DW.Input_CAN_WPCIndSyncVal_pr_mlsp = App_Model_DW.UnitDelay1_DSTATE;
        App_Model_DW.Var_INT_WPCIndCmdState_prev = App_Model_B.INT_WPCIndCmdState;
        App_Model_DW.WPCIndUSMState_prev_grnb = App_Model_B.INT_WPCIndUSMState;
        App_Model_DW.b_SyncAmber_prev_lnzu = App_Model_B.INT_b_SyncLED_WPC2;
        App_Model_DW.is_active_c200_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDLight_jxx1 = 1U;
        App_Model_DW.is_INDLight_jzsv = App_Model_IN_INDLight2_Off;
        App_Model_DW.Timer_INDLight_pm1y = 0U;
        App_Model_DW.is_active_IND_Animation_Sy_mfd1 = 1U;

        /* Default */
        App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_Mo_IN_WPC2INDAnimation_Init;
        App_Model_DW.sfEvent_j1hu = (sint32)App__event_CancelTimer_INDLight;
        App_Model_INDLight_idce();
        App_Model_DW.sfEvent_j1hu = -1;
        App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
        App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
        App_Model_DW.is_active_INDFadeIn_iojc = 1U;
        App_Model_DW.is_INDFadeIn_gyzm = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_kzsy = 0U;
        App_Model_DW.is_active_INDFadeOut_jiqg = 1U;
        App_Model_DW.is_INDFadeOut_pilc = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_cnjl = 0U;
      } else {
        if ((uint32)App_Model_DW.is_active_INDLight_jxx1 != 0U) {
          App_Model_INDLight_idce();
        }

        if ((uint32)App_Model_DW.is_active_IND_Animation_Sy_mfd1 != 0U) {
          IND_Animation_Sync_Control_d4de(&App_Model_DW.UnitDelay1_DSTATE, &App_Model_DW.UnitDelay13_DSTATE);
        }

        if ((uint32)App_Model_DW.is_active_INDFadeIn_iojc != 0U) {
          App_Model_INDFadeIn_dns5();
        }

        if ((uint32)App_Model_DW.is_active_INDFadeOut_jiqg != 0U) {
          App_Model_INDFadeOut_gkqv();
        }
      }

      /* End of Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
      /* End of Outputs for SubSystem: '<S217>/IND_Animation_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S217>/IndyOutputControl_Function' */
      IndyOutputControl_Function_nrso(rtb_NvM_INDContType_mlsp, App_Model_B.INT_WPC2IndCmdState, App_Model_B.INT_WPCIndUSMState, App_Model_B.b_AmberINDCmd_lyff, App_Model_B.INT_b_SyncLED_WPC2,
        rtb_BCAN_RX_C_CLU_DtntOutS_gff4, rtb_NvM_RheostatOption_k44v, rtb_BCAN_RX_C_Lamp_IntTail_i0kk, App_Model_B.b_GreenINDCmd_pkht, App_Model_B.BCAN_RX_RheoStatLevel_p5hv,
        App_Model_B.BCAN_RX_C_AutoBrightLevel_m1oc, &App_Model_B.P_GreenIND_OUT_jrko, &App_Model_B.P_GreenIND2_OUT_kfol, &App_Model_B.P_GreenIND3_OUT_olhg, &App_Model_B.P_AmberIND_OUT_hhha);

      /* End of Outputs for SubSystem: '<S217>/IndyOutputControl_Function' */
      /* End of Outputs for SubSystem: '<S16>/DWPC2_TE_sys' */

      /* Chart: '<S408>/Change_INT_NfcOnThePad' incorporates:
       *  DataTypeConversion: '<S432>/Data Type Conversion1'
       *  DataTypeConversion: '<S432>/Data Type Conversion2'
       *  Merge: '<S189>/Merge'
       *  Merge: '<S379>/Merge'
       */
      App_Model_DW.NfcOnThePad_1_prev = App_Model_DW.NfcOnThePad_1_start;
      App_Model_DW.NfcOnThePad_1_start = App_Model_B.NFC1_NfcOnThePad_m2d4;
      App_Model_DW.NfcOnThePad_2_prev = App_Model_DW.NfcOnThePad_2_start;
      App_Model_DW.NfcOnThePad_2_start = App_Model_B.NFC2_NfcOnThePad;
      if ((uint32)App_Model_DW.is_active_c30_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.NfcOnThePad_1_prev = App_Model_B.NFC1_NfcOnThePad_m2d4;
        App_Model_DW.NfcOnThePad_2_prev = App_Model_B.NFC2_NfcOnThePad;
        App_Model_DW.is_active_c30_Jdg_DualSyncOrder = 1U;
        App_Model_B.INT_NfcOnThePad_1 = App_Model_B.NFC1_NfcOnThePad_m2d4;
        if ((uint32)App_Model_B.WPCStatus_hv2c == PICCMode) {
          rtb_WCT2_ChargingOnthePad_etx4 = App_Model_DW.NfcOnThePad_1_start;
          rtb_WCT1_ChargingOnthePad_c3xl = App_Model_DW.NfcOnThePad_1_prev;
          if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) {
            App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
          } else if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_On)) {
            App_Model_B.INT_NfcOnThePad_1 = OnThePad_On;
          } else {
            /* no actions */
          }
        }

        App_Model_B.INT_NfcOnThePad_2 = App_Model_B.NFC2_NfcOnThePad;
        if ((uint32)App_Model_B.WPC2Status == PICCMode) {
          rtb_WCT2_ChargingOnthePad_etx4 = App_Model_DW.NfcOnThePad_2_start;
          rtb_WCT1_ChargingOnthePad_c3xl = App_Model_DW.NfcOnThePad_2_prev;
          if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) {
            App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
          } else if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_On)) {
            App_Model_B.INT_NfcOnThePad_2 = OnThePad_On;
          } else {
            /* no actions */
          }
        }
      } else {
        if ((uint32)App_Model_B.WPCStatus_hv2c == PICCMode) {
          rtb_WCT2_ChargingOnthePad_etx4 = App_Model_DW.NfcOnThePad_1_start;
          rtb_WCT1_ChargingOnthePad_c3xl = App_Model_DW.NfcOnThePad_1_prev;
          if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) {
            App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
          } else if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_On)) {
            App_Model_B.INT_NfcOnThePad_1 = OnThePad_On;
          } else {
            /* no actions */
          }
        } else {
          App_Model_B.INT_NfcOnThePad_1 = App_Model_B.NFC1_NfcOnThePad_m2d4;
        }

        if ((uint32)App_Model_B.WPC2Status == PICCMode) {
          rtb_WCT2_ChargingOnthePad_etx4 = App_Model_DW.NfcOnThePad_2_start;
          rtb_WCT1_ChargingOnthePad_c3xl = App_Model_DW.NfcOnThePad_2_prev;
          if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) {
            App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
          } else if ((rtb_WCT1_ChargingOnthePad_c3xl != rtb_WCT2_ChargingOnthePad_etx4) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_On)) {
            App_Model_B.INT_NfcOnThePad_2 = OnThePad_On;
          } else {
            /* no actions */
          }
        } else {
          App_Model_B.INT_NfcOnThePad_2 = App_Model_B.NFC2_NfcOnThePad;
        }
      }

      /* End of Chart: '<S408>/Change_INT_NfcOnThePad' */

      /* DataTypeConversion: '<S436>/Data Type Conversion1' */
      rtb_WCT1_ChargingOnthePad_c3xl = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[0].ChargingOnthePad;

      /* DataTypeConversion: '<S436>/Data Type Conversion4' */
      rtb_WCT2_ChargingOnthePad_etx4 = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[1].ChargingOnthePad;

      /* DataTypeConversion: '<S436>/Data Type Conversion2' */
      rtb_WCT1_ObjectOnthePad_a1dt = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[0].ObjectOnthePad;

      /* DataTypeConversion: '<S436>/Data Type Conversion3' */
      rtb_WCT2_ObjectOnthePad_izrx = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[1].ObjectOnthePad;

      /* Chart: '<S408>/Jdg_DualWPC_Onthepad' incorporates:
       *  DataTypeConversion: '<S436>/Data Type Conversion2'
       *  DataTypeConversion: '<S436>/Data Type Conversion3'
       *  Merge: '<S189>/Merge'
       *  Merge: '<S379>/Merge'
       */
      if ((uint32)App_Model_DW.is_active_c23_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.is_active_c23_Jdg_DualSyncOrder = 1U;
        if (((uint32)App_Model_B.INT_NfcOnThePad_1 == OnThePad_Off) && ((uint32)App_Model_B.INT_NfcOnThePad_2 == OnThePad_Off)) {
          /* Update for UnitDelay: '<S431>/Unit Delay20' */
          App_Model_DW.UnitDelay20_DSTATE = On;
        } else {
          /* Update for UnitDelay: '<S431>/Unit Delay20' */
          App_Model_DW.UnitDelay20_DSTATE = Off;
        }

        /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
        tmp_2 = App_Model_B.WPCStatus_hv2c;
        tmp_3 = App_Model_B.WPC2Status;
        if ((((uint32)rtb_WCT1_ChargingOnthePad_c3xl == OnThePad_Off) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) || (((uint32)tmp_2 == ModeOff) && ((uint32)
              rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) || (((uint32)tmp_3 == ModeOff) && ((uint32)rtb_WCT1_ChargingOnthePad_c3xl == OnThePad_Off))) {
          /* Update for UnitDelay: '<S431>/Unit Delay21' */
          /* USM WPC2 OFF, WPC1 O */
          App_Model_DW.UnitDelay21_DSTATE = On;
        } else {
          /* Update for UnitDelay: '<S431>/Unit Delay21' */
          App_Model_DW.UnitDelay21_DSTATE = Off;
        }

        /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
        if ((((uint32)rtb_WCT1_ObjectOnthePad_a1dt == OnThePad_Off) && ((uint32)rtb_WCT2_ObjectOnthePad_izrx == OnThePad_Off)) || (((uint32)tmp_2 == ModeOff) && ((uint32)rtb_WCT2_ObjectOnthePad_izrx ==
              OnThePad_Off)) || (((uint32)tmp_3 == ModeOff) && ((uint32)rtb_WCT1_ObjectOnthePad_a1dt == OnThePad_Off))) {
          /* Update for UnitDelay: '<S431>/Unit Delay6' */
          /* USM WPC2 OFF, WPC1 O */
          App_Model_DW.UnitDelay6_DSTATE = On;
        } else {
          /* Update for UnitDelay: '<S431>/Unit Delay6' */
          App_Model_DW.UnitDelay6_DSTATE = Off;
        }
      } else {
        if (((uint32)App_Model_B.INT_NfcOnThePad_1 == OnThePad_Off) && ((uint32)App_Model_B.INT_NfcOnThePad_2 == OnThePad_Off)) {
          /* Update for UnitDelay: '<S431>/Unit Delay20' */
          App_Model_DW.UnitDelay20_DSTATE = On;
        } else {
          /* Update for UnitDelay: '<S431>/Unit Delay20' */
          App_Model_DW.UnitDelay20_DSTATE = Off;
        }

        /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
        tmp_2 = App_Model_B.WPCStatus_hv2c;
        tmp_3 = App_Model_B.WPC2Status;
        if ((((uint32)rtb_WCT1_ChargingOnthePad_c3xl == OnThePad_Off) && ((uint32)rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) || (((uint32)tmp_2 == ModeOff) && ((uint32)
              rtb_WCT2_ChargingOnthePad_etx4 == OnThePad_Off)) || (((uint32)tmp_3 == ModeOff) && ((uint32)rtb_WCT1_ChargingOnthePad_c3xl == OnThePad_Off))) {
          /* Update for UnitDelay: '<S431>/Unit Delay21' */
          /* USM WPC2 OFF, WPC1 O */
          App_Model_DW.UnitDelay21_DSTATE = On;
        } else {
          /* Update for UnitDelay: '<S431>/Unit Delay21' */
          App_Model_DW.UnitDelay21_DSTATE = Off;
        }

        /* USM WPC1&2 ONUSM WPC1 OFF, WPC2 ON */
        if ((((uint32)rtb_WCT1_ObjectOnthePad_a1dt == OnThePad_Off) && ((uint32)rtb_WCT2_ObjectOnthePad_izrx == OnThePad_Off)) || (((uint32)tmp_2 == ModeOff) && ((uint32)rtb_WCT2_ObjectOnthePad_izrx ==
              OnThePad_Off)) || (((uint32)tmp_3 == ModeOff) && ((uint32)rtb_WCT1_ObjectOnthePad_a1dt == OnThePad_Off))) {
          /* Update for UnitDelay: '<S431>/Unit Delay6' */
          /* USM WPC2 OFF, WPC1 O */
          App_Model_DW.UnitDelay6_DSTATE = On;
        } else {
          /* Update for UnitDelay: '<S431>/Unit Delay6' */
          App_Model_DW.UnitDelay6_DSTATE = Off;
        }
      }

      /* End of Chart: '<S408>/Jdg_DualWPC_Onthepad' */

      /* DataTypeConversion: '<S432>/Data Type Conversion38' */
      rtb_NFC1_LPCD_Wakeup_o5zt = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[0].LPCD_Wakeup;

      /* DataTypeConversion: '<S432>/Data Type Conversion76' */
      rtb_NFC2_LPCD_Wakeup_ptyj = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[1].LPCD_Wakeup;

      /* Chart: '<S408>/LPCDWakeUp_Detect_DWPC_Priority' incorporates:
       *  DataTypeConversion: '<S432>/Data Type Conversion38'
       *  DataTypeConversion: '<S432>/Data Type Conversion76'
       *  Merge: '<S189>/Merge'
       *  Merge: '<S379>/Merge'
       */
      App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s;
      App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s = rtb_NFC1_LPCD_Wakeup_o5zt;
      App_Model_DW.Var_OPT_WPCStatus_1_prev_fkrl = App_Model_DW.Var_OPT_WPCStatus_1_start_fipw;
      App_Model_DW.Var_OPT_WPCStatus_1_start_fipw = App_Model_B.WPCStatus_hv2c;
      App_Model_DW.Var_OPT_WPCStatus_2_prev_cmdz = App_Model_DW.Var_OPT_WPCStatus_2_start_aclk;
      App_Model_DW.Var_OPT_WPCStatus_2_start_aclk = App_Model_B.WPC2Status;
      App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s;
      App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s = rtb_NFC2_LPCD_Wakeup_ptyj;
      if ((uint32)App_Model_DW.is_active_c47_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p = rtb_NFC1_LPCD_Wakeup_o5zt;
        App_Model_DW.Var_OPT_WPCStatus_1_prev_fkrl = App_Model_B.WPCStatus_hv2c;
        App_Model_DW.Var_OPT_WPCStatus_2_prev_cmdz = App_Model_B.WPC2Status;
        App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p = rtb_NFC2_LPCD_Wakeup_ptyj;
        App_Model_DW.is_active_c47_Jdg_DualSyncOrder = 1U;
        App_Model_B.Var_WPC1PreAct_bgn2 = Off;

        /* 1 */
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s;
        if ((rtb_NFC1_LPCD_Wakeup_o5zt != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off) && (rtb_NFC1_LPCD_Wakeup_o5zt != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)
             App_Model_B.WPCStatus_hv2c == LPCDMode)) {
          App_Model_B.Var_WPC1PreAct_bgn2 = On;
        }

        App_Model_B.Var_WPC2PreAct_dlkp = Off;

        /* 1 */
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s;
        if ((rtb_NFC1_LPCD_Wakeup_o5zt != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off) && (rtb_NFC1_LPCD_Wakeup_o5zt != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)
             App_Model_B.WPC2Status == LPCDMode)) {
          App_Model_B.Var_WPC2PreAct_dlkp = On;
        }
      } else {
        /* 1 */
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s;
        if (((uint32)App_Model_B.Var_WPC1PreAct_bgn2 == Off) && ((rtb_NFC1_LPCD_Wakeup_o5zt != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off)) && (rtb_NFC1_LPCD_Wakeup_o5zt
             != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)tmp_2 == LPCDMode)) {
          App_Model_B.Var_WPC1PreAct_bgn2 = On;
        } else {
          tmp_3 = App_Model_DW.Var_OPT_WPCStatus_1_prev_fkrl;
          tmp_4 = App_Model_DW.Var_OPT_WPCStatus_2_start_aclk;
          tmp_5 = App_Model_DW.Var_OPT_WPCStatus_2_prev_cmdz;
          if (((tmp_3 != App_Model_DW.Var_OPT_WPCStatus_1_start_fipw) && ((uint32)tmp_3 == LPCDMode)) || ((tmp_5 != tmp_4) && ((uint32)tmp_4 == LPCDMode)) || ((tmp_5 != tmp_4) && ((uint32)tmp_5 ==
                LPCDMode) && ((uint32)tmp_2 != LPCDMode))) {
            App_Model_B.Var_WPC1PreAct_bgn2 = Off;
          }
        }

        /* 1 */
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s;
        tmp_2 = App_Model_B.WPC2Status;
        if (((uint32)App_Model_B.Var_WPC2PreAct_dlkp == Off) && ((rtb_NFC1_LPCD_Wakeup_o5zt != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off)) && (rtb_NFC1_LPCD_Wakeup_o5zt
             != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)tmp_2 == LPCDMode)) {
          App_Model_B.Var_WPC2PreAct_dlkp = On;
        } else {
          tmp_3 = App_Model_DW.Var_OPT_WPCStatus_2_prev_cmdz;
          tmp_4 = App_Model_DW.Var_OPT_WPCStatus_1_start_fipw;
          tmp_5 = App_Model_DW.Var_OPT_WPCStatus_1_prev_fkrl;
          if (((tmp_3 != App_Model_DW.Var_OPT_WPCStatus_2_start_aclk) && ((uint32)tmp_3 == LPCDMode)) || ((tmp_5 != tmp_4) && ((uint32)tmp_4 == LPCDMode)) || ((tmp_5 != tmp_4) && ((uint32)tmp_5 ==
                LPCDMode) && ((uint32)tmp_2 != LPCDMode))) {
            App_Model_B.Var_WPC2PreAct_dlkp = Off;
          }
        }
      }

      /* End of Chart: '<S408>/LPCDWakeUp_Detect_DWPC_Priority' */

      /* Chart: '<S408>/Jdg_LPCDWakeUpOrder' */
      App_Model_DW.Var_WPC2PreAct_prev_pv1v = App_Model_DW.Var_WPC2PreAct_start_j405;
      App_Model_DW.Var_WPC2PreAct_start_j405 = App_Model_B.Var_WPC2PreAct_dlkp;
      App_Model_DW.Var_WPC1PreAct_prev_asvg = App_Model_DW.Var_WPC1PreAct_start_inrz;
      App_Model_DW.Var_WPC1PreAct_start_inrz = App_Model_B.Var_WPC1PreAct_bgn2;
      if ((uint32)App_Model_DW.is_active_c24_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.Var_WPC2PreAct_prev_pv1v = App_Model_B.Var_WPC2PreAct_dlkp;
        App_Model_DW.Var_WPC1PreAct_prev_asvg = App_Model_B.Var_WPC1PreAct_bgn2;
        App_Model_DW.is_active_c24_Jdg_DualSyncOrder = 1U;
        App_Model_B.LPCDWakeUpOrder = 0U;

        /* Default */
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Var_WPC2PreAct_start_j405;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Var_WPC1PreAct_start_inrz;
        tmp_6 = App_Model_B.Var_WPC2PreAct_dlkp;
        tmp_7 = App_Model_B.Var_WPC1PreAct_bgn2;
        App_Model_DW.Var_WPC1PreAct_prev = App_Model_DW.Var_WPC1PreAct_prev_asvg;
        App_Model_DW.Var_WPC2PreAct_prev = App_Model_DW.Var_WPC2PreAct_prev_pv1v;
        if ((((uint32)tmp_7 != Off) || ((App_Model_DW.Var_WPC2PreAct_prev == rtb_NFC1_LPCD_Wakeup_o5zt) || ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt != Off))) && (((uint32)tmp_6 != Off) ||
             ((App_Model_DW.Var_WPC1PreAct_prev == rtb_NFC2_LPCD_Wakeup_ptyj) || ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj != Off))) && (((uint32)tmp_6 != Off) || ((uint32)tmp_7 != Off))) {
          if (((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((uint32)tmp_6 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev !=
                rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off) && ((uint32)tmp_7 == On)) || ((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)
                rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On)))) {
            /* SameTimePutPhones */
            App_Model_B.LPCDWakeUpOrder = 1U;

            /* WPC1_Lead */
          } else if (((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On) && ((uint32)tmp_7 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev !=
                       rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == Off) && ((uint32)tmp_6 == On))) {
            App_Model_B.LPCDWakeUpOrder = 2U;

            /* WPC2_Lead */
          } else {
            /* no actions */
          }
        } else {
          /* 240627_TaskAdj */
        }
      } else {
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Var_WPC2PreAct_start_j405;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Var_WPC1PreAct_start_inrz;
        tmp_6 = App_Model_B.Var_WPC2PreAct_dlkp;
        tmp_7 = App_Model_B.Var_WPC1PreAct_bgn2;
        App_Model_DW.Var_WPC1PreAct_prev = App_Model_DW.Var_WPC1PreAct_prev_asvg;
        App_Model_DW.Var_WPC2PreAct_prev = App_Model_DW.Var_WPC2PreAct_prev_pv1v;
        if ((((uint32)tmp_7 == Off) && ((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off))) || (((uint32)tmp_6 == Off) &&
             ((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == Off))) || (((uint32)tmp_6 == Off) && ((uint32)tmp_7 == Off))) {
          /* 240627_TaskAdj */
          App_Model_B.LPCDWakeUpOrder = 0U;
        } else if (((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((uint32)tmp_6 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev !=
                     rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off) && ((uint32)tmp_7 == On)) || ((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)
                     rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On)))) {
          /* SameTimePutPhones */
          App_Model_B.LPCDWakeUpOrder = 1U;

          /* WPC1_Lead */
        } else if (((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On) && ((uint32)tmp_7 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev !=
                     rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == Off) && ((uint32)tmp_6 == On))) {
          App_Model_B.LPCDWakeUpOrder = 2U;

          /* WPC2_Lead */
        } else {
          /* no actions */
        }
      }

      /* Chart: '<S408>/NFC_Detect_DWPC_Priority' incorporates:
       *  DataTypeConversion: '<S432>/Data Type Conversion34'
       *  DataTypeConversion: '<S432>/Data Type Conversion75'
       *  Merge: '<S189>/Merge'
       *  Merge: '<S379>/Merge'
       */
      App_Model_DW.Var_NFCDetection_WPC1_prev = App_Model_DW.Var_NFCDetection_WPC1_start;
      App_Model_DW.Var_NFCDetection_WPC1_start = App_Model_B.NFC1_LC_WPC_NFCDetection_g5w2;
      App_Model_DW.Var_OPT_WPCStatus_1_prev = App_Model_DW.Var_OPT_WPCStatus_1_start;
      App_Model_DW.Var_OPT_WPCStatus_1_start = App_Model_B.WPCStatus_hv2c;
      App_Model_DW.Var_OPT_WPCStatus_2_prev = App_Model_DW.Var_OPT_WPCStatus_2_start;
      App_Model_DW.Var_OPT_WPCStatus_2_start = App_Model_B.WPC2Status;
      App_Model_DW.Var_NFCDetection_WPC2_prev = App_Model_DW.Var_NFCDetection_WPC2_start;
      App_Model_DW.Var_NFCDetection_WPC2_start = App_Model_B.NFC2_LC_WPC_NFCDetection;
      if ((uint32)App_Model_DW.is_active_c46_Jdg_DualSyncOrder == 0U) {
        LC_WPC_NFCDetection tmp_8;
        LC_WPC_NFCDetection tmp_9;
        App_Model_DW.Var_NFCDetection_WPC1_prev = App_Model_B.NFC1_LC_WPC_NFCDetection_g5w2;
        App_Model_DW.Var_OPT_WPCStatus_1_prev = App_Model_B.WPCStatus_hv2c;
        App_Model_DW.Var_OPT_WPCStatus_2_prev = App_Model_B.WPC2Status;
        App_Model_DW.Var_NFCDetection_WPC2_prev = App_Model_B.NFC2_LC_WPC_NFCDetection;
        App_Model_DW.is_active_c46_Jdg_DualSyncOrder = 1U;
        App_Model_B.Var_WPC1PreAct = Off;

        /* 1 */
        tmp_8 = App_Model_DW.Var_NFCDetection_WPC1_prev;
        tmp_9 = App_Model_DW.Var_NFCDetection_WPC1_start;
        if ((tmp_8 != tmp_9) && ((uint32)tmp_8 == NFCDetection_Off) && (tmp_8 != tmp_9) && ((uint32)App_Model_B.WPCStatus_hv2c == NFCMode)) {
          App_Model_B.Var_WPC1PreAct = On;
        } else {
          /* %Only Jdg in NFCMode 240905 */
        }

        App_Model_B.Var_WPC2PreAct = Off;

        /* 1 */
        tmp_8 = App_Model_DW.Var_NFCDetection_WPC2_prev;
        tmp_9 = App_Model_DW.Var_NFCDetection_WPC2_start;
        if ((tmp_8 != tmp_9) && ((uint32)tmp_8 == NFCDetection_Off) && (tmp_8 != tmp_9) && ((uint32)App_Model_B.WPC2Status == NFCMode)) {
          App_Model_B.Var_WPC2PreAct = On;
        } else {
          /* %Only Jdg in NFCMode 240905 */
        }
      } else {
        LC_WPC_NFCDetection tmp_8;
        LC_WPC_NFCDetection tmp_9;

        /* 1 */
        tmp_8 = App_Model_DW.Var_NFCDetection_WPC1_prev;
        tmp_9 = App_Model_DW.Var_NFCDetection_WPC1_start;
        tmp_2 = App_Model_B.WPCStatus_hv2c;
        if (((uint32)App_Model_B.Var_WPC1PreAct == Off) && ((tmp_8 != tmp_9) && ((uint32)tmp_8 == NFCDetection_Off)) && (tmp_8 != tmp_9) && ((uint32)tmp_2 == NFCMode)) {
          App_Model_B.Var_WPC1PreAct = On;
        } else {
          /* %Only Jdg in NFCMode 240905 */
          tmp_3 = App_Model_DW.Var_OPT_WPCStatus_1_prev;
          tmp_4 = App_Model_DW.Var_OPT_WPCStatus_2_start;
          tmp_5 = App_Model_DW.Var_OPT_WPCStatus_2_prev;
          if (((tmp_3 != App_Model_DW.Var_OPT_WPCStatus_1_start) && ((uint32)tmp_3 == NFCMode)) || ((tmp_5 != tmp_4) && ((uint32)tmp_4 == NFCMode)) || ((uint32)tmp_2 != NFCMode) || ((tmp_5 != tmp_4) &&
               ((uint32)tmp_5 == NFCMode) && ((uint32)tmp_2 != NFCMode))) {
            App_Model_B.Var_WPC1PreAct = Off;
          }
        }

        /* 1 */
        tmp_8 = App_Model_DW.Var_NFCDetection_WPC2_prev;
        tmp_9 = App_Model_DW.Var_NFCDetection_WPC2_start;
        tmp_2 = App_Model_B.WPC2Status;
        if (((uint32)App_Model_B.Var_WPC2PreAct == Off) && ((tmp_8 != tmp_9) && ((uint32)tmp_8 == NFCDetection_Off)) && (tmp_8 != tmp_9) && ((uint32)tmp_2 == NFCMode)) {
          App_Model_B.Var_WPC2PreAct = On;
        } else {
          /* %Only Jdg in NFCMode 240905 */
          tmp_3 = App_Model_DW.Var_OPT_WPCStatus_2_prev;
          tmp_4 = App_Model_DW.Var_OPT_WPCStatus_1_start;
          tmp_5 = App_Model_DW.Var_OPT_WPCStatus_1_prev;
          if (((tmp_3 != App_Model_DW.Var_OPT_WPCStatus_2_start) && ((uint32)tmp_3 == NFCMode)) || ((tmp_5 != tmp_4) && ((uint32)tmp_4 == NFCMode)) || ((uint32)tmp_2 != NFCMode) || ((tmp_5 != tmp_4) &&
               ((uint32)tmp_5 == NFCMode) && ((uint32)tmp_2 != NFCMode))) {
            App_Model_B.Var_WPC2PreAct = Off;
          }
        }
      }

      /* End of Chart: '<S408>/NFC_Detect_DWPC_Priority' */

      /* Chart: '<S408>/Jdg_LPCDWakeUpOrder' incorporates:
       *  Chart: '<S408>/Jdg_NFCDetectOrder'
       */
      App_Model_DW.Var_WPC2PreAct_prev = App_Model_DW.Var_WPC2PreAct_start;

      /* Chart: '<S408>/Jdg_NFCDetectOrder' */
      App_Model_DW.Var_WPC2PreAct_start = App_Model_B.Var_WPC2PreAct;

      /* Chart: '<S408>/Jdg_LPCDWakeUpOrder' incorporates:
       *  Chart: '<S408>/Jdg_NFCDetectOrder'
       */
      App_Model_DW.Var_WPC1PreAct_prev = App_Model_DW.Var_WPC1PreAct_start;

      /* Chart: '<S408>/Jdg_NFCDetectOrder' */
      App_Model_DW.Var_WPC1PreAct_start = App_Model_B.Var_WPC1PreAct;
      if ((uint32)App_Model_DW.is_active_c25_Jdg_DualSyncOrder == 0U) {
        /* Chart: '<S408>/Jdg_LPCDWakeUpOrder' */
        App_Model_DW.Var_WPC2PreAct_prev = App_Model_B.Var_WPC2PreAct;
        App_Model_DW.Var_WPC1PreAct_prev = App_Model_B.Var_WPC1PreAct;
        App_Model_DW.is_active_c25_Jdg_DualSyncOrder = 1U;
        App_Model_B.NFCDetectOrder = 0U;

        /* Default */
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Var_WPC2PreAct_start;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Var_WPC1PreAct_start;
        tmp_6 = App_Model_B.Var_WPC1PreAct;
        tmp_7 = App_Model_B.Var_WPC2PreAct;
        if ((((uint32)tmp_6 != Off) || ((App_Model_DW.Var_WPC2PreAct_prev == rtb_NFC1_LPCD_Wakeup_o5zt) || ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt != Off))) && (((uint32)tmp_7 != Off) ||
             ((App_Model_DW.Var_WPC1PreAct_prev == rtb_NFC2_LPCD_Wakeup_ptyj) || ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj != Off))) && (((uint32)tmp_6 != Off) || ((uint32)tmp_7 != Off))) {
          if (((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((uint32)tmp_7 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev !=
                rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off) && ((uint32)tmp_6 == On)) || ((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)
                rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On)))) {
            App_Model_B.NFCDetectOrder = 1U;

            /* WPC1_Lead */
          } else if (((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On) && ((uint32)tmp_6 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev !=
                       rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == Off) && ((uint32)tmp_7 == On))) {
            App_Model_B.NFCDetectOrder = 2U;

            /* WPC2_Lead */
          } else {
            /* no actions */
          }
        }
      } else {
        rtb_NFC1_LPCD_Wakeup_o5zt = App_Model_DW.Var_WPC2PreAct_start;
        rtb_NFC2_LPCD_Wakeup_ptyj = App_Model_DW.Var_WPC1PreAct_start;
        tmp_6 = App_Model_B.Var_WPC1PreAct;
        tmp_7 = App_Model_B.Var_WPC2PreAct;
        if ((((uint32)tmp_6 == Off) && ((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off))) || (((uint32)tmp_7 == Off) &&
             ((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == Off))) || (((uint32)tmp_6 == Off) && ((uint32)tmp_7 == Off))) {
          App_Model_B.NFCDetectOrder = 0U;
        } else if (((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((uint32)tmp_7 == Off)) || ((App_Model_DW.Var_WPC2PreAct_prev !=
                     rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == Off) && ((uint32)tmp_6 == On)) || ((App_Model_DW.Var_WPC1PreAct_prev != rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)
                     rtb_NFC2_LPCD_Wakeup_ptyj == On) && ((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On)))) {
          App_Model_B.NFCDetectOrder = 1U;

          /* WPC1_Lead */
        } else if (((App_Model_DW.Var_WPC2PreAct_prev != rtb_NFC1_LPCD_Wakeup_o5zt) && ((uint32)rtb_NFC1_LPCD_Wakeup_o5zt == On) && ((uint32)tmp_6 == Off)) || ((App_Model_DW.Var_WPC1PreAct_prev !=
                     rtb_NFC2_LPCD_Wakeup_ptyj) && ((uint32)rtb_NFC2_LPCD_Wakeup_ptyj == Off) && ((uint32)tmp_7 == On))) {
          App_Model_B.NFCDetectOrder = 2U;

          /* WPC2_Lead */
        } else {
          /* no actions */
        }
      }

      /* Chart: '<S410>/IND_Animation_WPC2_Priority_Flow_Graph' */
      App_Model_DW.Input_INT_WPC2IndSyncVal_prev = App_Model_DW.Input_INT_WPC2IndSyncVal_start;
      App_Model_DW.Input_INT_WPC2IndSyncVal_start = App_Model_B.Output_CAN_WPC2IndSyncVal;
      if ((uint32)App_Model_DW.is_active_c35_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.Input_INT_WPC2IndSyncVal_prev = App_Model_B.Output_CAN_WPC2IndSyncVal;
        App_Model_DW.is_active_c35_Jdg_DualSyncOrder = 1U;
        App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_Off;

        /* 1 */
        tmp_a = App_Model_DW.Input_INT_WPC2IndSyncVal_prev;
        tmp_b = App_Model_DW.Input_INT_WPC2IndSyncVal_start;
        if (((uint32)App_Model_B.Var_WPC2PreSyncAct_fdt4 == WPC2PreSyncAct_Off) && ((tmp_a != tmp_b) && ((uint32)tmp_a == WPC2IndSyncVal__Default)) && (tmp_a != tmp_b)) {
          App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_On;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_WPC2PreSyncAct_fdt4 == WPC2PreSyncAct_On) && ((tmp_a != tmp_b) && ((uint32)tmp_b == WPC2IndSyncVal__Default)) && (tmp_a != tmp_b)) {
          App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_Off;
        } else {
          /* no actions */
        }
      } else {
        /* 1 */
        tmp_a = App_Model_DW.Input_INT_WPC2IndSyncVal_prev;
        tmp_b = App_Model_DW.Input_INT_WPC2IndSyncVal_start;
        if (((uint32)App_Model_B.Var_WPC2PreSyncAct_fdt4 == WPC2PreSyncAct_Off) && ((tmp_a != tmp_b) && ((uint32)tmp_a == WPC2IndSyncVal__Default)) && (tmp_a != tmp_b)) {
          App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_On;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_WPC2PreSyncAct_fdt4 == WPC2PreSyncAct_On) && ((tmp_a != tmp_b) && ((uint32)tmp_b == WPC2IndSyncVal__Default)) && (tmp_a != tmp_b)) {
          App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_Off;
        } else {
          /* no actions */
        }
      }

      /* End of Chart: '<S410>/IND_Animation_WPC2_Priority_Flow_Graph' */

      /* Chart: '<S410>/IND_Animation_RWPC_Priority_Flow_Graph' */
      IND_Animation_RWPC_Priority_Flo(App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt, &App_Model_B.Var_RWPCPreSyncAct_baek, &App_Model_DW.sf_IND_Animation_RWPC_Priority_);

      /* Chart: '<S410>/IND_Animation_Priority_Flow_Graph' */
      IND_Animation_Priority_Flow_Gra(App_Model_B.Var_WPC2PreSyncAct_fdt4, App_Model_B.Var_RWPCPreSyncAct_baek, &App_Model_B.Var_PreSyncAct_akzv, &App_Model_DW.sf_IND_Animation_Priority_Flow_);

      /* Chart: '<S410>/IND_Animation_WPC_Priority_Flow_Graph' */
      App_Model_DW.Input_INT_WPCIndSyncVal_prev = App_Model_DW.Input_INT_WPCIndSyncVal_start;
      App_Model_DW.Input_INT_WPCIndSyncVal_start = App_Model_B.Output_CAN_WPCIndSyncVal_i4yx;
      if ((uint32)App_Model_DW.is_active_c36_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.Input_INT_WPCIndSyncVal_prev = App_Model_B.Output_CAN_WPCIndSyncVal_i4yx;
        App_Model_DW.is_active_c36_Jdg_DualSyncOrder = 1U;
        App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_Off;

        /* 1 */
        tmp_c = App_Model_DW.Input_INT_WPCIndSyncVal_prev;
        tmp_d = App_Model_DW.Input_INT_WPCIndSyncVal_start;
        if ((tmp_c != tmp_d) && ((uint32)tmp_c == WPCIndSyncVal__Default) && (tmp_c != tmp_d)) {
          App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_On;
        } else {
          /* 1 */
        }
      } else {
        /* 1 */
        tmp_c = App_Model_DW.Input_INT_WPCIndSyncVal_prev;
        tmp_d = App_Model_DW.Input_INT_WPCIndSyncVal_start;
        if (((uint32)App_Model_B.Var_WPCPreSyncAct_bh5w == WPCPreSyncAct_Off) && ((tmp_c != tmp_d) && ((uint32)tmp_c == WPCIndSyncVal__Default)) && (tmp_c != tmp_d)) {
          App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_On;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_WPCPreSyncAct_bh5w == WPCPreSyncAct_On) && ((tmp_c != tmp_d) && ((uint32)tmp_d == WPCIndSyncVal__Default)) && (tmp_c != tmp_d)) {
          App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_Off;
        } else {
          /* no actions */
        }
      }

      /* End of Chart: '<S410>/IND_Animation_WPC_Priority_Flow_Graph' */

      /* Chart: '<S410>/IND_Animation_Priority_Flow_Graph1' */
      if ((uint32)App_Model_DW.is_active_c33_Jdg_DualSyncOrder == 0U) {
        RWPCPreSyncAct tmp_f;
        App_Model_DW.is_active_c33_Jdg_DualSyncOrder = 1U;
        App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__Off;

        /* 1 */
        tmp_e = App_Model_B.Var_WPCPreSyncAct_bh5w;
        tmp_f = App_Model_B.Var_RWPCPreSyncAct_baek;
        if (((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp_f == RWPCPreSyncAct_Off)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__WPC;

          /* 1 */
        } else if (((uint32)tmp_e == WPCPreSyncAct_Off) && ((uint32)tmp_f == RWPCPreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__RWPC;
        } else {
          /* 1 */
        }
      } else {
        RWPCPreSyncAct tmp_f;

        /* 1 */
        tmp_e = App_Model_B.Var_WPCPreSyncAct_bh5w;
        tmp_f = App_Model_B.Var_RWPCPreSyncAct_baek;
        if (((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp_f == RWPCPreSyncAct_Off)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__WPC;

          /* 1 */
        } else if (((uint32)tmp_e == WPCPreSyncAct_Off) && ((uint32)tmp_f == RWPCPreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__RWPC;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_PreSyncAct_gfx0 == PreSyncAct__WPC) && ((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp_f == RWPCPreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__WPCRWPC;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_PreSyncAct_gfx0 == PreSyncAct__RWPC) && ((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp_f == RWPCPreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__RWPCWPC;

          /* 1 */
        } else if (((uint32)tmp_e == WPCPreSyncAct_Off) && ((uint32)tmp_f == RWPCPreSyncAct_Off)) {
          App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__Off;
        } else {
          /* no actions */
        }
      }

      /* End of Chart: '<S410>/IND_Animation_Priority_Flow_Graph1' */

      /* Chart: '<S409>/DWPC1_Amber_Sync_Chart' */
      App_Model_DW.Output_INT_WPCIndCmdState__eo32 = App_Model_DW.Output_INT_WPCIndCmdState__lcxt;
      App_Model_DW.Output_INT_WPCIndCmdState__lcxt = App_Model_B.Output_INT_WPCIndCmdState_ca53;
      if ((uint32)App_Model_DW.is_active_c6_Jdg_DualSyncOrder_ == 0U) {
        App_Model_DW.Output_INT_WPCIndCmdState__eo32 = App_Model_B.Output_INT_WPCIndCmdState_ca53;
        App_Model_DW.is_active_c6_Jdg_DualSyncOrder_ = 1U;
        App_Model_DW.is_SyncTrigger_f0k2 = App_Mode_IN_SyncTriggerOff_ffg4;
        rtb_b_CmdLEDSync_go1s = Off;
      } else if ((uint32)App_Model_DW.is_SyncTrigger_f0k2 == App_Mode_IN_SyncTriggerOff_ffg4) {
        rtb_b_CmdLEDSync_go1s = Off;
        tmp_g = App_Model_DW.Output_INT_WPCIndCmdState__eo32;
        tmp_h = App_Model_DW.Output_INT_WPCIndCmdState__lcxt;
        if (((tmp_g != tmp_h) && ((uint32)tmp_g == WPCIndCmdState__ErrorOn)) || ((tmp_g != tmp_h) && ((uint32)tmp_g == WPCIndCmdState__ErrorFadeOut)) || ((tmp_g != tmp_h) && ((uint32)tmp_g ==
              WPCIndCmdState__ErrorFadeIn))) {
          App_Model_DW.is_SyncTrigger_f0k2 = App_Model_IN_SyncTriggerOn_bnd3;
          rtb_b_CmdLEDSync_go1s = On;
        }
      } else {
        /* case IN_SyncTriggerOn: */
        rtb_b_CmdLEDSync_go1s = On;

        /* hasChangedTo(Output_INT_WPCIndCmdState, WPCIndCmdState__3rdChrgFadeOut)||...hasChangedTo(Output_INT_WPCIndCmdState, WPCIndCmdState__2ndChrgFadeOut)||...hasChangedTo(Output_INT_WPCIndCmdState, WPCIndCmdState__1stChrgFadeOut)||... */
        tmp_g = App_Model_DW.Output_INT_WPCIndCmdState__lcxt;
        tmp_h = App_Model_DW.Output_INT_WPCIndCmdState__eo32;
        if (((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__ErrorOn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__ChrgFadeOut)) || ((tmp_h != tmp_g) && ((uint32)tmp_g ==
              WPCIndCmdState__3rdChrgOn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__3rdChrgFadeIn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__2ndChrgOn)) || ((tmp_h !=
              tmp_g) && ((uint32)tmp_g == WPCIndCmdState__2ndChrgFadeIn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__1stChrgOn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g ==
              WPCIndCmdState__1stChrgFadeIn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__ChrgOff)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__Default))) {
          App_Model_DW.is_SyncTrigger_f0k2 = App_Mode_IN_SyncTriggerOff_ffg4;
          rtb_b_CmdLEDSync_go1s = Off;
        }
      }

      /* End of Chart: '<S409>/DWPC1_Amber_Sync_Chart' */

      /* Chart: '<S409>/DWPC1_LED_Sync_Indy' */
      App_Model_DWPC1_LED_Sync_Indy(App_Model_B.b_BlinkState_duuz, rtb_b_CmdLEDSync_go1s, App_Model_B.BlinkState_pber, &rtb_b_SyncLED_ipyt, &App_Model_DW.sf_DWPC1_LED_Sync_Indy);

      /* Chart: '<S409>/DWPC2_Amber_Sync_Chart' */
      App_Model_DW.Output_INT_WPC2IndCmdState_prev = App_Model_DW.Output_INT_WPC2IndCmdState_star;
      App_Model_DW.Output_INT_WPC2IndCmdState_star = App_Model_B.Output_INT_WPC2IndCmdState;
      if ((uint32)App_Model_DW.is_active_c11_Jdg_DualSyncOrder == 0U) {
        App_Model_DW.Output_INT_WPC2IndCmdState_prev = App_Model_B.Output_INT_WPC2IndCmdState;
        App_Model_DW.is_active_c11_Jdg_DualSyncOrder = 1U;
        App_Model_DW.is_SyncTrigger_c1fa = App_Mode_IN_SyncTriggerOff_ffg4;
        rtb_b_CmdLEDSync = Off;
      } else if ((uint32)App_Model_DW.is_SyncTrigger_c1fa == App_Mode_IN_SyncTriggerOff_ffg4) {
        WPC2IndCmdState tmp_i;
        WPC2IndCmdState tmp_j;
        rtb_b_CmdLEDSync = Off;
        tmp_i = App_Model_DW.Output_INT_WPC2IndCmdState_prev;
        tmp_j = App_Model_DW.Output_INT_WPC2IndCmdState_star;
        if (((tmp_i != tmp_j) && ((uint32)tmp_i == WPC2IndCmdState__ErrorOn)) || ((tmp_i != tmp_j) && ((uint32)tmp_i == WPC2IndCmdState__ErrorFadeOut)) || ((tmp_i != tmp_j) && ((uint32)tmp_i ==
              WPC2IndCmdState__ErrorFadeIn))) {
          App_Model_DW.is_SyncTrigger_c1fa = App_Model_IN_SyncTriggerOn_bnd3;
          rtb_b_CmdLEDSync = On;
        }
      } else {
        WPC2IndCmdState tmp_i;
        WPC2IndCmdState tmp_j;

        /* case IN_SyncTriggerOn: */
        rtb_b_CmdLEDSync = On;

        /* hasChangedTo(Output_INT_WPC2IndCmdState, WPC2IndCmdState__3rdChrgFadeOut)||...hasChangedTo(Output_INT_WPC2IndCmdState, WPC2IndCmdState__2ndChrgFadeOut)||...hasChangedTo(Output_INT_WPC2IndCmdState, WPC2IndCmdState__1stChrgFadeOut)||... */
        tmp_i = App_Model_DW.Output_INT_WPC2IndCmdState_star;
        tmp_j = App_Model_DW.Output_INT_WPC2IndCmdState_prev;
        if (((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__ErrorOn)) || ((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__ChrgFadeOut)) || ((tmp_j != tmp_i) && ((uint32)tmp_i ==
              WPC2IndCmdState__3rdChrgOn)) || ((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__3rdChrgFadeIn)) || ((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__2ndChrgOn)) || ((tmp_j
              != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__2ndChrgFadeIn)) || ((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__1stChrgOn)) || ((tmp_j != tmp_i) && ((uint32)tmp_i ==
              WPC2IndCmdState__1stChrgFadeIn)) || ((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__ChrgOff)) || ((tmp_j != tmp_i) && ((uint32)tmp_i == WPC2IndCmdState__Default))) {
          App_Model_DW.is_SyncTrigger_c1fa = App_Mode_IN_SyncTriggerOff_ffg4;
          rtb_b_CmdLEDSync = Off;
        }
      }

      /* End of Chart: '<S409>/DWPC2_Amber_Sync_Chart' */

      /* Chart: '<S409>/DWPC2_LED_Sync_Indy' */
      App_Model_DWPC1_LED_Sync_Indy(App_Model_B.b_BlinkState_ly2p, rtb_b_CmdLEDSync, App_Model_B.BlinkState_nwlq, &rtb_b_SyncLED, &App_Model_DW.sf_DWPC2_LED_Sync_Indy);

      /* DataTypeConversion: '<S427>/Data Type Conversion2' */
      rtb_BCAN_RX_C_CLU_ClusterU_nv2a = (C_USMReset)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_ClusterUSM;

      /* DataTypeConversion: '<S427>/Data Type Conversion22' */
      rtb_BCAN_RX_C_CLU_DisSpdVa_dmz0 = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DisSpdVal_KPH;

      /* DataTypeConversion: '<S427>/Data Type Conversion23' */
      rtb_BCAN_RX_C_ENG_EngSta_dbk1 = (C_EngineState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_ENG_EngSta;

      /* DataTypeConversion: '<S427>/Data Type Conversion28' */
      rtb_LCAN_RX_LC_IAU_Status_b5da = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_IAU_Status;

      /* DataTypeConversion: '<S427>/Data Type Conversion3' */
      rtb_BCAN_RX_C_HCU_HevRdySt_m21u = (C_HEVEngOnState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_HCU_HevRdySta;

      /* DataTypeConversion: '<S427>/Data Type Conversion5' */
      rtb_BCAN_RX_C_WPCIndUSMSta_n1ki = (WPCIndUSMState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCIndUSMState;

      /* DataTypeConversion: '<S427>/Data Type Conversion6' */
      rtb_BCAN_RX_C_WPC2IndSyncVal = (WPC2IndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2_IndSyncVal;

      /* DataTypeConversion: '<S433>/Data Type Conversion1' */
      rtb_NvM_WPCType_ccn1 = (WPCType)rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE;

      /* DataTypeConversion: '<S435>/Data Type Conversion1' */
      rtb_Uds_LPConditionFlag_f3pw = (Bool)rtb_TmpSignalConversionAtR_Uds_.Uds_LPConditionFlag;

      /* Chart: '<S438>/WPC_Mode_LPConditionJdg' */
      App_Mod_WPC_Mode_LPConditionJdg(App_Model_B.WPCStatus_hv2c, &rtb_WPCMode_LPConditionFla_e5bi, &App_Model_DW.sf_WPC_Mode_LPConditionJdg);

      /* Chart: '<S438>/NFC_Mode_LPConditionJdg' */
      App_Mod_NFC_Mode_LPConditionJdg(App_Model_B.WPCStatus_hv2c, &rtb_NFCMode_LPConditionFla_i45m, &App_Model_DW.sf_NFC_Mode_LPConditionJdg);

      /* Chart: '<S438>/MainControl_LPConditionJdg' */
      App__MainControl_LPConditionJdg(App_Model_B.WPCStatus_hv2c, App_Model_B.b_Timer_PhoneReminderCheck_mh5z, App_Model_B.b_Timer_PhoneWarningCheck_ajyk, App_Model_B.b_Timer_WarningComplete_expw,
        App_Model_B.b_Timer_WarningTypeCheck_cenb, App_Model_B.b_PhnLeftChk_Enable_lemt, &rtb_WPCMain_LPConditionFla_g2vh, &App_Model_DW.sf_MainControl_LPConditionJdg);

      /* Chart: '<S438>/SMKLF_LPConditionJdg' */
      App_Model_SMKLF_LPConditionJdg(App_Model_B.b_LFState_fv4t, &rtb_SMKLF_LPConditionFlag__edfo, &App_Model_DW.sf_SMKLF_LPConditionJdg);

      /* Chart: '<S438>/TempSnsrErrDetect_LPConditionJdg' */
      TempSnsrErrDetect_LPConditionJd(App_Model_B.b_TempSensorFault_ahdl, App_Model_B.b_Timer_TempSensor_Check_dej2, &rtb_TempSnsrError_LPCondit_lcr4, &App_Model_DW.sf_TempSnsrErrDetect_LPConditio);

      /* Chart: '<S438>/OverTempDetect_LPConditionJdg' */
      A_OverTempDetect_LPConditionJdg(App_Model_B.b_TemperatureFault_c04g, App_Model_B.b_Timer_OverTemp_p3xh, &rtb_OverTempDetect_LPCondi_l4hp, &App_Model_DW.sf_OverTempDetect_LPConditionJd);

      /* Chart: '<S438>/OverCurrent_LPConditionJdg' */
      App__OverCurrent_LPConditionJdg(App_Model_B.b_CurrentFault_jcbo, App_Model_B.b_Timer_OvrCurr_dt5l, App_Model_B.b_Timer_ReOvrCurr_dylv, &rtb_OverCurrent_LPConditio_ivuq,
        &App_Model_DW.sf_OverCurrent_LPConditionJdg);

      /* Chart: '<S438>/FAN_LPConditionJdg' */
      App_Model_FAN_LPConditionJdg(rtb_FAN_PWM_kvyy, &rtb_FAN_LPConditionFlag_wr_djmc, &App_Model_DW.sf_FAN_LPConditionJdg);

      /* Chart: '<S438>/USM_WPC_LPConditionJdg' incorporates:
       *  Constant: '<S438>/Constant'
       *  DataStoreRead: '<S438>/Data Store Read'
       *  DataStoreRead: '<S438>/Data Store Read1'
       *  DataStoreRead: '<S438>/Data Store Read2'
       *  DataStoreRead: '<S438>/Data Store Read4'
       */
      App_Mode_USM_WPC_LPConditionJdg(m_ProfileGuestWPCUSM_App, m_ProfileOneWPCUSM_App, m_ProfileTwoWPCUSM_App, 0.0, m_ProfileThreeWPCUSM_App, &App_Model_B.P_WPC_USM_LPConditionFlag__kp25,
        &App_Model_DW.sf_USM_WPC_LPConditionJdg);

      /* BusCreator: '<S18>/Bus Creator' incorporates:
       *  Concatenate: '<S13>/Vector Concatenate'
       *  DataStoreRead: '<S438>/Data Store Read'
       *  DataStoreRead: '<S438>/Data Store Read1'
       *  DataStoreRead: '<S438>/Data Store Read2'
       *  DataStoreRead: '<S438>/Data Store Read4'
       *  DataStoreRead: '<S438>/Data Store Read5'
       *  DataStoreRead: '<S438>/Data Store Read6'
       *  DataStoreRead: '<S438>/Data Store Read7'
       *  DataStoreRead: '<S438>/Data Store Read8'
       *  DataTypeConversion: '<S438>/Data Type Conversion'
       *  DataTypeConversion: '<S438>/Data Type Conversion1'
       *  DataTypeConversion: '<S438>/Data Type Conversion10'
       *  DataTypeConversion: '<S438>/Data Type Conversion11'
       *  DataTypeConversion: '<S438>/Data Type Conversion12'
       *  DataTypeConversion: '<S438>/Data Type Conversion13'
       *  DataTypeConversion: '<S438>/Data Type Conversion14'
       *  DataTypeConversion: '<S438>/Data Type Conversion15'
       *  DataTypeConversion: '<S438>/Data Type Conversion16'
       *  DataTypeConversion: '<S438>/Data Type Conversion18'
       *  DataTypeConversion: '<S438>/Data Type Conversion19'
       *  DataTypeConversion: '<S438>/Data Type Conversion2'
       *  DataTypeConversion: '<S438>/Data Type Conversion22'
       *  DataTypeConversion: '<S438>/Data Type Conversion24'
       *  DataTypeConversion: '<S438>/Data Type Conversion25'
       *  DataTypeConversion: '<S438>/Data Type Conversion26'
       *  DataTypeConversion: '<S438>/Data Type Conversion27'
       *  DataTypeConversion: '<S438>/Data Type Conversion29'
       *  DataTypeConversion: '<S438>/Data Type Conversion3'
       *  DataTypeConversion: '<S438>/Data Type Conversion4'
       *  DataTypeConversion: '<S438>/Data Type Conversion5'
       *  DataTypeConversion: '<S438>/Data Type Conversion6'
       *  DataTypeConversion: '<S438>/Data Type Conversion7'
       *  DataTypeConversion: '<S438>/Data Type Conversion8'
       *  DataTypeConversion: '<S438>/Data Type Conversion9'
       *  Merge: '<S189>/Merge'
       *  Merge generated from: '<S24>/Merge'
       *  Merge generated from: '<S25>/Merge'
       */
      App_Model_B.Device_bn3v[0].WPCWarning = (uint8)App_Model_B.C_WPCWarning_dbwe;
      App_Model_B.Device_bn3v[0].WPCRValue = (uint8)App_Model_B.WPCRValue;
      App_Model_B.Device_bn3v[0].PhoneWarningCheck_Timer = App_Model_B.b_Timer_PhoneWarningCheck_ajyk;
      App_Model_B.Device_bn3v[0].WPCStatus = (uint8)App_Model_B.WPCStatus_hv2c;
      App_Model_B.Device_bn3v[0].FAN_PWM = rtb_FAN_PWM_kvyy;
      App_Model_B.Device_bn3v[0].FANDutyRatioSta = (uint8)App_Model_B.FANDutyRatioSta_lwkf;
      App_Model_B.Device_bn3v[0].ChargingEnable = (uint8)App_Model_B.b_ChargingEnable_f5ak;
      App_Model_B.Device_bn3v[0].TempSensorFault = (uint8)App_Model_B.b_TempSensorFault_ahdl;
      App_Model_B.Device_bn3v[0].BlinkState = (uint8)App_Model_B.b_BlinkState_duuz;
      App_Model_B.Device_bn3v[0].LFState = (uint8)App_Model_B.b_LFState_fv4t;
      App_Model_B.Device_bn3v[0].AmberIND_OUT = App_Model_B.P_AmberIND_OUT_j3u5;
      App_Model_B.Device_bn3v[0].GreenIND1_OUT = App_Model_B.P_GreenIND_OUT_c12b;
      App_Model_B.Device_bn3v[0].GreenIND2_OUT = App_Model_B.P_GreenIND2_OUT_dniy;
      App_Model_B.Device_bn3v[0].GreenIND3_OUT = App_Model_B.P_GreenIND3_OUT_oayi;
      App_Model_B.Device_bn3v[0].PhnLeftChk_Enable = (uint8)App_Model_B.b_PhnLeftChk_Enable_lemt;
      App_Model_B.Device_bn3v[0].WPCMode_LPConditionFlag = rtb_WPCMode_LPConditionFla_e5bi;
      App_Model_B.Device_bn3v[0].NFCMode_LPConditionFlag = rtb_NFCMode_LPConditionFla_i45m;
      App_Model_B.Device_bn3v[0].WPCMain_LPConditionFlag = rtb_WPCMain_LPConditionFla_g2vh;
      App_Model_B.Device_bn3v[0].SMKLF_LPConditionFlag = rtb_SMKLF_LPConditionFlag__edfo;
      App_Model_B.Device_bn3v[0].TempSnsrError_LPConditionFlag = rtb_TempSnsrError_LPCondit_lcr4;
      App_Model_B.Device_bn3v[0].OverTempDetect_LPConditionFlag = rtb_OverTempDetect_LPCondi_l4hp;
      App_Model_B.Device_bn3v[0].OverCurrent_LPConditionFlag = rtb_OverCurrent_LPConditio_ivuq;
      App_Model_B.Device_bn3v[0].FAN_LPConditionFlag = rtb_FAN_LPConditionFlag_wr_djmc;
      App_Model_B.Device_bn3v[0].TemperatureFault = (uint8)App_Model_B.b_TemperatureFault_c04g;
      App_Model_B.Device_bn3v[0].CurrentFault = (uint8)App_Model_B.b_CurrentFault_jcbo;
      App_Model_B.Device_bn3v[0].m_ProfileGuestWPCUSM = (uint8)m_ProfileGuestWPCUSM_App;
      App_Model_B.Device_bn3v[0].m_ProfileOneWPCUSM = (uint8)m_ProfileOneWPCUSM_App;
      App_Model_B.Device_bn3v[0].m_ProfileTwoWPCUSM = (uint8)m_ProfileTwoWPCUSM_App;
      App_Model_B.Device_bn3v[0].m_ProfileThreeWPCUSM = (uint8)m_ProfileThreeWPCUSM_App;
      App_Model_B.Device_bn3v[0].m_RWPCUSM = App_Model_ConstB.m_RWPCUSM_j4ys;
      App_Model_B.Device_bn3v[0].USM_LPConditionFlag = App_Model_B.P_WPC_USM_LPConditionFlag__kp25;
      App_Model_B.Device_bn3v[0].WPCIndUSMState = App_Model_ConstB.WPCIndUSMState_e11k;
      App_Model_B.Device_bn3v[0].WPCIndSyncVal = App_Model_ConstB.WPCIndSyncVal_inxi;
      App_Model_B.Device_bn3v[0].RWPCIndSyncVal = App_Model_ConstB.RWPCIndSyncVal_ksit;
      App_Model_B.Device_bn3v[0].m_ProfileGuestFanUSM = (uint8)m_ProfileGuestWPCFanUSM_App;
      App_Model_B.Device_bn3v[0].m_ProfileOneFanUSM = (uint8)m_ProfileOneWPCFanUSM_App;
      App_Model_B.Device_bn3v[0].m_ProfileTwoFanUSM = (uint8)m_ProfileTwoWPCFanUSM_App;
      App_Model_B.Device_bn3v[0].m_ProfileThreeFanUSM = (uint8)m_ProfileThreeWPCFanUSM_App;
      App_Model_B.Device_bn3v[0].m_RWPCFanUSM = App_Model_ConstB.m_RWPCFanUSM_a1lp;

      /* Chart: '<S439>/WPC_Mode_LPConditionJdg' */
      App_Mod_WPC_Mode_LPConditionJdg(App_Model_B.WPC2Status, &rtb_WPCMode_LPConditionFla_pady, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_lmx5);

      /* Chart: '<S439>/NFC_Mode_LPConditionJdg' */
      App_Mod_NFC_Mode_LPConditionJdg(App_Model_B.WPC2Status, &rtb_NFCMode_LPConditionFla_jmfo, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_gc1n);

      /* Chart: '<S439>/MainControl_LPConditionJdg' */
      App__MainControl_LPConditionJdg(App_Model_B.WPC2Status, App_Model_B.b_Timer_PhoneReminderCheck_mflq, App_Model_B.b_Timer_PhoneWarningCheck_o0i3, App_Model_B.b_Timer_WarningComplete_ghdo,
        App_Model_B.b_Timer_WarningTypeCheck_i40f, App_Model_B.b_PhnLeftChk_Enable_m2kv, &rtb_WPCMain_LPConditionFla_cfn0, &App_Model_DW.sf_MainControl_LPCondition_kcum);

      /* Chart: '<S439>/SMKLF_LPConditionJdg' */
      App_Model_SMKLF_LPConditionJdg(App_Model_B.b_LFState_kucz, &rtb_SMKLF_LPConditionFlag__fnej, &App_Model_DW.sf_SMKLF_LPConditionJdg_esv2);

      /* Chart: '<S439>/TempSnsrErrDetect_LPConditionJdg' */
      TempSnsrErrDetect_LPConditionJd(App_Model_B.b_TempSensorFault_futc, App_Model_B.b_Timer_TempSensor_Check_eer0, &rtb_TempSnsrError_LPCondit_egth, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_c3yn);

      /* Chart: '<S439>/OverTempDetect_LPConditionJdg' */
      A_OverTempDetect_LPConditionJdg(App_Model_B.b_TemperatureFault_fxyc, App_Model_B.b_Timer_OverTemp_ce1w, &rtb_OverTempDetect_LPCondi_bvam, &App_Model_DW.sf_OverTempDetect_LPCondit_ehj5);

      /* Chart: '<S439>/OverCurrent_LPConditionJdg' */
      App__OverCurrent_LPConditionJdg(App_Model_B.b_CurrentFault_kptm, App_Model_B.b_Timer_OvrCurr_bvyp, App_Model_B.b_Timer_ReOvrCurr_gm1e, &rtb_OverCurrent_LPConditio_p4qh,
        &App_Model_DW.sf_OverCurrent_LPCondition_p2tn);

      /* Chart: '<S439>/FAN_LPConditionJdg' */
      App_Model_FAN_LPConditionJdg(rtb_FAN_PWM_luhf, &rtb_FAN_LPConditionFlag_wr_ddyr, &App_Model_DW.sf_FAN_LPConditionJdg_gs2a);

      /* Chart: '<S439>/USM_WPC2_LPCondition' incorporates:
       *  Constant: '<S439>/Constant'
       *  DataStoreRead: '<S439>/Data Store Read1'
       *  DataStoreRead: '<S439>/Data Store Read6'
       *  DataStoreRead: '<S439>/Data Store Read7'
       *  DataStoreRead: '<S439>/Data Store Read8'
       */
      App_Model_DW.sfEvent_px3u = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.m_ProfileGuestWPC2USM_App_prev = App_Model_DW.m_ProfileGuestWPC2USM_App_start;
      App_Model_DW.m_ProfileGuestWPC2USM_App_start = m_ProfileGuestWPC2USM_App;
      App_Model_DW.m_ProfileOneWPC2USM_App_prev = App_Model_DW.m_ProfileOneWPC2USM_App_start;
      App_Model_DW.m_ProfileOneWPC2USM_App_start = m_ProfileOneWPC2USM_App;
      App_Model_DW.m_ProfileTwoWPC2USM_App_prev = App_Model_DW.m_ProfileTwoWPC2USM_App_start;
      App_Model_DW.m_ProfileTwoWPC2USM_App_start = m_ProfileTwoWPC2USM_App;
      App_Model_DW.m_ProfileThreeWPC2USM_App_prev = App_Model_DW.m_ProfileThreeWPC2USM_App_start;
      App_Model_DW.m_ProfileThreeWPC2USM_App_start = m_ProfileThreeWPC2USM_App;
      App_Model_DW.m_RWPCUSM_App_prev = App_Model_DW.m_RWPCUSM_App_start;
      App_Model_DW.m_RWPCUSM_App_start = 0.0;
      if ((uint32)App_Model_DW.is_active_c11_LPConditionJdg_li == 0U) {
        App_Model_DW.m_ProfileGuestWPC2USM_App_prev = m_ProfileGuestWPC2USM_App;
        App_Model_DW.m_ProfileOneWPC2USM_App_prev = m_ProfileOneWPC2USM_App;
        App_Model_DW.m_ProfileTwoWPC2USM_App_prev = m_ProfileTwoWPC2USM_App;
        App_Model_DW.m_ProfileThreeWPC2USM_App_prev = m_ProfileThreeWPC2USM_App;
        App_Model_DW.m_RWPCUSM_App_prev = 0.0;
        App_Model_DW.is_active_c11_LPConditionJdg_li = 1U;
        App_Model_DW.is_active_LPConditionHold_bwlz = 1U;
        App_Model_DW.is_LPConditionHold_gkga = App_IN_LPConditionHold_Off_kvlq;
        App_Model_DW.Timer_LPConditionHold_n0a4 = 0U;
        App_Model_DW.is_active_LPConditionChk_C_kxfd = 1U;
        App_Model_DW.is_LPConditionChk_Chart_oepo = App_Mod_IN_LPCondition_Off_gfto;
        App_Model_DW.sfEvent_px3u = (sint32)event_StartTimer_LPConditi_i0nb;
        App_Model_LPConditionHold_bgap();
        App_Model_DW.sfEvent_px3u = -1;
        App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;

        /* Awake */
        App_Model_DW.ECUResetEnable_pyqo = 0U;
      } else {
        if ((uint32)App_Model_DW.is_active_LPConditionHold_bwlz != 0U) {
          App_Model_LPConditionHold_bgap();
        }

        if ((uint32)App_Model_DW.is_active_LPConditionChk_C_kxfd != 0U) {
          switch (App_Model_DW.is_LPConditionChk_Chart_oepo) {
           case App_Mod_IN_LPCondition_Off_gfto:
            App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
            if (App_Model_DW.ECUResetEnable_pyqo == 1U) {
              App_Model_DW.sfEvent_px3u = (sint32)event_CancelTimer_LPCondit_nxtu;
              if ((uint32)App_Model_DW.is_active_LPConditionHold_bwlz != 0U) {
                App_Model_LPConditionHold_bgap();
              }

              App_Model_DW.sfEvent_px3u = -1;
              App_Model_DW.ECUResetEnable_pyqo = 0U;
              App_Model_DW.is_LPConditionChk_Chart_oepo = App_Mode_IN_LPCondition_On_nvlj;
              App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 1U;

              /* SleepOK */
            } else {
              App__LPConditionTimerCheck_lfzr();
            }
            break;

           case App_Mode_IN_LPCondition_On_nvlj:
            App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 1U;
            if ((App_Model_DW.m_ProfileGuestWPC2USM_App_prev != App_Model_DW.m_ProfileGuestWPC2USM_App_start) || (App_Model_DW.m_ProfileOneWPC2USM_App_prev !=
                 App_Model_DW.m_ProfileOneWPC2USM_App_start) || (App_Model_DW.m_ProfileTwoWPC2USM_App_prev != App_Model_DW.m_ProfileTwoWPC2USM_App_start) ||
                (App_Model_DW.m_ProfileThreeWPC2USM_App_prev != App_Model_DW.m_ProfileThreeWPC2USM_App_start) || (App_Model_DW.m_RWPCUSM_App_prev != App_Model_DW.m_RWPCUSM_App_start)) {
              App_Model_DW.is_LPConditionChk_Chart_oepo = App_Mod_IN_LPCondition_Off_gfto;
              App_Model_DW.sfEvent_px3u = (sint32)event_StartTimer_LPConditi_i0nb;
              if ((uint32)App_Model_DW.is_active_LPConditionHold_bwlz != 0U) {
                App_Model_LPConditionHold_bgap();
              }

              App_Model_DW.sfEvent_px3u = -1;
              App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;

              /* Awake */
              App_Model_DW.ECUResetEnable_pyqo = 0U;
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }

      /* End of Chart: '<S439>/USM_WPC2_LPCondition' */

      /* BusCreator: '<S18>/Bus Creator3' incorporates:
       *  Concatenate: '<S13>/Vector Concatenate'
       *  DataStoreRead: '<S439>/Data Store Read1'
       *  DataStoreRead: '<S439>/Data Store Read2'
       *  DataStoreRead: '<S439>/Data Store Read4'
       *  DataStoreRead: '<S439>/Data Store Read5'
       *  DataStoreRead: '<S439>/Data Store Read6'
       *  DataStoreRead: '<S439>/Data Store Read7'
       *  DataStoreRead: '<S439>/Data Store Read8'
       *  DataStoreRead: '<S439>/Data Store Read9'
       *  DataTypeConversion: '<S439>/Data Type Conversion'
       *  DataTypeConversion: '<S439>/Data Type Conversion1'
       *  DataTypeConversion: '<S439>/Data Type Conversion10'
       *  DataTypeConversion: '<S439>/Data Type Conversion11'
       *  DataTypeConversion: '<S439>/Data Type Conversion12'
       *  DataTypeConversion: '<S439>/Data Type Conversion13'
       *  DataTypeConversion: '<S439>/Data Type Conversion14'
       *  DataTypeConversion: '<S439>/Data Type Conversion15'
       *  DataTypeConversion: '<S439>/Data Type Conversion16'
       *  DataTypeConversion: '<S439>/Data Type Conversion18'
       *  DataTypeConversion: '<S439>/Data Type Conversion19'
       *  DataTypeConversion: '<S439>/Data Type Conversion2'
       *  DataTypeConversion: '<S439>/Data Type Conversion22'
       *  DataTypeConversion: '<S439>/Data Type Conversion24'
       *  DataTypeConversion: '<S439>/Data Type Conversion25'
       *  DataTypeConversion: '<S439>/Data Type Conversion26'
       *  DataTypeConversion: '<S439>/Data Type Conversion27'
       *  DataTypeConversion: '<S439>/Data Type Conversion29'
       *  DataTypeConversion: '<S439>/Data Type Conversion3'
       *  DataTypeConversion: '<S439>/Data Type Conversion4'
       *  DataTypeConversion: '<S439>/Data Type Conversion5'
       *  DataTypeConversion: '<S439>/Data Type Conversion6'
       *  DataTypeConversion: '<S439>/Data Type Conversion7'
       *  DataTypeConversion: '<S439>/Data Type Conversion8'
       *  DataTypeConversion: '<S439>/Data Type Conversion9'
       *  Merge generated from: '<S219>/Merge'
       *  Merge generated from: '<S220>/Merge'
       *  Merge: '<S379>/Merge'
       */
      App_Model_B.Device_bn3v[1].WPCWarning = (uint8)App_Model_B.C_WPC2Warning;
      App_Model_B.Device_bn3v[1].WPCRValue = (uint8)App_Model_B.WPC2RValue;
      App_Model_B.Device_bn3v[1].PhoneWarningCheck_Timer = App_Model_B.b_Timer_PhoneWarningCheck_o0i3;
      App_Model_B.Device_bn3v[1].WPCStatus = (uint8)App_Model_B.WPC2Status;
      App_Model_B.Device_bn3v[1].FAN_PWM = rtb_FAN_PWM_luhf;
      App_Model_B.Device_bn3v[1].FANDutyRatioSta = (uint8)App_Model_B.FANDutyRatioSta_acxf;
      App_Model_B.Device_bn3v[1].ChargingEnable = (uint8)App_Model_B.b_ChargingEnable_lkuy;
      App_Model_B.Device_bn3v[1].TempSensorFault = (uint8)App_Model_B.b_TempSensorFault_futc;
      App_Model_B.Device_bn3v[1].BlinkState = (uint8)App_Model_B.b_BlinkState_ly2p;
      App_Model_B.Device_bn3v[1].LFState = (uint8)App_Model_B.b_LFState_kucz;
      App_Model_B.Device_bn3v[1].AmberIND_OUT = App_Model_B.P_AmberIND_OUT_hhha;
      App_Model_B.Device_bn3v[1].GreenIND1_OUT = App_Model_B.P_GreenIND_OUT_jrko;
      App_Model_B.Device_bn3v[1].GreenIND2_OUT = App_Model_B.P_GreenIND2_OUT_kfol;
      App_Model_B.Device_bn3v[1].GreenIND3_OUT = App_Model_B.P_GreenIND3_OUT_olhg;
      App_Model_B.Device_bn3v[1].PhnLeftChk_Enable = (uint8)App_Model_B.b_PhnLeftChk_Enable_m2kv;
      App_Model_B.Device_bn3v[1].WPCMode_LPConditionFlag = rtb_WPCMode_LPConditionFla_pady;
      App_Model_B.Device_bn3v[1].NFCMode_LPConditionFlag = rtb_NFCMode_LPConditionFla_jmfo;
      App_Model_B.Device_bn3v[1].WPCMain_LPConditionFlag = rtb_WPCMain_LPConditionFla_cfn0;
      App_Model_B.Device_bn3v[1].SMKLF_LPConditionFlag = rtb_SMKLF_LPConditionFlag__fnej;
      App_Model_B.Device_bn3v[1].TempSnsrError_LPConditionFlag = rtb_TempSnsrError_LPCondit_egth;
      App_Model_B.Device_bn3v[1].OverTempDetect_LPConditionFlag = rtb_OverTempDetect_LPCondi_bvam;
      App_Model_B.Device_bn3v[1].OverCurrent_LPConditionFlag = rtb_OverCurrent_LPConditio_p4qh;
      App_Model_B.Device_bn3v[1].FAN_LPConditionFlag = rtb_FAN_LPConditionFlag_wr_ddyr;
      App_Model_B.Device_bn3v[1].TemperatureFault = (uint8)App_Model_B.b_TemperatureFault_fxyc;
      App_Model_B.Device_bn3v[1].CurrentFault = (uint8)App_Model_B.b_CurrentFault_kptm;
      App_Model_B.Device_bn3v[1].m_ProfileGuestWPCUSM = (uint8)m_ProfileGuestWPC2USM_App;
      App_Model_B.Device_bn3v[1].m_ProfileOneWPCUSM = (uint8)m_ProfileOneWPC2USM_App;
      App_Model_B.Device_bn3v[1].m_ProfileTwoWPCUSM = (uint8)m_ProfileTwoWPC2USM_App;
      App_Model_B.Device_bn3v[1].m_ProfileThreeWPCUSM = (uint8)m_ProfileThreeWPC2USM_App;
      App_Model_B.Device_bn3v[1].m_RWPCUSM = App_Model_ConstB.m_RWPCUSM_m0pm;
      App_Model_B.Device_bn3v[1].USM_LPConditionFlag = App_Model_B.P_WPC2_USM_LPConditionFlag_writ;
      App_Model_B.Device_bn3v[1].WPCIndUSMState = App_Model_ConstB.WPCIndUSMState_k3sp;
      App_Model_B.Device_bn3v[1].WPCIndSyncVal = App_Model_ConstB.WPCIndSyncVal_ispm;
      App_Model_B.Device_bn3v[1].RWPCIndSyncVal = App_Model_ConstB.RWPCIndSyncVal_esuo;
      App_Model_B.Device_bn3v[1].m_ProfileGuestFanUSM = (uint8)m_ProfileGuestWPC2FanUSM_App;
      App_Model_B.Device_bn3v[1].m_ProfileOneFanUSM = (uint8)m_ProfileOneWPC2FanUSM_App;
      App_Model_B.Device_bn3v[1].m_ProfileTwoFanUSM = (uint8)m_ProfileTwoWPC2FanUSM_App;
      App_Model_B.Device_bn3v[1].m_ProfileThreeFanUSM = (uint8)m_ProfileThreeWPC2FanUSM_App;
      App_Model_B.Device_bn3v[1].m_RWPCFanUSM = App_Model_ConstB.m_RWPCFanUSM_igvf;

      /* Update for UnitDelay: '<S431>/Unit Delay' */
      App_Model_DW.UnitDelay_DSTATE_d0ul = App_Model_B.Output_INT_WPCIndUSMState_bcrl;

      /* Update for UnitDelay: '<S431>/Unit Delay2' */
      App_Model_DW.UnitDelay2_DSTATE = App_Model_B.Output_CAN_WPC2IndSyncVal;

      /* Update for UnitDelay: '<S431>/Unit Delay4' */
      App_Model_DW.UnitDelay4_DSTATE_kskc = App_Model_B.Output_INT_WPCIndCmdState_ca53;

      /* Update for UnitDelay: '<S431>/Unit Delay5' */
      App_Model_DW.UnitDelay5_DSTATE = App_Model_B.Output_INT_WPC2IndCmdState;

      /* Update for UnitDelay: '<S431>/Unit Delay9' */
      App_Model_DW.UnitDelay9_DSTATE_afvw = rtb_b_CmdLEDSync_go1s;

      /* Update for UnitDelay: '<S431>/Unit Delay10' */
      App_Model_DW.UnitDelay10_DSTATE_ijjh = rtb_b_SyncLED_ipyt;

      /* Update for UnitDelay: '<S431>/Unit Delay13' */
      App_Model_DW.UnitDelay13_DSTATE = App_Model_B.Var_PreSyncAct_akzv;

      /* Update for UnitDelay: '<S431>/Unit Delay15' incorporates:
       *  Merge generated from: '<S25>/Merge'
       */
      App_Model_DW.UnitDelay15_DSTATE_kgaf = App_Model_B.C_WPCWarning_dbwe;

      /* Update for UnitDelay: '<S431>/Unit Delay7' incorporates:
       *  Merge: '<S379>/Merge'
       */
      App_Model_DW.UnitDelay7_DSTATE_m4bk = App_Model_B.WPC2Status;

      /* Update for UnitDelay: '<S431>/Unit Delay8' */
      App_Model_DW.UnitDelay8_DSTATE = App_Model_B.NFCDetectOrder;

      /* Update for UnitDelay: '<S431>/Unit Delay17' */
      App_Model_DW.UnitDelay17_DSTATE = App_Model_B.LPCDWakeUpOrder;

      /* Update for UnitDelay: '<S431>/Unit Delay18' incorporates:
       *  Merge generated from: '<S25>/Merge'
       */
      App_Model_DW.UnitDelay18_DSTATE_ghv5 = App_Model_B.b_PhnLeftChk_Enable_lemt;

      /* Update for UnitDelay: '<S431>/Unit Delay1' */
      App_Model_DW.UnitDelay1_DSTATE = App_Model_B.Output_CAN_WPCIndSyncVal_i4yx;

      /* Update for UnitDelay: '<S431>/Unit Delay11' */
      App_Model_DW.UnitDelay11_DSTATE_ibvb = rtb_b_CmdLEDSync;

      /* Update for UnitDelay: '<S431>/Unit Delay12' */
      App_Model_DW.UnitDelay12_DSTATE_kt23 = rtb_b_SyncLED;

      /* Update for UnitDelay: '<S431>/Unit Delay14' */
      App_Model_DW.UnitDelay14_DSTATE = App_Model_B.Var_PreSyncAct_gfx0;

      /* Update for UnitDelay: '<S431>/Unit Delay16' incorporates:
       *  Merge generated from: '<S220>/Merge'
       */
      App_Model_DW.UnitDelay16_DSTATE_fcip = App_Model_B.C_WPC2Warning;

      /* Update for UnitDelay: '<S431>/Unit Delay3' incorporates:
       *  Merge: '<S189>/Merge'
       */
      App_Model_DW.UnitDelay3_DSTATE_lcrf = App_Model_B.WPCStatus_hv2c;

      /* Update for UnitDelay: '<S431>/Unit Delay19' incorporates:
       *  Merge generated from: '<S220>/Merge'
       */
      App_Model_DW.UnitDelay19_DSTATE_oefu = App_Model_B.b_PhnLeftChk_Enable_m2kv;
    } else if (App_Model_DW.DualWPC_MODE) {
      /* Disable for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
      /* Disable for Atomic SubSystem: '<S22>/IndyOutputControl_Function' */
      IndyOutputControl_Funct_Disable();

      /* End of Disable for SubSystem: '<S22>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S16>/DWPC1_TE_sys' */

      /* Disable for Atomic SubSystem: '<S16>/DWPC2_TE_sys' */
      /* Disable for Atomic SubSystem: '<S217>/IndyOutputControl_Function' */
      IndyOutputControl__gkc5_Disable();

      /* End of Disable for SubSystem: '<S217>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S16>/DWPC2_TE_sys' */
      App_Model_DW.DualWPC_MODE = false;
    } else {
      /* no actions */
    }

    /* End of RelationalOperator: '<S12>/Compare' */
    /* End of Outputs for SubSystem: '<S3>/DualWPC' */

    /* Outputs for Enabled SubSystem: '<S3>/SingleWPC' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    /* RelationalOperator: '<S10>/Compare' incorporates:
     *  Constant: '<S10>/Constant'
     *  DataTypeConversion: '<S3>/Data Type Conversion2'
     */
    if (rtb_TmpSignalConversionAtR_NvM_.WPC_NAME == (uint8)WPC) {
      if (!App_Model_DW.SingleWPC_MODE) {
        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay' */
        App_Model_DW.UnitDelay_DSTATE = WPCIndUSMState__Default;

        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay4' */
        App_Model_DW.UnitDelay4_DSTATE = WPCIndCmdState__Default;

        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay9' */
        App_Model_DW.UnitDelay9_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay10' */
        App_Model_DW.UnitDelay10_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay15' */
        App_Model_DW.UnitDelay15_DSTATE = WPCWarningOff;

        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay18' */
        App_Model_DW.UnitDelay18_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S844>/Unit Delay3' */
        App_Model_DW.UnitDelay3_DSTATE = ModeOff;

        /* SystemReset for Chart: '<S840>/DoorOpenCloseStateFunctionFlowGraph' */
        DoorOpenCloseStateFunctio_Reset(&App_Model_B.b_AstDrSw, &App_Model_B.b_DrvDrSw, &App_Model_B.b_RLDrSw, &App_Model_B.b_RRDrSw, &App_Model_DW.sf_DoorOpenCloseStateFunct_gpcq);

        /* SystemReset for Atomic SubSystem: '<S635>/SWPC_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S640>/TemperatureSensorErrorDetect_Function' */
        TemperatureSensorErr_nw4b_Reset(&App_Model_B.b_TempSensorFault, &App_Model_B.b_Timer_TempSensor_Check);

        /* End of SystemReset for SubSystem: '<S640>/TemperatureSensorErrorDetect_Function' */

        /* SystemReset for Atomic SubSystem: '<S640>/PreventionSMK_LF_Interference_Function' */
        PreventionSMK_LF_Int_gbj0_Reset(&App_Model_B.b_LFState);

        /* End of SystemReset for SubSystem: '<S640>/PreventionSMK_LF_Interference_Function' */

        /* SystemReset for Atomic SubSystem: '<S640>/OverCurrentDetecting_Function' */
        OverCurrentDetecting_lftl_Reset(&App_Model_B.b_CurrentFault, &App_Model_B.b_Timer_OvrCurr, &App_Model_B.b_Timer_ReOvrCurr);

        /* End of SystemReset for SubSystem: '<S640>/OverCurrentDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S640>/OverTemperatureDetecting_Function' */
        OverTemperatureDetec_dein_Reset(&App_Model_B.b_TemperatureFault, &App_Model_B.b_Timer_OverTemp);

        /* End of SystemReset for SubSystem: '<S640>/OverTemperatureDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S640>/WPC_PhoneLeftDetectingControl_Function' */
        WPC_PhoneLeftDetecti_fmai_Reset(&App_Model_B.Output_PhoneLeftWarningWPCStatu);

        /* End of SystemReset for SubSystem: '<S640>/WPC_PhoneLeftDetectingControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S638>/WPC_MainControl_Function' */
        WPC_MainControl_Func_aih4_Reset();

        /* End of SystemReset for SubSystem: '<S638>/WPC_MainControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S639>/FAN_Control_Function' */
        FAN_Control_Function_a5e3_Reset(&rtb_FAN_PWM, &App_Model_B.FANDutyRatioSta);

        /* End of SystemReset for SubSystem: '<S639>/FAN_Control_Function' */

        /* SystemReset for Atomic SubSystem: '<S639>/IND_Animation_Control_Function' */
        /* SystemReset for Atomic SubSystem: '<S644>/SWPC_INDAnimationControl' */
        /* SystemReset for Chart: '<S652>/IND_Animation_WPC2_Priority_Flow_Graph' */
        IND_Animation_WPC2_Priori_Reset(&App_Model_B.Var_WPC2PreSyncAct, &App_Model_DW.sf_IND_Animation_WPC2_Prio_msgq);

        /* SystemReset for Chart: '<S652>/IND_Animation_RWPC_Priority_Flow_Graph' */
        IND_Animation_RWPC_Priori_Reset(&App_Model_B.Var_RWPCPreSyncAct, &App_Model_DW.sf_IND_Animation_RWPC_Prio_his4);

        /* SystemReset for Chart: '<S652>/IND_Animation_Priority_Flow_Graph' */
        IND_Animation_Priority_Fl_Reset(&App_Model_B.Var_PreSyncAct, &App_Model_DW.sf_IND_Animation_Priority__njws);

        /* SystemReset for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */
        App_Model_DW.is_active_INDPhaseState = 0U;
        App_Model_DW.is_INDPhaseState = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_WPC2_IND_Command_Stat = 0U;
        App_Model_DW.is_WPC2_IND_Command_State_Contr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c168_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDPhaseState = 0U;
        App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_start = WPC2IndSyncVal__Default;

        /* SystemReset for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */
        App_Model_DW.is_active_INDPhaseState_o34r = 0U;
        App_Model_DW.is_INDPhaseState_n5rr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_RWPC_IND_Command_Stat = 0U;
        App_Model_DW.is_RWPC_IND_Command_State_Contr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c167_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDPhaseState_gnkj = 0U;
        App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;

        /* SystemReset for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
         *  Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart'
         *  Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart'
         */
        App_Model_DW.is_active_INDFadeIn = 0U;
        App_Model_DW.is_INDFadeIn = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDFadeOut = 0U;
        App_Model_DW.is_INDFadeOut = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDLight = 0U;
        App_Model_DW.is_INDLight = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_IND_Animation_Sync_Co = 0U;
        App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_1stS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_2ndS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c165_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDLight = 0U;
        App_Model_DW.Timer_INDFadeIn = 0U;
        App_Model_DW.Timer_INDFadeOut = 0U;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
        App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
        App_Model_DW.Var_PreSyncAct_start = PreSyncAct__Off;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_s_fuhd = RWPCIndSyncVal__Default;
        App_Model_DW.Var_INT_RWPCIndCmdState_start = RWPCIndCmdState__Default;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_s_hoel = WPC2IndSyncVal__Default;
        App_Model_DW.Var_INT_WPC2IndCmdState_start = WPC2IndCmdState__Default;
        App_Model_DW.WPCIndUSMState_start = WPCIndUSMState__Default;
        App_Model_DW.b_SyncAmber_start = Off;

        /* SystemReset for Chart: '<S652>/Amber_Sync_Chart' incorporates:
         *  Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_SyncTrigger = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c161_WPC_IND_Animatio = 0U;
        rtb_b_CmdAmberSync = Off;
        App_Model_DW.Output_INT_WPCIndCmdState_start = WPCIndCmdState__Default;

        /* SystemReset for Chart: '<S652>/Amber_Sync_Indy' */
        App_Model_Amber_Sync_Indy_Reset(&rtb_b_SyncAmber, &App_Model_DW.sf_Amber_Sync_Indy_mh0e);

        /* End of SystemReset for SubSystem: '<S644>/SWPC_INDAnimationControl' */

        /* SystemReset for Atomic SubSystem: '<S644>/SWPC_INDAnimationUSMSettingControl_v_1_2' */
        /* SystemReset for Chart: '<S661>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
        IND_Animation_Profile_Dec_Reset(&App_Model_B.CurProfile, &App_Model_DW.sf_IND_Animation_Profile_D_amxp);

        /* SystemReset for Chart: '<S661>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
        IND_Animation_USM_Setting_Reset(&App_Model_B.Output_CAN_WPCIndUSMState, &Output_INT_WPCIndUSMState, &App_Model_DW.sf_IND_Animation_USM_Setti_mmqi);

        /* End of SystemReset for SubSystem: '<S644>/SWPC_INDAnimationUSMSettingControl_v_1_2' */
        /* End of SystemReset for SubSystem: '<S639>/IND_Animation_Control_Function' */
        /* End of SystemReset for SubSystem: '<S635>/SWPC_TE_sys' */

        /* SystemReset for Chart: '<S852>/WPC_Mode_LPConditionJdg' */
        A_WPC_Mode_LPConditionJdg_Reset(&rtb_WPCMode_LPConditionFlag_wri, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_p0on);

        /* SystemReset for Chart: '<S852>/NFC_Mode_LPConditionJdg' */
        A_NFC_Mode_LPConditionJdg_Reset(&rtb_NFCMode_LPConditionFlag_wri, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_gkrq);

        /* SystemReset for Chart: '<S852>/MainControl_LPConditionJdg' */
        MainControl_LPConditionJd_Reset(&rtb_WPCMain_LPConditionFlag_wri, &App_Model_DW.sf_MainControl_LPCondition_gatm);

        /* SystemReset for Chart: '<S852>/SMKLF_LPConditionJdg' */
        App__SMKLF_LPConditionJdg_Reset(&rtb_SMKLF_LPConditionFlag_write, &App_Model_DW.sf_SMKLF_LPConditionJdg_j4fk);

        /* SystemReset for Chart: '<S852>/TempSnsrErrDetect_LPConditionJdg' */
        TempSnsrErrDetect_LPCondi_Reset(&rtb_TempSnsrError_LPConditionFl, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_ftjz);

        /* SystemReset for Chart: '<S852>/OverTempDetect_LPConditionJdg' */
        OverTempDetect_LPConditio_Reset(&rtb_OverTempDetect_LPConditionF, &App_Model_DW.sf_OverTempDetect_LPCondit_al4m);

        /* SystemReset for Chart: '<S852>/OverCurrent_LPConditionJdg' */
        OverCurrent_LPConditionJd_Reset(&rtb_OverCurrent_LPConditionFlag, &App_Model_DW.sf_OverCurrent_LPCondition_alin);

        /* SystemReset for Chart: '<S852>/FAN_LPConditionJdg' */
        App_Mo_FAN_LPConditionJdg_Reset(&rtb_FAN_LPConditionFlag_write, &App_Model_DW.sf_FAN_LPConditionJdg_jyac);

        /* SystemReset for Chart: '<S852>/USM_WPC_LPConditionJdg' */
        Ap_USM_WPC_LPConditionJdg_Reset(&App_Model_B.P_WPC_USM_LPConditionFlag_write, &App_Model_DW.sf_USM_WPC_LPConditionJdg_n0v1);
        App_Model_DW.SingleWPC_MODE = true;
      }

      /* DataTypeConversion: '<S846>/Data Type Conversion45' */
      rtb_NvM_INDContType = (INDContType)rtb_TmpSignalConversionAtR_NvM_.INDContType;

      /* DataTypeConversion: '<S846>/Data Type Conversion52' */
      rtb_NvM_RheostatOption = (RheostatOption)rtb_TmpSignalConversionAtR_NvM_.RheostatOption;

      /* DataTypeConversion: '<S846>/Data Type Conversion40' */
      App_Model_B.NvM_IndUSMOption = (Bool)rtb_TmpSignalConversionAtR_NvM_.IndUSMOption;

      /* DataTypeConversion: '<S846>/Data Type Conversion2' */
      rtb_NvM_EVOpt = (Bool)rtb_TmpSignalConversionAtR_NvM_.EVOption;

      /* DataTypeConversion: '<S839>/Data Type Conversion' */
      App_Model_B.ADC_IGN1_IN = (Bool)rtb_TmpSignalConversionAtR_ADC_.IGN1_IN;

      /* DataTypeConversion: '<S839>/Data Type Conversion8' */
      rtb_ADC_BatSysStateFault = (Bool)rtb_TmpSignalConversionAtR_ADC_.BatSysStateFault;

      /* DataTypeConversion: '<S848>/Data Type Conversion32' */
      rtb_Uds_m_NFCOption = (Bool)rtb_TmpSignalConversionAtR_Uds_.m_NFCOption;

      /* DataTypeConversion: '<S840>/Data Type Conversion1' */
      App_Model_B.BCAN_RX_C_LFAnt_SrchSta = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_LFAnt_SrchSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion16' */
      App_Model_B.BCAN_RX_RheoStatLevel = (C_RheoStatLevel)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RheoStatLevel;

      /* DataTypeConversion: '<S840>/Data Type Conversion17' */
      rtb_BCAN_RX_C_CLU_DtntOutSta = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DtntOutSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion18' */
      App_Model_B.BCAN_RX_C_WPCOnOffNvalueSet = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCOnOffNvalueSet;

      /* DataTypeConversion: '<S840>/Data Type Conversion43' */
      App_Model_B.BCAN_RX_C_CF_Gway_WPCAnimationN = (WPCAnimationNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_Gway_WPCAnimationNvalueSet;

      /* DataTypeConversion: '<S840>/Data Type Conversion19' */
      App_Model_B.BCAN_RX_C_USMReset = (C_USMReset)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USMReset;

      /* DataTypeConversion: '<S840>/Data Type Conversion20' */
      App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal = (C_ProfileIDRValue)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_IAU_ProfileIDRVal;

      /* DataTypeConversion: '<S840>/Data Type Conversion21' */
      App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu = (C_ProfileIDRValue)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_AVN_ProfileIDRValue;

      /* DataTypeConversion: '<S840>/Data Type Conversion50' */
      rtb_BCAN_RX_C_Lamp_IntTailLmpOn = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Lamp_IntTailLmpOnReq;

      /* DataTypeConversion: '<S840>/Data Type Conversion39' */
      App_Model_B.BCAN_RX_C_AutoBrightLevel = (C_AutoBrightLevel)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_AutoBrightLevel;

      /* DataTypeConversion: '<S840>/Data Type Conversion10' */
      App_Model_B.BCAN_RX_C_BCM_SmkOptTyp = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_BCM_SmkOptTyp;

      /* DataTypeConversion: '<S840>/Data Type Conversion51' */
      rtb_BCAN_Latch_TypeOption_DRV = (LatchTypeOption)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Latch_TypeOption_DRV;

      /* DataTypeConversion: '<S840>/Data Type Conversion13' */
      rtb_BCAN_AstDrSw = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion12' */
      rtb_BCAN_DrvDrSw = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion14' */
      rtb_BCAN_RLDrSw = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion15' */
      rtb_BCAN_RRDrSw = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion35' */
      rtb_BCAN_AstDrSw_SBCM = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta_SBCM;

      /* DataTypeConversion: '<S840>/Data Type Conversion47' */
      rtb_BCAN_DrvDrSw_SBCM = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta_SBCM;

      /* DataTypeConversion: '<S840>/Data Type Conversion48' */
      rtb_BCAN_RLDrSw_SBCM = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta_SBCM;

      /* DataTypeConversion: '<S840>/Data Type Conversion49' */
      rtb_BCAN_RRDrSw_SBCM = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta_SBCM;

      /* Chart: '<S840>/DoorOpenCloseStateFunctionFlowGraph' */
      DoorOpenCloseStateFunctionFlowG(rtb_BCAN_Latch_TypeOption_DRV, rtb_BCAN_AstDrSw, rtb_BCAN_DrvDrSw, rtb_BCAN_RLDrSw, rtb_BCAN_RRDrSw, rtb_BCAN_AstDrSw_SBCM, rtb_BCAN_DrvDrSw_SBCM,
        rtb_BCAN_RLDrSw_SBCM, rtb_BCAN_RRDrSw_SBCM, &App_Model_B.b_AstDrSw, &App_Model_B.b_DrvDrSw, &App_Model_B.b_RLDrSw, &App_Model_B.b_RRDrSw, &App_Model_DW.sf_DoorOpenCloseStateFunct_gpcq);

      /* DataTypeConversion: '<S840>/Data Type Conversion6' */
      App_Model_B.BCAN_RX_C_WPC2IndSyncVal = (WPC2IndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2_IndSyncVal;

      /* DataTypeConversion: '<S840>/Data Type Conversion42' */
      App_Model_B.BCAN_RX_C_RWPCIndSyncVal = (RWPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RWPC_IndSyncVal;

      /* DataTypeConversion: '<S840>/Data Type Conversion7' */
      App_Model_B.BCAN_RX_C_GearPosSta = (GearPosSta)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_VCU_GearPosSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion8' */
      App_Model_B.BCAN_RX_C_FANSpeedSet = (FANSpeed)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USM_FANSpeedSet;

      /* DataTypeConversion: '<S840>/Data Type Conversion25' */
      App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcmd = (LC_IAUWPCNFCcmd)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC_IAUWPCNFCcmd;

      /* DataTypeConversion: '<S840>/Data Type Conversion37' */
      App_Model_B.LCAN_RX_LC_OwnerKey_Reg_Status = (IAU_OwnerPhnRegRVal)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerKey_Reg_Status;

      /* DataTypeConversion: '<S840>/Data Type Conversion44' */
      App_Model_B.LCAN_RX_LC_OwnerPairingAdvertis = (OwnerPairingAdvertisingReq)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerPairingAdvertisingReq;

      /* DataTypeConversion: '<S845>/Data Type Conversion34' */
      App_Model_B.NFC1_LC_WPC_NFCDetection = (LC_WPC_NFCDetection)rtb_TmpSignalConversionAtR_NFC_.Device[0].NFCDetection;

      /* DataTypeConversion: '<S845>/Data Type Conversion1' */
      App_Model_B.NFC1_NfcOnThePad = (OnThePad)rtb_TmpSignalConversionAtR_NFC_.Device[0].NfcOnThePad;

      /* DataTypeConversion: '<S845>/Data Type Conversion38' */
      App_Model_B.NFC1_LPCD_Wakeup = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[0].LPCD_Wakeup;

      /* DataTypeConversion: '<S845>/Data Type Conversion83' */
      rtb_NFC1_b_MultiCardDetectionSt = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[0].MultiCardDetectionState;

      /* DataTypeConversion: '<S847>/Data Type Conversion29' */
      App_Model_B.UART_WPC1_PhoneLeft = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].PhoneLeft;

      /* DataTypeConversion: '<S847>/Data Type Conversion36' */
      App_Model_B.UART_WPC1_DeviceState = (DeviceState)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].DeviceState;

      /* DataTypeConversion: '<S847>/Data Type Conversion31' */
      App_Model_B.UART_WPC1_ChargingCurrent = rtb_TmpSignalConversionAtR_UART.Device_WCT[0].ChargingCurrent;

      /* DataTypeConversion: '<S847>/Data Type Conversion5' */
      App_Model_B.UART_WPC1_CoilTempDegree = rtb_TmpSignalConversionAtR_UART.Device_WCT[0].CoilTempDegree;

      /* DataTypeConversion: '<S847>/Data Type Conversion6' */
      App_Model_B.UART_WPC1_Temp_SnsrError = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].TempSnsrError;

      /* DataTypeConversion: '<S849>/Data Type Conversion1' */
      App_Model_B.WCT1_ChargingOnthePad = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[0].ChargingOnthePad;

      /* DataTypeConversion: '<S849>/Data Type Conversion2' */
      App_Model_B.WCT1_ObjectOnthePad = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[0].ObjectOnthePad;

      /* DataTypeConversion: '<S843>/Data Type Conversion1' incorporates:
       *  UnitDelay: '<S844>/Unit Delay'
       */
      App_Model_B.INT_SWPCIndUSMState = App_Model_DW.UnitDelay_DSTATE;

      /* DataTypeConversion: '<S843>/Data Type Conversion9' incorporates:
       *  UnitDelay: '<S844>/Unit Delay4'
       */
      App_Model_B.INT_SWPCIndCmdState = App_Model_DW.UnitDelay4_DSTATE;

      /* DataTypeConversion: '<S843>/Data Type Conversion64' incorporates:
       *  UnitDelay: '<S844>/Unit Delay9'
       */
      App_Model_B.INT_b_CmdAmberSync_SWPC = App_Model_DW.UnitDelay9_DSTATE;

      /* DataTypeConversion: '<S843>/Data Type Conversion65' incorporates:
       *  UnitDelay: '<S844>/Unit Delay10'
       */
      App_Model_B.INT_b_SyncAmber_SWPC = App_Model_DW.UnitDelay10_DSTATE;

      /* DataTypeConversion: '<S843>/Data Type Conversion70' incorporates:
       *  UnitDelay: '<S844>/Unit Delay15'
       */
      App_Model_B.INT_SWPCWarning = App_Model_DW.UnitDelay15_DSTATE;

      /* DataTypeConversion: '<S843>/Data Type Conversion78' incorporates:
       *  UnitDelay: '<S844>/Unit Delay18'
       */
      App_Model_B.INT_SWPC_b_PhnLeftChk_Enable = App_Model_DW.UnitDelay18_DSTATE;

      /* Outputs for Atomic SubSystem: '<S635>/SWPC_TE_sys' */
      /* Outputs for Atomic SubSystem: '<S638>/USMSettingControl_Function' */
      USMSettingControl_Function_k3rq(rtb_Uds_m_NFCOption, App_Model_B.BCAN_RX_C_WPCOnOffNvalueSet, App_Model_B.BCAN_RX_C_USMReset, App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu,
        App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal, &App_Model_B.C_WPCRValue, &App_Model_B.WPCSWOption);

      /* End of Outputs for SubSystem: '<S638>/USMSettingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S640>/NFC_WPC_Mode_Control_Function' */
      NFC_WPC_Mode_Control_Funct_fw4e(rtb_Uds_m_NFCOption, App_Model_B.ADC_IGN1_IN, App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcmd, App_Model_B.NFC1_LC_WPC_NFCDetection, App_Model_B.NFC1_LPCD_Wakeup,
        App_Model_B.WPCSWOption, App_Model_B.LCAN_RX_LC_OwnerKey_Reg_Status, App_Model_B.LCAN_RX_LC_OwnerPairingAdvertis, App_Model_B.NFC1_NfcOnThePad, App_Model_B.WCT1_ChargingOnthePad,
        App_Model_B.b_DrvDrSw, App_Model_B.INT_SWPCWarning, App_Model_B.WCT1_ObjectOnthePad, App_Model_B.INT_SWPC_b_PhnLeftChk_Enable, App_Model_B.b_AstDrSw, rtb_ADC_BatSysStateFault,
        &App_Model_B.WPCStatus_es4i);

      /* End of Outputs for SubSystem: '<S640>/NFC_WPC_Mode_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S640>/TemperatureSensorErrorDetect_Function' */
      TemperatureSensorErrorDete_p4vb(App_Model_B.WPCStatus_es4i, App_Model_B.UART_WPC1_Temp_SnsrError, App_Model_ConstB.Dum_WPC_Temp_SnsrError, App_Model_ConstB.Dum_R_DIA_gb_DTCClearFlag,
        &App_Model_B.b_TempSensorFault, &App_Model_B.b_Timer_TempSensor_Check);

      /* End of Outputs for SubSystem: '<S640>/TemperatureSensorErrorDetect_Function' */

      /* Outputs for Atomic SubSystem: '<S640>/PreventionSMK_LF_Interference_Function' */
      PreventionSMK_LF_Interfere_movb(App_Model_B.WPCStatus_es4i, App_Model_B.BCAN_RX_C_BCM_SmkOptTyp, App_Model_B.BCAN_RX_C_LFAnt_SrchSta, App_Model_B.b_AstDrSw, App_Model_B.b_DrvDrSw,
        App_Model_B.b_RLDrSw, App_Model_B.b_RRDrSw, App_Model_ConstB.Dum_L_LFSearchingOn_IN, &App_Model_B.b_LFState);

      /* End of Outputs for SubSystem: '<S640>/PreventionSMK_LF_Interference_Function' */

      /* Outputs for Atomic SubSystem: '<S640>/OverCurrentDetecting_Function' */
      OverCurrentDetecting_Funct_obzl(App_Model_B.WPCStatus_es4i, App_Model_B.UART_WPC1_ChargingCurrent, &App_Model_B.b_CurrentFault, &App_Model_B.b_Timer_OvrCurr, &App_Model_B.b_Timer_ReOvrCurr);

      /* End of Outputs for SubSystem: '<S640>/OverCurrentDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S640>/OverTemperatureDetecting_Function' */
      OverTemperatureDetecting_F_moxt(App_Model_B.WPCStatus_es4i, App_Model_B.UART_WPC1_CoilTempDegree, App_Model_ConstB.Dum_CoilTempDegree2_Convert, App_Model_ConstB.Dum_CoilTempDegree3_Convert,
        App_Model_B.UART_WPC1_DeviceState, &App_Model_B.b_TemperatureFault, &App_Model_B.b_Timer_OverTemp);

      /* End of Outputs for SubSystem: '<S640>/OverTemperatureDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S640>/WPC_PhoneLeftDetectingControl_Function' */
      WPC_PhoneLeftDetectingCont_evze(App_Model_B.WPCStatus_es4i, rtb_NFC1_b_MultiCardDetectionSt, &App_Model_B.Output_PhoneLeftWarningWPCStatu);

      /* End of Outputs for SubSystem: '<S640>/WPC_PhoneLeftDetectingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S638>/WPC_MainControl_Function' */
      A_WPC_MainControl_Function_agcy(rtb_Uds_m_NFCOption, rtb_NvM_EVOpt, App_Model_B.b_LFState, App_Model_B.b_CurrentFault, App_Model_B.b_TempSensorFault, App_Model_B.WPCSWOption,
        App_Model_B.b_TemperatureFault, App_Model_B.b_AstDrSw, App_Model_B.b_DrvDrSw, App_Model_B.UART_WPC1_PhoneLeft, App_Model_B.UART_WPC1_DeviceState, App_Model_B.WPCStatus_es4i,
        App_Model_B.ADC_IGN1_IN, App_Model_B.INT_SWPCIndUSMState, App_Model_B.INT_b_CmdAmberSync_SWPC, App_Model_B.INT_SWPCIndCmdState, App_Model_B.BCAN_RX_C_GearPosSta,
        App_Model_B.Output_PhoneLeftWarningWPCStatu, &App_Model_B.C_WPCWarning_kjwv, &App_Model_B.b_FANModeCmd, &App_Model_B.b_GreenINDCmd, &App_Model_B.b_AmberINDCmd, &App_Model_B.b_BlinkState,
        &App_Model_B.b_Timer_PhoneReminderCheck, &App_Model_B.b_Timer_PhoneWarningCheck, &App_Model_B.b_Timer_WarningComplete, &App_Model_B.b_ChargingEnable, &App_Model_B.BlinkState_i5ti,
        &App_Model_B.b_PhnLeftChk_Enable, &App_Model_B.b_Timer_WarningTypeCheck);

      /* End of Outputs for SubSystem: '<S638>/WPC_MainControl_Function' */

      /* Outputs for Atomic SubSystem: '<S639>/FAN_Control_Function' */
      App_M_FAN_Control_Function_h0dg(App_Model_B.b_FANModeCmd, App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal, App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu, App_Model_B.BCAN_RX_C_FANSpeedSet,
        App_Model_B.BCAN_RX_C_USMReset, &rtb_FAN_PWM, &App_Model_B.FANDutyRatioSta);

      /* End of Outputs for SubSystem: '<S639>/FAN_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S639>/IND_Animation_Control_Function' */
      /* Outputs for Atomic SubSystem: '<S644>/SWPC_INDAnimationControl' */
      /* Chart: '<S652>/IND_Animation_WPC2_Priority_Flow_Graph' */
      IND_Animation_WPC2_Priority_Flo(App_Model_B.BCAN_RX_C_WPC2IndSyncVal, &App_Model_B.Var_WPC2PreSyncAct, &App_Model_DW.sf_IND_Animation_WPC2_Prio_msgq);

      /* Chart: '<S652>/IND_Animation_RWPC_Priority_Flow_Graph' */
      IND_Animation_RWPC_Priority_Flo(App_Model_B.BCAN_RX_C_RWPCIndSyncVal, &App_Model_B.Var_RWPCPreSyncAct, &App_Model_DW.sf_IND_Animation_RWPC_Prio_his4);

      /* Chart: '<S652>/IND_Animation_Priority_Flow_Graph' */
      IND_Animation_Priority_Flow_Gra(App_Model_B.Var_WPC2PreSyncAct, App_Model_B.Var_RWPCPreSyncAct, &App_Model_B.Var_PreSyncAct, &App_Model_DW.sf_IND_Animation_Priority__njws);

      /* Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' incorporates:
       *  DataTypeConversion: '<S840>/Data Type Conversion6'
       */
      App_Model_DW.sfEvent_et4h = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_prev = App_Model_DW.Input_CAN_WPC2IndSyncVal_start;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_start = App_Model_B.BCAN_RX_C_WPC2IndSyncVal;
      if ((uint32)App_Model_DW.is_active_c168_WPC_IND_Animatio == 0U) {
        App_Model_DW.Input_CAN_WPC2IndSyncVal_prev = App_Model_B.BCAN_RX_C_WPC2IndSyncVal;
        App_Model_DW.is_active_c168_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDPhaseState = 1U;
        App_Model_DW.is_INDPhaseState = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState = 0U;
        App_Model_DW.is_active_WPC2_IND_Command_Stat = 1U;

        /* 1 */
        App_Model_DW.is_WPC2_IND_Command_State_Contr = App__IN_WPC2INDCmdState_Default;
        App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
      } else {
        if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
          App_Model_INDPhaseState_oafg();
        }

        if ((uint32)App_Model_DW.is_active_WPC2_IND_Command_Stat != 0U) {
          switch (App_Model_DW.is_WPC2_IND_Command_State_Contr) {
           case App_IN_WPC2INDCmdState_Charging:
            A_WPC2INDCmdState_Charging_k4jq();
            break;

           case App__IN_WPC2INDCmdState_Default:
            App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;

            /* 1 */
            tmp_a = App_Model_DW.Input_CAN_WPC2IndSyncVal_start;
            tmp_b = App_Model_DW.Input_CAN_WPC2IndSyncVal_prev;
            if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__3rdSync)) {
              App_Model_DW.is_WPC2_IND_Command_State_Contr = App_IN_WPC2INDCmdState_Charging;
              App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_3rdSync;
              App_Model_DW.is_WPC2INDCmdState_3rdSync = Ap_IN_WPC2INDCmdState_3rdChrgOn;
              App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                App_Model_INDPhaseState_oafg();
              }

              App_Model_DW.sfEvent_et4h = -1;
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;

              /* 1 */
            } else if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOn)) {
              App_Model_DW.is_WPC2_IND_Command_State_Contr = App_Mo_IN_WPC2INDCmdState_Error;

              /* 1 */
              App_Model_DW.is_WPC2INDCmdState_Error = App__IN_WPC2INDCmdState_ErrorOn;
              App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                App_Model_INDPhaseState_oafg();
              }

              App_Model_DW.sfEvent_et4h = -1;
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
            } else {
              /* no actions */
            }
            break;

           case App_Mo_IN_WPC2INDCmdState_Error:
            /* 1 */
            tmp_a = App_Model_DW.Input_CAN_WPC2IndSyncVal_start;
            tmp_b = App_Model_DW.Input_CAN_WPC2IndSyncVal_prev;
            if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndCmdState__Default)) {
              exit_internal_WPC2INDCmdSt_arr1();
              App_Model_DW.is_WPC2_IND_Command_State_Contr = App__IN_WPC2INDCmdState_Default;
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;

              /* 2 230113 for ReCharge */
            } else if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__3rdSync)) {
              exit_internal_WPC2INDCmdSt_arr1();
              App_Model_DW.is_WPC2_IND_Command_State_Contr = App_IN_WPC2INDCmdState_Charging;
              App_Model_DW.is_WPC2INDCmdState_Charging = App__IN_WPC2INDCmdState_3rdSync;
              App_Model_DW.is_WPC2INDCmdState_3rdSync = Ap_IN_WPC2INDCmdState_3rdChrgOn;
              c_previousEvent = App_Model_DW.sfEvent_et4h;
              App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                App_Model_INDPhaseState_oafg();
              }

              App_Model_DW.sfEvent_et4h = c_previousEvent;
              App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
            } else {
              switch (App_Model_DW.is_WPC2INDCmdState_Error) {
               case App_IN_WPC2INDCmdState_ErrorOff:
                App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;

                /* 1. */
                if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOn)) {
                  App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                    App_Model_INDPhaseState_oafg();
                  }

                  App_Model_DW.is_WPC2INDCmdState_Error = App__IN_WPC2INDCmdState_ErrorOn;
                  App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                    App_Model_INDPhaseState_oafg();
                  }

                  App_Model_DW.sfEvent_et4h = -1;
                  App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
                }
                break;

               case App__IN_WPC2INDCmdState_ErrorOn:
                App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;

                /* 1. */
                if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOff)) {
                  App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                    App_Model_INDPhaseState_oafg();
                  }

                  App_Model_DW.is_WPC2INDCmdState_Error = App_IN_WPC2INDCmdState_ErrorOff;
                  App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                    App_Model_INDPhaseState_oafg();
                  }

                  App_Model_DW.sfEvent_et4h = -1;
                  App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;
                } else if (App_Model_DW.Timer_INDPhaseState >= (uint32)((uint8)100U)) {
                  App_Model_DW.sfEvent_et4h = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                    App_Model_INDPhaseState_oafg();
                  }

                  App_Model_DW.sfEvent_et4h = -1;
                  App_Model_DW.is_WPC2INDCmdState_Error = Ap_IN_WPC2INDCmdState_ErrorOn_2;
                  App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorOn;
                } else {
                  /* no actions */
                }
                break;

               case Ap_IN_WPC2INDCmdState_ErrorOn_2:
                App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorOn;
                if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOff)) {
                  App_Model_DW.is_WPC2INDCmdState_Error = App_IN_WPC2INDCmdState_ErrorOff;
                  App_Model_DW.sfEvent_et4h = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState != 0U) {
                    App_Model_INDPhaseState_oafg();
                  }

                  App_Model_DW.sfEvent_et4h = -1;
                  App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;
                }
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }

      /* End of Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' */

      /* Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' incorporates:
       *  DataTypeConversion: '<S840>/Data Type Conversion42'
       */
      App_Model_DW.sfEvent_gpvl = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_prev = App_Model_DW.Input_CAN_RWPCIndSyncVal_start;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_start = App_Model_B.BCAN_RX_C_RWPCIndSyncVal;
      if ((uint32)App_Model_DW.is_active_c167_WPC_IND_Animatio == 0U) {
        App_Model_DW.Input_CAN_RWPCIndSyncVal_prev = App_Model_B.BCAN_RX_C_RWPCIndSyncVal;
        App_Model_DW.is_active_c167_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDPhaseState_o34r = 1U;
        App_Model_DW.is_INDPhaseState_n5rr = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState_gnkj = 0U;
        App_Model_DW.is_active_RWPC_IND_Command_Stat = 1U;

        /* 1 */
        App_Model_DW.is_RWPC_IND_Command_State_Contr = IN_RWPCINDCmdState_Default_kpc4;
        App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
      } else {
        if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
          App_Model_INDPhaseState_mb0u();
        }

        if ((uint32)App_Model_DW.is_active_RWPC_IND_Command_Stat != 0U) {
          switch (App_Model_DW.is_RWPC_IND_Command_State_Contr) {
           case IN_RWPCINDCmdState_Chargin_lczw:
            A_RWPCINDCmdState_Charging_irrl();
            break;

           case IN_RWPCINDCmdState_Default_kpc4:
            App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;

            /* 1 */
            if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync)) {
              App_Model_DW.is_RWPC_IND_Command_State_Contr = IN_RWPCINDCmdState_Chargin_lczw;
              App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_3rdSync_mj1c;
              App_Model_DW.is_RWPCINDCmdState_3rdSync = IN_RWPCINDCmdState_3rdChrg_cla5;
              App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                App_Model_INDPhaseState_mb0u();
              }

              App_Model_DW.sfEvent_gpvl = -1;
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;

              /* 1 */
            } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn))
            {
              App_Model_DW.is_RWPC_IND_Command_State_Contr = A_IN_RWPCINDCmdState_Error_jh1y;

              /* 1 */
              App_Model_DW.is_RWPCINDCmdState_Error = IN_RWPCINDCmdState_ErrorOn_ajx4;
              App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                App_Model_INDPhaseState_mb0u();
              }

              App_Model_DW.sfEvent_gpvl = -1;
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
            } else {
              /* no actions */
            }
            break;

           case A_IN_RWPCINDCmdState_Error_jh1y:
            /* 1 */
            if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndCmdState__Default)) {
              exit_internal_RWPCINDCmdSt_jszz();
              App_Model_DW.is_RWPC_IND_Command_State_Contr = IN_RWPCINDCmdState_Default_kpc4;
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;

              /* 2 230113 for ReCharge */
            } else if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__3rdSync))
            {
              exit_internal_RWPCINDCmdSt_jszz();
              App_Model_DW.is_RWPC_IND_Command_State_Contr = IN_RWPCINDCmdState_Chargin_lczw;
              App_Model_DW.is_RWPCINDCmdState_Charging = IN_RWPCINDCmdState_3rdSync_mj1c;
              App_Model_DW.is_RWPCINDCmdState_3rdSync = IN_RWPCINDCmdState_3rdChrg_cla5;
              c_previousEvent = App_Model_DW.sfEvent_gpvl;
              App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                App_Model_INDPhaseState_mb0u();
              }

              App_Model_DW.sfEvent_gpvl = c_previousEvent;
              App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__3rdChrgOn;
            } else {
              switch (App_Model_DW.is_RWPCINDCmdState_Error) {
               case IN_RWPCINDCmdState_ErrorOf_fcr1:
                App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;

                /* 1. */
                if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOn)) {
                  App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                    App_Model_INDPhaseState_mb0u();
                  }

                  App_Model_DW.is_RWPCINDCmdState_Error = IN_RWPCINDCmdState_ErrorOn_ajx4;
                  App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                    App_Model_INDPhaseState_mb0u();
                  }

                  App_Model_DW.sfEvent_gpvl = -1;
                  App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
                }
                break;

               case IN_RWPCINDCmdState_ErrorOn_ajx4:
                App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;

                /* 1. */
                if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOff)) {
                  App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                    App_Model_INDPhaseState_mb0u();
                  }

                  App_Model_DW.is_RWPCINDCmdState_Error = IN_RWPCINDCmdState_ErrorOf_fcr1;
                  App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                    App_Model_INDPhaseState_mb0u();
                  }

                  App_Model_DW.sfEvent_gpvl = -1;
                  App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
                } else if (App_Model_DW.Timer_INDPhaseState_gnkj >= (uint32)((uint8)100U)) {
                  App_Model_DW.sfEvent_gpvl = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                    App_Model_INDPhaseState_mb0u();
                  }

                  App_Model_DW.sfEvent_gpvl = -1;
                  App_Model_DW.is_RWPCINDCmdState_Error = IN_RWPCINDCmdState_ErrorOn_gzpb;
                } else {
                  /* no actions */
                }
                break;

               case IN_RWPCINDCmdState_ErrorOn_gzpb:
                App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeIn;
                if ((App_Model_DW.Input_CAN_RWPCIndSyncVal_prev != App_Model_DW.Input_CAN_RWPCIndSyncVal_start) && ((uint32)App_Model_DW.Input_CAN_RWPCIndSyncVal_start == RWPCIndSyncVal__ErrorOff)) {
                  App_Model_DW.is_RWPCINDCmdState_Error = IN_RWPCINDCmdState_ErrorOf_fcr1;
                  App_Model_DW.sfEvent_gpvl = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_o34r != 0U) {
                    App_Model_INDPhaseState_mb0u();
                  }

                  App_Model_DW.sfEvent_gpvl = -1;
                  App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__ErrorFadeOut;
                }
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }

      /* End of Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' */

      /* Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
       *  DataTypeConversion: '<S840>/Data Type Conversion42'
       *  DataTypeConversion: '<S840>/Data Type Conversion6'
       *  DataTypeConversion: '<S843>/Data Type Conversion1'
       *  DataTypeConversion: '<S843>/Data Type Conversion65'
       */
      App_Model_DW.sfEvent_gygj = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Var_PreSyncAct_prev = App_Model_DW.Var_PreSyncAct_start;
      App_Model_DW.Var_PreSyncAct_start = App_Model_B.Var_PreSyncAct;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_p_eqk4 = App_Model_DW.Input_CAN_RWPCIndSyncVal_s_fuhd;
      App_Model_DW.Input_CAN_RWPCIndSyncVal_s_fuhd = App_Model_B.BCAN_RX_C_RWPCIndSyncVal;
      App_Model_DW.Var_INT_RWPCIndCmdState_prev = App_Model_DW.Var_INT_RWPCIndCmdState_start;
      App_Model_DW.Var_INT_RWPCIndCmdState_start = App_Model_B.Var_INT_RWPCIndCmdState;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_p_ofvk = App_Model_DW.Input_CAN_WPC2IndSyncVal_s_hoel;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_s_hoel = App_Model_B.BCAN_RX_C_WPC2IndSyncVal;
      App_Model_DW.Var_INT_WPC2IndCmdState_prev = App_Model_DW.Var_INT_WPC2IndCmdState_start;
      App_Model_DW.Var_INT_WPC2IndCmdState_start = App_Model_B.Var_INT_WPC2IndCmdState;
      App_Model_DW.WPCIndUSMState_prev = App_Model_DW.WPCIndUSMState_start;
      App_Model_DW.WPCIndUSMState_start = App_Model_B.INT_SWPCIndUSMState;
      App_Model_DW.b_SyncAmber_prev = App_Model_DW.b_SyncAmber_start;
      App_Model_DW.b_SyncAmber_start = App_Model_B.INT_b_SyncAmber_SWPC;
      if ((uint32)App_Model_DW.is_active_c165_WPC_IND_Animatio == 0U) {
        App_Model_DW.Var_PreSyncAct_prev = App_Model_B.Var_PreSyncAct;
        App_Model_DW.Input_CAN_RWPCIndSyncVal_p_eqk4 = App_Model_B.BCAN_RX_C_RWPCIndSyncVal;
        App_Model_DW.Var_INT_RWPCIndCmdState_prev = App_Model_B.Var_INT_RWPCIndCmdState;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_p_ofvk = App_Model_B.BCAN_RX_C_WPC2IndSyncVal;
        App_Model_DW.Var_INT_WPC2IndCmdState_prev = App_Model_B.Var_INT_WPC2IndCmdState;
        App_Model_DW.WPCIndUSMState_prev = App_Model_B.INT_SWPCIndUSMState;
        App_Model_DW.b_SyncAmber_prev = App_Model_B.INT_b_SyncAmber_SWPC;
        App_Model_DW.is_active_c165_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDLight = 1U;
        App_Model_DW.is_INDLight = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight = 0U;
        App_Model_DW.is_active_IND_Animation_Sync_Co = 1U;

        /* Default */
        App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mod_IN_WPCINDAnimation_Init;
        App_Model_DW.sfEvent_gygj = (sint32)App__event_CancelTimer_INDLight;
        App_Model_INDLight_lnkr();
        App_Model_DW.sfEvent_gygj = -1;
        App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
        App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
        App_Model_DW.is_active_INDFadeIn = 1U;
        App_Model_DW.is_INDFadeIn = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn = 0U;
        App_Model_DW.is_active_INDFadeOut = 1U;
        App_Model_DW.is_INDFadeOut = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut = 0U;
      } else {
        if ((uint32)App_Model_DW.is_active_INDLight != 0U) {
          App_Model_INDLight_lnkr();
        }

        if ((uint32)App_Model_DW.is_active_IND_Animation_Sync_Co != 0U) {
          IND_Animation_Sync_Control_hzm0();
        }

        if ((uint32)App_Model_DW.is_active_INDFadeIn != 0U) {
          App_Model_INDFadeIn_njia();
        }

        if ((uint32)App_Model_DW.is_active_INDFadeOut != 0U) {
          App_Model_INDFadeOut_ckyy();
        }
      }

      /* End of Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */

      /* Chart: '<S652>/Amber_Sync_Chart' */
      App_Model_DW.Output_INT_WPCIndCmdState_prev = App_Model_DW.Output_INT_WPCIndCmdState_start;
      App_Model_DW.Output_INT_WPCIndCmdState_start = App_Model_B.Output_INT_WPCIndCmdState;
      if ((uint32)App_Model_DW.is_active_c161_WPC_IND_Animatio == 0U) {
        App_Model_DW.Output_INT_WPCIndCmdState_prev = App_Model_B.Output_INT_WPCIndCmdState;
        App_Model_DW.is_active_c161_WPC_IND_Animatio = 1U;
        App_Model_DW.is_SyncTrigger = App_Mode_IN_SyncTriggerOff_ffg4;
        rtb_b_CmdAmberSync = Off;
      } else if ((uint32)App_Model_DW.is_SyncTrigger == App_Mode_IN_SyncTriggerOff_ffg4) {
        rtb_b_CmdAmberSync = Off;
        tmp_g = App_Model_DW.Output_INT_WPCIndCmdState_prev;
        tmp_h = App_Model_DW.Output_INT_WPCIndCmdState_start;
        if (((tmp_g != tmp_h) && ((uint32)tmp_g == WPCIndCmdState__ErrorOn)) || ((tmp_g != tmp_h) && ((uint32)tmp_g == WPCIndCmdState__ErrorFadeOut))) {
          App_Model_DW.is_SyncTrigger = App_Model_IN_SyncTriggerOn_bnd3;
          rtb_b_CmdAmberSync = On;
        }
      } else {
        /* case IN_SyncTriggerOn: */
        rtb_b_CmdAmberSync = On;
        tmp_g = App_Model_DW.Output_INT_WPCIndCmdState_start;
        tmp_h = App_Model_DW.Output_INT_WPCIndCmdState_prev;
        if (((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__ErrorOn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__ChrgFadeOut)) || ((tmp_h != tmp_g) && ((uint32)tmp_g ==
              WPCIndCmdState__3rdChrgOn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__3rdChrgFadeIn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__2ndChrgOn)) || ((tmp_h !=
              tmp_g) && ((uint32)tmp_g == WPCIndCmdState__2ndChrgFadeIn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__1stChrgOn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g ==
              WPCIndCmdState__1stChrgFadeIn)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__ChrgOff)) || ((tmp_h != tmp_g) && ((uint32)tmp_g == WPCIndCmdState__Default))) {
          App_Model_DW.is_SyncTrigger = App_Mode_IN_SyncTriggerOff_ffg4;
          rtb_b_CmdAmberSync = Off;
        }
      }

      /* End of Chart: '<S652>/Amber_Sync_Chart' */

      /* Chart: '<S652>/Amber_Sync_Indy' */
      App_Model_Amber_Sync_Indy(App_Model_B.b_BlinkState, rtb_b_CmdAmberSync, App_Model_B.BlinkState_i5ti, &rtb_b_SyncAmber, &App_Model_DW.sf_Amber_Sync_Indy_mh0e);

      /* End of Outputs for SubSystem: '<S644>/SWPC_INDAnimationControl' */

      /* Outputs for Atomic SubSystem: '<S644>/SWPC_INDAnimationUSMSettingControl_v_1_2' */
      /* Chart: '<S661>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
      IND_Animation_Profile_Decision_(App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal, App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu, &App_Model_B.CurProfile, &App_Model_DW.sf_IND_Animation_Profile_D_amxp);

      /* Chart: '<S661>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
      IND_Animation_USM_Setting_Contr(App_Model_B.NvM_IndUSMOption, App_Model_B.BCAN_RX_C_CF_Gway_WPCAnimationN, App_Model_B.BCAN_RX_C_USMReset, App_Model_B.CurProfile,
        &App_Model_B.Output_CAN_WPCIndUSMState, &Output_INT_WPCIndUSMState, &App_Model_DW.sf_IND_Animation_USM_Setti_mmqi);

      /* End of Outputs for SubSystem: '<S644>/SWPC_INDAnimationUSMSettingControl_v_1_2' */
      /* End of Outputs for SubSystem: '<S639>/IND_Animation_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S639>/IndyOutputControl_Function' */
      IndyOutputControl_Function_ds32(rtb_NvM_INDContType, App_Model_B.INT_SWPCIndUSMState, rtb_NvM_RheostatOption, rtb_BCAN_RX_C_Lamp_IntTailLmpOn, rtb_BCAN_RX_C_CLU_DtntOutSta,
        App_Model_B.BCAN_RX_RheoStatLevel, App_Model_B.b_GreenINDCmd, App_Model_B.b_AmberINDCmd, App_Model_B.INT_SWPCIndCmdState, App_Model_B.INT_b_SyncAmber_SWPC,
        App_Model_B.BCAN_RX_C_AutoBrightLevel, &App_Model_B.P_GreenIND_OUT, &App_Model_B.P_GreenIND2_OUT, &App_Model_B.P_GreenIND3_OUT, &App_Model_B.P_AmberIND_OUT);

      /* End of Outputs for SubSystem: '<S639>/IndyOutputControl_Function' */
      /* End of Outputs for SubSystem: '<S635>/SWPC_TE_sys' */

      /* DataTypeConversion: '<S840>/Data Type Conversion2' */
      rtb_BCAN_RX_C_CLU_ClusterUSM = (C_USMReset)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_ClusterUSM;

      /* DataTypeConversion: '<S840>/Data Type Conversion22' */
      rtb_BCAN_RX_C_CLU_DisSpdVal_KPH = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DisSpdVal_KPH;

      /* DataTypeConversion: '<S840>/Data Type Conversion23' */
      rtb_BCAN_RX_C_ENG_EngSta = (C_EngineState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_ENG_EngSta;

      /* DataTypeConversion: '<S840>/Data Type Conversion26' */
      rtb_LCAN_RX_LC_WPC2_IAUWPCNFCcm = (LC_IAUWPCNFCcmd)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC2_IAUWPCNFCcmd;

      /* DataTypeConversion: '<S840>/Data Type Conversion28' */
      rtb_LCAN_RX_LC_IAU_Status = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_IAU_Status;

      /* DataTypeConversion: '<S840>/Data Type Conversion3' */
      rtb_BCAN_RX_C_HCU_HevRdySta = (C_HEVEngOnState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_HCU_HevRdySta;

      /* DataTypeConversion: '<S840>/Data Type Conversion4' */
      rtb_BCAN_RX_C_WPC2OnOffNvalueSe = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2OnOffNvalueSet;

      /* DataTypeConversion: '<S840>/Data Type Conversion5' */
      rtb_BCAN_RX_C_WPCIndUSMState = (WPCIndUSMState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCIndUSMState;

      /* DataTypeConversion: '<S843>/Data Type Conversion63' incorporates:
       *  UnitDelay: '<S844>/Unit Delay3'
       */
      rtb_INT_SWPCStatus = App_Model_DW.UnitDelay3_DSTATE;

      /* DataTypeConversion: '<S845>/Data Type Conversion2' */
      rtb_NFC2_NfcOnThePad = (OnThePad)rtb_TmpSignalConversionAtR_NFC_.Device[1].NfcOnThePad;

      /* DataTypeConversion: '<S845>/Data Type Conversion75' */
      rtb_NFC2_LC_WPC_NFCDetection = (LC_WPC_NFCDetection)rtb_TmpSignalConversionAtR_NFC_.Device[1].NFCDetection;

      /* DataTypeConversion: '<S845>/Data Type Conversion76' */
      rtb_NFC2_LPCD_Wakeup = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[1].LPCD_Wakeup;

      /* DataTypeConversion: '<S845>/Data Type Conversion82' */
      rtb_NFC2_b_MultiCardDetectionSt = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[1].MultiCardDetectionState;

      /* DataTypeConversion: '<S846>/Data Type Conversion1' */
      rtb_NvM_WPCType = (WPCType)rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE;

      /* DataTypeConversion: '<S847>/Data Type Conversion47' */
      rtb_UART_WPC2_PhoneLeft = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].PhoneLeft;

      /* DataTypeConversion: '<S847>/Data Type Conversion48' */
      rtb_UART_WPC2_ChargingCurrent = rtb_TmpSignalConversionAtR_UART.Device_WCT[1].ChargingCurrent;

      /* DataTypeConversion: '<S847>/Data Type Conversion49' */
      rtb_UART_WPC2_DeviceState = (DeviceState)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].DeviceState;

      /* DataTypeConversion: '<S847>/Data Type Conversion51' */
      rtb_UART_WPC2_CoilTempDegree = rtb_TmpSignalConversionAtR_UART.Device_WCT[1].CoilTempDegree;

      /* DataTypeConversion: '<S847>/Data Type Conversion55' */
      rtb_UART_WPC2_Temp_SnsrError = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].TempSnsrError;

      /* DataTypeConversion: '<S848>/Data Type Conversion1' */
      rtb_Uds_LPConditionFlag = (Bool)rtb_TmpSignalConversionAtR_Uds_.Uds_LPConditionFlag;

      /* DataTypeConversion: '<S849>/Data Type Conversion3' */
      rtb_WCT2_ChargingOnthePad = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[1].ChargingOnthePad;

      /* DataTypeConversion: '<S849>/Data Type Conversion4' */
      rtb_WCT2_ObjectOnthePad = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[1].ObjectOnthePad;

      /* Chart: '<S852>/WPC_Mode_LPConditionJdg' */
      App_Mod_WPC_Mode_LPConditionJdg(App_Model_B.WPCStatus_es4i, &rtb_WPCMode_LPConditionFlag_wri, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_p0on);

      /* Chart: '<S852>/NFC_Mode_LPConditionJdg' */
      App_Mod_NFC_Mode_LPConditionJdg(App_Model_B.WPCStatus_es4i, &rtb_NFCMode_LPConditionFlag_wri, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_gkrq);

      /* Chart: '<S852>/MainControl_LPConditionJdg' */
      App__MainControl_LPConditionJdg(App_Model_B.WPCStatus_es4i, App_Model_B.b_Timer_PhoneReminderCheck, App_Model_B.b_Timer_PhoneWarningCheck, App_Model_B.b_Timer_WarningComplete,
        App_Model_B.b_Timer_WarningTypeCheck, App_Model_B.b_PhnLeftChk_Enable, &rtb_WPCMain_LPConditionFlag_wri, &App_Model_DW.sf_MainControl_LPCondition_gatm);

      /* Chart: '<S852>/SMKLF_LPConditionJdg' */
      App_Model_SMKLF_LPConditionJdg(App_Model_B.b_LFState, &rtb_SMKLF_LPConditionFlag_write, &App_Model_DW.sf_SMKLF_LPConditionJdg_j4fk);

      /* Chart: '<S852>/TempSnsrErrDetect_LPConditionJdg' */
      TempSnsrErrDetect_LPConditionJd(App_Model_B.b_TempSensorFault, App_Model_B.b_Timer_TempSensor_Check, &rtb_TempSnsrError_LPConditionFl, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_ftjz);

      /* Chart: '<S852>/OverTempDetect_LPConditionJdg' */
      A_OverTempDetect_LPConditionJdg(App_Model_B.b_TemperatureFault, App_Model_B.b_Timer_OverTemp, &rtb_OverTempDetect_LPConditionF, &App_Model_DW.sf_OverTempDetect_LPCondit_al4m);

      /* Chart: '<S852>/OverCurrent_LPConditionJdg' */
      App__OverCurrent_LPConditionJdg(App_Model_B.b_CurrentFault, App_Model_B.b_Timer_OvrCurr, App_Model_B.b_Timer_ReOvrCurr, &rtb_OverCurrent_LPConditionFlag,
        &App_Model_DW.sf_OverCurrent_LPCondition_alin);

      /* Chart: '<S852>/FAN_LPConditionJdg' */
      App_Model_FAN_LPConditionJdg(rtb_FAN_PWM, &rtb_FAN_LPConditionFlag_write, &App_Model_DW.sf_FAN_LPConditionJdg_jyac);

      /* Chart: '<S852>/USM_WPC_LPConditionJdg' incorporates:
       *  Constant: '<S852>/Constant'
       *  DataStoreRead: '<S852>/Data Store Read'
       *  DataStoreRead: '<S852>/Data Store Read1'
       *  DataStoreRead: '<S852>/Data Store Read2'
       *  DataStoreRead: '<S852>/Data Store Read4'
       */
      App_Mode_USM_WPC_LPConditionJdg(m_ProfileGuestWPCUSM_App, m_ProfileOneWPCUSM_App, m_ProfileTwoWPCUSM_App, 0.0, m_ProfileThreeWPCUSM_App, &App_Model_B.P_WPC_USM_LPConditionFlag_write,
        &App_Model_DW.sf_USM_WPC_LPConditionJdg_n0v1);

      /* BusCreator: '<S637>/Bus Creator' incorporates:
       *  Concatenate: '<S15>/Vector Concatenate'
       *  DataStoreRead: '<S852>/Data Store Read'
       *  DataStoreRead: '<S852>/Data Store Read1'
       *  DataStoreRead: '<S852>/Data Store Read2'
       *  DataStoreRead: '<S852>/Data Store Read4'
       *  DataStoreRead: '<S852>/Data Store Read5'
       *  DataStoreRead: '<S852>/Data Store Read6'
       *  DataStoreRead: '<S852>/Data Store Read7'
       *  DataStoreRead: '<S852>/Data Store Read8'
       *  DataTypeConversion: '<S852>/Data Type Conversion'
       *  DataTypeConversion: '<S852>/Data Type Conversion1'
       *  DataTypeConversion: '<S852>/Data Type Conversion10'
       *  DataTypeConversion: '<S852>/Data Type Conversion11'
       *  DataTypeConversion: '<S852>/Data Type Conversion12'
       *  DataTypeConversion: '<S852>/Data Type Conversion13'
       *  DataTypeConversion: '<S852>/Data Type Conversion14'
       *  DataTypeConversion: '<S852>/Data Type Conversion15'
       *  DataTypeConversion: '<S852>/Data Type Conversion16'
       *  DataTypeConversion: '<S852>/Data Type Conversion18'
       *  DataTypeConversion: '<S852>/Data Type Conversion19'
       *  DataTypeConversion: '<S852>/Data Type Conversion2'
       *  DataTypeConversion: '<S852>/Data Type Conversion20'
       *  DataTypeConversion: '<S852>/Data Type Conversion21'
       *  DataTypeConversion: '<S852>/Data Type Conversion23'
       *  DataTypeConversion: '<S852>/Data Type Conversion24'
       *  DataTypeConversion: '<S852>/Data Type Conversion25'
       *  DataTypeConversion: '<S852>/Data Type Conversion26'
       *  DataTypeConversion: '<S852>/Data Type Conversion27'
       *  DataTypeConversion: '<S852>/Data Type Conversion29'
       *  DataTypeConversion: '<S852>/Data Type Conversion3'
       *  DataTypeConversion: '<S852>/Data Type Conversion4'
       *  DataTypeConversion: '<S852>/Data Type Conversion5'
       *  DataTypeConversion: '<S852>/Data Type Conversion6'
       *  DataTypeConversion: '<S852>/Data Type Conversion7'
       *  DataTypeConversion: '<S852>/Data Type Conversion8'
       *  DataTypeConversion: '<S852>/Data Type Conversion9'
       *  Merge generated from: '<S641>/Merge'
       *  Merge generated from: '<S642>/Merge'
       *  Merge: '<S811>/Merge'
       */
      App_Model_B.Device[0].WPCWarning = (uint8)App_Model_B.C_WPCWarning_kjwv;
      App_Model_B.Device[0].WPCRValue = (uint8)App_Model_B.C_WPCRValue;
      App_Model_B.Device[0].PhoneWarningCheck_Timer = App_Model_B.b_Timer_PhoneWarningCheck;
      App_Model_B.Device[0].WPCStatus = (uint8)App_Model_B.WPCStatus_es4i;
      App_Model_B.Device[0].FAN_PWM = rtb_FAN_PWM;
      App_Model_B.Device[0].FANDutyRatioSta = (uint8)App_Model_B.FANDutyRatioSta;
      App_Model_B.Device[0].ChargingEnable = (uint8)App_Model_B.b_ChargingEnable;
      App_Model_B.Device[0].TempSensorFault = (uint8)App_Model_B.b_TempSensorFault;
      App_Model_B.Device[0].BlinkState = (uint8)App_Model_B.b_BlinkState;
      App_Model_B.Device[0].LFState = (uint8)App_Model_B.b_LFState;
      App_Model_B.Device[0].AmberIND_OUT = App_Model_B.P_AmberIND_OUT;
      App_Model_B.Device[0].GreenIND1_OUT = App_Model_B.P_GreenIND_OUT;
      App_Model_B.Device[0].GreenIND2_OUT = App_Model_B.P_GreenIND2_OUT;
      App_Model_B.Device[0].GreenIND3_OUT = App_Model_B.P_GreenIND3_OUT;
      App_Model_B.Device[0].PhnLeftChk_Enable = (uint8)App_Model_B.b_PhnLeftChk_Enable;
      App_Model_B.Device[0].WPCMode_LPConditionFlag = rtb_WPCMode_LPConditionFlag_wri;
      App_Model_B.Device[0].NFCMode_LPConditionFlag = rtb_NFCMode_LPConditionFlag_wri;
      App_Model_B.Device[0].WPCMain_LPConditionFlag = rtb_WPCMain_LPConditionFlag_wri;
      App_Model_B.Device[0].SMKLF_LPConditionFlag = rtb_SMKLF_LPConditionFlag_write;
      App_Model_B.Device[0].TempSnsrError_LPConditionFlag = rtb_TempSnsrError_LPConditionFl;
      App_Model_B.Device[0].OverTempDetect_LPConditionFlag = rtb_OverTempDetect_LPConditionF;
      App_Model_B.Device[0].OverCurrent_LPConditionFlag = rtb_OverCurrent_LPConditionFlag;
      App_Model_B.Device[0].FAN_LPConditionFlag = rtb_FAN_LPConditionFlag_write;
      App_Model_B.Device[0].TemperatureFault = (uint8)App_Model_B.b_TemperatureFault;
      App_Model_B.Device[0].CurrentFault = (uint8)App_Model_B.b_CurrentFault;
      App_Model_B.Device[0].m_ProfileGuestWPCUSM = (uint8)m_ProfileGuestWPCUSM_App;
      App_Model_B.Device[0].m_ProfileOneWPCUSM = (uint8)m_ProfileOneWPCUSM_App;
      App_Model_B.Device[0].m_ProfileTwoWPCUSM = (uint8)m_ProfileTwoWPCUSM_App;
      App_Model_B.Device[0].m_ProfileThreeWPCUSM = (uint8)m_ProfileThreeWPCUSM_App;
      App_Model_B.Device[0].m_RWPCUSM = App_Model_ConstB.m_RWPCUSM_ikq2;
      App_Model_B.Device[0].USM_LPConditionFlag = App_Model_B.P_WPC_USM_LPConditionFlag_write;
      App_Model_B.Device[0].WPCIndUSMState = (uint8)App_Model_B.Output_CAN_WPCIndUSMState;
      App_Model_B.Device[0].WPCIndSyncVal = (uint8)App_Model_B.Output_CAN_WPCIndSyncVal;
      App_Model_B.Device[0].RWPCIndSyncVal = App_Model_ConstB.RWPCIndSyncVal_garo;
      App_Model_B.Device[0].m_ProfileGuestFanUSM = (uint8)m_ProfileGuestWPCFanUSM_App;
      App_Model_B.Device[0].m_ProfileOneFanUSM = (uint8)m_ProfileOneWPCFanUSM_App;
      App_Model_B.Device[0].m_ProfileTwoFanUSM = (uint8)m_ProfileTwoWPCFanUSM_App;
      App_Model_B.Device[0].m_ProfileThreeFanUSM = (uint8)m_ProfileThreeWPCFanUSM_App;
      App_Model_B.Device[0].m_RWPCFanUSM = App_Model_ConstB.m_RWPCFanUSM_b2hu;

      /* BusCreator: '<S637>/Bus Creator3' incorporates:
       *  Concatenate: '<S15>/Vector Concatenate'
       */
      App_Model_B.Device[1].WPCWarning = App_Model_ConstB.WPCWarning;
      App_Model_B.Device[1].WPCRValue = App_Model_ConstB.WPCRValue;
      App_Model_B.Device[1].PhoneWarningCheck_Timer = App_Model_ConstB.PhoneWarningCheck_Timer;
      App_Model_B.Device[1].WPCStatus = App_Model_ConstB.WPCStatus_kue5;
      App_Model_B.Device[1].FAN_PWM = App_Model_ConstB.FAN_PWM;
      App_Model_B.Device[1].FANDutyRatioSta = App_Model_ConstB.FANDutyRatioSta;
      App_Model_B.Device[1].ChargingEnable = App_Model_ConstB.ChargingEnable;
      App_Model_B.Device[1].TempSensorFault = App_Model_ConstB.TempSensorFault;
      App_Model_B.Device[1].BlinkState = App_Model_ConstB.BlinkState_bjtw;
      App_Model_B.Device[1].LFState = App_Model_ConstB.LFState;
      App_Model_B.Device[1].AmberIND_OUT = App_Model_ConstB.AmberIND_OUT;
      App_Model_B.Device[1].GreenIND1_OUT = App_Model_ConstB.GreenIND1_OUT;
      App_Model_B.Device[1].GreenIND2_OUT = App_Model_ConstB.GreenIND2_OUT;
      App_Model_B.Device[1].GreenIND3_OUT = App_Model_ConstB.GreenIND3_OUT;
      App_Model_B.Device[1].PhnLeftChk_Enable = App_Model_ConstB.PhnLeftChk_Enable;
      App_Model_B.Device[1].WPCMode_LPConditionFlag = App_Model_ConstB.WPCMode_LPConditionFlag;
      App_Model_B.Device[1].NFCMode_LPConditionFlag = App_Model_ConstB.NFCMode_LPConditionFlag;
      App_Model_B.Device[1].WPCMain_LPConditionFlag = App_Model_ConstB.WPCMain_LPConditionFlag;
      App_Model_B.Device[1].SMKLF_LPConditionFlag = App_Model_ConstB.SMKLF_LPConditionFlag;
      App_Model_B.Device[1].TempSnsrError_LPConditionFlag = App_Model_ConstB.TempSnsrError_LPConditionFl;
      App_Model_B.Device[1].OverTempDetect_LPConditionFlag = App_Model_ConstB.OverTempDetect_LPConditionF;
      App_Model_B.Device[1].OverCurrent_LPConditionFlag = App_Model_ConstB.OverCurrent_LPConditionFlag;
      App_Model_B.Device[1].FAN_LPConditionFlag = App_Model_ConstB.FAN_LPConditionFlag;
      App_Model_B.Device[1].TemperatureFault = App_Model_ConstB.TemperatureFault;
      App_Model_B.Device[1].CurrentFault = App_Model_ConstB.CurrentFault;
      App_Model_B.Device[1].m_ProfileGuestWPCUSM = App_Model_ConstB.m_ProfileGuestWPCUSM;
      App_Model_B.Device[1].m_ProfileOneWPCUSM = App_Model_ConstB.m_ProfileOneWPCUSM;
      App_Model_B.Device[1].m_ProfileTwoWPCUSM = App_Model_ConstB.m_ProfileTwoWPCUSM;
      App_Model_B.Device[1].m_ProfileThreeWPCUSM = App_Model_ConstB.m_ProfileThreeWPCUSM;
      App_Model_B.Device[1].m_RWPCUSM = App_Model_ConstB.m_RWPCUSM;
      App_Model_B.Device[1].USM_LPConditionFlag = App_Model_ConstB.USM_LPConditionFlag;
      App_Model_B.Device[1].WPCIndUSMState = App_Model_ConstB.WPCIndUSMState_cat4;
      App_Model_B.Device[1].WPCIndSyncVal = App_Model_ConstB.WPCIndSyncVal;
      App_Model_B.Device[1].RWPCIndSyncVal = App_Model_ConstB.RWPCIndSyncVal_n2m4;
      App_Model_B.Device[1].m_ProfileGuestFanUSM = App_Model_ConstB.m_ProfileGuestFanUSM;
      App_Model_B.Device[1].m_ProfileOneFanUSM = App_Model_ConstB.m_ProfileOneFanUSM;
      App_Model_B.Device[1].m_ProfileTwoFanUSM = App_Model_ConstB.m_ProfileTwoFanUSM;
      App_Model_B.Device[1].m_ProfileThreeFanUSM = App_Model_ConstB.m_ProfileThreeFanUSM;
      App_Model_B.Device[1].m_RWPCFanUSM = App_Model_ConstB.m_RWPCFanUSM;

      /* DataStoreRead: '<S851>/Data Store Read2' */
      rtb_DataStoreRead2 = m_ProfileOneWPC2FanUSM_App;

      /* DataStoreRead: '<S851>/Data Store Read3' */
      rtb_DataStoreRead3 = m_RWPCUSM_App;

      /* DataStoreRead: '<S851>/Data Store Read4' */
      rtb_DataStoreRead4 = m_ProfileTwoWPC2FanUSM_App;

      /* DataStoreRead: '<S851>/Data Store Read5' */
      rtb_DataStoreRead5_f43h = m_ProfileGuestWPC2FanUSM_App;

      /* DataStoreRead: '<S851>/Data Store Read6' */
      rtb_DataStoreRead6_dtsz = m_ProfileGuestWPC2USM_App;

      /* DataStoreRead: '<S851>/Data Store Read7' */
      rtb_DataStoreRead7_esnu = m_ProfileOneWPC2USM_App;

      /* DataStoreRead: '<S851>/Data Store Read8' */
      rtb_DataStoreRead8_cqkz = m_ProfileTwoWPC2USM_App;

      /* DataStoreRead: '<S851>/Data Store Read9' */
      rtb_DataStoreRead9 = m_ProfileThreeWPC2FanUSM_App;

      /* Update for UnitDelay: '<S844>/Unit Delay' */
      App_Model_DW.UnitDelay_DSTATE = App_Model_B.Output_CAN_WPCIndUSMState;

      /* Update for UnitDelay: '<S844>/Unit Delay4' */
      App_Model_DW.UnitDelay4_DSTATE = App_Model_B.Output_INT_WPCIndCmdState;

      /* Update for UnitDelay: '<S844>/Unit Delay9' */
      App_Model_DW.UnitDelay9_DSTATE = rtb_b_CmdAmberSync;

      /* Update for UnitDelay: '<S844>/Unit Delay10' */
      App_Model_DW.UnitDelay10_DSTATE = rtb_b_SyncAmber;

      /* Update for UnitDelay: '<S844>/Unit Delay15' incorporates:
       *  Merge generated from: '<S642>/Merge'
       */
      App_Model_DW.UnitDelay15_DSTATE = App_Model_B.C_WPCWarning_kjwv;

      /* Update for UnitDelay: '<S844>/Unit Delay18' incorporates:
       *  Merge generated from: '<S642>/Merge'
       */
      App_Model_DW.UnitDelay18_DSTATE = App_Model_B.b_PhnLeftChk_Enable;

      /* Update for UnitDelay: '<S844>/Unit Delay3' incorporates:
       *  Merge: '<S811>/Merge'
       */
      App_Model_DW.UnitDelay3_DSTATE = App_Model_B.WPCStatus_es4i;
    } else if (App_Model_DW.SingleWPC_MODE) {
      /* Disable for Atomic SubSystem: '<S635>/SWPC_TE_sys' */
      /* Disable for Atomic SubSystem: '<S639>/IndyOutputControl_Function' */
      IndyOutputControl__i523_Disable();

      /* End of Disable for SubSystem: '<S639>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S635>/SWPC_TE_sys' */
      App_Model_DW.SingleWPC_MODE = false;
    } else {
      /* no actions */
    }

    /* End of RelationalOperator: '<S10>/Compare' */
    /* End of Outputs for SubSystem: '<S3>/SingleWPC' */

    /* Outputs for Enabled SubSystem: '<S3>/RWPC' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    /* RelationalOperator: '<S11>/Compare' incorporates:
     *  Constant: '<S11>/Constant'
     *  DataTypeConversion: '<S3>/Data Type Conversion2'
     */
    if (rtb_TmpSignalConversionAtR_NvM_.WPC_NAME == (uint8)RWPC) {
      if (!App_Model_DW.RWPC_MODE) {
        /* InitializeConditions for UnitDelay: '<S617>/Unit Delay5' */
        App_Model_DW.UnitDelay5_DSTATE_dr5b = RWPCIndCmdState__Default;

        /* InitializeConditions for UnitDelay: '<S617>/Unit Delay11' */
        App_Model_DW.UnitDelay11_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S617>/Unit Delay12' */
        App_Model_DW.UnitDelay12_DSTATE = Off;

        /* InitializeConditions for UnitDelay: '<S617>/Unit Delay16' */
        App_Model_DW.UnitDelay16_DSTATE = WPCWarningOff;

        /* InitializeConditions for UnitDelay: '<S617>/Unit Delay7' */
        App_Model_DW.UnitDelay7_DSTATE = ModeOff;

        /* InitializeConditions for UnitDelay: '<S617>/Unit Delay19' */
        App_Model_DW.UnitDelay19_DSTATE = Off;

        /* SystemReset for Chart: '<S613>/DoorOpenCloseStateFunctionFlowGraph' */
        DoorOpenCloseStateFunctio_Reset(&App_Model_B.b_AstDrSw_jy3e, &App_Model_B.b_DrvDrSw_kh5i, &App_Model_B.b_RLDrSw_jnn1, &App_Model_B.b_RRDrSw_bczk, &App_Model_DW.sf_DoorOpenCloseStateFunct_mocq);

        /* SystemReset for Atomic SubSystem: '<S458>/RWPC_TE_sys' */
        /* SystemReset for Atomic SubSystem: '<S461>/USMSettingControl_Function' */
        USMSettingControl_Fu_p40r_Reset(&App_Model_B.RWPCSWOption, &App_Model_B.C_RWPCRValue);

        /* End of SystemReset for SubSystem: '<S461>/USMSettingControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S463>/TemperatureSensorErrorDetect_Function' */
        TemperatureSensorErr_ehys_Reset(&App_Model_B.b_TempSensorFault_h5jx, &App_Model_B.b_Timer_TempSensor_Check_hxeq);

        /* End of SystemReset for SubSystem: '<S463>/TemperatureSensorErrorDetect_Function' */

        /* SystemReset for Atomic SubSystem: '<S463>/PreventionSMK_LF_Interference_Function' */
        PreventionSMK_LF_Int_mhh2_Reset(&App_Model_B.b_LFState_o4ks);

        /* End of SystemReset for SubSystem: '<S463>/PreventionSMK_LF_Interference_Function' */

        /* SystemReset for Atomic SubSystem: '<S463>/OverCurrentDetecting_Function' */
        OverCurrentDetecting_lpsa_Reset(&App_Model_B.b_CurrentFault_p1jy, &App_Model_B.b_Timer_OvrCurr_bfb2, &App_Model_B.b_Timer_ReOvrCurr_c3aw);

        /* End of SystemReset for SubSystem: '<S463>/OverCurrentDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S463>/OverTemperatureDetecting_Function' */
        OverTemperatureDetec_a4ia_Reset(&App_Model_B.b_TemperatureFault_iak5, &App_Model_B.b_Timer_OverTemp_ffe1);

        /* End of SystemReset for SubSystem: '<S463>/OverTemperatureDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S462>/FAN_Control_Function' */
        FAN_Control_Function_h0nw_Reset(&rtb_FAN_PWM_eua1, &App_Model_B.FANDutyRatioSta_htud);

        /* End of SystemReset for SubSystem: '<S462>/FAN_Control_Function' */

        /* SystemReset for Atomic SubSystem: '<S462>/IND_Animation_Control_Function' */
        /* SystemReset for Atomic SubSystem: '<S467>/RWPC_INDAnimationControl' */
        /* SystemReset for Chart: '<S474>/IND_Animation_WPC_Priority_Flow_Graph' */
        App_Model_DW.is_active_c178_WPC_IND_Animatio = 0U;
        App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;
        App_Model_DW.Input_CAN_WPCIndSyncVal_st_cekz = WPCIndSyncVal__Default;

        /* SystemReset for Chart: '<S474>/IND_Animation_WPC2_Priority_Flow_Graph' */
        IND_Animation_WPC2_Priori_Reset(&App_Model_B.Var_WPC2PreSyncAct_ocx1, &App_Model_DW.sf_IND_Animation_WPC2_Prio_c04w);

        /* SystemReset for Chart: '<S474>/IND_Animation_Priority_Flow_Graph' */
        App_Model_DW.is_active_c175_WPC_IND_Animatio = 0U;
        App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__Off;

        /* SystemReset for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' incorporates:
         *  Chart: '<S474>/IND_Animation_WPC_Priority_Flow_Graph'
         */
        App_Model_DW.is_active_INDPhaseState_na13 = 0U;
        App_Model_DW.is_INDPhaseState_p4z4 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_WPC_IND_Command_State = 0U;
        App_Model_DW.is_WPC_IND_Command_State_Contro = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPCIndCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c180_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDPhaseState_holq = 0U;
        App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;
        App_Model_DW.Input_CAN_WPCIndSyncVal_start = WPCIndSyncVal__Default;

        /* SystemReset for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */
        App_Model_DW.is_active_INDPhaseState_eoo3 = 0U;
        App_Model_DW.is_INDPhaseState_k14z = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_WPC2_IND_Command_c4py = 0U;
        App_Model_DW.is_WPC2_IND_Command_State__krzh = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c179_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDPhaseState_h1ak = 0U;
        App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi = WPC2IndSyncVal__Default;

        /* SystemReset for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
         *  Chart: '<S474>/IND_Animation_Priority_Flow_Graph'
         *  Chart: '<S474>/IND_Animation_WPC_Priority_Flow_Graph'
         *  Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart'
         *  Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart'
         */
        App_Model_DW.is_active_INDFadeIn_afmn = 0U;
        App_Model_DW.is_INDFadeIn_n305 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDFadeOut_cklz = 0U;
        App_Model_DW.is_INDFadeOut_ps5o = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_INDLight_h5bd = 0U;
        App_Model_DW.is_INDLight_kqsl = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_IND_Animation_Sy_n4yx = 0U;
        App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDAnimationCharging_3rd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_RWPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c176_WPC_IND_Animatio = 0U;
        App_Model_DW.Timer_INDLight_ewv0 = 0U;
        App_Model_DW.Timer_INDFadeIn_g1fs = 0U;
        App_Model_DW.Timer_INDFadeOut_ey0j = 0U;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
        App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
        App_Model_DW.Var_PreSyncAct_start_ntz3 = PreSyncAct__Off;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_s_mifz = WPC2IndSyncVal__Default;
        App_Model_DW.Var_WPC2IndCmdState_start = WPC2IndCmdState__Default;
        App_Model_DW.Input_CAN_WPCIndSyncVal_st_iach = WPCIndSyncVal__Default;
        App_Model_DW.Var_WPCIndCmdState_start = WPCIndCmdState__Default;
        App_Model_DW.WPCIndUSMState_start_dh2i = WPCIndUSMState__Default;
        App_Model_DW.b_SyncAmber_start_hkgy = Off;

        /* SystemReset for Chart: '<S474>/Amber_Sync_Chart' incorporates:
         *  Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
         */
        App_Model_DW.is_SyncTrigger_owzu = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c171_WPC_IND_Animatio = 0U;
        rtb_b_CmdAmberSync_pbbn = Off;
        App_Model_DW.Output_INT_RWPCIndCmdState_star = RWPCIndCmdState__Default;

        /* SystemReset for Chart: '<S474>/Amber_Sync_Indy' */
        App_Model_Amber_Sync_Indy_Reset(&rtb_b_SyncAmber_jg2q, &App_Model_DW.sf_Amber_Sync_Indy);

        /* End of SystemReset for SubSystem: '<S467>/RWPC_INDAnimationControl' */
        /* End of SystemReset for SubSystem: '<S462>/IND_Animation_Control_Function' */

        /* SystemReset for Atomic SubSystem: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
        WPC_PhoneLeftDetecti_grzc_Reset();

        /* End of SystemReset for SubSystem: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
        /* End of SystemReset for SubSystem: '<S458>/RWPC_TE_sys' */

        /* SystemReset for Chart: '<S625>/WPC_Mode_LPConditionJdg' */
        A_WPC_Mode_LPConditionJdg_Reset(&rtb_WPCMode_LPConditionFla_hka2, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_jccj);

        /* SystemReset for Chart: '<S625>/NFC_Mode_LPConditionJdg' */
        A_NFC_Mode_LPConditionJdg_Reset(&rtb_NFCMode_LPConditionFla_ogfp, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_hmwu);

        /* SystemReset for Chart: '<S625>/MainControl_LPConditionJdg' */
        MainControl_LPConditionJd_Reset(&rtb_WPCMain_LPConditionFla_nrse, &App_Model_DW.sf_MainControl_LPCondition_aehg);

        /* SystemReset for Chart: '<S625>/SMKLF_LPConditionJdg' */
        App__SMKLF_LPConditionJdg_Reset(&rtb_SMKLF_LPConditionFlag__j4w3, &App_Model_DW.sf_SMKLF_LPConditionJdg_jne5);

        /* SystemReset for Chart: '<S625>/TempSnsrErrDetect_LPConditionJdg' */
        TempSnsrErrDetect_LPCondi_Reset(&rtb_TempSnsrError_LPCondit_oh14, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_flnb);

        /* SystemReset for Chart: '<S625>/OverTempDetect_LPConditionJdg' */
        OverTempDetect_LPConditio_Reset(&rtb_OverTempDetect_LPCondi_a4lc, &App_Model_DW.sf_OverTempDetect_LPCondit_hgqy);

        /* SystemReset for Chart: '<S625>/OverCurrent_LPConditionJdg' */
        OverCurrent_LPConditionJd_Reset(&rtb_OverCurrent_LPConditio_hfnx, &App_Model_DW.sf_OverCurrent_LPCondition_hwn5);

        /* SystemReset for Chart: '<S625>/FAN_LPConditionJdg' */
        App_Mo_FAN_LPConditionJdg_Reset(&rtb_FAN_LPConditionFlag_wr_okst, &App_Model_DW.sf_FAN_LPConditionJdg_ioqj);

        /* SystemReset for Chart: '<S625>/USM_WPC_LPConditionJdg' */
        App_Model_DW.is_active_LPConditionChk_Chart = 0U;
        App_Model_DW.is_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_LPConditionHold = 0U;
        App_Model_DW.is_LPConditionHold = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
        App_Model_DW.is_active_c50_sH3eOQeO4p6NHsKQC = 0U;
        App_Model_DW.ECUResetEnable = 0U;
        App_Model_DW.Timer_LPConditionHold = 0U;
        App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 0U;
        App_Model_DW.m_RWPCUSM_App_start_eznj = WPC_On;
        App_Model_DW.RWPC_MODE = true;
      }

      /* DataTypeConversion: '<S619>/Data Type Conversion45' */
      rtb_NvM_INDContType_gaoc = (INDContType)rtb_TmpSignalConversionAtR_NvM_.INDContType;

      /* DataTypeConversion: '<S619>/Data Type Conversion52' */
      rtb_NvM_RheostatOption_nwi3 = (RheostatOption)rtb_TmpSignalConversionAtR_NvM_.RheostatOption;

      /* DataTypeConversion: '<S619>/Data Type Conversion2' */
      rtb_NvM_EVOpt_mj52 = (Bool)rtb_TmpSignalConversionAtR_NvM_.EVOption;

      /* DataTypeConversion: '<S612>/Data Type Conversion' */
      App_Model_B.ADC_IGN1_IN_mp5r = (Bool)rtb_TmpSignalConversionAtR_ADC_.IGN1_IN;

      /* DataTypeConversion: '<S612>/Data Type Conversion8' */
      rtb_ADC_BatSysStateFault_e4zi = (Bool)rtb_TmpSignalConversionAtR_ADC_.BatSysStateFault;

      /* DataTypeConversion: '<S613>/Data Type Conversion1' */
      App_Model_B.BCAN_RX_C_LFAnt_SrchSta_jfhx = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_LFAnt_SrchSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion16' */
      App_Model_B.BCAN_RX_RheoStatLevel_g4ba = (C_RheoStatLevel)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RheoStatLevel;

      /* DataTypeConversion: '<S613>/Data Type Conversion17' */
      rtb_BCAN_RX_C_CLU_DtntOutS_hzdo = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DtntOutSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion18' */
      rtb_BCAN_RX_C_WPCOnOffNvalueSet = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCOnOffNvalueSet;

      /* DataTypeConversion: '<S613>/Data Type Conversion19' */
      rtb_BCAN_RX_C_USMReset = (C_USMReset)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USMReset;

      /* DataTypeConversion: '<S613>/Data Type Conversion50' */
      rtb_BCAN_RX_C_Lamp_IntTail_eket = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Lamp_IntTailLmpOnReq;

      /* DataTypeConversion: '<S613>/Data Type Conversion39' */
      App_Model_B.BCAN_RX_C_AutoBrightLevel_bziq = (C_AutoBrightLevel)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_AutoBrightLevel;

      /* DataTypeConversion: '<S613>/Data Type Conversion10' */
      App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_hvzq = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_BCM_SmkOptTyp;

      /* DataTypeConversion: '<S613>/Data Type Conversion51' */
      rtb_BCAN_Latch_TypeOption__pu2k = (LatchTypeOption)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Latch_TypeOption_DRV;

      /* DataTypeConversion: '<S613>/Data Type Conversion13' */
      rtb_BCAN_AstDrSw_mqsr = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion12' */
      rtb_BCAN_DrvDrSw_mxls = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion14' */
      rtb_BCAN_RLDrSw_is22 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion15' */
      rtb_BCAN_RRDrSw_hqit = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion35' */
      rtb_BCAN_AstDrSw_SBCM_n4f0 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta_SBCM;

      /* DataTypeConversion: '<S613>/Data Type Conversion47' */
      rtb_BCAN_DrvDrSw_SBCM_pmk5 = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta_SBCM;

      /* DataTypeConversion: '<S613>/Data Type Conversion48' */
      rtb_BCAN_RLDrSw_SBCM_g1uf = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta_SBCM;

      /* DataTypeConversion: '<S613>/Data Type Conversion49' */
      rtb_BCAN_RRDrSw_SBCM_j2dk = (Bool)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta_SBCM;

      /* Chart: '<S613>/DoorOpenCloseStateFunctionFlowGraph' */
      DoorOpenCloseStateFunctionFlowG(rtb_BCAN_Latch_TypeOption__pu2k, rtb_BCAN_AstDrSw_mqsr, rtb_BCAN_DrvDrSw_mxls, rtb_BCAN_RLDrSw_is22, rtb_BCAN_RRDrSw_hqit, rtb_BCAN_AstDrSw_SBCM_n4f0,
        rtb_BCAN_DrvDrSw_SBCM_pmk5, rtb_BCAN_RLDrSw_SBCM_g1uf, rtb_BCAN_RRDrSw_SBCM_j2dk, &App_Model_B.b_AstDrSw_jy3e, &App_Model_B.b_DrvDrSw_kh5i, &App_Model_B.b_RLDrSw_jnn1,
        &App_Model_B.b_RRDrSw_bczk, &App_Model_DW.sf_DoorOpenCloseStateFunct_mocq);

      /* DataTypeConversion: '<S613>/Data Type Conversion5' */
      App_Model_B.BCAN_RX_C_WPCIndUSMState = (WPCIndUSMState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCIndUSMState;

      /* DataTypeConversion: '<S613>/Data Type Conversion9' */
      App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki = (WPC2IndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2_IndSyncVal;

      /* DataTypeConversion: '<S613>/Data Type Conversion11' */
      App_Model_B.BCAN_RX_C_GearPosSta_g0d0 = (GearPosSta)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_VCU_GearPosSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion24' */
      rtb_BCAN_RX_C_FANSpeedSet = (FANSpeed)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USM_FANSpeedSet;

      /* DataTypeConversion: '<S618>/Data Type Conversion83' */
      rtb_NFC1_b_MultiCardDetect_p5dp = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[0].MultiCardDetectionState;

      /* DataTypeConversion: '<S620>/Data Type Conversion29' */
      App_Model_B.UART_WPC1_PhoneLeft_j1xl = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].PhoneLeft;

      /* DataTypeConversion: '<S620>/Data Type Conversion36' */
      App_Model_B.UART_WPC1_DeviceState_dona = (DeviceState)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].DeviceState;

      /* DataTypeConversion: '<S620>/Data Type Conversion31' */
      App_Model_B.UART_WPC1_ChargingCurrent_nw0n = rtb_TmpSignalConversionAtR_UART.Device_WCT[0].ChargingCurrent;

      /* DataTypeConversion: '<S620>/Data Type Conversion5' */
      App_Model_B.UART_WPC1_CoilTempDegree_ocbf = rtb_TmpSignalConversionAtR_UART.Device_WCT[0].CoilTempDegree;

      /* DataTypeConversion: '<S620>/Data Type Conversion6' */
      App_Model_B.UART_WPC1_Temp_SnsrError_gw1i = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[0].TempSnsrError;

      /* DataTypeConversion: '<S616>/Data Type Conversion60' incorporates:
       *  UnitDelay: '<S617>/Unit Delay5'
       */
      App_Model_B.INT_RWPCIndCmdState = App_Model_DW.UnitDelay5_DSTATE_dr5b;

      /* DataTypeConversion: '<S616>/Data Type Conversion66' incorporates:
       *  UnitDelay: '<S617>/Unit Delay11'
       */
      App_Model_B.INT_b_CmdAmberSync_RWPC = App_Model_DW.UnitDelay11_DSTATE;

      /* DataTypeConversion: '<S616>/Data Type Conversion67' incorporates:
       *  UnitDelay: '<S617>/Unit Delay12'
       */
      App_Model_B.INT_b_SyncAmber_RWPC = App_Model_DW.UnitDelay12_DSTATE;

      /* Outputs for Atomic SubSystem: '<S458>/RWPC_TE_sys' */
      /* Outputs for Atomic SubSystem: '<S461>/USMSettingControl_Function' */
      USMSettingControl_Function_gulk(rtb_BCAN_RX_C_WPCOnOffNvalueSet, rtb_BCAN_RX_C_USMReset, &App_Model_B.RWPCSWOption, &App_Model_B.C_RWPCRValue);

      /* End of Outputs for SubSystem: '<S461>/USMSettingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S463>/NFC_WPC_Mode_Control_Function' */
      NFC_WPC_Mode_Control_Funct_appg(rtb_NvM_EVOpt_mj52, App_Model_B.BCAN_RX_C_GearPosSta_g0d0, App_Model_B.C_RWPCRValue, rtb_ADC_BatSysStateFault_e4zi, App_Model_B.ADC_IGN1_IN_mp5r,
        &App_Model_B.WPCStatus_gxft);

      /* End of Outputs for SubSystem: '<S463>/NFC_WPC_Mode_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S463>/TemperatureSensorErrorDetect_Function' */
      TemperatureSensorErrorDete_kspf(App_Model_B.WPCStatus_gxft, App_Model_B.UART_WPC1_Temp_SnsrError_gw1i, App_Model_ConstB.Dum_WPC_Temp_SnsrError_jjjr, App_Model_ConstB.Dum_R_DIA_gb_DTCClearF_lyb0,
        &App_Model_B.b_TempSensorFault_h5jx, &App_Model_B.b_Timer_TempSensor_Check_hxeq);

      /* End of Outputs for SubSystem: '<S463>/TemperatureSensorErrorDetect_Function' */

      /* Outputs for Atomic SubSystem: '<S463>/PreventionSMK_LF_Interference_Function' */
      PreventionSMK_LF_Interfere_dgfk(App_Model_B.WPCStatus_gxft, App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_hvzq, App_Model_B.BCAN_RX_C_LFAnt_SrchSta_jfhx, App_Model_B.b_AstDrSw_jy3e,
        App_Model_B.b_DrvDrSw_kh5i, App_Model_B.b_RLDrSw_jnn1, App_Model_B.b_RRDrSw_bczk, App_Model_ConstB.Dum_L_LFSearchingOn_IN_mmw1, &App_Model_B.b_LFState_o4ks);

      /* End of Outputs for SubSystem: '<S463>/PreventionSMK_LF_Interference_Function' */

      /* Outputs for Atomic SubSystem: '<S463>/OverCurrentDetecting_Function' */
      OverCurrentDetecting_Funct_oslj(App_Model_B.WPCStatus_gxft, App_Model_B.UART_WPC1_ChargingCurrent_nw0n, &App_Model_B.b_CurrentFault_p1jy, &App_Model_B.b_Timer_OvrCurr_bfb2,
        &App_Model_B.b_Timer_ReOvrCurr_c3aw);

      /* End of Outputs for SubSystem: '<S463>/OverCurrentDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S463>/OverTemperatureDetecting_Function' */
      OverTemperatureDetecting_F_jyxc(App_Model_B.WPCStatus_gxft, App_Model_B.UART_WPC1_CoilTempDegree_ocbf, App_Model_ConstB.Dum_CoilTempDegree2_Co_olha, App_Model_ConstB.Dum_CoilTempDegree3_Co_piwk,
        App_Model_B.UART_WPC1_DeviceState_dona, &App_Model_B.b_TemperatureFault_iak5, &App_Model_B.b_Timer_OverTemp_ffe1);

      /* End of Outputs for SubSystem: '<S463>/OverTemperatureDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S461>/WPC_MainControl_Function' */
      A_WPC_MainControl_Function_lgtv(rtb_NvM_EVOpt_mj52, App_Model_B.b_LFState_o4ks, App_Model_B.b_CurrentFault_p1jy, App_Model_B.b_TempSensorFault_h5jx, App_Model_B.C_RWPCRValue,
        App_Model_B.b_TemperatureFault_iak5, App_Model_B.b_AstDrSw_jy3e, App_Model_B.b_DrvDrSw_kh5i, App_Model_B.UART_WPC1_PhoneLeft_j1xl, App_Model_B.UART_WPC1_DeviceState_dona,
        App_Model_B.WPCStatus_gxft, App_Model_B.ADC_IGN1_IN_mp5r, App_Model_B.BCAN_RX_C_WPCIndUSMState, App_Model_B.INT_b_CmdAmberSync_RWPC, App_Model_B.INT_RWPCIndCmdState,
        App_Model_B.BCAN_RX_C_GearPosSta_g0d0, &App_Model_B.C_WPCWarning_epwi, &App_Model_B.b_FANModeCmd_iroy, &App_Model_B.b_GreenINDCmd_lsi0, &App_Model_B.b_AmberINDCmd_cdgi,
        &App_Model_B.b_BlinkState_k1bt, &App_Model_B.b_Timer_PhoneReminderCheck_as5u, &App_Model_B.b_Timer_PhoneWarningCheck_icl4, &App_Model_B.b_Timer_WarningComplete_ib23,
        &App_Model_B.b_ChargingEnable_m33x, &App_Model_B.BlinkState_ouyp, &App_Model_B.b_PhnLeftChk_Enable_cnhm, &App_Model_B.b_Timer_WarningTypeCheck_eda4);

      /* End of Outputs for SubSystem: '<S461>/WPC_MainControl_Function' */

      /* Outputs for Atomic SubSystem: '<S462>/FAN_Control_Function' */
      App_M_FAN_Control_Function_nnca(rtb_BCAN_RX_C_FANSpeedSet, rtb_BCAN_RX_C_USMReset, App_Model_B.b_FANModeCmd_iroy, &rtb_FAN_PWM_eua1, &App_Model_B.FANDutyRatioSta_htud);

      /* End of Outputs for SubSystem: '<S462>/FAN_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S462>/IND_Animation_Control_Function' */
      /* Outputs for Atomic SubSystem: '<S467>/RWPC_INDAnimationControl' */
      /* Chart: '<S474>/IND_Animation_WPC_Priority_Flow_Graph' incorporates:
       *  DataTypeConversion: '<S613>/Data Type Conversion6'
       */
      App_Model_DW.Input_CAN_WPCIndSyncVal_pr_op3a = App_Model_DW.Input_CAN_WPCIndSyncVal_st_cekz;
      App_Model_DW.Input_CAN_WPCIndSyncVal_st_cekz = (C_WPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal;
      if ((uint32)App_Model_DW.is_active_c178_WPC_IND_Animatio == 0U) {
        App_Model_DW.Input_CAN_WPCIndSyncVal_pr_op3a = (C_WPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal;
        App_Model_DW.is_active_c178_WPC_IND_Animatio = 1U;
        App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;

        /* 1 */
        tmp_c = App_Model_DW.Input_CAN_WPCIndSyncVal_pr_op3a;
        tmp_d = App_Model_DW.Input_CAN_WPCIndSyncVal_st_cekz;
        if ((tmp_c != tmp_d) && ((uint32)tmp_c == WPCIndSyncVal__Default) && (tmp_c != tmp_d)) {
          App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_On;
        } else {
          /* 1 */
        }
      } else {
        /* 1 */
        tmp_c = App_Model_DW.Input_CAN_WPCIndSyncVal_pr_op3a;
        tmp_d = App_Model_DW.Input_CAN_WPCIndSyncVal_st_cekz;
        if (((uint32)App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_Off) && ((tmp_c != tmp_d) && ((uint32)tmp_c == WPCIndSyncVal__Default)) && (tmp_c != tmp_d)) {
          App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_On;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_WPCPreSyncAct == WPCPreSyncAct_On) && ((tmp_c != tmp_d) && ((uint32)tmp_d == WPCIndSyncVal__Default))) {
          App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;
        } else {
          /* no actions */
        }
      }

      /* End of Chart: '<S474>/IND_Animation_WPC_Priority_Flow_Graph' */

      /* Chart: '<S474>/IND_Animation_WPC2_Priority_Flow_Graph' */
      IND_Animation_WPC2_Priority_Flo(App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki, &App_Model_B.Var_WPC2PreSyncAct_ocx1, &App_Model_DW.sf_IND_Animation_WPC2_Prio_c04w);

      /* Chart: '<S474>/IND_Animation_Priority_Flow_Graph' */
      if ((uint32)App_Model_DW.is_active_c175_WPC_IND_Animatio == 0U) {
        WPC2PreSyncAct tmp;
        App_Model_DW.is_active_c175_WPC_IND_Animatio = 1U;
        App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__Off;

        /* 1 */
        tmp_e = App_Model_B.Var_WPCPreSyncAct;
        tmp = App_Model_B.Var_WPC2PreSyncAct_ocx1;
        if (((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp == WPC2PreSyncAct_Off)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__WPC;

          /* 1 */
        } else if (((uint32)tmp_e == WPCPreSyncAct_Off) && ((uint32)tmp == WPC2PreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__WPC2;
        } else {
          /* 1 */
        }
      } else {
        WPC2PreSyncAct tmp;

        /* 1 */
        tmp_e = App_Model_B.Var_WPCPreSyncAct;
        tmp = App_Model_B.Var_WPC2PreSyncAct_ocx1;
        if (((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp == WPC2PreSyncAct_Off)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__WPC;

          /* 1 */
        } else if (((uint32)tmp_e == WPCPreSyncAct_Off) && ((uint32)tmp == WPC2PreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__WPC2;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC) && ((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp == WPC2PreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__WPCWPC2;

          /* 1 */
        } else if (((uint32)App_Model_B.Var_PreSyncAct_jsc5 == PreSyncAct__WPC2) && ((uint32)tmp_e == WPCPreSyncAct_On) && ((uint32)tmp == WPC2PreSyncAct_On)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__WPC2WPC;

          /* 1 */
        } else if (((uint32)tmp_e == WPCPreSyncAct_Off) && ((uint32)tmp == WPC2PreSyncAct_Off)) {
          App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__Off;
        } else {
          /* no actions */
        }
      }

      /* End of Chart: '<S474>/IND_Animation_Priority_Flow_Graph' */

      /* Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' incorporates:
       *  DataTypeConversion: '<S613>/Data Type Conversion6'
       */
      App_Model_DW.sfEvent_bqin = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Input_CAN_WPCIndSyncVal_prev = App_Model_DW.Input_CAN_WPCIndSyncVal_start;
      App_Model_DW.Input_CAN_WPCIndSyncVal_start = (C_WPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal;
      if ((uint32)App_Model_DW.is_active_c180_WPC_IND_Animatio == 0U) {
        App_Model_DW.Input_CAN_WPCIndSyncVal_prev = (C_WPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal;
        App_Model_DW.is_active_c180_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDPhaseState_na13 = 1U;
        App_Model_DW.is_INDPhaseState_p4z4 = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState_holq = 0U;
        App_Model_DW.is_active_WPC_IND_Command_State = 1U;

        /* 1 */
        App_Model_DW.is_WPC_IND_Command_State_Contro = App_M_IN_WPCINDCmdState_Default;
        App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;
      } else {
        if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
          App_Model_INDPhaseState_jko2();
        }

        if ((uint32)App_Model_DW.is_active_WPC_IND_Command_State != 0U) {
          switch (App_Model_DW.is_WPC_IND_Command_State_Contro) {
           case App__IN_WPCINDCmdState_Charging:
            App_Mod_WPCINDCmdState_Charging();
            break;

           case App_M_IN_WPCINDCmdState_Default:
            App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;

            /* 1 */
            tmp_c = App_Model_DW.Input_CAN_WPCIndSyncVal_start;
            tmp_d = App_Model_DW.Input_CAN_WPCIndSyncVal_prev;
            if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndSyncVal__3rdSync)) {
              App_Model_DW.is_WPC_IND_Command_State_Contro = App__IN_WPCINDCmdState_Charging;
              App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_3rdSync;
              App_Model_DW.is_WPCINDCmdState_3rdSync = App_IN_WPCINDCmdState_3rdChrgOn;
              App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                App_Model_INDPhaseState_jko2();
              }

              App_Model_DW.sfEvent_bqin = -1;
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;

              /* 1 */
            } else if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndSyncVal__ErrorOn)) {
              App_Model_DW.is_WPC_IND_Command_State_Contro = App_Mod_IN_WPCIndCmdState_Error;

              /* 1 */
              App_Model_DW.is_WPCIndCmdState_Error = App_M_IN_WPCINDCmdState_ErrorOn;
              App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                App_Model_INDPhaseState_jko2();
              }

              App_Model_DW.sfEvent_bqin = -1;
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
            } else {
              /* no actions */
            }
            break;

           case App_Mod_IN_WPCIndCmdState_Error:
            /* 1 */
            tmp_c = App_Model_DW.Input_CAN_WPCIndSyncVal_start;
            tmp_d = App_Model_DW.Input_CAN_WPCIndSyncVal_prev;
            if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndCmdState__Default)) {
              exit_internal_WPCIndCmdState_Er();
              App_Model_DW.is_WPC_IND_Command_State_Contro = App_M_IN_WPCINDCmdState_Default;
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;

              /* 2 230113 for ReCharge */
            } else if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndSyncVal__3rdSync)) {
              exit_internal_WPCIndCmdState_Er();
              App_Model_DW.is_WPC_IND_Command_State_Contro = App__IN_WPCINDCmdState_Charging;
              App_Model_DW.is_WPCINDCmdState_Charging = App_M_IN_WPCINDCmdState_3rdSync;
              App_Model_DW.is_WPCINDCmdState_3rdSync = App_IN_WPCINDCmdState_3rdChrgOn;
              c_previousEvent = App_Model_DW.sfEvent_bqin;
              App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                App_Model_INDPhaseState_jko2();
              }

              App_Model_DW.sfEvent_bqin = c_previousEvent;
              App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__3rdChrgOn;
            } else {
              switch (App_Model_DW.is_WPCIndCmdState_Error) {
               case App__IN_WPCINDCmdState_ErrorOff:
                App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeOut;

                /* 1. */
                if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndSyncVal__ErrorOn)) {
                  App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                    App_Model_INDPhaseState_jko2();
                  }

                  App_Model_DW.is_WPCIndCmdState_Error = App_M_IN_WPCINDCmdState_ErrorOn;
                  App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                    App_Model_INDPhaseState_jko2();
                  }

                  App_Model_DW.sfEvent_bqin = -1;
                  App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;
                }
                break;

               case App_M_IN_WPCINDCmdState_ErrorOn:
                App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeIn;

                /* 1. */
                if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndSyncVal__ErrorOff)) {
                  App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                    App_Model_INDPhaseState_jko2();
                  }

                  App_Model_DW.is_WPCIndCmdState_Error = App__IN_WPCINDCmdState_ErrorOff;
                  App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                    App_Model_INDPhaseState_jko2();
                  }

                  App_Model_DW.sfEvent_bqin = -1;
                  App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeOut;
                } else if (App_Model_DW.Timer_INDPhaseState_holq >= (uint32)((uint8)100U)) {
                  App_Model_DW.sfEvent_bqin = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                    App_Model_INDPhaseState_jko2();
                  }

                  App_Model_DW.sfEvent_bqin = -1;
                  App_Model_DW.is_WPCIndCmdState_Error = App_IN_WPCINDCmdState_ErrorOn_2;
                  App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorOn;
                } else {
                  /* no actions */
                }
                break;

               case App_IN_WPCINDCmdState_ErrorOn_2:
                App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorOn;
                if ((tmp_d != tmp_c) && ((uint32)tmp_c == WPCIndSyncVal__ErrorOff)) {
                  App_Model_DW.is_WPCIndCmdState_Error = App__IN_WPCINDCmdState_ErrorOff;
                  App_Model_DW.sfEvent_bqin = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_na13 != 0U) {
                    App_Model_INDPhaseState_jko2();
                  }

                  App_Model_DW.sfEvent_bqin = -1;
                  App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__ErrorFadeOut;
                }
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }

      /* End of Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' */

      /* Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' incorporates:
       *  DataTypeConversion: '<S613>/Data Type Conversion9'
       */
      App_Model_DW.sfEvent_fezm = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc = App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi = App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki;
      if ((uint32)App_Model_DW.is_active_c179_WPC_IND_Animatio == 0U) {
        App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc = App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki;
        App_Model_DW.is_active_c179_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDPhaseState_eoo3 = 1U;
        App_Model_DW.is_INDPhaseState_k14z = App_M_IN_INDPhaseState_Off_bpnu;
        App_Model_DW.Timer_INDPhaseState_h1ak = 0U;
        App_Model_DW.is_active_WPC2_IND_Command_c4py = 1U;

        /* 1 */
        App_Model_DW.is_WPC2_IND_Command_State__krzh = App__IN_WPC2INDCmdState_Default;
        App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;
      } else {
        if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
          App_Model_INDPhaseState_pnuz();
        }

        if ((uint32)App_Model_DW.is_active_WPC2_IND_Command_c4py != 0U) {
          switch (App_Model_DW.is_WPC2_IND_Command_State__krzh) {
           case App_IN_WPC2INDCmdState_Charging:
            App_Mo_WPC2INDCmdState_Charging();
            break;

           case App__IN_WPC2INDCmdState_Default:
            App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;

            /* 1 */
            tmp_a = App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi;
            tmp_b = App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc;
            if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__3rdSync)) {
              App_Model_DW.is_WPC2_IND_Command_State__krzh = App_IN_WPC2INDCmdState_Charging;
              App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_3rdSync;
              App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = Ap_IN_WPC2INDCmdState_3rdChrgOn;
              App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                App_Model_INDPhaseState_pnuz();
              }

              App_Model_DW.sfEvent_fezm = -1;
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;

              /* 1 */
            } else if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOn)) {
              App_Model_DW.is_WPC2_IND_Command_State__krzh = App_Mo_IN_WPC2INDCmdState_Error;

              /* 1 */
              App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App__IN_WPC2INDCmdState_ErrorOn;
              App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                App_Model_INDPhaseState_pnuz();
              }

              App_Model_DW.sfEvent_fezm = -1;
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
            } else {
              /* no actions */
            }
            break;

           case App_Mo_IN_WPC2INDCmdState_Error:
            /* 1 */
            tmp_a = App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi;
            tmp_b = App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc;
            if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndCmdState__Default)) {
              exit_internal_WPC2INDCmdState_E();
              App_Model_DW.is_WPC2_IND_Command_State__krzh = App__IN_WPC2INDCmdState_Default;
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;

              /* 2 230113 for ReCharge */
            } else if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__3rdSync)) {
              exit_internal_WPC2INDCmdState_E();
              App_Model_DW.is_WPC2_IND_Command_State__krzh = App_IN_WPC2INDCmdState_Charging;
              App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App__IN_WPC2INDCmdState_3rdSync;
              App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = Ap_IN_WPC2INDCmdState_3rdChrgOn;
              c_previousEvent = App_Model_DW.sfEvent_fezm;
              App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
              if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                App_Model_INDPhaseState_pnuz();
              }

              App_Model_DW.sfEvent_fezm = c_previousEvent;
              App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__3rdChrgOn;
            } else {
              switch (App_Model_DW.is_WPC2INDCmdState_Error_jb0a) {
               case App_IN_WPC2INDCmdState_ErrorOff:
                App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;

                /* 1. */
                if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOn)) {
                  App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                    App_Model_INDPhaseState_pnuz();
                  }

                  App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App__IN_WPC2INDCmdState_ErrorOn;
                  App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                    App_Model_INDPhaseState_pnuz();
                  }

                  App_Model_DW.sfEvent_fezm = -1;
                  App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;
                }
                break;

               case App__IN_WPC2INDCmdState_ErrorOn:
                App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeIn;

                /* 1. */
                if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOff)) {
                  App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                    App_Model_INDPhaseState_pnuz();
                  }

                  App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_IN_WPC2INDCmdState_ErrorOff;
                  App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                    App_Model_INDPhaseState_pnuz();
                  }

                  App_Model_DW.sfEvent_fezm = -1;
                  App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;
                } else if (App_Model_DW.Timer_INDPhaseState_h1ak >= (uint32)((uint8)100U)) {
                  App_Model_DW.sfEvent_fezm = (sint32)event_CancelTimer_INDPhase_h0ww;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                    App_Model_INDPhaseState_pnuz();
                  }

                  App_Model_DW.sfEvent_fezm = -1;
                  App_Model_DW.is_WPC2INDCmdState_Error_jb0a = Ap_IN_WPC2INDCmdState_ErrorOn_2;
                  App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorOn;
                } else {
                  /* no actions */
                }
                break;

               case Ap_IN_WPC2INDCmdState_ErrorOn_2:
                App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorOn;
                if ((tmp_b != tmp_a) && ((uint32)tmp_a == WPC2IndSyncVal__ErrorOff)) {
                  App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_IN_WPC2INDCmdState_ErrorOff;
                  App_Model_DW.sfEvent_fezm = (sint32)event_StartTimer_INDPhaseS_a3lh;
                  if ((uint32)App_Model_DW.is_active_INDPhaseState_eoo3 != 0U) {
                    App_Model_INDPhaseState_pnuz();
                  }

                  App_Model_DW.sfEvent_fezm = -1;
                  App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__ErrorFadeOut;
                }
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }

      /* End of Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' */

      /* Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
       *  DataTypeConversion: '<S613>/Data Type Conversion5'
       *  DataTypeConversion: '<S613>/Data Type Conversion6'
       *  DataTypeConversion: '<S613>/Data Type Conversion9'
       *  DataTypeConversion: '<S616>/Data Type Conversion67'
       */
      App_Model_DW.sfEvent_c1ob = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.Var_PreSyncAct_prev_ojgc = App_Model_DW.Var_PreSyncAct_start_ntz3;
      App_Model_DW.Var_PreSyncAct_start_ntz3 = App_Model_B.Var_PreSyncAct_jsc5;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_p_mhlo = App_Model_DW.Input_CAN_WPC2IndSyncVal_s_mifz;
      App_Model_DW.Input_CAN_WPC2IndSyncVal_s_mifz = App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki;
      App_Model_DW.Var_WPC2IndCmdState_prev = App_Model_DW.Var_WPC2IndCmdState_start;
      App_Model_DW.Var_WPC2IndCmdState_start = App_Model_B.Var_WPC2IndCmdState;
      App_Model_DW.Input_CAN_WPCIndSyncVal_pr_jzlo = App_Model_DW.Input_CAN_WPCIndSyncVal_st_iach;
      App_Model_DW.Input_CAN_WPCIndSyncVal_st_iach = (C_WPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal;
      App_Model_DW.Var_WPCIndCmdState_prev = App_Model_DW.Var_WPCIndCmdState_start;
      App_Model_DW.Var_WPCIndCmdState_start = App_Model_B.Var_WPCIndCmdState;
      App_Model_DW.WPCIndUSMState_prev_nqvt = App_Model_DW.WPCIndUSMState_start_dh2i;
      App_Model_DW.WPCIndUSMState_start_dh2i = App_Model_B.BCAN_RX_C_WPCIndUSMState;
      App_Model_DW.b_SyncAmber_prev_eb5q = App_Model_DW.b_SyncAmber_start_hkgy;
      App_Model_DW.b_SyncAmber_start_hkgy = App_Model_B.INT_b_SyncAmber_RWPC;
      if ((uint32)App_Model_DW.is_active_c176_WPC_IND_Animatio == 0U) {
        App_Model_DW.Var_PreSyncAct_prev_ojgc = App_Model_B.Var_PreSyncAct_jsc5;
        App_Model_DW.Input_CAN_WPC2IndSyncVal_p_mhlo = App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki;
        App_Model_DW.Var_WPC2IndCmdState_prev = App_Model_B.Var_WPC2IndCmdState;
        App_Model_DW.Input_CAN_WPCIndSyncVal_pr_jzlo = (C_WPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal;
        App_Model_DW.Var_WPCIndCmdState_prev = App_Model_B.Var_WPCIndCmdState;
        App_Model_DW.WPCIndUSMState_prev_nqvt = App_Model_B.BCAN_RX_C_WPCIndUSMState;
        App_Model_DW.b_SyncAmber_prev_eb5q = App_Model_B.INT_b_SyncAmber_RWPC;
        App_Model_DW.is_active_c176_WPC_IND_Animatio = 1U;
        App_Model_DW.is_active_INDLight_h5bd = 1U;
        App_Model_DW.is_INDLight_kqsl = App_Model_IN_INDLight_Off;
        App_Model_DW.Timer_INDLight_ewv0 = 0U;
        App_Model_DW.is_active_IND_Animation_Sy_n4yx = 1U;

        /* Default */
        App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_Mo_IN_RWPCINDAnimation_Init;
        App_Model_DW.sfEvent_c1ob = (sint32)App__event_CancelTimer_INDLight;
        App_Model_INDLight_jhwd();
        App_Model_DW.sfEvent_c1ob = -1;
        App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
        App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
        App_Model_DW.is_active_INDFadeIn_afmn = 1U;
        App_Model_DW.is_INDFadeIn_n305 = App_Model_IN_INDFadeIn_Off;
        App_Model_DW.Timer_INDFadeIn_g1fs = 0U;
        App_Model_DW.is_active_INDFadeOut_cklz = 1U;
        App_Model_DW.is_INDFadeOut_ps5o = App_Model_IN_INDFadeOut_Off;
        App_Model_DW.Timer_INDFadeOut_ey0j = 0U;
      } else {
        if ((uint32)App_Model_DW.is_active_INDLight_h5bd != 0U) {
          App_Model_INDLight_jhwd();
        }

        if ((uint32)App_Model_DW.is_active_IND_Animation_Sy_n4yx != 0U) {
          IND_Animation_Sync_Control_ftqp(&rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC_IndSyncVal);
        }

        if ((uint32)App_Model_DW.is_active_INDFadeIn_afmn != 0U) {
          App_Model_INDFadeIn_kcqh();
        }

        if ((uint32)App_Model_DW.is_active_INDFadeOut_cklz != 0U) {
          App_Model_INDFadeOut_iwqq();
        }
      }

      /* End of Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */

      /* Chart: '<S474>/Amber_Sync_Chart' */
      App_Model_DW.Output_INT_RWPCIndCmdState_prev = App_Model_DW.Output_INT_RWPCIndCmdState_star;
      App_Model_DW.Output_INT_RWPCIndCmdState_star = App_Model_B.Output_INT_RWPCIndCmdState;
      if ((uint32)App_Model_DW.is_active_c171_WPC_IND_Animatio == 0U) {
        App_Model_DW.Output_INT_RWPCIndCmdState_prev = App_Model_B.Output_INT_RWPCIndCmdState;
        App_Model_DW.is_active_c171_WPC_IND_Animatio = 1U;
        App_Model_DW.is_SyncTrigger_owzu = App_Mode_IN_SyncTriggerOff_ffg4;
        rtb_b_CmdAmberSync_pbbn = Off;
      } else if ((uint32)App_Model_DW.is_SyncTrigger_owzu == App_Mode_IN_SyncTriggerOff_ffg4) {
        RWPCIndCmdState tmp_0;
        RWPCIndCmdState tmp_1;
        rtb_b_CmdAmberSync_pbbn = Off;
        tmp_0 = App_Model_DW.Output_INT_RWPCIndCmdState_prev;
        tmp_1 = App_Model_DW.Output_INT_RWPCIndCmdState_star;
        if (((tmp_0 != tmp_1) && ((uint32)tmp_0 == RWPCIndCmdState__ErrorOn)) || ((tmp_0 != tmp_1) && ((uint32)tmp_0 == RWPCIndCmdState__ErrorFadeOut))) {
          App_Model_DW.is_SyncTrigger_owzu = App_Model_IN_SyncTriggerOn_bnd3;
          rtb_b_CmdAmberSync_pbbn = On;
        }
      } else {
        RWPCIndCmdState tmp_0;
        RWPCIndCmdState tmp_1;

        /* case IN_SyncTriggerOn: */
        rtb_b_CmdAmberSync_pbbn = On;
        tmp_0 = App_Model_DW.Output_INT_RWPCIndCmdState_star;
        tmp_1 = App_Model_DW.Output_INT_RWPCIndCmdState_prev;
        if (((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__ErrorOn)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__ChrgFadeOut)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 ==
              RWPCIndCmdState__3rdChrgOn)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__3rdChrgFadeIn)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__2ndChrgOn)) || ((tmp_1
              != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__2ndChrgFadeIn)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__1stChrgOn)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 ==
              RWPCIndCmdState__1stChrgFadeIn)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__ChrgOff)) || ((tmp_1 != tmp_0) && ((uint32)tmp_0 == RWPCIndCmdState__Default))) {
          App_Model_DW.is_SyncTrigger_owzu = App_Mode_IN_SyncTriggerOff_ffg4;
          rtb_b_CmdAmberSync_pbbn = Off;
        }
      }

      /* End of Chart: '<S474>/Amber_Sync_Chart' */

      /* Chart: '<S474>/Amber_Sync_Indy' */
      App_Model_Amber_Sync_Indy(App_Model_B.b_BlinkState_k1bt, rtb_b_CmdAmberSync_pbbn, App_Model_B.BlinkState_ouyp, &rtb_b_SyncAmber_jg2q, &App_Model_DW.sf_Amber_Sync_Indy);

      /* End of Outputs for SubSystem: '<S467>/RWPC_INDAnimationControl' */
      /* End of Outputs for SubSystem: '<S462>/IND_Animation_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S462>/IndyOutputControl_Function' */
      IndyOutputControl_Function_bnu5(rtb_NvM_INDContType_gaoc, App_Model_B.INT_RWPCIndCmdState, App_Model_B.C_WPCWarning_epwi, App_Model_B.BCAN_RX_C_WPCIndUSMState, App_Model_B.b_AmberINDCmd_cdgi,
        App_Model_B.INT_b_SyncAmber_RWPC, rtb_BCAN_RX_C_CLU_DtntOutS_hzdo, rtb_NvM_RheostatOption_nwi3, rtb_BCAN_RX_C_Lamp_IntTail_eket, App_Model_B.b_GreenINDCmd_lsi0,
        App_Model_B.BCAN_RX_RheoStatLevel_g4ba, App_Model_B.BCAN_RX_C_AutoBrightLevel_bziq, &App_Model_B.P_GreenIND_OUT_efiw, &App_Model_B.P_GreenIND2_OUT_g4dl, &App_Model_B.P_GreenIND3_OUT_okli,
        &App_Model_B.P_AmberIND_OUT_fl2l);

      /* End of Outputs for SubSystem: '<S462>/IndyOutputControl_Function' */

      /* Outputs for Atomic SubSystem: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
      WPC_PhoneLeftDetectingCont_e5zj(App_Model_B.WPCStatus_gxft, rtb_NFC1_b_MultiCardDetect_p5dp);

      /* End of Outputs for SubSystem: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
      /* End of Outputs for SubSystem: '<S458>/RWPC_TE_sys' */

      /* DataTypeConversion: '<S613>/Data Type Conversion2' */
      rtb_BCAN_RX_C_CLU_ClusterU_loak = (C_USMReset)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_ClusterUSM;

      /* DataTypeConversion: '<S613>/Data Type Conversion20' */
      rtb_BCAN_RX_C_IAU_ProfileIDRVal = (C_ProfileIDRValue)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_IAU_ProfileIDRVal;

      /* DataTypeConversion: '<S613>/Data Type Conversion21' */
      rtb_BCAN_RX_C_CF_AVN_ProfileIDR = (C_ProfileIDRValue)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_AVN_ProfileIDRValue;

      /* DataTypeConversion: '<S613>/Data Type Conversion22' */
      rtb_BCAN_RX_C_CLU_DisSpdVa_fwgw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DisSpdVal_KPH;

      /* DataTypeConversion: '<S613>/Data Type Conversion23' */
      rtb_BCAN_RX_C_ENG_EngSta_ob2c = (C_EngineState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_ENG_EngSta;

      /* DataTypeConversion: '<S613>/Data Type Conversion25' */
      rtb_LCAN_RX_LC_WPC_IAUWPCNFCcmd = (LC_IAUWPCNFCcmd)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC_IAUWPCNFCcmd;

      /* DataTypeConversion: '<S613>/Data Type Conversion26' */
      rtb_LCAN_RX_LC_WPC2_IAUWPC_ar2p = (LC_IAUWPCNFCcmd)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC2_IAUWPCNFCcmd;

      /* DataTypeConversion: '<S613>/Data Type Conversion28' */
      rtb_LCAN_RX_LC_IAU_Status_cdna = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_IAU_Status;

      /* DataTypeConversion: '<S613>/Data Type Conversion3' */
      rtb_BCAN_RX_C_HCU_HevRdySt_cani = (C_HEVEngOnState)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_HCU_HevRdySta;

      /* DataTypeConversion: '<S613>/Data Type Conversion37' */
      rtb_LCAN_RX_LC_OwnerKey_Reg_Sta = (IAU_OwnerPhnRegRVal)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerKey_Reg_Status;

      /* DataTypeConversion: '<S613>/Data Type Conversion4' */
      rtb_BCAN_RX_C_WPC2OnOffNva_lh4l = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2OnOffNvalueSet;

      /* DataTypeConversion: '<S613>/Data Type Conversion42' */
      rtb_BCAN_RX_C_RWPCIndSyncVal = (RWPCIndSyncVal)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RWPC_IndSyncVal;

      /* DataTypeConversion: '<S613>/Data Type Conversion43' */
      rtb_BCAN_RX_C_CF_Gway_WPCAnimat = (WPCAnimationNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_Gway_WPCAnimationNvalueSet;

      /* DataTypeConversion: '<S613>/Data Type Conversion44' */
      rtb_LCAN_RX_LC_OwnerPairingAdve = (OwnerPairingAdvertisingReq)rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerPairingAdvertisingReq;

      /* DataTypeConversion: '<S613>/Data Type Conversion7' */
      rtb_BCAN_RX_C_RWPCOnOffNvalueSe = (C_WPCOnOffNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RWPC_OnOffNValueSet;

      /* DataTypeConversion: '<S613>/Data Type Conversion8' */
      rtb_BCAN_RX_C_CF_Gway_RWPCAnima = (WPCAnimationNvalueSet)rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RWPC_AnimationNvalueSet;

      /* DataTypeConversion: '<S616>/Data Type Conversion71' incorporates:
       *  UnitDelay: '<S617>/Unit Delay16'
       */
      rtb_INT_RWPCWarning = App_Model_DW.UnitDelay16_DSTATE;

      /* DataTypeConversion: '<S616>/Data Type Conversion72' incorporates:
       *  UnitDelay: '<S617>/Unit Delay7'
       */
      rtb_INT_RWPCStatus = App_Model_DW.UnitDelay7_DSTATE;

      /* DataTypeConversion: '<S616>/Data Type Conversion79' incorporates:
       *  UnitDelay: '<S617>/Unit Delay19'
       */
      rtb_INT_RWPC_b_PhnLeftChk_Enabl = App_Model_DW.UnitDelay19_DSTATE;

      /* DataTypeConversion: '<S618>/Data Type Conversion1' */
      rtb_NFC1_NfcOnThePad = (OnThePad)rtb_TmpSignalConversionAtR_NFC_.Device[0].NfcOnThePad;

      /* DataTypeConversion: '<S618>/Data Type Conversion2' */
      rtb_NFC2_NfcOnThePad_ly4s = (OnThePad)rtb_TmpSignalConversionAtR_NFC_.Device[1].NfcOnThePad;

      /* DataTypeConversion: '<S618>/Data Type Conversion34' */
      rtb_NFC1_LC_WPC_NFCDetection = (LC_WPC_NFCDetection)rtb_TmpSignalConversionAtR_NFC_.Device[0].NFCDetection;

      /* DataTypeConversion: '<S618>/Data Type Conversion38' */
      rtb_NFC1_LPCD_Wakeup = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[0].LPCD_Wakeup;

      /* DataTypeConversion: '<S618>/Data Type Conversion75' */
      rtb_NFC2_LC_WPC_NFCDetecti_bfk2 = (LC_WPC_NFCDetection)rtb_TmpSignalConversionAtR_NFC_.Device[1].NFCDetection;

      /* DataTypeConversion: '<S618>/Data Type Conversion76' */
      rtb_NFC2_LPCD_Wakeup_npea = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[1].LPCD_Wakeup;

      /* DataTypeConversion: '<S618>/Data Type Conversion82' */
      rtb_NFC2_b_MultiCardDetect_gfij = (Bool)rtb_TmpSignalConversionAtR_NFC_.Device[1].MultiCardDetectionState;

      /* DataTypeConversion: '<S619>/Data Type Conversion1' */
      rtb_NvM_WPCType_ge5s = (WPCType)rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE;

      /* DataTypeConversion: '<S619>/Data Type Conversion40' */
      rtb_NvM_IndUSMOption = (Bool)rtb_TmpSignalConversionAtR_NvM_.IndUSMOption;

      /* DataTypeConversion: '<S620>/Data Type Conversion47' */
      rtb_UART_WPC2_PhoneLeft_i3nv = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].PhoneLeft;

      /* DataTypeConversion: '<S620>/Data Type Conversion48' */
      rtb_UART_WPC2_ChargingCurr_mg2z = rtb_TmpSignalConversionAtR_UART.Device_WCT[1].ChargingCurrent;

      /* DataTypeConversion: '<S620>/Data Type Conversion49' */
      rtb_UART_WPC2_DeviceState_itii = (DeviceState)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].DeviceState;

      /* DataTypeConversion: '<S620>/Data Type Conversion51' */
      rtb_UART_WPC2_CoilTempDegr_k04h = rtb_TmpSignalConversionAtR_UART.Device_WCT[1].CoilTempDegree;

      /* DataTypeConversion: '<S620>/Data Type Conversion55' */
      rtb_UART_WPC2_Temp_SnsrErr_lnip = (Bool)rtb_TmpSignalConversionAtR_UART.Device_WCT[1].TempSnsrError;

      /* DataTypeConversion: '<S621>/Data Type Conversion1' */
      rtb_Uds_LPConditionFlag_l0d5 = (Bool)rtb_TmpSignalConversionAtR_Uds_.Uds_LPConditionFlag;

      /* DataTypeConversion: '<S621>/Data Type Conversion32' */
      rtb_Uds_m_NFCOption_k4ut = (Bool)rtb_TmpSignalConversionAtR_Uds_.m_NFCOption;

      /* DataTypeConversion: '<S622>/Data Type Conversion1' */
      rtb_WCT1_ChargingOnthePad = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[0].ChargingOnthePad;

      /* DataTypeConversion: '<S622>/Data Type Conversion2' */
      rtb_WCT1_ObjectOnthePad = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[0].ObjectOnthePad;

      /* DataTypeConversion: '<S622>/Data Type Conversion3' */
      rtb_WCT2_ChargingOnthePad_nsi0 = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[1].ChargingOnthePad;

      /* DataTypeConversion: '<S622>/Data Type Conversion4' */
      rtb_WCT2_ObjectOnthePad_nmu4 = (OnThePad)rtb_TmpSignalConversionAtR_WCT_.Device[1].ObjectOnthePad;

      /* Chart: '<S625>/WPC_Mode_LPConditionJdg' */
      App_Mod_WPC_Mode_LPConditionJdg(App_Model_B.WPCStatus_gxft, &rtb_WPCMode_LPConditionFla_hka2, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_jccj);

      /* Chart: '<S625>/NFC_Mode_LPConditionJdg' */
      App_Mod_NFC_Mode_LPConditionJdg(App_Model_B.WPCStatus_gxft, &rtb_NFCMode_LPConditionFla_ogfp, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_hmwu);

      /* Chart: '<S625>/MainControl_LPConditionJdg' */
      App__MainControl_LPConditionJdg(App_Model_B.WPCStatus_gxft, App_Model_B.b_Timer_PhoneReminderCheck_as5u, App_Model_B.b_Timer_PhoneWarningCheck_icl4, App_Model_B.b_Timer_WarningComplete_ib23,
        App_Model_B.b_Timer_WarningTypeCheck_eda4, App_Model_B.b_PhnLeftChk_Enable_cnhm, &rtb_WPCMain_LPConditionFla_nrse, &App_Model_DW.sf_MainControl_LPCondition_aehg);

      /* Chart: '<S625>/SMKLF_LPConditionJdg' */
      App_Model_SMKLF_LPConditionJdg(App_Model_B.b_LFState_o4ks, &rtb_SMKLF_LPConditionFlag__j4w3, &App_Model_DW.sf_SMKLF_LPConditionJdg_jne5);

      /* Chart: '<S625>/TempSnsrErrDetect_LPConditionJdg' */
      TempSnsrErrDetect_LPConditionJd(App_Model_B.b_TempSensorFault_h5jx, App_Model_B.b_Timer_TempSensor_Check_hxeq, &rtb_TempSnsrError_LPCondit_oh14, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_flnb);

      /* Chart: '<S625>/OverTempDetect_LPConditionJdg' */
      A_OverTempDetect_LPConditionJdg(App_Model_B.b_TemperatureFault_iak5, App_Model_B.b_Timer_OverTemp_ffe1, &rtb_OverTempDetect_LPCondi_a4lc, &App_Model_DW.sf_OverTempDetect_LPCondit_hgqy);

      /* Chart: '<S625>/OverCurrent_LPConditionJdg' */
      App__OverCurrent_LPConditionJdg(App_Model_B.b_CurrentFault_p1jy, App_Model_B.b_Timer_OvrCurr_bfb2, App_Model_B.b_Timer_ReOvrCurr_c3aw, &rtb_OverCurrent_LPConditio_hfnx,
        &App_Model_DW.sf_OverCurrent_LPCondition_hwn5);

      /* Chart: '<S625>/FAN_LPConditionJdg' */
      App_Model_FAN_LPConditionJdg(rtb_FAN_PWM_eua1, &rtb_FAN_LPConditionFlag_wr_okst, &App_Model_DW.sf_FAN_LPConditionJdg_ioqj);

      /* Chart: '<S625>/USM_WPC_LPConditionJdg' incorporates:
       *  Constant: '<S625>/Constant'
       *  DataStoreRead: '<S625>/Data Store Read3'
       */
      App_Model_DW.sfEvent_czwh = (sint32)App_Model_CALL_EVENT_ee3d;
      App_Model_DW.m_ProfileGuestWPCUSM_App_prev = App_Model_DW.m_ProfileGuestWPCUSM_App_start;
      App_Model_DW.m_ProfileGuestWPCUSM_App_start = 0.0;
      App_Model_DW.m_ProfileOneWPCUSM_App_prev = App_Model_DW.m_ProfileOneWPCUSM_App_start;
      App_Model_DW.m_ProfileOneWPCUSM_App_start = 0.0;
      App_Model_DW.m_ProfileTwoWPCUSM_App_prev = App_Model_DW.m_ProfileTwoWPCUSM_App_start;
      App_Model_DW.m_ProfileTwoWPCUSM_App_start = 0.0;
      App_Model_DW.m_ProfileThreeWPCUSM_App_prev = App_Model_DW.m_ProfileThreeWPCUSM_App_start;
      App_Model_DW.m_ProfileThreeWPCUSM_App_start = 0.0;
      App_Model_DW.m_RWPCUSM_App_prev_bsqc = App_Model_DW.m_RWPCUSM_App_start_eznj;
      App_Model_DW.m_RWPCUSM_App_start_eznj = m_RWPCUSM_App;
      if ((uint32)App_Model_DW.is_active_c50_sH3eOQeO4p6NHsKQC == 0U) {
        App_Model_DW.m_ProfileGuestWPCUSM_App_prev = 0.0;
        App_Model_DW.m_ProfileOneWPCUSM_App_prev = 0.0;
        App_Model_DW.m_ProfileTwoWPCUSM_App_prev = 0.0;
        App_Model_DW.m_ProfileThreeWPCUSM_App_prev = 0.0;
        App_Model_DW.m_RWPCUSM_App_prev_bsqc = m_RWPCUSM_App;
        App_Model_DW.is_active_c50_sH3eOQeO4p6NHsKQC = 1U;
        App_Model_DW.is_active_LPConditionHold = 1U;
        App_Model_DW.is_LPConditionHold = App_IN_LPConditionHold_Off_kvlq;
        App_Model_DW.Timer_LPConditionHold = 0U;
        App_Model_DW.is_active_LPConditionChk_Chart = 1U;
        App_Model_DW.is_LPConditionChk_Chart = App_Mod_IN_LPCondition_Off_gfto;
        App_Model_DW.sfEvent_czwh = (sint32)event_StartTimer_LPConditi_i0nb;
        App_Model_LPConditionHold_fjxw();
        App_Model_DW.sfEvent_czwh = -1;
        App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 0U;

        /* Awake */
        App_Model_DW.ECUResetEnable = 0U;
      } else {
        if ((uint32)App_Model_DW.is_active_LPConditionHold != 0U) {
          App_Model_LPConditionHold_fjxw();
        }

        if ((uint32)App_Model_DW.is_active_LPConditionChk_Chart != 0U) {
          switch (App_Model_DW.is_LPConditionChk_Chart) {
           case App_Mod_IN_LPCondition_Off_gfto:
            App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 0U;
            if (App_Model_DW.ECUResetEnable == 1U) {
              App_Model_DW.sfEvent_czwh = (sint32)event_CancelTimer_LPCondit_nxtu;
              if ((uint32)App_Model_DW.is_active_LPConditionHold != 0U) {
                App_Model_LPConditionHold_fjxw();
              }

              App_Model_DW.sfEvent_czwh = -1;
              App_Model_DW.ECUResetEnable = 0U;
              App_Model_DW.is_LPConditionChk_Chart = App_Mode_IN_LPCondition_On_nvlj;
              App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 1U;

              /* SleepOK */
            } else {
              App__LPConditionTimerCheck_mlkd();
            }
            break;

           case App_Mode_IN_LPCondition_On_nvlj:
            App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 1U;
            if ((App_Model_DW.m_ProfileGuestWPCUSM_App_prev != App_Model_DW.m_ProfileGuestWPCUSM_App_start) || (App_Model_DW.m_ProfileOneWPCUSM_App_prev != App_Model_DW.m_ProfileOneWPCUSM_App_start) ||
                (App_Model_DW.m_ProfileTwoWPCUSM_App_prev != App_Model_DW.m_ProfileTwoWPCUSM_App_start) || (App_Model_DW.m_ProfileThreeWPCUSM_App_prev != App_Model_DW.m_ProfileThreeWPCUSM_App_start) ||
                (App_Model_DW.m_RWPCUSM_App_prev_bsqc != App_Model_DW.m_RWPCUSM_App_start_eznj)) {
              App_Model_DW.is_LPConditionChk_Chart = App_Mod_IN_LPCondition_Off_gfto;
              App_Model_DW.sfEvent_czwh = (sint32)event_StartTimer_LPConditi_i0nb;
              if ((uint32)App_Model_DW.is_active_LPConditionHold != 0U) {
                App_Model_LPConditionHold_fjxw();
              }

              App_Model_DW.sfEvent_czwh = -1;
              App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 0U;

              /* Awake */
              App_Model_DW.ECUResetEnable = 0U;
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }

      /* End of Chart: '<S625>/USM_WPC_LPConditionJdg' */

      /* BusCreator: '<S460>/Bus Creator1' incorporates:
       *  Concatenate: '<S14>/Vector Concatenate'
       *  DataStoreRead: '<S625>/Data Store Read3'
       *  DataStoreRead: '<S625>/Data Store Read9'
       *  DataTypeConversion: '<S625>/Data Type Conversion'
       *  DataTypeConversion: '<S625>/Data Type Conversion1'
       *  DataTypeConversion: '<S625>/Data Type Conversion10'
       *  DataTypeConversion: '<S625>/Data Type Conversion11'
       *  DataTypeConversion: '<S625>/Data Type Conversion12'
       *  DataTypeConversion: '<S625>/Data Type Conversion13'
       *  DataTypeConversion: '<S625>/Data Type Conversion17'
       *  DataTypeConversion: '<S625>/Data Type Conversion18'
       *  DataTypeConversion: '<S625>/Data Type Conversion19'
       *  DataTypeConversion: '<S625>/Data Type Conversion2'
       *  DataTypeConversion: '<S625>/Data Type Conversion22'
       *  DataTypeConversion: '<S625>/Data Type Conversion24'
       *  DataTypeConversion: '<S625>/Data Type Conversion28'
       *  DataTypeConversion: '<S625>/Data Type Conversion3'
       *  DataTypeConversion: '<S625>/Data Type Conversion4'
       *  DataTypeConversion: '<S625>/Data Type Conversion5'
       *  DataTypeConversion: '<S625>/Data Type Conversion6'
       *  DataTypeConversion: '<S625>/Data Type Conversion7'
       *  DataTypeConversion: '<S625>/Data Type Conversion8'
       *  DataTypeConversion: '<S625>/Data Type Conversion9'
       *  Merge generated from: '<S465>/Merge'
       *  Merge: '<S591>/Merge'
       */
      App_Model_B.Device_pymj[0].WPCWarning = (uint8)App_Model_B.C_WPCWarning_epwi;
      App_Model_B.Device_pymj[0].WPCRValue = (uint8)App_Model_B.RWPCSWOption;
      App_Model_B.Device_pymj[0].PhoneWarningCheck_Timer = App_Model_B.b_Timer_PhoneWarningCheck_icl4;
      App_Model_B.Device_pymj[0].WPCStatus = (uint8)App_Model_B.WPCStatus_gxft;
      App_Model_B.Device_pymj[0].FAN_PWM = rtb_FAN_PWM_eua1;
      App_Model_B.Device_pymj[0].FANDutyRatioSta = (uint8)App_Model_B.FANDutyRatioSta_htud;
      App_Model_B.Device_pymj[0].ChargingEnable = (uint8)App_Model_B.b_ChargingEnable_m33x;
      App_Model_B.Device_pymj[0].TempSensorFault = (uint8)App_Model_B.b_TempSensorFault_h5jx;
      App_Model_B.Device_pymj[0].BlinkState = (uint8)App_Model_B.b_BlinkState_k1bt;
      App_Model_B.Device_pymj[0].LFState = (uint8)App_Model_B.b_LFState_o4ks;
      App_Model_B.Device_pymj[0].AmberIND_OUT = App_Model_B.P_AmberIND_OUT_fl2l;
      App_Model_B.Device_pymj[0].GreenIND1_OUT = App_Model_B.P_GreenIND_OUT_efiw;
      App_Model_B.Device_pymj[0].GreenIND2_OUT = App_Model_B.P_GreenIND2_OUT_g4dl;
      App_Model_B.Device_pymj[0].GreenIND3_OUT = App_Model_B.P_GreenIND3_OUT_okli;
      App_Model_B.Device_pymj[0].PhnLeftChk_Enable = (uint8)App_Model_B.b_PhnLeftChk_Enable_cnhm;
      App_Model_B.Device_pymj[0].WPCMode_LPConditionFlag = rtb_WPCMode_LPConditionFla_hka2;
      App_Model_B.Device_pymj[0].NFCMode_LPConditionFlag = rtb_NFCMode_LPConditionFla_ogfp;
      App_Model_B.Device_pymj[0].WPCMain_LPConditionFlag = rtb_WPCMain_LPConditionFla_nrse;
      App_Model_B.Device_pymj[0].SMKLF_LPConditionFlag = rtb_SMKLF_LPConditionFlag__j4w3;
      App_Model_B.Device_pymj[0].TempSnsrError_LPConditionFlag = rtb_TempSnsrError_LPCondit_oh14;
      App_Model_B.Device_pymj[0].OverTempDetect_LPConditionFlag = rtb_OverTempDetect_LPCondi_a4lc;
      App_Model_B.Device_pymj[0].OverCurrent_LPConditionFlag = rtb_OverCurrent_LPConditio_hfnx;
      App_Model_B.Device_pymj[0].FAN_LPConditionFlag = rtb_FAN_LPConditionFlag_wr_okst;
      App_Model_B.Device_pymj[0].TemperatureFault = (uint8)App_Model_B.b_TemperatureFault_iak5;
      App_Model_B.Device_pymj[0].CurrentFault = (uint8)App_Model_B.b_CurrentFault_p1jy;
      App_Model_B.Device_pymj[0].m_ProfileGuestWPCUSM = App_Model_ConstB.m_ProfileGuestWPCUSM_kudi;
      App_Model_B.Device_pymj[0].m_ProfileOneWPCUSM = App_Model_ConstB.m_ProfileOneWPCUSM_f5nx;
      App_Model_B.Device_pymj[0].m_ProfileTwoWPCUSM = App_Model_ConstB.m_ProfileTwoWPCUSM_mkbe;
      App_Model_B.Device_pymj[0].m_ProfileThreeWPCUSM = App_Model_ConstB.m_ProfileThreeWPCUSM_iypg;
      App_Model_B.Device_pymj[0].m_RWPCUSM = (uint8)m_RWPCUSM_App;
      App_Model_B.Device_pymj[0].USM_LPConditionFlag = App_Model_B.P_WPC_USM_LPConditionFlag__eeih;
      App_Model_B.Device_pymj[0].WPCIndUSMState = App_Model_ConstB.WPCIndUSMState_nr0f;
      App_Model_B.Device_pymj[0].WPCIndSyncVal = App_Model_ConstB.WPCIndSyncVal_plo1;
      App_Model_B.Device_pymj[0].RWPCIndSyncVal = (uint8)App_Model_B.Output_CAN_RWPCIndSyncVal;
      App_Model_B.Device_pymj[0].m_ProfileGuestFanUSM = App_Model_ConstB.m_ProfileGuestFanUSM_mzut;
      App_Model_B.Device_pymj[0].m_ProfileOneFanUSM = App_Model_ConstB.m_ProfileOneFanUSM_ae44;
      App_Model_B.Device_pymj[0].m_ProfileTwoFanUSM = App_Model_ConstB.m_ProfileTwoFanUSM_fv3n;
      App_Model_B.Device_pymj[0].m_ProfileThreeFanUSM = App_Model_ConstB.m_ProfileThreeFanUSM_gnxw;
      App_Model_B.Device_pymj[0].m_RWPCFanUSM = (uint8)m_RWPCFanUSM_App;

      /* BusCreator: '<S460>/Bus Creator3' incorporates:
       *  Concatenate: '<S14>/Vector Concatenate'
       */
      App_Model_B.Device_pymj[1].WPCWarning = App_Model_ConstB.WPCWarning_nref;
      App_Model_B.Device_pymj[1].WPCRValue = App_Model_ConstB.WPCRValue_bvwm;
      App_Model_B.Device_pymj[1].PhoneWarningCheck_Timer = App_Model_ConstB.PhoneWarningCheck_Time_kneb;
      App_Model_B.Device_pymj[1].WPCStatus = App_Model_ConstB.WPCStatus_adf2;
      App_Model_B.Device_pymj[1].FAN_PWM = App_Model_ConstB.FAN_PWM_izc0;
      App_Model_B.Device_pymj[1].FANDutyRatioSta = App_Model_ConstB.FANDutyRatioSta_mgfo;
      App_Model_B.Device_pymj[1].ChargingEnable = App_Model_ConstB.ChargingEnable_ptbg;
      App_Model_B.Device_pymj[1].TempSensorFault = App_Model_ConstB.TempSensorFault_lqxu;
      App_Model_B.Device_pymj[1].BlinkState = App_Model_ConstB.BlinkState_g03o;
      App_Model_B.Device_pymj[1].LFState = App_Model_ConstB.LFState_erpk;
      App_Model_B.Device_pymj[1].AmberIND_OUT = App_Model_ConstB.AmberIND_OUT_e2jh;
      App_Model_B.Device_pymj[1].GreenIND1_OUT = App_Model_ConstB.GreenIND1_OUT_been;
      App_Model_B.Device_pymj[1].GreenIND2_OUT = App_Model_ConstB.GreenIND2_OUT_czfu;
      App_Model_B.Device_pymj[1].GreenIND3_OUT = App_Model_ConstB.GreenIND3_OUT_h5lc;
      App_Model_B.Device_pymj[1].PhnLeftChk_Enable = App_Model_ConstB.PhnLeftChk_Enable_jbzc;
      App_Model_B.Device_pymj[1].WPCMode_LPConditionFlag = App_Model_ConstB.WPCMode_LPConditionFla_oj34;
      App_Model_B.Device_pymj[1].NFCMode_LPConditionFlag = App_Model_ConstB.NFCMode_LPConditionFla_heui;
      App_Model_B.Device_pymj[1].WPCMain_LPConditionFlag = App_Model_ConstB.WPCMain_LPConditionFla_e3cc;
      App_Model_B.Device_pymj[1].SMKLF_LPConditionFlag = App_Model_ConstB.SMKLF_LPConditionFlag_o1zl;
      App_Model_B.Device_pymj[1].TempSnsrError_LPConditionFlag = App_Model_ConstB.TempSnsrError_LPCondit_mx3e;
      App_Model_B.Device_pymj[1].OverTempDetect_LPConditionFlag = App_Model_ConstB.OverTempDetect_LPCondi_eukm;
      App_Model_B.Device_pymj[1].OverCurrent_LPConditionFlag = App_Model_ConstB.OverCurrent_LPConditio_mjd3;
      App_Model_B.Device_pymj[1].FAN_LPConditionFlag = App_Model_ConstB.FAN_LPConditionFlag_jc4k;
      App_Model_B.Device_pymj[1].TemperatureFault = App_Model_ConstB.TemperatureFault_edcr;
      App_Model_B.Device_pymj[1].CurrentFault = App_Model_ConstB.CurrentFault_gfta;
      App_Model_B.Device_pymj[1].m_ProfileGuestWPCUSM = App_Model_ConstB.m_ProfileGuestWPCUSM_n1rm;
      App_Model_B.Device_pymj[1].m_ProfileOneWPCUSM = App_Model_ConstB.m_ProfileOneWPCUSM_l2cn;
      App_Model_B.Device_pymj[1].m_ProfileTwoWPCUSM = App_Model_ConstB.m_ProfileTwoWPCUSM_jkws;
      App_Model_B.Device_pymj[1].m_ProfileThreeWPCUSM = App_Model_ConstB.m_ProfileThreeWPCUSM_i1uh;
      App_Model_B.Device_pymj[1].m_RWPCUSM = App_Model_ConstB.m_RWPCUSM_mcl5;
      App_Model_B.Device_pymj[1].USM_LPConditionFlag = App_Model_ConstB.USM_LPConditionFlag_orma;
      App_Model_B.Device_pymj[1].WPCIndUSMState = App_Model_ConstB.WPCIndUSMState_p2zf;
      App_Model_B.Device_pymj[1].WPCIndSyncVal = App_Model_ConstB.WPCIndSyncVal_gjdq;
      App_Model_B.Device_pymj[1].RWPCIndSyncVal = App_Model_ConstB.RWPCIndSyncVal_ciiv;
      App_Model_B.Device_pymj[1].m_ProfileGuestFanUSM = App_Model_ConstB.m_ProfileGuestFanUSM_iwmb;
      App_Model_B.Device_pymj[1].m_ProfileOneFanUSM = App_Model_ConstB.m_ProfileOneFanUSM_bzog;
      App_Model_B.Device_pymj[1].m_ProfileTwoFanUSM = App_Model_ConstB.m_ProfileTwoFanUSM_akig;
      App_Model_B.Device_pymj[1].m_ProfileThreeFanUSM = App_Model_ConstB.m_ProfileThreeFanUSM_c540;
      App_Model_B.Device_pymj[1].m_RWPCFanUSM = App_Model_ConstB.m_RWPCFanUSM_kogy;

      /* DataStoreRead: '<S624>/Data Store Read3' */
      rtb_DataStoreRead3_kbgw = m_RWPCUSM_App;

      /* DataStoreRead: '<S624>/Data Store Read6' */
      rtb_DataStoreRead6_kuqo = m_ProfileGuestWPC2USM_App;

      /* DataStoreRead: '<S624>/Data Store Read7' */
      rtb_DataStoreRead7_kjr0 = m_ProfileOneWPC2USM_App;

      /* DataStoreRead: '<S624>/Data Store Read8' */
      rtb_DataStoreRead8_pjyy = m_ProfileTwoWPC2USM_App;

      /* Update for UnitDelay: '<S617>/Unit Delay5' */
      App_Model_DW.UnitDelay5_DSTATE_dr5b = App_Model_B.Output_INT_RWPCIndCmdState;

      /* Update for UnitDelay: '<S617>/Unit Delay11' */
      App_Model_DW.UnitDelay11_DSTATE = rtb_b_CmdAmberSync_pbbn;

      /* Update for UnitDelay: '<S617>/Unit Delay12' */
      App_Model_DW.UnitDelay12_DSTATE = rtb_b_SyncAmber_jg2q;

      /* Update for UnitDelay: '<S617>/Unit Delay16' incorporates:
       *  Merge generated from: '<S465>/Merge'
       */
      App_Model_DW.UnitDelay16_DSTATE = App_Model_B.C_WPCWarning_epwi;

      /* Update for UnitDelay: '<S617>/Unit Delay7' incorporates:
       *  Merge: '<S591>/Merge'
       */
      App_Model_DW.UnitDelay7_DSTATE = App_Model_B.WPCStatus_gxft;

      /* Update for UnitDelay: '<S617>/Unit Delay19' incorporates:
       *  Merge generated from: '<S465>/Merge'
       */
      App_Model_DW.UnitDelay19_DSTATE = App_Model_B.b_PhnLeftChk_Enable_cnhm;
    } else if (App_Model_DW.RWPC_MODE) {
      /* Disable for Atomic SubSystem: '<S458>/RWPC_TE_sys' */
      /* Disable for Atomic SubSystem: '<S462>/IndyOutputControl_Function' */
      IndyOutputControl__n4jw_Disable();

      /* End of Disable for SubSystem: '<S462>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S458>/RWPC_TE_sys' */
      App_Model_DW.RWPC_MODE = false;
    } else {
      /* no actions */
    }

    /* End of RelationalOperator: '<S11>/Compare' */
    /* End of Outputs for SubSystem: '<S3>/RWPC' */

    /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion2'
     */
    switch (rtb_TmpSignalConversionAtR_NvM_.WPC_NAME) {
     case WPC:
      /* MultiPortSwitch: '<S3>/Multiport Switch' */
      (void)memcpy(&App_Model_B.MultiportSwitch[0], &App_Model_B.Device[0], sizeof(IDT_Model) << 1U);
      break;

     case RWPC:
      /* MultiPortSwitch: '<S3>/Multiport Switch' */
      (void)memcpy(&App_Model_B.MultiportSwitch[0], &App_Model_B.Device_pymj[0], sizeof(IDT_Model) << 1U);
      break;

     default:
      /* MultiPortSwitch: '<S3>/Multiport Switch' */
      (void)memcpy(&App_Model_B.MultiportSwitch[0], &App_Model_B.Device_bn3v[0], sizeof(IDT_Model) << 1U);
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch' */
  } else if (App_Model_DW.App_Model_TE_Sys_MODE) {
    /* Disable for Enabled SubSystem: '<S3>/DualWPC' */
    if (App_Model_DW.DualWPC_MODE) {
      /* Disable for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
      /* Disable for Atomic SubSystem: '<S22>/IndyOutputControl_Function' */
      IndyOutputControl_Funct_Disable();

      /* End of Disable for SubSystem: '<S22>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S16>/DWPC1_TE_sys' */

      /* Disable for Atomic SubSystem: '<S16>/DWPC2_TE_sys' */
      /* Disable for Atomic SubSystem: '<S217>/IndyOutputControl_Function' */
      IndyOutputControl__gkc5_Disable();

      /* End of Disable for SubSystem: '<S217>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S16>/DWPC2_TE_sys' */
      App_Model_DW.DualWPC_MODE = false;
    }

    /* End of Disable for SubSystem: '<S3>/DualWPC' */

    /* Disable for Enabled SubSystem: '<S3>/SingleWPC' */
    if (App_Model_DW.SingleWPC_MODE) {
      /* Disable for Atomic SubSystem: '<S635>/SWPC_TE_sys' */
      /* Disable for Atomic SubSystem: '<S639>/IndyOutputControl_Function' */
      IndyOutputControl__i523_Disable();

      /* End of Disable for SubSystem: '<S639>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S635>/SWPC_TE_sys' */
      App_Model_DW.SingleWPC_MODE = false;
    }

    /* End of Disable for SubSystem: '<S3>/SingleWPC' */

    /* Disable for Enabled SubSystem: '<S3>/RWPC' */
    if (App_Model_DW.RWPC_MODE) {
      /* Disable for Atomic SubSystem: '<S458>/RWPC_TE_sys' */
      /* Disable for Atomic SubSystem: '<S462>/IndyOutputControl_Function' */
      IndyOutputControl__n4jw_Disable();

      /* End of Disable for SubSystem: '<S462>/IndyOutputControl_Function' */
      /* End of Disable for SubSystem: '<S458>/RWPC_TE_sys' */
      App_Model_DW.RWPC_MODE = false;
    }

    /* End of Disable for SubSystem: '<S3>/RWPC' */
    App_Model_DW.App_Model_TE_Sys_MODE = false;
  } else {
    /* no actions */
  }

  /* End of Outputs for SubSystem: '<Root>/App_Model_TE_Sys' */

  /* BusCreator: '<Root>/Bus Creator' */
  (void)memcpy(&rtb_BusCreator.Device[0], &App_Model_B.MultiportSwitch[0], sizeof(IDT_Model) << 1U);

  /* Outport generated from: '<Root>/Bus Element Out' */
  (void)Rte_Write_P_Model_Model_STR(&rtb_BusCreator);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  App_Model_M->Timing.clockTick0++;
  if (!App_Model_M->Timing.clockTick0) {
    App_Model_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void Model_Init(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)App_Model_M, 0,
                sizeof(RT_MODEL_App_Model_T));

  /* block I/O */
  (void) memset(((void *) &App_Model_B), 0,
                sizeof(B_App_Model_T));

  {
    App_Model_B.WPCStatus_es4i = ModeOff;
    App_Model_B.Output_OPT_WPCStatus = ModeOff;
    App_Model_B.WPCStatus_gxft = ModeOff;
    App_Model_B.INT_WPC2Status = ModeOff;
    App_Model_B.INT_WPCStatus = ModeOff;
    App_Model_B.WPC2Status = ModeOff;
    App_Model_B.Output_OPT_WPCStatus_fwza = ModeOff;
    App_Model_B.WPCStatus_hv2c = ModeOff;
    App_Model_B.Output_OPT_WPCStatus_hxy1 = ModeOff;
    App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;
    App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_Off;
    App_Model_B.INT_SWPCIndUSMState = WPCIndUSMState__Default;
    App_Model_B.Output_CAN_WPCIndUSMState = WPCIndUSMState__Default;
    App_Model_B.BCAN_RX_C_WPCIndUSMState = WPCIndUSMState__Default;
    App_Model_B.INT_WPCIndUSMState = WPCIndUSMState__Default;
    App_Model_B.Output_CAN_WPCIndUSMState_kprv = WPCIndUSMState__Default;
    App_Model_B.Output_INT_WPCIndUSMState_bcrl = WPCIndUSMState__Default;
    App_Model_B.INT_SWPCIndCmdState = WPCIndCmdState__Default;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
    App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;
    App_Model_B.INT_WPCIndCmdState = WPCIndCmdState__Default;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
    App_Model_B.BCAN_RX_C_CF_Gway_WPCAnimationN = WPCAnimationNvalueSet__Type1;
    App_Model_B.BCAN_RX_C_CF_Gway_WPCAnima_litl = WPCAnimationNvalueSet__Type1;
    App_Model_B.Var_WPC2PreSyncAct = WPC2PreSyncAct_Off;
    App_Model_B.Var_WPC2PreSyncAct_ocx1 = WPC2PreSyncAct_Off;
    App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_Off;
    App_Model_B.BCAN_RX_C_WPC2IndSyncVal = WPC2IndSyncVal__Default;
    App_Model_B.BCAN_RX_C_WPC2IndSyncVal_ecki = WPC2IndSyncVal__Default;
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
    App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_B.INT_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_B.Var_RWPCPreSyncAct = RWPCPreSyncAct_Off;
    App_Model_B.Var_RWPCPreSyncAct_baek = RWPCPreSyncAct_Off;
    App_Model_B.BCAN_RX_C_RWPCIndSyncVal = RWPCIndSyncVal__Default;
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
    App_Model_B.BCAN_RX_C_RWPCIndSyncVal_b5xt = RWPCIndSyncVal__Default;
    App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
    App_Model_B.INT_RWPCIndCmdState = RWPCIndCmdState__Default;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
    App_Model_B.Var_RWPCIndCmdState = RWPCIndCmdState__Default;
    App_Model_B.Var_RWPCIndCmdState_mh2c = RWPCIndCmdState__Default;
    App_Model_B.Var_PreSyncAct = PreSyncAct__Off;
    App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__Off;
    App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__Off;
    App_Model_B.Var_PreSyncAct_akzv = PreSyncAct__Off;
    App_Model_B.LCAN_RX_LC_OwnerPairingAdvertis = OwnerPairingAdvertisingReq__Off;
    App_Model_B.LCAN_RX_LC_OwnerPairingAdv_i0z3 = OwnerPairingAdvertisingReq__Off;
    App_Model_B.NFC1_NfcOnThePad = OnThePad_Off;
    App_Model_B.WCT1_ChargingOnthePad = OnThePad_Off;
    App_Model_B.WCT1_ObjectOnthePad = OnThePad_Off;
    App_Model_B.NFC1_NfcOnThePad_m2d4 = OnThePad_Off;
    App_Model_B.NFC2_NfcOnThePad = OnThePad_Off;
    App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
    App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
    App_Model_B.MainContMode_ins3 = nonNFC_ICE;
    App_Model_B.MainContMode_fjp0 = nonNFC_ICE;
    App_Model_B.MainContMode_foyi = nonNFC_ICE;
    App_Model_B.NFC1_LC_WPC_NFCDetection = NFCDetection_Off;
    App_Model_B.NFC1_LC_WPC_NFCDetection_g5w2 = NFCDetection_Off;
    App_Model_B.NFC2_LC_WPC_NFCDetection = NFCDetection_Off;
    App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcmd = IAUWPCNFCcmdDefault;
    App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcm_h4rr = IAUWPCNFCcmdDefault;
    App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd = IAUWPCNFCcmdDefault;
    App_Model_B.LCAN_RX_LC_OwnerKey_Reg_Status = OwnerPhnReg__Default;
    App_Model_B.LCAN_RX_LC_OwnerKey_Reg_St_mn3f = OwnerPhnReg__Default;
    App_Model_B.BCAN_RX_C_GearPosSta = GearPos_P;
    App_Model_B.BCAN_RX_C_GearPosSta_g0d0 = GearPos_P;
    App_Model_B.BCAN_RX_C_GearPosSta_grgw = GearPos_P;
    App_Model_B.BCAN_RX_C_FANSpeedSet = FANSpd_Low;
    App_Model_B.BCAN_RX_C_FANSpeedSet_aqsp = FANSpd_Low;
    App_Model_B.FANDutyRatioSta = LowDuty;
    App_Model_B.FANDutyRatioSta_htud = LowDuty;
    App_Model_B.FANDutyRatioSta_acxf = LowDuty;
    App_Model_B.FANDutyRatioSta_lwkf = LowDuty;
    App_Model_B.UART_WPC1_DeviceState = Init;
    App_Model_B.UART_WPC1_DeviceState_dona = Init;
    App_Model_B.UART_WPC1_DeviceState_par2 = Init;
    App_Model_B.UART_WPC2_DeviceState = Init;
    App_Model_B.INT_SWPCWarning = WPCWarningOff;
    App_Model_B.C_WPCWarning_kjwv = WPCWarningOff;
    App_Model_B.Output_WPCWarning = WPCWarningOff;
    App_Model_B.C_WPCWarning_lymx = WPCWarningOff;
    App_Model_B.Output_WPCWarning_ddyd = WPCWarningOff;
    App_Model_B.C_WPCWarning_bpme = WPCWarningOff;
    App_Model_B.Output_PhoneLeftWarningWPCStatu = WPCWarningOff;
    App_Model_B.C_WPCWarning_epwi = WPCWarningOff;
    App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;
    App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
    App_Model_B.INT_WPCWarning = WPCWarningOff;
    App_Model_B.INT_WPC2Warning = WPCWarningOff;
    App_Model_B.C_WPC2Warning = WPCWarningOff;
    App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;
    App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
    App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;
    App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
    App_Model_B.Output_PhoneLeftWarningWPC_i4ao = WPCWarningOff;
    App_Model_B.C_WPCWarning_dbwe = WPCWarningOff;
    App_Model_B.Output_WPCWarning_ltaw = WPCWarningOff;
    App_Model_B.C_WPCWarning_fnhu = WPCWarningOff;
    App_Model_B.Output_WPCWarning_eqd5 = WPCWarningOff;
    App_Model_B.C_WPCWarning_abjx = WPCWarningOff;
    App_Model_B.Output_PhoneLeftWarningWPC_jnov = WPCWarningOff;
    App_Model_B.BCAN_RX_C_WPCOnOffNvalueSet = WPC_On;
    App_Model_B.C_WPCRValue = WPC_On;
    App_Model_B.WPCSWOption = WPC_On;
    App_Model_B.RWPCSWOption = WPC_On;
    App_Model_B.C_RWPCRValue = WPC_On;
    App_Model_B.BCAN_RX_C_WPCOnOffNvalueSe_ehax = WPC_On;
    App_Model_B.BCAN_RX_C_WPC2OnOffNvalueSet = WPC_On;
    App_Model_B.WPC2RValue = WPC_On;
    App_Model_B.WPC2SWOption = WPC_On;
    App_Model_B.WPCRValue = WPC_On;
    App_Model_B.WPCSWOption_oxhs = WPC_On;
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
    App_Model_B.BCAN_RX_C_USMReset = USMDefault;
    App_Model_B.BCAN_RX_C_USMReset_n3bg = USMDefault;
    App_Model_B.BCAN_RX_RheoStatLevel = RheoReserved;
    App_Model_B.BCAN_RX_RheoStatLevel_g4ba = RheoReserved;
    App_Model_B.BCAN_RX_RheoStatLevel_p5hv = RheoReserved;
    App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal = ProfileC_ProfileIDRValueDefault;
    App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu = ProfileC_ProfileIDRValueDefault;
    App_Model_B.CurProfile = ProfileC_ProfileIDRValueDefault;
    App_Model_B.BCAN_RX_C_IAU_ProfileIDRVa_dt1p = ProfileC_ProfileIDRValueDefault;
    App_Model_B.BCAN_RX_C_CF_AVN_ProfileID_lmko = ProfileC_ProfileIDRValueDefault;
    App_Model_B.CurProfile_md3a = ProfileC_ProfileIDRValueDefault;
    App_Model_B.BCAN_RX_C_AutoBrightLevel = Step13;
    App_Model_B.BCAN_RX_C_AutoBrightLevel_bziq = Step13;
    App_Model_B.BCAN_RX_C_AutoBrightLevel_m1oc = Step13;
    App_Model_B.NvM_IndUSMOption = Off;
    App_Model_B.ADC_IGN1_IN = Off;
    App_Model_B.BCAN_RX_C_LFAnt_SrchSta = Off;
    App_Model_B.BCAN_RX_C_BCM_SmkOptTyp = Off;
    App_Model_B.NFC1_LPCD_Wakeup = Off;
    App_Model_B.UART_WPC1_PhoneLeft = Off;
    App_Model_B.UART_WPC1_Temp_SnsrError = Off;
    App_Model_B.INT_b_CmdAmberSync_SWPC = Off;
    App_Model_B.INT_b_SyncAmber_SWPC = Off;
    App_Model_B.INT_SWPC_b_PhnLeftChk_Enable = Off;
    App_Model_B.b_AstDrSw = Off;
    App_Model_B.b_DrvDrSw = Off;
    App_Model_B.b_RLDrSw = Off;
    App_Model_B.b_RRDrSw = Off;
    App_Model_B.b_PhnLeftChk_Enable = Off;
    App_Model_B.b_FANModeCmd = Off;
    App_Model_B.b_GreenINDCmd = Off;
    App_Model_B.b_AmberINDCmd = Off;
    App_Model_B.b_BlinkState = Off;
    App_Model_B.b_ChargingEnable = Off;
    App_Model_B.Output_OPT_b_FANModeCmd = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd = Off;
    App_Model_B.Output_OPT_b_BlinkState = Off;
    App_Model_B.b_ChargingEnable_huiu = Off;
    App_Model_B.b_PhnLeftChk_Enable_cimn = Off;
    App_Model_B.b_FANModeCmd_ixvd = Off;
    App_Model_B.b_GreenINDCmd_nknt = Off;
    App_Model_B.b_AmberINDCmd_etta = Off;
    App_Model_B.b_BlinkState_nmq0 = Off;
    App_Model_B.b_ChargingEnable_bstx = Off;
    App_Model_B.b_PhnLeftChk_Enable_k4pd = Off;
    App_Model_B.Output_OPT_b_FANModeCmd_p5lq = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_coja = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_oela = Off;
    App_Model_B.Output_OPT_b_BlinkState_f0dr = Off;
    App_Model_B.b_ChargingEnable_nvnd = Off;
    App_Model_B.b_PhnLeftChk_Enable_hvh5 = Off;
    App_Model_B.b_FANModeCmd_gcqi = Off;
    App_Model_B.b_GreenINDCmd_c1er = Off;
    App_Model_B.b_AmberINDCmd_jnhz = Off;
    App_Model_B.b_BlinkState_epa5 = Off;
    App_Model_B.b_ChargingEnable_jd44 = Off;
    App_Model_B.b_PhnLeftChk_Enable_j1ju = Off;
    App_Model_B.b_TempSensorFault = Off;
    App_Model_B.b_LFState = Off;
    App_Model_B.b_TemperatureFault = Off;
    App_Model_B.b_CurrentFault = Off;
    App_Model_B.ADC_IGN1_IN_mp5r = Off;
    App_Model_B.BCAN_RX_C_LFAnt_SrchSta_jfhx = Off;
    App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_hvzq = Off;
    App_Model_B.UART_WPC1_PhoneLeft_j1xl = Off;
    App_Model_B.UART_WPC1_Temp_SnsrError_gw1i = Off;
    App_Model_B.INT_b_CmdAmberSync_RWPC = Off;
    App_Model_B.INT_b_SyncAmber_RWPC = Off;
    App_Model_B.b_AstDrSw_jy3e = Off;
    App_Model_B.b_DrvDrSw_kh5i = Off;
    App_Model_B.b_RLDrSw_jnn1 = Off;
    App_Model_B.b_RRDrSw_bczk = Off;
    App_Model_B.b_PhnLeftChk_Enable_cnhm = Off;
    App_Model_B.b_FANModeCmd_iroy = Off;
    App_Model_B.b_GreenINDCmd_lsi0 = Off;
    App_Model_B.b_AmberINDCmd_cdgi = Off;
    App_Model_B.b_BlinkState_k1bt = Off;
    App_Model_B.b_ChargingEnable_m33x = Off;
    App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
    App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
    App_Model_B.b_ChargingEnable_kg0a = Off;
    App_Model_B.b_PhnLeftChk_Enable_emma = Off;
    App_Model_B.b_FANModeCmd_l0dm = Off;
    App_Model_B.b_GreenINDCmd_esxl = Off;
    App_Model_B.b_AmberINDCmd_ptyk = Off;
    App_Model_B.b_BlinkState_jzug = Off;
    App_Model_B.b_ChargingEnable_eht5 = Off;
    App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
    App_Model_B.b_TempSensorFault_h5jx = Off;
    App_Model_B.b_LFState_o4ks = Off;
    App_Model_B.b_TemperatureFault_iak5 = Off;
    App_Model_B.b_CurrentFault_p1jy = Off;
    App_Model_B.NvM_IndUSMOption_kile = Off;
    App_Model_B.ADC_IGN1_IN_njed = Off;
    App_Model_B.BCAN_RX_C_LFAnt_SrchSta_enma = Off;
    App_Model_B.BCAN_RX_C_BCM_SmkOptTyp_a4ib = Off;
    App_Model_B.UART_WPC1_PhoneLeft_lmgd = Off;
    App_Model_B.UART_WPC1_Temp_SnsrError_n1or = Off;
    App_Model_B.INT_b_CmdLEDSync_WPC1 = Off;
    App_Model_B.INT_b_SyncLED_WPC1 = Off;
    App_Model_B.INT_WPC1_b_PhnLeftChk_Enable = Off;
    App_Model_B.INT_Jdg_NfcOnthepad = Off;
    App_Model_B.INT_Jdg_ChargingOnthepad = Off;
    App_Model_B.INT_Jdg_ObjectOnthepad = Off;
    App_Model_B.UART_WPC2_PhoneLeft = Off;
    App_Model_B.UART_WPC2_Temp_SnsrError = Off;
    App_Model_B.INT_b_CmdLEDSync_WPC2 = Off;
    App_Model_B.INT_b_SyncLED_WPC2 = Off;
    App_Model_B.INT_WPC2_b_PhnLeftChk_Enable = Off;
    App_Model_B.b_AstDrSw_c4ax = Off;
    App_Model_B.b_DrvDrSw_m4ht = Off;
    App_Model_B.b_RLDrSw_m3r3 = Off;
    App_Model_B.b_RRDrSw_cbkj = Off;
    App_Model_B.Var_WPC1PreAct = Off;
    App_Model_B.Var_WPC2PreAct = Off;
    App_Model_B.Var_WPC1PreAct_bgn2 = Off;
    App_Model_B.Var_WPC2PreAct_dlkp = Off;
    App_Model_B.b_PhnLeftChk_Enable_m2kv = Off;
    App_Model_B.b_FANModeCmd_e52k = Off;
    App_Model_B.b_GreenINDCmd_pkht = Off;
    App_Model_B.b_AmberINDCmd_lyff = Off;
    App_Model_B.b_BlinkState_ly2p = Off;
    App_Model_B.b_ChargingEnable_lkuy = Off;
    App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
    App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
    App_Model_B.b_ChargingEnable_anij = Off;
    App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
    App_Model_B.b_FANModeCmd_bint = Off;
    App_Model_B.b_GreenINDCmd_mwno = Off;
    App_Model_B.b_AmberINDCmd_m25s = Off;
    App_Model_B.b_BlinkState_mtzh = Off;
    App_Model_B.b_ChargingEnable_ovqe = Off;
    App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
    App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
    App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
    App_Model_B.b_ChargingEnable_iqlw = Off;
    App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
    App_Model_B.b_FANModeCmd_evyn = Off;
    App_Model_B.b_GreenINDCmd_otki = Off;
    App_Model_B.b_AmberINDCmd_a4kq = Off;
    App_Model_B.b_BlinkState_pir3 = Off;
    App_Model_B.b_ChargingEnable_ith1 = Off;
    App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
    App_Model_B.b_TempSensorFault_futc = Off;
    App_Model_B.b_LFState_kucz = Off;
    App_Model_B.b_TemperatureFault_fxyc = Off;
    App_Model_B.b_CurrentFault_kptm = Off;
    App_Model_B.b_PhnLeftChk_Enable_lemt = Off;
    App_Model_B.b_FANModeCmd_jg30 = Off;
    App_Model_B.b_GreenINDCmd_e5lz = Off;
    App_Model_B.b_AmberINDCmd_ldjg = Off;
    App_Model_B.b_BlinkState_duuz = Off;
    App_Model_B.b_ChargingEnable_f5ak = Off;
    App_Model_B.Output_OPT_b_FANModeCmd_k23k = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_axpq = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_jeww = Off;
    App_Model_B.Output_OPT_b_BlinkState_egfi = Off;
    App_Model_B.b_ChargingEnable_dbhd = Off;
    App_Model_B.b_PhnLeftChk_Enable_hrqc = Off;
    App_Model_B.b_FANModeCmd_oa2p = Off;
    App_Model_B.b_GreenINDCmd_f4jf = Off;
    App_Model_B.b_AmberINDCmd_b4wu = Off;
    App_Model_B.b_BlinkState_ofpx = Off;
    App_Model_B.b_ChargingEnable_n0zl = Off;
    App_Model_B.b_PhnLeftChk_Enable_cnve = Off;
    App_Model_B.Output_OPT_b_FANModeCmd_cl1i = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_j1ge = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_imzc = Off;
    App_Model_B.Output_OPT_b_BlinkState_cn4e = Off;
    App_Model_B.b_ChargingEnable_jtx4 = Off;
    App_Model_B.b_PhnLeftChk_Enable_gcof = Off;
    App_Model_B.b_FANModeCmd_oklr = Off;
    App_Model_B.b_GreenINDCmd_dnef = Off;
    App_Model_B.b_AmberINDCmd_cmmc = Off;
    App_Model_B.b_BlinkState_gbtl = Off;
    App_Model_B.b_ChargingEnable_otie = Off;
    App_Model_B.b_PhnLeftChk_Enable_oxbc = Off;
    App_Model_B.b_TempSensorFault_ahdl = Off;
    App_Model_B.b_LFState_fv4t = Off;
    App_Model_B.b_TemperatureFault_c04g = Off;
    App_Model_B.b_CurrentFault_jcbo = Off;
    App_Model_B.BlinkState_i5ti = BlinkOff;
    App_Model_B.Output_BlinkState = BlinkOff;
    App_Model_B.BlinkState_hzlt = BlinkOff;
    App_Model_B.Output_BlinkState_jxzf = BlinkOff;
    App_Model_B.BlinkState_avg4 = BlinkOff;
    App_Model_B.BlinkState_ouyp = BlinkOff;
    App_Model_B.Output_BlinkState_mkqq = BlinkOff;
    App_Model_B.BlinkState_dn5g = BlinkOff;
    App_Model_B.BlinkState_nwlq = BlinkOff;
    App_Model_B.Output_BlinkState_dygi = BlinkOff;
    App_Model_B.BlinkState_izow = BlinkOff;
    App_Model_B.Output_BlinkState_kepa = BlinkOff;
    App_Model_B.BlinkState_gx2f = BlinkOff;
    App_Model_B.BlinkState_pber = BlinkOff;
    App_Model_B.Output_BlinkState_djmk = BlinkOff;
    App_Model_B.BlinkState_e1cz = BlinkOff;
    App_Model_B.Output_BlinkState_alue = BlinkOff;
    App_Model_B.BlinkState_axn0 = BlinkOff;
  }

  /* states (dwork) */
  (void) memset((void *)&App_Model_DW, 0,
                sizeof(DW_App_Model_T));

  /* exported global states */
  Par_AutoBrightLevel001 = 0U;
  Par_AutoBrightLevel002 = 0U;
  Par_AutoBrightLevel003 = 0U;
  Par_AutoBrightLevel004 = 0U;
  Par_AutoBrightLevel005 = 0U;
  Par_AutoBrightLevel006 = 0U;
  Par_AutoBrightLevel007 = 0U;
  Par_AutoBrightLevel008 = 0U;
  Par_AutoBrightLevel009 = 0U;
  Par_AutoBrightLevel010 = 0U;
  Par_AutoBrightLevel011 = 0U;
  Par_AutoBrightLevel012 = 0U;
  Par_AutoBrightLevel013 = 0U;
  Par_AutoBrightLevel014 = 0U;
  Par_AutoBrightLevel015 = 0U;
  Par_AutoBrightLevel016 = 0U;
  Par_AutoBrightLevel017 = 0U;
  Par_AutoBrightLevel018 = 0U;
  Par_AutoBrightLevel019 = 0U;
  Par_AutoBrightLevel020 = 0U;
  Par_AutoBrightLevel021 = 0U;
  Par_AutoBrightLevel022 = 0U;
  Par_AutoBrightLevel023 = 0U;
  Par_AutoBrightLevel024 = 0U;
  Par_AutoBrightLevel025 = 0U;
  Par_AutoBrightLevel026 = 0U;
  Par_AutoBrightLevel027 = 0U;
  Par_AutoBrightLevel028 = 0U;
  Par_AutoBrightLevel029 = 0U;
  Par_AutoBrightLevel030 = 0U;
  Par_AutoBrightLevel031 = 0U;
  Par_AutoBrightLevel032 = 0U;
  Par_AutoBrightLevel033 = 0U;
  Par_AutoBrightLevel034 = 0U;
  Par_AutoBrightLevel035 = 0U;
  Par_AutoBrightLevel036 = 0U;
  Par_AutoBrightLevel037 = 0U;
  Par_AutoBrightLevel038 = 0U;
  Par_AutoBrightLevel039 = 0U;
  Par_AutoBrightLevel040 = 0U;
  Par_AutoBrightLevel041 = 0U;
  Par_AutoBrightLevel042 = 0U;
  Par_AutoBrightLevel043 = 0U;
  Par_AutoBrightLevel044 = 0U;
  Par_AutoBrightLevel045 = 0U;
  Par_AutoBrightLevel046 = 0U;
  Par_AutoBrightLevel047 = 0U;
  Par_AutoBrightLevel048 = 0U;
  Par_AutoBrightLevel049 = 0U;
  Par_AutoBrightLevel050 = 0U;
  Par_AutoBrightLevel051 = 0U;
  Par_AutoBrightLevel052 = 0U;
  Par_AutoBrightLevel053 = 0U;
  Par_AutoBrightLevel054 = 0U;
  Par_AutoBrightLevel055 = 0U;
  Par_AutoBrightLevel056 = 0U;
  Par_AutoBrightLevel057 = 0U;
  Par_AutoBrightLevel058 = 0U;
  Par_AutoBrightLevel059 = 0U;
  Par_AutoBrightLevel060 = 0U;
  Par_AutoBrightLevel061 = 0U;
  Par_AutoBrightLevel062 = 0U;
  Par_AutoBrightLevel063 = 0U;
  Par_AutoBrightLevel064 = 0U;
  Par_AutoBrightLevel065 = 0U;
  Par_AutoBrightLevel066 = 0U;
  Par_AutoBrightLevel067 = 0U;
  Par_AutoBrightLevel068 = 0U;
  Par_AutoBrightLevel069 = 0U;
  Par_AutoBrightLevel070 = 0U;
  Par_AutoBrightLevel071 = 0U;
  Par_AutoBrightLevel072 = 0U;
  Par_AutoBrightLevel073 = 0U;
  Par_AutoBrightLevel074 = 0U;
  Par_AutoBrightLevel075 = 0U;
  Par_AutoBrightLevel076 = 0U;
  Par_AutoBrightLevel077 = 0U;
  Par_AutoBrightLevel078 = 0U;
  Par_AutoBrightLevel079 = 0U;
  Par_AutoBrightLevel080 = 0U;
  Par_AutoBrightLevel081 = 0U;
  Par_AutoBrightLevel082 = 0U;
  Par_AutoBrightLevel083 = 0U;
  Par_AutoBrightLevel084 = 0U;
  Par_AutoBrightLevel085 = 0U;
  Par_AutoBrightLevel086 = 0U;
  Par_AutoBrightLevel087 = 0U;
  Par_AutoBrightLevel088 = 0U;
  Par_AutoBrightLevel089 = 0U;
  Par_AutoBrightLevel090 = 0U;
  Par_AutoBrightLevel091 = 0U;
  Par_RheostatBrightLevel00 = 0U;
  Par_RheostatBrightLevel01 = 0U;
  Par_RheostatBrightLevel02 = 0U;
  Par_RheostatBrightLevel03 = 0U;
  Par_RheostatBrightLevel04 = 0U;
  Par_RheostatBrightLevel05 = 0U;
  Par_RheostatBrightLevel06 = 0U;
  Par_RheostatBrightLevel07 = 0U;
  Par_RheostatBrightLevel08 = 0U;
  Par_RheostatBrightLevel09 = 0U;
  Par_RheostatBrightLevel10 = 0U;
  Par_RheostatBrightLevel11 = 0U;
  Par_RheostatBrightLevel12 = 0U;
  Par_RheostatBrightLevel13 = 0U;
  Par_RheostatBrightLevel14 = 0U;
  Par_RheostatBrightLevel15 = 0U;
  Par_RheostatBrightLevel16 = 0U;
  Par_RheostatBrightLevel17 = 0U;
  Par_RheostatBrightLevel18 = 0U;
  Par_RheostatBrightLevel19 = 0U;
  Par_RheostatBrightLevel20 = 0U;
  Par_RheostatBrightLevel21 = 0U;
  (void) memset(&m_AutoBrightLevelSet, 0,
                91U*sizeof(uint16));
  (void) memset(&m_RheostatBrightLevelSet, 0,
                22U*sizeof(uint16));
  m_ProfileGuestWPC2FanUSM_App = LowDuty;
  m_ProfileGuestWPCFanUSM_App = LowDuty;
  m_ProfileOneWPC2FanUSM_App = LowDuty;
  m_ProfileOneWPCFanUSM_App = LowDuty;
  m_ProfileThreeWPC2FanUSM_App = LowDuty;
  m_ProfileThreeWPCFanUSM_App = LowDuty;
  m_ProfileTwoWPC2FanUSM_App = LowDuty;
  m_ProfileTwoWPCFanUSM_App = LowDuty;
  m_RWPCFanUSM_App = LowDuty;
  m_ProfileGuestWPC2USM_App = WPC_On;
  m_ProfileGuestWPCUSM_App = WPC_On;
  m_ProfileOneWPC2USM_App = WPC_On;
  m_ProfileOneWPCUSM_App = WPC_On;
  m_ProfileThreeWPC2USM_App = WPC_On;
  m_ProfileThreeWPCUSM_App = WPC_On;
  m_ProfileTwoWPC2USM_App = WPC_On;
  m_ProfileTwoWPCUSM_App = WPC_On;
  m_RWPCUSM_App = WPC_On;
  m_WPCIndUSMState_Guest = WPCIndUSMState__Default;
  m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Default;
  m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Default;

  {
    /* local block i/o variables */
    uint16 rtb_FAN_PWM;
    uint16 rtb_FAN_PWM_eua1;
    uint16 rtb_FAN_PWM_luhf;
    uint16 rtb_FAN_PWM_kvyy;
    uint8 rtb_WPCMode_LPConditionFlag_wri;
    uint8 rtb_TempSnsrError_LPConditionFl;
    uint8 rtb_SMKLF_LPConditionFlag_write;
    uint8 rtb_OverTempDetect_LPConditionF;
    uint8 rtb_OverCurrent_LPConditionFlag;
    uint8 rtb_NFCMode_LPConditionFlag_wri;
    uint8 rtb_WPCMain_LPConditionFlag_wri;
    uint8 rtb_FAN_LPConditionFlag_write;
    uint8 rtb_WPCMode_LPConditionFla_hka2;
    uint8 rtb_TempSnsrError_LPCondit_oh14;
    uint8 rtb_SMKLF_LPConditionFlag__j4w3;
    uint8 rtb_OverTempDetect_LPCondi_a4lc;
    uint8 rtb_OverCurrent_LPConditio_hfnx;
    uint8 rtb_NFCMode_LPConditionFla_ogfp;
    uint8 rtb_WPCMain_LPConditionFla_nrse;
    uint8 rtb_FAN_LPConditionFlag_wr_okst;
    uint8 rtb_WPCMode_LPConditionFla_pady;
    uint8 rtb_TempSnsrError_LPCondit_egth;
    uint8 rtb_SMKLF_LPConditionFlag__fnej;
    uint8 rtb_OverTempDetect_LPCondi_bvam;
    uint8 rtb_OverCurrent_LPConditio_p4qh;
    uint8 rtb_NFCMode_LPConditionFla_jmfo;
    uint8 rtb_WPCMain_LPConditionFla_cfn0;
    uint8 rtb_FAN_LPConditionFlag_wr_ddyr;
    uint8 rtb_WPCMode_LPConditionFla_e5bi;
    uint8 rtb_TempSnsrError_LPCondit_lcr4;
    uint8 rtb_SMKLF_LPConditionFlag__edfo;
    uint8 rtb_OverTempDetect_LPCondi_l4hp;
    uint8 rtb_OverCurrent_LPConditio_ivuq;
    uint8 rtb_NFCMode_LPConditionFla_i45m;
    uint8 rtb_WPCMain_LPConditionFla_g2vh;
    uint8 rtb_FAN_LPConditionFlag_wr_djmc;
    Bool rtb_b_SyncAmber;
    Bool rtb_b_SyncAmber_jg2q;
    Bool rtb_b_SyncLED;
    Bool rtb_b_SyncLED_ipyt;
    WPCIndUSMState Output_INT_WPCIndUSMState;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel001' */
    Par_AutoBrightLevel001 = ((uint16)150U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel002' */
    Par_AutoBrightLevel002 = ((uint16)150U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel003' */
    Par_AutoBrightLevel003 = ((uint16)171U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel004' */
    Par_AutoBrightLevel004 = ((uint16)242U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel005' */
    Par_AutoBrightLevel005 = ((uint16)314U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel006' */
    Par_AutoBrightLevel006 = ((uint16)385U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel007' */
    Par_AutoBrightLevel007 = ((uint16)456U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel008' */
    Par_AutoBrightLevel008 = ((uint16)527U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel009' */
    Par_AutoBrightLevel009 = ((uint16)598U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel010' */
    Par_AutoBrightLevel010 = ((uint16)670U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel011' */
    Par_AutoBrightLevel011 = ((uint16)741U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel012' */
    Par_AutoBrightLevel012 = ((uint16)812U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel013' */
    Par_AutoBrightLevel013 = ((uint16)883U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel014' */
    Par_AutoBrightLevel014 = ((uint16)955U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel015' */
    Par_AutoBrightLevel015 = ((uint16)1026U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel016' */
    Par_AutoBrightLevel016 = ((uint16)1097U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel017' */
    Par_AutoBrightLevel017 = ((uint16)1168U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel018' */
    Par_AutoBrightLevel018 = ((uint16)1239U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel019' */
    Par_AutoBrightLevel019 = ((uint16)1311U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel020' */
    Par_AutoBrightLevel020 = ((uint16)1382U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel021' */
    Par_AutoBrightLevel021 = ((uint16)1453U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel022' */
    Par_AutoBrightLevel022 = ((uint16)1524U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel023' */
    Par_AutoBrightLevel023 = ((uint16)1595U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel024' */
    Par_AutoBrightLevel024 = ((uint16)1667U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel025' */
    Par_AutoBrightLevel025 = ((uint16)1692U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel026' */
    Par_AutoBrightLevel026 = ((uint16)1717U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel027' */
    Par_AutoBrightLevel027 = ((uint16)1742U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel028' */
    Par_AutoBrightLevel028 = ((uint16)1768U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel029' */
    Par_AutoBrightLevel029 = ((uint16)1793U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel030' */
    Par_AutoBrightLevel030 = ((uint16)1818U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel031' */
    Par_AutoBrightLevel031 = ((uint16)1843U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel032' */
    Par_AutoBrightLevel032 = ((uint16)1869U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel033' */
    Par_AutoBrightLevel033 = ((uint16)1894U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel034' */
    Par_AutoBrightLevel034 = ((uint16)1919U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel035' */
    Par_AutoBrightLevel035 = ((uint16)1944U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel036' */
    Par_AutoBrightLevel036 = ((uint16)1970U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel037' */
    Par_AutoBrightLevel037 = ((uint16)1995U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel038' */
    Par_AutoBrightLevel038 = ((uint16)2020U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel039' */
    Par_AutoBrightLevel039 = ((uint16)2045U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel040' */
    Par_AutoBrightLevel040 = ((uint16)2071U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel041' */
    Par_AutoBrightLevel041 = ((uint16)2096U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel042' */
    Par_AutoBrightLevel042 = ((uint16)2121U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel043' */
    Par_AutoBrightLevel043 = ((uint16)2146U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel044' */
    Par_AutoBrightLevel044 = ((uint16)2172U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel045' */
    Par_AutoBrightLevel045 = ((uint16)2197U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel046' */
    Par_AutoBrightLevel046 = ((uint16)2222U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel047' */
    Par_AutoBrightLevel047 = ((uint16)2247U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel048' */
    Par_AutoBrightLevel048 = ((uint16)2273U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel049' */
    Par_AutoBrightLevel049 = ((uint16)2298U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel050' */
    Par_AutoBrightLevel050 = ((uint16)2323U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel051' */
    Par_AutoBrightLevel051 = ((uint16)2348U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel052' */
    Par_AutoBrightLevel052 = ((uint16)2374U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel053' */
    Par_AutoBrightLevel053 = ((uint16)2399U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel054' */
    Par_AutoBrightLevel054 = ((uint16)2424U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel055' */
    Par_AutoBrightLevel055 = ((uint16)2449U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel056' */
    Par_AutoBrightLevel056 = ((uint16)2475U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel057' */
    Par_AutoBrightLevel057 = ((uint16)2500U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel058' */
    Par_AutoBrightLevel058 = ((uint16)2525U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel059' */
    Par_AutoBrightLevel059 = ((uint16)2551U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel060' */
    Par_AutoBrightLevel060 = ((uint16)2576U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel061' */
    Par_AutoBrightLevel061 = ((uint16)2601U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel062' */
    Par_AutoBrightLevel062 = ((uint16)2626U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel063' */
    Par_AutoBrightLevel063 = ((uint16)2652U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel064' */
    Par_AutoBrightLevel064 = ((uint16)2677U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel065' */
    Par_AutoBrightLevel065 = ((uint16)2702U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel066' */
    Par_AutoBrightLevel066 = ((uint16)2727U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel067' */
    Par_AutoBrightLevel067 = ((uint16)2753U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel068' */
    Par_AutoBrightLevel068 = ((uint16)2778U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel069' */
    Par_AutoBrightLevel069 = ((uint16)2803U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel070' */
    Par_AutoBrightLevel070 = ((uint16)2828U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel071' */
    Par_AutoBrightLevel071 = ((uint16)2854U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel072' */
    Par_AutoBrightLevel072 = ((uint16)2879U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel073' */
    Par_AutoBrightLevel073 = ((uint16)2904U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel074' */
    Par_AutoBrightLevel074 = ((uint16)2929U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel075' */
    Par_AutoBrightLevel075 = ((uint16)2955U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel076' */
    Par_AutoBrightLevel076 = ((uint16)2980U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel077' */
    Par_AutoBrightLevel077 = ((uint16)3005U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel078' */
    Par_AutoBrightLevel078 = ((uint16)3030U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel079' */
    Par_AutoBrightLevel079 = ((uint16)3056U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel080' */
    Par_AutoBrightLevel080 = ((uint16)3081U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel081' */
    Par_AutoBrightLevel081 = ((uint16)3106U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel082' */
    Par_AutoBrightLevel082 = ((uint16)3131U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel083' */
    Par_AutoBrightLevel083 = ((uint16)3157U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel084' */
    Par_AutoBrightLevel084 = ((uint16)3182U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel085' */
    Par_AutoBrightLevel085 = ((uint16)3207U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel086' */
    Par_AutoBrightLevel086 = ((uint16)3232U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel087' */
    Par_AutoBrightLevel087 = ((uint16)3258U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel088' */
    Par_AutoBrightLevel088 = ((uint16)3283U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel089' */
    Par_AutoBrightLevel089 = ((uint16)3308U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel090' */
    Par_AutoBrightLevel090 = ((uint16)3333U);

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel091' */
    Par_AutoBrightLevel091 = ((uint16)10000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel00' */
    Par_RheostatBrightLevel00 = ((uint16)10000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel01' */
    Par_RheostatBrightLevel01 = ((uint16)300U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel02' */
    Par_RheostatBrightLevel02 = ((uint16)500U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel03' */
    Par_RheostatBrightLevel03 = ((uint16)750U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel04' */
    Par_RheostatBrightLevel04 = ((uint16)1000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel05' */
    Par_RheostatBrightLevel05 = ((uint16)1250U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel06' */
    Par_RheostatBrightLevel06 = ((uint16)1500U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel07' */
    Par_RheostatBrightLevel07 = ((uint16)1750U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel08' */
    Par_RheostatBrightLevel08 = ((uint16)2000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel09' */
    Par_RheostatBrightLevel09 = ((uint16)2250U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel10' */
    Par_RheostatBrightLevel10 = ((uint16)2500U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel11' */
    Par_RheostatBrightLevel11 = ((uint16)2750U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel12' */
    Par_RheostatBrightLevel12 = ((uint16)3000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel13' */
    Par_RheostatBrightLevel13 = ((uint16)3250U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel14' */
    Par_RheostatBrightLevel14 = ((uint16)3500U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel15' */
    Par_RheostatBrightLevel15 = ((uint16)3750U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel16' */
    Par_RheostatBrightLevel16 = ((uint16)4000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel17' */
    Par_RheostatBrightLevel17 = ((uint16)4250U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel18' */
    Par_RheostatBrightLevel18 = ((uint16)4500U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel19' */
    Par_RheostatBrightLevel19 = ((uint16)4750U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel20' */
    Par_RheostatBrightLevel20 = ((uint16)5000U);

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel21' */
    Par_RheostatBrightLevel21 = ((uint16)10000U);

    /* Start for DataStoreMemory: '<Root>/m_ProfileGuestWPC2FanUSM_App' */
    m_ProfileGuestWPC2FanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App' */
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileGuestWPCFanUSM_App' */
    m_ProfileGuestWPCFanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileGuestWPCUSM_App' */
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileOneWPC2FanUSM_App' */
    m_ProfileOneWPC2FanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileOneWPC2USM_App' */
    m_ProfileOneWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileOneWPCFanUSM_App' */
    m_ProfileOneWPCFanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileOneWPCUSM_App' */
    m_ProfileOneWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileThreeWPC2FanUSM_App' */
    m_ProfileThreeWPC2FanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileThreeWPC2USM_App' */
    m_ProfileThreeWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileThreeWPCFanUSM_App' */
    m_ProfileThreeWPCFanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileThreeWPCUSM_App' */
    m_ProfileThreeWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileTwoWPC2FanUSM_App' */
    m_ProfileTwoWPC2FanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileTwoWPC2USM_App' */
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileTwoWPCFanUSM_App' */
    m_ProfileTwoWPCFanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_ProfileTwoWPCUSM_App' */
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_RWPCFanUSM_App' */
    m_RWPCFanUSM_App = LowDuty;

    /* Start for DataStoreMemory: '<Root>/m_RWPCUSM_App' */
    m_RWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_WPCIndUSMState_Guest' */
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type2;

    /* Start for DataStoreMemory: '<Root>/m_WPCIndUSMState_ProfileOne' */
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type2;

    /* Start for DataStoreMemory: '<Root>/m_WPCIndUSMState_ProfileTwo' */
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type2;

    /* SystemInitialize for Triggered SubSystem: '<Root>/AppInit_DataRead' */
    App_Model_AppInit_DataRead_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/AppInit_DataRead' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/App_Model_TE_Sys' */
    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay' */
    App_Model_DW.UnitDelay_DSTATE_d0ul = WPCIndUSMState__Default;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay2' */
    App_Model_DW.UnitDelay2_DSTATE = WPC2IndSyncVal__Default;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay4' */
    App_Model_DW.UnitDelay4_DSTATE_kskc = WPCIndCmdState__Default;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay5' */
    App_Model_DW.UnitDelay5_DSTATE = WPC2IndCmdState__Default;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay9' */
    App_Model_DW.UnitDelay9_DSTATE_afvw = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay10' */
    App_Model_DW.UnitDelay10_DSTATE_ijjh = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay13' */
    App_Model_DW.UnitDelay13_DSTATE = PreSyncAct__Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay15' */
    App_Model_DW.UnitDelay15_DSTATE_kgaf = WPCWarningOff;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay7' */
    App_Model_DW.UnitDelay7_DSTATE_m4bk = ModeOff;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay8' */
    App_Model_DW.UnitDelay8_DSTATE = ((uint8)0U);

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay17' */
    App_Model_DW.UnitDelay17_DSTATE = ((uint8)0U);

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay18' */
    App_Model_DW.UnitDelay18_DSTATE_ghv5 = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay20' */
    App_Model_DW.UnitDelay20_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay21' */
    App_Model_DW.UnitDelay21_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay6' */
    App_Model_DW.UnitDelay6_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay1' */
    App_Model_DW.UnitDelay1_DSTATE = WPCIndSyncVal__Default;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay11' */
    App_Model_DW.UnitDelay11_DSTATE_ibvb = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay12' */
    App_Model_DW.UnitDelay12_DSTATE_kt23 = Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay14' */
    App_Model_DW.UnitDelay14_DSTATE = PreSyncAct__Off;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay16' */
    App_Model_DW.UnitDelay16_DSTATE_fcip = WPCWarningOff;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay3' */
    App_Model_DW.UnitDelay3_DSTATE_lcrf = ModeOff;

    /* InitializeConditions for UnitDelay: '<S431>/Unit Delay19' */
    App_Model_DW.UnitDelay19_DSTATE_oefu = Off;

    /* SystemInitialize for Chart: '<S427>/DoorOpenCloseStateFunctionFlowGraph' */
    DoorOpenCloseStateFunction_Init(&App_Model_B.b_AstDrSw_c4ax, &App_Model_B.b_DrvDrSw_m4ht, &App_Model_B.b_RLDrSw_m3r3, &App_Model_B.b_RRDrSw_cbkj, &App_Model_DW.sf_DoorOpenCloseStateFunctionFl);

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S19>/USMSettingControl_Function' */
    USMSettingControl_Function_Init(&App_Model_B.WPCRValue, &App_Model_B.WPCSWOption_oxhs);

    /* End of SystemInitialize for SubSystem: '<S19>/USMSettingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/NFC_WPC_Mode_Control_Function' */
    NFC_WPC_Mode_Control_Funct_Init(&App_Model_B.WPCStatus_hv2c);

    /* End of SystemInitialize for SubSystem: '<S23>/NFC_WPC_Mode_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/TemperatureSensorErrorDetect_Function' */
    TemperatureSensorErro_lwl5_Init(&App_Model_B.b_TempSensorFault_ahdl, &App_Model_B.b_Timer_TempSensor_Check_dej2);

    /* End of SystemInitialize for SubSystem: '<S23>/TemperatureSensorErrorDetect_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/PreventionSMK_LF_Interference_Function' */
    PreventionSMK_LF_Inte_klhw_Init(&App_Model_B.b_LFState_fv4t);

    /* End of SystemInitialize for SubSystem: '<S23>/PreventionSMK_LF_Interference_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/OverCurrentDetecting_Function' */
    OverCurrentDetecting_Funct_Init(&App_Model_B.b_CurrentFault_jcbo, &App_Model_B.b_Timer_OvrCurr_dt5l, &App_Model_B.b_Timer_ReOvrCurr_dylv);

    /* End of SystemInitialize for SubSystem: '<S23>/OverCurrentDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/OverTemperatureDetecting_Function' */
    OverTemperatureDetecting_F_Init(&App_Model_B.b_TemperatureFault_c04g, &App_Model_B.b_Timer_OverTemp_p3xh);

    /* End of SystemInitialize for SubSystem: '<S23>/OverTemperatureDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectin_fcrj_Init(&App_Model_B.Output_PhoneLeftWarningWPC_jnov);

    /* End of SystemInitialize for SubSystem: '<S23>/WPC_PhoneLeftDetectingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S19>/WPC_MainControl_Function' */
    A_WPC_MainControl_Function_Init(&App_Model_B.C_WPCWarning_dbwe, &App_Model_B.b_FANModeCmd_jg30, &App_Model_B.b_GreenINDCmd_e5lz, &App_Model_B.b_AmberINDCmd_ldjg, &App_Model_B.b_BlinkState_duuz,
      &App_Model_B.b_Timer_PhoneReminderCheck_mh5z, &App_Model_B.b_Timer_PhoneWarningCheck_ajyk, &App_Model_B.b_Timer_WarningComplete_expw, &App_Model_B.b_ChargingEnable_f5ak,
      &App_Model_B.BlinkState_pber, &App_Model_B.b_PhnLeftChk_Enable_lemt, &App_Model_B.b_Timer_WarningTypeCheck_cenb);

    /* End of SystemInitialize for SubSystem: '<S19>/WPC_MainControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S22>/FAN_Control_Function' */
    App_M_FAN_Control_Function_Init(&rtb_FAN_PWM_kvyy, &App_Model_B.FANDutyRatioSta_lwkf);

    /* End of SystemInitialize for SubSystem: '<S22>/FAN_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* SystemInitialize for Chart: '<S35>/RWPC_IND_Command_State_Control_Function_State_Chart' */
    RWPC_IND_Command_State_Con_Init(&App_Model_B.Var_RWPCIndCmdState_mh2c, &App_Model_DW.sf_RWPC_IND_Command_State_Contr);

    /* SystemInitialize for Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step' */
    App_Model_DW.sfEvent_oqhy = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDFadeIn_oxbo = 0U;
    App_Model_DW.is_INDFadeIn_jkbd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDFadeOut_khxa = 0U;
    App_Model_DW.is_INDFadeOut_crlr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDLight_j5kt = 0U;
    App_Model_DW.is_INDLight_ajwi = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_IND_Animation_Sy_bgeh = 0U;
    App_Model_DW.is_IND_Animation_Sync_Cont_mfvz = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimation_Chargin_kod1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_gru2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_pkee = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_lvlw = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_aj4v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimation_Error_fh0i = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c197_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDLight_jkqo = 0U;
    App_Model_DW.Timer_INDFadeIn_bp2v = 0U;
    App_Model_DW.Timer_INDFadeOut_bvej = 0U;
    App_Model_B.Output_CAN_WPCIndSyncVal_i4yx = WPCIndSyncVal__Default;
    App_Model_B.Output_INT_WPCIndCmdState_ca53 = WPCIndCmdState__Default;
    App_Model_DW.Var_PreSyncAct_prev_nho5 = PreSyncAct__Off;
    App_Model_DW.Var_PreSyncAct_start_b2ke = PreSyncAct__Off;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_p_pwgh = RWPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_s_nnsr = RWPCIndSyncVal__Default;
    App_Model_DW.Var_INT_RWPCIndCmdState_pr_pexg = RWPCIndCmdState__Default;
    App_Model_DW.Var_INT_RWPCIndCmdState_st_ltqc = RWPCIndCmdState__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_p_c3v4 = WPC2IndSyncVal__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_s_pfdf = WPC2IndSyncVal__Default;
    App_Model_DW.Var_INT_WPC2IndCmdState_pr_hfp5 = WPC2IndCmdState__Default;
    App_Model_DW.Var_INT_WPC2IndCmdState_st_fxkz = WPC2IndCmdState__Default;
    App_Model_DW.WPCIndUSMState_prev_mwgm = WPCIndUSMState__Default;
    App_Model_DW.WPCIndUSMState_start_cume = WPCIndUSMState__Default;
    App_Model_DW.b_SyncAmber_prev_h2yl = Off;
    App_Model_DW.b_SyncAmber_start_hpuj = Off;

    /* SystemInitialize for Chart: '<S39>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
    IND_Animation_Profile_Deci_Init(&App_Model_B.CurProfile_md3a, &App_Model_DW.sf_IND_Animation_Profile_Decisi);

    /* SystemInitialize for Chart: '<S39>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    IND_Animation_USM_Setting__Init(&App_Model_B.Output_CAN_WPCIndUSMState_kprv, &App_Model_B.Output_INT_WPCIndUSMState_bcrl, &App_Model_DW.sf_IND_Animation_USM_Setting_Co);

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S22>/IndyOutputControl_Function' */
    IndyOutputControl_Function_Init(&App_Model_B.P_GreenIND_OUT_c12b, &App_Model_B.P_GreenIND2_OUT_dniy, &App_Model_B.P_GreenIND3_OUT_oayi, &App_Model_B.P_AmberIND_OUT_j3u5);

    /* End of SystemInitialize for SubSystem: '<S22>/IndyOutputControl_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC2_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S20>/USMSettingControl_Function' */
    USMSettingControl_Fun_dunh_Init(&App_Model_B.WPC2RValue, &App_Model_B.WPC2SWOption);

    /* End of SystemInitialize for SubSystem: '<S20>/USMSettingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S218>/NFC_WPC_Mode_Control_Function' */
    NFC_WPC_Mode_Control__dr2c_Init(&App_Model_B.WPC2Status);

    /* End of SystemInitialize for SubSystem: '<S218>/NFC_WPC_Mode_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S218>/TemperatureSensorErrorDetect_Function' */
    TemperatureSensorErro_lytz_Init(&App_Model_B.b_TempSensorFault_futc, &App_Model_B.b_Timer_TempSensor_Check_eer0);

    /* End of SystemInitialize for SubSystem: '<S218>/TemperatureSensorErrorDetect_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S218>/PreventionSMK_LF_Interference_Function' */
    PreventionSMK_LF_Inte_ggwa_Init(&App_Model_B.b_LFState_kucz);

    /* End of SystemInitialize for SubSystem: '<S218>/PreventionSMK_LF_Interference_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S218>/OverCurrentDetecting_Function' */
    OverCurrentDetecting__bnpf_Init(&App_Model_B.b_CurrentFault_kptm, &App_Model_B.b_Timer_OvrCurr_bvyp, &App_Model_B.b_Timer_ReOvrCurr_gm1e);

    /* End of SystemInitialize for SubSystem: '<S218>/OverCurrentDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S218>/OverTemperatureDetecting_Function' */
    OverTemperatureDetect_hzjw_Init(&App_Model_B.b_TemperatureFault_fxyc, &App_Model_B.b_Timer_OverTemp_ce1w);

    /* End of SystemInitialize for SubSystem: '<S218>/OverTemperatureDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S218>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectin_ee2l_Init(&App_Model_B.Output_PhoneLeftWarningWPC_i4ao);

    /* End of SystemInitialize for SubSystem: '<S218>/WPC_PhoneLeftDetectingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S20>/WPC_MainControl_Function' */
    WPC_MainControl_Funct_cp2h_Init(&App_Model_B.C_WPC2Warning, &App_Model_B.b_FANModeCmd_e52k, &App_Model_B.b_GreenINDCmd_pkht, &App_Model_B.b_AmberINDCmd_lyff, &App_Model_B.b_BlinkState_ly2p,
      &App_Model_B.b_Timer_PhoneReminderCheck_mflq, &App_Model_B.b_Timer_PhoneWarningCheck_o0i3, &App_Model_B.b_Timer_WarningComplete_ghdo, &App_Model_B.b_ChargingEnable_lkuy,
      &App_Model_B.BlinkState_nwlq, &App_Model_B.b_PhnLeftChk_Enable_m2kv, &App_Model_B.b_Timer_WarningTypeCheck_i40f);

    /* End of SystemInitialize for SubSystem: '<S20>/WPC_MainControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S217>/FAN_Control_Function' */
    FAN_Control_Function_hj2b_Init(&rtb_FAN_PWM_luhf, &App_Model_B.FANDutyRatioSta_acxf);

    /* End of SystemInitialize for SubSystem: '<S217>/FAN_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S217>/IND_Animation_Control_Function' */
    /* SystemInitialize for Chart: '<S229>/RWPC_IND_Command_State_Control_Function_State_Chart' */
    RWPC_IND_Command_State_Con_Init(&App_Model_B.Var_RWPCIndCmdState, &App_Model_DW.sf_RWPC_IND_Command_State__b4zd);

    /* SystemInitialize for Chart: '<S229>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_j1hu = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDFadeIn_iojc = 0U;
    App_Model_DW.is_INDFadeIn_gyzm = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDFadeOut_jiqg = 0U;
    App_Model_DW.is_INDFadeOut_pilc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDLight_jxx1 = 0U;
    App_Model_DW.is_INDLight_jzsv = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_IND_Animation_Sy_mfd1 = 0U;
    App_Model_DW.is_IND_Animation_Sync_Cont_jvqw = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_p2e5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c200_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDLight_pm1y = 0U;
    App_Model_DW.Timer_INDFadeIn_kzsy = 0U;
    App_Model_DW.Timer_INDFadeOut_cnjl = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Output_CAN_WPC2IndSyncVal = WPC2IndSyncVal__Default;
    App_Model_B.Output_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_DW.Var_PreSyncAct_prev_gyza = PreSyncAct__Off;
    App_Model_DW.Var_PreSyncAct_start_avlx = PreSyncAct__Off;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_p_dro5 = RWPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_s_gr5w = RWPCIndSyncVal__Default;
    App_Model_DW.Var_INT_RWPCIndCmdState_pr_cqwk = RWPCIndCmdState__Default;
    App_Model_DW.Var_INT_RWPCIndCmdState_st_bawh = RWPCIndCmdState__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_pr_mlsp = WPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_st_kruf = WPCIndSyncVal__Default;
    App_Model_DW.Var_INT_WPCIndCmdState_prev = WPCIndCmdState__Default;
    App_Model_DW.Var_INT_WPCIndCmdState_start = WPCIndCmdState__Default;
    App_Model_DW.WPCIndUSMState_prev_grnb = WPCIndUSMState__Default;
    App_Model_DW.WPCIndUSMState_start_gcuc = WPCIndUSMState__Default;
    App_Model_DW.b_SyncAmber_prev_lnzu = Off;
    App_Model_DW.b_SyncAmber_start_bf1w = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S217>/IND_Animation_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S217>/IndyOutputControl_Function' */
    IndyOutputControl_Fun_flyb_Init(&App_Model_B.P_GreenIND_OUT_jrko, &App_Model_B.P_GreenIND2_OUT_kfol, &App_Model_B.P_GreenIND3_OUT_olhg, &App_Model_B.P_AmberIND_OUT_hhha);

    /* End of SystemInitialize for SubSystem: '<S217>/IndyOutputControl_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC2_TE_sys' */

    /* SystemInitialize for Chart: '<S408>/Change_INT_NfcOnThePad' */
    App_Model_DW.is_active_c30_Jdg_DualSyncOrder = 0U;
    App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
    App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
    App_Model_DW.NfcOnThePad_1_prev = OnThePad_Off;
    App_Model_DW.NfcOnThePad_1_start = OnThePad_Off;
    App_Model_DW.NfcOnThePad_2_prev = OnThePad_Off;
    App_Model_DW.NfcOnThePad_2_start = OnThePad_Off;

    /* SystemInitialize for Chart: '<S408>/Jdg_DualWPC_Onthepad' */
    App_Model_DW.is_active_c23_Jdg_DualSyncOrder = 0U;

    /* SystemInitialize for Chart: '<S408>/LPCDWakeUp_Detect_DWPC_Priority' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_active_c47_Jdg_DualSyncOrder = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_WPC1PreAct_bgn2 = Off;
    App_Model_B.Var_WPC2PreAct_dlkp = Off;
    App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_p = Off;
    App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC1_s = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    App_Model_DW.Var_OPT_WPCStatus_1_prev_fkrl = ModeOff;
    App_Model_DW.Var_OPT_WPCStatus_1_start_fipw = ModeOff;
    App_Model_DW.Var_OPT_WPCStatus_2_prev_cmdz = ModeOff;
    App_Model_DW.Var_OPT_WPCStatus_2_start_aclk = ModeOff;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_p = Off;
    App_Model_DW.Receive_Flag_LPCD_Wakeup_WPC2_s = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S408>/Jdg_LPCDWakeUpOrder' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_active_c24_Jdg_DualSyncOrder = 0U;
    App_Model_B.LPCDWakeUpOrder = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Var_WPC2PreAct_prev_pv1v = Off;
    App_Model_DW.Var_WPC2PreAct_start_j405 = Off;
    App_Model_DW.Var_WPC1PreAct_prev_asvg = Off;
    App_Model_DW.Var_WPC1PreAct_start_inrz = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S408>/NFC_Detect_DWPC_Priority' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     *  Chart: '<S408>/LPCDWakeUp_Detect_DWPC_Priority'
     */
    App_Model_DW.is_active_c46_Jdg_DualSyncOrder = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_WPC1PreAct = Off;
    App_Model_B.Var_WPC2PreAct = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    App_Model_DW.Var_NFCDetection_WPC1_prev = NFCDetection_Off;
    App_Model_DW.Var_NFCDetection_WPC1_start = NFCDetection_Off;
    App_Model_DW.Var_OPT_WPCStatus_1_prev = ModeOff;
    App_Model_DW.Var_OPT_WPCStatus_1_start = ModeOff;
    App_Model_DW.Var_OPT_WPCStatus_2_prev = ModeOff;
    App_Model_DW.Var_OPT_WPCStatus_2_start = ModeOff;
    App_Model_DW.Var_NFCDetection_WPC2_prev = NFCDetection_Off;
    App_Model_DW.Var_NFCDetection_WPC2_start = NFCDetection_Off;

    /* SystemInitialize for Chart: '<S408>/Jdg_NFCDetectOrder' */
    App_Model_DW.is_active_c25_Jdg_DualSyncOrder = 0U;
    App_Model_B.NFCDetectOrder = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* SystemInitialize for Chart: '<S408>/Jdg_LPCDWakeUpOrder' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     *  Chart: '<S408>/Jdg_NFCDetectOrder'
     */
    App_Model_DW.Var_WPC2PreAct_prev = Off;

    /* SystemInitialize for Chart: '<S408>/Jdg_NFCDetectOrder' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.Var_WPC2PreAct_start = Off;

    /* SystemInitialize for Chart: '<S408>/Jdg_LPCDWakeUpOrder' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     *  Chart: '<S408>/Jdg_NFCDetectOrder'
     */
    App_Model_DW.Var_WPC1PreAct_prev = Off;

    /* SystemInitialize for Chart: '<S408>/Jdg_NFCDetectOrder' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.Var_WPC1PreAct_start = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S410>/IND_Animation_WPC2_Priority_Flow_Graph' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_active_c35_Jdg_DualSyncOrder = 0U;
    App_Model_B.Var_WPC2PreSyncAct_fdt4 = WPC2PreSyncAct_Off;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Input_INT_WPC2IndSyncVal_prev = WPC2IndSyncVal__Default;
    App_Model_DW.Input_INT_WPC2IndSyncVal_start = WPC2IndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S410>/IND_Animation_RWPC_Priority_Flow_Graph' */
    IND_Animation_RWPC_Priorit_Init(&App_Model_B.Var_RWPCPreSyncAct_baek, &App_Model_DW.sf_IND_Animation_RWPC_Priority_);

    /* SystemInitialize for Chart: '<S410>/IND_Animation_Priority_Flow_Graph' */
    IND_Animation_Priority_Flo_Init(&App_Model_B.Var_PreSyncAct_akzv, &App_Model_DW.sf_IND_Animation_Priority_Flow_);

    /* SystemInitialize for Chart: '<S410>/IND_Animation_WPC_Priority_Flow_Graph' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_active_c36_Jdg_DualSyncOrder = 0U;
    App_Model_B.Var_WPCPreSyncAct_bh5w = WPCPreSyncAct_Off;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Input_INT_WPCIndSyncVal_prev = WPCIndSyncVal__Default;
    App_Model_DW.Input_INT_WPCIndSyncVal_start = WPCIndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S410>/IND_Animation_Priority_Flow_Graph1' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_active_c33_Jdg_DualSyncOrder = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_PreSyncAct_gfx0 = PreSyncAct__Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S409>/DWPC1_Amber_Sync_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_SyncTrigger_f0k2 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c6_Jdg_DualSyncOrder_ = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Output_INT_WPCIndCmdState__eo32 = WPCIndCmdState__Default;
    App_Model_DW.Output_INT_WPCIndCmdState__lcxt = WPCIndCmdState__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S409>/DWPC1_LED_Sync_Indy' */
    App_Mo_DWPC1_LED_Sync_Indy_Init(&rtb_b_SyncLED_ipyt, &App_Model_DW.sf_DWPC1_LED_Sync_Indy);

    /* SystemInitialize for Chart: '<S409>/DWPC2_Amber_Sync_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_SyncTrigger_c1fa = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c11_Jdg_DualSyncOrder = 0U;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Output_INT_WPC2IndCmdState_prev = WPC2IndCmdState__Default;
    App_Model_DW.Output_INT_WPC2IndCmdState_star = WPC2IndCmdState__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */

    /* SystemInitialize for Chart: '<S409>/DWPC2_LED_Sync_Indy' */
    App_Mo_DWPC1_LED_Sync_Indy_Init(&rtb_b_SyncLED, &App_Model_DW.sf_DWPC2_LED_Sync_Indy);

    /* SystemInitialize for Chart: '<S438>/WPC_Mode_LPConditionJdg' */
    Ap_WPC_Mode_LPConditionJdg_Init(&rtb_WPCMode_LPConditionFla_e5bi, &App_Model_DW.sf_WPC_Mode_LPConditionJdg);

    /* SystemInitialize for Chart: '<S438>/NFC_Mode_LPConditionJdg' */
    Ap_NFC_Mode_LPConditionJdg_Init(&rtb_NFCMode_LPConditionFla_i45m, &App_Model_DW.sf_NFC_Mode_LPConditionJdg);

    /* SystemInitialize for Chart: '<S438>/MainControl_LPConditionJdg' */
    MainControl_LPConditionJdg_Init(&rtb_WPCMain_LPConditionFla_g2vh, &App_Model_DW.sf_MainControl_LPConditionJdg);

    /* SystemInitialize for Chart: '<S438>/SMKLF_LPConditionJdg' */
    App_M_SMKLF_LPConditionJdg_Init(&rtb_SMKLF_LPConditionFlag__edfo, &App_Model_DW.sf_SMKLF_LPConditionJdg);

    /* SystemInitialize for Chart: '<S438>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPCondit_Init(&rtb_TempSnsrError_LPCondit_lcr4, &App_Model_DW.sf_TempSnsrErrDetect_LPConditio);

    /* SystemInitialize for Chart: '<S438>/OverTempDetect_LPConditionJdg' */
    OverTempDetect_LPCondition_Init(&rtb_OverTempDetect_LPCondi_l4hp, &App_Model_DW.sf_OverTempDetect_LPConditionJd);

    /* SystemInitialize for Chart: '<S438>/OverCurrent_LPConditionJdg' */
    OverCurrent_LPConditionJdg_Init(&rtb_OverCurrent_LPConditio_ivuq, &App_Model_DW.sf_OverCurrent_LPConditionJdg);

    /* SystemInitialize for Chart: '<S438>/FAN_LPConditionJdg' */
    App_Mod_FAN_LPConditionJdg_Init(&rtb_FAN_LPConditionFlag_wr_djmc, &App_Model_DW.sf_FAN_LPConditionJdg);

    /* SystemInitialize for Chart: '<S438>/USM_WPC_LPConditionJdg' */
    App_USM_WPC_LPConditionJdg_Init(&App_Model_B.P_WPC_USM_LPConditionFlag__kp25, &App_Model_DW.sf_USM_WPC_LPConditionJdg);

    /* SystemInitialize for Chart: '<S439>/WPC_Mode_LPConditionJdg' */
    Ap_WPC_Mode_LPConditionJdg_Init(&rtb_WPCMode_LPConditionFla_pady, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_lmx5);

    /* SystemInitialize for Chart: '<S439>/NFC_Mode_LPConditionJdg' */
    Ap_NFC_Mode_LPConditionJdg_Init(&rtb_NFCMode_LPConditionFla_jmfo, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_gc1n);

    /* SystemInitialize for Chart: '<S439>/MainControl_LPConditionJdg' */
    MainControl_LPConditionJdg_Init(&rtb_WPCMain_LPConditionFla_cfn0, &App_Model_DW.sf_MainControl_LPCondition_kcum);

    /* SystemInitialize for Chart: '<S439>/SMKLF_LPConditionJdg' */
    App_M_SMKLF_LPConditionJdg_Init(&rtb_SMKLF_LPConditionFlag__fnej, &App_Model_DW.sf_SMKLF_LPConditionJdg_esv2);

    /* SystemInitialize for Chart: '<S439>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPCondit_Init(&rtb_TempSnsrError_LPCondit_egth, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_c3yn);

    /* SystemInitialize for Chart: '<S439>/OverTempDetect_LPConditionJdg' */
    OverTempDetect_LPCondition_Init(&rtb_OverTempDetect_LPCondi_bvam, &App_Model_DW.sf_OverTempDetect_LPCondit_ehj5);

    /* SystemInitialize for Chart: '<S439>/OverCurrent_LPConditionJdg' */
    OverCurrent_LPConditionJdg_Init(&rtb_OverCurrent_LPConditio_p4qh, &App_Model_DW.sf_OverCurrent_LPCondition_p2tn);

    /* SystemInitialize for Chart: '<S439>/FAN_LPConditionJdg' */
    App_Mod_FAN_LPConditionJdg_Init(&rtb_FAN_LPConditionFlag_wr_ddyr, &App_Model_DW.sf_FAN_LPConditionJdg_gs2a);

    /* SystemInitialize for Chart: '<S439>/USM_WPC2_LPCondition' */
    App_Model_DW.sfEvent_px3u = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_LPConditionChk_C_kxfd = 0U;
    App_Model_DW.is_LPConditionChk_Chart_oepo = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_LPConditionHold_bwlz = 0U;
    App_Model_DW.is_LPConditionHold_gkga = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c11_LPConditionJdg_li = 0U;
    App_Model_DW.ECUResetEnable_pyqo = 0U;
    App_Model_DW.Timer_LPConditionHold_n0a4 = 0U;
    App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
    App_Model_DW.m_ProfileGuestWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileGuestWPC2USM_App_start = WPC_On;
    App_Model_DW.m_ProfileOneWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileOneWPC2USM_App_start = WPC_On;
    App_Model_DW.m_ProfileTwoWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileTwoWPC2USM_App_start = WPC_On;
    App_Model_DW.m_ProfileThreeWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileThreeWPC2USM_App_start = WPC_On;

    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/SingleWPC' */
    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay' */
    App_Model_DW.UnitDelay_DSTATE = WPCIndUSMState__Default;

    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay4' */
    App_Model_DW.UnitDelay4_DSTATE = WPCIndCmdState__Default;

    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay9' */
    App_Model_DW.UnitDelay9_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay10' */
    App_Model_DW.UnitDelay10_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay15' */
    App_Model_DW.UnitDelay15_DSTATE = WPCWarningOff;

    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay18' */
    App_Model_DW.UnitDelay18_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S844>/Unit Delay3' */
    App_Model_DW.UnitDelay3_DSTATE = ModeOff;

    /* SystemInitialize for Chart: '<S840>/DoorOpenCloseStateFunctionFlowGraph' */
    DoorOpenCloseStateFunction_Init(&App_Model_B.b_AstDrSw, &App_Model_B.b_DrvDrSw, &App_Model_B.b_RLDrSw, &App_Model_B.b_RRDrSw, &App_Model_DW.sf_DoorOpenCloseStateFunct_gpcq);

    /* SystemInitialize for Atomic SubSystem: '<S635>/SWPC_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S638>/USMSettingControl_Function' */
    USMSettingControl_Fun_j1sr_Init(&App_Model_B.C_WPCRValue, &App_Model_B.WPCSWOption);

    /* End of SystemInitialize for SubSystem: '<S638>/USMSettingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S640>/NFC_WPC_Mode_Control_Function' */
    NFC_WPC_Mode_Control__ovav_Init(&App_Model_B.WPCStatus_es4i);

    /* End of SystemInitialize for SubSystem: '<S640>/NFC_WPC_Mode_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S640>/TemperatureSensorErrorDetect_Function' */
    TemperatureSensorErro_ixmp_Init(&App_Model_B.b_TempSensorFault, &App_Model_B.b_Timer_TempSensor_Check);

    /* End of SystemInitialize for SubSystem: '<S640>/TemperatureSensorErrorDetect_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S640>/PreventionSMK_LF_Interference_Function' */
    PreventionSMK_LF_Inte_oour_Init(&App_Model_B.b_LFState);

    /* End of SystemInitialize for SubSystem: '<S640>/PreventionSMK_LF_Interference_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S640>/OverCurrentDetecting_Function' */
    OverCurrentDetecting__ilt2_Init(&App_Model_B.b_CurrentFault, &App_Model_B.b_Timer_OvrCurr, &App_Model_B.b_Timer_ReOvrCurr);

    /* End of SystemInitialize for SubSystem: '<S640>/OverCurrentDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S640>/OverTemperatureDetecting_Function' */
    OverTemperatureDetect_fms5_Init(&App_Model_B.b_TemperatureFault, &App_Model_B.b_Timer_OverTemp);

    /* End of SystemInitialize for SubSystem: '<S640>/OverTemperatureDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S640>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectin_l2ay_Init(&App_Model_B.Output_PhoneLeftWarningWPCStatu);

    /* End of SystemInitialize for SubSystem: '<S640>/WPC_PhoneLeftDetectingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S638>/WPC_MainControl_Function' */
    WPC_MainControl_Funct_c5v2_Init(&App_Model_B.C_WPCWarning_kjwv, &App_Model_B.b_FANModeCmd, &App_Model_B.b_GreenINDCmd, &App_Model_B.b_AmberINDCmd, &App_Model_B.b_BlinkState,
      &App_Model_B.b_Timer_PhoneReminderCheck, &App_Model_B.b_Timer_PhoneWarningCheck, &App_Model_B.b_Timer_WarningComplete, &App_Model_B.b_ChargingEnable, &App_Model_B.BlinkState_i5ti,
      &App_Model_B.b_PhnLeftChk_Enable, &App_Model_B.b_Timer_WarningTypeCheck);

    /* End of SystemInitialize for SubSystem: '<S638>/WPC_MainControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S639>/FAN_Control_Function' */
    FAN_Control_Function_gebo_Init(&rtb_FAN_PWM, &App_Model_B.FANDutyRatioSta);

    /* End of SystemInitialize for SubSystem: '<S639>/FAN_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S639>/IND_Animation_Control_Function' */
    /* SystemInitialize for Atomic SubSystem: '<S644>/SWPC_INDAnimationControl' */
    /* SystemInitialize for Chart: '<S652>/IND_Animation_WPC2_Priority_Flow_Graph' */
    IND_Animation_WPC2_Priorit_Init(&App_Model_B.Var_WPC2PreSyncAct, &App_Model_DW.sf_IND_Animation_WPC2_Prio_msgq);

    /* SystemInitialize for Chart: '<S652>/IND_Animation_RWPC_Priority_Flow_Graph' */
    IND_Animation_RWPC_Priorit_Init(&App_Model_B.Var_RWPCPreSyncAct, &App_Model_DW.sf_IND_Animation_RWPC_Prio_his4);

    /* SystemInitialize for Chart: '<S652>/IND_Animation_Priority_Flow_Graph' */
    IND_Animation_Priority_Flo_Init(&App_Model_B.Var_PreSyncAct, &App_Model_DW.sf_IND_Animation_Priority__njws);

    /* SystemInitialize for Chart: '<S652>/WPC2_IND_Command_State_Control_Function_State_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_et4h = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDPhaseState = 0U;
    App_Model_DW.is_INDPhaseState = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_WPC2_IND_Command_Stat = 0U;
    App_Model_DW.is_WPC2_IND_Command_State_Contr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c168_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDPhaseState = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_INT_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_prev = WPC2IndSyncVal__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_start = WPC2IndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S652>/RWPC_IND_Command_State_Control_Function_State_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_gpvl = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDPhaseState_o34r = 0U;
    App_Model_DW.is_INDPhaseState_n5rr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_RWPC_IND_Command_Stat = 0U;
    App_Model_DW.is_RWPC_IND_Command_State_Contr = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c167_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDPhaseState_gnkj = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_prev = RWPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_start = RWPCIndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S652>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_gygj = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDFadeIn = 0U;
    App_Model_DW.is_INDFadeIn = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDFadeOut = 0U;
    App_Model_DW.is_INDFadeOut = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDLight = 0U;
    App_Model_DW.is_INDLight = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_IND_Animation_Sync_Co = 0U;
    App_Model_DW.is_IND_Animation_Sync_Control_F = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_Acti = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_1stS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_2ndS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimationCharging_3rdS = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c165_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDLight = 0U;
    App_Model_DW.Timer_INDFadeIn = 0U;
    App_Model_DW.Timer_INDFadeOut = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Output_CAN_WPCIndSyncVal = WPCIndSyncVal__Default;
    App_Model_B.Output_INT_WPCIndCmdState = WPCIndCmdState__Default;
    App_Model_DW.Var_PreSyncAct_prev = PreSyncAct__Off;
    App_Model_DW.Var_PreSyncAct_start = PreSyncAct__Off;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_p_eqk4 = RWPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_RWPCIndSyncVal_s_fuhd = RWPCIndSyncVal__Default;
    App_Model_DW.Var_INT_RWPCIndCmdState_prev = RWPCIndCmdState__Default;
    App_Model_DW.Var_INT_RWPCIndCmdState_start = RWPCIndCmdState__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_p_ofvk = WPC2IndSyncVal__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_s_hoel = WPC2IndSyncVal__Default;
    App_Model_DW.Var_INT_WPC2IndCmdState_prev = WPC2IndCmdState__Default;
    App_Model_DW.Var_INT_WPC2IndCmdState_start = WPC2IndCmdState__Default;
    App_Model_DW.WPCIndUSMState_prev = WPCIndUSMState__Default;
    App_Model_DW.WPCIndUSMState_start = WPCIndUSMState__Default;
    App_Model_DW.b_SyncAmber_prev = Off;
    App_Model_DW.b_SyncAmber_start = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S652>/Amber_Sync_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_SyncTrigger = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c161_WPC_IND_Animatio = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Output_INT_WPCIndCmdState_prev = WPCIndCmdState__Default;
    App_Model_DW.Output_INT_WPCIndCmdState_start = WPCIndCmdState__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S652>/Amber_Sync_Indy' */
    App_Model_Amber_Sync_Indy_Init(&rtb_b_SyncAmber, &App_Model_DW.sf_Amber_Sync_Indy_mh0e);

    /* End of SystemInitialize for SubSystem: '<S644>/SWPC_INDAnimationControl' */

    /* SystemInitialize for Atomic SubSystem: '<S644>/SWPC_INDAnimationUSMSettingControl_v_1_2' */
    /* SystemInitialize for Chart: '<S661>/IND_Animation_Profile_Decision_Function_Flow_Graph' */
    IND_Animation_Profile_Deci_Init(&App_Model_B.CurProfile, &App_Model_DW.sf_IND_Animation_Profile_D_amxp);

    /* SystemInitialize for Chart: '<S661>/IND_Animation_USM_Setting_Control_Function_State_Chart' */
    IND_Animation_USM_Setting__Init(&App_Model_B.Output_CAN_WPCIndUSMState, &Output_INT_WPCIndUSMState, &App_Model_DW.sf_IND_Animation_USM_Setti_mmqi);

    /* End of SystemInitialize for SubSystem: '<S644>/SWPC_INDAnimationUSMSettingControl_v_1_2' */
    /* End of SystemInitialize for SubSystem: '<S639>/IND_Animation_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S639>/IndyOutputControl_Function' */
    IndyOutputControl_Fun_fbjd_Init(&App_Model_B.P_GreenIND_OUT, &App_Model_B.P_GreenIND2_OUT, &App_Model_B.P_GreenIND3_OUT, &App_Model_B.P_AmberIND_OUT);

    /* End of SystemInitialize for SubSystem: '<S639>/IndyOutputControl_Function' */
    /* End of SystemInitialize for SubSystem: '<S635>/SWPC_TE_sys' */

    /* SystemInitialize for Chart: '<S852>/WPC_Mode_LPConditionJdg' */
    Ap_WPC_Mode_LPConditionJdg_Init(&rtb_WPCMode_LPConditionFlag_wri, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_p0on);

    /* SystemInitialize for Chart: '<S852>/NFC_Mode_LPConditionJdg' */
    Ap_NFC_Mode_LPConditionJdg_Init(&rtb_NFCMode_LPConditionFlag_wri, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_gkrq);

    /* SystemInitialize for Chart: '<S852>/MainControl_LPConditionJdg' */
    MainControl_LPConditionJdg_Init(&rtb_WPCMain_LPConditionFlag_wri, &App_Model_DW.sf_MainControl_LPCondition_gatm);

    /* SystemInitialize for Chart: '<S852>/SMKLF_LPConditionJdg' */
    App_M_SMKLF_LPConditionJdg_Init(&rtb_SMKLF_LPConditionFlag_write, &App_Model_DW.sf_SMKLF_LPConditionJdg_j4fk);

    /* SystemInitialize for Chart: '<S852>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPCondit_Init(&rtb_TempSnsrError_LPConditionFl, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_ftjz);

    /* SystemInitialize for Chart: '<S852>/OverTempDetect_LPConditionJdg' */
    OverTempDetect_LPCondition_Init(&rtb_OverTempDetect_LPConditionF, &App_Model_DW.sf_OverTempDetect_LPCondit_al4m);

    /* SystemInitialize for Chart: '<S852>/OverCurrent_LPConditionJdg' */
    OverCurrent_LPConditionJdg_Init(&rtb_OverCurrent_LPConditionFlag, &App_Model_DW.sf_OverCurrent_LPCondition_alin);

    /* SystemInitialize for Chart: '<S852>/FAN_LPConditionJdg' */
    App_Mod_FAN_LPConditionJdg_Init(&rtb_FAN_LPConditionFlag_write, &App_Model_DW.sf_FAN_LPConditionJdg_jyac);

    /* SystemInitialize for Chart: '<S852>/USM_WPC_LPConditionJdg' */
    App_USM_WPC_LPConditionJdg_Init(&App_Model_B.P_WPC_USM_LPConditionFlag_write, &App_Model_DW.sf_USM_WPC_LPConditionJdg_n0v1);

    /* End of SystemInitialize for SubSystem: '<S3>/SingleWPC' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/RWPC' */
    /* InitializeConditions for UnitDelay: '<S617>/Unit Delay5' */
    App_Model_DW.UnitDelay5_DSTATE_dr5b = RWPCIndCmdState__Default;

    /* InitializeConditions for UnitDelay: '<S617>/Unit Delay11' */
    App_Model_DW.UnitDelay11_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S617>/Unit Delay12' */
    App_Model_DW.UnitDelay12_DSTATE = Off;

    /* InitializeConditions for UnitDelay: '<S617>/Unit Delay16' */
    App_Model_DW.UnitDelay16_DSTATE = WPCWarningOff;

    /* InitializeConditions for UnitDelay: '<S617>/Unit Delay7' */
    App_Model_DW.UnitDelay7_DSTATE = ModeOff;

    /* InitializeConditions for UnitDelay: '<S617>/Unit Delay19' */
    App_Model_DW.UnitDelay19_DSTATE = Off;

    /* SystemInitialize for Chart: '<S613>/DoorOpenCloseStateFunctionFlowGraph' */
    DoorOpenCloseStateFunction_Init(&App_Model_B.b_AstDrSw_jy3e, &App_Model_B.b_DrvDrSw_kh5i, &App_Model_B.b_RLDrSw_jnn1, &App_Model_B.b_RRDrSw_bczk, &App_Model_DW.sf_DoorOpenCloseStateFunct_mocq);

    /* SystemInitialize for Atomic SubSystem: '<S458>/RWPC_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S461>/USMSettingControl_Function' */
    USMSettingControl_Fun_o1by_Init(&App_Model_B.RWPCSWOption, &App_Model_B.C_RWPCRValue);

    /* End of SystemInitialize for SubSystem: '<S461>/USMSettingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/NFC_WPC_Mode_Control_Function' */
    NFC_WPC_Mode_Control__dxgm_Init(&App_Model_B.WPCStatus_gxft);

    /* End of SystemInitialize for SubSystem: '<S463>/NFC_WPC_Mode_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/TemperatureSensorErrorDetect_Function' */
    TemperatureSensorErro_fuus_Init(&App_Model_B.b_TempSensorFault_h5jx, &App_Model_B.b_Timer_TempSensor_Check_hxeq);

    /* End of SystemInitialize for SubSystem: '<S463>/TemperatureSensorErrorDetect_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/PreventionSMK_LF_Interference_Function' */
    PreventionSMK_LF_Inte_myco_Init(&App_Model_B.b_LFState_o4ks);

    /* End of SystemInitialize for SubSystem: '<S463>/PreventionSMK_LF_Interference_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/OverCurrentDetecting_Function' */
    OverCurrentDetecting__bh0g_Init(&App_Model_B.b_CurrentFault_p1jy, &App_Model_B.b_Timer_OvrCurr_bfb2, &App_Model_B.b_Timer_ReOvrCurr_c3aw);

    /* End of SystemInitialize for SubSystem: '<S463>/OverCurrentDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/OverTemperatureDetecting_Function' */
    OverTemperatureDetect_crrl_Init(&App_Model_B.b_TemperatureFault_iak5, &App_Model_B.b_Timer_OverTemp_ffe1);

    /* End of SystemInitialize for SubSystem: '<S463>/OverTemperatureDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S461>/WPC_MainControl_Function' */
    WPC_MainControl_Funct_btar_Init(&App_Model_B.C_WPCWarning_epwi, &App_Model_B.b_FANModeCmd_iroy, &App_Model_B.b_GreenINDCmd_lsi0, &App_Model_B.b_AmberINDCmd_cdgi, &App_Model_B.b_BlinkState_k1bt,
      &App_Model_B.b_Timer_PhoneReminderCheck_as5u, &App_Model_B.b_Timer_PhoneWarningCheck_icl4, &App_Model_B.b_Timer_WarningComplete_ib23, &App_Model_B.b_ChargingEnable_m33x,
      &App_Model_B.BlinkState_ouyp, &App_Model_B.b_PhnLeftChk_Enable_cnhm, &App_Model_B.b_Timer_WarningTypeCheck_eda4);

    /* End of SystemInitialize for SubSystem: '<S461>/WPC_MainControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S462>/FAN_Control_Function' */
    FAN_Control_Function_iqwo_Init(&rtb_FAN_PWM_eua1, &App_Model_B.FANDutyRatioSta_htud);

    /* End of SystemInitialize for SubSystem: '<S462>/FAN_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S462>/IND_Animation_Control_Function' */
    /* SystemInitialize for Atomic SubSystem: '<S467>/RWPC_INDAnimationControl' */
    /* SystemInitialize for Chart: '<S474>/IND_Animation_WPC_Priority_Flow_Graph' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     *  Chart: '<S410>/IND_Animation_WPC_Priority_Flow_Graph'
     */
    App_Model_DW.is_active_c178_WPC_IND_Animatio = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    App_Model_B.Var_WPCPreSyncAct = WPCPreSyncAct_Off;

    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Input_CAN_WPCIndSyncVal_pr_op3a = WPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_st_cekz = WPCIndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S474>/IND_Animation_WPC2_Priority_Flow_Graph' */
    IND_Animation_WPC2_Priorit_Init(&App_Model_B.Var_WPC2PreSyncAct_ocx1, &App_Model_DW.sf_IND_Animation_WPC2_Prio_c04w);

    /* SystemInitialize for Chart: '<S474>/IND_Animation_Priority_Flow_Graph' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_active_c175_WPC_IND_Animatio = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_PreSyncAct_jsc5 = PreSyncAct__Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S474>/WPC_IND_Command_State_Control_Function_State_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_bqin = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDPhaseState_na13 = 0U;
    App_Model_DW.is_INDPhaseState_p4z4 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_WPC_IND_Command_State = 0U;
    App_Model_DW.is_WPC_IND_Command_State_Contro = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDCmdState_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDCmdState_1stSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDCmdState_2ndSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDCmdState_3rdSync = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCINDCmdState_Off = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPCIndCmdState_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c180_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDPhaseState_holq = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_WPCIndCmdState = WPCIndCmdState__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_prev = WPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_start = WPCIndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S474>/WPC2_IND_Command_State_Control_Function_State_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_fezm = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDPhaseState_eoo3 = 0U;
    App_Model_DW.is_INDPhaseState_k14z = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_WPC2_IND_Command_c4py = 0U;
    App_Model_DW.is_WPC2_IND_Command_State__krzh = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_Chargin_hwcc = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_1stSync_jxg5 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_2ndSync_mw3v = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_3rdSync_l1h3 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_Off_mcf1 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_WPC2INDCmdState_Error_jb0a = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c179_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDPhaseState_h1ak = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Var_WPC2IndCmdState = WPC2IndCmdState__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_p_jbvc = WPC2IndSyncVal__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_s_ksmi = WPC2IndSyncVal__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S474>/IND_Animation_Sync_Control_Function_State_Chart_7Step' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.sfEvent_c1ob = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_INDFadeIn_afmn = 0U;
    App_Model_DW.is_INDFadeIn_n305 = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDFadeOut_cklz = 0U;
    App_Model_DW.is_INDFadeOut_ps5o = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_INDLight_h5bd = 0U;
    App_Model_DW.is_INDLight_kqsl = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_IND_Animation_Sy_n4yx = 0U;
    App_Model_DW.is_IND_Animation_Sync_Cont_mjjk = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDAnimation_Charging = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDAnimationCharging_Act = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDAnimationCharging_1st = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDAnimationCharging_2nd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDAnimationCharging_3rd = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_RWPCINDAnimation_Error = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c176_WPC_IND_Animatio = 0U;
    App_Model_DW.Timer_INDLight_ewv0 = 0U;
    App_Model_DW.Timer_INDFadeIn_g1fs = 0U;
    App_Model_DW.Timer_INDFadeOut_ey0j = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_B.Output_CAN_RWPCIndSyncVal = RWPCIndSyncVal__Default;
    App_Model_B.Output_INT_RWPCIndCmdState = RWPCIndCmdState__Default;
    App_Model_DW.Var_PreSyncAct_prev_ojgc = PreSyncAct__Off;
    App_Model_DW.Var_PreSyncAct_start_ntz3 = PreSyncAct__Off;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_p_mhlo = WPC2IndSyncVal__Default;
    App_Model_DW.Input_CAN_WPC2IndSyncVal_s_mifz = WPC2IndSyncVal__Default;
    App_Model_DW.Var_WPC2IndCmdState_prev = WPC2IndCmdState__Default;
    App_Model_DW.Var_WPC2IndCmdState_start = WPC2IndCmdState__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_pr_jzlo = WPCIndSyncVal__Default;
    App_Model_DW.Input_CAN_WPCIndSyncVal_st_iach = WPCIndSyncVal__Default;
    App_Model_DW.Var_WPCIndCmdState_prev = WPCIndCmdState__Default;
    App_Model_DW.Var_WPCIndCmdState_start = WPCIndCmdState__Default;
    App_Model_DW.WPCIndUSMState_prev_nqvt = WPCIndUSMState__Default;
    App_Model_DW.WPCIndUSMState_start_dh2i = WPCIndUSMState__Default;
    App_Model_DW.b_SyncAmber_prev_eb5q = Off;
    App_Model_DW.b_SyncAmber_start_hkgy = Off;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S474>/Amber_Sync_Chart' incorporates:
     *  Chart: '<S35>/IND_Animation_Sync_Control_Function_State_Chart_7Step'
     */
    App_Model_DW.is_SyncTrigger_owzu = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c171_WPC_IND_Animatio = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    /* SystemInitialize for Atomic SubSystem: '<S16>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/IND_Animation_Control_Function' */
    App_Model_DW.Output_INT_RWPCIndCmdState_prev = RWPCIndCmdState__Default;
    App_Model_DW.Output_INT_RWPCIndCmdState_star = RWPCIndCmdState__Default;

    /* End of SystemInitialize for SubSystem: '<S22>/IND_Animation_Control_Function' */
    /* End of SystemInitialize for SubSystem: '<S16>/DWPC1_TE_sys' */
    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */

    /* SystemInitialize for Chart: '<S474>/Amber_Sync_Indy' */
    App_Model_Amber_Sync_Indy_Init(&rtb_b_SyncAmber_jg2q, &App_Model_DW.sf_Amber_Sync_Indy);

    /* End of SystemInitialize for SubSystem: '<S467>/RWPC_INDAnimationControl' */
    /* End of SystemInitialize for SubSystem: '<S462>/IND_Animation_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S462>/IndyOutputControl_Function' */
    IndyOutputControl_Fun_g554_Init(&App_Model_B.P_GreenIND_OUT_efiw, &App_Model_B.P_GreenIND2_OUT_g4dl, &App_Model_B.P_GreenIND3_OUT_okli, &App_Model_B.P_AmberIND_OUT_fl2l);

    /* End of SystemInitialize for SubSystem: '<S462>/IndyOutputControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectin_nhlp_Init();

    /* End of SystemInitialize for SubSystem: '<S463>/WPC_PhoneLeftDetectingControl_Function' */
    /* End of SystemInitialize for SubSystem: '<S458>/RWPC_TE_sys' */

    /* SystemInitialize for Chart: '<S625>/WPC_Mode_LPConditionJdg' */
    Ap_WPC_Mode_LPConditionJdg_Init(&rtb_WPCMode_LPConditionFla_hka2, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_jccj);

    /* SystemInitialize for Chart: '<S625>/NFC_Mode_LPConditionJdg' */
    Ap_NFC_Mode_LPConditionJdg_Init(&rtb_NFCMode_LPConditionFla_ogfp, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_hmwu);

    /* SystemInitialize for Chart: '<S625>/MainControl_LPConditionJdg' */
    MainControl_LPConditionJdg_Init(&rtb_WPCMain_LPConditionFla_nrse, &App_Model_DW.sf_MainControl_LPCondition_aehg);

    /* SystemInitialize for Chart: '<S625>/SMKLF_LPConditionJdg' */
    App_M_SMKLF_LPConditionJdg_Init(&rtb_SMKLF_LPConditionFlag__j4w3, &App_Model_DW.sf_SMKLF_LPConditionJdg_jne5);

    /* SystemInitialize for Chart: '<S625>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPCondit_Init(&rtb_TempSnsrError_LPCondit_oh14, &App_Model_DW.sf_TempSnsrErrDetect_LPCon_flnb);

    /* SystemInitialize for Chart: '<S625>/OverTempDetect_LPConditionJdg' */
    OverTempDetect_LPCondition_Init(&rtb_OverTempDetect_LPCondi_a4lc, &App_Model_DW.sf_OverTempDetect_LPCondit_hgqy);

    /* SystemInitialize for Chart: '<S625>/OverCurrent_LPConditionJdg' */
    OverCurrent_LPConditionJdg_Init(&rtb_OverCurrent_LPConditio_hfnx, &App_Model_DW.sf_OverCurrent_LPCondition_hwn5);

    /* SystemInitialize for Chart: '<S625>/FAN_LPConditionJdg' */
    App_Mod_FAN_LPConditionJdg_Init(&rtb_FAN_LPConditionFlag_wr_okst, &App_Model_DW.sf_FAN_LPConditionJdg_ioqj);

    /* SystemInitialize for Chart: '<S625>/USM_WPC_LPConditionJdg' incorporates:
     *  Chart: '<S439>/USM_WPC2_LPCondition'
     */
    App_Model_DW.sfEvent_czwh = (sint32)App_Model_CALL_EVENT_ee3d;
    App_Model_DW.is_active_LPConditionChk_Chart = 0U;
    App_Model_DW.is_LPConditionChk_Chart = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_LPConditionHold = 0U;
    App_Model_DW.is_LPConditionHold = App_Mod_IN_NO_ACTIVE_CHILD_k1rn;
    App_Model_DW.is_active_c50_sH3eOQeO4p6NHsKQC = 0U;
    App_Model_DW.ECUResetEnable = 0U;
    App_Model_DW.Timer_LPConditionHold = 0U;
    App_Model_B.P_WPC_USM_LPConditionFlag__eeih = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S3>/DualWPC' */
    App_Model_DW.m_RWPCUSM_App_prev_bsqc = WPC_On;
    App_Model_DW.m_RWPCUSM_App_start_eznj = WPC_On;

    /* End of SystemInitialize for SubSystem: '<S3>/DualWPC' */
    /* End of SystemInitialize for SubSystem: '<S3>/RWPC' */
    /* End of SystemInitialize for SubSystem: '<Root>/App_Model_TE_Sys' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
