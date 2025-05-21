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
#include "EcuInfo.h"
#include "App_Uds.h"
#include "Rte_App_Uds.h"

#include "Rte_NvM_Type.h"
#include "App_WCT.h"
#include "App_NvM.h"
#include "App_UART.h"
#include "App_Secure.h"
#include "App_Model_types.h"
#include "App_Version.h"


#include "Hmg_Sha256.h"
#include "Fls.h"
#include "Fls_TypesLib.h"
#include "Hsm_HostAPI.h"
#include "cy_gpio.h"

#include "Dcm_Types.h"

#define RTE_ALLOW_CROSS_HEADER_INCLUSION  // 미선언시 컴파일 오류 발생함.
#include "Rte_App_WDT.h"				// Rte_Call_R_WDT_EN_WriteDirect(OFF) 사용하기 위해서
#include "Rte_SWC_DiagnosticService.h"  // ServiceRequestSupplierNotification_Indication() 사용하기 위해서

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


// 지금까지는 배포시의 진단 기능인 SWC_DiagnoticsService.arxml 를 사용하지 않고
// 별도로 Uds.c로 별도의 파일을 만들고 SWC도 Mdw_Dcm.arxml을 별도로 만들어서 사용했다.
// 그러나 하모니할때 배포처에서는 SWC_DiagnoticsService.arxml 을 이용해서
// 테스트하고 배포하게 되는데 이것을 받아서 다시 니덱에서 uds.arxml로 변환하는 과정에서
// 하모니가 잘 안되는 문제를 발견함.
// uds로 변환하지 않고 그대로 사용하면 하모니가 정상적으로 되나 변경시에는 어디서 충돌이 나는지
// 정상으로 잘 안됨.
// 그래서 배포시에 추가되어 있는 SWC_DiagnoticsService.arxml 은 ASK의 배포시 추가된 기능은 그대로 사용하고
// App_Uds.arxml은 추가된 진단 id등으로 사용하기로 한다.


/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/


/* Write Infomation - Product Infomation */
#define 	cEcuDataCode 			(uint8_t)0xBB			/* ECU Data - partNumber / dateNumber / hardVersion */
#define 	cSerialNumCode 			(uint8_t)0xBD			/* Serial Number */

/* ECUSoftwareUNITnumber */
#define cECUSoftwareUNITnumber 0x01

#define cDiagSessionP3Timer     (uint16_t)500   /* 5s */

#define UDS_IGN1_MASK				0x01u
#define UDS_AMBER_MASK				0x02u
#define UDS_AMBER_BLINK_MASK		0x04u
#define UDS_GREEN_MASK				0x08u

#define UDS_LF_SEARCH_MASK			0x10u
#define UDS_CHARGE_OFF_MASK			0x60u
#define UDS_CHARGE_ON_MASK			0x20u
#define UDS_CHARGE_COMP_MASK		0x40u
#define UDS_CHARGE_INVALID_MASK		0x60u

#define UDS_IGN1_MASK_WPC2			0x01u	// reserved 미사용
#define UDS_AMBER_MASK_WPC2			0x02u
#define UDS_AMBER_BLINK_MASK_WPC2	0x04u
#define UDS_GREEN_MASK_WPC2			0x08u

#define UDS_LF_SEARCH_MASK_WPC2			0x10u // reserved 미사용
#define UDS_CHARGE_OFF_MASK_WPC2		0x60u
#define UDS_CHARGE_ON_MASK_WPC2			0x20u
#define UDS_CHARGE_COMP_MASK_WPC2		0x40u
#define UDS_CHARGE_INVALID_MASK_WPC2	0x60u


#define UDS_CharignMode_Default	0x00u
#define UDS_CharignMode_BPP 	0x01u
#define UDS_CharignMode_SFC 	0x02u
#define UDS_CharignMode_EPP 	0x03u

#define UDS_AuthState_NOT_AUTH 	0x00u
#define UDS_AuthState_AUTH 		0x01u


// WPC_20_01 start
// MCRT --> UTP --> Section에서 ASW영역만 아래에 기록
// aSIMS.ini
// [HASH_ALL_SECTION_START]
// AllSection =0x10058000--0x1005880f, 0x10059000--0x100600FF, 0x10060200--0x101F00FF, 0x101F0200--0x101F7FFF
// [HASH_ALL_SECTION_END]
// --> sector 2개로 변경됨
// [HASH_ALL_SECTION_START]
// AllSection =0x10058000--0x1005880F, 0x10059000--0x101F7FFF
// [HASH_ALL_SECTION_END]

#define CODE_BASE_START1                    0x10058000u
#define CODE_BASE_END1                      0x1005880Fu

#define CODE_BASE_START2                    0x10059000u
#define CODE_BASE_END2                      0x101F7FFFu

// #define CODE_BASE_START3                    0x10060200u
// #define CODE_BASE_END3                      0x101F00FFu

// #define CODE_BASE_START4                    0x101F0200u
// #define CODE_BASE_END4                      0x101F7FFFu
// WPC_475_01
// #define CODE_SIZE_UNIT                      0x00000040UL	// 64
// 약 2분 걸림. (한주기 실행시간 약 50us)
// pending 계속 회신하다가 네거티브 응답함. pendig 시간이 일정 시간 경과되면 negative 송신하는듯.
// #define CODE_SIZE_UNIT                      0x00000080UL	// 128


// 약 1분 걸림. (한주기 실행시간 약 100us)
// #define CODE_SIZE_UNIT                      0x00000100UL	// 256


// 약 30초 걸림. (한주기 실행시간 약 230us)
#define CODE_SIZE_UNIT                      0x00000200UL	// 512  // WPC_475_01 // WPC_420_01 // WPC_419_01 // WPC_46_02

// 약 17초 걸림. (한주기 실행시간 약 430us)
// #define CODE_SIZE_UNIT                      (uint32)0x00000400UL	// 1024 // WPC_422_04 // WPC_420_01

// 약 9초 걸림. (한주기 실행시간 약 870us)
// #define CODE_SIZE_UNIT                      (uint32)0x00000800	// WPC_475_01 // 2048 // WPC_422_04 // WPC_420_01 // WPC_419_01 // WPC_46_02

// 약 초 걸림. (한주기 실행시간 약 us)
// #define CODE_SIZE_UNIT                      0x00001000UL	// 4096 // OS 에러 발생함.

// WPC_418_05
#define Hash_Default     (uint8_t)0
#define Hash_OK          (uint8_t)1
#define Hash_During      (uint8_t)2
#define Hash_NG          (uint8_t)3
// WPC_418_05

// WPC_20_01 stop

#define  Macro_BIT_SET(val, mask)    	((val) |=  (mask))
#define  Macro_BIT_CLR(val, mask)		((val) &= ~(mask))


// N.0A_09 start
/* not Supported PID */
#define cPID_Not    0x00

/* Supported PID - uint8_t 0 */
#define cPID_01     0x80u
#define cPID_02     0x40u
#define cPID_03     0x20u
#define cPID_04     0x10u
#define cPID_05     0x08u
#define cPID_06     0x04u
#define cPID_07     0x02u
#define cPID_08     0x01u

/* Supported PID - uint8_t 1 */
#define cPID_09     0x80u
#define cPID_0A     0x40u
#define cPID_0B     0x20u
#define cPID_0C     0x10u
#define cPID_0D     0x08u
#define cPID_0E     0x04u
#define cPID_0F     0x02u
#define cPID_10     0x01u

/* Supported PID - uint8_t 2 */
#define cPID_11     0x80u
#define cPID_12     0x40u
#define cPID_13     0x20u
#define cPID_14     0x10u
#define cPID_15     0x08u
#define cPID_16     0x04u
#define cPID_17     0x02u
#define cPID_18     0x01u

/* Supported PID - uint8_t 3 */
#define cPID_19     0x80u
#define cPID_1A     0x40u
#define cPID_1B     0x20u
#define cPID_1C     0x10u
#define cPID_1D     0x08u
#define cPID_1E     0x04u
#define cPID_1F     0x02u
#define cPID_20     0x01u
// N.0A_09 stop

#define MDW_UDS_SERVICEID_DTC_CLEAR 0x14u

#define Par_SecureNgWaitCnt         (100000u / TIME_10MS) // WPC_125_05
#define Par_TestPresentHoldTime		(5000u 	/ TIME_10MS) /* 010A_02 */ // test present 타임아웃 4초이므로 더 길게함.

//#define Par_ReproProgressTimeout		(2000u / TIME_10MS) // 2sec

/* Supplier Code */
#define cSupplierCode1      'S' // 0x53
#define cSupplierCode2      'R' // 0x52
#define cSupplierCode3      '7' // 0x37
#define cSupplierCode4      '3' // 0x33

// SWC에서 runnable을 생성하지 않고 callback 함수를 사용하게 되면서 하기 define값이 생성안되므로 직접 선언함.
//#define DCM_E_PENDING 	10U

/****************************************************************
 FBL Version Info Address
****************************************************************/
volatile const uint8_t* Fbl_Version_Info = (uint8_t*)0x10057FE0;	/* 010D_01 */ // CYTXXX_Lite.ld 파일에 Section 영역에 FBL_VERSION_INFO 로 지정된 어드레스


#define UDS_B0BA_LIMIT		3u	/* WPC_2426_03 */

/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

typedef struct
{
	uint8_t App_Init_Completed;
	uint8_t Runnable_State;

	uint8_t	Repro_ProgressOld;

	uint8_t HashCal_State;
	uint8_t HashCalStatus;
	uint8_t digest1[HMG_SHA256_DIGEST_SIZE];
	uint8_t	HashCalStartReq;

    boolean Sha256Resp;
    HmgSha256Ctx ShaCtx;
    uint32 IncreaseAdd;

	uint16_t swDiagSessionTimer;

	//ECU_INFO EcuInfoTbl;			/* ECU Infomation */
	// uint8_t SerialNumber[15];		/* Serial Number */
	// uint8_t QRCode[21]; 			// QR Code Information

	HSM_SECURITY_INFO_t 		Securityinfo;
	HSM_CONFIG_LOCK_STATE_t 	ConfigurationLockState;

	//uint16_t	Uds_B0BADisableCnt;	/* WPC_2426_03 */
	uint16_t TestPresentHoldCnt;
} Inter_t;

typedef struct
{
	IDT_ADC_STR 	Inp_ADC;
	IDT_WCT_STR		Inp_WCT;
	IDT_NFC_STR		Inp_NFC;
	IDT_PWM_STR		Inp_PWM;
	IDT_Model_STR	Inp_Model;
	IDT_UART_STR 	Inp_UART;
	IDT_CAN_RX_STR 	Inp_CAN_RX;
	IDT_Repro_STR 	Inp_Repro;
	IDT_Mode_STR 	Inp_Mode;
	IDT_NvM_STR 	Inp_NvM;

	Inter_t 		Int;
	IDT_Uds_STR 	Out;

} Uds_Var_t;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/


static Uds_Var_t Uds = {0};
static NonSleepReason_t NonSleepReason = {0};	/* WPC_1905_01 */

/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/

static void ss_Uds_LPConditionCheck(void);
static void ss_Uds_TimerUpdate(void);

static void ss_Uds_HashCalculate(void);

static void ss_Uds_InitSet(void);
static void ss_Uds_RteRead(void);
static void ss_Uds_RteWrite(void);

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/
extern const SW_BlkFlashInfo App_SoftwareVersionHeader; /* 0108_14 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define App_Uds_START_SEC_CODE
#include "App_Uds_MemMap.h"

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_Uds_CODE) Uds_TE_Runnable(void)
{

	switch(Uds.Int.Runnable_State)
	{
		case 0u:// Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&Uds.Int.App_Init_Completed);

			if( Uds.Int.App_Init_Completed == ON ) /* SWP Init Complete? */
			{
				ss_Uds_InitSet();

				Uds.Int.Runnable_State = 1u;	/*  Main Runnable Mode Move > App Run */
			}
		break;

		case 1u:

			ss_Uds_RteRead();

			//ss_Uds_HashCalculate();

			ss_Uds_TimerUpdate();

			ss_Uds_RteWrite();

			ss_Uds_LPConditionCheck();

		break;

		default:
			Uds.Int.Runnable_State = 0u;
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Uds_InitSet(void)
{
	memset(&Uds.Out, 0, sizeof(Uds.Out));

	// Rte_Call_R_CS_NvM_Read_ECUInfo(NvM_BLK_ECU_INFO, Uds.Int.EcuInfoTbl.data);
	// Rte_Call_R_CS_NvM_Read_ECUInfo(NvM_BLK_SERIALNUM, Uds.Int.SerialNumber);
	// Rte_Call_R_CS_NvM_Read_QRCode(Uds.Int.QRCode);

	Uds.Out.m_NFCOption	= ON; // dual은 항상 NFC 사양임. 어플리케이션에서는 사용하지 않는 신호이나 모델에서 사용중이므로 일단 항상 on으로 해서 rte로 전송함

	Rte_Read_R_NvM_NvM_STR(&Uds.Inp_NvM);			// 한꺼번에 수신
	Uds.Out.m_B0BADisableCnt = Uds.Inp_NvM.m_B0BADisableCnt;	// eeprom 불러옴.

	// 최초 수신한 배열 NvM 을 구조체로 즉시 출력하여 NvM 모듈에서 값이 변경되지 않도록 한다.
	memcpy(Uds.Out.m_ECU_Info, Uds.Inp_NvM.m_ECU_Info, ECU_INFO_SIZE);
	memcpy(Uds.Out.m_SerialNum, Uds.Inp_NvM.m_SerialNum, SERIAL_NUM_SIZE);
	memcpy(Uds.Out.m_QRCode, Uds.Inp_NvM.m_QRCode, QRCODE_SIZE);
	//memcpy(Uds.Out.m_WctSourceVer, Uds.Inp_NvM.m_WctSourceVer, WCT_VER_SIZE); // UDS에는 버전 사용하지 않음.

	Rte_Write_P_Uds_Uds_STR(&Uds.Out);	// 구조체로 한꺼번에 전송 // m_NFCOption, m_B0BADisableCnt 값 즉시 전송하기 위해서 초기화시 호출함.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Uds_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_ADC_ADC_STR(&Uds.Inp_ADC);
	Rte_Read_R_CAN_RX_CAN_RX_STR(&Uds.Inp_CAN_RX);
	Rte_Read_R_UART_UART_STR(&Uds.Inp_UART);
	Rte_Read_R_Repro_Repro_STR(&Uds.Inp_Repro);
	Rte_Read_R_WCT_WCT_STR(&Uds.Inp_WCT);
	Rte_Read_R_NFC_NFC_STR(&Uds.Inp_NFC);
	Rte_Read_R_PWM_PWM_STR(&Uds.Inp_PWM);
	Rte_Read_R_Model_Model_STR(&Uds.Inp_Model);
	Rte_Read_R_NvM_NvM_STR(&Uds.Inp_NvM);


	// ign off시 IVD 다시 계산 하기 위해서 클리어 처리함.
	if(Uds.Inp_ADC.IGN1_IN == OFF)
	{
		Uds.Int.HashCal_State = 0;
		Uds.Int.HashCalStatus = Hash_Default;
		Uds.Int.HashCalStartReq = OFF;
		Uds.Int.Sha256Resp = 0;
		Uds.Int.IncreaseAdd = 0;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Uds_RteWrite(void)
{
	// On Off Request 신호 송신시에 이벤트 발생시키고 다음 request 송신 가능하도록 자동으로 default (0x00)로 변경한다.
	// 수신처에서는 기존 방법대로 event 체크하여 request on/off 여부 판단한다.
	// 100ms 후 default로 변경하는 이유는 강제 구동 수신 후 WCT_Diag 로 천히하기끼지 PVI Off 대기 시간이 50ms가 있으므로
	// 안전하게 100ms 후에 default로 초기화 처리 하도록 함
	// --> 전원 대기 시간은 wct 충전 ic에만 해당하고 pvi 전원은 해당 사항 없으므로 대기 시간 불필요하여 기존대로 원복함
	// gs_EventMsgAutoClear(&Uds.Out.DiagAmberBlink, &Uds.Int.DiagAmberBlink_Evt, Par_AutoClearTime_50ms);
	// gs_EventMsgAutoClear(&Uds.Out.DiagGreenBlink, &Uds.Int.DiagGreenBlink_Evt, Par_AutoClearTime_50ms);
	// gs_EventMsgAutoClear(&Uds.Out.DiagFanRotate, &Uds.Int.DiagFanRotate_Evt, Par_AutoClearTime_50ms);

	Rte_Write_P_Uds_Uds_STR(&Uds.Out);	// 구조체로 한꺼번에 전송

}


// N.0A_11 start
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Uds_TimerUpdate(void)
{
    if (Uds.Int.swDiagSessionTimer > 0u)
    {
        Uds.Int.swDiagSessionTimer--;
    }

/* 010A_02 */
	if(Uds.Int.TestPresentHoldCnt > 0)
	{
		Uds.Int.TestPresentHoldCnt --;
	}

	if(Uds.Int.TestPresentHoldCnt == 0)
	{
		Uds.Out.TestPresent = OFF;	// 자동 클리어 처리
	}
/* 010A_02 */
}
// N.0A_11 stop



// 진단 사양서 항목 순서대로 재배치함.
/*******************************************************************************
** Read Data by Identifier ($22 hex) Service                                  **
*******************************************************************************/
/*******************************************************************************
	Module Name : UserOptionRecordLocalIdentifier1 : $BE02 (len:19)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType InputOutputRecordLocalIdentifier1_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputRecordLocalIdentifier1_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;;

	//if(Uds.Inp_ADC.BatSysStateFault == OFF) /* 010E_01 */ // 배터리 비정상일때 진단 read하게 되면 Data[]에 저장된 쓰레기값으로 리턴될수 있어서 배터리 판단 로직 삭제함.
	{
		// 초기화
		// WPC_37_02
		// code sonar
		// Data[0] = 0; // 응답 값
		// Data[1] = 0;
		// Data[2] = 0;
		// Data[3] = 0;
		// Data[4] = 0;
		// Data[5] = 0;
		// Data[6] = 0;
		// Data[7] = 0;
		// Data[8] = 0;
		// Data[9] = 0;
		// Data[10] = 0;
		// Data[11] = 0;
		// Data[12] = 0;
		// Data[13] = 0;


		// Supported PID
		// Data[0] = ON; // 응답 값
		// Data[1] = 0x02;
		// Data[2] = 0x03;
		// Data[3] = 0x04;

		Data[0] = cPID_01 | cPID_02 | cPID_03 | cPID_04 | cPID_05 | cPID_06 | cPID_07 | cPID_08; 	/* 0x01 ~ 0x08 */
		Data[1] = cPID_09 | cPID_0A | cPID_0B | cPID_0C | cPID_0D | cPID_0E | cPID_0F | cPID_10;	/* 0x09 ~ 0x10 */
		Data[2] = cPID_Not;			/* 0x11 ~ 0x18 */
		Data[3] = cPID_Not; 		/* 0x19 ~ 0x20 */

		// data
		// 아래 공식은 진단기에서 읽을때 아래와 같이 처리한다는 뜻으로 풀이됨.
		// 그러므로 제어기에서는 저 공식과 반대로 보내야 진단기에서 실제 정보가 표출될것으로 생각됨.
		// 즉 제어기가 X 라는 값을 보내면 진단기는 0.08을 곱해서 표시한다는 뜻임.
		// 하기와 같이 변환식 상수가 결정된 이유 분석.
		// 최대값을 설정하고 그 최대값을 1바이트의 max값 255로 보내는 방식임.
		// 예를 들어 전압은 20V, 전류는 10A, 와트는 50W로 최대값을 설정했다.
		// 20(V) / 0.08 = 250
		// 10(A) / 0.0393 = 254
		// 50(W) / 0.196 = 255

		// #4	0x01	XX	Input	Charging Voltage	0.08 * X [V]
		// #5	0x02	XX	Input	Charging Current	0.0393 * X [A]
		// #6	0x03	XX	Input	Charging Power	0.196 * X [W]
		// #7	0x04	XX	Input	BAT+ Voltage	0.08 * X [V]
		// #8	0x05	XX	Input	IGN1 Voltage	0.08 * X [V]
		// #9	0x06	XX	Input	ActiveCoilID	1* X ( 0 ~ 2) Active Coil ID
		// #10	0x07	XX	Input	Coil1 TempSensor1	Unsigned Offset -40 1 * X (℃) (-40~85[℃])
		// #11	0x08	XX	Input	Coil2 TempSensor2	Unsigned Offset -40 1 * X (℃) (-40~85[℃])
		// #12	0x09	XX	Input	Coil3 TempSensor3	Unsigned Offset -40 1 * X (℃) (-40~85[℃])
		// #13	0x0A	XX	Input	FAN Speed	[%]
		// #14  0x0B    Reserved
		// #15  0x0C	XX	Input	WPC2 Charging Voltage	0.08 * X [V]
		// #16  0x0D	XX	Input	WPC2 Charging Current	0.0393 * X [A]
		// #17 	0x0E	XX	Input	WPC2 Charging Power	0.196 * X [W]
		// #18	0x0F	XX	Input	Coil1 TempSensor	Unsigned Offset -40 1 * X (℃) (-40~85[℃])
		// #19	0x10	XX	Input	WPC2 FAN Speed	[%]


		Data[4] = Uds.Inp_ADC.BATVolt_Convert; 						// 신호 생성처에서 미리 1바이트로 변환처리했음
		Data[5] = Uds.Inp_ADC.IGN1Volt_Convert;						// 신호 생성처에서 미리 1바이트로 변환처리했음

		Data[6] = Uds.Inp_UART.Device_WCT[D0].ChargingVolt_Convert;			// 신호 생성처에서 미리 1바이트로 변환처리했음
		Data[7] = Uds.Inp_UART.Device_WCT[D0].ChargingCurrent_Convert;		// 신호 생성처에서 미리 1바이트로 변환처리했음
		Data[8] = Uds.Inp_UART.Device_WCT[D0].ChargingPower_Convert;			// 신호 생성처에서 미리 1바이트로 변환처리했음
		Data[9] = Uds.Inp_UART.Device_WCT[D0].ActiveCoilID;
		//Data[10] = Uds.Inp_UART.Device_WCT[D0].CoilTempDegree_Convert; 		/* 0106_02 */ // 이미 Uart 모듈에서 전달될때 +40으로 1바이트 변환된 변수이므로 추가 +40변환은 하지 않는다.
		Data[10] = Uds.Inp_UART.Device_WCT[D0].CoilTempDegree + 40u; 		/* 0106_02 */
		Data[11] = 0; // temp2 // 온도 센서는 1개이므로 0으로 처리
		Data[12] = 0; // temp3 // 온도 센서는 1개이므로 0으로 처리
		Data[13] = (uint8_t)(Uds.Inp_PWM.Device[D0].FAN_PWM_DUTY_DIAG / 100u);// 강제구동까지 포함한 별도 rte 변수 생성.
		Data[14] = 0; // Reseved 0으로 처리함.


//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
		if((Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
		{
			Data[15] = Uds.Inp_UART.Device_WCT[D1].ChargingVolt_Convert;			// 신호 생성처에서 미리 1바이트로 변환처리했음
			Data[16] = Uds.Inp_UART.Device_WCT[D1].ChargingCurrent_Convert;		// 신호 생성처에서 미리 1바이트로 변환처리했음
			Data[17] = Uds.Inp_UART.Device_WCT[D1].ChargingPower_Convert;			// 신호 생성처에서 미리 1바이트로 변환처리했음
			// Data[18] = Uds.Inp_UART.Device_WCT[D1].CoilTempDegree_Convert; /* 0106_02 */  // 이미 Uart 모듈에서 전달될때 +40으로 1바이트 변환된 변수이므로 추가 +40변환은 하지 않는다.
			Data[18] = Uds.Inp_UART.Device_WCT[D1].CoilTempDegree + 40u; /* 0106_02 */
			Data[19] = (uint8_t)(Uds.Inp_PWM.Device[D1].FAN_PWM_DUTY_DIAG / 100u);// 강제구동까지 포함한 별도 rte 변수 생성.
		}
		else
		{
//#elif defined(WPC_TYPE4)	// Single
			Data[15] = 0;
			Data[16] = 0;
			Data[17] = 0;
			Data[18] = 0;
			Data[19] = 0;
		}

//#else
//   error : wpc type is not defined
//#endif






		retValue = RTE_E_OK;
	}

	return retValue;
}

/*******************************************************************************
	Module Name : UserOptionRecordLocalIdentifier2 : $BE03 (len:10)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType InputOutputRecordLocalIdentifier2_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputRecordLocalIdentifier2_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;;

	//if(Uds.Inp_ADC.BatSysStateFault == OFF) /* 010E_01 */ // 배터리 비정상일때 진단 read하게 되면 Data[]에 저장된 쓰레기값으로 리턴될수 있어서 배터리 판단 로직 삭제함.
	{
		// WPC_37_02
		// Data[0] = 0; // 응답 값
		// Data[1] = 0;
		// Data[2] = 0;
		// Data[3] = 0;
		// Data[4] = 0; // buffer clear

		// Supported PID
		// Data[0] = ON; // 응답 값
		// Data[1] = 0x02;
		// Data[2] = 0x03;
		// Data[3] = 0x04;
		Data[0] = cPID_01 | cPID_02 | cPID_03 | cPID_04 | cPID_05 | cPID_06 | cPID_07 | cPID_08; 	/* 0x01 ~ 0x08 */
		Data[1] = cPID_09 | cPID_0A | cPID_0B | cPID_0C | cPID_0D | cPID_0E | cPID_0F ;	/* 0x09 ~ 0x10 */
		Data[2] = cPID_12 | cPID_15 | cPID_16;			/* 0x11 ~ 0x18 */
		Data[3] = cPID_Not; 		/* 0x19 ~ 0x20 */

		// data (비트 제어임.)
		// #4	0x01	XX	B0	Input	IGN1 									(0:OFF / 1:ON)
		// 		0x02		B1	Input	WCT1 Amber LED On/Off Status			(0:OFF / 1:ON)
		// 		0x03		B2	Input	WCT1 Amber Blinking Status				(0:OFF / 1:Blinking)
		// 		0x04		B3	Input	WCT1 Green LED On/Off Status			(0:OFF / 1:ON)
		// 		0x05		B4	Input	SMK LF Searching Signal Status			(0:OFF / 1:ON)
		// 		0x06		B5	Input	WCT1 Charging Status					(0x00:Charging Off,  0x01:Charging, 0x02:Charging Complete, 0x03:Invalid) // 2bit
		// 		0x07		B6	Input	WCT1 Charging Status					(0x00:Charging Off,  0x01:Charging, 0x02:Charging Complete, 0x03:Invalid) // 2bit

		// #5	0x08		B0  Reserved 										0
		// 		0x09		B1	Input	WCT2 Amber LED On/Off Status			(0:OFF / 1:ON)
		// 		0x0A		B2	Input	WCT2 Amber Blinking Status				(0:OFF / 1:Blinking)
		// 		0x0B		B3	Input	WCT2 Green LED On/Off Status			(0:OFF / 1:ON)
		// 		0x0C		B4	Reserved										0
		// 		0x0D		B5	Input	WCT2 Charging Status					(0x00:Charging Off,  0x01:Charging, 0x02:Charging Complete, 0x03:Invalid) // 2bit
		// 		0x0E		B6	Input	WCT2 Charging Status					(0x00:Charging Off,  0x01:Charging, 0x02:Charging Complete, 0x03:Invalid) // 2bit

		// #6	0x0F	  	B0  Input   WCT Charging Mode						(0x00:Default, 0x01:BPP, 0x02:SFC(samsung fast charging, 0x03:EPP, 0x04~0x07:Reserved))
		//              	B1
		//              	B2

		// #7	0x12	  	B0  Input   WCT2 Charging Mode						(0x00:Default, 0x01:BPP, 0x02:SFC(samsung fast charging, 0x03:EPP, 0x04~0x07:Reserved))
		//              	B1
		//              	B2

		// #8	0x15	  	B0  Input   WCT Auth State							(0x00:Not Auth, 0x01:Auth)

		// #9	0x16	  	B0  Input   WCT2 Auth State							(0x00:Not Auth, 0x01:Auth)




		// PID 0x01
		if(Uds.Inp_ADC.IGN1_IN == ON)
		{
			Data[4] |= UDS_IGN1_MASK;	// Ign1 on
		}
		else
		{
			Data[4]  &= ~(UDS_IGN1_MASK); // Ign1 off // WPC_37_03
		}

		// PID 0x02
		if((Uds.Inp_PWM.Device[D0].AMBER_PWM_DUTY > 0u) &&
		(Uds.Inp_Model.Device[D0].BlinkState == OFF))
		// WPC_51_04
		{
			Data[4] |= UDS_AMBER_MASK;	// Led on
		}
		else
		{
			Data[4]  &= ~(UDS_AMBER_MASK); // Led off // WPC_37_03
		}

		// PID 0x03
		if(Uds.Inp_Model.Device[D0].BlinkState == ON)
		{
			Data[4] |= UDS_AMBER_BLINK_MASK;	// Amber Blink on
		}
		else
		{
			Data[4]  &= ~(UDS_AMBER_BLINK_MASK); // Amber Blink off // WPC_37_03
		}

		// PID 0x04
		// WPC_51_04
		//if((Uds.P_GreenIND_OUT < 10000u) || // 10000일때 LED 출력 OFF임
		//(Uds.DiagGreenBlinkStart == ON))
		if((Uds.Inp_PWM.Device[D0].GREEN1_PWM_DUTY > 0u) || // WPC_51_04
		(Uds.Inp_PWM.Device[D0].GREEN2_PWM_DUTY > 0u) || // WPC_402_35
		(Uds.Inp_PWM.Device[D0].GREEN3_PWM_DUTY > 0u)) // WPC_402_35
		// WPC_51_04
		{
			Data[4] |= UDS_GREEN_MASK;	// Led on
		}
		else
		{
			Data[4]  &= ~(UDS_GREEN_MASK); // Led off // WPC_37_03
		}

		// PID 0x05
		// if(Uds.b_LFState == ON) // GN7.12_02
		if(Uds.Inp_CAN_RX.BCAN.C_LFAnt_SrchSta == ON) // GN7.12_02
		{
			Data[4] |= UDS_LF_SEARCH_MASK;	// LF search on
		}
		else
		{
			Data[4]  &= ~(UDS_LF_SEARCH_MASK); // Led off // WPC_37_03
		}

		// PID 0x06, 0x07
		Data[4]  &= ~(UDS_CHARGE_OFF_MASK); // on/off가 아니므로 다른 비트와 혼합된다. 그러므로 매주기 all bit clear해야함.

		if((Uds.Inp_UART.Device_WCT[D0].DeviceState == cCharging) &&
		(Uds.Inp_Model.Device[D0].ChargingEnable == ON))
		{
			Data[4] |= UDS_CHARGE_ON_MASK;	// Chargeing on
		}
		else if((Uds.Inp_UART.Device_WCT[D0].DeviceState == Full_Charge) &&
		(Uds.Inp_Model.Device[D0].ChargingEnable == ON))
		{
			Data[4] |= UDS_CHARGE_COMP_MASK;	// Chargeing complete
		}

// WPC_37_03 start
		else if((Uds.Inp_UART.Device_WCT[D0].DeviceState == cInit) ||
		(Uds.Inp_UART.Device_WCT[D0].DeviceState == cStandby) ||
		(Uds.Inp_UART.Device_WCT[D0].DeviceState == cPrepareCharging) ||
		(Uds.Inp_UART.Device_WCT[D0].DeviceState == cFODError) ||
		(Uds.Inp_Model.Device[D0].ChargingEnable == OFF))	// 과열, 과전류, 온도센서에러. LfSearch일때 off됨. 폰방치 일때도 off됨.
		{
			Data[4]  &= ~(UDS_CHARGE_OFF_MASK); // Charge off
		}
		else
		{
			Data[4] |= UDS_CHARGE_INVALID_MASK;	// invalid
		}
// WPC_37_03 stop


//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
		if((Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
		{
			// PID 0x08 : reserved

			// PID 0x09
			if((Uds.Inp_PWM.Device[D1].AMBER_PWM_DUTY > 0u) &&
			(Uds.Inp_Model.Device[D1].BlinkState == OFF))
			{
				Data[5] |= UDS_AMBER_MASK_WPC2;	// Led on
			}
			else
			{
				Data[5]  &= ~(UDS_AMBER_MASK_WPC2); // Led off // WPC_37_03
			}

			// PID 0x0A
			if(Uds.Inp_Model.Device[D1].BlinkState == ON)
			{
				Data[5] |= UDS_AMBER_BLINK_MASK_WPC2;	// Amber Blink on
			}
			else
			{
				Data[5]  &= ~(UDS_AMBER_BLINK_MASK_WPC2); // Amber Blink off // WPC_37_03
			}

			// PID 0x0B
			if((Uds.Inp_PWM.Device[D1].GREEN1_PWM_DUTY > 0u) ||
			(Uds.Inp_PWM.Device[D1].GREEN2_PWM_DUTY > 0u) ||
			(Uds.Inp_PWM.Device[D1].GREEN3_PWM_DUTY > 0u))
			{
				Data[5] |= UDS_GREEN_MASK_WPC2;	// Led on
			}
			else
			{
				Data[5]  &= ~(UDS_GREEN_MASK_WPC2); // Led off // WPC_37_03
			}

			// PID 0x0C : reserved

			// PID 0x0D, 0x0E
			Data[5]  &= ~(UDS_CHARGE_OFF_MASK_WPC2); // on/off가 아니므로 다른 비트와 혼합된다. 그러므로 매주기 all bit clear해야함.

			if((Uds.Inp_UART.Device_WCT[D1].DeviceState == cCharging) &&
			(Uds.Inp_Model.Device[D1].ChargingEnable == ON))
			{
				Data[5] |= UDS_CHARGE_ON_MASK_WPC2;	// Chargeing on
			}
			else if((Uds.Inp_UART.Device_WCT[D1].DeviceState == Full_Charge) &&
			(Uds.Inp_Model.Device[D1].ChargingEnable == ON))
			{
				Data[5] |= UDS_CHARGE_COMP_MASK_WPC2;	// Chargeing complete
			}
			else if((Uds.Inp_UART.Device_WCT[D1].DeviceState == cStandby) ||
			(Uds.Inp_UART.Device_WCT[D1].DeviceState == cPrepareCharging) ||
			(Uds.Inp_UART.Device_WCT[D1].DeviceState == cFODError) ||
			(Uds.Inp_Model.Device[D1].ChargingEnable == OFF))	// 과열, 과전류, 온도센서에러. LfSearch일때 off됨. 폰방치 일때도 off됨.
			{
				Data[5]  &= ~(UDS_CHARGE_OFF_MASK_WPC2); // Charge off
			}
			else
			{
				Data[5] |= UDS_CHARGE_INVALID_MASK_WPC2;	// invalid
			}


			// PID 0xF
			Data[6] = Uds.Inp_UART.Device_WCT[D0].ChargingMode;
			// PID 0x12
			Data[7] = Uds.Inp_UART.Device_WCT[D1].ChargingMode;
			// PID 0x15
			Data[8] = Uds.Inp_UART.Device_WCT[D0].AuthState;
			// PID 0x16
			Data[9] = Uds.Inp_UART.Device_WCT[D1].AuthState;
		}
//#elif defined(WPC_TYPE4)	// Single
		else
		{
			Data[5] = 0;
			// PID 0xF
			Data[6] = Uds.Inp_UART.Device_WCT[D0].ChargingMode;
			Data[7] = 0;
			// PID 0x15
			Data[8] = Uds.Inp_UART.Device_WCT[D0].AuthState;
			Data[9] = 0;
		}

// #else
//    error : wpc type is not defined
// #endif


		retValue = RTE_E_OK;

	}

	return retValue;
}



/*******************************************************************************
	Module Name : ECUSecurityInformationDataIdentifier : $F1C0 (len:3)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType ECUSecurityInformationDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType ECUSecurityInformationDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;;
	Std_ReturnType result;
	Std_ReturnType ConfigurationLockState_result;
	Std_ReturnType secureBootState_result;
	Std_ReturnType secureDebugState_result;


	// #0	-	  	B0     Configuration Lock State					(0x00:Disabled, 0x01:Enabled)
	// #1	-	  	B0     Secure Boot State						(0x00:Disabled, 0x01:Enabled)
	// #2	-	  	B0     Secure Debug State						(0x00:Disabled, 0x01:Enabled, 0x2:DebugProtecction TempStop, 3:Debug Disable)

	result = HSM_GetConfigurationLockState(&Uds.Int.ConfigurationLockState);
	if(result != E_OK)
	{
		//Data[0] = 0xFF;
		Data[0] = 0; // Disable로 응답처리
	}
	else
	{
 		//HSM_CONFIG_LOCK_DISABLE = 0,
 		//HSM_CONFIG_LOCK_ENABLE = 1,
		//Data[0] = (uint8_t)Uds.Int.ConfigurationLockState;

		ConfigurationLockState_result = (uint8_t)Uds.Int.ConfigurationLockState;
		if(ConfigurationLockState_result == 1u)
		{
			Data[0] = 1u; // Enable로 응답처리
		}
		else
		{
			Data[0] = 0u; // 그 외는 Disable로 응답 처리
		}

	}

	result = HSM_GetAllSecurityInfo(&Uds.Int.Securityinfo);
	if(result != E_OK)
	{
		// Data[1] = 0xFF;
		// Data[2] = 0xFF;
		Data[1] = 0;// Disable로 응답처리
		Data[2] = 0;// Disable로 응답처리
	}
	else
	{
		//HSM_SECUREBOOT_DISABLE = 1,                         /*!< Disable */
		//HSM_SECUREBOOT_ENABLE = 2,                          /*!< Enable */
		//HSM_SECUREBOOT_SUCCESS = 3,                         /*!< Bootloader integrity verification success */
		//HSM_SECUREBOOT_NOT_PERFORMED = 12,                  /*!< Secure Boot not working */
		//Data[1] = (uint8_t)Uds.Int.Securityinfo.secureBootState;
		secureBootState_result = (uint8_t)Uds.Int.Securityinfo.secureBootState;
		if(secureBootState_result == 3u) /* 010E_02 */
		{
			Data[1] = 1u; // Enable로 응답처리
		}
		else
		{
			Data[1] = 0u; // 그 외는 Disable로 응답 처리
		}


		// Secure Debug State 값 관련 부연 설명 드립니다.
		// 0=Disabled (Secure Debug 미설정)
		// 1=Enabled (Secure Debug 설정)
		// 2=DebugProtectionTempStop (Secure Debug 설정 이후 인증에 따른 임시해제)
		// 3=Debug Disable (Debug port 미사용 설정), 영구적 미사용 설정시 해당함.

		//HSM_DEBUG_PROTECTION_DISABLE = 0,                   /*!< SECURE DEBUG Disable */
		//HSM_DEBUG_PROTECTION_ENABLE = 1,                    /*!< SECURE DEBUG Enable */
		//HSM_DEBUG_PROTECTION_TEMP_STOP = 2,                 /*!< SECURE DEBUG Pause */
		//Data[2] = (uint8_t)Uds.Int.Securityinfo.secureDebugState;
		secureDebugState_result = (uint8_t)Uds.Int.Securityinfo.secureDebugState;
		if(secureDebugState_result == 2u)
		{
			Data[2] = 2u; // Temp Stop으로 응답처리
		}
		else if(secureDebugState_result == 1u)
		{
			Data[2] = 1u; // Protection Enable로 응답 처리
		}
		else
		{
			Data[2] = 0u; // 그외 값은 Secure Debug 미설정으로 응답 처리
		}
		// 현대 사양에서에 있는 리턴값 3 (영구적 미사용 설정)은 해당 사항이 없으므로 로직에서 미적용함. /* 010E_02 */
	}

	retValue = RTE_E_OK;


	return retValue;
}


/*******************************************************************************
	Module Name : System Name : $F197  (len:3)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: System Name
*******************************************************************************/
Std_ReturnType SystemName_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType SystemName_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	Data[0] = (uint8_t)'W';
	Data[1] = (uint8_t)'P';
	Data[2] = (uint8_t)'C';

	return retValue;
}


/*******************************************************************************
	Module Name : VehicleManufacturerSparePartNumberDataIdentifier : $F187  (len:10)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: Vehicle Part Number
*******************************************************************************/
Std_ReturnType VehicleManufacturerSparePartNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType VehicleManufacturerSparePartNumberDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	// Data[0] = Uds.Int.EcuInfoTbl.PartNumber[0];  /* ECU PART NUMBER SET */
	// Data[1] = Uds.Int.EcuInfoTbl.PartNumber[1];
	// Data[2] = Uds.Int.EcuInfoTbl.PartNumber[2];
	// Data[3] = Uds.Int.EcuInfoTbl.PartNumber[3];
	// Data[4] = Uds.Int.EcuInfoTbl.PartNumber[4];
	// Data[5] = Uds.Int.EcuInfoTbl.PartNumber[5];
	// Data[6] = Uds.Int.EcuInfoTbl.PartNumber[6];
	// Data[7] = Uds.Int.EcuInfoTbl.PartNumber[7];
	// Data[8] = Uds.Int.EcuInfoTbl.PartNumber[8];
	// Data[9] = Uds.Int.EcuInfoTbl.PartNumber[9];

	Data[0] = Uds.Out.m_ECU_Info[0];  /* ECU PART NUMBER SET (0 ~ 9 : 10byte )*/
	Data[1] = Uds.Out.m_ECU_Info[1];
	Data[2] = Uds.Out.m_ECU_Info[2];
	Data[3] = Uds.Out.m_ECU_Info[3];
	Data[4] = Uds.Out.m_ECU_Info[4];
	Data[5] = Uds.Out.m_ECU_Info[5];
	Data[6] = Uds.Out.m_ECU_Info[6];
	Data[7] = Uds.Out.m_ECU_Info[7];
	Data[8] = Uds.Out.m_ECU_Info[8];
	Data[9] = Uds.Out.m_ECU_Info[9];

	// memcpy(Data, Uds.Int.EcuInfoTbl.data, sizeof(Uds.Int.EcuInfoTbl.PartNumber));
	return retValue;
}



/*******************************************************************************
	Module Name : ECUSoftwareUNITnumberDataIdentifier : $F1B0  (len:1)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: The number of S/W Unit
*******************************************************************************/
Std_ReturnType ECUSoftwareUNITnumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType ECUSoftwareUNITnumberDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	Data[0] = cECUSoftwareUNITnumber;	/* ECUSoftwareUNITnumber */

	return retValue;
}


/*******************************************************************************
	Module Name : ECUSoftwareUNIT1VersionDataIdentifier : $F1B1 (len:5)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: Supplier S/W Unit1 Version
*******************************************************************************/
Std_ReturnType ECUSoftwareUNIT1VersionDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType ECUSoftwareUNIT1VersionDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
/* 0108_14 */ // U/R/S 롬 컴파일시 자동으로 버전만 변경되어 3가지 s19가 자동으로 생성되도록 하기 위해서 로직 변경함.
	// Data[0] = (uint8_t)cAppSoftVerYear1;	/* Soft Version */
	// Data[1] = (uint8_t)cAppSoftVerYear2;
	// Data[2] = (uint8_t)cAppSoftVerMonth;
	// Data[3] = (uint8_t)cAppSoftVerOrder;
	// Data[4] = (uint8_t)cAppSoftVerOption;

	// hex에서 버전이 저장되는 address에서 다이렉트로 access하여 read함.
	Data[0] = App_SoftwareVersionHeader.currentVersion[0];	/* Soft Version */
	Data[1] = App_SoftwareVersionHeader.currentVersion[1];
	Data[2] = App_SoftwareVersionHeader.currentVersion[2];
	Data[3] = App_SoftwareVersionHeader.currentVersion[3];
	Data[4] = App_SoftwareVersionHeader.currentVersion[4];

/* 0108_14 */
	return retValue;
}


/*******************************************************************************
	Module Name : ECUManufacturingDateDataIdentifier : $F18B (len:4)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: Supplier H/W Version
*******************************************************************************/
Std_ReturnType ECUManufacturingDateDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType ECUManufacturingDateDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	// Data[0] = Uds.Int.EcuInfoTbl.Date[0];		/* Data */
	// Data[1] = Uds.Int.EcuInfoTbl.Date[1];
	// Data[2] = Uds.Int.EcuInfoTbl.Date[2];
	// Data[3] = Uds.Int.EcuInfoTbl.Date[3];

	Data[0] = Uds.Out.m_ECU_Info[10]; /* Date : 10 ~ 13 : 4byte */
	Data[1] = Uds.Out.m_ECU_Info[11];
	Data[2] = Uds.Out.m_ECU_Info[12];
	Data[3] = Uds.Out.m_ECU_Info[13];
	return retValue;
}

/*******************************************************************************
	Module Name : ECUSerialNumberDataIdentifier : $F18C  (len:15)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: Serial Number
*******************************************************************************/
Std_ReturnType ECUSerialNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType ECUSerialNumberDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	Data[0] = Uds.Out.m_SerialNum[0];		/* ECU SERIAL NUMBER SET */
	Data[1] = Uds.Out.m_SerialNum[1];
	Data[2] = Uds.Out.m_SerialNum[2];
	Data[3] = Uds.Out.m_SerialNum[3];
	Data[4] = Uds.Out.m_SerialNum[4];
	Data[5] = Uds.Out.m_SerialNum[5];
	Data[6] = Uds.Out.m_SerialNum[6];
 	Data[7] = Uds.Out.m_SerialNum[7];
	Data[8] = Uds.Out.m_SerialNum[8];
	Data[9] = Uds.Out.m_SerialNum[9];
	Data[10] = Uds.Out.m_SerialNum[10];
	Data[11] = Uds.Out.m_SerialNum[11];
	Data[12] = Uds.Out.m_SerialNum[12];
	Data[13] = Uds.Out.m_SerialNum[13];
	Data[14] = Uds.Out.m_SerialNum[14];
	return retValue;
}


/*******************************************************************************
	Module Name : VehicleManufacturerECUHardwareNumberDataIdentifier : $F191 (len:4)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType VehicleManufacturerECUHardwareNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType VehicleManufacturerECUHardwareNumberDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	// Data[0] = Uds.Int.EcuInfoTbl.HwVersion[0];
	// Data[1] = (uint8_t)'.';
	// Data[2] = Uds.Int.EcuInfoTbl.HwVersion[1];
	// Data[3] = Uds.Int.EcuInfoTbl.HwVersion[2];

	Data[0] = Uds.Out.m_ECU_Info[14]; /* hw versiohn : 14 ~ 16 : 3byte */
	Data[1] = (uint8_t)'.';
	Data[2] = Uds.Out.m_ECU_Info[15];
	Data[3] = Uds.Out.m_ECU_Info[16];


	return retValue;
}
/*******************************************************************************
	Module Name : SystemSupplierECUHardwareVersionNumberDataIdentifier : $F193 (len:4)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType SystemSupplierECUHardwareVersionNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType SystemSupplierECUHardwareVersionNumberDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	// Data[0] = (uint8_t)Uds.Int.EcuInfoTbl.HwVersion[0];
	// Data[1] = (uint8_t)'.';
	// Data[2] = (uint8_t)Uds.Int.EcuInfoTbl.HwVersion[1];
	// Data[3] = (uint8_t)Uds.Int.EcuInfoTbl.HwVersion[2];

	Data[0] = Uds.Out.m_ECU_Info[14]; /* hw versiohn : 14 ~ 16 : 3byte */
	Data[1] = (uint8_t)'.';
	Data[2] = Uds.Out.m_ECU_Info[15];
	Data[3] = Uds.Out.m_ECU_Info[16];

	return retValue;
}


/*******************************************************************************
	Module Name : SoftwareVersionforHKMCVehiclemanufactureDataIdentifier : $F1A0 (len:5)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: Vehicle S/W Version
*******************************************************************************/
Std_ReturnType SoftwareVersionforHKMCVehiclemanufactureDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
#if defined (DEBUG_AUTO_TEST_USE)		// 검증팀 AUTO TEST 용 hex 배포시에만 사용해야함. 진단 사양서상 F1A0 삭제 되었음
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
#else
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;	// F1A0 삭제된것과 동일한 부정 응답 코드 전송하도록 수정함
#endif
    return retValue;
}
Std_ReturnType SoftwareVersionforHKMCVehiclemanufactureDataIdentifier_Read(uint8* Data)
{
#if defined (DEBUG_AUTO_TEST_USE)		// 검증팀 AUTO TEST 용 hex 배포시에만 사용해야함. 진단 사양서상 F1A0 삭제 되었음
    Std_ReturnType retValue = RTE_E_OK;
#else
	Std_ReturnType retValue = E_NOT_OK; // F1A0 삭제된것과 동일한 부정 응답 코드 전송하도록 수정함
#endif

/* 0108_14 */ // U/R/S 롬 컴파일시 자동으로 버전만 변경되어 3가지 s19가 자동으로 생성되도록 하기 위해서 로직 변경함.
	// Data[0] = (uint8_t)cAppSoftVerYear1;	/* Soft Version */
	// Data[1] = (uint8_t)cAppSoftVerYear2;
	// Data[2] = (uint8_t)cAppSoftVerMonth;
	// Data[3] = (uint8_t)cAppSoftVerOrder;
	// Data[4] = (uint8_t)cAppSoftVerOption;

	// hex에서 버전이 저장되는 address에서 다이렉트로 access하여 read함.
	Data[0] = App_SoftwareVersionHeader.currentVersion[0];	/* Soft Version */
	Data[1] = App_SoftwareVersionHeader.currentVersion[1];
	Data[2] = App_SoftwareVersionHeader.currentVersion[2];
	Data[3] = App_SoftwareVersionHeader.currentVersion[3];
	Data[4] = App_SoftwareVersionHeader.currentVersion[4];
/* 0108_14 */

	return retValue;
}

/*******************************************************************************
	Module Name : ECUSupplierCodeDataIdentifier : $F1A1  (len:4)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: System Supplier Code
*******************************************************************************/
Std_ReturnType ECUSupplierCodeDataIdentifier_ConditionCheckRead(uint8* ErrorCode) // qac 에서 발견됨. 선언된것과 다르게 사용되고 있었음. 선언된것과 일치되게 변경
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType ECUSupplierCodeDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	Data[0] = (uint8_t)cSupplierCode1;	/* Supplier Code */
	Data[1] = (uint8_t)cSupplierCode2;
	Data[2] = (uint8_t)cSupplierCode3;
	Data[3] = (uint8_t)cSupplierCode4;

	return retValue;
}


/*******************************************************************************
	Module Name : CANDataBaseVersionNumberDataIdentifier : $F100  (len:4)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType CANDataBaseVersionNumberDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType CANDataBaseVersionNumberDataIdentifier_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	Data[0] = (uint8_t)cBCanDBVersion1;	/* Can DB Version */
	Data[1] = (uint8_t)'.';
	Data[2] = (uint8_t)cBCanDBVersion2;
	Data[3] = (uint8_t)cBCanDBVersion3;

	return retValue;
}

/*******************************************************************************
	Module Name : LocalRXSWINDataIdentifier  : $F1EF  (len:40)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType LocalRXSWINDataIdentifier_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType LocalRXSWINDataIdentifier_ReadDataLength(uint16* DataLength)
{
    Std_ReturnType retValue = RTE_E_OK;

	*DataLength = 0;
	*DataLength += 2u;							/* 진단 ID : 0x07, 0x25 */
	*DataLength += 1u + strlen(cRxSWINData1);	/* Length byte(1u) + 문자열 길이 */
	*DataLength += 1u + strlen(cRxSWINData2);
	*DataLength += 1u + strlen(cRxSWINData3); // 40byte
	
#if defined(EXTENDED_RXSWIN_ON) //  (65 byte)
	*DataLength += 1u + strlen(cRxSWINData4);
	*DataLength += 1u + strlen(cRxSWINData5);
	*DataLength += 1u + strlen(cRxSWINData6);
	*DataLength += 1u + strlen(cRxSWINData7);
#endif
	// total : 105 byte

    return retValue;
}
Std_ReturnType LocalRXSWINDataIdentifier_Read(uint8* Data)
{
// 좀더 단순하게 변경함.

// 메모리 할당 크기 ▶ sizeof
// 문자열의 길이 확인 ▶ strlen

// sizeof는 NULL문자를 포함한 메모리의 할당크기를 바이트단위로 구합니다.
// strlen는 순수하게 문자열의 길이만을 구합니다.

    Std_ReturnType retValue = RTE_E_OK;

    // Calculate lengths
    unsigned char len1 = strlen(cRxSWINData1); // Length of cRxSWINData1
    unsigned char len2 = strlen(cRxSWINData2); // Length of cRxSWINData2
    unsigned char len3 = strlen(cRxSWINData3); // Length of cRxSWINData3
/* 010D_03 */
#if defined(EXTENDED_RXSWIN_ON)
	unsigned char len4 = strlen(cRxSWINData4); // Length of cRxSWINData4
	unsigned char len5 = strlen(cRxSWINData5); // Length of cRxSWINData5
	unsigned char len6 = strlen(cRxSWINData6); // Length of cRxSWINData6
	unsigned char len7 = strlen(cRxSWINData7); // Length of cRxSWINData7
#endif
/* 010D_03 */

    uint8_t index = 0;

	// Add Request ID
	Data[index++] = 0x07;
	Data[index++] = 0x25;

	// Add length and cRxSWINData1
    Data[index++] = len1; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData1, len1);
    index += len1;

    // Add length and cRxSWINData2
    Data[index++] = len2; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData2, len2);
    index += len2;

    // Add length and cRxSWINData3
    Data[index++] = len3; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData3, len3);
    index += len3;

/* 010D_03 */
#if defined(EXTENDED_RXSWIN_ON)
    // Add length and cRxSWINData4
    Data[index++] = len4; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData4, len4);
    index += len4;

    // Add length and cRxSWINData5
    Data[index++] = len5; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData5, len5);
    index += len5;

    // Add length and cRxSWINData6
    Data[index++] = len6; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData6, len6);
    index += len6;

    // Add length and cRxSWINData7
    Data[index++] = len7; // Add length as ASCII character
    memcpy(&Data[index], cRxSWINData7, len7);
    index += len7;

#endif
/* 010D_03 */

	return retValue;
}


// WPC_20_01 start
/*******************************************************************************
	Module Name : ECUSoftwareUnit1IVDDataIdentifier : $F1C1 (len:32)
	Function	: Invoked Event
	Parameters	:
	Return		: RTE_E_OK     - Request was successful
	Remark		: E_NOT_OK - Request was not successful
*******************************************************************************/
Std_ReturnType ECUSoftwareUnit1IVDDataIdentifier_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return retValue;
}

Std_ReturnType ECUSoftwareUnit1IVDDataIdentifier_Read(uint8 OpStatus, uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	uint8_t i;

	switch(OpStatus)
	{
		case DCM_INITIAL :
			if(Uds.Int.HashCalStatus != Hash_OK)	// 미리 계산된 값이 있으면 다시 계산하지 않는다.
			{
				Uds.Int.HashCalStartReq = ON;
				ss_Uds_HashCalculate();
			}

        	retValue = DCM_E_PENDING;
			break;

		case DCM_PENDING :
        	if( Uds.Int.HashCalStatus == Hash_OK )
        	{
            	for (i = 0; i < 32u; i++)
            	{
                	Data[i] =Uds.Int.digest1[i];
            	}
            	retValue = RTE_E_OK;
        	}
        	else if( Uds.Int.HashCalStatus == Hash_During )
        	{
				ss_Uds_HashCalculate();
            	retValue = DCM_E_PENDING;
        	}
        	else	// Uds.HashCalStatus == Hash_NG, Hash_Default
        	{
            	retValue = E_NOT_OK;
        	}
			break;

		case DCM_CANCEL :
			retValue = RTE_E_OK;
			break;

		default :
			// M3CM Rule-16.4
			break;
	}

    return retValue;

}


/*******************************************************************************
	Module Name : PlatfromSoftwareVersion : $F17F  (len:11)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType PlatformSoftwareVersion_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType PlatformSoftwareVersion_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	/* Platform Software Version */

	Data[0] = (uint8_t)cPlatformSoftVer1;
	Data[1] = (uint8_t)cPlatformSoftVer2;
	Data[2] = (uint8_t)'.';
	Data[3] = (uint8_t)cPlatformSoftVer3;
	Data[4] = (uint8_t)cPlatformSoftVer4;
	Data[5] = (uint8_t)'.';
	Data[6] = (uint8_t)cPlatformSoftVer5;
	Data[7] = (uint8_t)cPlatformSoftVer6;
	Data[8] = (uint8_t)'.';
	Data[9] = (uint8_t)cPlatformSoftVer7;
	Data[10] = (uint8_t)cPlatformSoftVer8;
	Data[11] = (uint8_t)'.';
	Data[12] = (uint8_t)cPlatformSoftVer9;
	Data[13] = (uint8_t)cPlatformSoftVer10;
	return retValue;
}


/*******************************************************************************
	Module Name : PlatfromHardwareVersion : $F17D  (len:11)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType PlatformHardwareVersion_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType PlatformHardwareVersion_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	/* Platform Hardware Version */

	//Data[0] = (uint8_t)cPlatformHardVer1;
	//Data[1] = (uint8_t)cPlatformHardVer2;

	if(Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE4)
	{
		Data[0] = '0';
		Data[1] = '4';
	}
	else if(Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE5)
	{
		Data[0] = '0';
		Data[1] = '5';
	}
	else if(Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE6)
	{
		Data[0] = '0';
		Data[1] = '6';
	}
	else
	{
		// QAC
	}

	Data[2] = (uint8_t)'.';
	Data[3] = (uint8_t)cPlatformHardVer3;
	Data[4] = (uint8_t)cPlatformHardVer4;
	Data[5] = (uint8_t)'.';
	Data[6] = (uint8_t)cPlatformHardVer5;
	Data[7] = (uint8_t)cPlatformHardVer6;
	Data[8] = (uint8_t)'.';
	Data[9] = (uint8_t)cPlatformHardVer7;
	Data[10] = (uint8_t)cPlatformHardVer8;

	return retValue;
}


/* WPC_1903_04 Start */
/*******************************************************************************
	Module Name : NonSleepCollectedEachEcuDataDataIdentifier : $ED90
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType NonSleepCollectedEachEcuDataDataIdentifier_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return retValue;
}
Std_ReturnType NonSleepCollectedEachEcuDataDataIdentifier_Read(uint8 OpStatus, uint8* Data)
{
	Std_ReturnType retValue = RTE_E_OK;

// RTE로 전달 받은 변수를 사용하므로 주석 처리함.
	/* WPC_1905_01 Start */
	/* WPC_1908_03 Start */
	// Rte_ModeType_MDG_ComMMode_PNC ComMModePNC141_Prev, ComMModePNC141_Next;
	// Rte_ModeType_MDG_ComMMode_PNC ComMModePNC153_Prev, ComMModePNC153_Next;
	// Rte_ModeType_MDG_ComMMode_PNC ComMModePNC159_Prev, ComMModePNC159_Next;

	// Rte_ModeType_MDG_ComMMode ComMModeBCAN_Prev, ComMModeBCAN_Next;
	// Rte_ModeType_MDG_ComMMode ComMModeLCAN1_Prev, ComMModeLCAN1_Next;

	/* PNC Com의 Mode를 불러옴, Previous는 읽기만하고 사용하지는 않음 */
	// Rte_Mode_R_modeSwitchPort_ComMMode_PNC141_ComMMode_PNC141(&ComMModePNC141_Prev, &ComMModePNC141_Next);
	// Rte_Mode_R_modeSwitchPort_ComMMode_PNC153_ComMMode_PNC153(&ComMModePNC153_Prev, &ComMModePNC153_Next);
	// Rte_Mode_R_modeSwitchPort_ComMMode_PNC159_ComMMode_PNC159(&ComMModePNC159_Prev, &ComMModePNC159_Next);	// WPC_1912_01

	/* 물리 Com의 Mode를 불러옴, Previous는 읽기만하고 사용하지는 않음 */
	// Rte_Mode_ComMModeInterface_BCAN_ComMMode_BCAN(&ComMModeBCAN_Prev, &ComMModeBCAN_Next);
	// Rte_Mode_ComMModeInterface_LCAN1_ComMMode_LCAN1(&ComMModeLCAN1_Prev, &ComMModeLCAN1_Next);
// RTE로 전달 받은 변수를 사용하므로 주석 처리함.

	/* 요구되는 값들 입력 */
	NonSleepReason.B2CAN.ACC				= 0; 	/* B2CAN을 통해 받는 ACC 신호 없음 */
	NonSleepReason.B2CAN.IGN1				= 0;	/* B2CAN을 통해 받는 IGN 신호 없음 */

	if(Uds.Inp_CAN_RX.BCAN.C_Latch_TypeOption_DRV == 1u) /* WPC_2419_02 */
	{
		NonSleepReason.B2CAN.DrvDrSw			= ((Uds.Inp_CAN_RX.BCAN.C_Warn_DrvDrSwSta_SBCM != 0u) ? 1u : 0u);
		NonSleepReason.B2CAN.AstDrSw			= ((Uds.Inp_CAN_RX.BCAN.C_Warn_AsstDrSwSta_SBCM != 0u) ? 1u : 0u);
		NonSleepReason.B2CAN.RLDrSw				= ((Uds.Inp_CAN_RX.BCAN.C_Warn_RrLftDrSwSta_SBCM != 0u) ? 1u : 0u);
		NonSleepReason.B2CAN.RRDrSw				= ((Uds.Inp_CAN_RX.BCAN.C_Warn_RrRtDrSwSta_SBCM != 0u) ? 1u : 0u);
	}
	else
	{
		NonSleepReason.B2CAN.DrvDrSw			= ((Uds.Inp_CAN_RX.BCAN.C_Warn_DrvDrSwSta != 0u) ? 1u : 0u);	/* WPC_1910_03 */
		NonSleepReason.B2CAN.AstDrSw			= ((Uds.Inp_CAN_RX.BCAN.C_Warn_AsstDrSwSta != 0u) ? 1u : 0u);	/* WPC_1910_03 */
		NonSleepReason.B2CAN.RLDrSw				= ((Uds.Inp_CAN_RX.BCAN.C_Warn_RrLftDrSwSta != 0u) ? 1u : 0u);	/* WPC_1910_03 */
		NonSleepReason.B2CAN.RRDrSw				= ((Uds.Inp_CAN_RX.BCAN.C_Warn_RrRtDrSwSta != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	}

	NonSleepReason.B2CAN.AutoBrightValue	= ((Uds.Inp_CAN_RX.BCAN.C_CLU_AutoBrightSta != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* WPC_1908_11 */
	NonSleepReason.B2CAN.SMKOption			= ((Uds.Inp_CAN_RX.BCAN.C_BCM_SmkOptTyp != 0u) ? 1u : 0u);						/* WPC_1910_03 */	/* WPC_1908_11 */
	NonSleepReason.B2CAN.Reserved0			= UDS_RESERVED_VALUE;
	NonSleepReason.B2CAN.ComMModePNC153		= Uds.Inp_Mode.BCAN_ComMModePNC153;									/* SHLee : 표기방법 재논의 필요 */
	NonSleepReason.B2CAN.ComMModePNC141		= Uds.Inp_Mode.BCAN_ComMModePNC141;									/* SHLee : 표기방법 재논의 필요 */
	NonSleepReason.B2CAN.Reserved1			= UDS_RESERVED_VALUE;
	NonSleepReason.B2CAN.Reserved2			= UDS_RESERVED_VALUE;

	NonSleepReason.LCAN1.OwnerPhnRegRVal	= ((Uds.Inp_CAN_RX.LCAN.LC_OwnerKey_Reg_Status != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.LCAN1.OPAdv_On_Cmd		= ((Uds.Inp_CAN_RX.LCAN.LC_OwnerPairingAdvertisingReq != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.LCAN1.WPC_Device_On_Cmd	= ((Uds.Inp_CAN_RX.LCAN.LC_DeviceOnWPC != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.LCAN1.Reserved0			= UDS_RESERVED_VALUE;
	NonSleepReason.LCAN1.ComMModePNC159		= Uds.Inp_Mode.LCAN_ComMModePNC159;	/* WPC_1912_01 */									/* SHLee : 표기방법 재논의 필요 */
	NonSleepReason.LCAN1.Reserved1			= UDS_RESERVED_VALUE;

	NonSleepReason.LCAN2.Reserved0			= UDS_RESERVED_VALUE;
	NonSleepReason.LCAN2.Reserved1			= UDS_RESERVED_VALUE;

	NonSleepReason.ECUSpec.UDS_LpCondition	= ((Uds.Out.Uds_LPConditionFlag != 0u) ? 1u : 0u);					/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */


	// single 시 강제로 비활성화 값 set
	if(Uds.Inp_NvM.WPC_TYPE == cWPC_TYPE4) /* only single */
	{
		Uds.Inp_Model.Device[D1].WPCMode_LPConditionFlag = OFF;
		Uds.Inp_WCT.Device[D1].WCT_LPConditionFlag = OFF;
		Uds.Inp_NFC.Device[D1].NFC_LPConditionFlag = OFF;
	}

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	NonSleepReason.ECUSpec.WPC_LpCondition	= (((Uds.Inp_Model.Device[D0].WPCMode_LPConditionFlag | Uds.Inp_Model.Device[D1].WPCMode_LPConditionFlag) != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */
	NonSleepReason.ECUSpec.WCT_LpCondition	= (((Uds.Inp_WCT.Device[D0].WCT_LPConditionFlag | Uds.Inp_WCT.Device[D1].WCT_LPConditionFlag) != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */
	NonSleepReason.ECUSpec.NFC_LpCondition	= (((Uds.Inp_NFC.Device[D0].NFC_LPConditionFlag | Uds.Inp_NFC.Device[D1].NFC_LPConditionFlag) != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */

//#elif defined(WPC_TYPE4)	// Single
//	NonSleepReason.ECUSpec.WPC_LpCondition	= (((Uds.Inp_Model.Device[D0].WPCMode_LPConditionFlag ) != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */
//	NonSleepReason.ECUSpec.WCT_LpCondition	= (((Uds.Inp_WCT.Device[D0].WCT_LPConditionFlag ) != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */
//	NonSleepReason.ECUSpec.NFC_LpCondition	= (((Uds.Inp_NFC.Device[D0].NFC_LPConditionFlag ) != 0u) ? 1u : 0u);	/* WPC_1910_03 */	/* SHLee : 표기방법 재논의 필요 */

//#else
//   error : wpc type is not defined
//#endif



	NonSleepReason.ECUSpec.Reserved0		= UDS_RESERVED_VALUE;
	NonSleepReason.ECUSpec.Reserved1		= UDS_RESERVED_VALUE;
	NonSleepReason.ECUSpec.Reserved2		= UDS_RESERVED_VALUE;
	NonSleepReason.ECUSpec.Reserved3		= UDS_RESERVED_VALUE;

	NonSleepReason.HWInput.A_IGN1_IN		= ((Uds.Inp_ADC.IGN1_IN != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.HWInput.Reserved0		= UDS_RESERVED_VALUE;

	NonSleepReason.NetState.DiagMsg			= ((Uds.Out.Uds_LPConditionFlag != 0u) ? 0u : 1u);	/* WPC_1910_03 */
	NonSleepReason.NetState.AutosarNMPNCOn	= (((Uds.Inp_Mode.LCAN_ComMModePNC159|Uds.Inp_Mode.BCAN_ComMModePNC141|Uds.Inp_Mode.BCAN_ComMModePNC153) != 0u) ? 0u : 1u);	/* WPC_1912_01 */	/* WPC_1910_03 */
	NonSleepReason.NetState.BCANWakeUp		= ((Uds.Inp_Mode.ComMMode_BCAN != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.NetState.LCAN1WakeUp		= ((Uds.Inp_Mode.ComMMode_LCAN != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.NetState.LCAN2WakeUp		= 0;	/* LCAN2 없음 */
	NonSleepReason.NetState.Reserved0		= UDS_RESERVED_VALUE;

	NonSleepReason.Index.B2CAN				= (((NonSleepReason.B2CAN.data[0]|NonSleepReason.B2CAN.data[1]|NonSleepReason.B2CAN.data[2]|NonSleepReason.B2CAN.data[3]) != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.Index.LCAN1				= (((NonSleepReason.LCAN1.data[0]|NonSleepReason.LCAN1.data[1]) != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.Index.LCAN2				= (((NonSleepReason.LCAN2.data[0]|NonSleepReason.LCAN2.data[1]) != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.Index.ECUSpecData		= (((NonSleepReason.ECUSpec.data[0]|NonSleepReason.ECUSpec.data[1]|NonSleepReason.ECUSpec.data[2]|NonSleepReason.ECUSpec.data[3]) != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.Index.HWInput			= ((NonSleepReason.HWInput.data != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.Index.NetworkCondition	= ((NonSleepReason.NetState.data != 0u) ? 1u : 0u);	/* WPC_1910_03 */
	NonSleepReason.Index.Reserved0			= UDS_RESERVED_VALUE;

	for (uint8 i = 0; i < 15u; i++)
	{
		*Data = NonSleepReason.data[i];
		Data++;
	}
	/* WPC_1908_03 End */
	/* WPC_1905_01 End */

	return retValue;
}
/* WPC_1903_04 Stop */

// WPC_20_01 stop
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
*/
/*
Hash Calculated Function
***************************************************************************************************/
// WPC_422_04
static void ss_Uds_HashCalculate(void)
{
	uint8_t i;

	// if(Uds.Inp_ADC.IGN1_IN == OFF)
	// {
	// 	Uds.Int.HashCal_State = 0;
	// 	Uds.Int.HashCalStatus = Hash_Default;	// ign off시 다시 계산 하기 위해서 클리어 처리함.
	// 	Uds.Int.HashCalStartReq = OFF;
	// 	Uds.Int.Sha256Resp = 0;
	// 	Uds.Int.IncreaseAdd = 0;
	// }

	switch(Uds.Int.HashCal_State)
	{
		case 0:
			if(Uds.Int.HashCalStartReq == ON)
    		{
				Uds.Int.HashCalStartReq = OFF;
        		Uds.Int.HashCalStatus = Hash_During;

        		for (i = 0; i < 32u; i++)
        		{
            		Uds.Int.digest1[i] = 0u;
        		}

				Uds.Int.HashCal_State = 1;
			}
		break;


		case 1: // 분산처리 적용. 1task에 Sha256Update 2회 실행할경우 특정 조건에서 문제됨 (hash 계산 byte도 2048상태로 ig on 상태로 ota 업데이트 후 리셋 걸림. )
        	Uds.Int.Sha256Resp = Hmg_Sha256Start(&Uds.Int.ShaCtx);
        	Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, CODE_BASE_START1, CODE_SIZE_UNIT);
        	Uds.Int.IncreaseAdd = CODE_SIZE_UNIT;

			Uds.Int.HashCal_State = 2;

		break;


		case 2:
            if((CODE_BASE_START1 + Uds.Int.IncreaseAdd) <= (CODE_BASE_END1-CODE_SIZE_UNIT))
            {
                Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START1 + Uds.Int.IncreaseAdd), CODE_SIZE_UNIT);
                Uds.Int.IncreaseAdd = Uds.Int.IncreaseAdd + CODE_SIZE_UNIT;
            }
            else
            {
                Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START1 + Uds.Int.IncreaseAdd), (CODE_BASE_END1 - CODE_BASE_START1 - Uds.Int.IncreaseAdd + 1u));
                Uds.Int.IncreaseAdd = 0;
                // mb1StHashEnd = ON;

				Uds.Int.HashCal_State = 3;
            }

		break;

// WPC_475_01
		case 3:

            if((CODE_BASE_START2 + Uds.Int.IncreaseAdd) <= (CODE_BASE_END2-CODE_SIZE_UNIT))
            {
                Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START2 + Uds.Int.IncreaseAdd), CODE_SIZE_UNIT);
                Uds.Int.IncreaseAdd = Uds.Int.IncreaseAdd + CODE_SIZE_UNIT;

            }
            else
            {
                Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START2 + Uds.Int.IncreaseAdd), (CODE_BASE_END2 - CODE_BASE_START2 - Uds.Int.IncreaseAdd + 1u));
                Uds.Int.Sha256Resp += Hmg_Sha256Finish(&Uds.Int.ShaCtx, Uds.Int.digest1);
				Uds.Int.IncreaseAdd = 0;


				// Uds.Int.HashCal_State = 4;
				Uds.Int.HashCal_State = 6;
            }

		break;


		// case 4:

        //     if((CODE_BASE_START3 + Uds.Int.IncreaseAdd) <= (CODE_BASE_END3-CODE_SIZE_UNIT))
        //     {
        //         Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START3 + Uds.Int.IncreaseAdd), CODE_SIZE_UNIT);
        //         Uds.Int.IncreaseAdd = Uds.Int.IncreaseAdd + CODE_SIZE_UNIT;
        //     }
        //     else
        //     {
        //         Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START3 + Uds.Int.IncreaseAdd), (CODE_BASE_END3 - CODE_BASE_START3 - Uds.Int.IncreaseAdd + 1u));
		// 		Uds.Int.IncreaseAdd = 0;
		// 		Uds.Int.HashCal_State = 5;
        //     }

		// break;


		// case 5:

        //     if((CODE_BASE_START4 + Uds.Int.IncreaseAdd) <= (CODE_BASE_END4-CODE_SIZE_UNIT))
        //     {
        //         Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START4 + Uds.Int.IncreaseAdd), CODE_SIZE_UNIT);
        //         Uds.Int.IncreaseAdd = Uds.Int.IncreaseAdd + CODE_SIZE_UNIT;
        //     }
        //     else
        //     {
        //         Uds.Int.Sha256Resp += Hmg_Sha256Update(&Uds.Int.ShaCtx, (CODE_BASE_START4 + Uds.Int.IncreaseAdd), (CODE_BASE_END4 - CODE_BASE_START4 - Uds.Int.IncreaseAdd + 1u));
        //         Uds.Int.Sha256Resp += Hmg_Sha256Finish(&Uds.Int.ShaCtx, Uds.Int.digest1);
		// 		Uds.Int.HashCal_State = 6;
        //     }

		// break;


		case 6:
        	if( Uds.Int.Sha256Resp == 0u )  /* Hash Finish successful */
        	{
            	Uds.Int.HashCalStatus = Hash_OK;
        	}
        	else            /* Hash Finish Fail */
        	{
            	Uds.Int.HashCalStatus = Hash_NG;
        	}

			Uds.Int.HashCal_State = 7;

		break;


		case 7:
			// M3CM Rule-15.7
		break;
// WPC_475_01

		default:
                                // M3CM Rule-16.4
		break;

	}

}
// WPC_422_04


/*******************************************************************************
	Module Name : EcuInfoRead : $B0BA (len:72byte)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType EcuInfoRead_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	HSM_GetConfigurationLockState(&Uds.Int.ConfigurationLockState);
	//Uds.Int.ConfigurationLockState = HSM_CONFIG_LOCK_ENABLE; // for debug
	if(Uds.Int.ConfigurationLockState == HSM_CONFIG_LOCK_ENABLE)
	{
		if(Uds.Out.m_B0BADisableCnt < 255u)
		{
			Uds.Out.m_B0BADisableCnt++;	/* ConfigLock이 걸린 상태에서 B0BA 호출마다 카운트업 */
		}
	}

	/* WPC_2426_03 Start */
	if(Uds.Out.m_B0BADisableCnt > UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}

    return retValue;
}
Std_ReturnType EcuInfoRead_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
	uint8_t i;
	Std_ReturnType result = E_NOT_OK;// WPC_90_01
	//static HSM_ERROR_CODE g_ErrorCode;// WPC_90_01

// WPC_2F_07 start
	/************************************
	 품번
	************************************/
	for(i=0; i<10u; i++)
	{
		//Data[i] = Uds.Int.EcuInfoTbl.PartNumber[i];
		Data[i] = Uds.Out.m_ECU_Info[i]; /* Part No : 0 ~ 9 : 10byte */
	}

	/************************************
	 날짜
	************************************/
	for(i=0; i<4u; i++)
	{
		//Data[i+10u] = Uds.Int.EcuInfoTbl.Date[i];
		Data[i+10u] = Uds.Out.m_ECU_Info[i+10u]; /* date : 10 ~ 13 : 4byte */
	}

	/************************************
	 고객 소프트 버전
	************************************/
/* 0108_14 */ // U/R/S 롬 컴파일시 자동으로 버전만 변경되어 3가지 s19가 자동으로 생성되도록 하기 위해서 로직 변경함.
	// Data[14] = (uint8_t)cAppSoftVerYear1;
	// Data[15] = (uint8_t)cAppSoftVerYear2;
	// Data[16] = (uint8_t)cAppSoftVerMonth;
	// Data[17] = (uint8_t)cAppSoftVerOrder;
	// Data[18] = (uint8_t)cAppSoftVerOption;

	// hex에서 버전이 저장되는 address에서 다이렉트로 access하여 read함.
	Data[14] = App_SoftwareVersionHeader.currentVersion[0];	/* Soft Version */
	Data[15] = App_SoftwareVersionHeader.currentVersion[1];
	Data[16] = App_SoftwareVersionHeader.currentVersion[2];
	Data[17] = App_SoftwareVersionHeader.currentVersion[3];
	Data[18] = App_SoftwareVersionHeader.currentVersion[4];
/* 0108_14 */

	/************************************
	 내부 소프트 버전
	************************************/
	Data[19] = (uint8_t)cAppSoftVerCAR1;
	Data[20] = (uint8_t)cAppSoftVerCAR2;
	Data[21] = (uint8_t)cAppSoftVerIndex1;
	Data[22] = (uint8_t)cAppSoftVerIndex2;

	/************************************
	 고객 하드웨어 버전
	************************************/
	for(i=0; i<3u; i++)
	{
		//Data[i+23u] = Uds.Int.EcuInfoTbl.HwVersion[i];
		Data[i+23u] = Uds.Out.m_ECU_Info[i+14u]; /* Hw ver : 14 ~ 16 : 3byte */
	}

	/************************************
	 BCAN DB 버전
	************************************/
	Data[26] = (uint8_t)cBCanDBVersion1;
	Data[27] = (uint8_t)cBCanDBVersion2;
	Data[28] = (uint8_t)cBCanDBVersion3;

	/************************************
	 WCT 소프트 버전
	************************************/
	Data[29] = Uds.Inp_UART.WctSourceVer[0];	// ascii값으로 변환된 상태임.
	Data[30] = Uds.Inp_UART.WctSourceVer[1];
	Data[31] = Uds.Inp_UART.WctSourceVer[2];

	/************************************
	 QRCODE
	************************************/
	for(i=0; i<21u; i++)
	{
		Data[i+32u] = Uds.Out.m_QRCode[i];
	}
	// 21+30 = 51 , 즉 배열 넘버가 51까지임 (0  ~ 50). 그러므로 모빌젠에서 51바이트 설정해야함

// WPC_2F_07 stop

#if 0
typedef enum
{ //HSM-Driver Sync Need
	HSM_SECUREBOOT_INIT = 0,                            /*!< Initialization */
	HSM_SECUREBOOT_DISABLE = 1,                         /*!< Disable */
	HSM_SECUREBOOT_ENABLE = 2,                          /*!< Enable */
	HSM_SECUREBOOT_SUCCESS = 3,                         /*!< Bootloader integrity verification success */
	HSM_SECUREBOOT_HEADER_ERR = 4,                      /*!< Table header, footer error */
	HSM_SECUREBOOT_INVALID_CMAC = 5,                    /*!< Bootloader integrity verification fail */
	HSM_SECUREBOOT_CMAC_GEN_FAIL = 6,                   /*!< MAC generation failure for integrity verification */
	HSM_SECUREBOOT_HASH_GEN_FAIL = 7,                   /*!< Hash generation failed when verifying the firmware signature */
	HSM_SECUREBOOT_DECRYPT_FAIL = 8,                    /*!< Encrypted table decryption failed */
	HSM_SECUREBOOT_XOR_SUM_FAIL = 9,                    /*!< XOR Value Verification fail */
	HSM_SECUREBOOT_SIGN_VERIFY_FAIL = 10,               /*!< Signature verification fail */
	HSM_SECUREBOOT_WR_INFO_FAIL = 11,                   /*!< Table write fail */
	HSM_SECUREBOOT_NOT_PERFORMED = 12,                  /*!< Secure Boot not working */
	HSM_SECUREBOOT_STATE_ENUM_SET_UINT32 = 0x7FFFFFFF,
} HSM_SECUREBOOT_STATE_t;
typedef enum
{ //HSM-Driver Sync Need
	HSM_DEBUG_PROTECTION_DISABLE = 0,                   /*!< SECURE DEBUG Disable */
	HSM_DEBUG_PROTECTION_ENABLE = 1,                    /*!< SECURE DEBUG Enable */
	HSM_DEBUG_PROTECTION_TEMP_STOP = 2,                 /*!< SECURE DEBUG Pause */
	HSM_DEBUG_PROTECTION_UNLOCK_FAIL = 3,               /*!< SECURE DEBUG Unlock Fail */
	HSM_DEBUG_PROTECTION_UNLOCK_FAIL_PASSWORD = 4,      /*!< SECURE DEBUG Password verification Fail */
	HSM_DEBUG_PROTECTION_NOT_SUPPORTED = 5,             /*!< SEUCRE DEBUG Unlock function not available */
	HSM_DEBUG_STATE_ENUM_SET_UINT32 = 0x7FFFFFFF,
} HSM_SECUREDEBUG_STATE_t; //hsm secure debug unlock state
typedef struct
{
    HSM_SECUREBOOT_STATE_t secureBootState;     /*!< Secure Boot Status information */
    HSM_FTD_RUN_STATE_t fwTamperDetectionState; /*!< Fw Tamper Detection Status information */
    HSM_SECUREDEBUG_STATE_t secureDebugState;   /*!< Secure Debug Status information */
} HSM_SECURITY_INFO_t;
#endif

// secureBootState는 라이팅 직후 HSM_SECUREBOOT_ENABLE = 2 전원 리셋 후 HSM_SECUREBOOT_SUCCESS = 3가 리턴됨
// Traveo2_lifecycle_SECURE.cmm 실행 직후 디버그에서 Run 실행 후 전원 리셋하면
// secureBootState = 3, secureDebugState = 1, ConfigurationLockState = 1로 읽어진다.

// secure debug 임시 해제 요청 후 상태 읽어보면
// secureBootState = 3, secureDebugState = 2, ConfigurationLockState = 1로 읽어진다.

	result = HSM_GetAllSecurityInfo(&Uds.Int.Securityinfo);

	if(result != E_OK)
	{
		//result = E_NOT_OK;
		//g_ErrorCode = (HSM_ERROR_CODE)HSM_GetLastErrorCode();
		Data[53] = 0xFF;
		Data[54] = 0xFF;
	}
	else
	{
		Data[53] = (uint8_t)Uds.Int.Securityinfo.secureBootState;
		Data[54] = (uint8_t)Uds.Int.Securityinfo.secureDebugState;
	}


// typedef enum
// {
// 	HSM_CONFIG_LOCK_DISABLE = 0,
// 	HSM_CONFIG_LOCK_ENABLE = 1,
// 	HSM_CONFIG_LOCK_ENUM_SET_UINT32 = 0x7FFFFFFF,
// } HSM_CONFIG_LOCK_STATE_t;
	result = HSM_GetConfigurationLockState(&Uds.Int.ConfigurationLockState);

	if(result != E_OK)
	{
		//result = E_NOT_OK;
		//g_ErrorCode = (HSM_ERROR_CODE)HSM_GetLastErrorCode();
		Data[55] = 0xFF;
	}
	else
	{
		Data[55] = (uint8_t)Uds.Int.ConfigurationLockState;

	}

	/************************************
	 FBL Version Info
	************************************/
	Data[56] = Fbl_Version_Info[0]; // FBL SW Version
	Data[57] = Fbl_Version_Info[1];
	Data[58] = Fbl_Version_Info[2];
	Data[59] = Fbl_Version_Info[3];
	Data[60] = Fbl_Version_Info[4];

	Data[61] = Fbl_Version_Info[5]; // FBL Inter SW Version
	Data[62] = Fbl_Version_Info[6];
	Data[63] = Fbl_Version_Info[7];
	Data[64] = Fbl_Version_Info[8];

	Data[65] = Fbl_Version_Info[9]; // FBL SWP Version
	Data[66] = Fbl_Version_Info[10];
	Data[67] = Fbl_Version_Info[11];

	Data[68] = Fbl_Version_Info[12]; // Reserved
	Data[69] = Fbl_Version_Info[13];
	Data[70] = Fbl_Version_Info[14];
	Data[71] = Fbl_Version_Info[15];


	return retValue;
}


// WPC_98_10 start
// Secure Debug 임시 해제를 위한 Challenge & Response 기능
/*******************************************************************************
	Module Name : ChallengeRequest : $4348 (len:16byte)
	Function	: Invoked Event
	Parameters	:
	Return		: RTE_E_OK     - Request was successful
	Remark		: E_NOT_OK - Request was not successful
*******************************************************************************/

static uint8 HSM_ChallengeData[16] = {0,};
static uint8 HSM_RequestData[16] = {0,};
//Secure Debug
//활성화 이후 임시 해제 절차의 예시는 다음과 같다
//1) CAN 메시지, GPIO 같은 외부도구 입력 등을 이용하여 Challenge Request API (HSM_ChallengeRequest() 호출
//2) MCU 에서 Challenge 값을 생성하여 사용자에게 회신
//3) 사용자는 MCU 에서 받은 Challenge 값과 ASK 모듈을 이용해 Response 값 생성
//4) CAN 메시지 , GPIO 같은 외부도구 입력 등을 이용하여 Response Forward API(HSM_ResponseForward() 로 MCU 에 전달
//5) MCU 는 사용자에게 전달받은 Response 값 을 검증 후 검증 여부에 따라 Secure Debug 임시 해제
//6) 사용자는 디버거 핀 , 포트 설정을 HW 환경과 회로 구조에 맞게 활성화

// 진단기에서 WPC에 Challenge Request 요청함.
// WPC는 HSM에 challenge data 요청하여 생성된 challenge data(16바이트)를 다시 진단기에 회신함)
Std_ReturnType ChallengeRequest_ConditionCheckRead(uint8* ErrorCode)
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return retValue;
}
Std_ReturnType ChallengeRequest_Read(uint8* Data)
{

// Challenge Request 송신 시

	Std_ReturnType retValue = RTE_E_OK;
	Std_ReturnType result = E_NOT_OK;


	//static HSM_ERROR_CODE g_ErrorCode;

	uint8_t Index;

	result = HSM_ChallengeRequest(HSM_ChallengeData);// HSM API호출하여 Challenge Data Generate 함

	if(result != E_OK)
	{
		result = E_NOT_OK;
		//g_ErrorCode = (HSM_ERROR_CODE)HSM_GetLastErrorCode();
	}
	else
	{
		for(Index=0; Index<16u; Index++)
		{
			Data[Index] = HSM_ChallengeData[Index];// 진다기에 응답하기 위해서 응답 버퍼에 Challenge Data 에 복사.
		}
	}
	retValue = result;


	return retValue;
}

// 진단기에서 WPC에 Response Data를 송신함.
// Response Data는 WPC로 부터 수신한 Challenge Data(16바이트)와 ASK 모듈(진단기 자체 보유)을 이용해서 생성함
Std_ReturnType ChallengeRequest_Write(const uint8* Data, uint8* ErrorCode)
{
// Challenge Response 송신 시

	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	Std_ReturnType result = E_NOT_OK;

	//static HSM_ERROR_CODE g_ErrorCode;
	uint8_t Index;

	for(Index = 0; Index < 16u; Index++)
	{
		HSM_RequestData[Index] = Data[Index];// 진단기로 부터 수신한 Response Data 복사
	}

	// result = HSM_ResponseForward((UINT8 *)HSM_RequestData);
	result = HSM_ResponseForward(HSM_RequestData);// 정상 처리되면 secure debug 임시 해제됨


	if(result != E_OK)
	{
		result = E_NOT_OK;
		//g_ErrorCode = (HSM_ERROR_CODE)HSM_GetLastErrorCode();
		//*ErrorCode = g_ErrorCode;
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT; // g_ErrorCode 에러 코드는 ErrorCode와 형식이 맞지 않는다.일반적인 에러로 대체함.
	}
	else
	{
		// 디버거 핀, 포트 설정을 HW환경과 구조에 맞게 활성화 (메뉴얼에 나와 있는 함수이나 swp에서 사용하지 않음)
		// 디버거 핀을 다시 설정해야 디버깅이 가능함

		//Cy_GPIO_Pin_FastInit(GPIO_PRT2, 4u, CY_GPIO_DM_HIGHZ, 0, P2_0_CPUSS_SWJ_TRSTN);	// 추가, 메뉴얼에는 없는 포트임. 이거 추가해야 활성화됨
		Cy_GPIO_Pin_FastInit(GPIO_PRT2, 0u, (uint32_t)CY_GPIO_DM_HIGHZ, 0u, P2_0_CPUSS_SWJ_TRSTN);	//  P2.0인데 P2.4로 설정한듯. P2.0에 맞게 다시 설정함.
		Cy_GPIO_Pin_FastInit(GPIO_PRT23, 4u, (uint32_t)CY_GPIO_DM_STRONG, 0u, P23_4_CPUSS_SWJ_SWO_TDO);
		Cy_GPIO_Pin_FastInit(GPIO_PRT23, 5u, (uint32_t)CY_GPIO_DM_HIGHZ, 0u, P23_5_CPUSS_SWJ_SWCLK_TCLK);
		Cy_GPIO_Pin_FastInit(GPIO_PRT23, 6u, (uint32_t)CY_GPIO_DM_HIGHZ, 0u, P23_6_CPUSS_SWJ_SWDIO_TMS);
		Cy_GPIO_Pin_FastInit(GPIO_PRT23, 7u, (uint32_t)CY_GPIO_DM_HIGHZ, 0u, P23_7_CPUSS_SWJ_SWDOE_TDI);


	}

	retValue = result;

	return retValue;
}


// WPC_98_10 stop

// WPC_125_05
// WPC_109_02 start
/*******************************************************************************
	Module Name : SecureBootEnable : SID : 0x22 DID : 0x5242 (len:8)
	Function	: Invoked Event
	Parameters	:
	Return		: RTE_E_OK     - Request was successful
	Remark		: E_NOT_OK - Request was not successful
*******************************************************************************/
Std_ReturnType SecureBootEnable_ConditionCheckRead(uint8 OpStatus, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	/* WPC_2426_04 Start */
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}

	return retValue;

	// 서비스 호출시 여기 먼저 호출되고 그 다음 아래 함수 호출됨
	//  ok 아닐때 아래 호출되는지 테스트 해보자.

	// 여기서 직접 호출하면 가끔 리셋 발생함. 그래서 ServiceRequestSupplierNotification_Indication 여기서 disable 처리함
	//Rte_Call_R_WDT_EN_WriteDirect(OFF);	// WDT disable (port high)
}

Std_ReturnType SecureBootEnable_Read(uint8 OpStatus, uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

	uint8 SecureMode_State = 0;
	static uint16 PendigWaitCnt = 0;

	// pendig message는 최대 125sec 유지 후 negative 회신한다.
	// can UDS Pending 송신 주기는 2.5초 이나 여기 호출되는것은 10ms 주기이다. gpio로 확인
	// 즉 pending 취소 여부확이느 매주기마다 실시함.

	// 펜딩 메시지가 50ms 마다 호출되는것으로 알고 있음.
	// 비주기 타스크 인므로 315ms 보다 더 오래 걸려야 할것 같은데
	// 주기 타스크에서 평가 했던것이랑 동이랗게 315ms 걸림.
	// 원인 추측 : 비주기 타스크는 주기 타스크가 idle 상태일때 실행되므로
	// 반대로 idle 일때 계속 실행되기 때문에 주기 타스크에서 실행했던것이랑 별차이 없이
	// cpu 점유 시간이 많아서 실행시간에 별차이가 없는듯.

	switch(OpStatus)
	{
		case DCM_INITIAL : // SecureBootEnable 완료시까지 pending 처리. 약 300ms 걸림. // WDT Disable 해야함.
			Data[0] = 0x0;
			PendigWaitCnt = 0; // 초기화

			Rte_Trigger_TriggerInterface_BG_Trigger_BG(); // 실행시간이 오래 걸리므로 (315ms) 비주기 task 호출 함.

			retValue = DCM_E_PENDING;

			break;

		case DCM_PENDING :
			SecureMode_State = gs_Get_SecureMode_State();

			Rte_Trigger_TriggerInterface_BG_Trigger_BG(); // 실행시간이 오래 걸리므로 (315ms) 비주기 task 호출 함.

			if(SecureMode_State == cSecure_ConfigLock)
			{
				Data[0] = cSecure_ConfigLock;
				retValue = RTE_E_OK;

				Uds.Out.WdtDisable_ConfigLock = OFF; // WDT Disable Request OFF
			}
			else if(SecureMode_State == cSecure_Ng)
			{
				Data[0] = cSecure_Ng;
				retValue = RTE_E_OK;

				Uds.Out.WdtDisable_ConfigLock = OFF; // WDT Disable Request OFF
			}
        	else
        	{
				PendigWaitCnt ++;
				retValue = DCM_E_PENDING;

				// pending max 대기 시간(400초)에 의해서 nagetive 되면 wdt on이 안된 상태로 종료되기때문에
				// 강제로 카운트 만들어서 pending에 의해서 종료되기 전에 정상 ng로 종료 시킨다.
				if(PendigWaitCnt >= Par_SecureNgWaitCnt)		// 100초
				{
					PendigWaitCnt = 0;
					Data[0] = cSecure_Ng;
					retValue = E_NOT_OK;

					Uds.Out.WdtDisable_ConfigLock = OFF; // WDT Disable Request OFF
				}
			}

			break;

		case DCM_CANCEL :
			retValue = RTE_E_OK;
			break;

		default :
                                       // Rule-16.4
			break;
	}

    return retValue;

}
// WPC_109_02 stop
// WPC_125_05

/*******************************************************************************
** Write Control by Identifier ($2E hex) Service                              **
*******************************************************************************/
/*******************************************************************************
	Module Name : EcuInfoWrite : $12B0 (len:18)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType EcuInfoWrite_Write(const uint8* Data, uint16 DataLength, uint8 OpStatus, uint8* ErrorCode)
{

    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	uint16_t i;

	NvM_RequestResultType bNvMBlockStatus = NVM_REQ_NOT_OK;

	// 실제 기능도 동작되지  않도록 함.
	/* WPC_2426_04 Start */
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}
	else
	{
		// FAQ : 진단 pending 응답 송출 가이드 대로 변경함. (기존 방법은 #if 0 처리.)
		// 로직 변경은 없음
		switch(OpStatus)
		{
			case DCM_INITIAL:
				/* NvM Update Request */
		        if(( Data[0] == cEcuDataCode ) &&
				(DataLength == (ECU_INFO_SIZE + 1u)))// WPC_100_01		// WPC_96_02 // DataLength는 Code(0xBB, 0xBD)와 EcuInfo 17바이트 합쳐서 18이다.
				{/* $0xBB : ECU Data - partNumber / dateNumber / hardVersion */
		            for(i=0; i<ECU_INFO_SIZE; i++){// WPC_96_02
						Uds.Out.m_ECU_Info[i] = Data[1u+i];
		            }
					//이방식 사용하지 않고 구조체로 rte로 매주기 전달한다.
					//Rte_Call_R_CS_NvM_Write_ECUInfo(NvM_BLK_ECU_INFO, Uds.Int.EcuInfoTbl.data);
		            retValue = DCM_E_PENDING; // NvM Write Pending
		        }
				else if(Data[0] == cSerialNumCode) // 현재 양산 라인에서 미사용. 스티커로 대체되었다고함.
				{/* $0xBD : Serial Number */
					for(i=0; i<(DataLength-1u); i++) // 15바이트는 진단 스펙에서 정의된 크기이며 실제 사용하는 몇바이트 수만큼 length 값이 지정됨
					{
						Uds.Out.m_SerialNum[i] = Data[1u+i];
					}

					for(i=(DataLength-1u); i<SERIAL_NUM_SIZE; i++) // 15바이트보다 시리얼 넘버가 작을 경우 나머지 바이트를0으로 초기화 처리
					{
						Uds.Out.m_SerialNum[i] = 0x00;
					}
					//이방식 사용하지 않고 구조체로 rte로 매주기 전달한다.
					//Rte_Call_R_CS_NvM_Write_ECUInfo(NvM_BLK_SERIALNUM, Uds.Int.SerialNumber);
		            retValue = DCM_E_PENDING; // NvM Write Pending
				}
				else
				{	/* SUB-FUNCTION NOT SUPPORTED */
					retValue = E_NOT_OK;
		            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
		        }
			break;

			case DCM_PENDING:
				/* NvM Update Check */
				if( Data[0] == cEcuDataCode )
				{
					//NvM 라이트 완료 여부를 체크 하는 방법을 변경함.
					//Rte_Call_R_CS_NvM_ReadState_ECUInfo(NvM_BLK_ECU_INFO, &bNvMBlockStatus);
					if(Uds.Inp_NvM.NvMBlk_Array_Complete[BLK_NO_ARR_ECU_Info] == ON)
					{
						retValue = NVM_REQ_OK;
					}
					else
					{
						// 펜딩 처리시 resp max count 수는 모빌젠에 설정되고 200으로 설정됨
						// 펜딩 인터벌시간은 2.5초 임.
						// 펜딩시 이 함수로 다시 콜은 10ms 마다 re call됨.
						retValue = DCM_E_PENDING;
					}
				}
				else if(Data[0] == cSerialNumCode)
				{
					//Rte_Call_R_CS_NvM_ReadState_ECUInfo(NvM_BLK_SERIALNUM, &bNvMBlockStatus);
					if(Uds.Inp_NvM.NvMBlk_Array_Complete[BLK_NO_ARR_ECU_Info] == ON)
					{
						retValue = NVM_REQ_OK;
					}
					else
					{
						// 펜딩 처리시 resp max count 수는 모빌젠에 설정되고 200으로 설정됨
						// 펜딩 인터벌시간은 2.5초 임.
						// 펜딩시 이 함수로 다시 콜은 10ms 마다 re call됨.
						retValue = DCM_E_PENDING;
					}
				}
				else
				{
					retValue = E_NOT_OK;
					*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;  // fail
				}

			break;

			case DCM_CANCEL:
				retValue = RTE_E_OK;
			break;

			default :
    	                                // rule 16.4
			break;
		}
	}

    return retValue;

}
/*******************************************************************************
	Module Name : QRCodeWrite : $5152 (len:21)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType QRCodeWrite_Write(const uint8* Data, uint8 OpStatus, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	uint8_t i;
	//uint8_t mbPending = ON;
	NvM_RequestResultType bNvMBlockStatus = NVM_REQ_NOT_OK;



	/* WPC_2426_04 Start */
	// 실제 기능도 동작하지 않도록 함.
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}
	else
	{
		// FAQ : 진단 pending 응답 송출 가이드 대로 변경함. (기존 방법은 #if 0 처리.)
		// 로직 변경은 없음
		switch(OpStatus) {
			case DCM_INITIAL :
				/* NvM Update Request */
    	    	for(i=0; i<QRCODE_SIZE; i++){// WPC_96_02
					Uds.Out.m_QRCode[i] = Data[i];
    	   		}
				//NvM 라이트 완료 여부를 체크 하는 방법을 변경함.
				//Rte_Call_R_CS_NvM_Write_QRCode(Uds.Out.m_QRCode);
    	    	retValue = DCM_E_PENDING; // NvM Write Pending

				break;

			case DCM_PENDING :
				/* NvM Update Check */
				//Rte_Call_R_CS_NvM_ReadState_QRCode(&bNvMBlockStatus);
				if(Uds.Inp_NvM.NvMBlk_Array_Complete[BLK_NO_ARR_SerialNum] == ON)
				{
					retValue = NVM_REQ_OK;
				}
				else
				{
					// 펜딩 최대 시간은 400초임(모빌젠 설정 80번으로 설정됨. pending 인터벌 5초 이므로 5x80 = 400초)
					retValue = DCM_E_PENDING;
				}

				// 여기서 pending이 너무 오래 걸리면 안되므로 일정 횟수 이상 complete가 안되면
				// 강제로 에러 리턴하는 것도 검토 해봐야 함.


				// if(bNvMBlockStatus == NVM_REQ_OK)
				// {
				// 	retValue = RTE_E_OK;													/* EEPROM UPDATE COMPLETE */
				// }
				// else if(bNvMBlockStatus == NVM_REQ_PENDING)
				// {
				// 	// 펜딩 최대 시간은 400초임(모빌젠 설정 80번으로 설정됨. pending 인터벌 5초 이므로 5x80 = 400초)
				// 	retValue = DCM_E_PENDING;	/* EEPROM UPDATE NOT-COMPLETE */
				// }
				// else
				// {
				// 	retValue = E_NOT_OK;
				// 	*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;  // fail
				// }

				break;

			case DCM_CANCEL:
				retValue = RTE_E_OK;
			break;

			default :
    	                                // rule 16.4
				break;
		}
	}

    return retValue;
}


/*******************************************************************************
** Input Output Control by Identifier ($2F hex) Service                       **
*******************************************************************************/
/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_Supportedcheck : $F010 (len:4)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
Std_ReturnType InputOutputControlbyIdentifier_Supportedcheck_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_Supportedcheck_FreezeCurrentState(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_Supportedcheck_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;

    /*  Supported DID : 0x01 ~ 0x20             */
    /*  Response : 4 Byte (A, B, C, D)          */
    /*  Byte #0 A: DID 0x01~0x08,                */
    /*  Byte #1 B: DID 0x09~0x10                 */
    /*  Byte #2 C: DID 0x11~0x18,                */
    /*  Byte #3 D: DID 0x19~0x20                 */
	//         | bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 |
	// Byte #0 | 0x01  | 0x02  | 0x03  | 0x04  | 0x05  | 0x06  | 0x07  | 0x08  |
//	               0       0       0       0       0       0       0       0     = 0x00
	// Byte #1 | 0x09  | 0x0A  | 0x0B  | 0x0C  | 0x0D  | 0x0E  | 0x0F  | 0x10  |
//	               0       0       0       0       0       0       0       0     = 0x00
	// Byte #2 | 0x11  | 0x12  | 0x13  | 0x14  | 0x15  | 0x16  | 0x17  | 0x18  |
//	               1       1       1       0       0       1       1       1     = 0xE7
	// Byte #3 | 0x19  | 0x1A  | 0x1B  | 0x1C  | 0x1D  | 0x1E  | 0x1F  | 0x20  |
//	               1       0       0       0       0       0       0       0     = 0x80
	Data[0] = 0x00;	/* Supported DID Data A */
	Data[1] = 0x00;	/* Supported DID Data B */
	Data[2] = 0xE0;	/* Supported DID Data C */ // 사양서에 기재된 값만 출력하는 하도록함.
	Data[3] = 0x00;	/* Supported DID Data D */ // 개발용으로 사용하는것은 미출력함.

	return retValue;
}
/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_11 : $F011 (Request Data Size : 8bit Need mobilgene setting)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: 모빌젠 DcmDsp>Data 에서 Size는 8비트로 설정함.
	              이 8비트의 의미는 (2F F0 11 03 yy) 송신시 yy의 값이 1바이트여야 한다는 의미임.
				  단 wpc 진단 사양서상에는 yy 값을 사용하지 않도록 사양화 되어 있어 ES Spec과 충돌이 발생함. (dcm 업데이트 후)
				  그래서 다시 yy 값이 없어도 positive 응답 하도록 dcm 을 다시 업데이트 패치함.
				  즉 2F F0 11 03 도 ok, 2F F0 11 03 00도 OK 2F F0 11 03 22 도  ok임. 즉 yy 는 don't care임
				  그러나 2F F0 11 03 00 01 과 같이 1바이트가 아닌 2byte의 경우에는 negative 응답함.
				  단 (2F F0 11 00) 송신시에는 데이터가 없어야 함. 즉 모벨젠 설정값에 관계 없이 항상 없어야 햠.
				  2F F0 11 00 01 이렇게 되면 negative 응답함.

				  InputOutputControlbyIdentifier_11_Read()과
				  InputOutputControlbyIdentifier_11_ReadDataLength() 에서
				  설정하는 Data[0] = 0x01; Data[1] = 0x02; Data[2] = 0x03;과 *DataLength = 3u; 는
				  즉 data 값과 그 길이는 모빌젠 설정 size와 무관하다.
				  어플리케이션 코드에서 설정하는대로 출력된다.
				  위처럼 설정하면 아래 처럼 출력된다.
				  tx : 2F F0 11 00
				  rx : 2F F0 11 00 01 02 03

				  tx : 2F F0 11 03
				  rx : 2F F0 11 03 01 02 03

				  WPC 강제 구동 positive 응답은 Length : 1byte, Data : 0x01을 응답하도록 설정한다.
				  위에서 말한대로 데이터 부분이 없거나 1바이트 일때만 긍정응답하고 그 이상이면 부정응답한다.
				  tx : 2F F0 11 00
				  rx : 2F F0 11 00 01
				  tx : 2F F0 11 00 xx
				  rx : 7F 2F 13

				  tx : 2F F0 11 03
				  rx : 2F F0 11 03 01
				  tx : 2F F0 11 03 xx
				  rx : 2F F0 11 03 01
				  tx : 2F F0 11 03 xx yy
				  rx : 7F 2F 13

*******************************************************************************/
// InputOutputControlParameter : 0x0 (retrunControlToEcu)
// InputOutputControlParameter : 0x3 (shortTermAdjustment)
// 진단 0x00, 0x03 실행시 아래 함수 호출 순서
// 1. InputOutputControlbyIdentifier_11_ShortTermAdjustment() -->
// 2. InputOutputControlbyIdentifier_11_ConditionCheckRead() -->
// 3. InputOutputControlbyIdentifier_11_ReadDataLength() -->
// 4. InputOutputControlbyIdentifier_11_Read() 순으로 호출됨.

// 0x0 (retrunControlToEcu) 나 0x3 (shortTermAdjustment) 수신시
// 항상 positive 응답시 데이터의 길이는 1바이트에 응답 데이터 0x01로 응답한다.
// 위 내용은 명확히 스펙화 되어 있는것은 아니고
// 이전 양산 코드에서 적용된 대로 그대로 적용한다
// ES SPEC을 고려하여 수정하다가 자칫 현재 진단기에서 문제가 될 가능성도 있다.
// 그러므로 그냥 이전 양산 소스 그대로 복원하기로 한다.

// WPC_473_02
// InputOutputControlParameter : 0x0 (retrunControlToEcu), 0x1 (resetToDefault), 0x2 (freezeCurrentState), 0x3 (shortTermAdjustment)
Std_ReturnType InputOutputControlbyIdentifier_11_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_11_Read(uint8* Data)
{	// Positive 응답하는 데이터 값 설정하는 부분
    Std_ReturnType retValue = RTE_E_OK;
	Data[0] = 0x1;	// GN7, CE1등 이전 양산품과 동일하게 항상 1로 응답하도록 복원함. 이전까지의 진단기가 이 응답으로 알고 있기 때문임. 괜히 ES SPEC에 맞게 수정했다가 오히려 문제 될수 있으므로 그냥 이전과 동일하게 복원함.

	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_11_ReturnControlToECU(uint8* ErrorCode)
{
	// 0x0 (retrunControlToEcu) 에 의해서도 호출되지만
	// 0x3 (shortTermAdjustment) 호출  후 Test present (5초)가 유지 되지 않을 경우에도 자동으로 호출된다.
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	Uds.Out.DiagAmberBlink = OFF;

	return retValue;
}

Std_ReturnType InputOutputControlbyIdentifier_11_ReadDataLength(uint16* DataLength)
{// positive 응답시 응답 데이터 길이 설정하는 부분
    Std_ReturnType retValue = RTE_E_OK;

	*DataLength = 1u;	// GN7, CE1등 이전 양산품과 동일하게 항상 1byte length 복원함. 이전까지의 진단기가 이 응답으로 알고 있기 때문임. 괜히 ES SPEC에 맞게 수정했다가 오히려 문제 될수 있으므로 그냥 이전과 동일하게 복원함.

    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_11_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode)
{
	// InputOutputControlParameter : 0x3 (shortTermAdjustment) 수신시 call
	// DataLength는 수신하지만 이전부터 사용하지 않음.
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	if((Uds.Inp_ADC.IGN1_IN == ON) &&
	(Uds.Inp_ADC.BatSysStateFault == OFF))
	{
		Uds.Out.DiagAmberBlink = ON;
		*ErrorCode = DCM_E_POSITIVERESPONSE;
		retValue = RTE_E_OK;
	}
	else
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		retValue = E_NOT_OK;
	}

	return retValue;
}

/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_12 : $F012 (Request Data Size : 8bit Need mobilgene setting)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
// InputOutputControlParameter : 0x0 (retrunControlToEcu), 0x1 (resetToDefault), 0x2 (freezeCurrentState), 0x3 (shortTermAdjustment)
Std_ReturnType InputOutputControlbyIdentifier_12_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_12_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
	Data[0] = 0x01;
	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_12_ReturnControlToECU(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	Uds.Out.DiagGreenBlink = OFF;

	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_12_ReadDataLength(uint16* DataLength)
{
    Std_ReturnType retValue = RTE_E_OK;
	*DataLength = 1u;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_12_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	if((Uds.Inp_ADC.IGN1_IN == ON) &&
	(Uds.Inp_ADC.BatSysStateFault == OFF))
	{
		Uds.Out.DiagGreenBlink = ON;
		*ErrorCode = DCM_E_POSITIVERESPONSE;
		retValue = RTE_E_OK;
	}
	else
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		retValue = E_NOT_OK;
	}

	return retValue;
}

/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_13 : $F013 (Request Data Size : 8bit Need mobilgene setting)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		:
*******************************************************************************/
// InputOutputControlParameter : 0x0 (retrunControlToEcu), 0x1 (resetToDefault), 0x2 (freezeCurrentState), 0x3 (shortTermAdjustment)
Std_ReturnType InputOutputControlbyIdentifier_13_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_13_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
	Data[0] = 0x01;
	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_13_ReturnControlToECU(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	Uds.Out.DiagFanRotate = OFF;

	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_13_ReadDataLength(uint16* DataLength)
{
    Std_ReturnType retValue = RTE_E_OK;
	*DataLength = 1u;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_13_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	if((Uds.Inp_ADC.IGN1_IN == ON) &&
	(Uds.Inp_ADC.BatSysStateFault == OFF))
	{
		Uds.Out.DiagFanRotate = ON;
		*ErrorCode = DCM_E_POSITIVERESPONSE;
		retValue = RTE_E_OK;
	}
	else
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		retValue = E_NOT_OK;
	}

	return retValue;
}



/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_16 : $F016 (Request Data Size : 8bit Need mobilgene setting)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: dvp1 msg Start/Stop
*******************************************************************************/
// InputOutputControlParameter : 0x0 (retrunControlToEcu), 0x1 (resetToDefault), 0x2 (freezeCurrentState), 0x3 (shortTermAdjustment)
// ex: 0x3 (shortTermAdjustment) 수신시
// 1. InputOutputControlbyIdentifier_11_ShortTermAdjustment() -->
// 2. InputOutputControlbyIdentifier_11_ConditionCheckRead() -->
// 3. InputOutputControlbyIdentifier_11_ReadDataLength() -->
// 4. InputOutputControlbyIdentifier_11_Read() 순으로 호출됨.
Std_ReturnType InputOutputControlbyIdentifier_16_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	/* WPC_2426_04 Start */
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}

    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_16_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
	Data[0] = 0x01;
	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_16_ReturnControlToECU(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	Uds.Out.DiagDvp1Start = OFF;

	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_16_ReadDataLength(uint16* DataLength)
{
    Std_ReturnType retValue = RTE_E_OK;
	*DataLength = 1u;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_16_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength,	uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	// 실제 기능도 동작하지 않도록 함.
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}
	else
	{
		Uds.Out.DiagDvp1Start = ON; // Dvp 커맨드는 D0,D1이 구분되어 있으나 현재는 동일하게 사용함.

		retValue = RTE_E_OK;
		*ErrorCode = DCM_E_POSITIVERESPONSE;
	}

	return retValue;
}



/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_17 : $F017 (Request Data Size : 8bit Need mobilgene setting)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: WCT IC Reprogram Start/Stop
*******************************************************************************/
// InputOutputControlParameter : 0x0 (retrunControlToEcu), 0x1 (resetToDefault), 0x2 (freezeCurrentState), 0x3 (shortTermAdjustment)
// ex: 0x3 (shortTermAdjustment) 수신시
// 1. InputOutputControlbyIdentifier_11_ShortTermAdjustment() -->
// 2. InputOutputControlbyIdentifier_11_ConditionCheckRead() -->
// 3. InputOutputControlbyIdentifier_11_ReadDataLength() -->
// 4. InputOutputControlbyIdentifier_11_Read() 순으로 호출됨.
Std_ReturnType InputOutputControlbyIdentifier_17_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	/* WPC_2426_04 Start */
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}

    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_17_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
	Data[0] = 0x01;
	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_17_ReturnControlToECU(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	Uds.Out.Repro_Start = OFF;

	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_17_ReadDataLength(uint16* DataLength)
{
    Std_ReturnType retValue = RTE_E_OK;
	*DataLength = 1u;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_17_ShortTermAdjustment(uint8* ControlStateInfo, uint16 DataLength,	uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	// 실제 기능도 동작하지 않도록 함.
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}
	else
	{
		if((Uds.Inp_ADC.IGN1_IN == OFF) &&
		(Uds.Inp_ADC.BatSysStateFault == OFF))
		{
			Uds.Out.Repro_Start = ON;

			retValue = RTE_E_OK;
			*ErrorCode = DCM_E_POSITIVERESPONSE;
		}
		else
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			retValue = E_NOT_OK;
		}
	}

	return retValue;
}


/*******************************************************************************
	Module Name : InputOutputControlbyIdentifier_18 : $F018 (Request Data Size : 80bit Need mobilgene setting)
	Function	: Invoked Event
	Parameters	:
	Return		:
	Remark		: DvpData Set
*******************************************************************************/
Std_ReturnType InputOutputControlbyIdentifier_18_ConditionCheckRead(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	/* WPC_2426_04 Start */
	if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
	{
		retValue = E_NOT_OK;
		*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}

    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_18_Read(uint8* Data)
{
    Std_ReturnType retValue = RTE_E_OK;
	Data[0] = 0x01;
	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_18_ReturnControlToECU(uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	uint8_t i;
	for(i=0; i<10u; i++)
	{
		Uds.Out.DvpTuneData[i] = 0;
	}

	return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_18_ReadDataLength(uint16* DataLength)
{
    Std_ReturnType retValue = RTE_E_OK;
	*DataLength = 1u;
    return retValue;
}
Std_ReturnType InputOutputControlbyIdentifier_18_ShortTermAdjustment(const uint8* ControlStateInfo, uint16 DataLength, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	uint8_t i;
	for(i=0; i<10u; i++)
	{
		Uds.Out.DvpTuneData[i] = ControlStateInfo[i];
	}

	return retValue;
}



/*******************************************************************************
** Routine Control ($31 hex) Service                       **
*******************************************************************************/

// GN7.0D_13 start
/*******************************************************************************
	Module Name : OTA Ready :
	Function	: Invoked Event
	Parameters	:
	Return		: RTE_E_OK     - Request was successful
	Remark		: RTE_E_NOT_OK - Request was not successful
*******************************************************************************/
Std_ReturnType OTAReady_Start(uint8 OpStatus,	uint8* DataOut_OutSignal, uint8* ErrorCode)
{
    Std_ReturnType retValue = RTE_E_OK;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

	// 현재는 OTA Ready에 요청에 대해서 항상 긍정 응답을 하고 있다.
	// Negative / Pending은 아직 추가하지 않음.
	// 어떤 조건에서 negative, pending을 회신해야 하는지 결정되면
	// 로직 추가 할것.

	switch(OpStatus)
	{
		case DCM_INITIAL :
			DataOut_OutSignal[0] = 0x01;
            retValue = RTE_E_OK;
			break;

		case DCM_PENDING :
			retValue = RTE_E_OK;
			break;

		case DCM_CANCEL :
			retValue = RTE_E_OK;
			break;

		default :
                                    // rule 16.4
			break;
	}

	return retValue;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_Uds_L2H_Set(void)
{
	// Uds.Int.Runnable_State = 0u; // wakeup시 다시 시작하면 안됨.
									// wakeup시마다 memset() 초기화가 호출되어 Uds.Out.Uds_LPConditionFlag = OFF;가 되어
									// LCAN에 의해서 Wakeup 될때도 BCAN이 Wakeup 조건인 Uds.Out.Uds_LPConditionFlag = OFF가 되어 BCAN이 wakeup 되버린다.

									// 장기적으로는 LPConditionFlag = OFF 일때 Wakeup되는것이 문제임.
									// flag 명을 바꿔서 OFF일때 Sleep이고 ON일때 Wakeup 되도록 변경해야함.
									// 이렇게 하면 wakeup시마다 out. 구조체 변수를 초기화해도 wakup조건이 아니므로 wakeup 되지 않을 것임.

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_Uds_H2L_Set(void)
{



}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Uds_LPConditionCheck(void)
{

    if (Uds.Int.swDiagSessionTimer != 0u)
	{
		Uds.Out.Uds_LPConditionFlag = OFF;	// Active
	}
	else
	{
		Uds.Out.Uds_LPConditionFlag = ON;	// Sleep
	}

}







// 배포시에 포함된 App_DiagnosticService.c에 포함되어 있던 함수이나
// 현대 사양 로직을 포함시켜야 해서 이쪽으로 이동시킴.
/*******************************************************************************
** Function Name        : ServiceRequestSupplierNotification_Indication       **
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
// FUNC(Std_ReturnType, SWC_DiagnosticService_CODE) ServiceRequestSupplierNotification_Indication(
//   IN VAR(uint8, AUTOMATIC) SID,
//   uint8* RequestData,
//   uint16 DataSize,
//   IN VAR(uint8, AUTOMATIC) ReqType,
//   uint16 SourceAddress,
//   uint8* ErrorCode)
FUNC(Std_ReturnType, SWC_DiagnosticService_CODE) ServiceRequestSupplierNotification_Indication(
	IN VAR(uint8, AUTOMATIC) SID,
	IN P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData,
	IN VAR(uint16, AUTOMATIC) DataSize,
	IN VAR(uint8, AUTOMATIC) ReqType,
	IN VAR(uint16, AUTOMATIC) SourceAddress,
	OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode) /* PRQA S 3432 1 */
{
	Std_ReturnType retValue = RTE_E_OK;
	*ErrorCode = DCM_E_POSITIVERESPONSE;

// 모든 진단 요청시마다 호출되는 콜백 함수임.

  	Uds.Int.swDiagSessionTimer = cDiagSessionP3Timer;

// ES95486-02 UDS 진단 통신 통합 사양서에 엔진 조건에 대해서
// 표로 정확하게 명시되어 있어서 사양대로 로직 변경함. (2023.09.20)
// engine runnin 을 이외의 조건은 모두 engine stop 판정함. (진단 사양서 표)

// Engine Running/Stop : Except Engine running or Drivable, The others are ENGINE STOP
/*
---------------------------------------------------------------------------------------------------------------------------------
| EMS_02 (ENG_EngSta), Emission Engine  | HCU_03 (HCU_HevRdySta), Hybrid            | VCU_01 (VCU_01_10ms), EV                  |
---------------------------------------------------------------------------------------------------------------------------------
| Value Description  | Engine condition | Value Description      | Engine condition | Value Description      | Engine condition |
---------------------------------------------------------------------------------------------------------------------------------
| 0x00 : Engine stop | STOP             | 0x00 : HEV not ready   | STOP             | 0x00 : None            | STOP             |
| 0x01 : Cranking    | STOP             | 0x01 : HEV Drivable    | Running          | 0x01 : EV Drivable     | Running          |
| 0x02 : Stalled     | STOP             | 0x02 : Not used        | STOP             | 0x02 : Not used        | STOP             |
| 0x03 : Running     | Running          | 0x03 : Error Indicator | STOP             | 0x03 : Error Indicator | STOP             |
| 0x07 : Fault       | STOP             |                        |                  |                        |                  |
---------------------------------------------------------------------------------------------------------------------------------
*/


// WPC_37_03 start
// GN7.1D_01 start
	if ((SID == 0x10u) &&	// SID : DiagnosticSessionControl
	((RequestData[0] == 0x02u) || // Programing Session (0x02) : response해야 하는 sub function
	(RequestData[0] == 0x82u))) // WPC_109_04 	 // Programing Session (0x82) : response 없이 처리하는 펑션. 테스트 케이스 악의조건에 있음
	{
// WPC_47_02 start
// #if cDEBUG_WDT == ON // WPC_85_02 // wdt enable disable 여부와 무관하게 항상 disable처리하자.
		Rte_Call_R_WDT_EN_WriteDirect(OFF);	// GN7.1F_09 // WDT disable (high) // low active, high is disable
		// direct 포트 제어와 request 요청 둘다 동시에 처리하도록 함.
		Uds.Out.WdtDisable_ProgramSession =ON; // WPC_418_04 // WDT Disable Request ON
//#endif

		if ((Uds.Inp_CAN_RX.BCAN.C_ENG_EngSta != 0x03u) &&
		(Uds.Inp_CAN_RX.BCAN.C_HCU_HevRdySta != 0x01u) &&
		(Uds.Inp_CAN_RX.BCAN.C_VCU_EvDrvRdySta != 0x01u))
		{
			*ErrorCode = DCM_E_POSITIVERESPONSE;
			retValue = RTE_E_OK;
		}
		else
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;// WPC_5D_01
			retValue = E_NOT_OK;
		}
	}

// OTA 제어 대상 제어기임.
	else if((SID == 0x11u)	|| // SID : ECUReset
	(SID == 0x28u)) // SID : CommunicationControl
	{
		if ((Uds.Inp_CAN_RX.BCAN.C_ENG_EngSta != 0x03u) &&
		(Uds.Inp_CAN_RX.BCAN.C_HCU_HevRdySta != 0x01u) &&
		(Uds.Inp_CAN_RX.BCAN.C_VCU_EvDrvRdySta != 0x01u))
		{
			*ErrorCode = DCM_E_POSITIVERESPONSE;
			retValue = RTE_E_OK;
		}
		else
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;// WPC_5D_01
			retValue = E_NOT_OK;
		}
	}
	else if((SID == 0x2Eu) || // SID : WriteDataByIdenfifier
	(SID == 0x3Du))		// SID : WriteMemoryByAddress
	{
		if ((Uds.Inp_CAN_RX.BCAN.C_ENG_EngSta != 0x03u) &&
		(Uds.Inp_CAN_RX.BCAN.C_HCU_HevRdySta != 0x01u) &&
		(Uds.Inp_CAN_RX.BCAN.C_VCU_EvDrvRdySta != 0x01u) &&
		(Uds.Inp_ADC.IGN1_IN == ON)) // ign on
		{
			*ErrorCode = DCM_E_POSITIVERESPONSE;
			retValue = RTE_E_OK;
		}
		else
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;// WPC_5D_01
			retValue = E_NOT_OK;
		}
	}
	else if((SID == 0x22u) &&  // SID : read
	(RequestData[0] == 0x52u) && // secure mode 진입시 wdt disable 처리함. 해당 uds에서 처리했더니 가끔 리셋 걸림
	(RequestData[1] == 0x42u))
	{
		Rte_Call_R_WDT_EN_WriteDirect(OFF);	// WDT disable (port high) // Direct로 wdt disable 하고 나서 rte 요청하기로 함.
		Uds.Out.WdtDisable_ConfigLock = ON; // WDT Disable Request ON

		// 지금까지 아래 코드를 추가 하지 않았었음. 그런데도 정상 동작했음. 아마도 쓰레기 값이 0 으로 리턴되었던듯함.
		*ErrorCode = DCM_E_POSITIVERESPONSE;
		retValue = RTE_E_OK;

		/* WPC_2426_04 Start */
		if(Uds.Out.m_B0BADisableCnt >= UDS_B0BA_LIMIT)	/* 카운트가 limit값 이상이면 notsupported 출력 */
		{
			retValue = E_NOT_OK;
			*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
		}
	}
	// ES95489-21 : 4.2.14.강제 구동 조건 강화 --> 반영
	// 강제 구동은 정차 상태에서만 허용해야 한다. (강제구동 서비스(0x2F) 사용 시에만 해당)
	// 필요시 별도 협의 후 예외 혀용함.
	// 정차 상태는 0kph이나 오차 고려하여 5kph미만으로 정의한다.
	// 강제 구동 진입 후 상태 조건 변경 시 강제 구동을 중단한다.
	else if(SID == 0x2Fu)	// SID : InputOutputControlByIdentifie
	{
		if(Uds.Inp_CAN_RX.BCAN.C_CLU_DisSpdVal_KPH < 5u)
		{
			*ErrorCode = DCM_E_POSITIVERESPONSE;
			retValue = RTE_E_OK;
		}
		else
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			retValue = E_NOT_OK;
		}

	}
	else
	{
		*ErrorCode = DCM_E_POSITIVERESPONSE;
		retValue = RTE_E_OK;
	}

	// SID : 0x31, 0x34, 0x35, 0x36, 0x37 --> No Restriction (제한 없음)
	// SID : 0x2F : 제어기 특화 (일단 No Restriction으로 설정함.)


	/* 010A_02 */
	// 통신 상태 유지를 위해서 test present 가 주기적으로 송신된다.
	// 2초 주기, 타임아웃 4초
	if((SID == 0x3E) &&	// test present
	(RequestData[0] == 0x00u))
	{
		Uds.Out.TestPresent = ON;

		Uds.Int.TestPresentHoldCnt = Par_TestPresentHoldTime; // 4초
	}
	/* 010A_02 */

	return retValue;
}


#define App_Uds_STOP_SEC_CODE
#include "App_Uds_MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
