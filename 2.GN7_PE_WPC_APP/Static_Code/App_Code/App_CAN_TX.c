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
#include "App_CAN_TX.h"
#include "Rte_App_CAN_TX.h"

#include "App_WCT.h"
#include "App_Version.h"

#include "CanTp_PCTypes.h"
#include "Hsm_AppInfo.h"
#include "Hsm_HostAPI.h"

#include "ErrM_Cbk_User.h"

#include "EcuM.h" // EcuM_GetResetReason()

#define RTE_ALLOW_CROSS_HEADER_INCLUSION
#include "Fbl_SharedCfg.h"	// fbl version read
#include "Rte_App_CAN_RX.h"

#define App_CAN_TX_START_SEC_CODE
#include "App_CAN_TX_MemMap.h"

/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/



/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

typedef struct
{
	uint8_t Runnable_State;
	uint8_t App_Init_Completed;

	Mcu_ResetType ResetReason;

	HSM_VERSION_CTX_t HSM_Ver; // 초기화 되면 안되므로 별도 초기화 하지 않는다.
	
	uint8_t TCI_CODE;
	
	Event_t IGN1_IN_Evt;
	
	uint8_t HSM_Version_Unmatch;

} Inter_t;


typedef struct
{
	IDT_ADC_STR 	Inp_ADC;
	IDT_Mode_STR 	Inp_Mode;
	IDT_WCT_STR		Inp_WCT;
	IDT_NFC_STR		Inp_NFC;
	IDT_Uds_STR 	Inp_Uds;
	IDT_Model_STR	Inp_Model;
	IDT_UART_STR	Inp_UART;
	IDT_Repro_STR 	Inp_Repro;
	IDT_DTC_STR		Inp_DTC;
	IDT_NvM_STR		Inp_NvM;	
	IDT_WDT_STR 	Inp_WDT;

	Inter_t Int;

	// TX는 out없음

} CAN_TX_struct;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/
static CAN_TX_struct CAN_TX = {0};

static MsgGr_E2E_BCAN_WPC_FD_01_200ms BCAN_WPC_FD_01_200ms_tmp = {0};
static MsgGr_E2E_BCAN_WPC_FD_01_200ms BCAN_WPC_FD_01_200ms_tmp_old = {0};
static MsgGr_E2E_BCAN_WPC2_FD_01_200ms BCAN_WPC2_FD_01_200ms_tmp = {0};
static MsgGr_E2E_BCAN_WPC2_FD_01_200ms BCAN_WPC2_FD_01_200ms_tmp_old = {0};

static MsgGr_E2E_LCAN_L_WPC_FD_01_00ms LCAN_L_WPC_FD_01_00ms_tmp = {0};
static MsgGr_E2E_LCAN_L_WPC_FD_01_00ms LCAN_L_WPC_FD_01_00ms_tmp_old = {0};
static MsgGr_E2E_LCAN_L_WPC_FD_20_200ms LCAN_L_WPC_FD_20_200ms_tmp = {0};
static MsgGr_E2E_LCAN_L_WPC_FD_20_200ms LCAN_L_WPC_FD_20_200ms_tmp_old = {0};

static MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms WPC_FD_VCRM_01_00ms_tmp = {0};
static MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms WPC_FD_VCRM_01_00ms_tmp_old = {0};

/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_CAN_TX_InitSet(void);
static void ss_CAN_TX_RteRead(void);
static void ss_CAN_TX_RteWrite(void);
static void ss_CAN_TX_DvpWrite(void);

static void ss_GetResetReason(void);
static void ss_HsmVersion_Check(void);

static void ss_CAN_TX_DvpMessageClear(void);

/* Extern for EcuM_GetResetReason API */
//extern uint8_t EcuM_GetResetReason(uint8_t * resetReason);

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/
extern const SW_BlkFlashInfo App_SoftwareVersionHeader; /* 0108_14 */

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_CAN_TX_CODE) CAN_TX_TE_Runnable(void)
{
	static uint16_t ErrM_CycleCnt = 0;

	switch(CAN_TX.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&CAN_TX.Int.App_Init_Completed);				/* SWP Init Complete Check */

			if( CAN_TX.Int.App_Init_Completed == ON ) /* SWP Init Complete? */
			{
				/* SWC Init Process */
				ss_CAN_TX_InitSet();

				CAN_TX.Int.Runnable_State = 1u;	/*  Main Runnable Mode Move > App Run */
			}
		break;

		case 1u:
#if defined ( DEBUG_ErrM_Module_USE )
			ErrM_CycleCnt ++;
			if(ErrM_CycleCnt >= 10u)	// 100ms 인터벌
			{
				ErrM_CycleCnt = 0;
				gs_GetCpuLoad();
				gs_GetStackUsage();
				gs_GetOsError();
			}

#endif
			ss_GetResetReason();
			ss_HsmVersion_Check();
			ss_CAN_TX_RteRead();
			ss_CAN_TX_RteWrite();
			ss_CAN_TX_DvpWrite();
		break;

		default:
			CAN_TX.Int.Runnable_State = 0u;
		break;
	}
}
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static  void    ss_CAN_TX_InitSet(void)
{

	CAN_TX.Int.ResetReason = MCU_RESET_UNDEFINED;

	// TCI_CODE;
    #if defined (TCI_Code_Hyundai)
		CAN_TX.Int.TCI_CODE = 0u;
    #elif defined (TCI_Code_Kia)
		CAN_TX.Int.TCI_CODE = 1u;
	#elif defined (TCI_Code_Genesis)
		CAN_TX.Int.TCI_CODE = 2u;
    #else
    	Error : not defined
    #endif

}
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_CAN_TX_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_ADC_ADC_STR(&CAN_TX.Inp_ADC);
	Rte_Read_R_Mode_Mode_STR(&CAN_TX.Inp_Mode);
	Rte_Read_R_WCT_WCT_STR(&CAN_TX.Inp_WCT);
	Rte_Read_R_NFC_NFC_STR(&CAN_TX.Inp_NFC);
	Rte_Read_R_Uds_Uds_STR(&CAN_TX.Inp_Uds);
	Rte_Read_R_Model_Model_STR(&CAN_TX.Inp_Model);
	Rte_Read_R_UART_UART_STR(&CAN_TX.Inp_UART);	
	Rte_Read_R_Repro_Repro_STR(&CAN_TX.Inp_Repro);
	Rte_Read_R_DTC_DTC_STR(&CAN_TX.Inp_DTC);
	Rte_Read_R_NvM_NvM_STR(&CAN_TX.Inp_NvM);
	Rte_Read_R_WDT_WDT_STR(&CAN_TX.Inp_WDT);
	
	gs_UpdateEvent(CAN_TX.Inp_ADC.IGN1_IN, &CAN_TX.Int.IGN1_IN_Evt);	// event update	
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void  ss_CAN_TX_RteWrite(void)
{
	// BCAN BUS 로 전송
	if ((CAN_TX.Inp_Mode.PduGroupTx_BCAN_PNC141 == RTE_MODE_MDG_PduGroup_START) || 	// BCAN WPC
	(CAN_TX.Inp_Mode.PduGroupTx_BCAN_PNC153 == RTE_MODE_MDG_PduGroup_START) ||		// BCAN B2-CAN
	(CAN_TX.Inp_Mode.PduGroupTx_BCAN_PNC32 == RTE_MODE_MDG_PduGroup_START))			// BCAN All ECUs
	{

		// E2E 메세지는 제어기 노드간의 무결성 검사가 아니라
		// 동일 제어기 내에서 각 레이어 간에 무결성 검사이다.
		// 즉 어플리케이션에서 설정한 값과 can bsw 사이에 무결성을 검사하는 것이다.
		// 이유는 모르겠으나 Rte_Write_BCAN_WPC_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms()를
		// 호출할때마다 can 메세지가 즉시 노드에 전송되므로
		// 기존 방식이 아니라 값의 변경이 있을때만 호출되도록 로직 구성함.
		// 그리고 주기 메세지 이지만 이벤트 발생시에는 그 즉시 전송되어야 하므로
		// 아래 로직으로 처리해야함.
		
		// BCAN_WPC_FD_01_200ms (DBC 파일 배치 순서로 정리)
		BCAN_WPC_FD_01_200ms_tmp.USM_CmdWPCIndSta = 0; // Dual에서는 미사용 신호이므로 0으로 설정함.
		BCAN_WPC_FD_01_200ms_tmp.USM_CmdWPCSta = CAN_TX.Inp_Model.Device[D0].WPCRValue;
		BCAN_WPC_FD_01_200ms_tmp.WPC_DualWPCOptSta = 1; // dual 항상 1
		BCAN_WPC_FD_01_200ms_tmp.WPC_IndSyncVal = 0; // Dual에서는 미사용 신호이므로 0으로 설정함.
		BCAN_WPC_FD_01_200ms_tmp.WPC_PhnLftWrngSta = CAN_TX.Inp_Model.Device[D0].WPCWarning;		
		BCAN_WPC_FD_01_200ms_tmp.WPC_ResetOpSta = CAN_TX.Inp_WDT.WPC_ResetOpSta;		

/* 0108_14 */ // U/R/S 롬 컴파일시 자동으로 버전만 변경되어 3가지 s19가 자동으로 생성되도록 하기 위해서 로직 변경함.
		// BCAN_WPC_FD_01_200ms_tmp.WPC_SWVerMajor1 = (uint8_t)cAppSoftVerYear1;
		// BCAN_WPC_FD_01_200ms_tmp.WPC_SWVerMinor1 = (uint8_t)cAppSoftVerYear2;
		// BCAN_WPC_FD_01_200ms_tmp.WPC_SWVerMinor2 = (uint8_t)cAppSoftVerMonth;

		BCAN_WPC_FD_01_200ms_tmp.WPC_SWVerMajor1 = App_SoftwareVersionHeader.currentVersion[0];
		BCAN_WPC_FD_01_200ms_tmp.WPC_SWVerMinor1 = App_SoftwareVersionHeader.currentVersion[1];
		BCAN_WPC_FD_01_200ms_tmp.WPC_SWVerMinor2 = App_SoftwareVersionHeader.currentVersion[2];			
/* 0108_14 */		
		
		// int memcmp(const void* buf1, const void* buf2, size_t size); 이므로 qac위해서 리턴값을 FALSE대신 0 (int)으로 변경함.
		if(memcmp(&BCAN_WPC_FD_01_200ms_tmp, &BCAN_WPC_FD_01_200ms_tmp_old, sizeof(MsgGr_E2E_BCAN_WPC_FD_01_200ms)) != 0)
		{
			if(Rte_Write_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms(&BCAN_WPC_FD_01_200ms_tmp) == RTE_E_OK)
			{
				BCAN_WPC_FD_01_200ms_tmp_old = BCAN_WPC_FD_01_200ms_tmp;
			}
		}
				
		if((CAN_TX.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(CAN_TX.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
		{			
			// BCAN_WPC2_FD_01_200ms
			BCAN_WPC2_FD_01_200ms_tmp.USM_CmdWPC2Sta = CAN_TX.Inp_Model.Device[D1].WPCRValue;
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_IndSyncVal = 0; // Dual에서는 미사용 신호이므로 0으로 설정함.
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_OptSta = 1; // Dual			
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_PhnLftWrngSta = CAN_TX.Inp_Model.Device[D1].WPCWarning;
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_ResetOpSta = CAN_TX.Inp_WDT.WPC_ResetOpSta;	
/* 0108_14 */ // U/R/S 롬 컴파일시 자동으로 버전만 변경되어 3가지 s19가 자동으로 생성되도록 하기 위해서 로직 변경함.
			// BCAN_WPC2_FD_01_200ms_tmp.WPC2_SWVerMajor1 = (uint8_t)cAppSoftVerYear1;
			// BCAN_WPC2_FD_01_200ms_tmp.WPC2_SWVerMinor1 = (uint8_t)cAppSoftVerYear2;
			// BCAN_WPC2_FD_01_200ms_tmp.WPC2_SWVerMinor2 = (uint8_t)cAppSoftVerMonth;
			
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_SWVerMajor1 = App_SoftwareVersionHeader.currentVersion[0];
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_SWVerMinor1 = App_SoftwareVersionHeader.currentVersion[1];
			BCAN_WPC2_FD_01_200ms_tmp.WPC2_SWVerMinor2 = App_SoftwareVersionHeader.currentVersion[2];				
/* 0108_14 */			
			if(memcmp(&BCAN_WPC2_FD_01_200ms_tmp, &BCAN_WPC2_FD_01_200ms_tmp_old, sizeof(MsgGr_E2E_BCAN_WPC2_FD_01_200ms)) != 0)
			{
				if(Rte_Write_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms(&BCAN_WPC2_FD_01_200ms_tmp) == RTE_E_OK)
				{
					BCAN_WPC2_FD_01_200ms_tmp_old = BCAN_WPC2_FD_01_200ms_tmp;
				}
			}			
		}				
		
		WPC_FD_VCRM_01_00ms_tmp.WPC_PhnUsingTime				= CAN_TX.Inp_WCT.VCRM[0].PhnUsingTime;
		WPC_FD_VCRM_01_00ms_tmp.WPC_PhnChargingCompleteCnt		= CAN_TX.Inp_WCT.VCRM[0].PhnChargingCompleteCnt;
		WPC_FD_VCRM_01_00ms_tmp.WPC_EPPChargingCnt				= CAN_TX.Inp_WCT.VCRM[0].EPPChargingCnt;
		WPC_FD_VCRM_01_00ms_tmp.WPC_MPPChargingCnt				= CAN_TX.Inp_WCT.VCRM[0].MPPChargingCnt;
		WPC_FD_VCRM_01_00ms_tmp.WPC_DigitalKeyAuth				= CAN_TX.Inp_WCT.VCRM[0].DigitalKeyAuth;
		WPC_FD_VCRM_01_00ms_tmp.WPC_DigitalKeyDevice			= CAN_TX.Inp_WCT.VCRM[0].DigitalKeyDevice;
		WPC_FD_VCRM_01_00ms_tmp.WPC_PhnChargingErrCnt			= CAN_TX.Inp_WCT.VCRM[0].PhnChargingErrCnt;
		WPC_FD_VCRM_01_00ms_tmp.WPC_ThermalSnsrMaxTemp			= CAN_TX.Inp_WCT.VCRM[0].ThermalSnsrMaxTemp;
		WPC_FD_VCRM_01_00ms_tmp.WPC_CANBusOffDTC				= CAN_TX.Inp_WCT.VCRM[0].CANBusOffDTC;
		WPC_FD_VCRM_01_00ms_tmp.WPC_LocalCANBusOffDTC			= CAN_TX.Inp_WCT.VCRM[0].LocalCANBusOffDTC;
		WPC_FD_VCRM_01_00ms_tmp.WPC_TempSnsrFltDTC				= CAN_TX.Inp_WCT.VCRM[0].TempSnsrFltDTC;
		WPC_FD_VCRM_01_00ms_tmp.WPC_FANFltDTC					= CAN_TX.Inp_WCT.VCRM[0].FANFltDTC;
		WPC_FD_VCRM_01_00ms_tmp.WPC_InternalECUErrDTC			= CAN_TX.Inp_WCT.VCRM[0].InternalECUErrDTC;		
	
		if(CAN_TX.Int.IGN1_IN_Evt.Off_Event == ON)
		{
			if(Rte_Write_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms(&WPC_FD_VCRM_01_00ms_tmp) == RTE_E_OK)
			{
				WPC_FD_VCRM_01_00ms_tmp_old = WPC_FD_VCRM_01_00ms_tmp;
			}
		}
		else
		{
			/* do nothing */
		}				
	}

	if((CAN_TX.Inp_Mode.PduGroupTx_LCAN_PNC159 == RTE_MODE_MDG_PduGroup_START) ||	// LCAN BDC 전체. bdc에 물려있는 모든 제어기 tx 됨.
	(CAN_TX.Inp_Mode.PduGroupTx_LCAN_PNC32 == RTE_MODE_MDG_PduGroup_START))		// LCAN All ECUs
	{
		LCAN_L_WPC_FD_01_00ms_tmp.WPC_NFCDetection_Sta = CAN_TX.Inp_NFC.Device[D0].NFCDetection;
		LCAN_L_WPC_FD_01_00ms_tmp.WPC_NFCReset_Sta = CAN_TX.Inp_NFC.Device[D0].NFCReset;

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
		if((CAN_TX.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(CAN_TX.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
		{			
			LCAN_L_WPC_FD_01_00ms_tmp.WPC2_NFCDetection_Sta = CAN_TX.Inp_NFC.Device[D1].NFCDetection;
			LCAN_L_WPC_FD_01_00ms_tmp.WPC2_NFCReset_Sta = CAN_TX.Inp_NFC.Device[D1].NFCReset;
		}
//#endif			
		if(memcmp(&LCAN_L_WPC_FD_01_00ms_tmp, &LCAN_L_WPC_FD_01_00ms_tmp_old, sizeof(MsgGr_E2E_LCAN_L_WPC_FD_01_00ms)) != 0)
		{
			if(Rte_Write_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms(&LCAN_L_WPC_FD_01_00ms_tmp) == RTE_E_OK)
			{
				LCAN_L_WPC_FD_01_00ms_tmp_old = LCAN_L_WPC_FD_01_00ms_tmp;
			}
		}
		else
		{
			/* do nothing */
		}

		LCAN_L_WPC_FD_20_200ms_tmp.WPC_Status = CAN_TX.Inp_Model.Device[D0].WPCStatus;
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */			
		if((CAN_TX.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(CAN_TX.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
		{
			LCAN_L_WPC_FD_20_200ms_tmp.WPC2_Status = CAN_TX.Inp_Model.Device[D1].WPCStatus;
		}
//#endif		
		
		LCAN_L_WPC_FD_20_200ms_tmp.WPC_NFC_Opt = CAN_TX.Inp_NvM.NfcOption; /* 010C_08 */ // C_WPCNFC_Option 0x0:Default(NotApplied)/0x1:Applied/0x2:Reserved/0x3:invalid

		if(memcmp(&LCAN_L_WPC_FD_20_200ms_tmp, &LCAN_L_WPC_FD_20_200ms_tmp_old, sizeof(MsgGr_E2E_LCAN_L_WPC_FD_20_200ms)) != 0)
		{
			if(Rte_Write_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms(&LCAN_L_WPC_FD_20_200ms_tmp) == RTE_E_OK)
			{
				LCAN_L_WPC_FD_20_200ms_tmp_old = LCAN_L_WPC_FD_20_200ms_tmp;
			}
		}
		else
		{
			/* do nothing */
		}
	}

	// 타 SWC에 전달할 내용 없음.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
// WPC_5D_02 start
static void ss_HsmVersion_Check(void)
{
	static uint8_t InitCheckFlag1 = OFF;

	if(InitCheckFlag1 == OFF)
	{
		InitCheckFlag1 = ON;

		HSM_GetVersionInfo(&CAN_TX.Int.HSM_Ver);

		if((CAN_TX.Int.HSM_Ver.hsmMajorVersion != CAN_TX.Int.HSM_Ver.driverMajorVersion) ||
		(CAN_TX.Int.HSM_Ver.hsmMinorVersion != CAN_TX.Int.HSM_Ver.driverMinorVersion) ||
		(CAN_TX.Int.HSM_Ver.hsmPatchVersion != CAN_TX.Int.HSM_Ver.driverPatchVersion))
		{
			CAN_TX.Int.HSM_Version_Unmatch = ON;
		}
	}


}
// WPC_5D_02 stop


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_CAN_TX_DvpWrite(void)
{
	static uint8_t DvpSendTimeCnt = 0;
	static uint8_t DvpIndex = 1;	// 0부터 송신되기 위해서 1로 초기화
	static uint8_t Device = 1;	// 0부터 송신되기 위해서 1로 초기화
	uint16_t Temp;

	if((CAN_TX.Inp_Uds.DiagDvp1Start == ON) // DVP 송신 요청 플래그.
	|| (CAN_TX.Inp_Uds.Repro_Start == ON)
	) // repro percent 수신 받기 위해서
    {
		// BCAN BUS 로 전송
		if ((CAN_TX.Inp_Mode.PduGroupTx_BCAN_PNC141 == RTE_MODE_MDG_PduGroup_START) || 	// BCAN WPC
		(CAN_TX.Inp_Mode.PduGroupTx_BCAN_PNC153 == RTE_MODE_MDG_PduGroup_START) ||		// BCAN B2-CAN
		(CAN_TX.Inp_Mode.PduGroupTx_BCAN_PNC32 == RTE_MODE_MDG_PduGroup_START))			// BCAN All ECUs
		{
			DvpSendTimeCnt++;
		    if(DvpSendTimeCnt >= 5u) // 50ms 주기로 전송. 충전IC에서 100ms 주기로 device0/1이 모두 수신되므로 dvp도 100ms 주기에 device0/1 모두 전송되도록 한다.
		    {
		        DvpSendTimeCnt = 0u;
				DvpIndex = DvpIndex ^ 1u;	// device0과 device1이 toggle되면서 송신됨.
				Device = DvpIndex;

				// 공통 데이터. 중복으로 전송됨. dvp가 64바이트까지 전송 가능하므로 로직 단순화를 위해서 중복으로 전송되는것 감안함.
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte00((CAN_TX.Inp_NvM.LedDutyTableOption << 6u) | (CAN_TX.Inp_NvM.INDContType << 4u) |(CAN_TX.Inp_NvM.IndUSMOption << 3u) | (CAN_TX.Inp_NvM.RheostatOption << 2u ) | (CAN_TX.Inp_DTC.WctIcErrorDTC << 1u) | DvpIndex);
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte01((CanTp_GaaSTminBs[1].ucSTMin << 4u)| (CAN_TX.Int.TCI_CODE << 2u) | (CAN_TX.Int.HSM_Version_Unmatch << 1u) | (CAN_TX.Inp_UART.AutoCalibrated)); /* 0108_02 */ /* 0108_03 */ // lcan tp가 1번 채널일때 임.
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte02(CAN_TX.Inp_Repro.ReproPercent);
				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte03(CAN_TX.Inp_Repro.WctVerCheck & 0x03);
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte04(((SYNCHRO1 & 0x0F) << 4u) | (SYNCHRO2 & 0x0F));
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte05((CAN_TX.Int.HSM_Ver.hsmMajorVersion << 4u) | CAN_TX.Int.HSM_Ver.hsmMinorVersion);
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte06((CAN_TX.Int.HSM_Ver.hsmPatchVersion << 4u) | CAN_TX.Int.HSM_Ver.driverMajorVersion);
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte07((CAN_TX.Int.HSM_Ver.driverMinorVersion << 4u) | CAN_TX.Int.HSM_Ver.driverPatchVersion);
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte08((uint8_t)CAN_TX.Int.ResetReason);
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte09((CAN_TX.Inp_Repro.ReproErrCode << 3u) | CAN_TX.Inp_NvM.WPC_TYPE);
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte10(CAN_TX.Inp_Repro.ReproFlashStatus & 0x0F);


				// Device0, Device1 toggle 주기로 데이터 번갈아 가면서 전송됨.(device는 toggle의 2배 주기로 데이터 갱신됨)
				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte11((CAN_TX.Inp_UART.Device_WCT[Device].RxChargingStatus << 4u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte12((CAN_TX.Inp_UART.Device_WCT[Device].TxChargingStatus << 4u) | (CAN_TX.Inp_UART.Device_WCT[Device].TxChargingErrors));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte13((CAN_TX.Inp_Model.Device[Device].WPCStatus << 4u) | (CAN_TX.Inp_WCT.Device[Device].WCT_Status));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte14((CAN_TX.Inp_NFC.Device[Device].NFC_Status << 4u) | (CAN_TX.Inp_UART.Device_WCT[Device].DeviceState));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte15(CAN_TX.Inp_UART.Device_DVP[Device].ChargingRate);
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte16((CAN_TX.Inp_UART.Device_WCT[Device].TempSnsrError << 7u) | (CAN_TX.Inp_DTC.Device[Device].TempSnsrFaultDTC << 6u) | (CAN_TX.Inp_DTC.Device[Device].FanFaultDTC << 5u) | (CAN_TX.Inp_UART.Device_DVP[Device].SFC_Mode << 4u) | (CAN_TX.Inp_UART.Device_DVP[Device].bPLCFlag << 3u) | (CAN_TX.Inp_UART.Device_WCT[Device].AuthState << 2u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte16((CAN_TX.Inp_UART.Device_WCT[Device].TempSnsrError << 7u) | (CAN_TX.Inp_DTC.Device[Device].TempSnsrFaultDTC << 6u) | (CAN_TX.Inp_DTC.Device[Device].FanFaultDTC << 5u) | (CAN_TX.Inp_UART.Device_DVP[Device].bPLCFlag << 3u) | (CAN_TX.Inp_UART.Device_WCT[Device].AuthState << 2u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte17((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].wGuaranteedPowerHalfWatt & 0x00FFu));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte18((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].wMaximumPowerHalfWatt & 0x00FFu));				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte19(CAN_TX.Inp_UART.Device_DVP[Device].byQFactor);
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte20(CAN_TX.Inp_UART.Device_DVP[Device].byPowerPacketType);
				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte21((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].dwRxReportedPower & 0xFF000000u) >> 24u)); // MSB				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte22((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].dwRxReportedPower & 0x00FF0000u) >> 16u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte23((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].dwRxReportedPower & 0x0000FF00u) >> 8u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte24((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].dwRxReportedPower & 0x000000FFu)); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte25((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].dwActiveFreq & 0xFF000000u) >> 24u)); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte26((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].dwActiveFreq & 0x00FF0000u) >> 16u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte27((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].dwActiveFreq & 0x0000FF00u) >> 8u));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte28((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].dwActiveFreq & 0x000000FFu)); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte29((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].wRetryMeasuredQFactor & MSB_MASK) >> 8u)); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte30((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].wRetryMeasuredQFactor & LSB_MASK));
				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte31((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].wMeasuredQFactor & MSB_MASK) >> 8u)); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte32((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].wMeasuredQFactor & LSB_MASK));


				// singed 2byte이나 unsigned로 각각 1byte씩 송신하므로 수신처에서 sigend 2byte 변수로 할당해야함.
				// sigend 는 비트 연산시 숫자가 왜곡됨
				// unsigend 으로 변경후 비트 연산 처리함.

				// 이전 single 타입은 uint 변수였으나 dual 타입은 sint로 변경됨.
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swSFCPowerLossThresholdInOperationMode & MSB_MASK); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte33((uint8_t)(Temp >> 8u));
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swSFCPowerLossThresholdInOperationMode & LSB_MASK); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte34((uint8_t)Temp);

				// 이전 single 타입은 uint 변수였으나 dual 타입은 sint로 변경됨.
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swPowerLossDetectionThreshold & MSB_MASK); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte35((uint8_t)(Temp >> 8u));
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swPowerLossDetectionThreshold & LSB_MASK); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte36((uint8_t)Temp);

				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swNormalizedParasiticLoss & MSB_MASK); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte37((uint8_t)(Temp >> 8u));
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swNormalizedParasiticLoss & LSB_MASK); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte38((uint8_t)Temp);

				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swParasiticLoss & MSB_MASK); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte39((uint8_t)(Temp >> 8u));
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swParasiticLoss & LSB_MASK); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte40((uint8_t)Temp);

				// 이전 single 타입은 uint 변수였으나 dual 타입은 sint로 변경됨.
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swBPPLPPowerLossThresholdInOperationMode & MSB_MASK); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte41((uint8_t)(Temp >> 8u));
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].swBPPLPPowerLossThresholdInOperationMode & LSB_MASK); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte42((uint8_t)Temp);
	
				// sint32 이나 sint16으로 범위가 충분하여 sint16으로 사용함.
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].sdwTxPowerInCalibMode2 & MSB_MASK); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte43((uint8_t)(Temp >> 8u));
				Temp = (uint16_t)((uint16_t)CAN_TX.Inp_UART.Device_DVP[Device].sdwTxPowerInCalibMode2 & LSB_MASK); // LSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte44((uint8_t)Temp);	
				
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte45((uint8_t)((CAN_TX.Inp_UART.Device_DVP[Device].wReceivedPowerInConnectMode & MSB_MASK) >> 8u)); // MSB
				//Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte46((uint8_t)(CAN_TX.Inp_UART.Device_DVP[Device].wReceivedPowerInConnectMode & LSB_MASK));
								
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte47((uint8_t)((CAN_TX.Inp_UART.Device_WCT[Device].ManufactureID & MSB_MASK) >> 8u)); // MSB
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte48((uint8_t)(CAN_TX.Inp_UART.Device_WCT[Device].ManufactureID & LSB_MASK)); // LSB;
				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte49((CAN_TX.Inp_UART.Device_WCT[Device].ChargingMode & 0x0Fu));				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte50((CAN_TX.Inp_UART.Device_WCT[Device].RxChargingErrors));
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte51(0);	
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte52((CAN_TX.Inp_UART.Device_DVP[Device].Qi_Ver));
				
				Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte63(0);	// 마지막 바이트를 꼭 라이팅해줘야 전체 데이터가 전송됨
	
			}
		}
	}
	else
	{
		//ss_CAN_TX_DvpMessageClear(); // clear // 상시 DVP 메세지 출력 되버림. 주석처리함.
		DvpSendTimeCnt = 0;
		DvpIndex = 0;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_CAN_TX_DvpMessageClear(void)
{
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte01(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte02(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte03(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte04(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte05(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte06(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte07(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte08(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte09(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte10(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte11(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte12(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte13(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte14(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte15(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte16(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte17(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte18(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte19(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte20(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte21(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte22(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte23(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte24(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte25(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte26(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte27(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte28(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte29(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte30(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte31(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte32(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte33(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte34(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte35(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte36(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte37(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte38(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte39(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte40(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte41(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte42(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte43(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte44(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte45(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte46(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte47(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte48(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte49(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte50(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte51(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte52(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte53(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte54(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte55(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte56(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte57(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte58(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte59(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte60(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte61(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte62(0);
	Rte_Write_BCAN_WPCmsgDvp1_WPCmsgDvp1DataByte63(0);

}
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
// typedef enum
// {
//   MCU_RESET_UNDEFINED, 0
//   MCU_POWER_ON_RESET,1
//   MCU_WATCHDOG_RESET,2
//   MCU_ACT_FAULT_RESET,3
//   MCU_DPSLP_FAULT_RESET,4

//   MCU_TEST_DEBUG_RESET,5

//   MCU_SW_RESET,6
//   MCU_MCWDT0_RESET,7
//   MCU_MCWDT1_RESET,8
//   MCU_MCWDT2_RESET,9
//   MCU_MCWDT3_RESET,10

//   MCU_XRES_RESET,11 (Power on Reset)

//   MCU_BOD_VDDD_RESET,12
//   MCU_BOD_VDDA_RESET,13
//   MCU_BOD_VCCD_RESET,14
//   MCU_OVD_VDDD_RESET,15
//   MCU_OVD_VDDA_RESET,16
//   MCU_OVD_VCCD_RESET,17
//   MCU_OCD_ACTIVE_REGULATOR_RESET,18
//   MCU_OCD_DEEPSLEEP_REGULATOR_RESET,19
//   MCU_STRUCTURAL_XRES_RESET,20
//   MCU_CSV_HF_RESET,21
//   MCU_CSV_REF_RESET,22
//   MCU_WAKEUP_RESET,23
//   MCU_REGHC_OCD_RESET,24
//   MCU_REGHC_PMIC_RESET,25
//   MCU_PXRES_RESET 26
// }

// #include "WPC_types.h" 이 헤더 내용과 EcuM_GetResetReason()을 사용하기 위해서
// 선언해야 하는 헤더 내용이 서로 중복되는 변수가 있어서
// 컴파일 에러가 계속 발생함.
// 그래서 EcuM_GetResetReason() 이 함수의 헤더 파일을 인크루드하지 않고
// 비슷한 형으로 선언하고 extern으로 불러서 사용함.
//uint8_t resetReason;
static void ss_GetResetReason(void)// WPC_7E_05
{
	static uint8_t InitCheckFlag2 = OFF;
	// Std_ReturnType retValue;
	Mcu_ResetType resetReason;

	if(InitCheckFlag2 == OFF)
	{
		InitCheckFlag2 = ON;

		// 리셋 요인 read
		if (E_OK == EcuM_GetResetReason(&resetReason))
        {
			// dvp로 전송
			CAN_TX.Int.ResetReason = resetReason; // WPC_7E_05
        }
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_CAN_TX_L2H_Set(void)
{
	CAN_TX.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_CAN_TX_H2L_Set(void)
{



}


#define App_CAN_TX_STOP_SEC_CODE
#include "App_CAN_TX_MemMap.h"
