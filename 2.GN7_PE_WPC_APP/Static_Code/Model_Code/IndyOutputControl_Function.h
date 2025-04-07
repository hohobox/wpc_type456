/*
 * File: IndyOutputControl_Function.h
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

#ifndef RTW_HEADER_IndyOutputControl_Function_h_
#define RTW_HEADER_IndyOutputControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S85>/Amber_IND_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c323_IndyOutputContro;/* '<S85>/Amber_IND_Control_Function_Flow_Graph' */
} DW_Amber_IND_Control_Function_T;

/* Block states (default storage) for system '<S87>/FadeIn' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S95>/Delay Input1' */
  float64 UnitDelay_DSTATE;            /* '<S93>/Unit Delay' */
} DW_FadeIn_App_Model_T;

/* Block states (default storage) for system '<S87>/FadeOut' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S101>/Delay Input2' */
  uint32 FadeOut_ELAPS_T;              /* '<S87>/FadeOut' */
  uint32 FadeOut_PREV_T;               /* '<S87>/FadeOut' */
  uint16 DelayInput1_DSTATE;           /* '<S97>/Delay Input1' */
  boolean FadeOut_RESET_ELAPS_T;       /* '<S87>/FadeOut' */
} DW_FadeOut_App_Model_T;

/* Block signals for system '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass_c;                      /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_g;         /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S94>/Switch1' */
  uint16 Switch2;                      /* '<S93>/Switch2' */
  sint8 Trigger;                       /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger_FO;                    /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Amber_IND_with_Animation_Co_T;

/* Block states (default storage) for system '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c425_IndyOutputContro;/* '<S85>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut_App_Model_T FadeOut;      /* '<S87>/FadeOut' */
  DW_FadeIn_App_Model_T FadeIn;        /* '<S87>/FadeIn' */
} DW_Amber_IND_with_Animation_C_T;

/* Block states (default storage) for system '<S85>/Bright_Max_Value_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c333_IndyOutputContro;/* '<S85>/Bright_Max_Value_Control_Function_Flow_Graph' */
} DW_Bright_Max_Value_Control_F_T;

/* Block states (default storage) for system '<S85>/Green_IND_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c337_IndyOutputContro;/* '<S85>/Green_IND_Control_Function_Flow_Graph' */
} DW_Green_IND_Control_Function_T;

/* Block states (default storage) for system '<S90>/FadeIn1' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S109>/Delay Input1' */
  float64 UnitDelay_DSTATE;            /* '<S103>/Unit Delay' */
} DW_FadeIn1_App_Model_T;

/* Block states (default storage) for system '<S90>/FadeOut1' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S119>/Delay Input2' */
  uint32 FadeOut1_ELAPS_T;             /* '<S90>/FadeOut1' */
  uint32 FadeOut1_PREV_T;              /* '<S90>/FadeOut1' */
  uint16 DelayInput1_DSTATE;           /* '<S115>/Delay Input1' */
  boolean FadeOut1_RESET_ELAPS_T;      /* '<S90>/FadeOut1' */
} DW_FadeOut1_App_Model_T;

/* Block states (default storage) for system '<S90>/FadeIn2' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S111>/Delay Input1' */
  float64 UnitDelay_DSTATE;            /* '<S104>/Unit Delay' */
} DW_FadeIn2_App_Model_T;

/* Block states (default storage) for system '<S90>/FadeOut2' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S125>/Delay Input2' */
  uint32 FadeOut2_ELAPS_T;             /* '<S90>/FadeOut2' */
  uint32 FadeOut2_PREV_T;              /* '<S90>/FadeOut2' */
  uint16 DelayInput1_DSTATE;           /* '<S121>/Delay Input1' */
  boolean FadeOut2_RESET_ELAPS_T;      /* '<S90>/FadeOut2' */
} DW_FadeOut2_App_Model_T;

/* Block states (default storage) for system '<S90>/FadeIn3' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S113>/Delay Input1' */
  float64 UnitDelay_DSTATE;            /* '<S105>/Unit Delay' */
} DW_FadeIn3_App_Model_T;

/* Block states (default storage) for system '<S90>/FadeOut3' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S131>/Delay Input2' */
  uint32 FadeOut3_ELAPS_T;             /* '<S90>/FadeOut3' */
  uint32 FadeOut3_PREV_T;              /* '<S90>/FadeOut3' */
  uint16 DelayInput1_DSTATE;           /* '<S127>/Delay Input1' */
  boolean FadeOut3_RESET_ELAPS_T;      /* '<S90>/FadeOut3' */
} DW_FadeOut3_App_Model_T;

/* Block signals for system '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass1_f;                     /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2_a;                     /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3_j;                     /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_p;         /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_pw;        /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_a;         /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_f;                   /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_c;         /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_g;         /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_j;                   /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S108>/Switch1' */
  uint16 Switch2;                      /* '<S105>/Switch2' */
  uint16 Switch1_d;                    /* '<S107>/Switch1' */
  uint16 Switch2_g;                    /* '<S104>/Switch2' */
  uint16 Switch1_o;                    /* '<S106>/Switch1' */
  uint16 Switch2_c;                    /* '<S103>/Switch2' */
  sint8 Trigger1;                      /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger1_FO;                   /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2;                      /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2_FO;                   /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3;                      /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3_FO;                   /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Green_IND_with_Animation_Co_T;

/* Block states (default storage) for system '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c427_IndyOutputContro;/* '<S85>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut3_App_Model_T FadeOut3;    /* '<S90>/FadeOut3' */
  DW_FadeIn3_App_Model_T FadeIn3;      /* '<S90>/FadeIn3' */
  DW_FadeOut2_App_Model_T FadeOut2;    /* '<S90>/FadeOut2' */
  DW_FadeIn2_App_Model_T FadeIn2;      /* '<S90>/FadeIn2' */
  DW_FadeOut1_App_Model_T FadeOut1;    /* '<S90>/FadeOut1' */
  DW_FadeIn1_App_Model_T FadeIn1;      /* '<S90>/FadeIn1' */
} DW_Green_IND_with_Animation_C_T;

/* Block states (default storage) for system '<S85>/IND_Output_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c428_IndyOutputContro;/* '<S85>/IND_Output_Control_Function_Flow_Graph' */
} DW_IND_Output_Control_Functio_T;

/* Block states (default storage) for system '<S85>/WPC_IND_Output_Control_Function' */
typedef struct {
  uint8 is_active_c343_IndyOutputContro;/* '<S85>/WPC_IND_Output_Control_Function' */
} DW_WPC_IND_Output_Control_Fun_T;

/* Block states (default storage) for system '<S133>/Bright_Max_Value_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c356_IndyOutputContro;/* '<S133>/Bright_Max_Value_Control_Function_Flow_Graph' */
} DW_Bright_Max_Value_Control_n_T;

/* Block states (default storage) for system '<S37>/Bright_Max_Value_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c415_IndyOutputContro;/* '<S37>/Bright_Max_Value_Control_Function_Flow_Graph' */
} DW_Bright_Max_Value_Control_c_T;

/* Block states (default storage) for system '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
typedef struct {
  uint8 is_active_c420_IndyOutputContro;/* '<S37>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
} DW_WPC_IND_Output_With_Auto_B_T;

/* Block states (default storage) for system '<S267>/FadeOut' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S281>/Delay Input2' */
  uint32 FadeOut_ELAPS_T;              /* '<S267>/FadeOut' */
  uint32 FadeOut_PREV_T;               /* '<S267>/FadeOut' */
  uint16 DelayInput1_DSTATE;           /* '<S277>/Delay Input1' */
  boolean FadeOut_RESET_ELAPS_T;       /* '<S267>/FadeOut' */
} DW_FadeOut_App_Model_f_T;

/* Block signals for system '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass_m;                      /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_j;         /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S274>/Switch1' */
  uint16 Switch2;                      /* '<S273>/Switch2' */
  sint8 Trigger;                       /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger_FO;                    /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Amber_IND_with_Animation__m_T;

/* Block states (default storage) for system '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c345_IndyOutputContro;/* '<S265>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut_App_Model_f_T FadeOut;    /* '<S267>/FadeOut' */
  DW_FadeIn_App_Model_T FadeIn;        /* '<S267>/FadeIn' */
} DW_Amber_IND_with_Animation_l_T;

/* Block states (default storage) for system '<S270>/FadeOut3' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S311>/Delay Input2' */
  uint32 FadeOut3_ELAPS_T;             /* '<S270>/FadeOut3' */
  uint32 FadeOut3_PREV_T;              /* '<S270>/FadeOut3' */
  uint16 DelayInput1_DSTATE;           /* '<S307>/Delay Input1' */
  boolean FadeOut3_RESET_ELAPS_T;      /* '<S270>/FadeOut3' */
} DW_FadeOut3_App_Model_i_T;

/* Block signals for system '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass1_n;                     /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2_l;                     /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3_m;                     /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_h;         /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_m;         /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_p;         /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_p;                   /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_e;         /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_pp;        /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_h;                   /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S288>/Switch1' */
  uint16 Switch2;                      /* '<S285>/Switch2' */
  uint16 Switch1_m;                    /* '<S287>/Switch1' */
  uint16 Switch2_l;                    /* '<S284>/Switch2' */
  uint16 Switch1_h;                    /* '<S286>/Switch1' */
  uint16 Switch2_k;                    /* '<S283>/Switch2' */
  sint8 Trigger1;                      /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger1_FO;                   /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2;                      /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2_FO;                   /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3;                      /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3_FO;                   /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Green_IND_with_Animation__n_T;

/* Block states (default storage) for system '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c349_IndyOutputContro;/* '<S265>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut3_App_Model_i_T FadeOut3;  /* '<S270>/FadeOut3' */
  DW_FadeIn3_App_Model_T FadeIn3;      /* '<S270>/FadeIn3' */
  DW_FadeOut2_App_Model_T FadeOut2;    /* '<S270>/FadeOut2' */
  DW_FadeIn2_App_Model_T FadeIn2;      /* '<S270>/FadeIn2' */
  DW_FadeOut1_App_Model_T FadeOut1;    /* '<S270>/FadeOut1' */
  DW_FadeIn1_App_Model_T FadeIn1;      /* '<S270>/FadeIn1' */
} DW_Green_IND_with_Animation_e_T;

/* Block states (default storage) for system '<S265>/IND_Output_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c351_IndyOutputContro;/* '<S265>/IND_Output_Control_Function_Flow_Graph' */
} DW_IND_Output_Control_Funct_p_T;

extern void Amber_IND_Control_Function_Init(uint16 *rty_Var_AmberIND);
extern void Amber_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_AmberINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_AmberIND, DW_Amber_IND_Control_Function_T *localDW);
extern void App_Model_FadeIn_Reset(DW_FadeIn_App_Model_T *localDW);
extern void App_Model_FadeIn(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger, float64 rtu_pass, uint16 *rty_y_FadeIn, DW_FadeIn_App_Model_T *localDW);
extern void App_Model_FadeOut_Reset(DW_FadeOut_App_Model_T *localDW);
extern void App_Model_FadeOut_Enable(DW_FadeOut_App_Model_T *localDW);
extern void App_Model_FadeOut(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_T *localDW);
extern void Amber_IND_with_Animation_C_Init(uint16 *rty_Var_AmberINDwithAnimation);
extern void Amber_IND_with_Animation_Enable(DW_Amber_IND_with_Animation_C_T *localDW);
extern void Amber_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW);
extern void Bright_Max_Value_Control_F_Init(uint16 *rty_Var_BrightMaxValue);
extern void Bright_Max_Value_Control_Functi(Bool rtu_Input_DetentOut, RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue,
  DW_Bright_Max_Value_Control_F_T *localDW);
extern void Green_IND_Control_Function_Init(uint16 *rty_Var_GreenIND);
extern void Green_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_GreenINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_GreenIND, DW_Green_IND_Control_Function_T *localDW);
extern void App_Model_FadeIn1_Reset(DW_FadeIn1_App_Model_T *localDW);
extern void App_Model_FadeIn1(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger1, float64 rtu_pass1, uint16 *rty_y_FadeIn1, DW_FadeIn1_App_Model_T *localDW);
extern void App_Model_FadeOut1_Reset(DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeOut1_Enable(DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeOut1(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger1_FO, float64 rtu_pass1, uint16 *rty_y_FadeOut1,
  DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeIn2_Reset(DW_FadeIn2_App_Model_T *localDW);
extern void App_Model_FadeIn2(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger2, float64 rtu_pass2, uint16 *rty_y_FadeIn2, DW_FadeIn2_App_Model_T *localDW);
extern void App_Model_FadeOut2_Reset(DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeOut2_Enable(DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeOut2(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger2_FO, float64 rtu_pass2, uint16 *rty_y_FadeOut2,
  DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeIn3_Reset(DW_FadeIn3_App_Model_T *localDW);
extern void App_Model_FadeIn3(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger3, float64 rtu_pass3, uint16 *rty_y_FadeIn3, DW_FadeIn3_App_Model_T *localDW);
extern void App_Model_FadeOut3_Reset(DW_FadeOut3_App_Model_T *localDW);
extern void App_Model_FadeOut3_Enable(DW_FadeOut3_App_Model_T *localDW);
extern void App_Model_FadeOut3(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_T *localDW);
extern void Green_IND_with_Animation_C_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3);
extern void Green_IND_with_Animation_Enable(DW_Green_IND_with_Animation_C_T *localDW);
extern void Green_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW);
extern void IND_Output_Control_Functio_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT);
extern void IND_Output_Control_Function_Flo(WPCIndCmdState rtu_Input_INT_WPCIndCmdState, WPCIndUSMState rtu_Var_INT_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Functio_T *localDW);
extern void WPC_IND_Output_Control_Fun_Init(uint16 *rty_RheoLevelValue);
extern void WPC_IND_Output_Control_Function(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue, DW_WPC_IND_Output_Control_Fun_T *localDW);
extern void Bright_Max_Value_Control_i_Init(uint16 *rty_Var_BrightMaxValue);
extern void Bright_Max_Value_Control_Func_b(RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue,
  DW_Bright_Max_Value_Control_n_T *localDW);
extern void Bright_Max_Value_Control_m_Init(uint16 *rty_Var_BrightMaxValue);
extern void Bright_Max_Value_Control_Func_n(Bool rtu_Input_DetentOut, uint16 rtu_AutoBrightValue, uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Control_c_T *localDW);
extern void WPC_IND_Output_With_Auto_B_Init(uint16 *rty_AutoBrightValue);
extern void WPC_IND_Output_With_Auto_Bright(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue, DW_WPC_IND_Output_With_Auto_B_T *localDW);
extern void App_Model_FadeOut_a_Reset(DW_FadeOut_App_Model_f_T *localDW);
extern void App_Model_FadeOut_a_Enable(DW_FadeOut_App_Model_f_T *localDW);
extern void App_Model_FadeOut_d(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_f_T *localDW);
extern void Amber_IND_with_Animation_l_Init(uint16 *rty_Var_AmberINDwithAnimation);
extern void Amber_IND_with_Animati_l_Enable(DW_Amber_IND_with_Animation_l_T *localDW);
extern void Amber_IND_with_Animation_Cont_m(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animation__m_T *localB, DW_Amber_IND_with_Animation_l_T *localDW);
extern void App_Model_FadeOut3_k_Reset(DW_FadeOut3_App_Model_i_T *localDW);
extern void App_Model_FadeOut3_b_Enable(DW_FadeOut3_App_Model_i_T *localDW);
extern void App_Model_FadeOut3_i(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_i_T *localDW);
extern void Green_IND_with_Animation_m_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3);
extern void Green_IND_with_Animati_k_Enable(DW_Green_IND_with_Animation_e_T *localDW);
extern void Green_IND_with_Animation_Cont_e(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16
  *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animation__n_T *localB, DW_Green_IND_with_Animation_e_T *localDW);
extern void IND_Output_Control_Funct_p_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT);
extern void IND_Output_Control_Function_F_k(WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, WPCIndUSMState rtu_Input_C_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Funct_p_T *localDW);
extern void IndyOutputControl_Function_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_j, uint16 *rty_IndyOutput_Sig_i, uint16 *rty_IndyOutput_Sig_d);
extern void IndyOutputControl_Funct_Disable(void);
extern void App__IndyOutputControl_Function(INDContType rtu_PostProcessIn, Bool rtu_PostProcessIn_j, Bool rtu_PostProcessIn_i, WPCIndCmdState rtu_PostProcessIn_d, Bool rtu_PostProcessIn_f,
  RheostatOption rtu_PostProcessIn_k, Bool rtu_PostProcessIn_jn, Bool rtu_PostProcessIn_p, WPCIndUSMState rtu_PostProcessIn_dz, C_RheoStatLevel rtu_PostProcessIn_o, C_AutoBrightLevel
  rtu_PostProcessIn_b, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_j, uint16 *rty_IndyOutput_Sig_i, uint16 *rty_IndyOutput_Sig_d);
extern void IndyOutputControl_Functi_d_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_g, uint16 *rty_IndyOutput_Sig_l, uint16 *rty_IndyOutput_Sig_m);
extern void IndyOutputControl_Fun_e_Disable(void);
extern void Ap_IndyOutputControl_Function_n(INDContType rtu_PostProcessIn, Bool rtu_PostProcessIn_g, Bool rtu_PostProcessIn_l, WPC2IndCmdState rtu_PostProcessIn_m, Bool rtu_PostProcessIn_f,
  RheostatOption rtu_PostProcessIn_k, Bool rtu_PostProcessIn_b, Bool rtu_PostProcessIn_mk, WPCIndUSMState rtu_PostProcessIn_fg, C_RheoStatLevel rtu_PostProcessIn_j, C_AutoBrightLevel
  rtu_PostProcessIn_c, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_g, uint16 *rty_IndyOutput_Sig_l, uint16 *rty_IndyOutput_Sig_m);

#endif                                 /* RTW_HEADER_IndyOutputControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
