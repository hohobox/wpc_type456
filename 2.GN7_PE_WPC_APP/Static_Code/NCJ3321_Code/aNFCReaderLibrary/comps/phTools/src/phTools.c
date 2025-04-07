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
*   @file    phTools.c
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

#include <phTools.h>
#include <ph_RefDefs.h>
#include <NxpNfcRdLib_Ver.h>
#include <phDriver.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTools.c
* @implements     DESIGN001, DESIGN002
*/
#define PHTOOLS_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHTOOLS_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHTOOLS_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHTOOLS_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHTOOLS_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHTOOLS_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHTOOLS_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phTools.h header file are of the same vendor */
#if (PHTOOLS_VENDOR_ID_C != PHTOOLS_VENDOR_ID)
    #error "phTools.c and phTools.h have different vendor ids"
#endif
/* Check if current file and phpalSli15693_Sw.h header file are of the same Autosar version */
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C    != PHTOOLS_AR_RELEASE_MAJOR_VERSION) || \
     (PHTOOLS_AR_RELEASE_MINOR_VERSION_C    != PHTOOLS_AR_RELEASE_MINOR_VERSION) || \
     (PHTOOLS_AR_RELEASE_REVISION_VERSION_C != PHTOOLS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phTools.c and phTools.h are different"
#endif
/* Check if current file and phTools.h header file are of the same Software version */
#if ((PHTOOLS_SW_MAJOR_VERSION_C != PHTOOLS_SW_MAJOR_VERSION) || \
     (PHTOOLS_SW_MINOR_VERSION_C != PHTOOLS_SW_MINOR_VERSION) || \
     (PHTOOLS_SW_PATCH_VERSION_C != PHTOOLS_SW_PATCH_VERSION))
    #error "Software Version Numbers of phTools.c and phTools.h are different"
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
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint32, ANFCRL_VAR) random_next = 1U;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static FUNC(uint8, ANFCRL_CODE) phTools_CalcParity(VAR(uint8, ANFCRL_VAR) bDataByte, VAR(uint8, ANFCRL_VAR) bOption);

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventCreate(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_PollFunc_t, ANFCRL_VAR) pPollFunc, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPollFuncParam)
{
	pDataParams->bEventState = PH_TOOLS_EVENT_IDLE;
	pDataParams->pEventPollFunc = pPollFunc;
	pDataParams->pEventPollParams = pPollFuncParam;
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventPend(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_EventOpt_t, ANFCRL_VAR) options, VAR(uint32, ANFCRL_VAR) timeToWait, VAR(phTools_EventBits_t, ANFCRL_VAR) FlagsToWait,
    P2VAR(phTools_EventBits_t, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags)
{
	VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;
	P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) eventHandle = &(pDataParams->wEventHandle);
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwElapsedTime = 0U;

	/*Polling for checking Event's condition*/
	pDataParams->pEventPollFunc(pDataParams->pEventPollParams);
	if((PH_ERR_SUCCESS != pDataParams->dEventStatus) &&
			(PH_STATUS_INPROCESS != pDataParams->dEventStatus))
	{
		status = pDataParams->dEventStatus;
		/* Reset data parameter values */
		pDataParams->dEventStatus = PH_ERR_SUCCESS;
		pDataParams->bEventState = PH_TOOLS_EVENT_IDLE;
		return PH_ADD_COMPCODE(status, PH_COMP_HAL);
	}
	else
	{
		/* Do nothing */
	}

	switch (pDataParams->bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:

			pDataParams->wTimeToWait = timeToWait;
			pDataParams->bEventState = PH_TOOLS_EVENT_PENDING;
			pDataParams->dEventStatus = PH_STATUS_INPROCESS;
			pDataParams->wEventTimeStart = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
			return PH_STATUS_INPROCESS;

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			if ((((options & E_EVENT_OPT_PEND_SET_ALL) != 0U) && (((*eventHandle) & FlagsToWait) == FlagsToWait))
					|| (((options & E_EVENT_OPT_PEND_SET_ALL) == 0U) && (((*eventHandle) & FlagsToWait) != 0U)))
			{
				pDataParams->dEventStatus = PH_ERR_SUCCESS;
			}
			else
			{
				/* Check whether infinite wait, if not check timer. */
				if (pDataParams->wTimeToWait != PH_TOOLS_EVENT_MAX_DELAY)
				{
					dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, pDataParams->wEventTimeStart);

					/* Check for timer overflow, abort if timer overflow happens */
					if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
					{
						pDataParams->dEventStatus = PH_ERR_ABORTED;
						status = pDataParams->dEventStatus;
						break;
					}
					else
					{
						/* Timer's Event */
						if (((uint64)pDataParams->wTimeToWait * 1000U) > (uint64)dwElapsedTime)
						{
							return PH_STATUS_INPROCESS;
						}
						else
						{
							pDataParams->dEventStatus = PH_ERR_IO_TIMEOUT;
						}
					}
				}
				/* Infinite wait */
				else
				{
					return PH_STATUS_INPROCESS;
				}
			}

			if (pCurrFlags != NULL)
			{
				*pCurrFlags = *eventHandle;
			}

			if ((options & E_EVENT_OPT_PEND_CLEAR_ON_EXIT) != 0u)
			{
				*eventHandle &= (~(FlagsToWait & (*eventHandle)));
			}
			status = pDataParams->dEventStatus;
			break;
	}

	pDataParams->bEventState = PH_TOOLS_EVENT_IDLE;
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventPost(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_EventOpt_t, ANFCRL_VAR) options, VAR(phTools_EventBits_t, ANFCRL_VAR) FlagsToPost,
  P2VAR(phTools_EventBits_t, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags)
{
  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) eventHandle = &(pDataParams->wEventHandle);
	PH_UNUSED_VARIABLE(options);
	/* Set the events. */
	*eventHandle |= FlagsToPost;

	if (pCurrFlags != NULL)
	{
		*pCurrFlags = *eventHandle;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventClear(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_EventOpt_t, ANFCRL_VAR) options, VAR(phTools_EventBits_t, ANFCRL_VAR) FlagsToClear,
  P2VAR(phTools_EventBits_t, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags)
{
  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) eventHandle = &(pDataParams->wEventHandle);
	PH_UNUSED_VARIABLE(options);

	if (pCurrFlags != NULL)
	{
		*pCurrFlags = *eventHandle;
	}

	*eventHandle &= (~FlagsToClear);

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_EncodeParity(
                                VAR(uint8, ANFCRL_VAR) bOption,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer,
                                VAR(uint16, ANFCRL_VAR) wInBufferLength,
                                VAR(uint8, ANFCRL_VAR) bInBufferBits,
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits
                                )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wByteIndexIn;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wByteIndexOut;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitPosition;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wInByteCount;

    /* Parameter check */
    if (((bOption != PH_TOOLS_PARITY_OPTION_EVEN) && (bOption != PH_TOOLS_PARITY_OPTION_ODD)) || (bInBufferBits > 7U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    /* Retrieve full input byte count */
    if (bInBufferBits == 0U)
    {
        wInByteCount = wInBufferLength;
    }
    else
    {
        wInByteCount = wInBufferLength - 1u;
    }

    /* Retrieve number of (additional) full bytes */
    (*pOutBufferLength) = (uint16)((uint16)(wInByteCount + bInBufferBits) >> 3U);

    /* Retrieve output bits */
    *pOutBufferBits = (uint8)((uint16)(wInByteCount + bInBufferBits) % 8U);

    /* Increment output length in case of incomplete byte */
    if (*pOutBufferBits > 0U)
    {
        ++(*pOutBufferLength);
    }

    /* Overflow check */
    if ((*pOutBufferLength) > (0xFFFFU - wInByteCount))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    /* Calculate number of output bytes */
    (*pOutBufferLength) = wInByteCount + (*pOutBufferLength);

    /* Buffer overflow check*/
    if (wOutBufferSize < (*pOutBufferLength))
    {
        (*pOutBufferLength) = 0;
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_TOOLS);
    }

    /* Prepare output buffer */
    pOutBuffer[0] = 0x00;

    /* Prepare loop vars */
    wByteIndexIn = 0;
    wByteIndexOut = 0;
    bBitPosition = 7;

    /* Do for each byte */
    for (; wByteIndexIn < wInBufferLength; ++wByteIndexIn )
    {
        /* Append source bits to output */
        pOutBuffer[wByteIndexOut] |= (uint8)(pInBuffer[wByteIndexIn] << (7U - bBitPosition));

        /* If there is more data bits in the source byte append it to next data byte */
        if ((wByteIndexOut + 1U) < (*pOutBufferLength))
        {
            if(bBitPosition == 7U)
            {
            pOutBuffer[wByteIndexOut + 1U]  = 0;
            }
            else
            {
            pOutBuffer[wByteIndexOut + 1U]  = (uint8)(pInBuffer[wByteIndexIn] >> (1u + bBitPosition));
            }

            /* Perform parity appending if this isn't an incomplete byte */
            if ((bInBufferBits == 0U) || ((wByteIndexIn + 1U) < wInBufferLength))
            {
                pOutBuffer[wByteIndexOut + 1U] |= (uint8)(phTools_CalcParity(pInBuffer[wByteIndexIn], bOption) << (7U - bBitPosition));
            }
        }

        /* We have reached the 8th parity bit, the output buffer index is now one ahead */
        if (bBitPosition == 0U)
        {
            if ((wByteIndexOut + 2U) < (*pOutBufferLength))
            {
                bBitPosition = 8;
                pOutBuffer[++wByteIndexOut + 1U] = 0x00;
            }
        }

        ++wByteIndexOut;
        --bBitPosition;
    }

    /* Mask out invalid bits of last byte */
    if (*pOutBufferBits > 0U)
    {
        pOutBuffer[(*pOutBufferLength) - 1U] &= (uint8)(0xFFU >> (8U - *pOutBufferBits));
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_DecodeParity(
                                VAR(uint8, ANFCRL_VAR) bOption,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer,
                                VAR(uint16, ANFCRL_VAR) wInBufferLength,
                                VAR(uint8, ANFCRL_VAR) bInBufferBits,
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits
                                )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wByteIndexIn;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wByteIndexOut;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitPosition;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDiv;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMod;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bParity;

    /* Parameter check */
    if (((bOption != PH_TOOLS_PARITY_OPTION_EVEN) && (bOption != PH_TOOLS_PARITY_OPTION_ODD)) || (bInBufferBits > 7U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    /* Parameter check */
    if (wInBufferLength == 0U)
    {
        /* Zero input length is simply passed through */
        if (bInBufferBits == 0U)
        {
            (*pOutBufferLength) = 0;
            *pOutBufferBits = 0;
            return PH_ERR_SUCCESS;
        }
        /* Invalid parameter */
        else
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
        }
    }

    /* Retrieve DIV and MOD */
    if (bInBufferBits == 0U)
    {
        wDiv = (uint16)(wInBufferLength / 9U);
        bMod = (uint8)(wInBufferLength % 9U);
    }
    else
    {
        wDiv = (uint16)((wInBufferLength - 1U) / 9U);
        bMod = (uint8)((wInBufferLength - 1U) % 9U);
    }

    /* Calculate number of output bytes */
    (*pOutBufferLength) = (uint16)((wDiv << 3U) + bMod);
    if (bMod > bInBufferBits)
    {
        --(*pOutBufferLength);
    }

    /* Calculate number of rest-bits of output */
    *pOutBufferBits = (uint8)((8U - (((8U + ((*pOutBufferLength) % 8U)) - bInBufferBits) % 8U)) % 8U);

    /* Increment output length in case of incomplete byte */
    if (*pOutBufferBits > 0U)
    {
        ++(*pOutBufferLength);
    }

    /* Buffer overflow check*/
    if (wOutBufferSize < (*pOutBufferLength))
    {
        (*pOutBufferLength) = 0;
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_TOOLS);
    }

    /* Prepare loop vars */
    wByteIndexIn = 0U;
    wByteIndexOut = 0U;
    bBitPosition = 7U;

    /* Do for each byte */
    while(wByteIndexOut < pOutBufferLength[0])
    {
        /* Append source bits to output */
        pOutBuffer[wByteIndexOut] = (uint8)(pInBuffer[wByteIndexIn] >> (7U - bBitPosition));

        /* If there is more data bits in the source byte append it to next data byte */
        if ((wByteIndexIn + 1U) < wInBufferLength)
        {
            /* Append remaining bits to output */
            pOutBuffer[wByteIndexOut] |= (uint8)((uint16)pInBuffer[wByteIndexIn + 1U] << (1U + bBitPosition));

            /* Perform parity checking if this isn't an incomplete byte */
            if ((*pOutBufferBits == 0U)
                || ((wByteIndexOut + 1U) < (*pOutBufferLength)))
            {
                bParity = phTools_CalcParity(pOutBuffer[wByteIndexOut], bOption);
                if ((pInBuffer[wByteIndexIn + 1U] & (uint8)(1U << (7U - bBitPosition))) != (bParity << (7U - bBitPosition)))
                {
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_TOOLS);
                }
            }
        }

        /* We have reached the 8th parity bit, the input buffer index is now one ahead */
        if (bBitPosition == 0U)
        {
            bBitPosition = 8;
            ++wByteIndexIn;
        }
        ++wByteIndexOut;
        ++wByteIndexIn;
        --bBitPosition;
    }

    /* Mask out invalid bits of last byte */
    if (*pOutBufferBits > 0U)
    {
        pOutBuffer[(*pOutBufferLength) - 1U] &= (uint8)(0xFFU >> (8U - *pOutBufferBits));
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc5(
                                 VAR(uint8, ANFCRL_VAR) bOption,
                                 VAR(uint8, ANFCRL_VAR) bPreset,
                                 VAR(uint8, ANFCRL_VAR) bPolynom,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                 VAR(uint16, ANFCRL_VAR) wDataLength,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc
                                 )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataIndex = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitIndex;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitMax;

    if (0u != (bOption & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    *pCrc = bPreset;

    if (0U != (bOption & PH_TOOLS_CRC_OPTION_MSB_FIRST))
    {
        /* Shift 5bit preset to 8bit (data) alignment */
        *pCrc <<= 3U;

        /* Shift 5bit polynomial to 8bit (data) alignment */
        bPolynom <<= 3U;
    }

    /* Loop through all data bytes */
    while (0U != wDataLength)
    {
        /* XOR input data */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_BITWISE))
        {
            if (wDataLength < 8U)
            {
                bBitMax = (uint8)wDataLength;
                wDataLength = 0;
            }
            else
            {
                bBitMax = 8;
                wDataLength -= 8u;
            }
        }
        else
        {
            bBitMax = 8;
            /* Decrement DataLen */
            --wDataLength;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_MSB_FIRST))
        {
            *pCrc ^= pData[wDataIndex++] & (0xFFU << (8U - bBitMax));

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0u != ((*pCrc) & 0x80U))
                {
                    *pCrc = (uint8)(((*pCrc) << 1U) ^ bPolynom);
                }
                else
                {
                    *pCrc = (*pCrc) << 1U;
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc ^= pData[wDataIndex++] & (0xFFU >> (8U - bBitMax));

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0u != ((*pCrc) & 0x01U))
                {
                    *pCrc = (uint8)(((*pCrc) >> 1U) ^ bPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) >> 1U);
                }
            }
        }
    }

    if (0U != (bOption & PH_TOOLS_CRC_OPTION_MSB_FIRST))
    {
        /* Shift back for 5bit alignment */
        *pCrc >>= 3U;
    }

    /* Invert CRC if requested */
    if (0U != (bOption & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED))
    {
        *pCrc ^= 0x1FU;
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc8(
                                 VAR(uint8, ANFCRL_VAR) bOption,
                                 VAR(uint8, ANFCRL_VAR) bPreset,
                                 VAR(uint8, ANFCRL_VAR) bPolynom,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                 VAR(uint16, ANFCRL_VAR) wDataLength,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc
                                 )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataIndex = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitIndex;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitMax;

    if (0u != (bOption & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    *pCrc = bPreset;

    /* Loop through all data bytes */
    while (0U != wDataLength)
    {
        /* XOR input data */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_BITWISE))
        {
            if (wDataLength < 8U)
            {
                bBitMax = (uint8)wDataLength;
                wDataLength = 0;
            }
            else
            {
                bBitMax = 8;
                wDataLength -= 8u;
            }
        }
        else
        {
            bBitMax = 8;
            /* Decrement DataLen */
            --wDataLength;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_MSB_FIRST))
        {
            *pCrc ^= pData[wDataIndex++] & (0xFFU << (8U - bBitMax));

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0U != ((*pCrc) & 0x80U))
                {
                    *pCrc = (uint8)(((*pCrc) << 1U) ^ bPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) << 1U);
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc ^= pData[wDataIndex++] & (0xFFU >> (8U - bBitMax));

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0u != ((*pCrc) & 0x01U))
                {
                    *pCrc = (uint8)(((*pCrc) >> 1U) ^ bPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) >> 1U);
                }
            }
        }
    }

    /* Invert CRC if requested */
    if (0U != (bOption & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED))
    {
        *pCrc ^= 0xFFU;
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc16(
                                  VAR(uint8, ANFCRL_VAR) bOption,
                                  VAR(uint16, ANFCRL_VAR) wPreset,
                                  VAR(uint16, ANFCRL_VAR) wPolynom,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                  VAR(uint16, ANFCRL_VAR) wDataLength,
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pCrc
                                  )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataIndex = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitIndex;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitMax;

    if (0u != (bOption & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    *pCrc = wPreset;

    /* Loop through all data bytes */
    while (0U != wDataLength)
    {
        /* XOR input data */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_BITWISE))
        {
            if (wDataLength < 8U)
            {
                bBitMax = (uint8)wDataLength;
                wDataLength = 0;
            }
            else
            {
                bBitMax = 8;
                wDataLength -= 8u;
            }
        }
        else
        {
            bBitMax = 8;
            /* Decrement DataLen */
            --wDataLength;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_MSB_FIRST))
        {
            *pCrc ^= (uint16)pData[wDataIndex++] << 8U;

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0u != ((*pCrc) & 0x8000U))
                {
                    *pCrc = (uint16)(((*pCrc) << 1U) ^ wPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) << 1U);
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc ^= pData[wDataIndex++];

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0U != ((*pCrc) & 0x0001U))
                {
                    *pCrc = (uint16)(((*pCrc) >> 1U) ^ wPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) >> 1U);
                }
            }
        }
    }

    /* Invert CRC if requested */
    if (0U != (bOption & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED))
    {
        *pCrc ^= 0xFFFFU;
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc32(
                                  VAR(uint8, ANFCRL_VAR) bOption,
                                  VAR(uint32, ANFCRL_VAR) dwPreset,
                                  VAR(uint32, ANFCRL_VAR) dwPolynom,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                  VAR(uint16, ANFCRL_VAR) wDataLength,
                                  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pCrc
                                  )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataIndex = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitIndex;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitMax;

    if (0u != (bOption & (uint8)~(uint8)PH_TOOLS_CRC_OPTION_MASK))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TOOLS);
    }

    *pCrc = dwPreset;

    /* Loop through all data bytes */
    while (0U != wDataLength)
    {
        /* XOR input data */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_BITWISE))
        {
            if (wDataLength < 8U)
            {
                bBitMax = (uint8)wDataLength;
                wDataLength = 0;
            }
            else
            {
                bBitMax = 8;
                wDataLength -= 8u;
            }
        }
        else
        {
            bBitMax = 8;
            /* Decrement DataLen */
            --wDataLength;
        }

        /* CRC polynomial (MSB first) */
        if (0U != (bOption & PH_TOOLS_CRC_OPTION_MSB_FIRST))
        {
            *pCrc ^= (uint32)pData[wDataIndex++] << 24U;

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0u != ((*pCrc) & 0x80000000U))
                {
                    *pCrc = (uint32)(((*pCrc) << 1U) ^ dwPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) << 1U);
                }
            }
        }
        /* CRC polynomial (LSB first) */
        else
        {
            *pCrc ^= pData[wDataIndex++];

            for (bBitIndex = 0; bBitIndex < bBitMax; ++bBitIndex)
            {
                if (0u != ((*pCrc) & 0x00000001U))
                {
                    *pCrc = (uint32)(((*pCrc) >> 1U) ^ dwPolynom);
                }
                else
                {
                    *pCrc = ((*pCrc) >> 1U);
                }
            }
        }
    }

    /* Invert CRC if requested */
    if (0U != (bOption & PH_TOOLS_CRC_OPTION_OUPUT_INVERTED))
    {
        *pCrc ^= 0xFFFFFFFFU;
    }

    return PH_ERR_SUCCESS;
}

static FUNC(uint8, ANFCRL_CODE) phTools_CalcParity(
		VAR(uint8, ANFCRL_VAR) bDataByte,
		VAR(uint8, ANFCRL_VAR) bOption)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBit;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bParity;

    if (bOption == PH_TOOLS_PARITY_OPTION_EVEN)
    {
        bParity = 0x00;
    }
    else
    {
        bParity = 0x01;
    }

    for (bBit = 0; bBit < 8U; ++bBit)
    {
        if (0U != (bDataByte & (uint8)(1U << bBit)))
        {
            ++bParity;
        }
    }
    return bParity & 0x01U;
}

static FUNC(void, ANFCRL_CODE) phTools_UpdateCrc_B(
		VAR(uint8, ANFCRL_VAR) bCh,
		P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pLpwCrc)
{
    bCh = (bCh^(uint8)((*pLpwCrc)&0x00FFU));
    bCh = (bCh ^ (bCh<<4U));
    *pLpwCrc = (*pLpwCrc >> 8U) ^ ((uint16)bCh << 8U) ^ ((uint16)bCh << 3U) ^ ((uint16)bCh>>4U);
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_ComputeCrc_B(
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                VAR(uint32, ANFCRL_VAR) dwLength,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bChBlock = 0;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrc = 0xFFFF;

    do
    {
        bChBlock = *pData++;
        phTools_UpdateCrc_B(bChBlock, &wCrc);
    } while (0u != (--dwLength));

    wCrc = ~wCrc;

    pCrc[0] = (uint8) (wCrc & 0xFFU);
    pCrc[1] = (uint8) ( (wCrc>>8U) & 0xFFU);

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTools_GetVersion(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProductVer,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pMajor,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMinor,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pPatch_Dev,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVersionString,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pVersionStringLen)
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCopyLen = 0;
    CONST(char, ANFCRL_CONST) szNxpNfcRdLib_VER_FILEDESCRIPTION[] = NxpNfcRdLib_VER_FILEDESCRIPTION;

    PH_UNUSED_VARIABLE(pProductVer);

    *pMajor = NxpNfcRdLib_VER_MAJOR;
    *pMinor = NxpNfcRdLib_VER_MINOR;
    *pPatch_Dev = NxpNfcRdLib_VER_DEV;

    wCopyLen = (uint16)(sizeof(szNxpNfcRdLib_VER_FILEDESCRIPTION)/sizeof(szNxpNfcRdLib_VER_FILEDESCRIPTION[0]));

    if(*pVersionStringLen < (wCopyLen - 1u))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_LENGTH_ERROR, PH_COMP_TOOLS);
    }
    else
    {
        wCopyLen = min_val(wCopyLen,(*pVersionStringLen));

        phTools_memcpy(pVersionString, szNxpNfcRdLib_VER_FILEDESCRIPTION, wCopyLen);

        *pVersionStringLen = wCopyLen - 1u;
    }

    return PH_ERR_SUCCESS;
}

FUNC(void, ANFCRL_CODE) phTools_memcpy(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) dest,
    P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) src,
    VAR(uint32, ANFCRL_VAR) num)
{
   P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) csrc = src;
   uint8 *cdest = (uint8 *)dest;
   VAR(uint32, ANFCRL_VAR) i = 0;

   /* Copy contents of src[] to dest[] */
   for (i=0; i<num; i++)
   {
       cdest[i] = csrc[i];
   }
}

FUNC(uint32, ANFCRL_CODE) phTools_rand(void) {
	random_next = (random_next * 1103515245U) + 12345U;
	return random_next & 0x7FFFU;
}

FUNC(void, ANFCRL_CODE) phTools_srand(VAR(uint32, ANFCRL_VAR) seed)
{
	random_next = seed;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
