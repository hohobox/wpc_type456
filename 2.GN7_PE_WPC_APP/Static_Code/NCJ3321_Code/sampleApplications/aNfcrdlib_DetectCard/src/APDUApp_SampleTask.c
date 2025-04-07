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

#include <phApp_Init.h>
#include <Nfcrdlib_Detect_Card.h>
static VAR(ANFC_APDU_StateType_t, ANFCRL_VAR) ANFC_DOOR_State = ANFC_APDU_SELECT_AID;
//static VAR(uint8, ANFCRL_VAR) bSampleTaskState = 0U;

static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuff = NULL;
static VAR(uint16, ANFCRL_VAR) wRxBuffLen = 0u;

/* ----------------------------------------------- */
/***  APDU Task perform several exchange         ***/
/* ----------------------------------------------- */
static FUNC(phStatus_t, ANFCRL_CODE) APDU_SampleTask(
    P2VAR(phApp_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer, VAR(uint16, ANFCRL_VAR) length)
{
    P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p4Data =
    pDataParams->pPal14443p4Params;
    /* select application */
    //VAR(uint8, ANFCRL_VAR) txBuff[] =
    //    { 0x00U, 0xA4U, 0x04U, 0x00U, 0x05U, 0xA0U, 0x64U, 0x6FU, 0x6FU, 0x72U, 0x00U };

    VAR(phStatus_t, ANFCRL_VAR) status = 0U;
    switch (ANFC_DOOR_State)
    {
        case ANFC_APDU_SELECT_AID:
            /* Select AID */
            status = phpalI14443p4_Exchange(pPal14443p4Data,
            PH_EXCHANGE_DEFAULT, txBuffer, length, &pRxBuff, &wRxBuffLen);

            if (status == PH_STATUS_INPROCESS)
            {
                break;
            }

#if 1 // def DEBUG
			DEBUG_PRINTF("~~~ C-APDU:");
			phApp_Print_Buff(txBuffer, (uint8)sizeof(txBuffer));
			DEBUG_PRINTF("\n");
            if (status == PH_ERR_SUCCESS)
            {
                DEBUG_PRINTF("~~~ R-APDU:");
                phApp_Print_Buff(pRxBuff, (uint8)wRxBuffLen);
                DEBUG_PRINTF("\n");

                ANFC_DOOR_State = ANFC_APDU_FINISH;
                break;
            }
            else
            {
                DEBUG_PRINTF("~~~ No R-APDU. Status=%X\n", status);
            }
#endif
            ANFC_DOOR_State = ANFC_APDU_FINISH;
            break;
        case ANFC_APDU_FINISH:
            ANFC_DOOR_State = ANFC_APDU_SELECT_AID;
            // No protocol reset to send several APDUs
            //status = phpalI14443p4_ResetProtocol(pPal14443p4Data);
            CHECK_STATUS(status);
            /* Return Success or Error */
            return PH_ERR_SUCCESS;
        default:
            break;
    }
    return PH_STATUS_INPROCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) ISO14443A_SampleTask(
    P2VAR(phApp_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) apdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) txBuffer, VAR(uint16, ANFCRL_VAR) length)
{
    VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

    if (apdu != 0U)
    {
        status = APDU_SampleTask(pDataParams, txBuffer, length);
        if (status == PH_STATUS_INPROCESS)
        {
            return PH_STATUS_INPROCESS;
        }
    }
    // No HaltA to send several APDUs
    // bSampleTaskState = 1U;

    return status;
}

FUNC(uint8*, ANFCRL_CODE) Get_APDU_RxBuff(void)
{
	return pRxBuff;
}

FUNC(uint8, ANFCRL_CODE) Get_APDU_RxLength(void)
{
	return (uint8)wRxBuffLen;
}



