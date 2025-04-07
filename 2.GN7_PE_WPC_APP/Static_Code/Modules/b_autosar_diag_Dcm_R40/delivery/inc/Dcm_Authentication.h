/*******************************************************************************
**  (C) 2022 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Authentication.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_Authentication                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision     Date            By             Description                    **
********************************************************************************
** 2.14.0.0     30-Sep-2024     JHHong       #48435                           **
**                                                                            **
** 2.11.1.0     16-Apr-2024     JHHong       #45144, #44551                   **
**                                                                            **
** 2.8.0.0      15-Nov-2023     Suyon Kim    #43348                           **
**                                                                            **
** 2.7.0        25-Jul-2022     Suyon Kim    #40261                           **
**                                                                            **
** 2.6.0        30-Sep-2022     LanhLT       Initial Version                  **
*******************************************************************************/

#ifndef DCM_AUTHENTICATION_H
#define DCM_AUTHENTICATION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_PCTypes.h"

#if ((DCM_AUTHENTICATION_SUPPORT == STD_ON) && (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF))
#include "Csm.h"
#endif

/*******************************************************************************
**                     Types and Variables definition                         **
*******************************************************************************/
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)

#define DEAUTHENTICATED_ROLE (Dcm_AuthenticationConfig.DeauthenticatedRole)

typedef uint8 Dcm_AuthenticationStateType;
#define DCM_DEAUTHENTICATED ((Dcm_AuthenticationStateType)0x00)
#define DCM_AUTHENTICATED   ((Dcm_AuthenticationStateType)0x01)
#define AUTHENTICATION_CONNECTION_ID_NOT_CONFIGURED (0xFFu)

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
typedef uint8 Dcm_AuthenticationESProcessingStateType;
#define AUTHENTICATION_IDLE                       ((Dcm_AuthenticationESProcessingStateType) 0x00)
#define UNIDIRECTIONAL_PENDING                    ((Dcm_AuthenticationESProcessingStateType) 0x01)
#define UNIDIRECTIONAL_SUCCESSFULLY               ((Dcm_AuthenticationESProcessingStateType) 0x02)
#define PROOFOFOWNERSHIP_PENDING                  ((Dcm_AuthenticationESProcessingStateType) 0x03)
#define PROOFOFOWNERSHIP_SUCCESSFULLY             ((Dcm_AuthenticationESProcessingStateType) 0x04)

#define AUTHENTICAITON_PROCESSING_MAX_STATE       ((Dcm_AuthenticationESProcessingStateType) 0x05)


typedef struct STagDcm_AuthenticationConnectionESInfoType
{
  /* Authenticattion role */
  Dcm_AuthenticationRoleType Role;

  /* Authentication State */
  Dcm_AuthenticationESProcessingStateType ESProcessingState;

  /* Authentication State */
  Dcm_AuthenticationStateType State;

} Dcm_AuthenticationConnectionESInfoType;

typedef P2VAR(Dcm_AuthenticationConnectionESInfoType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_AuthenticationConnectionESInfoPtrType;

typedef P2CONST(Dcm_AuthenticationConnectionESInfoType, AUTOMATIC, DCM_APPL_CONST)
  Dcm_AuthenticationConnectionESInfoConstPtrType;

#else /*DCM_AUTHENTICATION_ES_SUPPORT != STD_ON*/

typedef uint8 Dcm_AuthenticationProcessingStateType;

#define VERIFY_CERTIFICATE_INITIAL                ((Dcm_AuthenticationProcessingStateType) 0x00)
#define VERIFY_CERTIFICATE                        ((Dcm_AuthenticationProcessingStateType) 0x01)
#define VERIFY_CERTIFICATE_WAITTING_CALLBACK      ((Dcm_AuthenticationProcessingStateType) 0x02)
#define VERIFY_CERTIFICATE_TARGET_ID              ((Dcm_AuthenticationProcessingStateType) 0x03)
#define CREATE_CHALLENGE_SERVER                   ((Dcm_AuthenticationProcessingStateType) 0x04)
#define CREATE_CHALLENGE_SERVER_WAITTING_CALLBACK ((Dcm_AuthenticationProcessingStateType) 0x05)
#define CREATE_CHALLENGE_SERVER_DONE              ((Dcm_AuthenticationProcessingStateType) 0x06)
#define UNIDIRECTIONAL_RESPONSE                   ((Dcm_AuthenticationProcessingStateType) 0x07)
#define SIGN_CHALLENGE_CLIENT                     ((Dcm_AuthenticationProcessingStateType) 0x08)
#define SIGN_CHALLENGE_CLIENT_WAITTING_CALLBACK   ((Dcm_AuthenticationProcessingStateType) 0x09)
#define PROVIDE_SERVER_CERTIFICATE                ((Dcm_AuthenticationProcessingStateType) 0x0A)
#define BIDIRECTIONAL_RESPONSE                    ((Dcm_AuthenticationProcessingStateType) 0x0B)
#define PROOFOFOWNERSHIP_INITIAL                  ((Dcm_AuthenticationProcessingStateType) 0x0C)
#define VERIFY_PROOFOFOWNERSHIP                   ((Dcm_AuthenticationProcessingStateType) 0x0D)
#define VERIFY_PROOFOFOWNERSHIP_WAITTING_CALLBACK ((Dcm_AuthenticationProcessingStateType) 0x0E)
#define VERIFY_PROOFOFOWNERSHIP_RESULT            ((Dcm_AuthenticationProcessingStateType) 0x0F)
#define PROOFOFOWNERSHIP_RESPONSE                 ((Dcm_AuthenticationProcessingStateType) 0x10)
#define AUTHENTICATION_NEGATIVE_RESPONSE          ((Dcm_AuthenticationProcessingStateType) 0x11)
#define AUTHENTICAITON_PROCESSING_MAX_STATE       ((Dcm_AuthenticationProcessingStateType) 0x12)

typedef struct STagDcm_AuthenticationConnectionInfoType
{
  /* Store CsmJobId after Dcm called asynchronous function in Csm module*/
  uint32 CsmAsyncJobId;

  /* buffer stored server challenge length */
  uint32 ChallengeServerDataLength;

  /* buffer stored Certificate Server data length */
  uint32 LengthOfCertificateServer;

  /* buffer stored proof of ownership data length */
  uint32 LengthOfProofOfOwnershipServer;

  /* buffer stored server challenge */
  uint8 ChallengeServerData[AUTHENTICATION_MAX_DATALENGTH];

  /* buffer stored proof of ownership data */
  uint8 ProofOfOwnerShipServer[AUTHENTICATION_MAX_DATALENGTH];

  /* buffer stored Certificate Server data  */
  uint8 CertificateServerData[AUTHENTICATION_MAX_DATALENGTH];

  /* Authenticated role */
  Dcm_AuthenticationRoleType Role;

  /* Result of asynchronous function of Csm module */
  Crypto_VerifyResultType CsmSignatureVerifyResult;

  /* Authentication State */
  Dcm_AuthenticationStateType State;

  /* Authentication processing state for each main function  */
  Dcm_AuthenticationProcessingStateType AuthenticationProcessingState; 

} Dcm_AuthenticationConnectionInfoType;

typedef P2VAR(Dcm_AuthenticationConnectionInfoType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_AuthenticationConnectionInfoPtrType;

typedef P2CONST(Dcm_AuthenticationConnectionInfoType, AUTOMATIC, DCM_APPL_CONST)
  Dcm_AuthenticationConnectionInfoConstPtrType;

#endif /* DCM_AUTHENTICATION_ES_SUPPORT == STD_ON */
#endif /* DCM_AUTHENTICATION_SUPPORT == STD_ON */

/*******************************************************************************
**                      Function  Definitions                                 **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

#if ((DCM_AUTHENTICATION_PERSIST_STATE_MODE_RULE == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON))
extern FUNC(void, DCM_CODE) Dcm_StartPersistAuthenticationState(void);

extern FUNC(void, DCM_CODE) Dcm_WaitRestorePersistedAuthenticationState(void);

extern FUNC(void, DCM_CODE) Dcm_CancelRestorePersistedAuthenticationState(void);

extern FUNC(void, DCM_CODE) Dcm_WaitPersistAuthenticationState(void);

extern FUNC(void, DCM_CODE) Dcm_CancelPersistAuthenticationState(void);

extern FUNC(void, DCM_CODE) Dcm_StartRestorePersistedAuthenticationState(void);
#endif /* (DCM_AUTHENTICATION_PERSIST_STATE_MODE_RULE == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON) */

#if ((DCM_MODE_CONDITION == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON))
extern FUNC(boolean, DCM_CODE) Dcm_IsValidCertificateElementCondition(
  Dcm_ModeConditionConfigConstPtrType pModeCondCfg);
#endif /* (DCM_MODE_CONDITION == STD_ON) && (DCM_AUTHENTICATION_SUPPORT == STD_ON) */

#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)

extern FUNC(void, DCM_CODE) Dcm_InitAuthentication(void);

extern FUNC(boolean, DCM_CODE) Dcm_TriggerTimerFallbackToDeauthenticatedState(boolean ChkStopVal);

extern FUNC(void, DCM_CODE) Dcm_FallbackToDeauthenticatedState(void);

extern FUNC(boolean, DCM_CODE) Dcm_ValidateServiceAccessRights(
  P2CONST(Dcm_ServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pServiceCfg);

extern FUNC(boolean, DCM_CODE) Dcm_ValidateSubServiceAccessRights(
  P2CONST(Dcm_ServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pServiceCfg
  , P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pSubServiceCfg);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmAuthentication(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

// public for future use in DSP (some special services) if have configured role
extern FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRights(
  Dcm_AuthenticationRoleType AssignedRole);

// public for future use in DSP (some special services) after failed to validate role
/* @Trace: SWS_Dcm_01525 */
extern FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLDid(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen);

/* @Trace: SWS_Dcm_01526 */
extern FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLRid(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen);

/* @Trace: SWS_Dcm_01527 */
extern FUNC(boolean, DCM_CODE) Dcm_ValidateAccessRightsWithWLMemorySelection(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData
  , uint32 DataLen);

extern FUNC(boolean, DCM_CODE) Dcm_IsAuthenticatedConnection(
  uint16 ConnectionId);

extern FUNC(uint8, DCM_CODE) Dcm_GetAuthConnectionIndex(
  uint16 ConnectionId);

extern FUNC(boolean, DCM_CODE) Dcm_ResetToDeauthenticatedState(
  uint16 ConnectionId);

extern FUNC(boolean, DCM_CODE) Dcm_TransitIntoAuthenticatedState(
  uint16 ConnectionId);

extern FUNC(void, DCM_CODE) Dcm_Authentication_UpdateTimers(void);

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
extern FUNC(boolean, DCM_CODE) Dcm_SetAuthenticationConnectionESInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionESInfoConstPtrType pAuthConInfo);

extern FUNC(boolean, DCM_CODE) Dcm_GetAuthenticationConnectionESInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionESInfoPtrType pAuthConInfo)  ;
#else
extern FUNC(boolean, DCM_CODE) Dcm_GetAuthenticationConnectionInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionInfoPtrType pAuthConInfo);

extern FUNC(boolean, DCM_CODE) Dcm_SetAuthenticationConnectionInfo(
  uint16 ConnectionId
  , Dcm_AuthenticationConnectionInfoConstPtrType pAuthConInfo);
#endif

#endif /* DCM_AUTHENTICATION_SUPPORT == STD_ON */

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
