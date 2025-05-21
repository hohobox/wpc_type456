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
**  SRC-MODULE: Fota.c                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provide definition of FOTA function                           **
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
** 2.0.1.0     14-Mar-2025   YWJung       #CP44-15409, #CP44-14095            **
**                                        #CP44-16648, #CP44-16830            **
** 2.0.0.0     31-Dec-2024   ThanhTVP2    #CP44-12051                         **
** 1.2.0.0     09-Apr-2024   YSJ          #CP44-7653                          **
** 1.1.1.0_HF1 20-Sep-2024   YWJung       #CP44-10887, #CP44-13136            **
** 1.1.1.0     03-Jun-2024   KJShim       #CP44-9249, #CP44-8822, #CP44-7803  **
**                           KhanhHC      #CP44-8128, #CP44-9351              **
**                           YWJung       #CP44-9278                          **
** 1.1.0.0_HF2 07-Jun-2024   JSKang       #CP44-9298                          **
** 1.1.0.0_HF1 26-Apr-2024   KJShim       #CP44-8300                          **
** 0.1.1.0     26-Mar-2024   YSJ          #CP44-3525                          **
**                                        #CP44-3708                          **
**                                        #CP44-3720                          **
**                                        #CP44-4173                          **
**                                        #CP44-5405                          **
** 0.1.0.1     11-Dec-2023   VuPH6        #CP44-3526                          **
**                                        #CP44-3527                          **
**                                        #CP44-3545                          **
**                                        #CP44-3542                          **
**                           YSJ          #CP44-4173                          **
** 0.1.0.0     30-Mar-2022   YSJ          Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota.h"
#include "Fota_Globals.h"
#include "Mem_76_Pfls.h"
#include "Mem_76_Pfls_Types.h"
#include "Mem_76_Pfls_Globals.h"
#include "Fota_PflsInterface.h"
#include "Fota_User_Callouts.h"
#include "Fota_NonMmuSubFunc.h"
#include "Fota_MagicKeyMgr.h"
#include "Fota_MacUpdateMgr.h"
#include "Rte_Fota.h"
#include "Fota_AreaSyncMgr.h"
#include "Fota_IntFunc.h"
#include "Fota_Verify.h"
#include "HwResource.h"
#include "Fota_Diag.h"
#include "Csm.h"
#include "Fota_BootManager.h"
#include "Fota_SoftwareVersionCheck.h"
#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
#include "Fota_Decrypt.h"
#endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
/* polyspace-begin MISRA-C3:2.7,8.13,20.9 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                             Macro Definition                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                     Global Data                                            **
*******************************************************************************/
/* polyspace-begin MISRA-C3:8.9 [Not a defect: Justify with annotations] "No Impact of this rule violation" */
static Fota_FlashWriteType Fota_Write;

#if (FOTA_MODE == FOTA_APP_MODE)
static const uint32 rub_PartChkAreaFlag = 0x55;
#endif

Fota_RetransferType Fota_Retransfer = {0x00000000UL, FOTA_FALSE};

#if ((FOTA_STD_ON == FOTA_SF20_ENABLE) || (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED))
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
static Fota_FwBlockProcessingType *BlockProcessingRulePtr;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
#endif

#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
static uint8 Lau8_DecryptedBuffer[FOTA_TP_BLOCK_LENGTH - 2U];
#endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
static uint8 Lau8_SignedBuffer[SEC_SF_SIGNATURE_TOTAL_SIZE];
/* polyspace-end MISRA-C3:8.9 [Not a defect: Justify with annotations] "No Impact of this rule violation" */
#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
static uint8 Fota_MetaDataRequestCheck = FOTA_FALSE;
#endif

/* polyspace-begin MISRA-C3:8.4 [Not a defect: Justify with annotations] "No Impact of this rule violation" */
#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
VAR(Fota_BackgroundResultType, FOTA_VAR) Fota_BackgroundResult[FOTA_NUM_OF_SWUNIT];
#endif
/* polyspace-end MISRA-C3:8.4 [Not a defect: Justify with annotations] "No Impact of this rule violation" */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/*******************************************************************************
** Function Name        : Fota_Init                                           **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : Initialization function - initializes all variables **
**                        and sets the module state to initialized            **
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
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        rub_PartChkAreaFlag                                 **
**                        rub_PartChkAreaFlagAddr                             **
**                        Fota_State                                          **
**                        Fota_CurCmdStat                                     **
**                        Fota_ResetAfterSwapReq                              **
**                        Fota_NotDefinedSwUnit                               **
**                        Fota_SecureFlashDecryptOn                           **
**                        BlockProcessingRulePtr                              **
**                        Fota_InitStatus                                     **
**                        Fota_AreaSyncState                                  **
**                        Function(s) invoked :                               **
**                        Fota_PflsInit                                       **
**                        Fota_BootManager                                    **
**                        Fota_ResetSvcResultAllSwUnit                        **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES98765_02E_00027 FOTA_SRS_ES98765_02E_00031 FOTA_SRS_ES98765_02E_00037 FOTA_SRS_ES98765_02E_00038 FOTA_SRS_UDS_00011 */
/* @Trace: FOTA_SRS_ES95489_52E_00008 FOTA_SRS_ES98765_01E_00001 FOTA_SRS_ES98765_02E_00039 FOTA_SRS_UDS_00014*/
FUNC(void, FOTA_CODE) Fota_Init(void)
{
  #if (FOTA_MODE == FOTA_APP_MODE)
  /* polyspace +1 MISRA-C3:11.4 [Justified:Low] "No impact of this rule violation." */
  rub_PartChkAreaFlagAddr =(uint32)&rub_PartChkAreaFlag;
  #endif
  /* @Trace: FOTA_SUD_API_00001 */
  Fota_PflsInit();

  #if FOTA_BOOT_MANAGER_USED
  #if (FOTA_MODE == FOTA_FBL_MODE)
  Fota_BootManager();
  #endif
  #endif
  Fota_State = FOTA_INIT;
  Fota_InitStatus = FOTA_MODULEINIT;
  Fota_CurCmdStat = FOTA_CMD_IDLE;
  Fota_ResetAfterSwapReq = FOTA_FALSE;
  Fota_NotDefinedSwUnit = FOTA_FALSE;
  Fota_SecureFlashDecryptOn = FOTA_FALSE;

  #if ((FOTA_STD_ON == FOTA_SF20_ENABLE) || (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED))
  BlockProcessingRulePtr = NULL_PTR;
  #endif
  
  #if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
  Fota_ResetSvcResultAllSwUnit(FOTA_INIT_API, FOTA_ZERO);
  #endif
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  Fota_AreaSyncState = FOTA_SYNC_IDLE;
  #endif
}

/*******************************************************************************
** Function Name        : Fota_DeInit                                         **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : De-initialize module. If there is still an access   **
**                        job pending, it is immediately terminated (using    **
**                        hardware cancel operation) and the Mem driver       **
**                        module state is set to unitialized. Therefore, Mem  **
**                        must be re-initialized before it will accept any    **
**                        new job requests after this service is processed.   **
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
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_State                                          **
**                        Fota_InitStatus                                     **
**                        Function(s) invoked :                               **
**                        Fota_PflsDeinit                                     **
*******************************************************************************/
FUNC(void, FOTA_CODE) Fota_DeInit(void)
{
  /* @Trace: FOTA_SUD_API_00006 */
  Fota_PflsDeinit();
  Fota_State = FOTA_IDLE;
  Fota_InitStatus = FOTA_MODULEDEINIT;
}
/*******************************************************************************
** Function Name        : Fota_ProcessReadActiveArea                          **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : Read active bank memory, it's 0xA or 0xB            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InEcuSwUnit                                         **
**                        OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpOut_MemoryArea                                    **
**                        LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_GetSoftwareModuleBlkBySwType                   **
**                        Fota_GetActivePartition                             **
**                        Fota_PflsGetActiveBank                              **
*******************************************************************************/
/* @Trace: FOTA_SRS_UDS_00002 */
/* polyspace-begin CODE-METRIC:LEVEL[Justified:Low] "High risk of code changes: Changes have wide impact" */
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessReadActiveArea
(
  VAR(uint16, AUTOMATIC) InEcuSwUnit,
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpOut_MemoryArea,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{

  VAR(Std_ReturnType,AUTOMATIC) retVal = E_NOT_OK;
  VAR(Fota_PartitionType,AUTOMATIC) LenActivePartition;
  VAR(Fota_ActAreaResType,AUTOMATIC) LenRetArea;
  VAR(uint8, AUTOMATIC) rub_UnUsed_1;
  VAR(uint8, AUTOMATIC) rub_UnUsed_2;
  VAR(uint8, AUTOMATIC) Fota_ActiveBankCheckValue = 0u;
  FOTA_UNUSED(InEcuSwUnit);
  FOTA_UNUSED(OpStatus);
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_GENERALREJECT;

  /* polyspace-begin DEFECT:USELESS_IF MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
  /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
  if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
  /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
  {

    if((Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTA_TYPE,&rub_UnUsed_1)==E_OK) && /* from Ldj function name should be changed */
     (Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTB_TYPE,&rub_UnUsed_2)==E_OK))
    {
      /* @Trace: FOTA_SUD_API_00009 */
      if(Fota_GetActivePartition(&LenActivePartition)==E_OK)
      {
        if(LenActivePartition==FOTA_PARTITION_A)
        {
          LenRetArea = FOTA_AREA_A;

          retVal = E_OK;
         /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          *LpOut_MemoryArea = (uint8)LenRetArea;
 
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else if(LenActivePartition==FOTA_PARTITION_B)
        {
          LenRetArea = FOTA_AREA_B;

          retVal = E_OK;
          /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          *LpOut_MemoryArea = (uint8)LenRetArea;
          
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
        {
          #if (FOTA_MODE==FOTA_FBL_MODE)
          LenRetArea = FOTA_AREA_B;

          retVal = E_OK;
           /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          *LpOut_MemoryArea = (uint8)LenRetArea;
           
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
          #else

          #endif
        }
      }
      else
      {
        #if (FOTA_MODE==FOTA_FBL_MODE)
        LenRetArea = FOTA_AREA_B;

        retVal = E_OK;
        *LpOut_MemoryArea = (uint8)LenRetArea;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        #else

        #endif
      }
    }
    
    else
    /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
    {
      
      /* @Trace: FOTA_SUD_API_00015 */
      retVal=Fota_PflsGetActiveBank(&Fota_ActiveBankCheckValue);
      if(E_OK==retVal)
      {
  /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        *LpOut_MemoryArea = Fota_ActiveBankCheckValue;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
      }
      else
      {
        *LpErrorCode = DCM_E_GENERALREJECT;
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_REQUEST_FAILED, retVal);
        #endif
      }
    }
  }
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
  /* polyspace-end DEFECT:USELESS_IF MISRA-C3:13.2,14.3 [Justified:Low] "if-condition depends on the configuration." */
  return retVal;
}
/* polyspace-end CODE-METRIC:LEVEL[Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessActivateSingleMem                       **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : Trigger Acitvate service                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InMemArea                                           **
**                        InEcuSwUnit                                         **
**                        OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpErrorCode                                         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_MemoryInstance                                 **
**                        Fota_State                                          **
**                        Fota_Gast_SwUnitTable                               **
**                        Function(s) invoked :                               **
**                        Fota_GetMemInstanceBySwUnit                         **
**                        Fota_CheckAllSwUnitVersionCheck                     **
**                        Fota_VersionCheckRequest                            **
**                        Fota_VersionCheckResult                             **
**                        Fota_ChkVfyKeyAllSwUnit                             **
**                        Fota_PflsEraseRequest                               **
**                        Fota_PflsGetJobResult                               **
**                        Fota_ChkActKey                                      **
**                        Fota_SetActKey_Request                              **
**                        Fota_SetKey_Result                                  **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:LEVEL,VG,FXLN,CALLS[Justified:Low] "High risk of code changes: Changes have wide impact" */
#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessActivateSingleMem
(
  VAR(uint8, AUTOMATIC) InMemArea,
  VAR(uint16, AUTOMATIC) InEcuSwUnit,
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  VAR(Std_ReturnType, AUTOMATIC) retVal = E_NOT_OK;
  VAR(Fota_SetKeyResultType, AUTOMATIC) setKeyResult;
  static Fota_SwapStatType swapState = FOTA_SWAP_ERR;
  static VAR(uint8, AUTOMATIC) indexSwUnit;
  #if FOTA_SOFTWARE_VERSION_CHECK
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC) memJobResult;
  uint32 eraseRomLength;
  static Fota_VersionCheckRequestType versionCheckRequest;
  Fota_JobResultType versionCheckResult;
  static boolean allSwUnitSvcAreGood;
  #endif
  static boolean recoverySwUnit;
  static Fota_SvcOrVerifyKeyType SvcOrVerifyKeyCheck;
  Fota_SoftwareType softwareType;
  Fota_KeyMgrType keyMagicType;
  softwareType = FOTA_RTSW_TYPE;
  
  FOTA_UNUSED(InMemArea);
  FOTA_UNUSED(InEcuSwUnit);
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_GENERALREJECT;

  /* @Trace: FOTA_SUD_API_00018 */
  if (OpStatus == DCM_INITIAL)
  {
    indexSwUnit = FOTA_ZERO;

    #if (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON)
    Fota_CheckAllSwUnitVersionCheck(&allSwUnitSvcAreGood);
    #endif
    SvcOrVerifyKeyCheck = FOTA_SVC_CHECK;
    if (E_OK == Fota_CheckNextSwUnitProgramming(&indexSwUnit,
                                          &recoverySwUnit, SvcOrVerifyKeyCheck))
    {
      (void)Fota_GetMemInstanceBySwUnit(indexSwUnit, &Fota_MemoryInstance);

      #if (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON)
      /* Set Version check process */
      Fota_State = FOTA_VERSION_CHECK_PROCESSING;

      if (FOTA_TRUE == allSwUnitSvcAreGood)
      {
        swapState = FOTA_SWAP_VERSION_CHECK_REQUEST;
      }
      else
      {
        swapState = FOTA_SWAP_RECOVERY_TRAILER_ERASE_ROM;
      }
      #else
      swapState = FOTA_SWAP_VERIFY_KEY_CHK;
      #endif
    }
    else
    {
      /* Don't have any SwUnit SVC is programed before */
      swapState = FOTA_SWAP_VERIFY_KEY_CHK;
    }
    /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
    retVal = DCM_E_FORCE_RCRRP;
    *LpErrorCode = DCM_E_POSITIVERESPONSE;
    /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  }
  /* polyspace+1 MISRA-C3:15.7 [Not a defect:Low] "the IF condition is used for the pratical case" */
  else if ((OpStatus == DCM_PENDING)||(OpStatus == DCM_FORCE_RCRRP_OK))
  {
    switch (swapState)
    {
      #if FOTA_SOFTWARE_VERSION_CHECK
      case FOTA_SWAP_VERSION_CHECK_REQUEST:
        /* @Trace: FOTA_SUD_API_00019 */
        versionCheckRequest = FOTA_VERSION_CHECK_CPD_REQUEST;
        Fota_VersionCheckRequest(versionCheckRequest, FOTA_ZERO);

        swapState = FOTA_SWAP_VERSION_CHECK_RESULT;
        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_SWAP_VERSION_CHECK_RESULT:
        /* @Trace: FOTA_SUD_API_00207 */
        versionCheckResult = Fota_VersionCheckResult();
        if (FOTA_JOB_PENDING == versionCheckResult)
        {
          /* Do nothing */
        }
        else if (FOTA_JOB_OK == versionCheckResult)
        {
          if (FOTA_FALSE == recoverySwUnit)
          {
            indexSwUnit = indexSwUnit + FOTA_ONE;
            if (E_OK == Fota_CheckNextSwUnitProgramming(&indexSwUnit,
                                      &recoverySwUnit, SvcOrVerifyKeyCheck))
            {
              swapState = FOTA_SWAP_VERSION_CHECK_REQUEST;
            }
            else
            {
              /* Finished all SwUnit for version check */
              Fota_State = FOTA_READY;
              swapState = FOTA_SWAP_VERIFY_KEY_CHK;
            }
          }
          else
          {
            /* Go to erase room after recovery trailer */
            Fota_State = FOTA_READY;
            swapState = FOTA_SWAP_ERASE;
          }
        }
        else
        {
          if (FOTA_VERSION_CHECK_CPD_REQUEST == versionCheckRequest)
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_SVC_UPDATE_TRAILER_FAILED, retVal);
            #endif
            Fota_SvcInitializeEraseRomSwUnit(&indexSwUnit);
            (void)Fota_CheckNextSwUnitProgramming(&indexSwUnit,
                                      &recoverySwUnit, SvcOrVerifyKeyCheck);

            swapState = FOTA_SWAP_RECOVERY_TRAILER_ERASE_ROM;
          }
          else if (FOTA_VERSION_CHECK_ERASE_ROM_REQUEST == versionCheckRequest)
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_SVC_RECOVERY_TRAILER_FAILED, retVal);
            #endif
            /* Go to erase rom after recovery failed */
            Fota_State = FOTA_READY;
            swapState = FOTA_SWAP_ERASE;
          }
          else
          {
            /* Do nothing */
          }
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_SWAP_RECOVERY_TRAILER_ERASE_ROM:
        /* Set Version check process */
        Fota_State = FOTA_VERSION_CHECK_PROCESSING;
        /* @Trace: FOTA_SUD_API_00208 */
        versionCheckRequest = FOTA_VERSION_CHECK_ERASE_ROM_REQUEST;

        Fota_VersionCheckRequest(versionCheckRequest, FOTA_ZERO);

        swapState = FOTA_SWAP_VERSION_CHECK_RESULT;
        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
      #endif /* #if FOTA_SOFTWARE_VERSION_CHECK */

      #if FOTA_SOFTWARE_VERSION_CHECK
      case FOTA_SWAP_ERASE:
        /* @Trace: FOTA_SUD_API_00210 */
        /* Erase area which same as routine-control erase
         * If version check enable, this delete except trailer
         */
        /* 1st Erase Area for sector which include header */
        eraseRomLength = Fota_VersionCheckEraseRomLength(indexSwUnit);

        swapState = FOTA_SWAP_ERASE_CHK;
        (void)Fota_GetMemInstanceBySwUnit(indexSwUnit, &Fota_MemoryInstance);

        if (E_OK == Fota_PflsEraseRequest(
             Fota_MemoryInstance,
             Fota_Gast_SwUnitTable[indexSwUnit].StartAddress,
             eraseRomLength))
        {
          swapState = FOTA_SWAP_ERASE_CHK;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_ERASE_REQUEST_FAILED, FOTA_ZERO);
          #endif
          swapState = FOTA_SWAP_ERR_VERSION;
        }
        retVal = DCM_E_PENDING;
        break;

      case FOTA_SWAP_ERASE_CHK:
        /* @Trace: FOTA_SUD_API_00211 */
        memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);

        if (memJobResult == MEM_JOB_PENDING)
        {
          /* Time for erase one sector in Chorus 10M is long (~1s)
           * => need return DCM_E_FORCE_RCRRP for transmit a pending response NRC78 to tester
           * this probelm is not occurn in RTSW due to task is managed by interrupt */
          #if (((FOTA_MODE == FOTA_FBL_MODE) && (FOTA_MCU_MEMORY_ACCESS_TYPE != FOTA_MMU_TYPE)) \
           && (FOTA_LARGE_SECTOR == STD_ON))
          retVal = DCM_E_FORCE_RCRRP;
          #else
          retVal = DCM_E_PENDING;
          #endif
        }
        else
        {
          if (memJobResult ==  MEM_JOB_FAILED)
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_ERASE_JOB_FAILED, FOTA_ZERO);
            #endif
          }
          /* Go to next SwUnit for recovery */
          indexSwUnit = indexSwUnit + FOTA_ONE;
          if (E_OK == Fota_CheckNextSwUnitProgramming(&indexSwUnit,
                                          &recoverySwUnit, SvcOrVerifyKeyCheck))
          {
            /* Go to recovery SwUnit */
            swapState = FOTA_SWAP_RECOVERY_TRAILER_ERASE_ROM;
          }
          else
          {
            /* Finish recovery and erase room for SwUnit have failed version*/
            swapState = FOTA_SWAP_ERR_VERSION;
          }
          retVal = DCM_E_PENDING;
        }
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
      #endif /* #if FOTA_SOFTWARE_VERSION_CHECK */

      case FOTA_SWAP_VERIFY_KEY_CHK:
        /* @Trace: FOTA_SUD_API_00209 */
        if (E_OK == Fota_ChkVfyKeyAllSwUnit(FOTA_TARGET_AREA))
        {
          indexSwUnit = FOTA_ZERO;
          swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE;
        }
        else
        {
          #if FOTA_SOFTWARE_VERSION_CHECK
          indexSwUnit = FOTA_ZERO;
          SvcOrVerifyKeyCheck = FOTA_VERIFY_KEY_CHECK;
          if (E_OK == Fota_CheckNextSwUnitProgramming(&indexSwUnit,
                                    &recoverySwUnit, SvcOrVerifyKeyCheck))
          {
            swapState = FOTA_SWAP_RECOVERY_TRAILER_ERASE_ROM;
          }
          else
          #endif
          {
            swapState = FOTA_SWAP_ERR;
          }
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_SWAP_ACTIVATE_KEY_WRITE:
        /* @Trace: FOTA_SUD_API_00212 */
        if (E_OK==Fota_ChkActKey(indexSwUnit,FOTA_TARGET_AREA))
        {
          indexSwUnit++;
          if (indexSwUnit < FOTA_NUM_OF_SWUNIT)
          {
            (void)Fota_GetMemInstanceBySwUnit(indexSwUnit, &Fota_MemoryInstance);
          }
          else
          {
            swapState = FOTA_SWAP_END;
          }
          retVal = DCM_E_PENDING;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        {
          (void)Fota_GetSoftwareTypeBySwUnitId(indexSwUnit, &softwareType);

          if (FOTA_FBL_TYPE == softwareType)
           /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
          {
            keyMagicType = FOTA_BMKEY_MGR;
          }
           /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
          else
          {
            keyMagicType = FOTA_FLKEY_MGR;
          }
          if (E_OK==Fota_SetActKey_Request(keyMagicType, indexSwUnit))
          {
            swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE_CHK;
            *LpErrorCode = DCM_E_POSITIVERESPONSE;
          }
          else
          {
            swapState = FOTA_SWAP_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_WRITE_REQUEST_FAILED, FOTA_ZERO);
            #endif
          }
          retVal = DCM_E_PENDING;
        }
        break;


      case FOTA_SWAP_ACTIVATE_KEY_WRITE_CHK:
        /* @Trace: FOTA_SUD_API_00213 */
        setKeyResult = Fota_SetKey_Result();
        if (FOTA_SETMAGICKEY_OK == setKeyResult)
        {
          if(E_OK==Fota_ChkActKey(indexSwUnit,FOTA_TARGET_AREA))
          {
            indexSwUnit++;
            if (indexSwUnit < FOTA_NUM_OF_SWUNIT)
            {
              (void)Fota_GetMemInstanceBySwUnit(indexSwUnit, &Fota_MemoryInstance);
              swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE;
            }
            else
            {
              swapState = FOTA_SWAP_END;
            }
            *LpErrorCode = DCM_E_POSITIVERESPONSE;
          }
          else
          {
            swapState = FOTA_SWAP_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
            #endif
          }
        }
        else if (FOTA_SETMAGICKEY_FAILED == setKeyResult)
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
          #endif
        }
        else
        {
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        retVal = DCM_E_PENDING;
        break;

      case FOTA_SWAP_END:
        /* @Trace: FOTA_SUD_API_00214 */
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        retVal = E_OK;
        Fota_ResetSvcResultAllSwUnit(FOTA_CPD_API, FOTA_ZERO);
        break;

      #if (FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON)
      case FOTA_SWAP_ERR_VERSION:

        *LpErrorCode = DCM_E_LOWERVERSIONDOWNLOADATTEMPT;
        retVal = E_NOT_OK;
        break;
      #endif

      case FOTA_SWAP_ERR:
      default:
        *LpErrorCode = DCM_E_GENERALREJECT;
        retVal = E_NOT_OK;
        break;
    }
  }
  return retVal;
}
#endif /* #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) */
/* polyspace-end CODE-METRIC:LEVEL,VG,FXLN,CALLS[Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessActivateDualMem                         **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : Trigger Swap memory service                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InMemArea                                           **
**                        InEcuSwUnit                                         **
**                        OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_ProgrammingSWUnitId                            **
**                        Fota_MemoryInstance                                 **
**                        Fota_Gast_SwUnitTable                               **
**                        Function(s) invoked :                               **
**                        Fota_GetTargetPartition                             **
**                        Fota_GetSwUnitIdByPartition                         **
**                        Fota_GetSwUnitIdByLabel                             **
**                        Fota_GetMemInstanceBySwUnit                         **
**                        Fota_PflsTgtAreaSet                                 **
**                        Fota_DualMemDownGradeChk_Callout                    **
**                        Fota_DualMemSwUnitsVerDependChk_Callout             **
**                        Fota_ChkVfyKeyAllSwUnit                             **
**                        Fota_ChkVfyKey                                      **
**                        Fota_SetTopPrioActKey_Request                       **
**                        Fota_ChkActKey                                      **
**                        Fota_GetSoftwareModuleBlkBySwType                   **
**                        Fota_SetActKey_Request                              **
**                        Fota_SetKey_Result                                  **
**                        Fota_MacUpdateRequest                               **
**                        Fota_MacUpdateResult                                **
**                        Fota_PflsSwapBankRequest                            **
**                        Fota_PflsGetJobResult                               **
**                        Fota_PflsEraseRequest                               **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:VG,CALLS,FXLN,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/* @Trace: FOTA_SRS_ES98765_02E_00021 FOTA_SRS_ES98765_02E_00029 FOTA_SRS_ES98765_02E_00033 FOTA_SRS_ES98765_02E_00032 */
/* @Trace: FOTA_SRS_ES98765_02E_00034 FOTA_SRS_ES98765_02E_00036 FOTA_SRS_UDS_00004 FOTA_SRS_UDS_00026 */
#if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessActivateDualMem
(
  VAR(uint8, AUTOMATIC) InMemArea,
  VAR(uint16, AUTOMATIC) InEcuSwUnit,
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  /* @Trace: FOTA_SUD_API_00035 */
  VAR(Std_ReturnType,AUTOMATIC) retVal = E_NOT_OK;
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC) memJobResult;
  VAR(Fota_SetKeyResultType, AUTOMATIC) setKeyResult;
  VAR(Fota_PartitionType,AUTOMATIC) TgtPart=FOTA_PARTITION_UNKNOWN;
  /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
  static Fota_SwapStatType swapState = FOTA_SWAP_ERR;
  VAR(Std_ReturnType,AUTOMATIC) retSetKey = E_NOT_OK;
  VAR(Fota_JobResultType,AUTOMATIC) retJobResult;
  #if((FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02) && \
  (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) && \
  (FOTA_STD_ON == FOTA_FBL_SWUNIT_USED))
  VAR(uint8, AUTOMATIC) rub_UnUsed;
  #endif
  Fota_SoftwareType softwareType;
  Fota_KeyMgrType keyMagicType;
 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_POSITIVERESPONSE;
 softwareType = FOTA_RTSW_TYPE;
  /* polyspace-begin MISRA-C3:12.1,15.7 [Justified:Low] "No Impact of this rule violation" */
  if(OpStatus == DCM_INITIAL)
  {
    
    /* @Trace: FOTA_SUD_API_00036 */
    #if(FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_01)
    if (E_OK == Fota_ValidateMemoryArea(InMemArea))
    {
      if(Fota_IsDualPartitionSwUnit(InEcuSwUnit)==E_OK)
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        if(Fota_GetTargetPartition(&TgtPart)==E_OK)
        {
          retVal = Fota_GetSwUnitIdByPartition(TgtPart,&Fota_ProgrammingSWUnitId);
        }
        else
         /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        {
          retVal = E_NOT_OK;
        }
         /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      }
     /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      {
        retVal = Fota_GetSwUnitIdByLabel(InEcuSwUnit, &Fota_ProgrammingSWUnitId);
      }
      /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
    }
    #elif (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02)
    FOTA_UNUSED(InMemArea);
    FOTA_UNUSED(InEcuSwUnit);
    #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_NON_MMU_TYPE)
    if (Fota_GetTargetPartition(&TgtPart)==E_OK)
    {
      retVal = Fota_GetSwUnitIdByPartition(TgtPart,&Fota_ProgrammingSWUnitId);
    }
    else
    {
      retVal = E_NOT_OK;
    }
    #else
    FOTA_UNUSED(TgtPart);
    Fota_ProgrammingSWUnitId = FOTA_ZERO;
    retVal = E_OK;
    #endif /* FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_NON_MMU_TYPE */
    #else
    FOTA_UNUSED(TgtPart);
    #endif /* FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02 */

    /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
     
    if (E_OK != retVal)
    /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
    {
      /* Server shall respond NRC 31 */
      *LpErrorCode = DCM_E_REQUESTOUTOFRANGE;
      swapState = FOTA_SWAP_ERR;
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_BLOCKID_INVALID, retVal);
      #endif
    }
     /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
    else
    {
      (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);

      #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
      (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_ALT_ADDR);
      #endif

      #if (FOTA_DOWN_GRADE_PROTECTION_USED == FOTA_STD_ON)
      swapState = FOTA_SWAP_DOWNGRADE_CHECK;
      #else
      swapState = FOTA_SWAP_DEPENDENCY_CHECK;
      #endif
      retVal = DCM_E_FORCE_RCRRP;
      *LpErrorCode = DCM_E_POSITIVERESPONSE;
    }
  }
  else if(OpStatus == DCM_PENDING || OpStatus == DCM_FORCE_RCRRP_OK)
  {
    switch(swapState)
    {
      #if (FOTA_DOWN_GRADE_PROTECTION_USED == FOTA_STD_ON)
      case FOTA_SWAP_DOWNGRADE_CHECK:
      /* polyspace+1 MISRA-C3:10.5 [Not a defect:Low] "It is not effect, the enum is casted to usigned type" */
        retJobResult = (Fota_JobResultType)Fota_DualMemDownGradeChk_Callout();

        if(retJobResult == FOTA_JOB_OK)
        {
          swapState = FOTA_SWAP_DEPENDENCY_CHECK;
        }
        else if(retJobResult == FOTA_JOB_FAILED)
        {
          swapState = FOTA_SWAP_ERASE;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_DUALMEM_DOWNGRADE_DETECT, FOTA_ZERO);
          #endif
        }
        else
        {
          /* Do Nothing */
        }
        retVal  = DCM_E_PENDING;
        break;
      #endif

      case FOTA_SWAP_DEPENDENCY_CHECK:
        /* polyspace +1 MISRA-C3:10.5 [Not a defect:Low] "No impact of this rule violation" */
        retJobResult = (Fota_JobResultType)Fota_DualMemSwUnitsVerDependChk_Callout();

        if(retJobResult == FOTA_JOB_OK)
        {
          swapState = FOTA_SWAP_VERIFY_KEY_CHK;
        }
        else if(retJobResult == FOTA_JOB_FAILED)
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_SW_UNIT_DEPENDENCY_FAILED, FOTA_ZERO);
          #endif
        }
        else
        {
          /* Do Nothing */
        }
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
        retVal  = DCM_E_PENDING;
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
        /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        break;

      case FOTA_SWAP_VERIFY_KEY_CHK:
        /* @Trace: FOTA_SUD_API_00037 */
        #if((FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02)&&(FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)) /* MMU Type and 2ndGen */
        if(E_OK==Fota_ChkVfyKeyAllSwUnit(FOTA_TARGET_AREA))
        #else
        if (E_OK==Fota_ChkVfyKey(Fota_ProgrammingSWUnitId,FOTA_TARGET_AREA))
        #endif
        {
          swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_VERIFY_KEY_SW_UNIT_ID_FAILED, FOTA_ZERO);
          #endif
        }
        retVal = DCM_E_PENDING;
        break;

      case FOTA_SWAP_ACTIVATE_KEY_WRITE:
        /* @Trace: FOTA_SUD_API_00216 */
        (void)Fota_GetSoftwareTypeBySwUnitId(Fota_ProgrammingSWUnitId, &softwareType);
        if (FOTA_FBL_TYPE == softwareType)
        /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified,IF condition always evaluates false. Avoid to "Unreachable code" of the polyspace" */
        {
          keyMagicType = FOTA_BMKEY_MGR;
        }
        else
        {
          keyMagicType = FOTA_FLKEY_MGR;
        }
        #if(FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_NON_MMU_TYPE)

        retSetKey=Fota_SetTopPrioActKey_Request(keyMagicType, Fota_ProgrammingSWUnitId);

        if(retSetKey==E_OK)
        {
          swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE_CHK;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        {
          if(retSetKey==FOTA_E_NOT_OK_STORIGE_FULL)
          {
            swapState = FOTA_SWAP_ERR_CNT_OVER;
          }
          else
          {
            swapState = FOTA_SWAP_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_STORAGE_FAILED, retVal);
            #endif
          }
        }
        #else
        #if(FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02)
        if (E_OK == Fota_ChkActKey(Fota_ProgrammingSWUnitId,FOTA_TARGET_AREA))
        {
          Fota_ProgrammingSWUnitId++;
          if (Fota_ProgrammingSWUnitId < FOTA_NUM_OF_SWUNIT)
          {
            (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);

            #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
            (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_ALT_ADDR);
            #endif
          }
          else
          {
            #if(FOTA_STD_ON == FOTA_FBL_SWUNIT_USED)
            if(Fota_GetSoftwareModuleBlkBySwType(FOTA_FBL_TYPE,&rub_UnUsed)==E_OK)
            {
              swapState = FOTA_SWAP_SECURE_BOOT_MAC_UPDATE;
            }
            else
            #endif
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
            {
              swapState = FOTA_SWAP_CMD;
            }
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
          }
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        #endif
        {
          retSetKey=Fota_SetActKey_Request(keyMagicType, Fota_ProgrammingSWUnitId);

          if(retSetKey==E_OK)
          {
            swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE_CHK;
            *LpErrorCode = DCM_E_POSITIVERESPONSE;
          }
          else
          {
            swapState = FOTA_SWAP_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_WRITE_REQUEST_FAILED, FOTA_ZERO);
            #endif
          }
        }
        #endif
        retVal = DCM_E_PENDING;
        break;

      case FOTA_SWAP_ACTIVATE_KEY_WRITE_CHK:
        /* @Trace: FOTA_SUD_API_00217 */
        setKeyResult = Fota_SetKey_Result();
        if (FOTA_SETMAGICKEY_OK == setKeyResult)
        {
          #if((FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02) && (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE))
          if (E_OK == Fota_ChkActKey(Fota_ProgrammingSWUnitId,FOTA_TARGET_AREA))
          {
            /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] " CP44-15732 comment_1. This function do not re-enter within processing, so datarace can be ignored */
            Fota_ProgrammingSWUnitId++;
            if (Fota_ProgrammingSWUnitId < FOTA_NUM_OF_SWUNIT)
            {
              (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);

              #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
              (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_ALT_ADDR);
              #endif

              swapState = FOTA_SWAP_ACTIVATE_KEY_WRITE;
            }
            else
            {
              #if(FOTA_STD_ON == FOTA_FBL_SWUNIT_USED)
              if (Fota_GetSoftwareModuleBlkBySwType(FOTA_FBL_TYPE, &rub_UnUsed)==E_OK)
              {
                swapState = FOTA_SWAP_SECURE_BOOT_MAC_UPDATE;
              }
              else
              #endif
              /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
              {
                swapState = FOTA_SWAP_CMD;
              }
              /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
            }
          }
          else
          {
            swapState = FOTA_SWAP_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
            #endif            
          }
          #else
    /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
          {
            swapState = FOTA_SWAP_CMD;
          }
    /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
          #endif
        }
        else if (FOTA_SETMAGICKEY_FAILED == setKeyResult)
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
          #endif
        }
        else
        {
          /* Do nothing */
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the MCU." */
      /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      #if(FOTA_STD_ON == FOTA_FBL_SWUNIT_USED)
      case FOTA_SWAP_SECURE_BOOT_MAC_UPDATE:
        /* @Trace: FOTA_SUD_API_00218 */
        Fota_MacUpdateRequest();
        swapState = FOTA_SWAP_SECURE_BOOT_MAC_UPDATE_CHK;
        retVal  = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
      break;
      /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_SWAP_SECURE_BOOT_MAC_UPDATE_CHK:
        /* @Trace: FOTA_SUD_API_00219 */
        retJobResult = Fota_MacUpdateResult();

        if(retJobResult == FOTA_JOB_OK)
        {
          swapState = FOTA_SWAP_CMD;
        }
        else if(retJobResult == FOTA_JOB_FAILED)
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_MAC_UPDATE_RESULT_FAILED, FOTA_ZERO);
          #endif
        }
        else
        {
          /* Do Nothing */
        }
        retVal  = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
        #endif
      /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the MCU." */

      case FOTA_SWAP_CMD:
        /* @Trace: FOTA_SUD_API_00220 */
        if(E_OK == Fota_PflsSwapBankRequest())
        {
          swapState = FOTA_SWAP_CMD_CHK;
        }
        else
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_PFLS_SWAP_BANK_FAILED, retVal);
          #endif
        }
        retVal  = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_SWAP_CMD_CHK:
        /* @Trace: FOTA_SUD_API_00221 */
        memJobResult = Fota_PflsGetJobResult(FOTA_ZERO);
        if (MEM_JOB_OK == memJobResult)
        {
          swapState = FOTA_SWAP_END;
        }
        else if (MEM_JOB_FAILED == memJobResult)
        {
          swapState = FOTA_SWAP_ERR;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_VERIFY_JOB_FAILED, retVal);
          #endif
        }
        else
        {
          /* Do nothing */
        }
        retVal  = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
/* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_SWAP_ERASE:
        /* @Trace: FOTA_SUD_API_00222 */
        /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        if(E_OK == Fota_DualMemSwUnitsEraseChk_Callout(Fota_ProgrammingSWUnitId))
        {
        /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
          #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) /* MMU Dual */
          (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_ALT_ADDR);
          #else
          (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_STD_ADDR);
          #endif
          if (E_OK == Fota_PflsEraseRequest(
                    Fota_MemoryInstance,
                    Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].StartAddress,
                    Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].EndAddress - Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].StartAddress + 1))
          {
            swapState  = FOTA_SWAP_ERASE_CHK;
          }
          else
          {
            swapState = FOTA_SWAP_ERR_VERSION;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_ERASE_REQUEST_FAILED, retVal);
            #endif
          }
        }
        else
        {
          if(Fota_ProgrammingSWUnitId >= (Fota_NumOfSwUnit-FOTA_ONE))
          {
            Fota_ProgrammingSWUnitId=FOTA_ZERO;
            swapState = FOTA_SWAP_ERR_VERSION;
          }
          else
          {
            /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] " CP44-15732 comment_1. This function do not re-enter within processing, so datarace can be ignored */
            Fota_ProgrammingSWUnitId++;
            (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
            swapState = FOTA_SWAP_ERASE;
          }
        }

        retVal  = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
/* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_SWAP_ERASE_CHK:
        /* @Trace: FOTA_SUD_API_00223 */
        memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);

        if (memJobResult == MEM_JOB_PENDING)
        {
          #if (((FOTA_MODE == FOTA_FBL_MODE) && (FOTA_MCU_MEMORY_ACCESS_TYPE != FOTA_MMU_TYPE)) \
              && (FOTA_LARGE_SECTOR == STD_ON))
          retVal = DCM_E_FORCE_RCRRP;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
          break;
          #else
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
          #endif
        }
        else if (memJobResult ==  MEM_JOB_OK)
        {
          #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) && (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02))/* MMU Dual */

          /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */
          if(Fota_ProgrammingSWUnitId >= (Fota_NumOfSwUnit-FOTA_ONE))
          {
            Fota_ProgrammingSWUnitId=FOTA_ZERO;
            swapState = FOTA_SWAP_ERR_VERSION;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_PROGRAMING_SW_UNIT_ID_FAILED, retVal);
            #endif
          }
          else
          {
            /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] " CP44-15732 comment_1. This function do not re-enter within processing, so datarace can be ignored */
            Fota_ProgrammingSWUnitId++;
            (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
            swapState = FOTA_SWAP_ERASE;
          }
          /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */

          #else
          swapState = FOTA_SWAP_ERR_VERSION;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_MEMORY_ACCESS_TYPE_IMPLEMENTATION_RULE_INVALID, retVal);
          #endif
          #endif
        }
        else
        {
          swapState = FOTA_SWAP_ERR_VERSION;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_SWAP_ACTIVE_AREA_SID, FOTA_E_VERIFY_JOB_FAILED, retVal);
          #endif
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_SWAP_END:
        /* @Trace: FOTA_SUD_API_00224 */
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        retVal = E_OK;

        break;
/* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_SWAP_ERR_VERSION:
        /* @Trace: FOTA_SUD_API_00225 */
        *LpErrorCode = DCM_E_LOWERVERSIONDOWNLOADATTEMPT;
        retVal = E_NOT_OK;

        break;
/* polyspace+1 RTE:UNR [Not a defect:Low] "Not impact,the switch case is depend on configuration " */
      case FOTA_SWAP_ERR_CNT_OVER:
        /* @Trace: FOTA_SUD_API_00226 */
        *LpErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        retVal = E_NOT_OK;

        break;

      case FOTA_SWAP_ERR:
      default:
        /* @Trace: FOTA_SUD_API_00227 */
        /* polyspace-begin MISRA-C3:14.3 [Justified:Low] "No Impact of this rule violation" */
        if (DCM_E_POSITIVERESPONSE == *LpErrorCode)
        {
          *LpErrorCode = DCM_E_GENERALREJECT;
        }
        else
        /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition always evaluates true.Avoid to "Unreachable code" of the polyspace. " */
        {
          /* Do nothing */
        }
        /* polyspace-end MISRA-C3:14.3 [Justified:Low] "No Impact of this rule violation" */
        retVal = E_NOT_OK;
        break;
    }
  }
  return retVal;
}
#endif /* #if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE) */
/* polyspace-end CODE-METRIC:VG,CALLS,FXLN,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessEraseTargetArea                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Server Function in the Client-Server Port Comm      **
**                        DCM Call this to erase target area (RID = 0x0212)   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InMemArea                                           **
**                        InEcuSwUnit                                         **
**                        OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpOut_MemoryArea                                    **
**                        LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_ProgrammingSWUnitId                            **
**                        Fota_MemoryInstance                                 **
**                        Fota_SvcResultAllSwUnit                             **
**                        Fota_State                                          **
**                        Fota_PflsEraseAlignmentValue                        **
**                        BlockProcessingRulePtr                              **
**                        Fota_MetaDataRequestCheck                           **
**                        Fota_AreaSyncState                                  **
**                        Function(s) invoked :                               **
**                        Fota_IsDualPartitionSwUnit                          **
**                        Fota_GetTargetPartition                             **
**                        Fota_GetSwUnitIdByPartition                         **
**                        Fota_GetSwUnitIdByLabel                             **
**                        Fota_GetMemInstanceBySwUnit                         **
**                        Fota_PflsGetFlashAlignment                          **
**                        Fota_SvcInit                                        **
**                        Fota_AreaSyncRequest                                **
**                        Fota_VersionCheckRequest                            **
**                        Fota_VersionCheckResult                             **
**                        Fota_PflsTgtAreaSet                                 **
**                        Fota_PflsGetSectorSize                              **
**                        Fota_ValidateAddressLengthAlignment                 **
**                        Fota_PflsEraseRequest                               **
**                        Fota_PflsGetJobResult                               **
**                        Fota_PflsCancelReq                                  **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:CALLS,FXLN,VG,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/* @Trace: FOTA_SRS_UDS_00003 FOTA_SRS_UDS_00013 FOTA_SRS_ES98765_02E_00019 FOTA_SRS_UDS_00024 */
/* @Trace: FOTA_SRS_ES98765_02E_00033 FOTA_SRS_GENSEC_00007 FOTA_SRS_UDS_00001 */
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessEraseTargetArea
(
  VAR(uint8, AUTOMATIC) InMemArea,
  VAR(uint16, AUTOMATIC) InEcuSwUnit,
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpOut_MemoryArea,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  VAR(Std_ReturnType,AUTOMATIC) retVal = E_NOT_OK;
  VAR(uint32,AUTOMATIC) startAddress;
  VAR(uint32,AUTOMATIC) eraseLen;

  VAR(Mem_76_Pfls_JobResultType,AUTOMATIC) ren_CodeEraseReport;
  P2VAR(Fota_FirmwareType, AUTOMATIC, FOTA_APPL_DATA) firmwareInfoPtr;
  P2CONST(Fota_SwModule, AUTOMATIC, FOTA_APPL_CONST) swUnitHandlePtr;
  /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
  static VAR(Fota_PartitionType,AUTOMATIC) TgtPart;
  #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) &&\
       (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02))
  VAR(Fota_JobResultType,AUTOMATIC) rue_SyncJobResult;
  #endif

  /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
  static VAR(Fota_EraseStatType,AUTOMATIC) eraseState = FOTA_ERASE_ERR;

  #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
    (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
  VAR(uint32,AUTOMATIC) blkTrailerAddress;
  Fota_JobResultType versionCheckResult;
  #endif
 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_GENERALREJECT;
  if (OpStatus == DCM_INITIAL)
  {
    /* @Trace: FOTA_SUD_API_00045 */
    TgtPart = FOTA_PARTITION_UNKNOWN;
    #if ((FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE) &&\
      (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_01))
    retVal = Fota_ValidateMemoryArea(InMemArea);
    #else
    FOTA_UNUSED(InMemArea);
    retVal = E_OK;
    #endif

    /* polyspace-begin DEFECT:USELESS_IF MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
    /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
    if (E_OK == retVal)
    {
      #if(FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_NON_MMU_TYPE)
      if(Fota_IsDualPartitionSwUnit(InEcuSwUnit)==E_OK)
      {
        if(Fota_GetTargetPartition(&TgtPart)==E_OK)
        {
          retVal = Fota_GetSwUnitIdByPartition(TgtPart,&Fota_ProgrammingSWUnitId);
        }
        else
       /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        {
          retVal = E_NOT_OK;
        }
         /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      }
      else
      #else
      FOTA_UNUSED(TgtPart);
      #endif
      /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
      {
        retVal = Fota_GetSwUnitIdByLabel(InEcuSwUnit, &Fota_ProgrammingSWUnitId);
      }
      (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
      (void)Fota_PflsGetFlashAlignment(Fota_MemoryInstance, &Fota_PflsWriteAlignmentValue);
      /* polyspace+1 RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      if (E_OK == retVal)
      {
        #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
        if ((FOTA_TRUE == Fota_SecureFlashDecryptOn) &&
          (NULL_PTR != BlockProcessingRulePtr))
        /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
        {
          retVal = Fota_FreeDecryptProcessing(BlockProcessingRulePtr);
          if (E_OK != retVal)
          {
            *LpErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          }
          else
          {
            /* Do nothing */
          }
          Fota_SecureFlashDecryptOn = FOTA_FALSE;
          BlockProcessingRulePtr = NULL_PTR;
        }
        /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
        #endif
      }
    }
    /* polyspace-end DEFECT:USELESS_IF MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */

    if (E_OK != retVal)
    {
      /* polyspace-begin MISRA-C3:14.3 [Justified:Low] "IF condition is depend on configuration. " */
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      if (DCM_E_CONDITIONSNOTCORRECT != *LpErrorCode)
      /* polyspace-end MISRA-C3:14.3 [Justified:Low] "IF condition is depend on configuration. " */
      {
        /* Server shall respond NRC 31 */
        *LpErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_ERASE_MEMORY_SID, FOTA_E_BLOCKID_INVALID, retVal);
      #endif
    }
    else
    {
      /* set the erase state to be FOTA_ERASE_CMD */
      #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) &&\
        (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02))

      /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
      #if (FOTA_NUM_OF_SWUNIT > 1U)
      if (Fota_Use_EraseSwUnitSync() == E_OK)
      {
        eraseState = FOTA_ERASE_RESYNC_REQUEST;
      }
      else
      {
        eraseState = FOTA_ERASE_CMD;
      }
      #else
      eraseState = FOTA_ERASE_CMD;
      #endif /* #if (FOTA_NUM_OF_SWUNIT > 1U) */
      /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
      #else /* #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) &&\
                 (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02)) */
	    #if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
            (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      Fota_ResetSvcResultAllSwUnit(FOTA_ERASE_API, Fota_ProgrammingSWUnitId);
      #endif
	  
      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      retVal = Fota_SvcInit(Fota_ProgrammingSWUnitId);
      if (E_OK == retVal)
      {
        #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
        if (Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].CheckVersion ==
                                                          FOTA_VERSION_USED)
        #endif
        {
          eraseState = FOTA_ERASE_VERSION_CHECK_REQUEST;
        }
        #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
        else
        {
          eraseState = FOTA_ERASE_CMD;
        }
        #endif
      }
      else
      {
        eraseState = FOTA_ERASE_ERR_VERSION;
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_ERASE_MEMORY_SID, FOTA_E_SVC_INIT_FAILED, FOTA_ZERO);
        #endif
      }
      #else
      eraseState = FOTA_ERASE_CMD;
      #endif /* #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
                  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE)) */
      #endif /* #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) &&\
                 (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02)) */
      retVal = DCM_E_FORCE_RCRRP;
    }
  }
  else if ((OpStatus == DCM_FORCE_RCRRP_OK) || (OpStatus == DCM_PENDING))
  {
    switch (eraseState)
    {
      #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) &&\
        (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02))

      case FOTA_ERASE_RESYNC_REQUEST:
        /* @Trace: FOTA_SUD_API_00046 */
        /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        if(Fota_AreaSyncRequest(FOTA_SYNC_VERIFIED_NONACT_SWUNIT)==E_OK)
        {
          eraseState = FOTA_ERASE_RESYNC_RESULT;
        }
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        retVal = DCM_E_PENDING;
        /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        break;

      case FOTA_ERASE_RESYNC_RESULT:
        /* @Trace: FOTA_SUD_API_00228 */
        rue_SyncJobResult = Fota_AreaSyncGetJobResult();

        /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        if(rue_SyncJobResult==FOTA_JOB_OK)
        {
          (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
          eraseState = FOTA_ERASE_CMD;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else if(rue_SyncJobResult==FOTA_JOB_PENDING)
        {
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        {
          eraseState = FOTA_ERASE_ERR_SYNC;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ERASE_MEMORY_SID, FOTA_E_ERASE_REQUEST_FAILED, FOTA_ZERO);
          #endif
        }
        retVal = DCM_E_PENDING;
        break;
      #endif

      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      case FOTA_ERASE_VERSION_CHECK_REQUEST:
        /* @Trace: FOTA_SUD_API_00229 */
        Fota_VersionCheckRequest(
                            FOTA_VERSION_CHECK_BEFORE_ERASE_REQUEST, FOTA_ZERO);
        Fota_State = FOTA_VERSION_CHECK_PROCESSING;
        eraseState = FOTA_ERASE_VERSION_CHECK_RESULT;
        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_ERASE_VERSION_CHECK_RESULT:
        /* @Trace: FOTA_SUD_API_00230 */
        versionCheckResult = Fota_VersionCheckResult();
        if (FOTA_JOB_PENDING == versionCheckResult)
        {
          retVal  = DCM_E_PENDING;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else if (FOTA_JOB_OK == versionCheckResult)
        {
          Fota_State = FOTA_READY;
          eraseState = FOTA_ERASE_CMD;
          retVal     = DCM_E_PENDING;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else /* (FOTA_JOB_FAILED = versionCheckResult) */
        {
          eraseState = FOTA_ERASE_ERR_VERSION;
          retVal     = DCM_E_PENDING;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ERASE_MEMORY_SID, FOTA_E_SVC_ERASE_CHECK_FAILED, FOTA_ZERO);
          #endif
        }
        break;
      #endif

      case FOTA_ERASE_CMD:
        #if ((FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE) &&\
        (FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02))
        if(Fota_AreaSyncState != FOTA_SYNC_IDLE)
        {
          retVal = DCM_E_PENDING;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        #endif
        {
          (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
          /* @Trace: FOTA_SUD_API_00231 */
          swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];
          #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
          (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance, FOTA_ALT_ADDR);
          #endif
          /* get start address for erase operation  */
            /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          startAddress = swUnitHandlePtr->StartAddress;
            
          /* memory length to be erased   */
          eraseLen = swUnitHandlePtr->EndAddress - swUnitHandlePtr->StartAddress + FOTA_ONE;

          firmwareInfoPtr = swUnitHandlePtr->FirmwareInfoPtr;
      /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
          if (NULL_PTR != firmwareInfoPtr)
          {
            #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
            Fota_MetaDataRequestCheck = FOTA_FALSE;
            #endif
            #if ((FOTA_STD_ON == FOTA_SF20_ENABLE) || (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED))
            BlockProcessingRulePtr = firmwareInfoPtr->FwBlockProcessingInfo;
            #endif
          }
          #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
            (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
          #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
          if (Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].CheckVersion ==
                                                            FOTA_VERSION_USED)
          #endif
          {
            blkTrailerAddress =
              Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].BlkTrailerAddress;

            if ((swUnitHandlePtr->StartAddress + eraseLen) > blkTrailerAddress)
            {

              retVal = Fota_PflsGetSectorSize(Fota_MemoryInstance, &Fota_PflsEraseAlignmentValue,
                                    blkTrailerAddress);
              if (E_OK == retVal)
              {
                /* Erase memory without trailer area */
                eraseLen = (blkTrailerAddress - (blkTrailerAddress %
                  Fota_PflsEraseAlignmentValue)) - swUnitHandlePtr->StartAddress;
              }
              else
              {
                eraseState = FOTA_ERASE_ERR_VERSION;
                retVal     = DCM_E_PENDING;
                #if (FOTA_DEV_ERROR_DETECT == STD_ON)
                /* Report Det Error */
                Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                  FOTA_ERASE_MEMORY_SID, FOTA_E_PFLS_GET_SECTOR_SIZE_FAILED, FOTA_ZERO);
                #endif
              }
            }
            else
        /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
            {
              #if (FOTA_DEV_ERROR_DETECT == STD_ON)
              /* Report Det Error */
              Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_ERASE_MEMORY_SID, FOTA_E_SVC_ERASE_LENGTH_INVALID, FOTA_ZERO);
              #endif
              eraseState = FOTA_ERASE_ERR_VERSION;
              retVal     = DCM_E_PENDING;
            }
        /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          }
          #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
          else
          {
            retVal = E_OK;
          }
          #endif
          if (E_OK == retVal)
          #endif
          {
            retVal = Fota_ValidateAddressLengthAlignment(startAddress, eraseLen);
            if (E_OK == retVal)
            {
              if (E_OK == Fota_PflsEraseRequest(\
                    Fota_MemoryInstance, \
                    startAddress, \
                    eraseLen))
              {
              eraseState = FOTA_ERASE_CHK;
              *LpErrorCode = DCM_E_POSITIVERESPONSE;
              }
              else
              {
              eraseState = FOTA_ERASE_ERR;
              #if (FOTA_DEV_ERROR_DETECT == STD_ON)
              /* Report Det Error */
              Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_ERASE_MEMORY_SID, FOTA_E_PFLS_ERASE_REQUEST_FAILED, retVal);
              #endif
              }
            }
            else
            {
              eraseState = FOTA_ERASE_ERR;
              #if (FOTA_DEV_ERROR_DETECT == STD_ON)
              /* Report Det Error */
              Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_ERASE_MEMORY_SID, FOTA_E_ADDRESS_LENGTH_INVALID, retVal);
              #endif
            }
            retVal     = DCM_E_PENDING;
          }
        }


        break;

      case FOTA_ERASE_CHK:
        /* @Trace: FOTA_SUD_API_00047 */
        ren_CodeEraseReport = Fota_PflsGetJobResult(Fota_MemoryInstance);

        if(ren_CodeEraseReport == MEM_JOB_PENDING)
        {
          /* Time for erase one sector in Chorus 10M is long (~1s)
          * => need return DCM_E_FORCE_RCRRP for transmit a pending response NRC78 to tester
          * this probelm is not occurn in RTSW due to task is managed by interrupt */
          #if (((FOTA_MODE == FOTA_FBL_MODE) && (FOTA_MCU_MEMORY_ACCESS_TYPE != FOTA_MMU_TYPE)) \
          && (FOTA_LARGE_SECTOR == STD_ON))
          retVal  = DCM_E_FORCE_RCRRP;
          #else
          retVal = DCM_E_PENDING;
          #endif
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else if(ren_CodeEraseReport==MEM_JOB_OK)
        {
          eraseState = FOTA_ERASE_END;
          retVal = DCM_E_PENDING;
          *LpErrorCode = DCM_E_POSITIVERESPONSE;
        }
        else
        {
          eraseState = FOTA_ERASE_ERR;
          retVal = DCM_E_PENDING;
        }
        break;

      case FOTA_ERASE_END:
        /* @Trace: FOTA_SUD_API_00048 */
        #if(FOTA_IMPLEMENTATION_RULE==FOTA_OTA_ES98765_02)
        if(TgtPart==FOTA_PARTITION_A)
       /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        {
          LpOut_MemoryArea[FOTA_ZERO] = (uint8)FOTA_AREA_A;
        }
       /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        else if(TgtPart==FOTA_PARTITION_B)
         /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        {
          LpOut_MemoryArea[FOTA_ZERO] = (uint8)FOTA_AREA_B;
        }
         /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        else
        {
          LpOut_MemoryArea[FOTA_ZERO] = (uint8)FOTA_AREA_UNKNOWN;
        }
        #else
          FOTA_UNUSED(LpOut_MemoryArea);
        #endif
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        Fota_State = FOTA_INIT;
        retVal = E_OK;
        break;

      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      case FOTA_ERASE_ERR_VERSION:
        /* @Trace: FOTA_SUD_API_00049 */
        *LpErrorCode = DCM_E_LOWERVERSIONDOWNLOADATTEMPT;
        retVal = E_NOT_OK;
        break;
      #endif
 /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_ERASE_ERR_SYNC:
        *LpErrorCode = DCM_E_GENERALREJECT;
        retVal = E_NOT_OK;
        break;

      case FOTA_ERASE_ERR:
      default :
        /* @Trace: FOTA_SUD_API_00232 */
        *LpErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        retVal = E_NOT_OK;
        break;
    }
  }
  /* @Trace: FOTA_SUD_API_00050 */
  else if (OpStatus == DCM_CANCEL)
  {
    (void)Fota_PflsCancelReq(Fota_MemoryInstance);
    retVal = DCM_WRITE_FAILED;
  }
  else
  {
    retVal = DCM_WRITE_FAILED;
  }

  return retVal;
}
/* polyspace-end CODE-METRIC:CALLS,FXLN,VG,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessRequestDownload                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : DCM CallOut function call this to request download  **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                        DataFormatIdentifier                                **
**                        MemoryAddress                                       **
**                        MemorySize                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpBlockLength                                       **
**                        LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Write                                          **
**                        Fota_State                                          **
**                        Fota_Retransfer                                     **
**                        Fota_SecureFlashDecryptOn                           **
**                        Fota_ProgrammingFwBlockId                           **
**                        BlockProcessingRulePtr                              **
**                        Fota_MetaDataRequestCheck                           **
**                        Function(s) invoked :                               **
**                        Fota_CheckMetadataArea                              **
**                        Fota_CheckMetadataSize                              **
**                        Fota_CheckFwBlockArea                               **
**                        Fota_DecryptStart                                   **
**                        Fota_CheckAddressIsSignatureArea                    **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:LEVEL,VG,PARAM [Justified:Medium] "High risk of code changes: Changes have wide impact" */
/* @Trace: FOTA_SRS_ES95489_52E_00004 FOTA_SRS_ES95489_52E_00005 FOTA_SRS_ES95489_52E_00006 FOTA_SRS_UDS_00006 FOTA_SRS_ES98765_01E_00005*/
/* @Trace: FOTA_SRS_ES98765_02E_00024 FOTA_SRS_ES98765_01E_00011 FOTA_SRS_ES98765_01E_00012 FOTA_SRS_ES98765_01E_00013 */
/* @Trace: FOTA_SRS_ES98765_01E_00006 FOTA_SRS_ES98765_02E_00025 FOTA_SRS_ES98765_02E_00026 FOTA_SRS_ES98765_02E_00039 FOTA_SRS_UDS_00014 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_ProcessRequestDownload
(
  Dcm_OpStatusType OpStatus,
  uint8 DataFormatIdentifier,
  uint32 MemoryAddress,
  uint32 MemorySize,
  P2VAR(uint32, AUTOMATIC, FOTA_PRIVATE_DATA) LpBlockLength,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  Std_ReturnType retVal = E_NOT_OK;
     /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *(LpBlockLength) = FOTA_TP_BLOCK_LENGTH;
     
  Fota_Write.BlockType = FOTA_UNKNOWN;

  FOTA_UNUSED(DataFormatIdentifier);

  if ((OpStatus == DCM_INITIAL) || (OpStatus == DCM_PENDING))
  {
    if ((Fota_State==FOTA_INIT) || (Fota_State==FOTA_READY))
    {
      #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
      if (FOTA_TRUE == Fota_CheckMetadataArea(MemoryAddress))
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        /* @Trace: FOTA_SUD_API_00067 */
        if (FOTA_TRUE == Fota_CheckMetadataSize(MemorySize))
        {
          if (FOTA_TRUE == Fota_MetaDataRequestCheck)
          {
          /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
            *LpErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            retVal = E_NOT_OK;
          }
          else
          {
            retVal = E_OK;
          }
          Fota_Write.BlockType = FOTA_METADATA;
          Fota_ProgrammingFwBlockId = FOTA_INVALID_INDEX;
          Fota_MetaDataRequestCheck = FOTA_TRUE;
        }
        else
        {
          /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          *LpErrorCode = DCM_E_REQUESTOUTOFRANGE;
          retVal = E_NOT_OK;
        }
      }
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      #endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
      /* @Trace: FOTA_SUD_API_00068 */
      if (FOTA_TRUE == Fota_CheckFwBlockArea(MemoryAddress))
      {
        Fota_Write.BlockType = FOTA_FIRMWARE;
        retVal = E_OK;

        #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
        /* This data chunk belong to another Fw block. Check whether a
          decryption flow is on-going. */
        /* polyspace +3 RTE:UNR [Not a defect:Low] "Not a effect, IF condition is depend on configuration" */
        /* polyspace +2 RTE:IDP [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        if (FOTA_TRUE == BlockProcessingRulePtr[\
                          Fota_ProgrammingFwBlockId].IsEncrypted)
        {
          if (FOTA_TRUE == Fota_MetaDataRequestCheck)
          {
            if (FOTA_FALSE == Fota_SecureFlashDecryptOn)
            {
              /* No previous decryption job is on-going. Check if new Fw block
                needs decryption so start a new decryption flow.*/
              if(Fota_DecryptStart(BlockProcessingRulePtr[\
                            Fota_ProgrammingFwBlockId].DecryptJobId) == E_OK)
              {
                retVal = E_OK;
              }
              else
              {
                /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
                *LpErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                retVal = E_NOT_OK;
              }
            }
            else
            {
              /* Do nothing */
            }
          }
          else
          {
          /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
            *LpErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            retVal = E_NOT_OK;
          }
        }
        #endif
      }
      else if (FOTA_TRUE == Fota_CheckAddressIsSignatureArea(MemoryAddress))
   /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        if (MemorySize == FOTA_SIGNATURE_BLOCK_LENGTH)
        {
          Fota_Write.BlockType = FOTA_SIGNATURE;
          retVal = E_OK;
        }
        else
        {
            /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          *LpErrorCode = DCM_E_REQUESTOUTOFRANGE;
          retVal = E_NOT_OK;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_REQUEST_DOWNLOAD_SID, FOTA_E_ADDRESS_LENGTH_INVALID, retVal);
          #endif
        }
      }
   /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      {
        retVal = E_NOT_OK;
           /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        *(LpErrorCode) = DCM_E_REQUESTOUTOFRANGE;
           
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_REQUEST_DOWNLOAD_SID, FOTA_E_ADDRESS_LENGTH_INVALID, retVal);
        #endif
      }

      if(retVal==E_OK)
      {
        Fota_Write.StartAddPhy = MemoryAddress;
        Fota_Write.WriteAddPhy = MemoryAddress;
        Fota_Write.TotalLen    = MemorySize;
        Fota_Write.Writelen = FOTA_ZERO;     /* Transfer Data will be set this */
        Fota_Write.TotalWrittenlen = FOTA_ZERO;
        Fota_Retransfer.New_Chunk_Received = FOTA_FALSE;
        Fota_Retransfer.SavedAddr = FOTA_SAVEDADDR_INIT;
        retVal = E_OK;
        Fota_State = FOTA_WAIT;
          /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        *(LpErrorCode) = DCM_E_POSITIVERESPONSE;
         
      }
    }
    else
    {
       retVal = E_NOT_OK;
       /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
       *LpErrorCode = DCM_E_REQUESTSEQUENCEERROR;

    }
  }
  /* @Trace: FOTA_SUD_API_00069 */
  else if (OpStatus == DCM_CANCEL)
  {
    retVal = E_NOT_OK;
  }
  else if (OpStatus == DCM_FORCE_RCRRP_OK)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
/* polyspace-end CODE-METRIC:LEVEL,VG,PARAM [Justified:Medium] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessTransferDataWrite                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : DCM CallOut function call this to transfer data     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                        MemoryIdentifier                                    **
**                        MemoryAddress                                       **
**                        MemoryWriteLen                                      **
**                        pWriteData                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_ReturnWriteMemoryType retVal                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Write                                          **
**                        Fota_State                                          **
**                        Fota_SvcResultAllSwUnit                             **
**                        Fota_ProgrammingSWUnitId                            **
**                        Fota_VersionStatus                                  **
**                        Fota_Gast_SwUnitTable                               **
**                        Fota_Retransfer                                     **
**                        Fota_PflsWriteAlignmentValue                        **
**                        Lau8_SignedBuffer                                   **
**                        Function(s) invoked :                               **
**                        Fota_VersionCheckRequest                            **
**                        Fota_VersionCheckResult                             **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* @Trace: FOTA_SRS_UDS_00007 FOTA_SRS_ES98765_02E_00033 FOTA_SRS_GENSEC_00007 FOTA_SRS_GENSEC_00012 */
/* @Trace: FOTA_SRS_GENSEC_00010 FOTA_SRS_GENSEC_00014 FOTA_SRS_ES95489_52E_00004 FOTA_SRS_ES95489_52E_00005 */
/* @Trace: FOTA_SRS_ES95489_52E_00006 FOTA_SRS_ES98765_01E_00004 FOTA_SRS_ES98765_02E_00023 FOTA_SRS_ES98765_02E_00018 */
/* polyspace-begin CODE-METRIC:VG,LEVEL,FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */
FUNC(Dcm_ReturnWriteMemoryType, FOTA_CODE) Fota_ProcessTransferDataWrite
(
  Dcm_OpStatusType OpStatus,
  uint8 MemoryIdentifier /* Not Supported Argument */,
  uint32 MemoryAddress,
  uint32 MemoryWriteLen,
  P2CONST(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) pWriteData
)
{
  Dcm_ReturnWriteMemoryType retVal = DCM_WRITE_FAILED;
  uint32 remainingForMemAlign;
  static Fota_DownloadStatType downloadState = FOTA_DOWNLOAD_NORMAL;
  #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
    (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
  Fota_JobResultType versionCheckResult;
  #endif

  FOTA_UNUSED(MemoryIdentifier);
  
  if (OpStatus == DCM_INITIAL)
  {
    /* @Trace: FOTA_SUD_API_00076 */
    if (Fota_State==FOTA_WAIT) /* Fota job check */
    {
      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
  /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The array index is depend on argument that is passed in this function" */
      if (Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].CheckVersion ==
                                                        FOTA_VERSION_USED)
      #endif
      {
        if (Fota_VersionStatus == FOTA_VERSION_INIT)
        {
        /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          if (MemoryAddress >= (Fota_Gast_SwUnitTable[
            Fota_ProgrammingSWUnitId].BlkHeaderAddress + FOTA_BLK_TOTAL_LENGTH))
          {
            downloadState = FOTA_DOWNLOAD_VERSION_CHECK_REQUEST;
          }
        }
      }
      #endif

      if (Fota_Retransfer.SavedAddr!=MemoryAddress)
      {
        if ((FOTA_SIGNATURE == Fota_Write.BlockType) || \
            (FOTA_METADATA == Fota_Write.BlockType))
        {
          /* polyspace +1 CERT-C:INT33-C [Not a defect:Low] "The destination is larger than the type of InEcuSwUnit." */
          remainingForMemAlign = MemoryWriteLen % Fota_PflsWriteAlignmentValue;
          if(remainingForMemAlign>0UL)
          {
            Fota_Write.Writelen = MemoryWriteLen + (Fota_PflsWriteAlignmentValue - remainingForMemAlign);
            Fota_Write.TotalLen += Fota_PflsWriteAlignmentValue - remainingForMemAlign;
          }
          else
          {
            Fota_Write.Writelen = MemoryWriteLen;
          }
        }
        else
        {
          Fota_Write.Writelen = MemoryWriteLen;
        }

        if (FOTA_SIGNATURE == Fota_Write.BlockType)
         /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        {
          (void)FOTA_MEMSET(Lau8_SignedBuffer, 0xFF, sizeof(Lau8_SignedBuffer));
/* polyspace +1 MISRA-C3:D4.11 [Not a defect:Low] "The parameter passed into a function is valid"*/
          (void)FOTA_MEMCPY(Lau8_SignedBuffer, pWriteData, MemoryWriteLen);
        }
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        Fota_Write.pWriteData = pWriteData;
        Fota_Retransfer.SavedAddr = MemoryAddress;

        #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
          (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
        if (FOTA_DOWNLOAD_VERSION_CHECK_REQUEST == downloadState)
        {
          Fota_Retransfer.New_Chunk_Received = FOTA_FALSE;
        }
        else
        {
          Fota_Retransfer.New_Chunk_Received = FOTA_TRUE;
        }
        #else
        Fota_Retransfer.New_Chunk_Received = FOTA_TRUE;
        #endif

        #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
        retVal = DCM_WRITE_FORCE_RCRRP;
        #else
        retVal = DCM_WRITE_PENDING;
        #endif
      }
      else
      {
        retVal = DCM_WRITE_FAILED;
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_TRANSFER_DATA_SID, FOTA_E_TRANSFER_DATA_AFTER_REQUEST_OFF, retVal);
        #endif
      }
    }
    else
    {
      retVal = DCM_WRITE_FAILED;
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
        FOTA_TRANSFER_DATA_SID, FOTA_E_CHECK_JOB_FAIL, retVal);
      #endif
    }
  }
  else if ((OpStatus == DCM_FORCE_RCRRP_OK) || (OpStatus == DCM_PENDING))
  {
    switch (downloadState)
    {
      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      case FOTA_DOWNLOAD_VERSION_CHECK_REQUEST:
        /* @Trace: FOTA_SUD_API_00077 */
        Fota_VersionCheckRequest(
                    FOTA_VERSION_CHECK_AFTER_DOWNLOAD_REQUEST, MemoryAddress);

        Fota_State = FOTA_VERSION_CHECK_PROCESSING;
        downloadState = FOTA_DOWNLOAD_VERSION_CHECK_RESULT;
        retVal     = DCM_WRITE_PENDING;
        break;

      case FOTA_DOWNLOAD_VERSION_CHECK_RESULT:
        /* @Trace: FOTA_SUD_API_00233 */
        versionCheckResult = Fota_VersionCheckResult();
        if (FOTA_JOB_PENDING == versionCheckResult)
        {
          retVal = DCM_WRITE_PENDING;
        }
        else if (FOTA_JOB_OK == versionCheckResult)
        {
          Fota_State = FOTA_WAIT;
          downloadState = FOTA_DOWNLOAD_NORMAL;
          Fota_Retransfer.New_Chunk_Received = FOTA_TRUE;
          retVal = DCM_WRITE_PENDING;
        }
        else /* (FOTA_JOB_FAILED = versionCheckResult) */
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_TRANSFER_DATA_SID, FOTA_E_SVC_UPDATE_HEADER_FAILED, retVal);
          #endif
          Fota_State = FOTA_WAIT;
          downloadState = FOTA_DOWNLOAD_NORMAL;
          Fota_Retransfer.New_Chunk_Received = FOTA_TRUE;
          retVal = DCM_WRITE_PENDING;
        }

        break;
      #endif

      case FOTA_DOWNLOAD_NORMAL:
        /* @Trace: FOTA_SUD_API_00234 */
        if (Fota_State == FOTA_PROCESSING) /* Fota job check */
        {
          retVal = DCM_WRITE_PENDING;
        }
        else if (Fota_State == FOTA_WAIT)
        {
          if (Fota_Retransfer.New_Chunk_Received == FOTA_FALSE)
          {
            if (Fota_Write.TotalLen > Fota_Write.TotalWrittenlen)
            {
        /* polyspace +2 CERT-C:INT30-C [Not a defect:Low] "The value of operand is larger " */ 
        /* polyspace +1 DEFECT:UINT_OVFL [Not a defect:Low] "The value of operand is larger" */
              Fota_Write.WriteAddPhy     += Fota_Write.Writelen; 
        /* polyspace +2 CERT-C:INT30-C [Not a defect:Low] "The value of operand is larger" */
        /* polyspace +1 DEFECT:UINT_OVFL [Not a defect:Low] "The value of operand is larger" */              
              Fota_Write.TotalWrittenlen += Fota_Write.Writelen; 

              retVal = DCM_WRITE_OK;
              Fota_Retransfer.New_Chunk_Received = FOTA_FALSE;
            }
            else
            {
              retVal = DCM_WRITE_FAILED;
            }
          }
          else
          {
            retVal = DCM_WRITE_PENDING;
          }
        }
        else
        {
          retVal = DCM_WRITE_FAILED;
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_TRANSFER_DATA_SID, FOTA_E_CHECK_JOB_FAIL, retVal);
          #endif
        }
        break;
      /* polyspace +2 DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "Default case to avoid misra and warning" */
    /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and default case will run in specific cases." */
      default :
        /* @Trace: FOTA_SUD_API_00235 */
        retVal = DCM_WRITE_FAILED;
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_TRANSFER_DATA_SID, FOTA_E_DOWNLOAD_STATE_INVALID, retVal);
        #endif
        break;
    }
  }
  /* @Trace: FOTA_SUD_API_00078 */
  else if (OpStatus == DCM_CANCEL)
  {
    retVal = DCM_WRITE_FAILED;
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_TRANSFER_DATA_SID, FOTA_E_OPSTATUS_INVALID, retVal);
    #endif
  }
  else
  {
    retVal = DCM_WRITE_FAILED;
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_TRANSFER_DATA_SID, FOTA_E_OPSTATUS_INVALID, retVal);
    #endif
  }

  return retVal;
}
/* polyspace-end CODE-METRIC:VG,LEVEL,FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessRequestTransferExit                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : DCM CallOut function call this to transfer exit     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                        LpMemoryData                                        **
**                        LulParameterRecordSize                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Write                                          **
**                        Fota_State                                          **
**                        Function(s) invoked :                               **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* @Trace: FOTA_SRS_UDS_00008 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_ProcessRequestTransferExit
(
  Dcm_OpStatusType OpStatus,
  /* polyspace +1 MISRA-C3:8.13 [Not a defect:Low] "For the AUTOSAR Spectification, the data type should point to a const qualified type" */
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpMemoryData,
   /* polyspace +1 MISRA-C3:8.13 [Not a defect:Low] "For the AUTOSAR Spectification, the data type should point to a const qualified type" */
  uint32* LulParameterRecordSize,
 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, FOTA_PRIVATE_DATA)LpErrorCode

)
{
  /* @Trace: FOTA_SUD_API_00079 */
  Std_ReturnType retVal = E_NOT_OK;
 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_POSITIVERESPONSE;


  FOTA_UNUSED(OpStatus);
  FOTA_UNUSED(LpMemoryData);
  FOTA_UNUSED(LulParameterRecordSize);

  if (Fota_Write.TotalLen == Fota_Write.TotalWrittenlen)
  {
    *LpErrorCode = DCM_E_POSITIVERESPONSE;
    Fota_State = FOTA_READY;
    retVal = E_OK;
  }
  else
  {
    *LpErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    Fota_State = FOTA_ERROR;
    retVal = E_NOT_OK;
    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
    /* Report Det Error */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_REQUEST_TRANSFER_EXIT_SID, FOTA_E_ADDRESS_LENGTH_INVALID, retVal);
    #endif
  }

  return retVal;
}
/* polyspace-end CODE-METRIC:FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessVerifyGenOne                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fota Verify function in CPD Service                 **
**                        (Reprogram Gen 1 Case (FOTA_OTA_ES98765_01))        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InMemArea                                           **
**                        InEcuSwUnit                                         **
**                        OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpOut_MemoryArea                                    **
**                        LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_ProgrammingSWUnitId                            **
**                        Fota_MemoryInstance                                 **
**                        Fota_VersionStatus                                  **
**                        Fota_SecureFlashDecryptOn                           **
**                        Fota_ProgrammingMemoryArea                          **
**                        Fota_State                                          **
**                        Fota_Gast_SwUnitTable                               **
**                        BlockProcessingRulePtr                              **
**                        Lau8_DecryptedBuffer                                **
**                        Function(s) invoked :                               **
**                        Fota_ValidateMemoryArea                             **
**                        Fota_IsDualPartitionSwUnit                          **
**                        Fota_GetTargetPartition                             **
**                        Fota_GetSwUnitIdByPartition                         **
**                        Fota_GetSwUnitIdByLabel                             **
**                        Fota_GetMemInstanceBySwUnit                         **
**                        Fota_DecryptFinish                                  **
**                        Fota_VerifyRequest                                  **
**                        Fota_VerifyJobResult                                **
**                        Fota_VersionCheckRequest                            **
**                        Fota_VersionCheckResult                             **
**                        Fota_ChkVfyKey                                      **
**                        Fota_ChkActKey                                      **
**                        Fota_SetVfyKey_Request                              **
**                        Fota_SetActKey_Request                              **
**                        Fota_SetKey_Result                                  **
**                        Fota_VersionCheckEraseRomLength                     **
**                        Fota_PflsTgtAreaSet                                 **
**                        Fota_PflsEraseRequest                               **
**                        Fota_PflsGetJobResult                               **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:CALLS,FXLN,VG,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/* @Trace: FOTA_SRS_ES95489_52E_00008 FOTA_SRS_ES95489_52E_00009 FOTA_SRS_ES98765_01E_00003 FOTA_SRS_GENSEC_00009 FOTA_SRS_UDS_00005 */
/* @Trace: FOTA_SRS_ES95489_52E_00001 FOTA_SRS_GENSEC_00007 FOTA_SRS_GENSEC_00010 FOTA_SRS_GENSEC_00012 */
/* @Trace: FOTA_SRS_ES98765_02E_00021 FOTA_SRS_ES98765_02E_00029 FOTA_SRS_UDS_00004 FOTA_SRS_UDS_00026 */
#if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_01)
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessVerifyGenOne
(
  VAR(uint8, AUTOMATIC) InMemArea,
  VAR(uint16, AUTOMATIC) InEcuSwUnit,
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpOut_MemoryArea,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  VAR(Std_ReturnType,AUTOMATIC) retVal;
  VAR(Fota_JobResultType,AUTOMATIC) jobVerifyResult;
  VAR(Fota_SetKeyResultType, AUTOMATIC) setKeyResult;
  VAR(Fota_PartitionType,AUTOMATIC) TgtPart;

  /* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
  static Fota_CpdStatType programmingState = FOTA_CPD_ERR;
  #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
    (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
  static Fota_VersionCheckRequestType versionCheckRequest =
                                            FOTA_VERSION_CHECK_CPD_REQUEST;
  Fota_JobResultType versionCheckResult;
  #endif
  uint32 eraseRomLength;
  VAR(Mem_76_Pfls_JobResultType,AUTOMATIC) memJobResult;
  #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
  uint32 decryptJobId;
  uint32 decryptionLen = FOTA_TP_BLOCK_LENGTH;
  #endif
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE)
  Fota_SoftwareType softwareType;
  Fota_KeyMgrType keyMagicType;
  softwareType = FOTA_RTSW_TYPE;
  #endif

  FOTA_UNUSED(LpOut_MemoryArea);
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_POSITIVERESPONSE;
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  retVal = E_NOT_OK;
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  if (OpStatus == DCM_INITIAL)
  {
    /* @Trace: FOTA_SUD_API_00080 */
    /* get the memory area to local variable */
    if (E_OK == Fota_ValidateMemoryArea(InMemArea))
    {
      /* get ECU software Unit ID */
      if(Fota_IsDualPartitionSwUnit(InEcuSwUnit)==E_OK)
      /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      {
        if(Fota_GetTargetPartition(&TgtPart)==E_OK)
        {
          retVal = Fota_GetSwUnitIdByPartition(TgtPart,&Fota_ProgrammingSWUnitId);
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      else
      {
        retVal = Fota_GetSwUnitIdByLabel(InEcuSwUnit, &Fota_ProgrammingSWUnitId);
      }
    }
    /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
    if (E_OK != retVal)
    {
      /* Server shall respond NRC 31 */
      *LpErrorCode = DCM_E_REQUESTOUTOFRANGE;
      retVal = E_NOT_OK;
      Fota_State = FOTA_ERROR;
      #if (FOTA_DEV_ERROR_DETECT == STD_ON)
      /* Report Det Error */
      Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_BLOCKID_INVALID, retVal);
      #endif
    }
    else
    {
      (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      if (Fota_VersionStatus == FOTA_VERSION_OK)
      {
        programmingState = FOTA_CPD_VERSION_CHECK_REQUEST;
      }
      else
      {
        programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
      }
      #else
      programmingState = FOTA_CPD_CMD;
      #endif
      retVal     = DCM_E_FORCE_RCRRP;
      *LpErrorCode = DCM_E_POSITIVERESPONSE;
    }
    /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
  }
  else if ((OpStatus == DCM_PENDING)||(OpStatus == DCM_FORCE_RCRRP_OK))
  {
    switch (programmingState)
    {
      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      case FOTA_CPD_VERSION_CHECK_REQUEST:
        /* @Trace: FOTA_SUD_API_00237 */
        versionCheckRequest = FOTA_VERSION_CHECK_CPD_REQUEST;
        Fota_VersionCheckRequest(versionCheckRequest, FOTA_ZERO);

        Fota_State = FOTA_VERSION_CHECK_PROCESSING;
        programmingState = FOTA_CPD_VERSION_CHECK_RESULT;
        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_VERSION_CHECK_RESULT:

        versionCheckResult = Fota_VersionCheckResult();
        if (FOTA_JOB_PENDING == versionCheckResult)
        {
          /* Do nothing */
        }
        else if (FOTA_JOB_OK == versionCheckResult)
        {
          if (FOTA_VERSION_CHECK_CPD_REQUEST == versionCheckRequest)
          {
            programmingState = FOTA_CPD_CMD;
          }
          else /* (FOTA_VERSION_CHECK_ERASE_ROM_REQUEST = versionCheckRequest) */
          {
            Fota_State = FOTA_READY;
            programmingState = FOTA_CPD_ERASE_ROM;
          }
        }
        else /* (FOTA_JOB_FAILED = versionCheckResult) */
        {

          if (FOTA_VERSION_CHECK_CPD_REQUEST == versionCheckRequest)
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_SVC_UPDATE_TRAILER_FAILED, retVal);
            #endif
            programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
          }
          else /* (FOTA_VERSION_CHECK_ERASE_ROM_REQUEST = versionCheckRequest) */
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_SVC_UPDATE_TRAILER_FAILED, retVal);
            #endif
            Fota_State = FOTA_READY;
            programmingState = FOTA_CPD_ERASE_ROM;
          }
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM:
        /* @Trace: FOTA_SUD_API_00240 */
        versionCheckRequest = FOTA_VERSION_CHECK_ERASE_ROM_REQUEST;
        Fota_VersionCheckRequest(versionCheckRequest, FOTA_ZERO);

        Fota_State = FOTA_VERSION_CHECK_PROCESSING;
        programmingState = FOTA_CPD_VERSION_CHECK_RESULT;

        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
      #endif  /* #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\ *
               * (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))    */

      case FOTA_CPD_ERASE_ROM:
        /* Erase area which same as routine-control erase
         * If version check enable, this delete except trailer
         */
        /* 1st Erase Area for sector which include header */
        #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
          (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
        eraseRomLength = Fota_VersionCheckEraseRomLength(Fota_ProgrammingSWUnitId);
        #else
      /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        eraseRomLength = Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].EndAddress - 
          Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].StartAddress + FOTA_ONE;
        #endif

        if (E_OK == Fota_PflsEraseRequest(
             Fota_MemoryInstance,
             Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].StartAddress,
             eraseRomLength))
        {
          programmingState = FOTA_CPD_ERASE_ROM_CHECK;
        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_ERASE_REQUEST_FAILED, retVal);
          #endif
          programmingState = FOTA_CPD_ERR;
        }
        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_ERASE_ROM_CHECK:
        /* @Trace: FOTA_SUD_API_00242 */
        memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);

        if (memJobResult == MEM_JOB_PENDING)
        {
          /* Time for erase one sector in Chorus 10M is long (~1s)
           * => need return DCM_E_FORCE_RCRRP for transmit a pending response NRC78 to tester
           * this probelm is not occurn in RTSW due to task is managed by interrupt */
          #if (((FOTA_MODE == FOTA_FBL_MODE) && (FOTA_MCU_MEMORY_ACCESS_TYPE != FOTA_MMU_TYPE)) \
           && (FOTA_LARGE_SECTOR == STD_ON))
          retVal  = DCM_E_FORCE_RCRRP;
          #else
          retVal = DCM_E_PENDING;
          #endif
        }
        else if (memJobResult ==  MEM_JOB_OK)
        {
          programmingState = FOTA_CPD_ERR;
          retVal  = DCM_E_PENDING;
        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_ERASE_JOB_FAILED, retVal);
          #endif
          programmingState = FOTA_CPD_ERR;
          retVal  = DCM_E_PENDING;
        }
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_CMD:
        #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
        if (FOTA_TRUE == Fota_SecureFlashDecryptOn)
        {
          /* polyspace +3 RTE:IDP [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          /* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          decryptJobId = \
            BlockProcessingRulePtr[Fota_ProgrammingFwBlockId].DecryptJobId;
          if (Fota_DecryptFinish(FOTA_ROUTINE_CONTROL_CPD_SID, decryptJobId,
                                   &Lau8_DecryptedBuffer[0], &decryptionLen) == E_OK)
          {
            /*do nothing*/
          }
          else
          {
            #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
              (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
            programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
            #else
            programmingState = FOTA_CPD_ERASE_ROM;
            #endif
            *LpErrorCode = DCM_E_POSITIVERESPONSE;
            retVal = DCM_E_PENDING;
            break;
          }
        }
        #endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
        /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        Fota_VerifyRequest(Fota_ProgrammingMemoryArea);
        Fota_State = FOTA_VERIFY;
        programmingState = FOTA_CPD_INTEGRITY_CHECK;
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_INTEGRITY_CHECK:
        /* @Trace: FOTA_SUD_API_00236 */
        jobVerifyResult = Fota_VerifyJobResult();

        if (jobVerifyResult == FOTA_JOB_PENDING)
        {
          /* Do nothing */
        }
        else if (jobVerifyResult == FOTA_JOB_OK)
        {
          Fota_State = FOTA_READY;

          #if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
          programmingState = FOTA_CPD_CPDKEY_WRITE;
          #else
          programmingState = FOTA_CPD_PARTITION_WRITE;
          #endif

        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_VERIFY_JOB_FAILED, retVal);
          #endif

          #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
            (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
          programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
          #else
          programmingState = FOTA_CPD_ERASE_ROM;
          #endif
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      #if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
      case FOTA_CPD_CPDKEY_WRITE:
      #else
      case FOTA_CPD_PARTITION_WRITE:
      #endif
        #if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
        if (E_OK == Fota_ChkVfyKey(Fota_ProgrammingSWUnitId, FOTA_TARGET_AREA))
        {
          programmingState = FOTA_CPD_END_READY;
        }
        else
        {
          if (E_OK == Fota_SetVfyKey_Request(Fota_ProgrammingSWUnitId))
          {
            programmingState = FOTA_CPD_CPDKEY_WRITE_CHECK;
          }
        #else
        if (E_OK == Fota_ChkActKey(Fota_ProgrammingSWUnitId, FOTA_TARGET_AREA))
        {
          programmingState = FOTA_CPD_END_READY;
        }
        else
        {
          (void)Fota_GetSoftwareTypeBySwUnitId(Fota_ProgrammingSWUnitId, &softwareType);
          if (FOTA_FBL_TYPE == softwareType)
      /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          {
            keyMagicType = FOTA_BMKEY_MGR;
          }
      /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          else
          {
            keyMagicType = FOTA_FLKEY_MGR;
          }
          if (E_OK==Fota_SetActKey_Request(keyMagicType, Fota_ProgrammingSWUnitId))
          {
            programmingState = FOTA_CPD_PARTITION_WRITE_CHECK;
          }
        #endif
          else
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_REQUEST_FAILED, retVal);
            #endif

            #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
              (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
            programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
            #else
            programmingState = FOTA_CPD_ERASE_ROM;
            #endif
          }
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      #if (FOTA_MCU_MEMORY_ACCESS_TYPE!=FOTA_SINGLE_TYPE)
      case FOTA_CPD_CPDKEY_WRITE_CHECK:
      #else
      case FOTA_CPD_PARTITION_WRITE_CHECK:
      #endif
        /* @Trace: FOTA_SUD_API_00239 */
        setKeyResult = Fota_SetKey_Result();
        if (FOTA_SETMAGICKEY_OK == setKeyResult)
        {
          programmingState = FOTA_CPD_END_READY;
        }
        else if (FOTA_SETMAGICKEY_FAILED == setKeyResult)
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_JOB_FAILED, retVal);
          #endif
          
          #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
            (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
          programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
          #else
          programmingState = FOTA_CPD_ERASE_ROM;
          #endif
        }
        else
        {
          /* Do nothing */
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_END_READY:
        /* @Trace: FOTA_SUD_API_00243 */
        (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_STD_ADDR);

        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        Fota_State = FOTA_READY;
        retVal = E_OK;
        break;

      case FOTA_CPD_ERR:
      default :
        /* @Trace: FOTA_SUD_API_00245 */
        #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
        (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance, FOTA_ALT_ADDR);
        #else
        (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance, FOTA_STD_ADDR);
        #endif

        #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
          (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
        if (Fota_VersionStatus == FOTA_VERSION_NOT_OK)
        {
          *LpErrorCode = DCM_E_LOWERVERSIONDOWNLOADATTEMPT;
        }
        else
        #endif
        {
          *LpErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        }
        retVal = E_NOT_OK;
        Fota_State = FOTA_ERROR;
        break;
    }
  }
  /* @Trace: FOTA_SUD_API_00082 */
  else if (OpStatus == DCM_CANCEL)
  {
    retVal = E_NOT_OK;
    *LpErrorCode = DCM_E_GENERALREJECT;
  }
  else
  {
    retVal = E_NOT_OK;
    *LpErrorCode = DCM_E_GENERALREJECT;
  }
  return retVal;
}
#endif /* #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_01) */
/* polyspace-end CODE-METRIC:CALLS,FXLN,VG,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessVerifyGenTwo                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fota Verify function in Check Memory Service        **
**                        (Reprogram Gen 2 Case (FOTA_OTA_ES98765_02))        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InMemArea                                           **
**                        InEcuSwUnit                                         **
**                        OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpOut_MemoryArea                                    **
**                        LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_ProgrammingSWUnitId                            **
**                        Fota_MemoryInstance                                 **
**                        Fota_VersionStatus                                  **
**                        Fota_SvcResultAllSwUnit                             **
**                        Fota_SecureFlashDecryptOn                           **
**                        Fota_ProgrammingMemoryArea                          **
**                        Fota_State                                          **
**                        Fota_Gast_SwUnitTable                               **
**                        BlockProcessingRulePtr                              **
**                        Lau8_DecryptedBuffer                                **
**                        Fota_BackgroundResult                               **
**                        Function(s) invoked :                               **
**                        Fota_GetMemInstanceBySwUnit                         **
**                        Fota_DecryptFinish                                  **
**                        Fota_VerifyRequest                                  **
**                        Fota_VerifyJobResult                                **
**                        Fota_ChkVfyKey                                      **
**                        Fota_SetVfyKey_Request                              **
**                        Fota_SetKey_Result                                  **
**                        Fota_PflsTgtAreaSet                                 **
**                        Fota_DetReportErr                                   **
**                        Fota_VersionCheckRequest                            **
**                        Fota_VersionCheckResult                             **
**                        Fota_VersionCheckEraseRomLength                     **
**                        Fota_PflsEraseRequest                               **
**                        Fota_PflsGetJobResult                               **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:FXLN,VG,LEVEL,CALLS [Justified:Low] "High risk of code changes: Changes have wide impact" */
/* @Trace:FOTA_SRS_ES95489_52E_00009 FOTA_SRS_ES98765_01E_00003 FOTA_SRS_ES95489_52E_00008 FOTA_SRS_GENSEC_00009 */
/* @Trace: FOTA_SRS_ES95489_52E_00001 FOTA_SRS_ES98765_02E_00020 FOTA_SRS_GENSEC_00007 FOTA_SRS_GENSEC_00010 FOTA_SRS_GENSEC_00012 */
#if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessVerifyGenTwo
(
  VAR(uint8, AUTOMATIC) InMemArea,
  VAR(uint16, AUTOMATIC) InEcuSwUnit,
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpOut_MemoryArea,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  VAR(Std_ReturnType,AUTOMATIC) retVal;
  VAR(Fota_JobResultType,AUTOMATIC) jobVerifyResult;
  VAR(Fota_SetKeyResultType, AUTOMATIC) setKeyResult;

  static Fota_CpdStatType programmingState = FOTA_CPD_ERR;
  #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
    (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
  Fota_JobResultType versionCheckResult;
  #endif
  VAR(Mem_76_Pfls_JobResultType,AUTOMATIC) memJobResult;
  uint32 eraseRomLength;
  #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
  uint32 decryptJobId;
  uint32 decryptionLen = FOTA_TP_BLOCK_LENGTH;
  #endif
  FOTA_UNUSED(InMemArea);
  FOTA_UNUSED(InEcuSwUnit);
  FOTA_UNUSED(LpOut_MemoryArea);
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  retVal = E_NOT_OK;
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_GENERALREJECT;
  /* polyspace-begin MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */
  if (OpStatus == DCM_INITIAL)
  {
    retVal = DCM_E_FORCE_RCRRP;
    /* @Trace: FOTA_SUD_API_00086 */
    (void)Fota_GetMemInstanceBySwUnit(Fota_ProgrammingSWUnitId, &Fota_MemoryInstance);
    programmingState = FOTA_CPD_CMD;
    *LpErrorCode = DCM_E_POSITIVERESPONSE;

    #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
      (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The array index is depend on argument that is passed in this function" */
    Fota_BackgroundResult[Fota_ProgrammingSWUnitId].UseProgramming = FOTA_PROGRAMMING;

    if (Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].CheckVersion ==
                                                        FOTA_VERSION_USED)
    {
      if (Fota_VersionStatus == FOTA_VERSION_OK)
      {
        Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].
                                                  VersionCheckResult = E_OK;
        programmingState = FOTA_CPD_CMD;
      }
      else
      {
        Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].
                                                VersionCheckResult = E_NOT_OK;
        programmingState = FOTA_CPD_END_READY;
      }
    }
    else
    {
      /* Set default value */
      Fota_SvcResultAllSwUnit[Fota_ProgrammingSWUnitId].
                                                VersionCheckResult = E_OK;
    }
    #endif
  }
  else if(OpStatus == DCM_PENDING || OpStatus == DCM_FORCE_RCRRP_OK)
  {
    switch(programmingState)
    {
      case FOTA_CPD_CMD:
        #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
        if (FOTA_TRUE == Fota_SecureFlashDecryptOn)
        {
          /* polyspace +3 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          /* polyspace +2 RTE:IDP [Not a defect:Low] "The pointer memory location is suitable for dereference" */
          decryptJobId = \
            BlockProcessingRulePtr[Fota_ProgrammingFwBlockId].DecryptJobId;
          if (Fota_DecryptFinish(FOTA_ROUTINE_CONTROL_CPD_SID,decryptJobId,
                                   &Lau8_DecryptedBuffer[0], &decryptionLen) == E_OK)
          {
            /*do nothing*/
          }
          else
          {
            *LpErrorCode = DCM_E_POSITIVERESPONSE;
            #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
              (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
            programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
            #else
            programmingState = FOTA_CPD_ERASE_ROM;
            #endif
            retVal = DCM_E_PENDING;
            break;
          }
        }
        #endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
        /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        Fota_VerifyRequest(Fota_ProgrammingMemoryArea);
        Fota_State = FOTA_VERIFY;
        programmingState = FOTA_CPD_INTEGRITY_CHECK;
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        break;

      case FOTA_CPD_INTEGRITY_CHECK:
        /* @Trace: FOTA_SUD_API_00246 */
        jobVerifyResult = Fota_VerifyJobResult();
       
        if (jobVerifyResult == FOTA_JOB_PENDING)
        {
          /* Do nothing */
        }
        else if (jobVerifyResult == FOTA_JOB_OK)
        {
          Fota_State = FOTA_READY;
          programmingState = FOTA_CPD_CPDKEY_WRITE;
        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
        	Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          	FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_VERIFY_JOB_FAILED, FOTA_ZERO);
          #endif

          #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
            (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
          programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
          #else
          programmingState = FOTA_CPD_ERASE_ROM;
          #endif
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_CPDKEY_WRITE:
        if (E_OK == Fota_ChkVfyKey(Fota_ProgrammingSWUnitId, FOTA_TARGET_AREA))
        {
          programmingState = FOTA_CPD_END_READY;
        }
        else
        {
          /* @Trace: FOTA_SUD_API_00247 */
          if (E_OK == Fota_SetVfyKey_Request(Fota_ProgrammingSWUnitId))
          {
            programmingState = FOTA_CPD_CPDKEY_WRITE_CHECK;
          }
          else
          {
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_REQUEST_FAILED, FOTA_ZERO);
            #endif
            #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
              (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
            programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
            #else
            programmingState = FOTA_CPD_ERASE_ROM;
            #endif
          }
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_CPDKEY_WRITE_CHECK:
        /* @Trace: FOTA_SUD_API_00248 */
        setKeyResult = Fota_SetKey_Result();

        if (FOTA_SETMAGICKEY_OK == setKeyResult)
        {
          programmingState = FOTA_CPD_END_READY;
        }
        else if (FOTA_SETMAGICKEY_FAILED == setKeyResult)
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
          #endif
          #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
            (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
          programmingState = FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM;
          #else
          programmingState = FOTA_CPD_ERASE_ROM;
          #endif
        }
        else
        {
          /* Do nothing */
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
        (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
      case FOTA_CPD_RECOVERY_TRAILER_ERASE_ROM:
        /* @Trace: FOTA_SUD_API_00240 */
        Fota_VersionCheckRequest(FOTA_VERSION_CHECK_ERASE_ROM_REQUEST, FOTA_ZERO);

        Fota_State = FOTA_VERSION_CHECK_PROCESSING;
        programmingState = FOTA_CPD_VERSION_CHECK_RESULT;

        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_VERSION_CHECK_RESULT:

        versionCheckResult = Fota_VersionCheckResult();
        if (FOTA_JOB_PENDING == versionCheckResult)
        {
          /* Do nothing */
        }
        else if (FOTA_JOB_OK == versionCheckResult)
        {
          Fota_State = FOTA_READY;
          programmingState = FOTA_CPD_ERASE_ROM;
        }
        else /* (FOTA_JOB_FAILED = versionCheckResult) */
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_SVC_UPDATE_TRAILER_FAILED, retVal);
          #endif
          Fota_State = FOTA_READY;
          programmingState = FOTA_CPD_ERASE_ROM;
          
        }
        retVal = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;
      #endif  /* #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\ *
               * (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))    */

      case FOTA_CPD_ERASE_ROM:
        /* Erase area which same as routine-control erase
         * If version check enable, this delete except trailer
         */
        /* 1st Erase Area for sector which include header */
        #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
          (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
        eraseRomLength = Fota_VersionCheckEraseRomLength(Fota_ProgrammingSWUnitId);
        #else
        /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        eraseRomLength = Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].EndAddress - 
          Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].StartAddress + FOTA_ONE;
        #endif

        if (E_OK == Fota_PflsEraseRequest(
             Fota_MemoryInstance,
             Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId].StartAddress,
             eraseRomLength))
        {
          programmingState = FOTA_CPD_ERASE_ROM_CHECK;
        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_ERASE_REQUEST_FAILED, retVal);
          #endif
          programmingState = FOTA_CPD_ERR;
        }
        retVal     = DCM_E_PENDING;
        *LpErrorCode = DCM_E_POSITIVERESPONSE;        
        break;
      
      case FOTA_CPD_ERASE_ROM_CHECK:
        memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);

        if (memJobResult == MEM_JOB_PENDING)
        {
          /* Time for erase one sector in Chorus 10M is long (~1s)
           * => need return DCM_E_FORCE_RCRRP for transmit a pending response NRC78 to tester
           * this probelm is not occurn in RTSW due to task is managed by interrupt */
          #if (((FOTA_MODE == FOTA_FBL_MODE) && (FOTA_MCU_MEMORY_ACCESS_TYPE != FOTA_MMU_TYPE)) \
           && (FOTA_LARGE_SECTOR == STD_ON))
          retVal  = DCM_E_FORCE_RCRRP;
          #else
          retVal = DCM_E_PENDING;
          #endif
        }
        else if (memJobResult ==  MEM_JOB_OK)
        {
          programmingState = FOTA_CPD_ERR;
          retVal  = DCM_E_PENDING;
        }
        else
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ROUTINE_CONTROL_CPD_SID, FOTA_E_ERASE_JOB_FAILED, retVal);
          #endif
          programmingState = FOTA_CPD_ERR;
          retVal  = DCM_E_PENDING;
        }
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        break;

      case FOTA_CPD_END_READY:
        /* @Trace: FOTA_SUD_API_00249 */
        #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE)
   /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The array index is depend on argument that is passed in this function" */
        Fota_BackgroundResult[Fota_ProgrammingSWUnitId].VerifyKeyResult = E_OK;
        #endif
        (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance, FOTA_STD_ADDR);
        *LpErrorCode = DCM_E_POSITIVERESPONSE;
        Fota_State = FOTA_READY;
        retVal = E_OK;
        break;

      case FOTA_CPD_ERR:
      default :
        #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE)
   /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The array index is depend on argument that is passed in this function" */
        Fota_BackgroundResult[Fota_ProgrammingSWUnitId].VerifyKeyResult = E_NOT_OK;
        #endif
        /* @Trace: FOTA_SUD_API_00251 */
        #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
        (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance, FOTA_ALT_ADDR);
        #else
        (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance, FOTA_STD_ADDR);
        #endif
        *LpErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        retVal = E_NOT_OK;
        Fota_State = FOTA_ERROR;
        break;
    }
  }
  /* @Trace: FOTA_SUD_API_00088 */
  else if (OpStatus == DCM_CANCEL)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_NOT_OK;

  }
  /* polyspace-end MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */

  return retVal;
}
#endif /* #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) */
/* polyspace-end CODE-METRIC:FXLN,VG,LEVEL,CALLS [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
** Function Name        : Fota_ProcessAreaDataSync                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Fota Verify function in Finish Update Service       **
**                        (Reprogram Gen 2 Case (FOTA_OTA_ES98765_02))        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpErrorCode                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_AreaSyncRequest                                **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES98765_02E_00022 FOTA_SRS_UDS_00027 */
#if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
FUNC (Std_ReturnType, FOTA_CODE) Fota_ProcessAreaDataSync
(
  VAR(uint8, AUTOMATIC) OpStatus,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) LpErrorCode
)
{
  VAR(Std_ReturnType,AUTOMATIC) retVal;

  /* polyspace-begin MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
  /* @Trace: FOTA_SUD_API_00089 */
  if (OpStatus == DCM_INITIAL)
  {
    #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  /* polyspace+2 RTE:UNR [Justified:Low] "if-condition depends on the configuration." */
  /* polyspace+1 MISRA-C3:14.3 [Justified:Low] "if-conditizon depends on the configuration." */
    if(FOTA_NUM_OF_SWUNIT>FOTA_ZERO)
    {
      (void)Fota_AreaSyncRequest(FOTA_SYNC_ALL_SWUNIT);
    }
    #endif
  }
  else
  {
    /* Do nothing */
  }
  /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  *LpErrorCode = DCM_E_POSITIVERESPONSE;
  

  retVal = DCM_E_OK;
  /* polyspace-end MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
  return retVal;
}
#endif /* #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) */
/*******************************************************************************
** Function Name        : Fota_GetVersionInfo                                 **
**                                                                            **
** Service ID           : 0xF1                                                **
**                                                                            **
** Description          : This service returns the version information of     **
**                        this module.                                        **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : versioninfo                                         **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* @Trace: FOTA_SRS_ES98765_02E_00033 FOTA_SRS_GENSEC_00007 */
#if (FOTA_VERSION_INFO_API == STD_ON)
FUNC(void, FOTA_CODE) Fota_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC,
    FOTA_PRIVATE_DATA) versioninfo)
{
  /* @Trace: FOTA_SUD_API_00091 */
  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
  /* Check whether Version Information is equal to Null Ptr */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
      FOTA_GET_VERSION_SID, FOTA_E_NULL_POINTER, FOTA_ZERO);
  }
  else
  #endif /* End of if (FOTA_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Requirement PDUR234 - Fota_GetVersionInfo shall return the version
    information of this module in the passed argument *versionInfo*/
    /* Copy the vendor Id */
    versioninfo->vendorID = FOTA_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = FOTA_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = FOTA_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = FOTA_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = FOTA_SW_PATCH_VERSION;
  }
} /* End of Fota_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC,
   *Fota_APPL_DATA) versioninfo) */
#endif /* #if (FOTA_VERSION_INFO_API == STD_ON) */
/*******************************************************************************
** Function Name        : Fota_MainFunction                                   **
**                                                                            **
** Service ID           : 0x3                                                 **
**                                                                            **
** Description          : Fota Main Function                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_State                                          **
**                        Fota_Write                                          **
**                        Fota_Retransfer                                     **
**                        Fota_MemoryInstance                                 **
**                        BlockProcessingRulePtr                              **
**                        Lau8_DecryptedBuffer                                **
**                        Lau8_SignedBuffer                                   **
**                        Function(s) invoked :                               **
**                        Fota_MetaDataProcessing                             **
**                        Fota_UserCallOutProcessing                          **
**                        Fota_DecryptUpdate                                  **
**                        Fota_PflsWriteRequest                               **
**                        Fota_CheckMetaWriteRequest                          **
**                        Fota_PflsGetJobResult                               **
**                        Fota_MainVersionCheck                               **
**                        Fota_JobVerifyProcess                               **
**                        Fota_RequestReset                                   **
**                        Fota_MacUpdateMain                                  **
**                        Fota_AreaSyncMain                                   **
**                        Fota_DetReportErr                                   **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:VG,LEVEL,CALLS,FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */
FUNC(void, FOTA_CODE) Fota_MainFunction(void)
{
  Mem_76_Pfls_JobResultType memJobResult;
  Std_ReturnType retVal = E_NOT_OK;
  #if ((FOTA_STD_ON == FOTA_SF20_ENABLE) || (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED))
  Fota_StateType localFotaState;
  #endif
  #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
  uint32 decryptJobId;
  #endif
  #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
    (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
  #endif
  switch(Fota_State)
  {
    case FOTA_IDLE:

      /* Initial state of the FOTA Handler after the ECU startup procedure */
      break;

    case FOTA_INIT:
      /* @Trace: FOTA_SUD_API_00252 */
      /* The FOTA Handler is initialized and Dcm is set into the correct state
        * (in Dcm FOTA session and security access has been granted).
        */
      #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
          Fota_S32k3_Hse_Psk_injection(); /* Usercode */
      #endif

      break;

    case FOTA_WAIT:
     /* The FOTA Handler has successfully processed the last received data chunk,
      * returned the Dcm callout function and is waiting for the next data chunk.
      */
      /* @Trace: FOTA_SUD_API_00092 */
      if (Fota_Retransfer.New_Chunk_Received == FOTA_TRUE)
      {
        /* To prevent Dcm transferData preemption during Decryption or Pfls writing,
         * Set FOTA_PROCESSING state here
         */
        Fota_State = FOTA_PROCESSING;
        #if ((FOTA_STD_ON == FOTA_SF20_ENABLE) || (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED))
        localFotaState = FOTA_WAIT;
        #endif
        #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
        if (Fota_Write.BlockType == FOTA_METADATA)
        {
          retVal = Fota_MetaDataProcessing(&Fota_Write, localFotaState);
        }
        else
        #endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
        {
          if (Fota_Write.BlockType == FOTA_FIRMWARE)
        /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          {
            #if (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED)
            retVal = Fota_UserCallOutProcessing(BlockProcessingRulePtr,
                                                localFotaState);
            #else
            retVal = E_OK;
            #endif
            #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
            if (FOTA_TRUE == Fota_SecureFlashDecryptOn)
            {
            /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
              decryptJobId = BlockProcessingRulePtr[\
                        Fota_ProgrammingFwBlockId].DecryptJobId;

              retVal |= Fota_DecryptUpdate(
                          decryptJobId,
                          Fota_Write.pWriteData,
                          Lau8_DecryptedBuffer,
                          (uint32*)&Fota_Write.Writelen);

              Fota_Write.pWriteData = Lau8_DecryptedBuffer;
            }
            else
            {
              /* Decryption is not needed. */
            }
            #endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
          }
        /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          else 
          {
            Fota_Write.pWriteData = Lau8_SignedBuffer;
            retVal = E_OK;
          }

          /* polyspace-begin MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
          /* polyspace+1 RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          if (E_OK == retVal)
          {
            retVal = Fota_PflsWriteRequest(Fota_MemoryInstance, \
                      Fota_Write.WriteAddPhy, \
                      Fota_Write.pWriteData, Fota_Write.Writelen);
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            if (E_NOT_OK == retVal)
            {
              /* Report Det Error */
              Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_REQUEST_FAILED, retVal);
            }
            #endif
          }
          /* polyspace-end MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
        }

        if (retVal != E_OK)
        {
          Fota_State = FOTA_ERROR;
        }
      }
      break;

    case FOTA_PROCESSING:
     /* The FOTA Handler is triggered by the Dcm callout since a new chunk has been
      * received and is processed in the callout context.
      */
      /* @Trace: FOTA_SUD_API_00093 */
      if (Fota_Retransfer.New_Chunk_Received == FOTA_TRUE)
      {
        #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
        if (Fota_Write.BlockType == FOTA_METADATA)
        /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
        {
          if (FOTA_TRUE == Fota_CheckMetaWriteRequest())
          /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          {
      
            memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);
          }
      /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          else
    /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          {
            memJobResult = MEM_JOB_OK;
          }
    /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
        }
      /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
        else
        #endif
        {
          memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);
        }

        if (MEM_JOB_FAILED == memJobResult)
        {
          #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_JOB_FAILED, retVal);
          #endif
          Fota_Retransfer.New_Chunk_Received = FOTA_FALSE;
          Fota_State = FOTA_ERROR;
        }
        else if (MEM_JOB_OK == memJobResult)
        {
          #if ((FOTA_STD_ON == FOTA_SF20_ENABLE) || (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED))
          localFotaState = FOTA_PROCESSING;
          #endif
          #if (FOTA_STD_ON == FOTA_SF20_ENABLE)
          if (Fota_Write.BlockType == FOTA_METADATA)
        /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          {
            retVal = Fota_MetaDataProcessing(&Fota_Write, localFotaState);
           
            if(retVal == CRYPTO_E_BUSY)
            {
              /* Wait until CRYPTO_E_BUSY end */
            }
            else if(E_OK != retVal)
            {
              /* Dcm_WriteMemory don't have item of errCode, response only NRC 72 in this case. */
              Fota_State = FOTA_ERROR;
            }
            else
            {
              /*do nothing*/
            }
            
          }
      /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
          else
          #endif /* (FOTA_STD_ON == FOTA_SF20_ENABLE) */
          {
            retVal = E_OK;
            #if (FOTA_STD_ON == FOTA_USER_CALL_OUT_USED)
            if (Fota_Write.BlockType == FOTA_FIRMWARE)
            {
              retVal = Fota_UserCallOutProcessing(BlockProcessingRulePtr,
                                                  localFotaState);
            }
            #endif
          }
        }
        else
        {
          /* Do Nothing */
        }

        if (E_OK == retVal)
        {
          Fota_Retransfer.New_Chunk_Received = FOTA_FALSE;
          Fota_State = FOTA_WAIT;
        }
      }
      break;

    #if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
      (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
    case FOTA_VERSION_CHECK_PROCESSING:
      /* @Trace: FOTA_SUD_API_00094 */
      Fota_MainVersionCheck();
      break;
    #endif
    case FOTA_VERIFY:
      /* @Trace: FOTA_SUD_API_00253 */
      /* Optional and implementer specific step, since the FOTA Target does not
        * specify any details on the verification process.
        */
      Fota_JobVerifyProcess();
      break;

    case FOTA_READY:
      /* All FOTA data chunks have been installed, activation procedure can be triggered. */
      break;

    case FOTA_ERROR:
      /* Optional and implementer specific. Reserved state for e.g. implementer
        * specific error handling, which is not (yet) covered by the FOTA Target.
        */
      break;
/* polyspace+1 RTE:UNR [Not a defect:Low] "Not a impact of this rule violation" */
    default:
      /*Do nothing */
      break;
  }

  /* polyspace+5 MISRA-C3:2.2 [Justified:Low] "The function is depend on IF condition " */
  #if (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02)
    #if(FOTA_STD_ON == FOTA_FBL_SWUNIT_USED)
    Fota_MacUpdateMain();
    #endif
  Fota_AreaSyncMain();
  #endif

}
/* polyspace-end CODE-METRIC:VG,LEVEL,CALLS,FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
