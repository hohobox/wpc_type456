/*
 * File: WPC_MainControl_Function.c
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
#include "WPC_MainControl_Function.h"
#include "rtwtypes.h"
#include "App_Model.h"

/* Named constants for Chart: '<S212>/WPC_MainControl2_250507' */
#define A_event_Start_Timer_AmberINDBlk (7)
#define Ap_event_Cancel_Timer_PhoneLeft (3)
#define App_M_IN_LeavingPhone_NoWarning ((uint8)1U)
#define App_Mod_IN_LeavingPhone_Warning ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_otry ((uint8)0U)
#define App_Model_CALL_EVENT_fnhw      (-1)
#define App_Model_IN_Off_phf5          ((uint8)1U)
#define App_Model_IN_On_ph4v           ((uint8)2U)
#define App_Model_IN_WPCMode_Disable   ((uint8)1U)
#define App_Model_IN_WPCMode_Enable    ((uint8)2U)
#define App_Model_IN_WPCMode_Run       ((uint8)1U)
#define App_Model_IN_WPCMode_Stop      ((uint8)2U)
#define App_Model_IN_WPCRun_Charging   ((uint8)1U)
#define App_Model_IN_WPCRun_FODError   ((uint8)3U)
#define App_Model_IN_WPCRun_Standby    ((uint8)4U)
#define App_Model_IN_WPCStop_NotTempErr ((uint8)1U)
#define App_Model_IN_WPCStop_TempErr   ((uint8)2U)
#define App__IN_WPCRun_ChargingComplete ((uint8)2U)
#define App_event_Start_Timer_PhoneLeft (10)
#define event_Cancel_Timer_AmberINDBlk (0)
#define event_Cancel_Timer_AmberINDBlk2 (1)
#define event_Cancel_Timer_PhnLeftChatt (2)
#define event_Cancel_Timer_PhoneReminde (4)
#define event_Cancel_Timer_PhoneWarning (5)
#define event_Cancel_Timer_WarningCompl (6)
#define event_Start_Timer_AmberINDBlk2 (8)
#define event_Start_Timer_PhnLeftChatte (9)
#define event_Start_Timer_PhoneReminder (11)
#define event_Start_Timer_PhoneWarningC (12)
#define event_Start_Timer_WarningComple (13)

/* Named constants for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
#define Ap_IN_LeavingPhone_Warning_ehk4 ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_kgop ((uint8)0U)
#define App_Mod_IN_WPCMode_Disable_lsz5 ((uint8)1U)
#define App_Mod_IN_WPCRun_Charging_gdm3 ((uint8)1U)
#define App_Mod_IN_WPCRun_FODError_ba02 ((uint8)3U)
#define App_Mod_IN_WPCStop_TempErr_i2ty ((uint8)2U)
#define App_Mode_IN_WPCMode_Enable_glxy ((uint8)2U)
#define App_Mode_IN_WPCRun_Standby_nqhk ((uint8)4U)
#define App_Model_CALL_EVENT_ll15      (-1)
#define App_Model_IN_Off_oqv2          ((uint8)1U)
#define App_Model_IN_On_frgm           ((uint8)2U)
#define App_Model_IN_WPCMode_Init      ((uint8)3U)
#define App_Model_IN_WPCMode_NFC       ((uint8)1U)
#define App_Model_IN_WPCMode_Off       ((uint8)2U)
#define App_Model_IN_WPCMode_Run_f0sr  ((uint8)2U)
#define App_Model_IN_WPCMode_Stop_lkmx ((uint8)3U)
#define App__IN_WPCStop_NotTempErr_p5xt ((uint8)1U)
#define IN_LeavingPhone_NoWarning_gjzu ((uint8)1U)
#define IN_LeavingPhone_Warning_InWPCMo ((uint8)1U)
#define IN_WPCRun_ChargingComplete_h041 ((uint8)2U)
#define event_Cancel_Timer_AmberIN_lasm (0)
#define event_Cancel_Timer_AmberIN_mdtx (1)
#define event_Cancel_Timer_PhoneLe_b044 (2)
#define event_Cancel_Timer_PhoneWa_hjy0 (3)
#define event_Cancel_Timer_WarningTypeC (5)
#define event_Cancel_Timer_Warning_pka1 (4)
#define event_Start_Timer_AmberIND_dvx4 (7)
#define event_Start_Timer_AmberIND_k21q (6)
#define event_Start_Timer_PhoneLef_bbky (8)
#define event_Start_Timer_PhoneWar_iihy (9)
#define event_Start_Timer_WarningC_gju2 (10)
#define event_Start_Timer_WarningTypeCh (11)

/* Named constants for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
#define A_event_Cancel_Timer_CardINDBlk (2)
#define Ap_IN_LeavingPhone_Warning_lsxs ((uint8)2U)
#define Ap_event_Start_Timer_CardINDBlk (9)
#define App_Mod_IN_NO_ACTIVE_CHILD_gpfz ((uint8)0U)
#define App_Mod_IN_WPCMode_Disable_nt1b ((uint8)1U)
#define App_Mod_IN_WPCRun_Charging_k53m ((uint8)1U)
#define App_Mod_IN_WPCRun_FODError_hefu ((uint8)3U)
#define App_Mod_IN_WPCStop_TempErr_iyhn ((uint8)2U)
#define App_Mode_IN_WPCMode_Enable_eoox ((uint8)2U)
#define App_Mode_IN_WPCRun_Standby_mcah ((uint8)4U)
#define App_Model_CALL_EVENT_ajpu      (-1)
#define App_Model_IN_Off_eyrr          ((uint8)1U)
#define App_Model_IN_On_nf3k           ((uint8)2U)
#define App_Model_IN_WPCMode_Init_eart ((uint8)3U)
#define App_Model_IN_WPCMode_NFC_etgv  ((uint8)1U)
#define App_Model_IN_WPCMode_Off_azfk  ((uint8)2U)
#define App_Model_IN_WPCMode_Run_nyg1  ((uint8)1U)
#define App_Model_IN_WPCMode_Stop_babp ((uint8)2U)
#define App__IN_WPCStop_NotTempErr_iie2 ((uint8)1U)
#define IN_LeavingPhone_NoWarning_dpgw ((uint8)1U)
#define IN_WPCRun_ChargingComplete_lfsh ((uint8)2U)
#define event_Cancel_Timer_AmberIN_hohe (0)
#define event_Cancel_Timer_AmberIN_iv3b (1)
#define event_Cancel_Timer_PhoneLe_gauw (3)
#define event_Cancel_Timer_PhoneRe_edzf (4)
#define event_Cancel_Timer_PhoneWa_daos (5)
#define event_Cancel_Timer_Warning_ogip (6)
#define event_Start_Timer_AmberIND_fk4t (8)
#define event_Start_Timer_AmberIND_ggut (7)
#define event_Start_Timer_PhoneLef_hsco (10)
#define event_Start_Timer_PhoneRem_akzn (11)
#define event_Start_Timer_PhoneWar_mfiz (12)
#define event_Start_Timer_WarningC_ovzu (13)

/* Named constants for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
#define Ap_IN_LeavingPhone_Warning_adft ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_mv0c ((uint8)0U)
#define App_Mod_IN_WPCMode_Disable_bpa3 ((uint8)1U)
#define App_Mod_IN_WPCRun_Charging_hrde ((uint8)1U)
#define App_Mod_IN_WPCRun_FODError_nm1x ((uint8)3U)
#define App_Mod_IN_WPCStop_TempErr_kphv ((uint8)2U)
#define App_Mode_IN_WPCMode_Enable_pqhu ((uint8)2U)
#define App_Mode_IN_WPCRun_Standby_k4g3 ((uint8)4U)
#define App_Model_CALL_EVENT_gte2      (-1)
#define App_Model_IN_Off_nuz2          ((uint8)1U)
#define App_Model_IN_On_flaa           ((uint8)2U)
#define App_Model_IN_WPCMode_Init_ebss ((uint8)3U)
#define App_Model_IN_WPCMode_NFC_dm0v  ((uint8)1U)
#define App_Model_IN_WPCMode_Off_hmmp  ((uint8)2U)
#define App_Model_IN_WPCMode_Run_cd5k  ((uint8)2U)
#define App_Model_IN_WPCMode_Stop_ifk1 ((uint8)3U)
#define App__IN_WPCStop_NotTempErr_gqho ((uint8)1U)
#define IN_LeavingPhone_NoWarning_nxri ((uint8)1U)
#define IN_LeavingPhone_Warning_In_f01q ((uint8)1U)
#define IN_WPCRun_ChargingComplete_mgvv ((uint8)2U)
#define event_Cancel_Timer_AmberIN_fhe4 (0)
#define event_Cancel_Timer_AmberIN_l5xw (1)
#define event_Cancel_Timer_PhoneLe_jhwb (2)
#define event_Cancel_Timer_PhoneWa_pmk0 (3)
#define event_Cancel_Timer_Warning_diaj (5)
#define event_Cancel_Timer_Warning_geeb (4)
#define event_Start_Timer_AmberIND_bkdu (6)
#define event_Start_Timer_AmberIND_dk4p (7)
#define event_Start_Timer_PhoneLef_ikxf (8)
#define event_Start_Timer_PhoneWar_b3yi (9)
#define event_Start_Timer_WarningC_lx0t (10)
#define event_Start_Timer_WarningT_lnoc (11)

/* Named constants for Chart: '<S402>/WPC2_MainControl2_250507' */
#define Ap_IN_LeavingPhone_Warning_ji1s ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_ctxu ((uint8)0U)
#define App_Mod_IN_WPCMode_Disable_cyvt ((uint8)1U)
#define App_Mod_IN_WPCRun_Charging_aref ((uint8)1U)
#define App_Mod_IN_WPCRun_FODError_hm2b ((uint8)3U)
#define App_Mod_IN_WPCStop_TempErr_n0yp ((uint8)2U)
#define App_Mode_IN_WPCMode_Enable_jcmy ((uint8)2U)
#define App_Mode_IN_WPCRun_Standby_mdky ((uint8)4U)
#define App_Model_CALL_EVENT_eki3      (-1)
#define App_Model_IN_Off_hvcc          ((uint8)1U)
#define App_Model_IN_On_pbff           ((uint8)2U)
#define App_Model_IN_WPCMode_Run_ildf  ((uint8)1U)
#define App_Model_IN_WPCMode_Stop_aynr ((uint8)2U)
#define App__IN_WPCStop_NotTempErr_ccgp ((uint8)1U)
#define IN_LeavingPhone_NoWarning_dyop ((uint8)1U)
#define IN_WPCRun_ChargingComplete_jydm ((uint8)2U)
#define event_Cancel_Timer_AmberIN_eo3b (1)
#define event_Cancel_Timer_AmberIN_fgf5 (0)
#define event_Cancel_Timer_PhnLeft_ekpc (2)
#define event_Cancel_Timer_PhoneLe_ftby (3)
#define event_Cancel_Timer_PhoneRe_jjf3 (4)
#define event_Cancel_Timer_PhoneWa_hotu (5)
#define event_Cancel_Timer_Warning_niui (6)
#define event_Start_Timer_AmberIND_ho5y (8)
#define event_Start_Timer_AmberIND_jx2y (7)
#define event_Start_Timer_PhnLeftC_hlfc (9)
#define event_Start_Timer_PhoneLef_j1qj (10)
#define event_Start_Timer_PhoneRem_dsov (11)
#define event_Start_Timer_PhoneWar_n1mt (12)
#define event_Start_Timer_WarningC_esnt (13)

/* Named constants for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
#define App_Model_IN_WPCMode_Init_nxhy ((uint8)3U)
#define App_Model_IN_WPCMode_NFC_eleo  ((uint8)1U)
#define App_Model_IN_WPCMode_Off_nufv  ((uint8)2U)
#define App_Model_IN_WPCMode_Run_acpk  ((uint8)2U)
#define App_Model_IN_WPCMode_Stop_ihz1 ((uint8)3U)
#define IN_LeavingPhone_Warning_In_arkq ((uint8)1U)
#define event_Cancel_Timer_PhoneLe_n1xi (2)
#define event_Cancel_Timer_PhoneWa_ataa (3)
#define event_Cancel_Timer_Warning_as5n (5)
#define event_Cancel_Timer_Warning_dez2 (4)
#define event_Start_Timer_AmberIND_a1uc (6)
#define event_Start_Timer_AmberIND_h1p5 (7)
#define event_Start_Timer_PhoneLef_kbqs (8)
#define event_Start_Timer_PhoneWar_lqk1 (9)
#define event_Start_Timer_WarningC_fils (10)
#define event_Start_Timer_WarningT_nkmg (11)

/* Named constants for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
#define event_Cancel_Timer_CardIND_keyb (2)
#define event_Start_Timer_CardINDB_e5ba (9)

/* Named constants for Chart: '<S608>/RWPC_MainControl2_250507' */
#define Ap_IN_LeavingPhone_Warning_g052 ((uint8)2U)
#define App_Mod_IN_NO_ACTIVE_CHILD_ad3y ((uint8)0U)
#define App_Mod_IN_WPCMode_Disable_pcex ((uint8)1U)
#define App_Mod_IN_WPCRun_Charging_o2bp ((uint8)1U)
#define App_Mod_IN_WPCRun_FODError_ewty ((uint8)3U)
#define App_Mod_IN_WPCStop_TempErr_hdpu ((uint8)2U)
#define App_Mode_IN_WPCMode_Enable_jlo4 ((uint8)2U)
#define App_Mode_IN_WPCRun_Standby_dtiz ((uint8)4U)
#define App_Model_CALL_EVENT_mp4p      (-1)
#define App_Model_IN_Off_pxcg          ((uint8)1U)
#define App_Model_IN_On_g4y5           ((uint8)2U)
#define App_Model_IN_WPCMode_Run_oi2w  ((uint8)1U)
#define App_Model_IN_WPCMode_Stop_hnbq ((uint8)2U)
#define App__IN_WPCStop_NotTempErr_eapl ((uint8)1U)
#define IN_LeavingPhone_NoWarning_lklq ((uint8)1U)
#define IN_WPCRun_ChargingComplete_oknr ((uint8)2U)
#define event_Cancel_Timer_AmberIN_cile (0)
#define event_Cancel_Timer_AmberIN_cw02 (1)
#define event_Cancel_Timer_PhnLeft_hwkj (2)
#define event_Cancel_Timer_PhoneLe_fatc (3)
#define event_Cancel_Timer_PhoneRe_bamn (4)
#define event_Cancel_Timer_PhoneWa_mdmw (5)
#define event_Cancel_Timer_Warning_opqw (6)
#define event_Start_Timer_AmberIND_lptb (7)
#define event_Start_Timer_AmberIND_mkfa (8)
#define event_Start_Timer_PhnLeftC_dpmm (9)
#define event_Start_Timer_PhoneLef_n4dh (10)
#define event_Start_Timer_PhoneRem_jphw (11)
#define event_Start_Timer_PhoneWar_pusf (12)
#define event_Start_Timer_WarningC_gzuk (13)

/* Named constants for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
#define App_Model_IN_WPCMode_Init_e2hz ((uint8)3U)
#define App_Model_IN_WPCMode_NFC_bm2k  ((uint8)1U)
#define App_Model_IN_WPCMode_Off_likq  ((uint8)2U)
#define App_Model_IN_WPCMode_Run_gtpc  ((uint8)2U)
#define App_Model_IN_WPCMode_Stop_mk5d ((uint8)3U)
#define IN_LeavingPhone_Warning_In_exxx ((uint8)1U)
#define event_Cancel_Timer_PhoneLe_kfwe (2)
#define event_Cancel_Timer_PhoneWa_jyj3 (3)
#define event_Cancel_Timer_Warning_denu (5)
#define event_Cancel_Timer_Warning_o4g2 (4)
#define event_Start_Timer_AmberIND_djbs (7)
#define event_Start_Timer_AmberIND_k03b (6)
#define event_Start_Timer_PhoneLef_kata (8)
#define event_Start_Timer_PhoneWar_pc5i (9)
#define event_Start_Timer_WarningC_fats (10)
#define event_Start_Timer_WarningT_imcq (11)

/* Forward declaration for local functions */
static void App_Model_Tick_Timer_PhoneLeft(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void Ap_Tick_Timer_PhoneWarningCheck(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App_Mode_Tick_Timer_AmberINDBlk(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App_M_exit_internal_WPCMode_Run(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App_M_Function_ChargingINDColor(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd);
static void App_Mod_Tick_Timer_AmberINDBlk2(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App_Mode_Function_LEDErrorBlink(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdAmberSync, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, BlinkState *rty_BlinkState,
  DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App_Model_WPCMode_Run(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, Bool rtu_b_TemperatureFault, DeviceState rtu_DeviceState, WPCIndUSMState
  rtu_IND_WPCIndUSMState, Bool rtu_b_CmdAmberSync, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, Bool
  *rty_b_ChargingEnable, BlinkState *rty_BlinkState, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App__exit_internal_WPCMode_Stop(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void A_Tick_Timer_PhoneReminderCheck(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App__Tick_Timer_WarningComplete(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void Ap_Tick_Timer_PhnLeftChattering(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void App_Model_Function_WPCWarning(C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, C_WPCWarning *rty_C_WPCWarning, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void Ap_enter_atomic_WPCMode_Disable(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, uint16 *rty_b_Timer_PhoneReminderCheck, uint16
  *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer_Phone(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer__nj2u(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer__cg5k(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer_Warni(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer_Amber(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer__cvhw(DW_WPC_MainControl2_250507_Ap_T *localDW);
static void enter_internal_Tick_Timer_PhnLe(DW_WPC_MainControl2_250507_Ap_T *localDW);

/* Forward declaration for local functions */
static void App_Tick_Timer_AmberINDBlk_f2hb(DW_WPC_MainControl2_EV_250328_T *localDW);
static void exit_internal_WPCMode_Run_esdn(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl2_EV_250328_T *localDW);
static void Function_ChargingINDColor_c04u(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd);
static void Ap_Tick_Timer_AmberINDBlk2_gl4k(DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_Function_LEDErrorBlink_ly4n(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, BlinkState
  *rty_Output_BlinkState, DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_Tick_Timer_WarningTypeCheck(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_M_Tick_Timer_PhoneLeft_jjb3(DW_WPC_MainControl2_EV_250328_T *localDW);
static void Tick_Timer_PhoneWarningChe_cfdy(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_EV_250328_T *localDW);
static void Tick_Timer_WarningComplete_mg4j(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_Mo_Function_WPCWarning_elof(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, C_WPCWarning *rty_Output_WPCWarning, uint16
  *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_Model_WPCMode_Run_aqiy(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_DrvDrSw, GearPosSta
  rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *
  rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW);
static void exit_internal_WPCMode_Stop_knm3(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_atomic_WPCMode_Disab_ddfc(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW);
static void App__enter_internal_WPCMode_Off(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, C_WPCWarning
  *rty_Output_WPCWarning, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_Mo_enter_atomic_WPCMode_NFC(uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_EV_250328_T *localDW);
static void App_Model_WPCMode_Enable(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool
  rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool
  *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool
  *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW);
static void A_enter_internal_WPCMode_Enable(Bool rtu_Input_OPT_b_TemperatureFaul, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool
  *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState,
  DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_internal_Tick_Timer__btlk(DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_internal_Tick_Timer__mqe0(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_internal_Tick_Timer__f2oq(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_internal_Tick_Timer__eloo(DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_internal_Tick_Timer__bosw(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl2_EV_250328_T *localDW);
static void enter_internal_Tick_Timer__kbtb(DW_WPC_MainControl2_EV_250328_T *localDW);

/* Forward declaration for local functions */
static void App_Tick_Timer_AmberINDBlk_inx4(DW_WPC_MainControl3_CardSync__T *localDW);
static void exit_internal_WPCMode_Run_dawy(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl3_CardSync__T *localDW);
static void exit_internal_WPCMode_Stop_pahe(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_atomic_WPCMode_Disab_ejz1(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, BlinkState *rty_BlinkState, Bool
  *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *localDW);
static void App_M_Tick_Timer_PhoneLeft_hpwh(DW_WPC_MainControl3_CardSync__T *localDW);
static void Tick_Timer_PhoneWarningChe_nzwe(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl3_CardSync__T *localDW);
static void Tick_Timer_PhoneReminderCh_e2q5(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl3_CardSync__T *localDW);
static void Tick_Timer_WarningComplete_d50v(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl3_CardSync__T *localDW);
static void A_enter_atomic_WPCMode_NFC_bfni(uint16 *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl3_CardSync__T *localDW);
static void App_Mo_Function_WPCWarning_nh3i(C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, C_WPCWarning *rty_C_WPCWarning, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_WPCMode_Disable(C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, WPCStatus rtu_WPCStatus, C_WPCWarning
  *rty_C_WPCWarning, uint16 *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *
  localDW);
static void Ap_Tick_Timer_AmberINDBlk2_i5dr(DW_WPC_MainControl3_CardSync__T *localDW);
static void App_Function_LEDErrorBlink_jh0y(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, BlinkState *rty_BlinkState,
  DW_WPC_MainControl3_CardSync__T *localDW);
static void App_enter_internal_WPCMode_Stop(Bool rtu_b_TemperatureFault, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_AmberINDCmd, Bool
  *rty_b_BlinkState, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, DW_WPC_MainControl3_CardSync__T *localDW);
static void Function_ChargingINDColor_jywh(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd);
static void App_Model_WPCMode_Enable_pbu4(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_b_TemperatureFault, Bool rtu_C_AstDrSw,
  Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning
  rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl3_CardSync__T *localDW);
static void App_Model_Tick_Timer_CardINDBlk(DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer__pgf0(DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer__fqbw(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer__n0n5(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer__jsgj(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer__i5yz(DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer__m02b(DW_WPC_MainControl3_CardSync__T *localDW);
static void enter_internal_Tick_Timer_CardI(DW_WPC_MainControl3_CardSync__T *localDW);

/* Forward declaration for local functions */
static void App_Tick_Timer_AmberINDBlk_m40d(DW_WPC_MainControl_EV_250522__T *localDW);
static void exit_internal_WPCMode_Run_jkjs(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl_EV_250522__T *localDW);
static void Function_ChargingINDColor_ievi(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd);
static void Ap_Tick_Timer_AmberINDBlk2_eqqq(DW_WPC_MainControl_EV_250522__T *localDW);
static void App_Function_LEDErrorBlink_mtqm(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, BlinkState
  *rty_Output_BlinkState, DW_WPC_MainControl_EV_250522__T *localDW);
static void Tick_Timer_WarningTypeChec_ck1w(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl_EV_250522__T *localDW);
static void App_M_Tick_Timer_PhoneLeft_igxy(DW_WPC_MainControl_EV_250522__T *localDW);
static void Tick_Timer_PhoneWarningChe_f1qw(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl_EV_250522__T *localDW);
static void Tick_Timer_WarningComplete_fhjl(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl_EV_250522__T *localDW);
static void App_Mo_Function_WPCWarning_dcfw(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, C_WPCWarning *rty_Output_WPCWarning, uint16
  *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW);
static void App_Model_WPCMode_Run_nbvc(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_DrvDrSw, GearPosSta
  rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool
  *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16
  *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW);
static void exit_internal_WPCMode_Stop_hytv(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_atomic_WPCMode_Disab_m4cj(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_WPCMode_Off_mlee(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, C_WPCWarning
  *rty_Output_WPCWarning, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl_EV_250522__T *localDW);
static void A_enter_atomic_WPCMode_NFC_mzhi(uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl_EV_250522__T *localDW);
static void App_Model_WPCMode_Enable_dizk(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool
  rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool
  *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16
  *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_WPCMode_Ena_cy3v(Bool rtu_Input_OPT_b_TemperatureFaul, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool
  *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState,
  DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_Tick_Timer__bs5t(DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_Tick_Timer__fnog(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_Tick_Timer__f2g1(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_Tick_Timer__cbjs(DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_Tick_Timer__d3uy(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl_EV_250522__T *localDW);
static void enter_internal_Tick_Timer__gvic(DW_WPC_MainControl_EV_250522__T *localDW);

/* Forward declaration for local functions */
static void Tick_Timer_PhnLeftChatteri_b3cl(void);
static void Tick_Timer_PhoneReminderCh_dizt(void);
static void Tick_Timer_WarningComplete_nw2l(void);
static void App_M_Tick_Timer_PhoneLeft_mgtt(void);
static void Tick_Timer_PhoneWarningChe_cc3i(void);
static void App_Mo_Function_WPCWarning_anx5(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21);
static void Function_ChargingINDColor_nkrs(WPCIndUSMState rtu_Main_InSig_nwkh);
static void Ap_Tick_Timer_AmberINDBlk2_hmqx(void);
static void App_Tick_Timer_AmberINDBlk_bgbj(void);
static void App_Function_LEDErrorBlink_jeob(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void exit_internal_WPCMode_Run_a4zn(void);
static void App_Model_WPCMode_Run_cecy(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, Bool rtu_Main_InSig_gcjy, DeviceState rtu_Main_InSig_pg4m, WPCIndUSMState
  rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void exit_internal_WPCMode_Stop_kaxj(void);
static void enter_atomic_WPCMode_Disab_iqu4(void);
static void enter_internal_Tick_Timer__mysx(void);
static void enter_internal_Tick_Timer__poh4(void);
static void enter_internal_Tick_Timer__mz1h(void);
static void enter_internal_Tick_Timer__nbtx(void);
static void enter_internal_Tick_Timer__kdnl(void);
static void enter_internal_Tick_Timer__hqxq(void);
static void enter_internal_Tick_Timer__fi5q(void);
static void Function_ChargingINDColor_hytd(WPCIndUSMState rtu_Main_InSig_nwkh);
static void Ap_Tick_Timer_AmberINDBlk2_ecjj(void);
static void App_Tick_Timer_AmberINDBlk_czhp(void);
static void App_Function_LEDErrorBlink_clzh(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void exit_internal_WPCMode_Run_aiin(void);
static void Tick_Timer_WarningTypeChec_lutt(void);
static void App_M_Tick_Timer_PhoneLeft_c2km(void);
static void Tick_Timer_PhoneWarningChe_pom4(void);
static void Tick_Timer_WarningComplete_bggd(void);
static void App_Mo_Function_WPCWarning_hcv4(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21);
static void App_Model_WPCMode_Run_indc(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta rtu_Main_InSig_jgrv);
static void exit_internal_WPCMode_Stop_hr24(void);
static void enter_atomic_WPCMode_Disab_emnh(void);
static void enter_internal_WPCMode_Off_mwtd(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, GearPosSta rtu_Main_InSig_jgrv);
static void A_enter_atomic_WPCMode_NFC_exg2(void);
static void App_Model_WPCMode_Enable_kr2m(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta
  rtu_Main_InSig_jgrv);
static void enter_internal_WPCMode_Ena_oryk(Bool rtu_Main_InSig_gcjy, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void enter_internal_Tick_Timer__nlr0(void);
static void enter_internal_Tick_Timer__gq2v(void);
static void enter_internal_Tick_Timer__dzgk(void);
static void enter_internal_Tick_Timer__o1rh(void);
static void enter_internal_Tick_Timer__i2ff(void);
static void enter_internal_Tick_Timer__cxi4(void);
static void Function_ChargingINDColor_aroz(WPCIndUSMState rtu_Main_InSig_nwkh);
static void Ap_Tick_Timer_AmberINDBlk2_iopl(void);
static void App_Tick_Timer_AmberINDBlk_fqxk(void);
static void App_Function_LEDErrorBlink_ejqw(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void enter_internal_WPCMode_Sto_h1gw(Bool rtu_Main_InSig_gcjy, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void exit_internal_WPCMode_Run_fhr1(void);
static void exit_internal_WPCMode_Stop_dxd4(void);
static void enter_atomic_WPCMode_Disab_or5p(void);
static void App_M_Tick_Timer_PhoneLeft_jzcf(void);
static void Tick_Timer_PhoneWarningChe_lzxg(void);
static void Tick_Timer_PhoneReminderCh_f2nt(void);
static void Tick_Timer_WarningComplete_njjk(void);
static void App_Mo_Function_WPCWarning_n3ee(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21);
static void A_enter_atomic_WPCMode_NFC_jagk(void);
static void enter_internal_WPCMode_Dis_o4re(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, WPCStatus rtu_Main_InSig_pov1);
static void App_Model_WPCMode_Enable_lmai(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs,
  C_WPCWarning rtu_Main_InSig_lhyq);
static void App__Tick_Timer_CardINDBlk_mju2(void);
static void enter_internal_Tick_Timer__eqcb(void);
static void enter_internal_Tick_Timer__g2zg(void);
static void enter_internal_Tick_Timer__mm4n(void);
static void enter_internal_Tick_Timer__akvt(void);
static void enter_internal_Tick_Timer__pcsj(void);
static void enter_internal_Tick_Timer__fsrs(void);
static void enter_internal_Tick_Timer__jdfo(void);
static void Function_ChargingINDColor_bjlk(WPCIndUSMState rtu_Main_InSig_nwkh);
static void Ap_Tick_Timer_AmberINDBlk2_pqgr(void);
static void App_Tick_Timer_AmberINDBlk_cdeg(void);
static void App_Function_LEDErrorBlink_jrjx(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void exit_internal_WPCMode_Run_mjyr(void);
static void Tick_Timer_WarningTypeChec_j1qx(void);
static void App_M_Tick_Timer_PhoneLeft_bizk(void);
static void Tick_Timer_PhoneWarningChe_d40l(void);
static void Tick_Timer_WarningComplete_poap(void);
static void App_Mo_Function_WPCWarning_kxrk(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21);
static void App_Model_WPCMode_Run_kcl3(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool rtu_Main_InSig_nv40, Bool
  rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta rtu_Main_InSig_jgrv, C_WPCWarning rtu_Main_InSig_lhyq);
static void exit_internal_WPCMode_Stop_fyoo(void);
static void enter_atomic_WPCMode_Disab_diah(void);
static void enter_internal_WPCMode_Off_iu3m(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, GearPosSta rtu_Main_InSig_jgrv);
static void A_enter_atomic_WPCMode_NFC_ggnd(void);
static void App_Model_WPCMode_Enable_a3go(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool rtu_Main_InSig_nv40, Bool
  rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta rtu_Main_InSig_jgrv, C_WPCWarning
  rtu_Main_InSig_lhyq);
static void enter_internal_WPCMode_Ena_bzqz(Bool rtu_Main_InSig_gcjy, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs);
static void enter_internal_Tick_Timer__eqt5(void);
static void enter_internal_Tick_Timer__afno(void);
static void enter_internal_Tick_Timer__djfr(void);
static void enter_internal_Tick_Timer__kc5l(void);
static void enter_internal_Tick_Timer__la5p(void);
static void enter_internal_Tick_Timer__pr3d(void);

/* Forward declaration for local functions */
static void Tick_Timer_PhnLeftChatteri_bjsy(void);
static void Tick_Timer_PhoneReminderCh_kfry(void);
static void Tick_Timer_WarningComplete_krdu(void);
static void App_M_Tick_Timer_PhoneLeft_gv5q(void);
static void Tick_Timer_PhoneWarningChe_jngs(void);
static void App_Mo_Function_WPCWarning_h44q(C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_exqx, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli);
static void Function_ChargingINDColor_ebqs(WPCIndUSMState rtu_Main_InSig_i4oh);
static void Ap_Tick_Timer_AmberINDBlk2_cmm0(void);
static void App_Tick_Timer_AmberINDBlk_ezex(void);
static void App_Function_LEDErrorBlink_mwqe(WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x);
static void exit_internal_WPCMode_Run_nddy(void);
static void App_Model_WPCMode_Run_nopn(Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, Bool rtu_Main_InSig_bvye, DeviceState rtu_Main_InSig_o3od, WPCIndUSMState
  rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x);
static void exit_internal_WPCMode_Stop_on5z(void);
static void enter_atomic_WPCMode_Disab_ewpa(void);
static void enter_internal_Tick_Timer__hri5(void);
static void enter_internal_Tick_Timer__jpd4(void);
static void enter_internal_Tick_Timer__b25k(void);
static void enter_internal_Tick_Timer__bo0g(void);
static void enter_internal_Tick_Timer__gv5p(void);
static void enter_internal_Tick_Timer__jc4l(void);
static void enter_internal_Tick_Timer__ku30(void);
static void Function_ChargingINDColor_jq5h(WPCIndUSMState rtu_Main_InSig_i4oh);
static void Ap_Tick_Timer_AmberINDBlk2_p5ah(void);
static void App_Tick_Timer_AmberINDBlk_li22(void);
static void App_Function_LEDErrorBlink_f23p(WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x);
static void exit_internal_WPCMode_Run_aifz(void);
static void Tick_Timer_WarningTypeChec_bias(void);
static void App_M_Tick_Timer_PhoneLeft_ofh0(void);
static void Tick_Timer_PhoneWarningChe_h4zv(void);
static void Tick_Timer_WarningComplete_ci2o(void);
static void App_Mo_Function_WPCWarning_a0qj(C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli);
static void App_Model_WPCMode_Run_ksb1(Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_bvye, Bool
  rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, DeviceState rtu_Main_InSig_o3od, WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x, GearPosSta rtu_Main_InSig_m0c4);
static void exit_internal_WPCMode_Stop_mh2b(void);
static void enter_atomic_WPCMode_Disab_e3k4(void);
static void enter_internal_WPCMode_Off_fjwh(C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, GearPosSta rtu_Main_InSig_m0c4);
static void A_enter_atomic_WPCMode_NFC_khti(void);
static void App_Model_WPCMode_Enable_hnge(Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_bvye, Bool
  rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, DeviceState rtu_Main_InSig_o3od, WPCStatus rtu_Main_InSig_ll4c, WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x, GearPosSta
  rtu_Main_InSig_m0c4);
static void enter_internal_WPCMode_Ena_l2l1(Bool rtu_Main_InSig_bvye, WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x);
static void enter_internal_Tick_Timer__llj1(void);
static void enter_internal_Tick_Timer__dbsl(void);
static void enter_internal_Tick_Timer__mias(void);
static void enter_internal_Tick_Timer__pzsw(void);
static void enter_internal_Tick_Timer__fsed(void);
static void enter_internal_Tick_Timer__jpu3(void);

/*
 * System initialize for atomic system:
 *    '<S25>/Chart'
 *    '<S220>/Chart'
 *    '<S642>/Chart'
 */
void App_Model_Chart_Init(MainContMode *rty_MainContMode, DW_Chart_App_Model_T *localDW)
{
  localDW->is_active_c6_App_Model = 0U;
  *rty_MainContMode = nonNFC_ICE;
}

/*
 * System reset for atomic system:
 *    '<S25>/Chart'
 *    '<S220>/Chart'
 *    '<S642>/Chart'
 */
void App_Model_Chart_Reset(MainContMode *rty_MainContMode, DW_Chart_App_Model_T *localDW)
{
  localDW->is_active_c6_App_Model = 0U;
  *rty_MainContMode = nonNFC_ICE;
}

/*
 * Output and update for atomic system:
 *    '<S25>/Chart'
 *    '<S220>/Chart'
 *    '<S642>/Chart'
 */
void App_Model_Chart(Bool rtu_Uds_m_NFCOption, Bool rtu_NvM_EVOpt, MainContMode *rty_MainContMode, DW_Chart_App_Model_T *localDW)
{
  /* Chart: '<S25>/Chart' */
  if ((uint32)localDW->is_active_c6_App_Model == 0U) {
    localDW->is_active_c6_App_Model = 1U;
    if (((uint32)rtu_Uds_m_NFCOption == Off) && ((uint32)rtu_NvM_EVOpt == Off)) {
      *rty_MainContMode = nonNFC_ICE;
    } else if (((uint32)rtu_Uds_m_NFCOption == Off) && ((uint32)rtu_NvM_EVOpt == On)) {
      *rty_MainContMode = nonNFC_EV;
    } else if (((uint32)rtu_Uds_m_NFCOption == On) && ((uint32)rtu_NvM_EVOpt == Off)) {
      *rty_MainContMode = NFC_ICE;
    } else if (((uint32)rtu_Uds_m_NFCOption == On) && ((uint32)rtu_NvM_EVOpt == On)) {
      *rty_MainContMode = NFC_EV;
    } else {
      /* no actions */
    }
  } else if (((uint32)rtu_Uds_m_NFCOption == Off) && ((uint32)rtu_NvM_EVOpt == Off)) {
    *rty_MainContMode = nonNFC_ICE;
  } else if (((uint32)rtu_Uds_m_NFCOption == Off) && ((uint32)rtu_NvM_EVOpt == On)) {
    *rty_MainContMode = nonNFC_EV;
  } else if (((uint32)rtu_Uds_m_NFCOption == On) && ((uint32)rtu_NvM_EVOpt == Off)) {
    *rty_MainContMode = NFC_ICE;
  } else if (((uint32)rtu_Uds_m_NFCOption == On) && ((uint32)rtu_NvM_EVOpt == On)) {
    *rty_MainContMode = NFC_EV;
  } else {
    /* no actions */
  }

  /* End of Chart: '<S25>/Chart' */
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_Model_Tick_Timer_PhoneLeft(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneLeft) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)App_event_Start_Timer_PhoneLeft) {
      localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_On_ph4v;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)Ap_event_Cancel_Timer_PhoneLeft) {
        localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_phf5;
        localDW->Timer_PhoneLeft = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneLeft + 1;
        if (((sint32)localDW->Timer_PhoneLeft + 1) > 255) {
          tmp = 255;
        }

        localDW->Timer_PhoneLeft = (uint8)tmp;
        if (localDW->sfEvent == (sint32)App_event_Start_Timer_PhoneLeft) {
          localDW->Timer_PhoneLeft = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void Ap_Tick_Timer_PhoneWarningCheck(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneWarningCheck) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWarningC) {
      localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_On_ph4v;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneWarning) {
        localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_phf5;
        localDW->Timer_PhoneWarningCheck = 0U;
        *rty_b_Timer_PhoneWarningCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneWarningCheck + 1;
        if (((sint32)localDW->Timer_PhoneWarningCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhoneWarningCheck = (uint16)tmp;
        *rty_b_Timer_PhoneWarningCheck = localDW->Timer_PhoneWarningCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWarningC) {
          localDW->Timer_PhoneWarningCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_Mode_Tick_Timer_AmberINDBlk(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)A_event_Start_Timer_AmberINDBlk) {
      localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_On_ph4v;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberINDBlk) {
        localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_phf5;
        localDW->Timer_AmberINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk + 1;
        if (((sint32)localDW->Timer_AmberINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk = (uint16)tmp;
        if (localDW->sfEvent == (sint32)A_event_Start_Timer_AmberINDBlk) {
          localDW->Timer_AmberINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_M_exit_internal_WPCMode_Run(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Run == App_Model_IN_WPCRun_FODError) {
    sint32 b_previousEvent;
    *rty_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Mode_Tick_Timer_AmberINDBlk(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_b_BlinkState = Off;
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  } else {
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_M_Function_ChargingINDColor(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd)
{
  /* 1. */
  if ((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) {
    *rty_b_GreenINDCmd = On;
    *rty_b_AmberINDCmd = Off;
  } else {
    *rty_b_GreenINDCmd = Off;
    *rty_b_AmberINDCmd = On;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_Mod_Tick_Timer_AmberINDBlk2(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk2) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberINDBlk2) {
      localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_On_ph4v;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberINDBlk2) {
        localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_phf5;
        localDW->Timer_AmberINDBlk2 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk2 + 1;
        if (((sint32)localDW->Timer_AmberINDBlk2 + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk2 = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberINDBlk2) {
          localDW->Timer_AmberINDBlk2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_Mode_Function_LEDErrorBlink(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdAmberSync, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, BlinkState *rty_BlinkState,
  DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (rtu_b_CmdAmberSync) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)(*rty_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 == App_Model_IN_Off_phf5)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk == App_Model_IN_Off_phf5)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                   localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                    localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOff;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)(*rty_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 == App_Model_IN_Off_phf5)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberINDBlk2;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
          App_Mod_Tick_Timer_AmberINDBlk2(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk == App_Model_IN_Off_phf5)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                   localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                    localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOff;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)A_event_Start_Timer_AmberINDBlk;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Mode_Tick_Timer_AmberINDBlk(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_Model_WPCMode_Run(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, Bool rtu_b_TemperatureFault, DeviceState rtu_DeviceState, WPCIndUSMState
  rtu_IND_WPCIndUSMState, Bool rtu_b_CmdAmberSync, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, Bool
  *rty_b_ChargingEnable, BlinkState *rty_BlinkState, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  /* 1. */
  if (((uint32)rtu_b_LFState == On) || ((uint32)rtu_b_CurrentFault == On) || ((uint32)rtu_b_TempSensorFault == On) || ((uint32)rtu_b_TemperatureFault == On)) {
    App_M_exit_internal_WPCMode_Run(rty_b_BlinkState, rty_BlinkState, localDW);
    localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop;
    *rty_b_FANModeCmd = Off;
    *rty_b_GreenINDCmd = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    *rty_b_ChargingEnable = Off;

    /* 1. */
    if ((uint32)rtu_b_TemperatureFault == On) {
      localDW->is_WPCMode_Stop = App_Model_IN_WPCStop_TempErr;
      *rty_C_WPCWarning = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      *rty_BlinkState = BlinkOff;
      localDW->Counter_BlinkCnt = 0U;
      App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

      /*  Non GFS  */
      *rty_b_BlinkState = On;
    } else {
      localDW->is_WPCMode_Stop = App_Model_IN_WPCStop_NotTempErr;
      *rty_C_WPCWarning = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      *rty_b_AmberINDCmd = Off;
    }
  } else {
    switch (localDW->is_WPCMode_Run) {
     case App_Model_IN_WPCRun_Charging:
      *rty_b_FANModeCmd = On;

      /* 1. */
      if (((uint32)rtu_DeviceState == Standby) || ((uint32)rtu_DeviceState == Init)) {
        localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Standby;
        *rty_C_WPCWarning = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_b_FANModeCmd = Off;
        *rty_b_GreenINDCmd = Off;
        *rty_b_AmberINDCmd = Off;
      } else {
        /* 2. */
        switch (rtu_DeviceState) {
         case FODError:
          /*  b_FODFault == On] */
          localDW->is_WPCMode_Run = App_Model_IN_WPCRun_FODError;
          *rty_C_WPCWarning = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;
          App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

          /*  Non GFS  */
          *rty_b_BlinkState = On;
          break;

         case Full_Charge:
          /* 3. */
          localDW->is_WPCMode_Run = App__IN_WPCRun_ChargingComplete;
          *rty_C_WPCWarning = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_b_FANModeCmd = On;
          *rty_b_GreenINDCmd = On;
          *rty_b_AmberINDCmd = Off;
          break;

         default:
          App_M_Function_ChargingINDColor(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
          break;
        }
      }
      break;

     case App__IN_WPCRun_ChargingComplete:
      *rty_b_FANModeCmd = On;

      /* 1. */
      if (((uint32)rtu_DeviceState == Standby) || ((uint32)rtu_DeviceState == Init)) {
        localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Standby;
        *rty_C_WPCWarning = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_b_FANModeCmd = Off;
        *rty_b_GreenINDCmd = Off;
        *rty_b_AmberINDCmd = Off;
      } else {
        /* 2. */
        switch (rtu_DeviceState) {
         case FODError:
          /*  b_FODFault == On] */
          localDW->is_WPCMode_Run = App_Model_IN_WPCRun_FODError;
          *rty_C_WPCWarning = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;
          App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

          /*  Non GFS  */
          *rty_b_BlinkState = On;
          break;

         case Charging:
          /* 3. */
          localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Charging;
          *rty_C_WPCWarning = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_b_FANModeCmd = On;
          App_M_Function_ChargingINDColor(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Model_IN_WPCRun_FODError:
      {
        *rty_b_FANModeCmd = Off;

        /* 1. */
        if (((uint32)rtu_DeviceState == Standby) || ((uint32)rtu_DeviceState == Init)) {
          sint32 c_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          *rty_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          c_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
          if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
            App_Mode_Tick_Timer_AmberINDBlk(localDW);
          }

          localDW->sfEvent = c_previousEvent;

          /*  Non GFS  */
          *rty_b_BlinkState = Off;
          localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Standby;
          *rty_C_WPCWarning = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;
          *rty_b_AmberINDCmd = Off;
        } else {
          /* 2. */
          switch (rtu_DeviceState) {
           case Charging:
            {
              sint32 c_previousEvent;

              /* BlinkState == BlinkComplete 8차 적용 */
              *rty_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              c_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
              if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Mode_Tick_Timer_AmberINDBlk(localDW);
              }

              localDW->sfEvent = c_previousEvent;

              /*  Non GFS  */
              *rty_b_BlinkState = Off;
              localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Charging;
              *rty_C_WPCWarning = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_b_FANModeCmd = On;
              App_M_Function_ChargingINDColor(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
            }
            break;

           case Full_Charge:
            {
              sint32 c_previousEvent;

              /* 3. */
              /* BlinkState == BlinkComplete 8차 적용 */
              *rty_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              c_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
              if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Mode_Tick_Timer_AmberINDBlk(localDW);
              }

              localDW->sfEvent = c_previousEvent;

              /*  Non GFS  */
              *rty_b_BlinkState = Off;
              localDW->is_WPCMode_Run = App__IN_WPCRun_ChargingComplete;
              *rty_C_WPCWarning = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_b_FANModeCmd = On;
              *rty_b_GreenINDCmd = On;
              *rty_b_AmberINDCmd = Off;
            }
            break;

           default:
            App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);
            break;
          }
        }
      }
      break;

     case App_Model_IN_WPCRun_Standby:
      *rty_b_FANModeCmd = Off;

      /* 1. */
      switch (rtu_DeviceState) {
       case FODError:
        /*  b_FODFault == On] */
        localDW->is_WPCMode_Run = App_Model_IN_WPCRun_FODError;
        *rty_C_WPCWarning = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        *rty_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = 0U;
        *rty_b_FANModeCmd = Off;
        *rty_b_GreenINDCmd = Off;
        App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

        /*  Non GFS  */
        *rty_b_BlinkState = On;
        break;

       case Charging:
        /* 2. */
        localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Charging;
        *rty_C_WPCWarning = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        *rty_b_FANModeCmd = On;
        App_M_Function_ChargingINDColor(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
        break;

       case Full_Charge:
        /* 3. */
        localDW->is_WPCMode_Run = App__IN_WPCRun_ChargingComplete;
        *rty_C_WPCWarning = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        *rty_b_FANModeCmd = On;
        *rty_b_GreenINDCmd = On;
        *rty_b_AmberINDCmd = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App__exit_internal_WPCMode_Stop(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Stop == App_Model_IN_WPCStop_TempErr) {
    sint32 b_previousEvent;
    *rty_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Mode_Tick_Timer_AmberINDBlk(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_b_BlinkState = Off;
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  } else {
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void A_Tick_Timer_PhoneReminderCheck(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneReminderChec) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneReminder) {
      localDW->is_Tick_Timer_PhoneReminderChec = App_Model_IN_On_ph4v;
      localDW->b_Timer_PhoneReminderCheck_is_R = On;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneReminde) {
        localDW->is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_phf5;
        localDW->Timer_PhoneReminderCheck = 0U;
        *rty_b_Timer_PhoneReminderCheck = 0U;
        localDW->b_Timer_PhoneReminderCheck_is_R = Off;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneReminderCheck + 1;
        if (((sint32)localDW->Timer_PhoneReminderCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhoneReminderCheck = (uint16)tmp;
        *rty_b_Timer_PhoneReminderCheck = localDW->Timer_PhoneReminderCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneReminder) {
          localDW->Timer_PhoneReminderCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App__Tick_Timer_WarningComplete(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_WarningComplete) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)event_Start_Timer_WarningComple) {
      localDW->is_Tick_Timer_WarningComplete = App_Model_IN_On_ph4v;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_WarningCompl) {
        localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_phf5;
        localDW->Timer_WarningComplete = 0U;
        *rty_b_Timer_WarningComplete = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_WarningComplete + 1;
        if (((sint32)localDW->Timer_WarningComplete + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_WarningComplete = (uint16)tmp;
        *rty_b_Timer_WarningComplete = localDW->Timer_WarningComplete;
        if (localDW->sfEvent == (sint32)event_Start_Timer_WarningComple) {
          localDW->Timer_WarningComplete = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void Ap_Tick_Timer_PhnLeftChattering(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  switch (localDW->is_Tick_Timer_PhnLeftChattering) {
   case App_Model_IN_Off_phf5:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhnLeftChatte) {
      localDW->is_Tick_Timer_PhnLeftChattering = App_Model_IN_On_ph4v;
    }
    break;

   case App_Model_IN_On_ph4v:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhnLeftChatt) {
        localDW->is_Tick_Timer_PhnLeftChattering = App_Model_IN_Off_phf5;
        localDW->Timer_PhnLeftChattering = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhnLeftChattering + 1;
        if (((sint32)localDW->Timer_PhnLeftChattering + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhnLeftChattering = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhnLeftChatte) {
          localDW->Timer_PhnLeftChattering = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void App_Model_Function_WPCWarning(C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, C_WPCWarning *rty_C_WPCWarning, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  /* 1 */
  if (((uint32)rtu_WPCSWOption == WPC_Off) || ((localDW->Timer_PhoneWarningCheck >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_b_WPCPhoneExist == Off)) || (localDW->Timer_PhoneLeft >= ((uint8)50U)))
  {
    sint32 d_previousEvent;
    *rty_C_WPCWarning = WPCWarningOff;
    localDW->b_WarnClearEnable = Off;
    *rty_b_PhnLeftChk_Enable = Off;
    d_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_PhoneLeft;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_Model_Tick_Timer_PhoneLeft(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWarning;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneReminde;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
      A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_WarningCompl;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      App__Tick_Timer_WarningComplete(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = d_previousEvent;
  } else {
    sint32 d_previousEvent;
    Bool tmp;

    /* 1. */
    tmp = localDW->b_WPCPhoneExist_start;
    if (((uint32)localDW->b_WarnClearEnable == On) && ((localDW->b_WPCPhoneExist_prev != tmp) && ((uint32)tmp == Off))) {
      d_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)App_event_Start_Timer_PhoneLeft;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_Model_Tick_Timer_PhoneLeft(localDW);
      }

      localDW->sfEvent = d_previousEvent;

      /* 1. */
    } else if (((uint32)localDW->is_Tick_Timer_PhoneLeft == App_Model_IN_On_ph4v) && ((uint32)rtu_b_WPCPhoneExist == On)) {
      d_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_PhoneLeft;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_Model_Tick_Timer_PhoneLeft(localDW);
      }

      localDW->sfEvent = d_previousEvent;
    } else {
      /* no actions */
    }

    if ((localDW->Timer_PhoneWarningCheck >= ((uint16)10U)) && (localDW->Timer_PhoneWarningCheck <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_b_WPCPhoneExist == On)) {
      *rty_C_WPCWarning = Cellphoneonthepad;
      localDW->b_WarnClearEnable = On;
      d_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWarning;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
        Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
      }

      localDW->sfEvent = (sint32)event_Start_Timer_PhoneReminder;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
        A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
      }

      localDW->sfEvent = d_previousEvent;

      /* 5차 적용 */
    } else {
      tmp = localDW->C_DrvDrSw_start;
      if (((uint32)localDW->b_Timer_PhoneReminderCheck_is_R == On) && (localDW->Timer_PhoneReminderCheck < ((uint16)6000U)) && ((uint32)localDW->b_WarnClearEnable == On) && ((uint32)
           rtu_b_WPCPhoneExist == On) && (((localDW->C_DrvDrSw_prev != tmp) && ((uint32)tmp == On)) || ((localDW->C_AstDrSw_prev != localDW->C_AstDrSw_start) && ((uint32)localDW->C_AstDrSw_start == On))))
      {
        *rty_C_WPCWarning = Cellphoneonthepad;
        d_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneReminde;
        if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
          A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
        }

        localDW->sfEvent = (sint32)event_Start_Timer_PhnLeftChatte;
        if ((uint32)localDW->is_active_Tick_Timer_PhnLeftCha != 0U) {
          Ap_Tick_Timer_PhnLeftChattering(localDW);
        }

        localDW->sfEvent = d_previousEvent;
      } else if ((localDW->Timer_PhoneReminderCheck >= ((uint16)6000U)) && ((uint32)localDW->b_WarnClearEnable == On) && ((uint32)rtu_b_WPCPhoneExist == On)) {
        /* 1. */
        if (((uint32)rtu_C_DrvDrSw == On) || ((uint32)rtu_C_AstDrSw == On)) {
          localDW->b_WarnClearEnable = Off;
          *rty_C_WPCWarning = WPCWarningOff;
          *rty_b_PhnLeftChk_Enable = Off;
          d_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneReminde;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
            A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
          }

          localDW->sfEvent = d_previousEvent;
        } else {
          /* 2. */
          *rty_C_WPCWarning = Cellphonereminder;
          d_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneReminde;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
            A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Start_Timer_WarningComple;
          if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
            App__Tick_Timer_WarningComplete(rty_b_Timer_WarningComplete, localDW);
          }

          localDW->sfEvent = d_previousEvent;
        }
      } else if ((localDW->Timer_WarningComplete >= ((uint16)50U)) && ((uint32)localDW->b_WarnClearEnable == On) && ((uint32)rtu_b_WPCPhoneExist == On)) {
        *rty_C_WPCWarning = WPCWarningOff;
        localDW->b_WarnClearEnable = Off;
        *rty_b_PhnLeftChk_Enable = Off;
        d_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_WarningCompl;
        if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
          App__Tick_Timer_WarningComplete(rty_b_Timer_WarningComplete, localDW);
        }

        localDW->sfEvent = d_previousEvent;
      } else if ((localDW->Timer_PhnLeftChattering >= ((uint16)600U)) && ((uint32)localDW->b_WarnClearEnable == On) && ((uint32)rtu_b_WPCPhoneExist == On)) {
        *rty_C_WPCWarning = WPCWarningOff;
        localDW->b_WarnClearEnable = Off;
        d_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_PhnLeftChatt;
        if ((uint32)localDW->is_active_Tick_Timer_PhnLeftCha != 0U) {
          Ap_Tick_Timer_PhnLeftChattering(localDW);
        }

        localDW->sfEvent = d_previousEvent;
      } else {
        /* no actions */
      }
    }
  }
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void Ap_enter_atomic_WPCMode_Disable(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, uint16 *rty_b_Timer_PhoneReminderCheck, uint16
  *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  sint32 b_previousEvent;

  /* Chart: '<S212>/WPC_MainControl2_250507' */
  *rty_C_WPCWarning = WPCWarningOff;
  *rty_BlinkState = BlinkOff;
  localDW->Counter_BlinkCnt = 0U;
  localDW->b_WarnClearEnable = Off;

  /* Chart: '<S212>/WPC_MainControl2_250507' */
  *rty_b_FANModeCmd = Off;
  *rty_b_GreenINDCmd = Off;
  *rty_b_AmberINDCmd = Off;
  *rty_b_PhnLeftChk_Enable = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
  if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
    App_Mode_Tick_Timer_AmberINDBlk(localDW);
  }

  localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_PhoneLeft;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
    App_Model_Tick_Timer_PhoneLeft(localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWarning;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
    /* Chart: '<S212>/WPC_MainControl2_250507' */
    Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneReminde;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
    /* Chart: '<S212>/WPC_MainControl2_250507' */
    A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_WarningCompl;
  if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
    /* Chart: '<S212>/WPC_MainControl2_250507' */
    App__Tick_Timer_WarningComplete(rty_b_Timer_WarningComplete, localDW);
  }

  localDW->sfEvent = b_previousEvent;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer_Phone(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_phf5;
  localDW->Timer_PhoneLeft = 0U;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__nj2u(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_phf5;
  localDW->Timer_PhoneWarningCheck = 0U;

  /* Chart: '<S212>/WPC_MainControl2_250507' */
  *rty_b_Timer_PhoneWarningCheck = 0U;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__cg5k(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_phf5;
  localDW->Timer_PhoneReminderCheck = 0U;

  /* Chart: '<S212>/WPC_MainControl2_250507' */
  *rty_b_Timer_PhoneReminderCheck = 0U;
  localDW->b_Timer_PhoneReminderCheck_is_R = Off;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer_Warni(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_phf5;
  localDW->Timer_WarningComplete = 0U;

  /* Chart: '<S212>/WPC_MainControl2_250507' */
  *rty_b_Timer_WarningComplete = 0U;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer_Amber(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_phf5;
  localDW->Timer_AmberINDBlk = 0U;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__cvhw(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_phf5;
  localDW->Timer_AmberINDBlk2 = 0U;
}

/* Function for Chart: '<S212>/WPC_MainControl2_250507' */
static void enter_internal_Tick_Timer_PhnLe(DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->is_Tick_Timer_PhnLeftChattering = App_Model_IN_Off_phf5;
  localDW->Timer_PhnLeftChattering = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S212>/WPC_MainControl2_250507'
 *    '<S834>/WPC_MainControl2_250507'
 */
void Ap_WPC_MainControl2_250507_Init(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_fnhw;
  localDW->is_active_MainControl = 0U;
  localDW->is_MainControl = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_AmberINDBl = 0U;
  localDW->is_Tick_Timer_AmberINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_Amber_aksf = 0U;
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_PhnLeftCha = 0U;
  localDW->is_Tick_Timer_PhnLeftChattering = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_PhoneLeft = 0U;
  localDW->is_Tick_Timer_PhoneLeft = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_PhoneRemin = 0U;
  localDW->is_Tick_Timer_PhoneReminderChec = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_PhoneWarni = 0U;
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_Tick_Timer_WarningCom = 0U;
  localDW->is_Tick_Timer_WarningComplete = App_Mod_IN_NO_ACTIVE_CHILD_otry;
  localDW->is_active_c42_MainControl_Lib = 0U;
  localDW->b_WarnClearEnable = Off;
  localDW->Timer_AmberINDBlk = 0U;
  localDW->Timer_PhoneLeft = 0U;
  localDW->Timer_PhoneReminderCheck = 0U;
  localDW->Timer_PhoneWarningCheck = 0U;
  localDW->Timer_WarningComplete = 0U;
  localDW->Counter_BlinkCnt = 0U;
  localDW->Timer_AmberINDBlk2 = 0U;
  localDW->Timer_PhnLeftChattering = 0U;
  localDW->b_Timer_PhoneReminderCheck_is_R = Off;
  *rty_C_WPCWarning = WPCWarningOff;
  *rty_b_FANModeCmd = Off;
  *rty_b_GreenINDCmd = Off;
  *rty_b_AmberINDCmd = Off;
  *rty_b_BlinkState = Off;
  *rty_b_Timer_PhoneReminderCheck = 0U;
  *rty_b_Timer_PhoneWarningCheck = 0U;
  *rty_b_Timer_WarningComplete = 0U;
  *rty_b_ChargingEnable = Off;
  *rty_BlinkState = BlinkOff;
  *rty_b_PhnLeftChk_Enable = Off;
  localDW->b_WPCPhoneExist_prev = Off;
  localDW->b_WPCPhoneExist_start = Off;
  localDW->C_DrvDrSw_prev = Off;
  localDW->C_DrvDrSw_start = Off;
  localDW->C_AstDrSw_prev = Off;
  localDW->C_AstDrSw_start = Off;
  localDW->WPCIndCmdState_prev = WPCIndCmdState__Default;
  localDW->WPCIndCmdState_start = WPCIndCmdState__Default;
  localDW->L_IGN1_IN_prev = Off;
  localDW->L_IGN1_IN_start = Off;
}

/*
 * Output and update for atomic system:
 *    '<S212>/WPC_MainControl2_250507'
 *    '<S834>/WPC_MainControl2_250507'
 */
void App_Mod_WPC_MainControl2_250507(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_b_TemperatureFault, Bool rtu_C_AstDrSw, Bool
  rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool rtu_L_IGN1_IN, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdAmberSync, WPCIndCmdState
  rtu_WPCIndCmdState, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16 *rty_b_Timer_PhoneReminderCheck, uint16
  *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_250507_Ap_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_fnhw;
  localDW->b_WPCPhoneExist_prev = localDW->b_WPCPhoneExist_start;
  localDW->b_WPCPhoneExist_start = rtu_b_WPCPhoneExist;
  localDW->C_DrvDrSw_prev = localDW->C_DrvDrSw_start;
  localDW->C_DrvDrSw_start = rtu_C_DrvDrSw;
  localDW->C_AstDrSw_prev = localDW->C_AstDrSw_start;
  localDW->C_AstDrSw_start = rtu_C_AstDrSw;
  localDW->WPCIndCmdState_prev = localDW->WPCIndCmdState_start;
  localDW->WPCIndCmdState_start = rtu_WPCIndCmdState;
  localDW->L_IGN1_IN_prev = localDW->L_IGN1_IN_start;
  localDW->L_IGN1_IN_start = rtu_L_IGN1_IN;

  /* Chart: '<S212>/WPC_MainControl2_250507' */
  if ((uint32)localDW->is_active_c42_MainControl_Lib == 0U) {
    Bool tmp;
    localDW->b_WPCPhoneExist_prev = rtu_b_WPCPhoneExist;
    localDW->C_DrvDrSw_prev = rtu_C_DrvDrSw;
    localDW->C_AstDrSw_prev = rtu_C_AstDrSw;
    localDW->WPCIndCmdState_prev = rtu_WPCIndCmdState;
    localDW->L_IGN1_IN_prev = rtu_L_IGN1_IN;
    localDW->is_active_c42_MainControl_Lib = 1U;
    localDW->is_active_MainControl = 1U;
    localDW->is_MainControl = App_Model_IN_WPCMode_Disable;
    Ap_enter_atomic_WPCMode_Disable(rty_C_WPCWarning, rty_b_FANModeCmd, rty_b_GreenINDCmd, rty_b_AmberINDCmd, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete,
      rty_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
    tmp = localDW->L_IGN1_IN_start;
    if ((localDW->L_IGN1_IN_prev != tmp) && ((uint32)tmp == Off)) {
      sint32 f_previousEvent;
      localDW->is_WPCMode_Disable = App_Mod_IN_LeavingPhone_Warning;
      f_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Start_Timer_PhoneWarningC;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
        Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
      }

      localDW->sfEvent = f_previousEvent;
      App_Model_Function_WPCWarning(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
        rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
      *rty_b_PhnLeftChk_Enable = On;
    } else {
      localDW->is_WPCMode_Disable = App_M_IN_LeavingPhone_NoWarning;
    }

    localDW->is_active_Tick_Timer_PhoneLeft = 1U;
    enter_internal_Tick_Timer_Phone(localDW);
    localDW->is_active_Tick_Timer_PhoneWarni = 1U;
    enter_internal_Tick_Timer__nj2u(rty_b_Timer_PhoneWarningCheck, localDW);
    localDW->is_active_Tick_Timer_PhoneRemin = 1U;
    enter_internal_Tick_Timer__cg5k(rty_b_Timer_PhoneReminderCheck, localDW);
    localDW->is_active_Tick_Timer_WarningCom = 1U;
    enter_internal_Tick_Timer_Warni(rty_b_Timer_WarningComplete, localDW);
    localDW->is_active_Tick_Timer_AmberINDBl = 1U;
    enter_internal_Tick_Timer_Amber(localDW);
    localDW->is_active_Tick_Timer_Amber_aksf = 1U;
    enter_internal_Tick_Timer__cvhw(localDW);
    localDW->is_active_Tick_Timer_PhnLeftCha = 1U;
    enter_internal_Tick_Timer_PhnLe(localDW);
  } else {
    if ((uint32)localDW->is_active_MainControl != 0U) {
      switch (localDW->is_MainControl) {
       case App_Model_IN_WPCMode_Disable:
        *rty_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_WPCStatus == WPCMode) {
          if ((uint32)localDW->is_WPCMode_Disable == App_Mod_IN_LeavingPhone_Warning) {
            localDW->b_WarnClearEnable = Off;
            *rty_b_PhnLeftChk_Enable = Off;
            localDW->sfEvent = (sint32)Ap_event_Cancel_Timer_PhoneLeft;
            if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
              App_Model_Tick_Timer_PhoneLeft(localDW);
            }

            localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWarning;
            if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
              Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
            }

            localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneReminde;
            if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
              A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
            }

            localDW->sfEvent = (sint32)event_Cancel_Timer_WarningCompl;
            if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
              App__Tick_Timer_WarningComplete(rty_b_Timer_WarningComplete, localDW);
            }

            localDW->sfEvent = -1;
            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_otry;
          } else {
            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_otry;
          }

          localDW->is_MainControl = App_Model_IN_WPCMode_Enable;
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop;
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;

          /* b_ROHMOperCmd = Off /_ Non GFS _/ */
          *rty_b_ChargingEnable = Off;

          /* 1. */
          if ((uint32)rtu_b_TemperatureFault == On) {
            localDW->is_WPCMode_Stop = App_Model_IN_WPCStop_TempErr;
            *rty_C_WPCWarning = Charging_error;

            /* b_WPCWarn = Charging_error 8차 LFRollBack */
            *rty_BlinkState = BlinkOff;
            localDW->Counter_BlinkCnt = 0U;
            App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

            /*  Non GFS  */
            *rty_b_BlinkState = On;
          } else {
            localDW->is_WPCMode_Stop = App_Model_IN_WPCStop_NotTempErr;
            *rty_C_WPCWarning = WPCWarningOff;

            /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
            *rty_b_AmberINDCmd = Off;
          }
        } else if ((uint32)localDW->is_WPCMode_Disable == App_Mod_IN_LeavingPhone_Warning) {
          App_Model_Function_WPCWarning(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
            rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
        } else {
          /* no actions */
        }
        break;

       case App_Model_IN_WPCMode_Enable:
        {
          /* 1. */
          if ((uint32)rtu_WPCStatus == ModeOff) {
            Bool tmp;
            switch (localDW->is_WPCMode_Enable) {
             case App_Model_IN_WPCMode_Run:
              App_M_exit_internal_WPCMode_Run(rty_b_BlinkState, rty_BlinkState, localDW);
              localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_otry;
              break;

             case App_Model_IN_WPCMode_Stop:
              App__exit_internal_WPCMode_Stop(rty_b_BlinkState, rty_BlinkState, localDW);
              localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_otry;
              break;

             default:
              /* no actions */
              break;
            }

            /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
            *rty_b_ChargingEnable = Off;
            localDW->is_MainControl = App_Model_IN_WPCMode_Disable;
            Ap_enter_atomic_WPCMode_Disable(rty_C_WPCWarning, rty_b_FANModeCmd, rty_b_GreenINDCmd, rty_b_AmberINDCmd, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
              rty_b_Timer_WarningComplete, rty_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
            tmp = localDW->L_IGN1_IN_start;
            if ((localDW->L_IGN1_IN_prev != tmp) && ((uint32)tmp == Off)) {
              sint32 f_previousEvent;
              localDW->is_WPCMode_Disable = App_Mod_IN_LeavingPhone_Warning;
              f_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Start_Timer_PhoneWarningC;
              if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
                Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
              }

              localDW->sfEvent = f_previousEvent;
              App_Model_Function_WPCWarning(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
                rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
              *rty_b_PhnLeftChk_Enable = On;
            } else {
              localDW->is_WPCMode_Disable = App_M_IN_LeavingPhone_NoWarning;
            }
          } else {
            switch (localDW->is_WPCMode_Enable) {
             case App_Model_IN_WPCMode_Run:
              App_Model_WPCMode_Run(rtu_b_LFState, rtu_b_CurrentFault, rtu_b_TempSensorFault, rtu_b_TemperatureFault, rtu_DeviceState, rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_C_WPCWarning,
                                    rty_b_FANModeCmd, rty_b_GreenINDCmd, rty_b_AmberINDCmd, rty_b_BlinkState, rty_b_ChargingEnable, rty_BlinkState, localDW);
              break;

             case App_Model_IN_WPCMode_Stop:
              *rty_b_FANModeCmd = Off;
              if (((uint32)rtu_DeviceState == Full_Charge) && ((uint32)rtu_b_LFState == Off) && ((uint32)rtu_b_CurrentFault == Off) && ((uint32)rtu_b_TemperatureFault == Off) && ((uint32)
                   rtu_b_TempSensorFault == Off)) {
                App__exit_internal_WPCMode_Stop(rty_b_BlinkState, rty_BlinkState, localDW);
                localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run;

                /* b_ROHMOperCmd = On /_ Non GFS _/ */
                *rty_b_ChargingEnable = On;
                localDW->is_WPCMode_Run = App__IN_WPCRun_ChargingComplete;
                *rty_C_WPCWarning = Charging_Complete;

                /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                *rty_b_FANModeCmd = On;
                *rty_b_GreenINDCmd = On;
                *rty_b_AmberINDCmd = Off;
              } else if (((uint32)rtu_DeviceState == Charging) && ((uint32)rtu_b_LFState == Off) && ((uint32)rtu_b_CurrentFault == Off) && ((uint32)rtu_b_TemperatureFault == Off) && ((uint32)
                          rtu_b_TempSensorFault == Off)) {
                App__exit_internal_WPCMode_Stop(rty_b_BlinkState, rty_BlinkState, localDW);
                localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run;

                /* b_ROHMOperCmd = On /_ Non GFS _/ */
                *rty_b_ChargingEnable = On;
                localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Charging;
                *rty_C_WPCWarning = PhoneCharging;

                /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                *rty_b_FANModeCmd = On;
                App_M_Function_ChargingINDColor(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
              } else {
                switch (localDW->is_WPCMode_Stop) {
                 case App_Model_IN_WPCStop_NotTempErr:
                  /* 1. */
                  if ((uint32)rtu_b_TemperatureFault == On) {
                    localDW->is_WPCMode_Stop = App_Model_IN_WPCStop_TempErr;
                    *rty_C_WPCWarning = Charging_error;

                    /* b_WPCWarn = Charging_error 8차 LFRollBack */
                    *rty_BlinkState = BlinkOff;
                    localDW->Counter_BlinkCnt = 0U;
                    App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

                    /*  Non GFS  */
                    *rty_b_BlinkState = On;

                    /* 2. */
                  } else if (((uint32)rtu_b_LFState == Off) && ((uint32)rtu_b_CurrentFault == Off) && ((uint32)rtu_b_TempSensorFault == Off)) {
                    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_otry;
                    localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    *rty_b_ChargingEnable = On;
                    localDW->is_WPCMode_Run = App_Model_IN_WPCRun_Standby;
                    *rty_C_WPCWarning = WPCWarningOff;

                    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                    *rty_b_FANModeCmd = Off;
                    *rty_b_GreenINDCmd = Off;
                    *rty_b_AmberINDCmd = Off;
                  } else {
                    /* no actions */
                  }
                  break;

                 case App_Model_IN_WPCStop_TempErr:
                  /* 1. */
                  if ((uint32)rtu_b_TemperatureFault == Off) {
                    *rty_BlinkState = BlinkOff;
                    localDW->Counter_BlinkCnt = 0U;
                    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberINDBlk;
                    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                      App_Mode_Tick_Timer_AmberINDBlk(localDW);
                    }

                    localDW->sfEvent = -1;

                    /*  Non GFS  */
                    *rty_b_BlinkState = Off;
                    localDW->is_WPCMode_Stop = App_Model_IN_WPCStop_NotTempErr;
                    *rty_C_WPCWarning = WPCWarningOff;

                    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                    *rty_b_AmberINDCmd = Off;
                  } else {
                    App_Mode_Function_LEDErrorBlink(rtu_IND_WPCIndUSMState, rtu_b_CmdAmberSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);
                  }
                  break;

                 default:
                  /* no actions */
                  break;
                }
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

    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_Model_Tick_Timer_PhoneLeft(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Ap_Tick_Timer_PhoneWarningCheck(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
      A_Tick_Timer_PhoneReminderCheck(rty_b_Timer_PhoneReminderCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      App__Tick_Timer_WarningComplete(rty_b_Timer_WarningComplete, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Mode_Tick_Timer_AmberINDBlk(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_Amber_aksf != 0U) {
      App_Mod_Tick_Timer_AmberINDBlk2(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhnLeftCha != 0U) {
      Ap_Tick_Timer_PhnLeftChattering(localDW);
    }
  }

  /* End of Chart: '<S212>/WPC_MainControl2_250507' */
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Tick_Timer_AmberINDBlk_f2hb(DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk) {
   case App_Model_IN_Off_oqv2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_k21q) {
      localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_On_frgm;
    }
    break;

   case App_Model_IN_On_frgm:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberIN_lasm) {
        localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_oqv2;
        localDW->Timer_AmberINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk + 1;
        if (((sint32)localDW->Timer_AmberINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_k21q) {
          localDW->Timer_AmberINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void exit_internal_WPCMode_Run_esdn(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Run == App_Mod_IN_WPCRun_FODError_ba02) {
    sint32 b_previousEvent;
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_f2hb(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_Output_OPT_b_BlinkState = Off;
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  } else {
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void Function_ChargingINDColor_c04u(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd)
{
  /* 1. */
  if ((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) {
    *rty_Output_OPT_b_GreenINDCmd = On;
    *rty_Output_OPT_b_AmberINDCmd = Off;
  } else {
    *rty_Output_OPT_b_GreenINDCmd = Off;
    *rty_Output_OPT_b_AmberINDCmd = On;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void Ap_Tick_Timer_AmberINDBlk2_gl4k(DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk2) {
   case App_Model_IN_Off_oqv2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_dvx4) {
      localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_On_frgm;
    }
    break;

   case App_Model_IN_On_frgm:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberIN_mdtx) {
        localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_oqv2;
        localDW->Timer_AmberINDBlk2 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk2 + 1;
        if (((sint32)localDW->Timer_AmberINDBlk2 + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk2 = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_dvx4) {
          localDW->Timer_AmberINDBlk2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Function_LEDErrorBlink_ly4n(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, BlinkState
  *rty_Output_BlinkState, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (rtu_b_CmdLEDSync) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)(*rty_Output_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_mdtx;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_mdtx;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 ==
                  App_Model_IN_Off_oqv2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dvx4;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk ==
                  App_Model_IN_Off_oqv2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_Output_OPT_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_k21q;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
                  ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_k21q;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
        ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOff;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_k21q;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dvx4;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dvx4;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)(*rty_Output_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_mdtx;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_mdtx;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 ==
                  App_Model_IN_Off_oqv2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dvx4;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk ==
                  App_Model_IN_Off_oqv2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_Output_OPT_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_k21q;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
                  ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_k21q;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
        ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOff;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_k21q;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_f2hb(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dvx4;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dvx4;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Tick_Timer_WarningTypeCheck(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (localDW->is_Tick_Timer_WarningTypeCheck) {
   case App_Model_IN_Off_oqv2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_WarningTypeCh) {
      localDW->is_Tick_Timer_WarningTypeCheck = App_Model_IN_On_frgm;
    }
    break;

   case App_Model_IN_On_frgm:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_WarningTypeC) {
        localDW->is_Tick_Timer_WarningTypeCheck = App_Model_IN_Off_oqv2;
        localDW->Timer_WarningTypeCheck = 0U;
        *rty_b_Timer_WarningTypeCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_WarningTypeCheck + 1;
        if (((sint32)localDW->Timer_WarningTypeCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_WarningTypeCheck = (uint16)tmp;
        *rty_b_Timer_WarningTypeCheck = localDW->Timer_WarningTypeCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_WarningTypeCh) {
          localDW->Timer_WarningTypeCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_M_Tick_Timer_PhoneLeft_jjb3(DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneLeft) {
   case App_Model_IN_Off_oqv2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneLef_bbky) {
      localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_On_frgm;
    }
    break;

   case App_Model_IN_On_frgm:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneLe_b044) {
        localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_oqv2;
        localDW->Timer_PhoneLeft = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneLeft + 1;
        if (((sint32)localDW->Timer_PhoneLeft + 1) > 255) {
          tmp = 255;
        }

        localDW->Timer_PhoneLeft = (uint8)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneLef_bbky) {
          localDW->Timer_PhoneLeft = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void Tick_Timer_PhoneWarningChe_cfdy(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneWarningCheck) {
   case App_Model_IN_Off_oqv2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWar_iihy) {
      localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_On_frgm;
    }
    break;

   case App_Model_IN_On_frgm:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneWa_hjy0) {
        localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_oqv2;
        localDW->Timer_PhoneWarningCheck = 0U;
        *rty_b_Timer_PhoneWarningCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneWarningCheck + 1;
        if (((sint32)localDW->Timer_PhoneWarningCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhoneWarningCheck = (uint16)tmp;
        *rty_b_Timer_PhoneWarningCheck = localDW->Timer_PhoneWarningCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWar_iihy) {
          localDW->Timer_PhoneWarningCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void Tick_Timer_WarningComplete_mg4j(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  switch (localDW->is_Tick_Timer_WarningComplete) {
   case App_Model_IN_Off_oqv2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_WarningC_gju2) {
      localDW->is_Tick_Timer_WarningComplete = App_Model_IN_On_frgm;
    }
    break;

   case App_Model_IN_On_frgm:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_Warning_pka1) {
        localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_oqv2;
        localDW->Timer_WarningComplete = 0U;
        *rty_b_Timer_WarningComplete = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_WarningComplete + 1;
        if (((sint32)localDW->Timer_WarningComplete + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_WarningComplete = (uint16)tmp;
        *rty_b_Timer_WarningComplete = localDW->Timer_WarningComplete;
        if (localDW->sfEvent == (sint32)event_Start_Timer_WarningC_gju2) {
          localDW->Timer_WarningComplete = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Mo_Function_WPCWarning_elof(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, C_WPCWarning *rty_Output_WPCWarning, uint16
  *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  /*  WPC 모드가 해제 or 폰 감지가 안되었을 경우 or 출력 후 폰 가져간 경우900ms */
  if (((uint32)rtu_Input_OPT_b_WPCSWOption == WPC_Off) || ((localDW->Timer_PhoneWarningCheck >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Input_OPT_b_WPCPhoneExist == Off)) ||
      (localDW->Timer_PhoneLeft >= ((uint8)50U))) {
    sint32 c_previousEvent;

    /* 500m */
    /*  Warning OffNidec */
    *rty_Output_WPCWarning = WPCWarningOff;

    /* Output_WPCWarning = SavedPreWPCMode%Nidec */
    localDW->b_WarnClearEnable = Off;

    /* Nidec충전가능 */
    *rty_b_PhnLeftChk_Enable = Off;
    c_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_b044;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_hjy0;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_pka1;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_WarningTypeC;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /*  방치 알림 신호 출력 후, 휴대폰을 가져가는 경우 */
    if (((uint32)localDW->b_WarnClearEnable == On) && ((localDW->Input_OPT_b_WPCPhoneExist_prev != localDW->Input_OPT_b_WPCPhoneExist_start) && ((uint32)localDW->Input_OPT_b_WPCPhoneExist_start == Off)))
    {
      /*  폰 비거치 시간 측정 타이머 시작 */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Start_Timer_PhoneLef_bbky;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
      }

      localDW->sfEvent = c_previousEvent;

      /*  방치알림 신호 출력 후, 폰 비거치 상태-> 다시 폰 거치 확인한 경우 */
    } else if (((uint32)localDW->is_Tick_Timer_PhoneLeft == App_Model_IN_On_frgm) && ((uint32)rtu_Input_OPT_b_WPCPhoneExist == On)) {
      /*  폰 비거치 시간 측정 타이머 취소 */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_b044;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
      }

      localDW->sfEvent = c_previousEvent;
    } else {
      /* no actions */
    }

    /*  폰 경고 확인 조건 판단 */
    if ((uint32)localDW->PhoneLeftWrnType_irrq == PhoneLeftWrnType__Default) {
      if (localDW->Timer_WarningTypeCheck < ((uint16)6000U)) {
        /* 60s */
        if ((uint32)rtu_b_DrvDrSw == On) {
          /*  60초 이내에 DoorOpen 이벤트 발생할 경우,
             경고타입 (1sec Delay 후 6sec 간 경고 출력 발생) 설정 */
          localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__LongDuration;

          /* Nidec 60초이전 이벤트는 충전금지필요%WPCMode가 아닐 때는 상시 On이므로 WPCMode일 때를 위한 조건 */
          *rty_b_PhnLeftChk_Enable = On;

          /* HMC사양에 폰충전불가 주석원복함. */
          c_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_WarningTypeC;
          if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
            App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Start_Timer_PhoneWar_iihy;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
            Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
          }

          localDW->sfEvent = c_previousEvent;
        } else {
          /* WPCMode아닐 때 충전금지위해
             PhnLeftChck_Enable On유지 */
        }
      } else {
        /*  60초 간 Door Open 없을 시, 경고 타입(즉시 500ms 경고 출력 발생) 설정 */
        localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__ShortDuration;

        /* b_PhnLeftChk_Enable = On%Nidec%60초 이후 영향으로 불필요 */
        c_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_WarningTypeC;
        if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
          App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
        }

        localDW->sfEvent = (sint32)event_Start_Timer_PhoneWar_iihy;
        if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
          Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
        }

        localDW->sfEvent = c_previousEvent;
      }
    }

    /*  폰 경고 확인 시간 중 폰 감지됨100ms900ms */
    if ((localDW->Timer_PhoneWarningCheck >= (uint16)((uint8)10U)) && (localDW->Timer_PhoneWarningCheck <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Input_OPT_b_WPCPhoneExist == On)) {
      /* Output_WPCWarning = Cellphoneonthepad%NFCModeControl연동시그널. IG On중에는 미적용 */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_hjy0;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
      }

      localDW->sfEvent = (sint32)event_Start_Timer_WarningC_gju2;
      if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
      }

      localDW->sfEvent = c_previousEvent;
    }

    /*  경고 알림 출력
       [(PhoneLeftWrnType == PhoneLeftWrnType__LongDuration&&Timer_WarningComplete >= Par_WarningDelayTime &&...0s
       Timer_WarningComplete <= Par_WarningTime__LongDuration+Par_WarningDelayTime) ||...6s+0s %%DelayDelete_Nidec6s */
    if ((((uint32)localDW->PhoneLeftWrnType_irrq == PhoneLeftWrnType__LongDuration) && ((uint32)localDW->is_Tick_Timer_WarningComplete == App_Model_IN_On_frgm) && (localDW->Timer_WarningComplete <=
          ((uint16)600U))) || (((uint32)localDW->PhoneLeftWrnType_irrq == PhoneLeftWrnType__ShortDuration) && ((uint32)localDW->is_Tick_Timer_WarningComplete == App_Model_IN_On_frgm) &&
         (localDW->Timer_WarningComplete <= ((uint16)50U)))) {
      /* 500m */
      *rty_Output_WPCWarning = Cellphonereminder;
      localDW->b_WarnClearEnable = On;

      /*  경고 알림 출력 해제 조건 */
    } else if ((((uint32)localDW->PhoneLeftWrnType_irrq == PhoneLeftWrnType__LongDuration) && (localDW->Timer_WarningComplete > (((uint16)600U) + ((uint16)0U)))) || (((uint32)
                 localDW->PhoneLeftWrnType_irrq == PhoneLeftWrnType__ShortDuration) && (localDW->Timer_WarningComplete > ((uint16)50U)))) {
      /* Nidec */
      *rty_Output_WPCWarning = WPCWarningOff;

      /* Output_WPCWarning = SavedPreWPCMode%NidecNidec 필요250219 */
      *rty_b_PhnLeftChk_Enable = Off;

      /* HMC사양에 폰충전불가 주석원복함. */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_pka1;
      if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
      }

      localDW->sfEvent = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Model_WPCMode_Run_aqiy(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_DrvDrSw, GearPosSta
  rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *
  rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  Bool tmp;
  tmp = localDW->b_DrvDrSw_start;
  if (((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P) && ((uint32)rtu_b_DrvDrSw == On)) ||
      ((localDW->b_DrvDrSw_prev != tmp) && ((uint32)tmp == On) && ((uint32)rtu_Input_OPT_GearPosSta == GearPos_P))) {
    sint32 d_previousEvent;

    /* Nidec */
    exit_internal_WPCMode_Run_esdn(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
    localDW->is_WPCMode_Enable = IN_LeavingPhone_Warning_InWPCMo;
    localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
    localDW->b_WarnClearEnable = Off;
    *rty_b_ChargingEnable = Off;
    d_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Start_Timer_WarningTypeCh;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = d_previousEvent;
    App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
      rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

    /* 1. */
  } else if (((uint32)rtu_Input_OPT_b_LFState == On) || ((uint32)rtu_Input_OPT_b_CurrentFault == On) || ((uint32)rtu_Input_OPT_b_TempSensorFault == On) || ((uint32)rtu_Input_OPT_b_TemperatureFaul ==
              On)) {
    /*  ||b_CardProtection == On ]...CardDetect_Nidec */
    exit_internal_WPCMode_Run_esdn(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
    localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_lkmx;
    *rty_Output_OPT_b_FANModeCmd = Off;
    *rty_Output_OPT_b_GreenINDCmd = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    *rty_b_ChargingEnable = Off;

    /* 1. */
    if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
      localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_i2ty;
      *rty_Output_WPCWarning = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      *rty_Output_BlinkState = BlinkOff;
      localDW->Counter_BlinkCnt = 0U;
      App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

      /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
      *rty_Output_OPT_b_BlinkState = On;
    } else {
      localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_p5xt;
      *rty_Output_WPCWarning = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      *rty_Output_OPT_b_AmberINDCmd = Off;
    }
  } else {
    switch (localDW->is_WPCMode_Run) {
     case App_Mod_IN_WPCRun_Charging_gdm3:
      *rty_Output_OPT_b_FANModeCmd = On;

      /* 1. */
      if (((uint32)rtu_Input_OPT_DeviceState == Standby) || ((uint32)rtu_Input_OPT_DeviceState == Init)) {
        localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_nqhk;
        *rty_Output_WPCWarning = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = Off;
        *rty_Output_OPT_b_GreenINDCmd = Off;
        *rty_Output_OPT_b_AmberINDCmd = Off;
      } else {
        /* 2. */
        switch (rtu_Input_OPT_DeviceState) {
         case FODError:
          /*  b_FODFault == On] */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_ba02;
          *rty_Output_WPCWarning = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_Output_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;
          App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

          /*  Non GFS  */
          *rty_Output_OPT_b_BlinkState = On;
          break;

         case Full_Charge:
          /* 3. */
          localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_h041;
          *rty_Output_WPCWarning = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          *rty_Output_OPT_b_GreenINDCmd = On;
          *rty_Output_OPT_b_AmberINDCmd = Off;
          break;

         default:
          Function_ChargingINDColor_c04u(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_h041:
      *rty_Output_OPT_b_FANModeCmd = On;

      /* 1. */
      if (((uint32)rtu_Input_OPT_DeviceState == Standby) || ((uint32)rtu_Input_OPT_DeviceState == Init)) {
        localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_nqhk;
        *rty_Output_WPCWarning = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = Off;
        *rty_Output_OPT_b_GreenINDCmd = Off;
        *rty_Output_OPT_b_AmberINDCmd = Off;
      } else {
        /* 2. */
        switch (rtu_Input_OPT_DeviceState) {
         case FODError:
          /*  b_FODFault == On] */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_ba02;
          *rty_Output_WPCWarning = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_Output_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;
          App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

          /*  Non GFS  */
          *rty_Output_OPT_b_BlinkState = On;
          break;

         case Charging:
          /* 3. */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_gdm3;
          *rty_Output_WPCWarning = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          Function_ChargingINDColor_c04u(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_ba02:
      {
        *rty_Output_OPT_b_FANModeCmd = Off;

        /* 1. */
        if (((uint32)rtu_Input_OPT_DeviceState == Standby) || ((uint32)rtu_Input_OPT_DeviceState == Init)) {
          sint32 d_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          *rty_Output_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          d_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
          if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
            App_Tick_Timer_AmberINDBlk_f2hb(localDW);
          }

          localDW->sfEvent = d_previousEvent;

          /*  Non GFS  */
          *rty_Output_OPT_b_BlinkState = Off;
          localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_nqhk;
          *rty_Output_WPCWarning = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;
          *rty_Output_OPT_b_AmberINDCmd = Off;
        } else {
          /* 2. */
          switch (rtu_Input_OPT_DeviceState) {
           case Charging:
            {
              sint32 d_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_Output_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              d_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
              if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Tick_Timer_AmberINDBlk_f2hb(localDW);
              }

              localDW->sfEvent = d_previousEvent;

              /*  Non GFS  */
              *rty_Output_OPT_b_BlinkState = Off;
              localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_gdm3;
              *rty_Output_WPCWarning = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_Output_OPT_b_FANModeCmd = On;
              Function_ChargingINDColor_c04u(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
            }
            break;

           case Full_Charge:
            {
              sint32 d_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_Output_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              d_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
              if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Tick_Timer_AmberINDBlk_f2hb(localDW);
              }

              localDW->sfEvent = d_previousEvent;

              /*  Non GFS  */
              *rty_Output_OPT_b_BlinkState = Off;
              localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_h041;
              *rty_Output_WPCWarning = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_Output_OPT_b_FANModeCmd = On;
              *rty_Output_OPT_b_GreenINDCmd = On;
              *rty_Output_OPT_b_AmberINDCmd = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_nqhk:
      *rty_Output_OPT_b_FANModeCmd = Off;

      /* 1. */
      switch (rtu_Input_OPT_DeviceState) {
       case FODError:
        /*  b_FODFault == On] */
        localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_ba02;
        *rty_Output_WPCWarning = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        *rty_Output_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = 0U;
        *rty_Output_OPT_b_FANModeCmd = Off;
        *rty_Output_OPT_b_GreenINDCmd = Off;
        App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

        /*  Non GFS  */
        *rty_Output_OPT_b_BlinkState = On;
        break;

       case Charging:
        /* 2. */
        localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_gdm3;
        *rty_Output_WPCWarning = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = On;
        Function_ChargingINDColor_c04u(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
        break;

       case Full_Charge:
        /* 3. */
        localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_h041;
        *rty_Output_WPCWarning = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = On;
        *rty_Output_OPT_b_GreenINDCmd = On;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void exit_internal_WPCMode_Stop_knm3(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Stop == App_Mod_IN_WPCStop_TempErr_i2ty) {
    sint32 b_previousEvent;

    /* Function_NFCCardDetection() 8차 적용 삭제 */
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_f2hb(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_Output_OPT_b_BlinkState = Off;
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  } else {
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_atomic_WPCMode_Disab_ddfc(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  sint32 b_previousEvent;
  *rty_Output_WPCWarning = WPCWarningOff;

  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
  *rty_Output_BlinkState = BlinkOff;
  localDW->Counter_BlinkCnt = 0U;

  /* b_ChargingEnable = Off 8차 적용 삭제 */
  *rty_Output_OPT_b_FANModeCmd = Off;
  *rty_Output_OPT_b_GreenINDCmd = Off;
  *rty_Output_OPT_b_AmberINDCmd = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
  if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
    App_Tick_Timer_AmberINDBlk_f2hb(localDW);
  }

  localDW->sfEvent = b_previousEvent;

  /* Nidec */
  *rty_b_PhnLeftChk_Enable = Off;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App__enter_internal_WPCMode_Off(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, C_WPCWarning
  *rty_Output_WPCWarning, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl2_EV_250328_T *localDW)
{
  /* [hasChangedTo(Input_OPT_GearPosSta,GearPos_P)] */
  if ((uint32)rtu_Input_OPT_GearPosSta == GearPos_P) {
    sint32 b_previousEvent;

    /* Nidec */
    localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_ehk4;
    localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
    localDW->b_WarnClearEnable = Off;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Start_Timer_WarningTypeCh;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = b_previousEvent;
    App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
      rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

    /* Nidec */
    *rty_b_PhnLeftChk_Enable = On;
  } else {
    localDW->is_WPCMode_Off = IN_LeavingPhone_NoWarning_gjzu;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Mo_enter_atomic_WPCMode_NFC(uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  sint32 b_previousEvent;
  localDW->b_WarnClearEnable = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_b044;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
    App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_hjy0;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
    Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_pka1;
  if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
    Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_WarningTypeC;
  if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
    App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
  }

  localDW->sfEvent = b_previousEvent;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void App_Model_WPCMode_Enable(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool
  rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool
  *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool
  *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  /* 1. */
  if ((uint32)rtu_Input_OPT_WPCStatus != WPCMode) {
    switch (localDW->is_WPCMode_Enable) {
     case IN_LeavingPhone_Warning_InWPCMo:
      /* Nidec */
      *rty_b_PhnLeftChk_Enable = Off;
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
      break;

     case App_Model_IN_WPCMode_Run_f0sr:
      exit_internal_WPCMode_Run_esdn(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
      break;

     case App_Model_IN_WPCMode_Stop_lkmx:
      exit_internal_WPCMode_Stop_knm3(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
      break;

     default:
      /* no actions */
      break;
    }

    /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
    *rty_b_ChargingEnable = Off;
    localDW->is_MainControl = App_Mod_IN_WPCMode_Disable_lsz5;
    enter_atomic_WPCMode_Disab_ddfc(rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable,
      localDW);

    /* 1. */
    if (((uint32)rtu_Input_OPT_WPCStatus == NFCMode) || ((uint32)rtu_Input_OPT_WPCStatus == LPCDMode) || ((uint32)rtu_Input_OPT_WPCStatus == PICCMode)) {
      localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC;
      App_Mo_enter_atomic_WPCMode_NFC(rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
    } else {
      localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off;
      App__enter_internal_WPCMode_Off(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
        rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
    }
  } else {
    switch (localDW->is_WPCMode_Enable) {
     case IN_LeavingPhone_Warning_InWPCMo:
      {
        Bool tmp_0;
        GearPosSta tmp;
        tmp = localDW->Input_OPT_GearPosSta_prev;
        tmp_0 = localDW->b_DrvDrSw_start;
        if (((tmp != localDW->Input_OPT_GearPosSta_start) && ((uint32)tmp == GearPos_P)) || ((localDW->b_DrvDrSw_prev != tmp_0) && ((uint32)tmp_0 == Off))) {
          /* Nidec DoorClose */
          /* Nidec */
          *rty_b_PhnLeftChk_Enable = Off;
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_lkmx;
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;

          /* b_ROHMOperCmd = Off /_ Non GFS _/ */
          *rty_b_ChargingEnable = Off;

          /* 1. */
          if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
            localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_i2ty;
            *rty_Output_WPCWarning = Charging_error;

            /* b_WPCWarn = Charging_error 8차 LFRollBack */
            *rty_Output_BlinkState = BlinkOff;
            localDW->Counter_BlinkCnt = 0U;
            App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

            /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
            *rty_Output_OPT_b_BlinkState = On;
          } else {
            localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_p5xt;
            *rty_Output_WPCWarning = WPCWarningOff;

            /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
            *rty_Output_OPT_b_AmberINDCmd = Off;
          }
        } else if ((tmp != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P)) {
          sint32 b_previousEvent;

          /* Nidec */
          *rty_b_PhnLeftChk_Enable = Off;
          localDW->is_WPCMode_Enable = IN_LeavingPhone_Warning_InWPCMo;
          localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
          localDW->b_WarnClearEnable = Off;
          *rty_b_ChargingEnable = Off;
          b_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Start_Timer_WarningTypeCh;
          if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
            App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
          }

          localDW->sfEvent = b_previousEvent;
          App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
            rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
        } else {
          /* b_PhnLeftChk_Enable = On%Nidec%충전상태를 조건에따라 판단하기위해 주석처리 */
          App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
            rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
        }
      }
      break;

     case App_Model_IN_WPCMode_Run_f0sr:
      App_Model_WPCMode_Run_aqiy(rtu_Input_OPT_b_LFState, rtu_Input_OPT_b_CurrentFault, rtu_Input_OPT_b_TempSensorFault, rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption,
        rtu_Input_OPT_b_TemperatureFaul, rtu_Input_OPT_DeviceState, rtu_Input_IND_WPCIndUSMState, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rtu_b_CmdLEDSync, rty_Output_WPCWarning,
        rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
        rty_b_Timer_WarningComplete, rty_b_ChargingEnable, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
      break;

     case App_Model_IN_WPCMode_Stop_lkmx:
      {
        *rty_Output_OPT_b_FANModeCmd = Off;
        if (((uint32)rtu_Input_OPT_DeviceState == Full_Charge) && ((uint32)rtu_Input_OPT_b_LFState == Off) && ((uint32)rtu_Input_OPT_b_CurrentFault == Off) && ((uint32)rtu_Input_OPT_b_TemperatureFaul ==
             Off) && ((uint32)rtu_Input_OPT_b_TempSensorFault == Off)) {
          /*  &&b_CardProtection == Off]%CardDetect_Nidec]
             Input_PhoneLeftWarningWPCStatus == Off]
             b_ChargingEnable == On 8차 적용 삭제 */
          exit_internal_WPCMode_Stop_knm3(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f0sr;
          *rty_b_ChargingEnable = On;
          localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_h041;
          *rty_Output_WPCWarning = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          *rty_Output_OPT_b_GreenINDCmd = On;
          *rty_Output_OPT_b_AmberINDCmd = Off;
        } else if (((uint32)rtu_Input_OPT_DeviceState == Charging) && ((uint32)rtu_Input_OPT_b_LFState == Off) && ((uint32)rtu_Input_OPT_b_CurrentFault == Off) && ((uint32)
                    rtu_Input_OPT_b_TemperatureFaul == Off) && ((uint32)rtu_Input_OPT_b_TempSensorFault == Off)) {
          /* &&b_CardProtection == Off]%CardDetect_Nidec]
             Input_PhoneLeftWarningWPCStatus == Off]
             b_ChargingEnable == On 8차 적용 삭제 */
          exit_internal_WPCMode_Stop_knm3(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f0sr;
          *rty_b_ChargingEnable = On;
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_gdm3;
          *rty_Output_WPCWarning = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          Function_ChargingINDColor_c04u(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
        } else {
          GearPosSta tmp;
          tmp = localDW->Input_OPT_GearPosSta_start;
          if (((localDW->Input_OPT_GearPosSta_prev != tmp) && ((uint32)tmp == GearPos_P) && ((uint32)rtu_b_DrvDrSw == On)) || ((localDW->b_DrvDrSw_prev != localDW->b_DrvDrSw_start) && ((uint32)
                localDW->b_DrvDrSw_start == On) && ((uint32)rtu_Input_OPT_GearPosSta == GearPos_P))) {
            sint32 b_previousEvent;

            /* Nidec */
            exit_internal_WPCMode_Stop_knm3(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
            localDW->is_WPCMode_Enable = IN_LeavingPhone_Warning_InWPCMo;
            localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
            localDW->b_WarnClearEnable = Off;
            *rty_b_ChargingEnable = Off;
            b_previousEvent = localDW->sfEvent;
            localDW->sfEvent = (sint32)event_Start_Timer_WarningTypeCh;
            if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
              App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
            }

            localDW->sfEvent = b_previousEvent;
            App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
              rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
          } else {
            switch (localDW->is_WPCMode_Stop) {
             case App__IN_WPCStop_NotTempErr_p5xt:
              /* 1. */
              if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
                localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_i2ty;
                *rty_Output_WPCWarning = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                *rty_Output_BlinkState = BlinkOff;
                localDW->Counter_BlinkCnt = 0U;
                App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

                /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
                *rty_Output_OPT_b_BlinkState = On;

                /* 2. */
              } else if (((uint32)rtu_Input_OPT_b_LFState == Off) && ((uint32)rtu_Input_OPT_b_CurrentFault == Off) && ((uint32)rtu_Input_OPT_b_TempSensorFault == Off)) {
                /* &&b_CardProtection == Off]%CardDetect_Nidec]
                   Input_PhoneLeftWarningWPCStatus == Off]
                   b_ChargingEnable == On 8차 적용 삭제 */
                localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
                localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_f0sr;
                *rty_b_ChargingEnable = On;
                localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_nqhk;
                *rty_Output_WPCWarning = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                *rty_Output_OPT_b_FANModeCmd = Off;
                *rty_Output_OPT_b_GreenINDCmd = Off;
                *rty_Output_OPT_b_AmberINDCmd = Off;
              } else {
                /* Function_NFCCardDetection() 8차 적용 삭제
                   Function_NFCCardDetection() 8차 적용 삭제 */
              }
              break;

             case App_Mod_IN_WPCStop_TempErr_i2ty:
              {
                /* 1. */
                if ((uint32)rtu_Input_OPT_b_TemperatureFaul == Off) {
                  sint32 b_previousEvent;

                  /* Function_NFCCardDetection() 8차 적용 삭제 */
                  *rty_Output_BlinkState = BlinkOff;
                  localDW->Counter_BlinkCnt = 0U;
                  b_previousEvent = localDW->sfEvent;
                  localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
                  if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                    App_Tick_Timer_AmberINDBlk_f2hb(localDW);
                  }

                  localDW->sfEvent = b_previousEvent;

                  /*  Non GFS  */
                  *rty_Output_OPT_b_BlinkState = Off;
                  localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_p5xt;
                  *rty_Output_WPCWarning = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  *rty_Output_OPT_b_AmberINDCmd = Off;
                } else {
                  App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
                }
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void A_enter_internal_WPCMode_Enable(Bool rtu_Input_OPT_b_TemperatureFaul, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool
  *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState,
  DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_lkmx;
  *rty_Output_OPT_b_FANModeCmd = Off;
  *rty_Output_OPT_b_GreenINDCmd = Off;

  /* b_ROHMOperCmd = Off /_ Non GFS _/ */
  *rty_b_ChargingEnable = Off;

  /* 1. */
  if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
    localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_i2ty;
    *rty_Output_WPCWarning = Charging_error;

    /* b_WPCWarn = Charging_error 8차 LFRollBack */
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    App_Function_LEDErrorBlink_ly4n(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

    /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
    *rty_Output_OPT_b_BlinkState = On;
  } else {
    localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_p5xt;
    *rty_Output_WPCWarning = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    *rty_Output_OPT_b_AmberINDCmd = Off;
  }
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__btlk(DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_oqv2;
  localDW->Timer_PhoneLeft = 0U;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__mqe0(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_oqv2;
  localDW->Timer_PhoneWarningCheck = 0U;

  /* Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
  *rty_b_Timer_PhoneWarningCheck = 0U;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__f2oq(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_oqv2;
  localDW->Timer_WarningComplete = 0U;

  /* Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
  *rty_b_Timer_WarningComplete = 0U;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__eloo(DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_oqv2;
  localDW->Timer_AmberINDBlk = 0U;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__bosw(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_Tick_Timer_WarningTypeCheck = App_Model_IN_Off_oqv2;
  localDW->Timer_WarningTypeCheck = 0U;

  /* Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
  *rty_b_Timer_WarningTypeCheck = 0U;
}

/* Function for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__kbtb(DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_oqv2;
  localDW->Timer_AmberINDBlk2 = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S211>/WPC_MainControl2_EV_250328_HMC'
 *    '<S833>/WPC_MainControl_EV_250328_HMC_dum'
 */
void WPC_MainControl2_EV_250328_Init(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool
  *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ll15;
  localDW->is_active_MainControl = 0U;
  localDW->is_MainControl = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_Tick_Timer_AmberINDBl = 0U;
  localDW->is_Tick_Timer_AmberINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_Tick_Timer_Amber_ba0g = 0U;
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_Tick_Timer_PhoneLeft = 0U;
  localDW->is_Tick_Timer_PhoneLeft = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_Tick_Timer_PhoneWarni = 0U;
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_Tick_Timer_WarningCom = 0U;
  localDW->is_Tick_Timer_WarningComplete = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_Tick_Timer_WarningTyp = 0U;
  localDW->is_Tick_Timer_WarningTypeCheck = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
  localDW->is_active_c70_MainControl_Lib = 0U;
  localDW->Timer_AmberINDBlk = 0U;
  localDW->Timer_PhoneLeft = 0U;
  localDW->Timer_PhoneWarningCheck = 0U;
  localDW->Timer_WarningComplete = 0U;
  localDW->Counter_BlinkCnt = 0U;
  localDW->Timer_WarningTypeCheck = 0U;
  localDW->b_WarnClearEnable = 0U;
  localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
  localDW->Timer_AmberINDBlk2 = 0U;
  *rty_Output_WPCWarning = WPCWarningOff;
  *rty_Output_OPT_b_FANModeCmd = Off;
  *rty_Output_OPT_b_GreenINDCmd = Off;
  *rty_Output_OPT_b_AmberINDCmd = Off;
  *rty_Output_OPT_b_BlinkState = Off;
  *rty_b_Timer_WarningTypeCheck = 0U;
  *rty_b_Timer_PhoneWarningCheck = 0U;
  *rty_b_Timer_WarningComplete = 0U;
  *rty_b_ChargingEnable = Off;
  *rty_Output_BlinkState = BlinkOff;
  *rty_b_PhnLeftChk_Enable = Off;
  localDW->Input_OPT_b_WPCPhoneExist_prev = Off;
  localDW->Input_OPT_b_WPCPhoneExist_start = Off;
  localDW->WPCIndCmdState_prev = WPCIndCmdState__Default;
  localDW->WPCIndCmdState_start = WPCIndCmdState__Default;
  localDW->Input_OPT_GearPosSta_prev = GearPos_P;
  localDW->Input_OPT_GearPosSta_start = GearPos_P;
  localDW->b_DrvDrSw_prev = Off;
  localDW->b_DrvDrSw_start = Off;
}

/*
 * Output and update for atomic system:
 *    '<S211>/WPC_MainControl2_EV_250328_HMC'
 *    '<S833>/WPC_MainControl_EV_250328_HMC_dum'
 */
void WPC_MainControl2_EV_250328_HMC(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool
  rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, WPCIndCmdState rtu_WPCIndCmdState, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool
  *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16
  *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl2_EV_250328_T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ll15;
  localDW->Input_OPT_b_WPCPhoneExist_prev = localDW->Input_OPT_b_WPCPhoneExist_start;
  localDW->Input_OPT_b_WPCPhoneExist_start = rtu_Input_OPT_b_WPCPhoneExist;
  localDW->WPCIndCmdState_prev = localDW->WPCIndCmdState_start;
  localDW->WPCIndCmdState_start = rtu_WPCIndCmdState;
  localDW->Input_OPT_GearPosSta_prev = localDW->Input_OPT_GearPosSta_start;
  localDW->Input_OPT_GearPosSta_start = rtu_Input_OPT_GearPosSta;
  localDW->b_DrvDrSw_prev = localDW->b_DrvDrSw_start;
  localDW->b_DrvDrSw_start = rtu_b_DrvDrSw;

  /* Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
  if ((uint32)localDW->is_active_c70_MainControl_Lib == 0U) {
    localDW->Input_OPT_b_WPCPhoneExist_prev = rtu_Input_OPT_b_WPCPhoneExist;
    localDW->WPCIndCmdState_prev = rtu_WPCIndCmdState;
    localDW->Input_OPT_GearPosSta_prev = rtu_Input_OPT_GearPosSta;
    localDW->b_DrvDrSw_prev = rtu_b_DrvDrSw;
    localDW->is_active_c70_MainControl_Lib = 1U;
    localDW->is_active_MainControl = 1U;
    localDW->is_MainControl = App_Model_IN_WPCMode_Init;
    *rty_Output_WPCWarning = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    localDW->b_WarnClearEnable = Off;

    /* b_ChargingEnable = 8차 적용 삭제 */
    *rty_Output_OPT_b_FANModeCmd = Off;
    *rty_Output_OPT_b_GreenINDCmd = Off;
    *rty_Output_OPT_b_AmberINDCmd = Off;

    /* Nidec */
    *rty_b_PhnLeftChk_Enable = Off;
    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_b044;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_hjy0;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_pka1;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_lasm;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_f2hb(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_WarningTypeC;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = -1;
    localDW->is_active_Tick_Timer_PhoneLeft = 1U;
    enter_internal_Tick_Timer__btlk(localDW);
    localDW->is_active_Tick_Timer_PhoneWarni = 1U;
    enter_internal_Tick_Timer__mqe0(rty_b_Timer_PhoneWarningCheck, localDW);
    localDW->is_active_Tick_Timer_WarningCom = 1U;
    enter_internal_Tick_Timer__f2oq(rty_b_Timer_WarningComplete, localDW);
    localDW->is_active_Tick_Timer_AmberINDBl = 1U;
    enter_internal_Tick_Timer__eloo(localDW);
    localDW->is_active_Tick_Timer_WarningTyp = 1U;
    enter_internal_Tick_Timer__bosw(rty_b_Timer_WarningTypeCheck, localDW);
    localDW->is_active_Tick_Timer_Amber_ba0g = 1U;
    enter_internal_Tick_Timer__kbtb(localDW);
  } else {
    if ((uint32)localDW->is_active_MainControl != 0U) {
      switch (localDW->is_MainControl) {
       case App_Mod_IN_WPCMode_Disable_lsz5:
        *rty_Output_OPT_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_Input_OPT_WPCStatus == WPCMode) {
          if ((uint32)localDW->is_WPCMode_Disable == App_Model_IN_WPCMode_Off) {
            if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_ehk4) {
              *rty_Output_WPCWarning = WPCWarningOff;

              /* Nidec */
              *rty_b_PhnLeftChk_Enable = Off;
              localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
            } else {
              localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
            }

            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
          } else {
            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
          }

          localDW->b_WarnClearEnable = Off;
          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_b044;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
            App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_hjy0;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
            Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_pka1;
          if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
            Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_WarningTypeC;
          if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
            App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_MainControl = App_Mode_IN_WPCMode_Enable_glxy;
          A_enter_internal_WPCMode_Enable(rtu_Input_OPT_b_TemperatureFaul, rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd,
            rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_ChargingEnable, rty_Output_BlinkState, localDW);
        } else {
          switch (localDW->is_WPCMode_Disable) {
           case App_Model_IN_WPCMode_NFC:
            /* 1. */
            if (((uint32)rtu_Input_OPT_WPCStatus == ModeOff) || ((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start ==
                  GearPos_P))) {
              /* Nide */
              localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off;
              App__enter_internal_WPCMode_Off(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
            }
            break;

           case App_Model_IN_WPCMode_Off:
            /* 1. */
            if (((uint32)rtu_Input_OPT_WPCStatus == NFCMode) || ((uint32)rtu_Input_OPT_WPCStatus == LPCDMode) || ((uint32)rtu_Input_OPT_WPCStatus == PICCMode)) {
              if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_ehk4) {
                *rty_Output_WPCWarning = WPCWarningOff;

                /* Nidec */
                *rty_b_PhnLeftChk_Enable = Off;
                localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
              } else {
                localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_kgop;
              }

              localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC;
              App_Mo_enter_atomic_WPCMode_NFC(rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
            } else {
              switch (localDW->is_WPCMode_Off) {
               case IN_LeavingPhone_NoWarning_gjzu:
                if ((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P)) {
                  localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_ehk4;
                  localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
                  localDW->b_WarnClearEnable = Off;
                  localDW->sfEvent = (sint32)event_Start_Timer_WarningTypeCh;
                  if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
                    App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
                  }

                  localDW->sfEvent = -1;
                  App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                    rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

                  /* Nidec */
                  *rty_b_PhnLeftChk_Enable = On;
                }
                break;

               case Ap_IN_LeavingPhone_Warning_ehk4:
                if ((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P)) {
                  *rty_Output_WPCWarning = WPCWarningOff;

                  /* Nidec */
                  *rty_b_PhnLeftChk_Enable = Off;
                  localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_ehk4;
                  localDW->PhoneLeftWrnType_irrq = PhoneLeftWrnType__Default;
                  localDW->b_WarnClearEnable = Off;
                  localDW->sfEvent = (sint32)event_Start_Timer_WarningTypeCh;
                  if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
                    App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
                  }

                  localDW->sfEvent = -1;
                  App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                    rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

                  /* Nidec */
                  *rty_b_PhnLeftChk_Enable = On;
                } else {
                  App_Mo_Function_WPCWarning_elof(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                    rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
                }
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
        break;

       case App_Mode_IN_WPCMode_Enable_glxy:
        App_Model_WPCMode_Enable(rtu_Input_OPT_b_LFState, rtu_Input_OPT_b_CurrentFault, rtu_Input_OPT_b_TempSensorFault, rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption,
          rtu_Input_OPT_b_TemperatureFaul, rtu_Input_OPT_DeviceState, rtu_Input_OPT_WPCStatus, rtu_Input_IND_WPCIndUSMState, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rtu_b_CmdLEDSync,
          rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_Timer_WarningTypeCheck,
          rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_ChargingEnable, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
        break;

       case App_Model_IN_WPCMode_Init:
        *rty_Output_OPT_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_Input_OPT_WPCStatus != WPCMode) {
          localDW->is_MainControl = App_Mod_IN_WPCMode_Disable_lsz5;
          enter_atomic_WPCMode_Disab_ddfc(rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable,
            localDW);

          /* 1. */
          if (((uint32)rtu_Input_OPT_WPCStatus == NFCMode) || ((uint32)rtu_Input_OPT_WPCStatus == LPCDMode) || ((uint32)rtu_Input_OPT_WPCStatus == PICCMode)) {
            localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC;
            App_Mo_enter_atomic_WPCMode_NFC(rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
          } else {
            localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off;
            App__enter_internal_WPCMode_Off(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
              rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
          }

          /* 2 */
        } else if ((uint32)rtu_Input_OPT_WPCStatus == WPCMode) {
          localDW->is_MainControl = App_Mode_IN_WPCMode_Enable_glxy;
          A_enter_internal_WPCMode_Enable(rtu_Input_OPT_b_TemperatureFaul, rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd,
            rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_ChargingEnable, rty_Output_BlinkState, localDW);
        } else {
          /* no actions */
        }
        break;

       default:
        /* no actions */
        break;
      }
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_jjb3(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_cfdy(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_mg4j(rty_b_Timer_WarningComplete, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_f2hb(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      App_Tick_Timer_WarningTypeCheck(rty_b_Timer_WarningTypeCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_Amber_ba0g != 0U) {
      Ap_Tick_Timer_AmberINDBlk2_gl4k(localDW);
    }
  }

  /* End of Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_Tick_Timer_AmberINDBlk_inx4(DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_ggut) {
      localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberIN_hohe) {
        localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_eyrr;
        localDW->Timer_AmberINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk + 1;
        if (((sint32)localDW->Timer_AmberINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_ggut) {
          localDW->Timer_AmberINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void exit_internal_WPCMode_Run_dawy(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl3_CardSync__T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Run == App_Mod_IN_WPCRun_FODError_hefu) {
    sint32 b_previousEvent;
    *rty_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_inx4(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_b_BlinkState = Off;
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  } else {
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void exit_internal_WPCMode_Stop_pahe(Bool *rty_b_BlinkState, BlinkState *rty_BlinkState, DW_WPC_MainControl3_CardSync__T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Stop == App_Mod_IN_WPCStop_TempErr_iyhn) {
    sint32 b_previousEvent;
    *rty_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_inx4(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_b_BlinkState = Off;
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  } else {
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_atomic_WPCMode_Disab_ejz1(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, BlinkState *rty_BlinkState, Bool
  *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *localDW)
{
  sint32 b_previousEvent;
  *rty_C_WPCWarning = WPCWarningOff;
  *rty_BlinkState = BlinkOff;
  localDW->Counter_BlinkCnt = 0U;
  *rty_b_FANModeCmd = Off;
  *rty_b_GreenINDCmd = Off;
  *rty_b_AmberINDCmd = Off;
  *rty_b_PhnLeftChk_Enable = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
  if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
    App_Tick_Timer_AmberINDBlk_inx4(localDW);
  }

  localDW->sfEvent = b_previousEvent;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_M_Tick_Timer_PhoneLeft_hpwh(DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneLeft) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneLef_hsco) {
      localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneLe_gauw) {
        localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_eyrr;
        localDW->Timer_PhoneLeft = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneLeft + 1;
        if (((sint32)localDW->Timer_PhoneLeft + 1) > 255) {
          tmp = 255;
        }

        localDW->Timer_PhoneLeft = (uint8)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneLef_hsco) {
          localDW->Timer_PhoneLeft = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void Tick_Timer_PhoneWarningChe_nzwe(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneWarningCheck) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWar_mfiz) {
      localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneWa_daos) {
        localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_eyrr;
        localDW->Timer_PhoneWarningCheck = 0U;
        *rty_b_Timer_PhoneWarningCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneWarningCheck + 1;
        if (((sint32)localDW->Timer_PhoneWarningCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhoneWarningCheck = (uint16)tmp;
        *rty_b_Timer_PhoneWarningCheck = localDW->Timer_PhoneWarningCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWar_mfiz) {
          localDW->Timer_PhoneWarningCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void Tick_Timer_PhoneReminderCh_e2q5(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneReminderChec) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneRem_akzn) {
      localDW->is_Tick_Timer_PhoneReminderChec = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneRe_edzf) {
        localDW->is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_eyrr;
        localDW->Timer_PhoneReminderCheck = 0U;
        *rty_b_Timer_PhoneReminderCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneReminderCheck + 1;
        if (((sint32)localDW->Timer_PhoneReminderCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhoneReminderCheck = (uint16)tmp;
        *rty_b_Timer_PhoneReminderCheck = localDW->Timer_PhoneReminderCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneRem_akzn) {
          localDW->Timer_PhoneReminderCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void Tick_Timer_WarningComplete_d50v(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_WarningComplete) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)event_Start_Timer_WarningC_ovzu) {
      localDW->is_Tick_Timer_WarningComplete = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_Warning_ogip) {
        localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_eyrr;
        localDW->Timer_WarningComplete = 0U;
        *rty_b_Timer_WarningComplete = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_WarningComplete + 1;
        if (((sint32)localDW->Timer_WarningComplete + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_WarningComplete = (uint16)tmp;
        *rty_b_Timer_WarningComplete = localDW->Timer_WarningComplete;
        if (localDW->sfEvent == (sint32)event_Start_Timer_WarningC_ovzu) {
          localDW->Timer_WarningComplete = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void A_enter_atomic_WPCMode_NFC_bfni(uint16 *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl3_CardSync__T *localDW)
{
  sint32 b_previousEvent;
  localDW->b_WarnClearEnable = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_gauw;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
    App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_daos;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
    Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneRe_edzf;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
    Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_ogip;
  if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
    Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
  }

  localDW->sfEvent = b_previousEvent;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_Mo_Function_WPCWarning_nh3i(C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, C_WPCWarning *rty_C_WPCWarning, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *localDW)
{
  /* 1 */
  if (((uint32)rtu_WPCSWOption == WPC_Off) || ((localDW->Timer_PhoneWarningCheck >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_b_WPCPhoneExist == Off)) || (localDW->Timer_PhoneLeft >= ((uint8)50U)))
  {
    sint32 c_previousEvent;
    *rty_C_WPCWarning = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    localDW->b_WarnClearEnable = Off;
    *rty_b_PhnLeftChk_Enable = Off;
    c_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_gauw;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_daos;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneRe_edzf;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_ogip;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /* 1. */
    if (((uint32)localDW->b_WarnClearEnable == On) && ((localDW->b_WPCPhoneExist_prev != localDW->b_WPCPhoneExist_start) && ((uint32)localDW->b_WPCPhoneExist_start == Off))) {
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Start_Timer_PhoneLef_hsco;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
      }

      localDW->sfEvent = c_previousEvent;

      /* 1. */
    } else if (((uint32)localDW->is_Tick_Timer_PhoneLeft == App_Model_IN_On_nf3k) && ((uint32)rtu_b_WPCPhoneExist == On)) {
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_gauw;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
      }

      localDW->sfEvent = c_previousEvent;
    } else {
      /* no actions */
    }

    /* 1. */
    if ((localDW->Timer_PhoneWarningCheck >= ((uint16)10U)) && (localDW->Timer_PhoneWarningCheck <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_b_WPCPhoneExist == On)) {
      *rty_C_WPCWarning = Cellphoneonthepad;

      /* b_WPCWarn = Cellphoneonthepad 8차 LFRollBack */
      localDW->b_WarnClearEnable = On;
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_daos;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
      }

      localDW->sfEvent = (sint32)event_Start_Timer_PhoneRem_akzn;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
        Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
      }

      localDW->sfEvent = c_previousEvent;

      /* 5차 적용 */

      /* 1. */
    } else if ((localDW->Timer_PhoneReminderCheck >= ((uint16)6000U)) && ((uint32)localDW->b_WarnClearEnable == On) && ((uint32)rtu_b_WPCPhoneExist == On)) {
      /* 1. */
      if (((uint32)rtu_C_DrvDrSw == On) || ((uint32)rtu_C_AstDrSw == On)) {
        localDW->b_WarnClearEnable = Off;
        *rty_C_WPCWarning = WPCWarningOff;
        *rty_b_PhnLeftChk_Enable = Off;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        c_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneRe_edzf;
        if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
          Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
        }

        localDW->sfEvent = c_previousEvent;
      } else {
        /* 2. */
        *rty_C_WPCWarning = Cellphonereminder;

        /* b_WPCWarn = Cellphonereminder 8차 LFRollBack */
        c_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneRe_edzf;
        if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
          Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
        }

        localDW->sfEvent = (sint32)event_Start_Timer_WarningC_ovzu;
        if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
          Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
        }

        localDW->sfEvent = c_previousEvent;
      }

      /* 1. */
    } else if ((localDW->Timer_WarningComplete >= ((uint16)50U)) && ((uint32)localDW->b_WarnClearEnable == On) && ((uint32)rtu_b_WPCPhoneExist == On)) {
      *rty_C_WPCWarning = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      localDW->b_WarnClearEnable = Off;
      *rty_b_PhnLeftChk_Enable = Off;
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_ogip;
      if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
      }

      localDW->sfEvent = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_WPCMode_Disable(C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_C_AstDrSw, Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, WPCStatus rtu_WPCStatus, C_WPCWarning
  *rty_C_WPCWarning, uint16 *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *
  localDW)
{
  /* 1. */
  if (((uint32)rtu_WPCStatus == NFCMode) || ((uint32)rtu_WPCStatus == LPCDMode) || ((uint32)rtu_WPCStatus == PICCMode)) {
    localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_etgv;
    A_enter_atomic_WPCMode_NFC_bfni(rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
  } else {
    localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off_azfk;
    if ((localDW->L_IGN1_IN_prev != localDW->L_IGN1_IN_start) && ((uint32)localDW->L_IGN1_IN_start == Off)) {
      sint32 b_previousEvent;
      localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_lsxs;
      localDW->b_WarnClearEnable = Off;
      b_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Start_Timer_PhoneWar_mfiz;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
      }

      localDW->sfEvent = b_previousEvent;
      App_Mo_Function_WPCWarning_nh3i(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
        rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
      *rty_b_PhnLeftChk_Enable = On;
    } else {
      localDW->is_WPCMode_Off = IN_LeavingPhone_NoWarning_dpgw;
    }
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void Ap_Tick_Timer_AmberINDBlk2_i5dr(DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk2) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_fk4t) {
      localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberIN_iv3b) {
        localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_eyrr;
        localDW->Timer_AmberINDBlk2 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk2 + 1;
        if (((sint32)localDW->Timer_AmberINDBlk2 + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk2 = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_fk4t) {
          localDW->Timer_AmberINDBlk2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_Function_LEDErrorBlink_jh0y(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, BlinkState *rty_BlinkState,
  DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (rtu_b_CmdLEDSync) {
   case Off:
    {
      /* ForFODError%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)(*rty_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_iv3b;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_iv3b;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 == App_Model_IN_Off_eyrr)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_fk4t;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk == App_Model_IN_Off_eyrr)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_ggut;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                   localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_ggut;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                    localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOff;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_ggut;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_fk4t;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_fk4t;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* ForFODError%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)(*rty_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_iv3b;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkComplete;
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_iv3b;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 == App_Model_IN_Off_eyrr)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_fk4t;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk == App_Model_IN_Off_eyrr)) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_ggut;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                   localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_ggut;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)
                    localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_BlinkState = BlinkOff;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_ggut;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_inx4(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOn;
        *rty_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_fk4t;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_fk4t;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_enter_internal_WPCMode_Stop(Bool rtu_b_TemperatureFault, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_AmberINDCmd, Bool
  *rty_b_BlinkState, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, DW_WPC_MainControl3_CardSync__T *localDW)
{
  /* 1. */
  if ((uint32)rtu_b_TemperatureFault == On) {
    localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_iyhn;

    /* 240926 */
    *rty_b_ChargingEnable = Off;
    *rty_C_WPCWarning = Charging_error;
    *rty_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);
    *rty_b_BlinkState = On;
  } else {
    localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_iie2;

    /* 240926 */
    *rty_b_ChargingEnable = Off;
    *rty_C_WPCWarning = WPCWarningOff;
    *rty_b_AmberINDCmd = Off;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void Function_ChargingINDColor_jywh(WPCIndUSMState rtu_IND_WPCIndUSMState, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd)
{
  /* 1. */
  if ((uint32)rtu_IND_WPCIndUSMState == WPCIndUSMState__Type2) {
    *rty_b_GreenINDCmd = On;
    *rty_b_AmberINDCmd = Off;
  } else {
    *rty_b_GreenINDCmd = Off;
    *rty_b_AmberINDCmd = On;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_Model_WPCMode_Enable_pbu4(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_b_TemperatureFault, Bool rtu_C_AstDrSw,
  Bool rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning
  rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl3_CardSync__T *localDW)
{
  /* 1. */
  if ((uint32)rtu_WPCStatus != WPCMode) {
    switch (localDW->is_WPCMode_Enable) {
     case App_Model_IN_WPCMode_Run_nyg1:
      exit_internal_WPCMode_Run_dawy(rty_b_BlinkState, rty_BlinkState, localDW);
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
      break;

     case App_Model_IN_WPCMode_Stop_babp:
      exit_internal_WPCMode_Stop_pahe(rty_b_BlinkState, rty_BlinkState, localDW);
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
      break;

     default:
      /* no actions */
      break;
    }

    *rty_b_ChargingEnable = Off;
    localDW->is_MainControl = App_Mod_IN_WPCMode_Disable_nt1b;
    enter_atomic_WPCMode_Disab_ejz1(rty_C_WPCWarning, rty_b_FANModeCmd, rty_b_GreenINDCmd, rty_b_AmberINDCmd, rty_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
    enter_internal_WPCMode_Disable(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rtu_WPCStatus, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
      rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
  } else {
    switch (localDW->is_WPCMode_Enable) {
     case App_Model_IN_WPCMode_Run_nyg1:
      {
        /* 1. */
        if (((uint32)rtu_b_LFState == On) || ((uint32)rtu_b_CurrentFault == On) || ((uint32)rtu_b_TempSensorFault == On) || ((uint32)rtu_b_TemperatureFault == On) || ((uint32)
             rtu_PhoneLeftWarningWPCStatus == NFCCardDetected)) {
          exit_internal_WPCMode_Run_dawy(rty_b_BlinkState, rty_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_babp;
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;

          /* b_ChargingEnable = Off */
          App_enter_internal_WPCMode_Stop(rtu_b_TemperatureFault, rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_C_WPCWarning, rty_b_AmberINDCmd, rty_b_BlinkState, rty_b_ChargingEnable, rty_BlinkState,
            localDW);
        } else {
          switch (localDW->is_WPCMode_Run) {
           case App_Mod_IN_WPCRun_Charging_k53m:
            *rty_b_FANModeCmd = On;

            /* 1. */
            if (((uint32)rtu_DeviceState == Standby) || ((uint32)rtu_DeviceState == Init)) {
              localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_mcah;
              *rty_C_WPCWarning = WPCWarningOff;

              /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
              *rty_b_FANModeCmd = Off;
              *rty_b_GreenINDCmd = Off;
              *rty_b_AmberINDCmd = Off;
            } else {
              /* 2. */
              switch (rtu_DeviceState) {
               case FODError:
                /*  b_FODFault == On] */
                localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_hefu;
                *rty_C_WPCWarning = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                *rty_BlinkState = BlinkOff;
                localDW->Counter_BlinkCnt = 0U;
                *rty_b_FANModeCmd = Off;
                *rty_b_GreenINDCmd = Off;
                App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

                /*  Non GFS  */
                *rty_b_BlinkState = On;
                break;

               case Full_Charge:
                /* 3. */
                localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_lfsh;
                *rty_C_WPCWarning = Charging_Complete;

                /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                *rty_b_FANModeCmd = On;
                *rty_b_GreenINDCmd = On;
                *rty_b_AmberINDCmd = Off;
                break;

               default:
                Function_ChargingINDColor_jywh(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
                break;
              }
            }
            break;

           case IN_WPCRun_ChargingComplete_lfsh:
            *rty_b_FANModeCmd = On;

            /* 1. */
            if (((uint32)rtu_DeviceState == Standby) || ((uint32)rtu_DeviceState == Init)) {
              localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_mcah;
              *rty_C_WPCWarning = WPCWarningOff;

              /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
              *rty_b_FANModeCmd = Off;
              *rty_b_GreenINDCmd = Off;
              *rty_b_AmberINDCmd = Off;
            } else {
              /* 2. */
              switch (rtu_DeviceState) {
               case FODError:
                /*  b_FODFault == On] */
                localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_hefu;
                *rty_C_WPCWarning = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                *rty_BlinkState = BlinkOff;
                localDW->Counter_BlinkCnt = 0U;
                *rty_b_FANModeCmd = Off;
                *rty_b_GreenINDCmd = Off;
                App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

                /*  Non GFS  */
                *rty_b_BlinkState = On;
                break;

               case Charging:
                /* 3. */
                localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_k53m;
                *rty_C_WPCWarning = PhoneCharging;

                /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                *rty_b_FANModeCmd = On;
                Function_ChargingINDColor_jywh(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           case App_Mod_IN_WPCRun_FODError_hefu:
            {
              *rty_b_FANModeCmd = Off;

              /* 1. */
              if (((uint32)rtu_DeviceState == Standby) || ((uint32)rtu_DeviceState == Init)) {
                sint32 d_previousEvent;

                /*  BlinkState == BlinkComplete 8차 적용 */
                *rty_BlinkState = BlinkOff;
                localDW->Counter_BlinkCnt = 0U;
                d_previousEvent = localDW->sfEvent;
                localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
                if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                  App_Tick_Timer_AmberINDBlk_inx4(localDW);
                }

                localDW->sfEvent = d_previousEvent;

                /*  Non GFS  */
                *rty_b_BlinkState = Off;
                localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_mcah;
                *rty_C_WPCWarning = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                *rty_b_FANModeCmd = Off;
                *rty_b_GreenINDCmd = Off;
                *rty_b_AmberINDCmd = Off;
              } else {
                /* 2. */
                switch (rtu_DeviceState) {
                 case Charging:
                  {
                    sint32 d_previousEvent;

                    /*  BlinkState == BlinkComplete 8차 적용 */
                    *rty_BlinkState = BlinkOff;
                    localDW->Counter_BlinkCnt = 0U;
                    d_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
                    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                      App_Tick_Timer_AmberINDBlk_inx4(localDW);
                    }

                    localDW->sfEvent = d_previousEvent;

                    /*  Non GFS  */
                    *rty_b_BlinkState = Off;
                    localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_k53m;
                    *rty_C_WPCWarning = PhoneCharging;

                    /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                    *rty_b_FANModeCmd = On;
                    Function_ChargingINDColor_jywh(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
                  }
                  break;

                 case Full_Charge:
                  {
                    sint32 d_previousEvent;

                    /* 3. */
                    /*  BlinkState == BlinkComplete 8차 적용 */
                    *rty_BlinkState = BlinkOff;
                    localDW->Counter_BlinkCnt = 0U;
                    d_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
                    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                      App_Tick_Timer_AmberINDBlk_inx4(localDW);
                    }

                    localDW->sfEvent = d_previousEvent;

                    /*  Non GFS  */
                    *rty_b_BlinkState = Off;
                    localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_lfsh;
                    *rty_C_WPCWarning = Charging_Complete;

                    /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                    *rty_b_FANModeCmd = On;
                    *rty_b_GreenINDCmd = On;
                    *rty_b_AmberINDCmd = Off;
                  }
                  break;

                 default:
                  App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);
                  break;
                }
              }
            }
            break;

           case App_Mode_IN_WPCRun_Standby_mcah:
            *rty_b_FANModeCmd = Off;

            /* 1. */
            switch (rtu_DeviceState) {
             case FODError:
              /*  b_FODFault == On] */
              localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_hefu;
              *rty_C_WPCWarning = Charging_error;

              /* b_WPCWarn = Charging_error 8차 LFRollBack */
              *rty_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              *rty_b_FANModeCmd = Off;
              *rty_b_GreenINDCmd = Off;
              App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);

              /*  Non GFS  */
              *rty_b_BlinkState = On;
              break;

             case Charging:
              /* 2. */
              localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_k53m;
              *rty_C_WPCWarning = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_b_FANModeCmd = On;
              Function_ChargingINDColor_jywh(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
              break;

             case Full_Charge:
              /* 3. */
              localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_lfsh;
              *rty_C_WPCWarning = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_b_FANModeCmd = On;
              *rty_b_GreenINDCmd = On;
              *rty_b_AmberINDCmd = Off;
              break;

             default:
              /* no actions */
              break;
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_Model_IN_WPCMode_Stop_babp:
      {
        *rty_b_FANModeCmd = Off;
        if (((uint32)rtu_DeviceState == Full_Charge) && ((uint32)rtu_b_LFState == Off) && ((uint32)rtu_b_CurrentFault == Off) && ((uint32)rtu_b_TemperatureFault == Off) && ((uint32)
             rtu_b_TempSensorFault == Off) && ((uint32)rtu_PhoneLeftWarningWPCStatus == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_pahe(rty_b_BlinkState, rty_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_nyg1;
          *rty_b_ChargingEnable = On;

          /* b_ROHMOperCmd = On /_ Non GFS _/ */
          localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_lfsh;
          *rty_C_WPCWarning = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_b_FANModeCmd = On;
          *rty_b_GreenINDCmd = On;
          *rty_b_AmberINDCmd = Off;
        } else if (((uint32)rtu_DeviceState == Charging) && ((uint32)rtu_b_LFState == Off) && ((uint32)rtu_b_CurrentFault == Off) && ((uint32)rtu_b_TemperatureFault == Off) && ((uint32)
                    rtu_b_TempSensorFault == Off) && ((uint32)rtu_PhoneLeftWarningWPCStatus == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_pahe(rty_b_BlinkState, rty_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_nyg1;
          *rty_b_ChargingEnable = On;

          /* b_ROHMOperCmd = On /_ Non GFS _/ */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_k53m;
          *rty_C_WPCWarning = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_b_FANModeCmd = On;
          Function_ChargingINDColor_jywh(rtu_IND_WPCIndUSMState, rty_b_GreenINDCmd, rty_b_AmberINDCmd);
        } else {
          switch (localDW->is_WPCMode_Stop) {
           case App__IN_WPCStop_NotTempErr_iie2:
            /* 1. */
            if ((uint32)rtu_b_TemperatureFault == On) {
              localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_iyhn;

              /* 240926 */
              *rty_b_ChargingEnable = Off;
              *rty_C_WPCWarning = Charging_error;
              *rty_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);
              *rty_b_BlinkState = On;

              /* 2. */
            } else if (((uint32)rtu_b_LFState == Off) && ((uint32)rtu_b_CurrentFault == Off) && ((uint32)rtu_b_TempSensorFault == Off) && ((uint32)rtu_PhoneLeftWarningWPCStatus == WPCWarningOff)) {
              localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
              localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_nyg1;
              *rty_b_ChargingEnable = On;

              /* b_ROHMOperCmd = On /_ Non GFS _/ */
              localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_mcah;
              *rty_C_WPCWarning = WPCWarningOff;

              /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
              *rty_b_FANModeCmd = Off;
              *rty_b_GreenINDCmd = Off;
              *rty_b_AmberINDCmd = Off;
            } else {
              /* no actions */
            }
            break;

           case App_Mod_IN_WPCStop_TempErr_iyhn:
            {
              /* 1. */
              if ((uint32)rtu_b_TemperatureFault == Off) {
                sint32 d_previousEvent;
                *rty_BlinkState = BlinkOff;
                localDW->Counter_BlinkCnt = 0U;
                d_previousEvent = localDW->sfEvent;
                localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
                if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                  App_Tick_Timer_AmberINDBlk_inx4(localDW);
                }

                localDW->sfEvent = d_previousEvent;

                /*  Non GFS  */
                *rty_b_BlinkState = Off;
                localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_iie2;

                /* 240926 */
                *rty_b_ChargingEnable = Off;
                *rty_C_WPCWarning = WPCWarningOff;
                *rty_b_AmberINDCmd = Off;
              } else {
                App_Function_LEDErrorBlink_jh0y(rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_b_AmberINDCmd, rty_b_BlinkState, rty_BlinkState, localDW);
              }
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
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void App_Model_Tick_Timer_CardINDBlk(DW_WPC_MainControl3_CardSync__T *localDW)
{
  switch (localDW->is_Tick_Timer_CardINDBlk) {
   case App_Model_IN_Off_eyrr:
    if (localDW->sfEvent == (sint32)Ap_event_Start_Timer_CardINDBlk) {
      localDW->is_Tick_Timer_CardINDBlk = App_Model_IN_On_nf3k;
    }
    break;

   case App_Model_IN_On_nf3k:
    {
      if (localDW->sfEvent == (sint32)A_event_Cancel_Timer_CardINDBlk) {
        localDW->is_Tick_Timer_CardINDBlk = App_Model_IN_Off_eyrr;
        localDW->Timer_CardINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_CardINDBlk + 1;
        if (((sint32)localDW->Timer_CardINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_CardINDBlk = (uint16)tmp;
        if (localDW->sfEvent == (sint32)Ap_event_Start_Timer_CardINDBlk) {
          localDW->Timer_CardINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__pgf0(DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_eyrr;
  localDW->Timer_PhoneLeft = 0U;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__fqbw(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_eyrr;
  localDW->Timer_PhoneWarningCheck = 0U;

  /* Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
  *rty_b_Timer_PhoneWarningCheck = 0U;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__n0n5(uint16 *rty_b_Timer_PhoneReminderCheck, DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_eyrr;
  localDW->Timer_PhoneReminderCheck = 0U;

  /* Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
  *rty_b_Timer_PhoneReminderCheck = 0U;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__jsgj(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_eyrr;
  localDW->Timer_WarningComplete = 0U;

  /* Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
  *rty_b_Timer_WarningComplete = 0U;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__i5yz(DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_eyrr;
  localDW->Timer_AmberINDBlk = 0U;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__m02b(DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_eyrr;
  localDW->Timer_AmberINDBlk2 = 0U;
}

/* Function for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer_CardI(DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->is_Tick_Timer_CardINDBlk = App_Model_IN_Off_eyrr;
  localDW->Timer_CardINDBlk = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S210>/WPC_MainControl3_CardSync_250522'
 *    '<S832>/WPC_MainControl3_CardSync_250522'
 */
void WPC_MainControl3_CardSync__Init(C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState, uint16
  *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ajpu;
  localDW->is_active_MainControl = 0U;
  localDW->is_MainControl = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_AmberINDBl = 0U;
  localDW->is_Tick_Timer_AmberINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_Amber_l1wn = 0U;
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_CardINDBlk = 0U;
  localDW->is_Tick_Timer_CardINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_PhoneLeft = 0U;
  localDW->is_Tick_Timer_PhoneLeft = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_PhoneRemin = 0U;
  localDW->is_Tick_Timer_PhoneReminderChec = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_PhoneWarni = 0U;
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_Tick_Timer_WarningCom = 0U;
  localDW->is_Tick_Timer_WarningComplete = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
  localDW->is_active_c53_MainControl_Lib = 0U;
  localDW->b_WarnClearEnable = Off;
  localDW->Timer_AmberINDBlk = 0U;
  localDW->Timer_PhoneLeft = 0U;
  localDW->Timer_PhoneReminderCheck = 0U;
  localDW->Timer_PhoneWarningCheck = 0U;
  localDW->Timer_WarningComplete = 0U;
  localDW->Counter_BlinkCnt = 0U;
  localDW->Timer_AmberINDBlk2 = 0U;
  localDW->Timer_CardINDBlk = 0U;
  *rty_C_WPCWarning = WPCWarningOff;
  *rty_b_FANModeCmd = Off;
  *rty_b_GreenINDCmd = Off;
  *rty_b_AmberINDCmd = Off;
  *rty_b_BlinkState = Off;
  *rty_b_Timer_PhoneReminderCheck = 0U;
  *rty_b_Timer_PhoneWarningCheck = 0U;
  *rty_b_Timer_WarningComplete = 0U;
  *rty_b_ChargingEnable = Off;
  *rty_BlinkState = BlinkOff;
  *rty_b_PhnLeftChk_Enable = Off;
  localDW->b_WPCPhoneExist_prev = Off;
  localDW->b_WPCPhoneExist_start = Off;
  localDW->WPCIndCmdState_prev = WPCIndCmdState__Default;
  localDW->WPCIndCmdState_start = WPCIndCmdState__Default;
  localDW->L_IGN1_IN_prev = Off;
  localDW->L_IGN1_IN_start = Off;
}

/*
 * Output and update for atomic system:
 *    '<S210>/WPC_MainControl3_CardSync_250522'
 *    '<S832>/WPC_MainControl3_CardSync_250522'
 */
void WPC_MainControl3_CardSync_25052(Bool rtu_b_LFState, Bool rtu_b_CurrentFault, Bool rtu_b_TempSensorFault, C_WPCOnOffNvalueSet rtu_WPCSWOption, Bool rtu_b_TemperatureFault, Bool rtu_C_AstDrSw, Bool
  rtu_C_DrvDrSw, Bool rtu_b_WPCPhoneExist, DeviceState rtu_DeviceState, WPCStatus rtu_WPCStatus, Bool rtu_L_IGN1_IN, WPCIndUSMState rtu_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, WPCIndCmdState
  rtu_WPCIndCmdState, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_C_WPCWarning, Bool *rty_b_FANModeCmd, Bool *rty_b_GreenINDCmd, Bool *rty_b_AmberINDCmd, Bool *rty_b_BlinkState,
  uint16 *rty_b_Timer_PhoneReminderCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_BlinkState, Bool
  *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl3_CardSync__T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_ajpu;
  localDW->b_WPCPhoneExist_prev = localDW->b_WPCPhoneExist_start;
  localDW->b_WPCPhoneExist_start = rtu_b_WPCPhoneExist;
  localDW->WPCIndCmdState_prev = localDW->WPCIndCmdState_start;
  localDW->WPCIndCmdState_start = rtu_WPCIndCmdState;
  localDW->L_IGN1_IN_prev = localDW->L_IGN1_IN_start;
  localDW->L_IGN1_IN_start = rtu_L_IGN1_IN;

  /* Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
  if ((uint32)localDW->is_active_c53_MainControl_Lib == 0U) {
    localDW->b_WPCPhoneExist_prev = rtu_b_WPCPhoneExist;
    localDW->WPCIndCmdState_prev = rtu_WPCIndCmdState;
    localDW->L_IGN1_IN_prev = rtu_L_IGN1_IN;
    localDW->is_active_c53_MainControl_Lib = 1U;
    localDW->is_active_MainControl = 1U;
    localDW->is_MainControl = App_Model_IN_WPCMode_Init_eart;
    *rty_C_WPCWarning = WPCWarningOff;
    *rty_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    localDW->b_WarnClearEnable = Off;
    *rty_b_FANModeCmd = Off;
    *rty_b_GreenINDCmd = Off;
    *rty_b_AmberINDCmd = Off;
    *rty_b_ChargingEnable = Off;
    *rty_b_PhnLeftChk_Enable = Off;
    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_gauw;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_daos;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneRe_edzf;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_ogip;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_hohe;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_inx4(localDW);
    }

    localDW->sfEvent = -1;
    localDW->is_active_Tick_Timer_PhoneLeft = 1U;
    enter_internal_Tick_Timer__pgf0(localDW);
    localDW->is_active_Tick_Timer_PhoneWarni = 1U;
    enter_internal_Tick_Timer__fqbw(rty_b_Timer_PhoneWarningCheck, localDW);
    localDW->is_active_Tick_Timer_PhoneRemin = 1U;
    enter_internal_Tick_Timer__n0n5(rty_b_Timer_PhoneReminderCheck, localDW);
    localDW->is_active_Tick_Timer_WarningCom = 1U;
    enter_internal_Tick_Timer__jsgj(rty_b_Timer_WarningComplete, localDW);
    localDW->is_active_Tick_Timer_AmberINDBl = 1U;
    enter_internal_Tick_Timer__i5yz(localDW);
    localDW->is_active_Tick_Timer_Amber_l1wn = 1U;
    enter_internal_Tick_Timer__m02b(localDW);
    localDW->is_active_Tick_Timer_CardINDBlk = 1U;
    enter_internal_Tick_Timer_CardI(localDW);
  } else {
    if ((uint32)localDW->is_active_MainControl != 0U) {
      switch (localDW->is_MainControl) {
       case App_Mod_IN_WPCMode_Disable_nt1b:
        *rty_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_WPCStatus == WPCMode) {
          if ((uint32)localDW->is_WPCMode_Disable == App_Model_IN_WPCMode_Off_azfk) {
            if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_lsxs) {
              *rty_C_WPCWarning = WPCWarningOff;
              *rty_b_PhnLeftChk_Enable = Off;
              localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
            } else {
              localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
            }

            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
          } else {
            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
          }

          localDW->b_WarnClearEnable = Off;
          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_gauw;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
            App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_daos;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
            Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneRe_edzf;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
            Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_ogip;
          if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
            Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_MainControl = App_Mode_IN_WPCMode_Enable_eoox;
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_babp;
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;

          /* b_ChargingEnable = Off */
          App_enter_internal_WPCMode_Stop(rtu_b_TemperatureFault, rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_C_WPCWarning, rty_b_AmberINDCmd, rty_b_BlinkState, rty_b_ChargingEnable, rty_BlinkState,
            localDW);
        } else {
          switch (localDW->is_WPCMode_Disable) {
           case App_Model_IN_WPCMode_NFC_etgv:
            /* 1. */
            if ((uint32)rtu_WPCStatus == ModeOff) {
              localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off_azfk;
              localDW->is_WPCMode_Off = IN_LeavingPhone_NoWarning_dpgw;
            }
            break;

           case App_Model_IN_WPCMode_Off_azfk:
            /* 1. */
            if (((uint32)rtu_WPCStatus == NFCMode) || ((uint32)rtu_WPCStatus == LPCDMode) || ((uint32)rtu_WPCStatus == PICCMode)) {
              if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_lsxs) {
                *rty_C_WPCWarning = WPCWarningOff;
                *rty_b_PhnLeftChk_Enable = Off;
                localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
              } else {
                localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_gpfz;
              }

              localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_etgv;
              A_enter_atomic_WPCMode_NFC_bfni(rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
            } else if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_lsxs) {
              App_Mo_Function_WPCWarning_nh3i(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck,
                rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
            } else {
              /* no actions */
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
        break;

       case App_Mode_IN_WPCMode_Enable_eoox:
        App_Model_WPCMode_Enable_pbu4(rtu_b_LFState, rtu_b_CurrentFault, rtu_b_TempSensorFault, rtu_WPCSWOption, rtu_b_TemperatureFault, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist,
          rtu_DeviceState, rtu_WPCStatus, rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rtu_PhoneLeftWarningWPCStatus, rty_C_WPCWarning, rty_b_FANModeCmd, rty_b_GreenINDCmd, rty_b_AmberINDCmd,
          rty_b_BlinkState, rty_b_Timer_PhoneReminderCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_ChargingEnable, rty_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
        break;

       case App_Model_IN_WPCMode_Init_eart:
        *rty_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_WPCStatus != WPCMode) {
          localDW->is_MainControl = App_Mod_IN_WPCMode_Disable_nt1b;
          enter_atomic_WPCMode_Disab_ejz1(rty_C_WPCWarning, rty_b_FANModeCmd, rty_b_GreenINDCmd, rty_b_AmberINDCmd, rty_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
          enter_internal_WPCMode_Disable(rtu_WPCSWOption, rtu_C_AstDrSw, rtu_C_DrvDrSw, rtu_b_WPCPhoneExist, rtu_WPCStatus, rty_C_WPCWarning, rty_b_Timer_PhoneReminderCheck,
            rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

          /* 2 */
        } else if ((uint32)rtu_WPCStatus == WPCMode) {
          localDW->is_MainControl = App_Mode_IN_WPCMode_Enable_eoox;
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_babp;
          *rty_b_FANModeCmd = Off;
          *rty_b_GreenINDCmd = Off;

          /* b_ChargingEnable = Off */
          App_enter_internal_WPCMode_Stop(rtu_b_TemperatureFault, rtu_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_C_WPCWarning, rty_b_AmberINDCmd, rty_b_BlinkState, rty_b_ChargingEnable, rty_BlinkState,
            localDW);
        } else {
          /* no actions */
        }
        break;

       default:
        /* no actions */
        break;
      }
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_hpwh(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_nzwe(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCh_e2q5(rty_b_Timer_PhoneReminderCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_d50v(rty_b_Timer_WarningComplete, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_inx4(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_Amber_l1wn != 0U) {
      Ap_Tick_Timer_AmberINDBlk2_i5dr(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_CardINDBlk != 0U) {
      App_Model_Tick_Timer_CardINDBlk(localDW);
    }
  }

  /* End of Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void App_Tick_Timer_AmberINDBlk_m40d(DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk) {
   case App_Model_IN_Off_nuz2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_bkdu) {
      localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_On_flaa;
    }
    break;

   case App_Model_IN_On_flaa:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberIN_fhe4) {
        localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_nuz2;
        localDW->Timer_AmberINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk + 1;
        if (((sint32)localDW->Timer_AmberINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_bkdu) {
          localDW->Timer_AmberINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void exit_internal_WPCMode_Run_jkjs(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl_EV_250522__T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Run == App_Mod_IN_WPCRun_FODError_nm1x) {
    sint32 b_previousEvent;
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_m40d(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_Output_OPT_b_BlinkState = Off;
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  } else {
    localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void Function_ChargingINDColor_ievi(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd)
{
  /* 1. */
  if ((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) {
    *rty_Output_OPT_b_GreenINDCmd = On;
    *rty_Output_OPT_b_AmberINDCmd = Off;
  } else {
    *rty_Output_OPT_b_GreenINDCmd = Off;
    *rty_Output_OPT_b_AmberINDCmd = On;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void Ap_Tick_Timer_AmberINDBlk2_eqqq(DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (localDW->is_Tick_Timer_AmberINDBlk2) {
   case App_Model_IN_Off_nuz2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_dk4p) {
      localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_On_flaa;
    }
    break;

   case App_Model_IN_On_flaa:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_AmberIN_l5xw) {
        localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_nuz2;
        localDW->Timer_AmberINDBlk2 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_AmberINDBlk2 + 1;
        if (((sint32)localDW->Timer_AmberINDBlk2 + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_AmberINDBlk2 = (uint16)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_AmberIND_dk4p) {
          localDW->Timer_AmberINDBlk2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void App_Function_LEDErrorBlink_mtqm(WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, BlinkState
  *rty_Output_BlinkState, DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (rtu_b_CmdLEDSync) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)(*rty_Output_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_l5xw;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_l5xw;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 ==
                  App_Model_IN_Off_nuz2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dk4p;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk ==
                  App_Model_IN_Off_nuz2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_Output_OPT_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_bkdu;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
                  ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_bkdu;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
        ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOff;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_bkdu;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dk4p;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dk4p;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)(*rty_Output_BlinkState) != BlinkComplete) && (localDW->Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_l5xw;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (localDW->Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkComplete;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_l5xw;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
        *rty_Output_OPT_b_BlinkState = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk2 ==
                  App_Model_IN_Off_nuz2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dk4p;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) != BlinkComplete) && ((uint32)localDW->is_Tick_Timer_AmberINDBlk ==
                  App_Model_IN_Off_nuz2)) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;

        /* Counter_BlinkCnt ++ */
        *rty_Output_OPT_b_AmberINDCmd = Off;

        /* OffStart */
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_bkdu;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOff) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
                  ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOn;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_bkdu;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState != WPCIndUSMState__Type2) && ((uint32)(*rty_Output_BlinkState) == BlinkOn) && (((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) &&
        ((uint32)localDW->WPCIndCmdState_prev == WPCIndCmdState__ErrorFadeOut)) || ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_start ==
                    WPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        *rty_Output_BlinkState = BlinkOff;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_bkdu;
        if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_m40d(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOn;
        *rty_Output_OPT_b_AmberINDCmd = On;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dk4p;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Input_IND_WPCIndUSMState == WPCIndUSMState__Type2) && ((localDW->WPCIndCmdState_prev != localDW->WPCIndCmdState_start) && ((uint32)localDW->WPCIndCmdState_prev ==
                   WPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        *rty_Output_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = (uint8)((sint32)((sint32)localDW->Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        *rty_Output_OPT_b_AmberINDCmd = Off;
        t_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Start_Timer_AmberIND_dk4p;
        if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
        }

        localDW->sfEvent = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void Tick_Timer_WarningTypeChec_ck1w(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (localDW->is_Tick_Timer_WarningTypeCheck) {
   case App_Model_IN_Off_nuz2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_WarningT_lnoc) {
      localDW->is_Tick_Timer_WarningTypeCheck = App_Model_IN_On_flaa;
    }
    break;

   case App_Model_IN_On_flaa:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_Warning_diaj) {
        localDW->is_Tick_Timer_WarningTypeCheck = App_Model_IN_Off_nuz2;
        localDW->Timer_WarningTypeCheck = 0U;
        *rty_b_Timer_WarningTypeCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_WarningTypeCheck + 1;
        if (((sint32)localDW->Timer_WarningTypeCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_WarningTypeCheck = (uint16)tmp;
        *rty_b_Timer_WarningTypeCheck = localDW->Timer_WarningTypeCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_WarningT_lnoc) {
          localDW->Timer_WarningTypeCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void App_M_Tick_Timer_PhoneLeft_igxy(DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneLeft) {
   case App_Model_IN_Off_nuz2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneLef_ikxf) {
      localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_On_flaa;
    }
    break;

   case App_Model_IN_On_flaa:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneLe_jhwb) {
        localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_nuz2;
        localDW->Timer_PhoneLeft = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneLeft + 1;
        if (((sint32)localDW->Timer_PhoneLeft + 1) > 255) {
          tmp = 255;
        }

        localDW->Timer_PhoneLeft = (uint8)tmp;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneLef_ikxf) {
          localDW->Timer_PhoneLeft = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void Tick_Timer_PhoneWarningChe_f1qw(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (localDW->is_Tick_Timer_PhoneWarningCheck) {
   case App_Model_IN_Off_nuz2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWar_b3yi) {
      localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_On_flaa;
    }
    break;

   case App_Model_IN_On_flaa:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_PhoneWa_pmk0) {
        localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_nuz2;
        localDW->Timer_PhoneWarningCheck = 0U;
        *rty_b_Timer_PhoneWarningCheck = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_PhoneWarningCheck + 1;
        if (((sint32)localDW->Timer_PhoneWarningCheck + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_PhoneWarningCheck = (uint16)tmp;
        *rty_b_Timer_PhoneWarningCheck = localDW->Timer_PhoneWarningCheck;
        if (localDW->sfEvent == (sint32)event_Start_Timer_PhoneWar_b3yi) {
          localDW->Timer_PhoneWarningCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void Tick_Timer_WarningComplete_fhjl(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl_EV_250522__T *localDW)
{
  switch (localDW->is_Tick_Timer_WarningComplete) {
   case App_Model_IN_Off_nuz2:
    if (localDW->sfEvent == (sint32)event_Start_Timer_WarningC_lx0t) {
      localDW->is_Tick_Timer_WarningComplete = App_Model_IN_On_flaa;
    }
    break;

   case App_Model_IN_On_flaa:
    {
      if (localDW->sfEvent == (sint32)event_Cancel_Timer_Warning_geeb) {
        localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_nuz2;
        localDW->Timer_WarningComplete = 0U;
        *rty_b_Timer_WarningComplete = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)localDW->Timer_WarningComplete + 1;
        if (((sint32)localDW->Timer_WarningComplete + 1) > 65535) {
          tmp = 65535;
        }

        localDW->Timer_WarningComplete = (uint16)tmp;
        *rty_b_Timer_WarningComplete = localDW->Timer_WarningComplete;
        if (localDW->sfEvent == (sint32)event_Start_Timer_WarningC_lx0t) {
          localDW->Timer_WarningComplete = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void App_Mo_Function_WPCWarning_dcfw(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, C_WPCWarning *rty_Output_WPCWarning, uint16
  *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW)
{
  /*  WPC 모드가 해제 or 폰 감지가 안되었을 경우 or 출력 후 폰 가져간 경우900ms */
  if (((uint32)rtu_Input_OPT_b_WPCSWOption == WPC_Off) || ((localDW->Timer_PhoneWarningCheck >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Input_OPT_b_WPCPhoneExist == Off)) ||
      (localDW->Timer_PhoneLeft >= ((uint8)50U))) {
    sint32 c_previousEvent;

    /* 500m */
    /*  Warning OffNidec */
    *rty_Output_WPCWarning = WPCWarningOff;

    /* Output_WPCWarning = SavedPreWPCMode%Nidec */
    localDW->b_WarnClearEnable = Off;

    /* Nidec충전가능 */
    *rty_b_PhnLeftChk_Enable = Off;
    c_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_jhwb;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_igxy(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_pmk0;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_geeb;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_diaj;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /*  방치 알림 신호 출력 후, 휴대폰을 가져가는 경우 */
    if (((uint32)localDW->b_WarnClearEnable == On) && ((localDW->Input_OPT_b_WPCPhoneExist_prev != localDW->Input_OPT_b_WPCPhoneExist_start) && ((uint32)localDW->Input_OPT_b_WPCPhoneExist_start == Off)))
    {
      /*  폰 비거치 시간 측정 타이머 시작 */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Start_Timer_PhoneLef_ikxf;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_igxy(localDW);
      }

      localDW->sfEvent = c_previousEvent;

      /*  방치알림 신호 출력 후, 폰 비거치 상태-> 다시 폰 거치 확인한 경우 */
    } else if (((uint32)localDW->is_Tick_Timer_PhoneLeft == App_Model_IN_On_flaa) && ((uint32)rtu_Input_OPT_b_WPCPhoneExist == On)) {
      /*  폰 비거치 시간 측정 타이머 취소 */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_jhwb;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_igxy(localDW);
      }

      localDW->sfEvent = c_previousEvent;
    } else {
      /* no actions */
    }

    /*  폰 경고 확인 조건 판단 */
    if ((uint32)localDW->PhoneLeftWrnType_lkkm == PhoneLeftWrnType__Default) {
      if (localDW->Timer_WarningTypeCheck < ((uint16)6000U)) {
        /* 60s */
        if ((uint32)rtu_b_DrvDrSw == On) {
          /*  60초 이내에 DoorOpen 이벤트 발생할 경우,
             경고타입 (1sec Delay 후 6sec 간 경고 출력 발생) 설정 */
          localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__LongDuration;

          /* Nidec 60초이전 이벤트는 충전금지필요%WPCMode가 아닐 때는 상시 On이므로 WPCMode일 때를 위한 조건 */
          *rty_b_PhnLeftChk_Enable = On;

          /* HMC사양에 폰충전불가 주석원복함. */
          c_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_diaj;
          if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
            Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Start_Timer_PhoneWar_b3yi;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
            Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
          }

          localDW->sfEvent = c_previousEvent;
        } else {
          /* WPCMode아닐 때 충전금지위해
             PhnLeftChck_Enable On유지 */
        }
      } else {
        /*  60초 간 Door Open 없을 시, 경고 타입(즉시 500ms 경고 출력 발생) 설정 */
        localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__ShortDuration;

        /* b_PhnLeftChk_Enable = On%Nidec%60초 이후 영향으로 불필요 */
        c_previousEvent = localDW->sfEvent;
        localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_diaj;
        if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
          Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
        }

        localDW->sfEvent = (sint32)event_Start_Timer_PhoneWar_b3yi;
        if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
          Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
        }

        localDW->sfEvent = c_previousEvent;
      }
    }

    /*  폰 경고 확인 시간 중 폰 감지됨100ms900ms */
    if ((localDW->Timer_PhoneWarningCheck >= (uint16)((uint8)10U)) && (localDW->Timer_PhoneWarningCheck <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Input_OPT_b_WPCPhoneExist == On)) {
      /* Output_WPCWarning = Cellphoneonthepad%NFCModeControl연동시그널. IG On중에는 미적용 */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_pmk0;
      if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
      }

      localDW->sfEvent = (sint32)event_Start_Timer_WarningC_lx0t;
      if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
      }

      localDW->sfEvent = c_previousEvent;
    }

    /*  경고 알림 출력
       [(PhoneLeftWrnType == PhoneLeftWrnType__LongDuration&&Timer_WarningComplete >= Par_WarningDelayTime &&...0s
       Timer_WarningComplete <= Par_WarningTime__LongDuration+Par_WarningDelayTime) ||...6s+0s %%DelayDelete_Nidec6s */
    if ((((uint32)localDW->PhoneLeftWrnType_lkkm == PhoneLeftWrnType__LongDuration) && ((uint32)localDW->is_Tick_Timer_WarningComplete == App_Model_IN_On_flaa) && (localDW->Timer_WarningComplete <=
          ((uint16)600U))) || (((uint32)localDW->PhoneLeftWrnType_lkkm == PhoneLeftWrnType__ShortDuration) && ((uint32)localDW->is_Tick_Timer_WarningComplete == App_Model_IN_On_flaa) &&
         (localDW->Timer_WarningComplete <= ((uint16)50U)))) {
      /* 500m */
      *rty_Output_WPCWarning = Cellphonereminder;
      localDW->b_WarnClearEnable = On;

      /*  경고 알림 출력 해제 조건 */
    } else if ((((uint32)localDW->PhoneLeftWrnType_lkkm == PhoneLeftWrnType__LongDuration) && (localDW->Timer_WarningComplete > (((uint16)600U) + ((uint16)0U)))) || (((uint32)
                 localDW->PhoneLeftWrnType_lkkm == PhoneLeftWrnType__ShortDuration) && (localDW->Timer_WarningComplete > ((uint16)50U)))) {
      /* Nidec */
      *rty_Output_WPCWarning = WPCWarningOff;

      /* Output_WPCWarning = SavedPreWPCMode%NidecNidec 필요250219 */
      *rty_b_PhnLeftChk_Enable = Off;

      /* HMC사양에 폰충전불가 주석원복함. */
      c_previousEvent = localDW->sfEvent;
      localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_geeb;
      if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
      }

      localDW->sfEvent = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void App_Model_WPCMode_Run_nbvc(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_DrvDrSw, GearPosSta
  rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool
  *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16
  *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW)
{
  Bool tmp;
  tmp = localDW->b_DrvDrSw_start;
  if (((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P) && ((uint32)rtu_b_DrvDrSw == On)) ||
      ((localDW->b_DrvDrSw_prev != tmp) && ((uint32)tmp == On) && ((uint32)rtu_Input_OPT_GearPosSta == GearPos_P))) {
    sint32 d_previousEvent;

    /* Nidec */
    exit_internal_WPCMode_Run_jkjs(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
    localDW->is_WPCMode_Enable = IN_LeavingPhone_Warning_In_f01q;
    localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
    localDW->b_WarnClearEnable = Off;
    *rty_b_ChargingEnable = Off;
    d_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Start_Timer_WarningT_lnoc;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = d_previousEvent;
    App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
      rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

    /* 1. */
  } else if (((uint32)rtu_Input_OPT_b_LFState == On) || ((uint32)rtu_Input_OPT_b_CurrentFault == On) || ((uint32)rtu_Input_OPT_b_TempSensorFault == On) || ((uint32)rtu_Input_OPT_b_TemperatureFaul ==
              On) || ((uint32)rtu_PhoneLeftWarningWPCStatus == NFCCardDetected)) {
    exit_internal_WPCMode_Run_jkjs(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
    localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_ifk1;
    *rty_Output_OPT_b_FANModeCmd = Off;
    *rty_Output_OPT_b_GreenINDCmd = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    *rty_b_ChargingEnable = Off;

    /* 1. */
    if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
      localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_kphv;
      *rty_Output_WPCWarning = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      *rty_Output_BlinkState = BlinkOff;
      localDW->Counter_BlinkCnt = 0U;
      App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

      /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
      *rty_Output_OPT_b_BlinkState = On;
    } else {
      localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_gqho;
      *rty_Output_WPCWarning = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      *rty_Output_OPT_b_AmberINDCmd = Off;
    }
  } else {
    switch (localDW->is_WPCMode_Run) {
     case App_Mod_IN_WPCRun_Charging_hrde:
      *rty_Output_OPT_b_FANModeCmd = On;

      /* 1. */
      if (((uint32)rtu_Input_OPT_DeviceState == Standby) || ((uint32)rtu_Input_OPT_DeviceState == Init)) {
        localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_k4g3;
        *rty_Output_WPCWarning = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = Off;
        *rty_Output_OPT_b_GreenINDCmd = Off;
        *rty_Output_OPT_b_AmberINDCmd = Off;
      } else {
        /* 2. */
        switch (rtu_Input_OPT_DeviceState) {
         case FODError:
          /*  b_FODFault == On] */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_nm1x;
          *rty_Output_WPCWarning = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_Output_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;
          App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

          /*  Non GFS  */
          *rty_Output_OPT_b_BlinkState = On;
          break;

         case Full_Charge:
          /* 3. */
          localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_mgvv;
          *rty_Output_WPCWarning = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          *rty_Output_OPT_b_GreenINDCmd = On;
          *rty_Output_OPT_b_AmberINDCmd = Off;
          break;

         default:
          Function_ChargingINDColor_ievi(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_mgvv:
      *rty_Output_OPT_b_FANModeCmd = On;

      /* 1. */
      if (((uint32)rtu_Input_OPT_DeviceState == Standby) || ((uint32)rtu_Input_OPT_DeviceState == Init)) {
        localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_k4g3;
        *rty_Output_WPCWarning = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = Off;
        *rty_Output_OPT_b_GreenINDCmd = Off;
        *rty_Output_OPT_b_AmberINDCmd = Off;
      } else {
        /* 2. */
        switch (rtu_Input_OPT_DeviceState) {
         case FODError:
          /*  b_FODFault == On] */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_nm1x;
          *rty_Output_WPCWarning = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          *rty_Output_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;
          App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

          /*  Non GFS  */
          *rty_Output_OPT_b_BlinkState = On;
          break;

         case Charging:
          /* 3. */
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_hrde;
          *rty_Output_WPCWarning = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          Function_ChargingINDColor_ievi(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_nm1x:
      {
        *rty_Output_OPT_b_FANModeCmd = Off;

        /* 1. */
        if (((uint32)rtu_Input_OPT_DeviceState == Standby) || ((uint32)rtu_Input_OPT_DeviceState == Init)) {
          sint32 d_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          *rty_Output_BlinkState = BlinkOff;
          localDW->Counter_BlinkCnt = 0U;
          d_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
          if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
            App_Tick_Timer_AmberINDBlk_m40d(localDW);
          }

          localDW->sfEvent = d_previousEvent;

          /*  Non GFS  */
          *rty_Output_OPT_b_BlinkState = Off;
          localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_k4g3;
          *rty_Output_WPCWarning = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;
          *rty_Output_OPT_b_AmberINDCmd = Off;
        } else {
          /* 2. */
          switch (rtu_Input_OPT_DeviceState) {
           case Charging:
            {
              sint32 d_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_Output_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              d_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
              if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Tick_Timer_AmberINDBlk_m40d(localDW);
              }

              localDW->sfEvent = d_previousEvent;

              /*  Non GFS  */
              *rty_Output_OPT_b_BlinkState = Off;
              localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_hrde;
              *rty_Output_WPCWarning = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              *rty_Output_OPT_b_FANModeCmd = On;
              Function_ChargingINDColor_ievi(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
            }
            break;

           case Full_Charge:
            {
              sint32 d_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              *rty_Output_BlinkState = BlinkOff;
              localDW->Counter_BlinkCnt = 0U;
              d_previousEvent = localDW->sfEvent;
              localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
              if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Tick_Timer_AmberINDBlk_m40d(localDW);
              }

              localDW->sfEvent = d_previousEvent;

              /*  Non GFS  */
              *rty_Output_OPT_b_BlinkState = Off;
              localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_mgvv;
              *rty_Output_WPCWarning = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              *rty_Output_OPT_b_FANModeCmd = On;
              *rty_Output_OPT_b_GreenINDCmd = On;
              *rty_Output_OPT_b_AmberINDCmd = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_k4g3:
      *rty_Output_OPT_b_FANModeCmd = Off;

      /* 1. */
      switch (rtu_Input_OPT_DeviceState) {
       case FODError:
        /*  b_FODFault == On] */
        localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_nm1x;
        *rty_Output_WPCWarning = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        *rty_Output_BlinkState = BlinkOff;
        localDW->Counter_BlinkCnt = 0U;
        *rty_Output_OPT_b_FANModeCmd = Off;
        *rty_Output_OPT_b_GreenINDCmd = Off;
        App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

        /*  Non GFS  */
        *rty_Output_OPT_b_BlinkState = On;
        break;

       case Charging:
        /* 2. */
        localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_hrde;
        *rty_Output_WPCWarning = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = On;
        Function_ChargingINDColor_ievi(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
        break;

       case Full_Charge:
        /* 3. */
        localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_mgvv;
        *rty_Output_WPCWarning = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        *rty_Output_OPT_b_FANModeCmd = On;
        *rty_Output_OPT_b_GreenINDCmd = On;
        *rty_Output_OPT_b_AmberINDCmd = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void exit_internal_WPCMode_Stop_hytv(Bool *rty_Output_OPT_b_BlinkState, BlinkState *rty_Output_BlinkState, DW_WPC_MainControl_EV_250522__T *localDW)
{
  if ((uint32)localDW->is_WPCMode_Stop == App_Mod_IN_WPCStop_TempErr_kphv) {
    sint32 b_previousEvent;

    /* Function_NFCCardDetection() 8차 적용 삭제 */
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_m40d(localDW);
    }

    localDW->sfEvent = b_previousEvent;

    /*  Non GFS  */
    *rty_Output_OPT_b_BlinkState = Off;
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  } else {
    localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_atomic_WPCMode_Disab_m4cj(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW)
{
  sint32 b_previousEvent;
  *rty_Output_WPCWarning = WPCWarningOff;

  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
  *rty_Output_BlinkState = BlinkOff;
  localDW->Counter_BlinkCnt = 0U;

  /* b_ChargingEnable = Off 8차 적용 삭제 */
  *rty_Output_OPT_b_FANModeCmd = Off;
  *rty_Output_OPT_b_GreenINDCmd = Off;
  *rty_Output_OPT_b_AmberINDCmd = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
  if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
    App_Tick_Timer_AmberINDBlk_m40d(localDW);
  }

  localDW->sfEvent = b_previousEvent;

  /* Nidec */
  *rty_b_PhnLeftChk_Enable = Off;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_WPCMode_Off_mlee(Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet rtu_Input_OPT_b_WPCSWOption, Bool rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, C_WPCWarning
  *rty_Output_WPCWarning, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_PhnLeftChk_Enable,
  DW_WPC_MainControl_EV_250522__T *localDW)
{
  /* [hasChangedTo(Input_OPT_GearPosSta,GearPos_P)] */
  if ((uint32)rtu_Input_OPT_GearPosSta == GearPos_P) {
    sint32 b_previousEvent;

    /* Nidec */
    localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_adft;
    localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
    localDW->b_WarnClearEnable = Off;
    b_previousEvent = localDW->sfEvent;
    localDW->sfEvent = (sint32)event_Start_Timer_WarningT_lnoc;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = b_previousEvent;
    App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
      rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

    /* Nidec */
    *rty_b_PhnLeftChk_Enable = On;
  } else {
    localDW->is_WPCMode_Off = IN_LeavingPhone_NoWarning_nxri;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void A_enter_atomic_WPCMode_NFC_mzhi(uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl_EV_250522__T *localDW)
{
  sint32 b_previousEvent;
  localDW->b_WarnClearEnable = Off;
  b_previousEvent = localDW->sfEvent;
  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_jhwb;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
    App_M_Tick_Timer_PhoneLeft_igxy(localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_pmk0;
  if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
    Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_geeb;
  if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
    Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
  }

  localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_diaj;
  if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
    Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
  }

  localDW->sfEvent = b_previousEvent;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void App_Model_WPCMode_Enable_dizk(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool
  rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool
  *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16
  *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW)
{
  /* 1. */
  if ((uint32)rtu_Input_OPT_WPCStatus != WPCMode) {
    switch (localDW->is_WPCMode_Enable) {
     case IN_LeavingPhone_Warning_In_f01q:
      /* Nidec */
      *rty_b_PhnLeftChk_Enable = Off;
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
      break;

     case App_Model_IN_WPCMode_Run_cd5k:
      exit_internal_WPCMode_Run_jkjs(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
      break;

     case App_Model_IN_WPCMode_Stop_ifk1:
      exit_internal_WPCMode_Stop_hytv(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
      localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
      break;

     default:
      /* no actions */
      break;
    }

    /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
    *rty_b_ChargingEnable = Off;
    localDW->is_MainControl = App_Mod_IN_WPCMode_Disable_bpa3;
    enter_atomic_WPCMode_Disab_m4cj(rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable,
      localDW);

    /* 1. */
    if (((uint32)rtu_Input_OPT_WPCStatus == NFCMode) || ((uint32)rtu_Input_OPT_WPCStatus == LPCDMode) || ((uint32)rtu_Input_OPT_WPCStatus == PICCMode)) {
      localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_dm0v;
      A_enter_atomic_WPCMode_NFC_mzhi(rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
    } else {
      localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off_hmmp;
      enter_internal_WPCMode_Off_mlee(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
        rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
    }
  } else {
    switch (localDW->is_WPCMode_Enable) {
     case IN_LeavingPhone_Warning_In_f01q:
      {
        Bool tmp_0;
        GearPosSta tmp;
        tmp = localDW->Input_OPT_GearPosSta_prev;
        tmp_0 = localDW->b_DrvDrSw_start;
        if (((tmp != localDW->Input_OPT_GearPosSta_start) && ((uint32)tmp == GearPos_P)) || ((localDW->b_DrvDrSw_prev != tmp_0) && ((uint32)tmp_0 == Off))) {
          /* Nidec DoorClose */
          /* Nidec */
          *rty_b_PhnLeftChk_Enable = Off;
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_ifk1;
          *rty_Output_OPT_b_FANModeCmd = Off;
          *rty_Output_OPT_b_GreenINDCmd = Off;

          /* b_ROHMOperCmd = Off /_ Non GFS _/ */
          *rty_b_ChargingEnable = Off;

          /* 1. */
          if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
            localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_kphv;
            *rty_Output_WPCWarning = Charging_error;

            /* b_WPCWarn = Charging_error 8차 LFRollBack */
            *rty_Output_BlinkState = BlinkOff;
            localDW->Counter_BlinkCnt = 0U;
            App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

            /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
            *rty_Output_OPT_b_BlinkState = On;
          } else {
            localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_gqho;
            *rty_Output_WPCWarning = WPCWarningOff;

            /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
            *rty_Output_OPT_b_AmberINDCmd = Off;
          }
        } else if ((tmp != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P)) {
          sint32 b_previousEvent;

          /* Nidec */
          *rty_b_PhnLeftChk_Enable = Off;
          localDW->is_WPCMode_Enable = IN_LeavingPhone_Warning_In_f01q;
          localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
          localDW->b_WarnClearEnable = Off;
          *rty_b_ChargingEnable = Off;
          b_previousEvent = localDW->sfEvent;
          localDW->sfEvent = (sint32)event_Start_Timer_WarningT_lnoc;
          if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
            Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
          }

          localDW->sfEvent = b_previousEvent;
          App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
            rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
        } else {
          /* b_PhnLeftChk_Enable = On%Nidec%충전상태를 조건에따라 판단하기위해 주석처리 */
          App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck,
            rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
        }
      }
      break;

     case App_Model_IN_WPCMode_Run_cd5k:
      App_Model_WPCMode_Run_nbvc(rtu_Input_OPT_b_LFState, rtu_Input_OPT_b_CurrentFault, rtu_Input_OPT_b_TempSensorFault, rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption,
        rtu_Input_OPT_b_TemperatureFaul, rtu_Input_OPT_DeviceState, rtu_Input_IND_WPCIndUSMState, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rtu_b_CmdLEDSync, rtu_PhoneLeftWarningWPCStatus,
        rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_Timer_WarningTypeCheck,
        rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_ChargingEnable, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
      break;

     case App_Model_IN_WPCMode_Stop_ifk1:
      {
        *rty_Output_OPT_b_FANModeCmd = Off;
        if (((uint32)rtu_Input_OPT_DeviceState == Full_Charge) && ((uint32)rtu_Input_OPT_b_LFState == Off) && ((uint32)rtu_Input_OPT_b_CurrentFault == Off) && ((uint32)rtu_Input_OPT_b_TemperatureFaul ==
             Off) && ((uint32)rtu_Input_OPT_b_TempSensorFault == Off) && ((uint32)rtu_PhoneLeftWarningWPCStatus == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_hytv(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_cd5k;
          *rty_b_ChargingEnable = On;
          localDW->is_WPCMode_Run = IN_WPCRun_ChargingComplete_mgvv;
          *rty_Output_WPCWarning = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          *rty_Output_OPT_b_GreenINDCmd = On;
          *rty_Output_OPT_b_AmberINDCmd = Off;
        } else if (((uint32)rtu_Input_OPT_DeviceState == Charging) && ((uint32)rtu_Input_OPT_b_LFState == Off) && ((uint32)rtu_Input_OPT_b_CurrentFault == Off) && ((uint32)
                    rtu_Input_OPT_b_TemperatureFaul == Off) && ((uint32)rtu_Input_OPT_b_TempSensorFault == Off) && ((uint32)rtu_PhoneLeftWarningWPCStatus == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_hytv(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
          localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_cd5k;
          *rty_b_ChargingEnable = On;
          localDW->is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_hrde;
          *rty_Output_WPCWarning = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          *rty_Output_OPT_b_FANModeCmd = On;
          Function_ChargingINDColor_ievi(rtu_Input_IND_WPCIndUSMState, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd);
        } else {
          GearPosSta tmp;
          tmp = localDW->Input_OPT_GearPosSta_start;
          if (((localDW->Input_OPT_GearPosSta_prev != tmp) && ((uint32)tmp == GearPos_P) && ((uint32)rtu_b_DrvDrSw == On)) || ((localDW->b_DrvDrSw_prev != localDW->b_DrvDrSw_start) && ((uint32)
                localDW->b_DrvDrSw_start == On) && ((uint32)rtu_Input_OPT_GearPosSta == GearPos_P))) {
            sint32 b_previousEvent;

            /* Nidec */
            exit_internal_WPCMode_Stop_hytv(rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
            localDW->is_WPCMode_Enable = IN_LeavingPhone_Warning_In_f01q;
            localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
            localDW->b_WarnClearEnable = Off;
            *rty_b_ChargingEnable = Off;
            b_previousEvent = localDW->sfEvent;
            localDW->sfEvent = (sint32)event_Start_Timer_WarningT_lnoc;
            if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
              Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
            }

            localDW->sfEvent = b_previousEvent;
            App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
              rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
          } else {
            switch (localDW->is_WPCMode_Stop) {
             case App__IN_WPCStop_NotTempErr_gqho:
              /* 1. */
              if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
                localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_kphv;
                *rty_Output_WPCWarning = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                *rty_Output_BlinkState = BlinkOff;
                localDW->Counter_BlinkCnt = 0U;
                App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

                /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
                *rty_Output_OPT_b_BlinkState = On;

                /* 2. */
              } else if (((uint32)rtu_Input_OPT_b_LFState == Off) && ((uint32)rtu_Input_OPT_b_CurrentFault == Off) && ((uint32)rtu_Input_OPT_b_TempSensorFault == Off) && ((uint32)
                          rtu_PhoneLeftWarningWPCStatus == WPCWarningOff)) {
                localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
                localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Run_cd5k;
                *rty_b_ChargingEnable = On;
                localDW->is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_k4g3;
                *rty_Output_WPCWarning = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                *rty_Output_OPT_b_FANModeCmd = Off;
                *rty_Output_OPT_b_GreenINDCmd = Off;
                *rty_Output_OPT_b_AmberINDCmd = Off;
              } else {
                /* Function_NFCCardDetection() 8차 적용 삭제
                   Function_NFCCardDetection() 8차 적용 삭제 */
              }
              break;

             case App_Mod_IN_WPCStop_TempErr_kphv:
              {
                /* 1. */
                if ((uint32)rtu_Input_OPT_b_TemperatureFaul == Off) {
                  sint32 b_previousEvent;

                  /* Function_NFCCardDetection() 8차 적용 삭제 */
                  *rty_Output_BlinkState = BlinkOff;
                  localDW->Counter_BlinkCnt = 0U;
                  b_previousEvent = localDW->sfEvent;
                  localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
                  if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
                    App_Tick_Timer_AmberINDBlk_m40d(localDW);
                  }

                  localDW->sfEvent = b_previousEvent;

                  /*  Non GFS  */
                  *rty_Output_OPT_b_BlinkState = Off;
                  localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_gqho;
                  *rty_Output_WPCWarning = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  *rty_Output_OPT_b_AmberINDCmd = Off;
                } else {
                  App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);
                }
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_WPCMode_Ena_cy3v(Bool rtu_Input_OPT_b_TemperatureFaul, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool rtu_b_CmdLEDSync, C_WPCWarning *rty_Output_WPCWarning, Bool
  *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState,
  DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_ifk1;
  *rty_Output_OPT_b_FANModeCmd = Off;
  *rty_Output_OPT_b_GreenINDCmd = Off;

  /* b_ROHMOperCmd = Off /_ Non GFS _/ */
  *rty_b_ChargingEnable = Off;

  /* 1. */
  if ((uint32)rtu_Input_OPT_b_TemperatureFaul == On) {
    localDW->is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_kphv;
    *rty_Output_WPCWarning = Charging_error;

    /* b_WPCWarn = Charging_error 8차 LFRollBack */
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    App_Function_LEDErrorBlink_mtqm(rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_Output_BlinkState, localDW);

    /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
    *rty_Output_OPT_b_BlinkState = On;
  } else {
    localDW->is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_gqho;
    *rty_Output_WPCWarning = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    *rty_Output_OPT_b_AmberINDCmd = Off;
  }
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_Tick_Timer__bs5t(DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_Tick_Timer_PhoneLeft = App_Model_IN_Off_nuz2;
  localDW->Timer_PhoneLeft = 0U;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_Tick_Timer__fnog(uint16 *rty_b_Timer_PhoneWarningCheck, DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_nuz2;
  localDW->Timer_PhoneWarningCheck = 0U;

  /* Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
  *rty_b_Timer_PhoneWarningCheck = 0U;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_Tick_Timer__f2g1(uint16 *rty_b_Timer_WarningComplete, DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_Tick_Timer_WarningComplete = App_Model_IN_Off_nuz2;
  localDW->Timer_WarningComplete = 0U;

  /* Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
  *rty_b_Timer_WarningComplete = 0U;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_Tick_Timer__cbjs(DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_nuz2;
  localDW->Timer_AmberINDBlk = 0U;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_Tick_Timer__d3uy(uint16 *rty_b_Timer_WarningTypeCheck, DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_Tick_Timer_WarningTypeCheck = App_Model_IN_Off_nuz2;
  localDW->Timer_WarningTypeCheck = 0U;

  /* Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
  *rty_b_Timer_WarningTypeCheck = 0U;
}

/* Function for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
static void enter_internal_Tick_Timer__gvic(DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_nuz2;
  localDW->Timer_AmberINDBlk2 = 0U;
}

/*
 * System initialize for atomic system:
 *    '<S209>/WPC_MainControl_EV_250522_HMC'
 *    '<S831>/WPC_MainControl_EV_250328_HMC'
 */
void WPC_MainControl_EV_250522__Init(C_WPCWarning *rty_Output_WPCWarning, Bool *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool
  *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16 *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState
  *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_gte2;
  localDW->is_active_MainControl = 0U;
  localDW->is_MainControl = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_Tick_Timer_AmberINDBl = 0U;
  localDW->is_Tick_Timer_AmberINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_Tick_Timer_Amber_berc = 0U;
  localDW->is_Tick_Timer_AmberINDBlk2 = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_Tick_Timer_PhoneLeft = 0U;
  localDW->is_Tick_Timer_PhoneLeft = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_Tick_Timer_PhoneWarni = 0U;
  localDW->is_Tick_Timer_PhoneWarningCheck = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_Tick_Timer_WarningCom = 0U;
  localDW->is_Tick_Timer_WarningComplete = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_Tick_Timer_WarningTyp = 0U;
  localDW->is_Tick_Timer_WarningTypeCheck = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
  localDW->is_active_c61_MainControl_Lib = 0U;
  localDW->Timer_AmberINDBlk = 0U;
  localDW->Timer_PhoneLeft = 0U;
  localDW->Timer_PhoneWarningCheck = 0U;
  localDW->Timer_WarningComplete = 0U;
  localDW->Counter_BlinkCnt = 0U;
  localDW->Timer_WarningTypeCheck = 0U;
  localDW->b_WarnClearEnable = 0U;
  localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
  localDW->Timer_AmberINDBlk2 = 0U;
  *rty_Output_WPCWarning = WPCWarningOff;
  *rty_Output_OPT_b_FANModeCmd = Off;
  *rty_Output_OPT_b_GreenINDCmd = Off;
  *rty_Output_OPT_b_AmberINDCmd = Off;
  *rty_Output_OPT_b_BlinkState = Off;
  *rty_b_Timer_WarningTypeCheck = 0U;
  *rty_b_Timer_PhoneWarningCheck = 0U;
  *rty_b_Timer_WarningComplete = 0U;
  *rty_b_ChargingEnable = Off;
  *rty_Output_BlinkState = BlinkOff;
  *rty_b_PhnLeftChk_Enable = Off;
  localDW->Input_OPT_b_WPCPhoneExist_prev = Off;
  localDW->Input_OPT_b_WPCPhoneExist_start = Off;
  localDW->WPCIndCmdState_prev = WPCIndCmdState__Default;
  localDW->WPCIndCmdState_start = WPCIndCmdState__Default;
  localDW->Input_OPT_GearPosSta_prev = GearPos_P;
  localDW->Input_OPT_GearPosSta_start = GearPos_P;
  localDW->b_DrvDrSw_prev = Off;
  localDW->b_DrvDrSw_start = Off;
}

/*
 * Output and update for atomic system:
 *    '<S209>/WPC_MainControl_EV_250522_HMC'
 *    '<S831>/WPC_MainControl_EV_250328_HMC'
 */
void A_WPC_MainControl_EV_250522_HMC(Bool rtu_Input_OPT_b_LFState, Bool rtu_Input_OPT_b_CurrentFault, Bool rtu_Input_OPT_b_TempSensorFault, Bool rtu_Input_OPT_b_WPCPhoneExist, C_WPCOnOffNvalueSet
  rtu_Input_OPT_b_WPCSWOption, Bool rtu_Input_OPT_b_TemperatureFaul, DeviceState rtu_Input_OPT_DeviceState, WPCStatus rtu_Input_OPT_WPCStatus, WPCIndUSMState rtu_Input_IND_WPCIndUSMState, Bool
  rtu_b_DrvDrSw, GearPosSta rtu_Input_OPT_GearPosSta, Bool rtu_b_CmdLEDSync, WPCIndCmdState rtu_WPCIndCmdState, C_WPCWarning rtu_PhoneLeftWarningWPCStatus, C_WPCWarning *rty_Output_WPCWarning, Bool
  *rty_Output_OPT_b_FANModeCmd, Bool *rty_Output_OPT_b_GreenINDCmd, Bool *rty_Output_OPT_b_AmberINDCmd, Bool *rty_Output_OPT_b_BlinkState, uint16 *rty_b_Timer_WarningTypeCheck, uint16
  *rty_b_Timer_PhoneWarningCheck, uint16 *rty_b_Timer_WarningComplete, Bool *rty_b_ChargingEnable, BlinkState *rty_Output_BlinkState, Bool *rty_b_PhnLeftChk_Enable, DW_WPC_MainControl_EV_250522__T
  *localDW)
{
  localDW->sfEvent = (sint32)App_Model_CALL_EVENT_gte2;
  localDW->Input_OPT_b_WPCPhoneExist_prev = localDW->Input_OPT_b_WPCPhoneExist_start;
  localDW->Input_OPT_b_WPCPhoneExist_start = rtu_Input_OPT_b_WPCPhoneExist;
  localDW->WPCIndCmdState_prev = localDW->WPCIndCmdState_start;
  localDW->WPCIndCmdState_start = rtu_WPCIndCmdState;
  localDW->Input_OPT_GearPosSta_prev = localDW->Input_OPT_GearPosSta_start;
  localDW->Input_OPT_GearPosSta_start = rtu_Input_OPT_GearPosSta;
  localDW->b_DrvDrSw_prev = localDW->b_DrvDrSw_start;
  localDW->b_DrvDrSw_start = rtu_b_DrvDrSw;

  /* Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
  if ((uint32)localDW->is_active_c61_MainControl_Lib == 0U) {
    localDW->Input_OPT_b_WPCPhoneExist_prev = rtu_Input_OPT_b_WPCPhoneExist;
    localDW->WPCIndCmdState_prev = rtu_WPCIndCmdState;
    localDW->Input_OPT_GearPosSta_prev = rtu_Input_OPT_GearPosSta;
    localDW->b_DrvDrSw_prev = rtu_b_DrvDrSw;
    localDW->is_active_c61_MainControl_Lib = 1U;
    localDW->is_active_MainControl = 1U;
    localDW->is_MainControl = App_Model_IN_WPCMode_Init_ebss;
    *rty_Output_WPCWarning = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    *rty_Output_BlinkState = BlinkOff;
    localDW->Counter_BlinkCnt = 0U;
    localDW->b_WarnClearEnable = Off;

    /* b_ChargingEnable = 8차 적용 삭제 */
    *rty_Output_OPT_b_FANModeCmd = Off;
    *rty_Output_OPT_b_GreenINDCmd = Off;
    *rty_Output_OPT_b_AmberINDCmd = Off;

    /* Nidec */
    *rty_b_PhnLeftChk_Enable = Off;
    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_jhwb;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_igxy(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_pmk0;
    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_geeb;
    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_AmberIN_fhe4;
    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_m40d(localDW);
    }

    localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_diaj;
    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
    }

    localDW->sfEvent = -1;
    localDW->is_active_Tick_Timer_PhoneLeft = 1U;
    enter_internal_Tick_Timer__bs5t(localDW);
    localDW->is_active_Tick_Timer_PhoneWarni = 1U;
    enter_internal_Tick_Timer__fnog(rty_b_Timer_PhoneWarningCheck, localDW);
    localDW->is_active_Tick_Timer_WarningCom = 1U;
    enter_internal_Tick_Timer__f2g1(rty_b_Timer_WarningComplete, localDW);
    localDW->is_active_Tick_Timer_AmberINDBl = 1U;
    enter_internal_Tick_Timer__cbjs(localDW);
    localDW->is_active_Tick_Timer_WarningTyp = 1U;
    enter_internal_Tick_Timer__d3uy(rty_b_Timer_WarningTypeCheck, localDW);
    localDW->is_active_Tick_Timer_Amber_berc = 1U;
    enter_internal_Tick_Timer__gvic(localDW);
  } else {
    if ((uint32)localDW->is_active_MainControl != 0U) {
      switch (localDW->is_MainControl) {
       case App_Mod_IN_WPCMode_Disable_bpa3:
        *rty_Output_OPT_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_Input_OPT_WPCStatus == WPCMode) {
          if ((uint32)localDW->is_WPCMode_Disable == App_Model_IN_WPCMode_Off_hmmp) {
            if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_adft) {
              *rty_Output_WPCWarning = WPCWarningOff;

              /* Nidec */
              *rty_b_PhnLeftChk_Enable = Off;
              localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
            } else {
              localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
            }

            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
          } else {
            localDW->is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
          }

          localDW->b_WarnClearEnable = Off;
          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneLe_jhwb;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
            App_M_Tick_Timer_PhoneLeft_igxy(localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_PhoneWa_pmk0;
          if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
            Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_geeb;
          if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
            Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
          }

          localDW->sfEvent = (sint32)event_Cancel_Timer_Warning_diaj;
          if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
            Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
          }

          localDW->sfEvent = -1;
          localDW->is_MainControl = App_Mode_IN_WPCMode_Enable_pqhu;
          enter_internal_WPCMode_Ena_cy3v(rtu_Input_OPT_b_TemperatureFaul, rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd,
            rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_ChargingEnable, rty_Output_BlinkState, localDW);
        } else {
          switch (localDW->is_WPCMode_Disable) {
           case App_Model_IN_WPCMode_NFC_dm0v:
            /* 1. */
            if (((uint32)rtu_Input_OPT_WPCStatus == ModeOff) || ((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start ==
                  GearPos_P))) {
              /* Nide */
              localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off_hmmp;
              enter_internal_WPCMode_Off_mlee(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
            }
            break;

           case App_Model_IN_WPCMode_Off_hmmp:
            /* 1. */
            if (((uint32)rtu_Input_OPT_WPCStatus == NFCMode) || ((uint32)rtu_Input_OPT_WPCStatus == LPCDMode) || ((uint32)rtu_Input_OPT_WPCStatus == PICCMode)) {
              if ((uint32)localDW->is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_adft) {
                *rty_Output_WPCWarning = WPCWarningOff;

                /* Nidec */
                *rty_b_PhnLeftChk_Enable = Off;
                localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
              } else {
                localDW->is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_mv0c;
              }

              localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_dm0v;
              A_enter_atomic_WPCMode_NFC_mzhi(rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
            } else {
              switch (localDW->is_WPCMode_Off) {
               case IN_LeavingPhone_NoWarning_nxri:
                if ((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P)) {
                  localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_adft;
                  localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
                  localDW->b_WarnClearEnable = Off;
                  localDW->sfEvent = (sint32)event_Start_Timer_WarningT_lnoc;
                  if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
                    Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
                  }

                  localDW->sfEvent = -1;
                  App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                    rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

                  /* Nidec */
                  *rty_b_PhnLeftChk_Enable = On;
                }
                break;

               case Ap_IN_LeavingPhone_Warning_adft:
                if ((localDW->Input_OPT_GearPosSta_prev != localDW->Input_OPT_GearPosSta_start) && ((uint32)localDW->Input_OPT_GearPosSta_start == GearPos_P)) {
                  *rty_Output_WPCWarning = WPCWarningOff;

                  /* Nidec */
                  *rty_b_PhnLeftChk_Enable = Off;
                  localDW->is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_adft;
                  localDW->PhoneLeftWrnType_lkkm = PhoneLeftWrnType__Default;
                  localDW->b_WarnClearEnable = Off;
                  localDW->sfEvent = (sint32)event_Start_Timer_WarningT_lnoc;
                  if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
                    Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
                  }

                  localDW->sfEvent = -1;
                  App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                    rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);

                  /* Nidec */
                  *rty_b_PhnLeftChk_Enable = On;
                } else {
                  App_Mo_Function_WPCWarning_dcfw(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
                    rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
                }
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
        break;

       case App_Mode_IN_WPCMode_Enable_pqhu:
        App_Model_WPCMode_Enable_dizk(rtu_Input_OPT_b_LFState, rtu_Input_OPT_b_CurrentFault, rtu_Input_OPT_b_TempSensorFault, rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption,
          rtu_Input_OPT_b_TemperatureFaul, rtu_Input_OPT_DeviceState, rtu_Input_OPT_WPCStatus, rtu_Input_IND_WPCIndUSMState, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rtu_b_CmdLEDSync,
          rtu_PhoneLeftWarningWPCStatus, rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState,
          rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_ChargingEnable, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable, localDW);
        break;

       case App_Model_IN_WPCMode_Init_ebss:
        *rty_Output_OPT_b_FANModeCmd = Off;

        /* 1. */
        if ((uint32)rtu_Input_OPT_WPCStatus != WPCMode) {
          localDW->is_MainControl = App_Mod_IN_WPCMode_Disable_bpa3;
          enter_atomic_WPCMode_Disab_m4cj(rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd, rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_BlinkState, rty_b_PhnLeftChk_Enable,
            localDW);

          /* 1. */
          if (((uint32)rtu_Input_OPT_WPCStatus == NFCMode) || ((uint32)rtu_Input_OPT_WPCStatus == LPCDMode) || ((uint32)rtu_Input_OPT_WPCStatus == PICCMode)) {
            localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_dm0v;
            A_enter_atomic_WPCMode_NFC_mzhi(rty_b_Timer_WarningTypeCheck, rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, localDW);
          } else {
            localDW->is_WPCMode_Disable = App_Model_IN_WPCMode_Off_hmmp;
            enter_internal_WPCMode_Off_mlee(rtu_Input_OPT_b_WPCPhoneExist, rtu_Input_OPT_b_WPCSWOption, rtu_b_DrvDrSw, rtu_Input_OPT_GearPosSta, rty_Output_WPCWarning, rty_b_Timer_WarningTypeCheck,
              rty_b_Timer_PhoneWarningCheck, rty_b_Timer_WarningComplete, rty_b_PhnLeftChk_Enable, localDW);
          }

          /* 2 */
        } else if ((uint32)rtu_Input_OPT_WPCStatus == WPCMode) {
          localDW->is_MainControl = App_Mode_IN_WPCMode_Enable_pqhu;
          enter_internal_WPCMode_Ena_cy3v(rtu_Input_OPT_b_TemperatureFaul, rtu_Input_IND_WPCIndUSMState, rtu_b_CmdLEDSync, rty_Output_WPCWarning, rty_Output_OPT_b_FANModeCmd,
            rty_Output_OPT_b_GreenINDCmd, rty_Output_OPT_b_AmberINDCmd, rty_Output_OPT_b_BlinkState, rty_b_ChargingEnable, rty_Output_BlinkState, localDW);
        } else {
          /* no actions */
        }
        break;

       default:
        /* no actions */
        break;
      }
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_igxy(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_f1qw(rty_b_Timer_PhoneWarningCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_fhjl(rty_b_Timer_WarningComplete, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_m40d(localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_ck1w(rty_b_Timer_WarningTypeCheck, localDW);
    }

    if ((uint32)localDW->is_active_Tick_Timer_Amber_berc != 0U) {
      Ap_Tick_Timer_AmberINDBlk2_eqqq(localDW);
    }
  }

  /* End of Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
}

/* System initialize for atomic system: '<S19>/WPC_MainControl_Function' */
void A_WPC_MainControl_Function_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_m0hg, Bool *rty_MainOut_Sig_lm4d, Bool *rty_MainOut_Sig_gidz, Bool *rty_MainOut_Sig_gyaw, uint16
  *rty_MainOut_Sig_bv10, uint16 *rty_MainOut_Sig_jtve, uint16 *rty_MainOut_Sig_jymu, Bool *rty_MainOut_Sig_a14n, BlinkState *rty_MainOut_Sig_hq4y, Bool *rty_MainOut_Sig_khfv, uint16
  *rty_MainOut_Sig_lzgx)
{
  /* SystemInitialize for Chart: '<S25>/Chart' */
  App_Model_Chart_Init(&App_Model_B.MainContMode_foyi, &App_Model_DW.sf_Chart);

  /* SystemInitialize for IfAction SubSystem: '<S25>/nonNFC_ICE' */

  /* SystemInitialize for Chart: '<S212>/WPC_MainControl2_250507' */
  Ap_WPC_MainControl2_250507_Init(&App_Model_B.C_WPCWarning_abjx, &App_Model_B.b_FANModeCmd_oklr, &App_Model_B.b_GreenINDCmd_dnef, &App_Model_B.b_AmberINDCmd_cmmc, &App_Model_B.b_BlinkState_gbtl,
    &App_Model_B.b_Timer_PhoneReminderCheck_fcw3, &App_Model_B.b_Timer_PhoneWarningCheck_osxd, &App_Model_B.b_Timer_WarningComplete_jnak, &App_Model_B.b_ChargingEnable_otie,
    &App_Model_B.BlinkState_axn0, &App_Model_B.b_PhnLeftChk_Enable_oxbc, &App_Model_DW.sf_WPC_MainControl2_250507);

  /* End of SystemInitialize for SubSystem: '<S25>/nonNFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/nonNFC_EV' */

  /* SystemInitialize for Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
  WPC_MainControl2_EV_250328_Init(&App_Model_B.Output_WPCWarning_eqd5, &App_Model_B.Output_OPT_b_FANModeCmd_cl1i, &App_Model_B.Output_OPT_b_GreenINDCmd_j1ge, &App_Model_B.Output_OPT_b_AmberINDCmd_imzc,
    &App_Model_B.Output_OPT_b_BlinkState_cn4e, &App_Model_B.b_Timer_WarningTypeCheck_iljm, &App_Model_B.b_Timer_PhoneWarningCheck_fwqa, &App_Model_B.b_Timer_WarningComplete_ljqi,
    &App_Model_B.b_ChargingEnable_jtx4, &App_Model_B.Output_BlinkState_alue, &App_Model_B.b_PhnLeftChk_Enable_gcof, &App_Model_DW.sf_WPC_MainControl2_EV_250328_H);

  /* End of SystemInitialize for SubSystem: '<S25>/nonNFC_EV' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/NFC_ICE' */

  /* SystemInitialize for Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
  WPC_MainControl3_CardSync__Init(&App_Model_B.C_WPCWarning_fnhu, &App_Model_B.b_FANModeCmd_oa2p, &App_Model_B.b_GreenINDCmd_f4jf, &App_Model_B.b_AmberINDCmd_b4wu, &App_Model_B.b_BlinkState_ofpx,
    &App_Model_B.b_Timer_PhoneReminderCheck_kbyt, &App_Model_B.b_Timer_PhoneWarningCheck_p5cr, &App_Model_B.b_Timer_WarningComplete_d2v5, &App_Model_B.b_ChargingEnable_n0zl,
    &App_Model_B.BlinkState_e1cz, &App_Model_B.b_PhnLeftChk_Enable_cnve, &App_Model_DW.sf_WPC_MainControl3_CardSync_25);

  /* End of SystemInitialize for SubSystem: '<S25>/NFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/NFC_EV' */

  /* SystemInitialize for Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
  WPC_MainControl_EV_250522__Init(&App_Model_B.Output_WPCWarning_ltaw, &App_Model_B.Output_OPT_b_FANModeCmd_k23k, &App_Model_B.Output_OPT_b_GreenINDCmd_axpq, &App_Model_B.Output_OPT_b_AmberINDCmd_jeww,
    &App_Model_B.Output_OPT_b_BlinkState_egfi, &App_Model_B.b_Timer_WarningTypeCheck_ffan, &App_Model_B.b_Timer_PhoneWarningCheck_je1q, &App_Model_B.b_Timer_WarningComplete_guzk,
    &App_Model_B.b_ChargingEnable_dbhd, &App_Model_B.Output_BlinkState_djmk, &App_Model_B.b_PhnLeftChk_Enable_hrqc, &App_Model_DW.sf_WPC_MainControl_EV_250522_HM);

  /* End of SystemInitialize for SubSystem: '<S25>/NFC_EV' */

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig = WPCWarningOff;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_hq4y = BlinkOff;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_khfv = Off;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_lzgx = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_m0hg = Off;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_lm4d = Off;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_gidz = Off;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_gyaw = Off;

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_bv10 = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_jtve = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_jymu = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S25>/Merge' */
  *rty_MainOut_Sig_a14n = Off;
}

/* System reset for atomic system: '<S19>/WPC_MainControl_Function' */
void WPC_MainControl_Function_Reset(void)
{
  /* SystemReset for Chart: '<S25>/Chart' */
  App_Model_Chart_Reset(&App_Model_B.MainContMode_foyi, &App_Model_DW.sf_Chart);
}

/* Output and update for atomic system: '<S19>/WPC_MainControl_Function' */
void App_Mo_WPC_MainControl_Function(Bool rtu_Main_InSig, Bool rtu_Main_InSig_m0hg, Bool rtu_Main_InSig_lm4d, Bool rtu_Main_InSig_gidz, Bool rtu_Main_InSig_gyaw, C_WPCOnOffNvalueSet
  rtu_Main_InSig_bv10, Bool rtu_Main_InSig_jtve, Bool rtu_Main_InSig_jymu, Bool rtu_Main_InSig_a14n, Bool rtu_Main_InSig_hq4y, DeviceState rtu_Main_InSig_khfv, WPCStatus rtu_Main_InSig_lzgx, Bool
  rtu_Main_InSig_h0c5, WPCIndUSMState rtu_Main_InSig_k1w3, Bool rtu_Main_InSig_fwrw, WPCIndCmdState rtu_Main_InSig_hwiv, GearPosSta rtu_Main_InSig_fy33, C_WPCWarning rtu_Main_InSig_no0k, C_WPCWarning *
  rty_MainOut_Sig, Bool *rty_MainOut_Sig_m0hg, Bool *rty_MainOut_Sig_lm4d, Bool *rty_MainOut_Sig_gidz, Bool *rty_MainOut_Sig_gyaw, uint16 *rty_MainOut_Sig_bv10, uint16 *rty_MainOut_Sig_jtve, uint16
  *rty_MainOut_Sig_jymu, Bool *rty_MainOut_Sig_a14n, BlinkState *rty_MainOut_Sig_hq4y, Bool *rty_MainOut_Sig_khfv, uint16 *rty_MainOut_Sig_lzgx)
{
  /* Chart: '<S25>/Chart' */
  App_Model_Chart(rtu_Main_InSig, rtu_Main_InSig_m0hg, &App_Model_B.MainContMode_foyi, &App_Model_DW.sf_Chart);

  /* SwitchCase: '<S25>/Switch Case1' */
  switch (App_Model_B.MainContMode_foyi) {
   case nonNFC_ICE:
    /* Outputs for IfAction SubSystem: '<S25>/nonNFC_ICE' incorporates:
     *  ActionPort: '<S212>/ActionPort'
     */
    /* Chart: '<S212>/WPC_MainControl2_250507' */
    App_Mod_WPC_MainControl2_250507(rtu_Main_InSig_lm4d, rtu_Main_InSig_gidz, rtu_Main_InSig_gyaw, rtu_Main_InSig_bv10, rtu_Main_InSig_jtve, rtu_Main_InSig_jymu, rtu_Main_InSig_a14n,
      rtu_Main_InSig_hq4y, rtu_Main_InSig_khfv, rtu_Main_InSig_lzgx, rtu_Main_InSig_h0c5, rtu_Main_InSig_k1w3, rtu_Main_InSig_fwrw, rtu_Main_InSig_hwiv, &App_Model_B.C_WPCWarning_abjx,
      &App_Model_B.b_FANModeCmd_oklr, &App_Model_B.b_GreenINDCmd_dnef, &App_Model_B.b_AmberINDCmd_cmmc, &App_Model_B.b_BlinkState_gbtl, &App_Model_B.b_Timer_PhoneReminderCheck_fcw3,
      &App_Model_B.b_Timer_PhoneWarningCheck_osxd, &App_Model_B.b_Timer_WarningComplete_jnak, &App_Model_B.b_ChargingEnable_otie, &App_Model_B.BlinkState_axn0, &App_Model_B.b_PhnLeftChk_Enable_oxbc,
      &App_Model_DW.sf_WPC_MainControl2_250507);

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig = App_Model_B.C_WPCWarning_abjx;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_m0hg = App_Model_B.b_FANModeCmd_oklr;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_khfv = App_Model_B.b_PhnLeftChk_Enable_oxbc;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_lzgx = App_Model_ConstB.b_Timer_WarningTy_mfz2gjnlk;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_lm4d = App_Model_B.b_GreenINDCmd_dnef;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_gidz = App_Model_B.b_AmberINDCmd_cmmc;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_gyaw = App_Model_B.b_BlinkState_gbtl;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_bv10 = App_Model_B.b_Timer_PhoneReminderCheck_fcw3;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_jtve = App_Model_B.b_Timer_PhoneWarningCheck_osxd;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_jymu = App_Model_B.b_Timer_WarningComplete_jnak;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_a14n = App_Model_B.b_ChargingEnable_otie;

    /* SignalConversion generated from: '<S212>/nonNFC_nonEV' */
    *rty_MainOut_Sig_hq4y = App_Model_B.BlinkState_axn0;

    /* End of Outputs for SubSystem: '<S25>/nonNFC_ICE' */
    break;

   case nonNFC_EV:
    /* Outputs for IfAction SubSystem: '<S25>/nonNFC_EV' incorporates:
     *  ActionPort: '<S211>/ActionPort'
     */
    /* Chart: '<S211>/WPC_MainControl2_EV_250328_HMC' */
    WPC_MainControl2_EV_250328_HMC(rtu_Main_InSig_lm4d, rtu_Main_InSig_gidz, rtu_Main_InSig_gyaw, rtu_Main_InSig_hq4y, rtu_Main_InSig_bv10, rtu_Main_InSig_jtve, rtu_Main_InSig_khfv,
      rtu_Main_InSig_lzgx, rtu_Main_InSig_k1w3, rtu_Main_InSig_a14n, rtu_Main_InSig_fy33, rtu_Main_InSig_fwrw, rtu_Main_InSig_hwiv, &App_Model_B.Output_WPCWarning_eqd5,
      &App_Model_B.Output_OPT_b_FANModeCmd_cl1i, &App_Model_B.Output_OPT_b_GreenINDCmd_j1ge, &App_Model_B.Output_OPT_b_AmberINDCmd_imzc, &App_Model_B.Output_OPT_b_BlinkState_cn4e,
      &App_Model_B.b_Timer_WarningTypeCheck_iljm, &App_Model_B.b_Timer_PhoneWarningCheck_fwqa, &App_Model_B.b_Timer_WarningComplete_ljqi, &App_Model_B.b_ChargingEnable_jtx4,
      &App_Model_B.Output_BlinkState_alue, &App_Model_B.b_PhnLeftChk_Enable_gcof, &App_Model_DW.sf_WPC_MainControl2_EV_250328_H);

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig = App_Model_B.Output_WPCWarning_eqd5;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_m0hg = App_Model_B.Output_OPT_b_FANModeCmd_cl1i;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_khfv = App_Model_B.b_PhnLeftChk_Enable_gcof;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_lzgx = App_Model_B.b_Timer_WarningTypeCheck_iljm;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_lm4d = App_Model_B.Output_OPT_b_GreenINDCmd_j1ge;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_gidz = App_Model_B.Output_OPT_b_AmberINDCmd_imzc;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_gyaw = App_Model_B.Output_OPT_b_BlinkState_cn4e;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_bv10 = App_Model_ConstB.b_Timer_PhoneRemi_fuw5aotm5;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_jtve = App_Model_B.b_Timer_PhoneWarningCheck_fwqa;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_jymu = App_Model_B.b_Timer_WarningComplete_ljqi;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_a14n = App_Model_B.b_ChargingEnable_jtx4;

    /* SignalConversion generated from: '<S211>/nonNFC_EV' */
    *rty_MainOut_Sig_hq4y = App_Model_B.Output_BlinkState_alue;

    /* End of Outputs for SubSystem: '<S25>/nonNFC_EV' */
    break;

   case NFC_ICE:
    /* Outputs for IfAction SubSystem: '<S25>/NFC_ICE' incorporates:
     *  ActionPort: '<S210>/ActionPort'
     */
    /* Chart: '<S210>/WPC_MainControl3_CardSync_250522' */
    WPC_MainControl3_CardSync_25052(rtu_Main_InSig_lm4d, rtu_Main_InSig_gidz, rtu_Main_InSig_gyaw, rtu_Main_InSig_bv10, rtu_Main_InSig_jtve, rtu_Main_InSig_jymu, rtu_Main_InSig_a14n,
      rtu_Main_InSig_hq4y, rtu_Main_InSig_khfv, rtu_Main_InSig_lzgx, rtu_Main_InSig_h0c5, rtu_Main_InSig_k1w3, rtu_Main_InSig_fwrw, rtu_Main_InSig_hwiv, rtu_Main_InSig_no0k,
      &App_Model_B.C_WPCWarning_fnhu, &App_Model_B.b_FANModeCmd_oa2p, &App_Model_B.b_GreenINDCmd_f4jf, &App_Model_B.b_AmberINDCmd_b4wu, &App_Model_B.b_BlinkState_ofpx,
      &App_Model_B.b_Timer_PhoneReminderCheck_kbyt, &App_Model_B.b_Timer_PhoneWarningCheck_p5cr, &App_Model_B.b_Timer_WarningComplete_d2v5, &App_Model_B.b_ChargingEnable_n0zl,
      &App_Model_B.BlinkState_e1cz, &App_Model_B.b_PhnLeftChk_Enable_cnve, &App_Model_DW.sf_WPC_MainControl3_CardSync_25);

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig = App_Model_B.C_WPCWarning_fnhu;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_m0hg = App_Model_B.b_FANModeCmd_oa2p;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_khfv = App_Model_B.b_PhnLeftChk_Enable_cnve;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_lzgx = App_Model_ConstB.b_Timer_WarningTyp_mfz2gjnl;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_lm4d = App_Model_B.b_GreenINDCmd_f4jf;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_gidz = App_Model_B.b_AmberINDCmd_b4wu;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_gyaw = App_Model_B.b_BlinkState_ofpx;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_bv10 = App_Model_B.b_Timer_PhoneReminderCheck_kbyt;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_jtve = App_Model_B.b_Timer_PhoneWarningCheck_p5cr;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_jymu = App_Model_B.b_Timer_WarningComplete_d2v5;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_a14n = App_Model_B.b_ChargingEnable_n0zl;

    /* SignalConversion generated from: '<S210>/NFC_nonEV' */
    *rty_MainOut_Sig_hq4y = App_Model_B.BlinkState_e1cz;

    /* End of Outputs for SubSystem: '<S25>/NFC_ICE' */
    break;

   case NFC_EV:
    /* Outputs for IfAction SubSystem: '<S25>/NFC_EV' incorporates:
     *  ActionPort: '<S209>/ActionPort'
     */
    /* Chart: '<S209>/WPC_MainControl_EV_250522_HMC' */
    A_WPC_MainControl_EV_250522_HMC(rtu_Main_InSig_lm4d, rtu_Main_InSig_gidz, rtu_Main_InSig_gyaw, rtu_Main_InSig_hq4y, rtu_Main_InSig_bv10, rtu_Main_InSig_jtve, rtu_Main_InSig_khfv,
      rtu_Main_InSig_lzgx, rtu_Main_InSig_k1w3, rtu_Main_InSig_a14n, rtu_Main_InSig_fy33, rtu_Main_InSig_fwrw, rtu_Main_InSig_hwiv, rtu_Main_InSig_no0k, &App_Model_B.Output_WPCWarning_ltaw,
      &App_Model_B.Output_OPT_b_FANModeCmd_k23k, &App_Model_B.Output_OPT_b_GreenINDCmd_axpq, &App_Model_B.Output_OPT_b_AmberINDCmd_jeww, &App_Model_B.Output_OPT_b_BlinkState_egfi,
      &App_Model_B.b_Timer_WarningTypeCheck_ffan, &App_Model_B.b_Timer_PhoneWarningCheck_je1q, &App_Model_B.b_Timer_WarningComplete_guzk, &App_Model_B.b_ChargingEnable_dbhd,
      &App_Model_B.Output_BlinkState_djmk, &App_Model_B.b_PhnLeftChk_Enable_hrqc, &App_Model_DW.sf_WPC_MainControl_EV_250522_HM);

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig = App_Model_B.Output_WPCWarning_ltaw;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_m0hg = App_Model_B.Output_OPT_b_FANModeCmd_k23k;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_khfv = App_Model_B.b_PhnLeftChk_Enable_hrqc;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_lzgx = App_Model_B.b_Timer_WarningTypeCheck_ffan;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_lm4d = App_Model_B.Output_OPT_b_GreenINDCmd_axpq;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_gidz = App_Model_B.Output_OPT_b_AmberINDCmd_jeww;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_gyaw = App_Model_B.Output_OPT_b_BlinkState_egfi;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_bv10 = App_Model_ConstB.b_Timer_PhoneRemin_fuw5aotm;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_jtve = App_Model_B.b_Timer_PhoneWarningCheck_je1q;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_jymu = App_Model_B.b_Timer_WarningComplete_guzk;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_a14n = App_Model_B.b_ChargingEnable_dbhd;

    /* SignalConversion generated from: '<S209>/NFC_EV' */
    *rty_MainOut_Sig_hq4y = App_Model_B.Output_BlinkState_djmk;

    /* End of Outputs for SubSystem: '<S25>/NFC_EV' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S25>/Switch Case1' */
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void Tick_Timer_PhnLeftChatteri_b3cl(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhnLeftChatt_eous) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhnLeftC_hlfc) {
      App_Model_DW.is_Tick_Timer_PhnLeftChatt_eous = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_PhnLeft_ekpc) {
        App_Model_DW.is_Tick_Timer_PhnLeftChatt_eous = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhnLeftChattering_jk53 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhnLeftChattering_jk53 + 1;
        if (((sint32)App_Model_DW.Timer_PhnLeftChattering_jk53 + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhnLeftChattering_jk53 = (uint16)tmp;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhnLeftC_hlfc) {
          App_Model_DW.Timer_PhnLeftChattering_jk53 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void Tick_Timer_PhoneReminderCh_dizt(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneReminde_davg) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhoneRem_dsov) {
      App_Model_DW.is_Tick_Timer_PhoneReminde_davg = App_Model_IN_On_pbff;
      App_Model_DW.b_Timer_PhoneReminderCheck_fpiw = On;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_PhoneRe_jjf3) {
        App_Model_DW.is_Tick_Timer_PhoneReminde_davg = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneReminderCheck_gd2r = 0U;
        App_Model_B.b_Timer_PhoneReminderCheck_btkg = 0U;
        App_Model_DW.b_Timer_PhoneReminderCheck_fpiw = Off;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneReminderCheck_gd2r + 1;
        if (((sint32)App_Model_DW.Timer_PhoneReminderCheck_gd2r + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneReminderCheck_gd2r = (uint16)tmp;
        App_Model_B.b_Timer_PhoneReminderCheck_btkg = App_Model_DW.Timer_PhoneReminderCheck_gd2r;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhoneRem_dsov) {
          App_Model_DW.Timer_PhoneReminderCheck_gd2r = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void Tick_Timer_WarningComplete_nw2l(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningCompl_d0pq) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_WarningC_esnt) {
      App_Model_DW.is_Tick_Timer_WarningCompl_d0pq = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_Warning_niui) {
        App_Model_DW.is_Tick_Timer_WarningCompl_d0pq = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_WarningComplete_inev = 0U;
        App_Model_B.b_Timer_WarningComplete_oufu = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningComplete_inev + 1;
        if (((sint32)App_Model_DW.Timer_WarningComplete_inev + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete_inev = (uint16)tmp;
        App_Model_B.b_Timer_WarningComplete_oufu = App_Model_DW.Timer_WarningComplete_inev;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_WarningC_esnt) {
          App_Model_DW.Timer_WarningComplete_inev = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void App_M_Tick_Timer_PhoneLeft_mgtt(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft_oo5f) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhoneLef_j1qj) {
      App_Model_DW.is_Tick_Timer_PhoneLeft_oo5f = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_PhoneLe_ftby) {
        App_Model_DW.is_Tick_Timer_PhoneLeft_oo5f = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneLeft_g0qt = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneLeft_g0qt + 1;
        if (((sint32)App_Model_DW.Timer_PhoneLeft_g0qt + 1) > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft_g0qt = (uint8)tmp;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhoneLef_j1qj) {
          App_Model_DW.Timer_PhoneLeft_g0qt = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void Tick_Timer_PhoneWarningChe_cc3i(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarning_m4i5) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhoneWar_n1mt) {
      App_Model_DW.is_Tick_Timer_PhoneWarning_m4i5 = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_PhoneWa_hotu) {
        App_Model_DW.is_Tick_Timer_PhoneWarning_m4i5 = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneWarningCheck_dcqd = 0U;
        App_Model_B.b_Timer_PhoneWarningCheck_bml0 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneWarningCheck_dcqd + 1;
        if (((sint32)App_Model_DW.Timer_PhoneWarningCheck_dcqd + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck_dcqd = (uint16)tmp;
        App_Model_B.b_Timer_PhoneWarningCheck_bml0 = App_Model_DW.Timer_PhoneWarningCheck_dcqd;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_PhoneWar_n1mt) {
          App_Model_DW.Timer_PhoneWarningCheck_dcqd = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void App_Mo_Function_WPCWarning_anx5(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21)
{
  /* Outputs for IfAction SubSystem: '<S220>/nonNFC_ICE' incorporates:
   *  ActionPort: '<S402>/ActionPort'
   */
  /* SwitchCase: '<S220>/Switch Case1' incorporates:
   *  Chart: '<S402>/WPC2_MainControl2_250507'
   */
  /* 1 */
  if (((uint32)rtu_Main_InSig_e0fo == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck_dcqd >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == Off)) ||
      (App_Model_DW.Timer_PhoneLeft_g0qt >= ((uint8)50U))) {
    sint32 d_previousEvent;
    App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
    App_Model_DW.b_WarnClearEnable_lyus = Off;
    App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
    d_previousEvent = App_Model_DW.sfEvent_g0by;
    App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneLe_ftby;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_g4qp != 0U) {
      App_M_Tick_Timer_PhoneLeft_mgtt();
    }

    App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneWa_hotu;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
      Tick_Timer_PhoneWarningChe_cc3i();
    }

    App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
      Tick_Timer_PhoneReminderCh_dizt();
    }

    App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_Warning_niui;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_hwpi != 0U) {
      Tick_Timer_WarningComplete_nw2l();
    }

    App_Model_DW.sfEvent_g0by = d_previousEvent;
  } else {
    sint32 d_previousEvent;
    Bool tmp;

    /* 1. */
    tmp = App_Model_DW.b_WPCPhoneExist_start_mymr;
    if (((uint32)App_Model_DW.b_WarnClearEnable_lyus == On) && ((App_Model_DW.b_WPCPhoneExist_prev_hngm != tmp) && ((uint32)tmp == Off))) {
      d_previousEvent = App_Model_DW.sfEvent_g0by;
      App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_PhoneLef_j1qj;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_g4qp != 0U) {
        App_M_Tick_Timer_PhoneLeft_mgtt();
      }

      App_Model_DW.sfEvent_g0by = d_previousEvent;

      /* 1. */
    } else if (((uint32)App_Model_DW.is_Tick_Timer_PhoneLeft_oo5f == App_Model_IN_On_pbff) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      d_previousEvent = App_Model_DW.sfEvent_g0by;
      App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneLe_ftby;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_g4qp != 0U) {
        App_M_Tick_Timer_PhoneLeft_mgtt();
      }

      App_Model_DW.sfEvent_g0by = d_previousEvent;
    } else {
      /* no actions */
    }

    if ((App_Model_DW.Timer_PhoneWarningCheck_dcqd >= ((uint16)10U)) && (App_Model_DW.Timer_PhoneWarningCheck_dcqd <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      App_Model_B.C_WPCWarning_bs3s = Cellphoneonthepad;
      App_Model_DW.b_WarnClearEnable_lyus = On;
      d_previousEvent = App_Model_DW.sfEvent_g0by;
      App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneWa_hotu;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
        Tick_Timer_PhoneWarningChe_cc3i();
      }

      App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_PhoneRem_dsov;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
        Tick_Timer_PhoneReminderCh_dizt();
      }

      App_Model_DW.sfEvent_g0by = d_previousEvent;

      /* 5차 적용 */
    } else {
      tmp = App_Model_DW.C_DrvDrSw_start_hwlv;
      if (((uint32)App_Model_DW.b_Timer_PhoneReminderCheck_fpiw == On) && (App_Model_DW.Timer_PhoneReminderCheck_gd2r < ((uint16)6000U)) && ((uint32)App_Model_DW.b_WarnClearEnable_lyus == On) &&
          ((uint32)rtu_Main_InSig_nt21 == On) && (((App_Model_DW.C_DrvDrSw_prev_a1mt != tmp) && ((uint32)tmp == On)) || ((App_Model_DW.C_AstDrSw_prev_n4pb != App_Model_DW.C_AstDrSw_start_a3od) &&
            ((uint32)App_Model_DW.C_AstDrSw_start_a3od == On)))) {
        App_Model_B.C_WPCWarning_bs3s = Cellphoneonthepad;
        d_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
          Tick_Timer_PhoneReminderCh_dizt();
        }

        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_PhnLeftC_hlfc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhnLe_c01w != 0U) {
          Tick_Timer_PhnLeftChatteri_b3cl();
        }

        App_Model_DW.sfEvent_g0by = d_previousEvent;
      } else if ((App_Model_DW.Timer_PhoneReminderCheck_gd2r >= ((uint16)6000U)) && ((uint32)App_Model_DW.b_WarnClearEnable_lyus == On) && ((uint32)rtu_Main_InSig_nt21 == On)) {
        /* 1. */
        if (((uint32)rtu_Main_InSig_nv40 == On) || ((uint32)rtu_Main_InSig_jjhc == On)) {
          App_Model_DW.b_WarnClearEnable_lyus = Off;
          App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
          App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
          d_previousEvent = App_Model_DW.sfEvent_g0by;
          App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
            Tick_Timer_PhoneReminderCh_dizt();
          }

          App_Model_DW.sfEvent_g0by = d_previousEvent;
        } else {
          /* 2. */
          App_Model_B.C_WPCWarning_bs3s = Cellphonereminder;
          d_previousEvent = App_Model_DW.sfEvent_g0by;
          App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
            Tick_Timer_PhoneReminderCh_dizt();
          }

          App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_WarningC_esnt;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_hwpi != 0U) {
            Tick_Timer_WarningComplete_nw2l();
          }

          App_Model_DW.sfEvent_g0by = d_previousEvent;
        }
      } else if ((App_Model_DW.Timer_WarningComplete_inev >= ((uint16)50U)) && ((uint32)App_Model_DW.b_WarnClearEnable_lyus == On) && ((uint32)rtu_Main_InSig_nt21 == On)) {
        App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
        App_Model_DW.b_WarnClearEnable_lyus = Off;
        App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
        d_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_Warning_niui;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_hwpi != 0U) {
          Tick_Timer_WarningComplete_nw2l();
        }

        App_Model_DW.sfEvent_g0by = d_previousEvent;
      } else if ((App_Model_DW.Timer_PhnLeftChattering_jk53 >= ((uint16)600U)) && ((uint32)App_Model_DW.b_WarnClearEnable_lyus == On) && ((uint32)rtu_Main_InSig_nt21 == On)) {
        App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
        App_Model_DW.b_WarnClearEnable_lyus = Off;
        d_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhnLeft_ekpc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhnLe_c01w != 0U) {
          Tick_Timer_PhnLeftChatteri_b3cl();
        }

        App_Model_DW.sfEvent_g0by = d_previousEvent;
      } else {
        /* no actions */
      }
    }
  }

  /* End of SwitchCase: '<S220>/Switch Case1' */
  /* End of Outputs for SubSystem: '<S220>/nonNFC_ICE' */
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void Function_ChargingINDColor_nkrs(WPCIndUSMState rtu_Main_InSig_nwkh)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) {
    App_Model_B.b_GreenINDCmd_otki = On;
    App_Model_B.b_AmberINDCmd_a4kq = Off;
  } else {
    App_Model_B.b_GreenINDCmd_otki = Off;
    App_Model_B.b_AmberINDCmd_a4kq = On;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void Ap_Tick_Timer_AmberINDBlk2_hmqx(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_AmberIND_ho5y) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_AmberIN_eo3b) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk2_hgzx = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk2_hgzx + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk2_hgzx + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2_hgzx = (uint16)tmp;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_AmberIND_ho5y) {
          App_Model_DW.Timer_AmberINDBlk2_hgzx = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void App_Tick_Timer_AmberINDBlk_bgbj(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_AmberIND_jx2y) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_g0by == (sint32)event_Cancel_Timer_AmberIN_fgf5) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk_lrhp = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk_lrhp + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk_lrhp + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk_lrhp = (uint16)tmp;
        if (App_Model_DW.sfEvent_g0by == (sint32)event_Start_Timer_AmberIND_jx2y) {
          App_Model_DW.Timer_AmberINDBlk_lrhp = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void App_Function_LEDErrorBlink_jeob(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  switch (rtu_Main_InSig_htzs) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)App_Model_B.BlinkState_gx2f != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_f1ey >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkComplete;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
        App_Model_B.b_BlinkState_pir3 = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_f1ey >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkComplete;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
        App_Model_B.b_BlinkState_pir3 = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOn;
        App_Model_B.b_AmberINDCmd_a4kq = On;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.b_AmberINDCmd_a4kq = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev_dtts !=
                   App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_gx2f = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_f1ey = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_f1ey + 1));
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev_dtts !=
                    App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev_dtts !=
                    App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)App_Model_DW.WPC2IndCmdState_start_jjne == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_gx2f = BlinkOff;
        App_Model_B.b_AmberINDCmd_a4kq = On;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_dtts != App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOn;
        App_Model_B.b_AmberINDCmd_a4kq = On;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_dtts != App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_f1ey = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_f1ey + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)App_Model_B.BlinkState_gx2f != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_f1ey >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkComplete;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
        App_Model_B.b_BlinkState_pir3 = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_f1ey >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkComplete;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
        App_Model_B.b_BlinkState_pir3 = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOn;
        App_Model_B.b_AmberINDCmd_a4kq = On;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.b_AmberINDCmd_a4kq = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev_dtts !=
                   App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_gx2f = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_f1ey = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_f1ey + 1));
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_gx2f == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev_dtts !=
                    App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev_dtts !=
                    App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)App_Model_DW.WPC2IndCmdState_start_jjne == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_gx2f = BlinkOff;
        App_Model_B.b_AmberINDCmd_a4kq = On;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_dtts != App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOn;
        App_Model_B.b_AmberINDCmd_a4kq = On;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_dtts != App_Model_DW.WPC2IndCmdState_start_jjne) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_dtts == WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_gx2f = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_f1ey = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_f1ey + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        t_previousEvent = App_Model_DW.sfEvent_g0by;
        App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        App_Model_DW.sfEvent_g0by = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void exit_internal_WPCMode_Run_a4zn(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Run_gdr3 == App_Mod_IN_WPCRun_FODError_hm2b) {
    sint32 b_previousEvent;
    App_Model_B.BlinkState_gx2f = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
    b_previousEvent = App_Model_DW.sfEvent_g0by;
    App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
      App_Tick_Timer_AmberINDBlk_bgbj();
    }

    App_Model_DW.sfEvent_g0by = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.b_BlinkState_pir3 = Off;
    App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void App_Model_WPCMode_Run_cecy(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, Bool rtu_Main_InSig_gcjy, DeviceState rtu_Main_InSig_pg4m, WPCIndUSMState
  rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  /* Outputs for IfAction SubSystem: '<S220>/nonNFC_ICE' incorporates:
   *  ActionPort: '<S402>/ActionPort'
   */
  /* SwitchCase: '<S220>/Switch Case1' incorporates:
   *  Chart: '<S402>/WPC2_MainControl2_250507'
   */
  /* 1. */
  if (((uint32)rtu_Main_InSig == On) || ((uint32)rtu_Main_InSig_gmt2 == On) || ((uint32)rtu_Main_InSig_b5rk == On) || ((uint32)rtu_Main_InSig_gcjy == On)) {
    exit_internal_WPCMode_Run_a4zn();
    App_Model_DW.is_WPCMode_Enable_nczh = App_Model_IN_WPCMode_Stop_aynr;
    App_Model_B.b_FANModeCmd_evyn = Off;
    App_Model_B.b_GreenINDCmd_otki = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_ith1 = Off;

    /* 1. */
    if ((uint32)rtu_Main_InSig_gcjy == On) {
      App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_WPCStop_TempErr_n0yp;
      App_Model_B.C_WPCWarning_bs3s = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      App_Model_B.BlinkState_gx2f = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
      App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

      /*  Non GFS  */
      App_Model_B.b_BlinkState_pir3 = On;
    } else {
      App_Model_DW.is_WPCMode_Stop_n5gl = App__IN_WPCStop_NotTempErr_ccgp;
      App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_B.b_AmberINDCmd_a4kq = Off;
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Run_gdr3) {
     case App_Mod_IN_WPCRun_Charging_aref:
      App_Model_B.b_FANModeCmd_evyn = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
        App_Model_DW.is_WPCMode_Run_gdr3 = App_Mode_IN_WPCRun_Standby_mdky;
        App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_evyn = Off;
        App_Model_B.b_GreenINDCmd_otki = Off;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_pg4m) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_FODError_hm2b;
          App_Model_B.C_WPCWarning_bs3s = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.BlinkState_gx2f = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
          App_Model_B.b_FANModeCmd_evyn = Off;
          App_Model_B.b_GreenINDCmd_otki = Off;
          App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

          /*  Non GFS  */
          App_Model_B.b_BlinkState_pir3 = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_gdr3 = IN_WPCRun_ChargingComplete_jydm;
          App_Model_B.C_WPCWarning_bs3s = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.b_GreenINDCmd_otki = On;
          App_Model_B.b_AmberINDCmd_a4kq = Off;
          break;

         default:
          Function_ChargingINDColor_nkrs(rtu_Main_InSig_nwkh);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_jydm:
      App_Model_B.b_FANModeCmd_evyn = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
        App_Model_DW.is_WPCMode_Run_gdr3 = App_Mode_IN_WPCRun_Standby_mdky;
        App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_evyn = Off;
        App_Model_B.b_GreenINDCmd_otki = Off;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_pg4m) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_FODError_hm2b;
          App_Model_B.C_WPCWarning_bs3s = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.BlinkState_gx2f = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
          App_Model_B.b_FANModeCmd_evyn = Off;
          App_Model_B.b_GreenINDCmd_otki = Off;
          App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

          /*  Non GFS  */
          App_Model_B.b_BlinkState_pir3 = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_Charging_aref;
          App_Model_B.C_WPCWarning_bs3s = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          Function_ChargingINDColor_nkrs(rtu_Main_InSig_nwkh);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_hm2b:
      {
        App_Model_B.b_FANModeCmd_evyn = Off;

        /* 1. */
        if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
          sint32 c_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          App_Model_B.BlinkState_gx2f = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
          c_previousEvent = App_Model_DW.sfEvent_g0by;
          App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
            App_Tick_Timer_AmberINDBlk_bgbj();
          }

          App_Model_DW.sfEvent_g0by = c_previousEvent;

          /*  Non GFS  */
          App_Model_B.b_BlinkState_pir3 = Off;
          App_Model_DW.is_WPCMode_Run_gdr3 = App_Mode_IN_WPCRun_Standby_mdky;
          App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          App_Model_B.b_GreenINDCmd_otki = Off;
          App_Model_B.b_AmberINDCmd_a4kq = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_pg4m) {
           case Charging:
            {
              sint32 c_previousEvent;

              /* BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.BlinkState_gx2f = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
              c_previousEvent = App_Model_DW.sfEvent_g0by;
              App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
                App_Tick_Timer_AmberINDBlk_bgbj();
              }

              App_Model_DW.sfEvent_g0by = c_previousEvent;

              /*  Non GFS  */
              App_Model_B.b_BlinkState_pir3 = Off;
              App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_Charging_aref;
              App_Model_B.C_WPCWarning_bs3s = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_evyn = On;
              Function_ChargingINDColor_nkrs(rtu_Main_InSig_nwkh);
            }
            break;

           case Full_Charge:
            {
              sint32 c_previousEvent;

              /* 3. */
              /* BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.BlinkState_gx2f = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
              c_previousEvent = App_Model_DW.sfEvent_g0by;
              App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
                App_Tick_Timer_AmberINDBlk_bgbj();
              }

              App_Model_DW.sfEvent_g0by = c_previousEvent;

              /*  Non GFS  */
              App_Model_B.b_BlinkState_pir3 = Off;
              App_Model_DW.is_WPCMode_Run_gdr3 = IN_WPCRun_ChargingComplete_jydm;
              App_Model_B.C_WPCWarning_bs3s = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_evyn = On;
              App_Model_B.b_GreenINDCmd_otki = On;
              App_Model_B.b_AmberINDCmd_a4kq = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_mdky:
      App_Model_B.b_FANModeCmd_evyn = Off;

      /* 1. */
      switch (rtu_Main_InSig_pg4m) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_FODError_hm2b;
        App_Model_B.C_WPCWarning_bs3s = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        App_Model_B.BlinkState_gx2f = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
        App_Model_B.b_GreenINDCmd_otki = Off;
        App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

        /*  Non GFS  */
        App_Model_B.b_BlinkState_pir3 = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_Charging_aref;
        App_Model_B.C_WPCWarning_bs3s = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_evyn = On;
        Function_ChargingINDColor_nkrs(rtu_Main_InSig_nwkh);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run_gdr3 = IN_WPCRun_ChargingComplete_jydm;
        App_Model_B.C_WPCWarning_bs3s = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_evyn = On;
        App_Model_B.b_GreenINDCmd_otki = On;
        App_Model_B.b_AmberINDCmd_a4kq = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  /* End of SwitchCase: '<S220>/Switch Case1' */
  /* End of Outputs for SubSystem: '<S220>/nonNFC_ICE' */
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void exit_internal_WPCMode_Stop_kaxj(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Stop_n5gl == App_Mod_IN_WPCStop_TempErr_n0yp) {
    sint32 b_previousEvent;
    App_Model_B.BlinkState_gx2f = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
    b_previousEvent = App_Model_DW.sfEvent_g0by;
    App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
      App_Tick_Timer_AmberINDBlk_bgbj();
    }

    App_Model_DW.sfEvent_g0by = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.b_BlinkState_pir3 = Off;
    App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_atomic_WPCMode_Disab_iqu4(void)
{
  sint32 b_previousEvent;
  App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
  App_Model_B.BlinkState_gx2f = BlinkOff;
  App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
  App_Model_DW.b_WarnClearEnable_lyus = Off;
  App_Model_B.b_FANModeCmd_evyn = Off;
  App_Model_B.b_GreenINDCmd_otki = Off;
  App_Model_B.b_AmberINDCmd_a4kq = Off;
  App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
  b_previousEvent = App_Model_DW.sfEvent_g0by;
  App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
    App_Tick_Timer_AmberINDBlk_bgbj();
  }

  App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneLe_ftby;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_g4qp != 0U) {
    App_M_Tick_Timer_PhoneLeft_mgtt();
  }

  App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneWa_hotu;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
    Tick_Timer_PhoneWarningChe_cc3i();
  }

  App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
    Tick_Timer_PhoneReminderCh_dizt();
  }

  App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_Warning_niui;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_hwpi != 0U) {
    Tick_Timer_WarningComplete_nw2l();
  }

  App_Model_DW.sfEvent_g0by = b_previousEvent;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__mysx(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft_oo5f = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneLeft_g0qt = 0U;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__poh4(void)
{
  App_Model_DW.is_Tick_Timer_PhoneWarning_m4i5 = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneWarningCheck_dcqd = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_bml0 = 0U;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__mz1h(void)
{
  App_Model_DW.is_Tick_Timer_PhoneReminde_davg = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneReminderCheck_gd2r = 0U;
  App_Model_B.b_Timer_PhoneReminderCheck_btkg = 0U;
  App_Model_DW.b_Timer_PhoneReminderCheck_fpiw = Off;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__nbtx(void)
{
  App_Model_DW.is_Tick_Timer_WarningCompl_d0pq = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_WarningComplete_inev = 0U;
  App_Model_B.b_Timer_WarningComplete_oufu = 0U;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__kdnl(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk_lrhp = 0U;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__hqxq(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk2_hgzx = 0U;
}

/* Function for Chart: '<S402>/WPC2_MainControl2_250507' */
static void enter_internal_Tick_Timer__fi5q(void)
{
  App_Model_DW.is_Tick_Timer_PhnLeftChatt_eous = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhnLeftChattering_jk53 = 0U;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void Function_ChargingINDColor_hytd(WPCIndUSMState rtu_Main_InSig_nwkh)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) {
    App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = On;
    App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
  } else {
    App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void Ap_Tick_Timer_AmberINDBlk2_ecjj(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_AmberIND_h1p5) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cpiu == (sint32)event_Cancel_Timer_AmberIN_eo3b) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk2_mfn5 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk2_mfn5 + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk2_mfn5 + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2_mfn5 = (uint16)tmp;
        if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_AmberIND_h1p5) {
          App_Model_DW.Timer_AmberINDBlk2_mfn5 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void App_Tick_Timer_AmberINDBlk_czhp(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_AmberIND_a1uc) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cpiu == (sint32)event_Cancel_Timer_AmberIN_fgf5) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk_hwlh = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk_hwlh + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk_hwlh + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk_hwlh = (uint16)tmp;
        if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_AmberIND_a1uc) {
          App_Model_DW.Timer_AmberINDBlk_hwlh = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void App_Function_LEDErrorBlink_clzh(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  switch (rtu_Main_InSig_htzs) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)App_Model_B.Output_BlinkState_kepa != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_poku >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_poku >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev_eusn !=
                   App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_kepa = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_poku = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_poku + 1));
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev_eusn !=
                    App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev_eusn !=
                    App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)App_Model_DW.WPC2IndCmdState_start_nyja == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_kepa = BlinkOff;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_eusn != App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_eusn != App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_poku = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_poku + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)App_Model_B.Output_BlinkState_kepa != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_poku >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_poku >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev_eusn !=
                   App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_kepa = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_poku = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_poku + 1));
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_kepa == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev_eusn !=
                    App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev_eusn !=
                    App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)App_Model_DW.WPC2IndCmdState_start_nyja == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_kepa = BlinkOff;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_eusn != App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = On;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_eusn != App_Model_DW.WPC2IndCmdState_start_nyja) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_eusn == WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_kepa = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_poku = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_poku + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        t_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }

        App_Model_DW.sfEvent_cpiu = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void exit_internal_WPCMode_Run_aiin(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Run_nncw == App_Mod_IN_WPCRun_FODError_hm2b) {
    sint32 b_previousEvent;
    App_Model_B.Output_BlinkState_kepa = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_poku = 0U;
    b_previousEvent = App_Model_DW.sfEvent_cpiu;
    App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
      App_Tick_Timer_AmberINDBlk_czhp();
    }

    App_Model_DW.sfEvent_cpiu = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
    App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void Tick_Timer_WarningTypeChec_lutt(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningTypeC_e2pu) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_WarningT_nkmg) {
      App_Model_DW.is_Tick_Timer_WarningTypeC_e2pu = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cpiu == (sint32)event_Cancel_Timer_Warning_as5n) {
        App_Model_DW.is_Tick_Timer_WarningTypeC_e2pu = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_WarningTypeCheck_kf0i = 0U;
        App_Model_B.b_Timer_WarningTypeCheck_c4cy = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningTypeCheck_kf0i + 1;
        if (((sint32)App_Model_DW.Timer_WarningTypeCheck_kf0i + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningTypeCheck_kf0i = (uint16)tmp;
        App_Model_B.b_Timer_WarningTypeCheck_c4cy = App_Model_DW.Timer_WarningTypeCheck_kf0i;
        if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_WarningT_nkmg) {
          App_Model_DW.Timer_WarningTypeCheck_kf0i = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void App_M_Tick_Timer_PhoneLeft_c2km(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft_a0zn) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_PhoneLef_kbqs) {
      App_Model_DW.is_Tick_Timer_PhoneLeft_a0zn = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cpiu == (sint32)event_Cancel_Timer_PhoneLe_n1xi) {
        App_Model_DW.is_Tick_Timer_PhoneLeft_a0zn = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneLeft_ew4s = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneLeft_ew4s + 1;
        if (((sint32)App_Model_DW.Timer_PhoneLeft_ew4s + 1) > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft_ew4s = (uint8)tmp;
        if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_PhoneLef_kbqs) {
          App_Model_DW.Timer_PhoneLeft_ew4s = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void Tick_Timer_PhoneWarningChe_pom4(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarning_euwb) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_PhoneWar_lqk1) {
      App_Model_DW.is_Tick_Timer_PhoneWarning_euwb = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cpiu == (sint32)event_Cancel_Timer_PhoneWa_ataa) {
        App_Model_DW.is_Tick_Timer_PhoneWarning_euwb = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneWarningCheck_odnd = 0U;
        App_Model_B.b_Timer_PhoneWarningCheck_jt3z = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneWarningCheck_odnd + 1;
        if (((sint32)App_Model_DW.Timer_PhoneWarningCheck_odnd + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck_odnd = (uint16)tmp;
        App_Model_B.b_Timer_PhoneWarningCheck_jt3z = App_Model_DW.Timer_PhoneWarningCheck_odnd;
        if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_PhoneWar_lqk1) {
          App_Model_DW.Timer_PhoneWarningCheck_odnd = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void Tick_Timer_WarningComplete_bggd(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningCompl_nhqc) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_WarningC_fils) {
      App_Model_DW.is_Tick_Timer_WarningCompl_nhqc = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cpiu == (sint32)event_Cancel_Timer_Warning_dez2) {
        App_Model_DW.is_Tick_Timer_WarningCompl_nhqc = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_WarningComplete_lffg = 0U;
        App_Model_B.b_Timer_WarningComplete_n0c3 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningComplete_lffg + 1;
        if (((sint32)App_Model_DW.Timer_WarningComplete_lffg + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete_lffg = (uint16)tmp;
        App_Model_B.b_Timer_WarningComplete_n0c3 = App_Model_DW.Timer_WarningComplete_lffg;
        if (App_Model_DW.sfEvent_cpiu == (sint32)event_Start_Timer_WarningC_fils) {
          App_Model_DW.Timer_WarningComplete_lffg = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void App_Mo_Function_WPCWarning_hcv4(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21)
{
  /*  WPC 모드가 해제 or 폰 감지가 안되었을 경우 or 출력 후 폰 가져간 경우900ms */
  if (((uint32)rtu_Main_InSig_e0fo == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck_odnd >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == Off)) ||
      (App_Model_DW.Timer_PhoneLeft_ew4s >= ((uint8)50U))) {
    sint32 c_previousEvent;

    /* 500m */
    /*  Warning OffNidec */
    App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

    /* Output_WPCWarning = SavedPreWPCMode%Nidec */
    App_Model_DW.b_WarnClearEnable_f4qc = Off;

    /* Nidec충전가능 */
    App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
    c_previousEvent = App_Model_DW.sfEvent_cpiu;
    App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
      App_M_Tick_Timer_PhoneLeft_c2km();
    }

    App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneWa_ataa;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
      Tick_Timer_PhoneWarningChe_pom4();
    }

    App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_dez2;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
      Tick_Timer_WarningComplete_bggd();
    }

    App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_as5n;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
      Tick_Timer_WarningTypeChec_lutt();
    }

    App_Model_DW.sfEvent_cpiu = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /*  방치 알림 신호 출력 후, 휴대폰을 가져가는 경우 */
    if (((uint32)App_Model_DW.b_WarnClearEnable_f4qc == On) && ((App_Model_DW.Input_OPT_b_WPCPhoneExist__asus != App_Model_DW.Input_OPT_b_WPCPhoneExist__igwe) && ((uint32)
          App_Model_DW.Input_OPT_b_WPCPhoneExist__igwe == Off))) {
      /*  폰 비거치 시간 측정 타이머 시작 */
      c_previousEvent = App_Model_DW.sfEvent_cpiu;
      App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_PhoneLef_kbqs;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
        App_M_Tick_Timer_PhoneLeft_c2km();
      }

      App_Model_DW.sfEvent_cpiu = c_previousEvent;

      /*  방치알림 신호 출력 후, 폰 비거치 상태-> 다시 폰 거치 확인한 경우 */
    } else if (((uint32)App_Model_DW.is_Tick_Timer_PhoneLeft_a0zn == App_Model_IN_On_pbff) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      /*  폰 비거치 시간 측정 타이머 취소 */
      c_previousEvent = App_Model_DW.sfEvent_cpiu;
      App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
        App_M_Tick_Timer_PhoneLeft_c2km();
      }

      App_Model_DW.sfEvent_cpiu = c_previousEvent;
    } else {
      /* no actions */
    }

    /*  폰 경고 확인 조건 판단 */
    if ((uint32)App_Model_DW.PhoneLeftWrnType_elrn == PhoneLeftWrnType__Default) {
      if (App_Model_DW.Timer_WarningTypeCheck_kf0i < ((uint16)6000U)) {
        /* 60s */
        if ((uint32)rtu_Main_InSig_nv40 == On) {
          /*  60초 이내에 DoorOpen 이벤트 발생할 경우,
             경고타입 (1sec Delay 후 6sec 간 경고 출력 발생) 설정 */
          App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__LongDuration;

          /* Nidec 60초이전 이벤트는 충전금지필요%WPCMode가 아닐 때는 상시 On이므로 WPCMode일 때를 위한 조건 */
          App_Model_B.b_PhnLeftChk_Enable_hhyt = On;

          /* HMC사양에 폰충전불가 주석원복함. */
          c_previousEvent = App_Model_DW.sfEvent_cpiu;
          App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_as5n;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
            Tick_Timer_WarningTypeChec_lutt();
          }

          App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_PhoneWar_lqk1;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
            Tick_Timer_PhoneWarningChe_pom4();
          }

          App_Model_DW.sfEvent_cpiu = c_previousEvent;
        } else {
          /* WPCMode아닐 때 충전금지위해
             PhnLeftChck_Enable On유지 */
        }
      } else {
        /*  60초 간 Door Open 없을 시, 경고 타입(즉시 500ms 경고 출력 발생) 설정 */
        App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__ShortDuration;

        /* b_PhnLeftChk_Enable = On%Nidec%60초 이후 영향으로 불필요 */
        c_previousEvent = App_Model_DW.sfEvent_cpiu;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_as5n;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
          Tick_Timer_WarningTypeChec_lutt();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_PhoneWar_lqk1;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
          Tick_Timer_PhoneWarningChe_pom4();
        }

        App_Model_DW.sfEvent_cpiu = c_previousEvent;
      }
    }

    /*  폰 경고 확인 시간 중 폰 감지됨100ms900ms */
    if ((App_Model_DW.Timer_PhoneWarningCheck_odnd >= (uint16)((uint8)10U)) && (App_Model_DW.Timer_PhoneWarningCheck_odnd <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      /* Output_WPCWarning = Cellphoneonthepad%NFCModeControl연동시그널. IG On중에는 미적용 */
      c_previousEvent = App_Model_DW.sfEvent_cpiu;
      App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneWa_ataa;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
        Tick_Timer_PhoneWarningChe_pom4();
      }

      App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningC_fils;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
        Tick_Timer_WarningComplete_bggd();
      }

      App_Model_DW.sfEvent_cpiu = c_previousEvent;
    }

    /*  경고 알림 출력
       [(PhoneLeftWrnType == PhoneLeftWrnType__LongDuration&&Timer_WarningComplete >= Par_WarningDelayTime &&...0s
       Timer_WarningComplete <= Par_WarningTime__LongDuration+Par_WarningDelayTime) ||...6s+0s %%DelayDelete_Nidec6s */
    if ((((uint32)App_Model_DW.PhoneLeftWrnType_elrn == PhoneLeftWrnType__LongDuration) && ((uint32)App_Model_DW.is_Tick_Timer_WarningCompl_nhqc == App_Model_IN_On_pbff) &&
         (App_Model_DW.Timer_WarningComplete_lffg <= ((uint16)600U))) || (((uint32)App_Model_DW.PhoneLeftWrnType_elrn == PhoneLeftWrnType__ShortDuration) && ((uint32)
          App_Model_DW.is_Tick_Timer_WarningCompl_nhqc == App_Model_IN_On_pbff) && (App_Model_DW.Timer_WarningComplete_lffg <= ((uint16)50U)))) {
      /* 500m */
      App_Model_B.Output_WPCWarning_pw1g = Cellphonereminder;
      App_Model_DW.b_WarnClearEnable_f4qc = On;

      /*  경고 알림 출력 해제 조건 */
    } else if ((((uint32)App_Model_DW.PhoneLeftWrnType_elrn == PhoneLeftWrnType__LongDuration) && (App_Model_DW.Timer_WarningComplete_lffg > (((uint16)600U) + ((uint16)0U)))) || (((uint32)
                 App_Model_DW.PhoneLeftWrnType_elrn == PhoneLeftWrnType__ShortDuration) && (App_Model_DW.Timer_WarningComplete_lffg > ((uint16)50U)))) {
      /* Nidec */
      App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

      /* Output_WPCWarning = SavedPreWPCMode%NidecNidec 필요250219 */
      App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;

      /* HMC사양에 폰충전불가 주석원복함. */
      c_previousEvent = App_Model_DW.sfEvent_cpiu;
      App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_dez2;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
        Tick_Timer_WarningComplete_bggd();
      }

      App_Model_DW.sfEvent_cpiu = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void App_Model_WPCMode_Run_indc(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta rtu_Main_InSig_jgrv)
{
  Bool tmp;
  tmp = App_Model_DW.b_DrvDrSw_start_e0qz;
  if (((App_Model_DW.Input_OPT_GearPosSta_prev_bpse != App_Model_DW.Input_OPT_GearPosSta_start_djgk) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start_djgk == GearPos_P) && ((uint32)
        rtu_Main_InSig_nv40 == On)) || ((App_Model_DW.b_DrvDrSw_prev_ii3v != tmp) && ((uint32)tmp == On) && ((uint32)rtu_Main_InSig_jgrv == GearPos_P))) {
    sint32 d_previousEvent;

    /* Nidec */
    exit_internal_WPCMode_Run_aiin();
    App_Model_DW.is_WPCMode_Enable_l4ui = IN_LeavingPhone_Warning_In_arkq;
    App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
    App_Model_DW.b_WarnClearEnable_f4qc = Off;
    App_Model_B.b_ChargingEnable_iqlw = Off;
    d_previousEvent = App_Model_DW.sfEvent_cpiu;
    App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningT_nkmg;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
      Tick_Timer_WarningTypeChec_lutt();
    }

    App_Model_DW.sfEvent_cpiu = d_previousEvent;
    App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

    /* 1. */
  } else if (((uint32)rtu_Main_InSig == On) || ((uint32)rtu_Main_InSig_gmt2 == On) || ((uint32)rtu_Main_InSig_b5rk == On) || ((uint32)rtu_Main_InSig_gcjy == On)) {
    /*  ||b_CardProtection == On ]...CardDetect_Nidec */
    exit_internal_WPCMode_Run_aiin();
    App_Model_DW.is_WPCMode_Enable_l4ui = App_Model_IN_WPCMode_Stop_ihz1;
    App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_iqlw = Off;

    /* 1. */
    if ((uint32)rtu_Main_InSig_gcjy == On) {
      App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_WPCStop_TempErr_n0yp;
      App_Model_B.Output_WPCWarning_pw1g = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      App_Model_B.Output_BlinkState_kepa = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_poku = 0U;
      App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

      /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
      App_Model_B.Output_OPT_b_BlinkState_nxwe = On;
    } else {
      App_Model_DW.is_WPCMode_Stop_lqw5 = App__IN_WPCStop_NotTempErr_ccgp;
      App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Run_nncw) {
     case App_Mod_IN_WPCRun_Charging_aref:
      App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
        App_Model_DW.is_WPCMode_Run_nncw = App_Mode_IN_WPCRun_Standby_mdky;
        App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_pg4m) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_FODError_hm2b;
          App_Model_B.Output_WPCWarning_pw1g = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.Output_BlinkState_kepa = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_poku = 0U;
          App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
          App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_nxwe = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_nncw = IN_WPCRun_ChargingComplete_jydm;
          App_Model_B.Output_WPCWarning_pw1g = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = On;
          App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
          break;

         default:
          Function_ChargingINDColor_hytd(rtu_Main_InSig_nwkh);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_jydm:
      App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
        App_Model_DW.is_WPCMode_Run_nncw = App_Mode_IN_WPCRun_Standby_mdky;
        App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_pg4m) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_FODError_hm2b;
          App_Model_B.Output_WPCWarning_pw1g = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.Output_BlinkState_kepa = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_poku = 0U;
          App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
          App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_nxwe = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_Charging_aref;
          App_Model_B.Output_WPCWarning_pw1g = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          Function_ChargingINDColor_hytd(rtu_Main_InSig_nwkh);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_hm2b:
      {
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;

        /* 1. */
        if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
          sint32 d_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          App_Model_B.Output_BlinkState_kepa = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_poku = 0U;
          d_previousEvent = App_Model_DW.sfEvent_cpiu;
          App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
            App_Tick_Timer_AmberINDBlk_czhp();
          }

          App_Model_DW.sfEvent_cpiu = d_previousEvent;

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
          App_Model_DW.is_WPCMode_Run_nncw = App_Mode_IN_WPCRun_Standby_mdky;
          App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
          App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_pg4m) {
           case Charging:
            {
              sint32 d_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.Output_BlinkState_kepa = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_poku = 0U;
              d_previousEvent = App_Model_DW.sfEvent_cpiu;
              App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
                App_Tick_Timer_AmberINDBlk_czhp();
              }

              App_Model_DW.sfEvent_cpiu = d_previousEvent;

              /*  Non GFS  */
              App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
              App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_Charging_aref;
              App_Model_B.Output_WPCWarning_pw1g = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;
              Function_ChargingINDColor_hytd(rtu_Main_InSig_nwkh);
            }
            break;

           case Full_Charge:
            {
              sint32 d_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.Output_BlinkState_kepa = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_poku = 0U;
              d_previousEvent = App_Model_DW.sfEvent_cpiu;
              App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
                App_Tick_Timer_AmberINDBlk_czhp();
              }

              App_Model_DW.sfEvent_cpiu = d_previousEvent;

              /*  Non GFS  */
              App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
              App_Model_DW.is_WPCMode_Run_nncw = IN_WPCRun_ChargingComplete_jydm;
              App_Model_B.Output_WPCWarning_pw1g = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;
              App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = On;
              App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_mdky:
      App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;

      /* 1. */
      switch (rtu_Main_InSig_pg4m) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_FODError_hm2b;
        App_Model_B.Output_WPCWarning_pw1g = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        App_Model_B.Output_BlinkState_kepa = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_poku = 0U;
        App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
        App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

        /*  Non GFS  */
        App_Model_B.Output_OPT_b_BlinkState_nxwe = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_Charging_aref;
        App_Model_B.Output_WPCWarning_pw1g = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;
        Function_ChargingINDColor_hytd(rtu_Main_InSig_nwkh);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run_nncw = IN_WPCRun_ChargingComplete_jydm;
        App_Model_B.Output_WPCWarning_pw1g = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;
        App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = On;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void exit_internal_WPCMode_Stop_hr24(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Stop_lqw5 == App_Mod_IN_WPCStop_TempErr_n0yp) {
    sint32 b_previousEvent;

    /* Function_NFCCardDetection() 8차 적용 삭제 */
    App_Model_B.Output_BlinkState_kepa = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_poku = 0U;
    b_previousEvent = App_Model_DW.sfEvent_cpiu;
    App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
      App_Tick_Timer_AmberINDBlk_czhp();
    }

    App_Model_DW.sfEvent_cpiu = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
    App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_atomic_WPCMode_Disab_emnh(void)
{
  sint32 b_previousEvent;
  App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
  App_Model_B.Output_BlinkState_kepa = BlinkOff;
  App_Model_DW.Counter_BlinkCnt_poku = 0U;

  /* b_ChargingEnable = Off 8차 적용 삭제 */
  App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
  App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
  b_previousEvent = App_Model_DW.sfEvent_cpiu;
  App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
    App_Tick_Timer_AmberINDBlk_czhp();
  }

  App_Model_DW.sfEvent_cpiu = b_previousEvent;

  /* Nidec */
  App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_WPCMode_Off_mwtd(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, GearPosSta rtu_Main_InSig_jgrv)
{
  /* [hasChangedTo(Input_OPT_GearPosSta,GearPos_P)] */
  if ((uint32)rtu_Main_InSig_jgrv == GearPos_P) {
    sint32 b_previousEvent;

    /* Nidec */
    App_Model_DW.is_WPCMode_Off_mguh = Ap_IN_LeavingPhone_Warning_ji1s;
    App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
    App_Model_DW.b_WarnClearEnable_f4qc = Off;
    b_previousEvent = App_Model_DW.sfEvent_cpiu;
    App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningT_nkmg;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
      Tick_Timer_WarningTypeChec_lutt();
    }

    App_Model_DW.sfEvent_cpiu = b_previousEvent;
    App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

    /* Nidec */
    App_Model_B.b_PhnLeftChk_Enable_hhyt = On;
  } else {
    App_Model_DW.is_WPCMode_Off_mguh = IN_LeavingPhone_NoWarning_dyop;
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void A_enter_atomic_WPCMode_NFC_exg2(void)
{
  sint32 b_previousEvent;
  App_Model_DW.b_WarnClearEnable_f4qc = Off;
  b_previousEvent = App_Model_DW.sfEvent_cpiu;
  App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
    App_M_Tick_Timer_PhoneLeft_c2km();
  }

  App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneWa_ataa;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
    Tick_Timer_PhoneWarningChe_pom4();
  }

  App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_dez2;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
    Tick_Timer_WarningComplete_bggd();
  }

  App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_as5n;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
    Tick_Timer_WarningTypeChec_lutt();
  }

  App_Model_DW.sfEvent_cpiu = b_previousEvent;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void App_Model_WPCMode_Enable_kr2m(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta
  rtu_Main_InSig_jgrv)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_pov1 != WPCMode) {
    switch (App_Model_DW.is_WPCMode_Enable_l4ui) {
     case IN_LeavingPhone_Warning_In_arkq:
      /* Nidec */
      App_Model_DW.is_WPCMode_Enable_l4ui = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     case App_Model_IN_WPCMode_Run_acpk:
      exit_internal_WPCMode_Run_aiin();
      App_Model_DW.is_WPCMode_Enable_l4ui = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     case App_Model_IN_WPCMode_Stop_ihz1:
      exit_internal_WPCMode_Stop_hr24();
      App_Model_DW.is_WPCMode_Enable_l4ui = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     default:
      /* no actions */
      break;
    }

    /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_iqlw = Off;
    App_Model_DW.is_MainControl_aanr = App_Mod_IN_WPCMode_Disable_cyvt;
    enter_atomic_WPCMode_Disab_emnh();

    /* 1. */
    if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
      App_Model_DW.is_WPCMode_Disable_keqj = App_Model_IN_WPCMode_NFC_eleo;
      A_enter_atomic_WPCMode_NFC_exg2();
    } else {
      App_Model_DW.is_WPCMode_Disable_keqj = App_Model_IN_WPCMode_Off_nufv;

      /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
       *  ActionPort: '<S401>/ActionPort'
       */
      /* SwitchCase: '<S220>/Switch Case1' incorporates:
       *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
       */
      enter_internal_WPCMode_Off_mwtd(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_jgrv);

      /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Enable_l4ui) {
     case IN_LeavingPhone_Warning_In_arkq:
      {
        Bool tmp_0;
        GearPosSta tmp;
        tmp = App_Model_DW.Input_OPT_GearPosSta_prev_bpse;
        tmp_0 = App_Model_DW.b_DrvDrSw_start_e0qz;
        if (((tmp != App_Model_DW.Input_OPT_GearPosSta_start_djgk) && ((uint32)tmp == GearPos_P)) || ((App_Model_DW.b_DrvDrSw_prev_ii3v != tmp_0) && ((uint32)tmp_0 == Off))) {
          /* Nidec DoorClose */
          /* Nidec */
          App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
          App_Model_DW.is_WPCMode_Enable_l4ui = App_Model_IN_WPCMode_Stop_ihz1;
          App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;

          /* b_ROHMOperCmd = Off /_ Non GFS _/ */
          App_Model_B.b_ChargingEnable_iqlw = Off;

          /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
           *  ActionPort: '<S401>/ActionPort'
           */
          /* SwitchCase: '<S220>/Switch Case1' incorporates:
           *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
           */
          /* 1. */
          if ((uint32)rtu_Main_InSig_gcjy == On) {
            App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_WPCStop_TempErr_n0yp;
            App_Model_B.Output_WPCWarning_pw1g = Charging_error;

            /* b_WPCWarn = Charging_error 8차 LFRollBack */
            App_Model_B.Output_BlinkState_kepa = BlinkOff;
            App_Model_DW.Counter_BlinkCnt_poku = 0U;
            App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

            /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
            App_Model_B.Output_OPT_b_BlinkState_nxwe = On;
          } else {
            App_Model_DW.is_WPCMode_Stop_lqw5 = App__IN_WPCStop_NotTempErr_ccgp;
            App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

            /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
            App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
          }

          /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
        } else if ((tmp != App_Model_DW.Input_OPT_GearPosSta_start_djgk) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start_djgk == GearPos_P)) {
          sint32 b_previousEvent;

          /* Nidec */
          App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
          App_Model_DW.is_WPCMode_Enable_l4ui = IN_LeavingPhone_Warning_In_arkq;
          App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
          App_Model_DW.b_WarnClearEnable_f4qc = Off;
          App_Model_B.b_ChargingEnable_iqlw = Off;
          b_previousEvent = App_Model_DW.sfEvent_cpiu;
          App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningT_nkmg;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
            Tick_Timer_WarningTypeChec_lutt();
          }

          App_Model_DW.sfEvent_cpiu = b_previousEvent;

          /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
           *  ActionPort: '<S401>/ActionPort'
           */
          /* SwitchCase: '<S220>/Switch Case1' incorporates:
           *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
           */
          App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

          /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
        } else {
          /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
           *  ActionPort: '<S401>/ActionPort'
           */
          /* SwitchCase: '<S220>/Switch Case1' incorporates:
           *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
           */
          /* b_PhnLeftChk_Enable = On%Nidec%충전상태를 조건에따라 판단하기위해 주석처리 */
          App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

          /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
        }
      }
      break;

     case App_Model_IN_WPCMode_Run_acpk:
      /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
       *  ActionPort: '<S401>/ActionPort'
       */
      /* SwitchCase: '<S220>/Switch Case1' incorporates:
       *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
       */
      App_Model_WPCMode_Run_indc(rtu_Main_InSig, rtu_Main_InSig_gmt2, rtu_Main_InSig_b5rk, rtu_Main_InSig_e0fo, rtu_Main_InSig_gcjy, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_pg4m,
        rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs, rtu_Main_InSig_jgrv);

      /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
      break;

     case App_Model_IN_WPCMode_Stop_ihz1:
      {
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;

        /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
         *  ActionPort: '<S401>/ActionPort'
         */
        /* SwitchCase: '<S220>/Switch Case1' incorporates:
         *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
         */
        if (((uint32)rtu_Main_InSig_pg4m == Full_Charge) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
             rtu_Main_InSig_b5rk == Off)) {
          /*  &&b_CardProtection == Off]%CardDetect_Nidec]
             Input_PhoneLeftWarningWPCStatus == Off]
             b_ChargingEnable == On 8차 적용 삭제 */
          exit_internal_WPCMode_Stop_hr24();
          App_Model_DW.is_WPCMode_Enable_l4ui = App_Model_IN_WPCMode_Run_acpk;
          App_Model_B.b_ChargingEnable_iqlw = On;
          App_Model_DW.is_WPCMode_Run_nncw = IN_WPCRun_ChargingComplete_jydm;
          App_Model_B.Output_WPCWarning_pw1g = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;
          App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = On;
          App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
        } else if (((uint32)rtu_Main_InSig_pg4m == Charging) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
                    rtu_Main_InSig_b5rk == Off)) {
          /* &&b_CardProtection == Off]%CardDetect_Nidec]
             Input_PhoneLeftWarningWPCStatus == Off]
             b_ChargingEnable == On 8차 적용 삭제 */
          exit_internal_WPCMode_Stop_hr24();
          App_Model_DW.is_WPCMode_Enable_l4ui = App_Model_IN_WPCMode_Run_acpk;
          App_Model_B.b_ChargingEnable_iqlw = On;
          App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_WPCRun_Charging_aref;
          App_Model_B.Output_WPCWarning_pw1g = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          App_Model_B.Output_OPT_b_FANModeCmd_ll4e = On;
          Function_ChargingINDColor_hytd(rtu_Main_InSig_nwkh);
        } else {
          GearPosSta tmp;
          tmp = App_Model_DW.Input_OPT_GearPosSta_start_djgk;
          if (((App_Model_DW.Input_OPT_GearPosSta_prev_bpse != tmp) && ((uint32)tmp == GearPos_P) && ((uint32)rtu_Main_InSig_nv40 == On)) || ((App_Model_DW.b_DrvDrSw_prev_ii3v !=
                App_Model_DW.b_DrvDrSw_start_e0qz) && ((uint32)App_Model_DW.b_DrvDrSw_start_e0qz == On) && ((uint32)rtu_Main_InSig_jgrv == GearPos_P))) {
            sint32 b_previousEvent;

            /* Nidec */
            exit_internal_WPCMode_Stop_hr24();
            App_Model_DW.is_WPCMode_Enable_l4ui = IN_LeavingPhone_Warning_In_arkq;
            App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
            App_Model_DW.b_WarnClearEnable_f4qc = Off;
            App_Model_B.b_ChargingEnable_iqlw = Off;
            b_previousEvent = App_Model_DW.sfEvent_cpiu;
            App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningT_nkmg;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
              Tick_Timer_WarningTypeChec_lutt();
            }

            App_Model_DW.sfEvent_cpiu = b_previousEvent;
            App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
          } else {
            switch (App_Model_DW.is_WPCMode_Stop_lqw5) {
             case App__IN_WPCStop_NotTempErr_ccgp:
              /* 1. */
              if ((uint32)rtu_Main_InSig_gcjy == On) {
                App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_WPCStop_TempErr_n0yp;
                App_Model_B.Output_WPCWarning_pw1g = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.Output_BlinkState_kepa = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_poku = 0U;
                App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

                /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
                App_Model_B.Output_OPT_b_BlinkState_nxwe = On;

                /* 2. */
              } else if (((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_b5rk == Off)) {
                /*  &&b_CardProtection == Off]%CardDetect_Nidec]
                   Input_PhoneLeftWarningWPCStatus == Off]
                   b_ChargingEnable == On 8차 적용 삭제 */
                App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                App_Model_DW.is_WPCMode_Enable_l4ui = App_Model_IN_WPCMode_Run_acpk;
                App_Model_B.b_ChargingEnable_iqlw = On;
                App_Model_DW.is_WPCMode_Run_nncw = App_Mode_IN_WPCRun_Standby_mdky;
                App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
                App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
              } else {
                /* Function_NFCCardDetection() 8차 적용 삭제
                   Function_NFCCardDetection() 8차 적용 삭제 */
              }
              break;

             case App_Mod_IN_WPCStop_TempErr_n0yp:
              {
                /* 1. */
                if ((uint32)rtu_Main_InSig_gcjy == Off) {
                  sint32 b_previousEvent;

                  /* Function_NFCCardDetection() 8차 적용 삭제 */
                  App_Model_B.Output_BlinkState_kepa = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt_poku = 0U;
                  b_previousEvent = App_Model_DW.sfEvent_cpiu;
                  App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
                    App_Tick_Timer_AmberINDBlk_czhp();
                  }

                  App_Model_DW.sfEvent_cpiu = b_previousEvent;

                  /*  Non GFS  */
                  App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;
                  App_Model_DW.is_WPCMode_Stop_lqw5 = App__IN_WPCStop_NotTempErr_ccgp;
                  App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
                } else {
                  App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
                }
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }

        /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_WPCMode_Ena_oryk(Bool rtu_Main_InSig_gcjy, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  App_Model_DW.is_WPCMode_Enable_l4ui = App_Model_IN_WPCMode_Stop_ihz1;
  App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;

  /* b_ROHMOperCmd = Off /_ Non GFS _/ */
  App_Model_B.b_ChargingEnable_iqlw = Off;

  /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
   *  ActionPort: '<S401>/ActionPort'
   */
  /* SwitchCase: '<S220>/Switch Case1' incorporates:
   *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
   */
  /* 1. */
  if ((uint32)rtu_Main_InSig_gcjy == On) {
    App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_WPCStop_TempErr_n0yp;
    App_Model_B.Output_WPCWarning_pw1g = Charging_error;

    /* b_WPCWarn = Charging_error 8차 LFRollBack */
    App_Model_B.Output_BlinkState_kepa = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_poku = 0U;
    App_Function_LEDErrorBlink_clzh(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

    /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_nxwe = On;
  } else {
    App_Model_DW.is_WPCMode_Stop_lqw5 = App__IN_WPCStop_NotTempErr_ccgp;
    App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
  }

  /* End of SwitchCase: '<S220>/Switch Case1' */
  /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__nlr0(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft_a0zn = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneLeft_ew4s = 0U;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__gq2v(void)
{
  App_Model_DW.is_Tick_Timer_PhoneWarning_euwb = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneWarningCheck_odnd = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_jt3z = 0U;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__dzgk(void)
{
  App_Model_DW.is_Tick_Timer_WarningCompl_nhqc = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_WarningComplete_lffg = 0U;
  App_Model_B.b_Timer_WarningComplete_n0c3 = 0U;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__o1rh(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk_hwlh = 0U;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__i2ff(void)
{
  App_Model_DW.is_Tick_Timer_WarningTypeC_e2pu = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_WarningTypeCheck_kf0i = 0U;
  App_Model_B.b_Timer_WarningTypeCheck_c4cy = 0U;
}

/* Function for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__cxi4(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk2_mfn5 = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void Function_ChargingINDColor_aroz(WPCIndUSMState rtu_Main_InSig_nwkh)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) {
    App_Model_B.b_GreenINDCmd_mwno = On;
    App_Model_B.b_AmberINDCmd_m25s = Off;
  } else {
    App_Model_B.b_GreenINDCmd_mwno = Off;
    App_Model_B.b_AmberINDCmd_m25s = On;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void Ap_Tick_Timer_AmberINDBlk2_iopl(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_AmberIND_ho5y) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_AmberIN_eo3b) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk2_oixi = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk2_oixi + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk2_oixi + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2_oixi = (uint16)tmp;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_AmberIND_ho5y) {
          App_Model_DW.Timer_AmberINDBlk2_oixi = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void App_Tick_Timer_AmberINDBlk_fqxk(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_AmberIND_jx2y) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1 = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_AmberIN_fgf5) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1 = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk_e3ak = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk_e3ak + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk_e3ak + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk_e3ak = (uint16)tmp;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_AmberIND_jx2y) {
          App_Model_DW.Timer_AmberINDBlk_e3ak = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void App_Function_LEDErrorBlink_ejqw(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  switch (rtu_Main_InSig_htzs) {
   case Off:
    {
      /* ForFODError%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)App_Model_B.BlinkState_izow != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_fhcr >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkComplete;
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
        App_Model_B.b_BlinkState_mtzh = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_fhcr >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkComplete;
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
        App_Model_B.b_BlinkState_mtzh = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOn;
        App_Model_B.b_AmberINDCmd_m25s = On;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1 ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.b_AmberINDCmd_m25s = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev_gzvs !=
                   App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_izow = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_fhcr = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_fhcr + 1));
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev_gzvs !=
                    App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev_gzvs !=
                    App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)App_Model_DW.WPC2IndCmdState_start_jkee == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_izow = BlinkOff;
        App_Model_B.b_AmberINDCmd_m25s = On;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_gzvs != App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOn;
        App_Model_B.b_AmberINDCmd_m25s = On;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_gzvs != App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_fhcr = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_fhcr + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* ForFODError%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)App_Model_B.BlinkState_izow != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_fhcr >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkComplete;
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
        App_Model_B.b_BlinkState_mtzh = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_fhcr >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkComplete;
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
        App_Model_B.b_BlinkState_mtzh = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOn;
        App_Model_B.b_AmberINDCmd_m25s = On;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1 ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.b_AmberINDCmd_m25s = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev_gzvs !=
                   App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_izow = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_fhcr = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_fhcr + 1));
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_izow == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev_gzvs !=
                    App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev_gzvs !=
                    App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)App_Model_DW.WPC2IndCmdState_start_jkee == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_izow = BlinkOff;
        App_Model_B.b_AmberINDCmd_m25s = On;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_jx2y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
          App_Tick_Timer_AmberINDBlk_fqxk();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_gzvs != App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOn;
        App_Model_B.b_AmberINDCmd_m25s = On;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev_gzvs != App_Model_DW.WPC2IndCmdState_start_jkee) && ((uint32)
                   App_Model_DW.WPC2IndCmdState_prev_gzvs == WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_izow = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_fhcr = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_fhcr + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.b_AmberINDCmd_m25s = Off;
        t_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_AmberIND_ho5y;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_iopl();
        }

        App_Model_DW.sfEvent_cbxk = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_WPCMode_Sto_h1gw(Bool rtu_Main_InSig_gcjy, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_gcjy == On) {
    App_Model_DW.is_WPCMode_Stop_a2vp = App_Mod_IN_WPCStop_TempErr_n0yp;

    /* 240926 */
    App_Model_B.b_ChargingEnable_ovqe = Off;
    App_Model_B.C_WPCWarning_d4ol = Charging_error;
    App_Model_B.BlinkState_izow = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
    App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

    /*  Non GFS  */
    App_Model_B.b_BlinkState_mtzh = On;
  } else {
    App_Model_DW.is_WPCMode_Stop_a2vp = App__IN_WPCStop_NotTempErr_ccgp;

    /* 240926 */
    App_Model_B.b_ChargingEnable_ovqe = Off;
    App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
    App_Model_B.b_AmberINDCmd_m25s = Off;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void exit_internal_WPCMode_Run_fhr1(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Run_b3iy == App_Mod_IN_WPCRun_FODError_hm2b) {
    sint32 b_previousEvent;
    App_Model_B.BlinkState_izow = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
    b_previousEvent = App_Model_DW.sfEvent_cbxk;
    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
      App_Tick_Timer_AmberINDBlk_fqxk();
    }

    App_Model_DW.sfEvent_cbxk = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.b_BlinkState_mtzh = Off;
    App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void exit_internal_WPCMode_Stop_dxd4(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Stop_a2vp == App_Mod_IN_WPCStop_TempErr_n0yp) {
    sint32 b_previousEvent;
    App_Model_B.BlinkState_izow = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
    b_previousEvent = App_Model_DW.sfEvent_cbxk;
    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
      App_Tick_Timer_AmberINDBlk_fqxk();
    }

    App_Model_DW.sfEvent_cbxk = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.b_BlinkState_mtzh = Off;
    App_Model_DW.is_WPCMode_Stop_a2vp = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Stop_a2vp = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_atomic_WPCMode_Disab_or5p(void)
{
  sint32 b_previousEvent;
  App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
  App_Model_B.BlinkState_izow = BlinkOff;
  App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
  App_Model_B.b_FANModeCmd_bint = Off;
  App_Model_B.b_GreenINDCmd_mwno = Off;
  App_Model_B.b_AmberINDCmd_m25s = Off;
  App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
  b_previousEvent = App_Model_DW.sfEvent_cbxk;
  App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
    App_Tick_Timer_AmberINDBlk_fqxk();
  }

  App_Model_DW.sfEvent_cbxk = b_previousEvent;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void App_M_Tick_Timer_PhoneLeft_jzcf(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft_gvmy) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_PhoneLef_j1qj) {
      App_Model_DW.is_Tick_Timer_PhoneLeft_gvmy = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_PhoneLe_ftby) {
        App_Model_DW.is_Tick_Timer_PhoneLeft_gvmy = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneLeft_g1mn = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneLeft_g1mn + 1;
        if (((sint32)App_Model_DW.Timer_PhoneLeft_g1mn + 1) > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft_g1mn = (uint8)tmp;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_PhoneLef_j1qj) {
          App_Model_DW.Timer_PhoneLeft_g1mn = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void Tick_Timer_PhoneWarningChe_lzxg(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarning_m43e) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_PhoneWar_n1mt) {
      App_Model_DW.is_Tick_Timer_PhoneWarning_m43e = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_PhoneWa_hotu) {
        App_Model_DW.is_Tick_Timer_PhoneWarning_m43e = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneWarningCheck_hqal = 0U;
        App_Model_B.b_Timer_PhoneWarningCheck_nhb3 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneWarningCheck_hqal + 1;
        if (((sint32)App_Model_DW.Timer_PhoneWarningCheck_hqal + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck_hqal = (uint16)tmp;
        App_Model_B.b_Timer_PhoneWarningCheck_nhb3 = App_Model_DW.Timer_PhoneWarningCheck_hqal;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_PhoneWar_n1mt) {
          App_Model_DW.Timer_PhoneWarningCheck_hqal = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void Tick_Timer_PhoneReminderCh_f2nt(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneReminde_iesd) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_PhoneRem_dsov) {
      App_Model_DW.is_Tick_Timer_PhoneReminde_iesd = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_PhoneRe_jjf3) {
        App_Model_DW.is_Tick_Timer_PhoneReminde_iesd = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneReminderCheck_ivxo = 0U;
        App_Model_B.b_Timer_PhoneReminderCheck_gvtz = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneReminderCheck_ivxo + 1;
        if (((sint32)App_Model_DW.Timer_PhoneReminderCheck_ivxo + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneReminderCheck_ivxo = (uint16)tmp;
        App_Model_B.b_Timer_PhoneReminderCheck_gvtz = App_Model_DW.Timer_PhoneReminderCheck_ivxo;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_PhoneRem_dsov) {
          App_Model_DW.Timer_PhoneReminderCheck_ivxo = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void Tick_Timer_WarningComplete_njjk(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningCompl_gyc1) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_WarningC_esnt) {
      App_Model_DW.is_Tick_Timer_WarningCompl_gyc1 = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_Warning_niui) {
        App_Model_DW.is_Tick_Timer_WarningCompl_gyc1 = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_WarningComplete_flk2 = 0U;
        App_Model_B.b_Timer_WarningComplete_hjex = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningComplete_flk2 + 1;
        if (((sint32)App_Model_DW.Timer_WarningComplete_flk2 + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete_flk2 = (uint16)tmp;
        App_Model_B.b_Timer_WarningComplete_hjex = App_Model_DW.Timer_WarningComplete_flk2;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_WarningC_esnt) {
          App_Model_DW.Timer_WarningComplete_flk2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void App_Mo_Function_WPCWarning_n3ee(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21)
{
  /* 1 */
  if (((uint32)rtu_Main_InSig_e0fo == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck_hqal >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == Off)) ||
      (App_Model_DW.Timer_PhoneLeft_g1mn >= ((uint8)50U))) {
    sint32 c_previousEvent;
    App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    App_Model_DW.b_WarnClearEnable_nzmj = Off;
    App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
    c_previousEvent = App_Model_DW.sfEvent_cbxk;
    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneLe_ftby;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
      App_M_Tick_Timer_PhoneLeft_jzcf();
    }

    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneWa_hotu;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
      Tick_Timer_PhoneWarningChe_lzxg();
    }

    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
      Tick_Timer_PhoneReminderCh_f2nt();
    }

    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_Warning_niui;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
      Tick_Timer_WarningComplete_njjk();
    }

    App_Model_DW.sfEvent_cbxk = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /* 1. */
    if (((uint32)App_Model_DW.b_WarnClearEnable_nzmj == On) && ((App_Model_DW.b_WPCPhoneExist_prev_njde != App_Model_DW.b_WPCPhoneExist_start_k4jj) && ((uint32)App_Model_DW.b_WPCPhoneExist_start_k4jj ==
          Off))) {
      c_previousEvent = App_Model_DW.sfEvent_cbxk;
      App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_PhoneLef_j1qj;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
        App_M_Tick_Timer_PhoneLeft_jzcf();
      }

      App_Model_DW.sfEvent_cbxk = c_previousEvent;

      /* 1. */
    } else if (((uint32)App_Model_DW.is_Tick_Timer_PhoneLeft_gvmy == App_Model_IN_On_pbff) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      c_previousEvent = App_Model_DW.sfEvent_cbxk;
      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneLe_ftby;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
        App_M_Tick_Timer_PhoneLeft_jzcf();
      }

      App_Model_DW.sfEvent_cbxk = c_previousEvent;
    } else {
      /* no actions */
    }

    /* 1. */
    if ((App_Model_DW.Timer_PhoneWarningCheck_hqal >= ((uint16)10U)) && (App_Model_DW.Timer_PhoneWarningCheck_hqal <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      App_Model_B.C_WPCWarning_d4ol = Cellphoneonthepad;

      /* b_WPCWarn = Cellphoneonthepad 8차 LFRollBack */
      App_Model_DW.b_WarnClearEnable_nzmj = On;
      c_previousEvent = App_Model_DW.sfEvent_cbxk;
      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneWa_hotu;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
        Tick_Timer_PhoneWarningChe_lzxg();
      }

      App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_PhoneRem_dsov;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
        Tick_Timer_PhoneReminderCh_f2nt();
      }

      App_Model_DW.sfEvent_cbxk = c_previousEvent;

      /* 5차 적용 */

      /* 1. */
    } else if ((App_Model_DW.Timer_PhoneReminderCheck_ivxo >= ((uint16)6000U)) && ((uint32)App_Model_DW.b_WarnClearEnable_nzmj == On) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      /* 1. */
      if (((uint32)rtu_Main_InSig_nv40 == On) || ((uint32)rtu_Main_InSig_jjhc == On)) {
        App_Model_DW.b_WarnClearEnable_nzmj = Off;
        App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
        App_Model_B.b_PhnLeftChk_Enable_azgu = Off;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        c_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
          Tick_Timer_PhoneReminderCh_f2nt();
        }

        App_Model_DW.sfEvent_cbxk = c_previousEvent;
      } else {
        /* 2. */
        App_Model_B.C_WPCWarning_d4ol = Cellphonereminder;

        /* b_WPCWarn = Cellphonereminder 8차 LFRollBack */
        c_previousEvent = App_Model_DW.sfEvent_cbxk;
        App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
          Tick_Timer_PhoneReminderCh_f2nt();
        }

        App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_WarningC_esnt;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
          Tick_Timer_WarningComplete_njjk();
        }

        App_Model_DW.sfEvent_cbxk = c_previousEvent;
      }

      /* 1. */
    } else if ((App_Model_DW.Timer_WarningComplete_flk2 >= ((uint16)50U)) && ((uint32)App_Model_DW.b_WarnClearEnable_nzmj == On) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_DW.b_WarnClearEnable_nzmj = Off;
      App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
      c_previousEvent = App_Model_DW.sfEvent_cbxk;
      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_Warning_niui;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
        Tick_Timer_WarningComplete_njjk();
      }

      App_Model_DW.sfEvent_cbxk = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void A_enter_atomic_WPCMode_NFC_jagk(void)
{
  sint32 b_previousEvent;
  App_Model_DW.b_WarnClearEnable_nzmj = Off;
  b_previousEvent = App_Model_DW.sfEvent_cbxk;
  App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneLe_ftby;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
    App_M_Tick_Timer_PhoneLeft_jzcf();
  }

  App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneWa_hotu;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
    Tick_Timer_PhoneWarningChe_lzxg();
  }

  App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
    Tick_Timer_PhoneReminderCh_f2nt();
  }

  App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_Warning_niui;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
    Tick_Timer_WarningComplete_njjk();
  }

  App_Model_DW.sfEvent_cbxk = b_previousEvent;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_WPCMode_Dis_o4re(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, WPCStatus rtu_Main_InSig_pov1)
{
  /* 1. */
  if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
    App_Model_DW.is_WPCMode_Disable_kogf = App_Model_IN_WPCMode_NFC_eleo;
    A_enter_atomic_WPCMode_NFC_jagk();
  } else {
    App_Model_DW.is_WPCMode_Disable_kogf = App_Model_IN_WPCMode_Off_nufv;
    if ((App_Model_DW.L_IGN1_IN_prev_eaae != App_Model_DW.L_IGN1_IN_start_lebj) && ((uint32)App_Model_DW.L_IGN1_IN_start_lebj == Off)) {
      sint32 b_previousEvent;
      App_Model_DW.is_WPCMode_Off_pxad = Ap_IN_LeavingPhone_Warning_ji1s;
      App_Model_DW.b_WarnClearEnable_nzmj = Off;
      b_previousEvent = App_Model_DW.sfEvent_cbxk;
      App_Model_DW.sfEvent_cbxk = (sint32)event_Start_Timer_PhoneWar_n1mt;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
        Tick_Timer_PhoneWarningChe_lzxg();
      }

      App_Model_DW.sfEvent_cbxk = b_previousEvent;
      App_Mo_Function_WPCWarning_n3ee(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
      App_Model_B.b_PhnLeftChk_Enable_azgu = On;
    } else {
      App_Model_DW.is_WPCMode_Off_pxad = IN_LeavingPhone_NoWarning_dyop;
    }
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void App_Model_WPCMode_Enable_lmai(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs,
  C_WPCWarning rtu_Main_InSig_lhyq)
{
  /* Outputs for IfAction SubSystem: '<S220>/NFC_ICE' incorporates:
   *  ActionPort: '<S400>/ActionPort'
   */
  /* SwitchCase: '<S220>/Switch Case1' incorporates:
   *  Chart: '<S400>/WPC2_MainControl3_CardSync_250522'
   */
  /* 1. */
  if ((uint32)rtu_Main_InSig_pov1 != WPCMode) {
    switch (App_Model_DW.is_WPCMode_Enable_evbg) {
     case App_Model_IN_WPCMode_Run_ildf:
      exit_internal_WPCMode_Run_fhr1();
      App_Model_DW.is_WPCMode_Enable_evbg = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     case App_Model_IN_WPCMode_Stop_aynr:
      exit_internal_WPCMode_Stop_dxd4();
      App_Model_DW.is_WPCMode_Enable_evbg = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     default:
      /* no actions */
      break;
    }

    App_Model_B.b_ChargingEnable_ovqe = Off;
    App_Model_DW.is_MainControl_ct4w = App_Mod_IN_WPCMode_Disable_cyvt;
    enter_atomic_WPCMode_Disab_or5p();
    enter_internal_WPCMode_Dis_o4re(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_pov1);
  } else {
    switch (App_Model_DW.is_WPCMode_Enable_evbg) {
     case App_Model_IN_WPCMode_Run_ildf:
      {
        /* 1. */
        if (((uint32)rtu_Main_InSig == On) || ((uint32)rtu_Main_InSig_gmt2 == On) || ((uint32)rtu_Main_InSig_b5rk == On) || ((uint32)rtu_Main_InSig_gcjy == On) || ((uint32)rtu_Main_InSig_lhyq ==
             NFCCardDetected)) {
          exit_internal_WPCMode_Run_fhr1();
          App_Model_DW.is_WPCMode_Enable_evbg = App_Model_IN_WPCMode_Stop_aynr;
          App_Model_B.b_FANModeCmd_bint = Off;
          App_Model_B.b_GreenINDCmd_mwno = Off;

          /* b_ChargingEnable = Off */
          enter_internal_WPCMode_Sto_h1gw(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
        } else {
          switch (App_Model_DW.is_WPCMode_Run_b3iy) {
           case App_Mod_IN_WPCRun_Charging_aref:
            App_Model_B.b_FANModeCmd_bint = On;

            /* 1. */
            if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
              App_Model_DW.is_WPCMode_Run_b3iy = App_Mode_IN_WPCRun_Standby_mdky;
              App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;

              /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_bint = Off;
              App_Model_B.b_GreenINDCmd_mwno = Off;
              App_Model_B.b_AmberINDCmd_m25s = Off;
            } else {
              /* 2. */
              switch (rtu_Main_InSig_pg4m) {
               case FODError:
                /*  b_FODFault == On] */
                App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_FODError_hm2b;
                App_Model_B.C_WPCWarning_d4ol = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.BlinkState_izow = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
                App_Model_B.b_FANModeCmd_bint = Off;
                App_Model_B.b_GreenINDCmd_mwno = Off;
                App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

                /*  Non GFS  */
                App_Model_B.b_BlinkState_mtzh = On;
                break;

               case Full_Charge:
                /* 3. */
                App_Model_DW.is_WPCMode_Run_b3iy = IN_WPCRun_ChargingComplete_jydm;
                App_Model_B.C_WPCWarning_d4ol = Charging_Complete;

                /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                App_Model_B.b_GreenINDCmd_mwno = On;
                App_Model_B.b_AmberINDCmd_m25s = Off;
                break;

               default:
                Function_ChargingINDColor_aroz(rtu_Main_InSig_nwkh);
                break;
              }
            }
            break;

           case IN_WPCRun_ChargingComplete_jydm:
            App_Model_B.b_FANModeCmd_bint = On;

            /* 1. */
            if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
              App_Model_DW.is_WPCMode_Run_b3iy = App_Mode_IN_WPCRun_Standby_mdky;
              App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;

              /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_bint = Off;
              App_Model_B.b_GreenINDCmd_mwno = Off;
              App_Model_B.b_AmberINDCmd_m25s = Off;
            } else {
              /* 2. */
              switch (rtu_Main_InSig_pg4m) {
               case FODError:
                /*  b_FODFault == On] */
                App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_FODError_hm2b;
                App_Model_B.C_WPCWarning_d4ol = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.BlinkState_izow = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
                App_Model_B.b_FANModeCmd_bint = Off;
                App_Model_B.b_GreenINDCmd_mwno = Off;
                App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

                /*  Non GFS  */
                App_Model_B.b_BlinkState_mtzh = On;
                break;

               case Charging:
                /* 3. */
                App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_Charging_aref;
                App_Model_B.C_WPCWarning_d4ol = PhoneCharging;

                /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                Function_ChargingINDColor_aroz(rtu_Main_InSig_nwkh);
                break;

               default:
                /* no actions */
                break;
              }
            }
            break;

           case App_Mod_IN_WPCRun_FODError_hm2b:
            {
              App_Model_B.b_FANModeCmd_bint = Off;

              /* 1. */
              if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
                sint32 d_previousEvent;

                /*  BlinkState == BlinkComplete 8차 적용 */
                App_Model_B.BlinkState_izow = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
                d_previousEvent = App_Model_DW.sfEvent_cbxk;
                App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
                  App_Tick_Timer_AmberINDBlk_fqxk();
                }

                App_Model_DW.sfEvent_cbxk = d_previousEvent;

                /*  Non GFS  */
                App_Model_B.b_BlinkState_mtzh = Off;
                App_Model_DW.is_WPCMode_Run_b3iy = App_Mode_IN_WPCRun_Standby_mdky;
                App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                App_Model_B.b_GreenINDCmd_mwno = Off;
                App_Model_B.b_AmberINDCmd_m25s = Off;
              } else {
                /* 2. */
                switch (rtu_Main_InSig_pg4m) {
                 case Charging:
                  {
                    sint32 d_previousEvent;

                    /*  BlinkState == BlinkComplete 8차 적용 */
                    App_Model_B.BlinkState_izow = BlinkOff;
                    App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
                    d_previousEvent = App_Model_DW.sfEvent_cbxk;
                    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
                      App_Tick_Timer_AmberINDBlk_fqxk();
                    }

                    App_Model_DW.sfEvent_cbxk = d_previousEvent;

                    /*  Non GFS  */
                    App_Model_B.b_BlinkState_mtzh = Off;
                    App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_Charging_aref;
                    App_Model_B.C_WPCWarning_d4ol = PhoneCharging;

                    /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                    App_Model_B.b_FANModeCmd_bint = On;
                    Function_ChargingINDColor_aroz(rtu_Main_InSig_nwkh);
                  }
                  break;

                 case Full_Charge:
                  {
                    sint32 d_previousEvent;

                    /* 3. */
                    /*  BlinkState == BlinkComplete 8차 적용 */
                    App_Model_B.BlinkState_izow = BlinkOff;
                    App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
                    d_previousEvent = App_Model_DW.sfEvent_cbxk;
                    App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
                      App_Tick_Timer_AmberINDBlk_fqxk();
                    }

                    App_Model_DW.sfEvent_cbxk = d_previousEvent;

                    /*  Non GFS  */
                    App_Model_B.b_BlinkState_mtzh = Off;
                    App_Model_DW.is_WPCMode_Run_b3iy = IN_WPCRun_ChargingComplete_jydm;
                    App_Model_B.C_WPCWarning_d4ol = Charging_Complete;

                    /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                    App_Model_B.b_FANModeCmd_bint = On;
                    App_Model_B.b_GreenINDCmd_mwno = On;
                    App_Model_B.b_AmberINDCmd_m25s = Off;
                  }
                  break;

                 default:
                  App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
                  break;
                }
              }
            }
            break;

           case App_Mode_IN_WPCRun_Standby_mdky:
            App_Model_B.b_FANModeCmd_bint = Off;

            /* 1. */
            switch (rtu_Main_InSig_pg4m) {
             case FODError:
              /*  b_FODFault == On] */
              App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_FODError_hm2b;
              App_Model_B.C_WPCWarning_d4ol = Charging_error;

              /* b_WPCWarn = Charging_error 8차 LFRollBack */
              App_Model_B.BlinkState_izow = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
              App_Model_B.b_GreenINDCmd_mwno = Off;
              App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

              /*  Non GFS  */
              App_Model_B.b_BlinkState_mtzh = On;
              break;

             case Charging:
              /* 2. */
              App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_Charging_aref;
              App_Model_B.C_WPCWarning_d4ol = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_bint = On;
              Function_ChargingINDColor_aroz(rtu_Main_InSig_nwkh);
              break;

             case Full_Charge:
              /* 3. */
              App_Model_DW.is_WPCMode_Run_b3iy = IN_WPCRun_ChargingComplete_jydm;
              App_Model_B.C_WPCWarning_d4ol = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_bint = On;
              App_Model_B.b_GreenINDCmd_mwno = On;
              App_Model_B.b_AmberINDCmd_m25s = Off;
              break;

             default:
              /* no actions */
              break;
            }
            break;

           default:
            /* no actions */
            break;
          }
        }
      }
      break;

     case App_Model_IN_WPCMode_Stop_aynr:
      {
        App_Model_B.b_FANModeCmd_bint = Off;
        if (((uint32)rtu_Main_InSig_pg4m == Full_Charge) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
             rtu_Main_InSig_b5rk == Off) && ((uint32)rtu_Main_InSig_lhyq == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_dxd4();
          App_Model_DW.is_WPCMode_Enable_evbg = App_Model_IN_WPCMode_Run_ildf;
          App_Model_B.b_ChargingEnable_ovqe = On;

          /* b_ROHMOperCmd = On /_ Non GFS _/ */
          App_Model_DW.is_WPCMode_Run_b3iy = IN_WPCRun_ChargingComplete_jydm;
          App_Model_B.C_WPCWarning_d4ol = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.b_FANModeCmd_bint = On;
          App_Model_B.b_GreenINDCmd_mwno = On;
          App_Model_B.b_AmberINDCmd_m25s = Off;
        } else if (((uint32)rtu_Main_InSig_pg4m == Charging) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
                    rtu_Main_InSig_b5rk == Off) && ((uint32)rtu_Main_InSig_lhyq == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_dxd4();
          App_Model_DW.is_WPCMode_Enable_evbg = App_Model_IN_WPCMode_Run_ildf;
          App_Model_B.b_ChargingEnable_ovqe = On;

          /* b_ROHMOperCmd = On /_ Non GFS _/ */
          App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_WPCRun_Charging_aref;
          App_Model_B.C_WPCWarning_d4ol = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          App_Model_B.b_FANModeCmd_bint = On;
          Function_ChargingINDColor_aroz(rtu_Main_InSig_nwkh);
        } else {
          switch (App_Model_DW.is_WPCMode_Stop_a2vp) {
           case App__IN_WPCStop_NotTempErr_ccgp:
            /* 1. */
            if ((uint32)rtu_Main_InSig_gcjy == On) {
              App_Model_DW.is_WPCMode_Stop_a2vp = App_Mod_IN_WPCStop_TempErr_n0yp;

              /* 240926 */
              App_Model_B.b_ChargingEnable_ovqe = Off;
              App_Model_B.C_WPCWarning_d4ol = Charging_error;
              App_Model_B.BlinkState_izow = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
              App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

              /*  Non GFS  */
              App_Model_B.b_BlinkState_mtzh = On;

              /* 2. */
            } else if (((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_b5rk == Off) && ((uint32)rtu_Main_InSig_lhyq == WPCWarningOff)) {
              App_Model_DW.is_WPCMode_Stop_a2vp = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
              App_Model_DW.is_WPCMode_Enable_evbg = App_Model_IN_WPCMode_Run_ildf;
              App_Model_B.b_ChargingEnable_ovqe = On;

              /* b_ROHMOperCmd = On /_ Non GFS _/ */
              App_Model_DW.is_WPCMode_Run_b3iy = App_Mode_IN_WPCRun_Standby_mdky;
              App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;

              /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
              App_Model_B.b_GreenINDCmd_mwno = Off;
              App_Model_B.b_AmberINDCmd_m25s = Off;
            } else {
              /* no actions */
            }
            break;

           case App_Mod_IN_WPCStop_TempErr_n0yp:
            {
              /* 1. */
              if ((uint32)rtu_Main_InSig_gcjy == Off) {
                sint32 d_previousEvent;
                App_Model_B.BlinkState_izow = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
                d_previousEvent = App_Model_DW.sfEvent_cbxk;
                App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
                  App_Tick_Timer_AmberINDBlk_fqxk();
                }

                App_Model_DW.sfEvent_cbxk = d_previousEvent;

                /*  Non GFS  */
                App_Model_B.b_BlinkState_mtzh = Off;
                App_Model_DW.is_WPCMode_Stop_a2vp = App__IN_WPCStop_NotTempErr_ccgp;

                /* 240926 */
                App_Model_B.b_ChargingEnable_ovqe = Off;
                App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
                App_Model_B.b_AmberINDCmd_m25s = Off;
              } else {
                App_Function_LEDErrorBlink_ejqw(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
              }
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

  /* End of SwitchCase: '<S220>/Switch Case1' */
  /* End of Outputs for SubSystem: '<S220>/NFC_ICE' */
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void App__Tick_Timer_CardINDBlk_mju2(void)
{
  switch (App_Model_DW.is_Tick_Timer_CardINDBlk) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_CardINDB_e5ba) {
      App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_cbxk == (sint32)event_Cancel_Timer_CardIND_keyb) {
        App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_CardINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_CardINDBlk + 1;
        if (((sint32)App_Model_DW.Timer_CardINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_CardINDBlk = (uint16)tmp;
        if (App_Model_DW.sfEvent_cbxk == (sint32)event_Start_Timer_CardINDB_e5ba) {
          App_Model_DW.Timer_CardINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__eqcb(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft_gvmy = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneLeft_g1mn = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__g2zg(void)
{
  App_Model_DW.is_Tick_Timer_PhoneWarning_m43e = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneWarningCheck_hqal = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_nhb3 = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__mm4n(void)
{
  App_Model_DW.is_Tick_Timer_PhoneReminde_iesd = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneReminderCheck_ivxo = 0U;
  App_Model_B.b_Timer_PhoneReminderCheck_gvtz = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__akvt(void)
{
  App_Model_DW.is_Tick_Timer_WarningCompl_gyc1 = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_WarningComplete_flk2 = 0U;
  App_Model_B.b_Timer_WarningComplete_hjex = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__pcsj(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1 = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk_e3ak = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__fsrs(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk2_oixi = 0U;
}

/* Function for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
static void enter_internal_Tick_Timer__jdfo(void)
{
  App_Model_DW.is_Tick_Timer_CardINDBlk = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_CardINDBlk = 0U;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void Function_ChargingINDColor_bjlk(WPCIndUSMState rtu_Main_InSig_nwkh)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) {
    App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = On;
    App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
  } else {
    App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void Ap_Tick_Timer_AmberINDBlk2_pqgr(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_AmberIND_h1p5) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_ed3e == (sint32)event_Cancel_Timer_AmberIN_eo3b) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk2_lgqd = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk2_lgqd + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk2_lgqd + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2_lgqd = (uint16)tmp;
        if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_AmberIND_h1p5) {
          App_Model_DW.Timer_AmberINDBlk2_lgqd = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void App_Tick_Timer_AmberINDBlk_cdeg(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_AmberIND_a1uc) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_ed3e == (sint32)event_Cancel_Timer_AmberIN_fgf5) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_AmberINDBlk_eod2 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk_eod2 + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk_eod2 + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk_eod2 = (uint16)tmp;
        if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_AmberIND_a1uc) {
          App_Model_DW.Timer_AmberINDBlk_eod2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void App_Function_LEDErrorBlink_jrjx(WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  switch (rtu_Main_InSig_htzs) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)App_Model_B.Output_BlinkState_dygi != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_jg3b >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_fegv = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_jg3b >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_fegv = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev !=
                   App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_dygi = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_jg3b = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_jg3b + 1));
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev !=
                    App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev !=
                    App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_start == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_dygi = BlinkOff;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_jg3b = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_jg3b + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)App_Model_B.Output_BlinkState_dygi != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_jg3b >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_fegv = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_jg3b >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_eo3b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_fegv = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c ==
                  App_Model_IN_Off_hvcc)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi == BlinkOff) && ((App_Model_DW.WPC2IndCmdState_prev !=
                   App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_dygi = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_jg3b = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_jg3b + 1));
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_dygi == BlinkOn) && (((App_Model_DW.WPC2IndCmdState_prev !=
                    App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev == WPC2IndCmdState__ErrorFadeOut)) || ((App_Model_DW.WPC2IndCmdState_prev !=
                    App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_start == WPC2IndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_dygi = BlinkOff;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_a1uc;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = On;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_nwkh == WPCIndUSMState__Type2) && ((App_Model_DW.WPC2IndCmdState_prev != App_Model_DW.WPC2IndCmdState_start) && ((uint32)App_Model_DW.WPC2IndCmdState_prev ==
                   WPC2IndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_dygi = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_jg3b = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_jg3b + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        t_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_AmberIND_h1p5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }

        App_Model_DW.sfEvent_ed3e = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void exit_internal_WPCMode_Run_mjyr(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Run_bcbf == App_Mod_IN_WPCRun_FODError_hm2b) {
    sint32 b_previousEvent;
    App_Model_B.Output_BlinkState_dygi = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
    b_previousEvent = App_Model_DW.sfEvent_ed3e;
    App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
      App_Tick_Timer_AmberINDBlk_cdeg();
    }

    App_Model_DW.sfEvent_ed3e = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
    App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void Tick_Timer_WarningTypeChec_j1qx(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningTypeC_lr0v) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_WarningT_nkmg) {
      App_Model_DW.is_Tick_Timer_WarningTypeC_lr0v = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_ed3e == (sint32)event_Cancel_Timer_Warning_as5n) {
        App_Model_DW.is_Tick_Timer_WarningTypeC_lr0v = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_WarningTypeCheck_g02y = 0U;
        App_Model_B.b_Timer_WarningTypeCheck_k1s5 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningTypeCheck_g02y + 1;
        if (((sint32)App_Model_DW.Timer_WarningTypeCheck_g02y + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningTypeCheck_g02y = (uint16)tmp;
        App_Model_B.b_Timer_WarningTypeCheck_k1s5 = App_Model_DW.Timer_WarningTypeCheck_g02y;
        if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_WarningT_nkmg) {
          App_Model_DW.Timer_WarningTypeCheck_g02y = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void App_M_Tick_Timer_PhoneLeft_bizk(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft_mf02) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_PhoneLef_kbqs) {
      App_Model_DW.is_Tick_Timer_PhoneLeft_mf02 = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_ed3e == (sint32)event_Cancel_Timer_PhoneLe_n1xi) {
        App_Model_DW.is_Tick_Timer_PhoneLeft_mf02 = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneLeft_dlm0 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneLeft_dlm0 + 1;
        if (((sint32)App_Model_DW.Timer_PhoneLeft_dlm0 + 1) > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft_dlm0 = (uint8)tmp;
        if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_PhoneLef_kbqs) {
          App_Model_DW.Timer_PhoneLeft_dlm0 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void Tick_Timer_PhoneWarningChe_d40l(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarning_i4oo) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_PhoneWar_lqk1) {
      App_Model_DW.is_Tick_Timer_PhoneWarning_i4oo = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_ed3e == (sint32)event_Cancel_Timer_PhoneWa_ataa) {
        App_Model_DW.is_Tick_Timer_PhoneWarning_i4oo = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_PhoneWarningCheck_l4yv = 0U;
        App_Model_B.b_Timer_PhoneWarningCheck_ep1a = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneWarningCheck_l4yv + 1;
        if (((sint32)App_Model_DW.Timer_PhoneWarningCheck_l4yv + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck_l4yv = (uint16)tmp;
        App_Model_B.b_Timer_PhoneWarningCheck_ep1a = App_Model_DW.Timer_PhoneWarningCheck_l4yv;
        if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_PhoneWar_lqk1) {
          App_Model_DW.Timer_PhoneWarningCheck_l4yv = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void Tick_Timer_WarningComplete_poap(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningCompl_oqlc) {
   case App_Model_IN_Off_hvcc:
    if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_WarningC_fils) {
      App_Model_DW.is_Tick_Timer_WarningCompl_oqlc = App_Model_IN_On_pbff;
    }
    break;

   case App_Model_IN_On_pbff:
    {
      if (App_Model_DW.sfEvent_ed3e == (sint32)event_Cancel_Timer_Warning_dez2) {
        App_Model_DW.is_Tick_Timer_WarningCompl_oqlc = App_Model_IN_Off_hvcc;
        App_Model_DW.Timer_WarningComplete_dewu = 0U;
        App_Model_B.b_Timer_WarningComplete_fmqe = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningComplete_dewu + 1;
        if (((sint32)App_Model_DW.Timer_WarningComplete_dewu + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete_dewu = (uint16)tmp;
        App_Model_B.b_Timer_WarningComplete_fmqe = App_Model_DW.Timer_WarningComplete_dewu;
        if (App_Model_DW.sfEvent_ed3e == (sint32)event_Start_Timer_WarningC_fils) {
          App_Model_DW.Timer_WarningComplete_dewu = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void App_Mo_Function_WPCWarning_kxrk(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21)
{
  /*  WPC 모드가 해제 or 폰 감지가 안되었을 경우 or 출력 후 폰 가져간 경우900ms */
  if (((uint32)rtu_Main_InSig_e0fo == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck_l4yv >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == Off)) ||
      (App_Model_DW.Timer_PhoneLeft_dlm0 >= ((uint8)50U))) {
    sint32 c_previousEvent;

    /* 500m */
    /*  Warning OffNidec */
    App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

    /* Output_WPCWarning = SavedPreWPCMode%Nidec */
    App_Model_DW.b_WarnClearEnable_bxvw = Off;

    /* Nidec충전가능 */
    App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
    c_previousEvent = App_Model_DW.sfEvent_ed3e;
    App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
      App_M_Tick_Timer_PhoneLeft_bizk();
    }

    App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneWa_ataa;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
      Tick_Timer_PhoneWarningChe_d40l();
    }

    App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_dez2;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
      Tick_Timer_WarningComplete_poap();
    }

    App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_as5n;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
      Tick_Timer_WarningTypeChec_j1qx();
    }

    App_Model_DW.sfEvent_ed3e = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /*  방치 알림 신호 출력 후, 휴대폰을 가져가는 경우 */
    if (((uint32)App_Model_DW.b_WarnClearEnable_bxvw == On) && ((App_Model_DW.Input_OPT_b_WPCPhoneExist__gxll != App_Model_DW.Input_OPT_b_WPCPhoneExist__mct5) && ((uint32)
          App_Model_DW.Input_OPT_b_WPCPhoneExist__mct5 == Off))) {
      /*  폰 비거치 시간 측정 타이머 시작 */
      c_previousEvent = App_Model_DW.sfEvent_ed3e;
      App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_PhoneLef_kbqs;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
        App_M_Tick_Timer_PhoneLeft_bizk();
      }

      App_Model_DW.sfEvent_ed3e = c_previousEvent;

      /*  방치알림 신호 출력 후, 폰 비거치 상태-> 다시 폰 거치 확인한 경우 */
    } else if (((uint32)App_Model_DW.is_Tick_Timer_PhoneLeft_mf02 == App_Model_IN_On_pbff) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      /*  폰 비거치 시간 측정 타이머 취소 */
      c_previousEvent = App_Model_DW.sfEvent_ed3e;
      App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
        App_M_Tick_Timer_PhoneLeft_bizk();
      }

      App_Model_DW.sfEvent_ed3e = c_previousEvent;
    } else {
      /* no actions */
    }

    /*  폰 경고 확인 조건 판단 */
    if ((uint32)App_Model_DW.PhoneLeftWrnType_bjkd == PhoneLeftWrnType__Default) {
      if (App_Model_DW.Timer_WarningTypeCheck_g02y < ((uint16)6000U)) {
        /* 60s */
        if ((uint32)rtu_Main_InSig_nv40 == On) {
          /*  60초 이내에 DoorOpen 이벤트 발생할 경우,
             경고타입 (1sec Delay 후 6sec 간 경고 출력 발생) 설정 */
          App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__LongDuration;

          /* Nidec 60초이전 이벤트는 충전금지필요%WPCMode가 아닐 때는 상시 On이므로 WPCMode일 때를 위한 조건 */
          App_Model_B.b_PhnLeftChk_Enable_ei3s = On;

          /* HMC사양에 폰충전불가 주석원복함. */
          c_previousEvent = App_Model_DW.sfEvent_ed3e;
          App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_as5n;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
            Tick_Timer_WarningTypeChec_j1qx();
          }

          App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_PhoneWar_lqk1;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
            Tick_Timer_PhoneWarningChe_d40l();
          }

          App_Model_DW.sfEvent_ed3e = c_previousEvent;
        } else {
          /* WPCMode아닐 때 충전금지위해
             PhnLeftChck_Enable On유지 */
        }
      } else {
        /*  60초 간 Door Open 없을 시, 경고 타입(즉시 500ms 경고 출력 발생) 설정 */
        App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__ShortDuration;

        /* b_PhnLeftChk_Enable = On%Nidec%60초 이후 영향으로 불필요 */
        c_previousEvent = App_Model_DW.sfEvent_ed3e;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_as5n;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
          Tick_Timer_WarningTypeChec_j1qx();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_PhoneWar_lqk1;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
          Tick_Timer_PhoneWarningChe_d40l();
        }

        App_Model_DW.sfEvent_ed3e = c_previousEvent;
      }
    }

    /*  폰 경고 확인 시간 중 폰 감지됨100ms900ms */
    if ((App_Model_DW.Timer_PhoneWarningCheck_l4yv >= (uint16)((uint8)10U)) && (App_Model_DW.Timer_PhoneWarningCheck_l4yv <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_nt21 == On)) {
      /* Output_WPCWarning = Cellphoneonthepad%NFCModeControl연동시그널. IG On중에는 미적용 */
      c_previousEvent = App_Model_DW.sfEvent_ed3e;
      App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneWa_ataa;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
        Tick_Timer_PhoneWarningChe_d40l();
      }

      App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningC_fils;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
        Tick_Timer_WarningComplete_poap();
      }

      App_Model_DW.sfEvent_ed3e = c_previousEvent;
    }

    /*  경고 알림 출력
       [(PhoneLeftWrnType == PhoneLeftWrnType__LongDuration&&Timer_WarningComplete >= Par_WarningDelayTime &&...0s
       Timer_WarningComplete <= Par_WarningTime__LongDuration+Par_WarningDelayTime) ||...6s+0s %%DelayDelete_Nidec6s */
    if ((((uint32)App_Model_DW.PhoneLeftWrnType_bjkd == PhoneLeftWrnType__LongDuration) && ((uint32)App_Model_DW.is_Tick_Timer_WarningCompl_oqlc == App_Model_IN_On_pbff) &&
         (App_Model_DW.Timer_WarningComplete_dewu <= ((uint16)600U))) || (((uint32)App_Model_DW.PhoneLeftWrnType_bjkd == PhoneLeftWrnType__ShortDuration) && ((uint32)
          App_Model_DW.is_Tick_Timer_WarningCompl_oqlc == App_Model_IN_On_pbff) && (App_Model_DW.Timer_WarningComplete_dewu <= ((uint16)50U)))) {
      /* 500m */
      App_Model_B.Output_WPCWarning_lelw = Cellphonereminder;
      App_Model_DW.b_WarnClearEnable_bxvw = On;

      /*  경고 알림 출력 해제 조건 */
    } else if ((((uint32)App_Model_DW.PhoneLeftWrnType_bjkd == PhoneLeftWrnType__LongDuration) && (App_Model_DW.Timer_WarningComplete_dewu > (((uint16)600U) + ((uint16)0U)))) || (((uint32)
                 App_Model_DW.PhoneLeftWrnType_bjkd == PhoneLeftWrnType__ShortDuration) && (App_Model_DW.Timer_WarningComplete_dewu > ((uint16)50U)))) {
      /* Nidec */
      App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

      /* Output_WPCWarning = SavedPreWPCMode%NidecNidec 필요250219 */
      App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;

      /* HMC사양에 폰충전불가 주석원복함. */
      c_previousEvent = App_Model_DW.sfEvent_ed3e;
      App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_dez2;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
        Tick_Timer_WarningComplete_poap();
      }

      App_Model_DW.sfEvent_ed3e = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void App_Model_WPCMode_Run_kcl3(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool rtu_Main_InSig_nv40, Bool
  rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta rtu_Main_InSig_jgrv, C_WPCWarning rtu_Main_InSig_lhyq)
{
  Bool tmp;
  tmp = App_Model_DW.b_DrvDrSw_start_drnb;
  if (((App_Model_DW.Input_OPT_GearPosSta_prev_ki4t != App_Model_DW.Input_OPT_GearPosSta_start_n44n) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start_n44n == GearPos_P) && ((uint32)
        rtu_Main_InSig_nv40 == On)) || ((App_Model_DW.b_DrvDrSw_prev_h4if != tmp) && ((uint32)tmp == On) && ((uint32)rtu_Main_InSig_jgrv == GearPos_P))) {
    sint32 d_previousEvent;

    /* Nidec */
    exit_internal_WPCMode_Run_mjyr();
    App_Model_DW.is_WPCMode_Enable_mxi5 = IN_LeavingPhone_Warning_In_arkq;
    App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;
    App_Model_DW.b_WarnClearEnable_bxvw = Off;
    App_Model_B.b_ChargingEnable_anij = Off;
    d_previousEvent = App_Model_DW.sfEvent_ed3e;
    App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningT_nkmg;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
      Tick_Timer_WarningTypeChec_j1qx();
    }

    App_Model_DW.sfEvent_ed3e = d_previousEvent;
    App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

    /* 1. */
  } else if (((uint32)rtu_Main_InSig == On) || ((uint32)rtu_Main_InSig_gmt2 == On) || ((uint32)rtu_Main_InSig_gcjy == On) || ((uint32)rtu_Main_InSig_gcjy == On) || ((uint32)rtu_Main_InSig_lhyq ==
              NFCCardDetected)) {
    exit_internal_WPCMode_Run_mjyr();
    App_Model_DW.is_WPCMode_Enable_mxi5 = App_Model_IN_WPCMode_Stop_ihz1;
    App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_anij = Off;

    /* 1. */
    if ((uint32)rtu_Main_InSig_gcjy == On) {
      App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_WPCStop_TempErr_n0yp;
      App_Model_B.Output_WPCWarning_lelw = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      App_Model_B.Output_BlinkState_dygi = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
      App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

      /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
      App_Model_B.Output_OPT_b_BlinkState_fegv = On;
    } else {
      App_Model_DW.is_WPCMode_Stop_g1qo = App__IN_WPCStop_NotTempErr_ccgp;
      App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Run_bcbf) {
     case App_Mod_IN_WPCRun_Charging_aref:
      App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
        App_Model_DW.is_WPCMode_Run_bcbf = App_Mode_IN_WPCRun_Standby_mdky;
        App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_pg4m) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_FODError_hm2b;
          App_Model_B.Output_WPCWarning_lelw = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.Output_BlinkState_dygi = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
          App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
          App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_fegv = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_bcbf = IN_WPCRun_ChargingComplete_jydm;
          App_Model_B.Output_WPCWarning_lelw = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = On;
          App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
          break;

         default:
          Function_ChargingINDColor_bjlk(rtu_Main_InSig_nwkh);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_jydm:
      App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
        App_Model_DW.is_WPCMode_Run_bcbf = App_Mode_IN_WPCRun_Standby_mdky;
        App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_pg4m) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_FODError_hm2b;
          App_Model_B.Output_WPCWarning_lelw = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.Output_BlinkState_dygi = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
          App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
          App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_fegv = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_Charging_aref;
          App_Model_B.Output_WPCWarning_lelw = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          Function_ChargingINDColor_bjlk(rtu_Main_InSig_nwkh);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_hm2b:
      {
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;

        /* 1. */
        if (((uint32)rtu_Main_InSig_pg4m == Standby) || ((uint32)rtu_Main_InSig_pg4m == Init)) {
          sint32 d_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          App_Model_B.Output_BlinkState_dygi = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
          d_previousEvent = App_Model_DW.sfEvent_ed3e;
          App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
            App_Tick_Timer_AmberINDBlk_cdeg();
          }

          App_Model_DW.sfEvent_ed3e = d_previousEvent;

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
          App_Model_DW.is_WPCMode_Run_bcbf = App_Mode_IN_WPCRun_Standby_mdky;
          App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
          App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_pg4m) {
           case Charging:
            {
              sint32 d_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.Output_BlinkState_dygi = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
              d_previousEvent = App_Model_DW.sfEvent_ed3e;
              App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
                App_Tick_Timer_AmberINDBlk_cdeg();
              }

              App_Model_DW.sfEvent_ed3e = d_previousEvent;

              /*  Non GFS  */
              App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
              App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_Charging_aref;
              App_Model_B.Output_WPCWarning_lelw = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;
              Function_ChargingINDColor_bjlk(rtu_Main_InSig_nwkh);
            }
            break;

           case Full_Charge:
            {
              sint32 d_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.Output_BlinkState_dygi = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
              d_previousEvent = App_Model_DW.sfEvent_ed3e;
              App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
                App_Tick_Timer_AmberINDBlk_cdeg();
              }

              App_Model_DW.sfEvent_ed3e = d_previousEvent;

              /*  Non GFS  */
              App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
              App_Model_DW.is_WPCMode_Run_bcbf = IN_WPCRun_ChargingComplete_jydm;
              App_Model_B.Output_WPCWarning_lelw = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;
              App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = On;
              App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_mdky:
      App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;

      /* 1. */
      switch (rtu_Main_InSig_pg4m) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_FODError_hm2b;
        App_Model_B.Output_WPCWarning_lelw = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        App_Model_B.Output_BlinkState_dygi = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
        App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
        App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

        /*  Non GFS  */
        App_Model_B.Output_OPT_b_BlinkState_fegv = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_Charging_aref;
        App_Model_B.Output_WPCWarning_lelw = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;
        Function_ChargingINDColor_bjlk(rtu_Main_InSig_nwkh);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run_bcbf = IN_WPCRun_ChargingComplete_jydm;
        App_Model_B.Output_WPCWarning_lelw = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;
        App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = On;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void exit_internal_WPCMode_Stop_fyoo(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Stop_g1qo == App_Mod_IN_WPCStop_TempErr_n0yp) {
    sint32 b_previousEvent;

    /* Function_NFCCardDetection() 8차 적용 삭제 */
    App_Model_B.Output_BlinkState_dygi = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
    b_previousEvent = App_Model_DW.sfEvent_ed3e;
    App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
      App_Tick_Timer_AmberINDBlk_cdeg();
    }

    App_Model_DW.sfEvent_ed3e = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
    App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  } else {
    App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_atomic_WPCMode_Disab_diah(void)
{
  sint32 b_previousEvent;
  App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
  App_Model_B.Output_BlinkState_dygi = BlinkOff;
  App_Model_DW.Counter_BlinkCnt_jg3b = 0U;

  /* b_ChargingEnable = Off 8차 적용 삭제 */
  App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
  App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
  b_previousEvent = App_Model_DW.sfEvent_ed3e;
  App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
    App_Tick_Timer_AmberINDBlk_cdeg();
  }

  App_Model_DW.sfEvent_ed3e = b_previousEvent;

  /* Nidec */
  App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_WPCMode_Off_iu3m(C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, GearPosSta rtu_Main_InSig_jgrv)
{
  /* [hasChangedTo(Input_OPT_GearPosSta,GearPos_P)] */
  if ((uint32)rtu_Main_InSig_jgrv == GearPos_P) {
    sint32 b_previousEvent;

    /* Nidec */
    App_Model_DW.is_WPCMode_Off_hfyl = Ap_IN_LeavingPhone_Warning_ji1s;
    App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;
    App_Model_DW.b_WarnClearEnable_bxvw = Off;
    b_previousEvent = App_Model_DW.sfEvent_ed3e;
    App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningT_nkmg;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
      Tick_Timer_WarningTypeChec_j1qx();
    }

    App_Model_DW.sfEvent_ed3e = b_previousEvent;
    App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

    /* Nidec */
    App_Model_B.b_PhnLeftChk_Enable_ei3s = On;
  } else {
    App_Model_DW.is_WPCMode_Off_hfyl = IN_LeavingPhone_NoWarning_dyop;
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void A_enter_atomic_WPCMode_NFC_ggnd(void)
{
  sint32 b_previousEvent;
  App_Model_DW.b_WarnClearEnable_bxvw = Off;
  b_previousEvent = App_Model_DW.sfEvent_ed3e;
  App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
    App_M_Tick_Timer_PhoneLeft_bizk();
  }

  App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneWa_ataa;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
    Tick_Timer_PhoneWarningChe_d40l();
  }

  App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_dez2;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
    Tick_Timer_WarningComplete_poap();
  }

  App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_as5n;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
    Tick_Timer_WarningTypeChec_j1qx();
  }

  App_Model_DW.sfEvent_ed3e = b_previousEvent;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void App_Model_WPCMode_Enable_a3go(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool rtu_Main_InSig_nv40, Bool
  rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs, GearPosSta rtu_Main_InSig_jgrv, C_WPCWarning
  rtu_Main_InSig_lhyq)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_pov1 != WPCMode) {
    switch (App_Model_DW.is_WPCMode_Enable_mxi5) {
     case IN_LeavingPhone_Warning_In_arkq:
      /* Nidec */
      App_Model_DW.is_WPCMode_Enable_mxi5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     case App_Model_IN_WPCMode_Run_acpk:
      exit_internal_WPCMode_Run_mjyr();
      App_Model_DW.is_WPCMode_Enable_mxi5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     case App_Model_IN_WPCMode_Stop_ihz1:
      exit_internal_WPCMode_Stop_fyoo();
      App_Model_DW.is_WPCMode_Enable_mxi5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
      break;

     default:
      /* no actions */
      break;
    }

    /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_anij = Off;
    App_Model_DW.is_MainControl_i4ep = App_Mod_IN_WPCMode_Disable_cyvt;
    enter_atomic_WPCMode_Disab_diah();

    /* 1. */
    if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
      App_Model_DW.is_WPCMode_Disable_mi5f = App_Model_IN_WPCMode_NFC_eleo;
      A_enter_atomic_WPCMode_NFC_ggnd();
    } else {
      App_Model_DW.is_WPCMode_Disable_mi5f = App_Model_IN_WPCMode_Off_nufv;

      /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
       *  ActionPort: '<S399>/ActionPort'
       */
      /* SwitchCase: '<S220>/Switch Case1' incorporates:
       *  Chart: '<S399>/WPC2_MainControl_EV_250522'
       */
      enter_internal_WPCMode_Off_iu3m(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_jgrv);

      /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Enable_mxi5) {
     case IN_LeavingPhone_Warning_In_arkq:
      {
        Bool tmp_0;
        GearPosSta tmp;
        tmp = App_Model_DW.Input_OPT_GearPosSta_prev_ki4t;
        tmp_0 = App_Model_DW.b_DrvDrSw_start_drnb;
        if (((tmp != App_Model_DW.Input_OPT_GearPosSta_start_n44n) && ((uint32)tmp == GearPos_P)) || ((App_Model_DW.b_DrvDrSw_prev_h4if != tmp_0) && ((uint32)tmp_0 == Off))) {
          /* Nidec DoorClose */
          /* Nidec */
          App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
          App_Model_DW.is_WPCMode_Enable_mxi5 = App_Model_IN_WPCMode_Stop_ihz1;
          App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;

          /* b_ROHMOperCmd = Off /_ Non GFS _/ */
          App_Model_B.b_ChargingEnable_anij = Off;

          /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
           *  ActionPort: '<S399>/ActionPort'
           */
          /* SwitchCase: '<S220>/Switch Case1' incorporates:
           *  Chart: '<S399>/WPC2_MainControl_EV_250522'
           */
          /* 1. */
          if ((uint32)rtu_Main_InSig_gcjy == On) {
            App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_WPCStop_TempErr_n0yp;
            App_Model_B.Output_WPCWarning_lelw = Charging_error;

            /* b_WPCWarn = Charging_error 8차 LFRollBack */
            App_Model_B.Output_BlinkState_dygi = BlinkOff;
            App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
            App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

            /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
            App_Model_B.Output_OPT_b_BlinkState_fegv = On;
          } else {
            App_Model_DW.is_WPCMode_Stop_g1qo = App__IN_WPCStop_NotTempErr_ccgp;
            App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

            /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
            App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
          }

          /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
        } else if ((tmp != App_Model_DW.Input_OPT_GearPosSta_start_n44n) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start_n44n == GearPos_P)) {
          sint32 b_previousEvent;

          /* Nidec */
          App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
          App_Model_DW.is_WPCMode_Enable_mxi5 = IN_LeavingPhone_Warning_In_arkq;
          App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;
          App_Model_DW.b_WarnClearEnable_bxvw = Off;
          App_Model_B.b_ChargingEnable_anij = Off;
          b_previousEvent = App_Model_DW.sfEvent_ed3e;
          App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningT_nkmg;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
            Tick_Timer_WarningTypeChec_j1qx();
          }

          App_Model_DW.sfEvent_ed3e = b_previousEvent;

          /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
           *  ActionPort: '<S399>/ActionPort'
           */
          /* SwitchCase: '<S220>/Switch Case1' incorporates:
           *  Chart: '<S399>/WPC2_MainControl_EV_250522'
           */
          App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

          /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
        } else {
          /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
           *  ActionPort: '<S399>/ActionPort'
           */
          /* SwitchCase: '<S220>/Switch Case1' incorporates:
           *  Chart: '<S399>/WPC2_MainControl_EV_250522'
           */
          /* b_PhnLeftChk_Enable = On%Nidec%충전상태를 조건에따라 판단하기위해 주석처리 */
          App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

          /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
        }
      }
      break;

     case App_Model_IN_WPCMode_Run_acpk:
      /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
       *  ActionPort: '<S399>/ActionPort'
       */
      /* SwitchCase: '<S220>/Switch Case1' incorporates:
       *  Chart: '<S399>/WPC2_MainControl_EV_250522'
       */
      App_Model_WPCMode_Run_kcl3(rtu_Main_InSig, rtu_Main_InSig_gmt2, rtu_Main_InSig_e0fo, rtu_Main_InSig_gcjy, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_pg4m, rtu_Main_InSig_nwkh,
        rtu_Main_InSig_htzs, rtu_Main_InSig_jgrv, rtu_Main_InSig_lhyq);

      /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
      break;

     case App_Model_IN_WPCMode_Stop_ihz1:
      {
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;

        /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
         *  ActionPort: '<S399>/ActionPort'
         */
        /* SwitchCase: '<S220>/Switch Case1' incorporates:
         *  Chart: '<S399>/WPC2_MainControl_EV_250522'
         */
        if (((uint32)rtu_Main_InSig_pg4m == Full_Charge) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
             rtu_Main_InSig_gcjy == Off) && ((uint32)rtu_Main_InSig_lhyq == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_fyoo();
          App_Model_DW.is_WPCMode_Enable_mxi5 = App_Model_IN_WPCMode_Run_acpk;
          App_Model_B.b_ChargingEnable_anij = On;
          App_Model_DW.is_WPCMode_Run_bcbf = IN_WPCRun_ChargingComplete_jydm;
          App_Model_B.Output_WPCWarning_lelw = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;
          App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = On;
          App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
        } else if (((uint32)rtu_Main_InSig_pg4m == Charging) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
                    rtu_Main_InSig_gcjy == Off) && ((uint32)rtu_Main_InSig_lhyq == WPCWarningOff)) {
          exit_internal_WPCMode_Stop_fyoo();
          App_Model_DW.is_WPCMode_Enable_mxi5 = App_Model_IN_WPCMode_Run_acpk;
          App_Model_B.b_ChargingEnable_anij = On;
          App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_WPCRun_Charging_aref;
          App_Model_B.Output_WPCWarning_lelw = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = On;
          Function_ChargingINDColor_bjlk(rtu_Main_InSig_nwkh);
        } else {
          GearPosSta tmp;
          tmp = App_Model_DW.Input_OPT_GearPosSta_start_n44n;
          if (((App_Model_DW.Input_OPT_GearPosSta_prev_ki4t != tmp) && ((uint32)tmp == GearPos_P) && ((uint32)rtu_Main_InSig_nv40 == On)) || ((App_Model_DW.b_DrvDrSw_prev_h4if !=
                App_Model_DW.b_DrvDrSw_start_drnb) && ((uint32)App_Model_DW.b_DrvDrSw_start_drnb == On) && ((uint32)rtu_Main_InSig_jgrv == GearPos_P))) {
            sint32 b_previousEvent;

            /* Nidec */
            exit_internal_WPCMode_Stop_fyoo();
            App_Model_DW.is_WPCMode_Enable_mxi5 = IN_LeavingPhone_Warning_In_arkq;
            App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;
            App_Model_DW.b_WarnClearEnable_bxvw = Off;
            App_Model_B.b_ChargingEnable_anij = Off;
            b_previousEvent = App_Model_DW.sfEvent_ed3e;
            App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningT_nkmg;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
              Tick_Timer_WarningTypeChec_j1qx();
            }

            App_Model_DW.sfEvent_ed3e = b_previousEvent;
            App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
          } else {
            switch (App_Model_DW.is_WPCMode_Stop_g1qo) {
             case App__IN_WPCStop_NotTempErr_ccgp:
              /* 1. */
              if ((uint32)rtu_Main_InSig_gcjy == On) {
                App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_WPCStop_TempErr_n0yp;
                App_Model_B.Output_WPCWarning_lelw = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.Output_BlinkState_dygi = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
                App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

                /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
                App_Model_B.Output_OPT_b_BlinkState_fegv = On;

                /* 2. */
              } else if (((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)rtu_Main_InSig_lhyq == WPCWarningOff)) {
                App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                App_Model_DW.is_WPCMode_Enable_mxi5 = App_Model_IN_WPCMode_Run_acpk;
                App_Model_B.b_ChargingEnable_anij = On;
                App_Model_DW.is_WPCMode_Run_bcbf = App_Mode_IN_WPCRun_Standby_mdky;
                App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
                App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
              } else {
                /* Function_NFCCardDetection() 8차 적용 삭제
                   Function_NFCCardDetection() 8차 적용 삭제 */
              }
              break;

             case App_Mod_IN_WPCStop_TempErr_n0yp:
              {
                /* 1. */
                if ((uint32)rtu_Main_InSig_gcjy == Off) {
                  sint32 b_previousEvent;

                  /* Function_NFCCardDetection() 8차 적용 삭제 */
                  App_Model_B.Output_BlinkState_dygi = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
                  b_previousEvent = App_Model_DW.sfEvent_ed3e;
                  App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
                    App_Tick_Timer_AmberINDBlk_cdeg();
                  }

                  App_Model_DW.sfEvent_ed3e = b_previousEvent;

                  /*  Non GFS  */
                  App_Model_B.Output_OPT_b_BlinkState_fegv = Off;
                  App_Model_DW.is_WPCMode_Stop_g1qo = App__IN_WPCStop_NotTempErr_ccgp;
                  App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
                } else {
                  App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
                }
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }

        /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_WPCMode_Ena_bzqz(Bool rtu_Main_InSig_gcjy, WPCIndUSMState rtu_Main_InSig_nwkh, Bool rtu_Main_InSig_htzs)
{
  App_Model_DW.is_WPCMode_Enable_mxi5 = App_Model_IN_WPCMode_Stop_ihz1;
  App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;

  /* b_ROHMOperCmd = Off /_ Non GFS _/ */
  App_Model_B.b_ChargingEnable_anij = Off;

  /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
   *  ActionPort: '<S399>/ActionPort'
   */
  /* SwitchCase: '<S220>/Switch Case1' incorporates:
   *  Chart: '<S399>/WPC2_MainControl_EV_250522'
   */
  /* 1. */
  if ((uint32)rtu_Main_InSig_gcjy == On) {
    App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_WPCStop_TempErr_n0yp;
    App_Model_B.Output_WPCWarning_lelw = Charging_error;

    /* b_WPCWarn = Charging_error 8차 LFRollBack */
    App_Model_B.Output_BlinkState_dygi = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
    App_Function_LEDErrorBlink_jrjx(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

    /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_fegv = On;
  } else {
    App_Model_DW.is_WPCMode_Stop_g1qo = App__IN_WPCStop_NotTempErr_ccgp;
    App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
  }

  /* End of SwitchCase: '<S220>/Switch Case1' */
  /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_Tick_Timer__eqt5(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft_mf02 = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneLeft_dlm0 = 0U;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_Tick_Timer__afno(void)
{
  App_Model_DW.is_Tick_Timer_PhoneWarning_i4oo = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_PhoneWarningCheck_l4yv = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_ep1a = 0U;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_Tick_Timer__djfr(void)
{
  App_Model_DW.is_Tick_Timer_WarningCompl_oqlc = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_WarningComplete_dewu = 0U;
  App_Model_B.b_Timer_WarningComplete_fmqe = 0U;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_Tick_Timer__kc5l(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk_eod2 = 0U;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_Tick_Timer__la5p(void)
{
  App_Model_DW.is_Tick_Timer_WarningTypeC_lr0v = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_WarningTypeCheck_g02y = 0U;
  App_Model_B.b_Timer_WarningTypeCheck_k1s5 = 0U;
}

/* Function for Chart: '<S399>/WPC2_MainControl_EV_250522' */
static void enter_internal_Tick_Timer__pr3d(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx = App_Model_IN_Off_hvcc;
  App_Model_DW.Timer_AmberINDBlk2_lgqd = 0U;
}

/* System initialize for atomic system: '<S20>/WPC_MainControl_Function' */
void WPC_MainControl_Funct_cp2h_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_gmt2, Bool *rty_MainOut_Sig_b5rk, Bool *rty_MainOut_Sig_e0fo, Bool *rty_MainOut_Sig_gcjy, uint16
  *rty_MainOut_Sig_jjhc, uint16 *rty_MainOut_Sig_nv40, uint16 *rty_MainOut_Sig_nt21, Bool *rty_MainOut_Sig_pg4m, BlinkState *rty_MainOut_Sig_pov1, Bool *rty_MainOut_Sig_kyig, uint16
  *rty_MainOut_Sig_nwkh)
{
  /* SystemInitialize for Chart: '<S220>/Chart' */
  App_Model_Chart_Init(&App_Model_B.MainContMode_fjp0, &App_Model_DW.sf_Chart_psff);

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  /* SystemInitialize for Chart: '<S402>/WPC2_MainControl2_250507' */
  App_Model_DW.sfEvent_g0by = (sint32)App_Model_CALL_EVENT_eki3;
  App_Model_DW.is_active_MainControl_ptwm = 0U;
  App_Model_DW.is_MainControl_dd3w = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Disable_maoa = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Enable_nczh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_c1uf = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk_kbhx = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_eu2r = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_hfwv = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_PhnLe_c01w = 0U;
  App_Model_DW.is_Tick_Timer_PhnLeftChatt_eous = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_g4qp = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft_oo5f = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_hytt = 0U;
  App_Model_DW.is_Tick_Timer_PhoneReminde_davg = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_nbqp = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarning_m4i5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Warni_hwpi = 0U;
  App_Model_DW.is_Tick_Timer_WarningCompl_d0pq = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_c40_MainControl_Lib = 0U;
  App_Model_DW.b_WarnClearEnable_lyus = Off;
  App_Model_DW.Timer_AmberINDBlk_lrhp = 0U;
  App_Model_DW.Timer_PhoneLeft_g0qt = 0U;
  App_Model_DW.Timer_PhoneReminderCheck_gd2r = 0U;
  App_Model_DW.Timer_PhoneWarningCheck_dcqd = 0U;
  App_Model_DW.Timer_WarningComplete_inev = 0U;
  App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
  App_Model_DW.Timer_AmberINDBlk2_hgzx = 0U;
  App_Model_DW.Timer_PhnLeftChattering_jk53 = 0U;
  App_Model_DW.b_Timer_PhoneReminderCheck_fpiw = Off;
  App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;
  App_Model_B.b_FANModeCmd_evyn = Off;
  App_Model_B.b_GreenINDCmd_otki = Off;
  App_Model_B.b_AmberINDCmd_a4kq = Off;
  App_Model_B.b_BlinkState_pir3 = Off;
  App_Model_B.b_Timer_PhoneReminderCheck_btkg = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_bml0 = 0U;
  App_Model_B.b_Timer_WarningComplete_oufu = 0U;
  App_Model_B.b_ChargingEnable_ith1 = Off;
  App_Model_B.BlinkState_gx2f = BlinkOff;
  App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
  App_Model_DW.b_WPCPhoneExist_prev_hngm = Off;
  App_Model_DW.b_WPCPhoneExist_start_mymr = Off;
  App_Model_DW.C_DrvDrSw_prev_a1mt = Off;
  App_Model_DW.C_DrvDrSw_start_hwlv = Off;
  App_Model_DW.C_AstDrSw_prev_n4pb = Off;
  App_Model_DW.C_AstDrSw_start_a3od = Off;
  App_Model_DW.WPC2IndCmdState_prev_dtts = WPC2IndCmdState__Default;
  App_Model_DW.WPC2IndCmdState_start_jjne = WPC2IndCmdState__Default;
  App_Model_DW.L_IGN1_IN_prev_hgcq = Off;
  App_Model_DW.L_IGN1_IN_start_pbim = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_EV' */
  /* SystemInitialize for Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' incorporates:
   *  Chart: '<S402>/WPC2_MainControl2_250507'
   */
  App_Model_DW.sfEvent_cpiu = (sint32)App_Model_CALL_EVENT_eki3;
  App_Model_DW.is_active_MainControl_nmbq = 0U;
  App_Model_DW.is_MainControl_aanr = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Disable_keqj = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Off_mguh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Enable_l4ui = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Run_nncw = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Stop_lqw5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_bojy = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk_l2dh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_b43o = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_aj1o = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_kzfg = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft_a0zn = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_lijn = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarning_euwb = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Warni_plve = 0U;
  App_Model_DW.is_Tick_Timer_WarningCompl_nhqc = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Warni_empn = 0U;
  App_Model_DW.is_Tick_Timer_WarningTypeC_e2pu = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_c71_MainControl_Lib = 0U;
  App_Model_DW.Timer_AmberINDBlk_hwlh = 0U;
  App_Model_DW.Timer_PhoneLeft_ew4s = 0U;
  App_Model_DW.Timer_PhoneWarningCheck_odnd = 0U;
  App_Model_DW.Timer_WarningComplete_lffg = 0U;
  App_Model_DW.Counter_BlinkCnt_poku = 0U;
  App_Model_DW.Timer_WarningTypeCheck_kf0i = 0U;
  App_Model_DW.b_WarnClearEnable_f4qc = 0U;
  App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
  App_Model_DW.Timer_AmberINDBlk2_mfn5 = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;
  App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
  App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;
  App_Model_B.Output_OPT_b_BlinkState_nxwe = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.b_Timer_WarningTypeCheck_c4cy = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_jt3z = 0U;
  App_Model_B.b_Timer_WarningComplete_n0c3 = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.b_ChargingEnable_iqlw = Off;
  App_Model_B.Output_BlinkState_kepa = BlinkOff;
  App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
  App_Model_DW.Input_OPT_b_WPCPhoneExist__asus = Off;
  App_Model_DW.Input_OPT_b_WPCPhoneExist__igwe = Off;
  App_Model_DW.WPC2IndCmdState_prev_eusn = WPC2IndCmdState__Default;
  App_Model_DW.WPC2IndCmdState_start_nyja = WPC2IndCmdState__Default;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_DW.Input_OPT_GearPosSta_prev_bpse = GearPos_P;
  App_Model_DW.Input_OPT_GearPosSta_start_djgk = GearPos_P;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_DW.b_DrvDrSw_prev_ii3v = Off;
  App_Model_DW.b_DrvDrSw_start_e0qz = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_EV' */

  /* SystemInitialize for IfAction SubSystem: '<S220>/NFC_ICE' */
  /* SystemInitialize for Chart: '<S400>/WPC2_MainControl3_CardSync_250522' incorporates:
   *  Chart: '<S402>/WPC2_MainControl2_250507'
   */
  App_Model_DW.sfEvent_cbxk = (sint32)App_Model_CALL_EVENT_eki3;
  App_Model_DW.is_active_MainControl_dj5b = 0U;
  App_Model_DW.is_MainControl_ct4w = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Disable_kogf = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Off_pxad = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Enable_evbg = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Run_b3iy = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Stop_a2vp = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_ko34 = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk_asl1 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_kdsx = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_fh1o = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_CardINDBlk = 0U;
  App_Model_DW.is_Tick_Timer_CardINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_pxif = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft_gvmy = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_j2ai = 0U;
  App_Model_DW.is_Tick_Timer_PhoneReminde_iesd = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_ci1r = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarning_m43e = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Warni_ln5u = 0U;
  App_Model_DW.is_Tick_Timer_WarningCompl_gyc1 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_c52_MainControl_Lib = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_DW.b_WarnClearEnable_nzmj = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_DW.Timer_AmberINDBlk_e3ak = 0U;
  App_Model_DW.Timer_PhoneLeft_g1mn = 0U;
  App_Model_DW.Timer_PhoneReminderCheck_ivxo = 0U;
  App_Model_DW.Timer_PhoneWarningCheck_hqal = 0U;
  App_Model_DW.Timer_WarningComplete_flk2 = 0U;
  App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
  App_Model_DW.Timer_AmberINDBlk2_oixi = 0U;
  App_Model_DW.Timer_CardINDBlk = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
  App_Model_B.b_FANModeCmd_bint = Off;
  App_Model_B.b_GreenINDCmd_mwno = Off;
  App_Model_B.b_AmberINDCmd_m25s = Off;
  App_Model_B.b_BlinkState_mtzh = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.b_Timer_PhoneReminderCheck_gvtz = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_nhb3 = 0U;
  App_Model_B.b_Timer_WarningComplete_hjex = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.b_ChargingEnable_ovqe = Off;
  App_Model_B.BlinkState_izow = BlinkOff;
  App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
  App_Model_DW.b_WPCPhoneExist_prev_njde = Off;
  App_Model_DW.b_WPCPhoneExist_start_k4jj = Off;
  App_Model_DW.WPC2IndCmdState_prev_gzvs = WPC2IndCmdState__Default;
  App_Model_DW.WPC2IndCmdState_start_jkee = WPC2IndCmdState__Default;
  App_Model_DW.L_IGN1_IN_prev_eaae = Off;
  App_Model_DW.L_IGN1_IN_start_lebj = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  /* End of SystemInitialize for SubSystem: '<S220>/NFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S220>/NFC_EV' */
  /* SystemInitialize for Chart: '<S399>/WPC2_MainControl_EV_250522' incorporates:
   *  Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC'
   *  Chart: '<S402>/WPC2_MainControl2_250507'
   */
  App_Model_DW.sfEvent_ed3e = (sint32)App_Model_CALL_EVENT_eki3;
  App_Model_DW.is_active_MainControl_phku = 0U;
  App_Model_DW.is_MainControl_i4ep = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Disable_mi5f = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Off_hfyl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Enable_mxi5 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Run_bcbf = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_WPCMode_Stop_g1qo = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_nm31 = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk_dp4c = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Amber_djxt = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_iebx = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_pcac = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft_mf02 = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Phone_nkyp = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarning_i4oo = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Warni_ghx5 = 0U;
  App_Model_DW.is_Tick_Timer_WarningCompl_oqlc = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_Tick_Timer_Warni_l1oa = 0U;
  App_Model_DW.is_Tick_Timer_WarningTypeC_lr0v = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
  App_Model_DW.is_active_c63_MainControl_Lib = 0U;
  App_Model_DW.Timer_AmberINDBlk_eod2 = 0U;
  App_Model_DW.Timer_PhoneLeft_dlm0 = 0U;
  App_Model_DW.Timer_PhoneWarningCheck_l4yv = 0U;
  App_Model_DW.Timer_WarningComplete_dewu = 0U;
  App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
  App_Model_DW.Timer_WarningTypeCheck_g02y = 0U;
  App_Model_DW.b_WarnClearEnable_bxvw = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_EV' */
  App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_EV' */
  App_Model_DW.Timer_AmberINDBlk2_lgqd = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;
  App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
  App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;
  App_Model_B.Output_OPT_b_BlinkState_fegv = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.b_Timer_WarningTypeCheck_k1s5 = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_ep1a = 0U;
  App_Model_B.b_Timer_WarningComplete_fmqe = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_B.b_ChargingEnable_anij = Off;
  App_Model_B.Output_BlinkState_dygi = BlinkOff;
  App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
  App_Model_DW.Input_OPT_b_WPCPhoneExist__gxll = Off;
  App_Model_DW.Input_OPT_b_WPCPhoneExist__mct5 = Off;
  App_Model_DW.WPC2IndCmdState_prev = WPC2IndCmdState__Default;
  App_Model_DW.WPC2IndCmdState_start = WPC2IndCmdState__Default;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_EV' */
  App_Model_DW.Input_OPT_GearPosSta_prev_ki4t = GearPos_P;
  App_Model_DW.Input_OPT_GearPosSta_start_n44n = GearPos_P;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_EV' */

  /* SystemInitialize for IfAction SubSystem: '<S220>/nonNFC_ICE' */
  App_Model_DW.b_DrvDrSw_prev_h4if = Off;
  App_Model_DW.b_DrvDrSw_start_drnb = Off;

  /* End of SystemInitialize for SubSystem: '<S220>/nonNFC_ICE' */
  /* End of SystemInitialize for SubSystem: '<S220>/NFC_EV' */

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig = WPCWarningOff;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_pov1 = BlinkOff;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_kyig = Off;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_nwkh = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_gmt2 = Off;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_b5rk = Off;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_e0fo = Off;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_gcjy = Off;

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_jjhc = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_nv40 = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_nt21 = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S220>/Merge' */
  *rty_MainOut_Sig_pg4m = Off;
}

/* System reset for atomic system: '<S20>/WPC_MainControl_Function' */
void WPC_MainControl_Func_klre_Reset(void)
{
  /* SystemReset for Chart: '<S220>/Chart' */
  App_Model_Chart_Reset(&App_Model_B.MainContMode_fjp0, &App_Model_DW.sf_Chart_psff);
}

/* Output and update for atomic system: '<S20>/WPC_MainControl_Function' */
void A_WPC_MainControl_Function_e3ud(Bool rtu_Main_InSig, Bool rtu_Main_InSig_gmt2, Bool rtu_Main_InSig_b5rk, C_WPCOnOffNvalueSet rtu_Main_InSig_e0fo, Bool rtu_Main_InSig_gcjy, Bool
  rtu_Main_InSig_jjhc, Bool rtu_Main_InSig_nv40, Bool rtu_Main_InSig_nt21, DeviceState rtu_Main_InSig_pg4m, WPCStatus rtu_Main_InSig_pov1, Bool rtu_Main_InSig_kyig, WPCIndUSMState rtu_Main_InSig_nwkh,
  Bool rtu_Main_InSig_htzs, WPC2IndCmdState rtu_Main_InSig_n4dm, GearPosSta rtu_Main_InSig_jgrv, C_WPCWarning rtu_Main_InSig_lhyq, Bool rtu_Main_InSig_m0ue, Bool rtu_Main_InSig_gspt, C_WPCWarning
  *rty_MainOut_Sig, Bool *rty_MainOut_Sig_gmt2, Bool *rty_MainOut_Sig_b5rk, Bool *rty_MainOut_Sig_e0fo, Bool *rty_MainOut_Sig_gcjy, uint16 *rty_MainOut_Sig_jjhc, uint16 *rty_MainOut_Sig_nv40, uint16
  *rty_MainOut_Sig_nt21, Bool *rty_MainOut_Sig_pg4m, BlinkState *rty_MainOut_Sig_pov1, Bool *rty_MainOut_Sig_kyig, uint16 *rty_MainOut_Sig_nwkh)
{
  /* Chart: '<S220>/Chart' */
  App_Model_Chart(rtu_Main_InSig_m0ue, rtu_Main_InSig_gspt, &App_Model_B.MainContMode_fjp0, &App_Model_DW.sf_Chart_psff);

  /* SwitchCase: '<S220>/Switch Case1' */
  switch (App_Model_B.MainContMode_fjp0) {
   case nonNFC_ICE:
    {
      /* Outputs for IfAction SubSystem: '<S220>/nonNFC_ICE' incorporates:
       *  ActionPort: '<S402>/ActionPort'
       */
      /* Chart: '<S402>/WPC2_MainControl2_250507' */
      App_Model_DW.sfEvent_g0by = (sint32)App_Model_CALL_EVENT_eki3;
      App_Model_DW.b_WPCPhoneExist_prev_hngm = App_Model_DW.b_WPCPhoneExist_start_mymr;
      App_Model_DW.b_WPCPhoneExist_start_mymr = rtu_Main_InSig_nt21;
      App_Model_DW.C_DrvDrSw_prev_a1mt = App_Model_DW.C_DrvDrSw_start_hwlv;
      App_Model_DW.C_DrvDrSw_start_hwlv = rtu_Main_InSig_nv40;
      App_Model_DW.C_AstDrSw_prev_n4pb = App_Model_DW.C_AstDrSw_start_a3od;
      App_Model_DW.C_AstDrSw_start_a3od = rtu_Main_InSig_jjhc;
      App_Model_DW.WPC2IndCmdState_prev_dtts = App_Model_DW.WPC2IndCmdState_start_jjne;
      App_Model_DW.WPC2IndCmdState_start_jjne = rtu_Main_InSig_n4dm;
      App_Model_DW.L_IGN1_IN_prev_hgcq = App_Model_DW.L_IGN1_IN_start_pbim;
      App_Model_DW.L_IGN1_IN_start_pbim = rtu_Main_InSig_kyig;
      if ((uint32)App_Model_DW.is_active_c40_MainControl_Lib == 0U) {
        Bool tmp_0;
        App_Model_DW.b_WPCPhoneExist_prev_hngm = rtu_Main_InSig_nt21;
        App_Model_DW.C_DrvDrSw_prev_a1mt = rtu_Main_InSig_nv40;
        App_Model_DW.C_AstDrSw_prev_n4pb = rtu_Main_InSig_jjhc;
        App_Model_DW.WPC2IndCmdState_prev_dtts = rtu_Main_InSig_n4dm;
        App_Model_DW.L_IGN1_IN_prev_hgcq = rtu_Main_InSig_kyig;
        App_Model_DW.is_active_c40_MainControl_Lib = 1U;
        App_Model_DW.is_active_MainControl_ptwm = 1U;
        App_Model_DW.is_MainControl_dd3w = App_Mod_IN_WPCMode_Disable_cyvt;
        enter_atomic_WPCMode_Disab_iqu4();
        tmp_0 = App_Model_DW.L_IGN1_IN_start_pbim;
        if ((App_Model_DW.L_IGN1_IN_prev_hgcq != tmp_0) && ((uint32)tmp_0 == Off)) {
          sint32 f_previousEvent;
          App_Model_DW.is_WPCMode_Disable_maoa = Ap_IN_LeavingPhone_Warning_ji1s;
          f_previousEvent = App_Model_DW.sfEvent_g0by;
          App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_PhoneWar_n1mt;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
            Tick_Timer_PhoneWarningChe_cc3i();
          }

          App_Model_DW.sfEvent_g0by = f_previousEvent;
          App_Mo_Function_WPCWarning_anx5(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
          App_Model_B.b_PhnLeftChk_Enable_pm4r = On;
        } else {
          App_Model_DW.is_WPCMode_Disable_maoa = IN_LeavingPhone_NoWarning_dyop;
        }

        App_Model_DW.is_active_Tick_Timer_Phone_g4qp = 1U;
        enter_internal_Tick_Timer__mysx();
        App_Model_DW.is_active_Tick_Timer_Phone_nbqp = 1U;
        enter_internal_Tick_Timer__poh4();
        App_Model_DW.is_active_Tick_Timer_Phone_hytt = 1U;
        enter_internal_Tick_Timer__mz1h();
        App_Model_DW.is_active_Tick_Timer_Warni_hwpi = 1U;
        enter_internal_Tick_Timer__nbtx();
        App_Model_DW.is_active_Tick_Timer_Amber_c1uf = 1U;
        enter_internal_Tick_Timer__kdnl();
        App_Model_DW.is_active_Tick_Timer_Amber_eu2r = 1U;
        enter_internal_Tick_Timer__hqxq();
        App_Model_DW.is_active_Tick_Timer_PhnLe_c01w = 1U;
        enter_internal_Tick_Timer__fi5q();
      } else {
        if ((uint32)App_Model_DW.is_active_MainControl_ptwm != 0U) {
          switch (App_Model_DW.is_MainControl_dd3w) {
           case App_Mod_IN_WPCMode_Disable_cyvt:
            App_Model_B.b_FANModeCmd_evyn = Off;

            /* 1. */
            if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
              if ((uint32)App_Model_DW.is_WPCMode_Disable_maoa == Ap_IN_LeavingPhone_Warning_ji1s) {
                App_Model_DW.b_WarnClearEnable_lyus = Off;
                App_Model_B.b_PhnLeftChk_Enable_pm4r = Off;
                App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneLe_ftby;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_g4qp != 0U) {
                  App_M_Tick_Timer_PhoneLeft_mgtt();
                }

                App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneWa_hotu;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
                  Tick_Timer_PhoneWarningChe_cc3i();
                }

                App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
                  Tick_Timer_PhoneReminderCh_dizt();
                }

                App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_Warning_niui;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_hwpi != 0U) {
                  Tick_Timer_WarningComplete_nw2l();
                }

                App_Model_DW.sfEvent_g0by = -1;
                App_Model_DW.is_WPCMode_Disable_maoa = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
              } else {
                App_Model_DW.is_WPCMode_Disable_maoa = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
              }

              App_Model_DW.is_MainControl_dd3w = App_Mode_IN_WPCMode_Enable_jcmy;
              App_Model_DW.is_WPCMode_Enable_nczh = App_Model_IN_WPCMode_Stop_aynr;
              App_Model_B.b_GreenINDCmd_otki = Off;

              /* b_ROHMOperCmd = Off /_ Non GFS _/ */
              App_Model_B.b_ChargingEnable_ith1 = Off;

              /* 1. */
              if ((uint32)rtu_Main_InSig_gcjy == On) {
                App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_WPCStop_TempErr_n0yp;
                App_Model_B.C_WPCWarning_bs3s = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.BlinkState_gx2f = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
                App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

                /*  Non GFS  */
                App_Model_B.b_BlinkState_pir3 = On;
              } else {
                App_Model_DW.is_WPCMode_Stop_n5gl = App__IN_WPCStop_NotTempErr_ccgp;
                App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                App_Model_B.b_AmberINDCmd_a4kq = Off;
              }
            } else if ((uint32)App_Model_DW.is_WPCMode_Disable_maoa == Ap_IN_LeavingPhone_Warning_ji1s) {
              App_Mo_Function_WPCWarning_anx5(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
            } else {
              /* no actions */
            }
            break;

           case App_Mode_IN_WPCMode_Enable_jcmy:
            {
              /* 1. */
              if ((uint32)rtu_Main_InSig_pov1 == ModeOff) {
                Bool tmp_0;
                switch (App_Model_DW.is_WPCMode_Enable_nczh) {
                 case App_Model_IN_WPCMode_Run_ildf:
                  exit_internal_WPCMode_Run_a4zn();
                  App_Model_DW.is_WPCMode_Enable_nczh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                  break;

                 case App_Model_IN_WPCMode_Stop_aynr:
                  exit_internal_WPCMode_Stop_kaxj();
                  App_Model_DW.is_WPCMode_Enable_nczh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                  break;

                 default:
                  /* no actions */
                  break;
                }

                /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
                App_Model_B.b_ChargingEnable_ith1 = Off;
                App_Model_DW.is_MainControl_dd3w = App_Mod_IN_WPCMode_Disable_cyvt;
                enter_atomic_WPCMode_Disab_iqu4();
                tmp_0 = App_Model_DW.L_IGN1_IN_start_pbim;
                if ((App_Model_DW.L_IGN1_IN_prev_hgcq != tmp_0) && ((uint32)tmp_0 == Off)) {
                  sint32 f_previousEvent;
                  App_Model_DW.is_WPCMode_Disable_maoa = Ap_IN_LeavingPhone_Warning_ji1s;
                  f_previousEvent = App_Model_DW.sfEvent_g0by;
                  App_Model_DW.sfEvent_g0by = (sint32)event_Start_Timer_PhoneWar_n1mt;
                  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
                    Tick_Timer_PhoneWarningChe_cc3i();
                  }

                  App_Model_DW.sfEvent_g0by = f_previousEvent;
                  App_Mo_Function_WPCWarning_anx5(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
                  App_Model_B.b_PhnLeftChk_Enable_pm4r = On;
                } else {
                  App_Model_DW.is_WPCMode_Disable_maoa = IN_LeavingPhone_NoWarning_dyop;
                }
              } else {
                switch (App_Model_DW.is_WPCMode_Enable_nczh) {
                 case App_Model_IN_WPCMode_Run_ildf:
                  App_Model_WPCMode_Run_cecy(rtu_Main_InSig, rtu_Main_InSig_gmt2, rtu_Main_InSig_b5rk, rtu_Main_InSig_gcjy, rtu_Main_InSig_pg4m, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
                  break;

                 case App_Model_IN_WPCMode_Stop_aynr:
                  App_Model_B.b_FANModeCmd_evyn = Off;
                  if (((uint32)rtu_Main_InSig_pg4m == Full_Charge) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
                       rtu_Main_InSig_b5rk == Off)) {
                    exit_internal_WPCMode_Stop_kaxj();
                    App_Model_DW.is_WPCMode_Enable_nczh = App_Model_IN_WPCMode_Run_ildf;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    App_Model_B.b_ChargingEnable_ith1 = On;
                    App_Model_DW.is_WPCMode_Run_gdr3 = IN_WPCRun_ChargingComplete_jydm;
                    App_Model_B.C_WPCWarning_bs3s = Charging_Complete;

                    /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                    App_Model_B.b_FANModeCmd_evyn = On;
                    App_Model_B.b_GreenINDCmd_otki = On;
                    App_Model_B.b_AmberINDCmd_a4kq = Off;
                  } else if (((uint32)rtu_Main_InSig_pg4m == Charging) && ((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_gcjy == Off) && ((uint32)
                              rtu_Main_InSig_b5rk == Off)) {
                    exit_internal_WPCMode_Stop_kaxj();
                    App_Model_DW.is_WPCMode_Enable_nczh = App_Model_IN_WPCMode_Run_ildf;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    App_Model_B.b_ChargingEnable_ith1 = On;
                    App_Model_DW.is_WPCMode_Run_gdr3 = App_Mod_IN_WPCRun_Charging_aref;
                    App_Model_B.C_WPCWarning_bs3s = PhoneCharging;

                    /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                    App_Model_B.b_FANModeCmd_evyn = On;
                    Function_ChargingINDColor_nkrs(rtu_Main_InSig_nwkh);
                  } else {
                    switch (App_Model_DW.is_WPCMode_Stop_n5gl) {
                     case App__IN_WPCStop_NotTempErr_ccgp:
                      /* 1. */
                      if ((uint32)rtu_Main_InSig_gcjy == On) {
                        App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_WPCStop_TempErr_n0yp;
                        App_Model_B.C_WPCWarning_bs3s = Charging_error;

                        /* b_WPCWarn = Charging_error 8차 LFRollBack */
                        App_Model_B.BlinkState_gx2f = BlinkOff;
                        App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
                        App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);

                        /*  Non GFS  */
                        App_Model_B.b_BlinkState_pir3 = On;

                        /* 2. */
                      } else if (((uint32)rtu_Main_InSig == Off) && ((uint32)rtu_Main_InSig_gmt2 == Off) && ((uint32)rtu_Main_InSig_b5rk == Off)) {
                        App_Model_DW.is_WPCMode_Stop_n5gl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                        App_Model_DW.is_WPCMode_Enable_nczh = App_Model_IN_WPCMode_Run_ildf;

                        /* b_ROHMOperCmd = On /_ Non GFS _/ */
                        App_Model_B.b_ChargingEnable_ith1 = On;
                        App_Model_DW.is_WPCMode_Run_gdr3 = App_Mode_IN_WPCRun_Standby_mdky;
                        App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

                        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                        App_Model_B.b_GreenINDCmd_otki = Off;
                        App_Model_B.b_AmberINDCmd_a4kq = Off;
                      } else {
                        /* no actions */
                      }
                      break;

                     case App_Mod_IN_WPCStop_TempErr_n0yp:
                      /* 1. */
                      if ((uint32)rtu_Main_InSig_gcjy == Off) {
                        App_Model_B.BlinkState_gx2f = BlinkOff;
                        App_Model_DW.Counter_BlinkCnt_f1ey = 0U;
                        App_Model_DW.sfEvent_g0by = (sint32)event_Cancel_Timer_AmberIN_fgf5;
                        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
                          App_Tick_Timer_AmberINDBlk_bgbj();
                        }

                        App_Model_DW.sfEvent_g0by = -1;

                        /*  Non GFS  */
                        App_Model_B.b_BlinkState_pir3 = Off;
                        App_Model_DW.is_WPCMode_Stop_n5gl = App__IN_WPCStop_NotTempErr_ccgp;
                        App_Model_B.C_WPCWarning_bs3s = WPCWarningOff;

                        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                        App_Model_B.b_AmberINDCmd_a4kq = Off;
                      } else {
                        App_Function_LEDErrorBlink_jeob(rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
                      }
                      break;

                     default:
                      /* no actions */
                      break;
                    }
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

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_g4qp != 0U) {
          App_M_Tick_Timer_PhoneLeft_mgtt();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nbqp != 0U) {
          Tick_Timer_PhoneWarningChe_cc3i();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_hytt != 0U) {
          Tick_Timer_PhoneReminderCh_dizt();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_hwpi != 0U) {
          Tick_Timer_WarningComplete_nw2l();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_c1uf != 0U) {
          App_Tick_Timer_AmberINDBlk_bgbj();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_eu2r != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_hmqx();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhnLe_c01w != 0U) {
          Tick_Timer_PhnLeftChatteri_b3cl();
        }
      }

      /* End of Chart: '<S402>/WPC2_MainControl2_250507' */

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig = App_Model_B.C_WPCWarning_bs3s;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_gmt2 = App_Model_B.b_FANModeCmd_evyn;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_kyig = App_Model_B.b_PhnLeftChk_Enable_pm4r;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_nwkh = App_Model_ConstB.b_Timer_WarningType_mfz2gjn;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_b5rk = App_Model_B.b_GreenINDCmd_otki;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_e0fo = App_Model_B.b_AmberINDCmd_a4kq;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_gcjy = App_Model_B.b_BlinkState_pir3;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_jjhc = App_Model_B.b_Timer_PhoneReminderCheck_btkg;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_nv40 = App_Model_B.b_Timer_PhoneWarningCheck_bml0;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_nt21 = App_Model_B.b_Timer_WarningComplete_oufu;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_pg4m = App_Model_B.b_ChargingEnable_ith1;

      /* SignalConversion generated from: '<S402>/nonNFC_nonEV' */
      *rty_MainOut_Sig_pov1 = App_Model_B.BlinkState_gx2f;

      /* End of Outputs for SubSystem: '<S220>/nonNFC_ICE' */
    }
    break;

   case nonNFC_EV:
    {
      /* Outputs for IfAction SubSystem: '<S220>/nonNFC_EV' incorporates:
       *  ActionPort: '<S401>/ActionPort'
       */
      /* Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */
      App_Model_DW.sfEvent_cpiu = (sint32)App_Model_CALL_EVENT_eki3;
      App_Model_DW.Input_OPT_b_WPCPhoneExist__asus = App_Model_DW.Input_OPT_b_WPCPhoneExist__igwe;
      App_Model_DW.Input_OPT_b_WPCPhoneExist__igwe = rtu_Main_InSig_nt21;
      App_Model_DW.WPC2IndCmdState_prev_eusn = App_Model_DW.WPC2IndCmdState_start_nyja;
      App_Model_DW.WPC2IndCmdState_start_nyja = rtu_Main_InSig_n4dm;
      App_Model_DW.Input_OPT_GearPosSta_prev_bpse = App_Model_DW.Input_OPT_GearPosSta_start_djgk;
      App_Model_DW.Input_OPT_GearPosSta_start_djgk = rtu_Main_InSig_jgrv;
      App_Model_DW.b_DrvDrSw_prev_ii3v = App_Model_DW.b_DrvDrSw_start_e0qz;
      App_Model_DW.b_DrvDrSw_start_e0qz = rtu_Main_InSig_nv40;
      if ((uint32)App_Model_DW.is_active_c71_MainControl_Lib == 0U) {
        App_Model_DW.Input_OPT_b_WPCPhoneExist__asus = rtu_Main_InSig_nt21;
        App_Model_DW.WPC2IndCmdState_prev_eusn = rtu_Main_InSig_n4dm;
        App_Model_DW.Input_OPT_GearPosSta_prev_bpse = rtu_Main_InSig_jgrv;
        App_Model_DW.b_DrvDrSw_prev_ii3v = rtu_Main_InSig_nv40;
        App_Model_DW.is_active_c71_MainControl_Lib = 1U;
        App_Model_DW.is_active_MainControl_nmbq = 1U;
        App_Model_DW.is_MainControl_aanr = App_Model_IN_WPCMode_Init_nxhy;
        App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_BlinkState_kepa = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_poku = 0U;
        App_Model_DW.b_WarnClearEnable_f4qc = Off;

        /* b_ChargingEnable = 8차 적용 삭제 */
        App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_dyzl = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_kimn = Off;

        /* Nidec */
        App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
          App_M_Tick_Timer_PhoneLeft_c2km();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneWa_ataa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
          Tick_Timer_PhoneWarningChe_pom4();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_dez2;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
          Tick_Timer_WarningComplete_bggd();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_as5n;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
          Tick_Timer_WarningTypeChec_lutt();
        }

        App_Model_DW.sfEvent_cpiu = -1;
        App_Model_DW.is_active_Tick_Timer_Phone_kzfg = 1U;
        enter_internal_Tick_Timer__nlr0();
        App_Model_DW.is_active_Tick_Timer_Phone_lijn = 1U;
        enter_internal_Tick_Timer__gq2v();
        App_Model_DW.is_active_Tick_Timer_Warni_plve = 1U;
        enter_internal_Tick_Timer__dzgk();
        App_Model_DW.is_active_Tick_Timer_Amber_bojy = 1U;
        enter_internal_Tick_Timer__o1rh();
        App_Model_DW.is_active_Tick_Timer_Warni_empn = 1U;
        enter_internal_Tick_Timer__i2ff();
        App_Model_DW.is_active_Tick_Timer_Amber_b43o = 1U;
        enter_internal_Tick_Timer__cxi4();
      } else {
        if ((uint32)App_Model_DW.is_active_MainControl_nmbq != 0U) {
          switch (App_Model_DW.is_MainControl_aanr) {
           case App_Mod_IN_WPCMode_Disable_cyvt:
            {
              App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;

              /* 1. */
              if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
                if ((uint32)App_Model_DW.is_WPCMode_Disable_keqj == App_Model_IN_WPCMode_Off_nufv) {
                  if ((uint32)App_Model_DW.is_WPCMode_Off_mguh == Ap_IN_LeavingPhone_Warning_ji1s) {
                    /* Nidec */
                    App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
                    App_Model_DW.is_WPCMode_Off_mguh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                  } else {
                    App_Model_DW.is_WPCMode_Off_mguh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                  }

                  App_Model_DW.is_WPCMode_Disable_keqj = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                } else {
                  App_Model_DW.is_WPCMode_Disable_keqj = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                }

                App_Model_DW.b_WarnClearEnable_f4qc = Off;
                App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
                  App_M_Tick_Timer_PhoneLeft_c2km();
                }

                App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_PhoneWa_ataa;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
                  Tick_Timer_PhoneWarningChe_pom4();
                }

                App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_dez2;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
                  Tick_Timer_WarningComplete_bggd();
                }

                App_Model_DW.sfEvent_cpiu = (sint32)event_Cancel_Timer_Warning_as5n;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
                  Tick_Timer_WarningTypeChec_lutt();
                }

                App_Model_DW.sfEvent_cpiu = -1;
                App_Model_DW.is_MainControl_aanr = App_Mode_IN_WPCMode_Enable_jcmy;
                enter_internal_WPCMode_Ena_oryk(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
              } else {
                switch (App_Model_DW.is_WPCMode_Disable_keqj) {
                 case App_Model_IN_WPCMode_NFC_eleo:
                  {
                    GearPosSta tmp;

                    /* 1. */
                    tmp = App_Model_DW.Input_OPT_GearPosSta_start_djgk;
                    if (((uint32)rtu_Main_InSig_pov1 == ModeOff) || ((App_Model_DW.Input_OPT_GearPosSta_prev_bpse != tmp) && ((uint32)tmp == GearPos_P))) {
                      /* Nide */
                      App_Model_DW.is_WPCMode_Disable_keqj = App_Model_IN_WPCMode_Off_nufv;
                      enter_internal_WPCMode_Off_mwtd(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_jgrv);
                    }
                  }
                  break;

                 case App_Model_IN_WPCMode_Off_nufv:
                  {
                    /* 1. */
                    if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
                      if ((uint32)App_Model_DW.is_WPCMode_Off_mguh == Ap_IN_LeavingPhone_Warning_ji1s) {
                        App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

                        /* Nidec */
                        App_Model_B.b_PhnLeftChk_Enable_hhyt = Off;
                        App_Model_DW.is_WPCMode_Off_mguh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                      } else {
                        App_Model_DW.is_WPCMode_Off_mguh = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                      }

                      App_Model_DW.is_WPCMode_Disable_keqj = App_Model_IN_WPCMode_NFC_eleo;
                      A_enter_atomic_WPCMode_NFC_exg2();
                    } else {
                      switch (App_Model_DW.is_WPCMode_Off_mguh) {
                       case IN_LeavingPhone_NoWarning_dyop:
                        {
                          GearPosSta tmp;
                          tmp = App_Model_DW.Input_OPT_GearPosSta_start_djgk;
                          if ((App_Model_DW.Input_OPT_GearPosSta_prev_bpse != tmp) && ((uint32)tmp == GearPos_P)) {
                            App_Model_DW.is_WPCMode_Off_mguh = Ap_IN_LeavingPhone_Warning_ji1s;
                            App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
                            App_Model_DW.b_WarnClearEnable_f4qc = Off;
                            App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningT_nkmg;
                            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
                              Tick_Timer_WarningTypeChec_lutt();
                            }

                            App_Model_DW.sfEvent_cpiu = -1;
                            App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

                            /* Nidec */
                            App_Model_B.b_PhnLeftChk_Enable_hhyt = On;
                          }
                        }
                        break;

                       case Ap_IN_LeavingPhone_Warning_ji1s:
                        {
                          GearPosSta tmp;
                          tmp = App_Model_DW.Input_OPT_GearPosSta_start_djgk;
                          if ((App_Model_DW.Input_OPT_GearPosSta_prev_bpse != tmp) && ((uint32)tmp == GearPos_P)) {
                            App_Model_B.Output_WPCWarning_pw1g = WPCWarningOff;

                            /* Nidec */
                            App_Model_DW.is_WPCMode_Off_mguh = Ap_IN_LeavingPhone_Warning_ji1s;
                            App_Model_DW.PhoneLeftWrnType_elrn = PhoneLeftWrnType__Default;
                            App_Model_DW.b_WarnClearEnable_f4qc = Off;
                            App_Model_DW.sfEvent_cpiu = (sint32)event_Start_Timer_WarningT_nkmg;
                            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
                              Tick_Timer_WarningTypeChec_lutt();
                            }

                            App_Model_DW.sfEvent_cpiu = -1;
                            App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

                            /* Nidec */
                            App_Model_B.b_PhnLeftChk_Enable_hhyt = On;
                          } else {
                            App_Mo_Function_WPCWarning_hcv4(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
                          }
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
            }
            break;

           case App_Mode_IN_WPCMode_Enable_jcmy:
            App_Model_WPCMode_Enable_kr2m(rtu_Main_InSig, rtu_Main_InSig_gmt2, rtu_Main_InSig_b5rk, rtu_Main_InSig_e0fo, rtu_Main_InSig_gcjy, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21,
              rtu_Main_InSig_pg4m, rtu_Main_InSig_pov1, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs, rtu_Main_InSig_jgrv);
            break;

           case App_Model_IN_WPCMode_Init_nxhy:
            App_Model_B.Output_OPT_b_FANModeCmd_ll4e = Off;

            /* 1. */
            if ((uint32)rtu_Main_InSig_pov1 != WPCMode) {
              App_Model_DW.is_MainControl_aanr = App_Mod_IN_WPCMode_Disable_cyvt;
              enter_atomic_WPCMode_Disab_emnh();

              /* 1. */
              if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
                App_Model_DW.is_WPCMode_Disable_keqj = App_Model_IN_WPCMode_NFC_eleo;
                A_enter_atomic_WPCMode_NFC_exg2();
              } else {
                App_Model_DW.is_WPCMode_Disable_keqj = App_Model_IN_WPCMode_Off_nufv;
                enter_internal_WPCMode_Off_mwtd(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_jgrv);
              }

              /* 2 */
            } else if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
              App_Model_DW.is_MainControl_aanr = App_Mode_IN_WPCMode_Enable_jcmy;
              enter_internal_WPCMode_Ena_oryk(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
            } else {
              /* no actions */
            }
            break;

           default:
            /* no actions */
            break;
          }
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kzfg != 0U) {
          App_M_Tick_Timer_PhoneLeft_c2km();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_lijn != 0U) {
          Tick_Timer_PhoneWarningChe_pom4();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_plve != 0U) {
          Tick_Timer_WarningComplete_bggd();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_bojy != 0U) {
          App_Tick_Timer_AmberINDBlk_czhp();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_empn != 0U) {
          Tick_Timer_WarningTypeChec_lutt();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_b43o != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_ecjj();
        }
      }

      /* End of Chart: '<S401>/WPC2_MainControl2_EV_250328_HMC' */

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig = App_Model_B.Output_WPCWarning_pw1g;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_gmt2 = App_Model_B.Output_OPT_b_FANModeCmd_ll4e;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_kyig = App_Model_B.b_PhnLeftChk_Enable_hhyt;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_nwkh = App_Model_B.b_Timer_WarningTypeCheck_c4cy;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_b5rk = App_Model_B.Output_OPT_b_GreenINDCmd_dyzl;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_e0fo = App_Model_B.Output_OPT_b_AmberINDCmd_kimn;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_gcjy = App_Model_B.Output_OPT_b_BlinkState_nxwe;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_jjhc = App_Model_ConstB.b_Timer_PhoneRemind_fuw5aot;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_nv40 = App_Model_B.b_Timer_PhoneWarningCheck_jt3z;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_nt21 = App_Model_B.b_Timer_WarningComplete_n0c3;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_pg4m = App_Model_B.b_ChargingEnable_iqlw;

      /* SignalConversion generated from: '<S401>/nonNFC_EV' */
      *rty_MainOut_Sig_pov1 = App_Model_B.Output_BlinkState_kepa;

      /* End of Outputs for SubSystem: '<S220>/nonNFC_EV' */
    }
    break;

   case NFC_ICE:
    /* Outputs for IfAction SubSystem: '<S220>/NFC_ICE' incorporates:
     *  ActionPort: '<S400>/ActionPort'
     */
    /* Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */
    App_Model_DW.sfEvent_cbxk = (sint32)App_Model_CALL_EVENT_eki3;
    App_Model_DW.b_WPCPhoneExist_prev_njde = App_Model_DW.b_WPCPhoneExist_start_k4jj;
    App_Model_DW.b_WPCPhoneExist_start_k4jj = rtu_Main_InSig_nt21;
    App_Model_DW.WPC2IndCmdState_prev_gzvs = App_Model_DW.WPC2IndCmdState_start_jkee;
    App_Model_DW.WPC2IndCmdState_start_jkee = rtu_Main_InSig_n4dm;
    App_Model_DW.L_IGN1_IN_prev_eaae = App_Model_DW.L_IGN1_IN_start_lebj;
    App_Model_DW.L_IGN1_IN_start_lebj = rtu_Main_InSig_kyig;
    if ((uint32)App_Model_DW.is_active_c52_MainControl_Lib == 0U) {
      App_Model_DW.b_WPCPhoneExist_prev_njde = rtu_Main_InSig_nt21;
      App_Model_DW.WPC2IndCmdState_prev_gzvs = rtu_Main_InSig_n4dm;
      App_Model_DW.L_IGN1_IN_prev_eaae = rtu_Main_InSig_kyig;
      App_Model_DW.is_active_c52_MainControl_Lib = 1U;
      App_Model_DW.is_active_MainControl_dj5b = 1U;
      App_Model_DW.is_MainControl_ct4w = App_Model_IN_WPCMode_Init_nxhy;
      App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
      App_Model_B.BlinkState_izow = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_fhcr = 0U;
      App_Model_DW.b_WarnClearEnable_nzmj = Off;
      App_Model_B.b_FANModeCmd_bint = Off;
      App_Model_B.b_GreenINDCmd_mwno = Off;
      App_Model_B.b_AmberINDCmd_m25s = Off;
      App_Model_B.b_ChargingEnable_ovqe = Off;
      App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneLe_ftby;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
        App_M_Tick_Timer_PhoneLeft_jzcf();
      }

      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneWa_hotu;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
        Tick_Timer_PhoneWarningChe_lzxg();
      }

      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
        Tick_Timer_PhoneReminderCh_f2nt();
      }

      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_Warning_niui;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
        Tick_Timer_WarningComplete_njjk();
      }

      App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_AmberIN_fgf5;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
        App_Tick_Timer_AmberINDBlk_fqxk();
      }

      App_Model_DW.sfEvent_cbxk = -1;
      App_Model_DW.is_active_Tick_Timer_Phone_pxif = 1U;
      enter_internal_Tick_Timer__eqcb();
      App_Model_DW.is_active_Tick_Timer_Phone_ci1r = 1U;
      enter_internal_Tick_Timer__g2zg();
      App_Model_DW.is_active_Tick_Timer_Phone_j2ai = 1U;
      enter_internal_Tick_Timer__mm4n();
      App_Model_DW.is_active_Tick_Timer_Warni_ln5u = 1U;
      enter_internal_Tick_Timer__akvt();
      App_Model_DW.is_active_Tick_Timer_Amber_ko34 = 1U;
      enter_internal_Tick_Timer__pcsj();
      App_Model_DW.is_active_Tick_Timer_Amber_kdsx = 1U;
      enter_internal_Tick_Timer__fsrs();
      App_Model_DW.is_active_Tick_Timer_CardINDBlk = 1U;
      enter_internal_Tick_Timer__jdfo();
    } else {
      if ((uint32)App_Model_DW.is_active_MainControl_dj5b != 0U) {
        switch (App_Model_DW.is_MainControl_ct4w) {
         case App_Mod_IN_WPCMode_Disable_cyvt:
          App_Model_B.b_FANModeCmd_bint = Off;

          /* 1. */
          if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
            if ((uint32)App_Model_DW.is_WPCMode_Disable_kogf == App_Model_IN_WPCMode_Off_nufv) {
              if ((uint32)App_Model_DW.is_WPCMode_Off_pxad == Ap_IN_LeavingPhone_Warning_ji1s) {
                App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
                App_Model_DW.is_WPCMode_Off_pxad = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
              } else {
                App_Model_DW.is_WPCMode_Off_pxad = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
              }

              App_Model_DW.is_WPCMode_Disable_kogf = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
            } else {
              App_Model_DW.is_WPCMode_Disable_kogf = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
            }

            App_Model_DW.b_WarnClearEnable_nzmj = Off;
            App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneLe_ftby;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
              App_M_Tick_Timer_PhoneLeft_jzcf();
            }

            App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneWa_hotu;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
              Tick_Timer_PhoneWarningChe_lzxg();
            }

            App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_PhoneRe_jjf3;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
              Tick_Timer_PhoneReminderCh_f2nt();
            }

            App_Model_DW.sfEvent_cbxk = (sint32)event_Cancel_Timer_Warning_niui;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
              Tick_Timer_WarningComplete_njjk();
            }

            App_Model_DW.sfEvent_cbxk = -1;
            App_Model_DW.is_MainControl_ct4w = App_Mode_IN_WPCMode_Enable_jcmy;
            App_Model_DW.is_WPCMode_Enable_evbg = App_Model_IN_WPCMode_Stop_aynr;
            App_Model_B.b_GreenINDCmd_mwno = Off;

            /* b_ChargingEnable = Off */
            enter_internal_WPCMode_Sto_h1gw(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
          } else {
            switch (App_Model_DW.is_WPCMode_Disable_kogf) {
             case App_Model_IN_WPCMode_NFC_eleo:
              /* 1. */
              if ((uint32)rtu_Main_InSig_pov1 == ModeOff) {
                App_Model_DW.is_WPCMode_Disable_kogf = App_Model_IN_WPCMode_Off_nufv;
                App_Model_DW.is_WPCMode_Off_pxad = IN_LeavingPhone_NoWarning_dyop;
              }
              break;

             case App_Model_IN_WPCMode_Off_nufv:
              /* 1. */
              if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
                if ((uint32)App_Model_DW.is_WPCMode_Off_pxad == Ap_IN_LeavingPhone_Warning_ji1s) {
                  App_Model_B.C_WPCWarning_d4ol = WPCWarningOff;
                  App_Model_B.b_PhnLeftChk_Enable_azgu = Off;
                  App_Model_DW.is_WPCMode_Off_pxad = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                } else {
                  App_Model_DW.is_WPCMode_Off_pxad = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                }

                App_Model_DW.is_WPCMode_Disable_kogf = App_Model_IN_WPCMode_NFC_eleo;
                A_enter_atomic_WPCMode_NFC_jagk();
              } else if ((uint32)App_Model_DW.is_WPCMode_Off_pxad == Ap_IN_LeavingPhone_Warning_ji1s) {
                App_Mo_Function_WPCWarning_n3ee(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
              } else {
                /* no actions */
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
          break;

         case App_Mode_IN_WPCMode_Enable_jcmy:
          App_Model_WPCMode_Enable_lmai(rtu_Main_InSig, rtu_Main_InSig_gmt2, rtu_Main_InSig_b5rk, rtu_Main_InSig_e0fo, rtu_Main_InSig_gcjy, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40,
            rtu_Main_InSig_nt21, rtu_Main_InSig_pg4m, rtu_Main_InSig_pov1, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs, rtu_Main_InSig_lhyq);
          break;

         case App_Model_IN_WPCMode_Init_nxhy:
          App_Model_B.b_FANModeCmd_bint = Off;

          /* 1. */
          if ((uint32)rtu_Main_InSig_pov1 != WPCMode) {
            App_Model_DW.is_MainControl_ct4w = App_Mod_IN_WPCMode_Disable_cyvt;
            enter_atomic_WPCMode_Disab_or5p();
            enter_internal_WPCMode_Dis_o4re(rtu_Main_InSig_e0fo, rtu_Main_InSig_jjhc, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_pov1);

            /* 2 */
          } else if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
            App_Model_DW.is_MainControl_ct4w = App_Mode_IN_WPCMode_Enable_jcmy;
            App_Model_DW.is_WPCMode_Enable_evbg = App_Model_IN_WPCMode_Stop_aynr;
            App_Model_B.b_GreenINDCmd_mwno = Off;

            /* b_ChargingEnable = Off */
            enter_internal_WPCMode_Sto_h1gw(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
          } else {
            /* no actions */
          }
          break;

         default:
          /* no actions */
          break;
        }
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pxif != 0U) {
        App_M_Tick_Timer_PhoneLeft_jzcf();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_ci1r != 0U) {
        Tick_Timer_PhoneWarningChe_lzxg();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_j2ai != 0U) {
        Tick_Timer_PhoneReminderCh_f2nt();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ln5u != 0U) {
        Tick_Timer_WarningComplete_njjk();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ko34 != 0U) {
        App_Tick_Timer_AmberINDBlk_fqxk();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kdsx != 0U) {
        Ap_Tick_Timer_AmberINDBlk2_iopl();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_CardINDBlk != 0U) {
        App__Tick_Timer_CardINDBlk_mju2();
      }
    }

    /* End of Chart: '<S400>/WPC2_MainControl3_CardSync_250522' */

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig = App_Model_B.C_WPCWarning_d4ol;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_gmt2 = App_Model_B.b_FANModeCmd_bint;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_kyig = App_Model_B.b_PhnLeftChk_Enable_azgu;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_nwkh = App_Model_ConstB.b_Timer_WarningTypeC_mfz2gj;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_b5rk = App_Model_B.b_GreenINDCmd_mwno;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_e0fo = App_Model_B.b_AmberINDCmd_m25s;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_gcjy = App_Model_B.b_BlinkState_mtzh;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_jjhc = App_Model_B.b_Timer_PhoneReminderCheck_gvtz;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_nv40 = App_Model_B.b_Timer_PhoneWarningCheck_nhb3;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_nt21 = App_Model_B.b_Timer_WarningComplete_hjex;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_pg4m = App_Model_B.b_ChargingEnable_ovqe;

    /* SignalConversion generated from: '<S400>/NFC_nonEV' */
    *rty_MainOut_Sig_pov1 = App_Model_B.BlinkState_izow;

    /* End of Outputs for SubSystem: '<S220>/NFC_ICE' */
    break;

   case NFC_EV:
    {
      /* Outputs for IfAction SubSystem: '<S220>/NFC_EV' incorporates:
       *  ActionPort: '<S399>/ActionPort'
       */
      /* Chart: '<S399>/WPC2_MainControl_EV_250522' */
      App_Model_DW.sfEvent_ed3e = (sint32)App_Model_CALL_EVENT_eki3;
      App_Model_DW.Input_OPT_b_WPCPhoneExist__gxll = App_Model_DW.Input_OPT_b_WPCPhoneExist__mct5;
      App_Model_DW.Input_OPT_b_WPCPhoneExist__mct5 = rtu_Main_InSig_nt21;
      App_Model_DW.WPC2IndCmdState_prev = App_Model_DW.WPC2IndCmdState_start;
      App_Model_DW.WPC2IndCmdState_start = rtu_Main_InSig_n4dm;
      App_Model_DW.Input_OPT_GearPosSta_prev_ki4t = App_Model_DW.Input_OPT_GearPosSta_start_n44n;
      App_Model_DW.Input_OPT_GearPosSta_start_n44n = rtu_Main_InSig_jgrv;
      App_Model_DW.b_DrvDrSw_prev_h4if = App_Model_DW.b_DrvDrSw_start_drnb;
      App_Model_DW.b_DrvDrSw_start_drnb = rtu_Main_InSig_nv40;
      if ((uint32)App_Model_DW.is_active_c63_MainControl_Lib == 0U) {
        App_Model_DW.Input_OPT_b_WPCPhoneExist__gxll = rtu_Main_InSig_nt21;
        App_Model_DW.WPC2IndCmdState_prev = rtu_Main_InSig_n4dm;
        App_Model_DW.Input_OPT_GearPosSta_prev_ki4t = rtu_Main_InSig_jgrv;
        App_Model_DW.b_DrvDrSw_prev_h4if = rtu_Main_InSig_nv40;
        App_Model_DW.is_active_c63_MainControl_Lib = 1U;
        App_Model_DW.is_active_MainControl_phku = 1U;
        App_Model_DW.is_MainControl_i4ep = App_Model_IN_WPCMode_Init_nxhy;
        App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_BlinkState_dygi = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_jg3b = 0U;
        App_Model_DW.b_WarnClearEnable_bxvw = Off;

        /* b_ChargingEnable = 8차 적용 삭제 */
        App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_muj0 = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_cr22 = Off;

        /* Nidec */
        App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
          App_M_Tick_Timer_PhoneLeft_bizk();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneWa_ataa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
          Tick_Timer_PhoneWarningChe_d40l();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_dez2;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
          Tick_Timer_WarningComplete_poap();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_AmberIN_fgf5;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_as5n;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
          Tick_Timer_WarningTypeChec_j1qx();
        }

        App_Model_DW.sfEvent_ed3e = -1;
        App_Model_DW.is_active_Tick_Timer_Phone_pcac = 1U;
        enter_internal_Tick_Timer__eqt5();
        App_Model_DW.is_active_Tick_Timer_Phone_nkyp = 1U;
        enter_internal_Tick_Timer__afno();
        App_Model_DW.is_active_Tick_Timer_Warni_ghx5 = 1U;
        enter_internal_Tick_Timer__djfr();
        App_Model_DW.is_active_Tick_Timer_Amber_nm31 = 1U;
        enter_internal_Tick_Timer__kc5l();
        App_Model_DW.is_active_Tick_Timer_Warni_l1oa = 1U;
        enter_internal_Tick_Timer__la5p();
        App_Model_DW.is_active_Tick_Timer_Amber_djxt = 1U;
        enter_internal_Tick_Timer__pr3d();
      } else {
        if ((uint32)App_Model_DW.is_active_MainControl_phku != 0U) {
          switch (App_Model_DW.is_MainControl_i4ep) {
           case App_Mod_IN_WPCMode_Disable_cyvt:
            {
              App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;

              /* 1. */
              if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
                if ((uint32)App_Model_DW.is_WPCMode_Disable_mi5f == App_Model_IN_WPCMode_Off_nufv) {
                  if ((uint32)App_Model_DW.is_WPCMode_Off_hfyl == Ap_IN_LeavingPhone_Warning_ji1s) {
                    /* Nidec */
                    App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
                    App_Model_DW.is_WPCMode_Off_hfyl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                  } else {
                    App_Model_DW.is_WPCMode_Off_hfyl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                  }

                  App_Model_DW.is_WPCMode_Disable_mi5f = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                } else {
                  App_Model_DW.is_WPCMode_Disable_mi5f = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                }

                App_Model_DW.b_WarnClearEnable_bxvw = Off;
                App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneLe_n1xi;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
                  App_M_Tick_Timer_PhoneLeft_bizk();
                }

                App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_PhoneWa_ataa;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
                  Tick_Timer_PhoneWarningChe_d40l();
                }

                App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_dez2;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
                  Tick_Timer_WarningComplete_poap();
                }

                App_Model_DW.sfEvent_ed3e = (sint32)event_Cancel_Timer_Warning_as5n;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
                  Tick_Timer_WarningTypeChec_j1qx();
                }

                App_Model_DW.sfEvent_ed3e = -1;
                App_Model_DW.is_MainControl_i4ep = App_Mode_IN_WPCMode_Enable_jcmy;
                enter_internal_WPCMode_Ena_bzqz(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
              } else {
                switch (App_Model_DW.is_WPCMode_Disable_mi5f) {
                 case App_Model_IN_WPCMode_NFC_eleo:
                  {
                    GearPosSta tmp;

                    /* 1. */
                    tmp = App_Model_DW.Input_OPT_GearPosSta_start_n44n;
                    if (((uint32)rtu_Main_InSig_pov1 == ModeOff) || ((App_Model_DW.Input_OPT_GearPosSta_prev_ki4t != tmp) && ((uint32)tmp == GearPos_P))) {
                      /* Nide */
                      App_Model_DW.is_WPCMode_Disable_mi5f = App_Model_IN_WPCMode_Off_nufv;
                      enter_internal_WPCMode_Off_iu3m(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_jgrv);
                    }
                  }
                  break;

                 case App_Model_IN_WPCMode_Off_nufv:
                  {
                    /* 1. */
                    if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
                      if ((uint32)App_Model_DW.is_WPCMode_Off_hfyl == Ap_IN_LeavingPhone_Warning_ji1s) {
                        App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

                        /* Nidec */
                        App_Model_B.b_PhnLeftChk_Enable_ei3s = Off;
                        App_Model_DW.is_WPCMode_Off_hfyl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                      } else {
                        App_Model_DW.is_WPCMode_Off_hfyl = App_Mod_IN_NO_ACTIVE_CHILD_ctxu;
                      }

                      App_Model_DW.is_WPCMode_Disable_mi5f = App_Model_IN_WPCMode_NFC_eleo;
                      A_enter_atomic_WPCMode_NFC_ggnd();
                    } else {
                      switch (App_Model_DW.is_WPCMode_Off_hfyl) {
                       case IN_LeavingPhone_NoWarning_dyop:
                        {
                          GearPosSta tmp;
                          tmp = App_Model_DW.Input_OPT_GearPosSta_start_n44n;
                          if ((App_Model_DW.Input_OPT_GearPosSta_prev_ki4t != tmp) && ((uint32)tmp == GearPos_P)) {
                            App_Model_DW.is_WPCMode_Off_hfyl = Ap_IN_LeavingPhone_Warning_ji1s;
                            App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;
                            App_Model_DW.b_WarnClearEnable_bxvw = Off;
                            App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningT_nkmg;
                            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
                              Tick_Timer_WarningTypeChec_j1qx();
                            }

                            App_Model_DW.sfEvent_ed3e = -1;
                            App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

                            /* Nidec */
                            App_Model_B.b_PhnLeftChk_Enable_ei3s = On;
                          }
                        }
                        break;

                       case Ap_IN_LeavingPhone_Warning_ji1s:
                        {
                          GearPosSta tmp;
                          tmp = App_Model_DW.Input_OPT_GearPosSta_start_n44n;
                          if ((App_Model_DW.Input_OPT_GearPosSta_prev_ki4t != tmp) && ((uint32)tmp == GearPos_P)) {
                            App_Model_B.Output_WPCWarning_lelw = WPCWarningOff;

                            /* Nidec */
                            App_Model_DW.is_WPCMode_Off_hfyl = Ap_IN_LeavingPhone_Warning_ji1s;
                            App_Model_DW.PhoneLeftWrnType_bjkd = PhoneLeftWrnType__Default;
                            App_Model_DW.b_WarnClearEnable_bxvw = Off;
                            App_Model_DW.sfEvent_ed3e = (sint32)event_Start_Timer_WarningT_nkmg;
                            if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
                              Tick_Timer_WarningTypeChec_j1qx();
                            }

                            App_Model_DW.sfEvent_ed3e = -1;
                            App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);

                            /* Nidec */
                            App_Model_B.b_PhnLeftChk_Enable_ei3s = On;
                          } else {
                            App_Mo_Function_WPCWarning_kxrk(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21);
                          }
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
            }
            break;

           case App_Mode_IN_WPCMode_Enable_jcmy:
            App_Model_WPCMode_Enable_a3go(rtu_Main_InSig, rtu_Main_InSig_gmt2, rtu_Main_InSig_e0fo, rtu_Main_InSig_gcjy, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_pg4m,
              rtu_Main_InSig_pov1, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs, rtu_Main_InSig_jgrv, rtu_Main_InSig_lhyq);
            break;

           case App_Model_IN_WPCMode_Init_nxhy:
            App_Model_B.Output_OPT_b_FANModeCmd_hdp3 = Off;

            /* 1. */
            if ((uint32)rtu_Main_InSig_pov1 != WPCMode) {
              App_Model_DW.is_MainControl_i4ep = App_Mod_IN_WPCMode_Disable_cyvt;
              enter_atomic_WPCMode_Disab_diah();

              /* 1. */
              if (((uint32)rtu_Main_InSig_pov1 == NFCMode) || ((uint32)rtu_Main_InSig_pov1 == LPCDMode) || ((uint32)rtu_Main_InSig_pov1 == PICCMode)) {
                App_Model_DW.is_WPCMode_Disable_mi5f = App_Model_IN_WPCMode_NFC_eleo;
                A_enter_atomic_WPCMode_NFC_ggnd();
              } else {
                App_Model_DW.is_WPCMode_Disable_mi5f = App_Model_IN_WPCMode_Off_nufv;
                enter_internal_WPCMode_Off_iu3m(rtu_Main_InSig_e0fo, rtu_Main_InSig_nv40, rtu_Main_InSig_nt21, rtu_Main_InSig_jgrv);
              }

              /* 2 */
            } else if ((uint32)rtu_Main_InSig_pov1 == WPCMode) {
              App_Model_DW.is_MainControl_i4ep = App_Mode_IN_WPCMode_Enable_jcmy;
              enter_internal_WPCMode_Ena_bzqz(rtu_Main_InSig_gcjy, rtu_Main_InSig_nwkh, rtu_Main_InSig_htzs);
            } else {
              /* no actions */
            }
            break;

           default:
            /* no actions */
            break;
          }
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_pcac != 0U) {
          App_M_Tick_Timer_PhoneLeft_bizk();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_nkyp != 0U) {
          Tick_Timer_PhoneWarningChe_d40l();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_ghx5 != 0U) {
          Tick_Timer_WarningComplete_poap();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_nm31 != 0U) {
          App_Tick_Timer_AmberINDBlk_cdeg();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_l1oa != 0U) {
          Tick_Timer_WarningTypeChec_j1qx();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_djxt != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_pqgr();
        }
      }

      /* End of Chart: '<S399>/WPC2_MainControl_EV_250522' */

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig = App_Model_B.Output_WPCWarning_lelw;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_gmt2 = App_Model_B.Output_OPT_b_FANModeCmd_hdp3;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_kyig = App_Model_B.b_PhnLeftChk_Enable_ei3s;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_nwkh = App_Model_B.b_Timer_WarningTypeCheck_k1s5;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_b5rk = App_Model_B.Output_OPT_b_GreenINDCmd_muj0;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_e0fo = App_Model_B.Output_OPT_b_AmberINDCmd_cr22;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_gcjy = App_Model_B.Output_OPT_b_BlinkState_fegv;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_jjhc = App_Model_ConstB.b_Timer_PhoneReminde_fuw5ao;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_nv40 = App_Model_B.b_Timer_PhoneWarningCheck_ep1a;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_nt21 = App_Model_B.b_Timer_WarningComplete_fmqe;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_pg4m = App_Model_B.b_ChargingEnable_anij;

      /* SignalConversion generated from: '<S399>/NFC_EV' */
      *rty_MainOut_Sig_pov1 = App_Model_B.Output_BlinkState_dygi;

      /* End of Outputs for SubSystem: '<S220>/NFC_EV' */
    }
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S220>/Switch Case1' */
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void Tick_Timer_PhnLeftChatteri_bjsy(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhnLeftChattering) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhnLeftC_dpmm) {
      App_Model_DW.is_Tick_Timer_PhnLeftChattering = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_PhnLeft_hwkj) {
        App_Model_DW.is_Tick_Timer_PhnLeftChattering = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_PhnLeftChattering_owvz = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhnLeftChattering_owvz + 1;
        if (((sint32)App_Model_DW.Timer_PhnLeftChattering_owvz + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhnLeftChattering_owvz = (uint16)tmp;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhnLeftC_dpmm) {
          App_Model_DW.Timer_PhnLeftChattering_owvz = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void Tick_Timer_PhoneReminderCh_kfry(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneReminderChec) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhoneRem_jphw) {
      App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_On_g4y5;
      App_Model_DW.b_Timer_PhoneReminderCheck_is_R = On;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_PhoneRe_bamn) {
        App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_PhoneReminderCheck = 0U;
        App_Model_B.b_Timer_PhoneReminderCheck_hhaw = 0U;
        App_Model_DW.b_Timer_PhoneReminderCheck_is_R = Off;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneReminderCheck + 1;
        if (((sint32)App_Model_DW.Timer_PhoneReminderCheck + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneReminderCheck = (uint16)tmp;
        App_Model_B.b_Timer_PhoneReminderCheck_hhaw = App_Model_DW.Timer_PhoneReminderCheck;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhoneRem_jphw) {
          App_Model_DW.Timer_PhoneReminderCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void Tick_Timer_WarningComplete_krdu(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningCompl_mg4r) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_WarningC_gzuk) {
      App_Model_DW.is_Tick_Timer_WarningCompl_mg4r = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_Warning_opqw) {
        App_Model_DW.is_Tick_Timer_WarningCompl_mg4r = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_WarningComplete_jdlj = 0U;
        App_Model_B.b_Timer_WarningComplete_n54s = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningComplete_jdlj + 1;
        if (((sint32)App_Model_DW.Timer_WarningComplete_jdlj + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete_jdlj = (uint16)tmp;
        App_Model_B.b_Timer_WarningComplete_n54s = App_Model_DW.Timer_WarningComplete_jdlj;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_WarningC_gzuk) {
          App_Model_DW.Timer_WarningComplete_jdlj = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void App_M_Tick_Timer_PhoneLeft_gv5q(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft_jafl) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhoneLef_n4dh) {
      App_Model_DW.is_Tick_Timer_PhoneLeft_jafl = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_PhoneLe_fatc) {
        App_Model_DW.is_Tick_Timer_PhoneLeft_jafl = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_PhoneLeft_onnd = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneLeft_onnd + 1;
        if (((sint32)App_Model_DW.Timer_PhoneLeft_onnd + 1) > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft_onnd = (uint8)tmp;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhoneLef_n4dh) {
          App_Model_DW.Timer_PhoneLeft_onnd = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void Tick_Timer_PhoneWarningChe_jngs(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarning_i3dp) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhoneWar_pusf) {
      App_Model_DW.is_Tick_Timer_PhoneWarning_i3dp = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_PhoneWa_mdmw) {
        App_Model_DW.is_Tick_Timer_PhoneWarning_i3dp = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_PhoneWarningCheck_hbn3 = 0U;
        App_Model_B.b_Timer_PhoneWarningCheck_bn3m = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneWarningCheck_hbn3 + 1;
        if (((sint32)App_Model_DW.Timer_PhoneWarningCheck_hbn3 + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck_hbn3 = (uint16)tmp;
        App_Model_B.b_Timer_PhoneWarningCheck_bn3m = App_Model_DW.Timer_PhoneWarningCheck_hbn3;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_PhoneWar_pusf) {
          App_Model_DW.Timer_PhoneWarningCheck_hbn3 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void App_Mo_Function_WPCWarning_h44q(C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_exqx, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli)
{
  /* Outputs for IfAction SubSystem: '<S465>/Subsystem' incorporates:
   *  ActionPort: '<S608>/ActionPort'
   */
  /* SwitchCase: '<S465>/Switch Case2' incorporates:
   *  Chart: '<S608>/RWPC_MainControl2_250507'
   */
  /* 1 */
  if (((uint32)rtu_Main_InSig_gfkd == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck_hbn3 >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_pfli == Off)) ||
      (App_Model_DW.Timer_PhoneLeft_onnd >= ((uint8)50U))) {
    sint32 d_previousEvent;
    App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
    App_Model_DW.b_WarnClearEnable_h2ib = Off;
    App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
    d_previousEvent = App_Model_DW.sfEvent_lj3c;
    App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneLe_fatc;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kep1 != 0U) {
      App_M_Tick_Timer_PhoneLeft_gv5q();
    }

    App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneWa_mdmw;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
      Tick_Timer_PhoneWarningChe_jngs();
    }

    App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneRe_bamn;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
      Tick_Timer_PhoneReminderCh_kfry();
    }

    App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_Warning_opqw;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_cwy4 != 0U) {
      Tick_Timer_WarningComplete_krdu();
    }

    App_Model_DW.sfEvent_lj3c = d_previousEvent;
  } else {
    sint32 d_previousEvent;
    Bool tmp;

    /* 1. */
    tmp = App_Model_DW.b_WPCPhoneExist_start;
    if (((uint32)App_Model_DW.b_WarnClearEnable_h2ib == On) && ((App_Model_DW.b_WPCPhoneExist_prev != tmp) && ((uint32)tmp == Off))) {
      d_previousEvent = App_Model_DW.sfEvent_lj3c;
      App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_PhoneLef_n4dh;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kep1 != 0U) {
        App_M_Tick_Timer_PhoneLeft_gv5q();
      }

      App_Model_DW.sfEvent_lj3c = d_previousEvent;

      /* 1. */
    } else if (((uint32)App_Model_DW.is_Tick_Timer_PhoneLeft_jafl == App_Model_IN_On_g4y5) && ((uint32)rtu_Main_InSig_pfli == On)) {
      d_previousEvent = App_Model_DW.sfEvent_lj3c;
      App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneLe_fatc;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kep1 != 0U) {
        App_M_Tick_Timer_PhoneLeft_gv5q();
      }

      App_Model_DW.sfEvent_lj3c = d_previousEvent;
    } else {
      /* no actions */
    }

    if ((App_Model_DW.Timer_PhoneWarningCheck_hbn3 >= ((uint16)10U)) && (App_Model_DW.Timer_PhoneWarningCheck_hbn3 <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_pfli == On)) {
      App_Model_B.C_WPCWarning_jsvy = Cellphoneonthepad;
      App_Model_DW.b_WarnClearEnable_h2ib = On;
      d_previousEvent = App_Model_DW.sfEvent_lj3c;
      App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneWa_mdmw;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
        Tick_Timer_PhoneWarningChe_jngs();
      }

      App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_PhoneRem_jphw;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
        Tick_Timer_PhoneReminderCh_kfry();
      }

      App_Model_DW.sfEvent_lj3c = d_previousEvent;

      /* 5차 적용 */
    } else {
      tmp = App_Model_DW.C_DrvDrSw_start;
      if (((uint32)App_Model_DW.b_Timer_PhoneReminderCheck_is_R == On) && (App_Model_DW.Timer_PhoneReminderCheck < ((uint16)6000U)) && ((uint32)App_Model_DW.b_WarnClearEnable_h2ib == On) && ((uint32)
           rtu_Main_InSig_pfli == On) && (((App_Model_DW.C_DrvDrSw_prev != tmp) && ((uint32)tmp == On)) || ((App_Model_DW.C_AstDrSw_prev != App_Model_DW.C_AstDrSw_start) && ((uint32)
             App_Model_DW.C_AstDrSw_start == On)))) {
        App_Model_B.C_WPCWarning_jsvy = Cellphoneonthepad;
        d_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneRe_bamn;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
          Tick_Timer_PhoneReminderCh_kfry();
        }

        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_PhnLeftC_dpmm;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhnLeftCha != 0U) {
          Tick_Timer_PhnLeftChatteri_bjsy();
        }

        App_Model_DW.sfEvent_lj3c = d_previousEvent;
      } else if ((App_Model_DW.Timer_PhoneReminderCheck >= ((uint16)6000U)) && ((uint32)App_Model_DW.b_WarnClearEnable_h2ib == On) && ((uint32)rtu_Main_InSig_pfli == On)) {
        /* 1. */
        if (((uint32)rtu_Main_InSig_c0zj == On) || ((uint32)rtu_Main_InSig_exqx == On)) {
          App_Model_DW.b_WarnClearEnable_h2ib = Off;
          App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
          App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
          d_previousEvent = App_Model_DW.sfEvent_lj3c;
          App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneRe_bamn;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
            Tick_Timer_PhoneReminderCh_kfry();
          }

          App_Model_DW.sfEvent_lj3c = d_previousEvent;
        } else {
          /* 2. */
          App_Model_B.C_WPCWarning_jsvy = Cellphonereminder;
          d_previousEvent = App_Model_DW.sfEvent_lj3c;
          App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneRe_bamn;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
            Tick_Timer_PhoneReminderCh_kfry();
          }

          App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_WarningC_gzuk;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_cwy4 != 0U) {
            Tick_Timer_WarningComplete_krdu();
          }

          App_Model_DW.sfEvent_lj3c = d_previousEvent;
        }
      } else if ((App_Model_DW.Timer_WarningComplete_jdlj >= ((uint16)50U)) && ((uint32)App_Model_DW.b_WarnClearEnable_h2ib == On) && ((uint32)rtu_Main_InSig_pfli == On)) {
        App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
        App_Model_DW.b_WarnClearEnable_h2ib = Off;
        App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
        d_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_Warning_opqw;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_cwy4 != 0U) {
          Tick_Timer_WarningComplete_krdu();
        }

        App_Model_DW.sfEvent_lj3c = d_previousEvent;
      } else if ((App_Model_DW.Timer_PhnLeftChattering_owvz >= ((uint16)600U)) && ((uint32)App_Model_DW.b_WarnClearEnable_h2ib == On) && ((uint32)rtu_Main_InSig_pfli == On)) {
        App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
        App_Model_DW.b_WarnClearEnable_h2ib = Off;
        d_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhnLeft_hwkj;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhnLeftCha != 0U) {
          Tick_Timer_PhnLeftChatteri_bjsy();
        }

        App_Model_DW.sfEvent_lj3c = d_previousEvent;
      } else {
        /* no actions */
      }
    }
  }

  /* End of SwitchCase: '<S465>/Switch Case2' */
  /* End of Outputs for SubSystem: '<S465>/Subsystem' */
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void Function_ChargingINDColor_ebqs(WPCIndUSMState rtu_Main_InSig_i4oh)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) {
    App_Model_B.b_GreenINDCmd_esxl = On;
    App_Model_B.b_AmberINDCmd_ptyk = Off;
  } else {
    App_Model_B.b_GreenINDCmd_esxl = Off;
    App_Model_B.b_AmberINDCmd_ptyk = On;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void Ap_Tick_Timer_AmberINDBlk2_cmm0(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_AmberIND_mkfa) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_AmberIN_cw02) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_AmberINDBlk2_nmef = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk2_nmef + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk2_nmef + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2_nmef = (uint16)tmp;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_AmberIND_mkfa) {
          App_Model_DW.Timer_AmberINDBlk2_nmef = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void App_Tick_Timer_AmberINDBlk_ezex(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk_avth) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_AmberIND_lptb) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk_avth = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_lj3c == (sint32)event_Cancel_Timer_AmberIN_cile) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk_avth = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_AmberINDBlk_ptlt = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk_ptlt + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk_ptlt + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk_ptlt = (uint16)tmp;
        if (App_Model_DW.sfEvent_lj3c == (sint32)event_Start_Timer_AmberIND_lptb) {
          App_Model_DW.Timer_AmberINDBlk_ptlt = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void App_Function_LEDErrorBlink_mwqe(WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x)
{
  switch (rtu_Main_InSig_hp1x) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)App_Model_B.BlinkState_dn5g != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_gerk >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkComplete;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
        App_Model_B.b_BlinkState_jzug = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_gerk >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkComplete;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
        App_Model_B.b_BlinkState_jzug = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOn;
        App_Model_B.b_AmberINDCmd_ptyk = On;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_mkfa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_avth ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.b_AmberINDCmd_ptyk = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_lptb;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g == BlinkOff) && ((App_Model_DW.RWPCIndCmdState_prev_o0zq !=
                   App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_dn5g = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_gerk = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_gerk + 1));
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_lptb;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g == BlinkOn) && (((App_Model_DW.RWPCIndCmdState_prev_o0zq !=
                    App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeOut)) || ((App_Model_DW.RWPCIndCmdState_prev_o0zq !=
                    App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)App_Model_DW.RWPCIndCmdState_start_avm4 == RWPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_dn5g = BlinkOff;
        App_Model_B.b_AmberINDCmd_ptyk = On;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_lptb;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev_o0zq != App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)
                   App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOn;
        App_Model_B.b_AmberINDCmd_ptyk = On;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_mkfa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev_o0zq != App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)
                   App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_gerk = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_gerk + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_mkfa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)App_Model_B.BlinkState_dn5g != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt_gerk >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkComplete;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
        App_Model_B.b_BlinkState_jzug = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt_gerk >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkComplete;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
        App_Model_B.b_BlinkState_jzug = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOn;
        App_Model_B.b_AmberINDCmd_ptyk = On;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_mkfa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk_avth ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.b_AmberINDCmd_ptyk = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_lptb;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g == BlinkOff) && ((App_Model_DW.RWPCIndCmdState_prev_o0zq !=
                   App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_dn5g = BlinkOn;
        App_Model_DW.Counter_BlinkCnt_gerk = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_gerk + 1));
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_lptb;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.BlinkState_dn5g == BlinkOn) && (((App_Model_DW.RWPCIndCmdState_prev_o0zq !=
                    App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeOut)) || ((App_Model_DW.RWPCIndCmdState_prev_o0zq !=
                    App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)App_Model_DW.RWPCIndCmdState_start_avm4 == RWPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.BlinkState_dn5g = BlinkOff;
        App_Model_B.b_AmberINDCmd_ptyk = On;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_lptb;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev_o0zq != App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)
                   App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOn;
        App_Model_B.b_AmberINDCmd_ptyk = On;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_mkfa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev_o0zq != App_Model_DW.RWPCIndCmdState_start_avm4) && ((uint32)
                   App_Model_DW.RWPCIndCmdState_prev_o0zq == RWPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.BlinkState_dn5g = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_gerk = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt_gerk + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        t_previousEvent = App_Model_DW.sfEvent_lj3c;
        App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_AmberIND_mkfa;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        App_Model_DW.sfEvent_lj3c = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void exit_internal_WPCMode_Run_nddy(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Run_iqye == App_Mod_IN_WPCRun_FODError_ewty) {
    sint32 b_previousEvent;
    App_Model_B.BlinkState_dn5g = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_gerk = 0U;
    b_previousEvent = App_Model_DW.sfEvent_lj3c;
    App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
      App_Tick_Timer_AmberINDBlk_ezex();
    }

    App_Model_DW.sfEvent_lj3c = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.b_BlinkState_jzug = Off;
    App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  } else {
    App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void App_Model_WPCMode_Run_nopn(Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, Bool rtu_Main_InSig_bvye, DeviceState rtu_Main_InSig_o3od, WPCIndUSMState
  rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x)
{
  /* Outputs for IfAction SubSystem: '<S465>/Subsystem' incorporates:
   *  ActionPort: '<S608>/ActionPort'
   */
  /* SwitchCase: '<S465>/Switch Case2' incorporates:
   *  Chart: '<S608>/RWPC_MainControl2_250507'
   */
  /* 1. */
  if (((uint32)rtu_Main_InSig_ld2g == On) || ((uint32)rtu_Main_InSig_a0gd == On) || ((uint32)rtu_Main_InSig_lm51 == On) || ((uint32)rtu_Main_InSig_bvye == On)) {
    exit_internal_WPCMode_Run_nddy();
    App_Model_DW.is_WPCMode_Enable_d4ts = App_Model_IN_WPCMode_Stop_hnbq;
    App_Model_B.b_FANModeCmd_l0dm = Off;
    App_Model_B.b_GreenINDCmd_esxl = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_eht5 = Off;

    /* 1. */
    if ((uint32)rtu_Main_InSig_bvye == On) {
      App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_WPCStop_TempErr_hdpu;
      App_Model_B.C_WPCWarning_jsvy = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      App_Model_B.BlinkState_dn5g = BlinkOff;
      App_Model_DW.Counter_BlinkCnt_gerk = 0U;
      App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

      /*  Non GFS  */
      App_Model_B.b_BlinkState_jzug = On;
    } else {
      App_Model_DW.is_WPCMode_Stop_guvc = App__IN_WPCStop_NotTempErr_eapl;
      App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_B.b_AmberINDCmd_ptyk = Off;
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Run_iqye) {
     case App_Mod_IN_WPCRun_Charging_o2bp:
      App_Model_B.b_FANModeCmd_l0dm = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_o3od == Standby) || ((uint32)rtu_Main_InSig_o3od == Init)) {
        App_Model_DW.is_WPCMode_Run_iqye = App_Mode_IN_WPCRun_Standby_dtiz;
        App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_l0dm = Off;
        App_Model_B.b_GreenINDCmd_esxl = Off;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_o3od) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_FODError_ewty;
          App_Model_B.C_WPCWarning_jsvy = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.BlinkState_dn5g = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_gerk = 0U;
          App_Model_B.b_FANModeCmd_l0dm = Off;
          App_Model_B.b_GreenINDCmd_esxl = Off;
          App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

          /*  Non GFS  */
          App_Model_B.b_BlinkState_jzug = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_iqye = IN_WPCRun_ChargingComplete_oknr;
          App_Model_B.C_WPCWarning_jsvy = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.b_GreenINDCmd_esxl = On;
          App_Model_B.b_AmberINDCmd_ptyk = Off;
          break;

         default:
          Function_ChargingINDColor_ebqs(rtu_Main_InSig_i4oh);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_oknr:
      App_Model_B.b_FANModeCmd_l0dm = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_o3od == Standby) || ((uint32)rtu_Main_InSig_o3od == Init)) {
        App_Model_DW.is_WPCMode_Run_iqye = App_Mode_IN_WPCRun_Standby_dtiz;
        App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_l0dm = Off;
        App_Model_B.b_GreenINDCmd_esxl = Off;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_o3od) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_FODError_ewty;
          App_Model_B.C_WPCWarning_jsvy = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.BlinkState_dn5g = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_gerk = 0U;
          App_Model_B.b_FANModeCmd_l0dm = Off;
          App_Model_B.b_GreenINDCmd_esxl = Off;
          App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

          /*  Non GFS  */
          App_Model_B.b_BlinkState_jzug = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_Charging_o2bp;
          App_Model_B.C_WPCWarning_jsvy = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          Function_ChargingINDColor_ebqs(rtu_Main_InSig_i4oh);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_ewty:
      {
        App_Model_B.b_FANModeCmd_l0dm = Off;

        /* 1. */
        if (((uint32)rtu_Main_InSig_o3od == Standby) || ((uint32)rtu_Main_InSig_o3od == Init)) {
          sint32 c_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          App_Model_B.BlinkState_dn5g = BlinkOff;
          App_Model_DW.Counter_BlinkCnt_gerk = 0U;
          c_previousEvent = App_Model_DW.sfEvent_lj3c;
          App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
            App_Tick_Timer_AmberINDBlk_ezex();
          }

          App_Model_DW.sfEvent_lj3c = c_previousEvent;

          /*  Non GFS  */
          App_Model_B.b_BlinkState_jzug = Off;
          App_Model_DW.is_WPCMode_Run_iqye = App_Mode_IN_WPCRun_Standby_dtiz;
          App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          App_Model_B.b_GreenINDCmd_esxl = Off;
          App_Model_B.b_AmberINDCmd_ptyk = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_o3od) {
           case Charging:
            {
              sint32 c_previousEvent;

              /* BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.BlinkState_dn5g = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_gerk = 0U;
              c_previousEvent = App_Model_DW.sfEvent_lj3c;
              App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
                App_Tick_Timer_AmberINDBlk_ezex();
              }

              App_Model_DW.sfEvent_lj3c = c_previousEvent;

              /*  Non GFS  */
              App_Model_B.b_BlinkState_jzug = Off;
              App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_Charging_o2bp;
              App_Model_B.C_WPCWarning_jsvy = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_l0dm = On;
              Function_ChargingINDColor_ebqs(rtu_Main_InSig_i4oh);
            }
            break;

           case Full_Charge:
            {
              sint32 c_previousEvent;

              /* 3. */
              /* BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.BlinkState_dn5g = BlinkOff;
              App_Model_DW.Counter_BlinkCnt_gerk = 0U;
              c_previousEvent = App_Model_DW.sfEvent_lj3c;
              App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
                App_Tick_Timer_AmberINDBlk_ezex();
              }

              App_Model_DW.sfEvent_lj3c = c_previousEvent;

              /*  Non GFS  */
              App_Model_B.b_BlinkState_jzug = Off;
              App_Model_DW.is_WPCMode_Run_iqye = IN_WPCRun_ChargingComplete_oknr;
              App_Model_B.C_WPCWarning_jsvy = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              App_Model_B.b_FANModeCmd_l0dm = On;
              App_Model_B.b_GreenINDCmd_esxl = On;
              App_Model_B.b_AmberINDCmd_ptyk = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_dtiz:
      App_Model_B.b_FANModeCmd_l0dm = Off;

      /* 1. */
      switch (rtu_Main_InSig_o3od) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_FODError_ewty;
        App_Model_B.C_WPCWarning_jsvy = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        App_Model_B.BlinkState_dn5g = BlinkOff;
        App_Model_DW.Counter_BlinkCnt_gerk = 0U;
        App_Model_B.b_GreenINDCmd_esxl = Off;
        App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

        /*  Non GFS  */
        App_Model_B.b_BlinkState_jzug = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_Charging_o2bp;
        App_Model_B.C_WPCWarning_jsvy = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_l0dm = On;
        Function_ChargingINDColor_ebqs(rtu_Main_InSig_i4oh);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run_iqye = IN_WPCRun_ChargingComplete_oknr;
        App_Model_B.C_WPCWarning_jsvy = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        App_Model_B.b_FANModeCmd_l0dm = On;
        App_Model_B.b_GreenINDCmd_esxl = On;
        App_Model_B.b_AmberINDCmd_ptyk = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }

  /* End of SwitchCase: '<S465>/Switch Case2' */
  /* End of Outputs for SubSystem: '<S465>/Subsystem' */
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void exit_internal_WPCMode_Stop_on5z(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Stop_guvc == App_Mod_IN_WPCStop_TempErr_hdpu) {
    sint32 b_previousEvent;
    App_Model_B.BlinkState_dn5g = BlinkOff;
    App_Model_DW.Counter_BlinkCnt_gerk = 0U;
    b_previousEvent = App_Model_DW.sfEvent_lj3c;
    App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
      App_Tick_Timer_AmberINDBlk_ezex();
    }

    App_Model_DW.sfEvent_lj3c = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.b_BlinkState_jzug = Off;
    App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  } else {
    App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  }
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_atomic_WPCMode_Disab_ewpa(void)
{
  sint32 b_previousEvent;
  App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
  App_Model_B.BlinkState_dn5g = BlinkOff;
  App_Model_DW.Counter_BlinkCnt_gerk = 0U;
  App_Model_DW.b_WarnClearEnable_h2ib = Off;
  App_Model_B.b_FANModeCmd_l0dm = Off;
  App_Model_B.b_GreenINDCmd_esxl = Off;
  App_Model_B.b_AmberINDCmd_ptyk = Off;
  App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
  b_previousEvent = App_Model_DW.sfEvent_lj3c;
  App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
    App_Tick_Timer_AmberINDBlk_ezex();
  }

  App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneLe_fatc;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kep1 != 0U) {
    App_M_Tick_Timer_PhoneLeft_gv5q();
  }

  App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneWa_mdmw;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
    Tick_Timer_PhoneWarningChe_jngs();
  }

  App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneRe_bamn;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
    Tick_Timer_PhoneReminderCh_kfry();
  }

  App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_Warning_opqw;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_cwy4 != 0U) {
    Tick_Timer_WarningComplete_krdu();
  }

  App_Model_DW.sfEvent_lj3c = b_previousEvent;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__hri5(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft_jafl = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_PhoneLeft_onnd = 0U;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__jpd4(void)
{
  App_Model_DW.is_Tick_Timer_PhoneWarning_i3dp = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_PhoneWarningCheck_hbn3 = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_bn3m = 0U;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__b25k(void)
{
  App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_PhoneReminderCheck = 0U;
  App_Model_B.b_Timer_PhoneReminderCheck_hhaw = 0U;
  App_Model_DW.b_Timer_PhoneReminderCheck_is_R = Off;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__bo0g(void)
{
  App_Model_DW.is_Tick_Timer_WarningCompl_mg4r = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_WarningComplete_jdlj = 0U;
  App_Model_B.b_Timer_WarningComplete_n54s = 0U;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__gv5p(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk_avth = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_AmberINDBlk_ptlt = 0U;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__jc4l(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_AmberINDBlk2_nmef = 0U;
}

/* Function for Chart: '<S608>/RWPC_MainControl2_250507' */
static void enter_internal_Tick_Timer__ku30(void)
{
  App_Model_DW.is_Tick_Timer_PhnLeftChattering = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_PhnLeftChattering_owvz = 0U;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void Function_ChargingINDColor_jq5h(WPCIndUSMState rtu_Main_InSig_i4oh)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) {
    App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = On;
    App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
  } else {
    App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
    App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void Ap_Tick_Timer_AmberINDBlk2_p5ah(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk2) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_AmberIND_djbs) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_owa4 == (sint32)event_Cancel_Timer_AmberIN_cw02) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_AmberINDBlk2 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk2 + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk2 + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk2 = (uint16)tmp;
        if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_AmberIND_djbs) {
          App_Model_DW.Timer_AmberINDBlk2 = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void App_Tick_Timer_AmberINDBlk_li22(void)
{
  switch (App_Model_DW.is_Tick_Timer_AmberINDBlk) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_AmberIND_k03b) {
      App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_owa4 == (sint32)event_Cancel_Timer_AmberIN_cile) {
        App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_AmberINDBlk = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_AmberINDBlk + 1;
        if (((sint32)App_Model_DW.Timer_AmberINDBlk + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_AmberINDBlk = (uint16)tmp;
        if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_AmberIND_k03b) {
          App_Model_DW.Timer_AmberINDBlk = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void App_Function_LEDErrorBlink_f23p(WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x)
{
  switch (rtu_Main_InSig_hp1x) {
   case Off:
    {
      /* For_OnlyAmber%WPC가 하나이거나 우선순위가 가장 높을경우 */
      /* 1. */
      if (((uint32)App_Model_B.Output_BlinkState_mkqq != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2 ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_djbs;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_k03b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq == BlinkOff) && ((App_Model_DW.RWPCIndCmdState_prev !=
                   App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev == RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk2 >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;
        App_Model_DW.Counter_BlinkCnt = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt + 1));
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_k03b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq == BlinkOn) && (((App_Model_DW.RWPCIndCmdState_prev !=
                    App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev == RWPCIndCmdState__ErrorFadeOut)) || ((App_Model_DW.RWPCIndCmdState_prev !=
                    App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_start == RWPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_mkqq = BlinkOff;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_k03b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev != App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev ==
                   RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_djbs;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev != App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev ==
                   RWPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOff;
        App_Model_DW.Counter_BlinkCnt = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_djbs;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   case On:
    {
      /* For_OnlyAmber%WPC가 타WPC에 비해 우선순위가 낮을경우 */
      /* 1. */
      if (((uint32)App_Model_B.Output_BlinkState_mkqq != BlinkComplete) && (App_Model_DW.Counter_BlinkCnt >= ((uint8)10U))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;

        /*  Non GFS  */
      } else if (App_Model_DW.Counter_BlinkCnt >= ((uint8)10U)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkComplete;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cw02;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
        App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;

        /*  Non GFS  */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk2 ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_djbs;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq != BlinkComplete) && ((uint32)App_Model_DW.is_Tick_Timer_AmberINDBlk ==
                  App_Model_IN_Off_pxcg)) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;

        /* Counter_BlinkCnt ++ */
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;

        /* OffStart */
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_k03b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq == BlinkOff) && ((App_Model_DW.RWPCIndCmdState_prev !=
                   App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev == RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;
        App_Model_DW.Counter_BlinkCnt = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt + 1));
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_k03b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh != WPCIndUSMState__Type2) && ((uint32)App_Model_B.Output_BlinkState_mkqq == BlinkOn) && (((App_Model_DW.RWPCIndCmdState_prev !=
                    App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev == RWPCIndCmdState__ErrorFadeOut)) || ((App_Model_DW.RWPCIndCmdState_prev !=
                    App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_start == RWPCIndCmdState__ErrorOn)))) {
        sint32 t_previousEvent;

        /* Timer_AmberINDBlk >= Par_LEDBlinkTime] */
        App_Model_B.Output_BlinkState_mkqq = BlinkOff;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_k03b;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
          App_Tick_Timer_AmberINDBlk_li22();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev != App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev ==
                   RWPCIndCmdState__ErrorFadeIn))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOn;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = On;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_djbs;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;

        /* 1. */
      } else if (((uint32)rtu_Main_InSig_i4oh == WPCIndUSMState__Type2) && ((App_Model_DW.RWPCIndCmdState_prev != App_Model_DW.RWPCIndCmdState_start) && ((uint32)App_Model_DW.RWPCIndCmdState_prev ==
                   RWPCIndCmdState__ErrorFadeOut))) {
        sint32 t_previousEvent;
        App_Model_B.Output_BlinkState_mkqq = BlinkOff;
        App_Model_DW.Counter_BlinkCnt = (uint8)((sint32)((sint32)App_Model_DW.Counter_BlinkCnt + 1));

        /* Adapt after FadeOut and LEDOff // 230110 */
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        t_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_AmberIND_djbs;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_p5ah();
        }

        App_Model_DW.sfEvent_owa4 = t_previousEvent;
      } else {
        /* no actions */
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void exit_internal_WPCMode_Run_aifz(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Run == App_Mod_IN_WPCRun_FODError_ewty) {
    sint32 b_previousEvent;
    App_Model_B.Output_BlinkState_mkqq = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    b_previousEvent = App_Model_DW.sfEvent_owa4;
    App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_li22();
    }

    App_Model_DW.sfEvent_owa4 = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
    App_Model_DW.is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  } else {
    App_Model_DW.is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void Tick_Timer_WarningTypeChec_bias(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningTypeCheck) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_WarningT_imcq) {
      App_Model_DW.is_Tick_Timer_WarningTypeCheck = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_owa4 == (sint32)event_Cancel_Timer_Warning_denu) {
        App_Model_DW.is_Tick_Timer_WarningTypeCheck = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_WarningTypeCheck = 0U;
        App_Model_B.b_Timer_WarningTypeCheck_pkt3 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningTypeCheck + 1;
        if (((sint32)App_Model_DW.Timer_WarningTypeCheck + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningTypeCheck = (uint16)tmp;
        App_Model_B.b_Timer_WarningTypeCheck_pkt3 = App_Model_DW.Timer_WarningTypeCheck;
        if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_WarningT_imcq) {
          App_Model_DW.Timer_WarningTypeCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void App_M_Tick_Timer_PhoneLeft_ofh0(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneLeft) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_PhoneLef_kata) {
      App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_owa4 == (sint32)event_Cancel_Timer_PhoneLe_kfwe) {
        App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_PhoneLeft = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneLeft + 1;
        if (((sint32)App_Model_DW.Timer_PhoneLeft + 1) > 255) {
          tmp = 255;
        }

        App_Model_DW.Timer_PhoneLeft = (uint8)tmp;
        if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_PhoneLef_kata) {
          App_Model_DW.Timer_PhoneLeft = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void Tick_Timer_PhoneWarningChe_h4zv(void)
{
  switch (App_Model_DW.is_Tick_Timer_PhoneWarningCheck) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_PhoneWar_pc5i) {
      App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_owa4 == (sint32)event_Cancel_Timer_PhoneWa_jyj3) {
        App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_PhoneWarningCheck = 0U;
        App_Model_B.b_Timer_PhoneWarningCheck_frp4 = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_PhoneWarningCheck + 1;
        if (((sint32)App_Model_DW.Timer_PhoneWarningCheck + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_PhoneWarningCheck = (uint16)tmp;
        App_Model_B.b_Timer_PhoneWarningCheck_frp4 = App_Model_DW.Timer_PhoneWarningCheck;
        if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_PhoneWar_pc5i) {
          App_Model_DW.Timer_PhoneWarningCheck = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void Tick_Timer_WarningComplete_ci2o(void)
{
  switch (App_Model_DW.is_Tick_Timer_WarningComplete) {
   case App_Model_IN_Off_pxcg:
    if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_WarningC_fats) {
      App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_On_g4y5;
    }
    break;

   case App_Model_IN_On_g4y5:
    {
      if (App_Model_DW.sfEvent_owa4 == (sint32)event_Cancel_Timer_Warning_o4g2) {
        App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_Off_pxcg;
        App_Model_DW.Timer_WarningComplete = 0U;
        App_Model_B.b_Timer_WarningComplete_kjpg = 0U;
      } else {
        sint32 tmp;
        tmp = (sint32)App_Model_DW.Timer_WarningComplete + 1;
        if (((sint32)App_Model_DW.Timer_WarningComplete + 1) > 65535) {
          tmp = 65535;
        }

        App_Model_DW.Timer_WarningComplete = (uint16)tmp;
        App_Model_B.b_Timer_WarningComplete_kjpg = App_Model_DW.Timer_WarningComplete;
        if (App_Model_DW.sfEvent_owa4 == (sint32)event_Start_Timer_WarningC_fats) {
          App_Model_DW.Timer_WarningComplete = 0U;
        }
      }
    }
    break;

   default:
    /* no actions */
    break;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void App_Mo_Function_WPCWarning_a0qj(C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli)
{
  /*  WPC 모드가 해제 or 폰 감지가 안되었을 경우 or 출력 후 폰 가져간 경우900ms */
  if (((uint32)rtu_Main_InSig_gfkd == WPC_Off) || ((App_Model_DW.Timer_PhoneWarningCheck >= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_pfli == Off)) || (App_Model_DW.Timer_PhoneLeft >=
       ((uint8)50U))) {
    sint32 c_previousEvent;

    /* 500m */
    /*  Warning OffNidec */
    App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

    /* Output_WPCWarning = SavedPreWPCMode%Nidec */
    App_Model_DW.b_WarnClearEnable = Off;

    /* Nidec충전가능 */
    App_Model_B.b_PhnLeftChk_Enable_emma = Off;
    c_previousEvent = App_Model_DW.sfEvent_owa4;
    App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneLe_kfwe;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
      App_M_Tick_Timer_PhoneLeft_ofh0();
    }

    App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneWa_jyj3;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
      Tick_Timer_PhoneWarningChe_h4zv();
    }

    App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_o4g2;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
      Tick_Timer_WarningComplete_ci2o();
    }

    App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_denu;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_bias();
    }

    App_Model_DW.sfEvent_owa4 = c_previousEvent;
  } else {
    sint32 c_previousEvent;

    /*  방치 알림 신호 출력 후, 휴대폰을 가져가는 경우 */
    if (((uint32)App_Model_DW.b_WarnClearEnable == On) && ((App_Model_DW.Input_OPT_b_WPCPhoneExist_prev != App_Model_DW.Input_OPT_b_WPCPhoneExist_start) && ((uint32)
          App_Model_DW.Input_OPT_b_WPCPhoneExist_start == Off))) {
      /*  폰 비거치 시간 측정 타이머 시작 */
      c_previousEvent = App_Model_DW.sfEvent_owa4;
      App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_PhoneLef_kata;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_ofh0();
      }

      App_Model_DW.sfEvent_owa4 = c_previousEvent;

      /*  방치알림 신호 출력 후, 폰 비거치 상태-> 다시 폰 거치 확인한 경우 */
    } else if (((uint32)App_Model_DW.is_Tick_Timer_PhoneLeft == App_Model_IN_On_g4y5) && ((uint32)rtu_Main_InSig_pfli == On)) {
      /*  폰 비거치 시간 측정 타이머 취소 */
      c_previousEvent = App_Model_DW.sfEvent_owa4;
      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneLe_kfwe;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_ofh0();
      }

      App_Model_DW.sfEvent_owa4 = c_previousEvent;
    } else {
      /* no actions */
    }

    /*  폰 경고 확인 조건 판단 */
    if ((uint32)App_Model_DW.PhoneLeftWrnType_hyhg == PhoneLeftWrnType__Default) {
      if (App_Model_DW.Timer_WarningTypeCheck < ((uint16)6000U)) {
        /* 60s */
        if ((uint32)rtu_Main_InSig_c0zj == On) {
          /*  60초 이내에 DoorOpen 이벤트 발생할 경우,
             경고타입 (1sec Delay 후 6sec 간 경고 출력 발생) 설정 */
          App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__LongDuration;

          /* Nidec 60초이전 이벤트는 충전금지필요%WPCMode가 아닐 때는 상시 On이므로 WPCMode일 때를 위한 조건 */
          App_Model_B.b_PhnLeftChk_Enable_emma = On;

          /* HMC사양에 폰충전불가 주석원복함. */
          c_previousEvent = App_Model_DW.sfEvent_owa4;
          App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_denu;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
            Tick_Timer_WarningTypeChec_bias();
          }

          App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_PhoneWar_pc5i;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
            Tick_Timer_PhoneWarningChe_h4zv();
          }

          App_Model_DW.sfEvent_owa4 = c_previousEvent;
        } else {
          /* WPCMode아닐 때 충전금지위해
             PhnLeftChck_Enable On유지 */
        }
      } else {
        /*  60초 간 Door Open 없을 시, 경고 타입(즉시 500ms 경고 출력 발생) 설정 */
        App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__ShortDuration;

        /* b_PhnLeftChk_Enable = On%Nidec%60초 이후 영향으로 불필요 */
        c_previousEvent = App_Model_DW.sfEvent_owa4;
        App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_denu;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
          Tick_Timer_WarningTypeChec_bias();
        }

        App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_PhoneWar_pc5i;
        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
          Tick_Timer_PhoneWarningChe_h4zv();
        }

        App_Model_DW.sfEvent_owa4 = c_previousEvent;
      }
    }

    /*  폰 경고 확인 시간 중 폰 감지됨100ms900ms */
    if ((App_Model_DW.Timer_PhoneWarningCheck >= (uint16)((uint8)10U)) && (App_Model_DW.Timer_PhoneWarningCheck <= (uint16)Par_PhoneCheckTime) && ((uint32)rtu_Main_InSig_pfli == On)) {
      /* Output_WPCWarning = Cellphoneonthepad%NFCModeControl연동시그널. IG On중에는 미적용 */
      c_previousEvent = App_Model_DW.sfEvent_owa4;
      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneWa_jyj3;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_h4zv();
      }

      App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningC_fats;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_ci2o();
      }

      App_Model_DW.sfEvent_owa4 = c_previousEvent;
    }

    /*  경고 알림 출력
       [(PhoneLeftWrnType == PhoneLeftWrnType__LongDuration&&Timer_WarningComplete >= Par_WarningDelayTime &&...0s
       Timer_WarningComplete <= Par_WarningTime__LongDuration+Par_WarningDelayTime) ||...6s+0s %%DelayDelete_Nidec6s */
    if ((((uint32)App_Model_DW.PhoneLeftWrnType_hyhg == PhoneLeftWrnType__LongDuration) && ((uint32)App_Model_DW.is_Tick_Timer_WarningComplete == App_Model_IN_On_g4y5) &&
         (App_Model_DW.Timer_WarningComplete <= ((uint16)600U))) || (((uint32)App_Model_DW.PhoneLeftWrnType_hyhg == PhoneLeftWrnType__ShortDuration) && ((uint32)
          App_Model_DW.is_Tick_Timer_WarningComplete == App_Model_IN_On_g4y5) && (App_Model_DW.Timer_WarningComplete <= ((uint16)50U)))) {
      /* 500m */
      App_Model_B.Output_WPCWarning_jifb = Cellphonereminder;
      App_Model_DW.b_WarnClearEnable = On;

      /*  경고 알림 출력 해제 조건 */
    } else if ((((uint32)App_Model_DW.PhoneLeftWrnType_hyhg == PhoneLeftWrnType__LongDuration) && (App_Model_DW.Timer_WarningComplete > (((uint16)600U) + ((uint16)0U)))) || (((uint32)
                 App_Model_DW.PhoneLeftWrnType_hyhg == PhoneLeftWrnType__ShortDuration) && (App_Model_DW.Timer_WarningComplete > ((uint16)50U)))) {
      /* Nidec */
      App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

      /* Output_WPCWarning = SavedPreWPCMode%NidecNidec 필요250219 */
      App_Model_B.b_PhnLeftChk_Enable_emma = Off;

      /* HMC사양에 폰충전불가 주석원복함. */
      c_previousEvent = App_Model_DW.sfEvent_owa4;
      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_o4g2;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_ci2o();
      }

      App_Model_DW.sfEvent_owa4 = c_previousEvent;
    } else {
      /* no actions */
    }
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void App_Model_WPCMode_Run_ksb1(Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_bvye, Bool
  rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, DeviceState rtu_Main_InSig_o3od, WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x, GearPosSta rtu_Main_InSig_m0c4)
{
  Bool tmp;
  tmp = App_Model_DW.b_DrvDrSw_start;
  if (((App_Model_DW.Input_OPT_GearPosSta_prev != App_Model_DW.Input_OPT_GearPosSta_start) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start == GearPos_P) && ((uint32)rtu_Main_InSig_c0zj == On)) ||
      ((App_Model_DW.b_DrvDrSw_prev != tmp) && ((uint32)tmp == On) && ((uint32)rtu_Main_InSig_m0c4 == GearPos_P))) {
    sint32 d_previousEvent;

    /* Nidec */
    exit_internal_WPCMode_Run_aifz();
    App_Model_DW.is_WPCMode_Enable = IN_LeavingPhone_Warning_In_exxx;
    App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
    App_Model_DW.b_WarnClearEnable = Off;
    App_Model_B.b_ChargingEnable_kg0a = Off;
    d_previousEvent = App_Model_DW.sfEvent_owa4;
    App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningT_imcq;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_bias();
    }

    App_Model_DW.sfEvent_owa4 = d_previousEvent;
    App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);

    /* 1. */
  } else if (((uint32)rtu_Main_InSig_ld2g == On) || ((uint32)rtu_Main_InSig_a0gd == On) || ((uint32)rtu_Main_InSig_lm51 == On) || ((uint32)rtu_Main_InSig_bvye == On)) {
    /*  ||b_CardProtection == On ]...CardDetect_Nidec */
    exit_internal_WPCMode_Run_aifz();
    App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_mk5d;
    App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
    App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;

    /* b_ROHMOperCmd = Off /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_kg0a = Off;

    /* 1. */
    if ((uint32)rtu_Main_InSig_bvye == On) {
      App_Model_DW.is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_hdpu;
      App_Model_B.Output_WPCWarning_jifb = Charging_error;

      /* b_WPCWarn = Charging_error 8차 LFRollBack */
      App_Model_B.Output_BlinkState_mkqq = BlinkOff;
      App_Model_DW.Counter_BlinkCnt = 0U;
      App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

      /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
      App_Model_B.Output_OPT_b_BlinkState_dvqq = On;
    } else {
      App_Model_DW.is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_eapl;
      App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Run) {
     case App_Mod_IN_WPCRun_Charging_o2bp:
      App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_o3od == Standby) || ((uint32)rtu_Main_InSig_o3od == Init)) {
        App_Model_DW.is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_dtiz;
        App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_o3od) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_ewty;
          App_Model_B.Output_WPCWarning_jifb = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.Output_BlinkState_mkqq = BlinkOff;
          App_Model_DW.Counter_BlinkCnt = 0U;
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
          App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_dvqq = On;
          break;

         case Full_Charge:
          /* 3. */
          App_Model_DW.is_WPCMode_Run = IN_WPCRun_ChargingComplete_oknr;
          App_Model_B.Output_WPCWarning_jifb = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = On;
          App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
          break;

         default:
          Function_ChargingINDColor_jq5h(rtu_Main_InSig_i4oh);
          break;
        }
      }
      break;

     case IN_WPCRun_ChargingComplete_oknr:
      App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;

      /* 1. */
      if (((uint32)rtu_Main_InSig_o3od == Standby) || ((uint32)rtu_Main_InSig_o3od == Init)) {
        App_Model_DW.is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_dtiz;
        App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
        App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
      } else {
        /* 2. */
        switch (rtu_Main_InSig_o3od) {
         case FODError:
          /*  b_FODFault == On] */
          App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_ewty;
          App_Model_B.Output_WPCWarning_jifb = Charging_error;

          /* b_WPCWarn = Charging_error 8차 LFRollBack */
          App_Model_B.Output_BlinkState_mkqq = BlinkOff;
          App_Model_DW.Counter_BlinkCnt = 0U;
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
          App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_dvqq = On;
          break;

         case Charging:
          /* 3. */
          App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_o2bp;
          App_Model_B.Output_WPCWarning_jifb = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          Function_ChargingINDColor_jq5h(rtu_Main_InSig_i4oh);
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     case App_Mod_IN_WPCRun_FODError_ewty:
      {
        App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;

        /* 1. */
        if (((uint32)rtu_Main_InSig_o3od == Standby) || ((uint32)rtu_Main_InSig_o3od == Init)) {
          sint32 d_previousEvent;

          /*  BlinkState == BlinkComplete 8차 적용 */
          App_Model_B.Output_BlinkState_mkqq = BlinkOff;
          App_Model_DW.Counter_BlinkCnt = 0U;
          d_previousEvent = App_Model_DW.sfEvent_owa4;
          App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
            App_Tick_Timer_AmberINDBlk_li22();
          }

          App_Model_DW.sfEvent_owa4 = d_previousEvent;

          /*  Non GFS  */
          App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
          App_Model_DW.is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_dtiz;
          App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

          /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
          App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
          App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        } else {
          /* 2. */
          switch (rtu_Main_InSig_o3od) {
           case Charging:
            {
              sint32 d_previousEvent;

              /*  BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.Output_BlinkState_mkqq = BlinkOff;
              App_Model_DW.Counter_BlinkCnt = 0U;
              d_previousEvent = App_Model_DW.sfEvent_owa4;
              App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Tick_Timer_AmberINDBlk_li22();
              }

              App_Model_DW.sfEvent_owa4 = d_previousEvent;

              /*  Non GFS  */
              App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
              App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_o2bp;
              App_Model_B.Output_WPCWarning_jifb = PhoneCharging;

              /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
              App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;
              Function_ChargingINDColor_jq5h(rtu_Main_InSig_i4oh);
            }
            break;

           case Full_Charge:
            {
              sint32 d_previousEvent;

              /* 3. */
              /*  BlinkState == BlinkComplete 8차 적용 */
              App_Model_B.Output_BlinkState_mkqq = BlinkOff;
              App_Model_DW.Counter_BlinkCnt = 0U;
              d_previousEvent = App_Model_DW.sfEvent_owa4;
              App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
              if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
                App_Tick_Timer_AmberINDBlk_li22();
              }

              App_Model_DW.sfEvent_owa4 = d_previousEvent;

              /*  Non GFS  */
              App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
              App_Model_DW.is_WPCMode_Run = IN_WPCRun_ChargingComplete_oknr;
              App_Model_B.Output_WPCWarning_jifb = Charging_Complete;

              /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
              App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;
              App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = On;
              App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
            }
            break;

           default:
            App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
            break;
          }
        }
      }
      break;

     case App_Mode_IN_WPCRun_Standby_dtiz:
      App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;

      /* 1. */
      switch (rtu_Main_InSig_o3od) {
       case FODError:
        /*  b_FODFault == On] */
        App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_FODError_ewty;
        App_Model_B.Output_WPCWarning_jifb = Charging_error;

        /* b_WPCWarn = Charging_error 8차 LFRollBack */
        App_Model_B.Output_BlinkState_mkqq = BlinkOff;
        App_Model_DW.Counter_BlinkCnt = 0U;
        App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
        App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

        /*  Non GFS  */
        App_Model_B.Output_OPT_b_BlinkState_dvqq = On;
        break;

       case Charging:
        /* 2. */
        App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_o2bp;
        App_Model_B.Output_WPCWarning_jifb = PhoneCharging;

        /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;
        Function_ChargingINDColor_jq5h(rtu_Main_InSig_i4oh);
        break;

       case Full_Charge:
        /* 3. */
        App_Model_DW.is_WPCMode_Run = IN_WPCRun_ChargingComplete_oknr;
        App_Model_B.Output_WPCWarning_jifb = Charging_Complete;

        /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
        App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;
        App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = On;
        App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        break;

       default:
        /* no actions */
        break;
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void exit_internal_WPCMode_Stop_mh2b(void)
{
  if ((uint32)App_Model_DW.is_WPCMode_Stop == App_Mod_IN_WPCStop_TempErr_hdpu) {
    sint32 b_previousEvent;

    /* Function_NFCCardDetection() 8차 적용 삭제 */
    App_Model_B.Output_BlinkState_mkqq = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    b_previousEvent = App_Model_DW.sfEvent_owa4;
    App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
      App_Tick_Timer_AmberINDBlk_li22();
    }

    App_Model_DW.sfEvent_owa4 = b_previousEvent;

    /*  Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
    App_Model_DW.is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  } else {
    App_Model_DW.is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_atomic_WPCMode_Disab_e3k4(void)
{
  sint32 b_previousEvent;
  App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
  App_Model_B.Output_BlinkState_mkqq = BlinkOff;
  App_Model_DW.Counter_BlinkCnt = 0U;

  /* b_ChargingEnable = Off 8차 적용 삭제 */
  App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
  App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
  b_previousEvent = App_Model_DW.sfEvent_owa4;
  App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
    App_Tick_Timer_AmberINDBlk_li22();
  }

  App_Model_DW.sfEvent_owa4 = b_previousEvent;

  /* Nidec */
  App_Model_B.b_PhnLeftChk_Enable_emma = Off;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_WPCMode_Off_fjwh(C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, GearPosSta rtu_Main_InSig_m0c4)
{
  /* [hasChangedTo(Input_OPT_GearPosSta,GearPos_P)] */
  if ((uint32)rtu_Main_InSig_m0c4 == GearPos_P) {
    sint32 b_previousEvent;

    /* Nidec */
    App_Model_DW.is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_g052;
    App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
    App_Model_DW.b_WarnClearEnable = Off;
    b_previousEvent = App_Model_DW.sfEvent_owa4;
    App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningT_imcq;
    if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
      Tick_Timer_WarningTypeChec_bias();
    }

    App_Model_DW.sfEvent_owa4 = b_previousEvent;
    App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);

    /* Nidec */
    App_Model_B.b_PhnLeftChk_Enable_emma = On;
  } else {
    App_Model_DW.is_WPCMode_Off = IN_LeavingPhone_NoWarning_lklq;
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void A_enter_atomic_WPCMode_NFC_khti(void)
{
  sint32 b_previousEvent;
  App_Model_DW.b_WarnClearEnable = Off;
  b_previousEvent = App_Model_DW.sfEvent_owa4;
  App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneLe_kfwe;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
    App_M_Tick_Timer_PhoneLeft_ofh0();
  }

  App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneWa_jyj3;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
    Tick_Timer_PhoneWarningChe_h4zv();
  }

  App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_o4g2;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
    Tick_Timer_WarningComplete_ci2o();
  }

  App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_denu;
  if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
    Tick_Timer_WarningTypeChec_bias();
  }

  App_Model_DW.sfEvent_owa4 = b_previousEvent;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void App_Model_WPCMode_Enable_hnge(Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool rtu_Main_InSig_bvye, Bool
  rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, DeviceState rtu_Main_InSig_o3od, WPCStatus rtu_Main_InSig_ll4c, WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x, GearPosSta
  rtu_Main_InSig_m0c4)
{
  /* 1. */
  if ((uint32)rtu_Main_InSig_ll4c != WPCMode) {
    switch (App_Model_DW.is_WPCMode_Enable) {
     case IN_LeavingPhone_Warning_In_exxx:
      /* Nidec */
      App_Model_DW.is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
      break;

     case App_Model_IN_WPCMode_Run_gtpc:
      exit_internal_WPCMode_Run_aifz();
      App_Model_DW.is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
      break;

     case App_Model_IN_WPCMode_Stop_mk5d:
      exit_internal_WPCMode_Stop_mh2b();
      App_Model_DW.is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
      break;

     default:
      /* no actions */
      break;
    }

    /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
    App_Model_B.b_ChargingEnable_kg0a = Off;
    App_Model_DW.is_MainControl = App_Mod_IN_WPCMode_Disable_pcex;
    enter_atomic_WPCMode_Disab_e3k4();

    /* 1. */
    if (((uint32)rtu_Main_InSig_ll4c == NFCMode) || ((uint32)rtu_Main_InSig_ll4c == LPCDMode) || ((uint32)rtu_Main_InSig_ll4c == PICCMode)) {
      App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_bm2k;
      A_enter_atomic_WPCMode_NFC_khti();
    } else {
      App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_Off_likq;

      /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
       *  ActionPort: '<S609>/ActionPort'
       */
      /* SwitchCase: '<S465>/Switch Case2' incorporates:
       *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
       */
      enter_internal_WPCMode_Off_fjwh(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli, rtu_Main_InSig_m0c4);

      /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
    }
  } else {
    switch (App_Model_DW.is_WPCMode_Enable) {
     case IN_LeavingPhone_Warning_In_exxx:
      {
        Bool tmp_0;
        GearPosSta tmp;
        tmp = App_Model_DW.Input_OPT_GearPosSta_prev;
        tmp_0 = App_Model_DW.b_DrvDrSw_start;
        if (((tmp != App_Model_DW.Input_OPT_GearPosSta_start) && ((uint32)tmp == GearPos_P)) || ((App_Model_DW.b_DrvDrSw_prev != tmp_0) && ((uint32)tmp_0 == Off))) {
          /* Nidec DoorClose */
          /* Nidec */
          App_Model_B.b_PhnLeftChk_Enable_emma = Off;
          App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_mk5d;
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
          App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;

          /* b_ROHMOperCmd = Off /_ Non GFS _/ */
          App_Model_B.b_ChargingEnable_kg0a = Off;

          /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
           *  ActionPort: '<S609>/ActionPort'
           */
          /* SwitchCase: '<S465>/Switch Case2' incorporates:
           *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
           */
          /* 1. */
          if ((uint32)rtu_Main_InSig_bvye == On) {
            App_Model_DW.is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_hdpu;
            App_Model_B.Output_WPCWarning_jifb = Charging_error;

            /* b_WPCWarn = Charging_error 8차 LFRollBack */
            App_Model_B.Output_BlinkState_mkqq = BlinkOff;
            App_Model_DW.Counter_BlinkCnt = 0U;
            App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

            /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
            App_Model_B.Output_OPT_b_BlinkState_dvqq = On;
          } else {
            App_Model_DW.is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_eapl;
            App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

            /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
            App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
          }

          /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
        } else if ((tmp != App_Model_DW.Input_OPT_GearPosSta_start) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start == GearPos_P)) {
          sint32 b_previousEvent;

          /* Nidec */
          App_Model_B.b_PhnLeftChk_Enable_emma = Off;
          App_Model_DW.is_WPCMode_Enable = IN_LeavingPhone_Warning_In_exxx;
          App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
          App_Model_DW.b_WarnClearEnable = Off;
          App_Model_B.b_ChargingEnable_kg0a = Off;
          b_previousEvent = App_Model_DW.sfEvent_owa4;
          App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningT_imcq;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
            Tick_Timer_WarningTypeChec_bias();
          }

          App_Model_DW.sfEvent_owa4 = b_previousEvent;

          /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
           *  ActionPort: '<S609>/ActionPort'
           */
          /* SwitchCase: '<S465>/Switch Case2' incorporates:
           *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
           */
          App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);

          /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
           *  ActionPort: '<S609>/ActionPort'
           */
          /* SwitchCase: '<S465>/Switch Case2' incorporates:
           *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
           */
          /* b_PhnLeftChk_Enable = On%Nidec%충전상태를 조건에따라 판단하기위해 주석처리 */
          App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);

          /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
        }
      }
      break;

     case App_Model_IN_WPCMode_Run_gtpc:
      /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
       *  ActionPort: '<S609>/ActionPort'
       */
      /* SwitchCase: '<S465>/Switch Case2' incorporates:
       *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
       */
      App_Model_WPCMode_Run_ksb1(rtu_Main_InSig_ld2g, rtu_Main_InSig_a0gd, rtu_Main_InSig_lm51, rtu_Main_InSig_gfkd, rtu_Main_InSig_bvye, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli, rtu_Main_InSig_o3od,
        rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x, rtu_Main_InSig_m0c4);

      /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
      break;

     case App_Model_IN_WPCMode_Stop_mk5d:
      {
        App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;

        /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
         *  ActionPort: '<S609>/ActionPort'
         */
        /* SwitchCase: '<S465>/Switch Case2' incorporates:
         *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
         */
        if (((uint32)rtu_Main_InSig_o3od == Full_Charge) && ((uint32)rtu_Main_InSig_ld2g == Off) && ((uint32)rtu_Main_InSig_a0gd == Off) && ((uint32)rtu_Main_InSig_bvye == Off) && ((uint32)
             rtu_Main_InSig_lm51 == Off)) {
          /*  &&b_CardProtection == Off]%CardDetect_Nidec]
             Input_PhoneLeftWarningWPCStatus == Off]
             b_ChargingEnable == On 8차 적용 삭제 */
          exit_internal_WPCMode_Stop_mh2b();
          App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_gtpc;
          App_Model_B.b_ChargingEnable_kg0a = On;
          App_Model_DW.is_WPCMode_Run = IN_WPCRun_ChargingComplete_oknr;
          App_Model_B.Output_WPCWarning_jifb = Charging_Complete;

          /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;
          App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = On;
          App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
        } else if (((uint32)rtu_Main_InSig_o3od == Charging) && ((uint32)rtu_Main_InSig_ld2g == Off) && ((uint32)rtu_Main_InSig_a0gd == Off) && ((uint32)rtu_Main_InSig_bvye == Off) && ((uint32)
                    rtu_Main_InSig_lm51 == Off)) {
          /* &&b_CardProtection == Off]%CardDetect_Nidec]
             Input_PhoneLeftWarningWPCStatus == Off]
             b_ChargingEnable == On 8차 적용 삭제 */
          exit_internal_WPCMode_Stop_mh2b();
          App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_gtpc;
          App_Model_B.b_ChargingEnable_kg0a = On;
          App_Model_DW.is_WPCMode_Run = App_Mod_IN_WPCRun_Charging_o2bp;
          App_Model_B.Output_WPCWarning_jifb = PhoneCharging;

          /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = On;
          Function_ChargingINDColor_jq5h(rtu_Main_InSig_i4oh);
        } else {
          GearPosSta tmp;
          tmp = App_Model_DW.Input_OPT_GearPosSta_start;
          if (((App_Model_DW.Input_OPT_GearPosSta_prev != tmp) && ((uint32)tmp == GearPos_P) && ((uint32)rtu_Main_InSig_c0zj == On)) || ((App_Model_DW.b_DrvDrSw_prev != App_Model_DW.b_DrvDrSw_start) &&
               ((uint32)App_Model_DW.b_DrvDrSw_start == On) && ((uint32)rtu_Main_InSig_m0c4 == GearPos_P))) {
            sint32 b_previousEvent;

            /* Nidec */
            exit_internal_WPCMode_Stop_mh2b();
            App_Model_DW.is_WPCMode_Enable = IN_LeavingPhone_Warning_In_exxx;
            App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
            App_Model_DW.b_WarnClearEnable = Off;
            App_Model_B.b_ChargingEnable_kg0a = Off;
            b_previousEvent = App_Model_DW.sfEvent_owa4;
            App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningT_imcq;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
              Tick_Timer_WarningTypeChec_bias();
            }

            App_Model_DW.sfEvent_owa4 = b_previousEvent;
            App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);
          } else {
            switch (App_Model_DW.is_WPCMode_Stop) {
             case App__IN_WPCStop_NotTempErr_eapl:
              /* 1. */
              if ((uint32)rtu_Main_InSig_bvye == On) {
                App_Model_DW.is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_hdpu;
                App_Model_B.Output_WPCWarning_jifb = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.Output_BlinkState_mkqq = BlinkOff;
                App_Model_DW.Counter_BlinkCnt = 0U;
                App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

                /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
                App_Model_B.Output_OPT_b_BlinkState_dvqq = On;

                /* 2. */
              } else if (((uint32)rtu_Main_InSig_ld2g == Off) && ((uint32)rtu_Main_InSig_a0gd == Off) && ((uint32)rtu_Main_InSig_lm51 == Off)) {
                /* &&b_CardProtection == Off]%CardDetect_Nidec]
                   Input_PhoneLeftWarningWPCStatus == Off]
                   b_ChargingEnable == On 8차 적용 삭제 */
                App_Model_DW.is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
                App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Run_gtpc;
                App_Model_B.b_ChargingEnable_kg0a = On;
                App_Model_DW.is_WPCMode_Run = App_Mode_IN_WPCRun_Standby_dtiz;
                App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
                App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
              } else {
                /* Function_NFCCardDetection() 8차 적용 삭제
                   Function_NFCCardDetection() 8차 적용 삭제 */
              }
              break;

             case App_Mod_IN_WPCStop_TempErr_hdpu:
              {
                /* 1. */
                if ((uint32)rtu_Main_InSig_bvye == Off) {
                  sint32 b_previousEvent;

                  /* Function_NFCCardDetection() 8차 적용 삭제 */
                  App_Model_B.Output_BlinkState_mkqq = BlinkOff;
                  App_Model_DW.Counter_BlinkCnt = 0U;
                  b_previousEvent = App_Model_DW.sfEvent_owa4;
                  App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
                  if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
                    App_Tick_Timer_AmberINDBlk_li22();
                  }

                  App_Model_DW.sfEvent_owa4 = b_previousEvent;

                  /*  Non GFS  */
                  App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;
                  App_Model_DW.is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_eapl;
                  App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

                  /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                  App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
                } else {
                  App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
                }
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
        }

        /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
      }
      break;

     default:
      /* no actions */
      break;
    }
  }
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_WPCMode_Ena_l2l1(Bool rtu_Main_InSig_bvye, WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x)
{
  App_Model_DW.is_WPCMode_Enable = App_Model_IN_WPCMode_Stop_mk5d;
  App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;

  /* b_ROHMOperCmd = Off /_ Non GFS _/ */
  App_Model_B.b_ChargingEnable_kg0a = Off;

  /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
   *  ActionPort: '<S609>/ActionPort'
   */
  /* SwitchCase: '<S465>/Switch Case2' incorporates:
   *  Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC'
   */
  /* 1. */
  if ((uint32)rtu_Main_InSig_bvye == On) {
    App_Model_DW.is_WPCMode_Stop = App_Mod_IN_WPCStop_TempErr_hdpu;
    App_Model_B.Output_WPCWarning_jifb = Charging_error;

    /* b_WPCWarn = Charging_error 8차 LFRollBack */
    App_Model_B.Output_BlinkState_mkqq = BlinkOff;
    App_Model_DW.Counter_BlinkCnt = 0U;
    App_Function_LEDErrorBlink_f23p(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

    /* Function_NFCCardDetection() 8차 적용 삭제 Non GFS  */
    App_Model_B.Output_OPT_b_BlinkState_dvqq = On;
  } else {
    App_Model_DW.is_WPCMode_Stop = App__IN_WPCStop_NotTempErr_eapl;
    App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

    /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
    App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
  }

  /* End of SwitchCase: '<S465>/Switch Case2' */
  /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__llj1(void)
{
  App_Model_DW.is_Tick_Timer_PhoneLeft = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_PhoneLeft = 0U;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__dbsl(void)
{
  App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_PhoneWarningCheck = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_frp4 = 0U;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__mias(void)
{
  App_Model_DW.is_Tick_Timer_WarningComplete = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_WarningComplete = 0U;
  App_Model_B.b_Timer_WarningComplete_kjpg = 0U;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__pzsw(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_AmberINDBlk = 0U;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__fsed(void)
{
  App_Model_DW.is_Tick_Timer_WarningTypeCheck = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_WarningTypeCheck = 0U;
  App_Model_B.b_Timer_WarningTypeCheck_pkt3 = 0U;
}

/* Function for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
static void enter_internal_Tick_Timer__jpu3(void)
{
  App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Model_IN_Off_pxcg;
  App_Model_DW.Timer_AmberINDBlk2 = 0U;
}

/* System initialize for atomic system: '<S461>/WPC_MainControl_Function' */
void WPC_MainControl_Funct_btar_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_ld2g, Bool *rty_MainOut_Sig_a0gd, Bool *rty_MainOut_Sig_lm51, Bool *rty_MainOut_Sig_gfkd, uint16
  *rty_MainOut_Sig_bvye, uint16 *rty_MainOut_Sig_exqx, uint16 *rty_MainOut_Sig_c0zj, Bool *rty_MainOut_Sig_pfli, BlinkState *rty_MainOut_Sig_o3od, Bool *rty_MainOut_Sig_ll4c, uint16
  *rty_MainOut_Sig_kivv)
{
  /* SystemInitialize for IfAction SubSystem: '<S465>/Subsystem' */
  /* SystemInitialize for Chart: '<S608>/RWPC_MainControl2_250507' */
  App_Model_DW.sfEvent_lj3c = (sint32)App_Model_CALL_EVENT_mp4p;
  App_Model_DW.is_active_MainControl_dm2d = 0U;
  App_Model_DW.is_MainControl_bl3s = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Disable_gn4v = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Enable_d4ts = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_Amber_kl1n = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk_avth = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_Amber_pnxk = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2_bazp = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_PhnLeftCha = 0U;
  App_Model_DW.is_Tick_Timer_PhnLeftChattering = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_Phone_kep1 = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft_jafl = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_PhoneRemin = 0U;
  App_Model_DW.is_Tick_Timer_PhoneReminderChec = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_Phone_kixw = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarning_i3dp = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_Warni_cwy4 = 0U;
  App_Model_DW.is_Tick_Timer_WarningCompl_mg4r = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_c75_MainControl_Lib = 0U;
  App_Model_DW.b_WarnClearEnable_h2ib = Off;
  App_Model_DW.Timer_AmberINDBlk_ptlt = 0U;
  App_Model_DW.Timer_PhoneLeft_onnd = 0U;
  App_Model_DW.Timer_PhoneReminderCheck = 0U;
  App_Model_DW.Timer_PhoneWarningCheck_hbn3 = 0U;
  App_Model_DW.Timer_WarningComplete_jdlj = 0U;
  App_Model_DW.Counter_BlinkCnt_gerk = 0U;
  App_Model_DW.Timer_AmberINDBlk2_nmef = 0U;
  App_Model_DW.Timer_PhnLeftChattering_owvz = 0U;
  App_Model_DW.b_Timer_PhoneReminderCheck_is_R = Off;
  App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;
  App_Model_B.b_FANModeCmd_l0dm = Off;
  App_Model_B.b_GreenINDCmd_esxl = Off;
  App_Model_B.b_AmberINDCmd_ptyk = Off;
  App_Model_B.b_BlinkState_jzug = Off;
  App_Model_B.b_Timer_PhoneReminderCheck_hhaw = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_bn3m = 0U;
  App_Model_B.b_Timer_WarningComplete_n54s = 0U;
  App_Model_B.b_ChargingEnable_eht5 = Off;
  App_Model_B.BlinkState_dn5g = BlinkOff;
  App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
  App_Model_DW.b_WPCPhoneExist_prev = Off;
  App_Model_DW.b_WPCPhoneExist_start = Off;
  App_Model_DW.C_DrvDrSw_prev = Off;
  App_Model_DW.C_DrvDrSw_start = Off;
  App_Model_DW.C_AstDrSw_prev = Off;
  App_Model_DW.C_AstDrSw_start = Off;
  App_Model_DW.RWPCIndCmdState_prev_o0zq = RWPCIndCmdState__Default;
  App_Model_DW.RWPCIndCmdState_start_avm4 = RWPCIndCmdState__Default;
  App_Model_DW.L_IGN1_IN_prev = Off;
  App_Model_DW.L_IGN1_IN_start = Off;

  /* End of SystemInitialize for SubSystem: '<S465>/Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S465>/Subsystem1' */
  /* SystemInitialize for Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' incorporates:
   *  Chart: '<S608>/RWPC_MainControl2_250507'
   */
  App_Model_DW.sfEvent_owa4 = (sint32)App_Model_CALL_EVENT_mp4p;
  App_Model_DW.is_active_MainControl = 0U;
  App_Model_DW.is_MainControl = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Enable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Run = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_WPCMode_Stop = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_AmberINDBl = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_Amber_ifnu = 0U;
  App_Model_DW.is_Tick_Timer_AmberINDBlk2 = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_PhoneLeft = 0U;
  App_Model_DW.is_Tick_Timer_PhoneLeft = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_PhoneWarni = 0U;
  App_Model_DW.is_Tick_Timer_PhoneWarningCheck = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_WarningCom = 0U;
  App_Model_DW.is_Tick_Timer_WarningComplete = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_Tick_Timer_WarningTyp = 0U;
  App_Model_DW.is_Tick_Timer_WarningTypeCheck = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
  App_Model_DW.is_active_c72_MainControl_Lib = 0U;
  App_Model_DW.Timer_AmberINDBlk = 0U;
  App_Model_DW.Timer_PhoneLeft = 0U;
  App_Model_DW.Timer_PhoneWarningCheck = 0U;
  App_Model_DW.Timer_WarningComplete = 0U;
  App_Model_DW.Counter_BlinkCnt = 0U;
  App_Model_DW.Timer_WarningTypeCheck = 0U;
  App_Model_DW.b_WarnClearEnable = 0U;
  App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
  App_Model_DW.Timer_AmberINDBlk2 = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S465>/Subsystem' */
  App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;
  App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
  App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
  App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;
  App_Model_B.Output_OPT_b_BlinkState_dvqq = Off;

  /* End of SystemInitialize for SubSystem: '<S465>/Subsystem' */
  App_Model_B.b_Timer_WarningTypeCheck_pkt3 = 0U;
  App_Model_B.b_Timer_PhoneWarningCheck_frp4 = 0U;
  App_Model_B.b_Timer_WarningComplete_kjpg = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S465>/Subsystem' */
  App_Model_B.b_ChargingEnable_kg0a = Off;
  App_Model_B.Output_BlinkState_mkqq = BlinkOff;
  App_Model_B.b_PhnLeftChk_Enable_emma = Off;
  App_Model_DW.Input_OPT_b_WPCPhoneExist_prev = Off;
  App_Model_DW.Input_OPT_b_WPCPhoneExist_start = Off;
  App_Model_DW.RWPCIndCmdState_prev = RWPCIndCmdState__Default;
  App_Model_DW.RWPCIndCmdState_start = RWPCIndCmdState__Default;

  /* End of SystemInitialize for SubSystem: '<S465>/Subsystem' */
  App_Model_DW.Input_OPT_GearPosSta_prev = GearPos_P;
  App_Model_DW.Input_OPT_GearPosSta_start = GearPos_P;

  /* SystemInitialize for IfAction SubSystem: '<S465>/Subsystem' */
  App_Model_DW.b_DrvDrSw_prev = Off;
  App_Model_DW.b_DrvDrSw_start = Off;

  /* End of SystemInitialize for SubSystem: '<S465>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S465>/Subsystem1' */

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig = WPCWarningOff;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_o3od = BlinkOff;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_ll4c = Off;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_kivv = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_ld2g = Off;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_a0gd = Off;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_lm51 = Off;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_gfkd = Off;

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_bvye = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_exqx = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_c0zj = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S465>/Merge' */
  *rty_MainOut_Sig_pfli = Off;
}

/* Output and update for atomic system: '<S461>/WPC_MainControl_Function' */
void A_WPC_MainControl_Function_lgtv(Bool rtu_Main_InSig, Bool rtu_Main_InSig_ld2g, Bool rtu_Main_InSig_a0gd, Bool rtu_Main_InSig_lm51, C_WPCOnOffNvalueSet rtu_Main_InSig_gfkd, Bool
  rtu_Main_InSig_bvye, Bool rtu_Main_InSig_exqx, Bool rtu_Main_InSig_c0zj, Bool rtu_Main_InSig_pfli, DeviceState rtu_Main_InSig_o3od, WPCStatus rtu_Main_InSig_ll4c, Bool rtu_Main_InSig_kivv,
  WPCIndUSMState rtu_Main_InSig_i4oh, Bool rtu_Main_InSig_hp1x, RWPCIndCmdState rtu_Main_InSig_agui, GearPosSta rtu_Main_InSig_m0c4, C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_ld2g, Bool
  *rty_MainOut_Sig_a0gd, Bool *rty_MainOut_Sig_lm51, Bool *rty_MainOut_Sig_gfkd, uint16 *rty_MainOut_Sig_bvye, uint16 *rty_MainOut_Sig_exqx, uint16 *rty_MainOut_Sig_c0zj, Bool *rty_MainOut_Sig_pfli,
  BlinkState *rty_MainOut_Sig_o3od, Bool *rty_MainOut_Sig_ll4c, uint16 *rty_MainOut_Sig_kivv)
{
  /* SwitchCase: '<S465>/Switch Case2' */
  switch (rtu_Main_InSig) {
   case Off:
    {
      /* Outputs for IfAction SubSystem: '<S465>/Subsystem' incorporates:
       *  ActionPort: '<S608>/ActionPort'
       */
      /* Chart: '<S608>/RWPC_MainControl2_250507' */
      App_Model_DW.sfEvent_lj3c = (sint32)App_Model_CALL_EVENT_mp4p;
      App_Model_DW.b_WPCPhoneExist_prev = App_Model_DW.b_WPCPhoneExist_start;
      App_Model_DW.b_WPCPhoneExist_start = rtu_Main_InSig_pfli;
      App_Model_DW.C_DrvDrSw_prev = App_Model_DW.C_DrvDrSw_start;
      App_Model_DW.C_DrvDrSw_start = rtu_Main_InSig_c0zj;
      App_Model_DW.C_AstDrSw_prev = App_Model_DW.C_AstDrSw_start;
      App_Model_DW.C_AstDrSw_start = rtu_Main_InSig_exqx;
      App_Model_DW.RWPCIndCmdState_prev_o0zq = App_Model_DW.RWPCIndCmdState_start_avm4;
      App_Model_DW.RWPCIndCmdState_start_avm4 = rtu_Main_InSig_agui;
      App_Model_DW.L_IGN1_IN_prev = App_Model_DW.L_IGN1_IN_start;
      App_Model_DW.L_IGN1_IN_start = rtu_Main_InSig_kivv;
      if ((uint32)App_Model_DW.is_active_c75_MainControl_Lib == 0U) {
        Bool tmp;
        App_Model_DW.b_WPCPhoneExist_prev = rtu_Main_InSig_pfli;
        App_Model_DW.C_DrvDrSw_prev = rtu_Main_InSig_c0zj;
        App_Model_DW.C_AstDrSw_prev = rtu_Main_InSig_exqx;
        App_Model_DW.RWPCIndCmdState_prev_o0zq = rtu_Main_InSig_agui;
        App_Model_DW.L_IGN1_IN_prev = rtu_Main_InSig_kivv;
        App_Model_DW.is_active_c75_MainControl_Lib = 1U;
        App_Model_DW.is_active_MainControl_dm2d = 1U;
        App_Model_DW.is_MainControl_bl3s = App_Mod_IN_WPCMode_Disable_pcex;
        enter_atomic_WPCMode_Disab_ewpa();
        tmp = App_Model_DW.L_IGN1_IN_start;
        if ((App_Model_DW.L_IGN1_IN_prev != tmp) && ((uint32)tmp == Off)) {
          sint32 f_previousEvent;
          App_Model_DW.is_WPCMode_Disable_gn4v = Ap_IN_LeavingPhone_Warning_g052;
          f_previousEvent = App_Model_DW.sfEvent_lj3c;
          App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_PhoneWar_pusf;
          if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
            Tick_Timer_PhoneWarningChe_jngs();
          }

          App_Model_DW.sfEvent_lj3c = f_previousEvent;
          App_Mo_Function_WPCWarning_h44q(rtu_Main_InSig_gfkd, rtu_Main_InSig_exqx, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);
          App_Model_B.b_PhnLeftChk_Enable_jfyr = On;
        } else {
          App_Model_DW.is_WPCMode_Disable_gn4v = IN_LeavingPhone_NoWarning_lklq;
        }

        App_Model_DW.is_active_Tick_Timer_Phone_kep1 = 1U;
        enter_internal_Tick_Timer__hri5();
        App_Model_DW.is_active_Tick_Timer_Phone_kixw = 1U;
        enter_internal_Tick_Timer__jpd4();
        App_Model_DW.is_active_Tick_Timer_PhoneRemin = 1U;
        enter_internal_Tick_Timer__b25k();
        App_Model_DW.is_active_Tick_Timer_Warni_cwy4 = 1U;
        enter_internal_Tick_Timer__bo0g();
        App_Model_DW.is_active_Tick_Timer_Amber_kl1n = 1U;
        enter_internal_Tick_Timer__gv5p();
        App_Model_DW.is_active_Tick_Timer_Amber_pnxk = 1U;
        enter_internal_Tick_Timer__jc4l();
        App_Model_DW.is_active_Tick_Timer_PhnLeftCha = 1U;
        enter_internal_Tick_Timer__ku30();
      } else {
        if ((uint32)App_Model_DW.is_active_MainControl_dm2d != 0U) {
          switch (App_Model_DW.is_MainControl_bl3s) {
           case App_Mod_IN_WPCMode_Disable_pcex:
            App_Model_B.b_FANModeCmd_l0dm = Off;

            /* 1. */
            if ((uint32)rtu_Main_InSig_ll4c == WPCMode) {
              if ((uint32)App_Model_DW.is_WPCMode_Disable_gn4v == Ap_IN_LeavingPhone_Warning_g052) {
                App_Model_DW.b_WarnClearEnable_h2ib = Off;
                App_Model_B.b_PhnLeftChk_Enable_jfyr = Off;
                App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneLe_fatc;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kep1 != 0U) {
                  App_M_Tick_Timer_PhoneLeft_gv5q();
                }

                App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneWa_mdmw;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
                  Tick_Timer_PhoneWarningChe_jngs();
                }

                App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_PhoneRe_bamn;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
                  Tick_Timer_PhoneReminderCh_kfry();
                }

                App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_Warning_opqw;
                if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_cwy4 != 0U) {
                  Tick_Timer_WarningComplete_krdu();
                }

                App_Model_DW.sfEvent_lj3c = -1;
                App_Model_DW.is_WPCMode_Disable_gn4v = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
              } else {
                App_Model_DW.is_WPCMode_Disable_gn4v = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
              }

              App_Model_DW.is_MainControl_bl3s = App_Mode_IN_WPCMode_Enable_jlo4;
              App_Model_DW.is_WPCMode_Enable_d4ts = App_Model_IN_WPCMode_Stop_hnbq;
              App_Model_B.b_GreenINDCmd_esxl = Off;

              /* b_ROHMOperCmd = Off /_ Non GFS _/ */
              App_Model_B.b_ChargingEnable_eht5 = Off;

              /* 1. */
              if ((uint32)rtu_Main_InSig_bvye == On) {
                App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_WPCStop_TempErr_hdpu;
                App_Model_B.C_WPCWarning_jsvy = Charging_error;

                /* b_WPCWarn = Charging_error 8차 LFRollBack */
                App_Model_B.BlinkState_dn5g = BlinkOff;
                App_Model_DW.Counter_BlinkCnt_gerk = 0U;
                App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

                /*  Non GFS  */
                App_Model_B.b_BlinkState_jzug = On;
              } else {
                App_Model_DW.is_WPCMode_Stop_guvc = App__IN_WPCStop_NotTempErr_eapl;
                App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

                /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                App_Model_B.b_AmberINDCmd_ptyk = Off;
              }
            } else if ((uint32)App_Model_DW.is_WPCMode_Disable_gn4v == Ap_IN_LeavingPhone_Warning_g052) {
              App_Mo_Function_WPCWarning_h44q(rtu_Main_InSig_gfkd, rtu_Main_InSig_exqx, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);
            } else {
              /* no actions */
            }
            break;

           case App_Mode_IN_WPCMode_Enable_jlo4:
            {
              /* 1. */
              if ((uint32)rtu_Main_InSig_ll4c == ModeOff) {
                Bool tmp;
                switch (App_Model_DW.is_WPCMode_Enable_d4ts) {
                 case App_Model_IN_WPCMode_Run_oi2w:
                  exit_internal_WPCMode_Run_nddy();
                  App_Model_DW.is_WPCMode_Enable_d4ts = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
                  break;

                 case App_Model_IN_WPCMode_Stop_hnbq:
                  exit_internal_WPCMode_Stop_on5z();
                  App_Model_DW.is_WPCMode_Enable_d4ts = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
                  break;

                 default:
                  /* no actions */
                  break;
                }

                /* b_ROHMOperCmd = Off  /_ Non GFS _/ */
                App_Model_B.b_ChargingEnable_eht5 = Off;
                App_Model_DW.is_MainControl_bl3s = App_Mod_IN_WPCMode_Disable_pcex;
                enter_atomic_WPCMode_Disab_ewpa();
                tmp = App_Model_DW.L_IGN1_IN_start;
                if ((App_Model_DW.L_IGN1_IN_prev != tmp) && ((uint32)tmp == Off)) {
                  sint32 f_previousEvent;
                  App_Model_DW.is_WPCMode_Disable_gn4v = Ap_IN_LeavingPhone_Warning_g052;
                  f_previousEvent = App_Model_DW.sfEvent_lj3c;
                  App_Model_DW.sfEvent_lj3c = (sint32)event_Start_Timer_PhoneWar_pusf;
                  if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
                    Tick_Timer_PhoneWarningChe_jngs();
                  }

                  App_Model_DW.sfEvent_lj3c = f_previousEvent;
                  App_Mo_Function_WPCWarning_h44q(rtu_Main_InSig_gfkd, rtu_Main_InSig_exqx, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);
                  App_Model_B.b_PhnLeftChk_Enable_jfyr = On;
                } else {
                  App_Model_DW.is_WPCMode_Disable_gn4v = IN_LeavingPhone_NoWarning_lklq;
                }
              } else {
                switch (App_Model_DW.is_WPCMode_Enable_d4ts) {
                 case App_Model_IN_WPCMode_Run_oi2w:
                  App_Model_WPCMode_Run_nopn(rtu_Main_InSig_ld2g, rtu_Main_InSig_a0gd, rtu_Main_InSig_lm51, rtu_Main_InSig_bvye, rtu_Main_InSig_o3od, rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
                  break;

                 case App_Model_IN_WPCMode_Stop_hnbq:
                  App_Model_B.b_FANModeCmd_l0dm = Off;
                  if (((uint32)rtu_Main_InSig_o3od == Full_Charge) && ((uint32)rtu_Main_InSig_ld2g == Off) && ((uint32)rtu_Main_InSig_a0gd == Off) && ((uint32)rtu_Main_InSig_bvye == Off) && ((uint32)
                       rtu_Main_InSig_lm51 == Off)) {
                    exit_internal_WPCMode_Stop_on5z();
                    App_Model_DW.is_WPCMode_Enable_d4ts = App_Model_IN_WPCMode_Run_oi2w;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    App_Model_B.b_ChargingEnable_eht5 = On;
                    App_Model_DW.is_WPCMode_Run_iqye = IN_WPCRun_ChargingComplete_oknr;
                    App_Model_B.C_WPCWarning_jsvy = Charging_Complete;

                    /* b_WPCWarn = Charging_Complete 8차 LFRollBack */
                    App_Model_B.b_FANModeCmd_l0dm = On;
                    App_Model_B.b_GreenINDCmd_esxl = On;
                    App_Model_B.b_AmberINDCmd_ptyk = Off;
                  } else if (((uint32)rtu_Main_InSig_o3od == Charging) && ((uint32)rtu_Main_InSig_ld2g == Off) && ((uint32)rtu_Main_InSig_a0gd == Off) && ((uint32)rtu_Main_InSig_bvye == Off) &&
                             ((uint32)rtu_Main_InSig_lm51 == Off)) {
                    exit_internal_WPCMode_Stop_on5z();
                    App_Model_DW.is_WPCMode_Enable_d4ts = App_Model_IN_WPCMode_Run_oi2w;

                    /* b_ROHMOperCmd = On /_ Non GFS _/ */
                    App_Model_B.b_ChargingEnable_eht5 = On;
                    App_Model_DW.is_WPCMode_Run_iqye = App_Mod_IN_WPCRun_Charging_o2bp;
                    App_Model_B.C_WPCWarning_jsvy = PhoneCharging;

                    /* b_WPCWarn = PhoneCharging 8차 LFRollBack */
                    App_Model_B.b_FANModeCmd_l0dm = On;
                    Function_ChargingINDColor_ebqs(rtu_Main_InSig_i4oh);
                  } else {
                    switch (App_Model_DW.is_WPCMode_Stop_guvc) {
                     case App__IN_WPCStop_NotTempErr_eapl:
                      /* 1. */
                      if ((uint32)rtu_Main_InSig_bvye == On) {
                        App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_WPCStop_TempErr_hdpu;
                        App_Model_B.C_WPCWarning_jsvy = Charging_error;

                        /* b_WPCWarn = Charging_error 8차 LFRollBack */
                        App_Model_B.BlinkState_dn5g = BlinkOff;
                        App_Model_DW.Counter_BlinkCnt_gerk = 0U;
                        App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);

                        /*  Non GFS  */
                        App_Model_B.b_BlinkState_jzug = On;

                        /* 2. */
                      } else if (((uint32)rtu_Main_InSig_ld2g == Off) && ((uint32)rtu_Main_InSig_a0gd == Off) && ((uint32)rtu_Main_InSig_lm51 == Off)) {
                        App_Model_DW.is_WPCMode_Stop_guvc = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
                        App_Model_DW.is_WPCMode_Enable_d4ts = App_Model_IN_WPCMode_Run_oi2w;

                        /* b_ROHMOperCmd = On /_ Non GFS _/ */
                        App_Model_B.b_ChargingEnable_eht5 = On;
                        App_Model_DW.is_WPCMode_Run_iqye = App_Mode_IN_WPCRun_Standby_dtiz;
                        App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

                        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                        App_Model_B.b_GreenINDCmd_esxl = Off;
                        App_Model_B.b_AmberINDCmd_ptyk = Off;
                      } else {
                        /* no actions */
                      }
                      break;

                     case App_Mod_IN_WPCStop_TempErr_hdpu:
                      /* 1. */
                      if ((uint32)rtu_Main_InSig_bvye == Off) {
                        App_Model_B.BlinkState_dn5g = BlinkOff;
                        App_Model_DW.Counter_BlinkCnt_gerk = 0U;
                        App_Model_DW.sfEvent_lj3c = (sint32)event_Cancel_Timer_AmberIN_cile;
                        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
                          App_Tick_Timer_AmberINDBlk_ezex();
                        }

                        App_Model_DW.sfEvent_lj3c = -1;

                        /*  Non GFS  */
                        App_Model_B.b_BlinkState_jzug = Off;
                        App_Model_DW.is_WPCMode_Stop_guvc = App__IN_WPCStop_NotTempErr_eapl;
                        App_Model_B.C_WPCWarning_jsvy = WPCWarningOff;

                        /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
                        App_Model_B.b_AmberINDCmd_ptyk = Off;
                      } else {
                        App_Function_LEDErrorBlink_mwqe(rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
                      }
                      break;

                     default:
                      /* no actions */
                      break;
                    }
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

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kep1 != 0U) {
          App_M_Tick_Timer_PhoneLeft_gv5q();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Phone_kixw != 0U) {
          Tick_Timer_PhoneWarningChe_jngs();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneRemin != 0U) {
          Tick_Timer_PhoneReminderCh_kfry();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Warni_cwy4 != 0U) {
          Tick_Timer_WarningComplete_krdu();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_kl1n != 0U) {
          App_Tick_Timer_AmberINDBlk_ezex();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_pnxk != 0U) {
          Ap_Tick_Timer_AmberINDBlk2_cmm0();
        }

        if ((uint32)App_Model_DW.is_active_Tick_Timer_PhnLeftCha != 0U) {
          Tick_Timer_PhnLeftChatteri_bjsy();
        }
      }

      /* End of Chart: '<S608>/RWPC_MainControl2_250507' */

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig = App_Model_B.C_WPCWarning_jsvy;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_ld2g = App_Model_B.b_FANModeCmd_l0dm;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_ll4c = App_Model_B.b_PhnLeftChk_Enable_jfyr;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_kivv = App_Model_ConstB.b_Timer_WarningTypeCh_mfz2g;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_a0gd = App_Model_B.b_GreenINDCmd_esxl;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_lm51 = App_Model_B.b_AmberINDCmd_ptyk;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_gfkd = App_Model_B.b_BlinkState_jzug;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_bvye = App_Model_B.b_Timer_PhoneReminderCheck_hhaw;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_exqx = App_Model_B.b_Timer_PhoneWarningCheck_bn3m;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_c0zj = App_Model_B.b_Timer_WarningComplete_n54s;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_pfli = App_Model_B.b_ChargingEnable_eht5;

      /* SignalConversion generated from: '<S608>/ICEHEV' */
      *rty_MainOut_Sig_o3od = App_Model_B.BlinkState_dn5g;

      /* End of Outputs for SubSystem: '<S465>/Subsystem' */
    }
    break;

   case On:
    /* Outputs for IfAction SubSystem: '<S465>/Subsystem1' incorporates:
     *  ActionPort: '<S609>/ActionPort'
     */
    /* Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */
    App_Model_DW.sfEvent_owa4 = (sint32)App_Model_CALL_EVENT_mp4p;
    App_Model_DW.Input_OPT_b_WPCPhoneExist_prev = App_Model_DW.Input_OPT_b_WPCPhoneExist_start;
    App_Model_DW.Input_OPT_b_WPCPhoneExist_start = rtu_Main_InSig_pfli;
    App_Model_DW.RWPCIndCmdState_prev = App_Model_DW.RWPCIndCmdState_start;
    App_Model_DW.RWPCIndCmdState_start = rtu_Main_InSig_agui;
    App_Model_DW.Input_OPT_GearPosSta_prev = App_Model_DW.Input_OPT_GearPosSta_start;
    App_Model_DW.Input_OPT_GearPosSta_start = rtu_Main_InSig_m0c4;
    App_Model_DW.b_DrvDrSw_prev = App_Model_DW.b_DrvDrSw_start;
    App_Model_DW.b_DrvDrSw_start = rtu_Main_InSig_c0zj;
    if ((uint32)App_Model_DW.is_active_c72_MainControl_Lib == 0U) {
      App_Model_DW.Input_OPT_b_WPCPhoneExist_prev = rtu_Main_InSig_pfli;
      App_Model_DW.RWPCIndCmdState_prev = rtu_Main_InSig_agui;
      App_Model_DW.Input_OPT_GearPosSta_prev = rtu_Main_InSig_m0c4;
      App_Model_DW.b_DrvDrSw_prev = rtu_Main_InSig_c0zj;
      App_Model_DW.is_active_c72_MainControl_Lib = 1U;
      App_Model_DW.is_active_MainControl = 1U;
      App_Model_DW.is_MainControl = App_Model_IN_WPCMode_Init_e2hz;
      App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

      /* b_WPCWarn = WPCWarningOff 8차 LFRollBack */
      App_Model_B.Output_BlinkState_mkqq = BlinkOff;
      App_Model_DW.Counter_BlinkCnt = 0U;
      App_Model_DW.b_WarnClearEnable = Off;

      /* b_ChargingEnable = 8차 적용 삭제 */
      App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;
      App_Model_B.Output_OPT_b_GreenINDCmd_cxqe = Off;
      App_Model_B.Output_OPT_b_AmberINDCmd_mm4w = Off;

      /* Nidec */
      App_Model_B.b_PhnLeftChk_Enable_emma = Off;
      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneLe_kfwe;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_ofh0();
      }

      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneWa_jyj3;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_h4zv();
      }

      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_o4g2;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_ci2o();
      }

      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_AmberIN_cile;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
        App_Tick_Timer_AmberINDBlk_li22();
      }

      App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_denu;
      if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
        Tick_Timer_WarningTypeChec_bias();
      }

      App_Model_DW.sfEvent_owa4 = -1;
      App_Model_DW.is_active_Tick_Timer_PhoneLeft = 1U;
      enter_internal_Tick_Timer__llj1();
      App_Model_DW.is_active_Tick_Timer_PhoneWarni = 1U;
      enter_internal_Tick_Timer__dbsl();
      App_Model_DW.is_active_Tick_Timer_WarningCom = 1U;
      enter_internal_Tick_Timer__mias();
      App_Model_DW.is_active_Tick_Timer_AmberINDBl = 1U;
      enter_internal_Tick_Timer__pzsw();
      App_Model_DW.is_active_Tick_Timer_WarningTyp = 1U;
      enter_internal_Tick_Timer__fsed();
      App_Model_DW.is_active_Tick_Timer_Amber_ifnu = 1U;
      enter_internal_Tick_Timer__jpu3();
    } else {
      if ((uint32)App_Model_DW.is_active_MainControl != 0U) {
        switch (App_Model_DW.is_MainControl) {
         case App_Mod_IN_WPCMode_Disable_pcex:
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;

          /* 1. */
          if ((uint32)rtu_Main_InSig_ll4c == WPCMode) {
            if ((uint32)App_Model_DW.is_WPCMode_Disable == App_Model_IN_WPCMode_Off_likq) {
              if ((uint32)App_Model_DW.is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_g052) {
                /* Nidec */
                App_Model_B.b_PhnLeftChk_Enable_emma = Off;
                App_Model_DW.is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
              } else {
                App_Model_DW.is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
              }

              App_Model_DW.is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
            } else {
              App_Model_DW.is_WPCMode_Disable = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
            }

            App_Model_DW.b_WarnClearEnable = Off;
            App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneLe_kfwe;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
              App_M_Tick_Timer_PhoneLeft_ofh0();
            }

            App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_PhoneWa_jyj3;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
              Tick_Timer_PhoneWarningChe_h4zv();
            }

            App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_o4g2;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
              Tick_Timer_WarningComplete_ci2o();
            }

            App_Model_DW.sfEvent_owa4 = (sint32)event_Cancel_Timer_Warning_denu;
            if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
              Tick_Timer_WarningTypeChec_bias();
            }

            App_Model_DW.sfEvent_owa4 = -1;
            App_Model_DW.is_MainControl = App_Mode_IN_WPCMode_Enable_jlo4;
            enter_internal_WPCMode_Ena_l2l1(rtu_Main_InSig_bvye, rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
          } else {
            switch (App_Model_DW.is_WPCMode_Disable) {
             case App_Model_IN_WPCMode_NFC_bm2k:
              /* 1. */
              if (((uint32)rtu_Main_InSig_ll4c == ModeOff) || ((App_Model_DW.Input_OPT_GearPosSta_prev != App_Model_DW.Input_OPT_GearPosSta_start) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start ==
                    GearPos_P))) {
                /* Nide */
                App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_Off_likq;
                enter_internal_WPCMode_Off_fjwh(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli, rtu_Main_InSig_m0c4);
              }
              break;

             case App_Model_IN_WPCMode_Off_likq:
              /* 1. */
              if (((uint32)rtu_Main_InSig_ll4c == NFCMode) || ((uint32)rtu_Main_InSig_ll4c == LPCDMode) || ((uint32)rtu_Main_InSig_ll4c == PICCMode)) {
                if ((uint32)App_Model_DW.is_WPCMode_Off == Ap_IN_LeavingPhone_Warning_g052) {
                  App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

                  /* Nidec */
                  App_Model_B.b_PhnLeftChk_Enable_emma = Off;
                  App_Model_DW.is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
                } else {
                  App_Model_DW.is_WPCMode_Off = App_Mod_IN_NO_ACTIVE_CHILD_ad3y;
                }

                App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_bm2k;
                A_enter_atomic_WPCMode_NFC_khti();
              } else {
                switch (App_Model_DW.is_WPCMode_Off) {
                 case IN_LeavingPhone_NoWarning_lklq:
                  if ((App_Model_DW.Input_OPT_GearPosSta_prev != App_Model_DW.Input_OPT_GearPosSta_start) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start == GearPos_P)) {
                    App_Model_DW.is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_g052;
                    App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
                    App_Model_DW.b_WarnClearEnable = Off;
                    App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningT_imcq;
                    if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
                      Tick_Timer_WarningTypeChec_bias();
                    }

                    App_Model_DW.sfEvent_owa4 = -1;
                    App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);

                    /* Nidec */
                    App_Model_B.b_PhnLeftChk_Enable_emma = On;
                  }
                  break;

                 case Ap_IN_LeavingPhone_Warning_g052:
                  if ((App_Model_DW.Input_OPT_GearPosSta_prev != App_Model_DW.Input_OPT_GearPosSta_start) && ((uint32)App_Model_DW.Input_OPT_GearPosSta_start == GearPos_P)) {
                    App_Model_B.Output_WPCWarning_jifb = WPCWarningOff;

                    /* Nidec */
                    App_Model_DW.is_WPCMode_Off = Ap_IN_LeavingPhone_Warning_g052;
                    App_Model_DW.PhoneLeftWrnType_hyhg = PhoneLeftWrnType__Default;
                    App_Model_DW.b_WarnClearEnable = Off;
                    App_Model_DW.sfEvent_owa4 = (sint32)event_Start_Timer_WarningT_imcq;
                    if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
                      Tick_Timer_WarningTypeChec_bias();
                    }

                    App_Model_DW.sfEvent_owa4 = -1;
                    App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);

                    /* Nidec */
                    App_Model_B.b_PhnLeftChk_Enable_emma = On;
                  } else {
                    App_Mo_Function_WPCWarning_a0qj(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli);
                  }
                  break;

                 default:
                  /* no actions */
                  break;
                }
              }
              break;

             default:
              /* no actions */
              break;
            }
          }
          break;

         case App_Mode_IN_WPCMode_Enable_jlo4:
          App_Model_WPCMode_Enable_hnge(rtu_Main_InSig_ld2g, rtu_Main_InSig_a0gd, rtu_Main_InSig_lm51, rtu_Main_InSig_gfkd, rtu_Main_InSig_bvye, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli,
            rtu_Main_InSig_o3od, rtu_Main_InSig_ll4c, rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x, rtu_Main_InSig_m0c4);
          break;

         case App_Model_IN_WPCMode_Init_e2hz:
          App_Model_B.Output_OPT_b_FANModeCmd_ax5u = Off;

          /* 1. */
          if ((uint32)rtu_Main_InSig_ll4c != WPCMode) {
            App_Model_DW.is_MainControl = App_Mod_IN_WPCMode_Disable_pcex;
            enter_atomic_WPCMode_Disab_e3k4();

            /* 1. */
            if (((uint32)rtu_Main_InSig_ll4c == NFCMode) || ((uint32)rtu_Main_InSig_ll4c == LPCDMode) || ((uint32)rtu_Main_InSig_ll4c == PICCMode)) {
              App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_NFC_bm2k;
              A_enter_atomic_WPCMode_NFC_khti();
            } else {
              App_Model_DW.is_WPCMode_Disable = App_Model_IN_WPCMode_Off_likq;
              enter_internal_WPCMode_Off_fjwh(rtu_Main_InSig_gfkd, rtu_Main_InSig_c0zj, rtu_Main_InSig_pfli, rtu_Main_InSig_m0c4);
            }

            /* 2 */
          } else if ((uint32)rtu_Main_InSig_ll4c == WPCMode) {
            App_Model_DW.is_MainControl = App_Mode_IN_WPCMode_Enable_jlo4;
            enter_internal_WPCMode_Ena_l2l1(rtu_Main_InSig_bvye, rtu_Main_InSig_i4oh, rtu_Main_InSig_hp1x);
          } else {
            /* no actions */
          }
          break;

         default:
          /* no actions */
          break;
        }
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneLeft != 0U) {
        App_M_Tick_Timer_PhoneLeft_ofh0();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_PhoneWarni != 0U) {
        Tick_Timer_PhoneWarningChe_h4zv();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningCom != 0U) {
        Tick_Timer_WarningComplete_ci2o();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_AmberINDBl != 0U) {
        App_Tick_Timer_AmberINDBlk_li22();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_WarningTyp != 0U) {
        Tick_Timer_WarningTypeChec_bias();
      }

      if ((uint32)App_Model_DW.is_active_Tick_Timer_Amber_ifnu != 0U) {
        Ap_Tick_Timer_AmberINDBlk2_p5ah();
      }
    }

    /* End of Chart: '<S609>/RWPC_MainControl2_EV_250328_HMC' */

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig = App_Model_B.Output_WPCWarning_jifb;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_ld2g = App_Model_B.Output_OPT_b_FANModeCmd_ax5u;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_ll4c = App_Model_B.b_PhnLeftChk_Enable_emma;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_kivv = App_Model_B.b_Timer_WarningTypeCheck_pkt3;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_a0gd = App_Model_B.Output_OPT_b_GreenINDCmd_cxqe;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_lm51 = App_Model_B.Output_OPT_b_AmberINDCmd_mm4w;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_gfkd = App_Model_B.Output_OPT_b_BlinkState_dvqq;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_bvye = App_Model_ConstB.b_Timer_PhoneReminder_fuw5a;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_exqx = App_Model_B.b_Timer_PhoneWarningCheck_frp4;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_c0zj = App_Model_B.b_Timer_WarningComplete_kjpg;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_pfli = App_Model_B.b_ChargingEnable_kg0a;

    /* SignalConversion generated from: '<S609>/EV' */
    *rty_MainOut_Sig_o3od = App_Model_B.Output_BlinkState_mkqq;

    /* End of Outputs for SubSystem: '<S465>/Subsystem1' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S465>/Switch Case2' */
}

/* System initialize for atomic system: '<S638>/WPC_MainControl_Function' */
void WPC_MainControl_Funct_c5v2_Init(C_WPCWarning *rty_MainOut_Sig, Bool *rty_MainOut_Sig_grvv, Bool *rty_MainOut_Sig_nok3, Bool *rty_MainOut_Sig_fabi, Bool *rty_MainOut_Sig_pnk1, uint16
  *rty_MainOut_Sig_kq4p, uint16 *rty_MainOut_Sig_oxwl, uint16 *rty_MainOut_Sig_iocw, Bool *rty_MainOut_Sig_biyp, BlinkState *rty_MainOut_Sig_ig04, Bool *rty_MainOut_Sig_o5is, uint16
  *rty_MainOut_Sig_blb1)
{
  /* SystemInitialize for Chart: '<S642>/Chart' */
  App_Model_Chart_Init(&App_Model_B.MainContMode_ins3, &App_Model_DW.sf_Chart_nbto);

  /* SystemInitialize for IfAction SubSystem: '<S642>/nonNFC_ICE' */

  /* SystemInitialize for Chart: '<S834>/WPC_MainControl2_250507' */
  Ap_WPC_MainControl2_250507_Init(&App_Model_B.C_WPCWarning_bpme, &App_Model_B.b_FANModeCmd_gcqi, &App_Model_B.b_GreenINDCmd_c1er, &App_Model_B.b_AmberINDCmd_jnhz, &App_Model_B.b_BlinkState_epa5,
    &App_Model_B.b_Timer_PhoneReminderCheck_hbbx, &App_Model_B.b_Timer_PhoneWarningCheck_jhsv, &App_Model_B.b_Timer_WarningComplete_fxi2, &App_Model_B.b_ChargingEnable_jd44,
    &App_Model_B.BlinkState_avg4, &App_Model_B.b_PhnLeftChk_Enable_j1ju, &App_Model_DW.sf_WPC_MainControl2_250507_ju5u);

  /* End of SystemInitialize for SubSystem: '<S642>/nonNFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S642>/nonNFC_EV' */

  /* SystemInitialize for Chart: '<S833>/WPC_MainControl_EV_250328_HMC_dum' */
  WPC_MainControl2_EV_250328_Init(&App_Model_B.Output_WPCWarning_ddyd, &App_Model_B.Output_OPT_b_FANModeCmd_p5lq, &App_Model_B.Output_OPT_b_GreenINDCmd_coja, &App_Model_B.Output_OPT_b_AmberINDCmd_oela,
    &App_Model_B.Output_OPT_b_BlinkState_f0dr, &App_Model_B.b_Timer_WarningTypeCheck_degg, &App_Model_B.b_Timer_PhoneWarningCheck_kiyd, &App_Model_B.b_Timer_WarningComplete_ozo0,
    &App_Model_B.b_ChargingEnable_nvnd, &App_Model_B.Output_BlinkState_jxzf, &App_Model_B.b_PhnLeftChk_Enable_hvh5, &App_Model_DW.sf_WPC_MainControl_EV_250328_HM);

  /* End of SystemInitialize for SubSystem: '<S642>/nonNFC_EV' */

  /* SystemInitialize for IfAction SubSystem: '<S642>/NFC_ICE' */

  /* SystemInitialize for Chart: '<S832>/WPC_MainControl3_CardSync_250522' */
  WPC_MainControl3_CardSync__Init(&App_Model_B.C_WPCWarning_lymx, &App_Model_B.b_FANModeCmd_ixvd, &App_Model_B.b_GreenINDCmd_nknt, &App_Model_B.b_AmberINDCmd_etta, &App_Model_B.b_BlinkState_nmq0,
    &App_Model_B.b_Timer_PhoneReminderCheck_hvgy, &App_Model_B.b_Timer_PhoneWarningCheck_pzbu, &App_Model_B.b_Timer_WarningComplete_bjwa, &App_Model_B.b_ChargingEnable_bstx,
    &App_Model_B.BlinkState_hzlt, &App_Model_B.b_PhnLeftChk_Enable_k4pd, &App_Model_DW.sf_WPC_MainControl3_CardSy_mikn);

  /* End of SystemInitialize for SubSystem: '<S642>/NFC_ICE' */

  /* SystemInitialize for IfAction SubSystem: '<S642>/NFC_EV' */

  /* SystemInitialize for Chart: '<S831>/WPC_MainControl_EV_250328_HMC' */
  WPC_MainControl_EV_250522__Init(&App_Model_B.Output_WPCWarning, &App_Model_B.Output_OPT_b_FANModeCmd, &App_Model_B.Output_OPT_b_GreenINDCmd, &App_Model_B.Output_OPT_b_AmberINDCmd,
    &App_Model_B.Output_OPT_b_BlinkState, &App_Model_B.b_Timer_WarningTypeCheck_eu5y, &App_Model_B.b_Timer_PhoneWarningCheck_bvzj, &App_Model_B.b_Timer_WarningComplete_mdn4,
    &App_Model_B.b_ChargingEnable_huiu, &App_Model_B.Output_BlinkState, &App_Model_B.b_PhnLeftChk_Enable_cimn, &App_Model_DW.sf_WPC_MainControl_EV_2503_fwvf);

  /* End of SystemInitialize for SubSystem: '<S642>/NFC_EV' */

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig = WPCWarningOff;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_ig04 = BlinkOff;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_o5is = Off;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_blb1 = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_grvv = Off;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_nok3 = Off;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_fabi = Off;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_pnk1 = Off;

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_kq4p = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_oxwl = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_iocw = ((uint16)0U);

  /* SystemInitialize for Merge generated from: '<S642>/Merge' */
  *rty_MainOut_Sig_biyp = Off;
}

/* System reset for atomic system: '<S638>/WPC_MainControl_Function' */
void WPC_MainControl_Func_aih4_Reset(void)
{
  /* SystemReset for Chart: '<S642>/Chart' */
  App_Model_Chart_Reset(&App_Model_B.MainContMode_ins3, &App_Model_DW.sf_Chart_nbto);
}

/* Output and update for atomic system: '<S638>/WPC_MainControl_Function' */
void A_WPC_MainControl_Function_agcy(Bool rtu_Main_InSig, Bool rtu_Main_InSig_grvv, Bool rtu_Main_InSig_nok3, Bool rtu_Main_InSig_fabi, Bool rtu_Main_InSig_pnk1, C_WPCOnOffNvalueSet
  rtu_Main_InSig_kq4p, Bool rtu_Main_InSig_oxwl, Bool rtu_Main_InSig_iocw, Bool rtu_Main_InSig_biyp, Bool rtu_Main_InSig_ig04, DeviceState rtu_Main_InSig_o5is, WPCStatus rtu_Main_InSig_blb1, Bool
  rtu_Main_InSig_ikrw, WPCIndUSMState rtu_Main_InSig_fv4u, Bool rtu_Main_InSig_jnua, WPCIndCmdState rtu_Main_InSig_pbxa, GearPosSta rtu_Main_InSig_duir, C_WPCWarning rtu_Main_InSig_iouk, C_WPCWarning *
  rty_MainOut_Sig, Bool *rty_MainOut_Sig_grvv, Bool *rty_MainOut_Sig_nok3, Bool *rty_MainOut_Sig_fabi, Bool *rty_MainOut_Sig_pnk1, uint16 *rty_MainOut_Sig_kq4p, uint16 *rty_MainOut_Sig_oxwl, uint16
  *rty_MainOut_Sig_iocw, Bool *rty_MainOut_Sig_biyp, BlinkState *rty_MainOut_Sig_ig04, Bool *rty_MainOut_Sig_o5is, uint16 *rty_MainOut_Sig_blb1)
{
  /* Chart: '<S642>/Chart' */
  App_Model_Chart(rtu_Main_InSig, rtu_Main_InSig_grvv, &App_Model_B.MainContMode_ins3, &App_Model_DW.sf_Chart_nbto);

  /* SwitchCase: '<S642>/Switch Case1' */
  switch (App_Model_B.MainContMode_ins3) {
   case nonNFC_ICE:
    /* Outputs for IfAction SubSystem: '<S642>/nonNFC_ICE' incorporates:
     *  ActionPort: '<S834>/ActionPort'
     */
    /* Chart: '<S834>/WPC_MainControl2_250507' */
    App_Mod_WPC_MainControl2_250507(rtu_Main_InSig_nok3, rtu_Main_InSig_fabi, rtu_Main_InSig_pnk1, rtu_Main_InSig_kq4p, rtu_Main_InSig_oxwl, rtu_Main_InSig_iocw, rtu_Main_InSig_biyp,
      rtu_Main_InSig_ig04, rtu_Main_InSig_o5is, rtu_Main_InSig_blb1, rtu_Main_InSig_ikrw, rtu_Main_InSig_fv4u, rtu_Main_InSig_jnua, rtu_Main_InSig_pbxa, &App_Model_B.C_WPCWarning_bpme,
      &App_Model_B.b_FANModeCmd_gcqi, &App_Model_B.b_GreenINDCmd_c1er, &App_Model_B.b_AmberINDCmd_jnhz, &App_Model_B.b_BlinkState_epa5, &App_Model_B.b_Timer_PhoneReminderCheck_hbbx,
      &App_Model_B.b_Timer_PhoneWarningCheck_jhsv, &App_Model_B.b_Timer_WarningComplete_fxi2, &App_Model_B.b_ChargingEnable_jd44, &App_Model_B.BlinkState_avg4, &App_Model_B.b_PhnLeftChk_Enable_j1ju,
      &App_Model_DW.sf_WPC_MainControl2_250507_ju5u);

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig = App_Model_B.C_WPCWarning_bpme;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_grvv = App_Model_B.b_FANModeCmd_gcqi;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_o5is = App_Model_B.b_PhnLeftChk_Enable_j1ju;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_blb1 = App_Model_ConstB.b_Timer_WarningTypeChe_mfz2;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_nok3 = App_Model_B.b_GreenINDCmd_c1er;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_fabi = App_Model_B.b_AmberINDCmd_jnhz;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_pnk1 = App_Model_B.b_BlinkState_epa5;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_kq4p = App_Model_B.b_Timer_PhoneReminderCheck_hbbx;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_oxwl = App_Model_B.b_Timer_PhoneWarningCheck_jhsv;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_iocw = App_Model_B.b_Timer_WarningComplete_fxi2;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_biyp = App_Model_B.b_ChargingEnable_jd44;

    /* SignalConversion generated from: '<S834>/nonNFC_nonEV' */
    *rty_MainOut_Sig_ig04 = App_Model_B.BlinkState_avg4;

    /* End of Outputs for SubSystem: '<S642>/nonNFC_ICE' */
    break;

   case nonNFC_EV:
    /* Outputs for IfAction SubSystem: '<S642>/nonNFC_EV' incorporates:
     *  ActionPort: '<S833>/ActionPort'
     */
    /* Chart: '<S833>/WPC_MainControl_EV_250328_HMC_dum' */
    WPC_MainControl2_EV_250328_HMC(rtu_Main_InSig_nok3, rtu_Main_InSig_fabi, rtu_Main_InSig_pnk1, rtu_Main_InSig_ig04, rtu_Main_InSig_kq4p, rtu_Main_InSig_oxwl, rtu_Main_InSig_o5is,
      rtu_Main_InSig_blb1, rtu_Main_InSig_fv4u, rtu_Main_InSig_biyp, rtu_Main_InSig_duir, rtu_Main_InSig_jnua, rtu_Main_InSig_pbxa, &App_Model_B.Output_WPCWarning_ddyd,
      &App_Model_B.Output_OPT_b_FANModeCmd_p5lq, &App_Model_B.Output_OPT_b_GreenINDCmd_coja, &App_Model_B.Output_OPT_b_AmberINDCmd_oela, &App_Model_B.Output_OPT_b_BlinkState_f0dr,
      &App_Model_B.b_Timer_WarningTypeCheck_degg, &App_Model_B.b_Timer_PhoneWarningCheck_kiyd, &App_Model_B.b_Timer_WarningComplete_ozo0, &App_Model_B.b_ChargingEnable_nvnd,
      &App_Model_B.Output_BlinkState_jxzf, &App_Model_B.b_PhnLeftChk_Enable_hvh5, &App_Model_DW.sf_WPC_MainControl_EV_250328_HM);

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig = App_Model_B.Output_WPCWarning_ddyd;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_grvv = App_Model_B.Output_OPT_b_FANModeCmd_p5lq;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_o5is = App_Model_B.b_PhnLeftChk_Enable_hvh5;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_blb1 = App_Model_B.b_Timer_WarningTypeCheck_degg;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_nok3 = App_Model_B.Output_OPT_b_GreenINDCmd_coja;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_fabi = App_Model_B.Output_OPT_b_AmberINDCmd_oela;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_pnk1 = App_Model_B.Output_OPT_b_BlinkState_f0dr;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_kq4p = App_Model_ConstB.b_Timer_PhoneReminderC_fuw5;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_oxwl = App_Model_B.b_Timer_PhoneWarningCheck_kiyd;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_iocw = App_Model_B.b_Timer_WarningComplete_ozo0;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_biyp = App_Model_B.b_ChargingEnable_nvnd;

    /* SignalConversion generated from: '<S833>/nonNFC_EV' */
    *rty_MainOut_Sig_ig04 = App_Model_B.Output_BlinkState_jxzf;

    /* End of Outputs for SubSystem: '<S642>/nonNFC_EV' */
    break;

   case NFC_ICE:
    /* Outputs for IfAction SubSystem: '<S642>/NFC_ICE' incorporates:
     *  ActionPort: '<S832>/ActionPort'
     */
    /* Chart: '<S832>/WPC_MainControl3_CardSync_250522' */
    WPC_MainControl3_CardSync_25052(rtu_Main_InSig_nok3, rtu_Main_InSig_fabi, rtu_Main_InSig_pnk1, rtu_Main_InSig_kq4p, rtu_Main_InSig_oxwl, rtu_Main_InSig_iocw, rtu_Main_InSig_biyp,
      rtu_Main_InSig_ig04, rtu_Main_InSig_o5is, rtu_Main_InSig_blb1, rtu_Main_InSig_ikrw, rtu_Main_InSig_fv4u, rtu_Main_InSig_jnua, rtu_Main_InSig_pbxa, rtu_Main_InSig_iouk,
      &App_Model_B.C_WPCWarning_lymx, &App_Model_B.b_FANModeCmd_ixvd, &App_Model_B.b_GreenINDCmd_nknt, &App_Model_B.b_AmberINDCmd_etta, &App_Model_B.b_BlinkState_nmq0,
      &App_Model_B.b_Timer_PhoneReminderCheck_hvgy, &App_Model_B.b_Timer_PhoneWarningCheck_pzbu, &App_Model_B.b_Timer_WarningComplete_bjwa, &App_Model_B.b_ChargingEnable_bstx,
      &App_Model_B.BlinkState_hzlt, &App_Model_B.b_PhnLeftChk_Enable_k4pd, &App_Model_DW.sf_WPC_MainControl3_CardSy_mikn);

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig = App_Model_B.C_WPCWarning_lymx;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_grvv = App_Model_B.b_FANModeCmd_ixvd;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_o5is = App_Model_B.b_PhnLeftChk_Enable_k4pd;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_blb1 = App_Model_ConstB.b_Timer_WarningTypeCheck;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_nok3 = App_Model_B.b_GreenINDCmd_nknt;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_fabi = App_Model_B.b_AmberINDCmd_etta;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_pnk1 = App_Model_B.b_BlinkState_nmq0;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_kq4p = App_Model_B.b_Timer_PhoneReminderCheck_hvgy;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_oxwl = App_Model_B.b_Timer_PhoneWarningCheck_pzbu;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_iocw = App_Model_B.b_Timer_WarningComplete_bjwa;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_biyp = App_Model_B.b_ChargingEnable_bstx;

    /* SignalConversion generated from: '<S832>/NFC_nonEV' */
    *rty_MainOut_Sig_ig04 = App_Model_B.BlinkState_hzlt;

    /* End of Outputs for SubSystem: '<S642>/NFC_ICE' */
    break;

   case NFC_EV:
    /* Outputs for IfAction SubSystem: '<S642>/NFC_EV' incorporates:
     *  ActionPort: '<S831>/ActionPort'
     */
    /* Chart: '<S831>/WPC_MainControl_EV_250328_HMC' */
    A_WPC_MainControl_EV_250522_HMC(rtu_Main_InSig_nok3, rtu_Main_InSig_fabi, rtu_Main_InSig_oxwl, rtu_Main_InSig_ig04, rtu_Main_InSig_kq4p, rtu_Main_InSig_pnk1, rtu_Main_InSig_o5is,
      rtu_Main_InSig_blb1, rtu_Main_InSig_fv4u, rtu_Main_InSig_biyp, rtu_Main_InSig_duir, rtu_Main_InSig_jnua, rtu_Main_InSig_pbxa, rtu_Main_InSig_iouk, &App_Model_B.Output_WPCWarning,
      &App_Model_B.Output_OPT_b_FANModeCmd, &App_Model_B.Output_OPT_b_GreenINDCmd, &App_Model_B.Output_OPT_b_AmberINDCmd, &App_Model_B.Output_OPT_b_BlinkState,
      &App_Model_B.b_Timer_WarningTypeCheck_eu5y, &App_Model_B.b_Timer_PhoneWarningCheck_bvzj, &App_Model_B.b_Timer_WarningComplete_mdn4, &App_Model_B.b_ChargingEnable_huiu,
      &App_Model_B.Output_BlinkState, &App_Model_B.b_PhnLeftChk_Enable_cimn, &App_Model_DW.sf_WPC_MainControl_EV_2503_fwvf);

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig = App_Model_B.Output_WPCWarning;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_grvv = App_Model_B.Output_OPT_b_FANModeCmd;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_o5is = App_Model_B.b_PhnLeftChk_Enable_cimn;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_blb1 = App_Model_B.b_Timer_WarningTypeCheck_eu5y;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_nok3 = App_Model_B.Output_OPT_b_GreenINDCmd;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_fabi = App_Model_B.Output_OPT_b_AmberINDCmd;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_pnk1 = App_Model_B.Output_OPT_b_BlinkState;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_kq4p = App_Model_ConstB.b_Timer_PhoneReminderCheck;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_oxwl = App_Model_B.b_Timer_PhoneWarningCheck_bvzj;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_iocw = App_Model_B.b_Timer_WarningComplete_mdn4;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_biyp = App_Model_B.b_ChargingEnable_huiu;

    /* SignalConversion generated from: '<S831>/NFC_EV' */
    *rty_MainOut_Sig_ig04 = App_Model_B.Output_BlinkState;

    /* End of Outputs for SubSystem: '<S642>/NFC_EV' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S642>/Switch Case1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
