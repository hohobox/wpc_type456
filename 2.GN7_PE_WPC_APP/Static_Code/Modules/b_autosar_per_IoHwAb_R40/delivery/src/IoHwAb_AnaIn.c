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
**  SRC-MODULE: IoHwAb_AnaIn.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : APIs implementation for IoHwAb module                         **
**              IoHwAb_AnaInInit                                              **
**              IoHwAb_AnaInConvertStart                                      **
**              IoHwAb_AnaInConvertStop                                       **
**              IoHwAb_AnaInRead                                              **
**              IoHwAb_AnaInReadDirect                                        **
**              IoHwAb_AnaInFreeze                                            **
**              IoHwAb_AnaInUnfreeze                                          **
**              IoHwAb_AnaInFirstOrderFiltering                               **
**              IoHwAb_AnaInFilter                                            **
**              IoHwAb_AnaInConvertAllChannels                                **
**              IoHwAb_AnaInAdcAllGrNf                                        **
**              IoHwAb_AnaInDirReadDirect                                     **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By         Description                             **
********************************************************************************
** 1.15.3.0  08-Aug-2022   Yangjin    #35064                                  **
** 1.15.2    22-Mar-2022   Yangjin    #34887                                  **
** 1.15.1    24-Dec-2021   Yangjin    #33411                                  **
** 1.15.0.2  09-Sep-2021   Yangjin    #31974                                  **
** 1.15.0    08-Mar-2021   Yangjin    #28664                                  **
** 1.13.0    20-Jan-2021   Yangjin    #27616, #27537                          **
** 1.11.0    24-Sep-2020   Yangjin    #25514, #25515                          **
** 1.10.1    04-Aug-2020   Yangjin    #24902                                  **
** 1.10.0    26-Jun-2020   Yangjin    #24001, #24095                          **
** 1.9.0     04-Jun-2020   Yangjin    #23413, #23696                          **
** 1.8.1     08-May-2020   Yangjin    #23096                                  **
** 1.8.0     21-Apr-2020   Yangjin    #22141                                  **
** 1.7.1     26-Feb-2020   Yangjin    #21555, #21627, #21781                  **
** 1.7.0     26-Nov-2019   Yangjin    #19730                                  **
** 1.5.0     28-Aug-2019   Yangjin    #18753                                  **
** 1.3.2     04-Jun-2019   Yangjin    #17632                                  **
** 1.2.5     08-Aug-2018   Jongyoung  #13075                                  **
** 1.2.4     29-Jun-2018   Jongyoung  #13213                                  **
** 1.2.3     17-Aug-2017   Jongyoung  #9520                                   **
** 1.2.2     30-Mar-2017   Jongyoung  #7890                                   **
** 1.2.1     02-Dec-2016   Jongyoung  #6845                                   **
** 1.2.0     02-Nov-2016   Jongyoung  #6161                                   **
** 1.1.9     11-Oct-2016   Jongyoung  #6161                                   **
** 1.1.8     31-Aug-2016   Jongyoung  #5904                                   **
** 1.1.7     08-Jun-2016   Jongyoung  #5027                                   **
** 1.1.6     24-May-2016   Jongyoung  #4798                                   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_IoHwAb.h"
#include "IoHwAb_AnaIn.h"
#include "IoHwAb_Config.h"
#if (IOHWAB_USE_IO_MAN== STD_ON)
#include "IoHwAb_IOManager.h"
#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */

#if ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON))
#include "Adc.h"
#include "IoHwAb_Util.h"
#include "Adc_Cfg.h"
#endif

#include "SchM_IoHwAb.h"

#ifdef IOHWAB_MCAL_TI_TDA4X
#include "Adc_Priv.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* polyspace-begin RTE:IDP RTE:NIV [Justified:Low] "Validated by test cases. It works as intended." */
/*polyspace:begin<RTE: OBAI:Not a defect : No Action Planned > Array Checked  */
/* polyspace-begin RTE:UNR [Not a defect:Unset] "Reachable code" */
/* polyspace-begin MISRA-C3:D4.14 MISRA-C3:D4.5 [Justified:Unset] "Not a defect" */
/* polyspace-begin MISRA-C3:11.5 [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-begin DEFECT:USELESS_IF [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-begin MISRA-C3:14.3 MISRA-C3:2.1 [Justified:Low] "It depends on the configuration." */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON))

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin MISRA-C3:5.9 [Justified:Unset] "Not a defect" */
#if (defined(IOHWAB_MCAL_NXP_S32K14X))
static FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvCompleted(uint8 IoHwAb_AdcHwUnitNum, uint8 IoHwAb_AdcDirLength);
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
static FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvCompleted(const Adc_GroupConfigType * IoHwAb_AdcGroupCfg);
#else
static FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvCompleted(uint8 IoHwAb_AdcHwUnitNum);
#endif

#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
	  || defined(IOHWAB_MCAL_ST_SPC58XHX) \
	  || defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
	  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
	  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
	  || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) \
	  || defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
	  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM) \
	  || defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX) \
	  || defined(IOHWAB_MCAL_FREESCALE_MPC574XR) || defined(IOHWAB_MCAL_NXP_S32G2X) \
	  || defined(IOHWAB_MCAL_TI_TDA4X) \
	  || defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX) \
	  || defined(IOHWAB_MCAL_NXP_S32K14X))
static inline FUNC(uint32, IOHWAB_CODE)IoHwAb_AdcConvCompleted
#if (defined(IOHWAB_MCAL_NXP_S32K14X))
(uint8 AdcHwUnitNum, uint8 AdcDirLen);
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
(uint32 AdcBaseAddr);
#else
(uint8 AdcHwUnitNum);
#endif
#endif

#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX) \
  || defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
  || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM) \
  || defined(IOHWAB_MCAL_FREESCALE_MPC574XR) \
  || defined(IOHWAB_MCAL_NXP_S32G2X) || defined(IOHWAB_MCAL_TI_TDA4X))
static inline FUNC(void, IOHWAB_CODE)IoHwAb_AdcAcknowledged(uint8 AdcHwUnitNum);
#endif

#if (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
  || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM) \
  || defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX) \
  || defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX) \
  || defined(IOHWAB_MCAL_TI_TDA4X) )
static inline FUNC(void, IOHWAB_CODE)IoHwAb_AdcConvProc
#if (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
(Adc_GroupType AdcGrp);
#else
(uint8 AdcHwUnitNum);
#endif
#endif
/* polyspace-end MISRA-C3:5.9 [Justified:Unset] "Not a defect" */
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON)) */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"

#if (IOHWAB_USE_ANA_IN == STD_ON)
/*******************************************************************************
** Function Name        : IoHwAb_AnaInInit                                    **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : BufIdx                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Level                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInFiltResults,                       **
**                          IoHwAb_GaaAnaInInfos,                             **
**                          IoHwAb_GaaAnaInAdcResults,                        **
**                          IoHwAb_GblAnaInAdcIsBusy,                         **
**                          IoHwAb_GaaAnaInAllGroupInfos                      **
**                        Function(s) invoked    :                            **
**                          Adc_SetupResultBuffer,                            **
**                          Det_ReportError,                                  **
**                          Dem_ReportErrorStatus                             **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInInit(void)
{
  uint8 LucIdx; 
  uint8 LucAdcHwUnitId;

  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumLgc; LucIdx++)
  {
    IoHwAb_GaaAnaInFiltResults[LucIdx].blEnable = TRUE;
    IoHwAb_GaaAnaInFiltResults[LucIdx].usFiltResult
      = IoHwAb_GaaAnaInInfos[LucIdx].usDefVal;
    LucAdcHwUnitId = IoHwAb_GaaAnaInInfos[LucIdx].ucAdcHwUnitId;

    if (Adc_SetupResultBuffer(IoHwAb_GaaAnaInInfos[LucIdx].ddAdcGroupType,
      &(IoHwAb_GaaAnaInAdcResults.usOneChBuffer[LucAdcHwUnitId])) != E_OK)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
        (uint8)IOHWAB_ANAIN_INIT_SID, (uint8)IOHWAB_E_DET_SETUP_FAIL);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_SETUP_FAIL, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
    }
  }

  for (LucIdx = 0; LucIdx < IoHwAb_GucAdcHwUnitMaxNum; LucIdx++)
  {
    IoHwAb_GblAnaInAdcIsBusy[LucIdx] = FALSE;
  }

  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumAdcAllGroup; LucIdx++)
  {
    if (Adc_SetupResultBuffer(IoHwAb_GaaAnaInAllGroupInfos[LucIdx].ddAdcAllGroupType,
      IoHwAb_GaaAnaInAdcResults.usAllChBuffer[LucIdx]) != E_OK)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
      (uint8)IOHWAB_ANAIN_INIT_SID, (uint8)IOHWAB_E_DET_SETUP_FAIL);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_SETUP_FAIL, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
    }
  }  
}


/*******************************************************************************
** Function Name        : IoHwAb_AnaInConvertStart                            **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInAllGroupInfos                      **
**                        Function(s) invoked    :                            **
**                          Adc_EnableGroupNotification                       **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInConvertStart(void)
{
  uint8 LucIdx;

  /* enable each adc's notification function */
  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumAdcAllGroup; LucIdx++)
  {
    Adc_EnableGroupNotification(IoHwAb_GaaAnaInAllGroupInfos[LucIdx].ddAdcAllGroupType);
  }
}


/*******************************************************************************
** Function Name        : IoHwAb_AnaInConvertStop                             **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInAllGroupInfos                      **
**                        Function(s) invoked    :                            **
**                          Adc_DisableGroupNotification                      **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInConvertStop(void)
{
  uint8 LucIdx;

  /* disable each adc's notification function */
  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumAdcAllGroup; LucIdx++)
  {
    Adc_DisableGroupNotification(IoHwAb_GaaAnaInAllGroupInfos[LucIdx].ddAdcAllGroupType);
  }
}

/*******************************************************************************
** Function Name        : IoHwAb_AnaInRead                                    **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Value                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInFiltResults                        **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInRead(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_ValueType, AUTOMATIC, IOHWAB_APPL_DATA) Value)
{
  if(IoHwAb_GucAnaInNumLgc <= ChIdx)
  {
       #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
      (uint8)IOHWAB_ANAIN_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_WRONG_PARAM);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_WRONG_PARAM, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */    
  }
  else
  {
    SchM_Enter_IoHwAb_IoHwAbProtection();
    if (Value != NULL_PTR)
    {
      *Value = IoHwAb_GaaAnaInFiltResults[ChIdx].usFiltResult;
    }
    SchM_Exit_IoHwAb_IoHwAbProtection();
  }
}

#if (IOHWAB_USE_DIRECT_ACCESS_ANA_IN == STD_ON)
/*******************************************************************************
** Function Name        : IoHwAb_AnaInReadDirect                              **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LddError                                            **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInInfos,                             **
**                          IoHwAb_GblAnaInAdcIsBusy,                         **
**                          IoHwAb_GaaAnaInAdcResults                         **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection,                **
**                          Adc_StartGroupConversion,                         **
**                          Det_ReportError,                                  **
**                          Dem_ReportErrorStatus                             **
*******************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInReadDirect(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_ValueType, AUTOMATIC, IOHWAB_APPL_DATA) Value)
{
  Std_ReturnType LddError = E_OK;
  uint8 LucAdcHwUnitId;
#if !(defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
  uint8 LucAdcHwUnitNum;
#endif
  /*  Check if Value is NULL_PTR.  */
  if (Value == NULL_PTR)
  {
    #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
    (uint8)IOHWAB_ANAIN_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_WRONG_PARAM);
    #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
    #if (IOHWAB_USE_DEM_EVENT == STD_ON)
    Dem_ReportErrorStatus(IOHWAB_E_WRONG_PARAM, DEM_EVENT_STATUS_FAILED);
    #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
    LddError = E_NOT_OK;
  }

  /*  Check if IoHwAb_GucAnaInNumLgc is less than or equal to ChIdx.  */
  if (LddError == E_OK)
  {
    if (IoHwAb_GucAnaInNumLgc <= ChIdx)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
      (uint8)IOHWAB_ANAIN_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_WRONG_PARAM);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_WRONG_PARAM, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
      LddError = E_NOT_OK;
    }
    else
    {
      LucAdcHwUnitId = IoHwAb_GaaAnaInInfos[ChIdx].ucAdcHwUnitId;
#if !(defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
	  /* polyspace-begin DEFECT:USELESS_WRITE MISRA-C3:2.2 [Justified:Low] "It is used for other MCUs." */
      LucAdcHwUnitNum = IoHwAb_GaaAnaInInfos[ChIdx].ucAdcHwUnitNum;
	  /* polyspace-end DEFECT:USELESS_WRITE MISRA-C3:2.2 [Justified:Low] "It is used for other MCUs." */
#endif
    }
  }

  SchM_Enter_IoHwAb_IoHwAbProtection();

  /*  Check if Adc busy flag is set.  */
  if (LddError == E_OK)
  {
    if (IoHwAb_GblAnaInAdcIsBusy[LucAdcHwUnitId] == TRUE)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
        (uint8)IOHWAB_ANAIN_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_BUSY);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_BUSY, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
      LddError = IoHwAb_GucAnaInBusyErr;
    }
    else
    {
      IoHwAb_GblAnaInAdcIsBusy[LucAdcHwUnitId] = (boolean)TRUE;
    }
  }

  SchM_Exit_IoHwAb_IoHwAbProtection();

  if (LddError == E_OK)
  {
    SchM_Enter_IoHwAb_IoHwAbProtection();

    Adc_StartGroupConversion(IoHwAb_GaaAnaInInfos[ChIdx].ddAdcGroupType);

    #if (defined(IOHWAB_MCAL_NXP_S32K14X))
    LddError = IoHwAb_AnaInConvCompleted(LucAdcHwUnitNum, 0U);
    #elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
    LddError = IoHwAb_AnaInConvCompleted(
    (const Adc_GroupConfigType *) Adc_GetGroupConfig(IoHwAb_GaaAnaInInfos[ChIdx].ddAdcGroupType));
    #else
    LddError = IoHwAb_AnaInConvCompleted(LucAdcHwUnitNum);
    #endif
	
    #if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || defined(IOHWAB_MCAL_FREESCALE_MPC574XR) || \
         defined(IOHWAB_MCAL_ST_SPC58XCX)        || defined(IOHWAB_MCAL_ST_SPC58XHX) || \
         defined(IOHWAB_MCAL_NXP_S32K14X)        || defined(IOHWAB_MCAL_NXP_S32G2X))
    SchM_Exit_IoHwAb_IoHwAbProtection();
    (void)Adc_ReadGroup( IoHwAb_GaaAnaInInfos[ChIdx].ddAdcGroupType, Value);

    #else /* Aurix, RH850, Cypress */
      #if (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
      IoHwAb_AdcConvProc(IoHwAb_GaaAnaInInfos[ChIdx].ddAdcGroupType);
      #else
      IoHwAb_AdcConvProc(LucAdcHwUnitNum);
      #endif
    SchM_Exit_IoHwAb_IoHwAbProtection();        
      #if (defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX ) || \
           defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
      (void)Adc_ReadGroup( IoHwAb_GaaAnaInInfos[ChIdx].ddAdcGroupType, Value);
      #else /* When Arix, RH850 */
      *Value = IoHwAb_GaaAnaInAdcResults.usOneChBuffer[LucAdcHwUnitId];
      Adc_StopGroupConversion(IoHwAb_GaaAnaInInfos[ChIdx].ddAdcGroupType);
      #endif
    #endif

    /*  Clear the Adc busy flag.  */
    SchM_Enter_IoHwAb_IoHwAbProtection();
    IoHwAb_GblAnaInAdcIsBusy[LucAdcHwUnitId] = (boolean)FALSE;
    SchM_Exit_IoHwAb_IoHwAbProtection();
  }

  return LddError;
}
#endif /* (IOHWAB_USE_DIRECT_ACCESS_ANA_IN == STD_ON) */
/*******************************************************************************
** Function Name        : IoHwAb_AnaInFreeze                                  **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInFiltResults                        **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInFreeze(IoHwAb_IndexType ChIdx)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if (ChIdx < IoHwAb_GucAnaInNumLgc)
  {
    IoHwAb_GaaAnaInFiltResults[ChIdx].blEnable = FALSE;
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}

/*******************************************************************************
** Function Name        : IoHwAb_AnaInUnfreeze                                **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInFiltResults                        **
**                        Function(s) invoked    :                            **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection                 **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInUnfreeze(IoHwAb_IndexType ChIdx)
{
  SchM_Enter_IoHwAb_IoHwAbProtection();
  if (ChIdx < IoHwAb_GucAnaInNumLgc)
  {
    IoHwAb_GaaAnaInFiltResults[ChIdx].blEnable = TRUE;
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();
}
/* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations>It depends on the configuration to execute filtering logic.*/
/* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] "It depends on the configuration to execute filtering logic." */
/*******************************************************************************
** Function Name        : IoHwAb_AnaInFilter                                  **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInFiltResults,                       **
**                          IoHwAb_GaaAnaInInfos                              **
**                        Function(s) invoked    : none                       **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInFilter(void)
{
  uint8 LucIdx;
  uint8 LucFiltCst = 0U;          /*store localy the filtering constant*/

  for (LucIdx = 0U; LucIdx < IoHwAb_GucAnaInNumLgc; LucIdx++)
  {
    /*take every configured analog input*/
    if (IoHwAb_GaaAnaInFiltResults[LucIdx].blEnable != 0U)
    {
      /*for code zise optimization*/
      LucFiltCst = IoHwAb_GaaAnaInInfos[LucIdx].ucFiltCst;

      if (LucFiltCst != 0U)
      {
        /*we do the filtering for this one*/
        IoHwAb_GaaAnaInFiltResults[LucIdx].usFiltResult
          = IoHwAb_AnaInFirstOrderFiltering(               /*new filtered value*/
          IoHwAb_GaaAnaInFiltResults[LucIdx].usFiltResult, /*previous filtered value*/
          IoHwAb_GaaAnaInFiltResults[LucIdx].usRawResult,  /*current sample*/
          LucFiltCst);                                     /*filtering constant*/

        IoHwAb_GaaAnaInFiltResults[LucIdx].usFiltResult
          = IoHwAb_GaaAnaInFiltResults[LucIdx].usFiltResult;
      }
      else
      {
        /*input defined with no filtering*/
        /*just copy the raw value*/
        IoHwAb_GaaAnaInFiltResults[LucIdx].usFiltResult
          = IoHwAb_GaaAnaInFiltResults[LucIdx].usRawResult;
      }
    }
  }
}
/* polyspace:end<CERT-C:MSC12-C:Not a defect:Justify with annotations>It depends on the configuration to execute filtering logic.*/
/* polyspace-end DEFECT:DEAD_CODE [Justified:Low] "It depends on the configuration to execute filtering logic." */
/* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations>These if statements are for checking the Adc status for IO Manager logics. It depends on configured number of Adc HW units.*/
/* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] "These if statements are for checking the Adc status for IO Manager logics. It depends on configured number of Adc HW units." */
/*******************************************************************************
** Function Name        : IoHwAb_AnaInConvertAllChannels                      **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GblAnaInAdcIsBusy,                         **
**                          IoHwAb_GaaAnaInAllGroupInfos                      **
**                        Function(s) invoked    :                            **
**                          Adc_StartGroupConversion,                         **
**                          Det_ReportError,                                  **
**                          Dem_ReportErrorStatus                             **
*******************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvertAllChannels(void)
{
  uint8 LucIdx;
  uint8 LucIdxErr;
  uint8 LucHwUnitId = 0U;
  Std_ReturnType LddError = E_OK;

  SchM_Enter_IoHwAb_IoHwAbProtection();
  
  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumAdcAllGroup; LucIdx++)
  {
    LucHwUnitId = IoHwAb_GaaAnaInAllGroupInfos[LucIdx].ucAdcHwUnitId;
    if (IoHwAb_GblAnaInAdcIsBusy[LucHwUnitId] != TRUE)
    {
      IoHwAb_GblAnaInAdcIsBusy[LucHwUnitId] = TRUE;
	  IoHwAb_GblAnaInAdcIsBusyIOM[LucHwUnitId] = TRUE;
    }
	else
	{
      LddError = E_NOT_OK;
	  break;
	}
  }

  if (LddError != E_OK)
  {
    for (LucIdxErr = 0; LucIdxErr < LucIdx; LucIdxErr++)
    {
      LucHwUnitId = IoHwAb_GaaAnaInAllGroupInfos[LucIdxErr].ucAdcHwUnitId;
      IoHwAb_GblAnaInAdcIsBusy[LucHwUnitId] = FALSE;
	  IoHwAb_GblAnaInAdcIsBusyIOM[LucHwUnitId] = FALSE;
    }
  }

  SchM_Exit_IoHwAb_IoHwAbProtection();

  if (LddError == E_OK)
  {
    for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumAdcAllGroup; LucIdx++)
    {
      Adc_StartGroupConversion(IoHwAb_GaaAnaInAllGroupInfos[LucIdx].ddAdcAllGroupType);    
    }
  }
  else
  {
    #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
    (uint8)IOHWAB_ANAIN_CONVERT_ALL_SID, (uint8)IOHWAB_E_DET_BUSY);
    #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
    #if (IOHWAB_USE_DEM_EVENT == STD_ON)
    Dem_ReportErrorStatus(IOHWAB_E_BUSY, DEM_EVENT_STATUS_FAILED);
    #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
  }

  return LddError;
}
/*******************************************************************************
** Function Name        : IoHwAb_AnaInAdcAllGrNf                              **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : GroupId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInInfos,                             **
**                          IoHwAb_GaaAnaInFiltResults,                       **
**                          IoHwAb_GblAnaInAdcIsBusy                          **
**                        Function(s) invoked    :                            **
**                          IoHwAb_AnaInConvProcAllChannels,                  **
**                          IoHwAb_IOMAnaInAcqEnd                             **
*******************************************************************************/
FUNC(void, IOHWAB_CODE)IoHwAb_AnaInAdcAllGrNf(uint8 GroupId)
{
  uint8 LucIdx;
  uint8 LucBufIdx;
  uint8 LucHwUnitId = 0U;
  boolean LblDoCbk = TRUE;

  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumLgc; LucIdx++)
  {
    if (IoHwAb_GaaAnaInInfos[LucIdx].ucAdcGroupId == GroupId)
    {      
      if (LucHwUnitId != IoHwAb_GaaAnaInInfos[LucIdx].ucAdcHwUnitId)
      {
        /* In Normal case, it is assigned only once. */ 
        LucHwUnitId = IoHwAb_GaaAnaInInfos[LucIdx].ucAdcHwUnitId;
      }
      LucBufIdx = IoHwAb_GaaAnaInInfos[LucIdx].ucIndexInResultBuffer;
      IoHwAb_GaaAnaInFiltResults[LucIdx].usRawResult
        = IoHwAb_GaaAnaInAdcResults.usAllChBuffer[GroupId][LucBufIdx];
    }
  }

  SchM_Enter_IoHwAb_IoHwAbProtection();
  /* ADC Busy flag is cleared */
  if (LucHwUnitId < IoHwAb_GucAdcHwUnitMaxNum)
  {
    IoHwAb_GblAnaInAdcIsBusy[LucHwUnitId] = FALSE;
    IoHwAb_GblAnaInAdcIsBusyIOM[LucHwUnitId] = FALSE;
#if (IOHWAB_USE_IO_MAN == STD_ON)
    IoHwAb_GstIOManagerCounter.ucAllGrNfCalled[LucHwUnitId]++;
#endif
  }

  /* Callback function */
  for (LucIdx = 0; LucIdx < IoHwAb_GucAnaInNumAdcAllGroup; LucIdx++)
  {
    LucHwUnitId = IoHwAb_GaaAnaInAllGroupInfos[LucIdx].ucAdcHwUnitId;
    if (IoHwAb_GblAnaInAdcIsBusyIOM[LucHwUnitId] == TRUE)
    {
       LblDoCbk = FALSE;
    }
  }
  SchM_Exit_IoHwAb_IoHwAbProtection();

  /* All resource is free check */
  if (LblDoCbk == TRUE)
  {
    IoHwAb_IOMAnaInAcqEnd();
  }
}
/* polyspace:end<CERT-C:MSC12-C:Not a defect:Justify with annotations>These if statements are for checking the Adc status for IO Manager logics. It depends on configured number of Adc HW units.*/
/* polyspace-end DEFECT:DEAD_CODE [Justified:Low] "These if statements are for checking the Adc status for IO Manager logics. It depends on configured number of Adc HW units." */
#endif /* (IOHWAB_USE_ANA_IN == STD_ON) */

/*polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> No Impact of this rule violation*/
/*polyspace-begin RTE:UNR [Not a Defect] "No Impact of this rule violation"*/
/* polyspace-begin MISRA-C3:18.1 [Justified:Unset] "Not a defect and validated by test cases" */
#if (IOHWAB_USE_ANA_IN_DIR == STD_ON)
/*******************************************************************************
** Function Name        : IoHwAb_AnaInDirReadDirect                           **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ChIdx                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Value                                               **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                          IoHwAb_GaaAnaInDirInfos,                          **
**                          IoHwAb_GblAnaInAdcIsBusy,                         **
**                          IoHwAb_GucAnaInNumAdcAllGroup                     **
**                        Function(s) invoked    :                            **
**                          Adc_SetupResultBuffer,                            **
**                          Adc_StartGroupConversion,                         **
**                          SchM_Enter_IoHwAb_IoHwAbProtection,               **
**                          SchM_Exit_IoHwAb_IoHwAbProtection,                **
**                          IoHwAb_AnaInDirConvProc,                          **
**                          Det_ReportError,                                  **
**                          Dem_ReportErrorStatus                             **
*******************************************************************************/
FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInDirReadDirect(IoHwAb_IndexType ChIdx,
  P2VAR(IoHwAb_ValueType, AUTOMATIC, IOHWAB_APPL_DATA) Value,
  IoHwAb_LengthType AnaInDirLength)
{
  uint8 LucIdx;
  uint8 LucAdcHwUnitId;
#if !(defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
  uint8 LucAdcHwUnitNum = IoHwAb_GaaAnaInDirInfos[ChIdx].ucAdcHwUnitNum;
#endif
  uint8 LucAdcGroupLength = IoHwAb_GaaAnaInDirInfos[ChIdx].ucAdcGroupLength;
  Std_ReturnType LddError = E_OK;
  IoHwAb_ValueType * LpValue = Value;
  LucAdcHwUnitId = IoHwAb_GaaAnaInDirInfos[ChIdx].ucAdcHwUnitId;
  
  /*  Check if Value is NULL_PTR.  */
  if (LpValue == NULL_PTR)
  {
    #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
      (uint8)IOHWAB_ANAINDIR_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_WRONG_PARAM);
    #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
    #if (IOHWAB_USE_DEM_EVENT == STD_ON)
    Dem_ReportErrorStatus(IOHWAB_E_WRONG_PARAM, DEM_EVENT_STATUS_FAILED);
    #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
    LddError = E_NOT_OK;
  }

  /*  Check if AnaInDirLength is less than LucAdcGroupLength.  */
  if (LddError == E_OK)
  {
    if (AnaInDirLength > LucAdcGroupLength)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
        (uint8)IOHWAB_ANAINDIR_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_WRONG_PARAM);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_WRONG_PARAM, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
      LddError = RTE_E_IoHwAb_If_AnaInDir_E_WRONG_LENGTH;
    }
  }

  /*  Setup result buffer.  */
  if (LddError == E_OK)
  {
    if (Adc_SetupResultBuffer(IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType,
      IoHwAb_GaaAnaInDirAdcResults[LucAdcHwUnitId]) != E_OK)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
        (uint8)IOHWAB_ANAINDIR_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_SETUP_FAIL);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_SETUP_FAIL, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
      LddError = RTE_E_IoHwAb_If_AnaInDir_E_SETUP_BUFFER_FAIL;
    }
  }

  SchM_Enter_IoHwAb_IoHwAbProtection();
  
  /*  Check if Adc busy flag is set.  */
  if (LddError == E_OK)
  {
    if (IoHwAb_GblAnaInAdcIsBusy[LucAdcHwUnitId] == TRUE)
    {
      #if (IOHWAB_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError((uint16)IOHWAB_MODULE_ID, (uint8)IOHWAB_INSTANCE_ID,
        (uint8)IOHWAB_ANAINDIR_READ_DIRECT_SID, (uint8)IOHWAB_E_DET_BUSY);
      #endif /* (IOHWAB_DEV_ERROR_DETECT == STD_ON) */
      #if (IOHWAB_USE_DEM_EVENT == STD_ON)
      Dem_ReportErrorStatus(IOHWAB_E_BUSY, DEM_EVENT_STATUS_FAILED);
      #endif /* (IOHWAB_USE_DEM_EVENT == STD_ON) */
      LddError = RTE_E_IoHwAb_If_AnaInDir_E_BUSY;
    }
    else
    {
      IoHwAb_GblAnaInAdcIsBusy[LucAdcHwUnitId] = (boolean)TRUE;
    }
  }

  SchM_Exit_IoHwAb_IoHwAbProtection();

  if (LddError == E_OK)
  {
    SchM_Enter_IoHwAb_IoHwAbProtection();

    Adc_StartGroupConversion(IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType);
    #if (defined(IOHWAB_MCAL_NXP_S32K14X))
/* polyspace:begin<CERT-C:MSC12-C:Not a defect:Justify with annotations>It depends on the configuration of the group length.*/
/* polyspace-begin DEFECT:DEAD_CODE [Justified:Low] "It depends on the configuration of the group length." */
    if (LucAdcGroupLength > 0U)
    {
      LddError = IoHwAb_AnaInConvCompleted(LucAdcHwUnitNum, (LucAdcGroupLength - 1U));
    }
    else 
    {
      LddError = IoHwAb_AnaInConvCompleted(LucAdcHwUnitNum, 0U);
    }
/* polyspace:end<CERT-C:MSC12-C:Not a defect:Justify with annotations>It depends on the configuration of the group length.*/
/* polyspace-end DEFECT:DEAD_CODE [Justified:Low] "It depends on the configuration of the group length." */
    #elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
    LddError = IoHwAb_AnaInConvCompleted(
    (const Adc_GroupConfigType *) Adc_GetGroupConfig(IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType));
    #else
    LddError = IoHwAb_AnaInConvCompleted(LucAdcHwUnitNum);
    #endif

    #if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB)|| defined(IOHWAB_MCAL_FREESCALE_MPC574XR) ||\
         defined(IOHWAB_MCAL_ST_SPC58XCX)       || defined(IOHWAB_MCAL_ST_SPC58XHX) ||\
         defined(IOHWAB_MCAL_NXP_S32K14X)       || defined(IOHWAB_MCAL_NXP_S32G2X))
    SchM_Exit_IoHwAb_IoHwAbProtection();
    (void)Adc_ReadGroup( IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType, IoHwAb_GaaAnaInDirAdcResults[LucAdcHwUnitId]);
    #else /* Aurix, RH850, Cypress */
      #if (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
      IoHwAb_AdcConvProc(IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType);
      #else
      IoHwAb_AdcConvProc(LucAdcHwUnitNum);
      #endif
      SchM_Exit_IoHwAb_IoHwAbProtection();
      #if (defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX) ||\
           defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
      (void)Adc_ReadGroup(IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType,
                         IoHwAb_GaaAnaInDirAdcResults[LucAdcHwUnitId]);
      #else /* When Aurix, RH850 */
      Adc_StopGroupConversion(IoHwAb_GaaAnaInDirInfos[ChIdx].ddAdcGroupType);
      #endif
    #endif

    for (LucIdx = 0; LucIdx < AnaInDirLength; LucIdx++)
    {
      *LpValue = IoHwAb_GaaAnaInDirAdcResults[LucAdcHwUnitId][LucIdx];
/* polyspace-begin MISRA-C3:17.8 [Justified:Unset] "This function parameter has to be changed for an adc group which has multiple adc channels." */
      LpValue++;
/* polyspace-end MISRA-C3:17.8 [Justified:Unset] "This function parameter has to be changed for an adc group which has multiple adc channels." */
    }

    /*  Clear the Adc busy flag.  */
    SchM_Enter_IoHwAb_IoHwAbProtection();
    IoHwAb_GblAnaInAdcIsBusy[LucAdcHwUnitId] = (boolean)FALSE;
    SchM_Exit_IoHwAb_IoHwAbProtection();
  }

  return LddError;
}
#endif /* (IOHWAB_USE_ANA_IN_DIR == STD_ON) */
/*polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> No Impact of this rule violation*/
/*polyspace-end RTE:UNR*/
/* polyspace-end MISRA-C3:18.1 [Justified:Unset] "Not a defect and validated by test cases" */
#if ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON))
/*******************************************************************************
** Function Name        : IoHwAb_AnaInFirstOrderFiltering                     **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : FiltValue, RawValue, Gain                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : result                                              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : none                       **
**                        Function(s) invoked    : none                       **
*******************************************************************************/
FUNC(uint16, IOHWAB_CODE)IoHwAb_AnaInFirstOrderFiltering(
  uint16 FiltValue, uint16 RawValue, uint8 Gain)
{
  uint16 LusFilteredResult;
  if (FiltValue >= RawValue)
  {
    LusFilteredResult = RawValue + (uint16)((((uint32)FiltValue - (uint32)RawValue) * (uint32)Gain ) >> 8);
  }
  else
  {
    LusFilteredResult = RawValue - (uint16)((((uint32)RawValue - (uint32)FiltValue) * (uint32)Gain ) >> 8);
  }
  return LusFilteredResult;
}
/*polyspace:begin<MISRA-C:11.3:Not a defect:Justify with annotations> No Impact of this rule violation*/
/*polyspace-begin RTE:UNR [Not a Defect] "No Impact of this rule violation"*/
/* polyspace-begin MISRA-C3:18.1 [Justified:Unset] "Not a defect and validated by test cases" */
/*******************************************************************************
** Function Name        : IoHwAb_AnaInConvCompleted                           **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : IoHwAb_AdcHwUnitId                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : IoHwAb_AdcHwUnitNum                                 **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : none                       **
**                        Function(s) invoked    : none                       **
*******************************************************************************/
#if (defined(IOHWAB_MCAL_NXP_S32K14X))
static FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvCompleted(uint8 IoHwAb_AdcHwUnitNum, uint8 IoHwAb_AdcDirLength)
{
  volatile uint16 LulAdcDelayCounter = IoHwAb_GucAdcReadDirectMaxDelay ;
  Std_ReturnType LddError = (Std_ReturnType)E_OK;

  if (IoHwAb_AdcHwUnitNum < 0xFFU)
  {
    while( ( IoHwAb_AdcConvCompleted(IoHwAb_AdcHwUnitNum, IoHwAb_AdcDirLength) == 0U) &&
           ( LulAdcDelayCounter > 0U ) )
    {
      LulAdcDelayCounter--;
    }

    if (LulAdcDelayCounter == 0U)
    {
      LddError = (Std_ReturnType)E_NOT_OK;
    }
  }
  else
  {
    LddError = (Std_ReturnType)E_NOT_OK;
  }
  return LddError;
}
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
/* polyspace-begin MISRA-C3:15.5 [Justified:Unset] "For efficiency and readability." */
static FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvCompleted(const Adc_GroupConfigType * IoHwAb_AdcGroupCfg)
{
  volatile uint16 LulAdcDelayCounter = IoHwAb_GucAdcReadDirectMaxDelay ;
  Std_ReturnType LddError = (Std_ReturnType)E_OK;
  uint32 LulAdcChBaseAddress = 0U;
  
  if (IoHwAb_AdcGroupCfg == NULL_PTR)
  {
    LddError = (Std_ReturnType)E_NOT_OK;
    return LddError;
  }
  
  const Adc_ChannelConfigType * LpAdcChConfig =
    Adc_GetChannelConfig(IoHwAb_AdcGroupCfg->LastLogicalChannelConfigIndex);
  
  LulAdcChBaseAddress = LpAdcChConfig->RegisterBase;

  if (LulAdcChBaseAddress != 0U)
  {
    while( ( IoHwAb_AdcConvCompleted(LulAdcChBaseAddress) == 0U) &&
           ( LulAdcDelayCounter > 0U ) )
    {
      LulAdcDelayCounter--;
    }

    if (LulAdcDelayCounter == 0U)
    {
      LddError = (Std_ReturnType)E_NOT_OK;
    }
  }
  else
  {
    LddError = (Std_ReturnType)E_NOT_OK;
  }
  return LddError;
}
/* polyspace-end MISRA-C3:15.5 [Justified:Unset] "For efficiency and readability." */
#else
static FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_AnaInConvCompleted(uint8 IoHwAb_AdcHwUnitNum)
{
  volatile uint16 LulAdcDelayCounter = IoHwAb_GucAdcReadDirectMaxDelay ;
  Std_ReturnType LddError = (Std_ReturnType)E_OK;

  if (IoHwAb_AdcHwUnitNum < 0xFFU)
  {
    while( ( IoHwAb_AdcConvCompleted(IoHwAb_AdcHwUnitNum) == 0U) &&
           ( LulAdcDelayCounter > 0U ) )
    {
      LulAdcDelayCounter--;
    }

    if (LulAdcDelayCounter == 0U)
    {
      LddError = (Std_ReturnType)E_NOT_OK;
    }
    IoHwAb_AdcAcknowledged(IoHwAb_AdcHwUnitNum);
  }
  else
  {
    LddError = (Std_ReturnType)E_NOT_OK;
  }
  return LddError;
}
#endif

/* polyspace-begin MISRA-C3:11.4 [Justified:Low] "This conversion cannot be modified to access a specific memory location." */
/* polyspace-begin ISO-17961:intptrconv [Justified:Low] "This conversion cannot be modified to access a specific memory location." */
/* polyspace-begin CERT-C:INT36-C [Justified:Low] "This conversion cannot be modified to access a specific memory location." */
/*******************************************************************************
** Function Name        : IoHwAb_AdcConvCompleted                             **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
	  || defined(IOHWAB_MCAL_ST_SPC58XHX) \
	  || defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
	  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
	  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
	  || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) \
	  || defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
	  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM) \
	  || defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX) \
	  || defined(IOHWAB_MCAL_FREESCALE_MPC574XR) || defined(IOHWAB_MCAL_NXP_S32G2X) \
	  || defined(IOHWAB_MCAL_TI_TDA4X) \
	  || defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX) \
	  || defined(IOHWAB_MCAL_NXP_S32K14X))
static inline FUNC(uint32, IOHWAB_CODE)IoHwAb_AdcConvCompleted
#if (defined(IOHWAB_MCAL_NXP_S32K14X))
(uint8 AdcHwUnitNum, uint8 AdcDirLen)
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
(uint32 AdcBaseAddr)
#else
(uint8 AdcHwUnitNum)
#endif
{
  uint32 LulValue = 0;
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX))
  #if (defined(ADC_SW_MAJOR_VERSION_REG) && (ADC_SW_MAJOR_VERSION_REG > 1))
    LulValue = REG_READ32(ADC_ISR_REG(ADC_ADDRESS(AdcHwUnitNum)))&(IOHWAB_ADC_ISR_ECH);
  #else
    LulValue = REG_READ32(ADC_ISR_REG(AdcHwUnitNum))&(IOHWAB_ADC_ISR_ECH);
  #endif
#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
	|| defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X))
  LulValue = ((uint32)(*(volatile uint32*)(IOHWAB_ADC_CONV_BASE_ADDRESS + (0x10u*((uint32)AdcHwUnitNum)))))&(((uint32)1U)<<24);
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413))
  LulValue = ((uint32)(*(volatile uint32*)(0xfff20308UL + (0x1000UL*((uint32)AdcHwUnitNum)))&((uint32)0x0002U)));
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM)) 
  LulValue = (uint32)((*(volatile uint32*)(0xffd6d308UL + (0x1b3000UL*((((uint32)AdcHwUnitNum)+1u)&0x0001u))))&((uint32)0x0002u));
#elif (defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || (defined(IOHWAB_MCAL_CYPRESS_S6J33XX)))
  LulValue = (uint32)( (*(volatile uint32*)(0xB48C0300UL)) + (*(volatile uint32*)(0xB48C0304UL)) );
#elif (defined(IOHWAB_MCAL_FREESCALE_MPC574XR))
  LulValue = REG_READ32(ADCDIG_ISR_REG_ADDR32(AdcHwUnitNum))&(ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
#elif (defined(IOHWAB_MCAL_NXP_S32G2X))
  LulValue = (((uint32)(*(volatile uint32*)((IOHWAB_ADC_ISR_ADDRESS) + (IOHWAB_ADC_HWUNIT_OFFSET*(AdcHwUnitNum)))))&(((uint32)1U)<<0));
#elif (defined(IOHWAB_MCAL_TI_TDA4X))
  LulValue = (((uint32)(*(volatile uint32*)((IOHWAB_ADDRESS_ADC_STATUS_RAW) + (0x10000u*(AdcHwUnitNum)))))&(((uint32)1U)<<1));
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
  LulValue = (uint32)( (*(volatile uint32*)((AdcBaseAddr) + 0x10UL)) );
#elif (defined(IOHWAB_MCAL_NXP_S32K14X))
  LulValue = REG_READ32(ADC12BSARV2_SC1_REG_ADDR32((AdcHwUnitNum), (uint32)AdcDirLen)) & (0x00000080UL);
#else
#endif
  return LulValue;
}
#endif
/*******************************************************************************
** Function Name        : IoHwAb_AdcAcknowledged                              **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX) \
  || defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
  || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM) \
  || defined(IOHWAB_MCAL_FREESCALE_MPC574XR) \
  || defined(IOHWAB_MCAL_NXP_S32G2X) || defined(IOHWAB_MCAL_TI_TDA4X))
static inline FUNC(void, IOHWAB_CODE)IoHwAb_AdcAcknowledged(uint8 AdcHwUnitNum)
{
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || defined(IOHWAB_MCAL_ST_SPC58XCX) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX))
  #if (defined(ADC_SW_MAJOR_VERSION_REG) && (ADC_SW_MAJOR_VERSION_REG > 1))
    REG_WRITE32( ADC_ISR_REG(ADC_ADDRESS(AdcHwUnitNum)),IOHWAB_ADC_ISR_ECH);
  #else
    REG_WRITE32( ADC_ISR_REG(AdcHwUnitNum),IOHWAB_ADC_ISR_ECH);
  #endif
#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
    || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X))
  ((*(volatile uint32*)(IOHWAB_ADC_CONV_BASE_ADDRESS + (0x10u*((uint32)AdcHwUnitNum)))))|=(((uint32)1U)<<25);
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413))
  ((*(volatile uint16*)(IOHWAB_ADC_CONV_BASE_ADDRESS + (0x1186UL*((uint32)AdcHwUnitNum)))))&=( (uint16)0xEFFFu );
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM))
  ((*(volatile uint16*)(IOHWAB_ADC_CONV_BASE_ADDRESS + (0xc786UL*((uint32)AdcHwUnitNum)))))&=( (uint16)0xEFFFu );
#elif (defined(IOHWAB_MCAL_FREESCALE_MPC574XR))
  REG_WRITE32( ADCDIG_ISR_REG_ADDR32(AdcHwUnitNum),ADCDIG_ISR_END_CHANNEL_NORM_CONV_U32);
#elif (defined(IOHWAB_MCAL_NXP_S32K14X))
  (*(volatile uint32*)((ADC12BSARV2_SC1_REG_ADDR32((AdcHwUnitNum), (uint32)0)))) &= (0xFFFFFFFFUL - 0xC0UL);
#elif (defined(IOHWAB_MCAL_NXP_S32G2X))
  #if (ADC_SW_MAJOR_VERSION >= 2)
    IOHWAB_UNUSED8(AdcHwUnitNum);
  #else
    ((*(volatile uint32*)(IOHWAB_ADC_ISR_ADDRESS + (IOHWAB_ADC_HWUNIT_OFFSET*(AdcHwUnitNum)))))|=(((uint32)1U)<<0);
  #endif
#elif (defined(IOHWAB_MCAL_TI_TDA4X))
  ((*(volatile uint32*)(IOHWAB_ADDRESS_ADC_STATUS + (0x10000u*(AdcHwUnitNum)))))|=(((uint32)1U)<<1);
#else
  IOHWAB_UNUSED8(AdcHwUnitNum);
#endif
}
#endif
/* polyspace-end MISRA-C3:11.4 [Justified:Low] "This conversion cannot be modified to access a specific memory location." */
/* polyspace-end ISO-17961:intptrconv [Justified:Low] "This conversion cannot be modified to access a specific memory location." */
/* polyspace-end CERT-C:INT36-C [Justified:Low] "This conversion cannot be modified to access a specific memory location." */
/*******************************************************************************
** Function Name        : IoHwAb_AdcConvProc                                  **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#if (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
  || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
  || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM) \
  || defined(IOHWAB_MCAL_CYPRESS_S6J32XX) || defined(IOHWAB_MCAL_CYPRESS_S6J33XX) \
  || defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX) \
  || defined(IOHWAB_MCAL_TI_TDA4X) )
static inline FUNC(void, IOHWAB_CODE)IoHwAb_AdcConvProc
#if (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
(Adc_GroupType AdcGrp)
#else
(uint8 AdcHwUnitNum)
#endif
{
#if (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
  || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
  || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) )
  Adc_IsrSrn1AdcRS1(AdcHwUnitNum);
#elif (defined(IOHWAB_MCAL_INFINEON_TC38X)) || (defined(IOHWAB_MCAL_INFINEON_TC39X))
  Adc_RS0EventInterruptHandler(AdcHwUnitNum);
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
    || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM))
  Adc_Isr( (uint8)(AdcHwUnitNum), 0U );
#elif (defined(IOHWAB_MCAL_CYPRESS_S6J32XX)) || (defined(IOHWAB_MCAL_CYPRESS_S6J33XX))
  Adc_IsrGroupConversionFinished(AdcHwUnitNum);
#elif (defined(IOHWAB_MCAL_TI_TDA4X))
  Adc_IrqTxRx(&Adc_DrvObj.hwUnitObj[AdcHwUnitNum]);
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
  Adc_IsrGroupConversionFinished((const Adc_GroupConfigType *)Adc_GetGroupConfig(AdcGrp));
#else
#endif
}
#endif
#endif /* ((IOHWAB_USE_ANA_IN == STD_ON) || (IOHWAB_USE_ANA_IN_DIR == STD_ON)) */

#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace-end MISRA-C3:18.1 [Justified:Unset] "Not a defect and validated by test cases" */
/*polyspace:end<MISRA-C:11.3:Not a defect:Justify with annotations> No Impact of this rule violation*/
/*polyspace-end RTE:UNR*/
/* polyspace-end RTE:IDP RTE:NIV [Justified:Low] "Validated by test cases. It works as intended." */
/*polyspace:end<RTE: OBAI: Not a defect : No Action Planned > Array Checked   */
/* polyspace-end RTE:UNR [Not a defect:Unset] "Reachable code" */
/* polyspace-end MISRA-C3:D4.14 MISRA-C3:D4.5 [Justified:Unset] "Not a defect" */
/* polyspace-end MISRA-C3:11.5 [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-end DEFECT:DEAD_CODE [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-end DEFECT:USELESS_IF [Justified:Low] "Validated by test cases. It works as intended." */
/* polyspace-end MISRA-C3:14.3 MISRA-C3:2.1 [Justified:Low] "It depends on the configuration." */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
