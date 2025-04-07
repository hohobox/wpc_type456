/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspMemoryServices.h                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspMemoryServices                            **
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
** 2.11.0.0  31-Jan-2024   Suyon Kim      #44893                              **
**                                                                            **
** 2.10.0.0  28-Dec-2023   Suyon Kim      #42075                              **
**                                                                            **
** 2.3.2.0   05-Nov-2020   EunKyung Kim   #26432                              **
**                                                                            **
** 1.0.1     10-08-2015    Youngjin Yun   #2977                               **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSPMEMORYSERVICES_H
#define DCM_DSPMEMORYSERVICES_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
 
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadMemoryByAddress(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE)Dcm_DcmReadMemoryCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmWriteMemoryByAddress(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmWriteMemoryCall
  (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestDownLoad(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmDownLoadCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestUpLoad(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmUpLoadCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmTransferData(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern  FUNC(void, DCM_CODE) Dcm_DownLoadTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
extern  FUNC(void, DCM_CODE)Dcm_UpLoadTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
  
#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
extern  FUNC(void, DCM_CODE)Dcm_WriteFileTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
extern  FUNC(void, DCM_CODE)Dcm_ReadFileOrDirTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_CallWriteFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_CallReadFileOrDirFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);
#endif
#endif

#if(DCM_TRANSFER_EXIT_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestTransferExit(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern  FUNC(void, DCM_CODE)Dcm_RequestTransferExitCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif 

#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_InitFileInfo(void);
extern FUNC(void, DCM_CODE) Dcm_InitTransferData(void);

FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestFileTransfer(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmFileTransferCall(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NrcPtrType pErrorCode);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_CallFileTransferFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

extern FUNC(void, DCM_CODE) Dcm_DataToResponseParameter(
  uint8 numOfByte,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pInData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pOutData);

extern FUNC(uint16, DCM_CODE) Dcm_RequestParameterToUint16(
  uint8 numOfByte,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData);

extern FUNC(uint64, DCM_CODE) Dcm_RequestParameterToUint64(
  uint8 numOfByte,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData);

extern FUNC(void, DCM_CODE) Dcm_Uint64ToResponseParameter(
  uint8 numOfByte,
  uint64 resData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pResData);

extern FUNC(boolean, DCM_CODE) Dcm_CheckParameterByteLen(
  uint8 numOfByte,
  uint64 value);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/ 
#endif /* DCM_DSPMEMORYSERVICES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
