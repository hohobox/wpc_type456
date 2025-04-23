/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/


/***************************************************************************************************
    INCLUDE FILES
***************************************************************************************************/
#include "EcuInfo.h"
#include "App_DTC.h"
#include "Rte_App_DTC.h"

#include "App_WCT.h"
#include "App_WDT.h"
#include "App_UART.h"
#include "App_Model_types.h"

#include "Dem_Types.h"


#define App_DTC_START_SEC_CODE
#include "App_DTC_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/
#define Par_FanFaultOnTime 				(2000u 	/ TIME_10MS)
#define Par_FanFaultOffTime 			(2000u 	/ TIME_10MS)
#define Par_UartCommErrChkDelayTime		(10000u / TIME_10MS)
#define Par_FanFaultChkDelayTime		(10000u / TIME_10MS)
#define Par_TempSnsrFaultChkDelayTime	(10000u / TIME_10MS)
#define Par_UartCommRecoveryTime		(500u 	/ TIME_10MS)
#define	Par_TempSnsrFaultOnTime			(2000u  / TIME_10MS)
#define Par_WdtEnableWaitTime 			( 100u  / TIME_10MS)

#define Par_InternalErrRetryMaxCnt		(3u)	// DTC 발생을 위한 uart 통신 에러 횟수


#define DEM_CYCLE_STATE_START 0x00U
#define DEM_CYCLE_STATE_END 0x01U


/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

// CAN OFF 관련은 플랫폼에서 제어하므로 별도로 어플리케이션에서는 처리하지않음
typedef enum
{
	MDW_UDS_DTC_Temp_Snsr_Fault,
	MDW_UDS_DTC_Fan_Fault,
    MDW_UDS_DTC_ECU_Internal_ERR,
    MDW_UDS_DTC_NUMBER,
} MDW_UDS_DTC_LIST_t;

//qac 룰 위반 해결을 위해서 매크로를 풀어서 수정
//#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)
//#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
//typedef P2FUNC(Std_ReturnType, App_DTC_CODE, pFnc_EventInfo_GetEventStatus)(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);
//typedef P2FUNC(Std_ReturnType, App_DTC_CODE, pFnc_Event_SetEventStatus)(Dem_EventStatusType EventStatus);
typedef Std_ReturnType (* pFnc_EventInfo_GetEventStatus)(Dem_EventStatusExtendedType *EventStatusExtended);
typedef Std_ReturnType (* pFnc_Event_SetEventStatus)(Dem_EventStatusType EventStatus);

typedef struct
{
	uint8_t App_Init_Completed;
	uint8_t Runnable_State;

    uint8_t FanFaultDTC_ClrReq;
	uint8_t WctIcErrDTC_ClrReq;
	uint8_t TempSnsrErrDTC_ClrReq;

	Event_t IGN1_IN_Evt;
	
	uint16_t WctIcErrorDTCOffCnt;

	TS_STATE_t TempSnsrFault[Device_MAX];
	uint16_t FaultOnCnt[Device_MAX];
	uint16_t TempSnsrFaultChkDelayCnt[Device_MAX];

	TS_STATE_t FanFault_High[Device_MAX];
	TS_STATE_t FanFault_Low[Device_MAX];

	uint16_t FanFaultHigh_OnCnt[Device_MAX];
	uint16_t FanFaultLow_OnCnt[Device_MAX];
	uint8_t	DirectRead_FANFG[Device_MAX];
	uint16_t FanFaultChkDelayCnt[Device_MAX];
	//uint8_t InternalErrRetryCnt;
	
	Event_t WctUartRxTimeout_Evt;
}Inter_t;


typedef struct
{
	IDT_ADC_STR 	Inp_ADC;	
	IDT_UART_STR 	Inp_UART;
	IDT_Model_STR   Inp_Model;
	IDT_CAN_RX_STR  Inp_CAN_RX;
	IDT_Uds_STR 	Inp_Uds;
	IDT_NvM_STR 	Inp_NvM;

	Inter_t 		Int;
	IDT_DTC_STR		Out;
} DTC_struct;



/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/
static const pFnc_EventInfo_GetEventStatus Mdw_Uds_FnTable_GetEventStatus[MDW_UDS_DTC_NUMBER] =
    {
        //&Rte_Call_R_EventInfo_CANSM_E_BUS_OFF_BCAN_GetEventStatus,// WPC_421_02
        //&Rte_Call_R_EventInfo_CANSM_E_BUS_OFF_LCAN_GetEventStatus,// WPC_421_02
		//NULL, // BCAN BUS OFF // WPC_421_01 // WPC_421_02
		//NULL,// LCAN BUS OFF, // WPC_421_01 // WPC_421_02
		&Rte_Call_R_EventInfo_DemEventParameter_Temp_Snsr_Fault_GetEventStatus, // WPC_421_01
		&Rte_Call_R_EventInfo_DemEventParameter_Fan_Fault_GetEventStatus, // WPC_421_01
		&Rte_Call_R_EventInfo_DemEventParameter_ECU_Internal_ERR_GetEventStatus
};

static const pFnc_Event_SetEventStatus Mdw_Uds_FnTable_SetEventStatus[MDW_UDS_DTC_NUMBER] =
    {
        //NULL, // WPC_421_01 // BCAN BUS OFF, 처리하지 않기 위해서 강제로 0으로 설정함. // qac에서 걸려서 NULL로 변경함.
        //NULL, // WPC_421_01 // LCAN BUS OFF, 처리하지 않기 위해서 강제로 0으로 설정함.
		&Rte_Call_R_Event_DemEventParameter_Temp_Snsr_Fault_SetEventStatus, // WPC_421_01
		&Rte_Call_R_Event_DemEventParameter_Fan_Fault_SetEventStatus, // WPC_421_01
		&Rte_Call_R_Event_DemEventParameter_ECU_Internal_ERR_SetEventStatus
};


static DTC_struct DTC = {0};


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_DTC_InitSet(void);
static void ss_DTC_RteRead(void);
static void ss_DTC_RteWrite(void);
static void ss_TempSnsrFaultCheck(void);
static void ss_EcuIntenalErrorCheck(void);
static void ss_FanFaultCheck(void);
static void ss_DtcActivationCheck(void);

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_DTC_CODE) DTC_TE_Runnable(void)
{
	switch(DTC.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&DTC.Int.App_Init_Completed);

			if( DTC.Int.App_Init_Completed == ON ) 	/* SWP Init Complete? */
			{

				ss_DTC_InitSet(); 		/* SWC Init Process */

				DTC.Int.Runnable_State = 1u;

			}
		break;

		case 1u:


			//------------------------------------------------------
			// Input (Rte Read)
			//------------------------------------------------------
			ss_DTC_RteRead();

			//------------------------------------------------------
			// Control Logic
			//------------------------------------------------------
			

			ss_EcuIntenalErrorCheck(); 		// 충전시에만 DTC 판단. 단 클리어 요청은 항상 수신해야 하므로 main task에 있어야 함
			ss_TempSnsrFaultCheck();		// 충전시에만 DTC 판단. 단 클리어 요청은 항상 수신해야 하므로 main task에 있어야 함
			// ss_FanFaultCheck(); /* 010C_01 */	// 충전시에만 DTC 판단. 단 클리어 요청은 항상 수신해야 하므로 main task에 있어야 함
			ss_DtcActivationCheck();


			//------------------------------------------------------
			// Timer
			//------------------------------------------------------


			//------------------------------------------------------
			// Output (Rte Write)
			//------------------------------------------------------

			ss_DTC_RteWrite();


		break;

		default:
			DTC.Int.Runnable_State = 0u;
		break;
	}
}



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_DTC_InitSet(void)
{
	// memset(&DTC.Out, 0, sizeof(DTC.Out));  	// DTC 값은 플랫폼 초기화 되도 클리어 되면 안됨.			// 구조체 변수를 0으로 클리어

	DTC.Int.FanFaultDTC_ClrReq = OFF;
	DTC.Int.WctIcErrDTC_ClrReq = OFF;
	DTC.Int.TempSnsrErrDTC_ClrReq = OFF;

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_DTC_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_ADC_ADC_STR(&DTC.Inp_ADC);
	Rte_Read_R_UART_UART_STR(&DTC.Inp_UART);
	Rte_Read_R_Model_Model_STR(&DTC.Inp_Model);
	Rte_Read_R_CAN_RX_CAN_RX_STR(&DTC.Inp_CAN_RX);
	Rte_Read_R_Uds_Uds_STR(&DTC.Inp_Uds);
	Rte_Read_R_NvM_NvM_STR(&DTC.Inp_NvM);

	gs_UpdateEvent(DTC.Inp_ADC.IGN1_IN, &DTC.Int.IGN1_IN_Evt);	// event update
	gs_UpdateEvent(DTC.Inp_UART.WctUartRxTimeout, &DTC.Int.WctUartRxTimeout_Evt);	// event update
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_DTC_RteWrite(void)
{
    Rte_Call_R_EventInfo_CANSM_E_BUS_OFF_BCAN_GetEventStatus(&DTC.Out.BcanBusOffDTC);
    Rte_Call_R_EventInfo_CANSM_E_BUS_OFF_LCAN_GetEventStatus(&DTC.Out.LcanBusOffDTC);
	// Rte_Call_R_EventInfo_DemEventParameter_Temp_Snsr_Fault_GetEventStatus(&DTC.Out.Device[0].TempSnsrFaultDTC);
	// Rte_Call_R_EventInfo_DemEventParameter_Fan_Fault_GetEventStatus(&DTC.Out.Device[0].FanFaultDTC);
	// Rte_Call_R_EventInfo_DemEventParameter_ECU_Internal_ERR_GetEventStatus(&DTC.Out.WctIcErrorDTC);
	
	
	/*
	DEM_UDS_STATUS_TF	: Test Failed
	DEM_UDS_STATUS_CDTC	: Confirm DTC
	*/

	DTC.Out.BcanBusOffDTC				&= (DEM_UDS_STATUS_TF | DEM_UDS_STATUS_CDTC);
	DTC.Out.LcanBusOffDTC				&= (DEM_UDS_STATUS_TF | DEM_UDS_STATUS_CDTC);
	// DTC.Out.Device[0].TempSnsrFaultDTC	&= (DEM_UDS_STATUS_TF | DEM_UDS_STATUS_CDTC);
	// DTC.Out.Device[0].FanFaultDTC		&= (DEM_UDS_STATUS_TF | DEM_UDS_STATUS_CDTC);
	// DTC.Out.WctIcErrorDTC				&= (DEM_UDS_STATUS_TF | DEM_UDS_STATUS_CDTC);	
		
	
	// 타 SWC에 RTE로 전달
	Rte_Write_P_DTC_DTC_STR(&DTC.Out);	// 한꺼번에 전송
	
}



/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_EcuIntenalErrorCheck(void) /* 010A_11 */
{

	if(DTC.Int.WctIcErrDTC_ClrReq == ON)// || // 이벤트 신호로 동작함. 다음주기에 클리어 됨
	//(DTC.Int.IGN1_IN_Evt.On_Event == ON)) // dtc 클리어 조건은 통신 복귀이므로 주석처리함.	// uds에서 보내던 것을 가식성 높게 직접 조건으로 추가함. ig off --> on시 클리어처리
	{
		DTC.Int.WctIcErrDTC_ClrReq = OFF;
		DTC.Out.WctIcErrorDTC = OFF;	// 강제 DTC 클리어 처리
		DTC.Int.WctIcErrorDTCOffCnt = 0u;
		//DTC.Int.InternalErrRetryCnt = 0u;	 /* 010C_07 */
	}

	// 전원 리셋시 8초, 노멀시 2초 통신 에러 발생으로 DTC가 발생한다.
	// 그 후 리셋 발생후 정상으로 통신이 되면 DTC는 소거 된다.
	
	// 매 IG On 사이클에서 IG On 후 3초 이후에 CCU에서 일괄로 DTC 수집하여 서버에 올림.
	// 그러므로 최대한 빨리 DTC 클리어 될수 있도록 기존 ON 채터링 타임 삭제하고 즉시 클리어 처리함.
	// 그러므로 간헐적 통신 에러로 인한  DTC가 서버로 전송되는것을 방지하기 위해서
	// 통신 에러로 인한 리셋이 연속 3회 초과 발생할때 DTC 발생하도록 강건화 처리 추가한다.
	// 그러나 이 로직은 사양 위배 이므로 고객 신고 또는 내부 협의가 필요함

	//-------------------------------------------------------
	// WPC ECU Internal Error DTC 판단 (Charging Controller의  MCU 이상 발생시 : uart 통신 에러 발생시 에러로 판단하기로함.)
	// ------------------------------------------------------
			
	// DTC 검출은 보수적으로 Ig on 상태에서만 실시하고
	// DTC 클리어는 ig off에서도 할수 있도록 수정함.
	// 서버에서 dtc 수집 기능이 생겼으므로 최대한 검출은 둔감화하고 해제는 즉시처리하도록 한다.
	if((DTC.Inp_ADC.IGN1_IN == ON) &&
	(DTC.Inp_ADC.BatSysStateFault == OFF) &&
	(DTC.Int.WctUartRxTimeout_Evt.On_Event == (uint8_t)DETECTED_ON)) // 리트라이는 전원 리셋할때 1회로 카운트 해야 하므로 이벤트 신호 사용
	{
/* 010C_07 */		
		// UART 타임아웃 카운터 증가
		// if(DTC.Int.InternalErrRetryCnt < Par_InternalErrRetryMaxCnt) 
		// {
		// 	DTC.Int.InternalErrRetryCnt++;
		// }
			
		// 3회 초과 발생 시 DTC ON
		// if(DTC.Int.InternalErrRetryCnt >= Par_InternalErrRetryMaxCnt) 
		// {
			DTC.Out.WctIcErrorDTC = ON;
			DTC.Int.WctIcErrorDTCOffCnt = 0;
		// }
/* 010C_07 */		
	}
	// 복귀 조건 판정 (충전부정상 복귀시 and 500ms 경과)
	else if(DTC.Inp_UART.WctUartRxTimeout == (uint8_t)DETECTED_OFF) // DTC 검출된 상태에서 통신이 정상일때가 복구 모드이다.		
	{
		// 통신 복구 시 카운터 리셋
		// DTC.Int.InternalErrRetryCnt = 0; /* 010C_07 */
			
		if(DTC.Out.WctIcErrorDTC == ON) // DTC 검출 모드 일때
		{
			if (DTC.Int.WctIcErrorDTCOffCnt >= Par_UartCommRecoveryTime) // 정상 통신 500ms 유지시 복구
			{
				DTC.Out.WctIcErrorDTC = OFF;
				DTC.Int.WctIcErrorDTCOffCnt = 0;					
			}
			else
			{
				DTC.Int.WctIcErrorDTCOffCnt++;
			}
		}				
	}
	else 
	{
/* 010C_07 */		
		// if(DTC.Inp_ADC.IGN1_IN == OFF)
		// {
		// 	DTC.Int.InternalErrRetryCnt = 0u;	
		// }
/* 010C_07 */		
		
		DTC.Int.WctIcErrorDTCOffCnt = 0u;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void  ss_TempSnsrFaultCheck(void)
{
// 사양 만족 로직, 간헐적으로 에러 발생 후 정상 복귀시 DTC 코드 클리어 안됨.
	// static uint16_t FaultOnCnt[Device_MAX] = {0};
	// static uint8_t TempSnsrFault[Device_MAX] = {DETECTED_DEFAULT};
	// static uint16_t TempSnsrFaultChkDelayCnt = 0;
	uint8_t Device;

	if((DTC.Int.TempSnsrErrDTC_ClrReq == ON) ||	// 송신처에서 이벤트 신호로 보냄. 다음 주기에  자동으로 off됨.
	(DTC.Int.IGN1_IN_Evt.On_Event == ON))			// uds에서 보내던 것을 가식성 높게 직접 조건으로 추가함. ig off --> on시 클리어처리
	{
		DTC.Int.TempSnsrErrDTC_ClrReq = OFF;

		for(Device = 0; Device < DTC.Inp_NvM.DeviceMaxCnt; Device++)
		{
			DTC.Out.Device[Device].TempSnsrFaultDTC = OFF;
			DTC.Int.FaultOnCnt[Device] = 0;
			DTC.Int.TempSnsrFault[Device] = DETECTED_DEFAULT;
			DTC.Int.TempSnsrFaultChkDelayCnt[Device] = 0; // WPC_426_02 // 클리어 처리
		}
	}

// WPC_98_06
// define명은 short와 open이나 실제로 하드웨어로 open / short를 검출할수 없는 상황이다.
// 그래서 일단 비정상 전압을 감지하여 센서 fault로 처리한다.

// 여기서 판단한 값을 이용해서 채터링 처리는 모델에서 처리하므로 여기서는 채터링 처리 삭제한다.
// 양산 코드에서는 모델에서 판단된 센서 에러 값을 이용해서 DTC 판단했다.
// 하지만 이렇게 하면 온도 센서 페일 상태에서 DTC Clear 요청 왔을때 온도센서 DTC를 클리어는 할수 없다.
// 모델에서는 ign off --> On (wpc off mode) 일때만 fault가 off가 되므로
// dct 클리어해도 외부에서 dtc 판단 값을 클리어 할수가 없다.
// 그러므로 온도 센서 페일 dtc 판단 처리를 모델에서 주는 값을 사용하지 않고 별도 로직으로 판단한다.
// WPC_98_06

	for(Device = 0; Device < DTC.Inp_NvM.DeviceMaxCnt; Device++)
	{
		//-------------------------------------------------------
		// 온도 페일 DTC 판단 & 모델 전달용 Fault 판단.
		// ------------------------------------------------------
		if((DTC.Inp_ADC.IGN1_IN == ON) &&
		(DTC.Inp_ADC.BatSysStateFault == OFF))	// ig on 즉 충전 상태 일때만 DTC 판단
		{
			if (DTC.Inp_UART.Device_WCT[Device].TempSnsrError == ON)
			{
				if (DTC.Int.FaultOnCnt[Device] >= Par_TempSnsrFaultOnTime)	// 2sec // 진단 사양에 2초로 되어 있음
				{
					DTC.Int.TempSnsrFault[Device] = DETECTED_ON;
				}
				else
				{
					DTC.Int.FaultOnCnt[Device]++;
				}
			}
			else
			{
				DTC.Int.TempSnsrFault[Device] = DETECTED_OFF;
				DTC.Int.FaultOnCnt[Device] = 0;
			}

			// 온도 센서 페일 진단도 fan 진단과 동일하게 10초 딜레이 로직 적용함.
			// DTC 진단 표출만 10초 뒤에 표출되도록 함. 즉 10초 딜레이동안 에러 발생해도 10초 안에 복귀만 되면 dtc 표출 안됨
			if (DTC.Int.TempSnsrFaultChkDelayCnt[Device] >= Par_TempSnsrFaultChkDelayTime)// delay time 경과
			{
				//=========================================
				// TempSnsr falut DTC 판정 (복귀 안됨, ig off-->on시 클리어)
				//=========================================
				if(DTC.Int.TempSnsrFault[Device] == DETECTED_ON)
				{
					DTC.Out.Device[Device].TempSnsrFaultDTC = ON;	// dtc 용. ig off --> on시까지 유지됨.
				}
			}
			else
			{
				DTC.Int.TempSnsrFaultChkDelayCnt[Device] ++;
			}
		}
		else
		{
			DTC.Int.TempSnsrFault[Device] = DETECTED_DEFAULT;
			DTC.Int.FaultOnCnt[Device] = 0;
		}
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       Fan이 동작해야 하는 모드(충전중)인데 fan이 동작 하는 않는 경우를 Fault 판단한다.
			FanFault = on 후 FAN 정상 동작시 해제됨.
***************************************************************************************************/

// HB-5008H05R V01.pdf 문서 기준
// RPM = Frequency(f) x 30 (f : FG로 출력되는 주파수인듯. 확인 필요)
// 10% duty = 약 900 RPM
// 100% duty = 약 4500 RPM

// duty 10% 일때 f = 900 / 30 = 30hz , pulse 1개 길이 : 1/ 30 = 0.034 (34ms)
// duty 100% 일때 f = 4500 / 30 = 150hz , pulse 1개 길이 : 1/ 150 = 0.007 (7ms) --> 실측해 보니186Hz 측정됨.

// 그러므로 10ms task에서 FG 에서 출력되는 Pulse의 변화를 모두 측정이 불가하므로
// 확실하게 pulse가 측정 가능한 시간을 판단 주기로 변경한다.
// 위 내용대로 하면 출력 duyt의 min이 10%라고 가정할 경우
// 약 34ms이므로 10ms task로는 측정 불가함.
// 약 100ms 주기로 하면 적어도 10% duty 설정할경우 3회의 pulse는 나와야 함.
// 그러므로 fan fault 체크 주기는 100ms로 설정한다.


// fan fault 사양은 fan 구동 조건에서 FG에서 Pulse가 발생하지 않으면 Fault로 처리함.
// fan 구동 조건에서 pulse count값이 증가방향으로 변화가 있으면 정상 일정 시간이상 카운트 값이 변화가 없으면 fault로 판정
// fan이 구동중에 멈출수도 있으므로 pulse count값의 변화 여부를 관찰함.

// fan이 회전하지 않을때 FG값이 항상 High가 되면 위처럼 복자합게 할 필요 없음.
// 지금은 High or Low 를 유지한다고 하면 그냥 high인지 low 인지 여부만 확인해도 될듯.
// 하지만 재수 없으면 펄스의 high만 계속 읽을 수 있으므로 단순히 port이 high 여부만 판단하는 것은 위험하므로
// 지금처럼 펄스 카운트 측정하는 방법으로 하자.

// 사양
// - FAN 모터가 동작 진행 시 문제가 될 경우 DTC 발생
//   ㄴ 검출 시간은 2초 유지 시 DTC 발생
//   ㄴ FAN 모터가 정상적으로 출력이 들어 올 경우 DTC 클리어

// WPC FAN 모터 동작 중 Error 검출 시 DTC 검출건에 대한 협의 사항이 있어 메일을 송부 드립니다.

// 1. ERROR 검출 시간 : 2초 검출
//    ㄴ TM PE WPC FAN 모터가 정상 동작 후 이상 검출 시 2초간 검지 후 DTC 출력 (반영 완료)
//    ㄴ 모터가 정상적으로 동작 할 경우 Feedbak 신호를 검출 하여 정상 검출 (반영 완료)

// 2. 모터 검출 시 이상 조건 설명 : 2.5초 후 Feedback 신호 입력
//    ㄴ TM PE WPC에 전원 인가 후 충전 모드 진입 시 FAN 모터 동작 진행 (Feedback 입력이 2.5초 부터 발생)
//    ㄴ Sleep 상태에서 Wake_Up 후 충전 모드 진입 시  FAN 모터 동작 진행 (Feedback 입력이 0.25초 부터 발생)
//    ㄴ 니덱 WPC 제품에 반영된 FAN 모터 Error 검출 방식 변경 진행 (모터 출력 후 5초 이후부터 2초간 Error 검출 방식으로 변경 진행)
//    → FAN 모터의 전원을 분리 후 개선방향을 검토 하였으나, 현재는 FAN 모터가 동작 시점 부터 2초간 Error 검출은 어려운 상태 입니다.

// FAN 강제 구동 명령시에는 Fan Fault Check 실시하지 않는다.
// 강제 구동 시간이 5초 인데 니덱은 5초 안에 fan fault 여부 체크하지 못하게 되어 있다.
// 그러므로 사양적으로 문제이긴 하나 강제 구동시에는 체크 하지 않는다.
// 강제 구동시 충전 OFF 되므로 검출조건이 아니게 되어 강제 구동시에는 체크 하지 않게 된다.


// WPC_117_01
// FAN 입력 주파수 : 25Khz
// 주의
// fan feedback 주파수가 task 주기와 10ms (100hz) 동일한 100hz가될경우에는 (또는 200hz등 배수일때)
// high나  low만 계속 검출 될 수 있다.
// 일단 duty 20%의 경우에는 약 44hz (실측) 이므로 100hz(10ms Task) 보다 작으므로 항상 검출된다.
// 아래 로직을 사용한다.
// duty 100% : 172hz (실측), 20% 와 100% 사이에 100hz 영역 있음. 해당 duty 사용시에는 아래 로직 문제 있음.
static void ss_FanFaultCheck(void)// WPC_402_32
{

// 사양 만족 로직, 간헐적으로 에러 발생 후 정상 복귀시 DTC 코드 클리어 안됨.  (Ign off --> on시 DTC 클리어됨)
	// static TS_STATE_t 	FanFault_High[Device_MAX] = {DETECTED_DEFAULT, DETECTED_DEFAULT};
	// static TS_STATE_t 	FanFault_Low[Device_MAX] = {DETECTED_DEFAULT, DETECTED_DEFAULT};

	// static uint16_t FanFaultHigh_OnCnt[Device_MAX] = {0};
	// static uint16_t FanFaultLow_OnCnt[Device_MAX] = {0};
	// static uint8_t 	DirectRead_FANFG[Device_MAX] = {OFF};
	// static uint16_t FanFaultChkDelayCnt = 0;
	uint8_t Device;

	if((DTC.Int.FanFaultDTC_ClrReq == ON) || // 송신처에서 이벤트 신호로 보냄. 다음 주기에  자동으로 off됨.
    (DTC.Int.IGN1_IN_Evt.On_Event == ON)) // uds에서 보내던 것을 가식성 높게 직접 조건으로 추가함. ig off --> on시 클리어처리
	{
		DTC.Int.FanFaultDTC_ClrReq = OFF;

		for(Device = 0; Device < DTC.Inp_NvM.DeviceMaxCnt; Device++)
		{
			DTC.Int.FanFault_High[Device] = DETECTED_DEFAULT;
			DTC.Int.FanFault_Low[Device] = DETECTED_DEFAULT;

			DTC.Int.FanFaultHigh_OnCnt[Device] = 0;
			DTC.Int.FanFaultLow_OnCnt[Device] = 0;

			DTC.Out.Device[Device].FanFaultDTC = OFF;
			DTC.Out.Device[Device].FanFault = (uint8_t)DETECTED_OFF;

			DTC.Int.FanFaultChkDelayCnt[Device] = 0; // 클리어 처리
		}
	}


	for(Device = 0; Device < DTC.Inp_NvM.DeviceMaxCnt; Device++)
	{
		//=========================================
		// Fan Feedback Pulse가 연속적으로 High 상태 에러
		//=========================================
		if(((DTC.Inp_UART.Device_WCT[Device].DeviceState == Full_Charge) ||
		(DTC.Inp_UART.Device_WCT[Device].DeviceState == Charging)) &&
		(DTC.Inp_ADC.IGN1_IN == ON) &&
		(DTC.Inp_ADC.BatSysStateFault == OFF))
		{
			if(Device == (uint8_t)D0)
			{
				Rte_Call_R_FAN1_PULSE_ReadDirect(&DTC.Int.DirectRead_FANFG[Device]);
			}
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */	
			if((DTC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
			(DTC.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
			{
				if(Device == (uint8_t)D1)
				{
					Rte_Call_R_FAN2_PULSE_ReadDirect(&DTC.Int.DirectRead_FANFG[Device]);
				}
			}
//#endif	


			if(DTC.Int.DirectRead_FANFG[Device] == HIGH)
			{
				if (DTC.Int.FanFaultHigh_OnCnt[Device] >= Par_FanFaultOnTime)
				{
					DTC.Int.FanFault_High[Device] = DETECTED_ON;
				}
				else
				{
					DTC.Int.FanFaultHigh_OnCnt[Device]++;
				}

				DTC.Int.FanFaultLow_OnCnt[Device] = 0;
				DTC.Int.FanFault_Low[Device] = DETECTED_OFF;
			}
			else if(DTC.Int.DirectRead_FANFG[Device] == LOW)
			{
				if (DTC.Int.FanFaultLow_OnCnt[Device] >= Par_FanFaultOnTime)
				{
					DTC.Int.FanFault_Low[Device] = DETECTED_ON;
				}
				else
				{
					DTC.Int.FanFaultLow_OnCnt[Device]++;
				}

				DTC.Int.FanFaultHigh_OnCnt[Device] = 0;
				DTC.Int.FanFault_High[Device] = DETECTED_OFF;
			}
			else
			{
			// M3CM Rule-15.7
			}

			// DTC 진단 표출만 10초 뒤에 표출되도록 함. 즉 10초 딜레이동안 에러 발생해도 10초 안에 복귀만 되면 dtc 표출 안됨.
			if (DTC.Int.FanFaultChkDelayCnt[Device] >= Par_FanFaultChkDelayTime) // 클리어 처리 >= Par_FanFaultChkDelayTime)// delay time 경과
			{
				//=========================================
				// Fan falut DTC 판정 (복귀 안됨, ig off-->on시 클리어)
				//=========================================
				if((DTC.Int.FanFault_High[Device] == DETECTED_ON) ||
				(DTC.Int.FanFault_Low[Device] == DETECTED_ON))
				{
					DTC.Out.Device[Device].FanFaultDTC = ON;	// dtc 용. ig off --> on시까지 유지됨.
				}
			}
			else
			{
				DTC.Int.FanFaultChkDelayCnt[Device] ++; // 클리어 처리 ++; // 카운트 증가
			}

		}
		else
		{
			DTC.Int.FanFaultHigh_OnCnt[Device] = 0;
			DTC.Int.FanFaultLow_OnCnt[Device] = 0;

			DTC.Int.FanFault_High[Device] = DETECTED_DEFAULT;
			DTC.Int.FanFault_Low[Device] = DETECTED_DEFAULT;
		}

		//=========================================
		// Fan fault 판정 (복귀가능)
		//=========================================
		if((DTC.Int.FanFault_High[Device] == DETECTED_ON) ||
		(DTC.Int.FanFault_Low[Device] == DETECTED_ON))
		{
			DTC.Out.Device[Device].FanFault = (uint8_t)DETECTED_ON;		// fan duty 진단 표출시 에러 여부 판단용으로 사용. 복구시 ig off --> on 아니여도 복구됨.
		}
		else if((DTC.Int.FanFault_High[Device] == DETECTED_OFF) &&
		(DTC.Int.FanFault_Low[Device] == DETECTED_OFF))
		{
			DTC.Out.Device[Device].FanFault = (uint8_t)DETECTED_OFF;
		}
		else if((DTC.Int.FanFault_High[Device] == DETECTED_DEFAULT) &&
		(DTC.Int.FanFault_Low[Device] == DETECTED_DEFAULT))
		{
			DTC.Out.Device[Device].FanFault = (uint8_t)DETECTED_DEFAULT;		// fan fault 판단조건 아닐때는 진단에서 fan duty 출력을 0%로 하기 위해서 default 설정
		}
		else
		{
		// M3CM Rule-15.7
		}
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       SAG_DIAG.pdf의 3.7 Aging Counter 증가 조건 가이드 문서 참고하여 작성됨. (SBCM으로 부터 유용)
***************************************************************************************************/

static void ss_DtcActivationCheck(void)
{
    static Std_ReturnType mDtcConfigRteRetVal = E_NOT_OK;
    static Std_ReturnType mDtcRteRetVal[MDW_UDS_DTC_NUMBER] = {0}; // E_OK : 0
    static uint8_t mDtcSetVal[MDW_UDS_DTC_NUMBER] = {0}; 		// DEM_EVENT_STATUS_PASSED 0x00U
    static uint8_t mPrevDtcSetVal[MDW_UDS_DTC_NUMBER] = {0}; 	// DEM_EVENT_STATUS_PASSED 0x00U
    static Dem_EventStatusExtendedType DtcEventStatus[MDW_UDS_DTC_NUMBER] = {0};
    static Std_ReturnType retVal[MDW_UDS_DTC_NUMBER] = {0};
	static uint8_t mbBatStateFaultOld = ON;
    static uint8_t bDtcConditionVal[MDW_UDS_DTC_NUMBER] = {0};
    static uint8_t bBufIndex;	// for debug. break가 안결려서 static으로 변경함.

    static uint8_t bDTC_Cleared[MDW_UDS_DTC_NUMBER] = {0};
    Dem_EventStatusExtendedType prevDtcStatus = 0;
	Dem_EventStatusExtendedType nowDtcStatus = 0;
	
	static uint8_t PDC_ResetPreWrngForOthersOld = cResetPreWrng_NoWarning;


    if (mDtcConfigRteRetVal != E_OK) // 전원 인가시 최초 1회 실행
    {
        mDtcConfigRteRetVal = Rte_Call_R_StorageCond_DemStorageCondition_SetStorageCondition(TRUE);
    }


// 배터리 fail시 실행되는 로직이나
// B+ On 조건시 Start/ B+ off시 end 처리 실행될듯.
// SAG_DIAG.pdf 문서에 B+ on시와 B+off시에도 실행되어야 한다고 되어 있음
// 그리고 Deep Stop 진입시에도 end 처리되어야 한다고 되어 있음.
// mbBatStateFaultOld 이값을 초기 값을on으로 설정했으므로
// 최초 전원 인가시 Start 실행될듯.
// deep sleep 진입시 end는 별도로 호출해줘야 할듯.


// 전원 리셋시 aging counter 가 +1 증가 되는 현상은
// 모빌젠 Dem.arxml 설정에서 Operation Cycle Status Storage 설정이 True 여서 발생한 현상임.
// true 일 경우 operation cycle Start/Stop을 nvm 에 저장하므로
// 배터리 리셋이 되면 Start --> Start로 인식되어 aging counter가 +1됨
// 이 옵션을 true로 해놓은 이유는 GN7 개발시 False로 하고 싶었으나
// false로 할경우 Allgenerated 에서는 에러 발생하지 않으나
// 컴파일시 에러 발생해서 어쩔수 없이 true로 설정했음.

// 그러나 그 동안 플랫폼이 업데이트 되어서 false로 해도 컴파일까지 정상 동작함.
// 그래서 false로 했더니 배터리 리셋시 Start --> Start가 아니여서
// aging counter가 +1 증가 하지 않음.


// --> 위 방법은 신규로 적용하는 차종에만 적용 가능함
// 오토에버에 확인한 결과 위 옵션을 변경하면 NvM 블럭이 변경된다고함.
// 그러면 기존 FBL 과 변경 가능성이 있으므로 신규 차종 이외에는 적용하면 안됨.
// 그래서 MX5에는 적용하지 않음. (실차 조건에서 발생 가능성 희박함)
// DWPC에는 적용함.

	//B+ 전압 정상 -> 비정상 or 비정상 -> 정상으로 변경될 때.
    if ((DTC.Inp_ADC.BatSysStateFault != mbBatStateFaultOld) ||
	(DTC.Inp_CAN_RX.BCAN.C_PDC_ResetReqForOthers != PDC_ResetPreWrngForOthersOld))
    {
        if ((DTC.Inp_ADC.BatSysStateFault == OFF) && /* 정상 전압 -> PWR 그룹 DEM 시작 */
		(DTC.Inp_CAN_RX.BCAN.C_PDC_ResetReqForOthers != cResetPreWrng_Warning))
        {
            Rte_Call_R_OpCycle_DemOperationCycle_PWR_SetOperationCycleState(DEM_CYCLE_STATE_START); //B+상태 DTC감지 사이클 시작
            Rte_Call_R_OpCycle_DemOperationCycle_IGN_SetOperationCycleState(DEM_CYCLE_STATE_START); //IGN상태 DTC감지 사이클 시작

            // for (bBufIndex = (uint8_t)MDW_UDS_DTC_BCAN_BUS_OFF; bBufIndex < (uint8_t)MDW_UDS_DTC_NUMBER; bBufIndex++) // WPC_421_01
			for (bBufIndex = 0; bBufIndex < (uint8_t)MDW_UDS_DTC_NUMBER; bBufIndex++) // WPC_421_01
            {
                mPrevDtcSetVal[bBufIndex] = ~mDtcSetVal[bBufIndex];	// 값을 반대로 설정하는 이유는? -->반대로 설정해서 무조건 고장정보 설정이 1회 실행하기 위해서. 초기화 처리 같은 개념
            }
        }
        else/* 비정상 전압 -> PWR 그룹 DEM 중지 */
        {
            Rte_Call_R_OpCycle_DemOperationCycle_PWR_SetOperationCycleState(DEM_CYCLE_STATE_END); //B+상태 DTC감지 사이클 종료
            Rte_Call_R_OpCycle_DemOperationCycle_IGN_SetOperationCycleState(DEM_CYCLE_STATE_END); //IGN상태 DTC감지 사이클 종료
        }
    }

	mbBatStateFaultOld = DTC.Inp_ADC.BatSysStateFault;
	PDC_ResetPreWrngForOthersOld = DTC.Inp_CAN_RX.BCAN.C_PDC_ResetReqForOthers;


	// ign 30회 카운트 관련된 로직은 플랫폼에서 자동 처리되나 CYCLE 처리는 여기서 해야함.

	// Ign on/off 30회시 dtc 클리어 사양이 있는데
	// 모빌젠 설정에서 aging counter를 30으로 설정하면 31회째에 dtc가 클리어 된다.
	// 모빌젠 메뉴얼에 (SAG_Diag.pdf) dtc fail을 발생시킨 동일 사이클에 ign on/off를 해도
	// aging 카운터가 증가되지 않는다고 되어 있다.
	// 31회째 클리어 되는것은 위의 내용이 이유이나
	// 평가자입장에서는 고려 사항이 아니므로 모빌젠 설정을 30 --> 29로 변경한다.
	// 이렇게 하면 30회째에 dtc clear된다.


  	if((DTC.Int.IGN1_IN_Evt.Off_Event == ON) &&
	(DTC.Inp_CAN_RX.BCAN.C_PDC_ResetReqForOthers != cResetPreWrng_Warning)) // Prewarning이고 Ign off 시 DTC 진단 시작되면 안되므로
  	{
    	//Operation Restart
    	Rte_Call_R_OpCycle_DemOperationCycle_IGN_SetOperationCycleState(DEM_CYCLE_STATE_START); // START --> START, START --> END 시 AgingCounter 증가함.
  	}

// DTC WCT2도 추가 해야함.
	// single 시 강제로 OFF set
	if(DTC.Inp_NvM.WPC_TYPE == cWPC_TYPE4) /* only single */
	{
		DTC.Out.Device[D1].TempSnsrFaultDTC = OFF;
		DTC.Out.Device[D1].FanFaultDTC = OFF;
	}
	
	if((DTC.Out.Device[D0].TempSnsrFaultDTC == ON)
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */	
	|| (DTC.Out.Device[D1].TempSnsrFaultDTC == ON) // single일 경우 이값은 항상 OFF가 되도록 해당 모듈에서 설정하자.
//#endif
	)	
	{
		bDtcConditionVal[MDW_UDS_DTC_Temp_Snsr_Fault] = ON;	// 판단 버퍼에 저장
	}
	else
	{
		bDtcConditionVal[MDW_UDS_DTC_Temp_Snsr_Fault] = OFF;	// 판단 버퍼에 저장
	}

	if((DTC.Out.Device[D0].FanFaultDTC == ON)
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */	
	|| (DTC.Out.Device[D1].FanFaultDTC == ON) // single일 경우 이값은 항상 OFF가 되도록 해당 모듈에서 설정하자.
//#endif
	)
	{
		bDtcConditionVal[MDW_UDS_DTC_Fan_Fault] = ON;	// 판단 버퍼에 저장
	}
	else
	{
		bDtcConditionVal[MDW_UDS_DTC_Fan_Fault] = OFF;	// 판단 버퍼에 저장
	}
	

	if(DTC.Out.WctIcErrorDTC == ON)
	{
		bDtcConditionVal[MDW_UDS_DTC_ECU_Internal_ERR] = ON;	// 판단 버퍼에 저장
	}
	else
	{
		bDtcConditionVal[MDW_UDS_DTC_ECU_Internal_ERR] = OFF;	// 판단 버퍼에 저장
	}
// WPC_421_01

	// Dtc Status  (Dem User Manual 에 있음)
	// bit 0 : TestFailed (현재 고장 의미)
	// bit 3 : ConfirmedDTC (과거 고장 의미)
    // for (bBufIndex = (uint8_t)MDW_UDS_DTC_BCAN_BUS_OFF; bBufIndex < (uint8_t)MDW_UDS_DTC_NUMBER; bBufIndex++) // WPC_421_01
	for (bBufIndex = 0; bBufIndex < (uint8_t)MDW_UDS_DTC_NUMBER; bBufIndex++) // WPC_421_01
    {
        if (Mdw_Uds_FnTable_GetEventStatus[bBufIndex] != NULL) // WPC_420_02// 단위시험 오류 사항으로 수정함. // 항상 true이므로 불필요함.
        {
			// 0x09는 어떤 의미인지?
            prevDtcStatus = DtcEventStatus[bBufIndex] & 0x09u;       //0x09: 0000 1001 -> Confirmed * TestFail Flag
            retVal[bBufIndex] = Mdw_Uds_FnTable_GetEventStatus[bBufIndex](&DtcEventStatus[bBufIndex]); // WPC_420_02
            nowDtcStatus = (DtcEventStatus[bBufIndex] & 0x09u);

			// retVal[bBufIndex] 이 값은 미사용인지? --> 리턴값 저장용.미사용
			// 이전값과 현재 값이 다르면 클리어 요청을 하는 이유는? --> 플랫폼은 dtc 클리어 여부를 알고 있으나 어플리케이션은 모름.
			// 어플리케이션에 dtc 클리어 여부 알려주고 어플리케이션은 고장 진단을 초기화후 다시 고장 진단 하라는 의미임.
            if ((prevDtcStatus != 0u) &&	// 고장이 있다가 클리어 되었으므로 어플리케이션에 클리어 요청하기 위함.
                (nowDtcStatus == 0u))
            {
                bDTC_Cleared[bBufIndex] = ON;	// 이벤트 신호와 동일하게 동작함.
            }
            else
            {
                bDTC_Cleared[bBufIndex] = OFF;	// 이벤트 신호와 동일하게 동작함.
            }
       }


		// BCAN/LCAN은 플랫폼에서 처리하므로 여기서는 처리하지 않는다.
		// 어플리케이션 고장 정보만 설정 처리한다.
		// bBufIndex가 BCAN/LCAB은 Mdw_Uds_FnTable_SetEventStatus[0], Mdw_Uds_FnTable_SetEventStatus[1] 가
		// 0으로 define했으므로 처리되지 않고  else 처리 된다.

        if (Mdw_Uds_FnTable_SetEventStatus[bBufIndex] != NULL)
        {
            if (bDtcConditionVal[bBufIndex] != OFF)
            {
                mDtcSetVal[bBufIndex] = ON;
            }
            else
            {
                mDtcSetVal[bBufIndex] = OFF;
            }

            if (mPrevDtcSetVal[bBufIndex] != mDtcSetVal[bBufIndex])
            {
                if (bDtcConditionVal[bBufIndex] != 0u)
                {
                    mDtcSetVal[bBufIndex] = DEM_EVENT_STATUS_FAILED;
                }
                else
                {
                    mDtcSetVal[bBufIndex] = DEM_EVENT_STATUS_PASSED;
                }

                //DTC Failed set Request
                mDtcRteRetVal[bBufIndex] = Mdw_Uds_FnTable_SetEventStatus[bBufIndex](mDtcSetVal[bBufIndex]);	// 고장 정보 Fail/Pass 여부 설정

                if (mDtcRteRetVal[bBufIndex] == E_OK)	// OK가 아니면 다시 설정 시도하도록 리턴값이 OK일때만 변경.
                {
                    mPrevDtcSetVal[bBufIndex] = mDtcSetVal[bBufIndex];
                }
            }
        }
    }

	// SWP에서 DTC All Clear든 개별 Clear든 수신하게되면 자동으로 DTC가 Clear 되므로
	// 그정보가 클리어되면 아래 로직에서 판단해서 어플리케이션에 클리어 요청하게 된다.
	// 별도로 플래그로 판단하여 요청 할 필요 없다.


	// DTC 개별  Clear
	if(bDTC_Cleared[MDW_UDS_DTC_ECU_Internal_ERR] == ON)
    {
		DTC.Int.WctIcErrDTC_ClrReq = ON;
    }

	// DTC 개별  Clear
	if(bDTC_Cleared[MDW_UDS_DTC_Temp_Snsr_Fault] == ON)
    {
		DTC.Int.TempSnsrErrDTC_ClrReq = ON;
    }

	// DTC 개별  Clear
	if(bDTC_Cleared[MDW_UDS_DTC_Fan_Fault] == ON)
    {
		DTC.Int.FanFaultDTC_ClrReq = ON;
    }
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(Std_ReturnType, App_DTC_CODE) ECU_Internal_ERR_InitMonitorForEvent_IE_Runnable(
	IN VAR(Dem_InitMonitorReasonType, AUTOMATIC) InitMonitorReason)
{
	Std_ReturnType retValue = RTE_E_OK;

	return retValue;
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(Std_ReturnType, App_DTC_CODE) Fan_Fault_InitMonitorForEvent_IE_Runnable(
	IN VAR(Dem_InitMonitorReasonType, AUTOMATIC) InitMonitorReason)
{
	Std_ReturnType retValue = RTE_E_OK;

	return retValue;
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(Std_ReturnType, App_DTC_CODE) TempSnsr_Fault_InitMonitorForEvent_IE_Runnable(
	IN VAR(Dem_InitMonitorReasonType, AUTOMATIC) InitMonitorReason)
{
	Std_ReturnType retValue = RTE_E_OK;

	return retValue;
}



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_DTC_L2H_Set(void)
{
	DTC.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_DTC_H2L_Set(void)
{



}


#define App_DTC_STOP_SEC_CODE
#include "App_DTC_MemMap.h"
