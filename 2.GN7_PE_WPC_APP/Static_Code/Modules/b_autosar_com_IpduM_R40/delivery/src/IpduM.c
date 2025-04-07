/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM.c                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Initialization processFunctions            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.1.0     19-May-2022   HM Shin     Internal Redmine #34769                **
** 2.0.5     07-Dec-2020   Jongsun Lim #27006                                 **
** 2.0.4     21-Dec-2016   Chan Kim    Internal Redmine #7006                 **
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #6822                 **
** 2.0.2     15-Jul-2016   Chan Kim    Internal Redmine #5552                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_IpduM.h"
#include "IpduM_Ram.h"
#include "IpduM.h"
#include "IpduM_Cbk.h"
#include "IpduM_Internal.h"
#include "IpduM_PCTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define IPDUM_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_C_AR_RELEASE_REVISION_VERSION 3

/* IPDUM software version information */
#define IPDUM_C_SW_MAJOR_VERSION            2
#define IPDUM_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != IPDUM_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != IPDUM_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_C_SW_MAJOR_VERSION)
#error "IpduM.c : Mismatch in Software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_C_SW_MINOR_VERSION)
#error "IpduM.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : IpduM_Init                                          **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This function performs initialization of            **
**                        IpduM buffer and RAM variables                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : config                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : IpduM_GblStatus            **
**                                                 IpduM_GaaTxOutIpdu[]       **
**                                                 IpduM_GaaTxInIpdu[]        **
**                                                 IpduM_GaaTxPendingFlag[]   **
**                                                 IpduM_No_Of_Tx_Pathways    **
**                                                 IpduM_Tx_Pending_Flag_Bytes**
**                        Function(s) invoked    : Com_TriggerTransmit()      **
**                                                 PduR_IpduMTriggerTransmit()**
**                                                 IpduM_CopySegmentBit()     **
**                                                 IpduM_CopySegmentByte()    **
*******************************************************************************/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_Init(P2CONST(IpduM_ConfigType, AUTOMATIC,
    IPDUM_CONST) config)
{
  #if (IPDUM_ENABLE == STD_ON)
  #if (IPDUM_TX_IPDU == STD_ON)
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) LpStatusFlag;
  P2CONST(IpduM_TxInIpdu, AUTOMATIC, IPDUM_CONST) LpTxInIpdu;
  /* Local pointer to point the starting location of IpduM */
  P2CONST(IpduM_TxOutIpdu, AUTOMATIC, IPDUM_CONST) LpTxOutIpdu;
  /* Local variable ptr to PduInfoPtr */
  P2VAR(PduInfoType, AUTOMATIC, IPDUM_VAR) LddPduInfo;
  /*Local structure of PduInfoType */
  PduInfoType LddPdu;
  PduIdType LddTxInPduId;
  uint16 LusStatusCount;
  uint16 LusIPDUMTxPdu;
  PduIdType LddTxPduIdIndex;
  uint8 LaaSduData[IPDUM_MAX_PDU_LENGTH];

  LddPduInfo = &LddPdu;
  LddPduInfo->SduDataPtr = &LaaSduData[IPDUM_ZERO];
  LusIPDUMTxPdu = (uint16)IpduM_No_Of_Tx_Pathways;

  while ((uint16)IPDUM_ZERO != LusIPDUMTxPdu)
  {
    LusIPDUMTxPdu--;
    /* Get the pointer to Tx out ipdu structure */
    LpTxOutIpdu = &IpduM_GaaTxOutIpdu[LusIPDUMTxPdu];
    #if (IPDUM_TX_STATIC_IPDU == STD_ON)
    if (IPDUM_TRUE == LpTxOutIpdu->blStaticIpduExist)
    {
      /* Initalisation  Static Part*/
      if (IPDUM_INVALID != LpTxOutIpdu->ddStaticPduId)
      {
        /* Get the static ipdu id */
        LddTxInPduId = LpTxOutIpdu->ddStaticPduId;
        /* Get the pointer to Tx in ipdu structure */
        LpTxInIpdu = &IpduM_GaaTxInIpdu[LddTxInPduId];
        #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
        /* Fetch the static part from com module */
        (void)Com_TriggerTransmit(LpTxInIpdu->ddTxUpIpduId, LddPduInfo);
        #else
        /* Fetch the static part from PduR module */
        (void)PduR_IpduMTriggerTransmit(LpTxInIpdu->ddTxUpIpduId, LddPduInfo);
        #endif /*#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
        /* Copy the data into dynamic I-PDUs buffer */
        #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
        IpduM_CopySegmentBit(LpTxInIpdu->pSegmentBitField,
          LddPduInfo->SduDataPtr,
          LpTxInIpdu->ucNoOfSegmentBitField);
        #else
        /* Copy the data into static I-PDUs buffer */
        IpduM_CopySegmentByte(LpTxInIpdu, LddPduInfo);
        #endif /* #if (IPDUM_COPY_BITFIELD == STD_ON) */
      }/* End of if(IpduM_GaaTxOutIpdu[LusIPDUMTxPdu].ddStaticPduId
        != IPDUM_INVALID) */
    }
    #endif /* #if (IPDUM_TX_STATIC_IPDU == STD_ON))*/
    /* Initalisation  Dynamic Part*/
    /* Get the initial dynamic ipdu id */
    LddTxInPduId = LpTxOutIpdu->ddInitialDynamicPduId;
    /* Get the pointer to Tx in ipdu structure */
    LpTxInIpdu = &IpduM_GaaTxInIpdu[LddTxInPduId];
    #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
    /* Fetch the dynamic part from com module */
    (void)Com_TriggerTransmit(LpTxInIpdu->ddTxUpIpduId, LddPduInfo);
    #else
    /* Fetch the dynamic part from PduR module */
    (void)PduR_IpduMTriggerTransmit(LpTxInIpdu->ddTxUpIpduId, LddPduInfo);
    #endif /*#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
    #if (IPDUM_TX_CONFIRMATION == STD_ON)
    /* Copy the Multiplexed and Transmitted Dynamic Handle Id*/
    IpduM_GaaTxConfrmDynamicHandleId[LpTxInIpdu->ddTxOutIpduId]
     = LddTxInPduId;
    #endif /*#if (IPDUM_TX_CONFIRMATION == STD_ON)*/
    /* Copy the data into dynamic I-PDUs buffer */
    #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
    IpduM_CopySegmentBit(LpTxInIpdu->pSegmentBitField, LddPduInfo->SduDataPtr,
      LpTxInIpdu->ucNoOfSegmentBitField);
    #else
    IpduM_CopySegmentByte(LpTxInIpdu, LddPduInfo);
    #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */
  };

  /* Get the pointer to pending flag status */
  LddTxPduIdIndex = (PduIdType)IPDUM_ZERO;
  LpStatusFlag = &IpduM_GaaTxPendingFlag[LddTxPduIdIndex];

  /* Get the number of Tx Pending Status bytes into local variable */
  LusStatusCount = (uint16)IpduM_Tx_Pending_Flag_Bytes;

  do
  {
    /* Reset Tx Pending Status flag to zero */
    *LpStatusFlag = (uint8)IPDUM_ZERO;

    /* Increment pointer by one */

    LddTxPduIdIndex++;
    LpStatusFlag = &IpduM_GaaTxPendingFlag[LddTxPduIdIndex];

    /* Decrement count by one */
    --LusStatusCount;
  } while ((uint16)IPDUM_ZERO != LusStatusCount);

  #endif /*#if (IPDUM_TX_IPDU == STD_ON) */

  /* set the Ipdum init status TRUE*/
  IpduM_GblStatus = IPDUM_INIT;

  IPDUM_UNUSED_PTR(config);
  #else
  IpduM_GblStatus = IPDUM_UNINIT;

  IPDUM_UNUSED_PTR(config);
  #endif /*#if (IPDUM_ENABLE == STD_ON) */
}                                 /* End of IpduM_Init */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IpduM_GetVersionInfo                                **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : This function returns the version information of the**
**                        IpduM Module.                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : versioninfo                                         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : Det_ReportError()          **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_VERSION_INFO_API == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_GetVersionInfo(P2VAR(Std_VersionInfoType,
    AUTOMATIC, IPDUM_VAR) versioninfo)
{
  #if (IPDUM_DEV_ERROR_DETECT == STD_ON)

  /* Check whether version information is equal to NULL */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET */
    (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
      (uint8)IPDUM_GETVERSIONINFO_SID, (uint8)IPDUM_E_PARAM_POINTER);
  }
  else
  #endif /* End of if (IPDUM_DEV_ERROR_DETECT == STD_ON) */
  {
   /* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
    /* Copy the vendor ID */
    versioninfo->vendorID = (uint16)IPDUM_VENDOR_ID;

    /* Copy the module ID */
    versioninfo->moduleID = (uint16)IPDUM_MODULE_ID;

    /* Copy software major version */
    versioninfo->sw_major_version = (uint8)IPDUM_SW_MAJOR_VERSION;

    /* Copy software minor version */
    versioninfo->sw_minor_version = (uint8)IPDUM_SW_MINOR_VERSION;

    /* Copy software patch version */
    versioninfo->sw_patch_version = (uint8)IPDUM_SW_PATCH_VERSION;
    /* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
  }
}                                 /* End of IpduM_GetVersionInfo */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (IPDUM_VERSION_INFO_API == STD_ON) */
#endif 
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

