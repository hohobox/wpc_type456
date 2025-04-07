/*******************************************************************************
NOTE : This file is a template code to use CDD_ROUTER. 
Please, make a CDD_Router.c in other folder for integration code and refer this file.
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Co., Ltd.                                       **
**                                                                            **
**  SRC-MODULE: CDD_Router.c                                                  **
**                                                                            **
**  PRODUCT   : CDD_Router Module                                             **
**                                                                            **
**  NOTE      : The provided static and generated codes of CDD_Router Module  **
**              are just for the understanding of the relationship between    **
**              communication Modules. The user must make sure that there are **
**              no problems with the operation through the full verification. **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.3.4     25-Aug-2023   MJ Kim      Detailed description of sample code    **
** 2.3.3     09-Jun-2023   MJ Kim      Sample Code updated                    **
** 2.3.0     25-Jan-2022   SM Kwon     Sample Code updated for CanTp          **
** 2.2.1     24-Mar-2021   SM Kwon     Sample Code updated                    **
** 2.2.0     24-Mar-2021   HM Shin     Sample Code updated                    **
** 2.1.0     02-Mar-2021   HM Shin     Sample Code updated                    **
** 2.0.1     09-Jul-2019   Jongsun Lim Sample Code Update 4.1.1 API Updated   **
** 2.0.0     08-Aug-2018   Chan Kim    Sample Code updated                    **
** 1.5.0     23-Aug-2016   Chan Kim    Sample Code updated                    **
** 1.0.0     16-Mar-2015   Autoever      Initial Version                      **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define CDD_ROUTER_C_AR_RELEASE_MAJOR_VERSION     4
#define CDD_ROUTER_C_AR_RELEASE_MINOR_VERSION     0
#define CDD_ROUTER_C_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define CDD_ROUTER_C_SW_MAJOR_VERSION  2
#define CDD_ROUTER_C_SW_MINOR_VERSION  3

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "CDD_Router.h"
#if ((CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_LOWER_IF_RX_PDU_COUNT > 0))
#include "CanIf.h"
#endif
#if ((CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_LOWER_SOAD_IF_RX_PDU_COUNT > 0))
#include "SoAd.h"
#endif
#if ((CDD_ROUTER_MAX_UPPER_CANTP_IF_TX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_UPPER_CANTP_IF_RX_PDU_COUNT > 0))
#include "CanTp_Cbk.h"
#endif
#if 0 /* disable sample code */
#include "Rte_CDD_Router_SwComponentType.h"
#endif
/* Pre-compile option for 4.1.1 support */
#define CDD_Router_FOUR_ONE_ONE                   0
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*This function is provided as a sample.
Purpose: Forward Tx Confirmation from Canif to Upper Layer Module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0)
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CDD_ROUTER_CODE) CDD_RouterIF_TxConfirmation(PduIdType CddTxPduId)
{
  #if 0 /* disable sample code */
  if(CddTxPduId < (PduIdType)CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT)  
  {
    if(CddTxPduId == CDD_Router_LowerIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      /* Confirmation process for PduR Module */
      PduR_CDD_RouterIFTxConfirmation((PduIdType)CDD_Router_GaaUpperIfTxPduInfo
      [CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddTxPduHandleId);
    }
    else if(CddTxPduId == CDD_Router_LowerIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      /* Confirmation process for PduR Module */
      PduR_CDD_RouterIFTxConfirmation((PduIdType)CDD_Router_GaaUpperIfTxPduInfo
      [CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddTxPduHandleId);
    }
    else if(CddTxPduId == CDD_Router_LowerIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      /* Confirmation process for CanTp Module */
      CanTp_TxConfirmation((PduIdType)CDD_Router_GaaUpperCanTpIfTxPduInfo
      [CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddTxPduHandleId);
    }
    else
    {
      /* Discard */
    }
  }
  else
  {
    /* Error handling */
  }
  #endif
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif  //CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0

/*This function is provided as a sample.
Purpose: Forward Tx Confirmation from SoAd to Upper Layer Module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT > 0)
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CDD_ROUTER_CODE) CDD_RouterIF_SoAdIfTxConfirmation(PduIdType CddTxPduId)
{
  #if 0 /* disable sample code */
  if(CddTxPduId < (PduIdType)CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT)  
  {
    if(CddTxPduId == CDD_Router_LowerSoAdIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      /* Confirmation process for PduR Module */
      PduR_CDD_RouterIFTxConfirmation((PduIdType)CDD_Router_GaaUpperIfTxPduInfo
      [CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddTxPduHandleId);
    }
    else if(CddTxPduId == CDD_Router_LowerSoAdIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      /* Confirmation process for PduR Module */
      PduR_CDD_RouterIFTxConfirmation((PduIdType)CDD_Router_GaaUpperIfTxPduInfo
      [CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddTxPduHandleId);
    }
    else
    {
      /* Discard */
    }
  }
  else
  {
    /* Error handling */
  }
  #endif
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif  //(CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT >0)

/*This function is provided as a sample.
Purpose: Forward Transmit from PduR to lower layer module
It can be deleted at the user's judgment*/
#if ((CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT > 0))
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_RouterIF_Transmit(PduIdType CddTxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  Std_ReturnType Ldd_ReturnValue = E_NOT_OK;
  #if 0 /* disable sample code */  
  if(CddTxPduId < CDD_ROUTER_MAX_UPPER_IF_TX_PDU_COUNT)
  {
    if(CddTxPduId == CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      Ldd_ReturnValue = CanIf_Transmit((PduIdType)CDD_Router_GaaLowerIfTxPduInfo
        [CDD_Router_LowerIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
        .ddTxPduHandleId, PduInfoPtr);
    }
    else if(CddTxPduId == CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      Ldd_ReturnValue = SoAdIf_Transmit((PduIdType)CDD_Router_GaaLowerSoAdIfTxPduInfo
        [CDD_Router_LowerSoAdIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
        .ddTxPduHandleId, PduInfoPtr);
    }
    else
    {
      /* Discard */
    }
  }
  else
  {
    /* Error handling */
  }
  #endif

  #if 0 
  /* If you configure 'CddIfUpperLayerPduRef', then you can use below sample code 
   * /AUTRON/Cdd/CddComStackContribution/CddPduRLowerLayerContribution/CddPduRLowerLayerTxPdu/CddIfUpperLayerPduRef 
   */
  if(CddTxPduId < CDD_ROUTER_MAX_UPPER_IF_TX_PDU_COUNT)
  {
    if (CDD_Router_GaaUpperIfTxPduInfo[CddTxPduId].ddLayerType == CddComIfUpperLayer)
    {
      #if (CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0)
      Ldd_ReturnValue = CanIf_Transmit((PduIdType)(CDD_Router_GaaLowerIfTxPduInfo[
      CDD_Router_GaaUpperIfTxPduInfo[CddTxPduId].ddLoTargetPduHandleId].ddTxPduHandleId), PduInfoPtr);
      #endif
    }
    else 
    {
      #if (CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT > 0)
      Ldd_ReturnValue = SoAd_IfTransmit((PduIdType)(CDD_Router_GaaLowerIfTxPduInfo[
      CDD_Router_GaaUpperIfTxPduInfo[CddTxPduId].ddLoTargetPduHandleId].ddTxPduHandleId), PduInfoPtr);
      #endif
    }
  }
  #endif 
  return Ldd_ReturnValue;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*This function is provided as a sample.
Purpose: Forward Transmit from CanTp to lower layer module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_UPPER_CANTP_IF_TX_PDU_COUNT > 0)
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_RouterIF_CanTpTransmit(PduIdType CddTxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  Std_ReturnType Ldd_ReturnValue = E_NOT_OK;
  #if 0 /* disable sample code */  
  if(CddTxPduId < CDD_ROUTER_MAX_UPPER_IF_TX_PDU_COUNT)
  {
    if(CddTxPduId == CDD_Router_UpperIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
    {
      Ldd_ReturnValue = CanIf_Transmit((PduIdType)CDD_Router_GaaLowerIfTxPduInfo
        [CDD_Router_LowerIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
        .ddTxPduHandleId, PduInfoPtr);
    }
    else
    {
      /* Discard */
    }
  }
  else
  {
    /* Error handling */
  }
  #endif

  #if 0 
  /* If you configure 'CddIfUpperLayerPduRef' in 'CddIfUpperLayerPduRef of 'CddCanTpLowerLayerTxPdu',
     then you can use below sample code 
   * /AUTRON/Cdd/CddComStackContribution/CddCanTpLowerLayerContribution/CddCanTpLowerLayerTxPdu/CddIfUpperLayerPduRef 
   */
  #if(CDD_ROUTER_MAX_UPPER_CANTP_IF_TX_PDU_COUNT > 0)
  if(CddTxPduId < CDD_ROUTER_MAX_UPPER_CANTP_IF_TX_PDU_COUNT)
  {
    #if(CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0)
    if (CDD_Router_GaaUpperCanTpIfTxPduInfo[CddTxPduId].ddLayerType == CddComIfUpperLayer)
    {
      Ldd_ReturnValue = CanIf_Transmit((PduIdType)(CDD_Router_GaaLowerIfTxPduInfo[
      CDD_Router_GaaUpperCanTpIfTxPduInfo[CddTxPduId].ddLoTargetPduHandleId].ddTxPduHandleId), PduInfoPtr);
    }
    #endif /* #if(CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0) */
  }
  #endif /* #if(CDD_ROUTER_MAX_UPPER_CANTP_IF_TX_PDU_COUNT > 0) */
  #endif /* #if 0 */

  return Ldd_ReturnValue;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif  // #if ((CDD_ROUTER_MAX_LOWER_IF_TX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_LOWER_SOAD_IF_TX_PDU_COUNT >0))

/*This function is provided as a sample.
Purpose: Forward RxIndication from CanIf to upper layer module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_LOWER_IF_RX_PDU_COUNT > 0)
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CDD_ROUTER_CODE) CDD_RouterIF_RxIndication(PduIdType CddRxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  Std_ReturnType Ldd_ReturnValue = E_NOT_OK;
  #if 0 /* disable sample code */
  PduLengthType TpLength = 0;
  NotifResultType NotiResult = NTFRSLT_E_NOT_OK;
  PduInfoType LddPduInfo;
  if(CddRxPduId == CDD_Router_LowerIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
  {
    /* IF message handling */
    /* It is possible to transmit the PDU via CanIf/SoAd module directly(Sample1), but we do not recommend to use this gateway.*/
    /* For using functioniality of PduR module, we recomment to deliver received PDU to PduR module by using PduR_CDD_RouterIFRxIndication function(Sample2) */
    /* Sample 1 */
    Ldd_ReturnValue = CanIf_Transmit((PduIdType)CDD_Router_GaaLowerIfTxPduInfo
      [CDD_Router_LowerIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddTxPduHandleId, PduInfoPtr);

    /* Sample 2 */
    PduR_CDD_RouterIFRxIndication((PduIdType)CDD_Router_GaaUpperIfRxPduInfo
      [CDD_Router_UpperIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddRxPduHandleId, PduInfoPtr);
  }
  else if(CddRxPduId == CDD_Router_LowerIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
  {
    /* TP message handling */

    /* Sample for handling 0x7DF message CDD_RouterTP -> PduR -> Dcm */
    LddPduInfo.SduLength = PduInfoPtr->SduDataPtr[0];
    LddPduInfo.SduDataPtr = (PduInfoPtr->SduDataPtr + 1);

    #if (CDD_Router_FOUR_ONE_ONE == 0)
    if(BUFREQ_OK == PduR_CDD_RouterTPStartOfReception(
      (PduIdType)CDD_Router_GaaUpperTpRxPduInfo
      [CDD_Router_UpperTpRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddRxPduHandleId,
      LddPduInfo.SduLength, (PduLengthType*)&TpLength))
    {
      if(BUFREQ_OK == PduR_CDD_RouterTPCopyRxData(
        (PduIdType)CDD_Router_GaaUpperTpRxPduInfo
        [CDD_Router_UpperTpRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
        .ddRxPduHandleId, &LddPduInfo, (PduLengthType*)&TpLength))
      {
        NotiResult = NTFRSLT_OK;
      }
    }
    #else
    if(BUFREQ_OK == PduR_CDD_RouterTPStartOfReception(
      (PduIdType)CDD_Router_GaaUpperTpRxPduInfo
      [CDD_Router_UpperTpRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/].ddRxPduHandleId,
      (PduInfoType*)&LddPduInfo, LddPduInfo.SduLength, (PduLengthType*)&TpLength))
    {
      if(BUFREQ_OK == PduR_CDD_RouterTPCopyRxData(
        (PduIdType)CDD_Router_GaaUpperTpRxPduInfo
        [CDD_Router_UpperTpRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
        .ddRxPduHandleId, &LddPduInfo, (PduLengthType*)&TpLength))
      {
        NotiResult = NTFRSLT_OK;
      }
    }    
    #endif /* (CDD_Router_FOUR_ONE_ONE == 0) */
    PduR_CDD_RouterTPRxIndication(
      (PduIdType)CDD_Router_GaaUpperTpRxPduInfo
      [CDD_Router_UpperTpRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddRxPduHandleId, NotiResult);

    /* Sample for handling 0x7DF message CDD_RouterIF -> PduR -> CanIf */
    PduR_CDD_RouterIFRxIndication((PduIdType)CDD_Router_GaaUpperIfRxPduInfo
      [CDD_Router_UpperIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddRxPduHandleId, PduInfoPtr);
  }
  else if((CddRxPduId == CDD_Router_LowerIfRxPduId_XXXXXXXX) || (CddRxPduId == CDD_Router_LowerIfRxPduId_XXXXXXXX)/*Use MACRO which defined in CDD_Router_Cfg.h*/)
  {
    /* N : 1 Gateway handling */
    
    /* Sample for report gateway status to application */
    Rte_Call_CDDRoutingGroupHandlingClientServerInterface_CDD_RouterRequestMode(PDU_ID, PDU_STATUS);

    /* Sample for normal gateway status to application */
    PduR_CDD_RouterIFRxIndication((PduIdType)CDD_Router_GaaUpperIfRxPduInfo
      [CDD_Router_UpperIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddRxPduHandleId, PduInfoPtr);
  }
  else if(CddRxPduId == CDD_Router_LowerIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
  {
    /* CanTp IF message handling */

    /* Call CanTp_RxIndication */
    CanTp_RxIndication((PduIdType)CDD_Router_GaaUpperCanTpIfRxPduInfo
    [CDD_Router_UpperIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
    .ddRxPduHandleId, PduInfoPtr);

  }
  else
  {
    
    /* Error handling */  
  }
  #endif
}  
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif  //(CDD_ROUTER_MAX_LOWER_IF_RX_PDU_COUNT > 0)

/*This function is provided as a sample.
Purpose: Forward RxIndication from SoAd to upper layer module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_LOWER_SOAD_IF_RX_PDU_COUNT > 0)
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CDD_ROUTER_CODE) CDD_RouterIF_SoAdIfRxIndication(PduIdType CddRxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  Std_ReturnType Ldd_ReturnValue = E_NOT_OK;
  #if 0 /* disable sample code */
  PduLengthType TpLength = 0;
  NotifResultType NotiResult = NTFRSLT_E_NOT_OK;
  PduInfoType LddPduInfo;
  if(CddRxPduId == CDD_Router_LowerSoAdIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/)
  {
    /* IF message handling */
    /* It is possible to transmit the PDU via CanIf/SoAd module directly(Sample1), but we do not recommend to use this gateway.*/
    /* For using functioniality of PduR module, we recomment to deliver received PDU to PduR module by using PduR_CDD_RouterIFRxIndication function(Sample2) */
    /* Sample 1 */
    Ldd_ReturnValue = SoAdIf_Transmit((PduIdType)CDD_Router_GaaLowerSoAdIfTxPduInfo
        [CDD_Router_LowerSoAdIfTxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
        .ddTxPduHandleId, PduInfoPtr);

    /* Sample 2 */
    PduR_CDD_RouterIFRxIndication((PduIdType)CDD_Router_GaaUpperIfRxPduInfo
      [CDD_Router_UpperIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddRxPduHandleId, PduInfoPtr);
  }
  else if((CddRxPduId == CDD_Router_LowerSoAdIfRxPduId_XXXXXXXX) || (CddRxPduId == CDD_Router_LowerSoAdIfRxPduId_XXXXXXXX)/*Use MACRO which defined in CDD_Router_Cfg.h*/)
  {
    /* N : 1 Gateway handling */
    
    /* Sample for report gateway status to application */
    Rte_Call_CDDRoutingGroupHandlingClientServerInterface_CDD_RouterRequestMode(PDU_ID, PDU_STATUS);

    /* Sample for normal gateway status to application */
    PduR_CDD_RouterIFRxIndication((PduIdType)CDD_Router_GaaUpperIfRxPduInfo
      [CDD_Router_UpperIfRxPduId_XXXXXXXX/*Use MACRO which defined in CDD_Router_Cfg.h*/]
      .ddRxPduHandleId, PduInfoPtr);
  }
  else
  {
    
    /* Error handling */  
  }
  #endif
}  
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif  //(CDD_ROUTER_MAX_LOWER_SOAD_IF_RX_PDU_COUNT > 0)


/*This function is provided as a sample.
Purpose: Forward Transmit from PduR to lower layer module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_IPC_IF_TX_PDU_COUNT > 0)
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_IPC_IF_Transmit(PduIdType CddTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  Std_ReturnType Ldd_ReturnValue = E_NOT_OK;

  return Ldd_ReturnValue;
}
#endif  //(CDD_ROUTER_MAX_IPC_IF_TX_PDU_COUNT > 0)

/*This function is provided as a sample.
Purpose: Forward Transmit TP message from PduR to lower layer module
It can be deleted at the user's judgment*/
#if (CDD_ROUTER_MAX_IPC_TP_TX_PDU_COUNT > 0)
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_IPC_TP_Transmit(PduIdType CddTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  Std_ReturnType Ldd_ReturnValue = E_NOT_OK;

  return Ldd_ReturnValue;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif //(CDD_ROUTER_MAX_IPC_TP_TX_PDU_COUNT > 0)

/*This function is provided as a sample.
Purpose: Forward RxIndication from IPC Driver to upper layer module
It can be deleted at the user's judgment*/
#if ((CDD_ROUTER_MAX_IPC_IF_RX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_IPC_TP_RX_PDU_COUNT > 0))
#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CDD_ROUTER_CODE) CDD_IPC_RxIndication(
  P2CONST(uint8, AUTOMATIC, CDD_ROUTER_APPL_DATA)DataPtr)
{
#if 0    
  /* Process Data Format and Make Pdu
   * If DataPtr is formed 2B-ID, 2B-Length and Data
   */
  PduInfoType LddPduPtr;
  uint8 LucData[64];
  uint8 loop;

  /* User should get Id and DataLength, Below is just example */
  CddMsgIdType LusTargetId = 0x17ff07DF;
  PduLengthType LusDataLength = 0x00FF;
  PduIdType LusUpperLayerPduHandleId;

  for (loop = 0; loop < CDD_ROUTER_MAX_UPPER_IF_TX_PDU_COUNT; loop++)
  {
    if(CDD_IPC_GaaUpperIfRxPduInfo[loop].ddTargetAddressId == LusTargetId)
    {
      LusUpperLayerPduHandleId = CDD_IPC_GaaUpperIfRxPduInfo[loop].ddRxPduHandleId;
      memcpy(LucData, &DataPtr[4], LusDataLength);
      LddPduPtr.SduDataPtr = LucData;
      LddPduPtr.SduLength = LusDataLength;

      PduR_CDD_IPC_IFRxIndication(LusUpperLayerPduHandleId, (const)&LddPduPtr);
    }
    else if(CDD_IPC_GaaUpperTpRxPduInfo[loop].ddTargetAddressId == LusTargetId)
    {
      LusUpperLayerPduHandleId = CDD_IPC_GaaUpperTpRxPduInfo[loop].ddRxPduHandleId;
      memcpy(LucData, &DataPtr[4], LusDataLength);
      LddPduPtr.SduDataPtr = LucData;
      LddPduPtr.SduLength = LusDataLength;
      
      /* Do TP-Processing flow */            
    }
  }
#endif
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"
#endif //((CDD_ROUTER_MAX_IPC_IF_RX_PDU_COUNT > 0) || (CDD_ROUTER_MAX_IPC_TP_RX_PDU_COUNT > 0))

/* Not Supported Functions */
#if 0

#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_RouterIF_CancelTransmit
  (PduIdType CddTxPduId)
{
  /* Not Supported */
  return E_NOT_OK;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"


#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_RouterTP_Transmit
  (PduIdType CddTxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, CDD_ROUTER_APPL_DATA)PduInfoPtr)
{
  /* Not Supported */
  return E_NOT_OK;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"


#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_RouterTP_CancelTransmit
  (PduIdType CddTxPduId)
{
  /* Not Supported */
  return E_NOT_OK;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"


#define CDD_ROUTER_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CDD_ROUTER_CODE) CDD_RouterTP_CancelReceive
  (CONST(PduIdType, CDD_ROUTER_CODE) CddRxPduId)
{
  /* Not Supported */
  return E_NOT_OK;
}
#define CDD_ROUTER_STOP_SEC_CODE
#include "MemMap.h"

#endif /* Not Supported Functions */


/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/

