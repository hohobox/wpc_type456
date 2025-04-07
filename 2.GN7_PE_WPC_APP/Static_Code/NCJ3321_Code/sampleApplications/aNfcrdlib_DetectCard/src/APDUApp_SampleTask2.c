/*******************************************************************************
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
static VAR(ANFC_APDU_StateType_t2, ANFCRL_VAR) ANFC_DOOR_State2 = ANFC_APDU_SELECT_AID2;
// static VAR(uint8, ANFCRL_VAR) bSampleTaskState2 = 0U;

static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuff2 = NULL;
static VAR(uint16, ANFCRL_VAR) wRxBuffLen2 = 0u;

/* ----------------------------------------------- */
/***  APDU Task perform several exchange         ***/
/* ----------------------------------------------- */
static FUNC(phStatus_t2, ANFCRL_CODE) APDU_SampleTask2(
    P2VAR(phApp_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer2, VAR(uint16, ANFCRL_VAR) length2)
{
    P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p4Data2 =
    pDataParams2->pPal14443p4Params2;
    /* select application */
    //VAR(uint8, ANFCRL_VAR) txBuff2[] =
    //    { 0x00U, 0xA4U, 0x04U, 0x00U, 0x05U, 0xA0U, 0x64U, 0x6FU, 0x6FU, 0x72U, 0x00U };

    VAR(phStatus_t2, ANFCRL_VAR) status2 = 0U;
    switch (ANFC_DOOR_State2)
    {
        case ANFC_APDU_SELECT_AID2:
            /* Select AID */
            status2 = phpalI14443p4_Exchange2(pPal14443p4Data2,
            PH_EXCHANGE_DEFAULT2, txBuffer2, length2, &pRxBuff2, &wRxBuffLen2);

            if (status2 == PH_STATUS_INPROCESS2)
            {
                break;
            }

#if 1 // def DEBUG
			DEBUG_PRINTF2("~~~ C-APDU:");
			phApp_Print_Buff2(txBuffer2, (uint8)sizeof(txBuffer2));
			DEBUG_PRINTF2("\n");
            if (status2 == PH_ERR_SUCCESS2)
            {
                DEBUG_PRINTF2("~~~ R-APDU:");
                phApp_Print_Buff2(pRxBuff2, (uint8)wRxBuffLen2);
                DEBUG_PRINTF2("\n");

                ANFC_DOOR_State2 = ANFC_APDU_FINISH2;
                break;
            }
            else
            {
                DEBUG_PRINTF2("~~~ No R-APDU. Status=%X\n", status2);
            }
#endif
            ANFC_DOOR_State2 = ANFC_APDU_FINISH2;
            break;
        case ANFC_APDU_FINISH2:
            ANFC_DOOR_State2 = ANFC_APDU_SELECT_AID2;
            // No protocol reset to send several APDUs
            //status2 = phpalI14443p4_ResetProtocol2(pPal14443p4Data2);
            CHECK_STATUS2(status2);
            /* Return Success or Error */
            return PH_ERR_SUCCESS2;
        default:
            break;
    }
    return PH_STATUS_INPROCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) ISO14443A_SampleTask2(
    P2VAR(phApp_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) apdu2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer2, VAR(uint16, ANFCRL_VAR) length2)
{
    VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

    if (apdu2 != 0U)
    {
        status2 = APDU_SampleTask2(pDataParams2, txBuffer2, length2);
        if (status2 == PH_STATUS_INPROCESS2)
        {
            return PH_STATUS_INPROCESS2;
        }
    }
    // No HaltA to send several APDUs
    // bSampleTaskState2 = 1U;

    return status2;
}

FUNC(uint8*, ANFCRL_CODE) Get_APDU_RxBuff2(void)
{
	return pRxBuff2;
}

FUNC(uint8, ANFCRL_CODE) Get_APDU_RxLength2(void)
{
	return (uint8)wRxBuffLen2;
}
