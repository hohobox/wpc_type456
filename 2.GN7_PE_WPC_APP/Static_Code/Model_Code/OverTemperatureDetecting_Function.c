/*
 * File: OverTemperatureDetecting_Function.c
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
#include "OverTemperatureDetecting_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
#define Ap_IN_TemperatureError_OffCheck ((uint8)1U)
#define App_IN_TemperatureError_OnCheck ((uint8)2U)
#define App_Mode_IN_Temperature_FaultOn ((uint8)3U)
#define App_Model_CALL_EVENT_c         (-1)
#define App_Model_IN_NO_ACTIVE_CHILD_p ((uint8)0U)
#define App_Model_IN_Off_l             ((uint8)1U)
#define App_Model_IN_On_h              ((uint8)2U)
#define App_Model_IN_Temperature_Normal ((uint8)4U)
#define App__event_Start_Timer_OverTemp (1)
#define App_event_Cancel_Timer_OverTemp (0)

/* Forward declaration for local functions */
static void App_Model_Tick_Timer_OverTemp(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);
static void enter_internal_Tick_Timer_OverT(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);

/* Function for Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
static void App_Model_Tick_Timer_OverTemp(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  switch (localDW->is_Tick_Timer_OverTemp) {
   case App_Model_IN_Off_l:
    if (localDW->sfEvent == App__event_Start_Timer_OverTemp) {
      localDW->is_Tick_Timer_OverTemp = App_Model_IN_On_h;
    }
    break;

   case App_Model_IN_On_h:
    {
      if (localDW->sfEvent == App_event_Cancel_Timer_OverTemp) {
        localDW->is_Tick_Timer_OverTemp = App_Model_IN_Off_l;
        localDW->Timer_OverTemp = 0U;
        *rty_b_Timer_OverTemp = 0U;
      } else {
        sint32 tmp_0;
        uint16 tmp;
        tmp_0 = localDW->Timer_OverTemp + 1;
        if (localDW->Timer_OverTemp + 1 > 65535) {
          tmp_0 = 65535;
        }

        localDW->Timer_OverTemp = (uint16)tmp_0;
        tmp = localDW->Timer_OverTemp;
        if (localDW->Timer_OverTemp > 255) {
          tmp = 255U;
        }

        *rty_b_Timer_OverTemp = (uint8)tmp;
        if (localDW->sfEvent == App__event_Start_Timer_OverTemp) {
          localDW->Timer_OverTemp = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
static void enter_internal_Tick_Timer_OverT(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->is_Tick_Timer_OverTemp = App_Model_IN_Off_l;
  localDW->Timer_OverTemp = 0U;

  /* Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  *rty_b_Timer_OverTemp = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S363>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 */
void OverTemperatureDetecting3__Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_c;
  *rty_b_TemperatureFault = Off;
  *rty_b_Timer_OverTemp = 0U;
}

/*
 * System reset for atomic system:
 *    '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S363>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 */
void OverTemperatureDetecting3_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_c;
  localDW->is_active_OverTemperatureDetect = 0U;
  localDW->is_OverTemperatureDetecting = App_Model_IN_NO_ACTIVE_CHILD_p;
  localDW->is_active_Tick_Timer_OverTemp = 0U;
  localDW->is_Tick_Timer_OverTemp = App_Model_IN_NO_ACTIVE_CHILD_p;
  localDW->is_active_c6_OverTemperatureDet = 0U;
  localDW->Timer_OverTemp = 0U;
  *rty_b_TemperatureFault = Off;
  *rty_b_Timer_OverTemp = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S363>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 */
void OverTemperatureDetecting3_5_SCR(sint16 rtu_Temperature_Sensor1, sint16 rtu_Temperature_Sensor2, sint16 rtu_Temperature_Sensor3, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_c;

  /* Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  if (localDW->is_active_c6_OverTemperatureDet == 0U) {
    localDW->is_active_c6_OverTemperatureDet = 1U;
    localDW->is_active_OverTemperatureDetect = 1U;
    localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
    localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
    if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
      App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
    }

    localDW->sfEvent = -1;
    *rty_b_TemperatureFault = Off;
    localDW->is_active_Tick_Timer_OverTemp = 1U;
    enter_internal_Tick_Timer_OverT(rty_b_Timer_OverTemp, localDW);
  } else {
    if (localDW->is_active_OverTemperatureDetect != 0U) {
      switch (localDW->is_OverTemperatureDetecting) {
       case Ap_IN_TemperatureError_OffCheck:
        /* 1. */
        if ((rtu_WPCStatus != WPCMode) || (localDW->Timer_OverTemp >= 500)) {
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TemperatureFault = Off;

          /* 2. */
        } else if ((rtu_Temperature_Sensor1 > 65) || (rtu_Temperature_Sensor2 > 65) || (rtu_Temperature_Sensor3 > 65)) {
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_OverTemperatureDetecting = App_Mode_IN_Temperature_FaultOn;
          *rty_b_TemperatureFault = On;
        }
        break;

       case App_IN_TemperatureError_OnCheck:
        /* 1. */
        if ((rtu_WPCStatus != WPCMode) || (rtu_DeviceState == Standby) || ((rtu_Temperature_Sensor1 < 70) && (rtu_Temperature_Sensor2 < 70) && (rtu_Temperature_Sensor3 < 70))) {
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TemperatureFault = Off;

          /* 2. */
        } else if (localDW->Timer_OverTemp >= 500) {
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_OverTemperatureDetecting = App_Mode_IN_Temperature_FaultOn;
          *rty_b_TemperatureFault = On;
        }
        break;

       case App_Mode_IN_Temperature_FaultOn:
        *rty_b_TemperatureFault = On;

        /* 2. */
        if ((rtu_Temperature_Sensor1 <= 65) && (rtu_Temperature_Sensor2 <= 65) && (rtu_Temperature_Sensor3 <= 65)) {
          localDW->is_OverTemperatureDetecting = Ap_IN_TemperatureError_OffCheck;
          localDW->sfEvent = App__event_Start_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;

          /* 1. */
        } else if (rtu_WPCStatus != WPCMode) {
          localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
          localDW->sfEvent = App_event_Cancel_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TemperatureFault = Off;
        }
        break;

       case App_Model_IN_Temperature_Normal:
        *rty_b_TemperatureFault = Off;

        /* 1. */
        if ((rtu_WPCStatus == WPCMode) && (rtu_DeviceState != Standby) && ((rtu_Temperature_Sensor1 >= 70) || (rtu_Temperature_Sensor2 >= 70) || (rtu_Temperature_Sensor3 >= 70))) {
          localDW->is_OverTemperatureDetecting = App_IN_TemperatureError_OnCheck;
          localDW->sfEvent = App__event_Start_Timer_OverTemp;
          if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
        }
        break;
      }
    }

    if (localDW->is_active_Tick_Timer_OverTemp != 0U) {
      App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
    }
  }

  /* End of Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
}

/* System initialize for atomic system: '<S18>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_F_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemInitialize for Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3__Init(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetecting3_5_);
}

/* Output and update for atomic system: '<S18>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_Functi(WPCStatus rtu_WPCStatus, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_a, sint16 rtu_PreProcessIn_n, DeviceState rtu_PreProcessIn_f, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* Chart: '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_5_SCR(rtu_PreProcessIn, rtu_PreProcessIn_a, rtu_PreProcessIn_n, rtu_PreProcessIn_f, rtu_WPCStatus, rty_b_TemperatureFault, rty_b_Timer_OverTemp,
    &App_Model_DW.sf_OverTemperatureDetecting3_5_);
}

/* System initialize for atomic system: '<S203>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_l_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemInitialize for Chart: '<S363>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3__Init(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetecting3__m);
}

/* System reset for atomic system: '<S203>/OverTemperatureDetecting_Function' */
void OverTemperatureDetectin_c_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemReset for Chart: '<S363>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_Reset(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetecting3__m);
}

/* Output and update for atomic system: '<S203>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_Func_a(WPCStatus rtu_WPC2Status, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_n, sint16 rtu_PreProcessIn_o, DeviceState rtu_PreProcessIn_g, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* Chart: '<S363>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_5_SCR(rtu_PreProcessIn, rtu_PreProcessIn_n, rtu_PreProcessIn_o, rtu_PreProcessIn_g, rtu_WPC2Status, rty_b_TemperatureFault, rty_b_Timer_OverTemp,
    &App_Model_DW.sf_OverTemperatureDetecting3__m);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
