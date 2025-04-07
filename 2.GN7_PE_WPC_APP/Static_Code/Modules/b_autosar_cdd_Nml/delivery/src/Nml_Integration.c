/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI MOTOR GROUP                                              **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: xxxxxxxxxxx.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Classic Platform Application                                  **
**                                                                            **
**  PURPOSE   : Log application for SWP                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** X.X.X     DD-MM-YYYY    name.family name                                   **
** 0.0.1     29-Nov-2022    KC.Lim        xxxxxxxxxxxxxx                      **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Integration.h"
#include "Nml_Log.h"
#include "Nml_Lib.h"
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] ""DCM_E_CONDITIONSNOTCORRECT" defined in Dcm_Cfg.h file used in Nml_Integration.c file as a compile macro." */
#include "Dcm_Cfg.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] ""DCM_E_CONDITIONSNOTCORRECT" defined in Dcm_Cfg.h file used in Nml_Integration.c file as a compile macro." */
#include "Dcm.h"
#include "Nml_Ram.h"
#include "Rte_Type.h"
/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "In case of NXP compiler, there is compile error if not used." */
#include "NvM.h" /* 2.0.5_HF1 : Implicity declaration */
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "In case of NXP compiler, there is compile error if not used." */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Macro definition                                      **
*******************************************************************************/
#if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) /* if R40 */
  #define NML_DCM_E_POSITIVERESPONSE     DCM_E_POSITIVERESPONSE
  #define NML_DCM_E_CONDITIONSNOTCORRECT DCM_E_CONDITIONSNOTCORRECT
  #define NML_RTE_E_OK                   RTE_E_OK
  #define NML_DCM_DSP_MAX_DID_SIZE       DCM_DSP_MAX_DID_SIZE
#elif (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_44)  /* if R44 */
  #define NML_DCM_E_POSITIVERESPONSE     DCM_POSITIVE_RESPONSE
  #define NML_DCM_E_CONDITIONSNOTCORRECT DCM_E_CONDITIONSNOTCORRECT
  #define NML_RTE_E_OK                   RTE_E_OK
  #define NML_DCM_DSP_MAX_DID_SIZE       DCM_DSP_MAX_DID_SIZE
#else /* Other variant */
  #error "No ComM Module R44 or R40"
#endif /* #if (NML_INTEGRATED_AR_VERSION == NML_AR_VERSION_40) */

#if (NML_DCM_DSP_MAX_DID_SIZE < NML_LOGDATA_SIZE)
	#error 'DCM DID MAX Buffer size is less than Nml_LogData size, Please contact to Kyungchul.lim@hyundai.com'
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

uint8 Nml_LogData[NML_LOGDATA_SIZE];

#define NML_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"



/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


#define NML_START_SEC_CODE
#include "MemMap.h"

void Nml_EcuM_LogDataCallout(uint32 wakeupSource)
{
	#if (STD_ON == NML_USE)
		Nml_LogFuncWUS(wakeupSource);
	#endif /*#if (STD_ON == NML_USE)*/
}



Std_ReturnType Nml_RDBI_DataRead(uint8* Data)
{
  /* polyspace-begin DEFECT:UNMODIFIED_VAR_NOT_CONST [Not a defect:Unset] "According to SWS_NvM, the return value shall be E_OK or E_NOT_OK. In the usecase of Nml, there is no E_NOT_OK case." */
  Std_ReturnType LddRetVal = NML_RTE_E_OK;
  /* polyspace-end DEFECT:UNMODIFIED_VAR_NOT_CONST [Not a defect:Unset] "According to SWS_NvM, the return value shall be E_OK or E_NOT_OK. In the usecase of Nml, there is no E_NOT_OK case." */
  uint8 i = 0x00;

  #if (STD_ON == NML_USE)
	for (i=0; i<NML_LOGDATA_SIZE; i++)
	{
		Data[i] = NML_NVM_BUFFER[i];
	}
  #endif /*#if (STD_ON == NML_USE)*/

   return LddRetVal;
}

Std_ReturnType Nml_RDBI_CondCheckRead(uint8* ErrorCode)
{
  /* polyspace-begin DEFECT:UNMODIFIED_VAR_NOT_CONST [Not a defect:Unset] "According to SWS_DCM, the return value of this function is E_OK or E_NOT_OK or E_PENDING. In case of NML, there is no case of E_NOT_OK and E_PENDING, that why always return E_OK" */
  Std_ReturnType LddRetVal = NML_RTE_E_OK;
  /* polyspace-end DEFECT:UNMODIFIED_VAR_NOT_CONST [Not a defect:Unset] "According to SWS_DCM, the return value of this function is E_OK or E_NOT_OK or E_PENDING. In case of NML, there is no case of E_NOT_OK and E_PENDING, that why always return E_OK" */

  #if (STD_ON == NML_USE) 
	*ErrorCode = NML_DCM_E_POSITIVERESPONSE;
  #else
    /* If NML module is not USED  */
    *ErrorCode = NML_DCM_E_CONDITIONSNOTCORRECT;
  #endif /*#if (STD_ON == NML_USE)*/
 
  return LddRetVal;
}

Std_ReturnType Nml_Callback_Nml_LogData_JobFinished(uint8 ServiceId, uint8 JobResult)
{
  /* polyspace-begin DEFECT:UNMODIFIED_VAR_NOT_CONST [Not a defect:Unset] "According to SWS_NvM, the return value shall be E_OK or E_NOT_OK. In the usecase of Nml, there is no E_NOT_OK case." */
  Std_ReturnType funcRetVal = E_OK;
  /* polyspace-end DEFECT:UNMODIFIED_VAR_NOT_CONST [Not a defect:Unset] "According to SWS_NvM, the return value shall be E_OK or E_NOT_OK. In the usecase of Nml, there is no E_NOT_OK case." */

 #if (STD_ON == NML_USE)
    Nml_Error.infoNvmSrvId     = ServiceId;
    Nml_Error.infoNvmReqResult = JobResult;
    Nml_SetLogNmlError();

 #endif /*#if (STD_ON == NML_USE)*/
  return funcRetVal;
}

Std_ReturnType Nml_GetNvMReqStatus(void)
{
  #if (STD_ON == NML_USE)
    return (Std_ReturnType)Nml_Error.infoNvmReqResult;
  #else
    return 0x00;
  #endif /*#if (STD_ON == NML_USE)*/  

}

uint8 Nml_GetNvMReqSrvId(void)
{
  #if (STD_ON == NML_USE)
    return (Std_ReturnType)Nml_Error.infoNvmSrvId;
  #else
    return 0x00;
  #endif /*#if (STD_ON == NML_USE)*/  

}

void Nml_SetNvMReqStatus(void)
{
  #if (STD_ON == NML_USE)
    Nml_Error.infoNvmSrvId     = 0xFFu;
    Nml_Error.infoNvmReqResult = 0xFFu;
  #else
  #endif /*#if (STD_ON == NML_USE)*/  
}

void Nml_InitSleepToWakeup(void)
{
  #if (STD_ON == NML_USE)
  /* [NML-3] Sleep/Wakeup Callout */
  uint8 i = 0x00;
  Nml_LibCallCnt           = 0x00;
  Nml_LibCallCntTotal      = 0x0000;
  Nml_LibInternalTime.hour = 0x00;
  Nml_LibInternalTime.min  = 0x00;
  Nml_LibInternalTime.sec  = 0x00;
  Nml_LibInternalTime.ms   = 0x00;
  
  /* polyspace-begin DEFECT:DUPLICATED_CODE [Not a defect:Unset] "Separate variables are required for CanNm and UdpNm for RVCCM, CanNm and UdpNm channels are separated" */
  /* polyspace-begin DEFECT:DUPLICATED_CODE [Not a defect:Unset] "2 funcs(Nml_InitSleepToWakeup, Nml_InitGlobalVariables) are called exclusively by wakeup and reset." */
  Nml_CanNormalDetectCnt   = NML_UINT8_MIN;
  Nml_CanRssDetectCnt      = NML_UINT8_MIN;
  Nml_CanRmsDetectCnt      = NML_UINT8_MIN;
  Nml_CanPbsDetectCnt      = NML_UINT8_MIN;
  Nml_CanBusSleppDetectCnt = NML_UINT8_MIN;

  Nml_UdpNormalDetectCnt   = NML_UINT8_MIN;
  Nml_UdpRssDetectCnt      = NML_UINT8_MIN;
  Nml_UdpRmsDetectCnt      = NML_UINT8_MIN;
  Nml_UdpPbsDetectCnt      = NML_UINT8_MIN;
  Nml_UdpBusSleppDetectCnt = NML_UINT8_MIN;
  /* polyspace-end DEFECT:DUPLICATED_CODE [Not a defect:Unset] "2 funcs(Nml_InitSleepToWakeup, Nml_InitGlobalVariables) are called exclusively by wakeup and reset." */
  /* polyspace-end DEFECT:DUPLICATED_CODE [Not a defect:Unset] "Separate variables are required for CanNm and UdpNm for RVCCM, CanNm and UdpNm channels are separated" */
  
  #if(NVM_SET_RAM_BLOCK_STATUS_API  == STD_ON)
  /* This function shall be required to store Nml_LogData RAM variable into NvM */
  (void)NvM_SetRamBlockStatus(NML_NVM_BLOCK_ID, TRUE);
  #endif
  Nml_IsFirstMainLoopAfterWakeUp = NML_TRUE;
  Nml_IsH2LTransition = NML_FALSE;
  Nml_IsEcuRequestSleep = NML_FALSE;
  Nml_LibNvMWriteRetryCnt = NML_UINT8_MIN;

	#if (NML_NVM_WRITE_USED == STD_ON)
        for (i = 0; i < (uint8)NML_DATA_LAST; i++)
        {
            Nml_IsNeedToWriteNvM[i] = 0x00;
            Nml_IsWriteNvMDone[i]   = 0x00;
        }
	#endif /*#if (NML_NVM_WRITE_USED == STD_ON)*/

  #endif /*#if (STD_ON == NML_USE)*/  
}

void Nml_PrepareSleep(void)
{
#if (STD_ON == NML_USE)
  Nml_IsEcuRequestSleep = NML_TRUE;
#endif /*#if (STD_ON == NML_USE)*/  
}

void Nml_DeInitToSleep(void)
{

#if (STD_ON == NML_USE)
  Nml_IsH2LTransition = NML_TRUE;
#endif /*#if (STD_ON == NML_USE)*/  

}

/* polyspace-begin DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */
#define NML_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace-end DEFECT:USELESS_INCLUDE [Not a defect:Unset] "MemMap.h file used for Function to be rocated" */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
