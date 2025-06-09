/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Fota_NonMmuSubFunc.c                                          **
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
********************************************************************************
** 1.1.6.0	 14-Apr-2025   KJShim       CP44-15734                            **
** 1.1.0.0   14-May-2024   HJOh         CP44-7948                             **
** 1.0.4.0   21-Aug-2024   JSKang       CP44-11940                            **
** 1.0.0.0   20-Feb-2023   DJ Lee       #                                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Fota_User_Callouts.h"

#ifndef FOTA_INTEGRATION_SINGLEMEM_PLATFORM

#include "Fota_MagicKeyMgr.h"
#include "Fota_PflsInterface.h"
#include "Fota_Globals.h"
#include "Fota_User_Callouts.h"

/* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
/* polyspace-begin RTE:OBAI,IDP [Justified:Low] "The index of array checked about range at Init or validated at generator"*/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

static Fota_KeyAreaInfoType gst_KeyWriteStr;

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

static FUNC(void, FOTA_CODE) Fota_CopyKeyToKeyWriteStr(
  VAR(uint32, AUTOMATIC) Key,
  VAR(uint32, AUTOMATIC) Key_Prio);

static FUNC(uint32, FOTA_CODE) Fota_ReadActKeyVal(Fota_MagicKeyAreaType *pMagicKeyArea, uint8 step);
static FUNC(uint32, FOTA_CODE) Fota_ReadActKeyPrio(Fota_MagicKeyAreaType *pMagicKeyArea, uint8 step);

/*******************************************************************************
** Function Name        : Fota_GetTopPrioActKey                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get top priority SwUnit idx             **
**                        (Non MMU & Single Only)                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ecuSwUnit                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : pEcuSwUnitIdx                                       **
**                                                                            **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/

FUNC(Std_ReturnType,FOTA_CODE) Fota_GetTopPrioActKey(
		     VAR(Fota_KeyMgrType,AUTOMATIC) KeyMgr,
		     P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) pEcuSwUnitIdx)
{
	Fota_MagicKeyAreaType    *pMagicKeyArea;
	const Fota_TargetBlockSwUnitType *pPartBlockPtr;

	VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;
	VAR(uint32,AUTOMATIC) MaxOfPrio=FOTA_ZERO;
	VAR(uint8,AUTOMATIC)  Index=FOTA_ZERO;
	VAR(uint8,AUTOMATIC)  ActKeyCnt=FOTA_ZERO;
	VAR(uint32,AUTOMATIC) ActKeyVal=FOTA_ZERO;
	VAR(uint32,AUTOMATIC) ActKeyPrio=FOTA_ZERO;

	VAR(uint32,AUTOMATIC) ActKeyCmpVal=FOTA_FL_SECURITY_KEY_VALUE;

	Fota_BeforeFlashReadFunc();

	if(KeyMgr==FOTA_BMKEY_MGR)
	{
		ActKeyCmpVal = FOTA_BM_SECURITY_KEY_VALUE;
	}
	else
	{
		ActKeyCmpVal = FOTA_FL_SECURITY_KEY_VALUE;
	}

	for (Index = FOTA_ZERO; Index < FOTA_NUM_OF_SWUNIT; Index++ )
	{
		pPartBlockPtr = Fota_Gast_SwUnitTable[Index].PartitionInfoPtr;
		/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
		* the register value can be read via the address" */
		/* polyspace-begin CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
		pMagicKeyArea = (Fota_MagicKeyAreaType *)(pPartBlockPtr->StartAddress);
		/* polyspace-end CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
		/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
		* the register value can be read via the address" */

		ActKeyCnt  = Fota_ReadActKeyCnt(pMagicKeyArea);
		if(ActKeyCnt != 0u)
		{
			ActKeyVal  = Fota_ReadActKeyVal(pMagicKeyArea,ActKeyCnt-FOTA_ONE);
			ActKeyPrio = Fota_ReadActKeyPrio(pMagicKeyArea,ActKeyCnt-FOTA_ONE);

			if(ActKeyVal==ActKeyCmpVal)
			{
				/* polyspace-begin MISRA-C3:14.3 [Justified:Low] "if-condition depends on the MCU." */
				if(ActKeyPrio>=MaxOfPrio)
				{
					MaxOfPrio    = ActKeyPrio;
					*pEcuSwUnitIdx = Index;
					retVal        = E_OK;
				}
				/* polyspace-end MISRA-C3:14.3 [Justified:Low] "if-condition depends on the MCU." */
			}
		}
	}

	Fota_AfterFlashReadFunc();

	return retVal;
}

/*******************************************************************************
** Function Name        : Fota_SetTopPrioActKey_Request                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : request function to set top priority SwUnit idx     **
**                        (Non MMU & Single Only)                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : KeyMgr,EcuSwUnitIdx                                 **
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

FUNC(Std_ReturnType,FOTA_CODE) Fota_SetTopPrioActKey_Request(
		     VAR(Fota_KeyMgrType,AUTOMATIC) KeyMgr,
		     VAR(uint8,AUTOMATIC) EcuSwUnitIdx)
{

	VAR(uint8,AUTOMATIC) ActSwUnitIdx=FOTA_ZERO;
	VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;

	VAR(uint8,AUTOMATIC)  ActActKeyCnt;
	VAR(uint32,AUTOMATIC) ActActKeyPrio;
	VAR(uint32,AUTOMATIC) TgtActKeyCnt,TgtActKeyPrio;
	VAR(uint32,AUTOMATIC) TgtActKeyAddr=FOTA_ZERO;

	const Fota_TargetBlockSwUnitType *pActPartBlockPtr;
	Fota_MagicKeyAreaType            *pActMagicKeyArea;

	const Fota_TargetBlockSwUnitType *pTgtPartBlockPtr;
	Fota_MagicKeyAreaType            *pTgtMagicKeyArea;

	VAR(uint8,AUTOMATIC)             TgtMemoryInstance;



	if(Fota_GetTopPrioActKey(KeyMgr,&ActSwUnitIdx)==E_OK)
	{
		pActPartBlockPtr = Fota_Gast_SwUnitTable[ActSwUnitIdx].PartitionInfoPtr;
		/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
		* the register value can be read via the address" */
		/* polyspace-begin CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
		pActMagicKeyArea = (Fota_MagicKeyAreaType *)(pActPartBlockPtr->StartAddress);
		/* polyspace-end CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
		/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
		* the register value can be read via the address" */
		Fota_BeforeFlashReadFunc();

		ActActKeyCnt     = Fota_ReadActKeyCnt(pActMagicKeyArea);
		ActActKeyPrio    = Fota_ReadActKeyPrio(pActMagicKeyArea,ActActKeyCnt-1);

		Fota_AfterFlashReadFunc();

		TgtActKeyPrio    = ActActKeyPrio+FOTA_ONE;
	}
	else
	{
		TgtActKeyPrio    = FOTA_ZERO;
	}

	if(KeyMgr==FOTA_BMKEY_MGR)
	{
		Fota_CopyKeyToKeyWriteStr(FOTA_BM_SECURITY_KEY_VALUE,TgtActKeyPrio);
	}
	else
	{
		Fota_CopyKeyToKeyWriteStr(FOTA_FL_SECURITY_KEY_VALUE,TgtActKeyPrio);
	}
	/* polyspace-begin MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
	pTgtPartBlockPtr = Fota_Gast_SwUnitTable[EcuSwUnitIdx].PartitionInfoPtr;
	TgtMemoryInstance =  Fota_Gast_SwUnitTable[EcuSwUnitIdx].PflsInstanceId;
	/* polyspace-end MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
	/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */
	/* polyspace-begin CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
	pTgtMagicKeyArea = (Fota_MagicKeyAreaType *)(pTgtPartBlockPtr->StartAddress);
	/* polyspace-end CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
	/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */

	Fota_BeforeFlashReadFunc();

	TgtActKeyCnt     = Fota_ReadActKeyCnt(pTgtMagicKeyArea);
	/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */
	TgtActKeyAddr    = (uint32)(&(pTgtMagicKeyArea->ActKeyPage[TgtActKeyCnt]));
	/* polyspace-end MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */
	Fota_AfterFlashReadFunc();

	if(TgtActKeyCnt<FOTA_ACTKEY_MAX_CNT)
	{
		retVal = Fota_PflsWriteRequest(TgtMemoryInstance,
									  TgtActKeyAddr,
									   &(gst_KeyWriteStr.KeyBytes[0]),
									   FOTA_MAGICKEY_PAGE_SIZE);
	}
	else
	{
		retVal = FOTA_E_NOT_OK_STORIGE_FULL;
	}

	return retVal;
}
/*******************************************************************************
** Function Name        : Fota_ChkActKeyAllSwUnit                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check act key in All SwUnit                         **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : KeyArea                                             **
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


FUNC(Std_ReturnType,FOTA_CODE) Fota_ChkActKeyAllSwUnit(
			 VAR(Fota_ChkKeyAreaType,AUTOMATIC) KeyArea)
{
	  VAR(Std_ReturnType,AUTOMATIC)    retVal=E_OK;
	  uint8 rub_Index;

	  for(rub_Index=FOTA_ZERO;rub_Index<FOTA_NUM_OF_SWUNIT;rub_Index++)
	  {
		  if(Fota_ChkActKey(rub_Index,KeyArea)!=E_OK)
		  {
			  retVal=E_NOT_OK;
			  break;
		  }
	  }

	  return retVal;
}



/*******************************************************************************
** Function Name        : Fota_SetActKey_Request                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : request function to set top priority SwUnit idx     **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : KeyMgr,EcuSwUnitIdx                                 **
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

FUNC(Std_ReturnType,FOTA_CODE) Fota_SetActKey_Request(
	         VAR(Fota_KeyMgrType,AUTOMATIC) KeyMgr,
		     VAR(uint8,AUTOMATIC) EcuSwUnitIdx)
{
	const Fota_TargetBlockSwUnitType *pTgtPartBlockPtr;
	Fota_MagicKeyAreaType            *pTgtMagicKeyArea;
	VAR(Std_ReturnType,AUTOMATIC)    retVal=E_NOT_OK;

	VAR(uint32,AUTOMATIC) TgtActKeyPrio;
	VAR(uint32,AUTOMATIC) TgtActKeyAddr=FOTA_ZERO;
	VAR(uint8,AUTOMATIC)  TgtMemoryInstance;

    /* polyspace-begin MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
	pTgtPartBlockPtr = Fota_Gast_SwUnitTable[EcuSwUnitIdx].PartitionInfoPtr;
	TgtMemoryInstance = Fota_Gast_SwUnitTable[EcuSwUnitIdx].PflsInstanceId;
	/* polyspace-end MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
	/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */
	/* polyspace-begin CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
	pTgtMagicKeyArea = (Fota_MagicKeyAreaType *)(pTgtPartBlockPtr->StartAddress);
	TgtActKeyAddr    = (uint32)(&(pTgtMagicKeyArea->ActKeyPage[0]));
	/* polyspace-end CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
	/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */
	TgtActKeyPrio    = FOTA_ZERO;

	if(KeyMgr==FOTA_BMKEY_MGR)
	{
		Fota_CopyKeyToKeyWriteStr(FOTA_BM_SECURITY_KEY_VALUE,TgtActKeyPrio);
	}
	else
	{
		Fota_CopyKeyToKeyWriteStr(FOTA_FL_SECURITY_KEY_VALUE,TgtActKeyPrio);
	}

	retVal = Fota_PflsWriteRequest(TgtMemoryInstance,
			                       TgtActKeyAddr,
	                               &(gst_KeyWriteStr.KeyBytes[0]),
								   FOTA_MAGICKEY_PAGE_SIZE);

	return retVal;
}

/*******************************************************************************
** Function Name        : Fota_ChkVfyKeyAllSwUnit                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check verify key in All SwUnit                      **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : KeyArea                                             **
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


FUNC(Std_ReturnType,FOTA_CODE) Fota_ChkVfyKeyAllSwUnit(
			 VAR(Fota_ChkKeyAreaType,AUTOMATIC) KeyArea)
{
	  VAR(Std_ReturnType,AUTOMATIC)    retVal=E_OK;
	  uint8 rub_Index;


	  for(rub_Index=FOTA_ZERO;rub_Index<FOTA_NUM_OF_SWUNIT;rub_Index++)
	  {
		  if(Fota_ChkVfyKey(rub_Index,KeyArea)!=E_OK)
		  {
			  retVal=E_NOT_OK;
			  break;
		  }
	  }


	  return retVal;
}


/*******************************************************************************
** Function Name        : Fota_SetVfyKey_Request                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set request verify key in SwUnit Area               **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : EcuSwUnitIdx                                        **
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

FUNC(Std_ReturnType,FOTA_CODE) Fota_SetVfyKey_Request(
		     VAR(uint8,AUTOMATIC) EcuSwUnitIdx)
{
	const Fota_TargetBlockSwUnitType *pTgtPartBlockPtr;
	Fota_MagicKeyAreaType            *pTgtMagicKeyArea;

	VAR(Std_ReturnType,AUTOMATIC)    retVal=E_NOT_OK;

	VAR(uint32,AUTOMATIC) TgtVfyKeyAddr=FOTA_ZERO;
	VAR(uint8,AUTOMATIC)  TgtMemoryInstance;

	/* polyspace-begin MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
	pTgtPartBlockPtr = Fota_Gast_SwUnitTable[EcuSwUnitIdx].PartitionInfoPtr;
	TgtMemoryInstance = Fota_Gast_SwUnitTable[EcuSwUnitIdx].PflsInstanceId;
    /* polyspace-end MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
	/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */
	/* polyspace-begin CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
	pTgtMagicKeyArea = (Fota_MagicKeyAreaType *)(pTgtPartBlockPtr->StartAddress);
	TgtVfyKeyAddr    = (uint32)(&(pTgtMagicKeyArea->VfyKeyPage));
	/* polyspace-end CWE:704 [Not a defect:Low] "The integer value represents the address" */ 
	/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4,18.1 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
	* the register value can be read via the address" */

	Fota_CopyKeyToKeyWriteStr(FOTA_VERIFY_SECURITY_KEY_VALUE,/*TgtVfyKeyAddr*/ FOTA_ZERO);

	retVal = Fota_PflsWriteRequest(TgtMemoryInstance,
			                       TgtVfyKeyAddr,
	                               &(gst_KeyWriteStr.KeyBytes[0]),
								   FOTA_MAGICKEY_PAGE_SIZE);

	return retVal;
}

/*******************************************************************************
** Function Name        : Fota_SetVfyKey_Result                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : result of request magic key write in SwUnit Area    **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : EcuSwUnitIdx                                        **
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

FUNC(Fota_SetKeyResultType,FOTA_CODE) Fota_SetKey_Result(void)
{
	Mem_76_Pfls_JobResultType       result;
	Fota_SetKeyResultType           retVal;

	result=Fota_PflsGetJobResult(Fota_MemoryInstance);

	if(result==MEM_JOB_OK)
	{
		retVal=FOTA_SETMAGICKEY_OK;
	}
	else if(result==MEM_JOB_PENDING)
	{
		retVal=FOTA_SETMAGICKEY_PENDING;
	}
	else
	{
		retVal=FOTA_SETMAGICKEY_FAILED;
	}

	return retVal;
}

/*******************************************************************************
** Function Name        : Fota_CopyKeyToKeyWriteStr                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Internal function (Key buffer fill)                 **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Key, Key_Prio                                       **
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

static FUNC(void, FOTA_CODE) Fota_CopyKeyToKeyWriteStr(
  VAR(uint32, AUTOMATIC) Key,
  VAR(uint32, AUTOMATIC) Key_Prio)
{
  VAR(uint16, AUTOMATIC) Index;
  for(Index=FOTA_ZERO;Index<FOTA_MAGICKEY_PAGE_SIZE;Index++)
  {
	  gst_KeyWriteStr.KeyBytes[Index]=FOTA_ZERO;
  }

  gst_KeyWriteStr.KeyElement.OrgKey      = Key;
  gst_KeyWriteStr.KeyElement.OrgKey_Prio = Key_Prio;
  gst_KeyWriteStr.KeyElement.CpyKey      = Key;
  gst_KeyWriteStr.KeyElement.CpyKey_Prio = Key_Prio;
}

/*******************************************************************************
** Function Name        : Fota_ReadActKeyVal                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Internal function (Act Key read in structure)       **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : pMagicKeyArea, step                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : ActKey                                              **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
	
/* polyspace-begin MISRA-C3:8.13 [Justified:Low] "Not a defect" */
static FUNC(uint32, FOTA_CODE) Fota_ReadActKeyVal(Fota_MagicKeyAreaType *pMagicKeyArea, uint8 step)
/* polyspace-begin MISRA-C3:8.13 [Justified:Low] "Not a defect" */
{
  uint32 ActKey;

  ActKey = pMagicKeyArea->ActKeyPage[step].KeyElement.OrgKey;

  return ActKey;
}

/*******************************************************************************
** Function Name        : Fota_ReadActKeyVal                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Internal function (Act Key Prio read in structure)  **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : pMagicKeyArea, step                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : ActKeyPrio                                          **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
	
/* polyspace-begin MISRA-C3:8.13 [Justified:Low] "Not a defect" */
static FUNC(uint32, FOTA_CODE) Fota_ReadActKeyPrio(Fota_MagicKeyAreaType *pMagicKeyArea, uint8 step)
/* polyspace-end MISRA-C3:8.13 [Justified:Low] "Not a defect" */
{
  uint32 ActKeyPrio;
  /* polyspace-begin MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
  ActKeyPrio    = pMagicKeyArea->ActKeyPage[step].KeyElement.OrgKey_Prio;
  /* polyspace-end MISRA-C3:18.1 [Justified:High] "It gets array index in range" */
  return ActKeyPrio;
}

/*******************************************************************************
** Function Name        : Fota_ReadActKeyVal                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Internal function (Act Key Cnt read in structure)   **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : pMagicKeyArea, step                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
**                                                                            **
** Return parameter     : ActKeyCnt                                           **
**                                                                            **
** Preconditions        : none                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
	
/* polyspace-begin MISRA-C3:8.13,18.1 [Justified:Low] "Not a defect" */
FUNC(uint8, FOTA_CODE) Fota_ReadActKeyCnt(Fota_MagicKeyAreaType *pMagicKeyArea)
/* polyspace-end MISRA-C3:8.13,18.1 [Justified:Low] "Not a defect" */
{
  uint8 ActKeyCnt=FOTA_ZERO;

  Fota_DisableEccErrorRecord_UserCallout();

  for(ActKeyCnt=FOTA_ZERO;ActKeyCnt<FOTA_ACTKEY_MAX_CNT;ActKeyCnt++)
  {
    if((pMagicKeyArea->ActKeyPage[ActKeyCnt].KeyElement.OrgKey != FOTA_BM_SECURITY_KEY_VALUE) &&
       (pMagicKeyArea->ActKeyPage[ActKeyCnt].KeyElement.OrgKey != FOTA_FL_SECURITY_KEY_VALUE))
    {
      break;
    }
  }
  
  Fota_EnableEccErrorRecord_UserCallout();
  
  return ActKeyCnt;
}

/* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
/* polyspace-end RTE:OBAI,IDP [Justified:Low] "The index of array checked about range at Init or validated at generator"*/
#endif /* #ifndef FOTA_INTEGRATION_SINGLEMEM_PLATFORM */
