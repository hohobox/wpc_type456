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
*   @file    phpalI14443p4_Sw2.c
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

#include <ph_Status2.h>
#include <phhalHw2.h>
#include <phpalI14443p42.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PHPAL_I14443P4_SW2

#include "phpalI14443p4_Sw_Int2.h"
#include "phpalI14443p4_Sw2.h"
#include <phTools2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4_Sw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_SW_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4_Sw.h header file are of the same vendor */
#if (PHPALI14443P4_SW_VENDOR_ID_C2 != PHPALI14443P4_SW_VENDOR_ID2)
    #error "phpalI14443p4_Sw2.c and phpalI14443p4_Sw2.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2    != PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2    != PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION_C2 != PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalI14443p4_Sw2.c and phpalI14443p4_Sw2.h are different"
#endif
/* Check if current file and phpalI14443p4_Sw.h header file are of the same Software version */
#if ((PHPALI14443P4_SW_SW_MAJOR_VERSION_C2 != PHPALI14443P4_SW_SW_MAJOR_VERSION2) || \
     (PHPALI14443P4_SW_SW_MINOR_VERSION_C2 != PHPALI14443P4_SW_SW_MINOR_VERSION2) || \
     (PHPALI14443P4_SW_SW_PATCH_VERSION_C2 != PHPALI14443P4_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalI14443p4_Sw2.c and phpalI14443p4_Sw2.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4_SW2
#define PH_CHECK_ERROR_UPDATE_STATE2(status2,stateVar2,stateVal2)         if ((uint16)((status2) & 0xFFU) != PH_ERR_SUCCESS2) {(stateVar2) = (stateVal2); return (status2);}

#define PHPAL_I14443P4_SW_IS_BLOCKNR_EQUAL2(bPcb2)                        \
    (                                                                   \
        ((((bPcb2) & PHPAL_I14443P4_SW_PCB_BLOCKNR2) ^ pDataParams2->bPcbBlockNum2) == 0U) \
        ? 1u : 0u                                                       \
    )

#define PHPAL_I14443P4_SW_IS_ACK2(bPcb2)                                  \
    (                                                                   \
    (((bPcb2) & PHPAL_I14443P4_SW_PCB_NAK2) == PHPAL_I14443P4_SW_PCB_ACK2) \
    ? 1u : 0u                                                             \
    )

#define PHPAL_I14443P4_SW_IS_CHAINING2(bPcb2)                                         \
    (                                                                               \
    (((bPcb2) & PHPAL_I14443P4_SW_PCB_CHAINING2) == PHPAL_I14443P4_SW_PCB_CHAINING2)   \
    ? 1u : 0u                                                                         \
    )

#define PHPAL_I14443P4_SW_IS_WTX2(bPcb2)                                  \
    (                                                                   \
    (((bPcb2) & PHPAL_I14443P4_SW_PCB_WTX2) == PHPAL_I14443P4_SW_PCB_WTX2) \
    ? 1u : 0u                                                             \
    )

#define PHPAL_I14443P4_SW_IS_DESELECT2(bPcb2)                                     \
    (                                                                           \
    (((bPcb2) & PHPAL_I14443P4_SW_PCB_WTX2) == PHPAL_I14443P4_SW_PCB_DESELECT2)    \
    ? 1u : 0u                                                                     \
    )

#define PHPAL_I14443P4_SW_IS_I_BLOCK2(bPcb2)                                  \
    (                                                                       \
    (((bPcb2) & PHPAL_I14443P4_SW_BLOCK_MASK2) == PHPAL_I14443P4_SW_I_BLOCK2)  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_IS_R_BLOCK2(bPcb2)                                  \
    (                                                                       \
    (((bPcb2) & PHPAL_I14443P4_SW_BLOCK_MASK2) == PHPAL_I14443P4_SW_R_BLOCK2)  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_IS_S_BLOCK2(bPcb2)                                  \
    (                                                                       \
    (((bPcb2) & PHPAL_I14443P4_SW_BLOCK_MASK2) == PHPAL_I14443P4_SW_S_BLOCK2)  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_IS_INVALID_BLOCK_STATUS2(bStatus2)                  \
    ((                                                                      \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2) ||                     \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2) ||                \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_FRAMING_ERROR2) ||                  \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2))                  \
    ? 1u : 0u                                                                 \
    )

#define PHPAL_I14443P4_SW_DESELECT_IS_INVALID_BLOCK_STATUS2(bStatus2)         \
    ((                                                                      \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2) ||                     \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2) ||                \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_FRAMING_ERROR2) ||                  \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_SUCCESS_INCOMPLETE_BYTE2) ||        \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_PROTOCOL_ERROR2) ||                 \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2))                  \
    ? 1u : 0u                                                                 \
    )

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(I14443P4_EXCHANGE_StateType_t2, ANFCRL_VAR) P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
static VAR(uint16, ANFCRL_VAR) wIsoFrameLenBackup2 = 0;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) bIsoFrameBackup2[3];

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 bI14443p4_FsTable2[13] = {16, 24, 32,
                                                                   40, 48, 64,
                                                                   96, 128, 256,
                                                                   512, 1024,
                                                                   2048, 4096};
#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2== 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_Init2(
                                 P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
                                 )
{
	if (sizeof(phpalI14443p4_Sw_DataParams_t2) != wSizeOfDataParams2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P42);
	}
	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(pHalDataParams2);

	P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
	/* reset state */
	pDataParams2->eExchangeState2 = PHPAL_I14443P4_EXCHANGE_START2;
	pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_IDLE2;
	pDataParams2->eDeselState2 = PHPAL_I14443P4_DESEL_IDLE2;
	pDataParams2->ePresCheckState2 = PHPAL_I14443P4_PRESCHECK_SEND2;

	/* Init private data */
	pDataParams2->wId2 = PH_COMP_PAL_ISO14443P42 | PHPAL_I14443P4_SW_ID2;
	pDataParams2->pHalDataParams2 = pHalDataParams2;
	pDataParams2->bOpeMode2 = RD_LIB_MODE_ISO2;

	/* Reset protocol to defaults */
	return phpalI14443p4_Sw_ResetProtocol2(pDataParams2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_SetProtocol2(P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bCidEnable2, VAR(uint8, ANFCRL_VAR) bCid2, VAR(uint8, ANFCRL_VAR) bNadEnable2, VAR(uint8, ANFCRL_VAR) bNad2, VAR(uint8, ANFCRL_VAR) bFwi2,
    VAR(uint8, ANFCRL_VAR) bFsdi2, VAR(uint8, ANFCRL_VAR) bFsci2)
{
	/* Rule A, ISO/IEC 14443-4:2008(E), init. Block number to zero */
	pDataParams2->bPcbBlockNum2 = 0U;

	/* Check parameters */
	if ((bCid2 > PHPAL_I14443P4_CID_MAX2) || (bFwi2 > PHPAL_I14443P4_FWI_MAX2) || (bFsdi2 > PHPAL_I14443P4_FRAMESIZE_MAX2) || (bFsci2 > PHPAL_I14443P4_FRAMESIZE_MAX2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P42);
	}

	/* Apply parameters */
	pDataParams2->bCidEnabled2 = bCidEnable2;
	pDataParams2->bCid2 = bCid2;
	pDataParams2->bNadEnabled2 = bNadEnable2;
	pDataParams2->bNad2 = bNad2;
	pDataParams2->bFwi2 = bFwi2;
	pDataParams2->bFsdi2 = bFsdi2;
	pDataParams2->bFsci2 = bFsci2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_ResetProtocol2(P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
	/* Set default state */
	pDataParams2->bStateNow2 = PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2;

	/* Rule A, ISO/IEC 14443-4:2008(E), init. Block number to zero */
	pDataParams2->bPcbBlockNum2 = 0U;

	/* Apply default parameters */
	pDataParams2->bCidEnabled2 = 0x00U;
	pDataParams2->bCid2 = 0x00U;
	pDataParams2->bNadEnabled2 = 0x00U;
	pDataParams2->bNad2 = 0x00U;
	pDataParams2->bFwi2 = PHPAL_I14443P4_SW_FWI_DEFAULT2;
	pDataParams2->bFsdi2 = 0x00U;
	pDataParams2->bFsci2 = PHPAL_I14443P4_SW_FSCI_DEFAULT2;
	pDataParams2->bMaxRetryCount2 = PHPAL_I14443P4_SW_MAX_RETRIES_DEFAULT2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsValidIBlock2(
    VAR(uint8, ANFCRL_VAR) bCheckCid2,
    VAR(uint8, ANFCRL_VAR) bCid2,
    VAR(uint8, ANFCRL_VAR) bCheckNad2,
    VAR(uint8, ANFCRL_VAR) bNad2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    VAR(uint16, ANFCRL_VAR) wRxLength2
    )
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wExpRxLength2 = 0U;

	/* Check RFU bits */
	if ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_I_BLOCK_RFU_MASK2) != PHPAL_I14443P4_SW_I_BLOCK_RFU_BITS2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength2 = 1U;

	/* Enable CID checking if necessary */
	if (0U != (bCheckCid2))
	{
		wExpRxLength2++;
	}

	/* Enable NAD checking if necessary */
	if (0U != (bCheckNad2))
	{
		wExpRxLength2++;
	}

	/* The frame should have the minimum frame length */
	if (wRxLength2 < wExpRxLength2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* CID presence check */
	if ((0u != bCheckCid2) && ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2) > 0U) && ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2 + 1U] & PHPAL_I14443P4_SW_CID_MASK2) == bCid2))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid2) && (0u == (pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2)))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* NAD presence check */
	if ((0u != bCheckNad2) && (0U != (pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING2)) && (pRxBuffer2[wExpRxLength2 - 1u] == bNad2))
	{
		/* CHECK SUCCEEDED */
	}
	/* NAD absence check */
	else if ((bCheckNad2 == 0U) && ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING2) == 0U))
	{
		/* CHECK SUCCEEDED */
	}
	/* NAD protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsValidRBlock2(
	VAR(uint8, ANFCRL_VAR) bCheckCid2,
	VAR(uint8, ANFCRL_VAR) bCid2,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    VAR(uint16, ANFCRL_VAR) wRxLength2)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wExpRxLength2 = 0U;

	/* Check RFU bits */
	if ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_R_BLOCK_RFU_MASK2) != PHPAL_I14443P4_SW_R_BLOCK_RFU_BITS2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength2 = 1U;

	/* If CID is enabled, we always expect it */
	if (0U != (bCheckCid2))
	{
		wExpRxLength2++;
	}

	/* The frame should have the exact frame length */
	if (wRxLength2 != wExpRxLength2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* CID presence check */
	if ((0U != bCheckCid2) && (0U != (pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2)) && ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2 + 1U] & PHPAL_I14443P4_SW_CID_MASK2) == bCid2))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid2) && (0u == (pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2)))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsValidSBlock2(
    VAR(uint8, ANFCRL_VAR) bCheckCid2,
    VAR(uint8, ANFCRL_VAR) bCid2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    VAR(uint16, ANFCRL_VAR) wRxLength2
    )
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wExpRxLength2 = 0U;

	/* Check RFU bits, return with Protocol error if received PCB byte is not related to "Waiting time extension" */
	if ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_S_BLOCK_RFU_MASK2) != PHPAL_I14443P4_SW_S_BLOCK_RFU_BITS2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength2 = 1U;

	/* If CID is enabled, we always expect it */
	if (0U != (bCheckCid2))
	{
		wExpRxLength2++;
	}

	/* If this is a WTX request, we expect an additional INF byte */
	if (0u != (PHPAL_I14443P4_SW_IS_WTX2(pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2])))
	{
		wExpRxLength2++;
	}

	/* The frame should have the exact frame length */
	if (wRxLength2 != wExpRxLength2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	/* CID presence check */
	if ((0u != bCheckCid2) && (0U != (pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2)) && ((pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2 + 1U] & PHPAL_I14443P4_SW_CID_MASK2) == bCid2))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid2) && (0u == (pRxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2)))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_BuildIBlock2(
	VAR(uint8, ANFCRL_VAR) bCidEnabled2,
	VAR(uint8, ANFCRL_VAR) bCid2,
	VAR(uint8, ANFCRL_VAR) bNadEnabled2,
	VAR(uint8, ANFCRL_VAR) bNad2,
	VAR(uint8, ANFCRL_VAR) bPcbBlockNum2,
	VAR(uint8, ANFCRL_VAR) bChaining2,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength2)
{
	/* I-Block PCB */
	pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] = PHPAL_I14443P4_SW_I_BLOCK2 | PHPAL_I14443P4_SW_I_BLOCK_RFU_BITS2 | bPcbBlockNum2;
	*pTxLength2 = 1U;

	/* Check if chaining is necessary */
	if (0U != (bChaining2))
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_CHAINING2;
	}

	/* Append CID if necessary */
	if (0U != (bCidEnabled2))
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2;
		pTxBuffer2[(*pTxLength2)++] = bCid2;
	}

	/* Append NAD if necessary */
	if (0U != (bNadEnabled2))
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING2;
		pTxBuffer2[(*pTxLength2)++] = bNad2;
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_BuildRBlock12(
	VAR(uint8, ANFCRL_VAR) bCidEnabled2,
	VAR(uint8, ANFCRL_VAR) bCid2,
	VAR(uint8, ANFCRL_VAR) bPcbBlockNum2,
	VAR(uint8, ANFCRL_VAR) bIsAck2,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength2)
{
	/* R(ACK) PCB */
	pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] = PHPAL_I14443P4_SW_R_BLOCK2 | PHPAL_I14443P4_SW_R_BLOCK_RFU_BITS2 | bPcbBlockNum2;
	*pTxLength2 = 1U;

	/* Switch to R(NAK) if necessary */
	if (0U == (bIsAck2))
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_NAK2;
	}

	/* Append CID if supported */
	if (bCidEnabled2 != 0U)
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2;
		pTxBuffer2[(*pTxLength2)++] = bCid2;
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_BuildSBlock2(
	VAR(uint8, ANFCRL_VAR) bCidEnabled2,
	VAR(uint8, ANFCRL_VAR) bCid2,
	VAR(uint8, ANFCRL_VAR) bIsWtx2,
	VAR(uint8, ANFCRL_VAR) bWtxm2,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength2)
{
	/* S-Block PCB */
	pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] = PHPAL_I14443P4_SW_S_BLOCK2 | PHPAL_I14443P4_SW_S_BLOCK_RFU_BITS2;
	*pTxLength2 = 1U;

	/* Append CID if supported */
	if (bCidEnabled2 != 0U)
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2;
		pTxBuffer2[(*pTxLength2)++] = bCid2;
	}

	/* By default, PCB byte(bit 5 and 6) is configured to DESELECT command.
	 * Configure PCB byte to WTX(instead of DESELECT) and append WTXM based on bIsWtx2 input value.
	 */
	if (0U != (bIsWtx2))
	{
		pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] |= PHPAL_I14443P4_SW_PCB_WTX2;
		pTxBuffer2[(*pTxLength2)++] = bWtxm2;
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_SetConfig2(P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wConfig2,
    VAR(uint16, ANFCRL_VAR) wValue2)
{
	switch (wConfig2)
	{
	case PHPAL_I14443P4_CONFIG_OPE_MODE2:
	{
		pDataParams2->bOpeMode2 = (uint8) wValue2;
		break;
	}
	case PHPAL_I14443P4_CONFIG_BLOCKNO2:
	{
		if (wValue2 == 0U)
		{
			pDataParams2->bPcbBlockNum2 = 0U;
		}
		else
		{
			pDataParams2->bPcbBlockNum2 = 1U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_CID2:
	{
		if (0U != (wValue2 & 0xFF00U))
		{
			if ((wValue2 & 0x00FFU) > PHPAL_I14443P4_CID_MAX2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P42);
			}
			pDataParams2->bCidEnabled2 = 1;
			pDataParams2->bCid2 = (uint8) (wValue2);
		}
		else
		{
			pDataParams2->bCidEnabled2 = 0U;
			pDataParams2->bCid2 = 0U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_NAD2:
	{
		if (0U != (wValue2 & 0xFF00U))
		{
			pDataParams2->bNadEnabled2 = 1U;
			pDataParams2->bNad2 = (uint8) (wValue2);
		}
		else
		{
			pDataParams2->bNadEnabled2 = 0U;
			pDataParams2->bNad2 = 0U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_FWI2:
	{
		if (wValue2 > PHPAL_I14443P4_FWI_MAX2)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P42);
		}
		pDataParams2->bFwi2 = (uint8) (wValue2);
		break;
	}
	case PHPAL_I14443P4_CONFIG_FSI2:
	{
		if (((wValue2 >> 8U) > PHPAL_I14443P4_FRAMESIZE_MAX2) || ((wValue2 & 0xFFU) > PHPAL_I14443P4_FRAMESIZE_MAX2))
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P42);
		}

		pDataParams2->bFsdi2 = (uint8) (wValue2 >> 8U);
		pDataParams2->bFsci2 = (uint8) (wValue2);
		break;
	}
	case PHPAL_I14443P4_CONFIG_MAXRETRYCOUNT2:
	{
		pDataParams2->bMaxRetryCount2 = (uint8) (wValue2);
		break;
	}
	default:
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P42);
	}
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_GetConfig2(P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wConfig2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2)
{
	switch (wConfig2)
	{
	case PHPAL_I14443P4_CONFIG_BLOCKNO2:
	{
		if (pDataParams2->bPcbBlockNum2 == 0U)
		{
			*pValue2 = 0U;
		}
		else
		{
			*pValue2 = 1U;
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_CID2:
	{
		if (0U != (pDataParams2->bCidEnabled2))
		{
			*pValue2 = (uint16) (0x0100u | pDataParams2->bCid2);
		}
		else
		{
			*pValue2 = (uint16) (pDataParams2->bCid2);
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_NAD2:
	{
		if (0U != (pDataParams2->bNadEnabled2))
		{
			*pValue2 = (uint16) (0x0100u | pDataParams2->bNad2);
		}
		else
		{
			*pValue2 = (uint16) (pDataParams2->bNad2);
		}

		break;
	}
	case PHPAL_I14443P4_CONFIG_FWI2:
	{
		*pValue2 = (uint16) pDataParams2->bFwi2;
		break;
	}
	case PHPAL_I14443P4_CONFIG_FSI2:
	{
		*pValue2 = (uint16) ((uint16) (pDataParams2->bFsdi2) << 8U);
		*pValue2 |= (uint16) (pDataParams2->bFsci2);
		break;
	}
	case PHPAL_I14443P4_CONFIG_MAXRETRYCOUNT2:
	{
		*pValue2 = (uint16) pDataParams2->bMaxRetryCount2;
		break;
	}
	default:
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P42);
	}
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_Exchange2(
                                     P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                     VAR(uint16, ANFCRL_VAR) wOption2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                     VAR(uint16, ANFCRL_VAR) wTxLength2,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                     )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBufferOverflow2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wOptionBackUp2 = 0U;

	/* Used to build I/R/S block frames */
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIsoFrame2[3] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUseNad2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bForceSend2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRxOverlapped2[3] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wIsoFrameLen2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxOverlappedLen2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxStartPos2 = 0U;

	/* Used for Transmission */
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxBufferSize2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxBufferSize2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxBufferLen2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wInfLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wMaxPcdFrameSize2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wMaxCardFrameSize2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wPcb2 = 0u;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRetryCountRetransmit2 = 0U;

	/* For non-blocking implementation */
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBackUpState2 = 0U;

	if ((ppRxBuffer2 == NULL) || (pRxLength2 == NULL))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P42);
	}

	/* Option parameter check */
	if (0u != (wOption2 &  (uint16_t)~(uint16_t)
		(
		PH_EXCHANGE_BUFFERED_BIT2 | PH_EXCHANGE_LEAVE_BUFFER_BIT2 |
		PH_EXCHANGE_TXCHAINING2 | PH_EXCHANGE_RXCHAINING2 | PH_EXCHANGE_RXCHAINING_BUFSIZE2
		)))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P42);
	}

	switch (P4_Exchange_State2)
	{
	case PHPAL_I14443P4_EXCHANGE_START2:
		bBackUpState2 = 0U;
		wOptionBackUp2 = wOption2;
		/* No break */
	case PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX2:
		if (P4_Exchange_State2 == PHPAL_I14443P4_EXCHANGE_START2)
		{
			I14443P4_LOG2("--- EXCHANGE ISODEP START --\r\n");

			pDataParams2->pTmpRxBuff2 = *ppRxBuffer2;
			wIsoFrameLenBackup2 = 0;
			/* Retrieve HAL buffer sizes */
			statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE2, &wRxBufferSize2);
			PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
			statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER_BUFSIZE2, &wTxBufferSize2);
			PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);

			/* Retrieve maximum frame sizes */
			wMaxPcdFrameSize2 = bI14443p4_FsTable2[pDataParams2->bFsdi2] - (uint16) 2U;
			wMaxCardFrameSize2 = bI14443p4_FsTable2[pDataParams2->bFsci2] - (uint16) 2U;

			/* R(ACK) transmission in case of Rx-Chaining */
			if (((wOption2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_RXCHAINING2) || ((wOption2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_RXCHAINING_BUFSIZE2))
			{
				pDataParams2->bStateNow2 = PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2 | PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
			}
			/* I-Block transmission */
			else
			{
				/* Reset to default state if not in Tx-Mode */
				if ((pDataParams2->bStateNow2 & PH_EXCHANGE_MODE_MASK2) != PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2)
				{
					pDataParams2->bStateNow2 = PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2;
				}
			}

			P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX2;
			/* Reset receive length */
			*pRxLength2 = 0;
			pDataParams2->wTmpRxLen2 = 0;

			/* Reset RetryCount */
			bRetryCountRetransmit2 = 0U;

			/* Reset BufferOverflow flag */
			bBufferOverflow2 = 0U;
			pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_IDLE2;
			pDataParams2->wTmpTxLen2 = wTxLength2;
			pDataParams2->pTmpTxBuff2 = pTxBuffer2;
		}
		/* ******************************** */
		/*     I-BLOCK TRANSMISSION LOOP    */
		/* ******************************** */
		switch (pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_MASK2)
		{
			case PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2:
				if(0U == bBackUpState2)
				{
					/* Reset Preloaded bytes and ForceSend */
					wTxBufferLen2 = 0U;
					bForceSend2 = 0U;

					/* Retrieve Number of preloaded bytes */
					if (0U != (wOption2 & PH_EXCHANGE_LEAVE_BUFFER_BIT2))
					{
						statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER_LENGTH2, &wTxBufferLen2);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
					}

					/* Set initial INF length to (remaining) input data length */
					wInfLength2 = pDataParams2->wTmpTxLen2;

					/* Frame has already been preloaded -> IsoFrameLen is zero */
					if (wTxBufferLen2 > 0U)
					{
						/* do not generate the iso frame */
						wIsoFrameLen2 = 0;
					}
					/* Else evaluate IsoFrameLen*/
					else
					{
						/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
						if ((0U == ((pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))))
						{
							bUseNad2 = pDataParams2->bNadEnabled2;
						}
						else
						{
							bUseNad2 = 0U;
						}

						/* Evaluate frame overhead */
						wIsoFrameLen2 = 1U;
						if (0U != (bUseNad2))
						{
							++wIsoFrameLen2;
						}
						if (0U != (pDataParams2->bCidEnabled2))
						{
							++wIsoFrameLen2;
						}
					}

					/* Check if chaining is intended or not */
					if ((wOption2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_TXCHAINING2)
					{
						pDataParams2->bStateNow2 |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
					}
					else
					{
						pDataParams2->bStateNow2 &= (uint8) ~(uint8) PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
					}

					/* Force frame exchange if
					 a) the maximum frame size of the card has been reached;
					 */
					if ((wTxBufferLen2 + wIsoFrameLen2 + wInfLength2) > wMaxCardFrameSize2)
					{
						/* force frame exchange */
						bForceSend2 = 1;

						/* force chaining */
						pDataParams2->bStateNow2 |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;

						/* limit number of bytes to send */
						wInfLength2 = wMaxCardFrameSize2 - wTxBufferLen2 - wIsoFrameLen2;
					}

					/* Force frame exchange if
					 b) the TxBuffer is full;
					 */
					if ((0U != ((wOption2 & PH_EXCHANGE_BUFFERED_BIT2))) && ((wTxBufferLen2 + wIsoFrameLen2 + wInfLength2) >= wTxBufferSize2))
					{
						/* force frame exchange */
						bForceSend2 = 1;

						/* force chaining */
						pDataParams2->bStateNow2 |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
					}

					/* Generate / Buffer ISO frame */
					if (wIsoFrameLen2 > 0U)
					{
						/* Generate I-Block frame header */
						statusTmp2 = phpalI14443p4_Sw_BuildIBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, bUseNad2, pDataParams2->bNad2, pDataParams2->bPcbBlockNum2,
								(0U != (pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_CHAINING_BIT2)) ? 1U : 0U, bIsoFrame2, &wIsoFrameLen2);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
						bBackUpState2 = 1U;
					}
					else
					{
#ifdef NXPBUILD__PH_LOG_EX2
						I14443P4_LOG_BUF2(">>> I-BLOCK: ", bIsoFrame2, (uint8 )wIsoFrameLen2);
						if (wInfLength2 > 0U)
						{
							I14443P4_LOG_BUF2(">>> I-DATA: ", pDataParams2->pTmpTxBuff2, (uint8 )wInfLength2);
						}
#endif
						bBackUpState2 = 2U;
					}
				}

				if(1U == bBackUpState2)
				{
					/* Write Frame to HAL TxBuffer but do not perform Exchange */
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_BUFFER_FIRST2, bIsoFrame2, wIsoFrameLen2, NULL, NULL));
					PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);

					/* Retain the preloaded bytes from now on */
					wOption2 |= PH_EXCHANGE_LEAVE_BUFFER_BIT2;
					wOptionBackUp2 = wOption2;
#ifdef NXPBUILD__PH_LOG_EX2
					I14443P4_LOG_BUF2(">>> I-BLOCK: ", bIsoFrame2, (uint8 )wIsoFrameLen2);
					if (wInfLength2 > 0U)
					{
						I14443P4_LOG_BUF2(">>> I-DATA: ", pDataParams2->pTmpTxBuff2, (uint8 )wInfLength2);
					}
#endif
					bBackUpState2 = 2U;
				}

				if(2U == bBackUpState2)
				{
					/* Tx-Buffering mode (and no forced exchange) */
					if ((0U == bForceSend2) && (0U != (wOptionBackUp2 & PH_EXCHANGE_BUFFERED_BIT2)))
					{
						/* Preload the data into the TxBuffer */
						PH_CHECK_INPROCESS_FCT2(statusTmp2,
								phhalHw_Exchange2(pDataParams2->pHalDataParams2, (wOptionBackUp2 & (uint16)~(uint16)PH_EXCHANGE_MODE_MASK2), pDataParams2->pTmpTxBuff2, wInfLength2, NULL, NULL));
						I14443P4_LOG2("...\r\n");
						bBackUpState2 = 0U;
						P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
						return statusTmp2;
					}

					bBackUpState2 = 0U;
					/* Content has been buffered before */
					if (wTxBufferLen2 > 0U)
					{
						/* retrieve PCB byte */
						statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER_OFFSET2, 0x00);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
						statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER2, &wPcb2);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);

						/* Preloaded Data or ForceSend -> Modify PCB byte if necessary */
						if ((0U != bForceSend2) || ((wOptionBackUp2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_TXCHAINING2))
						{
							/* modify PCB byte */
							wPcb2 |= PHPAL_I14443P4_SW_PCB_CHAINING2;
							statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER2, wPcb2);
							PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
						}
					}
				}
				break;

			case PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2:
				if(0U == bBackUpState2)
				{
					/* Build R(ACK) frame */
					statusTmp2 = phpalI14443p4_Sw_BuildRBlock12(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pDataParams2->bPcbBlockNum2, 1, bIsoFrame2, &wIsoFrameLen2);
					PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
					bBackUpState2 = 1U;
					return PH_STATUS_INPROCESS2;
				}

				if(1U == bBackUpState2)
				{
					/* Write Frame to HAL TxBuffer but do not perform Exchange */
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_BUFFERED_BIT2, bIsoFrame2, wIsoFrameLen2, NULL, NULL));
					I14443P4_LOG_BUF2(">>> IsoFrame: ", bIsoFrame2, (uint8)wIsoFrameLen2);
					bBackUpState2 = 0U;
					PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);

					/* Retain the preloaded bytes from now on */
					wOption2 |= PH_EXCHANGE_LEAVE_BUFFER_BIT2;
					wOptionBackUp2 = wOption2;

					/* do not append any data */
					wInfLength2 = 0;
				}
				break;
				/* Should NEVER happen! */
			default:
				P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P42);
		}
		P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_ISO_HANDLING2;
		return PH_STATUS_INPROCESS2;
		/* No break */
	case PHPAL_I14443P4_EXCHANGE_ISO_HANDLING2:
		/* Perform Exchange using complete ISO handling */
		if(wIsoFrameLenBackup2 > 0U)
		{
			/* Continue ISO handling loop */
			PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4_Sw_IsoHandling2(
				pDataParams2,
				PH_EXCHANGE_DEFAULT2,
				bRetryCountRetransmit2,
				bIsoFrameBackup2,
				wIsoFrameLenBackup2,
				&pDataParams2->pTmpRxBuff2,
				&pDataParams2->wTmpRxLen2));
		}
		else
		{
			PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4_Sw_IsoHandling2(
				pDataParams2,
				wOptionBackUp2 & (uint16_t)~(uint16_t)PH_EXCHANGE_BUFFERED_BIT2,
				bRetryCountRetransmit2,
				pDataParams2->pTmpTxBuff2,
				wInfLength2,
				&pDataParams2->pTmpRxBuff2,
				&pDataParams2->wTmpRxLen2));
		}
		wOptionBackUp2 = 0U;
		*ppRxBuffer2 = pDataParams2->pTmpRxBuff2;
		*pRxLength2 = pDataParams2->wTmpRxLen2;
		/* Complete chaining if buffer is full */
		if (((status2 & PH_ERR_MASK2) == PH_ERR_BUFFER_OVERFLOW2) &&
			((wOption2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_RXCHAINING_BUFSIZE2))
		{
			/* Indicate Buffer Overflow */
			bBufferOverflow2 = 1;

			/* Toggle block number */
			pDataParams2->bPcbBlockNum2 ^= PHPAL_I14443P4_SW_PCB_BLOCKNR2;
		}
		/* Else bail out on error */
		else
		{
			PH_CHECK_ERROR_UPDATE_STATE2(status2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
		}

		/* Re-transmission in progress */
		if (0U != (pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT2))
		{
			/* Increment re-transmit RetryCount */
			++bRetryCountRetransmit2;

			/* Restore internal TxBuffer. */
			/* Necessary in case RxBuffer and TxBuffer are the same. */
			if (wTxBufferLen2 > 0U)
			{
				/* restore PCB byte */
				PH_CHECK_FAILURE_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER_OFFSET2, 0x00));
				PH_CHECK_FAILURE_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER2, wPcb2));

				/* restore TxBufferLen */
				PH_CHECK_FAILURE_FCT2(statusTmp2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TXBUFFER_LENGTH2,
					wTxBufferLen2));
			}

			/* Clear re-transmission bit */
			pDataParams2->bStateNow2 &= (uint8_t)~(uint8_t)PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT2;
		}
		/* No re-transmission in progress */
		else
		{
			/* Reset re-transmit RetryCount */
			bRetryCountRetransmit2 = 0;

			/* Chaining is active */
			if (pDataParams2->bStateNow2 == (PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2 | PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))
			{
				/* Bytes to send cannot be less than sent bytes */
				if (pDataParams2->wTmpTxLen2 < wInfLength2)
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P42);
				}

				/* Remove sent bytes from TxBuffer */
				pDataParams2->pTmpTxBuff2 = &pDataParams2->pTmpTxBuff2[wInfLength2];

				/* below if condition is added to make QAC compliant  */
				if(pDataParams2->wTmpTxLen2 > 0U)
				{
					pDataParams2->wTmpTxLen2 = pDataParams2->wTmpTxLen2 - wInfLength2;
				}
			}
			else
			{
				/* Do nothing */
			}

			/* Buffered / TxChaining mode -> finished after sending */
			if ((pDataParams2->wTmpTxLen2 == 0U) &&
				(
				((wOption2 & PH_EXCHANGE_BUFFERED_BIT2) > 0U) ||
				((wOption2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_TXCHAINING2)
				))
			{
				*ppRxBuffer2 = pDataParams2->pTmpRxBuff2;
				*pRxLength2 = pDataParams2->wTmpRxLen2;
				status2 = PH_ERR_SUCCESS2;
				break;
			}
			else
			{
				/* Do nothing */
			}
		}
		if((pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_MASK2) != PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2)
		{
			P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX2;
			/* Reset Preloaded bytes and ForceSend */
			wTxBufferLen2 = 0U;
			bForceSend2 = 0U;
		}
		else
		{
			P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX2;
			/* Overlap PCB */
			wRxOverlappedLen2 = 1;

			/* Overlap CID */
			if (0u != ((pDataParams2->pTmpRxBuff2)[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2))
			{
				wRxOverlappedLen2++;
			}

			/* Overlap NAD */
			if (0u != ((pDataParams2->pTmpRxBuff2)[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING2))
			{
				wRxOverlappedLen2++;
			}

			/* Reset RxStartPos */
			wRxStartPos2 = 0;
		}
		return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX2:
		if(0U == bBackUpState2)
		{
			/* ******************************** */
			/*      I-BLOCK RECEPTION LOOP      */
			/* ******************************** */
			/* Only allow receive state at this point */
			if ((pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_MASK2) != PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2)
			{
				P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P42);
			}

			/* Rule 2, ISO/IEC 14443-4:2008(E), PICC chaining */
			if (0U != (pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))
			{
				/* Skip overlapping / SUCCESS_CHAINING checks in case of BufferOverflow */
				if (0U == (bBufferOverflow2))
				{
					/* This is first chained response */
					if (wRxStartPos2 == 0U)
					{
						/* Special NAD chaining handling */
						/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
						if (0U != (pDataParams2->bNadEnabled2))
						{
							--wRxOverlappedLen2;
						}
					}

					/* Backup overlapped bytes */
					(void) phTools_memcpy2(bRxOverlapped2, &(pDataParams2->pTmpRxBuff2)[(pDataParams2->wTmpRxLen2 - wRxOverlappedLen2)], wRxOverlappedLen2);

					/* Calculate RxBuffer Start Position */
					wRxStartPos2 = pDataParams2->wTmpRxLen2 - wRxOverlappedLen2;

					/* Skip SUCCESS_CHAINING check for RXCHAINING_BUFSIZE mode */
					if ((wOption2 & PH_EXCHANGE_MODE_MASK2) != PH_EXCHANGE_RXCHAINING_BUFSIZE2)
					{
						/* Return with chaining status2 if the next chain may not fit into our buffer */
						if ((pDataParams2->wTmpRxLen2 + wMaxPcdFrameSize2) > wRxBufferSize2)
						{
							/* Adjust RxBuffer position */
							pDataParams2->pTmpRxBuff2 = &(pDataParams2->pTmpRxBuff2)[wRxOverlappedLen2];
							pDataParams2->wTmpRxLen2 = (pDataParams2->wTmpRxLen2) - wRxOverlappedLen2;

							P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_PAL_ISO14443P42); /* original: PH_ERR_SUCCESS_CHAINING */
						}
					}
				}

				/* Set RxBuffer Start Position */
				statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2, wRxStartPos2);
				PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);

				/* Prepare R(ACK) frame */
				statusTmp2 = phpalI14443p4_Sw_BuildRBlock12(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pDataParams2->bPcbBlockNum2, 1, bIsoFrame2, &wIsoFrameLen2);
				PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);
				bBackUpState2 = 1U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				bBackUpState2 = 2U;
				return PH_STATUS_INPROCESS2;
			}
		}
		else if(1U == bBackUpState2)
		{
			/* Perform Exchange using complete ISO handling */
			if(wIsoFrameLenBackup2 > 0U)
			{
				/* Continue ISO handling loop */
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4_Sw_IsoHandling2(
						pDataParams2,
						PH_EXCHANGE_DEFAULT2,
						bRetryCountRetransmit2,
						bIsoFrameBackup2,
						wIsoFrameLenBackup2,
						&pDataParams2->pTmpRxBuff2,
						&pDataParams2->wTmpRxLen2));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4_Sw_IsoHandling2(
						pDataParams2,
						PH_EXCHANGE_DEFAULT2,
						bRetryCountRetransmit2,
						bIsoFrame2,
						wIsoFrameLen2,
						&pDataParams2->pTmpRxBuff2,
						&pDataParams2->wTmpRxLen2));
			}
			*ppRxBuffer2 = pDataParams2->pTmpRxBuff2;
			*pRxLength2 = pDataParams2->wTmpRxLen2;
			/* Complete chaining if buffer is full */
			if (((status2 & PH_ERR_MASK2) == PH_ERR_BUFFER_OVERFLOW2) &&
				((wOption2 & PH_EXCHANGE_MODE_MASK2) == PH_EXCHANGE_RXCHAINING_BUFSIZE2))
			{
				/* Reset wRxStartPos2 */
				wRxStartPos2 = 0;

				/* Indicate Buffer Overflow */
				bBufferOverflow2 = 1;

				/* Toggle block number */
				pDataParams2->bPcbBlockNum2 ^= PHPAL_I14443P4_SW_PCB_BLOCKNR2;
			}
			/* Default behaviour */
			else
			{
				/* In case of buffer overflow error from HAL, reset the HAL Rx Buffer Start position */
				if ((pDataParams2->bOpeMode2 != RD_LIB_MODE_ISO2) && ((status2 & PH_ERR_MASK2) == PH_ERR_BUFFER_OVERFLOW2))
				{
					PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2, 0));
				}
				/* Bail out on error */
				PH_CHECK_ERROR_UPDATE_STATE2(status2, P4_Exchange_State2, PHPAL_I14443P4_EXCHANGE_START2);

				/* Restore overlapped INF bytes */
				(void)memcpy(&(*ppRxBuffer2)[wRxStartPos2], bRxOverlapped2, wRxOverlappedLen2); /* PRQA S 3354 */
				bBackUpState2 = 0U;
			}
		}
		/* No chaining -> reception finished */
		else if(2U == bBackUpState2)
		{
			/* Return data */
			if (0U == (bBufferOverflow2))
			{
				/* Special NAD chaining handling */
				/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
				if ((wRxStartPos2 > 0U) && (pDataParams2->bNadEnabled2 > 0U))
				{
					++wRxOverlappedLen2;
				}

				/* Do not return protocol bytes, advance to INF field */
				pDataParams2->pTmpRxBuff2 = &(pDataParams2->pTmpRxBuff2[wRxOverlappedLen2]);
				pDataParams2->wTmpRxLen2 = pDataParams2->wTmpRxLen2 - wRxOverlappedLen2;
				/* Reception successful */

				*ppRxBuffer2 = pDataParams2->pTmpRxBuff2;
				*pRxLength2 = pDataParams2->wTmpRxLen2;
				status2 = PH_ERR_SUCCESS2;
			}
			/* do not return any data in case of Buffer Overflow */
			else
			{
				*pRxLength2 = 0U;
				pDataParams2->wTmpRxLen2 = 0;
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_PAL_ISO14443P42);
			}

			/* Reception finished */
			pDataParams2->bStateNow2 = PHPAL_I14443P4_SW_STATE_FINISHED2;
			P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
			bBackUpState2 = 0U;
		}
		else
		{
			/* Should never happen */
			status2 = PH_ERR_INTERNAL_ERROR2;
			break;
		}

		if(pDataParams2->bStateNow2 != PHPAL_I14443P4_SW_STATE_FINISHED2)
		{
			P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX2;
			return PH_STATUS_INPROCESS2;
		}
		else
		{
			break;
		}
	}
    /* Dereference of NULL pointer should be avoided. */
    if ((status2 == PH_ERR_SUCCESS2) && (*ppRxBuffer2 == NULL))
    {
        P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
        return PH_ERR_INTERNAL_ERROR2;
    }
	P4_Exchange_State2 = PHPAL_I14443P4_EXCHANGE_START2;
	bBackUpState2 = 0U;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsoHandling2(
                                        P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint16, ANFCRL_VAR) wOption2,
                                        VAR(uint8, ANFCRL_VAR) bRetryCount2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                        VAR(uint16, ANFCRL_VAR) wTxLength2,
                                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                        )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bInvalidBlock2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCheckNad2;
    static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusBkUp2 = PH_ERR_SUCCESS2;
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLen2 = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxBufferStartPos2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTimeout2;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTimeoutMax2 = PHPAL_I14443P4_SW_FWT_MAX_US2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bResponseReceived2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bWtxm2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTimeoutInMs2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRetryCount02 = 0U;
    static VAR(uint8, ANFCRL_VAR) bIsoFrame2[3];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTimeoutPrev2 = 0U;
    static VAR(uint16, ANFCRL_VAR) wIsoFrameLen2 = 0u;
    static VAR(uint16, ANFCRL_VAR) wOptionTmp2 = PH_EXCHANGE_DEFAULT2;
    static VAR(phStatus_t2, ANFCRL_VAR) statusBeforeSendDESL2 = 0U;
    static VAR(I14443P4_DISPATCHER_RETURNCASE_t2, ANFCRL_VAR) PH_MEMLOC_REM2 bReturnCase2 = INITIAL_CASE2;
    static VAR(I14443P4_ISOMSG_StateType_t2, ANFCRL_VAR) P4_ISOMSG_NextState2 = PHPAL_I14443P4_STATE_IDLE2;

	switch (pDataParams2->eIsoMsgState2)
	{
		case PHPAL_I14443P4_STATE_IDLE2:
            status2 = PH_ERR_SUCCESS2;
			wOptionTmp2 = wOption2;
			/* Buffered Exchange is not allowed here */
			if (0U != (wOptionTmp2 & PH_EXCHANGE_BUFFERED_BIT2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P42);
			}
			/* Ignore custom modes */
			wOptionTmp2 &= (uint16) ~(uint16) PH_EXCHANGE_MODE_MASK2;
			wIsoFrameLenBackup2 = 0U;
			/* Reset response received flag */
			bResponseReceived2 = 0U;
			bRetryCount02 = bRetryCount2;
			bWtxm2 = 0U;

			pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SEND_BLOCK2;
			/* no break */
		case PHPAL_I14443P4_STATE_SEND_BLOCK2:
			/* Loops in case of an error */
			/* WTX Timeout - set temporary FWT */
			if (bWtxm2 > 0U)
			{
				/* Retrieve current timeout */
				status2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, &wTimeoutPrev2);

				/* Timeout is out of range, retrieve it in milliseconds */
				if ((status2 & PH_ERR_MASK2) == PH_ERR_PARAMETER_OVERFLOW2)
				{
					(void) phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, &wTimeoutPrev2);
					bTimeoutInMs2 = 1U;
				}
				else
				{
					PH_BREAK_ON_FAILURE2(status2);
					bTimeoutInMs2 = 0U;
				}

				if (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
				{
					dwTimeout2 = (((uint32) PHPAL_I14443P4_SW_FWT_MIN_US2
							* ((uint32) 1U << pDataParams2->bFwi2)) * (uint32) bWtxm2)
							+ (uint32) PHPAL_I14443P4_EXT_TIME_US2;
				}
				else
				{
					/* As per Digital Spec V1.1 req 15.3.2.1, NFC Forum Device SHALL wait at least FWTtemp + delta FWTT4AT for a Response */
					dwTimeout2 = (((uint32) PHPAL_I14443P4_SW_FWT_MIN_US2
							* ((uint32) 1U << pDataParams2->bFwi2)) * (uint32) bWtxm2)
							+ (uint32) PHPAL_I14443P4_SW_DELTA_FWT_US2;

					dwTimeoutMax2 = PHPAL_I14443P4_SW_NFC_FWT_MAX_US2;

					if (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2)
					{
						dwTimeout2 += (uint32) PHPAL_I14443P4_SW_DELTA_TPCD_US2;

						dwTimeoutMax2 = PHPAL_I14443P4_SW_EMVCO_FWT_MAX_US2;
					}
				}

				/* Limit timeout to FWT max */
				if (dwTimeout2 > dwTimeoutMax2)
				{
					dwTimeout2 = dwTimeoutMax2;
				}

				I14443P4_LOG2("~~~ SET TEMPORARY WTX \r\n");

				/* Set temporary WTX timeout */
                if (dwTimeout2 > 0xFFFFU)
                {
                    pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_MS2;
                }
                else
                {
                    pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_US2;
                }
                return PH_STATUS_INPROCESS2;
            }
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_MS2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, (uint16 )((dwTimeout2 / 1000U) + 1U)));
            PH_BREAK_ON_FAILURE2(statusTmp2);
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_US2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, (uint16 )dwTimeout2));
            PH_BREAK_ON_FAILURE2(statusTmp2);
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS2;
            /* no break */
        case PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS2:
            wIsoFrameLen2 = wTxLength2;

#ifdef NXPBUILD__PH_LOG_EX2
			if (PHPAL_I14443P4_SW_IS_I_BLOCK2(pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2]) != 0U)
			{
				(void) phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, &wTimeoutPrev2);
				I14443P4_LOG2(">>> P4_STATE_SEND_IBLOCK BlockNum:%d TIMEOUT:%d ms \r\n", pDataParams2->bPcbBlockNum2, wTimeoutPrev2);
				I14443P4_LOG_BUF2(">>> I-DATA: ", pTxBuffer2, (uint8 )wIsoFrameLen2);
			}
			else if (PHPAL_I14443P4_SW_IS_R_BLOCK2(pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2]) != 0U)
			{
				if ((pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2] & PHPAL_I14443P4_SW_PCB_NAK2) != 0U)
				{
					I14443P4_LOG2(">>> R(NACK) \r\n");
				}
				else
				{
					I14443P4_LOG2(">>> R(ACK) \r\n");
				}
			}
			else if (PHPAL_I14443P4_SW_IS_S_BLOCK2(pTxBuffer2[PHPAL_I14443P4_SW_PCB_POS2]) != 0U)
			{
				I14443P4_LOG2(">>> P4_STATE_SEND_SBLOCK \r\n");
			}
			else
			{
				; /* No action here */
			}
#endif
			bReturnCase2 = INITIAL_CASE2;
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_WAITRSP_BLOCK2;

            return PH_STATUS_INPROCESS2;
		case PHPAL_I14443P4_STATE_WAITRSP_BLOCK2:
			/* Call HAL exchange function */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, wOptionTmp2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2));
			statusBkUp2 = status2;

			I14443P4_LOG2("<<< P4_STATE_WAITRSP State:%0X Length:%d \r\n", status2, *pRxLength2);
			/* Reset Exchange Option */
			wOptionTmp2 = PH_EXCHANGE_DEFAULT2;
			wIsoFrameLenBackup2 = 0U;
			/* Reset transmission length */
			wIsoFrameLen2 = 0U;
			/* WTX Timeout - restore previous value */
			if (bWtxm2 > 0U)
			{
				I14443P4_LOG2("~~~ RESTORE WTX \r\n");
				/* Restore previous state and timeout after */
				if (0U == (bTimeoutInMs2))
				{
                    pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_US2;
				}
				else
				{
                    pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_MS2;
				}
	            return PH_STATUS_INPROCESS2;
			}
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_US2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, wTimeoutPrev2));
            PH_BREAK_ON_FAILURE2(statusTmp2);
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_MS2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, wTimeoutPrev2));
            PH_BREAK_ON_FAILURE2(statusTmp2);
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS2;
            /* no break*/
        case PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS2:
			bInvalidBlock2 = (uint8) PHPAL_I14443P4_SW_IS_INVALID_BLOCK_STATUS2(status2);

			if (0U == (bInvalidBlock2))
			{
				/* MIFARE compliance: force protocol error on NAK */
				if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS_INCOMPLETE_BYTE2)
				{
					*pRxLength2 = 0U;
					statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2, 0);
					PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, pDataParams2->eIsoMsgState2, PHPAL_I14443P4_STATE_IDLE2);
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
					break;
				}
				else
				{
					PH_CHECK_ERROR_UPDATE_STATE2(status2, pDataParams2->eIsoMsgState2, PHPAL_I14443P4_STATE_IDLE2);
				}
			}

			/* Reset defaults */
			bWtxm2 = 0U;

			/* Emvco: case_id TA404_04, TA411_04, TB404_04, TB411_04 */
			statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2, &wRxBufferStartPos2);
			PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, pDataParams2->eIsoMsgState2, PHPAL_I14443P4_STATE_IDLE2);
#ifdef NXPBUILD__PH_LOG_EX2
			/* For Logging data */
			if (status2 == PH_ERR_SUCCESS2)
			{
				I14443P4_LOG_BUF2("<<< ANY-BLOCK:", *ppRxBuffer2 + wRxBufferStartPos2, (uint8 )(*pRxLength2 - wRxBufferStartPos2));
			}
			else
			{
				I14443P4_LOG2("<<< ANY-BLOCK: -- -- \r\n");
			}
			/* End Logging data */
#endif
			/* Check for FSD */
			if (((*pRxLength2) - wRxBufferStartPos2) > (bI14443p4_FsTable2[pDataParams2->bFsdi2] - 2u))
			{
				(void) phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2, 0);
				*pRxLength2 = 0U;
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
				break;
			}
			/* Do not enter if we received an invalid block */
			if (0U == (bInvalidBlock2))
			{
				/* Signal that we've received something */
				bResponseReceived2 = 1U;

				/* Map receive buffer pointer to current data */
				pResp2 = &((*ppRxBuffer2)[wRxBufferStartPos2]);
				wRespLen2 = *pRxLength2 - wRxBufferStartPos2;

				/* I-Block handling */
				if (0u != (PHPAL_I14443P4_SW_IS_I_BLOCK2(pResp2[PHPAL_I14443P4_SW_PCB_POS2])))
				{
					I14443P4_LOG2("~~~ I-BLOCK HANDLING \r\n");
					/* Rule 2/10, ISO/IEC 14443-4:2008(E) */
					if (pDataParams2->bStateNow2 == (PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2 | PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))
					{
						/* Protocol violation */
						bInvalidBlock2 = 1U;
					}
					else
					{
						/* Evaluate if NAD should be present */
						/* 7.1.1.3 c), ISO/IEC 14443-4:2008(E), "During chaining the NAD shall only be transmitted in the first block of chain." */
						if ((pDataParams2->bNadEnabled2 > 0U) && (0U == ((pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))))
						{
							bCheckNad2 = 1U;
						}
						else
						{
							bCheckNad2 = 0U;
						}

						/* Check if I-Block is valid */
						statusTmp2 = phpalI14443p4_Sw_IsValidIBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, bCheckNad2, pDataParams2->bNad2, pResp2, wRespLen2);

						/* Block number is equal, I-Block Rx mode is active */
						if (((statusTmp2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2) && (PHPAL_I14443P4_SW_IS_BLOCKNR_EQUAL2(pResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U))
						{
							/* Switch from Tx-Mode to Rx-Mode */
							if ((pDataParams2->bStateNow2 & PHPAL_I14443P4_SW_STATE_MASK2) == PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2)
							{
								pDataParams2->bStateNow2 = PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2;
								bReturnCase2 = TXMODE_NORMAL_SWITH_TO_RXMODE2;
								/* Set chaining bit if card is chaining */
								if (0u != (PHPAL_I14443P4_SW_IS_CHAINING2(pResp2[PHPAL_I14443P4_SW_PCB_POS2])))
								{
									pDataParams2->bStateNow2 |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
								}
								/* Clear chaining bit otherwise */
								else
								{
									pDataParams2->bStateNow2 &= (uint8) ~(uint8) PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
									/* RETURN CASE 1-2 */
									bReturnCase2 = TXMODE_NORMAL_FINISH2; /* Finish */
								}
							}
							/* Rx-Mode */
							else
							{
								/* Set chaining bit if card is chaining */
								if (0u != (PHPAL_I14443P4_SW_IS_CHAINING2(pResp2[PHPAL_I14443P4_SW_PCB_POS2])))
								{
									pDataParams2->bStateNow2 |= PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
									if (PH_ERR_BUFFER_OVERFLOW2 == (statusBkUp2 & PH_ERR_MASK2))
									{
										/* RETURN CASE 2-5 */
										bReturnCase2 = RXMODE_ABNORMAL_BUFFER_OVERFLOW2;
									}
									else
									{
										/* RETURN CASE 2-1 */
										bReturnCase2 = RXMODE_NORMAL_RECEIVING_IBLOCK2;
									}
								}
								/* Clear chaining bit otherwise */
								else
								{
									pDataParams2->bStateNow2 &= (uint8) ~(uint8) PHPAL_I14443P4_SW_STATE_CHAINING_BIT2;
									/* RETURN CASE 2-2 */
									bReturnCase2 = RXMODE_NORMAL_FINISH2;
								}
							}
							/* Rule B, ISO/IEC 14443-4:2008(E), toggle Block number */
							pDataParams2->bPcbBlockNum2 ^= PHPAL_I14443P4_SW_PCB_BLOCKNR2;
							/* Overlap CID */
							I14443P4_LOG_BUF2("~~~ P4_SW_PCB_POS: ", pResp2+PHPAL_I14443P4_SW_PCB_POS2, 1U);

						}
						/* We received an invalid block */
						else
						{
							/* Protocol violation */
							bInvalidBlock2 = 1U;
						}
					}
				}
				/* R(ACK) handling */
				else if ((PHPAL_I14443P4_SW_IS_R_BLOCK2(pResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U) && (PHPAL_I14443P4_SW_IS_ACK2(pResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U))
				{
					I14443P4_LOG2("~~~ R(ACK) HANDLING: CurrentBN:%d \r\n", pDataParams2->bPcbBlockNum2);
					/* Check if R-Block is valid */
					status2 = phpalI14443p4_Sw_IsValidRBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pResp2, wRespLen2);

					/* R-Block invalid or not in transmission mode */
					if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
					{
						/* Protocol violation */
						bInvalidBlock2 = 1U;
					}
					else
					{
						/* Block number is equal */
						if (0u != (PHPAL_I14443P4_SW_IS_BLOCKNR_EQUAL2(pResp2[PHPAL_I14443P4_SW_PCB_POS2])))
						{
							/* Continue TX chaining */
							if (pDataParams2->bStateNow2 == (PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2 | PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))
							{
								/* Rule B, ISO/IEC 14443-4:2008(E), toggle Block number */
								pDataParams2->bPcbBlockNum2 ^= PHPAL_I14443P4_SW_PCB_BLOCKNR2;
								/* RETURNCASE 1-4 */
								bReturnCase2 = TXMODE_NORMAL_NEXT_TRANSMISSION2;
							}
							/* Not in chaining mode */
							else
							{
								/* Protocol violation */
								bInvalidBlock2 = 1U;
							}
						}
						/* Rule 6, ISO/IEC 14443-4:2008(E), unequal block number */
						else
						{
							I14443P4_LOG2("~~~ R(ACK) unequal block number \r\n");
							/* Limit this behaviour with bMaxRetryCount2, bRetry count is set by the caller in this case */
							if ((bRetryCount02 > pDataParams2->bMaxRetryCount2) || (pDataParams2->bMaxRetryCount2 == 0U))
							{
								/* Protocol violation */
								bInvalidBlock2 = 1U;
							}
							/* Send last I-Block again */
							else
							{
								pDataParams2->bStateNow2 |= PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT2;
								/* RETURNCASE 1-5, Re-Transmit */
								bReturnCase2 = TXMODE_ABNORMAL_RE_TRANSMISSION2;
							}
						}
					}
				}
				/* S(WTX) handling */
				else if ((PHPAL_I14443P4_SW_IS_S_BLOCK2(pResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U) && (PHPAL_I14443P4_SW_IS_WTX2(pResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U))
				{
					I14443P4_LOG2("~~~ S(WTX) HANDLING \r\n");
					/* Check if S-Block is valid */
					status2 = phpalI14443p4_Sw_IsValidSBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pResp2, wRespLen2);

					/* Rule 3, ISO/IEC 14443-4:2008(E), S(WTX) handling */
					if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
					{
						/* Retrieve WTXM */
						bWtxm2 = pResp2[wRespLen2 - 1u];

						/* Ignore and clear the Power Level Indication */
						bWtxm2 &= 0x3FU;

						/* Treat invalid WTXM value as protocol error, do not perform error correction. */
						if ((bWtxm2 == 0U) || (bWtxm2 > 59U))
						{
							status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
							break;
						}

						/* Generate S(WTX) frame */
						statusTmp2 = phpalI14443p4_Sw_BuildSBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, 1, bWtxm2, bIsoFrame2, &wIsoFrameLen2);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, pDataParams2->eIsoMsgState2, PHPAL_I14443P4_STATE_IDLE2);
						/* Prepare S(WTX) frame, Rule 3 */
						bReturnCase2 = PROCESS_CMD_SWTX2;
					}
					/* We received an invalid block */
					else
					{
						/* Protocol violation */
						bInvalidBlock2 = 1U;
					}
				}
				/* We received an invalid block */
				else
				{
					/* Protocol violation */
					bInvalidBlock2 = 1U;
				}

				/* Protocol violation */
				if (0U != (bInvalidBlock2))
				{
					bReturnCase2 = HANDLING_ERROR_PROTOCOL2;
					if (pDataParams2->bMaxRetryCount2 > 0U)
					{
						bRetryCount02 = pDataParams2->bMaxRetryCount2;
					}
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
					statusBeforeSendDESL2 = status2;
                    pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT2;
                    return PH_STATUS_INPROCESS2;
				}
				/* Reset retry counter on no error */
				else
				{
					bRetryCount02 = 0U;
				}
			}
			/* Invalid Block received */
			else
			{
				I14443P4_LOG2("~~~ X-BLOCK (INVALID) HANDLING \r\n");
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
				if ((bRetryCount02 >= pDataParams2->bMaxRetryCount2) && (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2))
				{
					if (pDataParams2->bMaxRetryCount2 > 0U)
					{
						/* backup retry count */
						bRetryCount02 = pDataParams2->bMaxRetryCount2;

						/* set retry count to zero to send only one S(DESELECT) */
						pDataParams2->bMaxRetryCount2 = 0;

						P4_ISOMSG_NextState2 = PHPAL_I14443P4_STATE_DESEL2;
						statusBeforeSendDESL2 = status2;
					}
					else
					{
						P4_ISOMSG_NextState2 = PHPAL_I14443P4_STATE_IDLE2;
					}
					/* RETURNCASE 9-1 */
					bReturnCase2 = HANDLING_ERROR_MAX_RETRY_OCCURS2;
					pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE2;
					return PH_STATUS_INPROCESS2;
				}
				else if (bRetryCount02 <= pDataParams2->bMaxRetryCount2)
				{
					/* Rule 5, ISO/IEC 14443-4:2008(E) */
					if (pDataParams2->bStateNow2 == (PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2 | PHPAL_I14443P4_SW_STATE_CHAINING_BIT2))
					{
						/* RETURNCASE 2-3 */
						bReturnCase2 = RXMODE_ABNORMAL_SEND_RACK_FOR_RETRY2;
						/* Generate R(ACK) frame */
						statusTmp2 = phpalI14443p4_Sw_BuildRBlock12(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pDataParams2->bPcbBlockNum2, 1, bIsoFrame2, &wIsoFrameLen2);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, pDataParams2->eIsoMsgState2, PHPAL_I14443P4_STATE_IDLE2);
					}
					/* Rule 4, ISO/IEC 14443-4:2008(E) */
					else
					{
						/* Generate R(NAK) frame */
						statusTmp2 = phpalI14443p4_Sw_BuildRBlock12(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pDataParams2->bPcbBlockNum2, 0, bIsoFrame2, &wIsoFrameLen2);
						PH_CHECK_ERROR_UPDATE_STATE2(statusTmp2, pDataParams2->eIsoMsgState2, PHPAL_I14443P4_STATE_IDLE2);
						/* RETURNCASE 1-3 */
						bReturnCase2 = TXMODE_ABNORMAL_TIMEOUT_RETRY2RCV_IBLOCK2;
					}
				}
				/* Bail out if the max. retry count is reached */
				else
				{
					bReturnCase2 = HANDLING_ERROR_MAX_RETRY_OCCURS2;
					/* Deselect card if behaviour is enabled */
					if (pDataParams2->bMaxRetryCount2 > 0U)
					{
						/* backup retry count */
						bRetryCount02 = pDataParams2->bMaxRetryCount2;

						/* set retry count to zero to send only one S(DESELECT) */
						pDataParams2->bMaxRetryCount2 = 0;

						statusBeforeSendDESL2 = status2;
                        pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT2;
                        return PH_STATUS_INPROCESS2;
					}
					pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE2;
					return PH_STATUS_INPROCESS2;
				}

				/* Increment retry count */
				++bRetryCount02;
			}

			/* Map TxBuffer to ISO Frame buffer for next loop */
			if (wIsoFrameLen2 > 0U)
			{
				phTools_memcpy2(bIsoFrameBackup2, bIsoFrame2, wIsoFrameLen2);
			}
			wIsoFrameLenBackup2 = wIsoFrameLen2;
			/* Loop as long as we generate transmissions */
			if (0U != wIsoFrameLen2)
			{
				pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_SEND_BLOCK2;
				return PH_STATUS_INPROCESS2;
			}
			P4_ISOMSG_NextState2 = PHPAL_I14443P4_STATE_IDLE2;
			pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE2;
			return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT2:
            P4_ISOMSG_NextState2 = PHPAL_I14443P4_STATE_DESEL2;
            pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE2;
            /* no break */
		case PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE2:
			switch (bReturnCase2)
			{
				case INITIAL_CASE2:
					break;
				case TXMODE_NORMAL_FINISH2:
					/* Getting first I-BLOCK (no chaining), Finish ISO-DEP Messaging */
					I14443P4_LOG2("^^^ [CASE 12: TX-MODE RETURN NORMAL - FINISH]\r\n");
					break;
				case TXMODE_NORMAL_SWITH_TO_RXMODE2:
					I14443P4_LOG2("^^^ [CASE 11: TX-MODE NORMAL - CONTINOUS TO RX-MODE]\r\n");
					break;
				case TXMODE_ABNORMAL_TIMEOUT_RETRY2RCV_IBLOCK2:
					(void) phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, &wTimeoutPrev2);
					I14443P4_LOG2("^^^ [CASE 13: TX-MODE ABNORMAL TRY AGAIN (TO RCV FIRST I-BLOCK) TIMEOUT:%d ms]\r\n", wTimeoutPrev2);
					break;
				case TXMODE_NORMAL_NEXT_TRANSMISSION2:
					I14443P4_LOG2("^^^ [CASE 14: TX-MODE NORMAL, NEXT-TRANSMISSION ]\r\n");
					break;
				case TXMODE_ABNORMAL_RE_TRANSMISSION2:
					I14443P4_LOG2("^^^ [CASE 15: TX-MODE ABNORMAL, RE-TRANSMISSION ]\r\n");
					break;
				case RXMODE_NORMAL_RECEIVING_IBLOCK2:
					I14443P4_LOG2("^^^ [CASE 21: RX-MODE RECEIVING DATA FROM CARD ]\r\n");
					/* Return with chaining status2 if the next chain may not fit into our buffer */
					break;
				case RXMODE_NORMAL_FINISH2:
					I14443P4_LOG2("^^^ [CASE 22: RX-MODE RETURN NORMAL - FINISH]\r\n");
					break;
				case RXMODE_ABNORMAL_SEND_RACK_FOR_RETRY2:
					I14443P4_LOG2("^^^ [CASE 23: RX-MODE RETRY SEND R(ACK) AGAIN ]\r\n");
					break;
				case RXMODE_NORMAL_SEND_RACK_FOR_RECEIVING2:
					I14443P4_LOG2("[CASE 24: RX-MODE RETURN NORMAL - SEND R(ACK) FOR CONTINUE RECEIVING]\r\n");
					break;
				case RXMODE_ABNORMAL_BUFFER_OVERFLOW2:
					I14443P4_LOG2("^^^ [CASE 25: RX-MODE RETURN ABNORMAL - RECEIVING BUFFER OVERFLOW ]\r\n");
					break;
				case PROCESS_CMD_SWTX2:
					I14443P4_LOG2("^^^ [CASE 30: PROCESS S(WTX) FROM CARD, SET WTX ]\r\n");
					break;
				case HANDLING_ERROR_PROTOCOL2:
					I14443P4_LOG2("^^^ [CASE 90: PROTOCOL ERROR ]\r\n");
					break;
				case HANDLING_ERROR_MAX_RETRY_OCCURS2:
					I14443P4_LOG2("^^^ [CASE 91: ABNORMAL MAX RETRIES ERROR ]\r\n");
					break;
			}
			if (P4_ISOMSG_NextState2 == PHPAL_I14443P4_STATE_DESEL2)
			{
				pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_DESEL2;
				return PH_STATUS_INPROCESS2;
			}
			break;

		case PHPAL_I14443P4_STATE_DESEL2:
		    /* Send S(DESELECT) */
			status2 = phpalI14443p4_Sw_Deselect2(pDataParams2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return PH_STATUS_INPROCESS2;
			}
			I14443P4_LOG2("-- DESELECT IF ERROR  --\r\n");
			/* restore retry count setting */
			pDataParams2->bMaxRetryCount2 = bRetryCount02;
			status2 = statusBeforeSendDESL2;
			/* Return ERR_RECOVERY_FAILED if some response has been received before */
			if (0U != (bResponseReceived2))
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
			}
			break;
		default:
			status2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}
    pDataParams2->eIsoMsgState2 = PHPAL_I14443P4_STATE_IDLE2;
    statusBkUp2 = PH_ERR_SUCCESS2;
    dwTimeout2 = 0U;
    bTimeoutInMs2 = 0U;
    if(statusTmp2 != PH_ERR_SUCCESS2)
    {
    	status2 = statusTmp2;
    }
	/* Reset RxBuffer Start Position */
	PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2, 0));
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_Deselect2(P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bInvalidBlock2 = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLen2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIsoFrame2[3] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wIsoFrameLen2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bResponseReceived2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRetries2 = 0U;

	switch (pDataParams2->eDeselState2)
	{
	case PHPAL_I14443P4_DESEL_IDLE2:
		/* Set DESELECT timeout */
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
		                                                  PHPAL_I14443P4_SW_FWT_DESELECT_US2 + PHPAL_I14443P4_EXT_TIME_US2));
		PH_BREAK_ON_FAILURE2(status2);
		/* Retrieve max. retry count */
		wRetries2 = (uint16) pDataParams2->bMaxRetryCount2 + 1U;

		/* Build S(DESELECT) frame */
		PH_CHECK_FAILURE_FCT2(status2, phpalI14443p4_Sw_BuildSBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, 0, 0, bIsoFrame2, &wIsoFrameLen2));

		/* Reset response received flag */
		bResponseReceived2 = 0;
		pDataParams2->eDeselState2 = PHPAL_I14443P4_DESEL_SEND2;
		I14443P4_LOG_BUF2(">>> P4_STATE_CMD_DESELECT_SEND:", bIsoFrame2, (uint8 )wIsoFrameLen2);
		/* no break */

	case PHPAL_I14443P4_DESEL_SEND2:
		/* Do as long as invalid responses are received
		 and the retry counter has not reached zero.*/
		/* Send the S(DESELECT) request */
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, bIsoFrame2, wIsoFrameLen2, &pResp2, &wRespLen2));

#ifdef NXPBUILD__PH_LOG_EX2
		if (status2 != PH_ERR_SUCCESS2)
		{
			I14443P4_LOG2("<<< P4_STATE_CMD_DESELECT_RESPONSE Status:%0X \r\n", status2);
		}
		else
		{
			I14443P4_LOG_BUF2("<<< P4_STATE_CMD_DESELECT_RESPONSE:", pResp2, (uint8 )wRespLen2);
		}
#endif
		/* Status --> InvalidBlock mapping */
		bInvalidBlock2 = (uint8) PHPAL_I14443P4_SW_DESELECT_IS_INVALID_BLOCK_STATUS2(status2);

		if (0U == (bInvalidBlock2))
		{
			/* Check for other errors */
			PH_BREAK_ON_FAILURE2(status2);

			/* Signal that we've received something */
			bResponseReceived2 = 1;

			/* Rule 8, ISO/IEC 14443-4:2008(E), "...the S(DESELECT) request may be re-transmitted..." */
			if ((wRespLen2 == wIsoFrameLen2) && (wRespLen2 > 0U) && (wRespLen2 < 3U))
			{
				/* Mask out Power-Level-Indication */
				if (0U != (pDataParams2->bCidEnabled2))
				{
					pResp2[1] &= 0x3FU;
				}

				/* Verify S(DESELECT) Response */
				if (memcmp(bIsoFrame2, pResp2, wRespLen2) != 0)
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
				}
			}
			else
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
			}
		}
		--wRetries2;
		/* Retry as long as necessary */
		if ((0U != bInvalidBlock2) && (wRetries2 != 0U))
		{
			pDataParams2->eDeselState2 = PHPAL_I14443P4_DESEL_SEND2;
			return PH_STATUS_INPROCESS2;
		}
		/* Operation not successful */
		if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
		{
			/* Return ERR_RECOVERY_FAILED if some response has been received before (bMaxRetryCount2 = 0 suppresses the retry behaviour) */
			if ((pDataParams2->bMaxRetryCount2 > 0U) && (bResponseReceived2 > 0U))
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
			}
		}

		/* Apply default parameters */
		(void) phpalI14443p4_Sw_ResetProtocol2(pDataParams2);
		break;
	}

	/* Reset variables */
	bIsoFrame2[0] = 0U;
	bIsoFrame2[1] = 0U;
	bIsoFrame2[2] = 0U;
	wIsoFrameLen2 = 0U;
	bResponseReceived2 = 0U;
	wRetries2 = 0U;
	pResp2 = NULL;
	wRespLen2 = 0U;
	pDataParams2->eDeselState2 = PHPAL_I14443P4_DESEL_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_PresCheck2(
                                      P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                      )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIsoFrame2[3] = {0U};
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pIsoFrameResp2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wIsoFrameLen2 = 0U;

	switch (pDataParams2->ePresCheckState2)
	{
	case PHPAL_I14443P4_PRESCHECK_SEND2:
		/* Build R(NAK) frame */
		PH_CHECK_FAILURE_FCT2(status2, phpalI14443p4_Sw_BuildRBlock12(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pDataParams2->bPcbBlockNum2, 0, bIsoFrame2, &wIsoFrameLen2));

		I14443P4_LOG_BUF2(">>> P4_STATE_CMD_RNAK_SEND: ", bIsoFrame2, (uint8 )wIsoFrameLen2);
		pDataParams2->ePresCheckState2 = PHPAL_I14443P4_PRESCHECK_WAITRSP2;

		return PH_STATUS_INPROCESS2;

	case PHPAL_I14443P4_PRESCHECK_WAITRSP2:
		/* Send frame */
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, bIsoFrame2, wIsoFrameLen2, &pIsoFrameResp2, &wIsoFrameLen2));

#ifdef NXPBUILD__PH_LOG_EX2
		if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
		{
			I14443P4_LOG2("<<< P4_STATE_CMD_RNAK_WAITRSP:%0X  \r\n", status2);
		}
		else
		{
			I14443P4_LOG_BUF2("<<< P4_STATE_CMD_RNAK_WAITRSP: ", pIsoFrameResp2, (uint8 )wIsoFrameLen2);
		}
#endif /* NXPBUILD__PH_LOG_EX2 */

		/* Check if we got a valid R(ACK) response */
		if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
		{
			if ((PHPAL_I14443P4_SW_IS_R_BLOCK2(pIsoFrameResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U) && (PHPAL_I14443P4_SW_IS_ACK2(pIsoFrameResp2[PHPAL_I14443P4_SW_PCB_POS2]) > 0U))
			{
				status2 = phpalI14443p4_Sw_IsValidRBlock2(pDataParams2->bCidEnabled2, pDataParams2->bCid2, pIsoFrameResp2, wIsoFrameLen2);
			}
			else
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P42);
			}
		}
		break;
	}

	/* Reset variables */
	bIsoFrame2[0] = 0U;
	bIsoFrame2[1] = 0U;
	bIsoFrame2[2] = 0U;
	pIsoFrameResp2 = NULL;
	wIsoFrameLen2 = 0U;
	pDataParams2->ePresCheckState2 = PHPAL_I14443P4_PRESCHECK_SEND2;
	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION_C2== 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

#ifdef __cplusplus
}
#endif
