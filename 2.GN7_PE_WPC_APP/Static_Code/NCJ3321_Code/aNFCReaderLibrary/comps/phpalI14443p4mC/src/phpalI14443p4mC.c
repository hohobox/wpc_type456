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
*   @file    phpalI14443p4mC.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p4mC - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p4mC ISO/IEC 14443-4mC
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
#include <ph_RefDefs.h>
#include <phpalI14443p4mC.h>

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
#include "Sw/phpalI14443p4mC_Sw.h"
#endif/* NXPBUILD__PHPAL_I14443P4MC_SW */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4mC.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4MC_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4MC_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4MC_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4MC_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4MC_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4mC.h header file are of the same vendor */
#if (PHPALI14443P4MC_VENDOR_ID_C != PHPALI14443P4MC_VENDOR_ID)
    #error "phpalI14443p4mC.c and phpalI14443p4mC.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4mC.h header file are of the same Autosar version */
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P4MC_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4MC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4mC.c and phpalI14443p4mC.h are different"
#endif
/* Check if current file and phpalI14443p4mC.h header file are of the same Software version */
#if ((PHPALI14443P4MC_SW_MAJOR_VERSION_C != PHPALI14443P4MC_SW_MAJOR_VERSION) || \
     (PHPALI14443P4MC_SW_MINOR_VERSION_C != PHPALI14443P4MC_SW_MINOR_VERSION) || \
     (PHPALI14443P4MC_SW_PATCH_VERSION_C != PHPALI14443P4MC_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4mC.c and phpalI14443p4mC.h are different"
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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4MC
#ifndef NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_ResetProtocol(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
										 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
	   case PHPAL_I14443P4MC_SW_ID:
		   status = phpalI14443p4mC_Sw_ResetProtocol((phpalI14443p4mC_Sw_DataParams_t *)pDataParams);
		   break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

	   default:
		   status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		   break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Receive(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wOption,
                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
		case PHPAL_I14443P4MC_SW_ID:
			status = phpalI14443p4mC_Sw_Receive(
				(phpalI14443p4mC_Sw_DataParams_t *)pDataParams,
				wOption,
				ppRxBuffer,
				pRxLength);
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

		default:
			status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
			break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Transmit(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wOption,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                  VAR(uint16, ANFCRL_VAR) wTxLength
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
	if (0U != (wTxLength)) PH_ASSERT_NULL (pTxBuffer);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
		case PHPAL_I14443P4MC_SW_ID:
			status = phpalI14443p4mC_Sw_Transmit(
				(phpalI14443p4mC_Sw_DataParams_t *)pDataParams,
				wOption,
				pTxBuffer,
				wTxLength);
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

		default:
			status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
			break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Activate(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRats,
                  VAR(uint8, ANFCRL_VAR) bRatsLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts,
                  VAR(uint16, ANFCRL_VAR) wAtsLength
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pRats);
	PH_ASSERT_NULL (pAts);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
		case PHPAL_I14443P4MC_SW_ID:
			status = phpalI14443p4mC_Sw_Activate(
				(phpalI14443p4mC_Sw_DataParams_t *)pDataParams,
				pRats, bRatsLength,
				pAts,
				wAtsLength);
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

		default:
			status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
			break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Wtx(
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
							   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
	   case PHPAL_I14443P4MC_SW_ID:
		   status = phpalI14443p4mC_Sw_Wtx((phpalI14443p4mC_Sw_DataParams_t *)pDataParams);
		   break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

	   default:
		   status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		   break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_SetConfig(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wConfig,
                   VAR(uint16, ANFCRL_VAR) wValue
									 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
		case PHPAL_I14443P4MC_SW_ID:
			status = phpalI14443p4mC_Sw_SetConfig(
				(phpalI14443p4mC_Sw_DataParams_t *)pDataParams,
				wConfig,
				wValue);
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

		default:
			status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
			break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_GetConfig(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wConfig,
                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
									 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pValue);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_I14443P4MC)
	{
		status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
		case PHPAL_I14443P4MC_SW_ID:
			status = phpalI14443p4mC_Sw_GetConfig(
				(phpalI14443p4mC_Sw_DataParams_t *)pDataParams,
				wConfig,
				pValue);
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

		default:
			status = (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
			break;
	}

	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */
#endif/*NXPBUILD__PHPAL_I14443P4MC */

#ifdef __cplusplus
}
#endif
