/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Obd.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_Obd.c                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 4.0.0   27-Jul-2023   EunKyung Kim   #40946                                **
**                                                                            **
** 3.3.3    19-10-2021    LanhLT       Changes made As per Redmine #31128     **
**                                                                            **
** 1.2.0    22-02-2021    EunKyung.Kim    Changes made As per Redmine #25380  **
**                                                                            **
** 1.1.0    10-12-2018    EunKyung.Kim    Changes made As per Redmine #8561   **
**                                                                            **
** 1.0.0     06-11-2015    Autron      Initial Version                        **                      
*******************************************************************************/

#ifndef DEM_OBD_H
#define DEM_OBD_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_ObdRam.h"

/*******************************************************************************
**                      Macro Section                                         **
*******************************************************************************/
#if(DEM_OBD_SUPPORT == STD_ON)
/* @Trace: SWS_Dem_00755
 * The Dem shall only support a linear mapping, i.e. only support
 * values for the coefficients b, c, and f.
 * */
/* @Trace: SWS_Dem_00758
 * The Dem shall support a conversion of the ECUinternal resolution into
 * the standardized external uint16 size and resolution according to the
 * configured and standardized UaSID. For that reason, the conversion
 * formula is configured per DTR. It is assumed that the conveyed parameter
 * of the API call contain the values in the internal size and resolution.
 * The Dem does offer sint32 as parameter for that reason to cover uint16
 * as well as sint16 (or even sint32) internal data types. */
#define DEM_DTR_INSIDE         (0x00U)
#define DEM_DTR_OUTSIDE_MIN    (0x01U)
#define DEM_DTR_OUTSIDE_MAX    (0x02U)



/* Trace: DEM_OBD_09_10 */
#define DEM_PID01_CALC          (0x01U)
#define DEM_PID41_CALC          (0x41U)

#define DEM_NUM_OF_IUMPR_GROUP   16U


/* Trace: DEM_19792_06_10 */
#define DEM_MONITOR_ACTIVITY_INIT           (0x00U)
#define DEM_MONITOR_ACTIVITY_ALLBYTE           (DEM_MONITOR_ACTIVITY_NUM_INCREMENT | \
                                                DEM_MONITOR_ACTIVITY_NUM_INHIBIT)
#define DEM_MONITOR_ACTIVITY_NUM_INCREMENT  DEM_BIT0_MASK1
#define DEM_MONITOR_ACTIVITY_NUM_INHIBIT    DEM_BIT1_MASK1
#define DEM_MONITOR_ACTIVITY_DEN_INCREMENT  DEM_BIT0_MASK1
#define DEM_MONITOR_ACTIVITY_DEN_INHIBIT    DEM_BIT1_MASK1
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"


#if(DEM_OBD_SUPPORT == STD_ON)

extern FUNC(void, DEM_CODE) Dem_InitOBD(void);
extern FUNC(void, DEM_CODE) Dem_MainFunctionOBD(void);



#ifdef DEM_MIL_INDICATORID
extern FUNC(void, DEM_CODE)
Dem_SetMalfuntionOnOff(void);
#endif

#if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)
extern FUNC(Std_ReturnType, DEM_CODE)
Dem_GetReadDataOfPID(
  P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) entry,
  P2VAR(uint8, AUTOMATIC, DEM_VAR)DestBuffer,
  boolean ReportTotalRecord,
  Dem_PidIdentifierType PidIdentifier,
  boolean ReportTotalDataElement,
  Dem_NumOfDataElementClassType DataElementIndexOfPID);
#endif

extern FUNC(void, DEM_CODE) Dem_CalcPIDValue(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue,
  uint8 LusByteValue, uint8 LucOBDReadinessGrp);

extern FUNC(void, DEM_CODE) Dem_CalcPID41_34(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41Value);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfTimeEngineStart(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetPIDDataOnRequest(
  P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_CONST)LpEventMemory,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)DestBuffer,
  uint8 LucEventMemoryIndex, boolean ReportTotalRecord, uint16 DataIdentifier,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)LucTotalSizePid);

#if (DEM_OBD_SUPPORT == STD_ON)
extern FUNC(Dem_ReturnGetFreezeFrameDataByRecordType, DEM_CODE)
Dem_DcmGetOBDFreezeFrameData(
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_VAR) DTC,
  P2VAR(uint8, AUTOMATIC, DEM_VAR)DestBuffer,
  P2VAR(uint8, AUTOMATIC, DEM_VAR)BufSize);

extern FUNC(Std_ReturnType, DEM_CODE)
Dem_GetSizeOfOBDFreezeFrameData(
    Dem_EventParameterCPCType event,
    const boolean ReportTotalRecord,
    const Dem_PidIdentifierType PidIdentifier,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize);
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
extern FUNC(Std_ReturnType, DEM_CODE)
Dem_SetPfcCycleSetPfcCycleQualified(void);

extern FUNC(Std_ReturnType, Dem_CODE) 
Dem_GetPfcCycleQualified(P2VAR(boolean, AUTOMATIC, DEM_VAR) pfcCycleisqualified);

#endif

#if(DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO)

extern FUNC(void, DEM_CODE)Dem_ProcessNum(
    Dem_EventParameterCPCType event,
    Dem_UdsStatusByteType EventStatus);

extern FUNC(void, DEM_CODE) Dem_OCStartInit(void);

/* Trace: DEM_19792_06_06 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_ProcessMonitorActivityNum(
    Dem_EventIdType EventId, 
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) NvMDirtyFlag
);
/* Trace: DEM_19792_06_08 */
extern FUNC(void, DEM_CODE)Dem_UpdateMonitorActivityRatio(void);
/* Trace: DEM_19792_06_08 */
extern FUNC(void, DEM_CODE)Dem_InitMonitorActivityRatio(void);

#endif /* DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO */

extern FUNC(boolean, Dem_CODE) Dem_GetMalfuntionOnOff(void);

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_SetObdCycle(uint8 LucOperationCycleId);

extern FUNC(void, DEM_CODE) Dem_ClearObdInfomation(void);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21( uint8* PID21value );
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31( uint8* PID31value );
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D( uint8* PID4Dvalue );
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E( uint8* PID4Evalue );

extern FUNC(void, DEM_CODE) Dem_CalcReadinessPIDValue(
  VAR(uint8, DEM_VAR) LucPIDType,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue,
  VAR(uint8, DEM_VAR) LusByteValue,
  VAR(uint8, DEM_VAR) LucOBDReadinessGrp);

#if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO))
extern FUNC(uint32, DEM_CODE) Dem_GetOffSetOfPidData(void);
#endif /*(DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)*/

/* Dem_DcmGetInfoTypeValue79 */
/* Trace: DEM_19792_06_16 */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue79(
  VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DataValueBuffer);

#if (DEM_J1979_2_OBD_ON_UDS == STD_ON)
/* Dem_DcmGetInfoTypeValue79 */
/* Trace: DEM_19792_06_16 */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR(
  VAR(uint16, DEM_VAR) DTRId,
  VAR(sint32, DEM_VAR) TestResult,
  VAR(sint32, DEM_VAR) LowerLimit,
  VAR(sint32, DEM_VAR) UpperLimit,
  Dem_DTRControlType Ctrlval);
#endif /* J19792 */
#endif

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_INDICATOR_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


