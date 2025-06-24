/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2023
 * All rights reserved.
 *
 * Disclaimer
 * 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any warranties of any kind.
 * NXP makes no warranties to Licensee and shall not indemnify Licensee or hold it harmless for any
 * reason related to the NXP Software/Source Code or otherwise be liable to the NXP customer. The NXP
 * customer acknowledges and agrees that the NXP Software/Source Code is provided AS-IS and accepts
 * all risks of utilizing the NXP Software under the conditions set forth according to this disclaimer.
 *
 * 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUS-TOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGDED TO HAVE RESULTED FROM ANY DEFECT, ER-ROR OR OMMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPE-CIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RE-LATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 * 3. NXP reserves the right to make changes to the NXP Software/Source code any time, also without
 * informing customer.
 *
 * 4. Licensee agrees to indemnify and hold harmless NXP and its affiliated companies from and against
 * any claims, suits, losses, damages, liabilities, costs and expenses (including reasonable
 * attorney's fees) resulting from Licensee's and/or Licensee customer's/licensee's use of the NXP
 * Software/Source Code.
 *******************************************************************************/

#include <Nfcrdlib.h>

static uint8 lpcd_cal_compelete;
static uint8 lpcd_WakeupState;
static uint8 data_exchangeState;
static uint8 nfcModeExitReady = NXP_ON;		// 230509
static APDUStatus_ENUM_t apduExchangeStatus = APDU_None;
static ANFC_MAIN_StateType_t discloop_state = ANFC_STATE_IDLE;

static phStatus_t	NFC_CommunicationError = PH_ERR_SUCCESS;
static uint16		NFC_CommErr_Cnt = 0U;

#define MAX_TX_BUFFER_SIZE	270

phStatus_t NXP_NfcRdLib_Init(void)
/* NXP Module 230209 */
{
	phStatus_t status = PH_ERR_SUCCESS;
	static uint8 init_state = 0;

	switch (init_state)
	{
	case 0:
		status = aNfcRdLib_Init_Platform_Init();
		if(status != PH_ERR_SUCCESS)
			break;
		init_state = 1;
		// no break
	case 1:
		status = aNfcRdLib_Init_Ncx3321_Init();
		if(status != PH_ERR_SUCCESS)
			break;
		init_state = 2;
		// no break
	case 2:
		status = aNfcRdLib_Init_Component_Init();
		if(status != PH_ERR_SUCCESS)
			break;
		init_state = 3;
		// no break
	case 3:
		status = aNfcRdLib_Init_Task_Init();
		if(status != PH_ERR_SUCCESS)
			break;
		init_state = 4;
		// no break
	case 4:
		status = aNfcRdLib_Rf_Config_Init();
		if(status != PH_ERR_SUCCESS)
			break;
		init_state = 0;
		// no break
	default:
		break;
	}

	return status;
}
/* NXP Module 230209 */

/***************************************************************************************************
@param[in]  uint8 LpcdState
 - 0 : 해당 모듈은 재시작을 위해서 초기화 처리한다. (Entry 모듈에서 1회 호출)
 - 1 : 해당 모듈은 초기화 이후 시컨스 부터 시작한다. (During 모듈에서 10ms 마다 호출)
@return     void
@note
 - LPCD 제어 관련 모듈로써 LPCD 기능 사용시 10ms 마다 호출된다.
***************************************************************************************************/
void NXP_LPCD_MainControl(void)
{
	if (lpcd_cal_compelete == NXP_OFF)
	{
		lpcd_WakeupState = NXP_OFF;

		if (discloop_state == ANFC_STATE_IDLE)
		{
			discloop_state = aNfc_Idle(TRUE);
		}
		else if (discloop_state == ANFC_STATE_LPCD_CONFIG)
		{
			discloop_state = aNfc_LpcdConfig();
		}
		else if (discloop_state == ANFC_STATE_LPCD_DETECT)
		{
			lpcd_cal_compelete = NXP_ON;
		}
	}
	else
	{
		switch (discloop_state)
		{
		case ANFC_STATE_LPCD_DETECT:
			discloop_state = aNfc_LpcdDetect();
			break;
		case ANFC_STATE_APPLY_PROTO_TYPE_A:
			lpcd_WakeupState = NXP_ON;
			discloop_state = ANFC_STATE_PAUSE;
			// no break;
		case ANFC_STATE_PAUSE:
			Reset_NXP_NFC_CommunicationErrors();	// 230503. JJH
			// do nothing
			break;
		default:
			break;
		}
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
 - 제어 관련 변수 초기화 처리
***************************************************************************************************/
void NXP_LPCD_MainControl_Init(void)
{
	// discloop_state = aNfc_Idle(TRUE);
	discloop_state = ANFC_STATE_IDLE;
	lpcd_cal_compelete = NXP_OFF;
	lpcd_WakeupState = NXP_OFF;
}

/***************************************************************************************************
@param[in]  void
@return     uint8
 - NXP_OFF(0) : not wakeup
 - NXP_ON(1) : LPCD wakeup detected
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
 - LPCD Wakeup 검출 여부를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_LPCD_WakeupCheck(void)
{
	return lpcd_WakeupState;
}

/***************************************************************************************************
@param[in]  uint8 NfcState
 - 0 : 해당 모듈은 재시작을 위해서 초기화 처리한다. (Entry 모듈에서 1회 호출)
 - 1 : 해당 모듈은 초기화 이후 시컨스 부터 시작한다. (During 모듈에서 10ms 마다 호출)
@return     void
@note
 - NFC 검출 및 NFC와 Data 통신 제어 관련 모듈로써 NFC 검출 및 Data 통신 기능 사용 시 10ms 마다 호출된다.
 - NFC 검출 후 최대 대기시간 타이머를 시작한다.
 - Get_CanTpRxComplete()을 호출하여 리턴값이 1이 될때까지 대기한다. 최대 대기 시간은 2초이다.(함수는 니덱에서 생성)
 - 2초가 경과해도 리턴값이 1이 되지 않으면 TIMEOUT1(3)을 리턴한다.
 - 1이 리턴되면 최대 대기시간 타이머를 클리어 하고 폰과 Data 통신을 시작한다.
 - uint8 * Get_CanTpRxBuf(void)를 호출하여 폰에 전달 해야하는 data  (uint8 *CanTpRxBuf)를 get한다. (함수는 니덱에서 생성)
 - uint8 Get_CanTpRxSize(void)를 호출하여 폰에 전달 해야하는 data 와 크기(uint8 CanTpRxSize)를 get한다. (함수는 니덱에서 생성)
 - get한 데이터를 폰에 전달한다. (data는 임시로 생성하여 사용할 것.)
 - 폰과의 data 통신이 시작시 최대 대기시간 타이머를 시작하고 2초가 경과하도록 정상 완료 되지 않으면 타이머 클리어하고 TIMEOUT2(4)을 리턴한다.
 - 폰과의 data 통신이 정상적으로 완료 되면 ON을 리턴하고 NFC 동작을 중지하고 다음 초기화 및 재시작 명령을 대기한다.
***************************************************************************************************/
phStatus_t NXP_NFC_MainControl(uint8 dataExchange, uint8* pTxBuff, uint16 length)
{
	static uint8 txBuffer[MAX_TX_BUFFER_SIZE];
	static uint16 txLength = 0;

	switch (discloop_state)
	{
	case ANFC_STATE_IDLE:
		discloop_state = aNfc_Idle(FALSE);
		// break;	// no break
	case ANFC_STATE_APPLY_PROTO_TYPE_A:
		discloop_state = aNfc_ApplyProtocolSetting();
		break;
	case ANFC_STATE_FIELD_ON:
		discloop_state = aNfc_FieldOnState();
		break;
	// case 0xF1:
	//     discloop_state = ANFC_STATE_DETECTING_TYPE_A;
	// 	break;
	case ANFC_STATE_DETECTING_TYPE_A:
		discloop_state = aNfc_DetectingCard(FALSE);
		break;
	// case 0xF2:
	//     discloop_state = ANFC_STATE_VASUPA;
	// 	break;
	case ANFC_STATE_VASUPA:
		discloop_state = aNfc_VasupA();
		break;
	case ANFC_STATE_ACTIVATECARD:
		discloop_state = aNfc_ActivateCard();
		break;
	case ANFC_STATE_ACTIVATED_N_WAIT:
		data_exchangeState = NXP_OFF;
		apduExchangeStatus = APDU_None;
		if ((dataExchange == NXP_ON) &&	(pTxBuff != NULL) &&
			(length > 0) && (length <= MAX_TX_BUFFER_SIZE))
		{
			memset(txBuffer, 0, MAX_TX_BUFFER_SIZE);
			memcpy(txBuffer, pTxBuff, length);
			txLength = length;

			aNfc_Activated_N_Wait();
			nfcModeExitReady = NXP_OFF;
			apduExchangeStatus = APDU_Send;
			discloop_state = aNfc_DataExchange(txBuffer, txLength);
			if (discloop_state == ANFC_STATE_DATA_EXCHANGE)
			{
				return PH_STATUS_INPROCESS;
			}

			nfcModeExitReady = NXP_ON;
		}
		break;
	case ANFC_STATE_DATA_EXCHANGE:
		nfcModeExitReady = NXP_OFF;	// 230509
		discloop_state = aNfc_DataExchange(txBuffer, txLength);
		if (discloop_state == ANFC_STATE_DATA_EXCHANGE)
		{
			return PH_STATUS_INPROCESS;
		}
/* 0107_03 */
		if(aNfcRdLib_get_APDU_RxLength() > 0u)
		{
			data_exchangeState = NXP_ON;
			nfcModeExitReady = NXP_ON;  // 230509
			apduExchangeStatus = APDU_Receive;
			
			discloop_state = ANFC_STATE_ACTIVATED_N_WAIT;
		}   
		// data_exchangeState = NXP_ON;
		// nfcModeExitReady = NXP_ON;   // 230509
		// apduExchangeStatus = APDU_Receive;
/* 0107_03 */	
		break;
	default:
		break;
	}

	Reset_NXP_NFC_CommunicationErrors();	// 230503. JJH

	return PH_ERR_SUCCESS;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
 - 제어 관련 변수 초기화 처리
***************************************************************************************************/
void NXP_NFC_MainControl_Init(void)
{
	discloop_state = aNfc_Idle(FALSE);
	nfcModeExitReady = NXP_ON;	// 230509
	apduExchangeStatus = APDU_None;
}

/***************************************************************************************************
@param[in]  void
@return     uint8
 - NXP_OFF(0) : not detected
 - NXP_ON(1) : NFC detected
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
- NFC detection 검출 여부를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_NFC_DetectCheck(void)
{
	return aNfcRdLib_getCardDetection();
}

/***************************************************************************************************
@param[in]  void
@return     void
 - NXP_OFF(0) : Not Complete
 - NXP_ON(1) : Complete
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
 - NFC Data Exchange 완료 여부를 리턴한다.
 - TIMEOUT1(2): CanTp 수신 타임아웃 error 발생
 - TIMEOUT2(3): 폰과의 data 통신 타임아웃 error 발생
***************************************************************************************************/
uint8 Get_NXP_NFC_DataExchangeCheck(void)
{
	return data_exchangeState;
}

/***************************************************************************************************
@param[in]  void
@return     uint8 * : data exchage를 통해서 전달 받은 Data
@note
- 폰과 data exchage를 통해서 전달 받은 Data를 리턴한다.
***************************************************************************************************/
uint8 * Get_NXP_NFC_CanTpTxBuf(void)
{
	return aNfcRdLib_get_APDU_RxBuff();
}

/***************************************************************************************************
@param[in]  void
@return     uint8 : 전달 받은 Data 크기
@note
- 폰과 data exchage를 통해서 전달 받은 Data 크기를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_NFC_CanTpTxSize(void)
{
	return aNfcRdLib_get_APDU_RxLength();
}

/***************************************************************************************************
@param[in]  uint8 PiccState
 - 파리미터 PiccState : 0  로 호출 할경우 해당 모듈은 재시작을 위해서 초기화 처리한다. (Entry 모듈에서 1회 호출)
 - 파리미터 PiccState : 1  로 호출 할경우 해당 모듈은 초기화 이후 시컨스 부터 시작한다. (During 모듈에서 10ms 마다 호출)
@return     void
@note
 - 패드위에 NFC장착된 디바이스가 올려져 있는지 여부를 확인하기 위해서 10ms 마다 호출된다.
 - 1000ms 이내에 1회이상 NFC가 검출되면 패드 위에 폰이 있는 것으로 판정하고 즉시 NFC 검출을 중단하고 500ms 후에 다시 NFC 검출을 재시작 한다..
 - 1000ms 이상 연속으로 NFC가 검출되지 않으면 패드 위에 폰이  없는 것으로 판정하고 NFC 검출을 중단한다.
***************************************************************************************************/
phStatus_t NXP_PICC_MainControl(void)
{
	switch (discloop_state)
	{
	case ANFC_STATE_IDLE:
		discloop_state = aNfc_Idle(FALSE);
		// break;
	case ANFC_STATE_APPLY_PROTO_TYPE_A:
		discloop_state = aNfc_ApplyProtocolSetting();
		break;
	case ANFC_STATE_FIELD_ON:
		discloop_state = aNfc_FieldOnState();
		break;
	case ANFC_STATE_DETECTING_TYPE_A:
		discloop_state = aNfc_DetectingCard(TRUE);
		if( (aNfcRdLib_getPiccOnPCD() == DEFAULT_STATE) ||
			(aNfcRdLib_getPiccOnPCD() == CARD_DETECTING))
			return PH_STATUS_INPROCESS;
		break;
	case ANFC_STATE_VASUPA:
		discloop_state = aNfc_VasupA();
		break;
	case ANFC_STATE_PAUSE:
		// NXP_PICC_MainControl_Init();
		break;
	default:
		break;
	}

	if(aNfcRdLib_getPiccOnPCD() == CARD_DETECTED)
	{
		aNfc_FieldOff();
	}

	Reset_NXP_NFC_CommunicationErrors();	// 230503. JJH

	return PH_ERR_SUCCESS;
}

/***************************************************************************************************
@param[in]  uint8 PiccState
@return     void
@note
 - 제어 관련 변수 초기화 처리
***************************************************************************************************/
void NXP_PICC_MainControl_Init(void)
{
	NXP_NFC_MainControl_Init();
}

/***************************************************************************************************
@param[in]  void
@return
 - NXP_OFF(0) : not on the pad
 - NXP_ON(1) : on the pad
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
 - 패드위에 NFC 장착된 디바이스가 올려져 있는지 여부를 리턴 한다.
***************************************************************************************************/
uint8 Get_NXP_PICC_OnThePad(void)
{
	uint8 state;
	// uint8 ret_val;
	uint8 ret_val = 0u;	// Code Sonar

	state = aNfcRdLib_getPiccOnPCD();

	switch(state)
	{
	case CARD_DETECTED:
		ret_val = 2u;	// OnThePad_On
		break;
	case NO_CARD:
		ret_val = 1u;	// OnThePad_Off
		break;
	case CARD_DETECTING:
	case DEFAULT_STATE:
		ret_val = 0u;	// OnThePad_Default
		break;
	}

	return ret_val;
}

void Set_NXP_PICC_OnThePad(uint8 PiccState)
{
	aNfcRdLib_setPiccOnPCD(PiccState);
}

uint8 Get_NXP_NfcModeExitReady(void)
{
	return nfcModeExitReady;
}

APDUStatus_ENUM_t Get_NXP_ApduExchangeState(void)
{
	return apduExchangeStatus;
}

/***************************************************************************************************
@param[in]  void
@return		void
@note
 - RF field OFF
***************************************************************************************************/
phStatus_t NXP_Field_OFF(void)
{
	phStatus_t status = PH_ERR_SUCCESS;

	status = aNfc_FieldOff();

	return status;
}

/***************************************************************************************************
@param[in]  void
@return		void
@note
 - RF field ON
***************************************************************************************************/
phStatus_t NXP_Field_ON(void)
{
	phStatus_t status = PH_ERR_SUCCESS;

	status = aNfc_FieldOn();

	return status;
}

/***************************************************************************************************
@param[in]  void
@return		void
@note
 - Switch to normal mode of operation. It terminates LPCD.
***************************************************************************************************/
phStatus_t NXP_Switch_Mode_Normal(void)
{
	phStatus_t status = PH_ERR_SUCCESS;

	status = aNfc_SwitchModeNormal();

	return status;
}

/***************************************************************************************************
@param[in]  phStatus_t
- NFC Communication Errors
@return     void
@note
- Get NFC Communication Errors
- Error Count SUM
***************************************************************************************************/
void Get_NXP_NFC_CommunicationErrors(phStatus_t status)
{
	NFC_CommunicationError = status;

	switch(NFC_CommunicationError)
	{
		case PH_ERR_IO_TIMEOUT:
		case PH_ERR_INTEGRITY_ERROR:
		case PH_ERR_COLLISION_ERROR:
		case PH_ERR_BUFFER_OVERFLOW:
		case PH_ERR_FRAMING_ERROR:
		case PH_ERR_PROTOCOL_ERROR:
		case PH_ERR_AUTH_ERROR:
		case PH_ERR_READ_WRITE_ERROR:
		case PH_ERR_TEMPERATURE_ERROR:
		case PH_ERR_RF_ERROR:
		case PH_ERR_INTERFACE_ERROR:
		case PH_ERR_LENGTH_ERROR:
		case PH_ERR_RESOURCE_ERROR:
		case PH_ERR_TX_NAK_ERROR:
		case PH_ERR_RX_NAK_ERROR:
		case PH_ERR_EXT_RF_ERROR:
		case PH_ERR_NOISE_ERROR:
		case PH_ERR_ABORTED:
		case PH_ERR_LPCD_ABORTED:
		case PH_ERR_INTERNAL_ERROR:
		case PH_ERR_AUTH_DELAY:
			NFC_CommErr_Cnt++;
			break;
		default:
			break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     uint8
 - NXP_OFF(0)	: No Error
 - NXP_ON(1)	: Error
@note
- NFC Communication Errors 검출 여부를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_NFC_CommunicationErrorsCheck(void)
{
	uint8 ret_val;

	if(NFC_CommErr_Cnt > 0U)
	{
		ret_val = NXP_ON;
	}
	else
	{
		ret_val = NXP_OFF;
	}

	NFC_CommErr_Cnt = 0U;

	return ret_val;
}

/***************************************************************************************************
@param[in]  void
@return     phStatus_t
 - NFC_CommunicationError : Communication Errors
@note
- NFC Communication Errors Status를 리턴한다.
***************************************************************************************************/
phStatus_t Get_NXP_NFC_CommunicationErrorsStatus(void)
{
	return NFC_CommunicationError;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
- Reset NFC Communication Errors Status
- Reset NFC Communication Errors Count
***************************************************************************************************/
void Reset_NXP_NFC_CommunicationErrors(void)
{
	NFC_CommunicationError = PH_ERR_SUCCESS;
	NFC_CommErr_Cnt = 0U;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
- Reset NFC Communication Errors Status
- Reset NFC Communication Errors Count
***************************************************************************************************/
// uint16_t NXP_CardProtection_MainControl_Init(void)
// {
// 	uint16_t ret_val;
// 	// ret_val = detune_meas_reference();
//     // PH_CHECK_INPROCESS_FCT_REDUCE(ret_val, detune_meas_reference());

// 	// DIST_STATE_s = DIST_ST_IDLE;

// 	return ret_val;
// }


/***************************************************************************************************
@param[in]  void
@return     void
@note
- Reset NFC Communication Errors Status
- Reset NFC Communication Errors Count
***************************************************************************************************/
// uint8_t NXP_CardProtection_MainControl(void)
uint16_t NXP_CardProtection_MainControl(void)
{
	DIST_RESULT_t ret_val;

	// ret_val = Dist_run();
	ret_val = Dist_run_CleanSurface();

	return ret_val;
}


/******************************************************************************
 **                            End Of File
 ******************************************************************************/
