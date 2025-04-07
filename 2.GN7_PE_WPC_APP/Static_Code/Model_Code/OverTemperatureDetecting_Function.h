/*
 * File: OverTemperatureDetecting_Function.h
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

#ifndef RTW_HEADER_OverTemperatureDetecting_Function_h_
#define RTW_HEADER_OverTemperatureDetecting_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
typedef struct {
  sint32 sfEvent;                      /* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  uint16 Timer_OverTemp;               /* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  uint8 is_active_c6_OverTemperatureDet;/* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  uint8 is_OverTemperatureDetecting;   /* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  uint8 is_active_OverTemperatureDetect;/* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  uint8 is_Tick_Timer_OverTemp;        /* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
  uint8 is_active_Tick_Timer_OverTemp; /* '<S183>/OverTemperatureDetecting3_5_SCR_211126_004_LPC' */
} DW_OverTemperatureDetecting3__T;

extern void OverTemperatureDetecting3__Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);
extern void OverTemperatureDetecting3_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);
extern void OverTemperatureDetecting3_5_SCR(sint16 rtu_Temperature_Sensor1, sint16 rtu_Temperature_Sensor2, sint16 rtu_Temperature_Sensor3, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp, DW_OverTemperatureDetecting3__T *localDW);
extern void OverTemperatureDetecting_F_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp);
extern void OverTemperatureDetecting_Functi(WPCStatus rtu_WPCStatus, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_a, sint16 rtu_PreProcessIn_n, DeviceState rtu_PreProcessIn_f, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp);
extern void OverTemperatureDetecting_l_Init(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp);
extern void OverTemperatureDetectin_c_Reset(Bool *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp);
extern void OverTemperatureDetecting_Func_a(WPCStatus rtu_WPC2Status, sint16 rtu_PreProcessIn, sint16 rtu_PreProcessIn_n, sint16 rtu_PreProcessIn_o, DeviceState rtu_PreProcessIn_g, Bool
  *rty_b_TemperatureFault, uint8 *rty_b_Timer_OverTemp);

#endif                                 /* RTW_HEADER_OverTemperatureDetecting_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
