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

#ifndef INTFS_NFCRDLIB_DETECT_CARD_H
#define INTFS_NFCRDLIB_DETECT_CARD_H

#include <ph_Status.h>
#include <phApp_Init.h>

/**< Guard time configuration for Type V poll in Micro seconds.*/
#define PH_MAX_EXECUTED_DISCLOOP                                              6U

typedef enum
{
    ANFC_APDU_SELECT_AID = 0,
    ANFC_APDU_GET_VERSION,
    ANFC_APDU_FINISH
} ANFC_APDU_StateType_t;

typedef enum
{
    ANFC_STATE_IDLE = 0,
    ANFC_STATE_LPCD_CONFIG,
    ANFC_STATE_LPCD_DETECT,
    ANFC_STATE_GDTCONFIG,
    ANFC_STATE_FIELD_ON,
    ANFC_STATE_APPLY_PROTO_TYPE_A,
    ANFC_STATE_DETECTING_TYPE_A,
    ANFC_STATE_VASUPA,
    ANFC_STATE_ACTIVATECARD,
    ANFC_STATE_ACTIVATED_N_WAIT,
    ANFC_STATE_DATA_EXCHANGE,
	ANFC_STATE_PAUSE,
    ANFC_STATE_FINISH
} ANFC_MAIN_StateType_t;

typedef enum
{
	NO_CARD = 0,
	CARD_DETECTED = 1,
	CARD_DETECTING = 2,
	DEFAULT_STATE = 3
} ANFC_Card_detection_StateType_t;

// FUNC(void, ANFCRL_CODE) BasicDiscoveryLoop_Task(
//     P2VAR(phApp_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_Idle(VAR(bool, ANFCRL_VAR) enable_lpcd);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_LpcdConfig(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_LpcdDetect(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_ApplyProtocolSetting(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_FieldOnState(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_DetectingCard(VAR(bool, ANFCRL_VAR) detectCardOnly);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_VasupA(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_ActivateCard(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_Activated_N_Wait(void);
FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_DataExchange(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer, VAR(uint16, ANFCRL_VAR) length);


FUNC(phStatus_t, ANFCRL_CODE) aNfcRdLib_Init_Platform_Init(void);
FUNC(phNfcLib_Status_t, ANFCRL_CODE) aNfcRdLib_Init_Ncx3321_Init(void);
FUNC(phNfcLib_Status_t, ANFCRL_CODE) aNfcRdLib_Init_Component_Init(void);
FUNC(phStatus_t, ANFCRL_CODE) aNfcRdLib_Init_Task_Init(void);

FUNC(phStatus_t, ANFCRL_CODE) aNfcRdLib_Rf_Config_Init(void);
FUNC(void, ANFCRL_CODE) aNfcRdLib_setCardDetection(VAR(uint8, ANFCRL_VAR) state);
FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getCardDetection(void);
FUNC(uint8*, ANFCRL_CODE) aNfcRdLib_get_APDU_RxBuff(void);
FUNC(uint8, ANFCRL_CODE) aNfcRdLib_get_APDU_RxLength(void);
FUNC(void, ANFCRL_CODE) aNfcRdLib_setPiccOnPCD(VAR(uint8, ANFCRL_VAR) state);
FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getPiccOnPCD(void);
FUNC(phStatus_t, ANFCRL_CODE) aNfc_FieldOff(void);
FUNC(phStatus_t, ANFCRL_CODE) aNfc_FieldOn(void);
FUNC(phStatus_t, ANFCRL_CODE) aNfc_SwitchModeNormal(void);

// CARD Protection
FUNC(void, ANFCRL_CODE) ANFCLib_Task_Init(
        P2VAR(phApp_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

#endif /* INTFS_NFCRDLIB_DETECT_CARD_H */
