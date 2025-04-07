/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  Generate On : The time-stamp is removed
**                                                                            **
**  SRC-MODULE:           ComXf_Cfg.c                                         **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain function body for generic public  **
**                        API's.                                              **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComXf.h"
#include "ComXf_Types.h"
#include "ComXf_Cfg.h"
#include "ComXf_GlobalDataDefinition.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/

#define COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"
CONST(ComXf_PackSigType, COMXF_CONST) ComXf_Kast_SigPackInfo[42] =
{
  /* ComXf_BCAN_WPC_FD_01_200ms_USM_CmdWPCSta */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfcU,
    
    /* u8_SetOREndMsk */
    0xfcU

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_PhnLftWrngSta */
  {
    /* en_ShiftBits */
    COMXF_TWO_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xe3U,
    
    /* u8_SetOREndMsk */
    0xe3U

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_DualWPCOptSta */
  {
    /* en_ShiftBits */
    COMXF_FOUR_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xcfU,
    
    /* u8_SetOREndMsk */
    0xcfU

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_SWVerMajor1 */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x80U,
    
    /* u8_SetOREndMsk */
    0x80U

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_SWVerMinor1 */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x80U,
    
    /* u8_SetOREndMsk */
    0x80U

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_SWVerMinor2 */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x80U,
    
    /* u8_SetOREndMsk */
    0x80U

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_IndSyncVal */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xf8U,
    
    /* u8_SetOREndMsk */
    0xf8U

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_USM_CmdWPCIndSta */
  {
    /* en_ShiftBits */
    COMXF_THREE_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xc7U,
    
    /* u8_SetOREndMsk */
    0xc7U

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_ResetOpSta */
  {
    /* en_ShiftBits */
    COMXF_SIX_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x3fU,
    
    /* u8_SetOREndMsk */
    0x3fU

  },
  /* ComXf_BCAN_WPC_FD_01_200ms_WPC_FD_01_200ms_E2EReserved */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x0U,
    
    /* u8_SetOREndMsk */
    0x0U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnUsingTime */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x0U,
    
    /* u8_SetOREndMsk */
    0x0U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnChargingCompleteCnt */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xf0U,
    
    /* u8_SetOREndMsk */
    0xf0U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_EPPChargingCnt */
  {
    /* en_ShiftBits */
    COMXF_FOUR_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfU,
    
    /* u8_SetOREndMsk */
    0xfU

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_MPPChargingCnt */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xf0U,
    
    /* u8_SetOREndMsk */
    0xf0U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_DigitalKeyAuth */
  {
    /* en_ShiftBits */
    COMXF_FOUR_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xefU,
    
    /* u8_SetOREndMsk */
    0x10U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_DigitalKeyDevice */
  {
    /* en_ShiftBits */
    COMXF_FIVE_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x1fU,
    
    /* u8_SetOREndMsk */
    0x1fU

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnChargingErrCnt */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xc0U,
    
    /* u8_SetOREndMsk */
    0xc0U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_ThermalSnsrMaxTemp */
  {
    /* en_ShiftBits */
    COMXF_SIX_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_TWO_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x3fU,
    
    /* u8_SetOREndMsk */
    0xc0U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_CANBusOffDTC */
  {
    /* en_ShiftBits */
    COMXF_SIX_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x3fU,
    
    /* u8_SetOREndMsk */
    0x3fU

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_LocalCANBusOffDTC */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfcU,
    
    /* u8_SetOREndMsk */
    0xfcU

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_TempSnsrFltDTC */
  {
    /* en_ShiftBits */
    COMXF_TWO_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xf3U,
    
    /* u8_SetOREndMsk */
    0xf3U

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_FANFltDTC */
  {
    /* en_ShiftBits */
    COMXF_FOUR_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xcfU,
    
    /* u8_SetOREndMsk */
    0xcfU

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_InternalECUErrDTC */
  {
    /* en_ShiftBits */
    COMXF_SIX_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x3fU,
    
    /* u8_SetOREndMsk */
    0x3fU

  },
  /* ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_FD_VCRM_01_00ms_E2EReserved */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x0U,
    
    /* u8_SetOREndMsk */
    0x0U

  },
  /* ComXf_LCAN_L_WPC_FD_01_00ms_WPC_NFCDetection_Sta */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfcU,
    
    /* u8_SetOREndMsk */
    0xfcU

  },
  /* ComXf_LCAN_L_WPC_FD_01_00ms_WPC_NFCReset_Sta */
  {
    /* en_ShiftBits */
    COMXF_TWO_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfbU,
    
    /* u8_SetOREndMsk */
    0x4U

  },
  /* ComXf_LCAN_L_WPC_FD_01_00ms_WPC2_NFCDetection_Sta */
  {
    /* en_ShiftBits */
    COMXF_THREE_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xe7U,
    
    /* u8_SetOREndMsk */
    0xe7U

  },
  /* ComXf_LCAN_L_WPC_FD_01_00ms_WPC2_NFCReset_Sta */
  {
    /* en_ShiftBits */
    COMXF_FIVE_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xdfU,
    
    /* u8_SetOREndMsk */
    0x20U

  },
  /* ComXf_LCAN_L_WPC_FD_01_00ms_L_WPC_FD_01_00ms_E2EReserved */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x0U,
    
    /* u8_SetOREndMsk */
    0x0U

  },
  /* ComXf_LCAN_L_WPC_FD_20_200ms_WPC_Status */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xf8U,
    
    /* u8_SetOREndMsk */
    0xf8U

  },
  /* ComXf_LCAN_L_WPC_FD_20_200ms_WPC2_Status */
  {
    /* en_ShiftBits */
    COMXF_THREE_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xc7U,
    
    /* u8_SetOREndMsk */
    0xc7U

  },
  /* ComXf_LCAN_L_WPC_FD_20_200ms_WPC_NFC_Opt */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfcU,
    
    /* u8_SetOREndMsk */
    0xfcU

  },
  /* ComXf_LCAN_L_WPC_FD_20_200ms_L_WPC_FD_20_200ms_E2EReserved */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x0U,
    
    /* u8_SetOREndMsk */
    0x0U

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_USM_CmdWPC2Sta */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xfcU,
    
    /* u8_SetOREndMsk */
    0xfcU

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_PhnLftWrngSta */
  {
    /* en_ShiftBits */
    COMXF_TWO_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xe3U,
    
    /* u8_SetOREndMsk */
    0xe3U

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_OptSta */
  {
    /* en_ShiftBits */
    COMXF_FOUR_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xcfU,
    
    /* u8_SetOREndMsk */
    0xcfU

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_SWVerMajor1 */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x80U,
    
    /* u8_SetOREndMsk */
    0x80U

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_SWVerMinor1 */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x80U,
    
    /* u8_SetOREndMsk */
    0x80U

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_SWVerMinor2 */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x80U,
    
    /* u8_SetOREndMsk */
    0x80U

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_IndSyncVal */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0xf8U,
    
    /* u8_SetOREndMsk */
    0xf8U

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_ResetOpSta */
  {
    /* en_ShiftBits */
    COMXF_SIX_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x3fU,
    
    /* u8_SetOREndMsk */
    0x3fU

  },
  /* ComXf_BCAN_WPC2_FD_01_200ms_WPC2_FD_01_200ms_E2EReserved */
  {
    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_StartORClearBitMask */
    0x0U,
    
    /* u8_SetOREndMsk */
    0x0U

  }
};
#define COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"


#define COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"
CONST(ComXf_UnPackSigType, COMXF_CONST) ComXf_Kast_SigUnPackInfo[3] =
{
  /* ComXf_BCAN_PDC_FD_15_300ms_PDC_ResetPreWrngForOthers */
  {
    /* u64_SigSignMsk */
    0x00U,
      
    /* u32_SigSignMsk */
    0x00U,

    /* en_ShiftBits */
    COMXF_TWO_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_RxEndMsk */
    0xcU
      
  },
  /* ComXf_BCAN_PDC_FD_15_300ms_PDC_ResetReqForOthers */
  {
    /* u64_SigSignMsk */
    0x00U,
      
    /* u32_SigSignMsk */
    0x00U,

    /* en_ShiftBits */
    COMXF_SIX_BIT_SHIFT,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_RxEndMsk */
    0xc0U
      
  },
  /* ComXf_BCAN_PDC_FD_15_300ms_PDC_FD_15_300ms_E2EReserved */
  {
    /* u64_SigSignMsk */
    0x00U,
      
    /* u32_SigSignMsk */
    0x00U,

    /* en_ShiftBits */
    COMXF_BIT_ALIGNED,

    /* en_NoOfBytes */
    COMXF_ONE_BYTE_SIZE,

    /* u8_RxEndMsk */
    0xffU
      
  }
};
#define COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"

/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
