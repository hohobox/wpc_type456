/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_CallOuts.H                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the declaration for Dcm callout functions  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 2.12.0.0  17-Apr-2024   Suyon Kim       #44568                             **
**                                                                            **
** 2.10.0.0  28-Dec-2023   Suyon Kim       #42075                             **
**                                                                            **
** 2.9.0.0   27-11.2023    GS Ryu          #42519                             **
**                                                                            **
** 2.8.0.0   15-Nov-2023   Suyon Kim       #43348                             **
**                                                                            **
** 2.7.0     25-Jul-2022   Suyon Kim       #40261                             **
**                                                                            **
** 2.6.4.1   28-Jun-2023   GS Ryu          #41467                              **
**                                                                            **
** 2.6.2.0   19-Apr-2023   LanhLT          #1493                              **
**                                                                            **
** 2.6.1.0   13-Jan-2023   DanhTQ1         #38247                             **
**                                                                            **
** 2.3.18.0  24-Jan-2022   KH Kim          #34012                             **
**                                                                            **
** 2.3.4.0   28-Jan-2021   EunKyung Kim    #27997                             **
**                                                                            **
** 2.3.2.0   05-Nov-2020   EunKyung Kim    #26432                             **
**                                                                            **
** 1.0.3     19-04-2017    Jin      Jung   #6973, #8006                       **
**                                                                            **
** 1.0.2     05-12-2016    Jin      Jung   #6645                              **
**                                                                            **
** 1.0.1     24-05-2016    Jun      Jung   #4922                              **
**                                                                            **
** 1.0.0     06-07-2011    Autron          Initial Version                    **
*******************************************************************************/

#ifndef DCM_CALLOUTS_H
#define DCM_CALLOUTS_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_PCTypes.h"
#include "Dcm_Types.h"
#include "HwResource.h"
#include "Rte_Type.h"
#include "Dcm_Ram.h"
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/ 
#define DCM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

#if (HWRESOURCE_VENDOR(HWRESOURCE_INFINEON))
/* Structure for programming condition used in both DCM and FBL (For AURIX) */
typedef struct
{
  /* Tester source address configured per protocol */
  uint16 TesterSourceAddr;
  /* reserved for align */
  uint16 reserved0;
  /* Id of the protocol on which the request has been received */
  uint8 ProtocolId;
  /* Service identifier of the received request */
  uint8 Sid;
  /* Identifier of the received subfunction */
  uint8 SubFncId;
  /* Set to true in order to request reprogramming of the ECU */
  uint8 ReprogramingRequest;
  /* Indicate whether the application has been updated or not */
  uint8 ApplUpdated;
  /* Set to true in case the flashloader or application shall send a response */
  uint8 ResponseRequired;
  /* Jump from FBL */
  uint8 JumpFromBootloader;
  /* Security Level 0:lock otherwise:unlock */
  uint8 SecLvInfo;
  /* Reserved bit */
  uint8 Reserved[2];
  #if defined (DCM_FBL_TYPE) && (DCM_FBL_TYPE == DCM_AUTOEVER_FBL_USED_RXCONNECTION_ID_USED)
  /*Unique id of the connection on which the request has been received*/
  uint16 ConnectionId;
  #endif  
}Dcm_McuDepProgConditionsType;
#else
/* Structure for programming condition used in both DCM and FBL */
typedef struct
{
  /* Tester source address configured per protocol */
  uint16 TesterSourceAddr;
  /* Id of the protocol on which the request has been received */
  uint8 ProtocolId;
  /* Service identifier of the received request */
  uint8 Sid;
  /* Identifier of the received subfunction */
  uint8 SubFncId;
  /* Set to true in order to request reprogramming of the ECU */
  uint8 ReprogramingRequest;
  /* Indicate whether the application has been updated or not */
  uint8 ApplUpdated;
  /* Set to true in case the flashloader or application shall send a response */
  uint8 ResponseRequired;
  /* Security Level 0:lock otherwise:unlock */
  uint8 SecLvInfo; 
  #if defined (DCM_FBL_TYPE) && (DCM_FBL_TYPE == DCM_AUTOEVER_FBL_USED_RXCONNECTION_ID_USED)
  /*Unique id of the connection on which the request has been received*/
  uint16 ConnectionId;
  #endif  
}Dcm_McuDepProgConditionsType;
#endif

extern FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
  (P2VAR(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions
  (P2CONST(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_CONST) ProgConditions);

#if (DCM_CNR_USED_SHA1 == STD_ON)
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SignatureVerify
    (P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) dataPtr,
    VAR(uint32, AUTOMATIC) dataLength,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) signaturePtr,
    VAR(uint32, AUTOMATIC) signatureLength,
    P2CONST(Dcm_AsymPublicKeyType, AUTOMATIC, DCM_APPL_CONST) publicKey,
    P2VAR(Std_ReturnType, AUTOMATIC, DCM_APPL_CONST) verifyPtr);
#endif

#ifdef DcmConf_DcmDspSecurityRow_L21
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_GetRandomSeed
  (P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) RandomSeed);

extern FUNC(void, DCM_CALLOUT_CODE) Dcm_GetPublicKey
  (P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) PublicKey);
#endif

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestTransferExit
  (Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpMemoryData,
  uint32* LulParameterRecordSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC,
  DCM_PRIVATE_DATA)LpNegativeErrorCode);


extern FUNC(Dcm_ReturnReadMemoryType, DCM_CALLOUT_CODE) Dcm_ReadMemory
  (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) pMemoryData);

extern FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_WriteMemory
  (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) pWriteData);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestDownload
  (Dcm_OpStatusType OpStatus,uint8 DataFormatIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint32, AUTOMATIC, DCM_PRIVATE_DATA)LpBlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC,
        DCM_PRIVATE_DATA)LpNegativeErrorCode);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestUpload
  (Dcm_OpStatusType OpStatus,uint8 DataFormatIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint32, AUTOMATIC, DCM_PRIVATE_DATA)LpBlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC,
        DCM_PRIVATE_DATA)LpNegativeErrorCode);
        
#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)
extern FUNC(void, DCM_CALLOUT_CODE) Dcm_Authentication_User_CallOut (
  Dcm_OpStatusType OpStatus, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext, 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

#if (DCM_AUTHENTICATION_ES_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SettingAccessRightsFailedFnc (
  P2VAR(Dcm_CertAuthorizationInfoType, AUTOMATIC, DCM_APPL_DATA) authorization,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DeauthenticationFailedFnc (
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext, 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);
#endif
#endif

#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)

/*******************************************************************************
**                        File transfer function definition                   **
*******************************************************************************/
/* @Trace: SWS_Dcm_91078 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestAddFile(
  Dcm_OpStatusType OpStatus
  , uint16 FilePathAndNameLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) FilePathAndName
  , uint8 DataFormatIdentifier
  , uint64 FileSizeUncompressed
  , uint64 FileSizeCompressed
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) MaxNumberOfBlockLength
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

/* @Trace: SWS_Dcm_91079 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestDeleteFile(
  Dcm_OpStatusType OpStatus
  , uint16 FilePathAndNameLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) FilePathAndName
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

/* @Trace: SWS_Dcm_91080 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestReplaceFile(
  Dcm_OpStatusType OpStatus
  , uint16 FilePathAndNameLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) FilePathAndName
  , uint8 DataFormatIdentifier
  , uint64 FileSizeUncompressed
  , uint64 FileSizeCompressed
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) MaxNumberOfBlockLength
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

/* @Trace: SWS_Dcm_91081 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestReadFile(
  Dcm_OpStatusType OpStatus
  , uint16 FilePathAndNameLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) FilePathAndName
  , uint8 DataFormatIdentifier
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) FileSizeUncompressed
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) FileSizeCompressed
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) MaxNumberOfBlockLength
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

/* @Trace: SWS_Dcm_91082 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestReadDir(
  Dcm_OpStatusType OpStatus
  , uint16 FilePathAndNameLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) FilePathAndName
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) DirInfoLength
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) MaxNumberOfBlockLength
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestResumeFile(
  Dcm_OpStatusType OpStatus
  , uint16 FilePathAndNameLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) FilePathAndName
  , uint8 DataFormatIdentifier
  , uint64 FileSizeUncompressed
  , uint64 FileSizeCompressed
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) MaxNumberOfBlockLength
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) FilePosition
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);
/* @Trace: SWS_Dcm_91083 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_WriteFile(
  Dcm_OpStatusType OpStatus
  , uint64 DataLength
  , P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) Data
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

/* @Trace: SWS_Dcm_91085 */
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ReadFileOrDir(
  Dcm_OpStatusType OpStatus
  , P2VAR(uint64, AUTOMATIC, DCM_APPL_DATA) DataLength
  , P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data
  , P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

#endif /* (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON) */

#define DCM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif /* End DCM_CALLOUTS_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
