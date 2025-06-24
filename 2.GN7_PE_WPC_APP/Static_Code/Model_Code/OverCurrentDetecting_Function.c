/*
 * File: OverCurrentDetecting_Function.c
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
#include "OverCurrentDetecting_Function.h"
#include "App_Model.h"

/* Named constants for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
#define A_IN_CurrentMonitoring_FaultOff ((uint8)1U)
#define Ap_IN_CurrentMonitoring_FaultOn ((uint8)2U)
#define Ap_IN_CurrentMonitoring_Inhibit ((uint8)2U)
#define Ap_event_Cancel_Timer_ReOvrCurr (1)
#define App_M_event_Start_Timer_OvrCurr (2)
#define App_Mo_IN_CurrentMonitoring_Off ((uint8)1U)
#define App_Mod_IN_CurrentMonitoring_On ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_mjrn ((uint8)0U)
#define App_Model_CALL_EVENT_ekce      (-1)
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

/* Function for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
static void App_Model_Tick_Timer_OvrCurr(uint8 *rty_b_Timer_OvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  switch (localDW->is_Tick_Timer_OvrCurr) {
   case App_Model_IN_Off:
    if (localDW->sfEvent == (sint32)App_M_event_Start_Timer_OvrCurr) {
      localDW->is_Tick_Timer_OvrCurr = App_Model_IN_On;
    }
    break;

   case App_Model_IN_On:
    {
      if (localDW->sfEvent == (sint32)App__event_Cancel_Timer_OvrCurr) {
        localDW->is_Tick_Timer_OvrCurr = App_Model_IN_Off;
        localDW->Timer_OvrCurr = 0U;
        *rty_b_Timer_OvrCurr = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_OvrCurr + 1;
        if (((sint32)localDW->Timer_OvrCurr + 1) > 255) {
          tmp = 255;
        }

        localDW->Timer_OvrCurr = (uint8)tmp;
        *rty_b_Timer_OvrCurr = localDW->Timer_OvrCurr;
        if (localDW->sfEvent == (sint32)App_M_event_Start_Timer_OvrCurr) {
          localDW->Timer_OvrCurr = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
static void App_Model_Tick_Timer_ReOvrCurr(uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  switch (localDW->is_Tick_Timer_ReOvrCurr) {
   case App_Model_IN_Off:
    if (localDW->sfEvent == (sint32)App_event_Start_Timer_ReOvrCurr) {
      localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_On;
    }
    break;

   case App_Model_IN_On:
    {
      if (localDW->sfEvent == (sint32)Ap_event_Cancel_Timer_ReOvrCurr) {
        localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_Off;
        localDW->Timer_ReOvrCurr = 0U;
        *rty_b_Timer_ReOvrCurr = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_ReOvrCurr + 1;
        if (((sint32)localDW->Timer_ReOvrCurr + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_ReOvrCurr = (uint16)tmp;
        *rty_b_Timer_ReOvrCurr = localDW->Timer_ReOvrCurr;
        if (localDW->sfEvent == (sint32)App_event_Start_Timer_ReOvrCurr) {
          localDW->Timer_ReOvrCurr = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
static void enter_atomic_CurrentMonitoring_(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  sint32 b_previousEvent;
  localDW->Counter_OverCurr = 0U;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)App__event_Cancel_Timer_OvrCurr;
  if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
    /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
    App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
  }

  localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_ReOvrCurr;
  if ((uint32)localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
    /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
    App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
  }

  localDW->sfEvent = b_previousEvent;

  /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  *rty_b_CurrentFault = Off;
}

/* Function for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
static void enter_internal_Tick_Timer_OvrCu(uint8 *rty_b_Timer_OvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->is_Tick_Timer_OvrCurr = App_Model_IN_Off;
  localDW->Timer_OvrCurr = 0U;

  /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  *rty_b_Timer_OvrCurr = 0U;
}

/* Function for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
static void enter_internal_Tick_Timer_ReOvr(uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->is_Tick_Timer_ReOvrCurr = App_Model_IN_Off;
  localDW->Timer_ReOvrCurr = 0U;

  /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  *rty_b_Timer_ReOvrCurr = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S190>/OverCurrentDetecting3_8_LPC'
 *    '<S380>/OverCurrentDetecting3_8_LPC'
 *    '<S592>/OverCurrentDetecting3_8_LPC'
 *    '<S812>/OverCurrentDetecting3_8_LPC'
 */
void OverCurrentDetecting3_8_LP_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ekce;
  localDW->is_active_OverCurrentDetecting = 0U;
  localDW->is_OverCurrentDetecting = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_CurrentMonitoring_On = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_CurrentMonitoring_FaultOff = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_CurrentMonitoring_FaultOn = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_active_Tick_Timer_OvrCurr = 0U;
  localDW->is_Tick_Timer_OvrCurr = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_active_Tick_Timer_ReOvrCurr = 0U;
  localDW->is_Tick_Timer_ReOvrCurr = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_active_c4_OverCurrentDetecti = 0U;
  localDW->Timer_OvrCurr = 0U;
  localDW->Timer_ReOvrCurr = 0U;
  localDW->Counter_OverCurr = 0U;
  *rty_b_CurrentFault = Off;
  *rty_b_Timer_OvrCurr = 0U;
  *rty_b_Timer_ReOvrCurr = 0U;
}

/*
 * System reset for atomic system:
 *    '<S190>/OverCurrentDetecting3_8_LPC'
 *    '<S380>/OverCurrentDetecting3_8_LPC'
 *    '<S592>/OverCurrentDetecting3_8_LPC'
 *    '<S812>/OverCurrentDetecting3_8_LPC'
 */
void OverCurrentDetecting3_8_L_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr, DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ekce;
  localDW->is_active_OverCurrentDetecting = 0U;
  localDW->is_OverCurrentDetecting = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_CurrentMonitoring_On = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_CurrentMonitoring_FaultOff = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_CurrentMonitoring_FaultOn = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_active_Tick_Timer_OvrCurr = 0U;
  localDW->is_Tick_Timer_OvrCurr = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
  localDW->is_active_Tick_Timer_ReOvrCurr = 0U;
  localDW->is_Tick_Timer_ReOvrCurr = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
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
 *    '<S190>/OverCurrentDetecting3_8_LPC'
 *    '<S380>/OverCurrentDetecting3_8_LPC'
 *    '<S592>/OverCurrentDetecting3_8_LPC'
 *    '<S812>/OverCurrentDetecting3_8_LPC'
 */
void App_OverCurrentDetecting3_8_LPC(uint16 rtu_CurrentCurr, WPCStatus rtu_WPCStatus, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr,
  DW_OverCurrentDetecting3_8_LP_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ekce;

  /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  if ((uint32)localDW->is_active_c4_OverCurrentDetecti == 0U) {
    localDW->is_active_c4_OverCurrentDetecti = 1U;
    localDW->is_active_OverCurrentDetecting = 1U;
    localDW->is_OverCurrentDetecting = App_Mo_IN_CurrentMonitoring_Off;
    enter_atomic_CurrentMonitoring_(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, localDW);
    localDW->is_active_Tick_Timer_OvrCurr = 1U;
    enter_internal_Tick_Timer_OvrCu(rty_b_Timer_OvrCurr, localDW);
    localDW->is_active_Tick_Timer_ReOvrCurr = 1U;
    enter_internal_Tick_Timer_ReOvr(rty_b_Timer_ReOvrCurr, localDW);
  } else {
    if ((uint32)localDW->is_active_OverCurrentDetecting != 0U) {
      switch (localDW->is_OverCurrentDetecting) {
       case App_Mo_IN_CurrentMonitoring_Off:
        *rty_b_CurrentFault = Off;

        /* 1. */
        if ((uint32)rtu_WPCStatus == WPCMode) {
          localDW->is_OverCurrentDetecting = App_Mod_IN_CurrentMonitoring_On;
          localDW->is_CurrentMonitoring_On = A_IN_CurrentMonitoring_FaultOff;
          *rty_b_CurrentFault = Off;
          if (rtu_CurrentCurr < ((uint16)4500U)) {
            localDW->is_CurrentMonitoring_FaultOff = App__IN_CurrentMonitoring_Nomal;
            localDW->Counter_OverCurr = 0U;
          } else {
            localDW->is_CurrentMonitoring_FaultOff = IN_CurrentMonitoring_Filtering;
            localDW->sfEvent = (sint32)App_M_event_Start_Timer_OvrCurr;
            if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
              App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
            }

            localDW->sfEvent = -1;
          }
        }
        break;

       case App_Mod_IN_CurrentMonitoring_On:
        {
          /* 1. */
          if ((uint32)rtu_WPCStatus == ModeOff) {
            switch (localDW->is_CurrentMonitoring_On) {
             case A_IN_CurrentMonitoring_FaultOff:
              if ((uint32)localDW->is_CurrentMonitoring_FaultOff == IN_CurrentMonitoring_Filtering) {
                localDW->sfEvent = (sint32)App__event_Cancel_Timer_OvrCurr;
                if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                  App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_CurrentMonitoring_FaultOff = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
              } else {
                localDW->is_CurrentMonitoring_FaultOff = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
              }

              localDW->is_CurrentMonitoring_On = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
              break;

             case Ap_IN_CurrentMonitoring_FaultOn:
              if ((uint32)localDW->is_CurrentMonitoring_FaultOn == App__IN_CurrentMonitoring_Fault) {
                localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_ReOvrCurr;
                if ((uint32)localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                  App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                }

                localDW->sfEvent = -1;
                localDW->is_CurrentMonitoring_FaultOn = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
              } else {
                localDW->is_CurrentMonitoring_FaultOn = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
              }

              localDW->is_CurrentMonitoring_On = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
              break;

             default:
              /* no actions */
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
                    if (rtu_CurrentCurr < ((uint16)4500U)) {
                      localDW->sfEvent = (sint32)App__event_Cancel_Timer_OvrCurr;
                      if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                        App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                      }

                      localDW->sfEvent = -1;
                      localDW->is_CurrentMonitoring_FaultOff = App__IN_CurrentMonitoring_Nomal;
                      localDW->Counter_OverCurr = 0U;

                      /* 2. */
                    } else if (localDW->Timer_OvrCurr >= ((uint8)15U)) {
                      sint32 tmp;
                      localDW->sfEvent = (sint32)App__event_Cancel_Timer_OvrCurr;
                      if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                        App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                      }

                      localDW->is_CurrentMonitoring_FaultOff = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
                      localDW->is_CurrentMonitoring_On = Ap_IN_CurrentMonitoring_FaultOn;
                      *rty_b_CurrentFault = On;
                      localDW->is_CurrentMonitoring_FaultOn = App__IN_CurrentMonitoring_Fault;
                      localDW->sfEvent = (sint32)App_event_Start_Timer_ReOvrCurr;
                      if ((uint32)localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                        App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                      }

                      localDW->sfEvent = -1;
                      tmp = (sint32)localDW->Counter_OverCurr + 1;
                      if (((sint32)localDW->Counter_OverCurr + 1) > 255) {
                        tmp = 255;
                      }

                      localDW->Counter_OverCurr = (uint8)tmp;
                    } else {
                      /* no actions */
                    }
                  }
                  break;

                 case App__IN_CurrentMonitoring_Nomal:
                  /* 1.  */
                  if (rtu_CurrentCurr >= ((uint16)4500U)) {
                    localDW->is_CurrentMonitoring_FaultOff = IN_CurrentMonitoring_Filtering;
                    localDW->sfEvent = (sint32)App_M_event_Start_Timer_OvrCurr;
                    if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                      App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                    }

                    localDW->sfEvent = -1;
                  }
                  break;

                 default:
                  /* no actions */
                  break;
                }
              }
              break;

             case Ap_IN_CurrentMonitoring_FaultOn:
              *rty_b_CurrentFault = On;

              /* 1. */
              if ((localDW->Counter_OverCurr < ((uint8)10U)) && (localDW->Timer_ReOvrCurr >= ((uint16)500U))) {
                if ((uint32)localDW->is_CurrentMonitoring_FaultOn == App__IN_CurrentMonitoring_Fault) {
                  localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_ReOvrCurr;
                  if ((uint32)localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                    App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                  }

                  localDW->sfEvent = -1;
                  localDW->is_CurrentMonitoring_FaultOn = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
                } else {
                  localDW->is_CurrentMonitoring_FaultOn = App_Mod_IN_NO_ACTIVE_CHILD_mjrn;
                }

                localDW->is_CurrentMonitoring_On = A_IN_CurrentMonitoring_FaultOff;
                *rty_b_CurrentFault = Off;
                if (rtu_CurrentCurr < ((uint16)4500U)) {
                  localDW->is_CurrentMonitoring_FaultOff = App__IN_CurrentMonitoring_Nomal;
                  localDW->Counter_OverCurr = 0U;
                } else {
                  localDW->is_CurrentMonitoring_FaultOff = IN_CurrentMonitoring_Filtering;
                  localDW->sfEvent = (sint32)App_M_event_Start_Timer_OvrCurr;
                  if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
                    App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
                  }

                  localDW->sfEvent = -1;
                }
              } else if ((uint32)localDW->is_CurrentMonitoring_FaultOn == App__IN_CurrentMonitoring_Fault) {
                /* 1.  */
                if (localDW->Counter_OverCurr >= ((uint8)10U)) {
                  localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_ReOvrCurr;
                  if ((uint32)localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
                    App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
                  }

                  localDW->sfEvent = -1;
                  localDW->is_CurrentMonitoring_FaultOn = Ap_IN_CurrentMonitoring_Inhibit;
                }
              } else {
                /* no actions */
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }
        break;

       default:
        /* no actions */
        break;
      }
    }

    if ((uint32)localDW->is_active_Tick_Timer_OvrCurr != 0U) {
      App_Model_Tick_Timer_OvrCurr(rty_b_Timer_OvrCurr, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_ReOvrCurr != 0U) {
      App_Model_Tick_Timer_ReOvrCurr(rty_b_Timer_ReOvrCurr, localDW);
    }
  }

  /* End of Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
}

/* System initialize for atomic system: '<S23>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Funct_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemInitialize for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_LP_Init(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LPC);
}

/* System reset for atomic system: '<S23>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Func_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemReset for Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_L_Reset(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LPC);
}

/* Output and update for atomic system: '<S23>/OverCurrentDetecting_Function' */
void A_OverCurrentDetecting_Function(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* Chart: '<S190>/OverCurrentDetecting3_8_LPC' */
  App_OverCurrentDetecting3_8_LPC(rtu_PreProcessIn, rtu_WPCStatus, rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_LPC);
}

/* System initialize for atomic system: '<S218>/OverCurrentDetecting_Function' */
void OverCurrentDetecting__bnpf_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemInitialize for Chart: '<S380>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_LP_Init(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_aumt);
}

/* System reset for atomic system: '<S218>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_kzza_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemReset for Chart: '<S380>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_L_Reset(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_aumt);
}

/* Output and update for atomic system: '<S218>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Funct_i2cq(WPCStatus rtu_WPC2Status, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* Chart: '<S380>/OverCurrentDetecting3_8_LPC' */
  App_OverCurrentDetecting3_8_LPC(rtu_PreProcessIn, rtu_WPC2Status, rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_aumt);
}

/* System initialize for atomic system: '<S463>/OverCurrentDetecting_Function' */
void OverCurrentDetecting__bh0g_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemInitialize for Chart: '<S592>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_LP_Init(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_pj0a);
}

/* System reset for atomic system: '<S463>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_lpsa_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemReset for Chart: '<S592>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_L_Reset(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_pj0a);
}

/* Output and update for atomic system: '<S463>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Funct_oslj(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* Chart: '<S592>/OverCurrentDetecting3_8_LPC' */
  App_OverCurrentDetecting3_8_LPC(rtu_PreProcessIn, rtu_WPCStatus, rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_pj0a);
}

/* System initialize for atomic system: '<S640>/OverCurrentDetecting_Function' */
void OverCurrentDetecting__ilt2_Init(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemInitialize for Chart: '<S812>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_LP_Init(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_iegy);
}

/* System reset for atomic system: '<S640>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_lftl_Reset(Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* SystemReset for Chart: '<S812>/OverCurrentDetecting3_8_LPC' */
  OverCurrentDetecting3_8_L_Reset(rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_iegy);
}

/* Output and update for atomic system: '<S640>/OverCurrentDetecting_Function' */
void OverCurrentDetecting_Funct_obzl(WPCStatus rtu_WPCStatus, uint16 rtu_PreProcessIn, Bool *rty_b_CurrentFault, uint8 *rty_b_Timer_OvrCurr, uint16 *rty_b_Timer_ReOvrCurr)
{
  /* Chart: '<S812>/OverCurrentDetecting3_8_LPC' */
  App_OverCurrentDetecting3_8_LPC(rtu_PreProcessIn, rtu_WPCStatus, rty_b_CurrentFault, rty_b_Timer_OvrCurr, rty_b_Timer_ReOvrCurr, &App_Model_DW.sf_OverCurrentDetecting3_8_iegy);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
