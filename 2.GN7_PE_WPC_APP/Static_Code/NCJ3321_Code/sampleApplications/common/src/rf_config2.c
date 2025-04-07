/*******************************************************************************
 * (c) NXP B.V. 2022
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
#include <phApp_Init2.h>
#include <rf_config2.h>
#include <phhalHw_Ncx3321_Instr2.h>
#include <phhalHw_Ncx3321_Reg2.h>
//#include "EcuInfo.h"
//#include "App_NFC.h"

//#define READ_ALL_EEPROM
//#define UPDATE_COMMON_SETTING
//#define UPDATE_LPCD_SETTING
//#define UPDATE_ULPCD_SETTING



#define DATA_LEN_1    0x01
#define DATA_LEN_2    0x02
#define DATA_LEN_3    0x03
#define DATA_LEN_4    0x04

static int math_pow2(int base2, int exponent2);

#define VDDPA_HIGH_VALUE            0x020 // 0x00=1.5V, 0x12=3.3V, 0x20=4.7V, 0x23=5.0V		// WPC_471_01 // WPC_469_01

/****************************** LPCD mode ******************************/
static phStatus_t2 ncx3321_read_LPCD_config2(void);

#define LPCD_RSSI_TARGET            0x0150 // 0x000 ~ 0xFFF
#define LPCD_AVG_SAMPLE_NUM         6 // 0~6 : in power of 2 (6: 2^6=64 samples). See LPCD_AVG_SAMPLES
#define LPCD_VDDPA                  0x0C // 1.5 ~ 2.7V	/* NXP Module 230208 */
#define LPCD_PULSE_WIDTH            5 // Pulse width of LPCD = LPCD_PULSE_WIDTH + 20 (offset)
#define LPCD_THRESHOLD_I			120 // LPCD_THRESHOLD_COARSE 0~1 bytes	// WPC_465_02
#define LPCD_THRESHOLD_Q			120 // LPCD_THRESHOLD_COARSE 2~3 btyes	// WPC_465_02
/*
The LPCD_THRESHOLD_COARSE must be defined in combination with the LPCD_AVG_SAMPLES

LPCD_AVG_SAMPLES
Value|I/Q range| typical threshold
  0  | ±30,000 |  3200
  1  | ±16,000 |  1600
  2  | ± 8,000 |   800
  3  | ± 4,000 |   400
  4  | ± 2,000 |   200
  5  | ± 1,000 |   100
  6  | ±   500 |    50
*/

static uint8_t eeprom_buf2[4];

/*
* This function initializes LPCD and  configuration.
*/
phStatus_t2 ncx3321_LPCD_init2(void)
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;
#if 0
	phhalHw_Ncx3321_Version_t ver;

	phhalHw_Ncx3321_Instr_GetVersion(pHal2, &ver);
	DEBUG_PRINTF2("Chip Info: HW ver = 0x%02X, ROM ver = 0x%02X, FW ver = 0x%04X\n",
		ver.bHw_Version, ver.bROM_Version, ver.wFW_Version);
#endif

	math_pow2(0, 0); // to remove compile warning

	PH_CHECK_INPROCESS_FCT2(status2, ncx3321_read_LPCD_config2());

	return status2;
}


/*
* Read LPCD EEPROM config
*/
#ifndef DEBUG_TUNE_LPCD_USE	/* Debug Tune LPCD Parameters */

static phStatus_t2 ncx3321_read_LPCD_config2(void)
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;
	static uint8_t lpcd_init_state2 = 0;
#if 1	/* NXP Module 230217 *//* NXP Module 230208 */
	uint8_t rssi_low2 = 0x00;
	uint8_t rssi_high2 = 0x00;
#endif	/* NXP Module 230217 *//* NXP Module 230208 */

	DEBUG_PRINTF2("\n<<< Read and Check LPCD configuration >>>\n");	/* NXP Module 230208 */

	if (lpcd_init_state2 == 0)
	{
#if 0
		/**************************************************************************************************/
		/* 8.25.151 LPCD_AVG_SAMPLES (0492h) - Defining how many samples of the I and Q values are used   */
		/*                                     for the averaging.                                         */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_LPCD_AVG_SAMPLES, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD_AVG_SAMPLES = 0x%02X, %d samples\n", EEPROM_LPCD_AVG_SAMPLES, eeprom_buf2[0], math_pow2(2, (int)eeprom_buf2[0]));

		if (eeprom_buf2[0] != LPCD_AVG_SAMPLE_NUM) {
			eeprom_buf2[0] = LPCD_AVG_SAMPLE_NUM;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_AVG_SAMPLES, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD_AVG_SAMPLES = 0x%02X, %d samples\n", eeprom_buf2[0], math_pow2(2, (int)eeprom_buf2[0]));
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.152 LPCD_RSSI_TARGET (0494h) - Value to be set in register DGRM_RSSI_REG_DGRM_RSSI_TARGET */
		/*									  it is recommended to use and not change the default settings*/
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_LPCD_RSSI_TARGET, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		rssi_low2 = eeprom_buf2[0];
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)(EEPROM_LPCD_RSSI_TARGET+1), eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		rssi_high2 = eeprom_buf2[0];
		DEBUG_PRINTF2("0x%04X LPCD_RSSI_TARGET = 0x%02X%02X\n", EEPROM_LPCD_RSSI_TARGET, rssi_high2, rssi_low2);

		if (rssi_low2 != (uint8_t)(LPCD_RSSI_TARGET&0x00FF) || rssi_high2 != (uint8_t)((LPCD_RSSI_TARGET&0xFF00)>>8)) {

			rssi_low2 = (uint8_t)(LPCD_RSSI_TARGET&0x00FF);
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_RSSI_TARGET, &rssi_low2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);

			rssi_high2 = (uint8_t)((LPCD_RSSI_TARGET&0xFF00)>>8);
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, (EEPROM_LPCD_RSSI_TARGET+1), &rssi_high2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD RSSI Target = 0x%02X%02X\n", rssi_high2, rssi_low2);
		}
		else
		{
			// If LPCD_RSSI_TARGET has been already set then Stop lpcd configuration.
			// Because other values have been set as well.
			// return status2;	// WPC_465_02
		}
#endif


#if 1
		/**************************************************************************************************/
		/* 8.25.155 LPCD_THRESHOLD_COARSE (049Ah) - LPCD I/Q channel threshold                            */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_LPCD_THRESHOLD_COARSE, eeprom_buf2, DATA_LEN_4);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD_THRESHOLD_COARSE = 0x%02X%02X%02X%02X, I-channel=%d, Q-channel=%d\n",
				EEPROM_LPCD_THRESHOLD_COARSE, eeprom_buf2[3], eeprom_buf2[2], eeprom_buf2[1], eeprom_buf2[0], (int)(eeprom_buf2[1]*256 + eeprom_buf2[0]), (int)(eeprom_buf2[3]*256 + eeprom_buf2[2]));

		if ((eeprom_buf2[3]!=LPCD_THRESHOLD_I/256 || eeprom_buf2[2]!=LPCD_THRESHOLD_I%256) ||
			(eeprom_buf2[1]!=LPCD_THRESHOLD_Q/256 || eeprom_buf2[0]!=LPCD_THRESHOLD_Q%256)) {
			eeprom_buf2[3] = LPCD_THRESHOLD_I/256; // I-Channel
			eeprom_buf2[2] = LPCD_THRESHOLD_I%256;
			eeprom_buf2[1] = LPCD_THRESHOLD_Q/256; // Q-Channel
			eeprom_buf2[0] = LPCD_THRESHOLD_Q%256;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_THRESHOLD_COARSE, eeprom_buf2, DATA_LEN_4);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD Threshold = 0x%02X%02X%02X%02X, I-channel=%d, Q-channel=%d\n",
				eeprom_buf2[3], eeprom_buf2[2], eeprom_buf2[1], eeprom_buf2[0], LPCD_THRESHOLD_I, LPCD_THRESHOLD_Q);
		}
#endif
		lpcd_init_state2 = 1;
		return PH_STATUS_INPROCESS2;
	}
	else
	{
#if 1
		/**************************************************************************************************/
		/* 8.25.156 WAIT_RX_SETTLE (04ABh) - Delay between Field-On and starting ADC data averaging for   */
		/*                                   the LPCD                                                     */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_WAIT_RX_SETTLE, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD pulse width = 0x%02X, %dus\n",EEPROM_WAIT_RX_SETTLE, eeprom_buf2[0], (eeprom_buf2[0]+20));

		if (eeprom_buf2[0]!=LPCD_PULSE_WIDTH) {
			eeprom_buf2[0] = LPCD_PULSE_WIDTH;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_WAIT_RX_SETTLE, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD pulse width = 0x%02X, %dus\n", eeprom_buf2[0], (eeprom_buf2[0]+20));
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.157 LPCD_VDDPA (04AFh) - VDDPA voltage during LPCD                                        */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, EEPROM_LPCD_VDDPA, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD_VDDPA = 0x%02X, %d.%dV\n", EEPROM_LPCD_VDDPA, eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);

		// Nidec VDDPA range is 1.5V to 2.7V. (VBAT is 3V and MAX VDDPA is 2.7V due to 0.3V drop)
		if (eeprom_buf2[0] != LPCD_VDDPA) { // Check whether VDDPA is LPCD_VDDPA
			eeprom_buf2[0] = LPCD_VDDPA;

			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_VDDPA, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD VDDPA = 0x%02X, %d.%dV\n", eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.102 DPC_CONFIG (0076h) - DPC Configuration												  */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, EEPROM_DPC_CONFIG, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X DPC_CONFIG = 0x%02X, %s\n", EEPROM_DPC_CONFIG, eeprom_buf2[0], ((eeprom_buf2[0] & 0x01) ? "enabled" : "disabled"));

		if ((eeprom_buf2[0] & 0x01))
		{
			eeprom_buf2[0] = 0x70;
			do
			{
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2( pHal2, EEPROM_DPC_CONFIG, eeprom_buf2, DATA_LEN_1);
			} while(status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write DPC_CONFIG = 0x%02X, disable\n", eeprom_buf2[0]);
		}
#endif

#if 1
		// WPC_469_01
		/**************************************************************************************************/
		/* 8.25.4 TXLDO_VDDPA_HIGH (0006h) - TX_LDO output: initial voltage in case the DPC is used.      */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_VDDPALDO_VDDPA_HIGH, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X VDDPALDO_VDDPA_HIGH = 0x%02X, %d.%dV\n", EEPROM_VDDPALDO_VDDPA_HIGH, eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);

		if (eeprom_buf2[0] != VDDPA_HIGH_VALUE) { // check VDDPA_HIGH_VALUE
			eeprom_buf2[0] = VDDPA_HIGH_VALUE;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_VDDPALDO_VDDPA_HIGH, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write VDDPALDO_VDDPA_HIGH = 0x%02X, %d.%dV\n", eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);
		}
		// WPC_469_01
#endif
	}

	lpcd_init_state2 = 0;
	return status2;
}

#else	/* Debug Tune LPCD Parameters */
static phStatus_t2 ncx3321_read_LPCD_config(void)
{
	phStatus_t2 status2 = PH_ERR_SUCCESS2;
	static uint8_t lpcd_init_state2 = 0;
#if 1	/* NXP Module 230217 *//* NXP Module 230208 */
	uint8_t rssi_low2 = 0x00;
	uint8_t rssi_high2 = 0x00;
#endif	/* NXP Module 230217 *//* NXP Module 230208 */

	DEBUG_PRINTF2("\n<<< Read and Check LPCD configuration >>>\n");	/* NXP Module 230208 */

	if (lpcd_init_state2 == 0)
	{
#if 0
		/**************************************************************************************************/
		/* 8.25.151 LPCD_AVG_SAMPLES (0492h) - Defining how many samples of the I and Q values are used   */
		/*                                     for the averaging.                                         */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_LPCD_AVG_SAMPLES, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD_AVG_SAMPLES = 0x%02X, %d samples\n", EEPROM_LPCD_AVG_SAMPLES, eeprom_buf2[0], math_pow2(2, (int)eeprom_buf2[0]));

		if (eeprom_buf2[0] != Tune_LPCD_AVG_SAMPLE_NUM) {
			eeprom_buf2[0] = Tune_LPCD_AVG_SAMPLE_NUM;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_AVG_SAMPLES, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD_AVG_SAMPLES = 0x%02X, %d samples\n", eeprom_buf2[0], math_pow2(2, (int)eeprom_buf2[0]));
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.152 LPCD_RSSI_TARGET (0494h) - Value to be set in register DGRM_RSSI_REG_DGRM_RSSI_TARGET */
		/*									  it is recommended to use and not change the default settings*/
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_LPCD_RSSI_TARGET, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		rssi_low2 = eeprom_buf2[0];
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)(EEPROM_LPCD_RSSI_TARGET+1), eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		rssi_high2 = eeprom_buf2[0];
		DEBUG_PRINTF2("0x%04X LPCD_RSSI_TARGET = 0x%02X%02X\n", EEPROM_LPCD_RSSI_TARGET, rssi_high2, rssi_low2);

		if (rssi_low2 != (uint8_t)(Tune_LPCD_RSSI_TARGET&0x00FF) || rssi_high2 != (uint8_t)((Tune_LPCD_RSSI_TARGET&0xFF00)>>8)) {

			rssi_low2 = (uint8_t)(Tune_LPCD_RSSI_TARGET&0x00FF);
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_RSSI_TARGET, &rssi_low2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);

			rssi_high2 = (uint8_t)((Tune_LPCD_RSSI_TARGET&0xFF00)>>8);
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, (EEPROM_LPCD_RSSI_TARGET+1), &rssi_high2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD RSSI Target = 0x%02X%02X\n", rssi_high2, rssi_low2);
		}
		else
		{
			// If LPCD_RSSI_TARGET has been already set then Stop lpcd configuration.
			// Because other values have been set as well.
			// return status2;	// WPC_465_02
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.155 LPCD_THRESHOLD_COARSE (049Ah) - LPCD I/Q channel threshold                            */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_LPCD_THRESHOLD_COARSE, eeprom_buf2, DATA_LEN_4);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD_THRESHOLD_COARSE = 0x%02X%02X%02X%02X, I-channel=%d, Q-channel=%d\n",
				EEPROM_LPCD_THRESHOLD_COARSE, eeprom_buf2[3], eeprom_buf2[2], eeprom_buf2[1], eeprom_buf2[0], (int)(eeprom_buf2[1]*256 + eeprom_buf2[0]), (int)(eeprom_buf2[3]*256 + eeprom_buf2[2]));

		if ((eeprom_buf2[3]!=Tune_LPCD_THRESHOLD_I/256 || eeprom_buf2[2]!=Tune_LPCD_THRESHOLD_I%256) ||
			(eeprom_buf2[1]!=Tune_LPCD_THRESHOLD_Q/256 || eeprom_buf2[0]!=Tune_LPCD_THRESHOLD_Q%256)) {
			eeprom_buf2[3] = Tune_LPCD_THRESHOLD_I/256; // I-Channel
			eeprom_buf2[2] = Tune_LPCD_THRESHOLD_I%256;
			eeprom_buf2[1] = Tune_LPCD_THRESHOLD_Q/256; // Q-Channel
			eeprom_buf2[0] = Tune_LPCD_THRESHOLD_Q%256;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_THRESHOLD_COARSE, eeprom_buf2, DATA_LEN_4);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD Threshold = 0x%02X%02X%02X%02X, I-channel=%d, Q-channel=%d\n",
				eeprom_buf2[3], eeprom_buf2[2], eeprom_buf2[1], eeprom_buf2[0], Tune_LPCD_THRESHOLD_I, Tune_LPCD_THRESHOLD_Q);
		}
#endif
		lpcd_init_state2 = 1;
		return PH_STATUS_INPROCESS2;
	}
	else
	{
#if 1
		/**************************************************************************************************/
		/* 8.25.156 WAIT_RX_SETTLE (04ABh) - Delay between Field-On and starting ADC data averaging for   */
		/*                                   the LPCD                                                     */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_WAIT_RX_SETTLE, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD pulse width = 0x%02X, %dus\n",EEPROM_WAIT_RX_SETTLE, eeprom_buf2[0], (eeprom_buf2[0]+20));

		if (eeprom_buf2[0]!=Tune_LPCD_PULSE_WIDTH) {
			eeprom_buf2[0] = Tune_LPCD_PULSE_WIDTH;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_WAIT_RX_SETTLE, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD pulse width = 0x%02X, %dus\n", eeprom_buf2[0], (eeprom_buf2[0]+20));
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.157 LPCD_VDDPA (04AFh) - VDDPA voltage during LPCD                                        */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, EEPROM_LPCD_VDDPA, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X LPCD_VDDPA = 0x%02X, %d.%dV\n", EEPROM_LPCD_VDDPA, eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);

		// Nidec VDDPA range is 1.5V to 2.7V. (VBAT is 3V and MAX VDDPA is 2.7V due to 0.3V drop)
		if (eeprom_buf2[0] != Tune_LPCD_VDDPA) { // Check whether VDDPA is LPCD_VDDPA
			eeprom_buf2[0] = Tune_LPCD_VDDPA;

			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_LPCD_VDDPA, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write LPCD VDDPA = 0x%02X, %d.%dV\n", eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);
		}
#endif

#if 1
		/**************************************************************************************************/
		/* 8.25.102 DPC_CONFIG (0076h) - DPC Configuration												  */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, EEPROM_DPC_CONFIG, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X DPC_CONFIG = 0x%02X, %s\n", EEPROM_DPC_CONFIG, eeprom_buf2[0], ((eeprom_buf2[0] & 0x01) ? "enabled" : "disabled"));

		if ((eeprom_buf2[0] & 0x01))
		{
			eeprom_buf2[0] = 0x70;
			do
			{
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2( pHal2, EEPROM_DPC_CONFIG, eeprom_buf2, DATA_LEN_1);
			} while(status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write DPC_CONFIG = 0x%02X, disable\n", eeprom_buf2[0]);
		}
#endif

#if 1
		// WPC_469_01
		/**************************************************************************************************/
		/* 8.25.4 TXLDO_VDDPA_HIGH (0006h) - TX_LDO output: initial voltage in case the DPC is used.      */
		/**************************************************************************************************/
		memset(eeprom_buf2, 0x00, 4);
		do {
			status2 = phhalHw_Ncx3321_Instr_ReadE2Prom2(pHal2, (uint16_t)EEPROM_VDDPALDO_VDDPA_HIGH, eeprom_buf2, DATA_LEN_1);
		} while (status2 == PH_STATUS_INPROCESS2);
		DEBUG_PRINTF2("0x%04X VDDPALDO_VDDPA_HIGH = 0x%02X, %d.%dV\n", EEPROM_VDDPALDO_VDDPA_HIGH, eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);

		if (eeprom_buf2[0] != Tune_VDDPA_HIGH_VALUE) { // check VDDPA_HIGH_VALUE
			eeprom_buf2[0] = Tune_VDDPA_HIGH_VALUE;
			do {
				status2 = phhalHw_Ncx3321_Instr_WriteE2Prom2(pHal2, EEPROM_VDDPALDO_VDDPA_HIGH, eeprom_buf2, DATA_LEN_1);
			} while (status2 == PH_STATUS_INPROCESS2);
			DEBUG_PRINTF2("\t\t>>> Write VDDPALDO_VDDPA_HIGH = 0x%02X, %d.%dV\n", eeprom_buf2[0], (eeprom_buf2[0]+15)/10, (eeprom_buf2[0]+15)%10);
		}
		// WPC_469_01
#endif
	}

	lpcd_init_state2 = 0;
	return status2;
} /* Debug Tune LPCD Parameters */

#endif


/*****************************************/
/*           Utility Functions           */
/*****************************************/
static int math_pow2(int base2, int exponent2)
{
	int i, result;

	result = 1;
	for (i = 0 ; i < exponent2 ; i++)
		result = result * base2;

	return result;
}
