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
**  SRC-MODULE: Fota_Verify.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Define the functions to verify the firmware data              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Revision History                               **
********************************************************************************
** Revision      Date          By           Description                       **
********************************************************************************
** 2.0.0.0       31-Dec-2024   ThanhTVP2    #CP44-12051                       **
** 1.1.1.0       19-Jul-2024   KJShim       #CP44-8300                        **
**                             JSKang       #CP44-9298                        **
**                             KhanhHC      #CP44-8128, #CP44-9351            **
** 1.1.0.0_HF2   07-Jun-2024   JSKang       #CP44-9298                        **
** 1.1.0.0_HF1   26-Apr-2024   KJShim       #CP44-8300                        **
** 0.2.0.0       20-Feb-2023   VuPH6        Improvement                       **
** 0.1.0.0       23-Nov-2022   VuPH6        Initial version                   **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota.h"
#include "Fota_Types.h"
#include "Fota_IntFunc.h"
#include "Fota_Cfg.h"
#include "Fota_Verify.h"
#include "Fota_Globals.h"
#include "Rte_Csm_Type.h"
#include "Csm.h"
#include "Mem_76_Pfls.h"
#include "Fota_PflsInterface.h"
#include "Fota_User_Callouts.h"

/* polyspace-begin MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
/* polyspace +1 MISRA-C3:8.4  [Not a defect:Low] "This is initialize global variable" */
Fota_Verify_StatType FotaVerifyState = FOTA_STAT_VERIFY_INACTIVE;
static Fota_CrcInfoType Fota_CrcInfo[1];

static uint16 Fota_CalcVerifyCRC = 0;

static Fota_VerificationSwUnitType *Fota_PtrSWUnitHandler;
static uint8 Fota_NumOfVerification;
static uint8 Fota_JobIndexProcessing;
static Fota_SFSignChk_CmdType Fota_SFSignChkCmd[FOTA_NUM_OF_MAX_VERIFY];

static Fota_VerifyMethodType Fota_VerifyMethod;

#if FOTA_VERIFY_BUFFER_USED
static uint8 Fota_VerifyBufferUsed;

static uint32 Fota_DataSizeOneCycle = 0;

static uint8 Fota_SignatureReadData[SEC_SF_SIGNATURE_DELIMITER_LENGTH +
                                    SEC_SF_SIGNATURE_SIZE_LENGTH +
                                    SEC_SF_SIGNATURE_SIZE];
static uint8 Fota_DataReadBuffer[FOTA_VERIFY_DATA_SIZE_ONE_CYCLE_MAX];
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CRCInitDataPushDirect(void);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CRCGetResult(void);

static FUNC(void, FOTA_CODE) Fota_VerifyInitProcess(void);

static FUNC(Std_ReturnType, FOTA_CODE) Fota_GetSecureFlashPublicKeyByDelimiter(
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) rul_Delimiter);

static FUNC(Std_ReturnType, FOTA_CODE) Fota_SignInitDataPush(
  VAR(uint32, AUTOMATIC) signatureAddress);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CalculateCRCDirect(
                                                      uint32 *dataRemainSize,
                                                      uint16 *crcAreaNum,
                                                      uint32 *dataVerifiedSize);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CheckAllJobResult(void);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobFinish(void);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobUpdateDirect(void);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobStart(
  uint32 *dataRemainSize,
  uint16 *blockIndexProcessing,
  uint32 *dataVerifiedSize);

#if FOTA_VERIFY_BUFFER_USED
static FUNC(void, FOTA_CODE) Fota_CRCInitDataPushBuffer(
                                                  uint32 *dataRemainSize,
                                                  uint16 *crcAreaNum,
                                                  uint32 *dataVerifiedSize);
static FUNC(void, FOTA_CODE) Fota_CalculateCRCBuffer(uint32 *dataRemainSize,
                                               uint16 *crcAreaNum,
                                               uint32 *dataVerifiedSize);

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobUpdateBuffer(
  uint32 *dataRemainSize,
  uint16 *blockIndexProcessing,
  uint32 *dataVerifiedSize);
static FUNC(Std_ReturnType, FOTA_CODE) Fota_VerifyBlockRead(
  uint32 dataRemainSize,
  uint16 blockIndexProcessing,
  uint16 crcAreaNum,
  uint32 dataVerifiedSize);
static FUNC(Std_ReturnType, FOTA_CODE) Fota_VerifyReadInfo(void);
#endif

#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
** Function Name        : Fota_VerifyRequest                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request start verification operation                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : In_MemoryArea                                       **
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
**                        FotaVerifyState                                     **
**                        Function(s) invoked :                               **
**                        Fota_SetVerifyJobResult                             **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(void, FOTA_CODE) Fota_VerifyRequest(
  VAR(uint32, AUTOMATIC) In_MemoryArea
)
{
  FOTA_UNUSED(In_MemoryArea);
  FotaVerifyState = FOTA_STAT_VERIFY_INIT;
  Fota_SetVerifyJobResult(FOTA_JOB_PENDING);
}

/*******************************************************************************
** Function Name        : Fota_VerifyJobResult                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get result of verification operation                **
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
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_GetVerifyJobResult                             **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 */
FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyJobResult(void)
{
  /* @Trace: FOTA_SUD_API_00084 */
  Fota_JobResultType jobResult;

  jobResult = Fota_GetVerifyJobResult();

  return jobResult;
}
 
/*******************************************************************************
** Function Name        : Fota_JobVerifyProcess                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Operation sequense in verification                  **
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
**                        FotaVerifyState                                     **
**                        Fota_VerifyBufferUsed                               **
**                        Fota_VerifyMethod                                   **
**                        Fota_MemoryInstance                                 **
**                        Function(s) invoked :                               **
**                        Fota_BeforeFlashReadFunc                            **
**                        Fota_VerifyInitProcess                              **
**                        Fota_SetVerifyJobResult                             **
**                        Fota_VerifyReadInfo                                 **
**                        Fota_VerifyCsmJobStart                              **
**                        Fota_CRCInitDataPushBuffer                          **
**                        Fota_CRCInitDataPushDirect                          **
**                        Fota_VerifyBlockRead                                **
**                        Fota_VerifyCsmJobUpdateBuffer                       **
**                        Fota_VerifyCsmJobUpdateDirect                       **
**                        Fota_CalculateCRCBuffer                             **
**                        Fota_CalculateCRCDirect                             **
**                        Fota_PflsGetJobResult                               **
**                        Fota_VerifyCsmJobFinish                             **
**                        Fota_CRCGetResult                                   **
**                        Fota_CheckAllJobResult                              **
**                        Fota_AfterFlashReadFunc                             **
**                        Fota_DetReportErr                                   **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 */
/* polyspace-begin CODE-METRIC:VG,CALLS,LEVEL,FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */
FUNC(void, FOTA_CODE) Fota_JobVerifyProcess(void)
{
  Fota_JobResultType jobResult = FOTA_JOB_FAILED;
  #if (FOTA_VERIFY_BUFFER_USED == STD_ON) || (FOTA_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType retVal = E_NOT_OK;
  #endif
  #if FOTA_VERIFY_BUFFER_USED
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC) memJobResult;
  static Fota_VerifyMemJobType memJobProcessing;
  static uint16 blockIndexProcessing;
  #endif
  static uint32 dataRemainSize;
  static uint32 dataVerifiedSize;
  static uint16 crcAreaNum;

  switch (FotaVerifyState)
  {
    case FOTA_STAT_VERIFY_INACTIVE:
    break;

    case FOTA_STAT_VERIFY_INIT:
      /* @Trace: FOTA_SUD_API_00118 */
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
      Fota_BeforeFlashReadFunc();
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
      Fota_VerifyInitProcess();

      #if FOTA_VERIFY_BUFFER_USED
      blockIndexProcessing = FOTA_ZERO;
      #endif

      Fota_SetVerifyJobResult(FOTA_JOB_PENDING);
      #if FOTA_VERIFY_BUFFER_USED
      if (FOTA_TRUE == Fota_VerifyBufferUsed)
      {
        FotaVerifyState = FOTA_STAT_VERIFY_INFO_READ;
      }
      else
      #endif
    /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      {
        FotaVerifyState = FOTA_STAT_VERIFY_START;
      }
    /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      break;
    #if FOTA_VERIFY_BUFFER_USED
    case FOTA_STAT_VERIFY_INFO_READ:
      /* @Trace: FOTA_SUD_API_00258 */
      retVal = Fota_VerifyReadInfo();
      if (retVal == E_OK)
      {
        memJobProcessing = FOTA_VERIFY_MEM_JOB_READ_SIGN;
        FotaVerifyState = FOTA_STAT_VERIFY_MEM_JOB_CHECK;
      }
      else
      {
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
      break;
    #endif
    case FOTA_STAT_VERIFY_START:
      #if FOTA_VERIFY_BUFFER_USED
      memJobProcessing = FOTA_VERIFY_MEM_JOB_NONE;
      #endif
      dataRemainSize = FOTA_ZERO;
      dataVerifiedSize = FOTA_ZERO;
      crcAreaNum = FOTA_ZERO;
      /* @Trace: FOTA_SUD_API_00119 */
      if (FOTA_SIGNATURE_VERIFY == Fota_VerifyMethod)
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        #if FOTA_VERIFY_BUFFER_USED
        if (FOTA_TRUE == Fota_VerifyBufferUsed)
        {
          jobResult = Fota_VerifyCsmJobStart(&dataRemainSize,
                                             &blockIndexProcessing,
                                             &dataVerifiedSize);
        }
        else
        #endif
        {
          jobResult = Fota_VerifyCsmJobStart(NULL_PTR, NULL_PTR,
                                             NULL_PTR);
        }
      }
     /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      {
        #if FOTA_VERIFY_BUFFER_USED
        if (FOTA_TRUE == Fota_VerifyBufferUsed)
        {
          Fota_CRCInitDataPushBuffer(&dataRemainSize, &crcAreaNum,
                                     &dataVerifiedSize);
          jobResult = FOTA_JOB_OK;
        }
        else
        #endif
        {
          jobResult = Fota_CRCInitDataPushDirect();
        }
      }
      /* polyspace-begin MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
      if (jobResult == FOTA_JOB_OK)
      {
        #if FOTA_VERIFY_BUFFER_USED
        if (FOTA_TRUE == Fota_VerifyBufferUsed)
        {
          FotaVerifyState = FOTA_STAT_VERIFY_BLOCK_READ;
        }
        else
        #endif
        {
          FotaVerifyState = FOTA_STAT_VERIFY_UPDATE;
        }
      } 
      /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      /* polyspace +1 DEFECT:USELESS_IF [Justified:Low] "if-condition depends on the configuration." */
      else if (jobResult == FOTA_JOB_FAILED) 
       /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_MAIN_FUNCTION_SID, FOTA_E_VERIFY_CSM_START_FAILED, retVal);
        #endif
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
       /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
      {
        /*do nothing*/
      }
    /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
    /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      break;
    #if FOTA_VERIFY_BUFFER_USED
    case FOTA_STAT_VERIFY_BLOCK_READ:
      /* @Trace: FOTA_SUD_API_00259 */
      retVal = Fota_VerifyBlockRead(dataRemainSize,
                                    blockIndexProcessing,
                                    crcAreaNum,
                                    dataVerifiedSize);
      if (retVal == E_OK)
      {
        memJobProcessing = FOTA_VERIFY_MEM_JOB_READ_FIRMWARE;
        FotaVerifyState = FOTA_STAT_VERIFY_MEM_JOB_CHECK;
      }
      else if (retVal == E_NOT_OK)
      {
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
      else
      {
        /* Do nothing */
      }
      break;
    #endif
    case FOTA_STAT_VERIFY_UPDATE:
      /* @Trace: FOTA_SUD_API_00120 */
      if (FOTA_SIGNATURE_VERIFY == Fota_VerifyMethod)
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        #if FOTA_VERIFY_BUFFER_USED
        if (FOTA_TRUE == Fota_VerifyBufferUsed)
        {
          jobResult = Fota_VerifyCsmJobUpdateBuffer(&dataRemainSize,
                                              &blockIndexProcessing,
                                              &dataVerifiedSize);
        }
        else
        #endif
        {
          jobResult = Fota_VerifyCsmJobUpdateDirect();
        }
      }
     /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      {
        #if FOTA_VERIFY_BUFFER_USED
        if (FOTA_TRUE == Fota_VerifyBufferUsed)
        {
          Fota_CalculateCRCBuffer(&dataRemainSize, &crcAreaNum,
                                  &dataVerifiedSize);
          jobResult = FOTA_JOB_OK;
        }
        else
        #endif
        {
          jobResult = Fota_CalculateCRCDirect(&dataRemainSize,
                                              &crcAreaNum,
                                              &dataVerifiedSize);
        }
      }

      if (jobResult == FOTA_JOB_OK)
      {
        /* Do nothing */
      }
      else if (jobResult == FOTA_JOB_FAILED)
       /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_MAIN_FUNCTION_SID, FOTA_E_VERIFY_CSM_UPDATE_FAILED, retVal);
        #endif
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
       /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      {
        /* Do nothing */
      }
      break;
    #if FOTA_VERIFY_BUFFER_USED
    case FOTA_STAT_VERIFY_MEM_JOB_CHECK:
      /* @Trace: FOTA_SUD_API_00260 */
      memJobResult = Fota_PflsGetJobResult(Fota_MemoryInstance);
      if (MEM_JOB_OK == memJobResult)
      {
        if (FOTA_VERIFY_MEM_JOB_READ_SIGN == memJobProcessing)
        {
          FotaVerifyState = FOTA_STAT_VERIFY_START;
        }
        /* polyspace +1 MISRA-C3:15.7 [Not a defect:Low] "the IF condition is depend on configuration" */
        else if (FOTA_VERIFY_MEM_JOB_READ_FIRMWARE == memJobProcessing)
        {
          FotaVerifyState = FOTA_STAT_VERIFY_UPDATE;
        }
      }
      else if (MEM_JOB_FAILED == memJobResult)
      {
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
      else
      {
        /* Do nothing */
      }
    break;
    #endif
    case FOTA_STAT_VERIFY_FINISH:
      /* @Trace: FOTA_SUD_API_00121 */
      if (FOTA_SIGNATURE_VERIFY == Fota_VerifyMethod)
   /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        jobResult = Fota_VerifyCsmJobFinish();
      }
   /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      {
        jobResult = Fota_CRCGetResult();
      }

      if (jobResult == FOTA_JOB_FAILED)
      {
        #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        /* Report Det Error */
        Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
          FOTA_MAIN_FUNCTION_SID, FOTA_E_VERIFY_CSM_FINIISH_FAILED, retVal);
        #endif
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
      else
      {
        FotaVerifyState = FOTA_STAT_VERIFY_CHECK;
      }
      break;

    case FOTA_STAT_VERIFY_CHECK:
      /* @Trace: FOTA_SUD_API_00122 */
      jobResult = Fota_CheckAllJobResult();

      /* polyspace-begin MISRA-C3:14.3 [Justified:Low] "if-condition depends on the configuration." */
      if (jobResult == FOTA_JOB_OK)
      {
        FotaVerifyState = FOTA_STAT_VERIFY_END;
      }
      else if (jobResult == FOTA_JOB_PENDING)
      {
        #if FOTA_VERIFY_BUFFER_USED
        if (FOTA_TRUE == Fota_VerifyBufferUsed)
        {
          /* All jobs are not handle, continue for remaining job */
          FotaVerifyState = FOTA_STAT_VERIFY_INFO_READ;
        }
        else
        #endif
         /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
        {
          /* All jobs are not handle, continue for remaining job */
          FotaVerifyState = FOTA_STAT_VERIFY_START;
        }
         /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      }
      /* polyspace +1 DEFECT:USELESS_IF [Justified:Low] "if-condition depends on the configuration." */
      else
       /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        FotaVerifyState = FOTA_STAT_VERIFY_ERR;
      }
       /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */

      break;

    case FOTA_STAT_VERIFY_END:
      /* @Trace: FOTA_SUD_API_00123 */
      Fota_SetVerifyJobResult(FOTA_JOB_OK);
      FotaVerifyState = FOTA_STAT_VERIFY_INACTIVE;
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
      Fota_AfterFlashReadFunc();
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
      break;

    case FOTA_STAT_VERIFY_ERR:
    default:
      /* @Trace: FOTA_SUD_API_00261 */
      Fota_SetVerifyJobResult(FOTA_JOB_FAILED);
      FotaVerifyState = FOTA_STAT_VERIFY_INACTIVE;
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
      Fota_AfterFlashReadFunc();
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
      break;
  }
}
/* polyspace-end CODE-METRIC:VG,CALLS,LEVEL,FXLN [Justified:Low] "High risk of code changes: Changes have wide impact" */

/*******************************************************************************
** Function Name        : Fota_CRCInitDataPushBuffer                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Init data for caculation CRC                        **
**                        when the verify buffer option is enabled            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataRemainSize                                      **
**                        crcAreaNum                                          **
**                        dataVerifiedSize                                    **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_CrcInfo                                        **
**                        Fota_CalcVerifyCRC                                  **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

#if FOTA_VERIFY_BUFFER_USED
static FUNC(void, FOTA_CODE) Fota_CRCInitDataPushBuffer(
                                                  uint32 *dataRemainSize,
                                                  uint16 *crcAreaNum,
                                                  uint32 *dataVerifiedSize)
{
  /* @Trace: FOTA_SUD_API_00137 */
  uint16 initVerifyCRC = 0;

  initVerifyCRC =
    Fota_CrcInfo->InitCrc[INIT_CRC_LEN - CRC_INIT_HIBYTE_OFF];

  initVerifyCRC = initVerifyCRC << 8;

  initVerifyCRC |=
  Fota_CrcInfo->InitCrc[INIT_CRC_LEN - CRC_INIT_LOBYTE_OFF];

  Fota_CalcVerifyCRC = initVerifyCRC;

  *crcAreaNum = 0;

  *dataRemainSize = Fota_CrcInfo->CrcArea[*crcAreaNum].EndAddress -
    Fota_CrcInfo->CrcArea[*crcAreaNum].StartAddress + 1;

  *dataVerifiedSize = 0;
}
#endif

/*******************************************************************************
** Function Name        : Fota_CRCInitDataPushDirect                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Init data for caculation CRC                        **
**                        when the verify buffer option is disabled           **
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
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_JobIndexProcessing                             **
**                        Fota_MemoryInstance                                 **
**                        Fota_CrcInfo                                        **
**                        Fota_CalcVerifyCRC                                  **
**                        Function(s) invoked :                               **
**                        Fota_PflsGetCovAddr                                 **
*******************************************************************************/

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CRCInitDataPushDirect(void)
{
  Fota_JobResultType jobResult;
  Fota_VerificationSwUnitType *ptrHandler;
  const Fota_TargetBlockSwUnitType *signaturePtr;
  uint32 crcInfoAddress;
  uint16 initVerifyCRC = 0;
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  Std_ReturnType retVal = E_NOT_OK;
  uint32 crcInfoSize;
  crcInfoSize = sizeof(Fota_CrcInfoType);
  #endif
  /* @Trace: FOTA_SUD_API_00138 */
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
  /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  signaturePtr = ptrHandler->VerifySignature;
  crcInfoAddress = signaturePtr->StartAddress;


  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
  * the register value can be read via the address" */
  /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
  retVal = Fota_PflsGetCovAddr(Fota_MemoryInstance,
  		                     FOTA_ALT_ADDR,
							 &crcInfoAddress,
							 &crcInfoSize);
  /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
  * the register value can be read via the address" */
  /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */

  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
  /* @Trace: FOTA_SUD_API_00139 */
  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
  if (E_OK == retVal)
  #endif
  {
    crcInfoAddress = crcInfoAddress - INIT_CRC_LEN;

    /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
  /* polyspace +1 MISRA-C3:D4.11 [Not a defect:Low] "The parameter passed into a function is valid" */
    FOTA_MEMCPY((uint8 *)Fota_CrcInfo, (uint8 *)crcInfoAddress, sizeof(Fota_CrcInfoType));
    /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */

    initVerifyCRC =
      Fota_CrcInfo->InitCrc[INIT_CRC_LEN-CRC_INIT_HIBYTE_OFF];

    initVerifyCRC = initVerifyCRC << 8;

    initVerifyCRC |=
    Fota_CrcInfo->InitCrc[INIT_CRC_LEN-CRC_INIT_LOBYTE_OFF];

    Fota_CalcVerifyCRC = initVerifyCRC;
    jobResult = FOTA_JOB_OK;
  }
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  else
  {
    jobResult = FOTA_JOB_FAILED;
  }
  #endif
 
  return jobResult;
}
 
/*******************************************************************************
** Function Name        : Fota_Crc16CoverArea                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Caculate CRC16                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : data                                                **
**                        length                                              **
**                        crc                                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16 ret_crc                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Gau16_CRCA001_8                                **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
 
/* polyspace +2 MISRA-C3:8.13 [Not a defect:Low] "No impact of this rule violation" */
FUNC(uint16, FOTA_CODE) Fota_Crc16CoverArea(
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) data,
  VAR(uint32, AUTOMATIC) length,
  VAR(uint16, AUTOMATIC) crc
)
{
  /* @Trace: FOTA_SUD_API_00112 */
  uint16 ret_crc;
  uint32 length_temp;
  uint32 data_cnt;

  length_temp=length;
  ret_crc=crc;
  data_cnt=0u;

  if (data != NULL_PTR)
  {
    while (length_temp > 0UL)
    {
  
      /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
      ret_crc = (ret_crc >> 8) ^ (uint16)Fota_Gau16_CRCA001_8[(ret_crc ^ (data[data_cnt])) & 0xFFU];
       
      length_temp--;
      data_cnt++;
    }
  }
  return ret_crc;
}
 
/*******************************************************************************
** Function Name        : Fota_CalculateCRCBuffer                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Calculate CRC for each block                        **
**                        when the verify buffer option is enabled            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : crcAreaNum                                          **
**                                                                            **
** Output Parameters    : dataRemainSize                                      **
**                        dataVerifiedSize                                    **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_CrcInfo                                        **
**                        FotaVerifyState                                     **
**                        Fota_CalcVerifyCRC                                  **
**                        Function(s) invoked :                               **
**                        Fota_Crc16CoverArea                                 **
*******************************************************************************/

#if FOTA_VERIFY_BUFFER_USED
static FUNC(void, FOTA_CODE) Fota_CalculateCRCBuffer(uint32 *dataRemainSize,
                                               uint16 *crcAreaNum,
                                               uint32 *dataVerifiedSize)
{
  /* @Trace: FOTA_SUD_API_00144 */
  Fota_CalcVerifyCRC = Fota_Crc16CoverArea(Fota_DataReadBuffer,
                                          Fota_DataSizeOneCycle,
                                          Fota_CalcVerifyCRC);

  *dataRemainSize -= Fota_DataSizeOneCycle;
  *dataVerifiedSize += Fota_DataSizeOneCycle;

  if (*dataRemainSize == 0)
  {
    *crcAreaNum = *crcAreaNum + 1;
    if (*crcAreaNum < Fota_CrcInfo->NumberOfCrcAreas)
    {
		/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
      *dataRemainSize = Fota_CrcInfo->CrcArea[*crcAreaNum].EndAddress -
        Fota_CrcInfo->CrcArea[*crcAreaNum].StartAddress + 1;

      *dataVerifiedSize = 0;
      FotaVerifyState = FOTA_STAT_VERIFY_BLOCK_READ;
    }
    else
    {
      FotaVerifyState = FOTA_STAT_VERIFY_FINISH;
    }
  }
  else
  {
    FotaVerifyState = FOTA_STAT_VERIFY_BLOCK_READ;
  }
}
#endif

/*******************************************************************************
** Function Name        : Fota_CalculateCRCDirect                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Calculate CRC for each block                        **
**                        when the verify buffer option is disabled           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : crcAreaNum                                          **
**                                                                            **
** Output Parameters    : dataRemainSize                                      **
**                        dataVerifiedSize                                    **
**                                                                            **
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_CrcInfo                                        **
**                        Fota_MemoryInstance                                 **
**                        Fota_CalcVerifyCRC                                  **
**                        FotaVerifyState                                     **
**                        Fota_CalcVerifyCRC                                  **
**                        Function(s) invoked :                               **
**                        Fota_PflsGetCovAddr                                 **
**                        Fota_Crc16CoverArea                                 **
*******************************************************************************/
 
static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CalculateCRCDirect(
                                                      uint32 *dataRemainSize,
                                                      uint16 *crcAreaNum,
                                                      uint32 *dataVerifiedSize)
{
  /* @Trace: FOTA_SUD_API_00145 */
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  Std_ReturnType retVal = E_OK;
  #endif
  Fota_JobResultType jobResult;
  uint32 dataVerifySize;
  uint32 startAddress;
  static uint32 startAddressVerify;

  if (*dataRemainSize == FOTA_ZERO)
  {
    *dataVerifiedSize = FOTA_ZERO;
     /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    startAddress  = Fota_CrcInfo->CrcArea[*crcAreaNum].StartAddress;
     
    *dataRemainSize = Fota_CrcInfo->CrcArea[*crcAreaNum].EndAddress -
                 Fota_CrcInfo->CrcArea[*crcAreaNum].StartAddress + 1;

    #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
    /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    retVal = Fota_PflsGetCovAddr(Fota_MemoryInstance,
    		                     FOTA_ALT_ADDR,
								 &startAddress,
								 dataRemainSize);
    /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    #endif
    startAddressVerify = startAddress;
  }
  /* @Trace: FOTA_SUD_API_00146 */
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  if (E_OK == retVal)
  #endif
  {
    if (*dataRemainSize > CODE_FLASH_VERIFY_SIZE_OF_ONECYCLE)
    {
      dataVerifySize = CODE_FLASH_VERIFY_SIZE_OF_ONECYCLE;
    }
    else
    {
      dataVerifySize = *dataRemainSize;
    }

    /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-begin MISRA-C3:18.4 [Justified:Low] "Decrement and Increment operator is used to achieve better throughput" */
    Fota_CalcVerifyCRC = Fota_Crc16CoverArea((uint8 *)startAddressVerify + *dataVerifiedSize,
                                          dataVerifySize,
                                          Fota_CalcVerifyCRC);
    /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-end MISRA-C3:18.4 [Justified:Low] "Decrement and Increment operator is used to achieve better throughput" */

    *dataVerifiedSize += dataVerifySize;
    *dataRemainSize -= dataVerifySize;

    if (*dataRemainSize == FOTA_ZERO)
    {
      *crcAreaNum = *crcAreaNum + FOTA_ONE;
      if (*crcAreaNum >= Fota_CrcInfo->NumberOfCrcAreas)
      {
        *crcAreaNum = FOTA_ZERO;
        *dataVerifiedSize = FOTA_ZERO;
        FotaVerifyState = FOTA_STAT_VERIFY_FINISH;
        jobResult = FOTA_JOB_OK;
      }
      else
      {
        jobResult = FOTA_JOB_PENDING;
      }
    }
    else
    {
      jobResult = FOTA_JOB_PENDING;
    }
  }
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  else
  {
    jobResult = FOTA_JOB_FAILED;
  }
  #endif

  return jobResult;
}
 
/*******************************************************************************
** Function Name        : Fota_CRCGetResult                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get result of verification CRC                      **
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
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_CrcInfo                                        **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_CalcVerifyCRC                                  **
**                        Fota_JobIndexProcessing                             **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CRCGetResult(void)
{
  /* @Trace: FOTA_SUD_API_00148 */
  Fota_JobResultType jobResult = FOTA_JOB_FAILED;
  Fota_VerificationSwUnitType *ptrHandler;

  if (Fota_CalcVerifyCRC == Fota_CrcInfo->CrcValue)
  {
     /* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
    ptrHandler->VerifyJobState = FOTA_CSM_JOB_FINISHED;
     
    ptrHandler->VerifyJobResult = FOTA_CSM_E_OK;
    jobResult = FOTA_JOB_OK;
  }

  return jobResult;
}

/*******************************************************************************
** Function Name        : Fota_GetSecureFlashPublicKeyByDelimiter             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check delimiter type and get pubic key              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_Delimiter                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType Ldt_RetValue                         **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Sec_Gau8_Asims_Delimiter                            **
**                        Fota_SFSignChkCmd                                   **
**                        Fota_JobIndexProcessing                             **
**                        Sec_Gau8_Fst_Delimiter                              **
**                        Sec_Gau8_Signature_Length                           **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00002 FOTA_SRS_ES95489_52E_00003 */
/* @Trace: FOTA_SRS_ES95489_52E_00006 FOTA_SRS_ES95489_52E_00007 */
static FUNC(Std_ReturnType, FOTA_CODE) Fota_GetSecureFlashPublicKeyByDelimiter(
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) rul_Delimiter
)
{
  /* @Trace: FOTA_SUD_API_00133 */
  Std_ReturnType Ldt_RetValue = E_NOT_OK;
  uint8 Lu8_SwIndex;
  uint8 Lu8_MaxIndex;
  Fota_SFSign_MadeBy Ldt_CheckDelimiter = FOTA_SF_MADEBY_NONE;
  /*---------------------------------------------*
  *| Secure Flash 2.0 Signaure                  |*
  *|-----------+-------+------------------------+*
  *|           | size  | data                   |*
  *|-----------+-------+------------------------+*
  *| Delimiter | 4byte | many kinds             |*
  *|-----------+-------+------------------------+*
  *| Length    | 4byte | 0x00, 0x00, 0x01, 0x00 |*
  -+--------------------------------------------+*/

  Lu8_MaxIndex = (uint8)sizeof(Sec_Gau8_Asims_Delimiter)/(0x04);

  for(Lu8_SwIndex = 0; Lu8_SwIndex < Lu8_MaxIndex; Lu8_SwIndex++)
  {
     /* polyspace-begin MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    if((rul_Delimiter[0]==Sec_Gau8_Asims_Delimiter[Lu8_SwIndex][0])&&
         (rul_Delimiter[1]==Sec_Gau8_Asims_Delimiter[Lu8_SwIndex][1])&&
         (rul_Delimiter[2]==Sec_Gau8_Asims_Delimiter[Lu8_SwIndex][2])&&
         (rul_Delimiter[3]==Sec_Gau8_Asims_Delimiter[Lu8_SwIndex][3]))
          /* polyspace-end MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    {
      Ldt_CheckDelimiter = FOTA_SF_MADEBY_ASIMS;
      Fota_SFSignChkCmd[Fota_JobIndexProcessing].PublicKeyBuffer =
        Fota_Sec_Gau8_ImageServPubKeyAsims;
      break;
    }
  }
  /* @Trace: FOTA_SUD_API_00134 */
  if (Ldt_CheckDelimiter == FOTA_SF_MADEBY_NONE)
  {
    Lu8_MaxIndex = (uint8)sizeof(Sec_Gau8_Fst_Delimiter)/(0x04);

    for(Lu8_SwIndex = 0; Lu8_SwIndex < Lu8_MaxIndex; Lu8_SwIndex++)
    {
       /* polyspace-begin MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
      if((rul_Delimiter[0]==Sec_Gau8_Fst_Delimiter[Lu8_SwIndex][0])&&
         (rul_Delimiter[1]==Sec_Gau8_Fst_Delimiter[Lu8_SwIndex][1])&&
         (rul_Delimiter[2]==Sec_Gau8_Fst_Delimiter[Lu8_SwIndex][2])&&
         (rul_Delimiter[3]==Sec_Gau8_Fst_Delimiter[Lu8_SwIndex][3]))
          /* polyspace-end MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
      {
        Ldt_CheckDelimiter = FOTA_SF_MADEBY_FST;
        Fota_SFSignChkCmd[Fota_JobIndexProcessing].PublicKeyBuffer =
          Fota_Sec_Gau8_ImageServPubKeyFst;
        break;
      }
    }
  }

  if (Ldt_CheckDelimiter == FOTA_SF_MADEBY_NONE)
  {
    Ldt_RetValue = E_NOT_OK;
  }
  else
  {
    /* check signature length */
     /* polyspace-begin MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    if((rul_Delimiter[4]==Sec_Gau8_Signature_Length[0])&&
         (rul_Delimiter[5]==Sec_Gau8_Signature_Length[1])&&
         (rul_Delimiter[6]==Sec_Gau8_Signature_Length[2])&&
         (rul_Delimiter[7]==Sec_Gau8_Signature_Length[3]))
          /* polyspace-end MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    {
      Ldt_RetValue=E_OK;
    }
    else
    {
      Ldt_RetValue=E_NOT_OK;
    }
  }

  return Ldt_RetValue;
}

/*******************************************************************************
** Function Name        : Fota_SignInitDataPush                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get signature data                                  **
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
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_SFSignChkCmd                                   **
**                        Fota_JobIndexProcessing                             **
**                        Function(s) invoked :                               **
**                        Fota_GetSecureFlashPublicKeyByDelimiter             **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00002 FOTA_SRS_ES95489_52E_00003 */
/* @Trace: FOTA_SRS_ES95489_52E_00006 FOTA_SRS_ES95489_52E_00007 */
/* @Trace: FOTA_SRS_ES95489_52E_00008 */
static FUNC(Std_ReturnType, FOTA_CODE) Fota_SignInitDataPush(
  VAR(uint32, AUTOMATIC) signatureAddress)
{
  /* @Trace: FOTA_SUD_API_00132 */
  Std_ReturnType retVal;
  /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
  * the register value can be read via the address" */
  if (Fota_GetSecureFlashPublicKeyByDelimiter(
    (uint8 *)signatureAddress) == E_OK)
  {
    Fota_SFSignChkCmd[Fota_JobIndexProcessing].SignatureBuffer =
      (uint8*)(signatureAddress + (SEC_SF_SIGNATURE_DELIMITER_LENGTH +
                                   SEC_SF_SIGNATURE_SIZE_LENGTH));
    retVal = E_OK;
  }
  else
  {
    retVal = E_NOT_OK;
  }
  /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
  * the register value can be read via the address" */
  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_VerifyInitProcess                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Init data for verification operation                **
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
**                        Fota_Gast_SwUnitTable                               **
**                        Fota_ProgrammingSWUnitId                            **
**                        Fota_VerifyBufferUsed                               **
**                        Fota_VerifyMethod                                   **
**                        Fota_NumOfVerification                              **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 */
static FUNC(void, FOTA_CODE) Fota_VerifyInitProcess(void)
{
  /* @Trace: FOTA_SUD_API_00124 */
  uint8 jobIndex;
  Fota_VerificationSwUnitType *ptrHandler;
  const Fota_VerificationType *ptrVerification;
  const Fota_SwModule *swUnitHandlePtr;
  const Fota_TargetBlockSwUnitType *signaturePtr;

  swUnitHandlePtr = &Fota_Gast_SwUnitTable[Fota_ProgrammingSWUnitId];

  Fota_JobIndexProcessing = 0;
 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  ptrVerification = swUnitHandlePtr->VerificationInfoPtr;

  Fota_PtrSWUnitHandler = ptrVerification->VerificationSWUnit;

  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
  #if FOTA_VERIFY_BUFFER_USED
  Fota_VerifyBufferUsed = ptrHandler->VerifyBufferUsed;
  #endif

  signaturePtr = ptrHandler->VerifySignature;

  if (FOTA_SIGNATURE == signaturePtr->BlockType)
   /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
  {
    Fota_VerifyMethod = FOTA_SIGNATURE_VERIFY;
  }
   /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
  else
  {
    Fota_VerifyMethod = FOTA_CRC_VERIFY;
  }

  Fota_NumOfVerification = ptrVerification->NumOfVerification;

  for (jobIndex = 0; jobIndex < Fota_NumOfVerification; jobIndex++)
  {
    ptrHandler = &Fota_PtrSWUnitHandler[jobIndex];
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    ptrHandler->VerifyJobState = FOTA_CSM_JOB_IDLE;
    ptrHandler->VerifyJobResult = FOTA_CSM_E_OK;
  }
}
 
/*******************************************************************************
** Function Name        : Fota_VerifyReadInfo                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Init data for verification operation                **
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
** Remarks              : Global Variable(s)  :                               **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_JobIndexProcessing                             **
**                        Fota_MemoryInstance                                 **
**                        Fota_SignatureReadData                              **
**                        Fota_CrcInfo                                        **
**                        Function(s) invoked :                               **
**                        Fota_PflsTgtAreaSet                                 **
**                        Fota_PflsReadRequest                                **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 */
#if FOTA_VERIFY_BUFFER_USED
static FUNC(Std_ReturnType, FOTA_CODE) Fota_VerifyReadInfo(void)
{
  /* @Trace: FOTA_SUD_API_00126 */
  Std_ReturnType retVal;
  Fota_VerificationSwUnitType *ptrHandler;
  const Fota_TargetBlockSwUnitType *signaturePtr;

  retVal = E_NOT_OK;
  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  signaturePtr = ptrHandler->VerifySignature;

  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_ALT_ADDR);
  #else
  (void)Fota_PflsTgtAreaSet(Fota_MemoryInstance,FOTA_STD_ADDR);
  #endif
  
  if (FOTA_SIGNATURE == signaturePtr->BlockType)
   /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
  {
    retVal = Fota_PflsReadRequest(Fota_MemoryInstance, \
                                  signaturePtr->StartAddress, \
                                  Fota_SignatureReadData, (SEC_SF_SIGNATURE_DELIMITER_LENGTH +
                                                            SEC_SF_SIGNATURE_SIZE_LENGTH +
                                                            SEC_SF_SIGNATURE_SIZE));
  }
   /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
  else 
  {
    retVal = Fota_PflsReadRequest(Fota_MemoryInstance, \
                                  signaturePtr->StartAddress - INIT_CRC_LEN, \
                                  (uint8 *)Fota_CrcInfo, sizeof(Fota_CrcInfoType));
  }

  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Fota_VerifyCsmJobStart                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Init sequence and start Csm job service             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataRemainSize                                      **
**                        blockIndexProcessing                                **
**                        dataVerifiedSize                                    **
**                                                                            **
** Return parameter     : Fota_JobResultType result                           **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_JobIndexProcessing                             **
**                        Fota_SignatureReadData                              **
**                        Fota_MemoryInstance                                 **
**                        Fota_SFSignChkCmd                                   **
**                        Fota_SignatureReadData                              **
**                        Fota_CrcInfo                                        **
**                        Fota_VerifyBufferUsed                               **
**                        Function(s) invoked :                               **
**                        Fota_SignInitDataPush                               **
**                        Fota_PflsGetCovAddr                                 **
**                        Csm_KeyElementSet                                   **
**                        Csm_KeySetValid                                     **
**                        Csm_SignatureVerify                                 **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00002 FOTA_SRS_ES95489_52E_00008 FOTA_SRS_GENSEC_00006 */
/* polyspace-begin CODE-METRIC:VG,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */
/* polyspace-begin MISRA-C3:8.13 [Not a defect:Low] "For the AUTOSAR Spectification, the data type should point to a const qualified type" */
static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobStart(
  uint32 *dataRemainSize,
  uint16 *blockIndexProcessing,
  uint32 *dataVerifiedSize)
/* polyspace-end MISRA-C3:8.13 [Not a defect:Low] "For the AUTOSAR Spectification, the data type should point to a const qualified type" */
{
  /* @Trace: FOTA_SUD_API_00130 */
  Std_ReturnType retVal;
  Fota_JobResultType result;
  Crypto_VerifyResultType verifyResult;

  Fota_VerificationSwUnitType *ptrHandler;
  #if FOTA_VERIFY_BUFFER_USED
  const Fota_TargetBlockSwUnitType *targetBlockPtr;
  #endif
  #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
  uint32 signatureSize;
  #endif
  
  const Fota_TargetBlockSwUnitType *ptrBlockSignature;
  uint32 signatureAddress;
  result = FOTA_JOB_FAILED;
  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  ptrBlockSignature = ptrHandler->VerifySignature;
  #if FOTA_VERIFY_BUFFER_USED
  if (FOTA_TRUE == Fota_VerifyBufferUsed)
  {
  /* polyspace +1 MISRA-C3:11.4 [Not a defect:Low] "Not impact, this is not effect. " */
    retVal = Fota_SignInitDataPush((uint32)&Fota_SignatureReadData[0]);
  }
  else
  #endif
  {
    signatureAddress = ptrBlockSignature->StartAddress;
  
    #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
    /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
    signatureSize = FOTA_VERIFY_SIGNATURE_LEN;
    /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    retVal = Fota_PflsGetCovAddr(Fota_MemoryInstance,
    		                     FOTA_ALT_ADDR,
								 &signatureAddress,
								 &signatureSize);
    /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    if (retVal == E_OK)
    #endif
    {
      retVal = Fota_SignInitDataPush(signatureAddress);
    }
  }
  /* @Trace: FOTA_SUD_API_00131 */
  if (retVal == E_OK)
  {
    retVal = Csm_KeyElementSet(ptrHandler->VerifyCsmKeyId,
                               ptrHandler->VerifyCsmKeyElementId,
                               Fota_SFSignChkCmd[Fota_JobIndexProcessing].PublicKeyBuffer,
                               ptrHandler->VerifyCsmKeyLength);

    if (retVal == E_OK)
    {
       retVal = Csm_KeySetValid(ptrHandler->VerifyCsmKeyId);

      if (retVal == E_OK)
      {
        retVal = Csm_SignatureVerify(ptrHandler->VerifyCsmJobId,
                   CRYPTO_OPERATIONMODE_START,
                   NULL_PTR, 0,
                   Fota_SFSignChkCmd[Fota_JobIndexProcessing].SignatureBuffer,
                   FOTA_VERIFY_SIGNATURE_LEN,
                   &verifyResult);

        if (retVal == E_OK)
        {
          #if FOTA_VERIFY_BUFFER_USED
          if (FOTA_TRUE == Fota_VerifyBufferUsed)
          {
            targetBlockPtr = ptrHandler->VerifyTargetBlock;
            *blockIndexProcessing = 0;

            *dataRemainSize = targetBlockPtr[*blockIndexProcessing].EndAddress -
              targetBlockPtr[*blockIndexProcessing].StartAddress + 1;

            *dataVerifiedSize = 0;
          }
          /* polyspace +2 MISRA-C3:20.14 [Not a defect:Low] "No impact of this rule violation." */
          /* polyspace +1 MISRA-C3:D2.1 [Not a defect:Low] "No impact of this rule violation." */
          #else
        /* polyspace-begin RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and default case will run in specific cases." */
          FOTA_UNUSED_PTR(dataRemainSize);
          FOTA_UNUSED_PTR(blockIndexProcessing);
          FOTA_UNUSED_PTR(dataVerifiedSize);
          /* polyspace-end RTE:UNR */
          #endif
          result = FOTA_JOB_OK;
        }
      }
    }
    
    if(retVal == CRYPTO_E_BUSY)
    {
      /* Wait until CRYPTO_E_BUSY end */
      result = FOTA_JOB_PENDING;
    }
  }

  return result;
}
/* polyspace-end CODE-METRIC:VG,LEVEL [Justified:Low] "High risk of code changes: Changes have wide impact" */

/*******************************************************************************
** Function Name        : Fota_CheckAllJobResult                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check all number of verification are successfully   **
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
** Return parameter     : Fota_JobResultType result                           **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_NumOfVerification                              **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_VerifyBufferUsed                               **
**                        Fota_VerifyMethod                                   **
**                        Fota_JobIndexProcessing                             **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 */
static FUNC(Fota_JobResultType, FOTA_CODE) Fota_CheckAllJobResult(void)
{
  /* @Trace: FOTA_SUD_API_00149 */
  uint8 jobIndex;
  uint8 countJobOk;
  Fota_JobResultType result;
  Fota_VerificationSwUnitType *ptrHandler;
  const Fota_TargetBlockSwUnitType *signaturePtr;

  result = FOTA_JOB_FAILED;
  countJobOk = 0;

  for (jobIndex = 0; jobIndex < Fota_NumOfVerification; jobIndex++)
  {
    ptrHandler = &Fota_PtrSWUnitHandler[jobIndex];
 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    if (FOTA_CSM_JOB_IDLE == ptrHandler->VerifyJobState)
    {
      /* Job is not handled, break function and start new sequence */
      #if FOTA_VERIFY_BUFFER_USED
      Fota_VerifyBufferUsed = ptrHandler->VerifyBufferUsed;
      #endif
      signaturePtr = ptrHandler->VerifySignature;

      if (FOTA_SIGNATURE == signaturePtr->BlockType)
     /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      {
        Fota_VerifyMethod = FOTA_SIGNATURE_VERIFY;
      }
     /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      else
      {
        Fota_VerifyMethod = FOTA_CRC_VERIFY;
      }
      Fota_JobIndexProcessing = jobIndex;
      result = FOTA_JOB_PENDING;
      break;
    }
    /* polyspace+2 RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
    /* polyspace +1 MISRA-C3:15.7 [Not a defect:Low] "The IF condition is depend on configuration" */
    else if (FOTA_CSM_JOB_FINISHED == ptrHandler -> VerifyJobState)
    {
       /* polyspace+1 RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      if (FOTA_CSM_E_OK == ptrHandler->VerifyJobResult)
      {
        countJobOk++;
      }
    }
  }
  if (countJobOk == Fota_NumOfVerification)
  {
    result = FOTA_JOB_OK;
  }
  return result;
}

/*******************************************************************************
** Function Name        : Fota_VerifyCsmJobFinish                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Finish Csm job service                              **
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
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_JobIndexProcessing                             **
**                        Fota_SFSignChkCmd                                   **
**                        Fota_JobIndexProcessing                             **
**                        Function(s) invoked :                               **
**                        Csm_SignatureVerify                                 **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00002 FOTA_SRS_ES95489_52E_00008 FOTA_SRS_GENSEC_00006 */
static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobFinish(void)
{
  /* @Trace: FOTA_SUD_API_00147 */
  Crypto_VerifyResultType verifyResult;
  Fota_JobResultType jobResult;
  Fota_VerificationSwUnitType *ptrHandler;
  Std_ReturnType retVal;

  jobResult = FOTA_JOB_OK;

  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];

 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  retVal = Csm_SignatureVerify(ptrHandler->VerifyCsmJobId,
             CRYPTO_OPERATIONMODE_FINISH,
             NULL_PTR, 0,
             Fota_SFSignChkCmd[Fota_JobIndexProcessing].SignatureBuffer,
             FOTA_VERIFY_SIGNATURE_LEN,
             &verifyResult);


  if (E_OK == retVal)
  {
    ptrHandler->VerifyJobState = FOTA_CSM_JOB_FINISHED;

    if (CRYPTO_E_VER_OK == verifyResult)
    {
      ptrHandler->VerifyJobResult = FOTA_CSM_E_OK;
    }
    else
    {
      ptrHandler->VerifyJobResult = FOTA_CSM_E_NOT_OK;
    }
  }
  else
  {
    jobResult = FOTA_JOB_FAILED;
  }

  return jobResult;
}
 
/*******************************************************************************
** Function Name        : Fota_VerifyBlockRead                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Update Csm job service                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : dataRemainSize                                      **
**                        blockIndexProcessing                                **
**                        crcAreaNum                                          **
**                        dataVerifiedSize                                    **
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
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_JobIndexProcessing                             **
**                        Fota_VerifyMethod                                   **
**                        Fota_DataSizeOneCycle                               **
**                        Fota_MemoryInstance                                 **
**                        Fota_DataReadBuffer                                 **
**                        Function(s) invoked :                               **
**                        Fota_PflsReadRequest                                **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00008 FOTA_SRS_ES98765_02E_00020 FOTA_SRS_UDS_00025 */
#if FOTA_VERIFY_BUFFER_USED
static FUNC(Std_ReturnType, FOTA_CODE) Fota_VerifyBlockRead(
  uint32 dataRemainSize,
  uint16 blockIndexProcessing,
  uint16 crcAreaNum,
  uint32 dataVerifiedSize)
{
  /* @Trace: FOTA_SUD_API_00140 */
  Std_ReturnType retVal;
  const Fota_TargetBlockSwUnitType *targetBlockPtr;
  Fota_VerificationSwUnitType *ptrHandler;

  retVal = E_NOT_OK;
  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  targetBlockPtr = ptrHandler->VerifyTargetBlock;

  if (FOTA_SIGNATURE_VERIFY == Fota_VerifyMethod)
   /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
  {
  /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    if (dataRemainSize >= ptrHandler->VerifyMaxDataSizeOneCycle)
    {
      Fota_DataSizeOneCycle = ptrHandler->VerifyMaxDataSizeOneCycle;
    }
    else
    {
      Fota_DataSizeOneCycle = dataRemainSize;
    }
/* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    retVal = Fota_PflsReadRequest(Fota_MemoryInstance,
                                  targetBlockPtr[blockIndexProcessing].StartAddress +
                                  dataVerifiedSize,
                                  Fota_DataReadBuffer, Fota_DataSizeOneCycle);
  }
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
  else
  {
    if (dataRemainSize >= ptrHandler->VerifyMaxDataSizeOneCycle)
    {
      Fota_DataSizeOneCycle = ptrHandler->VerifyMaxDataSizeOneCycle;
    }
    else
    {
      Fota_DataSizeOneCycle = dataRemainSize;
    }
/* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    retVal = Fota_PflsReadRequest(Fota_MemoryInstance,
                                  (uint32)(Fota_CrcInfo->CrcArea[crcAreaNum].StartAddress) +
                                  dataVerifiedSize,
                                  Fota_DataReadBuffer, Fota_DataSizeOneCycle);
  }
  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Fota_VerifyCsmJobUpdateBuffer                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Update Csm job service                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataRemainSize                                      **
**                        blockIndexProcessing                                **
**                        dataVerifiedSize                                    **
**                                                                            **
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_PtrSWUnitHandler                               **
**                        Fota_JobIndexProcessing                             **
**                        Fota_DataReadBuffer                                 **
**                        Fota_SFSignChkCmd                                   **
**                        FotaVerifyState                                     **
**                        Function(s) invoked :                               **
**                        Csm_SignatureVerify                                 **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00002 FOTA_SRS_ES95489_52E_00008 FOTA_SRS_GENSEC_00006 */
#if FOTA_VERIFY_BUFFER_USED
static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobUpdateBuffer(
  uint32 *dataRemainSize,
  uint16 *blockIndexProcessing,
  uint32 *dataVerifiedSize)
{
  /* @Trace: FOTA_SUD_API_00141 */
  Crypto_VerifyResultType verifyResult;
  Std_ReturnType retVal;
  Fota_JobResultType jobResult;
  Fota_VerificationSwUnitType *ptrHandler;
  const Fota_TargetBlockSwUnitType *targetBlockPtr;

  jobResult = FOTA_JOB_FAILED;
  retVal = E_NOT_OK;

  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  targetBlockPtr = ptrHandler->VerifyTargetBlock;

  retVal = Csm_SignatureVerify(ptrHandler->VerifyCsmJobId,
             CRYPTO_OPERATIONMODE_UPDATE,
             Fota_DataReadBuffer, Fota_DataSizeOneCycle,
             Fota_SFSignChkCmd[Fota_JobIndexProcessing].SignatureBuffer,
             FOTA_VERIFY_SIGNATURE_LEN,
             &verifyResult);

  if (E_OK == retVal)
  {
    ptrHandler->VerifyJobState = FOTA_CSM_JOB_UPDATED;

    *dataRemainSize -= Fota_DataSizeOneCycle;
    *dataVerifiedSize += Fota_DataSizeOneCycle;

    if (*dataRemainSize == 0)
    {
      *blockIndexProcessing = *blockIndexProcessing + 1;
      if (*blockIndexProcessing < ptrHandler->VerifyNumberOfBlock)
      {
        *dataRemainSize = targetBlockPtr[*blockIndexProcessing].EndAddress -
          targetBlockPtr[*blockIndexProcessing].StartAddress + 1;

        *dataVerifiedSize = 0;

        FotaVerifyState = FOTA_STAT_VERIFY_BLOCK_READ;
      }
      else
      {
        FotaVerifyState = FOTA_STAT_VERIFY_FINISH;
      }
    }
    else
    {
      FotaVerifyState = FOTA_STAT_VERIFY_BLOCK_READ;
    }
    jobResult = FOTA_JOB_OK;
  }
  else
  {

  }
  return jobResult;
}
#endif

/*******************************************************************************
** Function Name        : Fota_VerifyCsmJobUpdateDirect                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Update Csm job service                              **
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
** Return parameter     : Fota_JobResultType jobResult                        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_MemoryInstance                                 **
**                        Fota_SFSignChkCmd                                   **
**                        Fota_JobIndexProcessing                             **
**                        FotaVerifyState                                     **
**                        Function(s) invoked :                               **
**                        Fota_PflsGetCovAddr                                 **
**                        Csm_SignatureVerify                                 **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES95489_52E_00002 FOTA_SRS_ES95489_52E_00008 FOTA_SRS_GENSEC_00006 */
static FUNC(Fota_JobResultType, FOTA_CODE) Fota_VerifyCsmJobUpdateDirect(void)
{
  /* @Trace: FOTA_SUD_API_00142 */
  Crypto_VerifyResultType verifyResult;
  Std_ReturnType retVal;
  Std_ReturnType finalResult;
  Fota_JobResultType jobResult;
  Fota_VerificationSwUnitType *ptrHandler;
  const Fota_TargetBlockSwUnitType *targetBlockPtr;
  uint32 startAddressVerify;
  uint32 dataSize;
  uint16 blockIndex;

  jobResult = FOTA_JOB_FAILED;
  finalResult = E_OK;
  

  ptrHandler = &Fota_PtrSWUnitHandler[Fota_JobIndexProcessing];
     /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  targetBlockPtr = ptrHandler->VerifyTargetBlock;
     
  blockIndex = 0;
  do
  {
    startAddressVerify  = targetBlockPtr[blockIndex].StartAddress;
    dataSize = targetBlockPtr[blockIndex].EndAddress - startAddressVerify + 1;

    #if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
    /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    retVal = Fota_PflsGetCovAddr(Fota_MemoryInstance,
    		                     FOTA_ALT_ADDR,
								 &startAddressVerify,
								 &dataSize);
    /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    if (E_OK == retVal)
    #endif
    {
      /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      retVal = Csm_SignatureVerify(ptrHandler->VerifyCsmJobId,
                 CRYPTO_OPERATIONMODE_UPDATE,
                 (const uint8*)startAddressVerify, dataSize,
                 Fota_SFSignChkCmd[Fota_JobIndexProcessing].SignatureBuffer,
                 FOTA_VERIFY_SIGNATURE_LEN,
                 &verifyResult);
      /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
    }

    finalResult = finalResult | retVal;

    blockIndex++;

  }
  while (blockIndex < ptrHandler->VerifyNumberOfBlock);
  /* @Trace: FOTA_SUD_API_00275 */
  if (E_OK == finalResult)
  {
    jobResult = FOTA_JOB_OK;
    ptrHandler->VerifyJobState = FOTA_CSM_JOB_UPDATED;
    FotaVerifyState = FOTA_STAT_VERIFY_FINISH;
  }
  else
  {

  }
  return jobResult;
}
 
#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
