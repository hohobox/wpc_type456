/*
 * File: TemperatureSensorErrorDetect_Function.h
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

#ifndef RTW_HEADER_TemperatureSensorErrorDetect_Function_h_
#define RTW_HEADER_TemperatureSensorErrorDetect_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
typedef struct {
  sint32 sfEvent;                      /* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_active_c4_TemperatureSensorE;/* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_TempSensorErrorDetect;      /* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_active_TempSensorErrorDetect;/* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_Tick_Timer_TempSensor_Check;/* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_active_Tick_Timer_TempSensor;/* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 Timer_TempSensor_Check;        /* '<S185>/TemperatureSensorErrorDetect3_8_LPC' */
} DW_TemperatureSensorErrorDete_T;

extern void TemperatureSensorErrorDete_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
extern void TemperatureSensorErrorDet_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
extern void TemperatureSensorErrorDetect3_8(Bool rtu_b_Temperature_SensorFault1, Bool rtu_b_Temperature_SensorFault2, Bool rtu_b_DTCClearFlag, WPCStatus rtu_WPCStatus, Bool *rty_b_TempSensorFault,
  uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
extern void TemperatureSensorErrorDe_l_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDetect_Fu(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_p, Bool rtu_PreProcessIn_e, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDe_d_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorD_d_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDetect__h(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn1, Bool rtu_PreProcessIn1_m, Bool rtu_PreProcessIn1_md, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check);

#endif                                 /* RTW_HEADER_TemperatureSensorErrorDetect_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
