/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : ErrM_Cbk_User.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Error Management SWC                                  **
**                                                                            **
**  PURPOSE   : SWC Sample code for Error Management                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
//#include "Rte_SWC_ErrM.h"
#include "ErrM.h"
#include "Dcm_Types.h"
#include "Os_Hook.h"
#include "OS_Debug.h"
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include "EcuInfo.h"
#include "ErrM_Cbk_User.h"

#if defined ( DEBUG_ErrM_Module_USE )

/*******************************************************************************
**                     User Config Macros                                     **
*******************************************************************************/
/* This macros must be changed */
/* Max Dem event number */
#define DEM_MAX_ERROR_NUM 67u
/* Max OS error number */
#define OS_MAX_ERROR_NUM 103u + 1u // Os_ErrorValueType 의 갯수
/* The value of parameter 'Max Data Length' in 'DcmDspDidRange' container */
//#define DIDRANGE_MAX_DATA_LENGTH 200


typedef struct
{
  double CPULoad;     /**< Current CPU Load value */ // uint16 (0 ~ 1000)
  double CPULoadPeak; /**< CPU Load Peak value after value reset */ // uint16 (0 ~ 1000)
  double CPULoadMean; /**< CPU Load Mean value */ // uint16 (0 ~ 1000)
  double ITLoad;      /**< Current Interrupt Load value */ // uint16 (0 ~ 1000)
  double ITLoadPeak;  /**< Interrupt Load Peak value after value reset */ // uint16 (0 ~ 1000)
  double ITLoadMean;  /**< Interrupt Load Mean value */ // uint16 (0 ~ 1000)
} Os_LoadType_Percent;


typedef struct
{
	uint32 Usage;
	uint32 Size;
  double Percent;
}StackUsage_t;

typedef struct
{
  StackUsage_t ASW_FG1_100ms;
  StackUsage_t ASW_FG1_10ms;
  StackUsage_t ASW_FG2_WdgMTestMode;
  StackUsage_t BSW_ComMModeRequest;
  StackUsage_t BSW_FG1_10ms;
  StackUsage_t BSW_FG1_100ms;
  StackUsage_t BSW_FG1_5ms_Com;
  StackUsage_t BSW_FG2_WdgMAPI;
  StackUsage_t BSW_Init;
  StackUsage_t BSW_Mem_Process;
  StackUsage_t BSW_FG1_IOManager;
  StackUsage_t BSW_FG2_IOManager;
  StackUsage_t BSW_RomTst;
  StackUsage_t CAN_DRE_Process;
  StackUsage_t CAN_DREE_Process;
  StackUsage_t SWC_BG;
  StackUsage_t ASW_5ms;
  StackUsage_t BSW_BG_KeyM;
  StackUsage_t BSW_BG_Fota;
  StackUsage_t BSW_BG_Crypto_Main;
  StackUsage_t TOTAL;

}StackUsage_Task_t;

typedef struct
{
	uint32 Id;
	uint32 Count;
}OsError_t;

typedef struct
{
	Os_ErrorValueType Id;
	uint32 Count;
}OsErrorMonitor_t;

typedef struct
{
  double ASW_FG1_100ms;
  double ASW_FG1_10ms;
  double ASW_FG2_WdgMTestMode;
  double BSW_ComMModeRequest;
  double BSW_FG1_10ms;
  double BSW_FG1_100ms;  
  double BSW_FG1_5ms_Com;
  double BSW_FG2_WdgMAPI;
  double BSW_Init;
  double BSW_Mem_Process;
  double BSW_FG1_IOManager;
  double BSW_FG2_IOManager;
  double BSW_RomTst;
  double CAN_DRE_Process;
  double CAN_DREE_Process;
  double SWC_BG;
  double ASW_5ms;
  double BSW_BG_KeyM;
  double BSW_BG_Fota;
  double BSW_BG_Crypto_Main;  
}StackMonitor_t;

typedef struct
{
	Os_ErrorValueType Id;
	uint32 Count;
}Stack_t;

typedef struct
{
  Os_LoadType Load;
  Os_LoadType_Percent LoadPercent;


  OsError_t Os_Error[OS_MAX_ERROR_NUM];
  OsErrorMonitor_t OS_ErrorMonitor[OS_MAX_ERROR_NUM];

  StackUsage_Task_t StackTask;
  //StackMonitor_t StackUsage_Percent;

} ErrM_t;


static ErrM_t ErrM = {0};


/*******************************************************************************
**                     Global Data Types                                      **
*******************************************************************************/
// #define SWC_ErrM_START_SEC_VAR_CLEARED_UNSPECIFIED
// #include "SWC_ErrM_MemMap.h"

uint8 Sdat_GaaDemErrorCount[DEM_MAX_ERROR_NUM];
uint8 Sdat_GaaOsErrorCount[OS_MAX_ERROR_NUM];


//static void ss_SetOsError(void);


// #define SWC_ErrM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
// #include "SWC_ErrM_MemMap.h"

/*******************************************************************************
**                     Function Definitions                                   **
*******************************************************************************/
// #define SWC_ErrM_START_SEC_CODE
// #include "SWC_ErrM_MemMap.h"
// 에러 발생시에 notification오로 호출되는 함수
uint8_t ErrM_Callback(uint8_t ErrorId, ErrM_ErrorType ErrorType)
{
  Std_ReturnType LddReturn;

  LddReturn = E_OK;

  switch(ErrorType)
  {
    case ERRM_OS_ERROR:
      /* START OS ERROR */
      /* Refer to Os_error_api.h (i.e E_OS_ACCESS, etc) */
      if(ErrorId <= OS_MAX_ERROR_NUM)
      {
        Sdat_GaaOsErrorCount[ErrorId]++;
      }
      else
      {
      }
      break;
      /* STOP OS ERROR */
    case ERRM_DEM_EVENT_FAIL:
      /* START DEM EVENT FAIL */
      /* Refer to Dem_Cfg.h (i.e WDGM_E_IMPROPER_CALLER, etc) */
      if(ErrorId <= DEM_MAX_ERROR_NUM)
      {
        Sdat_GaaDemErrorCount[ErrorId]++;
      }
      else
      {
      }

      break;
      /* STOP DEM EVENT FAIL */

    case ERRM_NONE:
    default:
      /* ERRM_NONE or default */

      break;

  }

  if(Sdat_GaaOsErrorCount[ErrorId] > 0)
  {
    ErrM.Os_Error[ErrorId].Id = ErrorId;
    ErrM.Os_Error[ErrorId].Count = Sdat_GaaOsErrorCount[ErrorId];
  }

  return LddReturn;
}


/***************************************************************************************************
@param[in]  void
@return     void
@note    	LpLoad     A pointer for save CPU and IT load
 			restart    OS_TRUE : Get load and restart measurement
                       OS_FALSE : Just get load
***************************************************************************************************/
void gs_GetCpuLoad(void)
{
// /**
//   * This structure holds the CPU and Interrupt Load value.
//   */
// typedef struct
// {
//   uint16 usCPULoad;     /**< Current CPU Load value */ // uint16 (0 ~ 1000)
//   uint16 usCPULoadPeak; /**< CPU Load Peak value after value reset */ // uint16 (0 ~ 1000)
//   uint16 usCPULoadMean; /**< CPU Load Mean value */ // uint16 (0 ~ 1000)
//   uint16 usITLoad;      /**< Current Interrupt Load value */ // uint16 (0 ~ 1000)
//   uint16 usITLoadPeak;  /**< Interrupt Load Peak value after value reset */ // uint16 (0 ~ 1000)
//   uint16 usITLoadMean;  /**< Interrupt Load Mean value */ // uint16 (0 ~ 1000)
// } Os_LoadType;

// 오트론 답변
// 해당 단위는 1/1000 입니다. 즉, 0.1% 입니다.
// 즉, 1000 = 100%, 100 = 10%로 해석하시면 됩니다.

		Os_UserGetCPULoad(&ErrM.Load, OS_FALSE); // just load

		// %로 수정하여 출력 (max가 1000 이므로 %로 출력하기위해서는 최종 계산식으로 적용)
		ErrM.LoadPercent.CPULoad = ErrM.Load.usCPULoad / 10.0;
		ErrM.LoadPercent.CPULoadPeak = ErrM.Load.usCPULoadPeak / 10.0;
		ErrM.LoadPercent.CPULoadMean = ErrM.Load.usCPULoadMean / 10.0;
		ErrM.LoadPercent.ITLoad = ErrM.Load.usITLoad / 10.0;
		ErrM.LoadPercent.ITLoadPeak = ErrM.Load.usITLoadPeak / 10.0;
		ErrM.LoadPercent.ITLoadMean = ErrM.Load.usITLoadMean / 10.0;

}

/***************************************************************************************************
@param[in]  void
@return     void
@note       LddTaskId – Task ID
			pStackUsage - Stack usage of the stack which is used by Task
			pStackSize - Total stack size of the stack which is used by Task
***************************************************************************************************/
void gs_GetStackUsage(void)
{

  // 매주기 읽어도 부하에 문제가 되는지 여부 확인 필요.
	// 자료 작성후 즉시 undefiend 해서 실행되지 않도록 하자.

  StatusType statusReturn;

// OS TASK에서 별도로 stack 설정하지 않으면 userstack 으로 설정한 값을 나눠서 사용함. (4096으로 설정됨)
// 그리고 Usage도 공용으로 사용하는것은 모두 통합해서 나옴.
// 그러므로 각각 계산할 필요 없고 공용 task중에서 하나만 호출해서 나온 사용량으로 퍼센트 사용하면 된다.
// Os_GetMaxStackUsage() 함수는 한번도 실행되지 않으면 usage가 size 설정값 그대로 리턴된다.
	statusReturn = Os_GetMaxStackUsage(OsTask_ASW_FG1_100ms, &ErrM.StackTask.ASW_FG1_100ms.Usage, &ErrM.StackTask.ASW_FG1_100ms.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.ASW_FG1_100ms.Percent = (ErrM.StackTask.ASW_FG1_100ms.Usage  * 100.0 / ErrM.StackTask.ASW_FG1_100ms.Size);
    ErrM.StackTask.TOTAL.Usage = ErrM.StackTask.ASW_FG1_100ms.Usage; // userstack 사용량 총합임.
    ErrM.StackTask.TOTAL.Size = ErrM.StackTask.ASW_FG1_100ms.Size;
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_ASW_FG1_10ms, &ErrM.StackTask.ASW_FG1_10ms.Usage, &ErrM.StackTask.ASW_FG1_10ms.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.ASW_FG1_10ms.Percent = (ErrM.StackTask.ASW_FG1_10ms.Usage * 100.0 / ErrM.StackTask.ASW_FG1_10ms.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_ASW_FG2_WdgMTestMode, &ErrM.StackTask.ASW_FG2_WdgMTestMode.Usage, &ErrM.StackTask.ASW_FG2_WdgMTestMode.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.ASW_FG2_WdgMTestMode.Percent = (ErrM.StackTask.ASW_FG2_WdgMTestMode.Usage * 100.0 / ErrM.StackTask.ASW_FG2_WdgMTestMode.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_ComMModeRequest, &ErrM.StackTask.BSW_ComMModeRequest.Usage, &ErrM.StackTask.BSW_ComMModeRequest.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_ComMModeRequest.Percent = (ErrM.StackTask.BSW_ComMModeRequest.Usage * 100.0 / ErrM.StackTask.BSW_ComMModeRequest.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_FG1_10ms, &ErrM.StackTask.BSW_FG1_10ms.Usage, &ErrM.StackTask.BSW_FG1_10ms.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_FG1_10ms.Percent = (ErrM.StackTask.BSW_FG1_10ms.Usage * 100.0 / ErrM.StackTask.BSW_FG1_10ms.Size);
  }
  
	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_FG1_100ms, &ErrM.StackTask.BSW_FG1_100ms.Usage, &ErrM.StackTask.BSW_FG1_100ms.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_FG1_100ms.Percent = (ErrM.StackTask.BSW_FG1_100ms.Usage * 100.0 / ErrM.StackTask.BSW_FG1_100ms.Size);
  }  

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_FG1_5ms_Com, &ErrM.StackTask.BSW_FG1_5ms_Com.Usage, &ErrM.StackTask.BSW_FG1_5ms_Com.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_FG1_5ms_Com.Percent = (ErrM.StackTask.BSW_FG1_5ms_Com.Usage * 100.0 / ErrM.StackTask.BSW_FG1_5ms_Com.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_FG2_WdgMAPI, &ErrM.StackTask.BSW_FG2_WdgMAPI.Usage, &ErrM.StackTask.BSW_FG2_WdgMAPI.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_FG2_WdgMAPI.Percent = (ErrM.StackTask.BSW_FG2_WdgMAPI.Usage * 100.0 / ErrM.StackTask.BSW_FG2_WdgMAPI.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_Init, &ErrM.StackTask.BSW_Init.Usage, &ErrM.StackTask.BSW_Init.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_Init.Percent = (ErrM.StackTask.BSW_Init.Usage * 100.0 / ErrM.StackTask.BSW_Init.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_FG1_IOManager, &ErrM.StackTask.BSW_FG1_IOManager.Usage, &ErrM.StackTask.BSW_FG1_IOManager.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_FG1_IOManager.Percent = (ErrM.StackTask.BSW_FG1_IOManager.Usage * 100.0 / ErrM.StackTask.BSW_FG1_IOManager.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_FG2_IOManager, &ErrM.StackTask.BSW_FG2_IOManager.Usage, &ErrM.StackTask.BSW_FG2_IOManager.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_FG2_IOManager.Percent = (ErrM.StackTask.BSW_FG2_IOManager.Usage * 100.0 / ErrM.StackTask.BSW_FG2_IOManager.Size);
  }
  
	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_RomTst, &ErrM.StackTask.BSW_RomTst.Usage, &ErrM.StackTask.BSW_RomTst.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_RomTst.Percent = (ErrM.StackTask.BSW_RomTst.Usage * 100.0 / ErrM.StackTask.BSW_RomTst.Size);
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_Mem_Process, &ErrM.StackTask.BSW_Mem_Process.Usage, &ErrM.StackTask.BSW_Mem_Process.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_Mem_Process.Percent = (ErrM.StackTask.BSW_Mem_Process.Usage * 100.0 / ErrM.StackTask.BSW_Mem_Process.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.BSW_Mem_Process.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.BSW_Mem_Process.Size;
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_CAN_DRE_Process, &ErrM.StackTask.CAN_DRE_Process.Usage, &ErrM.StackTask.CAN_DRE_Process.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.CAN_DRE_Process.Percent = (ErrM.StackTask.CAN_DRE_Process.Usage * 100.0 / ErrM.StackTask.CAN_DRE_Process.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.CAN_DRE_Process.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.CAN_DRE_Process.Size;
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_CAN_DREE_Process, &ErrM.StackTask.CAN_DREE_Process.Usage, &ErrM.StackTask.CAN_DREE_Process.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.CAN_DREE_Process.Percent = (ErrM.StackTask.CAN_DREE_Process.Usage * 100.0 / ErrM.StackTask.CAN_DREE_Process.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.CAN_DREE_Process.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.CAN_DREE_Process.Size;
  }

	statusReturn = Os_GetMaxStackUsage(OsTask_SWC_BG, &ErrM.StackTask.SWC_BG.Usage, &ErrM.StackTask.SWC_BG.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.SWC_BG.Percent = (ErrM.StackTask.SWC_BG.Usage * 100.0 / ErrM.StackTask.SWC_BG.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.SWC_BG.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.SWC_BG.Size;
  }
  
	statusReturn = Os_GetMaxStackUsage(OsTask_ASW_5ms, &ErrM.StackTask.ASW_5ms.Usage, &ErrM.StackTask.ASW_5ms.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.ASW_5ms.Percent = (ErrM.StackTask.ASW_5ms.Usage * 100.0 / ErrM.StackTask.ASW_5ms.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.ASW_5ms.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.ASW_5ms.Size;
  }  
  
	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_BG_KeyM, &ErrM.StackTask.BSW_BG_KeyM.Usage, &ErrM.StackTask.BSW_BG_KeyM.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_BG_KeyM.Percent = (ErrM.StackTask.BSW_BG_KeyM.Usage * 100.0 / ErrM.StackTask.BSW_BG_KeyM.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.BSW_BG_KeyM.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.BSW_BG_KeyM.Size;
  }    
  
	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_BG_Fota, &ErrM.StackTask.BSW_BG_Fota.Usage, &ErrM.StackTask.BSW_BG_Fota.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_BG_Fota.Percent = (ErrM.StackTask.BSW_BG_Fota.Usage * 100.0 / ErrM.StackTask.BSW_BG_Fota.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.BSW_BG_Fota.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.BSW_BG_Fota.Size;
  } 
    
	statusReturn = Os_GetMaxStackUsage(OsTask_BSW_BG_Crypto_Main, &ErrM.StackTask.BSW_BG_Crypto_Main.Usage, &ErrM.StackTask.BSW_BG_Crypto_Main.Size);
  if(statusReturn == E_OK)
  {
    ErrM.StackTask.BSW_BG_Crypto_Main.Percent = (ErrM.StackTask.BSW_BG_Crypto_Main.Usage * 100.0 / ErrM.StackTask.BSW_BG_Crypto_Main.Size);
    ErrM.StackTask.TOTAL.Usage += ErrM.StackTask.BSW_BG_Crypto_Main.Usage;
    ErrM.StackTask.TOTAL.Size += ErrM.StackTask.BSW_BG_Crypto_Main.Size;
  } 
      
  ErrM.StackTask.TOTAL.Percent = (ErrM.StackTask.TOTAL.Usage * 100.0 / ErrM.StackTask.TOTAL.Size); // 공용으로 사용하는 stack과 개별로 할당된 Stack 총합으로 계산한 퍼센트

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void gs_GetOsError(void)
{
  uint8 nOsErrorId;

  for(nOsErrorId=0; nOsErrorId < OS_MAX_ERROR_NUM; nOsErrorId++)
  {
    ErrM.OS_ErrorMonitor[nOsErrorId].Id = nOsErrorId;
    ErrM.OS_ErrorMonitor[nOsErrorId].Count = ErrM.Os_Error[nOsErrorId].Count;
  }
}

// FUNC(Std_ReturnType, SWC_ErrM_CODE) ErrM_SDAT_DidRange(
//   IN VAR(uint16, AUTOMATIC) DID,
//   OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data,
//   IN VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
//   OUT P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DataLength,
//   OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
// {
//   VAR(Std_ReturnType, RTE_DATA) LddRetVal;
//   Os_LoadType LpCPULoad = {0u,0u,0u,0u};
//   uint32 LulTimeStamp;
//   uint8 nIndex = 4;
//   uint8 nDemEventId = 1;
//   uint8 nOsErrorId = 1;

//   LddRetVal = E_NOT_OK;

//   /* Need to change case conditions to match values of parameters
//     'Identifier Lower Limit', 'Identifier Upper Limit'
//      in 'DcmDspDidRange' container */
//   switch(DID)
//   {
//     case 0x1100:
//       *DataLength = 10;

//       /* CPU Usage, refer to OS User Manual */
//       #if (OS_DEBUG_CPULOAD == STD_ON)
//       {
//         Os_UserGetCPULoad(&LpCPULoad);
//         Data[9] = (uint8)LpCPULoad.usCPULoad;
//         Data[8] = (uint8)(LpCPULoad.usCPULoad>>8);
//       }
//       #else
//       {
//         Data[9] = 0xFF;
//         Data[8] = 0xFF;
//       }
//       #endif

//       /* if Stack Usage is used, refer to OS User Manual  */
//       #if(OS_DEBUG_STACKDEPTH == STD_ON)
//       {
//         Data[7] = (uint8)MainStack_GetUsage();
//         Data[6] = (uint8)(MainStack_GetUsage()>>8);
//         Data[5] = (uint8)(MainStack_GetUsage()>>16);
//         Data[4] = (uint8)(MainStack_GetUsage()>>24);
//       }
//       #else
//       {
//         Data[7] = 0x00;
//         Data[6] = 0x00;
//         Data[5] = 0x00;
//         Data[4] = 0x00;
//       }
//       #endif

//       /* Fill timestamp to response data, refer to OS User Manual  */
//       LulTimeStamp = OS_GET_TIMESTAMP();
//       Data[3] = (uint8)LulTimeStamp;
//       Data[2] = (uint8)(LulTimeStamp>>8);
//       Data[1] = (uint8)(LulTimeStamp>>16);
//       Data[0] = (uint8)(LulTimeStamp>>24);

//       *ErrorCode = DCM_E_POSITIVERESPONSE;
//       LddRetVal = RTE_E_OK;
//       break;

//   case 0x1101:
//   case 0x1102:
//     nIndex = 4;
//     /* Note : OsErrorId starts from 1 */
//     for (nOsErrorId = 1; nOsErrorId <= OS_MAX_ERROR_NUM; nOsErrorId++)
//     {
//       if((Sdat_GaaOsErrorCount[nOsErrorId] > 0) &&
//          (nIndex <= (DIDRANGE_MAX_DATA_LENGTH - 4)))
//       {
//         Data[nIndex] = nOsErrorId;
//         Data[nIndex+1] = ERRM_OS_ERROR;
//         Data[nIndex+2] = Sdat_GaaOsErrorCount[nOsErrorId];
//         nIndex = nIndex + 3;
//       }
//     }
//     /* Note : DemEventId starts from 1 */
//     for (nDemEventId = 1; nDemEventId <= DEM_MAX_ERROR_NUM; nDemEventId++)
//     {
//       if((Sdat_GaaDemErrorCount[nDemEventId] > 0) &&
//          (nIndex <= (DIDRANGE_MAX_DATA_LENGTH - 4)))
//       {
//         Data[nIndex] = nDemEventId;
//         Data[nIndex+1] = ERRM_DEM_EVENT_FAIL;
//         Data[nIndex+2] = Sdat_GaaDemErrorCount[nDemEventId];
//         nIndex = nIndex + 3;
//       }
//     }

//     *DataLength = nIndex;

//     /* Fill timestamp to response data, refer to OS User Manual  */
//     LulTimeStamp = OS_GET_TIMESTAMP();
//     Data[3] = (uint8)LulTimeStamp;
//     Data[2] = (uint8)(LulTimeStamp>>8);
//     Data[1] = (uint8)(LulTimeStamp>>16);
//     Data[0] = (uint8)(LulTimeStamp>>24);

//     *ErrorCode = DCM_E_POSITIVERESPONSE;
//     LddRetVal = RTE_E_OK;
//     break;

//   default:
//     *ErrorCode = DCM_E_GENERALREJECT;
//     break;
//   }

//   return LddRetVal;
// }
// #define SWC_ErrM_STOP_SEC_CODE
// #include "SWC_ErrM_MemMap.h"


#endif
