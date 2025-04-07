/*
 (c) NXP B.V. 2009-2019. All rights reserved.

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
 * dinstinguishing.h contains some data structures required in this file.
 */

/* NIDEC_PORTING */
#include <ph_Status.h>
#include <phApp_Init.h>
#include "App_NFC.h"
#include "EcuInfo.h"
/* NIDEC_PORTING */

#include "CPAL.h"
#include "distinguishing_types.h"

#define PASSPORT_ENABLED 0
/*############################################################
 *
 *                        INCLUDES
 *
 ###########################################################*/
#include <phNfcLib.h>
#include <phpalI14443p4.h>
#include <phacDiscLoop.h>
#include "phhalHw_Ncx3321_Instr.h"
#include "phDriver_Timer.h"
#include "distinguishing.h"

/*############################################################
 *
 *                      COMPILER FLAGS
 *
 ###########################################################*/

/*############################################################
 *
 *                  FUNCTION-LIKE MACROS
 *
 ###########################################################*/

/*############################################################
 *
 *                        GLOBALS
 *
 *##########################################################*/


VAR(NFC_DEVICE_t, ANFCRL_VAR) nfcDevice;

#if((STD_ON) == ANFCRL_VAS_ENABLED)
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0x6AU, 0x02U, 0xC3U, 0x02U, 0x01U, 0x01U, 0x0FU, 0xFFU };
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x0F, 0x03 }; // HKMC Mock-Test
 static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { cTCI_Code1, cTCI_Code2, cTCI_Code3, cTCI_Code4, cTCI_Code5, cTCI_Code6, cTCI_Code7, cTCI_Code8 };	// WPC_415_04
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED */

/*############################################################
 *
 *                        CONSTANTS
 *
 *##########################################################*/

/*############################################################
 *
 *                     Static variables
 *
 ###########################################################*/

/*############################################################
 *
 *                        FUNCTIONS
 *
 ###########################################################*/
FUNC(void, ANFCRL_CODE) print_Buff(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff, VAR(uint8, ANFCRL_VAR) num);
#if((STD_ON) == ANFCRL_VAS_ENABLED)
static FUNC(phStatus_t, ANFCRL_CODE) InitVAS(void);
static FUNC(phStatus_t, ANFCRL_CODE) LoadProfileNfcMode(void);
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED */

/* Local headers */
/*******************************************************************************
 **   Enum Defines
 *******************************************************************************/

/*******************************************************************************
 **   Global Defines
 *******************************************************************************/
static VAR(aNfcRdLibState_t, ANFCRL_VAR) aNfcRdlibState = ANFC_RDLIB_ST_INIT;

static VAR(DIST_RESULT_t, ANFCRL_VAR) cpalIntermediateResult = DIST_RESULT_ERROR;

static VAR(uint8, ANFCRL_VAR) aResponseHolder[64] = { 0x00U };

static VAR(phStatus_t, ANFCRL_VAR) discLoopStatus_g = PH_ERR_INTERNAL_ERROR;

static VAR(uint8, ANFCRL_VAR) extFieldDetected = 0U;
VAR(sint8, ANFCRL_VAR) printBuffer[1024];

/* ----------------------------------------------- */
/***                CPAL Functions               ***/
/* ----------------------------------------------- */
FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_reset(void)
{
    extFieldDetected = 0U;
    // CONSOLE_MESSAGE(GRN("\n\rNXP - Card Protection with Load Modulation Detection\r\n"));
    // CONSOLE_MESSAGE_ARGS("Amplitude Ratio Threshold: %d\r\n", AMPLITUDE_CHANGE_THRESHOLD);
    // CONSOLE_MESSAGE_ARGS("Phase Shift Threshold: %d\r\n", PHASE_DIFFERENT_THRESHOLD);
    // CONSOLE_MESSAGE_ARGS("Low VDDPA: 0x%02X, High VDDPA: 0x%02X\r\n", LMD_VDDPA_LOW, LMD_VDDPA_HIGH);
#if(FAST_CTS_EXECUTION == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Fast CTS enabled\r\n");
#else
    // CONSOLE_MESSAGE_ARGS("Fast CTS disabled\r\n");
#endif

#if(CHECK_MULTI_TECH_SUPPORT == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Multiple technology check enabled\r\n");
#else
    // CONSOLE_MESSAGE_ARGS("Multiple technology check disabled\r\n");
#endif

#if(CLEAN_SURFACE_CHECK == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Clean surface check enabled\r\n");
#if(CLEAN_SURFACE_CALIBRATE == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Clean surface calibration enabled\r\n");
#else
    // CONSOLE_MESSAGE_ARGS("Clean surface calibration disabled\r\n");
#endif
    // CONSOLE_MESSAGE_ARGS("Clean surface HF Attenuation Threshold: %d\r\n", CLEAN_SURFACE_HFATT_THRESHOLD);
#else
    // CONSOLE_MESSAGE_ARGS("Clean surface check disabled\r\n");
#endif

#if(CHECK_SATURATED_IQ == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Check for saturated IQ values enabled\r\n");
    // CONSOLE_MESSAGE_ARGS("Threshold for number of saturated values in log: %d\r\n", NUM_SATURATED_IQ_THRESHOLD);
#else
    // CONSOLE_MESSAGE_ARGS("Check for saturated IQ values disabled\r\n");
#endif

    // CONSOLE_MESSAGE_ARGS("\r\n\r\n");

    return DIST_RESULT_RESUME;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_init(void)
{
    return DIST_RESULT_RESUME;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) scanNonBlocking(
        VAR(DistinguishingState_t, ANFCRL_VAR) DIST_STATE_c)
{
    VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_ERROR;

    if (aNfcRdlibState == ANFC_RDLIB_ST_IDLE)
    {
        aNfcRdlibState = ANFC_RDLIB_ST_INIT;

        switch (DIST_STATE_c)
        {
            case DIST_ST_SCAN_ALL:
                // CONSOLE_MESSAGE("Scan All Types\r\n");
                break;
            case DIST_ST_SCAN_BF:
                // CONSOLE_MESSAGE("Scan Type BFV\r\n");
                break;
            default:
                // CONSOLE_MESSAGE("Unknown Scan State\r\n");
        }
    }

    switch (aNfcRdlibState)
    {
    	case ANFC_RDLIB_ST_INIT:
		case ANFC_RDLIB_ST_START_DISCOVERY:
            return scanField(DIST_STATE_c);
        case ANFC_RDLIB_ST_CHECK_NTF:
            /* Scan until timeout */
            return getFieldContent();
        case ANFC_RDLIB_ST_STOP_DISCOVERY:
            result = CPAL_fieldOff();
            if((DIST_RESULT_IN_PROGRESS == result) || (DIST_RESULT_ERROR == result))
            {
                return result;
            }
            aNfcRdlibState = ANFC_RDLIB_ST_IDLE;
            return cpalIntermediateResult;
        default:
            assert_msg(FALSE, "Undefined state\r\n");
            return DIST_RESULT_ERROR;
    }
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) scanField(VAR(DistinguishingState_t, ANFCRL_VAR) DIST_STATE_c)
{
    VAR(uint16, ANFCRL_VAR) tech = 0U;
    VAR(phStatus_t, ANFCRL_VAR) nfc_status = PH_ERR_INTERNAL_ERROR;

    phacDiscLoop_Sw_DataParams_t * pDiscLoop =
            (phacDiscLoop_Sw_DataParams_t *) phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);

    switch (aNfcRdlibState)
    {
        case ANFC_RDLIB_ST_INIT:

#if((STD_ON) == ANFCRL_VAS_ENABLED)
            /*VAS only support in NFC Forum mode*/
            nfc_status = LoadProfileNfcMode();
            // CHECK_NFC_SUCCESS(nfc_status);
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED */
            nfc_status = phhalHw_FieldOff(phNfcLib_GetDataParams(PH_COMP_HAL));
            if (nfc_status == PH_STATUS_INPROCESS)
            {
                return DIST_RESULT_IN_PROGRESS;
            }
            else if(nfc_status != PH_ERR_SUCCESS)
            {
                if (nfc_status == 0x201U)
                {
                    // CONSOLE_MESSAGE("Error Switching off the field! Is the antenna connected correctly?");
                }
                return DIST_RESULT_ERROR;
            }
            else
            {
                /* Do nothing */
            }

            switch (DIST_STATE_c)
            {
                case DIST_ST_SCAN_ALL:
                    // tech = PHAC_DISCLOOP_POS_BIT_MASK_A |
					// PHAC_DISCLOOP_POS_BIT_MASK_B |
                    // PHAC_DISCLOOP_POS_BIT_MASK_F212 |
                    // PHAC_DISCLOOP_POS_BIT_MASK_V;
                    tech = PHAC_DISCLOOP_POS_BIT_MASK_A;
                    break;
				case DIST_ST_SCAN_BF:
					tech = PHAC_DISCLOOP_POS_BIT_MASK_B |
					PHAC_DISCLOOP_POS_BIT_MASK_F212;
					break;
				default:
					return DIST_RESULT_ERROR;
			}

            nfc_status = phacDiscLoop_SetConfig(pDiscLoop,
            PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE,
            PHAC_DISCLOOP_POLL_STATE_DETECTION);
            // CHECK_NFC_SUCCESS(nfc_status);

            nfc_status = phacDiscLoop_SetConfig(pDiscLoop,
            PHAC_DISCLOOP_CONFIG_BAIL_OUT, PH_OFF);
            // CHECK_NFC_SUCCESS(nfc_status);

            nfc_status = phacDiscLoop_SetConfig(pDiscLoop,
            PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG, tech);
            // CHECK_NFC_SUCCESS(nfc_status);

#if((STD_ON) == ANFCRL_VAS_ENABLED)
            /*Enable VAS*/
            nfc_status = InitVAS();
            // CHECK_NFC_SUCCESS(nfc_status);
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED */

            pDiscLoop->sTypeATargetInfo.sTypeA_I3P4.pAts = aResponseHolder;

            /* Clear previously found tags so the activation failed case works */
			pDiscLoop->sTypeBTargetInfo.bTotalTagsFound = 0;
			pDiscLoop->sTypeFTargetInfo.bTotalTagsFound = 0;
			pDiscLoop->sTypeVTargetInfo.bTotalTagsFound = 0;
			pDiscLoop->sTypeATargetInfo.bTotalTagsFound = 0;

            /* Send Rf_Field_Info Command */
            aNfcRdlibState = ANFC_RDLIB_ST_START_DISCOVERY;
            /*no break*/

        case ANFC_RDLIB_ST_START_DISCOVERY:
            /* Start Discovery */
            discLoopStatus_g = phacDiscLoop_Run(pDiscLoop, PHAC_DISCLOOP_ENTRY_POINT_POLL);

            if (discLoopStatus_g == PH_STATUS_INPROCESS)
            {
                return DIST_RESULT_IN_PROGRESS;
            }
            else
            {
                aNfcRdlibState = ANFC_RDLIB_ST_CHECK_NTF;
            }

            return DIST_RESULT_IN_PROGRESS;

        default:
            assert_msg(FALSE, "Undefined state\r\n");
            return DIST_RESULT_ERROR;
    }
}

VAR(uint16, ANFCRL_VAR) test_MultiTech = 0U;
VAR(uint16, ANFCRL_VAR) test_MultiDevice = 0U;
VAR(uint16, ANFCRL_VAR) test_NoTech = 0U;
VAR(uint16, ANFCRL_VAR) test_DeviceActivated = 0U;
VAR(uint16, ANFCRL_VAR) test_TargetActivated = 0U;
VAR(uint16, ANFCRL_VAR) test_Failure = 0U;
VAR(uint16, ANFCRL_VAR) test_Unknown = 0U;

FUNC(DIST_RESULT_t, ANFCRL_CODE) getFieldContent(void)
{
    VAR(phStatus_t, ANFCRL_VAR) wDiscStatus = discLoopStatus_g;
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop =
            phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);
    VAR(uint16, ANFCRL_VAR) wTagsDetected = 0U;
    cpalIntermediateResult = DIST_RESULT_ERROR;

    nfcDevice.Interface = NFC_INTF_UNDETERMINED;
    nfcDevice.Protocol = NFC_PROT_UNDETERMINED;
    nfcDevice.ModeTech = NFC_TECH_UNKNOWN;

	if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MULTI_TECH_DETECTED)
	{
		(void) phacDiscLoop_GetConfig(pDiscLoop,
		PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);
test_MultiTech++;
		if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_A))
		{
            // CONSOLE_MESSAGE(" \tType A detected... \n\r");
		}
		if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_B))
		{
            // CONSOLE_MESSAGE(" \tType B detected... \n\r");
		}
		if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_F212))
		{
            // CONSOLE_MESSAGE(" \tType F detected... \n\r");
		}
		if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_F424))
		{
            // CONSOLE_MESSAGE(" \tType F detected... \n\r");
		}
		if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_V))
		{
            // CONSOLE_MESSAGE(" \tType V detected... \n\r");
		}

		/* reinitialize state machine and leave */
		cpalIntermediateResult = DIST_RESULT_PROHIBIT;
		aNfcRdlibState = ANFC_RDLIB_ST_STOP_DISCOVERY;
		return DIST_RESULT_IN_PROGRESS;
	}

	if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED)
	{
		/* Get number of tags detected */
		(void) phacDiscLoop_GetConfig(pDiscLoop,
		PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND, &wTagsDetected);
        // CONSOLE_MESSAGE_1(" \n\r Multiple cards resolved: %d cards\n\r", wTagsDetected);
test_MultiDevice++;

		/* Get Detected Technology Type */
		(void) phacDiscLoop_GetConfig(pDiscLoop,
		PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);

		// printTagInfo(wTagsDetected);

		/* reinitialize state machine and leave */
		cpalIntermediateResult = DIST_RESULT_PROHIBIT;
		aNfcRdlibState = ANFC_RDLIB_ST_STOP_DISCOVERY;
		return DIST_RESULT_IN_PROGRESS;
	}
	else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_TECH_DETECTED)
	{
        /* reinitialize state machine and leave */
test_NoTech++;
		/* reinitialize state machine and leave */
		// CONSOLE_MESSAGE("\tNo endpoint detected\n\r");
		cpalIntermediateResult = DIST_RESULT_ALLOW;
		aNfcRdlibState = ANFC_RDLIB_ST_STOP_DISCOVERY;
		return DIST_RESULT_IN_PROGRESS;
	}
#ifdef FULL_NFC
else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_EXTERNAL_RFON)
{
  /*
   * If external RF is detected during POLL, return back so that the application
   * can restart the loop in LISTEN mode
   */
}
#endif
	else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND)
	{
        // CONSOLE_MESSAGE(" \n\r Device having T4T and NFC-DEP support detected... \n\r");

		/* Get Detected Technology Type */
		(void) phacDiscLoop_GetConfig(pDiscLoop,
		PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);

		printTagInfo(wTagsDetected);

		aNfcRdlibState = ANFC_RDLIB_ST_IDLE;
		return DIST_RESULT_RESUME;
	}
	else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_DEVICE_ACTIVATED)
	{
test_DeviceActivated++;
		/* Get Detected Technology Type */
		(void) phacDiscLoop_GetConfig(pDiscLoop,
		PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);
		printTagInfo(wTagsDetected);

		aNfcRdlibState = ANFC_RDLIB_ST_IDLE;
		return DIST_RESULT_RESUME;
	}
#ifdef FULL_NFC
else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED)
{
        // CONSOLE_MESSAGE(" \n\r Active target detected... \n\r");
test_TargetActivated++;
  /* Switch to LISTEN mode after POLL mode */
}
#endif
	else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED)
	{
        // CONSOLE_MESSAGE(" \n\r Passive target detected... \n\r");
		/* Get Detected Technology Type */
		(void) phacDiscLoop_GetConfig(pDiscLoop,
		PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);
		nfcDevice.Interface = NFC_INTF_NFC_DEP;
		printTagInfo(wTagsDetected);

		/* reinitialize state machine and leave */
		cpalIntermediateResult = DIST_RESULT_ALLOW;
		aNfcRdlibState = ANFC_RDLIB_ST_STOP_DISCOVERY;
		return DIST_RESULT_IN_PROGRESS;
	}
	else if ((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED)
	{
		cpalIntermediateResult = DIST_RESULT_ALLOW;
		aNfcRdlibState = ANFC_RDLIB_ST_STOP_DISCOVERY;
		return DIST_RESULT_IN_PROGRESS;
	}
	else
	{
		if (((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_FAILURE) ||
			((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED))
		{
test_Failure++;
			/* There is an NFC endpoint on the antenna but failed to activate it */
            // CONSOLE_MESSAGE(" \n\r Activation failed... \n\r");

			if((wDiscStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED)
			{
				/* Request was successful but collision resolution failed therefore LMD might work */
				if(pDiscLoop->sTypeBTargetInfo.bTotalTagsFound != 0)
				{
					nfcDevice.ModeTech = NFC_TECH_B;
				}
				else if(pDiscLoop->sTypeFTargetInfo.bTotalTagsFound != 0)
				{
					nfcDevice.ModeTech = NFC_TECH_F;
				}
				else if(pDiscLoop->sTypeVTargetInfo.bTotalTagsFound != 0)
				{
					nfcDevice.ModeTech = NFC_TECH_15693;
				}
				else
				{
					nfcDevice.ModeTech = NFC_TECH_A;
				}
			}
		}
		else
		{
test_Unknown++;
			printErrorInfo(wDiscStatus);
		}
	}

	cpalIntermediateResult = DIST_RESULT_ERROR;
	aNfcRdlibState = ANFC_RDLIB_ST_STOP_DISCOVERY;
	return DIST_RESULT_IN_PROGRESS;
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_fieldOff(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_INTERNAL_ERROR;

    /* Switch off RF field */
    void* pHal_CPAL = phNfcLib_GetDataParams(PH_COMP_HAL);
    status = phhalHw_FieldOff(pHal_CPAL);
    if(PH_STATUS_INPROCESS == status)
    {
        return DIST_RESULT_IN_PROGRESS;
    }
    else if(PH_ERR_SUCCESS != status)
    {
        return DIST_RESULT_ERROR;
    }
    else
    {
         return DIST_RESULT_RESUME;
    }
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_scanAllTypes(void)
{

    return scanNonBlocking(DIST_ST_SCAN_ALL);
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_scanTypeBF(void)
{
    VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_ERROR;

    result = scanNonBlocking(DIST_ST_SCAN_BF);

    if (result == DIST_RESULT_ALLOW)
    {
        /* ALLOW means no device found therefore we cannot decide
         * if the device from ScanAll is a phone or a card */
        return DIST_RESULT_RESUME;

    }
    else if(result == DIST_RESULT_RESUME)
    {
    	/* We found another endpoint which means single device
    	 * answering to two techs -> phone */
    	return DIST_RESULT_ALLOW;
    }
    else
    {
        return result;
    }
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) CPAL_hasPassportAID(void)
{
#if PASSPORT_ENABLED
    VAR(DIST_RESULT_t, ANFCRL_VAR) result = DIST_RESULT_ERROR;

    /* According to Table 60 in [ISO 7816-4]
     * Especially section 12.2.5.2 is of interest
     * CLA=0, INS=A4, P1=4, P2=0: That is required to activate by aid
     * Followed by Lc=<leo of content> <aid> Le=<expected answer length> */
    VAR(uint8, ANFCRL_VAR) command[] = { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xA0, 0x00, 0x00, 0xDE,
            0xAD, 0xBE, 0xEF, 0x09 };
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) Answer;
    VAR(uint16, ANFCRL_VAR) AnswerSize;

    result = exchangeApdu(command, sizeof(command), &Answer, &AnswerSize);

    /* APDU response received so check it */
    if ((result == DIST_RESULT_RESUME) && (AnswerSize > 2))
    {
        // CONSOLE_MESSAGE("\n\r AID found\r\n");
        /* Passports are considered as cards */
        return DIST_RESULT_PROHIBIT;

    }
    else
    {
        return result;
    }
#else
  return DIST_RESULT_RESUME;

#endif
}


FUNC(void, ANFCRL_CODE) printTagInfo(VAR(uint16, ANFCRL_VAR) wTagsDetected)
{
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams =
            phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);
    VAR(uint8, ANFCRL_VAR) bTagType;

    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_A))
    {
		/* Mapping of aNFC Reader Library -> RFID Protection enumeration */
    	nfcDevice.ModeTech = NFC_TECH_A;
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
		nfcDevice.UidLen = pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].bUidSize;
		(void)memcpy(nfcDevice.Uid, pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aUid,
				nfcDevice.UidLen);

		if ((pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aSak & (uint8) ~0xFBU) == 0U)
		{
			/* Bit b3 is set to zero, [Digital] 4.8.2 */
			/* Mask out all other bits except for b7 and b6 */
			bTagType = (pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aSak & 0x60U);
			bTagType = bTagType >> 5U;

			switch (bTagType)
			{
				case PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK:
					nfcDevice.Protocol = NFC_PROT_T2T;
                    // CONSOLE_MESSAGE("\n\r\tType 2 Tag\n");
					break;
				case PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK:
					nfcDevice.Protocol = NFC_PROT_ISODEP;
                    // CONSOLE_MESSAGE("\n\r\tType 4A Tag\n");
					break;
				case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK:
					nfcDevice.Protocol = NFC_PROT_NFCDEP;
					nfcDevice.Interface = NFC_INTF_NFC_DEP;
                    // CONSOLE_MESSAGE("\n\r\tNFC_DEP\n");
					break;
				case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK:
					nfcDevice.Protocol = NFC_PROT_NFCDEP;
					nfcDevice.Interface = NFC_INTF_NFC_DEP;
                    // CONSOLE_MESSAGE("\n\r\tType NFC_DEP and  4A Tag\n");
					break;
				default:
                    /* Handle error cases not explicitly */
					break;
			}
		}

		// CONSOLE_MESSAGE("\n\r\tUID:");
		print_Buff(pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aUid,
				pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].bUidSize);
    }
    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_B))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice.ModeTech = NFC_TECH_B;

        // CONSOLE_MESSAGE("\n\r\tType B");

        // CONSOLE_MESSAGE("\n\r\tUID :");
        /* PUPI Length is always 4 bytes */
        print_Buff(pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].aPupi, 0x04U);

        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice.UidLen = 0x04U;
        (void)memcpy(nfcDevice.Uid, pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].aPupi, 0x04U);

        // CONSOLE_MESSAGE("\n\r");
    }
    if ( PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_F212) ||
            PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_F424))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice.ModeTech = NFC_TECH_F;
        // CONSOLE_MESSAGE("\n\r\tType F");

        // CONSOLE_MESSAGE("\n\r\tUID :");
        print_Buff(pDataParams->sTypeFTargetInfo.aTypeFTag[0].aIDmPMm,
                PHAC_DISCLOOP_FELICA_IDM_LENGTH);

        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice.UidLen = PHAC_DISCLOOP_FELICA_IDM_LENGTH;
        (void)memcpy(nfcDevice.Uid, pDataParams->sTypeFTargetInfo.aTypeFTag[0].aIDmPMm,
                PHAC_DISCLOOP_FELICA_IDM_LENGTH);

        // CONSOLE_MESSAGE("\n\r");
    }
    if (PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_V))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice.ModeTech = NFC_TECH_15693;
        // CONSOLE_MESSAGE("\n\r\tType V / ISO 15693 / T5T");

        // CONSOLE_MESSAGE("\n\r\tUID :");
        print_Buff(pDataParams->sTypeVTargetInfo.aTypeV[0].aUid, 0x08U);

        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice.UidLen = 0x08U;
        (void)memcpy(nfcDevice.Uid, pDataParams->sTypeVTargetInfo.aTypeV[0].aUid, 0x08U);

        // CONSOLE_MESSAGE("\n\r");
    }
}

FUNC(void, ANFCRL_CODE) printErrorInfo(VAR(uint16, ANFCRL_VAR) wStatus)
{
    DEBUG_MESSAGE("\n ErrorInfo Comp:");

    switch (wStatus & 0xFF00U)
    {
        case PH_COMP_BAL:
            DEBUG_MESSAGE("\t PH_COMP_BAL");
            break;
        case PH_COMP_HAL:
            DEBUG_MESSAGE("\t PH_COMP_HAL");
            break;
        case PH_COMP_PAL_ISO14443P3A:
            DEBUG_MESSAGE("\t PH_COMP_PAL_ISO14443P3A");
            break;
        case PH_COMP_PAL_ISO14443P3B:
            DEBUG_MESSAGE("\t PH_COMP_PAL_ISO14443P3B");
            break;
        case PH_COMP_PAL_ISO14443P4A:
            DEBUG_MESSAGE("\t PH_COMP_PAL_ISO14443P4A");
            break;
        case PH_COMP_PAL_ISO14443P4:
            DEBUG_MESSAGE("\t PH_COMP_PAL_ISO14443P4");
            break;
        case PH_COMP_PAL_FELICA:
            DEBUG_MESSAGE("\t PH_COMP_PAL_FELICA");
            break;
        case PH_COMP_PAL_EPCUID:
            DEBUG_MESSAGE("\t PH_COMP_PAL_EPCUID");
            break;
        case PH_COMP_PAL_SLI15693:
            DEBUG_MESSAGE("\t PH_COMP_PAL_SLI15693");
            break;
        case PH_COMP_PAL_I14443P4MC:
            DEBUG_MESSAGE("\t PH_COMP_PAL_I14443P4MC");
            break;
        case PH_COMP_AC_DISCLOOP:
            DEBUG_MESSAGE("\t PH_COMP_AC_DISCLOOP");
            break;
        case PH_COMP_OSAL:
            DEBUG_MESSAGE("\t PH_COMP_OSAL");
            break;
        default:
            DEBUG_MESSAGE("\t 0x%x", (((uint32)wStatus) & ((uint32)PH_COMPID_MASK)));
            break;
    }

    DEBUG_MESSAGE("\t type:");

    switch (wStatus & PH_ERR_MASK)
    {
        case PH_ERR_SUCCESS_INCOMPLETE_BYTE:
            DEBUG_MESSAGE("\t PH_ERR_SUCCESS_INCOMPLETE_BYTE");
            break;
        case PH_ERR_IO_TIMEOUT:
            DEBUG_MESSAGE("\t PH_ERR_IO_TIMEOUT");
            break;
        case PH_ERR_INTEGRITY_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_INTEGRITY_ERROR");
            break;
        case PH_ERR_COLLISION_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_COLLISION_ERROR");
            break;
        case PH_ERR_BUFFER_OVERFLOW:
            DEBUG_MESSAGE("\t PH_ERR_BUFFER_OVERFLOW");
            break;
        case PH_ERR_FRAMING_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_FRAMING_ERROR");
            break;
        case PH_ERR_PROTOCOL_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_PROTOCOL_ERROR");
            break;
        case PH_ERR_RF_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_RF_ERROR");
            break;
        case PH_ERR_EXT_RF_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_EXT_RF_ERROR");
            break;
        case PH_ERR_NOISE_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_NOISE_ERROR");
            break;
        case PH_ERR_ABORTED:
            DEBUG_MESSAGE("\t PH_ERR_ABORTED");
            break;
        case PH_ERR_INTERNAL_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_INTERNAL_ERROR");
            break;
        case PH_ERR_INVALID_DATA_PARAMS:
            DEBUG_MESSAGE("\t PH_ERR_INVALID_DATA_PARAMS");
            break;
        case PH_ERR_INVALID_PARAMETER:
            DEBUG_MESSAGE("\t PH_ERR_INVALID_PARAMETER");
            break;
        case PH_ERR_PARAMETER_OVERFLOW:
            DEBUG_MESSAGE("\t PH_ERR_PARAMETER_OVERFLOW");
            break;
        case PH_ERR_UNSUPPORTED_PARAMETER:
            DEBUG_MESSAGE("\t PH_ERR_UNSUPPORTED_PARAMETER");
            break;
        case PH_ERR_OSAL_ERROR:
            DEBUG_MESSAGE("\t PH_ERR_OSAL_ERROR");
            break;
        case PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED:
            DEBUG_MESSAGE("\t PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED");
            break;
        case PHAC_DISCLOOP_COLLISION_PENDING:
            DEBUG_MESSAGE("\t PHAC_DISCLOOP_COLLISION_PENDING");
            break;
        default:
            DEBUG_MESSAGE("\t 0x%x", (((uint32)wStatus) & ((uint32)PH_ERR_MASK)));
            break;
    }
}

/**
 * This function will print buffer content
 * \param   *pBuff   Buffer Reference
 * \param   num      data size to be print
 */
FUNC(void, ANFCRL_CODE) print_Buff(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff,
        VAR(uint8, ANFCRL_VAR) num)
{
    VAR(uint32, ANFCRL_VAR) i;

    for (i = 0U; i < num; i++)
    {
        // CONSOLE_MESSAGE_1(" %02X", pBuff[i]);
    }
    UNUSED (pBuff);
}

FUNC(DIST_RESULT_t, ANFCRL_CODE) exchangeApdu(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCommand,
    VAR(uint16, ANFCRL_VAR) CommandSize,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAnswer,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pAnswerSize)
{
  UNUSED (pCommand);
  UNUSED (CommandSize);
  UNUSED (pAnswer);
  UNUSED (pAnswerSize);
#if PASSPORT_ENABLED
    VAR(phStatus_t, ANFCRL_VAR) result = PH_ERR_SUCCESS;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuff = NULL;
    VAR(uint16, ANFCRL_VAR) wRxBuffLen = 0U;
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop =
            phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);

  /* Select AID */
  result = phpalI14443p4_Exchange(pDiscLoop->pPal14443p4DataParams,PH_EXCHANGE_DEFAULT,
      pCommand, CommandSize, &pRxBuff, &wRxBuffLen );

    if (result == PH_STATUS_INPROCESS)
    {
        return DIST_RESULT_IN_PROGRESS;
    }
    else if (result == PH_ERR_SUCCESS)
    {
        /* return buffers are valid now */
        *pAnswer = pRxBuff;
        *pAnswerSize = wRxBuffLen;
        return DIST_RESULT_RESUME;
    }
    else
    {
        // CONSOLE_MESSAGE("Undefined state\r\n");
        printErrorInfo(result);
        return DIST_RESULT_ERROR;
    }
#else
  return DIST_RESULT_ERROR;
#endif
}

#if((STD_ON) == ANFCRL_VAS_ENABLED)
static FUNC(phStatus_t, ANFCRL_CODE) InitVAS(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) wPasPollConfig = 0U;

    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop =
            phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);

    pDiscLoop->sVASTargetInfo.pCmdBytes = aVASCmd;
    pDiscLoop->sVASTargetInfo.bLenCmdBytes = 0x08U;
    status = phacDiscLoop_GetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG,
            &wPasPollConfig);
    // CHECK_NFC_SUCCESS(status);
    wPasPollConfig |= PHAC_DISCLOOP_POS_BIT_MASK_VAS;
    /* Set Passive poll bitmap config. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG,
            wPasPollConfig);
    // CHECK_NFC_SUCCESS(status);

    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE,
    		PHPAL_I14443P3A_VASUP_VERSION_02);
    // CHECK_NFC_SUCCESS(status);

    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE,
            PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING);
    // CHECK_NFC_SUCCESS(status);

    return status;
}

static FUNC(phStatus_t, ANFCRL_CODE) LoadProfileNfcMode(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) wPasPollConfig = 0U;
    VAR(uint16, ANFCRL_VAR) wActPollConfig = 0U;
    VAR(uint16, ANFCRL_VAR) wPasLisConfig = 0U;
    VAR(uint16, ANFCRL_VAR) wActLisConfig = 0U;

    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop =
    phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
    wPasPollConfig |= PHAC_DISCLOOP_POS_BIT_MASK_A;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    wPasPollConfig |= PHAC_DISCLOOP_POS_BIT_MASK_B;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
    wPasPollConfig |= (PHAC_DISCLOOP_POS_BIT_MASK_F212 | PHAC_DISCLOOP_POS_BIT_MASK_F424);
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    wPasPollConfig |= PHAC_DISCLOOP_POS_BIT_MASK_V;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE
    wActPollConfig |= PHAC_DISCLOOP_ACT_POS_BIT_MASK_106;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_P2P_ACTIVE
    wActPollConfig |= PHAC_DISCLOOP_ACT_POS_BIT_MASK_212;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_P2P_ACTIVE
    wActPollConfig |= PHAC_DISCLOOP_ACT_POS_BIT_MASK_424;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE
    wPasLisConfig |= PHAC_DISCLOOP_POS_BIT_MASK_A;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE
    wPasLisConfig |= PHAC_DISCLOOP_POS_BIT_MASK_F212;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE
    wPasLisConfig |= PHAC_DISCLOOP_POS_BIT_MASK_F424;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE
    wActLisConfig |= PHAC_DISCLOOP_POS_BIT_MASK_A;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE
    wActLisConfig |= PHAC_DISCLOOP_POS_BIT_MASK_F212;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE
    wActLisConfig |= PHAC_DISCLOOP_POS_BIT_MASK_F424;
#endif

    /* passive Bailout bitmap config. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_BAIL_OUT, 0x00U);
    // CHECK_NFC_SUCCESS(status);

    /* Set Passive poll bitmap config. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG,
            wPasPollConfig);
    // CHECK_NFC_SUCCESS(status);

    /* Set Active poll bitmap config. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG,
            wActPollConfig);
    // CHECK_NFC_SUCCESS(status);

    /* Set Passive listen bitmap config. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG,
            wPasLisConfig);
    // CHECK_NFC_SUCCESS(status);

    /* Set Active listen bitmap config. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG,
            wActLisConfig);
    // CHECK_NFC_SUCCESS(status);

    /* reset collision Pending */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_COLLISION_PENDING, PH_OFF);
    // CHECK_NFC_SUCCESS(status);

    /* whether anti-collision is supported or not. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_ANTI_COLL, PH_ON);
    // CHECK_NFC_SUCCESS(status);

    /* Poll Mode default state*/
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE,
    PHAC_DISCLOOP_POLL_STATE_DETECTION);
    // CHECK_NFC_SUCCESS(status);

#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
    /* Device limit for Type A */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT, 3U);
    // CHECK_NFC_SUCCESS(status);

    /* Passive polling Tx Guard times in micro seconds. */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_GTA_VALUE_US, 5100U);
    // CHECK_NFC_SUCCESS(status);
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    /* Device limit for Type B */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT, 3U);
    // CHECK_NFC_SUCCESS(status);

    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_GTB_VALUE_US, 5100U);
    // CHECK_NFC_SUCCESS(status);
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
    /* Device limit for Type F */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT, 3U);
    // CHECK_NFC_SUCCESS(status);

    /* Guard time for Type F. This guard time is applied when Type F poll before Type B */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US, 20400U);
    // CHECK_NFC_SUCCESS(status);

    /* Guard time for Type F. This guard time is applied when Type B poll before Type F */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US, 15300U);
    // CHECK_NFC_SUCCESS(status);
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    /* Device limit for Type V (ISO 15693) */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT, 3U);
    // CHECK_NFC_SUCCESS(status);

    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_GTV_VALUE_US, 5200U);
    // CHECK_NFC_SUCCESS(status);
#endif

    /* NFC Activity version supported */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION,
    PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_1);
    // CHECK_NFC_SUCCESS(status);

    /* Discovery loop Operation mode */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_OPE_MODE, RD_LIB_MODE_NFC);
    // CHECK_NFC_SUCCESS(status);

    return status;
}
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED */
