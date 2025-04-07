/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2023
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
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGED TO HAVE RESULTED FROM ANY DEFECT, ERROR OR OMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RELATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
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
 /**
*   @file    phTools2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Tools - Common API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phTools Tools
*   @ingroup phcommon
*   @{
*/
/*==================================================================================================
*   Project              : Anfc Reader Library
*   Platform             : ARM
*   Peripheral           : NCX3320
*   Dependencies         : Driver modules
*
*   Build Version        : S32K14X_S32K144_ANFC_Reader_Lib_1_0_20240401
*
*   Copyright 2016-2023 NXP
*
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <phTools2.h>
#include <ph_RefDefs2.h>
#include <NxpNfcRdLib_Ver2.h>
#include <phDriver2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTools2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHTOOLS_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHTOOLS_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHTOOLS_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHTOOLS_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHTOOLS_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHTOOLS_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHTOOLS_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phTools2.h header file are of the same vendor */
#if (PHTOOLS_VENDOR_ID_C2 != PHTOOLS_VENDOR_ID2)
    #error "phTools2.c and phTools2.h have different vendor ids"
#endif
/* Check if current file and phpalSli15693_Sw.h header file are of the same Autosar version */
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C2    != PHTOOLS_AR_RELEASE_MAJOR_VERSION2) || \
     (PHTOOLS_AR_RELEASE_MINOR_VERSION_C2    != PHTOOLS_AR_RELEASE_MINOR_VERSION2) || \
     (PHTOOLS_AR_RELEASE_REVISION_VERSION_C2 != PHTOOLS_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phTools2.c and phTools2.h are different"
#endif
/* Check if current file and phTools2.h header file are of the same Software version */
#if ((PHTOOLS_SW_MAJOR_VERSION_C2 != PHTOOLS_SW_MAJOR_VERSION2) || \
     (PHTOOLS_SW_MINOR_VERSION_C2 != PHTOOLS_SW_MINOR_VERSION2) || \
     (PHTOOLS_SW_PATCH_VERSION_C2 != PHTOOLS_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phTools2.c and phTools2.h are different"
#endif
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint32, ANFCRL_VAR) random_next2 = 1U;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static FUNC(uint8, ANFCRL_CODE) phTools_CalcParity2(VAR(uint8, ANFCRL_VAR) bDataByte2, VAR(uint8, ANFCRL_VAR) bOption2);

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventCreate2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_PollFunc_t2, ANFCRL_VAR) pPollFunc2, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPollFuncParam2)
{
	pDataParams2->bEventState2 = PH_TOOLS_EVENT_IDLE2;
	pDataParams2->pEventPollFunc2 = pPollFunc2;
	pDataParams2->pEventPollParams2 = pPollFuncParam2;
	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventPend2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_EventOpt_t2, ANFCRL_VAR) options2, VAR(uint32, ANFCRL_VAR) timeToWait2, VAR(phTools_EventBits_t2, ANFCRL_VAR) FlagsToWait2,
    P2VAR(phTools_EventBits_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags2)
{
	VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;
	P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) eventHandle2 = &(pDataParams2->wEventHandle2);
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwElapsedTime2 = 0U;

	/*Polling for checking Event's condition*/
	pDataParams2->pEventPollFunc2(pDataParams2->pEventPollParams2);
	if((PH_ERR_SUCCESS2 != pDataParams2->dEventStatus2) &&
			(PH_STATUS_INPROCESS2 != pDataParams2->dEventStatus2))
	{
		status2 = pDataParams2->dEventStatus2;
		/* Reset data parameter values */
		pDataParams2->dEventStatus2 = PH_ERR_SUCCESS2;
		pDataParams2->bEventState2 = PH_TOOLS_EVENT_IDLE2;
		return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
	}
	else
	{
		/* Do nothing */
	}

	switch (pDataParams2->bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:

			pDataParams2->wTimeToWait2 = timeToWait2;
			pDataParams2->bEventState2 = PH_TOOLS_EVENT_PENDING2;
			pDataParams2->dEventStatus2 = PH_STATUS_INPROCESS2;
			pDataParams2->wEventTimeStart2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
			return PH_STATUS_INPROCESS2;

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			if ((((options2 & E_EVENT_OPT_PEND_SET_ALL2) != 0U) && (((*eventHandle2) & FlagsToWait2) == FlagsToWait2))
					|| (((options2 & E_EVENT_OPT_PEND_SET_ALL2) == 0U) && (((*eventHandle2) & FlagsToWait2) != 0U)))
			{
				pDataParams2->dEventStatus2 = PH_ERR_SUCCESS2;
			}
			else
			{
				/* Check whether infinite wait, if not check timer. */
				if (pDataParams2->wTimeToWait2 != PH_TOOLS_EVENT_MAX_DELAY2)
				{
					dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, pDataParams2->wEventTimeStart2);

					/* Check for timer overflow, abort if timer overflow happens */
					if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
					{
						pDataParams2->dEventStatus2 = PH_ERR_ABORTED2;
						status2 = pDataParams2->dEventStatus2;
						break;
					}
					else
					{
						/* Timer's Event */
						if (((uint64)pDataParams2->wTimeToWait2 * 1000U) > (uint64)dwElapsedTime2)
						{
							return PH_STATUS_INPROCESS2;
						}
						else
						{
							pDataParams2->dEventStatus2 = PH_ERR_IO_TIMEOUT2;
						}
					}
				}
				/* Infinite wait */
				else
				{
					return PH_STATUS_INPROCESS2;
				}
			}

			if (pCurrFlags2 != NULL)
			{
				*pCurrFlags2 = *eventHandle2;
			}

			if ((options2 & E_EVENT_OPT_PEND_CLEAR_ON_EXIT2) != 0u)
			{
				*eventHandle2 &= (~(FlagsToWait2 & (*eventHandle2)));
			}
			status2 = pDataParams2->dEventStatus2;
			break;
	}

	pDataParams2->bEventState2 = PH_TOOLS_EVENT_IDLE2;
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventPost2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_EventOpt_t2, ANFCRL_VAR) options2, VAR(phTools_EventBits_t2, ANFCRL_VAR) FlagsToPost2,
  P2VAR(phTools_EventBits_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags2)
{
  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) eventHandle2 = &(pDataParams2->wEventHandle2);
	PH_UNUSED_VARIABLE2(options2);
	/* Set the events. */
	*eventHandle2 |= FlagsToPost2;

	if (pCurrFlags2 != NULL)
	{
		*pCurrFlags2 = *eventHandle2;
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventClear2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_EventOpt_t2, ANFCRL_VAR) options2, VAR(phTools_EventBits_t2, ANFCRL_VAR) FlagsToClear2,
  P2VAR(phTools_EventBits_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags2)
{
  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) eventHandle2 = &(pDataParams2->wEventHandle2);
	PH_UNUSED_VARIABLE2(options2);

	if (pCurrFlags2 != NULL)
	{
		*pCurrFlags2 = *eventHandle2;
	}

	*eventHandle2 &= (~FlagsToClear2);

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EncodeParity2(
                                VAR(uint8, ANFCRL_VAR) bOption2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer2,
                                VAR(uint16, ANFCRL_VAR) wInBufferLength2,
                                VAR(uint8, ANFCRL_VAR) bInBufferBits2,
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer2,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits2
                                )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wByteIndexIn2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wByteIndexOut2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitPosition2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wInByteCount2;

    /* Parameter check */
    if (((bOption2 != PH_TOOLS_PARITY_OPTION_EVEN2) && (bOption2 != PH_TOOLS_PARITY_OPTION_ODD2)) || (bInBufferBits2 > 7U))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    /* Retrieve full input byte count */
    if (bInBufferBits2 == 0U)
    {
        wInByteCount2 = wInBufferLength2;
    }
    else
    {
        wInByteCount2 = wInBufferLength2 - 1u;
    }

    /* Retrieve number of (additional) full bytes */
    (*pOutBufferLength2) = (uint16)((uint16)(wInByteCount2 + bInBufferBits2) >> 3U);

    /* Retrieve output bits */
    *pOutBufferBits2 = (uint8)((uint16)(wInByteCount2 + bInBufferBits2) % 8U);

    /* Increment output length in case of incomplete byte */
    if (*pOutBufferBits2 > 0U)
    {
        ++(*pOutBufferLength2);
    }

    /* Overflow check */
    if ((*pOutBufferLength2) > (0xFFFFU - wInByteCount2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    /* Calculate number of output bytes */
    (*pOutBufferLength2) = wInByteCount2 + (*pOutBufferLength2);

    /* Buffer overflow check*/
    if (wOutBufferSize2 < (*pOutBufferLength2))
    {
        (*pOutBufferLength2) = 0;
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_TOOLS2);
    }

    /* Prepare output buffer */
    pOutBuffer2[0] = 0x00;

    /* Prepare loop vars */
    wByteIndexIn2 = 0;
    wByteIndexOut2 = 0;
    bBitPosition2 = 7;

    /* Do for each byte */
    for (; wByteIndexIn2 < wInBufferLength2; ++wByteIndexIn2 )
    {
        /* Append source bits to output */
        pOutBuffer2[wByteIndexOut2] |= (uint8)(pInBuffer2[wByteIndexIn2] << (7U - bBitPosition2));

        /* If there is more data bits in the source byte append it to next data byte */
        if ((wByteIndexOut2 + 1U) < (*pOutBufferLength2))
        {
            if(bBitPosition2 == 7U)
            {
            pOutBuffer2[wByteIndexOut2 + 1U]  = 0;
            }
            else
            {
            pOutBuffer2[wByteIndexOut2 + 1U]  = (uint8)(pInBuffer2[wByteIndexIn2] >> (1u + bBitPosition2));
            }

            /* Perform parity appending if this isn't an incomplete byte */
            if ((bInBufferBits2 == 0U) || ((wByteIndexIn2 + 1U) < wInBufferLength2))
            {
                pOutBuffer2[wByteIndexOut2 + 1U] |= (uint8)(phTools_CalcParity2(pInBuffer2[wByteIndexIn2], bOption2) << (7U - bBitPosition2));
            }
        }

        /* We have reached the 8th parity bit, the output buffer index is now one ahead */
        if (bBitPosition2 == 0U)
        {
            if ((wByteIndexOut2 + 2U) < (*pOutBufferLength2))
            {
                bBitPosition2 = 8;
                pOutBuffer2[++wByteIndexOut2 + 1U] = 0x00;
            }
        }

        ++wByteIndexOut2;
        --bBitPosition2;
    }

    /* Mask out invalid bits of last byte */
    if (*pOutBufferBits2 > 0U)
    {
        pOutBuffer2[(*pOutBufferLength2) - 1U] &= (uint8)(0xFFU >> (8U - *pOutBufferBits2));
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_DecodeParity2(
                                VAR(uint8, ANFCRL_VAR) bOption2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer2,
                                VAR(uint16, ANFCRL_VAR) wInBufferLength2,
                                VAR(uint8, ANFCRL_VAR) bInBufferBits2,
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer2,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits2
                                )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wByteIndexIn2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wByteIndexOut2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitPosition2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDiv2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bMod2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bParity2;

    /* Parameter check */
    if (((bOption2 != PH_TOOLS_PARITY_OPTION_EVEN2) && (bOption2 != PH_TOOLS_PARITY_OPTION_ODD2)) || (bInBufferBits2 > 7U))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    /* Parameter check */
    if (wInBufferLength2 == 0U)
    {
        /* Zero input length is simply passed through */
        if (bInBufferBits2 == 0U)
        {
            (*pOutBufferLength2) = 0;
            *pOutBufferBits2 = 0;
            return PH_ERR_SUCCESS2;
        }
        /* Invalid parameter */
        else
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
        }
    }

    /* Retrieve DIV and MOD */
    if (bInBufferBits2 == 0U)
    {
        wDiv2 = (uint16)(wInBufferLength2 / 9U);
        bMod2 = (uint8)(wInBufferLength2 % 9U);
    }
    else
    {
        wDiv2 = (uint16)((wInBufferLength2 - 1U) / 9U);
        bMod2 = (uint8)((wInBufferLength2 - 1U) % 9U);
    }

    /* Calculate number of output bytes */
    (*pOutBufferLength2) = (uint16)((wDiv2 << 3U) + bMod2);
    if (bMod2 > bInBufferBits2)
    {
        --(*pOutBufferLength2);
    }

    /* Calculate number of rest-bits of output */
    *pOutBufferBits2 = (uint8)((8U - (((8U + ((*pOutBufferLength2) % 8U)) - bInBufferBits2) % 8U)) % 8U);

    /* Increment output length in case of incomplete byte */
    if (*pOutBufferBits2 > 0U)
    {
        ++(*pOutBufferLength2);
    }

    /* Buffer overflow check*/
    if (wOutBufferSize2 < (*pOutBufferLength2))
    {
        (*pOutBufferLength2) = 0;
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_TOOLS2);
    }

    /* Prepare loop vars */
    wByteIndexIn2 = 0U;
    wByteIndexOut2 = 0U;
    bBitPosition2 = 7U;

    /* Do for each byte */
    while(wByteIndexOut2 < pOutBufferLength2[0])
    {
        /* Append source bits to output */
        pOutBuffer2[wByteIndexOut2] = (uint8)(pInBuffer2[wByteIndexIn2] >> (7U - bBitPosition2));

        /* If there is more data bits in the source byte append it to next data byte */
        if ((wByteIndexIn2 + 1U) < wInBufferLength2)
        {
            /* Append remaining bits to output */
            pOutBuffer2[wByteIndexOut2] |= (uint8)((uint16)pInBuffer2[wByteIndexIn2 + 1U] << (1U + bBitPosition2));

            /* Perform parity checking if this isn't an incomplete byte */
            if ((*pOutBufferBits2 == 0U)
                || ((wByteIndexOut2 + 1U) < (*pOutBufferLength2)))
            {
                bParity2 = phTools_CalcParity2(pOutBuffer2[wByteIndexOut2], bOption2);
                if ((pInBuffer2[wByteIndexIn2 + 1U] & (uint8)(1U << (7U - bBitPosition2))) != (bParity2 << (7U - bBitPosition2)))
                {
                    return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTEGRITY_ERROR2, PH_COMP_TOOLS2);
                }
            }
        }

        /* We have reached the 8th parity bit, the input buffer index is now one ahead */
        if (bBitPosition2 == 0U)
        {
            bBitPosition2 = 8;
            ++wByteIndexIn2;
        }
        ++wByteIndexOut2;
        ++wByteIndexIn2;
        --bBitPosition2;
    }

    /* Mask out invalid bits of last byte */
    if (*pOutBufferBits2 > 0U)
    {
        pOutBuffer2[(*pOutBufferLength2) - 1U] &= (uint8)(0xFFU >> (8U - *pOutBufferBits2));
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc52(
                                 VAR(uint8, ANFCRL_VAR) bOption2,
                                 VAR(uint8, ANFCRL_VAR) bPreset2,
                                 VAR(uint8, ANFCRL_VAR) bPolynom2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                                 VAR(uint16, ANFCRL_VAR) wDataLength2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2
                                 )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataIndex2 = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitIndex2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitMax2;

    if (0u != (bOption2 & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    *pCrc2 = bPreset2;

    if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_MSB_FIRST2))
    {
        /* Shift 5bit preset to 8bit (data) alignment */
        *pCrc2 <<= 3U;

        /* Shift 5bit polynomial to 8bit (data) alignment */
        bPolynom2 <<= 3U;
    }

    /* Loop through all data bytes */
    while (0U != wDataLength2)
    {
        /* XOR input data */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_BITWISE2))
        {
            if (wDataLength2 < 8U)
            {
                bBitMax2 = (uint8)wDataLength2;
                wDataLength2 = 0;
            }
            else
            {
                bBitMax2 = 8;
                wDataLength2 -= 8u;
            }
        }
        else
        {
            bBitMax2 = 8;
            /* Decrement DataLen */
            --wDataLength2;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_MSB_FIRST2))
        {
            *pCrc2 ^= pData2[wDataIndex2++] & (0xFFU << (8U - bBitMax2));

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0u != ((*pCrc2) & 0x80U))
                {
                    *pCrc2 = (uint8)(((*pCrc2) << 1U) ^ bPolynom2);
                }
                else
                {
                    *pCrc2 = (*pCrc2) << 1U;
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc2 ^= pData2[wDataIndex2++] & (0xFFU >> (8U - bBitMax2));

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0u != ((*pCrc2) & 0x01U))
                {
                    *pCrc2 = (uint8)(((*pCrc2) >> 1U) ^ bPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) >> 1U);
                }
            }
        }
    }

    if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_MSB_FIRST2))
    {
        /* Shift back for 5bit alignment */
        *pCrc2 >>= 3U;
    }

    /* Invert CRC if requested */
    if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED2))
    {
        *pCrc2 ^= 0x1FU;
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc82(
                                 VAR(uint8, ANFCRL_VAR) bOption2,
                                 VAR(uint8, ANFCRL_VAR) bPreset2,
                                 VAR(uint8, ANFCRL_VAR) bPolynom2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                                 VAR(uint16, ANFCRL_VAR) wDataLength2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2
                                 )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataIndex2 = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitIndex2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitMax2;

    if (0u != (bOption2 & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    *pCrc2 = bPreset2;

    /* Loop through all data bytes */
    while (0U != wDataLength2)
    {
        /* XOR input data */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_BITWISE2))
        {
            if (wDataLength2 < 8U)
            {
                bBitMax2 = (uint8)wDataLength2;
                wDataLength2 = 0;
            }
            else
            {
                bBitMax2 = 8;
                wDataLength2 -= 8u;
            }
        }
        else
        {
            bBitMax2 = 8;
            /* Decrement DataLen */
            --wDataLength2;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_MSB_FIRST2))
        {
            *pCrc2 ^= pData2[wDataIndex2++] & (0xFFU << (8U - bBitMax2));

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0U != ((*pCrc2) & 0x80U))
                {
                    *pCrc2 = (uint8)(((*pCrc2) << 1U) ^ bPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) << 1U);
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc2 ^= pData2[wDataIndex2++] & (0xFFU >> (8U - bBitMax2));

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0u != ((*pCrc2) & 0x01U))
                {
                    *pCrc2 = (uint8)(((*pCrc2) >> 1U) ^ bPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) >> 1U);
                }
            }
        }
    }

    /* Invert CRC if requested */
    if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED2))
    {
        *pCrc2 ^= 0xFFU;
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc162(
                                  VAR(uint8, ANFCRL_VAR) bOption2,
                                  VAR(uint16, ANFCRL_VAR) wPreset2,
                                  VAR(uint16, ANFCRL_VAR) wPolynom2,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                                  VAR(uint16, ANFCRL_VAR) wDataLength2,
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2
                                  )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataIndex2 = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitIndex2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitMax2;

    if (0u != (bOption2 & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    *pCrc2 = wPreset2;

    /* Loop through all data bytes */
    while (0U != wDataLength2)
    {
        /* XOR input data */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_BITWISE2))
        {
            if (wDataLength2 < 8U)
            {
                bBitMax2 = (uint8)wDataLength2;
                wDataLength2 = 0;
            }
            else
            {
                bBitMax2 = 8;
                wDataLength2 -= 8u;
            }
        }
        else
        {
            bBitMax2 = 8;
            /* Decrement DataLen */
            --wDataLength2;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_MSB_FIRST2))
        {
            *pCrc2 ^= (uint16)pData2[wDataIndex2++] << 8U;

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0u != ((*pCrc2) & 0x8000U))
                {
                    *pCrc2 = (uint16)(((*pCrc2) << 1U) ^ wPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) << 1U);
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc2 ^= pData2[wDataIndex2++];

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0U != ((*pCrc2) & 0x0001U))
                {
                    *pCrc2 = (uint16)(((*pCrc2) >> 1U) ^ wPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) >> 1U);
                }
            }
        }
    }

    /* Invert CRC if requested */
    if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED2))
    {
        *pCrc2 ^= 0xFFFFU;
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc322(
                                  VAR(uint8, ANFCRL_VAR) bOption2,
                                  VAR(uint32, ANFCRL_VAR) dwPreset2,
                                  VAR(uint32, ANFCRL_VAR) dwPolynom2,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                                  VAR(uint16, ANFCRL_VAR) wDataLength2,
                                  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2
                                  )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataIndex2 = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitIndex2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitMax2;

    if (0u != (bOption2 & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TOOLS2);
    }

    *pCrc2 = dwPreset2;

    /* Loop through all data bytes */
    while (0U != wDataLength2)
    {
        /* XOR input data */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_BITWISE2))
        {
            if (wDataLength2 < 8U)
            {
                bBitMax2 = (uint8)wDataLength2;
                wDataLength2 = 0;
            }
            else
            {
                bBitMax2 = 8;
                wDataLength2 -= 8u;
            }
        }
        else
        {
            bBitMax2 = 8;
            /* Decrement DataLen */
            --wDataLength2;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_MSB_FIRST2))
        {
            *pCrc2 ^= (uint32)pData2[wDataIndex2++] << 24U;

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0u != ((*pCrc2) & 0x80000000U))
                {
                    *pCrc2 = (uint32)(((*pCrc2) << 1U) ^ dwPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) << 1U);
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc2 ^= pData2[wDataIndex2++];

            for (bBitIndex2 = 0; bBitIndex2 < bBitMax2; ++bBitIndex2)
            {
                if (0u != ((*pCrc2) & 0x00000001U))
                {
                    *pCrc2 = (uint32)(((*pCrc2) >> 1U) ^ dwPolynom2);
                }
                else
                {
                    *pCrc2 = ((*pCrc2) >> 1U);
                }
            }
        }
    }

    /* Invert CRC if requested */
    if (0U != (bOption2 & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED2))
    {
        *pCrc2 ^= 0xFFFFFFFFU;
    }

    return PH_ERR_SUCCESS2;
}

static FUNC(uint8, ANFCRL_CODE) phTools_CalcParity2(
		VAR(uint8, ANFCRL_VAR) bDataByte2,
		VAR(uint8, ANFCRL_VAR) bOption2)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBit2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bParity2;

    if (bOption2 == PH_TOOLS_PARITY_OPTION_EVEN2)
    {
        bParity2 = 0x00;
    }
    else
    {
        bParity2 = 0x01;
    }

    for (bBit2 = 0; bBit2 < 8U; ++bBit2)
    {
        if (0U != (bDataByte2 & (uint8)(1U << bBit2)))
        {
            ++bParity2;
        }
    }
    return bParity2 & 0x01U;
}

static FUNC(void, ANFCRL_CODE) phTools_UpdateCrc_B2(
		VAR(uint8, ANFCRL_VAR) bCh2,
		P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pLpwCrc2)
{
    bCh2 = (bCh2^(uint8)((*pLpwCrc2)&0x00FFU));
    bCh2 = (bCh2 ^ (bCh2<<4U));
    *pLpwCrc2 = (*pLpwCrc2 >> 8U) ^ ((uint16)bCh2 << 8U) ^ ((uint16)bCh2 << 3U) ^ ((uint16)bCh2>>4U);
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_ComputeCrc_B2(
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                                VAR(uint32, ANFCRL_VAR) dwLength2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bChBlock2 = 0;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCrc2 = 0xFFFF;

    do
    {
        bChBlock2 = *pData2++;
        phTools_UpdateCrc_B2(bChBlock2, &wCrc2);
    } while (0u != (--dwLength2));

    wCrc2 = ~wCrc2;

    pCrc2[0] = (uint8) (wCrc2 & 0xFFU);
    pCrc2[1] = (uint8) ( (wCrc2>>8U) & 0xFFU);

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTools_GetVersion2(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProductVer2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pMajor2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMinor2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pPatch_Dev2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVersionString2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pVersionStringLen2)
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCopyLen2 = 0;
    CONST(char, ANFCRL_CONST) szNxpNfcRdLib_VER_FILEDESCRIPTION2[] = NxpNfcRdLib_VER_FILEDESCRIPTION2;

    PH_UNUSED_VARIABLE2(pProductVer2);

    *pMajor2 = NxpNfcRdLib_VER_MAJOR2;
    *pMinor2 = NxpNfcRdLib_VER_MINOR2;
    *pPatch_Dev2 = NxpNfcRdLib_VER_DEV2;

    wCopyLen2 = (uint16)(sizeof(szNxpNfcRdLib_VER_FILEDESCRIPTION2)/sizeof(szNxpNfcRdLib_VER_FILEDESCRIPTION2[0]));

    if(*pVersionStringLen2 < (wCopyLen2 - 1u))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_LENGTH_ERROR2, PH_COMP_TOOLS2);
    }
    else
    {
        wCopyLen2 = min_val2(wCopyLen2,(*pVersionStringLen2));

        phTools_memcpy2(pVersionString2, szNxpNfcRdLib_VER_FILEDESCRIPTION2, wCopyLen2);

        *pVersionStringLen2 = wCopyLen2 - 1u;
    }

    return PH_ERR_SUCCESS2;
}

FUNC(void, ANFCRL_CODE) phTools_memcpy2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) dest2,
    P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) src2,
    VAR(uint32, ANFCRL_VAR) num2)
{
   P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) csrc = src2;
   uint8 *cdest = (uint8 *)dest2;
   VAR(uint32, ANFCRL_VAR) i2 = 0;

   /* Copy contents of src2[] to dest2[] */
   for (i2=0; i2<num2; i2++)
   {
       cdest[i2] = csrc[i2];
   }
}

FUNC(uint32, ANFCRL_CODE) phTools_rand2(void) {
	random_next2 = (random_next2 * 1103515245U) + 12345U;
	return random_next2 & 0x7FFFU;
}

FUNC(void, ANFCRL_CODE) phTools_srand2(VAR(uint32, ANFCRL_VAR) seed2)
{
	random_next2 = seed2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
