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
**  SRC-MODULE: Fota_PflsInterface.c                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Define interfacing functions to using the Mem_76_Pfls         **
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
** 2.0.1.0       14-Mar-2025   YWJung       #CP44-15409, #CP44-14095          **
**                                          #CP44-16648, #CP44-16830          **
** 2.0.0.0       14-Oct-2024   ThanhTVP2    #CP44-12051                       **
** 1.1.1.0_HF1   20-Sep-2024   YWJung       #CP44-10580                       **
** 1.0.0.0       20-Jun-2022   YSJ          Initial version                   **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota.h"
#include "Fota_PflsInterface.h"
#include "Mem_76_Pfls.h"
#include "Mem_76_Pfls_Types.h"
#include "Mem_76_Pfls_Globals.h"
#include "Fota_User_Callouts.h"

/* polyspace-begin MISRA-C3:11.8 [Justified:Low]"Not a defect. Type cast for memcpy is safe" */
/* polyspace-begin MISRA-C3:10.5 [Not a defect:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
static Fota_CodeFlash_InitType rue_CodeInitialized = FOTA_CODEFLASH_DEINITIALIZED;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
static Fota_HwSpSvBfType rue_HwSpSvBf1,rue_HwSpSvBf2;

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      External Function Definitions                         **
*******************************************************************************/

#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
** Function Name        : Fota_PflsInit                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Init Pfls module                                    **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        Function(s) invoked :                               **
**                        Fota_PflsInit_UserCallout                           **
*******************************************************************************/

FUNC(void, FOTA_CODE) Fota_PflsInit(void)
{
  uint8 Fota_Lu8_UseInternal = TRUE;

  /* @Trace: FOTA_SUD_API_00002 */
  Fota_PflsInit_UserCallout(&Fota_Lu8_UseInternal);

  /* polyspace-begin MISRA-C3:12.1,14.3 [Justified:Low] "No Impact of this rule violation" */
  if(TRUE == Fota_Lu8_UseInternal)
  {
    (((Mem_76_Pfls_FuncPtrTableType *)\
        &Mem_76_Pfls_FuncPtrTable)->InitServFuncPtr)(NULL_PTR);

    rue_CodeInitialized = FOTA_CODEFLASH_INITIALIZED;
  }
  /* polyspace-end MISRA-C3:12.1,14.3 [Justified:Low] "No Impact of this rule violation" */
}

/*******************************************************************************
** Function Name        : Fota_PflsDeinit                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : De-init Pfls module                                 **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        Function(s) invoked :                               **
**                        Fota_PflsDeinit_UserCallout                         **
*******************************************************************************/

FUNC(void, FOTA_CODE) Fota_PflsDeinit(void)
{
  uint8 Fota_Lu8_UseInternal = TRUE;

  /* @Trace: FOTA_SUD_API_00007 */
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
  Fota_PflsDeinit_UserCallout(&Fota_Lu8_UseInternal);
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */

  /* @Trace: FOTA_SUD_API_00008 */
  /* polyspace-begin MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */
  if (TRUE == Fota_Lu8_UseInternal)
  {
    (((Mem_76_Pfls_FuncPtrTableType *)\
        &Mem_76_Pfls_FuncPtrTable)->DeInitServFuncPtr)();

    rue_CodeInitialized = FOTA_CODEFLASH_DEINITIALIZED;
  }
  /* polyspace-end MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */
}

/*******************************************************************************
** Function Name        : Fota_PflsCancelReq                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Cancel Pfls request                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsCancelReq_UserCallout                      **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00039 FOTA_SRS_UDS_00014 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsCancelReq
(
	VAR(uint32, AUTOMATIC) rul_MemoryInstance
)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00065 */
    /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
    retVal = Fota_PflsCancelReq_UserCallout(rul_MemoryInstance);
    /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation. This function is for User." */
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00066 */
    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(rul_MemoryInstance, \
                                                  MEM_76_PFLS_CANCEL_JOB, \
                                    &rue_HwSpSvBf1.Bytes[FOTA_ZERO],
                                    &rue_HwSpSvBf2.rul_u32);
      /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    }
  }

  return retVal;
}
 
/*******************************************************************************
** Function Name        : Fota_PflsEraseRequest                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request erase job to Pfls                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : In_MemoryArea                                       **
**                        areaAddress                                         **
**                        eraseLen                                            **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsCancelReq_UserCallout                      **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00040 FOTA_SRS_ES98765_02E_00041 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsEraseRequest
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  VAR(uint32, AUTOMATIC) areaAddress,
  VAR(uint32, AUTOMATIC) eraseLen
)
{
  Std_ReturnType retVal=E_NOT_OK;

  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00031 */
    retVal = Fota_PflsEraseRequest_UserCallout(rul_MemoryInstance, areaAddress, eraseLen);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00032 */
    if(rue_CodeInitialized == FOTA_CODEFLASH_INITIALIZED)
    {
      /* Mem_76_Pfls_Erase */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->EraseServFuncPtr)(rul_MemoryInstance, \
                                                                areaAddress, \
                                                                eraseLen);
    }
  }

  return retVal;
}
 
/*******************************************************************************
** Function Name        : Fota_PflsWriteRequest                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request write job to Pfls                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                        rul_WriteStartAddr                                  **
**                        rup_Write_buff                                      **
**                        rul_write_size                                      **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsWriteRequest_UserCallout                   **
*******************************************************************************/

/* polyspace-begin MISRA-C3:8.13 [Justified:Low] "The pointer should point to const qualified type" */
/* @Trace: FOTA_SRS_ES98765_02E_00040 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsWriteRequest
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  VAR(uint32, AUTOMATIC) rul_WriteStartAddr,
  P2CONST(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) rup_Write_buff,
  VAR(uint32, AUTOMATIC) rul_write_size
){/* polyspace-end MISRA-C3:8.13 [Justified:Low] "The pointer should point to const qualified type" */
  Std_ReturnType retVal = E_NOT_OK;

  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00097 */
    retVal = Fota_PflsWriteRequest_UserCallout(rul_MemoryInstance, rul_WriteStartAddr, rup_Write_buff, rul_write_size);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00098 */
    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* Mem_76_Pfls_Write */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->WriteServFuncPtr)(rul_MemoryInstance, \
                                                                rul_WriteStartAddr, \
                                                                rup_Write_buff, \
                                                                rul_write_size);
    }
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsReadRequest                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request read job to Pfls                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                        rul_ReadStartAddr                                   **
**                        rul_read_size                                       **
**                                                                            **
** InOut parameter      : rup_Read_buff                                       **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsReadRequest_UserCallout                    **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00040 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsReadRequest
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  VAR(uint32, AUTOMATIC) rul_ReadStartAddr,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) rup_Read_buff,
  VAR(uint32, AUTOMATIC) rul_read_size
){
  Std_ReturnType retVal = E_NOT_OK;

  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00128 */
    retVal = Fota_PflsReadRequest_UserCallout(rul_MemoryInstance, rul_ReadStartAddr, rup_Read_buff, rul_read_size);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00129 */
    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* Mem_76_Pfls_Read */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->ReadServFuncPtr)(rul_MemoryInstance, \
                                                              rul_ReadStartAddr, \
                                                              rup_Read_buff, \
                                                              rul_read_size);
    }
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsSwapBankRequest                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request swap job to Pfls                            **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsSwapBankRequest_UserCallout                **
*******************************************************************************/

/* @Trace: FOTA_SRS_UDS_00004 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsSwapBankRequest
(
	void
)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 Fota_Lu8_UseInternal = TRUE;

  /* @Trace: FOTA_SUD_API_00043 */
  retVal = Fota_PflsSwapBankRequest_UserCallout(&Fota_Lu8_UseInternal);

  /* @Trace: FOTA_SUD_API_00044 */
  /* polyspace-begin MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */
  if ((E_OK == retVal) && (TRUE == Fota_Lu8_UseInternal) && (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized))
  {
    /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(FOTA_ZERO, \
                                                MEM_76_PFLS_SWAP_ACTIVE, \
                                  &rue_HwSpSvBf1.Bytes[FOTA_ZERO],
                                  &rue_HwSpSvBf2.rul_u32);
    /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
    * the register value can be read via the address" */
    /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
  }
  /* polyspace-end MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsGetJobResult                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get job result of Pfls                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Mem_76_Pfls_JobResultType jobResult                 **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsGetJobResult_UserCallout                   **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00040 FOTA_SRS_ES98765_02E_00041 */
/* polyspace-begin CODE-METRIC:CALLING [Justified:Low] "High risk of code changes: High frequency of use"*/
FUNC(Mem_76_Pfls_JobResultType, FOTA_CODE) Fota_PflsGetJobResult
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance
)
{
  Mem_76_Pfls_JobResultType jobResult;
  
  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00033 */
    jobResult = (Mem_76_Pfls_JobResultType)Fota_PflsGetJobResult_UserCallout(rul_MemoryInstance);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00034 */
    /* Mem_76_Pfls_GetJobResult */
    jobResult = (((Mem_76_Pfls_FuncPtrTableType *)\
          &Mem_76_Pfls_FuncPtrTable)->GetJobResultServFuncPtr)(rul_MemoryInstance);
  }

  return jobResult;
}
/* polyspace-end CODE-METRIC:CALLING [Justified:Low] "High risk of code changes: High frequency of use"*/

/*******************************************************************************
** Function Name        : Fota_PflsGetActiveBank                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get Active Bank info                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : pReadBank                                           **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsGetActiveBank_UserCallout                  **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00041 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsGetActiveBank
(
	P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) pReadBank
)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 Fota_Lu8_UseInternal = TRUE;

  retVal = Fota_PflsGetActiveBank_UserCallout(pReadBank, &Fota_Lu8_UseInternal);
  
  /* polyspace-begin MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */
  if(E_OK == retVal && TRUE == Fota_Lu8_UseInternal)
  {
    /* @Trace: FOTA_SUD_API_00017 */
    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(FOTA_ZERO, \
                                            MEM_76_PFLS_ACTIVE_BANK_CHECK, \
                                    &rue_HwSpSvBf1.Bytes[FOTA_ZERO],
                                    &rue_HwSpSvBf2.rul_u32);
      /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    }

    *pReadBank=rue_HwSpSvBf1.rub_u8;
  }
  /* polyspace-end MISRA-C3:12.1 [Justified:Low] "No Impact of this rule violation" */

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsGetCovAddr                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get Converted Address for ALT                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                        ren_Fota_HwSpSvAddrType                             **
**                                                                            **
** InOut parameter      : rup_StdAddr                                         **
**                        rup_length                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsGetCovAddr_UserCallout                     **
*******************************************************************************/

FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsGetCovAddr
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  VAR(Fota_HwSpSvAddrType,AUTOMATIC) ren_Fota_HwSpSvAddrType,
  P2VAR(uint32, AUTOMATIC, FOTA_PRIVATE_DATA) rup_StdAddr,
  P2VAR(uint32, AUTOMATIC, FOTA_PRIVATE_DATA) rup_length
)
{
  Std_ReturnType retVal = E_NOT_OK;


  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00135 */
    /* polyspace +1 MISRA-C3:10.3 [Not a defect:Low] "Have to casting to enum type" */
    retVal = Fota_PflsGetCovAddr_UserCallout(rul_MemoryInstance, (Fota_HwSpSvAddrType_CallOut)ren_Fota_HwSpSvAddrType, rup_StdAddr, rup_length);
  }

  else
  {
    /* @Trace: FOTA_SUD_API_00136 */
    /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    rue_HwSpSvBf1.rul_u32 = *rup_StdAddr;
    /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    rue_HwSpSvBf2.rul_u32 = *rup_length;
    

    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(rul_MemoryInstance, \
                                    MEM_76_PFLS_GET_OFFSET_STD_ALT, \
                                    &rue_HwSpSvBf1.Bytes[FOTA_ZERO],  /* addr */
                                    &rue_HwSpSvBf2.rul_u32); /* len */
      /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    }

    *rup_StdAddr = rue_HwSpSvBf1.rul_u32;
    *rup_length  = rue_HwSpSvBf2.rul_u32;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsTgtAreaSet                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set Area STD or ALT (for MMU)                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                        ren_Fota_HwSpSvAddrType                             **
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
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsTgtAreaSet_UserCallout                     **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00041 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsTgtAreaSet
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  VAR(Fota_HwSpSvAddrType, AUTOMATIC) rue_HwSpSvAddrType
)
{
  Std_ReturnType retVal = E_NOT_OK;

  
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00038 */
    /* polyspace +1 MISRA-C3:10.3 [Not a defect:Low] "Have to casting to enum type" */
    retVal = Fota_PflsTgtAreaSet_UserCallout(rul_MemoryInstance, (Fota_HwSpSvAddrType_CallOut)rue_HwSpSvAddrType);
  }
  
  else
  {
    if(rue_HwSpSvAddrType==FOTA_ALT_ADDR)
    /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and IF condition is depend on configuration." */
    {
      /* @Trace: FOTA_SUD_API_00039 */
      if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
      {
        /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
        * the register value can be read via the address" */
        /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
        retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                    &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(rul_MemoryInstance, \
                                              MEM_76_PFLS_ALT_ADDRESS_ACCESS, \
                                      &rue_HwSpSvBf1.Bytes[FOTA_ZERO],  /* addr */
                                      &rue_HwSpSvBf2.rul_u32); /* len */
        /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
        * the register value can be read via the address" */
        /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      }
    }
    else
    {
      /* @Trace: FOTA_SUD_API_00040 */
      if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
      {
        /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
        * the register value can be read via the address" */
        /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
        retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                    &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(rul_MemoryInstance, \
                                              MEM_76_PFLS_DIRECT_ADDRESS_ACCESS, \
                                      &rue_HwSpSvBf1.Bytes[FOTA_ZERO],  /* addr */
                                      &rue_HwSpSvBf2.rul_u32); /* len */
        /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
        * the register value can be read via the address" */
        /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      }
    }
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsGetFlashAlignment                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get Flash Alignment value                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                                                                            **
** InOut parameter      : rup_AlineVal                                        **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsGetFlashAlignment_UserCallout              **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00040 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsGetFlashAlignment
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  P2VAR(uint32, AUTOMATIC, FOTA_PRIVATE_DATA) rup_AlineVal
)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00059 */
    retVal = Fota_PflsGetFlashAlignment_UserCallout(rul_MemoryInstance, rup_AlineVal);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00060 */
    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(rul_MemoryInstance, \
                                            MEM_76_PFLS_GET_FLASH_ALIGNMENT, \
                                    &rue_HwSpSvBf1.Bytes[FOTA_ZERO],  /* addr */
                                    &rue_HwSpSvBf2.rul_u32); /* len */
      /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
    }

    *rup_AlineVal  = rue_HwSpSvBf1.rul_u32;
  }

  return retVal;
}

/*******************************************************************************
** Function Name        : Fota_PflsGetSectorSize                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get Sector Size value                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_MemoryInstance                                  **
**                        address                                             **
**                                                                            **
** InOut parameter      : rup_AlineVal                                        **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Mem_76_Pfls_FuncPtrTable                            **
**                        rue_CodeInitialized                                 **
**                        rue_HwSpSvBf1                                       **
**                        rue_HwSpSvBf2                                       **
**                        Function(s) invoked :                               **
**                        Fota_PflsUseCallout                                 **
**                        Fota_PflsGetSectorSize_UserCallout                  **
*******************************************************************************/

/* @Trace: FOTA_SRS_ES98765_02E_00040 */
FUNC(Std_ReturnType, FOTA_CODE) Fota_PflsGetSectorSize
(
  VAR(uint32, AUTOMATIC) rul_MemoryInstance,
  P2VAR(uint32, AUTOMATIC, FOTA_PRIVATE_DATA) rup_AlineVal,
  VAR(uint32, AUTOMATIC) address
)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  if(E_OK == Fota_PflsUseCallout(rul_MemoryInstance))
  {
    /* @Trace: FOTA_SUD_API_00022 */
    retVal = Fota_PflsGetSectorSize_UserCallout(rul_MemoryInstance, rup_AlineVal, address);
  }
  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:2.1,14.3 [Justified:Low] "if-condition depends on the configuration." */
  else
  {
    /* @Trace: FOTA_SUD_API_00023 */
    if (FOTA_CODEFLASH_INITIALIZED == rue_CodeInitialized)
    {
      /* @CTEC : Justify and exclude from coverage - Platform type check pre-processing */
      #if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
      rue_HwSpSvBf1.Bytes[3] = (uint8)((address >> 24) & (uint32)0xFF);
      rue_HwSpSvBf1.Bytes[2] = (uint8)((address >> 16) & (uint32)0xFF);
      rue_HwSpSvBf1.Bytes[1] = (uint8)((address >> 8) & (uint32)0xFF);
      rue_HwSpSvBf1.Bytes[0] = (uint8)(address & (uint32)0xFF);
      /* @CTEC : Justify and exclude from coverage - Platform type check pre-processing */
      #else
      rue_HwSpSvBf1.Bytes[0] = (uint8)((address >> 24) & (uint32)0xFF);
      rue_HwSpSvBf1.Bytes[1] = (uint8)((address >> 16) & (uint32)0xFF);
      rue_HwSpSvBf1.Bytes[2] = (uint8)((address >> 8) & (uint32)0xFF);
      rue_HwSpSvBf1.Bytes[3] = (uint8)(address & (uint32)0xFF);
      #endif
      rue_HwSpSvBf2.Bytes[0] = 4U;
      /* polyspace-begin DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      retVal = (((Mem_76_Pfls_FuncPtrTableType *)\
                  &Mem_76_Pfls_FuncPtrTable)->HwSpecificServFuncPtr)(rul_MemoryInstance, \
                                            MEM_76_PFLS_GET_SECTOR_SIZE, \
                                    &rue_HwSpSvBf1.Bytes[FOTA_ZERO],  /* addr */
                                    &rue_HwSpSvBf2.rul_u32); /* len */
      /* polyspace-end DEFECT:PTR_CAST, MISRA-C3:11.3 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
      * the register value can be read via the address" */
      /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
      if (E_OK == retVal)
      {
        *rup_AlineVal  = rue_HwSpSvBf1.rul_u32;
      }
      else
      {

      }
    }
  }

  return retVal;
}

#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/