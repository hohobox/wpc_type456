/*
 * File: IndyOutputControl_Function.h
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

#ifndef RTW_HEADER_IndyOutputControl_Function_h_
#define RTW_HEADER_IndyOutputControl_Function_h_
#ifndef App_Model_COMMON_INCLUDES_
#define App_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_App_Model.h"
#endif                                 /* App_Model_COMMON_INCLUDES_ */

#include "App_Model_types.h"

/* Block states (default storage) for system '<S93>/Amber_IND_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c323_IndyOutputContro;/* '<S93>/Amber_IND_Control_Function_Flow_Graph' */
} DW_Amber_IND_Control_Function_T;

/* Block states (default storage) for system '<S95>/FadeIn' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S103>/Delay Input1' */
  float64 UnitDelay_DSTATE;            /* '<S101>/Unit Delay' */
} DW_FadeIn_App_Model_T;

/* Block states (default storage) for system '<S95>/FadeOut' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S109>/Delay Input2' */
  uint32 FadeOut_ELAPS_T[2];           /* '<S95>/FadeOut' */
  uint32 FadeOut_PREV_T[2];            /* '<S95>/FadeOut' */
  uint16 DelayInput1_DSTATE;           /* '<S105>/Delay Input1' */
  boolean FadeOut_RESET_ELAPS_T;       /* '<S95>/FadeOut' */
} DW_FadeOut_App_Model_T;

/* Block signals for system '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass_ckkq;                   /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_gb0o;      /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S102>/Switch1' */
  uint16 Switch2;                      /* '<S101>/Switch2' */
  sint8 Trigger;                       /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger_FO;                    /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Amber_IND_with_Animation_Co_T;

/* Block states (default storage) for system '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c425_IndyOutputContro;/* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut_App_Model_T FadeOut;      /* '<S95>/FadeOut' */
  DW_FadeIn_App_Model_T FadeIn;        /* '<S95>/FadeIn' */
} DW_Amber_IND_with_Animation_C_T;

/* Block states (default storage) for system '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c333_IndyOutputContro;/* '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
} DW_Bright_Max_Value_Control_F_T;

/* Block states (default storage) for system '<S93>/Green_IND_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c337_IndyOutputContro;/* '<S93>/Green_IND_Control_Function_Flow_Graph' */
} DW_Green_IND_Control_Function_T;

/* Block states (default storage) for system '<S98>/FadeIn1' */
typedef struct {
  float64 UnitDelay_DSTATE;            /* '<S111>/Unit Delay' */
  float64 DelayInput1_DSTATE;          /* '<S117>/Delay Input1' */
} DW_FadeIn1_App_Model_T;

/* Block states (default storage) for system '<S98>/FadeOut1' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S127>/Delay Input2' */
  uint32 FadeOut1_ELAPS_T[2];          /* '<S98>/FadeOut1' */
  uint32 FadeOut1_PREV_T[2];           /* '<S98>/FadeOut1' */
  uint16 DelayInput1_DSTATE;           /* '<S123>/Delay Input1' */
  boolean FadeOut1_RESET_ELAPS_T;      /* '<S98>/FadeOut1' */
} DW_FadeOut1_App_Model_T;

/* Block states (default storage) for system '<S98>/FadeIn2' */
typedef struct {
  float64 UnitDelay_DSTATE;            /* '<S112>/Unit Delay' */
  float64 DelayInput1_DSTATE;          /* '<S119>/Delay Input1' */
} DW_FadeIn2_App_Model_T;

/* Block states (default storage) for system '<S98>/FadeOut2' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S133>/Delay Input2' */
  uint32 FadeOut2_ELAPS_T[2];          /* '<S98>/FadeOut2' */
  uint32 FadeOut2_PREV_T[2];           /* '<S98>/FadeOut2' */
  uint16 DelayInput1_DSTATE;           /* '<S129>/Delay Input1' */
  boolean FadeOut2_RESET_ELAPS_T;      /* '<S98>/FadeOut2' */
} DW_FadeOut2_App_Model_T;

/* Block states (default storage) for system '<S98>/FadeIn3' */
typedef struct {
  float64 UnitDelay_DSTATE;            /* '<S113>/Unit Delay' */
  float64 DelayInput1_DSTATE;          /* '<S121>/Delay Input1' */
} DW_FadeIn3_App_Model_T;

/* Block states (default storage) for system '<S98>/FadeOut3' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S139>/Delay Input2' */
  uint32 FadeOut3_ELAPS_T[2];          /* '<S98>/FadeOut3' */
  uint32 FadeOut3_PREV_T[2];           /* '<S98>/FadeOut3' */
  uint16 DelayInput1_DSTATE;           /* '<S135>/Delay Input1' */
  boolean FadeOut3_RESET_ELAPS_T;      /* '<S98>/FadeOut3' */
} DW_FadeOut3_App_Model_T;

/* Block signals for system '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass1_fccy;                  /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2_a01e;                  /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3_j1af;                  /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_pd5c;      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_pwkg;      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_agl2;      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_f2d1;                /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_cemj;      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_g0z4;      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_j1fr;                /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S116>/Switch1' */
  uint16 Switch2;                      /* '<S113>/Switch2' */
  uint16 Switch1_dv4w;                 /* '<S115>/Switch1' */
  uint16 Switch2_gauv;                 /* '<S112>/Switch2' */
  uint16 Switch1_odey;                 /* '<S114>/Switch1' */
  uint16 Switch2_cs5u;                 /* '<S111>/Switch2' */
  sint8 Trigger1;                      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger1_FO;                   /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2;                      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2_FO;                   /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3;                      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3_FO;                   /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Green_IND_with_Animation_Co_T;

/* Block states (default storage) for system '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c427_IndyOutputContro;/* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut3_App_Model_T FadeOut3;    /* '<S98>/FadeOut3' */
  DW_FadeIn3_App_Model_T FadeIn3;      /* '<S98>/FadeIn3' */
  DW_FadeOut2_App_Model_T FadeOut2;    /* '<S98>/FadeOut2' */
  DW_FadeIn2_App_Model_T FadeIn2;      /* '<S98>/FadeIn2' */
  DW_FadeOut1_App_Model_T FadeOut1;    /* '<S98>/FadeOut1' */
  DW_FadeIn1_App_Model_T FadeIn1;      /* '<S98>/FadeIn1' */
} DW_Green_IND_with_Animation_C_T;

/* Block states (default storage) for system '<S93>/IND_Output_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c428_IndyOutputContro;/* '<S93>/IND_Output_Control_Function_Flow_Graph' */
} DW_IND_Output_Control_Functio_T;

/* Block states (default storage) for system '<S93>/WPC_IND_Output_Control_Function' */
typedef struct {
  uint8 is_active_c343_IndyOutputContro;/* '<S93>/WPC_IND_Output_Control_Function' */
} DW_WPC_IND_Output_Control_Fun_T;

/* Block signals for system '<S28>/RheoStatIndyOutputControl_Type1' */
typedef struct {
  uint16 RheoLevelValue;               /* '<S93>/WPC_IND_Output_Control_Function' */
  uint16 Var_GreenINDwithAnimation1;   /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_GreenINDwithAnimation2;   /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_GreenINDwithAnimation3;   /* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
  uint16 Var_AmberINDwithAnimation;    /* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  B_Green_IND_with_Animation_Co_T sf_Green_IND_with_Animation_Con;/* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  B_Amber_IND_with_Animation_Co_T sf_Amber_IND_with_Animation_Con;/* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_RheoStatIndyOutputControl_T_T;

/* Block states (default storage) for system '<S28>/RheoStatIndyOutputControl_Type1' */
typedef struct {
  DW_WPC_IND_Output_Control_Fun_T sf_WPC_IND_Output_Control_Funct;/* '<S93>/WPC_IND_Output_Control_Function' */
  DW_IND_Output_Control_Functio_T sf_IND_Output_Control_Function_;/* '<S93>/IND_Output_Control_Function_Flow_Graph' */
  DW_Green_IND_with_Animation_C_T sf_Green_IND_with_Animation_Con;/* '<S93>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_Green_IND_Control_Function_T sf_Green_IND_Control_Function_F;/* '<S93>/Green_IND_Control_Function_Flow_Graph' */
  DW_Bright_Max_Value_Control_F_T sf_Bright_Max_Value_Control_Fun;/* '<S93>/Bright_Max_Value_Control_Function_Flow_Graph' */
  DW_Amber_IND_with_Animation_C_T sf_Amber_IND_with_Animation_Con;/* '<S93>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_Amber_IND_Control_Function_T sf_Amber_IND_Control_Function_F;/* '<S93>/Amber_IND_Control_Function_Flow_Graph' */
} DW_RheoStatIndyOutputControl__T;

/* Block states (default storage) for system '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c356_IndyOutputContro;/* '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
} DW_Bright_Max_Value_Cont_nvtj_T;

/* Block signals for system '<S28>/RheoStatIndyOutputControl_Type2' */
typedef struct {
  uint16 RheoLevelValue;               /* '<S141>/WPC_IND_Output_Control_Function' */
  uint16 Var_GreenINDwithAnimation1;   /* '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_GreenINDwithAnimation2;   /* '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_GreenINDwithAnimation3;   /* '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
  uint16 Var_AmberINDwithAnimation;    /* '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  B_Green_IND_with_Animation_Co_T sf_Green_IND_with_Animation_Con;/* '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  B_Amber_IND_with_Animation_Co_T sf_Amber_IND_with_Animation_Con;/* '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_RheoStatIndyOutputCont_h4yx_T;

/* Block states (default storage) for system '<S28>/RheoStatIndyOutputControl_Type2' */
typedef struct {
  DW_WPC_IND_Output_Control_Fun_T sf_WPC_IND_Output_Control_Funct;/* '<S141>/WPC_IND_Output_Control_Function' */
  DW_IND_Output_Control_Functio_T sf_IND_Output_Control_Function_;/* '<S141>/IND_Output_Control_Function_Flow_Graph' */
  DW_Green_IND_with_Animation_C_T sf_Green_IND_with_Animation_Con;/* '<S141>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_Green_IND_Control_Function_T sf_Green_IND_Control_Function_F;/* '<S141>/Green_IND_Control_Function_Flow_Graph' */
  DW_Bright_Max_Value_Cont_nvtj_T sf_Bright_Max_Value_Control_Fun;/* '<S141>/Bright_Max_Value_Control_Function_Flow_Graph' */
  DW_Amber_IND_with_Animation_C_T sf_Amber_IND_with_Animation_Con;/* '<S141>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_Amber_IND_Control_Function_T sf_Amber_IND_Control_Function_F;/* '<S141>/Amber_IND_Control_Function_Flow_Graph' */
} DW_RheoStatIndyOutputCon_gpfz_T;

/* Block states (default storage) for system '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c415_IndyOutputContro;/* '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
} DW_Bright_Max_Value_Cont_cwb0_T;

/* Block states (default storage) for system '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
typedef struct {
  uint8 is_active_c420_IndyOutputContro;/* '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
} DW_WPC_IND_Output_With_Auto_B_T;

/* Block signals for system '<S28>/AutoBrightIndyOutputControl_Type3' */
typedef struct {
  uint16 AutoBrightValue;              /* '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  uint16 Var_GreenINDwithAnimation1;   /* '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_GreenINDwithAnimation2;   /* '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_GreenINDwithAnimation3;   /* '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
  uint16 Var_AmberINDwithAnimation;    /* '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  B_Green_IND_with_Animation_Co_T sf_Green_IND_with_Animation_Con;/* '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  B_Amber_IND_with_Animation_Co_T sf_Amber_IND_with_Animation_Con;/* '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_AutoBrightIndyOutputControl_T;

/* Block states (default storage) for system '<S28>/AutoBrightIndyOutputControl_Type3' */
typedef struct {
  uint8 is_active_c419_IndyOutputContro;/* '<S45>/IND_Output_Control_Function_Flow_Graph' */
  DW_WPC_IND_Output_With_Auto_B_T sf_WPC_IND_Output_With_Auto_Bri;/* '<S45>/WPC_IND_Output_With_Auto_Bright_Control_Function' */
  DW_Green_IND_with_Animation_C_T sf_Green_IND_with_Animation_Con;/* '<S45>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_Green_IND_Control_Function_T sf_Green_IND_Control_Function_F;/* '<S45>/Green_IND_Control_Function_Flow_Graph' */
  DW_Bright_Max_Value_Cont_cwb0_T sf_Bright_Max_Value_Control_Fun;/* '<S45>/Bright_Max_Value_Control_Function_Flow_Graph' */
  DW_Amber_IND_with_Animation_C_T sf_Amber_IND_with_Animation_Con;/* '<S45>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_Amber_IND_Control_Function_T sf_Amber_IND_Control_Function_F;/* '<S45>/Amber_IND_Control_Function_Flow_Graph' */
} DW_AutoBrightIndyOutputContro_T;

/* Block states (default storage) for system '<S285>/FadeOut' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S299>/Delay Input2' */
  uint32 FadeOut_ELAPS_T[2];           /* '<S285>/FadeOut' */
  uint32 FadeOut_PREV_T[2];            /* '<S285>/FadeOut' */
  uint16 DelayInput1_DSTATE;           /* '<S295>/Delay Input1' */
  boolean FadeOut_RESET_ELAPS_T;       /* '<S285>/FadeOut' */
} DW_FadeOut_App_Model_f2o5_T;

/* Block signals for system '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass_m4he;                   /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_jldw;      /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S292>/Switch1' */
  uint16 Switch2;                      /* '<S291>/Switch2' */
  sint8 Trigger;                       /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger_FO;                    /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Amber_IND_with_Animati_m1ud_T;

/* Block states (default storage) for system '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass;                        /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c345_IndyOutputContro;/* '<S283>/Amber_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut_App_Model_f2o5_T FadeOut; /* '<S285>/FadeOut' */
  DW_FadeIn_App_Model_T FadeIn;        /* '<S285>/FadeIn' */
} DW_Amber_IND_with_Animat_lfth_T;

/* Block states (default storage) for system '<S288>/FadeOut3' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S329>/Delay Input2' */
  uint32 FadeOut3_ELAPS_T[2];          /* '<S288>/FadeOut3' */
  uint32 FadeOut3_PREV_T[2];           /* '<S288>/FadeOut3' */
  uint16 DelayInput1_DSTATE;           /* '<S325>/Delay Input1' */
  boolean FadeOut3_RESET_ELAPS_T;      /* '<S288>/FadeOut3' */
} DW_FadeOut3_App_Model_icri_T;

/* Block signals for system '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass1_nzqq;                  /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2_l0mx;                  /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3_ms0p;                  /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue;           /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_hgto;      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue;                     /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_mmam;      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_pkpq;      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_p1ys;                /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_erul;      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_ppql;      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 preValue_hdix;                /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Switch1;                      /* '<S306>/Switch1' */
  uint16 Switch2;                      /* '<S303>/Switch2' */
  uint16 Switch1_mhph;                 /* '<S305>/Switch1' */
  uint16 Switch2_lswb;                 /* '<S302>/Switch2' */
  uint16 Switch1_hri5;                 /* '<S304>/Switch1' */
  uint16 Switch2_kpl0;                 /* '<S301>/Switch2' */
  sint8 Trigger1;                      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger1_FO;                   /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2;                      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger2_FO;                   /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3;                      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  sint8 Trigger3_FO;                   /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
} B_Green_IND_with_Animati_nvy5_T;

/* Block states (default storage) for system '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
typedef struct {
  float64 pass1;                       /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass2;                       /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  float64 pass3;                       /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_prev;      /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint16 Var_BrightMaxValue_start;     /* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  uint8 is_active_c349_IndyOutputContro;/* '<S283>/Green_IND_with_Animation_Control_Function_Flow_Graph_Mix' */
  DW_FadeOut3_App_Model_icri_T FadeOut3;/* '<S288>/FadeOut3' */
  DW_FadeIn3_App_Model_T FadeIn3;      /* '<S288>/FadeIn3' */
  DW_FadeOut2_App_Model_T FadeOut2;    /* '<S288>/FadeOut2' */
  DW_FadeIn2_App_Model_T FadeIn2;      /* '<S288>/FadeIn2' */
  DW_FadeOut1_App_Model_T FadeOut1;    /* '<S288>/FadeOut1' */
  DW_FadeIn1_App_Model_T FadeIn1;      /* '<S288>/FadeIn1' */
} DW_Green_IND_with_Animat_eu5k_T;

/* Block states (default storage) for system '<S283>/IND_Output_Control_Function_Flow_Graph' */
typedef struct {
  uint8 is_active_c351_IndyOutputContro;/* '<S283>/IND_Output_Control_Function_Flow_Graph' */
} DW_IND_Output_Control_Fu_pb2o_T;

/* Block states (default storage) for system '<S523>/FadeIn' */
typedef struct {
  float64 UnitDelay3_DSTATE;           /* '<S529>/Unit Delay3' */
  float64 DelayInput1_DSTATE;          /* '<S531>/Delay Input1' */
} DW_FadeIn_App_Model_prxo_T;

/* Block states (default storage) for system '<S523>/FadeOut' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S533>/Delay Input1' */
  float64 UnitDelay_DSTATE;            /* '<S530>/Unit Delay' */
} DW_FadeOut_App_Model_m1tn_T;

/* Block signals for system '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
typedef struct {
  float64 pass;                        /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass_n2fm;                   /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue;           /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_bq5h;      /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 preValue;                     /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 DataTypeConversion9;          /* '<S530>/Data Type Conversion9' */
  uint16 Switch2;                      /* '<S529>/Switch2' */
  sint8 Trigger;                       /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  sint8 Trigger_FO;                    /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
} B_Amber_IND_with_Animati_atgr_T;

/* Block states (default storage) for system '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
typedef struct {
  float64 pass;                        /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_prev;      /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_start;     /* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  uint8 is_active_c436_IndyOutputContro;/* '<S521>/Amber_IND_with_Animation_Control_Function_Flow_Graph' */
  DW_FadeOut_App_Model_m1tn_T FadeOut; /* '<S523>/FadeOut' */
  DW_FadeIn_App_Model_prxo_T FadeIn;   /* '<S523>/FadeIn' */
} DW_Amber_IND_with_Animat_pevs_T;

/* Block states (default storage) for system '<S526>/FadeIn1' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S541>/Delay Input1' */
  float64 UnitDelay3_DSTATE;           /* '<S535>/Unit Delay3' */
} DW_FadeIn1_App_Model_b0rw_T;

/* Block states (default storage) for system '<S526>/FadeOut1' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S547>/Delay Input2' */
  uint32 FadeOut1_ELAPS_T[2];          /* '<S526>/FadeOut1' */
  uint32 FadeOut1_PREV_T[2];           /* '<S526>/FadeOut1' */
  boolean FadeOut1_RESET_ELAPS_T;      /* '<S526>/FadeOut1' */
} DW_FadeOut1_App_Model_pelm_T;

/* Block states (default storage) for system '<S526>/FadeIn2' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S543>/Delay Input1' */
  float64 UnitDelay3_DSTATE;           /* '<S536>/Unit Delay3' */
} DW_FadeIn2_App_Model_ph3h_T;

/* Block states (default storage) for system '<S526>/FadeOut2' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S550>/Delay Input2' */
  uint32 FadeOut2_ELAPS_T[2];          /* '<S526>/FadeOut2' */
  uint32 FadeOut2_PREV_T[2];           /* '<S526>/FadeOut2' */
  boolean FadeOut2_RESET_ELAPS_T;      /* '<S526>/FadeOut2' */
} DW_FadeOut2_App_Model_bhad_T;

/* Block states (default storage) for system '<S526>/FadeIn3' */
typedef struct {
  float64 DelayInput1_DSTATE;          /* '<S545>/Delay Input1' */
  float64 UnitDelay3_DSTATE;           /* '<S537>/Unit Delay3' */
} DW_FadeIn3_App_Model_bxni_T;

/* Block states (default storage) for system '<S526>/FadeOut3' */
typedef struct {
  float64 DelayInput2_DSTATE;          /* '<S553>/Delay Input2' */
  uint32 FadeOut3_ELAPS_T[2];          /* '<S526>/FadeOut3' */
  uint32 FadeOut3_PREV_T[2];           /* '<S526>/FadeOut3' */
  boolean FadeOut3_RESET_ELAPS_T;      /* '<S526>/FadeOut3' */
} DW_FadeOut3_App_Model_hstr_T;

/* Block signals for system '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
typedef struct {
  float64 pass1;                       /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass1_ijju;                  /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass2;                       /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass2_pugk;                  /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass3;                       /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass3_gtdo;                  /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue;           /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_bbx1;      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 preValue;                     /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_eerv;      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_ihru;      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 preValue_kulh;                /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_dv1t;      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_ezuy;      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 preValue_mb0b;                /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 DataTypeConversion4;          /* '<S540>/Data Type Conversion4' */
  uint16 Switch2;                      /* '<S537>/Switch2' */
  uint16 DataTypeConversion4_idq1;     /* '<S539>/Data Type Conversion4' */
  uint16 Switch2_acm4;                 /* '<S536>/Switch2' */
  uint16 DataTypeConversion4_lorm;     /* '<S538>/Data Type Conversion4' */
  uint16 Switch2_mawl;                 /* '<S535>/Switch2' */
  sint8 Trigger1;                      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  sint8 Trigger1_FO;                   /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  sint8 Trigger2;                      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  sint8 Trigger2_FO;                   /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  sint8 Trigger3;                      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  sint8 Trigger3_FO;                   /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
} B_Green_IND_with_Animati_mn3u_T;

/* Block states (default storage) for system '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
typedef struct {
  float64 pass1;                       /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass2;                       /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  float64 pass3;                       /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_prev;      /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint16 Var_BrightMaxValue_start;     /* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  uint8 is_active_c439_IndyOutputContro;/* '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
  DW_FadeOut3_App_Model_hstr_T FadeOut3;/* '<S526>/FadeOut3' */
  DW_FadeIn3_App_Model_bxni_T FadeIn3; /* '<S526>/FadeIn3' */
  DW_FadeOut2_App_Model_bhad_T FadeOut2;/* '<S526>/FadeOut2' */
  DW_FadeIn2_App_Model_ph3h_T FadeIn2; /* '<S526>/FadeIn2' */
  DW_FadeOut1_App_Model_pelm_T FadeOut1;/* '<S526>/FadeOut1' */
  DW_FadeIn1_App_Model_b0rw_T FadeIn1; /* '<S526>/FadeIn1' */
} DW_Green_IND_with_Animat_pmuj_T;

/* Invariant block signals for system '<S526>/FadeOut1' */
typedef struct {
  const float64 DataTypeConversion5;   /* '<S538>/Data Type Conversion5' */
} ConstB_FadeOut1_App_Mode_lif3_T;

/* Invariant block signals for system '<S526>/FadeOut2' */
typedef struct {
  const float64 DataTypeConversion5;   /* '<S539>/Data Type Conversion5' */
} ConstB_FadeOut2_App_Mode_g3pr_T;

/* Invariant block signals for system '<S526>/FadeOut3' */
typedef struct {
  const float64 DataTypeConversion5;   /* '<S540>/Data Type Conversion5' */
} ConstB_FadeOut3_App_Mode_n4dx_T;

/* Invariant block signals for system '<S521>/Green_IND_with_Animation_Control_Function_Flow_Graph' */
typedef struct {
  ConstB_FadeOut3_App_Mode_n4dx_T FadeOut3;/* '<S526>/FadeOut3' */
  ConstB_FadeOut2_App_Mode_g3pr_T FadeOut2;/* '<S526>/FadeOut2' */
  ConstB_FadeOut1_App_Mode_lif3_T FadeOut1;/* '<S526>/FadeOut1' */
} ConstB_Green_IND_with_An_nczp_T;

extern void Amber_IND_Control_Function_Init(uint16 *rty_Var_AmberIND, DW_Amber_IND_Control_Function_T *localDW);
extern void Amber_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_AmberINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_AmberIND, DW_Amber_IND_Control_Function_T *localDW);
extern void App_Model_FadeIn_Init(DW_FadeIn_App_Model_T *localDW);
extern void App_Model_FadeIn_Reset(DW_FadeIn_App_Model_T *localDW);
extern void App_Model_FadeIn(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger, float64 rtu_pass, uint16 *rty_y_FadeIn, DW_FadeIn_App_Model_T *localDW);
extern void App_Model_FadeOut_Init(DW_FadeOut_App_Model_T *localDW);
extern void App_Model_FadeOut_Reset(DW_FadeOut_App_Model_T *localDW);
extern void App_Model_FadeOut_Enable(DW_FadeOut_App_Model_T *localDW);
extern void App_Model_FadeOut(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_T *localDW);
extern void Amber_IND_with_Animation_C_Init(uint16 *rty_Var_AmberINDwithAnimation, DW_Amber_IND_with_Animation_C_T *localDW);
extern void Amber_IND_with_Animation_Enable(DW_Amber_IND_with_Animation_C_T *localDW);
extern void Amber_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animation_Co_T *localB, DW_Amber_IND_with_Animation_C_T *localDW);
extern void Bright_Max_Value_Control_F_Init(uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Control_F_T *localDW);
extern void Bright_Max_Value_Control_Functi(Bool rtu_Input_DetentOut, RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue,
  DW_Bright_Max_Value_Control_F_T *localDW);
extern void Green_IND_Control_Function_Init(uint16 *rty_Var_GreenIND, DW_Green_IND_Control_Function_T *localDW);
extern void Green_IND_Control_Function_Flow(Bool rtu_Input_OPT_b_GreenINDCmd, uint16 rtu_Var_BrightMaxValue, uint16 *rty_Var_GreenIND, DW_Green_IND_Control_Function_T *localDW);
extern void App_Model_FadeIn1_Init(DW_FadeIn1_App_Model_T *localDW);
extern void App_Model_FadeIn1_Reset(DW_FadeIn1_App_Model_T *localDW);
extern void App_Model_FadeIn1(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger1, float64 rtu_pass1, uint16 *rty_y_FadeIn1, DW_FadeIn1_App_Model_T *localDW);
extern void App_Model_FadeOut1_Init(DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeOut1_Reset(DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeOut1_Enable(DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeOut1(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger1_FO, float64 rtu_pass1, uint16 *rty_y_FadeOut1,
  DW_FadeOut1_App_Model_T *localDW);
extern void App_Model_FadeIn2_Init(DW_FadeIn2_App_Model_T *localDW);
extern void App_Model_FadeIn2_Reset(DW_FadeIn2_App_Model_T *localDW);
extern void App_Model_FadeIn2(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger2, float64 rtu_pass2, uint16 *rty_y_FadeIn2, DW_FadeIn2_App_Model_T *localDW);
extern void App_Model_FadeOut2_Init(DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeOut2_Reset(DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeOut2_Enable(DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeOut2(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger2_FO, float64 rtu_pass2, uint16 *rty_y_FadeOut2,
  DW_FadeOut2_App_Model_T *localDW);
extern void App_Model_FadeIn3_Init(DW_FadeIn3_App_Model_T *localDW);
extern void App_Model_FadeIn3_Reset(DW_FadeIn3_App_Model_T *localDW);
extern void App_Model_FadeIn3(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger3, float64 rtu_pass3, uint16 *rty_y_FadeIn3, DW_FadeIn3_App_Model_T *localDW);
extern void App_Model_FadeOut3_Init(DW_FadeOut3_App_Model_T *localDW);
extern void App_Model_FadeOut3_Reset(DW_FadeOut3_App_Model_T *localDW);
extern void App_Model_FadeOut3_Enable(DW_FadeOut3_App_Model_T *localDW);
extern void App_Model_FadeOut3(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_T *localDW);
extern void Green_IND_with_Animation_C_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, DW_Green_IND_with_Animation_C_T
  *localDW);
extern void Green_IND_with_Animation_Enable(DW_Green_IND_with_Animation_C_T *localDW);
extern void Green_IND_with_Animation_Contro(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPCIndCmdState rtu_Input_INT_WPCIndCmdState, uint16 *rty_Var_GreenINDwithAnimation1,
  uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animation_Co_T *localB, DW_Green_IND_with_Animation_C_T *localDW);
extern void IND_Output_Control_Functio_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT,
  DW_IND_Output_Control_Functio_T *localDW);
extern void IND_Output_Control_Function_Flo(WPCIndCmdState rtu_Input_INT_WPCIndCmdState, WPCIndUSMState rtu_Var_INT_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Functio_T *localDW);
extern void WPC_IND_Output_Control_Fun_Init(uint16 *rty_RheoLevelValue, DW_WPC_IND_Output_Control_Fun_T *localDW);
extern void WPC_IND_Output_Control_Function(C_RheoStatLevel rtu_Input_RheoStatLevel, uint16 *rty_RheoLevelValue, DW_WPC_IND_Output_Control_Fun_T *localDW);
extern void RheoStatIndyOutputControl__Init(B_RheoStatIndyOutputControl_T_T *localB, DW_RheoStatIndyOutputControl__T *localDW);
extern void RheoStatIndyOutputContro_Enable(DW_RheoStatIndyOutputControl__T *localDW);
extern void RheoStatIndyOutputControl_Type1(RT_MODEL_App_Model_T * const App_Model_M, WPCIndUSMState rtu_IND_WPCIndUSMState, RheostatOption rtu_C_RheostatOption, Bool rtu_C_b_IntTailOn, Bool
  rtu_C_DetentOut, C_RheoStatLevel rtu_C_RheoStatLevel, Bool rtu_b_GreenINDCmd, Bool rtu_b_AmberINDCmd, WPCIndCmdState rtu_INT_WPCIndCmdState, Bool rtu_b_SyncAmber, uint16 *rty_P_GreenIND_OUT, uint16 *
  rty_P_GreenIND2_OUT, uint16 *rty_P_GreenIND3_OUT, uint16 *rty_P_AmberIND_OUT, B_RheoStatIndyOutputControl_T_T *localB, DW_RheoStatIndyOutputControl__T *localDW);
extern void Bright_Max_Value_Cont_abam_Init(uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_nvtj_T *localDW);
extern void Bright_Max_Value_Control_F_bk5u(RheostatOption rtu_Input_RheostatOption, Bool rtu_Input_b_IntTailOn, uint16 rtu_RheoLevelValue, uint16 *rty_Var_BrightMaxValue,
  DW_Bright_Max_Value_Cont_nvtj_T *localDW);
extern void RheoStatIndyOutputCon_dc24_Init(B_RheoStatIndyOutputCont_h4yx_T *localB, DW_RheoStatIndyOutputCon_gpfz_T *localDW);
extern void RheoStatIndyOutputC_jyjj_Enable(DW_RheoStatIndyOutputCon_gpfz_T *localDW);
extern void RheoStatIndyOutputControl_Type2(RT_MODEL_App_Model_T * const App_Model_M, WPCIndUSMState rtu_IND_WPCIndUSMState, RheostatOption rtu_C_RheostatOption, Bool rtu_b_IntTailOn, C_RheoStatLevel
  rtu_C_RheoStatLevel, Bool rtu_b_GreenINDCmd, Bool rtu_b_AmberINDCmd, WPCIndCmdState rtu_INT_WPCIndCmdState, Bool rtu_b_SyncAmber, uint16 *rty_P_GreenIND_OUT, uint16 *rty_P_GreenIND2_OUT, uint16
  *rty_P_GreenIND3_OUT, uint16 *rty_P_AmberIND_OUT, B_RheoStatIndyOutputCont_h4yx_T *localB, DW_RheoStatIndyOutputCon_gpfz_T *localDW);
extern void Bright_Max_Value_Cont_issq_Init(uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_cwb0_T *localDW);
extern void Bright_Max_Value_Control_F_nqis(Bool rtu_Input_DetentOut, uint16 rtu_AutoBrightValue, uint16 *rty_Var_BrightMaxValue, DW_Bright_Max_Value_Cont_cwb0_T *localDW);
extern void WPC_IND_Output_With_Auto_B_Init(uint16 *rty_AutoBrightValue, DW_WPC_IND_Output_With_Auto_B_T *localDW);
extern void WPC_IND_Output_With_Auto_Bright(C_AutoBrightLevel rtu_Input_AutoBrightLevel, uint16 *rty_AutoBrightValue, DW_WPC_IND_Output_With_Auto_B_T *localDW);
extern void AutoBrightIndyOutputContro_Init(B_AutoBrightIndyOutputControl_T *localB, DW_AutoBrightIndyOutputContro_T *localDW);
extern void AutoBrightIndyOutputCont_Enable(DW_AutoBrightIndyOutputContro_T *localDW);
extern void AutoBrightIndyOutputControl_Typ(RT_MODEL_App_Model_T * const App_Model_M, WPCIndUSMState rtu_IND_WPCIndUSMState, C_AutoBrightLevel rtu_C_AutoBrightLevel, Bool rtu_C_DetentOut, Bool
  rtu_b_GreenINDCmd, Bool rtu_b_AmberINDCmd, WPCIndCmdState rtu_INT_WPCIndCmdState, Bool rtu_b_SyncAmber, uint16 *rty_P_GreenIND_OUT, uint16 *rty_P_GreenIND2_OUT, uint16 *rty_P_GreenIND3_OUT, uint16
  *rty_P_AmberIND_OUT, B_AutoBrightIndyOutputControl_T *localB, DW_AutoBrightIndyOutputContro_T *localDW);
extern void App_Model_FadeOut_ppnc_Init(DW_FadeOut_App_Model_f2o5_T *localDW);
extern void App_Model_FadeOut_adke_Reset(DW_FadeOut_App_Model_f2o5_T *localDW);
extern void App_Model_FadeOut_bcra_Enable(DW_FadeOut_App_Model_f2o5_T *localDW);
extern void App_Model_FadeOut_dxzi(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut,
  DW_FadeOut_App_Model_f2o5_T *localDW);
extern void Amber_IND_with_Animat_oufc_Init(uint16 *rty_Var_AmberINDwithAnimation, DW_Amber_IND_with_Animat_lfth_T *localDW);
extern void Amber_IND_with_Anim_cncj_Enable(DW_Amber_IND_with_Animat_lfth_T *localDW);
extern void Amber_IND_with_Animation_C_m52k(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16
  *rty_Var_AmberINDwithAnimation, B_Amber_IND_with_Animati_m1ud_T *localB, DW_Amber_IND_with_Animat_lfth_T *localDW);
extern void App_Model_FadeOut3_nmq3_Init(DW_FadeOut3_App_Model_icri_T *localDW);
extern void App_Model_FadeOut3_pmzl_Reset(DW_FadeOut3_App_Model_icri_T *localDW);
extern void App_Model_FadeOut3_l4ud_Enable(DW_FadeOut3_App_Model_icri_T *localDW);
extern void App_Model_FadeOut3_ig5d(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  DW_FadeOut3_App_Model_icri_T *localDW);
extern void Green_IND_with_Animat_mbvj_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, DW_Green_IND_with_Animat_eu5k_T
  *localDW);
extern void Green_IND_with_Anim_c1ni_Enable(DW_Green_IND_with_Animat_eu5k_T *localDW);
extern void Green_IND_with_Animation_C_eqpi(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, uint16
  *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animati_nvy5_T *localB, DW_Green_IND_with_Animat_eu5k_T *localDW);
extern void IND_Output_Control_Fu_bpei_Init(uint16 *rty_Output_AmberIND_OUT, uint16 *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT,
  DW_IND_Output_Control_Fu_pb2o_T *localDW);
extern void IND_Output_Control_Functio_kj3y(WPC2IndCmdState rtu_Input_INT_WPC2IndCmdState, WPCIndUSMState rtu_Input_C_WPCIndUSMState, uint16 rtu_Var_GreenIND, uint16 rtu_Var_AmberIND, uint16
  rtu_Var_GreenINDwithAnimation2, uint16 rtu_Var_GreenINDwithAnimation3, uint16 rtu_Var_GreenINDwithAnimation1, uint16 rtu_Var_AmberINDwithAnimation, uint16 *rty_Output_AmberIND_OUT, uint16
  *rty_Output_GreenIND_OUT, uint16 *rty_Output_GreenIND2_OUT, uint16 *rty_Output_GreenIND3_OUT, DW_IND_Output_Control_Fu_pb2o_T *localDW);
extern void App_Model_FadeIn_doz4_Init(DW_FadeIn_App_Model_prxo_T *localDW);
extern void App_Model_FadeIn_pvaj_Reset(DW_FadeIn_App_Model_prxo_T *localDW);
extern void App_Model_FadeIn_ptpu(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger, float64 rtu_pass, uint16 *rty_y_FadeIn, DW_FadeIn_App_Model_prxo_T *localDW);
extern void App_Model_FadeOut_dnmv_Init(DW_FadeOut_App_Model_m1tn_T *localDW);
extern void App_Model_FadeOut_hpxk_Reset(DW_FadeOut_App_Model_m1tn_T *localDW);
extern void App_Model_FadeOut_gvzk(uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger_FO, float64 rtu_pass, uint16 *rty_y_FadeOut, DW_FadeOut_App_Model_m1tn_T *localDW);
extern void Amber_IND_with_Animat_crfg_Init(uint16 *rty_Var_AmberINDwithAnimation, DW_Amber_IND_with_Animat_pevs_T *localDW);
extern void Amber_IND_with_Anim_ddyk_Enable(DW_Amber_IND_with_Animat_pevs_T *localDW);
extern void Amber_IND_with_Animation_C_lyja(uint16 rtu_Var_BrightMaxValue, Bool rtu_b_SyncAmber, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16 *rty_Var_AmberINDwithAnimation,
  B_Amber_IND_with_Animati_atgr_T *localB, DW_Amber_IND_with_Animat_pevs_T *localDW);
extern void App_Model_FadeIn1_keed_Init(DW_FadeIn1_App_Model_b0rw_T *localDW);
extern void App_Model_FadeIn1_ed0b_Reset(DW_FadeIn1_App_Model_b0rw_T *localDW);
extern void App_Model_FadeIn1_gjxk(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger1, float64 rtu_pass1, uint16 *rty_y_FadeIn1, DW_FadeIn1_App_Model_b0rw_T *localDW);
extern void App_Model_FadeOut1_c3qa_Init(DW_FadeOut1_App_Model_pelm_T *localDW);
extern void App_Model_FadeOut1_lxyd_Reset(DW_FadeOut1_App_Model_pelm_T *localDW);
extern void App_Model_FadeOut1_e32b_Enable(DW_FadeOut1_App_Model_pelm_T *localDW);
extern void App_Model_FadeOut1_cr24(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger1_FO, float64 rtu_pass1, uint16 *rty_y_FadeOut1,
  const ConstB_FadeOut1_App_Mode_lif3_T *localC, DW_FadeOut1_App_Model_pelm_T *localDW);
extern void App_Model_FadeIn2_kjhn_Init(DW_FadeIn2_App_Model_ph3h_T *localDW);
extern void App_Model_FadeIn2_d1tk_Reset(DW_FadeIn2_App_Model_ph3h_T *localDW);
extern void App_Model_FadeIn2_jdzr(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger2, float64 rtu_pass2, uint16 *rty_y_FadeIn2, DW_FadeIn2_App_Model_ph3h_T *localDW);
extern void App_Model_FadeOut2_mud4_Init(DW_FadeOut2_App_Model_bhad_T *localDW);
extern void App_Model_FadeOut2_jnvs_Reset(DW_FadeOut2_App_Model_bhad_T *localDW);
extern void App_Model_FadeOut2_lnni_Enable(DW_FadeOut2_App_Model_bhad_T *localDW);
extern void App_Model_FadeOut2_annl(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger2_FO, float64 rtu_pass2, uint16 *rty_y_FadeOut2,
  const ConstB_FadeOut2_App_Mode_g3pr_T *localC, DW_FadeOut2_App_Model_bhad_T *localDW);
extern void App_Model_FadeIn3_i1ka_Init(DW_FadeIn3_App_Model_bxni_T *localDW);
extern void App_Model_FadeIn3_hl4u_Reset(DW_FadeIn3_App_Model_bxni_T *localDW);
extern void App_Model_FadeIn3_kzku(uint16 rtu_Var_BrightMaxValue, sint8 rtu_Trigger3, float64 rtu_pass3, uint16 *rty_y_FadeIn3, DW_FadeIn3_App_Model_bxni_T *localDW);
extern void App_Model_FadeOut3_m2ax_Init(DW_FadeOut3_App_Model_hstr_T *localDW);
extern void App_Model_FadeOut3_dv1c_Reset(DW_FadeOut3_App_Model_hstr_T *localDW);
extern void App_Model_FadeOut3_gnna_Enable(DW_FadeOut3_App_Model_hstr_T *localDW);
extern void App_Model_FadeOut3_n4kz(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, uint16 rtu_preValue, sint8 rtu_Trigger3_FO, float64 rtu_pass3, uint16 *rty_y_FadeOut3,
  const ConstB_FadeOut3_App_Mode_n4dx_T *localC, DW_FadeOut3_App_Model_hstr_T *localDW);
extern void Green_IND_with_Animat_dqaz_Init(uint16 *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, DW_Green_IND_with_Animat_pmuj_T
  *localDW);
extern void Green_IND_with_Anim_cp3n_Enable(DW_Green_IND_with_Animat_pmuj_T *localDW);
extern void Green_IND_with_Animation_C_j0ur(RT_MODEL_App_Model_T * const App_Model_M, uint16 rtu_Var_BrightMaxValue, RWPCIndCmdState rtu_Input_INT_RWPCIndCmdState, uint16
  *rty_Var_GreenINDwithAnimation1, uint16 *rty_Var_GreenINDwithAnimation2, uint16 *rty_Var_GreenINDwithAnimation3, B_Green_IND_with_Animati_mn3u_T *localB, const ConstB_Green_IND_with_An_nczp_T
  *localC, DW_Green_IND_with_Animat_pmuj_T *localDW);
extern void IndyOutputControl_Function_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_jb4v, uint16 *rty_IndyOutput_Sig_ilyk, uint16 *rty_IndyOutput_Sig_dfmq);
extern void IndyOutputControl_Funct_Disable(void);
extern void App__IndyOutputControl_Function(INDContType rtu_PostProcessIn, WPCIndUSMState rtu_PostProcessIn_jb4v, RheostatOption rtu_PostProcessIn_ilyk, Bool rtu_PostProcessIn_dfmq, Bool
  rtu_PostProcessIn_f2vh, C_RheoStatLevel rtu_PostProcessIn_k42s, Bool rtu_PostProcessIn_jn04, Bool rtu_PostProcessIn_ppii, WPCIndCmdState rtu_PostProcessIn_dzkt, Bool rtu_PostProcessIn_omf3,
  C_AutoBrightLevel rtu_PostProcessIn_boj3, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_jb4v, uint16 *rty_IndyOutput_Sig_ilyk, uint16 *rty_IndyOutput_Sig_dfmq);
extern void IndyOutputControl_Fun_flyb_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_gx5p, uint16 *rty_IndyOutput_Sig_lzzp, uint16 *rty_IndyOutput_Sig_mowe);
extern void IndyOutputControl__gkc5_Disable(void);
extern void IndyOutputControl_Function_nrso(INDContType rtu_PostProcessIn, WPC2IndCmdState rtu_PostProcessIn_gx5p, WPCIndUSMState rtu_PostProcessIn_lzzp, Bool rtu_PostProcessIn_mowe, Bool
  rtu_PostProcessIn_f2vy, Bool rtu_PostProcessIn_kr5d, RheostatOption rtu_PostProcessIn_bizt, Bool rtu_PostProcessIn_mkqp, Bool rtu_PostProcessIn_fg01, C_RheoStatLevel rtu_PostProcessIn_jxih,
  C_AutoBrightLevel rtu_PostProcessIn_cr0j, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_gx5p, uint16 *rty_IndyOutput_Sig_lzzp, uint16 *rty_IndyOutput_Sig_mowe);
extern void IndyOutputControl_Fun_g554_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_e2b1, uint16 *rty_IndyOutput_Sig_czfa, uint16 *rty_IndyOutput_Sig_a1tj);
extern void IndyOutputControl__n4jw_Disable(void);
extern void IndyOutputControl_Function_bnu5(INDContType rtu_PostProcessIn, RWPCIndCmdState rtu_PostProcessIn_e2b1, C_WPCWarning rtu_PostProcessIn_czfa, WPCIndUSMState rtu_PostProcessIn_a1tj, Bool
  rtu_PostProcessIn_jr04, Bool rtu_PostProcessIn_ec5f, Bool rtu_PostProcessIn_jvxw, RheostatOption rtu_PostProcessIn_fhfw, Bool rtu_PostProcessIn_ijyl, Bool rtu_PostProcessIn_mall, C_RheoStatLevel
  rtu_PostProcessIn_muku, C_AutoBrightLevel rtu_PostProcessIn_js3h, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_e2b1, uint16 *rty_IndyOutput_Sig_czfa, uint16 *rty_IndyOutput_Sig_a1tj);
extern void IndyOutputControl_Fun_fbjd_Init(uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_m0cm, uint16 *rty_IndyOutput_Sig_hewm, uint16 *rty_IndyOutput_Sig_nd1o);
extern void IndyOutputControl__i523_Disable(void);
extern void IndyOutputControl_Function_ds32(INDContType rtu_PostProcessIn, WPCIndUSMState rtu_PostProcessIn_m0cm, RheostatOption rtu_PostProcessIn_hewm, Bool rtu_PostProcessIn_nd1o, Bool
  rtu_PostProcessIn_fhw1, C_RheoStatLevel rtu_PostProcessIn_nuol, Bool rtu_PostProcessIn_iuww, Bool rtu_PostProcessIn_e0kb, WPCIndCmdState rtu_PostProcessIn_date, Bool rtu_PostProcessIn_heya,
  C_AutoBrightLevel rtu_PostProcessIn_b0mg, uint16 *rty_IndyOutput_Sig, uint16 *rty_IndyOutput_Sig_m0cm, uint16 *rty_IndyOutput_Sig_hewm, uint16 *rty_IndyOutput_Sig_nd1o);

#endif                                 /* RTW_HEADER_IndyOutputControl_Function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
