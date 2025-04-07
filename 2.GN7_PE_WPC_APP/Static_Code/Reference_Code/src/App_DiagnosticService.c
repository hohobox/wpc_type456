/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  FILE NAME : App_DiagnosticService.c                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the API definitions for SW-C Sample of Dcm **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.0.0   04-Jul-2022   N/A          Following latest HKMC policy          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_SWC_DiagnosticService.h"
#include "HwResource.h"
#include "Mcu.h"
#if defined(RTE_E_SecurityAccess_L9_E_NOT_OK)
#include "HKMC_ASK_Server.h"
#endif

#if defined(RTE_E_SecurityAccess_L10_E_NOT_OK)
#include "Csm_Version.h"

#include "EcuInfo.h" /* WPC_2411_01 */
#include "App_NvM.h"
#endif



/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define APPDCM_AC 0x0A
#define APPDCM_RPM_HIGH 0x07
#define APPDCM_RPM_LOW 0x50


/* Generate Seed from random generator */
#if (defined(Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart) || \
     defined(Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart) || \
   defined(Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed) || \
   defined(Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed))
#define APPDCM_HAE_PSEUDO_ENTROPY_LENGTH 16U
#endif

#if (defined(RTE_E_SecurityAccess_L1_E_NOT_OK) || \
     defined(RTE_E_SecurityAccess_L9_E_NOT_OK) || \
     defined(RTE_E_SecurityAccess_L10_E_NOT_OK))
uint8 AppDcm_GaaRandomNum[8];
#endif

#if !defined(RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK)
#define RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK 0x00
#endif

// uint8 AppDcm_GucEcuIsBusy = 0U;
// uint8 AppDcm_GucActualtorValue = APPDCM_AC;
// uint8 AppDcm_GaaVIN[17];
// uint8 AppDcm_GaaRPM[] = {APPDCM_RPM_HIGH,APPDCM_RPM_LOW};
// uint8 AppDcm_GaaECT[] = {0xA6U};
// uint8 AppDcm_GaaBatVolt[] = {0x8CU};
// uint8 AppDcm_GaaWriteData[255];
uint8 AppDcm_GucSID = 0U;
uint8 AppDcm_GucReqType = 0U;
uint16 AppDcm_GusSourceAddress = 0U;
uint16 AppDcm_GusDataSize = 0U;
Dcm_ConfirmationStatusType AppDcm_GddConfirmationStatus = 0U;

static uint8 sbDiagSessionChange_ExtendToDefault = OFF;              /* Extended -> Default : ON(1) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define SWC_DiagnosticService_START_SEC_CODE
#include "SWC_DiagnosticService_MemMap.h"
/*******************************************************************************
** Function Name        : AppDcm_DiagnosticSessionControlNotification         **
**                                                                            **
** Description          : This function notifies session transition.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void,SWC_DiagnosticService_CODE)
  AppDcm_DiagnosticSessionControlNotification(void)
{
  Rte_ModeType_DcmDiagnosticSessionControl LddPrevMode;
  Rte_ModeType_DcmDiagnosticSessionControl LddNextMode;

  Rte_Mode_modeNotificationPort_SessionControl_DcmDiagnosticSessionControl(&LddPrevMode, &LddNextMode);
  
  if((LddPrevMode == DCM_EXTENDED_DIAGNOSTIC_SESSION) &&  /* Old Mode  == Extended ? */
     (LddNextMode == DCM_DEFAULT_SESSION))                /* Next(Now) Mode == Default ? */
  {
    sbDiagSessionChange_ExtendToDefault = ON;           /* Extended -> Default : ON(1) */
  }
  else
  {
    sbDiagSessionChange_ExtendToDefault = OFF;
  }
    
}

/*******************************************************************************
** Function Name        : AppDcm_StartProtocol                                **
**                                                                            **
** Description          : This function notifies the start of a particular    **
**                        protocol.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ProtocolID                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_CallbackDCMRequestServices_E_NOT_OK :                            **
**     Request was not successful                                             **

**   - RTE_E_CallbackDCMRequestServices_E_PROTOCOL_NOT_ALLOWED : conditions in**
**     conditions in application allows no further procession of protocol     **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) AppDcm_StartProtocol(
  IN Dcm_ProtocolType ProtocolID)
{
  Std_ReturnType LddRetVal = RTE_E_OK;

  return LddRetVal;
}

/*******************************************************************************
** Function Name        : AppDcm_StopProtocol                                 **
**                                                                            **
** Description          : This function notifies the stop of a particular     **
**                        protocol.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ProtocolID                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_CallbackDCMRequestServices_E_NOT_OK :                            **
**     Request was not successful                                             **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) AppDcm_StopProtocol(
  IN Dcm_ProtocolType ProtocolID)
{
  Std_ReturnType LddRetVal = RTE_E_OK;

  return LddRetVal;
}

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_ActuatorControl           **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ConditionCheckRead_ActuatorControl(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_ActuatorControl_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_FreezeCurrentState_ActuatorControl           **
// **                                                                            **
// ** Description          : This function requests to the application to freeze **
// **                        the current state of an IOControl.                  **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_FreezeCurrentState_ActuatorControl(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_ActuatorControl_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_ActuatorControl                     **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_ActuatorControl(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = AppDcm_GucActualtorValue;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_WriteData_ActuatorControl                    **
// **                                                                            **
// ** Description          : This function requests the application to write     **
// **                        a data value of a DID.                              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - Data : Buffer containing the data to be written                          **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_WriteData_ActuatorControl(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_ActuatorControl_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     AppDcm_GucActualtorValue = Data[0];

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ResetToDefault_ActuatorControl               **
// **                                                                            **
// ** Description          : This function requests to the application to reset  **
// **                        an IOControl to default value.                      **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ResetToDefault_ActuatorControl(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_ActuatorControl_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     AppDcm_GucActualtorValue = APPDCM_AC;

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReturnControlToECU_ActuatorControl           **
// **                                                                            **
// ** Description          : This function requests to the application to return **
// **                        control to ECU of an IOControl.                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReturnControlToECU_ActuatorControl(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U != AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucActualtorValue = APPDCM_AC;

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }
//   else
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_ActuatorControl_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ShortTermAdjustment_ActuatorControl          **
// **                                                                            **
// ** Description          : This function requests to the application to adjust **
// **                        the IO signal.                                      **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - ControlOptionRecord : ControlState information contained in the          **
// **   ControlOptionRecord parameter of the InputOutputControlByIdentifier      **
// **   diagnostic request                                                       **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ActuatorControl_E_NOT_OK :                          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ShortTermAdjustment_ActuatorControl(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ControlOptionRecord,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_ActuatorControl_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     AppDcm_GucActualtorValue = ControlOptionRecord[0];

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_IsDidAvailable_DID_0100h_0110h               **
// **                                                                            **
// ** Description          : This function requests if a specific DID is         **
// **                        available within the range or not.                  **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - DID : DID value                                                          **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - supported : Indicate if the DID is available within the range.           **
// **   - 1 : it is supported within the range                                   **
// **   - 0 : it is not supported within the range                               **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK :                **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_IsDidAvailable_DID_0100h_0110h(
//   IN uint16 DID,
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) supported)
// {
//   Std_ReturnType LddRetVal;

//   if((DID >= 0x0100) && (DID <= 0x0109))
//   {
//     LddRetVal = RTE_E_OK;
//     *supported = 1U;
//   }
//   else
//   {
//     LddRetVal = RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK;
//     *supported = 0U;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadDidData_DID_0100h_0110h                  **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Asynchronous                                        **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - DID : DID value                                                          **
// ** - OpStatus : Status of the current operation                               **
// **   - DCM_INITIAL : Indicates the initial call to the operation              **
// **   - DCM_PENDING : Indicates that a pending return has been done on         **
// **                   the previous call of the operation                       **
// **   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
// **                  the pending operation                                     **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// ** - DataLength : Length of the data to be read                               **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK :                **
// **     Request was not successful                                             **
// **   - RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_DCM_E_PENDING :           **
// **     Request is not yet finished, Further call required to finish           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadDidData_DID_0100h_0110h(
//   IN uint16 DID,
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   IN Dcm_OpStatusType OpStatus,
//   OUT P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DataLength,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   LddRetVal = RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK;

//   switch(DID)
//   {
//   case 0x0100:
//     *DataLength = 1U;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//     break;

//   case 0x0101:
//     *DataLength = 27U;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//     break;

//   case 0x0102:
//     *DataLength = 1U;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//     break;

//   case 0x0103:
//     *DataLength = 5U;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//     break;

//   case 0x0104:
//     *DataLength = 0U;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//     break;

//   default:
//     *DataLength = 0U;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//     break;
//   }

//   if(0U != *DataLength)
//   {
//     uint16 iteratorData;
//     for(iteratorData = 0U; iteratorData < *DataLength; iteratorData++)
//     {
//       Data[iteratorData] = iteratorData + 1U;
//     }

//     LddRetVal = RTE_E_OK;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_WriteDidData_DID_0100h_0110h                 **
// **                                                                            **
// ** Description          : This function requests the application to write     **
// **                        a data value of a DID.                              **
// **                                                                            **
// ** Sync/Async           : Asynchronous                                        **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - DID : DID value                                                          **
// ** - Data : Buffer containing the data to be written                          **
// ** - OpStatus : Status of the current operation                               **
// **   - DCM_INITIAL : Indicates the initial call to the operation              **
// **   - DCM_PENDING : Indicates that a pending return has been done on         **
// **                   the previous call of the operation                       **
// **   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
// **                  the pending operation                                     **
// ** - DataLength : Length of the data to be written                            **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK :                **
// **     Request was not successful                                             **
// **   - RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_DCM_E_PENDING :           **
// **     Request is not yet finished, Further call required to finish           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_WriteDidData_DID_0100h_0110h(
//   IN uint16 DID,
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   IN Dcm_OpStatusType OpStatus,
//   IN uint16 DataLength,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;
//   uint16 iteratorData;

//   LddRetVal = RTE_E_DataServices_DIDRange_DIDs_0100h_0110h_E_NOT_OK;

//   switch(DID)
//   {
//   case 0x0100:/* no break */

//   case 0x0101:/* no break */

//   case 0x0102:/* no break */

//   case 0x0103:
//     for(iteratorData = 0U; iteratorData < DataLength; iteratorData++)
//     {
//       AppDcm_GaaWriteData[iteratorData] = Data[iteratorData];
//     }

//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//     LddRetVal = RTE_E_OK;
//     break;

//   case 0x0104:
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//     break;

//   case 0x0110:
//     *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
//     break;

//   default:
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//     break;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_SystemSupplierECUHardware **
// **                        VersionNumber                                       **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_SystemSupplierECUHardwareVersionNumber_E_NOT_OK :   **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE)
//   AppDcm_ConditionCheckRead_SystemSupplierECUHardwareVersionNumber(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_SystemSupplierECUHardwareVersion    **
// **                        Number                                              **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_SystemSupplierECUHardwareVersionNumber_E_NOT_OK :   **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE)
//   AppDcm_ReadData_SystemSupplierECUHardwareVersionNumber(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = 0x00U;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_SystemSupplierECUSoftware **
// **                        Number                                              **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_SystemSupplierECUSoftwareNumber_E_NOT_OK :          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE)
//   AppDcm_ConditionCheckRead_SystemSupplierECUSoftwareNumber(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_SystemSupplierECUSoftwareNumber     **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_SystemSupplierECUSoftwareNumber_E_NOT_OK :          **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_SystemSupplierECUSoftwareNumber(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = 0x00U;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_VehicleManufacturerECU    **
// **                        SoftwareVersionNumber                               **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VehicleManufacturerECUSoftwareVersionNumber_E_NOT_OK**
// **     : Request was not successful                                           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE)
//   AppDcm_ConditionCheckRead_VehicleManufacturerECUSoftwareVersionNumber(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_VehicleManufacturerECUSoftware      **
// **                        VersionNumber                                       **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VehicleManufacturerECUSoftwareVersionNumber_E_NOT_OK**
// **     : Request was not successful                                           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE)
//   AppDcm_ReadData_VehicleManufacturerECUSoftwareVersionNumber(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = 0x00U;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_VehicleSpeed              **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VehicleSpeed_E_NOT_OK : Request was not successful  **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ConditionCheckRead_VehicleSpeed(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_GetScalingInformation_VehicleSpeed           **
// **                                                                            **
// ** Description          : This function requests to the application           **
// **                        for the scaling information of a Data.              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ScalingInfo : caling information (scalingByte and scalingByteExtension)  **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VehicleSpeed_E_NOT_OK : Request was not successful  **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetScalingInformation_VehicleSpeed(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) ScalingInfo,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   /*
//     s#1 {unsigned numeric, 1 data byte}        0x01
//     s#2 {formula, 5 data bytes}                0x95
//     e#2 [byte#1] {formulaIdentifier=C0*x+C1}   0x00
//     e#2 [byte#2] {C0 high byte}                0xE0
//     e#2 [byte#3] {C0 low byte}[C0=75*10P-2P]   0x4B
//     e#2 [byte#4] {C1 high byte}                0x00
//     e#2 [byte#5] {C1 low byte}[C1=30*10P0P]    0x1E
//     s#3 {unit / format, 1 data byte}           0xA1
//     e#3 [byte#1]  {unit ID, km/h}              0x30
//   */

//   ScalingInfo[0] = (uint8)0x01U;
//   ScalingInfo[1] = (uint8)0x95U;
//   ScalingInfo[2] = (uint8)0x00U;
//   ScalingInfo[3] = (uint8)0xE0U;
//   ScalingInfo[4] = (uint8)0x4BU;
//   ScalingInfo[5] = (uint8)0x00U;
//   ScalingInfo[6] = (uint8)0x1EU;
//   ScalingInfo[7] = (uint8)0xA1U;
//   ScalingInfo[8] = (uint8)0x30U;

//   LddRetVal = RTE_E_OK;
//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_VehicleSpeed                        **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VehicleSpeed_E_NOT_OK : Request was not successful  **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_VehicleSpeed(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = 0x00U;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_RequestResults_CalibrationActuator           **
// **                                                                            **
// ** Description          : This function requests to the application the result**
// **                        of a routine execution.                             **
// **                                                                            **
// ** Sync/Async           : Asynchronous                                        **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - OpStatus : Status of the current operation                               **
// **   - DCM_INITIAL : Indicates the initial call to the operation              **
// **   - DCM_PENDING : Indicates that a pending return has been done on         **
// **                   the previous call of the operation                       **
// **   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
// **                  the pending operation                                     **
// **   - DCM_FORCE_RCRRP_OK : Confirm a response pending transmission           **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - DataOut1 : Fixed-length Output data to provide in the routine control    **
// **              response                                                      **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_E_NOT_OK :         **
// **     Request was not successful                                             **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_PENDING :    **
// **     Request is not yet finished, Further call required to finish           **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_FORCE_RCRRP :**
// **     application request the transmission of a response Response Pending
//   **
// **     (NRC 0x78)                                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_RequestResults_CalibrationActuator(
//   IN Dcm_OpStatusType OpStatus,
//   OUT P2VAR(RequestDataOutType_RID_0200h_CalibrationActuator_routineStatus_ResOutSignal, AUTOMATIC, RTE_APPL_DATA) DataOut1,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;
//   DataOut1[0] = 0x71U;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_Start_CalibrationActuator                    **
// **                                                                            **
// ** Description          : This function requests to the application to start  **
// **                        the execution of a routine.                         **
// **                                                                            **
// ** Sync/Async           : Asynchronous                                        **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - DataIn1 : Fixed-length input data provided in the routine control request**
// ** - OpStatus : Status of the current operation                               **
// **   - DCM_INITIAL : Indicates the initial call to the operation              **
// **   - DCM_PENDING : Indicates that a pending return has been done on         **
// **                   the previous call of the operation                       **
// **   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
// **                  the pending operation                                     **
// **   - DCM_FORCE_RCRRP_OK : Confirm a response pending transmission           **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - DataOut1 : Fixed-length Output data to provide in the routine control    **
// **              response                                                      **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_E_NOT_OK :         **
// **     Request was not successful                                             **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_PENDING :    **
// **     Request is not yet finished, Further call required to finish           **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_FORCE_RCRRP :**
// **     application request the transmission of a response Response Pending
//   **
// **     (NRC 0x78)                                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_Start_CalibrationActuator(
//   IN StartDataInType_RID_0200h_CalibrationActuator_routineControlOption_StartInSignal DataIn1,
//   IN Dcm_OpStatusType OpStatus,
//   OUT P2VAR(StartDataOutType_RID_0200h_CalibrationActuator_routineStatus_StartOutSignal, AUTOMATIC, RTE_APPL_DATA) DataOut1,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;
//   DataOut1[0] = DataIn1;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_Stop_CalibrationActuator                     **
// **                                                                            **
// ** Description          : This function requests to the application to stop   **
// **                        the execution of a routine.                         **
// **                                                                            **
// ** Sync/Async           : Asynchronous                                        **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - DataIn1 : Fixed-length input data provided in the routine control request**
// ** - OpStatus : Status of the current operation                               **
// **   - DCM_INITIAL : Indicates the initial call to the operation              **
// **   - DCM_PENDING : Indicates that a pending return has been done on         **
// **                   the previous call of the operation                       **
// **   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
// **                  the pending operation                                     **
// **   - DCM_FORCE_RCRRP_OK : Confirm a response pending transmission           **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - DataOut1 : Fixed-length Output data to provide in the routine control    **
// **              response                                                      **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_E_NOT_OK :         **
// **     Request was not successful                                             **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_PENDING :    **
// **     Request is not yet finished, Further call required to finish           **
// **   - RTE_E_RoutineServices_RID_0200h_CalibrationActuator_DCM_E_FORCE_RCRRP :**
// **     application request the transmission of a response Response Pending
//   **
// **     (NRC 0x78)                                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_Stop_CalibrationActuator(
//   IN StopDataInType_RID_0200h_CalibrationActuator_DcmDspRoutineStopInSignal0 DataIn1,
//   IN Dcm_OpStatusType OpStatus,
//   OUT P2VAR(StopDataInType_RID_0200h_CalibrationActuator_DcmDspRoutineStopInSignal0, AUTOMATIC, RTE_APPL_DATA) DataOut1,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;
//   DataOut1[0] = DataIn1;

//   return LddRetVal;
// }

/*******************************************************************************
** Function Name        : AppDcm_GetRandomSeed                                **
**                                                                            **
** Description          : This function shall offer user random seed for      **
**                        SW PRNG Entropy. This function is used when HSM     **
**                        is not applied                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : RandomSeed[]                                        **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - E_OK : Success generate User RandomSeed                                **
**   - E_NOT_OK : Fail generate User RandomSeed                               **
**                                                                            **
*******************************************************************************/
#if (defined(Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart) || \
     defined(Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart) || \
   defined(Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed) || \
   defined(Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed) || \
   defined(Rte_Call_HaeHsmRandomGenerate_L9_CsmRandomGenerateConfig_RandomGenerate))

FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetRandomSeed(
  P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) RandomSeed)
{
  Std_ReturnType RetVal = E_NOT_OK;

  /*
  * Apply user RandomSeed to the argument in this function.
  * RandomSeed is a 16-row array. (RandomSeed[16])
  * Assign a random number to this variable (RandomSeed)
  * ex) current time, tick count, event timer, ADC noise, sensor value, etc..
  */

  /*
  * If you apply RandomSeed, you must return E_OK.
  * E_OK : Use the user RandomSeed
  * E_NOT_OK : Fail to use RandomSeed
  */
 
  /* Example of SPC58x RandomSeed.
   * This code is an example and is not guaranteed and should be used only for reference.
   * OS tick address is different for each MCU
   *
   *
   * uint32 LulSeed, LulSeedAddr, LulNoise;
   * uint8 LucIndex;
   *
   * LulSeedAddr = 0xF4070004; // Address of SPC58x OS Tick
   * LulSeed=(*(volatile uint32*)LulSeedAddr);
   *
   * for(LucIndex=0; LucIndex<APPDCM_HAE_PSEUDO_ENTROPY_LENGTH; LucIndex++)
   * {
   *   LulSeed = (uint32)((LulSeed * 1103515245 + 12345)>>16) & 0xFF;
   *   RandomSeed[LucIndex] = (uint8)(LulSeed + LulNoise);
   * }
   *
   *  RetVal = E_OK;
   *
   */

//  #ifdef INSTST_TESTCODE_INTEGRATED
  /* Only Classic AUTOSAR Team Integration Test*/
  RetVal = E_OK;
//  #endif

  return RetVal;
}
#endif

#if (defined(RTE_E_SecurityAccess_L1_E_NOT_OK) && \
     defined(RTE_E_SecurityAccess_L9_E_NOT_OK))
#error 'SeedKey and AdvSeedKey can not be used at the same time by HKMC Policy. Choose only 1 SeedKey Algorithm'
/*******************************************************************************
** Function Name        : AppDcm_GetSeed_L1                                   **
**                                                                            **
** Description          : Request to application for asynchronous provision of**
**                        seed value.                                         **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - OpStatus : Status of the current operation                               **
**   - DCM_INITIAL : Indicates the initial call to the operation              **
**   - DCM_PENDING : Indicates that a pending return has been done on         **
**                   the previous call of the operation                       **
**   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
**                  the pending operation                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    :                                                     **
** - Seed : Pointer for provided seed                                         **
** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
**   shall send a negative response with NRC code equal to the parameter      **
**   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_SecurityAccess_L1_E_NOT_OK : Request was not successful          **
**   - RTE_E_SecurityAccess_L1_DCM_E_PENDING :                                **
**     Request is not yet finished, Further call required to finish           **
**                                                                            **
*******************************************************************************/
#elif defined(RTE_E_SecurityAccess_L1_E_NOT_OK)
FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetSeed_L1(
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L1_E_NOT_OK;
  uint32 resultLength = 4UL; /* L1 SeedKey Length is 4-byte*/

  #if defined(Rte_Call_AutHsmPseudoRandomGenerate_L1_RandomGenerate)
  /* Case 1. Random Generate with TRNG + PRNG : Autron HSM 1.0 */
  if (RTE_E_OK == Rte_Call_AutHsmPseudoRandomGenerate_L1_RandomGenerate(&AppDcm_GaaRandomNum[0], resultLength))
  #elif defined(Rte_Call_HaeHsmPseudoRandomGenerate_L1_RandomGenerate)
  /* Case 2. Random Generate with TRNG + PRNG : HAE HSM 2.0 */
  if (RTE_E_OK == Rte_Call_HaeHsmPseudoRandomGenerate_L1_RandomGenerate(&AppDcm_GaaRandomNum[0], resultLength))
  #elif ((defined(Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart)) || \
     (defined(Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed))) /* R44 Csm */
  /* Case 3. Random Generate with SW PRNG : HAE CryptoLib */
  volatile static boolean LblRandomSeedUpdated = FALSE;
  if (FALSE == LblRandomSeedUpdated)
  {
    uint8 LaaHaeHacSalt_L1[APPDCM_HAE_PSEUDO_ENTROPY_LENGTH] = {0U};

    /* Get User RandomSeed */
    if (E_OK == AppDcm_GetRandomSeed(LaaHaeHacSalt_L1))
    {
      /* Update RandomSeed */
      #if defined(Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart) /* R40 Csm */
      if (RTE_E_OK == Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart())
      {
        if (RTE_E_OK == Rte_Call_HaePseudoRandomSeed_L1_RandomSeedUpdate(LaaHaeHacSalt_L1, APPDCM_HAE_PSEUDO_ENTROPY_LENGTH))
        {
          if (RTE_E_OK == Rte_Call_HaePseudoRandomSeed_L1_RandomSeedFinish())
          {
            LblRandomSeedUpdated = TRUE;
          }
        }
      }
      #elif defined(Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed)
      if (RTE_E_OK == Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed(LaaHaeHacSalt_L1, APPDCM_HAE_PSEUDO_ENTROPY_LENGTH))
      {
        LblRandomSeedUpdated = TRUE;
      }
      #endif
    }
  }
  if ((TRUE == LblRandomSeedUpdated) &&
  #if (defined(Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart))
      (RTE_E_OK == Rte_Call_HaePseudoRandomGenerate_L1_RandomGenerate(&AppDcm_GaaRandomNum[0], resultLength)))
  #elif (defined(Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed))
    (RTE_E_OK == Rte_Call_CsmRandomGenerate_L1_RandomGenerate(&AppDcm_GaaRandomNum[0], &resultLength)))
  #endif

  #else
  #error 'Not found Csm Random Generate Configuration. Please make random number in AppDcm_GaaRandomNum[] by yourself'
  #endif
  {
    uint8 LucIndex;
    for (LucIndex = 0U; LucIndex < resultLength; LucIndex++)
    {
      Seed[LucIndex] = AppDcm_GaaRandomNum[LucIndex];
    }
    LddRetVal = RTE_E_OK;
  }
  #if (defined(Rte_Call_HaePseudoRandomSeed_L1_RandomSeedStart) || \
     defined(Rte_Call_CsmKeyManagement_RandomSeed_L1_RandomSeed))
  else
  {
    LblRandomSeedUpdated = FALSE;
  }
  #endif

  if (RTE_E_OK != LddRetVal)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return LddRetVal;
}



/*******************************************************************************
** Function Name        : AppDcm_CompareKey_L1                                **
**                                                                            **
** Description          : Request to application for asynchronous comparing   **
**                        key.                                                **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - Key : Key, which needs to be compared                                    **
** - OpStatus : Status of the current operation                               **
**   - DCM_INITIAL : Indicates the initial call to the operation              **
**   - DCM_PENDING : Indicates that a pending return has been done on         **
**                   the previous call of the operation                       **
**   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
**                  the pending operation                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_SecurityAccess_L1_E_NOT_OK : Request was not successful          **
**   - RTE_E_SecurityAccess_L1_DCM_E_PENDING :                                **
**     Request is not yet finished, Further call required to finish           **
**   - RTE_E_SecurityAccess_L1_DCM_E_COMPARE_KEY_FAILED : Key did not match   **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) AppDcm_CompareKey_L1(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
  IN Dcm_OpStatusType OpStatus)
{
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L1_E_NOT_OK;

  /*
  * Apply user Key Generate Algorithm in this function
  * Input Random Number : AppDcm_GaaRandomNum[4]
  * Expected Output : Key[4]
  *
  
* This Key Generate Algorithm must be same as Diagnositic Server .c or dll file.
  * If you use MCRT or H_OTA, you need to create .dll file which is the same logic of this function
  * AutSeedKey should not be applied by HKMC Policy
  *
  * Step
  *  1) Generate Key by using AppDcm_GaaRandomNum.

  *  2) If Key Generate Success, LddRetVal = RTE_E_OK.
  *  3) If generated Key is not matched to received key, 
  *      RTE_E_SecurityAccess_L1_DCM_E_COMPARE_KEY_FAILED shall be retrun.
  */
  
  #ifdef INSTST_TESTCODE_INTEGRATED
  /* Only Classic AUTOSAR Team Integration Test*/
  LddRetVal = RTE_E_OK;
  #endif

  return LddRetVal;
}

/*******************************************************************************
** Function Name        : AppDcm_GetSeed_L9                                   **
**                                                                            **
** Description          : Request to application for asynchronous provision of**
**                        seed value.                                         **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - OpStatus : Status of the current operation                               **
**   - DCM_INITIAL : Indicates the initial call to the operation              **
**   - DCM_PENDING : Indicates that a pending return has been done on         **
**                   the previous call of the operation                       **
**   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
**                  the pending operation                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    :                                                     **
** - Seed : Pointer for provided seed                                         **
** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
**   shall send a negative response with NRC code equal to the parameter      **
**   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_SecurityAccess_L9_E_NOT_OK : Request was not successful          **
**   - RTE_E_SecurityAccess_L9_DCM_E_PENDING :                                **
**     Request is not yet finished, Further call required to finish           **
**                                                                            **
*******************************************************************************/
#elif defined(RTE_E_SecurityAccess_L9_E_NOT_OK)
FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetSeed_L9(
  IN Dcm_OpStatusType OpStatus,
  OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L9_E_NOT_OK;
  uint32 resultLength = 8UL; /* L1 SeedKey Length is 4-byte*/

  #if defined(Rte_Call_AutHsmPseudoRandomGenerate_L9_RandomGenerate)
  /* Case 1. Random Generate with HSM PRNG (TRNG + SW PRNG) : Autron HSM 1.0 */
  if (RTE_E_OK == Rte_Call_AutHsmPseudoRandomGenerate_L9_RandomGenerate(&AppDcm_GaaRandomNum[0], resultLength))
  #elif defined(Rte_Call_HaeHsmPseudoRandomGenerate_L9_RandomGenerate)
  /* Case 2. Random Generate with HSM PRNG (TRNG + SW PRNG) : HAE HSM 2.0 */
  #elif defined(Rte_Call_HaeHsmRandomGenerate_L9_CsmRandomGenerateConfig_RandomGenerate)
  if (RTE_E_OK == Rte_Call_HaeHsmRandomGenerate_L9_CsmRandomGenerateConfig_RandomGenerate(&AppDcm_GaaRandomNum[0], &resultLength))
  /* Case 3. Random Generate with SW PRNG : HAE CryptoLib */
  #elif ((defined(Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart)) || \
     (defined(Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed))) /* R44 Csm */
  volatile static boolean LblRandomSeedUpdated = FALSE;
  
  if (FALSE == LblRandomSeedUpdated)
  {
    uint8 LaaHaeHacSalt_L9[APPDCM_HAE_PSEUDO_ENTROPY_LENGTH] = {0U};

    /* Get User RandomSeed */
    if (E_OK == AppDcm_GetRandomSeed(LaaHaeHacSalt_L9))
    {
      /* Update RandomSeed */
      #if defined(Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart)
      if (RTE_E_OK == Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart())
      {
        if (RTE_E_OK == Rte_Call_HaePseudoRandomSeed_L9_RandomSeedUpdate(LaaHaeHacSalt_L9, APPDCM_HAE_PSEUDO_ENTROPY_LENGTH))
        {
          if (RTE_E_OK == Rte_Call_HaePseudoRandomSeed_L9_RandomSeedFinish())
          {
            LblRandomSeedUpdated = TRUE;
          }
        }
      }
      #elif defined(Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed)
      if (RTE_E_OK == Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed(LaaHaeHacSalt_L9, APPDCM_HAE_PSEUDO_ENTROPY_LENGTH))
      {
        LblRandomSeedUpdated = TRUE;
      }
      #endif
    }
  }
  if ((TRUE == LblRandomSeedUpdated) &&
  #if (defined(Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart))
      (RTE_E_OK == Rte_Call_HaePseudoRandomGenerate_L9_RandomGenerate(&AppDcm_GaaRandomNum[0], resultLength)))
  #elif (defined(Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed))
    (RTE_E_OK == Rte_Call_RandomGenerate_L9_CsmRandomGenerateConfig_RandomGenerate(&AppDcm_GaaRandomNum[0], &resultLength)))
  #elif (defined(Rte_Call_HaeHsmRandomGenerate_L9_CsmRandomGenerateConfig_RandomGenerate))
    (RTE_E_OK == Rte_Call_HaeHsmRandomGenerate_L9_CsmRandomGenerateConfig_RandomGenerate(&AppDcm_GaaRandomNum[0], &resultLength)))
  #endif
  #else
  #error 'Not found Csm Random Generate Configuration. Please make random number in AppDcm_GaaRandomNum[] by yourself'
  #endif
  {
    uint8 LucIndex;
    for (LucIndex = 0U; LucIndex < resultLength; LucIndex++)
    {
      Seed[LucIndex] = AppDcm_GaaRandomNum[LucIndex];
    }
    LddRetVal = RTE_E_OK;
  }
  #if (defined(Rte_Call_HaePseudoRandomSeed_L9_RandomSeedStart) || \
       defined(Rte_Call_CsmKeyManagement_RandomSeed_L9_RandomSeed))
  else
  {
    LblRandomSeedUpdated = FALSE;
  }
  #endif  

  if (RTE_E_OK != LddRetVal)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

  return LddRetVal;
}

/*******************************************************************************
** Function Name        : AppDcm_CompareKey_L9                                **
**                                                                            **
** Description          : Request to application for asynchronous comparing   **
**                        key.                                                **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - Key : Key, which needs to be compared                                    **
** - OpStatus : Status of the current operation                               **
**   - DCM_INITIAL : Indicates the initial call to the operation              **
**   - DCM_PENDING : Indicates that a pending return has been done on         **
**                   the previous call of the operation                       **
**   - DCM_CANCEL : Indicates that the DCM requests to cancel                 **
**                  the pending operation                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_SecurityAccess_L9_E_NOT_OK : Request was not successful          **
**   - RTE_E_SecurityAccess_L9_DCM_E_PENDING :                                **
**     Request is not yet finished, Further call required to finish           **
**   - RTE_E_SecurityAccess_L9_DCM_E_COMPARE_KEY_FAILED : Key did not match   **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) AppDcm_CompareKey_L9(
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
  IN Dcm_OpStatusType OpStatus)
{
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L9_E_NOT_OK;
  uint8 LaaKey[8] = {0U, };
  
  /* Call ASK library Key Generate API SEEDKEY_SUCCESS */
  if (SEEDKEY_SUCCESS == ASK_KeyGenerate(&AppDcm_GaaRandomNum[0], &LaaKey[0]))
  {
    uint8 LucIndex;
    /* Compare generated Key & received Key*/
    for (LucIndex = 0U; LucIndex < 8U; LucIndex++)
    {
      if (LaaKey[LucIndex] != Key[LucIndex])
      {
        break;
      }
    }
    if (LucIndex == 8U)
    {
      /* key matches */
      LddRetVal = RTE_E_OK;
    }
    else
    {
      /* key does not match */
      LddRetVal = RTE_E_SecurityAccess_L9_DCM_E_COMPARE_KEY_FAILED;
    }
  }

  return LddRetVal;
}
#endif 


// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_VINDataIdentifier         **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VINDataIdentifier_E_NOT_OK :                        **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ConditionCheckRead_VINDataIdentifier(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_VINDataIdentifier                   **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VINDataIdentifier_E_NOT_OK :                        **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_VINDataIdentifier(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   uint16 iteratorData;

//   for(iteratorData = 0U; iteratorData < 17U; iteratorData++)
//   {
//     Data[iteratorData] = iteratorData + 1U;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_WriteData_VINDataIdentifier                  **
// **                                                                            **
// ** Description          : This function requests the application to write     **
// **                        a data value of a DID.                              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - Data : Buffer containing the data to be written                          **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VINDataIdentifier_E_NOT_OK :                        **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_WriteData_VINDataIdentifier(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;
//   uint16 iteratorData;

//   if(Data[0] == 0x57U) /* 0x57 = 'W' */
//   {
//     for(iteratorData = 0U; iteratorData < 17U; iteratorData++)
//     {
//       AppDcm_GaaVIN[iteratorData] = Data[iteratorData];
//     }

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }
//   else
//   {
//     LddRetVal = RTE_E_DataServices_VINDataIdentifier_E_NOT_OK;
//     *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_GetScalingInformation_VINDataIdentifier      **
// **                                                                            **
// ** Description          : This function requests to the application           **
// **                        for the scaling information of a Data.              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ScalingInfo : caling information (scalingByte and scalingByteExtension)  **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_VINDataIdentifier_E_NOT_OK :                        **
// **     Request was not successful                                             **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetScalingInformation_VINDataIdentifier(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) ScalingInfo,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   /*
//     0x6F = scalingByte#1 {ASCII, 15 data bytes}
//     0x62 = scalingByte#2 {ASCII, 2 data bytes}
//   */

//   ScalingInfo[0] = 0x6FU;
//   ScalingInfo[1] = 0x62U;
//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_BatVolt                   **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_BatVolt_E_NOT_OK : Request was not successful       **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ConditionCheckRead_BatVolt(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_BatVolt                             **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_BatVolt_E_NOT_OK : Request was not successful       **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_BatVolt(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = AppDcm_GaaBatVolt[0];

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_WriteData_BatVolt                            **
// **                                                                            **
// ** Description          : This function requests the application to write     **
// **                        a data value of a DID.                              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - Data : Buffer containing the data to be written                          **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_BatVolt_E_NOT_OK : Request was not successful       **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_WriteData_BatVolt(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;
//   AppDcm_GaaBatVolt[0] = Data[0];

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_ECT                       **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ECT_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ConditionCheckRead_ECT(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_ECT                                 **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ECT_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_ECT(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = AppDcm_GaaECT[0];

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_WriteData_ECT                                **
// **                                                                            **
// ** Description          : This function requests the application to write     **
// **                        a data value of a DID.                              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - Data : Buffer containing the data to be written                          **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_ECT_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_WriteData_ECT(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;
//   AppDcm_GaaECT[0] = Data[0];

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ConditionCheckRead_RPM                       **
// **                                                                            **
// ** Description          : This function requests to the application if the    **
// **                        conditions to read the Data are correct.            **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_RPM_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ConditionCheckRead_RPM(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReadData_ECT                                 **
// **                                                                            **
// ** Description          : This function requests to the application a data    **
// **                        value of a DID.                                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - Data : Buffer where the requested data shall be copied to                **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_RPM_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReadData_RPM(
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   Data[0] = AppDcm_GaaRPM[0];
//   Data[1] = AppDcm_GaaRPM[1];

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_WriteData_RPM                                **
// **                                                                            **
// ** Description          : This function requests the application to write     **
// **                        a data value of a DID.                              **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - Data : Buffer containing the data to be written                          **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_RPM_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_WriteData_RPM(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   *ErrorCode = DCM_E_POSITIVERESPONSE;
//   AppDcm_GaaRPM[0] = Data[0];
//   AppDcm_GaaRPM[1] = Data[1];

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_FreezeCurrentState_RPM                       **
// **                                                                            **
// ** Description          : This function requests to the application to freeze **
// **                        the current state of an IOControl.                  **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_RPM_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_FreezeCurrentState_RPM(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_RPM_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ReturnControlToECU_RPM                       **
// **                                                                            **
// ** Description          : This function requests to the application to return **
// **                        control to ECU of an IOControl.                     **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     : None                                                **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_RPM_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ReturnControlToECU_RPM(
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U != AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GaaRPM[0] = APPDCM_RPM_HIGH;
//     AppDcm_GaaRPM[1] = APPDCM_RPM_LOW;

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }
//   else
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_RPM_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }

//   return LddRetVal;
// }

// /*******************************************************************************
// ** Function Name        : AppDcm_ShortTermAdjustment_RPM                      **
// **                                                                            **
// ** Description          : This function requests to the application to adjust **
// **                        the IO signal.                                      **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - ControlOptionRecord : ControlState information contained in the          **
// **   ControlOptionRecord parameter of the InputOutputControlByIdentifier      **
// **   diagnostic request                                                       **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_DataServices_RPM_E_NOT_OK : Request was not successful           **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType, RTE_CODE) AppDcm_ShortTermAdjustment_RPM(
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ControlOptionRecord,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal;

//   if(1U == AppDcm_GucEcuIsBusy)
//   {
//     AppDcm_GucEcuIsBusy = 0U;

//     LddRetVal = RTE_E_DataServices_RPM_E_NOT_OK;
//     *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
//   }
//   else
//   {
//     AppDcm_GaaRPM[0] = ControlOptionRecord[0];
//     AppDcm_GaaRPM[1] = ControlOptionRecord[1];

//     LddRetVal = RTE_E_OK;
//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//   }

//   return LddRetVal;
// }

/*******************************************************************************
** Function Name : AppDcm_ApplicationUpdatedIndication                        **
**                                                                            **
** Description : This function notifies Application updated.                  **
**                                                                            **
** Sync/Async : Synchronous                                                   **
**                                                                            **
** Re-entrancy : Non-Reentrant                                                **
**                                                                            **
** Input Parameters : None                                                    **
**                                                                            **
** InOut parameter : None                                                     **
**                                                                            **
** Output Parameters : None                                                   **
**                                                                            **
** Return parameter : None                                                    **
**                                                                            **
*******************************************************************************/
FUNC(void,SWC_DiagnosticService_CODE) AppDcm_ApplicationUpdatedIndication(void)
{
    /* Endter User Code */
}

/*******************************************************************************
** Function Name        : ServiceRequestSupplierNotification_Confirmation     **
**                                                                            **
** Description          : This function notifies the confirmation of          **
**                        diagnostic service.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - SID : Service ID                                                         **
** - ReqType : Rx message address type                                        **
** - SourceAddress : Source address                                           **
** - ConfirmationStatus :                                                     **
**   - DCM_RES_POS_OK : Transmission of positive response was successful      **
**   - DCM_RES_POS_NOT_OK : Transmission of positive response failled         **
**   - DCM_RES_NEG_OK : Transmission of negative response was successful      **
**   - DCM_RES_NEG_NOT_OK : Transmission of negative response failled         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_ServiceRequestNotification_E_NOT_OK : Request was not successful **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) ServiceRequestSupplierNotification_Confirmation(
  IN uint8 SID,
  IN uint8 ReqType,
  IN uint16 SourceAddress,
  IN Dcm_ConfirmationStatusType ConfirmationStatus)
{
  Std_ReturnType LddRetVal = RTE_E_OK;

  AppDcm_GucSID = SID;
  AppDcm_GucReqType = ReqType;
  AppDcm_GusSourceAddress = SourceAddress;
  AppDcm_GddConfirmationStatus = ConfirmationStatus;

  return LddRetVal;
}

// 아래 함수만 App_Uds.c에서 처리함.
// 내부 변수들이 rte로 받아야 하기 때문임.
// /*******************************************************************************
// ** Function Name        : ServiceRequestSupplierNotification_Indication       **
// **                                                                            **
// ** Description          : This function notifies the confirmation of          **
// **                        diagnostic service.                                 **
// **                                                                            **
// ** Sync/Async           : Synchronous                                         **
// **                                                                            **
// ** Re-entrancy          : Non-Reentrant                                       **
// **                                                                            **
// ** Input Parameters     :                                                     **
// ** - SID : Service ID                                                         **
// ** - RequestData : Pointer to received data                                   **
// ** - DataSize : Data length of received data                                  **
// ** - ReqType : Rx message address type                                        **
// ** - SourceAddress : Source address                                           **
// **                                                                            **
// ** InOut parameter      : None                                                **
// **                                                                            **
// ** Output Parameters    :                                                     **
// ** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
// **   shall send a negative response with NRC code equal to the parameter      **
// **   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
// **                                                                            **
// ** Return parameter     :                                                     **
// ** - Std_ReturnType                                                           **
// **   - RTE_E_OK : Request was successful                                      **
// **   - RTE_E_ServiceRequestNotification_E_NOT_OK : Request was not successful **
// **                                                                            **
// *******************************************************************************/
// FUNC(Std_ReturnType,RTE_CODE) ServiceRequestSupplierNotification_Indication(
//   IN uint8 SID,
//   IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData,
//   IN uint16 DataSize,
//   IN uint8 ReqType,
//   IN uint16 SourceAddress,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   Std_ReturnType LddRetVal = RTE_E_OK;

//   AppDcm_GucSID = SID;
//   AppDcm_GusDataSize = DataSize;
//   AppDcm_GucReqType = ReqType;
//   AppDcm_GusSourceAddress = SourceAddress;

//   return LddRetVal;
// }

/*******************************************************************************
** Function Name        : ServiceRequestManufacturerNotification_Confirmation **
**                                                                            **
** Description          : This function notifies the confirmation of          **
**                        diagnostic service.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - SID : Service ID                                                         **
** - ReqType : Rx message address type                                        **
** - SourceAddress : Source address                                           **
** - ConfirmationStatus :                                                     **
**   - DCM_RES_POS_OK : Transmission of positive response was successful      **
**   - DCM_RES_POS_NOT_OK : Transmission of positive response failled         **
**   - DCM_RES_NEG_OK : Transmission of negative response was successful      **
**   - DCM_RES_NEG_NOT_OK : Transmission of negative response failled         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_ServiceRequestNotification_E_NOT_OK : Request was not successful **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) ServiceRequestManufacturerNotification_Confirmation(
  IN uint8 SID,
  IN uint8 ReqType,
  IN uint16 SourceAddress,
  IN Dcm_ConfirmationStatusType ConfirmationStatus)
{
  Std_ReturnType LddRetVal = RTE_E_OK;

  AppDcm_GucSID = SID;
  AppDcm_GucReqType = ReqType;
  AppDcm_GusSourceAddress = SourceAddress;
  AppDcm_GddConfirmationStatus = ConfirmationStatus;

  return LddRetVal;
}

/*******************************************************************************
** Function Name        : ServiceRequestManufacturerNotification_Indication   **
**                                                                            **
** Description          : This function notifies the confirmation of          **
**                        diagnostic service.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     :                                                     **
** - SID : Service ID                                                         **
** - RequestData : Pointer to received data                                   **
** - DataSize : Data length of received data                                  **
** - ReqType : Rx message address type                                        **
** - SourceAddress : Source address                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    :                                                     **
** - ErrorCode : If this operation returns value E_NOT_OK, the Dcm module     **
**   shall send a negative response with NRC code equal to the parameter      **
**   ErrorCode parameter value. (Refer to the Rte_Dcm_Type.h)                 **
**                                                                            **
** Return parameter     :                                                     **
** - Std_ReturnType                                                           **
**   - RTE_E_OK : Request was successful                                      **
**   - RTE_E_ServiceRequestNotification_E_NOT_OK : Request was not successful **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType,RTE_CODE) ServiceRequestManufacturerNotification_Indication(
  IN uint8 SID,
  IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData,
  IN uint16 DataSize,
  IN uint8 ReqType,
  IN uint16 SourceAddress,
  OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  Std_ReturnType LddRetVal = RTE_E_OK;

  AppDcm_GucSID = SID;
  AppDcm_GusDataSize = DataSize;
  AppDcm_GucReqType = ReqType;
  AppDcm_GusSourceAddress = SourceAddress;

  return LddRetVal;
}

FUNC(void, RTE_CODE) ApplicationUpdatedIndication(void)
{
}

#ifdef RTE_E_SecurityAccess_L10_E_NOT_OK
// const uint8 Dcm_GaaPublicKeyData[260] = {
//   /*public key 256 byte*/
//   0xcc, 0x1a, 0x54, 0xf6, 0x52, 0xc2, 0x62, 0x34, 0x01, 0x0d, 0x18, 0xe3, 0xd9, 0xfe, 0x79, 0x5d,
//   0xa2, 0x7d, 0x7a, 0x10, 0xa2, 0x53, 0x14, 0x1a, 0xc9, 0x3b, 0x1a, 0xf5, 0x90, 0x29, 0x49, 0x26,
//   0xc3, 0xe2, 0x0e, 0xb1, 0xb4, 0x7a, 0x25, 0x2b, 0x36, 0x7a, 0xb3, 0xe0, 0xa5, 0x18, 0x9e, 0x58,
//   0x68, 0x91, 0x1e, 0x6d, 0xab, 0x95, 0xd7, 0x44, 0x0d, 0x7b, 0xf0, 0x58, 0xfc, 0x8b, 0x5d, 0x45,
//   0x19, 0xf1, 0x27, 0xee, 0x54, 0x1c, 0xa1, 0x55, 0xd0, 0x45, 0xa4, 0x0d, 0xf6, 0x1a, 0x3b, 0x14,
//   0x84, 0x6e, 0x2e, 0x63, 0x0d, 0xbe, 0xb9, 0x58, 0x76, 0xea, 0x3e, 0x7b, 0xa9, 0xcf, 0xdb, 0xa3,
//   0x42, 0x71, 0x3c, 0x7d, 0xb5, 0x55, 0xd1, 0xc6, 0xa9, 0xb7, 0x33, 0x8d, 0x78, 0xbe, 0xf0, 0x96,
//   0x3f, 0x7d, 0x64, 0x10, 0xa1, 0x92, 0xf2, 0x5c, 0x12, 0x0f, 0xca, 0xdb, 0x02, 0xe2, 0x55, 0xa9,
//   0x18, 0xdd, 0x98, 0x91, 0x51, 0x08, 0xbf, 0xc8, 0x95, 0x22, 0xcc, 0x59, 0x0e, 0xba, 0x13, 0xce,
//   0x39, 0x5d, 0x5a, 0x6f, 0x6f, 0xa9, 0x77, 0x1d, 0x8e, 0x35, 0xab, 0xee, 0x73, 0x04, 0x62, 0x4d,
//   0xbb, 0x79, 0x8c, 0x74, 0x6c, 0xb4, 0xd3, 0xf0, 0x24, 0xf5, 0x32, 0x5b, 0x04, 0xdb, 0xae, 0x3b,
//   0xd2, 0x91, 0xb9, 0x9b, 0xd6, 0x99, 0x7d, 0x51, 0x9b, 0x39, 0x50, 0xa6, 0xb8, 0xa4, 0x53, 0x78,
//   0xaa, 0xd1, 0x54, 0xa5, 0xcc, 0x54, 0xb6, 0x1a, 0xc8, 0x17, 0xea, 0xab, 0x2f, 0x62, 0x9e, 0x13,
//   0x59, 0xae, 0x8b, 0xd1, 0xf8, 0x87, 0x9d, 0x06, 0x7e, 0xed, 0x21, 0x1d, 0x3f, 0x9f, 0xba, 0x2a,
//   0x7d, 0xbb, 0x20, 0x94, 0x33, 0xab, 0x33, 0xa9, 0x54, 0xbd, 0xde, 0xe2, 0xf5, 0xaf, 0xe0, 0x2a,
//   0x71, 0xd3, 0xb8, 0x1e, 0x87, 0x39, 0x46, 0x1a, 0x7a, 0x89, 0xf3, 0x6f, 0x18, 0x6c, 0x2c, 0x55,
//   /*exponent 4 byte*/
//   0x01, 0x00 ,0x01, 0x00
// };

/* 010A_07 */
/* PubKey를 fbl Flash에서 가져다 씀 */
typedef uint8 PubKey_t[260];
volatile const PubKey_t* Dcm_GaaPublicKeyData = (PubKey_t*)0x10057E00; /* .OEUK_PUB_KEY_FLASH 영역 어드레스 */
/* 010A_07 */

#if(CSM_AR_RELEASE_MAJOR_VERSION != CSM_AR_RELEASE_MINOR_VERSION) // Csm_R40
Csm_AsymPublicKeyType Dcm_GaaPublicKey;
#define SIGNATURE_VERIFY_NONE  (0x00U)
#define SIGNATURE_VERIFY_IDLE (0x01U)
#define SIGANTURE_VERIFY_PENDING (0x03)
 
#define SIGNATURE_VERIFY_START (0x01U)
#define SIGNATURE_VERIFY_START_PENDING (0x02U)
#define SIGNATURE_VERIFY_UPDATE (0x03U)
#define SIGNATURE_VERIFY_UPDATE_PENDING (0x04U)
#define SIGNATURE_VERIFY_FINISH (0x05U)
#define SIGNATURE_VERIFY_FINISH_PENDING (0x06U)
#define SIGNTAURE_VERIFY_ERR (0x07U)
 
static uint8 AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_NONE;
static uint8 AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_START;
 
FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetSeed_L10(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
  uint32 resultLength = 8UL;
 
  if (RTE_E_OK == Rte_Call_HaeHsmPseudoRandomGenerate_L10_RandomGenerate(&AppDcm_GaaRandomNum[0], resultLength))
  {
    uint8 LucIndex;
    for(LucIndex = 0U; LucIndex < resultLength; LucIndex++)
    {
      Seed[LucIndex] = AppDcm_GaaRandomNum[LucIndex];
      /* Test Code */
      //AppDcm_GaaRandomNum[LucIndex] = LucIndex+1;
    }
    LddRetVal = RTE_E_OK;
  }
 
  if (RTE_E_OK != LddRetVal)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }
 
  return LddRetVal;
}
 
FUNC(Std_ReturnType, RTE_CODE) AppDcm_CompareKey_L10(
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
  Dcm_OpStatusType OpStatus)
{
  uint32 LucIndex;
  uint32 LaaKeyLength = 260U;
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
  static VAR(Csm_VerifyResultType, DCM_VAR) Dcm_LaaVerifyResult = CSM_E_VER_NOT_OK;
 
  switch(AppDcm_SignatureVerifySequence)
  {
    case SIGNATURE_VERIFY_START:
      Dcm_GaaPublicKey.length = LaaKeyLength;
   
      for (LucIndex = 0U; LucIndex < LaaKeyLength; LucIndex++)
      {
        Dcm_GaaPublicKey.data[LucIndex] = Dcm_GaaPublicKeyData[LucIndex]; /* 010A_07 */
      }
 
      if (RTE_E_OK == Rte_Call_HaeSignatureVerify_L10_SignatureVerifyStart(&Dcm_GaaPublicKey))
      {
        AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_START_PENDING;
        AppDcm_SignatureVerifyStatus = SIGANTURE_VERIFY_PENDING;
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      else
      {
        LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
      }
      break;
     
    case SIGNATURE_VERIFY_START_PENDING:
      if(AppDcm_SignatureVerifyStatus == SIGNATURE_VERIFY_IDLE)
      {
        AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_UPDATE;
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      else
      {
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      break;
 
    case SIGNATURE_VERIFY_UPDATE: 
      if (RTE_E_OK == Rte_Call_HaeSignatureVerify_L10_SignatureVerifyUpdate(&AppDcm_GaaRandomNum[0], 8))
      {
        AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_UPDATE_PENDING;
        AppDcm_SignatureVerifyStatus = SIGANTURE_VERIFY_PENDING;
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      else
      {
        LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
      }       
      break;
     
    case SIGNATURE_VERIFY_UPDATE_PENDING: 
      if(AppDcm_SignatureVerifyStatus == SIGNATURE_VERIFY_IDLE)
      {
        AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_FINISH;
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      else
      {
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      break;
     
    case SIGNATURE_VERIFY_FINISH:
      if (RTE_E_OK == Rte_Call_HaeSignatureVerify_L10_SignatureVerifyFinish(&Key[0], 256, &Dcm_LaaVerifyResult))
      {
        AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_FINISH_PENDING;
        AppDcm_SignatureVerifyStatus = SIGANTURE_VERIFY_PENDING;
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      else
      {
        LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
      }
 
      break;
 
    case SIGNATURE_VERIFY_FINISH_PENDING: 
      if(AppDcm_SignatureVerifyStatus == SIGNATURE_VERIFY_IDLE)
      {
        if(Dcm_LaaVerifyResult == CSM_E_VER_OK)
        {
          AppDcm_SignatureVerifySequence = SIGNATURE_VERIFY_START;
          LddRetVal = E_OK;
        }
        else
        {
          LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_COMPARE_KEY_FAILED;
        }
      }
      else
      {
        LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
      }
      break;
 
    case SIGNTAURE_VERIFY_ERR:
    default:
      LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
      break;
  }
  return LddRetVal;
}
 
FUNC(Std_ReturnType, RTE_CODE) AppDcm_CompareKey_L10_cbk(VAR(Std_ReturnType, AUTOMATIC) retVal)
{
  if(retVal == CSM_E_VER_OK)
  {
    AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_IDLE;
  }
  else
  {
    AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_NONE;
    AppDcm_SignatureVerifySequence = SIGNTAURE_VERIFY_ERR;
  }
  return E_OK;
}
#else // Csm_R44
#define SIGNATURE_VERIFY_NONE  (0x00U)
#define SIGNATURE_VERIFY_START (0x01U)
#define SIGNATURE_VERIFY_FINISH (0x02U)
static uint8 AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_NONE;
 
FUNC(Std_ReturnType, RTE_CODE) AppDcm_GetSeed_L10(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Seed,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
  Std_ReturnType LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
  uint32 resultLength = 8UL;

  #if defined(Rte_Call_HaeHsmRandomGenerate_L10_RandomGenerate_L10_RandomGenerate)
  /* Case 1. Random Generate with HSM PRNG (TRNG + SW PRNG) : HAE HSM 2.0 */
  if (RTE_E_OK == Rte_Call_HaeHsmRandomGenerate_L10_RandomGenerate_L10_RandomGenerate(&AppDcm_GaaRandomNum[0], &resultLength))
  #elif defined(Rte_Call_CsmKeyManagement_RandomSeed_L10_RandomSeed)
  /* Case 2. Random Generate with SW DRBG : HAE CryptoLib */
  volatile static boolean LblRandomSeedUpdated = FALSE;
     
  if (FALSE == LblRandomSeedUpdated)
  {
    uint8 LaaHaeHacSalt_L10[APPDCM_HAE_PSEUDO_ENTROPY_LENGTH] = {0U};
   
    /* Get User RandomSeed */
    if (E_OK == AppDcm_GetRandomSeed(LaaHaeHacSalt_L10))
    {
      #if defined(Rte_Call_CsmKeyManagement_RandomSeed_L10_RandomSeed)
        if (RTE_E_OK == Rte_Call_CsmKeyManagement_RandomSeed_L10_RandomSeed(LaaHaeHacSalt_L10, APPDCM_HAE_PSEUDO_ENTROPY_LENGTH))
        {
          LblRandomSeedUpdated = TRUE;
        }
      #endif
    }
  }
  if ((TRUE == LblRandomSeedUpdated) &&
  #if defined(Rte_Call_CsmKeyManagement_RandomSeed_L10_RandomSeed)
      (RTE_E_OK == Rte_Call_RandomGenerate_L10_RandomGenerate_L10_RandomGenerate(&AppDcm_GaaRandomNum[0], &resultLength)))
         
  #endif
  #else
  #error 'Not found Csm Random Generate Configuration. Please make random number in AppDcm_GaaRandomNum[] by yourself'
  #endif
  {
#if defined (DEBUG_FIXED_RANDOM_SEED_USE) 	/* test for fixed random seed  */
		AppDcm_GaaRandomNum[0] = 0x11;
		AppDcm_GaaRandomNum[1] = 0x22;
		AppDcm_GaaRandomNum[2] = 0x33;
		AppDcm_GaaRandomNum[3] = 0x44;
		AppDcm_GaaRandomNum[4] = 0x55;
		AppDcm_GaaRandomNum[5] = 0x66;
		AppDcm_GaaRandomNum[6] = 0x77;
		AppDcm_GaaRandomNum[7] = 0x88;
#endif
    
    uint8 LucIndex;
     
    for (LucIndex = 0U; LucIndex < resultLength; LucIndex++)
    {
      Seed[LucIndex] = AppDcm_GaaRandomNum[LucIndex];
      //AppDcm_GaaRandomNum[LucIndex] = LucIndex+1;  //TestCode to check configuration about OEUK
    }
    LddRetVal = RTE_E_OK;
  }
  #if defined(Rte_Call_CsmKeyManagement_RandomSeed_L10_RandomSeed)
  else
  {
    LblRandomSeedUpdated = FALSE;
  }
  #endif
   
  if (RTE_E_OK != LddRetVal)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
  }

/* WPC_2411_01 Start */
#if defined(DOWNGRADE_PREVENT_OFF)
  LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
  *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
#elif defined (DOWNGRADE_PREVENT_ON)
  // none  
#else
  Error : DOWNGRADE_PREVENT not defined    
#endif
/* WPC_2411_01 End */
   
  return LddRetVal;
}
 
FUNC(Std_ReturnType, RTE_CODE) AppDcm_CompareKey_L10(
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Key,
  Dcm_OpStatusType OpStatus
  )
{
  static P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_APPL_DATA) Dcm_LaaVerifyResult = CRYPTO_E_VER_NOT_OK;
  static VAR(uint32, DCM_VAR) Dcm_LaaPublicKeyLength = 260;
  Std_ReturnType LddRetVal = E_NOT_OK;
 
 // nidec : AppDcm_SignatureVerifyStatus 변수를 초기화 해주는 곳이 없어서 최초에 1회 성공하면 그 이후에도 항상 성공하고
 // 최초에 실패하면 그 이후에도 하상 실패 하는 버그가 있음.
 // FAQ 에서 가이드 해준 소스 코드를 수정하여 버그를 없애고 사용하기로 함.
	switch(OpStatus)
	{
		case DCM_INITIAL :
      AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_NONE;
      LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
			break;

		case DCM_PENDING :
      switch(AppDcm_SignatureVerifyStatus)
      {
        case SIGNATURE_VERIFY_NONE:
          if (RTE_E_OK == Rte_Call_CsmKeyManagement_CryptoKey_OEUK_KeyElementSet(0x01, (const uint8*)&Dcm_GaaPublicKeyData, Dcm_LaaPublicKeyLength)) /* 010A_07 */
          {
            if (RTE_E_OK == Rte_Call_CsmKeyManagement_CryptoKey_OEUK_KeySetValid())
            {
              if (RTE_E_OK == Rte_Call_SWC_DiagnosticService_CsmSignatureVerify_RSASSA_PKCS1_v1_5_SignatureVerify
                  (CRYPTO_OPERATIONMODE_SINGLECALL,
                   &AppDcm_GaaRandomNum[0],
                   8,
                   &Key[0],
                   256,
                   &Dcm_LaaVerifyResult))
              {
                AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_START;
                LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
              }
              else
              {
                LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
              }
            }
          }
          break;
    
        case SIGNATURE_VERIFY_START:
          LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
          break;
    
        case SIGNATURE_VERIFY_FINISH:
          if (Dcm_LaaVerifyResult == CRYPTO_E_VER_OK) // Verify Success
          {
            LddRetVal = RTE_E_OK;
          }
          else // Verify Fail
          {
            LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_COMPARE_KEY_FAILED;
          }
          break;
    
        default:
          LddRetVal = RTE_E_SecurityAccess_L10_DCM_E_PENDING;
          break;
      }    
			break;

		case DCM_CANCEL :
			LddRetVal = RTE_E_OK;
			break;

		default :
			break;
	}
   
/* WPC_2411_01 Start */
#if defined(DOWNGRADE_PREVENT_OFF)
  LddRetVal = RTE_E_SecurityAccess_L10_E_NOT_OK;
#elif defined (DOWNGRADE_PREVENT_ON)
  // none  
#else
  Error : DOWNGRADE_PREVENT not defined    
#endif
/* WPC_2411_01 End */
   
  return LddRetVal;
}
 
FUNC(void, RTE_CODE) AppDcm_CompareKey_L10_cbk(
  VAR(Csm_ResultType, AUTOMATIC) result)
{
  if(result == E_OK) // SignatureVerify Job Finish
  {
    AppDcm_SignatureVerifyStatus = SIGNATURE_VERIFY_FINISH;
  }
}
#endif
#endif


#define SWC_DiagnosticService_STOP_SEC_CODE
#include "SWC_DiagnosticService_MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
