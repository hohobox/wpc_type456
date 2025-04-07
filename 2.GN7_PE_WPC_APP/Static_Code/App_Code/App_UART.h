/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  APP_UART_H
#define  APP_UART_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/

// Time for Uart Rx Wait Timeout
#define Par_WctUartTimeoutTime		(2000u 	/ TIME_10MS) // DTC 스펙에서 Detecting Time 2000ms 이므로 2초로 설정한다.
#define Par_WctUartTimeoutCnt       (3u)  
#define Par_ReproUartTimeoutTime	(2000u 	/ TIME_10MS)
// single에서는 충전IC 최초 라이팅후 캘리브레이션시에 약 1초 이내로 걸렸는데
// 듀얼에서는 4초 전후로 걸리는 경우가 있음
// 그래서 기존 4초 설정으로 OK된 경우도 있지만 실패하는경우도 있음
// 그래서 5초 일단 변경해보니 캘리브레이션 정상 동작함.
// 이부분 요청해서 single 과 동일한 시간으로 단축 필요함.
#define Par_InitUartTimeoutTime		(5000u 	/ TIME_10MS) // 최초 전원 인가시는 충전 Ic 부팅 타임이 500ms 이므로 노멀과 동일하게 2초로 해도 무방함.


#define Par_TransmitTime			(3000u 	/ TIME_10MS)
#define Par_TransmitIntervalTime	(100u 	/ TIME_10MS)

#define cHeader_Request 	0xC5u
#define cHeader_Response 	0xBAu

// rx index
#define cRequest_Cmd_Index0			0u
// rx size
#define cRequest_Cmd_Size			4u


// tx index
#define cResponse_Data_Index0	    0u
#define cResponse_Data_Index1		1u
#define cResponse_Data_Index2		2u
#define cResponse_Data_Index3		3u
#define cResponse_Data_Index4		4u
#define cResponse_Data_Index5		5u
#define cResponse_Data_Index6		6u
#define cResponse_Data_IndexF	    0xfu
// tx size
#define cResponse_Data_Size			19u

/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


// 모델 define과 동일하게 redefine하여 디버그에서 글자로 모니터링 가능하게 한다.
// --> 모델에 Prepare define이 없으므로 모델 define 사용하지 않기로 함.

#define cInit                0U
#define cDeviceStatReserved  1U
#define cStandby             2U
#define cCharging            3U
#define cFull_Charge         4U
#define cFODError            5U
#define cDeviceError         6U
#define cSystemError         7U
#define cNVMError            8U
#define cAPPError            9U
#define cErrorComm			 10U
#define cPrepareCharging	 11U


typedef enum
{
    WCT_TX_STS_HALT                 = 0U,   // Chip verification failed.
    WCT_TX_STS_APP_HALT             = 1U,   // Application stopped TX by calling WCT_Stop().
    WCT_TX_STS_OBJECT_DETECTION     = 2U,   // TX is detecting existence of the RX.
    WCT_TX_STS_COIL_SELECTION       = 3U,   // TX is selecting the best coil.
    WCT_TX_STS_COIL_SELECTION_CFM   = 4U,   // TX is confirming the best coil.
    WCT_TX_STS_DIGITAL_PING         = 5U,   // TX has found the best coil. Do digital ping as in specification.
    WCT_TX_STS_NFC_DETECTION        = 6U,
    WCT_TX_STS_IDENTIFICATION       = 7U,   // TX is in identification state as in specification.
    WCT_TX_STS_CONFIGURATION        = 8U,   // TX is in configuration state as in specification.
    WCT_TX_STS_NEGOTIATION          = 9U,   // TX is in negotiation state as in specification.
    WCT_TX_STS_CALIBRATION          = 10U,  // TX is in calibration state as in specification.
    WCT_TX_STS_POWER_TRANSFER       = 11U,  // TX is in power transfer state as in specification.
    WCT_TX_STS_RENEGOTIATION        = 12U,  // TX is in re-negotiation state as in specification
    WCT_TX_STS_RECHARGE_RETRY       = 13U,  // TX waits some time to restart if an error occurs, unless RX is removed.
    WCT_TX_STS_CLOAKING             = 14U // mpp support
} WCT_TX_CHARGING_STATUS_E;

typedef enum
{
    WCT_TX_ERR_SUCCESS              = 0U,
    WCT_TX_ERR_CHIP                 = 1U,
    WCT_TX_ERR_PRE_FOD              = 2U,   // 무선충전 초기 진입 중 발생하는 fod 에러. Q-Factor로 확인함.
    WCT_TX_ERR_FOD                  = 3U,   // 충전중 발생하는 fod, power loss로 확인함.
    WCT_TX_ERR_QFOD                 = 4U,   // 협상 단계에서 발생하는 FOD, EPP사용함
    WCT_TX_ERR_RUNTIME_PARAM        = 5U,
    WCT_TX_ERR_CHARGE_REPEATED_FAIL = 6U,
    WCT_TX_ERR_RETRY_DPING			= 8U	//Add one Tx error mode for DP only status, // 휴대폰 방치 모드로 추가됨.
} WCT_TX_CHARGING_ERRORS_E;

typedef enum
{
    WCT_RX_STS_NONE              = 0U,  // 핸드폰 감지 안될때, 아날로그 핑 쏘는 단계
    WCT_RX_STS_PREPARE_CHARGE    = 1U,  // can be seen as RX detected and give user indication, // 디지털 핑 쏘면서 SS데이터 수신하고 있을때
    WCT_RX_STS_CHARGING          = 2U,  // real charging, but indication may be slow, // 충전중
    WCT_RX_STS_CHARGED           = 3U,  // Full 충전
    WCT_RX_STS_LIMITED_CHARGING  = 4U,
    WCT_RX_STS_UNDEFINE          = 5U,  // 무선충전 안되는 폰이나 물체 올려져 있을때, 정의 안된 상태, fod error and recharge retry state
    WCT_RX_STS_FAULT             = 6U,   // 핸드폰에 문제 발생시
    WCT_RX_STS_CLOAKING          = 7U   // mpp support
} WCT_RX_CHARGING_STATUS_E;

typedef enum
{
    WCT_RX_ERR_SUCCESS                     = 0U,
    WCT_RX_ERR_EPT_UNKNOWN                 = 1U,
    WCT_RX_ERR_EPT_INTERNAL_FAULT          = 2U,
    WCT_RX_ERR_EPT_OVER_TEMP               = 3U,
    WCT_RX_ERR_EPT_OVER_VOLT               = 4U,
    WCT_RX_ERR_EPT_OVER_CURRENT            = 5U,
    WCT_RX_ERR_EPT_BATTERY_FAILURE         = 6U,
    WCT_RX_ERR_EPT_NO_RESPONSE             = 7U,
    WCT_RX_ERR_EPT_RESTART_POWERTRANSFER   = 8U,
    WCT_RX_ERR_EPT_NEGOTIATION_FAILURE     = 9U,
    WCT_RX_ERR_EPT_REPING				   = 10U,
    WCT_RX_ERR_EPT_NFC					   = 11U,
    WCT_RX_ERR_EPT_PTX_NFC				   = 12U,
    WCT_RX_ERR_EPT_RESERVED                = 13U,
    WCT_RX_ERR_PACKET_INCOMPATIBLE         = 14U,
    WCT_RX_ERR_POWER_BEYOND_CAPABILITY     = 15U,
    WCT_RX_ERR_RCVPWR_TIMEOUT              = 16U
} WCT_RX_CHARGING_ERRORS_E;

/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/


/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/

extern void ISR_Scb_Isr_Vector_94_Cat2(void);

extern void gs_App_UART_L2H_Set(void);
extern void gs_App_UART_H2L_Set(void);

#endif
