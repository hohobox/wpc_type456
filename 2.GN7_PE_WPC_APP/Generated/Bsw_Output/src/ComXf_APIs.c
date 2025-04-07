/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  Generate On : The time-stamp is removed
**                                                                            **
**  SRC-MODULE:           ComXf_APIs.c                                        **
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
#include "Det.h"
#include "ComXf_Types.h"
#include "ComXf_Cfg.h"
#include "ComXf_GlobalDataDefinition.h"
#include "ComXf_Macros.h"
#include "ComXf_Packing.h"
#include "ComXf_UnPacking.h"
#include "ComXf_ErrorCheck.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/

/* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Not a defect, Decrement and Increment operator is used to achieve better throughput */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] Pointer is not a NULL and valid */
/* polyspace:begin <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
/*=============================================================================*
** Service Name         : ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms                               **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function transforms a Sender/Receiver          **
**                        Transformer communication using the serialization   **
**                        of COM Based It takes the data element as input and **
**                        outputs an uint8 array containing the serialized    **
**                        data called transformer module                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : dataElement                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : buffer, bufferLength                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC_FD_01_200ms, AUTOMATIC, COMXF_CONST)
  dataElement)
{
  uint8 Lu8_ReturnStatus;
  
  /* Pointer to signal for fetching signal properties */
  P2CONST(ComXf_PackSigType, AUTOMATIC, COM_CONST) Lpst_PackSigType;
  Lpst_PackSigType = NULL_PTR;
  Lu8_ReturnStatus = E_OK;
  
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  
  COMXF_MODULE_INIT_CHECK(COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, buffer,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, bufferLength,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, dataElement,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  if(E_OK == Lu8_ReturnStatus)
  #endif
  {
    ComXf_FillUnusedBufferArea(&buffer[0], 13, 0x0);
   
    Lpst_PackSigType = &ComXf_Kast_SigPackInfo[ComXf_BCAN_WPC_FD_01_200ms_USM_CmdWPCSta];
    
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->USM_CmdWPCSta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->WPC_PhnLftWrngSta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[6], Lpst_PackSigType, dataElement->WPC_DualWPCOptSta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[7], Lpst_PackSigType, dataElement->WPC_SWVerMajor1);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[8], Lpst_PackSigType, dataElement->WPC_SWVerMinor1);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[9], Lpst_PackSigType, dataElement->WPC_SWVerMinor2);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[10], Lpst_PackSigType, dataElement->WPC_IndSyncVal);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[10], Lpst_PackSigType, dataElement->USM_CmdWPCIndSta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[10], Lpst_PackSigType, dataElement->WPC_ResetOpSta);
    
    buffer[12] = dataElement->WPC_FD_01_200ms_E2EReserved;
    
    *bufferLength = 13;
  }
  
  
  return Lu8_ReturnStatus;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
/*=============================================================================*
** Service Name         : ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms                               **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function transforms a Sender/Receiver          **
**                        Transformer communication using the serialization   **
**                        of COM Based It takes the data element as input and **
**                        outputs an uint8 array containing the serialized    **
**                        data called transformer module                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : dataElement                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : buffer, bufferLength                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms, AUTOMATIC, COMXF_CONST)
  dataElement)
{
  uint8 Lu8_ReturnStatus;
  
  /* Pointer to signal for fetching signal properties */
  P2CONST(ComXf_PackSigType, AUTOMATIC, COM_CONST) Lpst_PackSigType;
  Lpst_PackSigType = NULL_PTR;
  Lu8_ReturnStatus = E_OK;
  
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  
  COMXF_MODULE_INIT_CHECK(COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, buffer,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, bufferLength,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, dataElement,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  if(E_OK == Lu8_ReturnStatus)
  #endif
  {
    ComXf_FillUnusedBufferArea(&buffer[0], 13, 0x0);
   
    Lpst_PackSigType = &ComXf_Kast_SigPackInfo[ComXf_BCAN_WPC_FD_VCRM_01_00ms_WPC_PhnUsingTime];
    
    
    buffer[0] = dataElement->WPC_PhnUsingTime;
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[1], Lpst_PackSigType, dataElement->WPC_PhnChargingCompleteCnt);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[1], Lpst_PackSigType, dataElement->WPC_EPPChargingCnt);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[2], Lpst_PackSigType, dataElement->WPC_MPPChargingCnt);
    
    Lpst_PackSigType++;
    
    ComXf_PackBoolean(&buffer[2], Lpst_PackSigType, dataElement->WPC_DigitalKeyAuth);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[2], Lpst_PackSigType, dataElement->WPC_DigitalKeyDevice);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[3], Lpst_PackSigType, dataElement->WPC_PhnChargingErrCnt);
    
    Lpst_PackSigType++;
    
    ComXf_Pack2ByteNotAlign(&buffer[3], Lpst_PackSigType, dataElement->WPC_ThermalSnsrMaxTemp, 1);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[4], Lpst_PackSigType, dataElement->WPC_CANBusOffDTC);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->WPC_LocalCANBusOffDTC);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->WPC_TempSnsrFltDTC);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->WPC_FANFltDTC);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->WPC_InternalECUErrDTC);
    
    buffer[12] = dataElement->WPC_FD_VCRM_01_00ms_E2EReserved;
    
    *bufferLength = 13;
  }
  
  
  return Lu8_ReturnStatus;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
/*=============================================================================*
** Service Name         : ComXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms                               **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function transforms a Sender/Receiver          **
**                        Transformer communication using the serialization   **
**                        of COM Based It takes the data element as input and **
**                        outputs an uint8 array containing the serialized    **
**                        data called transformer module                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : dataElement                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : buffer, bufferLength                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_LCAN_L_WPC_FD_01_00ms, AUTOMATIC, COMXF_CONST)
  dataElement)
{
  uint8 Lu8_ReturnStatus;
  
  /* Pointer to signal for fetching signal properties */
  P2CONST(ComXf_PackSigType, AUTOMATIC, COM_CONST) Lpst_PackSigType;
  Lpst_PackSigType = NULL_PTR;
  Lu8_ReturnStatus = E_OK;
  
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  
  COMXF_MODULE_INIT_CHECK(COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, buffer,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, bufferLength,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, dataElement,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  if(E_OK == Lu8_ReturnStatus)
  #endif
  {
    ComXf_FillUnusedBufferArea(&buffer[0], 5, 0x0);
   
    Lpst_PackSigType = &ComXf_Kast_SigPackInfo[ComXf_LCAN_L_WPC_FD_01_00ms_WPC_NFCDetection_Sta];
    
    
    ComXf_Pack1ByteNotAlign(&buffer[0], Lpst_PackSigType, dataElement->WPC_NFCDetection_Sta);
    
    Lpst_PackSigType++;
    
    ComXf_PackBoolean(&buffer[0], Lpst_PackSigType, dataElement->WPC_NFCReset_Sta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[0], Lpst_PackSigType, dataElement->WPC2_NFCDetection_Sta);
    
    Lpst_PackSigType++;
    
    ComXf_PackBoolean(&buffer[0], Lpst_PackSigType, dataElement->WPC2_NFCReset_Sta);
    
    buffer[4] = dataElement->L_WPC_FD_01_00ms_E2EReserved;
    
    *bufferLength = 5;
  }
  
  
  return Lu8_ReturnStatus;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
/*=============================================================================*
** Service Name         : ComXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms                               **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function transforms a Sender/Receiver          **
**                        Transformer communication using the serialization   **
**                        of COM Based It takes the data element as input and **
**                        outputs an uint8 array containing the serialized    **
**                        data called transformer module                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : dataElement                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : buffer, bufferLength                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_LCAN_L_WPC_FD_20_200ms, AUTOMATIC, COMXF_CONST)
  dataElement)
{
  uint8 Lu8_ReturnStatus;
  
  /* Pointer to signal for fetching signal properties */
  P2CONST(ComXf_PackSigType, AUTOMATIC, COM_CONST) Lpst_PackSigType;
  Lpst_PackSigType = NULL_PTR;
  Lu8_ReturnStatus = E_OK;
  
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  
  COMXF_MODULE_INIT_CHECK(COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, buffer,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, bufferLength,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, dataElement,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  if(E_OK == Lu8_ReturnStatus)
  #endif
  {
    ComXf_FillUnusedBufferArea(&buffer[0], 5, 0x0);
   
    Lpst_PackSigType = &ComXf_Kast_SigPackInfo[ComXf_LCAN_L_WPC_FD_20_200ms_WPC_Status];
    
    
    ComXf_Pack1ByteNotAlign(&buffer[0], Lpst_PackSigType, dataElement->WPC_Status);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[0], Lpst_PackSigType, dataElement->WPC2_Status);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[1], Lpst_PackSigType, dataElement->WPC_NFC_Opt);
    
    buffer[4] = dataElement->L_WPC_FD_20_200ms_E2EReserved;
    
    *bufferLength = 5;
  }
  
  
  return Lu8_ReturnStatus;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
/*=============================================================================*
** Service Name         : ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms                               **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function transforms a Sender/Receiver          **
**                        Transformer communication using the serialization   **
**                        of COM Based It takes the data element as input and **
**                        outputs an uint8 array containing the serialized    **
**                        data called transformer module                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : dataElement                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : buffer, bufferLength                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC2_FD_01_200ms, AUTOMATIC, COMXF_CONST)
  dataElement)
{
  uint8 Lu8_ReturnStatus;
  
  /* Pointer to signal for fetching signal properties */
  P2CONST(ComXf_PackSigType, AUTOMATIC, COM_CONST) Lpst_PackSigType;
  Lpst_PackSigType = NULL_PTR;
  Lu8_ReturnStatus = E_OK;
  
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  
  COMXF_MODULE_INIT_CHECK(COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, buffer,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, bufferLength,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, dataElement,
    COMXF_TRANSFORMER_SERVICE_ID);
  
  if(E_OK == Lu8_ReturnStatus)
  #endif
  {
    ComXf_FillUnusedBufferArea(&buffer[0], 13, 0x0);
   
    Lpst_PackSigType = &ComXf_Kast_SigPackInfo[ComXf_BCAN_WPC2_FD_01_200ms_USM_CmdWPC2Sta];
    
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->USM_CmdWPC2Sta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[5], Lpst_PackSigType, dataElement->WPC2_PhnLftWrngSta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[6], Lpst_PackSigType, dataElement->WPC2_OptSta);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[7], Lpst_PackSigType, dataElement->WPC2_SWVerMajor1);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[8], Lpst_PackSigType, dataElement->WPC2_SWVerMinor1);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[9], Lpst_PackSigType, dataElement->WPC2_SWVerMinor2);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[10], Lpst_PackSigType, dataElement->WPC2_IndSyncVal);
    
    Lpst_PackSigType++;
    
    ComXf_Pack1ByteNotAlign(&buffer[10], Lpst_PackSigType, dataElement->WPC2_ResetOpSta);
    
    buffer[12] = dataElement->WPC2_FD_01_200ms_E2EReserved;
    
    *bufferLength = 13;
  }
  
  
  return Lu8_ReturnStatus;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms                         **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : This function deserializes a Sender/Receiver        **
**                        communication using the deserialization of COM      **
**                        Based Transformer. It takes the uint8 array as      **
**                        containing the serialized data as input and outputs **
**                        the original data element which will be passed to   **
**                        the Rte.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : buffer, bufferLength                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataElement                                         **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_BCAN_PDC_FD_15_300ms, AUTOMATIC, COMXF_VAR)
  dataElement)
{
  uint8 Lu8_ReturnStatus;
  
  /* Pointer to signal for fetching signal properties */
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType;
  
  Lpst_UnPackSigType = NULL_PTR;
  Lu8_ReturnStatus = E_OK;
  
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
   
  COMXF_MODULE_INIT_CHECK(COMXF_INVTRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_PTR_AND_BUFFERLENGTH_CHECK(Lu8_ReturnStatus, buffer, bufferLength, COMXF_INVTRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, buffer,
    COMXF_INVTRANSFORMER_SERVICE_ID);
  
  COMXF_BUFFERLENGTH_CHECK(Lu8_ReturnStatus, bufferLength,
    COMXF_INVTRANSFORMER_SERVICE_ID);
  
  COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, dataElement,
    COMXF_INVTRANSFORMER_SERVICE_ID);
  
  if(E_OK == Lu8_ReturnStatus)
  #endif
  {
    Lpst_UnPackSigType = &ComXf_Kast_SigUnPackInfo[ComXf_BCAN_PDC_FD_15_300ms_PDC_ResetPreWrngForOthers];
    dataElement->PDC_ResetPreWrngForOthers = ComXf_UnPack1ByteNotAlign(&buffer[2], Lpst_UnPackSigType);
          
    Lpst_UnPackSigType++;
    
    dataElement->PDC_ResetReqForOthers = ComXf_UnPack1ByteNotAlign(&buffer[2], Lpst_UnPackSigType);
          
    dataElement->PDC_FD_15_300ms_E2EReserved = buffer[28];
          
  }
  
  
  return Lu8_ReturnStatus;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Not a defect, Decrement and Increment operator is used to achieve better throughput */
/* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] Pointer is not a NULL and valid */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
