/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FOTA_IntFunc.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   :                                                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
** 1.2.0.0   09-Apr-2024   jys          #CP44-7653                            **
** 1.1.1.0   19-Jul-2024   KJShim       #CP44-9249, #CP44-8822, #CP44-7803    **
**                         KhanhHC      #CP44-8128, #CP44-9351                **
** 1.0.1.0   11-Dec-2023   VuPH6        #CP44-3526                            **
** 1.0.0.0   30-Mar-2022   jys          Initial version                       **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota_IntTypes.h"
#include "Fota_IntFunc.h"
#include "Fota.h"
#include "Fota_Globals.h"
#include "Fota_PflsInterface.h"
#include "Fota_NonMmuSubFunc.h"
#include "Fota_SoftwareVersionCheck.h"
#include "Fota_User_Callouts.h"
#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
#include "Fota_Decrypt.h"
#endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
static Fota_JobResultType  FotaVerifyResult;
/* polyspace-begin MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
 * the register value can be read via the address" */

/* polyspace-end MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
 * the register value can be read via the address" */

#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
/* polyspace-begin MISRA-C3:8.9 [Not a defect: Justify with annotations] "No Impact of this rule violation" */
static uint8* Fota_MetaDataBuffer;
/* polyspace-end MISRA-C3:8.9 [Not a defect: Justify with annotations] "No Impact of this rule violation" */
#endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */

#if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
  (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
static boolean Fota_AllSwUnitSvcAreGood;
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
** Function Name        : Fota_FindSoftwareArea                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to find index in software unit table base  **
**                        on software type                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Fota_SoftwareType softwareType                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : swUnitIndex                                         **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(uint8, FOTA_CODE) Fota_FindSoftwareArea(
  VAR(Fota_SoftwareType, FOTA_VAR) softwareType)
{
  uint8 Lu8_Indx;
  /* @Trace: FOTA_SUD_API_00004 */
  uint8 swUnitIndex = FOTA_INVALID_INDEX;

  for (Lu8_Indx = 0; Lu8_Indx < FOTA_NUM_OF_SWUNIT; Lu8_Indx++ )
  {
    if (softwareType == Fota_Gast_SwUnitTable[Lu8_Indx].SoftwareType)
    {
      swUnitIndex = Lu8_Indx;
      break;
    }
  }
  return swUnitIndex;
}
/*******************************************************************************
** Function Name        : Fota_UserCallOutProcessing                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to processing user call out function in    **
**                        main function                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED)
/* polyspace-begin MISRA-C3:8.13 [Justified:Low] "Not a defect" */
FUNC(Std_ReturnType, FOTA_CODE) Fota_UserCallOutProcessing(
                                        Fota_FwBlockProcessingType *fwBlockPtr,
                                        Fota_StateType fotaState)
/* polyspace-end MISRA-C3:8.13 [Justified:Low] "Not a defect" */
{
  Std_ReturnType retVal = E_OK;
  uint8 numOfUserCallouts;
  Fota_UserCalloutType* UserCalloutPtr;
  uint8 index;
  if (FOTA_WAIT == fotaState)
  {
    /* @Trace: FOTA_SUD_API_00102 */
    numOfUserCallouts =
      fwBlockPtr[Fota_ProgrammingFwBlockId].NumOfPreProcCallout;
    UserCalloutPtr = fwBlockPtr[Fota_ProgrammingFwBlockId].PreProcCalloutPtr;

    /* User Pre-BlockProccessing Call-out */
    for (index = 0; index < numOfUserCallouts; index++)
    {
      UserCalloutPtr = &UserCalloutPtr[index];
      if (NULL_PTR != UserCalloutPtr->CalloutFuncPtr)
      {
        retVal |= UserCalloutPtr->CalloutFuncPtr();
      }
    }
  }
  else if (FOTA_PROCESSING == fotaState)
  {
    /* @Trace: FOTA_SUD_API_00103 */
    numOfUserCallouts =
      fwBlockPtr[Fota_ProgrammingFwBlockId].NumOfPostProcCallout;
    UserCalloutPtr = fwBlockPtr[Fota_ProgrammingFwBlockId].PostProcCalloutPtr;

    /* User Post-BlockProccessing Callout */
    for (index = 0; index < numOfUserCallouts; index++)
    {
      UserCalloutPtr = &UserCalloutPtr[index];
      if (NULL_PTR != UserCalloutPtr->CalloutFuncPtr)
      {
        retVal |= UserCalloutPtr->CalloutFuncPtr();
      }
    }
  }
  else
  {
    /* do nothing */
  }

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_USER_CALL_OUT_FAILED, retVal);
    #endif
  }
  
  return retVal;
}
#endif /* (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED) */

#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
/*******************************************************************************
** Function Name        : Fota_MetaDataProcessing                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to processing meta data in main function   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace-begin MISRA-C3:8.13 [Justified:Low] "Not a defect" */
/* @Trace: FOTA_SRS_ES95489_52E_00008 FOTA_SRS_GENSEC_00001 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_MetaDataProcessing(
                                                 Fota_FlashWriteType *fotaWrite,
                                                 Fota_StateType fotaState)
/* polyspace-end MISRA-C3:8.13 [Justified:Low] "Not a defect" */
{
  /* @Trace: FOTA_SUD_API_00095 */
  Std_ReturnType retVal = E_NOT_OK;

  if (FOTA_WAIT == fotaState)
  {
    /* polyspace-begin MISRA-C3:11.8 [Justified:Low]"Not a defect. Type cast for memcpy is safe" */
    Fota_MetaDataBuffer = (uint8*)fotaWrite->pWriteData;
    /* polyspace-end MISRA-C3:11.8 [Justified:Low]"Not a defect. Type cast for memcpy is safe" */

    if (FOTA_TRUE == Fota_CheckMetaWriteRequest())
    {
      retVal = Fota_PflsWriteRequest(Fota_MemoryInstance, \
                fotaWrite->WriteAddPhy, \
                fotaWrite->pWriteData, fotaWrite->Writelen);
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      if (E_NOT_OK == retVal)
      {
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_METADATA_REQUEST_FAILED, retVal);
      }
      #endif
    }
    else
    {
      retVal = E_OK;
    }
  }
  else if (FOTA_PROCESSING == fotaState)
  {
    retVal = Fota_DeriveKey(Fota_MetaDataBuffer, \
                              Fota_ProgrammingMetadataBlkId);
    if(E_OK != retVal)
    {
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_MAIN_FUNCTION_SID, FOTA_E_DERIVE_KEY_FAILED, retVal); 
      #endif
    }
  }
  else
  {
    /* do nothing */
  }
  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_CheckMetaWriteRequest                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check meta block is requested write by  **
**                        Fota configuration                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(boolean, FOTA_CODE) Fota_CheckMetaWriteRequest(void)
{
  /* @Trace: FOTA_SUD_API_00096 */
  boolean result;
  Fota_SWUnitMetadataType *swUnitMetadataInfoPtr;
  Fota_MetaDataType  *metaDataPtr;
  const Fota_SwModule *swUnitHandlePtr;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];

  metaDataPtr = swUnitHandlePtr->MetaDataInfoPtr;

  swUnitMetadataInfoPtr = metaDataPtr->SWUnitMetadata;

  result = swUnitMetadataInfoPtr->IsWriteRequired;

  return result;
}
/*******************************************************************************
** Function Name        : Fota_CheckMetadataArea                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check address is address of metadata    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : metadataAddress                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES95489_52E_00005 FOTA_SRS_ES95489_52E_00004 FOTA_SRS_ES95489_52E_00006 */
FUNC(boolean, FOTA_CODE) Fota_CheckMetadataArea(
  VAR(uint32, FOTA_VAR) metadataAddress)
{
  /* @Trace: FOTA_SUD_API_00070 */
  uint8 blockIndex;
  boolean result;
  const Fota_TargetBlockSwUnitType  *targetBlockSwUnitPtr;
  Fota_SWUnitMetadataType *swUnitMetadataInfoPtr;
  const Fota_TargetBlockType  *targetBlockPtr;
  Fota_MetaDataType  *metaDataPtr;
  const Fota_SwModule *swUnitHandlePtr;

  result = FOTA_FALSE;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];

  targetBlockPtr = swUnitHandlePtr->TargetBlockInfoPtr;

  targetBlockSwUnitPtr = targetBlockPtr->TargetBlockSwUnitPtr;

  for (blockIndex = 0; blockIndex < targetBlockPtr->NumOfBlock; blockIndex++ )
  {
    if (FOTA_METADATA == targetBlockSwUnitPtr[blockIndex].BlockType)
    {
      if (metadataAddress == targetBlockSwUnitPtr[blockIndex].StartAddress)
      {
        result = FOTA_TRUE;
        break;
      }
    }
  }

  if (FOTA_TRUE == result)
  {
    metaDataPtr = swUnitHandlePtr->MetaDataInfoPtr;
    swUnitMetadataInfoPtr = metaDataPtr->SWUnitMetadata;

    for (blockIndex = 0; blockIndex < metaDataPtr->NumOfMetadata; blockIndex++ )
    {
      targetBlockSwUnitPtr = swUnitMetadataInfoPtr[blockIndex].Metadata;
      if (metadataAddress == targetBlockSwUnitPtr->StartAddress)
      {
        Fota_PreviousMetadataBlkId = Fota_ProgrammingMetadataBlkId;
        Fota_ProgrammingMetadataBlkId = blockIndex;
        break;
      }
    }
  }

  return result;
}

/*******************************************************************************
** Function Name        : Fota_CheckMetadataSize                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check address is Size of metadata       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : metadataAddress                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES95489_52E_00004 FOTA_SRS_ES95489_52E_00005 FOTA_SRS_ES95489_52E_00006 */
FUNC(boolean, FOTA_CODE) Fota_CheckMetadataSize(
  VAR(uint32, FOTA_VAR) InMetadataSize)
{
  /* @Trace: FOTA_SUD_API_00071 */
  boolean result;
  uint32 SetMetaDataSize;
  uint32 SetSKMetaLength;
  uint32 SetMACLength;

  const Fota_SwModule *swUnitHandlePtr;
  Fota_MetaDataType  *metaDataPtr;
  Fota_SWUnitMetadataType* MetadataBlkPtr;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];
  metaDataPtr     = swUnitHandlePtr->MetaDataInfoPtr;
  MetadataBlkPtr  = metaDataPtr->SWUnitMetadata;

  SetMetaDataSize = MetadataBlkPtr[Fota_ProgrammingMetadataBlkId].HeaderLength;
  SetSKMetaLength = MetadataBlkPtr[Fota_ProgrammingMetadataBlkId].SKMetaLength;
  SetMACLength    = MetadataBlkPtr[Fota_ProgrammingMetadataBlkId].MACLength;

  if(InMetadataSize == (SetMetaDataSize + SetSKMetaLength + SetMACLength))
  {
	  result = FOTA_TRUE;
  }
  else
  {
	  result = FOTA_FALSE;
  }

  return result;
}
#endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
/*******************************************************************************
** Function Name        : Fota_CheckFwBlockArea                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check address is address of firmware    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : firmwareBlkAddress                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : retVal                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(boolean, FOTA_CODE) Fota_CheckFwBlockArea(
  VAR(uint32, FOTA_VAR) firmwareBlkAddress)
{
  /* @Trace: FOTA_SUD_API_00073 */
  boolean retVal;
  uint8 blockIndex;
  uint8 tempCnt;
  const Fota_TargetBlockSwUnitType* swUnitBlkTargetPtr;
  const Fota_TargetBlockType  *targetBlockPtr;
  const Fota_SwModule *swUnitHandlePtr;

  retVal = FOTA_FALSE;
  tempCnt = 0;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];

  targetBlockPtr = swUnitHandlePtr->TargetBlockInfoPtr;

  swUnitBlkTargetPtr = targetBlockPtr->TargetBlockSwUnitPtr;

  for (blockIndex = 0; blockIndex < targetBlockPtr->NumOfBlock; blockIndex++)
  {
    if (FOTA_FIRMWARE == swUnitBlkTargetPtr[blockIndex].BlockType)
    {
      tempCnt += 1;
      if (firmwareBlkAddress == swUnitBlkTargetPtr[blockIndex].StartAddress)
      {
        Fota_PreviousFwBlockId = Fota_ProgrammingFwBlockId;
        Fota_ProgrammingFwBlockId = tempCnt - 1;
        retVal = FOTA_TRUE;
        break;
      }
    }
  }

  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_CheckAddressIsSignatureArea                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check address is address of signature   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : signatureAddress                                    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(boolean, FOTA_CODE) Fota_CheckAddressIsSignatureArea(
  VAR(uint32, FOTA_VAR) signatureAddress)
{
  /* @Trace: FOTA_SUD_API_00075 */
  uint8 blockIndex;
  boolean result = FOTA_FALSE;
  const Fota_TargetBlockType  *targetBlockPtr;
  const Fota_TargetBlockSwUnitType  *targetBlockSwUnitPtr;
  const Fota_SwModule *swUnitHandlePtr;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];

  targetBlockPtr = swUnitHandlePtr->TargetBlockInfoPtr;

  targetBlockSwUnitPtr = targetBlockPtr->TargetBlockSwUnitPtr;

  for (blockIndex = 0; blockIndex < targetBlockPtr->NumOfBlock; blockIndex++ )
  {
    if (FOTA_SIGNATURE == targetBlockSwUnitPtr[blockIndex].BlockType)
    {
      if (signatureAddress == targetBlockSwUnitPtr[blockIndex].StartAddress)
      {
        result = FOTA_TRUE;
        break;
      }
    }
  }
  return result;
}
/*******************************************************************************
** Function Name        : Fota_ValidateMemoryArea                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check the validity of MemoryArea        **
**                      need to be processed.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ecuSwUnit                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : SwUnitIndex                                         **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType,FOTA_CODE) Fota_ValidateMemoryArea(
  VAR(uint8,AUTOMATIC) memoryArea
)
{
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_NON_MMU_TYPE)
  VAR(Fota_PartitionType,AUTOMATIC) TgtPart;
  VAR(uint8, AUTOMATIC) rub_UnUsed=0U;
  #endif
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  VAR(uint8, AUTOMATIC) rue_ReadBank=0U;
  #endif

  switch(memoryArea)
  {
    case 0x00:
      /* @Trace: FOTA_SUD_API_00051 */
      retVal = E_OK;
      break;

    #if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
   	case 0x0A:
   	  /* polyspace-begin MISRA-C3:13.2 [Justified:Low] "Not a Defect, rub_UnUsed won't be chagned" */
      /* @Trace: FOTA_SUD_API_00052 */
      #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_NON_MMU_TYPE)
      if((Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTA_TYPE,&rub_UnUsed)==E_OK) && /* from Ldj function name should be changed */
         (Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTB_TYPE,&rub_UnUsed)==E_OK))
      /* polyspace-end MISRA-C3:13.2 [Justified:Low] "Not a Defect, rub_UnUsed won't be chagned" */
      {
        if(Fota_GetTargetPartition(&TgtPart)==E_OK)
        {
          if(TgtPart==FOTA_PARTITION_A)
          {
            retVal = E_OK;
          }
          else
          {
            retVal = E_NOT_OK;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_MAIN_FUNCTION_SID, FOTA_E_TARGET_PARTITION_FAILED, retVal);
            #endif
          }
        }
      }
      #elif (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
      {
        (void)Fota_PflsGetActiveBank(&rue_ReadBank);
        Fota_ProgrammingMemoryArea=rue_ReadBank;

        if (memoryArea != Fota_ProgrammingMemoryArea)
        {
          Fota_ProgrammingMemoryArea = memoryArea;
          retVal = E_OK;
        }
        else
        {
          retVal = E_NOT_OK;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_MAIN_FUNCTION_SID, FOTA_E_PFLS_GET_ACTIVE_BANK_FAILED, retVal);
          #endif
        }
      }
      #endif
 		  break;

   	case 0x0B:
      /* polyspace-begin MISRA-C3:13.2 [Justified:Low] "Not a Defect, rub_UnUsed won't be chagned" */
      /* @Trace: FOTA_SUD_API_00053 */
      #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_NON_MMU_TYPE)
      if((Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTA_TYPE,&rub_UnUsed)==E_OK) && /* from Ldj function name should be changed */
         (Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTB_TYPE,&rub_UnUsed)==E_OK))
      /* polyspace-end MISRA-C3:13.2 [Justified:Low] "Not a Defect, rub_UnUsed won't be chagned" */
      {
        if(Fota_GetTargetPartition(&TgtPart)==E_OK)
        {
          if(TgtPart==FOTA_PARTITION_B)
          {
            retVal = E_OK;
          }
          else
          {

            retVal = E_NOT_OK;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_MAIN_FUNCTION_SID, FOTA_E_TARGET_PARTITION_FAILED, retVal);
            #endif
          }
        }
      }
      #elif (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
      {
        (void)Fota_PflsGetActiveBank(&rue_ReadBank);
        Fota_ProgrammingMemoryArea=rue_ReadBank;

        if (memoryArea != Fota_ProgrammingMemoryArea)
        {
          Fota_ProgrammingMemoryArea = memoryArea;
          retVal = E_OK;
        }
        else
        {
          retVal = E_NOT_OK;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_MAIN_FUNCTION_SID, FOTA_E_PFLS_GET_ACTIVE_BANK_FAILED, retVal);
          #endif
        }
      }
      #endif
 		  break;
    #endif /* FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE */

    default:
      /* @Trace: FOTA_SUD_API_00054 */
      retVal = E_NOT_OK;
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_MAIN_FUNCTION_SID, FOTA_E_VALIDATE_MEMORY_EREA_FAILED, retVal);
      #endif
      break;
  }
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_GetMemInstanceBySwUnit                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the Index of Pfls Instance based on **
**                        SwUnitMemoryArea                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ecuSwUnit                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PflsInstanceId                                                **
**                                                                            **
**                                                                            **
** Return parameter     : SwUnitIndex                                         **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType,FOTA_CODE) Fota_GetMemInstanceBySwUnit(
  VAR(uint8,AUTOMATIC) swUnitId,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) PflsInstanceId)
{
  VAR(Std_ReturnType,AUTOMATIC) retVal;
  /* @Trace: FOTA_SUD_API_00020 */
  retVal = E_NOT_OK;

  if (swUnitId < FOTA_NUM_OF_SWUNIT)
  {
    *PflsInstanceId = Fota_Gast_SwUnitTable[swUnitId].PflsInstanceId;
    retVal = E_OK;
  }

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_MEMORY_INSTANCE_FAILED, retVal);  
    #endif
  }
  
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_GetSwUnitIdByLabel                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the Index of Software Unit based on **
**                        SwUnitMemoryArea                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ecuSwUnit                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : SwUnitIndex                                         **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType,FOTA_CODE) Fota_GetSwUnitIdByLabel(
  VAR(uint16,AUTOMATIC) swUnitLabel,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) programmingSwUnitId)
{
  VAR(uint8, AUTOMATIC) icount;
  VAR(Std_ReturnType,AUTOMATIC) retVal;
  /* @Trace: FOTA_SUD_API_00057 */
  retVal = E_NOT_OK;
  *programmingSwUnitId = 0xFF;

  for (icount = 0;icount < FOTA_NUM_OF_SWUNIT;icount++)
  {
    if(swUnitLabel == Fota_Gast_SwUnitTable[icount].ECUSWUnit)
    {
      *programmingSwUnitId = Fota_Gast_SwUnitTable[icount].LogicalID;
      retVal = E_OK;
      break;
    }
  }

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_GET_SW_UNIT_ID_FAILED, retVal); 
    #endif  
  }
  
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_GetSoftwareModuleBlkBySwType                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the Index of Software Unit based on **
**                        SwUnitMemoryArea                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : In_SwType                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : programmingSwUnitId                                 **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Fota_Gast_SwUnitTable         **
**                                                                            **
**                        Function(s) invoked : None                          **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType,FOTA_CODE) Fota_GetSoftwareModuleBlkBySwType( /* from Ldj function name should be changed */
  VAR(Fota_SoftwareType, AUTOMATIC) In_SwType,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) programmingSwUnitId)
{
  VAR(uint8, AUTOMATIC) icount;
  VAR(Std_ReturnType,AUTOMATIC) retVal;
  /* @Trace: FOTA_SUD_API_00010 */
  retVal = E_NOT_OK;

  for (icount = 0;icount < FOTA_NUM_OF_SWUNIT;icount++)
  {
    if (In_SwType == Fota_Gast_SwUnitTable[icount].SoftwareType)
    {
      if (NULL_PTR != programmingSwUnitId)
      {
        *programmingSwUnitId = Fota_Gast_SwUnitTable[icount].LogicalID;
      }
      retVal = E_OK;
      break;
    }
  }

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_GET_SW_MODULE_FAILED, retVal);  
    #endif
  }
  
  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_GetSoftwareModuleBlkByRunArea                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the Index of Software Unit based on **
**                        SwUnitMemoryArea                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : programmingSwUnitId                                 **
**                                                                            **
** Return parameter     : SwUnitIndex                                         **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Fota_Gast_SwUnitTable         **
**                                              rub_PartChkAreaFlagAddr       **
**                                                                            **
**                        Function(s) invoked : None                          **
**                                                                            **
*******************************************************************************/
#if (FOTA_MODE==FOTA_APP_MODE)
FUNC(Std_ReturnType,FOTA_CODE) Fota_GetSoftwareModuleBlkByRunArea( /* from Ldj function name should be changed */
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) programmingSwUnitId)
{
  VAR(uint32, AUTOMATIC) rub_SwUnitStartAddr;
  VAR(uint32, AUTOMATIC) rub_SwUnitEndAddr;
  VAR(Std_ReturnType,AUTOMATIC) retVal;
  VAR(uint8, AUTOMATIC) icount;
  /* @Trace: FOTA_SUD_API_00013 */
  retVal = E_NOT_OK;

  for (icount = 0;icount < FOTA_NUM_OF_SWUNIT;icount++)
  {
	  rub_SwUnitStartAddr = Fota_Gast_SwUnitTable[icount].StartAddress;
	  rub_SwUnitEndAddr = Fota_Gast_SwUnitTable[icount].EndAddress;

	  if((rub_PartChkAreaFlagAddr>=rub_SwUnitStartAddr)&&(rub_PartChkAreaFlagAddr<=rub_SwUnitEndAddr))
	  {
		  *programmingSwUnitId = Fota_Gast_SwUnitTable[icount].LogicalID;
		  retVal = E_OK;
		  break;
	  }
  }

  if(E_OK != retVal)
  {
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_MAIN_FUNCTION_SID, FOTA_E_GET_SW_MODULE_FAILED, retVal);   
    #endif
  }
  return retVal;
}
#endif
/*******************************************************************************
** Function Name        : Fota_ValidateAddressLengthAlignment                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check address and length are valid for access       **
**                        memory in Pflash                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : startAddress, eraseLen, accessType                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType,FOTA_CODE) Fota_ValidateAddressLengthAlignment(
  VAR(uint32, AUTOMATIC) startAddress,
  VAR(uint32, AUTOMATIC) eraseLen,
  VAR(Fota_AccessMemoryType, AUTOMATIC) accessType)
{
  /* @Trace: FOTA_SUD_API_00064 */
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  retVal = E_OK;

  if (FOTA_ERASE_ACCESS_TYPE == accessType)
  {
    retVal = Fota_PflsGetSectorSize(Fota_MemoryInstance,
                                    &Fota_PflsEraseAlignmentValue,
                                    startAddress);
    if (FOTA_ZERO != (startAddress % Fota_PflsEraseAlignmentValue))
    {
      retVal = E_NOT_OK;
    }
    if (FOTA_ZERO != (eraseLen % Fota_PflsEraseAlignmentValue))
    {
      retVal = E_NOT_OK;
    }
    
    if(E_OK != retVal)
    {
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_ERASE_MEMORY_SID, FOTA_E_PFLS_GET_SECTOR_SIZE_FAILED, retVal);
      #endif
    }
  }
  else if (FOTA_WRITE_ACCESS_TYPE == accessType)
  {
    if (FOTA_ZERO != (startAddress % Fota_PflsWriteAlignmentValue))
    {
       retVal = E_NOT_OK;
    }
    if (FOTA_ZERO != (eraseLen % Fota_PflsWriteAlignmentValue))
    {
      retVal = E_NOT_OK;
    }

    if(E_OK != retVal)
    {
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_ERASE_MEMORY_SID, FOTA_E_PFLS_ERASE_REQUEST_FAILED, retVal);  
      #endif
    }
  }
  else
  {
    /* Do nothing */
  }

  return retVal;
}
/*******************************************************************************
** Function Name        : Fota_RequestSTDOrALTAccess                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to check meta block is requested write by  **
**                        Fota configuration                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(void, FOTA_CODE) Fota_RequestSTDOrALTAccess(void)
{
  /* @Trace: FOTA_SUD_API_00127 */
  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
  if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
  {
	  (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_ALT_ADDR);
  }
  else
  {
	  (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_STD_ADDR);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
}
/*******************************************************************************
** Function Name        : Fota_CheckAllSwUnitVersionCheck                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to Check all Sw Unit's Version             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Fota_SvcResultAllSwUnit       **
**                                                                            **
**                        Function(s) invoked : None                          **
**                                                                            **
*******************************************************************************/
/* @Trace: FOTA_SRS_GENSEC_00007 FOTA_SRS_GENSEC_00010 */
#if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
  (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(void, FOTA_CODE) Fota_CheckAllSwUnitVersionCheck(boolean *allSwUnitSvcAreGood)
{
  Std_ReturnType retVal;
  uint8 indexSwUnit;
  retVal = E_OK;
  /* @Trace: FOTA_SUD_API_00024 */
  for (indexSwUnit = 0; indexSwUnit < FOTA_NUM_OF_SWUNIT; indexSwUnit++)
  {
    if (Fota_BackgroundResult[indexSwUnit].UseProgramming == FOTA_PROGRAMMING)
    {
      if (Fota_SvcResultAllSwUnit[indexSwUnit].CheckVersion ==
                                                            FOTA_VERSION_USED)
      {
        if (E_NOT_OK == Fota_SvcResultAllSwUnit[indexSwUnit].VersionCheckResult)
        {
          retVal = E_NOT_OK;
          break;
        }
        else
        {
          /* Do nothing */
        }
      }
    }
  }
  if (retVal != E_NOT_OK)
  {
    Fota_AllSwUnitSvcAreGood = FOTA_TRUE;
    *allSwUnitSvcAreGood = FOTA_TRUE;
  }
  else
  {
    Fota_AllSwUnitSvcAreGood = FOTA_FALSE;
    *allSwUnitSvcAreGood = FOTA_FALSE;
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_ERASE_MEMORY_SID, FOTA_E_SVC_SW_UNIT_FAILED, retVal); 
    #endif
  }
}
#endif
/*******************************************************************************
** Function Name        : Fota_CheckNextSwUnitProgramming                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to return value of FotaVerifyResult        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : FotaVerifyResult                                    **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(Std_ReturnType, FOTA_CODE) Fota_CheckNextSwUnitProgramming(
                                            uint8 *swUnitIndex,
                                            uint8 *recoverySwUnit,
                                            Fota_SvcOrVerifyKeyType optionCheck)
{
  Std_ReturnType retVal;
  uint8 index;
  /* @Trace: FOTA_SUD_API_00029 */
  retVal = E_NOT_OK;

  for (index = *swUnitIndex; index < FOTA_NUM_OF_SWUNIT; index++)
  {
    if (Fota_BackgroundResult[index].UseProgramming == FOTA_PROGRAMMING)
    {
      #if (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON)
      if (Fota_SvcResultAllSwUnit[index].CheckVersion == FOTA_VERSION_USED)
      {
        Fota_SvcResetGlobalVariable(index);
        *swUnitIndex = index;
        retVal = E_OK;
        
        if (FOTA_SVC_CHECK == optionCheck)
        {
          if (E_OK == Fota_SvcResultAllSwUnit[index].VersionCheckResult)
          {
            if (FOTA_FALSE == Fota_AllSwUnitSvcAreGood)
            {
              if (E_NOT_OK == Fota_SingleMemDependencyVersionCheck_Callout(FOTA_SVC_CHECK))
              {
                /* Go to next SwUnit */
                *recoverySwUnit = FOTA_FALSE;
                retVal = E_NOT_OK;
              }
              else
              {
                *recoverySwUnit = FOTA_TRUE;
                break;
              }
            }
            else
            {
              *recoverySwUnit = FOTA_FALSE;
              break;
            }
          }
          else
          {
            *recoverySwUnit = FOTA_TRUE;
            break;
          }
        }
        else
        {
          if (E_NOT_OK == Fota_SingleMemDependencyVersionCheck_Callout(FOTA_VERIFY_KEY_CHECK))
          {
            if (E_OK == Fota_BackgroundResult[index].VerifyKeyResult)
            {
              /* Go to next SwUnit */
              *recoverySwUnit = FOTA_FALSE;
              retVal = E_NOT_OK;
            }
            else
            {
              *recoverySwUnit = FOTA_TRUE;
              break;
            }
          }
          else
          {
            *recoverySwUnit = FOTA_TRUE;
            break;
          }
        }
      }
      else
      {
        /* Do nothing */
      }
      #else
      FOTA_UNUSED(optionCheck);
      FOTA_UNUSED_PTR(recoverySwUnit);
      *swUnitIndex = index;
      retVal = E_OK;
      break;
      #endif
    }
    else
    {
      /* Do nothing */
    }
  }
  return retVal;
}
#endif
/*******************************************************************************
** Function Name        : Fota_SvcInitializeEraseRomSwUnit                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to return value of FotaVerifyResult        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : FotaVerifyResult                                    **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE) &&\
  (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON))
FUNC(void, FOTA_CODE) Fota_SvcInitializeEraseRomSwUnit(uint8 *swUnitIndex)
{
  Std_ReturnType retVal;
  uint8 index;
  /* @Trace: FOTA_SUD_API_00029 */
  retVal = E_NOT_OK;

  if (E_OK == Fota_SingleMemDependencyVersionCheck_Callout(FOTA_SVC_CHECK))
  {
    for (index = FOTA_ZERO; index < FOTA_NUM_OF_SWUNIT; index++)
    {
      if (Fota_SvcResultAllSwUnit[index].CheckVersion == FOTA_VERSION_USED)
      {
        Fota_SvcResultAllSwUnit[index].VersionCheckResult = E_NOT_OK;
      }
    }
    *swUnitIndex = FOTA_ZERO;
  }
  else
  {
    Fota_SvcResultAllSwUnit[*swUnitIndex].VersionCheckResult = E_NOT_OK;
  }
  Fota_AllSwUnitSvcAreGood = FOTA_FALSE;
}
#endif
/*******************************************************************************
** Function Name        : Fota_ResetSvcResultAllSwUnit                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to return value of FotaVerifyResult        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : FotaVerifyResult                                    **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(void, FOTA_CODE) Fota_ResetSvcResultAllSwUnit(Fota_FunctionType type,
  uint8 swUnitIndex)
{
  uint8 index;
  /* @Trace: FOTA_SUD_API_00029 */
  if ((FOTA_CPD_API == type) || (FOTA_INIT_API == type))
  {
    for (index = FOTA_ZERO; index < FOTA_NUM_OF_SWUNIT; index++)
    {
      #if (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON)
      Fota_SvcResultAllSwUnit[index].VersionCheckResult = E_NOT_OK;
      #endif
      Fota_BackgroundResult[index].UseProgramming = FOTA_NONE_PROGRAMMING;
      Fota_BackgroundResult[index].VerifyKeyResult = E_NOT_OK;
    }
  }
  else
  {
    #if (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON)
    Fota_SvcResultAllSwUnit[swUnitIndex].VersionCheckResult = E_NOT_OK;
    #endif
    Fota_BackgroundResult[swUnitIndex].UseProgramming = FOTA_NONE_PROGRAMMING;
    Fota_BackgroundResult[swUnitIndex].VerifyKeyResult = E_NOT_OK;
  }
}
#endif
/*******************************************************************************
** Function Name        : Fota_GetVerifyJobResult                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to return value of FotaVerifyResult        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : FotaVerifyResult                                    **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(Fota_JobResultType, FOTA_CODE) Fota_GetVerifyJobResult(void)
{
  /* @Trace: FOTA_SUD_API_00085 */
  return FotaVerifyResult;
}
/*******************************************************************************
** Function Name        : Fota_SetVerifyJobResult                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to set value of FotaVerifyResult           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Result                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(void, FOTA_CODE) Fota_SetVerifyJobResult(
  VAR(Fota_JobResultType, FOTA_VAR) Result)
{
  /* @Trace: FOTA_SUD_API_00125 */
  FotaVerifyResult = Result;
}
/*******************************************************************************
** Function Name        : Fota_DetReportErr                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to report errors.                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ModuleId, InstanceId, ApiId, ErrorId, retVal        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:CALLING [Justified:Low] "High risk of code changes: Changes have wide impact" */
#if (FOTA_DEV_ERROR_DETECT == STD_ON)
FUNC(void, FOTA_CODE) Fota_DetReportErr
(
  VAR(uint16, AUTOMATIC) ModuleId,
  VAR(uint8, AUTOMATIC) InstanceId,
  VAR(uint8, AUTOMATIC) ApiId,
  VAR(uint8, AUTOMATIC) ErrorId,
  VAR(uint8, AUTOMATIC) retVal
)
{
  (void)Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId);
  if((retVal != FOTA_ZERO) && (retVal != FOTA_ONE))
  {
    Fota_Ret = retVal;
  }
}
#endif
/* polyspace-end CODE-METRIC:CALLING [Justified:Low] "High risk of code changes: Changes have wide impact" */
#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
