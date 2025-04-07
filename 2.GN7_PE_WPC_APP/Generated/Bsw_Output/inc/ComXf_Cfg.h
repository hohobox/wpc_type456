/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  Generate On : The time-stamp is removed
**                                                                            **
**  SRC-MODULE:           ComXf_Cfg.h                                         **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain internal macros, externs etc.     **
**                        API's.                                              **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

#ifndef COMXF_CFG_H
#define COMXF_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
 
#include "TransformerTypes.h" 
 
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COMXF_MODULE_ID                                        (175)
#define COMXF_VENDOR_ID                                        (76)
#define COMXF_CFG_C_AR_RELEASE_MAJOR_VERSION                   (4)
#define COMXF_CFG_C_AR_RELEASE_MINOR_VERSION                   (3)
#define COMXF_CFG_C_AR_RELEASE_REVISION_VERSION                (0)
#define COMXF_CFG_C_SW_MAJOR_VERSION                           (1)
#define COMXF_CFG_C_SW_MINOR_VERSION                           (0)
#define COMXF_CFG_C_SW_PATCH_VERSION                           (1)

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
/******************************************************************************/
/* Description : Development Error Detection Switch                           */
/*                                                                            */
/* Range       : STD_ON, STD_OFF                                              */
/******************************************************************************/
#define COMXF_DEV_ERROR_DETECT                                 STD_ON

/******************************************************************************/
/* Description : Version Information Switch                                   */
/*                                                                            */
/* Range       : STD_ON, STD_OFF                                              */
/******************************************************************************/
#define COMXF_VERSION_INFORMATION                              STD_OFF

/******************************************************************************/
/* Description : ComXf Pre-Compile Switch                                     */
/*                                                                            */
/* Range       : STD_ON, STD_OFF                                              */
/******************************************************************************/
#define COMXF_PRECOMPILE_CONFIG                                STD_ON

/******************************************************************************/
/* Description : ComXf Pack Info                                              */
/*                                                                            */
/* Range       :                                                              */
/******************************************************************************/
#define COMXF_PRECOMPILE_PACK_INFO_COUNT                       42

/******************************************************************************/
/* Description : ComXf UnPack Info                                            */
/*                                                                            */
/* Range       :                                                              */
/******************************************************************************/
#define COMXF_PRECOMPILE_UNPACK_INFO_COUNT                     3

/******************************************************************************/
/* Description : ComXf 64-bit functions support                               */
/*                                                                            */
/* Range       : STD_ON, STD_OFF                                              */
/******************************************************************************/
#define COMXF_64BIT_DATATYPE_SUPPORT                           STD_OFF

/*******************************************************************************
**                       Tx Group Signals Handle Ids                          **
*******************************************************************************/
#define ComXf_BCAN_WPC_FD_01_200ms_USM_CmdWPCSta     0
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_PhnLftWrngSta 1
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_DualWPCOptSta 2
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_SWVerMajor1   3
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_SWVerMinor1   4
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_SWVerMinor2   5
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_IndSyncVal    6
#define ComXf_BCAN_WPC_FD_01_200ms_USM_CmdWPCIndSta  7
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_ResetOpSta    8
#define ComXf_BCAN_WPC_FD_01_200ms_WPC_FD_01_200ms_E2EReserved 9
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnUsingTime 10
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnChargingCompleteCnt 11
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_EPPChargingCnt 12
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_MPPChargingCnt 13
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_DigitalKeyAuth 14
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_DigitalKeyDevice 15
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnChargingErrCnt 16
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_ThermalSnsrMaxTemp 17
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_CANBusOffDTC 18
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_LocalCANBusOffDTC 19
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_TempSnsrFltDTC 20
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_FANFltDTC 21
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_InternalECUErrDTC 22
#define ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_FD_VCRM_01_00ms_E2EReserved 23
#define ComXf_LCAN_L_WPC_FD_01_00ms_WPC_NFCDetection_Sta 24
#define ComXf_LCAN_L_WPC_FD_01_00ms_WPC_NFCReset_Sta 25
#define ComXf_LCAN_L_WPC_FD_01_00ms_WPC2_NFCDetection_Sta 26
#define ComXf_LCAN_L_WPC_FD_01_00ms_WPC2_NFCReset_Sta 27
#define ComXf_LCAN_L_WPC_FD_01_00ms_L_WPC_FD_01_00ms_E2EReserved 28
#define ComXf_LCAN_L_WPC_FD_20_200ms_WPC_Status      29
#define ComXf_LCAN_L_WPC_FD_20_200ms_WPC2_Status     30
#define ComXf_LCAN_L_WPC_FD_20_200ms_WPC_NFC_Opt     31
#define ComXf_LCAN_L_WPC_FD_20_200ms_L_WPC_FD_20_200ms_E2EReserved 32
#define ComXf_BCAN_WPC2_FD_01_200ms_USM_CmdWPC2Sta   33
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_PhnLftWrngSta 34
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_OptSta      35
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_SWVerMajor1 36
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_SWVerMinor1 37
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_SWVerMinor2 38
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_IndSyncVal  39
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_ResetOpSta  40
#define ComXf_BCAN_WPC2_FD_01_200ms_WPC2_FD_01_200ms_E2EReserved 41

/*******************************************************************************
**                       Rx Group Signals Handle Ids                          **
*******************************************************************************/
#define ComXf_BCAN_PDC_FD_15_300ms_PDC_ResetPreWrngForOthers 0
#define ComXf_BCAN_PDC_FD_15_300ms_PDC_ResetReqForOthers 1
#define ComXf_BCAN_PDC_FD_15_300ms_PDC_FD_15_300ms_E2EReserved 2

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/

#endif /* COMXF_CFG_H */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
