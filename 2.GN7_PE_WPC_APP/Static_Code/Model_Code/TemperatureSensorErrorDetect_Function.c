/*
 * File: TemperatureSensorErrorDetect_Function.c
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
#include "rtwtypes.h"
#include "TemperatureSensorErrorDetect_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
#define App_Mo_IN_TempSensorError_Check ((uint8)1U)
#define App_Mode_IN_TempSensorError_Off ((uint8)2U)
#define App_Model_CALL_EVENT_na        (-1)
#define App_Model_IN_NO_ACTIVE_CHILD_f ((uint8)0U)
#define App_Model_IN_Off_n             ((uint8)1U)
#define App_Model_IN_On_k              ((uint8)2U)
#define App_Model_IN_TempSensorError_On ((uint8)3U)
#define event_Cancel_Timer_TempSensor_C (0)
#define event_Start_Timer_TempSensor_Ch (1)

/* Forward declaration for local functions */
static void App_Tick_Timer_TempSensor_Check(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
static void enter_internal_Tick_Timer_TempS(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);

/* Function for Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
static void App_Tick_Timer_TempSensor_Check(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  switch (localDW->is_Tick_Timer_TempSensor_Check) {
   case App_Model_IN_Off_n:
    if (localDW->sfEvent == event_Start_Timer_TempSensor_Ch) {
      localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_On_k;
    }
    break;

   case App_Model_IN_On_k:
    {
      if (localDW->sfEvent == event_Cancel_Timer_TempSensor_C) {
        localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_Off_n;
        localDW->Timer_TempSensor_Check = 0U;
        *rty_b_Timer_TempSensor_Check = 0U;
      } else {
        sint32 tmp;
        tmp = localDW->Timer_TempSensor_Check + 1;
        if (localDW->Timer_TempSensor_Check + 1 > 255) {
          tmp = 255;
        }

        localDW->Timer_TempSensor_Check = (uint8)tmp;
        *rty_b_Timer_TempSensor_Check = localDW->Timer_TempSensor_Check;
        if (localDW->sfEvent == event_Start_Timer_TempSensor_Ch) {
          localDW->Timer_TempSensor_Check = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
static void enter_internal_Tick_Timer_TempS(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_Off_n;
  localDW->Timer_TempSensor_Check = 0U;

  /* Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  *rty_b_Timer_TempSensor_Check = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S185>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S365>/TemperatureSensorErrorDetect3_8_LPC'
 */
void TemperatureSensorErrorDete_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_na;
  *rty_b_TempSensorFault = Off;
  *rty_b_Timer_TempSensor_Check = 0U;
}

/*
 * System reset for atomic system:
 *    '<S185>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S365>/TemperatureSensorErrorDetect3_8_LPC'
 */
void TemperatureSensorErrorDet_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_na;
  localDW->is_active_TempSensorErrorDetect = 0U;
  localDW->is_TempSensorErrorDetect = App_Model_IN_NO_ACTIVE_CHILD_f;
  localDW->is_active_Tick_Timer_TempSensor = 0U;
  localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_NO_ACTIVE_CHILD_f;
  localDW->is_active_c4_TemperatureSensorE = 0U;
  localDW->Timer_TempSensor_Check = 0U;
  *rty_b_TempSensorFault = Off;
  *rty_b_Timer_TempSensor_Check = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S185>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S365>/TemperatureSensorErrorDetect3_8_LPC'
 */
void TemperatureSensorErrorDetect3_8(Bool rtu_b_Temperature_SensorFault1, Bool rtu_b_Temperature_SensorFault2, Bool rtu_b_DTCClearFlag, WPCStatus rtu_WPCStatus, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_na;

  /* Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  if (localDW->is_active_c4_TemperatureSensorE == 0U) {
    localDW->is_active_c4_TemperatureSensorE = 1U;
    localDW->is_active_TempSensorErrorDetect = 1U;
    localDW->is_TempSensorErrorDetect = App_Mode_IN_TempSensorError_Off;
    localDW->sfEvent = event_Cancel_Timer_TempSensor_C;
    if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
      App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
    }

    localDW->sfEvent = -1;
    *rty_b_TempSensorFault = Off;
    localDW->is_active_Tick_Timer_TempSensor = 1U;
    enter_internal_Tick_Timer_TempS(rty_b_Timer_TempSensor_Check, localDW);
  } else {
    if (localDW->is_active_TempSensorErrorDetect != 0U) {
      switch (localDW->is_TempSensorErrorDetect) {
       case App_Mo_IN_TempSensorError_Check:
        /* 1. %NonGFS  */
        if ((rtu_WPCStatus != WPCMode) || (rtu_b_DTCClearFlag == On) || ((rtu_b_Temperature_SensorFault1 == Off) && (rtu_b_Temperature_SensorFault2 == Off) && (rtu_b_Temperature_SensorFault2 == Off)))
        {
          localDW->sfEvent = event_Cancel_Timer_TempSensor_C;
          if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->is_TempSensorErrorDetect = App_Mode_IN_TempSensorError_Off;
          localDW->sfEvent = event_Cancel_Timer_TempSensor_C;
          if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TempSensorFault = Off;
        } else if (localDW->Timer_TempSensor_Check >= 200) {
          localDW->sfEvent = event_Cancel_Timer_TempSensor_C;
          if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_TempSensorErrorDetect = App_Model_IN_TempSensorError_On;
          *rty_b_TempSensorFault = On;
        }
        break;

       case App_Mode_IN_TempSensorError_Off:
        *rty_b_TempSensorFault = Off;

        /* 1.  %NonGFS  */
        if ((rtu_WPCStatus == WPCMode) && (rtu_b_DTCClearFlag == Off) && ((rtu_b_Temperature_SensorFault1 == On) || (rtu_b_Temperature_SensorFault2 == On) || (rtu_b_Temperature_SensorFault2 == On))) {
          localDW->is_TempSensorErrorDetect = App_Mo_IN_TempSensorError_Check;
          localDW->sfEvent = event_Start_Timer_TempSensor_Ch;
          if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
        }
        break;

       case App_Model_IN_TempSensorError_On:
        *rty_b_TempSensorFault = On;

        /* 1.
           [WPCStatus != WPCMode ||.... 8차 선반영 */
        if ((rtu_WPCStatus == ModeOff) || (rtu_b_DTCClearFlag == On)) {
          /* NonGFS */
          localDW->is_TempSensorErrorDetect = App_Mode_IN_TempSensorError_Off;
          localDW->sfEvent = event_Cancel_Timer_TempSensor_C;
          if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TempSensorFault = Off;
        }
        break;
      }
    }

    if (localDW->is_active_Tick_Timer_TempSensor != 0U) {
      App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
    }
  }

  /* End of Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
}

/* System initialize for atomic system: '<S18>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDe_l_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemInitialize for Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDete_Init(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorDetect);
}

/* Output and update for atomic system: '<S18>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDetect_Fu(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_e, Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* Chart: '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDetect3_8(rtu_PreProcessIn, rtu_PreProcessIn_p, rtu_PreProcessIn_e, rtu_WPCStatus, rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check,
    &App_Model_DW.sf_TemperatureSensorErrorDetect);
}

/* System initialize for atomic system: '<S203>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDe_d_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemInitialize for Chart: '<S365>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDete_Init(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorDete_p);
}

/* System reset for atomic system: '<S203>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorD_d_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemReset for Chart: '<S365>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDet_Reset(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorDete_p);
}

/* Output and update for atomic system: '<S203>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDetect__h(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn1, Bool rtu_PreProcessIn1_m, Bool rtu_PreProcessIn1_md, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check)
{
  /* Chart: '<S365>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDetect3_8(rtu_PreProcessIn1, rtu_PreProcessIn1_m, rtu_PreProcessIn1_md, rtu_WPC2Status, rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check,
    &App_Model_DW.sf_TemperatureSensorErrorDete_p);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
