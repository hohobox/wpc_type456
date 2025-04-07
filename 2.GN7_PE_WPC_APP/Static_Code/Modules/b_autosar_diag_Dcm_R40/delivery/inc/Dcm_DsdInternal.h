/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DsdInternal.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service IDs     **
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
** 2.6.1.0   13-Jan-2023   DanhTQ1         #38699                             **
**                                                                            **
** 2.5.1.0   12-Aug-2020   LanhLT         Fix UNECE #35929                    **
**                                                                            **
** 2.3.2.0   05-Nov-2020   EunKyung Kim   #26432                              **
**                                                                            **
** 1.0.3     09-11-2018    Y.S     Jeon   #13923                              **
**                                                                            **
** 1.0.2     10-08-2015    Youngjin Yun   #2977                               **
**                                                                            **
** 1.0.1     16-04-2015    Sungeol Baek   #2171                               **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSDINTERNAL_H
#define DCM_DSDINTERNAL_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
 
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"
 /* To SID index   */
extern FUNC(uint8, DCM_CODE)  Dcm_DsdSIdIndex(uint8  aServiceID);

 /* To provide indications  */
extern FUNC(boolean, DCM_CODE)Dcm_DsdIndication
  (PduIdType LddRxPduId, boolean LblStopProtocol, boolean LblPerTransmission,
    boolean LblROETransmission);

/* To provide confirmation  */
extern FUNC(void, DCM_CODE) Dcm_DsdConfirmation
                                       (NotifResultType LddResult);

/* Get Pdu ID */
extern FUNC(uint8,  DCM_CODE)  Dcm_GetProtocolIDIndex(uint8  aProtocolID);

extern 
boolean  Dcm_DsdValidateSecurity(
  P2CONST(uint8,  AUTOMATIC,  DCM_APPL_CONST) pSecurityLevelTable,
  uint8  numOfSecurityLevelEntry);  
  
extern FUNC(uint32, DCM_CODE) Dcm_DsdInternal_GetBufferSize(PduIdType PduId);
  
extern boolean Dcm_DsdValidateSession(
P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST)LpSesLevel, uint8 LucNoOfSes);


#if(DCM_MODE_RULE  ==  STD_ON)
extern FUNC(uint8, DCM_CODE) Dcm_DsdGetSubServiceModeRuleIndex(
  P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST)LpSubService,
                                     uint8 LucSubfucCount, uint8 LucSubfucion);
#endif

extern boolean Dcm_DsdModeConditionCheck(uint8 LucModeRuleIndex);

extern boolean  Dcm_DsdModeRuleCheck(Dcm_ModeType  LucModeRuleIndex);


/*******************************************************************************
**                     Response completion handling                           **
*******************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_ExternalSetNegResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  Dcm_NegativeResponseCodeType ErrorCode);

extern FUNC(void, DCM_CODE) Dcm_ExternalProcessingDone
          (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_InternalSetNegResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  Dcm_NegativeResponseCodeType ErrorCode);
  
extern FUNC(void, DCM_CODE) Dcm_InternalProcessingDone(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  boolean IsSync);

/*******************************************************************************
**                       Paged transmission handling                          **
*******************************************************************************/

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DsdStartPagedProcessing
             (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DsdProcessPage(Dcm_MsgLenType FilledPageLen);
#endif

extern FUNC(void, DCM_CODE) Dcm_DsdCancelOperation(void);

extern FUNC(Dcm_MsgType, DCM_CODE) 
Dcm_DsdInternal_GetMsgTxBuffer(
  PduIdType aPduId,
  Dcm_BufferKindType aBufferKind
);

/*******************************************************************************
**                       Request Dispatcher                                   **
*******************************************************************************/
extern FUNC(void, DCM_CODE) Dcm_DiagnosticSerivceDispatch(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_RequestContextType, AUTOMATIC, DCM_APPL_DATA) requestContext);  

/*******************************************************************************
**                     Message context                                        **
*******************************************************************************/ 
extern FUNC(Dcm_BufferConfig_Ptr, DCM_CODE) 
  Dcm_DsdInternal_GetBuffferConfig(PduIdType DcmRxPduId);
  
extern FUNC(Dcm_ProtocolConfig_Ptr, DCM_CODE) Dcm_DsdInternal_GetProcotocolByRxPduId(
  PduIdType DcmRxPduId);

extern  FUNC(Dcm_RequestContextType_Ptr, DCM_CODE) 
  Dcm_DsdInternal_GetRequestContextByRxPduId(PduIdType DcmRxPduId);
  
extern FUNC(Dcm_SubServiceIdConfigType_Ptr, DCM_CODE) 
  Dcm_DsdInternal_GetSubFunctionByMsgContext(P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(Dcm_DiagSessionConfigType_Ptr, DCM_CODE) 
Dcm_DsdInternal_GetSessionCfg(
  P2CONST(Dcm_ProtocolConfig, AUTOMATIC, DCM_APPL_CONST) protocolCfg,
  Dcm_SesCtrlType requestSession,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) outSessionIndex); 

FUNC(void, DCM_CODE) Dcm_DsdInternal_InitRequestContext(void);
 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
 
#endif /* DCM_DSDINTERNAL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
