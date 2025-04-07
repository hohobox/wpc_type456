/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2021
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

#ifndef INTFS_NFCRDLIB2_DETECT_CARD_H
#define INTFS_NFCRDLIB2_DETECT_CARD_H

#include <ph_Status2.h>
#include <phApp_Init2.h>

/**< Guard time configuration for Type V poll in Micro seconds.*/
#define PH_MAX_EXECUTED_DISCLOOP                                              6U

typedef enum
{
    ANFC_APDU_SELECT_AID2 = 0,
    ANFC_APDU_GET_VERSION2,
    ANFC_APDU_FINISH2
} ANFC_APDU_StateType_t2;

typedef enum
{
    ANFC_STATE_IDLE2 = 0,
    ANFC_STATE_LPCD_CONFIG2,
    ANFC_STATE_LPCD_DETECT2,
    ANFC_STATE_GDTCONFIG2,
    ANFC_STATE_FIELD_ON2,
    ANFC_STATE_APPLY_PROTO_TYPE_A2,
    ANFC_STATE_DETECTING_TYPE_A2,
    ANFC_STATE_VASUPA2,
    ANFC_STATE_ACTIVATECARD2,
    ANFC_STATE_ACTIVATED_N_WAIT2,
    ANFC_STATE_DATA_EXCHANGE2,
	ANFC_STATE_PAUSE2,
    ANFC_STATE_FINISH2
} ANFC_MAIN_StateType_t2;

typedef enum
{
	NO_CARD2 = 0,
	CARD_DETECTED2 = 1,
	CARD_DETECTING2 = 2,
	DEFAULT_STATE2 = 3
} ANFC_Card_detection_StateType_t2;

// FUNC(void, ANFCRL_CODE) BasicDiscoveryLoop_Task2(
//     P2VAR(phApp_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2);

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_Idle2(VAR(bool, ANFCRL_VAR) enable_lpcd2);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_LpcdConfig2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_LpcdDetect2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_ApplyProtocolSetting2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_FieldOnState2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_DetectingCard2(VAR(bool, ANFCRL_VAR) detectCardOnly2);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_VasupA2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_ActivateCard2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_Activated_N_Wait2(void);
FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_DataExchange2(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer2, VAR(uint16, ANFCRL_VAR) length2);


FUNC(phStatus_t2, ANFCRL_CODE) aNfcRdLib_Init_Platform_Init2(void);
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) aNfcRdLib_Init_Ncx3321_Init2(void);
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) aNfcRdLib_Init_Component_Init2(void);
FUNC(phStatus_t2, ANFCRL_CODE) aNfcRdLib_Init_Task_Init2(void);

FUNC(phStatus_t2, ANFCRL_CODE) aNfcRdLib_Rf_Config_Init2(void);
FUNC(void, ANFCRL_CODE) aNfcRdLib_setCardDetection2(VAR(uint8, ANFCRL_VAR) state2);
FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getCardDetection2(void);
FUNC(uint8*, ANFCRL_CODE) aNfcRdLib_get_APDU_RxBuff2(void);
FUNC(uint8, ANFCRL_CODE) aNfcRdLib_get_APDU_RxLength2(void);
FUNC(void, ANFCRL_CODE) aNfcRdLib_setPiccOnPCD2(VAR(uint8, ANFCRL_VAR) state2);
FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getPiccOnPCD2(void);
FUNC(phStatus_t2, ANFCRL_CODE) aNfc_FieldOff2(void);
FUNC(phStatus_t2, ANFCRL_CODE) aNfc_FieldOn2(void);
FUNC(phStatus_t2, ANFCRL_CODE) aNfc_SwitchModeNormal2(void);

// CARD Protection
FUNC(void, ANFCRL_CODE) ANFCLib_Task_Init2(
        P2VAR(phApp_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2);

#endif /* INTFS_NFCRDLIB_DETECT_CARD_H */
