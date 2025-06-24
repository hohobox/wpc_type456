/*
 * File: OverTemperatureDetecting_Function.c
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

#include "App_Model_types.h"
#include "rtwtypes.h"
#include "OverTemperatureDetecting_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
#define Ap_IN_TemperatureError_OffCheck ((uint8)1U)
#define App_IN_TemperatureError_OnCheck ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_pq51 ((uint8)0U)
#define App_Mode_IN_Temperature_FaultOn ((uint8)3U)
#define App_Model_CALL_EVENT_cijc      (-1)
#define App_Model_IN_Off_lmxw          ((uint8)1U)
#define App_Model_IN_On_hyox           ((uint8)2U)
#define App_Model_IN_Temperature_Normal ((uint8)4U)
#define App__event_Start_Timer_OverTemp (1)
#define App_event_Cancel_Timer_OverTemp (0)

/* Forward declaration for local functions */
static void App_Model_Tick_Timer_OverTemp(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);
static void enter_internal_Tick_Timer_OverT(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);

/* Function for Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
static void App_Model_Tick_Timer_OverTemp(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  switch (localDW->is_Tick_Timer_OverTemp) {
   case App_Model_IN_Off_lmxw:
    if (localDW->sfEvent == (sint32)App__event_Start_Timer_OverTemp) {
      localDW->is_Tick_Timer_OverTemp = App_Model_IN_On_hyox;
    }
    break;

   case App_Model_IN_On_hyox:
    {
      if (localDW->sfEvent == (sint32)App_event_Cancel_Timer_OverTemp) {
        localDW->is_Tick_Timer_OverTemp = App_Model_IN_Off_lmxw;
        localDW->Timer_OverTemp = 0U;
        *rty_b_Timer_OverTemp = 0U;
      } else {
        sint32 tmp_0;
        uint16 tmp;
        tmp_0 = (sint32)localDW->Timer_OverTemp + 1;
        if (((sint32)localDW->Timer_OverTemp + 1) > 65535) {
          tmp_0 = 65535;
        }

        localDW->Timer_OverTemp = (uint16)tmp_0;
        tmp = localDW->Timer_OverTemp;
        if (localDW->Timer_OverTemp > 255U) {
          tmp = 255U;
        }

        *rty_b_Timer_OverTemp = (uint8)tmp;
        if (localDW->sfEvent == (sint32)App__event_Start_Timer_OverTemp) {
          localDW->Timer_OverTemp = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
static void enter_internal_Tick_Timer_OverT(uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->is_Tick_Timer_OverTemp = App_Model_IN_Off_lmxw;
  localDW->Timer_OverTemp = 0U;

  /* Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  *rty_b_Timer_OverTemp = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S381>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S593>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S813>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 */
void OverTemperatureDetecting3__Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_cijc;
  localDW->is_active_OverTemperatureDetect = 0U;
  localDW->is_OverTemperatureDetecting = App_Mod_IN_NO_ACTIVE_CHILD_pq51;
  localDW->is_active_Tick_Timer_OverTemp = 0U;
  localDW->is_Tick_Timer_OverTemp = App_Mod_IN_NO_ACTIVE_CHILD_pq51;
  localDW->is_active_c6_OverTemperatureDet = 0U;
  localDW->Timer_OverTemp = 0U;
  *rty_b_TemperatureFault = Off;
  *rty_b_Timer_OverTemp = 0U;
}

/*
 * System reset for atomic system:
 *    '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S381>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S593>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S813>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 */
void OverTemperatureDetecting3_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_cijc;
  localDW->is_active_OverTemperatureDetect = 0U;
  localDW->is_OverTemperatureDetecting = App_Mod_IN_NO_ACTIVE_CHILD_pq51;
  localDW->is_active_Tick_Timer_OverTemp = 0U;
  localDW->is_Tick_Timer_OverTemp = App_Mod_IN_NO_ACTIVE_CHILD_pq51;
  localDW->is_active_c6_OverTemperatureDet = 0U;
  localDW->Timer_OverTemp = 0U;
  *rty_b_TemperatureFault = Off;
  *rty_b_Timer_OverTemp = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S381>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S593>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 *    '<S813>/OverTemperatureDetecting3_5_SCR_211126_004_LPC'
 */
void OverTemperatureDetecting3_5_SCR(sint16 rtu_Temperature_Sensor1, sint16 rtu_Temperature_Sensor2, sint16 rtu_Temperature_Sensor3, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_cijc;

  /* Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  if ((uint32)localDW->is_active_c6_OverTemperatureDet == 0U) {
    localDW->is_active_c6_OverTemperatureDet = 1U;
    localDW->is_active_OverTemperatureDetect = 1U;
    localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
    localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
    if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
      App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
    }

    localDW->sfEvent = -1;
    *rty_b_TemperatureFault = Off;
    localDW->is_active_Tick_Timer_OverTemp = 1U;
    enter_internal_Tick_Timer_OverT(rty_b_Timer_OverTemp, localDW);
  } else {
    if ((uint32)localDW->is_active_OverTemperatureDetect != 0U) {
      switch (localDW->is_OverTemperatureDetecting) {
       case Ap_IN_TemperatureError_OffCheck:
        /* 1. */
        if (((uint32)rtu_WPCStatus != WPCMode) || (localDW->Timer_OverTemp >= ((uint16)500U))) {
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TemperatureFault = Off;

          /* 2. */
        } else if (((sint32)rtu_Temperature_Sensor1 > (sint32)((uint16)65U)) || ((sint32)rtu_Temperature_Sensor2 > (sint32)((uint16)65U)) || ((sint32)rtu_Temperature_Sensor3 > (sint32)((uint16)65U)))
        {
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_OverTemperatureDetecting = App_Mode_IN_Temperature_FaultOn;
          *rty_b_TemperatureFault = On;
        } else {
          /* no actions */
        }
        break;

       case App_IN_TemperatureError_OnCheck:
        /* 1. */
        if (((uint32)rtu_WPCStatus != WPCMode) || ((uint32)rtu_DeviceState == Standby) || (((sint32)rtu_Temperature_Sensor1 < (sint32)((uint16)70U)) && ((sint32)rtu_Temperature_Sensor2 < (sint32)
              ((uint16)70U)) && ((sint32)rtu_Temperature_Sensor3 < (sint32)((uint16)70U)))) {
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TemperatureFault = Off;

          /* 2. */
        } else if (localDW->Timer_OverTemp >= ((uint16)500U)) {
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_OverTemperatureDetecting = App_Mode_IN_Temperature_FaultOn;
          *rty_b_TemperatureFault = On;
        } else {
          /* no actions */
        }
        break;

       case App_Mode_IN_Temperature_FaultOn:
        *rty_b_TemperatureFault = On;

        /* 2. */
        if (((sint32)rtu_Temperature_Sensor1 <= (sint32)((uint16)65U)) && ((sint32)rtu_Temperature_Sensor2 <= (sint32)((uint16)65U)) && ((sint32)rtu_Temperature_Sensor3 <= (sint32)((uint16)65U))) {
          localDW->is_OverTemperatureDetecting = Ap_IN_TemperatureError_OffCheck;
          localDW->sfEvent = (sint32)App__event_Start_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;

          /* 1. */
        } else if ((uint32)rtu_WPCStatus != WPCMode) {
          localDW->is_OverTemperatureDetecting = App_Model_IN_Temperature_Normal;
          localDW->sfEvent = (sint32)App_event_Cancel_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TemperatureFault = Off;
        } else {
          /* no actions */
        }
        break;

       case App_Model_IN_Temperature_Normal:
        *rty_b_TemperatureFault = Off;

        /* 1. */
        if (((uint32)rtu_WPCStatus == WPCMode) && ((uint32)rtu_DeviceState != Standby) && (((sint32)rtu_Temperature_Sensor1 >= (sint32)((uint16)70U)) || ((sint32)rtu_Temperature_Sensor2 >= (sint32)
              ((uint16)70U)) || ((sint32)rtu_Temperature_Sensor3 >= (sint32)((uint16)70U)))) {
          localDW->is_OverTemperatureDetecting = App_IN_TemperatureError_OnCheck;
          localDW->sfEvent = (sint32)App__event_Start_Timer_OverTemp;
          if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
            App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
          }

          localDW->sfEvent = -1;
        }
        break;

       default:
        /* no actions */
        break;
      }
    }

    if ((uint32)localDW->is_active_Tick_Timer_OverTemp != 0U) {
      App_Model_Tick_Timer_OverTemp(rty_b_Timer_OverTemp, localDW);
    }
  }

  /* End of Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
}

/* System initialize for atomic system: '<S23>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_F_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemInitialize for Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3__Init(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetecting3_5_);
}

/* System reset for atomic system: '<S23>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting__Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemReset for Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_Reset(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetecting3_5_);
}

/* Output and update for atomic system: '<S23>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_Functi(WPCStatus rtu_WPCStatus, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_a0nf, sint16 rtu_PreProcessIn_n4bo, DeviceState rtu_PreProcessIn_ftxx, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* Chart: '<S191>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_5_SCR(rtu_PreProcessIn, rtu_PreProcessIn_a0nf, rtu_PreProcessIn_n4bo, rtu_PreProcessIn_ftxx, rtu_WPCStatus, rty_b_TemperatureFault, rty_b_Timer_OverTemp,
    &App_Model_DW.sf_OverTemperatureDetecting3_5_);
}

/* System initialize for atomic system: '<S218>/OverTemperatureDetecting_Function' */
void OverTemperatureDetect_hzjw_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemInitialize for Chart: '<S381>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3__Init(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetectin_mmt1);
}

/* System reset for atomic system: '<S218>/OverTemperatureDetecting_Function' */
void OverTemperatureDetec_b014_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemReset for Chart: '<S381>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_Reset(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetectin_mmt1);
}

/* Output and update for atomic system: '<S218>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_F_aewx(WPCStatus rtu_WPC2Status, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_nyiu, sint16 rtu_PreProcessIn_orls, DeviceState rtu_PreProcessIn_gpdt, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* Chart: '<S381>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_5_SCR(rtu_PreProcessIn, rtu_PreProcessIn_nyiu, rtu_PreProcessIn_orls, rtu_PreProcessIn_gpdt, rtu_WPC2Status, rty_b_TemperatureFault, rty_b_Timer_OverTemp,
    &App_Model_DW.sf_OverTemperatureDetectin_mmt1);
}

/* System initialize for atomic system: '<S463>/OverTemperatureDetecting_Function' */
void OverTemperatureDetect_crrl_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemInitialize for Chart: '<S593>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3__Init(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetectin_fvta);
}

/* System reset for atomic system: '<S463>/OverTemperatureDetecting_Function' */
void OverTemperatureDetec_a4ia_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemReset for Chart: '<S593>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_Reset(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetectin_fvta);
}

/* Output and update for atomic system: '<S463>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_F_jyxc(WPCStatus rtu_WPCStatus, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_ghfk, sint16 rtu_PreProcessIn_oeja, DeviceState rtu_PreProcessIn_i3rf, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* Chart: '<S593>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_5_SCR(rtu_PreProcessIn, rtu_PreProcessIn_ghfk, rtu_PreProcessIn_oeja, rtu_PreProcessIn_i3rf, rtu_WPCStatus, rty_b_TemperatureFault, rty_b_Timer_OverTemp,
    &App_Model_DW.sf_OverTemperatureDetectin_fvta);
}

/* System initialize for atomic system: '<S640>/OverTemperatureDetecting_Function' */
void OverTemperatureDetect_fms5_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemInitialize for Chart: '<S813>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3__Init(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetectin_jqs5);
}

/* System reset for atomic system: '<S640>/OverTemperatureDetecting_Function' */
void OverTemperatureDetec_dein_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* SystemReset for Chart: '<S813>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_Reset(rty_b_TemperatureFault, rty_b_Timer_OverTemp, &App_Model_DW.sf_OverTemperatureDetectin_jqs5);
}

/* Output and update for atomic system: '<S640>/OverTemperatureDetecting_Function' */
void OverTemperatureDetecting_F_moxt(WPCStatus rtu_WPCStatus, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_jv1h, sint16 rtu_PreProcessIn_bwtf, DeviceState rtu_PreProcessIn_lugo, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp)
{
  /* Chart: '<S813>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  OverTemperatureDetecting3_5_SCR(rtu_PreProcessIn, rtu_PreProcessIn_jv1h, rtu_PreProcessIn_bwtf, rtu_PreProcessIn_lugo, rtu_WPCStatus, rty_b_TemperatureFault, rty_b_Timer_OverTemp,
    &App_Model_DW.sf_OverTemperatureDetectin_jqs5);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
