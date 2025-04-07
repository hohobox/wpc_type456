/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspMemoryServices.c                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the definitions for UDS services           **
**              implemented by DSP layer of Dcm module                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                 Description                     **
********************************************************************************
** 2.14.0.0  30-Sep-2024   Suyon Kim          #48600 #48642                   **
**                                                                            **
** 2.12.0.0  17-Apr-2024   Suyon Kim         #44568 #45079                    **
**                                                                            **
** 2.10.0.0  28-Dec-2023   Suyon Kim         #42075                           **
**                                                                            **
** 2.6.1.0   13-Jan-2023   DanhTQ1            #38699                          **
**                                                                            **
** 2.5.1.0   12-Aug-2020   LanhLT         Fix UNECE #35929                    **
**                                                                            **
** 2.3.8.0   26-04-2021    S.K     Park      #27996                           **
**                                                                            **
** 2.3.7.0   08-04-2021    EunKyung.Kim      #29178                           **
**                                                                            **
** 2.3.5.0   16-02-2021    EunKyung.Kim      #28368                           **
**                                                                            **
** 2.3.4.0   28-Jan-2021   EunKyung Kim      #27909                           **
**                                                                            **
** 1.0.6     05-11-2020    EunKyung Kim      #26432                           **
**                                                                            **
** 1.0.5     20-03-2020    EunKyung Kim      #21905, #22523                   **
**                                                                            **
** 1.0.4     23-07-2019    Y.S     Jeon      #17172                           **
**                                                                            **
** 1.0.3     12-06-2017    Jin     Jung       #5428                           **
**                                                                            **
** 1.0.2     03-03-2016    Sungeol Baek       #3754                           **
**                                                                            **
** 1.0.1     16-04-2015    Sungeol Baek       #2171                           **
**                                                                            **
** 1.0.0     09-01-2013    Autron             Initial version                 **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_Ram.h"
#include "Dcm_DsdInternal.h"
#include "Dcm_DslInternal.h"
#include "Dcm_CallOuts.h"
#include "Dcm_DspMemoryServices.h"
#include "Dcm_Config.h"

#if(DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**              Common data for request file transfer services                **
*******************************************************************************/
#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)

typedef enum
{
  DCM_UNDEFINED_FILE_OPERATION,
  DCM_ADD_FILE,
  DCM_DELETE_FILE,
  DCM_REPLACE_FILE,
  DCM_READ_FILE,
  DCM_READ_DIR,
  DCM_RESUME_FILE,
} Dcm_FileOperationType;

/* polyspace +1 MISRA2012:2.4 [Justified:Low] Justify with annotations */
typedef struct STagDcm_FileInfoType
{
  uint64 blockLength;
  uint64 fileSizeCompressed;
  uint64 fileSizeUnCompressedOrDirInfoLength;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pFilePathAndName;
  uint16 filePathAndNameLen;
  Dcm_FileOperationType operationType;
  uint8 dataFormatId;
  uint64 transferfilePosition;
} Dcm_FileInfoType;

typedef struct 
{
  uint64 fileBlockLength;
  uint64 fileDataLen;
  uint64 remainFileSize;
  uint64 filePosition;

  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pDataRead;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pDataWrite;
  
  uint32 dataBlockLength;
  uint32 remainMemSize;
  uint32 currentMemAddr;
  uint8 memoryId;
} Dcm_TransferDataType;

typedef P2VAR(Dcm_FileInfoType, AUTOMATIC, DCM_APPL_DATA) Dcm_FileInfoPtrType;

/*******************************************************************************
**                      Variable Definitions                                  **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
static VAR(Dcm_FileInfoType, DCM_VAR) Dcm_FileInfo;

static VAR(Dcm_TransferDataType, DCM_VAR) Dcm_TransferData;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#if (DCM_DEV_ERROR_DETECT == STD_ON)
static FUNC(boolean, DCM_CODE) Dcm_CheckBlockLength(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

static FUNC(uint32, DCM_CODE) Dcm_GetMaxBufferSize(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
static FUNC(void, DCM_CODE) Dcm_SetFileInfo(
  Dcm_FileInfoPtrType pFileInfo);

static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckFileSizeParameterLength(
  uint8 fileSizeParameterLen);

static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckFileTransferRequest(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckAddOrRepOrResumeFileRequest(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckDelFileOrReadDirRequest(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckReadFileRequest(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessAddFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessDeleteFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessReplaceFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessReadFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessReadDirFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessResumeFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode);

static FUNC(boolean, DCM_CODE) Dcm_CheckFileTransferInfo(void);

static FUNC(boolean, DCM_CODE) Dcm_CheckAddOrRepOrResumeFileInfo(void);

static FUNC(boolean, DCM_CODE) Dcm_CheckReadFileInfo(void);

static FUNC(boolean, DCM_CODE) Dcm_CheckReadDirInfo(void);

static FUNC(void, DCM_CODE) Dcm_UpdateFileTransferResponse(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(void, DCM_CODE) Dcm_UpdateAddOrRepFileResponse(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(void, DCM_CODE) Dcm_UpdateDeleteFileResponse(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(void, DCM_CODE) Dcm_UpdateReadFileResponse(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(void, DCM_CODE) Dcm_UpdateReadDirResponse(
  Dcm_MsgContextPtrType pMsgContext);

FUNC(void, DCM_CODE) Dcm_UpdateResumeFileResponse(
  Dcm_MsgContextPtrType pMsgContext);

static FUNC(void, DCM_CODE) Dcm_TriggerFileTransferProcess(void);
#endif /* END OF REQUEST FILE TRANSFER */

/*******************************************************************************
** Function Name        : Dcm_DcmReadMemoryByAddress                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : ReadMemoryByAddress service is used to get data     **
**                        from requested memory address.                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : none                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : none                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Dcm_ServiceForcePendingStatus                       **
**                        Dcm_GddOpStatus , Dcm_GddNegRespError               **
**                        Dcm_GusMaxNoOfForceRespPend,Dcm_GaaReadMemRngConfig **
**                        Dcm_GaaAddressAndLengthFormatIds ,                  **
**                        Dcm_GulRMBAMemoryAddress, Dcm_GaaModeRuleConfig     **
**                        Function(s) invoked :                               **
**                        Dcm_DsdValidateSecurity, Dcm_DsdModeRuleCheck ,     **
**                        Dcm_DcmReadMemoryCall, Dcm_ExternalSetNegResponse , **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"
#if(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadMemoryByAddress(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucMemoryIdentifier;
  uint8 LucAddrLenForId = (uint8)0x00;
  uint8 LucMemAdrBytes;
  uint8 LucMemSizeBytes;
  uint8 LucLoopVar;
  /*if memory range security reference is configured or mode rule is configured, ened to check results of search*/
  #if((DCM_READMEMORY_RANGE_SECURITY_REF == STD_ON)||(DCM_MODE_RULE == STD_ON) )
  boolean LblSearchResult;
  #endif
  boolean LblItemFound;
  boolean LblReadMemoryApiInvoked;

  /* Set Force pending status flag to False */
  Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus =
    DCM_FALSE;
  /* Initialize global variables */
  Dcm_GddOpStatus = DCM_INITIAL;
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
  /* Initialize local variables */
  LulMemoryAddress = DCM_ZERO;
  LulMemorySize = DCM_ZERO;
  LblReadMemoryApiInvoked = DCM_FALSE;
  LblItemFound = DCM_FALSE;
  
  /*if memory range security reference is configured or mode rule is configured, ened to check results of search*/
  #if((DCM_READMEMORY_RANGE_SECURITY_REF == STD_ON)||(DCM_MODE_RULE == STD_ON) )
  LblSearchResult=DCM_TRUE;
  #endif

  if (
    (pMsgContext == NULL_PTR) ||
    (pMsgContext->reqData == NULL_PTR)
  )
  {
    /* TODO : Det Error */
  }
  else
  {
    /* Get data from request */
    LpReqResData = pMsgContext->reqData;

    /*Get the addressAndLengthFormatIdentifier from the request*/
    LucAddrLenForId = pMsgContext->reqData[0];
    
    /* Get memory address and size bytes from AddressAndLengthFormatIdentifier */
    LucMemAdrBytes = (LucAddrLenForId & DCM_SIG_BYTE_MASK_VALUE);
    LucMemSizeBytes = ((LucAddrLenForId & DCM_SIG_SIZE_MASK_VALUE) >> DCM_FOUR);

    #if(DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != DCM_ZERO)
    /* Check for configured Address and length format identifier */
    for(
      LucLoopVar = DCM_ZERO;
      LucLoopVar < Dcm_Num_Of_Address_Length_Format_ID_Config; 
      LucLoopVar++)
    {
      if(LucAddrLenForId == Dcm_GaaAddressAndLengthFormatIds[LucLoopVar])
      {
        LblItemFound = DCM_TRUE;
        break;
      }
    }
    #else
    LblItemFound = DCM_TRUE;
    #endif

    /*Check addressAndLengthFormatIdentifier is valid*/
    if(LblItemFound == DCM_TRUE)
    {
      /* Check Requested Data length is valid or not */
      if(pMsgContext->reqDataLen ==
        (uint32)((uint32)LucMemAdrBytes + (uint32)LucMemSizeBytes + (uint32)0x01))
      {
        LucLoopVar = DCM_ZERO;
        /* Get Memory address from request */
        do
        {         
          LulMemoryAddress = LulMemoryAddress << DCM_EIGHT;
          LpReqResData = &LpReqResData[1u];
  
          LulMemoryAddress |= *(LpReqResData);
          LucLoopVar++;
        }
        while(LucLoopVar < LucMemAdrBytes);

        LucLoopVar = DCM_ZERO;
      
        /*Get memory size from the request*/
        do
        {

          LulMemorySize = LulMemorySize << DCM_EIGHT;
          LpReqResData = &LpReqResData[1u];       
          LulMemorySize |= *(LpReqResData);            

          LucLoopVar++;
        }
        while(LucLoopVar < LucMemSizeBytes);

        /* Variable To break The Loop*/
        LblItemFound = DCM_FALSE;

        /* Check Current memory is within memory Range Configures */
        for(LucLoopVar = 0U; LucLoopVar < Dcm_Total_Num_Read_Memory_Configured; LucLoopVar++)
        {
        /*reqLowAddr and reqHighAddr range should be 0 .. 4294967294, 
        so the value of (LulMemoryAddress + (uint32)LulMemorySize) - (uint32)1U) can not be over uint32*/
          uint32 reqHighAddr = (LulMemoryAddress + (uint32)LulMemorySize) - (uint32)1U;
          uint32 reqLowAddr = LulMemoryAddress;
          if ((reqLowAddr  >= Dcm_GaaReadMemRngConfig[LucLoopVar].ulReadMemRngLow) &&
              (reqHighAddr <= Dcm_GaaReadMemRngConfig[LucLoopVar].ulReadMemRngHigh))
          {
            LblItemFound = DCM_TRUE;
            break;
          }
        }

        if(LblItemFound == DCM_TRUE)
        {
          if(LucMemSizeBytes == DCM_ONE)
          {
            /* check memory size is valid or not */
			/* LulMemorySize+SID should be euqal to or less than pMsgContext->resMaxDataLen  */
            if(((LulMemorySize+1) > pMsgContext->resMaxDataLen) || (LulMemorySize < DCM_ONE))
            {
              /* set NRC RequestOutOfRange */
              Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
              LblItemFound = DCM_FALSE;
            }
            else
            {
              /* Do Nothing */
            }
          }

          if(DCM_TRUE == LblItemFound)
          {
            /* Get configured Memory range */
            #if(DCM_READMEMORY_RANGE_SECURITY_REF == STD_ON)
            if(Dcm_GaaReadMemRngConfig[LucLoopVar].pReadMemRngSec != NULL_PTR)
            {
              /* Invoke function for security validation */
              LblSearchResult = Dcm_DsdValidateSecurity(
                Dcm_GaaReadMemRngConfig[LucLoopVar].pReadMemRngSec, 
                Dcm_GaaReadMemRngConfig[LucLoopVar].ucReadMemSecCount);
            }
            else
            {
              LblSearchResult = DCM_TRUE;
            }

            /* Check is the current Security level supported by the service Id */
            if(LblSearchResult == DCM_TRUE)
            #endif
            {
              #if(DCM_MODE_RULE == STD_ON)
              if(Dcm_GaaReadMemRngConfig[LucLoopVar].blModeRuleConfigured == DCM_TRUE)
              {
                LblSearchResult = Dcm_DsdModeRuleCheck
                  (Dcm_GaaReadMemRngConfig[LucLoopVar].ucDIDmoderuleArrayindex);
              }

              if(LblSearchResult != DCM_TRUE)
              {
                #if(DCM_DSP_MODE_RULE_NRC == STD_ON)
                Dcm_GddNegRespError = 
                  Dcm_GaaModeRuleConfig[Dcm_GaaReadMemRngConfig[LucLoopVar].ucDIDmoderuleArrayindex].ucNRCType;
                #else
                Dcm_GddNegRespError = DCM_E_CONDITIONSNOTCORRECT;
                #endif              
              }
              else
              #endif              
              {
                #if(DCM_USE_MEMORY_ID_ENABLE == STD_ON)
                if(Dcm_GaaReadMemRngConfig[LucLoopVar].blUseMemoryValue == DCM_TRUE)
                {
                  /* Get configured memory identifier */
                  LucMemoryIdentifier = Dcm_GaaReadMemRngConfig[LucLoopVar].ucReadMemoryIdentifier;
                }
                else
                #endif
                {
                  /* Get configured memory identifier */
                  LucMemoryIdentifier = DCM_ZERO;
                }
                /* Update Dcm_GulRMBAMemoryAddress */
                Dcm_GulRMBAMemoryAddress = LulMemoryAddress;
                /* Update Dcm_GusRMBAMemorySize */
                Dcm_GulRMBAMemorySize = LulMemorySize;
                /* Update Dcm_GucRMBAMemoryIdentifier */
                Dcm_GucRMBAMemoryIdentifier = LucMemoryIdentifier;
                LblReadMemoryApiInvoked = DCM_TRUE;
                /* Call to Dcm_ReadMemory() to get the data record */
                Dcm_DcmReadMemoryCall(pMsgContext);
              }
            }
            #if(DCM_READMEMORY_RANGE_SECURITY_REF == STD_ON)
            else
            {
              /* Report the Security Access Denied  NRC */
              Dcm_GddNegRespError = DCM_E_SECURITYACCESSDENIED;
            }
            #endif
          }
          else
          {
            /* Do Nothing */
          }
        }
        else
        {
          /* Report the Request out of range NRC Because Memory Address
            Not With in Specified Memory Range */
          Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
        }
      }
      else
      {
        /* Report the Incorrect message length NRC */
        Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
    }
    else
    {
      /* Report the Request out of range NRC Because of Wrong ALFID */
      Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
    }
    if(LblReadMemoryApiInvoked == DCM_FALSE)
    {
      /* send response from main function */
      Dcm_GblSendResponse = DCM_TRUE;
    }
  }

  DCM_UNUSED(OpStatus);
  /* TODO: return value shall be processed */
  return E_OK;  
}

/*******************************************************************************
** Function Name        : Dcm_DcmReadMemoryCall                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmReadMemoryCall function is used to call      **
**                        Dcm_ReadMemory callout.                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Dcm_GddNegRespError           **
**                        Dcm_MemServicePendingStatus,Dcm_GddOpStatus         **
**                        Dcm_GulRMBAMemoryAddress , Dcm_GusRMBAMemorySize    **
**                        Dcm_ServiceForcePendingStatus,Dcm_GpMsgContext      **
**                        Dcm_GusRMBAMemorySize , Dcm_GusMaxNoOfForceRespPend,**
**                        Dcm_GaaResponseBuf , Dcm_TxRespStatus               **
**                        Function(s) invoked :                               **
**                        Dcm_ReadMemory, Dcm_DslPduRTransmit ,               **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_DcmReadMemoryCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Dcm_ReturnReadMemoryType LddReturnValue = (Dcm_ReturnReadMemoryType)0x00;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucMemoryIdentifier;

  /* Reset Dcm_GddNegRespError */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucReadMemPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus =
    DCM_FALSE;

  /* Get Memory address, memory size and Memory identifier */
  LulMemoryAddress = Dcm_GulRMBAMemoryAddress;
  LulMemorySize = Dcm_GulRMBAMemorySize;
  LucMemoryIdentifier = Dcm_GucRMBAMemoryIdentifier;

  /*  Fix For MISRA 21.1 - BSH  */
  if (
    (pMsgContext == NULL_PTR) || 
    (pMsgContext->resData == NULL_PTR) ||
    (pMsgContext->reqData == NULL_PTR)
  )
  {
    /* TODO : Det Error */    
    Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
  }
  else
  {
    /* Invoke callout Dcm_ReadMemory  */
    /* polyspace-begin MISRA-C3:2.1 MISRA-C3:14.3 DEFECT:DEAD_CODE [Justified:Low] "return value of Dcm_readMemory is depends on the User. User need to fill the Dcm_readMemory function,
    so the return value is depends on the user.Therefore need to check return value." */
    LddReturnValue = Dcm_ReadMemory(Dcm_GddOpStatus, LucMemoryIdentifier,
      LulMemoryAddress, LulMemorySize, pMsgContext->resData);  
  
    /* Check for OpStatus */
    if(Dcm_GddOpStatus != DCM_CANCEL)
    {
      if(LddReturnValue == DCM_READ_OK)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;

        /* Update response data length */
        pMsgContext->resDataLen = LulMemorySize;
      }      
      else if(LddReturnValue == DCM_READ_PENDING)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_PENDING;
        /* Set response pending flag to True */
        Dcm_MemServicePendingStatus.ucReadMemPendingStatus
          = DCM_TRUE;
      }
      else if(LddReturnValue == DCM_READ_FORCE_RCRRP)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
        /* Set Force response pending flag to True */
        Dcm_ServiceForcePendingStatus.
        ucReadMemForcePendingStatus = DCM_TRUE;
        /* Update Dcm_GusMaxNoOfForceRespPend */
        Dcm_GusMaxNoOfForceRespPend++;
        /* Check if Dcm_GusMaxNoOfForceRespPend reaches configured limit */
        /* 0xFF : limit threshold is unused */
        if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
        {
          /* Update Dcm_GddOpStatus */
          Dcm_GddOpStatus = DCM_INITIAL;
          /* Update Dcm_GddNegRespError */
          Dcm_GddNegRespError = DCM_E_GENERALREJECT;
            Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
          /* Invoke callout Dcm_ReadMemory with OpStatus as DCM_CANCEL */
          (void)Dcm_ReadMemory(DCM_CANCEL, LucMemoryIdentifier,
            LulMemoryAddress, LulMemorySize, pMsgContext->resData);

          /* Set Force response pending flag to false */
          Dcm_ServiceForcePendingStatus.
            ucReadMemForcePendingStatus  = DCM_FALSE;
        }
        else
        {

        }
      }
      else
      {
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
      }
      /* polyspace-end MISRA-C3:2.1 MISRA-C3:14.3 DEFECT:DEAD_CODE [Justified:Low] "return value of Dcm_readMemory is depends on the User. User need to fill the Dcm_readMemory function,
    so the return value is depends on the user.Therefore need to check return value." */
    }
  }

  /* To send positive and negative response */
  if (
    (Dcm_MemServicePendingStatus.ucReadMemPendingStatus == DCM_FALSE) && 
    (Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus == DCM_FALSE) && 
    (Dcm_GddOpStatus != DCM_CANCEL)
  )
  {
    Dcm_GddOpStatus = DCM_INITIAL;

    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  /* To send response pending */
  /* polyspace-begin DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus value is depends on the return value of Dcm_Writememory
  . so It is depends on the user. Therefore Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus value can be true by user." */
  else if(Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] = ((pMsgContext->idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;
    
    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
   /* polyspace-end DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus value is depends on the return value of Dcm_Writememory
  . so It is depends on the user. Therefore Dcm_ServiceForcePendingStatus.ucReadMemForcePendingStatus value can be true by user." */
}
#endif

/*******************************************************************************
** Function Name        : Dcm_DcmWriteMemoryByAddress                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmWriteMemoryByAddress service is used to      **
**                        write data using a physical memory address          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :Dcm_GusMaxNoOfForceRespPend,    **
**                        Dcm_GddNegRespError , Dcm_GddOpStatus,              **
**                        Dcm_GaaAddressAndLengthFormatIds ,Dcm_GpWriteData   **
**                        Dcm_GucMemAddrSizeBytes, Dcm_GaaWriteMemRngConfig   **
**                        Dcm_GulWriteMemoryAddress, Dcm_GusWriteMemorySize   **
**                        Dcm_GucMemoryIdentifier, Dcm_GaaModeRuleConfig      **
**                        Function(s) invoked :                               **
**                        Dcm_DsdValidateSecurity, Dcm_DsdModeRuleCheck ,     **
**                        Dcm_DcmWriteMemoryCall, Dcm_ExternalSetNegResponse ,**
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmWriteMemoryByAddress(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData;

  #if((DCM_MODE_RULE  ==  STD_ON) && (DCM_DSP_MODE_RULE_NRC == STD_ON))
  P2CONST(Dcm_ModeRuleConfigType,  AUTOMATIC,  DCM_APPL_CONST)
    LpModeRule;
  #endif
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucAddrLenForId = (uint8)0x00;
  uint8 LucMemAdrBytes;
  uint8 LucMemSizeBytes;
  uint8 LucMemoryIdentifier;
  uint8 LucLoopVar;
  boolean LblItemFound;
  
  /*if memory range security reference is configured or mode rule is configured, ened to check results of search*/
  #if((DCM_WRITEMEMORY_RANGE_SECURITY_REF == STD_ON)||(DCM_MODE_RULE == STD_ON) )
  boolean LblSearchResult;
  #endif
  boolean LblWriteMemoryApiInvoked;

  /* Initialize local variables */
  LulMemoryAddress = DCM_ZERO;
  LulMemorySize = DCM_ZERO;
  LblItemFound = DCM_FALSE;
  LblWriteMemoryApiInvoked = DCM_FALSE;
  /* Resetting global variables */
  Dcm_GusMaxNoOfForceRespPend = DCM_E_POSITIVERESPONSE;
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GddOpStatus = DCM_INITIAL;

  /*if memory range security reference is configured or mode rule is configured, ened to check results of search*/
  #if((DCM_WRITEMEMORY_RANGE_SECURITY_REF == STD_ON)||(DCM_MODE_RULE == STD_ON) )
  LblSearchResult=DCM_TRUE;
  #endif

  if (
    (pMsgContext == NULL_PTR) || 
    (pMsgContext->resData == NULL_PTR) ||
    (pMsgContext->reqData == NULL_PTR)
  )
  {
    /* TODO : Det Error */    
    Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
  }
  else
  {
    /* Get data from request */
    LpReqResData = pMsgContext->reqData;
  
    /* Get the addressAndLengthFormatIdentifier from the request */
    LucAddrLenForId = *(LpReqResData);
  
  
    #if(DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != DCM_ZERO)
    /* Check for configured Address and length format identifier */
    for(LucLoopVar = DCM_ZERO;
      LucLoopVar < Dcm_Num_Of_Address_Length_Format_ID_Config; LucLoopVar++)
    {
      if(LucAddrLenForId == Dcm_GaaAddressAndLengthFormatIds[LucLoopVar])
      {
        LblItemFound = DCM_TRUE;
        break;
      }
    }
    #else
    LblItemFound = DCM_TRUE;
    #endif

    if(LblItemFound == DCM_TRUE)
    {
      /* Get memory address and memory size bytes from
      AddressAndLengthFormatIdentifier*/
      LucMemAdrBytes = (LucAddrLenForId & DCM_SIG_BYTE_MASK_VALUE);
      LucMemSizeBytes = ((LucAddrLenForId & DCM_SIG_SIZE_MASK_VALUE) >> DCM_FOUR);

      Dcm_GucMemAddrSizeBytes = LucMemAdrBytes + LucMemSizeBytes + DCM_ONE;

      LucLoopVar = DCM_ZERO;

      /* Get Memory Address from the request */
      do
      {
        LulMemoryAddress = LulMemoryAddress << DCM_EIGHT;
    
        LpReqResData = &LpReqResData[1u];
        
        LulMemoryAddress |= *(LpReqResData);
        LucLoopVar++;
      }
      while(LucLoopVar < LucMemAdrBytes);

      LucLoopVar = DCM_ZERO;
    
      /* Get Memory Size from the request */
      do
      {       
        LulMemorySize = LulMemorySize << DCM_EIGHT;
    
        LpReqResData = &LpReqResData[1u];
        
        LulMemorySize |= *(LpReqResData);
        LucLoopVar++;    
      }
      while(LucLoopVar < LucMemSizeBytes);


      LpReqResData = &LpReqResData[1u];
      Dcm_GpWriteData = LpReqResData;

      /* Check length of request is valid or not */
      if(pMsgContext->reqDataLen == (uint32)((uint32)LulMemorySize + (uint32)LucMemAdrBytes + 
      (uint32)LucMemSizeBytes + (uint32)0x01))
      {
        /* Variable To break The Loop */
        LblItemFound = DCM_ZERO;

        /* Check Current memory is with in memory range configures */
        for(LucLoopVar = 0U; LucLoopVar < Dcm_Total_Num_Write_Memory_Configured; LucLoopVar++)
        { 
          /*reqLowAddr and reqHighAddr range should be 0 .. 4294967294, 
          so the value of (LulMemoryAddress + (uint32)LulMemorySize) - (uint32)1U) can not be over uint32*/
          if (((LulMemoryAddress + (uint32)LulMemorySize) - (uint32)1U)  < 0xFFFFFFFFU)
          {
            uint32 reqHighAddr = (LulMemoryAddress + (uint32)LulMemorySize) - (uint32)1U;
            uint32 reqLowAddr = LulMemoryAddress;
            if ((reqLowAddr  >= Dcm_GaaWriteMemRngConfig[LucLoopVar].ulWriteMemRngLow) &&
                (reqHighAddr <= Dcm_GaaWriteMemRngConfig[LucLoopVar].ulWriteMemRngHigh))
            {
              LblItemFound = DCM_TRUE;
              break;
            }
          }
        }

        if(DCM_TRUE == LblItemFound)
        {
          /* Get configured memory range */
          /* Check security for memory range is configured */
          #if(DCM_WRITEMEMORY_RANGE_SECURITY_REF == STD_ON)
          if(Dcm_GaaWriteMemRngConfig[LucLoopVar].pWriteMemRngSec != NULL_PTR)
          {
            /* Invoke function for security validation */
            LblSearchResult = Dcm_DsdValidateSecurity(
              Dcm_GaaWriteMemRngConfig[LucLoopVar].pWriteMemRngSec,
                Dcm_GaaWriteMemRngConfig[LucLoopVar].ucWriteMemSecCount);
          }
          else
          {
            LblSearchResult = DCM_TRUE;
          }

          /* check is current security level supported by the service ID */
          if(LblSearchResult == DCM_TRUE)
          #endif
          {
            #if(DCM_MODE_RULE  ==  STD_ON)
            if(Dcm_GaaWriteMemRngConfig[LucLoopVar].blModeRuleConfigured == DCM_TRUE)
            {
              LblSearchResult = Dcm_DsdModeRuleCheck
                (Dcm_GaaWriteMemRngConfig[LucLoopVar].ucDIDmoderuleArrayindex);
            }

            if(LblSearchResult  ==  DCM_TRUE)
            #endif
            {          
              /* Fixed by youngjin yun 2014.10.24 */
              #if(DCM_USE_MEMORY_ID_ENABLE == STD_ON)
              if(Dcm_GaaWriteMemRngConfig[LucLoopVar].blUseMemoryValue == DCM_TRUE)
              {
                /* Get configured memory identifier */
                LucMemoryIdentifier = 
                  Dcm_GaaWriteMemRngConfig[LucLoopVar].ucWriteMemoryIdentifier;
              }
              else
              #endif
              {
                /* Get configured memory identifier */
                LucMemoryIdentifier = DCM_ZERO;
              }

              /* Update Dcm_GulWriteMemoryAddress */
              Dcm_GulWriteMemoryAddress = LulMemoryAddress;
              /* Update Dcm_GusWriteMemorySize */
              Dcm_GulWriteMemorySize = LulMemorySize;
              /* Update Dcm_GucMemoryIdentifier */
              Dcm_GucMemoryIdentifier = LucMemoryIdentifier;
              LblWriteMemoryApiInvoked = DCM_TRUE;
              /* call to Dcm_DcmWriteMemoryCall to get data record */
              Dcm_DcmWriteMemoryCall(pMsgContext);
            }
            #if(DCM_MODE_RULE  ==  STD_ON)
            /*  Store  the  NRC  error  and  set  the  error  flag  */
            else
            {
              #if(DCM_DSP_MODE_RULE_NRC == STD_ON)
              LpModeRule  =  &Dcm_GaaModeRuleConfig
                  [Dcm_GaaWriteMemRngConfig[LucLoopVar].ucDIDmoderuleArrayindex];
              Dcm_GddNegRespError =  LpModeRule->ucNRCType;
              #else
              /* Update Negative Response Code */
              Dcm_GddNegRespError  =  DCM_E_CONDITIONSNOTCORRECT;
              #endif
            }
            #endif
          }
          #if(DCM_WRITEMEMORY_RANGE_SECURITY_REF == STD_ON)
          else
          {
            /* 
              set NRC Security access denied because security level
                                is not supported by service ID */
            Dcm_GddNegRespError = DCM_E_SECURITYACCESSDENIED;
          }
          #endif
        }
        else
        {
          /* Redmine #1677 ,Modified by youngjin.yun
            set NRC RequestOutOfRange because (memory address + size) is not
            with in the range */
          Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
        }
      }
      else
      {
        /* Set IncorrectMessageLengthOrInvalidFormatId NRC */
        Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }

    }
    else
    {
      /* Set NRC RequestOutOfRange because of wrong ALFID  */
      Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
    }
  }

  if(LblWriteMemoryApiInvoked == DCM_FALSE)
  {
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }

  DCM_UNUSED(OpStatus);
  
  /* TODO: return value shall be processed */
  return E_OK;  
}

/*******************************************************************************
** Function Name        : Dcm_DcmWriteMemoryCall                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmWriteMemoryCall function is used to call     **
**                        Dcm_WriteMemory call out.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Dcm_GddNegRespError,           **
**                        Dcm_MemServicePendingStatus ,Dcm_GddOpStatus        **
**                        Dcm_GulWriteMemoryAddress ,Dcm_GusWriteMemorySize , **
**                        Dcm_GucMemoryIdentifier, Dcm_GucMemAddrSizeBytes    **
**                        Dcm_ServiceForcePendingStatus ,                     **
**                        Dcm_GusMaxNoOfForceRespPend , Dcm_GaaResponseBuf ,  **
**                        Dcm_TxRespStatus                                    **
**                        Function(s) invoked :                               **
**                        Dcm_WriteMemory, Dcm_DslPduRTransmit ,              **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_DcmWriteMemoryCall(
 P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Dcm_ReturnWriteMemoryType LddReturnValue;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucMemoryIdentifier;
  uint8 LucLoopVar;

  if (
    (pMsgContext == NULL_PTR) || 
    (pMsgContext->resData == NULL_PTR) ||
    (pMsgContext->reqData == NULL_PTR)
  )
  {
    /* TODO : Det Error */    
    Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
  }
  else
  {
    /* Resetting Dcm_GddNegRespError */
    Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;

    /* Set response pending flag to False */
    Dcm_MemServicePendingStatus.ucWriteMemPendingStatus  =  DCM_FALSE;
    /* Set ForceRcrrp Pending flag to False */
    Dcm_ServiceForcePendingStatus.ucWriteMemForcePendingStatus = DCM_FALSE;

    /* Get memory address, memory size and memory identifier */
    LulMemoryAddress = Dcm_GulWriteMemoryAddress;
    LulMemorySize = Dcm_GulWriteMemorySize;
    LucMemoryIdentifier = Dcm_GucMemoryIdentifier;

    /* Invoke callout Dcm_Write Memory  */
    /* polyspace-begin DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "return value of Dcm_readMemory is depends on the User. User need to fill the Dcm_readMemory function, and need to check return value. SWP only provide samples." */
    LddReturnValue = Dcm_WriteMemory(Dcm_GddOpStatus, LucMemoryIdentifier,
      LulMemoryAddress, LulMemorySize, Dcm_GpWriteData);
    /* check for OpStatus */
    if(Dcm_GddOpStatus != DCM_CANCEL)
    {
      if(LddReturnValue == DCM_WRITE_OK)
      {
        /* Update response data length */
        pMsgContext->resDataLen = Dcm_GucMemAddrSizeBytes;
        /* send positive response */
        LucLoopVar = DCM_ZERO;
        /* Updat response data */
        do
        {
          pMsgContext->resData[LucLoopVar] = pMsgContext->reqData[LucLoopVar];
          LucLoopVar++;
        }
        while(LucLoopVar < Dcm_GucMemAddrSizeBytes);
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
      }
      else if(LddReturnValue == DCM_WRITE_PENDING)
      {
      /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_PENDING;
        /* Set response pending flag to True */
        Dcm_MemServicePendingStatus.ucWriteMemPendingStatus =
          DCM_TRUE;
      }
      else if(LddReturnValue == DCM_WRITE_FORCE_RCRRP)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
        /* Set Force responsepending flag to True */
        Dcm_ServiceForcePendingStatus.
          ucWriteMemForcePendingStatus = DCM_TRUE;
        /* Update Dcm_GusMaxNoOfForceRespPend */
        Dcm_GusMaxNoOfForceRespPend++;
        /* Check for Dcm_GusMaxNoOfForceRespPend */
        /* 0xFF : limit threshold is unused */
        if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
        {
          /* Update Dcm_GddOpStatus */
          Dcm_GddOpStatus = DCM_INITIAL;
          /* Update Dcm_GddNegRespError */
          Dcm_GddNegRespError = DCM_E_GENERALREJECT;
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
          /* Invoke callout Dcm_WriteMemory  with OpStatus as DCM_CANCEL */
          (void) Dcm_WriteMemory(DCM_CANCEL, LucMemoryIdentifier,
            LulMemoryAddress, LulMemorySize, Dcm_GpWriteData);
          /* Set Force responsepending flag to False */
          Dcm_ServiceForcePendingStatus.
            ucWriteMemForcePendingStatus = DCM_FALSE;
        }
        else
        {

        }
      }
      else
      {
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
      }
      /* polyspace-end DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "return value of Dcm_readMemory is depends on the User. User need to fill the Dcm_readMemory function, and need to check return value. SWP only provide samples." */
    }
  }

  /* To send positive and negative response */
  if((Dcm_MemServicePendingStatus.ucWriteMemPendingStatus ==
    DCM_FALSE) && (Dcm_ServiceForcePendingStatus.
    ucWriteMemForcePendingStatus == DCM_FALSE) && (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  /* To send response pending */
  else if(Dcm_ServiceForcePendingStatus.
        ucWriteMemForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
    /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((pMsgContext->idContext) & (DCM_BIT6_AND_MASK));
    /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_DcmRequestDownLoad                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmRequestDownLoad service is used to request   **
**                        the start of download process.                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :Dcm_GusMaxNoOfForceRespPend,    **
**                        Dcm_GddNegRespError , Dcm_GddOpStatus ,             **
**                        Dcm_GaaAddressAndLengthFormatIds ,Dcm_GulDLMemSize  **
**                        Dcm_GulDLMemAddress,                                **
**                        Dcm_GucDataForId ,                                  **
**                        Function(s) invoked :                               **
**                        Dcm_DcmDownLoadCall, Dcm_ExternalSetNegResponse ,   **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestDownLoad(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint32 LucMemAdrBytes;
  uint32 LucMemSizeBytes;
  uint32 LucAddrLenForId;
  uint8 LucDataForId;
  #if(DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != DCM_ZERO)
  uint8 LucLoopVar;
  #endif
  boolean LblDownLoadApiInvoked;
  boolean LddAddrLenForIdSupported;

  uint32 LulMaxValOfMemSizeBytes = 0;
  uint8 LucMemSizeCount = 0;

  LulMemoryAddress = DCM_ZERO;
  LulMemorySize = DCM_ZERO;
  Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
  LddAddrLenForIdSupported = DCM_FALSE;
  LblDownLoadApiInvoked = DCM_FALSE;

  /* set NRC flag to false */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GddOpStatus = DCM_INITIAL;

  /* Get requested data */
  LpReqResData = pMsgContext->reqData;


  /* Get DataFormatIdentifier from the request */
  LucDataForId = *(LpReqResData);

  /* MISRA Rule        : 17.4
    Message            : Increment or decrement operation
                         performed on pointer
    Reason             : Increment operator not used
                         to achieve better throughput.
    Verification       : However, part of the code
                         is verified manually and
                         it is not having any impact.
  */
  /* Get the addressAndLengthFormatIdentifier from the request */
  LpReqResData++;
  LucAddrLenForId = *(LpReqResData);

  #if(DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != DCM_ZERO)
  /* Check for configured Address and length format identifier */
  for(LucLoopVar = DCM_ZERO;
    LucLoopVar < Dcm_Num_Of_Address_Length_Format_ID_Config; LucLoopVar++)
  {
    if(LucAddrLenForId == Dcm_GaaAddressAndLengthFormatIds[LucLoopVar])
    {
      LddAddrLenForIdSupported = DCM_TRUE;
      /* MISRA Rule        : 13.6
        Message            : Control variable, LucLoopVar,
                             modified in body of loop
        Reason             : Once the search element found, control
                             exiting from the for loop to terminate
                             next iteration.
        Verification       : However, part of the code
                             is verified manually and
                             it is not having any impact.
      */
      /* To Break Loop */
      break;
    }
  }
  #else
  LddAddrLenForIdSupported = DCM_TRUE;
  #endif

  /* check AddressAndLengthFormatIdentifier is valid or not */
  if(LddAddrLenForIdSupported == DCM_TRUE)
  {
    /* Get the number of memory address and memory size bytes */
    LucMemAdrBytes = (LucAddrLenForId & DCM_SIG_BYTE_MASK_VALUE);
    LucMemSizeBytes = ((LucAddrLenForId & DCM_SIG_SIZE_MASK_VALUE) >> DCM_FOUR);

    /* check length of the request is valid or not */
    if(pMsgContext->reqDataLen == (LucMemAdrBytes + LucMemSizeBytes + DCM_TWO))
    {
      /* Get memory address from the request */
      do
      {
        LulMemoryAddress = LulMemoryAddress << DCM_EIGHT;
        /* MISRA Rule        : 17.4
          Message            : Increment or decrement operation
                               performed on pointer
          Reason             : Increment operator not used
                               to achieve better throughput.
          Verification       : However, part of the code
                               is verified manually and
                               it is not having any impact.
        */
        LpReqResData++;
        LulMemoryAddress |= *(LpReqResData);
        LucMemAdrBytes--;
      }
      while(LucMemAdrBytes != DCM_ZERO);
      /* Get memory size from the request */
      do
      {
        LulMemorySize = LulMemorySize << DCM_EIGHT;
        /* MISRA Rule        : 17.4
          Message            : Increment or decrement operation
                               performed on pointer
          Reason             : Increment operator not used
                               to achieve better throughput.
          Verification       : However, part of the code
                               is verified manually and
                               it is not having any impact.
        */
        LpReqResData++;
        LulMemorySize |= *(LpReqResData);
        LucMemSizeBytes--;

        LulMaxValOfMemSizeBytes = LulMaxValOfMemSizeBytes << DCM_EIGHT;
        LucMemSizeCount++;
        LulMaxValOfMemSizeBytes |= (uint32)(0x000000FF);
      }
      while(LucMemSizeBytes != DCM_ZERO);

      if(LulMemorySize < LulMaxValOfMemSizeBytes)
      {
          /* Update Memory Address,Size and Dataformat ID */
          Dcm_GulDLMemAddress = LulMemoryAddress;
          Dcm_GulDLMemSize = LulMemorySize;
          Dcm_GucDataForId = LucDataForId;
          LblDownLoadApiInvoked = DCM_TRUE;
          /* Call to DownLoad call out */
          Dcm_DcmDownLoadCall(pMsgContext);
      }
      else
      {
    	  Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
      }

    }
    else
    {
      /* set NRC IncorrectMessageLengthOrInvalidFormat */
      Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
  }
  else
  {
    /* set NRC RequestOutOfRange  because of wrong ALFID */
    Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
  }
  if(LblDownLoadApiInvoked == DCM_FALSE)
  {
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }

  DCM_UNUSED(OpStatus);
  /* TODO: return value shall be processed */
  return E_OK;  
}

/*******************************************************************************
** Function Name        : Dcm_DcmDownLoadCall                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmDownLoadCall function is used to call        **
**                        Dcm_ProcessRequestDownload callout.                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):Dcm_GddNegRespError,             **
**                        Dcm_MemServicePendingStatus ,                       **
**                        Dcm_ServiceForcePendingStatus ,                     **
**                        Dcm_GulDLMemAddress,Dcm_GulDLMemSize                **
**                        Dcm_GucDataForId ,Dcm_GblDownLoadActive ,           **
**                        Dcm_GblUpLoadActive , Dcm_GucBlockSeqCounter        **
**                        Dcm_GddOpStatus , Dcm_GulBlockLength ,              **
**                        Dcm_GulNumOfBytesToBeTransfer,                      **
**                        Dcm_GusMaxNoOfForceRespPend,                        **
**                        Dcm_TxRespStatus, Dcm_GulBlockLength                **
**                        Dcm_GaaResponseBuf                                  **
**                        Function(s) invoked :                               **
**                        Dcm_ProcessRequestDownload, Dcm_DslPduRTransmit ,   **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_DcmDownLoadCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Dcm_NegativeResponseCodeType LddNegativeErrorCode;
  Std_ReturnType LddReturnValue;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucDataForId;
  uint8 LucIndex;
  uint32 LucTempLength;
  uint32 LulBlockLength = 0;
  uint32 LulTempBlockLength = 0;

  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  LddNegativeErrorCode = DCM_E_POSITIVERESPONSE;
  LulTempBlockLength = Dcm_GetMaxBufferSize(pMsgContext);
  if (LulTempBlockLength != DCM_ZERO)
  {
    LulBlockLength = LulTempBlockLength - 0x02; /* exclude SID and BlockSequenceCounter */
  }

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucDlPendingStatus = DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.ucDlForcePendingStatus =
    DCM_FALSE;


  /* Updating Memory address, size and Data format ID */
  LulMemoryAddress = Dcm_GulDLMemAddress;
  LulMemorySize = Dcm_GulDLMemSize;
  LucDataForId = Dcm_GucDataForId;

  /* Invoke callout Dcm_ProcessRequestDownload */
  /* polyspace-begin DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "LddReturnValue, is depends on the Dcm_ProcessRequestDownload's return value.
        and this value can return various value according to user implementaion. Therefore need to check all return values" */
  LddReturnValue = Dcm_ProcessRequestDownload(Dcm_GddOpStatus, LucDataForId,
    LulMemoryAddress, LulMemorySize, &LulBlockLength, &LddNegativeErrorCode);
  /* Check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == E_OK)
    {
      /* Update Dcm_GblDownLoadActive */
      Dcm_GblDownLoadActive = DCM_TRUE;
      /* Update Dcm_GblUpLoadActive */
      Dcm_GblUpLoadActive = DCM_FALSE;
      
#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
      Dcm_GblWriteFileActive = DCM_FALSE;
      Dcm_GblReadFileActive = DCM_FALSE;
#endif
      /* Update Dcm_GucBlockSeqCounter */
      Dcm_GucBlockSeqCounter = DCM_ONE;
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;
      /* Update Dcm_GulBlockLength */
       Dcm_GulBlockLength = LulBlockLength;
      /* Update Dcm_GulNumOfBytesToBeTransfer */
      Dcm_GulNumOfBytesToBeTransfer = LulMemorySize;

    }
    else if(LddReturnValue == DCM_E_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.ucDlPendingStatus =
        DCM_TRUE;
    }
    else if(LddReturnValue == DCM_E_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.ucDlForcePendingStatus =
        DCM_TRUE;
      /* Update Dcm_GusMaxNoOfForceRespPend */
      Dcm_GusMaxNoOfForceRespPend++;
      /* 0xFF : limit threshold is unused */
      if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALREJECT;
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
        /* Invoke callout Dcm_ProcessRequestDownload with OpStatus DCM_CANCEL */
        (void) Dcm_ProcessRequestDownload(DCM_CANCEL, LucDataForId,
          LulMemoryAddress, LulMemorySize,
            &LulBlockLength, &LddNegativeErrorCode);
        /* Set DownLoad Force pending Status flag to false */
        Dcm_ServiceForcePendingStatus.
        ucDlForcePendingStatus = DCM_FALSE;
      }
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = LddNegativeErrorCode;
    }
  }

  if ((Dcm_MemServicePendingStatus.ucDlPendingStatus == DCM_FALSE) &&
      (Dcm_ServiceForcePendingStatus.ucDlForcePendingStatus == DCM_FALSE) &&  
      (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
    Dcm_TxRespStatus.ucNegResp = DCM_FALSE;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_FALSE;    
    /* Check if the negative response needs to be updated here */
    if (Dcm_GddNegRespError != DCM_E_POSITIVERESPONSE)
    {
      /* Report the NRC to the DSD layer */
      Dcm_ExternalSetNegResponse(pMsgContext, Dcm_GddNegRespError);
    }
    else
    { 
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
      /* Check size of BlockLength - Refer R44 specification
       * SWS_Dcm_01418: If the function call Xxx_ProcessRequestDownload returns a requested buffer length 
       * larger than the supported buffer length of the current protocol connection, 
       * the Dcm shall report the Det error DCM_E_INTERFACE_BUFFER_OVERFLOW */
      if (DCM_TRUE == Dcm_CheckBlockLength(pMsgContext))
      #endif
      {
        /* Update positive response */
        if (Dcm_GulBlockLength <= 0x000000FF)
        {
          LucTempLength = 0x01;
        }
        else if (Dcm_GulBlockLength <= 0x0000FFFF)
        {
          LucTempLength = 0x02;
        }
        else if (Dcm_GulBlockLength <= 0x00FFFFFF)
        {
          LucTempLength = 0x03;
        }
        else
        {
          LucTempLength = 0x04;
        }

        /* Length of positive response (not including response SID) */
        pMsgContext->resDataLen = LucTempLength + 1;

        /* lengthFormatIdentifier */
        pMsgContext->resData[0U] = (uint8)LucTempLength << 4U;

        /* Get value of maxNumberOfBlockLength */
        for (LucIndex = 1; LucIndex < (LucTempLength + 1); LucIndex++)
        {
          pMsgContext->resData[LucIndex] = (uint8)((Dcm_GulBlockLength) >> (8*(LucTempLength - LucIndex)));
        }
      }
    }

    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  else if(Dcm_ServiceForcePendingStatus.ucDlForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((pMsgContext->idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;      
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;

    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
  /* polyspace-end DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "LddReturnValue is depends on the Dcm_ProcessRequestDownload's return value.
        and this value can return various value according to user implementaion. Therefore need to check all return values" */
}
#endif

/*******************************************************************************
** Function Name       : Dcm_DcmRequestUpLoad                                 **
**                                                                            **
** Service ID          : NA                                                   **
**                                                                            **
** Description         : Dcm_DcmRequestUpLoad service is used to request      **
**                       Start of Upload process                              **
**                                                                            **
** Sync/Async          : Synchronous                                          **
**                                                                            **
** Re-entrancy         : Non Reentrant                                        **
**                                                                            **
** Input Parameters    : None                                                 **
**                                                                            **
** InOut parameter     : pMsgContext                                          **
**                                                                            **
** Output Parameters   : None                                                 **
**                                                                            **
** Return parameter    : void                                                 **
**                                                                            **
** Preconditions       : None.                                                **
**                                                                            **
** Remarks             : Global Variable(s) : Dcm_GddNegRespError             **
**                       Dcm_GusMaxNoOfForceRespPend ,Dcm_GulULMemAddress     **
**                       Dcm_MemServicePendingStatus , Dcm_GulULMemSize       **
**                       Dcm_GaaAddressAndLengthFormatIds, Dcm_GucDataForId   **
**                       Function(s) invoked :                                **
**                        Dcm_DcmUpLoadCall, Dcm_ExternalSetNegResponse ,     **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestUpLoad(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint32 LulReqDataLength;
  uint8 LucMemAdrBytes;
  uint8 LucMemSizeBytes;
  uint8 LucAddrLenForId;
  uint8 LucDataForId;
    #if(DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != DCM_ZERO)
  uint8 LucLoopVar;
  #endif
  boolean LddAddrLenForIdSupported;
  boolean LblUploadApiInvoked;

  /* Initialize local variables */
  LulMemoryAddress = DCM_ZERO;
  LulMemorySize = DCM_ZERO;
  LddAddrLenForIdSupported = DCM_FALSE;
  LblUploadApiInvoked = DCM_FALSE;

  /* Initialize global variables */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
  Dcm_GddOpStatus = DCM_INITIAL;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucUlPendingStatus = DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.ucUlForcePendingStatus =
    DCM_FALSE;


  /* Get Requested data from request */
  LpReqResData = pMsgContext->reqData;
  /* Get Requested data Length from request*/
  LulReqDataLength = pMsgContext->reqDataLen;

  /* Get DataFormatIdentifier from the request */
  LucDataForId = *(LpReqResData);

  /* MISRA Rule        : 17.4
    Message            : Increment or decrement operation
                         performed on pointer
    Reason             : Increment operator not used
                         to achieve better throughput.
    Verification       : However, part of the code
                         is verified manually and
                         it is not having any impact.
  */
  /*Get the addressAndLengthFormatIdentifier from the request*/
  LpReqResData++;
  LucAddrLenForId = *(LpReqResData);

  #if(DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != DCM_ZERO)
  /* Check for configured Address and length format identifier */
  for(LucLoopVar = DCM_ZERO;
    LucLoopVar < Dcm_Num_Of_Address_Length_Format_ID_Config; LucLoopVar++)
  {
    if(LucAddrLenForId == Dcm_GaaAddressAndLengthFormatIds[LucLoopVar])
    {
      LddAddrLenForIdSupported = DCM_TRUE;
      /* MISRA Rule        : 13.6
        Message            : Control variable, LucLoopVar,
                             modified in body of loop
        Reason             : Once the search element found, control
                             exiting from the for loop to terminate
                             next iteration.
        Verification       : However, part of the code
                             is verified manually and
                             it is not having any impact.
      */
      /* To Break Loop */
      LucLoopVar = Dcm_Num_Of_Address_Length_Format_ID_Config;
    }
  }
  #else
  LddAddrLenForIdSupported = DCM_TRUE;
  #endif

  /* check AddressAndLengthFormatIdentifier is valid or not */
  if(LddAddrLenForIdSupported == DCM_TRUE)
  {
    /* Get Memory address bytes and memory size bytes
      from the request */
    LucMemAdrBytes = (LucAddrLenForId & DCM_SIG_BYTE_MASK_VALUE);
    LucMemSizeBytes =
      (uint8)((LucAddrLenForId & DCM_SIG_SIZE_MASK_VALUE) >> DCM_FOUR);

    /* check length of the request is valid or not */
    if(LulReqDataLength == (uint32)(LucMemAdrBytes + LucMemSizeBytes + DCM_TWO))
    {
      /* Get memory address from the request */
      do
      {
        LulMemoryAddress = LulMemoryAddress << DCM_EIGHT;
        /* MISRA Rule        : 17.4
          Message            : Increment or decrement operation
                               performed on pointer
          Reason             : Increment operator not used
                               to achieve better throughput.
          Verification       : However, part of the code
                               is verified manually and
                               it is not having any impact.
        */
        LpReqResData++;
        LulMemoryAddress |= *(LpReqResData);
        LucMemAdrBytes--;
      }
      while(LucMemAdrBytes != DCM_ZERO);

      /* Get memory size from the request */
      do
      {
        LulMemorySize = LulMemorySize << DCM_EIGHT;
        /* MISRA Rule        : 17.4
          Message            : Increment or decrement operation
                               performed on pointer
          Reason             : Increment operator not used
                               to achieve better throughput.
          Verification       : However, part of the code
                               is verified manually and
                               it is not having any impact.
        */
        LpReqResData++;
        LulMemorySize |= *(LpReqResData);
        LucMemSizeBytes--;
      }
      while(LucMemSizeBytes != DCM_ZERO);

      /* Update Memory Address,Size and Data format ID */
      Dcm_GulULMemAddress = LulMemoryAddress;
      Dcm_GulULMemSize = LulMemorySize;
      Dcm_GucDataForId = LucDataForId;
      LblUploadApiInvoked = DCM_TRUE;
      /* Invoke Request Upload call */
      Dcm_DcmUpLoadCall(pMsgContext);
    }
    else
    {

      /*set NRC IncorrectMessageLengthOrInvalidFormat */
      Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
  }
  else
  {
    /*set NRC RequestOutOfRange  because of wrong ALFID */
    Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
  }

  if(LblUploadApiInvoked == DCM_FALSE)
  {
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }

  DCM_UNUSED(OpStatus);
  
  /* TODO: return value shall be processed */
  return E_OK;  
}

/*******************************************************************************
** Function Name        : Dcm_DcmUpLoadCall                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmUpLoadCall function is used to invoke        **
**                        Dcm_ProcessRequestUpload callout.                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):Dcm_MemServicePendingStatus      **
**                        Dcm_ServiceForcePendingStatus , Dcm_GucDataForId    **
**                        Dcm_GulULMemAddress,Dcm_GulULMemSize,               **
**                        Dcm_GddOpStatus ,Dcm_GblUpLoadActive,               **
**                        Dcm_GblDownLoadActive ,Dcm_GucBlockSeqCounter,      **
**                        Dcm_GulBlockLength ,Dcm_GulNumOfBytesToBeTransfer   **
**                        Dcm_GusMaxNoOfForceRespPend , Dcm_TxRespStatus      **
**                        Dcm_GpMsgContext,Dcm_GaaResponseBuf                 **
**                        Function(s) invoked :                               **
**                        Dcm_ProcessRequestUpload, Dcm_DslPduRTransmit ,     **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_DcmUpLoadCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Dcm_NegativeResponseCodeType LddNegativeErrorCode;
  Std_ReturnType LddReturnValue;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint32 LulBlockLength;
  uint8 LucDataForId;

  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  LddNegativeErrorCode = DCM_E_POSITIVERESPONSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucUlPendingStatus = DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.ucUlForcePendingStatus =
    DCM_FALSE;

  /* Update Memory address, Size and data format ID */
  LulMemoryAddress = Dcm_GulULMemAddress;
  LulMemorySize = Dcm_GulULMemSize;
  LucDataForId = Dcm_GucDataForId;

  /* Invoke callout Dcm_ProcessRequestUpload */
  LddReturnValue = Dcm_ProcessRequestUpload(Dcm_GddOpStatus, LucDataForId,
    LulMemoryAddress, LulMemorySize, &LulBlockLength, &LddNegativeErrorCode);
  /* check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == E_OK)
    {
      /* Update Dcm_GblUpLoadActive */
      Dcm_GblUpLoadActive = DCM_TRUE;
      /* Update Dcm_GblDownLoadActive */
      Dcm_GblDownLoadActive = DCM_FALSE;
#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
      Dcm_GblWriteFileActive = DCM_FALSE;
      Dcm_GblReadFileActive = DCM_FALSE;
#endif
      /* Update Dcm_GucBlockSeqCounter */
      Dcm_GucBlockSeqCounter = DCM_ONE;
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;
      /* Update Dcm_GulBlockLength */
      Dcm_GulBlockLength = LulBlockLength;
      /* Update Dcm_GulNumOfBytesToBeTransfer */
      Dcm_GulNumOfBytesToBeTransfer = LulMemorySize;
    }
    else if(LddReturnValue == DCM_E_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.ucUlPendingStatus =
        DCM_TRUE;
    }
    else if(LddReturnValue == DCM_E_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.ucUlForcePendingStatus =
        DCM_TRUE;
      /* Update Dcm_GusMaxNoOfForceRespPend */
      Dcm_GusMaxNoOfForceRespPend++;
      /* 0xFF : limit threshold is unused */
      if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALREJECT;
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
        /* Invoke callout Dcm_ProcessRequestUpload with OpStatus DCM_CANCEL */
        (void) Dcm_ProcessRequestUpload(DCM_CANCEL, LucDataForId,
          LulMemoryAddress, LulMemorySize, &LulBlockLength,
            &LddNegativeErrorCode);
        /* Set Force responsepending flag to False */
        Dcm_ServiceForcePendingStatus.
        ucUlForcePendingStatus = DCM_FALSE;
      }
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = LddNegativeErrorCode;
    }
  }

  if((Dcm_MemServicePendingStatus.ucUlPendingStatus ==
    DCM_FALSE) &&
   (Dcm_ServiceForcePendingStatus.ucUlForcePendingStatus
    == DCM_FALSE) &&  (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
    Dcm_TxRespStatus.ucNegResp = DCM_FALSE;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_FALSE;    
    if (Dcm_GddNegRespError != DCM_E_POSITIVERESPONSE)
    {
      Dcm_ExternalSetNegResponse(&Dcm_GstMsgContext, Dcm_GddNegRespError);
    }
    else
    {
      /* Update positive response */
      pMsgContext->resDataLen = DCM_FIVE;
      pMsgContext->resData[DCM_ZERO] = DCM_SIXTY_FOUR;
      pMsgContext->resData[DCM_ONE] =
        (uint8)((Dcm_GulBlockLength) >> DCM_TWENTYFOUR);
      pMsgContext->resData[DCM_TWO] =
        (uint8)((Dcm_GulBlockLength) >> DCM_SIXTEEN);
      pMsgContext->resData[DCM_THREE] =
        (uint8)((Dcm_GulBlockLength) >> DCM_EIGHT);
      pMsgContext->resData[DCM_FOUR] =
        (uint8)(Dcm_GulBlockLength);
    }
    
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  else if(Dcm_ServiceForcePendingStatus.
    ucUlForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((Dcm_GstMsgContext.idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;
    
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;
    
    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_DcmTransferData                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmTransferData service is used to transfer     **
**                        Data during a download or upload process.           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
** Remarks              : Global Variable(s) :Dcm_GddNegRespError,            **
**                        Dcm_GusMaxNoOfForceRespPend ,Dcm_GddOpStatus        **
**                        Dcm_MemServicePendingStatus ,Dcm_GpWriteData        **
**                        Dcm_ServiceForcePendingStatus ,                     **
**                        Dcm_GblDownLoadActive ,Dcm_GblUpLoadActive          **
**                        Dcm_GulBlockLength ,Dcm_GucBlockSeqCounter,         **
**                        Dcm_GblBlockSeqCounterRepeated,                     **
**                        Dcm_GulNumOfBytesToBeTransfer,                      **
**                        Dcm_GulTransferResponseLength                       **
**                        Function(s) invoked :                               **
**                        Dcm_DcmUpLoadCall, Dcm_ExternalSetNegResponse ,     **
**                        Dcm_ExternalProcessingDone.                         **
**                        Function(s) invoked :                               **
**                        Dcm_DownLoadTransferCall, Dcm_UpLoadTransferCall,   **
**                        Dcm_ExternalSetNegResponse ,                        **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmTransferData(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData;
  uint32 LulReqDataLength;
  uint16 LusBlockSeqCounter;
  boolean LblDownLoadActive;
  boolean LblUpLoadActive;
  #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
  boolean LblReadFileActive;
  boolean LblWriteFileActive;
  #endif
  boolean LblSequenceResponse;

  /* Initialize global variables */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
  Dcm_GddOpStatus = DCM_INITIAL;
  Dcm_GblTransferDataApiInvoked = DCM_FALSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferDataPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus = DCM_FALSE;

  LblSequenceResponse = DCM_FALSE;
  /* Update DownLoad and UpLoad and FileTransfer Active flags */
  LblDownLoadActive = Dcm_GblDownLoadActive;
  LblUpLoadActive = Dcm_GblUpLoadActive;
  #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
  LblReadFileActive = Dcm_GblReadFileActive;
  LblWriteFileActive = Dcm_GblWriteFileActive;
  #endif

  /* Get Requested data from request */
  LpReqResData = pMsgContext->reqData;
  /* Get Requested data length from request */
  LulReqDataLength = pMsgContext->reqDataLen;

  /* Get block sequence counter from the request */
  LusBlockSeqCounter = *(LpReqResData);

  /* Update data to transfer if DownLoad is active */
  if(LblDownLoadActive == DCM_TRUE)
  {
    /* MISRA Rule        : 17.4
      Message            : Increment or decrement operation
                           performed on pointer
      Reason             : Increment operator not used
                           to achieve better throughput.
      Verification       : However, part of the code
                           is verified manually and
                           it is not having any impact.
    */
    LpReqResData++;
    Dcm_GpWriteData = LpReqResData;
  }

  /* check for DownLoad or UpLoad or FileTransfer activation */
  if((LblDownLoadActive == DCM_TRUE) || (LblUpLoadActive == DCM_TRUE) 
  #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
  || (LblReadFileActive == DCM_TRUE) || (LblWriteFileActive == DCM_TRUE)
  #endif
  )
  {
    /* check for length of request In case of Download */
    if((LblDownLoadActive == DCM_TRUE) &&
      (LulReqDataLength > (Dcm_GulBlockLength - DCM_ONE)))
    {
      /* set NRC IncorrectMessageLengthOrInvalidFormat */
      Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    /* check for length of request In case of UpLoad */
    else if((LblUpLoadActive == DCM_TRUE) && (LulReqDataLength != DCM_ONE))
    {
      /* set NRC IncorrectMessageLengthOrInvalidFormat */
      Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
    /* check for length of request In case of Read */
    else if((LblReadFileActive == DCM_TRUE) && (LulReqDataLength != DCM_ONE))
    {
      /* set NRC IncorrectMessageLengthOrInvalidFormat */
      Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    /* check for length of request In case of Write */
    else if((LblWriteFileActive == DCM_TRUE) &&
      (LulReqDataLength < DCM_TWO) /* BlockSequenceCounter + Minimum DataLen */)
    {
      /* set NRC IncorrectMessageLengthOrInvalidFormat */
      Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    #endif
    /* Update Block Sequence Counter */
    else if(((uint8)LusBlockSeqCounter == (Dcm_GucBlockSeqCounter - DCM_ONE)) || (((uint8)LusBlockSeqCounter == 0xFFu) && (Dcm_GucBlockSeqCounter == 0x0U)))
    {
      /* set a flag to indicate BlockSequenceCounter repeated */
      Dcm_GblBlockSeqCounterRepeated = DCM_TRUE;
    }
    /* check for Block Sequence Counter */
    else if(((LusBlockSeqCounter != DCM_ONE) &&
      (LusBlockSeqCounter != Dcm_GucBlockSeqCounter) &&
      (Dcm_GblBlockSeqCounterRepeated == DCM_FALSE)) ||
      ((LusBlockSeqCounter == DCM_ONE) &&
        (LusBlockSeqCounter != Dcm_GucBlockSeqCounter)))
    {
      /* set NRC WrongBlockSequenceCounter */
      Dcm_GddNegRespError = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
    }
    else if(((LblDownLoadActive == DCM_TRUE) || (LblUpLoadActive == DCM_TRUE)) &&
	(Dcm_GulNumOfBytesToBeTransfer == DCM_ZERO))
    {
      /* set NRC RequestSequenceError */
      Dcm_GddNegRespError = DCM_E_REQUESTSEQUENCEERROR;
    }
    #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
	else if(((LblReadFileActive == DCM_TRUE) || (LblWriteFileActive == DCM_TRUE)) &&
    (Dcm_TransferData.remainFileSize == DCM_ZERO))
    {
      /* set NRC RequestSequenceError */
      Dcm_GddNegRespError = DCM_E_REQUESTSEQUENCEERROR;
    }
    #endif
    else if((LblDownLoadActive == DCM_TRUE) &&
      ((pMsgContext->reqDataLen - (DCM_ONE)) > Dcm_GulNumOfBytesToBeTransfer))
    { 
      /* set NRC RequestOutOfRange */
      Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
    }
    #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
    else if(LblWriteFileActive == DCM_TRUE) 
    {
      /* LulReqDataLength: excluding SID
         Dcm_TransferData.remainFileSize / Dcm_TransferData.fileBlockLength: excluding SID and BlockSequenceCounter */
      Dcm_TransferData.remainFileSize++;
      Dcm_TransferData.fileBlockLength++;
      if ((LulReqDataLength > Dcm_TransferData.remainFileSize) || (LulReqDataLength > Dcm_TransferData.fileBlockLength))
      {
        /* set NRC RequestOutOfRange */
        Dcm_GddNegRespError = DCM_E_REQUESTOUTOFRANGE;
      }
    }
    #endif
    else
    {
      /* Do Nothing */
    }
  }
  else
  {
    /* set NRC RequestSequenceError */
    Dcm_GddNegRespError = DCM_E_REQUESTSEQUENCEERROR;
  }
  /* Check to find block sequence counter is repeated or not */
  if((Dcm_GblBlockSeqCounterRepeated == DCM_TRUE) &&
    (Dcm_GddNegRespError == DCM_E_POSITIVERESPONSE))
  {
    pMsgContext->resData[0] = (uint8)LusBlockSeqCounter;

    /* Update Dcm_GblBlockSeqCounterRepeated */
    Dcm_GblBlockSeqCounterRepeated = DCM_FALSE;

    LblSequenceResponse = DCM_TRUE;
  }
  else
  {
    /* for QAC */
  }
  
  if(Dcm_GddNegRespError == DCM_E_POSITIVERESPONSE)
  {
    if(LblSequenceResponse == DCM_FALSE)
    {
      /* Transfer data in case of DownLoad */
      if(LblDownLoadActive == DCM_TRUE)
      {
        #if(DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
        Dcm_GblTransferDataApiInvoked = DCM_TRUE;
        /* Invoke Dcm_WriteMemory callout */
        Dcm_DownLoadTransferCall(pMsgContext);
        #endif
      }
      /* Transfer data in case of UpLoad */
      if(LblUpLoadActive == DCM_TRUE)
      {
        #if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
        Dcm_GblTransferDataApiInvoked = DCM_TRUE;
        /* Invoke Dcm_ReadMemory callout */
        Dcm_UpLoadTransferCall(pMsgContext);
        #endif
      }
      #if(DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
      if(LblReadFileActive == DCM_TRUE)
      {
        
        Dcm_GblTransferDataApiInvoked = DCM_TRUE;
        /* Invoke Dcm_ReadFileOrDir callout */
        Dcm_TransferData.pDataRead = &(pMsgContext->resData[1U]);
        Dcm_ReadFileOrDirTransferCall(pMsgContext);
      }
      if(LblWriteFileActive == DCM_TRUE)
      {
        Dcm_GblTransferDataApiInvoked = DCM_TRUE;
        /* Invoke Dcm_WriteFile callout */
        Dcm_TransferData.pDataWrite = &(pMsgContext->reqData[1U]);
        Dcm_WriteFileTransferCall(pMsgContext);
        
      }
      #endif
      if(Dcm_GucBlockSeqCounter == DCM_MAXVALUE)
      {
        /* Update Dcm_GucBlockSeqCounter */
        Dcm_GucBlockSeqCounter = DCM_ZERO;
      }
      else
      {
        /* Update Dcm_GucBlockSeqCounter */
        Dcm_GucBlockSeqCounter++;
      }
    }
    else
    {
      if(LblDownLoadActive == DCM_TRUE)
      {
        /* prev res is neg :
        2. Dcm_GddTransDataPosRes,multiple tran req is valid var. first request it wil be init~*/
        if (Dcm_GddTransDataPosRes == DCM_FALSE)
        {
          #if(DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
          Dcm_GblTransferDataApiInvoked = DCM_TRUE;
          /* Invoke Dcm_WriteMemory callout */
          Dcm_DownLoadTransferCall(pMsgContext);
          #endif
        }
        else
        {
          /* Update response data length in case of DownLoad */
          pMsgContext->resDataLen = DCM_ONE;
        }
      }
      else if (LblUpLoadActive == DCM_TRUE)
      {
        /* Update response data length in case of UpLoad */
        pMsgContext->resDataLen = Dcm_GulTransferResponseLength;
      }
      #if(DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
      else if(LblWriteFileActive == DCM_TRUE)
      {
        /* prev res is neg :
        2. Dcm_GddTransDataPosRes,multiple tran req is valid var. first request it wil be init~*/
        if (Dcm_GddTransDataPosRes == DCM_FALSE)
        {
          Dcm_GblTransferDataApiInvoked = DCM_TRUE;
          /* Invoke Dcm_WriteFile callout */
          Dcm_TransferData.pDataWrite = &(pMsgContext->reqData[1U]);
          Dcm_WriteFileTransferCall(pMsgContext);   
        }
        else
        {
          /* Update response data length in case of Write */
          pMsgContext->resDataLen = DCM_ONE;
        }
      }
      else if (LblReadFileActive == DCM_TRUE)
      {
        /* Update response data length in case of Read */
        /* pMsgContext->resDataLen is updated on Dcm_ReadFileOrDirTransferCall */
      }
      #endif
      else
      {
        /* QAC */
      }         
    }
  }
  else
  {
  	/* Negative */
  }


  if((Dcm_GblTransferDataApiInvoked == DCM_FALSE)  ||
  (LblSequenceResponse == DCM_TRUE))
  {
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }

  DCM_UNUSED(OpStatus);
  /* TODO: return value shall be processed */
  return E_OK;
}

/*******************************************************************************
** Function Name        :Dcm_DownLoadTransferCall                             **
**                                                                            **
** Service ID           :NA                                                   **
**                                                                            **
** Description          : Dcm_DownLoadTransferCall function is used to        **
**                        invoke Dcm_WriteMemory callout.                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions         :None                                                **
**                                                                            **
** Remarks               :Global Variable(s):Dcm_GddNegRespError ,            **
**                        Dcm_MemServicePendingStatus,Dcm_GulDLMemAddress     **
**                        Dcm_ServiceForcePendingStatus ,Dcm_GddOpStatus      **
**                        Dcm_GulBlockLength, Dcm_GaaWriteMemRngConfig        **
**                        Dcm_GulNumOfBytesToBeTransfer, Dcm_GaaResponseBuf   **
**                        Dcm_GusMaxNoOfForceRespPend ,Dcm_GpMsgContext       **
**                        Dcm_TxRespStatus                                    **
**                        Function(s) invoked :                               **
**                        Dcm_WriteMemory, Dcm_DslPduRTransmit ,              **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
FUNC(void, DCM_CODE) Dcm_DownLoadTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2CONST(Dcm_WriteMemRngInfoConfigType, AUTOMATIC, DCM_APPL_CONST)
    LpWriteMemRng;
  Dcm_ReturnWriteMemoryType LddReturnValue;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucMemoryIdentifier;
  uint8 LucLoopVar;
  boolean LblMemoryFound;

  LulMemorySize = (uint32)DCM_ZERO;

  /* Update Dcm_GddNegRespError */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  LblMemoryFound = DCM_FALSE;
  
  Dcm_GddTransDataPosRes = DCM_FALSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferDataPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus = DCM_FALSE;

  /* Update Memory address and memory size */
  LulMemoryAddress = Dcm_GulDLMemAddress;

  if (Dcm_GulBlockLength >= DCM_TWO)
  {
    LulMemorySize = Dcm_GulBlockLength - DCM_TWO;
  }

  for(LucLoopVar = DCM_ZERO;
  ((LucLoopVar < Dcm_Total_Num_Write_Memory_Configured) && (DCM_FALSE == LblMemoryFound));
    LucLoopVar++)
  {
    LpWriteMemRng = &Dcm_GaaWriteMemRngConfig[LucLoopVar];
    if((LulMemoryAddress >= LpWriteMemRng->ulWriteMemRngLow) &&
          (((LulMemoryAddress + LulMemorySize) - DCM_ONE) <=
          LpWriteMemRng->ulWriteMemRngHigh))
    {
      LblMemoryFound = DCM_TRUE;
    }
  }

  LpWriteMemRng = &Dcm_GaaWriteMemRngConfig[LucLoopVar - DCM_ONE];
  /* Get Configured Memory Identifier */
  LucMemoryIdentifier = LpWriteMemRng->ucWriteMemoryIdentifier;

  /* Invoke callout Dcm_WriteMemory  */
  /* polyspace-begin DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_GddOpStatus and LddReturnValue value is depends on the return value of Dcm_WriteMemory
  . so It is depends on the user. Therefore Dcm_GddOpStatus,LddReturnValue value should be checked." */
  LddReturnValue = Dcm_WriteMemory(Dcm_GddOpStatus, LucMemoryIdentifier,
    LulMemoryAddress, ((pMsgContext->reqDataLen) - DCM_ONE), Dcm_GpWriteData);
  /* check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == DCM_WRITE_OK)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;

      Dcm_GddTransDataPosRes = DCM_TRUE;

      /* Update Response data Length */
      pMsgContext->resDataLen = DCM_ONE;
      /* Update Response data */
      pMsgContext->resData[DCM_ZERO] = pMsgContext->reqData[DCM_ZERO];
      /* Update Dcm_GulNumOfBytesToBeTransfer */
      Dcm_GulNumOfBytesToBeTransfer = (Dcm_GulNumOfBytesToBeTransfer -
        ((pMsgContext->reqDataLen) - DCM_ONE));
      /* Update Dcm_GulDLMemAddress */
      Dcm_GulDLMemAddress = Dcm_GulDLMemAddress + ((pMsgContext->reqDataLen) - DCM_ONE); 
    }
    else if(LddReturnValue == DCM_WRITE_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.
      ucTransferDataPendingStatus = DCM_TRUE;
    }
    else if(LddReturnValue == DCM_WRITE_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.
        ucTransferDataForcePendingStatus = DCM_TRUE;
      /* Update Dcm_GusMaxNoOfForceRespPend */
      Dcm_GusMaxNoOfForceRespPend++;
      /* Check if Dcm_GusMaxNoOfForceRespPend reaches configured limit */
      /* 0xFF : limit threshold is unused */
      if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALREJECT;
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
        /* Invoke callout Dcm_WriteMemory with OpStatus DCM_CANCEL */
        (void) Dcm_WriteMemory(DCM_CANCEL, LucMemoryIdentifier,
          LulMemoryAddress, LulMemorySize, Dcm_GpWriteData);
        /* Set Force responsepending flag to false */
        Dcm_ServiceForcePendingStatus.
          ucTransferDataForcePendingStatus = DCM_FALSE;
      }
      else
      {

      }
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
    }
  }

  if((Dcm_MemServicePendingStatus.
  ucTransferDataPendingStatus == DCM_FALSE) &&
  (Dcm_ServiceForcePendingStatus.
  ucTransferDataForcePendingStatus == DCM_FALSE) && (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
     
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  else if(Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((Dcm_GstMsgContext.idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;

    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
   /* polyspace-end DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_GddOpStatus and LddReturnValue value is depends on the return value of Dcm_WriteMemory
  . so It is depends on the user. Therefore Dcm_GddOpStatus,LddReturnValue value should be checked." */
}
#endif

/*******************************************************************************
** Function Name         : Dcm_UpLoadTransferCall                             **
**                                                                            **
** Service ID            : NA                                                 **
**                                                                            **
** Description           : Dcm_UpLoadTransferCall function is used to invoke  **
**                         Dcm_ReadMemory callout                             **
**                                                                            **
** Sync/Async            : Synchronous                                        **
**                                                                            **
** Re-entrancy           : Non Reentrant                                      **
**                                                                            **
** Input Parameters      : None                                               **
**                                                                            **
** InOut parameter       : pMsgContext                                        **
**                                                                            **
** Output Parameters     : None                                               **
**                                                                            **
** Return parameter      : void                                               **
**                                                                            **
** Preconditions         :None                                                **
**                                                                            **
** Remarks               :Global Variable(s):Dcm_GddNegRespError ,            **
**                        Dcm_MemServicePendingStatus ,                       **
**                        Dcm_ServiceForcePendingStatus ,                     **
**                        Dcm_GulULMemAddress ,Dcm_GulBlockLength             **
**                        Dcm_GaaReadMemRngConfig,Dcm_GddOpStatus             **
**                        Dcm_GulNumOfBytesToBeTransfer ,                     **
**                        Dcm_GusMaxNoOfForceRespPend ,Dcm_GpMsgContext       **
**                        Dcm_GaaResponseBuf ,Dcm_TxRespStatus                **
**                        Function(s) invoked :                               **
**                        Dcm_ReadMemory, Dcm_DslPduRTransmit ,               **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
FUNC(void, DCM_CODE) Dcm_UpLoadTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  P2CONST(Dcm_ReadMemRngInfoConfigType, AUTOMATIC, DCM_APPL_CONST)
    LpReadMemRng;
  Dcm_ReturnReadMemoryType LddReturnValue;
  uint32 LulMemoryAddress;
  uint32 LulMemorySize;
  uint8 LucMemoryIdentifier;
  uint8 LucLoopVar;
  boolean LblMemoryFound;


  /* Update Dcm_GddNegRespError*/
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  LblMemoryFound = DCM_FALSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferDataPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus = DCM_FALSE;

  /* Update Memory address and memory size */
  LulMemoryAddress = Dcm_GulULMemAddress;
  LulMemorySize = Dcm_GulBlockLength - DCM_TWO;


  for(LucLoopVar = DCM_ZERO;
    ((LucLoopVar < Dcm_Total_Num_Read_Memory_Configured) && (!LblMemoryFound));
    LucLoopVar++)
  {
  /* Get Configured memory range */
    LpReadMemRng = &Dcm_GaaReadMemRngConfig[LucLoopVar];
    if((LulMemoryAddress >= LpReadMemRng->ulReadMemRngLow) &&
      (((LulMemoryAddress + LulMemorySize) - DCM_ONE) <=
      LpReadMemRng->ulReadMemRngHigh))
    {
      LblMemoryFound = DCM_TRUE;
    }

  }
  LpReadMemRng = &Dcm_GaaReadMemRngConfig[LucLoopVar - DCM_ONE];
  /* Get Configured Memory Identifier */
  LucMemoryIdentifier = LpReadMemRng->ucReadMemoryIdentifier;

  /* MISRA Rule        : 17.4
    Message            : Performing pointer arithmetic
    Reason             : Increment operator not used
                         to achieve better throughput.
    Verification       : However, part of the code
                         is verified manually and
                         it is not having any impact.
  */
  /* Invoke callout Dcm_ReadMemory  */
  LddReturnValue = Dcm_ReadMemory(Dcm_GddOpStatus, LucMemoryIdentifier,
    LulMemoryAddress, LulMemorySize, (Dcm_GstMsgContext.resData + DCM_ONE));
  /* Check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == DCM_READ_OK)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;

      /* Update Response data */
      pMsgContext->resData[DCM_ZERO] = pMsgContext->reqData[DCM_ZERO];
      if(Dcm_GulNumOfBytesToBeTransfer >= (Dcm_GulBlockLength - DCM_TWO))
      {
        /* Update Response data Length */
        pMsgContext->resDataLen = (Dcm_GulBlockLength - DCM_ONE);
      }
      else
      {
        /* Update Response data Length */
        pMsgContext->resDataLen = (Dcm_GulNumOfBytesToBeTransfer + DCM_ONE);
      }
      /* Update Dcm_GulTransferResponseLength */
      Dcm_GulTransferResponseLength = pMsgContext->resDataLen;

      /* Update Dcm_GulNumOfBytesToBeTransfer */
      Dcm_GulNumOfBytesToBeTransfer = (Dcm_GulNumOfBytesToBeTransfer -
        ((pMsgContext->resDataLen) - DCM_ONE));
    }
    else if(LddReturnValue == DCM_READ_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.
      ucTransferDataPendingStatus = DCM_TRUE;
    }
    else if(LddReturnValue == DCM_READ_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.
        ucTransferDataForcePendingStatus = DCM_TRUE;
      /* Update Dcm_GusMaxNoOfForceRespPend */
      Dcm_GusMaxNoOfForceRespPend++;
      /* Check if Dcm_GusMaxNoOfForceRespPend reaches configured limit */
      /* 0xFF : limit threshold is unused */
      if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALREJECT;
        /* MISRA Rule        : 17.4
          Message            : Performing pointer arithmetic
          Reason             : Increment operator not used
                               to achieve better throughput.
          Verification       : However, part of the code
                               is verified manually and
                               it is not having any impact.
        */
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
        /* Invoke callout Dcm_ReadMemory with OpStatus DCM_CANCEL */
        (void) Dcm_ReadMemory(DCM_CANCEL, LucMemoryIdentifier,
          LulMemoryAddress, LulMemorySize,
          (Dcm_GstMsgContext.resData + DCM_ONE));
        /* Set Force responsepending flag to False */
        Dcm_ServiceForcePendingStatus.
          ucTransferDataForcePendingStatus = DCM_FALSE;
      }
      else
      {

      }
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
    }
  }


  if((Dcm_MemServicePendingStatus.
  ucTransferDataPendingStatus == DCM_FALSE) &&
  (Dcm_ServiceForcePendingStatus.
  ucTransferDataForcePendingStatus == DCM_FALSE) &&
  (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
    
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  else if(Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((Dcm_GstMsgContext.idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;
    
    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
}
#endif

#if(DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
/*******************************************************************************
** Function Name        :Dcm_WriteFileTransferCall                            **
**                                                                            **
** Service ID           :NA                                                   **
**                                                                            **
** Description          : Dcm_WriteFileTransferCall function is used to       **
**                        invoke Dcm_WriteFile callout.                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions         :None                                                **
**                                                                            **
** Remarks               :Global Variable(s):Dcm_GddNegRespError ,            **
**                        Dcm_MemServicePendingStatus,Dcm_GulDLMemAddress     **
**                        Dcm_ServiceForcePendingStatus ,Dcm_GddOpStatus      **
**                        Dcm_GulBlockLength, Dcm_GaaWriteMemRngConfig        **
**                        Dcm_GulNumOfBytesToBeTransfer, Dcm_GaaResponseBuf   **
**                        Dcm_GusMaxNoOfForceRespPend ,Dcm_GpMsgContext       **
**                        Dcm_TxRespStatus                                    **
**                        Function(s) invoked :                               **
**                        Dcm_WriteMemory, Dcm_DslPduRTransmit ,              **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_WriteFileTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Dcm_ReturnWriteMemoryType LddReturnValue;

  /* Update Dcm_GddNegRespError */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  
  Dcm_GddTransDataPosRes = DCM_FALSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferDataPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus = DCM_FALSE;

  /* Invoke callout Dcm_WriteMemory  */
  /* polyspace-begin DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_GddOpStatus and LddReturnValue value is depends on the return value of Dcm_WriteMemory
  . so It is depends on the user. Therefore Dcm_GddOpStatus,LddReturnValue value should be checked." */
  LddReturnValue = Dcm_CallWriteFileFunc(Dcm_GddOpStatus, &Dcm_GddNegRespError);
  /* check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == E_OK)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;

      Dcm_GddTransDataPosRes = DCM_TRUE;

      /* Update Response data Length */
      pMsgContext->resDataLen = DCM_ONE;
      /* Update Response data : Block Sequence */
      pMsgContext->resData[DCM_ZERO] = pMsgContext->reqData[DCM_ZERO];
      /* Update remainFileSize */
      Dcm_TransferData.remainFileSize++; /* Block Sequence */
      Dcm_TransferData.remainFileSize -= pMsgContext->reqDataLen;
    }
    else if(LddReturnValue == DCM_E_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.
      ucTransferDataPendingStatus = DCM_TRUE;
    }
    else if(LddReturnValue == DCM_E_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.
        ucTransferDataForcePendingStatus = DCM_TRUE;
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
    }
  }

  if((Dcm_MemServicePendingStatus.
  ucTransferDataPendingStatus == DCM_FALSE) &&
  (Dcm_ServiceForcePendingStatus.
  ucTransferDataForcePendingStatus == DCM_FALSE) && (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
     
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  else if(Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((Dcm_GstMsgContext.idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;

    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
   /* polyspace-end DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_GddOpStatus and LddReturnValue value is depends on the return value of Dcm_WriteMemory
  . so It is depends on the user. Therefore Dcm_GddOpStatus,LddReturnValue value should be checked." */
}


/*******************************************************************************
** Function Name         : Dcm_ReadFileOrDirTransferCall                      **
**                                                                            **
** Service ID            : NA                                                 **
**                                                                            **
** Description           : Dcm_ReadFileOrDirTransferCall function is used to  **
**                         invoke Dcm_ReadFileOrDir callou                    **
**                                                                            **
** Sync/Async            : Synchronous                                        **
**                                                                            **
** Re-entrancy           : Non Reentrant                                      **
**                                                                            **
** Input Parameters      : None                                               **
**                                                                            **
** InOut parameter       : pMsgContext                                        **
**                                                                            **
** Output Parameters     : None                                               **
**                                                                            **
** Return parameter      : void                                               **
**                                                                            **
** Preconditions         :None                                                **
**                                                                            **
** Remarks               :Global Variable(s):Dcm_GddNegRespError ,            **
**                        Dcm_MemServicePendingStatus ,                       **
**                        Dcm_ServiceForcePendingStatus ,                     **
**                        Dcm_GulULMemAddress ,Dcm_GulBlockLength             **
**                        Dcm_GaaReadMemRngConfig,Dcm_GddOpStatus             **
**                        Dcm_GulNumOfBytesToBeTransfer ,                     **
**                        Dcm_GusMaxNoOfForceRespPend ,Dcm_GpMsgContext       **
**                        Dcm_GaaResponseBuf ,Dcm_TxRespStatus                **
**                        Function(s) invoked :                               **
**                        Dcm_ReadMemory, Dcm_DslPduRTransmit ,               **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_ReadFileOrDirTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  Dcm_ReturnReadMemoryType LddReturnValue;

  /* Update Dcm_GddNegRespError*/
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferDataPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus = DCM_FALSE;

  /* Invoke callout Dcm_ReadFileOrDir  */
  LddReturnValue = Dcm_CallReadFileOrDirFunc(Dcm_GddOpStatus, &Dcm_GddNegRespError);
  /* Check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == E_OK)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;

      /* Update Response data Length */
      pMsgContext->resDataLen = (Dcm_MsgLenType)(Dcm_TransferData.fileDataLen + 1U /* block sequence */);
      /* Update Block Sequence */
      pMsgContext->resData[DCM_ZERO] = pMsgContext->reqData[DCM_ZERO];

      /* Update remainFileSize, remainFileSize  will be used in next command */
      Dcm_TransferData.remainFileSize++; /* Block Sequence */
      Dcm_TransferData.remainFileSize -= pMsgContext->resDataLen;
    }
    else if(LddReturnValue == DCM_E_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.
      ucTransferDataPendingStatus = DCM_TRUE;
    }
    else if(LddReturnValue == DCM_E_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.
        ucTransferDataForcePendingStatus = DCM_TRUE;
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = DCM_E_GENERALPROGRAMMINGFAILURE;
    }
  }

  if((Dcm_MemServicePendingStatus.
  ucTransferDataPendingStatus == DCM_FALSE) &&
  (Dcm_ServiceForcePendingStatus.
  ucTransferDataForcePendingStatus == DCM_FALSE) && (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
     
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  else if(Dcm_ServiceForcePendingStatus.
    ucTransferDataForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
     /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((Dcm_GstMsgContext.idContext) & (DCM_BIT6_AND_MASK));
     /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;

    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* To Avoid QAC Warning */
  }
}

/*******************************************************************************
** Function Name        : Dcm_CallWriteFileFunc                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call the processing function of UDS 0x36 service    **
**                        in case write file process enable                   ** 
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_CallWriteFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  Dcm_TransferData.fileDataLen = Dcm_TransferData.fileBlockLength - 2U;

  /* polyspace-begin MISRA-C3:14.3 MISRA-C3:2.1 [Justified:Low] Same as Dead Code. */
  /* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] */
  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pWriteFileFnc)
  {
    /* @Trace: Dcm_SUD_API_31458 */
    retVal = Dcm_GaaFileTransferFncConfig.pWriteFileFnc(
              OpStatus, 
              Dcm_TransferData.fileDataLen, 
              Dcm_TransferData.pDataWrite, 
              pErrorCode);
  }
  /* polyspace-end MISRA-C3:14.3 MISRA-C3:2.1 [Justified:Low] Same as Dead Code. */
  /* polyspace-end DEFECT:DEAD_CODE [Justified:Low] */
  else
  {
    /* @Trace: Dcm_SUD_API_31457 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CallReadFileOrDirFunc                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call the processing function of UDS 0x36 service    **
**                        in case read file process enable                    ** 
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_CallReadFileOrDirFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal= E_NOT_OK;

  Dcm_TransferData.fileDataLen = Dcm_TransferData.fileBlockLength - 2U;

  /* polyspace-begin MISRA-C3:14.3 MISRA-C3:2.1 [Justified:Low] Same as Dead Code. */
  /* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] */
  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pReadFileOrDirFnc)
  {
    /* @Trace: Dcm_SUD_API_31448 */
    retVal = Dcm_GaaFileTransferFncConfig.pReadFileOrDirFnc(
              OpStatus, 
              &(Dcm_TransferData.fileDataLen), 
              Dcm_TransferData.pDataRead, 
              pErrorCode);
  }
  /* polyspace-end MISRA-C3:14.3 MISRA-C3:2.1 [Justified:Low] Same as Dead Code. */
  /* polyspace-end DEFECT:DEAD_CODE [Justified:Low] */
  else
  {
    /* @Trace: Dcm_SUD_API_31447 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
}

#endif /*if(DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)*/

#endif /*if(DCM_TRANSFER_DATA_SERVICE == STD_ON)*/

/*******************************************************************************
** Function Name        : Dcm_DcmRequestTransferExit                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmRequestTransferExit service is used to       **
**                        terminate a download or upload process              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None.                                               **
**                                                                            **
** Remarks              : Global Variable(s) :Dcm_GddNegRespError ,           **
**                        Dcm_GusMaxNoOfForceRespPend ,Dcm_GddOpStatus        **
**                        Dcm_MemServicePendingStatus ,                       **
**                        Dcm_GblDownLoadActive , Dcm_GblUpLoadActive         **
**                        Function(s) invoked :                               **
**                        Dcm_RequestTransferExitCall,                        **
**                        Dcm_ExternalSetNegResponse ,                        **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
#if(DCM_TRANSFER_EXIT_SERVICE == STD_ON)
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestTransferExit(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  /* Initialize global variables */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
  Dcm_GddOpStatus = DCM_INITIAL;
  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferExitPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferExitForcePendingStatus = DCM_FALSE;

  /* Check for requested data length */
  if(pMsgContext->reqDataLen != DCM_ZERO)
  {
    /* set NRC Incorrect Message length */
    Dcm_GddNegRespError = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    /* Update Dcm_GblDownLoadActive */
    Dcm_GblDownLoadActive = DCM_FALSE;
    /* Update Dcm_GblUpLoadActive */
    Dcm_GblUpLoadActive = DCM_FALSE;
  }
  else
  {

    /* check for DownLoad and UpLoad activation */
    if((Dcm_GblDownLoadActive == DCM_FALSE) &&
    (Dcm_GblUpLoadActive == DCM_FALSE)
    #if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
    && (Dcm_GblReadFileActive == DCM_FALSE)
    && (Dcm_GblWriteFileActive == DCM_FALSE)
    #endif
    )
    {
      /* set NRC RequestSequenceError */
      Dcm_GddNegRespError = DCM_E_REQUESTSEQUENCEERROR;
    }
  }

  if(Dcm_GddNegRespError == DCM_E_POSITIVERESPONSE)
  {
    /* Invoke TransferExit callout */
    Dcm_RequestTransferExitCall(pMsgContext);
    Dcm_GblTransferExitDataApiInvoked = DCM_TRUE;
  }
  if(Dcm_GblTransferExitDataApiInvoked == DCM_FALSE)
  {
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }

  DCM_UNUSED(OpStatus);
  /* TODO: return value shall be processed */
  return E_OK;  
}

/*******************************************************************************
** Function Name        : Dcm_RequestTransferExitCall                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_RequestTransferExitCall function is used to     **
**                        invoke Dcm_ProcessRequestTransferExit callout       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pMsgContext                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s): Dcm_GddNegRespError ,           **
**                        Dcm_MemServicePendingStatus ,                       **
**                        Dcm_ServiceForcePendingStatus ,                     **
**                        Dcm_GddOpStatus , Dcm_GblDownLoadActive             **
**                        Dcm_GblUpLoadActive ,Dcm_GddNegRespError            **
**                        Dcm_GaaResponseBuf , Dcm_TxRespStatus               **
**                        Function(s) invoked :                               **
**                        Dcm_ProcessRequestTransferExit, Dcm_DslPduRTransmit **
**                        Dcm_ExternalSetNegResponse,                         **
**                        Dcm_ExternalProcessingDone.                         **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_RequestTransferExitCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{

  uint32 LulParameterRecordSize;
  Dcm_NegativeResponseCodeType LddNegativeErrorCode;

  Std_ReturnType LddReturnValue;

  LulParameterRecordSize = DCM_ZERO;
  /* Update Dcm_GddNegRespError */
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  LddNegativeErrorCode = DCM_E_POSITIVERESPONSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucTransferExitPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucTransferExitForcePendingStatus = DCM_FALSE;

  /* Invoke callout Dcm_WriteMemory  */
   /* polyspace-begin DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_GddOpStatus and LddReturnValue value is depends on the return value of Dcm_ProcessRequestTransferExit
  . so It is depends on the user. Therefore Dcm_GddOpStatus,LddReturnValue value should be checked." */
  LddReturnValue = Dcm_ProcessRequestTransferExit(Dcm_GddOpStatus,
    &pMsgContext->resData[DCM_ZERO], &LulParameterRecordSize,
    &LddNegativeErrorCode);
  /* Check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == E_OK)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;
      /* Update Response data length */
      pMsgContext->resDataLen = LulParameterRecordSize;
      /* Clear Dcm_GblDownLoadActive flag */
      Dcm_GblDownLoadActive = DCM_FALSE;
      /* Clear Dcm_GblUpLoadActive flag */
      Dcm_GblUpLoadActive = DCM_FALSE;

    }
    else if(LddReturnValue == DCM_E_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.
      ucTransferExitPendingStatus = DCM_TRUE;
    }
    else if(LddReturnValue == DCM_E_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.
        ucTransferExitForcePendingStatus = DCM_TRUE;
      /* Update Dcm_GusMaxNoOfForceRespPend */
      Dcm_GusMaxNoOfForceRespPend++;
      /* Check if Dcm_GusMaxNoOfForceRespPend reaches configured limit */
      /* 0xFF : limit threshold is unused */
      if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALREJECT;
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
        /* Invoke callout Dcm_WriteMemory with OpStatus DCM_CANCEL */
        (void) Dcm_ProcessRequestTransferExit(DCM_CANCEL,
          &pMsgContext->resData[DCM_ZERO],
          &LulParameterRecordSize, &LddNegativeErrorCode);
        /* Set Force responsepending flag to False */
        Dcm_ServiceForcePendingStatus.
          ucTransferExitForcePendingStatus = DCM_FALSE;
      }
      else
      {
        /* Set Force pending flag to True */
      }
    }
    else
    {
      /* Update Dcm_GddNegRespError */
      Dcm_GddNegRespError = LddNegativeErrorCode;
    }
  }

  /* Transmit Positive response and Negative response */
  if((Dcm_MemServicePendingStatus.
  ucTransferExitPendingStatus == DCM_FALSE) &&
    (Dcm_ServiceForcePendingStatus.
    ucTransferExitForcePendingStatus == DCM_FALSE) &&
    (Dcm_GddOpStatus != DCM_CANCEL))
  {
    Dcm_GddOpStatus = DCM_INITIAL;
    
    /* Send response from main function */
    Dcm_GblSendResponse = DCM_TRUE;
  }
  /* To transmit Response pending NRC in case of Force response pending */
  else if(Dcm_ServiceForcePendingStatus.
    ucTransferExitForcePendingStatus == DCM_TRUE)
  {
    /* Update the negative response service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
    /* Update the service Id in the response buffer */
    Dcm_GaaResponseBuf[DCM_ONE] =
      ((pMsgContext->idContext) & (DCM_BIT6_AND_MASK));
    /* Update the NRC in the response buffer */
    Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
    /* Update the bit flag for negative response to TRUE */
    Dcm_TxRespStatus.ucNegResp = DCM_TRUE;
    
    /* Send response from main function */
    Dcm_GblPduRTransmitResponse = DCM_TRUE;
  }
  else
  {
    /* Update Dcm_GddOpStatus */
    Dcm_GddOpStatus = DCM_PENDING;
  }
   /* polyspace-end DEFECT:DEAD_CODE MISRA-C3:2.1 MISRA-C3:14.3 [Justified:Low] "Dcm_GddOpStatus and LddReturnValue value is depends on the return value of Dcm_ProcessRequestTransferExit
  . so It is depends on the user. Therefore Dcm_GddOpStatus,LddReturnValue value should be checked." */
}
#endif

/*******************************************************************************
** Function Name        : Dcm_CheckBlockLength                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the returned block length is exceed        **
**                        the maximum buffer size or not                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if (DCM_DEV_ERROR_DETECT == STD_ON)
static FUNC(boolean, DCM_CODE) Dcm_CheckBlockLength(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  boolean LblretVal = DCM_TRUE;

  /* The block length describe complete length in transferData service */
  uint32 LulBufferSize = Dcm_GetMaxBufferSize(pMsgContext);

  if (Dcm_GulBlockLength > LulBufferSize)
  {
    LblretVal = DCM_FALSE;
    DCM_REPORT_ERROR(DCM_VARIANT_FUNC_SID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
  }

  return LblretVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_GetMaxBufferSize                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the buffer size is configured in protocol       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace+3 MISRA-C3:8.13 [Justified:Low] "pMsgContext type is the prototype specified in the AUTOSAR specification.
part of the code is verfied manually and it has no impact"*/
static FUNC(uint32, DCM_CODE) Dcm_GetMaxBufferSize(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext)
{
  uint32 LulBufferSize = 0U;

  #if (DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
  LulBufferSize = Dcm_DsdInternal_GetBufferSize(pMsgContext->dcmRxPduId);
  #endif

  return LulBufferSize;
}

#if (DCM_REQUEST_FILE_TRANSFER_SERVICE == STD_ON)
/*******************************************************************************
** Function Name        : Dcm_DataToResponseParameter                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function use to convert                        **
**                        a series of byte data to response message           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : numOfByte, pInData                                  **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pOutData                                            **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_DataToResponseParameter(
  uint8 numOfByte,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pInData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pOutData)
{
  uint8 LucIdx;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpShadowInData = pInData;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpShadowOutData = pOutData;

  #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
  /* Big endian */
  /* The LpShadowInData will point to the MSB byte */
  for (LucIdx = DCM_ZERO; LucIdx < numOfByte; LucIdx++)
  {
    /* @Trace: Dcm_SUD_API_50908 */
    LpShadowOutData[LucIdx] = (uint8) (*LpShadowInData);
    LpShadowInData++;
  }
  #else
  /* Little endian */
  /* Pointer to the MSB byte at the end of variable address */
  LpShadowInData = &LpShadowInData[numOfByte];
  for (LucIdx = DCM_ZERO; LucIdx < numOfByte; LucIdx++)
  {
    /* @Trace: Dcm_SUD_API_50909 */
    LpShadowInData--;
    LpShadowOutData[LucIdx] = (uint8) (*LpShadowInData);
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_RequestParameterToUint16                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function use to get data                       **
**                        from request message and convert it to uint16       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : numOfByte, pData                                    **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LulData                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(uint16, DCM_CODE) Dcm_RequestParameterToUint16(
  uint8 numOfByte,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData)
{
  uint8 LucIdx;
  uint16 LusData = DCM_ZERO;

  for (LucIdx = DCM_ZERO; LucIdx < numOfByte; LucIdx++)
  {
    /* @Trace: Dcm_SUD_API_20288 */
    LusData = LusData << DCM_EIGHT;
    LusData = LusData | pData[LucIdx];
  }

  return LusData;
}

/*******************************************************************************
** Function Name        : Dcm_RequestParameterToUint64                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function use to get data                       **
**                        from request message and convert it to uint64       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : numOfByte, pData                                    **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LulData                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(uint64, DCM_CODE) Dcm_RequestParameterToUint64(
  uint8 numOfByte,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pData)
{
  uint8 LucIdx;
  uint64 LulData = DCM_ZERO;

  for (LucIdx = DCM_ZERO; LucIdx < numOfByte; LucIdx++)
  {
    /* @Trace: Dcm_SUD_API_20290 */
    LulData = LulData << DCM_EIGHT;
    LulData = LulData | pData[LucIdx];
  }

  return LulData;
}

/*******************************************************************************
** Function Name        : Dcm_Uint64ToResponseParameter                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function use to convert n byte                 **
**                        from uint64 variable to response message            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : numOfByte, resData                                  **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pResData                                            **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_Uint64ToResponseParameter(
  uint8 numOfByte,
  uint64 resData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pResData)
{
  /* @Trace: Dcm_SUD_API_10235 */
  uint64 shadowResData = resData;
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpActualResData = (uint8*) &shadowResData;
  Dcm_DataToResponseParameter(numOfByte, LpActualResData, pResData);
}

/*******************************************************************************
** Function Name        : Dcm_CheckParameterByteLen                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function use to check the maximum length       **
**                        of parameter based on number of byte                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : numOfByte, value                                    **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LblRetVal                                           **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_CheckParameterByteLen(
  uint8 numOfByte,
  uint64 value)
{
  /* @Trace: Dcm_SUD_API_11235 */
  boolean LblRetVal = DCM_TRUE;

  /* number of bit = number of byte x 8 */
  uint8 LucNumOfBit = numOfByte << DCM_THREE;

  /*  The length of a number is n bytes, so maximum value of it is 2^n - 1 */
  uint64 LulMaxValue = ((uint64) DCM_ONE << (uint64) LucNumOfBit) - (uint64) DCM_ONE;

  if (value > LulMaxValue)
  {
    /* @Trace: Dcm_SUD_API_11234 */
    LblRetVal = DCM_FALSE;
  }

  return LblRetVal;
}

/*******************************************************************************
** Function Name        : Dcm_InitFileInfo                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Initialize data for UDS 0x38 service                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_InitFileInfo(void)
{
  /* @Trace: Dcm_SUD_API_31591 */
  Dcm_FileInfo.blockLength = 0U;
  Dcm_FileInfo.fileSizeCompressed = 0U;
  Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength = 0U; 
  Dcm_FileInfo.pFilePathAndName = NULL_PTR;
  Dcm_FileInfo.filePathAndNameLen = 0U;
  Dcm_FileInfo.operationType = DCM_UNDEFINED_FILE_OPERATION;
  Dcm_FileInfo.dataFormatId = 0U;

  #if (DCM_TRANSFER_DATA_SERVICE == STD_ON)
    Dcm_GblReadFileActive = DCM_FALSE;
    Dcm_GblWriteFileActive = DCM_FALSE;
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_SetFileInfo                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the data for UDS 0x38 service                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pFileInfo                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace +2 MISRA2012:8.13 [Justified:Low] Justify with annotations */
static FUNC(void, DCM_CODE) Dcm_SetFileInfo(
  Dcm_FileInfoPtrType pFileInfo)
{
  /* @Trace: Dcm_SUD_API_31708 */
  if (NULL_PTR != pFileInfo) 
  {
    /* @Trace: Dcm_SUD_API_31662 */
    Dcm_FileInfo = *pFileInfo;
  }
}

/*******************************************************************************
** Function Name        : Dcm_CheckFileSizeParameterLength                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check whether the fileSizeParameterLength is valid  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : fileSizeParameterLen                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_NegativeResponseCodeType                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckFileSizeParameterLength(
  uint8 fileSizeParameterLen)
{
  /* @Trace: Dcm_SUD_API_31492 */
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
  
  /* @Trace: SWS_Dcm_01448 */
  /* If the fileSizeParameterLength parameter in the RequestFile-
    Transfer request is present and outside the closed interval [0x01..0x08], 
    the Dcm shall send a negative response with NRC 0x31 (RequestOutOfRange). */
  if ((fileSizeParameterLen < 0x01) || (fileSizeParameterLen > 0x08))
  {
    /* @Trace: Dcm_SUD_API_31493 */
    errorCode = DCM_E_REQUESTOUTOFRANGE;
  }  

  return errorCode;
}  

/*******************************************************************************
** Function Name        : Dcm_CheckFileTransferRequest                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the request message of UDS 0x38            **
**                        is valid or not                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_NegativeResponseCodeType                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckFileTransferRequest(
  Dcm_MsgContextPtrType pMsgContext)
{
  /* polyspace +2 MISRA-C3:10.5 [Justified:Low] Justify with annotations */
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
  Dcm_FileOperationType operationType = (Dcm_FileOperationType) pMsgContext->reqData[0];

  switch (operationType) 
  {
    case DCM_ADD_FILE:
    case DCM_REPLACE_FILE:
    case DCM_RESUME_FILE:
      /* @Trace: Dcm_SUD_API_31503 */
      errorCode = Dcm_CheckAddOrRepOrResumeFileRequest(pMsgContext);
      break;

    case DCM_READ_DIR:
    case DCM_DELETE_FILE:
      /* @Trace: Dcm_SUD_API_31504 */
      errorCode = Dcm_CheckDelFileOrReadDirRequest(pMsgContext);
      break;

    case DCM_READ_FILE:
      /* @Trace: Dcm_SUD_API_31505 */
      errorCode = Dcm_CheckReadFileRequest(pMsgContext);
      break;

    default:
      /* @Trace: SWS_Dcm_01449 */
      /* @Trace: Dcm_SUD_API_31506 */
      errorCode = DCM_E_REQUESTOUTOFRANGE;
      break;
  }

  return errorCode;
}

/*******************************************************************************
** Function Name        : Dcm_CheckAddOrRepFileRequest                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check request message in case the operation mode    **
**                        is add file or replace file                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_NegativeResponseCodeType                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace +2 MISRA2012:8.13 [Justified:Low] Justify with annotations */
static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckAddOrRepOrResumeFileRequest(
  Dcm_MsgContextPtrType pMsgContext)
{
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
  Dcm_Uint8PtrType pReqData = pMsgContext->reqData;

  uint8 fileSizeParameterLen = DCM_ZERO;
  Dcm_FileInfoType fileInfo = {0U};
  uint32 LddReqDataLen = pMsgContext->reqDataLen;

  /* Get modeOfOperation */
  /* polyspace +1 MISRA-C3:10.5 [Justified:Low] Justify with annotations */
  fileInfo.operationType = (Dcm_FileOperationType) *(pReqData);

  /* Get filePathAndNameLength parameter from request message */
  pReqData++;
  fileInfo.filePathAndNameLen = Dcm_RequestParameterToUint16(2U, pReqData);
  
  /* Get a pointer to filePathAndName */
  pReqData = &pReqData[2U];
  fileInfo.pFilePathAndName = pReqData;

  /* check remain length */
  /* DCM_THREE: modeOfOperation(1) + filePathAndNameLength(2) */
  LddReqDataLen = LddReqDataLen - DCM_THREE;

  if (LddReqDataLen >= fileInfo.filePathAndNameLen)
  {
    LddReqDataLen = LddReqDataLen - fileInfo.filePathAndNameLen;
  }
  else
  {
    LddReqDataLen = DCM_ZERO;
  }

  if (LddReqDataLen > DCM_ZERO)
  {
    /* Get dataFormatIdentifier */
    pReqData = &pReqData[fileInfo.filePathAndNameLen];
    fileInfo.dataFormatId = *(pReqData);
    LddReqDataLen = LddReqDataLen - DCM_ONE;
  }

  if (LddReqDataLen > DCM_ZERO)
  {
    /* Get fileSizeParameterLength */
    pReqData++;
    fileSizeParameterLen = *(pReqData);
  }
  
  /* maximum length can be computed using fileSizeParamterLength and filePathAndNameLength */
  errorCode = Dcm_CheckFileSizeParameterLength(fileSizeParameterLen);
  if (DCM_E_POSITIVERESPONSE == errorCode)
  {
    /* @Trace: Dcm_SUD_API_31472 */
    /* DCM_FIVE: modeOfOperation(1) + filePathAndNameLength(2) + filePathAndName(1) + dataFormatIdentifier(1) */
    uint32 expectedLength = 
      (fileInfo.filePathAndNameLen + ((uint32) fileSizeParameterLen << DCM_ONE) + DCM_FIVE);
    
    /* Full length check */
    if (pMsgContext->reqDataLen != expectedLength)
    {
      /* @Trace: Dcm_SUD_API_31473 */
      errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
      /* @Trace: Dcm_SUD_API_31474 */
      /* Get fileSizeUnCompressed from the request message */
      pReqData++;
      fileInfo.fileSizeUnCompressedOrDirInfoLength = 
        Dcm_RequestParameterToUint64(fileSizeParameterLen, pReqData);

      /* Get fileSizeCompressed from the request message */
      pReqData = &pReqData[fileSizeParameterLen];
      fileInfo.fileSizeCompressed = 
        Dcm_RequestParameterToUint64(fileSizeParameterLen, pReqData);

      /* BlockLength need to set separately because this parameter handle at Callout Function. */
      if (fileInfo.operationType == DCM_RESUME_FILE)
      {
        fileInfo.blockLength = Dcm_FileInfo.blockLength;
      }

      /* Update to static variable for further process */
      Dcm_SetFileInfo(&fileInfo);
    }
  }

  return errorCode;
}

/*******************************************************************************
** Function Name        : Dcm_CheckDelFileOrReadDirRequest                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check request message in case the operation mode    **
**                        is delete file or read directory                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_NegativeResponseCodeType                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace +2 MISRA2012:8.13 [Justified:Low] Justify with annotations */
static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckDelFileOrReadDirRequest(
  Dcm_MsgContextPtrType pMsgContext)
{
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
  Dcm_Uint8PtrType pReqData = pMsgContext->reqData;

  Dcm_FileInfoType fileInfo = {0U};

  /* Get modeOfOperation */
  /* polyspace +1 MISRA-C3:10.5 [Justified:Low] Justify with annotations */
  fileInfo.operationType = (Dcm_FileOperationType) *(pReqData);

  /* Get filePathAndNameLength parameter from request message */
  pReqData++;
  fileInfo.filePathAndNameLen = Dcm_RequestParameterToUint16(2U, pReqData);

  /* Get a pointer to filePathAndName */
  pReqData = &pReqData[2U];
  fileInfo.pFilePathAndName = pReqData;

  /* Full length check */
  if (pMsgContext->reqDataLen != ((uint32) fileInfo.filePathAndNameLen + DCM_THREE))
  {
    /* @Trace: Dcm_SUD_API_31490 */
    errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31489 */
    /* Update to static variable for further process */
    Dcm_SetFileInfo(&fileInfo);
  }

  return errorCode;
}

/*******************************************************************************
** Function Name        : Dcm_CheckReadFileRequest                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check request message in case the operation mode    **
**                        is read file                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_NegativeResponseCodeType                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace +2 MISRA2012:8.13 [Justified:Low] Justify with annotations */
static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_CheckReadFileRequest(
  Dcm_MsgContextPtrType pMsgContext)
{
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
  Dcm_Uint8PtrType pReqData = pMsgContext->reqData;
  uint32 LddReqDataLen = pMsgContext->reqDataLen;

  Dcm_FileInfoType fileInfo = {0U};

  /* Get modeOfOperation */
  /* polyspace +1 MISRA-C3:10.5 [Justified:Low] Justify with annotations */
  fileInfo.operationType = (Dcm_FileOperationType) *(pReqData);

  /* Get filePathAndNameLength parameter from request message */
  pReqData++;
  fileInfo.filePathAndNameLen = Dcm_RequestParameterToUint16(2U, pReqData);

  /* Get a pointer to filePathAndName */
  pReqData = &pReqData[2U];
  fileInfo.pFilePathAndName = pReqData;

  LddReqDataLen = LddReqDataLen - DCM_FOUR; /* minimum length */
  if (LddReqDataLen > DCM_ZERO)
  {
    /* Get dataFormatIdentifier */
    pReqData = &pReqData[fileInfo.filePathAndNameLen];
    fileInfo.dataFormatId = *(pReqData);
  }

  if (pMsgContext->reqDataLen != ((uint32) fileInfo.filePathAndNameLen + DCM_FOUR))
  {
    /* @Trace: Dcm_SUD_API_31523 */
    errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31522 */
    /* Update to static variable for further process */
    Dcm_SetFileInfo(&fileInfo);
  }

  return errorCode;
}

/*******************************************************************************
** Function Name        : Dcm_CallFileTransferFunc                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function for UDS 0x38 service       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_CallFileTransferFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  /* @Trace: Dcm_SUD_API_31400 */
  Std_ReturnType retVal = E_NOT_OK;

  switch (Dcm_FileInfo.operationType)
  {
    case DCM_ADD_FILE:
      /* @Trace: Dcm_SUD_API_31401 */
      retVal = Dcm_CallProcessAddFileFunc(OpStatus, pErrorCode);
      break;

    case DCM_DELETE_FILE:
      /* @Trace: Dcm_SUD_API_31402 */
      retVal = Dcm_CallProcessDeleteFileFunc(OpStatus, pErrorCode);
      break;

    case DCM_REPLACE_FILE:
      /* @Trace: Dcm_SUD_API_31403 */
      retVal = Dcm_CallProcessReplaceFileFunc(OpStatus, pErrorCode);
      break;
    
    case DCM_READ_FILE:
      /* @Trace: Dcm_SUD_API_31405 */
      retVal = Dcm_CallProcessReadFileFunc(OpStatus, pErrorCode);
      break;

    case DCM_READ_DIR:
      /* @Trace: Dcm_SUD_API_31404 */
      retVal = Dcm_CallProcessReadDirFunc(OpStatus, pErrorCode);
      break;

    case DCM_RESUME_FILE:
      /* Always E_OK because ResumeFile don't have Callout Function */
      retVal = Dcm_CallProcessResumeFileFunc(OpStatus, pErrorCode);
      break;

    default:
      /* No action in this case */
      break;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CallProcessAddFileFunc                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function in case the operation mode **
**                        is add file                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessAddFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pProcessRequestAddFileFnc)
  {
    /* @Trace: SWS_Dcm_01446 SWS_Dcm_01447 */
    /* @Trace: Dcm_SUD_API_31408 */
    retVal = Dcm_GaaFileTransferFncConfig.pProcessRequestAddFileFnc(
          OpStatus,
          Dcm_FileInfo.filePathAndNameLen,
          Dcm_FileInfo.pFilePathAndName,
          Dcm_FileInfo.dataFormatId,
          Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength,
          Dcm_FileInfo.fileSizeCompressed,
          &(Dcm_FileInfo.blockLength),
          pErrorCode);
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31407 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CallProcessDeleteFileFunc                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function in case the operation mode **
**                        is delete file                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessDeleteFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pProcessRequestDeleteFileFnc)
  {
    /* @Trace: SWS_Dcm_01446 SWS_Dcm_01447 */
    /* @Trace: Dcm_SUD_API_31411 */
    retVal = Dcm_GaaFileTransferFncConfig.pProcessRequestDeleteFileFnc(
          OpStatus,
          Dcm_FileInfo.filePathAndNameLen,
          Dcm_FileInfo.pFilePathAndName,
          pErrorCode);
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31412 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
} 

/*******************************************************************************
** Function Name        : Dcm_CallProcessReplaceFileFunc                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function in case the operation mode **
**                        is replace file                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessReplaceFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pProcessRequestReplaceFileFnc)
  {
    /* @Trace: SWS_Dcm_01446 SWS_Dcm_01447 */
    /* @Trace: Dcm_SUD_API_31428 */
    retVal = Dcm_GaaFileTransferFncConfig.pProcessRequestReplaceFileFnc(
          OpStatus,
          Dcm_FileInfo.filePathAndNameLen,
          Dcm_FileInfo.pFilePathAndName,
          Dcm_FileInfo.dataFormatId,
          Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength,
          Dcm_FileInfo.fileSizeCompressed,
          &(Dcm_FileInfo.blockLength),
          pErrorCode);
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31427 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
} 

/*******************************************************************************
** Function Name        : Dcm_CallProcessReadFileFunc                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function in case the operation mode **
**                        is read file                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessReadFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pProcessRequestReadFileFnc)
  {
    /* @Trace: SWS_Dcm_01446 SWS_Dcm_01447 */
    /* @Trace: Dcm_SUD_API_31424 */
    retVal = Dcm_GaaFileTransferFncConfig.pProcessRequestReadFileFnc(
          OpStatus,
          Dcm_FileInfo.filePathAndNameLen,
          Dcm_FileInfo.pFilePathAndName,
          Dcm_FileInfo.dataFormatId,
          &(Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength),
          &(Dcm_FileInfo.fileSizeCompressed),
          &(Dcm_FileInfo.blockLength),
          pErrorCode);
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31423 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;  
} 

/*******************************************************************************
** Function Name        : Dcm_CallProcessReadDirFunc                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function in case the operation mode **
**                        is read directory                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessReadDirFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pProcessRequestReadDirFnc)
  {
    /* @Trace: SWS_Dcm_01446 SWS_Dcm_01447 */
    /* @Trace: Dcm_SUD_API_31420 */
    retVal = Dcm_GaaFileTransferFncConfig.pProcessRequestReadDirFnc(
          OpStatus,
          Dcm_FileInfo.filePathAndNameLen,
          Dcm_FileInfo.pFilePathAndName,
          &(Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength),
          &(Dcm_FileInfo.blockLength),
          pErrorCode);
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31419 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
} 

/*******************************************************************************
** Function Name        : Dcm_CallProcessResumeFileFunc                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Call processing function in case the operation mode **
**                        is resume file                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CallProcessResumeFileFunc(
  Dcm_OpStatusType OpStatus,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (NULL_PTR != Dcm_GaaFileTransferFncConfig.pProcessRequestResumeFileFnc)
  {
    /* @Trace: SWS_Dcm_01446 SWS_Dcm_01447 */
    /* @Trace: Dcm_SUD_API_31408 */
    retVal = Dcm_GaaFileTransferFncConfig.pProcessRequestResumeFileFnc(
          OpStatus,
          Dcm_FileInfo.filePathAndNameLen,
          Dcm_FileInfo.pFilePathAndName,
          Dcm_FileInfo.dataFormatId,
          Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength,
          Dcm_FileInfo.fileSizeCompressed,
          &(Dcm_FileInfo.blockLength),
          &(Dcm_FileInfo.transferfilePosition),
          pErrorCode);
  }
  else
  {
    /* @Trace: Dcm_SUD_API_31407 */
    *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CheckFileTransferInfo                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check the file information that returned form API   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_CheckFileTransferInfo(void)
{
  /* @Trace: Dcm_SUD_API_31495 */
  boolean retVal = DCM_FALSE;

  switch (Dcm_FileInfo.operationType)
  {
    case DCM_ADD_FILE:
    case DCM_REPLACE_FILE:
    case DCM_RESUME_FILE:
      /* @Trace: Dcm_SUD_API_31496 */
      retVal = Dcm_CheckAddOrRepOrResumeFileInfo();
      break;

    case DCM_DELETE_FILE:
      /* @Trace: Dcm_SUD_API_31497 */
      /* No check file information for this case */
      retVal = DCM_TRUE;
      break;

    case DCM_READ_FILE:
      /* @Trace: Dcm_SUD_API_31498 */
      retVal = Dcm_CheckReadFileInfo();
      break;

    case DCM_READ_DIR:
      /* @Trace: Dcm_SUD_API_31499 */
      retVal = Dcm_CheckReadDirInfo();
      break;

    default:
      /* No action in this case */
      break;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CheckAddOrRepOrResumeFileInfo                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check the file information that returned form API   **
**                        in case the operation mode is add or replace or     **
**                        resume file                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_CheckAddOrRepOrResumeFileInfo(void)
{
  /* @Trace: Dcm_SUD_API_31470 */
  boolean retVal = DCM_FALSE;

  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;

  retVal = Dcm_CheckParameterByteLen(lenFormatId, Dcm_FileInfo.blockLength);

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CheckReadFileInfo                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check the file information that returned form API   **
**                        in case the operation mode is read file             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_CheckReadFileInfo(void)
{
  /* @Trace: Dcm_SUD_API_31517 */
  boolean retVal = DCM_FALSE;

  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;
  uint8 fileSizeLen = Dcm_GaaFileTransferConfig.ucFileSizeOrDirInfoLength;

  retVal = Dcm_CheckParameterByteLen(lenFormatId, Dcm_FileInfo.blockLength);
  if (DCM_TRUE == retVal)
  {
    /* @Trace: Dcm_SUD_API_31518 */
    retVal = Dcm_CheckParameterByteLen(
      fileSizeLen, Dcm_FileInfo.fileSizeCompressed);

    if (DCM_TRUE == retVal)
    {
      /* @Trace: Dcm_SUD_API_31519 */
      retVal = Dcm_CheckParameterByteLen(
        fileSizeLen, Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength);
    }
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_CheckReadDirInfo                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check the file information that returned form API   **
**                        in case the operation mode is read directory        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_CheckReadDirInfo(void)
{
  /* @Trace: Dcm_SUD_API_31514 */
  boolean retVal = DCM_FALSE;

  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;
  uint8 dirInfoParameterLen = Dcm_GaaFileTransferConfig.ucFileSizeOrDirInfoLength;
  
  retVal = Dcm_CheckParameterByteLen(lenFormatId, Dcm_FileInfo.blockLength);
  if (DCM_TRUE == retVal)
  {
    /* @Trace: Dcm_SUD_API_31515 */
    retVal = Dcm_CheckParameterByteLen(
      dirInfoParameterLen, Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength);
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Dcm_UpdateFileTransferResponse                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fill the data to response message for 0x38 service  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_UpdateFileTransferResponse(
  Dcm_MsgContextPtrType pMsgContext)
{
  switch (Dcm_FileInfo.operationType)
  {
    case DCM_ADD_FILE:
    case DCM_REPLACE_FILE:
      /* @Trace: Dcm_SUD_API_31680 */
      Dcm_UpdateAddOrRepFileResponse(pMsgContext);
      break;

    case DCM_DELETE_FILE:
      /* @Trace: Dcm_SUD_API_31681 */
      Dcm_UpdateDeleteFileResponse(pMsgContext);
      break;

    case DCM_READ_FILE:
      /* @Trace: Dcm_SUD_API_31682 */
      Dcm_UpdateReadFileResponse(pMsgContext);
      break;

    case DCM_READ_DIR:
      /* @Trace: Dcm_SUD_API_31683 */
      Dcm_UpdateReadDirResponse(pMsgContext);
      break;
    
    case DCM_RESUME_FILE:
      /* @Trace: Dcm_SUD_API_31683 */
      Dcm_UpdateResumeFileResponse(pMsgContext);
      break;

    default:
      /* @Trace: Dcm_SUD_API_31684 */
      /* No action in this case */
      break;
  }  
}  

/*******************************************************************************
** Function Name        : Dcm_UpdateAddOrRepFileResponse                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fill the data to response message for 0x38 service  **
**                        is case the operation mode is add or replace file   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_UpdateAddOrRepFileResponse(
  Dcm_MsgContextPtrType pMsgContext)
{
  /* @Trace: Dcm_SUD_API_31678 */
  Dcm_Uint8PtrType pResData = pMsgContext->resData;

  uint64 blockLength = Dcm_FileInfo.blockLength;
  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;
  
  pMsgContext->resDataLen = 
    DCM_TWO + /* modeOfOperation , lengthFormatIdentifier */
    (Dcm_MsgLenType) lenFormatId + /* maxNumberOfBlockLength */
    DCM_ONE /* dataFormatIdentifier */;

  pResData[0U] = (uint8) Dcm_FileInfo.operationType;
  pResData[1U] = lenFormatId;

  pResData = &pResData[2U];
  Dcm_Uint64ToResponseParameter(lenFormatId, blockLength, pResData);

  pResData[lenFormatId] = Dcm_FileInfo.dataFormatId;
}

/*******************************************************************************
** Function Name        : Dcm_UpdateDeleteFileResponse                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fill the data to response message for 0x38 service  **
**                        is case the operation mode is delete file           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_UpdateDeleteFileResponse(
  Dcm_MsgContextPtrType pMsgContext)
{
  /* @Trace: Dcm_SUD_API_31679 */
  pMsgContext->resDataLen = 1U;

  pMsgContext->resData[0U] = (uint8) Dcm_FileInfo.operationType;
}

/*******************************************************************************
** Function Name        : Dcm_UpdateReadFileResponse                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fill the data to response message for 0x38 service  **
**                        is case the operation mode is read file             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_UpdateReadFileResponse(
  Dcm_MsgContextPtrType pMsgContext)
{
  /* @Trace: Dcm_SUD_API_31686 */
  Dcm_Uint8PtrType pResData = pMsgContext->resData;

  uint64 blockLength = Dcm_FileInfo.blockLength;
  uint64 fileSizeCompressed = Dcm_FileInfo.fileSizeCompressed;
  uint64 fileSizeUnCompressed = Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength;

  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;
  uint8 fileSizeLen = Dcm_GaaFileTransferConfig.ucFileSizeOrDirInfoLength;

  pMsgContext->resDataLen = ((uint32) fileSizeLen << DCM_ONE) + DCM_FIVE + lenFormatId;

  pResData[0U] = (uint8) Dcm_FileInfo.operationType;
  pResData[1U] = lenFormatId;

  pResData = &pResData[2U];
  Dcm_Uint64ToResponseParameter(lenFormatId, blockLength, pResData);

  pResData = &pResData[lenFormatId];
  pResData[0U] = Dcm_FileInfo.dataFormatId;

  /* 
  The file size parameter length in AR4.4 have range from 1 to 4.
  So, we will assign the MSB byte of fileSizeOrDirInfoParameterLength parameter
  in response message is 0x00.
  And the LSB byte is the value of fileSizeLen variable.
  */
  pResData[1U] = 0U;
  pResData[2U] = fileSizeLen;

  pResData = &pResData[3U];
  Dcm_Uint64ToResponseParameter(fileSizeLen, fileSizeUnCompressed, pResData);

  pResData = &pResData[fileSizeLen];
  Dcm_Uint64ToResponseParameter(fileSizeLen, fileSizeCompressed, pResData);
}

/*******************************************************************************
** Function Name        : Dcm_UpdateReadDirResponse                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fill the data to response message for 0x38 service  **
**                        is case the operation mode is read directory        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_UpdateReadDirResponse(
  Dcm_MsgContextPtrType pMsgContext)
{
  /* @Trace: Dcm_SUD_API_31685 */
  Dcm_Uint8PtrType pResData = pMsgContext->resData;

  uint64 blockLength = Dcm_FileInfo.blockLength;
  uint64 dirInfoLength = Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength;

  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;
  uint8 dirInfoParameterLen = Dcm_GaaFileTransferConfig.ucFileSizeOrDirInfoLength;

  pMsgContext->resDataLen = (Dcm_MsgLenType) lenFormatId + dirInfoParameterLen + DCM_FIVE;

  pResData[0U] = (uint8) Dcm_FileInfo.operationType;
  pResData[1U] = lenFormatId;

  pResData = &pResData[2U];
  Dcm_Uint64ToResponseParameter(lenFormatId, blockLength, pResData);

  /* Ref: ISO 14229-1, 
  If the modeOfOperation parameter equals to 0x05 (ReadDir) 
  the value of this parameter (dataFormatIdentifier) shall be equal to 0x00.
  */
  pResData = &pResData[lenFormatId];
  pResData[0U] = 0U;

  /* 
  The dir info parameter length in AR4.4 have range from 1 to 4.
  So, we will assign the MSB byte of fileSizeOrDirInfoParameterLength parameter
  in response message is 0x00.
  And the LSB byte is the value of dirInfoParameterLen variable.
  */
  pResData[1U] = 0U;
  pResData[2U] = dirInfoParameterLen;

  pResData = &pResData[3U];
  Dcm_Uint64ToResponseParameter(dirInfoParameterLen, dirInfoLength, pResData);
}

/*******************************************************************************
** Function Name        : Dcm_UpdateResumeFileResponse                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fill the data to response message for 0x38 service  **
**                        is case the operation mode is Resume file   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pMsgContext                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_UpdateResumeFileResponse(
  Dcm_MsgContextPtrType pMsgContext)
{
  /* @Trace: Dcm_SUD_API_31678 */
  Dcm_Uint8PtrType pResData = pMsgContext->resData;

  uint64 blockLength = Dcm_FileInfo.blockLength;
  uint8 lenFormatId = Dcm_GaaFileTransferConfig.uclengthFormatIdentifier;
  uint64 filePos = Dcm_FileInfo.transferfilePosition;
  
  pMsgContext->resDataLen = 
    DCM_TWO + /* modeOfOperation , lengthFormatIdentifier */
    (Dcm_MsgLenType) lenFormatId + /* maxNumberOfBlockLength */
    DCM_ONE + /* dataFormatIdentifier */
    DCM_EIGHT /* filePosition */;

  pResData[0U] = (uint8) Dcm_FileInfo.operationType;
  pResData[1U] = lenFormatId;

  pResData = &pResData[2U];
  Dcm_Uint64ToResponseParameter(lenFormatId, blockLength, pResData);

  pResData = &pResData[lenFormatId];
  pResData[0U] = Dcm_FileInfo.dataFormatId;

  pResData = &pResData[DCM_ONE];
  Dcm_Uint64ToResponseParameter(DCM_EIGHT, filePos, pResData);
}

/*******************************************************************************
** Function Name        : Dcm_TriggerFileTransferProcess                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Update data for transfer file process               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_TriggerFileTransferProcess(void)
{
  #if (DCM_TRANSFER_DATA_SERVICE == STD_ON)
  switch (Dcm_FileInfo.operationType)
  {
    case DCM_ADD_FILE:
    case DCM_REPLACE_FILE:
      /* @Trace: Dcm_SUD_API_31670 */
      Dcm_GblWriteFileActive = DCM_TRUE;
      Dcm_GblDownLoadActive = DCM_FALSE;
      Dcm_GblUpLoadActive = DCM_FALSE;
      break;

    case DCM_READ_FILE:
    case DCM_READ_DIR:
      /* @Trace: Dcm_SUD_API_31671 */
      Dcm_GblReadFileActive = DCM_TRUE;
      Dcm_GblDownLoadActive = DCM_FALSE;
      Dcm_GblUpLoadActive = DCM_FALSE;
      break;

    case DCM_RESUME_FILE:
      /* @Trace: Dcm_SUD_API_31671 */
      Dcm_GblResumeFileActive = DCM_TRUE;
      Dcm_GblDownLoadActive = DCM_FALSE;
      Dcm_GblUpLoadActive = DCM_FALSE;
      Dcm_TransferData.filePosition = Dcm_FileInfo.transferfilePosition;
      break;

    default:
      /* No action in this case */
      break;
  }

  /* @Trace: Dcm_SUD_API_31673 */
  /* The value of block sequence counter is begin with ONE */
  Dcm_GucBlockSeqCounter = DCM_ONE;

  /* Copy data for transfer process */
  Dcm_TransferData.fileBlockLength = Dcm_FileInfo.blockLength;
  Dcm_TransferData.remainFileSize = Dcm_FileInfo.fileSizeUnCompressedOrDirInfoLength;
  #else
  return;
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_DcmFileTransferCall                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Dcm_DcmFileTransferCall function is used to call    **
**                        RequestFileTransfer callout                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus, pMsgContext                               **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_DcmFileTransferCall(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NrcPtrType pErrorCode)
{
  Std_ReturnType LddReturnValue = E_OK;
  *pErrorCode = DCM_E_POSITIVERESPONSE;

  /* Set response pending flag to False */
  Dcm_MemServicePendingStatus.ucFileTransferPendingStatus =
    DCM_FALSE;
  /* Set ForceRcrrp Pending flag to False */
  Dcm_ServiceForcePendingStatus.
    ucFileTransferForcePendingStatus = DCM_FALSE;

  LddReturnValue = Dcm_CallFileTransferFunc(Dcm_GddOpStatus, pErrorCode);

  /* check for OpStatus */
  if(Dcm_GddOpStatus != DCM_CANCEL)
  {
    if(LddReturnValue == E_OK)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_INITIAL;

      if (DCM_FALSE == Dcm_CheckFileTransferInfo())
      {
        /* @Trace: Dcm_SUD_API_31609 */
        *pErrorCode = DCM_E_GENERALREJECT;
      }
      else
      {
        /* NRC 24 (requestSequenceError) should only be checked for ResumeFile. */
        if(Dcm_FileInfo.operationType == DCM_RESUME_FILE)
        {
          if ((Dcm_GblWriteFileActive == DCM_FALSE) ||
              (Dcm_GblTransferDataApiInvoked == DCM_FALSE) 
              #if(DCM_TRANSFER_EXIT_SERVICE == STD_ON)
              ||(Dcm_GblTransferExitDataApiInvoked == DCM_TRUE) 
              #endif
              )
          {
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
          }
          else
          {
            /* @Trace: Dcm_SUD_API_31610 */
            /* Clear the error code variable value */
            *pErrorCode = DCM_E_POSITIVERESPONSE;

            /* @Trace: SWS_Dcm_01455 SWS_Dcm_01090 SWS_Dcm_01456 SWS_Dcm_01091 */
            Dcm_UpdateFileTransferResponse(pMsgContext);
            Dcm_TriggerFileTransferProcess();
          }
        }
        else
        {
          /* @Trace: Dcm_SUD_API_31610 */
          /* Clear the error code variable value */
          *pErrorCode = DCM_E_POSITIVERESPONSE;

          /* @Trace: SWS_Dcm_01455 SWS_Dcm_01090 SWS_Dcm_01456 SWS_Dcm_01091 */
          Dcm_UpdateFileTransferResponse(pMsgContext);
          Dcm_TriggerFileTransferProcess();
        }
      }
    }
    else if(LddReturnValue == DCM_E_PENDING)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_PENDING;
      /* Set response pending flag to True */
      Dcm_MemServicePendingStatus.
      ucFileTransferPendingStatus = DCM_TRUE;
    }
    else if(LddReturnValue == DCM_E_FORCE_RCRRP)
    {
      /* Update Dcm_GddOpStatus */
      Dcm_GddOpStatus = DCM_FORCE_RCRRP_OK;
      /* Set Force responsepending flag to True */
      Dcm_ServiceForcePendingStatus.
        ucFileTransferForcePendingStatus = DCM_TRUE;
      /* Update Dcm_GusMaxNoOfForceRespPend */
      Dcm_GusMaxNoOfForceRespPend++;
      /* Check if Dcm_GusMaxNoOfForceRespPend reaches configured limit */
      /* 0xFF : limit threshold is unused */
      if(Dcm_GusMaxNoOfForceRespPend > Dcm_diag_Resp_Max_Num_Respend)
      {
        /* Update Dcm_GddOpStatus */
        Dcm_GddOpStatus = DCM_INITIAL;
        /* Update Dcm_GddNegRespError */
        Dcm_GddNegRespError = DCM_E_GENERALREJECT;
          Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;
        /* Invoke callout Dcm_WriteMemory with OpStatus DCM_CANCEL */
        (void) Dcm_CallFileTransferFunc(Dcm_GddOpStatus, pErrorCode);
        /* Set Force responsepending flag to false */
        Dcm_ServiceForcePendingStatus.
          ucTransferDataForcePendingStatus = DCM_FALSE;
      }
      else
      {

      }
    }
    else
    {

    }

    if((Dcm_MemServicePendingStatus.ucFileTransferPendingStatus == DCM_FALSE) &&
    (Dcm_ServiceForcePendingStatus.ucFileTransferForcePendingStatus == DCM_FALSE) && (Dcm_GddOpStatus != DCM_CANCEL))
    {
      Dcm_GddOpStatus = DCM_INITIAL;
      /* Send response from main function */
      Dcm_GblSendResponse = DCM_TRUE;
    }
    else if(Dcm_ServiceForcePendingStatus.ucFileTransferForcePendingStatus == DCM_TRUE)
    {
      /* Update the negative response service Id in the response buffer */
      Dcm_GaaResponseBuf[DCM_ZERO] = DCM_NEGATIVE_RESPONSE_SID;
      /* Update the service Id in the response buffer */
      Dcm_GaaResponseBuf[DCM_ONE] =
        ((Dcm_GstMsgContext.idContext) & (DCM_BIT6_AND_MASK));
      /* Update the NRC in the response buffer */
      Dcm_GaaResponseBuf[DCM_TWO] = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
      Dcm_TxRespStatus.ucNeedFailedConfiramtion = DCM_TRUE;    
      /* Update the bit flag for negative response to TRUE */
      Dcm_TxRespStatus.ucNegResp = DCM_TRUE;

      /* Send response from main function */
      Dcm_GblPduRTransmitResponse = DCM_TRUE;
    }
    else
    {
      /* To Avoid QAC Warning */
    }

  }
  DCM_UNUSED(OpStatus);

}

/*******************************************************************************
** Function Name        : Dcm_DcmRequestFileTransfer                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main processing function for UDS 0x38 service       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus, pMsgContext                               **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace +5 MISRA2012:8.13 [Justified:Low] Justify with annotations */
/* @Trace: SRS_Diag_04135 */
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestFileTransfer(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext)
{
  Std_ReturnType LddReturnValue = E_OK;
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;

  Dcm_GddOpStatus = DCM_INITIAL;
  Dcm_GddNegRespError = DCM_E_POSITIVERESPONSE;
  Dcm_GusMaxNoOfForceRespPend = DCM_ZERO;


  if (pMsgContext->reqDataLen < DCM_FOUR /*Minimun Length(5) - SID(1)*/)
  {
    errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {
    errorCode = Dcm_CheckFileTransferRequest(pMsgContext);
  }

  if (DCM_E_POSITIVERESPONSE == errorCode)
  {
    Dcm_DcmFileTransferCall(DCM_INITIAL, pMsgContext, &errorCode);
  }
  else
  {

  }
  
  if (DCM_E_POSITIVERESPONSE != errorCode)
  {
    Dcm_InternalSetNegResponse(pMsgContext, errorCode);
	Dcm_InternalProcessingDone(pMsgContext, DCM_ASYNC_DONE);
  }

  DCM_UNUSED(OpStatus);
  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : Dcm_InitTransferData                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Initialize for UDS 0x36 service                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
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
** Remarks              :                                                     **
*******************************************************************************/

FUNC(void, DCM_CODE) Dcm_InitTransferData(void)
{
  /* @Trace: Dcm_SUD_API_31593 */
  Dcm_TransferData.fileBlockLength = 0U;
  Dcm_TransferData.fileDataLen = 0U;
  Dcm_TransferData.remainFileSize = 0U;
  Dcm_TransferData.remainMemSize = 0U;
  Dcm_TransferData.currentMemAddr = 0U;
  Dcm_TransferData.memoryId = 0U;
}

#endif /* END OF REQUEST FILE TRANSFER */

#define DCM_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
