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

#include <phApp_Init.h>
#include <Nfcrdlib_Detect_Card.h>
#include <APDUApp_SampleTask.h>
#include <phacDiscLoop.h>
#include <phTools.h>
#include <rf_config.h>

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "phhalHw_Ncx3321.h"
#include "App_NFC.h"
#include "EcuInfo.h"

#include <Nfcrdlib.h>

// #define RTE_ALLOW_CROSS_HEADER_INCLUSION
// #include "Rte_IoHwAb.h"
// #include "Rte_App_CAN_RX.h"

#elif defined (PHDRIVER_S32K116)
#include <pcc_hw_access.h>

#endif	/* NIDEC_PORTING */

static VAR(uint8, ANFCRL_VAR) bMoreCards = 0U;
static VAR(ANFC_MAIN_StateType_t, ANFCRL_VAR) ANFC_Main_State = ANFC_STATE_IDLE;
/*The below variables needs to be initialized according to example requirements by a customer */
static VAR(uint8, ANFCRL_VAR) bLenUid_A = 0U;
static VAR(uint8, ANFCRL_VAR) bSakNum = 0U;
static VAR(uint8, ANFCRL_VAR) gpUid_A[16] ={ 0x00U };
static VAR(uint8, ANFCRL_VAR) bAts[20] = { 0x00U };
// VASUP-A command
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0x6A, 0x02U, 0xC3U, 0x02U, 0x01U, 0x01U, 0x0FU, 0xFFU };
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x0F, 0x03 }; // HKMC Mock-Test
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x03, 0x03 }; // Hyundai
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x03, 0x07 }; // Hyundai Owner paring mode
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x43 }; // Kia
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x47 }; // Kia Owner paring mode
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x53 }; // Genesis
// static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { 0xC3, 0x02, 0x01, 0x01, 0x00, 0x57 }; // Genesis Owner paring mode
static VAR(uint8, ANFCRL_VAR) aVASCmd[8] = { cTCI_Code1, cTCI_Code2, cTCI_Code3, cTCI_Code4, cTCI_Code5, cTCI_Code6, cTCI_Code7, cTCI_Code8 };	// WPC_415_04

static VAR(uint8, ANFCRL_VAR) bAtqa[2] = { 0x00U };
// static VAR(uint8, ANFCRL_VAR) bVasCmdCounter = 0U;

static uint8 isCardDetected = NO_CARD;
static uint8 isPiccOnPCD = DEFAULT_STATE;

static VAR(phApp_Sw_DataParams_t, ANFCRL_VAR) sSampleApp;
static VAR(uint8, ANFCRL_VAR) bRetryCnt = 0U;

// #define TASK_DELAY
// #ifdef TASK_DELAY
// static VAR(uint32, ANFCRL_VAR) wStartTime = 0U;
// static VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;
// #endif

FUNC(phStatus_t, ANFCRL_CODE) aNfcRdLib_Init_Platform_Init(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    VAR(phNfcLib_Status_t, ANFCRL_VAR) dwStatus = PH_NFCLIB_STATUS_SUCCESS;
#ifdef PH_PLATFORM_HAS_ICFRONTEND
    VAR(phNfcLib_AppContext_t, ANFCRL_VAR) AppContext = { 0x00U };
#endif /* PH_PLATFORM_HAS_ICFRONTEND */

    phNfcLib_DeInit();
    status = phPlatform_Init();
    CHECK_STATUS(status);
    if(PH_ERR_SUCCESS == status)
    {
#ifdef PH_PLATFORM_HAS_ICFRONTEND
        status = phbalReg_Init(&sBalParams, (uint16)sizeof(phbalReg_Type_t));
        CHECK_STATUS(status);

        AppContext.pBalDataparams = &sBalParams;
#ifdef NXPBUILD__PHHAL_HW_NCX3321
        AppContext.pHalPollFunc = &phApp_IrqPolling;
#endif
        dwStatus = phNfcLib_SetContext(&AppContext);
        CHECK_NFCLIB_STATUS(dwStatus);
#endif
    }

    return status;
}

FUNC(phNfcLib_Status_t, ANFCRL_CODE) aNfcRdLib_Init_Ncx3321_Init(void)
{
    return phNfcLib_Init_Ncx3321_Init();
}

FUNC(phNfcLib_Status_t, ANFCRL_CODE) aNfcRdLib_Init_Component_Init(void)
{
    phNfcLib_Status_t dwStatus = PH_NFCLIB_STATUS_SUCCESS;

    /* Perform Reader Library PAL Initialization */
    dwStatus = phNfcLib_Init_PAL_Init();

    /* Perform Reader Library AL Initialization */
    if (dwStatus == PH_NFCLIB_STATUS_SUCCESS)
        dwStatus = phNfcLib_Init_AL_Init();

    /* Initialize the discover component */
    if (dwStatus == PH_NFCLIB_STATUS_SUCCESS)
        dwStatus = phNfcLib_Init_DiscLoop_Sw_Init();

    return dwStatus;
}

/* ----------------------------------------------- */
/***    Automotive NFC Library Initialization    ***/
/* ----------------------------------------------- */
FUNC(void, ANFCRL_CODE) ANFCLib_Task_Init(
    P2VAR(phApp_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phNfcLib_Status_t, ANFCRL_VAR) dwStatus = PH_NFCLIB_STATUS_SUCCESS;

    pDataParams->pPal14443p3aParams = phNfcLib_GetDataParams(PH_COMP_PAL_ISO14443P3A);
    pDataParams->pPal14443p4aParams = phNfcLib_GetDataParams(PH_COMP_PAL_ISO14443P4A);
    pDataParams->pPal14443p4Params = phNfcLib_GetDataParams(PH_COMP_PAL_ISO14443P4);

// 아래 NFC Type 추가로 인해 Polling 동작시 4번만큼 의미 없는 RF 파형이 생성됨
// 원인 파악 필요.
/* Card Protection */
// #ifdef NXPBUILD__PHPAL_I14443P3B_SW
//     pDataParams->pPal14443p3bParams = phNfcLib_GetDataParams(PH_COMP_PAL_ISO14443P3B);
// #endif /*NXPBUILD__PHPAL_I14443P3B_SW*/
// #ifdef NXPBUILD__PHPAL_FELICA_SW
//     pDataParams->pPalFelicaParams = phNfcLib_GetDataParams(PH_COMP_PAL_FELICA);
// #endif /*NXPBUILD__PHPAL_FELICA_SW*/
// #ifdef NXPBUILD__PHPAL_SLI15693_SW
//     pDataParams->pPal15693Params = phNfcLib_GetDataParams(PH_COMP_PAL_SLI15693);
// #endif /*NXPBUILD__PHPAL_SLI15693_SW*/
// #ifdef NXPBUILD__PHAC_DISCLOOP_SW
//     pDataParams->pDiscLoopParams = phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);
// #endif /*NXPBUILD__PHAC_DISCLOOP_SW*/
/* Card Protection */

    dwStatus = phpalI14443p3a_SetConfig(pDataParams->pPal14443p3aParams, PHPAL_I14443P3A_CONFIG_OPE_MODE, RD_LIB_MODE_NFC);
    CHECK_STATUS(dwStatus);
    dwStatus = phpalI14443p4a_SetConfig(pDataParams->pPal14443p4aParams, PHPAL_I14443P4A_CONFIG_OPE_MODE, RD_LIB_MODE_NFC);
    CHECK_STATUS(dwStatus);
    dwStatus = phpalI14443p4_SetConfig(pDataParams->pPal14443p4Params, PHPAL_I14443P4_CONFIG_OPE_MODE, RD_LIB_MODE_NFC);
    CHECK_STATUS(dwStatus);
}

FUNC(phStatus_t, ANFCRL_CODE) aNfcRdLib_Init_Task_Init(void)
{
    P2VAR(phApp_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pSampleApp = &sSampleApp;
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    /* Set the generic pointer */
    pHal = phNfcLib_GetDataParams(PH_COMP_HAL);

    status = phApp_Configure_IRQ();
    CHECK_STATUS(status);
    if (PH_ERR_SUCCESS == status)
    {
        /* ANFC Library Initialization  */
        ANFCLib_Task_Init(pSampleApp);
        //DEBUG_PRINTF("\n\r NXP ANFCLib- Sample Discover ISO14443-A Card: \n\r");
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) aNfcRdLib_Rf_Config_Init(void)
{
    return ncx3321_LPCD_init();
}

/* ----------------------------------------------- */
/***              ANFC Main Task Sample          ***/
/* ----------------------------------------------- */

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_Idle(VAR(bool, ANFCRL_VAR) enable_lpcd)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    ANFC_Main_State = ANFC_STATE_IDLE;

    if (!enable_lpcd)
    {
        aNfcRdLib_setCardDetection(NO_CARD);
        aNfcRdLib_setPiccOnPCD(DEFAULT_STATE);
    }

#if 0 // CAS_KR: for fast card detection
    do
    {
        status = phhalHw_FieldOff(pHal);
    } while (status == PH_STATUS_INPROCESS);
#else
    status = phhalHw_FieldOff(pHal);
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;
#endif

    CHECK_STATUS(status);
    if (status != PH_ERR_SUCCESS)
        return ANFC_Main_State;
    DEBUG_PRINTF("\n Field Off");

    if (enable_lpcd)
    {
        ANFC_Main_State = ANFC_STATE_LPCD_CONFIG;
        status = phApp_ConfigureLPCD();
        if (status == PH_STATUS_INPROCESS)
            return ANFC_Main_State;

        CHECK_STATUS(status);
        if (status != PH_ERR_SUCCESS)
            return ANFC_Main_State;

        DEBUG_PRINTF("\n Card detecting...");
        ANFC_Main_State = ANFC_STATE_LPCD_DETECT;
    }
    else
    {
        ANFC_Main_State = ANFC_STATE_APPLY_PROTO_TYPE_A;
    }

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_LpcdConfig(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    status = phApp_ConfigureLPCD();
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;

    CHECK_STATUS(status);
    if (status != PH_ERR_SUCCESS)
        return ANFC_Main_State;

    DEBUG_PRINTF("\n Card detecting...");
    ANFC_Main_State = ANFC_STATE_LPCD_DETECT;

    return ANFC_Main_State;
}


FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_LpcdDetect(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    status = phhalHw_Lpcd(pHal);
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;
    CHECK_STATUS(status);
    if (status != PH_ERR_SUCCESS)
        return ANFC_Main_State;
    /*Setup Guard time for exchange*/
    ANFC_Main_State = ANFC_STATE_APPLY_PROTO_TYPE_A;

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_ApplyProtocolSetting(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    aNfcRdLib_setCardDetection(CARD_DETECTING);
    aNfcRdLib_setPiccOnPCD(CARD_DETECTING);

#if 1 // CAS_KR: for fast card detection
    do
    {
        status = phhalHw_ApplyProtocolSettings(pHal,PHHAL_HW_CARDTYPE_ISO14443A);
    } while (status == PH_STATUS_INPROCESS);
#else
    status = phhalHw_ApplyProtocolSettings(pHal,PHHAL_HW_CARDTYPE_ISO14443A);
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;
#endif
    CHECK_STATUS(status);

    ANFC_Main_State = ANFC_STATE_FIELD_ON;
    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_FieldOnState(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

#if 0 // CAS_KR: for fast card detection
    do
    {
        status = phhalHw_FieldOn(pHal);
    } while (status == PH_STATUS_INPROCESS);
#else
    status = phhalHw_FieldOn(pHal);
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;
#endif
    CHECK_STATUS(status);
    (void) phhalHw_SetConfig(pHal, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US, 5100);
    bRetryCnt = 0;
    ANFC_Main_State = ANFC_STATE_DETECTING_TYPE_A;
    // ANFC_Main_State = 0xF1;

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_DetectingCard(VAR(bool, ANFCRL_VAR) detectCardOnly)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    uint8_t pAtqa[2];

    aNfcRdLib_setCardDetection(NO_CARD);
    aNfcRdLib_setPiccOnPCD(NO_CARD);

#if 1 // CAS_KR: for fast card detection
    if(detectCardOnly)
    {
        do
        {
            status = phpalI14443p3a_WakeUpA(sSampleApp.pPal14443p3aParams,
                        pAtqa);            

            bRetryCnt++;
        } while (status == PH_STATUS_INPROCESS && bRetryCnt < 20);
    }
    else
    {
        do
        {
            status = phpalI14443p3a_ActivateCard(sSampleApp.pPal14443p3aParams,
                        NULL, 0U, gpUid_A, &bLenUid_A, &bSakNum, &bMoreCards);
            bRetryCnt++;
        // } while (status == PH_STATUS_INPROCESS && bRetryCnt < 20);
        } while (status == PH_STATUS_INPROCESS && bRetryCnt < 100);
        
    }
    
#else
    status = phpalI14443p3a_ActivateCard(sSampleApp.pPal14443p3aParams,
                NULL, 0U, gpUid_A, &bLenUid_A, &bSakNum, &bMoreCards);
#endif
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;

    if (status == PH_ERR_SUCCESS)
    {
        DEBUG_PRINTF("\n|SAK=0x%X, UID=", bSakNum);
        if (detectCardOnly)
        {
            aNfcRdLib_setPiccOnPCD(CARD_DETECTED);
            ANFC_Main_State = ANFC_STATE_PAUSE;
            return ANFC_Main_State;
       	}
        aNfcRdLib_setCardDetection(CARD_DETECTED);
        phApp_Print_Buff(gpUid_A, bLenUid_A);
        /* Check if there is an ISO-4 compliant card in the RF field */
        /* Mifare DesFire EV & JCOP */
#if 0
    bRetryCnt = 0;
    ANFC_Main_State = ANFC_STATE_ACTIVATECARD;

#else
        if (0x20U == (bSakNum & 0x20U))
        {
            bRetryCnt = 0;
            ANFC_Main_State = ANFC_STATE_ACTIVATECARD;
        }
        else
        {
            ANFC_Main_State = ANFC_STATE_DATA_EXCHANGE;
        }
    
#endif
    }
    else
    {
        ANFC_Main_State = ANFC_STATE_VASUPA;
        // ANFC_Main_State = 0xF2;
    }

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_VasupA(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    status = phpalI14443p3a_VASUpA(sSampleApp.pPal14443p3aParams, 0x02U, aVASCmd, sizeof(aVASCmd),bAtqa);
    if (status == PH_ERR_SUCCESS)
    {
        ANFC_Main_State = ANFC_STATE_DATA_EXCHANGE;
        DEBUG_PRINTF("\n######## Need to check this state #######");
        DEBUG_PRINTF("\n######## Need to check this state #######");
        DEBUG_PRINTF("\n######## Need to check this state #######");
    }
    else if (status != PH_STATUS_INPROCESS)
    {
        ANFC_Main_State = ANFC_STATE_IDLE;
        DEBUG_PRINTF("\n~~~ No Card. Status=%x", status);
    }

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_ActivateCard(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) bCidEnabled;
    VAR(uint8, ANFCRL_VAR) bCid;
    VAR(uint8, ANFCRL_VAR) bNadSupported;
    VAR(uint8, ANFCRL_VAR) bFwi;
    VAR(uint8, ANFCRL_VAR) bFsdi;
    VAR(uint8, ANFCRL_VAR) bFsci;


#if 1 // CAS_KR: for fast card detection
    do
    {
        status = phpalI14443p4a_ActivateCard(sSampleApp.pPal14443p4aParams,
                        0U, 0U, 0U, 0U, bAts);
        bRetryCnt++;
    } while (status == PH_STATUS_INPROCESS && bRetryCnt < 20);
#else
    status = phpalI14443p4a_ActivateCard(sSampleApp.pPal14443p4aParams,
                    0U, 0U, 0U, 0U, bAts);
#endif
    if (status == PH_STATUS_INPROCESS)
        return ANFC_Main_State;

    if (status == PH_ERR_SUCCESS)
    {
        DEBUG_PRINTF("\n|ATS=");
        phApp_Print_Buff(bAts, 6U);
        DEBUG_PRINTF(", FSCI=%d", ((phpalI14443p4a_Sw_DataParams_t* )(sSampleApp.pPal14443p4aParams))->bFsci);
        DEBUG_PRINTF(", FWT=%d", ((phpalI14443p4a_Sw_DataParams_t* )(sSampleApp.pPal14443p4aParams))->bFwi);
        DEBUG_PRINTF("\n----------------------\n");

        /* Retrieve 14443-4A protocol parameter */
        status = phpalI14443p4a_GetProtocolParams(sSampleApp.pPal14443p4aParams,
                &bCidEnabled, &bCid, &bNadSupported, &bFwi, &bFsdi, &bFsci);
        if (status != PH_ERR_SUCCESS)
        {
            ANFC_Main_State = ANFC_STATE_IDLE;
            return ANFC_Main_State;
        }

        /* Set 14443-4 protocol parameter */
        status = phpalI14443p4_SetProtocol(sSampleApp.pPal14443p4Params, bCidEnabled,
                bCid, bNadSupported, 0, bFwi,
                bFsdi, bFsci);
        if (status != PH_ERR_SUCCESS)
        {
            ANFC_Main_State = ANFC_STATE_IDLE;
            return ANFC_Main_State;
        }

        ANFC_Main_State = ANFC_STATE_ACTIVATED_N_WAIT;
    }
    else
    {
        DEBUG_PRINTF("\n~~~ ActivateCard(ISO14443-4A) Error Status: %x ~~~", status);
        ANFC_Main_State = ANFC_STATE_IDLE;
    }

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_Activated_N_Wait(void)
{
    ANFC_Main_State = ANFC_STATE_DATA_EXCHANGE;

    return ANFC_Main_State;
}

FUNC(ANFC_MAIN_StateType_t, ANFCRL_CODE) aNfc_DataExchange(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer, VAR(uint16, ANFCRL_VAR) length)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    status = ISO14443A_SampleTask(&sSampleApp, (bSakNum & 0x20U), txBuffer, length);
    if (status == PH_STATUS_INPROCESS)
    {
        return ANFC_Main_State;;
    }

    ANFC_Main_State = ANFC_STATE_IDLE;

    return ANFC_Main_State;
}

// NO_CARD = 0,
// CARD_DETECTED = 1,
// CARD_DETECTING = 2,
// DEFAULT_STATE = 3
FUNC(void, ANFCRL_CODE) aNfcRdLib_setCardDetection(VAR(uint8, ANFCRL_VAR) state)
{
    // isCardDetected = state;
    switch(state)
    {
    case CARD_DETECTED:
        isCardDetected = CARD_DETECTED;
        break;
    case NO_CARD:
    case CARD_DETECTING:
    case DEFAULT_STATE:
        isCardDetected = NO_CARD;
        break;
    }
}

FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getCardDetection(void)
{
    return isCardDetected;
}

FUNC(uint8*, ANFCRL_CODE) aNfcRdLib_get_APDU_RxBuff(void)
{
    return Get_APDU_RxBuff();
}

FUNC(uint8, ANFCRL_CODE) aNfcRdLib_get_APDU_RxLength(void)
{
    return Get_APDU_RxLength();
}

// NO_CARD = 0,
// CARD_DETECTED = 1,
// CARD_DETECTING = 2,
// DEFAULT_STATE = 3

// #define OnThePad_Default               ((OnThePad)0U)            /* Default value */
// #define OnThePad_Off                   ((OnThePad)1U)
// #define OnThePad_On                    ((OnThePad)2U)

FUNC(void, ANFCRL_CODE) aNfcRdLib_setPiccOnPCD(VAR(uint8, ANFCRL_VAR) state)
{
    isPiccOnPCD = state;

}

FUNC(uint8, ANFCRL_CODE) aNfcRdLib_getPiccOnPCD(void)
{
    return isPiccOnPCD;
}

FUNC(phStatus_t, ANFCRL_CODE) aNfc_FieldOff(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    status = phhalHw_FieldOff(pHal);

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) aNfc_FieldOn(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    do
    {
        status = phhalHw_ApplyProtocolSettings(pHal, PHHAL_HW_CARDTYPE_ISO14443A);
    } while(status == PH_STATUS_INPROCESS);
    PH_CHECK_SUCCESS(status);

    do
    {
        status = phhalHw_FieldOn(pHal);
    } while(status == PH_STATUS_INPROCESS);

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) aNfc_SwitchModeNormal(void)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    status = phhalHw_Stop_Lpcd(pHal);

    return status;
}

/******************************************************************************
 **                            End Of File
 ******************************************************************************/
