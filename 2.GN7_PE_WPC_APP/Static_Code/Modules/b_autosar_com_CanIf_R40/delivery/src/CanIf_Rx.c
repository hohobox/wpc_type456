/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Rx.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of Receive Indication Functionality                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 3.2.0    17-Jan-2025    Jh.Yang   #48464                                   **
** 3.1.1    08-Sep-2023    Jh.Yang   #42361                                   **
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.5    12-Aug-2022    Jh.Yang   #36772                                   **
** 3.0.2    21-Feb-2022    Sj.Kim    #34443                                   **
** 3.0.1    28-Dec-2021    Sj.Kim    #33378                                   **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.2    12-Jan-2021    Sj.Kim    #27560                                   **
** 2.7.1    25-Nov-2020    Sj.Kim    #26002                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.2    15-May-2020    Sj.Kim    #23352, #21882, #23360                   **
** 2.6.1    15-May-2020    Js.Lim    #22638                                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384, #19016                           **
** 2.5.6    10-May-2018    Js.Lim    #12562, #12222                           **
** 2.5.5    10-Jan-2018    Js.Lim    #11197                                   **
** 2.5.4    11-Oct-2017    C.Kim     #9850                                    **
** 2.5.3    20-Jul-2017    Js.Lim    #9287                                    **
** 2.5.2    18-Apr-2017    Js.Lim    #8241                                    **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 2.3.7    13-Jun-2016    Kt.Kim    #5139                                    **
** 2.3.6    18-Mar-2016    Kt.Kim    #4442                                    **
** 2.3.5    11-Mar-2016    Kt.Kim    #4386                                    **
** 2.3.4    12-Feb-2016    Kt.Kim    MISRA Justification                      **
** 2.3.3    25-Aug-2015    Kt.Kim    #2999                                    **
**                                   Justification for Runtime Error          **
** 2.3.2    13-Jun-2015    Kt.Kim    #2724                                    **
** 2.2.0    30-May-2013    Kt.Kim    Lib-Build Support                        **
** 2.1.0    29-May-2013    Kt.Kim    OsekNm Support                           **
** 1.0.0    30-Apr-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Ram.h"           /* RAM header file */
#include "CanIf_PCTypes.h"       /* Pre-compile type header file */
#include "CanIf_Rx.h"            /* Receive header */
#include "CanSM_Cbk.h"           /* CAN State Manager call back header file */
#include "SchM_CanIf.h"          /* SchM CanIf Header file */
#include "CanIf_Can.h"                  /* CAN Driver Module Header File */
#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "CanIf_Error.h"         /* CanIf DET file */
#endif
#if (STD_ON == CANIF_AUTOEVER_CANTRCV_SUPPORT)
#include "CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_EXTENAL_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"            /* CanTrcv header file */
#endif
#include "CanIf_UserInc.h"
#if (STD_ON == CANIF_IDSM_SUPPORT)
#include "IdsM_Cbk.h"            /* IdsM Module header file */
#endif
#if (CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440)
#include "Can_GeneralTypes.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANIF_RX_C_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_RX_C_AR_RELEASE_MINOR_VERSION    0
#define CANIF_RX_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANIF_RX_C_SW_MAJOR_VERSION    3
#define CANIF_RX_C_SW_MINOR_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_RX_AR_RELEASE_MAJOR_VERSION != \
  CANIF_RX_C_AR_RELEASE_MAJOR_VERSION)
  #error "CANIF_RX.c : Mismatch in Specification Major Version"
#endif
#if (CANIF_RX_AR_RELEASE_MINOR_VERSION != \
  CANIF_RX_C_AR_RELEASE_MINOR_VERSION)
  #error "CANIF_RX.c : Mismatch in Specification Minor Version"
#endif
#if (CANIF_RX_AR_RELEASE_REVISION_VERSION != \
  CANIF_RX_C_AR_RELEASE_REVISION_VERSION)
  #error "CANIF_RX.c : Mismatch in Specification Revision Version"
#endif
#if (CANIF_RX_SW_MAJOR_VERSION != CANIF_RX_C_SW_MAJOR_VERSION)
  #error "CANIF_RX.c : Mismatch in Software Major Version"
#endif
#if (CANIF_RX_SW_MINOR_VERSION != CANIF_RX_C_SW_MINOR_VERSION)
  #error "CANIF_RX.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if (STD_ON == CANIF_RX_BASIC_CAN_SUPPORT)
#if ((STD_ON == CANIF_BINARY_SEARCH)||(STD_ON == CANIF_IDTABLE_SEARCH))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_RxLpduPCType, CANIF_CODE)
                         CanIf_BinarySearch (
                         CanIf_RxLpduPCType LpRxLpdu,
                         VAR(PduIdType, CANIF_VAR) LddSize,
                         VAR(Can_IdType, CANIF_VAR) LddCanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#if (STD_ON == CANIF_RX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_RxNotification (
                         CanIf_RxLpduPCType LpRxLpdu,
                         VAR(uint8, CANIF_VAR) CanDlc,
                         CanIf_Uint8PCtype CanSduPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API) || \
                                           (STD_ON == CANIF_READRXPDU_DATA_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_RxStatusUpdate (
                       CanIf_RxLpduPCType LpRxLpdu,
                       P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_LINEAR_SEARCH)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_RxLpduPCType, CANIF_CODE)
                         CanIf_LinearSearch (
                         CanIf_RxLpduPCType LpRxLpdu,
                         VAR(PduIdType, CANIF_VAR) LddSize,
                         VAR(Can_IdType, CANIF_VAR) LddCanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_RX_BASIC_CAN_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_RxLpduPCType, CANIF_CODE)
                          CanIf_TriggerSWFilter (
                          P2CONST(CanIf_Hrh, AUTOMATIC, CANIF_CONST) LpHrh,
                          VAR(Can_IdType, CANIF_VAR) CanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* #5139 */
#if ((STD_ON == CANIF_RX_LPDU) && (STD_ON == CANIF_META_DATA_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_Uint8PCtype, CANIF_CODE) CanIf_RxData
  (Can_IdType CanId, uint8 CanDlc, CanIf_RxLpduPCType
    LpRxLpdu, P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : CanIf_RxNotification                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service provides the Rx Indication to the      **
**                        respective upper layers                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpRxLpdu, CanDlc                                    **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GblCanIfStatus            **
**                                            CanIf_GaaRxCbkUser              **
**                        Function(s) invoked:Det_ReportError,                **
**                                            CanIf_RxStatusUpdate,           **
**                                            IdsM_MsgReceptionReport         **
*******************************************************************************/
#if (STD_ON == CANIF_RX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_RxNotification (
                         CanIf_RxLpduPCType LpRxLpdu,
                         VAR(uint8, CANIF_VAR) CanDlc,
                         CanIf_Uint8PCtype CanSduPtr)
{
  P2CONST(CanIf_RxCbkUser, AUTOMATIC, CANIF_CONST) LpRxCbkUser;
  VAR(PduInfoType, CANIF_VAR) LddPduInfo;
  VAR(PduIdType, CANIF_VAR) LddTargetId;
  VAR(uint8, CANIF_VAR) LucVar;
  VAR(uint8, CANIF_VAR) LucDataLen;
  LucDataLen = CanDlc;

  memset(&LddPduInfo, CANIF_ZERO, sizeof(PduInfoType));

  /* 8241 */
  #if((STD_ON == CANIF_CANFD_SUPPORT) && (STD_ON == CANIF_CANFD_DISCRETE_DLC_SUPPORT))
  if((CanDlc > CANIF_EIGHT) && (CanDlc < CANIF_16))
  {
    LucDataLen = CanIf_GaaDiscreteDlctoDataLength[CanDlc - CANIF_NINE];
  }
  #endif

  #if(STD_ON == CANIF_DLC_CHECK_ENABLED)
  /* polyspace +2 MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
  /* polyspace +1 RTE:IDP [Not a defect: Justified] "Pointer is not outside its bounds." */
  if (LpRxLpdu->ucDlc <= LucDataLen)
  #endif
  {
    /* polyspace +1 MISRA-C3:11.8, CERT-C:EXP05-C [Not a defect:Justified] "This parameter was defined by specification." */
    LddPduInfo.SduDataPtr = (uint8 *)CanSduPtr;
    /* Get the SDU length*/
    /* #5139 */
    #if (STD_ON == CANIF_META_DATA_SUPPORT)
    /* Get the SDU length*/
    LddPduInfo.SduLength =  (PduLengthType)LucDataLen + (PduLengthType)LpRxLpdu->ucMetaDataLength;
    #else
    /* Get the SDU length*/
    LddPduInfo.SduLength = (uint8)LucDataLen;
    #endif
    #if (STD_ON == CANIF_IDSM_SUPPORT)
    if((LpRxLpdu->ucRxUserOrNotifSts & CANIF_RX_IDSM_REPORT_MASK) != CANIF_ZERO)
    {
      IdsM_MsgReceptionReport(LpRxLpdu->ddRxPduId, &LddPduInfo);
    }
    #endif
    #if ((STD_ON == CANIF_RX_LPDU) && (STD_ON == CANIF_TX_RX_MONITORING_SUPPORT))
    CanIf_GaaReceiveCnt[LpRxLpdu->ddRxPduId]++;
    #endif

    #if ((STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API) || \
          (STD_ON == CANIF_READRXPDU_DATA_API))
    /* Invoke CanIf_RxStatusUpdate for updation of RxPdu structure */
    CanIf_RxStatusUpdate(LpRxLpdu, &LddPduInfo);
    #endif
    /* Get the upper layer user into local variable */
    LucVar = ((CANIF_UL_MASK) & (LpRxLpdu->ucRxUserOrNotifSts));
    /* Check whether any upper layer is configured for upper layer
     indication */
    if (CANIF_MAX_UL >= LucVar)
    {
      /* Get TargetId */
      LddTargetId = (PduIdType)LpRxLpdu->ddTargetId;
      /* polyspace-begin CERT-C:DCL39-C [Not a defect:Justified] "This parameter was defined by specification" */
      #if(STD_ON == CANIF_RX_MULTIPLE_CALLBACK)
      {
        /* Get the pointer to RxCbkUser structure */
        LpRxCbkUser = &CanIf_GpRxMulCbkUser[LpRxLpdu->ucCallbackIndex];
        /* invoke the respective upper layer Indication for received PDU */
        LpRxCbkUser->pRxIndication(LddTargetId, &LddPduInfo);
      }
      #else
      {
        /* polyspace-begin MISRA-C3:18.1, RTE:OBAI,IDP [Not a defect:Justified] "Its boundary is pre-defined" */
        LpRxCbkUser = &CanIf_GaaRxSingleCbkUser[LucVar];

        /* polyspace +1 RTE:COR [Not a defect:Justified] "function is pre-defined" */
        LpRxCbkUser->pRxIndication(LddTargetId, &LddPduInfo);
        /*CanIf_GaaRxSingleCbkUser[LucVar].pRxIndication(LddTargetId, &LddPduInfo);*/
        /* polyspace-end MISRA-C3:18.1, RTE:OBAI,IDP [Not a defect:Justified] "Its boundary is pre-defined" */
      }
      #endif
      /* polyspace-end CERT-C:DCL39-C [Not a defect:Justified] "This parameter was defined by specification" */
    } /*  if (CANIF_MAX_UL >= LucVar) */
  } /* if (LpRxLpdu->ucDlc <= LucDiscreteLen) */
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  #if ((STD_ON == CANIF_DLC_CHECK_ENABLED) && (STD_ON == CANIF_DEV_ERROR_DETECT))
  else
  {
    /* Report to DET for invalid DLC*/
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                    CANIF_RX_INDICATION_SID, CANIF_E_PARAM_DLC);
  }
  #endif
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (STD_ON == CANIF_RX_LPDU) */

/*******************************************************************************
** Function Name        : CanIf_RxIndication                                  **
**                                                                            **
** Service ID           : 0x14                                                **
**                                                                            **
** Description          : This service indicates a L-PDU reception of a       **
**                        CAN L-PDU in any of the CAN drivers. This           **
**                        service performs software filtering and DLC check.  **
**                        On successful completion of software filtering and  **
**                        DLC check the upper layer is notified with          **
**                        respective upper layer call back function.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant but not for same HRH                     **
**                                                                            **
** Input Parameters     : Hrh, CanId, CanDlc, CanSduPtr                       **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised               **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GblCanIfStatus,           **
**                                            CanIf_GaaController             **
**                                            CanIf_GaaHrhMapArray,           **
**                                            CanIf_GaaHrh                    **
**                                            CanIf_GddRxCanId                **
**                        Function(s) invoked:CanIf_RxNotification            **
**                                            SchM_Enter_CanIf_MODE_STATUS_   **
**                                            PROTECTION,                     **
**                                            SchM_Exit_CanIf_MODE_STATUS_    **
**                                            PROTECTION,                     **
**                                            Det_ReportError,                **
**                                            CanIf_TriggerSWFilter           **
*******************************************************************************/
#if (STD_ON == CANIF_RX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
#if ((CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440) || \
      (((CAN_AR_RELEASE_MAJOR_VERSION == CAN_AR_RELEASE_MAJOR_VERSION_FOUR) && \
      (CAN_AR_RELEASE_MINOR_VERSION >= CAN_AR_RELEASE_MINOR_VERSION_TWO)) || \
      (CAN_AR_RELEASE_MAJOR_VERSION > CAN_AR_RELEASE_MAJOR_VERSION_FOUR)))
FUNC(void, CANIF_CODE) CanIf_RxIndication(
           P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_CONST) Mailbox,
           P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr)
#else
FUNC(void, CANIF_CODE) CanIf_RxIndication(
           VAR(Can_HwHandleType, CANIF_VAR) Hrh,
           VAR(Can_IdType, CANIF_VAR) CanId,
           VAR(uint8, CANIF_VAR) CanDlc,
           P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr)
#endif
{
  /* #5139 */
  CanIf_Uint8PCtype LpSduPtr;
  CanIf_RxLpduPCType LpRxLpdu;
  P2CONST(CanIf_Hrh, AUTOMATIC, CANIF_CONST) LpHrh;
  P2VAR(CanIf_Controller, AUTOMATIC, CANIF_VAR) LpController;
  VAR(uint8, CANIF_VAR) LucRxStatus;
  VAR(uint8, CANIF_VAR) LucSftwrFltrng;
  VAR(Can_HwHandleType, CANIF_VAR) Lddhrh;
  VAR(Can_IdType, CANIF_VAR) LddCanId;
  VAR(uint8, CANIF_VAR) LucCanDlc;
  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  VAR(uint8, CANIF_VAR) LucHrhOffset;
  VAR(uint8, CANIF_VAR) LucCanDriverId;
  #endif
  CanIf_Uint8PCtype LpCanSduPtr;
  VAR(CanIf_PtrSize, CANIF_VAR) nHrhIndex;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(uint8, CANIF_VAR) LenStdRetVal;
  #endif
  #if ((CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440) || \
      (((CAN_AR_RELEASE_MAJOR_VERSION == CAN_AR_RELEASE_MAJOR_VERSION_FOUR) && \
      (CAN_AR_RELEASE_MINOR_VERSION >= CAN_AR_RELEASE_MINOR_VERSION_TWO)) || \
      (CAN_AR_RELEASE_MAJOR_VERSION > CAN_AR_RELEASE_MAJOR_VERSION_FOUR)))
  /* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
  Lddhrh = Mailbox->Hoh;
  LddCanId = Mailbox->CanId;
  /* DLC is smaller than 256 */
  LucCanDlc = (uint8)PduInfoPtr->SduLength;
  LpCanSduPtr = PduInfoPtr->SduDataPtr;
  /* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  LucCanDriverId = CanIf_GaaControllerConfigType[Mailbox->ControllerId].ucCanDriverId;
  LucHrhOffset = CanIf_GaaHrhInit[LucCanDriverId].ucHrhOffSetId;
  #endif
  #else
  Lddhrh = Hrh;
  LddCanId = CanId;
  LucCanDlc = CanDlc;
  LpCanSduPtr = CanSduPtr;

  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  LucHrhOffset = CANIF_ZERO;
  LucCanDriverId = CanIf_GaaControllerConfigType[CanIf_GaaHrh[CanIf_GaaHrhMapArray[Lddhrh + LucHrhOffset]].ucControllerId].ucCanDriverId;
  #endif
  #endif

  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Initialize error status flag to false */
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized */
  /* polyspace +2 MISRA-C3:8.3 [Not a defect:Justified] "Declaration is matched" */
  /* polyspace +1 DEFECT:DECL_MISMATCH [Not a defect:Justified] "Declaration is matched" */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_RX_INDICATION_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if HRH Id is out of range */
  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  /* polyspace +2 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Genderated array index in range" */
  #if ((CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440) || \
      (((CAN_AR_RELEASE_MAJOR_VERSION == CAN_AR_RELEASE_MAJOR_VERSION_FOUR) && \
      (CAN_AR_RELEASE_MINOR_VERSION >= CAN_AR_RELEASE_MINOR_VERSION_TWO)) || \
      (CAN_AR_RELEASE_MAJOR_VERSION > CAN_AR_RELEASE_MAJOR_VERSION_FOUR)))
  if (((Lddhrh) > CanIf_GaaHrhArrayId[LucCanDriverId]) || (CANIF_INVALID == CanIf_GaaHrhMapArray[(Lddhrh + LucHrhOffset)]))
  #else
  if (((Lddhrh) > CanIf_GaaHrhArrayId[LucCanDriverId] + CanIf_GaaHrhInit[LucCanDriverId].ucHrhOffSetId) || (CANIF_INVALID == CanIf_GaaHrhMapArray[(Lddhrh + LucHrhOffset)]))
  #endif
  #else
  if (((Lddhrh) > CanIf_GaaHrhArrayId[CANIF_ZERO]) || (CANIF_INVALID == CanIf_GaaHrhMapArray[(Lddhrh)]))
  #endif
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                    CANIF_RX_INDICATION_SID, CANIF_E_PARAM_HRH);
    LenStdRetVal = (uint8)E_NOT_OK;
  }

  if ((uint8)E_OK == LenStdRetVal)
  {
    /* polyspace +1 MISRA-C3:D4.14,18.1, RTE:IDP,OBAI [Not a defect: Justified] "Its boundary is pre-defined" */
    #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
    LucSftwrFltrng = CanIf_GaaHrh[CanIf_GaaHrhMapArray[Lddhrh + LucHrhOffset]].ucFilterMethod;
    #else
    LucSftwrFltrng = CanIf_GaaHrh[CanIf_GaaHrhMapArray[Lddhrh]].ucFilterMethod;
    #endif
    #if ((STD_ON == CANIF_RX_STANDARD_CANID_ONLY) ||\
                                                (STD_ON == CANIF_RX_EXT_STD_CANID))
    /* If CanId is out of range of STD */
    if ((((uint8)CANIF_RX_BASIC_CAN_STD == LucSftwrFltrng) ||
                      ((uint8)CANIF_RX_FULL_CAN_STD == LucSftwrFltrng)) &&
                      (LddCanId >  CANIF_STANDARD_CANID_VALUE) &&
                      ((LddCanId & CANIF_STANDARD_FD_VALUE)== CANIF_ZERO))
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                  CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID);
      LenStdRetVal = (uint8)E_NOT_OK;
    }
    #endif
    #if ((STD_ON == CANIF_RX_EXTENDED_CANID_ONLY) ||\
                                                (STD_ON == CANIF_RX_EXT_STD_CANID))
    /* If CanId is out of range of EXT*/
    if ((((uint8)CANIF_RX_BASIC_CAN_EXT == LucSftwrFltrng) ||
                      ((uint8)CANIF_RX_FULL_CAN_EXT == LucSftwrFltrng)) &&
                      (LddCanId >  CANIF_EXTENDED_CANID_VALUE) &&
                      ((LddCanId & CANIF_EXTENDED_FD_VALUE)== CANIF_ZERO))
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID);
      LenStdRetVal = (uint8)E_NOT_OK;
    }
    #endif
    /* Report to DET, if CanSduPtr is null pointer */
    if (LpCanSduPtr == NULL_PTR)
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                       CANIF_RX_INDICATION_SID, CANIF_E_PARAM_POINTER);
      LenStdRetVal = (uint8)E_NOT_OK;
    }
  }

  /* Check whether any development errors are detected ?*/
  if ((uint8)E_OK == LenStdRetVal)
  #endif /* if development error is not enabled */
  /* Initialize value as null pointer */
  {

    #if(CANIF_BUSLOAD_DETECTING_SUPPORT == STD_ON)
    #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
    /* polyspace +1 RTE:OBAI [Not a defect: Justified] "Pointer is not outside its bounds." */
    #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
    CanIf_GaaRxMsgCnt[CanIf_GaaHrh[CanIf_GaaHrhMapArray[Lddhrh + LucHrhOffset]].ucControllerId]++;
    #else
    CanIf_GaaRxMsgCnt[CanIf_GaaHrh[CanIf_GaaHrhMapArray[Lddhrh]].ucControllerId]++;
    #endif
    #else
    CanIf_GaaRxMsgCnt[CANIF_ZERO]++;
    #endif
    #endif
    /* Get the pointer to HRH structure */
    LpHrh = &CanIf_GaaHrh[CANIF_ZERO];
    /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Array Indexing is not used to achieve better throughput. */
    /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Configuration Index is generated value based on Ecudescription" */
    #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
    nHrhIndex = ((CanIf_PtrSize)CanIf_GaaHrhMapArray[Lddhrh + LucHrhOffset]);
    #else
    nHrhIndex = ((CanIf_PtrSize)CanIf_GaaHrhMapArray[Lddhrh]);
    #endif
    #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
    /* Get the pointer to Controller */
    LpController = &CanIf_GaaController[LpHrh[nHrhIndex].ucControllerId];
    #else
    /* Get the pointer to Controller for single CanIfController configured */
    LpController = &CanIf_GaaController[CANIF_ZERO];
    #endif

    #if (STD_ON == CANIF_CANFD_SUPPORT)
    /* Clear the Second Most Significant Bit of fd frame*/
    #if (STD_OFF == CANIF_RX_STANDARD_CANID_ONLY)
    if ((LddCanId & CANIF_EXTENDED_BIT_SET) == CANIF_EXTENDED_BIT_SET)
    {
      if ((LddCanId & CANIF_EXTENDED_FD_VALUE) == CANIF_EXTENDED_FD_VALUE)
      {
        LddCanId = (Can_IdType)(LddCanId & CANIF_EXTENDED_CANID_VALUE);
      }
    }
    else
    #endif
    {
      if ((LddCanId & CANIF_STANDARD_FD_VALUE) == CANIF_STANDARD_FD_VALUE)
      {
        LddCanId = (Can_IdType)(LddCanId & CANIF_STANDARD_CANID_VALUE);
      }
    }
    #endif
    /* Save CAN identifier to global variable */
    CanIf_GddRxCanId = LddCanId;
    /* Check if Rx status of controller is set */
    /* polyspace<RTE: IDP : Not a defect : No Action Planned >
      Its boundary is pre-defined           */
    /* polyspace +1 MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
    LucRxStatus = LpController->ucRxStatus;
    /* Check the rx status of controller is not disabled */
    if (CANIF_RX_DISABLED != LucRxStatus)
    {
      #if ((STD_ON == CANIF_WAKEUP_CHECK_VALIDATION_SUPPORT))
      /* Check the rx status of controller is enabled */
      if (CANIF_RX_ENABLED == LucRxStatus)
      {
        /* Disable relevant interrupts */
        SchM_Enter_CanIf_MODE_STATUS_PROTECTION();
        /* Set the wakeup validation flag  - CANIF_RX_VALIDATE_WAKEUP 0x81 */
        LpController->ucRxStatus = CANIF_RX_VALIDATE_WAKEUP;
        /* Enable relevant interrupts */
        SchM_Exit_CanIf_MODE_STATUS_PROTECTION();
      }
      #endif
      #if (STD_ON == CANIF_RX_BASIC_CAN_SUPPORT)
      #if (STD_ON == CANIF_RX_FULL_CAN_SUPPORT)
      /* Check whether that HRH is FullCAN or BasicCAN */
      /* polyspace +2 MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
      /* polyspace +1 RTE:IDP [Not a defect: Justified] "Pointer is not outside its bounds." */
      LucSftwrFltrng = LpHrh[nHrhIndex].ucFilterMethod;
      /* Filter Method :
         0x00: -> BasicCAN WITH STANDARD
         0x01: -> BASICCAN WITH EXTENDED
         0x02: -> BASICCAN WITH MIXED
         0x03: -> FULLCAN WITH STANDARD
         0x04: -> FULLCAN WITH EXTENDED
         0x05: -> FULLCAN WITH MIXED */
      if (LucSftwrFltrng <= CANIF_RX_BASIC_CAN_MIXED)
      #endif
      {
        /* call the S/W triggerring function */
          LpRxLpdu = CanIf_TriggerSWFilter(&LpHrh[nHrhIndex], LddCanId);
        /* Check whether Rx LPDU is null pointer and invoke notification */
        if (LpRxLpdu != NULL_PTR)
        {
          /* #5139 */
          #if ((STD_ON == CANIF_RX_LPDU) && (STD_ON == CANIF_META_DATA_SUPPORT))
          LpSduPtr = CanIf_RxData(LddCanId, LucCanDlc, LpRxLpdu, LpCanSduPtr);
          #else
          LpSduPtr = LpCanSduPtr;
          #endif /* (STD_ON == CANIF_RX_LPDU) && (STD_ON == CANIF_META_DATA_SUPPORT) */
          CanIf_RxNotification(LpRxLpdu, LucCanDlc, LpSduPtr);
        }
      }
      #if (STD_ON == CANIF_RX_FULL_CAN_SUPPORT)
      else
      #endif
      #endif
      {
        /* For the Case of FULL CAN */
        #if (STD_ON == CANIF_RX_FULL_CAN_SUPPORT)
        /* Get the pointer to desired Rx L-PDU of range/list type */
        #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
        LpRxLpdu = &CanIf_GaaRxLpduSelect[LpHrh[nHrhIndex].ddRxLpduIndex];
        #else
        LpRxLpdu = &CanIf_GaaRxLpdu[LpHrh[nHrhIndex].ddRxLpduIndex];
        #endif

        /* Invoke CanIf_RxNotification to invoke upper layer indication */
        CanIf_RxNotification(LpRxLpdu, LucCanDlc, LpCanSduPtr);
        #endif
      }
    }/* if (CANIF_RX_DISABLED != LucRxStatus) */
  } /* if CANIF_DEV_ERROR_DETECT */
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_ReadRxNotifStatus                             **
**                                                                            **
** Service ID           : 0x08                                                **
**                                                                            **
** Description          : This service provides the status of the CAN Rx      **
**                        L-PDU requested by CanRxPduId. This API service     **
**                        notifies the upper layer about any transmit         **
**                        confirmation or receive indication event to the     **
**                        corresponding requested CAN Rx L-PDU.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : CanRxPduId                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : CanIf_NotifStatusType(CANIF_NO_NOTIFICATION,        **
**                                           CANIF_TX_RX_NOTIFICATION)        **
**                                                                            **
** Preconditions        : The CAN Interface must be initialized               **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GblCanIfStatus            **
**                                            CanIf_GaaController,            **
**                                            CanIf_GaaRxLpduNotify           **
**                        Function(s) invoked:Det_ReportError                 **
**                                            SchM_Enter_CanIf_RX_NOTIFSTATUS_**
**                                            PROTECTION,                     **
**                                            SchM_Exit_CanIf_RX_NOTIFSTATUS_ **
**                                            PROTECTION                      **
**                                                                            **
*******************************************************************************/
#if (STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus (VAR(PduIdType, CANIF_VAR) CanRxPduId)
{
  CanIf_RxLpduPCType LpRxLpdu;
  P2VAR(CanIf_RxLpduNotify, AUTOMATIC, CANIF_VAR) LpRxLpduNotify;
  CanIf_NotifStatusType LenNotifStsType;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  uint8 LucNotifStatus;
  uint8 LenStdRetVal;
  #endif
  uint8 LucPdu;
  uint16 LusRxPduCnt;

  LusRxPduCnt = CanIf_GddPrecompOpt.ddNumOfRxPdu;
  LucPdu = CANIF_FALSE;
  /* Initialize LenNotifStsType to CANIF_NO_NOTIFICATION */
  LenNotifStsType = CANIF_NO_NOTIFICATION;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  LenStdRetVal = CANIF_ZERO;
  /* Report to DET, if module is not initialized */

  if ((boolean)CANIF_UNINITIALISED == CanIf_GblCanIfStatus)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                CANIF_READ_RX_NOTIF_STATUS_SID, CANIF_E_UNINIT);
    LenStdRetVal++;
  }
  /* Report to DET, if RXPDUID is not in limits */

  if (CanRxPduId >= CanIf_GddPrecompOpt.ddNumOfRxPdu)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_READ_RX_NOTIF_STATUS_SID, CANIF_E_INVALID_RXPDUID);
    LenStdRetVal++;
  }
  #if (STD_OFF == CANIF_READRXPDU_DATA_API)
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_READ_RX_NOTIF_STATUS_SID, CANIF_E_INVALID_RXPDUID);
  LenStdRetVal++;
  #endif
  if ((uint8)CANIF_ZERO == LenStdRetVal)
  #endif
  {
    /* Get the pointer to first Rx L-PDU of range/list type */
    #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
    LpRxLpdu = &CanIf_GaaRxLpduSelect[CANIF_ZERO];
    #else
    LpRxLpdu = &CanIf_GaaRxLpdu[CANIF_ZERO];
    #endif
    /* Get the pointer to desired Rx L-PDU of range/list type */
    do
    {
      /* #5139 */
      /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Configuration Index is generated value based on Ecudescription" */
      if (CanRxPduId != (PduIdType)LpRxLpdu->ddRxPduId)
      {

        LpRxLpdu++;
        LusRxPduCnt--;
      }
      else
      {
        #if (STD_ON == CANIF_DEV_ERROR_DETECT)
        LucNotifStatus = LpRxLpdu->ucRxUserOrNotifSts;
        /* Report to DET if Status information is not available for RxPDU*/
        /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
        if ((LucNotifStatus & CANIF_RX_NOTIFY_STATUS_MASK) == CANIF_ZERO)
        {
          (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                       CANIF_READ_RX_NOTIF_STATUS_SID, CANIF_E_INVALID_RXPDUID);

          LenStdRetVal++;
        }/* if ((LucNotifStatus & 0x10) == CANIF_ZERO) */
        #endif
        /* to break the loop */
        LucPdu = CANIF_TRUE;
      }
    }while((LucPdu != CANIF_TRUE) && (LusRxPduCnt != CANIF_ZERO));

    #if (STD_ON == CANIF_DEV_ERROR_DETECT)
    /* Check whether any development error are detected */
    /* polyspace +1 MISRA-C3:14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
    if ((uint8)CANIF_ZERO == LenStdRetVal)
    #endif
    {
      if (LucPdu == CANIF_TRUE)
      {
        /* Get the pointer to RxLpduNotify structure */
        /* polyspace +1 MISRA-C3:18.4 [Not a defect: Justified] "Decrement and Increment operator is used to achieve better throughput" */
        LpRxLpduNotify = &CanIf_GaaRxLpduNotify[CANIF_ZERO] +
                                                         LpRxLpdu->ddRxNotifyId;
        /* Check whether RxLpduStatus is set or not */
        if ((LpRxLpduNotify->ucDlcOrNotify & CANIF_NOTIFY_STATUS_MASK) !=
                                                              (uint8)CANIF_ZERO)
        {
          /* Disable relevant interrupts */
          SchM_Enter_CanIf_RX_NOTIFSTATUS_PROTECTION();
          /* Reset the notification status */
          LpRxLpduNotify->ucDlcOrNotify &= (uint8)(~CANIF_NOTIFY_STATUS_MASK);
          /* Enable relevant interrupts */
          SchM_Exit_CanIf_RX_NOTIFSTATUS_PROTECTION();
          /* Set Rx notification to an upper layer */
          LenNotifStsType = CANIF_TX_RX_NOTIFICATION;
        } /*  if ((LpRxLpduNotify->ucDlcOrNotify & ... */
      } /* if (LucPdu == CANIF_TRUE) */
    } /* if ((uint8)E_OK == LenStdRetVal) */
  }/* if (E_OK == LenStdRetVal)*/
  return(LenNotifStsType);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_ReadRxPduData                                 **
**                                                                            **
** Service ID           : 0x06                                                **
**                                                                            **
** Description          : This service provides the CAN DLC and the received  **
**                        data of the requested CanRxPduId to the calling     **
**                        upper layer.                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : CanRxPduId                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : PduInfoPtr                                          **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : The CAN Interface must be initialized               **
**                                                                            **
** Remarks              : Global Variable(s):  CanIf_GblCanIfStatus,          **
**                                             aaRxBufferData                 **
**                                             CanIf_GaaRxLpduNotify,         **
**                                             CanIf_GaaController            **
**                        Function(s) invoked: Det_ReportError                **
**                                             SchM_Enter_CanIf_RX_DATA_      **
**                                             PROTECTION                     **
**                                             SchM_Exit_CanIf_RX_DATA_       **
**                                             PROTECTION                     **
*******************************************************************************/
#if (STD_ON == CANIF_READRXPDU_DATA_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData (
                      VAR(PduIdType, CANIF_VAR) CanRxPduId,
                      P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
{
  CanIf_RxLpduPCType LpRxLpdu;
  P2VAR(CanIf_Controller, AUTOMATIC, CANIF_VAR)LpController;
  P2VAR(CanIf_RxLpduNotify, AUTOMATIC, CANIF_VAR) LpRxLpduNotify;
  P2VAR (uint8, AUTOMATIC, CANIF_VAR) LpDataPtr;
  Std_ReturnType LenStdRetVal;
  uint8 LucDlc;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  uint8 LucNotifStatus;
  #endif
  uint8 LucPdu;
  uint16 LusRxPduCnt;
  LucPdu = CANIF_FALSE;
  LusRxPduCnt = CanIf_GddPrecompOpt.ddNumOfRxPdu;
  #if (STD_OFF == CANIF_DEV_ERROR_DETECT)
  LenStdRetVal = E_OK;
  #else
  /* Initialize standard return type to E_OK */
  LenStdRetVal = CANIF_ZERO;
  /* Report to DET, if module is not initialized */

  if ((boolean)CANIF_UNINITIALISED == CanIf_GblCanIfStatus)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                     CANIF_READ_RXPDU_DATA_SID, CANIF_E_UNINIT);
    LenStdRetVal++;
  }

  /* Report to DET, if RXPDUID is not in range */

  if (CanRxPduId >= CanIf_GddPrecompOpt.ddNumOfRxPdu)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                            CANIF_READ_RXPDU_DATA_SID, CANIF_E_INVALID_RXPDUID);
    LenStdRetVal++;
  }
  /* Report to DET, if PduInfopointer is a Null Pointer */

  if (PduInfoPtr == NULL_PTR)
  {
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                              CANIF_READ_RXPDU_DATA_SID, CANIF_E_PARAM_POINTER);
    LenStdRetVal++;
  }
  else
  {
    /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
    if (PduInfoPtr->SduDataPtr == NULL_PTR)
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                              CANIF_READ_RXPDU_DATA_SID, CANIF_E_PARAM_POINTER);
      LenStdRetVal++;
    }
  }
  if ((uint8)CANIF_ZERO == LenStdRetVal)
  #endif
  {
    /* Get the pointer to first Rx L-PDU of range/list type */
    #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
    LpRxLpdu = &CanIf_GaaRxLpduSelect[CANIF_ZERO];
    #else
    LpRxLpdu = &CanIf_GaaRxLpdu[CANIF_ZERO];
    #endif
    /* Get the RxNotifyId */
    do
    {
      /* #5139 */
      /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Configuration Index is generated value based on Ecudescription" */
      if (CanRxPduId != (PduIdType)LpRxLpdu->ddRxPduId)
      {
        LpRxLpdu++;
        LusRxPduCnt--;
      }
      else
      {
        #if (STD_ON == CANIF_DEV_ERROR_DETECT)
        LucNotifStatus = LpRxLpdu->ucRxUserOrNotifSts;
        /* Report to DET if Read data is not available for RxPDU*/
        /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
        if ((LucNotifStatus & CANIF_RX_DATA_STATUS_MASK) == CANIF_ZERO)
        {
          (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                            CANIF_READ_RXPDU_DATA_SID, CANIF_E_INVALID_RXPDUID);

          LenStdRetVal++;
        }




        #endif
        LucPdu = CANIF_TRUE;
      }
    }while((LucPdu != CANIF_TRUE) && (LusRxPduCnt != CANIF_ZERO));

    #if (STD_ON == CANIF_DEV_ERROR_DETECT)
    /* Check whether any development error are detected */
    /* polyspace +1 MISRA-C3:14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
    if ((uint8)CANIF_ZERO == LenStdRetVal)
    #endif
    {
      if (LucPdu == CANIF_TRUE)
      {
        /* Set the LenStdRetVal */
        LenStdRetVal = (Std_ReturnType)E_NOT_OK;
        /* Point to Controller */
        LpController =  &CanIf_GaaController[LpRxLpdu->ucControllerId];
        /* Check if controller mode is started */
        if ((uint8) CANIF_CS_STARTED == LpController->ucControllerMode)
        {
          /* Check ucRxStatus of controller */
          if (CANIF_RX_DISABLED != LpController->ucRxStatus)
          {
            /* Set the LenStdRetVal */
            LenStdRetVal = (Std_ReturnType)E_OK;
            /* Get the pointer to RxLpduNotify structure */
            /* polyspace +1 MISRA-C3:18.4 [Not a defect: Justified] "Decrement and Increment operator is used to achieve better throughput" */
            LpRxLpduNotify = &CanIf_GaaRxLpduNotify[CANIF_ZERO] +
                                                           LpRxLpdu->ddRxNotifyId;
            /* Get the DLC */
            LucDlc = ((LpRxLpduNotify->ucDlcOrNotify) &
                                                      (CANIF_RX_DLC_STATUS_MASK));
            /* Store Length */
            /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
            PduInfoPtr->SduLength = (uint8)LucDlc;
            /* Get the pointer to SduDataPtr */
            LpDataPtr = (PduInfoPtr->SduDataPtr);
            /* Disable relevant interrupts */
            SchM_Enter_CanIf_RX_DATA_PROTECTION();
            /* Loop to copy the data from BufferData to DataPtr */
            while ((uint8)CANIF_ZERO != LucDlc)
            {
              /* Decrement DLC counter */
              LucDlc--;
              /* Copy the data */
              /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
              LpDataPtr[LucDlc] = LpRxLpduNotify->aaRxBufferData[LucDlc];
              /* Increment buffer pointer by one */
            }
            /* Enable relevant interrupts */
            SchM_Exit_CanIf_RX_DATA_PROTECTION();
          }/* if (E_OK == LenStdRetVal) */
        }/* if ((uint8) CANIF_CS_STARTED == LpController->ucControllerMode) */
      } /* if (LucPdu == CANIF_TRUE) */
    }/* if (E_OK == LenStdRetVal) */
  }/* if (E_OK == LenStdRetVal)*/
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  else
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  #endif
  /* Return std return value */
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* #5139 */
/*******************************************************************************
** Function Name        : CanIf_RxData                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service provides the Rx Indication to the      **
**                        respective upper layers                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpRxLpdu, CanDlc                                    **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s): None                            **
**                                                                            **
**                        Function(s) invoked:None                            **
*******************************************************************************/
#if ((STD_ON == CANIF_RX_LPDU) && (STD_ON == CANIF_META_DATA_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_Uint8PCtype, CANIF_CODE) CanIf_RxData
  (Can_IdType CanId, uint8 CanDlc, CanIf_RxLpduPCType
    LpRxLpdu, P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr)
{
  Can_IdType LulCanId = CanId;
  static uint8 Lucdata[CANIF_TWELVE];
  uint8 LucMetadata[CANIF_FOUR];
  uint8 Luclength;
  uint8 LucPayLoadlength;
  uint32 LulRxCanIdMask;
  Luclength = CANIF_ZERO;
  LucPayLoadlength = CANIF_ZERO;

  LulRxCanIdMask = LpRxLpdu->ulCanIfRxPduCanIdMask;
  switch (LpRxLpdu->ucMetaDataLength)
  {
    case CANIF_ONE:
      LulCanId = LulCanId & LulRxCanIdMask;
      LulCanId = LulCanId & CANIF_CANID_MASK_ONE;
      LucMetadata[CANIF_ZERO] = (uint8)LulCanId;
      Lucdata[Luclength] = LucMetadata[CANIF_ZERO];
      Luclength++;
      break;

    case CANIF_TWO:
      LulCanId = LulCanId & LulRxCanIdMask;
      LulCanId = LulCanId & CANIF_CANID_MASK_TWO;
      LucMetadata[CANIF_ZERO] = (uint8)((LulCanId & CANIF_MASK_BYTE_ONE) >> CANIF_EIGHT);
      Lucdata[Luclength] = LucMetadata[CANIF_ZERO];
      Luclength++;
      LucMetadata[CANIF_ONE] = (uint8)(LulCanId & CANIF_CANID_MASK_ONE);
      Lucdata[Luclength] = LucMetadata[CANIF_ONE];
      Luclength++;
      break;

    case CANIF_FOUR:
      LulCanId = LulCanId & CANIF_CANID_MASK_FOUR;
      LucMetadata[CANIF_ZERO] = (uint8)((LulCanId & CANIF_MASK_BYTE_FOUR) >>
                                                              CANIF_TWENTY_FOUR);
      Lucdata[Luclength] = LucMetadata[CANIF_ZERO];
      Luclength++;
      LucMetadata[CANIF_ONE] = (uint8)((LulCanId & CANIF_MASK_BYTE_THREE) >> CANIF_SIXTEEN);
      Lucdata[Luclength] = LucMetadata[CANIF_ONE];
      Luclength++;
      LucMetadata[CANIF_TWO] = (uint8)((LulCanId & CANIF_MASK_BYTE_ONE) >> CANIF_EIGHT);
      Lucdata[Luclength] = LucMetadata[CANIF_TWO];
      Luclength++;
      LucMetadata[CANIF_THREE] = (uint8)(LulCanId & CANIF_CANID_MASK_ONE);
      Lucdata[Luclength] = LucMetadata[CANIF_THREE];
      Luclength++;
      break;

    default:
      /* empty */
      break;
  }
  /* polyspace-begin MISRA-C3:D4.14,18.1, RTE:OBAI [Not a defect: Justified] "It will not occur." */
  while(LucPayLoadlength < CanDlc)
  {
    Lucdata[Luclength] = CanSduPtr[LucPayLoadlength];
    LucPayLoadlength++;
    Luclength++;
  }
  /* polyspace-end MISRA-C3:D4.14,18.1, RTE:OBAI [Not a defect: Justified] "It will not occur." */
  return Lucdata;
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : CanIf_BinarySearch                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is used to implement the Binary       **
**                        search                                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpHrh, LddSize, LddCanId                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : LpRxLpdu                                            **
**                                                                            **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked:                                **
**                        None                                                **
*******************************************************************************/
#if (STD_ON == CANIF_RX_BASIC_CAN_SUPPORT)
#if ((STD_ON == CANIF_BINARY_SEARCH)||(STD_ON == CANIF_IDTABLE_SEARCH))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_RxLpduPCType, CANIF_CODE)
                         CanIf_BinarySearch (
                         CanIf_RxLpduPCType LpRxLpdu,
                         VAR(PduIdType, CANIF_VAR) LddSize,
                         VAR(Can_IdType, CANIF_VAR) LddCanId)
{
  CanIf_RxLpduPCType LpRxLpduRetVal;
  VAR(Can_IdType, CANIF_VAR) LddListCanId;
  VAR(PduIdType, CANIF_VAR) LddLow;
  VAR(PduIdType, CANIF_VAR) LddHigh;
  VAR(PduIdType, CANIF_VAR) LddMid;

  /* Initialize LddHigh variable with number of List L-PDUs - 1 */
  LddHigh = LddSize - (PduIdType)CANIF_ONE;
  /* Initialize LddLow variable with zero */
  LddLow = (PduIdType)CANIF_ONE;
  /* Initialize return value with null pointer */
  LpRxLpduRetVal = NULL_PTR;
  /* Get the lower limit of CAN-ID */
  /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
  LddListCanId = (LpRxLpdu->ddCanIdLl);
  /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Array Indexing is not used to achieve better throughput. */

  /* Check whether search CAN-ID is in range */
  if ((LddCanId >= LddListCanId) &&
  /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
  (LddCanId <= (Can_IdType)(LpRxLpdu[LddHigh].ddCanIdLl)))
  {
    
    /* Check whether requested CAN-ID is same as first CAN-ID of the list */
    if ((LddCanId & (LpRxLpdu->ulCanIfRxPduCanIdMask)) !=
        (LddListCanId & (LpRxLpdu->ulCanIfRxPduCanIdMask)))
    {
      do
      {
        /* Get the middle index number */
        LddMid = (LddHigh + LddLow) >> (PduIdType)CANIF_ONE;

        /* Get the CAN-ID of the mid Rx L-PDU */
        /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
        LddListCanId = (Can_IdType)(LpRxLpdu[LddMid].ddCanIdLl);
        /* Compare CAN-ID with the requested one */
        if ((LddCanId & (LpRxLpdu[LddMid].ulCanIfRxPduCanIdMask)) ==
            (LddListCanId & (LpRxLpdu[LddMid].ulCanIfRxPduCanIdMask)))
        {
          /* Update the return pointer with the Rx L-PDU structure */
          LpRxLpduRetVal = (P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST))(&LpRxLpdu[LddMid]);
          /* Set LddHigh to zero to break the loop */
          LddHigh = (PduIdType)CANIF_ZERO;
        }
        else
        {
          /* Compare the CAN-ID with the requested one */
          if (LddCanId < LddListCanId)
          {
            /* If the priority is lower, update LddHigh */
            /* polyspace +1 DEFECT:SIGN_CHANGE [Not a defect: Justified] "Overflow will not occur" */
            if((PduIdType)CANIF_ZERO != LddMid)
            {
              LddHigh = LddMid - (PduIdType)CANIF_ONE;
            }
          }
          else
          {
            /* If the priority is higher, update LddLow */
            LddLow = LddMid + (PduIdType)CANIF_ONE;
          }
        }
      }while (LddLow <= LddHigh);
    } /* if (LddCanId != LddListCanId) */
    else
    {
      /* Update the return pointer with the actual Rx L-PDU structure */
      LpRxLpduRetVal = LpRxLpdu;
    }
  } /* if (LddListCanId != LddCanId) */
  /* Return RxLpduRetVal pointer */
  /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Array Indexing is not used to achieve better throughput. */
  return (LpRxLpduRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : CanIf_TriggerSWFilter                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is triggerred to do the software      **
**                        filtering for the CanIds                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpHrh, CanId                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : LpRxLpdu                                            **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked:                                **
**                        None                                                **
*******************************************************************************/
#if (STD_ON == CANIF_RX_BASIC_CAN_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_RxLpduPCType, CANIF_CODE)
                          CanIf_TriggerSWFilter (
                          P2CONST(CanIf_Hrh, AUTOMATIC, CANIF_CONST) LpHrh,
                          VAR(Can_IdType, CANIF_VAR) CanId)
{
  CanIf_RxLpduPCType LpRxLpdu;
  VAR(PduIdType, CANIF_VAR) LddNoOfLpdus;
  VAR(Can_IdType, CANIF_VAR) LulCanId;
  #if ((STD_ON == CANIF_BINARY_SEARCH) || (STD_ON == CANIF_LINEAR_SEARCH))|| (STD_ON == CANIF_IDTABLE_SEARCH)
  VAR(uint8, CANIF_VAR) LucFilterStatus;
  #endif
  #if(STD_ON == CANIF_IDTABLE_SEARCH)
  VAR(uint8, CANIF_VAR) LucLdpuIdTableIndex;
  P2CONST(CanIf_RxLpduIdTable, AUTOMATIC, CANIF_CONST) LpRxLpduIdTable;
  #endif
  /* Get the pointer to first Rx L-PDU of range/list type */
  #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
  LpRxLpdu = &CanIf_GaaRxLpduSelect[LpHrh->ddRxLpduIndex];
  #else
  LpRxLpdu = &CanIf_GaaRxLpdu[LpHrh->ddRxLpduIndex];
  #endif
  #if ((STD_ON == CANIF_BINARY_SEARCH) || (STD_ON == CANIF_LINEAR_SEARCH))|| (STD_ON == CANIF_IDTABLE_SEARCH)
  /* Check the filter method for BASIC or FULL can*/
  LucFilterStatus = CANIF_FAILURE;
  #endif
  /* Get the number of ranges supported for that HRH */
  LddNoOfLpdus = LpHrh->ddNoOfRxLpdusRange;
  /* Get the can id */
  LulCanId = CanId;
  /* Check whether HRH is configured for range */
  while ((PduIdType)CANIF_ZERO != LddNoOfLpdus)
  {
    /* Check whether CAN-ID is in range */
    /* polyspace:begin CERT-C:MSC12-C [Not a defect:Justified] "Condition will be executed based on the configured values" */
    /* polyspace +2 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    if ((LulCanId >= LpRxLpdu->ddCanIdLl) && (LulCanId <= LpRxLpdu->ddCanIdUl))
    {
      #if ((STD_ON == CANIF_BINARY_SEARCH) || (STD_ON == CANIF_LINEAR_SEARCH)) || (STD_ON == CANIF_IDTABLE_SEARCH)
      /* Make software filtering successful (0x80) */
      LucFilterStatus = CANIF_RANGE_SUCCESS;
      #endif
      /* Break the loop */
      LddNoOfLpdus = (PduIdType)CANIF_ZERO;
    }
    else
    {
      /* Decrement the number of Tx L-PDU(s) */
      LddNoOfLpdus--;
      /* Increment the RxLpdu structure */
      /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment is used to achieve better throughput. */
      LpRxLpdu++;
    }
    /* polyspace:end CERT-C:MSC12-C [Not a defect:Justified] "Condition will be executed based on the configured values" */
  } /* while(LddNoOfLpdus != CANIF_ZERO);*/
  #if(STD_ON == CANIF_IDTABLE_SEARCH)
  /* Index Search Controller ID * 8(IP Table Number of each Controller) */
  LucLdpuIdTableIndex = ((LpRxLpdu->ucControllerId * CANIF_IPTABLE_COUNT)+((LulCanId & CANIF_STANDARD_ID_FIRSTBIT_MASK) >> CANIF_IPTABLE_COUNT));
  #endif
  #if ((STD_ON == CANIF_BINARY_SEARCH) || (STD_ON == CANIF_LINEAR_SEARCH)) || (STD_ON == CANIF_IDTABLE_SEARCH)
  /* Check whether id is found in range search */
  /* polyspace:begin CERT-C:MSC12-C [Not a defect: Justified] "Condition will be executed based on the configured values" */
  /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if (CANIF_FAILURE == LucFilterStatus)
  {
    #if(STD_ON == CANIF_IDTABLE_SEARCH)
    LpRxLpduIdTable = &CanIf_GaaRxLpduIdTable[LucLdpuIdTableIndex];
    /* Get the pointer to first Rx L-PDU of range/list type */
    #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
    LpRxLpdu = &CanIf_GaaRxLpduSelect[LpRxLpduIdTable->ddRxLpduIdTableIndex];
    #else
    LpRxLpdu = &CanIf_GaaRxLpdu[LpRxLpduIdTable->ddRxLpduIdTableIndex];
    #endif
    LddNoOfLpdus = LpRxLpduIdTable->ddNoOfRxLpdusRange;
    #else
    /* Get the number of List IDs from HRH structure */
    LddNoOfLpdus = LpHrh->ddNoOfRxLpdusList;
    #endif
    /* Check whether any list L-PDUs configured for that HRH */
    if ((PduIdType)CANIF_ZERO != LddNoOfLpdus)
    {
      /* Check filter method for that HRH*/
      #if (STD_ON == CANIF_BINARY_SEARCH) || (STD_ON == CANIF_IDTABLE_SEARCH)
      /* Do the Binary Search */
      LpRxLpdu = CanIf_BinarySearch(LpRxLpdu, LddNoOfLpdus, LulCanId);
      #endif

      #if (STD_ON == CANIF_LINEAR_SEARCH)
      /* Linear Search */
      LpRxLpdu = CanIf_LinearSearch(LpRxLpdu, LddNoOfLpdus, LulCanId);
      #endif

    } /* if (LddNoOfLpdus != CANIF_ZERO) */
    else
    {
      /* Initialize value as null pointer */
      LpRxLpdu = NULL_PTR;
    }
  } /* if (CANIF_FAILURE == LucFilterStatus)  */
  /* polyspace:end CERT-C:MSC12-C [Not a defect: Justified] "Condition will be executed based on the configured values" */
  #endif /* #if ((STD_ON == CANIF_BINARY_SEARCH) ||(...)) */
  /* Check whether software check returns true */
  return (LpRxLpdu);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_LinearSearch                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is used to implement the liear search **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpHrh, LddSize, LddCanId                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : LpRxLpdu                                            **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked:                                **
**                        None                                                **
*******************************************************************************/
#if (STD_ON == CANIF_LINEAR_SEARCH)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_RxLpduPCType, CANIF_CODE)
                         CanIf_LinearSearch (
                         CanIf_RxLpduPCType LpRxLpdu,
                         VAR(PduIdType, CANIF_VAR) LddSize,
                         VAR(Can_IdType, CANIF_VAR) LddCanId)
{
  /* Copy LpRxLpdu to LpCpyRxLpdu */
  CanIf_RxLpduPCType LpCpyRxLpdu = LpRxLpdu;
  VAR(PduIdType, CANIF_VAR) LddCpySize = LddSize;

  VAR(boolean, CANIF_VAR) LblSearchValue;
  /* Initialize search value to false */
  LblSearchValue = CANIF_FALSE;
  /*Loop all the Rx L-PDUs for the requested CAN ID. */
  do
  {
    /* If the CAN-ID is found in database,
      >> set the flag
      >> break the loop
    */
    if (((LpCpyRxLpdu->ddCanIdLl) & (LpCpyRxLpdu->ulCanIfRxPduCanIdMask)) ==
        (LddCanId & (LpCpyRxLpdu->ulCanIfRxPduCanIdMask)))
    {
      /* Set search flag to true */
      LblSearchValue = CANIF_TRUE;
      /* Set LddCpySize to zero to break the loop */
      LddCpySize = (PduIdType)CANIF_ZERO;
    }
    else
    {
      /* MISRA Rule    : 17.4
         Message       : Increment or decrement operation performed on pointer.
         Reason        : Increment operator used to achieve better throughput.
         Verification  : However, part of the code is verified manually and it is not having any impact.
      */
      /* Increment Rx L-PDU structure */
      LpCpyRxLpdu++;
      /* Decrement the size */
      LddCpySize--;
    }
  }while (LddCpySize != (PduIdType)CANIF_ZERO);

  /* Check whether CAN-ID is found in database */
  if ((boolean)CANIF_FALSE == LblSearchValue)
  {
    /* Return the null pointer */
    LpCpyRxLpdu = NULL_PTR;
  }
  /* Return LpRxLpdu pointer */
  return (LpCpyRxLpdu);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_RxStatusUpdate                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is used for the updating the RxStatus **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpRxLpdu                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GaaRxLpduNotify           **
**                                                                            **
**                        Function(s) invoked:                                **
**                                        SchM_Enter_CanIf_RX_DATA_PROTECTION **
**                                        SchM_Exit_CanIf_RX_DATA_PROTECTION  **
**                                                                            **
*******************************************************************************/
#if ((STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API) || \
                                           (STD_ON == CANIF_READRXPDU_DATA_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_RxStatusUpdate (
                        CanIf_RxLpduPCType LpRxLpdu,
                        P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr)
{
  P2VAR(CanIf_RxLpduNotify, AUTOMATIC, CANIF_VAR) LpRxLpduNotify;
  VAR(PduIdType, CANIF_VAR) LddNotifyId;
  #if (STD_ON == CANIF_READRXPDU_DATA_API)
  VAR(uint8, CANIF_VAR) LucVar;
  #endif
  VAR(uint8, CANIF_VAR) CanDlc;
  CanDlc = (uint8)PduInfoPtr->SduLength;
  /* Get the notify structure id from RxLpdu structure */
  LddNotifyId = LpRxLpdu->ddRxNotifyId;
  /* Check the notification status mask */
  LpRxLpduNotify = &CanIf_GaaRxLpduNotify[LddNotifyId];
  /* update the RxNotifSts with DLC and notification status */
  LpRxLpduNotify->ucDlcOrNotify = (CanDlc | CANIF_NOTIFY_STATUS_MASK);
  /*CANIF_NOTIFY_STATUS_MASK = 0x80*/
  #if (STD_ON == CANIF_READRXPDU_DATA_API)
  /* Get the pointer to RxLpduData pointer from RxLpduNotify
     structure CANIF_DATA_STATUS_MASK - 0X80 */
  if ((LpRxLpdu->ucRxUserOrNotifSts & CANIF_RX_DATA_STATUS_MASK) != CANIF_ZERO)
  {
    /* Assigned length to local variable */
    LucVar = CanDlc;
    /* Disable relevant interrupts */
    SchM_Enter_CanIf_RX_DATA_PROTECTION();
    /* Run Loop to copy the data as per DLC */
    while ((uint8)CANIF_ZERO != LucVar)
    {
      /* decrement the value of LucVar */
      LucVar--;
      /* polyspace +1 MISRA-C3:18.1, RTE:OBAI,IDP [Not a defect:Justified] "Configuration Index is generated value based on Ecudescription" */
      LpRxLpduNotify->aaRxBufferData[LucVar] = PduInfoPtr->SduDataPtr[LucVar];
    }
    /* Enable relevant interrupts */
    SchM_Exit_CanIf_RX_DATA_PROTECTION();
  } /*if ( LpRxLpduData != NULL_PTR) */
  #endif
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_ReadRxCanId                                 **
**                                                                            **
** Service ID           : none                                                **
**                                                                            **
** Description          : This service provides the actual value of           **
**                        CAN identifier received                             **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : none                                                **
**                                                                            **
** Output Parameters    : Can_IdType *CanIdPtr                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialized               **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        For post-build and pre-compile Implementation:      **
**                        CanIf_GddRxCanId                                    **
**                                                                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                                                        f                   **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void,CANIF_CODE) CanIf_ReadRxCanId
    (P2VAR(Can_IdType, AUTOMATIC, CANIF_APPL_DATA) CanIdPtr)
{
  if(CanIdPtr != NULL_PTR)
  {
    /* Copy CAN message identifier value */
		/* polyspace +1 MISRA-C3:D4.14,18.1 [Not a defect:Justified] "Array index in range" */
    *CanIdPtr = CanIf_GddRxCanId;
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
