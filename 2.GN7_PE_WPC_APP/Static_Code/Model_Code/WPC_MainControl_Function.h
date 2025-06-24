/*
 * File: WPC_MainControl_Function.h
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

#ifndef RTW_HEADER_WPC_MainControl_Function_h_
#define RTW_HEADER_WPC_MainControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S25>/Chart' */
typedef struct {
  uint8 is_active_c6_App_Model;        /* '<S25>/Chart' */
} DW_Chart_App_Model_T;

/* Block states (default storage) for system '<S212>/WPC_MainControl2_250507' */
typedef struct {
  sint32 sfEvent;                      /* '<S212>/WPC_MainControl2_250507' */
  uint16 Timer_AmberINDBlk;            /* '<S212>/WPC_MainControl2_250507' */
  uint16 Timer_PhoneReminderCheck;     /* '<S212>/WPC_MainControl2_250507' */
  uint16 Timer_PhoneWarningCheck;      /* '<S212>/WPC_MainControl2_250507' */
  uint16 Timer_WarningComplete;        /* '<S212>/WPC_MainControl2_250507' */
  uint16 Timer_AmberINDBlk2;           /* '<S212>/WPC_MainControl2_250507' */
  uint16 Timer_PhnLeftChattering;      /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_c42_MainControl_Lib; /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_PhoneLeft;       /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_PhoneLeft;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_MainControl;                /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_MainControl;         /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_WPCMode_Disable;            /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_WPCMode_Enable;             /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_WPCMode_Stop;               /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_WPCMode_Run;                /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_PhoneWarningCheck;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_PhoneWarni;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_PhoneReminderChec;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_PhoneRemin;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_WarningComplete; /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_WarningCom;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_AmberINDBlk;     /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_AmberINDBl;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_AmberINDBlk2;    /* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_Amber_aksf;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_Tick_Timer_PhnLeftChattering;/* '<S212>/WPC_MainControl2_250507' */
  uint8 is_active_Tick_Timer_PhnLeftCha;/* '<S212>/WPC_MainControl2_250507' */
  uint8 Timer_PhoneLeft;               /* '<S212>/WPC_MainControl2_250507' */
  uint8 Counter_BlinkCnt;              /* '<S212>/WPC_MainControl2_250507' */
  Bool b_WarnClearEnable;              /* '<S212>/WPC_MainControl2_250507' */
  Bool b_Timer_PhoneReminderCheck_is_R;/* '<S212>/WPC_MainControl2_250507' */
  Bool b_WPCPhoneExist_prev;           /* '<S212>/WPC_MainControl2_250507' */
  Bool b_WPCPhoneExist_start;          /* '<S212>/WPC_MainControl2_250507' */
  Bool C_DrvDrSw_prev;                 /* '<S212>/WPC_MainControl2_250507' */
  Bool C_DrvDrSw_start;                /* '<S212>/WPC_MainControl2_250507' */
  Bool C_AstDrSw_prev;                 /* '<S212>/WPC_MainControl2_250507' */
  Bool C_AstDrSw_start;                /* '<S212>/WPC_MainControl2_250507' */
  Bool L_IGN1_IN_prev;                 /* '<S212>/WPC_MainControl2_250507' */
  Bool L_IGN1_IN_start;                /* '<S212>/WPC_MainControl2_250507' */
  WPCIndCmdState WPCIndCmdState_prev;  /* '<S212>/WPC_MainControl2_250507' */
  WPCIndCmdState WPCIndCmdState_start; /* '<S212>/WPC_MainControl2_250507' */
} DW_WPC_MainControl2_250507_Ap_T;

/* Block states (default storage) for system '<S211>/WPC_MainControl2_EV_250328_HMC' */
typedef struct {
  sint32 sfEvent;                      /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint16 Timer_AmberINDBlk;            /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint16 Timer_PhoneWarningCheck;      /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint16 Timer_WarningComplete;        /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint16 Timer_WarningTypeCheck;       /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint16 b_WarnClearEnable;            /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint16 Timer_AmberINDBlk2;           /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_c70_MainControl_Lib; /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_MainControl;                /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_MainControl;         /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_WPCMode_Disable;            /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_WPCMode_Off;                /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_WPCMode_Enable;             /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_WPCMode_Stop;               /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_WPCMode_Run;                /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_Tick_Timer_PhoneLeft;       /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_Tick_Timer_PhoneLeft;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_Tick_Timer_PhoneWarningCheck;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_Tick_Timer_PhoneWarni;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_Tick_Timer_WarningComplete; /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_Tick_Timer_WarningCom;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_Tick_Timer_AmberINDBlk;     /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_Tick_Timer_AmberINDBl;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_Tick_Timer_WarningTypeCheck;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_Tick_Timer_WarningTyp;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_Tick_Timer_AmberINDBlk2;    /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 is_active_Tick_Timer_Amber_ba0g;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 Timer_PhoneLeft;               /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  uint8 Counter_BlinkCnt;              /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  Bool Input_OPT_b_WPCPhoneExist_prev; /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  Bool Input_OPT_b_WPCPhoneExist_start;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  Bool b_DrvDrSw_prev;                 /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  Bool b_DrvDrSw_start;                /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  WPCIndCmdState WPCIndCmdState_prev;  /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  WPCIndCmdState WPCIndCmdState_start; /* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  PhoneLeftWrnType PhoneLeftWrnType_irrq;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  GearPosSta Input_OPT_GearPosSta_prev;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
  GearPosSta Input_OPT_GearPosSta_start;/* '<S211>/WPC_MainControl2_EV_250328_HMC' */
} DW_WPC_MainControl2_EV_250328_T;

/* Block states (default storage) for system '<S210>/WPC_MainControl3_CardSync_250522' */
typedef struct {
  sint32 sfEvent;                      /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint16 Timer_AmberINDBlk;            /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint16 Timer_PhoneReminderCheck;     /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint16 Timer_PhoneWarningCheck;      /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint16 Timer_WarningComplete;        /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint16 Timer_AmberINDBlk2;           /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint16 Timer_CardINDBlk;             /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_c53_MainControl_Lib; /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_MainControl;                /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_MainControl;         /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_WPCMode_Disable;            /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_WPCMode_Off;                /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_WPCMode_Enable;             /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_WPCMode_Stop;               /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_WPCMode_Run;                /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_PhoneLeft;       /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_PhoneLeft;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_PhoneWarningCheck;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_PhoneWarni;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_PhoneReminderChec;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_PhoneRemin;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_WarningComplete; /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_WarningCom;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_AmberINDBlk;     /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_AmberINDBl;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_AmberINDBlk2;    /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_Amber_l1wn;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_Tick_Timer_CardINDBlk;      /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 is_active_Tick_Timer_CardINDBlk;/* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 Timer_PhoneLeft;               /* '<S210>/WPC_MainControl3_CardSync_250522' */
  uint8 Counter_BlinkCnt;              /* '<S210>/WPC_MainControl3_CardSync_250522' */
  Bool b_WarnClearEnable;              /* '<S210>/WPC_MainControl3_CardSync_250522' */
  Bool b_WPCPhoneExist_prev;           /* '<S210>/WPC_MainControl3_CardSync_250522' */
  Bool b_WPCPhoneExist_start;          /* '<S210>/WPC_MainControl3_CardSync_250522' */
  Bool L_IGN1_IN_prev;                 /* '<S210>/WPC_MainControl3_CardSync_250522' */
  Bool L_IGN1_IN_start;                /* '<S210>/WPC_MainControl3_CardSync_250522' */
  WPCIndCmdState WPCIndCmdState_prev;  /* '<S210>/WPC_MainControl3_CardSync_250522' */
  WPCIndCmdState WPCIndCmdState_start; /* '<S210>/WPC_MainControl3_CardSync_250522' */
} DW_WPC_MainControl3_CardSync__T;

/* Block states (default storage) for system '<S209>/WPC_MainControl_EV_250522_HMC' */
typedef struct {
  sint32 sfEvent;                      /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint16 Timer_AmberINDBlk;            /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint16 Timer_PhoneWarningCheck;      /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint16 Timer_WarningComplete;        /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint16 Timer_WarningTypeCheck;       /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint16 b_WarnClearEnable;            /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint16 Timer_AmberINDBlk2;           /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_c61_MainControl_Lib; /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_MainControl;                /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_MainControl;         /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_WPCMode_Disable;            /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_WPCMode_Off;                /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_WPCMode_Enable;             /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_WPCMode_Stop;               /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_WPCMode_Run;                /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_Tick_Timer_PhoneLeft;       /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_Tick_Timer_PhoneLeft;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_Tick_Timer_PhoneWarningCheck;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_Tick_Timer_PhoneWarni;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_Tick_Timer_WarningComplete; /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_Tick_Timer_WarningCom;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_Tick_Timer_AmberINDBlk;     /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_Tick_Timer_AmberINDBl;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_Tick_Timer_WarningTypeCheck;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_Tick_Timer_WarningTyp;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_Tick_Timer_AmberINDBlk2;    /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 is_active_Tick_Timer_Amber_berc;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 Timer_PhoneLeft;               /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  uint8 Counter_BlinkCnt;              /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  Bool Input_OPT_b_WPCPhoneExist_prev; /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  Bool Input_OPT_b_WPCPhoneExist_start;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  Bool b_DrvDrSw_prev;                 /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  Bool b_DrvDrSw_start;                /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  WPCIndCmdState WPCIndCmdState_prev;  /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  WPCIndCmdState WPCIndCmdState_start; /* '<S209>/WPC_MainControl_EV_250522_HMC' */
  PhoneLeftWrnType PhoneLeftWrnType_lkkm;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  GearPosSta Input_OPT_GearPosSta_prev;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
  GearPosSta Input_OPT_GearPosSta_start;/* '<S209>/WPC_MainControl_EV_250522_HMC' */
} DW_WPC_MainControl_EV_250522__T;

extern void App_Model_Chart_Init(MainContMode *rty_MainContMode, DW_Chart_App_Model_T *localDW);
extern void App_Model_Chart_Reset(MainContMode *rty_MainContMode, DW_Chart_App_Model_T *localDW);
extern void App_Model_Chart(Bool rtu_Uds_m_NFCOption, Bool rtu_NvM_EVOpt, MainContMode *rty_MainContMode, DW_Chart_App_Model_T *localDW);
extern void Ap_WPC_MainControl2_250507_Init(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl2_250507_Ap_T *localDW);
extern void App_Mod_WPC_MainControl2_250507(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_b_TemperatureFault, Bool
  rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool rtu_L_IGN1_IN, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdAmberSync,
  WPCIndCmdState rtu_WPCIndCmdState, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl2_250507_Ap_T *localDW);
extern void WPC_MainControl2_EV_250328_Init(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool
  *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW);
extern void WPC_MainControl2_EV_250328_HMC(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist,
  C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState
  rtu_Input_IND_WPCIndUSMState, Bool rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, WPCIndCmdState rtu_WPCIndCmdState, C_WPCWarning *rty_Output_WPCWarning, Bool
  *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16
  *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T
  *localDW);
extern void WPC_MainControl3_CardSync__Init(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl3_CardSync__T *localDW);
extern void WPC_MainControl3_CardSync_25052(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_b_TemperatureFault, Bool
  rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool rtu_L_IGN1_IN, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync,
  WPCIndCmdState rtu_WPCIndCmdState, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool
  *rty_b_BlinkState, uint16 *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool
  *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *localDW);
extern void WPC_MainControl_EV_250522__Init(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool
  *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW);
extern void A_WPC_MainControl_EV_250522_HMC(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist,
  C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState
  rtu_Input_IND_WPCIndUSMState, Bool rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, WPCIndCmdState rtu_WPCIndCmdState, C_WPCWarning rtu_PhoneLeftWarningWPCStatus,
  C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16
  *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool
  *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW);
extern void A_WPC_MainControl_Function_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m0hg, Bool *rty_MainOut_Sig_lm4d, Bool *rty_MainOut_Sig_gidz, Bool *rty_MainOut_Sig_gyaw, uint16
  *rty_MainOut_Sig_bv10, uint16 *rty_MainOut_Sig_jtve, uint16 *rty_MainOut_Sig_jymu, Bool *rty_MainOut_Sig_a14n, BlinkState *rty_MainOut_Sig_hq4y, Bool *rty_MainOut_Sig_khfv, uint16
  *rty_MainOut_Sig_lzgx);
extern void WPC_MainControl_Function_Reset(void);
extern void App_Mo_WPC_MainControl_Function(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m0hg, Bool rtu_Main_InSig_lm4d, Bool rtu_Main_InSig_gidz, Bool rtu_Main_InSig_gyaw, C_WPCOnOffNvalueSet
  rtu_Main_InSig_bv10, Bool rtu_Main_InSig_jtve, Bool rtu_Main_InSig_jymu, Bool rtu_Main_InSig_a14n, Bool rtu_Main_InSig_hq4y, DeviceState rtu_Main_InSig_khfv, WPCStatus rtu_Main_InSig_lzgx, Bool
  rtu_Main_InSig_h0c5, WPCIndUSMState rtu_Main_InSig_k1w3, Bool rtu_Main_InSig_fwrw, WPCIndCmdState rtu_Main_InSig_hwiv, GearPosSta rtu_Main_InSig_fy33, C_WPCWarning rtu_Main_InSig_no0k, C_WPCWarning *
  rty_MainOut_Sig, Bool *rty_MainOut_Sig_m0hg, Bool *rty_MainOut_Sig_lm4d, Bool *rty_MainOut_Sig_gidz, Bool *rty_MainOut_Sig_gyaw, uint16 *rty_MainOut_Sig_bv10, uint16 *rty_MainOut_Sig_jtve, uint16
  *rty_MainOut_Sig_jymu, Bool *rty_MainOut_Sig_a14n, BlinkState *rty_MainOut_Sig_hq4y, Bool *rty_MainOut_Sig_khfv, uint16 *rty_MainOut_Sig_lzgx);
extern void WPC_MainControl_Funct_cp2h_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_gmt2, Bool *rty_MainOut_Sig_b5rk, Bool *rty_MainOut_Sig_e0fo, Bool *rty_MainOut_Sig_gcjy, uint16
  *rty_MainOut_Sig_jjhc, uint16 *rty_MainOut_Sig_nv40, uint16 *rty_MainOut_Sig_nt21, Bool *rty_MainOut_Sig_pg4m, BlinkState *rty_MainOut_Sig_pov1, Bool *rty_MainOut_Sig_kyig, uint16
  *rty_MainOut_Sig_nwkh);
extern void WPC_MainControl_Func_klre_Reset(void);
extern void A_WPC_MainControl_Function_e3ud(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, Bool rtu_Main_InSig_kyig, WPCIndUSMState rtu_Main_InSig_nwkh,
  Bool rtu_Main_InSig_htzs, WPC2IndCmdState rtu_Main_InSig_n4dm, GearPosSta rtu_Main_InSig_jgrv, C_WPCWarning rtu_Main_InSig_lhyq, Bool rtu_Main_InSig_m0ue, Bool rtu_Main_InSig_gspt, C_WPCWarning
  *rty_MainOut_Sig, Bool *rty_MainOut_Sig_gmt2, Bool *rty_MainOut_Sig_b5rk, Bool *rty_MainOut_Sig_e0fo, Bool *rty_MainOut_Sig_gcjy, uint16 *rty_MainOut_Sig_jjhc, uint16 *rty_MainOut_Sig_nv40, uint16
  *rty_MainOut_Sig_nt21, Bool *rty_MainOut_Sig_pg4m, BlinkState *rty_MainOut_Sig_pov1, Bool *rty_MainOut_Sig_kyig, uint16 *rty_MainOut_Sig_nwkh);
extern void WPC_MainControl_Funct_btar_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_ld2g, Bool *rty_MainOut_Sig_a0gd, Bool *rty_MainOut_Sig_lm51, Bool *rty_MainOut_Sig_gfkd, uint16
  *rty_MainOut_Sig_bvye, uint16 *rty_MainOut_Sig_exqx, uint16 *rty_MainOut_Sig_c0zj, Bool *rty_MainOut_Sig_pfli, BlinkState *rty_MainOut_Sig_o3od, Bool *rty_MainOut_Sig_ll4c, uint16
  *rty_MainOut_Sig_kivv);
extern void A_WPC_MainControl_Function_lgtv(Bool rtu_Main_InSig, Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool
  rtu_Main_InSig_bvye, Bool rtu_Main_InSig_exqx, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, DeviceState rtu_Main_InSig_o3od, WPCStatus rtu_Main_InSig_ll4c, Bool rtu_Main_InSig_kivv,
  WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x, RWPCIndCmdState rtu_Main_InSig_agui, GearPosSta rtu_Main_InSig_m0c4, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_ld2g, Bool
  *rty_MainOut_Sig_a0gd, Bool *rty_MainOut_Sig_lm51, Bool *rty_MainOut_Sig_gfkd, uint16 *rty_MainOut_Sig_bvye, uint16 *rty_MainOut_Sig_exqx, uint16 *rty_MainOut_Sig_c0zj, Bool *rty_MainOut_Sig_pfli,
  BlinkState *rty_MainOut_Sig_o3od, Bool *rty_MainOut_Sig_ll4c, uint16 *rty_MainOut_Sig_kivv);
extern void WPC_MainControl_Funct_c5v2_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_grvv, Bool *rty_MainOut_Sig_nok3, Bool *rty_MainOut_Sig_fabi, Bool *rty_MainOut_Sig_pnk1, uint16
  *rty_MainOut_Sig_kq4p, uint16 *rty_MainOut_Sig_oxwl, uint16 *rty_MainOut_Sig_iocw, Bool *rty_MainOut_Sig_biyp, BlinkState *rty_MainOut_Sig_ig04, Bool *rty_MainOut_Sig_o5is, uint16
  *rty_MainOut_Sig_blb1);
extern void WPC_MainControl_Func_aih4_Reset(void);
extern void A_WPC_MainControl_Function_agcy(Bool rtu_Main_InSig, Bool rtu_Main_InSig_grvv, Bool rtu_Main_InSig_nok3, Bool rtu_Main_InSig_fabi, Bool rtu_Main_InSig_pnk1, C_WPCOnOffNvalueSet
  rtu_Main_InSig_kq4p, Bool rtu_Main_InSig_oxwl, Bool rtu_Main_InSig_iocw, Bool rtu_Main_InSig_biyp, Bool rtu_Main_InSig_ig04, DeviceState rtu_Main_InSig_o5is, WPCStatus rtu_Main_InSig_blb1, Bool
  rtu_Main_InSig_ikrw, WPCIndUSMState rtu_Main_InSig_fv4u, Bool rtu_Main_InSig_jnua, WPCIndCmdState rtu_Main_InSig_pbxa, GearPosSta rtu_Main_InSig_duir, C_WPCWarning rtu_Main_InSig_iouk, C_WPCWarning *
  rty_MainOut_Sig, Bool *rty_MainOut_Sig_grvv, Bool *rty_MainOut_Sig_nok3, Bool *rty_MainOut_Sig_fabi, Bool *rty_MainOut_Sig_pnk1, uint16 *rty_MainOut_Sig_kq4p, uint16 *rty_MainOut_Sig_oxwl, uint16
  *rty_MainOut_Sig_iocw, Bool *rty_MainOut_Sig_biyp, BlinkState *rty_MainOut_Sig_ig04, Bool *rty_MainOut_Sig_o5is, uint16 *rty_MainOut_Sig_blb1);

#endif                                 /* RTW_HEADER_WPC_MainControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
