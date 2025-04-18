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
#include "App_NvM.h"
#include "Rte_App_NvM.h"

#include "App_WCT.h"

#include "NvM.h"


#define App_NvM_START_SEC_CODE
#include "App_NvM_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/


/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/



typedef struct
{
	uint8_t Runnable_State;
	uint8_t BswInitFlag;
	uint8_t NvMInitFlag;

	uint8_t	NvMBlk_1B_Data_IN[BLK_NO_1BYTE_MAX];	// 1byte 를 for문 사용하기 위해서 배열로 변경
	uint8_t	NvMBlk_1B_BlockNo[BLK_NO_1BYTE_MAX];
	
	//uint8_t NvMBlk_1B_Complete[BLK_NO_1BYTE_MAX];
	uint8_t NvMBlk_1B_Status[BLK_NO_1BYTE_MAX];
	uint8_t NvMBlk_1B_RetValue[BLK_NO_1BYTE_MAX];
	uint16_t NvMBlk_1B_Pending_Cnt[BLK_NO_1BYTE_MAX];
	uint16_t NvMBlk_1B_WriteErrCnt[BLK_NO_1BYTE_MAX];
	uint16_t NvMBlk_1B_NotOk_Cnt[BLK_NO_1BYTE_MAX];	
	
	uint8_t	NvMBlk_Array_BlockNo[BLK_NO_ARRAY_MAX];
	uint8_t NvMBlk_Array_Status[BLK_NO_ARRAY_MAX];	
	uint8_t NvMBlk_Array_RetValue[BLK_NO_ARRAY_MAX];
	uint16_t NvMBlk_Array_Pending_Cnt[BLK_NO_ARRAY_MAX];
	uint16_t NvMBlk_Array_WriteErrCnt[BLK_NO_ARRAY_MAX];
	uint16_t NvMBlk_Array_NotOk_Cnt[BLK_NO_ARRAY_MAX];
		
	uint8_t NvMBlk_1B_Data_Ram[BLK_NO_1BYTE_MAX];
	
	uint8_t NvMBlk_ECU_Info_Ram[ECU_INFO_SIZE];	
	uint8_t NvMBlk_SerialNum_Ram[SERIAL_NUM_SIZE];	
	uint8_t NvMBlk_QRCode_Ram[QRCODE_SIZE];	

} Inter_t;


typedef struct
{
	IDT_Model_STR	Inp_Model;
	IDT_CAN_RX_STR	Inp_CAN_RX;
	IDT_WDT_STR		Inp_WDT;
	IDT_Log_STR 	Inp_Log;
	IDT_NFC_STR 	Inp_NFC;
	IDT_Uds_STR   	Inp_Uds;
	IDT_Repro_STR   Inp_Repro;

	Inter_t 		Int;
	IDT_NvM_STR 	Out;

} NvM_struct;

/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/
static NvM_struct NvM = {0};



/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_NvM_InitSet(void);
static void ss_NvM_PowerOnRteWrite(void);
static void ss_NvM_WriteBlock_1B(void);
static void ss_NvM_WriteBlock_Array(void);

static void ss_NvM_RteRead(void);
static void ss_NvM_RteWrite(void);
static void ss_NvM_WpcTypeJudge(void);
static void ss_NvM_1BDataRteSet(void);
static void ss_NvM_ArrayDataRteSet(void);

/***************************************************************************************************
    GLOBAL VARIABLES
***************************************************************************************************/

// NvM  저장 초기값을 모빌젠에서 설정한는것으로 변경함.
// 모빌젠에서 배열로 설정시 에러 발생해서 일반 변수로 설정함
// WPC_486_02
const uint8_t NvMBlk_1B_Init_0 = 2u; // ProfileGuestWPCUSM
const uint8_t NvMBlk_1B_Init_1 = 2u; // ProfileOneWPCUSM
const uint8_t NvMBlk_1B_Init_2 = 2u; // ProfileTwoWPCUSM
const uint8_t NvMBlk_1B_Init_3 = 13u;// AutoBrightSta
const uint8_t NvMBlk_1B_Init_4 = 2u; // ProfileGuestWPCAnimation
const uint8_t NvMBlk_1B_Init_5 = 2u; // ProfileOneWPCAnimation
const uint8_t NvMBlk_1B_Init_6 = 2u; // ProfileTwoWPCAnimation

const uint8_t NvMBlk_1B_Init_7 = 0u; // PDCReset
const uint8_t NvMBlk_1B_Init_8 = 0u; // ATN_Calibration
const uint8_t NvMBlk_1B_Init_9 = 0u; // B0BADisableCnt

// #if defined (WCT_REPROGRAM_OFF) /* 010A_02 */ 컨셉 변경으로 초기값은 0으로 변경함
const uint8_t NvMBlk_1B_Init_10 = 0u; // WctReproRequest  /* 0108_13 */
// #else
// const uint8_t NvMBlk_1B_Init_10 = 1u; // WctReproRequest  /* 0108_13 */
// #endif

// 예비로 미리 할당해둠
const uint8_t NvMBlk_1B_Init_11 = 0u; // Flag2
const uint8_t NvMBlk_1B_Init_12 = 0u; // Flag3
const uint8_t NvMBlk_1B_Init_13 = 0u; // Flag4
const uint8_t NvMBlk_1B_Init_14 = 0u; // Flag5
const uint8_t NvMBlk_1B_Init_15 = 0u; // Flag6

// default 값을 사용하여 라인에서 라이팅 안했을 경우를 판단 가능하도록 함.
// 중복되지 않는 유니크한 값으로 설정함.
const uint8_t NvMBlkInitSting_ECUINFO[ECU_INFO_SIZE]   = {'P','A','R','T','N','U','M','B','E','R',0x20u,0x00u,0x01u,0x01,'0','0','0'};
const uint8_t NvMBlkInitSting_SERNUMB[SERIAL_NUM_SIZE] = {'S','E','R','I','A','L','N','U','M','B','E','R','1','2','3'};
const uint8_t NvMBlkInitSting_QRCODE[QRCODE_SIZE]      = {'Q','R','C','O','D','E','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15'};
//const uint8_t NvMBlkInitSting_WCTVER[WCT_VER_SIZE]   = {'0', '0', '0'}; 

const uint8_t NvMBlkInitSting_Array1[NVM_USER_RESERVED]   = {'R','E','S','E','R','V','E','D'};
const uint8_t NvMBlkInitSting_Array2[NVM_USER_RESERVED]   = {'R','E','S','E','R','V','E','D'};
const uint8_t NvMBlkInitSting_Array3[NVM_USER_RESERVED]   = {'R','E','S','E','R','V','E','D'};

// WPC_486_02

// 모빌젠에서 설정한 NvM 글로벌 블럭 변수
uint8_t NvMBlk_1B_Data[BLK_NO_1BYTE_MAX] = {0}; 	// NvM Block Data (Eeprom Data)
uint8_t NvMBlk_ECU_Info[ECU_INFO_SIZE] = {0};
uint8_t NvMBlk_SerialNum[SERIAL_NUM_SIZE] = {0};
uint8_t NvMBlk_QRCode[QRCODE_SIZE] = {0};


// 예비로 미리 할당해둠
uint8_t NvMBlk_Array1[NVM_USER_RESERVED] = {0};	
uint8_t NvMBlk_Array2[NVM_USER_RESERVED] = {0};	
uint8_t NvMBlk_Array3[NVM_USER_RESERVED] = {0};	

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/
uint8_t gs_Get_NvM_WpcType(void) {return NvM.Out.WPC_TYPE;}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_NvM_CODE) NvM_TE_Runnable(void)
{
	switch(NvM.Int.Runnable_State)
	{
		case 0u:

			Rte_Call_R_CS_Mode_ModeInit(&NvM.Int.BswInitFlag);

			if((NvM.Int.BswInitFlag == ON) && // swp 에 의해서 자동으로 NvMBlk_1B_Data[]에 eeprom data가 read되고 BswInitFlag = on이면 NvMBlk_1B_Data[]가 모두 읽어진 상태를 뜻함
			   (NvM.Int.NvMInitFlag == OFF))
			{
				ss_NvM_InitSet();

				if(NvM.Int.NvMInitFlag == ON) // NvMBlk_1B_Data[]가 NvM.Int.NvMBlk_1B_Data_Ram[]에 복사가 완료 되면 그 이후 rte를 통해서 app에 eeprom값을 제공한다.
				{
					ss_NvM_PowerOnRteWrite();
					Rte_Call_R_CS_Mode_NvMInit(NvM.Int.NvMInitFlag); // 타모듈에 runnable로 진입 가능하도록 rte call로 notify함
					NvM.Int.Runnable_State = 1u;
				}
			}

		break;

		// 현재 문제는 WPC 는 App에서 전달한 USM eeprom 정보를 판단해서 다시 NvM 모듈에 전달하기까지 40ms 이상 걸리는듯.
		// 그래서 NvM에서는 이전 값과 nvm에 차이가 발생하면 저장하는 방식인데
		// 아직 판단하지 않은 default값을 수신해서 기존에 저장된 eeprom 값과 차이가있는것으로 판단해서
		// default값인 Nvm값을 0으로 eeprom을 변경해 버림. 그래서 지금 문제가 되고

		// 아래처럼 eeprom의 차이가 있는지 확인하는 로직을 50ms 딜레이는 주었더니 모든 문제 해결됨.
		// 즉 50ms 경과하면 모델에서 판단된 usm 정보가 전달 되므로 이 값으로 eeprom 저장 여부를 결정하므로 문제가 안되는것 같음.

		// 하지만 정식으로는 모델에서 전원 인가 후 10ms task 이내에 app에서 전달한 값으로 usm 판단해서
		// 판단한 값을 app의 nvm에 전달해야만 정식으로 판단된 값이 eeprom에 저장될수 있음.
		case 1u:

				ss_NvM_RteRead();

			 	ss_NvM_WriteBlock_1B();		// 1byte NvM 저장
				
				ss_NvM_WriteBlock_Array();	// 배열 NvM 저장
				
				ss_NvM_WpcTypeJudge();	// 동작 중 품번 변경시 WPC Type 갱신 필요
				
				ss_NvM_RteWrite();

		break;

		default:
			NvM.Int.Runnable_State = 0u;
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_NvM_InitSet(void)
{
	uint8_t retValue = E_OK;
	NvM_RequestResultType bNvMBlockStatus = NVM_REQ_OK;
	uint8_t bId;
	
	// 1byte 저장 블럭 넘버 설정
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ProfileGuestWPCUSM_0] = Rte_PDAV_NvMPS_NvMBlock_ProfileGuestWPCUSM_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ProfileOneWPCUSM_0] = Rte_PDAV_NvMPS_NvMBlock_ProfileOneWPCUSM_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ProfileTwoWPCUSM_0] = Rte_PDAV_NvMPS_NvMBlock_ProfileTwoWPCUSM_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_AutoBrightSta] = Rte_PDAV_NvMPS_NvMBlock_AutoBrightSta_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ProfileGuestWPCUSM_1] = Rte_PDAV_NvMPS_NvMBlock_ProfileGuestWPCAnimation_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ProfileOneWPCUSM_1] = Rte_PDAV_NvMPS_NvMBlock_ProfileOneWPCAnimation_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ProfileTwoWPCUSM_1] = Rte_PDAV_NvMPS_NvMBlock_ProfileTwoWPCAnimation_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_PDCReset] = Rte_PDAV_NvMPS_NvMBlock_PDCReset_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_ANT_Calibration] = Rte_PDAV_NvMPS_NvMBlock_ANT_Calibration_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_B0BADisableCnt] = Rte_PDAV_NvMPS_NvMBlock_B0BADisableCnt_1;
	NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_WctReproRequest] = Rte_PDAV_NvMPS_NvMBlock_WctReproRequest_1; /* 0108_13 */	
	// NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_Flag2] = Rte_PDAV_NvMPS_NvMBlock_Flag2_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_Flag3] = Rte_PDAV_NvMPS_NvMBlock_Flag3_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_Flag4] = Rte_PDAV_NvMPS_NvMBlock_Flag4_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_Flag5] = Rte_PDAV_NvMPS_NvMBlock_Flag5_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_BlockNo[BLK_NO_1B_Flag6] = Rte_PDAV_NvMPS_NvMBlock_Flag6_1; // 예비로 생성해 둠.

	// array 배열 저장 블럭 넘버 설정
	NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_ECU_Info] = Rte_PDAV_NvMPS_NvMBlock_ECU_Info_1; // 예비로 생성해 둠.
	NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_SerialNum] = Rte_PDAV_NvMPS_NvMBlock_SerialNum_1; // 예비로 생성해 둠.
	NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_QRCode] = Rte_PDAV_NvMPS_NvMBlock_QRCode_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_WctSourceVer] = Rte_PDAV_NvMPS_NvMBlock_WCT_SwVer_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_Var1] = Rte_PDAV_NvMPS_NvMBlock_Array1_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_Var2] = Rte_PDAV_NvMPS_NvMBlock_Array2_1; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_Array_BlockNo[BLK_NO_ARR_Var3] = Rte_PDAV_NvMPS_NvMBlock_Array3_1; // 예비로 생성해 둠.

	// 1byte 저장 블럭
	for (bId = 0; bId < (uint8_t)BLK_NO_1BYTE_MAX; bId++)
	{			
		retValue = NvM_GetErrorStatus((NvM.Int.NvMBlk_1B_BlockNo[bId]), &bNvMBlockStatus);

		if (retValue == E_OK)
		{
			if ((bNvMBlockStatus == NVM_REQ_OK) ||
			(bNvMBlockStatus == NVM_REQ_RESTORED_FROM_ROM)) // WPC_486_02 // 모빌젠 설정에 의해서 초기값 설정된 직후에 read시에 리턴되는 값임. 값 변경 후에는 리턴 안됨
			{
				NvM.Out.NvMBlk_1B_Complete[bId] = ON;
				NvM.Int.NvMBlk_1B_Data_Ram[bId] = NvMBlk_1B_Data[bId]; /* NvM Block (EEPROM) -> Application Copy */
			}
			else /* Error Condition */
			{
// WPC_486_02			
// note : 1만회 제어기 전원 리셋 테스트시에 에러처리되어 eeprom이 재 설정되버리는 버그 발생함.
//        그래서 코드 상에서 강제로 초기값 설정하는 로직 삭제 처리함.
//        대신에 모빌젠 설정에서 초기값 1회 설정하는것으로 변경함.
				// //virgin_flag = ON;
				// NvM.Int.NvMBlk_1B_Complete[bId] = OFF;
				// NvMBlk_1B_Data[bId] = NvMBlk1BInitVal[bId];
				// NvM.Int.NvMBlk_1B_Data_Ram[bId] = NvMBlk1BInitVal[bId];	 //Init RAM IMAGE, Local Buf. 
				// retValue = NvM_WriteBlock((bId + Nvm1BIdOffset), &NvMBlk_1B_Data[bId]); // EEPROM INIT
// WPC_486_02			
			}
		}
	}
	
	// array 저장 블럭
	for (bId = 0; bId < (uint8_t)BLK_NO_ARRAY_MAX; bId++)
	{
		retValue = NvM_GetErrorStatus((NvM.Int.NvMBlk_Array_BlockNo[bId]), &bNvMBlockStatus);

		if (retValue == E_OK)
		{
			if ((bNvMBlockStatus == NVM_REQ_OK) ||
			(bNvMBlockStatus == NVM_REQ_RESTORED_FROM_ROM)) // 모빌젠 설정에 의해서 초기값 설정된 직후에 read시에 리턴되는 값임. 값 변경 후에는 리턴 안됨
			{
				NvM.Out.NvMBlk_Array_Complete[bId] = ON;
				
				switch(bId)	
				{
					case BLK_NO_ARR_ECU_Info:
						memcpy(NvM.Int.NvMBlk_ECU_Info_Ram, NvMBlk_ECU_Info, ECU_INFO_SIZE);					
					break;
					
					case BLK_NO_ARR_SerialNum:	
						memcpy(NvM.Int.NvMBlk_SerialNum_Ram, NvMBlk_SerialNum, SERIAL_NUM_SIZE);				
					break;
					
					case BLK_NO_ARR_QRCode:
						memcpy(NvM.Int.NvMBlk_QRCode_Ram, NvMBlk_QRCode, QRCODE_SIZE);						
					break;
					
					default:
						// QAC
					break;															
				}							
			}
			else /* Error Condition */
			{
				// 만약 리턴값 에러로 인해서 Buf에 초기값이 저장되지 않았다면 주기 task에서 buf와 NvM 이미지 값이 달라서 Buf(0) 값으로 NvM이미지가 0으로 초기화 될것이다.
			}
		}
	}	

	NvM.Int.NvMInitFlag = ON; /* NvM 초기화 완료 */

}



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_NvM_RteRead(void)
{
	Rte_Read_R_Model_Model_STR(&NvM.Inp_Model);			// 한꺼번에 수신
	Rte_Read_R_CAN_RX_CAN_RX_STR(&NvM.Inp_CAN_RX);		// 한꺼번에 수신
	Rte_Read_R_WDT_WDT_STR(&NvM.Inp_WDT);				// 한꺼번에 수신
	Rte_Read_R_NFC_NFC_STR(&NvM.Inp_NFC);				// 한꺼번에 수신
	Rte_Read_R_Uds_Uds_STR(&NvM.Inp_Uds);       		// 한꺼번에 수신
	Rte_Read_R_Repro_Repro_STR(&NvM.Inp_Repro);       	// 한꺼번에 수신
}

/***************************************************************************************************
 @param[in]  void
 @return     void
 @note		1byte m변수를 저장하기 쉽게 배열로 NvM에 저장하고 실제 사용할때는 다시 1byte로 치환하여 사용한다.
***************************************************************************************************/
static void ss_NvM_1BDataRteSet(void)
{
	// NvM Pending 완료된 후에 변경된 값을 전송 해야햠.
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ProfileGuestWPCUSM_0] == ON)
	{
		NvM.Out.Device[0].m_ProfileGuestWPCUSM = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ProfileGuestWPCUSM_0];		
	}

	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ProfileOneWPCUSM_0] == ON)
	{
		NvM.Out.Device[0].m_ProfileOneWPCUSM = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ProfileOneWPCUSM_0];		
	}	

	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ProfileTwoWPCUSM_0] == ON)
	{
		NvM.Out.Device[0].m_ProfileTwoWPCUSM = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ProfileTwoWPCUSM_0];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_AutoBrightSta] == ON)
	{
		NvM.Out.m_AutoBrightSta = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_AutoBrightSta];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ProfileGuestWPCUSM_1] == ON)
	{
		NvM.Out.Device[1].m_ProfileGuestWPCUSM = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ProfileGuestWPCUSM_1];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ProfileOneWPCUSM_1] == ON)
	{
		NvM.Out.Device[1].m_ProfileOneWPCUSM = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ProfileOneWPCUSM_1];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ProfileTwoWPCUSM_1] == ON)
	{
		NvM.Out.Device[1].m_ProfileTwoWPCUSM = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ProfileTwoWPCUSM_1];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_PDCReset] == ON)
	{
		NvM.Out.m_PDCReset = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_PDCReset];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_ANT_Calibration] == ON)
	{
		NvM.Out.m_ANT_Calibration = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_ANT_Calibration];		
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_B0BADisableCnt] == ON)
	{
		NvM.Out.m_B0BADisableCnt = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_B0BADisableCnt];			
	}
	
	if(NvM.Out.NvMBlk_1B_Complete[BLK_NO_1B_WctReproRequest] == ON)
	{
		NvM.Out.m_WctReproRequest = NvM.Int.NvMBlk_1B_Data_Ram[BLK_NO_1B_WctReproRequest];/* 0108_13 */		
	}
		
	// NvM.Out.m_Flag2 = NvMBlk_1B_Data[BLK_NO_1B_Flag2]; // 예비로 생성해 둠.
	// NvM.Out.m_Flag3 = NvMBlk_1B_Data[BLK_NO_1B_Flag3]; // 예비로 생성해 둠.
	// NvM.Out.m_Flag4 = NvMBlk_1B_Data[BLK_NO_1B_Flag4]; // 예비로 생성해 둠.
	// NvM.Out.m_Flag5 = NvMBlk_1B_Data[BLK_NO_1B_Flag5]; // 예비로 생성해 둠.
	// NvM.Out.m_Flag6 = NvMBlk_1B_Data[BLK_NO_1B_Flag6]; // 예비로 생성해 둠.	
}
/***************************************************************************************************
 @param[in]  void
 @return     void
 @note
***************************************************************************************************/
static void ss_NvM_ArrayDataRteSet(void)
{	
	// NvM Pending 완료된 후에 변경된 값을 전송 해야햠.
	if(NvM.Out.NvMBlk_Array_Complete[BLK_NO_ARR_ECU_Info] == ON) // Write Complete	
	{
		memcpy( NvM.Out.m_ECU_Info, NvM.Int.NvMBlk_ECU_Info_Ram, ECU_INFO_SIZE);
	}
	
	if(NvM.Out.NvMBlk_Array_Complete[BLK_NO_ARR_SerialNum] == ON) // Write Complete	
	{
		memcpy(NvM.Out.m_SerialNum, NvM.Int.NvMBlk_SerialNum_Ram, SERIAL_NUM_SIZE);
	}
	
	if(NvM.Out.NvMBlk_Array_Complete[BLK_NO_ARR_QRCode] == ON) // Write Complete	
	{
		memcpy(NvM.Out.m_QRCode, NvM.Int.NvMBlk_QRCode_Ram, QRCODE_SIZE);
	}	
}

/***************************************************************************************************
 @param[in]  void
 @return     void
 @note
***************************************************************************************************/
static void ss_NvM_RteWrite(void)
{	
	ss_NvM_1BDataRteSet(); // NvM Pending 및 배열을 바이트로 변환

	ss_NvM_ArrayDataRteSet();
	
	Rte_Write_P_NvM_NvM_STR(&NvM.Out);	// 구조체로 한꺼번에 전송
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static  void    ss_NvM_PowerOnRteWrite(void)
{
	// NvM으로 부터 전원 인가시 최초로 Read 함
	// 1바이트 m변수 배열에서 1바이트로 치환을 여기서 다시 한다
	ss_NvM_1BDataRteSet();
	
	// 배열 NvM 은 그대로 사용하면 되므로 아래 처리는 불필요하다.
	
	// 여기는 안해도 되지 않을까? 이미 ss_NvM_InitSet()에서 저장됨. 여기서 중복인듯.
	// memcpy(NvM.Int.NvMBlk_ECU_Info_Ram, NvMBlk_ECU_Info, ECU_INFO_SIZE);
	// memcpy(NvM.Int.NvMBlk_SerialNum_Ram, NvMBlk_SerialNum, SERIAL_NUM_SIZE);
	// memcpy(NvM.Int.NvMBlk_QRCode_Ram, NvMBlk_QRCode, QRCODE_SIZE);
	// memcpy(NvM.Int.NvMBlk_WctSourceVer_Ram, NvMBlk_WCT_SwVer, WCT_VER_SIZE);	
	// memcpy(NvM.Inp_Uds.m_Array1, NvM.Int.NvMBlk_Array1, NVM_USER_RESERVED);	// 예비로 생성해 둠.
	// memcpy(NvM.Inp_Uds.m_Array2, NvM.Int.NvMBlk_Array2, NVM_USER_RESERVED);	// 예비로 생성해 둠.
	// memcpy(NvM.Inp_Uds.m_Array3, NvM.Int.NvMBlk_Array3, NVM_USER_RESERVED);	// 예비로 생성해 둠.


	// 고정 파라미터이고 모델에서 즉시 사용 가능하도록 eeprom 전송 타이밍과 같은 타이밍에 즉시 전송하도록 변경함.

	// define 이중으로 하는것 없애기 위해서 로직 변경
	// NvM.Out.INDContType = IND_CONT_TYPE;
    #if defined (IND_CONT_TYPE1)
		NvM.Out.INDContType = 0u; // withDetent : Rheostat Bright Level 21단계
    #elif defined (IND_CONT_TYPE2)
		NvM.Out.INDContType = 1u; // withoutDetent : Rheostat Bright Level 21단계
    #elif defined (IND_CONT_TYPE3)
		NvM.Out.INDContType = 2u; // withAutoBright : AutoBright Level 200단계
    #else
        Error : not defined
    #endif

	// NvM.Out.IndUSMOption = b_IndUSMOption;
    #if defined (b_IndUSMOption_ON)
		NvM.Out.IndUSMOption = 1u;
    #elif defined (b_IndUSMOption_OFF)
		NvM.Out.IndUSMOption = 0u;
    #else
        Error : not defined
    #endif

	// NvM.Out.RheostatOption = Var_RheostatOption;
    #if defined (Var_RheostatOption_ON)
		NvM.Out.RheostatOption = 1u;
    #elif defined (Var_RheostatOption_OFF)
		NvM.Out.RheostatOption = 0u;
    #else
        Error : not defined
    #endif

	// NvM.Out.LedDutyTableOption = LED_DUTY_TABLE;
    #if defined (LED_DUTY_TABLE_0)
		NvM.Out.LedDutyTableOption = 0u;
    #elif defined (LED_DUTY_TABLE_1)
		NvM.Out.LedDutyTableOption = 1u;
    #else
        Error : not defined
    #endif

	ss_NvM_WpcTypeJudge(); // 품번에 의해서 WPC Type 판정

	ss_NvM_ArrayDataRteSet();
	
	Rte_Write_P_NvM_NvM_STR(&NvM.Out);	// 구조체로 한꺼번에 전송
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		전원 리셋시 즉시 또는 매주기 판정하도록 모듈화하여 호출함
***************************************************************************************************/
void ss_NvM_WpcTypeJudge(void)
{
	// NvM.Int.NvMBlk_ECU_Info_Ram[0] = '9';//'9'
	// NvM.Int.NvMBlk_ECU_Info_Ram[1] = '5';//'5'
	// NvM.Int.NvMBlk_ECU_Info_Ram[2] = '5';//'5'
	// NvM.Int.NvMBlk_ECU_Info_Ram[3] = '6';//'6'
	// NvM.Int.NvMBlk_ECU_Info_Ram[4] = '0';//'0'
	// NvM.Int.NvMBlk_ECU_Info_Ram[5] = 'N';//'N'
	// NvM.Int.NvMBlk_ECU_Info_Ram[6] = '1';//'1'
	// NvM.Int.NvMBlk_ECU_Info_Ram[7] = '6';//'6'
	// NvM.Int.NvMBlk_ECU_Info_Ram[8] = '0';//'0'
	// NvM.Int.NvMBlk_ECU_Info_Ram[9] = '0';//'0'	
	
    // 양산 후 품번 추가 될 경우 소스 코드 변경 없이 적용하기 위해서
	// 품번 전체 비교에서 wpc type 규칙 있는 자리수까지 비교하는것으로 변경
	if(( NvM.Int.NvMBlk_ECU_Info_Ram[5] == cTYPE4_PartNo1) &&
	( NvM.Int.NvMBlk_ECU_Info_Ram[6] == cTYPE4_PartNo2) &&
	( NvM.Int.NvMBlk_ECU_Info_Ram[7] == cTYPE4_PartNo3))
	{
		NvM.Out.WPC_TYPE = cWPC_TYPE4;
		NvM.Out.DeviceMaxCnt = 1u;
	}
	else if(( NvM.Int.NvMBlk_ECU_Info_Ram[5] == cTYPE5_PartNo1) &&
	( NvM.Int.NvMBlk_ECU_Info_Ram[6] == cTYPE5_PartNo2) &&
	( NvM.Int.NvMBlk_ECU_Info_Ram[7] == cTYPE5_PartNo3))
	{
		NvM.Out.WPC_TYPE = cWPC_TYPE5;
		NvM.Out.DeviceMaxCnt = 2u;
	}
	else if(( NvM.Int.NvMBlk_ECU_Info_Ram[5] == cTYPE6_PartNo1) &&
	( NvM.Int.NvMBlk_ECU_Info_Ram[6] == cTYPE6_PartNo2) &&
	( NvM.Int.NvMBlk_ECU_Info_Ram[7] == cTYPE6_PartNo3))
	{
		NvM.Out.WPC_TYPE = cWPC_TYPE6;
		NvM.Out.DeviceMaxCnt = 2u;
	}
	else
	{
		NvM.Out.WPC_TYPE = cWPC_TYPE_None;	/* 0108_08 */ // default		
		NvM.Out.DeviceMaxCnt = 0u;
		
		// NvM.Out.WPC_TYPE = cWPC_TYPE6;	/* 0108_08 */ // default
		// NvM.Out.DeviceMaxCnt = 2u;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
// data는 1바이트씩 10ms 주기로 값의 변화가 있는지 여부를 판단하여 변화가 있을시에만 라이팅한는 방식임.
// ecuinfo는 요청할때 rte를 즉시 호출하여 비교없이 다시 라이팅함.
// wpc도 이방식과 유사하게 ecuinfo 제외한 나머지 7개 는 10ms task로 값의 변화가 있는지 여부를 계속
// 확인하면서 변화 있을시만 라이팅하는 방법을 택함.
// SCM에서 data write하는 방식과 유사하므로 약간만 변경하여 적용함.
// SCM은 매주기 data write rte를 모델에서 호출하는 방식으로 적용되었음.
// wpc data write rte를 매주기 호출하지는 않고  기존 wpc 컨셉과 유사하게 적용함.(기본 로직은 scm 횡전개함.)

static  void    ss_NvM_WriteBlock_1B(void)
{
	//NVM_REQ_OK (0):					Request 가 성공했을시의 Block 의 상태.
	//								또한 read 실패후, (InitBlockCallback 이 설정되어 있고), InitBlockCallback 을 호출하면, Ram Block
	//								은 Application 에서 처리했다고 생각하여, Block 의 상태는 NVM_REQ_OK 로 설정됨
	//								=> PENDING 아니고 RAM이미지 다르면 EEP write하도록 로직구성 필요

	//NVM_REQ_NOT_OK (1):				Request 가 실패하였을시에 Block 의 상태.
	//								=> PENDING 아니고 RAM이미지 다르면 EEP write하도록 로직구성 필요

	//NVM_REQ_PENDING (2):				Request 를 받은 상태로, Request 가 진행중인 Block 의 상태.
	//								=> PENDING 아니고 RAM이미지 다르면 EEP write하도록 로직구성 필요

	//NVM_REQ_INTEGRITY_FAILED (3):	Read/ReadAll 시에 fail 이 났으며, 읽기 동작은 이상없이 진행되었으나,
	//								그 fail 원인이 읽은 Data 값의 CRC 값이 맞지 않았을 때 발생하는 Block 의 상태
	//								=> 초기 한번만 처리필요. 읽기동작에 문제가 없었으므로 해당 리턴값에서는 초기값 써주면 안됨.

	//NVM_REQ_BLOCK_SKIPPED (4):		ReadAll 이나 WriteAll 시에 ReadAll/WriteAll 로 설정된 Block 은 그에 맞는 동작을 진행하며,
	//								ReadAll/WriteAll 이 설정되지 않은 Block 은 ReadAll/WriteAll 을 Skip 했단 의미로
	//								NVM_REQ_BLOCK_SKIPPED 가 설정됨.
	//								=> 모든 BLOCK을 ReadAll 하므로 skip되는 BLOCK없음. 고려 불필요

	// NVM_REQ_NV_INVALIDATED (5): 	NV Block 이 invalidated 일때 (Fee 의 Job Result 결과가 MEMIF_BLOCK_INVALID 일때)로,
	//								Fee 에 설정한 Block 이 Invalid 일 때 발생하는 Block 의 상태.
	//								예를들어, Ext.EEPROM 이나 Bolero 의 경우 한번도 write 하지 않은 초기 상태에서 Read 를 하는 경우
	//								에는 Block 상태가 NVM_REQ_NV_INVALIDATED 임 (단, NVM_REQ_NV_INVALIDATED 상태가
	//								Write 를 한번도 안한 상태만 의미하지는 않음.)
	//								=> CYPRESS에서는 어떨지 모르나 일단 ST와 동일하게 로직 구성.

	//NVM_REQ_CANCELED (6):			보충설명 없음. 영문내용 번역.
	//								다중 블록 요청 NvM_WriteAll이 NvM_CancelWriteAll을 호출하여 취소되었습니다.
	//								또는 NvM_CancelJobs를 호출하여 모든 단일 블록 작업 요청(NvM_ReadBlock, NvM_WriteBlock,
	//								NvM_EraseNvBlock, NvM_InvalidateNvBlock 및 NvM_RestoreBlockDefaults)이 취소되었습니다.
	//								=> WriteAll or CancelWriteAll or CancelJobs 미사용. 고려 불필요

	//NVM_REQ_REDUNDANCY_FAILED (7):	Redundant Block 에서 둘 다 실패했을 시에 발생하는 Error 로, 스펙에서 Type 으로 정의 만 되어있고,
	//								사용적인 측면에서는 나와있지 않아 현재 플랫폼 상에서는 따로 설정되지 않습니다. 하지만 스펙에 나와있
	//								는 만큼 추후에 업데이트될 가능성을 배제할 수 없기에 NVM_REQ_NOT_OK 와 동일하게 처리해 주시는
	//								게 좋을 것 같습니다
	//								=> SWP에서 리턴되지 않는 값임. 고려 불필요

	//NVM_REQ_RESTORED_FROM_ROM (8):	ROM Block 이 설정되어 있을시, Read 실패로 Rom Block 의 값이 Ram Block 에 저장이 되었을 때,
	//								설정되는 Block 의 상태임.
	//								실패시 결과값이 NVM_REQ_NV_INVALIDATED 나 NVM_REQ_INTEGRITY_FAILED 일지라도,
	//								ROM Block 이 설정되어 Rom Block 의 값이 저장이 되었다면, NVM_REQ_RESTORED_FROM_ROM 으로 Return 된다.
	//								=> ROM BLOCK미사용이므로 고려 불필요

	uint8_t 	retValue = E_OK;
	NvM_RequestResultType bNvMBlockStatus = NVM_REQ_OK;
	uint8_t NvMBlk_DataOld[BLK_NO_1BYTE_MAX] = {0};

	// uint8_t 	retValue2 = E_OK; // WPC_410_02
	// NvM_RequestResultType bNvMBlockStatus2 = NVM_REQ_OK; // WPC_410_02


	NvM_BlockIdType bId;	// for qac
	// uint8_t	bPendFlag = 0;

	// 한꺼번에 읽어온 데이터를 기존 로직 유용하기 위해서 기존 사용하는 변수에 복사처리
	// nvm 애니메이션을 사용하지 않으므로 대신에 wpc2 profie로 대체하여 사용함.
	// 임시로 컴파일 위주로 하고 나중에 변수명 디파인등도 변경하자.
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ProfileGuestWPCUSM_0] = NvM.Inp_Model.Device[D0].m_ProfileGuestWPCUSM;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ProfileOneWPCUSM_0] = NvM.Inp_Model.Device[D0].m_ProfileOneWPCUSM;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ProfileTwoWPCUSM_0] = NvM.Inp_Model.Device[D0].m_ProfileTwoWPCUSM;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_AutoBrightSta] = NvM.Inp_CAN_RX.BCAN.m_AutoBrightSta;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ProfileGuestWPCUSM_1] = NvM.Inp_Model.Device[D1].m_ProfileGuestWPCUSM;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ProfileOneWPCUSM_1] = NvM.Inp_Model.Device[D1].m_ProfileOneWPCUSM;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ProfileTwoWPCUSM_1] = NvM.Inp_Model.Device[D1].m_ProfileTwoWPCUSM;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_PDCReset] = NvM.Inp_WDT.m_PDCReset;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_ANT_Calibration] = NvM.Inp_NFC.m_ANT_Calibration;	
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_B0BADisableCnt] = NvM.Inp_Uds.m_B0BADisableCnt;
	NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_WctReproRequest] = NvM.Inp_Repro.m_WctReproRequest; /* 0108_13 */
	
	// 사용하고자 하는 해당 모듈에서 rte 구조체 추가하고 read할것
	// NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_Flag2] = NvM.Inp_Uds.m_Flag2; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_Flag3] = NvM.Inp_Uds.m_Flag3; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_Flag4] = NvM.Inp_Uds.m_Flag4; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_Flag5] = NvM.Inp_Uds.m_Flag5; // 예비로 생성해 둠.
	// NvM.Int.NvMBlk_1B_Data_IN[BLK_NO_1B_Flag6] = NvM.Inp_Uds.m_Flag6; // 예비로 생성해 둠.
	
	
	for (bId = 0; bId < (uint8_t)BLK_NO_1BYTE_MAX; bId++)
	{
		if (NvM.Int.NvMBlk_1B_Data_Ram[bId] != NvM.Int.NvMBlk_1B_Data_IN[bId])
		{
			NvM.Out.NvMBlk_1B_Complete[bId] = OFF; 
			NvM.Int.NvMBlk_1B_Data_Ram[bId] = NvM.Int.NvMBlk_1B_Data_IN[bId];
		}

		if (NvM.Out.NvMBlk_1B_Complete[bId] == OFF)
		{			
			retValue = NvM_GetErrorStatus((NvM.Int.NvMBlk_1B_BlockNo[bId]), &bNvMBlockStatus);

			NvM.Int.NvMBlk_1B_Status[bId] = bNvMBlockStatus; // 디버깅용 모니터링 변수
			NvM.Int.NvMBlk_1B_RetValue[bId] = retValue; // 디버깅용 모니터링 변수
			

			if (retValue == RTE_E_OK) //&&
			{
				if((bNvMBlockStatus == NVM_REQ_OK) || // &&
				(bNvMBlockStatus == NVM_REQ_RESTORED_FROM_ROM)) // WPC_486_02 // 모빌젠 설정에 의해서 초기값 설정된 직후에 read시에 리턴되는 값임. 값 변경 후에는 리턴 안됨
				{					
					if (NvM.Int.NvMBlk_1B_Data_Ram[bId] == NvMBlk_1B_Data[bId]) // 요청 후 라이팅 완료시까지 약 60ms 정도 소요되는듯.
					{
						NvM.Out.NvMBlk_1B_Complete[bId] = ON; //Write Complete
					}
					else
					{
// NvM_WriteBlock() 처리 강건화 추가
						NvMBlk_DataOld[bId] = NvMBlk_1B_Data[bId]; // 저장전 NvM데이터 백업
						NvMBlk_1B_Data[bId] = NvM.Int.NvMBlk_1B_Data_Ram[bId];
						
						retValue = NvM_WriteBlock((NvM.Int.NvMBlk_1B_BlockNo[bId]), &NvMBlk_1B_Data[bId]);
						if(retValue == RTE_E_OK) /* Request OK */
						{
							NvM.Int.NvMBlk_1B_WriteErrCnt[bId] = 0;
						}
						else /* Request Not OK */
						{
							// 리턴값이 실패 이므로 라이팅이 정상으로 되지 않았다고 판단하고
							// 다시 라이팅 이전 값으로 복귀처리함.
							// 이렇게 해야 다음 주기에서 다시 라이팅 시도 하게 됨.
							NvMBlk_1B_Data[bId]= NvMBlk_DataOld[bId]; // NvM데이터 실패 이전 값으로 복구
							NvM.Int.NvMBlk_1B_Data_Ram[bId] = NvMBlk_1B_Data[bId];						
							NvM.Int.NvMBlk_1B_WriteErrCnt[bId]++;							
						}
										
// NvM_WriteBlock() 처리 강건화 추가
					}
					
					NvM.Int.NvMBlk_1B_Pending_Cnt[bId] = 0;	// 디버깅용 모니터링 변수 (성공시 초기화 되지 않고 남아 있도록 일부러 여기서 초기화시킴)
					NvM.Int.NvMBlk_1B_NotOk_Cnt[bId] = 0; // 디버깅용 모니터링 변수
				}
				else if(bNvMBlockStatus == NVM_REQ_PENDING) // Request 를 받은 상태로, Request 가 진행중인 Block 의 상태.															
				{
					NvM.Int.NvMBlk_1B_Pending_Cnt[bId]++; // Pending 처리와 동일하게 다음주기의 for문 동일 index가 되면 다시 시도함 (약 40 ~ 60ms 정도 pening발생함)
				}
				else if(bNvMBlockStatus == NVM_REQ_NOT_OK) // Request 가 실패하였을시에 Block 의 상태.
				{
					//  request가 실패 했으므로 라이팅이 정상으로 되지 않았음
					// 다시 라이팅 이전 값으로 복귀처리함.
					// 이렇게 해야 다음 주기에서 다시 라이팅 시도 하게 됨.
					NvMBlk_1B_Data[bId]= NvMBlk_DataOld[bId]; // NvM데이터 실패 이전 값으로 복구
					NvM.Int.NvMBlk_1B_Data_Ram[bId] = NvMBlk_1B_Data[bId];						
					NvM.Int.NvMBlk_1B_WriteErrCnt[bId]++;		
												
					NvM.Int.NvMBlk_1B_NotOk_Cnt[bId]++; // 디버깅용 모니터링 변수
				}				
				else // 위 조건 이외의 리턴값에 대해서는 아무 처리 하지 않음. 다음 주기에 재시도 하도록
				{
					// QAC
				}				
			} // 리턴값이 에러 일경우 아무 처리 하지 않음. 다음 주기에 재시도 하도록.
		}
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		배열 NvM도 1바이트 방식으로 Write 방식 변경해 봄. 이전 방식은 실패시 리트라이도 안되고 해서 문제를 내포하고 있음. 개선 필요함.
***************************************************************************************************/
static  void    ss_NvM_WriteBlock_Array(void)
{
	NvM_BlockIdType bId = 0;
	NvM_RequestResultType bNvMBlockStatus = NVM_REQ_OK;
	uint8_t retValue = E_OK;
	uint8_t	NvMBlk_ECU_Info_Old[ECU_INFO_SIZE];
	uint8_t	NvMBlk_SerialNum_Old[SERIAL_NUM_SIZE];	
	uint8_t NvMBlk_QRCode_Old[QRCODE_SIZE];	
	
	// rte read에서 구조체로 매주기 app의 m 변수를 read하므로 별도로 모듈에서 리드 할 필요 없다.
	
	// int memcmp(const void* buf1, const void* buf2, size_t size); 이므로 qac위해서 리턴값을 FALSE대신 0 (int)으로 변경함.
	if(memcmp(NvM.Int.NvMBlk_ECU_Info_Ram, NvM.Inp_Uds.m_ECU_Info, ECU_INFO_SIZE) != 0) // 동일할 경우 0, 다를경우 음수/양수
	{
		NvM.Out.NvMBlk_Array_Complete[BLK_NO_ARR_ECU_Info] = OFF;
		memcpy(NvM.Int.NvMBlk_ECU_Info_Ram, NvM.Inp_Uds.m_ECU_Info, ECU_INFO_SIZE);
	}	
	if(memcmp(NvM.Int.NvMBlk_SerialNum_Ram, NvM.Inp_Uds.m_SerialNum, SERIAL_NUM_SIZE) != 0) // 동일할 경우 0, 다를경우 음수/양수
	{
		NvM.Out.NvMBlk_Array_Complete[BLK_NO_ARR_SerialNum] = OFF;
		memcpy(NvM.Int.NvMBlk_SerialNum_Ram, NvM.Inp_Uds.m_SerialNum, SERIAL_NUM_SIZE);
	}	
	if(memcmp(NvM.Int.NvMBlk_QRCode_Ram, NvM.Inp_Uds.m_QRCode, QRCODE_SIZE) != 0) // 동일할 경우 0, 다를경우 음수/양수
	{
		NvM.Out.NvMBlk_Array_Complete[BLK_NO_ARR_QRCode] = OFF;
		memcpy(NvM.Int.NvMBlk_QRCode_Ram, NvM.Inp_Uds.m_QRCode, QRCODE_SIZE);
	}			
			
	// App에서  NvM에 저장을 요청할 값은 CS Runnable에서 저장되고 저장 여부를 판단한다.
	
	for (bId = 0; bId < (uint8_t)BLK_NO_ARRAY_MAX; bId++)
	{
		if (NvM.Out.NvMBlk_Array_Complete[bId] == OFF)
		{			
			retValue = NvM_GetErrorStatus((NvM.Int.NvMBlk_Array_BlockNo[bId]), &bNvMBlockStatus);

			NvM.Int.NvMBlk_Array_Status[bId] = bNvMBlockStatus; // 디버깅용 모니터링 변수
			NvM.Int.NvMBlk_Array_RetValue[bId] = retValue; 		// 디버깅용 모니터링 변수
			
			if (retValue == RTE_E_OK)
			{
				if((bNvMBlockStatus == NVM_REQ_OK) ||
				(bNvMBlockStatus == NVM_REQ_RESTORED_FROM_ROM)) // 모빌젠 설정에 의해서 초기값 설정된 직후에 read시에 리턴되는 값임. 값 변경 후에는 리턴 안됨
				{	
					switch(bId)	
					{
						case BLK_NO_ARR_ECU_Info:
							if(memcmp(NvM.Int.NvMBlk_ECU_Info_Ram, NvMBlk_ECU_Info, ECU_INFO_SIZE) == 0) // 동일할 경우 0, 다를경우 음수/양수
							{
								NvM.Out.NvMBlk_Array_Complete[bId] = ON; // Write Complete
							}
							else
							{
								memcpy(NvMBlk_ECU_Info_Old, NvMBlk_ECU_Info, ECU_INFO_SIZE);	  // 저장전 NvM데이터 백업
								memcpy(NvMBlk_ECU_Info, NvM.Int.NvMBlk_ECU_Info_Ram, ECU_INFO_SIZE);	
						
								retValue = NvM_WriteBlock((NvM.Int.NvMBlk_Array_BlockNo[bId]), NvMBlk_ECU_Info);
								if(retValue == RTE_E_OK) /* Request OK */
								{
									NvM.Int.NvMBlk_Array_WriteErrCnt[bId] = 0;
								}
								else // request가 실패하면 이전값으로 복원하여 리트라이 되도록한다.
								{									
									memcpy(NvMBlk_ECU_Info, NvMBlk_ECU_Info_Old, ECU_INFO_SIZE);// NvM데이터 실패 이전 값으로 복구
									memcpy(NvM.Int.NvMBlk_ECU_Info_Ram, NvMBlk_ECU_Info, ECU_INFO_SIZE);	
									NvM.Int.NvMBlk_Array_WriteErrCnt[bId]++;						
								}
				
								//NvM.Int.NvMBlk_Array_Pending_Cnt[bId] = 0;	// 디버깅용 모니터링 변수
							}
						break;
						
						case BLK_NO_ARR_SerialNum:
							if(memcmp(NvM.Int.NvMBlk_SerialNum_Ram, NvMBlk_SerialNum, SERIAL_NUM_SIZE) == 0) // 동일할 경우 0, 다를경우 음수/양수
							{
								NvM.Out.NvMBlk_Array_Complete[bId] = ON; // Write Complete
							}
							else
							{
								memcpy(NvMBlk_SerialNum_Old, NvMBlk_SerialNum, SERIAL_NUM_SIZE);	  // 저장전 NvM데이터 백업
								memcpy(NvMBlk_SerialNum, NvM.Int.NvMBlk_SerialNum_Ram, SERIAL_NUM_SIZE);							
						
								retValue = NvM_WriteBlock((NvM.Int.NvMBlk_Array_BlockNo[bId]), NvMBlk_SerialNum);
								if(retValue == RTE_E_OK) /* Request OK */
								{
									NvM.Int.NvMBlk_Array_WriteErrCnt[bId] = 0;
								}
								else // request가 실패하면 이전값으로 복원하여 리트라이 되도록한다.
								{
									memcpy(NvMBlk_SerialNum, NvMBlk_SerialNum_Old, SERIAL_NUM_SIZE);// NvM데이터 실패 이전 값으로 복구
									memcpy(NvM.Int.NvMBlk_SerialNum_Ram, NvMBlk_SerialNum, SERIAL_NUM_SIZE);	
									NvM.Int.NvMBlk_Array_WriteErrCnt[bId]++;						
								}
				
								//NvM.Int.NvMBlk_Array_Pending_Cnt[bId] = 0;	// 디버깅용 모니터링 변수
							}					
						break;
						
						case BLK_NO_ARR_QRCode:
							if(memcmp(NvM.Int.NvMBlk_QRCode_Ram, NvMBlk_QRCode, QRCODE_SIZE) == 0) // 동일할 경우 0, 다를경우 음수/양수
							{
								NvM.Out.NvMBlk_Array_Complete[bId] = ON; // Write Complete
							}
							else
							{
								memcpy(NvMBlk_QRCode_Old, NvMBlk_QRCode, QRCODE_SIZE);	  // 저장전 NvM데이터 백업
								memcpy(NvMBlk_QRCode, NvM.Int.NvMBlk_QRCode_Ram, QRCODE_SIZE);									
						
								retValue = NvM_WriteBlock((NvM.Int.NvMBlk_Array_BlockNo[bId]), NvMBlk_QRCode);
								if(retValue == RTE_E_OK) /* Request OK */
								{
									NvM.Int.NvMBlk_Array_WriteErrCnt[bId] = 0;
								}
								else // request가 실패하면 이전값으로 복원하여 리트라이 되도록한다.
								{
									memcpy(NvMBlk_QRCode, NvMBlk_QRCode_Old, QRCODE_SIZE);// NvM데이터 실패 이전 값으로 복구
									memcpy(NvM.Int.NvMBlk_QRCode_Ram, NvMBlk_QRCode, QRCODE_SIZE);	
									NvM.Int.NvMBlk_Array_WriteErrCnt[bId]++;						
								}
				
								//NvM.Int.NvMBlk_Array_Pending_Cnt[bId] = 0;	// 디버깅용 모니터링 변수
							}							
						break;
						
						default:
							// QAC
						break;
																					
					}			
					NvM.Int.NvMBlk_Array_Pending_Cnt[bId] = 0;	// 디버깅용 모니터링 변수	
					NvM.Int.NvMBlk_Array_NotOk_Cnt[bId] = 0; // 디버깅용 모니터링 변수					
				}
				else if(bNvMBlockStatus == NVM_REQ_PENDING)	// Pending 처리와 동일하게 다음주기의 for문 동일 index가 되면 다시 시도함 (약 40 ~ 60ms 정도 pening발생함)
				{
					NvM.Int.NvMBlk_Array_Pending_Cnt[bId]++; // 디버깅용 모니터링 변수
				}
				else if(bNvMBlockStatus == NVM_REQ_NOT_OK)
				{
					NvM.Int.NvMBlk_Array_NotOk_Cnt[bId]++; // 디버깅용 모니터링 변수
					
					switch(bId)	
					{
						case BLK_NO_ARR_ECU_Info:
							memcpy(NvMBlk_ECU_Info, NvMBlk_ECU_Info_Old, ECU_INFO_SIZE);// NvM데이터 실패 이전 값으로 복구
							memcpy(NvM.Int.NvMBlk_ECU_Info_Ram, NvMBlk_ECU_Info, ECU_INFO_SIZE);	
							NvM.Int.NvMBlk_Array_WriteErrCnt[bId]++;							
						break;
						
						case BLK_NO_ARR_SerialNum:
							memcpy(NvMBlk_SerialNum, NvMBlk_SerialNum_Old, SERIAL_NUM_SIZE);// NvM데이터 실패 이전 값으로 복구
							memcpy(NvM.Int.NvMBlk_SerialNum_Ram, NvMBlk_SerialNum, SERIAL_NUM_SIZE);	
							NvM.Int.NvMBlk_Array_WriteErrCnt[bId]++;													
						break;
						
						case BLK_NO_ARR_QRCode:
							memcpy(NvMBlk_QRCode, NvMBlk_QRCode_Old, QRCODE_SIZE);// NvM데이터 실패 이전 값으로 복구
							memcpy(NvM.Int.NvMBlk_QRCode_Ram, NvMBlk_QRCode, QRCODE_SIZE);	
							NvM.Int.NvMBlk_Array_WriteErrCnt[bId]++;						
						break;
						
						default:
						
						break;
					}
					
					
				}					
				else // 위 조건 이외의 리턴값에 대해서는 아무 처리 하지 않음. 다음 주기에 재시도 하도록
				{
					// QAC
				}				
			}// 리턴값이 에러 일경우 아무 처리 하지 않음. 다음 주기에 재시도 하도록.
		}
	}	
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_NvM_L2H_Set(void)
{
	// NvM.Int.Runnable_State = 0u; // wakeup시 다시 시작하면 안됨.
									// 전원 인가시 1회만 실행하면 됨.
									// 오히려 wakeup시마다 실행하다가 에러 발생에 의해서 더 문제가 될수도 있음

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_NvM_H2L_Set(void)
{



}



#define App_NvM_STOP_SEC_CODE
#include "App_NvM_MemMap.h"
