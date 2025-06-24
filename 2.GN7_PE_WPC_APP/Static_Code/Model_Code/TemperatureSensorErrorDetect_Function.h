/*
 * File: TemperatureSensorErrorDetect_Function.h
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

#ifndef RTW_HEADER_TemperatureSensorErrorDetect_Function_h_
#define RTW_HEADER_TemperatureSensorErrorDetect_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
typedef struct {
  sint32 sfEvent;                      /* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_active_c4_TemperatureSensorE;/* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_TempSensorErrorDetect;      /* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_active_TempSensorErrorDetect;/* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_Tick_Timer_TempSensor_Check;/* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 is_active_Tick_Timer_TempSensor;/* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
  uint8 Timer_TempSensor_Check;        /* '<S193>/TemperatureSensorErrorDetect3_8_LPC' */
} DW_TemperatureSensorErrorDete_T;

extern void TemperatureSensorErrorDete_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
extern void TemperatureSensorErrorDet_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
extern void TemperatureSensorErrorDetect3_8(Bool rtu_b_Temperature_SensorFault1, Bool rtu_b_Temperature_SensorFault2, Bool rtu_b_DTCClearFlag, WPCStatus rtu_WPCStatus, Bool *rty_b_TempSensorFault,
  uint8 *rty_b_Timer_TempSensor_Check, DW_TemperatureSensorErrorDete_T *localDW);
extern void TemperatureSensorErro_lwl5_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErr_h0ez_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDetect_Fu(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_pjuf, Bool rtu_PreProcessIn_e1ca, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErro_lytz_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErr_hbvc_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDete_hhj5(WPCStatus rtu_WPC2Status, Bool rtu_PreProcessIn1, Bool rtu_PreProcessIn1_mbvk, Bool rtu_PreProcessIn1_mdmv, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErro_fuus_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErr_ehys_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDete_kspf(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_adgt, Bool rtu_PreProcessIn_knhi, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErro_ixmp_Init(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErr_nw4b_Reset(Bool *rty_b_TempSensorFault, uint8 *rty_b_Timer_TempSensor_Check);
extern void TemperatureSensorErrorDete_p4vb(WPCStatus rtu_WPCStatus, Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_frn2, Bool rtu_PreProcessIn_l13e, Bool *rty_b_TempSensorFault, uint8
  *rty_b_Timer_TempSensor_Check);

#endif                                 /* RTW_HEADER_TemperatureSensorErrorDetect_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
