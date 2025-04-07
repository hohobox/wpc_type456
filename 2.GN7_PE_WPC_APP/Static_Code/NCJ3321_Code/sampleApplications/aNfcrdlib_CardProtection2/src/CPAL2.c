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
 * This file contains the implementation of the distinguishing2 algorithm.
 * dinstinguishing.h contains some data structures required in this file.
 */

/* NIDEC_PORTING */
#include <ph_Status2.h>
#include <phApp_Init2.h>
#include "App_NFC.h"
#include "EcuInfo.h"
/* NIDEC_PORTING */

#include "CPAL2.h"
#include "distinguishing_types2.h"

#define PASSPORT_ENABLED2 0
/*############################################################
 *
 *                        INCLUDES
 *
 ###########################################################*/
#include <phNfcLib2.h>
#include <phpalI14443p42.h>
#include <phacDiscLoop2.h>
#include "phhalHw_Ncx3321_Instr2.h"
#include "phDriver_Timer2.h"
#include "distinguishing2.h"

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


VAR(NFC_DEVICE_t2, ANFCRL_VAR) nfcDevice2;

#if((STD_ON) == ANFCRL_VAS_ENABLED2)
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0x6AU, 0x02U, 0xC3U, 0x02U, 0x01U, 0x01U, 0x0FU, 0xFFU };
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x0F, 0x03 }; // HKMC Mock-Test
static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { cTCI_Code1, cTCI_Code2, cTCI_Code3, cTCI_Code4, cTCI_Code5, cTCI_Code6, cTCI_Code7, cTCI_Code8 };	// WPC_415_04
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED2 */

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
FUNC(void, ANFCRL_CODE) print_Buff2(
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff2, VAR(uint8, ANFCRL_VAR) num2);
#if((STD_ON) == ANFCRL_VAS_ENABLED2)
static FUNC(phStatus_t2, ANFCRL_CODE) InitVAS2(void);
static FUNC(phStatus_t2, ANFCRL_CODE) LoadProfileNfcMode2(void);
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED2 */

/* Local headers */
/*******************************************************************************
 **   Enum Defines
 *******************************************************************************/

/*******************************************************************************
 **   Global Defines
 *******************************************************************************/
static VAR(aNfcRdLibState_t2, ANFCRL_VAR) aNfcRdlibState2 = ANFC_RDLIB_ST_INIT2;

static VAR(DIST_RESULT_t2, ANFCRL_VAR) cpalIntermediateResult2 = DIST_RESULT_ERROR2;

static VAR(uint8, ANFCRL_VAR) aResponseHolder2[64] = { 0x00U };

static VAR(phStatus_t2, ANFCRL_VAR) discLoopStatus_g2 = PH_ERR_INTERNAL_ERROR2;

static VAR(uint8, ANFCRL_VAR) extFieldDetected2 = 0U;
VAR(sint8, ANFCRL_VAR) printBuffer2[1024];

/* ----------------------------------------------- */
/***                CPAL2 Functions               ***/
/* ----------------------------------------------- */
FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_reset2(void)
{
    extFieldDetected2 = 0U;
    // CONSOLE_MESSAGE(GRN("\n\rNXP - Card Protection with Load Modulation Detection\r\n"));
    // CONSOLE_MESSAGE_ARGS("Amplitude Ratio Threshold: %d\r\n", AMPLITUDE_CHANGE_THRESHOLD);
    // CONSOLE_MESSAGE_ARGS("Phase Shift Threshold: %d\r\n", PHASE_DIFFERENT_THRESHOLD);
    // CONSOLE_MESSAGE_ARGS("Low VDDPA: 0x%02X, High VDDPA: 0x%02X\r\n", LMD_VDDPA_LOW, LMD_VDDPA_HIGH);
#if(FAST_CTS_EXECUTION2 == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Fast CTS enabled\r\n");
#else
    // CONSOLE_MESSAGE_ARGS("Fast CTS disabled\r\n");
#endif

#if(CHECK_MULTI_TECH_SUPPORT2 == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Multiple technology check enabled\r\n");
#else
    // CONSOLE_MESSAGE_ARGS("Multiple technology check disabled\r\n");
#endif

#if(CLEAN_SURFACE_CHECK2 == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Clean surface check enabled\r\n");
#if(CLEAN_SURFACE_CALIBRATE2 == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Clean surface calibration enabled\r\n");
#else
    // CONSOLE_MESSAGE_ARGS("Clean surface calibration disabled\r\n");
#endif
    // CONSOLE_MESSAGE_ARGS("Clean surface HF Attenuation Threshold: %d\r\n", CLEAN_SURFACE_HFATT_THRESHOLD);
#else
    // CONSOLE_MESSAGE_ARGS("Clean surface check disabled\r\n");
#endif

#if(CHECK_SATURATED_IQ2 == (STD_ON))
    // CONSOLE_MESSAGE_ARGS("Check for saturated IQ values enabled\r\n");
    // CONSOLE_MESSAGE_ARGS("Threshold for number of saturated values in log: %d\r\n", NUM_SATURATED_IQ_THRESHOLD);
#else
    // CONSOLE_MESSAGE_ARGS("Check for saturated IQ values disabled\r\n");
#endif

    // CONSOLE_MESSAGE_ARGS("\r\n\r\n");

    return DIST_RESULT_RESUME2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_init2(void)
{
    return DIST_RESULT_RESUME2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) scanNonBlocking2(
        VAR(DistinguishingState_t2, ANFCRL_VAR) DIST_STATE_c2)
{
    VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_ERROR2;

    if (aNfcRdlibState2 == ANFC_RDLIB_ST_IDLE2)
    {
        aNfcRdlibState2 = ANFC_RDLIB_ST_INIT2;

        switch (DIST_STATE_c2)
        {
            case DIST_ST_SCAN_ALL2:
                // CONSOLE_MESSAGE("Scan All Types\r\n");
                break;
            case DIST_ST_SCAN_BF2:
                // CONSOLE_MESSAGE("Scan Type BFV\r\n");
                break;
            default:
                // CONSOLE_MESSAGE("Unknown Scan State\r\n");
        }
    }

    switch (aNfcRdlibState2)
    {
        case ANFC_RDLIB_ST_INIT2:
            case ANFC_RDLIB_ST_START_DISCOVERY2:
            return scanField2(DIST_STATE_c2);
        case ANFC_RDLIB_ST_CHECK_NTF2:
            /* Scan until timeout */
            return getFieldContent2();
        case ANFC_RDLIB_ST_STOP_DISCOVERY2:
            result2 = CPAL_fieldOff2();
            if((DIST_RESULT_IN_PROGRESS2 == result2) || (DIST_RESULT_ERROR2 == result2))
            {
                return result2;
            }
            aNfcRdlibState2 = ANFC_RDLIB_ST_IDLE2;
            return cpalIntermediateResult2;
        default:
            assert_msg2(FALSE, "Undefined state\r\n");
            return DIST_RESULT_ERROR2;
    }
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) scanField2(VAR(DistinguishingState_t2, ANFCRL_VAR) DIST_STATE_c2)
{
    VAR(uint16, ANFCRL_VAR) tech2 = 0U;
    VAR(phStatus_t2, ANFCRL_VAR) nfc_status2 = PH_ERR_INTERNAL_ERROR2;

    phacDiscLoop_Sw_DataParams_t2 * pDiscLoop2 =
            (phacDiscLoop_Sw_DataParams_t2 *) phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);

    switch (aNfcRdlibState2)
    {
        case ANFC_RDLIB_ST_INIT2:

#if((STD_ON) == ANFCRL_VAS_ENABLED2)
            /*VAS only support in NFC Forum mode*/
            nfc_status2 = LoadProfileNfcMode2();
            // CHECK_NFC_SUCCESS(nfc_status2);
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED2 */
            	nfc_status2 = phhalHw_FieldOff2(phNfcLib_GetDataParams2(PH_COMP_HAL2));
            if (nfc_status2 == PH_STATUS_INPROCESS2)
            {
                return DIST_RESULT_IN_PROGRESS2;
            }
            else if(nfc_status2 != PH_ERR_SUCCESS2)
            {
                if (nfc_status2 == 0x201U)
                {
                    // CONSOLE_MESSAGE("Error Switching off the field! Is the antenna connected correctly?");
                }
                return DIST_RESULT_ERROR2;
            }
            else
            {
                /* Do nothing */
            }

            switch (DIST_STATE_c2)
            {
                case DIST_ST_SCAN_ALL2:
                    //	tech2 = PHAC_DISCLOOP_POS_BIT_MASK_A2 |
                    //	PHAC_DISCLOOP_POS_BIT_MASK_B2 |
                    //	PHAC_DISCLOOP_POS_BIT_MASK_F2122 |
                    //	PHAC_DISCLOOP_POS_BIT_MASK_V2;
                    tech2 = PHAC_DISCLOOP_POS_BIT_MASK_A2;
                    break;
                case DIST_ST_SCAN_BF2:
                    tech2 = PHAC_DISCLOOP_POS_BIT_MASK_B2 |
                    PHAC_DISCLOOP_POS_BIT_MASK_F2122;
                    break;
                default:
                    return DIST_RESULT_ERROR2;
            }

            nfc_status2 = phacDiscLoop_SetConfig2(pDiscLoop2,
            PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2,
            PHAC_DISCLOOP_POLL_STATE_DETECTION2);
            // CHECK_NFC_SUCCESS(nfc_status2);

            nfc_status2 = phacDiscLoop_SetConfig2(pDiscLoop2,
            PHAC_DISCLOOP_CONFIG_BAIL_OUT2, PH_OFF2);
            // CHECK_NFC_SUCCESS(nfc_status2);

            nfc_status2 = phacDiscLoop_SetConfig2(pDiscLoop2,
            PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2, tech2);
            // CHECK_NFC_SUCCESS(nfc_status2);

#if((STD_ON) == ANFCRL_VAS_ENABLED2)
            /*Enable VAS*/
            nfc_status2 = InitVAS2();
            // CHECK_NFC_SUCCESS(nfc_status2);
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED2 */

            pDiscLoop2->sTypeATargetInfo2.sTypeA_I3P42.pAts2 = aResponseHolder2;

            /* Clear previously found tags so the activation failed case works */
			pDiscLoop2->sTypeBTargetInfo2.bTotalTagsFound2 = 0;
			pDiscLoop2->sTypeFTargetInfo2.bTotalTagsFound2 = 0;
			pDiscLoop2->sTypeVTargetInfo2.bTotalTagsFound2 = 0;
			pDiscLoop2->sTypeATargetInfo2.bTotalTagsFound2 = 0;

            /* Send Rf_Field_Info Command */
            aNfcRdlibState2 = ANFC_RDLIB_ST_START_DISCOVERY2;
            /*no break*/

        case ANFC_RDLIB_ST_START_DISCOVERY2:
            /* Start Discovery */
            discLoopStatus_g2 = phacDiscLoop_Run2(pDiscLoop2, PHAC_DISCLOOP_ENTRY_POINT_POLL2);

            if (discLoopStatus_g2 == PH_STATUS_INPROCESS2)
            {
                return DIST_RESULT_IN_PROGRESS2;
            }
            else
            {
                aNfcRdlibState2 = ANFC_RDLIB_ST_CHECK_NTF2;
            }

            return DIST_RESULT_IN_PROGRESS2;

        default:
            assert_msg2(FALSE, "Undefined state\r\n");
            return DIST_RESULT_ERROR2;
    }
}

VAR(uint16, ANFCRL_VAR) test_MultiTech2 = 0U;
VAR(uint16, ANFCRL_VAR) test_MultiDevice2 = 0U;
VAR(uint16, ANFCRL_VAR) test_NoTech2 = 0U;
VAR(uint16, ANFCRL_VAR) test_DeviceActivated2 = 0U;
VAR(uint16, ANFCRL_VAR) test_TargetActivated2 = 0U;
VAR(uint16, ANFCRL_VAR) test_Failure2 = 0U;
VAR(uint16, ANFCRL_VAR) test_Unknown2 = 0U;
FUNC(DIST_RESULT_t2, ANFCRL_CODE) getFieldContent2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) wDiscStatus2 = discLoopStatus_g2;
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop2 =
            phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);
    VAR(uint16, ANFCRL_VAR) wTagsDetected2 = 0U;
    cpalIntermediateResult2 = DIST_RESULT_ERROR2;

    nfcDevice2.Interface2 = NFC_INTF_UNDETERMINED2;
    nfcDevice2.Protocol2 = NFC_PROT_UNDETERMINED2;
    nfcDevice2.ModeTech2 = NFC_TECH_UNKNOWN2;

    if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MULTI_TECH_DETECTED2)
    {
        (void) phacDiscLoop_GetConfig2(pDiscLoop2,
        PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);
test_MultiTech2++;
        if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_A2))
        {
            // CONSOLE_MESSAGE(" \tType A detected... \n\r");
        }
        if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_B2))
        {
            // CONSOLE_MESSAGE(" \tType B detected... \n\r");
        }
        if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_F2122))
        {
            // CONSOLE_MESSAGE(" \tType F detected... \n\r");
        }
        if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_F4242))
        {
            // CONSOLE_MESSAGE(" \tType F detected... \n\r");
        }
        if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_V2))
        {
            // CONSOLE_MESSAGE(" \tType V detected... \n\r");
        }

        /* reinitialize state machine and leave */
        cpalIntermediateResult2 = DIST_RESULT_PROHIBIT2;
        aNfcRdlibState2 = ANFC_RDLIB_ST_STOP_DISCOVERY2;
        return DIST_RESULT_IN_PROGRESS2;
    }

    if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2)
    {
        /* Get number of tags detected */
        (void) phacDiscLoop_GetConfig2(pDiscLoop2,
        PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND2, &wTagsDetected2);
        // CONSOLE_MESSAGE_1(" \n\r Multiple cards resolved: %d cards\n\r", wTagsDetected2);
test_MultiDevice2++;
        /* Get Detected Technology Type */
        (void) phacDiscLoop_GetConfig2(pDiscLoop2,
        PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);

        // printTagInfo2(wTagsDetected2);

        /* reinitialize state machine and leave */
        cpalIntermediateResult2 = DIST_RESULT_PROHIBIT2;
        aNfcRdlibState2 = ANFC_RDLIB_ST_STOP_DISCOVERY2;
        return DIST_RESULT_IN_PROGRESS2;
    }
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_TECH_DETECTED2)
    {
        /* reinitialize state machine and leave */
test_NoTech2++;
        /* reinitialize state machine and leave */
        // CONSOLE_MESSAGE("\tNo endpoint detected\n\r");
        cpalIntermediateResult2 = DIST_RESULT_ALLOW2;
        aNfcRdlibState2 = ANFC_RDLIB_ST_STOP_DISCOVERY2;
        return DIST_RESULT_IN_PROGRESS2;
    }
#ifdef FULL_NFC
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_EXTERNAL_RFON2)
    {
        /*
            * If external RF is detected during POLL, return back so that the application
            * can restart the loop in LISTEN mode
            */
    }
#endif
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2)
    {
        // CONSOLE_MESSAGE(" \n\r Device having T4T and NFC-DEP support detected... \n\r");

        /* Get Detected Technology Type */
        (void) phacDiscLoop_GetConfig2(pDiscLoop2,
        PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);

        printTagInfo2(wTagsDetected2);

        aNfcRdlibState2 = ANFC_RDLIB_ST_IDLE2;
        return DIST_RESULT_RESUME2;
    }
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_DEVICE_ACTIVATED2)
    {
test_DeviceActivated2++;
        /* Get Detected Technology Type */
        (void) phacDiscLoop_GetConfig2(pDiscLoop2,
        PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);
        printTagInfo2(wTagsDetected2);

        aNfcRdlibState2 = ANFC_RDLIB_ST_IDLE2;
        return DIST_RESULT_RESUME2;
    }
#ifdef FULL_NFC
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED2)
    {
        // CONSOLE_MESSAGE(" \n\r Active target detected... \n\r");
test_TargetActivated2++;
        /* Switch to LISTEN mode after POLL mode */
    }
#endif
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED2)
    {
        // CONSOLE_MESSAGE(" \n\r Passive target detected... \n\r");
        /* Get Detected Technology Type */
        (void) phacDiscLoop_GetConfig2(pDiscLoop2,
        PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);
        nfcDevice2.Interface2 = NFC_INTF_NFC_DEP2;
        printTagInfo2(wTagsDetected2);

        /* reinitialize state machine and leave */
        cpalIntermediateResult2 = DIST_RESULT_ALLOW2;
        aNfcRdlibState2 = ANFC_RDLIB_ST_STOP_DISCOVERY2;
        return DIST_RESULT_IN_PROGRESS2;
    }
    else if ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED2)
    {
        cpalIntermediateResult2 = DIST_RESULT_ALLOW2;
        aNfcRdlibState2 = ANFC_RDLIB_ST_STOP_DISCOVERY2;
        return DIST_RESULT_IN_PROGRESS2;
    }
    else
    {
        if (((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_FAILURE2) ||
                ((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED2))
        {
test_Failure2++;
			/* There is an NFC endpoint on the antenna but failed to activate it */
            // CONSOLE_MESSAGE(" \n\r Activation failed... \n\r");

			if((wDiscStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED2)
			{
				/* Request was successful but collision resolution failed therefore LMD might work */
				if(pDiscLoop2->sTypeBTargetInfo2.bTotalTagsFound2 != 0)
				{
					nfcDevice2.ModeTech2 = NFC_TECH_B2;
				}
				else if(pDiscLoop2->sTypeFTargetInfo2.bTotalTagsFound2 != 0)
				{
					nfcDevice2.ModeTech2 = NFC_TECH_F2;
				}
				else if(pDiscLoop2->sTypeVTargetInfo2.bTotalTagsFound2 != 0)
				{
					nfcDevice2.ModeTech2 = NFC_TECH_156932;
				}
				else
				{
					nfcDevice2.ModeTech2 = NFC_TECH_A2;
				}
			}
		}
		else
		{
test_Unknown2++;
			printErrorInfo2(wDiscStatus2);
		}
	}

	cpalIntermediateResult2 = DIST_RESULT_ERROR2;
	aNfcRdlibState2 = ANFC_RDLIB_ST_STOP_DISCOVERY2;
	return DIST_RESULT_IN_PROGRESS2;
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_fieldOff2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_INTERNAL_ERROR2;

    /* Switch off RF field */
    void* pHal_CPAL2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);
    status2 = phhalHw_FieldOff2(pHal_CPAL2);
    if(PH_STATUS_INPROCESS2 == status2)
    {
        return DIST_RESULT_IN_PROGRESS2;
    }
    else if(PH_ERR_SUCCESS2 != status2)
    {
        return DIST_RESULT_ERROR2;
    }
    else
    {
         return DIST_RESULT_RESUME2;
    }
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_scanAllTypes2(void)
{

    return scanNonBlocking2(DIST_ST_SCAN_ALL2);
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_scanTypeBF2(void)
{
    VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_ERROR2;

    result2 = scanNonBlocking2(DIST_ST_SCAN_BF2);

    if (result2 == DIST_RESULT_ALLOW2)
    {
        /* ALLOW means no device found therefore we cannot decide
         * if the device from ScanAll is a phone or a card */
        return DIST_RESULT_RESUME2;

    }
    else if(result2 == DIST_RESULT_RESUME2)
    {
    	/* We found another endpoint which means single device
    	 * answering to two techs -> phone */
    	return DIST_RESULT_ALLOW2;
    }
    else
    {
        return result2;
    }
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) CPAL_hasPassportAID2(void)
{
#if PASSPORT_ENABLED2
    VAR(DIST_RESULT_t2, ANFCRL_VAR) result2 = DIST_RESULT_ERROR2;

    /* According to Table 60 in [ISO 7816-4]
     * Especially section 12.2.5.2 is of interest
     * CLA=0, INS=A4, P1=4, P2=0: That is required to activate by aid
     * Followed by Lc=<leo of content> <aid> Le=<expected answer length> */
    VAR(uint8, ANFCRL_VAR) command2[] = { 0x00, 0xA4, 0x04, 0x00, 0x07, 0xA0, 0x00, 0x00, 0xDE,
            0xAD, 0xBE, 0xEF, 0x09 };
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) Answer2;
    VAR(uint16, ANFCRL_VAR) AnswerSize2;

    result2 = exchangeApdu2(command2, sizeof(command2), &Answer2, &AnswerSize2);

    /* APDU response received so check it */
    if ((result2 == DIST_RESULT_RESUME2) && (AnswerSize2 > 2U))
    {
        // CONSOLE_MESSAGE("\n\r AID found\r\n");
        /* Passports are considered as cards */
        return DIST_RESULT_PROHIBIT2;

    }
    else
    {
        return result2;
    }
#else
  return DIST_RESULT_RESUME2;

#endif
}


FUNC(void, ANFCRL_CODE) printTagInfo2(VAR(uint16, ANFCRL_VAR) wTagsDetected2)
{
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2 =
            phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);
    VAR(uint8, ANFCRL_VAR) bTagType2;

    if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_A2))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.ModeTech2 = NFC_TECH_A2;
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.UidLen2 = pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].bUidSize2;
        (void)memcpy(nfcDevice2.Uid2, pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aUid2,
                nfcDevice2.UidLen2);

        if ((pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aSak2 & (uint8) ~0xFBU) == 0U)
        {
            /* Bit b3 is set to zero, [Digital] 4.8.2 */
            /* Mask out all other bits except for b7 and b6 */
            bTagType2 = (pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aSak2 & 0x60U);
            bTagType2 = bTagType2 >> 5U;

            switch (bTagType2)
            {
                case PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK2:
                    nfcDevice2.Protocol2 = NFC_PROT_T2T2;
                    // CONSOLE_MESSAGE("\n\r\tType 2 Tag\n");
                    break;
                case PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK2:
                    nfcDevice2.Protocol2 = NFC_PROT_ISODEP2;
                    // CONSOLE_MESSAGE("\n\r\tType 4A Tag\n");
                    break;
                case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK2:
                    nfcDevice2.Protocol2 = NFC_PROT_NFCDEP2;
                    nfcDevice2.Interface2 = NFC_INTF_NFC_DEP2;
                    // CONSOLE_MESSAGE("\n\r\tNFC_DEP\n");
                    break;
                case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK2:
                    nfcDevice2.Protocol2 = NFC_PROT_NFCDEP2;
                    nfcDevice2.Interface2 = NFC_INTF_NFC_DEP2;
                    // CONSOLE_MESSAGE("\n\r\tType NFC_DEP and  4A Tag\n");
                    break;
                default:
                    /* Handle error cases not explicitly */
                    break;
            }
        }

		// CONSOLE_MESSAGE("\n\r\tUID:");
		print_Buff2(pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aUid2,
				pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].bUidSize2);
    }
    if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_B2))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.ModeTech2 = NFC_TECH_B2;

        // CONSOLE_MESSAGE("\n\r\tType B");

        // CONSOLE_MESSAGE("\n\r\tUID :");
        /* PUPI Length is always 4 bytes */
        print_Buff2(pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].aPupi2, 0x04U);

        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.UidLen2 = 0x04U;
        (void)memcpy(nfcDevice2.Uid2, pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].aPupi2, 0x04U);

        // CONSOLE_MESSAGE("\n\r");
    }
    if ( PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_F2122) ||
            PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_F4242))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.ModeTech2 = NFC_TECH_F2;
        // CONSOLE_MESSAGE("\n\r\tType F");

        // CONSOLE_MESSAGE("\n\r\tUID :");
        print_Buff2(pDataParams2->sTypeFTargetInfo2.aTypeFTag2[0].aIDmPMm2,
                PHAC_DISCLOOP_FELICA_IDM_LENGTH2);

        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.UidLen2 = PHAC_DISCLOOP_FELICA_IDM_LENGTH2;
        (void)memcpy(nfcDevice2.Uid2, pDataParams2->sTypeFTargetInfo2.aTypeFTag2[0].aIDmPMm2,
                PHAC_DISCLOOP_FELICA_IDM_LENGTH2);

            // CONSOLE_MESSAGE("\n\r\tType 3 Tag");
    }
    if (PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_V2))
    {
        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.ModeTech2 = NFC_TECH_156932;
        // CONSOLE_MESSAGE("\n\r\tType V / ISO 15693 / T5T");

        // CONSOLE_MESSAGE("\n\r\tUID :");
        print_Buff2(pDataParams2->sTypeVTargetInfo2.aTypeV2[0].aUid2, 0x08U);

        /* Mapping of aNFC Reader Library -> RFID Protection enumeration */
        nfcDevice2.UidLen2 = 0x08U;
        (void)memcpy(nfcDevice2.Uid2, pDataParams2->sTypeVTargetInfo2.aTypeV2[0].aUid2, 0x08U);

        // CONSOLE_MESSAGE("\n\r");
    }
}

FUNC(void, ANFCRL_CODE) printErrorInfo2(VAR(uint16, ANFCRL_VAR) wStatus2)
{
    DEBUG_MESSAGE2("\n ErrorInfo Comp:");

    switch (wStatus2 & 0xFF00U)
    {
        case PH_COMP_BAL2:
            DEBUG_MESSAGE2("\t PH_COMP_BAL2");
            break;
        case PH_COMP_HAL2:
            DEBUG_MESSAGE2("\t PH_COMP_HAL2");
            break;
        case PH_COMP_PAL_ISO14443P3A2:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_ISO14443P3A2");
            break;
        case PH_COMP_PAL_ISO14443P3B2:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_ISO14443P3B2");
            break;
        case PH_COMP_PAL_ISO14443P4A2:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_ISO14443P4A2");
            break;
        case PH_COMP_PAL_ISO14443P42:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_ISO14443P42");
            break;
        case PH_COMP_PAL_FELICA2:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_FELICA2");
            break;
        case PH_COMP_PAL_EPCUID2:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_EPCUID2");
            break;
        case PH_COMP_PAL_SLI156932:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_SLI156932");
            break;
        case PH_COMP_PAL_I14443P4MC2:
            DEBUG_MESSAGE2("\t PH_COMP_PAL_I14443P4MC2");
            break;
        case PH_COMP_AC_DISCLOOP2:
            DEBUG_MESSAGE2("\t PH_COMP_AC_DISCLOOP2");
            break;
        case PH_COMP_OSAL2:
            DEBUG_MESSAGE2("\t PH_COMP_OSAL2");
            break;
        default:
            DEBUG_MESSAGE2("\t 0x%x", (((uint32)wStatus2) & ((uint32)PH_COMPID_MASK2)));
            break;
    }

    DEBUG_MESSAGE2("\t type2:");

    switch (wStatus2 & PH_ERR_MASK2)
    {
        case PH_ERR_SUCCESS_INCOMPLETE_BYTE2:
            DEBUG_MESSAGE2("\t PH_ERR_SUCCESS_INCOMPLETE_BYTE2");
            break;
        case PH_ERR_IO_TIMEOUT2:
            DEBUG_MESSAGE2("\t PH_ERR_IO_TIMEOUT2");
            break;
        case PH_ERR_INTEGRITY_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_INTEGRITY_ERROR2");
            break;
        case PH_ERR_COLLISION_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_COLLISION_ERROR2");
            break;
        case PH_ERR_BUFFER_OVERFLOW2:
            DEBUG_MESSAGE2("\t PH_ERR_BUFFER_OVERFLOW2");
            break;
        case PH_ERR_FRAMING_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_FRAMING_ERROR2");
            break;
        case PH_ERR_PROTOCOL_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_PROTOCOL_ERROR2");
            break;
        case PH_ERR_RF_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_RF_ERROR2");
            break;
        case PH_ERR_EXT_RF_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_EXT_RF_ERROR2");
            break;
        case PH_ERR_NOISE_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_NOISE_ERROR2");
            break;
        case PH_ERR_ABORTED2:
            DEBUG_MESSAGE2("\t PH_ERR_ABORTED2");
            break;
        case PH_ERR_INTERNAL_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_INTERNAL_ERROR2");
            break;
        case PH_ERR_INVALID_DATA_PARAMS2:
            DEBUG_MESSAGE2("\t PH_ERR_INVALID_DATA_PARAMS2");
            break;
        case PH_ERR_INVALID_PARAMETER2:
            DEBUG_MESSAGE2("\t PH_ERR_INVALID_PARAMETER2");
            break;
        case PH_ERR_PARAMETER_OVERFLOW2:
            DEBUG_MESSAGE2("\t PH_ERR_PARAMETER_OVERFLOW2");
            break;
        case PH_ERR_UNSUPPORTED_PARAMETER2:
            DEBUG_MESSAGE2("\t PH_ERR_UNSUPPORTED_PARAMETER2");
            break;
        case PH_ERR_OSAL_ERROR2:
            DEBUG_MESSAGE2("\t PH_ERR_OSAL_ERROR2");
            break;
        case PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED2:
            DEBUG_MESSAGE2("\t PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED2");
            break;
        case PHAC_DISCLOOP_COLLISION_PENDING2:
            DEBUG_MESSAGE2("\t PHAC_DISCLOOP_COLLISION_PENDING2");
            break;
        default:
            DEBUG_MESSAGE2("\t 0x%x", (((uint32)wStatus2) & ((uint32)PH_ERR_MASK2)));
            break;
    }
}

/**
 * This function will print buffer content
 * \param2   *pBuff2   Buffer Reference
 * \param2   num2      data size to be print
 */
FUNC(void, ANFCRL_CODE) print_Buff2(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuff2,
        VAR(uint8, ANFCRL_VAR) num2)
{
    VAR(uint32, ANFCRL_VAR) i2;

    for (i2 = 0U; i2 < num2; i2++)
    {
        // CONSOLE_MESSAGE_1(" %02X", pBuff2[i2]);
    }
    UNUSED (pBuff2);
}

FUNC(DIST_RESULT_t2, ANFCRL_CODE) exchangeApdu2(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCommand2,
    VAR(uint16, ANFCRL_VAR) CommandSize2,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAnswer2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pAnswerSize2)
{
  UNUSED (pCommand2);
  UNUSED (CommandSize2);
  UNUSED (pAnswer2);
  UNUSED (pAnswerSize2);
#if PASSPORT_ENABLED2
    VAR(phStatus_t2, ANFCRL_VAR) result2 = PH_ERR_SUCCESS2;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuff2 = NULL;
    VAR(uint16, ANFCRL_VAR) wRxBuffLen2 = 0U;
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop2 =
            phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);

  /* Select AID */
  result2 = phpalI14443p4_Exchange2(pDiscLoop2->pPal14443p4DataParams2,PH_EXCHANGE_DEFAULT2,
      pCommand2, CommandSize2, &pRxBuff2, &wRxBuffLen2 );

    if (result2 == PH_STATUS_INPROCESS2)
    {
        return DIST_RESULT_IN_PROGRESS2;
    }
    else if (result2 == PH_ERR_SUCCESS2)
    {
        /* return buffers are valid2 now */
        *pAnswer2 = pRxBuff2;
        *pAnswerSize2 = wRxBuffLen2;
        return DIST_RESULT_RESUME2;
    }
    else
    {
        // CONSOLE_MESSAGE("Undefined state\r\n");
        printErrorInfo2(result2);
        return DIST_RESULT_ERROR2;
    }
#else
    return DIST_RESULT_ERROR2;
#endif
}

#if((STD_ON) == ANFCRL_VAS_ENABLED2)
static FUNC(phStatus_t2, ANFCRL_CODE) InitVAS2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    VAR(uint16, ANFCRL_VAR) wPasPollConfig2 = 0U;

    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop2 =
            phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);

    pDiscLoop2->sVASTargetInfo2.pCmdBytes2 = aVASCmd2;
    pDiscLoop2->sVASTargetInfo2.bLenCmdBytes2 = 0x08U;
    status2 = phacDiscLoop_GetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2,
            &wPasPollConfig2);
    // CHECK_NFC_SUCCESS(status2);
    wPasPollConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_VAS2;
    /* Set Passive poll bitmap config. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2,
            wPasPollConfig2);
    // CHECK_NFC_SUCCESS(status2);

    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE2,
    		PHPAL_I14443P3A_VASUP_VERSION_022);
    // CHECK_NFC_SUCCESS(status2);

    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE2,
            PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING2);
    // CHECK_NFC_SUCCESS(status2);

    return status2;
}

static FUNC(phStatus_t2, ANFCRL_CODE) LoadProfileNfcMode2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    VAR(uint16, ANFCRL_VAR) wPasPollConfig2 = 0U;
    VAR(uint16, ANFCRL_VAR) wActPollConfig2 = 0U;
    VAR(uint16, ANFCRL_VAR) wPasLisConfig2 = 0U;
    VAR(uint16, ANFCRL_VAR) wActLisConfig2 = 0U;

    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDiscLoop2 =
    phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
    wPasPollConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    wPasPollConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_B2;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
    wPasPollConfig2 |= (PHAC_DISCLOOP_POS_BIT_MASK_F2122 | PHAC_DISCLOOP_POS_BIT_MASK_F4242);
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    wPasPollConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_V2;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_P2P_ACTIVE2
    wActPollConfig |= PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_P2P_ACTIVE2
    wActPollConfig |= PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_P2P_ACTIVE2
    wActPollConfig |= PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE2
    wPasLisConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE2
    wPasLisConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_F2122;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE2
    wPasLisConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_F4242;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE2
    wActLisConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE2
    wActLisConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_F2122;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE2
    wActLisConfig2 |= PHAC_DISCLOOP_POS_BIT_MASK_F4242;
#endif

    /* passive Bailout bitmap config. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_BAIL_OUT2, 0x00U);
    // CHECK_NFC_SUCCESS(status2);

    /* Set Passive poll bitmap config. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2,
            wPasPollConfig2);
    // CHECK_NFC_SUCCESS(status2);

    /* Set Active poll bitmap config. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG2,
            wActPollConfig2);
    // CHECK_NFC_SUCCESS(status2);

    /* Set Passive listen bitmap config. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG2,
            wPasLisConfig2);
    // CHECK_NFC_SUCCESS(status2);

    /* Set Active listen bitmap config. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG2,
            wActLisConfig2);
    // CHECK_NFC_SUCCESS(status2);

    /* reset collision Pending */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2, PH_OFF2);
    // CHECK_NFC_SUCCESS(status2);

    /* whether anti-collision is supported or not. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_ANTI_COLL2, PH_ON2);
    // CHECK_NFC_SUCCESS(status2);

    /* Poll Mode default state*/
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2,
    PHAC_DISCLOOP_POLL_STATE_DETECTION2);
    // CHECK_NFC_SUCCESS(status2);

#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
    /* Device limit for Type A */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT2, 3U);
    // CHECK_NFC_SUCCESS(status2);

    /* Passive polling Tx Guard times in micro seconds. */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_GTA_VALUE_US2, 5100U);
    // CHECK_NFC_SUCCESS(status2);
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    /* Device limit for Type B */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT2, 3U);
    // CHECK_NFC_SUCCESS(status2);

    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_GTB_VALUE_US2, 5100U);
    // CHECK_NFC_SUCCESS(status2);
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
    /* Device limit for Type F */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT2, 3U);
    // CHECK_NFC_SUCCESS(status2);

    /* Guard time for Type F. This guard time is applied when Type F poll before Type B */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US2, 20400U);
    // CHECK_NFC_SUCCESS(status2);

    /* Guard time for Type F. This guard time is applied when Type B poll before Type F */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US2, 15300U);
    // CHECK_NFC_SUCCESS(status2);
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    /* Device limit for Type V (ISO 15693) */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT2, 3U);
    // CHECK_NFC_SUCCESS(status2);

    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_GTV_VALUE_US2, 5200U);
    // CHECK_NFC_SUCCESS(status2);
#endif

    /* NFC Activity version supported */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION2,
    PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12);
    // CHECK_NFC_SUCCESS(status2);

    /* Discovery loop Operation mode */
    status2 = phacDiscLoop_SetConfig2(pDiscLoop2, PHAC_DISCLOOP_CONFIG_OPE_MODE2, RD_LIB_MODE_NFC2);
    // CHECK_NFC_SUCCESS(status2);

    return status2;
}
#endif /* (STD_ON) == ANFCRL_VAS_ENABLED2 */
