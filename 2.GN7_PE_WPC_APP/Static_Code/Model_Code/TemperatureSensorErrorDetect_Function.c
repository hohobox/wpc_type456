/*
 * File: TemperatureSensorErrorDetect_Function.c
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
#include "TemperatureSensorErrorDetect_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
#define App_Mo_IN_TempSensorError_Check ((uint8)1U)
#define App_Mod_IN_NO_ACTIVE_CHILD_fhyi ((uint8)0U)
#define App_Mode_IN_TempSensorError_Off ((uint8)2U)
#define App_Model_CALL_EVENT_naym      (-1)
#define App_Model_IN_Off_ncdc          ((uint8)1U)
#define App_Model_IN_On_kcwt           ((uint8)2U)
#define App_Model_IN_TempSensorError_On ((uint8)3U)
#define event_Cancel_Timer_TempSensor_C (0)
#define event_Start_Timer_TempSensor_Ch (1)

/* Forward declaration for local functions */
static void App_Tick_Timer_TempSensor_Check(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
static void enter_internal_Tick_Timer_TempS(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);

/* Function for Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
static void App_Tick_Timer_TempSensor_Check(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  switch (localDW->is_Tick_Timer_TempSensor_Check) {
   case App_Model_IN_Off_ncdc:
    if (localDW->sfEvent == (sint32)event_Start_Timer_TempSensor_Ch) {
      localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_On_kcwt;
    }
    break;

   case App_Model_IN_On_kcwt:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_TempSensor_C) {
        localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_Off_ncdc;
        localDW->Timer_TempSensor_Check = 0U;
        *rty_b_Timer_TempSensor_Check = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_TempSensor_Check + 1;
        if (((sint32)localDW->Timer_TempSensor_Check + 1) > 255) {
          tmp = 255;
        }

        localDW->Timer_TempSensor_Check = (uint8)tmp;
        *rty_b_Timer_TempSensor_Check = localDW->Timer_TempSensor_Check;
        if (localDW->sfEvent == (sint32)event_Start_Timer_TempSensor_Ch) {
          localDW->Timer_TempSensor_Check = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
static void enter_internal_Tick_Timer_TempS(uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->is_Tick_Timer_TempSensor_Check = App_Model_IN_Off_ncdc;
  localDW->Timer_TempSensor_Check = 0U;

  /* Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  *rty_b_Timer_TempSensor_Check = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S193>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S383>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S595>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S815>/TemperatureSensorErrorDetect3_8_LPC'
 */
void TemperatureSensorErrorDete_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_naym;
  localDW->is_active_TempSensorErrorDetect = 0U;
  localDW->is_TempSensorErrorDetect = App_Mod_IN_NO_ACTIVE_CHILD_fhyi;
  localDW->is_active_Tick_Timer_TempSensor = 0U;
  localDW->is_Tick_Timer_TempSensor_Check = App_Mod_IN_NO_ACTIVE_CHILD_fhyi;
  localDW->is_active_c4_TemperatureSensorE = 0U;
  localDW->Timer_TempSensor_Check = 0U;
  *rty_b_TempSensorFault = Off;
  *rty_b_Timer_TempSensor_Check = 0U;
}

/*
 * System reset for atomic system:
 *    '<S193>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S383>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S595>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S815>/TemperatureSensorErrorDetect3_8_LPC'
 */
void TemperatureSensorErrorDet_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_naym;
  localDW->is_active_TempSensorErrorDetect = 0U;
  localDW->is_TempSensorErrorDetect = App_Mod_IN_NO_ACTIVE_CHILD_fhyi;
  localDW->is_active_Tick_Timer_TempSensor = 0U;
  localDW->is_Tick_Timer_TempSensor_Check = App_Mod_IN_NO_ACTIVE_CHILD_fhyi;
  localDW->is_active_c4_TemperatureSensorE = 0U;
  localDW->Timer_TempSensor_Check = 0U;
  *rty_b_TempSensorFault = Off;
  *rty_b_Timer_TempSensor_Check = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S193>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S383>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S595>/TemperatureSensorErrorDetect3_8_LPC'
 *    '<S815>/TemperatureSensorErrorDetect3_8_LPC'
 */
void TemperatureSensorErrorDetect3_8(Bool rtu_b_Temperature_SensorFault1, Bool rtu_b_Temperature_SensorFault2, Bool rtu_b_DTCClearFlag, WPCStatus rtu_WPCStatus, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_naym;

  /* Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  if ((uint32)localDW->is_active_c4_TemperatureSensorE == 0U) {
    localDW->is_active_c4_TemperatureSensorE = 1U;
    localDW->is_active_TempSensorErrorDetect = 1U;
    localDW->is_TempSensorErrorDetect = App_Mode_IN_TempSensorError_Off;
    localDW->sfEvent = (sint32)event_Cancel_Timer_TempSensor_C;
    if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
      App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
    }

    localDW->sfEvent = -1;
    *rty_b_TempSensorFault = Off;
    localDW->is_active_Tick_Timer_TempSensor = 1U;
    enter_internal_Tick_Timer_TempS(rty_b_Timer_TempSensor_Check, localDW);
  } else {
    if ((uint32)localDW->is_active_TempSensorErrorDetect != 0U) {
      switch (localDW->is_TempSensorErrorDetect) {
       case App_Mo_IN_TempSensorError_Check:
        /* 1. %NonGFS  */
        if (((uint32)rtu_WPCStatus != WPCMode) || ((uint32)rtu_b_DTCClearFlag == On) || (((uint32)rtu_b_Temperature_SensorFault1 == Off) && ((uint32)rtu_b_Temperature_SensorFault2 == Off) && ((uint32)
              rtu_b_Temperature_SensorFault2 == Off))) {
          localDW->sfEvent = (sint32)event_Cancel_Timer_TempSensor_C;
          if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->is_TempSensorErrorDetect = App_Mode_IN_TempSensorError_Off;
          localDW->sfEvent = (sint32)event_Cancel_Timer_TempSensor_C;
          if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TempSensorFault = Off;
        } else if (localDW->Timer_TempSensor_Check >= ((uint8)200U)) {
          localDW->sfEvent = (sint32)event_Cancel_Timer_TempSensor_C;
          if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_TempSensorErrorDetect = App_Model_IN_TempSensorError_On;
          *rty_b_TempSensorFault = On;
        } else {
          /* no actions */
        }
        break;

       case App_Mode_IN_TempSensorError_Off:
        *rty_b_TempSensorFault = Off;

        /* 1.  %NonGFS  */
        if (((uint32)rtu_WPCStatus == WPCMode) && ((uint32)rtu_b_DTCClearFlag == Off) && (((uint32)rtu_b_Temperature_SensorFault1 == On) || ((uint32)rtu_b_Temperature_SensorFault2 == On) || ((uint32)
              rtu_b_Temperature_SensorFault2 == On))) {
          localDW->is_TempSensorErrorDetect = App_Mo_IN_TempSensorError_Check;
          localDW->sfEvent = (sint32)event_Start_Timer_TempSensor_Ch;
          if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
        }
        break;

       case App_Model_IN_TempSensorError_On:
        *rty_b_TempSensorFault = On;

        /* 1.
           [WPCStatus != WPCMode ||.... 8차 선반영 */
        if (((uint32)rtu_WPCStatus == ModeOff) || ((uint32)rtu_b_DTCClearFlag == On)) {
          /* NonGFS */
          localDW->is_TempSensorErrorDetect = App_Mode_IN_TempSensorError_Off;
          localDW->sfEvent = (sint32)event_Cancel_Timer_TempSensor_C;
          if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
            App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
          }

          localDW->sfEvent = -1;
          *rty_b_TempSensorFault = Off;
        }
        break;

       default:
        /* no actions */
        break;
      }
    }

    if ((uint32)localDW->is_active_Tick_Timer_TempSensor != 0U) {
      App_Tick_Timer_TempSensor_Check(rty_b_Timer_TempSensor_Check, localDW);
    }
  }

  /* End of Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
}

/* System initialize for atomic system: '<S23>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErro_lwl5_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemInitialize for Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDete_Init(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorDetect);
}

/* System reset for atomic system: '<S23>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErr_h0ez_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemReset for Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDet_Reset(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorDetect);
}

/* Output and update for atomic system: '<S23>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDetect_Fu(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_pjuf, Bool rtu_PreProcessIn_e1ca, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check)
{
  /* Chart: '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDetect3_8(rtu_PreProcessIn, rtu_PreProcessIn_pjuf, rtu_PreProcessIn_e1ca, rtu_WPCStatus, rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check,
    &App_Model_DW.sf_TemperatureSensorErrorDetect);
}

/* System initialize for atomic system: '<S218>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErro_lytz_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemInitialize for Chart: '<S383>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDete_Init(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorD_piso);
}

/* System reset for atomic system: '<S218>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErr_hbvc_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemReset for Chart: '<S383>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDet_Reset(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorD_piso);
}

/* Output and update for atomic system: '<S218>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDete_hhj5(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn1, Bool rtu_PreProcessIn1_mbvk, Bool rtu_PreProcessIn1_mdmv, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check)
{
  /* Chart: '<S383>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDetect3_8(rtu_PreProcessIn1, rtu_PreProcessIn1_mbvk, rtu_PreProcessIn1_mdmv, rtu_WPC2Status, rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check,
    &App_Model_DW.sf_TemperatureSensorErrorD_piso);
}

/* System initialize for atomic system: '<S463>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErro_fuus_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemInitialize for Chart: '<S595>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDete_Init(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorD_m0mu);
}

/* System reset for atomic system: '<S463>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErr_ehys_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemReset for Chart: '<S595>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDet_Reset(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorD_m0mu);
}

/* Output and update for atomic system: '<S463>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDete_kspf(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_adgt, Bool rtu_PreProcessIn_knhi, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check)
{
  /* Chart: '<S595>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDetect3_8(rtu_PreProcessIn, rtu_PreProcessIn_adgt, rtu_PreProcessIn_knhi, rtu_WPCStatus, rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check,
    &App_Model_DW.sf_TemperatureSensorErrorD_m0mu);
}

/* System initialize for atomic system: '<S640>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErro_ixmp_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemInitialize for Chart: '<S815>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDete_Init(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorD_p5cx);
}

/* System reset for atomic system: '<S640>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErr_nw4b_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check)
{
  /* SystemReset for Chart: '<S815>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDet_Reset(rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check, &App_Model_DW.sf_TemperatureSensorErrorD_p5cx);
}

/* Output and update for atomic system: '<S640>/TemperatureSensorErrorDetect_Function' */
void TemperatureSensorErrorDete_p4vb(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_frn2, Bool rtu_PreProcessIn_l13e, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check)
{
  /* Chart: '<S815>/TemperatureSensorErrorDetect3_8_LPC' */
  TemperatureSensorErrorDetect3_8(rtu_PreProcessIn, rtu_PreProcessIn_frn2, rtu_PreProcessIn_l13e, rtu_WPCStatus, rty_b_TempSensorFault, rty_b_Timer_TempSensor_Check,
    &App_Model_DW.sf_TemperatureSensorErrorD_p5cx);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
