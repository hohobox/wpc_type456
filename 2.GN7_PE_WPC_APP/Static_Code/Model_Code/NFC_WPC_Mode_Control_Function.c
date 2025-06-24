/*
 * File: NFC_WPC_Mode_Control_Function.c
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

#include "NFC_WPC_Mode_Control_Function.h"
#include "App_Model_types.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S195>/WPC_Mode_Control' */
#define App_Mod_IN_NO_ACTIVE_CHILD_g0k4 ((uint8)0U)
#define App_Model_IN_OperationMode_OFF ((uint8)1U)
#define App_Model_IN_OperationMode_ON  ((uint8)2U)

/* Named constants for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
#define A_event_StartTimer_LPCDOffDelay (7)
#define A_event_StartTimer_PICCOffDelay (12)
#define App_IN_NFCSearchingOffDelay_Off ((uint8)1U)
#define App_M_IN_NFCSearchingTimeout_On ((uint8)2U)
#define App_Mo_IN_NFCTimeOutConfirm_Off ((uint8)1U)
#define App_Mo_IN_PhnLeftChattering_Off ((uint8)1U)
#define App_Mod_IN_NFCTimeOutConfirm_On ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_e3xy ((uint8)0U)
#define App_Mod_IN_PICCLPCDOffDelay_Off ((uint8)1U)
#define App_Mod_IN_PhnLeftChattering_On ((uint8)2U)
#define App_Mode_IN_PICCLPCDOffDelay_On ((uint8)2U)
#define App_Model_CALL_EVENT_myt0      (-1)
#define App_Model_IN_LPCDOffDelay_Off  ((uint8)1U)
#define App_Model_IN_LPCDOffDelay_On   ((uint8)2U)
#define App_Model_IN_OperationMode_LPCD ((uint8)1U)
#define App_Model_IN_OperationMode_NFC ((uint8)2U)
#define App_Model_IN_OperationMode_Off ((uint8)3U)
#define App_Model_IN_OperationMode_Picc ((uint8)4U)
#define App_Model_IN_OperationMode_WPC ((uint8)5U)
#define App_Model_IN_PICCOffDelay_Off  ((uint8)1U)
#define App_Model_IN_PICCOffDelay_On   ((uint8)2U)
#define App__IN_NFCSearchingOffDelay_On ((uint8)2U)
#define App__IN_NFCSearchingTimeout_Off ((uint8)1U)
#define event_CancelTimer_LPCDOffDelay (0)
#define event_CancelTimer_NFCSearchingO (1)
#define event_CancelTimer_NFCSearchingT (2)
#define event_CancelTimer_NFCTimeOutCon (3)
#define event_CancelTimer_PICCLPCDOffDe (4)
#define event_CancelTimer_PICCOffDelay (5)
#define event_CancelTimer_PhnLeftChatte (6)
#define event_StartTimer_NFCSearchingOf (8)
#define event_StartTimer_NFCSearchingTi (9)
#define event_StartTimer_NFCTimeOutConf (10)
#define event_StartTimer_PICCLPCDOffDel (11)
#define event_StartTimer_PhnLeftChatter (13)

/* Named constants for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
#define A_IN_NFCTimeOutConfirm_Off_ixfd ((uint8)1U)
#define A_IN_PhnLeftChattering_Off_chv2 ((uint8)1U)
#define Ap_IN_NFCTimeOutConfirm_On_jhuc ((uint8)2U)
#define Ap_IN_PICCLPCDOffDelay_Off_chhf ((uint8)1U)
#define Ap_IN_PhnLeftChattering_On_htsg ((uint8)2U)
#define App_IN_PICCLPCDOffDelay_On_eouc ((uint8)2U)
#define App_M_IN_OperationMode_NFC_p5jl ((uint8)2U)
#define App_M_IN_OperationMode_Off_dzzr ((uint8)3U)
#define App_M_IN_OperationMode_WPC_bu5q ((uint8)5U)
#define App_Mo_IN_LPCDOffDelay_Off_cqlg ((uint8)1U)
#define App_Mo_IN_PICCOffDelay_Off_c24o ((uint8)1U)
#define App_Mod_IN_LPCDOffDelay_On_m41w ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_iabj ((uint8)0U)
#define App_Mod_IN_PICCOffDelay_On_allk ((uint8)2U)
#define App_Model_CALL_EVENT_e0qm      (-1)
#define App__IN_OperationMode_LPCD_niiv ((uint8)1U)
#define App__IN_OperationMode_Picc_dikm ((uint8)4U)
#define IN_NFCSearchingOffDelay_Of_hze2 ((uint8)1U)
#define IN_NFCSearchingOffDelay_On_pz0z ((uint8)2U)
#define IN_NFCSearchingTimeout_Off_c0qf ((uint8)1U)
#define IN_NFCSearchingTimeout_On_cogw ((uint8)2U)
#define event_CancelTimer_LPCDOffD_ilej (0)
#define event_CancelTimer_NFCSearc_c2ga (1)
#define event_CancelTimer_NFCSearc_dvmb (2)
#define event_CancelTimer_NFCTimeO_kvrm (3)
#define event_CancelTimer_PICCLPCD_c4rd (4)
#define event_CancelTimer_PICCOffD_njj0 (5)
#define event_CancelTimer_PhnLeftC_d0yr (6)
#define event_StartTimer_LPCDOffDe_bu05 (7)
#define event_StartTimer_NFCSearch_ded4 (8)
#define event_StartTimer_NFCSearch_ec4y (9)
#define event_StartTimer_NFCTimeOu_h3lj (10)
#define event_StartTimer_PICCLPCDO_av1s (11)
#define event_StartTimer_PICCOffDe_m15j (12)
#define event_StartTimer_PhnLeftCh_ghci (13)

/* Named constants for Chart: '<S598>/RWPC_Mode_Control_EV' */
#define App_M_IN_OperationMode_OFF_p0kw ((uint8)1U)
#define App_Mo_IN_OperationMode_ON_gqum ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_m0bk ((uint8)0U)

/* Named constants for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
#define A_IN_NFCTimeOutConfirm_Off_h15f ((uint8)1U)
#define A_IN_PhnLeftChattering_Off_e5ff ((uint8)1U)
#define Ap_IN_NFCTimeOutConfirm_On_eii2 ((uint8)2U)
#define Ap_IN_PhnLeftChattering_On_a4s0 ((uint8)2U)
#define App_M_IN_OperationMode_NFC_lhcw ((uint8)2U)
#define App_M_IN_OperationMode_Off_cmjb ((uint8)3U)
#define App_M_IN_OperationMode_WPC_hhld ((uint8)5U)
#define App_Mo_IN_LPCDOffDelay_Off_f3el ((uint8)1U)
#define App_Mo_IN_PICCOffDelay_Off_a1d0 ((uint8)1U)
#define App_Mod_IN_LPCDOffDelay_On_hw5i ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_g2az ((uint8)0U)
#define App_Mod_IN_PICCOffDelay_On_ercd ((uint8)2U)
#define App_Model_CALL_EVENT_lsjz      (-1)
#define App__IN_OperationMode_LPCD_maec ((uint8)1U)
#define App__IN_OperationMode_Picc_buju ((uint8)4U)
#define IN_NFCSearchingOffDelay_Of_p4ac ((uint8)1U)
#define IN_NFCSearchingOffDelay_On_oulx ((uint8)2U)
#define IN_NFCSearchingTimeout_Off_cpga ((uint8)1U)
#define IN_NFCSearchingTimeout_On_ctax ((uint8)2U)
#define event_CancelTimer_LPCDOffD_kg1v (0)
#define event_CancelTimer_NFCSearc_eghu (2)
#define event_CancelTimer_NFCSearc_gsrw (1)
#define event_CancelTimer_NFCTimeO_fjff (3)
#define event_CancelTimer_PICCOffD_fgqe (4)
#define event_CancelTimer_PhnLeftC_akjh (5)
#define event_StartTimer_LPCDOffDe_c055 (6)
#define event_StartTimer_NFCSearch_cveq (8)
#define event_StartTimer_NFCSearch_ljgd (7)
#define event_StartTimer_NFCTimeOu_dt5f (9)
#define event_StartTimer_PICCOffDe_leur (10)
#define event_StartTimer_PhnLeftCh_dc3j (11)

/* Forward declaration for local functions */
static void App_Model_NFCTimeOutConfirm(void);
static void App_Model_NFCSearchingOffDelay(void);
static void App_Model_LPCDOffDelay(void);
static void App_Model_NFCSearchingTimeout(void);
static void App_Model_PICCOffDelay(void);
static void A_exit_atomic_OperationMode_NFC(void);
static void App_Model_PICCLPCDOffDelay(void);
static void App_Mo_NFCSearchingOffDetection(void);
static void App_Model_NFCDetectionCheck(void);
static void enter_atomic_OperationMode_NFC(void);
static void enter_atomic_OperationMode_Picc(void);
static void App_Model_LPCDOff_Check(Bool rtu_PreProcessIn_aaws);
static void enter_atomic_OperationMode_LPCD(Bool rtu_PreProcessIn_aaws);
static void App_Model_PhnLeftChattering(void);
static void App_Mode_DrDoorPhnLeftHoldCheck(Bool rtu_PreProcessIn_aaws, Bool rtu_PreProcessIn_ksr2, C_WPCWarning rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_devb);
static void enter_atomic_OperationMode_Off(Bool rtu_PreProcessIn_aaws, Bool rtu_PreProcessIn_ksr2, C_WPCWarning rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_devb);
static void WPC_NFC_Mode_Control_Function_S(LC_IAUWPCNFCcmd rtu_PreProcessIn_crbo, Bool rtu_PreProcessIn_aaws, IAU_OwnerPhnRegRVal rtu_PreProcessIn_muxy, OwnerPairingAdvertisingReq
  rtu_PreProcessIn_ikas, C_WPCOnOffNvalueSet rtu_PreProcessIn_akvr, OnThePad rtu_PreProcessIn_etm5, Bool rtu_PreProcessIn_gvlh, Bool rtu_PreProcessIn_n1ix, WPCStatus rtu_PreProcessIn_hg1w, Bool
  rtu_PreProcessIn_ksr2, C_WPCWarning rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_mgbl, Bool rtu_PreProcessIn_devb);

/* Forward declaration for local functions */
static void App_Mode_NFCTimeOutConfirm_ahni(void);
static void App_M_NFCSearchingOffDelay_arjk(void);
static void App_Model_LPCDOffDelay_fxbc(void);
static void App_Mo_NFCSearchingTimeout_kj53(void);
static void App_Model_PICCOffDelay_jd1b(void);
static void exit_atomic_OperationMode__ajbt(void);
static void App_Model_PICCLPCDOffDelay_ec34(void);
static void A_NFCSearchingOffDetection_cknw(void);
static void App_Mode_NFCDetectionCheck_cmxs(void);
static void enter_atomic_OperationMode_gr2j(void);
static void enter_atomic_OperationMode_ejig(void);
static void App_Model_LPCDOff_Check_fbyv(Bool rtu_PreProcessIn_cqtq);
static void enter_atomic_OperationMode_f4nq(Bool rtu_PreProcessIn_cqtq);
static void App_Mode_PhnLeftChattering_od1i(void);
static void App_DrDoorPhnLeftHoldCheck_c35e(Bool rtu_PreProcessIn_cqtq, Bool rtu_PreProcessIn_h4bs, C_WPCWarning rtu_PreProcessIn_aibk, Bool rtu_PreProcessIn_dwyv, Bool rtu_PreProcessIn_ec0z);
static void enter_atomic_OperationMode_gleh(Bool rtu_PreProcessIn_cqtq, Bool rtu_PreProcessIn_h4bs, C_WPCWarning rtu_PreProcessIn_aibk, Bool rtu_PreProcessIn_dwyv, Bool rtu_PreProcessIn_ec0z);
static void WPC_NFC_Mode_Control_Funct_gbom(Bool rtu_PreProcessIn_cqtq, LC_IAUWPCNFCcmd rtu_PreProcessIn_eeym, C_WPCOnOffNvalueSet rtu_PreProcessIn_m2di, IAU_OwnerPhnRegRVal rtu_PreProcessIn_jp2a,
  OwnerPairingAdvertisingReq rtu_PreProcessIn_ltfm, OnThePad rtu_PreProcessIn_bfmr, Bool rtu_PreProcessIn_pjvj, Bool rtu_PreProcessIn_mbte, WPCStatus rtu_PreProcessIn_auml, Bool rtu_PreProcessIn_h4bs,
  C_WPCWarning rtu_PreProcessIn_aibk, Bool rtu_PreProcessIn_dwyv, Bool rtu_PreProcessIn_jqrj, Bool rtu_PreProcessIn_ec0z);

/* Forward declaration for local functions */
static void App_Mode_NFCTimeOutConfirm_giml(void);
static void App_M_NFCSearchingOffDelay_b5hj(void);
static void App_Model_LPCDOffDelay_mp4k(void);
static void App_Mo_NFCSearchingTimeout_k2k5(void);
static void App_Model_PICCOffDelay_el5i(void);
static void App_Mode_PhnLeftChattering_jrtx(void);
static void App_DrDoorPhnLeftHoldCheck_byf3(Bool rtu_PreProcessIn_atch, Bool rtu_PreProcessIn_mdz2, C_WPCWarning rtu_PreProcessIn_hjwo, Bool rtu_PreProcessIn_fbwq, Bool rtu_PreProcessIn_gi5q);
static void enter_atomic_OperationMode_ex4b(Bool rtu_PreProcessIn_atch, Bool rtu_PreProcessIn_mdz2, C_WPCWarning rtu_PreProcessIn_hjwo, Bool rtu_PreProcessIn_fbwq, Bool rtu_PreProcessIn_gi5q);
static void exit_atomic_OperationMode__jfok(void);
static void A_NFCSearchingOffDetection_niod(void);
static void App_Mode_NFCDetectionCheck_n2sn(void);
static void enter_atomic_OperationMode_ah2j(void);
static void App_Model_LPCDOff_Check_nsrx(Bool rtu_PreProcessIn_atch);
static void enter_atomic_OperationMode_m2hb(Bool rtu_PreProcessIn_atch);

/*
 * System initialize for action system:
 *    '<S189>/WPC_Mode_Control'
 *    '<S379>/WPC_Mode_Control'
 *    '<S591>/WPC_Mode_Control'
 *    '<S811>/WPC_Mode_Control'
 */
void App_Model_WPC_Mode_Control_Init(DW_WPC_Mode_Control_App_Model_T *localDW)
{
  /* SystemInitialize for Chart: '<S195>/WPC_Mode_Control' */
  localDW->is_WpcNfcModeControl = App_Mod_IN_NO_ACTIVE_CHILD_g0k4;
  localDW->is_active_c4_NFC_WPC_Mode_Contr = 0U;
}

/*
 * Output and update for action system:
 *    '<S189>/WPC_Mode_Control'
 *    '<S379>/WPC_Mode_Control'
 *    '<S591>/WPC_Mode_Control'
 *    '<S811>/WPC_Mode_Control'
 */
void App_Model_WPC_Mode_Control(Bool rtu_R_Local_L_IGN1_IN, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_R_Local_sbBatStateFault, WPCStatus *rty_WPC_Status, DW_WPC_Mode_Control_App_Model_T *localDW)
{
  /* Chart: '<S195>/WPC_Mode_Control' */
  if ((uint32)localDW->is_active_c4_NFC_WPC_Mode_Contr == 0U) {
    localDW->is_active_c4_NFC_WPC_Mode_Contr = 1U;
    localDW->is_WpcNfcModeControl = App_Model_IN_OperationMode_OFF;

    /* SignalConversion generated from: '<S195>/WPC_Status' */
    *rty_WPC_Status = ModeOff;
  } else if ((uint32)localDW->is_WpcNfcModeControl == App_Model_IN_OperationMode_OFF) {
    /* SignalConversion generated from: '<S195>/WPC_Status' */
    *rty_WPC_Status = ModeOff;

    /* 2. */
    if (((uint32)rtu_WPCSWOption == WPC_On) && ((uint32)rtu_R_Local_L_IGN1_IN == On) && ((uint32)rtu_R_Local_sbBatStateFault != On)) {
      /* Non_GFS */
      localDW->is_WpcNfcModeControl = App_Model_IN_OperationMode_ON;

      /* SignalConversion generated from: '<S195>/WPC_Status' */
      *rty_WPC_Status = WPCMode;
    }
  } else {
    /* SignalConversion generated from: '<S195>/WPC_Status' */
    /* case IN_OperationMode_ON: */
    *rty_WPC_Status = WPCMode;

    /* 1. */
    if (((uint32)rtu_R_Local_L_IGN1_IN == Off) || ((uint32)rtu_WPCSWOption == WPC_Off) || ((uint32)rtu_R_Local_sbBatStateFault == On)) {
      /* Non_GFS */
      localDW->is_WpcNfcModeControl = App_Model_IN_OperationMode_OFF;

      /* SignalConversion generated from: '<S195>/WPC_Status' */
      *rty_WPC_Status = ModeOff;
    }
  }

  /* End of Chart: '<S195>/WPC_Mode_Control' */
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_NFCTimeOutConfirm(void)
{
  switch (App_Model_DW.is_NFCTimeOutConfirm_mnmy) {
   case App_Mo_IN_NFCTimeOutConfirm_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)event_StartTimer_NFCTimeOutConf) {
      App_Model_DW.is_NFCTimeOutConfirm_mnmy = App_Mod_IN_NFCTimeOutConfirm_On;
    }
    break;

   case App_Mod_IN_NFCTimeOutConfirm_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_NFCTimeOutCon:
        App_Model_DW.is_NFCTimeOutConfirm_mnmy = App_Mo_IN_NFCTimeOutConfirm_Off;
        App_Model_DW.Timer_NFCTimeOutConfirm_gx3p = 0U;
        break;

       case event_StartTimer_NFCTimeOutConf:
        App_Model_DW.Timer_NFCTimeOutConfirm_gx3p = 0U;
        App_Model_DW.is_NFCTimeOutConfirm_mnmy = App_Mod_IN_NFCTimeOutConfirm_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCTimeOutConfirm_gx3p + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCTimeOutConfirm_gx3p + 1U) < App_Model_DW.Timer_NFCTimeOutConfirm_gx3p) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCTimeOutConfirm_gx3p = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_NFCSearchingOffDelay(void)
{
  switch (App_Model_DW.is_NFCSearchingOffDelay_f1ei) {
   case App_IN_NFCSearchingOffDelay_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)event_StartTimer_NFCSearchingOf) {
      App_Model_DW.is_NFCSearchingOffDelay_f1ei = App__IN_NFCSearchingOffDelay_On;
    }
    break;

   case App__IN_NFCSearchingOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_NFCSearchingO:
        App_Model_DW.is_NFCSearchingOffDelay_f1ei = App_IN_NFCSearchingOffDelay_Off;
        App_Model_DW.Timer_NFCSearchingOffDelay_cpfz = 0U;
        break;

       case event_StartTimer_NFCSearchingOf:
        App_Model_DW.Timer_NFCSearchingOffDelay_cpfz = 0U;
        App_Model_DW.is_NFCSearchingOffDelay_f1ei = App__IN_NFCSearchingOffDelay_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingOffDelay_cpfz + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCSearchingOffDelay_cpfz + 1U) < App_Model_DW.Timer_NFCSearchingOffDelay_cpfz) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingOffDelay_cpfz = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_LPCDOffDelay(void)
{
  switch (App_Model_DW.is_LPCDOffDelay_mznd) {
   case App_Model_IN_LPCDOffDelay_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)A_event_StartTimer_LPCDOffDelay) {
      App_Model_DW.is_LPCDOffDelay_mznd = App_Model_IN_LPCDOffDelay_On;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_dosr = true;
    }
    break;

   case App_Model_IN_LPCDOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_LPCDOffDelay:
        App_Model_DW.is_LPCDOffDelay_mznd = App_Model_IN_LPCDOffDelay_Off;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_dosr = false;
        App_Model_DW.Timer_LPCDOffDelay_gyxl = 0U;
        break;

       case A_event_StartTimer_LPCDOffDelay:
        App_Model_DW.Timer_LPCDOffDelay_gyxl = 0U;
        App_Model_DW.is_LPCDOffDelay_mznd = App_Model_IN_LPCDOffDelay_On;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_dosr = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPCDOffDelay_gyxl + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_LPCDOffDelay_gyxl + 1U) < App_Model_DW.Timer_LPCDOffDelay_gyxl) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPCDOffDelay_gyxl = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_NFCSearchingTimeout(void)
{
  switch (App_Model_DW.is_NFCSearchingTimeout_gbui) {
   case App__IN_NFCSearchingTimeout_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)event_StartTimer_NFCSearchingTi) {
      App_Model_DW.is_NFCSearchingTimeout_gbui = App_M_IN_NFCSearchingTimeout_On;
    }
    break;

   case App_M_IN_NFCSearchingTimeout_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_NFCSearchingT:
        App_Model_DW.is_NFCSearchingTimeout_gbui = App__IN_NFCSearchingTimeout_Off;
        App_Model_DW.Timer_NFCSearchingTimeout_odwm = 0U;
        break;

       case event_StartTimer_NFCSearchingTi:
        App_Model_DW.Timer_NFCSearchingTimeout_odwm = 0U;
        App_Model_DW.is_NFCSearchingTimeout_gbui = App_M_IN_NFCSearchingTimeout_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingTimeout_odwm + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCSearchingTimeout_odwm + 1U) < App_Model_DW.Timer_NFCSearchingTimeout_odwm) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingTimeout_odwm = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_PICCOffDelay(void)
{
  switch (App_Model_DW.is_PICCOffDelay_e1ym) {
   case App_Model_IN_PICCOffDelay_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)A_event_StartTimer_PICCOffDelay) {
      App_Model_DW.is_PICCOffDelay_e1ym = App_Model_IN_PICCOffDelay_On;
    }
    break;

   case App_Model_IN_PICCOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_PICCOffDelay:
        App_Model_DW.is_PICCOffDelay_e1ym = App_Model_IN_PICCOffDelay_Off;
        App_Model_DW.Timer_PICCOffDelay_eypp = 0U;
        break;

       case A_event_StartTimer_PICCOffDelay:
        App_Model_DW.Timer_PICCOffDelay_eypp = 0U;
        App_Model_DW.is_PICCOffDelay_e1ym = App_Model_IN_PICCOffDelay_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCOffDelay_eypp + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_PICCOffDelay_eypp + 1U) < App_Model_DW.Timer_PICCOffDelay_eypp) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCOffDelay_eypp = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void A_exit_atomic_OperationMode_NFC(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oymp;
  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCTimeOutCon;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_oghf != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCSearchingO;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_bqo4 != 0U) {
    App_Model_NFCSearchingOffDelay();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCSearchingT;
  if ((uint32)App_Model_DW.is_active_NFCSearchingTime_dso3 != 0U) {
    App_Model_NFCSearchingTimeout();
  }

  App_Model_DW.sfEvent_oymp = b_previousEvent;
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_PICCLPCDOffDelay(void)
{
  switch (App_Model_DW.is_PICCLPCDOffDelay_cx0h) {
   case App_Mod_IN_PICCLPCDOffDelay_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)event_StartTimer_PICCLPCDOffDel) {
      App_Model_DW.is_PICCLPCDOffDelay_cx0h = App_Mode_IN_PICCLPCDOffDelay_On;
    }
    break;

   case App_Mode_IN_PICCLPCDOffDelay_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_PICCLPCDOffDe:
        App_Model_DW.is_PICCLPCDOffDelay_cx0h = App_Mod_IN_PICCLPCDOffDelay_Off;
        App_Model_DW.Timer_PICCLPCDOffDelay_gv4z = 0U;
        break;

       case event_StartTimer_PICCLPCDOffDel:
        App_Model_DW.Timer_PICCLPCDOffDelay_gv4z = 0U;
        App_Model_DW.is_PICCLPCDOffDelay_cx0h = App_Mode_IN_PICCLPCDOffDelay_On;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCLPCDOffDelay_gv4z + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_PICCLPCDOffDelay_gv4z + 1U) < App_Model_DW.Timer_PICCLPCDOffDelay_gv4z) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCLPCDOffDelay_gv4z = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Mo_NFCSearchingOffDetection(void)
{
  if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi != App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj == WPCNFCDeselect_Stop)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_StartTimer_NFCSearchingOf;
    if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_bqo4 != 0U) {
      App_Model_NFCSearchingOffDelay();
    }

    App_Model_DW.sfEvent_oymp = c_previousEvent;
  } else if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi != App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj == WPCNFCPolling_Search)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCSearchingO;
    if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_bqo4 != 0U) {
      App_Model_NFCSearchingOffDelay();
    }

    App_Model_DW.sfEvent_oymp = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_NFCDetectionCheck(void)
{
  if (((App_Model_DW.Input_NFCDetection1_prev != App_Model_DW.Input_NFCDetection1_start) && ((uint32)App_Model_DW.Input_NFCDetection1_start == On)) || ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi !=
        App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj == WPCNFCPolling_Search))) {
    sint32 b_previousEvent;
    b_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCSearchingT;
    if ((uint32)App_Model_DW.is_active_NFCSearchingTime_dso3 != 0U) {
      App_Model_NFCSearchingTimeout();
    }

    App_Model_DW.sfEvent_oymp = b_previousEvent;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void enter_atomic_OperationMode_NFC(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oymp;
  App_Model_DW.sfEvent_oymp = (sint32)event_StartTimer_NFCTimeOutConf;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_oghf != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_StartTimer_NFCSearchingTi;
  if ((uint32)App_Model_DW.is_active_NFCSearchingTime_dso3 != 0U) {
    App_Model_NFCSearchingTimeout();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCLPCDOffDe;
  if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
    App_Model_PICCLPCDOffDelay();
  }

  App_Model_DW.sfEvent_oymp = b_previousEvent;
  App_Mo_NFCSearchingOffDetection();
  App_Model_NFCDetectionCheck();
  App_Model_B.Output_OPT_WPCStatus_hxy1 = NFCMode;
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void enter_atomic_OperationMode_Picc(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oymp;
  App_Model_DW.sfEvent_oymp = (sint32)A_event_StartTimer_PICCOffDelay;
  if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
    App_Model_PICCOffDelay();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_StartTimer_PICCLPCDOffDel;
  if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
    App_Model_PICCLPCDOffDelay();
  }

  App_Model_DW.sfEvent_oymp = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus_hxy1 = PICCMode;
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_LPCDOff_Check(Bool rtu_PreProcessIn_aaws)
{
  if (((uint32)rtu_PreProcessIn_aaws == Off) && !App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_dosr) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)A_event_StartTimer_LPCDOffDelay;
    if ((uint32)App_Model_DW.is_active_LPCDOffDelay_ifkk != 0U) {
      App_Model_LPCDOffDelay();
    }

    App_Model_DW.sfEvent_oymp = c_previousEvent;
  } else if ((uint32)rtu_PreProcessIn_aaws == On) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_LPCDOffDelay;
    if ((uint32)App_Model_DW.is_active_LPCDOffDelay_ifkk != 0U) {
      App_Model_LPCDOffDelay();
    }

    App_Model_DW.sfEvent_oymp = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void enter_atomic_OperationMode_LPCD(Bool rtu_PreProcessIn_aaws)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oymp;
  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCTimeOutCon;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_oghf != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCSearchingO;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_bqo4 != 0U) {
    App_Model_NFCSearchingOffDelay();
  }

  App_Model_DW.sfEvent_oymp = b_previousEvent;

  /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
  App_Model_B.Output_OPT_WPCStatus_hxy1 = LPCDMode;
  App_Model_LPCDOff_Check(rtu_PreProcessIn_aaws);
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Model_PhnLeftChattering(void)
{
  switch (App_Model_DW.is_PhnLeftChattering_mbyg) {
   case App_Mo_IN_PhnLeftChattering_Off:
    if (App_Model_DW.sfEvent_oymp == (sint32)event_StartTimer_PhnLeftChatter) {
      App_Model_DW.is_PhnLeftChattering_mbyg = App_Mod_IN_PhnLeftChattering_On;
      App_Model_DW.b_Timer_PhnLeftChattering__jemb = true;
    }
    break;

   case App_Mod_IN_PhnLeftChattering_On:
    {
      switch (App_Model_DW.sfEvent_oymp) {
       case event_CancelTimer_PhnLeftChatte:
        App_Model_DW.is_PhnLeftChattering_mbyg = App_Mo_IN_PhnLeftChattering_Off;
        App_Model_DW.b_Timer_PhnLeftChattering__jemb = false;
        App_Model_DW.Timer_PhnLeftChattering_b34g = 0U;
        break;

       case event_StartTimer_PhnLeftChatter:
        App_Model_DW.Timer_PhnLeftChattering_b34g = 0U;
        App_Model_DW.is_PhnLeftChattering_mbyg = App_Mod_IN_PhnLeftChattering_On;
        App_Model_DW.b_Timer_PhnLeftChattering__jemb = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PhnLeftChattering_b34g + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_PhnLeftChattering_b34g + 1U) < App_Model_DW.Timer_PhnLeftChattering_b34g) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PhnLeftChattering_b34g = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void App_Mode_DrDoorPhnLeftHoldCheck(Bool rtu_PreProcessIn_aaws, Bool rtu_PreProcessIn_ksr2, C_WPCWarning rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_devb)
{
  if ((((uint32)rtu_PreProcessIn_aaws == Off) && ((uint32)rtu_PreProcessIn_n5sz == WPCWarningOff) && ((uint32)rtu_PreProcessIn_i2ub == Off) && (((App_Model_DW.Input_b_DrvDrSw_prev_mlur !=
          App_Model_DW.Input_b_DrvDrSw_start_ct1q) && ((uint32)App_Model_DW.Input_b_DrvDrSw_start_ct1q == On)) || ((App_Model_DW.Input_b_DrvDrSw_prev_mlur != App_Model_DW.Input_b_DrvDrSw_start_ct1q) &&
         ((uint32)App_Model_DW.Input_b_DrvDrSw_start_ct1q == Off)))) || ((App_Model_DW.Timer_PhnLeftChattering_b34g >= (uint32)((uint16)600U)) || ((App_Model_DW.Input_PhnLeftChk_Enable_pr_bo4w !=
         App_Model_DW.Input_PhnLeftChk_Enable_st_jbeh) && ((uint32)App_Model_DW.Input_PhnLeftChk_Enable_st_jbeh == Off)))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_oz2q = On;
    d_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PhnLeftChatte;
    if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_cku2 != 0U) {
      App_Model_PhnLeftChattering();
    }

    App_Model_DW.sfEvent_oymp = d_previousEvent;
  } else if (!App_Model_DW.b_Timer_PhnLeftChattering__jemb && ((uint32)rtu_PreProcessIn_aaws == Off) && ((uint32)rtu_PreProcessIn_n5sz == Cellphoneonthepad) && ((uint32)rtu_PreProcessIn_i2ub == On) &&
             (((uint32)rtu_PreProcessIn_ksr2 == On) || ((uint32)rtu_PreProcessIn_devb == On))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_oz2q = Off;
    d_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_StartTimer_PhnLeftChatter;
    if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_cku2 != 0U) {
      App_Model_PhnLeftChattering();
    }

    App_Model_DW.sfEvent_oymp = d_previousEvent;
  } else if ((uint32)rtu_PreProcessIn_aaws == On) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_oz2q = Off;
    d_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PhnLeftChatte;
    if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_cku2 != 0U) {
      App_Model_PhnLeftChattering();
    }

    App_Model_DW.sfEvent_oymp = d_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void enter_atomic_OperationMode_Off(Bool rtu_PreProcessIn_aaws, Bool rtu_PreProcessIn_ksr2, C_WPCWarning rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_devb)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_oymp;
  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCTimeOutCon;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_oghf != 0U) {
    App_Model_NFCTimeOutConfirm();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_NFCSearchingO;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_bqo4 != 0U) {
    App_Model_NFCSearchingOffDelay();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_LPCDOffDelay;
  if ((uint32)App_Model_DW.is_active_LPCDOffDelay_ifkk != 0U) {
    App_Model_LPCDOffDelay();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCOffDelay;
  if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
    App_Model_PICCOffDelay();
  }

  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCLPCDOffDe;
  if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
    App_Model_PICCLPCDOffDelay();
  }

  App_Model_B.Output_OPT_WPCStatus_hxy1 = ModeOff;
  App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PhnLeftChatte;
  if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_cku2 != 0U) {
    App_Model_PhnLeftChattering();
  }

  App_Model_DW.sfEvent_oymp = b_previousEvent;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_oz2q = Off;
  App_Mode_DrDoorPhnLeftHoldCheck(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);
}

/* Function for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
static void WPC_NFC_Mode_Control_Function_S(LC_IAUWPCNFCcmd rtu_PreProcessIn_crbo, Bool rtu_PreProcessIn_aaws, IAU_OwnerPhnRegRVal rtu_PreProcessIn_muxy, OwnerPairingAdvertisingReq
  rtu_PreProcessIn_ikas, C_WPCOnOffNvalueSet rtu_PreProcessIn_akvr, OnThePad rtu_PreProcessIn_etm5, Bool rtu_PreProcessIn_gvlh, Bool rtu_PreProcessIn_n1ix, WPCStatus rtu_PreProcessIn_hg1w, Bool
  rtu_PreProcessIn_ksr2, C_WPCWarning rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_mgbl, Bool rtu_PreProcessIn_devb)
{
  sint32 g_previousEvent;
  boolean guard1;
  boolean guard2;
  boolean guard3;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  switch (App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk) {
   case App_Model_IN_OperationMode_LPCD:
    {
      C_WPCOnOffNvalueSet tmp;
      App_Model_B.Output_OPT_WPCStatus_hxy1 = LPCDMode;

      /* 1 */
      tmp = App_Model_DW.Input_OPT_WPCSWOption_star_etkv;
      if ((((uint32)rtu_PreProcessIn_akvr == WPC_On) && ((uint32)rtu_PreProcessIn_aaws == On) && ((uint32)rtu_PreProcessIn_crbo != WPCNFCPolling_Search) && (((uint32)rtu_PreProcessIn_muxy ==
             OwnerPhnReg__Enable) || ((uint32)rtu_PreProcessIn_ikas != OwnerPairingAdvertisingReq__StartEnable))) || ((App_Model_DW.Input_OPT_WPCSWOption_prev_hwrz != tmp) && ((uint32)tmp == WPC_On)))
      {
        /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
        g_previousEvent = App_Model_DW.sfEvent_oymp;
        App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCLPCDOffDe;
        if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
          App_Model_PICCLPCDOffDelay();
        }

        App_Model_DW.sfEvent_oymp = g_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_WPC;
        App_Model_B.Output_OPT_WPCStatus_hxy1 = WPCMode;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 ]%SWOff_Devided */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start_mgzq;
        if (((uint32)rtu_PreProcessIn_hg1w == NFCMode) || ((App_Model_DW.INT_LPCDWakeUpOrder_prev_oeow != App_Model_DW.INT_LPCDWakeUpOrder_start_fpfa) && (App_Model_DW.INT_LPCDWakeUpOrder_start_fpfa ==
              2U)) || ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev_l14g != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) || (((uint32)rtu_PreProcessIn_aaws == On) && ((uint32)rtu_PreProcessIn_ikas !=
              OwnerPairingAdvertisingReq__StartEnable) && ((uint32)rtu_PreProcessIn_akvr == WPC_Off) && ((uint32)rtu_PreProcessIn_hg1w != PICCMode))) {
          /* Prevention of oscillation
             SWOffDevided */
          guard1 = true;
        } else {
          /* 3 */
          /* 4 */
          tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj;
          if (((App_Model_DW.INT_LPCDWakeUpOrder_prev_oeow != App_Model_DW.INT_LPCDWakeUpOrder_start_fpfa) && (App_Model_DW.INT_LPCDWakeUpOrder_start_fpfa == 1U)) ||
              ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) || ((App_Model_DW.Input_b_IGN1_IN_prev_i5bk != App_Model_DW.Input_b_IGN1_IN_start_pxr5)
               && ((uint32)App_Model_DW.Input_b_IGN1_IN_start_pxr5 == On))) {
            /* SWOffDevided */
            /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
            g_previousEvent = App_Model_DW.sfEvent_oymp;
            App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCLPCDOffDe;
            if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
              App_Model_PICCLPCDOffDelay();
            }

            App_Model_DW.sfEvent_oymp = g_previousEvent;
            App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_NFC;
            enter_atomic_OperationMode_NFC();
          } else {
            WPCStatus tmp_1;

            /* 5 */
            tmp_1 = App_Model_DW.INT_OPT_WPCStatus_2_start;
            if (((uint32)rtu_PreProcessIn_aaws == Off) && ((App_Model_DW.Timer_LPCDOffDelay_gyxl >= (uint32)((uint16)6000U)) || (App_Model_DW.Timer_PICCLPCDOffDelay_gv4z >= (uint32)((uint16)6000U)) ||
                 ((App_Model_DW.INT_OPT_WPCStatus_2_prev != tmp_1) && ((uint32)tmp_1 == ModeOff)))) {
              /* Simultaneously */
              guard1 = true;
            } else {
              /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
               *  ActionPort: '<S196>/ActionPort'
               */
              /* SwitchCase: '<S189>/Switch Case' incorporates:
               *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
               */
              App_Model_LPCDOff_Check(rtu_PreProcessIn_aaws);

              /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
            }
          }
        }
      }
    }
    break;

   case App_Model_IN_OperationMode_NFC:
    {
      LC_IAUWPCNFCcmd tmp_0;
      App_Model_B.Output_OPT_WPCStatus_hxy1 = NFCMode;

      /* 1 */
      tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj;
      if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) {
        A_exit_atomic_OperationMode_NFC();
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_NFC;
        enter_atomic_OperationMode_NFC();
      } else {
        /* 2%WPC2Lead, WPC1Follow or WPC2NFCOnly */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start_mgzq;

        /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S196>/ActionPort'
         */
        /* SwitchCase: '<S189>/Switch Case' incorporates:
         *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
         */
        if ((((uint32)rtu_PreProcessIn_hg1w == NFCMode) && ((App_Model_DW.INT_NFCDetectOrder_prev_epmy != App_Model_DW.INT_NFCDetectOrder_start_ijca) && (App_Model_DW.INT_NFCDetectOrder_start_ijca ==
               2U))) || ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev_l14g != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search))) {
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Off;
          enter_atomic_OperationMode_Off(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);

          /* 30.5s60s */
        } else if (((uint32)rtu_PreProcessIn_aaws == On) && ((uint32)rtu_PreProcessIn_akvr == WPC_On) && ((App_Model_DW.Timer_NFCSearchingOffDelay_cpfz >= (uint32)((uint8)50U)) ||
                    (App_Model_DW.Timer_NFCTimeOutConfirm_gx3p >= (uint32)((uint16)6000U)) || (App_Model_DW.Timer_NFCSearchingTimeout_odwm >= (uint32)((uint16)150U)))) {
          /* 1.5 */
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_WPC;
          App_Model_B.Output_OPT_WPCStatus_hxy1 = WPCMode;

          /* 4 */
        } else if ((((uint32)rtu_PreProcessIn_aaws == Off) && (App_Model_DW.Timer_NFCSearchingOffDelay_cpfz >= (uint32)((uint8)50U))) || (((uint32)rtu_PreProcessIn_aaws == On) && ((uint32)
                     rtu_PreProcessIn_akvr == WPC_Off) && (App_Model_DW.Timer_NFCSearchingOffDelay_cpfz >= (uint32)((uint8)50U)))) {
          /* 0.5s */
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Picc;
          enter_atomic_OperationMode_Picc();

          /* 5 */
          /* 60.5s60s */
        } else if ((App_Model_DW.Timer_NFCSearchingOffDelay_cpfz >= (uint32)((uint8)50U)) || (App_Model_DW.Timer_NFCTimeOutConfirm_gx3p >= (uint32)((uint16)6000U)) ||
                   (App_Model_DW.Timer_NFCSearchingTimeout_odwm >= (uint32)((uint16)150U))) {
          /* 1.5 */
          A_exit_atomic_OperationMode_NFC();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_LPCD;
          enter_atomic_OperationMode_LPCD(rtu_PreProcessIn_aaws);
        } else {
          App_Mo_NFCSearchingOffDetection();
          App_Model_NFCDetectionCheck();
        }

        /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
      }
    }
    break;

   case App_Model_IN_OperationMode_Off:
    {
      WPCStatus tmp_1;
      App_Model_B.Output_OPT_WPCStatus_hxy1 = ModeOff;

      /* 1 */
      tmp_1 = App_Model_DW.INT_OPT_WPCStatus_2_prev;

      /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S196>/ActionPort'
       */
      /* SwitchCase: '<S189>/Switch Case' incorporates:
       *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
       */
      if (((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && ((uint32)tmp_1 == NFCMode) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_2_start ==
             LPCDMode))) || (((App_Model_DW.Var_DrDoorPhnLftHoldComple_ncdi != App_Model_DW.Var_DrDoorPhnLftHoldComple_g343) && (App_Model_DW.Var_DrDoorPhnLftHoldComple_g343 == On)) || (((uint32)
             rtu_PreProcessIn_aaws == On) && ((uint32)rtu_PreProcessIn_ikas == OwnerPairingAdvertisingReq__StartEnable) && ((uint32)rtu_PreProcessIn_akvr == WPC_Off) && ((uint32)rtu_PreProcessIn_hg1w ==
             ModeOff)))) {
        /* WPC1ChangeOff2LPCD,WhenWPC2ChangeNFC2LPCD */
        /* BothOffModeStartEnable */
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_LPCD;
        enter_atomic_OperationMode_LPCD(rtu_PreProcessIn_aaws);

        /* 2 */
        /* 3 */
      } else if ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_2_start == PICCMode)) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Picc;
        enter_atomic_OperationMode_Picc();

        /* 4 */
      } else if ((uint32)rtu_PreProcessIn_crbo == WPCNFCPolling_Search) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_NFC;
        enter_atomic_OperationMode_NFC();

        /* 5 */
      } else if (((uint32)rtu_PreProcessIn_aaws == On) && ((uint32)rtu_PreProcessIn_akvr == WPC_On) && ((uint32)rtu_PreProcessIn_hg1w != NFCMode)) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_WPC;
        App_Model_B.Output_OPT_WPCStatus_hxy1 = WPCMode;
      } else {
        App_Mode_DrDoorPhnLeftHoldCheck(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);
      }

      /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
    }
    break;

   case App_Model_IN_OperationMode_Picc:
    {
      App_Model_B.Output_OPT_WPCStatus_hxy1 = PICCMode;

      /* 1 */
      if ((uint32)rtu_PreProcessIn_gvlh == On) {
        /* NFC1 & 2 OnThePad_Off */
        /* PhnRemoveMode */
        g_previousEvent = App_Model_DW.sfEvent_oymp;
        App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCOffDelay;
        if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
          App_Model_PICCOffDelay();
        }

        App_Model_DW.sfEvent_oymp = g_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_LPCD;

        /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S196>/ActionPort'
         */
        /* SwitchCase: '<S189>/Switch Case' incorporates:
         *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
         */
        enter_atomic_OperationMode_LPCD(rtu_PreProcessIn_aaws);

        /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */

        /* 2 */
      } else if (((uint32)rtu_PreProcessIn_aaws == Off) && (App_Model_DW.Timer_PICCOffDelay_eypp >= (uint32)((uint16)6000U))) {
        guard2 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 3 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) {
          /* PhnRemoveMode */
          g_previousEvent = App_Model_DW.sfEvent_oymp;
          App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCOffDelay;
          if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
            App_Model_PICCOffDelay();
          }

          App_Model_DW.sfEvent_oymp = g_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_NFC;
          enter_atomic_OperationMode_NFC();

          /* 45sec */
        } else if (((uint32)rtu_PreProcessIn_aaws == On) && ((uint32)rtu_PreProcessIn_akvr == WPC_On) && (((uint32)rtu_PreProcessIn_etm5 == OnThePad_On) || (((uint32)rtu_PreProcessIn_etm5 ==
                      OnThePad_Default) && (App_Model_DW.Timer_PICCOffDelay_eypp >= (uint32)((uint16)500U))) || ((uint32)rtu_PreProcessIn_hg1w == WPCMode))) {
          /* TransitionMerge */
          /* PhnRemoveMode */
          g_previousEvent = App_Model_DW.sfEvent_oymp;
          App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCOffDelay;
          if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
            App_Model_PICCOffDelay();
          }

          App_Model_DW.sfEvent_oymp = g_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_WPC;
          App_Model_B.Output_OPT_WPCStatus_hxy1 = WPCMode;
        } else {
          WPCStatus tmp_1;

          /* 5Simultenously ModeOff */
          tmp_1 = App_Model_DW.INT_OPT_WPCStatus_2_prev;
          if ((((uint32)rtu_PreProcessIn_aaws == Off) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_2_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_2_start == ModeOff))) || ((tmp_1 !=
                App_Model_DW.INT_OPT_WPCStatus_2_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_2_start == NFCMode)) || (((uint32)rtu_PreProcessIn_akvr == WPC_Off) && (((uint32)
                 rtu_PreProcessIn_hg1w == WPCMode) || (App_Model_DW.Timer_PICCOffDelay_eypp >= (uint32)((uint16)6000U))))) {
            /* WPCSWOffALL_Case */
            guard2 = true;
          } else {
            /* 6%WPCSWOption_Off Case */
          }
        }
      }
    }
    break;

   case App_Model_IN_OperationMode_WPC:
    {
      App_Model_B.Output_OPT_WPCStatus_hxy1 = WPCMode;

      /* 1 */
      if ((uint32)rtu_PreProcessIn_hg1w == LPCDMode) {
        /* WhileWPC2isSWOff, WPC2MoveFromOFFtoLPCD */
        guard3 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search) && ((uint32)rtu_PreProcessIn_hg1w != NFCMode)) {
          /* WaitingforNFCCom */
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_NFC;
          enter_atomic_OperationMode_NFC();

          /* 3%When WPC1&2 are Both ChargingOnThePad_Off || ObjectOnthePad_Off */
        } else if ((((uint32)rtu_PreProcessIn_n1ix == On) || ((uint32)rtu_PreProcessIn_mgbl == On)) && (((uint32)rtu_PreProcessIn_muxy == OwnerPhnReg__Disable) || ((uint32)rtu_PreProcessIn_muxy ==
                     OwnerPhnReg__Default) || ((uint32)rtu_PreProcessIn_muxy == OwnerPhnReg__Invalid)) && ((uint32)rtu_PreProcessIn_ikas == OwnerPairingAdvertisingReq__StartEnable)) {
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Picc;
          enter_atomic_OperationMode_Picc();

          /* 4 */
        } else if (((uint32)rtu_PreProcessIn_aaws == Off) || ((uint32)rtu_PreProcessIn_akvr == WPC_Off) || ((uint32)rtu_PreProcessIn_hg1w == NFCMode)) {
          /* PollingSearchDivided */
          guard3 = true;
        } else {
          /* no actions */
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }

  if (guard3) {
    App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Off;

    /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S196>/ActionPort'
     */
    /* SwitchCase: '<S189>/Switch Case' incorporates:
     *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
     */
    enter_atomic_OperationMode_Off(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);

    /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
  }

  if (guard2) {
    /* PhnRemoveMode */
    g_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCOffDelay;
    if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
      App_Model_PICCOffDelay();
    }

    App_Model_DW.sfEvent_oymp = g_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Off;

    /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S196>/ActionPort'
     */
    /* SwitchCase: '<S189>/Switch Case' incorporates:
     *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
     */
    enter_atomic_OperationMode_Off(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);

    /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
  }

  if (guard1) {
    /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
    g_previousEvent = App_Model_DW.sfEvent_oymp;
    App_Model_DW.sfEvent_oymp = (sint32)event_CancelTimer_PICCLPCDOffDe;
    if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
      App_Model_PICCLPCDOffDelay();
    }

    App_Model_DW.sfEvent_oymp = g_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Off;

    /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S196>/ActionPort'
     */
    /* SwitchCase: '<S189>/Switch Case' incorporates:
     *  Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10'
     */
    enter_atomic_OperationMode_Off(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);

    /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
  }
}

/* System initialize for atomic system: '<S23>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Funct_Init(WPCStatus *rty_WPCStatus)
{
  /* SystemInitialize for IfAction SubSystem: '<S189>/WPC_Mode_Control' */
  App_Model_WPC_Mode_Control_Init(&App_Model_DW.WPC_Mode_Control);

  /* End of SystemInitialize for SubSystem: '<S189>/WPC_Mode_Control' */

  /* SystemInitialize for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' */
  /* SystemInitialize for Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
  App_Model_DW.sfEvent_oymp = (sint32)App_Model_CALL_EVENT_myt0;
  App_Model_DW.is_active_LPCDOffDelay_ifkk = 0U;
  App_Model_DW.is_LPCDOffDelay_mznd = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_NFCSearchingOffD_bqo4 = 0U;
  App_Model_DW.is_NFCSearchingOffDelay_f1ei = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_NFCSearchingTime_dso3 = 0U;
  App_Model_DW.is_NFCSearchingTimeout_gbui = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_NFCTimeOutConfir_oghf = 0U;
  App_Model_DW.is_NFCTimeOutConfirm_mnmy = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_PICCLPCDOffDelay_eekm = 0U;
  App_Model_DW.is_PICCLPCDOffDelay_cx0h = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_PICCOffDelay_bhdm = 0U;
  App_Model_DW.is_PICCOffDelay_e1ym = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_PhnLeftChatterin_cku2 = 0U;
  App_Model_DW.is_PhnLeftChattering_mbyg = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_WPC_NFC_Mode_Con_cpti = 0U;
  App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Mod_IN_NO_ACTIVE_CHILD_e3xy;
  App_Model_DW.is_active_c50_NFC_WPC_Mode_Cont = 0U;
  App_Model_DW.Timer_NFCTimeOutConfirm_gx3p = 0U;
  App_Model_DW.Timer_NFCSearchingOffDelay_cpfz = 0U;
  App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_dosr = false;
  App_Model_DW.Timer_LPCDOffDelay_gyxl = 0U;
  App_Model_DW.Timer_NFCSearchingTimeout_odwm = 0U;
  App_Model_DW.Timer_PICCOffDelay_eypp = 0U;
  App_Model_DW.Timer_PICCLPCDOffDelay_gv4z = 0U;
  App_Model_DW.b_Timer_PhnLeftChattering__jemb = false;
  App_Model_DW.Timer_PhnLeftChattering_b34g = 0U;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_oz2q = 0U;
  App_Model_B.Output_OPT_WPCStatus_hxy1 = ModeOff;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_ncdi = 0U;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_g343 = 0U;
  App_Model_DW.Input_NFCDetection1_prev = NFCDetection_Off;
  App_Model_DW.Input_NFCDetection1_start = NFCDetection_Off;
  App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_b_DrvDrSw_prev_mlur = Off;
  App_Model_DW.Input_b_DrvDrSw_start_ct1q = Off;
  App_Model_DW.Input_PhnLeftChk_Enable_pr_bo4w = Off;
  App_Model_DW.Input_PhnLeftChk_Enable_st_jbeh = Off;
  App_Model_DW.INT_OPT_WPCStatus_2_prev = ModeOff;
  App_Model_DW.INT_OPT_WPCStatus_2_start = ModeOff;
  App_Model_DW.Input_IAUWPCNFCcmd_2_prev_l14g = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_IAUWPCNFCcmd_2_start_mgzq = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_b_IGN1_IN_prev_i5bk = Off;
  App_Model_DW.Input_b_IGN1_IN_start_pxr5 = Off;
  App_Model_DW.Input_OPT_WPCSWOption_prev_hwrz = WPC_On;
  App_Model_DW.Input_OPT_WPCSWOption_star_etkv = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S189>/WPC_NFCModeControl_compact' */

  /* SystemInitialize for Merge: '<S189>/Merge' */
  *rty_WPCStatus = ModeOff;
}

/* Output and update for atomic system: '<S23>/NFC_WPC_Mode_Control_Function' */
void A_NFC_WPC_Mode_Control_Function(Bool rtu_PreProcessIn, LC_IAUWPCNFCcmd rtu_PreProcessIn_crbo, LC_IAUWPCNFCcmd rtu_PreProcessIn_p45h, Bool rtu_PreProcessIn_aaws, IAU_OwnerPhnRegRVal
  rtu_PreProcessIn_muxy, OwnerPairingAdvertisingReq rtu_PreProcessIn_ikas, C_WPCOnOffNvalueSet rtu_PreProcessIn_akvr, OnThePad rtu_PreProcessIn_etm5, LC_WPC_NFCDetection rtu_PreProcessIn_h3gr, Bool
  rtu_PreProcessIn_gvlh, Bool rtu_PreProcessIn_n1ix, WPCStatus rtu_PreProcessIn_hg1w, uint8 rtu_PreProcessIn_gomz, uint8 rtu_PreProcessIn_mc4r, Bool rtu_PreProcessIn_ksr2, C_WPCWarning
  rtu_PreProcessIn_n5sz, Bool rtu_PreProcessIn_i2ub, Bool rtu_PreProcessIn_mgbl, Bool rtu_PreProcessIn_devb, Bool rtu_PreProcessIn_k524, WPCStatus *rty_WPCStatus)
{
  /* SwitchCase: '<S189>/Switch Case' */
  switch (rtu_PreProcessIn) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S189>/WPC_Mode_Control' incorporates:
     *  ActionPort: '<S195>/ActionPort'
     */
    App_Model_WPC_Mode_Control(rtu_PreProcessIn_aaws, rtu_PreProcessIn_akvr, rtu_PreProcessIn_k524, rty_WPCStatus, &App_Model_DW.WPC_Mode_Control);

    /* End of Outputs for SubSystem: '<S189>/WPC_Mode_Control' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S189>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S196>/ActionPort'
     */
    /* Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */
    App_Model_DW.sfEvent_oymp = (sint32)App_Model_CALL_EVENT_myt0;
    App_Model_DW.Input_NFCDetection1_prev = App_Model_DW.Input_NFCDetection1_start;
    App_Model_DW.Input_NFCDetection1_start = rtu_PreProcessIn_h3gr;
    App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi = App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj;
    App_Model_DW.Input_IAUWPCNFCcmd_1_start_dxlj = rtu_PreProcessIn_crbo;
    App_Model_DW.Input_b_DrvDrSw_prev_mlur = App_Model_DW.Input_b_DrvDrSw_start_ct1q;
    App_Model_DW.Input_b_DrvDrSw_start_ct1q = rtu_PreProcessIn_ksr2;
    App_Model_DW.Input_PhnLeftChk_Enable_pr_bo4w = App_Model_DW.Input_PhnLeftChk_Enable_st_jbeh;
    App_Model_DW.Input_PhnLeftChk_Enable_st_jbeh = rtu_PreProcessIn_i2ub;
    App_Model_DW.INT_OPT_WPCStatus_2_prev = App_Model_DW.INT_OPT_WPCStatus_2_start;
    App_Model_DW.INT_OPT_WPCStatus_2_start = rtu_PreProcessIn_hg1w;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_ncdi = App_Model_DW.Var_DrDoorPhnLftHoldComple_g343;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_g343 = App_Model_DW.Var_DrDoorPhnLftHoldComple_oz2q;
    App_Model_DW.INT_LPCDWakeUpOrder_prev_oeow = App_Model_DW.INT_LPCDWakeUpOrder_start_fpfa;
    App_Model_DW.INT_LPCDWakeUpOrder_start_fpfa = rtu_PreProcessIn_gomz;
    App_Model_DW.Input_IAUWPCNFCcmd_2_prev_l14g = App_Model_DW.Input_IAUWPCNFCcmd_2_start_mgzq;
    App_Model_DW.Input_IAUWPCNFCcmd_2_start_mgzq = rtu_PreProcessIn_p45h;
    App_Model_DW.Input_b_IGN1_IN_prev_i5bk = App_Model_DW.Input_b_IGN1_IN_start_pxr5;
    App_Model_DW.Input_b_IGN1_IN_start_pxr5 = rtu_PreProcessIn_aaws;
    App_Model_DW.Input_OPT_WPCSWOption_prev_hwrz = App_Model_DW.Input_OPT_WPCSWOption_star_etkv;
    App_Model_DW.Input_OPT_WPCSWOption_star_etkv = rtu_PreProcessIn_akvr;
    App_Model_DW.INT_NFCDetectOrder_prev_epmy = App_Model_DW.INT_NFCDetectOrder_start_ijca;
    App_Model_DW.INT_NFCDetectOrder_start_ijca = rtu_PreProcessIn_mc4r;
    if ((uint32)App_Model_DW.is_active_c50_NFC_WPC_Mode_Cont == 0U) {
      App_Model_DW.Input_NFCDetection1_prev = rtu_PreProcessIn_h3gr;
      App_Model_DW.Input_IAUWPCNFCcmd_1_prev_jfxi = rtu_PreProcessIn_crbo;
      App_Model_DW.Input_b_DrvDrSw_prev_mlur = rtu_PreProcessIn_ksr2;
      App_Model_DW.Input_PhnLeftChk_Enable_pr_bo4w = rtu_PreProcessIn_i2ub;
      App_Model_DW.INT_OPT_WPCStatus_2_prev = rtu_PreProcessIn_hg1w;
      App_Model_DW.INT_LPCDWakeUpOrder_prev_oeow = rtu_PreProcessIn_gomz;
      App_Model_DW.Input_IAUWPCNFCcmd_2_prev_l14g = rtu_PreProcessIn_p45h;
      App_Model_DW.Input_b_IGN1_IN_prev_i5bk = rtu_PreProcessIn_aaws;
      App_Model_DW.Input_OPT_WPCSWOption_prev_hwrz = rtu_PreProcessIn_akvr;
      App_Model_DW.INT_NFCDetectOrder_prev_epmy = rtu_PreProcessIn_mc4r;
      App_Model_DW.is_active_c50_NFC_WPC_Mode_Cont = 1U;
      App_Model_DW.is_active_NFCTimeOutConfir_oghf = 1U;
      App_Model_DW.is_NFCTimeOutConfirm_mnmy = App_Mo_IN_NFCTimeOutConfirm_Off;
      App_Model_DW.Timer_NFCTimeOutConfirm_gx3p = 0U;
      App_Model_DW.is_active_NFCSearchingOffD_bqo4 = 1U;
      App_Model_DW.is_NFCSearchingOffDelay_f1ei = App_IN_NFCSearchingOffDelay_Off;
      App_Model_DW.Timer_NFCSearchingOffDelay_cpfz = 0U;
      App_Model_DW.is_active_LPCDOffDelay_ifkk = 1U;
      App_Model_DW.is_LPCDOffDelay_mznd = App_Model_IN_LPCDOffDelay_Off;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_dosr = false;
      App_Model_DW.Timer_LPCDOffDelay_gyxl = 0U;
      App_Model_DW.is_active_NFCSearchingTime_dso3 = 1U;
      App_Model_DW.is_NFCSearchingTimeout_gbui = App__IN_NFCSearchingTimeout_Off;
      App_Model_DW.Timer_NFCSearchingTimeout_odwm = 0U;
      App_Model_DW.is_active_PICCOffDelay_bhdm = 1U;
      App_Model_DW.is_PICCOffDelay_e1ym = App_Model_IN_PICCOffDelay_Off;
      App_Model_DW.Timer_PICCOffDelay_eypp = 0U;
      App_Model_DW.is_active_WPC_NFC_Mode_Con_cpti = 1U;

      /* Default */
      App_Model_DW.is_WPC_NFC_Mode_Control_Fu_kerk = App_Model_IN_OperationMode_Off;
      enter_atomic_OperationMode_Off(rtu_PreProcessIn_aaws, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_devb);
      App_Model_DW.is_active_PICCLPCDOffDelay_eekm = 1U;
      App_Model_DW.is_PICCLPCDOffDelay_cx0h = App_Mod_IN_PICCLPCDOffDelay_Off;
      App_Model_DW.Timer_PICCLPCDOffDelay_gv4z = 0U;
      App_Model_DW.is_active_PhnLeftChatterin_cku2 = 1U;
      App_Model_DW.is_PhnLeftChattering_mbyg = App_Mo_IN_PhnLeftChattering_Off;
      App_Model_DW.b_Timer_PhnLeftChattering__jemb = false;
      App_Model_DW.Timer_PhnLeftChattering_b34g = 0U;
    } else {
      if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_oghf != 0U) {
        App_Model_NFCTimeOutConfirm();
      }

      if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_bqo4 != 0U) {
        App_Model_NFCSearchingOffDelay();
      }

      if ((uint32)App_Model_DW.is_active_LPCDOffDelay_ifkk != 0U) {
        App_Model_LPCDOffDelay();
      }

      if ((uint32)App_Model_DW.is_active_NFCSearchingTime_dso3 != 0U) {
        App_Model_NFCSearchingTimeout();
      }

      if ((uint32)App_Model_DW.is_active_PICCOffDelay_bhdm != 0U) {
        App_Model_PICCOffDelay();
      }

      if ((uint32)App_Model_DW.is_active_WPC_NFC_Mode_Con_cpti != 0U) {
        WPC_NFC_Mode_Control_Function_S(rtu_PreProcessIn_crbo, rtu_PreProcessIn_aaws, rtu_PreProcessIn_muxy, rtu_PreProcessIn_ikas, rtu_PreProcessIn_akvr, rtu_PreProcessIn_etm5, rtu_PreProcessIn_gvlh,
          rtu_PreProcessIn_n1ix, rtu_PreProcessIn_hg1w, rtu_PreProcessIn_ksr2, rtu_PreProcessIn_n5sz, rtu_PreProcessIn_i2ub, rtu_PreProcessIn_mgbl, rtu_PreProcessIn_devb);
      }

      if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay_eekm != 0U) {
        App_Model_PICCLPCDOffDelay();
      }

      if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_cku2 != 0U) {
        App_Model_PhnLeftChattering();
      }
    }

    /* End of Chart: '<S196>/NFC_WPC_Mode_Control_DWPC1_r10' */

    /* SignalConversion: '<S196>/Signal Conversion1' */
    *rty_WPCStatus = App_Model_B.Output_OPT_WPCStatus_hxy1;

    /* End of Outputs for SubSystem: '<S189>/WPC_NFCModeControl_compact' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S189>/Switch Case' */
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Mode_NFCTimeOutConfirm_ahni(void)
{
  switch (App_Model_DW.is_NFCTimeOutConfirm_eole) {
   case A_IN_NFCTimeOutConfirm_Off_ixfd:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_NFCTimeOu_h3lj) {
      App_Model_DW.is_NFCTimeOutConfirm_eole = Ap_IN_NFCTimeOutConfirm_On_jhuc;
    }
    break;

   case Ap_IN_NFCTimeOutConfirm_On_jhuc:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_NFCTimeO_kvrm:
        App_Model_DW.is_NFCTimeOutConfirm_eole = A_IN_NFCTimeOutConfirm_Off_ixfd;
        App_Model_DW.Timer_NFCTimeOutConfirm_lajm = 0U;
        break;

       case event_StartTimer_NFCTimeOu_h3lj:
        App_Model_DW.Timer_NFCTimeOutConfirm_lajm = 0U;
        App_Model_DW.is_NFCTimeOutConfirm_eole = Ap_IN_NFCTimeOutConfirm_On_jhuc;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCTimeOutConfirm_lajm + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCTimeOutConfirm_lajm + 1U) < App_Model_DW.Timer_NFCTimeOutConfirm_lajm) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCTimeOutConfirm_lajm = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_M_NFCSearchingOffDelay_arjk(void)
{
  switch (App_Model_DW.is_NFCSearchingOffDelay_hdu2) {
   case IN_NFCSearchingOffDelay_Of_hze2:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_NFCSearch_ded4) {
      App_Model_DW.is_NFCSearchingOffDelay_hdu2 = IN_NFCSearchingOffDelay_On_pz0z;
    }
    break;

   case IN_NFCSearchingOffDelay_On_pz0z:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_NFCSearc_c2ga:
        App_Model_DW.is_NFCSearchingOffDelay_hdu2 = IN_NFCSearchingOffDelay_Of_hze2;
        App_Model_DW.Timer_NFCSearchingOffDelay_n2sf = 0U;
        break;

       case event_StartTimer_NFCSearch_ded4:
        App_Model_DW.Timer_NFCSearchingOffDelay_n2sf = 0U;
        App_Model_DW.is_NFCSearchingOffDelay_hdu2 = IN_NFCSearchingOffDelay_On_pz0z;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingOffDelay_n2sf + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCSearchingOffDelay_n2sf + 1U) < App_Model_DW.Timer_NFCSearchingOffDelay_n2sf) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingOffDelay_n2sf = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Model_LPCDOffDelay_fxbc(void)
{
  switch (App_Model_DW.is_LPCDOffDelay_eagi) {
   case App_Mo_IN_LPCDOffDelay_Off_cqlg:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_LPCDOffDe_bu05) {
      App_Model_DW.is_LPCDOffDelay_eagi = App_Mod_IN_LPCDOffDelay_On_m41w;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_osxv = true;
    }
    break;

   case App_Mod_IN_LPCDOffDelay_On_m41w:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_LPCDOffD_ilej:
        App_Model_DW.is_LPCDOffDelay_eagi = App_Mo_IN_LPCDOffDelay_Off_cqlg;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_osxv = false;
        App_Model_DW.Timer_LPCDOffDelay_fppw = 0U;
        break;

       case event_StartTimer_LPCDOffDe_bu05:
        App_Model_DW.Timer_LPCDOffDelay_fppw = 0U;
        App_Model_DW.is_LPCDOffDelay_eagi = App_Mod_IN_LPCDOffDelay_On_m41w;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_osxv = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPCDOffDelay_fppw + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_LPCDOffDelay_fppw + 1U) < App_Model_DW.Timer_LPCDOffDelay_fppw) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPCDOffDelay_fppw = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Mo_NFCSearchingTimeout_kj53(void)
{
  switch (App_Model_DW.is_NFCSearchingTimeout_jmpa) {
   case IN_NFCSearchingTimeout_Off_c0qf:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_NFCSearch_ec4y) {
      App_Model_DW.is_NFCSearchingTimeout_jmpa = IN_NFCSearchingTimeout_On_cogw;
    }
    break;

   case IN_NFCSearchingTimeout_On_cogw:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_NFCSearc_dvmb:
        App_Model_DW.is_NFCSearchingTimeout_jmpa = IN_NFCSearchingTimeout_Off_c0qf;
        App_Model_DW.Timer_NFCSearchingTimeout_a3sf = 0U;
        break;

       case event_StartTimer_NFCSearch_ec4y:
        App_Model_DW.Timer_NFCSearchingTimeout_a3sf = 0U;
        App_Model_DW.is_NFCSearchingTimeout_jmpa = IN_NFCSearchingTimeout_On_cogw;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingTimeout_a3sf + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCSearchingTimeout_a3sf + 1U) < App_Model_DW.Timer_NFCSearchingTimeout_a3sf) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingTimeout_a3sf = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Model_PICCOffDelay_jd1b(void)
{
  switch (App_Model_DW.is_PICCOffDelay_ajiq) {
   case App_Mo_IN_PICCOffDelay_Off_c24o:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_PICCOffDe_m15j) {
      App_Model_DW.is_PICCOffDelay_ajiq = App_Mod_IN_PICCOffDelay_On_allk;
    }
    break;

   case App_Mod_IN_PICCOffDelay_On_allk:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_PICCOffD_njj0:
        App_Model_DW.is_PICCOffDelay_ajiq = App_Mo_IN_PICCOffDelay_Off_c24o;
        App_Model_DW.Timer_PICCOffDelay_dxdj = 0U;
        break;

       case event_StartTimer_PICCOffDe_m15j:
        App_Model_DW.Timer_PICCOffDelay_dxdj = 0U;
        App_Model_DW.is_PICCOffDelay_ajiq = App_Mod_IN_PICCOffDelay_On_allk;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCOffDelay_dxdj + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_PICCOffDelay_dxdj + 1U) < App_Model_DW.Timer_PICCOffDelay_dxdj) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCOffDelay_dxdj = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void exit_atomic_OperationMode__ajbt(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_b4nk;
  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCTimeO_kvrm;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_msri != 0U) {
    App_Mode_NFCTimeOutConfirm_ahni();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCSearc_c2ga;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_poei != 0U) {
    App_M_NFCSearchingOffDelay_arjk();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCSearc_dvmb;
  if ((uint32)App_Model_DW.is_active_NFCSearchingTime_ixhk != 0U) {
    App_Mo_NFCSearchingTimeout_kj53();
  }

  App_Model_DW.sfEvent_b4nk = b_previousEvent;
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Model_PICCLPCDOffDelay_ec34(void)
{
  switch (App_Model_DW.is_PICCLPCDOffDelay) {
   case Ap_IN_PICCLPCDOffDelay_Off_chhf:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_PICCLPCDO_av1s) {
      App_Model_DW.is_PICCLPCDOffDelay = App_IN_PICCLPCDOffDelay_On_eouc;
    }
    break;

   case App_IN_PICCLPCDOffDelay_On_eouc:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_PICCLPCD_c4rd:
        App_Model_DW.is_PICCLPCDOffDelay = Ap_IN_PICCLPCDOffDelay_Off_chhf;
        App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
        break;

       case event_StartTimer_PICCLPCDO_av1s:
        App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
        App_Model_DW.is_PICCLPCDOffDelay = App_IN_PICCLPCDOffDelay_On_eouc;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PICCLPCDOffDelay + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_PICCLPCDOffDelay + 1U) < App_Model_DW.Timer_PICCLPCDOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PICCLPCDOffDelay = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void A_NFCSearchingOffDetection_cknw(void)
{
  if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != App_Model_DW.Input_IAUWPCNFCcmd_2_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_2_start == WPCNFCDeselect_Stop)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_NFCSearch_ded4;
    if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_poei != 0U) {
      App_M_NFCSearchingOffDelay_arjk();
    }

    App_Model_DW.sfEvent_b4nk = c_previousEvent;
  } else if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != App_Model_DW.Input_IAUWPCNFCcmd_2_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_2_start == WPCNFCPolling_Search)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCSearc_c2ga;
    if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_poei != 0U) {
      App_M_NFCSearchingOffDelay_arjk();
    }

    App_Model_DW.sfEvent_b4nk = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Mode_NFCDetectionCheck_cmxs(void)
{
  if (((App_Model_DW.Input_NFCDetection2_prev != App_Model_DW.Input_NFCDetection2_start) && ((uint32)App_Model_DW.Input_NFCDetection2_start == On)) || ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev !=
        App_Model_DW.Input_IAUWPCNFCcmd_2_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_2_start == WPCNFCPolling_Search))) {
    sint32 b_previousEvent;
    b_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCSearc_dvmb;
    if ((uint32)App_Model_DW.is_active_NFCSearchingTime_ixhk != 0U) {
      App_Mo_NFCSearchingTimeout_kj53();
    }

    App_Model_DW.sfEvent_b4nk = b_previousEvent;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void enter_atomic_OperationMode_gr2j(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_b4nk;
  App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_NFCTimeOu_h3lj;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_msri != 0U) {
    App_Mode_NFCTimeOutConfirm_ahni();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_NFCSearch_ec4y;
  if ((uint32)App_Model_DW.is_active_NFCSearchingTime_ixhk != 0U) {
    App_Mo_NFCSearchingTimeout_kj53();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCLPCD_c4rd;
  if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
    App_Model_PICCLPCDOffDelay_ec34();
  }

  App_Model_DW.sfEvent_b4nk = b_previousEvent;
  A_NFCSearchingOffDetection_cknw();
  App_Mode_NFCDetectionCheck_cmxs();
  App_Model_B.Output_OPT_WPCStatus_fwza = NFCMode;
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void enter_atomic_OperationMode_ejig(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_b4nk;
  App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_PICCOffDe_m15j;
  if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
    App_Model_PICCOffDelay_jd1b();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_PICCLPCDO_av1s;
  if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
    App_Model_PICCLPCDOffDelay_ec34();
  }

  App_Model_DW.sfEvent_b4nk = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus_fwza = PICCMode;
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Model_LPCDOff_Check_fbyv(Bool rtu_PreProcessIn_cqtq)
{
  if (((uint32)rtu_PreProcessIn_cqtq == Off) && !App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_osxv) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_LPCDOffDe_bu05;
    if ((uint32)App_Model_DW.is_active_LPCDOffDelay_bjkw != 0U) {
      App_Model_LPCDOffDelay_fxbc();
    }

    App_Model_DW.sfEvent_b4nk = c_previousEvent;
  } else if ((uint32)rtu_PreProcessIn_cqtq == On) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_LPCDOffD_ilej;
    if ((uint32)App_Model_DW.is_active_LPCDOffDelay_bjkw != 0U) {
      App_Model_LPCDOffDelay_fxbc();
    }

    App_Model_DW.sfEvent_b4nk = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void enter_atomic_OperationMode_f4nq(Bool rtu_PreProcessIn_cqtq)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_b4nk;
  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCTimeO_kvrm;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_msri != 0U) {
    App_Mode_NFCTimeOutConfirm_ahni();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCSearc_c2ga;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_poei != 0U) {
    App_M_NFCSearchingOffDelay_arjk();
  }

  App_Model_DW.sfEvent_b4nk = b_previousEvent;

  /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
  App_Model_B.Output_OPT_WPCStatus_fwza = LPCDMode;
  App_Model_LPCDOff_Check_fbyv(rtu_PreProcessIn_cqtq);
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_Mode_PhnLeftChattering_od1i(void)
{
  switch (App_Model_DW.is_PhnLeftChattering_aaex) {
   case A_IN_PhnLeftChattering_Off_chv2:
    if (App_Model_DW.sfEvent_b4nk == (sint32)event_StartTimer_PhnLeftCh_ghci) {
      App_Model_DW.is_PhnLeftChattering_aaex = Ap_IN_PhnLeftChattering_On_htsg;
      App_Model_DW.b_Timer_PhnLeftChattering__idxs = true;
    }
    break;

   case Ap_IN_PhnLeftChattering_On_htsg:
    {
      switch (App_Model_DW.sfEvent_b4nk) {
       case event_CancelTimer_PhnLeftC_d0yr:
        App_Model_DW.is_PhnLeftChattering_aaex = A_IN_PhnLeftChattering_Off_chv2;
        App_Model_DW.b_Timer_PhnLeftChattering__idxs = false;
        App_Model_DW.Timer_PhnLeftChattering_khfa = 0U;
        break;

       case event_StartTimer_PhnLeftCh_ghci:
        App_Model_DW.Timer_PhnLeftChattering_khfa = 0U;
        App_Model_DW.is_PhnLeftChattering_aaex = Ap_IN_PhnLeftChattering_On_htsg;
        App_Model_DW.b_Timer_PhnLeftChattering__idxs = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_PhnLeftChattering_khfa + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_PhnLeftChattering_khfa + 1U) < App_Model_DW.Timer_PhnLeftChattering_khfa) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_PhnLeftChattering_khfa = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void App_DrDoorPhnLeftHoldCheck_c35e(Bool rtu_PreProcessIn_cqtq, Bool rtu_PreProcessIn_h4bs, C_WPCWarning rtu_PreProcessIn_aibk, Bool rtu_PreProcessIn_dwyv, Bool rtu_PreProcessIn_ec0z)
{
  if ((((uint32)rtu_PreProcessIn_cqtq == Off) && ((uint32)rtu_PreProcessIn_aibk == WPCWarningOff) && ((uint32)rtu_PreProcessIn_dwyv == Off) && (((App_Model_DW.Input_b_DrvDrSw_prev_iqde !=
          App_Model_DW.Input_b_DrvDrSw_start_mb0f) && ((uint32)App_Model_DW.Input_b_DrvDrSw_start_mb0f == On)) || ((App_Model_DW.Input_b_DrvDrSw_prev_iqde != App_Model_DW.Input_b_DrvDrSw_start_mb0f) &&
         ((uint32)App_Model_DW.Input_b_DrvDrSw_start_mb0f == Off)))) || ((App_Model_DW.Timer_PhnLeftChattering_khfa >= (uint32)((uint16)600U)) || ((App_Model_DW.Input_PhnLeftChk_Enable_pr_me0u !=
         App_Model_DW.Input_PhnLeftChk_Enable_st_ntfs) && ((uint32)App_Model_DW.Input_PhnLeftChk_Enable_st_ntfs == Off)))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_cm1o = On;
    d_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PhnLeftC_d0yr;
    if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_law4 != 0U) {
      App_Mode_PhnLeftChattering_od1i();
    }

    App_Model_DW.sfEvent_b4nk = d_previousEvent;
  } else if (!App_Model_DW.b_Timer_PhnLeftChattering__idxs && ((uint32)rtu_PreProcessIn_cqtq == Off) && ((uint32)rtu_PreProcessIn_aibk == Cellphoneonthepad) && ((uint32)rtu_PreProcessIn_dwyv == On) &&
             (((uint32)rtu_PreProcessIn_h4bs == On) || ((uint32)rtu_PreProcessIn_ec0z == On))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_cm1o = Off;
    d_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_StartTimer_PhnLeftCh_ghci;
    if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_law4 != 0U) {
      App_Mode_PhnLeftChattering_od1i();
    }

    App_Model_DW.sfEvent_b4nk = d_previousEvent;
  } else if ((uint32)rtu_PreProcessIn_cqtq == On) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_cm1o = Off;
    d_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PhnLeftC_d0yr;
    if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_law4 != 0U) {
      App_Mode_PhnLeftChattering_od1i();
    }

    App_Model_DW.sfEvent_b4nk = d_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void enter_atomic_OperationMode_gleh(Bool rtu_PreProcessIn_cqtq, Bool rtu_PreProcessIn_h4bs, C_WPCWarning rtu_PreProcessIn_aibk, Bool rtu_PreProcessIn_dwyv, Bool rtu_PreProcessIn_ec0z)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent_b4nk;
  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCTimeO_kvrm;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_msri != 0U) {
    App_Mode_NFCTimeOutConfirm_ahni();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_NFCSearc_c2ga;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_poei != 0U) {
    App_M_NFCSearchingOffDelay_arjk();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_LPCDOffD_ilej;
  if ((uint32)App_Model_DW.is_active_LPCDOffDelay_bjkw != 0U) {
    App_Model_LPCDOffDelay_fxbc();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCOffD_njj0;
  if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
    App_Model_PICCOffDelay_jd1b();
  }

  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCLPCD_c4rd;
  if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
    App_Model_PICCLPCDOffDelay_ec34();
  }

  App_Model_B.Output_OPT_WPCStatus_fwza = ModeOff;

  /* OffLPCD_Check();%OffToLPCDforFollow */
  App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PhnLeftC_d0yr;
  if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_law4 != 0U) {
    App_Mode_PhnLeftChattering_od1i();
  }

  App_Model_DW.sfEvent_b4nk = b_previousEvent;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_cm1o = Off;
  App_DrDoorPhnLeftHoldCheck_c35e(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);
}

/* Function for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
static void WPC_NFC_Mode_Control_Funct_gbom(Bool rtu_PreProcessIn_cqtq, LC_IAUWPCNFCcmd rtu_PreProcessIn_eeym, C_WPCOnOffNvalueSet rtu_PreProcessIn_m2di, IAU_OwnerPhnRegRVal rtu_PreProcessIn_jp2a,
  OwnerPairingAdvertisingReq rtu_PreProcessIn_ltfm, OnThePad rtu_PreProcessIn_bfmr, Bool rtu_PreProcessIn_pjvj, Bool rtu_PreProcessIn_mbte, WPCStatus rtu_PreProcessIn_auml, Bool rtu_PreProcessIn_h4bs,
  C_WPCWarning rtu_PreProcessIn_aibk, Bool rtu_PreProcessIn_dwyv, Bool rtu_PreProcessIn_jqrj, Bool rtu_PreProcessIn_ec0z)
{
  sint32 g_previousEvent;
  boolean guard1;
  boolean guard2;
  boolean guard3;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  switch (App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum) {
   case App__IN_OperationMode_LPCD_niiv:
    {
      C_WPCOnOffNvalueSet tmp;
      App_Model_B.Output_OPT_WPCStatus_fwza = LPCDMode;

      /* 1 */
      tmp = App_Model_DW.Input_OPT_WPCSWOption_star_kbst;
      if ((((uint32)rtu_PreProcessIn_m2di == WPC_On) && ((uint32)rtu_PreProcessIn_cqtq == On) && ((uint32)rtu_PreProcessIn_eeym != WPCNFCPolling_Search) && (((uint32)rtu_PreProcessIn_jp2a ==
             OwnerPhnReg__Enable) || ((uint32)rtu_PreProcessIn_ltfm != OwnerPairingAdvertisingReq__StartEnable))) || ((App_Model_DW.Input_OPT_WPCSWOption_prev_oikd != tmp) && ((uint32)tmp == WPC_On)))
      {
        /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
        g_previousEvent = App_Model_DW.sfEvent_b4nk;
        App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCLPCD_c4rd;
        if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
          App_Model_PICCLPCDOffDelay_ec34();
        }

        App_Model_DW.sfEvent_b4nk = g_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_WPC_bu5q;
        App_Model_B.Output_OPT_WPCStatus_fwza = WPCMode;

        /* Output_WPC_NFCDetection = NFCDetection_Off; */
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 SWOff_Devided */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start;
        if (((uint32)rtu_PreProcessIn_auml == NFCMode) || ((App_Model_DW.INT_LPCDWakeUpOrder_prev != App_Model_DW.INT_LPCDWakeUpOrder_start) && (App_Model_DW.INT_LPCDWakeUpOrder_start == 1U)) ||
            ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) || (((uint32)rtu_PreProcessIn_cqtq == On) && ((uint32)rtu_PreProcessIn_ltfm !=
              OwnerPairingAdvertisingReq__StartEnable) && ((uint32)rtu_PreProcessIn_m2di == WPC_Off) && ((uint32)rtu_PreProcessIn_auml != PICCMode))) {
          /* Prevention of oscillation
             SWOffDevided */
          guard1 = true;
        } else {
          /* 3 */
          /* 4 */
          tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
          if (((App_Model_DW.INT_LPCDWakeUpOrder_prev != App_Model_DW.INT_LPCDWakeUpOrder_start) && (App_Model_DW.INT_LPCDWakeUpOrder_start == 2U)) || ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0)
               && ((uint32)tmp_0 == WPCNFCPolling_Search)) || ((App_Model_DW.Input_b_IGN1_IN_prev_icoz != App_Model_DW.Input_b_IGN1_IN_start_i333) && ((uint32)App_Model_DW.Input_b_IGN1_IN_start_i333 ==
                On))) {
            /* SWOffDevided */
            /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
            g_previousEvent = App_Model_DW.sfEvent_b4nk;
            App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCLPCD_c4rd;
            if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
              App_Model_PICCLPCDOffDelay_ec34();
            }

            App_Model_DW.sfEvent_b4nk = g_previousEvent;
            App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_NFC_p5jl;
            enter_atomic_OperationMode_gr2j();
          } else {
            WPCStatus tmp_1;

            /* 5 */
            tmp_1 = App_Model_DW.INT_OPT_WPCStatus_1_start;
            if (((uint32)rtu_PreProcessIn_cqtq == Off) && ((App_Model_DW.Timer_LPCDOffDelay_fppw >= (uint32)((uint16)6000U)) || (App_Model_DW.Timer_PICCLPCDOffDelay >= (uint32)((uint16)6000U)) ||
                 ((App_Model_DW.INT_OPT_WPCStatus_1_prev != tmp_1) && ((uint32)tmp_1 == ModeOff)))) {
              /* Simultaneously */
              guard1 = true;
            } else {
              /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
               *  ActionPort: '<S386>/ActionPort'
               */
              /* SwitchCase: '<S379>/Switch Case' incorporates:
               *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
               */
              App_Model_LPCDOff_Check_fbyv(rtu_PreProcessIn_cqtq);

              /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
            }
          }
        }
      }
    }
    break;

   case App_M_IN_OperationMode_NFC_p5jl:
    {
      LC_IAUWPCNFCcmd tmp_0;
      App_Model_B.Output_OPT_WPCStatus_fwza = NFCMode;

      /* 1 */
      tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
      if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) {
        exit_atomic_OperationMode__ajbt();
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_NFC_p5jl;
        enter_atomic_OperationMode_gr2j();
      } else {
        /* 2%WPC1Lead, WPC2Follow or WPC1NFCOnly */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_1_start;

        /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S386>/ActionPort'
         */
        /* SwitchCase: '<S379>/Switch Case' incorporates:
         *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
         */
        if ((((uint32)rtu_PreProcessIn_auml == NFCMode) && ((App_Model_DW.INT_NFCDetectOrder_prev != App_Model_DW.INT_NFCDetectOrder_start) && (App_Model_DW.INT_NFCDetectOrder_start == 1U))) ||
            ((App_Model_DW.Input_IAUWPCNFCcmd_1_prev != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search))) {
          exit_atomic_OperationMode__ajbt();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_Off_dzzr;
          enter_atomic_OperationMode_gleh(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);

          /* 30.5s60s */
        } else if (((uint32)rtu_PreProcessIn_cqtq == On) && ((uint32)rtu_PreProcessIn_m2di == WPC_On) && ((App_Model_DW.Timer_NFCSearchingOffDelay_n2sf >= (uint32)((uint8)50U)) ||
                    (App_Model_DW.Timer_NFCTimeOutConfirm_lajm >= (uint32)((uint16)6000U)) || (App_Model_DW.Timer_NFCSearchingTimeout_a3sf >= (uint32)((uint16)150U)))) {
          /* 1.5 */
          exit_atomic_OperationMode__ajbt();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_WPC_bu5q;
          App_Model_B.Output_OPT_WPCStatus_fwza = WPCMode;

          /* Output_WPC_NFCDetection = NFCDetection_Off; */

          /* 4 */
        } else if ((((uint32)rtu_PreProcessIn_cqtq == Off) && (App_Model_DW.Timer_NFCSearchingOffDelay_n2sf >= (uint32)((uint8)50U))) || (((uint32)rtu_PreProcessIn_cqtq == On) && ((uint32)
                     rtu_PreProcessIn_m2di == WPC_Off) && (App_Model_DW.Timer_NFCSearchingOffDelay_n2sf >= (uint32)((uint8)50U)))) {
          /* 0.5s */
          exit_atomic_OperationMode__ajbt();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App__IN_OperationMode_Picc_dikm;
          enter_atomic_OperationMode_ejig();

          /* 5 */
          /* 60.5s60s */
        } else if ((App_Model_DW.Timer_NFCSearchingOffDelay_n2sf >= (uint32)((uint8)50U)) || (App_Model_DW.Timer_NFCTimeOutConfirm_lajm >= (uint32)((uint16)6000U)) ||
                   (App_Model_DW.Timer_NFCSearchingTimeout_a3sf >= (uint32)((uint16)150U))) {
          /* 1.5 */
          exit_atomic_OperationMode__ajbt();
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App__IN_OperationMode_LPCD_niiv;
          enter_atomic_OperationMode_f4nq(rtu_PreProcessIn_cqtq);
        } else {
          A_NFCSearchingOffDetection_cknw();
          App_Mode_NFCDetectionCheck_cmxs();
        }

        /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
      }
    }
    break;

   case App_M_IN_OperationMode_Off_dzzr:
    {
      WPCStatus tmp_1;
      App_Model_B.Output_OPT_WPCStatus_fwza = ModeOff;

      /* 1 */
      tmp_1 = App_Model_DW.INT_OPT_WPCStatus_1_prev;

      /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S386>/ActionPort'
       */
      /* SwitchCase: '<S379>/Switch Case' incorporates:
       *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
       */
      if (((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && ((uint32)tmp_1 == NFCMode) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_1_start ==
             LPCDMode))) || (((App_Model_DW.Var_DrDoorPhnLftHoldComple_orto != App_Model_DW.Var_DrDoorPhnLftHoldComple_bqmt) && (App_Model_DW.Var_DrDoorPhnLftHoldComple_bqmt == On)) || (((uint32)
             rtu_PreProcessIn_cqtq == On) && ((uint32)rtu_PreProcessIn_ltfm == OwnerPairingAdvertisingReq__StartEnable) && ((uint32)rtu_PreProcessIn_m2di == WPC_Off) && ((uint32)rtu_PreProcessIn_auml ==
             ModeOff)))) {
        /* WPC2ChangeOff2LPCD,WhenWPC1ChangeNFC2LPCD */
        /* BothOffModeStartEnable */
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App__IN_OperationMode_LPCD_niiv;
        enter_atomic_OperationMode_f4nq(rtu_PreProcessIn_cqtq);

        /* 2 */
        /* 3 */
      } else if ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_1_start == PICCMode)) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App__IN_OperationMode_Picc_dikm;
        enter_atomic_OperationMode_ejig();

        /* 3 */
      } else if ((uint32)rtu_PreProcessIn_eeym == WPCNFCPolling_Search) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_NFC_p5jl;
        enter_atomic_OperationMode_gr2j();

        /* 5 */
      } else if (((uint32)rtu_PreProcessIn_cqtq == On) && ((uint32)rtu_PreProcessIn_m2di == WPC_On) && ((uint32)rtu_PreProcessIn_auml != NFCMode)) {
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_WPC_bu5q;
        App_Model_B.Output_OPT_WPCStatus_fwza = WPCMode;

        /* Output_WPC_NFCDetection = NFCDetection_Off; */
      } else {
        /* OffLPCD_Check();%OffToLPCDforFollow */
        App_DrDoorPhnLeftHoldCheck_c35e(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);
      }

      /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
    }
    break;

   case App__IN_OperationMode_Picc_dikm:
    {
      App_Model_B.Output_OPT_WPCStatus_fwza = PICCMode;

      /* 1 */
      if ((uint32)rtu_PreProcessIn_pjvj == On) {
        /* NFC1 or 2 OnThePad_Off */
        /* PhnRemoveMode */
        g_previousEvent = App_Model_DW.sfEvent_b4nk;
        App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCOffD_njj0;
        if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
          App_Model_PICCOffDelay_jd1b();
        }

        App_Model_DW.sfEvent_b4nk = g_previousEvent;
        App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App__IN_OperationMode_LPCD_niiv;

        /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
         *  ActionPort: '<S386>/ActionPort'
         */
        /* SwitchCase: '<S379>/Switch Case' incorporates:
         *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
         */
        enter_atomic_OperationMode_f4nq(rtu_PreProcessIn_cqtq);

        /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */

        /* 2 */
      } else if (((uint32)rtu_PreProcessIn_cqtq == Off) && (App_Model_DW.Timer_PICCOffDelay_dxdj >= (uint32)((uint16)6000U))) {
        guard2 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 3 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search)) {
          /* PhnRemoveMode */
          g_previousEvent = App_Model_DW.sfEvent_b4nk;
          App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCOffD_njj0;
          if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
            App_Model_PICCOffDelay_jd1b();
          }

          App_Model_DW.sfEvent_b4nk = g_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_NFC_p5jl;
          enter_atomic_OperationMode_gr2j();

          /* 45sec */
        } else if (((uint32)rtu_PreProcessIn_cqtq == On) && ((uint32)rtu_PreProcessIn_m2di == WPC_On) && (((uint32)rtu_PreProcessIn_bfmr == OnThePad_On) || (((uint32)rtu_PreProcessIn_bfmr ==
                      OnThePad_Default) && (App_Model_DW.Timer_PICCOffDelay_dxdj >= (uint32)((uint16)500U))) || ((uint32)rtu_PreProcessIn_auml == WPCMode))) {
          /* TransitionMerge */
          /* PhnRemoveMode */
          g_previousEvent = App_Model_DW.sfEvent_b4nk;
          App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCOffD_njj0;
          if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
            App_Model_PICCOffDelay_jd1b();
          }

          App_Model_DW.sfEvent_b4nk = g_previousEvent;
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_WPC_bu5q;
          App_Model_B.Output_OPT_WPCStatus_fwza = WPCMode;

          /* Output_WPC_NFCDetection = NFCDetection_Off; */
        } else {
          WPCStatus tmp_1;

          /* Simultenously ModeOff */
          tmp_1 = App_Model_DW.INT_OPT_WPCStatus_1_prev;
          if ((((uint32)rtu_PreProcessIn_cqtq == Off) && ((tmp_1 != App_Model_DW.INT_OPT_WPCStatus_1_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_1_start == ModeOff))) || ((tmp_1 !=
                App_Model_DW.INT_OPT_WPCStatus_1_start) && ((uint32)App_Model_DW.INT_OPT_WPCStatus_1_start == NFCMode)) || (((uint32)rtu_PreProcessIn_m2di == WPC_Off) && (((uint32)
                 rtu_PreProcessIn_auml == WPCMode) || (App_Model_DW.Timer_PICCOffDelay_dxdj >= (uint32)((uint16)6000U))))) {
            /* WPCSWOffALL_Case */
            guard2 = true;
          } else {
            /* 6%WPCSWOption_Off Case */
          }
        }
      }
    }
    break;

   case App_M_IN_OperationMode_WPC_bu5q:
    {
      App_Model_B.Output_OPT_WPCStatus_fwza = WPCMode;

      /* 1 */
      if ((uint32)rtu_PreProcessIn_auml == LPCDMode) {
        /* WhileWPC1isSWOff, WPC1MoveFromOFFtoLPCD */
        guard3 = true;
      } else {
        LC_IAUWPCNFCcmd tmp_0;

        /* 2 */
        tmp_0 = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
        if ((App_Model_DW.Input_IAUWPCNFCcmd_2_prev != tmp_0) && ((uint32)tmp_0 == WPCNFCPolling_Search) && ((uint32)rtu_PreProcessIn_auml != NFCMode)) {
          /* WaitingforNFCCom */
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_NFC_p5jl;
          enter_atomic_OperationMode_gr2j();

          /* 3%When WPC1&2 are Both ChargingOnThePad_Off || ObjectOnthePad_Off */
        } else if ((((uint32)rtu_PreProcessIn_mbte == On) || ((uint32)rtu_PreProcessIn_jqrj == On)) && (((uint32)rtu_PreProcessIn_jp2a == OwnerPhnReg__Disable) || ((uint32)rtu_PreProcessIn_jp2a ==
                     OwnerPhnReg__Default) || ((uint32)rtu_PreProcessIn_jp2a == OwnerPhnReg__Invalid)) && ((uint32)rtu_PreProcessIn_ltfm == OwnerPairingAdvertisingReq__StartEnable)) {
          App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App__IN_OperationMode_Picc_dikm;
          enter_atomic_OperationMode_ejig();

          /* 4 */
        } else if (((uint32)rtu_PreProcessIn_cqtq == Off) || ((uint32)rtu_PreProcessIn_m2di == WPC_Off) || ((uint32)rtu_PreProcessIn_auml == NFCMode)) {
          /* PollingSearchDivided */
          guard3 = true;
        } else {
          /* no actions */
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }

  if (guard3) {
    App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_Off_dzzr;

    /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S386>/ActionPort'
     */
    /* SwitchCase: '<S379>/Switch Case' incorporates:
     *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
     */
    enter_atomic_OperationMode_gleh(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);

    /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
  }

  if (guard2) {
    /* PhnRemoveMode */
    g_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCOffD_njj0;
    if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
      App_Model_PICCOffDelay_jd1b();
    }

    App_Model_DW.sfEvent_b4nk = g_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_Off_dzzr;

    /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S386>/ActionPort'
     */
    /* SwitchCase: '<S379>/Switch Case' incorporates:
     *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
     */
    enter_atomic_OperationMode_gleh(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);

    /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
  }

  if (guard1) {
    /* send(CancelTimer_LPCDOffDelay, LPCDOffDelay); */
    g_previousEvent = App_Model_DW.sfEvent_b4nk;
    App_Model_DW.sfEvent_b4nk = (sint32)event_CancelTimer_PICCLPCD_c4rd;
    if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
      App_Model_PICCLPCDOffDelay_ec34();
    }

    App_Model_DW.sfEvent_b4nk = g_previousEvent;
    App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_Off_dzzr;

    /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S386>/ActionPort'
     */
    /* SwitchCase: '<S379>/Switch Case' incorporates:
     *  Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10'
     */
    enter_atomic_OperationMode_gleh(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);

    /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
  }
}

/* System initialize for atomic system: '<S218>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control__dr2c_Init(WPCStatus *rty_WPC2Status)
{
  /* SystemInitialize for IfAction SubSystem: '<S379>/WPC_Mode_Control' */
  App_Model_WPC_Mode_Control_Init(&App_Model_DW.WPC_Mode_Control_lus0);

  /* End of SystemInitialize for SubSystem: '<S379>/WPC_Mode_Control' */

  /* SystemInitialize for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' */
  /* SystemInitialize for Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
  App_Model_DW.sfEvent_b4nk = (sint32)App_Model_CALL_EVENT_e0qm;
  App_Model_DW.is_active_LPCDOffDelay_bjkw = 0U;
  App_Model_DW.is_LPCDOffDelay_eagi = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_NFCSearchingOffD_poei = 0U;
  App_Model_DW.is_NFCSearchingOffDelay_hdu2 = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_NFCSearchingTime_ixhk = 0U;
  App_Model_DW.is_NFCSearchingTimeout_jmpa = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_NFCTimeOutConfir_msri = 0U;
  App_Model_DW.is_NFCTimeOutConfirm_eole = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_PICCLPCDOffDelay = 0U;
  App_Model_DW.is_PICCLPCDOffDelay = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_PICCOffDelay_a54p = 0U;
  App_Model_DW.is_PICCOffDelay_ajiq = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_PhnLeftChatterin_law4 = 0U;
  App_Model_DW.is_PhnLeftChattering_aaex = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_WPC_NFC_Mode_Con_hzbi = 0U;
  App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_Mod_IN_NO_ACTIVE_CHILD_iabj;
  App_Model_DW.is_active_c51_NFC_WPC_Mode_Cont = 0U;
  App_Model_DW.Timer_NFCTimeOutConfirm_lajm = 0U;
  App_Model_DW.Timer_NFCSearchingOffDelay_n2sf = 0U;
  App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_osxv = false;
  App_Model_DW.Timer_LPCDOffDelay_fppw = 0U;
  App_Model_DW.Timer_NFCSearchingTimeout_a3sf = 0U;
  App_Model_DW.Timer_PICCOffDelay_dxdj = 0U;
  App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
  App_Model_DW.b_Timer_PhnLeftChattering__idxs = false;
  App_Model_DW.Timer_PhnLeftChattering_khfa = 0U;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_cm1o = 0U;
  App_Model_B.Output_OPT_WPCStatus_fwza = ModeOff;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_orto = 0U;
  App_Model_DW.Var_DrDoorPhnLftHoldComple_bqmt = 0U;
  App_Model_DW.Input_NFCDetection2_prev = NFCDetection_Off;
  App_Model_DW.Input_NFCDetection2_start = NFCDetection_Off;
  App_Model_DW.Input_IAUWPCNFCcmd_2_prev = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_IAUWPCNFCcmd_2_start = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_b_DrvDrSw_prev_iqde = Off;
  App_Model_DW.Input_b_DrvDrSw_start_mb0f = Off;
  App_Model_DW.Input_PhnLeftChk_Enable_pr_me0u = Off;
  App_Model_DW.Input_PhnLeftChk_Enable_st_ntfs = Off;
  App_Model_DW.INT_OPT_WPCStatus_1_prev = ModeOff;
  App_Model_DW.INT_OPT_WPCStatus_1_start = ModeOff;
  App_Model_DW.Input_IAUWPCNFCcmd_1_prev = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_IAUWPCNFCcmd_1_start = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_b_IGN1_IN_prev_icoz = Off;
  App_Model_DW.Input_b_IGN1_IN_start_i333 = Off;
  App_Model_DW.Input_OPT_WPCSWOption_prev_oikd = WPC_On;
  App_Model_DW.Input_OPT_WPCSWOption_star_kbst = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S379>/WPC_NFCModeControl_compact' */

  /* SystemInitialize for Merge: '<S379>/Merge' */
  *rty_WPC2Status = ModeOff;
}

/* Output and update for atomic system: '<S218>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Funct_mock(Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_cqtq, LC_IAUWPCNFCcmd rtu_PreProcessIn_eeym, C_WPCOnOffNvalueSet rtu_PreProcessIn_m2di, IAU_OwnerPhnRegRVal
  rtu_PreProcessIn_jp2a, OwnerPairingAdvertisingReq rtu_PreProcessIn_ltfm, OnThePad rtu_PreProcessIn_bfmr, LC_WPC_NFCDetection rtu_PreProcessIn_k3pf, Bool rtu_PreProcessIn_pjvj, Bool
  rtu_PreProcessIn_mbte, WPCStatus rtu_PreProcessIn_auml, uint8 rtu_PreProcessIn_p5um, uint8 rtu_PreProcessIn_cphf, Bool rtu_PreProcessIn_h4bs, C_WPCWarning rtu_PreProcessIn_aibk, Bool
  rtu_PreProcessIn_dwyv, LC_IAUWPCNFCcmd rtu_PreProcessIn_hld1, Bool rtu_PreProcessIn_jqrj, Bool rtu_PreProcessIn_ec0z, Bool rtu_PreProcessIn_pgeg, WPCStatus *rty_WPC2Status)
{
  /* SwitchCase: '<S379>/Switch Case' */
  switch (rtu_PreProcessIn) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S379>/WPC_Mode_Control' incorporates:
     *  ActionPort: '<S385>/ActionPort'
     */
    App_Model_WPC_Mode_Control(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_m2di, rtu_PreProcessIn_pgeg, rty_WPC2Status, &App_Model_DW.WPC_Mode_Control_lus0);

    /* End of Outputs for SubSystem: '<S379>/WPC_Mode_Control' */
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S379>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S386>/ActionPort'
     */
    /* Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */
    App_Model_DW.sfEvent_b4nk = (sint32)App_Model_CALL_EVENT_e0qm;
    App_Model_DW.Input_NFCDetection2_prev = App_Model_DW.Input_NFCDetection2_start;
    App_Model_DW.Input_NFCDetection2_start = rtu_PreProcessIn_k3pf;
    App_Model_DW.Input_IAUWPCNFCcmd_2_prev = App_Model_DW.Input_IAUWPCNFCcmd_2_start;
    App_Model_DW.Input_IAUWPCNFCcmd_2_start = rtu_PreProcessIn_eeym;
    App_Model_DW.Input_b_DrvDrSw_prev_iqde = App_Model_DW.Input_b_DrvDrSw_start_mb0f;
    App_Model_DW.Input_b_DrvDrSw_start_mb0f = rtu_PreProcessIn_h4bs;
    App_Model_DW.Input_PhnLeftChk_Enable_pr_me0u = App_Model_DW.Input_PhnLeftChk_Enable_st_ntfs;
    App_Model_DW.Input_PhnLeftChk_Enable_st_ntfs = rtu_PreProcessIn_dwyv;
    App_Model_DW.INT_OPT_WPCStatus_1_prev = App_Model_DW.INT_OPT_WPCStatus_1_start;
    App_Model_DW.INT_OPT_WPCStatus_1_start = rtu_PreProcessIn_auml;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_orto = App_Model_DW.Var_DrDoorPhnLftHoldComple_bqmt;
    App_Model_DW.Var_DrDoorPhnLftHoldComple_bqmt = App_Model_DW.Var_DrDoorPhnLftHoldComple_cm1o;
    App_Model_DW.INT_LPCDWakeUpOrder_prev = App_Model_DW.INT_LPCDWakeUpOrder_start;
    App_Model_DW.INT_LPCDWakeUpOrder_start = rtu_PreProcessIn_p5um;
    App_Model_DW.Input_IAUWPCNFCcmd_1_prev = App_Model_DW.Input_IAUWPCNFCcmd_1_start;
    App_Model_DW.Input_IAUWPCNFCcmd_1_start = rtu_PreProcessIn_hld1;
    App_Model_DW.Input_b_IGN1_IN_prev_icoz = App_Model_DW.Input_b_IGN1_IN_start_i333;
    App_Model_DW.Input_b_IGN1_IN_start_i333 = rtu_PreProcessIn_cqtq;
    App_Model_DW.Input_OPT_WPCSWOption_prev_oikd = App_Model_DW.Input_OPT_WPCSWOption_star_kbst;
    App_Model_DW.Input_OPT_WPCSWOption_star_kbst = rtu_PreProcessIn_m2di;
    App_Model_DW.INT_NFCDetectOrder_prev = App_Model_DW.INT_NFCDetectOrder_start;
    App_Model_DW.INT_NFCDetectOrder_start = rtu_PreProcessIn_cphf;
    if ((uint32)App_Model_DW.is_active_c51_NFC_WPC_Mode_Cont == 0U) {
      App_Model_DW.Input_NFCDetection2_prev = rtu_PreProcessIn_k3pf;
      App_Model_DW.Input_IAUWPCNFCcmd_2_prev = rtu_PreProcessIn_eeym;
      App_Model_DW.Input_b_DrvDrSw_prev_iqde = rtu_PreProcessIn_h4bs;
      App_Model_DW.Input_PhnLeftChk_Enable_pr_me0u = rtu_PreProcessIn_dwyv;
      App_Model_DW.INT_OPT_WPCStatus_1_prev = rtu_PreProcessIn_auml;
      App_Model_DW.INT_LPCDWakeUpOrder_prev = rtu_PreProcessIn_p5um;
      App_Model_DW.Input_IAUWPCNFCcmd_1_prev = rtu_PreProcessIn_hld1;
      App_Model_DW.Input_b_IGN1_IN_prev_icoz = rtu_PreProcessIn_cqtq;
      App_Model_DW.Input_OPT_WPCSWOption_prev_oikd = rtu_PreProcessIn_m2di;
      App_Model_DW.INT_NFCDetectOrder_prev = rtu_PreProcessIn_cphf;
      App_Model_DW.is_active_c51_NFC_WPC_Mode_Cont = 1U;
      App_Model_DW.is_active_NFCTimeOutConfir_msri = 1U;
      App_Model_DW.is_NFCTimeOutConfirm_eole = A_IN_NFCTimeOutConfirm_Off_ixfd;
      App_Model_DW.Timer_NFCTimeOutConfirm_lajm = 0U;
      App_Model_DW.is_active_NFCSearchingOffD_poei = 1U;
      App_Model_DW.is_NFCSearchingOffDelay_hdu2 = IN_NFCSearchingOffDelay_Of_hze2;
      App_Model_DW.Timer_NFCSearchingOffDelay_n2sf = 0U;
      App_Model_DW.is_active_LPCDOffDelay_bjkw = 1U;
      App_Model_DW.is_LPCDOffDelay_eagi = App_Mo_IN_LPCDOffDelay_Off_cqlg;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Ru_osxv = false;
      App_Model_DW.Timer_LPCDOffDelay_fppw = 0U;
      App_Model_DW.is_active_NFCSearchingTime_ixhk = 1U;
      App_Model_DW.is_NFCSearchingTimeout_jmpa = IN_NFCSearchingTimeout_Off_c0qf;
      App_Model_DW.Timer_NFCSearchingTimeout_a3sf = 0U;
      App_Model_DW.is_active_PICCOffDelay_a54p = 1U;
      App_Model_DW.is_PICCOffDelay_ajiq = App_Mo_IN_PICCOffDelay_Off_c24o;
      App_Model_DW.Timer_PICCOffDelay_dxdj = 0U;
      App_Model_DW.is_active_WPC_NFC_Mode_Con_hzbi = 1U;

      /* Default */
      App_Model_DW.is_WPC_NFC_Mode_Control_Fu_ffum = App_M_IN_OperationMode_Off_dzzr;
      enter_atomic_OperationMode_gleh(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_ec0z);
      App_Model_DW.is_active_PICCLPCDOffDelay = 1U;
      App_Model_DW.is_PICCLPCDOffDelay = Ap_IN_PICCLPCDOffDelay_Off_chhf;
      App_Model_DW.Timer_PICCLPCDOffDelay = 0U;
      App_Model_DW.is_active_PhnLeftChatterin_law4 = 1U;
      App_Model_DW.is_PhnLeftChattering_aaex = A_IN_PhnLeftChattering_Off_chv2;
      App_Model_DW.b_Timer_PhnLeftChattering__idxs = false;
      App_Model_DW.Timer_PhnLeftChattering_khfa = 0U;
    } else {
      if ((uint32)App_Model_DW.is_active_NFCTimeOutConfir_msri != 0U) {
        App_Mode_NFCTimeOutConfirm_ahni();
      }

      if ((uint32)App_Model_DW.is_active_NFCSearchingOffD_poei != 0U) {
        App_M_NFCSearchingOffDelay_arjk();
      }

      if ((uint32)App_Model_DW.is_active_LPCDOffDelay_bjkw != 0U) {
        App_Model_LPCDOffDelay_fxbc();
      }

      if ((uint32)App_Model_DW.is_active_NFCSearchingTime_ixhk != 0U) {
        App_Mo_NFCSearchingTimeout_kj53();
      }

      if ((uint32)App_Model_DW.is_active_PICCOffDelay_a54p != 0U) {
        App_Model_PICCOffDelay_jd1b();
      }

      if ((uint32)App_Model_DW.is_active_WPC_NFC_Mode_Con_hzbi != 0U) {
        WPC_NFC_Mode_Control_Funct_gbom(rtu_PreProcessIn_cqtq, rtu_PreProcessIn_eeym, rtu_PreProcessIn_m2di, rtu_PreProcessIn_jp2a, rtu_PreProcessIn_ltfm, rtu_PreProcessIn_bfmr, rtu_PreProcessIn_pjvj,
          rtu_PreProcessIn_mbte, rtu_PreProcessIn_auml, rtu_PreProcessIn_h4bs, rtu_PreProcessIn_aibk, rtu_PreProcessIn_dwyv, rtu_PreProcessIn_jqrj, rtu_PreProcessIn_ec0z);
      }

      if ((uint32)App_Model_DW.is_active_PICCLPCDOffDelay != 0U) {
        App_Model_PICCLPCDOffDelay_ec34();
      }

      if ((uint32)App_Model_DW.is_active_PhnLeftChatterin_law4 != 0U) {
        App_Mode_PhnLeftChattering_od1i();
      }
    }

    /* End of Chart: '<S386>/NFC_WPC_Mode_Control_DWPC2_r10' */

    /* SignalConversion: '<S386>/Signal Conversion1' */
    *rty_WPC2Status = App_Model_B.Output_OPT_WPCStatus_fwza;

    /* End of Outputs for SubSystem: '<S379>/WPC_NFCModeControl_compact' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S379>/Switch Case' */
}

/* System initialize for atomic system: '<S463>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control__dxgm_Init(WPCStatus *rty_WPCStatus)
{
  /* SystemInitialize for IfAction SubSystem: '<S591>/WPC_Mode_Control' */
  App_Model_WPC_Mode_Control_Init(&App_Model_DW.WPC_Mode_Control_bs3f);

  /* End of SystemInitialize for SubSystem: '<S591>/WPC_Mode_Control' */

  /* SystemInitialize for IfAction SubSystem: '<S591>/WPC_Mode_Control_EV' */
  /* SystemInitialize for Chart: '<S598>/RWPC_Mode_Control_EV' */
  App_Model_DW.is_WpcNfcModeControl = App_Mod_IN_NO_ACTIVE_CHILD_m0bk;
  App_Model_DW.is_active_c11_NFC_WPC_Mode_Cont = 0U;

  /* End of SystemInitialize for SubSystem: '<S591>/WPC_Mode_Control_EV' */

  /* SystemInitialize for Merge: '<S591>/Merge' */
  *rty_WPCStatus = ModeOff;
}

/* Output and update for atomic system: '<S463>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Funct_appg(Bool rtu_PreProcessIn, GearPosSta rtu_PreProcessIn_hg3k, C_WPCOnOffNvalueSet rtu_PreProcessIn_dwtr, Bool rtu_PreProcessIn_olfo, Bool rtu_PreProcessIn_fnvi,
  WPCStatus *rty_WPCStatus)
{
  /* SwitchCase: '<S591>/Switch Case' */
  switch (rtu_PreProcessIn) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S591>/WPC_Mode_Control' incorporates:
     *  ActionPort: '<S597>/ActionPort'
     */
    App_Model_WPC_Mode_Control(rtu_PreProcessIn_fnvi, rtu_PreProcessIn_dwtr, rtu_PreProcessIn_olfo, rty_WPCStatus, &App_Model_DW.WPC_Mode_Control_bs3f);

    /* End of Outputs for SubSystem: '<S591>/WPC_Mode_Control' */
    break;

   case On:
    {
      WPCStatus rtb_WPCStatus;

      /* Outputs for IfAction SubSystem: '<S591>/WPC_Mode_Control_EV' incorporates:
       *  ActionPort: '<S598>/ActionPort'
       */
      /* Chart: '<S598>/RWPC_Mode_Control_EV' */
      if ((uint32)App_Model_DW.is_active_c11_NFC_WPC_Mode_Cont == 0U) {
        App_Model_DW.is_active_c11_NFC_WPC_Mode_Cont = 1U;
        App_Model_DW.is_WpcNfcModeControl = App_M_IN_OperationMode_OFF_p0kw;
        rtb_WPCStatus = ModeOff;
      } else if ((uint32)App_Model_DW.is_WpcNfcModeControl == App_M_IN_OperationMode_OFF_p0kw) {
        rtb_WPCStatus = ModeOff;

        /* 2. */
        if (((uint32)rtu_PreProcessIn_dwtr == WPC_On) && ((uint32)rtu_PreProcessIn_hg3k != GearPos_P) && ((uint32)rtu_PreProcessIn_olfo != On)) {
          /* Non_GFS */
          App_Model_DW.is_WpcNfcModeControl = App_Mo_IN_OperationMode_ON_gqum;
          rtb_WPCStatus = WPCMode;
        }
      } else {
        /* case IN_OperationMode_ON: */
        rtb_WPCStatus = WPCMode;

        /* 1. */
        if (((uint32)rtu_PreProcessIn_hg3k == GearPos_P) || ((uint32)rtu_PreProcessIn_dwtr == WPC_Off) || ((uint32)rtu_PreProcessIn_olfo == On)) {
          /* Non_GFS */
          App_Model_DW.is_WpcNfcModeControl = App_M_IN_OperationMode_OFF_p0kw;
          rtb_WPCStatus = ModeOff;
        }
      }

      /* End of Chart: '<S598>/RWPC_Mode_Control_EV' */

      /* SignalConversion generated from: '<S598>/WPC_Status' */
      *rty_WPCStatus = rtb_WPCStatus;

      /* End of Outputs for SubSystem: '<S591>/WPC_Mode_Control_EV' */
    }
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S591>/Switch Case' */
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Mode_NFCTimeOutConfirm_giml(void)
{
  switch (App_Model_DW.is_NFCTimeOutConfirm) {
   case A_IN_NFCTimeOutConfirm_Off_h15f:
    if (App_Model_DW.sfEvent == (sint32)event_StartTimer_NFCTimeOu_dt5f) {
      App_Model_DW.is_NFCTimeOutConfirm = Ap_IN_NFCTimeOutConfirm_On_eii2;
    }
    break;

   case Ap_IN_NFCTimeOutConfirm_On_eii2:
    {
      switch (App_Model_DW.sfEvent) {
       case event_CancelTimer_NFCTimeO_fjff:
        App_Model_DW.is_NFCTimeOutConfirm = A_IN_NFCTimeOutConfirm_Off_h15f;
        App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
        break;

       case event_StartTimer_NFCTimeOu_dt5f:
        App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
        App_Model_DW.is_NFCTimeOutConfirm = Ap_IN_NFCTimeOutConfirm_On_eii2;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCTimeOutConfirm + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCTimeOutConfirm + 1U) < App_Model_DW.Timer_NFCTimeOutConfirm) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCTimeOutConfirm = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_M_NFCSearchingOffDelay_b5hj(void)
{
  switch (App_Model_DW.is_NFCSearchingOffDelay) {
   case IN_NFCSearchingOffDelay_Of_p4ac:
    if (App_Model_DW.sfEvent == (sint32)event_StartTimer_NFCSearch_ljgd) {
      App_Model_DW.is_NFCSearchingOffDelay = IN_NFCSearchingOffDelay_On_oulx;
    }
    break;

   case IN_NFCSearchingOffDelay_On_oulx:
    {
      switch (App_Model_DW.sfEvent) {
       case event_CancelTimer_NFCSearc_gsrw:
        App_Model_DW.is_NFCSearchingOffDelay = IN_NFCSearchingOffDelay_Of_p4ac;
        App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
        break;

       case event_StartTimer_NFCSearch_ljgd:
        App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
        App_Model_DW.is_NFCSearchingOffDelay = IN_NFCSearchingOffDelay_On_oulx;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingOffDelay + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCSearchingOffDelay + 1U) < App_Model_DW.Timer_NFCSearchingOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingOffDelay = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Model_LPCDOffDelay_mp4k(void)
{
  switch (App_Model_DW.is_LPCDOffDelay) {
   case App_Mo_IN_LPCDOffDelay_Off_f3el:
    if (App_Model_DW.sfEvent == (sint32)event_StartTimer_LPCDOffDe_c055) {
      App_Model_DW.is_LPCDOffDelay = App_Mod_IN_LPCDOffDelay_On_hw5i;
      App_Model_DW.b_Timer_LPCDOffDelay_is_Running = true;
    }
    break;

   case App_Mod_IN_LPCDOffDelay_On_hw5i:
    {
      switch (App_Model_DW.sfEvent) {
       case event_CancelTimer_LPCDOffD_kg1v:
        App_Model_DW.is_LPCDOffDelay = App_Mo_IN_LPCDOffDelay_Off_f3el;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Running = false;
        App_Model_DW.Timer_LPCDOffDelay = 0U;
        break;

       case event_StartTimer_LPCDOffDe_c055:
        App_Model_DW.Timer_LPCDOffDelay = 0U;
        App_Model_DW.is_LPCDOffDelay = App_Mod_IN_LPCDOffDelay_On_hw5i;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Running = true;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_LPCDOffDelay + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_LPCDOffDelay + 1U) < App_Model_DW.Timer_LPCDOffDelay) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_LPCDOffDelay = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Mo_NFCSearchingTimeout_k2k5(void)
{
  switch (App_Model_DW.is_NFCSearchingTimeout) {
   case IN_NFCSearchingTimeout_Off_cpga:
    if (App_Model_DW.sfEvent == (sint32)event_StartTimer_NFCSearch_cveq) {
      App_Model_DW.is_NFCSearchingTimeout = IN_NFCSearchingTimeout_On_ctax;
    }
    break;

   case IN_NFCSearchingTimeout_On_ctax:
    {
      switch (App_Model_DW.sfEvent) {
       case event_CancelTimer_NFCSearc_eghu:
        App_Model_DW.is_NFCSearchingTimeout = IN_NFCSearchingTimeout_Off_cpga;
        App_Model_DW.Timer_NFCSearchingTimeout = 0U;
        break;

       case event_StartTimer_NFCSearch_cveq:
        App_Model_DW.Timer_NFCSearchingTimeout = 0U;
        App_Model_DW.is_NFCSearchingTimeout = IN_NFCSearchingTimeout_On_ctax;
        break;

       default:
        {
          uint32 qY;
          qY = App_Model_DW.Timer_NFCSearchingTimeout + /*MW:OvSatOk*/ 1U;
          if ((App_Model_DW.Timer_NFCSearchingTimeout + 1U) < App_Model_DW.Timer_NFCSearchingTimeout) {
            qY = MAX_uint32_T;
          }

          App_Model_DW.Timer_NFCSearchingTimeout = qY;
        }
        break;
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Model_PICCOffDelay_el5i(void)
{
  switch (App_Model_DW.is_PICCOffDelay) {
   case App_Mo_IN_PICCOffDelay_Off_a1d0:
    if (App_Model_DW.sfEvent == (sint32)event_StartTimer_PICCOffDe_leur) {
      App_Model_DW.is_PICCOffDelay = App_Mod_IN_PICCOffDelay_On_ercd;
    }
    break;

   case App_Mod_IN_PICCOffDelay_On_ercd:
    switch (App_Model_DW.sfEvent) {
     case event_CancelTimer_PICCOffD_fgqe:
      App_Model_DW.is_PICCOffDelay = App_Mo_IN_PICCOffDelay_Off_a1d0;
      App_Model_DW.Timer_PICCOffDelay = 0.0;
      break;

     case event_StartTimer_PICCOffDe_leur:
      App_Model_DW.Timer_PICCOffDelay = 0.0;
      App_Model_DW.is_PICCOffDelay = App_Mod_IN_PICCOffDelay_On_ercd;
      break;

     default:
      App_Model_DW.Timer_PICCOffDelay++;
      break;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Mode_PhnLeftChattering_jrtx(void)
{
  switch (App_Model_DW.is_PhnLeftChattering) {
   case A_IN_PhnLeftChattering_Off_e5ff:
    if (App_Model_DW.sfEvent == (sint32)event_StartTimer_PhnLeftCh_dc3j) {
      App_Model_DW.is_PhnLeftChattering = Ap_IN_PhnLeftChattering_On_a4s0;
      App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = true;
    }
    break;

   case Ap_IN_PhnLeftChattering_On_a4s0:
    switch (App_Model_DW.sfEvent) {
     case event_CancelTimer_PhnLeftC_akjh:
      App_Model_DW.is_PhnLeftChattering = A_IN_PhnLeftChattering_Off_e5ff;
      App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = false;
      App_Model_DW.Timer_PhnLeftChattering = 0.0;
      break;

     case event_StartTimer_PhnLeftCh_dc3j:
      App_Model_DW.Timer_PhnLeftChattering = 0.0;
      App_Model_DW.is_PhnLeftChattering = Ap_IN_PhnLeftChattering_On_a4s0;
      App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = true;
      break;

     default:
      App_Model_DW.Timer_PhnLeftChattering++;
      break;
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_DrDoorPhnLeftHoldCheck_byf3(Bool rtu_PreProcessIn_atch, Bool rtu_PreProcessIn_mdz2, C_WPCWarning rtu_PreProcessIn_hjwo, Bool rtu_PreProcessIn_fbwq, Bool rtu_PreProcessIn_gi5q)
{
  if ((((uint32)rtu_PreProcessIn_atch == Off) && ((uint32)rtu_PreProcessIn_hjwo == WPCWarningOff) && ((uint32)rtu_PreProcessIn_fbwq == Off) && (((App_Model_DW.Input_b_DrvDrSw_prev !=
          App_Model_DW.Input_b_DrvDrSw_start) && ((uint32)App_Model_DW.Input_b_DrvDrSw_start == On)) || ((App_Model_DW.Input_b_DrvDrSw_prev != App_Model_DW.Input_b_DrvDrSw_start) && ((uint32)
          App_Model_DW.Input_b_DrvDrSw_start == Off)))) || ((App_Model_DW.Timer_PhnLeftChattering >= (float64)((uint16)600U)) || ((App_Model_DW.Input_PhnLeftChk_Enable_prev !=
         App_Model_DW.Input_PhnLeftChk_Enable_start) && ((uint32)App_Model_DW.Input_PhnLeftChk_Enable_start == Off)))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete = 1.0;
    d_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_CancelTimer_PhnLeftC_akjh;
    if ((uint32)App_Model_DW.is_active_PhnLeftChattering != 0U) {
      App_Mode_PhnLeftChattering_jrtx();
    }

    App_Model_DW.sfEvent = d_previousEvent;

    /* Outputs for IfAction SubSystem: '<S811>/WPC_NFCModeControl_compact' incorporates:
     *  ActionPort: '<S818>/ActionPort'
     */
  } else if (!App_Model_DW.b_Timer_PhnLeftChattering_is_Ru && ((uint32)rtu_PreProcessIn_atch == Off) && ((uint32)rtu_PreProcessIn_hjwo == Cellphoneonthepad) && ((uint32)rtu_PreProcessIn_fbwq == On) &&
             (((uint32)rtu_PreProcessIn_mdz2 == On) || ((uint32)rtu_PreProcessIn_gi5q == On))) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete = 0.0;
    d_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_StartTimer_PhnLeftCh_dc3j;
    if ((uint32)App_Model_DW.is_active_PhnLeftChattering != 0U) {
      App_Mode_PhnLeftChattering_jrtx();
    }

    App_Model_DW.sfEvent = d_previousEvent;
  } else if ((uint32)rtu_PreProcessIn_atch == On) {
    sint32 d_previousEvent;
    App_Model_DW.Var_DrDoorPhnLftHoldComplete = 0.0;
    d_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_CancelTimer_PhnLeftC_akjh;
    if ((uint32)App_Model_DW.is_active_PhnLeftChattering != 0U) {
      App_Mode_PhnLeftChattering_jrtx();
    }

    App_Model_DW.sfEvent = d_previousEvent;

    /* End of Outputs for SubSystem: '<S811>/WPC_NFCModeControl_compact' */
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void enter_atomic_OperationMode_ex4b(Bool rtu_PreProcessIn_atch, Bool rtu_PreProcessIn_mdz2, C_WPCWarning rtu_PreProcessIn_hjwo, Bool rtu_PreProcessIn_fbwq, Bool rtu_PreProcessIn_gi5q)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent;
  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCTimeO_fjff;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Mode_NFCTimeOutConfirm_giml();
  }

  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCSearc_gsrw;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
    App_M_NFCSearchingOffDelay_b5hj();
  }

  App_Model_DW.sfEvent = (sint32)event_CancelTimer_LPCDOffD_kg1v;
  if ((uint32)App_Model_DW.is_active_LPCDOffDelay != 0U) {
    App_Model_LPCDOffDelay_mp4k();
  }

  App_Model_DW.sfEvent = (sint32)event_CancelTimer_PICCOffD_fgqe;
  if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
    App_Model_PICCOffDelay_el5i();
  }

  App_Model_B.Output_OPT_WPCStatus = ModeOff;

  /* Output_WPC_NFCDetection = NFCDetection_Off; */
  App_Model_DW.sfEvent = (sint32)event_CancelTimer_PhnLeftC_akjh;
  if ((uint32)App_Model_DW.is_active_PhnLeftChattering != 0U) {
    App_Mode_PhnLeftChattering_jrtx();
  }

  App_Model_DW.sfEvent = b_previousEvent;
  App_Model_DW.Var_DrDoorPhnLftHoldComplete = 0.0;

  /* Outputs for IfAction SubSystem: '<S811>/WPC_NFCModeControl_compact' incorporates:
   *  ActionPort: '<S818>/ActionPort'
   */
  /* SwitchCase: '<S811>/Switch Case' incorporates:
   *  Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529'
   */
  App_DrDoorPhnLeftHoldCheck_byf3(rtu_PreProcessIn_atch, rtu_PreProcessIn_mdz2, rtu_PreProcessIn_hjwo, rtu_PreProcessIn_fbwq, rtu_PreProcessIn_gi5q);

  /* End of Outputs for SubSystem: '<S811>/WPC_NFCModeControl_compact' */
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void exit_atomic_OperationMode__jfok(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent;
  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCTimeO_fjff;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Mode_NFCTimeOutConfirm_giml();
  }

  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCSearc_gsrw;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
    App_M_NFCSearchingOffDelay_b5hj();
  }

  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCSearc_eghu;
  if ((uint32)App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
    App_Mo_NFCSearchingTimeout_k2k5();
  }

  App_Model_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void A_NFCSearchingOffDetection_niod(void)
{
  if ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCDeselect_Stop)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_StartTimer_NFCSearch_ljgd;
    if ((uint32)App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
      App_M_NFCSearchingOffDelay_b5hj();
    }

    App_Model_DW.sfEvent = c_previousEvent;
  } else if ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search)) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCSearc_gsrw;
    if ((uint32)App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
      App_M_NFCSearchingOffDelay_b5hj();
    }

    App_Model_DW.sfEvent = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Mode_NFCDetectionCheck_n2sn(void)
{
  if (((App_Model_DW.Receive_Flag_NFCDetection_prev != App_Model_DW.Receive_Flag_NFCDetection_start) && ((uint32)App_Model_DW.Receive_Flag_NFCDetection_start == On)) ||
      ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search))) {
    sint32 b_previousEvent;
    b_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCSearc_eghu;
    if ((uint32)App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
      App_Mo_NFCSearchingTimeout_k2k5();
    }

    App_Model_DW.sfEvent = b_previousEvent;
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void enter_atomic_OperationMode_ah2j(void)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent;
  App_Model_DW.sfEvent = (sint32)event_StartTimer_NFCTimeOu_dt5f;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Mode_NFCTimeOutConfirm_giml();
  }

  App_Model_DW.sfEvent = (sint32)event_StartTimer_NFCSearch_cveq;
  if ((uint32)App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
    App_Mo_NFCSearchingTimeout_k2k5();
  }

  App_Model_DW.sfEvent = b_previousEvent;
  A_NFCSearchingOffDetection_niod();
  App_Mode_NFCDetectionCheck_n2sn();
  App_Model_B.Output_OPT_WPCStatus = NFCMode;
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void App_Model_LPCDOff_Check_nsrx(Bool rtu_PreProcessIn_atch)
{
  if (((uint32)rtu_PreProcessIn_atch == Off) && !App_Model_DW.b_Timer_LPCDOffDelay_is_Running) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_StartTimer_LPCDOffDe_c055;
    if ((uint32)App_Model_DW.is_active_LPCDOffDelay != 0U) {
      App_Model_LPCDOffDelay_mp4k();
    }

    App_Model_DW.sfEvent = c_previousEvent;
  } else if ((uint32)rtu_PreProcessIn_atch == On) {
    sint32 c_previousEvent;
    c_previousEvent = App_Model_DW.sfEvent;
    App_Model_DW.sfEvent = (sint32)event_CancelTimer_LPCDOffD_kg1v;
    if ((uint32)App_Model_DW.is_active_LPCDOffDelay != 0U) {
      App_Model_LPCDOffDelay_mp4k();
    }

    App_Model_DW.sfEvent = c_previousEvent;
  } else {
    /* no actions */
  }
}

/* Function for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
static void enter_atomic_OperationMode_m2hb(Bool rtu_PreProcessIn_atch)
{
  sint32 b_previousEvent;
  b_previousEvent = App_Model_DW.sfEvent;
  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCTimeO_fjff;
  if ((uint32)App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
    App_Mode_NFCTimeOutConfirm_giml();
  }

  App_Model_DW.sfEvent = (sint32)event_CancelTimer_NFCSearc_gsrw;
  if ((uint32)App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
    App_M_NFCSearchingOffDelay_b5hj();
  }

  App_Model_DW.sfEvent = b_previousEvent;
  App_Model_B.Output_OPT_WPCStatus = LPCDMode;

  /* Outputs for IfAction SubSystem: '<S811>/WPC_NFCModeControl_compact' incorporates:
   *  ActionPort: '<S818>/ActionPort'
   */
  /* SwitchCase: '<S811>/Switch Case' incorporates:
   *  Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529'
   */
  /* Output_WPC_NFCDetection = NFCDetection_Off; */
  App_Model_LPCDOff_Check_nsrx(rtu_PreProcessIn_atch);

  /* End of Outputs for SubSystem: '<S811>/WPC_NFCModeControl_compact' */
}

/* System initialize for atomic system: '<S640>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control__ovav_Init(WPCStatus *rty_WPCStatus)
{
  /* SystemInitialize for IfAction SubSystem: '<S811>/WPC_Mode_Control' */
  App_Model_WPC_Mode_Control_Init(&App_Model_DW.WPC_Mode_Control_fuid);

  /* End of SystemInitialize for SubSystem: '<S811>/WPC_Mode_Control' */

  /* SystemInitialize for IfAction SubSystem: '<S811>/WPC_NFCModeControl_compact' */
  /* SystemInitialize for Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
  App_Model_DW.sfEvent = (sint32)App_Model_CALL_EVENT_lsjz;
  App_Model_DW.is_active_LPCDOffDelay = 0U;
  App_Model_DW.is_LPCDOffDelay = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_NFCSearchingOffDelay = 0U;
  App_Model_DW.is_NFCSearchingOffDelay = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_NFCSearchingTimeout = 0U;
  App_Model_DW.is_NFCSearchingTimeout = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_NFCTimeOutConfirm = 0U;
  App_Model_DW.is_NFCTimeOutConfirm = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_PICCOffDelay = 0U;
  App_Model_DW.is_PICCOffDelay = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_PhnLeftChattering = 0U;
  App_Model_DW.is_PhnLeftChattering = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_WPC_NFC_Mode_Control_ = 0U;
  App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_Mod_IN_NO_ACTIVE_CHILD_g2az;
  App_Model_DW.is_active_c56_NFC_WPC_Mode_Cont = 0U;
  App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
  App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
  App_Model_DW.b_Timer_LPCDOffDelay_is_Running = false;
  App_Model_DW.Timer_LPCDOffDelay = 0U;
  App_Model_DW.Timer_NFCSearchingTimeout = 0U;
  App_Model_DW.Timer_PICCOffDelay = 0.0;
  App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = false;
  App_Model_DW.Timer_PhnLeftChattering = 0.0;
  App_Model_DW.Var_DrDoorPhnLftHoldComplete = 0.0;
  App_Model_B.Output_OPT_WPCStatus = ModeOff;
  App_Model_DW.Var_DrDoorPhnLftHoldComplete_pr = 0.0;
  App_Model_DW.Var_DrDoorPhnLftHoldComplete_st = 0.0;
  App_Model_DW.Receive_Flag_NFCDetection_prev = NFCDetection_Off;
  App_Model_DW.Receive_Flag_NFCDetection_start = NFCDetection_Off;
  App_Model_DW.Input_IAUWPCNFCcmd_prev = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_IAUWPCNFCcmd_start = IAUWPCNFCcmdDefault;
  App_Model_DW.Input_b_DrvDrSw_prev = Off;
  App_Model_DW.Input_b_DrvDrSw_start = Off;
  App_Model_DW.Input_PhnLeftChk_Enable_prev = Off;
  App_Model_DW.Input_PhnLeftChk_Enable_start = Off;
  App_Model_DW.Receive_Flag_LPCD_Wakeup_prev = Off;
  App_Model_DW.Receive_Flag_LPCD_Wakeup_start = Off;
  App_Model_DW.Input_b_IGN1_IN_prev = Off;
  App_Model_DW.Input_b_IGN1_IN_start = Off;
  App_Model_DW.Input_OPT_WPCSWOption_prev = WPC_On;
  App_Model_DW.Input_OPT_WPCSWOption_start = WPC_On;

  /* End of SystemInitialize for SubSystem: '<S811>/WPC_NFCModeControl_compact' */

  /* SystemInitialize for Merge: '<S811>/Merge' */
  *rty_WPCStatus = ModeOff;
}

/* Output and update for atomic system: '<S640>/NFC_WPC_Mode_Control_Function' */
void NFC_WPC_Mode_Control_Funct_fw4e(Bool rtu_PreProcessIn, Bool rtu_PreProcessIn_atch, LC_IAUWPCNFCcmd rtu_PreProcessIn_ieah, LC_WPC_NFCDetection rtu_PreProcessIn_c42z, Bool rtu_PreProcessIn_pcj3,
  C_WPCOnOffNvalueSet rtu_PreProcessIn_hk4h, IAU_OwnerPhnRegRVal rtu_PreProcessIn_essy, OwnerPairingAdvertisingReq rtu_PreProcessIn_a10h, OnThePad rtu_PreProcessIn_gfq2, OnThePad rtu_PreProcessIn_a0oa,
  Bool rtu_PreProcessIn_mdz2, C_WPCWarning rtu_PreProcessIn_hjwo, OnThePad rtu_PreProcessIn_crop, Bool rtu_PreProcessIn_fbwq, Bool rtu_PreProcessIn_gi5q, Bool rtu_PreProcessIn_jhgz, WPCStatus
  *rty_WPCStatus)
{
  /* SwitchCase: '<S811>/Switch Case' */
  switch (rtu_PreProcessIn) {
   case Off:
    /* Outputs for IfAction SubSystem: '<S811>/WPC_Mode_Control' incorporates:
     *  ActionPort: '<S817>/ActionPort'
     */
    App_Model_WPC_Mode_Control(rtu_PreProcessIn_atch, rtu_PreProcessIn_hk4h, rtu_PreProcessIn_jhgz, rty_WPCStatus, &App_Model_DW.WPC_Mode_Control_fuid);

    /* End of Outputs for SubSystem: '<S811>/WPC_Mode_Control' */
    break;

   case On:
    {
      /* Outputs for IfAction SubSystem: '<S811>/WPC_NFCModeControl_compact' incorporates:
       *  ActionPort: '<S818>/ActionPort'
       */
      /* Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */
      App_Model_DW.sfEvent = (sint32)App_Model_CALL_EVENT_lsjz;
      App_Model_DW.Receive_Flag_NFCDetection_prev = App_Model_DW.Receive_Flag_NFCDetection_start;
      App_Model_DW.Receive_Flag_NFCDetection_start = rtu_PreProcessIn_c42z;
      App_Model_DW.Input_IAUWPCNFCcmd_prev = App_Model_DW.Input_IAUWPCNFCcmd_start;
      App_Model_DW.Input_IAUWPCNFCcmd_start = rtu_PreProcessIn_ieah;
      App_Model_DW.Input_b_DrvDrSw_prev = App_Model_DW.Input_b_DrvDrSw_start;
      App_Model_DW.Input_b_DrvDrSw_start = rtu_PreProcessIn_mdz2;
      App_Model_DW.Input_PhnLeftChk_Enable_prev = App_Model_DW.Input_PhnLeftChk_Enable_start;
      App_Model_DW.Input_PhnLeftChk_Enable_start = rtu_PreProcessIn_fbwq;
      App_Model_DW.Var_DrDoorPhnLftHoldComplete_pr = App_Model_DW.Var_DrDoorPhnLftHoldComplete_st;
      App_Model_DW.Var_DrDoorPhnLftHoldComplete_st = App_Model_DW.Var_DrDoorPhnLftHoldComplete;
      App_Model_DW.Receive_Flag_LPCD_Wakeup_prev = App_Model_DW.Receive_Flag_LPCD_Wakeup_start;
      App_Model_DW.Receive_Flag_LPCD_Wakeup_start = rtu_PreProcessIn_pcj3;
      App_Model_DW.Input_b_IGN1_IN_prev = App_Model_DW.Input_b_IGN1_IN_start;
      App_Model_DW.Input_b_IGN1_IN_start = rtu_PreProcessIn_atch;
      App_Model_DW.Input_OPT_WPCSWOption_prev = App_Model_DW.Input_OPT_WPCSWOption_start;
      App_Model_DW.Input_OPT_WPCSWOption_start = rtu_PreProcessIn_hk4h;
      if ((uint32)App_Model_DW.is_active_c56_NFC_WPC_Mode_Cont == 0U) {
        App_Model_DW.Receive_Flag_NFCDetection_prev = rtu_PreProcessIn_c42z;
        App_Model_DW.Input_IAUWPCNFCcmd_prev = rtu_PreProcessIn_ieah;
        App_Model_DW.Input_b_DrvDrSw_prev = rtu_PreProcessIn_mdz2;
        App_Model_DW.Input_PhnLeftChk_Enable_prev = rtu_PreProcessIn_fbwq;
        App_Model_DW.Receive_Flag_LPCD_Wakeup_prev = rtu_PreProcessIn_pcj3;
        App_Model_DW.Input_b_IGN1_IN_prev = rtu_PreProcessIn_atch;
        App_Model_DW.Input_OPT_WPCSWOption_prev = rtu_PreProcessIn_hk4h;
        App_Model_DW.is_active_c56_NFC_WPC_Mode_Cont = 1U;
        App_Model_DW.is_active_NFCTimeOutConfirm = 1U;
        App_Model_DW.is_NFCTimeOutConfirm = A_IN_NFCTimeOutConfirm_Off_h15f;
        App_Model_DW.Timer_NFCTimeOutConfirm = 0U;
        App_Model_DW.is_active_NFCSearchingOffDelay = 1U;
        App_Model_DW.is_NFCSearchingOffDelay = IN_NFCSearchingOffDelay_Of_p4ac;
        App_Model_DW.Timer_NFCSearchingOffDelay = 0U;
        App_Model_DW.is_active_LPCDOffDelay = 1U;
        App_Model_DW.is_LPCDOffDelay = App_Mo_IN_LPCDOffDelay_Off_f3el;
        App_Model_DW.b_Timer_LPCDOffDelay_is_Running = false;
        App_Model_DW.Timer_LPCDOffDelay = 0U;
        App_Model_DW.is_active_NFCSearchingTimeout = 1U;
        App_Model_DW.is_NFCSearchingTimeout = IN_NFCSearchingTimeout_Off_cpga;
        App_Model_DW.Timer_NFCSearchingTimeout = 0U;
        App_Model_DW.is_active_PICCOffDelay = 1U;
        App_Model_DW.is_PICCOffDelay = App_Mo_IN_PICCOffDelay_Off_a1d0;
        App_Model_DW.Timer_PICCOffDelay = 0.0;
        App_Model_DW.is_active_WPC_NFC_Mode_Control_ = 1U;

        /* Default */
        App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_Off_cmjb;
        enter_atomic_OperationMode_ex4b(rtu_PreProcessIn_atch, rtu_PreProcessIn_mdz2, rtu_PreProcessIn_hjwo, rtu_PreProcessIn_fbwq, rtu_PreProcessIn_gi5q);
        App_Model_DW.is_active_PhnLeftChattering = 1U;
        App_Model_DW.is_PhnLeftChattering = A_IN_PhnLeftChattering_Off_e5ff;
        App_Model_DW.b_Timer_PhnLeftChattering_is_Ru = false;
        App_Model_DW.Timer_PhnLeftChattering = 0.0;
      } else {
        if ((uint32)App_Model_DW.is_active_NFCTimeOutConfirm != 0U) {
          App_Mode_NFCTimeOutConfirm_giml();
        }

        if ((uint32)App_Model_DW.is_active_NFCSearchingOffDelay != 0U) {
          App_M_NFCSearchingOffDelay_b5hj();
        }

        if ((uint32)App_Model_DW.is_active_LPCDOffDelay != 0U) {
          App_Model_LPCDOffDelay_mp4k();
        }

        if ((uint32)App_Model_DW.is_active_NFCSearchingTimeout != 0U) {
          App_Mo_NFCSearchingTimeout_k2k5();
        }

        if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
          App_Model_PICCOffDelay_el5i();
        }

        if ((uint32)App_Model_DW.is_active_WPC_NFC_Mode_Control_ != 0U) {
          switch (App_Model_DW.is_WPC_NFC_Mode_Control_Functio) {
           case App__IN_OperationMode_LPCD_maec:
            App_Model_B.Output_OPT_WPCStatus = LPCDMode;

            /* 1 */
            if ((((uint32)rtu_PreProcessIn_hk4h == WPC_On) && ((uint32)rtu_PreProcessIn_atch == On) && ((uint32)rtu_PreProcessIn_ieah != WPCNFCPolling_Search) && (((uint32)rtu_PreProcessIn_essy ==
                   OwnerPhnReg__Enable) || ((uint32)rtu_PreProcessIn_a10h != OwnerPairingAdvertisingReq__StartEnable))) || ((App_Model_DW.Input_OPT_WPCSWOption_prev !=
                  App_Model_DW.Input_OPT_WPCSWOption_start) && ((uint32)App_Model_DW.Input_OPT_WPCSWOption_start == WPC_On))) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_WPC_hhld;
              App_Model_B.Output_OPT_WPCStatus = WPCMode;

              /* Output_WPC_NFCDetection = NFCDetection_Off; */

              /* 2 */
            } else if (((App_Model_DW.Receive_Flag_LPCD_Wakeup_prev != App_Model_DW.Receive_Flag_LPCD_Wakeup_start) && ((uint32)App_Model_DW.Receive_Flag_LPCD_Wakeup_start == On)) ||
                       ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search)) ||
                       ((App_Model_DW.Input_b_IGN1_IN_prev != App_Model_DW.Input_b_IGN1_IN_start) && ((uint32)App_Model_DW.Input_b_IGN1_IN_start == On))) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_NFC_lhcw;
              enter_atomic_OperationMode_ah2j();

              /* 3 */
            } else if ((((uint32)rtu_PreProcessIn_atch == Off) && (App_Model_DW.Timer_LPCDOffDelay >= (uint32)((uint16)6000U))) || (((uint32)rtu_PreProcessIn_atch == On) && ((uint32)
                         rtu_PreProcessIn_a10h != OwnerPairingAdvertisingReq__StartEnable) && ((uint32)rtu_PreProcessIn_hk4h == WPC_Off))) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_Off_cmjb;
              enter_atomic_OperationMode_ex4b(rtu_PreProcessIn_atch, rtu_PreProcessIn_mdz2, rtu_PreProcessIn_hjwo, rtu_PreProcessIn_fbwq, rtu_PreProcessIn_gi5q);
            } else {
              /* 4 */
              /* 230406 */
              App_Model_LPCDOff_Check_nsrx(rtu_PreProcessIn_atch);

              /* 230406 */
            }
            break;

           case App_M_IN_OperationMode_NFC_lhcw:
            {
              App_Model_B.Output_OPT_WPCStatus = NFCMode;
              if ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search)) {
                exit_atomic_OperationMode__jfok();
                App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_NFC_lhcw;
                enter_atomic_OperationMode_ah2j();

                /* 2 */
              } else if (((uint32)rtu_PreProcessIn_atch == On) && ((uint32)App_Model_DW.Input_OPT_WPCSWOption_start == WPC_On) && ((App_Model_DW.Timer_NFCSearchingOffDelay >= (uint32)((uint8)50U)) ||
                          (App_Model_DW.Timer_NFCTimeOutConfirm >= (uint32)((uint16)6000U)) || (App_Model_DW.Timer_NFCSearchingTimeout >= (uint32)((uint16)150U)))) {
                exit_atomic_OperationMode__jfok();
                App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_WPC_hhld;
                App_Model_B.Output_OPT_WPCStatus = WPCMode;

                /* Output_WPC_NFCDetection = NFCDetection_Off; */

                /* 3. */
              } else if ((((uint32)rtu_PreProcessIn_atch == Off) && (App_Model_DW.Timer_NFCSearchingOffDelay >= (uint32)((uint8)50U))) || (((uint32)rtu_PreProcessIn_atch == On) && ((uint32)
                           App_Model_DW.Input_OPT_WPCSWOption_start == WPC_Off) && (App_Model_DW.Timer_NFCSearchingOffDelay >= (uint32)((uint8)50U)))) {
                sint32 g_previousEvent;
                exit_atomic_OperationMode__jfok();
                App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App__IN_OperationMode_Picc_buju;
                g_previousEvent = App_Model_DW.sfEvent;
                App_Model_DW.sfEvent = (sint32)event_StartTimer_PICCOffDe_leur;
                if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
                  App_Model_PICCOffDelay_el5i();
                }

                App_Model_DW.sfEvent = g_previousEvent;
                App_Model_B.Output_OPT_WPCStatus = PICCMode;

                /* 4. */
                /* 5 */
              } else if ((App_Model_DW.Timer_NFCSearchingOffDelay >= (uint32)((uint8)50U)) || (App_Model_DW.Timer_NFCTimeOutConfirm >= (uint32)((uint16)6000U)) ||
                         (App_Model_DW.Timer_NFCSearchingTimeout >= (uint32)((uint16)150U))) {
                exit_atomic_OperationMode__jfok();
                App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App__IN_OperationMode_LPCD_maec;
                enter_atomic_OperationMode_m2hb(rtu_PreProcessIn_atch);
              } else {
                A_NFCSearchingOffDetection_niod();
                App_Mode_NFCDetectionCheck_n2sn();
              }
            }
            break;

           case App_M_IN_OperationMode_Off_cmjb:
            App_Model_B.Output_OPT_WPCStatus = ModeOff;

            /* 1 */
            if (((App_Model_DW.Var_DrDoorPhnLftHoldComplete_pr != App_Model_DW.Var_DrDoorPhnLftHoldComplete_st) && (App_Model_DW.Var_DrDoorPhnLftHoldComplete_st == 1.0)) || (((uint32)
                  rtu_PreProcessIn_atch == On) && ((uint32)rtu_PreProcessIn_a10h == OwnerPairingAdvertisingReq__StartEnable) && ((uint32)App_Model_DW.Input_OPT_WPCSWOption_start == WPC_Off))) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App__IN_OperationMode_LPCD_maec;
              enter_atomic_OperationMode_m2hb(rtu_PreProcessIn_atch);

              /* 2. */
            } else if ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search)) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_NFC_lhcw;
              enter_atomic_OperationMode_ah2j();
            } else if (((uint32)rtu_PreProcessIn_atch == On) && ((uint32)App_Model_DW.Input_OPT_WPCSWOption_start == WPC_On)) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_WPC_hhld;
              App_Model_B.Output_OPT_WPCStatus = WPCMode;

              /* Output_WPC_NFCDetection = NFCDetection_Off; */
            } else {
              App_DrDoorPhnLeftHoldCheck_byf3(rtu_PreProcessIn_atch, rtu_PreProcessIn_mdz2, rtu_PreProcessIn_hjwo, rtu_PreProcessIn_fbwq, rtu_PreProcessIn_gi5q);
            }
            break;

           case App__IN_OperationMode_Picc_buju:
            App_Model_B.Output_OPT_WPCStatus = PICCMode;

            /* 1 */
            if ((uint32)rtu_PreProcessIn_gfq2 == OnThePad_Off) {
              /* PhnRemoveMode
                 Output_WPC_NFCDetection = NFCDetection_Off; */
              App_Model_DW.sfEvent = (sint32)event_CancelTimer_PICCOffD_fgqe;
              if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
                App_Model_PICCOffDelay_el5i();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App__IN_OperationMode_LPCD_maec;
              enter_atomic_OperationMode_m2hb(rtu_PreProcessIn_atch);

              /* 2 */
            } else if (((uint32)rtu_PreProcessIn_atch == Off) && (App_Model_DW.Timer_PICCOffDelay >= (float64)((uint16)6000U))) {
              /* PhnRemoveMode
                 Output_WPC_NFCDetection = NFCDetection_Off; */
              App_Model_DW.sfEvent = (sint32)event_CancelTimer_PICCOffD_fgqe;
              if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
                App_Model_PICCOffDelay_el5i();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_Off_cmjb;
              enter_atomic_OperationMode_ex4b(rtu_PreProcessIn_atch, rtu_PreProcessIn_mdz2, rtu_PreProcessIn_hjwo, rtu_PreProcessIn_fbwq, rtu_PreProcessIn_gi5q);

              /* 3 */
            } else if ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search)) {
              /* PhnRemoveMode
                 Output_WPC_NFCDetection = NFCDetection_Off; */
              App_Model_DW.sfEvent = (sint32)event_CancelTimer_PICCOffD_fgqe;
              if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
                App_Model_PICCOffDelay_el5i();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_NFC_lhcw;
              enter_atomic_OperationMode_ah2j();

              /* 4 */
            } else if (((uint32)rtu_PreProcessIn_atch == On) && (((uint32)rtu_PreProcessIn_gfq2 == OnThePad_On) || (((uint32)rtu_PreProcessIn_gfq2 == OnThePad_Default) &&
                         (App_Model_DW.Timer_PICCOffDelay >= (float64)((uint16)500U)))) && ((uint32)rtu_PreProcessIn_hk4h == WPC_On)) {
              /* PhnRemoveMode
                 Output_WPC_NFCDetection = NFCDetection_Off; */
              App_Model_DW.sfEvent = (sint32)event_CancelTimer_PICCOffD_fgqe;
              if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
                App_Model_PICCOffDelay_el5i();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_WPC_hhld;
              App_Model_B.Output_OPT_WPCStatus = WPCMode;

              /* Output_WPC_NFCDetection = NFCDetection_Off; */
            } else {
              /* no actions */
            }
            break;

           case App_M_IN_OperationMode_WPC_hhld:
            App_Model_B.Output_OPT_WPCStatus = WPCMode;

            /* 1 */
            if ((App_Model_DW.Input_IAUWPCNFCcmd_prev != App_Model_DW.Input_IAUWPCNFCcmd_start) && ((uint32)App_Model_DW.Input_IAUWPCNFCcmd_start == WPCNFCPolling_Search)) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_NFC_lhcw;
              enter_atomic_OperationMode_ah2j();

              /* 2 */
            } else if ((((uint32)rtu_PreProcessIn_a0oa == OnThePad_Off) || ((uint32)rtu_PreProcessIn_crop == OnThePad_Off)) && (((uint32)rtu_PreProcessIn_essy == OwnerPhnReg__Disable) || ((uint32)
                         rtu_PreProcessIn_essy == OwnerPhnReg__Default) || ((uint32)rtu_PreProcessIn_essy == OwnerPhnReg__Invalid)) && ((uint32)rtu_PreProcessIn_a10h ==
                        OwnerPairingAdvertisingReq__StartEnable)) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App__IN_OperationMode_Picc_buju;
              App_Model_DW.sfEvent = (sint32)event_StartTimer_PICCOffDe_leur;
              if ((uint32)App_Model_DW.is_active_PICCOffDelay != 0U) {
                App_Model_PICCOffDelay_el5i();
              }

              App_Model_DW.sfEvent = -1;
              App_Model_B.Output_OPT_WPCStatus = PICCMode;

              /* 3 */
            } else if (((uint32)rtu_PreProcessIn_atch == Off) || ((uint32)rtu_PreProcessIn_hk4h == WPC_Off)) {
              App_Model_DW.is_WPC_NFC_Mode_Control_Functio = App_M_IN_OperationMode_Off_cmjb;
              enter_atomic_OperationMode_ex4b(rtu_PreProcessIn_atch, rtu_PreProcessIn_mdz2, rtu_PreProcessIn_hjwo, rtu_PreProcessIn_fbwq, rtu_PreProcessIn_gi5q);
            } else {
              /* no actions */
            }
            break;

           default:
            /* no actions */
            break;
          }
        }

        if ((uint32)App_Model_DW.is_active_PhnLeftChattering != 0U) {
          App_Mode_PhnLeftChattering_jrtx();
        }
      }

      /* End of Chart: '<S818>/NFC_WPC_Mode_Control_GN7PE_250529' */

      /* SignalConversion: '<S818>/Signal Conversion1' */
      *rty_WPCStatus = App_Model_B.Output_OPT_WPCStatus;

      /* End of Outputs for SubSystem: '<S811>/WPC_NFCModeControl_compact' */
    }
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S811>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
