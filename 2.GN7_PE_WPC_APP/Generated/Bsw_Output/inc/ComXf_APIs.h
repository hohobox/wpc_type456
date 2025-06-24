/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  Generate On : The time-stamp is removed
**                                                                            **
**  SRC-MODULE:           ComXf_APIs.h                                        **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain extern declaration generic public **
**                        API's.                                              **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

#ifndef COMXF_APIS_H
#define COMXF_APIS_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
		
/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC_FD_01_200ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_LCAN_L_WPC_FD_01_00ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_LCAN_L_WPC_FD_20_200ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_BCAN_PDC_FD_15_300ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC2_FD_01_200ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Com_ComISignalGroup_MsgGr_E2E_BCAN_WPC_WU_01_500ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_BCAN_WPC_WU_01_500ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_APPL_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_APPL_CODE) ComXf_FillUnusedBufferArea(
  P2VAR(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer,
  uint32 Lu32_ComXfBufferLength ,uint8 Lu8_ComXfUnusedAreaValue);
#define COMXF_STOP_APPL_SEC_CODE
#include "ComXf_MemMap.h"

#endif /* COMXF_APIS_H */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
