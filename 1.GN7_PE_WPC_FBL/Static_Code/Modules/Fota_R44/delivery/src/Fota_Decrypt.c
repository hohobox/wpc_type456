/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: Fota_Decrypt.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provide definition of FOTA's decrypt function                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Revision History                               **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.0.0.0   31-Dec-2024   ThanhTVP2      #CP44-12051                         **
** 1.1.1.0   19-Jul-2024   KhanhHC        #CP44-8820, #CP44-9351              **
********************************************************************************
*******************************************************************************/
#include "Fota.h"
#include "Fota_Types.h"
#include "Fota_Decrypt.h"
#include "Csm.h"
#include "Fota_User_Callouts.h"

#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
VAR(Fota_MetaPars_Type, AUTOMATIC) rst_MetaPars;
static uint8 Sec_Gau8_SecureFlashFirmwareKey[FOTA_DEC_KEY_LENGTH];
static uint8 Sec_Gau8_SecureFlashMac[FOTA_MAC_LENGTH];
static uint8 Sec_Gau8_SecureFlashMacKey[FOTA_MAC_LENGTH];
static uint8 Sec_Gau8_SecureFlashIV[FOTA_DEC_IV_LENGTH];

static Fota_DecryptState Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_IDLE;

#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"
/*******************************************************************************
** Function Name        : Fota_ValidateMetadata                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check meta data is valid                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : MetaDataBufferPtr                                   **
**                        Csm_Meta_Header_Length                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_MetadataBlock_Delimiter                        **
**                        Fota_MetadataBlock_Length_64                        **
**                        Fota_MetadataBlock_Length_32                        **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES95489_52E_00004 FOTA_SRS_ES95489_52E_00005 FOTA_SRS_ES95489_52E_00006 */
static FUNC(Std_ReturnType, FOTA_CODE) Fota_ValidateMetadata(
  const uint8* MetaDataBufferPtr,
  uint32 Csm_Meta_Header_Length
)
{
  /* @Trace: FOTA_SUD_API_00101 */
  Std_ReturnType retVal;
  retVal = E_OK;
  /*--------------------------------------------------*
  *| Secure Flash 2.0 MetaData                       |*
  *|----------------+-------+------------------------+*
  *|                | size  | data                   |*
  *|----------------+-------+------------------------+*
  *| Delimiter      | 4byte | 0x3B, 0x49, 0x0C, 0x30 |*
  *|----------------+-------+------------------------+*
  *| Length(64byte) | 4byte | 0x40, 0x00, 0x00, 0x00 |*
  *|----------------+-------+------------------------+*
  *| Length(32byte) | 1byte | 0x38                   |*
  -+------------------------------------------------+*/
/* polyspace-begin MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  if ((Fota_MetadataBlock_Delimiter[0] != MetaDataBufferPtr[0]) || \
      (Fota_MetadataBlock_Delimiter[1] != MetaDataBufferPtr[1]) || \
      (Fota_MetadataBlock_Delimiter[2] != MetaDataBufferPtr[2]) || \
      (Fota_MetadataBlock_Delimiter[3] != MetaDataBufferPtr[3]))
/* polyspace-end MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  {
    retVal |= (Std_ReturnType)E_NOT_OK;
  }

  if (FOTA_EIGHT == Csm_Meta_Header_Length)
  {
    if ((Fota_MetadataBlock_Length_64[0] != MetaDataBufferPtr[4]) || \
    (Fota_MetadataBlock_Length_64[1] != MetaDataBufferPtr[5]) || \
    (Fota_MetadataBlock_Length_64[2] != MetaDataBufferPtr[6]) || \
    (Fota_MetadataBlock_Length_64[3] != MetaDataBufferPtr[7]))
    {
      retVal |= (Std_ReturnType)E_NOT_OK;
    }
  }
  else
  /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
  {  
    if (Fota_MetadataBlock_Length_32[0] != MetaDataBufferPtr[4])
    {
      retVal |= (Std_ReturnType)E_NOT_OK;
    }
  }
  /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_VALIDATE_META_FAILED, retVal);
    #endif /* (FOTA_DEV_ERROR_DETECT == STD_ON) */
  }

  
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_ProcessMetadata                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to processing meta data                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : MetaDataBufferPtr                                   **
**                        Csm_Hash_Job_Id                                     **
**                        Csm_Decrypt_Key_Id                                  **
**                        Csm_Meta_Header_Length                              **
**                        Csm_Meta_SK_Length                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        rst_MetaPars                                        **
**                        Sec_Gau8_SecureFlashFirmwareKey                     **
**                        Sec_Gau8_SecureFlashMac                             **
**                        Sec_Gau8_SecureFlashMacKey                          **
**                        Sec_Gau8_SecureFlashIV                              **
**                        Fota_Gu8_MetadataPSKidx                             **
**                        Function(s) invoked :                               **
**                        Fota_ValidateMetadata                               **
**                        Csm_Hash                                            **
**                        Csm_KeyElementSet                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.7 [Justified:Low] "Not a defect" */
/* @Trace: FOTA_SRS_GENSEC_00006 FOTA_SRS_ES95489_52E_00008 FOTA_SRS_ES98765_01E_00010 FOTA_SRS_ES98765_02E_00030 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_ProcessMetadata(
  const uint8* MetaDataBufferPtr,
  uint32 Csm_Hash_Job_Id,
  uint32 Csm_Decrypt_Key_Id,
  uint32 Csm_Meta_Header_Length,
  uint32 Csm_Meta_SK_Length
)
/* polyspace-end MISRA-C3:2.7 [Justified:Low] "Not a defect" */
{
  /* @Trace: FOTA_SUD_API_00100 */
  Std_ReturnType retVal;
  uint8 Lu8_Index;

  uint32 DigestLen = FOTA_MD_DIGEST_LENGTH;
	uint8 Lau8_SaltDigest[FOTA_MD_DIGEST_LENGTH];
	uint32 Lu32_SaltDigestMSB32;

  rst_MetaPars.FirmwareKeyPtr   = Sec_Gau8_SecureFlashFirmwareKey;
	rst_MetaPars.MacPtr           = Sec_Gau8_SecureFlashMac;
	rst_MetaPars.MacKeyPtr        = Sec_Gau8_SecureFlashMacKey;
	rst_MetaPars.DecryptIVPtr     = Sec_Gau8_SecureFlashIV;

  retVal = Fota_ValidateMetadata(MetaDataBufferPtr, Csm_Meta_Header_Length);

  if (E_OK == retVal)
  {
    for (Lu8_Index = 0U; Lu8_Index < FOTA_MAC_LENGTH; Lu8_Index++)
    {
    /* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
      rst_MetaPars.MacPtr[Lu8_Index] \
        = MetaDataBufferPtr[Csm_Meta_Header_Length \
                          + Csm_Meta_SK_Length + Lu8_Index];
    }

    retVal = Csm_Hash(\
                Csm_Hash_Job_Id, CRYPTO_OPERATIONMODE_SINGLECALL, \
                &MetaDataBufferPtr[Csm_Meta_Header_Length],Csm_Meta_SK_Length, \
                Lau8_SaltDigest, &DigestLen);
  }

  if (E_OK == retVal)
  {
    /* polyspace-begin MISRA-C3:9.1 [Not a defect:Low] "The variable have been initialized" */
    Lu32_SaltDigestMSB32 = \
        ((uint32)(Lau8_SaltDigest[0]) << 24) \
      + ((uint32)(Lau8_SaltDigest[1]) << 16) \
      + ((uint32)(Lau8_SaltDigest[2]) << 8) \
      +  (uint32)(Lau8_SaltDigest[3]);
    /* polyspace-end MISRA-C3:9.1 [Not a defect:Low] "The variable have been initialized" */

    /* polyspace-begin MISRA-C3:2.2 [Justified:Low] "if-condition depends on the MCU." */
    Fota_Gu8_MetadataPSKidx = \
      (uint8)(Lu32_SaltDigestMSB32 % (uint32)FOTA_KDF_NO_OF_HSMPRESHAREDKEY) \
      + FOTA_PSK_INDEX_OFFSET;
    /* polyspace-end MISRA-C3:2.2 [Justified:Low] "if-condition depends on the MCU." */

    for (Lu8_Index = 0U; Lu8_Index < FOTA_DEC_IV_LENGTH; Lu8_Index++)
    {
      /* polyspace+1 MISRA-C3:9.1 [Not a defect:Low] "The variable have been initialized" */
      rst_MetaPars.DecryptIVPtr[Lu8_Index] = Lau8_SaltDigest[Lu8_Index];
    }

    #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM)
    retVal |= Csm_KeyElementSet(Csm_Decrypt_Key_Id, FOTA_CSM_KE_ID_IV,\
                    rst_MetaPars.DecryptIVPtr, FOTA_DEC_IV_LENGTH);
    #else
    FOTA_UNUSED(Csm_Decrypt_Key_Id);
    #endif /* (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM) */
  }

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_PROCESS_META_FAILED, retVal);
    #endif /* (FOTA_DEV_ERROR_DETECT == STD_ON) */
  }
  
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_DeriveKey                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to derive key                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpu8_MetaDataBuffer                                 **
**                        MDBlockId                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Gast_SwUnitTable                               **
**                        Fota_ProgrammingSWUnitId                            **
**                        rst_MetaPars                                        **
**                        Function(s) invoked :                               **
**                        Fota_ProcessMetadata                                **
**                        Fota_DeriveKeyRequest_Callout                       **
**                        Csm_KeyElementSet                                   **
**                        Csm_KeySetValid                                     **
**                        Csm_MacVerify                                       **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES95489_52E_00008 FOTA_SRS_ES98765_01E_00010 FOTA_SRS_ES98765_02E_00030 FOTA_SRS_GENSEC_00001 FOTA_SRS_GENSEC_00006*/
FUNC(Std_ReturnType, FOTA_CODE) Fota_DeriveKey
(
  uint8 *Lpu8_MetaDataBuffer,
  uint8 MDBlockId
)
{
  /* @Trace: FOTA_SUD_API_00099 */
  Std_ReturnType retVal;

  uint32 Csm_Hash_Job_Id;
  uint32 Csm_Decrypt_Key_Id;
  uint32 Csm_Decrypt_Key_Length;
  uint32 Csm_Mac_Job_Id;
  uint32 Csm_Mac_Key_Id;
  uint32 Csm_Mac_Length;
  uint32 Csm_KDF_Key_Id;
  uint32 Csm_KDFResult_Key_Id;
  uint32 Csm_Meta_Header_Length;
  uint32 Csm_Meta_SK_Length;

  Crypto_VerifyResultType DecKeyMACresult = CRYPTO_E_VER_NOT_OK;

  const Fota_SwModule *swUnitHandlePtr;
  Fota_MetaDataType  *metaDataPtr;
  Fota_SWUnitMetadataType* MetadataBlkPtr;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];
  metaDataPtr = swUnitHandlePtr->MetaDataInfoPtr;
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  MetadataBlkPtr = metaDataPtr->SWUnitMetadata;
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  Csm_Hash_Job_Id         = MetadataBlkPtr[MDBlockId].HashJobId;
  Csm_KDF_Key_Id          = MetadataBlkPtr[MDBlockId].KDFKeyId;
  Csm_KDFResult_Key_Id    = MetadataBlkPtr[MDBlockId].KDFResultKeyId;
  Csm_Decrypt_Key_Id      = MetadataBlkPtr[MDBlockId].DecryptKeyId;
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  Csm_Decrypt_Key_Length  = MetadataBlkPtr[MDBlockId].DecryptKeyLength;
  Csm_Mac_Job_Id          = MetadataBlkPtr[MDBlockId].MACJobId;
  Csm_Mac_Key_Id          = MetadataBlkPtr[MDBlockId].MACKeyId;
  Csm_Mac_Length          = MetadataBlkPtr[MDBlockId].MACLength;
  Csm_Meta_Header_Length  = MetadataBlkPtr[MDBlockId].HeaderLength;
  Csm_Meta_SK_Length      = MetadataBlkPtr[MDBlockId].SKMetaLength;
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */

  retVal = Fota_ProcessMetadata(Lpu8_MetaDataBuffer, Csm_Hash_Job_Id,\
    Csm_Decrypt_Key_Id, Csm_Meta_Header_Length, Csm_Meta_SK_Length);

  if (E_OK == retVal)
  {
    retVal |= Fota_DeriveKeyRequest_Callout(Lpu8_MetaDataBuffer, MDBlockId, \
                  Csm_KDF_Key_Id, Csm_KDFResult_Key_Id, Csm_Meta_Header_Length, Csm_Meta_SK_Length);
  }

  #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM)
  if (E_OK == retVal)
  {
    /* Convert the Csm_Mac_Length variable from bytes to bits */
    Csm_Mac_Length = Csm_Mac_Length * FOTA_EIGHT;

    retVal |= Csm_KeyElementSet(Csm_Mac_Key_Id,
                      FOTA_CSM_KE_ID_MAINKEY,
                      rst_MetaPars.MacKeyPtr,
                      Csm_Decrypt_Key_Length);

    retVal |= Csm_KeySetValid(Csm_Mac_Key_Id);

    retVal |= Csm_MacVerify(
                Csm_Mac_Job_Id, CRYPTO_OPERATIONMODE_SINGLECALL,
                rst_MetaPars.FirmwareKeyPtr, Csm_Decrypt_Key_Length,
                rst_MetaPars.MacPtr, Csm_Mac_Length,
                &DecKeyMACresult);
  }

  if ((E_OK == retVal) && (CRYPTO_E_VER_OK == DecKeyMACresult))
  {
    retVal |= Csm_KeyElementSet(Csm_Decrypt_Key_Id,
                      FOTA_CSM_KE_ID_MAINKEY,
                      rst_MetaPars.FirmwareKeyPtr,
                      Csm_Decrypt_Key_Length);

    retVal |= Csm_KeySetValid(Csm_Decrypt_Key_Id);
  }
  else
  {
    retVal = E_NOT_OK;
  }
  #else
  FOTA_UNUSED(DecKeyMACresult);
  FOTA_UNUSED(Csm_Mac_Length);
  FOTA_UNUSED(Csm_Mac_Key_Id);
  FOTA_UNUSED(Csm_Mac_Job_Id);
  FOTA_UNUSED(Csm_Decrypt_Key_Id);
  FOTA_UNUSED(Csm_Decrypt_Key_Length);
  #endif
  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
  if (E_OK != retVal)
  {
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_DERIVE_KEY_FAILED, retVal);
  }
  #endif /*(FOTA_DEV_ERROR_DETECT == STD_ON)*/
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_DecryptStart                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to call start decrypt function             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : DecryptJobId                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        rst_MetaPars                                        **
**                        Fota_SecureFlashDecryptOn                           **
**                        Fota_DecryptProcessingState                         **
**                        Function(s) invoked :                               **
**                        Fota_ProcessMetadata                                **
**                        Csm_Decrypt                                         **
**                        Fota_DecryptStart_Callout                           **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.7 [Justified:Low] "Not a defect" */
/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_DecryptStart
(
  VAR(uint32, AUTOMATIC) DecryptJobId
)
/* polyspace-end MISRA-C3:2.7 [Justified:Low] "Not a defect" */
{
  /* @Trace: FOTA_SUD_API_00074 */
  Std_ReturnType retVal;

  #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM)
  retVal = Csm_Decrypt(DecryptJobId,
                        CRYPTO_OPERATIONMODE_START,
                        NULL_PTR, FOTA_ZERO,
                        NULL_PTR, NULL_PTR);
  #else
  FOTA_UNUSED(DecryptJobId);
  retVal = Fota_DecryptStart_Callout(rst_MetaPars.DecryptIVPtr, \
                rst_MetaPars.FirmwareKeyPtr, FOTA_DEC_KEY_LENGTH, \
                rst_MetaPars.MacPtr, rst_MetaPars.MacKeyPtr, FOTA_MAC_LENGTH);
  #endif

  if (E_OK == retVal)
  {
    Fota_SecureFlashDecryptOn = TRUE;
    Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_START;
  }
  else
  {
    Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_IDLE;
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_REQUEST_DOWNLOAD_SID, FOTA_E_DECRYPT_START_FAILED, retVal);
    #endif
  }

  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_DecryptUpdate                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to call update decrypt function            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : DecryptJobId                                        **
**                        inputPtr                                            **
**                        dataLenPtr                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : outputPtr                                           **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_DecryptProcessingState                         **
**                        Function(s) invoked :                               **
**                        Csm_Decrypt                                         **
**                        Fota_DecryptUpdate_Callout                          **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
FUNC(Std_ReturnType, FOTA_CODE) Fota_DecryptUpdate
(
  VAR(uint32, AUTOMATIC) DecryptJobId,
  P2CONST(uint8, AUTOMATIC, FOTA_CODE) inputPtr,
  P2VAR(uint8, AUTOMATIC, FOTA_CODE) outputPtr,
  P2VAR(uint32, AUTOMATIC, FOTA_CODE) dataLenPtr
)
/* polyspace-end MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
{
  /* @Trace: FOTA_SUD_API_00104 */
  Std_ReturnType retVal;

  #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM)
  retVal = Csm_Decrypt(DecryptJobId,
                        CRYPTO_OPERATIONMODE_UPDATE,
                        inputPtr, *dataLenPtr,
                        outputPtr, dataLenPtr);
  #else
  FOTA_UNUSED(DecryptJobId);
  retVal = Fota_DecryptUpdate_Callout(outputPtr, inputPtr, *dataLenPtr);
  #endif
  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
  if (E_OK != retVal)
  {
    Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_IDLE;
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_DECRYPT_UPDATE_FAILED, retVal);
  }
  else
  {
    Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_UPDATE;
  }
  #endif
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_DecryptFinish                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to call finish decrypt function            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : apiId                                               **
**                        decryptJobId                                        **
**                        dataLenPtr                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : outputPtr                                           **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_DecryptProcessingState                         **
**                        Fota_SecureFlashDecryptOn                           **
**                        Function(s) invoked :                               **
**                        Csm_Decrypt                                         **
**                        Fota_DecryptUpdate_Callout                          **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_DecryptFinish
(
  VAR(uint8, AUTOMATIC) apiId,
  VAR(uint32, AUTOMATIC) decryptJobId,
  P2VAR(uint8, AUTOMATIC, FOTA_CODE) outputPtr,
  P2VAR(uint32, AUTOMATIC, FOTA_CODE) dataLenPtr
)
/* polyspace-end MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
{
  /* @Trace: FOTA_SUD_API_00072 */
  Std_ReturnType retVal=E_NOT_OK;
  FOTA_UNUSED(apiId);

  #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM)
  retVal = Csm_Decrypt(decryptJobId,
                        CRYPTO_OPERATIONMODE_FINISH,
                        NULL_PTR, FOTA_ZERO,
                        outputPtr, dataLenPtr);
  #else
  FOTA_UNUSED(decryptJobId);
  FOTA_UNUSED(outputPtr);
  retVal = Fota_DecryptFinish_Callout(dataLenPtr);
  #endif
  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
  if (E_OK != retVal)
  {
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      apiId, FOTA_E_DECRYPT_FINISH_FAILED, retVal);

    Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_IDLE;
  }
  else
  {
    Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_FINISH;
  }
  #endif /* (FOTA_DEV_ERROR_DETECT == STD_ON) */
  Fota_SecureFlashDecryptOn = FALSE;

  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_FreeDecryptProcessing                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to free decrypt processing when decrypt    **
**                        processing previous is not completed                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : blockProcessingPtr                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_DecryptProcessingState                         **
**                        Function(s) invoked :                               **
**                        Csm_CancelJob                                       **
**                        Fota_DecryptFinish_Callout                          **
**                        Fota_DecryptUpdate_Callout                          **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_FreeDecryptProcessing(
  P2VAR(Fota_FwBlockProcessingType, AUTOMATIC, FOTA_PRIVATE_DATA) blockProcessingPtr)
/* polyspace-end MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
{
  uint32 decryptJobId;
  Std_ReturnType retVal;
  #if (FOTA_STD_OFF == FOTA_DECRYPTION_USING_CSM)
  uint32 dummyData;
  uint8 dummyBuffer[FOTA_TP_BLOCK_LENGTH - 2U];
  FOTA_MEMSET(dummyBuffer, FOTA_ZERO, (FOTA_TP_BLOCK_LENGTH - 2U));
  #endif
  retVal = E_OK;
  /* polyspace +3 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  /* polyspace+1 MISRA-C3:2.2 [Not a defect:Low] "this variable is parameter in some function below" */
  decryptJobId =
    blockProcessingPtr[Fota_ProgrammingFwBlockId].DecryptJobId;
  
  #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM)

  if (FOTA_STATE_DECRYPT_UPDATE == Fota_DecryptProcessingState)
  {
  /* polyspace+2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  /* polyspace+1 MISRA-C3:10.3 [Justified:Low] "Not a defect, this variable is casted to unsigned type. " */
    retVal = Csm_CancelJob(decryptJobId, FOTA_STATE_DECRYPT_UPDATE);
  }
  else if(FOTA_STATE_DECRYPT_START == Fota_DecryptProcessingState)
  {
  /* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  /* polyspace+1 MISRA-C3:10.3 [Justified:Low] "Not a defect, this variable is casted to unsigned type. " */
    retVal = Csm_CancelJob(decryptJobId, FOTA_STATE_DECRYPT_START);
  }
  else
 /* polyspace-begin RTE:UNR [Not a defect:Low] "This else condition is used for another enum type " */
  {
    /* do nothing*/
  }
/* polyspace-end RTE:UNR [Not a defect:Low] "This else condition is used for another enum type " */
  #else
  FOTA_UNUSED(decryptJobId);
  if (FOTA_STATE_DECRYPT_UPDATE == Fota_DecryptProcessingState)
  /* polyspace-begin RTE:UNR [Not a defect:Low] "This IF condition is depend on configuration" */
  {
    retVal = Fota_DecryptFinish_Callout(&dummyData);
  }
  /* polyspace-end RTE:UNR [Not a defect:Low] "This IF condition is depend on configuration" */
  else if (FOTA_STATE_DECRYPT_START == Fota_DecryptProcessingState)
  {
    retVal = Fota_DecryptUpdate_Callout(dummyBuffer, dummyBuffer,
                                          FOTA_TP_BLOCK_LENGTH - 2U);
    if (E_OK == retVal)
    {
      retVal = Fota_DecryptFinish_Callout(&dummyData);
    }
    else
    {
      /* Do nothing */
    }
  }
  else
  /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration"*/
  {
    /*do nothing*/
  }
  /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
  #endif /* End of #if (FOTA_STD_ON == FOTA_DECRYPTION_USING_CSM) */
  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
  if (E_OK != retVal)
  {
    retVal = E_NOT_OK;
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_ERASE_MEMORY_SID, FOTA_E_FREE_DECRYPT_PROCESSING_FAILED, retVal);
  }
  #endif
  Fota_DecryptProcessingState = FOTA_STATE_DECRYPT_IDLE;
  return retVal;
}
#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"
#endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
