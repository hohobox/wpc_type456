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
#include "App_CAN_RX.h"
#include "Rte_App_CAN_RX.h"


#define App_CAN_RX_START_SEC_CODE
#include "App_CAN_RX_MemMap.h"

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
	uint8_t C_AutoBrightLevelOld;
} Inter_t;


typedef struct
{
	IDT_ADC_STR 		Inp_ADC;
	IDT_NvM_STR 		Inp_NvM;
	IDT_Mode_STR 		Inp_Mode;
	Inter_t 			Int;
	IDT_CAN_RX_STR 		Out;

} CAN_RX_struct;



/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/
static CAN_RX_struct CAN_RX = {0};

static MsgGr_E2E_LCAN_PDC_FD_15_300ms LCAN_PDC_FD_15_300ms_tmp = {0};

static MsgGr_E2E_BCAN_PDC_FD_15_300ms BCAN_PDC_FD_15_300ms_tmp = {0};

/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_CAN_RX_InitSet(void);
static void ss_CAN_RX_RteRead(void);
static void ss_CAN_RX_RteWrite(void);

static void ss_AutoBright_Judge(void);
static void ss_USMReset_Judge(void);
static void ss_WPC_OnOffNvalueSet_Judge(void);
static void ss_WPC2_OnOffNvalueSet_Judge(void);





/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_CAN_RX_CODE) CAN_RX_TE_Runnable(void)
{
	switch(CAN_RX.Int.Runnable_State)
	{
		case 0:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&CAN_RX.Int.App_Init_Completed);				/* SWP Init Complete Check */

			if( CAN_RX.Int.App_Init_Completed == ON )										/* SWP Init Complete? */
			{
				/* SWC Init Process */
				ss_CAN_RX_InitSet();

				CAN_RX.Int.Runnable_State = ON;							/*  Main Runnable Mode Move > App Run */

			}
		break;

		case 1:

			ss_CAN_RX_RteRead();

			ss_CAN_RX_RteWrite();

		break;

		default:
			CAN_RX.Int.Runnable_State = 0;
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static  void    ss_CAN_RX_InitSet(void)
{
	// BCAN Init Set
	memset(&CAN_RX.Out, 0, sizeof(CAN_RX.Out));  				// 구조체 변수를 0으로 클리어

	Rte_Read_R_NvM_NvM_STR(&CAN_RX.Inp_NvM);			// 한꺼번에 수신
	CAN_RX.Out.BCAN.m_AutoBrightSta = CAN_RX.Inp_NvM.m_AutoBrightSta;	// eeprom 불러옴.
	Rte_Write_P_CAN_RX_CAN_RX_STR(&CAN_RX.Out);	// 한꺼번에 전송 // 즉시 write 버퍼 값을 변경해줘야함. 그렇지 않으면 Nvm rte read에서 초기값 0을 읽은 후 m_AutoBrightSta eeprom값을 0으로 변경시켜 버린다.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void  ss_CAN_RX_RteRead(void)
{

	Rte_Read_R_ADC_ADC_STR(&CAN_RX.Inp_ADC);		// 한꺼번에 수신
	Rte_Read_R_Mode_Mode_STR(&CAN_RX.Inp_Mode);		// 한꺼번에 수신

	// BCAN Signal Read
	if ((CAN_RX.Inp_Mode.PduGroupRx_BCAN_PNC141 == RTE_MODE_MDG_PduGroup_START) ||	// BCAN WPC
	(CAN_RX.Inp_Mode.PduGroupRx_BCAN_PNC153 == RTE_MODE_MDG_PduGroup_START) ||		// BCAN B2-CAN
	(CAN_RX.Inp_Mode.PduGroupRx_BCAN_PNC32 == RTE_MODE_MDG_PduGroup_START))			// BCAN All ECUs
	{
		CAN_RX.Out.BCAN.C_BCM_SmkOptTyp = Rte_DRead_BCAN_BDC_FD_02_200ms_BCM_SmkOptTyp();
		CAN_RX.Out.BCAN.C_CF_AVN_ProfileIDRValue = Rte_DRead_BCAN_HU_GW_03_200ms_CF_AVN_ProfileIDRValue();

		CAN_RX.Out.BCAN.C_CLU_DtntOutSta = Rte_DRead_BCAN_CLU_01_20ms_CLU_DtntOutSta();

		// 엔진 구동 여부 판단을위한 CAN 신호 (3세대 CAN)
		CAN_RX.Out.BCAN.C_ENG_EngSta = Rte_DRead_BCAN_EMS_02_10ms_ENG_EngSta(); // 내연 // timeout value 0x7 --> old value로 변경하면서 이쪽으로 이동함. DRE, DREE 불필요해짐.
		CAN_RX.Out.BCAN.C_HCU_HevRdySta = Rte_DRead_BCAN_HCU_03_10ms_HCU_HevRdySta(); // 하이브리드
		CAN_RX.Out.BCAN.C_VCU_EvDrvRdySta = Rte_DRead_BCAN_VCU_01_10ms_VCU_EvDrvRdySta(); // 전기차				

		//CAN_RX.Out.BCAN.C_HEV_EngOpSta = Rte_DRead_BCAN_EMS_07_10ms_HEV_EngOpSta();  // 미사용이나 db에 있으므로 추가함.
		
		CAN_RX.Out.BCAN.C_VCU_GearPosSta = Rte_DRead_BCAN_VCU_01_10ms_VCU_GearPosSta(); /* 010E_12 */

		CAN_RX.Out.BCAN.C_IAU_ProfileIDRVal = Rte_DRead_BCAN_IAU_FD_04_200ms_IAU_ProfileIDRVal();
		CAN_RX.Out.BCAN.C_Lamp_IntTailLmpOnReq = Rte_DRead_BCAN_BDC_FD_05_200ms_Lamp_IntTailLmpOnReq();
		CAN_RX.Out.BCAN.C_LFAnt_SrchSta = Rte_DRead_BCAN_BDC_FD_SMK_02_200ms_LFAnt_SrchSta();

		CAN_RX.Out.BCAN.C_Warn_RrLftDrSwSta = Rte_DRead_BCAN_PDC_FD_03_200ms_Warn_RrLftDrSwSta();
		CAN_RX.Out.BCAN.C_Warn_AsstDrSwSta = Rte_DRead_BCAN_PDC_FD_03_200ms_Warn_AsstDrSwSta();
		CAN_RX.Out.BCAN.C_Warn_DrvDrSwSta = Rte_DRead_BCAN_PDC_FD_03_200ms_Warn_DrvDrSwSta();
		CAN_RX.Out.BCAN.C_Warn_RrRtDrSwSta = Rte_DRead_BCAN_PDC_FD_03_200ms_Warn_RrRtDrSwSta();

		CAN_RX.Out.BCAN.C_Warn_RrLftDrSwSta_SBCM = Rte_DRead_BCAN_SBCM_RL_FD_01_200ms_Warn_RrLftDrSwSta_SBCM();
		CAN_RX.Out.BCAN.C_Warn_AsstDrSwSta_SBCM = Rte_DRead_BCAN_SBCM_AST_FD_01_200ms_Warn_AsstDrSwSta_SBCM();
		CAN_RX.Out.BCAN.C_Warn_DrvDrSwSta_SBCM = Rte_DRead_BCAN_SBCM_DRV_FD_01_200ms_Warn_DrvDrSwSta_SBCM();
		CAN_RX.Out.BCAN.C_Warn_RrRtDrSwSta_SBCM = Rte_DRead_BCAN_SBCM_RR_FD_01_200ms_Warn_RrRtDrSwSta_SBCM();		
		CAN_RX.Out.BCAN.C_Latch_TypeOption_DRV = Rte_DRead_BCAN_SBCM_DRV_FD_01_200ms_Latch_TypeOption_DRV();		

		CAN_RX.Out.BCAN.C_CLU_ClusterUSM = Rte_DRead_BCAN_CLU_20_200ms_CLU_ClusterUSM();

		CAN_RX.Out.BCAN.C_CF_Gway_WPCAnimationNvalueSet = Rte_DRead_BCAN_HU_USM_05_00ms_CF_Gway_WPCAnimationNvalueSet(); // wpc에서만 수신하고 이 정보를 wpc가 can 통신으로 wpc2,rwpc에 전달한다.

		CAN_RX.Out.BCAN.C_RWPC_IndSyncVal = Rte_DRead_BCAN_RWPC_FD_01_200ms_RWPC_IndSyncVal();
		//CAN_RX.Out.BCAN.C_WPC2_IndSyncVal = Rte_DRead_BCAN_WPC2_FD_01_200ms_WPC2_IndSyncVal(); // tx와 rx id를 중복으로 사용해서 일단 WPC2를 노드에서 이 메세지를 제거하고 임포트함. 

		// Timeout Value가 있는 시그널 : 모빌젠 설정에서 Timeout Value 추가하는 방식으로 변경함. --> db 수정없이 그대로 진행함. 고객에서 문제 없다고 회신받음.
		CAN_RX.Out.BCAN.C_CLU_DisSpdVal_KPH = Rte_DRead_BCAN_CLU_01_20ms_CLU_DisSpdVal_KPH(); 	// Timeout Value : 255
		CAN_RX.Out.BCAN.C_RheoStatLevel = Rte_DRead_BCAN_CLU_01_20ms_CLU_RhstaLvlSta();			// Timeout Value : 10
		CAN_RX.Out.BCAN.C_HEV_EngOpSta = Rte_DRead_BCAN_EMS_07_10ms_HEV_EngOpSta();				// Timeout Value : 7
		// Timeout Value가 있는 시그널
		
		// dual db import
		//CAN_RX.Out.BCAN.C_CF_Gway_WPC2_NValueSet = Rte_DRead_BCAN_HU_USM_04_00ms_CF_Gway_WPC2_NValueSet();
		
		Rte_Read_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms(&BCAN_PDC_FD_15_300ms_tmp);
		CAN_RX.Out.BCAN.C_PDC_ResetPreWrngForOthers = BCAN_PDC_FD_15_300ms_tmp.PDC_ResetPreWrngForOthers;
		CAN_RX.Out.BCAN.C_PDC_ResetReqForOthers = BCAN_PDC_FD_15_300ms_tmp.PDC_ResetReqForOthers;		
		CAN_RX.Out.BCAN.C_PDC_ResetFuncOpt = BCAN_PDC_FD_15_300ms_tmp.PDC_ResetFuncOpt;		
		
		// dual db import
		
		ss_AutoBright_Judge();			// C_AutoBrightLevel 신호 생성함.

		ss_USMReset_Judge(); 			// C_USMReset 신호 생성함

		ss_WPC_OnOffNvalueSet_Judge();	// C_WPCOnOffNvalueSet 신호 생성함.
		ss_WPC2_OnOffNvalueSet_Judge();	// C_WPC2OnOffNvalueSet 신호 생성함.


		// CAN_RX.Out.BCAN.C_WPC2IndCmdState = 0; // db에 시그널이없음. 추가 필요함. Sync로 신호 생성.
		// CAN_RX.Out.BCAN.C_RWPCIndCmdState = 0; // db에 시그널이없음. 추가 필요함. Sync로 신호 생성.
		// CAN_RX.Out.BCAN.C_WPCIndUSMState = 0; // db에 시그널이없음. 추가 필요함. C_WPCIndUSMState는 WPC에서 생성하는 신호 이므로 본인이 다시 받을 수 없다. 모델 내에서 내부변수로 입력 받는다.
	}

	// LCAN Signal Read
	if ((CAN_RX.Inp_Mode.PduGroupRx_LCAN_PNC159 == RTE_MODE_MDG_PduGroup_START) ||	// LCAN BDC에 물려 있는 제어기 전체
	(CAN_RX.Inp_Mode.PduGroupRx_LCAN_PNC32 == RTE_MODE_MDG_PduGroup_START))		// LCAN All ECUs
	{
		CAN_RX.Out.LCAN.LC_WPC_IAUWPCNFCcmd = Rte_DRead_LCAN_L_BDC_FD_IAU_01_00ms_WPC_NFC_Deselect_Cmd();
		CAN_RX.Out.LCAN.LC_WPC2_IAUWPCNFCcmd = Rte_DRead_LCAN_L_BDC_FD_IAU_01_00ms_WPC2_NFC_Deselect_Cmd();
		CAN_RX.Out.LCAN.LC_IAU_Status = Rte_DRead_LCAN_L_BDC_FD_IAU_10_200ms_BDC_TP_CAN_Sta();
		CAN_RX.Out.LCAN.LC_DeviceOnWPC = Rte_DRead_LCAN_L_BDC_FD_IAU_10_200ms_WPC_Device_On_Cmd();
		CAN_RX.Out.LCAN.LC_OwnerKey_Reg_Status = Rte_DRead_LCAN_IAU_FD_04_200ms_IAU_OwnerPhnRegRVal();
		CAN_RX.Out.LCAN.LC_OwnerPairingAdvertisingReq = Rte_DRead_LCAN_L_BDC_FD_IAU_10_200ms_OPAdv_On_Cmd();
		CAN_RX.Out.LCAN.LC_CCU_ForcedPowerOffReq = Rte_DRead_LCAN_CCU_01_00ms_CCU_ForcedPowerOffReq();
		CAN_RX.Out.LCAN.LC_IAU_DKOwnerSwapOption = Rte_DRead_LCAN_IAU_FD_04_200ms_IAU_DKOwnerSwapOption();
		CAN_RX.Out.LCAN.LC_IAU_SharedPhnRegStat = Rte_DRead_LCAN_IAU_FD_05_200ms_IAU_SharedPhnRegStat();
		
		//Rte_Read_Gr_MsgGr_E2E_LCAN_PDC_FD_15_300ms_MsgGr_E2E_LCAN_PDC_FD_15_300ms(&LCAN_PDC_FD_15_300ms_tmp); /* 0106_03 */ // 미사용 신호로 처리함.
		CAN_RX.Out.LCAN.LC_PDC_ResetPreWrngForOthers = LCAN_PDC_FD_15_300ms_tmp.PDC_ResetPreWrngForOthers;
		CAN_RX.Out.LCAN.LC_PDC_ResetReqForOthers = LCAN_PDC_FD_15_300ms_tmp.PDC_ResetReqForOthers;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void  ss_AutoBright_Judge(void)
{

	// IND_CONT_TYPE1 or IND_CONT_TYPE2는 모델에서 C_RheoStatLevel 이 신호를 사용하고
	// IND_CONT_TYPE3는 모델에서 C_CLU_AutoBrightSta 이 신호를 사용한다.

	// C_RheoStatLevel 이 신호는 타임아웃 Value가 있어서 DRE_CLU_01_20ms_1_Runnable()에서 수신된다.
	// C_CLU_AutoBrightSta 이 신호는 Eeeprom에 저장되 있는 값을 사용할지 can 값을 사용하지 판단이 필요해서 아래 로직을 통해서 판단한다.


	// 통신 안되는것을 어떻게 판단할까?
	// 사양상 C_CLU_AutoBrightSta 값에서 0은 미사용 값이다.
	// 즉 C_CLU_AutoBrightSta 값이 0이라는 것은 can로 부터 수신이 안되었다는 뜻이다.
	// 그러므로 C_CLU_AutoBrightSta 값이 초기값 0이면 이때는 eeprom에 저장된 값으로 출력한다.
	// C_CLU_AutoBrightSta 값이 0이 아닌 값이 되면 can 수신이 되었다는 뜻이므로
	// 이때는 can rx 수신 값으로 출력한다.

	Rte_Read_R_NvM_NvM_STR(&CAN_RX.Inp_NvM);		// 한꺼번에 수신

	CAN_RX.Out.BCAN.C_CLU_AutoBrightSta = Rte_DRead_BCAN_CLU_01_20ms_CLU_AutoBrightSta();

	if(CAN_RX.Out.BCAN.C_CLU_AutoBrightSta != 0u)	// step 0단계가 아닐때
	{
		CAN_RX.Out.BCAN.C_AutoBrightLevel = CAN_RX.Out.BCAN.C_CLU_AutoBrightSta;
	}
	else							// step 0단계 일때 (can 미수신으로 판단처리)
	{
		CAN_RX.Out.BCAN.C_AutoBrightLevel = CAN_RX.Inp_NvM.m_AutoBrightSta;
	}


	if((CAN_RX.Int.C_AutoBrightLevelOld != CAN_RX.Out.BCAN.C_CLU_AutoBrightSta) &&
	(CAN_RX.Out.BCAN.C_CLU_AutoBrightSta != 0u) &&	// WPC_418_02 // WPC_408_04 // step 0단계는 미사용이므로 수신시 제외 처리함. 즉 old value 적용함.
	(CAN_RX.Inp_ADC.BatCanStateFault == OFF))
	{
		CAN_RX.Out.BCAN.m_AutoBrightSta = CAN_RX.Out.BCAN.C_CLU_AutoBrightSta; // eeprom 변경용. nvm에서 사용함
	}

	CAN_RX.Int.C_AutoBrightLevelOld = CAN_RX.Out.BCAN.C_CLU_AutoBrightSta;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void  ss_USMReset_Judge(void)
{

	// 아래 2개 신호를 판단하여 USMReset 신호를 생성함.
	CAN_RX.Out.BCAN.C_CF_AVN_CluUSMReset = Rte_DRead_BCAN_HU_USM_02_00ms_CF_AVN_CluUSMReset();
	CAN_RX.Out.BCAN.C_USM_StaRst1Req = Rte_DRead_BCAN_CLU_05_00ms_USM_StaRst1Req();	// WPC 기능 USM RESET 설정시 사용

	// USM Reset 기능 (USM 설정 초기화), WPC, WPC2, RWCP 공통임.
	if((CAN_RX.Out.BCAN.C_USM_StaRst1Req == 0x01u) ||
	   (CAN_RX.Out.BCAN.C_USM_StaRst1Req == 0x02u) ||
	   (CAN_RX.Out.BCAN.C_USM_StaRst1Req == 0x03u))
	{
		if(CAN_RX.Out.BCAN.C_USM_StaRst1Req == 0x01u)
		{
			CAN_RX.Out.BCAN.C_USMReset = CAN_RX.Out.BCAN.C_USM_StaRst1Req;
		}
	}
	else if((CAN_RX.Out.BCAN.C_CF_AVN_CluUSMReset == 0x01u) ||
			(CAN_RX.Out.BCAN.C_CF_AVN_CluUSMReset == 0x02u) ||
			(CAN_RX.Out.BCAN.C_CF_AVN_CluUSMReset == 0x03u))
	{
		if(CAN_RX.Out.BCAN.C_CF_AVN_CluUSMReset == 0x01u)
		{
			CAN_RX.Out.BCAN.C_USMReset = CAN_RX.Out.BCAN.C_CF_AVN_CluUSMReset;
		}
	}
	else // WPC_412_04
	{
		CAN_RX.Out.BCAN.C_USMReset = 0x00u;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void  ss_WPC_OnOffNvalueSet_Judge(void)
{

	// 아래 2개 신호를 판단하여 C_WPCOnOffNvalueSet 신호를 생성함.
	CAN_RX.Out.BCAN.C_USM_WpcSetReq = Rte_DRead_BCAN_CLU_09_00ms_USM_WpcSetReq(); // WPC 충전 기능 On/Off USM 설정시 사용
	CAN_RX.Out.BCAN.C_CF_Gway_WPCNValueSet = Rte_DRead_BCAN_HU_USM_01_00ms_CF_Gway_WPCNValueSet();

	if((CAN_RX.Out.BCAN.C_USM_WpcSetReq == 0x01u) ||
	   (CAN_RX.Out.BCAN.C_USM_WpcSetReq == 0x02u) ||
	   (CAN_RX.Out.BCAN.C_USM_WpcSetReq == 0x03u))
	{
		CAN_RX.Out.BCAN.C_WPCOnOffNvalueSet = CAN_RX.Out.BCAN.C_USM_WpcSetReq;
	}
	else if((CAN_RX.Out.BCAN.C_CF_Gway_WPCNValueSet == 0x01u) ||
			(CAN_RX.Out.BCAN.C_CF_Gway_WPCNValueSet == 0x02u) ||
			(CAN_RX.Out.BCAN.C_CF_Gway_WPCNValueSet == 0x03u))
	{
		CAN_RX.Out.BCAN.C_WPCOnOffNvalueSet = CAN_RX.Out.BCAN.C_CF_Gway_WPCNValueSet;
	}
	else
	{
		CAN_RX.Out.BCAN.C_WPCOnOffNvalueSet = 0x00u;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void  ss_WPC2_OnOffNvalueSet_Judge(void)
{

	// 아래 2개 신호를 판단하여 C_WPCOnOffNvalueSet 신호를 생성함.
	// rx 시그널에 USM_Wpc2SetReq가 없다. DB 파일에 nidec에서 강제로 추가항 개발함.
	// CAN_RX.Out.BCAN.C_USM_Wpc2SetReq = Rte_DRead_BCAN_CLU_09_00ms_USM_Wpc2SetReq(); /* 010E_12 */ // 1.0 db에서 시그널 삭제됨. C_CF_Gway_WPC2_NValueSet 이 시그널만 사용되는것으로 변경함.// WPC2 충전 기능 On/Off USM 설정시 사용	
	CAN_RX.Out.BCAN.C_CF_Gway_WPC2_NValueSet = Rte_DRead_BCAN_HU_USM_04_00ms_CF_Gway_WPC2_NValueSet();

	// if((CAN_RX.Out.BCAN.C_USM_Wpc2SetReq == 0x01u) ||
	//    (CAN_RX.Out.BCAN.C_USM_Wpc2SetReq == 0x02u) ||
	//    (CAN_RX.Out.BCAN.C_USM_Wpc2SetReq == 0x03u))
	// {
	// 	CAN_RX.Out.BCAN.C_WPC2OnOffNvalueSet = CAN_RX.Out.BCAN.C_USM_Wpc2SetReq;
	// }
	// else 
/* 010E_12 */	
	if((CAN_RX.Out.BCAN.C_CF_Gway_WPC2_NValueSet == 0x01u) ||
			(CAN_RX.Out.BCAN.C_CF_Gway_WPC2_NValueSet == 0x02u) ||
			(CAN_RX.Out.BCAN.C_CF_Gway_WPC2_NValueSet == 0x03u))
	{
		CAN_RX.Out.BCAN.C_WPC2OnOffNvalueSet = CAN_RX.Out.BCAN.C_CF_Gway_WPC2_NValueSet;
	}
	else
	{
		CAN_RX.Out.BCAN.C_WPC2OnOffNvalueSet = 0x00u;
	}
/* 010E_12 */	
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_CAN_RX_RteWrite(void)
{
	// 타 SWC에 RTE로 전달
	Rte_Write_P_CAN_RX_CAN_RX_STR(&CAN_RX.Out);	// 구조체로 한꺼번에 전송
}


// 타임아웃 지정된 시그널은 아래처럼 별도 처리해서 timeout 발생시와 정상시를 구분해서 read처리 해야 한다.
// --> 아래 방식으로 변경함.
// Runnable은 생성되어 Callback으로 호출되도록 모빌젠 설정했으나
// 실제로 timeout value는 모빌젠 설정에 의해서 자동으로 설정되도록 변경함.
// 그래서 아래 DREE 함수는 호출할 필요 없게 되었음.(DRE 함수는 필요 없어서 삭제함.)
// 그러나 모빌젠에서 설정하는 기능을 사용하기 위해서는 DREE notification을 생성해야 하기 때문에
// DREE Runnable 함수는 존재해야 하므로 빈 함수로 생성함.

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
FUNC(void, App_CAN_RX_CODE) DREE_RhstaLvlSta_Runnable(void)
{
	//CAN_RX.Out.BCAN.C_RheoStatLevel = 0x0A;  // CAN Timeout Value Set
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
FUNC(void, App_CAN_RX_CODE) DREE_DisSpdVal_KPH_Runnable(void)
{
	//CAN_RX.Out.BCAN.C_CLU_DisSpdVal_KPH = 0xFF;// GN7.1F_01 // CAN Timeout Value Set
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
FUNC(void, App_CAN_RX_CODE) DREE_HEV_EngOpSta_Runnable(void)
{
	//CAN_RX.Out.BCAN.C_HEV_EngOpSta = 0x07;// GN7.1F_03 // CAN Timeout Value Set
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
FUNC(void, App_CAN_RX_CODE) DRE_PDC_FD_15_300ms_Runnable(void)
{
	CAN_RX.Out.BCAN.PDC_15_300_RevComplete = ON;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_CAN_RX_L2H_Set(void)
{
	CAN_RX.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_CAN_RX_H2L_Set(void)
{

}


#define App_CAN_RX_STOP_SEC_CODE
#include "App_CAN_RX_MemMap.h"
