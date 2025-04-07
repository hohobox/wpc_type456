/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2023
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
#include <Nfcrdlib_Detect_Card2.h>
#include <APDUApp_SampleTask2.h>
#include <phacDiscLoop2.h>
#include <phTools2.h>
#include <rf_config2.h>

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "phhalHw_Ncx33212.h"
#include "App_NFC.h"
#include "EcuInfo.h"

#include <Nfcrdlib2.h>

// #define RTE_ALLOW_CROSS_HEADER_INCLUSION
// #include "Rte_IoHwAb.h"
// #include "Rte_App_CAN_RX.h"

#elif defined (PHDRIVER_S32K116)
#include <pcc_hw_access.h>

#endif	/* NIDEC_PORTING */

static VAR(uint8, ANFCRL_VAR) bMoreCards2 = 0U;
static VAR(ANFC_MAIN_StateType_t2, ANFCRL_VAR) ANFC_Main_State2 = ANFC_STATE_IDLE2;
/*The below variables needs to be initialized according to example requirements by a customer */
static VAR(uint8, ANFCRL_VAR) bLenUid_A2 = 0U;
static VAR(uint8, ANFCRL_VAR) bSakNum2 = 0U;
static VAR(uint8, ANFCRL_VAR) gpUid_A2[16] ={ 0x00U };
static VAR(uint8, ANFCRL_VAR) bAts2[20] = { 0x00U };
// VASUP-A command
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0x6A, 0x02U, 0xC3U, 0x02U, 0x01U, 0x01U, 0x0FU, 0xFFU };
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x0F, 0x03 }; // HKMC Mock-Test
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x03, 0x03 }; // Hyundai
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x03, 0x07 }; // Hyundai Owner paring mode
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x43 }; // Kia
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x47 }; // Kia Owner paring mode
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x53 }; // Genesis
// static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x57 }; // Genesis Owner paring mode
static VAR(uint8, ANFCRL_VAR) aVASCmd2[8] = { cTCI_Code1, cTCI_Code2, cTCI_Code3, cTCI_Code4, cTCI_Code5, cTCI_Code6, cTCI_Code7, cTCI_Code8 };	// WPC_415_04

static VAR(uint8, ANFCRL_VAR) bAtqa2[2] = { 0x00U };
// static VAR(uint8, ANFCRL_VAR) bVasCmdCounter2 = 0U;

static uint8 isCardDetected2 = NO_CARD2;
static uint8 isPiccOnPCD2 = DEFAULT_STATE2;

static VAR(phApp_Sw_DataParams_t2, ANFCRL_VAR) sSampleApp2;
static VAR(uint8, ANFCRL_VAR) bRetryCnt2 = 0U;

// #define TASK_DELAY
// #ifdef TASK_DELAY
// static VAR(uint32, ANFCRL_VAR) wStartTime2 = 0U;
// static VAR(uint32, ANFCRL_VAR) dwElapsedTime2 = 0U;
// #endif

FUNC(phStatus_t2, ANFCRL_CODE) aNfcRdLib_Init_Platform_Init2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
#ifdef PH_PLATFORM_HAS_ICFRONTEND2
    VAR(phNfcLib_AppContext_t2, ANFCRL_VAR) AppContext2 = { 0x00U };
#endif /* PH_PLATFORM_HAS_ICFRONTEND */

    phNfcLib_DeInit2();
    status2 = phPlatform_Init2();
    CHECK_STATUS2(status2);
    if(PH_ERR_SUCCESS2 == status2)
    {
#ifdef PH_PLATFORM_HAS_ICFRONTEND2
        status2 = phbalReg_Init2(&sBalParams2, (uint16)sizeof(phbalReg_Type_t2));
        CHECK_STATUS2(status2);

        AppContext2.pBalDataparams2 = &sBalParams2;
#ifdef NXPBUILD__PHHAL_HW_NCX33212
        AppContext2.pHalPollFunc2 = &phApp_IrqPolling2;
#endif
        dwStatus2 = phNfcLib_SetContext2(&AppContext2);
        CHECK_NFCLIB_STATUS2(dwStatus2);
#endif
    }

    return status2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) aNfcRdLib_Init_Ncx3321_Init2(void)
{
    return phNfcLib_Init_Ncx3321_Init2();
}

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) aNfcRdLib_Init_Component_Init2(void)
{
    phNfcLib_Status_t2 dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;

    /* Perform Reader Library PAL Initialization */
    dwStatus2 = phNfcLib_Init_PAL_Init2();

    /* Perform Reader Library AL Initialization */
    if (dwStatus2 == PH_NFCLIB_STATUS_SUCCESS2)
        dwStatus2 = phNfcLib_Init_AL_Init2();

    /* Initialize the discover component */
    if (dwStatus2 == PH_NFCLIB_STATUS_SUCCESS2)
        dwStatus2 = phNfcLib_Init_DiscLoop_Sw_Init2();

    return dwStatus2;
}

/* ----------------------------------------------- */
/***    Automotive NFC Library Initialization    ***/
/* ----------------------------------------------- */
FUNC(void, ANFCRL_CODE) ANFCLib_Task_Init2(
    P2VAR(phApp_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
    VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;

    pDataParams2->pPal14443p3aParams2 = phNfcLib_GetDataParams2(PH_COMP_PAL_ISO14443P3A2);
    pDataParams2->pPal14443p4aParams2 = phNfcLib_GetDataParams2(PH_COMP_PAL_ISO14443P4A2);
    pDataParams2->pPal14443p4Params2 = phNfcLib_GetDataParams2(PH_COMP_PAL_ISO14443P42);

// 아래 NFC Type 추가로 인해 Polling 동작시 4번만큼 의미 없는 RF 파형이 생성됨
// 원인 파악 필요.
/* Card Protection */
//	#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
//	    pDataParams2->pPal14443p3bParams2 = phNfcLib_GetDataParams2(PH_COMP_PAL_ISO14443P3B2);
//	#endif /*NXPBUILD__PHPAL_I14443P3B_SW*/
//	#ifdef NXPBUILD__PHPAL_FELICA_SW2
//	    pDataParams2->pPalFelicaParams2 = phNfcLib_GetDataParams2(PH_COMP_PAL_FELICA2);
//	#endif /*NXPBUILD__PHPAL_FELICA_SW*/
//	#ifdef NXPBUILD__PHPAL_SLI15693_SW2
//	    pDataParams2->pPal15693Params2 = phNfcLib_GetDataParams2(PH_COMP_PAL_SLI156932);
//	#endif /*NXPBUILD__PHPAL_SLI15693_SW*/
//	#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
//	    pDataParams2->pDiscLoopParams2 = phNfcLib_GetDataParams2(PH_COMP_AC_DISCLOOP2);
//	#endif /*NXPBUILD__PHAC_DISCLOOP_SW*/
/* Card Protection */

    dwStatus2 = phpalI14443p3a_SetConfig2(pDataParams2->pPal14443p3aParams2, PHPAL_I14443P3A_CONFIG_OPE_MODE2, RD_LIB_MODE_NFC2);
    CHECK_STATUS2(dwStatus2);
    dwStatus2 = phpalI14443p4a_SetConfig2(pDataParams2->pPal14443p4aParams2, PHPAL_I14443P4A_CONFIG_OPE_MODE2, RD_LIB_MODE_NFC2);
    CHECK_STATUS2(dwStatus2);
    dwStatus2 = phpalI14443p4_SetConfig2(pDataParams2->pPal14443p4Params2, PHPAL_I14443P4_CONFIG_OPE_MODE2, RD_LIB_MODE_NFC2);
    CHECK_STATUS2(dwStatus2);
}

FUNC(phStatus_t2, ANFCRL_CODE) aNfcRdLib_Init_Task_Init2(void)
{
    P2VAR(phApp_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pSampleApp2 = &sSampleApp2;
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    /* Set the generic pointer */
    pHal2 = phNfcLib_GetDataParams2(PH_COMP_HAL2);

    status2 = phApp_Configure_IRQ2();
    CHECK_STATUS2(status2);
    if (PH_ERR_SUCCESS2 == status2)
    {
        /* ANFC Library Initialization  */
        ANFCLib_Task_Init2(pSampleApp2);
        //DEBUG_PRINTF2("\n\r NXP ANFCLib- Sample Discover ISO14443-A Card: \n\r");
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) aNfcRdLib_Rf_Config_Init2(void)
{
    return ncx3321_LPCD_init2();
}


/* ----------------------------------------------- */
/***              ANFC Main Task Sample          ***/
/* ----------------------------------------------- */

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_Idle2(VAR(bool, ANFCRL_VAR) enable_lpcd2)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    ANFC_Main_State2 = ANFC_STATE_IDLE2;

    if (!enable_lpcd2)
    {
        aNfcRdLib_setCardDetection2(NO_CARD2);
        aNfcRdLib_setPiccOnPCD2(DEFAULT_STATE2);
    }

#if 0 // CAS_KR: for fast card detection
    do
    {
        status2 = phhalHw_FieldOff2(pHal2);
    } while (status2 == PH_STATUS_INPROCESS2);
#else
    status2 = phhalHw_FieldOff2(pHal2);
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State2;
#endif

    CHECK_STATUS2(status2);
    if (status2 != PH_ERR_SUCCESS2)
        return ANFC_Main_State2;
    DEBUG_PRINTF2("\n Field Off");

    if (enable_lpcd2)
    {
        ANFC_Main_State2 = ANFC_STATE_LPCD_CONFIG2;
        status2 = phApp_ConfigureLPCD2();
        if (status2 == PH_STATUS_INPROCESS2)
            return ANFC_Main_State2;

        CHECK_STATUS2(status2);
        if (status2 != PH_ERR_SUCCESS2)
            return ANFC_Main_State2;

        DEBUG_PRINTF2("\n Card detecting...");
        ANFC_Main_State2 = ANFC_STATE_LPCD_DETECT2;
    }
    else
    {
        ANFC_Main_State2 = ANFC_STATE_APPLY_PROTO_TYPE_A2;
    }

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_LpcdConfig2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    status2 = phApp_ConfigureLPCD2();
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State2;

    CHECK_STATUS2(status2);
    if (status2 != PH_ERR_SUCCESS2)
        return ANFC_Main_State2;

    DEBUG_PRINTF2("\n Card detecting...");
    ANFC_Main_State2 = ANFC_STATE_LPCD_DETECT2;

    return ANFC_Main_State2;
}


FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_LpcdDetect2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    status2 = phhalHw_Lpcd2(pHal2);
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State2;
    CHECK_STATUS2(status2);
    if (status2 != PH_ERR_SUCCESS2)
        return ANFC_Main_State2;
    /*Setup Guard time for exchange*/
    ANFC_Main_State2 = ANFC_STATE_APPLY_PROTO_TYPE_A2;

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_ApplyProtocolSetting2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    aNfcRdLib_setCardDetection2(CARD_DETECTING2);
    aNfcRdLib_setPiccOnPCD2(CARD_DETECTING2);

#if 1 // CAS_KR: for fast card detection
    do
    {
        status2 = phhalHw_ApplyProtocolSettings2(pHal2,PHHAL_HW_CARDTYPE_ISO14443A2);
    } while (status2 == PH_STATUS_INPROCESS2);
#else
    status2 = phhalHw_ApplyProtocolSettings(pHal,PHHAL_HW_CARDTYPE_ISO14443A);
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State;
#endif
    CHECK_STATUS2(status2);

    ANFC_Main_State2 = ANFC_STATE_FIELD_ON2;
    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_FieldOnState2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

#if 0 // CAS_KR: for fast card detection
    do
    {
        status2 = phhalHw_FieldOn2(pHal2);
    } while (status2 == PH_STATUS_INPROCESS2);
#else
    status2 = phhalHw_FieldOn2(pHal2);
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State2;
#endif
    CHECK_STATUS2(status2);
    (void) phhalHw_SetConfig2(pHal2, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2, 5100);
    bRetryCnt2 = 0;
    ANFC_Main_State2 = ANFC_STATE_DETECTING_TYPE_A2;
    // ANFC_Main_State2 = 0xF1;

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_DetectingCard2(VAR(bool, ANFCRL_VAR) detectCardOnly2)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    uint8_t pAtqa2[2];

    aNfcRdLib_setCardDetection2(NO_CARD2);
    aNfcRdLib_setPiccOnPCD2(NO_CARD2);

#if 1 // CAS_KR: for fast card detection
    if(detectCardOnly2)
    {
        do
        {
            status2 = phpalI14443p3a_WakeUpA2(sSampleApp2.pPal14443p3aParams2,
                        pAtqa2);

            bRetryCnt2++;
        } while (status2 == PH_STATUS_INPROCESS2 && bRetryCnt2 < 20);
    }
    else
    {
        do
        {
            status2 = phpalI14443p3a_ActivateCard2(sSampleApp2.pPal14443p3aParams2,
                        NULL, 0U, gpUid_A2, &bLenUid_A2, &bSakNum2, &bMoreCards2);
            bRetryCnt2++;
        // } while (status2 == PH_STATUS_INPROCESS2 && bRetryCnt2 < 20);
        } while (status2 == PH_STATUS_INPROCESS2 && bRetryCnt2 < 100);
        
    }

#else
    status2 = phpalI14443p3a_ActivateCard2(sSampleApp2.pPal14443p3aParams2,
                NULL, 0U, gpUid_A2, &bLenUid_A2, &bSakNum2, &bMoreCards2);
				
#endif
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State2;

    if (status2 == PH_ERR_SUCCESS2)
    {
        DEBUG_PRINTF2("\n|SAK=0x%X, UID=", bSakNum2);
        if (detectCardOnly2)
        {
            aNfcRdLib_setPiccOnPCD2(CARD_DETECTED2);
            ANFC_Main_State2 = ANFC_STATE_PAUSE2;
            return ANFC_Main_State2;
       	}
        aNfcRdLib_setCardDetection2(CARD_DETECTED2);
        phApp_Print_Buff2(gpUid_A2, bLenUid_A2);
        /* Check if there is an ISO-4 compliant card in the RF field */
        /* Mifare DesFire EV & JCOP */
#if 0
    bRetryCnt2 = 0;
    ANFC_Main_State2 = ANFC_STATE_ACTIVATECARD2;

#else
        if (0x20U == (bSakNum2 & 0x20U))
        {
            bRetryCnt2 = 0;
            ANFC_Main_State2 = ANFC_STATE_ACTIVATECARD2;
        }
        else
        {
            ANFC_Main_State2 = ANFC_STATE_DATA_EXCHANGE2;
        }
    
#endif
    }
    else
    {
        ANFC_Main_State2 = ANFC_STATE_VASUPA2;
        // ANFC_Main_State2 = 0xF2;
    }

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_VasupA2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    status2 = phpalI14443p3a_VASUpA2(sSampleApp2.pPal14443p3aParams2, 0x02U, aVASCmd2, sizeof(aVASCmd2),bAtqa2);
    if (status2 == PH_ERR_SUCCESS2)
    {
        ANFC_Main_State2 = ANFC_STATE_DATA_EXCHANGE2;
        DEBUG_PRINTF2("\n######## Need to check this state #######");
        DEBUG_PRINTF2("\n######## Need to check this state #######");
        DEBUG_PRINTF2("\n######## Need to check this state #######");
    }
    else if (status2 != PH_STATUS_INPROCESS2)
    {
        ANFC_Main_State2 = ANFC_STATE_IDLE2;
        DEBUG_PRINTF2("\n~~~ No Card. Status=%x", status2);
    }

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_ActivateCard2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) bCidEnabled2;
    VAR(uint8, ANFCRL_VAR) bCid2;
    VAR(uint8, ANFCRL_VAR) bNadSupported2;
    VAR(uint8, ANFCRL_VAR) bFwi2;
    VAR(uint8, ANFCRL_VAR) bFsdi2;
    VAR(uint8, ANFCRL_VAR) bFsci2;


#if 1 // CAS_KR: for fast card detection
    do
    {
        status2 = phpalI14443p4a_ActivateCard2(sSampleApp2.pPal14443p4aParams2,
                        0U, 0U, 0U, 0U, bAts2);
        bRetryCnt2++;
    } while (status2 == PH_STATUS_INPROCESS2 && bRetryCnt2 < 20);
#else
    status2 = phpalI14443p4a_ActivateCard(sSampleApp.pPal14443p4aParams,
                    0U, 0U, 0U, 0U, bAts);
#endif
    if (status2 == PH_STATUS_INPROCESS2)
        return ANFC_Main_State2;

    if (status2 == PH_ERR_SUCCESS2)
    {
        DEBUG_PRINTF2("\n|ATS=");
        phApp_Print_Buff2(bAts2, 6U);
        DEBUG_PRINTF2(", FSCI=%d", ((phpalI14443p4a_Sw_DataParams_t2* )(sSampleApp2.pPal14443p4aParams2))->bFsci2);
        DEBUG_PRINTF2(", FWT=%d", ((phpalI14443p4a_Sw_DataParams_t2* )(sSampleApp2.pPal14443p4aParams2))->bFwi2);
        DEBUG_PRINTF2("\n----------------------\n");

        /* Retrieve 14443-4A protocol parameter */
        status2 = phpalI14443p4a_GetProtocolParams2(sSampleApp2.pPal14443p4aParams2,
                &bCidEnabled2, &bCid2, &bNadSupported2, &bFwi2, &bFsdi2, &bFsci2);
        if (status2 != PH_ERR_SUCCESS2)
        {
            ANFC_Main_State2 = ANFC_STATE_IDLE2;
            return ANFC_Main_State2;
        }

        /* Set 14443-4 protocol parameter */
        status2 = phpalI14443p4_SetProtocol2(sSampleApp2.pPal14443p4Params2, bCidEnabled2,
                bCid2, bNadSupported2, 0, bFwi2,
                bFsdi2, bFsci2);
        if (status2 != PH_ERR_SUCCESS2)
        {
            ANFC_Main_State2 = ANFC_STATE_IDLE2;
            return ANFC_Main_State2;
        }

        ANFC_Main_State2 = ANFC_STATE_ACTIVATED_N_WAIT2;
    }
    else
    {
        DEBUG_PRINTF2("\n~~~ ActivateCard(ISO14443-4A) Error Status: %x ~~~", status2);
        ANFC_Main_State2 = ANFC_STATE_IDLE2;
    }

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_Activated_N_Wait2(void)
{
    ANFC_Main_State2 = ANFC_STATE_DATA_EXCHANGE2;

    return ANFC_Main_State2;
}

FUNC(ANFC_MAIN_StateType_t2, ANFCRL_CODE) aNfc_DataExchange2(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer2, VAR(uint16, ANFCRL_VAR) length2)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    status2 = ISO14443A_SampleTask2(&sSampleApp2, (bSakNum2 & 0x20U), txBuffer2, length2);
    if (status2 == PH_STATUS_INPROCESS2)
    {
        return ANFC_Main_State2;
    }

    ANFC_Main_State2 = ANFC_STATE_IDLE2;

    return ANFC_Main_State2;
}

// NO_CARD2 = 0,
// CARD_DETECTED2 = 1,
// CARD_DETECTING2 = 2,
// DEFAULT_STATE2 = 3
FUNC(void, ANFCRL_CODE) aNfcRdLib_setCardDetection2(VAR(uint8, ANFCRL_VAR) state2)
{
    // isCardDetected = state2;
    switch(state2)
    {
    case CARD_DETECTED2:
        isCardDetected2 = CARD_DETECTED2;
        break;
    case NO_CARD2:
    case CARD_DETECTING2:
    case DEFAULT_STATE2:
        isCardDetected2 = NO_CARD2;
        break;
    }
}

FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getCardDetection2(void)
{
    return isCardDetected2;
}

FUNC(uint8*, ANFCRL_CODE) aNfcRdLib_get_APDU_RxBuff2(void)
{
    return Get_APDU_RxBuff2();
}

FUNC(uint8, ANFCRL_CODE) aNfcRdLib_get_APDU_RxLength2(void)
{
    return Get_APDU_RxLength2();
}

// NO_CARD2 = 0,
// CARD_DETECTED2 = 1,
// CARD_DETECTING2 = 2,
// DEFAULT_STATE2 = 3

// #define OnThePad_Default               ((OnThePad)0U)            /* Default value */
// #define OnThePad_Off                   ((OnThePad)1U)
// #define OnThePad_On                    ((OnThePad)2U)

FUNC(void, ANFCRL_CODE) aNfcRdLib_setPiccOnPCD2(VAR(uint8, ANFCRL_VAR) state2)
{
    isPiccOnPCD2 = state2;

}

FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getPiccOnPCD2(void)
{
    return isPiccOnPCD2;
}

FUNC(phStatus_t2, ANFCRL_CODE) aNfc_FieldOff2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    status2 = phhalHw_FieldOff2(pHal2);

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) aNfc_FieldOn2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    do
    {
        status2 = phhalHw_ApplyProtocolSettings2(pHal2, PHHAL_HW_CARDTYPE_ISO14443A2);
    } while(status2 == PH_STATUS_INPROCESS2);
    PH_CHECK_SUCCESS2(status2);

    do
    {
        status2 = phhalHw_FieldOn2(pHal2);
    } while(status2 == PH_STATUS_INPROCESS2);

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) aNfc_SwitchModeNormal2(void)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    status2 = phhalHw_Stop_Lpcd2(pHal2);

    return status2;
}

/******************************************************************************
 **                            End Of File
 ******************************************************************************/
