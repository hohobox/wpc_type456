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
**  SRC-MODULE: Fota_NonMmuSubFunc.c                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Define sub-functions for supporting Non MMU types             **
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
** 2.0.0.0   31-Dec-2024   ThanhTVP2      #CP44-12051                         **
** 1.0.0     20-Feb-2023   DJ Lee         Initial version                     **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota.h"
#include "Fota_NonMmuSubFunc.h"
#include "Fota_MagicKeyMgr.h"
#include "Fota_Globals.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
** Function Name        : Fota_IsDualPartitionSwUnit                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the Index of Software Unit based on **
**                        SwUnitMemoryArea (in Dual Memory Case)              **
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
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Gast_SwUnitTable                               **
**                        Function(s) invoked :                               **
**                        Fota_GetSwUnitIdByLabel                             **
*******************************************************************************/

FUNC(Std_ReturnType,FOTA_CODE) Fota_IsDualPartitionSwUnit(
		  VAR(uint16,AUTOMATIC) ecuSwUnit)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;
	VAR(uint8,AUTOMATIC)          rub_ProgID = 0xFF;
	/* @Trace: FOTA_SUD_API_00056 */
	retVal = E_NOT_OK;
/* polyspace +1 RTE:UNR [Not a defect:Low] "It was checked manually. IF condition is depend on the configuration" */
	if(Fota_GetSwUnitIdByLabel(ecuSwUnit, &rub_ProgID)==E_OK)
	{
		/* polyspace +3 RTE:UNR [Not a defect:Low] "It was checked manually. IF condition is depend on the configuration" */
		/* polyspace-begin DEFECT:OUT_BOUND_ARRAY [Not a defect:Low] "IF condition is depend on the configuration." */
		/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "No impact of this rule violation" */
		if((Fota_Gast_SwUnitTable[rub_ProgID].SoftwareType == FOTA_RTSW_PARTA_TYPE)||
		   (Fota_Gast_SwUnitTable[rub_ProgID].SoftwareType == FOTA_RTSW_PARTB_TYPE))
	    /* polyspace-end DEFECT:OUT_BOUND_ARRAY [Not a defect:Low] "IF condition is depend on the configuration." */
		/* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
		{
			retVal = E_OK;
		}
		/* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	}

    return retVal;
}
 

/*******************************************************************************
** Function Name        : Fota_GetSwUnitIdByPartition                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the Index of Software Unit based on **
**                        Partition                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Partition                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SwUnitIdx                                           **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_GetSoftwareModuleBlkBySwType                   **
*******************************************************************************/

FUNC(Std_ReturnType,FOTA_CODE) Fota_GetSwUnitIdByPartition(
		VAR(Fota_PartitionType,AUTOMATIC) Partition,
		P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) SwUnitIdx)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;

	/* @Trace: FOTA_SUD_API_00058 */
	if(Partition==FOTA_PARTITION_A)
	{
		retVal = Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTA_TYPE,SwUnitIdx);
	}
	else if( Partition == FOTA_PARTITION_B)
	{
		retVal = Fota_GetSoftwareModuleBlkBySwType(FOTA_RTSW_PARTB_TYPE,SwUnitIdx);
	}
	else
	/* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	{
		/*do nothing*/
	}
	/* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
    return retVal;
}

/*******************************************************************************
** Function Name        : Fota_GetTargetPartition                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the target partition info           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : pTargetPartition                                    **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_GetActivePartition                             **
*******************************************************************************/

FUNC(Std_ReturnType,FOTA_CODE) Fota_GetTargetPartition(
		P2VAR(Fota_PartitionType, AUTOMATIC, FOTA_PRIVATE_DATA) pTargetPartition)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;
	VAR(Fota_PartitionType,AUTOMATIC) ActPart;
	/* @Trace: FOTA_SUD_API_00055 */
	retVal = E_NOT_OK;
/* polyspace+1 RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	if(Fota_GetActivePartition(&ActPart)==E_OK)
	 /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	{
		if(ActPart==FOTA_PARTITION_A)
		{
			*pTargetPartition = FOTA_PARTITION_B;
			retVal = E_OK;
		}
		
		else if(ActPart==FOTA_PARTITION_B)
		{
			*pTargetPartition = FOTA_PARTITION_A;
			retVal = E_OK;
		}
		else
		/* polyspace +1 RTE:UNR [Not a defect:Low] "It was checked manually. IF condition is depend on the configuration" */
		{
/* UNKNOWN OR NO RTSW */
#if (FOTA_MODE==FOTA_FBL_MODE)
/* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
			*pTargetPartition = FOTA_PARTITION_A;
			retVal = E_OK;
#else

#endif

		}
	}
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
    return retVal;
}
 
/*******************************************************************************
** Function Name        : Fota_GetActivePartition                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the active parition info            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : pActivePartition                                    **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                        Function(s) invoked :                               **
**                        Fota_GetRunPartition                                **
*******************************************************************************/

FUNC(Std_ReturnType,FOTA_CODE) Fota_GetActivePartition(
		P2VAR(Fota_PartitionType, AUTOMATIC, FOTA_PRIVATE_DATA) pActivePartition)
{
	VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;
	/* @Trace: FOTA_SUD_API_00011 */
	retVal = E_NOT_OK;
/* polyspace+1 RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	if(Fota_GetRunPartition(pActivePartition)==E_OK)
 /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	{
		retVal = E_OK;
	}
 /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
    return retVal;
}

/*******************************************************************************
** Function Name        : Fota_GetRunPartition                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to get the running partition               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : pRunPartition                                       **
**                                                                            **
** Return parameter     : Std_ReturnType retVal                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Fota_Gast_SwUnitTable                               **
**                        Function(s) invoked :                               **
**                        Fota_GetTopPrioActKey                               **
**                        Fota_GetSoftwareModuleBlkByRunArea                  **
*******************************************************************************/

FUNC(Std_ReturnType,FOTA_CODE) Fota_GetRunPartition(
		P2VAR(Fota_PartitionType, AUTOMATIC, FOTA_PRIVATE_DATA) pRunPartition)
{
  VAR(uint8, AUTOMATIC) programmingSwUnitId = 0xFF;

  VAR(Std_ReturnType,AUTOMATIC) retVal=E_NOT_OK;
  /* @Trace: FOTA_SUD_API_00012 */
  retVal = E_NOT_OK;

#if (FOTA_MODE==FOTA_APP_MODE)
  if(Fota_GetSoftwareModuleBlkByRunArea(&programmingSwUnitId)==E_OK)
#else /*(FOTA_MODE==FOTA_FBL_MODE)*/
  if(Fota_GetTopPrioActKey(FOTA_FLKEY_MGR,&programmingSwUnitId)==E_OK)
#endif
  {
	/* polyspace-begin DEFECT:OUT_BOUND_ARRAY [Justified:Low] "IF condition is depend on the configuration." */
	 /* polyspace +1 MISRA-C3:18.1 [Not a defect:Low] "The pointer memory location is suitable for dereference" */
	  if(Fota_Gast_SwUnitTable[programmingSwUnitId].SoftwareType==FOTA_RTSW_PARTA_TYPE)
	 /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */  
	  {
		/* polyspace-end DEFECT:OUT_BOUND_ARRAY [Justified:Low] "IF condition is depend on the configuration. " */
		  *pRunPartition=FOTA_PARTITION_A;
		  retVal=E_OK;
	  }
	  /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	  else if(Fota_Gast_SwUnitTable[programmingSwUnitId].SoftwareType==FOTA_RTSW_PARTB_TYPE)
	   /* polyspace-begin RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	  {
		  *pRunPartition=FOTA_PARTITION_B;
		  retVal=E_OK;
	  }
	   /* polyspace-end RTE:UNR [Not a defect:Low] "Not impact, IF condition is depend on configuration" */
	  else
	  /* polyspace-begin RTE:UNR [Not a defect:Low] "It was checked manually. IF condition is depend on the configuration" */
	  {
		  *pRunPartition=FOTA_PARTITION_UNKNOWN;
	  }
	   /* polyspace-end RTE:UNR [Not a defect:Low] "It was checked manually. IF condition is depend on the configuration" */
  }
#if (FOTA_MODE==FOTA_FBL_MODE)
  else
  {
	  /* @Trace: FOTA_SUD_API_00014 */
	  *pRunPartition=FOTA_PARTITION_UNKNOWN;
	  retVal=E_OK;
  }
#endif
  return retVal;
}
 
#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/