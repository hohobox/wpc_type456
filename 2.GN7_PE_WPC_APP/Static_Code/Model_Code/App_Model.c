/*
 * File: App_Model.c
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

#include "App_Model.h"
#include "rtwtypes.h"
#include "App_Model_types.h"
#include "Rte_Type.h"
#include "App_Model_private.h"
#include <string.h>
#include "IndyOutputControl_Function.h"
#include "USMSettingControl_Function.h"
#include "NFC_WPC_Mode_Control_Function.h"
#include "TemperatureSensorErrorDetect_Function.h"
#include "PreventionSMK_LF_Interference_Function.h"
#include "OverCurrentDetecting_Function.h"
#include "OverTemperatureDetecting_Function.h"
#include "WPC_PhoneLeftDetectingControl_Function.h"
#include "WPC_MainControl_Function.h"
#include "FAN_Control_Function.h"
#include "IND_Animation_Control_Function.h"
#include "Jdg_DualOrder.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S424>/FAN_LPConditionJdg' */
#define App_Mode_IN_FAN_LPCondition_Off ((uint8)1U)
#define App_Model_IN_FAN_LPCondition_On ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_d ((uint8)0U)

/* Named constants for Chart: '<S424>/MainControl_LPConditionJdg' */
#define App_Mod_IN_Main_LPCondition_Off ((uint8)1U)
#define App_Mode_IN_Main_LPCondition_On ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_a ((uint8)0U)

/* Named constants for Chart: '<S424>/NFC_Mode_LPConditionJdg' */
#define App_Mode_IN_NFC_LPCondition_Off ((uint8)1U)
#define App_Model_IN_NFC_LPCondition_On ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_d4 ((uint8)0U)

/* Named constants for Chart: '<S424>/OverCurrent_LPConditionJdg' */
#define A_IN_OverCurrent_LPCondition_On ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_j ((uint8)0U)
#define IN_OverCurrent_LPCondition_Off ((uint8)1U)

/* Named constants for Chart: '<S424>/OverTempDetect_LPConditionJdg' */
#define App_Model_IN_NO_ACTIVE_CHILD_pv ((uint8)0U)
#define IN_OverTempDetect_LPCondition_O ((uint8)1U)
#define IN_OverTempDetect_LPCondition_i ((uint8)2U)

/* Named constants for Chart: '<S424>/SMKLF_LPConditionJdg' */
#define App_Mo_IN_SMKLF_LPCondition_Off ((uint8)1U)
#define App_Mod_IN_SMKLF_LPCondition_On ((uint8)2U)
#define App_Model_IN_NO_ACTIVE_CHILD_k ((uint8)0U)

/* Named constants for Chart: '<S424>/TempSnsrErrDetect_LPConditionJdg' */
#define App_Model_IN_NO_ACTIVE_CHILD_n ((uint8)0U)
#define IN_TempSnsrErrDetect_LPCondit_j ((uint8)2U)
#define IN_TempSnsrErrDetect_LPConditio ((uint8)1U)

/* Named constants for Chart: '<S424>/WPC_Mode_LPConditionJdg' */
#define App_Mode_IN_WPC_LPCondition_Off ((uint8)1U)
#define App_Model_IN_NO_ACTIVE_CHILD_ey ((uint8)0U)
#define App_Model_IN_WPC_LPCondition_On ((uint8)2U)

/* Named constants for Chart: '<S424>/USM_WPC_LPCondition' */
#define App_Mode_IN_LPConditionHold_Off ((uint8)1U)
#define App_Model_IN_LPConditionHold_On ((uint8)2U)
#define App_Model_IN_LPCondition_Off   ((uint8)1U)
#define App_Model_IN_LPCondition_On    ((uint8)2U)
#define event_CancelTimer_LPConditionHo (0)
#define event_StartTimer_LPConditionHol (1)

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
C_WPCOnOffNvalueSet m_ProfileGuestWPC2USM_App;/* Simulink.Signal object 'm_ProfileGuestWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileGuestWPCUSM_App;/* Simulink.Signal object 'm_ProfileGuestWPCUSM_App' */
C_WPCOnOffNvalueSet m_ProfileOneWPC2USM_App;/* Simulink.Signal object 'm_ProfileOneWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileOneWPCUSM_App;/* Simulink.Signal object 'm_ProfileOneWPCUSM_App' */
C_WPCOnOffNvalueSet m_ProfileTwoWPC2USM_App;/* Simulink.Signal object 'm_ProfileTwoWPC2USM_App' */
C_WPCOnOffNvalueSet m_ProfileTwoWPCUSM_App;/* Simulink.Signal object 'm_ProfileTwoWPCUSM_App' */
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
static uint8 safe_cast_to_C_WPCOnOffNvalueSe(uint8 input);
static uint8 App_safe_cast_to_WPCIndUSMState(uint8 input);

/* Forward declaration for local functions */
static void App_Model_LPConditionHold(void);
static void App_Model_LPConditionTimerCheck(void);
static void App_Model_LPConditionHold_h(void);
static void App_Mod_LPConditionTimerCheck_i(void);
static uint8 safe_cast_to_C_WPCOnOffNvalueSe(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for C_WPCOnOffNvalueSet (WPC_On) */
  output = 2U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of C_WPCOnOffNvalueSet */
    output = input;
  }

  return output;
}

static uint8 App_safe_cast_to_WPCIndUSMState(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for WPCIndUSMState (WPCIndUSMState__Default) */
  output = 0U;
  if (input <= 2) {
    /* Set output value to input value if it is a member of WPCIndUSMState */
    output = input;
  }

  return output;
}

/* System initialize for trigger system: '<Root>/AppInit_DataRead' */
void App_Model_AppInit_DataRead_Init(void)
{
  App_Model_PrevZCX.AppInit_DataRead_Trig_ZCE = ZERO_ZCSIG;
}

/* Output and update for trigger system: '<Root>/AppInit_DataRead' */
void App_Model_AppInit_DataRead(const IDT_NvM_STR *rtu_R_NvM_Data)
{
  sint32 i;

  /* Outputs for Triggered SubSystem: '<Root>/AppInit_DataRead' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  if (App_Model_B.AppInit_En && (App_Model_PrevZCX.AppInit_DataRead_Trig_ZCE != POS_ZCSIG)) {
    /* Chart: '<S2>/AutoBrightLevel_Read' */
    if (App_Model_DW.is_active_c7_App_Model == 0U) {
      App_Model_DW.is_active_c7_App_Model = 1U;

      /* Outputs for Function Call SubSystem: '<S5>/AutoBrightLevelSet' */
      /* MultiPortSwitch: '<S8>/Index Vector2' */
      /* initialize */
      switch (rtu_R_NvM_Data->LedDutyTableOption) {
       case 0:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/Default_Standard'
         */
        memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl0[0], 91U * sizeof(uint16));
        break;

       case 1:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/MX5_NEN_DL3PE'
         */
        memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl1[0], 91U * sizeof(uint16));
        break;

       case 2:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/ME1'
         */
        memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl2[0], 91U * sizeof(uint16));
        break;

       case 3:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/CL4'
         */
        memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl3[0], 91U * sizeof(uint16));
        break;

       case 4:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/MVa'
         */
        memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl4[0], 91U * sizeof(uint16));
        break;

       default:
        /* MultiPortSwitch: '<S8>/Index Vector2' incorporates:
         *  Constant: '<S8>/Default_Standard'
         */
        memcpy(&m_AutoBrightLevelSet[0], &Par_AutoBrightLevelTbl0[0], 91U * sizeof(uint16));
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
    /* NvM Initial Value
       WPCOnOffUSM */
    m_ProfileGuestWPCUSM_App = safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileGuestWPCUSM);
    m_ProfileOneWPCUSM_App = safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileOneWPCUSM);
    m_ProfileTwoWPCUSM_App = safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[0].m_ProfileTwoWPCUSM);
    m_ProfileGuestWPC2USM_App = safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileGuestWPCUSM);
    m_ProfileOneWPC2USM_App = safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileOneWPCUSM);
    m_ProfileTwoWPC2USM_App = safe_cast_to_C_WPCOnOffNvalueSe(rtu_R_NvM_Data->Device[1].m_ProfileTwoWPCUSM);

    /* WPCIndUSM */
    m_WPCIndUSMState_Guest = App_safe_cast_to_WPCIndUSMState(WPCAnimationNvalueSet__Default);
    m_WPCIndUSMState_ProfileOne = m_WPCIndUSMState_Guest;
    m_WPCIndUSMState_ProfileTwo = m_WPCIndUSMState_Guest;

    /* Chart: '<S2>/RheostatBrightLevel_Read' incorporates:
     *  Constant: '<S9>/Default_Standard'
     *  MultiPortSwitch: '<S9>/Index Vector2'
     */
    /* Reserved */
    if (App_Model_DW.is_active_c1_App_Model == 0U) {
      App_Model_DW.is_active_c1_App_Model = 1U;

      /* initialize
         CAR_TYPE = R_NvM_Data.LedDutyTableOption; */
      /* temp */
      for (i = 0; i < 22; i++) {
        /* Outputs for Function Call SubSystem: '<S7>/RheostatBrightLevelSet' */
        m_RheostatBrightLevelSet[i] = Par_RheostatBrightLevelTbl0[i];

        /* End of Outputs for SubSystem: '<S7>/RheostatBrightLevelSet' */
      }

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

  App_Model_PrevZCX.AppInit_DataRead_Trig_ZCE = App_Model_B.AppInit_En;

  /* End of Outputs for SubSystem: '<Root>/AppInit_DataRead' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/FAN_LPConditionJdg'
 *    '<S425>/FAN_LPConditionJdg'
 */
void App_Mod_FAN_LPConditionJdg_Init(uint8 *rty_FAN_LPConditionFlag_write)
{
  *rty_FAN_LPConditionFlag_write = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/FAN_LPConditionJdg'
 *    '<S425>/FAN_LPConditionJdg'
 */
void App_Mo_FAN_LPConditionJdg_Reset(uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW)
{
  localDW->is_FAN_LPConditionChk_Chart = App_Model_IN_NO_ACTIVE_CHILD_d;
  localDW->is_active_c13_App_Model = 0U;
  *rty_FAN_LPConditionFlag_write = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/FAN_LPConditionJdg'
 *    '<S425>/FAN_LPConditionJdg'
 */
void App_Model_FAN_LPConditionJdg(uint16 rtu_FAN_PWM, uint8 *rty_FAN_LPConditionFlag_write, DW_FAN_LPConditionJdg_App_Mod_T *localDW)
{
  /* Chart: '<S424>/FAN_LPConditionJdg' */
  if (localDW->is_active_c13_App_Model == 0U) {
    localDW->is_active_c13_App_Model = 1U;
    localDW->is_FAN_LPConditionChk_Chart = App_Mode_IN_FAN_LPCondition_Off;
    *rty_FAN_LPConditionFlag_write = 0U;
  } else if (localDW->is_FAN_LPConditionChk_Chart == App_Mode_IN_FAN_LPCondition_Off) {
    *rty_FAN_LPConditionFlag_write = 0U;
    if (rtu_FAN_PWM == 0) {
      localDW->is_FAN_LPConditionChk_Chart = App_Model_IN_FAN_LPCondition_On;
      *rty_FAN_LPConditionFlag_write = 1U;
    }
  } else {
    /* case IN_FAN_LPCondition_On: */
    *rty_FAN_LPConditionFlag_write = 1U;
    if (rtu_FAN_PWM != 0) {
      localDW->is_FAN_LPConditionChk_Chart = App_Mode_IN_FAN_LPCondition_Off;
      *rty_FAN_LPConditionFlag_write = 0U;
    }
  }

  /* End of Chart: '<S424>/FAN_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/MainControl_LPConditionJdg'
 *    '<S425>/MainControl_LPConditionJdg'
 */
void MainControl_LPConditionJdg_Init(uint8 *rty_WPCMain_LPConditionFlag_wri)
{
  *rty_WPCMain_LPConditionFlag_wri = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/MainControl_LPConditionJdg'
 *    '<S425>/MainControl_LPConditionJdg'
 */
void MainControl_LPConditionJd_Reset(uint8 *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW)
{
  localDW->is_Main_LPConditionChk_Chart = App_Model_IN_NO_ACTIVE_CHILD_a;
  localDW->is_active_c4_App_Model = 0U;
  *rty_WPCMain_LPConditionFlag_wri = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/MainControl_LPConditionJdg'
 *    '<S425>/MainControl_LPConditionJdg'
 */
void App__MainControl_LPConditionJdg(WPCStatus rtu_WPCStatus, uint16 rtu_b_Timer_PhoneReminderCheck, uint16 rtu_b_Timer_PhoneWarningCheck, uint16 rtu_b_Timer_WarningComplete, uint8
  *rty_WPCMain_LPConditionFlag_wri, DW_MainControl_LPConditionJdg_T *localDW)
{
  /* Chart: '<S424>/MainControl_LPConditionJdg' */
  if (localDW->is_active_c4_App_Model == 0U) {
    localDW->is_active_c4_App_Model = 1U;
    localDW->is_Main_LPConditionChk_Chart = App_Mod_IN_Main_LPCondition_Off;
    *rty_WPCMain_LPConditionFlag_wri = 0U;
  } else if (localDW->is_Main_LPConditionChk_Chart == App_Mod_IN_Main_LPCondition_Off) {
    *rty_WPCMain_LPConditionFlag_wri = 0U;
    if ((rtu_b_Timer_PhoneReminderCheck == 0) && (rtu_b_Timer_PhoneWarningCheck == 0) && (rtu_b_Timer_WarningComplete == 0) && (rtu_WPCStatus != WPCMode)) {
      localDW->is_Main_LPConditionChk_Chart = App_Mode_IN_Main_LPCondition_On;
      *rty_WPCMain_LPConditionFlag_wri = 1U;
    }
  } else {
    /* case IN_Main_LPCondition_On: */
    *rty_WPCMain_LPConditionFlag_wri = 1U;
    if ((rtu_b_Timer_PhoneReminderCheck > 0) || (rtu_b_Timer_PhoneWarningCheck > 0) || (rtu_b_Timer_WarningComplete > 0) || (rtu_WPCStatus == WPCMode)) {
      localDW->is_Main_LPConditionChk_Chart = App_Mod_IN_Main_LPCondition_Off;
      *rty_WPCMain_LPConditionFlag_wri = 0U;
    }
  }

  /* End of Chart: '<S424>/MainControl_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/NFC_Mode_LPConditionJdg'
 *    '<S425>/NFC_Mode_LPConditionJdg'
 */
void Ap_NFC_Mode_LPConditionJdg_Init(uint8 *rty_NFCMode_LPConditionFlag_wri)
{
  *rty_NFCMode_LPConditionFlag_wri = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/NFC_Mode_LPConditionJdg'
 *    '<S425>/NFC_Mode_LPConditionJdg'
 */
void A_NFC_Mode_LPConditionJdg_Reset(uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW)
{
  localDW->is_NFC_LPConditionChk_Chart = App_Model_IN_NO_ACTIVE_CHILD_d4;
  localDW->is_active_c8_App_Model = 0U;
  *rty_NFCMode_LPConditionFlag_wri = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/NFC_Mode_LPConditionJdg'
 *    '<S425>/NFC_Mode_LPConditionJdg'
 */
void App_Mod_NFC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_NFCMode_LPConditionFlag_wri, DW_NFC_Mode_LPConditionJdg_Ap_T *localDW)
{
  /* Chart: '<S424>/NFC_Mode_LPConditionJdg' */
  if (localDW->is_active_c8_App_Model == 0U) {
    localDW->is_active_c8_App_Model = 1U;
    localDW->is_NFC_LPConditionChk_Chart = App_Mode_IN_NFC_LPCondition_Off;
    *rty_NFCMode_LPConditionFlag_wri = 0U;
  } else if (localDW->is_NFC_LPConditionChk_Chart == App_Mode_IN_NFC_LPCondition_Off) {
    *rty_NFCMode_LPConditionFlag_wri = 0U;
    if ((rtu_WPCStatus != LPCDMode) && (rtu_WPCStatus != NFCMode) && (rtu_WPCStatus != PICCMode)) {
      localDW->is_NFC_LPConditionChk_Chart = App_Model_IN_NFC_LPCondition_On;
      *rty_NFCMode_LPConditionFlag_wri = 1U;
    }
  } else {
    /* case IN_NFC_LPCondition_On: */
    *rty_NFCMode_LPConditionFlag_wri = 1U;
    if ((rtu_WPCStatus == LPCDMode) || (rtu_WPCStatus == NFCMode) || (rtu_WPCStatus == PICCMode)) {
      localDW->is_NFC_LPConditionChk_Chart = App_Mode_IN_NFC_LPCondition_Off;
      *rty_NFCMode_LPConditionFlag_wri = 0U;
    }
  }

  /* End of Chart: '<S424>/NFC_Mode_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/OverCurrent_LPConditionJdg'
 *    '<S425>/OverCurrent_LPConditionJdg'
 */
void OverCurrent_LPConditionJdg_Init(uint8 *rty_OverCurrent_LPConditionFlag)
{
  *rty_OverCurrent_LPConditionFlag = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/OverCurrent_LPConditionJdg'
 *    '<S425>/OverCurrent_LPConditionJdg'
 */
void OverCurrent_LPConditionJd_Reset(uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW)
{
  localDW->is_OverCurrent_LPConditionChk_C = App_Model_IN_NO_ACTIVE_CHILD_j;
  localDW->is_active_c24_App_Model = 0U;
  *rty_OverCurrent_LPConditionFlag = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/OverCurrent_LPConditionJdg'
 *    '<S425>/OverCurrent_LPConditionJdg'
 */
void App__OverCurrent_LPConditionJdg(Bool rtu_b_CurrentFault, uint8 rtu_b_Timer_OvrCurr, uint16 rtu_b_Timer_ReOvrCurr, uint8 *rty_OverCurrent_LPConditionFlag, DW_OverCurrent_LPConditionJdg_T *localDW)
{
  /* Chart: '<S424>/OverCurrent_LPConditionJdg' */
  if (localDW->is_active_c24_App_Model == 0U) {
    localDW->is_active_c24_App_Model = 1U;
    localDW->is_OverCurrent_LPConditionChk_C = IN_OverCurrent_LPCondition_Off;
    *rty_OverCurrent_LPConditionFlag = 0U;
  } else if (localDW->is_OverCurrent_LPConditionChk_C == IN_OverCurrent_LPCondition_Off) {
    *rty_OverCurrent_LPConditionFlag = 0U;
    if ((rtu_b_CurrentFault == Off) && (rtu_b_Timer_OvrCurr == 0) && (rtu_b_Timer_ReOvrCurr == 0)) {
      localDW->is_OverCurrent_LPConditionChk_C = A_IN_OverCurrent_LPCondition_On;
      *rty_OverCurrent_LPConditionFlag = 1U;
    }
  } else {
    /* case IN_OverCurrent_LPCondition_On: */
    *rty_OverCurrent_LPConditionFlag = 1U;
    if ((rtu_b_CurrentFault == On) || (rtu_b_Timer_OvrCurr > 0) || (rtu_b_Timer_ReOvrCurr > 0)) {
      localDW->is_OverCurrent_LPConditionChk_C = IN_OverCurrent_LPCondition_Off;
      *rty_OverCurrent_LPConditionFlag = 0U;
    }
  }

  /* End of Chart: '<S424>/OverCurrent_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/OverTempDetect_LPConditionJdg'
 *    '<S425>/OverTempDetect_LPConditionJdg'
 */
void OverTempDetect_LPCondition_Init(uint8 *rty_OverTempDetect_LPConditionF)
{
  *rty_OverTempDetect_LPConditionF = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/OverTempDetect_LPConditionJdg'
 *    '<S425>/OverTempDetect_LPConditionJdg'
 */
void OverTempDetect_LPConditio_Reset(uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW)
{
  localDW->is_OverTempDetect_LPConditionCh = App_Model_IN_NO_ACTIVE_CHILD_pv;
  localDW->is_active_c12_App_Model = 0U;
  *rty_OverTempDetect_LPConditionF = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/OverTempDetect_LPConditionJdg'
 *    '<S425>/OverTempDetect_LPConditionJdg'
 */
void A_OverTempDetect_LPConditionJdg(Bool rtu_b_TemperatureFault, uint8 rtu_b_Timer_OverTemp, uint8 *rty_OverTempDetect_LPConditionF, DW_OverTempDetect_LPCondition_T *localDW)
{
  /* Chart: '<S424>/OverTempDetect_LPConditionJdg' */
  if (localDW->is_active_c12_App_Model == 0U) {
    localDW->is_active_c12_App_Model = 1U;
    localDW->is_OverTempDetect_LPConditionCh = IN_OverTempDetect_LPCondition_O;
    *rty_OverTempDetect_LPConditionF = 0U;
  } else if (localDW->is_OverTempDetect_LPConditionCh == IN_OverTempDetect_LPCondition_O) {
    *rty_OverTempDetect_LPConditionF = 0U;
    if ((rtu_b_TemperatureFault == Off) && (rtu_b_Timer_OverTemp == 0)) {
      localDW->is_OverTempDetect_LPConditionCh = IN_OverTempDetect_LPCondition_i;
      *rty_OverTempDetect_LPConditionF = 1U;
    }
  } else {
    /* case IN_OverTempDetect_LPCondition_On: */
    *rty_OverTempDetect_LPConditionF = 1U;
    if ((rtu_b_TemperatureFault == On) || (rtu_b_Timer_OverTemp > 0)) {
      localDW->is_OverTempDetect_LPConditionCh = IN_OverTempDetect_LPCondition_O;
      *rty_OverTempDetect_LPConditionF = 0U;
    }
  }

  /* End of Chart: '<S424>/OverTempDetect_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/SMKLF_LPConditionJdg'
 *    '<S425>/SMKLF_LPConditionJdg'
 */
void App_M_SMKLF_LPConditionJdg_Init(uint8 *rty_SMKLF_LPConditionFlag_write)
{
  *rty_SMKLF_LPConditionFlag_write = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/SMKLF_LPConditionJdg'
 *    '<S425>/SMKLF_LPConditionJdg'
 */
void App__SMKLF_LPConditionJdg_Reset(uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW)
{
  localDW->is_SMKLF_LPConditionChk_Chart = App_Model_IN_NO_ACTIVE_CHILD_k;
  localDW->is_active_c9_App_Model = 0U;
  *rty_SMKLF_LPConditionFlag_write = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/SMKLF_LPConditionJdg'
 *    '<S425>/SMKLF_LPConditionJdg'
 */
void App_Model_SMKLF_LPConditionJdg(Bool rtu_b_LFState, uint8 *rty_SMKLF_LPConditionFlag_write, DW_SMKLF_LPConditionJdg_App_M_T *localDW)
{
  /* Chart: '<S424>/SMKLF_LPConditionJdg' */
  if (localDW->is_active_c9_App_Model == 0U) {
    localDW->is_active_c9_App_Model = 1U;
    localDW->is_SMKLF_LPConditionChk_Chart = App_Mo_IN_SMKLF_LPCondition_Off;
    *rty_SMKLF_LPConditionFlag_write = 0U;
  } else if (localDW->is_SMKLF_LPConditionChk_Chart == App_Mo_IN_SMKLF_LPCondition_Off) {
    *rty_SMKLF_LPConditionFlag_write = 0U;
    if (rtu_b_LFState == Off) {
      localDW->is_SMKLF_LPConditionChk_Chart = App_Mod_IN_SMKLF_LPCondition_On;
      *rty_SMKLF_LPConditionFlag_write = 1U;
    }
  } else {
    /* case IN_SMKLF_LPCondition_On: */
    *rty_SMKLF_LPConditionFlag_write = 1U;
    if (rtu_b_LFState == On) {
      localDW->is_SMKLF_LPConditionChk_Chart = App_Mo_IN_SMKLF_LPCondition_Off;
      *rty_SMKLF_LPConditionFlag_write = 0U;
    }
  }

  /* End of Chart: '<S424>/SMKLF_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S425>/TempSnsrErrDetect_LPConditionJdg'
 */
void TempSnsrErrDetect_LPCondit_Init(uint8 *rty_TempSnsrError_LPConditionFl)
{
  *rty_TempSnsrError_LPConditionFl = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S425>/TempSnsrErrDetect_LPConditionJdg'
 */
void TempSnsrErrDetect_LPCondi_Reset(uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW)
{
  localDW->is_TempSnsrErrDetect_LPConditio = App_Model_IN_NO_ACTIVE_CHILD_n;
  localDW->is_active_c10_App_Model = 0U;
  *rty_TempSnsrError_LPConditionFl = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/TempSnsrErrDetect_LPConditionJdg'
 *    '<S425>/TempSnsrErrDetect_LPConditionJdg'
 */
void TempSnsrErrDetect_LPConditionJd(Bool rtu_b_TempSensorFault, uint8 rtu_b_Timer_TempSensor_Check, uint8 *rty_TempSnsrError_LPConditionFl, DW_TempSnsrErrDetect_LPCondit_T *localDW)
{
  /* Chart: '<S424>/TempSnsrErrDetect_LPConditionJdg' */
  if (localDW->is_active_c10_App_Model == 0U) {
    localDW->is_active_c10_App_Model = 1U;
    localDW->is_TempSnsrErrDetect_LPConditio = IN_TempSnsrErrDetect_LPConditio;
    *rty_TempSnsrError_LPConditionFl = 0U;
  } else if (localDW->is_TempSnsrErrDetect_LPConditio == IN_TempSnsrErrDetect_LPConditio) {
    *rty_TempSnsrError_LPConditionFl = 0U;
    if ((rtu_b_TempSensorFault == Off) && (rtu_b_Timer_TempSensor_Check == 0)) {
      localDW->is_TempSnsrErrDetect_LPConditio = IN_TempSnsrErrDetect_LPCondit_j;
      *rty_TempSnsrError_LPConditionFl = 1U;
    }
  } else {
    /* case IN_TempSnsrErrDetect_LPCondition_On: */
    *rty_TempSnsrError_LPConditionFl = 1U;
    if ((rtu_b_TempSensorFault == On) || (rtu_b_Timer_TempSensor_Check > 0)) {
      localDW->is_TempSnsrErrDetect_LPConditio = IN_TempSnsrErrDetect_LPConditio;
      *rty_TempSnsrError_LPConditionFl = 0U;
    }
  }

  /* End of Chart: '<S424>/TempSnsrErrDetect_LPConditionJdg' */
}

/*
 * System initialize for atomic system:
 *    '<S424>/WPC_Mode_LPConditionJdg'
 *    '<S425>/WPC_Mode_LPConditionJdg'
 */
void Ap_WPC_Mode_LPConditionJdg_Init(uint8 *rty_WPCMode_LPConditionFlag_wri)
{
  *rty_WPCMode_LPConditionFlag_wri = 0U;
}

/*
 * System reset for atomic system:
 *    '<S424>/WPC_Mode_LPConditionJdg'
 *    '<S425>/WPC_Mode_LPConditionJdg'
 */
void A_WPC_Mode_LPConditionJdg_Reset(uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW)
{
  localDW->is_WPC_LPConditionChk_Chart = App_Model_IN_NO_ACTIVE_CHILD_ey;
  localDW->is_active_c2_App_Model = 0U;
  *rty_WPCMode_LPConditionFlag_wri = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S424>/WPC_Mode_LPConditionJdg'
 *    '<S425>/WPC_Mode_LPConditionJdg'
 */
void App_Mod_WPC_Mode_LPConditionJdg(WPCStatus rtu_WPCStatus, uint8 *rty_WPCMode_LPConditionFlag_wri, DW_WPC_Mode_LPConditionJdg_Ap_T *localDW)
{
  /* Chart: '<S424>/WPC_Mode_LPConditionJdg' */
  if (localDW->is_active_c2_App_Model == 0U) {
    localDW->is_active_c2_App_Model = 1U;
    localDW->is_WPC_LPConditionChk_Chart = App_Mode_IN_WPC_LPCondition_Off;
    *rty_WPCMode_LPConditionFlag_wri = 0U;
  } else if (localDW->is_WPC_LPConditionChk_Chart == App_Mode_IN_WPC_LPCondition_Off) {
    *rty_WPCMode_LPConditionFlag_wri = 0U;
    if (rtu_WPCStatus != WPCMode) {
      localDW->is_WPC_LPConditionChk_Chart = App_Model_IN_WPC_LPCondition_On;
      *rty_WPCMode_LPConditionFlag_wri = 1U;
    }
  } else {
    /* case IN_WPC_LPCondition_On: */
    *rty_WPCMode_LPConditionFlag_wri = 1U;
    if (rtu_WPCStatus == WPCMode) {
      localDW->is_WPC_LPConditionChk_Chart = App_Mode_IN_WPC_LPCondition_Off;
      *rty_WPCMode_LPConditionFlag_wri = 0U;
    }
  }

  /* End of Chart: '<S424>/WPC_Mode_LPConditionJdg' */
}

/* Function for Chart: '<S424>/USM_WPC_LPCondition' */
static void App_Model_LPConditionHold(void)
{
  switch (App_Model_DW.is_LPConditionHold_j) {
   case App_Mode_IN_LPConditionHold_Off:
    if (App_Model_DW.sfEvent_e == event_StartTimer_LPConditionHol) {
      App_Model_DW.is_LPConditionHold_j = App_Model_IN_LPConditionHold_On;
    }
    break;

   case App_Model_IN_LPConditionHold_On:
    {
      switch (App_Model_DW.sfEvent_e) {
       case event_CancelTimer_LPConditionHo:
        App_Model_DW.is_LPConditionHold_j = App_Mode_IN_LPConditionHold_Off;
        App_Model_DW.Timer_LPConditionHold_c = 0U;
        break;

       case event_StartTimer_LPConditionHol:
        App_Model_DW.Timer_LPConditionHold_c = 0U;
        App_Model_DW.is_LPConditionHold_j = App_Model_IN_LPConditionHold_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPConditionHold_c + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_LPConditionHold_c + 1U < App_Model_DW.Timer_LPConditionHold_c) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPConditionHold_c = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S424>/USM_WPC_LPCondition' */
static void App_Model_LPConditionTimerCheck(void)
{
  if ((App_Model_DW.m_ProfileGuestWPCUSM_App_prev != App_Model_DW.m_ProfileGuestWPCUSM_App_start) || (App_Model_DW.m_ProfileOneWPCUSM_App_prev != App_Model_DW.m_ProfileOneWPCUSM_App_start) ||
      (App_Model_DW.m_ProfileTwoWPCUSM_App_prev != App_Model_DW.m_ProfileTwoWPCUSM_App_start)) {
    sint32 c_previousEvent;
    App_Model_DW.ECUResetEnable_j = 0U;
    c_previousEvent = App_Model_DW.sfEvent_e;
    App_Model_DW.sfEvent_e = event_StartTimer_LPConditionHol;
    if (App_Model_DW.is_active_LPConditionHold_n != 0U) {
      App_Model_LPConditionHold();
    }

    App_Model_DW.sfEvent_e = c_previousEvent;
  } else if (App_Model_DW.Timer_LPConditionHold_c >= 100U) {
    sint32 c_previousEvent;
    App_Model_DW.ECUResetEnable_j = 1U;
    c_previousEvent = App_Model_DW.sfEvent_e;
    App_Model_DW.sfEvent_e = event_CancelTimer_LPConditionHo;
    if (App_Model_DW.is_active_LPConditionHold_n != 0U) {
      App_Model_LPConditionHold();
    }

    App_Model_DW.sfEvent_e = c_previousEvent;
  }
}

/* Function for Chart: '<S425>/USM_WPC2_LPCondition' */
static void App_Model_LPConditionHold_h(void)
{
  switch (App_Model_DW.is_LPConditionHold) {
   case App_Mode_IN_LPConditionHold_Off:
    if (App_Model_DW.sfEvent == event_StartTimer_LPConditionHol) {
      App_Model_DW.is_LPConditionHold = App_Model_IN_LPConditionHold_On;
    }
    break;

   case App_Model_IN_LPConditionHold_On:
    {
      switch (App_Model_DW.sfEvent) {
       case event_CancelTimer_LPConditionHo:
        App_Model_DW.is_LPConditionHold = App_Mode_IN_LPConditionHold_Off;
        App_Model_DW.Timer_LPConditionHold = 0U;
        break;

       case event_StartTimer_LPConditionHol:
        App_Model_DW.Timer_LPConditionHold = 0U;
        App_Model_DW.is_LPConditionHold = App_Model_IN_LPConditionHold_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPConditionHold + /*MW:OvSatOk*/ 1U;
          if (App_Model_DW.Timer_LPConditionHold + 1U < App_Model_DW.Timer_LPConditionHold) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPConditionHold = qY;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S425>/USM_WPC2_LPCondition' */
static void App_Mod_LPConditionTimerCheck_i(void)
{
  if ((App_Model_DW.m_ProfileGuestWPC2USM_App_prev != App_Model_DW.m_ProfileGuestWPC2USM_App_start) || (App_Model_DW.m_ProfileOneWPC2USM_App_prev != App_Model_DW.m_ProfileOneWPC2USM_App_start) ||
      (App_Model_DW.m_ProfileTwoWPC2USM_App_prev != App_Model_DW.m_ProfileTwoWPC2USM_App_start)) {
    sint32 c_previousEvent;
    App_Model_DW.ECUResetEnable = 0U;
    c_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = event_StartTimer_LPConditionHol;
    if (App_Model_DW.is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold_h();
    }

    App_Model_DW.sfEvent = c_previousEvent;
  } else if (App_Model_DW.Timer_LPConditionHold >= 100U) {
    sint32 c_previousEvent;
    App_Model_DW.ECUResetEnable = 1U;
    c_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = event_CancelTimer_LPConditionHo;
    if (App_Model_DW.is_active_LPConditionHold != 0U) {
      App_Model_LPConditionHold_h();
    }

    App_Model_DW.sfEvent = c_previousEvent;
  }
}

/* Model step function */
void Model_TE_Runnable(void)
{
  /* local block i/o variables */
  IDT_NvM_STR rtb_TmpSignalConversionAtR_NvM_;
  uint16 rtb_FAN_PWM;
  uint8 rtb_WPCMode_LPConditionFlag_wri;
  uint8 rtb_TempSnsrError_LPConditionFl;
  uint8 rtb_SMKLF_LPConditionFlag_write;
  uint8 rtb_OverTempDetect_LPConditionF;
  uint8 rtb_OverCurrent_LPConditionFlag;
  uint8 rtb_NFCMode_LPConditionFlag_wri;
  uint8 rtb_WPCMain_LPConditionFlag_wri;
  uint8 rtb_FAN_LPConditionFlag_write;
  Bool rtb_b_SyncLED;
  Bool rtb_b_CmdLEDSync;
  Bool rtb_b_SyncLED_i;
  Bool rtb_b_CmdLEDSync_g;
  Bool rtb_NfcOnthepad_Jdg;
  Bool rtb_ChargingOnthepad_Jdg;
  Bool rtb_ObjectOnthepad_Jdg;
  IDT_ADC_STR rtb_TmpSignalConversionAtR_ADC_;
  IDT_CAN_RX_STR rtb_TmpSignalConversionAtR_CAN_;
  IDT_Model_STR rtb_BusCreator;
  IDT_NFC_STR rtb_TmpSignalConversionAtR_NFC_;
  IDT_Uds_STR rtb_TmpSignalConversionAtR_Uds_;
  IDT_WCT_STR rtb_TmpSignalConversionAtR_WCT_;

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
  (void)Rte_Read_R_UART_UART_STR(&App_Model_B.TmpSignalConversionAtR_UART_UAR);

  /* SignalConversion generated from: '<Root>/Bus Element In7' */
  (void)Rte_Read_R_WCT_WCT_STR(&rtb_TmpSignalConversionAtR_WCT_);

  /* Outputs for Atomic SubSystem: '<Root>/AppInit' */
  /* FunctionCaller: '<S1>/R_CS_Mode_ApplicationInit'
   *
   * Block description for '<S1>/R_CS_Mode_ApplicationInit':
   *  AppInitFlag && NvMInitFlag 완료 시, Application 구동 시작.
   */
  Rte_Call_R_CS_Mode_ApplicationInit(&App_Model_B.AppInit_En);

  /* End of Outputs for SubSystem: '<Root>/AppInit' */

  /* Outputs for Triggered SubSystem: '<Root>/AppInit_DataRead' */
  App_Model_AppInit_DataRead(&rtb_TmpSignalConversionAtR_NvM_);

  /* End of Outputs for SubSystem: '<Root>/AppInit_DataRead' */

  /* Outputs for Enabled SubSystem: '<Root>/App_Model_TE_Sys' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (App_Model_B.AppInit_En) {
    OnThePad rtb_WCT2_ChargingOnthePad;
    OnThePad rtb_WCT2_ObjectOnthePad;
    boolean rtb_DualWPCEn_n;
    App_Model_DW.App_Model_TE_Sys_MODE = true;

    /* DataTypeConversion: '<S410>/Data Type Conversion40' */
    App_Model_B.NvM_IndUSMOption = rtb_TmpSignalConversionAtR_NvM_.IndUSMOption;

    /* DataTypeConversion: '<S403>/Data Type Conversion' */
    App_Model_B.ADC_IGN1_IN = rtb_TmpSignalConversionAtR_ADC_.IGN1_IN;

    /* DataTypeConversion: '<S404>/Data Type Conversion1' */
    App_Model_B.BCAN_RX_C_LFAnt_SrchSta = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_LFAnt_SrchSta;

    /* DataTypeConversion: '<S404>/Data Type Conversion16' */
    App_Model_B.BCAN_RX_RheoStatLevel = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RheoStatLevel;

    /* DataTypeConversion: '<S404>/Data Type Conversion18' */
    App_Model_B.BCAN_RX_C_WPCOnOffNvalueSet = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPCOnOffNvalueSet;

    /* DataTypeConversion: '<S404>/Data Type Conversion43' */
    App_Model_B.BCAN_RX_C_CF_Gway_WPCAnimationN = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_Gway_WPCAnimationNvalueSet;

    /* DataTypeConversion: '<S404>/Data Type Conversion19' */
    App_Model_B.BCAN_RX_C_USMReset = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_USMReset;

    /* DataTypeConversion: '<S404>/Data Type Conversion20' */
    App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_IAU_ProfileIDRVal;

    /* DataTypeConversion: '<S404>/Data Type Conversion21' */
    App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CF_AVN_ProfileIDRValue;

    /* DataTypeConversion: '<S404>/Data Type Conversion39' */
    App_Model_B.BCAN_RX_C_AutoBrightLevel = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_AutoBrightLevel;

    /* DataTypeConversion: '<S404>/Data Type Conversion10' */
    App_Model_B.BCAN_RX_C_BCM_SmkOptTyp = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_BCM_SmkOptTyp;

    /* DataTypeConversion: '<S404>/Data Type Conversion13' */
    App_Model_B.b_AstDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta;

    /* DataTypeConversion: '<S404>/Data Type Conversion12' */
    App_Model_B.b_DrvDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta;

    /* DataTypeConversion: '<S404>/Data Type Conversion14' */
    App_Model_B.b_RLDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta;

    /* DataTypeConversion: '<S404>/Data Type Conversion15' */
    App_Model_B.b_RRDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta;

    /* Chart: '<S404>/Door OpenClose State Function Flow Graph' incorporates:
     *  DataTypeConversion: '<S404>/Data Type Conversion35'
     *  DataTypeConversion: '<S404>/Data Type Conversion47'
     *  DataTypeConversion: '<S404>/Data Type Conversion48'
     *  DataTypeConversion: '<S404>/Data Type Conversion49'
     *  DataTypeConversion: '<S404>/Data Type Conversion51'
     */
    if (App_Model_DW.is_active_c6_App_Model == 0U) {
      App_Model_DW.is_active_c6_App_Model = 1U;
      if (rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Latch_TypeOption_DRV == Latch_On) {
        App_Model_B.b_DrvDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta_SBCM;
        App_Model_B.b_AstDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta_SBCM;
        App_Model_B.b_RLDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta_SBCM;
        App_Model_B.b_RRDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta_SBCM;
      }
    } else if (rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Latch_TypeOption_DRV == Latch_On) {
      App_Model_B.b_DrvDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_DrvDrSwSta_SBCM;
      App_Model_B.b_AstDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_AsstDrSwSta_SBCM;
      App_Model_B.b_RLDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrLftDrSwSta_SBCM;
      App_Model_B.b_RRDrSw = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Warn_RrRtDrSwSta_SBCM;
    }

    /* End of Chart: '<S404>/Door OpenClose State Function Flow Graph' */

    /* DataTypeConversion: '<S404>/Data Type Conversion42' */
    App_Model_B.BCAN_C_RWPCIndSyncVal = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_RWPC_IndSyncVal;

    /* DataTypeConversion: '<S404>/Data Type Conversion25' */
    App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcmd = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC_IAUWPCNFCcmd;

    /* DataTypeConversion: '<S404>/Data Type Conversion26' */
    App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_WPC2_IAUWPCNFCcmd;

    /* DataTypeConversion: '<S404>/Data Type Conversion37' */
    App_Model_B.LCAN_RX_LC_OwnerKey_Reg_Status = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerKey_Reg_Status;

    /* DataTypeConversion: '<S404>/Data Type Conversion44' */
    App_Model_B.LCAN_RX_LC_OwnerPairingAdvertis = rtb_TmpSignalConversionAtR_CAN_.LCAN.LC_OwnerPairingAdvertisingReq;

    /* DataTypeConversion: '<S409>/Data Type Conversion34' */
    App_Model_B.NFC1_LC_WPC_NFCDetection = rtb_TmpSignalConversionAtR_NFC_.Device[0].NFCDetection;

    /* DataTypeConversion: '<S409>/Data Type Conversion1' */
    App_Model_B.NFC1_NfcOnThePad = rtb_TmpSignalConversionAtR_NFC_.Device[0].NfcOnThePad;

    /* DataTypeConversion: '<S409>/Data Type Conversion83' */
    App_Model_B.NFC1_CardProtectionResult = rtb_TmpSignalConversionAtR_NFC_.Device[0].CardProtectionResult;

    /* DataTypeConversion: '<S411>/Data Type Conversion29' */
    App_Model_B.UART_WPC1_PhoneLeft = App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[0].PhoneLeft;

    /* DataTypeConversion: '<S411>/Data Type Conversion36' */
    App_Model_B.UART_WPC1_DeviceState = App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[0].DeviceState;

    /* DataTypeConversion: '<S411>/Data Type Conversion6' */
    App_Model_B.UART_WPC1_Temp_SnsrError = App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[0].TempSnsrError;

    /* Outputs for Atomic SubSystem: '<S10>/DWPC1_TE_sys' */
    /* Outputs for Atomic SubSystem: '<S13>/USMSettingControl_Function' */
    /* DataTypeConversion: '<S412>/Data Type Conversion32' incorporates:
     *  DataTypeConversion: '<S403>/Data Type Conversion8'
     *  UnitDelay: '<S408>/Unit Delay15'
     *  UnitDelay: '<S408>/Unit Delay17'
     *  UnitDelay: '<S408>/Unit Delay18'
     *  UnitDelay: '<S408>/Unit Delay20'
     *  UnitDelay: '<S408>/Unit Delay21'
     *  UnitDelay: '<S408>/Unit Delay6'
     *  UnitDelay: '<S408>/Unit Delay7'
     *  UnitDelay: '<S408>/Unit Delay8'
     */
    App__USMSettingControl_Function(rtb_TmpSignalConversionAtR_Uds_.m_NFCOption, App_Model_B.BCAN_RX_C_WPCOnOffNvalueSet, App_Model_B.BCAN_RX_C_USMReset, App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu,
      App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal, &App_Model_B.C_WPCRValue, &App_Model_B.WPCSWOption);

    /* End of Outputs for SubSystem: '<S13>/USMSettingControl_Function' */

    /* Outputs for Atomic SubSystem: '<S18>/NFC_WPC_Mode_Control_Function' */
    A_NFC_WPC_Mode_Control_Function(rtb_TmpSignalConversionAtR_Uds_.m_NFCOption, App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcmd, App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd, App_Model_B.ADC_IGN1_IN,
      App_Model_B.LCAN_RX_LC_OwnerKey_Reg_Status, App_Model_B.LCAN_RX_LC_OwnerPairingAdvertis, App_Model_B.WPCSWOption, App_Model_B.NFC1_NfcOnThePad, App_Model_B.NFC1_LC_WPC_NFCDetection,
      App_Model_DW.UnitDelay20_DSTATE, App_Model_DW.UnitDelay21_DSTATE, App_Model_DW.UnitDelay7_DSTATE, App_Model_DW.UnitDelay17_DSTATE, App_Model_DW.UnitDelay8_DSTATE, App_Model_B.b_DrvDrSw,
      App_Model_DW.UnitDelay15_DSTATE, App_Model_DW.UnitDelay18_DSTATE, App_Model_DW.UnitDelay6_DSTATE, rtb_TmpSignalConversionAtR_ADC_.BatSysStateFault, &App_Model_B.WPCStatus_h);

    /* End of Outputs for SubSystem: '<S18>/NFC_WPC_Mode_Control_Function' */

    /* Outputs for Atomic SubSystem: '<S18>/TemperatureSensorErrorDetect_Function' */
    /* Constant: '<S406>/Constant5' incorporates:
     *  Constant: '<S406>/Constant'
     */
    TemperatureSensorErrorDetect_Fu(App_Model_B.WPCStatus_h, App_Model_B.UART_WPC1_Temp_SnsrError, Off, Off, &App_Model_B.b_TempSensorFault_a, &App_Model_B.b_Timer_TempSensor_Check_d);

    /* End of Outputs for SubSystem: '<S18>/TemperatureSensorErrorDetect_Function' */

    /* Outputs for Atomic SubSystem: '<S18>/PreventionSMK_LF_Interference_Function' */
    /* Constant: '<S406>/Constant1' */
    PreventionSMK_LF_Interference_F(App_Model_B.WPCStatus_h, App_Model_B.BCAN_RX_C_BCM_SmkOptTyp, App_Model_B.BCAN_RX_C_LFAnt_SrchSta, App_Model_B.b_AstDrSw, App_Model_B.b_DrvDrSw,
      App_Model_B.b_RLDrSw, App_Model_B.b_RRDrSw, Off, &App_Model_B.b_LFState_m);

    /* End of Outputs for SubSystem: '<S18>/PreventionSMK_LF_Interference_Function' */

    /* Outputs for Atomic SubSystem: '<S18>/OverCurrentDetecting_Function' */
    A_OverCurrentDetecting_Function(App_Model_B.WPCStatus_h, App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[0].ChargingCurrent, &App_Model_B.b_CurrentFault_j, &App_Model_B.b_Timer_OvrCurr_d,
      &App_Model_B.b_Timer_ReOvrCurr_d);

    /* End of Outputs for SubSystem: '<S18>/OverCurrentDetecting_Function' */

    /* Outputs for Atomic SubSystem: '<S18>/OverTemperatureDetecting_Function' */
    /* Constant: '<S406>/Constant2' incorporates:
     *  Constant: '<S406>/Constant3'
     */
    OverTemperatureDetecting_Functi(App_Model_B.WPCStatus_h, App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[0].CoilTempDegree, 0, 0, App_Model_B.UART_WPC1_DeviceState,
      &App_Model_B.b_TemperatureFault_c, &App_Model_B.b_Timer_OverTemp_p);

    /* End of Outputs for SubSystem: '<S18>/OverTemperatureDetecting_Function' */

    /* Outputs for Atomic SubSystem: '<S18>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectingControl_F(App_Model_B.NFC1_CardProtectionResult, &App_Model_B.b_CardProtection_i);

    /* End of Outputs for SubSystem: '<S18>/WPC_PhoneLeftDetectingControl_Function' */

    /* Outputs for Atomic SubSystem: '<S13>/WPC_MainControl_Function' */
    /* UnitDelay: '<S408>/Unit Delay' incorporates:
     *  UnitDelay: '<S408>/Unit Delay4'
     *  UnitDelay: '<S408>/Unit Delay9'
     */
    App_Mo_WPC_MainControl_Function(App_Model_B.b_LFState_m, App_Model_B.b_CurrentFault_j, App_Model_B.b_TempSensorFault_a, App_Model_B.WPCSWOption, App_Model_B.b_TemperatureFault_c,
      App_Model_B.b_AstDrSw, App_Model_B.b_DrvDrSw, App_Model_B.UART_WPC1_PhoneLeft, App_Model_B.UART_WPC1_DeviceState, App_Model_B.WPCStatus_h, App_Model_B.ADC_IGN1_IN, App_Model_DW.UnitDelay_DSTATE,
      App_Model_DW.UnitDelay9_DSTATE, App_Model_DW.UnitDelay4_DSTATE, App_Model_B.b_CardProtection_i, &App_Model_B.C_WPCWarning_i, &App_Model_B.b_FANModeCmd_f, &App_Model_B.b_GreenINDCmd_o,
      &App_Model_B.b_AmberINDCmd_g, &App_Model_B.b_BlinkState_n, &App_Model_B.b_Timer_PhoneReminderCheck_n, &App_Model_B.b_Timer_PhoneWarningCheck_i, &App_Model_B.b_Timer_WarningComplete_e,
      &App_Model_B.b_ChargingEnable_n, &App_Model_B.BlinkState_p, &App_Model_B.b_PhnLeftChk_Enable_j);

    /* End of Outputs for SubSystem: '<S13>/WPC_MainControl_Function' */

    /* Outputs for Atomic SubSystem: '<S17>/FAN_Control_Function' */
    rtb_FAN_PWM = App_Model_FAN_Control_Function(App_Model_B.b_FANModeCmd_f);

    /* End of Outputs for SubSystem: '<S17>/FAN_Control_Function' */

    /* Outputs for Atomic SubSystem: '<S17>/IND_Animation_Control_Function' */
    /* UnitDelay: '<S408>/Unit Delay2' incorporates:
     *  UnitDelay: '<S408>/Unit Delay'
     *  UnitDelay: '<S408>/Unit Delay10'
     *  UnitDelay: '<S408>/Unit Delay13'
     *  UnitDelay: '<S408>/Unit Delay5'
     */
    IND_Animation_Control_Function(App_Model_DW.UnitDelay2_DSTATE, App_Model_B.BCAN_C_RWPCIndSyncVal, App_Model_B.C_WPCWarning_i, App_Model_DW.UnitDelay13_DSTATE, App_Model_DW.UnitDelay5_DSTATE,
      App_Model_DW.UnitDelay_DSTATE, App_Model_DW.UnitDelay10_DSTATE, App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal, App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu, App_Model_B.NvM_IndUSMOption,
      App_Model_B.BCAN_RX_C_CF_Gway_WPCAnimationN, App_Model_B.BCAN_RX_C_USMReset, &App_Model_B.Output_INT_WPCIndUSMState, &App_Model_B.Output_CAN_WPCIndSyncVal, &App_Model_B.Output_INT_WPCIndCmdState);

    /* End of Outputs for SubSystem: '<S17>/IND_Animation_Control_Function' */

    /* Outputs for Atomic SubSystem: '<S17>/IndyOutputControl_Function' */
    /* DataTypeConversion: '<S410>/Data Type Conversion45' incorporates:
     *  DataTypeConversion: '<S404>/Data Type Conversion17'
     *  DataTypeConversion: '<S404>/Data Type Conversion50'
     *  DataTypeConversion: '<S410>/Data Type Conversion52'
     *  UnitDelay: '<S408>/Unit Delay'
     *  UnitDelay: '<S408>/Unit Delay10'
     *  UnitDelay: '<S408>/Unit Delay4'
     */
    App__IndyOutputControl_Function(rtb_TmpSignalConversionAtR_NvM_.INDContType, App_Model_B.b_AmberINDCmd_g, App_Model_DW.UnitDelay10_DSTATE, App_Model_DW.UnitDelay4_DSTATE,
      rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DtntOutSta, rtb_TmpSignalConversionAtR_NvM_.RheostatOption, rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Lamp_IntTailLmpOnReq, App_Model_B.b_GreenINDCmd_o,
      App_Model_DW.UnitDelay_DSTATE, App_Model_B.BCAN_RX_RheoStatLevel, App_Model_B.BCAN_RX_C_AutoBrightLevel, &App_Model_B.P_GreenIND_OUT_c, &App_Model_B.P_GreenIND2_OUT_d,
      &App_Model_B.P_GreenIND3_OUT_o, &App_Model_B.P_AmberIND_OUT_j);

    /* End of Outputs for SubSystem: '<S17>/IndyOutputControl_Function' */
    /* End of Outputs for SubSystem: '<S10>/DWPC1_TE_sys' */

    /* DataTypeConversion: '<S404>/Data Type Conversion4' */
    App_Model_B.BCAN_RX_C_WPC2OnOffNvalueSet = rtb_TmpSignalConversionAtR_CAN_.BCAN.C_WPC2OnOffNvalueSet;

    /* DataTypeConversion: '<S409>/Data Type Conversion75' */
    App_Model_B.NFC2_LC_WPC_NFCDetection = rtb_TmpSignalConversionAtR_NFC_.Device[1].NFCDetection;

    /* Switch: '<S415>/Switch' incorporates:
     *  Constant: '<S417>/Constant'
     *  Constant: '<S418>/Constant'
     *  DataTypeConversion: '<S416>/Data Type Conversion1'
     *  Logic: '<S416>/OR'
     *  RelationalOperator: '<S417>/Compare'
     *  RelationalOperator: '<S418>/Compare'
     */
    if ((rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE == Type5) || (rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE == Type6)) {
      /* Switch: '<S415>/Switch' incorporates:
       *  DataTypeConversion: '<S415>/Data Type Conversion1'
       */
      App_Model_B.NFC2_NfcOnThePad = rtb_TmpSignalConversionAtR_NFC_.Device[1].NfcOnThePad;
    } else {
      /* Switch: '<S415>/Switch' incorporates:
       *  Constant: '<S415>/Constant'
       */
      App_Model_B.NFC2_NfcOnThePad = OnThePad_Off;
    }

    /* End of Switch: '<S415>/Switch' */

    /* DataTypeConversion: '<S409>/Data Type Conversion82' */
    App_Model_B.NFC2_CardProtectionResult = rtb_TmpSignalConversionAtR_NFC_.Device[1].CardProtectionResult;

    /* DataTypeConversion: '<S411>/Data Type Conversion47' */
    App_Model_B.UART_WPC2_PhoneLeft = App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[1].PhoneLeft;

    /* DataTypeConversion: '<S411>/Data Type Conversion49' */
    App_Model_B.UART_WPC2_DeviceState = App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[1].DeviceState;

    /* DataTypeConversion: '<S411>/Data Type Conversion55' */
    App_Model_B.UART_WPC2_Temp_SnsrError = App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[1].TempSnsrError;

    /* Logic: '<S16>/OR' incorporates:
     *  Constant: '<S401>/Constant'
     *  Constant: '<S402>/Constant'
     *  DataTypeConversion: '<S416>/Data Type Conversion1'
     *  RelationalOperator: '<S401>/Compare'
     *  RelationalOperator: '<S402>/Compare'
     */
    rtb_DualWPCEn_n = ((rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE == Type5) || (rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE == Type6));

    /* Outputs for Enabled SubSystem: '<S10>/DWPC2_TE_sys' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    if (rtb_DualWPCEn_n) {
      if (!App_Model_DW.DWPC2_TE_sys_MODE) {
        /* SystemReset for Atomic SubSystem: '<S203>/TemperatureSensorErrorDetect_Function' */
        TemperatureSensorErrorD_d_Reset(&App_Model_B.b_TempSensorFault, &App_Model_B.b_Timer_TempSensor_Check);

        /* End of SystemReset for SubSystem: '<S203>/TemperatureSensorErrorDetect_Function' */

        /* SystemReset for Atomic SubSystem: '<S203>/PreventionSMK_LF_Interference_Function' */
        PreventionSMK_LF_Interf_m_Reset(&App_Model_B.b_LFState);

        /* End of SystemReset for SubSystem: '<S203>/PreventionSMK_LF_Interference_Function' */

        /* SystemReset for Atomic SubSystem: '<S203>/OverCurrentDetecting_Function' */
        OverCurrentDetecting_Fu_f_Reset(&App_Model_B.b_CurrentFault, &App_Model_B.b_Timer_OvrCurr, &App_Model_B.b_Timer_ReOvrCurr);

        /* End of SystemReset for SubSystem: '<S203>/OverCurrentDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S203>/OverTemperatureDetecting_Function' */
        OverTemperatureDetectin_c_Reset(&App_Model_B.b_TemperatureFault, &App_Model_B.b_Timer_OverTemp);

        /* End of SystemReset for SubSystem: '<S203>/OverTemperatureDetecting_Function' */

        /* SystemReset for Atomic SubSystem: '<S203>/WPC_PhoneLeftDetectingControl_Function' */
        WPC_PhoneLeftDetectingC_f_Reset(&App_Model_B.b_CardProtection);

        /* End of SystemReset for SubSystem: '<S203>/WPC_PhoneLeftDetectingControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S14>/WPC_MainControl_Function' */
        WPC_MainControl_Functio_f_Reset(&App_Model_B.C_WPCWarning_a, &App_Model_B.b_FANModeCmd, &App_Model_B.b_GreenINDCmd, &App_Model_B.b_AmberINDCmd, &App_Model_B.b_BlinkState,
          &App_Model_B.b_Timer_PhoneReminderCheck, &App_Model_B.b_Timer_PhoneWarningCheck, &App_Model_B.b_Timer_WarningComplete, &App_Model_B.b_ChargingEnable, &App_Model_B.BlinkState_o,
          &App_Model_B.b_PhnLeftChk_Enable);

        /* End of SystemReset for SubSystem: '<S14>/WPC_MainControl_Function' */

        /* SystemReset for Atomic SubSystem: '<S202>/FAN_Control_Function' */
        Ap_FAN_Control_Function_a_Reset(&App_Model_B.FAN_PWM_o);

        /* End of SystemReset for SubSystem: '<S202>/FAN_Control_Function' */

        /* SystemReset for Atomic SubSystem: '<S202>/IND_Animation_Control_Function' */
        IND_Animation_Control_F_g_Reset(&App_Model_B.Output_CAN_WPC2IndSyncVal, &App_Model_B.Output_INT_WPC2IndCmdState);

        /* End of SystemReset for SubSystem: '<S202>/IND_Animation_Control_Function' */
        App_Model_DW.DWPC2_TE_sys_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S14>/USMSettingControl_Function' */
      /* DataTypeConversion: '<S412>/Data Type Conversion32' incorporates:
       *  DataTypeConversion: '<S403>/Data Type Conversion8'
       *  UnitDelay: '<S408>/Unit Delay16'
       *  UnitDelay: '<S408>/Unit Delay17'
       *  UnitDelay: '<S408>/Unit Delay19'
       *  UnitDelay: '<S408>/Unit Delay20'
       *  UnitDelay: '<S408>/Unit Delay21'
       *  UnitDelay: '<S408>/Unit Delay3'
       *  UnitDelay: '<S408>/Unit Delay6'
       *  UnitDelay: '<S408>/Unit Delay8'
       */
      Ap_USMSettingControl_Function_h(rtb_TmpSignalConversionAtR_Uds_.m_NFCOption, App_Model_B.BCAN_RX_C_WPC2OnOffNvalueSet, App_Model_B.BCAN_RX_C_USMReset, App_Model_B.BCAN_RX_C_CF_AVN_ProfileIDRValu,
        App_Model_B.BCAN_RX_C_IAU_ProfileIDRVal, &App_Model_B.C_WPC2RValue, &App_Model_B.WPC2SWOption);

      /* End of Outputs for SubSystem: '<S14>/USMSettingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S203>/NFC_WPC_Mode_Control_Function' */
      NFC_WPC_Mode_Control_Function_m(rtb_TmpSignalConversionAtR_Uds_.m_NFCOption, App_Model_B.ADC_IGN1_IN, App_Model_B.LCAN_RX_LC_WPC2_IAUWPCNFCcmd, App_Model_B.WPC2SWOption,
        App_Model_B.LCAN_RX_LC_OwnerKey_Reg_Status, App_Model_B.LCAN_RX_LC_OwnerPairingAdvertis, App_Model_B.NFC2_NfcOnThePad, App_Model_B.NFC2_LC_WPC_NFCDetection, App_Model_DW.UnitDelay20_DSTATE,
        App_Model_DW.UnitDelay21_DSTATE, App_Model_DW.UnitDelay3_DSTATE, App_Model_DW.UnitDelay17_DSTATE, App_Model_DW.UnitDelay8_DSTATE, App_Model_B.b_DrvDrSw, App_Model_DW.UnitDelay16_DSTATE,
        App_Model_DW.UnitDelay19_DSTATE, App_Model_B.LCAN_RX_LC_WPC_IAUWPCNFCcmd, App_Model_DW.UnitDelay6_DSTATE, rtb_TmpSignalConversionAtR_ADC_.BatSysStateFault, &App_Model_B.WPC2Status);

      /* End of Outputs for SubSystem: '<S203>/NFC_WPC_Mode_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S203>/TemperatureSensorErrorDetect_Function' */
      /* Constant: '<S406>/Constant5' incorporates:
       *  Constant: '<S406>/Constant'
       */
      TemperatureSensorErrorDetect__h(App_Model_B.WPC2Status, App_Model_B.UART_WPC2_Temp_SnsrError, Off, Off, &App_Model_B.b_TempSensorFault, &App_Model_B.b_Timer_TempSensor_Check);

      /* End of Outputs for SubSystem: '<S203>/TemperatureSensorErrorDetect_Function' */

      /* Outputs for Atomic SubSystem: '<S203>/PreventionSMK_LF_Interference_Function' */
      /* Constant: '<S406>/Constant1' */
      PreventionSMK_LF_Interference_c(App_Model_B.WPC2Status, App_Model_B.BCAN_RX_C_BCM_SmkOptTyp, App_Model_B.BCAN_RX_C_LFAnt_SrchSta, App_Model_B.b_AstDrSw, App_Model_B.b_DrvDrSw,
        App_Model_B.b_RLDrSw, App_Model_B.b_RRDrSw, Off, &App_Model_B.b_LFState);

      /* End of Outputs for SubSystem: '<S203>/PreventionSMK_LF_Interference_Function' */

      /* Outputs for Atomic SubSystem: '<S203>/OverCurrentDetecting_Function' */
      OverCurrentDetecting_Function_i(App_Model_B.WPC2Status, App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[1].ChargingCurrent, &App_Model_B.b_CurrentFault, &App_Model_B.b_Timer_OvrCurr,
        &App_Model_B.b_Timer_ReOvrCurr);

      /* End of Outputs for SubSystem: '<S203>/OverCurrentDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S203>/OverTemperatureDetecting_Function' */
      /* Constant: '<S406>/Constant2' incorporates:
       *  Constant: '<S406>/Constant3'
       */
      OverTemperatureDetecting_Func_a(App_Model_B.WPC2Status, App_Model_B.TmpSignalConversionAtR_UART_UAR.Device_WCT[1].CoilTempDegree, 0, 0, App_Model_B.UART_WPC2_DeviceState,
        &App_Model_B.b_TemperatureFault, &App_Model_B.b_Timer_OverTemp);

      /* End of Outputs for SubSystem: '<S203>/OverTemperatureDetecting_Function' */

      /* Outputs for Atomic SubSystem: '<S203>/WPC_PhoneLeftDetectingControl_Function' */
      WPC_PhoneLeftDetectingControl_k(App_Model_B.NFC2_CardProtectionResult, &App_Model_B.b_CardProtection);

      /* End of Outputs for SubSystem: '<S203>/WPC_PhoneLeftDetectingControl_Function' */

      /* Outputs for Atomic SubSystem: '<S14>/WPC_MainControl_Function' */
      /* UnitDelay: '<S408>/Unit Delay' incorporates:
       *  UnitDelay: '<S408>/Unit Delay11'
       *  UnitDelay: '<S408>/Unit Delay5'
       */
      App__WPC_MainControl_Function_e(App_Model_B.b_LFState, App_Model_B.b_CurrentFault, App_Model_B.b_TempSensorFault, App_Model_B.WPC2SWOption, App_Model_B.b_TemperatureFault, App_Model_B.b_AstDrSw,
        App_Model_B.b_DrvDrSw, App_Model_B.UART_WPC2_PhoneLeft, App_Model_B.UART_WPC2_DeviceState, App_Model_B.WPC2Status, App_Model_B.ADC_IGN1_IN, App_Model_DW.UnitDelay_DSTATE,
        App_Model_DW.UnitDelay11_DSTATE, App_Model_DW.UnitDelay5_DSTATE, App_Model_B.b_CardProtection, &App_Model_B.C_WPCWarning_a, &App_Model_B.b_FANModeCmd, &App_Model_B.b_GreenINDCmd,
        &App_Model_B.b_AmberINDCmd, &App_Model_B.b_BlinkState, &App_Model_B.b_Timer_PhoneReminderCheck, &App_Model_B.b_Timer_PhoneWarningCheck, &App_Model_B.b_Timer_WarningComplete,
        &App_Model_B.b_ChargingEnable, &App_Model_B.BlinkState_o, &App_Model_B.b_PhnLeftChk_Enable);

      /* End of Outputs for SubSystem: '<S14>/WPC_MainControl_Function' */

      /* Outputs for Atomic SubSystem: '<S202>/FAN_Control_Function' */
      App_Mode_FAN_Control_Function_h(App_Model_B.b_FANModeCmd, &App_Model_B.FAN_PWM_o);

      /* End of Outputs for SubSystem: '<S202>/FAN_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S202>/IND_Animation_Control_Function' */
      /* UnitDelay: '<S408>/Unit Delay1' incorporates:
       *  UnitDelay: '<S408>/Unit Delay'
       *  UnitDelay: '<S408>/Unit Delay12'
       *  UnitDelay: '<S408>/Unit Delay14'
       *  UnitDelay: '<S408>/Unit Delay4'
       */
      IND_Animation_Control_Functio_i(App_Model_DW.UnitDelay1_DSTATE, App_Model_B.BCAN_C_RWPCIndSyncVal, App_Model_B.C_WPCWarning_a, App_Model_DW.UnitDelay14_DSTATE, App_Model_DW.UnitDelay4_DSTATE,
        App_Model_DW.UnitDelay_DSTATE, App_Model_DW.UnitDelay12_DSTATE, &App_Model_B.Output_CAN_WPC2IndSyncVal, &App_Model_B.Output_INT_WPC2IndCmdState);

      /* End of Outputs for SubSystem: '<S202>/IND_Animation_Control_Function' */

      /* Outputs for Atomic SubSystem: '<S202>/IndyOutputControl_Function' */
      /* DataTypeConversion: '<S410>/Data Type Conversion45' incorporates:
       *  DataTypeConversion: '<S404>/Data Type Conversion17'
       *  DataTypeConversion: '<S404>/Data Type Conversion50'
       *  DataTypeConversion: '<S410>/Data Type Conversion52'
       *  UnitDelay: '<S408>/Unit Delay'
       *  UnitDelay: '<S408>/Unit Delay12'
       *  UnitDelay: '<S408>/Unit Delay5'
       */
      Ap_IndyOutputControl_Function_n(rtb_TmpSignalConversionAtR_NvM_.INDContType, App_Model_B.b_AmberINDCmd, App_Model_DW.UnitDelay12_DSTATE, App_Model_DW.UnitDelay5_DSTATE,
        rtb_TmpSignalConversionAtR_CAN_.BCAN.C_CLU_DtntOutSta, rtb_TmpSignalConversionAtR_NvM_.RheostatOption, rtb_TmpSignalConversionAtR_CAN_.BCAN.C_Lamp_IntTailLmpOnReq, App_Model_B.b_GreenINDCmd,
        App_Model_DW.UnitDelay_DSTATE, App_Model_B.BCAN_RX_RheoStatLevel, App_Model_B.BCAN_RX_C_AutoBrightLevel, &App_Model_B.P_GreenIND_OUT, &App_Model_B.P_GreenIND2_OUT, &App_Model_B.P_GreenIND3_OUT,
        &App_Model_B.P_AmberIND_OUT);

      /* End of Outputs for SubSystem: '<S202>/IndyOutputControl_Function' */
    } else if (App_Model_DW.DWPC2_TE_sys_MODE) {
      /* Disable for Atomic SubSystem: '<S202>/IndyOutputControl_Function' */
      IndyOutputControl_Fun_e_Disable();

      /* End of Disable for SubSystem: '<S202>/IndyOutputControl_Function' */
      App_Model_DW.DWPC2_TE_sys_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S10>/DWPC2_TE_sys' */

    /* Switch: '<S420>/Switch' incorporates:
     *  Constant: '<S422>/Constant'
     *  Constant: '<S423>/Constant'
     *  DataTypeConversion: '<S416>/Data Type Conversion1'
     *  Logic: '<S419>/OR'
     *  RelationalOperator: '<S422>/Compare'
     *  RelationalOperator: '<S423>/Compare'
     *  Switch: '<S421>/Switch'
     */
    if ((rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE == Type5) || (rtb_TmpSignalConversionAtR_NvM_.WPC_TYPE == Type6)) {
      /* Switch: '<S420>/Switch' incorporates:
       *  DataTypeConversion: '<S420>/Data Type Conversion1'
       */
      rtb_WCT2_ChargingOnthePad = rtb_TmpSignalConversionAtR_WCT_.Device[1].ChargingOnthePad;

      /* Switch: '<S421>/Switch' incorporates:
       *  DataTypeConversion: '<S421>/Data Type Conversion1'
       */
      rtb_WCT2_ObjectOnthePad = rtb_TmpSignalConversionAtR_WCT_.Device[1].ObjectOnthePad;
    } else {
      /* Switch: '<S420>/Switch' incorporates:
       *  Constant: '<S420>/Constant'
       */
      rtb_WCT2_ChargingOnthePad = OnThePad_Off;

      /* Switch: '<S421>/Switch' incorporates:
       *  Constant: '<S420>/Constant'
       */
      rtb_WCT2_ObjectOnthePad = OnThePad_Off;
    }

    /* End of Switch: '<S420>/Switch' */

    /* Outputs for Atomic SubSystem: '<S10>/Jdg_DualOrder' */
    /* DataTypeConversion: '<S413>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S409>/Data Type Conversion38'
     *  DataTypeConversion: '<S409>/Data Type Conversion76'
     *  DataTypeConversion: '<S413>/Data Type Conversion2'
     */
    App_Model_Jdg_DualOrder(App_Model_B.WPCStatus_h, App_Model_B.Output_INT_WPCIndCmdState, App_Model_B.Output_CAN_WPCIndSyncVal, App_Model_B.b_BlinkState_n, App_Model_B.BlinkState_p,
      App_Model_B.WPC2Status, App_Model_B.Output_INT_WPC2IndCmdState, App_Model_B.Output_CAN_WPC2IndSyncVal, App_Model_B.b_BlinkState, App_Model_B.BlinkState_o, App_Model_B.NFC1_NfcOnThePad,
      App_Model_B.NFC2_NfcOnThePad, rtb_TmpSignalConversionAtR_WCT_.Device[0].ChargingOnthePad, rtb_WCT2_ChargingOnthePad, rtb_TmpSignalConversionAtR_WCT_.Device[0].ObjectOnthePad,
      rtb_WCT2_ObjectOnthePad, rtb_TmpSignalConversionAtR_NFC_.Device[0].LPCD_Wakeup, rtb_TmpSignalConversionAtR_NFC_.Device[1].LPCD_Wakeup, App_Model_B.NFC1_LC_WPC_NFCDetection,
      App_Model_B.NFC2_LC_WPC_NFCDetection, App_Model_B.BCAN_C_RWPCIndSyncVal, &App_Model_B.NFCDetectOrder, &App_Model_B.LPCDWakeUpOrder, &App_Model_B.Var_PreSyncAct_a, &App_Model_B.Var_PreSyncAct,
      &rtb_b_CmdLEDSync_g, &rtb_b_SyncLED_i, &rtb_b_CmdLEDSync, &rtb_b_SyncLED, &rtb_NfcOnthepad_Jdg, &rtb_ChargingOnthepad_Jdg, &rtb_ObjectOnthepad_Jdg);

    /* End of Outputs for SubSystem: '<S10>/Jdg_DualOrder' */

    /* Chart: '<S424>/WPC_Mode_LPConditionJdg' */
    App_Mod_WPC_Mode_LPConditionJdg(App_Model_B.WPCStatus_h, &rtb_WPCMode_LPConditionFlag_wri, &App_Model_DW.sf_WPC_Mode_LPConditionJdg);

    /* Chart: '<S424>/NFC_Mode_LPConditionJdg' */
    App_Mod_NFC_Mode_LPConditionJdg(App_Model_B.WPCStatus_h, &rtb_NFCMode_LPConditionFlag_wri, &App_Model_DW.sf_NFC_Mode_LPConditionJdg);

    /* Chart: '<S424>/MainControl_LPConditionJdg' */
    App__MainControl_LPConditionJdg(App_Model_B.WPCStatus_h, App_Model_B.b_Timer_PhoneReminderCheck_n, App_Model_B.b_Timer_PhoneWarningCheck_i, App_Model_B.b_Timer_WarningComplete_e,
      &rtb_WPCMain_LPConditionFlag_wri, &App_Model_DW.sf_MainControl_LPConditionJdg);

    /* Chart: '<S424>/SMKLF_LPConditionJdg' */
    App_Model_SMKLF_LPConditionJdg(App_Model_B.b_LFState_m, &rtb_SMKLF_LPConditionFlag_write, &App_Model_DW.sf_SMKLF_LPConditionJdg);

    /* Chart: '<S424>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPConditionJd(App_Model_B.b_TempSensorFault_a, App_Model_B.b_Timer_TempSensor_Check_d, &rtb_TempSnsrError_LPConditionFl, &App_Model_DW.sf_TempSnsrErrDetect_LPConditio);

    /* Chart: '<S424>/OverTempDetect_LPConditionJdg' */
    A_OverTempDetect_LPConditionJdg(App_Model_B.b_TemperatureFault_c, App_Model_B.b_Timer_OverTemp_p, &rtb_OverTempDetect_LPConditionF, &App_Model_DW.sf_OverTempDetect_LPConditionJd);

    /* Chart: '<S424>/OverCurrent_LPConditionJdg' */
    App__OverCurrent_LPConditionJdg(App_Model_B.b_CurrentFault_j, App_Model_B.b_Timer_OvrCurr_d, App_Model_B.b_Timer_ReOvrCurr_d, &rtb_OverCurrent_LPConditionFlag,
      &App_Model_DW.sf_OverCurrent_LPConditionJdg);

    /* Chart: '<S424>/FAN_LPConditionJdg' */
    App_Model_FAN_LPConditionJdg(rtb_FAN_PWM, &rtb_FAN_LPConditionFlag_write, &App_Model_DW.sf_FAN_LPConditionJdg);

    /* Chart: '<S424>/USM_WPC_LPCondition' incorporates:
     *  DataStoreRead: '<S424>/Data Store Read'
     *  DataStoreRead: '<S424>/Data Store Read1'
     *  DataStoreRead: '<S424>/Data Store Read2'
     */
    App_Model_DW.sfEvent_e = -1;
    App_Model_DW.m_ProfileGuestWPCUSM_App_prev = App_Model_DW.m_ProfileGuestWPCUSM_App_start;
    App_Model_DW.m_ProfileGuestWPCUSM_App_start = m_ProfileGuestWPCUSM_App;
    App_Model_DW.m_ProfileOneWPCUSM_App_prev = App_Model_DW.m_ProfileOneWPCUSM_App_start;
    App_Model_DW.m_ProfileOneWPCUSM_App_start = m_ProfileOneWPCUSM_App;
    App_Model_DW.m_ProfileTwoWPCUSM_App_prev = App_Model_DW.m_ProfileTwoWPCUSM_App_start;
    App_Model_DW.m_ProfileTwoWPCUSM_App_start = m_ProfileTwoWPCUSM_App;
    if (App_Model_DW.is_active_c14_App_Model == 0U) {
      App_Model_DW.m_ProfileGuestWPCUSM_App_prev = m_ProfileGuestWPCUSM_App;
      App_Model_DW.m_ProfileOneWPCUSM_App_prev = m_ProfileOneWPCUSM_App;
      App_Model_DW.m_ProfileTwoWPCUSM_App_prev = m_ProfileTwoWPCUSM_App;
      App_Model_DW.is_active_c14_App_Model = 1U;
      App_Model_DW.is_active_LPConditionHold_n = 1U;
      App_Model_DW.is_LPConditionHold_j = App_Mode_IN_LPConditionHold_Off;
      App_Model_DW.Timer_LPConditionHold_c = 0U;
      App_Model_DW.is_active_LPConditionChk_Char_a = 1U;
      App_Model_DW.is_LPConditionChk_Chart_p = App_Model_IN_LPCondition_Off;
      App_Model_DW.sfEvent_e = event_StartTimer_LPConditionHol;
      App_Model_LPConditionHold();
      App_Model_DW.sfEvent_e = -1;
      App_Model_B.P_WPC_USM_LPConditionFlag_write = 0U;
      App_Model_DW.ECUResetEnable_j = 0U;
    } else {
      if (App_Model_DW.is_active_LPConditionHold_n != 0U) {
        App_Model_LPConditionHold();
      }

      if (App_Model_DW.is_active_LPConditionChk_Char_a != 0U) {
        switch (App_Model_DW.is_LPConditionChk_Chart_p) {
         case App_Model_IN_LPCondition_Off:
          App_Model_B.P_WPC_USM_LPConditionFlag_write = 0U;
          if (App_Model_DW.ECUResetEnable_j == 1) {
            App_Model_DW.sfEvent_e = event_CancelTimer_LPConditionHo;
            if (App_Model_DW.is_active_LPConditionHold_n != 0U) {
              App_Model_LPConditionHold();
            }

            App_Model_DW.sfEvent_e = -1;
            App_Model_DW.ECUResetEnable_j = 0U;
            App_Model_DW.is_LPConditionChk_Chart_p = App_Model_IN_LPCondition_On;
            App_Model_B.P_WPC_USM_LPConditionFlag_write = 1U;
          } else {
            App_Model_LPConditionTimerCheck();
          }
          break;

         case App_Model_IN_LPCondition_On:
          App_Model_B.P_WPC_USM_LPConditionFlag_write = 1U;
          if ((App_Model_DW.m_ProfileGuestWPCUSM_App_prev != App_Model_DW.m_ProfileGuestWPCUSM_App_start) || (App_Model_DW.m_ProfileOneWPCUSM_App_prev != App_Model_DW.m_ProfileOneWPCUSM_App_start) ||
              (App_Model_DW.m_ProfileTwoWPCUSM_App_prev != App_Model_DW.m_ProfileTwoWPCUSM_App_start)) {
            App_Model_DW.is_LPConditionChk_Chart_p = App_Model_IN_LPCondition_Off;
            App_Model_DW.sfEvent_e = event_StartTimer_LPConditionHol;
            if (App_Model_DW.is_active_LPConditionHold_n != 0U) {
              App_Model_LPConditionHold();
            }

            App_Model_DW.sfEvent_e = -1;
            App_Model_B.P_WPC_USM_LPConditionFlag_write = 0U;
            App_Model_DW.ECUResetEnable_j = 0U;
          }
          break;
        }
      }
    }

    /* End of Chart: '<S424>/USM_WPC_LPCondition' */

    /* BusCreator: '<S12>/Bus Creator' incorporates:
     *  Concatenate: '<S3>/Vector Concatenate'
     *  DataStoreRead: '<S424>/Data Store Read'
     *  DataStoreRead: '<S424>/Data Store Read1'
     *  DataStoreRead: '<S424>/Data Store Read2'
     *  DataTypeConversion: '<S424>/Data Type Conversion'
     *  DataTypeConversion: '<S424>/Data Type Conversion1'
     *  DataTypeConversion: '<S424>/Data Type Conversion10'
     *  DataTypeConversion: '<S424>/Data Type Conversion14'
     *  DataTypeConversion: '<S424>/Data Type Conversion15'
     *  DataTypeConversion: '<S424>/Data Type Conversion16'
     *  DataTypeConversion: '<S424>/Data Type Conversion2'
     *  DataTypeConversion: '<S424>/Data Type Conversion3'
     *  DataTypeConversion: '<S424>/Data Type Conversion5'
     *  DataTypeConversion: '<S424>/Data Type Conversion6'
     *  DataTypeConversion: '<S424>/Data Type Conversion7'
     *  DataTypeConversion: '<S424>/Data Type Conversion8'
     *  DataTypeConversion: '<S424>/Data Type Conversion9'
     *  Merge: '<S181>/Merge'
     *  Merge generated from: '<S19>/Merge'
     */
    App_Model_B.Device[0].WPCWarning = App_Model_B.C_WPCWarning_i;
    App_Model_B.Device[0].WPCRValue = App_Model_B.C_WPCRValue;
    App_Model_B.Device[0].PhoneWarningCheck_Timer = App_Model_B.b_Timer_PhoneWarningCheck_i;
    App_Model_B.Device[0].WPCStatus = App_Model_B.WPCStatus_h;
    App_Model_B.Device[0].FAN_PWM = rtb_FAN_PWM;
    App_Model_B.Device[0].ChargingEnable = App_Model_B.b_ChargingEnable_n;
    App_Model_B.Device[0].TempSensorFault = App_Model_B.b_TempSensorFault_a;
    App_Model_B.Device[0].BlinkState = App_Model_B.b_BlinkState_n;
    App_Model_B.Device[0].LFState = App_Model_B.b_LFState_m;
    App_Model_B.Device[0].AmberIND_OUT = App_Model_B.P_AmberIND_OUT_j;
    App_Model_B.Device[0].GreenIND1_OUT = App_Model_B.P_GreenIND_OUT_c;
    App_Model_B.Device[0].GreenIND2_OUT = App_Model_B.P_GreenIND2_OUT_d;
    App_Model_B.Device[0].GreenIND3_OUT = App_Model_B.P_GreenIND3_OUT_o;
    App_Model_B.Device[0].PhnLeftChk_Enable = App_Model_B.b_PhnLeftChk_Enable_j;
    App_Model_B.Device[0].WPCMode_LPConditionFlag = rtb_WPCMode_LPConditionFlag_wri;
    App_Model_B.Device[0].NFCMode_LPConditionFlag = rtb_NFCMode_LPConditionFlag_wri;
    App_Model_B.Device[0].WPCMain_LPConditionFlag = rtb_WPCMain_LPConditionFlag_wri;
    App_Model_B.Device[0].SMKLF_LPConditionFlag = rtb_SMKLF_LPConditionFlag_write;
    App_Model_B.Device[0].TempSnsrError_LPConditionFlag = rtb_TempSnsrError_LPConditionFl;
    App_Model_B.Device[0].OverTempDetect_LPConditionFlag = rtb_OverTempDetect_LPConditionF;
    App_Model_B.Device[0].OverCurrent_LPConditionFlag = rtb_OverCurrent_LPConditionFlag;
    App_Model_B.Device[0].FAN_LPConditionFlag = rtb_FAN_LPConditionFlag_write;
    App_Model_B.Device[0].TemperatureFault = App_Model_B.b_TemperatureFault_c;
    App_Model_B.Device[0].CurrentFault = App_Model_B.b_CurrentFault_j;
    App_Model_B.Device[0].m_ProfileGuestWPCUSM = m_ProfileGuestWPCUSM_App;
    App_Model_B.Device[0].m_ProfileOneWPCUSM = m_ProfileOneWPCUSM_App;
    App_Model_B.Device[0].m_ProfileTwoWPCUSM = m_ProfileTwoWPCUSM_App;
    App_Model_B.Device[0].USM_LPConditionFlag = App_Model_B.P_WPC_USM_LPConditionFlag_write;

    /* Outputs for Enabled SubSystem: '<S12>/DWPC2_DataType_Conv' incorporates:
     *  EnablePort: '<S425>/Enable'
     */
    if (rtb_DualWPCEn_n) {
      if (!App_Model_DW.DWPC2_DataType_Conv_MODE) {
        /* SystemReset for Chart: '<S425>/MainControl_LPConditionJdg' */
        MainControl_LPConditionJd_Reset(&App_Model_B.WPCMain_LPConditionFlag_write, &App_Model_DW.sf_MainControl_LPConditionJdg_o);

        /* SystemReset for Chart: '<S425>/NFC_Mode_LPConditionJdg' */
        A_NFC_Mode_LPConditionJdg_Reset(&App_Model_B.NFCMode_LPConditionFlag_write, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_c);

        /* SystemReset for Chart: '<S425>/WPC_Mode_LPConditionJdg' */
        A_WPC_Mode_LPConditionJdg_Reset(&App_Model_B.WPCMode_LPConditionFlag_write, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_d);

        /* SystemReset for Chart: '<S425>/FAN_LPConditionJdg' */
        App_Mo_FAN_LPConditionJdg_Reset(&App_Model_B.FAN_LPConditionFlag_write, &App_Model_DW.sf_FAN_LPConditionJdg_n);

        /* SystemReset for Chart: '<S425>/TempSnsrErrDetect_LPConditionJdg' */
        TempSnsrErrDetect_LPCondi_Reset(&App_Model_B.TempSnsrError_LPConditionFlag_w, &App_Model_DW.sf_TempSnsrErrDetect_LPCondit_n);

        /* SystemReset for Chart: '<S425>/SMKLF_LPConditionJdg' */
        App__SMKLF_LPConditionJdg_Reset(&App_Model_B.SMKLF_LPConditionFlag_write, &App_Model_DW.sf_SMKLF_LPConditionJdg_f);

        /* SystemReset for Chart: '<S425>/OverTempDetect_LPConditionJdg' */
        OverTempDetect_LPConditio_Reset(&App_Model_B.OverTempDetect_LPConditionFlag_, &App_Model_DW.sf_OverTempDetect_LPCondition_o);

        /* SystemReset for Chart: '<S425>/OverCurrent_LPConditionJdg' */
        OverCurrent_LPConditionJd_Reset(&App_Model_B.OverCurrent_LPConditionFlag_wri, &App_Model_DW.sf_OverCurrent_LPConditionJdg_l);

        /* SystemReset for Chart: '<S425>/USM_WPC2_LPCondition' */
        App_Model_DW.is_active_LPConditionChk_Chart = 0U;
        App_Model_DW.is_LPConditionChk_Chart = 0;
        App_Model_DW.is_active_LPConditionHold = 0U;
        App_Model_DW.is_LPConditionHold = 0;
        App_Model_DW.is_active_c11_App_Model = 0U;
        App_Model_DW.ECUResetEnable = 0U;
        App_Model_DW.Timer_LPConditionHold = 0U;
        App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
        App_Model_DW.m_ProfileGuestWPC2USM_App_start = WPC_On;
        App_Model_DW.m_ProfileOneWPC2USM_App_start = WPC_On;
        App_Model_DW.m_ProfileTwoWPC2USM_App_start = WPC_On;
        App_Model_DW.DWPC2_DataType_Conv_MODE = true;
      }

      /* DataTypeConversion: '<S425>/Data Type Conversion1' */
      App_Model_B.WPCWarning = App_Model_B.C_WPCWarning_a;

      /* DataTypeConversion: '<S425>/Data Type Conversion7' incorporates:
       *  Merge generated from: '<S204>/Merge'
       */
      App_Model_B.WPCRValue = App_Model_B.C_WPC2RValue;

      /* DataTypeConversion: '<S425>/Data Type Conversion13' */
      App_Model_B.PhoneWarningCheck_Timer = App_Model_B.b_Timer_PhoneWarningCheck;

      /* DataTypeConversion: '<S425>/Data Type Conversion8' incorporates:
       *  Merge: '<S361>/Merge'
       */
      App_Model_B.WPCStatus_n = App_Model_B.WPC2Status;

      /* Chart: '<S425>/MainControl_LPConditionJdg' */
      App__MainControl_LPConditionJdg(App_Model_B.WPC2Status, App_Model_B.b_Timer_PhoneReminderCheck, App_Model_B.b_Timer_PhoneWarningCheck, App_Model_B.b_Timer_WarningComplete,
        &App_Model_B.WPCMain_LPConditionFlag_write, &App_Model_DW.sf_MainControl_LPConditionJdg_o);

      /* Chart: '<S425>/NFC_Mode_LPConditionJdg' */
      App_Mod_NFC_Mode_LPConditionJdg(App_Model_B.WPC2Status, &App_Model_B.NFCMode_LPConditionFlag_write, &App_Model_DW.sf_NFC_Mode_LPConditionJdg_c);

      /* Chart: '<S425>/WPC_Mode_LPConditionJdg' */
      App_Mod_WPC_Mode_LPConditionJdg(App_Model_B.WPC2Status, &App_Model_B.WPCMode_LPConditionFlag_write, &App_Model_DW.sf_WPC_Mode_LPConditionJdg_d);

      /* DataTypeConversion: '<S425>/Data Type Conversion4' */
      App_Model_B.FAN_PWM = App_Model_B.FAN_PWM_o;

      /* Chart: '<S425>/FAN_LPConditionJdg' */
      App_Model_FAN_LPConditionJdg(App_Model_B.FAN_PWM_o, &App_Model_B.FAN_LPConditionFlag_write, &App_Model_DW.sf_FAN_LPConditionJdg_n);

      /* DataTypeConversion: '<S425>/Data Type Conversion2' */
      App_Model_B.ChargingEnable = App_Model_B.b_ChargingEnable;

      /* DataTypeConversion: '<S425>/Data Type Conversion10' */
      App_Model_B.TempSensorFault = App_Model_B.b_TempSensorFault;

      /* Chart: '<S425>/TempSnsrErrDetect_LPConditionJdg' */
      TempSnsrErrDetect_LPConditionJd(App_Model_B.b_TempSensorFault, App_Model_B.b_Timer_TempSensor_Check, &App_Model_B.TempSnsrError_LPConditionFlag_w, &App_Model_DW.sf_TempSnsrErrDetect_LPCondit_n);

      /* DataTypeConversion: '<S425>/Data Type Conversion3' */
      App_Model_B.BlinkState_c = App_Model_B.b_BlinkState;

      /* DataTypeConversion: '<S425>/Data Type Conversion' */
      App_Model_B.LFState = App_Model_B.b_LFState;

      /* Chart: '<S425>/SMKLF_LPConditionJdg' */
      App_Model_SMKLF_LPConditionJdg(App_Model_B.b_LFState, &App_Model_B.SMKLF_LPConditionFlag_write, &App_Model_DW.sf_SMKLF_LPConditionJdg_f);

      /* DataTypeConversion: '<S425>/Data Type Conversion12' */
      App_Model_B.AmberIND_OUT = App_Model_B.P_AmberIND_OUT;

      /* DataTypeConversion: '<S425>/Data Type Conversion11' */
      App_Model_B.GreenIND1_OUT = App_Model_B.P_GreenIND_OUT;

      /* DataTypeConversion: '<S425>/Data Type Conversion18' */
      App_Model_B.GreenIND2_OUT = App_Model_B.P_GreenIND2_OUT;

      /* DataTypeConversion: '<S425>/Data Type Conversion19' */
      App_Model_B.GreenIND3_OUT = App_Model_B.P_GreenIND3_OUT;

      /* DataTypeConversion: '<S425>/Data Type Conversion6' */
      App_Model_B.PhnLeftChk_Enable = App_Model_B.b_PhnLeftChk_Enable;

      /* DataTypeConversion: '<S425>/Data Type Conversion5' */
      App_Model_B.TemperatureFault = App_Model_B.b_TemperatureFault;

      /* Chart: '<S425>/OverTempDetect_LPConditionJdg' */
      A_OverTempDetect_LPConditionJdg(App_Model_B.b_TemperatureFault, App_Model_B.b_Timer_OverTemp, &App_Model_B.OverTempDetect_LPConditionFlag_, &App_Model_DW.sf_OverTempDetect_LPCondition_o);

      /* DataTypeConversion: '<S425>/Data Type Conversion9' */
      App_Model_B.CurrentFault = App_Model_B.b_CurrentFault;

      /* Chart: '<S425>/OverCurrent_LPConditionJdg' */
      App__OverCurrent_LPConditionJdg(App_Model_B.b_CurrentFault, App_Model_B.b_Timer_OvrCurr, App_Model_B.b_Timer_ReOvrCurr, &App_Model_B.OverCurrent_LPConditionFlag_wri,
        &App_Model_DW.sf_OverCurrent_LPConditionJdg_l);

      /* DataTypeConversion: '<S425>/Data Type Conversion14' incorporates:
       *  DataStoreRead: '<S425>/Data Store Read6'
       */
      App_Model_B.m_ProfileGuestWPCUSM = m_ProfileGuestWPC2USM_App;

      /* DataTypeConversion: '<S425>/Data Type Conversion15' incorporates:
       *  DataStoreRead: '<S425>/Data Store Read7'
       */
      App_Model_B.m_ProfileOneWPCUSM = m_ProfileOneWPC2USM_App;

      /* DataTypeConversion: '<S425>/Data Type Conversion16' incorporates:
       *  DataStoreRead: '<S425>/Data Store Read8'
       */
      App_Model_B.m_ProfileTwoWPCUSM = m_ProfileTwoWPC2USM_App;

      /* Chart: '<S425>/USM_WPC2_LPCondition' incorporates:
       *  DataStoreRead: '<S425>/Data Store Read6'
       *  DataStoreRead: '<S425>/Data Store Read7'
       *  DataStoreRead: '<S425>/Data Store Read8'
       */
      App_Model_DW.sfEvent = -1;
      App_Model_DW.m_ProfileGuestWPC2USM_App_prev = App_Model_DW.m_ProfileGuestWPC2USM_App_start;
      App_Model_DW.m_ProfileGuestWPC2USM_App_start = m_ProfileGuestWPC2USM_App;
      App_Model_DW.m_ProfileOneWPC2USM_App_prev = App_Model_DW.m_ProfileOneWPC2USM_App_start;
      App_Model_DW.m_ProfileOneWPC2USM_App_start = m_ProfileOneWPC2USM_App;
      App_Model_DW.m_ProfileTwoWPC2USM_App_prev = App_Model_DW.m_ProfileTwoWPC2USM_App_start;
      App_Model_DW.m_ProfileTwoWPC2USM_App_start = m_ProfileTwoWPC2USM_App;
      if (App_Model_DW.is_active_c11_App_Model == 0U) {
        App_Model_DW.m_ProfileGuestWPC2USM_App_prev = m_ProfileGuestWPC2USM_App;
        App_Model_DW.m_ProfileOneWPC2USM_App_prev = m_ProfileOneWPC2USM_App;
        App_Model_DW.m_ProfileTwoWPC2USM_App_prev = m_ProfileTwoWPC2USM_App;
        App_Model_DW.is_active_c11_App_Model = 1U;
        App_Model_DW.is_active_LPConditionHold = 1U;
        App_Model_DW.is_LPConditionHold = App_Mode_IN_LPConditionHold_Off;
        App_Model_DW.Timer_LPConditionHold = 0U;
        App_Model_DW.is_active_LPConditionChk_Chart = 1U;
        App_Model_DW.is_LPConditionChk_Chart = App_Model_IN_LPCondition_Off;
        App_Model_DW.sfEvent = event_StartTimer_LPConditionHol;
        App_Model_LPConditionHold_h();
        App_Model_DW.sfEvent = -1;
        App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
        App_Model_DW.ECUResetEnable = 0U;
      } else {
        if (App_Model_DW.is_active_LPConditionHold != 0U) {
          App_Model_LPConditionHold_h();
        }

        if (App_Model_DW.is_active_LPConditionChk_Chart != 0U) {
          switch (App_Model_DW.is_LPConditionChk_Chart) {
           case App_Model_IN_LPCondition_Off:
            App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
            if (App_Model_DW.ECUResetEnable == 1) {
              App_Model_DW.sfEvent = event_CancelTimer_LPConditionHo;
              if (App_Model_DW.is_active_LPConditionHold != 0U) {
                App_Model_LPConditionHold_h();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_DW.ECUResetEnable = 0U;
              App_Model_DW.is_LPConditionChk_Chart = App_Model_IN_LPCondition_On;
              App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 1U;
            } else {
              App_Mod_LPConditionTimerCheck_i();
            }
            break;

           case App_Model_IN_LPCondition_On:
            App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 1U;
            if ((App_Model_DW.m_ProfileGuestWPC2USM_App_prev != App_Model_DW.m_ProfileGuestWPC2USM_App_start) || (App_Model_DW.m_ProfileOneWPC2USM_App_prev !=
                 App_Model_DW.m_ProfileOneWPC2USM_App_start) || (App_Model_DW.m_ProfileTwoWPC2USM_App_prev != App_Model_DW.m_ProfileTwoWPC2USM_App_start)) {
              App_Model_DW.is_LPConditionChk_Chart = App_Model_IN_LPCondition_Off;
              App_Model_DW.sfEvent = event_StartTimer_LPConditionHol;
              if (App_Model_DW.is_active_LPConditionHold != 0U) {
                App_Model_LPConditionHold_h();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_B.P_WPC2_USM_LPConditionFlag_writ = 0U;
              App_Model_DW.ECUResetEnable = 0U;
            }
            break;
          }
        }
      }

      /* End of Chart: '<S425>/USM_WPC2_LPCondition' */
    } else {
      App_Model_DW.DWPC2_DataType_Conv_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S12>/DWPC2_DataType_Conv' */

    /* BusCreator: '<S12>/Bus Creator3' incorporates:
     *  Concatenate: '<S3>/Vector Concatenate'
     */
    App_Model_B.Device[1].WPCWarning = App_Model_B.WPCWarning;
    App_Model_B.Device[1].WPCRValue = App_Model_B.WPCRValue;
    App_Model_B.Device[1].PhoneWarningCheck_Timer = App_Model_B.PhoneWarningCheck_Timer;
    App_Model_B.Device[1].WPCStatus = App_Model_B.WPCStatus_n;
    App_Model_B.Device[1].FAN_PWM = App_Model_B.FAN_PWM;
    App_Model_B.Device[1].ChargingEnable = App_Model_B.ChargingEnable;
    App_Model_B.Device[1].TempSensorFault = App_Model_B.TempSensorFault;
    App_Model_B.Device[1].BlinkState = App_Model_B.BlinkState_c;
    App_Model_B.Device[1].LFState = App_Model_B.LFState;
    App_Model_B.Device[1].AmberIND_OUT = App_Model_B.AmberIND_OUT;
    App_Model_B.Device[1].GreenIND1_OUT = App_Model_B.GreenIND1_OUT;
    App_Model_B.Device[1].GreenIND2_OUT = App_Model_B.GreenIND2_OUT;
    App_Model_B.Device[1].GreenIND3_OUT = App_Model_B.GreenIND3_OUT;
    App_Model_B.Device[1].PhnLeftChk_Enable = App_Model_B.PhnLeftChk_Enable;
    App_Model_B.Device[1].WPCMode_LPConditionFlag = App_Model_B.WPCMode_LPConditionFlag_write;
    App_Model_B.Device[1].NFCMode_LPConditionFlag = App_Model_B.NFCMode_LPConditionFlag_write;
    App_Model_B.Device[1].WPCMain_LPConditionFlag = App_Model_B.WPCMain_LPConditionFlag_write;
    App_Model_B.Device[1].SMKLF_LPConditionFlag = App_Model_B.SMKLF_LPConditionFlag_write;
    App_Model_B.Device[1].TempSnsrError_LPConditionFlag = App_Model_B.TempSnsrError_LPConditionFlag_w;
    App_Model_B.Device[1].OverTempDetect_LPConditionFlag = App_Model_B.OverTempDetect_LPConditionFlag_;
    App_Model_B.Device[1].OverCurrent_LPConditionFlag = App_Model_B.OverCurrent_LPConditionFlag_wri;
    App_Model_B.Device[1].FAN_LPConditionFlag = App_Model_B.FAN_LPConditionFlag_write;
    App_Model_B.Device[1].TemperatureFault = App_Model_B.TemperatureFault;
    App_Model_B.Device[1].CurrentFault = App_Model_B.CurrentFault;
    App_Model_B.Device[1].m_ProfileGuestWPCUSM = App_Model_B.m_ProfileGuestWPCUSM;
    App_Model_B.Device[1].m_ProfileOneWPCUSM = App_Model_B.m_ProfileOneWPCUSM;
    App_Model_B.Device[1].m_ProfileTwoWPCUSM = App_Model_B.m_ProfileTwoWPCUSM;
    App_Model_B.Device[1].USM_LPConditionFlag = App_Model_B.P_WPC2_USM_LPConditionFlag_writ;

    /* Update for UnitDelay: '<S408>/Unit Delay' */
    App_Model_DW.UnitDelay_DSTATE = App_Model_B.Output_INT_WPCIndUSMState;

    /* Update for UnitDelay: '<S408>/Unit Delay2' */
    App_Model_DW.UnitDelay2_DSTATE = App_Model_B.Output_CAN_WPC2IndSyncVal;

    /* Update for UnitDelay: '<S408>/Unit Delay4' */
    App_Model_DW.UnitDelay4_DSTATE = App_Model_B.Output_INT_WPCIndCmdState;

    /* Update for UnitDelay: '<S408>/Unit Delay5' */
    App_Model_DW.UnitDelay5_DSTATE = App_Model_B.Output_INT_WPC2IndCmdState;

    /* Update for UnitDelay: '<S408>/Unit Delay9' */
    App_Model_DW.UnitDelay9_DSTATE = rtb_b_CmdLEDSync_g;

    /* Update for UnitDelay: '<S408>/Unit Delay10' */
    App_Model_DW.UnitDelay10_DSTATE = rtb_b_SyncLED_i;

    /* Update for UnitDelay: '<S408>/Unit Delay13' */
    App_Model_DW.UnitDelay13_DSTATE = App_Model_B.Var_PreSyncAct_a;

    /* Update for UnitDelay: '<S408>/Unit Delay15' */
    App_Model_DW.UnitDelay15_DSTATE = App_Model_B.C_WPCWarning_i;

    /* Update for UnitDelay: '<S408>/Unit Delay7' incorporates:
     *  Merge: '<S361>/Merge'
     */
    App_Model_DW.UnitDelay7_DSTATE = App_Model_B.WPC2Status;

    /* Update for UnitDelay: '<S408>/Unit Delay8' */
    App_Model_DW.UnitDelay8_DSTATE = App_Model_B.NFCDetectOrder;

    /* Update for UnitDelay: '<S408>/Unit Delay17' */
    App_Model_DW.UnitDelay17_DSTATE = App_Model_B.LPCDWakeUpOrder;

    /* Update for UnitDelay: '<S408>/Unit Delay18' */
    App_Model_DW.UnitDelay18_DSTATE = App_Model_B.b_PhnLeftChk_Enable_j;

    /* Update for UnitDelay: '<S408>/Unit Delay20' */
    App_Model_DW.UnitDelay20_DSTATE = rtb_NfcOnthepad_Jdg;

    /* Update for UnitDelay: '<S408>/Unit Delay21' */
    App_Model_DW.UnitDelay21_DSTATE = rtb_ChargingOnthepad_Jdg;

    /* Update for UnitDelay: '<S408>/Unit Delay6' */
    App_Model_DW.UnitDelay6_DSTATE = rtb_ObjectOnthepad_Jdg;

    /* Update for UnitDelay: '<S408>/Unit Delay1' */
    App_Model_DW.UnitDelay1_DSTATE = App_Model_B.Output_CAN_WPCIndSyncVal;

    /* Update for UnitDelay: '<S408>/Unit Delay11' */
    App_Model_DW.UnitDelay11_DSTATE = rtb_b_CmdLEDSync;

    /* Update for UnitDelay: '<S408>/Unit Delay12' */
    App_Model_DW.UnitDelay12_DSTATE = rtb_b_SyncLED;

    /* Update for UnitDelay: '<S408>/Unit Delay14' */
    App_Model_DW.UnitDelay14_DSTATE = App_Model_B.Var_PreSyncAct;

    /* Update for UnitDelay: '<S408>/Unit Delay16' */
    App_Model_DW.UnitDelay16_DSTATE = App_Model_B.C_WPCWarning_a;

    /* Update for UnitDelay: '<S408>/Unit Delay3' incorporates:
     *  Merge: '<S181>/Merge'
     */
    App_Model_DW.UnitDelay3_DSTATE = App_Model_B.WPCStatus_h;

    /* Update for UnitDelay: '<S408>/Unit Delay19' */
    App_Model_DW.UnitDelay19_DSTATE = App_Model_B.b_PhnLeftChk_Enable;
  } else if (App_Model_DW.App_Model_TE_Sys_MODE) {
    /* Disable for Atomic SubSystem: '<S10>/DWPC1_TE_sys' */
    /* Disable for Atomic SubSystem: '<S17>/IndyOutputControl_Function' */
    IndyOutputControl_Funct_Disable();

    /* End of Disable for SubSystem: '<S17>/IndyOutputControl_Function' */
    /* End of Disable for SubSystem: '<S10>/DWPC1_TE_sys' */

    /* Disable for Enabled SubSystem: '<S10>/DWPC2_TE_sys' */
    if (App_Model_DW.DWPC2_TE_sys_MODE) {
      /* Disable for Atomic SubSystem: '<S202>/IndyOutputControl_Function' */
      IndyOutputControl_Fun_e_Disable();

      /* End of Disable for SubSystem: '<S202>/IndyOutputControl_Function' */
      App_Model_DW.DWPC2_TE_sys_MODE = false;
    }

    /* End of Disable for SubSystem: '<S10>/DWPC2_TE_sys' */

    /* Disable for Enabled SubSystem: '<S12>/DWPC2_DataType_Conv' */
    App_Model_DW.DWPC2_DataType_Conv_MODE = false;

    /* End of Disable for SubSystem: '<S12>/DWPC2_DataType_Conv' */
    App_Model_DW.App_Model_TE_Sys_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/App_Model_TE_Sys' */

  /* BusCreator: '<Root>/Bus Creator' */
  memcpy(&rtb_BusCreator.Device[0], &App_Model_B.Device[0], sizeof(IDT_Model) << 1U);

  /* Outport generated from: '<Root>/Bus Element Out' */
  (void)Rte_Write_P_Model_Model_STR(&rtb_BusCreator);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  App_Model_M->Timing.clockTick0++;
}

/* Model initialize function */
void Model_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    App_Model_B.BCAN_RX_C_CF_Gway_WPCAnimationN = WPCAnimationNvalueSet__Type1;
    App_Model_B.NFC1_NfcOnThePad = OnThePad_Off;
    App_Model_B.NFC2_NfcOnThePad = OnThePad_Off;
    App_Model_B.INT_NfcOnThePad_1 = OnThePad_Off;
    App_Model_B.INT_NfcOnThePad_2 = OnThePad_Off;
    App_Model_B.BCAN_RX_C_WPCOnOffNvalueSet = WPC_On;
    App_Model_B.BCAN_RX_C_WPC2OnOffNvalueSet = WPC_On;
    App_Model_B.C_WPC2RValue = WPC_On;
    App_Model_B.WPC2SWOption = WPC_On;
    App_Model_B.C_WPCRValue = WPC_On;
    App_Model_B.WPCSWOption = WPC_On;
    App_Model_B.BCAN_RX_C_AutoBrightLevel = Step13;
  }

  /* states (dwork) */

  /* exported global states */
  m_ProfileGuestWPC2USM_App = WPC_On;
  m_ProfileGuestWPCUSM_App = WPC_On;
  m_ProfileOneWPC2USM_App = WPC_On;
  m_ProfileOneWPCUSM_App = WPC_On;
  m_ProfileTwoWPC2USM_App = WPC_On;
  m_ProfileTwoWPCUSM_App = WPC_On;

  {
    /* local block i/o variables */
    uint16 rtb_FAN_PWM;
    uint8 rtb_WPCMode_LPConditionFlag_wri;
    uint8 rtb_TempSnsrError_LPConditionFl;
    uint8 rtb_SMKLF_LPConditionFlag_write;
    uint8 rtb_OverTempDetect_LPConditionF;
    uint8 rtb_OverCurrent_LPConditionFlag;
    uint8 rtb_NFCMode_LPConditionFlag_wri;
    uint8 rtb_WPCMain_LPConditionFlag_wri;
    uint8 rtb_FAN_LPConditionFlag_write;
    Bool rtb_b_SyncLED;
    Bool rtb_b_CmdLEDSync;
    Bool rtb_b_SyncLED_i;
    Bool rtb_b_CmdLEDSync_g;
    Bool rtb_NfcOnthepad_Jdg;
    Bool rtb_ChargingOnthepad_Jdg;
    Bool rtb_ObjectOnthepad_Jdg;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel001' */
    Par_AutoBrightLevel001 = 150U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel002' */
    Par_AutoBrightLevel002 = 150U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel003' */
    Par_AutoBrightLevel003 = 171U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel004' */
    Par_AutoBrightLevel004 = 242U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel005' */
    Par_AutoBrightLevel005 = 314U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel006' */
    Par_AutoBrightLevel006 = 385U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel007' */
    Par_AutoBrightLevel007 = 456U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel008' */
    Par_AutoBrightLevel008 = 527U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel009' */
    Par_AutoBrightLevel009 = 598U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel010' */
    Par_AutoBrightLevel010 = 670U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel011' */
    Par_AutoBrightLevel011 = 741U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel012' */
    Par_AutoBrightLevel012 = 812U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel013' */
    Par_AutoBrightLevel013 = 883U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel014' */
    Par_AutoBrightLevel014 = 955U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel015' */
    Par_AutoBrightLevel015 = 1026U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel016' */
    Par_AutoBrightLevel016 = 1097U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel017' */
    Par_AutoBrightLevel017 = 1168U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel018' */
    Par_AutoBrightLevel018 = 1239U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel019' */
    Par_AutoBrightLevel019 = 1311U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel020' */
    Par_AutoBrightLevel020 = 1382U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel021' */
    Par_AutoBrightLevel021 = 1453U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel022' */
    Par_AutoBrightLevel022 = 1524U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel023' */
    Par_AutoBrightLevel023 = 1595U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel024' */
    Par_AutoBrightLevel024 = 1667U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel025' */
    Par_AutoBrightLevel025 = 1692U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel026' */
    Par_AutoBrightLevel026 = 1717U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel027' */
    Par_AutoBrightLevel027 = 1742U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel028' */
    Par_AutoBrightLevel028 = 1768U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel029' */
    Par_AutoBrightLevel029 = 1793U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel030' */
    Par_AutoBrightLevel030 = 1818U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel031' */
    Par_AutoBrightLevel031 = 1843U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel032' */
    Par_AutoBrightLevel032 = 1869U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel033' */
    Par_AutoBrightLevel033 = 1894U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel034' */
    Par_AutoBrightLevel034 = 1919U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel035' */
    Par_AutoBrightLevel035 = 1944U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel036' */
    Par_AutoBrightLevel036 = 1970U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel037' */
    Par_AutoBrightLevel037 = 1995U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel038' */
    Par_AutoBrightLevel038 = 2020U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel039' */
    Par_AutoBrightLevel039 = 2045U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel040' */
    Par_AutoBrightLevel040 = 2071U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel041' */
    Par_AutoBrightLevel041 = 2096U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel042' */
    Par_AutoBrightLevel042 = 2121U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel043' */
    Par_AutoBrightLevel043 = 2146U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel044' */
    Par_AutoBrightLevel044 = 2172U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel045' */
    Par_AutoBrightLevel045 = 2197U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel046' */
    Par_AutoBrightLevel046 = 2222U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel047' */
    Par_AutoBrightLevel047 = 2247U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel048' */
    Par_AutoBrightLevel048 = 2273U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel049' */
    Par_AutoBrightLevel049 = 2298U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel050' */
    Par_AutoBrightLevel050 = 2323U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel051' */
    Par_AutoBrightLevel051 = 2348U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel052' */
    Par_AutoBrightLevel052 = 2374U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel053' */
    Par_AutoBrightLevel053 = 2399U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel054' */
    Par_AutoBrightLevel054 = 2424U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel055' */
    Par_AutoBrightLevel055 = 2449U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel056' */
    Par_AutoBrightLevel056 = 2475U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel057' */
    Par_AutoBrightLevel057 = 2500U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel058' */
    Par_AutoBrightLevel058 = 2525U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel059' */
    Par_AutoBrightLevel059 = 2551U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel060' */
    Par_AutoBrightLevel060 = 2576U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel061' */
    Par_AutoBrightLevel061 = 2601U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel062' */
    Par_AutoBrightLevel062 = 2626U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel063' */
    Par_AutoBrightLevel063 = 2652U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel064' */
    Par_AutoBrightLevel064 = 2677U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel065' */
    Par_AutoBrightLevel065 = 2702U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel066' */
    Par_AutoBrightLevel066 = 2727U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel067' */
    Par_AutoBrightLevel067 = 2753U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel068' */
    Par_AutoBrightLevel068 = 2778U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel069' */
    Par_AutoBrightLevel069 = 2803U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel070' */
    Par_AutoBrightLevel070 = 2828U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel071' */
    Par_AutoBrightLevel071 = 2854U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel072' */
    Par_AutoBrightLevel072 = 2879U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel073' */
    Par_AutoBrightLevel073 = 2904U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel074' */
    Par_AutoBrightLevel074 = 2929U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel075' */
    Par_AutoBrightLevel075 = 2955U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel076' */
    Par_AutoBrightLevel076 = 2980U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel077' */
    Par_AutoBrightLevel077 = 3005U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel078' */
    Par_AutoBrightLevel078 = 3030U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel079' */
    Par_AutoBrightLevel079 = 3056U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel080' */
    Par_AutoBrightLevel080 = 3081U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel081' */
    Par_AutoBrightLevel081 = 3106U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel082' */
    Par_AutoBrightLevel082 = 3131U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel083' */
    Par_AutoBrightLevel083 = 3157U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel084' */
    Par_AutoBrightLevel084 = 3182U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel085' */
    Par_AutoBrightLevel085 = 3207U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel086' */
    Par_AutoBrightLevel086 = 3232U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel087' */
    Par_AutoBrightLevel087 = 3258U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel088' */
    Par_AutoBrightLevel088 = 3283U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel089' */
    Par_AutoBrightLevel089 = 3308U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel090' */
    Par_AutoBrightLevel090 = 3333U;

    /* Start for DataStoreMemory: '<Root>/Par_AutoBrightLevel091' */
    Par_AutoBrightLevel091 = 10000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel00' */
    Par_RheostatBrightLevel00 = 10000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel01' */
    Par_RheostatBrightLevel01 = 300U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel02' */
    Par_RheostatBrightLevel02 = 500U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel03' */
    Par_RheostatBrightLevel03 = 750U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel04' */
    Par_RheostatBrightLevel04 = 1000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel05' */
    Par_RheostatBrightLevel05 = 1250U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel06' */
    Par_RheostatBrightLevel06 = 1500U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel07' */
    Par_RheostatBrightLevel07 = 1750U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel08' */
    Par_RheostatBrightLevel08 = 2000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel09' */
    Par_RheostatBrightLevel09 = 2250U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel10' */
    Par_RheostatBrightLevel10 = 2500U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel11' */
    Par_RheostatBrightLevel11 = 2750U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel12' */
    Par_RheostatBrightLevel12 = 3000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel13' */
    Par_RheostatBrightLevel13 = 3250U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel14' */
    Par_RheostatBrightLevel14 = 3500U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel15' */
    Par_RheostatBrightLevel15 = 3750U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel16' */
    Par_RheostatBrightLevel16 = 4000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel17' */
    Par_RheostatBrightLevel17 = 4250U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel18' */
    Par_RheostatBrightLevel18 = 4500U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel19' */
    Par_RheostatBrightLevel19 = 4750U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel20' */
    Par_RheostatBrightLevel20 = 5000U;

    /* Start for DataStoreMemory: '<Root>/Par_RheostatBrightLevel21' */
    Par_RheostatBrightLevel21 = 10000U;

    /* Start for DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App' */
    m_ProfileGuestWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileGuestWPCUSM_App' incorporates:
     *  DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App'
     */
    m_ProfileGuestWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileOneWPC2USM_App' incorporates:
     *  DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App'
     */
    m_ProfileOneWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileOneWPCUSM_App' incorporates:
     *  DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App'
     */
    m_ProfileOneWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileTwoWPC2USM_App' incorporates:
     *  DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App'
     */
    m_ProfileTwoWPC2USM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_ProfileTwoWPCUSM_App' incorporates:
     *  DataStoreMemory: '<Root>/m_ProfileGuestWPC2USM_App'
     */
    m_ProfileTwoWPCUSM_App = WPC_On;

    /* Start for DataStoreMemory: '<Root>/m_WPCIndUSMState_Guest' */
    m_WPCIndUSMState_Guest = WPCIndUSMState__Type2;

    /* Start for DataStoreMemory: '<Root>/m_WPCIndUSMState_ProfileOne' incorporates:
     *  DataStoreMemory: '<Root>/m_WPCIndUSMState_Guest'
     */
    m_WPCIndUSMState_ProfileOne = WPCIndUSMState__Type2;

    /* Start for DataStoreMemory: '<Root>/m_WPCIndUSMState_ProfileTwo' incorporates:
     *  DataStoreMemory: '<Root>/m_WPCIndUSMState_Guest'
     */
    m_WPCIndUSMState_ProfileTwo = WPCIndUSMState__Type2;

    /* SystemInitialize for Triggered SubSystem: '<Root>/AppInit_DataRead' */
    App_Model_AppInit_DataRead_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/AppInit_DataRead' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/App_Model_TE_Sys' */
    /* SystemInitialize for Atomic SubSystem: '<S10>/DWPC1_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S13>/USMSettingControl_Function' */
    USMSettingControl_Function_Init(&App_Model_B.C_WPCRValue, &App_Model_B.WPCSWOption);

    /* End of SystemInitialize for SubSystem: '<S13>/USMSettingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S18>/NFC_WPC_Mode_Control_Function' */
    NFC_WPC_Mode_Control_Funct_Init(&App_Model_B.WPCStatus_h);

    /* End of SystemInitialize for SubSystem: '<S18>/NFC_WPC_Mode_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S18>/TemperatureSensorErrorDetect_Function' */
    TemperatureSensorErrorDe_l_Init(&App_Model_B.b_TempSensorFault_a, &App_Model_B.b_Timer_TempSensor_Check_d);

    /* End of SystemInitialize for SubSystem: '<S18>/TemperatureSensorErrorDetect_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S18>/PreventionSMK_LF_Interference_Function' */
    PreventionSMK_LF_Interfe_k_Init(&App_Model_B.b_LFState_m);

    /* End of SystemInitialize for SubSystem: '<S18>/PreventionSMK_LF_Interference_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S18>/OverCurrentDetecting_Function' */
    OverCurrentDetecting_Funct_Init(&App_Model_B.b_CurrentFault_j, &App_Model_B.b_Timer_OvrCurr_d, &App_Model_B.b_Timer_ReOvrCurr_d);

    /* End of SystemInitialize for SubSystem: '<S18>/OverCurrentDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S18>/OverTemperatureDetecting_Function' */
    OverTemperatureDetecting_F_Init(&App_Model_B.b_TemperatureFault_c, &App_Model_B.b_Timer_OverTemp_p);

    /* End of SystemInitialize for SubSystem: '<S18>/OverTemperatureDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S18>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectingCo_f_Init(&App_Model_B.b_CardProtection_i);

    /* End of SystemInitialize for SubSystem: '<S18>/WPC_PhoneLeftDetectingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S13>/WPC_MainControl_Function' */
    A_WPC_MainControl_Function_Init(&App_Model_B.C_WPCWarning_i, &App_Model_B.b_FANModeCmd_f, &App_Model_B.b_GreenINDCmd_o, &App_Model_B.b_AmberINDCmd_g, &App_Model_B.b_BlinkState_n,
      &App_Model_B.b_Timer_PhoneReminderCheck_n, &App_Model_B.b_Timer_PhoneWarningCheck_i, &App_Model_B.b_Timer_WarningComplete_e, &App_Model_B.b_ChargingEnable_n, &App_Model_B.BlinkState_p,
      &App_Model_B.b_PhnLeftChk_Enable_j);

    /* End of SystemInitialize for SubSystem: '<S13>/WPC_MainControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S17>/FAN_Control_Function' */
    App_M_FAN_Control_Function_Init(&rtb_FAN_PWM);

    /* End of SystemInitialize for SubSystem: '<S17>/FAN_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S17>/IND_Animation_Control_Function' */
    IND_Animation_Control_Func_Init(&App_Model_B.Output_INT_WPCIndUSMState, &App_Model_B.Output_CAN_WPCIndSyncVal, &App_Model_B.Output_INT_WPCIndCmdState);

    /* End of SystemInitialize for SubSystem: '<S17>/IND_Animation_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S17>/IndyOutputControl_Function' */
    IndyOutputControl_Function_Init(&App_Model_B.P_GreenIND_OUT_c, &App_Model_B.P_GreenIND2_OUT_d, &App_Model_B.P_GreenIND3_OUT_o, &App_Model_B.P_AmberIND_OUT_j);

    /* End of SystemInitialize for SubSystem: '<S17>/IndyOutputControl_Function' */
    /* End of SystemInitialize for SubSystem: '<S10>/DWPC1_TE_sys' */

    /* SystemInitialize for Enabled SubSystem: '<S10>/DWPC2_TE_sys' */
    /* SystemInitialize for Atomic SubSystem: '<S14>/USMSettingControl_Function' */
    USMSettingControl_Functi_i_Init(&App_Model_B.C_WPC2RValue, &App_Model_B.WPC2SWOption);

    /* End of SystemInitialize for SubSystem: '<S14>/USMSettingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S203>/NFC_WPC_Mode_Control_Function' */
    NFC_WPC_Mode_Control_Fun_f_Init(&App_Model_B.WPC2Status);

    /* End of SystemInitialize for SubSystem: '<S203>/NFC_WPC_Mode_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S203>/TemperatureSensorErrorDetect_Function' */
    TemperatureSensorErrorDe_d_Init(&App_Model_B.b_TempSensorFault, &App_Model_B.b_Timer_TempSensor_Check);

    /* End of SystemInitialize for SubSystem: '<S203>/TemperatureSensorErrorDetect_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S203>/PreventionSMK_LF_Interference_Function' */
    PreventionSMK_LF_Interfe_p_Init(&App_Model_B.b_LFState);

    /* End of SystemInitialize for SubSystem: '<S203>/PreventionSMK_LF_Interference_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S203>/OverCurrentDetecting_Function' */
    OverCurrentDetecting_Fun_n_Init(&App_Model_B.b_CurrentFault, &App_Model_B.b_Timer_OvrCurr, &App_Model_B.b_Timer_ReOvrCurr);

    /* End of SystemInitialize for SubSystem: '<S203>/OverCurrentDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S203>/OverTemperatureDetecting_Function' */
    OverTemperatureDetecting_l_Init(&App_Model_B.b_TemperatureFault, &App_Model_B.b_Timer_OverTemp);

    /* End of SystemInitialize for SubSystem: '<S203>/OverTemperatureDetecting_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S203>/WPC_PhoneLeftDetectingControl_Function' */
    WPC_PhoneLeftDetectingCo_h_Init(&App_Model_B.b_CardProtection);

    /* End of SystemInitialize for SubSystem: '<S203>/WPC_PhoneLeftDetectingControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S14>/WPC_MainControl_Function' */
    WPC_MainControl_Function_g_Init(&App_Model_B.C_WPCWarning_a, &App_Model_B.b_FANModeCmd, &App_Model_B.b_GreenINDCmd, &App_Model_B.b_AmberINDCmd, &App_Model_B.b_BlinkState,
      &App_Model_B.b_Timer_PhoneReminderCheck, &App_Model_B.b_Timer_PhoneWarningCheck, &App_Model_B.b_Timer_WarningComplete, &App_Model_B.b_ChargingEnable, &App_Model_B.BlinkState_o,
      &App_Model_B.b_PhnLeftChk_Enable);

    /* End of SystemInitialize for SubSystem: '<S14>/WPC_MainControl_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S202>/FAN_Control_Function' */
    App_FAN_Control_Function_h_Init(&App_Model_B.FAN_PWM_o);

    /* End of SystemInitialize for SubSystem: '<S202>/FAN_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S202>/IND_Animation_Control_Function' */
    IND_Animation_Control_Fu_b_Init(&App_Model_B.Output_CAN_WPC2IndSyncVal, &App_Model_B.Output_INT_WPC2IndCmdState);

    /* End of SystemInitialize for SubSystem: '<S202>/IND_Animation_Control_Function' */

    /* SystemInitialize for Atomic SubSystem: '<S202>/IndyOutputControl_Function' */
    IndyOutputControl_Functi_d_Init(&App_Model_B.P_GreenIND_OUT, &App_Model_B.P_GreenIND2_OUT, &App_Model_B.P_GreenIND3_OUT, &App_Model_B.P_AmberIND_OUT);

    /* End of SystemInitialize for SubSystem: '<S202>/IndyOutputControl_Function' */
    /* End of SystemInitialize for SubSystem: '<S10>/DWPC2_TE_sys' */

    /* SystemInitialize for Atomic SubSystem: '<S10>/Jdg_DualOrder' */
    App_Model_Jdg_DualOrder_Init(&App_Model_B.NFCDetectOrder, &App_Model_B.LPCDWakeUpOrder, &App_Model_B.Var_PreSyncAct_a, &App_Model_B.Var_PreSyncAct, &rtb_b_CmdLEDSync_g, &rtb_b_SyncLED_i,
      &rtb_b_CmdLEDSync, &rtb_b_SyncLED, &rtb_NfcOnthepad_Jdg, &rtb_ChargingOnthepad_Jdg, &rtb_ObjectOnthepad_Jdg);

    /* End of SystemInitialize for SubSystem: '<S10>/Jdg_DualOrder' */

    /* SystemInitialize for Chart: '<S424>/WPC_Mode_LPConditionJdg' */
    Ap_WPC_Mode_LPConditionJdg_Init(&rtb_WPCMode_LPConditionFlag_wri);

    /* SystemInitialize for Chart: '<S424>/NFC_Mode_LPConditionJdg' */
    Ap_NFC_Mode_LPConditionJdg_Init(&rtb_NFCMode_LPConditionFlag_wri);

    /* SystemInitialize for Chart: '<S424>/MainControl_LPConditionJdg' */
    MainControl_LPConditionJdg_Init(&rtb_WPCMain_LPConditionFlag_wri);

    /* SystemInitialize for Chart: '<S424>/SMKLF_LPConditionJdg' */
    App_M_SMKLF_LPConditionJdg_Init(&rtb_SMKLF_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S424>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPCondit_Init(&rtb_TempSnsrError_LPConditionFl);

    /* SystemInitialize for Chart: '<S424>/OverTempDetect_LPConditionJdg' */
    OverTempDetect_LPCondition_Init(&rtb_OverTempDetect_LPConditionF);

    /* SystemInitialize for Chart: '<S424>/OverCurrent_LPConditionJdg' */
    OverCurrent_LPConditionJdg_Init(&rtb_OverCurrent_LPConditionFlag);

    /* SystemInitialize for Chart: '<S424>/FAN_LPConditionJdg' */
    App_Mod_FAN_LPConditionJdg_Init(&rtb_FAN_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S424>/USM_WPC_LPCondition' */
    App_Model_DW.sfEvent_e = -1;
    App_Model_DW.m_ProfileGuestWPCUSM_App_prev = WPC_On;
    App_Model_DW.m_ProfileGuestWPCUSM_App_start = WPC_On;
    App_Model_DW.m_ProfileOneWPCUSM_App_prev = WPC_On;
    App_Model_DW.m_ProfileOneWPCUSM_App_start = WPC_On;
    App_Model_DW.m_ProfileTwoWPCUSM_App_prev = WPC_On;
    App_Model_DW.m_ProfileTwoWPCUSM_App_start = WPC_On;

    /* SystemInitialize for Enabled SubSystem: '<S12>/DWPC2_DataType_Conv' */
    /* SystemInitialize for Chart: '<S425>/MainControl_LPConditionJdg' */
    MainControl_LPConditionJdg_Init(&App_Model_B.WPCMain_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S425>/NFC_Mode_LPConditionJdg' */
    Ap_NFC_Mode_LPConditionJdg_Init(&App_Model_B.NFCMode_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S425>/WPC_Mode_LPConditionJdg' */
    Ap_WPC_Mode_LPConditionJdg_Init(&App_Model_B.WPCMode_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S425>/FAN_LPConditionJdg' */
    App_Mod_FAN_LPConditionJdg_Init(&App_Model_B.FAN_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S425>/TempSnsrErrDetect_LPConditionJdg' */
    TempSnsrErrDetect_LPCondit_Init(&App_Model_B.TempSnsrError_LPConditionFlag_w);

    /* SystemInitialize for Chart: '<S425>/SMKLF_LPConditionJdg' */
    App_M_SMKLF_LPConditionJdg_Init(&App_Model_B.SMKLF_LPConditionFlag_write);

    /* SystemInitialize for Chart: '<S425>/OverTempDetect_LPConditionJdg' */
    OverTempDetect_LPCondition_Init(&App_Model_B.OverTempDetect_LPConditionFlag_);

    /* SystemInitialize for Chart: '<S425>/OverCurrent_LPConditionJdg' */
    OverCurrent_LPConditionJdg_Init(&App_Model_B.OverCurrent_LPConditionFlag_wri);

    /* SystemInitialize for Chart: '<S425>/USM_WPC2_LPCondition' incorporates:
     *  Chart: '<S424>/USM_WPC_LPCondition'
     */
    App_Model_DW.sfEvent = -1;
    App_Model_DW.m_ProfileGuestWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileGuestWPC2USM_App_start = WPC_On;
    App_Model_DW.m_ProfileOneWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileOneWPC2USM_App_start = WPC_On;
    App_Model_DW.m_ProfileTwoWPC2USM_App_prev = WPC_On;
    App_Model_DW.m_ProfileTwoWPC2USM_App_start = WPC_On;

    /* End of SystemInitialize for SubSystem: '<S12>/DWPC2_DataType_Conv' */
    /* End of SystemInitialize for SubSystem: '<Root>/App_Model_TE_Sys' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
