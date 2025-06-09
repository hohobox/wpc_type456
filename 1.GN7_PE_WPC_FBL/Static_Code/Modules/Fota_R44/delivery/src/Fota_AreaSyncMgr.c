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
**  SRC-MODULE: Fota_AreaSyncMgr.c                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provide definition of FOTA's area sync function               **
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
** 2.0.0.0      31-Dec-2024   ThanhTVP2    #CP44-12051                        **
** 1.1.1.0_HF1  20-Sep-2024   YWJung       #CP44-13136                        **
** 1.1.1.0      28-Jun-2024   KhanhHC      #CP44-8128, #CP44-9351             **
**                            DuyND25      #CP44-4174                         **
**                            YWJung       #CP44-9278                         **
** 1.0.0.0      23-Oct-2023   Djlee        Initial version                    **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota.h"
#include "Fota_Types.h"
#include "Fota_IntFunc.h"
#include "Fota_Cfg.h"
#include "Fota_Globals.h"
#include "Mem_76_Pfls.h"
#include "Fota_PflsInterface.h"
#include "Fota_AreaSyncMgr.h"
#include "Fota_BootManager.h"
#include "Fota_MagicKeyMgr.h"
#include "Fota_User_Callouts.h"

/* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
static Fota_JobResultType  Fota_AreaSyncResult   = FOTA_JOB_FAILED;
static Fota_SyncReqType    Fota_AreaSyncReq      = FOTA_SYNC_ALL_SWUNIT;
static uint8               Fota_AreaSyncRetryCnt = FOTA_SYNC_ALL_RETRY_CNT;
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"

#if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
static FUNC(void, FOTA_CODE)Fota_AreaSyncEnd_Cbk(void);
static FUNC(void, FOTA_CODE)Fota_AreaSyncErr_Cbk(void);
static FUNC(Std_ReturnType, FOTA_CODE) Fota_FlashCmp(uint32 CmpAddr1,uint32 CmpAddr2,uint32 Length);
#endif

/*******************************************************************************
** Function Name        : Fota_AreaSyncRequest                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request start area sync operation                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ren_ReqSync                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType RetVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_AreaSyncState                                  **
**                        Fota_AreaSyncReq                                    **
**                        Fota_AreaSyncResult                                 **
**                        Fota_AreaSyncRetryCnt                               **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.7 [Justified:Low] "Parameter depends on the Configuration." */
FUNC(Std_ReturnType, FOTA_CODE) Fota_AreaSyncRequest(Fota_SyncReqType ren_ReqSync)
/* polyspace-end MISRA-C3:2.7 [Justified:Low] "Parameter depends on the Configuration." */
{
	/* @Trace: FOTA_SUD_API_00062 */
	Std_ReturnType RetVal=E_NOT_OK;

	#if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)

		if(Fota_AreaSyncState==FOTA_SYNC_IDLE)
		{
			if(ren_ReqSync == FOTA_SYNC_ALL_SWUNIT)
			{
				Fota_AreaSyncReq      = ren_ReqSync;
				Fota_AreaSyncResult   = FOTA_JOB_PENDING;
				Fota_AreaSyncState    = FOTA_SYNC_START;
				Fota_AreaSyncRetryCnt = FOTA_SYNC_ALL_RETRY_CNT;

				RetVal=E_OK;
			}
			else /* (ren_ReqSync = FOTA_SYNC_VERIFIED_NONACT_SWUNIT) */
	 /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
			{
				Fota_AreaSyncReq      = ren_ReqSync;
				Fota_AreaSyncResult   = FOTA_JOB_PENDING;
				Fota_AreaSyncState    = FOTA_SYNC_START;
				Fota_AreaSyncRetryCnt = FOTA_SYNC_VERIFIED_NONACT_SWUNIT_RETRY_CNT;

				RetVal=E_OK;
			}
	/* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
		}
	#else
	FOTA_UNUSED(ren_ReqSync);
	#endif

	return RetVal;
}

/*******************************************************************************
** Function Name        : Fota_AreaSyncGetJobResult                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : result check area sync operation                    **
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
**                        Fota_AreaSyncResult                                 **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/
 
FUNC(Fota_JobResultType, FOTA_CODE) Fota_AreaSyncGetJobResult(void)
{
	/* @Trace: FOTA_SUD_API_00063 */
#if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
	return Fota_AreaSyncResult;
#else
	return FOTA_JOB_FAILED;
#endif
}
 
/*******************************************************************************
** Function Name        : Fota_AreaSyncEnd_Cbk                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : End result save                                     **
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
**                        Fota_AreaSyncState                                  **
**                        Fota_AreaSyncResult                                 **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

#if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
static FUNC(void, FOTA_CODE) Fota_AreaSyncEnd_Cbk(void)
{
	/* @Trace: FOTA_SUD_API_00167 */
	Fota_AreaSyncState  = FOTA_SYNC_IDLE;
	Fota_AreaSyncResult = FOTA_JOB_OK;
}

/*******************************************************************************
** Function Name        : Fota_AreaSyncErr_Cbk                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Err result save                                     **
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
**                        Fota_AreaSyncState                                  **
**                        Fota_AreaSyncResult                                 **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

static FUNC(void, FOTA_CODE) Fota_AreaSyncErr_Cbk(void)
{
	/* @Trace: FOTA_SUD_API_00168 */
	Fota_AreaSyncState  = FOTA_SYNC_IDLE;
	Fota_AreaSyncResult = FOTA_JOB_FAILED;
}

/*******************************************************************************
** Function Name        : Fota_FlashCmp                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : flash compare                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : CmpAddr1                                            **
**                        CmpAddr2                                            **
**                        Length                                              **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_BeforeFlashReadFunc                            **
**                        Fota_AfterFlashReadFunc                             **
*******************************************************************************/

static FUNC(Std_ReturnType, FOTA_CODE) Fota_FlashCmp(uint32 CmpAddr1,uint32 CmpAddr2,uint32 Length)
{
	/* @Trace: FOTA_SUD_API_00166 */
	uint32 rul_Loop;
	uint32 rul_u32Length;

	Std_ReturnType retVal=E_OK;

	rul_u32Length=(uint32)(Length/FOTA_FOUR)*FOTA_FOUR;

	Fota_BeforeFlashReadFunc();

	for (rul_Loop=FOTA_ZERO; rul_Loop<rul_u32Length; rul_Loop+=FOTA_FOUR)
	{
		/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
		* the register value can be read via the address" */
	/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
		if ((*(uint32 *)(CmpAddr1+rul_Loop)) != (*(uint32 *)(CmpAddr2+rul_Loop)))
		{
			retVal=E_NOT_OK;
			break;
		}
		/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
		* the register value can be read via the address" */
	}
	/* @Trace: FOTA_SUD_API_00201 */
	if (retVal==E_OK)
	{
		for(                 ;rul_Loop<Length;rul_Loop++)
		{
			/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
			* the register value can be read via the address" */
	/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
			if ((*(uint8 *)(CmpAddr1+rul_Loop)) != (*(uint8 *)(CmpAddr2+rul_Loop)))
			{
				retVal=E_NOT_OK;
				break;
			}
			/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
			* the register value can be read via the address" */
		}
	}

	Fota_AfterFlashReadFunc();

	return retVal;
}

/*******************************************************************************
** Function Name        : Fota_StdAltFlashCmp                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : STD, ALT in pfls flash compare                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : rul_StdAddr                                         **
**                        rul_StdLeng                                         **
**                        rub_memInstance                                     **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_PflsGetCovAddr                                 **
**                        Fota_FlashCmp                                       **
*******************************************************************************/

static FUNC(Std_ReturnType, FOTA_CODE) Fota_StdAltFlashCmp(uint32 rul_StdAddr,uint32 rul_StdLeng, uint8 rub_memInstance)
{
	uint32 rul_AltCovAddr;
	uint32 rul_AltCovLeng;
	uint32 rul_RemainLeng;
	uint16 ruw_CmpLoop;

	Std_ReturnType retVal=E_OK;

	rul_AltCovAddr=rul_StdAddr;
	rul_AltCovLeng=rul_StdLeng;
	rul_RemainLeng=rul_AltCovLeng;

	/* @Trace: FOTA_SUD_API_00165 */
	for (ruw_CmpLoop=FOTA_ZERO;ruw_CmpLoop<MAX_OF_CMPLOOPCNT;ruw_CmpLoop++)
	{
	  if (E_OK==Fota_PflsGetCovAddr(rub_memInstance, \
									FOTA_ALT_ADDR, \
									&rul_AltCovAddr, \
									&rul_AltCovLeng))
	  {
		  if (Fota_FlashCmp(rul_StdAddr,rul_AltCovAddr,rul_AltCovLeng)==E_OK)
		  {
			  /* polyspace-begin MISRA-C3:17.8 [Justified:Low] "It Modified for comparison of different address areas." */
			  rul_StdAddr   =rul_StdAddr   +rul_AltCovLeng;
			  /* polyspace-end MISRA-C3:17.8 [Justified:Low] "It Modified for comparison of different address areas." */
			  rul_AltCovAddr=rul_StdAddr;

			  rul_RemainLeng=rul_RemainLeng-rul_AltCovLeng;
			  rul_AltCovLeng=rul_RemainLeng;
		  }
		  else
		  {
			  retVal=E_NOT_OK;
		  }
	  }
	  else
	  {
		retVal=E_NOT_OK;
	  }

	  if((retVal==E_NOT_OK)||(rul_RemainLeng==FOTA_ZERO))
	  {
		break;
	  }
	}

	return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Fota_AreaSyncMain                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Area Sync Main Function                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_AreaSyncState                                  **
**                        Fota_AreaSyncReq                                    **
**                        Fota_AreaSyncRetryCnt                               **
**                        Function(s) invoked :                               **
**                        Fota_GetMemInstanceBySwUnit                         **
**                        Fota_ChkVfyKey                                      **
**                        Fota_ChkActKey                                      **
**                        Fota_PflsTgtAreaSet                                 **
**                        Fota_PflsEraseRequest                               **
**                        Fota_PflsGetJobResult                               **
**                        Fota_BeforeFlashReadFunc                            **
**                        Fota_AfterFlashReadFunc                             **
**                        Fota_PflsWriteRequest                               **
**                        Fota_StdAltFlashCmp                                 **
**                        Fota_SetVfyKey_Request                              **
**                        Fota_SetKey_Result                                  **
**                        Fota_AreaSyncEnd_Cbk                                **
**                        Fota_AreaSyncErr_Cbk                                **
*******************************************************************************/
/* polyspace-begin CODE-METRIC:FXLN,CALLS,VG [Justified:Low] "High risk of code changes: Changes have wide impact" */
FUNC(void, FOTA_CODE) Fota_AreaSyncMain(void)
{
#if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
	VAR(Fota_SetKeyResultType, AUTOMATIC) setKeyResult;
	static uint8 rub_SwUnitIdx;

	static const Fota_SwModule *swUnitHandlePtr;
	static uint8 rub_NumOfVerification;
	static uint8 rub_JobIndexVerification;
	static uint8 rub_NumOfVBlock;
	static uint8 rub_JobIndexVBlock;
	static const Fota_VerificationType *ptrVerification;
	static Fota_VerificationSwUnitType *ptrSWUnitHandler;
	static Fota_VerificationSwUnitType *ptrHandler;
	static const Fota_TargetBlockSwUnitType *targetBlockPtr;
	static const Fota_TargetBlockSwUnitType *ptrBlock;
	static const Fota_TargetBlockSwUnitType *ptrSig;
	static uint8 rub_SyncMemoryInstance;
	static uint32 rul_SyncWaitCnt=FOTA_ZERO;

	uint32 rul_StdAddr;
	uint32 rul_StdLeng;

	VAR(Mem_76_Pfls_JobResultType,AUTOMATIC) ren_CodeEraseReport;
	Mem_76_Pfls_JobResultType memJobResult;

    switch(Fota_AreaSyncState)
    {
      case FOTA_SYNC_IDLE:


      break;

      case FOTA_SYNC_START:
		/* @Trace: FOTA_SUD_API_00264 */
      	Fota_AreaSyncState = FOTA_SYNC_SET_SWUNIT;
      	rub_SwUnitIdx = FOTA_ZERO;

      	if(Fota_AreaSyncRetryCnt>FOTA_ZERO)
      	{
      		Fota_AreaSyncRetryCnt--;
      	}

      break;

      case FOTA_SYNC_SET_SWUNIT:
		/* @Trace: FOTA_SUD_API_00153 */
    	(void)Fota_GetMemInstanceBySwUnit(rub_SwUnitIdx, &rub_SyncMemoryInstance);
    	swUnitHandlePtr = &Fota_Gast_SwUnitTable[rub_SwUnitIdx];
	/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    	ptrVerification = swUnitHandlePtr->VerificationInfoPtr;

    	if(Fota_AreaSyncReq==FOTA_SYNC_ALL_SWUNIT)
    	{
    		Fota_AreaSyncState = FOTA_SYNC_ERASE_SWUNIT_REQ;
    	}
    	else
 /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
    	{
            if ((E_OK==Fota_ChkVfyKey(rub_SwUnitIdx,FOTA_TARGET_AREA))&&(E_OK!=Fota_ChkActKey(rub_SwUnitIdx,FOTA_TARGET_AREA)))
            {
            	Fota_AreaSyncState = FOTA_SYNC_SET_SWUNIT_END;
            }
            else
            {
            	Fota_AreaSyncState = FOTA_SYNC_ERASE_SWUNIT_REQ;
            }
    	}
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      break;

      case FOTA_SYNC_ERASE_SWUNIT_REQ:
		/* @Trace: FOTA_SUD_API_00154 */
        #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
        (void)Fota_PflsTgtAreaSet(rub_SyncMemoryInstance,FOTA_ALT_ADDR);
        #endif
/* polyspace +3 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
  		if (E_OK == Fota_PflsEraseRequest(\
  					rub_SyncMemoryInstance, \
					swUnitHandlePtr->StartAddress, \
					swUnitHandlePtr->EndAddress - swUnitHandlePtr->StartAddress + FOTA_ONE))
  		{
  			rul_SyncWaitCnt   = FOTA_ZERO;
  			Fota_AreaSyncState = FOTA_SYNC_ERASE_SWUNIT_CHK;
  		}
  		else
  		{
  			Fota_AreaSyncState = FOTA_SYNC_ERR;
		  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ERASE_MEMORY_SID, FOTA_E_PFLS_ERASE_REQUEST_FAILED, FOTA_ZERO);
		  #endif
  		}

      break;

      case FOTA_SYNC_ERASE_SWUNIT_CHK:
	  	/* @Trace: FOTA_SUD_API_00155 */
    	ren_CodeEraseReport = Fota_PflsGetJobResult(rub_SyncMemoryInstance);

    	if(ren_CodeEraseReport == MEM_JOB_PENDING)
    	{
          if(rul_SyncWaitCnt>FOTA_SYNCWAITCNT)
          {
            Fota_AreaSyncState = FOTA_SYNC_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_ERASE_MEMORY_SID, FOTA_E_SYNC_WAIT_CNT_FAILED, FOTA_ZERO);
            #endif
          }
          else
          {
        	rul_SyncWaitCnt++;
          }
    	}
    	else if(ren_CodeEraseReport==MEM_JOB_OK)
    	{
    	  Fota_AreaSyncState = FOTA_SYNC_SET_VERIFY_UNIT;
    	  rub_JobIndexVerification = 0;
    	}
    	else
    	{
    	  Fota_AreaSyncState = FOTA_SYNC_ERR;
		  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_ERASE_MEMORY_SID, FOTA_E_ERASE_JOB_FAILED, FOTA_ZERO); 
		  #endif
    	}
    	break;

      case FOTA_SYNC_SET_VERIFY_UNIT:
		  /* @Trace: FOTA_SUD_API_00156 */
	/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    	  rub_NumOfVerification = ptrVerification->NumOfVerification;

    	  ptrSWUnitHandler = ptrVerification->VerificationSWUnit;
    	  ptrHandler = &ptrSWUnitHandler[rub_JobIndexVerification];
    	  rub_JobIndexVBlock       = 0;

    	  Fota_AreaSyncState = FOTA_SYNC_SET_VERIFY_UNIT_MODULE;

    	break;

      case FOTA_SYNC_SET_VERIFY_UNIT_MODULE:
		  /* @Trace: FOTA_SUD_API_00265 */
		/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    	  rub_NumOfVBlock = ptrHandler->VerifyNumberOfBlock;

    	  targetBlockPtr = ptrHandler->VerifyTargetBlock;
    	  ptrBlock = &targetBlockPtr[rub_JobIndexVBlock];

    	  Fota_AreaSyncState = FOTA_SYNC_WRITE_FW_REQ;

        break;

      case FOTA_SYNC_WRITE_FW_REQ:
		 /* @Trace: FOTA_SUD_API_00157 */
		 #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
		 (void)Fota_PflsTgtAreaSet(rub_SyncMemoryInstance,FOTA_ALT_ADDR);
		 #endif

   		 /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
   		 * the register value can be read via the address" */
		 Fota_BeforeFlashReadFunc();
	/* polyspace +2 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
   		 if (E_OK == Fota_PflsWriteRequest(rub_SyncMemoryInstance, \
      		                              (uint32)(ptrBlock->StartAddress), \
				                          (uint8*)(ptrBlock->StartAddress), ptrBlock->EndAddress - ptrBlock->StartAddress + FOTA_ONE))

         {
   			 rul_SyncWaitCnt   = FOTA_ZERO;
     	     Fota_AreaSyncState = FOTA_SYNC_WRITE_FW_CHK;
         }
         else
         {
        	 Fota_AfterFlashReadFunc();
        	 Fota_AreaSyncState = FOTA_SYNC_ERR;
        	 #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	 /* Report Det Error */
             Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
               FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_REQUEST_FAILED, FOTA_ZERO);
			 #endif
         }
   		 /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
   		 * the register value can be read via the address" */

      break;

      case FOTA_SYNC_WRITE_FW_CHK:
		  /* @Trace: FOTA_SUD_API_00158 */
          memJobResult = Fota_PflsGetJobResult(rub_SyncMemoryInstance);

          if (MEM_JOB_OK == memJobResult)
          {
			/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        	  rul_StdAddr   =ptrBlock->StartAddress;
        	  rul_StdLeng   =ptrBlock->EndAddress - ptrBlock->StartAddress + FOTA_ONE;

        	  if(Fota_StdAltFlashCmp(rul_StdAddr,rul_StdLeng,rub_SyncMemoryInstance)==E_OK)
        	  {
        		  Fota_AreaSyncState = FOTA_SYNC_SET_VERIFY_UNIT_MODULE_END;
        	  }
        	  else
        	  {
        		  Fota_AreaSyncState = FOTA_SYNC_ERR;
				  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        		  /* Report Det Error */
                  Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                    FOTA_MAIN_FUNCTION_SID, FOTA_E_STD_ALT_PFLS_COMPARE_FAILED, FOTA_ZERO);  
				  #endif
        	  }

        	  Fota_AfterFlashReadFunc();
          }
          else if (MEM_JOB_FAILED == memJobResult)
          {
        	  Fota_AfterFlashReadFunc();

        	  Fota_AreaSyncState = FOTA_SYNC_ERR;
			#if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	/* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);  
			#endif
          }
          else
          {
            if(rul_SyncWaitCnt>FOTA_SYNCWAITCNT)
            {
            	Fota_AfterFlashReadFunc();

            	Fota_AreaSyncState = FOTA_SYNC_ERR;
			    #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	    /* Report Det Error */
                Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                  FOTA_MAIN_FUNCTION_SID, FOTA_E_SYNC_WAIT_CNT_FAILED, FOTA_ZERO);  
			    #endif
            }
            else
            {
            	rul_SyncWaitCnt++;
            }
          }

      break;

      case FOTA_SYNC_SET_VERIFY_UNIT_MODULE_END:
		  /* @Trace: FOTA_SUD_API_00266 */
    	  if(rub_JobIndexVBlock >= (rub_NumOfVBlock-FOTA_ONE))
    	  {
    		  Fota_AreaSyncState = FOTA_SYNC_WRITE_SIG_REQ;
    	  }
    	  else
    	  {
    		  rub_JobIndexVBlock++;
    		  Fota_AreaSyncState = FOTA_SYNC_SET_VERIFY_UNIT_MODULE;
    	  }

      break;

      case FOTA_SYNC_WRITE_SIG_REQ:
		  /* @Trace: FOTA_SUD_API_00159 */
		/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
    	  ptrSig = ptrHandler->VerifySignature;

    	  #if (FOTA_MCU_MEMORY_ACCESS_TYPE==FOTA_MMU_TYPE)
		  (void)Fota_PflsTgtAreaSet(rub_SyncMemoryInstance,FOTA_ALT_ADDR);
		  #endif

		  Fota_BeforeFlashReadFunc();

          /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
          * the register value can be read via the address" */
          if (E_OK == Fota_PflsWriteRequest(rub_SyncMemoryInstance, \
         		                              (uint32)(ptrSig->StartAddress), \
 				                              (uint8*)(ptrSig->StartAddress), ptrSig->EndAddress - ptrSig->StartAddress + FOTA_ONE))
          {
        	 rul_SyncWaitCnt   = FOTA_ZERO;
      	     Fota_AreaSyncState = FOTA_SYNC_WRITE_SIG_CHK;
          }
          else
          {
        	 Fota_AfterFlashReadFunc();

         	 Fota_AreaSyncState = FOTA_SYNC_ERR;
			#if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	/* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_REQUEST_FAILED, FOTA_ZERO);
			#endif
          }
          /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
          * the register value can be read via the address" */


      break;

      case FOTA_SYNC_WRITE_SIG_CHK:
		  /* @Trace: FOTA_SUD_API_00160 */
          memJobResult = Fota_PflsGetJobResult(rub_SyncMemoryInstance);

          if (MEM_JOB_OK == memJobResult)
          {
		/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
        	  rul_StdAddr   =ptrSig->StartAddress;
        	  rul_StdLeng   =ptrSig->EndAddress - ptrSig->StartAddress + FOTA_ONE;

        	  if(Fota_StdAltFlashCmp(rul_StdAddr,rul_StdLeng,rub_SyncMemoryInstance)==E_OK)
        	  {
        		  Fota_AreaSyncState = FOTA_SYNC_SET_VERIFY_UNIT_END;
        	  }
        	  else
        	  {
        		  Fota_AreaSyncState = FOTA_SYNC_ERR;
				#if (FOTA_DEV_ERROR_DETECT == STD_ON)
        		/* Report Det Error */
                Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                  FOTA_MAIN_FUNCTION_SID, FOTA_E_STD_ALT_PFLS_COMPARE_FAILED, FOTA_ZERO);
				#endif
        	  }

        	  Fota_AfterFlashReadFunc();

          }
          else if (MEM_JOB_FAILED == memJobResult)
          {
        	  Fota_AfterFlashReadFunc();

        	  Fota_AreaSyncState = FOTA_SYNC_ERR;
			#if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	/* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
			#endif
          }
          else
          {
            if(rul_SyncWaitCnt>FOTA_SYNCWAITCNT)
            {
            	Fota_AfterFlashReadFunc();

            	Fota_AreaSyncState = FOTA_SYNC_ERR;
			  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	  /* Report Det Error */
              Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_MAIN_FUNCTION_SID, FOTA_E_SYNC_WAIT_CNT_FAILED, FOTA_ZERO);
			  #endif
            }
            else
            {
            	rul_SyncWaitCnt++;
            }
          }

      break;

      case FOTA_SYNC_SET_VERIFY_UNIT_END:
		  /* @Trace: FOTA_SUD_API_00161 */
    	  if(rub_JobIndexVerification >= (rub_NumOfVerification-FOTA_ONE))
    	  {
    		  Fota_AreaSyncState = FOTA_SYNC_SET_SWUNIT_END;
    	  }
    	  else
 /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
    	  {
    		  rub_JobIndexVerification++;
    		  Fota_AreaSyncState = FOTA_SYNC_SET_VERIFY_UNIT;
    	  }
  /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact,IF condition is depend on configuration" */
      break;
      case FOTA_SYNC_SET_SWUNIT_END:
		  /* @Trace: FOTA_SUD_API_00267 */
    	  /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */
    	  #if (FOTA_NUM_OF_SWUNIT>1U)
    	    if(rub_SwUnitIdx >= (Fota_NumOfSwUnit-FOTA_ONE))
    	    {
    		  rub_SwUnitIdx=FOTA_ZERO;
    		  Fota_AreaSyncState = FOTA_SYNC_WRITE_VFYKEY_REQ;
    	    }
    	    else
    	    {
    		  rub_SwUnitIdx++;
    		  Fota_AreaSyncState = FOTA_SYNC_SET_SWUNIT;
    	    }
    	  #else
    	    Fota_AreaSyncState = FOTA_SYNC_WRITE_VFYKEY_REQ;
    	  #endif
    	  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */

      break;

      case FOTA_SYNC_WRITE_VFYKEY_REQ:
		  /* @Trace: FOTA_SUD_API_00162 */
    	  if (E_OK == Fota_ChkVfyKey(rub_SwUnitIdx,FOTA_TARGET_AREA))
    	  {
            /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */
            #if (FOTA_NUM_OF_SWUNIT>1U)
              if(rub_SwUnitIdx >= (Fota_NumOfSwUnit-FOTA_ONE))
              {
                Fota_AreaSyncState = FOTA_SYNC_END;
              }
              else
              {
                rub_SwUnitIdx++;
              }
            #else
              Fota_AreaSyncState = FOTA_SYNC_END;
            #endif
        	  /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */
    	  }
    	  else
    	  {
			  if (E_OK == Fota_SetVfyKey_Request(rub_SwUnitIdx))
			  {
				  Fota_AreaSyncState = FOTA_SYNC_WRITE_VFYKEY_CHK;
			  }
			  else
			  {
				  Fota_AreaSyncState = FOTA_SYNC_ERR;
			  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
        	  /* Report Det Error */
              Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
                FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_REQUEST_FAILED, FOTA_ZERO);
			  #endif
			  }
    	  }

      break;

      case FOTA_SYNC_WRITE_VFYKEY_CHK:
	    (void)Fota_GetMemInstanceBySwUnit(rub_SwUnitIdx, &Fota_MemoryInstance);

		  /* @Trace: FOTA_SUD_API_00163 */
        setKeyResult = Fota_SetKey_Result();

        if (FOTA_SETMAGICKEY_OK == setKeyResult)
        {
		  if (E_OK == Fota_ChkVfyKey(rub_SwUnitIdx,FOTA_TARGET_AREA))
		  {
		    /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */
		    #if (FOTA_NUM_OF_SWUNIT>1U) 
              if(rub_SwUnitIdx >= (Fota_NumOfSwUnit-FOTA_ONE))
        	  {
        		Fota_AreaSyncState = FOTA_SYNC_END;
              }
        	  else
        	  {
        	    rub_SwUnitIdx++;
        		  Fota_AreaSyncState = FOTA_SYNC_WRITE_VFYKEY_REQ;
        	  }
        	#else
        	  Fota_AreaSyncState = FOTA_SYNC_END;
        	#endif
            /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the Configuration." */
          }
          else
          {
            Fota_AreaSyncState = FOTA_SYNC_ERR;
            #if (FOTA_DEV_ERROR_DETECT == STD_ON)
            /* Report Det Error */
            Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
              FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
            #endif           
          }
        }
        else if (FOTA_SETMAGICKEY_FAILED == setKeyResult)
        {
          Fota_AreaSyncState = FOTA_SYNC_ERR;
		  #if (FOTA_DEV_ERROR_DETECT == STD_ON)
          /* Report Det Error */
          Fota_DetReportErr(FOTA_MODULE_ID, FOTA_INSTANCE_ID,
            FOTA_MAIN_FUNCTION_SID, FOTA_E_WRITE_JOB_FAILED, FOTA_ZERO);
		  #endif
        }
        else
        {
          /* Do nothing */
        }

        break;

      case FOTA_SYNC_END:
		  /* @Trace: FOTA_SUD_API_00164 */
    	  Fota_AreaSyncEnd_Cbk();

      break;

      case FOTA_SYNC_ERR:
		  /* @Trace: FOTA_SUD_API_00268 */
    	  /* retry for fail-safe */
    	  if(Fota_AreaSyncRetryCnt>FOTA_ZERO)
    	  {
    		  Fota_AreaSyncState = FOTA_SYNC_START;
    	  }
    	  else
    	  {
    		  Fota_AreaSyncErr_Cbk();
    	  }

      break;
      default:
		  /* @Trace: FOTA_SUD_API_00269 */
    	  Fota_AreaSyncErr_Cbk();

      break;
    }

    /* Provide user current sync state and let user implement their own logic */
    Fota_GetAreaSyncState_UserCallout((uint8)Fota_AreaSyncState);
#endif
}
/* polyspace-end CODE-METRIC:FXLN,CALLS,VG [Justified:Low] "High risk of code changes: Changes have wide impact" */
#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"

/* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
