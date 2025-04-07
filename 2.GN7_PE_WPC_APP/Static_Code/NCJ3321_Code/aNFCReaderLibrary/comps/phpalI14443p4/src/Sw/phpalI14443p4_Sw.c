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
*   @file    phpalI14443p4_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4 ISO/IEC 14443-4
*   @ingroup phpalProtocol
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

#include <ph_Status.h>
#include <phhalHw.h>
#include <phpalI14443p4.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHPAL_I14443P4_SW

#include "phpalI14443p4_Sw_Int.h"
#include "phpalI14443p4_Sw.h"
#include <phTools.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4_Sw.h header file are of the same vendor */
#if (PHPALI14443P4_SW_VENDOR_ID_C != PHPALI14443P4_SW_VENDOR_ID)
    #error "phpalI14443p4_Sw.c and phpalI14443p4_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4_Sw.c and phpalI14443p4_Sw.h are different"
#endif
/* Check if current file and phpalI14443p4_Sw.h header file are of the same Software version */
#if ((PHPALI14443P4_SW_SW_MAJOR_VERSION_C != PHPALI14443P4_SW_SW_MAJOR_VERSION) || \
     (PHPALI14443P4_SW_SW_MINOR_VERSION_C != PHPALI14443P4_SW_SW_MINOR_VERSION) || \
     (PHPALI14443P4_SW_SW_PATCH_VERSION_C != PHPALI14443P4_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4_Sw.c and phpalI14443p4_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4_SW
#define PH_CHECK_ERROR_UPDATE_STATE(status,stateVar,stateVal)         if ((uint16)((status) & 0xFFU) != PH_ERR_SUCCESS) {(stateVar) = (stateVal); return (status);}

#define PHPAL_I14443P4_SW_IS_BLOCKNR_EQUAL(bPcb)                        \
    (                                                                   \
        ((((bPcb) & PHPAL_I14443P4_SW_PCB_BLOCKNR) ^ pDataParams->bPcbBlockNum) == 0U) \
        ? 1u : 0u                                                       \
    )

#define PHPAL_I14443P4_SW_IS_ACK(bPcb)                                  \
    (                                                                   \
    (((bPcb) & PHPAL_I14443P4_SW_PCB_NAK) == PHPAL_I14443P4_SW_PCB_ACK) \
    ? 1u : 0u                                                             \
    )

#define PHPAL_I14443P4_SW_IS_CHAINING(bPcb)                                         \
    (                                                                               \
    (((bPcb) & PHPAL_I14443P4_SW_PCB_CHAINING) == PHPAL_I14443P4_SW_PCB_CHAINING)   \
    ? 1u : 0u                                                                         \
    )

#define PHPAL_I14443P4_SW_IS_WTX(bPcb)                                  \
    (                                                                   \
    (((bPcb) & PHPAL_I14443P4_SW_PCB_WTX) == PHPAL_I14443P4_SW_PCB_WTX) \
    ? 1u : 0u                                                             \
    )

#define PHPAL_I14443P4_SW_IS_DESELECT(bPcb)                                     \
    (                                                                           \
    (((bPcb) & PHPAL_I14443P4_SW_PCB_WTX) == PHPAL_I14443P4_SW_PCB_DESELECT)    \
    ? 1u : 0u                                                                     \
    )

#define PHPAL_I14443P4_SW_IS_I_BLOCK(bPcb)                                  \
    (                                                                       \
    (((bPcb) & PHPAL_I14443P4_SW_BLOCK_MASK) == PHPAL_I14443P4_SW_I_BLOCK)  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_IS_R_BLOCK(bPcb)                                  \
    (                                                                       \
    (((bPcb) & PHPAL_I14443P4_SW_BLOCK_MASK) == PHPAL_I14443P4_SW_R_BLOCK)  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_IS_S_BLOCK(bPcb)                                  \
    (                                                                       \
    (((bPcb) & PHPAL_I14443P4_SW_BLOCK_MASK) == PHPAL_I14443P4_SW_S_BLOCK)  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_IS_INVALID_BLOCK_STATUS(bStatus)                  \
    ((                                                                      \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT) ||                     \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR) ||                \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_FRAMING_ERROR) ||                  \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR))                  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_DESELECT_IS_INVALID_BLOCK_STATUS(bStatus)         \
    ((                                                                      \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT) ||                     \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR) ||                \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_FRAMING_ERROR) ||                  \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE) ||        \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_PROTOCOL_ERROR) ||                 \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR))                  \
    ? 1u : 0u                                                                 \
    )

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(I14443P4_EXCHANGE_StateType_t, ANFCRL_VAR) P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
static VAR(uint16, ANFCRL_VAR) wIsoFrameLenBackup = 0;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) bIsoFrameBackup[3];

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM bI14443p4_FsTable[13] = {16, 24, 32,
                                                                   40, 48, 64,
                                                                   96, 128, 256,
                                                                   512, 1024,
                                                                   2048, 4096};
#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_Init(
                                 P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                                 )
{
	if (sizeof(phpalI14443p4_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
	}
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pHalDataParams);

	P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
	/* reset state */
	pDataParams->eExchangeState = PHPAL_I14443P4_EXCHANGE_START;
	pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_IDLE;
	pDataParams->eDeselState = PHPAL_I14443P4_DESEL_IDLE;
	pDataParams->ePresCheckState = PHPAL_I14443P4_PRESCHECK_SEND;

	/* Init private data */
	pDataParams->wId = PH_COMP_PAL_ISO14443P4 | PHPAL_I14443P4_SW_ID;
	pDataParams->pHalDataParams = pHalDataParams;
	pDataParams->bOpeMode = RD_LIB_MODE_ISO;

	/* Reset protocol to defaults */
	return phpalI14443p4_Sw_ResetProtocol(pDataParams);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_SetProtocol(P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bCidEnable, VAR(uint8, ANFCRL_VAR) bCid, VAR(uint8, ANFCRL_VAR) bNadEnable, VAR(uint8, ANFCRL_VAR) bNad, VAR(uint8, ANFCRL_VAR) bFwi,
    VAR(uint8, ANFCRL_VAR) bFsdi, VAR(uint8, ANFCRL_VAR) bFsci)
{
	/* Rule A, ISO/IEC 14443-4:2008(E), init. Block number to zero */
	pDataParams->bPcbBlockNum = 0U;

	/* Check parameters */
	if ((bCid > PHPAL_I14443P4_CID_MAX) || (bFwi > PHPAL_I14443P4_FWI_MAX) || (bFsdi > PHPAL_I14443P4_FRAMESIZE_MAX) || (bFsci > PHPAL_I14443P4_FRAMESIZE_MAX))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4);
	}

	/* Apply parameters */
	pDataParams->bCidEnabled = bCidEnable;
	pDataParams->bCid = bCid;
	pDataParams->bNadEnabled = bNadEnable;
	pDataParams->bNad = bNad;
	pDataParams->bFwi = bFwi;
	pDataParams->bFsdi = bFsdi;
	pDataParams->bFsci = bFsci;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_ResetProtocol(P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	/* Set default state */
	pDataParams->bStateNow = PHPAL_I14443P4_SW_STATE_I_BLOCK_TX;

	/* Rule A, ISO/IEC 14443-4:2008(E), init. Block number to zero */
	pDataParams->bPcbBlockNum = 0U;

	/* Apply default parameters */
	pDataParams->bCidEnabled = 0x00U;
	pDataParams->bCid = 0x00U;
	pDataParams->bNadEnabled = 0x00U;
	pDataParams->bNad = 0x00U;
	pDataParams->bFwi = PHPAL_I14443P4_SW_FWI_DEFAULT;
	pDataParams->bFsdi = 0x00U;
	pDataParams->bFsci = PHPAL_I14443P4_SW_FSCI_DEFAULT;
	pDataParams->bMaxRetryCount = PHPAL_I14443P4_SW_MAX_RETRIES_DEFAULT;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_IsValidIBlock(
    VAR(uint8, ANFCRL_VAR) bCheckCid,
    VAR(uint8, ANFCRL_VAR) bCid,
    VAR(uint8, ANFCRL_VAR) bCheckNad,
    VAR(uint8, ANFCRL_VAR) bNad,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
    VAR(uint16, ANFCRL_VAR) wRxLength
    )
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wExpRxLength = 0U;

	/* Check RFU bits */
	if ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_I_BLOCK_RFU_MASK) != PHPAL_I14443P4_SW_I_BLOCK_RFU_BITS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength = 1U;

	/* Enable CID checking if necessary */
	if (0U != (bCheckCid))
	{
		wExpRxLength++;
	}

	/* Enable NAD checking if necessary */
	if (0U != (bCheckNad))
	{
		wExpRxLength++;
	}

	/* The frame should have the minimum frame length */
	if (wRxLength < wExpRxLength)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* CID presence check */
	if ((0u != bCheckCid) && ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING) > 0U) && ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS + 1U] & PHPAL_I14443P4_SW_CID_MASK) == bCid))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid) && (0u == (pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING)))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* NAD presence check */
	if ((0u != bCheckNad) && (0U != (pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING)) && (pRxBuffer[wExpRxLength - 1u] == bNad))
	{
		/* CHECK SUCCEEDED */
	}
	/* NAD absence check */
	else if ((bCheckNad == 0U) && ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING) == 0U))
	{
		/* CHECK SUCCEEDED */
	}
	/* NAD protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_IsValidRBlock(
	VAR(uint8, ANFCRL_VAR) bCheckCid,
	VAR(uint8, ANFCRL_VAR) bCid,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
    VAR(uint16, ANFCRL_VAR) wRxLength)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wExpRxLength = 0U;

	/* Check RFU bits */
	if ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_R_BLOCK_RFU_MASK) != PHPAL_I14443P4_SW_R_BLOCK_RFU_BITS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength = 1U;

	/* If CID is enabled, we always expect it */
	if (0U != (bCheckCid))
	{
		wExpRxLength++;
	}

	/* The frame should have the exact frame length */
	if (wRxLength != wExpRxLength)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* CID presence check */
	if ((0U != bCheckCid) && (0U != (pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING)) && ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS + 1U] & PHPAL_I14443P4_SW_CID_MASK) == bCid))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid) && (0u == (pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING)))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_IsValidSBlock(
    VAR(uint8, ANFCRL_VAR) bCheckCid,
    VAR(uint8, ANFCRL_VAR) bCid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
    VAR(uint16, ANFCRL_VAR) wRxLength
    )
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wExpRxLength = 0U;

	/* Check RFU bits, return with Protocol error if received PCB byte is not related to "Waiting time extension" */
	if ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_S_BLOCK_RFU_MASK) != PHPAL_I14443P4_SW_S_BLOCK_RFU_BITS)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength = 1U;

	/* If CID is enabled, we always expect it */
	if (0U != (bCheckCid))
	{
		wExpRxLength++;
	}

	/* If this is a WTX request, we expect an additional INF byte */
	if (0u != (PHPAL_I14443P4_SW_IS_WTX(pRxBuffer[PHPAL_I14443P4_SW_PCB_POS])))
	{
		wExpRxLength++;
	}

	/* The frame should have the exact frame length */
	if (wRxLength != wExpRxLength)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	/* CID presence check */
	if ((0u != bCheckCid) && (0U != (pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING)) && ((pRxBuffer[PHPAL_I14443P4_SW_PCB_POS + 1U] & PHPAL_I14443P4_SW_CID_MASK) == bCid))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid) && (0u == (pRxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING)))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_BuildIBlock(
	VAR(uint8, ANFCRL_VAR) bCidEnabled,
	VAR(uint8, ANFCRL_VAR) bCid,
	VAR(uint8, ANFCRL_VAR) bNadEnabled,
	VAR(uint8, ANFCRL_VAR) bNad,
	VAR(uint8, ANFCRL_VAR) bPcbBlockNum,
	VAR(uint8, ANFCRL_VAR) bChaining,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength)
{
	/* I-Block PCB */
	pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] = PHPAL_I14443P4_SW_I_BLOCK | PHPAL_I14443P4_SW_I_BLOCK_RFU_BITS | bPcbBlockNum;
	*pTxLength = 1U;

	/* Check if chaining is necessary */
	if (0U != (bChaining))
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_CHAINING;
	}

	/* Append CID if necessary */
	if (0U != (bCidEnabled))
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_CID_FOLLOWING;
		pTxBuffer[(*pTxLength)++] = bCid;
	}

	/* Append NAD if necessary */
	if (0U != (bNadEnabled))
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING;
		pTxBuffer[(*pTxLength)++] = bNad;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_BuildRBlock(
	VAR(uint8, ANFCRL_VAR) bCidEnabled,
	VAR(uint8, ANFCRL_VAR) bCid,
	VAR(uint8, ANFCRL_VAR) bPcbBlockNum,
	VAR(uint8, ANFCRL_VAR) bIsAck,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength)
{
	/* R(ACK) PCB */
	pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] = PHPAL_I14443P4_SW_R_BLOCK | PHPAL_I14443P4_SW_R_BLOCK_RFU_BITS | bPcbBlockNum;
	*pTxLength = 1U;

	/* Switch to R(NAK) if necessary */
	if (0U == (bIsAck))
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_NAK;
	}

	/* Append CID if supported */
	if (bCidEnabled != 0U)
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_CID_FOLLOWING;
		pTxBuffer[(*pTxLength)++] = bCid;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_BuildSBlock(
	VAR(uint8, ANFCRL_VAR) bCidEnabled,
	VAR(uint8, ANFCRL_VAR) bCid,
	VAR(uint8, ANFCRL_VAR) bIsWtx,
	VAR(uint8, ANFCRL_VAR) bWtxm,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength)
{
	/* S-Block PCB */
	pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] = PHPAL_I14443P4_SW_S_BLOCK | PHPAL_I14443P4_SW_S_BLOCK_RFU_BITS;
	*pTxLength = 1U;

	/* Append CID if supported */
	if (bCidEnabled != 0U)
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_CID_FOLLOWING;
		pTxBuffer[(*pTxLength)++] = bCid;
	}

	/* By default, PCB byte(bit 5 and 6) is configured to DESELECT command.
	 * Configure PCB byte to WTX(instead of DESELECT) and append WTXM based on bIsWtx input value.
	 */
	if (0U != (bIsWtx))
	{
		pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] |= PHPAL_I14443P4_SW_PCB_WTX;
		pTxBuffer[(*pTxLength)++] = bWtxm;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_SetConfig(P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig,
    VAR(uint16, ANFCRL_VAR) wValue)
{
	switch (wConfig)
	{
	case PHPAL_I14443P4_CONFIG_OPE_MODE:
	{
		pDataParams->bOpeMode = (uint8) wValue;
		break;
	}
	case PHPAL_I14443P4_CONFIG_BLOCKNO:
	{
		if (wValue == 0U)
		{
			pDataParams->bPcbBlockNum = 0U;
		}
		else
		{
			pDataParams->bPcbBlockNum = 1U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_CID:
	{
		if (0U != (wValue & 0xFF00U))
		{
			if ((wValue & 0x00FFU) > PHPAL_I14443P4_CID_MAX)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4);
			}
			pDataParams->bCidEnabled = 1;
			pDataParams->bCid = (uint8) (wValue);
		}
		else
		{
			pDataParams->bCidEnabled = 0U;
			pDataParams->bCid = 0U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_NAD:
	{
		if (0U != (wValue & 0xFF00U))
		{
			pDataParams->bNadEnabled = 1U;
			pDataParams->bNad = (uint8) (wValue);
		}
		else
		{
			pDataParams->bNadEnabled = 0U;
			pDataParams->bNad = 0U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_FWI:
	{
		if (wValue > PHPAL_I14443P4_FWI_MAX)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4);
		}
		pDataParams->bFwi = (uint8) (wValue);
		break;
	}
	case PHPAL_I14443P4_CONFIG_FSI:
	{
		if (((wValue >> 8U) > PHPAL_I14443P4_FRAMESIZE_MAX) || ((wValue & 0xFFU) > PHPAL_I14443P4_FRAMESIZE_MAX))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4);
		}

		pDataParams->bFsdi = (uint8) (wValue >> 8U);
		pDataParams->bFsci = (uint8) (wValue);
		break;
	}
	case PHPAL_I14443P4_CONFIG_MAXRETRYCOUNT:
	{
		pDataParams->bMaxRetryCount = (uint8) (wValue);
		break;
	}
	default:
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P4);
	}
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_GetConfig(P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
	switch (wConfig)
	{
	case PHPAL_I14443P4_CONFIG_BLOCKNO:
	{
		if (pDataParams->bPcbBlockNum == 0U)
		{
			*pValue = 0U;
		}
		else
		{
			*pValue = 1U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_CID:
	{
		if (0U != (pDataParams->bCidEnabled))
		{
			*pValue = (uint16) (0x0100u | pDataParams->bCid);
		}
		else
		{
			*pValue = (uint16) (pDataParams->bCid);
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_NAD:
	{
		if (0U != (pDataParams->bNadEnabled))
		{
			*pValue = (uint16) (0x0100u | pDataParams->bNad);
		}
		else
		{
			*pValue = (uint16) (pDataParams->bNad);
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_FWI:
	{
		*pValue = (uint16) pDataParams->bFwi;
		break;
	}
	case PHPAL_I14443P4_CONFIG_FSI:
	{
		*pValue = (uint16) ((uint16) (pDataParams->bFsdi) << 8U);
		*pValue |= (uint16) (pDataParams->bFsci);
		break;
	}
	case PHPAL_I14443P4_CONFIG_MAXRETRYCOUNT:
	{
		*pValue = (uint16) pDataParams->bMaxRetryCount;
		break;
	}
	default:
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P4);
	}
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_Exchange(
                                     P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wOption,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                                     VAR(uint16, ANFCRL_VAR) wTxLength,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                                     )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBufferOverflow = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOptionBackUp = 0U;

	/* Used to build I/R/S block frames */
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsoFrame[3] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUseNad = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bForceSend = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRxOverlapped[3] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIsoFrameLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxOverlappedLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxStartPos = 0U;

	/* Used for Transmission */
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferSize = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxBufferSize = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxBufferLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wInfLength = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wMaxPcdFrameSize = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wMaxCardFrameSize = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wPcb = 0u;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRetryCountRetransmit = 0U;

	/* For non-blocking implementation */
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpState = 0U;

	if ((ppRxBuffer == NULL) || (pRxLength == NULL))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4);
	}

	/* Option parameter check */
	if (0u != (wOption &  (uint16_t)~(uint16_t)
		(
		PH_EXCHANGE_BUFFERED_BIT | PH_EXCHANGE_LEAVE_BUFFER_BIT |
		PH_EXCHANGE_TXCHAINING | PH_EXCHANGE_RXCHAINING | PH_EXCHANGE_RXCHAINING_BUFSIZE
		)))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4);
	}

	switch (P4_Exchange_State)
	{
	case PHPAL_I14443P4_EXCHANGE_START:
		bBackUpState = 0U;
		wOptionBackUp = wOption;
		/* No break */
	case PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX:
		if (P4_Exchange_State == PHPAL_I14443P4_EXCHANGE_START)
		{
			I14443P4_LOG("--- EXCHANGE ISODEP START --\r\n");

			pDataParams->pTmpRxBuff = *ppRxBuffer;
			wIsoFrameLenBackup = 0;
			/* Retrieve HAL buffer sizes */
			statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE, &wRxBufferSize);
			PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
			statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_BUFSIZE, &wTxBufferSize);
			PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);

			/* Retrieve maximum frame sizes */
			wMaxPcdFrameSize = bI14443p4_FsTable[pDataParams->bFsdi] - (uint16) 2U;
			wMaxCardFrameSize = bI14443p4_FsTable[pDataParams->bFsci] - (uint16) 2U;

			/* R(ACK) transmission in case of Rx-Chaining */
			if (((wOption & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_RXCHAINING) || ((wOption & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_RXCHAINING_BUFSIZE))
			{
				pDataParams->bStateNow = PHPAL_I14443P4_SW_STATE_I_BLOCK_RX | PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
			}
			/* I-Block transmission */
			else
			{
				/* Reset to default state if not in Tx-Mode */
				if ((pDataParams->bStateNow & PH_EXCHANGE_MODE_MASK) != PHPAL_I14443P4_SW_STATE_I_BLOCK_TX)
				{
					pDataParams->bStateNow = PHPAL_I14443P4_SW_STATE_I_BLOCK_TX;
				}
			}

			P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX;
			/* Reset receive length */
			*pRxLength = 0;
			pDataParams->wTmpRxLen = 0;

			/* Reset RetryCount */
			bRetryCountRetransmit = 0U;

			/* Reset BufferOverflow flag */
			bBufferOverflow = 0U;
			pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_IDLE;
			pDataParams->wTmpTxLen = wTxLength;
			pDataParams->pTmpTxBuff = pTxBuffer;
		}
		/* ******************************** */
		/*     I-BLOCK TRANSMISSION LOOP    */
		/* ******************************** */
		switch (pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_MASK)
		{
			case PHPAL_I14443P4_SW_STATE_I_BLOCK_TX:
				if(0U == bBackUpState)
				{
					/* Reset Preloaded bytes and ForceSend */
					wTxBufferLen = 0U;
					bForceSend = 0U;

					/* Retrieve Number of preloaded bytes */
					if (0U != (wOption & PH_EXCHANGE_LEAVE_BUFFER_BIT))
					{
						statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_LENGTH, &wTxBufferLen);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
					}

					/* Set initial INF length to (remaining) input data length */
					wInfLength = pDataParams->wTmpTxLen;

					/* Frame has already been preloaded -> IsoFrameLen is zero */
					if (wTxBufferLen > 0U)
					{
						/* do not generate the iso frame */
						wIsoFrameLen = 0;
					}
					/* Else evaluate IsoFrameLen*/
					else
					{
						/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
						if ((0U == ((pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_CHAINING_BIT))))
						{
							bUseNad = pDataParams->bNadEnabled;
						}
						else
						{
							bUseNad = 0U;
						}

						/* Evaluate frame overhead */
						wIsoFrameLen = 1U;
						if (0U != (bUseNad))
						{
							++wIsoFrameLen;
						}
						if (0U != (pDataParams->bCidEnabled))
						{
							++wIsoFrameLen;
						}
					}

					/* Check if chaining is intended or not */
					if ((wOption & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_TXCHAINING)
					{
						pDataParams->bStateNow |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
					}
					else
					{
						pDataParams->bStateNow &= (uint8) ~(uint8) PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
					}

					/* Force frame exchange if
					 a) the maximum frame size of the card has been reached;
					 */
					if ((wTxBufferLen + wIsoFrameLen + wInfLength) > wMaxCardFrameSize)
					{
						/* force frame exchange */
						bForceSend = 1;

						/* force chaining */
						pDataParams->bStateNow |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT;

						/* limit number of bytes to send */
						wInfLength = wMaxCardFrameSize - wTxBufferLen - wIsoFrameLen;
					}

					/* Force frame exchange if
					 b) the TxBuffer is full;
					 */
					if ((0U != ((wOption & PH_EXCHANGE_BUFFERED_BIT))) && ((wTxBufferLen + wIsoFrameLen + wInfLength) >= wTxBufferSize))
					{
						/* force frame exchange */
						bForceSend = 1;

						/* force chaining */
						pDataParams->bStateNow |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
					}

					/* Generate / Buffer ISO frame */
					if (wIsoFrameLen > 0U)
					{
						/* Generate I-Block frame header */
						statusTmp = phpalI14443p4_Sw_BuildIBlock(pDataParams->bCidEnabled, pDataParams->bCid, bUseNad, pDataParams->bNad, pDataParams->bPcbBlockNum,
								(0U != (pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_CHAINING_BIT)) ? 1U : 0U, bIsoFrame, &wIsoFrameLen);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
						bBackUpState = 1U;
					}
					else
					{
#ifdef NXPBUILD__PH_LOG_EX
						I14443P4_LOG_BUF(">>> I-BLOCK: ", bIsoFrame, (uint8 )wIsoFrameLen);
						if (wInfLength > 0U)
						{
							I14443P4_LOG_BUF(">>> I-DATA: ", pDataParams->pTmpTxBuff, (uint8 )wInfLength);
						}
#endif
						bBackUpState = 2U;
					}
				}

				if(1U == bBackUpState)
				{
					/* Write Frame to HAL TxBuffer but do not perform Exchange */
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_BUFFER_FIRST, bIsoFrame, wIsoFrameLen, NULL, NULL));
					PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);

					/* Retain the preloaded bytes from now on */
					wOption |= PH_EXCHANGE_LEAVE_BUFFER_BIT;
					wOptionBackUp = wOption;
#ifdef NXPBUILD__PH_LOG_EX
					I14443P4_LOG_BUF(">>> I-BLOCK: ", bIsoFrame, (uint8 )wIsoFrameLen);
					if (wInfLength > 0U)
					{
						I14443P4_LOG_BUF(">>> I-DATA: ", pDataParams->pTmpTxBuff, (uint8 )wInfLength);
					}
#endif
					bBackUpState = 2U;
				}

				if(2U == bBackUpState)
				{
					/* Tx-Buffering mode (and no forced exchange) */
					if ((0U == bForceSend) && (0U != (wOptionBackUp & PH_EXCHANGE_BUFFERED_BIT)))
					{
						/* Preload the data into the TxBuffer */
						PH_CHECK_INPROCESS_FCT(statusTmp,
								phhalHw_Exchange(pDataParams->pHalDataParams, (wOptionBackUp & (uint16)~(uint16)PH_EXCHANGE_MODE_MASK), pDataParams->pTmpTxBuff, wInfLength, NULL, NULL));
						I14443P4_LOG("...\r\n");
						bBackUpState = 0U;
						P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
						return statusTmp;
					}

					bBackUpState = 0U;
					/* Content has been buffered before */
					if (wTxBufferLen > 0U)
					{
						/* retrieve PCB byte */
						statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_OFFSET, 0x00);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
						statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, &wPcb);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);

						/* Preloaded Data or ForceSend -> Modify PCB byte if necessary */
						if ((0U != bForceSend) || ((wOptionBackUp & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_TXCHAINING))
						{
							/* modify PCB byte */
							wPcb |= PHPAL_I14443P4_SW_PCB_CHAINING;
							statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, wPcb);
							PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
						}
					}
				}
				break;

			case PHPAL_I14443P4_SW_STATE_I_BLOCK_RX:
				if(0U == bBackUpState)
				{
					/* Build R(ACK) frame */
					statusTmp = phpalI14443p4_Sw_BuildRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pDataParams->bPcbBlockNum, 1, bIsoFrame, &wIsoFrameLen);
					PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
					bBackUpState = 1U;
					return PH_STATUS_INPROCESS;
				}

				if(1U == bBackUpState)
				{
					/* Write Frame to HAL TxBuffer but do not perform Exchange */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_BUFFERED_BIT, bIsoFrame, wIsoFrameLen, NULL, NULL));
					I14443P4_LOG_BUF(">>> IsoFrame: ", bIsoFrame, (uint8)wIsoFrameLen);
					bBackUpState = 0U;
					PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);

					/* Retain the preloaded bytes from now on */
					wOption |= PH_EXCHANGE_LEAVE_BUFFER_BIT;
					wOptionBackUp = wOption;

					/* do not append any data */
					wInfLength = 0;
				}
				break;
				/* Should NEVER happen! */
			default:
				P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P4);
		}
		P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_ISO_HANDLING;
		return PH_STATUS_INPROCESS;
		/* No break */
	case PHPAL_I14443P4_EXCHANGE_ISO_HANDLING:
		/* Perform Exchange using complete ISO handling */
		if(wIsoFrameLenBackup > 0U)
		{
			/* Continue ISO handling loop */
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4_Sw_IsoHandling(
				pDataParams,
				PH_EXCHANGE_DEFAULT,
				bRetryCountRetransmit,
				bIsoFrameBackup,
				wIsoFrameLenBackup,
				&pDataParams->pTmpRxBuff,
				&pDataParams->wTmpRxLen));
		}
		else
		{
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4_Sw_IsoHandling(
				pDataParams,
				wOptionBackUp & (uint16_t)~(uint16_t)PH_EXCHANGE_BUFFERED_BIT,
				bRetryCountRetransmit,
				pDataParams->pTmpTxBuff,
				wInfLength,
				&pDataParams->pTmpRxBuff,
				&pDataParams->wTmpRxLen));
		}
		wOptionBackUp = 0U;
		*ppRxBuffer = pDataParams->pTmpRxBuff;
		*pRxLength = pDataParams->wTmpRxLen;
		/* Complete chaining if buffer is full */
		if (((status & PH_ERR_MASK) == PH_ERR_BUFFER_OVERFLOW) &&
			((wOption & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_RXCHAINING_BUFSIZE))
		{
			/* Indicate Buffer Overflow */
			bBufferOverflow = 1;

			/* Toggle block number */
			pDataParams->bPcbBlockNum ^= PHPAL_I14443P4_SW_PCB_BLOCKNR;
		}
		/* Else bail out on error */
		else
		{
			PH_CHECK_ERROR_UPDATE_STATE(status, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
		}

		/* Re-transmission in progress */
		if (0U != (pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT))
		{
			/* Increment re-transmit RetryCount */
			++bRetryCountRetransmit;

			/* Restore internal TxBuffer. */
			/* Necessary in case RxBuffer and TxBuffer are the same. */
			if (wTxBufferLen > 0U)
			{
				/* restore PCB byte */
				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_OFFSET, 0x00));
				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, wPcb));

				/* restore TxBufferLen */
				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXBUFFER_LENGTH,
					wTxBufferLen));
			}

			/* Clear re-transmission bit */
			pDataParams->bStateNow &= (uint8_t)~(uint8_t)PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT;
		}
		/* No re-transmission in progress */
		else
		{
			/* Reset re-transmit RetryCount */
			bRetryCountRetransmit = 0;

			/* Chaining is active */
			if (pDataParams->bStateNow == (PHPAL_I14443P4_SW_STATE_I_BLOCK_TX | PHPAL_I14443P4_SW_STATE_CHAINING_BIT))
			{
				/* Bytes to send cannot be less than sent bytes */
				if (pDataParams->wTmpTxLen < wInfLength)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P4);
				}

				/* Remove sent bytes from TxBuffer */
				pDataParams->pTmpTxBuff = &pDataParams->pTmpTxBuff[wInfLength];

				/* below if condition is added to make QAC compliant  */
				if(pDataParams->wTmpTxLen > 0U)
				{
					pDataParams->wTmpTxLen = pDataParams->wTmpTxLen - wInfLength;
				}
			}
			else
			{
				/* Do nothing */
			}

			/* Buffered / TxChaining mode -> finished after sending */
			if ((pDataParams->wTmpTxLen == 0U) &&
				(
				((wOption & PH_EXCHANGE_BUFFERED_BIT) > 0U) ||
				((wOption & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_TXCHAINING)
				))
			{
				*ppRxBuffer = pDataParams->pTmpRxBuff;
				*pRxLength = pDataParams->wTmpRxLen;
				status = PH_ERR_SUCCESS;
				break;
			}
			else
			{
				/* Do nothing */
			}
		}
		if((pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_MASK) != PHPAL_I14443P4_SW_STATE_I_BLOCK_RX)
		{
			P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX;
			/* Reset Preloaded bytes and ForceSend */
			wTxBufferLen = 0U;
			bForceSend = 0U;
		}
		else
		{
			P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX;
			/* Overlap PCB */
			wRxOverlappedLen = 1;

			/* Overlap CID */
			if (0u != ((pDataParams->pTmpRxBuff)[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING))
			{
				wRxOverlappedLen++;
			}

			/* Overlap NAD */
			if (0u != ((pDataParams->pTmpRxBuff)[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING))
			{
				wRxOverlappedLen++;
			}

			/* Reset RxStartPos */
			wRxStartPos = 0;
		}
		return PH_STATUS_INPROCESS;
	case PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX:
		if(0U == bBackUpState)
		{
			/* ******************************** */
			/*      I-BLOCK RECEPTION LOOP      */
			/* ******************************** */
			/* Only allow receive state at this point */
			if ((pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_MASK) != PHPAL_I14443P4_SW_STATE_I_BLOCK_RX)
			{
				P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P4);
			}

			/* Rule 2, ISO/IEC 14443-4:2008(E), PICC chaining */
			if (0U != (pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_CHAINING_BIT))
			{
				/* Skip overlapping / SUCCESS_CHAINING checks in case of BufferOverflow */
				if (0U == (bBufferOverflow))
				{
					/* This is first chained response */
					if (wRxStartPos == 0U)
					{
						/* Special NAD chaining handling */
						/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
						if (0U != (pDataParams->bNadEnabled))
						{
							--wRxOverlappedLen;
						}
					}

					/* Backup overlapped bytes */
					(void) phTools_memcpy(bRxOverlapped, &(pDataParams->pTmpRxBuff)[(pDataParams->wTmpRxLen - wRxOverlappedLen)], wRxOverlappedLen);

					/* Calculate RxBuffer Start Position */
					wRxStartPos = pDataParams->wTmpRxLen - wRxOverlappedLen;

					/* Skip SUCCESS_CHAINING check for RXCHAINING_BUFSIZE mode */
					if ((wOption & PH_EXCHANGE_MODE_MASK) != PH_EXCHANGE_RXCHAINING_BUFSIZE)
					{
						/* Return with chaining status if the next chain may not fit into our buffer */
						if ((pDataParams->wTmpRxLen + wMaxPcdFrameSize) > wRxBufferSize)
						{
							/* Adjust RxBuffer position */
							pDataParams->pTmpRxBuff = &(pDataParams->pTmpRxBuff)[wRxOverlappedLen];
							pDataParams->wTmpRxLen = (pDataParams->wTmpRxLen) - wRxOverlappedLen;

							P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
							return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_PAL_ISO14443P4); /* original: PH_ERR_SUCCESS_CHAINING */
						}
					}
				}

				/* Set RxBuffer Start Position */
				statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, wRxStartPos);
				PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);

				/* Prepare R(ACK) frame */
				statusTmp = phpalI14443p4_Sw_BuildRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pDataParams->bPcbBlockNum, 1, bIsoFrame, &wIsoFrameLen);
				PH_CHECK_ERROR_UPDATE_STATE(statusTmp, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);
				bBackUpState = 1U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				bBackUpState = 2U;
				return PH_STATUS_INPROCESS;
			}
		}
		else if(1U == bBackUpState)
		{
			/* Perform Exchange using complete ISO handling */
			if(wIsoFrameLenBackup > 0U)
			{
				/* Continue ISO handling loop */
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4_Sw_IsoHandling(
						pDataParams,
						PH_EXCHANGE_DEFAULT,
						bRetryCountRetransmit,
						bIsoFrameBackup,
						wIsoFrameLenBackup,
						&pDataParams->pTmpRxBuff,
						&pDataParams->wTmpRxLen));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4_Sw_IsoHandling(
						pDataParams,
						PH_EXCHANGE_DEFAULT,
						bRetryCountRetransmit,
						bIsoFrame,
						wIsoFrameLen,
						&pDataParams->pTmpRxBuff,
						&pDataParams->wTmpRxLen));
			}
			*ppRxBuffer = pDataParams->pTmpRxBuff;
			*pRxLength = pDataParams->wTmpRxLen;
			/* Complete chaining if buffer is full */
			if (((status & PH_ERR_MASK) == PH_ERR_BUFFER_OVERFLOW) &&
				((wOption & PH_EXCHANGE_MODE_MASK) == PH_EXCHANGE_RXCHAINING_BUFSIZE))
			{
				/* Reset wRxStartPos */
				wRxStartPos = 0;

				/* Indicate Buffer Overflow */
				bBufferOverflow = 1;

				/* Toggle block number */
				pDataParams->bPcbBlockNum ^= PHPAL_I14443P4_SW_PCB_BLOCKNR;
			}
			/* Default behaviour */
			else
			{
				/* In case of buffer overflow error from HAL, reset the HAL Rx Buffer Start position */
				if ((pDataParams->bOpeMode != RD_LIB_MODE_ISO) && ((status & PH_ERR_MASK) == PH_ERR_BUFFER_OVERFLOW))
				{
					PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0));
				}
				/* Bail out on error */
				PH_CHECK_ERROR_UPDATE_STATE(status, P4_Exchange_State, PHPAL_I14443P4_EXCHANGE_START);

				/* Restore overlapped INF bytes */
				(void)memcpy(&(*ppRxBuffer)[wRxStartPos], bRxOverlapped, wRxOverlappedLen); /* PRQA S 3354 */
				bBackUpState = 0U;
			}
		}
		/* No chaining -> reception finished */
		else if(2U == bBackUpState)
		{
			/* Return data */
			if (0U == (bBufferOverflow))
			{
				/* Special NAD chaining handling */
				/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
				if ((wRxStartPos > 0U) && (pDataParams->bNadEnabled > 0U))
				{
					++wRxOverlappedLen;
				}

				/* Do not return protocol bytes, advance to INF field */
				pDataParams->pTmpRxBuff = &(pDataParams->pTmpRxBuff[wRxOverlappedLen]);
				pDataParams->wTmpRxLen = pDataParams->wTmpRxLen - wRxOverlappedLen;
				/* Reception successful */

				*ppRxBuffer = pDataParams->pTmpRxBuff;
				*pRxLength = pDataParams->wTmpRxLen;
				status = PH_ERR_SUCCESS;
			}
			/* do not return any data in case of Buffer Overflow */
			else
			{
				*pRxLength = 0U;
				pDataParams->wTmpRxLen = 0;
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_PAL_ISO14443P4);
			}

			/* Reception finished */
			pDataParams->bStateNow = PHPAL_I14443P4_SW_STATE_FINISHED;
			P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
			bBackUpState = 0U;
		}
		else
		{
			/* Should never happen */
			status = PH_ERR_INTERNAL_ERROR;
			break;
		}

		if(pDataParams->bStateNow != PHPAL_I14443P4_SW_STATE_FINISHED)
		{
			P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX;
			return PH_STATUS_INPROCESS;
		}
		else
		{
			break;
		}
	}
    /* Dereference of NULL pointer should be avoided. */
    if ((status == PH_ERR_SUCCESS) && (*ppRxBuffer == NULL))
    {
        P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
        return PH_ERR_INTERNAL_ERROR;
    }
	P4_Exchange_State = PHPAL_I14443P4_EXCHANGE_START;
	bBackUpState = 0U;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_IsoHandling(
                                        P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint16, ANFCRL_VAR) wOption,
                                        VAR(uint8, ANFCRL_VAR) bRetryCount,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                                        VAR(uint16, ANFCRL_VAR) wTxLength,
                                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                                        )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bInvalidBlock = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCheckNad;
    static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusBkUp = PH_ERR_SUCCESS;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferStartPos = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTimeout;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTimeoutMax = PHPAL_I14443P4_SW_FWT_MAX_US;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bResponseReceived = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bWtxm = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTimeoutInMs = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRetryCount0 = 0U;
    static VAR(uint8, ANFCRL_VAR) bIsoFrame[3];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTimeoutPrev = 0U;
    static VAR(uint16, ANFCRL_VAR) wIsoFrameLen = 0u;
    static VAR(uint16, ANFCRL_VAR) wOptionTmp = PH_EXCHANGE_DEFAULT;
    static VAR(phStatus_t, ANFCRL_VAR) statusBeforeSendDESL = 0U;
    static VAR(I14443P4_DISPATCHER_RETURNCASE_t, ANFCRL_VAR) PH_MEMLOC_REM bReturnCase = INITIAL_CASE;
    static VAR(I14443P4_ISOMSG_StateType_t, ANFCRL_VAR) P4_ISOMSG_NextState = PHPAL_I14443P4_STATE_IDLE;

	switch (pDataParams->eIsoMsgState)
	{
		case PHPAL_I14443P4_STATE_IDLE:
            status = PH_ERR_SUCCESS;
			wOptionTmp = wOption;
			/* Buffered Exchange is not allowed here */
			if (0U != (wOptionTmp & PH_EXCHANGE_BUFFERED_BIT))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P4);
			}
			/* Ignore custom modes */
			wOptionTmp &= (uint16) ~(uint16) PH_EXCHANGE_MODE_MASK;
			wIsoFrameLenBackup = 0U;
			/* Reset response received flag */
			bResponseReceived = 0U;
			bRetryCount0 = bRetryCount;
			bWtxm = 0U;

			pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SEND_BLOCK;
			/* no break */
		case PHPAL_I14443P4_STATE_SEND_BLOCK:
			/* Loops in case of an error */
			/* WTX Timeout - set temporary FWT */
			if (bWtxm > 0U)
			{
				/* Retrieve current timeout */
				status = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, &wTimeoutPrev);

				/* Timeout is out of range, retrieve it in milliseconds */
				if ((status & PH_ERR_MASK) == PH_ERR_PARAMETER_OVERFLOW)
				{
					(void) phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, &wTimeoutPrev);
					bTimeoutInMs = 1U;
				}
				else
				{
					PH_BREAK_ON_FAILURE(status);
					bTimeoutInMs = 0U;
				}

				if (pDataParams->bOpeMode == RD_LIB_MODE_ISO)
				{
					dwTimeout = (((uint32) PHPAL_I14443P4_SW_FWT_MIN_US
							* ((uint32) 1U << pDataParams->bFwi)) * (uint32) bWtxm)
							+ (uint32) PHPAL_I14443P4_EXT_TIME_US;
				}
				else
				{
					/* As per Digital Spec V1.1 req 15.3.2.1, NFC Forum Device SHALL wait at least FWTtemp + delta FWTT4AT for a Response */
					dwTimeout = (((uint32) PHPAL_I14443P4_SW_FWT_MIN_US
							* ((uint32) 1U << pDataParams->bFwi)) * (uint32) bWtxm)
							+ (uint32) PHPAL_I14443P4_SW_DELTA_FWT_US;

					dwTimeoutMax = PHPAL_I14443P4_SW_NFC_FWT_MAX_US;

					if (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO)
					{
						dwTimeout += (uint32) PHPAL_I14443P4_SW_DELTA_TPCD_US;

						dwTimeoutMax = PHPAL_I14443P4_SW_EMVCO_FWT_MAX_US;
					}
				}

				/* Limit timeout to FWT max */
				if (dwTimeout > dwTimeoutMax)
				{
					dwTimeout = dwTimeoutMax;
				}

				I14443P4_LOG("~~~ SET TEMPORARY WTX \r\n");

				/* Set temporary WTX timeout */
                if (dwTimeout > 0xFFFFU)
                {
                    pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_MS;
                }
                else
                {
                    pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_US;
                }
                return PH_STATUS_INPROCESS;
            }
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_MS:
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, (uint16 )((dwTimeout / 1000U) + 1U)));
            PH_BREAK_ON_FAILURE(statusTmp);
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_US:
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, (uint16 )dwTimeout));
            PH_BREAK_ON_FAILURE(statusTmp);
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS;
            /* no break */
        case PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS:
            wIsoFrameLen = wTxLength;

#ifdef NXPBUILD__PH_LOG_EX
			if (PHPAL_I14443P4_SW_IS_I_BLOCK(pTxBuffer[PHPAL_I14443P4_SW_PCB_POS]) != 0U)
			{
				(void) phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, &wTimeoutPrev);
				I14443P4_LOG(">>> P4_STATE_SEND_IBLOCK BlockNum:%d TIMEOUT:%d ms \r\n", pDataParams->bPcbBlockNum, wTimeoutPrev);
				I14443P4_LOG_BUF(">>> I-DATA: ", pTxBuffer, (uint8 )wIsoFrameLen);
			}
			else if (PHPAL_I14443P4_SW_IS_R_BLOCK(pTxBuffer[PHPAL_I14443P4_SW_PCB_POS]) != 0U)
			{
				if ((pTxBuffer[PHPAL_I14443P4_SW_PCB_POS] & PHPAL_I14443P4_SW_PCB_NAK) != 0U)
				{
					I14443P4_LOG(">>> R(NACK) \r\n");
				}
				else
				{
					I14443P4_LOG(">>> R(ACK) \r\n");
				}
			}
			else if (PHPAL_I14443P4_SW_IS_S_BLOCK(pTxBuffer[PHPAL_I14443P4_SW_PCB_POS]) != 0U)
			{
				I14443P4_LOG(">>> P4_STATE_SEND_SBLOCK \r\n");
			}
			else
			{
				; /* No action here */
			}
#endif
			bReturnCase = INITIAL_CASE;
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_WAITRSP_BLOCK;

            return PH_STATUS_INPROCESS;
		case PHPAL_I14443P4_STATE_WAITRSP_BLOCK:
			/* Call HAL exchange function */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, wOptionTmp, pTxBuffer, wTxLength, ppRxBuffer, pRxLength));
			statusBkUp = status;

			I14443P4_LOG("<<< P4_STATE_WAITRSP State:%0X Length:%d \r\n", status, *pRxLength);
			/* Reset Exchange Option */
			wOptionTmp = PH_EXCHANGE_DEFAULT;
			wIsoFrameLenBackup = 0U;
			/* Reset transmission length */
			wIsoFrameLen = 0U;
			/* WTX Timeout - restore previous value */
			if (bWtxm > 0U)
			{
				I14443P4_LOG("~~~ RESTORE WTX \r\n");
				/* Restore previous state and timeout after */
				if (0U == (bTimeoutInMs))
				{
                    pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_US;
				}
				else
				{
                    pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_MS;
				}
	            return PH_STATUS_INPROCESS;
			}
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_US:
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, wTimeoutPrev));
            PH_BREAK_ON_FAILURE(statusTmp);
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_MS:
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, wTimeoutPrev));
            PH_BREAK_ON_FAILURE(statusTmp);
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS;
            /* no break*/
        case PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS:
			bInvalidBlock = (uint8) PHPAL_I14443P4_SW_IS_INVALID_BLOCK_STATUS(status);

			if (0U == (bInvalidBlock))
			{
				/* MIFARE compliance: force protocol error on NAK */
				if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)
				{
					*pRxLength = 0U;
					statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0);
					PH_CHECK_ERROR_UPDATE_STATE(statusTmp, pDataParams->eIsoMsgState, PHPAL_I14443P4_STATE_IDLE);
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
					break;
				}
				else
				{
					PH_CHECK_ERROR_UPDATE_STATE(status, pDataParams->eIsoMsgState, PHPAL_I14443P4_STATE_IDLE);
				}
			}

			/* Reset defaults */
			bWtxm = 0U;

			/* Emvco: case_id TA404_04, TA411_04, TB404_04, TB411_04 */
			statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, &wRxBufferStartPos);
			PH_CHECK_ERROR_UPDATE_STATE(statusTmp, pDataParams->eIsoMsgState, PHPAL_I14443P4_STATE_IDLE);
#ifdef NXPBUILD__PH_LOG_EX
			/* For Logging data */
			if (status == PH_ERR_SUCCESS)
			{
				I14443P4_LOG_BUF("<<< ANY-BLOCK:", *ppRxBuffer + wRxBufferStartPos, (uint8 )(*pRxLength - wRxBufferStartPos));
			}
			else
			{
				I14443P4_LOG("<<< ANY-BLOCK: -- -- \r\n");
			}
			/* End Logging data */
#endif
			/* Check for FSD */
			if (((*pRxLength) - wRxBufferStartPos) > (bI14443p4_FsTable[pDataParams->bFsdi] - 2u))
			{
				(void) phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0);
				*pRxLength = 0U;
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
				break;
			}
			/* Do not enter if we received an invalid block */
			if (0U == (bInvalidBlock))
			{
				/* Signal that we've received something */
				bResponseReceived = 1U;

				/* Map receive buffer pointer to current data */
				pResp = &((*ppRxBuffer)[wRxBufferStartPos]);
				wRespLen = *pRxLength - wRxBufferStartPos;

				/* I-Block handling */
				if (0u != (PHPAL_I14443P4_SW_IS_I_BLOCK(pResp[PHPAL_I14443P4_SW_PCB_POS])))
				{
					I14443P4_LOG("~~~ I-BLOCK HANDLING \r\n");
					/* Rule 2/10, ISO/IEC 14443-4:2008(E) */
					if (pDataParams->bStateNow == (PHPAL_I14443P4_SW_STATE_I_BLOCK_TX | PHPAL_I14443P4_SW_STATE_CHAINING_BIT))
					{
						/* Protocol violation */
						bInvalidBlock = 1U;
					}
					else
					{
						/* Evaluate if NAD should be present */
						/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
						if ((pDataParams->bNadEnabled > 0U) && (0U == ((pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_CHAINING_BIT))))
						{
							bCheckNad = 1U;
						}
						else
						{
							bCheckNad = 0U;
						}

						/* Check if I-Block is valid */
						statusTmp = phpalI14443p4_Sw_IsValidIBlock(pDataParams->bCidEnabled, pDataParams->bCid, bCheckNad, pDataParams->bNad, pResp, wRespLen);

						/* Block number is equal, I-Block Rx mode is active */
						if (((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS) && (PHPAL_I14443P4_SW_IS_BLOCKNR_EQUAL(pResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U))
						{
							/* Switch from Tx-Mode to Rx-Mode */
							if ((pDataParams->bStateNow & PHPAL_I14443P4_SW_STATE_MASK) == PHPAL_I14443P4_SW_STATE_I_BLOCK_TX)
							{
								pDataParams->bStateNow = PHPAL_I14443P4_SW_STATE_I_BLOCK_RX;
								bReturnCase = TXMODE_NORMAL_SWITH_TO_RXMODE;
								/* Set chaining bit if card is chaining */
								if (0u != (PHPAL_I14443P4_SW_IS_CHAINING(pResp[PHPAL_I14443P4_SW_PCB_POS])))
								{
									pDataParams->bStateNow |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
								}
								/* Clear chaining bit otherwise */
								else
								{
									pDataParams->bStateNow &= (uint8) ~(uint8) PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
									/* RETURN CASE 1-2 */
									bReturnCase = TXMODE_NORMAL_FINISH; /* Finish */
								}
							}
							/* Rx-Mode */
							else
							{
								/* Set chaining bit if card is chaining */
								if (0u != (PHPAL_I14443P4_SW_IS_CHAINING(pResp[PHPAL_I14443P4_SW_PCB_POS])))
								{
									pDataParams->bStateNow |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
									if (PH_ERR_BUFFER_OVERFLOW == (statusBkUp & PH_ERR_MASK))
									{
										/* RETURN CASE 2-5 */
										bReturnCase = RXMODE_ABNORMAL_BUFFER_OVERFLOW;
									}
									else
									{
										/* RETURN CASE 2-1 */
										bReturnCase = RXMODE_NORMAL_RECEIVING_IBLOCK;
									}
								}
								/* Clear chaining bit otherwise */
								else
								{
									pDataParams->bStateNow &= (uint8) ~(uint8) PHPAL_I14443P4_SW_STATE_CHAINING_BIT;
									/* RETURN CASE 2-2 */
									bReturnCase = RXMODE_NORMAL_FINISH;
								}
							}
							/* Rule B, ISO/IEC 14443-4:2008(E), toggle Block number */
							pDataParams->bPcbBlockNum ^= PHPAL_I14443P4_SW_PCB_BLOCKNR;
							/* Overlap CID */
							I14443P4_LOG_BUF("~~~ P4_SW_PCB_POS: ", pResp+PHPAL_I14443P4_SW_PCB_POS, 1U);

						}
						/* We received an invalid block */
						else
						{
							/* Protocol violation */
							bInvalidBlock = 1U;
						}
					}
				}
				/* R(ACK) handling */
				else if ((PHPAL_I14443P4_SW_IS_R_BLOCK(pResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U) && (PHPAL_I14443P4_SW_IS_ACK(pResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U))
				{
					I14443P4_LOG("~~~ R(ACK) HANDLING: CurrentBN:%d \r\n", pDataParams->bPcbBlockNum);
					/* Check if R-Block is valid */
					status = phpalI14443p4_Sw_IsValidRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pResp, wRespLen);

					/* R-Block invalid or not in transmission mode */
					if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
					{
						/* Protocol violation */
						bInvalidBlock = 1U;
					}
					else
					{
						/* Block number is equal */
						if (0u != (PHPAL_I14443P4_SW_IS_BLOCKNR_EQUAL(pResp[PHPAL_I14443P4_SW_PCB_POS])))
						{
							/* Continue TX chaining */
							if (pDataParams->bStateNow == (PHPAL_I14443P4_SW_STATE_I_BLOCK_TX | PHPAL_I14443P4_SW_STATE_CHAINING_BIT))
							{
								/* Rule B, ISO/IEC 14443-4:2008(E), toggle Block number */
								pDataParams->bPcbBlockNum ^= PHPAL_I14443P4_SW_PCB_BLOCKNR;
								/* RETURNCASE 1-4 */
								bReturnCase = TXMODE_NORMAL_NEXT_TRANSMISSION;
							}
							/* Not in chaining mode */
							else
							{
								/* Protocol violation */
								bInvalidBlock = 1U;
							}
						}
						/* Rule 6, ISO/IEC 14443-4:2008(E), unequal block number */
						else
						{
							I14443P4_LOG("~~~ R(ACK) unequal block number \r\n");
							/* Limit this behaviour with bMaxRetryCount, bRetry count is set by the caller in this case */
							if ((bRetryCount0 > pDataParams->bMaxRetryCount) || (pDataParams->bMaxRetryCount == 0U))
							{
								/* Protocol violation */
								bInvalidBlock = 1U;
							}
							/* Send last I-Block again */
							else
							{
								pDataParams->bStateNow |= PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT;
								/* RETURNCASE 1-5, Re-Transmit */
								bReturnCase = TXMODE_ABNORMAL_RE_TRANSMISSION;
							}
						}
					}
				}
				/* S(WTX) handling */
				else if ((PHPAL_I14443P4_SW_IS_S_BLOCK(pResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U) && (PHPAL_I14443P4_SW_IS_WTX(pResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U))
				{
					I14443P4_LOG("~~~ S(WTX) HANDLING \r\n");
					/* Check if S-Block is valid */
					status = phpalI14443p4_Sw_IsValidSBlock(pDataParams->bCidEnabled, pDataParams->bCid, pResp, wRespLen);

					/* Rule 3, ISO/IEC 14443-4:2008(E), S(WTX) handling */
					if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
					{
						/* Retrieve WTXM */
						bWtxm = pResp[wRespLen - 1u];

						/* Ignore and clear the Power Level Indication */
						bWtxm &= 0x3FU;

						/* Treat invalid WTXM value as protocol error, do not perform error correction. */
						if ((bWtxm == 0U) || (bWtxm > 59U))
						{
							status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
							break;
						}

						/* Generate S(WTX) frame */
						statusTmp = phpalI14443p4_Sw_BuildSBlock(pDataParams->bCidEnabled, pDataParams->bCid, 1, bWtxm, bIsoFrame, &wIsoFrameLen);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, pDataParams->eIsoMsgState, PHPAL_I14443P4_STATE_IDLE);
						/* Prepare S(WTX) frame, Rule 3 */
						bReturnCase = PROCESS_CMD_SWTX;
					}
					/* We received an invalid block */
					else
					{
						/* Protocol violation */
						bInvalidBlock = 1U;
					}
				}
				/* We received an invalid block */
				else
				{
					/* Protocol violation */
					bInvalidBlock = 1U;
				}

				/* Protocol violation */
				if (0U != (bInvalidBlock))
				{
					bReturnCase = HANDLING_ERROR_PROTOCOL;
					if (pDataParams->bMaxRetryCount > 0U)
					{
						bRetryCount0 = pDataParams->bMaxRetryCount;
					}
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
					statusBeforeSendDESL = status;
                    pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT;
                    return PH_STATUS_INPROCESS;
				}
				/* Reset retry counter on no error */
				else
				{
					bRetryCount0 = 0U;
				}
			}
			/* Invalid Block received */
			else
			{
				I14443P4_LOG("~~~ X-BLOCK (INVALID) HANDLING \r\n");
				/* Only perform error correction if the max. retry count is not reached */
				/* For ISO (7.5.6.1 Errors detected by the PCD)
				 * aU) Transmission error (Frame error or EDC error) or FWT time-out
				 *      The PCD shall attempt error recovery by the following techniques in the order shown:
				 *   - Application of PCD rules (see 7.5.4.2),
				 *   - Optionally apply PCD rules (see 7.5.4.2) once more,
				 *   - Use of S(DESELECT) request,
				 *
				 *   ISO 10373-6 Scenario H.29
				 */

				/* DTA: Scenario 110 case: TC_POL_NFCA_T4AT_BI_31_xy, Article(13.2.5.4). Page 210
				 * and For EMVCo: TA401_15 Article(10.3.4.4)
				 * Says, After 2nd failed retry of I-block exchange. Send NAk
				 */

				/* This is added to restrict retry count less than 1 for ISO mode */
				if ((bRetryCount0 >= pDataParams->bMaxRetryCount) && (pDataParams->bOpeMode == RD_LIB_MODE_ISO))
				{
					if (pDataParams->bMaxRetryCount > 0U)
					{
						/* backup retry count */
						bRetryCount0 = pDataParams->bMaxRetryCount;

						/* set retry count to zero to send only one S(DESELECT) */
						pDataParams->bMaxRetryCount = 0;

						P4_ISOMSG_NextState = PHPAL_I14443P4_STATE_DESEL;
						statusBeforeSendDESL = status;
					}
					else
					{
						P4_ISOMSG_NextState = PHPAL_I14443P4_STATE_IDLE;
					}
					/* RETURNCASE 9-1 */
					bReturnCase = HANDLING_ERROR_MAX_RETRY_OCCURS;
					pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE;
					return PH_STATUS_INPROCESS;
				}
				else if (bRetryCount0 <= pDataParams->bMaxRetryCount)
				{
					/* Rule 5, ISO/IEC 14443-4:2008(E) */
					if (pDataParams->bStateNow == (PHPAL_I14443P4_SW_STATE_I_BLOCK_RX | PHPAL_I14443P4_SW_STATE_CHAINING_BIT))
					{
						/* RETURNCASE 2-3 */
						bReturnCase = RXMODE_ABNORMAL_SEND_RACK_FOR_RETRY;
						/* Generate R(ACK) frame */
						statusTmp = phpalI14443p4_Sw_BuildRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pDataParams->bPcbBlockNum, 1, bIsoFrame, &wIsoFrameLen);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, pDataParams->eIsoMsgState, PHPAL_I14443P4_STATE_IDLE);
					}
					/* Rule 4, ISO/IEC 14443-4:2008(E) */
					else
					{
						/* Generate R(NAK) frame */
						statusTmp = phpalI14443p4_Sw_BuildRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pDataParams->bPcbBlockNum, 0, bIsoFrame, &wIsoFrameLen);
						PH_CHECK_ERROR_UPDATE_STATE(statusTmp, pDataParams->eIsoMsgState, PHPAL_I14443P4_STATE_IDLE);
						/* RETURNCASE 1-3 */
						bReturnCase = TXMODE_ABNORMAL_TIMEOUT_RETRY2RCV_IBLOCK;
					}
				}
				/* Bail out if the max. retry count is reached */
				else
				{
					bReturnCase = HANDLING_ERROR_MAX_RETRY_OCCURS;
					/* Deselect card if behaviour is enabled */
					if (pDataParams->bMaxRetryCount > 0U)
					{
						/* backup retry count */
						bRetryCount0 = pDataParams->bMaxRetryCount;

						/* set retry count to zero to send only one S(DESELECT) */
						pDataParams->bMaxRetryCount = 0;

						statusBeforeSendDESL = status;
                        pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT;
                        return PH_STATUS_INPROCESS;
					}
					pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE;
					return PH_STATUS_INPROCESS;
				}

				/* Increment retry count */
				++bRetryCount0;
			}

			/* Map TxBuffer to ISO Frame buffer for next loop */
			if (wIsoFrameLen > 0U)
			{
				phTools_memcpy(bIsoFrameBackup, bIsoFrame, wIsoFrameLen);
			}
			wIsoFrameLenBackup = wIsoFrameLen;
			/* Loop as long as we generate transmissions */
			if (0U != wIsoFrameLen)
			{
				pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_SEND_BLOCK;
				return PH_STATUS_INPROCESS;
			}
			P4_ISOMSG_NextState = PHPAL_I14443P4_STATE_IDLE;
			pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE;
			return PH_STATUS_INPROCESS;
        case PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT:
            P4_ISOMSG_NextState = PHPAL_I14443P4_STATE_DESEL;
            pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE;
            /* no break */
		case PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE:
			switch (bReturnCase)
			{
				case INITIAL_CASE:
					break;
				case TXMODE_NORMAL_FINISH:
					/* Getting first I-BLOCK (no chaining), Finish ISO-DEP Messaging */
					I14443P4_LOG("^^^ [CASE 12: TX-MODE RETURN NORMAL - FINISH]\r\n");
					break;
				case TXMODE_NORMAL_SWITH_TO_RXMODE:
					I14443P4_LOG("^^^ [CASE 11: TX-MODE NORMAL - CONTINOUS TO RX-MODE]\r\n");
					break;
				case TXMODE_ABNORMAL_TIMEOUT_RETRY2RCV_IBLOCK:
					(void) phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, &wTimeoutPrev);
					I14443P4_LOG("^^^ [CASE 13: TX-MODE ABNORMAL TRY AGAIN (TO RCV FIRST I-BLOCK) TIMEOUT:%d ms]\r\n", wTimeoutPrev);
					break;
				case TXMODE_NORMAL_NEXT_TRANSMISSION:
					I14443P4_LOG("^^^ [CASE 14: TX-MODE NORMAL, NEXT-TRANSMISSION ]\r\n");
					break;
				case TXMODE_ABNORMAL_RE_TRANSMISSION:
					I14443P4_LOG("^^^ [CASE 15: TX-MODE ABNORMAL, RE-TRANSMISSION ]\r\n");
					break;
				case RXMODE_NORMAL_RECEIVING_IBLOCK:
					I14443P4_LOG("^^^ [CASE 21: RX-MODE RECEIVING DATA FROM CARD ]\r\n");
					/* Return with chaining status if the next chain may not fit into our buffer */
					break;
				case RXMODE_NORMAL_FINISH:
					I14443P4_LOG("^^^ [CASE 22: RX-MODE RETURN NORMAL - FINISH]\r\n");
					break;
				case RXMODE_ABNORMAL_SEND_RACK_FOR_RETRY:
					I14443P4_LOG("^^^ [CASE 23: RX-MODE RETRY SEND R(ACK) AGAIN ]\r\n");
					break;
				case RXMODE_NORMAL_SEND_RACK_FOR_RECEIVING:
					I14443P4_LOG("[CASE 24: RX-MODE RETURN NORMAL - SEND R(ACK) FOR CONTINUE RECEIVING]\r\n");
					break;
				case RXMODE_ABNORMAL_BUFFER_OVERFLOW:
					I14443P4_LOG("^^^ [CASE 25: RX-MODE RETURN ABNORMAL - RECEIVING BUFFER OVERFLOW ]\r\n");
					break;
				case PROCESS_CMD_SWTX:
					I14443P4_LOG("^^^ [CASE 30: PROCESS S(WTX) FROM CARD, SET WTX ]\r\n");
					break;
				case HANDLING_ERROR_PROTOCOL:
					I14443P4_LOG("^^^ [CASE 90: PROTOCOL ERROR ]\r\n");
					break;
				case HANDLING_ERROR_MAX_RETRY_OCCURS:
					I14443P4_LOG("^^^ [CASE 91: ABNORMAL MAX RETRIES ERROR ]\r\n");
					break;
			}
			if (P4_ISOMSG_NextState == PHPAL_I14443P4_STATE_DESEL)
			{
				pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_DESEL;
				return PH_STATUS_INPROCESS;
			}
			break;

		case PHPAL_I14443P4_STATE_DESEL:
		    /* Send S(DESELECT) */
			status = phpalI14443p4_Sw_Deselect(pDataParams);
			if (status == PH_STATUS_INPROCESS)
			{
				return PH_STATUS_INPROCESS;
			}
			I14443P4_LOG("-- DESELECT IF ERROR  --\r\n");
			/* restore retry count setting */
			pDataParams->bMaxRetryCount = bRetryCount0;
			status = statusBeforeSendDESL;
			/* Return ERR_RECOVERY_FAILED if some response has been received before */
			if (0U != (bResponseReceived))
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
			}
			break;
		default:
			status = PH_ERR_INTERNAL_ERROR;
			break;
	}
    pDataParams->eIsoMsgState = PHPAL_I14443P4_STATE_IDLE;
    statusBkUp = PH_ERR_SUCCESS;
    dwTimeout = 0U;
    bTimeoutInMs = 0U;
    if(statusTmp != PH_ERR_SUCCESS)
    {
    	status = statusTmp;
    }
	/* Reset RxBuffer Start Position */
	PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0));
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_Deselect(P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bInvalidBlock = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsoFrame[3] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIsoFrameLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bResponseReceived = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRetries = 0U;

	switch (pDataParams->eDeselState)
	{
	case PHPAL_I14443P4_DESEL_IDLE:
		/* Set DESELECT timeout */
		PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
		                                                  PHPAL_I14443P4_SW_FWT_DESELECT_US + PHPAL_I14443P4_EXT_TIME_US));
		PH_BREAK_ON_FAILURE(status);
		/* Retrieve max. retry count */
		wRetries = (uint16) pDataParams->bMaxRetryCount + 1U;

		/* Build S(DESELECT) frame */
		PH_CHECK_FAILURE_FCT(status, phpalI14443p4_Sw_BuildSBlock(pDataParams->bCidEnabled, pDataParams->bCid, 0, 0, bIsoFrame, &wIsoFrameLen));

		/* Reset response received flag */
		bResponseReceived = 0;
		pDataParams->eDeselState = PHPAL_I14443P4_DESEL_SEND;
		I14443P4_LOG_BUF(">>> P4_STATE_CMD_DESELECT_SEND:", bIsoFrame, (uint8 )wIsoFrameLen);
		/* no break */

	case PHPAL_I14443P4_DESEL_SEND:
		/* Do as long as invalid responses are received
		 and the retry counter has not reached zero.*/
		/* Send the S(DESELECT) request */
		PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, bIsoFrame, wIsoFrameLen, &pResp, &wRespLen));

#ifdef NXPBUILD__PH_LOG_EX
		if (status != PH_ERR_SUCCESS)
		{
			I14443P4_LOG("<<< P4_STATE_CMD_DESELECT_RESPONSE Status:%0X \r\n", status);
		}
		else
		{
			I14443P4_LOG_BUF("<<< P4_STATE_CMD_DESELECT_RESPONSE:", pResp, (uint8 )wRespLen);
		}
#endif
		/* Status --> InvalidBlock mapping */
		bInvalidBlock = (uint8) PHPAL_I14443P4_SW_DESELECT_IS_INVALID_BLOCK_STATUS(status);

		if (0U == (bInvalidBlock))
		{
			/* Check for other errors */
			PH_BREAK_ON_FAILURE(status);

			/* Signal that we've received something */
			bResponseReceived = 1;

			/* Rule 8, ISO/IEC 14443-4:2008(E), "...the S(DESELECT) request may be re-transmitted..." */
			if ((wRespLen == wIsoFrameLen) && (wRespLen > 0U) && (wRespLen < 3U))
			{
				/* Mask out Power-Level-Indication */
				if (0U != (pDataParams->bCidEnabled))
				{
					pResp[1] &= 0x3FU;
				}

				/* Verify S(DESELECT) Response */
				if (memcmp(bIsoFrame, pResp, wRespLen) != 0)
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
				}
			}
			else
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
			}
		}
		--wRetries;
		/* Retry as long as necessary */
		if ((0U != bInvalidBlock) && (wRetries != 0U))
		{
			pDataParams->eDeselState = PHPAL_I14443P4_DESEL_SEND;
			return PH_STATUS_INPROCESS;
		}
		/* Operation not successful */
		if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
		{
			/* Return ERR_RECOVERY_FAILED if some response has been received before (bMaxRetryCount = 0 suppresses the retry behaviour) */
			if ((pDataParams->bMaxRetryCount > 0U) && (bResponseReceived > 0U))
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
			}
		}

		/* Apply default parameters */
		(void) phpalI14443p4_Sw_ResetProtocol(pDataParams);
		break;
	}

	/* Reset variables */
	bIsoFrame[0] = 0U;
	bIsoFrame[1] = 0U;
	bIsoFrame[2] = 0U;
	wIsoFrameLen = 0U;
	bResponseReceived = 0U;
	wRetries = 0U;
	pResp = NULL;
	wRespLen = 0U;
	pDataParams->eDeselState = PHPAL_I14443P4_DESEL_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_PresCheck(
                                      P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                      )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsoFrame[3] = {0U};
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pIsoFrameResp = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIsoFrameLen = 0U;

	switch (pDataParams->ePresCheckState)
	{
	case PHPAL_I14443P4_PRESCHECK_SEND:
		/* Build R(NAK) frame */
		PH_CHECK_FAILURE_FCT(status, phpalI14443p4_Sw_BuildRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pDataParams->bPcbBlockNum, 0, bIsoFrame, &wIsoFrameLen));

		I14443P4_LOG_BUF(">>> P4_STATE_CMD_RNAK_SEND: ", bIsoFrame, (uint8 )wIsoFrameLen);
		pDataParams->ePresCheckState = PHPAL_I14443P4_PRESCHECK_WAITRSP;

		return PH_STATUS_INPROCESS;

	case PHPAL_I14443P4_PRESCHECK_WAITRSP:
		/* Send frame */
		PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, bIsoFrame, wIsoFrameLen, &pIsoFrameResp, &wIsoFrameLen));

#ifdef NXPBUILD__PH_LOG_EX
		if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
		{
			I14443P4_LOG("<<< P4_STATE_CMD_RNAK_WAITRSP:%0X  \r\n", status);
		}
		else
		{
			I14443P4_LOG_BUF("<<< P4_STATE_CMD_RNAK_WAITRSP: ", pIsoFrameResp, (uint8 )wIsoFrameLen);
		}
#endif /* NXPBUILD__PH_LOG_EX */

		/* Check if we got a valid R(ACK) response */
		if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
			if ((PHPAL_I14443P4_SW_IS_R_BLOCK(pIsoFrameResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U) && (PHPAL_I14443P4_SW_IS_ACK(pIsoFrameResp[PHPAL_I14443P4_SW_PCB_POS]) > 0U))
			{
				status = phpalI14443p4_Sw_IsValidRBlock(pDataParams->bCidEnabled, pDataParams->bCid, pIsoFrameResp, wIsoFrameLen);
			}
			else
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4);
			}
		}
		break;
	}

	/* Reset variables */
	bIsoFrame[0] = 0U;
	bIsoFrame[1] = 0U;
	bIsoFrame[2] = 0U;
	pIsoFrameResp = NULL;
	wIsoFrameLen = 0U;
	pDataParams->ePresCheckState = PHPAL_I14443P4_PRESCHECK_SEND;
	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4_SW */

#ifdef __cplusplus
}
#endif
