/*******************************************************************************
**  (C) 2022 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Authentication.c                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Communication Manager Module              **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision     Date            By           Description                      **
********************************************************************************
** 2.16.0.0     30-Apr-2025     Jihye Lee    #CP44STD-1072                    **
**                                                                            **
** 2.14.0.0     30-Sep-2024     JHHong       #48435, #48101                   **
**                                                                            **
** 2.13.0.0     11-Jul-2024     JHHong       #46662                   		  **
**                                                                            **
** 2.11.1.0     16-Apr-2024     JHHong       #45144, #44551                   **
**                                                                            **
** 2.8.0.0      15-Nov-2023     Suyon Kim    #43348                           **
**                                                                            **
** 2.7.0        25-Jul-2022     Suyon Kim    #40261                           **
**                                                                            **
** 2.6.2        19-Apr-2023     LanhLT       #1493                            **
**                                                                            **
** 2.6.0        30-Sep-2022     LanhLT       Initial Version                  **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_Authentication.h"
#include "Dcm_PCTypes.h"
#include "Dcm_Ram.h"
#include "Dcm_DsdInternal.h"
#include "Dcm_CallOuts.h"

#if ((DCM_AUTHENTICATION_SUPPORT == STD_ON) && (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF))
#include "KeyM.h"
#endif

#include "Dcm_KeyM.h"
#include "Dcm_Csm.h"

#if(DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                     Types and Variables definition                         **
*******************************************************************************/
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)

#define DCM_AUTHENTICATION_STATE_READOUT_TIME (3 * DCM_TASK_TIME)
#define DCM_AUTHENTICATION_STATE_WRITEOUT_TIME (3 * DCM_TASK_TIME)

#define DCM_GENERAL_NRC (Dcm_AuthenticationConfig.GeneralNrc)
#define DCM_NVM_BLOCK_ID (Dcm_AuthenticationConfig.PersistStateNvMBlockId)
#define DCM_RAM_DATA_BLOCK (Dcm_GaaAuthenticationElementData)

#define DCM_UDS_SERVICE_ID_RANGE_LOW (0x10)
#define DCM_UDS_SERVICE_ID_AUTHENTICATION (0x29)

#define DCM_SUPPORT_COMUNICATION_CONFIGURATION (0x00)
#define DCM_AUTHENTICATION_DATA_MIN_LENGTH (0x0000)
#define DCM_AUTHENTICATION_UNIDIRECTION_DATA_MIN_LENGTH (0x0007u)
#define DCM_AUTHENTICATION_PROOFOFOWNER_DATA_MIN_LENGTH (0x0006u)

/*AuthenticationReturnParameter*/
#define DCM_AUTHENTICATION_CONFIGURATION_APCE (0x02)
#define DCM_DE_AUTHENTICATION_SUCCESSFUL (0x10)
#define DCM_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSERY (0x11)
#define DCM_OWNERSHIPVERIFIED_AUTHENTICATIONCOMPLETE  (0x12)

#define DCM_DEFAULT_ASYNC_JOBID (0xFFFF)

/*Macros for Authentication Timer*/
#define DCM_AUTHENTICATION_DEFAULT_SESSION_TIMER                     ((uint8)0)
#define DCM_PERSIST_AUTHENTICATION_STATE_TIMER                       ((uint8)1)
#define DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER                   ((uint8)2)
#define TIMER_MAX_NUM                                                ((uint8)3)

enum {
  DE_AUTHENTICATE
  , VERIFY_CERTIFICATE_UNIDIRECTIONAL
  , VERIFY_CERTIFICATE_BIDIRECTIONAL
  , PROOF_OF_OWNERSHIP
  , TRANSMIT_CERTIFICATE
  , REQUEST_CHALLENGE_FOR_AUTHENTICATION
  , VERIFY_PROOF_OF_OWNERSHIP_UNIDIRECTIONAL
  , VERIFY_PROOF_OF_OWNERSHIP_BIDIRECTIONAL
  , AUTHENTICATION_CONFIGURATION
  , SUBFUNCTION_MAX_NUM
};

typedef P2FUNC(void, DCM_CODE, Dcm_AuthenTimerCallbackFunType)(void);

typedef struct
{
  boolean StartFlag;
  uint16 Time;
  Dcm_AuthenTimerCallbackFunType PendingCbk;
  Dcm_AuthenTimerCallbackFunType TimeoutCbk;
} Dcm_AuthenTimerInfoType;

typedef P2VAR(Dcm_AuthenTimerInfoType, AUTOMATIC, DCM_APPL_DATA) Dcm_AuthenTimerInfoPtrType;

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_DiagnosticServiceFunType) (
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);


typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_AuthProcessingFuncType) (
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static VAR(Dcm_AuthenticationConnectionESInfoType, DCM_VAR) Dcm_GaaAuthenConnectionESInfo
  [DCM_AUTHENTICATION_CONNECTION_ES_NUM];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#else 
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* SWS_Dcm_01477 SWS_Dcm_01479 */
VAR(Dcm_AuthenticationConnectionInfoType, DCM_VAR) Dcm_GaaAuthenConnectionInfo
  [DCM_AUTHENTICATION_CONNECTION_NUM];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static VAR(Dcm_AuthenTimerInfoType, DCM_VAR) Dcm_GaaAuthenticationTimer[TIMER_MAX_NUM];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Static Functions Declaration                          **
*******************************************************************************/
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"

static FUNC(Dcm_DiagnosticServiceFunType, DCM_CODE) Dcm_GetAuthenServiceFunPtr(
  P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pSubServiceCfg);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessDeAuthenticate(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessAuthenticationConfiguration(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessNotSupport(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(boolean, DCM_CODE) Dcm_IsServiceBypassAuthenticationCheck(
  Dcm_ServiceIdConfigType_Ptr pServiceCfg);

static FUNC(boolean, DCM_CODE) Dcm_VerifyAuthenticationRole(
  Dcm_AuthenticationRoleType AssignedRole
  , Dcm_AuthenticationRoleType ProvidedRole);

static FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLServices(void);

static FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLSubServices(void);

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
static FUNC(void, DCM_CODE) Dcm_AuthenticationESPendingProcessing(  
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#else
static FUNC(void, DCM_CODE) Dcm_CheckTargetIdModeRule(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

static FUNC(void, DCM_CODE) Dcm_CheckGeneralNrcModeRule(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

static FUNC(void, DCM_CODE) Dcm_ResetAuthenticationElement(
  Dcm_AuthenticationElementPtrType pAuthEle);

static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementRole(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg);

static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLServices(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg);

static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLDid(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg);

static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLMemorySelection(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg);

static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLRid(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg);

static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWhiteList(
  KeyM_CertificateIdType CertId
  , Dcm_AuthenticationElementPtrType pAuthEle
  , uint32 WLMaxSize);
#endif

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessVerifyCertificateUnidirectional(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(boolean, DCM_CODE) Dcm_ChkCommunicationConfiguration(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(boolean, DCM_CODE) Dcm_ChkLengthOfUnidirectional(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
static FUNC(void, DCM_CODE) Dcm_CanncelProofOfOwnerShipClientProcessing(void);

static FUNC(void, DCM_CODE) Dcm_CanncelUniDirectionalProcessing(void);

#else
static FUNC(boolean, DCM_CODE) Dcm_StoreCertificate(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_UniDirectionalInitial(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(boolean, DCM_CODE) Dcm_VerifyCertificate(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CreatingServerChallenge(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(void, DCM_CODE) Dcm_CanncelAsyncFuntionCall(void);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyProofofOwnerShipClient(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ChkCsm_SignatureVerify(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);  
#endif

static FUNC(void, DCM_CODE) Dcm_VerifyCertificateUnidirectionalSuccessfully(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessProofofOwnershipClient(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ChkProofofOwnerShipClientLength(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_OwnerShipVerificationSuccess(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)

#else
static FUNC(Dcm_AuthenticationProcessingStateType, DCM_CODE)
  Dcm_GetAuthProcessingState(void);

static FUNC(void, DCM_CODE) Dcm_SetAuthProcessingState(
  Dcm_AuthenticationProcessingStateType state);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_UniDirectionalResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_AuthentationNegativeResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_AuthenticationAsynWaitingCallBack(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessVerifyCertificateBidirectional(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyCertificateInitial(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_BiDirectionalInitial(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode); 

static FUNC(boolean, DCM_CODE) Dcm_ChkLengthOfBidirectional(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CreatingServerChallengeDone(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_SigningChallengeClient(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProvidingServerCertificate(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_BiDirectionalResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(void, DCM_CODE) Dcm_VerifyCertificateBidirectionalSuccessfully(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyTargetIdentification(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode);

static FUNC(void, DCM_CODE) Dcm_ResetAuthProcessingState(
Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo);

static FUNC(uint32, DCM_CODE) Dcm_AuthenticationGetAsyncJobId(
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo);

static FUNC(void, DCM_CODE) Dcm_AuthenticationSetAsyncJobId(
  uint32 JobId
  , Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo);

static FUNC(void, DCM_CODE) Dcm_MemClear(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pDest,
  uint32 Size);

#if ((DCM_DSP_AUTHENTICATION_WHITE_LIST_DID_CONFIGURED == STD_ON) \
     || (DCM_DSP_AUTHENTICATION_WHITE_LIST_RID_CONFIGURED == STD_ON))
static FUNC(boolean, DCM_CODE) Dcm_ExtendValidateAccessRightsWithWhiteList(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen
  , Dcm_AuthenticationElementPtrType pAuthEle);
#endif

#endif

static FUNC(void, DCM_CODE) Dcm_AuthenticationReProcessing(void);

static FUNC(uint16, DCM_CODE) Dcm_AuthenticationGet2ByteData(
  uint8 HighByte
  , uint8 LowByte);

static FUNC(uint8, DCM_CODE) Dcm_GetFirstByteFrom4ByteData(uint32 buffer);

static FUNC(uint8, DCM_CODE) Dcm_GetSecondByteFrom4ByteData(uint32 buffer);

static FUNC(uint8, DCM_CODE) Dcm_GetProtocolTypeIndex(uint8 ProtocolId);

static FUNC(void, DCM_CODE) Dcm_MemCopy(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pDest,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSrc,
  uint32 Size);

static FUNC(boolean, DCM_CODE) Dcm_MemCompare(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDest
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSrc
  , uint32 Size);

static FUNC(void, DCM_CODE) Dcm_StopTimer(uint8 Timer);

static FUNC(void, DCM_CODE) Dcm_StartTimerExt(
  uint8 Timer
  , uint16 Time
  , Dcm_AuthenTimerCallbackFunType PendingCbk
  , Dcm_AuthenTimerCallbackFunType TimeoutCbk);

static FUNC(void, DCM_CODE) Dcm_InitAuthenticationTimers(void);


#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)

#else
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
static CONST(Dcm_AuthProcessingFuncType, DCM_CONST) AuthDispatchTable[
  AUTHENTICAITON_PROCESSING_MAX_STATE] =
{
  Dcm_VerifyCertificateInitial
  , Dcm_VerifyCertificate
  , Dcm_AuthenticationAsynWaitingCallBack
  , Dcm_VerifyTargetIdentification
  , Dcm_CreatingServerChallenge
  , Dcm_AuthenticationAsynWaitingCallBack
  , Dcm_CreatingServerChallengeDone
  , Dcm_UniDirectionalResponse

  , Dcm_SigningChallengeClient
  , Dcm_AuthenticationAsynWaitingCallBack
  , Dcm_ProvidingServerCertificate
  , Dcm_BiDirectionalResponse

  , Dcm_ChkProofofOwnerShipClientLength
  , Dcm_VerifyProofofOwnerShipClient
  , Dcm_AuthenticationAsynWaitingCallBack
  , Dcm_ChkCsm_SignatureVerify
  , Dcm_OwnerShipVerificationSuccess
  , Dcm_AuthentationNegativeResponse
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif

/*******************************************************************************
**                              Function definition                           **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Dcm_InitAuthentication                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Initialize data for UDS Authentication Service      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pConfig                                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)
FUNC(void, DCM_CODE) Dcm_InitAuthentication(void)
{
  uint8 idx;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  for (idx = 0; idx < DCM_AUTHENTICATION_CONNECTION_ES_NUM; idx++)
  {
    Dcm_GaaAuthenConnectionESInfo[idx].State = DCM_DEAUTHENTICATED;
    Dcm_GaaAuthenConnectionESInfo[idx].ESProcessingState = AUTHENTICATION_IDLE;
    Dcm_MemCopy(Dcm_GaaAuthenConnectionESInfo[idx].Role, 
      DEAUTHENTICATED_ROLE, DCM_AUTHENTICATION_ROLE_SIZE);
  }
  #else
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo;

  for (idx = 0; idx < DCM_AUTHENTICATION_CONNECTION_NUM; idx++)
  {
    /* SWS_Dcm_01480 SWS_Dcm_01489 */
    pAuthConInfo = &Dcm_GaaAuthenConnectionInfo[idx];
    pAuthConInfo->State = DCM_DEAUTHENTICATED;

    Dcm_MemCopy(pAuthConInfo->Role, 
      DEAUTHENTICATED_ROLE, DCM_AUTHENTICATION_ROLE_SIZE);

    Dcm_ResetAuthProcessingState(pAuthConInfo);
  }
  #endif

  Dcm_InitAuthenticationTimers();
}
#endif

/*******************************************************************************
** Function Name        : Dcm_StartRestorePersistedAuthenticationState        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Start Restore Persisted Authentication State        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04077 SRS_Diag_04171 */
#if ((DCM_AUTHENTICATION_PERSIST_STATE_MODE_RULE == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON))
FUNC(void, DCM_CODE) Dcm_StartRestorePersistedAuthenticationState(void)
{
  Std_ReturnType RetVal;
  uint8 ModeRuleIndex = Dcm_AuthenticationConfig.PersistStateModeRuleIndex;
  if (DCM_E_POSITIVERESPONSE ==  Dcm_CheckModeRule(DCM_TRUE, ModeRuleIndex))
  {
    RetVal = NvM_ReadBlock(DCM_NVM_BLOCK_ID, DCM_RAM_DATA_BLOCK);
    if (E_OK == RetVal)
    {
      Dcm_StartTimerExt(
        DCM_PERSIST_AUTHENTICATION_STATE_TIMER
        , DCM_AUTHENTICATION_STATE_READOUT_TIME
        , Dcm_WaitRestorePersistedAuthenticationState
        , Dcm_CancelRestorePersistedAuthenticationState);
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_WaitRestorePersistedAuthenticationState         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Wait Restore Persisted Authentication State         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_WaitRestorePersistedAuthenticationState(void)
{
  NvM_RequestResultType ReqResult;
  uint8 idx;
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo;
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationElementPtrType pAuthEle;
  Std_ReturnType RetVal = NvM_GetErrorStatus(DCM_NVM_BLOCK_ID, &ReqResult);

  /* SWS_Dcm_01187 SWS_Dcm_01188 */
  if ((E_OK == RetVal) && (NVM_REQ_OK == ReqResult))
  {
    for (idx = 0; idx < DCM_AUTHENTICATION_CONNECTION_NUM; idx++)
    {
      pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[idx];
      pAuthEle = pAuthConCfg->pRole;

      if (0 == *(pAuthEle->pDataLen))
      {
        continue;
      }

      pAuthConInfo = &Dcm_GaaAuthenConnectionInfo[idx];
      pAuthConInfo->State = DCM_AUTHENTICATED;

      Dcm_MemCopy(pAuthConInfo->Role, 
        pAuthEle->pData, DCM_AUTHENTICATION_ROLE_SIZE);
    }

    Dcm_StopTimer(DCM_PERSIST_AUTHENTICATION_STATE_TIMER);
  }
}

/*******************************************************************************
** Function Name        : Dcm_CancelRestorePersistedAuthenticationState       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Cancel Restore Persisted Authentication State       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_CancelRestorePersistedAuthenticationState(void)
{
  NvM_CancelJobs(DCM_NVM_BLOCK_ID);
}

/*******************************************************************************
** Function Name        : Dcm_StartPersistAuthenticationState                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Start Persist Authentication State                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04077 */
FUNC(void, DCM_CODE) Dcm_StartPersistAuthenticationState(void)
{
  uint8 ModeRuleIndex = Dcm_AuthenticationConfig.PersistStateModeRuleIndex;

  if (DCM_E_POSITIVERESPONSE == Dcm_CheckModeRule(DCM_TRUE, ModeRuleIndex))
  {
    NvM_SetBlockLockStatus(DCM_NVM_BLOCK_ID, DCM_FALSE);
    Std_ReturnType RetVal = NvM_WriteBlock(DCM_NVM_BLOCK_ID, DCM_RAM_DATA_BLOCK);

    if (E_OK == RetVal)
    {
      Dcm_StartTimerExt(
        DCM_PERSIST_AUTHENTICATION_STATE_TIMER
        , DCM_AUTHENTICATION_STATE_WRITEOUT_TIME
        , Dcm_WaitPersistAuthenticationState
        , Dcm_CancelPersistAuthenticationState);
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_WaitPersistAuthenticationState                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Wait Persist Authentication State                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_WaitPersistAuthenticationState(void)
{
  NvM_RequestResultType ReqResult;
  Std_ReturnType RetVal = NvM_GetErrorStatus(DCM_NVM_BLOCK_ID, &ReqResult);

  /* SWS_Dcm_01189 */
  if ((E_OK == RetVal) && (NVM_REQ_OK == ReqResult))
  {
    NvM_SetBlockLockStatus(DCM_NVM_BLOCK_ID, DCM_TRUE);
    Dcm_StopTimer(DCM_PERSIST_AUTHENTICATION_STATE_TIMER);
  }
}

/*******************************************************************************
** Function Name        : Dcm_CancelPersistAuthenticationState                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Cancel Persist Authentication State                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_CancelPersistAuthenticationState(void)
{
  NvM_CancelJobs(DCM_NVM_BLOCK_ID);
  NvM_SetBlockLockStatus(DCM_NVM_BLOCK_ID, DCM_TRUE);
}
#endif /* (DCM_AUTHENTICATION_PERSIST_STATE_MODE_RULE == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON) */
/*******************************************************************************
** Function Name        : Dcm_TriggerTimerFallbackToDeauthenticatedState      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Trigger Timer Fallback To Deauthenticated State     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ChkStopVal                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04171 */
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)
FUNC(boolean, DCM_CODE) Dcm_TriggerTimerFallbackToDeauthenticatedState(boolean ChkStopVal)
{
  boolean RetVal = DCM_FALSE;

  #if (0 < DCM_AUTHENTICATION_DEFAULT_SESSION_TIMEOUT)
  if(ChkStopVal == DCM_FALSE){
    if (DCM_DEFAULT_SESSION != Dcm_GddCurrentSession)
    {
      Dcm_StopTimer(DCM_AUTHENTICATION_DEFAULT_SESSION_TIMER);
    }
    else
    {
      Dcm_StartTimerExt(
        DCM_AUTHENTICATION_DEFAULT_SESSION_TIMER
        , DCM_AUTHENTICATION_DEFAULT_SESSION_TIMEOUT
        , NULL_PTR
        , Dcm_FallbackToDeauthenticatedState);

      RetVal = DCM_TRUE;
    }
  }
  else{
    Dcm_StopTimer(DCM_AUTHENTICATION_DEFAULT_SESSION_TIMER);
  }

  #endif

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_FallbackToDeauthenticatedState                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fallback To Deauthenticated State                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_FallbackToDeauthenticatedState(void)
{
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    (void)Dcm_ResetToDeauthenticatedState(ConnectionId);
  }
}

/*******************************************************************************
** Function Name        : Dcm_ValidateServiceAccessRights                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate Service Access Rights                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pServiceCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01537 SWS_Dcm_01540 SWS_Dcm_01541 SWS_Dcm_01542 SWS_Dcm_01524 */
FUNC(boolean, DCM_CODE) Dcm_ValidateServiceAccessRights(
  P2CONST(Dcm_ServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pServiceCfg)
{
  boolean ChkVal = DCM_TRUE;
  if ((DCM_FALSE == Dcm_IsServiceBypassAuthenticationCheck(pServiceCfg))
      && (DCM_FALSE == pServiceCfg->blSubFunctionAvailable))
  {
    Dcm_AuthenticationRoleType AssignedRole;

    Dcm_MemCopy(AssignedRole, 
      pServiceCfg->ServiceRole, DCM_AUTHENTICATION_ROLE_SIZE);

    ChkVal = Dcm_ValidateAccessRights(AssignedRole);

    if (DCM_FALSE == ChkVal) 
    {
      ChkVal = Dcm_ValidateAccessRightsWithWLServices();
    }
  }

  return ChkVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateSubServiceAccessRights                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate Sub Service Access Rights                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pServiceCfg, pSubServiceCfg                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_ValidateSubServiceAccessRights(
  P2CONST(Dcm_ServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pServiceCfg
  , P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pSubServiceCfg)
{
  boolean ChkVal = DCM_TRUE;
  Dcm_AuthenticationRoleType AssignedRole;
  if (DCM_FALSE == Dcm_IsServiceBypassAuthenticationCheck(pServiceCfg))
  {
    Dcm_MemCopy(AssignedRole, 
      pSubServiceCfg->SubServiceRole, DCM_AUTHENTICATION_ROLE_SIZE);

    ChkVal = Dcm_ValidateAccessRights(AssignedRole);
 
    if (DCM_FALSE == ChkVal)
    {
      ChkVal = Dcm_ValidateAccessRightsWithWLSubServices();
    }
  }
  return ChkVal;
}
#endif /* DCM_AUTHENTICATION_SUPPORT == STD_ON */
/*******************************************************************************
** Function Name        : Dcm_IsValidCertificateElementCondition              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Is Valid Certificate Element Condition              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pModeCondCfg                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01119 */
#if ((DCM_MODE_CONDITION == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON))
FUNC(boolean, DCM_CODE) Dcm_IsValidCertificateElementCondition(
  Dcm_ModeConditionConfigConstPtrType pModeCondCfg)
{
  boolean ChkVal = DCM_FALSE;

  #if (DCM_AUTHENTICATION_TARGET_ID_MODE_RULE == STD_ON)
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  KeyM_CertificateIdType CertId;
  KeyM_CertElementIdType CertEleId;
  uint8 CertEleData[DCM_AUTHENTICATION_CERT_COMPARE_ELEMENT_MAX_LEN];
  uint32 CertEleDataLen = DCM_AUTHENTICATION_CERT_COMPARE_ELEMENT_MAX_LEN;
  Std_ReturnType Res;
  Dcm_ConditionType Condition;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if ((AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
      && (NULL_PTR != pModeCondCfg))
  {
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    CertId = pAuthConCfg->CertId;
    CertEleId = pAuthConCfg->CompareCertId;
  
    Res = KeyM_CertElementGet(
      CertId, CertEleId, CertEleData, &CertEleDataLen);

    Condition = pModeCondCfg->ConditionType;
    if ((E_OK == Res)
        && (pAuthConCfg->CompareDataLen == CertEleDataLen))
    {
      ChkVal =  Dcm_MemCompare(pAuthConCfg->pCompareData, 
          CertEleData, CertEleDataLen, Condition);
    }
  }
  #else
  DCM_UNUSED(pModeCondCfg);
  #endif

  return ChkVal;
}
#endif /* (DCM_MODE_CONDITION == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON) */

/*******************************************************************************
** Function Name        : Dcm_SetDeauthenticatedRole                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Sets a new role used in deauthenticated state       **
**                        for that connection. The set role is valid until    **
**                        the connection switches into authenticated state    **
**                        or the ECU is reset.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId, DeauthenticatedRole                   **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)
/* SWS_Dcm_91069 */
/* polyspace+4 MISRA-C3:8.13 [Justified:Low] "DeauthenticatedRole type is the prototype specified in the AUTOSAR specification. 
part of the code is verfied manually and it has no impact" */
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetDeauthenticatedRole(
  uint16 ConnectionId
  , Dcm_AuthenticationRoleType DeauthenticatedRole)
{
  boolean ChkVal;
  if (DCM_UNINITIALISED == Dcm_GblInitStatus)
  {
    DCM_REPORT_ERROR(DCM_SET_DEAUTHENTICATED_ROLE, DCM_E_UNINIT);
  }
  else
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  {
    Dcm_AuthenticationConnectionESInfoType AuthConESInfo;
    ChkVal = Dcm_GetAuthenticationConnectionESInfo(
      ConnectionId, &AuthConESInfo);

    if ((DCM_TRUE == ChkVal)
        && (DCM_DEAUTHENTICATED == AuthConESInfo.State))
    {
      Dcm_MemCopy(AuthConESInfo.Role, 
        DeauthenticatedRole, DCM_AUTHENTICATION_ROLE_SIZE);

      (void)Dcm_SetAuthenticationConnectionESInfo(ConnectionId, &AuthConESInfo);
    }
  }
  #else
  {
    Dcm_AuthenticationConnectionInfoType AuthConInfo;
    ChkVal = Dcm_GetAuthenticationConnectionInfo(
      ConnectionId, &AuthConInfo);

    /* SWS_Dcm_01486 SWS_Dcm_01487 SWS_Dcm_01488 */
    if ((DCM_TRUE == ChkVal)
        && (DCM_DEAUTHENTICATED == AuthConInfo.State))
    {
      Dcm_MemCopy(AuthConInfo.Role, 
        DeauthenticatedRole, DCM_AUTHENTICATION_ROLE_SIZE);

      (void)Dcm_SetAuthenticationConnectionInfo(ConnectionId, &AuthConInfo);
    }
  }
  #endif

  return E_OK;
}

/*******************************************************************************
** Function Name        : Dcm_DcmAuthentication                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main function to process UDS 0x29 service           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04230 SRS_Diag_04238 SRS_Diag_04240 */
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmAuthentication(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_OK;
  Dcm_DiagnosticServiceFunType pAuthenServiceFun;
  P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pSubServiceCfg;
  pSubServiceCfg = Dcm_DsdInternal_GetSubFunctionByMsgContext(pMsgContext);

  if (NULL_PTR == pSubServiceCfg)
  {
    Dcm_InternalSetNegResponse(pMsgContext, DCM_E_GENERALREJECT);
    Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
  }
  /* External diagnostic sub-service processing */
  else if (NULL_PTR != pSubServiceCfg->pSubServiceFnc)
  {
    RetVal = pSubServiceCfg->pSubServiceFnc(OpStatus, pMsgContext);
  }
  /* Internal diagnostic sub-service processing */
  else
  {
    pAuthenServiceFun = Dcm_GetAuthenServiceFunPtr(pSubServiceCfg);
    RetVal = pAuthenServiceFun(OpStatus, pMsgContext);

    /* this function added for User callout  */
    if ((DCM_E_POSITIVERESPONSE != Dcm_GddNegRespError) && (RetVal != E_OK))
    {
      Dcm_Authentication_User_CallOut(OpStatus, pMsgContext, &Dcm_GddNegRespError);
    }

  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateAccessRights                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate Access Rights                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : AssignedRole                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04233 */
FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRights(
  Dcm_AuthenticationRoleType AssignedRole)
{
  boolean RetVal = DCM_FALSE;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  Dcm_AuthenticationConnectionESInfoType AuthConInfo;
  boolean ChkVal = Dcm_GetAuthenticationConnectionESInfo(
    ConnectionId, &AuthConInfo);
  #else
  /* SWS_Dcm_01538 */
  Dcm_AuthenticationConnectionInfoType AuthConInfo;
  boolean ChkVal = Dcm_GetAuthenticationConnectionInfo(
    ConnectionId, &AuthConInfo);
  #endif

  if (DCM_TRUE == ChkVal)
  {
    RetVal = Dcm_VerifyAuthenticationRole(AssignedRole, AuthConInfo.Role);
  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_GetAuthenServiceFunPtr                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the process function according sub service      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pSubServiceCfg                                      **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_DiagnosticServiceFunType                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01559 SWS_Dcm_01551 */
static FUNC(Dcm_DiagnosticServiceFunType, DCM_CODE) Dcm_GetAuthenServiceFunPtr(
  P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pSubServiceCfg)
{
  uint8 Id = pSubServiceCfg->ucSubServiceId;
  Dcm_DiagnosticServiceFunType pServiceFun;

  Dcm_DiagnosticServiceFunType DispatchTable[SUBFUNCTION_MAX_NUM] =
  {
    /* 0x00 */ Dcm_ProcessDeAuthenticate
    /* 0x01 */ , Dcm_ProcessVerifyCertificateUnidirectional
    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    /* 0x02 */ , Dcm_ProcessNotSupport
    #else
    /* 0x02 */ , Dcm_ProcessVerifyCertificateBidirectional
    #endif
    /* 0x03 */ , Dcm_ProcessProofofOwnershipClient
    /* 0x04 */ , Dcm_ProcessNotSupport
    /* 0x05 */ , Dcm_ProcessNotSupport
    /* 0x06 */ , Dcm_ProcessNotSupport
    /* 0x07 */ , Dcm_ProcessNotSupport
    /* 0x08 */ , Dcm_ProcessAuthenticationConfiguration
  };

  pServiceFun = (Id < SUBFUNCTION_MAX_NUM) ?
    DispatchTable[Id] : Dcm_ProcessNotSupport;

  return pServiceFun;
}

/*******************************************************************************
** Function Name        : Dcm_ProcessDeAuthenticate                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main process function for sub function              **
**                        deAuthenticate                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04239 */
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessDeAuthenticate(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_OK;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable;
  uint16 ConnectionId;
  boolean IsAuthenticated = DCM_FALSE;

  if (1 != pMsgContext->reqDataLen)
  {
    Dcm_InternalSetNegResponse(pMsgContext, 
      DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);

    Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
  }
  else
  {
    /* SWS_Dcm_01561 */
    pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
    ConnectionId = pPduIdTable->usMainConnectionId ;
    IsAuthenticated = Dcm_IsAuthenticatedConnection(ConnectionId);

    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
    if (AuthConIdx != AUTHENTICATION_CONNECTION_ID_NOT_CONFIGURED)
    {
      if((Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucAuthenticationUsePort == USE_SYNCH_CLIENT_SERVER) ||
        (Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucAuthenticationUsePort == USE_SYNCH_FNC))
      {
        if(NULL_PTR != Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pDeauthenticationFailedFun)
        {
          RetVal = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pDeauthenticationFailedFun
          (pMsgContext, &Dcm_GddNegRespError);
        }
      }
      else if((Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucAuthenticationUsePort == USE_ASYNCH_CLIENT_SERVER) ||
          (Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucAuthenticationUsePort == USE_ASYNCH_FNC))
      {
        if (NULL_PTR != Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pAsyncDeauthenticationFailedFun)
        {
          RetVal = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pAsyncDeauthenticationFailedFun
          (pMsgContext, &Dcm_GddNegRespError);
        }
      }
      else
      {
        /* Nothing */
      }
    }
    else
    {
      /* Nothing */
    }
    #endif
    
    if ((DCM_E_POSITIVERESPONSE != Dcm_GddNegRespError) && (RetVal != E_OK))
    {
      Dcm_InternalSetNegResponse(pMsgContext, Dcm_GddNegRespError);
    }
    else
    {
      if (DCM_TRUE == IsAuthenticated)
      {
        (void)Dcm_ResetToDeauthenticatedState(ConnectionId);
      }

      pMsgContext->resDataLen = 2;
      pMsgContext->resData[0] = pMsgContext->reqData[0];

      /* SWS_Dcm_01565 */
      pMsgContext->resData[1] = DCM_DE_AUTHENTICATION_SUCCESSFUL;
    }
    Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
  }

  DCM_UNUSED(OpStatus);
  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ProcessAuthenticationConfiguration              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main process function for sub function              **
**                        authenticationConfiguration                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01533 */
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessAuthenticationConfiguration(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_OK;

  if (1 != pMsgContext->reqDataLen)
  {
    Dcm_InternalSetNegResponse(pMsgContext, 
      DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
  }
  else
  {
    if (DCM_E_POSITIVERESPONSE != Dcm_GddNegRespError)
    {
       Dcm_InternalSetNegResponse(pMsgContext, Dcm_GddNegRespError);
    }
    else
    {
      pMsgContext->resDataLen = 2;
      pMsgContext->resData[0] = pMsgContext->reqData[0];
      pMsgContext->resData[1] = DCM_AUTHENTICATION_CONFIGURATION_APCE;
    }
  }

  Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);

  DCM_UNUSED(OpStatus);
  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ProcessNotSupport                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main process function in case the sub function      **
**                        is not supported by Dcm module                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessNotSupport(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_OK;

  Dcm_InternalSetNegResponse(pMsgContext, DCM_E_SUBFUNCTIONNOTSUPPORTED);
  Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);

  DCM_UNUSED(OpStatus);
  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_IsServiceBypassAuthenticationCheck              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the service can be bypass                  **
**                        the authentication check or not                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : pServiceCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01536 SWS_Dcm_01558 */
static FUNC(boolean, DCM_CODE) Dcm_IsServiceBypassAuthenticationCheck(
  Dcm_ServiceIdConfigType_Ptr pServiceCfg)
{
  boolean ChkVal = DCM_FALSE;
  uint8 ServiceId = pServiceCfg->ucServiceId;

  if ((ServiceId < DCM_UDS_SERVICE_ID_RANGE_LOW)
      || (DCM_UDS_SERVICE_ID_AUTHENTICATION == ServiceId)
      || (DCM_TESTERPRESENT == ServiceId))
  {
    ChkVal = DCM_TRUE;
  }

  return ChkVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateAccessRightsWithWLDid                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate access rights with white list for did      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pData, DataLen                                      **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/

FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLDid(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen)
{
  boolean RetVal = DCM_FALSE;

  #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_DID_CONFIGURED == STD_ON)
  uint8 AuthConIdx;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  uint32 LulMaxLength;
  uint8 LucIndex;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) LpWL;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    /*WL DID fomat: DIDHighByte DIDLowByte AccessByte */
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
    LulMaxLength =  Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucWLDidSize;
    LpWL = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pWLDid;
    LucIndex = 0;

    while (LucIndex < LulMaxLength)
    {
      /* check 2 bytes DID */
      if (DCM_TRUE == Dcm_MemCompare(pData, LpWL, DCM_TWO))
      {
        /* check the access byte */
        if ((pData[DCM_TWO] & LpWL[DCM_TWO]) != 0U)
        {
          RetVal = DCM_TRUE;

          /*exit loop*/
          LucIndex = LulMaxLength;
        }
      }
      /* move to the next DID */
      LucIndex = LucIndex + 3;
      LpWL = &LpWL[LucIndex];
    }
  }
  DCM_UNUSED(DataLen);
  #else
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationElementPtrType pAuthEle;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];

    pAuthEle = pAuthConCfg->pWLDid;
    if (NULL_PTR != pAuthEle)
    {
      RetVal = Dcm_ExtendValidateAccessRightsWithWhiteList(
        pData, DataLen, pAuthEle);
    }
  }
  #endif /* DCM_AUTHENTICATION_ES_SUPPORT == STD_ON */
  #else
  DCM_UNUSED(pData);
  DCM_UNUSED(DataLen);
  #endif /* DCM_DSP_AUTHENTICATION_WHITE_LIST_DID_CONFIGURED == STD_ON */


  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateAccessRightsWithWLRid                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate access rights with white list for rid      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pData, DataLen                                      **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLRid(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen)
{
  boolean RetVal = DCM_FALSE;

  #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_RID_CONFIGURED == STD_ON)
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  uint8 AuthConIdx;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  uint32 LulMaxLength;
  uint8 LucIndex;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) LpWL;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    /*WL DID fomat: RIDHighByte RIDLowByte AccessByte */
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
    LulMaxLength =  Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucWLRidSize;
    LpWL = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pWLRid;
    LucIndex = 0;

    while (LucIndex < LulMaxLength)
    {
      /* check 2 bytes RID */
      if (DCM_TRUE == Dcm_MemCompare(pData, LpWL, DCM_TWO))
      {
        /* check the access byte */
        if ((pData[DCM_TWO] & LpWL[DCM_TWO]) != 0U)
        {
          RetVal = DCM_TRUE;

          /*exit loop*/
          LucIndex = LulMaxLength;
        }
      }
      /* move to the next DID */
      LucIndex = LucIndex + 3;
      LpWL = &LpWL[LucIndex];
    }
  }
  DCM_UNUSED(DataLen);
  #else
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationElementPtrType pAuthEle;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    pAuthEle = pAuthConCfg->pWLRid;

    if (NULL_PTR != pAuthEle)
    {
      RetVal = Dcm_ExtendValidateAccessRightsWithWhiteList(
        pData, DataLen, pAuthEle);
    }
  }
  #endif /* DCM_AUTHENTICATION_ES_SUPPORT == STD_ON */
  #else
  DCM_UNUSED(pData);
  DCM_UNUSED(DataLen);
  #endif /*DCM_DSP_AUTHENTICATION_WHITE_LIST_RID_CONFIGURED == STD_ON*/

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateAccessRightsWithWLMemorySelection       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate access rights with white list              **
**                        for memory selection of read dtc service            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pData, DataLen                                      **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLMemorySelection(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen)
{
  boolean RetVal = DCM_FALSE;

  #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_MEMORY_SELECTION_CONFIGURED == STD_ON)
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  uint8 AuthConIdx;
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationElementPtrType pAuthEle;
  uint8 idx;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    pAuthEle = pAuthConCfg->pWLMemorySelection;
    if (NULL_PTR != pAuthEle)
    {
        for (idx = 0; idx < DCM_AUTHENTICATION_WHITE_LIST_MEMORY_SELECTION_MAX_SIZE; idx++)
        {
            /* Checks on service 0x19 parameter MemorySelection */
          if (pData[0] == pAuthEle->pData[idx])
          {
            RetVal = DCM_TRUE;
            break;
          }
        }

    }
  }
  #else
  DCM_UNUSED(pData);
  DCM_UNUSED(DataLen);
  #endif

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_IsAuthenticatedConnection                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the connection is authenticated or not     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_IsAuthenticatedConnection(
  uint16 ConnectionId)
{
  boolean RetVal = DCM_FALSE;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  uint8 AuthenticationIdIndex;
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    if ((Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].State == DCM_AUTHENTICATED)||\
      (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState != AUTHENTICATION_IDLE))
    {
      RetVal = DCM_TRUE;
    }
  }
  #else
  Dcm_AuthenticationConnectionInfoType AuthConInfo;
  boolean ChkVal = Dcm_GetAuthenticationConnectionInfo(
    ConnectionId, &AuthConInfo);

  if ((DCM_TRUE == ChkVal)
      && (DCM_AUTHENTICATED == AuthConInfo.State))
  {
    RetVal = DCM_TRUE;
  }
  #endif

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_GetAuthConnectionIndex                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the configuration index of authentication       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
FUNC(uint8, DCM_CODE) Dcm_GetAuthConnectionIndex(
  uint16 ConnectionId)
{
  uint8 idx;
  uint8 AuthConIdx = AUTHENTICATION_CONNECTION_ID_NOT_CONFIGURED;

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  for (idx = 0; idx < DCM_AUTHENTICATION_CONNECTION_ES_NUM; idx++)
  {
    if (ConnectionId == Dcm_GaaAuthenticationConnectionESConfig[idx].usConnectionId)
    {
      AuthConIdx = idx;
      break;
    }
  }
  #else
  for (idx = 0; idx < DCM_AUTHENTICATION_CONNECTION_NUM; idx++)
  {
    if (ConnectionId == Dcm_GaaAuthConnectionIds[idx])
    {
      AuthConIdx = idx;
      break;
    }
  }
  #endif

  return AuthConIdx;
}

/*******************************************************************************
** Function Name        : Dcm_GetAuthenticationConnectionInfo                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get Authentication Connection Information           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pAuthConInfo                                        **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
FUNC(boolean, DCM_CODE) Dcm_GetAuthenticationConnectionInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo)
{
  boolean RetVal = DCM_FALSE;
  Dcm_AuthenticationConnectionInfoPtrType pMyAuthConInfo;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    pMyAuthConInfo = &Dcm_GaaAuthenConnectionInfo[AuthConIdx];
    pAuthConInfo->State = pMyAuthConInfo->State;

    Dcm_MemCopy(pAuthConInfo->Role, 
      pMyAuthConInfo->Role, DCM_AUTHENTICATION_ROLE_SIZE);

    RetVal = DCM_TRUE;
  }

  return RetVal;
}
  #endif

/*******************************************************************************
** Function Name        : Dcm_SetAuthenticationConnectionInfo                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set Authentication Connection Information           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId, pAuthConInfo                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
FUNC(boolean, DCM_CODE) Dcm_SetAuthenticationConnectionInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionInfoConstPtrType pAuthConInfo)
{
  boolean RetVal = DCM_FALSE;
  Dcm_AuthenticationConnectionInfoPtrType pMyAuthConInfo;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    pMyAuthConInfo = &Dcm_GaaAuthenConnectionInfo[AuthConIdx];
    pMyAuthConInfo->State = pAuthConInfo->State;

    Dcm_MemCopy(pMyAuthConInfo->Role, 
      pAuthConInfo->Role, DCM_AUTHENTICATION_ROLE_SIZE);

    RetVal = DCM_TRUE;
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ResetToDeauthenticatedState                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Reset To Deauthenticated State                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01485 SRS_Diag_04239 */
FUNC(boolean, DCM_CODE) Dcm_ResetToDeauthenticatedState(
  uint16 ConnectionId)
{
  boolean RetVal = DCM_FALSE;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    Dcm_GaaAuthenConnectionESInfo[AuthConIdx].State = DCM_DEAUTHENTICATED;
    Dcm_GaaAuthenConnectionESInfo[AuthConIdx].ESProcessingState = AUTHENTICATION_IDLE;
    
    Dcm_MemCopy(Dcm_GaaAuthenConnectionESInfo[AuthConIdx].Role, 
      DEAUTHENTICATED_ROLE, DCM_AUTHENTICATION_ROLE_SIZE);

    (void)Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pSchMSwitchAuthenticationStateFun
      (DCM_DEAUTHENTICATED);

    RetVal = DCM_TRUE;
  }

  #else
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo;
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    pAuthConInfo = &Dcm_GaaAuthenConnectionInfo[AuthConIdx];
    pAuthConInfo->State = DCM_DEAUTHENTICATED;

    Dcm_MemCopy(pAuthConInfo->Role, 
      DEAUTHENTICATED_ROLE, DCM_AUTHENTICATION_ROLE_SIZE);

    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];

    (void)pAuthConCfg->pSchMSwitchAuthenticationStateFun(DCM_DEAUTHENTICATED);

    Dcm_ResetAuthenticationElement(pAuthConCfg->pRole);
    Dcm_ResetAuthenticationElement(pAuthConCfg->pWLServices);

    #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_DID_CONFIGURED == STD_ON)
    Dcm_ResetAuthenticationElement(pAuthConCfg->pWLDid);
    #endif

    #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_MEMORY_SELECTION_CONFIGURED == STD_ON)
    Dcm_ResetAuthenticationElement(pAuthConCfg->pWLMemorySelection);
    #endif

    #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_RID_CONFIGURED == STD_ON)
    Dcm_ResetAuthenticationElement(pAuthConCfg->pWLRid);
    #endif

    /* SWS_Dcm_01484 */
    #if (DCM_AUTHENTICATION_PERSIST_STATE_MODE_RULE == STD_ON)
    Dcm_StartPersistAuthenticationState();
    #endif

    Dcm_ResetAuthProcessingState(pAuthConInfo);

    RetVal = DCM_TRUE;
  }
  #endif

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_TransitIntoAuthenticatedState                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Transit Into Authenticated State                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConnectionId                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01528 SWS_Dcm_01531 SWS_Dcm_01532 */
FUNC(boolean, DCM_CODE) Dcm_TransitIntoAuthenticatedState(
  uint16 ConnectionId)
{
  boolean RetVal = DCM_FALSE;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    Dcm_GaaAuthenConnectionESInfo[AuthConIdx].State = DCM_AUTHENTICATED;

    (void)Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pSchMSwitchAuthenticationStateFun
      (DCM_AUTHENTICATED);
    
    Dcm_MemCopy(Dcm_GaaAuthenConnectionESInfo[AuthConIdx].Role, 
      Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].AuthenticatedRole, 
      DCM_AUTHENTICATION_ROLE_SIZE);

    RetVal = DCM_TRUE;
  }
  #else
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];

    RetVal = Dcm_ReadAuthenticationElementRole(pAuthConCfg);

    /* SWS_Dcm_01516 SWS_Dcm_01517 */
    if (DCM_TRUE == RetVal)
    {
      RetVal = Dcm_ReadAuthenticationElementWLServices(pAuthConCfg);
    }

    if (DCM_TRUE == RetVal)
    {
      RetVal = Dcm_ReadAuthenticationElementWLDid(pAuthConCfg);
    }

    if (DCM_TRUE == RetVal)
    {
      RetVal = Dcm_ReadAuthenticationElementWLMemorySelection(pAuthConCfg);
    }

    if (DCM_TRUE == RetVal)
    {
      RetVal = Dcm_ReadAuthenticationElementWLRid(pAuthConCfg);
    }

    if (DCM_TRUE == RetVal)
    {
      pAuthConInfo = &Dcm_GaaAuthenConnectionInfo[AuthConIdx];
      pAuthConInfo->State = DCM_AUTHENTICATED;

      (void)pAuthConCfg->pSchMSwitchAuthenticationStateFun(DCM_AUTHENTICATED);

      /* SWS_Dcm_01514 */
      Dcm_MemCopy(pAuthConInfo->Role, 
        pAuthConCfg->pRole->pData, DCM_AUTHENTICATION_ROLE_SIZE);

      /* SWS_Dcm_01530 */
      #if (DCM_AUTHENTICATION_PERSIST_STATE_MODE_RULE == STD_ON)
      Dcm_StartPersistAuthenticationState();
      #endif
    }
  }
  #endif

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_VerifyAuthenticationRole                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the authentication role is accepted or not **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : AssignedRole, ProvidedRole                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01522 SWS_Dcm_01523 */
/* polyspace+4 MISRA-C3:8.13 [Justified:Low] "AssignedRole, ProvidedRole type are the prototype specified in the AUTOSAR specification. part of the code is verfied manually and it has no impact" */
static FUNC(boolean, DCM_CODE) Dcm_VerifyAuthenticationRole(
  Dcm_AuthenticationRoleType AssignedRole
  , Dcm_AuthenticationRoleType ProvidedRole)
{
  uint8 idx;
  boolean ChkVal = DCM_FALSE;

  for (idx = 0; idx < DCM_AUTHENTICATION_ROLE_SIZE; idx++)
  {
    /* 
       AssignedRole is configured in Authentication service
       ProvidedRole is configured in each service
       if role of the service is not configured , AssignedRole is generated as 0xFF.
    */
    if (0 < (AssignedRole[idx] & ProvidedRole[idx]))
    {
      ChkVal = DCM_TRUE;
      break;
    }
  }

  return ChkVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateAccessRightsWithWLServices              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate Access Rights With white list for services **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01562 */
static FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLServices(void)
{
  boolean RetVal = DCM_FALSE;

  uint8 AuthConIdx;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pReqData;
  uint8 RxBufferId;
  uint8 ProtocolIdx;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  #else
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationElementPtrType pAuthEle;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pElementData;
  uint32 element_length; // length of each element in while list
  #endif
  uint8 LucChkValue;
  uint32 element_MaxLen; // maximun length of pAuthEle->pData
  uint8 index_AuthEleData; // index of pAuthEle->pData;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  uint8 wlSID;
  LucChkValue = DCM_FALSE;

  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    LucChkValue = DCM_TRUE;
  }

  if (LucChkValue == DCM_TRUE)
  {
    LucChkValue = DCM_FALSE;

    RxBufferId = pPduIdTable->ucRxBufferId;
    ProtocolIdx = Dcm_GetProtocolTypeIndex(pPduIdTable->ddProtocolId);
    if (ProtocolIdx < DCM_NUM_OF_PROTOCOLCONFIG)
    {
      LucChkValue = DCM_TRUE;
    }
  }

  if (LucChkValue == DCM_TRUE)
  {
    LucChkValue = DCM_FALSE;

    pReqData = Dcm_GaaBufferConfig[RxBufferId].pBufferArea;
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
    #else
    if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
    #endif
    {
      LucChkValue = DCM_TRUE;
    }
  }

  if (LucChkValue == DCM_TRUE)
  {
    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    element_MaxLen = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucWLSidWithoutSubfuncSize;
    index_AuthEleData = 0;
    while (index_AuthEleData < element_MaxLen)
    {
      wlSID = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pWLSidsWithoutSubfunction[index_AuthEleData];
      if (*pReqData == wlSID)
      {
        RetVal = DCM_TRUE;
        
        // exit loop
        index_AuthEleData = (uint8)element_MaxLen;
      }
      else
      {
        index_AuthEleData++;
      }
    }
    #else
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    pAuthEle = pAuthConCfg->pWLServices;
    element_MaxLen = pAuthEle->DataMaxLen;
    index_AuthEleData = 0;

    while (index_AuthEleData < element_MaxLen)
    {
        /* point to the address of length for the next element*/
      element_length = (uint32)pAuthEle->pData[index_AuthEleData];
      if (element_length != 0) /* break check */
      {
        index_AuthEleData++;
        /* point to the address of data for the next element*/ 
        wlSID = pAuthEle->pData[index_AuthEleData];
        /*
          example: pAuthEle->pData = 01 85 02 11 01 03 22 12 3A 03 04 31 01 13 F4
            white list element 0 {length: 0x01, data: 0x85} 
            white list element 1 {length: 0x02, data: 0x11 0x01}
            white list element 2 {length: 0x03, data: 0x22 0x12 0x3A}
            white list element 3 {length: 0x04, data: 0x31 0x01 0x13 0xF4}

          Requested SID will be compared with byte 0 of each white list elements.
        */
        if ((wlSID == *pReqData) && (element_length == 1))
        {
          // requested Sid white list entry
          RetVal = DCM_TRUE;
          break;
        }

        index_AuthEleData += element_length; /* size of the data */
      }
      else
      {
        // exit loop
      index_AuthEleData = element_MaxLen;
      }
    }
    #endif
  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ValidateAccessRightsWithWLSubServices           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Validate Access Rights With white list for services **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLSubServices(void)
{
  boolean RetVal = DCM_FALSE;

  uint8 RxBufferId;
  uint8 ProtocolIdx;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pReqData;
  uint8 AuthConIdx;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON) 

  #else
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  Dcm_AuthenticationElementPtrType pAuthEle;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pElementData;
  uint8 isSubfunctionValidated;
  uint32 element_length; // length of each element in while list
  #endif
  uint32 element_MaxLen; // maximun length of pAuthEle->pData
  uint8 index_AuthEleData; // index of pAuthEle->pData;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId;
  uint8 LucChkValue;
  uint8 LucWLData;

  LucChkValue = DCM_FALSE;
  if (DCM_TRUE == Dcm_IsAuthenticatedConnection(ConnectionId))
  {
    LucChkValue = DCM_TRUE;
  }

  if (LucChkValue == DCM_TRUE)
  {
    LucChkValue = DCM_FALSE;
    RxBufferId = pPduIdTable->ucRxBufferId;
    ProtocolIdx = Dcm_GetProtocolTypeIndex(pPduIdTable->ddProtocolId);

    if (ProtocolIdx < DCM_NUM_OF_PROTOCOLCONFIG)
    {
      LucChkValue = DCM_TRUE;
    }
  }

  if (LucChkValue == DCM_TRUE)
  {
    LucChkValue = DCM_FALSE;
    pReqData = Dcm_GaaBufferConfig[RxBufferId].pBufferArea;
    AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
    #else
    if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
    #endif
    {
      LucChkValue = DCM_TRUE;
    }
  }

  if (LucChkValue == DCM_TRUE)
  {
    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    element_MaxLen = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].ucWLSidWithSubfuncSize;
    index_AuthEleData = 0;

    /*data format: SID SUB SID SUB SID SUB*/
    while (index_AuthEleData < element_MaxLen)
    {
      //check SID
      LucWLData = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pWLSidWithSubfunction[index_AuthEleData];
      if (pReqData[0] == LucWLData)
      {
        //check Subfunction
        index_AuthEleData++;
        LucWLData = Dcm_GaaAuthenticationConnectionESConfig[AuthConIdx].pWLSidWithSubfunction[index_AuthEleData];
        if (pReqData[1] == LucWLData)
        {
          RetVal = DCM_TRUE;

          //exit loop
          index_AuthEleData = (uint8)element_MaxLen;
        }
        else 
        {
          /* move to the next SID SUB */
          index_AuthEleData++;
        }
      }
      else
      {
        /*if SID is not matched, no need check subfunction */
        /* move to the next SID SUB */
        index_AuthEleData = index_AuthEleData + 2;
      }
    }
    #else
    isSubfunctionValidated = DCM_FALSE;
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    pAuthEle = pAuthConCfg->pWLServices;
    element_MaxLen = pAuthEle->DataMaxLen;
    index_AuthEleData = 0;

    while (index_AuthEleData < element_MaxLen)
    { /* point to the address of length for next element */
      element_length = (uint32)pAuthEle->pData[index_AuthEleData];
      if (element_length != 0)
      {
        index_AuthEleData++;
        /* point to the address of data for next element */
        pElementData = &pAuthEle->pData[index_AuthEleData];
        /*
          example: pAuthEle->pData = 01 85 02 11 01 03 22 12 3A 03 04 31 01 13 F4
            white list element 0 {length: 0x01, data: 0x85} 
            white list element 1 {length: 0x02, data: 0x11 0x01}   <== Target
            white list element 2 {length: 0x03, data: 0x22 0x12 0x3A}
            white list element 3 {length: 0x04, data: 0x31 0x01 0x13 0xF4}
            white list element 4 {length: 0x02, data: 0x31 0x02}   <== Target

          Requested SID will be compared with byte 0 of each white list elements.
        */

        /* only validate with white list element which length > 1*/
        if ((element_length == 2) && (*pElementData == *pReqData))
        {
          //Requested Subfunction will be compared with byte 1 of each white list elements.
          if (pElementData[1] == pReqData[1])
          {
            isSubfunctionValidated = DCM_TRUE;
            break;
          }
        }

        index_AuthEleData += element_length;
      }
      else 
      {
        /* no white list element left, exit loop */
        index_AuthEleData = element_MaxLen;
      }
    }

    if (isSubfunctionValidated == DCM_TRUE)
    {
      RetVal = DCM_TRUE;
    }
    #endif
  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ExtendValidateAccessRightsWithWhiteList         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Extend Validate Access Rights With White List       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pData, DataLen, pAuthEle                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
#if ((DCM_DSP_AUTHENTICATION_WHITE_LIST_DID_CONFIGURED == STD_ON) \
     || (DCM_DSP_AUTHENTICATION_WHITE_LIST_RID_CONFIGURED == STD_ON))
static FUNC(boolean, DCM_CODE) Dcm_ExtendValidateAccessRightsWithWhiteList(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData // input data will be DID/RID: HighByte LowByte GrantsAccessByte
  , uint32 DataLen //for RID and DID, this argument will be three 
  , Dcm_AuthenticationElementPtrType pAuthEle)
{
  /* input argument pData will follow below format:
     DID: DIDHighByte DIDLowByte MaskAccessByte 
     RID: RIDHighByte RIDLowByte MaskAccessByte
    example: F1 90 01
  */

  uint8 ChkVal;
  uint32 element_MaxLen; // maximun length of pAuthEle->pData
  uint32 element_length; // length of each element in while list
  uint8 index_AuthEleData; // index of pAuthEle->pData;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pElementData;

  ChkVal = DCM_FALSE;
  index_AuthEleData = 0;
  element_MaxLen = pAuthEle->DataMaxLen;

  while (index_AuthEleData < element_MaxLen)
  {
   /* pData[index_AuthEleData] pont to the address of lenth */
    element_length = (uint32)pAuthEle->pData[index_AuthEleData];
    if (element_length != 0U)
    {
      index_AuthEleData++;
        /* pData[index_AuthEleData] pont to the address of data */
      pElementData = &pAuthEle->pData[index_AuthEleData];
      /*
        example: pAuthEle->pData = 03 1A 90 01 03 31 4F 05 03 F1 90 03 
          white list element 0 {length: 0x03, data: 0x1A 0x90 0x01} : DID 0x1A90 can read
          white list element 1 {length: 0x03, data: 0x31 0x4F 0x05} : DID 0x314F can read and ControlAccess
          white list element 2 {length: 0x03, data: 0xF1 0x90 0x03} : DID 0xF190 can read and write
        RID will be same.

      */
      if (element_length == DataLen)
      {
        /* check the RID or DID */
        ChkVal = Dcm_MemCompare(pElementData, pData, DCM_TWO);
        if (DCM_TRUE == ChkVal) 
        {
          /*ex)  0b11 (read and write) && 0b01 (read) */ 
          if ((pElementData[DCM_TWO] & pData[DCM_TWO]) != 0U)
          {
            break;
          }
        }
      }
      index_AuthEleData += element_length;
    }
    else
    {
      /* exit loop */
      index_AuthEleData = element_MaxLen;
    }
  }


  return ChkVal;
}
#endif
#endif

/*******************************************************************************
** Function Name        : Dcm_CheckGeneralNrcModeRule                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check General Nrc Mode Rule                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01560 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_CheckGeneralNrcModeRule(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode)
{
  #if (DCM_AUTHENTICATION_GENERAL_NRC_MODE_RULE == STD_ON)
  uint8 ModeRuleIndex = Dcm_AuthenticationConfig.GeneralNrcModeRuleIndex;

  if ((DCM_E_POSITIVERESPONSE == Dcm_CheckModeRule(DCM_TRUE, ModeRuleIndex))
      && (NULL_PTR != pErrorCode))
  {
    *pErrorCode = DCM_GENERAL_NRC;
  }
  #else
  DCM_UNUSED(pErrorCode);
  #endif
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CheckTargetIdModeRule                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check Target Id Mode Rule                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01490 SWS_Dcm_01491 SWS_Dcm_01492 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_CheckTargetIdModeRule(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode)
{
  #if (DCM_AUTHENTICATION_TARGET_ID_MODE_RULE == STD_ON)
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  uint8 ModeRuleIndex; 
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    ModeRuleIndex = pAuthConCfg->TargetIdModeRuleIndex;
    if ((DCM_E_POSITIVERESPONSE != Dcm_CheckModeRule(DCM_TRUE, ModeRuleIndex))
        && (NULL_PTR != pErrorCode))
    {
      *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSCOPE;
    }
  }
  #else
  DCM_UNUSED(pErrorCode);
  #endif
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ResetAuthenticationElement                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Reset Authentication Element                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pAuthEle                                            **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_ResetAuthenticationElement(
  Dcm_AuthenticationElementPtrType pAuthEle)
{
  if (NULL_PTR != pAuthEle)
  {
    Dcm_MemClear(
      pAuthEle->pData, pAuthEle->DataMaxLen);

  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ReadAuthenticationElementRole                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Read Authentication Element Role                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementRole(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg)
{
  boolean RetVal = DCM_FALSE;
  KeyM_CertificateIdType CertId;
  Dcm_AuthenticationElementPtrType pAuthEle;
  KeyM_CertElementIdType CertEleId;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) CertEleData;
  uint32 CertEleDataLen;
  Std_ReturnType Res;

  if ((NULL_PTR != pAuthConCfg) && (NULL_PTR != pAuthConCfg->pRole))
  {
    CertId = pAuthConCfg->CertId;
    pAuthEle = pAuthConCfg->pRole;
    CertEleId = pAuthEle->Id;
    CertEleData = pAuthEle->pData;
    CertEleDataLen = pAuthEle->DataMaxLen;

    Res = KeyM_CertElementGet(
      CertId, CertEleId, CertEleData, &CertEleDataLen);

    /* SWS_Dcm_01515 */
    if ((E_OK == Res)
        && (DCM_AUTHENTICATION_ROLE_SIZE == CertEleDataLen))
    {
      RetVal = DCM_TRUE;
    }
  }

  return RetVal;
}
#endif
/*******************************************************************************
** Function Name        : Dcm_ReadAuthenticationElementWLServices             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Read Authentication Element white list for Services **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLServices(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg)
{
  boolean RetVal = DCM_FALSE;
  KeyM_CertificateIdType CertId;
  Dcm_AuthenticationElementPtrType pAuthEle;
  uint32 WLMaxSize;

  if ((NULL_PTR != pAuthConCfg) && (NULL_PTR != pAuthConCfg->pWLServices))
  {
    CertId = pAuthConCfg->CertId;
    pAuthEle = pAuthConCfg->pWLServices;
    WLMaxSize = DCM_AUTHENTICATION_WHITE_LIST_SERVICES_MAX_SIZE;

    RetVal = Dcm_ReadAuthenticationElementWhiteList(CertId, pAuthEle, WLMaxSize);
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ReadAuthenticationElementWLDid                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Read Authentication Element White List for Did      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLDid(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg)
{
  boolean RetVal = DCM_TRUE;
  KeyM_CertificateIdType CertId;
  Dcm_AuthenticationElementPtrType pAuthEle;
  uint32 WLMaxSize;

  #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_DID_CONFIGURED == STD_ON)
  if ((NULL_PTR != pAuthConCfg) && (NULL_PTR != pAuthConCfg->pWLDid))
  {
    CertId = pAuthConCfg->CertId;
    pAuthEle = pAuthConCfg->pWLDid;
    WLMaxSize = DCM_AUTHENTICATION_WHITE_LIST_DID_MAX_SIZE;

    RetVal = Dcm_ReadAuthenticationElementWhiteList(CertId, pAuthEle, WLMaxSize);
  }
  #else
  DCM_UNUSED(pAuthConCfg);
  #endif

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ReadAuthenticationElementWLMemorySelection      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Read Authentication Element White List for          **
**                        Memory Selection of Read DTC Service                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLMemorySelection(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg)
{
  boolean RetVal = DCM_TRUE;
  #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_MEMORY_SELECTION_CONFIGURED == STD_ON)
  KeyM_CertificateIdType CertId;
  Dcm_AuthenticationElementPtrType pAuthEle;
  uint32 WLMaxSize;

  if ((NULL_PTR != pAuthConCfg) && (NULL_PTR != pAuthConCfg->pWLMemorySelection))
  {
    CertId = pAuthConCfg->CertId;
    pAuthEle = pAuthConCfg->pWLMemorySelection;
    WLMaxSize = DCM_AUTHENTICATION_WHITE_LIST_MEMORY_SELECTION_MAX_SIZE;

    RetVal = Dcm_ReadAuthenticationElementWhiteList(CertId, pAuthEle, WLMaxSize);
  }
  #else
  DCM_UNUSED(pAuthConCfg);
  #endif

  return RetVal;
}
#endif
/*******************************************************************************
** Function Name        : Dcm_ReadAuthenticationElementWLRid                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Read Authentication Element White List for Rid      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConCfg                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWLRid(
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg)
{
  boolean RetVal = DCM_TRUE;
  #if (DCM_DSP_AUTHENTICATION_WHITE_LIST_RID_CONFIGURED == STD_ON)
  KeyM_CertificateIdType CertId;
  Dcm_AuthenticationElementPtrType pAuthEle;
  uint32 WLMaxSize;

  if ((NULL_PTR != pAuthConCfg) && (NULL_PTR != pAuthConCfg->pWLRid))
  {
    CertId = pAuthConCfg->CertId;
    pAuthEle = pAuthConCfg->pWLRid;
    WLMaxSize = DCM_AUTHENTICATION_WHITE_LIST_RID_MAX_SIZE;

    RetVal = Dcm_ReadAuthenticationElementWhiteList(CertId, pAuthEle, WLMaxSize);
  }
  #else
  DCM_UNUSED(pAuthConCfg);
  #endif

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ReadAuthenticationElementWhiteList              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Read Authentication Element White List              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : CertId, WLMaxSize                                   **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pAuthEle                                            **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ReadAuthenticationElementWhiteList(
  KeyM_CertificateIdType CertId
  , Dcm_AuthenticationElementPtrType pAuthEle
  , uint32 WLMaxSize)
{

  boolean RetVal = DCM_FALSE;
  KeyM_CertElementIdType CertEleId = pAuthEle->Id;
  KeyM_CertElementIteratorType CertEleIte;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pCertEleData;
  uint32 CertEleDataLen;
  uint32 maxLength;
  Std_ReturnType Res;

  /*make space for length in advance */
  CertEleDataLen = pAuthEle->DataMaxLen - 1; /* remain 1 byte for length*/
  maxLength = WLMaxSize;  /* ex) 13 byte in cfg Dcm ( length + data ) */
  pCertEleData = pAuthEle->pData; // point to address of length of first element 

  /*pData structure:
    byte 0: length
    byte 1: data
    byte 2: data
    ...
    byte n: length
    byte n+1: data
  */
  Res = KeyM_CertElementGetFirst(
    CertId, CertEleId, &CertEleIte, &pCertEleData[1], &CertEleDataLen);

  if (E_OK == Res)
  {
    pCertEleData[0] = (uint8) CertEleDataLen; // update length for first element

    while (E_OK == Res)
    {
       /* point to the next element */
      pCertEleData = &pCertEleData[CertEleDataLen + 1];  /* size of the data + size of the length */
      maxLength = maxLength - (CertEleDataLen + 1);// subtract the processed lenth

      /*make space for length in advance */
      CertEleDataLen = maxLength - 1; /* remained length  (sum of the size of length and data)*/
      Res = KeyM_CertElementGetNext(&CertEleIte, &pCertEleData[1], &CertEleDataLen);
      if (E_OK == Res)
      {
         pCertEleData[0] = (uint8) CertEleDataLen; // update length for next element
      }
    }
  }

  if ((E_OK != Res) && (E_NOT_OK != Res))
  {
    RetVal = DCM_FALSE;
  }
  else 
  {
    RetVal = DCM_TRUE;
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ProcessVerifyCertificateUnidirectional          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Process Verify Certificate Unidirectional           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessVerifyCertificateUnidirectional(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_NOT_OK;

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode;
  uint8 ResultVal = DCM_FALSE;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) LpCertificateData;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = NULL_PTR;
  uint8 AuthenticationIdIndex;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pResData;

  pNrcCode = &Dcm_GddNegRespError;
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(pPduIdTable->usMainConnectionId);

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    /* Check data length */
    ResultVal = Dcm_ChkLengthOfUnidirectional(pMsgContext, pNrcCode);

    /* Check data length valid */
    if (DCM_TRUE == ResultVal)
    {      
        if ((Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == AUTHENTICATION_IDLE) ||  
            (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == UNIDIRECTIONAL_PENDING) || 
            (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == UNIDIRECTIONAL_SUCCESSFULLY) || 
            (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == PROOFOFOWNERSHIP_PENDING) || 
            (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == PROOFOFOWNERSHIP_SUCCESSFULLY))
        {
          ResultVal = Dcm_ChkCommunicationConfiguration(pMsgContext, pNrcCode);

          /* Check COCO valid */
          if (DCM_TRUE == ResultVal)
          {
            LpCertificateData = &pMsgContext->reqData[4];
            pResData = &pMsgContext->resData[4]; 

            RetVal = Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].pUniDirectionalFun
              (LpCertificateData, OpStatus, pResData, pNrcCode);

            if (DCM_E_PENDING == RetVal)
            {
              Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = UNIDIRECTIONAL_PENDING;

              Dcm_StartTimerExt(
                DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER
                , AUTHENTICATION_WAITING_ASYNCFUNC_TIME
                , Dcm_AuthenticationReProcessing
                , Dcm_CanncelUniDirectionalProcessing);

              /* Authentication service has own pending processing, no need using common pending logic*/
              RetVal = E_OK;
            }
            else
            {
              if (*pNrcCode != DCM_E_POSITIVERESPONSE)
              {
                Dcm_InternalSetNegResponse(pMsgContext, *pNrcCode);
                Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);

                Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = AUTHENTICATION_IDLE;
              }
            }
          }
          /* Check COCO invalid */
          else{
            Dcm_InternalSetNegResponse(pMsgContext, *pNrcCode);
            Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);

            Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = AUTHENTICATION_IDLE;
          }
        }
        else{
          Dcm_InternalSetNegResponse(pMsgContext, DCM_E_REQUESTSEQUENCEERROR);
          Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);

          Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = AUTHENTICATION_IDLE;
        }
    }
    /* Check data length invaild */
    else{
      Dcm_InternalSetNegResponse(pMsgContext, *pNrcCode);
      Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);

      Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = AUTHENTICATION_IDLE;
    }
  }
  else{
    Dcm_InternalSetNegResponse(pMsgContext, DCM_E_GENERALREJECT);
    Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
  }
  
  #else
  Dcm_AuthenticationProcessingStateType UniDirectionalState;
  UniDirectionalState = Dcm_GetAuthProcessingState();

  if (UniDirectionalState == VERIFY_CERTIFICATE_INITIAL)
  {
    Dcm_StartTimerExt(
      DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER
      , AUTHENTICATION_WAITING_ASYNCFUNC_TIME
      , Dcm_AuthenticationReProcessing
      , Dcm_CanncelAsyncFuntionCall);
  }

  RetVal = AuthDispatchTable[UniDirectionalState](
    pMsgContext, &Dcm_GddNegRespError);

  if (E_OK != RetVal)
  {
    Dcm_SetAuthProcessingState(AUTHENTICATION_NEGATIVE_RESPONSE);
  }
  DCM_UNUSED(OpStatus);
  #endif

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_GetAuthProcessingState                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get Authentication Processing State                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_AuthenticationProcessingStateType               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Dcm_AuthenticationProcessingStateType, DCM_CODE) Dcm_GetAuthProcessingState(void)
{
  Dcm_AuthenticationProcessingStateType RetVal = AUTHENTICAITON_PROCESSING_MAX_STATE;
  uint8 AuthenticationIdIndex;

  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    RetVal = Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].AuthenticationProcessingState;
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_SetAuthProcessingState                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set Authentication Processing State                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : state                                               **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_SetAuthProcessingState(
  Dcm_AuthenticationProcessingStateType state)
{
  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];

  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].AuthenticationProcessingState = state;
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ChkCommunicationConfiguration                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check Communication Configuration                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01459 */
/* polyspace+3 MISRA-C3:8.13 [Justified:Low] "pMsgContext type is the prototype specified in the AUTOSAR specification. 
part of the code is verfied manually and it has no impact" */
static FUNC(boolean, DCM_CODE) Dcm_ChkCommunicationConfiguration(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  boolean RetVal = DCM_TRUE;
  uint8 COCO = pMsgContext->reqData[1U];

  if (DCM_SUPPORT_COMUNICATION_CONFIGURATION != COCO)
  {
    RetVal = DCM_FALSE;
    *pNrcCode = DCM_E_REQUESTOUTOFRANGE;
  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ChkLengthOfUnidirectional                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check Length Of Unidirectional                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01460*/
/* polyspace+3 MISRA-C3:8.13 [Justified:Low] "pMsgContext type is the prototype specified in the AUTOSAR specification. 
part of the code is verfied manually and it has no impact" */
static FUNC(boolean, DCM_CODE) Dcm_ChkLengthOfUnidirectional(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  boolean RetVal = DCM_TRUE;
  uint16 ChallengeClientLength;
  uint16 CertClientLength;
  uint16 RequestLength;
  uint8 HighByteChallengeClient;
  uint8 LowByteChallengeClient;
  uint8 HighByteCertClient;
  uint8 LowByteCertClient;
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = NULL_PTR;
  uint8 AuthenticationIdIndex;
  #endif

  RequestLength = (uint16)pMsgContext->reqDataLen;
  HighByteCertClient = pMsgContext->reqData[2U];
  LowByteCertClient = pMsgContext->reqData[3U];
  CertClientLength = 
    Dcm_AuthenticationGet2ByteData(HighByteCertClient, LowByteCertClient);

  HighByteChallengeClient = pMsgContext->reqData[CertClientLength + 4U];
  LowByteChallengeClient = pMsgContext->reqData[CertClientLength + 5U];
  ChallengeClientLength = Dcm_AuthenticationGet2ByteData(
    HighByteChallengeClient
    , LowByteChallengeClient);
  /* check minimum length ( Min len = Sub(1byte) + COCO(1byte)+ HighByteCertClient(1byte) 
   *                                  + LowByteCertClient(1byte) + cert(1byte)
   *                                  + HighByteChallengeClient(1byte) 
   *                                  + LowByteChallengeClient(1byte))
  */
  if (RequestLength < DCM_AUTHENTICATION_UNIDIRECTION_DATA_MIN_LENGTH) 
  {
    RetVal = DCM_FALSE;
    *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  /* CertClientLength + Sub(1byte) + COCO(1byte)+ HighByteCertClient(1byte) 
   *                                  + LowByteCertClient(1byte)
   *                                  + HighByteChallengeClient(1byte) 
   *                                  + LowByteChallengeClient(1byte) */
  else if (RequestLength != (CertClientLength + ChallengeClientLength + 6U))
  {
    RetVal = DCM_FALSE;
    *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else 
  {
    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
    AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(pPduIdTable->usMainConnectionId);
    
    if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
    {
      if ((uint32)CertClientLength > Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].ulCertificateClientSize)
      {
        RetVal = DCM_FALSE;
        *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        /* RetVal = DCM_TRUE; */
      }
    }
    else{
      RetVal = DCM_FALSE;
      *pNrcCode = DCM_E_GENERALREJECT;
    }
    #else
    /* RetVal = DCM_TRUE; */
    #endif
  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_AuthenticationReProcessing                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Authentication Re Processing                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_AuthenticationReProcessing(void)
{
  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  Dcm_AuthenticationESPendingProcessing(
    DCM_PENDING, &Dcm_GstMsgContext);
  #else
  (void)Dcm_DcmAuthentication(
    DCM_INITIAL, &Dcm_GstMsgContext);
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_StoreCertificate                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Store Certificate                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04231 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_StoreCertificate(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  boolean RetVal = DCM_FALSE;
  KeyM_CertificateIdType CertificateId;
  KeyM_CertDataType CertificateDataInfo;
  Std_ReturnType KeyMReturnVal;
  uint8 AuthenticationIdIndex;
  uint16 CertDataLength;
  uint8 HighByteLength;
  uint8 LowByteLength;

  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    CertificateId = Dcm_GaaAuthenticationConnectionConfig[AuthenticationIdIndex].CertId;

    HighByteLength = pMsgContext->reqData[2U];
    LowByteLength = pMsgContext->reqData[3u];  
    CertDataLength = Dcm_AuthenticationGet2ByteData(HighByteLength, LowByteLength);

    CertificateDataInfo.certDataLength = (uint32) CertDataLength;
    CertificateDataInfo.certData = &pMsgContext->reqData[4U];

    /* SWS_Dcm_01463 */
    KeyMReturnVal = KeyM_SetCertificate(CertificateId, &CertificateDataInfo);

    /* SWS_Dcm_01464 */
    if (KEYM_E_KEY_CERT_SIZE_MISMATCH == KeyMReturnVal)
    {
      *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    /* because KEYM_E_PARAMETER_MISMATCH is not mention in spec so NRC 0x10 will return*/
    else if ((E_OK != KeyMReturnVal) 
             && (KEYM_E_KEY_CERT_SIZE_MISMATCH != KeyMReturnVal))
    {
      *pNrcCode = DCM_E_GENERALREJECT;
    }
    else /*E_OK == KeyMReturnVal */
    {
      RetVal = DCM_TRUE;
    }
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_UniDirectionalInitial                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Uni Directional Initial                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UniDirectionalInitial(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;

  uint8 ResultVal = Dcm_ChkCommunicationConfiguration(pMsgContext, pNrcCode);

  if (DCM_TRUE == ResultVal)
  {
    ResultVal = Dcm_ChkLengthOfUnidirectional(pMsgContext, pNrcCode);
  }

  if (DCM_TRUE == ResultVal)
  {
    ResultVal = Dcm_StoreCertificate(pMsgContext, pNrcCode);
  }

  if (DCM_TRUE == ResultVal)
  {
    RetVal = E_OK;
    Dcm_SetAuthProcessingState(VERIFY_CERTIFICATE);
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_UniDirectionalResponse                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Uni Directional Response                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UniDirectionalResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;

  if ( DCM_E_POSITIVERESPONSE == *pNrcCode)
  {
    RetVal = E_OK;
    Dcm_SetAuthProcessingState(PROOFOFOWNERSHIP_INITIAL);
    Dcm_VerifyCertificateUnidirectionalSuccessfully(pMsgContext);
    Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);
    Dcm_GblSendResponse = DCM_TRUE;
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_VerifyCertificate                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Verify Certificate                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04235 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyCertificate(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  KeyM_CertificateIdType CertificateId;
  uint8 AuthenticationIdIndex;

  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    CertificateId = Dcm_GaaAuthenticationConnectionConfig[AuthenticationIdIndex].CertId;

    /* SWS_Dcm_01468 */
    RetVal = KeyM_VerifyCertificate(CertificateId);

    if (E_OK == RetVal)
    {
      Dcm_SetAuthProcessingState(VERIFY_CERTIFICATE_WAITTING_CALLBACK);
    }
    /* SWS_Dcm_01465 */
    else if (KEYM_E_BUSY == RetVal)
    {
      *pNrcCode = DCM_E_BUSYREPEATREQUEST;
    }
    else
    {
      /* SWS_Dcm_01466 */
      *pNrcCode = DCM_E_GENERALREJECT;
    }
  }

  DCM_UNUSED(pMsgContext);

  return RetVal;
}
  #endif

/*******************************************************************************
** Function Name        : Dcm_CanncelAsyncFuntionCall                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Canncel Async Funtion Call                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01467 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_CanncelAsyncFuntionCall(void)
{
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  uint32 JobId;
  uint8 AuthenticationIdIndex;
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];

  (void)Dcm_ResetToDeauthenticatedState(pPduIdTable->usMainConnectionId );
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );
 
  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    JobId = Dcm_AuthenticationGetAsyncJobId(
      &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex]);

    (void) Csm_CancelJob(JobId, CRYPTO_OPERATIONMODE_SINGLECALL);
  }
  

  Dcm_GblSendResponse = DCM_TRUE;
  Dcm_GddNegRespError = DCM_E_GENERALREJECT;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CreatingServerChallenge                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Creating Server Challenge                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01493 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CreatingServerChallenge(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint32 CsmJobId;

  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint8 AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if ((AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
      && (DCM_E_POSITIVERESPONSE == *pNrcCode))
  {
    CsmJobId = Dcm_GaaAuthenticationConnectionConfig[AuthenticationIdIndex].RandomJobId;
    Dcm_AuthenticationSetAsyncJobId(CsmJobId, &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex]);

    RetVal = Csm_RandomGenerate(
      CsmJobId
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerData[0U]
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerDataLength);

    if (E_OK == RetVal)
    {
      Dcm_SetAuthProcessingState(CREATE_CHALLENGE_SERVER_WAITTING_CALLBACK);
    }
    /* SWS_Dcm_01465 */
    else if (CRYPTO_E_BUSY == RetVal)
    {
      *pNrcCode = DCM_E_BUSYREPEATREQUEST;
    }
    else
    {
      /* SWS_Dcm_01466*/
      *pNrcCode = DCM_E_GENERALREJECT;
    }
  }

  DCM_UNUSED(pMsgContext);
  return RetVal;
}
#endif
/*******************************************************************************
** Function Name        : Dcm_VerifyCertificateUnidirectionalSuccessfully     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Verify Certificate Unidirectional Successfully      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01503 */
static FUNC(void, DCM_CODE) Dcm_VerifyCertificateUnidirectionalSuccessfully(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  uint8 AuthenticationIdIndex;
  uint32 DataLength;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    DataLength = Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].ulChallengeServerSize;

    pMsgContext->resDataLen = DataLength + 6U;

    pMsgContext->resData[0U] = pMsgContext->reqData[0];
    pMsgContext->resData[1U] = DCM_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSERY;

    pMsgContext->resData[2U] = Dcm_GetSecondByteFrom4ByteData(DataLength);
    pMsgContext->resData[3U] = Dcm_GetFirstByteFrom4ByteData(DataLength);

    pMsgContext->resData[DataLength + 4U] = 0U;
    pMsgContext->resData[DataLength + 5U] = 0U;
  }
  #else
  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    DataLength = Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerDataLength;

    Dcm_MemCopy(&pMsgContext->resData[4U]
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerData[0U]
      , DataLength);

    pMsgContext->resDataLen = DataLength + 6U;

    pMsgContext->resData[0U] = pMsgContext->reqData[0];
    pMsgContext->resData[1U] = DCM_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSERY;

    pMsgContext->resData[2U] = Dcm_GetSecondByteFrom4ByteData(DataLength);
    pMsgContext->resData[3U] = Dcm_GetFirstByteFrom4ByteData(DataLength);

    pMsgContext->resData[DataLength + 4U] = 0U;
    pMsgContext->resData[DataLength + 5U] = 0U;
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_ProcessProofofOwnershipClient                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Process Proof of Ownership Client                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessProofofOwnershipClient(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_NOT_OK;

  uint8 AuthenticationIdIndex;

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) LpProofOfOwnerShipClientData;
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode;
  #else
  Dcm_AuthenticationProcessingStateType AuthProcessingState;
  #endif

  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    pNrcCode = &Dcm_GddNegRespError;
    RetVal = Dcm_ChkProofofOwnerShipClientLength(pMsgContext, pNrcCode);

    if (E_OK == RetVal)
    {
      if ((Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == UNIDIRECTIONAL_SUCCESSFULLY) || 
          (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == PROOFOFOWNERSHIP_PENDING) || 
          (Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState == PROOFOFOWNERSHIP_SUCCESSFULLY))
      {

        LpProofOfOwnerShipClientData = &pMsgContext->reqData[3];
        RetVal = Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].pProofOfOwnerShipClientFun
          (LpProofOfOwnerShipClientData, OpStatus, pNrcCode);

        if (DCM_E_PENDING == RetVal)
        {
          Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = PROOFOFOWNERSHIP_PENDING;

          Dcm_StartTimerExt(
            DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER
            , AUTHENTICATION_WAITING_ASYNCFUNC_TIME
            , Dcm_AuthenticationReProcessing
            , Dcm_CanncelProofOfOwnerShipClientProcessing);
          
          /* Authentication service has own pending processing, no need using common pending logic*/
          RetVal = E_OK;
        }
        else
        {
          if (RetVal == E_NOT_OK)
          {
            Dcm_InternalSetNegResponse(pMsgContext, DCM_E_GENERALREJECT);
            Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
          }
          else
          {
            Dcm_InternalSetNegResponse(pMsgContext, DCM_E_GENERALREJECT);
            Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
            DCM_REPORT_ERROR(DCM_AUTHENTICATION_FUNC_SID, DCM_E_UNREACHED_CASE_IS_OCCURED);
          }
        }
      }
      else
      {
        Dcm_InternalSetNegResponse(pMsgContext, DCM_E_REQUESTSEQUENCEERROR);
        Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
      }
    }
    else 
    {
      Dcm_InternalSetNegResponse(pMsgContext, *pNrcCode);
      Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
    }
  }
  #else
  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    AuthProcessingState = Dcm_GetAuthProcessingState();

    /* SWS_Dcm_01509 */
    if (PROOFOFOWNERSHIP_INITIAL == AuthProcessingState)
    {
      Dcm_StartTimerExt(
        DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER
        , AUTHENTICATION_WAITING_ASYNCFUNC_TIME
        , Dcm_AuthenticationReProcessing
        , Dcm_CanncelAsyncFuntionCall);
    }

    if (PROOFOFOWNERSHIP_INITIAL > AuthProcessingState)
    {
      Dcm_GddNegRespError = DCM_E_REQUESTSEQUENCEERROR;
      AuthProcessingState = AUTHENTICATION_NEGATIVE_RESPONSE;
    }

    RetVal = AuthDispatchTable[AuthProcessingState](
      pMsgContext, &Dcm_GddNegRespError);
  }
 

  if (E_OK != RetVal)
  {
    Dcm_SetAuthProcessingState(AUTHENTICATION_NEGATIVE_RESPONSE);
  }
  #endif

  DCM_UNUSED(OpStatus);
  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_ChkProofofOwnerShipClientLength                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check Proof of OwnerShip Client Length              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01510 */
/* polyspace+3 MISRA-C3:8.13 [Justified:Low] "pMsgContext type is the prototype specified in the AUTOSAR specification. 
part of the code is verfied manually and it has no impact" */
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ChkProofofOwnerShipClientLength(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  uint8 RetVal = E_OK;
  uint16 CompareDataLen;

  uint16 LengthOfProofofOwnerShipClient;
  uint8 HighByteProofofOwnerShipClient;
  uint8 LowbyteProofofOwnerShipClient;

  uint16 LengthOfEphemeralPublicKeyClient;
  uint8 HighByteEphemeralPublicKeyClient;
  uint8 LowbyteEphemeralPublicKeyClient;

  #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable;
  #endif

  uint32 RequestLength;
  RequestLength = pMsgContext->reqDataLen;

  HighByteProofofOwnerShipClient = pMsgContext->reqData[1U];
  LowbyteProofofOwnerShipClient = pMsgContext->reqData[2U];
  LengthOfProofofOwnerShipClient = Dcm_AuthenticationGet2ByteData(
    HighByteProofofOwnerShipClient
    , LowbyteProofofOwnerShipClient);

  HighByteEphemeralPublicKeyClient = pMsgContext->reqData[
    LengthOfProofofOwnerShipClient + 3U];

  LowbyteEphemeralPublicKeyClient = pMsgContext->reqData[
    LengthOfProofofOwnerShipClient + 4U];

  LengthOfEphemeralPublicKeyClient = Dcm_AuthenticationGet2ByteData(
    HighByteEphemeralPublicKeyClient
    , LowbyteEphemeralPublicKeyClient);

  CompareDataLen = (LengthOfProofofOwnerShipClient + LengthOfEphemeralPublicKeyClient + 5U);

  /* Check minimum length ( Min len = Sub(1byte) +  HighByteProofofOwnerShipClient(1byte) 
   *                                 + LowbyteProofofOwnerShipClient(1byte) + proofOfOwnershipClient(1byte)
   *                                 + HighByteEphemeralPublicKeyClient(1byte) 
   *                                 + LowbyteEphemeralPublicKeyClient(1byte))
  */
  if (RequestLength < DCM_AUTHENTICATION_PROOFOFOWNER_DATA_MIN_LENGTH) 
  {
    RetVal = E_NOT_OK;
    *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  /* check total length
   * CompareDataLen =   Sub(1byte) + HighByteProofofOwnerShipClient(1byte) 
   *                                 + LowbyteProofofOwnerShipClient(1byte) + 
   *                                 + HighByteEphemeralPublicKeyClient(1byte) 
   *                                 + LowbyteEphemeralPublicKeyClient(1byte))
  */
  else if (RequestLength != CompareDataLen)
  {
    RetVal = E_NOT_OK;
    *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {
    #if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
    pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
    AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
      pPduIdTable->usMainConnectionId ); 

    if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
    {
      if (Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].ulProofOfOwnerShipClientSize
       != LengthOfProofofOwnerShipClient)
      {
        RetVal = E_NOT_OK;
        *pNrcCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        /* RetVal = E_OK; */
      }
    }
    #else
    Dcm_SetAuthProcessingState(VERIFY_PROOFOFOWNERSHIP);
    /* RetVal = E_OK; */
    #endif
  }

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_VerifyProofofOwnerShipClient                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Verify Proof of OwnerShip Client                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01511 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyProofofOwnerShipClient(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  uint8 RetVal = E_NOT_OK;

  Std_ReturnType CsmRetVal;
  uint32 JobId;
  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  uint16 LengthOfProofofOwnerShipClient;
  uint8 HighByteLength;
  uint8 LowByteLength;
  
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    JobId = Dcm_GaaAuthenticationConnectionConfig[AuthenticationIdIndex].ProofofOwnerShipClientJobId;
    
    HighByteLength = pMsgContext->reqData[1U];
    LowByteLength = pMsgContext->reqData[2U];
    LengthOfProofofOwnerShipClient = Dcm_AuthenticationGet2ByteData(
      HighByteLength
      , LowByteLength);

    Dcm_AuthenticationSetAsyncJobId(JobId, &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex]);

    CsmRetVal = Csm_SignatureVerify(
      JobId
      , CRYPTO_OPERATIONMODE_SINGLECALL
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerData[0U]
      , Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerDataLength
      , &pMsgContext->reqData[3U]
      , LengthOfProofofOwnerShipClient
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].CsmSignatureVerifyResult);

    if (E_OK == CsmRetVal)
    {
      RetVal = E_OK;
      Dcm_SetAuthProcessingState(VERIFY_PROOFOFOWNERSHIP_WAITTING_CALLBACK);
    }
    /* SWS_Dcm_01465 */
    else if (CRYPTO_E_BUSY == CsmRetVal)
    {
      *pNrcCode = DCM_E_BUSYREPEATREQUEST;
    }
    else
    {
      /* SWS_Dcm_01466*/
      *pNrcCode = DCM_E_GENERALREJECT;
    }
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ChkCsm_SignatureVerify                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check Csm_SignatureVerify                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ChkCsm_SignatureVerify(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  Crypto_VerifyResultType CsmResult;

  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    CsmResult = Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].CsmSignatureVerifyResult;

    /* SWS_Dcm_01529 */
    if (CRYPTO_E_VER_OK == CsmResult)
    {
      RetVal = E_OK;
      Dcm_SetAuthProcessingState(PROOFOFOWNERSHIP_RESPONSE);
    }
    else
    {
      /* SWS_Dcm_01512 */
      *pNrcCode = DCM_E_OWNERSHIPVERIFICATIONFAILED;
    }
  }

  DCM_UNUSED(pMsgContext);
  return RetVal;
}
#endif
/*******************************************************************************
** Function Name        : Dcm_OwnerShipVerificationSuccess                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Owner Ship Verification Success                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_OwnerShipVerificationSuccess(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  
  if (DCM_TRUE == Dcm_TransitIntoAuthenticatedState(pPduIdTable->usMainConnectionId))
  {

    pMsgContext->resDataLen = 4U;
    pMsgContext->resData[0U] = pMsgContext->reqData[0];
    pMsgContext->resData[1U] = DCM_OWNERSHIPVERIFIED_AUTHENTICATIONCOMPLETE;

    /* SWS_Dcm_01513 */
    pMsgContext->resData[2U] = 0U;
    pMsgContext->resData[3U] = 0U;

    RetVal = E_OK;

    #if (DCM_AUTHENTICATION_ES_SUPPORT != STD_ON)
    Dcm_GblSendResponse = DCM_TRUE;
    Dcm_SetAuthProcessingState(PROOFOFOWNERSHIP_INITIAL);
    Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);
    #endif
  }
  else
  {
    *pNrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCONTENT;
  }
  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_AuthentationNegativeResponse                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Authentation Negative Response                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_AuthentationNegativeResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  uint8 AuthConIdx;
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable;
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  
  if ( DCM_E_POSITIVERESPONSE != *pNrcCode)
  {
    Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);

    AuthConIdx = Dcm_GetAuthConnectionIndex(
      pPduIdTable->usMainConnectionId );

    if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
    {
      pAuthConInfo = &Dcm_GaaAuthenConnectionInfo[AuthConIdx];
      Dcm_ResetAuthProcessingState(pAuthConInfo);
    }

    Dcm_GblSendResponse = DCM_TRUE;
  }

  DCM_UNUSED(pMsgContext);
  return E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_AuthenticationAsynWaitingCallBack               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Authentication Asyn Waiting CallBack                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_AuthenticationAsynWaitingCallBack(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  DCM_UNUSED(pNrcCode);
  DCM_UNUSED(pMsgContext);
  return E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ProcessVerifyCertificateBidirectional           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Process Verify Certificate Bidirectional            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProcessVerifyCertificateBidirectional(
  Dcm_OpStatusType OpStatus
  , P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_NOT_OK;

  Dcm_AuthenticationProcessingStateType AuthProcessingState;
  AuthProcessingState = Dcm_GetAuthProcessingState();

  if (AuthProcessingState == VERIFY_CERTIFICATE_INITIAL)
  {
    Dcm_StartTimerExt(
      DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER
      , AUTHENTICATION_WAITING_ASYNCFUNC_TIME
      , Dcm_AuthenticationReProcessing
      , Dcm_CanncelAsyncFuntionCall);
  }

  RetVal = AuthDispatchTable[AuthProcessingState](
    pMsgContext, &Dcm_GddNegRespError);

  if (E_OK != RetVal)
  {
    Dcm_SetAuthProcessingState(AUTHENTICATION_NEGATIVE_RESPONSE);
  }

  DCM_UNUSED(OpStatus);
  return RetVal;
}
#endif
/*******************************************************************************
** Function Name        : Dcm_VerifyCertificateInitial                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Verify Certificate Initial                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyCertificateInitial(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint8 AuthenticationSubFunction;
  AuthenticationSubFunction = pMsgContext->reqData[0U];

  RetVal = (VERIFY_CERTIFICATE_BIDIRECTIONAL == AuthenticationSubFunction) ?
    Dcm_BiDirectionalInitial(pMsgContext, pErrorCode) :
    Dcm_UniDirectionalInitial(pMsgContext, pErrorCode);

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_BiDirectionalInitial                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Bi Directional Initial                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_BiDirectionalInitial(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint8 ResultVal = Dcm_ChkCommunicationConfiguration(pMsgContext, pNrcCode);

  if (DCM_TRUE == ResultVal) 
  {
    ResultVal = Dcm_ChkLengthOfBidirectional(pMsgContext, pNrcCode);
  }

  if (DCM_TRUE == ResultVal) 
  {
    ResultVal = Dcm_StoreCertificate(pMsgContext, pNrcCode);
  }

  if (DCM_TRUE == ResultVal) 
  {
    ResultVal = Dcm_StoreCertificate(pMsgContext, pNrcCode);
  }

  if (DCM_TRUE == ResultVal)
  {
    RetVal = E_OK;
    Dcm_SetAuthProcessingState(VERIFY_CERTIFICATE);
  }

  return RetVal;
}
#endif
/*******************************************************************************
** Function Name        : Dcm_ChkLengthOfBidirectional                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check Length Of Bidirectional                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01461 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(boolean, DCM_CODE) Dcm_ChkLengthOfBidirectional(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  boolean RetVal;
  uint16 ChallengeClientLength;
  uint16 CertClientLength;
  uint8 HighByteChallengeClient;
  uint8 LowByteChallengeClient;
  uint8 HighByteCertClient;
  uint8 LowByteCertClient;

  uint16 RequestLength;
  RequestLength = (uint16)pMsgContext->reqDataLen;

  HighByteCertClient = pMsgContext->reqData[2U];
  LowByteCertClient = pMsgContext->reqData[3U];
  CertClientLength = Dcm_AuthenticationGet2ByteData(
    HighByteCertClient
    , LowByteCertClient);

  HighByteChallengeClient = pMsgContext->reqData[CertClientLength + 4U];
  LowByteChallengeClient = pMsgContext->reqData[CertClientLength + 5U];  
  ChallengeClientLength = Dcm_AuthenticationGet2ByteData(
    HighByteChallengeClient
    , LowByteChallengeClient);

  if (CertClientLength == DCM_AUTHENTICATION_DATA_MIN_LENGTH) 
  {
    RetVal = DCM_FALSE;
  } 
  else if (ChallengeClientLength == DCM_AUTHENTICATION_DATA_MIN_LENGTH)
  {
    RetVal = DCM_FALSE;
  }
  else if (RequestLength != (CertClientLength + ChallengeClientLength + 6U))
  {
    RetVal = DCM_FALSE;
  } 
  else
  {
    RetVal = DCM_TRUE;
  }

  if (RetVal == DCM_FALSE) 
  {
    /*For ES95489-01. NRC 54 returned when certificate could not be evaluated because the format requirement has not been met.*/
    *pNrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDFORMAT;
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CreatingServerChallengeDone                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Creating Server Challenge Done                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CreatingServerChallengeDone(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  uint8 AuthenticationSubFunction;
  AuthenticationSubFunction = pMsgContext->reqData[0U];

  if (VERIFY_CERTIFICATE_BIDIRECTIONAL == AuthenticationSubFunction)
  {
    Dcm_SetAuthProcessingState(SIGN_CHALLENGE_CLIENT);
  }
  else
  {
    Dcm_SetAuthProcessingState(UNIDIRECTIONAL_RESPONSE);
  }

  DCM_UNUSED(pNrcCode);
  return E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_SigningChallengeClient                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Signing Challenge Client                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01504 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_SigningChallengeClient(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint32 JobId;
  uint8 AuthenticationIdIndex;
  uint16 CertClientLength;
  uint8 HighByteCertClient;
  uint8 LowByteCertClient;
  uint16 ChallengeClientLength;
  uint8 HighByteChallengeClient;
  uint8 LowByteChallengeClient;

  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pChallengeClientData;

  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  HighByteCertClient = pMsgContext->reqData[2U];
  LowByteCertClient = pMsgContext->reqData[3U];
  CertClientLength = Dcm_AuthenticationGet2ByteData(
    HighByteCertClient
    , LowByteCertClient);

  HighByteChallengeClient = pMsgContext->reqData[CertClientLength + 4U];
  LowByteChallengeClient = pMsgContext->reqData[CertClientLength + 5U];
  ChallengeClientLength = Dcm_AuthenticationGet2ByteData(
    HighByteChallengeClient
    , LowByteChallengeClient);

  pChallengeClientData = &pMsgContext->reqData[CertClientLength + 6U];

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    JobId = Dcm_GaaAuthenticationConnectionConfig[
      AuthenticationIdIndex].ClientChallengeSignJobId;

    Dcm_AuthenticationSetAsyncJobId(JobId, 
      &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex]);

    RetVal = Csm_SignatureGenerate(
      JobId
      , CRYPTO_OPERATIONMODE_SINGLECALL
      , pChallengeClientData
      , ChallengeClientLength
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ProofOfOwnerShipServer[0U]
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].LengthOfProofOfOwnershipServer
    );

    if (E_OK == RetVal)
    {
      Dcm_SetAuthProcessingState(SIGN_CHALLENGE_CLIENT_WAITTING_CALLBACK);
    } 
    /* SWS_Dcm_01465 */
    else if (CRYPTO_E_BUSY == RetVal)
    {
      *pNrcCode = DCM_E_BUSYREPEATREQUEST;
    }
    else
    {
      /* SWS_Dcm_01466*/
      *pNrcCode = DCM_E_GENERALREJECT;
    }
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ProvidingServerCertificate                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Providing Server Certificate                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01506 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_ProvidingServerCertificate(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint32 EcuCertId;
  KeyM_CertDataType CertificateServerInfo;

  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;

  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if(AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    EcuCertId = Dcm_GaaAuthenticationConnectionConfig[
      AuthenticationIdIndex].ECUCertificateId;

    CertificateServerInfo.certDataLength = AUTHENTICATION_MAX_DATALENGTH;

    CertificateServerInfo.certData = &Dcm_GaaAuthenConnectionInfo[
      AuthenticationIdIndex].CertificateServerData[0U];

    RetVal = KeyM_GetCertificate((KeyM_CertificateIdType)EcuCertId, &CertificateServerInfo);

    if (E_OK == RetVal)
    {
      Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].
      LengthOfCertificateServer = CertificateServerInfo.certDataLength;

      Dcm_SetAuthProcessingState(BIDIRECTIONAL_RESPONSE);
    }
    /* SWS_Dcm_01507 */
    else if (KEYM_E_KEY_CERT_SIZE_MISMATCH == RetVal)
    {
      *pNrcCode = DCM_E_RESPONSETOOLONG;
    }
    else
    {
      /* SWS_Dcm_01466*/
      *pNrcCode = DCM_E_GENERALREJECT;
    }
  }

  DCM_UNUSED(pMsgContext);
  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_BiDirectionalResponse                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Bi Directional Response                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_BiDirectionalResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;

  if ( DCM_E_POSITIVERESPONSE == *pNrcCode)
  {
    RetVal = E_OK;
    Dcm_SetAuthProcessingState(PROOFOFOWNERSHIP_INITIAL);
    Dcm_VerifyCertificateBidirectionalSuccessfully(pMsgContext);

    Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);
    Dcm_GblSendResponse = DCM_TRUE;
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_VerifyCertificateBidirectionalSuccessfully      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Verify Certificate Bidirectional Successfully       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_01508 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_VerifyCertificateBidirectionalSuccessfully(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  uint8 AuthenticationIdIndex;
  uint32 LengthOfChallengeServer;
  uint32 LengthOfCertificateServer;
  uint32 LengthOfProofOfOwnershipServer;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId );

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    pMsgContext->resData[0U] = pMsgContext->reqData[0];
    pMsgContext->resData[1U] = DCM_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSERY;

    LengthOfChallengeServer = Dcm_GaaAuthenConnectionInfo[
      AuthenticationIdIndex].ChallengeServerDataLength;

    LengthOfCertificateServer = Dcm_GaaAuthenConnectionInfo[
      AuthenticationIdIndex].LengthOfCertificateServer;

    LengthOfProofOfOwnershipServer = Dcm_GaaAuthenConnectionInfo[
      AuthenticationIdIndex].LengthOfProofOfOwnershipServer;

    pMsgContext->resDataLen = LengthOfChallengeServer + \
      LengthOfCertificateServer + LengthOfProofOfOwnershipServer + 10U;

    /*update challengeServer*/
    pMsgContext->resData[3U] = Dcm_GetFirstByteFrom4ByteData(LengthOfChallengeServer);
    pMsgContext->resData[2U] = Dcm_GetSecondByteFrom4ByteData(LengthOfChallengeServer);

    Dcm_MemCopy(&pMsgContext->resData[4U]
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ChallengeServerData[0U]
      , LengthOfChallengeServer);

    /*update certificateServer*/
    pMsgContext->resData[LengthOfChallengeServer + 5U] = Dcm_GetFirstByteFrom4ByteData(
      LengthOfCertificateServer);
    pMsgContext->resData[LengthOfChallengeServer + 4U] = Dcm_GetSecondByteFrom4ByteData(
      LengthOfCertificateServer);

    Dcm_MemCopy(&pMsgContext->resData[LengthOfChallengeServer + 6U]
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].CertificateServerData[0U]
      , LengthOfCertificateServer);

    /*update ProofOfOnwerShipServer*/
    pMsgContext->resData[LengthOfChallengeServer + LengthOfCertificateServer + 7U] = Dcm_GetFirstByteFrom4ByteData(
      LengthOfProofOfOwnershipServer);
    pMsgContext->resData[LengthOfChallengeServer + LengthOfCertificateServer + 6U] = Dcm_GetSecondByteFrom4ByteData(
      LengthOfProofOfOwnershipServer);

    Dcm_MemCopy(
      &pMsgContext->resData[LengthOfChallengeServer + LengthOfCertificateServer + 8U]
      , &Dcm_GaaAuthenConnectionInfo[AuthenticationIdIndex].ProofOfOwnerShipServer[0U]
      , LengthOfProofOfOwnershipServer);

    /*update LengthOfEphemeralPublicKeyServer*/
    pMsgContext->resData[LengthOfProofOfOwnershipServer + \
      LengthOfChallengeServer + LengthOfCertificateServer + 8U] = 0x00;

    pMsgContext->resData[LengthOfProofOfOwnershipServer + \
      LengthOfChallengeServer + LengthOfCertificateServer + 9U] = 0x00;
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_VerifyTargetIdentification                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Verify Target Identification                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pNrcCode                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
/* SRS_Diag_04236 */
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_VerifyTargetIdentification(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode)
{
  Std_ReturnType RetVal = E_NOT_OK;

  if (DCM_E_POSITIVERESPONSE == *pNrcCode)
  {
    Dcm_CheckTargetIdModeRule(pNrcCode);
  }
  else
  {
    Dcm_CheckGeneralNrcModeRule(pNrcCode);
  }

  if (DCM_E_POSITIVERESPONSE == *pNrcCode)
  {
    RetVal = E_OK;
    Dcm_SetAuthProcessingState(CREATE_CHALLENGE_SERVER);
  }

  DCM_UNUSED(pMsgContext);
  return RetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ResetAuthProcessingState                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Reset Authentication Processing State               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConInfo                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_ResetAuthProcessingState(
Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo)
{
  if (NULL_PTR != pAuthConInfo)
  {
    pAuthConInfo->AuthenticationProcessingState = VERIFY_CERTIFICATE_INITIAL;
    pAuthConInfo->CsmAsyncJobId = DCM_DEFAULT_ASYNC_JOBID;
    pAuthConInfo->CsmSignatureVerifyResult = CRYPTO_E_VER_NOT_OK;

    pAuthConInfo->ChallengeServerDataLength = AUTHENTICATION_MAX_DATALENGTH;
    Dcm_MemClear(pAuthConInfo->ChallengeServerData
      , AUTHENTICATION_MAX_DATALENGTH);

    pAuthConInfo->LengthOfProofOfOwnershipServer = AUTHENTICATION_MAX_DATALENGTH;
    Dcm_MemClear(pAuthConInfo->ProofOfOwnerShipServer
      , AUTHENTICATION_MAX_DATALENGTH);

    pAuthConInfo->LengthOfCertificateServer = AUTHENTICATION_MAX_DATALENGTH;
    Dcm_MemClear(pAuthConInfo->CertificateServerData
      , AUTHENTICATION_MAX_DATALENGTH);
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_AuthenticationSetAsyncJobId                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Authentication Set Async Job Id                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : JobId, pAuthConInfo                                 **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_AuthenticationSetAsyncJobId(
  uint32 JobId
  , Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo)
{

  if (NULL_PTR != pAuthConInfo)
  {
    pAuthConInfo->CsmAsyncJobId = JobId;
  }
}
#endif
/*******************************************************************************
** Function Name        : Dcm_AuthenticationGetAsyncJobId                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Authentication Get Async Job Id                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : pAuthConInfo                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(uint32, DCM_CODE) Dcm_AuthenticationGetAsyncJobId(
  Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo)
{
  uint32 JobId = DCM_DEFAULT_ASYNC_JOBID;

  if (NULL_PTR != pAuthConInfo)
  {
    JobId = pAuthConInfo->CsmAsyncJobId;
  }
  return JobId;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_AuthenticationGet2ByteData                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get uint16 data from 2 uint8 data                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : HighByte, LowByte                                   **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16                                              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(uint16, DCM_CODE) Dcm_AuthenticationGet2ByteData(
  uint8 HighByte
  , uint8 LowByte)
{
  uint16 Value;
  Value = (uint16) HighByte << DCM_EIGHT;
  Value = Value | (uint16) LowByte;

  return Value;
}

/*******************************************************************************
** Function Name        : Dcm_GetFirstByteFrom4ByteData                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get first byte of uint32 data                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : buffer                                              **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(uint8, DCM_CODE) Dcm_GetFirstByteFrom4ByteData(uint32 buffer)
{
  uint8 Value;
  Value = (uint8) (buffer & 0xFFu);
  return Value;
}

/*******************************************************************************
** Function Name        : Dcm_GetSecondByteFrom4ByteData                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get second byte of uint32 data                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : buffer                                              **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : NA                                                  **
**                                                                            **
*******************************************************************************/
static FUNC(uint8, DCM_CODE) Dcm_GetSecondByteFrom4ByteData(uint32 buffer)
{
  uint8 Value;
  Value = (uint8) (((buffer >> 8U) & 0xFFu));
  return Value;
}

/*******************************************************************************
** Function Name        : Dcm_KeyMAsyncCertificateVerifyFinished              **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Can be called from KeyM upon                        **
**                        finishing an asynchronous certificate verification  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Result, CertId                                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : Dcm_Init should be called before calling this API   **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
/* SWS_Dcm_91077*/
/*inconsistent with KeyM_CertificateVerifyCallbackNotification*/
/*https:jira.autosar.org/browse/AR-92614*/
/*https:jira.autosar.org/browse/AR-93855*/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
FUNC(Std_ReturnType, DCM_CODE) Dcm_KeyMAsyncCertificateVerifyFinished(
  KeyM_CertificateIdType  CertId
  , KeyM_CertificateStatusType Result)
{
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  Dcm_AuthenticationProcessingStateType CurrentAuthProcessingState;
  Dcm_AuthenticationConnectionConfigConstPtrType pAuthConCfg;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    pAuthConCfg = &Dcm_GaaAuthenticationConnectionConfig[AuthConIdx];
    CurrentAuthProcessingState = Dcm_GetAuthProcessingState();

    if (pAuthConCfg->CertId == CertId)
    {
      Dcm_NegativeResponseCodeType NrcCode;
     
      CurrentAuthProcessingState++;
      Dcm_SetAuthProcessingState(CurrentAuthProcessingState);

      switch (Result)
      {
        case KEYM_E_CERTIFICATE_SIGNATURE_FAIL:
          /* SWS_Dcm_01469*/
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDSIGNATURE;
        break;

        case KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST:
          /* SWS_Dcm_01470 */
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCHAINOFTRUST;
        break;

        case KEYM_E_CERTIFICATE_INVALID_TYPE:
        /* SWS_Dcm_01471 */
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTYPE;
        break;

        case KEYM_E_CERTIFICATE_INVALID_FORMAT:
        /* SWS_Dcm_01472 */
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDFORMAT;
        break;

        case KEYM_E_CERTIFICATE_INVALID_CONTENT:
          /* SWS_Dcm_01473 */
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCONTENT;
        break;

        case KEYM_E_CERTIFICATE_REVOKED:
          /* SWS_Dcm_01475 */
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDCERTIFICATE;
        break;

        case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
         /* SWS_Dcm_01476*/
          NrcCode = DCM_E_CERTIFICATEVERIFICATIONFAILEDINVALIDTIMEPERIOD;
        break;

        case KEYM_CERTIFICATE_INVALID:
          /* because there is no mention about NRC return for result KEYM_CERTIFICATE_INVALID */
          NrcCode = DCM_E_GENERALREJECT;
        break;

        default:
          /*E_OK*/
          NrcCode = DCM_E_POSITIVERESPONSE;
        break;

      }
       
      Dcm_GddNegRespError = NrcCode;
    }
  }

  return E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CsmAsyncJobFinished                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Can be called from Csm upon                         **
**                        finishing an asynchronous job processing.           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Result                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : Dcm_Init should be called before calling this API   **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
/*https:jira.autosar.org/browse/AR-93854*/
/* SWS_Dcm_91076 */
/*inconsistent with Csm_ApplicationCallbackNotification*/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
FUNC(Std_ReturnType, DCM_CODE) Dcm_CsmAsyncJobFinished(
  /*uint32 JobId*/
  Csm_ResultType Result)
{
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  uint16 ConnectionId = pPduIdTable->usMainConnectionId ;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  Dcm_AuthenticationProcessingStateType AuthProcessingState;
  AuthProcessingState = Dcm_GetAuthProcessingState();

  // uint32 CsmAsyncJobId = Dcm_AuthenticationGetAsyncJobId(&AuthConInfo->CsmAsyncJobId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_NUM)
  {
    
    if (E_OK == Result
        /*JobId == CsmAsyncJobId*/)
    {
      AuthProcessingState++;
      Dcm_SetAuthProcessingState(AuthProcessingState);
    }
    else
    {
      Dcm_SetAuthProcessingState(AUTHENTICATION_NEGATIVE_RESPONSE);

      /* SWS_Dcm_01466 SWS_Dcm_01467*/
      Dcm_GddNegRespError = DCM_E_GENERALREJECT;
    }
  }

  return E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_MemClear                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function clear pointer memory                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : Size                                                **
**                                                                            **
** InOut Parameters     : pDest                                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF)
static FUNC(void, DCM_CODE) Dcm_MemClear(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pDest,
  uint32 Size)
{
  uint32 idx;
  if (NULL_PTR != pDest)
  {
    for (idx = 0U; idx < Size; idx++)
    {
      pDest[idx] = 0U;
    }
  }
}
#endif

/*******************************************************************************
**  Function  Name       : Dcm_GetProtocolTypeIndex                           **
**                                                                            **
**  Service  ID          : NA                                                 **
**                                                                            **
**  Description          : This  function  will  give  the  protocol  index   **
**                                                                            **
**  Sync/Async           : Synchronous                                        **
**                                                                            **
**  Re-entrancy          : Non-Reentrant                                      **
**                                                                            **
**  Input  Parameters    : ProtocolId                                         **
**                                                                            **
**  InOut parameter      : None                                               **
**                                                                            **
**  Output  Parameters   : ProtocolIdx                                        **
**                                                                            **
**  Return  parameter    : void                                               **
**                                                                            **
**  Preconditions        : None                                               **
**                                                                            **
**  Remarks              : Global  Variable(s)  :                             **
**                         Dcm_GaaProtocolIds, Dcm_GaaProtocolConfig          **
**                                                                            **
*******************************************************************************/
static FUNC(uint8, DCM_CODE) Dcm_GetProtocolTypeIndex(uint8 ProtocolId)
{
  uint8 idx;
  uint8 ProtocolIdx = DCM_SERVICE_NOT_CONFIGURED;

  for (idx = 0U; idx < DCM_NUM_OF_PROTOCOLCONFIG; idx++)
  {
    if (ProtocolId == Dcm_GaaProtocolIds[idx])
    {
      ProtocolIdx = idx;
      break;
    }
  }

  return ProtocolIdx;
}

/*******************************************************************************
** Function Name        : Dcm_MemCopy                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to copy data to pointer                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pSrc, Size                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pDest                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_MemCopy(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pDest,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSrc,
  uint32 Size)
{
  uint32 idx;

  if ((NULL_PTR != pDest) && (NULL_PTR != pSrc))
  {
    for (idx = 0U; idx < Size; idx++)
    {
      pDest[idx] = pSrc[idx];
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_MemCompare                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to compare 2 memory data with              **
**                        input condition                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pDest, pSrc, Size                                   **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_MemCompare(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDest
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSrc
  , uint32 Size)
{
  uint32 idx;
  boolean ChkVal = DCM_TRUE;

  for (idx = 0U; idx < Size; idx++)
  {
    if ( pSrc[idx] != pDest[idx])
    {
      ChkVal = DCM_FALSE;
      break;
    }
  }

  return ChkVal;
}

/*******************************************************************************
** Function Name        : Dcm_Authentication_UpdateTimers                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function update Dcm available timer                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_GetTimerInfoPtr                   **
**                                      Dcm_StopTimer                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_Authentication_UpdateTimers(void)
{
  uint8 Timer;
  Dcm_AuthenTimerInfoPtrType pTimer = NULL_PTR;
  Dcm_AuthenTimerCallbackFunType pCbkFun = NULL_PTR;

  for (Timer = 0; Timer < TIMER_MAX_NUM; Timer++)
  {
    pTimer = &Dcm_GaaAuthenticationTimer[Timer];

    if (DCM_FALSE == pTimer->StartFlag)
    {
      continue;
    }

    if (0 < pTimer->Time)
    {
      pTimer->Time--;
    }

    pCbkFun = (0 < pTimer->Time) ? pTimer->PendingCbk : pTimer->TimeoutCbk;

    if (NULL_PTR != pCbkFun)
    {
      if(Dcm_TxRespStatus.ucNegResp == DCM_FALSE)
      {     
        pCbkFun();
      }

      if (pCbkFun == pTimer->TimeoutCbk)
      {
        Dcm_StopTimer(Timer);
      }
    }
  }
}


/*******************************************************************************
** Function Name        : Dcm_StartTimerExt                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function start Dcm available timer                  **
**                        and invoked setup function                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer, Time, PendingCbk, TimeoutCbk                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SetTimerInfo                      **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_StartTimerExt(
  uint8 Timer
  , uint16 Time
  , Dcm_AuthenTimerCallbackFunType PendingCbk
  , Dcm_AuthenTimerCallbackFunType TimeoutCbk)
{
  Dcm_AuthenTimerInfoPtrType pTimer = &Dcm_GaaAuthenticationTimer[Timer];
  pTimer->StartFlag = DCM_TRUE;
  pTimer->Time = (Time / DCM_TASK_TIME);
  pTimer->PendingCbk = PendingCbk;
  pTimer->TimeoutCbk = TimeoutCbk;
}


/*******************************************************************************
** Function Name        : Dcm_StopTimer                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function stop Dcm available timer                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SetTimerInfo                      **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_StopTimer(uint8 Timer)
{
  Dcm_AuthenTimerInfoPtrType pTimer = &Dcm_GaaAuthenticationTimer[Timer];
  pTimer->StartFlag = DCM_FALSE;
  pTimer->Time = (uint16)0U;
  pTimer->PendingCbk = NULL_PTR;
  pTimer->TimeoutCbk = NULL_PTR;
}

/*******************************************************************************
** Function Name        : Dcm_InitTimers                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function Dcm timer initialize                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : pConfig                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : Dcm_Init must be called before call this fucntion   **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SetTimerInfo                      **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_InitAuthenticationTimers(void)
{
  uint8 Timer;
  Dcm_AuthenTimerInfoPtrType pTimer;
  for (Timer = 0; Timer < TIMER_MAX_NUM; Timer++)
  {
    pTimer = &Dcm_GaaAuthenticationTimer[Timer];
    pTimer->StartFlag = DCM_FALSE;
    pTimer->Time = (uint16)0U;
    pTimer->PendingCbk = NULL_PTR;
    pTimer->TimeoutCbk = NULL_PTR;
  }
}

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
FUNC(boolean, DCM_CODE) Dcm_GetAuthenticationConnectionESInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionESInfoPtrType pAuthConInfo)
{
  boolean RetVal = DCM_FALSE;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);
  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    pAuthConInfo->State = Dcm_GaaAuthenConnectionESInfo[AuthConIdx].State;

    Dcm_MemCopy(pAuthConInfo->Role, 
      Dcm_GaaAuthenConnectionESInfo[AuthConIdx].Role, 
      DCM_AUTHENTICATION_ROLE_SIZE);

    RetVal = DCM_TRUE;
  }

  return RetVal;
}
#endif

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
FUNC(boolean, DCM_CODE) Dcm_SetAuthenticationConnectionESInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionESInfoConstPtrType pAuthConInfo)
{
  boolean RetVal = DCM_FALSE;
  Dcm_AuthenticationConnectionESInfoPtrType pMyAuthConInfo;
  uint8 AuthConIdx = Dcm_GetAuthConnectionIndex(ConnectionId);

  if (AuthConIdx < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    pMyAuthConInfo = &Dcm_GaaAuthenConnectionESInfo[AuthConIdx];
    pMyAuthConInfo->State = pAuthConInfo->State;

    Dcm_MemCopy(pMyAuthConInfo->Role, 
      pAuthConInfo->Role, DCM_AUTHENTICATION_ROLE_SIZE);

    RetVal = DCM_TRUE;
  }

  return RetVal;
}
#endif


#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
static FUNC(void, DCM_CODE) Dcm_AuthenticationESPendingProcessing(  
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Std_ReturnType RetVal = E_NOT_OK;
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA) pPduIdTable = NULL_PTR;
  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) LpCertificateData;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pResData;
  Dcm_AuthenticationESProcessingStateType LddState;
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) LpProofOfOwnerShipClientData;

  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(pPduIdTable->usMainConnectionId);
  
  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    LddState = Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState;
    pNrcCode = &Dcm_GddNegRespError;

    switch (LddState)
    {
      case UNIDIRECTIONAL_PENDING:
      {
        LpCertificateData = &pMsgContext->reqData[4];
        pResData = &pMsgContext->resData[4]; // challenge data start from byte 4
        RetVal = Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].pUniDirectionalFun
          (LpCertificateData, OpStatus, pResData, pNrcCode);

        if (E_OK == RetVal)
        {
          Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = UNIDIRECTIONAL_SUCCESSFULLY;
          // prepare response data
          Dcm_VerifyCertificateUnidirectionalSuccessfully(pMsgContext);

          Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);
          Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
        }
        else
        {
          if (*pNrcCode != DCM_E_POSITIVERESPONSE)
          {
            Dcm_InternalSetNegResponse(pMsgContext, *pNrcCode);
            Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);
            Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
          }
        }
      }
      break;

      case PROOFOFOWNERSHIP_PENDING:
      {
        LpProofOfOwnerShipClientData = &pMsgContext->reqData[3];
        RetVal = Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].pProofOfOwnerShipClientFun
          (LpProofOfOwnerShipClientData, OpStatus, pNrcCode);

        if (E_OK == RetVal)
        {
          Dcm_GaaAuthenConnectionESInfo[AuthenticationIdIndex].ESProcessingState = PROOFOFOWNERSHIP_SUCCESSFULLY;
          // prepare response data
          (void)Dcm_OwnerShipVerificationSuccess(pMsgContext, pNrcCode);

          Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);

          if (*pNrcCode != DCM_E_POSITIVERESPONSE)
          {
            Dcm_InternalSetNegResponse(pMsgContext, *pNrcCode);
          }
          
          Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
        }
        else
        {
          if (E_NOT_OK == RetVal)
          {
            Dcm_InternalSetNegResponse(pMsgContext, DCM_E_OWNERSHIPVERIFICATIONFAILED);
            Dcm_StopTimer(DCM_AUTHENTICATION_WAITING_ASYNCFUNC_TIMER);
            Dcm_InternalProcessingDone(pMsgContext, DCM_SYNC_DONE);
          }
        }
      }
      break;

      default:
        /*do nothing*/
      break;
    }
  }
}
#endif

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
static FUNC(void, DCM_CODE) Dcm_CanncelUniDirectionalProcessing(void)
{
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  uint8 AuthenticationIdIndex;
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pNrcCode = &Dcm_GddNegRespError;
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  (void)Dcm_ResetToDeauthenticatedState(pPduIdTable->usMainConnectionId );

  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId);

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    (void)Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].pProofOfOwnerShipClientFun
          (NULL_PTR, DCM_CANCEL, pNrcCode);
  }

  Dcm_InternalSetNegResponse(&Dcm_GstMsgContext, DCM_E_GENERALREJECT);
  Dcm_InternalProcessingDone(&Dcm_GstMsgContext, DCM_SYNC_DONE);

}
#endif

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
static FUNC(void, DCM_CODE) Dcm_CanncelProofOfOwnerShipClientProcessing(void)
{
  P2VAR(Dcm_PduIdTable, AUTOMATIC, DCM_APPL_DATA)  pPduIdTable;
  uint8 AuthenticationIdIndex;
  pPduIdTable = &Dcm_GaaPduIdTableConfig[Dcm_GddRxPduId];
  (void)Dcm_ResetToDeauthenticatedState(pPduIdTable->usMainConnectionId );

  AuthenticationIdIndex = Dcm_GetAuthConnectionIndex(
    pPduIdTable->usMainConnectionId);

  if (AuthenticationIdIndex < DCM_AUTHENTICATION_CONNECTION_ES_NUM)
  {
    (void)Dcm_GaaAuthenticationConnectionESConfig[AuthenticationIdIndex].pUniDirectionalFun
          (NULL_PTR, DCM_CANCEL, NULL_PTR, NULL_PTR);
  }

  Dcm_InternalSetNegResponse(&Dcm_GstMsgContext, DCM_E_GENERALREJECT);
  Dcm_InternalProcessingDone(&Dcm_GstMsgContext, DCM_SYNC_DONE);
}
#endif

#endif /*(DCM_AUTHENTICATION_SUPPORT == STD_ON)*/

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
********************************************************************************/
