/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2023
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
 *   @file    phacDiscLoop2.c
 *   @version 1.0.0
 *
 *   @brief   AUTOSAR acDiscLoop - API usage in common use cases.
 *   @details Functions need to be implemented by application code.
 *
 *   @addtogroup phacDiscLoop Discovery Loop
 *   @ingroup phac
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
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/

#include <ph_Status2.h>
#include <ph_RefDefs2.h>
#include <phacDiscLoop2.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "Sw/phacDiscLoop_Sw2.h"

 
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 ==================================================================================================*/
/**
 * @file           phacDiscLoop2.c
 * @implements     DESIGN001, DESIGN002
 */
#define PHACDISCLOOP_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
 *                                     FILE VERSION CHECKS
 ==================================================================================================*/

/* Check if current file and phacDiscLoop2.h header file are of the same vendor */
#if (PHACDISCLOOP_VENDOR_ID_C2 != PHACDISCLOOP_VENDOR_ID2)
#error "phacDiscLoop2.c and phacDiscLoop2.h have different vendor ids"
#endif
	/* Check if current file and phacDiscLoop2.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_AR_RELEASE_REVISION_VERSION2))
#error "AutoSar Version Numbers of phacDiscLoop2.c and phacDiscLoop2.h are different"
#endif
	/* Check if current file and phacDiscLoop2.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_PATCH_VERSION2))
#error "Software Version Numbers of phacDiscLoop2.c and phacDiscLoop2.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
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

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 ==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP2
#ifndef NXPRDLIB_REM_GEN_INTFS2
#define ANFCRL_START_SEC_CODE
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION_C2== 0))
#include <MemMap.h>
#else
#include <AnfcRL_MemMap.h>
#endif

	FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Run2(
			P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(phacDiscLoop_Sw_EntryPoints_t2, ANFCRL_VAR) bEntryPoint2)
	{
		VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

		PH_ASSERT_NULL2 (pDataParams2);

		/* Check data parameters */
		if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_AC_DISCLOOP2)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
		}

		/* Select the active layer to perform the action */
		switch (PH_GET_COMPID2(pDataParams2))
		{
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
			case PHAC_DISCLOOP_SW_ID2:
			status2 = phacDiscLoop_Sw_Run2((phacDiscLoop_Sw_DataParams_t2*)pDataParams2, bEntryPoint2);
			break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
			default:
			status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
			break;
		}
		return status2;
	}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_GetConfig2(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
VAR(uint16, ANFCRL_VAR) wConfig2,
P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pValue2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_AC_DISCLOOP2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
	}

	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
		case PHAC_DISCLOOP_SW_ID2:
		status2 = phacDiscLoop_Sw_GetConfig2((phacDiscLoop_Sw_DataParams_t2*)pDataParams2, wConfig2, pValue2);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_SetConfig2(
P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
VAR(uint16, ANFCRL_VAR) wConfig2,
VAR(uint16, ANFCRL_VAR) wValue2
)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_AC_DISCLOOP2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
	}

	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
		case PHAC_DISCLOOP_SW_ID2:
		status2 = phacDiscLoop_Sw_SetConfig2((phacDiscLoop_Sw_DataParams_t2*)pDataParams2, wConfig2, wValue2);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_ActivateCard2(
P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
VAR(uint8, ANFCRL_VAR) bTagType2,
VAR(uint8, ANFCRL_VAR) bTagIndex2
)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_AC_DISCLOOP2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
	}

	switch(PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
		case PHAC_DISCLOOP_SW_ID2:
		status2 = phacDiscLoop_Sw_ActivateCard2((phacDiscLoop_Sw_DataParams_t2*)pDataParams2, bTagType2, bTagIndex2);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_CfgPollSeq2(
P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiscloopCfgPollSeq2
)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pDiscloopCfgPollSeq2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_AC_DISCLOOP2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,PH_COMP_AC_DISCLOOP2);
    }

    /* Select the active layer to perform the action */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
        case PHAC_DISCLOOP_SW_ID2:
            status2 = phacDiscLoop_Sw_CfgPollSeq2(pDataParams2, pDiscloopCfgPollSeq2);
            break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
        default:
            status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
            break;
    }
    return status2;
}


#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */
#endif /* NXPBUILD__PHAC_DISCLOOP2 */

 
#ifdef __cplusplus
}
#endif
