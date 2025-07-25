/*******************************************************************************
 * (c) NXP Semiconductors
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

#ifndef RF_CONFIG_H_
#define RF_CONFIG_H_

/* Status header */
#include <ph_Status2.h>

// EEPROM CONFIGURATION REGISTER
typedef enum {
	EEPROM_PWR_CONFIG = 0x0,
	EEPROM_VDDPALDO_CONFIG = 0x2,
	EEPROM_VDDPALDO_VDDPA_HIGH = 0x6,
	EEPROM_VDDPALDO_VDDPA_LOW = 0x7,
	EEPROM_VDDPALDO_VDDPA_MAX_RDR = 0x8,
	EEPROM_VDDPALDO_VDDPA_HIGH_MAX_CARD = 0x9,
	EEPROM_BOOST_DEFAULT_VOLTAGE = 0xA,
	EEPROM_XTAL_CONFIG = 0x10,
	EEPROM_XTAL_TIMEOUT = 0x11,
	EEPROM_CLK_INPUT_FREQ = 0x12,
	EEPROM_XTAL_CHECK_DELAY = 0x13,
	EEPROM_TEMP_WARNING = 0x14,
	EEPROM_ENABLE_GPIO0_ON_OVERTEMP = 0x16,
	EEPROM_TX_SHAPING_CONFIG = 0x17,
	EEPROM_TX_INV_RM = 0x18,
	EEPROM_TX_CLK_MODE_1 = 0x19,
	EEPROM_TX_CLK_MODE_2 = 0x1A,
	EEPROM_RESIDUAL_AMP_LEVEL_A106 = 0x22,
	EEPROM_EDGE_TYPE_A106 = 0x23,
	EEPROM_EDGE_STYLE_A106 = 0x24,
	EEPROM_EDGE_LENGTH_A106 = 0x25,
	EEPROM_RESIDUAL_AMP_LEVEL_A212 = 0x26,
	EEPROM_EDGE_TYPE_A212 = 0x27,
	EEPROM_EDGE_STYLE_A212 = 0x28,
	EEPROM_EDGE_LENGTH_A212 = 0x29,
	EEPROM_RESIDUAL_AMP_LEVEL_A424 = 0x2A,
	EEPROM_EDGE_TYPE_A424 = 0x2B,
	EEPROM_EDGE_STYLE_A424 = 0x2C,
	EEPROM_EDGE_LENGTH_A424 = 0x2D,
	EEPROM_RESIDUAL_AMP_LEVEL_A848 = 0x2E,
	EEPROM_EDGE_TYPE_A848 = 0x2F,
	EEPROM_EDGE_STYLE_A848 = 0x30,
	EEPROM_EDGE_LENGTH_A848 = 0x31,
	EEPROM_RESIDUAL_AMP_LEVEL_B106 = 0x32,
	EEPROM_EDGE_TYPE_B106 = 0x33,
	EEPROM_EDGE_STYLE_B106 = 0x34,
	EEPROM_EDGE_LENGTH_B106 = 0x35,
	EEPROM_RESIDUAL_AMP_LEVEL_B212 = 0x36,
	EEPROM_EDGE_TYPE_B212 = 0x37,
	EEPROM_EDGE_STYLE_B212 = 0x38,
	EEPROM_EDGE_LENGTH_B212 = 0x39,
	EEPROM_RESIDUAL_AMP_LEVEL_B424 = 0x3A,
	EEPROM_EDGE_TYPE_B424 = 0x3B,
	EEPROM_EDGE_STYLE_B424 = 0x3C,
	EEPROM_EDGE_LENGTH_B424 = 0x3D,
	EEPROM_RESIDUAL_AMP_LEVEL_B848 = 0x3E,
	EEPROM_EDGE_TYPE_B848 = 0x3F,
	EEPROM_EDGE_STYLE_B848 = 0x40,
	EEPROM_EDGE_LENGTH_B848 = 0x41,
	EEPROM_RESIDUAL_AMP_LEVEL_F212 = 0x42,
	EEPROM_EDGE_TYPE_F212 = 0x43,
	EEPROM_EDGE_STYLE_F212 = 0x44,
	EEPROM_EDGE_LENGTH_F212 = 0x45,
	EEPROM_RESIDUAL_AMP_LEVEL_F424 = 0x46,
	EEPROM_EDGE_TYPE_F424 = 0x47,
	EEPROM_EDGE_STYLE_F424 = 0x48,
	EEPROM_EDGE_LENGTH_F424 = 0x49,
	EEPROM_RESIDUAL_AMP_LEVEL_V100_26 = 0x4A,
	EEPROM_EDGE_TYPE_V100_26 = 0x4B,
	EEPROM_EDGE_STYLE_V100_26 = 0x4C,
	EEPROM_EDGE_LENGTH_V100_26 = 0x4D,
	EEPROM_RESIDUAL_AMP_LEVEL_V100_53 = 0x4E,
	EEPROM_EDGE_TYPE_V100_53 = 0x4F,
	EEPROM_EDGE_STYLE_V100_53 = 0x50,
	EEPROM_EDGE_LENGTH_V100_53 = 0x51,
	EEPROM_RESIDUAL_AMP_LEVEL_V100_106 = 0x52,
	EEPROM_EDGE_TYPE_V100_106 = 0x53,
	EEPROM_EDGE_STYLE_V100_106 = 0x54,
	EEPROM_EDGE_LENGTH_V100_106 = 0x55,
	EEPROM_RESIDUAL_AMP_LEVEL_V100_212 = 0x56,
	EEPROM_EDGE_TYPE_V100_212 = 0x57,
	EEPROM_EDGE_STYLE_V100_212 = 0x58,
	EEPROM_EDGE_LENGTH_V100_212 = 0x59,
	EEPROM_RESIDUAL_AMP_LEVEL_V10_26 = 0x5A,
	EEPROM_EDGE_TYPE_V10_26 = 0x5B,
	EEPROM_EDGE_STYLE_V10_26 = 0x5C,
	EEPROM_EDGE_LENGTH_V10_26 = 0x5D,
	EEPROM_RESIDUAL_AMP_LEVEL_V10_53 = 0x5E,
	EEPROM_EDGE_TYPE_V10_53 = 0x5F,
	EEPROM_EDGE_STYLE_V10_53 = 0x60,
	EEPROM_EDGE_LENGTH_V10_53 = 0x61,
	EEPROM_RESIDUAL_AMP_LEVEL_V10_106 = 0x62,
	EEPROM_EDGE_TYPE_V10_106 = 0x63,
	EEPROM_EDGE_STYLE_V10_106 = 0x64,
	EEPROM_EDGE_LENGTH_V10_106 = 0x65,
	EEPROM_RESIDUAL_AMP_LEVEL_V10_212 = 0x66,
	EEPROM_EDGE_TYPE_V10_212 = 0x67,
	EEPROM_EDGE_STYLE_V10_212 = 0x68,
	EEPROM_EDGE_LENGTH_V10_212 = 0x69,
	EEPROM_RESIDUAL_AMP_LEVEL_180003m3_tari18p88 = 0x6A,
	EEPROM_EDGE_TYPE_180003m3_tari18p88 = 0x6B,
	EEPROM_EDGE_STYLE_180003m3_tari18p88 = 0x6C,
	EEPROM_EDGE_LENGTH_180003m3_tari18p88 = 0x6D,
	EEPROM_RESIDUAL_AMP_LEVEL_180003m3_tari9p44 = 0x6E,
	EEPROM_EDGE_TYPE_180003m3_tari9p44 = 0x6F,
	EEPROM_EDGE_STYLE_180003m3_tari9p44 = 0x70,
	EEPROM_EDGE_LENGTH_180003m3_tari9p44 = 0x71,
	EEPROM_RESIDUAL_AMP_LEVEL_B_PRIME_106 = 0x72,
	EEPROM_EDGE_TYPE_B_PRIME_106 = 0x73,
	EEPROM_EDGE_STYLE_B_PRIME_106 = 0x74,
	EEPROM_EDGE_LENGTH_B_PRIME_106 = 0x75,
	EEPROM_DPC_CONFIG = 0x76,
	EEPROM_DPC_TARGET_CURRENT = 0x77,
	EEPROM_DPC_HYSTERESIS_LOADING = 0x79,
	EEPROM_DPC_HYSTERESIS_UNLOADING = 0x7C,
	EEPROM_DPC_TXLDOVDDPALow = 0x7D,
	EEPROM_DPC_TXGSN = 0x7E,
	EEPROM_DPC_RDON_Control = 0x7F,
	EEPROM_DPC_InitialRDOn_RFOn = 0x80,
	EEPROM_DPC_GUARD_TIME = 0x87,
	EEPROM_DPC_ENABLE_DURING_FDT = 0x88,
	EEPROM_DPC_GUARD_TIME_AFTER_RX = 0x89,
	EEPROM_DPC_LOOKUP_TABLE = 0x8B,
	EEPROM_ARC_CONFIG = 0x137,
	EEPROM_ARC_VDDPA = 0x139,
	EEPROM_ARC_RM_A106 = 0x13E,
	EEPROM_ARC_RM_A212 = 0x148,
	EEPROM_ARC_RM_A424 = 0x152,
	EEPROM_ARC_RM_A848 = 0x15C,
	EEPROM_ARC_RM_B106 = 0x166,
	EEPROM_ARC_RM_B212 = 0x170,
	EEPROM_ARC_RM_B424 = 0x17A,
	EEPROM_ARC_RM_B848 = 0x184,
	EEPROM_ARC_RM_F212 = 0x18E,
	EEPROM_ARC_RM_F424 = 0x198,
	EEPROM_ARC_RM_V6p6 = 0x1A2,
	EEPROM_ARC_RM_V26 = 0x1AC,
	EEPROM_ARC_RM_V53 = 0x1B6,
	EEPROM_ARC_RM_V106 = 0x1C0,
	EEPROM_ARC_RM_V212 = 0x1CA,
	EEPROM_ARC_RM_18003m3_SC424_4MAN = 0x1D4,
	EEPROM_ARC_RM_18003m3_SC424_2MAN = 0x1DE,
	EEPROM_ARC_RM_18003m3_SC848_4MAN = 0x1E8,
	EEPROM_ARC_RM_18003m3_SC848_2MAN = 0x1F2,
	EEPROM_ARC_RM_AI106 = 0x1FC,
	EEPROM_ARC_RM_AI212 = 0x206,
	EEPROM_ARC_RM_AI424 = 0x210,
	EEPROM_RF_DEBOUNCE_TIMEOUT = 0x2B2,
	EEPROM_SENSE_RES = 0x2B3,
	EEPROM_NFC_ID1 = 0x2B5,
	EEPROM_SEL_RES = 0x2B8,
	EEPROM_FELICA_POLL_RES = 0x2B9,
	EEPROM_RANDOM_UID_ENABLE = 0x2CB,
	EEPROM_MFC_AUTH_TIMEOUT = 0x2CC,
	EEPROM_RSSI_TIMER = 0x2DA,
	EEPROM_RSSI_TIMER_FIRST_PERIOD = 0x2DC,
	EEPROM_RSSI_CTRL_00_AB = 0x2DE,
	EEPROM_RSSI_NB_ENTRIES_AB = 0x2DF,
	EEPROM_RSSI_THRESHOLD_PHASE_TABLE = 0x2E0,
	EEPROM_TX_PARAM_ENTRY_TABLE = 0x3A2,

	// LPCD
	EEPROM_LPCD_AVG_SAMPLES = 0x492,
	EEPROM_LPCD_RSSI_TARGET = 0x494,
	EEPROM_LPCD_RSSI_HYST = 0x496,
	EEPROM_LPCD_CONFIG = 0x497,
	EEPROM_LPCD_THRESHOLD_COARSE = 0x49A,
	EEPROM_WAIT_RX_SETTLE = 0x4AB,
	EEPROM_LPCD_VDDPA = 0x4AF,

	// uLPCD
	EEPROM_ULPCD_VDDPA_CTRL = 0x4BF,
	EEPROM_ULPCD_TIMING_CTRL = 0x4C2,
	EEPROM_ULPCD_VOLTAGE_CTRL = 0x4C6,
	EEPROM_ULPCD_RSSI_GUARD_TIME = 0x4C9,
	EEPROM_ULPCD_RSSI_SAMPLE_CFG = 0x4CA,
	EEPROM_ULPCD_THRESH_LVL = 0x4CB,
	EEPROM_ULPCD_GPIO3 = 0x4CC,

	EEPROM_TXIRQ_GUARDTIME = 0x559,
	EEPROM_FDT_DEFAULTVAL = 0x55D,
	EEPROM_RXIRQ_GUARDTIME = 0x561,
	EEPROM_NFCLD_RFLD_Valid = 0x6D3,
	EEPROM_CurrentSensorTrimConfig = 0xABC,
	EEPROM_CORRECTION_ENTRY_TABLE = 0xBDA,
	EEPROM_RTRANS_FRTANS_TABLE = 0xC03,
	EEPROM_CFG_NOV_CAL = 0xC83,
	EEPROM_NOV_CAL_VAL1 = 0xC84,
	EEPROM_NOV_CAL_VAL2 = 0xC85,
	EEPROM_NOV_CAL_THRESHOLD = 0xC86,
	EEPROM_NOV_CAL_OFFSET1 = 0xC87,
	EEPROM_NOV_CAL_OFFSET2 = 0xC8B,
	EEPROM_VDDPA_DISCHARGE = 0xC8F,
	EEPROM_ARC_RM_A106_FDT = 0xC9D,
	EEPROM_Tx_Symbol23_Mod_Reg_BR_53 = 0xCC5,
	EEPROM_Tx_Data_Mod_Reg_BR_53 = 0xCC9,
	EEPROM_Tx_Symbol23_Mod_Reg_BR_106 = 0xCCD,
	EEPROM_Tx_Data_Mod_Reg_BR_106 = 0xCD1,
	EEPROM_Tx_Symbol23_Mod_Reg_BR_212 = 0xCD5,
	EEPROM_Tx_Data_Mod_Reg_BR_212 = 0xCD9
} ADDRESSES_t2;

phStatus_t2 ncx3321_LPCD_init2(void); // Dual

#endif /* RF_CONFIG_H_ */
