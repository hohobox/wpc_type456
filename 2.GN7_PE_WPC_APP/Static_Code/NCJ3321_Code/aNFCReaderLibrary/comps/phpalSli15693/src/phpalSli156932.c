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
*   @file    phpalSli156932.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693 - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalSli156932 ISO/IEC 15693 
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

#include <phpalSli156932.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
#include "Sw/phpalSli15693_Sw2.h"
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
#ifdef NXPBUILD__PHPAL_SLI156932
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalSli156932.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalSli156932.h header file are of the same vendor */
#if (PHPALSLI15693_VENDOR_ID_C2 != PHPALSLI15693_VENDOR_ID2)
    #error "phpalSli156932.c and phpalSli156932.h have different vendor ids"
#endif
/* Check if current file and phpalSli156932.h header file are of the same Autosar version */
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C2    != PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C2    != PHPALSLI15693_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALSLI15693_AR_RELEASE_REVISION_VERSION_C2 != PHPALSLI15693_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalSli156932.c and phpalSli156932.h are different"
#endif
/* Check if current file and phpalSli156932.h header file are of the same Software version */
#if ((PHPALSLI15693_SW_MAJOR_VERSION_C2 != PHPALSLI15693_SW_MAJOR_VERSION2) || \
     (PHPALSLI15693_SW_MINOR_VERSION_C2 != PHPALSLI15693_SW_MINOR_VERSION2) || \
     (PHPALSLI15693_SW_PATCH_VERSION_C2 != PHPALSLI15693_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalSli156932.c and phpalSli156932.h are different"
#endif
#endif /* NXPBUILD__PHPAL_SLI156932 */
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
#ifdef NXPBUILD__PHPAL_SLI156932
#ifndef  NXPRDLIB_REM_GEN_INTFS2

#define ANFCRL_START_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Inventory2(
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                 VAR(uint8, ANFCRL_VAR) bFlags2,
                 VAR(uint8, ANFCRL_VAR) bAfi2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                 VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2
)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
	if (0U != (bMaskBitLength2)) PH_ASSERT_NULL2 (pMask2);
	PH_ASSERT_NULL2 (pDsfid2);
	PH_ASSERT_NULL2 (pUid2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_Inventory2(
			(phpalSli15693_Sw_DataParams_t2*)pDataParams2,
			bFlags2,
			bAfi2,
			pMask2,
			bMaskBitLength2,
			pDsfid2,
			pUid2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_SendEof2(
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                 VAR(uint8, ANFCRL_VAR) bOption2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
								 )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pDsfid2);
	PH_ASSERT_NULL2 (pUid2);
	PH_ASSERT_NULL2 (pUidLength2);
	PH_ASSERT_NULL2 (pData2);
	PH_ASSERT_NULL2 (pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_SendEof2(
			(phpalSli15693_Sw_DataParams_t2*)pDataParams2,
			bOption2,
			pDsfid2,
			pUid2,
			pUidLength2,
			pData2,
			pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_StayQuiet2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
								   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_StayQuiet2((phpalSli15693_Sw_DataParams_t2*)pDataParams2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Select2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
								)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_Select2((phpalSli15693_Sw_DataParams_t2*)pDataParams2 );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_ResetToReady2(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
									  )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_ResetToReady2((phpalSli15693_Sw_DataParams_t2*)pDataParams2 );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Exchange2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wOption2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                  VAR(uint16, ANFCRL_VAR) wTxLength2,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
								  )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
	if (0U != (wTxLength2)) PH_ASSERT_NULL2 (pTxBuffer2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_Exchange2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2 );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_ActivateCard2(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint8, ANFCRL_VAR) bOption2,
                    VAR(uint8, ANFCRL_VAR) bFlags2,
                    VAR(uint8, ANFCRL_VAR) bAfi2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
								   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
	if (0U != (bMaskBitLength2)) PH_ASSERT_NULL2 (pMask2);
	PH_ASSERT_NULL2 (pDsfid2);
	PH_ASSERT_NULL2 (pUid2);
	PH_ASSERT_NULL2 (pMoreCardsAvailable2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_ActivateCard2(
			(phpalSli15693_Sw_DataParams_t2*)pDataParams2,
			bOption2,
			bFlags2,
			bAfi2,
			pMask2,
			bMaskBitLength2,
			pDsfid2,
			pUid2,
			pMoreCardsAvailable2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_GetSerialNo2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2
									)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pUid2);
	PH_ASSERT_NULL2 (pUidLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_GetSerialNo2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, pUid2, pUidLength2 );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_SetSerialNo2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                   VAR(uint8, ANFCRL_VAR) bUidLength2
									)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pUid2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_SetSerialNo2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, pUid2, bUidLength2 );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_SetConfig2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                   VAR(uint16, ANFCRL_VAR) wConfig2,
                   VAR(uint16, ANFCRL_VAR) wValue2
								   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_SetConfig2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, wConfig2, wValue2 );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_GetConfig2(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                   VAR(uint16, ANFCRL_VAR) wConfig2,
                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
								   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(pValue2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_GetConfig2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, wConfig2, pValue2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_InventoryRead2(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                     VAR(uint8, ANFCRL_VAR) bFlags2,
                     VAR(uint8, ANFCRL_VAR) bAfi2,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                     VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                     VAR(uint8, ANFCRL_VAR) bBlockNo2,
                     VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
									   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);
	if (0U != (bMaskBitLength2))
		PH_ASSERT_NULL2(pMask2);
	PH_ASSERT_NULL2(pUid2);
	PH_ASSERT_NULL2(pUidLength2);
	PH_ASSERT_NULL2(pData2);
	PH_ASSERT_NULL2(pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_InventoryRead2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2,
				pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pUid2, pUidLength2,
				pData2, pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_InventoryReadExtended2(
                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                       VAR(uint8, ANFCRL_VAR) bFlags2,
                       VAR(uint8, ANFCRL_VAR) bAfi2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                       VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                       VAR(uint8, ANFCRL_VAR) bExtendedOptions2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,
                       VAR(uint8, ANFCRL_VAR) bBlockNo2,
                       VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
										   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);
	if (0U != (bMaskBitLength2))
		PH_ASSERT_NULL2(pMask2);
	PH_ASSERT_NULL2(pCIDOut2);
	PH_ASSERT_NULL2(pUid2);
	PH_ASSERT_NULL2(pUidLength2);
	PH_ASSERT_NULL2(pData2);
	PH_ASSERT_NULL2(pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_InventoryReadExtended2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2,
				pMask2, bMaskBitLength2, bExtendedOptions2, pCID2, bBlockNo2,
				wNoOfBlocks2, pCIDOut2, pUid2, pUidLength2, pData2, pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_FastInventoryRead2(
      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
      VAR(uint8, ANFCRL_VAR) bFlags2,
      VAR(uint8, ANFCRL_VAR) bAfi2,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
      VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
      VAR(uint8, ANFCRL_VAR) bBlockNo2,
      VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
			)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);
	if (0U != (bMaskBitLength2))
		PH_ASSERT_NULL2(pMask2);
	PH_ASSERT_NULL2(pUid2);
	PH_ASSERT_NULL2(pUidLength2);
	PH_ASSERT_NULL2(pData2);
	PH_ASSERT_NULL2(pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_FastInventoryRead2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2,
				pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pUid2, pUidLength2,
				pData2, pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_FastInventoryReadExtended2(
                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,        /**< [In] Pointer to this layers parameter structure. */
                       VAR(uint8, ANFCRL_VAR) bFlags2,            /**< [In] Request flags byte. */
                       VAR(uint8, ANFCRL_VAR) bAfi2,              /**< [In] Application Family Identifier. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,           /**< [In] UID mask, holding known UID bits. */
                       VAR(uint8, ANFCRL_VAR) bMaskBitLength2,    /**< [In] Number of UID bits within pMask2. */
                       VAR(uint8, ANFCRL_VAR) bExtendedOptions2,  /**< [In] Extended options */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,            /**< [In] Two byte CID -> if marked in extended options */
                       VAR(uint8, ANFCRL_VAR) bBlockNo2,          /**< [In] Block Number from where start reading */
                       VAR(uint16, ANFCRL_VAR) wNumOfBlocks2,     /**< [In] Number of blocks to read */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut2,        /**< [Out] Received UID. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,            /**< [Out] Received UID. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,      /**< [Out] Received UID Length. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,           /**< [Out] Received Data. */
                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2     /**< [Out] Received Data Length. */
										   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2(pDataParams2);
	if (0U != (bMaskBitLength2))
		PH_ASSERT_NULL2(pMask2);
	PH_ASSERT_NULL2(pCIDOut2);
	PH_ASSERT_NULL2(pUid2);
	PH_ASSERT_NULL2(pUidLength2);
	PH_ASSERT_NULL2(pData2);
	PH_ASSERT_NULL2(pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_FastInventoryReadExtended2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2,
				pMask2, bMaskBitLength2, bExtendedOptions2, pCID2, bBlockNo2,
				wNumOfBlocks2, pCIDOut2, pUid2, pUidLength2, pData2, pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_InventoryPageRead2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
        VAR(uint8, ANFCRL_VAR) bFlags2,
        VAR(uint8, ANFCRL_VAR) bAfi2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
        VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
        VAR(uint8, ANFCRL_VAR) bPageNo2,
        VAR(uint16, ANFCRL_VAR) wNoOfPages2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);
	if (0U != (bMaskBitLength2))
		PH_ASSERT_NULL2(pMask2);
	PH_ASSERT_NULL2(pUid2);
	PH_ASSERT_NULL2(pUidLength2);
	PH_ASSERT_NULL2(pData2);
	PH_ASSERT_NULL2(pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_InventoryPageRead2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2,
				pMask2, bMaskBitLength2, bPageNo2, wNoOfPages2, pUid2, pUidLength2,
				pData2, pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_FastInventoryPageRead2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                VAR(uint8, ANFCRL_VAR) bFlags2,
                VAR(uint8, ANFCRL_VAR) bAfi2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                VAR(uint8, ANFCRL_VAR) bPageNo2,
                VAR(uint16, ANFCRL_VAR) wNoOfPages2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
								)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);
	if (0U != (bMaskBitLength2))
		PH_ASSERT_NULL2(pMask2);
	PH_ASSERT_NULL2(pUid2);
	PH_ASSERT_NULL2(pUidLength2);
	PH_ASSERT_NULL2(pData2);
	PH_ASSERT_NULL2(pDataLength2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_FastInventoryPageRead2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2,
				pMask2, bMaskBitLength2, bPageNo2, wNoOfPages2, pUid2, pUidLength2,
				pData2, pDataLength2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_StayQuietPersistent2(
                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
											 )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_SLI156932) {
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);

		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	case PHPAL_SLI15693_SW_ID2:
		status2 = phpalSli15693_Sw_StayQuietPersistent2(
				(phpalSli15693_Sw_DataParams_t2*) pDataParams2);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2,
				PH_COMP_PAL_SLI156932);
		break;
	}

	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */
#endif /* NXPBUILD__PHPAL_SLI156932 */

#ifdef __cplusplus
}
#endif