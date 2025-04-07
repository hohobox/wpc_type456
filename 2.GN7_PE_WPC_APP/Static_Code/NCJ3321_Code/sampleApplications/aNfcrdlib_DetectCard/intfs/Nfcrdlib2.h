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

#ifndef NFCRDLIB2_H
#define NFCRDLIB2_H

// Common header
#include <ph_Status2.h>

// Detect Card
#include <Nfcrdlib_Detect_Card2.h>

// Card Protection
#include "distinguishing2.h"
// #include "detune_meas2.h"


typedef enum
{
	NXP_OFF2 = 0,
	NXP_ON2 = 1,
	NXP_ERR2 = 0xFF
} ERRORStatus_ENUM_t2;

typedef enum
{
	PICC_STATE_INIT2 = 0,
	PICC_STATE_ON2 = 1
} PICCStatus_ENUM_t2;

typedef enum
{
	APDU_None2 = 0,
	APDU_Send2 = 1,
	APDU_Receive2 = 2
} APDUStatus_ENUM_t2;

phStatus_t2 NXP_NfcRdLib_Init2(void);

void NXP_LPCD_MainControl2(void);
void NXP_LPCD_MainControl_Init2(void);
uint8 Get_NXP_LPCD_WakeupCheck2(void);
phStatus_t2 NXP_NFC_MainControl2(uint8 dataExchange2, uint8* pTxBuff2, uint16 length2);
void NXP_NFC_MainControl_Init2(void);
uint8 Get_NXP_NFC_DetectCheck2(void);
uint8 Get_NXP_NFC_DataExchangeCheck2(void);
uint8 * Get_NXP_NFC_CanTpTxBuf2(void);
uint8 Get_NXP_NFC_CanTpTxSize2(void);
phStatus_t2 NXP_PICC_MainControl2(void);
void NXP_PICC_MainControl_Init2(void);
uint8 Get_NXP_PICC_OnThePad2(void);
void Set_NXP_PICC_OnThePad2(uint8 PiccState2);
phStatus_t2 NXP_Field_OFF2(void);
phStatus_t2 NXP_Field_ON2(void);
phStatus_t2 NXP_Switch_Mode_Normal2(void);
uint8 Get_NXP_NfcModeExitReady2(void);
APDUStatus_ENUM_t2 Get_NXP_ApduExchangeState2(void);

/* 230503. JJH. NFC Communication Error */
void Get_NXP_NFC_CommunicationErrors2(phStatus_t2 status2);
uint8 Get_NXP_NFC_CommunicationErrorsCheck2(void);
phStatus_t2 Get_NXP_NFC_CommunicationErrorsStatus2(void);
void Reset_NXP_NFC_CommunicationErrors2(void);
/* 230503. JJH. NFC Communication Error */

// uint16_t NXP_CardProtection_MainControl_Init2(void);
// uint8_t NXP_CardProtection_MainControl2(void);
uint16_t NXP_CardProtection_MainControl2(void);

#endif /* NFCRDLIB_H */
