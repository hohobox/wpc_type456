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
 * This file contains the implementation of the distinguishing algorithm.
 * It's abstracted and can be used for different platforms via CPAL layer.
 * dinstinguishing_types.h contains some data structures required in this file.
 */

#include <ph_Status.h>
#include <phApp_Init.h>

#include "distinguishing.h"
#include "phApp_Init.h"

#ifdef CPU_S32K144HFT0VLLT
#include <lpuartLog.h>
#endif
#include "phhalHw_Ncx3321_Instr.h"
#include "phhalHw_Ncx3321_Reg.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef DEBUG_MSG
static CONST(uint8, ANFCRL_CONST) MAJOR_VERSION = 1;
#endif /* DEBUG_MSG */
#ifdef NXPBUILD__PH_LOG_EX
#define LOG_MESSAGE(...)        LOG_PRINTF(__VA_ARGS__)
#endif

static VAR(DIST_RESULT_t, ANFCRL_VAR) distIntermediateResult = DIST_RESULT_IN_PROGRESS;
static bool fieldOff = 0;

/* used for non blocking analysis of discovered tag
 * at least non pure sw analysis should use this index */
static VAR(analyzeIndex_t, ANFCRL_VAR) analyzeIndex = ANALYSIS_ERROR;

/* DEVELOPER NOTE:
 * every non void CPAL function can return IN_PROGRESS to make sure algo is non blocking */

VAR(DistinguishingState_t, ANFCRL_VAR) DIST_STATE_s = DIST_ST_RESET;
VAR(DistinguishingLmdState_t, ANFCRL_VAR) DIST_LMD_STATE_s = DIST_LMD_INIT;
VAR(DistinguishingLmdCtsInitState_t, ANFCRL_VAR) DIST_LMD_CTS_INIT_STATE_s = DIST_LMD_CTS_INIT_INITILIAZE;
VAR(DistinguishingLmdCtsRetrieveState_t, ANFCRL_VAR) DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_RETRIEVE_INIT;

int32_t previous_phase = -1;
int32_t previous_phase_i = 0;
int32_t previous_phase_q = 0;

sint16 amp[NUM_SAMPLES];
sint16 i_channel[NUM_SAMPLES];
sint16 q_channel[NUM_SAMPLES];

FUNC(phStatus_t, ANFCRL_CODE) CtsInit(void);
// FUNC(phStatus_t, ANFCRL_CODE) NCx3321_CFG_REG_BBA(uint32 vDgrmBBA);
FUNC(void, ANFCRL_CODE) NCx3321_CFG_REG_BBA(uint32 vDgrmBBA);	// Code Sonar

#if(CLEAN_SURFACE_CHECK == (STD_ON))
static VAR(cleanSurfaceCalibrateState_t, ANFCRL_VAR) cleanSurfaceState = 0;

#if(CLEAN_SURFACE_CALIBRATE == (STD_ON))
static VAR(uint8, ANFCRL_VAR) cleanSurfaceCalibHfAtt = 0U;
#else
static VAR(uint8, ANFCRL_VAR) cleanSurfaceCalibHfAtt = 35U;
#endif
#endif

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_run_CleanSurface(void)
{
	static VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_NO_RESULT;
#if(CLEAN_SURFACE_CHECK == (STD_ON))
	VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) hfAtt = 0U;

#if(CLEAN_SURFACE_CALIBRATE == (STD_ON))
	if(cleanSurfaceCalibHfAtt == 0)
	{
		do
		{
			status = Dist_cleanSurfaceGetHfAtt(&cleanSurfaceCalibHfAtt);
		}while (status == PH_STATUS_INPROCESS);

		if(status != PH_ERR_SUCCESS)
		{
			result =  DIST_RESULT_ERROR;
		}

		/* print calibration values */
		// CONSOLE_MESSAGE("Clean surface calibration Hf Att: %d\r\n",
				cleanSurfaceCalibHfAtt);
	}
#endif
#endif

#if(CLEAN_SURFACE_CHECK == (STD_ON))
	if(result != DIST_RESULT_PROHIBIT)
#endif

	{
		result = Dist_run();
	}
#if(CLEAN_SURFACE_CHECK == (STD_ON))
	else
	{
		/* Check surface */
		status = Dist_cleanSurfaceGetHfAtt(&hfAtt);
		if(status == PH_STATUS_INPROCESS)
		{
			return DIST_RESULT_IN_PROGRESS;
		}
		else if(status != PH_ERR_SUCCESS)
		{
			result = DIST_RESULT_ERROR;
		}
		else
		{
			// CONSOLE_MESSAGE("Hf attenuator difference %d\r\n", (uint16)abs(cleanSurfaceCalibHfAtt - hfAtt));
			if(abs(cleanSurfaceCalibHfAtt - hfAtt) > CLEAN_SURFACE_HFATT_THRESHOLD)
			{
				result = DIST_RESULT_PROHIBIT;
				// CONSOLE_MESSAGE("Device(s) not removed since previous prohibit state\r\n");
				// CONSOLE_MESSAGE(RED("PROHIBIT CHARGING\r\n"));

#if(DEBUG_DELAY_NEXT_LOOP == (STD_ON))
				// CONSOLE_MESSAGE("waiting for next execution");
				// CONSOLE_MESSAGE(".");
				while (phhalHw_Wait(pHal, PHHAL_HW_TIME_MILLISECONDS, 200u)
						== PH_STATUS_INPROCESS)
				{
				}
				// CONSOLE_MESSAGE(".");
				while (phhalHw_Wait(pHal, PHHAL_HW_TIME_MILLISECONDS, 200u)
						== PH_STATUS_INPROCESS)
				{
				}
				// CONSOLE_MESSAGE(".");
				// CONSOLE_MESSAGE("\r\n\n");
#endif
			}
			else
			{
				result = DIST_RESULT_ALLOW;
				// CONSOLE_MESSAGE("Device(s) removed. Surface cleared\r\n");
			}
		}
	}
#endif

	return result;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_run(void)
{
    VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_NO_RESULT;
#if(DEBUG_DELAY_NEXT_LOOP == (STD_ON))
	VAR(uint8, ANFCRL_VAR) count;
#endif
    /* Distinguishing State Machine */
    switch (DIST_STATE_s)
    {
        /* State RESET is only executed in case of an error */
        case DIST_ST_RESET:
            result = CPAL_reset();

            if (result == DIST_RESULT_RESUME)
            {
            	DIST_STATE_s = DIST_ST_INIT;
            }
            // break;	/* No Braek */

        case DIST_ST_INIT:
			/* Change the DGRM_BBA Configuration */

			/* DGRM_BBA :   FW default 0xED4D24A4,
				0x00004900	18688	 73		0		for 0dB
				0x00009200	37376	146		73		for 6dB
				0x0000DB00	56064	219		146		for 12dB
				0x00012400	74752	292		219		for 18dB
			*/
			NCx3321_CFG_REG_BBA((uint32)(0x00004900)); // Saturation TEST

            result = CPAL_init();

            /* If result is RESUME we continue with next step */
            if (result == DIST_RESULT_RESUME)
            {
                /* Reset internal variables */
                nfcDevice.ModeTech = NFC_TECH_UNKNOWN;
                analyzeIndex = ANALYZE_PASSPORT;
                fieldOff = FALSE;
                distIntermediateResult = DIST_RESULT_IN_PROGRESS;
				DIST_STATE_s = DIST_ST_SCAN_ALL;
				DIST_LMD_STATE_s = DIST_LMD_INIT;
            }
            // break;	 /* No Break */

        case DIST_ST_SCAN_ALL:
            result = CPAL_scanAllTypes();
        	 /* If result is RESUME we continue with next step */
            if (result == DIST_RESULT_RESUME)
            {
            	/* If result is RESUME we continue with next step */
                DIST_STATE_s = DIST_ST_ANALYZE_ALL;
            }
            else if(result == DIST_RESULT_ALLOW)
            {
            	/* In case nothing was detected, clear previous phase shift value */
            	previous_phase = -1;
            	previous_phase_i = 0;
            	previous_phase_q = 0;
            }
            else if (result == DIST_RESULT_ERROR)
            {
                /* DiscLoop failed, give it another try with LMD for Type A + B */
                if(nfcDevice.ModeTech == NFC_TECH_A || nfcDevice.ModeTech == NFC_TECH_B)
                {
                	result = DIST_RESULT_RESUME;
                	DIST_STATE_s = DIST_ST_LMD;
                }
                else
                {
                	// result = DIST_RESULT_PROHIBIT;
                	result = DIST_RESULT_ALLOW;	/* Antenna 연결 불량 */
                }
            }
            break;

        case DIST_ST_ANALYZE_ALL:
            result = Dist_analyzeResults();

            /* If result is RESUME we continue with
             * next scan depending on what we got before */
            if (result == DIST_RESULT_RESUME)
			{
#if(CHECK_MULTI_TECH_SUPPORT == (STD_ON))
				if (nfcDevice.ModeTech == NFC_TECH_A)
				{
					DIST_STATE_s = DIST_ST_SCAN_BF;

				}
				else
				{
					/* Should not happen */
					assert_msg(FALSE, "Endpoint discovered and not classified?");
					return DIST_RESULT_ERROR;
				}
#else
				DIST_STATE_s = DIST_ST_LMD;
#endif
			}
            break;

		case DIST_ST_SCAN_BF:
			/* Last step in the flowchart so we will end with a final state
			 * which is either ALLOW or INCONCLUSIVE */
			result = CPAL_scanTypeBF();
			if (result == DIST_RESULT_RESUME)
			{
				/* Restore previously detected endpoint */
				nfcDevice.ModeTech = NFC_TECH_A;
				DIST_STATE_s = DIST_ST_LMD;
			}
			else if (result == DIST_RESULT_ALLOW)
			{
				// CONSOLE_MESSAGE("Device emulating multiple technologies detected\r\n");
			}
			else if (result == DIST_RESULT_ERROR)
			{
				// CONSOLE_MESSAGE("ERROR!\r\n");
			}
			break;

		case DIST_ST_LMD:
			result = Dist_LMD();
			break;

		case DIST_ST_ERROR:
			default:
			assert_msg(FALSE, "Unknown Distinguishing State");
			result = DIST_RESULT_ERROR;
			break;
    }

    /* In case of ERROR or final state set algorithm state back to INIT */
    if ((result == DIST_RESULT_ALLOW) || (result == DIST_RESULT_PROHIBIT)
            || (result == DIST_RESULT_ERROR))
    {
        switch (result)
        {
            case DIST_RESULT_ALLOW:
                // CONSOLE_MESSAGE(GRN("\t\t\t\t\tALLOW CHARGING\r\n"));
                // RGB_GREEN_ON;
                // RGB_RED_OFF;
                break;
            case DIST_RESULT_PROHIBIT:
                // CONSOLE_MESSAGE(RED("\t\t\t\t\tPROHIBIT CHARGING\r\n"));
                // RGB_GREEN_OFF;
                // RGB_RED_ON;
                break;
            case DIST_RESULT_ERROR:
                // CONSOLE_MESSAGE("RESULT ERROR\r\n");
                break;
            default:
                // CONSOLE_MESSAGE("Unexpected final result\r\n");
                break;
        }
        // CONSOLE_MESSAGE("\t waiting for next execution\n");


        DIST_STATE_s = DIST_ST_INIT;
    }

    return result;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_analyzeResults(void)
{
    VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_ERROR;

    if (fieldOff == FALSE)
    {
        // DEBUG_MESSAGE("Analyze Results\r\n");

        /* Analyze the technology we discovered */
        switch (nfcDevice.ModeTech)
        {
            case NFC_TECH_15693:
                distIntermediateResult = DIST_RESULT_PROHIBIT;
                break;

            case NFC_TECH_F:
                distIntermediateResult = Dist_analyzeTypeF();
                break;

            case NFC_TECH_A:
                distIntermediateResult = Dist_analyzeTypeA();
                break;

            case NFC_TECH_B:
            	distIntermediateResult = DIST_RESULT_PROHIBIT;
                break;

            default:
                assert_msg(FALSE, "Unknown technology");
                distIntermediateResult = DIST_RESULT_ERROR;
                break;
        }

        /* We reached a final state so we return IN_PROGRESS once again
         * to come back here again and switch off the field */
        if ((distIntermediateResult != DIST_RESULT_IN_PROGRESS)
                && (distIntermediateResult != DIST_RESULT_ERROR))
        {
            fieldOff = TRUE;
            return DIST_RESULT_IN_PROGRESS;
        }
        else
        {
            return distIntermediateResult;
        }
    }
    else
    {
        /* Turn off field */
        result = CPAL_fieldOff();

        if ((result == DIST_RESULT_ERROR) || (result == DIST_RESULT_IN_PROGRESS))
        {
            return result;
        }
        else
        {
            /* Field off done -> return previously saved state */
            return distIntermediateResult;
        }
    }
}

uint32_t test_cnt_HaltA = 0;
uint32_t test_cnt_RequestA = 0;
uint32_t reset_cnt_RequestA = 0;
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_recoverDigitalTypeA(void)
{
	VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_RESUME;
	phStatus_t status = 0;
	uint8_t bAtqa = 0;
	P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop = phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);

	/* Field is already on and card is activated */

	/* Send SLP_REQ */
	do
	{
		status = phpalI14443p3a_HaltA(pDiscLoop->pPal1443p3aDataParams);
test_cnt_HaltA++;
	} while(status == PH_STATUS_INPROCESS);

	if(status != PH_ERR_SUCCESS)
	{
		return DIST_RESULT_ERROR;
	}

reset_cnt_RequestA = 0;
	/* Send SENS_REQ again */
	do
	{
		status = phpalI14443p3a_RequestA(pDiscLoop->pPal1443p3aDataParams, &bAtqa);
test_cnt_RequestA++;
reset_cnt_RequestA++;
	// } while(status == PH_STATUS_INPROCESS);
	} while((status == PH_STATUS_INPROCESS) && (reset_cnt_RequestA < 155));

	/* If there is a response return prohibit */
	if(status == PH_ERR_SUCCESS)
	{
		// CONSOLE_MESSAGE("\r\n\tFound lost Type A endpoint.\r\n");
		result = DIST_RESULT_PROHIBIT;
	}

	return result;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_analyzeTypeA(void)
{
    DEBUG_MESSAGE("Analyze Type A\r\n");
    VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_ERROR;

    /* Store support for 14443-4 for further distinguishing tasks */
    switch (nfcDevice.Protocol)
    {
        case NFC_PROT_T1T:
            /* There is no Card emulation for T1*/
            DEBUG_MESSAGE("\tT1T found - PROHIBIT\r\n");
            result = DIST_RESULT_PROHIBIT;
            break;

        case NFC_PROT_T2T:
            DEBUG_MESSAGE("\tT2T found, continue...\r\n");
            result = DIST_RESULT_RESUME;
            break;

        case NFC_PROT_NFCDEP:
            /* NFC DEP support implies card emulation */
            DEBUG_MESSAGE("\tNFCDEP found - ALLOW\r\n");
            result = DIST_RESULT_ALLOW;
            break;

        default:
            /* NFC DEP support implies card emulation */
            if (nfcDevice.Interface == NFC_INTF_NFC_DEP)
            {
                DEBUG_MESSAGE("\tNFCDEP found - ALLOW\r\n");
                result = DIST_RESULT_ALLOW;
                break;
            }

            /* non pure software analysis -> use non blocking index */
            switch (analyzeIndex)
            {
                case ANALYZE_PASSPORT:
                    result = CPAL_hasPassportAID();
                    /* In progress or prohibit */
                    if (result == DIST_RESULT_RESUME)
                    {
                        /* Resume -> no decision can be made
                         * Continue with next analyze step */
                        analyzeIndex = ANALYZE_PATTERNS;
                                // CONSOLE_MESSAGE("\tNo Passport AID found, continue..\r\n");
                        result = DIST_RESULT_IN_PROGRESS;
                    }
                    break;

                case ANALYZE_PATTERNS:
                    result = Dist_Assume_NoPatterns();
                    if (result == DIST_RESULT_RESUME)
                    {
                        analyzeIndex = ANALYZE_PASSPORT;
                                // CONSOLE_MESSAGE("\tNo pattern found, continue...\r\n");
                        result = DIST_RESULT_RESUME;
                    }
                    break;

                default:
                    assert_msg(FALSE, "Unknown Analyze Step");
                    return DIST_RESULT_ERROR;
            }
            break;
    }

    result = Dist_recoverDigitalTypeA();

	if(result == DIST_RESULT_PROHIBIT)
	{
		return result;
	}

    return result;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_analyzeTypeF(void)
{
    // CONSOLE_MESSAGE("Analyze Type F\r\n");

    if ((nfcDevice.Protocol == NFC_PROT_ISODEP)
            || (nfcDevice.Protocol == NFC_PROT_NFCDEP))
    {
        DEBUG_MESSAGE("\tNFC_PROT_ISODEP or NFC_PROT_NFCDEP found - ALLOW\r\n");
        return DIST_RESULT_ALLOW;
    }
    else
    {
        /* NFC DEP implies card emulation */
        if (nfcDevice.Interface == NFC_INTF_NFC_DEP)
        {
            DEBUG_MESSAGE("\tNFC_INTF_NFC_DEP found - ALLOW\r\n");
            return DIST_RESULT_ALLOW;
        }
        else
        {
            return Dist_CheckPAD0(nfcDevice.Uid[9]);
        }
    }
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_CheckPAD0(CONST(uint8, ANFCRL_CONST) pad0_1)
{
    /* The first byte of PAD0 codes, if the device is emulated.
     * TODO note source of this information */
    if ((pad0_1 == 0xFFU) || /* NFC-DEP */
    (pad0_1 == 0x06U) || /* Mobile Felica Vs 1 */
    (pad0_1 == 0x07U) || /* Mobile Felica Vs 1 */
    ((pad0_1 >= 0x10U) && (pad0_1 < 0x20U))) /* Mobile Felica Vs 2 or 3 */
    {
        DEBUG_MESSAGE("\tPAD0 indicates Phone - ALLOW\r\n");
        return DIST_RESULT_ALLOW;
    }
    else
    {
        /* TODO: further checking, if there is *really* no phone, which
         *  implements a different number than the ones above */
        DEBUG_MESSAGE("\tPAD0 indicates Card - PROHIBIT\r\n");
        return DIST_RESULT_PROHIBIT;
    }
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_Assume_NoPatterns(void)
{
#ifndef NO_PATTERNS_ASSUMPTION
    return DIST_RESULT_RESUME;
#else /* NO_PATTERNS_ASSUMPTION */

    if ((nfcDevice.ModeTech == NFC_TECH_A) || (nfcDevice.ModeTech == NFC_TECH_B))
    {
        return Dist_FindPatterns(nfcDevice.Uid, nfcDevice.UidLen);
    }
    else
    {
        return DIST_RESULT_ERROR;
    }
#endif /* NO_PATTERNS_ASSUMPTION */
}

/*
 * Finds ids that contain hex speak and ids that have ascending, descending and all the same bytes.
 * Finding the pattern works by comparing the first byte of a hex word with each id byte and if they are
 * equal, continue to compare the id to that particular word.
 * This results in a rather acceptable average time complexity of O(ID_LEN * NR_OF_WORDS)
 */
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_FindPatterns(CONST(uint8, ANFCRL_CONST) ID[],
        CONST(uint8, ANFCRL_CONST) ID_LEN)
{
    VAR(uint8, ANFCRL_VAR) id_index;
    bool all_same = TRUE;
    bool ascending = TRUE;
    bool descending = TRUE;
#ifdef HEXSPEAK
    bool pattern_found = FALSE;
#endif /* HEXSPEAK */

    DEBUG_MESSAGE("\tLooking for Pattern in UID\r\n");

#ifdef HEXSPEAK
    VAR(uint8, ANFCRL_VAR) byte_index;
    VAR(uint8, ANFCRL_VAR) word_index;

    CONST(uint8, ANFCRL_CONST) NR_OF_WORDS = 14;
    CONST(uint8, ANFCRL_CONST) NR_OF_BYTES = 4;
    CONST(uint8, ANFCRL_CONST) HEX_WORDS[14][4] =
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

    DEBUG_MESSAGE("\tID:");
    for(id_index = 0U; id_index < ID_LEN; id_index++)
    {
        DEBUG_MESSAGE(" 0x%.2X", ID[id_index]);
    }DEBUG_MESSAGE(": ");

    for(id_index = 0U; id_index < ID_LEN; id_index++)
    {
        if (id_index > 0U)
        {
            if (ID[id_index] != ID[id_index - 1U])
            {
                all_same = FALSE;
            }

            if (ID[id_index] != (ID[id_index - 1U] + 1U))
            {
                ascending = FALSE;
            }

            if (ID[id_index] != (ID[id_index - 1U] - 1U))
            {
                descending = FALSE;
            }
        }
#ifdef HEXSPEAK

        /* Check if ID contains hex speak */
        for (word_index = 0; word_index < NR_OF_WORDS && pattern_found == FALSE; word_index++)
        {
            pattern_found = TRUE;

            for (byte_index = 0; byte_index < NR_OF_BYTES; byte_index++)
            {
                if (HEX_WORDS[word_index][byte_index] == 0x00)
                {
                    /* ignore padding */
                    continue;

                }
                else if (((id_index + byte_index) >= ID_LEN)
                        || (HEX_WORDS[word_index][byte_index] != ID[id_index + byte_index]))
                {

                    pattern_found = FALSE;
                    break;
                }
            }
        }
#endif
    }

#ifdef HEXSPEAK
    if (FALSE != pattern_found)
    {
        DEBUG_MESSAGE("Pattern found!\r\n");
        return DIST_RESULT_IN_PROGRESS;
    }
    else if (FALSE != all_same)
    {
        DEBUG_MESSAGE("All bytes the same!\r\n");
    }
#else 
    if (FALSE != all_same)
    {
        DEBUG_MESSAGE("All bytes the same!\r\n");
    }
#endif /* HEXSPEAK */
    else if (FALSE != ascending)
    {
        DEBUG_MESSAGE("Ascending!\r\n");
    }
    else if (FALSE != descending)
    {
        DEBUG_MESSAGE("Descending!\r\n");
    }
    else
    {
        DEBUG_MESSAGE("No Pattern found.\r\n");
    }

#ifdef HEXSPEAK
    if (all_same || ascending || descending || pattern_found)
#else 
    if (all_same || ascending || descending)
    #endif /* HEXSPEAK */
    {
        return DIST_RESULT_ALLOW;
    }
    else
    {
        return DIST_RESULT_RESUME;
    }
}

int32_t ratio_amp = 0;
int32_t ratio_amp_cnt = 0;
int32_t ratio_amp_allow = 0;
int32_t ratio_amp_prohibit = 0;
FUNC(DIST_RESULT_t, ANFCRL_CODE) Dist_LMD()
{
	static int8_t vddpaIndex = 0;
	static uint32_t vddpa[2] = { LMD_VDDPA_HIGH, LMD_VDDPA_LOW };
	static int32_t phase[2] = { 0, 0 };
	static int32_t peak_to_peak[2] = { 0, 0 };
	static uint8_t i = 0;
	int32_t ratio = 0;

	uint8_t bAtqa = 0;
	uint8 aTypeAUid[7] = {0};
	uint8 bTypeANvbUid = 0;

	DIST_RESULT_t result = DIST_RESULT_IN_PROGRESS;
	phStatus_t status = PH_ERR_SUCCESS;

	void* pHal = phNfcLib_GetDataParams(PH_COMP_HAL);

	switch(DIST_LMD_STATE_s)
	{
		case DIST_LMD_INIT:
			// CONSOLE_MESSAGE("\r\n\tLMD analysis\r\n");
			vddpaIndex = 0;
			memset(peak_to_peak, 0x00, sizeof(peak_to_peak));
			memset(phase, 0x00, sizeof(phase));
			DIST_LMD_CTS_INIT_STATE_s = DIST_LMD_CTS_INIT_INITILIAZE;
			DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_RETRIEVE_INIT;
			DIST_LMD_STATE_s = DIST_LMD_APPLY_PROTOCOL;
			break;

		case DIST_LMD_APPLY_PROTOCOL:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(pHal, PHHAL_HW_CARDTYPE_ISO14443A));
					// CHECK_SUCCESS_RETURN_ERR(status);
			DIST_LMD_STATE_s = DIST_LMD_FIELD_OFF;
			break;

		case DIST_LMD_FIELD_OFF:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOff(pHal));
			// CHECK_SUCCESS_RETURN_ERR(status);

			/* If second VDDPA loop done start again otherwise finish */
			if(vddpaIndex < sizeof(vddpa) / sizeof(vddpa[0]))
			{
				DIST_LMD_STATE_s = DIST_LMD_WAIT_FIELD_OFF;
			}
			else
			{
				DIST_LMD_STATE_s = DIST_LMD_FINISH;
			}
			break;

		case DIST_LMD_WAIT_FIELD_OFF:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Wait(pHal, PHHAL_HW_TIME_MILLISECONDS, 5));
			// CHECK_SUCCESS_RETURN_ERR(status);
			DIST_LMD_STATE_s = DIST_LMD_FIELD_ON;
			break;

		case DIST_LMD_FIELD_ON:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOn(pHal));
			if(status != PH_ERR_SUCCESS)
			{
				if((status & PH_ERR_MASK) == PH_ERR_RF_ERROR)
				{
					// CONSOLE_MESSAGE("Rf on failed due to Rf error - Multiple devices\r\n");
					return DIST_RESULT_PROHIBIT;
				}
				else
				{
					// CONSOLE_MESSAGE("Rf on failed\r\n");
					return DIST_RESULT_ERROR;
				}
			}
			DIST_LMD_STATE_s = DIST_LMD_SET_VDDPA;
			break;

		case DIST_LMD_SET_VDDPA:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteRegister(pHal, TXLDO_VDDPA_CONFIG, vddpa[vddpaIndex]));
			// CHECK_SUCCESS_RETURN_ERR(status);
			// CONSOLE_MESSAGE_ARGS("\t\tVDDPA: 0x%02X \t", (unsigned int)vddpa[vddpaIndex]);
			DIST_LMD_STATE_s = DIST_LMD_WAIT_GT;
			break;

		case DIST_LMD_WAIT_GT:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Wait(pHal, PHHAL_HW_TIME_MICROSECONDS, PH_NXPNFCRDLIB_CONFIG_TYPEA_GT));
			// CHECK_SUCCESS_RETURN_ERR(status);
			DIST_LMD_STATE_s = DIST_LMD_SEND_WUPA;
			break;

		case DIST_LMD_SEND_WUPA:		
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_WakeUpA(
					phNfcLib_GetDataParams(PH_COMP_PAL_ISO14443P3A),
					&bAtqa));

			if(status != PH_ERR_SUCCESS)
			{
				if((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
				{
					// CONSOLE_MESSAGE("Collision error during WakeUpA - Multiple devices\r\n");
				}

				/* Not a valid measurement */
				// CONSOLE_MESSAGE("WakeUpA failed\r\n");
				return DIST_RESULT_PROHIBIT;
			}
			DIST_LMD_STATE_s = DIST_LMD_CTS_INIT;
			break;

		case DIST_LMD_CTS_INIT:
			/* CTS Config and Enable */
			PH_CHECK_INPROCESS_FCT(status, CtsInit());
			if((status & PH_ERR_MASK) == PH_ERR_NCX3321_INSTR_ERROR)
			{
				// CONSOLE_MESSAGE(RED("Fast CTS not supported please modify Card Protection configuration!\r\n"));
			}
			// CHECK_SUCCESS_RETURN_ERR(status);

			if(vddpaIndex == 0)
			{
				/* VDDPA already set to high, no need for ramp up */
				DIST_LMD_STATE_s = DIST_LMD_SEND_ANTICOLLISION;
			}
			else
			{
				/* reset i to slow VDDPA ramp up */
				i = LMD_VDDPA_LOW;
				DIST_LMD_STATE_s = DIST_LMD_UPDATE_VDDPA;
			}
			break;

		case DIST_LMD_UPDATE_VDDPA:
			/* slow VDDPA ramp up to not reset cards */
			if (i <= LMD_VDDPA_HIGH)
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteRegister(pHal, TXLDO_VDDPA_CONFIG, i));
				// CHECK_SUCCESS_RETURN_ERR(status);
				i += 2;
				break;
			}
			else
			{
				DIST_LMD_STATE_s = DIST_LMD_SEND_ANTICOLLISION;
				/* no break required as only the state is set */
			}

		case DIST_LMD_SEND_ANTICOLLISION:
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_Anticollision(
					phNfcLib_GetDataParams(PH_COMP_PAL_ISO14443P3A),
					0x93,      		/* Cascade code */
					aTypeAUid,      /* Input UID */
					bTypeANvbUid,   /* UID len = 0 */
					aTypeAUid,      /* UID out */
					&bTypeANvbUid   /* UID out size */
					));

			if(status != PH_ERR_SUCCESS)
			{
				if((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
				{
					// CONSOLE_MESSAGE("Collision error during Anticollision - Multiple devices\r\n");
				}

				/* Not a valid measurement */
				// CONSOLE_MESSAGE("Anticollision failed\r\n");
				return DIST_RESULT_PROHIBIT;
			}
			DIST_LMD_STATE_s = DIST_LMD_CTS_RETRIEVE;
			break;

		case DIST_LMD_CTS_RETRIEVE:
			/* CTS Retrieve Log */
			result = CtsRetrieve(&peak_to_peak[vddpaIndex], &phase[vddpaIndex], vddpa[vddpaIndex]);
			if(result == DIST_RESULT_IN_PROGRESS)
			{
				return result;
			}
			else if(result == DIST_RESULT_ALLOW)
			{
				return result;
			}
			else if(result == DIST_RESULT_ERROR)
			{
				// CONSOLE_MESSAGE_ARGS("\tResponse not correctly decoded from CTS log, noise?\r\n");
				return DIST_RESULT_PROHIBIT;
			}

			result = DIST_RESULT_IN_PROGRESS;

			/* If second VDDPA loop not done start again otherwise finish */
			if(vddpaIndex < sizeof(vddpa) / sizeof(vddpa[0]))
			{
				vddpaIndex++;
			}

			DIST_LMD_STATE_s = DIST_LMD_FIELD_OFF;
			break;

		case DIST_LMD_FINISH:
			/* Calculate peak ratio and conclude */
			ratio = 100 - 1.0 * min_val(peak_to_peak[0], peak_to_peak[1]) / max_val(peak_to_peak[0], peak_to_peak[1]) * 100;
ratio_amp = ratio;
ratio_amp_cnt++;
			if (ratio <= AMPLITUDE_CHANGE_THRESHOLD)
			{
				// CONSOLE_MESSAGE_ARGS("\tAmpRatio = %ld\r\n", ratio);
				result = DIST_RESULT_PROHIBIT;
ratio_amp_prohibit++;
			}
			else
			{
				// CONSOLE_MESSAGE_ARGS("\tAmpRatio = %ld\r\n", ratio);
				result = DIST_RESULT_ALLOW;
ratio_amp_allow++;
			}
			DIST_LMD_STATE_s = DIST_LMD_INIT;
			break;

		default:
			DIST_LMD_STATE_s = DIST_LMD_INIT;
			break;
	}

	return result;
}

FUNC(phStatus_t, ANFCRL_CODE) CtsInit(void)
{
	phStatus_t status;
	void* pHal = phNfcLib_GetDataParams(PH_COMP_HAL);

	/* CTS Config */
	phhalHw_Ncx3321_Instr_CtsConfig_t ctsConfig =
	{
			.bPreTriggerShift 	= 0x00,
			.bTriggerMode 		= 0x00,
			.bRamPageWidth 		= PAGE_SIZE / 256 - 1, /* 0x03 - Capturing 1024 bytes should be sufficient (256 bytes per step, 512 is min) */
			.bSampleClkDiv 		= 0x01, /* Sampling Rate 02h - 3390 kHz should be sufficient */
			.bSampleByteSel 	= 0x04,
			.bSampleModeSel 	= 0x00,
			.bTB0 				= 0x78,
			.bTB1 				= 0x79,
			.bTB2 				= 0x7A,
			.bTB3 				= 0x7B,
			.bTTBSelect 		= 0x9B,
			.dwClifCtsTbCtrl 	= 0x00000000,
			.dwHw0Trigger0 		= 0x00100010,
			.dwHw0Trigger1 		= 0x00000010,
			.dwHw0Trigger2 		= 0x00077777,
			.dwHw1Trigger0 		= 0x00000000,
			.dwHw1Trigger1 		= 0x00000000,
			.dwHw1Trigger2 		= 0x49877777	/* Delay of 90us to start capturing in the middle of ATQA */
	};


	switch(DIST_LMD_CTS_INIT_STATE_s)
	{
		case DIST_LMD_CTS_INIT_INITILIAZE:

			DIST_LMD_CTS_INIT_STATE_s = DIST_LMD_CTS_INIT_CONFIGURE;
			//no break required as SW initialization only

		case DIST_LMD_CTS_INIT_CONFIGURE:
#if(FAST_CTS_EXECUTION == (STD_ON))
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_CtsFastConfigEnable(pHal, &ctsConfig));
			PH_CHECK_SUCCESS(status);
			DIST_LMD_CTS_INIT_STATE_s = DIST_LMD_CTS_INIT_INITILIAZE;
			return status;
#else
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_CtsConfig(pHal, &ctsConfig));
			PH_CHECK_SUCCESS(status);
			DIST_LMD_CTS_INIT_STATE_s = DIST_LMD_CTS_INIT_ENABLE;
			return PH_STATUS_INPROCESS;
#endif

		case DIST_LMD_CTS_INIT_ENABLE:
			/* CTS Enable */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_CtsEnable(pHal, PH_ON));
			PH_CHECK_SUCCESS(status);
			DIST_LMD_CTS_INIT_STATE_s = DIST_LMD_CTS_INIT_INITILIAZE;
			break;

		default:
			return PH_ERR_INTERNAL_ERROR;

	}

	return status;
}

/* Function to remove the DC value from the original array */
void RemoveDcValue(sint16 *originals)
{
	sint16 diff_data[NUM_SAMPLES];
	int32_t dc_value = 0;
	int32_t i = 0;

	if (diff_data == NULL)
	{
		/* Handle memory allocation failure */
		// CONSOLE_MESSAGE("Memory allocation failed.\r\n");
		return;
	}

    /* Calculate the difference data */
    for (i = 0; i < NUM_SAMPLES - 1; i++)
    {
        diff_data[i] = originals[i + 1] - originals[i];
    }

    /* Find the DC value to remove */
    dc_value = FindDcValue(diff_data, originals);

    /* Subtract the DC value from the original array */
    for (i = 0; i < NUM_SAMPLES; i++)
    {
    	originals[i] = originals[i] - dc_value;
    }
}

int32_t FindDcValue(sint16 diffdata[], sint16 original[])
{
	int32_t max_length = 0;
	int32_t current_length = 0;
	int32_t start = 0;
	int32_t end = 0;
	int32_t temp_start = 0;
    int32_t sum = 0;
    int32_t i = 0;
    float64 dc_average_value = 0;

    for (i = 0; i < NUM_SAMPLES; i++)
    {
        if (diffdata[i] >= -20 && diffdata[i] <= 20)
        {
            if (current_length == 0)
            {
                temp_start = i;  /* Mark the possible start position */
            }
            current_length++;
            if (current_length > max_length)
            {
                max_length = current_length;
                start = temp_start;
                end = i;  /* Record the end position of the current sequence */
            }
        }
        else
        {
            current_length = 0;  /* Reset */
        }
    }

    /* Calculate average value for the longest subarray where diff is within [-20, 20] */
    for (i = start; i <= end; i++)
    {
        sum += original[i];
    }
    dc_average_value = (float64)sum / (end - start + 1);
    return (int32_t)dc_average_value;
}

/* Main function to find periodical signal */
void FindPeriodicalSignal(sint16 raw_values[], uint32_t length, uint32_t *start, uint32_t *end, int32_t *peak_to_peak_value)
{
	int32_t max_value = 0;
	int32_t min_value = 0;
    float64 check_value = 0;

    max_value = FindMax(raw_values, 0, length - 1);
    min_value = FindMin(raw_values, 0, length - 1);
    check_value = (max_value - min_value) / 5.0;

    /* max - (2/5 amp peak peak) */
    float64 line_value = max_value - 2 * check_value;

    int32_t index = 1;
    int32_t count = 0;
    int32_t count_index[4] = {0};

    while (index < length - 2)
    {
        if (raw_values[index - 1] < line_value && raw_values[index] > line_value)
        {
            count_index[count] = index;

            /* not able to find 4 periodic lows/highs in a row */
            if (count > 0 && (count_index[count] - count_index[count - 1]) >= 15)
            {
                count = 0; /* Reset count */
                count_index[0] = index;
            }
            if (count >= 3)
            {
                break;
            }

            count++;
        }
        index++;
    }

    if (count != 3)
    {
    	// CONSOLE_MESSAGE(YLW("Periodic signal not identified\r\n"));
        return; /* Early return if the count is not 4 */
    }

    *start = count_index[0];
    *end = count_index[3];

    *peak_to_peak_value = FindMax(raw_values, *start, *end) - FindMin(raw_values, *start, *end);
}

int32_t diff_phase = 0;
int32_t diff_phase_360 = 0;
int32_t diff_phase_cnt = 0;
int32_t diff_phase_allow = 0;
uint32_t IQ_numSatValues = 0;
uint32_t IQ_numSatValues_cnt = 0;
uint32_t IQ_numSatValues_allow = 0;

FUNC(DIST_RESULT_t, ANFCRL_CODE) CtsRetrieve(int32_t * peak_to_peak, int32_t * phase, uint8_t vddpa)
{
	DIST_RESULT_t result = DIST_RESULT_IN_PROGRESS;

	static uint8_t pLogData[CHUNK_SIZE] = { 0 };
	static uint8_t bLogDataSize = 0;

	int32_t adc_i_val = 0;
	int32_t adc_q_val = 0;
	uint16_t amplitude = 0;
	static int32_t current_phase = 0;

	static uint16_t i = 0;
	static uint8_t j = 0;
	static uint16_t store_index = 0;
	uint32_t value = 0;
	static uint32_t numSatValues = 0;
	phStatus_t status;

	int32_t i_val_max_amp = 0;
	int32_t q_val_max_amp = 0;
	uint32_t maxAmpIndex = 0;

	int32_t maxVal = 0;
	int32_t minVal = 0;

	static uint32_t start_index = 0;
	static uint32_t end_index = 0;
	static int32_t peak_to_peak_value = 0;

	P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pHal = phNfcLib_GetDataParams(PH_COMP_HAL);

	switch(DIST_LMD_CTS_RETRIEVE_s)
	{
		case DIST_LMD_CTS_RETRIEVE_INIT:
			memset(pLogData, 0x00, sizeof(pLogData));
			bLogDataSize = 0;
			i = 0;
			j = 0;
			current_phase = 0;
			store_index = 0;
			start_index = 0;
			end_index = 0;
			peak_to_peak = 0;
			numSatValues = 0;
			DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_CHECK_EVT;
			//no break required as SW initialization only

		case DIST_LMD_CTS_CHECK_EVT:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadRegister(pHal, 0x02, &value));
			// CHECK_SUCCESS_RETURN_ERR(status);

			/* Check if event occurred to then retrieve and analyze log */
			if ((value & (1 << 11)) == 0)
			{
				// CONSOLE_MESSAGE("Event not occurred, measurement cannot be done\r\n");
				return DIST_RESULT_ERROR;
			}
			else
			{
				pHal->bCTSEvent = 0x01;
				DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_RETRIEVE_HEADER;

			}
			break;

		case DIST_LMD_CTS_RETRIEVE_HEADER:
			/* Read header */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_CtsRetrieveLog(
					pHal, 60, pLogData, &bLogDataSize));

			if ((status & 0xFF) != PH_ERR_NCX3321_SUCCESS_CHAINING)
			{
				return DIST_RESULT_ERROR;
			}
			DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_RETRIEVE_DATA;
			break;

		case DIST_LMD_CTS_RETRIEVE_DATA:
			if(i < PAGE_SIZE / CHUNK_SIZE)
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_CtsRetrieveLog(
						pHal, CHUNK_SIZE, pLogData, &bLogDataSize));

				if (status != PH_ERR_SUCCESS && (status & 0xFF) != PH_ERR_NCX3321_SUCCESS_CHAINING)
				{
					return DIST_RESULT_ERROR;
				}

				DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_PARSE_CHUNK;
			}
			else
			{
				/* Everything received */
				DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_FIND_PERIODIC;
			}
			break;

		case DIST_LMD_CTS_PARSE_CHUNK:
			for(j = 0; j <= bLogDataSize - 4; j+= 4)
			{
				/* Parse I and Q value from received data */
				adc_i_val = (pLogData[j + 0] << 2) + (pLogData[j + 1] & 0x03);
				adc_q_val = (pLogData[j + 2] << 2) + (pLogData[j + 3] & 0x03);

				/* Convert to signed decimal */
				adc_i_val -= (adc_i_val & 0x200) ? 1024 : 0;
				adc_q_val -= (adc_q_val & 0x200) ? 1024 : 0;

				/* Check if value is saturated and inform application */
				if(abs(adc_i_val) >= 511 || abs(adc_q_val) >= 511)
				{
					numSatValues++;
				}

				/* Peak Amplitude = sqrt(I^2 + Q^2) */
				amplitude = sqrt(adc_i_val * adc_i_val + adc_q_val * adc_q_val);

#if(DEBUG_PRINT_CTS_DATA == (STD_ON))
				// CONSOLE_MESSAGE("index=%d;amp=%d;i=%ld;q=%ld\r\n",i*CHUNK_SIZE + j, amplitude, adc_i_val, adc_q_val);
#endif

				amp[store_index] = amplitude;
				i_channel[store_index] = adc_i_val;
				q_channel[store_index] = adc_q_val;
				store_index++;
			}

			i++;

			/* Receive next chunk */
			DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_RETRIEVE_DATA;
			break;

		case DIST_LMD_CTS_FIND_PERIODIC:
			RemoveDcValue(i_channel);
			RemoveDcValue(q_channel);

			for (i = 0; i < NUM_SAMPLES; i++)
			{
				amp[i] = sqrt(i_channel[i] * i_channel[i] + q_channel[i] * q_channel[i]);
			}

			/* Start index used for phase shift calculation */
			FindPeriodicalSignal(amp, NUM_SAMPLES, &start_index, &end_index, &peak_to_peak_value);
			if(end_index - start_index <= 0)
			{
				return DIST_RESULT_ERROR;
			}
			DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_ANALYZE_DATA;
			break;

		case DIST_LMD_CTS_ANALYZE_DATA:
			/* Calculate phase from identified periodic signal */
			maxAmpIndex = FindMaxIndex(amp, start_index, end_index);
			i_val_max_amp = i_channel[maxAmpIndex];
			q_val_max_amp = q_channel[maxAmpIndex];

			current_phase = (int32_t)(atan2(i_val_max_amp, q_val_max_amp) * 180.0 / M_PI);
			if(current_phase < 0)
			{
				current_phase = (current_phase + 360) % 360;
			}

			/* first measurement - previous phase does not have a value yet */
			if(previous_phase == -1)
			{
				previous_phase = current_phase;
			}

			maxVal = FindMax(amp, start_index, end_index);
			minVal = FindMin(amp, start_index, end_index);

			// CONSOLE_MESSAGE_ARGS("start: %ld; end: %ld; ampPP: %ld; maxVal: %ld; minVal: %ld; phase: %ld\r\n",
			// 					start_index, end_index, peak_to_peak_value, maxVal, minVal, current_phase);

			if(vddpa == LMD_VDDPA_HIGH && maxVal < 30)
			{
				// CONSOLE_MESSAGE(YLW("\t\tMax amplitude value for high VDDPA rather low, ratio might not be accurate\r\n"));
			}

diff_phase = abs(current_phase - previous_phase);
diff_phase_360 = 360 - abs(current_phase - previous_phase);
diff_phase_cnt++;
			/* In case phase shift difference is more than X degrees we know it's a phone */
			if(abs(current_phase - previous_phase) > PHASE_DIFFERENT_THRESHOLD && (360 - abs(current_phase - previous_phase)) > PHASE_DIFFERENT_THRESHOLD)
			{
				// CONSOLE_MESSAGE_ARGS("\t\tPhase shift detected above %d degrees detected\r\n", PHASE_DIFFERENT_THRESHOLD);
				result = DIST_RESULT_ALLOW;
diff_phase_allow++;
			}
			else
			{
				/* Pass result one level higher */
				result = DIST_RESULT_RESUME;
			}

			previous_phase = current_phase;
			previous_phase_i = i_val_max_amp;
			previous_phase_q = q_val_max_amp;

			*phase = current_phase;
			*peak_to_peak = peak_to_peak_value;

			if(numSatValues > 0)
			{
				// CONSOLE_MESSAGE_ARGS(YLW("\t\tI or Q saturated %ld times!\r\n"), numSatValues);

#if(CHECK_SATURATED_IQ == (STD_ON))
IQ_numSatValues = numSatValues;
IQ_numSatValues_cnt++;
				if(numSatValues > NUM_SATURATED_IQ_THRESHOLD)
				{
					// CONSOLE_MESSAGE_ARGS("\t\tSaturated IQ values exceeding threshold of %d\r\n", NUM_SATURATED_IQ_THRESHOLD);
					result = DIST_RESULT_ALLOW;
IQ_numSatValues_allow++;
				}
#endif
			}

			DIST_LMD_CTS_RETRIEVE_s = DIST_LMD_CTS_RETRIEVE_INIT;
			break;

		default:
			return DIST_RESULT_ERROR;
	}

	return result;
}

#if(CLEAN_SURFACE_CHECK == (STD_ON))
FUNC(phStatus_t, ANFCRL_CODE) Dist_cleanSurfaceGetHfAtt(uint8 *hfAtt)
{
	VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
	static VAR(uint32, ANFCRL_VAR) regVal = 0U;
    phhalHw_Ncx3321_DataParams_t * pHal = phNfcLib_GetDataParams(PH_COMP_HAL);

    switch(cleanSurfaceState)
	{
		case APPLY_PROTOCOL_SETTINGS:
			/* Load Protocol Settings to turn field on */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(pHal, PHHAL_HW_CARDTYPE_ISO14443A));
			PH_CHECK_SUCCESS(status);
			cleanSurfaceState = FIELD_ON;
			break;

		case FIELD_ON:
			/* Field On - default VDDPA which should be 4.7V */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOn(pHal));
			PH_CHECK_SUCCESS(status);
			cleanSurfaceState = WAIT_STABLE_RF;
			break;

		case WAIT_STABLE_RF:
			/* Delay to wait for stable RF conditions */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Wait(pHal, PHHAL_HW_TIME_MICROSECONDS, 1500U));
			PH_CHECK_SUCCESS(status);
			cleanSurfaceState = GET_HFATT;
			break;

		case GET_HFATT:
			/* Read Hf att */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadRegister(pHal, CLIF_RXCTRL_STATUS, &regVal));
			PH_CHECK_SUCCESS(status);
			cleanSurfaceState = FIELD_OFF;
			break;

		case FIELD_OFF:
			/* Field Off */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOff(pHal));
			PH_CHECK_SUCCESS(status);
			cleanSurfaceState = APPLY_PROTOCOL_SETTINGS;

			/* assign hf att value */
			*hfAtt = (uint8)((regVal & CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_MASK) >> CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_POS);
			return status;

		default:
			cleanSurfaceState = APPLY_PROTOCOL_SETTINGS;
			break;
	}

	return PH_STATUS_INPROCESS;
}
#endif


/* Helper functions */

/* Find the maximum value in an array */
int32_t FindMax(sint16 array[], uint32_t start, uint32_t end)
{
	int32_t max = 0;
	int32_t i = 0;

    if ((end - start) <= 0)
    {
    	// CONSOLE_MESSAGE("Invalid arguments in findMax().\n");
        return 0;
    }

    max = array[start];

    for (i = start + 1; i < end; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

/* Find the maximum value in an array */
int32_t FindMaxIndex(sint16 array[], uint32_t start, uint32_t end)
{
	int32_t max = 0;
	int32_t maxIndex = 0;
	int32_t i = 0;

    if ((end - start) <= 0)
    {
    	// CONSOLE_MESSAGE("Invalid arguments in findMaxIndex().\n");
        return 0;
    }

    max = array[start];
    maxIndex = start;

    for (i = start + 1; i < end; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

/* Find the minimum value in an array */
int32_t FindMin(sint16 array[], uint32_t start, uint32_t end)
{
	int32_t min = 0;
	int32_t i = 0;

    if ((end - start) <= 0)
    {
    	// CONSOLE_MESSAGE("Invalid arguments in findMin().\n");
        return 0;
    }

    min = array[start];

    for (i = start + 1; i < end; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}


/* Change the DGRM_BBA Configuration */

/* DGRM_BBA : FW default 0xED4D24A4, 0x00012400U for 18dB, 00004900 for 0dB

*            00009200 for 6dB , 0000DB00 for 12dB

*/

// FUNC(phStatus_t, ANFCRL_CODE) NCx3321_CFG_REG_BBA(uint32 vDgrmBBA)
FUNC(void, ANFCRL_CODE) NCx3321_CFG_REG_BBA(uint32 vDgrmBBA)	// Code Sonar
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
	VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
	// VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwBBARegister, tdwRegister;
	// VAR(uint8, ANFCRL_VAR) pRfConfBuf[PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE];
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwBBARegister = 0, tdwRegister = 0;	// Code Sonar
	VAR(uint8, ANFCRL_VAR) pRfConfBuf[PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE] = {0, };	// Code Sonar
	VAR(uint16, ANFCRL_VAR) RfConfBufSize = sizeof(pRfConfBuf);
	VAR(uint16, ANFCRL_VAR) i = 0;
	uint8 buf[6];

	/* Check BBA gain for Type A */
	do
	{
		status = phhalHw_Ncx3321_Instr_RetrieveRfConfiguration(pHal, PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC, pRfConfBuf, &RfConfBufSize);
	} while(status == PH_STATUS_INPROCESS);



	for(i = 0; i < RfConfBufSize; i += 5)
	{
		if(pRfConfBuf[i] == CLIF_DGRM_BBA)
		{
			dwBBARegister = pRfConfBuf[i+1];
			dwBBARegister |= (((uint32) pRfConfBuf[i+2]) << 8U);
			dwBBARegister |= (((uint32) pRfConfBuf[i+3]) << 16U);
			dwBBARegister |= (((uint32) pRfConfBuf[i+4]) << 24U);
			DEBUG_PRINTF("\tREG_DGRM_BBA = 0x%lx\r\n", dwBBARegister);
			DEBUG_PRINTF("\t\tDGRM_BBA_MIN_VAL=%d\r\n", (uint8)((dwBBARegister & CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_MASK) >> CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_POS));
			DEBUG_PRINTF("\t\tDGRM_BBA_MAX_VAL=%d\r\n", (uint8)((dwBBARegister & CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_MASK) >> CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_POS));
			DEBUG_PRINTF("\t\tDGRM_BBA_INIT_VAL=%d\r\n", (uint8)((dwBBARegister & CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_MASK) >> CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_POS));
		}
	}

	/* Update if the current value is not equal to the input value. */
	tdwRegister = dwBBARegister & (0x0001FF00U);
	
	if ( (vDgrmBBA & (0x0001FF00U)) != tdwRegister )
	{
		dwBBARegister = dwBBARegister & (0xFFFE00FFU);
		dwBBARegister = dwBBARegister | (vDgrmBBA & (0x0001FF00U));

		buf[0] = 0x80; // RX ISO14443A 106
		buf[1] = 0x2D; // DGRM_BBA (002Dh), default 0xED4D24A4
		buf[2] = (uint8)(dwBBARegister & 0xFFU);
		buf[3] = (uint8)((dwBBARegister & 0xFF00U) >> 8U);
		buf[4] = (uint8)((dwBBARegister & 0xFF0000U) >> 16U);
		buf[5] = (uint8)((dwBBARegister & 0xFF000000U) >> 24U);

		do {
			phhalHw_Ncx3321_Instr_UpdateRfConfiguration(pHal,buf, 6U);
		} while (status == PH_STATUS_INPROCESS);

		if ( status == PH_ERR_SUCCESS)
		{
			DEBUG_PRINTF("\tUpdate the REG_DGRM_BBA to 0x%lx\r\n", dwBBARegister);
			DEBUG_PRINTF("\t\tDGRM_BBA_MIN_VAL=%d\r\n", (uint8)((dwBBARegister & CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_MASK) >> CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_POS));
			DEBUG_PRINTF("\t\tDGRM_BBA_MAX_VAL=%d\r\n", (uint8)((dwBBARegister & CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_MASK) >> CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_POS));
			DEBUG_PRINTF("\t\tDGRM_BBA_INIT_VAL=%d\r\n", (uint8)((dwBBARegister & CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_MASK) >> CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_POS));
		}
		else
		{
			DEBUG_PRINTF("\tUpdate Failed 0x%x\r\n", status);
		}
	}
}
