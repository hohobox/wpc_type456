/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_ObdRam.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**  PURPOSE   : Defining Global Variables                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date:DD-MM-YYYY By            Description                         **
********************************************************************************
** 4.0.0   27-Jul-2023    EunKyung Kim   #40946                               **
**                                                                            **
** 1.1.2    04-09-2020    EunKyung.Kim   Changes made As per Redmine #25254   **
**                                                                            **
** 1.1.0    10-12-2018    EunKyung.Kim    Changes made As per Redmine #8561   **
**                                                                            **
** 1.0.0    18-11-2016      Autron      Initial Version                       **
*******************************************************************************/

/* polyspace-begin MISRA-C3:20.1 [Justified:Low] "Follow Autosar Spec" */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_ObdRam.h" /* Dem global Ram variables header file for OBD */

#if (DEM_OBD_SUPPORT == STD_ON)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*************************************************************************
 * VAR INIT_UNSPECIFIED
 ************************************************************************/
#define DEM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * NO_INIT_UNSPECIFIED == SAVED_ZONE
 ************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
/* PermaneDem_PerDtcStatent Event Memory variable */
VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_PermanentEventMemory
  [DEM_MAX_NUMBER_EVENT_ENTRY_PER];

VAR(Dem_PerDtcStateType, DEM_VAR_NOINIT) Dem_PerDtcState
  [DEM_MAX_NUMBER_EVENT_ENTRY_PER];
#endif

#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"


/*************************************************************************
 * VAR CLEARED_32
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

/* Used to Store the Mil on time [min] */
VAR(uint32, DEM_VAR) Dem_GulTimeSinceMilOn;  

/* Used to calculate time in milli sec */
VAR(uint32, DEM_VAR) Dem_GulDemTimeObdmsCount;
/* Used to Store whether event is disabled or not for pid41e */
VAR(uint32, DEM_VAR) Dem_GulEventIdDisabled;
/* Used to Store time since clear dtc is called count in min */
VAR(uint32, DEM_VAR) Dem_GulDemClearTimeCount;

VAR(uint32, DEM_VAR) Dem_OBDOldDistanceInfo;

VAR(uint32, DEM_VAR) Dem_OBDOldEngStartInfo;

#define DEM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

/*************************************************************************
 * CLEARED_16
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Store the value of General Denominator*/
VAR(uint16, DEM_VAR) Dem_GusGeneralDenominator;
/* Store the value of ignition counter */
VAR(uint16, DEM_VAR) Dem_GusIgnitionCylCnt;
/* Pointer point the memory location in which Obd event is stored */
VAR(uint16, DEM_VAR) Dem_GusObdDtcFirstStored;
/* Pointer point the memory location in which Obd event is stored */
VAR(uint16, DEM_VAR) Dem_GusEventstoredinPermanent;

#if (DEM_NUMBER_OF_RATIO_INFO > 0U)
/* Store the value of Denominator, Last Array is Always 0 */
VAR(uint16, DEM_VAR) Dem_GaaIumprDenominator[DEM_NUMBER_OF_RATIO_INFO + DEM_ONE];
/* Store the value of Numerator, Last Array is Always 0 */
VAR(uint16, DEM_VAR) Dem_GaaIumprNumerator[DEM_NUMBER_OF_RATIO_INFO + DEM_ONE];
/* Minimum Ratio per IUMPR Group */
VAR(uint16, DEM_VAR) Dem_GaaIumprMinimumRatioIDPerGroup[DEM_SIXTEEN];
#endif /* DEM_NUMBER_OF_RATIO_INFO > 0U */
/* Used to Store the warm up cycle count */
VAR(uint16, DEM_VAR) Dem_GusWarmUpCycleCount;

#define DEM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/*************************************************************************
 * CLEARED_8
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Used to calculate Mil status of pid01 */
VAR(uint8, DEM_VAR) Dem_GucMilonFlag;

/* Used to calculate Mil Off->On Check  */
VAR(uint8, DEM_VAR) Dem_GucPreMilonFlag;

/* Used to calculate Warm up cycle count when Mil status is off */
VAR(uint8, DEM_VAR) Dem_GucWarmUpCycleCountMil;

/* Used to calculate Warm up cycle count when DTC is cleared */
VAR(uint8, DEM_VAR) Dem_GucWarmUpCycleCountDtcClear;
#if (DEM_NUMBER_OF_RATIO_INFO > 0U)
/* Trace: DEM_19792_06_11 */
/* Store the value of Monitor Activity Denominator (MAD) */
VAR(uint8, DEM_VAR) Dem_GaaMonitorActivityDenominator[DEM_NUMBER_OF_RATIO_INFO];
/* Store the value of Monitor Activity Numerator (MAN) */
VAR(uint8, DEM_VAR) Dem_GaaMonitorActivityNumerator[DEM_NUMBER_OF_RATIO_INFO];
/* Store the value of Monitor Activity RATIO (MAR) */
VAR(uint8, DEM_VAR) Dem_GaaMonitorActivityRatio[DEM_NUMBER_OF_RATIO_INFO];

#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
/* Permanent Event Memory variable */
VAR(uint8, DEM_VAR) Dem_PermanentEventMemoryState
  [DEM_MAX_NUMBER_EVENT_ENTRY_PER];
#endif

/* Current Obd Memory ID  */
VAR(uint8, DEM_VAR) Dem_ObdMemoryId;

#define DEM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

/*****************************************************************************/
/* VAR CLEARED BOOLEAN                                                       */
/*****************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Current operation cycle Id Value */
VAR(boolean, DEM_VAR) Dem_ObdEventStored;
/* Used to calculate Mil status of pid01 */
VAR(boolean, DEM_VAR) Dem_GblMilStarted;
/* Used to calculate Clear Dtc time */
VAR(boolean, DEM_VAR) Dem_GblDtcCleared;
/* Used to Store the pto status */
VAR(boolean, DEM_VAR) Dem_GblPtoStatus;
/* Used to calculate time since clear dtc is called */
VAR(boolean, DEM_VAR) Dem_GblClearTimeStartObd;
#if (DEM_NUMBER_OF_RATIO_INFO > 0U)
VAR(boolean, DEM_VAR) Dem_GblRatioInit;
/* Store the value of General Denominator*/
VAR(boolean, DEM_VAR) Dem_GusRatioIdDisable[DEM_NUMBER_OF_RATIO_INFO];
VAR(boolean, DEM_VAR) Dem_GusRatioFaultFound[DEM_NUMBER_OF_RATIO_INFO];
VAR(boolean, DEM_VAR) Dem_GusRatioMonitored[DEM_SIXTEEN];
VAR(boolean, DEM_VAR) Dem_GusRatioDenCondState[DEM_IUMPR_MAX_CONDITION_NUMBER];
/* Store the indicator of Denominator whether it is updated in one Operation Cycle*/
VAR(boolean, DEM_VAR) Dem_GaaIumprDenominatorIsCounted[DEM_NUMBER_OF_RATIO_INFO];
/* Store the indicator of Numerator whether it is updated in one Operation Cycle*/
VAR(boolean, DEM_VAR) Dem_GaaIumprNumeratorIsCounted[DEM_NUMBER_OF_RATIO_INFO];
/* Minimum Ratio Update Flag Per IUMPR Group */
VAR(boolean, DEM_VAR) Dem_GaaIumprUpdateFlagPerGroup[DEM_SIXTEEN];

/* Trace: DEM_19792_06_12 */
/* Store the indicator of Monitor Activity Denominator whether it is updated in one Operation
 * Cycle*/
VAR(boolean, DEM_VAR) Dem_GaaMonitorActivityDenominatorNeedCountedCycleEnd[DEM_NUMBER_OF_RATIO_INFO];
/* Store the indicator of Monitor Activity Numerator whether it is updated in one Operation
 * Cycle*/
VAR(boolean, DEM_VAR) Dem_GaaMonitorActivityNumeratorNeedCountedCycleEnd[DEM_NUMBER_OF_RATIO_INFO];

#endif /* DEM_NUMBER_OF_RATIO_INFO > 0U */

#define DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*************************************************************************
 * CONST
 ************************************************************************/
 
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if (DEM_NUMBER_OF_DTRS > DEM_ZERO)
Dem_DTRDataType Dem_DtrData[DEM_NUMBER_OF_DTRS];
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  

/* polyspace-end MISRA-C3:20.1 [Justified:Low] "Follow Autosar Spec" */
/*****************************************************************************/

#endif /* DEM_OBD_SUPPORT == STD_ON */
/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/
