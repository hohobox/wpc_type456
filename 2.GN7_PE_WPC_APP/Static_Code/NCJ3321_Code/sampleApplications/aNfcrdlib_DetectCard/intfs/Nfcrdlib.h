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

#ifndef NFCRDLIB_H
#define NFCRDLIB_H

// Common header
#include <ph_Status.h>

// Detect Card
#include <Nfcrdlib_Detect_Card.h>

// Card Protection
#include "distinguishing.h"
// #include "detune_meas.h"

typedef enum
{
	NXP_OFF = 0,
	NXP_ON = 1,
	NXP_ERR = 0xFF
} ERRORStatus_ENUM_t;

typedef enum
{
	PICC_STATE_INIT = 0,
	PICC_STATE_ON = 1
} PICCStatus_ENUM_t;

typedef enum
{
	APDU_None = 0,
	APDU_Send = 1,
	APDU_Receive = 2
} APDUStatus_ENUM_t;

phStatus_t NXP_NfcRdLib_Init(void);

void NXP_LPCD_MainControl(void);
void NXP_LPCD_MainControl_Init(void);
uint8 Get_NXP_LPCD_WakeupCheck(void);
phStatus_t NXP_NFC_MainControl(uint8 dataExchange, uint8* pTxBuff, uint16 length);
void NXP_NFC_MainControl_Init(void);
uint8 Get_NXP_NFC_DetectCheck(void);
uint8 Get_NXP_NFC_DataExchangeCheck(void);
uint8 * Get_NXP_NFC_CanTpTxBuf(void);
uint8 Get_NXP_NFC_CanTpTxSize(void);
phStatus_t NXP_PICC_MainControl(void);
void NXP_PICC_MainControl_Init(void);
uint8 Get_NXP_PICC_OnThePad(void);
void Set_NXP_PICC_OnThePad(uint8 PiccState);
phStatus_t NXP_Field_OFF(void);
phStatus_t NXP_Field_ON(void);
phStatus_t NXP_Switch_Mode_Normal(void);
uint8 Get_NXP_NfcModeExitReady(void);
APDUStatus_ENUM_t Get_NXP_ApduExchangeState(void);

/* 230503. JJH. NFC Communication Error */
void Get_NXP_NFC_CommunicationErrors(phStatus_t status);
uint8 Get_NXP_NFC_CommunicationErrorsCheck(void);
phStatus_t Get_NXP_NFC_CommunicationErrorsStatus(void);
void Reset_NXP_NFC_CommunicationErrors(void);
/* 230503. JJH. NFC Communication Error */

// uint16_t NXP_CardProtection_MainControl_Init(void);
// uint8_t NXP_CardProtection_MainControl(void);
uint16_t NXP_CardProtection_MainControl(void);

#endif /* NFCRDLIB_H */
