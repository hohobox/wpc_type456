/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Obd.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : Provision of OnBoard Diagnostic functionality                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date:DD-MM-YYYY By            Description                         **
********************************************************************************
** 4.0.0   27-Jul-2023   EunKyung Kim   #40946                                **
**                                                                            **
** 3.3.4    31-12-2021    LanhLT         Changes made As per Redmine #33335   **
**                                                                            **
** 3.3.3    19-10-2021    LanhLT         Changes made As per Redmine #31306,  **
**                                       #31128                               **
**                                                                            **
** 1.1.4    18-02-2021    EunKyung.Kim   Changes made As per Redmine #25380   **
**                                                                            **
** 1.1.3    04-09-2020    EunKyung.Kim   Changes made As per Redmine #25254   **
**                                                                            **
** 1.1.2    01-06-2020    EunKyung.Kim    Changes made As per Redmine #20595  **
**                                                                            **    
** 1.1.1    02-04-2019    EunKyung.Kim    Changes made As per Redmine #16687  **
**                                                                            **
** 1.1.0    10-12-2018    EunKyung.Kim    Changes made As per Redmine #8561   **
**                                                                            **
** 1.0.8     16-05-2016     YoungJin.Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.7     11-01-2014     YoungJin.Yun  Changes made As per Redmine #366,   **
**                                        #368,#371,#372,#405,#366,#367,#368, **
**                                        #371,#372,#405,#369,#373,#374,#375, **
**                                        #376,#370,#377,#381,#382,#383,#384, **
**                                        #385,#386,#387,#388,#389,#390,#391, **
**                                        #397,#398,#399,#400,#378,#380,#401, **
**                                        #403,#404,#406,#409,#410,#411,#412  **
**                                        #367,                               **
**                                                                            **
** 1.0.0     01-Jan-2013   Autron      Initial Version                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dem.h"                /* DEM module Header File */
#include "Dem_Ram.h"            /* DEM Ram Header File */
#include "SchM_Dem.h"       /* Basic s/w module Scheduler symbols Header File */
#include "NvM.h"              /* NVRAM manager symbols Header File */
#include "Dem_EventRelatedData.h"
#include "Dem_Event.h"
#include "Dem_EventMemory.h"
#include "Dem_ObdRam.h"
#include "Dem_Dtc.h"

#if (DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                /* Det Header File */
#endif

#if (DEM_FIM_INTEGRATED == STD_ON)
#include "FiM.h"
#endif

/*******************************************************************************
**                           Global Data                                      **
*******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
/* Used to calculate time in sec */
VAR(uint16, DEM_VAR) Dem_GulDemMilOnTimeObdSecCount;

/* Used to calculate time in sec */
VAR(uint16, DEM_VAR) Dem_GulDemClearTimeObdSecCount;
#endif
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

static FUNC(void, DEM_CODE) Dem_ComputeDistanceTraveledData(void);

static FUNC(void, DEM_CODE) Dem_ComputeEngineRunTimeData(void);

#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)Dem_GetFimPermission(
    uint8 RatioIndex,
    boolean* permission );
FUNC(void, DEM_CODE)Dem_GetRatioIndex(
  Dem_EventParameterCPCType event,
  uint32 ArrayIndex,
  P2VAR(uint8, AUTOMATIC,DEM_VAR) RatioId);

/* Trace: DEM_OBD_09_03 */
static FUNC(void, DEM_CODE) Dem_DivideIumprRatioValue(
  VAR(Dem_RatioIdType, DEM_VAR) RatioID);
/* Trace: DEM_OBD_09_04 */
static FUNC(void, DEM_CODE) Dem_CalCulateMinimumRatioPerGroup(
  VAR(uint8, DEM_VAR) IumprGroupID);
/* Trace: DEM_OBD_09_05 */
static FUNC(void, DEM_CODE) Dem_ProcessDen100ms(void);  


/* Trace: DEM_19792_06_03 */
static FUNC(void, DEM_CODE) Dem_ProcessMonitorActivityInhibitConditionCheck(void);  
#endif /*(DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON)*/

#if (DEM_OBD_SUPPORT == STD_ON)
static FUNC(uint8, DEM_CODE) Dem_ObdGetSizeOfPID(  
  VAR(uint8, DEM_VAR) PID,
  VAR(uint8, DEM_VAR) DataElementIndexOfPID);

static FUNC(void, DEM_CODE) Dem_CalcPID41PerGroupCheck(
  VAR(uint32, DEM_VAR) DisableGroupID,
  VAR(uint8, DEM_VAR) OBDReadyGroupID,
  VAR(uint8, DEM_VAR) SupportedEnableGroup,
  VAR(uint8, DEM_VAR) ReadinessCompletenessGroup,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41ByteCAddr,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41ByteDAddr);

static FUNC(void, DEM_CODE) Dem_CalcPID41PerGroup(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue,
  VAR(uint8, DEM_VAR) DisableGroupIndexinPID41,
  VAR(uint8, DEM_VAR) ReadinessGroup,
  VAR(uint8, DEM_VAR) CompletenessIndexinPID41
  );

#endif /*DEM_OBD_SUPPORT == STD_ON*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DTR_Conversion_Linear(
  sint32 Value,
  uint16 Num0,
  uint16 Num1,
  uint16 Denominator0,
  uint16 * CalcResult);

/* polyspace +2 MISRA-C3:20.1 [Justified:Low] "Not a defect" */
#define DEM_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Dem_InitOBD                                         **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Initialize OBD variables                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : Dem_EventIdType EventId                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulEventIdDisabled                              **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
**                        SchM_Exit_Dem_CAPTURE_OBD_DATA()                    **
*******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(void, DEM_CODE) Dem_InitOBD(void)
{
  #if (DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO)
  uint16 LusRatioIdCount;
  uint8 LucGroupRatioCount;
  uint8 LucIdx;
  #endif
  VAR(Dem_EventIdType, DEM_VAR) LddEventId;
  VAR(Dem_CombinedDtcPCType, DEM_VAR) LddCbDTC;
  uint8 LucIndexPrimaryEventMemory;

  /* Initialise the obd event stored in permanent memory to zero */
  Dem_GusEventstoredinPermanent = DEM_ZERO;
  /* Initialise the obd dtc stored to zero */
  Dem_GusObdDtcFirstStored =  DEM_ZERO;
  /* Initialise the obd event store to false */
  Dem_ObdEventStored = DEM_FALSE;
  /* Initialise the  Milli Second Count to zero */
  Dem_GulDemTimeObdmsCount = DEM_ZERO;
  /* Initialise the Second Count to zero */
  Dem_GulDemMilOnTimeObdSecCount = DEM_ZERO;
  /* Initialise the Second Count to zero */
  Dem_GulDemClearTimeObdSecCount = DEM_ZERO;
  /* Initialise the Time since mil is on to zero */
  Dem_GulTimeSinceMilOn = DEM_ZERO;
  /* Initialise the Mil on flag to false */
  Dem_GucMilonFlag = Dem_EventStatusNvRamData.MilonFlag;
  /* Initialise the Pre Mil on flag to false */
  Dem_GucPreMilonFlag = Dem_EventStatusNvRamData.PreMilonFlag;
  /* Initialise the time since clear function is called to false */
  Dem_GulDemClearTimeCount = DEM_ZERO;

  Dem_GblDtcCleared = Dem_EventStatusNvRamData.DtcClear;
  /* Initialise the warmup cycle count to zero */
  Dem_GusWarmUpCycleCount = DEM_ZERO;

  /* Initialise the distance of start engine*/
  Dem_OBDOldDistanceInfo = DEM_ZERO;

  /* Initialise the time of start engine*/
  Dem_OBDOldEngStartInfo = DEM_ZERO;

  Dem_GstRecordDisableDTC.usObdDtc = 0U;

  #if (DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO)
  Dem_GblRatioInit = DEM_FALSE;
  /* Initialise the ignition cycle count to zero */
  Dem_GusIgnitionCylCnt = Dem_EventStatusNvRamData.IgnitionCylCnt;
  /* Initialise the general denominator for infotype08 and infotype0b as zero
   */
  Dem_GusGeneralDenominator = Dem_EventStatusNvRamData.GeneralDenCnt;
  
  for(LusRatioIdCount = DEM_ZERO; LusRatioIdCount < Dem_Num_Ratio_Info; LusRatioIdCount++)
  {
    /* Initialise all the ratioid to disable (release) */
    Dem_GusRatioIdDisable[LusRatioIdCount] = DEM_FALSE;

    Dem_GaaIumprNumeratorIsCounted[LusRatioIdCount] = DEM_FALSE;
    Dem_GaaIumprDenominatorIsCounted[LusRatioIdCount] = DEM_FALSE;
  }

  /* Initialise the numerator and denominator of IUMPR group to zero */
  for(LusRatioIdCount = DEM_ZERO; LusRatioIdCount < DEM_NUMBER_OF_RATIO_INFO; LusRatioIdCount++)
  {
    Dem_GaaIumprDenominator[LusRatioIdCount] = Dem_EventStatusNvRamData.IumprDenominator[LusRatioIdCount];
    Dem_GaaIumprNumerator[LusRatioIdCount] = Dem_EventStatusNvRamData.IumprNumerator[LusRatioIdCount];
    //Dem_GusRatioMonitored[LusRatioIdCount] = DEM_FALSE;   

  }

  for(LucGroupRatioCount = DEM_ZERO; LucGroupRatioCount < DEM_NUM_OF_IUMPR_GROUP; LucGroupRatioCount++)
  {
    Dem_GaaIumprUpdateFlagPerGroup[LucGroupRatioCount] = Dem_EventStatusNvRamData.IumprUpdateFlagPerGroup[LucGroupRatioCount];

    /* If assigned ratio is exist */
    if (Dem_GaaIumprUpdateFlagPerGroup[LucGroupRatioCount] == DEM_TRUE)
    {
      Dem_GaaIumprMinimumRatioIDPerGroup[LucGroupRatioCount] = 
          Dem_EventStatusNvRamData.IumprMinimumRatioIDPerGroup[LucGroupRatioCount];
    }
    /* If ratio is not assigned yet this group, init to Last index which always 0 */
    else 
    {
      Dem_GaaIumprUpdateFlagPerGroup[LucGroupRatioCount] = DEM_FALSE;
      Dem_GaaIumprMinimumRatioIDPerGroup[LucGroupRatioCount] = DEM_NUMBER_OF_RATIO_INFO;
    }
  }

  /* Last Array of Denominator, Numerator is always use to ZERO */
  Dem_GaaIumprDenominator[DEM_NUMBER_OF_RATIO_INFO + DEM_ONE] = DEM_ZERO;
  Dem_GaaIumprNumerator[DEM_NUMBER_OF_RATIO_INFO + DEM_ONE] = DEM_ZERO;

  /*Initialise the Dem_GusRatioDenCondState */
  for (LucIdx = DEM_ZERO; LucIdx < DEM_IUMPR_MAX_CONDITION_NUMBER; LucIdx++)
  {
    /* @Trace: Dem_SUD_API_11692 */    
    Dem_GusRatioDenCondState[LucIdx] = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
  }

  /* Individual denominators to support different conditions than the general denominator*/
  Dem_GusRatioDenCondState[DEM_IUMPR_DEN_NONE] = DEM_IUMPR_DEN_STATUS_REACHED;

  #if (DEM_J1979_2_OBD_ON_UDS == STD_ON)
  /* Trace: DEM_19792_06_05 */
  for (LucIdx = DEM_ZERO; LucIdx < DEM_NUMBER_OF_RATIO_INFO; LucIdx++)
  {
    Dem_GaaMonitorActivityNumerator[LucIdx] = Dem_EventStatusNvRamData.MonitorActivityNumerator[LucIdx];
    Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucIdx] = Dem_EventStatusNvRamData.MonitorActivityNumeratorNeedCountedCycleEnd[LucIdx];
    Dem_GaaMonitorActivityRatio[LucIdx] = Dem_EventStatusNvRamData.MonitorActivityRatio[LucIdx];
    Dem_GaaMonitorActivityDenominator[LucIdx] = Dem_EventStatusNvRamData.MonitorActivityDenominator[LucIdx];  
    Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucIdx] = Dem_EventStatusNvRamData.MonitorActivityDenominatorNeedCountedCycleEnd[LucIdx];
  }
  #endif /* J19792 */

  #endif /* DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO */

  #ifdef DEM_MIL_INDICATORID
  Dem_SetMalfuntionOnOff();
  #endif

  Dem_ObdMemoryId = DEM_NO_EVMEM_ENTRY;

  for (LucIndexPrimaryEventMemory = DEM_ZERO;
       LucIndexPrimaryEventMemory < DEM_MAX_NUMBER_EVENT_ENTRY_PRI;
       LucIndexPrimaryEventMemory++)
  {
    LddEventId = Dem_PrimaryEventMemory[LucIndexPrimaryEventMemory].EventIdRef;
    if (LddEventId != DEM_NO_EVENT)
    {
      LddCbDTC = Dem_GetCbDTCByEventId(LddEventId);
      if (LddCbDTC->usObdDtc != DEM_NO_DTC)
      {
        Dem_ObdMemoryId = Dem_EventStatusNvRamData.ObdMemoryId;
        break;
      }
    }
  }

}
#endif

/*******************************************************************************
** Function Name        : Dem_MainFunctionOBD                                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Interface for BSW Components to report Errors       **
**                        during start up (even before DEM initialization)    **
**                                                                            **
** Timing:              : FIXED_CYCLIC                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
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
**                        Dem_GucInit                                         **
**                        Dem_GblMilStarted                                   **
**                        Dem_GulTimeSinceMilOn                               **
**                        Dem_GulDemTimeObdmsCount                            **
**                        Dem_GucMilonFlag                                    **
**                        Dem_GblClearTimeStartObd                            **
**                        Dem_GulDemClearTimeCount                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(void, DEM_CODE) Dem_MainFunctionOBD(void)
{
  #if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
  static VAR(uint8, DEM_VAR) LucCount100ms = DEM_ZERO;
  #endif /*(DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON)*/

  boolean LblCheckMilOnEdge;
  
  #if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
  if (LucCount100ms >= DEM_TEN)
  {
    Dem_ProcessDen100ms();
    /* Trace: DEM_19792_06_03 */
    Dem_ProcessMonitorActivityInhibitConditionCheck();
    
    LucCount100ms = DEM_ZERO;
  }
  else
  {
    LucCount100ms++;
  }
  #endif /*(DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON)*/

  LblCheckMilOnEdge = DEM_FALSE;
  if ((Dem_GucPreMilonFlag == DEM_ZERO) && (Dem_GucMilonFlag == DEM_BIT7_MASK1))
  {
    LblCheckMilOnEdge = DEM_TRUE;
    Dem_GusWarmUpCycleCount = DEM_ZERO;
  }

  Dem_GucPreMilonFlag = Dem_GucMilonFlag;

  if (Dem_GucMilonFlag != Dem_EventStatusNvRamData.MilonFlag)
  {
    SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
    Dem_EventStatusNvRamData.MilonFlag = Dem_GucMilonFlag;
    Dem_EventStatusNvRamData.PreMilonFlag = Dem_GucPreMilonFlag;
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
    Dem_EvMem_SetNonVolatieDataStatus(
        DEM_NVDATA_ALL_EVENT_STATUS_ID, DEM_EVMEM_STATUS_DIRTY_NVM);
    Dem_EvMem_TriggerWriteAllBlocks(); 
  }

  if ((Dem_GusWarmUpCycleCount >= DEM_FOURTY) || (LblCheckMilOnEdge == DEM_TRUE) || 
      (Dem_GblDtcCleared == DEM_TRUE))
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    Dem_EventStatusNvRamData.DataOfPID21 = DEM_ZERO;
    Dem_EventStatusNvRamData.DataOfPID4D = DEM_ZERO;
    SchM_Exit_Dem_CAPTURE_OBD_DATA();
  }


  Dem_ComputeDistanceTraveledData();
  Dem_ComputeEngineRunTimeData();
#if 0
  /* Start the timer in the obd */
  Dem_GulDemTimeObdmsCount = Dem_GulDemTimeObdmsCount + Dem_Task_Time;

  /* Check that mil flag is set or not */
  if(Dem_GucMilonFlag == DEM_BIT7_MASK1)
  {
    /* Check first time after miloff is Mil flag is set*/
    if(Dem_GblMilStarted == DEM_TRUE)
    {
      /* Reset the Mil On time to zero*/
      Dem_GulTimeSinceMilOn = DEM_ZERO;

      Dem_GulDemMilOnTimeObdSecCount = DEM_ZERO;

      /* Reset the flag */
      Dem_GblMilStarted = FALSE;
    }
  }

  if(Dem_GblClearTimeStartObd == DEM_TRUE)
  {
    /* Check first time after miloff is Mil flag is set*/
    if(Dem_GblDtcCleared == DEM_TRUE)
    {
      /* Reset the Mil On time to zero*/
      Dem_GulDemClearTimeCount = DEM_ZERO;

      Dem_GulDemClearTimeObdSecCount = DEM_ZERO;

      /* Reset the flag */
      Dem_GblDtcCleared = FALSE;
    }
  }
  

  /* Check DemTimeObdmsCount is passed 1000sec */
  if(Dem_GulDemTimeObdmsCount >= DEM_THOUSAND_SEC)
  {
    /* Increment the second by one */
    Dem_GulDemMilOnTimeObdSecCount = Dem_GulDemMilOnTimeObdSecCount + DEM_ONE;
    Dem_GulDemClearTimeObdSecCount = Dem_GulDemClearTimeObdSecCount + DEM_ONE;

    /* Reset the milli second to zero */
    Dem_GulDemTimeObdmsCount = DEM_ZERO;

    /* Check 60sec is passed  */
    if(Dem_GulDemMilOnTimeObdSecCount >= DEM_SIXTY_SEC)
    {
      /* Check that mil flag is set or not */
      if(Dem_GucMilonFlag == DEM_BIT7_MASK1)
      {
        /* Increment the mil on count by one */
        Dem_GulTimeSinceMilOn = Dem_GulTimeSinceMilOn + DEM_ONE;
        Dem_EventStatusNvRamData.TimeSinceMilOn = Dem_GulTimeSinceMilOn;
      }

      /* Reset the second count to zero */
      Dem_GulDemMilOnTimeObdSecCount = DEM_ZERO;
    }

    /* Check 60sec is passed  */
    if(Dem_GulDemClearTimeObdSecCount >= DEM_SIXTY_SEC)
    {

      /* Check that Dem_ClearDtc function is called */
      if(Dem_GblClearTimeStartObd == DEM_TRUE)
      {
       /* Increment the count of Dem_ClearDtc is called by one */
       Dem_GulDemClearTimeCount = Dem_GulDemClearTimeCount + DEM_ONE;
       Dem_EventStatusNvRamData.TimeSinceLastClear = Dem_GulDemClearTimeCount;
      }
      /* Reset the second count to zero */
      Dem_GulDemClearTimeObdSecCount = DEM_ZERO;
    }
  }
#endif

}
#endif


/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
/*******************************************************************************
** Function Name        : Dem_SetEventDisabled                                **
**                                                                            **
** Service ID           : 0x51                                                **
**                                                                            **
** Description          : Service for reporting the event as disabled to      **
**                        the Dem for the PID $41 computation                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : EventId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulEventIdDisabled                              **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled(Dem_EventIdType EventId)
{
  /* EventId Index */
  Dem_EventIdType LddEventParameterIndex;
  Std_ReturnType LddReturnValue;
  uint32 LulReadinessGroup;

  /* Get the Event Parameter Index */
  LddEventParameterIndex = EventId - DEM_ONE;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
    DEM_SETEVENTDISABLED_SID, DEM_E_UNINIT);

    /* Return appropriate value */
    LddReturnValue = E_NOT_OK;
  }
  else if((EventId > Dem_Number_Of_Events) || (DEM_ZERO == EventId))
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_SETEVENTDISABLED_SID, DEM_E_PARAM_CONFIG);

    /* Return appropriate value */
    LddReturnValue = E_NOT_OK;
  }
  else
  #endif
  {
    LulReadinessGroup =
      Dem_Event[LddEventParameterIndex].ulEventOBDReadinessGroup;

    SchM_Enter_Dem_CAPTURE_OBD_DATA();

    switch(LulReadinessGroup)
    {
      case DEM_OBD_RDY_MISF:
           {
            /* Disable the event with masking 0x01 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_MISF;
           }
      break;

      case DEM_OBD_RDY_FLSYS:
           {
            /* Disable the event with masking 0x02 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_FLSYS;
           }
      break;

      case DEM_OBD_RDY_CMPRCMPT:
           {
            /* Disable the event with masking 0x04 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_CMPRCMPT;
           }
      break;

      case DEM_OBD_RDY_CAT:
           {
            /* Disable the event with masking 0x08 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_CAT;
           }
      break;

      case DEM_OBD_RDY_HTCAT:
           {
            /* Disable the event with masking 0x10 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_HTCAT;
           }
      break;

      case DEM_OBD_RDY_EVAP:
           {
            /* Disable the event with masking 0x20 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_EVAP;
           }
      break;

      case DEM_OBD_RDY_SECAIR:
           {
            /* Disable the event with masking 0x40 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_SECAIR;
           }
      break;

      case DEM_OBD_RDY_O2SENS:
           {
            /* Disable the event with masking 0x80 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_O2SENS;
           }
      break;

      case DEM_OBD_RDY_O2SENSHT:
           {
            /* Disable the event with masking 0x100 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_O2SENSHT;
           }
      break;

      case DEM_OBD_RDY_EGR:
           {
            /* Disable the event with masking 0x200 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_EGR;
           }
      break;

      case DEM_OBD_RDY_HCCAT:
           {
            /* Disable the event with masking 0x400 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_HCCAT;
           }
      break;

      case DEM_OBD_RDY_NOXCAT:
           {
            /* Disable the event with masking 0x800 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_NOXCAT;
           }
      break;

      case DEM_OBD_RDY_BOOSTPR:
           {
            /* Disable the event with masking 0x1000 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_BOOSTPR;
           }
      break;

      case DEM_OBD_RDY_EGSENS:
           {
            /* Disable the event with masking 0x2000 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_EGSENS;
           }
      break;

      case DEM_OBD_RDY_PMFLT:
           {
            /* Disable the event with masking 0x4000 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_PMFLT;
           }
      break;

      case DEM_OBD_RDY_AC:
           {
            /* Disable the event with masking 0x8000 */
            Dem_GulEventIdDisabled = Dem_GulEventIdDisabled | DEM_OBD_RDY_DISABLE_AC;
           }
      break;
      default:
      break;
    }
    SchM_Exit_Dem_CAPTURE_OBD_DATA();

    LddReturnValue = E_OK;
  }
  /* Return E_OK or E_NOT_OK */
  return(LddReturnValue);
}
#endif

/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID01                              **
**                                                                            **
** Service ID           : 0x61                                                **
**                                                                            **
** Description          : Service to report the value of PID 01 for Dem       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID01value                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulPid01Value                                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError, Dem_CalcPIDValue                   **
*******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01Value)
{

  /* @Trace: SWS_Dem_00293
   * For the following PIDs the data layout shall be compliant to SAE J1979DA
   * [18].
   * - PID $41 monitor status this driving cycle (4 byte)
   * - PID $01 monitor status since DTCs cleared (4 byte)
   * - PID $02 DTC that caused required freeze frame storage (2 byte)
   * - PID $1C OBD requirements to which vehicle or engine is certified (1 byte)
   * - PID $21 distance traveled while MIL is activated (2 byte)
   * - PID $30 number of warm-ups (WUC) since DTCs cleared (1 byte)
   * - PID $31 distance traveled since DTCs cleared (2 byte)
   * - PID $41 monitor status this driving cycle (4 byte)
   * - PID $4D engine run time while MIL is activated (2 byte)
   * - PID $4E engine run time since DTCs cleared (2 byte)
   * - PID $91 ECU OBD System Information (5 byte)
*/
   
  Std_ReturnType LddReturnValue;
  #if(DEM_MAX_NUMBER_EVENT_ENTRY_PER > DEM_ZERO)
  uint8 LaaPid01data[DEM_FOUR];
  Dem_EventIdType LusEventCount;
  Dem_EventIdType LusConfirmedDtcCount;
  uint8 LucByteCount;
  #endif

  LddReturnValue = E_OK;
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
     /* Error report to DET */
      (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
        DEM_DCMREADDATAOFPID01_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID01Value)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID01_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    #if(DEM_MAX_NUMBER_EVENT_ENTRY_PER > DEM_ZERO)

    /* Initialise the event count to zero */
    LusEventCount = DEM_ZERO;
    LusConfirmedDtcCount = DEM_ZERO;
    /* Loop to find that number of events whose confirmed bit is set */
    while(LusEventCount < Dem_Number_Of_Events)
    {
      Dem_EventIdType EventId = LusEventCount + 1u;
      Dem_UdsStatusByteType EventStatusMask = 0u;
      
      EventStatusMask = Dem_AllEventStatusByte[EventId];
      /* Check if confirmedDtc bit is set or not */
      if((DEM_BIT3_MASK1 == (EventStatusMask & DEM_BIT3_MASK1)) &&
        (DEM_TRUE == Dem_EvMem_DTCFormatIsValid(DEM_DTC_FORMAT_OBD, 
          &Dem_GaaCombinedDtc[Dem_Event[LusEventCount].e_PointToDTC]))
        )
      {
        /* confirmedDtcCount is incremented by 1 */
        LusConfirmedDtcCount = LusConfirmedDtcCount + DEM_ONE;
      }
      /* Increment the count by 1 */
      LusEventCount++;
    }
    /* Check LusConfirmedDtcCountcount is greater than zero or not */
    if(LusConfirmedDtcCount > DEM_ZERO)
    {
      /* Store the bit0 to bit6 of byteA with 0x7f*/
      /* Byte A (0-6): number of DTCs stored in this ECU */
      LaaPid01data[DEM_OBD_RDY_BYTE_A] = (uint8)(LusConfirmedDtcCount & DEM_BIT7_MASK2);

      /* update the bit7 to byteA */
      /* Byte A (7): Malfunction Indicator Lamp (MIL) Status */
      LaaPid01data[DEM_OBD_RDY_BYTE_A] = LaaPid01data[DEM_OBD_RDY_BYTE_A] | Dem_GucMilonFlag;
    }
    else
    {
      /* Update the byteA of pid01 with 0 as there is no confirmed dtc */
      LaaPid01data[DEM_OBD_RDY_BYTE_A] = DEM_ZERO;
    }

    /* PID01 ByteB lowernibble */
    LaaPid01data[DEM_OBD_RDY_BYTE_B] = DEM_PID01_ByteB_Lower_Nibble &
      DEM_MASK_LOWER_NIBBLE;

    /* Check Misfire is supported or not */
    #if((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_0_SUPPORTED_ENABLE_MISF) == DEM_OBD_RDY_BYTEB_0_SUPPORTED_ENABLE_MISF)
    {
      /* Calculate Byte-2 Bit4 value*/
      Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_B], 
        DEM_OBD_RDY_BYTEB_4_COMPLETENESS_READINESS_MISF, DEM_OBD_RDY_MISF);  

    }
    #else
    {
      /* Misfire not supported then bit4 of byteB is set to 0 */
      LaaPid01data[DEM_OBD_RDY_BYTE_B] = (LaaPid01data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_4_COMPLETENESS_READINESS_MISF);
    }
    #endif

    /* Check Fuel system is supported or not */
    #if((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_1_SUPPORTED_ENABLE_FLSYS) == DEM_OBD_RDY_BYTEB_1_SUPPORTED_ENABLE_FLSYS)
    {
      /* Calculate Byte-2 Bit5 value*/
      Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_B], 
        DEM_OBD_RDY_BYTEB_5_COMPLETENESS_READINESS_FLSYS, DEM_OBD_RDY_FLSYS);  
    }
    #else
    {
      /* Fuel system not supported then bit5 is set of byteB to 0 */
      LaaPid01data[DEM_OBD_RDY_BYTE_B] = (LaaPid01data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_5_COMPLETENESS_READINESS_FLSYS);
    }
    #endif

    /* Check Comprehensive component is supported or not */
    #if((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_2_SUPPORTED_ENABLE_CMPRCMPT) == DEM_OBD_RDY_BYTEB_2_SUPPORTED_ENABLE_CMPRCMPT)
    {
      /* Calculate Byte-2 Bit6 value*/
      Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_B], 
        DEM_OBD_RDY_BYTEB_6_COMPLETENESS_READINESS_CMPRCMPT, DEM_OBD_RDY_CMPRCMPT);   
    }
    #else
    {
      /* Comprehensive component not supported then bit6 of byteB is set to 0*/
      LaaPid01data[DEM_OBD_RDY_BYTE_B] = LaaPid01data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_6_COMPLETENESS_READINESS_CMPRCMPT;
    }
    #endif

    /* bit7 of byteB is set to 0 as it is ISO/SAE reserved */
    LaaPid01data[DEM_OBD_RDY_BYTE_B] = LaaPid01data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_7_COMPLETENESS_READINESS_RESERVED;

    /* Check for the engine is spark */
    #if((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_3_COMPRESSION_SPARK_IGNITION) == DEM_ZERO)
    {
      /* PID01 ByteC */
      LaaPid01data[DEM_OBD_RDY_BYTE_C] = DemM_PID01_ByteC_Spark;

      /* Check Catalyst monitoring is supported or not */
      #if((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_0_SPARK_SUPPORTED_ENABLED_CAT) == DEM_OBD_RDY_BYTEC_0_SPARK_SUPPORTED_ENABLED_CAT)
      {
        /* Calculate Byte-3 Bit-1 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_0_SPARK_COMPLETENESS_READINESS_CAT, DEM_OBD_RDY_CAT);  
      }
      #else
      {
        /*  Catalyst monitoring not supported then bit0 of byteD is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_0_SPARK_COMPLETENESS_READINESS_CAT);
      }
      #endif

      /* Check Heated Catalyst monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_1_SPARK_SUPPORTED_ENABLED_HTCAT) == DEM_OBD_RDY_BYTEC_1_SPARK_SUPPORTED_ENABLED_HTCAT)
      {
        /* Calculate Byte-3 Bit-2 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_1_SPARK_COMPLETENESS_READINESS_HTCAT, DEM_OBD_RDY_HTCAT);   
      }
      #else
      {
        /* Heated Catalyst monitoring not supported then bit1 of byteD is set to
         0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_1_SPARK_COMPLETENESS_READINESS_HTCAT);
      }
      #endif

      /* Check Evaporative system monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_2_SPARK_SUPPORTED_ENABLED_EVAP) == DEM_OBD_RDY_BYTEC_2_SPARK_SUPPORTED_ENABLED_EVAP)
      {
        /* Calculate Byte-3 Bit-2 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
           DEM_OBD_RDY_BYTED_2_SPARK_COMPLETENESS_READINESS_EVAP, DEM_OBD_RDY_EVAP);    
      }
      #else
      {
        /*  Evaporative system monitoring not supported then bit2 of byteD is
          set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] =  (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_2_SPARK_COMPLETENESS_READINESS_EVAP);
      }
      #endif

      /* Check Secondary air system monitoring is supported or not */
       #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_3_SPARK_SUPPORTED_ENABLED_SECAIR) == DEM_OBD_RDY_BYTEC_3_SPARK_SUPPORTED_ENABLED_SECAIR)
      {
        /* Calculate Byte-3 Bit-3 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_3_SPARK_COMPLETENESS_READINESS_SECAIR, DEM_OBD_RDY_SECAIR);
      }
      #else
      {
        /*  Secondary air system monitoring not supported then bit3 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_3_SPARK_COMPLETENESS_READINESS_SECAIR);
      }
      #endif

      /*  As per ISO 0 is set to 0 */
      LaaPid01data[DEM_OBD_RDY_BYTE_C] = (LaaPid01data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_4_SUPPORTED_ENABLED_RESERVED);
      /* As per ISO 0 is set to 0 */
      LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_4_COMPLETENESS_READINESS_RESERVED);

      /* Check Oxygen sensor monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_5_SPARK_SUPPORTED_ENABLED_O2SENS) == DEM_OBD_RDY_BYTEC_5_SPARK_SUPPORTED_ENABLED_O2SENS)
      {
        /* Calculate Byte-3 Bit-5 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_5_SPARK_COMPLETENESS_READINESS_O2SENS, DEM_OBD_RDY_O2SENS); 
      }
      #else
      {
        /* Oxygen sensor monitoring not supported then bit5 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_5_SPARK_COMPLETENESS_READINESS_O2SENS);
      }
      #endif
      /* Check Oxygen sensor heater monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_6_SPARK_SUPPORTED_ENABLED_O2SENSHT) == DEM_OBD_RDY_BYTEC_6_SPARK_SUPPORTED_ENABLED_O2SENSHT)
      {
        /* Calculate Byte-3 Bit-6 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_6_SPARK_COMPLETENESS_READINESS_O2SENSHT, DEM_OBD_RDY_O2SENSHT);   
      }
      #else
      {
        /* Oxygen sensor heater monitoring not supported then bit6 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_6_SPARK_COMPLETENESS_READINESS_O2SENSHT);
      }
      #endif

      /* Check EGR system monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR) == DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR)
      {
        /* Calculate Byte-3 Bit-7 value*/
      /* Trace: DEM_OBD_01_03 */
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_7_SPARK_COMPLETENESS_READINESS_EGR, DEM_OBD_RDY_EGR);  

      }
      #else
      {
        /* EGR system monitoring not supported then bit6 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_7_SPARK_COMPLETENESS_READINESS_EGR);
      }
      #endif

    } /* Check for the engine is spark */
    #else
    {
      /* PID01 ByteC If compression engine */
      LaaPid01data[DEM_OBD_RDY_BYTE_C] = Dem_PID01_ByteC_Compression;

      /* Check NMHC catalyst monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_0_COMPRESSION_SUPPORTED_ENABLED_HCCAT) == DEM_OBD_RDY_BYTEC_0_COMPRESSION_SUPPORTED_ENABLED_HCCAT)
      {
        /* Calculate Byte-3 Bit-0 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_0_COMPRESSION_COMPLETENESS_READINESS_HCCAT, DEM_OBD_RDY_HCCAT);  
      }
      #else
      {
        /* @Trace: Dem_SUD_API_12566 */
        /* NMHC Catalyst monitoring not supported then bit0 of byteD is set to 0
         */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_0_COMPRESSION_COMPLETENESS_READINESS_HCCAT);
      }
      #endif

      /* Check NOx aftertreatment system monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_1_COMPRESSION_SUPPORTED_ENABLED_NOXCAT) == DEM_OBD_RDY_BYTEC_1_COMPRESSION_SUPPORTED_ENABLED_NOXCAT)
      {
        /* Calculate Byte-3 Bit-1 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_1_COMPRESSION_COMPLETENESS_READINESS_NOXCAT, DEM_OBD_RDY_NOXCAT);  
      }
      #else
      {
        /*  NOx aftertreatment system monitoring not supported then bit1 of
            byteD is set to 0
         */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_1_COMPRESSION_COMPLETENESS_READINESS_NOXCAT);
      }
      #endif

      /* Set Bit2 of byteD to zero */
      LaaPid01data[DEM_OBD_RDY_BYTE_D] = LaaPid01data[DEM_OBD_RDY_BYTE_D] & DEM_BIT2_MASK2;

      /* Check Boost pressure system monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_3_COMPRESSION_SUPPORTED_ENABLED_BOOSTPR) == DEM_OBD_RDY_BYTEC_3_COMPRESSION_SUPPORTED_ENABLED_BOOSTPR)
      {
        /* Calculate Byte-3 Bit-3 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_3_COMPRESSION_COMPLETENESS_READINESS_BOOSTPR, DEM_OBD_RDY_BOOSTPR);      
      }
      #else
      {
        /* Boost pressure system monitoring not supported then bit3 of byteD
           is set to 0
         */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_3_COMPRESSION_COMPLETENESS_READINESS_BOOSTPR);
      }
      #endif

      /* Set Bit4 of byteD to zero */
      LaaPid01data[DEM_OBD_RDY_BYTE_D] = LaaPid01data[DEM_OBD_RDY_BYTE_D] & DEM_BIT4_MASK2;

      /* Check Exhaust gas sensor monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_5_COMPRESSION_SUPPORTED_ENABLED_EGSENS) == DEM_OBD_RDY_BYTEC_5_COMPRESSION_SUPPORTED_ENABLED_EGSENS)
      {
        /* Calculate Byte-3 Bit- value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_5_COMPRESSION_COMPLETENESS_READINESS_EGSENS, DEM_OBD_RDY_EGSENS);
      }
      #else
      {
        /* @Trace: Dem_SUD_API_12573 */
        /* Exhaust gas sensor not supported then bit5 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_5_COMPRESSION_COMPLETENESS_READINESS_EGSENS);
      }
      #endif

      /* Check PM filter monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_6_COMPRESSION_SUPPORTED_ENABLED_PMFLT) == DEM_OBD_RDY_BYTEC_6_COMPRESSION_SUPPORTED_ENABLED_PMFLT)
      {
        /* Calculate Byte-3 Bit-6 value*/
        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_6_COMPRESSION_COMPLETENESS_READINESS_PMFLT, DEM_OBD_RDY_PMFLT);  
      }
      #else
      {
        /* PM filter monitoring not supported then bit6 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_6_COMPRESSION_COMPLETENESS_READINESS_PMFLT);
      }
      #endif

      /* Check EGR system monitoring is supported or not */
      #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR) == DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR)
      {
        /* Calculate Byte-3 Bit-7 value*/

        Dem_CalcReadinessPIDValue(DEM_PID01_CALC, &LaaPid01data[DEM_OBD_RDY_BYTE_D], 
          DEM_OBD_RDY_BYTED_7_SPARK_COMPLETENESS_READINESS_EGR, DEM_OBD_RDY_EGR);  
      }
      #else
      {
        /* EGR system monitoring not supported then bit6 of byteD
          is set to 0 */
        LaaPid01data[DEM_OBD_RDY_BYTE_D] = (LaaPid01data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_7_SPARK_COMPLETENESS_READINESS_EGR);
      }
      #endif

    }
    #endif

    /* Initialise  the count value to zero */
    LucByteCount = DEM_ZERO;

    /* Loop for giving the data */
   while (LucByteCount < DEM_FOUR)
   {
     /* Output data into destination buffer */
     PID01Value[LucByteCount] = LaaPid01data[LucByteCount];

     LucByteCount++;
   }
   #else
   /*No event is present in primary memory */
    *PID01Value = DEM_ZERO;
   #endif

  }/*Det check */
  return(LddReturnValue);
}
#endif
/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID21                              **
**                                                                            **
** Service ID           : 0x64                                                **
**                                                                            **
** Description          : Service to report the value of PID 21 for Dem       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID21value                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GaaPid, Dem_GulTimeSinceMilOn                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError, Dem_GetReadDataOfPID                     **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21Value)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID21_SID, DEM_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  else if(NULL_PTR == PID21Value)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID21_SID, DEM_E_PARAM_POINTER);
    LddReturnValue = E_NOT_OK;
  }
  else
  #endif
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    PID21Value[DEM_ZERO] = (uint8)(Dem_EventStatusNvRamData.DataOfPID21 & 0x00FFU);
    PID21Value[DEM_ONE]  = (uint8)((Dem_EventStatusNvRamData.DataOfPID21 & 0xFF00U) >> DEM_EIGHT);
    SchM_Exit_Dem_CAPTURE_OBD_DATA();
  }

  return (LddReturnValue);
}

static FUNC(void, DEM_CODE) Dem_ComputeDistanceTraveledData(void)
{
  /* PID $21 : Distance Traveled while MiL is active
    condition for "Distance Traveled" couter:
      - reset to $0000 when MIL state changes from deactivated to activated;
      - accumulate counts in km if MIL is activated (ON);
      - do not change value while MIL is not activated (OFF);
      - reset to $0000 if diagnostic information is cleared either by service $04 or at least 40 warm-up
        cycles without MIL activated;
      - do not wrap to $0000 if value is $FFFF.
  */

  /*  PID $31 : Distance Traveled since DTC cleared
      CLR_DIST shall remain at 65535 km and not wrap to zero
  */

  uint16 LusTempPid21Data;
  uint16 LusTempPid31Data;

  Std_ReturnType LddTravelDisStatus;
  uint32 LulnewDistanceInfo;
  uint32 LulTravelDistance;

  P2CONST(Dem_DataElementClassType, AUTOMATIC, DEM_CONST) LpElement = NULL_PTR;

  LusTempPid21Data = Dem_EventStatusNvRamData.DataOfPID21;
  LusTempPid31Data = Dem_EventStatusNvRamData.DataOfPID31;
  LulnewDistanceInfo = DEM_ZERO;
  LddTravelDisStatus = E_NOT_OK;
  LulTravelDistance = DEM_ZERO;

  /* DemOBDInputVehicleSpeed only referece to DemExternalCSDataElementClass
    because DemExternalSRDataElementClass is not supported*/
  LpElement = Dem_GstGeneralOBDInfo[DEM_ZERO].pOBDInputDistanceInformation;

  if (NULL_PTR != LpElement)
  {
    if (NULL_PTR != LpElement->ReadFunc)
    {
      LddTravelDisStatus = LpElement->ReadFunc((uint8*) &LulnewDistanceInfo);
    }
  }
  
  if (LddTravelDisStatus == E_OK)
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    if (Dem_OBDOldDistanceInfo < LulnewDistanceInfo)
    {
      LulTravelDistance = LulnewDistanceInfo - Dem_OBDOldDistanceInfo;
      Dem_OBDOldDistanceInfo = LulnewDistanceInfo;

      /* Distance travelled while MIL is activated */
      if ((Dem_GucMilonFlag == DEM_BIT7_MASK1))
      {
        LusTempPid21Data = LusTempPid21Data + (uint16)LulTravelDistance;
        Dem_EventStatusNvRamData.DataOfPID21 = LusTempPid21Data;
      }

      if (DEM_TRUE == Dem_GblDtcCleared)
      {
        if ((LusTempPid31Data + LulTravelDistance) > DEM_MAX_DISTANCE_SINCE_DTCS_CLEARED)
        {
          LusTempPid31Data = DEM_MAX_DISTANCE_SINCE_DTCS_CLEARED;
        }
        else
        {
          LusTempPid31Data = LusTempPid31Data +  (uint16)LulTravelDistance;
        }

        Dem_EventStatusNvRamData.DataOfPID31 = LusTempPid31Data;
      }
    }
    SchM_Exit_Dem_CAPTURE_OBD_DATA();

  }

}

#endif
/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID30                              **
**                                                                            **
** Service ID           : 0x65                                                **
**                                                                            **
** Description          : Service to report the value of PID 30 for Dem       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID30value                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Function(s) invoked :                               **
**                        Det_ReportError                     **
**                        SchM_Exit_Dem_CAPTURE_OBD_DATA                      **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30Value)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
     /* Error report to DET */
      (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
        DEM_DCMREADDATAOFPID30_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID30Value)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID30_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /* Check count is not maximum */
    if(Dem_EventStatusNvRamData.NumOfWUCSinceLC < DEM_MAX_WARM_UP_COUNT)
    {
      /* Store the LSB byte */
      *PID30Value = Dem_EventStatusNvRamData.NumOfWUCSinceLC;

    }
    else
    {
      *PID30Value = DEM_MAX_WARM_UP_COUNT;
    }

  }
  return(LddReturnValue);
}
#endif
/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID31                              **
**                                                                            **
** Service ID           : 0x66                                                **
**                                                                            **
** Description          : Service to report the value of PID 31 for Dem       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID31value                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):Dem_GulDemClearTimeCount,        **
**                        Dem_GaaPid                                          **
**                        Function(s) invoked :                               **
**                        Det_ReportError, Dem_GetReadDataOfPID               **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31Value)
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
   /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID31_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID31Value)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID31_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    PID31Value[DEM_ZERO] = (uint8)(Dem_EventStatusNvRamData.DataOfPID31 & 0x00FFU);
    PID31Value[DEM_ONE]  = (uint8)((Dem_EventStatusNvRamData.DataOfPID31 & 0xFF00U) >> DEM_EIGHT);
    SchM_Exit_Dem_CAPTURE_OBD_DATA();
  }

  return(E_OK);
}
#endif
/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID41                              **
**                                                                            **
** Service ID           : 0x67                                                **
**                                                                            **
** Description          : Service to report the value of PID 41 for Dem       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID41value                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError, Dem_GetReadDataOfPID                     **
**                        SchM_Exit_Dem_CAPTURE_OBD_DATA                      **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41(
 P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41Value)
{
  Std_ReturnType LddReturnValue;
  uint8 LaaPid41data[DEM_FOUR];
  uint8 LucByteCount;

  LddReturnValue = E_OK;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID41_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID41Value)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID41_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /* Set byte1 of Pid41 to Zero as per SAEJ1979 */
    LaaPid41data[DEM_ZERO] = DEM_ZERO;

    /* Initialize local variables to zero */
    LaaPid41data[DEM_ONE] = DEM_ZERO;
    LaaPid41data[DEM_TWO] = DEM_ZERO;
    LaaPid41data[DEM_THREE] = DEM_ZERO;

    /* Check that event is disabled for Misfire monitoring or it is not
     * supported.
     */
    #if ((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_0_SUPPORTED_ENABLE_MISF) != DEM_OBD_RDY_BYTEB_0_SUPPORTED_ENABLE_MISF)
    /* Bit0, Bit4 of byte-2 are set to 0 WITH MASK 0XEE*/
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_0_SUPPORTED_ENABLE_MISF);
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_4_COMPLETENESS_READINESS_MISF);
    #else
    Dem_CalcPID41PerGroup(
      &LaaPid41data[DEM_OBD_RDY_BYTE_B], 
      DEM_OBD_RDY_DISABLE_MISF, 
      DEM_OBD_RDY_MISF, 
      DEM_OBD_RDY_BYTEB_4_COMPLETENESS_READINESS_MISF);
    #endif

    /* Check that event is disabled for Fuel system monitoring */
    #if ((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_1_SUPPORTED_ENABLE_FLSYS) != DEM_OBD_RDY_BYTEB_1_SUPPORTED_ENABLE_FLSYS)
    {
      /* Bit1, Bit5 of byte-2 are set to 0 */
      LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_1_SUPPORTED_ENABLE_FLSYS);
      LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_5_COMPLETENESS_READINESS_FLSYS);
    }
    #else
    Dem_CalcPID41PerGroup(&LaaPid41data[DEM_OBD_RDY_BYTE_B], 
      DEM_OBD_RDY_DISABLE_FLSYS, 
      DEM_OBD_RDY_FLSYS, 
      DEM_OBD_RDY_BYTEB_5_COMPLETENESS_READINESS_FLSYS);
    #endif

    /* Check that event is disabled for Comprehensive component monitoring */
    #if ((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_2_SUPPORTED_ENABLE_CMPRCMPT) != DEM_OBD_RDY_BYTEB_2_SUPPORTED_ENABLE_CMPRCMPT)
    /* Bit-2, Bit-6 of byte-2 are set to 0 */
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_2_SUPPORTED_ENABLE_CMPRCMPT);
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_6_COMPLETENESS_READINESS_CMPRCMPT);
    #else
    Dem_CalcPID41PerGroup(
      &LaaPid41data[DEM_OBD_RDY_BYTE_B], 
      DEM_OBD_RDY_DISABLE_CMPRCMPT, 
      DEM_OBD_RDY_CMPRCMPT, 
      DEM_OBD_RDY_BYTEB_6_COMPLETENESS_READINESS_CMPRCMPT);
    #endif

    /* Check Compression ignition monitoring supported*/
    #if ((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_3_COMPRESSION_SPARK_IGNITION) == DEM_OBD_RDY_BYTEB_3_COMPRESSION_SPARK_IGNITION)
    /* Bit3 of byte2 is set to 0 if Spark ignition monitors supported */
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] | ~DEM_OBD_RDY_BYTEB_3_COMPRESSION_SPARK_IGNITION);
    #else
    /* Bit3 of byte2 is set to 0 if Spark ignition monitors supported */
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = LaaPid41data[DEM_OBD_RDY_BYTE_B] & (~DEM_OBD_RDY_BYTEB_3_COMPRESSION_SPARK_IGNITION);
    #endif

    /* Set bit7 is set of byte2 to 0 as it is ISO reserved */
    LaaPid41data[DEM_OBD_RDY_BYTE_B] = (LaaPid41data[DEM_OBD_RDY_BYTE_B] & ~DEM_OBD_RDY_BYTEB_7_COMPLETENESS_READINESS_RESERVED);

    /* For spark engines*/
    #if ((DEM_PID01_BYTEB_LOWER_NIBBLE & DEM_OBD_RDY_BYTEB_3_COMPRESSION_SPARK_IGNITION) == DEM_ZERO)
    /* Check Catalyst monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_0_SPARK_SUPPORTED_ENABLED_CAT) == \
                                  DEM_OBD_RDY_BYTEC_0_SPARK_SUPPORTED_ENABLED_CAT)  
      Dem_CalcPID41PerGroupCheck(
        DEM_OBD_RDY_DISABLE_CAT,
        DEM_OBD_RDY_CAT,
        DEM_OBD_RDY_BYTEC_0_SPARK_SUPPORTED_ENABLED_CAT,
        DEM_OBD_RDY_BYTED_0_SPARK_COMPLETENESS_READINESS_CAT,
        &LaaPid41data[DEM_OBD_RDY_BYTE_C],
        &LaaPid41data[DEM_OBD_RDY_BYTE_D]
      );
    #else
    /*  monitoring disabled */
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_0_SPARK_SUPPORTED_ENABLED_CAT); 
    #endif

    /* Check Heated Catalyst monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_1_SPARK_SUPPORTED_ENABLED_HTCAT) == \
                                DEM_OBD_RDY_BYTEC_1_SPARK_SUPPORTED_ENABLED_HTCAT)  
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_HTCAT,
      DEM_OBD_RDY_HTCAT,
      DEM_OBD_RDY_BYTEC_1_SPARK_SUPPORTED_ENABLED_HTCAT,
      DEM_OBD_RDY_BYTED_1_SPARK_COMPLETENESS_READINESS_HTCAT,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_1_SPARK_SUPPORTED_ENABLED_HTCAT);  
    #endif

    /* Check Evaporative system monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_2_SPARK_SUPPORTED_ENABLED_EVAP) == \
                                DEM_OBD_RDY_BYTEC_2_SPARK_SUPPORTED_ENABLED_EVAP)
    {
      Dem_CalcPID41PerGroupCheck(
        DEM_OBD_RDY_DISABLE_EVAP,
        DEM_OBD_RDY_EVAP,
        DEM_OBD_RDY_BYTEC_2_SPARK_SUPPORTED_ENABLED_EVAP,
        DEM_OBD_RDY_BYTED_2_SPARK_COMPLETENESS_READINESS_EVAP,
        &LaaPid41data[DEM_OBD_RDY_BYTE_C],
        &LaaPid41data[DEM_OBD_RDY_BYTE_D]
      );
    }
    #else
    {
      /*  Evaporative system monitoring not supported then bit2 of byteD is
        set to 0 */
      LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_2_SPARK_SUPPORTED_ENABLED_EVAP);
    }
    #endif


    /* Check Secondary air system monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_3_SPARK_SUPPORTED_ENABLED_SECAIR) == \
                                  DEM_OBD_RDY_BYTEC_3_SPARK_SUPPORTED_ENABLED_SECAIR)  
      Dem_CalcPID41PerGroupCheck(
        DEM_OBD_RDY_DISABLE_SECAIR,
        DEM_OBD_RDY_SECAIR,
        DEM_OBD_RDY_BYTEC_3_SPARK_SUPPORTED_ENABLED_SECAIR,
        DEM_OBD_RDY_BYTED_3_SPARK_COMPLETENESS_READINESS_SECAIR,
        &LaaPid41data[DEM_OBD_RDY_BYTE_C],
        &LaaPid41data[DEM_OBD_RDY_BYTE_D]
      );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_3_SPARK_SUPPORTED_ENABLED_SECAIR);
    #endif

    /*  As per ISO 0 is set to 0 */
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_4_SUPPORTED_ENABLED_RESERVED);
    /* As per ISO 0 is set to 0 */
    LaaPid41data[DEM_OBD_RDY_BYTE_D] = (LaaPid41data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_4_COMPLETENESS_READINESS_RESERVED);

    /* Check Oxygen sensor monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_5_SPARK_SUPPORTED_ENABLED_O2SENS) == \
                                  DEM_OBD_RDY_BYTEC_5_SPARK_SUPPORTED_ENABLED_O2SENS)  
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_O2SENS,
      DEM_OBD_RDY_O2SENS,
      DEM_OBD_RDY_BYTEC_5_SPARK_SUPPORTED_ENABLED_O2SENS,
      DEM_OBD_RDY_BYTED_5_SPARK_COMPLETENESS_READINESS_O2SENS,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_5_SPARK_SUPPORTED_ENABLED_O2SENS);
    #endif

    /* Check Oxygen sensor heater monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_6_SPARK_SUPPORTED_ENABLED_O2SENSHT) == \
                                  DEM_OBD_RDY_BYTEC_6_SPARK_SUPPORTED_ENABLED_O2SENSHT)  
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_O2SENSHT,
      DEM_OBD_RDY_O2SENSHT,
      DEM_OBD_RDY_BYTEC_6_SPARK_SUPPORTED_ENABLED_O2SENSHT,
      DEM_OBD_RDY_BYTED_6_SPARK_COMPLETENESS_READINESS_O2SENSHT,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_6_SPARK_SUPPORTED_ENABLED_O2SENSHT);
    #endif

    /* Check EGR system monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_SPARK & DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR) == \
                                  DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR)  
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_EGR,
      DEM_OBD_RDY_EGR,
      DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR,
      DEM_OBD_RDY_BYTED_7_SPARK_COMPLETENESS_READINESS_EGR,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR);  
    #endif

    #else /* Spark Ignition End */
    /* For Compression engines*/

    /* Check NMHC Catalyst monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_0_COMPRESSION_SUPPORTED_ENABLED_HCCAT) == \
                                  DEM_OBD_RDY_BYTEC_0_COMPRESSION_SUPPORTED_ENABLED_HCCAT)
    Dem_CalcPID41PerGroupCheck(
        DEM_OBD_RDY_DISABLE_HCCAT,
        DEM_OBD_RDY_HCCAT,
        DEM_OBD_RDY_BYTEC_0_COMPRESSION_SUPPORTED_ENABLED_HCCAT,
        DEM_OBD_RDY_BYTED_0_SPARK_COMPLETENESS_READINESS_CAT,
        &LaaPid41data[DEM_OBD_RDY_BYTE_C],
        &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_0_COMPRESSION_SUPPORTED_ENABLED_HCCAT);   
    #endif

    /* Check NOx aftertreatment monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_1_COMPRESSION_SUPPORTED_ENABLED_NOXCAT) == \
                                  DEM_OBD_RDY_BYTEC_1_COMPRESSION_SUPPORTED_ENABLED_NOXCAT)
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_NOXCAT,
      DEM_OBD_RDY_NOXCAT,
      DEM_OBD_RDY_BYTEC_1_COMPRESSION_SUPPORTED_ENABLED_NOXCAT,
      DEM_OBD_RDY_BYTED_1_COMPRESSION_COMPLETENESS_READINESS_NOXCAT,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_1_COMPRESSION_SUPPORTED_ENABLED_NOXCAT); 
    #endif

    /* Check Boost pressure system monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_3_COMPRESSION_SUPPORTED_ENABLED_BOOSTPR) == \
                                  DEM_OBD_RDY_BYTEC_3_COMPRESSION_SUPPORTED_ENABLED_BOOSTPR)
    Dem_CalcPID41PerGroupCheck(
        DEM_OBD_RDY_DISABLE_BOOSTPR,
        DEM_OBD_RDY_BOOSTPR,
        DEM_OBD_RDY_BYTEC_3_COMPRESSION_SUPPORTED_ENABLED_BOOSTPR,
        DEM_OBD_RDY_BYTED_3_COMPRESSION_COMPLETENESS_READINESS_BOOSTPR,
        &LaaPid41data[DEM_OBD_RDY_BYTE_C],
        &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_3_COMPRESSION_SUPPORTED_ENABLED_BOOSTPR);     
    #endif

    /*  As per ISO 0 is set to 0 */
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_4_SUPPORTED_ENABLED_RESERVED);
    /* As per ISO 0 is set to 0 */
    LaaPid41data[DEM_OBD_RDY_BYTE_D] = (LaaPid41data[DEM_OBD_RDY_BYTE_D] & ~DEM_OBD_RDY_BYTED_4_COMPLETENESS_READINESS_RESERVED);

    /* Check Exhaust gas sensor monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_5_COMPRESSION_SUPPORTED_ENABLED_EGSENS) == \
                                  DEM_OBD_RDY_BYTEC_5_COMPRESSION_SUPPORTED_ENABLED_EGSENS)
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_EGSENS,
      DEM_OBD_RDY_EGSENS,
      DEM_OBD_RDY_BYTEC_5_COMPRESSION_SUPPORTED_ENABLED_EGSENS,
      DEM_OBD_RDY_BYTED_5_COMPRESSION_COMPLETENESS_READINESS_EGSENS,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_5_COMPRESSION_SUPPORTED_ENABLED_EGSENS);
    #endif

    /* Check PM filter monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_6_COMPRESSION_SUPPORTED_ENABLED_PMFLT) == \
                                  DEM_OBD_RDY_BYTEC_6_COMPRESSION_SUPPORTED_ENABLED_PMFLT)
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_PMFLT,
      DEM_OBD_RDY_PMFLT,
      DEM_OBD_RDY_BYTEC_6_COMPRESSION_SUPPORTED_ENABLED_PMFLT,
      DEM_OBD_RDY_BYTED_6_COMPRESSION_COMPLETENESS_READINESS_PMFLT,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_6_COMPRESSION_SUPPORTED_ENABLED_PMFLT);   
    #endif

    /* Check PM filter monitoring is supported or not */
    #if ((DEM_PID01_BYTEC_COMPRESSION & DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR) == \
                                  DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR)
    Dem_CalcPID41PerGroupCheck(
      DEM_OBD_RDY_DISABLE_EGR,
      DEM_OBD_RDY_EGR,
      DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR,
      DEM_OBD_RDY_BYTED_7_SPARK_COMPLETENESS_READINESS_EGR,
      &LaaPid41data[DEM_OBD_RDY_BYTE_C],
      &LaaPid41data[DEM_OBD_RDY_BYTE_D]
    );
    #else
    LaaPid41data[DEM_OBD_RDY_BYTE_C] = (LaaPid41data[DEM_OBD_RDY_BYTE_C] & ~DEM_OBD_RDY_BYTEC_7_SPARK_SUPPORTED_ENABLED_EGR);   
    #endif

    #endif /* Compression Ignition End */

    /* Initialise  the count value to zero */
    LucByteCount = DEM_ZERO;

    /* Loop for giving the data */
    while (LucByteCount < DEM_FOUR)
    {
      /* Output data into destination buffer */
      PID41Value[LucByteCount] = LaaPid41data[LucByteCount];

      LucByteCount++;
    }

  }/* Det check */
  
  return(LddReturnValue);
}
#endif
/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID4D                              **
**                                                                            **
** Service ID           : 0x68                                                **
**                                                                            **
** Description          : Service to report the value of PID  4D for Dem      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID4Dvalue                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulTimeSinceMilOn                               **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4DValue)
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
   /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID4D_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID4DValue)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID4D_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    PID4DValue[DEM_ZERO] = (uint8)(Dem_EventStatusNvRamData.DataOfPID4D & 0x00FFU);
    PID4DValue[DEM_ONE]  = (uint8)((Dem_EventStatusNvRamData.DataOfPID4D & 0xFF00U) >> DEM_EIGHT);
    SchM_Exit_Dem_CAPTURE_OBD_DATA();
  }

  return(E_OK);
}

static FUNC(void, DEM_CODE) Dem_ComputeEngineRunTimeData(void)
{

  /* PID $4D: Engine run time while MIL is activated
    - reset to $0000 when MIL state changes from deactivated to activated by this ECU;
    - accumulate counts in minutes if MIL is activated (ON);
    - do not change value while MIL is not activated (OFF);
    - reset to $0000 if diagnostic information is cleared either by service $04 or at least 40 warm-up cycles without MIL activated;
    - do not wrap to $0000 if value is $FFFF.
  */

  /* PID $4E: Engine run time since DTCs cleared
    - Engine run time accumulated since DTCs were cleared
    - If greater than 65535 min has occurred, CLR_TIME shall remain at 65535 min and not wrap to zero.
  */
  Std_ReturnType LddTimeEngStartStatus;
  uint16 LusTempPid4DData;
  uint16 LusTempPid4EData;
  uint32 LulNewEngStartInfo;
  uint32 LulGapEngStartInfo;
  P2CONST(Dem_DataElementClassType, AUTOMATIC, DEM_CONST) LpElement = NULL_PTR;

  LddTimeEngStartStatus = E_NOT_OK;
  LulNewEngStartInfo = DEM_ZERO;
  LulGapEngStartInfo = DEM_ZERO;
  LusTempPid4DData = Dem_EventStatusNvRamData.DataOfPID4D;
  LusTempPid4EData = Dem_EventStatusNvRamData.DataOfPID4E;

  /* DemOBDInputVehicleSpeed should be referece to DemExternalCSDataElementClass */
  LpElement = Dem_GstGeneralOBDInfo[DEM_ZERO].pOBDTimeSinceEngineStart;

  if (NULL_PTR != LpElement)
  {
    if (NULL_PTR != LpElement->ReadFunc)
    {
      LddTimeEngStartStatus = LpElement->ReadFunc((uint8*) &LulNewEngStartInfo);
    }
  }

  if (LddTimeEngStartStatus == E_OK)
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    if (Dem_OBDOldEngStartInfo < LulNewEngStartInfo)
    {
      LulGapEngStartInfo = LulNewEngStartInfo - Dem_OBDOldEngStartInfo;
      Dem_OBDOldEngStartInfo = LulNewEngStartInfo;

      if (Dem_GucMilonFlag == DEM_BIT7_MASK1)
      {
        LusTempPid4DData = LusTempPid4DData + (uint16)LulGapEngStartInfo;
        Dem_EventStatusNvRamData.DataOfPID4D = LusTempPid4DData;
      }

      if (DEM_TRUE == Dem_GblDtcCleared)
      {
        if ((LusTempPid4EData + LulGapEngStartInfo) > DEM_MAX_ENGINE_START_TIME_SINCE_DTCS_CLEARED)
        {
          LusTempPid4EData = DEM_MAX_ENGINE_START_TIME_SINCE_DTCS_CLEARED;
        }
        else 
        {
          LusTempPid4EData = LusTempPid4EData + (uint16)LulGapEngStartInfo;
        }

        Dem_EventStatusNvRamData.DataOfPID4E = LusTempPid4EData;
      }
    }
    SchM_Exit_Dem_CAPTURE_OBD_DATA();
  }
}

#endif

/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID4E                              **
**                                                                            **
** Service ID           : 0x69                                                **
**                                                                            **
** Description          : Service to report the value of PID  4E for Dem      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID4Dvalue                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulDemClearTimeCount                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
**                        SchM_Exit_Dem_CAPTURE_OBD_DATA                      **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E(
 P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4EValue)
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID4E_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID4EValue)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID4E_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    SchM_Enter_Dem_CAPTURE_OBD_DATA();
    PID4EValue[DEM_ZERO] = (uint8)(Dem_EventStatusNvRamData.DataOfPID4E & 0x00FFU);
    PID4EValue[DEM_ONE]  = (uint8)((Dem_EventStatusNvRamData.DataOfPID4E & 0xFF00U) >> DEM_EIGHT);
    SchM_Exit_Dem_CAPTURE_OBD_DATA();
  }
  return(E_OK);
}
#endif

/*******************************************************************************
** Function Name        : Dem_DcmReadDataOfPID1C                              **
**                                                                            **
** Service ID           : 0x63                                                **
**                                                                            **
** Description          : Service to report the value of PID  1C for Dem      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PID1Cvalue                                          **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulPid1CValue                                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
**                                                                            **
*******************************************************************************/
/* Check if DEM_OBD_SUPPORT == STD_ON */
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C(
 P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1CValue)
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
     /* Error report to DET */
      (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
        DEM_DCMREADDATAOFPID1C_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PID1CValue)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID1C_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /* update the pid1cvalue with OBD compliance */
    *PID1CValue = DEM_OBD_COMPLIANCE;
  }
  return(E_OK);
}
#endif

/*******************************************************************************
** Function Name        : Dem_ReadDataOfTimeEngineStart                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Service to report the value of time since engine    **
**                        starts for Dem                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PIDValue                                            **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulPid1CValue                                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfTimeEngineStart(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
   /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID31_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == PIDValue)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_DCMREADDATAOFPID31_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /* MISRA Rule : 10.1
     * Message : Implicit conversion from unsigned long to double.
     * Reason : The result will never be greater than unsigned long
     * Verification : However, part of the code is verified
     * manually and it is not having any impact.
     */
     
    P2CONST(Dem_DataElementClassType, AUTOMATIC, DEM_CONST)
     elementClass = Dem_GstGeneralOBDInfo->pOBDTimeSinceEngineStart;


    if (NULL_PTR != elementClass->ReadFunc)
    {
      elementClass->ReadFunc(PIDValue);

    }
    else
    {
       /* Km with DTC clear is set to zero if speed is not found  */
      *PIDValue = (uint8)DEM_ZERO;

       /*
        * MISRA Rule        : 17.4
        * Message           : Increment or decrement operation performed
        *                     on pointer.
        * Reason            : Increment operator is used to achieve better
        *                     throughput.
        * Verification      : However, part of the code is verified manually
                              and it is not having any impact
        */
        PIDValue++;

      /* Km with DTC clear is set to zero if speed is not found  */
      *PIDValue = (uint8)DEM_ZERO;
    }

  }
  return(LddReturnValue);
}
#endif


  /*******************************************************************************
  ** Function Name        : Dem_DcmGetOBDFreezeFrameData                        **
  **                                                                            **
  ** Service ID           : 0x52                                                **
  **                                                                            **
  ** Description          : This function shall be used to copy a specific      **
  **                        FreezeFrame selected via the associated PID number  **
  **                                                                            **
  ** Sync/Async           : Synchronous                                         **
  **                                                                            **
  ** Re-entrancy          : Non-Reentrant                                       **
  **                                                                            **
  ** Input Parameters     : PID                                                 **
  **                                                                            **
  ** InOut parameter      : BufSize                                             **
  **                                                                            **
  ** Output Parameters    : uint8 *DestBuffer,                                  **
  **                                                                            **
  ** Return parameter     : Std_Returntype                                      **
  **                                                                            **
  ** Preconditions        : None                                                **
  **                                                                            **
  ** Remarks              : Global Variable(s)  :                               **
  **                        Dem_GulEventIdDisabled                              **
  **                                                                            **
  **                        Function(s) invoked :                               **
  **                        Det_ReportError                                     **
  *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
/* @IF_REQ : Dem_ReturnGetFreezeFrameDataByRecordType should be changed to 
          Std_ReturnType in future. */
FUNC(Dem_ReturnGetFreezeFrameDataByRecordType, DEM_CODE)
Dem_DcmGetOBDFreezeFrameData(
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_VAR) DTC,
  P2VAR(uint8, AUTOMATIC, DEM_VAR)DestBuffer,
  P2VAR(uint8, AUTOMATIC, DEM_VAR)BufSize)
{
  Std_ReturnType result = E_NOT_OK;
  Dem_ReturnGetFreezeFrameDataByRecordType retVal = DEM_GET_FFBYRECORD_WRONG_RECORD;
  
  Dem_SizeOfOBDFreezeFrameDataType size = 0U;
  Dem_EventMemoryEntryPtrType entry = NULL_PTR; 
  Dem_EventParameterCPCType event = NULL_PTR;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == DestBuffer)
  {
    DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_POINTER);
  }
  else if(NULL_PTR == BufSize)
  {
    DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_POINTER);
  }
  else if(NULL_PTR == DTC)
  {
    DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_POINTER);
  }
  else 
  #endif
  {
    #if(DEM_MAX_NUMBER_OF_PID_RECDS == 0U)
    DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_CONFIG);
    #else
    /*@IF_REQ : Find obd event.*/
    /* Get the Primary memory address */
    entry = &Dem_PrimaryEventMemory[DEM_ZERO];

    result = Dem_GetSizeOfOBDFreezeFrameData(event, DEM_TRUE, 0U, &size);
    if (E_NOT_OK == result)
    {
      /*No OBD Freeze Frame configured */   
      DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_CONFIG);
    }
    else if (0U == size)
    {
      /*No OBD Freeze Frame configured */
      DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_CONFIG);
    }
    else if(*BufSize < size)
    {  
      /* Target buff size is too small. */
      DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_LENGTH);
    }
    else
    {
      /* @IF_REQ : FIND OBD EVENT ENTRY !!! */      
      /* Retrieve  a OBD freeze frame data */
      result = Dem_GetReadDataOfPID(entry,DestBuffer,DEM_TRUE, 0U, DEM_TRUE, 0U);
      if (E_NOT_OK == result)
      {
        DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_LENGTH);
      }
      else 
      {
        result = Dem_GetEventDTC(event,DTC, DEM_DTC_FORMAT_OBD);
        if (E_NOT_OK == result)
        {
          DEM_REPORT_ERROR(DEM_GETOBDFREEZEFRAMEDATA_SID, DEM_E_PARAM_LENGTH);
        }
        else 
        {
           *BufSize = size;
           retVal = DEM_GET_FFBYRECORD_OK;
        }
      }
    }
    #endif /*DEM_MAX_NUMBER_OF_PID_RECDS == 0U*/
  }

  return retVal;

}
#endif


/*******************************************************************************
** Function Name        : Dem_ReadDataOfOBDFreezeFrame                        **
**                                                                            **
** Service ID           : 0x52                                                **
**                                                                            **
** Description          : This function shall be used to copy a specific      **
**                        FreezeFrame selected via the associated PID number  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : PID                                                 **
**                                                                            **
** InOut parameter      : BufSize                                             **
**                                                                            **
** Output Parameters    : uint8 *DestBuffer,                                  **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GulEventIdDisabled                              **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_ReadDataOfOBDFreezeFrame(
  uint8 PID,
  uint8 DataElementIndexOfPID, 
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)DestBuffer,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)BufSize)
{
  Std_ReturnType retVal = E_NOT_OK;
  P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_DATA) entry;
  Std_ReturnType result = E_NOT_OK;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    DEM_REPORT_ERROR(DEM_READDATAOFOBDFREEZEFRAME_SID, DEM_E_UNINIT);
  }
  else if(NULL_PTR == DestBuffer)
  {
    DEM_REPORT_ERROR(DEM_READDATAOFOBDFREEZEFRAME_SID, DEM_E_PARAM_POINTER);
  }
  else if(NULL_PTR == BufSize)
  {
    DEM_REPORT_ERROR(DEM_READDATAOFOBDFREEZEFRAME_SID, DEM_E_PARAM_POINTER);
  }
  else if(DataElementIndexOfPID > Dem_Max_Number_Of_Pid_DataElement)
  {
    DEM_REPORT_ERROR(DEM_READDATAOFOBDFREEZEFRAME_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  {
    #if(DEM_MAX_NUMBER_OF_PID_RECDS == 0U)
    DEM_REPORT_ERROR(DEM_READDATAOFOBDFREEZEFRAME_SID, DEM_E_PARAM_CONFIG);
    #else
    Dem_SizeOfOBDFreezeFrameDataType size = 0U;
    
    /* Get the Primary memory address */
    /* @IF_REQ:  DO NOT ACCESS VARIABLE, USE FUNCTION */
    if ((DEM_NO_EVMEM_ENTRY != Dem_ObdMemoryId) &&
          (DEM_MAX_NUMBER_EVENT_ENTRY_PRI > Dem_ObdMemoryId))
    {
      entry = &Dem_PrimaryEventMemory[Dem_ObdMemoryId];
    }

    size = Dem_ObdGetSizeOfPID(PID, DataElementIndexOfPID);
    if(*BufSize < size)
    {  
      DEM_REPORT_ERROR(DEM_GETFREEZEFRAMEDATABYDTC_SID,
                        DEM_E_PARAM_LENGTH);
    }
    else
    {
      /* @IF_REQ : FIND OBD EVENT ENTRY !!! */
    
      /* @IF_REQ: DTC Format should be verified by 
      Dem_VerifyRecordNumberOfFreezeFrame in future */
      result = Dem_GetReadDataOfPID(entry,DestBuffer,
                          DEM_FALSE, PID, 
                          DEM_FALSE, DataElementIndexOfPID);

      if (E_OK == result)
      {
        *BufSize = size;
        retVal = E_OK;
      }
    } 
    #endif
  }
  return retVal;
}
#endif
/*******************************************************************************
** Function Name        : Dem_RepIUMPRFaultDetect                             **
**                                                                            **
** Service ID           : 0x73                                                **
**                                                                            **
** Description          : Service for reporting that faults are possibly found**
**                        because all conditions are fulfilled.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : RatioID                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GaaRatioIdInfo                                  **
**                        Dem_Event                                           **
**                        Dem_GaaIumprNumerator                               **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect(Dem_RatioIdType RatioID)
{
  uint8 LucIumprGroupId;
  boolean permission, dirty = DEM_FALSE;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
    DEM_REPIUMPRFAULTDETECT_SID, DEM_E_UNINIT);
  }
  else if(RatioID > Dem_Num_Ratio_Info)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_REPIUMPRFAULTDETECT_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  {
    if ((DEM_RATIO_API == Dem_GaaRatioIdInfo[RatioID].ucRatioIdType)
        /* && (Dem_GusRatioIdDisable[RatioID] == DEM_FALSE)*/)
    {
      Dem_GetFimPermission(RatioID, &permission);

      if(permission == DEM_TRUE)
      {
        Dem_UdsStatusByteType EventStatusMask = 0u;
        Dem_OperationCycleStateType CycleState = (Dem_OperationCycleStateType)DEM_CYCLE_STATE_END;
        
        EventStatusMask = Dem_AllEventStatusByte[Dem_GaaRatioIdInfo[RatioID].rid_EventId];
        (void)Dem_GetOpCycleStateByEvent(Dem_GaaRatioIdInfo[RatioID].rid_EventId, &CycleState);

        if ((CycleState == DEM_CYCLE_STATE_START) && ((EventStatusMask & DEM_UDS_STATUS_PDTC) != DEM_UDS_STATUS_PDTC))
        {
          /* Get the group id for a particular ratioid */
          LucIumprGroupId = Dem_GaaRatioIdInfo[RatioID].ucIUMPRGroup;

          if (Dem_GaaIumprNumeratorIsCounted[RatioID] == DEM_FALSE)
          {
            /*In IUMPR, if either the numerator or denominator for a specific
            *component reaches the maximum value of 65535, both numbers shall
            *be divided by two before either is incremented again to avoid
            *overflow problems
            */
            if(Dem_GaaIumprNumerator[RatioID] == DEM_MAX_DENOMINATOR_NUMERATOR_VALUE)
            {
              Dem_DivideIumprRatioValue(RatioID);
            }
          
            /* Increment the numerator for the requested group */
            Dem_GaaIumprNumerator[RatioID]++;
            Dem_GaaIumprNumeratorIsCounted[RatioID] = DEM_TRUE;
            Dem_CalCulateMinimumRatioPerGroup(LucIumprGroupId);
              
            SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
            Dem_EventStatusNvRamData.IumprNumerator[RatioID] = Dem_GaaIumprNumerator[RatioID];
            Dem_EventStatusNvRamData.IumprDenominator[RatioID] = Dem_GaaIumprDenominator[RatioID];
            Dem_EventStatusNvRamData.IumprMinimumRatioIDPerGroup[LucIumprGroupId] = Dem_GaaIumprMinimumRatioIDPerGroup[LucIumprGroupId];
            Dem_EventStatusNvRamData.IumprUpdateFlagPerGroup[LucIumprGroupId] = Dem_GaaIumprUpdateFlagPerGroup[LucIumprGroupId];
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
           
            dirty = DEM_TRUE;
          }
        }
      }
    }

  }/* Det check */

  if(dirty == DEM_TRUE)
  {
    Dem_EvMem_SetNonVolatieDataStatus(DEM_NVDATA_ALL_EVENT_STATUS_ID, DEM_EVMEM_STATUS_DIRTY_NVM);
    Dem_EvMem_TriggerWriteAllBlocks(); 
  }
  
  /* E_OK report of IUMPR result was successfully reported */
  return (E_OK);
}
#endif
/*******************************************************************************
** Function Name        : Dem_RepIUMPRDenLock                                 **
**                                                                            **
** Service ID           : 0x71                                                **
**                                                                            **
** Description          : Service is used to lock a denominator of a specific **
**                        monitor.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RatioID                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GusRatioIdDisable                               **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock(Dem_RatioIdType RatioID)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_NOT_OK;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_REPIUMPRDENLOCK_SID, DEM_E_UNINIT);

  }
  else if(RatioID > Dem_Num_Ratio_Info)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_REPIUMPRDENLOCK_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  {
    /* Refer Dem_RepIUMPRDenRelease */
    if (Dem_GaaRatioIdInfo[RatioID].ucIUMPRDenGroup == DEM_IUMPR_DEN_PHYS_API)
    {
      Dem_GusRatioDenCondState[DEM_IUMPR_DEN_PHYS_API] = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
      LddReturnValue = E_OK;
    }
 
  }/* Det check */

  return(LddReturnValue);
}
#endif
/*******************************************************************************
** Function Name        : Dem_RepIUMPRDenRelease                              **
**                                                                            **
** Service ID           : 0x72                                                **
**                                                                            **
** Description          : This Service is used to release a denominator of a  **
**                        specific monitor                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RatioID                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GusRatioIdDisable                               **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease(Dem_RatioIdType RatioID)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_NOT_OK;
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_REPIUMPRDENRELEASE_SID, DEM_E_UNINIT);
  }
  else if(RatioID > Dem_Num_Ratio_Info)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_REPIUMPRDENRELEASE_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  {
    /* if DemIUMPRDenGroup set to DEM_IUMPR_DEN_PHYS_API: Additional physical condition (component activity) computed within
       the SW-C and reported via Dem_RepIUMPRDenRelease.
    */
    if (Dem_GaaRatioIdInfo[RatioID].ucIUMPRDenGroup == DEM_IUMPR_DEN_PHYS_API)
    {
      Dem_GusRatioDenCondState[DEM_IUMPR_DEN_PHYS_API] = DEM_IUMPR_DEN_STATUS_REACHED;
      LddReturnValue = E_OK;
    }

  } /* Det check */

  return(LddReturnValue);
}
#endif

/*******************************************************************************
** Function Name        : Dem_SetIUMPRDenCondition                            **
**                                                                            **
** Service ID           : 0xae                                                **
**                                                                            **
** Description          : This Service is used to set condition of denominator**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ConditionID                                         **
**                        ConditionStatus                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GusRatioIdDisable                               **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition(
  Dem_IumprDenomCondIdType ConditionId,
  Dem_IumprDenomCondStatusType CondidtionStatus)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_NOT_OK;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_SETIUMPRDENCONDITION_SID, DEM_E_UNINIT);
  }
  else if(ConditionId > DEM_IUMPR_MAX_CONDITION_NUMBER)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_SETIUMPRDENCONDITION_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  {
    if(ConditionId < DEM_IUMPR_MAX_CONDITION_NUMBER)
    {
      Dem_GusRatioDenCondState[ConditionId] = CondidtionStatus;
      LddReturnValue = E_OK;
    }

  } /* Det check */

  return(LddReturnValue);
}
#endif

/*******************************************************************************
** Function Name        : Dem_GetIUMPRDenCondition                            **
**                                                                            **
** Service ID           : 0xaf                                                **
**                                                                            **
** Description          : This Service is used to get condition of denominator**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ConditionID                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : ConditionStatus                                     **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GusRatioIdDisable                               **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition(
  Dem_IumprDenomCondIdType ConditionId,
  Dem_IumprDenomCondStatusType* CondidtionStatus)
{
  /* The Dem shall provide an API Dem_GetIUMPRDenCondition to give a software
   * component the possibility to get the General Denominator status information.
   * The Dem shall provide the API Dem_GetIUMPRDenCondition
   * to read out the status of a particular condition.
   * */
  VAR(Std_ReturnType, DEM_VAR) LddReturnValue;

  LddReturnValue = E_NOT_OK;
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETIUMPRDENCONDITION_SID, DEM_E_UNINIT);
  }
  else if(ConditionId > DEM_IUMPR_MAX_CONDITION_NUMBER)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETIUMPRDENCONDITION_SID, DEM_E_PARAM_CONFIG);
  }
  else if (CondidtionStatus == NULL_PTR)
  {
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETIUMPRDENCONDITION_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  {
    *CondidtionStatus = Dem_GusRatioDenCondState[ConditionId];
    LddReturnValue = E_OK;
  }

  return LddReturnValue;
}
#endif

/*******************************************************************************
** Function Name        : Dem_GetInfoTypeValue08                              **
**                                                                            **
** Service ID           : 0x6b                                                **
**                                                                            **
** Description          : This Service is used to request for IUMPR data      **
**                        according InfoType 08.                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Iumprdata08                                         **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GaaIumprDenominator                             **
**                        Dem_GusGeneralDenominator                           **
**                        Dem_GusIgnitionCylCnt                               **
**                        Dem_GaaIumprNumerator                               **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_NUMBER_OF_RATIO_INFO > 0U))
FUNC(Std_ReturnType, DEM_CODE) Dem_GetInfoTypeValue08(
  Dcm_OpStatusType OpStatus, uint8* Iumprdata08)
{
  uint8 LucIndex;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_UNINIT);
  }
  else if(DCM_INITIAL != OpStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_PARAM_CONFIG);
  }
  else if(NULL_PTR == Iumprdata08)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /*In R40 version, Iumprdata08: buffer containing the contents of InfoType $08.*/
    LucIndex = DEM_ZERO;

    /* OBD Monitoring Conditions Encountered Counts */
    Iumprdata08[/*0*/LucIndex++] = (uint8)(Dem_GusGeneralDenominator >> DEM_EIGHT);
    Iumprdata08[/*1*/LucIndex++] = (uint8)Dem_GusGeneralDenominator;

    /* Ignition Cycle Counter */
    Iumprdata08[/*2*/LucIndex++] = (uint8)(Dem_GusIgnitionCylCnt >> DEM_EIGHT);
    Iumprdata08[/*3*/LucIndex++] = (uint8)Dem_GusIgnitionCylCnt;

    /* Catalyst Monitor Completion Counts Bank 1 (Numerator) */
    Iumprdata08[/*4*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ONE]] >> DEM_EIGHT);
    Iumprdata08[/*5*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ONE]]);
    /* Catalyst Monitor Conditions Encountered Counts Bank 1 (Denominator) */
    Iumprdata08[/*6*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ONE]] >> DEM_EIGHT);
    Iumprdata08[/*7*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ONE]]);

    /* Catalyst Monitor Completion Counts Bank 2 (Numerator) */
    Iumprdata08[/*8*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TWO]] >> DEM_EIGHT);
    Iumprdata08[/*9*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TWO]]);
    /* Catalyst Monitor Conditions Encountered Counts Bank 2 (Denominator) */
    Iumprdata08[/*10*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TWO]] >> DEM_EIGHT);
    Iumprdata08[/*11*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TWO]]);
    
    /* O2 Sensor Monitor Completion Counts Bank 1 (Numerator) */
    Iumprdata08[/*12*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_NINE]] >> DEM_EIGHT);
    Iumprdata08[/*13*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_NINE]]);
    /* O2 Sensor Monitor Conditions Encountered Counts Bank 1 (Denominator) */
    Iumprdata08[/*14*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_NINE]] >> DEM_EIGHT);
    Iumprdata08[/*15*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_NINE]]);

    /* O2 Sensor Monitor Completion Counts Bank 2 (Numerator) */
    Iumprdata08[/*16*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TEN]] >> DEM_EIGHT);
    Iumprdata08[/*17*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TEN]]);
    /* O2 Sensor Monitor Conditions Encountered Counts Bank 2 (Denominator) */
    Iumprdata08[/*18*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TEN]] >> DEM_EIGHT);
    Iumprdata08[/*19*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_TEN]]);
    
    /* EGR and/or VVT Monitor Completion Counts Bank (Numerator) */
    Iumprdata08[/*20*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]] >> DEM_EIGHT);
    Iumprdata08[/*21*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]]);
    /* EGR and/or VVT Monitor Conditions Encountered Counts Bank (Denominator) */
    Iumprdata08[/*22*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]] >> DEM_EIGHT);
    Iumprdata08[/*23*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]]);
    
    /* AIR Monitor Completion Counts Bank (Numerator) */
    Iumprdata08[/*24*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THIRTEEN]] >> DEM_EIGHT);
    Iumprdata08[/*25*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THIRTEEN]]);
    /* AIR Monitor Conditions Encountered Counts Bank (Denominator) */
    Iumprdata08[/*26*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THIRTEEN]] >> DEM_EIGHT);
    Iumprdata08[/*27*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THIRTEEN]]);
    
    /* EVAP Monitor Completion Counts Bank (Numerator) */
    Iumprdata08[/*28*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIVE]] >> DEM_EIGHT);
    Iumprdata08[/*29*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIVE]]);
    /* EVAP Monitor Conditions Encountered Counts Bank (Denominator) */
    Iumprdata08[/*30*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIVE]] >> DEM_EIGHT);
    Iumprdata08[/*31*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIVE]]);
    
    /* Secondary O2 Sensor Monitor Completion Counts Bank 1 (Numerator) */
    Iumprdata08[/*32*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOURTEEN]] >> DEM_EIGHT);
    Iumprdata08[/*33*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOURTEEN]]);
    /* Secondary O2 Sensor Monitor Conditions Encountered Counts Bank 1 (Denominator) */
    Iumprdata08[/*34*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOURTEEN]] >> DEM_EIGHT);
    Iumprdata08[/*35*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOURTEEN]]);

    /* Secondary O2 Sensor Monitor Completion Counts Bank 2 (Numerator) */
    Iumprdata08[/*36*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIFTEEN]] >> DEM_EIGHT);
    Iumprdata08[/*37*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIFTEEN]]);
    /* Secondary O2 Sensor Monitor Conditions Encountered Counts Bank 2 (Denominator) */
    Iumprdata08[/*38*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIFTEEN]] >> DEM_EIGHT);
    Iumprdata08[/*39*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FIFTEEN]]);
  
  } /* Det check */

  /*Always E_OK is returned*/
  return(E_OK);
}
#endif /*(DEM_OBD_SUPPORT == STD_ON) && (DEM_NUMBER_OF_RATIO_INFO > 0U)*/

/*******************************************************************************
** Function Name        : Dem_GetInfoTypeValue0B                              **
**                                                                            **
** Service ID           : 0x6c                                                **
**                                                                            **
** Description          : This Service is used to request for IUMPR data      **
**                        according InfoType0B.                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Iumprdata0B                                         **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GusGeneralDenominator                           **
**                        Dem_GusIgnitionCylCnt                               **
**                        Dem_GaaIumprNumerator                               **
**                        Dem_GaaIumprDenominator                             **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_NUMBER_OF_RATIO_INFO > 0U))
FUNC(Std_ReturnType, DEM_CODE) Dem_GetInfoTypeValue0B(
  Dcm_OpStatusType OpStatus, uint8* Iumprdata0B)
{
  uint8 LucIndex;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE0B_SID, DEM_E_UNINIT);
  }
  else if(DCM_INITIAL != OpStatus)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE0B_SID, DEM_E_PARAM_CONFIG);
  }
  else if(NULL_PTR == Iumprdata0B)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE0B_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /*In R40 version, Iumprdata0B: buffer containing the contents of InfoType $0B.*/
    LucIndex = DEM_ZERO;
    /* OBD Monitoring Conditions Encountered Counts */
    Iumprdata0B[/*0*/LucIndex++] = (uint8)(Dem_GusGeneralDenominator >> DEM_EIGHT);
    Iumprdata0B[/*1*/LucIndex++] = (uint8)Dem_GusGeneralDenominator;

    /* Ignition Cycle Counter */
    Iumprdata0B[/*2*/LucIndex++] = (uint8)(Dem_GusIgnitionCylCnt >> DEM_EIGHT);
    Iumprdata0B[/*3*/LucIndex++] = (uint8)Dem_GusIgnitionCylCnt;

    /* NMHC Catalyst Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*4*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SIX]] >> DEM_EIGHT);
    Iumprdata0B[/*5*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SIX]]);
    /* NMHC Catalyst Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*6*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SIX]] >> DEM_EIGHT);
    Iumprdata0B[/*7*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SIX]]);

    /* NOx Catalyst Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*8*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_EIGHT]] >> DEM_EIGHT);
    Iumprdata0B[/*9*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_EIGHT]]);
    /* NOx Catalyst Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*10*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_EIGHT]] >> DEM_EIGHT);
    Iumprdata0B[/*11*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_EIGHT]]);

    /* NOx Adsorber Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*12*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SEVEN]] >> DEM_EIGHT);
    Iumprdata0B[/*13*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SEVEN]]);
    /* NOx Adsorber Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*14*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SEVEN]] >> DEM_EIGHT);
    Iumprdata0B[/*15*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SEVEN]]);

    /* PM Filter Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*16*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ELEVEN]] >> DEM_EIGHT);
    Iumprdata0B[/*17*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ELEVEN]]);
    /* PM Filter Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*18*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ELEVEN]] >> DEM_EIGHT);
    Iumprdata0B[/*19*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ELEVEN]]);

    /* Exhaust Gas Sensor Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*20*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOUR]] >> DEM_EIGHT);
    Iumprdata0B[/*21*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOUR]]);
    /* Exhaust Gas Sensor Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*22*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOUR]] >> DEM_EIGHT);
    Iumprdata0B[/*23*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_FOUR]]);
    
    /* EGR and/or VVT Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*24*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]] >> DEM_EIGHT);
    Iumprdata0B[/*25*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]]);
    /* EGR and/or VVT Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*26*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]] >> DEM_EIGHT);
    Iumprdata0B[/*27*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_THREE]]);
    
    /* Boost Pressure Monitor Monitor Completion Condition Counts (Numerator) */
    Iumprdata0B[/*28*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ZERO]] >> DEM_EIGHT);
    Iumprdata0B[/*29*/LucIndex++] = (uint8)(Dem_GaaIumprNumerator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ZERO]]);
    /* Boost Pressure Monitor Monitor Conditions Encountered Counts (Denominator) */
    Iumprdata0B[/*30*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ZERO]] >> DEM_EIGHT);
    Iumprdata0B[/*31*/LucIndex++] = (uint8)(Dem_GaaIumprDenominator[Dem_GaaIumprMinimumRatioIDPerGroup[DEM_ZERO]]);

  } /* Det check */

  /*Always E_OK is returned*/
  return(E_OK);
}
#endif /* (DEM_OBD_SUPPORT == STD_ON) && (DEM_NUMBER_OF_RATIO_INFO > 0U) */

/*******************************************************************************
** Function Name        : Dem_GetDTCOfOBDFreezeFrame                          **
**                                                                            **
** Service ID           : 0x53                                                **
**                                                                            **
** Description          : Gets DTC by freeze frame record number              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : FrameNumber                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : uint8 *DTC,                                         **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfOBDFreezeFrame(uint8
  FrameNumber, P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)DTC)
{
  Std_ReturnType LddReturnValue;

  uint32 LulDTC;
  P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_DATA) LddEntry = NULL_PTR;

  LddReturnValue = E_NOT_OK;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETDTCOFOBDFREEZEFRAME_SID, DEM_E_UNINIT);
  }
  else if(DTC == NULL_PTR)
  {
    /* Report to DET */
   (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
    DEM_GETDTCOFOBDFREEZEFRAME_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /* Check if Freeze Frame number is zero or not*/
    if(DEM_ZERO == FrameNumber)
    {
      if (Dem_ObdMemoryId == DEM_NO_EVMEM_ENTRY)
      {
        LulDTC = DEM_ZERO;
        LddReturnValue = E_OK;
      }
      else 
      {
        if (DEM_MAX_NUMBER_EVENT_ENTRY_PRI > Dem_ObdMemoryId)
        {
          LddEntry = &Dem_PrimaryEventMemory[Dem_ObdMemoryId];
        }
        if (NULL_PTR != LddEntry)
        {
          if ((LddEntry->EventIdRef != DEM_NO_EVENT) &&
              (LddEntry->EventIdRef < DEM_NUMBER_OF_EVENTS))
          {
              (void)Dem_GetEventDTC(
                  &Dem_Event[LddEntry->EventIdRef - DEM_ONE],
                  &LulDTC,
                  DEM_DTC_FORMAT_OBD); /*DEM_DTC_FORMAT_OBD*/
              LddReturnValue = E_OK;
          }
        }
      }

      *DTC = LulDTC;
      #if 0
      LulDTC = (uint32)Dem_GusObdDtcFirstStored;

      /* Most important freeze frame dtc */
      *DTC = (LulDTC << 8) & 0xFFFF00;

      LddReturnValue = E_OK;
      #endif
    }/* Check Freeze frame record number */
    else
    {
       #if (DEM_DEV_ERROR_DETECT == STD_ON)
        /* Error report to DET */
        (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
          DEM_GETDTCOFOBDFREEZEFRAME_SID, DEM_E_PARAM_CONFIG);
       #endif
    }
  }/* Det check */

  return(LddReturnValue);
}
#endif

/*******************************************************************************
** Function Name        : Dem_SetPtoStatus                                    **
**                                                                            **
** Service ID           : 0x79                                                **
**                                                                            **
** Description          : This API is available for support of pid 1E         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : PtoStatus                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GblPtoStatus                                    **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus(boolean PtoStatus)
{
  Std_ReturnType LddReturnValue;
  
  LddReturnValue = E_NOT_OK;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Error report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_SETPTOSTATUS_SID, DEM_E_UNINIT);
  }
  else if((PtoStatus != DEM_TRUE) && (PtoStatus != DEM_FALSE))
  {
   /* Report to DET */
   (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
    DEM_SETPTOSTATUS_SID, DEM_E_PARAM_CONFIG);
  }
  else
  #endif
  { 
    /* Check new status is same as old status */
    if(PtoStatus !=  Dem_GblPtoStatus)
    {
      Dem_GblPtoStatus = PtoStatus;

      LddReturnValue = E_OK;
    }
  }

  return(LddReturnValue);
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_GetFimPermission                                **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to get Fim permission              **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : RatioIndex                                          **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : permission                                          **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)Dem_GetFimPermission(
    uint8 RatioIndex,
    boolean* permission )
{
  #if (DEM_FIM_INTEGRATED == STD_ON)
  uint8 i = 0;
  FiM_GetFunctionPermission(Dem_GaaRatioIdInfo[RatioIndex].ucPrimaryFid, permission);
  if(*permission == DEM_TRUE)
  {
    if(Dem_GaaRatioIdInfo[RatioIndex].ucNumofSecFid >0)
    {
      for(i = 0; i < Dem_GaaRatioIdInfo[RatioIndex].ucNumofSecFid; i++)
      {
        FiM_GetFunctionPermission(Dem_GaaRatioIdInfo[RatioIndex].ucSecondaryFid[i], permission);
        if(*permission == DEM_FALSE)
        {
          break;
        }
      }
    }
  }
  #else
  *permission = DEM_TRUE;
  DEM_UNUSED(RatioIndex);
  #endif /*DEM_FIM_INTEGRATED == STD_ON*/
}
#endif


/*******************************************************************************
 ** Function Name       : Dem_ProcessNum                                      **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to get ratio index                 **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : event, EventStatus                                  **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)Dem_ProcessNum(
    Dem_EventParameterCPCType event,
    Dem_UdsStatusByteType EventStatus)
{
  VAR(uint16, DEM_VAR) LusNum = DEM_ZERO;
  VAR(uint16, DEM_VAR) LusIndex = DEM_ZERO;
  VAR(boolean, DEM_VAR) LblPermission;
  VAR(boolean, DEM_VAR) LblDirty = DEM_FALSE;
  uint8 LucRatioIndex;
  uint8 LucIumprGroupId;

  LusNum = event->usRatioIdCount;

  for (LusIndex = DEM_ZERO; LusIndex < LusNum; LusIndex++)
  {
    LucRatioIndex = DEM_ZERO;

    Dem_GetRatioIndex(event, LusIndex, &LucRatioIndex);
    /*
      Only for monitors being configured with the option "observer",
      the Dem module shall increment the numerator of the corresponding monitor, 
      if the assigned event gets tested/qualified (as passed or failed)
    */
   if (Dem_GaaRatioIdInfo[LucRatioIndex].ucRatioIdType == DEM_RATIO_OBSERVER)
   {
     LblPermission = DEM_FALSE;
     Dem_GetFimPermission(LucRatioIndex, &LblPermission);
     if (LblPermission == DEM_TRUE)
     {
       LucIumprGroupId = Dem_GaaRatioIdInfo[LucRatioIndex].ucIUMPRGroup;
 
       /* As long as an event has Pending status, the Dem module shall stop increasing the numerator and denominator*/
       if ((Dem_GaaIumprNumeratorIsCounted[LucRatioIndex] == DEM_FALSE) &&
           (((EventStatus & (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC) !=
             (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC)))
       {
         /* In IUMPR, if either the numerator or denominator for a specific component reaches the maximum value of 65535, 
           both numbers shall be divided by two before either is incremented again to avoid overflow problems 
         */
         if (Dem_GaaIumprNumerator[LucRatioIndex] ==  DEM_MAX_DENOMINATOR_NUMERATOR_VALUE)
         {
           Dem_DivideIumprRatioValue(LucRatioIndex);
         }
 
         /* Increment the numerator for the requested group */
         if (Dem_GaaIumprNumeratorIsCounted[LucRatioIndex] == DEM_FALSE)
         {
           Dem_GaaIumprNumerator[LucRatioIndex]++;
           Dem_GaaIumprNumeratorIsCounted[LucRatioIndex] = DEM_TRUE;
           Dem_CalCulateMinimumRatioPerGroup(LucIumprGroupId);
         }

        /* Trace: DEM_19792_06_06 */

        /* Increment Flag Logic */
        if (( DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex], 
                                                DEM_MONITOR_ACTIVITY_NUM_INHIBIT)  )   &&  
            ( DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex], 
                                                DEM_MONITOR_ACTIVITY_NUM_INCREMENT)  ))  
        {
              DEM_SET_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex],
                                          DEM_MONITOR_ACTIVITY_NUM_INCREMENT);     
        }

            
 
         SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
         Dem_EventStatusNvRamData.IumprNumerator[LucRatioIndex] = Dem_GaaIumprNumerator[LucRatioIndex];
         Dem_EventStatusNvRamData.IumprDenominator[LucRatioIndex] = Dem_GaaIumprDenominator[LucRatioIndex];
         Dem_EventStatusNvRamData.IumprMinimumRatioIDPerGroup[LucIumprGroupId] = Dem_GaaIumprMinimumRatioIDPerGroup[LucIumprGroupId];
         Dem_EventStatusNvRamData.IumprUpdateFlagPerGroup[LucIumprGroupId] = Dem_GaaIumprUpdateFlagPerGroup[LucIumprGroupId];


         Dem_EventStatusNvRamData.MonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex] = 
            Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex]; 
                
         SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
 
         LblDirty = DEM_TRUE;
        }
      }
    }
  }

  if (LblDirty == DEM_TRUE)
  {
    /* @Trace: Dem_SUD_API_11765 */
    Dem_EvMem_SetNonVolatieDataStatus(DEM_NVDATA_ALL_EVENT_STATUS_ID,
        DEM_EVMEM_STATUS_DIRTY_NVM);
    Dem_EvMem_TriggerWriteAllBlocks(); 
  }  
}
#endif


/*******************************************************************************
 ** Function Name       : Dem_ProcessDen100ms                                 **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : The function is used for incrementing of denominator**
 **                                                                           **
 ** Sync/Async          : Synchronous                                         **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : LucOperationCycleId                                 **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : void                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             : Global Variable(s)  :                               **
 **                       Dem_GaaOperationCycleIdsList, Dem_GaaRatioIdInfo    **
 **                       Dem_Event, Dem_GusRatioIdDisable        **
 **                       Dem_GaaIumprDenominator, Dem_GaaIumprNumerator      **
 **                       Function(s) invoked :  None                         **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
static FUNC(void, DEM_CODE) Dem_ProcessDen100ms()
{
  uint16 LucRatioIdIndex;
  Dem_EventIdType LddEventId;
  Dem_UdsStatusByteType LddEventStatusMask;
  uint8 LucIumprGroupId;
  boolean Lblpermission, LblDirty = DEM_FALSE;
  uint8 LucDenCond;

  if (Dem_GblRatioInit == DEM_FALSE)
  {
     /* In master and optionally primary OBD ECUs, the Dem shall increment ECU
     * global internal general denominator depending on the denominator
     * DEM_IUMPR_GENERAL_OBDCOND, if available. Depending on the system
     * definition the global general denominator (and therefore the
     * DEM_IUMPR_GENERAL_OBDCOND) may not be needed in some or even all primary
     * ECUs. In such cases the DEM_IUMPR_GENERAL_OBDCOND is never set, and the
     * general denominator is stuck at 0 (and reporting of the InfoType $08 /
     * $0B is disabled in the Dcm).*/
    if ((Dem_GusRatioDenCondState[DEM_IUMPR_GENERAL_OBDCOND] ==
           DEM_IUMPR_DEN_STATUS_REACHED))
    {
       Dem_GblRatioInit = DEM_TRUE;
      if (Dem_GusGeneralDenominator < DEM_MAX_DENOMINATOR_NUMERATOR_VALUE)
      {
        Dem_GusGeneralDenominator++;
        if (Dem_GusGeneralDenominator == DEM_MAX_DENOMINATOR_NUMERATOR_VALUE)
        {
          Dem_GusGeneralDenominator = DEM_ZERO;
        }

        SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
        Dem_EventStatusNvRamData.GeneralDenCnt = Dem_GusGeneralDenominator;
        SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
        LblDirty = DEM_TRUE; 
      }
    } 
  }

  for ( LucRatioIdIndex = DEM_ZERO; 
        LucRatioIdIndex < DEM_NUMBER_OF_RATIO_INFO; 
        LucRatioIdIndex++)
  {
    LddEventId = Dem_GaaRatioIdInfo[LucRatioIdIndex].rid_EventId;
    LddEventStatusMask = Dem_AllEventStatusByte[LddEventId];
    LucIumprGroupId = Dem_GaaRatioIdInfo[LucRatioIdIndex].ucIUMPRGroup;

    Dem_GetFimPermission(LucRatioIdIndex, &Lblpermission);
    /* Trace: DEM_19792_06_18 */
    /* @Trace: Dem_SUD_API_11773 */
    if ((Lblpermission == DEM_TRUE)        
        /* Check Inhibit Condition */  
        && (DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIdIndex], 
                                            DEM_MONITOR_ACTIVITY_DEN_INHIBIT) &&
            DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIdIndex], 
                                          DEM_MONITOR_ACTIVITY_DEN_INCREMENT) )                                              
        && (Dem_GusRatioDenCondState[DEM_IUMPR_GENERAL_DENOMINATOR] == DEM_IUMPR_DEN_STATUS_REACHED)
        && ((LddEventStatusMask & (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC) !=
              (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC)
        /* @Trace: SWS_Dem_01104
         * IUMPR ratios referring to an unavailable event shall neither be
         * computed nor reported.*/
      )
    {
        DEM_SET_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIdIndex],
                                    DEM_MONITOR_ACTIVITY_DEN_INCREMENT);    
        SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
        Dem_EventStatusNvRamData.MonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIdIndex] = 
        Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIdIndex];
        SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
        LblDirty = DEM_TRUE;
    } 


    LucDenCond = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    switch (Dem_GaaRatioIdInfo[LucRatioIdIndex].ucIUMPRDenGroup)
    {
      /* 
      * The Dem shall increment monitor internal denominators depending on
      * the DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR, and additional conditions
      * if configured in DemIUMPRDenGroup a maximum of once per driving cycle,
      * and shall consider monitor specific conditions only for the cycle the
      * Release operation was called in.*/

      /* 
      * DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR - individual denominators to
      * support different conditions than the general denominator.
      * It acts on individual denominators and allows a different condition to b e set than
      * for the general denominator. If the standard individual denominator conditions 
      * differ from the general denominator conditions, 
      * they typically differ by a "fueled engine" criterion. */

      case DEM_IUMPR_DEN_NONE:
      /* If Denominator Configuration is DEM_IUMPR_DEN_NONE,
      use DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR (General Denominator + fueled engine operatoin 10 seconds?)
      General Denominator is only used for Infotype $08, $0B */
      if (Dem_GusRatioDenCondState[DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR] == DEM_IUMPR_DEN_STATUS_REACHED)
      {
        LucDenCond = DEM_IUMPR_DEN_STATUS_REACHED;
      }
      break;
      
      default:
      if (Dem_GusRatioDenCondState[DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR] == DEM_IUMPR_DEN_STATUS_REACHED)
      {
        /* If Denominator Configuration is not DEM_IUMPR_DEN_NONE (Cold Start, Physical Condition, etc..),
        use Additional Condition */
        if (Dem_GusRatioDenCondState[Dem_GaaRatioIdInfo[LucRatioIdIndex].ucIUMPRDenGroup] == DEM_IUMPR_DEN_STATUS_REACHED)
        {
          LucDenCond = DEM_IUMPR_DEN_STATUS_REACHED;
        }
      }
      break;
    }

    if ((Lblpermission == DEM_TRUE)
        && (LucDenCond == DEM_IUMPR_DEN_STATUS_REACHED)
        && ((Dem_GaaIumprDenominatorIsCounted[LucRatioIdIndex] == DEM_FALSE))
        && ((LddEventStatusMask & (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC) !=
              (Dem_UdsStatusByteType)DEM_UDS_STATUS_PDTC)
       )
    {
      /*In IUMPR, if either the numerator or denominator for a specific
       *component reaches the maximum value of 65535, both numbers shall
       *be divided by two before either is incremented again to avoid
       *overflow problems
       */
      if (Dem_GaaIumprDenominator[LucRatioIdIndex] == DEM_MAX_DENOMINATOR_NUMERATOR_VALUE)
      {          
        Dem_DivideIumprRatioValue(LucRatioIdIndex);      
      }

      if (Dem_GaaIumprDenominatorIsCounted[LucRatioIdIndex] == DEM_FALSE) 
      {
        Dem_GaaIumprDenominator[LucRatioIdIndex]++;
        Dem_GaaIumprDenominatorIsCounted[LucRatioIdIndex] = DEM_TRUE;
        Dem_CalCulateMinimumRatioPerGroup(LucIumprGroupId);
      }
      
      SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
      Dem_EventStatusNvRamData.IumprDenominator[LucRatioIdIndex] =
          Dem_GaaIumprDenominator[LucRatioIdIndex];
      Dem_EventStatusNvRamData.IumprNumerator[LucRatioIdIndex] =
          Dem_GaaIumprNumerator[LucRatioIdIndex];         
      Dem_EventStatusNvRamData.IumprMinimumRatioIDPerGroup[LucIumprGroupId] =
          Dem_GaaIumprMinimumRatioIDPerGroup[LucIumprGroupId];    
      Dem_EventStatusNvRamData.IumprUpdateFlagPerGroup[LucIumprGroupId] =
          Dem_GaaIumprUpdateFlagPerGroup[LucIumprGroupId];      
      SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();  

       LblDirty = DEM_TRUE;
    }

  }

  if (LblDirty == DEM_TRUE)
  {
    Dem_EvMem_SetNonVolatieDataStatus(DEM_NVDATA_ALL_EVENT_STATUS_ID, DEM_EVMEM_STATUS_DIRTY_NVM);
    Dem_EvMem_TriggerWriteAllBlocks(); 
  }

}
#endif

/*******************************************************************************
 ** Function Name       : Dem_CalcReadinessPIDValue                           **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : API to calculate the value of PID Byte              **
 **                                                                           **
 ** Sync/Async          : Synchronous                                         **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : LucOBDReadinessGrp, LucPIDType, LusByteValue        **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : PIDValue                                            **
 **                                                                           **
 ** Return parameter    : void                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             : Global Variable(s)  :                               **
 **                       Dem_Event                                           **
 **                                                                           **
 **                       Function(s) invoked : None                          **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
FUNC(void, DEM_CODE) Dem_CalcReadinessPIDValue(
  VAR(uint8, DEM_VAR) LucPIDType,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue,
  VAR(uint8, DEM_VAR) LusByteValue,
  VAR(uint8, DEM_VAR) LucOBDReadinessGrp)
{
  VAR(Dem_EventIdType, DEM_VAR) LddEventCount = DEM_ZERO;
  VAR(boolean, DEM_VAR) LblNotReadyGrpFlag = DEM_FALSE;
  VAR(boolean, DEM_VAR) LblConfirmedDTCinGrpFlag = DEM_FALSE;

  *PIDValue = (uint8)(*PIDValue & (uint8)(~LusByteValue));
  while(LddEventCount < Dem_Number_Of_Events)
  {
    if (Dem_Event[LddEventCount].ulEventOBDReadinessGroup == LucOBDReadinessGrp)
    {
      Dem_EventIdType EventId = LddEventCount + DEM_ONE;
      Dem_UdsStatusByteType LddEventStatusMask = DEM_ZERO;
      LddEventStatusMask = Dem_AllEventStatusByte[EventId];

      if (LucPIDType == DEM_PID01_CALC)
      {
        /* Check if test is failed/Passed Last Clear */
        if ((LddEventStatusMask & DEM_UDS_STATUS_TNCSLC) == DEM_UDS_STATUS_TNCSLC)
        {      
          LblNotReadyGrpFlag = DEM_TRUE; 
        }

        /* Check if Confirmed State */
        if ((LddEventStatusMask & DEM_UDS_STATUS_CDTC) == DEM_UDS_STATUS_CDTC)
        {      
          LblConfirmedDTCinGrpFlag = DEM_TRUE; 
          /* Readiness is Fixed to OK */
          LddEventCount = Dem_Number_Of_Events;
        }          
      }
      else if (LucPIDType == DEM_PID41_CALC)
      {
        /* Check if test is failed/Passed this operation cycle */
        if ((LddEventStatusMask & DEM_UDS_STATUS_TNCTOC) == DEM_UDS_STATUS_TNCTOC)
        {      
          LblNotReadyGrpFlag = DEM_TRUE; 
          /* Completeness is Fixed to NOT OK */
          LddEventCount = Dem_Number_Of_Events;
        }
      }
      else 
      {
        // Do Nothing
      }

    }
    LddEventCount++;
  }

  if (LucPIDType == DEM_PID01_CALC)
  {
    /* 1. If Confirmed DTC Exist in Requested Group */
    if (LblConfirmedDTCinGrpFlag == DEM_TRUE)
    {
      /* This group is Ready -> Value is zero in SAE1979) */
      *PIDValue = *PIDValue & (~LusByteValue);      
    }
    /* If Not Tested Since Last Clear DTC or Confirmed DTC not Exist in Requested Group */
    else if (LblNotReadyGrpFlag == DEM_TRUE) 
    {
      /* This group is not Ready -> Value is one in SAE1979 */
      *PIDValue = *PIDValue | LusByteValue;      
    }
  }
  else if (LucPIDType == DEM_PID41_CALC)
  {    
    /* If Not Tested since This Operation Cycle dtc Exist in Requested Group */
    if (LblNotReadyGrpFlag == DEM_TRUE)
    {
      /* This group is Complete -> Value is zero in SAE1979) */
      *PIDValue = *PIDValue | LusByteValue;      
    }
  }      
  else 
  {
    // Do Nothing
  }
}
#endif /**DEM_OBD_SUPPORT == STD_ON*/

/*******************************************************************************
 ** Function Name       : Dem_CalcPID41PerGroup                               **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : API to calculate the value of PID 41                **
 **                                                                           **
 ** Sync/Async          : Synchronous                                         **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : PIDValue, DisableGroupIndexinPID41,                 **
 **                        ReadinessGroup, CompletenessIndexinPID41           **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : void                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             : Global Variable(s)  :                               **
 **                       Dem_GulEventIdDisabled                              **
 **                                                                           **
 **                       Function(s) invoked : None                          **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
static FUNC(void, DEM_CODE) Dem_CalcPID41PerGroup(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue,
  VAR(uint8, DEM_VAR) DisableGroupIndexinPID41,
  VAR(uint8, DEM_VAR) ReadinessGroup,
  VAR(uint8, DEM_VAR) CompletenessIndexinPID41
  )
{
  if (DEM_ZERO == (Dem_GulEventIdDisabled & DisableGroupIndexinPID41))
  {
    /* @Trace: Dem_SUD_API_11068 */
    *PIDValue = *PIDValue | DisableGroupIndexinPID41;

    Dem_CalcReadinessPIDValue(DEM_PID41_CALC, PIDValue, 
    CompletenessIndexinPID41, ReadinessGroup); 
  }
  else
  {
    *PIDValue = *PIDValue & (~DisableGroupIndexinPID41);

    /* Bit-4 of byte2 is set to 1 if monitor is disabled */
    *PIDValue = *PIDValue | CompletenessIndexinPID41;
  }
}
#endif /*DEM_OBD_SUPPORT == STD_ON*/
/*******************************************************************************
 ** Function Name       : Dem_CalcPID41PerGroupCheck                          **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : API to calculate the value of PID 41                **
 **                                                                           **
 ** Sync/Async          : Synchronous                                         **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : DisableGroupID, OBDReadyGroupID,                    **
 **                       ReadinessCompletenessGroup, SupportedEnableGroup    **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : PID41ByteCAddr , PID41ByteDAddr                     **
 **                                                                           **
 ** Return parameter    : void                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             : Global Variable(s)  :                               **
 **                       Dem_GulEventIdDisabled                              **
 **                                                                           **
 **                       Function(s) invoked : None                          **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
static FUNC(void, DEM_CODE) Dem_CalcPID41PerGroupCheck(
  VAR(uint32, DEM_VAR) DisableGroupID,
  VAR(uint8, DEM_VAR) OBDReadyGroupID,
  VAR(uint8, DEM_VAR) SupportedEnableGroup,
  VAR(uint8, DEM_VAR) ReadinessCompletenessGroup,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41ByteCAddr,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41ByteDAddr
  )
{
    if ((Dem_GulEventIdDisabled & DisableGroupID) != DisableGroupID)
    {
      Dem_CalcReadinessPIDValue(DEM_PID41_CALC, PID41ByteDAddr, 
      ReadinessCompletenessGroup, 
      OBDReadyGroupID);
      /*  monitoring Enabled */
      *PID41ByteCAddr = (*PID41ByteCAddr | SupportedEnableGroup);
    }
    else
    {
      /*  monitoring disabled */
      *PID41ByteCAddr = (*PID41ByteCAddr & ~SupportedEnableGroup);
      /*  monitoring uncomplete */
      *PID41ByteDAddr = (*PID41ByteDAddr | ReadinessCompletenessGroup);
    }
}

#endif

/*******************************************************************************
 ** Function Name       : Dem_SetMalfuntionOnOff  = *1                        **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to process the indicator bit for   **
 **                       obd                                                 **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : LucIndicatorIndex, LusCount, EventStatusMask        **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
#ifdef DEM_MIL_INDICATORID
FUNC(void, DEM_CODE)
Dem_SetMalfuntionOnOff(void)
{
  boolean indicatorAttributeStatus;
  Dem_NumOfIndicatorAttributeType idx;
  P2CONST(Dem_IndicatorAttributeType , AUTOMATIC, DEM_VAR) indicator;

  for (idx = 0U; idx < Dem_Number_Of_Indicators; idx++)
  {
    indicator = Dem_GetCfgIndicatorAtt(idx);
    if(DEM_MIL_INDICATORID == indicator->IndicatorIdRef)
    {
      indicatorAttributeStatus = Dem_EvMem_GetIndicatorAttStatus(indicator->EventIdRef, indicator->IndicatorAttStatusPos);
      Dem_GucMilonFlag = indicatorAttributeStatus << 7U;
      if(Dem_GucMilonFlag == DEM_BIT7_MASK1)
      {
        break;
      }
    }
  }
}
#endif
#endif

/*******************************************************************************
 ** Function Name       : Dem_GetRatioIndex                                   **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to get ratio index                 **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : event, ArrayIndex, EventStatusMask                  **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : RatioId                                             **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)
Dem_GetRatioIndex(
  Dem_EventParameterCPCType event,
  uint32 ArrayIndex,
  P2VAR(uint8, AUTOMATIC,DEM_VAR) RatioId)
{
  *RatioId = event->aaRatioIndex[ArrayIndex];
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_SetPfcCycleSetPfcCycleQualified                 **
 **                                                                           **
 ** Service ID          : 0xaa                                                **
 **                                                                           **
 ** Description         : Function is used to set pfc qualifed flag           **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U))
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetPfcCycleSetPfcCycleQualified(void)
{
  Dem_NumOfEventMemoryEntryType memLoc = DEM_NO_EVMEM_ENTRY;
  Dem_NumOfEventMemoryEntryType numOfMemEntries = Dem_SizeOfEventMemory[DEM_DTC_ORIGIN_PERMANENT_MEMORY];
  
  for(memLoc = 0U; memLoc < numOfMemEntries; memLoc++)
  {
    SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
    Dem_PerDtcState[memLoc].PfcQualified = DEM_TRUE;
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }

  return E_OK;
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_GetPfcCycleQualified                            **
 **                                                                           **
 ** Service ID          : 0xab                                                **
 **                                                                           **
 ** Description         : Function is used to get pfc qualifed flag           **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U))
FUNC(Std_ReturnType, Dem_CODE) 
Dem_GetPfcCycleQualified(P2VAR(boolean, AUTOMATIC, DEM_VAR) pfcCycleisqualified)
{
  
  *pfcCycleisqualified = Dem_PerDtcState[0].PfcQualified;
  
  return E_OK;
}
#endif



/*******************************************************************************
 ** Function Name       : Dem_GetMalfuntionOnOff                              **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to get the indicator bit for obd   **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : Dem_GucMilonFlag                                    **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(boolean, Dem_CODE)
Dem_GetMalfuntionOnOff(void)
{

  return Dem_GucMilonFlag;
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_SetObdCycle                                     **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to set OBD Cyle                     **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetObdCycle(uint8 LucOperationCycleId)
{
  boolean dirty = DEM_FALSE;

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
  if( (DEM_OPCYC_WARMUP == Dem_GstOperationCycleName[LucOperationCycleId].ucOperationCycle) 
       && (DEM_TRUE == Dem_EventStatusNvRamData.DtcClear))
  {
    if(Dem_EventStatusNvRamData.NumOfWUCSinceLC < DEM_MAX_WARM_UP_COUNT)
    {
      Dem_EventStatusNvRamData.NumOfWUCSinceLC++;
      dirty = DEM_TRUE;
    }
    Dem_GusWarmUpCycleCount++;
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }
  else if (DEM_OPCYC_WARMUP ==
             Dem_GstOperationCycleName[LucOperationCycleId].ucOperationCycle)
  {
    Dem_GusWarmUpCycleCount++;
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }
  #if(DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO)
  else if(DEM_OPCYC_IGNITION == Dem_GstOperationCycleName[LucOperationCycleId].ucOperationCycle)
  {
    if(Dem_GusIgnitionCylCnt < DEM_MAX_DENOMINATOR_NUMERATOR_VALUE)
    {
      Dem_GusIgnitionCylCnt++;
      
      Dem_EventStatusNvRamData.IgnitionCylCnt = Dem_GusIgnitionCylCnt;
      dirty = DEM_TRUE;
    }
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }
  #endif
  else
  {
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }

  

  if(dirty == DEM_TRUE)
  {
    Dem_EvMem_SetNonVolatieDataStatus(DEM_NVDATA_ALL_EVENT_STATUS_ID, DEM_EVMEM_STATUS_DIRTY_NVM);
    Dem_EvMem_TriggerWriteAllBlocks(); 
  }
  
  return E_OK;
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_ClearObdInfomation                              **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to clear OBD information           **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(void, DEM_CODE) Dem_ClearObdInfomation(void)
{
  Dem_EventMemoryEntryPtrType LddMemEntry;
  uint8 LucGroupRatioCount;

  Dem_GblClearTimeStartObd = DEM_TRUE;
  Dem_GblDtcCleared = DEM_TRUE;
  Dem_GulTimeSinceMilOn = 0;
  Dem_GulDemClearTimeCount = 0;

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
  Dem_EventStatusNvRamData.DtcClear = Dem_GblDtcCleared; 
  Dem_EventStatusNvRamData.NumOfWUCSinceLC = 0;
  Dem_EventStatusNvRamData.DataOfPID21 = DEM_ZERO;
  Dem_EventStatusNvRamData.DataOfPID31 = DEM_ZERO;
  Dem_EventStatusNvRamData.DataOfPID4D = DEM_ZERO;
  Dem_EventStatusNvRamData.DataOfPID4E = DEM_ZERO;
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  
  #if (DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO)

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
  /* Initialise the general denominator for infotype08 and infotype0b as zero */
  Dem_EventStatusNvRamData.GeneralDenCnt = DEM_ZERO;
  Dem_GusGeneralDenominator = Dem_EventStatusNvRamData.GeneralDenCnt;
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();

  for (LucGroupRatioCount = DEM_ZERO; LucGroupRatioCount < DEM_SIXTEEN; LucGroupRatioCount++)
  {
     SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
    /* Init to Last Array, which always 0 */
    Dem_EventStatusNvRamData.IumprMinimumRatioIDPerGroup[LucGroupRatioCount] = DEM_NUMBER_OF_RATIO_INFO;
    Dem_GaaIumprMinimumRatioIDPerGroup[LucGroupRatioCount] = Dem_EventStatusNvRamData.IumprMinimumRatioIDPerGroup[LucGroupRatioCount];

    Dem_EventStatusNvRamData.IumprUpdateFlagPerGroup[LucGroupRatioCount] = DEM_ZERO;
    Dem_GaaIumprUpdateFlagPerGroup[LucGroupRatioCount] = Dem_EventStatusNvRamData.IumprUpdateFlagPerGroup[LucGroupRatioCount];
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }
  #endif /* DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO */

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
  if ((DEM_NO_EVMEM_ENTRY != Dem_ObdMemoryId) &&
      (DEM_MAX_NUMBER_EVENT_ENTRY_PRI > Dem_ObdMemoryId))
  {
    if (DEM_NO_EVENT != Dem_PrimaryEventMemory[Dem_ObdMemoryId].EventIdRef)
    {
      uint8 LucIdx;
      LddMemEntry = &Dem_PrimaryEventMemory[Dem_ObdMemoryId];
      LddMemEntry->EventIdRef = DEM_NO_EVENT;
      
      for (LucIdx = DEM_ZERO; LucIdx < DEM_SIZE_OF_EVENT_DATA; LucIdx++)
      {
        LddMemEntry->data[LucIdx] = DEM_ZERO;
      }

      #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)
      for (LucIdx = 0; LucIdx < DEM_MAX_NUM_EVENTS_PER_DTC; LucIdx++)
      {
        LddMemEntry->EventStatuByte[LucIdx] = 0x00;
      }   
      #endif /*DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON*/
    }
    Dem_ObdMemoryId = DEM_NO_EVMEM_ENTRY;
    Dem_EventStatusNvRamData.ObdMemoryId = Dem_ObdMemoryId;
      Dem_EvMem_SetNonVolatieDataStatus(DEM_NVDATA_ALL_EVENT_STATUS_ID,
          DEM_EVMEM_STATUS_DIRTY_NVM);
      Dem_EvMem_TriggerWriteAllBlocks();

  }
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();

}
#endif


/*******************************************************************************
 ** Function Name       : Dem_OPStartInit                                     **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to set OBD Cyle                    **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)
Dem_OCStartInit(void)
{

  uint8 LucIdxRatio, LucIdx;
  Dem_GblRatioInit = DEM_FALSE;

  #if (DEM_J1979_2_OBD_ON_UDS == STD_ON)
  /* Trace: DEM_19792_06_08 */

  /* @Trace: Dem_SUD_API_11821 */
  /* Update Monitor Activity Ratio When Driving Cycle End */
  Dem_UpdateMonitorActivityRatio();

  /* Driving Cycle Start Funciton */
  Dem_InitMonitorActivityRatio();
  #endif /* MCUSOL1_DEVELOP_19792 */

  /* numerator and denominator may not be incremented more than once by driving cycle*/
  for (LucIdxRatio = DEM_ZERO;
       LucIdxRatio < DEM_NUMBER_OF_RATIO_INFO;
       LucIdxRatio++ )
  {
    Dem_GaaIumprDenominatorIsCounted[LucIdxRatio] = DEM_FALSE;
    Dem_GaaIumprNumeratorIsCounted[LucIdxRatio] = DEM_FALSE;
  }

  for (LucIdx = DEM_ZERO;
             LucIdx < DEM_IUMPR_MAX_CONDITION_NUMBER ;
             LucIdx++)
  {
    Dem_GusRatioDenCondState[LucIdx] = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
  }

  Dem_GusRatioDenCondState[DEM_IUMPR_DEN_NONE] = DEM_IUMPR_DEN_STATUS_REACHED;

}
#endif

/*******************************************************************************
 ** Function Name       : Dem_SetDataOfPID21                                  **
 **                                                                           **
 ** Service ID          : 0xa6                                                **
 **                                                                           **
 ** Description         : Function is used to set the value of PID $21 in the **
 **                       Dem by a software component.                        **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : PID21value                                          **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetDataOfPID21( uint8* PID21value )
{

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_UNINIT);
  }
  else
  #endif
  {

  }

  return E_OK;
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_SetDataOfPID31                                  **
 **                                                                           **
 ** Service ID          : 0xa7                                                **
 **                                                                           **
 ** Description         : Function is used to set the value of PID $31 in the **
 **                       Dem by a software component.                        **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : PID31value                                          **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetDataOfPID31( uint8* PID31value )
{

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_UNINIT);
  }
  else
  #endif
  {

  }
  
  return E_OK;
}
#endif

/*******************************************************************************
 ** Function Name       : Dem_SetDataOfPID4D                                  **
 **                                                                           **
 ** Service ID          : 0xa8                                                **
 **                                                                           **
 ** Description         : Function is used to set the value of PID $4D in the **
 **                       Dem by a software component.                        **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : PID4Dvalue                                          **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetDataOfPID4D( uint8* PID4Dvalue )
{

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_UNINIT);
  }
  else
  #endif
  {


  }
  
  return E_OK;
}
#endif


/*******************************************************************************
 ** Function Name       : Dem_SetDataOfPID4E                                  **
 **                                                                           **
 ** Service ID          : 0xa9                                                **
 **                                                                           **
 ** Description         : Function is used to set the value of PID $4E in the **
 **                       Dem by a software component.                        **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : PID4Evalue                                          **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetDataOfPID4E( uint8* PID4Evalue )
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* Module Initialization check */
  if(DEM_INIT != Dem_GucInit)
  {
    /* Report to DET */
    (void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID,
      DEM_GETINFOTYPEVALUE08_SID, DEM_E_UNINIT);
  }
  else
  #endif
  {

  }
  
  return E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Dem_SetDTR                                          **
**                                                                            **
** Service ID           : 0xa2                                                **
**                                                                            **
** Description          : Reports a DTR result with lower and upper limit.    **
**                        The internal event status serves as master whether  **
**                        the DTR values are forwarded or ignored, also       **
**                        taking the DTRUpdateKind into account.              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different DTRIds. Non reentrant for   **
**                        the same DTRId.                                     **
**                                                                            **
** Input Parameters     : DTRId      - Identification of a DTR element by     **
**                                     assigned DTRId.                        **
**                        TestResult - Test result of DTR                     **
**                        LowerLimit - Lower limit of DTR                     **
**                        UpperLimit - Upper limit of DTR                     **
**                        Ctrlval    - Control value of the DTR to support    **
**                                     its interpretation Dem-internally.     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
/* @Trace: SRS_Diag_04126 SRS_Diag_04179 SRS_Diag_04181
 */
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetDTR(
    VAR(uint16, DEM_VAR) DTRId,
    VAR(sint32, DEM_VAR) TestResult,
    VAR(sint32, DEM_VAR) LowerLimit,
    VAR(sint32, DEM_VAR) UpperLimit,
    VAR(Dem_DTRControlType, DEM_VAR)Ctrlval
    )
{
  sint32 LslTestResult = TestResult;
  sint32 LslLowerLimit = LowerLimit;
  sint32 LslUpperLimit = UpperLimit;

  /* @Trace: SWS_Dem_00756
   * The Dem shall provide an API Dem_SetDTR within an interface
   * DTRCentralReport to provide a report mechanism to the SWC for their test
   * results. Arguments shall be the DemDtrId, the test value, the minimum and
   * maximum limit, and a state indicating whether the monitor provides a valid
   * minimum limit, maximum limit, or both, or whether the reported values shall
   * be reset to zero.*/

  Std_ReturnType LddRetVal = E_NOT_OK;
  /* Module Initialization check */
  if (DEM_INIT != Dem_GucInit)
  {
    /* @Trace: Dem_SUD_API_12954 */
    /* Report to DET */
    DEM_REPORT_ERROR( DEM_SETDTR_SID, DEM_E_UNINIT);
    /*LddRetVal = E_NOT_OK;*/
  }
  #if (DEM_NUMBER_OF_DTRS > DEM_ZERO)
  else if (DTRId >= DEM_NUMBER_OF_DTRS)
  {
    /* @Trace: Dem_SUD_API_00169 */
    DEM_REPORT_ERROR( DEM_SETDTR_SID, DEM_E_PARAM_DATA);
    /*LddRetVal = E_NOT_OK;*/
  }
  #endif
  else
  {
    /* @Trace: SWS_Dem_00757
     * If DemDtrEventRef references a DemEventParameter, the Dem shall
     * process the reported DTR values only if all the enable/storage
     * conditions of the referenced event are fulfilled, independent
     * of DemDtrUpdateKind. If any of the enable/storage conditions
     * of the referenced event are not fulfilled, then the Dem shall
     * ignore the reported DTR values.*/
    #if (DEM_NUMBER_OF_DTRS > DEM_ZERO)
    boolean LblIsProceed = DEM_FALSE;
    if (Dem_GaaDtrInfo[DTRId].usEventId != DEM_NO_IDX_U16)
    {
      /* @Trace: SWS_Dem_01105
       * DTRs referring to the event shall neither be computed nor reported
       * (Dem_SetDTR).*/

      /* @Trace: Dem_SUD_MACRO_006*/
      #if (DEM_ENABLE_CONDITION_SUPPORT == STD_ON)
      /* @Trace: Dem_SUD_API_12972 */
      if (E_OK ==
            Dem_GetEventEnableConditionState(Dem_GaaDtrInfo[DTRId].usEventId))
      #endif
      {
        #if (DEM_STORAGE_CONDITION_SUPPORT == STD_ON)
        Dem_EventParameterCPCType event = &Dem_Event[Dem_GaaDtrInfo[DTRId].usEventId - 1U];
        /* @Trace: Dem_SUD_API_12973 */
        if (E_OK ==
              Dem_GetEventStorageConditionState(event))
        #endif
        {
          /* @Trace: SWS_Dem_00754
           * The Dem shall use the DemDtrUpdateKind for the evaluation and
           * processing of reported DTR-values:
           * DEM_DTR_UPDATE_ALWAYS: State of the event is not considered
           * (default, and used if DemDtrEventRef is not configured).
           * DEM_DTR_UPDATE_STEADY: Only when the events pre-debouncing
           * within Dem is "stuck" at the FAIL or PASS limit, and the latest
           * result matches the debouncing direction.*/
          /* @Trace: Dem_SUD_API_12974 */
          if (DEM_DTR_UPDATE_STEADY == Dem_GaaDtrInfo[DTRId].usUpdateKind)
          {
            /* @Trace: Dem_SUD_API_12975 */
            LblIsProceed = DEM_TRUE;
          }
        }
      }
      
    }
    else if (DEM_DTR_UPDATE_ALWAYS == Dem_GaaDtrInfo[DTRId].usUpdateKind)
    {
      /* @Trace: Dem_SUD_API_12970 */
      LblIsProceed = DEM_TRUE;
    }
    else
    {
      /* @Trace: Dem_SUD_API_12965 */
      /* Nothing to do */
    }

    if (DEM_TRUE == LblIsProceed)
    {
      LddRetVal = E_OK;
      if (Ctrlval == DEM_DTR_CTL_RESET)
      {
        /* @Trace: Dem_SUD_API_12976 */
        Dem_DtrData[DTRId].Testvalue = DEM_ZERO;
        Dem_DtrData[DTRId].Lowlimvalue = DEM_ZERO;
        Dem_DtrData[DTRId].Upplimvalue = DEM_ZERO;
      }
      else if ((DEM_DTR_CTL_NO_MAX == Ctrlval) ||
               (DEM_DTR_CTL_NO_MIN == Ctrlval) ||
               (DEM_DTR_CTL_NORMAL == Ctrlval))
      {
        uint8 LucOldOutInSide = DEM_DTR_INSIDE;
        uint8 LucNewOutInSide = DEM_DTR_INSIDE;
        uint16 LslValDTRConvert;

        if (Ctrlval == DEM_DTR_CTL_NO_MAX)
        {
          /* @Trace: Dem_SUD_API_12960 */
          LslUpperLimit = (sint32)0xFFFF;
        }
        else if (Ctrlval == DEM_DTR_CTL_NO_MIN)
        {
          /* @Trace: Dem_SUD_API_12956 */
          LslLowerLimit = (sint32)0x00;
        }
        else
        {
          /* @Trace: Dem_SUD_API_12955 */
          /* Nothing to do */
        }

        if (LslTestResult < LslLowerLimit)
        {
          /* @Trace: Dem_SUD_API_12959 */
          LucOldOutInSide = DEM_DTR_OUTSIDE_MIN;
        }
        else if (LslTestResult > LslUpperLimit)
        {
          /* @Trace: Dem_SUD_API_12958 */
          LucOldOutInSide = DEM_DTR_OUTSIDE_MAX;
        }
        else
        {
          /* @Trace: Dem_SUD_API_12957 */
          /* Nothing to do */
        }
        /* @Trace: SWS_Dem_00759
         * The Dem shall ensure the validity of the test results vs.
         * threshold(s). If the parameter TestResult passed in Dem_SetDTR is
         * inside/outside the thresholds given by UpperLimit and LowerLimit,
         * Testvalue of Dem_DcmGetDTRData shall also be inside/outside
         * Upplimvalue and Lowlimvalue. If rounding effects lead to an
         * unintended change of the meaning, the thresholds shall be shifted by
         * one increment accordingly to restore the result*/
        
        if (E_OK == Dem_DTR_Conversion_Linear(LslTestResult,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuNumerator0,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuNumerator1,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuDenominator0,
                      &LslValDTRConvert))
        {
          /* @Trace: Dem_SUD_API_12961 */
          Dem_DtrData[DTRId].Testvalue = LslValDTRConvert;
        }
        if (E_OK == Dem_DTR_Conversion_Linear(LslLowerLimit,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuNumerator0,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuNumerator1,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuDenominator0,
                      &LslValDTRConvert))
        {
          /* @Trace: Dem_SUD_API_12963 */
          Dem_DtrData[DTRId].Lowlimvalue = LslValDTRConvert;
        }
        if (E_OK == Dem_DTR_Conversion_Linear(LslUpperLimit,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuNumerator0,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuNumerator1,
                      Dem_GaaDtrInfo[DTRId].usDemDtrCompuDenominator0,
                      &LslValDTRConvert))
        {
          /* @Trace: Dem_SUD_API_12966 */
          Dem_DtrData[DTRId].Upplimvalue = LslValDTRConvert;
        }

        if (Dem_DtrData[DTRId].Testvalue < Dem_DtrData[DTRId].Lowlimvalue)
        {
          /* @Trace: Dem_SUD_API_00170 */
          LucNewOutInSide = DEM_DTR_OUTSIDE_MIN;
        }
        else if (Dem_DtrData[DTRId].Testvalue
            > Dem_DtrData[DTRId].Upplimvalue)
        {
          /* @Trace: Dem_SUD_API_12967 */
          LucNewOutInSide = DEM_DTR_OUTSIDE_MAX;
        }
        else
        {
          /* @Trace: Dem_SUD_API_12968 */
          /* Nothing to do */
        }

        if (((LucOldOutInSide == DEM_DTR_INSIDE)
            && (LucNewOutInSide == DEM_DTR_OUTSIDE_MAX))
            || ((LucOldOutInSide == DEM_DTR_OUTSIDE_MAX)
                && ((LucNewOutInSide == DEM_DTR_INSIDE)
                    || (LucNewOutInSide == DEM_DTR_OUTSIDE_MIN))))
        {
          /* @Trace: Dem_SUD_API_12969 */
          Dem_DtrData[DTRId].Upplimvalue = Dem_DtrData[DTRId].Upplimvalue
              - DEM_ONE;
        }
        else if (((LucOldOutInSide == DEM_DTR_INSIDE)
            && (LucNewOutInSide == DEM_DTR_OUTSIDE_MIN))
            || ((LucOldOutInSide == DEM_DTR_OUTSIDE_MIN)
                && ((LucNewOutInSide == DEM_DTR_INSIDE)
                    || (LucNewOutInSide == DEM_DTR_OUTSIDE_MAX))))
        {
          /* @Trace: Dem_SUD_API_00171 */
          Dem_DtrData[DTRId].Lowlimvalue = Dem_DtrData[DTRId].Lowlimvalue
              + DEM_ONE;
        }
        else
        {
          /* @Trace: Dem_SUD_API_12964 */
          /* Nothing to do */
        }
      }
      else if (Ctrlval != DEM_DTR_CTL_INVISIBLE)
      {
        /* @Trace: Dem_SUD_API_00172 */
        /* DEM_DTR_CTL_INVISIBLE Values are all ignored. This DTR is treated
         * for the external view (tester) as if not integrated.*/
        LddRetVal = E_NOT_OK;
      }
      else
      {
        /* @Trace: Dem_SUD_API_12977 */
        /* Nothing to do */
      }
    }
    #else
    /* @Trace: Dem_SUD_API_12962 */
    DEM_UNUSED(DTRId);
    DEM_UNUSED(LslTestResult);
    DEM_UNUSED(LslLowerLimit);
    DEM_UNUSED(LslUpperLimit);
    DEM_UNUSED(Ctrlval);
    #endif
  }

  return LddRetVal;
}

#endif

/*******************************************************************************
** Function Name        : Dem_DcmGetDTRData                                   **
**                                                                            **
** Service ID           : 0xa5                                                **
**                                                                            **
** Description          : Reports a DTR data along with TID-value, UaSID,     **
**                        test result with lower and upper limit.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Obdmid      - Identification of a DTR element by    **
**                                      assigned DTRId.                       **
**                        TIDindex    - Index of the TID within the DEM. Runs **
**                                      from 0 to "numberOfTIDs" obtained in  **
**                                      the call to                           **
**                                      Dem_DcmGetNumTIDsOfOBDMID()           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : TIDvalue    - TID to be put on the tester reponse   **
**                        UaSID       - UaSID to be put on the tester reponse **
**                        Testvalue   - Latest test result                    **
**                        Lowlimvalue - Lower limit value associated to the   **
**                                      latest test result                   **
**                        Upplimvalue - Upper limit value associated to the   **
**                                      latest test result                   **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetDTRData(
    VAR(uint8, DEM_VAR) Obdmid,
    VAR(uint8, DEM_VAR) TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
    )
{
  /* @Trace: SWS_Dem_00762
   * Upon request by the Dcm, the Dem shall respond with the data
   * available for a particular OBDMID / TIDindex per requested OBDMID using the
   * API Dem_DcmGetDTRData. This value can be used by the Dcm to iteratively
   * request for the DTR data per OBDMID / TIDindex starting from 0 to
   * numberofTIDs minus one.
   * */

  Std_ReturnType LddRetVal = E_NOT_OK;
  /* Module Initialization check */
  if (DEM_INIT != Dem_GucInit)
  {
    /* @Trace: Dem_SUD_API_12684 */
    /* Report to DET */
    DEM_REPORT_ERROR( DEM_DCMGETDTRDATA_SID, DEM_E_UNINIT);
  }
  else if ((NULL_PTR == TIDvalue) ||
           (NULL_PTR == UaSID) ||
           (NULL_PTR == Testvalue) ||
           (NULL_PTR == Lowlimvalue) ||
           (NULL_PTR == Upplimvalue) )
  {
    /* @Trace: Dem_SUD_API_12686 */
    DEM_REPORT_ERROR( DEM_DCMGETDTRDATA_SID, DEM_E_PARAM_POINTER);
  }
  else
  {
    #if (DEM_NUMBER_OF_DTRS > DEM_ZERO)
    uint8 LucIdx;
    /* @Trace: Dem_SUD_API_12688 */
    for (LucIdx = DEM_ZERO; LucIdx < DEM_NUMBER_OF_DTRS; LucIdx++)
    {
      boolean LblEvIsSuppressionTriggered = DEM_FALSE;
      /* @Trace: Dem_SUD_API_12691 */
      if (DEM_NO_IDX_U16 != Dem_GaaDtrInfo[LucIdx].usEventId)
      {

        LblEvIsSuppressionTriggered =
            Dem_EvIsProcStateTriggered(
                Dem_GaaDtrInfo[LucIdx].usEventId, DEM_EVPROCSTATE_DTC_SUPP);
      }
      /* @Trace: Dem_SUD_API_12685 */
      if ((Obdmid == Dem_GaaDtrInfo[LucIdx].usOBDMID) &&
         (TIDindex == Dem_GaaDtrInfo[LucIdx].usTIDIndex)
         && (DEM_TRUE != LblEvIsSuppressionTriggered)
        )
      {
        /* @Trace: Dem_SUD_API_12693 */
        *TIDvalue = Dem_GaaDtrInfo[LucIdx].usTID;
        *UaSID = Dem_GaaDtrInfo[LucIdx].usUaSID;
        *Testvalue = Dem_DtrData[LucIdx].Testvalue;
        *Lowlimvalue = Dem_DtrData[LucIdx].Lowlimvalue;
        *Upplimvalue = Dem_DtrData[LucIdx].Upplimvalue;
        LddRetVal = E_OK;
      }

    }
    #else
    /* @Trace: Dem_SUD_API_12687 */
    DEM_UNUSED(Obdmid);
    DEM_UNUSED(TIDindex);
    #endif
  }
  return LddRetVal;
}
#endif

/*******************************************************************************
** Function Name        : Dem_DTR_Conversion_Linear                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : It used conversion liner for DTR                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : sint32 Value                                        **
**                        sint32 Value                                        **
**                        uint16 Num0                                         **
**                        uint16 Num1                                         **
**                        uint16 Denominator0                                 **
**                                                                            **
** InOut parameter      : uint16* CalcResult                                  **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_Returntype                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
*******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
FUNC(Std_ReturnType, DEM_CODE) Dem_DTR_Conversion_Linear(
  sint32 Value,
  uint16 Num0,
  uint16 Num1,
  uint16 Denominator0,
  uint16 * CalcResult)
{
  uint32 LulVal = (uint32) Value;
  Std_ReturnType LddReturnValue = E_OK;
  if ((DEM_ZERO != Num1) && (DEM_ZERO != Denominator0))
  {
    /* @Trace: Dem_SUD_API_11798 */
    if (LulVal > ((DEM_MAX_DENOMINATOR_NUMERATOR_VALUE) / ((uint32)Num1)))
    {
      /* @Trace: Dem_SUD_API_11799 */
      LddReturnValue = E_NOT_OK;
    }
    /* @Trace: Dem_SUD_API_11800 */
    if (E_OK == LddReturnValue)
    {
      *CalcResult = (((uint16)LulVal) * (Num1));
      if ((*CalcResult > ((DEM_MAX_DENOMINATOR_NUMERATOR_VALUE) - (Num0))))
      {
        /* @Trace: Dem_SUD_API_11801 */
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* @Trace: Dem_SUD_API_11802 */
        *CalcResult = (*CalcResult + Num0)/(Denominator0);
      }
    }
  }
  else
  {
    /* @Trace: Dem_SUD_API_11797 */
    LddReturnValue = E_NOT_OK;
  }

  return LddReturnValue;
}
#endif


/*******************************************************************************
** Function Name        : Dem_DcmGetInfoTypeValue79                           **
**                                                                            **
** Service ID           : 0xc3                                                **
**                                                                            **
** Description          : Service to report the value of monitor activity 
                          denominator PID computed by the Dem. 
                          API is needed in OBD-relevant ECUs only. API Availability: 
                          This API will be available only if: 
                          ({ecucDem/DemGeneral.DemOBDSupport)} 
                          != DEM_OBD_NO_OBD_SUPPORT)                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus          - OpStatus "Only DCM_INITIAL will appear, 
                                          because this API behaves synchronous."                   **
**                        DataValueBufferSize  - The maximum number of data bytes 
                                            that can be written to the DataValueBuffer. 
                                            When the function returns, the value is updated with the actual 
                                            number of data bytes that are written to the Data ValueBuffer.        **

**                        DataValueBuffer    - Buffer containing the contents of 
                                              the monitor activity denominator. 
                                              The buffer is provided by the caller with the appropriate size.            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GucInit                                         **
**                        Dem_GaaIumprDenominator                             **
**                        Dem_GusGeneralDenominator                           **
**                        Dem_GusIgnitionCylCnt                               **
**                        Dem_GaaIumprNumerator                               **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/

/* Trace: DEM_19792_06_16 */
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue79(
  VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DataValueBuffer)
{
  VAR(Std_ReturnType, DEM_VAR) LddReturnValue = E_OK;
  VAR(uint8, DEM_VAR) LucIndex;

  /* Module Initialization check */
  if (DEM_INIT != Dem_GucInit)
  {
    /* @Trace: Dem_SUD_API_12553 */
    /* Report to DET */
    DEM_REPORT_ERROR( DEM_DCMGETINFOTYPEVALUE79_SID, DEM_E_UNINIT);
  }
  else if (DCM_INITIAL != OpStatus)
  {
    /* @Trace: Dem_SUD_API_12554 */
    /* Report to DET */
    DEM_REPORT_ERROR( DEM_DCMGETINFOTYPEVALUE79_SID, DEM_E_PARAM_CONFIG);
  }
  else if (NULL_PTR == DataValueBuffer)
  {
    /* @Trace: Dem_SUD_API_12555 */
    /* Report to DET */
    DEM_REPORT_ERROR( DEM_DCMGETINFOTYPEVALUE79_SID, DEM_E_PARAM_POINTER);
  }
  else
  {
      /* @Trace: SWS_Dem_01369 in R21-11
      * Support of Monitor Activity Denominator dThe Dem shall calculate the data
      * for ITID "Monitor Activity Denominator" and provide it in the parameter 
      * of DataValueBuffer of the API Dem_DcmGetInfoTypeValue79.c
      * */
      LucIndex = DEM_ZERO;      
      /* Get the Monitor Activity Denominator, Index 0 */
      /* In General, MAD is Same in All Ratio */
      DataValueBuffer[LucIndex] = Dem_GaaMonitorActivityDenominator[LucIndex];
  }/* Det check */

  return(LddReturnValue);
}
#endif 
/*******************************************************************************
 ** Function Name       : Dem_ProcessMonitorActivityInhibitConditionCheck     **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to Calculate Inhibit Condition Monitor Activity N/D  **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
/* @Trace: RS_Diag_04252 in R21-11
  Support of SAE J1979-2
 */
/* Trace: DEM_19792_06_17 */
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
static FUNC(void, DEM_CODE)Dem_ProcessMonitorActivityInhibitConditionCheck()
{  
  VAR(uint16, DEM_VAR) LusFidIndex = DEM_ZERO;
  VAR(uint16, DEM_VAR) LusIndex = DEM_ZERO;
  VAR(uint8, DEM_VAR) LucRatioIndex = DEM_ZERO;
  VAR(uint16, DEM_VAR) LusEventId = DEM_ZERO;
  VAR(boolean, DEM_VAR) LblPermission = DEM_FALSE;
  VAR(boolean, DEM_VAR) LblPendingOBDDTCisExist = DEM_FALSE;
  P2CONST(Dem_CombinedDtcType, AUTOMATIC,  DEM_VAR) LddCbDTC;
  
  /* Check For ALL DTC, not Depend on DemEventMemorySet */
  for (LusIndex = DEM_ZERO; LusIndex < DEM_MAX_NUMBER_EVENT_ENTRY_PRI; LusIndex++)
  {
    LusEventId = Dem_PrimaryEventMemory[LusIndex].EventIdRef;
    if ((LusEventId != DEM_NO_EVENT))
    {
      LddCbDTC = Dem_GetCbDTCByEventId(LusEventId);

      if (DEM_IS_BIT_SET_UDSSTATUSBYTE(LusEventId, DEM_UDS_STATUS_PDTC)
        )
      {  
        /* Pending OBD DTC is Exist */
        LblPendingOBDDTCisExist = DEM_TRUE;          
        break;
      }
    }
  }
  
  /* Check Ratio Permission of All FID related with MonitorActivity */    
  for (LucRatioIndex = DEM_ZERO; LucRatioIndex < DEM_NUMBER_OF_RATIO_INFO; LucRatioIndex++)
  {
    /* Check Inhibit Condition - OBD(Event Can Mil-On) DTC Exist in Primary Memory */
    /* Check Only When Permit to Increase */
    /* Checking 1st index is enough to Check Num inhibit condition related with Pending OBD DTC(Event Can Mil-On) */
    if (DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex], 
                                          DEM_MONITOR_ACTIVITY_DEN_INHIBIT) ||
        DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex], 
                                          DEM_MONITOR_ACTIVITY_NUM_INHIBIT) )
    {
      if (LblPendingOBDDTCisExist == DEM_TRUE)
      {
        for(LucRatioIndex = DEM_ZERO; LucRatioIndex < DEM_NUMBER_OF_RATIO_INFO; LucRatioIndex++)    
        {     
          /* Trace: DEM_19792_06_09 */
          /* If Pending OBD DTC Exist in Primary Memory, Monitor Activity Denominator cannot increase */
          DEM_SET_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex],
                                        DEM_MONITOR_ACTIVITY_DEN_INHIBIT);
                      
          /* If Monitor Activity Denominator Increment flag is already set, reset the flag */
          if ( DEM_IS_BIT_SET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex],
                                      DEM_MONITOR_ACTIVITY_DEN_INCREMENT) )
          {
            /* Reset the Increment Bit */
            DEM_CLR_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex],
                                      DEM_MONITOR_ACTIVITY_DEN_INCREMENT);
          }      
        
          /* If Pending OBD DTC Exist in Primary Memory, Monitor Activity Numerator cannot increase */
          DEM_SET_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex],
                                        DEM_MONITOR_ACTIVITY_NUM_INHIBIT);
                        
          /* If Monitor Activity Numerator Increment flag is already set, reset the flag */
          if ( DEM_IS_BIT_SET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex],
                                        DEM_MONITOR_ACTIVITY_NUM_INCREMENT) )
          {
              /* Reset the Increment Bit */
              DEM_CLR_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex],
                                            DEM_MONITOR_ACTIVITY_NUM_INCREMENT);
          }  
        }
      } 

      SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
      Dem_EventStatusNvRamData.MonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex] = 
      Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex];
      Dem_EventStatusNvRamData.MonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex] = 
      Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex];
      SchM_Exit_Dem_REQUEST_STATUS_PROTECTION(); 
    }
    
    /* Check Inhibit Condition - FIMFID per Ratio */
    /* Check Only When Permit to Increase */
    if (DEM_IS_BIT_UNSET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex], 
                                              DEM_MONITOR_ACTIVITY_DEN_INHIBIT))
    {
      if (Dem_GaaRatioIdInfo[LucRatioIndex].ucRatioIdType == DEM_RATIO_OBSERVER)
          /*&& (Dem_GusRatioFaultFound[LucRatioIndex] == DEM_FALSE)*/
      {
        Dem_GetFimPermission(LucRatioIndex, &LblPermission);
      }

      #if (DEM_FIM_INTEGRATED == STD_ON)
      /* @Trace: Dem_SUD_API_11767 */
      if (LblPermission == DEM_FALSE)
      #endif
      {
        /* If LblPermission is FALSE, Monitor Activity Denominator cannot increase */
        DEM_SET_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex]
                                        ,DEM_MONITOR_ACTIVITY_DEN_INHIBIT);
        /* If Increment flag is already set, reset the flag */
        if ( DEM_IS_BIT_SET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex]
                                              ,DEM_MONITOR_ACTIVITY_DEN_INCREMENT) )
        {
          /* Reset the Increment Bit */
          DEM_CLR_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex],
                                    DEM_MONITOR_ACTIVITY_DEN_INCREMENT);
          SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
          Dem_EventStatusNvRamData.MonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex] = 
          Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex];
          SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
        }
      }
    } 
  }
}
#endif /* MCUSOL1_DEVELOP_19792 */

/*******************************************************************************
 ** Function Name       : Dem_UpdateMonitorActivityRatio                           **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to update MAR                      **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : EventId, EventStatus                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
/* @Trace: RS_Diag_04252 in R21-11
  Support of SAE J1979-2
 */
/* Trace: DEM_19792_06_08 */
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)Dem_UpdateMonitorActivityRatio(void)
{
    /* Monitor-Activity */         
  VAR(uint8, DEM_VAR) LucRatioIndex = DEM_ZERO;                        

    for(LucRatioIndex = 0; LucRatioIndex < DEM_NUMBER_OF_RATIO_INFO; LucRatioIndex++)    
    {           
      /* If Set Monitor Activity Denominator Incremented Flag in this OC */
      if ( DEM_IS_BIT_SET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex], 
                                              DEM_MONITOR_ACTIVITY_DEN_INCREMENT)  )     
      {
          /* Only can Incremented once for MINI-D */
          if (Dem_GaaMonitorActivityDenominator[LucRatioIndex] < 0xFFu)
          {
            Dem_GaaMonitorActivityDenominator[LucRatioIndex]++;
            SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
            Dem_EventStatusNvRamData.MonitorActivityDenominator[LucRatioIndex] = Dem_GaaMonitorActivityDenominator[LucRatioIndex];   
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
          }   
      }    
      
      /* If Set Monitor Activity Numerator Incremented Flag in this OC */
      if ( DEM_IS_BIT_SET_MONITOR_ACTIVITY(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex], 
                                            DEM_MONITOR_ACTIVITY_NUM_INCREMENT)  )   
      {
          if (Dem_GaaMonitorActivityNumerator[LucRatioIndex] < 0xFFu)
          {
              Dem_GaaMonitorActivityNumerator[LucRatioIndex]++;
              SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
              Dem_EventStatusNvRamData.MonitorActivityNumerator[LucRatioIndex] = Dem_GaaMonitorActivityNumerator[LucRatioIndex];
              SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
          }
      }

      /* Monitor Activity Ratio is Only Updated When MAD reached 0xFFu */
      if (Dem_GaaMonitorActivityDenominator[LucRatioIndex] == 0xFFu)
      {
          /* Calculate Monitor Activity Ratio */
          Dem_GaaMonitorActivityRatio[LucRatioIndex] = Dem_GaaMonitorActivityNumerator[LucRatioIndex];     
          /* Mini-N Reset, Mini-D will reset after Loop */
          Dem_GaaMonitorActivityNumerator[LucRatioIndex] = 0u;
          Dem_GaaMonitorActivityDenominator[LucRatioIndex] = 0u;

          SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
          Dem_EventStatusNvRamData.MonitorActivityRatio[LucRatioIndex] = Dem_GaaMonitorActivityRatio[LucRatioIndex];
              Dem_EventStatusNvRamData.MonitorActivityNumerator[LucRatioIndex] = Dem_GaaMonitorActivityNumerator[LucRatioIndex];
          Dem_EventStatusNvRamData.MonitorActivityDenominator[LucRatioIndex] = Dem_GaaMonitorActivityDenominator[LucRatioIndex];   
          SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
      }
    }
}
#endif /* MCUSOL1_DEVELOP_19792 */



/*******************************************************************************
 ** Function Name       : Dem_InitMonitorActivityRatio                           **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Function is used to Init Monitor Activity 
                              when Operation Cycle Start                      **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : EventId, EventStatus                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
/* @Trace: RS_Diag_04252 in R21-11
  Support of SAE J1979-2
 */
/* Trace: DEM_19792_06_05 */
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
FUNC(void, DEM_CODE)Dem_InitMonitorActivityRatio(void)
{
  /* Monitor-Activity */
  VAR(uint16, DEM_VAR) LucRatioIndex = DEM_ZERO;

  /* Init MAR Status */
  for(LucRatioIndex = DEM_ZERO; LucRatioIndex < DEM_NUMBER_OF_RATIO_INFO; LucRatioIndex++)    
  {         
    DEM_CLR_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex], 
                                  DEM_MONITOR_ACTIVITY_ALLBYTE);
    DEM_CLR_MONITOR_ACTIVITYBYTE(Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex], 
                                  DEM_MONITOR_ACTIVITY_ALLBYTE);  
    SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
    Dem_EventStatusNvRamData.MonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex] = 
          Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[LucRatioIndex];
    Dem_EventStatusNvRamData.MonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex] =
          Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[LucRatioIndex];
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  }
}

#endif

/*******************************************************************************
 ** Function Name       : Dem_DivideIumprRatioValue                           **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Num or Den have to Divided when Num or Den reached  **
                          to 0xFFFF. Min Ratio or Min Index have to           **
 **                       re-assigned                                         **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : RatioID                                             **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
static FUNC(void, DEM_CODE) Dem_DivideIumprRatioValue( VAR(Dem_RatioIdType, DEM_VAR) RatioID)
{
  if (Dem_GaaIumprDenominator[RatioID] != DEM_ZERO)
  {
    Dem_GaaIumprDenominator[RatioID] =
        (Dem_GaaIumprDenominator[RatioID] - DEM_ONE) / DEM_TWO;
  }

  if (Dem_GaaIumprNumerator[RatioID] != DEM_ZERO)
  {
    Dem_GaaIumprNumerator[RatioID] =
        (Dem_GaaIumprNumerator[RatioID] - DEM_ONE) / DEM_TWO;
  }
}
#endif /*(DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON)*/

/*******************************************************************************
 ** Function Name       : Dem_CalCulateMinimumRatioPerGroup                   **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : when denominator or numerator change,               **
                          Check the Minimum Ratio Per Group                   **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : RatioID                                             **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
static FUNC(void, DEM_CODE) Dem_CalCulateMinimumRatioPerGroup( VAR(uint8, DEM_VAR) IumprGroupID)
{
  VAR(uint16, DEM_VAR) LusPerRatioIndex;
  VAR(uint16, DEM_VAR) LusPrevMinRatioId;
  VAR(float32, DEM_VAR) LusPrevMinRatioValue;
  VAR(float32, DEM_VAR) LusRatioValue;

  LusPrevMinRatioId = Dem_GaaIumprMinimumRatioIDPerGroup[IumprGroupID];

  /* All Numerators in Same Group have to compared with Minimum Ratio */
  for ( LusPerRatioIndex = DEM_ZERO; 
        LusPerRatioIndex < DEM_NUMBER_OF_RATIO_INFO; 
        LusPerRatioIndex++)
  {
    /* Check this Ratio is Same Group */
    if (IumprGroupID == Dem_GaaRatioIdInfo[LusPerRatioIndex].ucIUMPRGroup)
    {
      if ((Dem_GaaIumprDenominator[LusPerRatioIndex] == DEM_ZERO) || 
          (Dem_GaaIumprDenominator[LusPrevMinRatioId] == DEM_ZERO))
      {
        /* exclude the case when Denominator is zero */
        LusPrevMinRatioValue = (float32)Dem_GaaIumprNumerator[LusPrevMinRatioId] / DEM_ONE;
        LusRatioValue = (float32)Dem_GaaIumprNumerator[LusPerRatioIndex] / DEM_ONE;
      }
      else
      {
        LusPrevMinRatioValue = ((float32)Dem_GaaIumprNumerator[LusPrevMinRatioId] / (float32)Dem_GaaIumprDenominator[LusPrevMinRatioId]);
        LusRatioValue = (float32)(Dem_GaaIumprNumerator[LusPerRatioIndex] / (float32)Dem_GaaIumprDenominator[LusPerRatioIndex]);
      }

      /* Check Minimum Value */
      if (LusRatioValue < LusPrevMinRatioValue)
      {
        Dem_GaaIumprMinimumRatioIDPerGroup[IumprGroupID] = LusPerRatioIndex;
        Dem_GaaIumprUpdateFlagPerGroup[IumprGroupID] = DEM_TRUE;
      }
      else 
      {
        if  (LusRatioValue == LusPrevMinRatioValue)
        {
          /* If Same Ratio, Change only when Numerator or Denominator is bigger than prev ratio */
          if ((Dem_GaaIumprNumerator[LusPerRatioIndex] > Dem_GaaIumprNumerator[LusPrevMinRatioId]) || 
              (Dem_GaaIumprDenominator[LusPerRatioIndex] > Dem_GaaIumprDenominator[LusPrevMinRatioId]))
          {
            Dem_GaaIumprMinimumRatioIDPerGroup[IumprGroupID] = LusPerRatioIndex;
            Dem_GaaIumprUpdateFlagPerGroup[IumprGroupID] = DEM_TRUE;
          }
        }
      }
    }
  }
}
#endif /* (DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON) */

/*******************************************************************************
 ** Function Name       : Dem_ObdGetSizeOfPID                                 **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Get Size of PID                                     **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : PID, DataElementIndexOfPID                           **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : None                                                **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
static FUNC(uint8, DEM_CODE) Dem_ObdGetSizeOfPID(
  VAR(uint8, DEM_VAR) PID,
  VAR(uint8, DEM_VAR) DataElementIndexOfPID)
{
  VAR(uint8, DEM_VAR) LucSize = DEM_ZERO;

  #if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)
  uint8 LucDataElementIndexOfPID;
  P2CONST(Dem_DataElementClassType, AUTOMATIC, DEM_CONST) DataElementPtr;
  uint8 LucIdx;
  for (LucIdx = DEM_ZERO; LucIdx < DEM_MAX_NUMBER_OF_PID_RECDS; LucIdx++)
  {
    if ((PID == Dem_GaaPid[LucIdx].ucPid) &&
        (DataElementIndexOfPID < Dem_GaaPid[LucIdx].ucNumOfDataElements))
    {
      LucDataElementIndexOfPID =  Dem_GaaPid[LucIdx].aaPidDataElementIndex[DataElementIndexOfPID];
      DataElementPtr = &Dem_DataElementClass[LucDataElementIndexOfPID];
      LucSize = DataElementPtr->size;
    }
  }
  #endif /* DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO */

  return LucSize;
}
#endif /* DEM_OBD_SUPPORT == STD_ON*/

/*******************************************************************************
 ** Function Name       : Dem_GetOffSetOfPidData                              **
 **                                                                           **
 ** Service ID          : None                                                **
 **                                                                           **
 ** Description         : Get offset of stored PID data                       **
 **                                                                           **
 ** Re-entrancy         : Reentrant                                           **
 **                                                                           **
 ** Input Parameters    : None                                                **
 **                                                                           **
 ** InOut parameter     : None                                                **
 **                                                                           **
 ** Output Parameters   : None                                                **
 **                                                                           **
 ** Return parameter    : uint32                                              **
 **                                                                           **
 ** Preconditions       : None                                                **
 **                                                                           **
 ** Remarks             :                                                     **
 *******************************************************************************/
#if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO))
FUNC(uint32, DEM_CODE) Dem_GetOffSetOfPidData(void)
{
  uint32 offset;
  Dem_EventParameterPCType event;
  P2CONST(Dem_EventRelatedDataType, AUTOMATIC, DEM_VAR) EvData;
  Dem_EventIdType eventId;

  offset = 0;
  /*
   * Data format = [-FF0-|-FF1-| ED | J1939FF | J1939EXFF | PIDData]
  */
  if ((DEM_NO_EVMEM_ENTRY != Dem_ObdMemoryId) &&
      (DEM_MAX_NUMBER_EVENT_ENTRY_PRI > Dem_ObdMemoryId))
  {
    if (Dem_PrimaryEventMemory[Dem_ObdMemoryId].EventIdRef != DEM_NO_EVMEM_ENTRY)
    {
      eventId = Dem_PrimaryEventMemory[Dem_ObdMemoryId].EventIdRef; 
      event = &Dem_Event[eventId- 1U];
      EvData = &Dem_EventRelatedData[event->e_PointToData];

      #if (DEM_SIZE_OF_FREEZEFRAME > 0u)  
      if (EvData->FFClassPos < Dem_Num_Of_FreezeFrameClass)
      {
        /* Data format = [-FF0-|-FF1-| ED | J1939FF | J1939EXFF| PIDData] */
        offset = (uint32)EvData->MaxNumOfFreezeFrameRecords * (uint32)Dem_FreezeFrameClass[EvData->FFClassPos].size;
      }
      #endif /*DEM_SIZE_OF_FREEZEFRAME > 0u*/

      #if (DEM_SIZE_OF_EXTENDED_DATA > 0u)
      if (EvData->EDClassPos < Dem_Num_Of_ExtendedDataClass)
      {
        /* Data format = [-FF0-|-FF1-| ED | J1939FF | J1939EXFF| PIDData ] */
        offset += (uint16)Dem_ExtendedDataClass[EvData->EDClassPos].size;
      }
      #endif /*DEM_SIZE_OF_EXTENDED_DATA > 0u*/
      
      #if ((DEM_J1939_SUPPORT == STD_ON) && (DEM_SIZE_OF_J1939FREEZEFRAME > 0U))
      if(EvData->J1939FFClassPos < Dem_Num_Of_J1939FreezeFrameClass)
      {
        /* Data format = [-FF0-|-FF1-| ED | J1939FF | J1939EXFF| PIDData ] */
        offset += (uint32)Dem_J1939FreezeFrameClass[EvData->J1939FFClassPos].size;
      }
      #endif /*(DEM_J1939_SUPPORT == STD_ON) && (DEM_SIZE_OF_J1939FREEZEFRAME > 0U)*/
    
      #if ((DEM_J1939_SUPPORT == STD_ON) && (DEM_SIZE_OF_J1939EXPANDEDFREEZEFRAME > 0U))
      if (EvData->J1939EXFFClassPos < Dem_Num_Of_J1939FreezeFrameClass)
      {
        offset += (uint32)Dem_J1939FreezeFrameClass[EvData->J1939EXFFClassPos].size;
      }
      #endif /*(DEM_J1939_SUPPORT == STD_ON) && (DEM_SIZE_OF_J1939EXPANDEDFREEZEFRAME > 0U)*/
    }
  }

  return offset;
}
#endif /*(DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)*/


/* polyspace +2 MISRA-C3:20.1 [Justified:Low] "Not a defect" */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
