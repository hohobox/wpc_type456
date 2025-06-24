/*
 (c) NXP B.V. 2009-2021. All rights reserved.

 Disclaimer
 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any
 warranties of any kind. NXP makes no warranties to Licensee and shall not
 indemnify Licensee or hold it harmless for any reason related to the NXP
 Software/Source Code or otherwise be liable to the NXP customer. The NXP
 customer acknowledges and agrees that the NXP Software/Source Code is
 provided AS-IS and accepts all risks of utilizing the NXP Software under
 the conditions set forth according to this disclaimer.

 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING,
 BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF INTELLECTUAL PROPERTY
 RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
 SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES,
 INCLUDING WITHOUT LIMITATION, DAMAGES RESULTING OR ALLEGDED TO HAVE
 RESULTED FROM ANY DEFECT, ERROR OR OMMISSION IN THE NXP SOFTWARE/SOURCE
 CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A
 RESULT OF ANY INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY
 THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE FOR ANY INCIDENTAL,
 INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES
 (INCLUDING LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES,
 AFFILIATES, OR ANY OTHER THIRD PARTY ARISING OUT OF OR RELATED TO THE NXP
 SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGES.

 3. NXP reserves the right to make changes to the NXP Software/Sourcecode any
 time, also without informing customer.

 4. Licensee agrees to indemnify and hold harmless NXP and its affiliated
 companies from and against any claims, suits, losses, damages,
 liabilities, costs and expenses (including reasonable attorney's fees)
 resulting from Licensee's and/or Licensee customer's/licensee's use of the
 NXP Software/Source Code.

 */

/*
 * This file contains the implementation of the distinguishing2 algorithm.
 * It's abstracted and can be used for different platforms via CPAL2 layer.
 * dinstinguishing_types.h contains some data structures required in this file.
 */

#include <ph_Status2.h>
#include <phApp_Init2.h>

#include "distinguishing2.h"
#include "phApp_Init2.h"

#ifdef CPU_S32K144HFT0VLLT
#include <lpuartLog2.h>
#endif
#include "phhalHw_Ncx3321_Instr2.h"
#include "phhalHw_Ncx3321_Reg2.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef DEBUG_MSG
static CONST(uint8, ANFCRL_CONST) MAJOR_VERSION = 1;
#endif /* DEBUG_MSG */
#ifdef NXPBUILD__PH_LOG_EX2
#define LOG_MESSAGE(...)        LOG_PRINTF(__VA_ARGS__)
#endif

static VAR(DIST_RESULT_t2, ANFCRL_VAR) distIntermediateResult2 = DIST_RESULT_IN_PROGRESS2;
static bool fieldOff2 = 0;

/* used for non blocking analysis of discovered tag
 * at least non pure sw analysis should use this index2 */
static VAR(analyzeIndex_t2, ANFCRL_VAR) analyzeIndex2 = ANALYSIS_ERROR2;

/* DEVELOPER NOTE:
 * every non void CPAL2 function can return IN_PROGRESS to make sure algo is non blocking */

VAR(DistinguishingState_t2, ANFCRL_VAR) DIST_STATE_s2 = DIST_ST_RESET2;
VAR(DistinguishingLmdState_t2, ANFCRL_VAR) DIST_LMD_STATE_s2 = DIST_LMD_INIT2;
VAR(DistinguishingLmdCtsInitState_t2, ANFCRL_VAR) DIST_LMD_CTS_INIT_STATE_s2 = DIST_LMD_CTS_INIT_INITILIAZE2;
VAR(DistinguishingLmdCtsRetrieveState_t2, ANFCRL_VAR) DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_RETRIEVE_INIT2;

int32_t previous_phase2 = -1;
int32_t previous_phase_i2 = 0;
int32_t previous_phase_q2 = 0;

sint16 amp2[NUM_SAMPLES2];
sint16 i_channel2[NUM_SAMPLES2];
sint16 q_channel2[NUM_SAMPLES2];

FUNC(phStatus_t2, ANFCRL_CODE) CtsInit2(void);
// FUNC(phStatus_t2, ANFCRL_CODE) NCx3321_CFG_REG_BBA2(uint32 vDgrmBBA2);
FUNC(void, ANFCRL_CODE) NCx3321_CFG_REG_BBA2(uint32 vDgrmBBA2);	// Code Sonar

#if(CLEAN_SURFACE_CHECK2 == (STD_ON))
static VAR(cleanSurfaceCalibrateState_t2, ANFCRL_VAR) cleanSurfaceState2 = 0;

#if(CLEAN_SURFACE_CALIBRATE2 == (STD_ON))
static VAR(uint8, ANFCRL_VAR) cleanSurfaceCalibHfAtt2 = 0U;
#else
static VAR(uint8, ANFCRL_VAR) cleanSurfaceCalibHfAtt2 = 35U;
#endif
#endif

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_run_CleanSurface2(void)
{
    static VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_NO_RESULT2;
#if(CLEAN_SURFACE_CHECK2 == (STD_ON))
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) hfAtt2 = 0U;

#if(CLEAN_SURFACE_CALIBRATE2 == (STD_ON))
	if(cleanSurfaceCalibHfAtt2 == 0)
	{
		do
		{
			status2 = Dist_cleanSurfaceGetHfAtt2(&cleanSurfaceCalibHfAtt2);
		}while (status2 == PH_STATUS_INPROCESS2);

		if(status2 != PH_ERR_SUCCESS2)
		{
			result2 =  DIST_RESULT_ERROR2;
		}

		/* print calibration values */
		// CONSOLE_MESSAGE("Clean surface calibration Hf Att: %d\r\n",
				cleanSurfaceCalibHfAtt2);
	}
#endif
#endif

#if(CLEAN_SURFACE_CHECK2 == (STD_ON))
	if(result2 != DIST_RESULT_PROHIBIT2)
#endif

	{
		result2 = Dist_run2();
	}
#if(CLEAN_SURFACE_CHECK2 == (STD_ON))
	else
	{
		/* Check surface */
		status2 = Dist_cleanSurfaceGetHfAtt2(&hfAtt2);
		if(status2 == PH_STATUS_INPROCESS2)
		{
			return DIST_RESULT_IN_PROGRESS2;
		}
		else if(status2 != PH_ERR_SUCCESS2)
		{
			result2 = DIST_RESULT_ERROR2;
		}
		else
		{
			// CONSOLE_MESSAGE("Hf attenuator difference %d\r\n", (uint16)abs(cleanSurfaceCalibHfAtt - hfAtt2));
			if(abs(cleanSurfaceCalibHfAtt2 - hfAtt2) > CLEAN_SURFACE_HFATT_THRESHOLD2)
			{
				result2 = DIST_RESULT_PROHIBIT2;
				// CONSOLE_MESSAGE("Device(s) not removed since previous prohibit state\r\n");
				// CONSOLE_MESSAGE(RED("PROHIBIT CHARGING\r\n"));

#if(DEBUG_DELAY_NEXT_LOOP2 == (STD_ON))
				// CONSOLE_MESSAGE("waiting for next execution");
				// CONSOLE_MESSAGE(".");
				while (phhalHw_Wait2(pHal2, PHHAL_HW_TIME_MILLISECONDS2, 200u)
						== PH_STATUS_INPROCESS2)
				{
				}
				// CONSOLE_MESSAGE(".");
				while (phhalHw_Wait2(pHal2, PHHAL_HW_TIME_MILLISECONDS2, 200u)
						== PH_STATUS_INPROCESS2)
				{
				}
				// CONSOLE_MESSAGE(".");
				// CONSOLE_MESSAGE("\r\n\n");
#endif
			}
			else
			{
				result2 = DIST_RESULT_ALLOW2;
				// CONSOLE_MESSAGE("Device(s) removed. Surface cleared\r\n");
			}
		}
	}
#endif

	return result2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_run2(void)
{
    VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_NO_RESULT2;
#if(DEBUG_DELAY_NEXT_LOOP2 == (STD_ON))
	VAR(uint8, ANFCRL_VAR) count2;
#endif
    /* Distinguishing State Machine */
    switch (DIST_STATE_s2)
    {
        /* State RESET is only executed in case of an error */
        case DIST_ST_RESET2:
            result2 = CPAL_reset2();

            if (result2 == DIST_RESULT_RESUME2)
            {
                DIST_STATE_s2 = DIST_ST_INIT2;
            }
            // break;	/* No Braek */

        case DIST_ST_INIT2:
			/* Change the DGRM_BBA Configuration */

			/* DGRM_BBA :   FW default 0xED4D24A4,
				0x00004900	18688	 73		0		for 0dB
				0x00009200	37376	146		73		for 6dB
				0x0000DB00	56064	219		146		for 12dB
				0x00012400	74752	292		219		for 18dB
			*/
			NCx3321_CFG_REG_BBA2((uint32)(0x00004900)); // Saturation TEST

            result2 = CPAL_init2();

            /* If result2 is RESUME we continue with next step */
            if (result2 == DIST_RESULT_RESUME2)
            {
                /* Reset internal variables */
                nfcDevice2.ModeTech2 = NFC_TECH_UNKNOWN2;
                analyzeIndex2 = ANALYZE_PASSPORT2;
                fieldOff2 = FALSE;
                distIntermediateResult2 = DIST_RESULT_IN_PROGRESS2;
				DIST_STATE_s2 = DIST_ST_SCAN_ALL2;
				DIST_LMD_STATE_s2 = DIST_LMD_INIT2;
            }
            // break;	 /* No Break */

        case DIST_ST_SCAN_ALL2:
        		result2 = CPAL_scanAllTypes2();
        	 /* If result2 is RESUME we continue with next step */
			if (result2 == DIST_RESULT_RESUME2)
			{
            	/* If result2 is RESUME we continue with next step */
				DIST_STATE_s2 = DIST_ST_ANALYZE_ALL2;
			}
            else if(result2 == DIST_RESULT_ALLOW2)
            {
            	/* In case nothing was detected, clear previous phase2 shift value2 */
            	previous_phase2 = -1;
            	previous_phase_i2 = 0;
            	previous_phase_q2 = 0;
            }
            else if (result2 == DIST_RESULT_ERROR2)
			{
                /* DiscLoop failed, give it another try with LMD for Type A + B */
                if(nfcDevice2.ModeTech2 == NFC_TECH_A2 || nfcDevice2.ModeTech2 == NFC_TECH_B2)
                {
                	result2 = DIST_RESULT_RESUME2;
                	DIST_STATE_s2 = DIST_ST_LMD2;
                }
                else
                {
                	// result2 = DIST_RESULT_PROHIBIT2;
                	result2 = DIST_RESULT_ALLOW2;	/* Antenna 연결 불량 */
                }
            }
            break;

        case DIST_ST_ANALYZE_ALL2:
				result2 = Dist_analyzeResults2();

				/* If result2 is RESUME we continue with
				 * next scan depending on what we got before */
				if (result2 == DIST_RESULT_RESUME2)
				{
#if(CHECK_MULTI_TECH_SUPPORT2 == (STD_ON))
				if (nfcDevice2.ModeTech2 == NFC_TECH_A2)
				{
					DIST_STATE_s2 = DIST_ST_SCAN_BF2;

				}
				else
				{
					/* Should not happen */
					assert_msg2(FALSE, "Endpoint discovered and not classified?");
					return DIST_RESULT_ERROR2;
				}
#else
				DIST_STATE_s2 = DIST_ST_LMD2;
#endif
			}
            break;

		case DIST_ST_SCAN_BF2:
			/* Last step in the flowchart so we will end2 with a final state
			 * which is either ALLOW or INCONCLUSIVE */
			result2 = CPAL_scanTypeBF2();
			if (result2 == DIST_RESULT_RESUME2)
			{
				/* Restore previously detected endpoint */
				nfcDevice2.ModeTech2 = NFC_TECH_A2;
				DIST_STATE_s2 = DIST_ST_LMD2;
			}
			else if (result2 == DIST_RESULT_ALLOW2)
			{
				// CONSOLE_MESSAGE("Device emulating multiple technologies detected\r\n");
			}
			else if (result2 == DIST_RESULT_ERROR2)
			{
				// CONSOLE_MESSAGE("ERROR!\r\n");
			}
			break;

		case DIST_ST_LMD2:
			result2 = Dist_LMD2();
			break;

    case DIST_ST_ERROR2:
        default:
        assert_msg2(FALSE, "Unknown Distinguishing State");
        result2 = DIST_RESULT_ERROR2;
        break;
    }

    /* In case of ERROR or final state set algorithm state back to INIT */
    if ((result2 == DIST_RESULT_ALLOW2) || (result2 == DIST_RESULT_PROHIBIT2)
            || (result2 == DIST_RESULT_ERROR2))
    {
        switch (result2)
        {
            case DIST_RESULT_ALLOW2:
                // CONSOLE_MESSAGE(GRN("\t\t\t\t\tALLOW CHARGING\r\n"));
                // RGB_GREEN_ON;
                // RGB_RED_OFF;
                break;
            case DIST_RESULT_PROHIBIT2:
                // CONSOLE_MESSAGE(RED("\t\t\t\t\tPROHIBIT CHARGING\r\n"));
                // RGB_GREEN_OFF;
                // RGB_RED_ON;
                break;
            case DIST_RESULT_ERROR2:
                // CONSOLE_MESSAGE("RESULT ERROR\r\n");
                break;
            default:
                // CONSOLE_MESSAGE("Unexpected final result2\r\n");
                break;
        }
        // CONSOLE_MESSAGE("\t waiting for next execution\n");


        DIST_STATE_s2 = DIST_ST_INIT2;
    }

    return result2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_analyzeResults2(void)
{
    VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_ERROR2;

    if (fieldOff2 == FALSE)
    {
        // DEBUG_MESSAGE2("Analyze Results\r\n");

        /* Analyze the technology we discovered */
        switch (nfcDevice2.ModeTech2)
        {
            case NFC_TECH_156932:
                distIntermediateResult2 = DIST_RESULT_PROHIBIT2;
                break;

            case NFC_TECH_F2:
                distIntermediateResult2 = Dist_analyzeTypeF2();
                break;

            case NFC_TECH_A2:
                distIntermediateResult2 = Dist_analyzeTypeA2();
                break;

            case NFC_TECH_B2:
            	distIntermediateResult2 = DIST_RESULT_PROHIBIT2;
                break;

            default:
                assert_msg2(FALSE, "Unknown technology");
                distIntermediateResult2 = DIST_RESULT_ERROR2;
                break;
        }

        /* We reached a final state so we return IN_PROGRESS once again
         * to come back here again and switch off the field */
        if ((distIntermediateResult2 != DIST_RESULT_IN_PROGRESS2)
                && (distIntermediateResult2 != DIST_RESULT_ERROR2))
        {
            fieldOff2 = TRUE;
            return DIST_RESULT_IN_PROGRESS2;
        }
        else
        {
            return distIntermediateResult2;
        }
    }
    else
    {
        /* Turn off field */
        result2 = CPAL_fieldOff2();

        if ((result2 == DIST_RESULT_ERROR2) || (result2 == DIST_RESULT_IN_PROGRESS2))
        {
            return result2;
        }
        else
        {
            /* Field off done -> return previously saved state */
            return distIntermediateResult2;
        }
    }
}

uint32_t test_cnt_HaltA2 = 0;
uint32_t test_cnt_RequestA2 = 0;
uint32_t reset_cnt_RequestA2 = 0;
FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_recoverDigitalTypeA2(void)
{
	VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_RESUME2;
	phStatus_t2 status2 = 0;
	uint8_t bAtqa2 = 0;
	P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop2 = phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);

	/* Field is already on and card is activated */

	/* Send SLP_REQ */
	do
	{
		status2 = phpalI14443p3a_HaltA2(pDiscLoop2->pPal1443p3aDataParams2);
test_cnt_HaltA2++;
	} while(status2 == PH_STATUS_INPROCESS2);

	if(status2 != PH_ERR_SUCCESS2)
	{
		return DIST_RESULT_ERROR2;
	}

reset_cnt_RequestA2 = 0;
	/* Send SENS_REQ again */
	do
	{
		status2 = phpalI14443p3a_RequestA2(pDiscLoop2->pPal1443p3aDataParams2, &bAtqa2);
test_cnt_RequestA2++;
reset_cnt_RequestA2++;
	// } while(status2 == PH_STATUS_INPROCESS2);
	} while((status2 == PH_STATUS_INPROCESS2) && (reset_cnt_RequestA2 < 155));

	/* If there is a response return prohibit */
	if(status2 == PH_ERR_SUCCESS2)
	{
		// CONSOLE_MESSAGE("\r\n\tFound lost Type A endpoint.\r\n");
		result2 = DIST_RESULT_PROHIBIT2;
	}

	return result2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_analyzeTypeA2(void)
{
    DEBUG_MESSAGE2("Analyze Type A\r\n");
    VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_ERROR2;

    /* Store support for 14443-4 for further distinguishing tasks */
    switch (nfcDevice2.Protocol2)
    {
        case NFC_PROT_T1T2:
            /* There is no Card emulation for T1*/
            DEBUG_MESSAGE2("\tT1T found - PROHIBIT\r\n");
            result2 = DIST_RESULT_PROHIBIT2;
            break;

        case NFC_PROT_T2T2:
            DEBUG_MESSAGE2("\tT2T found, continue...\r\n");
            result2 = DIST_RESULT_RESUME2;
            break;

        case NFC_PROT_NFCDEP2:
            /* NFC DEP support implies card emulation */
            DEBUG_MESSAGE2("\tNFCDEP found - ALLOW\r\n");
            result2 = DIST_RESULT_ALLOW2;
            break;

        default:
            /* NFC DEP support implies card emulation */
            if (nfcDevice2.Interface2 == NFC_INTF_NFC_DEP2)
            {
                DEBUG_MESSAGE2("\tNFCDEP found - ALLOW\r\n");
                result2 = DIST_RESULT_ALLOW2;
                break;
            }

            /* non pure software analysis -> use non blocking index2 */
            switch (analyzeIndex2)
            {
                case ANALYZE_PASSPORT2:
                    result2 = CPAL_hasPassportAID2();
                    /* In progress or prohibit */
                    if (result2 == DIST_RESULT_RESUME2)
                    {
                        /* Resume -> no decision can be made
                         * Continue with next analyze step */
                        analyzeIndex2 = ANALYZE_PATTERNS2;
                        // CONSOLE_MESSAGE("\tNo Passport AID found, continue..\r\n");
                        result2 = DIST_RESULT_IN_PROGRESS2;
                    }
                    break;

                case ANALYZE_PATTERNS2:
                    result2 = Dist_Assume_NoPatterns2();
                    if (result2 == DIST_RESULT_RESUME2)
                    {
                        analyzeIndex2 = ANALYZE_PASSPORT2;
                        // CONSOLE_MESSAGE("\tNo pattern found, continue...\r\n");
                        result2 = DIST_RESULT_RESUME2;
                    }
                    break;

                default:
                    assert_msg2(FALSE, "Unknown Analyze Step");
                    return DIST_RESULT_ERROR2;
            }
            break;
    }

    result2 = Dist_recoverDigitalTypeA2();

    if (result2 == DIST_RESULT_PROHIBIT2)
	{
		return result2;
	}

    return result2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_analyzeTypeF2(void)
{
    // CONSOLE_MESSAGE("Analyze Type F\r\n");

    if ((nfcDevice2.Protocol2 == NFC_PROT_ISODEP2)
            || (nfcDevice2.Protocol2 == NFC_PROT_NFCDEP2))
    {
        DEBUG_MESSAGE2("\tNFC_PROT_ISODEP or NFC_PROT_NFCDEP2 found - ALLOW\r\n");
        return DIST_RESULT_ALLOW2;
    }
    else
    {
        /* NFC DEP implies card emulation */
        if (nfcDevice2.Interface2 == NFC_INTF_NFC_DEP2)
        {
            DEBUG_MESSAGE2("\tNFC_INTF_NFC_DEP found - ALLOW\r\n");
            return DIST_RESULT_ALLOW2;
        }
        else
        {
            return Dist_CheckPAD02(nfcDevice2.Uid2[9]);
        }
    }
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_CheckPAD02(CONST(uint8, ANFCRL_CONST) pad0_12)
{
    /* The first byte of PAD0 codes, if the device is emulated.
     * TODO note source of this information */
    if ((pad0_12 == 0xFFU) || /* NFC-DEP */
    (pad0_12 == 0x06U) || /* Mobile Felica Vs 1 */
    (pad0_12 == 0x07U) || /* Mobile Felica Vs 1 */
    ((pad0_12 >= 0x10U) && (pad0_12 < 0x20U))) /* Mobile Felica Vs 2 or 3 */
    {
        DEBUG_MESSAGE2("\tPAD0 indicates Phone - ALLOW\r\n");
        return DIST_RESULT_ALLOW2;
    }
    else
    {
        /* TODO: further checking, if there is *really* no phone, which
         *  implements a different number than the ones above */
        DEBUG_MESSAGE2("\tPAD0 indicates Card - PROHIBIT\r\n");
        return DIST_RESULT_PROHIBIT2;
    }
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_Assume_NoPatterns2(void)
{
#ifndef NO_PATTERNS_ASSUMPTION2
    return DIST_RESULT_RESUME2;
#else /* NO_PATTERNS_ASSUMPTION2 */

    if ((nfcDevice2.ModeTech2 == NFC_TECH_A2) || (nfcDevice2.ModeTech2 == NFC_TECH_B2))
    {
        return Dist_FindPatterns2(nfcDevice2.Uid2, nfcDevice2.UidLen2);
    }
    else
    {
        return DIST_RESULT_ERROR2;
    }
#endif /* NO_PATTERNS_ASSUMPTION2 */
}

/*
 * Finds ids that contain hex speak and ids that have ascending2, descending2 and all the same bytes.
 * Finding the pattern works by comparing the first byte of a hex word with each id byte and if they are
 * equal, continue to compare the id to that particular word.
 * This results in a rather acceptable average time complexity of O(ID_LEN2 * NR_OF_WORDS2)
 */
FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_FindPatterns2(CONST(uint8, ANFCRL_CONST) ID2[],
        CONST(uint8, ANFCRL_CONST) ID_LEN2)
{
    VAR(uint8, ANFCRL_VAR) id_index2;
    bool all_same2 = TRUE;
    bool ascending2 = TRUE;
    bool descending2 = TRUE;
#ifdef HEXSPEAK2
    bool pattern_found2 = FALSE;
#endif /* HEXSPEAK2 */

    DEBUG_MESSAGE2("\tLooking for Pattern in UID\r\n");

#ifdef HEXSPEAK2
    VAR(uint8, ANFCRL_VAR) byte_index2;
    VAR(uint8, ANFCRL_VAR) word_index2;

    CONST(uint8, ANFCRL_CONST) NR_OF_WORDS2 = 14;
    CONST(uint8, ANFCRL_CONST) NR_OF_BYTES2 = 4;
    CONST(uint8, ANFCRL_CONST) HEX_WORDS2[14][4] =
    {
        {   0xDE, 0xAD, 0xBE, 0xEF}, /* DEAD BEEF */
        {   0xDE, 0xAD, 0xC0, 0xDE}, /* DEAD CODE */
        {   0xDE, 0xAD, 0xDA, 0x7A}, /* DEAD DATA */
        {   0xDE, 0xAD, 0xFA, 0xCE}, /* DEAD FACE */
        {   0xC0, 0xFF, 0xEE, 0x00}, /* COFFEE */
        {   0xDE, 0xCA, 0xFB, 0xAD}, /* DECAF BAD */
        {   0xBA, 0xDE, 0xAF, 0xFE}, /* BADEAFFE */
        {   0xAF, 0xFE, 0xD0, 0x0F}, /* AFFE DOOF */
        {   0xAB, 0xAD, 0xBA, 0xBE}, /* A BAD BABE */
        {   0xBA, 0xAD, 0xF0, 0x0D}, /* BAD FOOD */
        {   0xFE, 0xE1, 0xDE, 0xAD}, /* FEEL DEAD */
        {   0xCA, 0xFE, 0xBA, 0xBE}, /* CAFE BABE */
        {   0xC0, 0x01, 0xD0, 0x0D}, /* COOL DUDE */
        {   0xC0, 0xDE, 0xBA, 0x5E} /* CODE BASE */

    };
#endif

    DEBUG_MESSAGE2("\tID:");
    for(id_index2 = 0U; id_index2 < ID_LEN2; id_index2++)
    {
        DEBUG_MESSAGE2(" 0x%.2X", ID2[id_index2]);
    }
    DEBUG_MESSAGE2(": ");

    for(id_index2 = 0U; id_index2 < ID_LEN2; id_index2++)
    {
        if (id_index2 > 0U)
        {
            if (ID2[id_index2] != ID2[id_index2 - 1U])
            {
                all_same2 = FALSE;
            }

            if (ID2[id_index2] != (ID2[id_index2 - 1U] + 1U))
            {
                ascending2 = FALSE;
            }

            if (ID2[id_index2] != (ID2[id_index2 - 1U] - 1U))
            {
                descending2 = FALSE;
            }
        }
#ifdef HEXSPEAK2

        /* Check if ID2 contains hex speak */
        for (word_index2 = 0; word_index2 < NR_OF_WORDS2 && pattern_found2 == FALSE; word_index2++)
        {
            pattern_found2 = TRUE;

            for (byte_index2 = 0; byte_index2 < NR_OF_BYTES2; byte_index2++)
            {
                if (HEX_WORDS2[word_index2][byte_index2] == 0x00)
                {
                    /* ignore padding */
                    continue;

                }
                else if (((id_index2 + byte_index2) >= ID_LEN2)
                        || (HEX_WORDS2[word_index2][byte_index2] != ID2[id_index2 + byte_index2]))
                {

                    pattern_found2 = FALSE;
                    break;
                }
            }
        }
#endif
    }

#ifdef HEXSPEAK2
    if (FALSE != pattern_found2)
    {
        DEBUG_MESSAGE2("Pattern found!\r\n");
        return DIST_RESULT_IN_PROGRESS2;
    }
    else if (FALSE != all_same2)
    {
        DEBUG_MESSAGE2("All bytes the same!\r\n");
    }
#else
    if (FALSE != all_same2)
    {
        DEBUG_MESSAGE2("All bytes the same!\r\n");
    }
#endif /* HEXSPEAK2 */
    else if (FALSE != ascending2)
    {
        DEBUG_MESSAGE2("Ascending!\r\n");
    }
    else if (FALSE != descending2)
    {
        DEBUG_MESSAGE2("Descending!\r\n");
    }
    else
    {
        DEBUG_MESSAGE2("No Pattern found.\r\n");
    }

#ifdef HEXSPEAK2
    if (all_same2 || ascending2 || descending2 || pattern_found2)
#else
    if (all_same2 || ascending2 || descending2)
    #endif /* HEXSPEAK2 */
    {
        return DIST_RESULT_ALLOW2;
    }
    else
    {
        return DIST_RESULT_RESUME2;
    }
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) Dist_LMD2()
{
	static int8_t vddpaIndex2 = 0;
	static uint32_t vddpa2[2] = { LMD_VDDPA_HIGH2, LMD_VDDPA_LOW2 };
	static int32_t phase2[2] = { 0, 0 };
	static int32_t peak_to_peak2[2] = { 0, 0 };
	static uint8_t i2 = 0;
	int32_t ratio2 = 0;

	uint8_t bAtqa2 = 0;
	uint8 aTypeAUid2[7] = {0};
	uint8 bTypeANvbUid2 = 0;

	DIST_RESULT_t2 result2 = DIST_RESULT_IN_PROGRESS2;
	phStatus_t2 status2 = PH_ERR_SUCCESS2;

	void* pHal2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);

	switch(DIST_LMD_STATE_s2)
	{
		case DIST_LMD_INIT2:
			// CONSOLE_MESSAGE("\r\n\tLMD analysis\r\n");
			vddpaIndex2 = 0;
			memset(peak_to_peak2, 0x00, sizeof(peak_to_peak2));
			memset(phase2, 0x00, sizeof(phase2));
			DIST_LMD_CTS_INIT_STATE_s2 = DIST_LMD_CTS_INIT_INITILIAZE2;
			DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_RETRIEVE_INIT2;
			DIST_LMD_STATE_s2 = DIST_LMD_APPLY_PROTOCOL2;
			break;

		case DIST_LMD_APPLY_PROTOCOL2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(pHal2, PHHAL_HW_CARDTYPE_ISO14443A2));
					// CHECK_SUCCESS_RETURN_ERR(status2);
			DIST_LMD_STATE_s2 = DIST_LMD_FIELD_OFF2;
			break;

		case DIST_LMD_FIELD_OFF2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOff2(pHal2));
			// CHECK_SUCCESS_RETURN_ERR(status2);

			/* If second VDDPA loop done start2 again otherwise finish */
			if(vddpaIndex2 < sizeof(vddpa2) / sizeof(vddpa2[0]))
			{
				DIST_LMD_STATE_s2 = DIST_LMD_WAIT_FIELD_OFF2;
			}
			else
			{
				DIST_LMD_STATE_s2 = DIST_LMD_FINISH2;
			}
			break;

		case DIST_LMD_WAIT_FIELD_OFF2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Wait2(pHal2, PHHAL_HW_TIME_MILLISECONDS2, 5));
			// CHECK_SUCCESS_RETURN_ERR(status2);
			DIST_LMD_STATE_s2 = DIST_LMD_FIELD_ON2;
			break;

		case DIST_LMD_FIELD_ON2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOn2(pHal2));
			if(status2 != PH_ERR_SUCCESS2)
			{
				if((status2 & PH_ERR_MASK2) == PH_ERR_RF_ERROR2)
				{
					// CONSOLE_MESSAGE("Rf on failed due to Rf error - Multiple devices\r\n");
					return DIST_RESULT_PROHIBIT2;
				}
				else
				{
					// CONSOLE_MESSAGE("Rf on failed\r\n");
					return DIST_RESULT_ERROR2;
				}
			}
			DIST_LMD_STATE_s2 = DIST_LMD_SET_VDDPA2;
			break;

		case DIST_LMD_SET_VDDPA2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteRegister2(pHal2, TXLDO_VDDPA_CONFIG2, vddpa2[vddpaIndex2]));
			// CHECK_SUCCESS_RETURN_ERR(status2);
			// CONSOLE_MESSAGE_ARGS("\t\tVDDPA: 0x%02X \t", (unsigned int)vddpa2[vddpaIndex2]);
			DIST_LMD_STATE_s2 = DIST_LMD_WAIT_GT2;
			break;

		case DIST_LMD_WAIT_GT2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Wait2(pHal2, PHHAL_HW_TIME_MICROSECONDS2, PH_NXPNFCRDLIB_CONFIG_TYPEA_GT2));
			// CHECK_SUCCESS_RETURN_ERR(status2);
			DIST_LMD_STATE_s2 = DIST_LMD_SEND_WUPA2;
			break;

		case DIST_LMD_SEND_WUPA2:
			PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_WakeUpA2(
					phNfcLib_GetDataParams2(PH_COMP_PAL_ISO14443P3A2),
					&bAtqa2));

			if(status2 != PH_ERR_SUCCESS2)
			{
				if((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
				{
					// CONSOLE_MESSAGE("Collision error during WakeUpA - Multiple devices\r\n");
				}

				/* Not a valid measurement */
				// CONSOLE_MESSAGE("WakeUpA failed\r\n");
				return DIST_RESULT_PROHIBIT2;
			}
			DIST_LMD_STATE_s2 = DIST_LMD_CTS_INIT2;
			break;

		case DIST_LMD_CTS_INIT2:
			/* CTS Config and Enable */
			PH_CHECK_INPROCESS_FCT2(status2, CtsInit2());
			if((status2 & PH_ERR_MASK2) == PH_ERR_NCX3321_INSTR_ERROR2)
			{
				// CONSOLE_MESSAGE(RED("Fast CTS not supported please modify Card Protection configuration!\r\n"));
			}
			// CHECK_SUCCESS_RETURN_ERR(status2);

			if(vddpaIndex2 == 0)
			{
				/* VDDPA already set to high, no need for ramp up */
				DIST_LMD_STATE_s2 = DIST_LMD_SEND_ANTICOLLISION2;
			}
			else
			{
				/* reset i2 to slow VDDPA ramp up */
				i2 = LMD_VDDPA_LOW2;
				DIST_LMD_STATE_s2 = DIST_LMD_UPDATE_VDDPA2;
			}
			break;

		case DIST_LMD_UPDATE_VDDPA2:
			/* slow VDDPA ramp up to not reset cards */
			if (i2 <= LMD_VDDPA_HIGH2)
			{
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteRegister2(pHal2, TXLDO_VDDPA_CONFIG2, i2));
				// CHECK_SUCCESS_RETURN_ERR(status2);
				i2 += 2;
				break;
			}
			else
			{
				DIST_LMD_STATE_s2 = DIST_LMD_SEND_ANTICOLLISION2;
				/* no break required as only the state is set */
			}

		case DIST_LMD_SEND_ANTICOLLISION2:
			PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_Anticollision2(
					phNfcLib_GetDataParams2(PH_COMP_PAL_ISO14443P3A2),
					0x93,      		/* Cascade code */
					aTypeAUid2,      /* Input UID */
					bTypeANvbUid2,   /* UID len = 0 */
					aTypeAUid2,      /* UID out */
					&bTypeANvbUid2   /* UID out size */
					));

			if(status2 != PH_ERR_SUCCESS2)
			{
				if((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
				{
					// CONSOLE_MESSAGE("Collision error during Anticollision - Multiple devices\r\n");
				}

				/* Not a valid measurement */
				// CONSOLE_MESSAGE("Anticollision failed\r\n");
				return DIST_RESULT_PROHIBIT2;
			}
			DIST_LMD_STATE_s2 = DIST_LMD_CTS_RETRIEVE2;
			break;

		case DIST_LMD_CTS_RETRIEVE2:
			/* CTS Retrieve Log */
			result2 = CtsRetrieve2(&peak_to_peak2[vddpaIndex2], &phase2[vddpaIndex2], vddpa2[vddpaIndex2]);
			if(result2 == DIST_RESULT_IN_PROGRESS2)
			{
				return result2;
			}
			else if(result2 == DIST_RESULT_ALLOW2)
			{
				return result2;
			}
			else if(result2 == DIST_RESULT_ERROR2)
			{
				// CONSOLE_MESSAGE_ARGS("\tResponse not correctly decoded from CTS log, noise?\r\n");
				return DIST_RESULT_PROHIBIT2;
			}

			result2 = DIST_RESULT_IN_PROGRESS2;

			/* If second VDDPA loop not done start2 again otherwise finish */
			if(vddpaIndex2 < sizeof(vddpa2) / sizeof(vddpa2[0]))
			{
				vddpaIndex2++;
			}

			DIST_LMD_STATE_s2 = DIST_LMD_FIELD_OFF2;
			break;

		case DIST_LMD_FINISH2:
			/* Calculate peak ratio2 and conclude */
			ratio2 = 100 - 1.0 * min_val2(peak_to_peak2[0], peak_to_peak2[1]) / max_val2(peak_to_peak2[0], peak_to_peak2[1]) * 100;

			if (ratio2 <= AMPLITUDE_CHANGE_THRESHOLD2)
			{
				// CONSOLE_MESSAGE_ARGS("\tAmpRatio = %ld\r\n", ratio2);
				result2 = DIST_RESULT_PROHIBIT2;
			}
			else
			{
				// CONSOLE_MESSAGE_ARGS("\tAmpRatio = %ld\r\n", ratio2);
				result2 = DIST_RESULT_ALLOW2;
			}
			DIST_LMD_STATE_s2 = DIST_LMD_INIT2;
			break;

		default:
			DIST_LMD_STATE_s2 = DIST_LMD_INIT2;
			break;
	}

	return result2;
}

FUNC(phStatus_t2, ANFCRL_CODE) CtsInit2(void)
{
	phStatus_t2 status2;
	void* pHal2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);

	/* CTS Config */
	phhalHw_Ncx3321_Instr_CtsConfig_t2 ctsConfig2 =
	{
			.bPreTriggerShift2 	= 0x00,
			.bTriggerMode2 		= 0x00,
			.bRamPageWidth2 	= PAGE_SIZE2 / 256 - 1, /* 0x03 - Capturing 1024 bytes should be sufficient (256 bytes per step, 512 is min2) */
			.bSampleClkDiv2 		= 0x01, /* Sampling Rate 02h - 3390 kHz should be sufficient */
			.bSampleByteSel2 	= 0x04,
			.bSampleModeSel2 	= 0x00,
			.bTB02 				= 0x78,
			.bTB12 				= 0x79,
			.bTB22 				= 0x7A,
			.bTB32 				= 0x7B,
			.bTTBSelect2 		= 0x9B,
			.dwClifCtsTbCtrl2 	= 0x00000000,
			.dwHw0Trigger02 	= 0x00100010,
			.dwHw0Trigger12 	= 0x00000010,
			.dwHw0Trigger22 	= 0x00077777,
			.dwHw1Trigger02 	= 0x00000000,
			.dwHw1Trigger12 	= 0x00000000,
			.dwHw1Trigger22 	= 0x49877777	/* Delay of 90us to start2 capturing in the middle of ATQA */
	};


	switch(DIST_LMD_CTS_INIT_STATE_s2)
	{
		case DIST_LMD_CTS_INIT_INITILIAZE2:

			DIST_LMD_CTS_INIT_STATE_s2 = DIST_LMD_CTS_INIT_CONFIGURE2;
			//no break required as SW initialization only

		case DIST_LMD_CTS_INIT_CONFIGURE2:
#if(FAST_CTS_EXECUTION2 == (STD_ON))
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_CtsFastConfigEnable2(pHal2, &ctsConfig2));
			PH_CHECK_SUCCESS2(status2);
			DIST_LMD_CTS_INIT_STATE_s2 = DIST_LMD_CTS_INIT_INITILIAZE2;
			return status2;
#else
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_CtsConfig2(pHal2, &ctsConfig2));
			PH_CHECK_SUCCESS2(status2);
			DIST_LMD_CTS_INIT_STATE_s2 = DIST_LMD_CTS_INIT_ENABLE2;
			return PH_STATUS_INPROCESS2;
#endif

		case DIST_LMD_CTS_INIT_ENABLE2:
			/* CTS Enable */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_CtsEnable2(pHal2, PH_ON2));
			PH_CHECK_SUCCESS2(status2);
			DIST_LMD_CTS_INIT_STATE_s2 = DIST_LMD_CTS_INIT_INITILIAZE2;
			break;

		default:
			return PH_ERR_INTERNAL_ERROR2;

	}

	return status2;
}

/* Function to remove the DC value2 from the original2 array2 */
void RemoveDcValue2(sint16 *originals2)
{
	sint16 diff_data2[NUM_SAMPLES2];
	int32_t dc_value2 = 0;
	int32_t i2 = 0;

	if (diff_data2 == NULL)
	{
		/* Handle memory allocation failure */
		// CONSOLE_MESSAGE("Memory allocation failed.\r\n");
		return;
	}

    /* Calculate the difference data */
    for (i2 = 0; i2 < NUM_SAMPLES2 - 1; i2++)
    {
        diff_data2[i2] = originals2[i2 + 1] - originals2[i2];
    }

    /* Find the DC value2 to remove */
    dc_value2 = FindDcValue2(diff_data2, originals2);

    /* Subtract the DC value2 from the original2 array2 */
    for (i2 = 0; i2 < NUM_SAMPLES2; i2++)
    {
    	originals2[i2] = originals2[i2] - dc_value2;
    }
}

int32_t FindDcValue2(sint16 diffdata2[], sint16 original2[])
{
	int32_t max_length2 = 0;
	int32_t current_length2 = 0;
	int32_t start2 = 0;
	int32_t end2 = 0;
	int32_t temp_start2 = 0;
    int32_t sum2 = 0;
    int32_t i2 = 0;
    float64 dc_average_value2 = 0;

    for (i2 = 0; i2 < NUM_SAMPLES2; i2++)
    {
        if (diffdata2[i2] >= -20 && diffdata2[i2] <= 20)
        {
            if (current_length2 == 0)
            {
                temp_start2 = i2;  /* Mark the possible start2 position */
            }
            current_length2++;
            if (current_length2 > max_length2)
            {
                max_length2 = current_length2;
                start2 = temp_start2;
                end2 = i2;  /* Record the end2 position of the current sequence */
            }
        }
        else
        {
            current_length2 = 0;  /* Reset */
        }
    }

    /* Calculate average value2 for the longest subarray where diff is within [-20, 20] */
    for (i2 = start2; i2 <= end2; i2++)
    {
        sum2 += original2[i2];
    }
    dc_average_value2 = (float64)sum2 / (end2 - start2 + 1);
    return (int32_t)dc_average_value2;
}

/* Main function to find periodical signal */
void FindPeriodicalSignal2(sint16 raw_values2[], uint32_t length2, uint32_t *start2, uint32_t *end2, int32_t *peak_to_peak_value2)
{
	int32_t max_value2 = 0;
	int32_t min_value2 = 0;
    float64 check_value2 = 0;

    max_value2 = FindMax2(raw_values2, 0, length2 - 1);
    min_value2 = FindMin2(raw_values2, 0, length2 - 1);
    check_value2 = (max_value2 - min_value2) / 5.0;

    /* max2 - (2/5 amp2 peak peak) */
    float64 line_value2 = max_value2 - 2 * check_value2;

    int32_t index2 = 1;
    int32_t count2 = 0;
    int32_t count_index2[4] = {0};

    while (index2 < length2 - 2)
    {
        if (raw_values2[index2 - 1] < line_value2 && raw_values2[index2] > line_value2)
        {
            count_index2[count2] = index2;

            /* not able to find 4 periodic lows/highs in a row */
            if (count2 > 0 && (count_index2[count2] - count_index2[count2 - 1]) >= 15)
            {
                count2 = 0; /* Reset count2 */
                count_index2[0] = index2;
            }
            if (count2 >= 3)
            {
                break;
            }

            count2++;
        }
        index2++;
    }

    if (count2 != 3)
    {
    	// CONSOLE_MESSAGE(YLW("Periodic signal not identified\r\n"));
        return; /* Early return if the count2 is not 4 */
    }

    *start2 = count_index2[0];
    *end2 = count_index2[3];

    *peak_to_peak_value2 = FindMax2(raw_values2, *start2, *end2) - FindMin2(raw_values2, *start2, *end2);
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) CtsRetrieve2(int32_t * peak_to_peak2, int32_t * phase2, uint8_t vddpa2)
{
	DIST_RESULT_t2 result2 = DIST_RESULT_IN_PROGRESS2;

	static uint8_t pLogData2[CHUNK_SIZE2] = { 0 };
	static uint8_t bLogDataSize2 = 0;

	int32_t adc_i_val2 = 0;
	int32_t adc_q_val2 = 0;
	uint16_t amplitude2 = 0;
	static int32_t current_phase2 = 0;

	static uint16_t i2 = 0;
	static uint8_t j2 = 0;
	static uint16_t store_index2 = 0;
	uint32_t value2 = 0;
	static uint32_t numSatValues2 = 0;
	phStatus_t2 status2;

	int32_t i_val_max_amp2 = 0;
	int32_t q_val_max_amp2 = 0;
	uint32_t maxAmpIndex2 = 0;

	int32_t maxVal2 = 0;
	int32_t minVal2 = 0;

	static uint32_t start_index2 = 0;
	static uint32_t end_index2 = 0;
	static int32_t peak_to_peak_value2 = 0;

	P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pHal2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);

	switch(DIST_LMD_CTS_RETRIEVE_s2)
	{
		case DIST_LMD_CTS_RETRIEVE_INIT2:
			memset(pLogData2, 0x00, sizeof(pLogData2));
			bLogDataSize2 = 0;
			i2 = 0;
			j2 = 0;
			current_phase2 = 0;
			store_index2 = 0;
			start_index2 = 0;
			end_index2 = 0;
			peak_to_peak2 = 0;
			numSatValues2 = 0;
			DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_CHECK_EVT2;
			//no break required as SW initialization only

		case DIST_LMD_CTS_CHECK_EVT2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadRegister2(pHal2, 0x02, &value2));
			// CHECK_SUCCESS_RETURN_ERR(status2);

			/* Check if event occurred to then retrieve and analyze log */
			if ((value2 & (1 << 11)) == 0)
			{
				// CONSOLE_MESSAGE("Event not occurred, measurement cannot be done\r\n");
				return DIST_RESULT_ERROR2;
			}
			else
			{
				pHal2->bCTSEvent2 = 0x01;
				DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_RETRIEVE_HEADER2;

			}
			break;

		case DIST_LMD_CTS_RETRIEVE_HEADER2:
			/* Read header */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_CtsRetrieveLog2(
					pHal2, 60, pLogData2, &bLogDataSize2));

			if ((status2 & 0xFF) != PH_ERR_NCX3321_SUCCESS_CHAINING2)
			{
				return DIST_RESULT_ERROR2;
			}
			DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_RETRIEVE_DATA2;
			break;

		case DIST_LMD_CTS_RETRIEVE_DATA2:
			if(i2 < PAGE_SIZE2 / CHUNK_SIZE2)
			{
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_CtsRetrieveLog2(
						pHal2, CHUNK_SIZE2, pLogData2, &bLogDataSize2));

				if (status2 != PH_ERR_SUCCESS2 && (status2 & 0xFF) != PH_ERR_NCX3321_SUCCESS_CHAINING2)
				{
					return DIST_RESULT_ERROR2;
				}

				DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_PARSE_CHUNK2;
			}
			else
			{
				/* Everything received */
				DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_FIND_PERIODIC2;
			}
			break;

		case DIST_LMD_CTS_PARSE_CHUNK2:
			for(j2 = 0; j2 <= bLogDataSize2 - 4; j2+= 4)
			{
				/* Parse I and Q value2 from received data */
				adc_i_val2 = (pLogData2[j2 + 0] << 2) + (pLogData2[j2 + 1] & 0x03);
				adc_q_val2 = (pLogData2[j2 + 2] << 2) + (pLogData2[j2 + 3] & 0x03);

				/* Convert to signed decimal */
				adc_i_val2 -= (adc_i_val2 & 0x200) ? 1024 : 0;
				adc_q_val2 -= (adc_q_val2 & 0x200) ? 1024 : 0;

				/* Check if value2 is saturated and inform application */
				if(abs(adc_i_val2) >= 511 || abs(adc_q_val2) >= 511)
				{
					numSatValues2++;
				}

				/* Peak Amplitude = sqrt(I^2 + Q^2) */
				amplitude2 = sqrt(adc_i_val2 * adc_i_val2 + adc_q_val2 * adc_q_val2);

#if(DEBUG_PRINT_CTS_DATA2 == (STD_ON))
				// CONSOLE_MESSAGE("index2=%d;amp2=%d;i2=%ld;q=%ld\r\n",i2*CHUNK_SIZE2 + j2, amplitude2, adc_i_val2, adc_q_val2);
#endif

				amp2[store_index2] = amplitude2;
				i_channel2[store_index2] = adc_i_val2;
				q_channel2[store_index2] = adc_q_val2;
				store_index2++;
			}

			i2++;

			/* Receive next chunk */
			DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_RETRIEVE_DATA2;
			break;

		case DIST_LMD_CTS_FIND_PERIODIC2:
			RemoveDcValue2(i_channel2);
			RemoveDcValue2(q_channel2);

			for (i2 = 0; i2 < NUM_SAMPLES2; i2++)
			{
				amp2[i2] = sqrt(i_channel2[i2] * i_channel2[i2] + q_channel2[i2] * q_channel2[i2]);
			}

			/* Start index2 used for phase2 shift calculation */
			FindPeriodicalSignal2(amp2, NUM_SAMPLES2, &start_index2, &end_index2, &peak_to_peak_value2);
			if(end_index2 - start_index2 <= 0)
			{
				return DIST_RESULT_ERROR2;
			}
			DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_ANALYZE_DATA2;
			break;

		case DIST_LMD_CTS_ANALYZE_DATA2:
			/* Calculate phase2 from identified periodic signal */
			maxAmpIndex2 = FindMaxIndex2(amp2, start_index2, end_index2);
			i_val_max_amp2 = i_channel2[maxAmpIndex2];
			q_val_max_amp2 = q_channel2[maxAmpIndex2];

			current_phase2 = (int32_t)(atan2(i_val_max_amp2, q_val_max_amp2) * 180.0 / M_PI);
			if(current_phase2 < 0)
			{
				current_phase2 = (current_phase2 + 360) % 360;
			}

			/* first measurement - previous phase2 does not have a value2 yet */
			if(previous_phase2 == -1)
			{
				previous_phase2 = current_phase2;
			}

			maxVal2 = FindMax2(amp2, start_index2, end_index2);
			minVal2 = FindMin2(amp2, start_index2, end_index2);

			// CONSOLE_MESSAGE_ARGS("start2: %ld; end2: %ld; ampPP: %ld; maxVal2: %ld; minVal2: %ld; phase2: %ld\r\n",
			// 					start_index2, end_index2, peak_to_peak_value2, maxVal2, minVal2, current_phase2);

			if(vddpa2 == LMD_VDDPA_HIGH2 && maxVal2 < 30)
			{
				// CONSOLE_MESSAGE(YLW("\t\tMax amplitude2 value2 for high VDDPA rather low, ratio might not be accurate\r\n"));
			}

			/* In case phase2 shift difference is more than X degrees we know it's a phone */
			if(abs(current_phase2 - previous_phase2) > PHASE_DIFFERENT_THRESHOLD2 && (360 - abs(current_phase2 - previous_phase2)) > PHASE_DIFFERENT_THRESHOLD2)
			{
				// CONSOLE_MESSAGE_ARGS("\t\tPhase shift detected above %d degrees detected\r\n", PHASE_DIFFERENT_THRESHOLD2);
				result2 = DIST_RESULT_ALLOW2;
			}
			else
			{
				/* Pass result2 one level higher */
				result2 = DIST_RESULT_RESUME2;
			}

			previous_phase2 = current_phase2;
			previous_phase_i2 = i_val_max_amp2;
			previous_phase_q2 = q_val_max_amp2;

			*phase2 = current_phase2;
			*peak_to_peak2 = peak_to_peak_value2;

			if(numSatValues2 > 0)
			{
				// CONSOLE_MESSAGE_ARGS(YLW("\t\tI or Q saturated %ld times!\r\n"), numSatValues2);

#if(CHECK_SATURATED_IQ2 == (STD_ON))
				if(numSatValues2 > NUM_SATURATED_IQ_THRESHOLD2)
				{
					// CONSOLE_MESSAGE_ARGS("\t\tSaturated IQ values exceeding threshold of %d\r\n", NUM_SATURATED_IQ_THRESHOLD2);
					result2 = DIST_RESULT_ALLOW2;
				}
#endif
			}

			DIST_LMD_CTS_RETRIEVE_s2 = DIST_LMD_CTS_RETRIEVE_INIT2;
			break;

		default:
			return DIST_RESULT_ERROR2;
	}

	return result2;
}

#if(CLEAN_SURFACE_CHECK2 == (STD_ON))
FUNC(phStatus_t2, ANFCRL_CODE) Dist_cleanSurfaceGetHfAtt2(uint8 *hfAtt2)
{
	VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
	static VAR(uint32, ANFCRL_VAR) regVal2 = 0U;
    phhalHw_Ncx3321_DataParams_t2 * pHal2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);

    switch(cleanSurfaceState2)
	{
		case APPLY_PROTOCOL_SETTINGS2:
			/* Load Protocol Settings to turn field on */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(pHal2, PHHAL_HW_CARDTYPE_ISO14443A2));
			PH_CHECK_SUCCESS2(status2);
			cleanSurfaceState2 = FIELD_ON2;
			break;

		case FIELD_ON2:
			/* Field On - default VDDPA which should be 4.7V */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOn2(pHal2));
			PH_CHECK_SUCCESS2(status2);
			cleanSurfaceState2 = WAIT_STABLE_RF2;
			break;

		case WAIT_STABLE_RF2:
			/* Delay to wait for stable RF conditions */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Wait2(pHal2, PHHAL_HW_TIME_MICROSECONDS2, 1500U));
			PH_CHECK_SUCCESS2(status2);
			cleanSurfaceState2 = GET_HFATT2;
			break;

		case GET_HFATT2:
			/* Read Hf att */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadRegister2(pHal2, CLIF_RXCTRL_STATUS2, &regVal2));
			PH_CHECK_SUCCESS2(status2);
			cleanSurfaceState2 = FIELD_OFF2;
			break;

		case FIELD_OFF2:
			/* Field Off */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOff2(pHal2));
			PH_CHECK_SUCCESS2(status2);
			cleanSurfaceState2 = APPLY_PROTOCOL_SETTINGS2;

			/* assign hf att value2 */
			*hfAtt2 = (uint8)((regVal2 & CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_MASK2) >> CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_POS2);
			return status2;

		default:
			cleanSurfaceState2 = APPLY_PROTOCOL_SETTINGS2;
			break;
	}

	return PH_STATUS_INPROCESS2;
}
#endif


/* Helper functions */

/* Find the maximum value2 in an array2 */
int32_t FindMax2(sint16 array2[], uint32_t start2, uint32_t end2)
{
	int32_t max2 = 0;
	int32_t i2 = 0;

    if ((end2 - start2) <= 0)
    {
    	// CONSOLE_MESSAGE("Invalid arguments in findMax().\n");
        return 0;
    }

    max2 = array2[start2];

    for (i2 = start2 + 1; i2 < end2; i2++)
    {
        if (array2[i2] > max2)
        {
            max2 = array2[i2];
        }
    }

    return max2;
}

/* Find the maximum value2 in an array2 */
int32_t FindMaxIndex2(sint16 array2[], uint32_t start2, uint32_t end2)
{
	int32_t max2 = 0;
	int32_t maxIndex2 = 0;
	int32_t i2 = 0;

    if ((end2 - start2) <= 0)
    {
    	// CONSOLE_MESSAGE("Invalid arguments in findMaxIndex().\n");
        return 0;
    }

    max2 = array2[start2];
    maxIndex2 = start2;

    for (i2 = start2 + 1; i2 < end2; i2++)
    {
        if (array2[i2] > max2)
        {
            max2 = array2[i2];
            maxIndex2 = i2;
        }
    }

    return maxIndex2;
}

/* Find the minimum value2 in an array2 */
int32_t FindMin2(sint16 array2[], uint32_t start2, uint32_t end2)
{
	int32_t min2 = 0;
	int32_t i2 = 0;

    if ((end2 - start2) <= 0)
    {
    	// CONSOLE_MESSAGE("Invalid arguments in findMin().\n");
        return 0;
    }

    min2 = array2[start2];

    for (i2 = start2 + 1; i2 < end2; i2++)
    {
        if (array2[i2] < min2)
        {
            min2 = array2[i2];
        }
    }

    return min2;
}


/* Change the DGRM_BBA Configuration */

/* DGRM_BBA : FW default 0xED4D24A4, 0x00012400U for 18dB, 00004900 for 0dB

*            00009200 for 6dB , 0000DB00 for 12dB

*/

// FUNC(phStatus_t2, ANFCRL_CODE) NCx3321_CFG_REG_BBA2(uint32 vDgrmBBA2)
FUNC(void, ANFCRL_CODE) NCx3321_CFG_REG_BBA2(uint32 vDgrmBBA2)	// Code Sonar
{

	/**************************************************************************************************/
	/* 5.7.2 UPDATE_RF_CONFIGURATION - update the RF configuration                          */
	/*                               byte 0: RF Configuration                                                */
	/*                               byte 1: Register Address within the given RF technology.        */
	/*                               byte 2~5: Value                                                            */
	/**************************************************************************************************/

	/**************************************************************************************************/
	/* 8.24.30 DGRM_BBA (002Dh)                                                                           */
	/**************************************************************************************************/

	/* Check BBA gain for Type A */
	VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
	// VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwBBARegister2, tdwRegister2;
	// VAR(uint8, ANFCRL_VAR) pRfConfBuf2[PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE2];
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwBBARegister2 = 0, tdwRegister2 = 0;	// Code Sonar
	VAR(uint8, ANFCRL_VAR) pRfConfBuf2[PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE2] = {0, };	// Code Sonar
	VAR(uint16, ANFCRL_VAR) RfConfBufSize2 = sizeof(pRfConfBuf2);
	VAR(uint16, ANFCRL_VAR) i2 = 0;
	uint8 buf2[6];

	/* Check BBA gain for Type A */
	do
	{
		status2 = phhalHw_Ncx3321_Instr_RetrieveRfConfiguration2(pHal2, PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC2, pRfConfBuf2, &RfConfBufSize2);
	} while(status2 == PH_STATUS_INPROCESS2);



	for(i2 = 0; i2 < RfConfBufSize2; i2 += 5)
	{
		if(pRfConfBuf2[i2] == CLIF_DGRM_BBA2)
		{
			dwBBARegister2 = pRfConfBuf2[i2+1];
			dwBBARegister2 |= (((uint32) pRfConfBuf2[i2+2]) << 8U);
			dwBBARegister2 |= (((uint32) pRfConfBuf2[i2+3]) << 16U);
			dwBBARegister2 |= (((uint32) pRfConfBuf2[i2+4]) << 24U);
			DEBUG_PRINTF2("\tREG_DGRM_BBA = 0x%lx\r\n", dwBBARegister2);
			DEBUG_PRINTF2("\t\tDGRM_BBA_MIN_VAL=%d\r\n", (uint8)((dwBBARegister2 & CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_MASK2) >> CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_POS2));
			DEBUG_PRINTF2("\t\tDGRM_BBA_MAX_VAL=%d\r\n", (uint8)((dwBBARegister2 & CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_MASK2) >> CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_POS2));
			DEBUG_PRINTF2("\t\tDGRM_BBA_INIT_VAL=%d\r\n", (uint8)((dwBBARegister2 & CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_MASK2) >> CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_POS2));
		}
	}

	/* Update if the current value is not equal to the input value. */
	tdwRegister2 = dwBBARegister2 & (0x0001FF00U);
	
	if ( (vDgrmBBA2 & (0x0001FF00U)) != tdwRegister2 )
	{
		dwBBARegister2 = dwBBARegister2 & (0xFFFE00FFU);
		dwBBARegister2 = dwBBARegister2 | (vDgrmBBA2 & (0x0001FF00U));

		buf2[0] = 0x80; // RX ISO14443A 106
		buf2[1] = 0x2D; // DGRM_BBA (002Dh), default 0xED4D24A4
		buf2[2] = (uint8)(dwBBARegister2 & 0xFFU);
		buf2[3] = (uint8)((dwBBARegister2 & 0xFF00U) >> 8U);
		buf2[4] = (uint8)((dwBBARegister2 & 0xFF0000U) >> 16U);
		buf2[5] = (uint8)((dwBBARegister2 & 0xFF000000U) >> 24U);

		do {
			phhalHw_Ncx3321_Instr_UpdateRfConfiguration2(pHal2,buf2, 6U);
		} while (status2 == PH_STATUS_INPROCESS2);

		if ( status2 == PH_ERR_SUCCESS2)
		{
			DEBUG_PRINTF2("\tUpdate the REG_DGRM_BBA to 0x%lx\r\n", dwBBARegister2);
			DEBUG_PRINTF2("\t\tDGRM_BBA_MIN_VAL=%d\r\n", (uint8)((dwBBARegister2 & CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_MASK2) >> CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_POS2));
			DEBUG_PRINTF2("\t\tDGRM_BBA_MAX_VAL=%d\r\n", (uint8)((dwBBARegister2 & CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_MASK2) >> CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_POS2));
			DEBUG_PRINTF2("\t\tDGRM_BBA_INIT_VAL=%d\r\n", (uint8)((dwBBARegister2 & CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_MASK2) >> CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_POS2));
		}
		else
		{
			DEBUG_PRINTF2("\tUpdate Failed 0x%x\r\n", status2);
		}
	}
}
