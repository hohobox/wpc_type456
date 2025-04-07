/*
 * File: OverCurrentDetecting_Function.c
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
#include "OverCurrentDetecting_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
#define A_IN_CurrentMonitoring_FaultOff ((uint8)1U)
#define Ap_IN_CurrentMonitoring_FaultOn ((uint8)2U)
#define Ap_IN_CurrentMonitoring_Inhibit ((uint8)2U)
#define Ap_event_Cancel_Timer_ReOvrCurr (1)
#define App_M_event_Start_Timer_OvrCurr (2)
#define App_Mo_IN_CurrentMonitoring_Off ((uint8)1U)
#define App_Mod_IN_CurrentMonitoring_On ((uint8)2U)
#define App_Model_CALL_EVENT_e         (-1)
#define App_Model_IN_NO_ACTIVE_CHILD_m ((uint8)0U)
#define App_Model_IN_Off               ((uint8)1U)
#define App_Model_IN_On                ((uint8)2U)
#define App__IN_CurrentMonitoring_Fault ((uint8)1U)
#define App__IN_CurrentMonitoring_Nomal ((uint8)2U)
#define App__event_Cancel_Timer_OvrCurr (0)
#define App_event_Start_Timer_ReOvrCurr (3)
#define IN_CurrentMonitoring_Filtering ((uint8)1U)

/* Forward declaration for local functions */
static void App_Model_Tick_Timer_OvrCurr(uint8 *rty_b_Timer_OvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);
static void App_Model_Tick_Timer_ReOvrCurr(uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);
static void enter_atomic_CurrentMonitoring_(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);
static void enter_internal_Tick_Timer_OvrCu(uint8 *rty_b_Timer_OvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);
static void enter_internal_Tick_Timer_ReOvr(uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW);

/* Function for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
static void App_Model_Tick_Timer_OvrCurr(uint8 *rty_b_Timer_OvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  switch (localDW->is_Tick_Timer_OvrCurr) {
   case App_Model_IN_Off:
    if (localDW->sfEvent == App_M_event_Start_Timer_OvrCurr) {
      localDW->is_Tick_Timer_OvrCurr = App_Model_IN_On;
    }
    break;

   case App_Model_IN_On:
    {
      if (localDW->sfEvent == App__event_Cancel_Timer_OvrCurr) {
        localDW->is_Tick_Timer_OvrCurr = App_Model_IN_Off;
        localDW->Timer_OvrCurr = 0U;
        *rty_b_Timer_OvrCurr = 0U;
      } else {
        sint32 tmp;
        tmp = localDW->Timer_OvrCurr + 1;
        if (localDW->Timer_OvrCurr + 1 > 255) {
          tmp = 255;
        }

        localDW->Timer_OvrCurr = (uint8)tmp;
        *rty_b_Timer_OvrCurr = localDW->Timer_OvrCurr;
        if (localDW->sfEvent == App_M_event_Start_Timer_OvrCurr) {
          localDW->Timer_OvrCurr = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
static void App_Model_Tick_Timer_ReOvrCurr(uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  switch (localDW->is_Tick_Timer_ReOvrCurr) {
   case App_Model_IN_Off:
    if (localDW->sfEvent == App_event_Start_Timer_ReOvrCurr) {
      localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_On;
    }
    break;

   case App_Model_IN_On:
    {
      if (localDW->sfEvent == Ap_event_Cancel_Timer_ReOvrCurr) {
        localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_Off;
        localDW->Timer_ReOvrCurr = 0U;
        *rty_b_Timer_ReOvrCurr = 0U;
      } else {
        sint32 tmp;
        tmp = localDW->Timer_ReOvrCurr + 1;
        if (localDW->Timer_ReOvrCurr + 1 > 65535) {
          tmp = 65535;
        }

        localDW->Timer_ReOvrCurr = (uint16)tmp;
        *rty_b_Timer_ReOvrCurr = localDW->Timer_ReOvrCurr;
        if (localDW->sfEvent == App_event_Start_Timer_ReOvrCurr) {
          localDW->Timer_ReOvrCurr = 0U;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
static void enter_atomic_CurrentMonitoring_(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  sint32 b_previousEvent;
  localDW->Counter_OverCurr = 0U;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = App__event_Cancel_Timer_OvrCurr;
  if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
    /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
    App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
  }

  localDW->sfEvent = Ap_event_Cancel_Timer_ReOvrCurr;
  if (localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
    /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
    App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
  }

  localDW->sfEvent = b_previousEvent;

  /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
  *rty_b_CurrentFault = Off;
}

/* Function for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
static void enter_internal_Tick_Timer_OvrCu(uint8 *rty_b_Timer_OvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->is_Tick_Timer_OvrCurr = App_Model_IN_Off;
  localDW->Timer_OvrCurr = 0U;

  /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
  *rty_b_Timer_OvrCurr = 0U;
}

/* Function for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
static void enter_internal_Tick_Timer_ReOvr(uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_Off;
  localDW->Timer_ReOvrCurr = 0U;

  /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
  *rty_b_Timer_ReOvrCurr = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S182>/OverCurrentDetecting3_8_LPC'
 *    '<S362>/OverCurrentDetecting3_8_LPC'
 */
void OverCurrentDetecting3_8_LP_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_e;
  *rty_b_CurrentFault = Off;
  *rty_b_Timer_OvrCurr = 0U;
  *rty_b_Timer_ReOvrCurr = 0U;
}

/*
 * System reset for atomic system:
 *    '<S182>/OverCurrentDetecting3_8_LPC'
 *    '<S362>/OverCurrentDetecting3_8_LPC'
 */
void OverCurrentDetecting3_8_L_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_e;
  localDW->is_active_OverCurrentDetecting = 0U;
  localDW->is_OverCurrentDetecting = App_Model_IN_NO_ACTIVE_CHILD_m;
  localDW->is_CurrentMonitoring_On = App_Model_IN_NO_ACTIVE_CHILD_m;
  localDW->is_CurrentMonitoring_FaultOff = App_Model_IN_NO_ACTIVE_CHILD_m;
  localDW->is_CurrentMonitoring_FaultOn = App_Model_IN_NO_ACTIVE_CHILD_m;
  localDW->is_active_Tick_Timer_OvrCurr = 0U;
  localDW->is_Tick_Timer_OvrCurr = App_Model_IN_NO_ACTIVE_CHILD_m;
  localDW->is_active_Tick_Timer_ReOvrCurr = 0U;
  localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_NO_ACTIVE_CHILD_m;
  localDW->is_active_c4_OverCurrentDetecti = 0U;
  localDW->Timer_OvrCurr = 0U;
  localDW->Timer_ReOvrCurr = 0U;
  localDW->Counter_OverCurr = 0U;
  *rty_b_CurrentFault = Off;
  *rty_b_Timer_OvrCurr = 0U;
  *rty_b_Timer_ReOvrCurr = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S182>/OverCurrentDetecting3_8_LPC'
 *    '<S362>/OverCurrentDetecting3_8_LPC'
 */
void App_OverCurrentDetecting3_8_LPC(uint16 rtu_CurrentCurr, WPCStatus rtu_WPCStatus, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr,
  DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->sfEvent = App_Model_CALL_EVENT_e;

  /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
  if (localDW->is_active_c4_OverCurrentDetecti == 0U) {
    localDW->is_active_c4_OverCurrentDetecti = 1U;
    localDW->is_active_OverCurrentDetecting = 1U;
    localDW->is_OverCurrentDetecting = App_Mo_IN_CurrentMonitoring_Off;
    enter_atomic_CurrentMonitoring_(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, localDW);
    localDW->is_active_Tick_Timer_OvrCurr = 1U;
    enter_internal_Tick_Timer_OvrCu(rty_b_Timer_OvrCurr, localDW);
    localDW->is_active_Tick_Timer_ReOvrCurr = 1U;
    enter_internal_Tick_Timer_ReOvr(rty_b_Timer_ReOvrCurr, localDW);
  } else {
    if (localDW->is_active_OverCurrentDetecting != 0U) {
      switch (localDW->is_OverCurrentDetecting) {
       case App_Mo_IN_CurrentMonitoring_Off:
        *rty_b_CurrentFault = Off;

        /* 1. */
        if (rtu_WPCStatus == WPCMode) {
          localDW->is_OverCurrentDetecting = App_Mod_IN_CurrentMonitoring_On;
          localDW->is_CurrentMonitoring_On = A_IN_CurrentMonitoring_FaultOff;
          *rty_b_CurrentFault = Off;
          if (rtu_CurrentCurr < 4500) {
            localDW->is_CurrentMonitoring_FaultOff = App__IN_CurrentMonitoring_Nomal;
            localDW->Counter_OverCurr = 0U;
          } else {
            localDW->is_CurrentMonitoring_FaultOff = IN_CurrentMonitoring_Filtering;
            localDW->sfEvent = App_M_event_Start_Timer_OvrCurr;
            if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
              App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
            }

            localDW->sfEvent = -1;
          }
        }
        break;

       case App_Mod_IN_CurrentMonitoring_On:
        {
          /* 1. */
          if (rtu_WPCStatus == ModeOff) {
            switch (localDW->is_CurrentMonitoring_On) {
             case A_IN_CurrentMonitoring_FaultOff:
              if (localDW->is_CurrentMonitoring_FaultOff == IN_CurrentMonitoring_Filtering) {
                localDW->sfEvent = App__event_Cancel_Timer_OvrCurr;
                if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                  App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_CurrentMonitoring_FaultOff = App_Model_IN_NO_ACTIVE_CHILD_m;
              } else {
                localDW->is_CurrentMonitoring_FaultOff = App_Model_IN_NO_ACTIVE_CHILD_m;
              }

              localDW->is_CurrentMonitoring_On = App_Model_IN_NO_ACTIVE_CHILD_m;
              break;

             case Ap_IN_CurrentMonitoring_FaultOn:
              if (localDW->is_CurrentMonitoring_FaultOn == App__IN_CurrentMonitoring_Fault) {
                localDW->sfEvent = Ap_event_Cancel_Timer_ReOvrCurr;
                if (localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                  App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_CurrentMonitoring_FaultOn = App_Model_IN_NO_ACTIVE_CHILD_m;
              } else {
                localDW->is_CurrentMonitoring_FaultOn = App_Model_IN_NO_ACTIVE_CHILD_m;
              }

              localDW->is_CurrentMonitoring_On = App_Model_IN_NO_ACTIVE_CHILD_m;
              break;
            }

            localDW->is_OverCurrentDetecting = App_Mo_IN_CurrentMonitoring_Off;
            enter_atomic_CurrentMonitoring_(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, localDW);
          } else {
            switch (localDW->is_CurrentMonitoring_On) {
             case A_IN_CurrentMonitoring_FaultOff:
              {
                *rty_b_CurrentFault = Off;
                switch (localDW->is_CurrentMonitoring_FaultOff) {
                 case IN_CurrentMonitoring_Filtering:
                  {
                    /* 1 */
                    if (rtu_CurrentCurr < 4500) {
                      localDW->sfEvent = App__event_Cancel_Timer_OvrCurr;
                      if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                        App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                      }

                      localDW->sfEvent = -1;
                      localDW->is_CurrentMonitoring_FaultOff = App__IN_CurrentMonitoring_Nomal;
                      localDW->Counter_OverCurr = 0U;

                      /* 2. */
                    } else if (localDW->Timer_OvrCurr >= 15) {
                      sint32 tmp;
                      localDW->sfEvent = App__event_Cancel_Timer_OvrCurr;
                      if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                        App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                      }

                      localDW->is_CurrentMonitoring_FaultOff = App_Model_IN_NO_ACTIVE_CHILD_m;
                      localDW->is_CurrentMonitoring_On = Ap_IN_CurrentMonitoring_FaultOn;
                      *rty_b_CurrentFault = On;
                      localDW->is_CurrentMonitoring_FaultOn = App__IN_CurrentMonitoring_Fault;
                      localDW->sfEvent = App_event_Start_Timer_ReOvrCurr;
                      if (localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                        App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                      }

                      localDW->sfEvent = -1;
                      tmp = localDW->Counter_OverCurr + 1;
                      if (localDW->Counter_OverCurr + 1 > 255) {
                        tmp = 255;
                      }

                      localDW->Counter_OverCurr = (uint8)tmp;
                    }
                  }
                  break;

                 case App__IN_CurrentMonitoring_Nomal:
                  /* 1.  */
                  if (rtu_CurrentCurr >= 4500) {
                    localDW->is_CurrentMonitoring_FaultOff = IN_CurrentMonitoring_Filtering;
                    localDW->sfEvent = App_M_event_Start_Timer_OvrCurr;
                    if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                      App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                    }

                    localDW->sfEvent = -1;
                  }
                  break;
                }
              }
              break;

             case Ap_IN_CurrentMonitoring_FaultOn:
              *rty_b_CurrentFault = On;

              /* 1. */
              if ((localDW->Counter_OverCurr < 10) && (localDW->Timer_ReOvrCurr >= 500)) {
                if (localDW->is_CurrentMonitoring_FaultOn == App__IN_CurrentMonitoring_Fault) {
                  localDW->sfEvent = Ap_event_Cancel_Timer_ReOvrCurr;
                  if (localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                    App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                  }

                  localDW->sfEvent = -1;
                  localDW->is_CurrentMonitoring_FaultOn = App_Model_IN_NO_ACTIVE_CHILD_m;
                } else {
                  localDW->is_CurrentMonitoring_FaultOn = App_Model_IN_NO_ACTIVE_CHILD_m;
                }

                localDW->is_CurrentMonitoring_On = A_IN_CurrentMonitoring_FaultOff;
                *rty_b_CurrentFault = Off;
                if (rtu_CurrentCurr < 4500) {
                  localDW->is_CurrentMonitoring_FaultOff = App__IN_CurrentMonitoring_Nomal;
                  localDW->Counter_OverCurr = 0U;
                } else {
                  localDW->is_CurrentMonitoring_FaultOff = IN_CurrentMonitoring_Filtering;
                  localDW->sfEvent = App_M_event_Start_Timer_OvrCurr;
                  if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                    App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                  }

                  localDW->sfEvent = -1;
                }
              } else if ((localDW->is_CurrentMonitoring_FaultOn == App__IN_CurrentMonitoring_Fault) && (localDW->Counter_OverCurr >= 10)) {
                /* 1.  */
                localDW->sfEvent = Ap_event_Cancel_Timer_ReOvrCurr;
                if (localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                  App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_CurrentMonitoring_FaultOn = Ap_IN_CurrentMonitoring_Inhibit;
              }
              break;
            }
          }
        }
        break;
      }
    }

    if (localDW->is_active_Tick_Timer_OvrCurr != 0U) {
      App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
    }

    if (localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
      App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
    }
  }

  /* End of Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
}

/* System initialize for atomic system: '<S18>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Funct_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemInitialize for Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_LP_Init(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LPC);
}

/* Output and update for atomic system: '<S18>/OverCurrentDetecting_Function' */
void A_OverCurrentDetecting_Function(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* Chart: '<S182>/OverCurrentDetecting3_8_LPC' */
  App_OverCurrentDetecting3_8_LPC(rtu_PreProcessIn, rtu_WPCStatus, rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LPC);
}

/* System initialize for atomic system: '<S203>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Fun_n_Init(Bool *rty_b_CurrenFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemInitialize for Chart: '<S362>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_LP_Init(rty_b_CurrenFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LP_a);
}

/* System reset for atomic system: '<S203>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Fu_f_Reset(Bool *rty_b_CurrenFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemReset for Chart: '<S362>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_L_Reset(rty_b_CurrenFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LP_a);
}

/* Output and update for atomic system: '<S203>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Function_i(WPCStatus rtu_WPC2Status, uint16 rtu_PreProcessIn, Bool *rty_b_CurrenFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* Chart: '<S362>/OverCurrentDetecting3_8_LPC' */
  App_OverCurrentDetecting3_8_LPC(rtu_PreProcessIn, rtu_WPC2Status, rty_b_CurrenFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LP_a);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
