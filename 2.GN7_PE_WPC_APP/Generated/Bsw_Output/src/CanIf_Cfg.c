/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**  FILE-NAME: CanIf_Cfg.c                                                    **
**                                                                            **
**  MODULE-NAME: AUTOSAR CAN Interface Module                                 **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **                                                                
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 3.2.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            ** 
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_CDD_Router.arxml
 *                Configuration\ECU\Ecud_CanIf.arxml
 *                Configuration\ECU\Ecud_CanNm.arxml
 *                Configuration\ECU\Ecud_CanTp.arxml
 *                Configuration\ECU\Ecud_CanTrcv.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_Nm.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 *                Configuration\ECU\Mcal\Ecud_Can.arxml
 * GENERATED ON: The time-stamp is removed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_PCTypes.h"
#include "CanIf_Can.h"
#include "CanIf_Version.h"        /* CanIf Version header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define CANIF_CFG_C_AR_RELEASE_MAJOR_VERSION               (4)
#define CANIF_CFG_C_AR_RELEASE_MINOR_VERSION               (0)
#define CANIF_CFG_C_AR_RELEASE_REVISION_VERSION            (3)
#define CANIF_CFG_C_SW_MAJOR_VERSION                       (3)
#define CANIF_CFG_C_SW_MINOR_VERSION                       (2)
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_PCTYPES_AR_RELEASE_MAJOR_VERSION != \
  CANIF_CFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "CanIf_Cfg.c : Mismatch in Specification Major Version"
#endif

#if (CANIF_PCTYPES_AR_RELEASE_MINOR_VERSION != \
  CANIF_CFG_C_AR_RELEASE_MINOR_VERSION)
  #error "CanIf_Cfg.c : Mismatch in Specification Minor Version"
#endif

#if (CANIF_PCTYPES_AR_RELEASE_REVISION_VERSION != \
  CANIF_CFG_C_AR_RELEASE_REVISION_VERSION)
  #error "CanIf_Cfg.c : Mismatch in Specification Revision Version"
#endif

#if (CANIF_PCTYPES_SW_MAJOR_VERSION != CANIF_CFG_C_SW_MAJOR_VERSION)
  #error "CanIf_Cfg.c : Mismatch in Software Major Version"
#endif

#if (CANIF_PCTYPES_SW_MINOR_VERSION != CANIF_CFG_C_SW_MINOR_VERSION)
  #error "CanIf_Cfg.c : Mismatch in Software Minor Version"
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Initialization Structure                              **
*******************************************************************************/

/* Global array for Tx and Rx notificaton status */
/* VAR(uint8, CANIF_VAR) 
  CanIf_GaaBitArray[]; */

/*  Global array for Queue allocation */
/* static P2VAR(CanIf_TxQueue, CANIF_VAR, CANIF_VAR) 
  CanIf_GaaQueueList[]; */

/* Global array for Rx L-PDU notify structure */
/* VAR(CanIf_RxLpduNotify, CANIF_VAR) 
  CanIf_GaaRxLpduNotify[]; */

/* Global variable for the transmit queue */
/* VAR(CanIf_TxQueue, CANIF_VAR) 
  CanIf_GaaTxQueue[]; */

/* Global array for tx buffer of transmit queue */
/* VAR(uint8, CANIF_VAR) 
  CanIf_GaaTxSharedBuffer[]; */


/* CONST(uint8, CANIF_CONST) CanIf_GaaCanCntrlIds[]; */
/* CONST(CanIf_CanDriver, CANIF_CONST)CanIf_GaaCanDriver[]; */
/* CONST(CanIf_TransceiverConfigType, CANIF_CONST)CanIf_GaaCanTrcv[]; */
/*CONST(CanIf_CanTrcvDriver, CANIF_CONST)CanIf_GaaCanTrcvDriver[]; */
/* CONST(uint8, CANIF_CONST) CanIf_GaaCanTrcvIds[]; */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for Controller */
CONST(CanIf_ControllerConfigType, CANIF_CONST)CanIf_GaaControllerConfigType[] =
{
  /* CONTROLLER 0 - CanIf_0 */
  {
    /* *pTxLpdu */
    &CanIf_GaaTxLpdu[0],

    /* ddNoOfTxPdu */
    0x07,

    /* ucCanControllerId */
    0x00
  },

  /* CONTROLLER 1 - CanIf_1 */
  {
    /* *pTxLpdu */
    &CanIf_GaaTxLpdu[7],

    /* ddNoOfTxPdu */
    0x04,

    /* ucCanControllerId */
    0x01
  }
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for HRH */
CONST(CanIf_Hrh, CANIF_CONST) CanIf_GaaHrh[] =
{
  /* HRH 0 - CanGeneralCntrl0Hrh0 */
  {
    /* ddRxLpduIndex */
    0x0000,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 1 - CanGeneralCntrl0Hrh1 */
  {
    /* ddRxLpduIndex */
    0x0001,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x00,

    /* ucControllerId */
    0x00
  },

  /* HRH 2 - CanGeneralCntrl0Hrh2 */
  {
    /* ddRxLpduIndex */
    0x000C,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 3 - CanGeneralCntrl0Hrh3 */
  {
    /* ddRxLpduIndex */
    0x0014,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 4 - CanGeneralCntrl0Hrh4 */
  {
    /* ddRxLpduIndex */
    0x0015,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 5 - CanGeneralCntrl0Hrh5 */
  {
    /* ddRxLpduIndex */
    0x0016,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 6 - CanGeneralCntrl0Hrh6 */
  {
    /* ddRxLpduIndex */
    0x0017,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 7 - CanGeneralCntrl0Hrh7 */
  {
    /* ddRxLpduIndex */
    0x0018,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 8 - CanGeneralCntrl0Hrh8 */
  {
    /* ddRxLpduIndex */
    0x0019,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 9 - CanGeneralCntrl0Hrh9 */
  {
    /* ddRxLpduIndex */
    0x001A,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 10 - CanGeneralCntrl0Hrh10 */
  {
    /* ddRxLpduIndex */
    0x0002,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 11 - CanGeneralCntrl0Hrh11 */
  {
    /* ddRxLpduIndex */
    0x0003,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 12 - CanGeneralCntrl0Hrh12 */
  {
    /* ddRxLpduIndex */
    0x0004,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 13 - CanGeneralCntrl0Hrh13 */
  {
    /* ddRxLpduIndex */
    0x0005,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 14 - CanGeneralCntrl0Hrh14 */
  {
    /* ddRxLpduIndex */
    0x0006,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 15 - CanGeneralCntrl0Hrh15 */
  {
    /* ddRxLpduIndex */
    0x0007,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 16 - CanGeneralCntrl0Hrh16 */
  {
    /* ddRxLpduIndex */
    0x0008,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 17 - CanGeneralCntrl0Hrh17 */
  {
    /* ddRxLpduIndex */
    0x0009,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 18 - CanGeneralCntrl0Hrh18 */
  {
    /* ddRxLpduIndex */
    0x000A,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 19 - CanGeneralCntrl0Hrh19 */
  {
    /* ddRxLpduIndex */
    0x000B,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 20 - CanGeneralCntrl0Hrh20 */
  {
    /* ddRxLpduIndex */
    0x000D,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 21 - CanGeneralCntrl0Hrh21 */
  {
    /* ddRxLpduIndex */
    0x000E,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 22 - CanGeneralCntrl0Hrh22 */
  {
    /* ddRxLpduIndex */
    0x000F,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 23 - CanGeneralCntrl0Hrh23 */
  {
    /* ddRxLpduIndex */
    0x0010,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 24 - CanGeneralCntrl0Hrh24 */
  {
    /* ddRxLpduIndex */
    0x0011,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 25 - CanGeneralCntrl0Hrh25 */
  {
    /* ddRxLpduIndex */
    0x0012,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x00
  },

  /* HRH 26 - CanGeneralCntrl0Hrh26 */
  {
    /* ddRxLpduIndex */
    0x0013,

    /* ddNoOfRxLpdusRange */
    0x01,

    /* ddNoOfRxLpdusList */
    0x00,

    /* ucFilterMethod */
    0x01,

    /* ucControllerId */
    0x00
  },

  /* HRH 27 - CanGeneralCntrl1Hrh27 */
  {
    /* ddRxLpduIndex */
    0x001B,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x04,

    /* ucControllerId */
    0x01
  },

  /* HRH 28 - CanGeneralCntrl1Hrh28 */
  {
    /* ddRxLpduIndex */
    0x001C,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x04,

    /* ucControllerId */
    0x01
  },

  /* HRH 29 - CanGeneralCntrl1Hrh29 */
  {
    /* ddRxLpduIndex */
    0x001D,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x04,

    /* ucControllerId */
    0x01
  },

  /* HRH 30 - CanGeneralCntrl1Hrh30 */
  {
    /* ddRxLpduIndex */
    0x001E,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x01
  },

  /* HRH 31 - CanGeneralCntrl1Hrh31 */
  {
    /* ddRxLpduIndex */
    0x001F,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x01
  },

  /* HRH 32 - CanGeneralCntrl1Hrh32 */
  {
    /* ddRxLpduIndex */
    0x0020,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x01
  },

  /* HRH 33 - CanGeneralCntrl1Hrh33 */
  {
    /* ddRxLpduIndex */
    0x0021,

    /* ddNoOfRxLpdusRange */
    0x00,

    /* ddNoOfRxLpdusList */
    0x01,

    /* ucFilterMethod */
    0x03,

    /* ucControllerId */
    0x01
  },

  /* HRH 34 - CanGeneralCntrl1Hrh34 */
  {
    /* ddRxLpduIndex */
    0x0022,

    /* ddNoOfRxLpdusRange */
    0x01,

    /* ddNoOfRxLpdusList */
    0x00,

    /* ucFilterMethod */
    0x01,

    /* ucControllerId */
    0x01
  }
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for HRH Init */
CONST(CanIf_HrhInit, CANIF_CONST)CanIf_GaaHrhInit[] =
{
  /* HRH_INIT 0 - CanGeneral */
  {
    /* usMaxHrhId */
    0x0022
  }
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for HRH Map array */
CONST(uint16, CANIF_CONST) CanIf_GaaHrhMapArray[] =
{
  0x0000,

  0x0001,

  0x0002,

  0x0003,

  0x0004,

  0x0005,

  0x0006,

  0x0007,

  0x0008,

  0x0009,

  0x000A,

  0x000B,

  0x000C,

  0x000D,

  0x000E,

  0x000F,

  0x0010,

  0x0011,

  0x0012,

  0x0013,

  0x0014,

  0x0015,

  0x0016,

  0x0017,

  0x0018,

  0x0019,

  0x001A,

  0x001B,

  0x001C,

  0x001D,

  0x001E,

  0x001F,

  0x0020,

  0x0021,

  0x0022
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* CONST(CanIf_RxCbkUser, CANIF_CONST)CanIf_GaaRxCbkUser[]; */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for Rx L-PDU(Range Or List) */
CONST(CanIf_RxLpdu, CANIF_VAR) CanIf_GaaRxLpdu[] =
{
  /* RX-LIST-RANGE 0 - Ctrl_Lis2015_CanIfRxPduCfg_IN_WPC_BCAN_0x7df_BCAN_GST_ALL */
  {
    /* ddCanIdLl */
    0x000007DFU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0000,

    /* ddTargetId */
    0x0002,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x01,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 1 - Ctrl_Lis1829_CanIfRxPduCfg_IN_WPC_BCAN_0x725_BCAN_GST_WPC */
  {
    /* ddCanIdLl */
    0x00000725U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x001A,

    /* ddTargetId */
    0x0000,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x01,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 2 - Ctrl_Lis830_CanIfRxPduCfg_IN_WPC_BCAN_0x33e_BCAN_SBCM_RL_FD_01_200ms */
  {
    /* ddCanIdLl */
    0x0000033EU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0009,

    /* ddTargetId */
    0x0009,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x18,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 3 - Ctrl_Lis829_CanIfRxPduCfg_IN_WPC_BCAN_0x33d_BCAN_SBCM_RR_FD_01_200ms */
  {
    /* ddCanIdLl */
    0x0000033DU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x000A,

    /* ddTargetId */
    0x0008,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x18,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 4 - Ctrl_Lis813_CanIfRxPduCfg_IN_WPC_BCAN_0x32d_BCAN_SBCM_DRV_FD_01_200ms */
  {
    /* ddCanIdLl */
    0x0000032DU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x000B,

    /* ddTargetId */
    0x000C,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 5 - Ctrl_Lis811_CanIfRxPduCfg_IN_WPC_BCAN_0x32b_BCAN_SBCM_AST_FD_01_200ms */
  {
    /* ddCanIdLl */
    0x0000032BU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x000C,

    /* ddTargetId */
    0x000D,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 6 - Ctrl_Lis789_CanIfRxPduCfg_IN_WPC_BCAN_0x315_BCAN_CLU_20_200ms */
  {
    /* ddCanIdLl */
    0x00000315U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x000D,

    /* ddTargetId */
    0x000E,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x10,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 7 - Ctrl_Lis788_CanIfRxPduCfg_IN_WPC_BCAN_0x314_BCAN_RWPC_FD_01_200ms */
  {
    /* ddCanIdLl */
    0x00000314U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x000E,

    /* ddTargetId */
    0x000F,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x10,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 8 - Ctrl_Lis745_CanIfRxPduCfg_IN_WPC_BCAN_0x2e9_BCAN_PDC_FD_15_300ms */
  {
    /* ddCanIdLl */
    0x000002E9U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0018,

    /* ddTargetId */
    0x001D,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 9 - Ctrl_Lis426_CanIfRxPduCfg_IN_WPC_BCAN_0x1aa_BCAN_CLU_01_20ms */
  {
    /* ddCanIdLl */
    0x000001AAU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x000F,

    /* ddTargetId */
    0x0012,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x10,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 10 - Ctrl_Lis278_CanIfRxPduCfg_IN_WPC_BCAN_0x116_BCAN_HU_USM_05_00ms */
  {
    /* ddCanIdLl */
    0x00000116U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0010,

    /* ddTargetId */
    0x0007,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 11 - Ctrl_Lis276_CanIfRxPduCfg_IN_WPC_BCAN_0x114_BCAN_HU_USM_04_00ms */
  {
    /* ddCanIdLl */
    0x00000114U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0019,

    /* ddTargetId */
    0x001E,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 12 - Ctrl_Lis1242_CanIfRxPduCfg_IN_WPC_BCAN_0x4da_BCAN_CLU_09_00ms */
  {
    /* ddCanIdLl */
    0x000004DAU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0001,

    /* ddTargetId */
    0x0003,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 13 - Ctrl_Lis274_CanIfRxPduCfg_IN_WPC_BCAN_0x112_BCAN_HU_USM_02_00ms */
  {
    /* ddCanIdLl */
    0x00000112U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0011,

    /* ddTargetId */
    0x0005,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 14 - Ctrl_Lis273_CanIfRxPduCfg_IN_WPC_BCAN_0x111_BCAN_HU_USM_01_00ms */
  {
    /* ddCanIdLl */
    0x00000111U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0012,

    /* ddTargetId */
    0x0006,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 15 - Ctrl_Lis261_CanIfRxPduCfg_IN_WPC_BCAN_0x105_BCAN_EMS_07_10ms */
  {
    /* ddCanIdLl */
    0x00000105U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0013,

    /* ddTargetId */
    0x000B,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 16 - Ctrl_Lis256_CanIfRxPduCfg_IN_WPC_BCAN_0x100_BCAN_EMS_02_10ms */
  {
    /* ddCanIdLl */
    0x00000100U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0014,

    /* ddTargetId */
    0x000A,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 17 - Ctrl_Lis250_CanIfRxPduCfg_IN_WPC_BCAN_0xfa_BCAN_HCU_03_10ms */
  {
    /* ddCanIdLl */
    0x000000FAU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0015,

    /* ddTargetId */
    0x0004,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 18 - Ctrl_Lis53_CanIfRxPduCfg_IN_WPC_BCAN_0x35_BCAN_VCU_01_10ms */
  {
    /* ddCanIdLl */
    0x00000035U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0016,

    /* ddTargetId */
    0x0000,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 19 - Cntrl_CanGeneralCntrl0Hrh26_Ran2549874688-2549874942_CanIfRxPduCfg_IN_WPC_BCAN_CANNM_MESSAGE */
  {
    /* ddCanIdLl */
    0x97FC0000U,

    /* ddCanIdUl */
    0x97FC00FEU,

    /* ddRxPduId */
    0x0017,

    /* ddTargetId */
    0x0000,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x02,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x1FFFFFFFU
  },

  /* RX-LIST-RANGE 20 - Ctrl_Lis1233_CanIfRxPduCfg_IN_WPC_BCAN_0x4d1_BCAN_CLU_05_00ms */
  {
    /* ddCanIdLl */
    0x000004D1U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0002,

    /* ddTargetId */
    0x0002,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 21 - Ctrl_Lis1025_CanIfRxPduCfg_IN_WPC_BCAN_0x401_BCAN_BDC_FD_SMK_02_200ms */
  {
    /* ddCanIdLl */
    0x00000401U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0003,

    /* ddTargetId */
    0x0001,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 22 - Ctrl_Lis994_CanIfRxPduCfg_IN_WPC_BCAN_0x3e2_BCAN_PDC_FD_03_200ms */
  {
    /* ddCanIdLl */
    0x000003E2U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0004,

    /* ddTargetId */
    0x0013,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x10,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 23 - Ctrl_Lis980_CanIfRxPduCfg_IN_WPC_BCAN_0x3d4_BCAN_BDC_FD_05_200ms */
  {
    /* ddCanIdLl */
    0x000003D4U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0005,

    /* ddTargetId */
    0x0015,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 24 - Ctrl_Lis977_CanIfRxPduCfg_IN_WPC_BCAN_0x3d1_BCAN_BDC_FD_02_200ms */
  {
    /* ddCanIdLl */
    0x000003D1U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0006,

    /* ddTargetId */
    0x0014,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 25 - Ctrl_Lis870_CanIfRxPduCfg_IN_WPC_BCAN_0x366_BCAN_HU_GW_03_200ms */
  {
    /* ddCanIdLl */
    0x00000366U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0007,

    /* ddTargetId */
    0x0010,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x18,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 26 - Ctrl_Lis849_CanIfRxPduCfg_IN_WPC_BCAN_0x351_BCAN_IAU_FD_04_200ms */
  {
    /* ddCanIdLl */
    0x00000351U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0008,

    /* ddTargetId */
    0x0011,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x00,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 27 - Ctrl_Lis2348810500_CanIfRxPduCfg_IN_WPC_LCAN_0xc000104_LCAN_L_TP_BDC_FD_L_WPC_FD */
  {
    /* ddCanIdLl */
    0x8C000104U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x001B,

    /* ddTargetId */
    0x0001,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x01,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x1FFFFFFFU
  },

  /* RX-LIST-RANGE 28 - Ctrl_Lis2281701456_CanIfRxPduCfg_IN_WPC_LCAN_0x8000050_LCAN_L_BDC_FD_IAU_10_200ms */
  {
    /* ddCanIdLl */
    0x88000050U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x001C,

    /* ddTargetId */
    0x0017,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x1FFFFFFFU
  },

  /* RX-LIST-RANGE 29 - Ctrl_Lis2214592592_CanIfRxPduCfg_IN_WPC_LCAN_0x4000050_LCAN_L_BDC_FD_IAU_01_00ms */
  {
    /* ddCanIdLl */
    0x84000050U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x001D,

    /* ddTargetId */
    0x0016,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x1FFFFFFFU
  },

  /* RX-LIST-RANGE 30 - Ctrl_Lis1087_CanIfRxPduCfg_IN_WPC_LCAN_0x43f_LCAN_CCU_01_00ms */
  {
    /* ddCanIdLl */
    0x0000043FU,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x001E,

    /* ddTargetId */
    0x001A,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x08,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 31 - Ctrl_Lis850_CanIfRxPduCfg_IN_WPC_LCAN_0x352_LCAN_IAU_FD_05_200ms */
  {
    /* ddCanIdLl */
    0x00000352U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x001F,

    /* ddTargetId */
    0x0018,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 32 - Ctrl_Lis849_CanIfRxPduCfg_IN_WPC_LCAN_0x351_LCAN_IAU_FD_04_200ms */
  {
    /* ddCanIdLl */
    0x00000351U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0020,

    /* ddTargetId */
    0x0019,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 33 - Ctrl_Lis745_CanIfRxPduCfg_IN_WPC_LCAN_0x2e9_LCAN_PDC_FD_15_300ms */
  {
    /* ddCanIdLl */
    0x000002E9U,

    /* ddCanIdUl */
    0x00000000U,

    /* ddRxPduId */
    0x0022,

    /* ddTargetId */
    0x001C,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x00,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x000007FFU
  },

  /* RX-LIST-RANGE 34 - Cntrl_CanGeneralCntrl1Hrh34_Ran2549874688-2549874942_CanIfRxPduCfg_IN_WPC_LCAN_CANNM_MESSAGE */
  {
    /* ddCanIdLl */
    0x97FC0000U,

    /* ddCanIdUl */
    0x97FC00FEU,

    /* ddRxPduId */
    0x0021,

    /* ddTargetId */
    0x0001,

    /* ucCallbackIndex */
    0xFF,

    /* ucDlc */
    0x20,

    /* *ucRxUserOrNotifSts */
    0x02,

    /* ucControllerId */
    0x01,

    /* RxPduCanIdMask */
    0x1FFFFFFFU
  }
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* CONST(CanIf_RxLpduIdTable, CANIF_VAR) CanIf_GaaRxLpduIdTable[]; */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for Basic TxPdu Index Map array */
CONST(uint16, CANIF_CONST) CanIf_GaaTxBasicPduIndexMapping[] =
{
  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID,

  CANIF_INVALID
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* CONST(CanIf_TxBuffer, CANIF_CONST) CanIf_GaaTxBuffer[]; */
/* CONST(CanIf_TxCbkUser, CANIF_CONST)CanIf_GaaTxCbkUser[]; */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Structure for Transmit L-PDU */
CONST(CanIf_TxLpdu, CANIF_CONST)CanIf_GaaTxLpdu[] =
{
  /* TX LPDU 0 - CanIfTxPduCfg_OUT_WPC_BCAN_0x21f_BCAN_WPC_FD_VCRM_01_00ms */
  {
    /* ddCanId */
    0x4000021FU,

    /* ddHthIdorBufferId */
    0x23,

    /* ddTxConfirmPduId */
    0x0000,

    /* ddTxPduId */
    0x0000,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x03,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x10,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 1 - CanIfTxPduCfg_OUT_WPC_BCAN_0x391_BCAN_WPC_FD_01_200ms */
  {
    /* ddCanId */
    0x40000391U,

    /* ddHthIdorBufferId */
    0x24,

    /* ddTxConfirmPduId */
    0x0001,

    /* ddTxPduId */
    0x0001,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x03,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x10,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 2 - CanIfTxPduCfg_OUT_WPC_BCAN_0x17fc009e_BCAN_NM_WPC_FD */
  {
    /* ddCanId */
    0xD7FC009EU,

    /* ddHthIdorBufferId */
    0x28,

    /* ddTxConfirmPduId */
    0x0000,

    /* ddTxPduId */
    0x0002,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x02,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x04,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x20,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 3 - CanIfTxPduCfg_OUT_WPC_BCAN_0x392_BCAN_WPC2_FD_01_200ms */
  {
    /* ddCanId */
    0x40000392U,

    /* ddHthIdorBufferId */
    0x25,

    /* ddTxConfirmPduId */
    0x0006,

    /* ddTxPduId */
    0x0003,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x03,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x10,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 4 - CanIfTxPduCfg_OUT_WPC_BCAN_0x686_BCAN_WPCmsgDvp1 */
  {
    /* ddCanId */
    0x40000686U,

    /* ddHthIdorBufferId */
    0x26,

    /* ddTxConfirmPduId */
    0x0007,

    /* ddTxPduId */
    0x0004,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x03,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x40,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 5 - CanIfTxPduCfg_OUT_WPC_BCAN_0x72d_BCAN_WPC_GST */
  {
    /* ddCanId */
    0x4000072DU,

    /* ddHthIdorBufferId */
    0x27,

    /* ddTxConfirmPduId */
    0x0000,

    /* ddTxPduId */
    0x0005,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x01,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x03,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x08,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 6 - CanIfTxPduCfg_OUT_WPC_BCAN_0x1ec7b001_BCAN_WPC_WU_01_500ms */
  {
    /* ddCanId */
    0xDEC7B001U,

    /* ddHthIdorBufferId */
    0x29,

    /* ddTxConfirmPduId */
    0x0008,

    /* ddTxPduId */
    0x0006,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x04,

    /* ucControllerId */
    0x00,

    /* ucTxDlc */
    0x10,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 7 - CanIfTxPduCfg_OUT_WPC_LCAN_0x4000070_LCAN_L_WPC_FD_01_00ms */
  {
    /* ddCanId */
    0xC4000070U,

    /* ddHthIdorBufferId */
    0x2A,

    /* ddTxConfirmPduId */
    0x0002,

    /* ddTxPduId */
    0x0007,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x04,

    /* ucControllerId */
    0x01,

    /* ucTxDlc */
    0x08,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 8 - CanIfTxPduCfg_OUT_WPC_LCAN_0x8000070_LCAN_L_WPC_FD_20_200ms */
  {
    /* ddCanId */
    0xC8000070U,

    /* ddHthIdorBufferId */
    0x2B,

    /* ddTxConfirmPduId */
    0x0003,

    /* ddTxPduId */
    0x0008,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x00,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x04,

    /* ucControllerId */
    0x01,

    /* ucTxDlc */
    0x08,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 9 - CanIfTxPduCfg_OUT_WPC_LCAN_0xc000105_LCAN_L_TP_L_WPC_FD_BDC_FD */
  {
    /* ddCanId */
    0xCC000105U,

    /* ddHthIdorBufferId */
    0x2C,

    /* ddTxConfirmPduId */
    0x0001,

    /* ddTxPduId */
    0x0009,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x01,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x04,

    /* ucControllerId */
    0x01,

    /* ucTxDlc */
    0x20,

    /* blTxPduTruncation */
    0x00
  },

  /* TX LPDU 10 - CanIfTxPduCfg_OUT_WPC_LCAN_0x17fc001e_LCAN_NM_L_WPC_FD */
  {
    /* ddCanId */
    0xD7FC001EU,

    /* ddHthIdorBufferId */
    0x2D,

    /* ddTxConfirmPduId */
    0x0001,

    /* ddTxPduId */
    0x000A,

    /* ucCallbackIndex */
    0xFF,

    /* ucTxCbkUser */
    0x02,

    /* ucHTHTypeOrTXPN */
    0x01,

    /* ucCanIdType */
    0x04,

    /* ucControllerId */
    0x01,

    /* ucTxDlc */
    0x20,

    /* blTxPduTruncation */
    0x00
  }
};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* VAR(CanIf_TxPduIdType, CANIF_VAR) CanIf_GaaTxPduToQueueMapping[CANIF_NO_OF_BASIC_TXLPDU];*/
/* CONST(CanIf_WakeupSource, CANIF_CONST)CanIf_GaaWakeupSource[]; */
/* VAR(Can_IdType, CANIF_VAR_NOINIT) CanIf_GddCanId[]; */

/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations>> The number of macros doesn't matter. */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
