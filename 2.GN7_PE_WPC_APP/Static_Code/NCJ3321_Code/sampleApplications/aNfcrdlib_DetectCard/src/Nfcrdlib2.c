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

#include <Nfcrdlib2.h>

static uint8 lpcd_cal_compelete2;
static uint8 lpcd_WakeupState2;
static uint8 data_exchangeState2;
static uint8 nfcModeExitReady2 = NXP_ON2;		// 230509
static APDUStatus_ENUM_t2 apduExchangeStatus2 = APDU_None2;
static ANFC_MAIN_StateType_t2 discloop_state2 = ANFC_STATE_IDLE2;

static phStatus_t2	NFC_CommunicationError2 = PH_ERR_SUCCESS2;
static uint16		NFC_CommErr_Cnt2 = 0U;

#define MAX_TX_BUFFER_SIZE2	270

phStatus_t2 NXP_NfcRdLib_Init2(void)
/* NXP Module 230209 */
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;
	static uint8 init_state2 = 0;

	switch (init_state2)
	{
	case 0:
		status2 = aNfcRdLib_Init_Platform_Init2();
		if(status2 != PH_ERR_SUCCESS2)
			break;
		init_state2 = 1;
		// no break
	case 1:
		status2 = aNfcRdLib_Init_Ncx3321_Init2();
		if(status2 != PH_ERR_SUCCESS2)
			break;
		init_state2 = 2;
		// no break
	case 2:
		status2 = aNfcRdLib_Init_Component_Init2();
		if(status2 != PH_ERR_SUCCESS2)
			break;
		init_state2 = 3;
		// no break
	case 3:
		status2 = aNfcRdLib_Init_Task_Init2();
		if(status2 != PH_ERR_SUCCESS2)
			break;
		init_state2 = 4;
		// no break
	case 4:
		status2 = aNfcRdLib_Rf_Config_Init2();
		if(status2 != PH_ERR_SUCCESS2)
			break;
		init_state2 = 0;
		// no break
	default:
		break;
	}

	return status2;
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
void NXP_LPCD_MainControl2(void)
{
	if (lpcd_cal_compelete2 == NXP_OFF2)
	{
		lpcd_WakeupState2 = NXP_OFF2;

		if (discloop_state2 == ANFC_STATE_IDLE2)
		{
			discloop_state2 = aNfc_Idle2(TRUE);
		}
		else if (discloop_state2 == ANFC_STATE_LPCD_CONFIG2)
		{
			discloop_state2 = aNfc_LpcdConfig2();
		}
		else if (discloop_state2 == ANFC_STATE_LPCD_DETECT2)
		{
			lpcd_cal_compelete2 = NXP_ON2;
		}
	}
	else
	{
		switch (discloop_state2)
		{
		case ANFC_STATE_LPCD_DETECT2:
			discloop_state2 = aNfc_LpcdDetect2();
			break;
		case ANFC_STATE_APPLY_PROTO_TYPE_A2:
			lpcd_WakeupState2 = NXP_ON2;
			discloop_state2 = ANFC_STATE_PAUSE2;
			// no break;
		case ANFC_STATE_PAUSE2:
			Reset_NXP_NFC_CommunicationErrors2();	// 230503. JJH
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
void NXP_LPCD_MainControl_Init2(void)
{
	// discloop_state2 = aNfc_Idle2(TRUE);
	discloop_state2 = ANFC_STATE_IDLE2;
	lpcd_cal_compelete2 = NXP_OFF2;
	lpcd_WakeupState2 = NXP_OFF2;
}

/***************************************************************************************************
@param[in]  void
@return     uint8
 - NXP_OFF2(0) : not wakeup
 - NXP_ON2(1) : LPCD wakeup detected
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
 - LPCD Wakeup 검출 여부를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_LPCD_WakeupCheck2(void)
{
	return lpcd_WakeupState2;
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
phStatus_t2 NXP_NFC_MainControl2(uint8 dataExchange2, uint8* pTxBuff2, uint16 length2)
{
	static uint8 txBuffer2[MAX_TX_BUFFER_SIZE2];
	static uint16 txLength2 = 0;

	switch (discloop_state2)
	{
	case ANFC_STATE_IDLE2:
		discloop_state2 = aNfc_Idle2(FALSE);
		// break;	// no break
	case ANFC_STATE_APPLY_PROTO_TYPE_A2:
		discloop_state2 = aNfc_ApplyProtocolSetting2();
		break;
	case ANFC_STATE_FIELD_ON2:
		discloop_state2 = aNfc_FieldOnState2();
		break;
	// case 0xF1:
	//     discloop_state2 = ANFC_STATE_DETECTING_TYPE_A2;
	// 	break;
	case ANFC_STATE_DETECTING_TYPE_A2:
		discloop_state2 = aNfc_DetectingCard2(FALSE);
		break;
	// case 0xF2:
	//     discloop_state2 = ANFC_STATE_VASUPA2;
	// 	break;
	case ANFC_STATE_VASUPA2:
		discloop_state2 = aNfc_VasupA2();
		break;
	case ANFC_STATE_ACTIVATECARD2:
		discloop_state2 = aNfc_ActivateCard2();
		break;
	case ANFC_STATE_ACTIVATED_N_WAIT2:
		data_exchangeState2 = NXP_OFF2;
		apduExchangeStatus2 = APDU_None2;
		if ((dataExchange2 == NXP_ON2) &&	(pTxBuff2 != NULL) &&
			(length2 > 0) && (length2 <= MAX_TX_BUFFER_SIZE2))
		{
			memset(txBuffer2, 0, MAX_TX_BUFFER_SIZE2);
			memcpy(txBuffer2, pTxBuff2, length2);
			txLength2 = length2;

			aNfc_Activated_N_Wait2();
			nfcModeExitReady2 = NXP_OFF2;
			apduExchangeStatus2 = APDU_Send2;
			discloop_state2 = aNfc_DataExchange2(txBuffer2, txLength2);
			if (discloop_state2 == ANFC_STATE_DATA_EXCHANGE2)
			{
				return PH_STATUS_INPROCESS2;
			}

			nfcModeExitReady2 = NXP_ON2;
		}
		break;
	case ANFC_STATE_DATA_EXCHANGE2:
		nfcModeExitReady2 = NXP_OFF2;	// 230509
		discloop_state2 = aNfc_DataExchange2(txBuffer2, txLength2);
		if (discloop_state2 == ANFC_STATE_DATA_EXCHANGE2)
		{
			return PH_STATUS_INPROCESS2;
		}
/* 0109_02 */
		if(aNfcRdLib_get_APDU_RxLength2() > 0u)
		{
			data_exchangeState2 = NXP_ON2;
			nfcModeExitReady2 = NXP_ON2;  // 230509
			apduExchangeStatus2 = APDU_Receive2;
			
			discloop_state2 = ANFC_STATE_ACTIVATED_N_WAIT2;
		}   
		// data_exchangeState2 = NXP_ON2;
		// nfcModeExitReady2 = NXP_ON2;   // 230509
		// apduExchangeStatus2 = APDU_Receive2;
/* 0109_02 */	
		break;
	default:
		break;
	}

	Reset_NXP_NFC_CommunicationErrors2();	// 230503. JJH

	return PH_ERR_SUCCESS2;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
 - 제어 관련 변수 초기화 처리
***************************************************************************************************/
void NXP_NFC_MainControl_Init2(void)
{
	discloop_state2 = aNfc_Idle2(FALSE);
	nfcModeExitReady2 = NXP_ON2;	// 230509
	apduExchangeStatus2 = APDU_None2;
}

/***************************************************************************************************
@param[in]  void
@return     uint8
 - NXP_OFF2(0) : not detected
 - NXP_ON2(1) : NFC detected
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
- NFC detection 검출 여부를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_NFC_DetectCheck2(void)
{
	return aNfcRdLib_getCardDetection2();
}

/***************************************************************************************************
@param[in]  void
@return     void
 - NXP_OFF2(0) : Not Complete
 - NXP_ON2(1) : Complete
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
 - NFC Data Exchange 완료 여부를 리턴한다.
 - TIMEOUT1(2): CanTp 수신 타임아웃 error 발생
 - TIMEOUT2(3): 폰과의 data 통신 타임아웃 error 발생
***************************************************************************************************/
uint8 Get_NXP_NFC_DataExchangeCheck2(void)
{
	return data_exchangeState2;
}

/***************************************************************************************************
@param[in]  void
@return     uint8 * : data exchage를 통해서 전달 받은 Data
@note
- 폰과 data exchage를 통해서 전달 받은 Data를 리턴한다.
***************************************************************************************************/
uint8 * Get_NXP_NFC_CanTpTxBuf2(void)
{
	return aNfcRdLib_get_APDU_RxBuff2();
}

/***************************************************************************************************
@param[in]  void
@return     uint8 : 전달 받은 Data 크기
@note
- 폰과 data exchage를 통해서 전달 받은 Data 크기를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_NFC_CanTpTxSize2(void)
{
	return aNfcRdLib_get_APDU_RxLength2();
}

/***************************************************************************************************
@param[in]  uint8 PiccState2
 - 파리미터 PiccState2 : 0  로 호출 할경우 해당 모듈은 재시작을 위해서 초기화 처리한다. (Entry 모듈에서 1회 호출)
 - 파리미터 PiccState2 : 1  로 호출 할경우 해당 모듈은 초기화 이후 시컨스 부터 시작한다. (During 모듈에서 10ms 마다 호출)
@return     void
@note
 - 패드위에 NFC장착된 디바이스가 올려져 있는지 여부를 확인하기 위해서 10ms 마다 호출된다.
 - 1000ms 이내에 1회이상 NFC가 검출되면 패드 위에 폰이 있는 것으로 판정하고 즉시 NFC 검출을 중단하고 500ms 후에 다시 NFC 검출을 재시작 한다..
 - 1000ms 이상 연속으로 NFC가 검출되지 않으면 패드 위에 폰이  없는 것으로 판정하고 NFC 검출을 중단한다.
***************************************************************************************************/
phStatus_t2 NXP_PICC_MainControl2(void)
{
	switch (discloop_state2)
	{
	case ANFC_STATE_IDLE2:
		discloop_state2 = aNfc_Idle2(FALSE);
		// break;
	case ANFC_STATE_APPLY_PROTO_TYPE_A2:
		discloop_state2 = aNfc_ApplyProtocolSetting2();
		break;
	case ANFC_STATE_FIELD_ON2:
		discloop_state2 = aNfc_FieldOnState2();
		break;
	case ANFC_STATE_DETECTING_TYPE_A2:
		discloop_state2 = aNfc_DetectingCard2(TRUE);
		if( (aNfcRdLib_getPiccOnPCD2() == DEFAULT_STATE2) ||
			(aNfcRdLib_getPiccOnPCD2() == CARD_DETECTING2))
			return PH_STATUS_INPROCESS2;
		break;
	case ANFC_STATE_VASUPA2:
		discloop_state2 = aNfc_VasupA2();
		break;
	case ANFC_STATE_PAUSE2:
		// NXP_PICC_MainControl_Init();
		break;
	default:
		break;
	}

	if(aNfcRdLib_getPiccOnPCD2() == CARD_DETECTED2)
	{
		aNfc_FieldOff2();
	}

	Reset_NXP_NFC_CommunicationErrors2();	// 230503. JJH

	return PH_ERR_SUCCESS2;
}

/***************************************************************************************************
@param[in]  uint8 PiccState2
@return     void
@note
 - 제어 관련 변수 초기화 처리
***************************************************************************************************/
void NXP_PICC_MainControl_Init2(void)
{
	NXP_NFC_MainControl_Init2();
}

/***************************************************************************************************
@param[in]  void
@return
 - NXP_OFF2(0) : not on the pad
 - NXP_ON2(1) : on the pad
 - NXP_ERR(x) : error 발생 (Error Number 리턴)
@note
 - 패드위에 NFC 장착된 디바이스가 올려져 있는지 여부를 리턴 한다.
***************************************************************************************************/
uint8 Get_NXP_PICC_OnThePad2(void)
{
	uint8 state2;
	uint8 ret_val2;

	state2 = aNfcRdLib_getPiccOnPCD2();

	switch(state2)
	{
	case CARD_DETECTED2:
		ret_val2 = 2u;	// OnThePad_On
		break;
	case NO_CARD2:
		ret_val2 = 1u;	// OnThePad_Off
		break;
	case CARD_DETECTING2:
	case DEFAULT_STATE2:
		ret_val2 = 0u;	// OnThePad_Default
		break;
	}

	return ret_val2;
}

void Set_NXP_PICC_OnThePad2(uint8 PiccState2)
{
	aNfcRdLib_setPiccOnPCD2(PiccState2);
}

uint8 Get_NXP_NfcModeExitReady2(void)
{
	return nfcModeExitReady2;
}

APDUStatus_ENUM_t2 Get_NXP_ApduExchangeState2(void)
{
	return apduExchangeStatus2;
}

/***************************************************************************************************
@param[in]  void
@return		void
@note
 - RF field OFF
***************************************************************************************************/
phStatus_t2 NXP_Field_OFF2(void)
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;

	status2 = aNfc_FieldOff2();

	return status2;
}

/***************************************************************************************************
@param[in]  void
@return		void
@note
 - RF field ON
***************************************************************************************************/
phStatus_t2 NXP_Field_ON2(void)
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;

	status2 = aNfc_FieldOn2();

	return status2;
}

/***************************************************************************************************
@param[in]  void
@return		void
@note
 - Switch to normal mode of operation. It terminates LPCD.
***************************************************************************************************/
phStatus_t2 NXP_Switch_Mode_Normal2(void)
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;

	status2 = aNfc_SwitchModeNormal2();

	return status2;
}

/***************************************************************************************************
@param[in]  phStatus_t2
- NFC Communication Errors
@return     void
@note
- Get NFC Communication Errors
- Error Count SUM
***************************************************************************************************/
void Get_NXP_NFC_CommunicationErrors2(phStatus_t2 status2)
{
	NFC_CommunicationError2 = status2;

	switch(NFC_CommunicationError2)
	{
		case PH_ERR_IO_TIMEOUT2:
		case PH_ERR_INTEGRITY_ERROR2:
		case PH_ERR_COLLISION_ERROR2:
		case PH_ERR_BUFFER_OVERFLOW2:
		case PH_ERR_FRAMING_ERROR2:
		case PH_ERR_PROTOCOL_ERROR2:
		case PH_ERR_AUTH_ERROR2:
		case PH_ERR_READ_WRITE_ERROR2:
		case PH_ERR_TEMPERATURE_ERROR2:
		case PH_ERR_RF_ERROR2:
		case PH_ERR_INTERFACE_ERROR2:
		case PH_ERR_LENGTH_ERROR2:
		case PH_ERR_RESOURCE_ERROR2:
		case PH_ERR_TX_NAK_ERROR2:
		case PH_ERR_RX_NAK_ERROR2:
		case PH_ERR_EXT_RF_ERROR2:
		case PH_ERR_NOISE_ERROR2:
		case PH_ERR_ABORTED2:
		case PH_ERR_LPCD_ABORTED2:
		case PH_ERR_INTERNAL_ERROR2:
		case PH_ERR_AUTH_DELAY2:
			NFC_CommErr_Cnt2++;
			break;
		default:
			break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     uint8
 - NXP_OFF2(0)	: No Error
 - NXP_ON2(1)	: Error
@note
- NFC Communication Errors 검출 여부를 리턴한다.
***************************************************************************************************/
uint8 Get_NXP_NFC_CommunicationErrorsCheck2(void)
{
	uint8 ret_val2;

	if(NFC_CommErr_Cnt2 > 0U)
	{
		ret_val2 = NXP_ON2;
	}
	else
	{
		ret_val2 = NXP_OFF2;
	}

	NFC_CommErr_Cnt2 = 0U;

	return ret_val2;
}

/***************************************************************************************************
@param[in]  void
@return     phStatus_t2
 - NFC_CommunicationError : Communication Errors
@note
- NFC Communication Errors Status를 리턴한다.
***************************************************************************************************/
phStatus_t2 Get_NXP_NFC_CommunicationErrorsStatus2(void)
{
	return NFC_CommunicationError2;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
- Reset NFC Communication Errors Status
- Reset NFC Communication Errors Count
***************************************************************************************************/
void Reset_NXP_NFC_CommunicationErrors2(void)
{
	NFC_CommunicationError2 = PH_ERR_SUCCESS2;
	NFC_CommErr_Cnt2 = 0U;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
- Reset NFC Communication Errors Status
- Reset NFC Communication Errors Count
***************************************************************************************************/
// uint16_t NXP_CardProtection_MainControl_Init2(void)
// {
// 	uint16_t ret_val2;
// 	//	ret_val2 = detune_meas_reference2();
//     // PH_CHECK_INPROCESS_FCT_REDUCE2(ret_val2, detune_meas_reference2());

// 	// DIST_STATE_s2 = DIST_ST_IDLE2;

// 	return ret_val2;
// }


/***************************************************************************************************
@param[in]  void
@return     void
@note
- Reset NFC Communication Errors Status
- Reset NFC Communication Errors Count
***************************************************************************************************/
// uint8_t NXP_CardProtection_MainControl2(void)
uint16_t NXP_CardProtection_MainControl2(void)
{
	DIST_RESULT_t2 ret_val2;

	// ret_val2 = Dist_run2();
	ret_val2 = Dist_run_CleanSurface2();

	return ret_val2;
}


/******************************************************************************
 **                            End Of File
 ******************************************************************************/
