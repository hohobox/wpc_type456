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
*   @file    phhalHw_Ncx3321_Instr.c
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Instr - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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
#include <ph_RefDefs.h>
#include <ph_Status.h>
#include <phhalHw.h>
#include <phDriver.h>
#include <phTools.h>

#ifdef NXPBUILD__PHHAL_HW_NCX3321
#include "phhalHw_Ncx3321.h"
#include "phhalHw_Ncx3321_InstrMngr.h"
#include <phhalHw_Ncx3321_Instr.h>
#include "phhalHw_Ncx3321_Int.h"
#include <phhalHw_Ncx3321_Reg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Instr.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INSTR_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_Instr.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INSTR_VENDOR_ID_C != PHHALHW_NCX3321_INSTR_VENDOR_ID)
    #error "phhalHw_Ncx3321_Instr.c and phhalHw_Ncx3321_Instr.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_Instr.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C    != PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C    != PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION) || \
     (PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION_C != PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Instr.c and phhalHw_Ncx3321_Instr.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_Instr.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION_C != PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION_C != PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION) || \
     (PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION_C != PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Instr.c and phhalHw_Ncx3321_Instr.h are different"
#endif
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
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
#ifdef NXPBUILD__PHHAL_HW_NCX3321
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) gaInstrBuffer[16U] = {0};

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegister(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      VAR(uint8, ANFCRL_VAR) bRegister,
                      VAR(uint32, ANFCRL_VAR) dwValue
                                            )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
    { 0U };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[5] =
    { 0U };
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /*Check to ensure that the pointer is not equal null*/
    if(pDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    switch(pDataParams->bRegisterOpState)
    {
        case PHHAL_INSTR_STATE_CHECK_PARAM :
            /* Check data parameters. */
            if (((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
                    || ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
            }

            /* Check if the Register address is valid. */
            if (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS)
            {
                if ((bRegister < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT) || (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT))
                {
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
                }
            }

            /* Save set value of the CLIF_SS_TX1_RMCFG and CLIF_SS_TX2_RMCFG registers in case it is reset after LPCD */
            if(CLIF_SS_TX1_RMCFG == bRegister)
            {
                pDataParams->bSsTx1ConfigIsConfigured = 1U;
                pDataParams->dwSetSsTx1ConfigValue = dwValue;
            }

            if(CLIF_SS_TX2_RMCFG == bRegister)
            {
                pDataParams->bSsTx2ConfigIsConfigured = 1U;
                pDataParams->dwSetSsTx2ConfigValue = dwValue;
            }

            pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_SEND_CMD;
            /* no break */
        case PHHAL_INSTR_STATE_SEND_CMD:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER;

            sCmdParams.bQueue = PH_ON;

            /* Value */
            aInstrBuffer[bIndex++] = bRegister;
            aInstrBuffer[bIndex++] = (uint8) (dwValue & 0xFFU);
            aInstrBuffer[bIndex++] = (uint8) ((dwValue >> 8U) & 0xFFU);
            aInstrBuffer[bIndex++] = (uint8) ((dwValue >> 16U) & 0xFFU);
            aInstrBuffer[bIndex++] = (uint8) ((dwValue >> 24U) & 0xFFU);

            sCmdParams.pTxDataBuff = &aInstrBuffer[0];
            sCmdParams.wTxDataLength = bIndex;
            sCmdParams.pRxLength = &wRxLen;
            sCmdParams.ppRxBuffer = &pRxData;
            /* Send command */
            PH_CHECK_INPROCESS_FCT(status,phhalHw_Ncx3321_InstMngr_HandleCmd(pDataParams, &sCmdParams,
                    PH_EXCHANGE_DEFAULT));
            break;
        default:
            status = PH_ERR_NCX3321_INTERNAL_ERROR;
            break;
    }
    pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_CHECK_PARAM;
    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterOrMask(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint8, ANFCRL_VAR) bRegister,
                        VAR(uint32, ANFCRL_VAR) dwMask
												)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
    { 0U };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[5] =
    { 0U };
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /*Check to ensure that the pointer is not equal null*/
    if(pDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    switch(pDataParams->bRegisterOpState)
	{
        case PHHAL_INSTR_STATE_CHECK_PARAM :
            /* Check data parameters. */
            if (((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
                    || ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
            }

            /* Check if the Register address is valid. */
            if (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS)
            {
                if ((bRegister < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT) || (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT))
                {
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
                }
            }

            pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_SEND_CMD;
            /* no break */
        case PHHAL_INSTR_STATE_SEND_CMD :
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_OR_MASK;

            sCmdParams.bQueue = PH_ON;

            /* Value */
            aInstrBuffer[bIndex++] = bRegister;
            aInstrBuffer[bIndex++] = (uint8) (dwMask & 0xFFU);
            aInstrBuffer[bIndex++] = (uint8) ((dwMask >> 8U) & 0xFFU);
            aInstrBuffer[bIndex++] = (uint8) ((dwMask >> 16U) & 0xFFU);
            aInstrBuffer[bIndex++] = (uint8) ((dwMask >> 24U) & 0xFFU);

            sCmdParams.pTxDataBuff = &aInstrBuffer[0];
            sCmdParams.wTxDataLength = bIndex;
            sCmdParams.pRxLength = &wRxLen;
            sCmdParams.ppRxBuffer = &pRxData;

            /* Send command */
            PH_CHECK_INPROCESS_FCT(status,phhalHw_Ncx3321_InstMngr_HandleCmd(pDataParams, &sCmdParams,
            		PH_EXCHANGE_DEFAULT));
            break;
        default:
            status = PH_ERR_NCX3321_INTERNAL_ERROR;
            break;
    }
    pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_CHECK_PARAM;
    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterAndMask(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          VAR(uint8, ANFCRL_VAR) bRegister,
                          VAR(uint32, ANFCRL_VAR) dwMask
													)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
	VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[5] =
	{ 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	/* Check if the Register address is valid. */
	if (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS)
	{
		if ((bRegister < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT) || (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
		}
	}

	/* Command Type */
	sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_AND_MASK;

	sCmdParams.bQueue = PH_ON;

	/* Value */
	aInstrBuffer[bIndex++] = bRegister;
	aInstrBuffer[bIndex++] = (uint8) (dwMask & 0xFFU);
	aInstrBuffer[bIndex++] = (uint8) ((dwMask >> 8U) & 0xFFU);
	aInstrBuffer[bIndex++] = (uint8) ((dwMask >> 16U) & 0xFFU);
	aInstrBuffer[bIndex++] = (uint8) ((dwMask >> 24U) & 0xFFU);

	sCmdParams.pTxDataBuff = &aInstrBuffer[0];
	sCmdParams.wTxDataLength = bIndex;
	sCmdParams.pRxLength = &wRxLen;
	sCmdParams.ppRxBuffer = &pRxData;

	/* Send command */
	PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(pDataParams, &sCmdParams,
			PH_EXCHANGE_DEFAULT));

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterMultiple(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRegTypeValueSets,
                          VAR(uint16, ANFCRL_VAR) wSizeOfRegTypeValueSets
													)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
	VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	/* Validate
	 * pRegTypeValueSets
	 * wSizeOfRegTypeValueSets
	 * wSizeOfRegTypeValueSets for modulus of 6. One set of write register is of 6 byte*/

	if ((NULL == pRegTypeValueSets) || (wSizeOfRegTypeValueSets > PHHAL_HW_NCX3321_MAX_REGISTER_TYPE_VALUE_SET)
			|| (wSizeOfRegTypeValueSets < PHHAL_HW_NCX3321_MIN_REGISTER_TYPE_VALUE_SET)
			|| ((wSizeOfRegTypeValueSets % PHHAL_HW_NCX3321_MIN_REGISTER_TYPE_VALUE_SET) != 0U))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
	}

	/* Build the command frame */
	sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_MULTIPLE;

	sCmdParams.bQueue = PH_OFF;

	sCmdParams.pTxDataBuff = pRegTypeValueSets;
	sCmdParams.wTxDataLength = wSizeOfRegTypeValueSets;
	sCmdParams.pRxLength = &wRxLen;
	sCmdParams.ppRxBuffer = &pRxData;

	/* Send command */
	PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(pDataParams, &sCmdParams,
			PH_EXCHANGE_DEFAULT));

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadRegister(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      VAR(uint8, ANFCRL_VAR) bRegister,
                      P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue
											)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
	VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[1] =
	{ 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->bRegisterOpState)
	{
		case PHHAL_INSTR_STATE_CHECK_PARAM:
			/* Check if the Register address and input parameter is valid. */
			if (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS)
			{
				if ((bRegister < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT) || (bRegister > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT))
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
				}
			}

			if (pValue == NULL)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}
			pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_SEND_CMD;
			return PH_STATUS_INPROCESS;
			/* No break */

		case PHHAL_INSTR_STATE_SEND_CMD:
			/* Command Type */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_READ_REGISTER;

			sCmdParams.bQueue = PH_OFF;

			aInstrBuffer[bIndex++] = bRegister;

			sCmdParams.pTxDataBuff = &aInstrBuffer[0];
			sCmdParams.wTxDataLength = bIndex;
			sCmdParams.pRxLength = &wRxLen;
			sCmdParams.ppRxBuffer = &pRxData;
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(pDataParams, &sCmdParams,
					PH_EXCHANGE_DEFAULT));
			if (status == PH_ERR_NCX3321_SUCCESS)
			{
				*pValue = pRxData[0];
				*pValue |= (((uint32) pRxData[1]) << 8U);
				*pValue |= (((uint32) pRxData[2]) << 16U);
				*pValue |= (((uint32) pRxData[3]) << 24U);
			}
			else
			{
				/* Do nothing */
			}
			break;

		default:
			status = PH_ERR_NCX3321_INTERNAL_ERROR;
			break;
	}

	pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_CHECK_PARAM;
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadRegisterMultiple(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRegisters,
                          VAR(uint8, ANFCRL_VAR) bNumOfRegisters,
                          P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppValues
													)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNumExpBytes = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
	VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	/* Check input parameters. */
	if ((ppValues == NULL) || (pRegisters == NULL) || (bNumOfRegisters > ((uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS)))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
	}

	bNumExpBytes = bNumOfRegisters * PHHAL_HW_NCX3321_BYTES_PER_REGISTER;
    /* Command Type */
	sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_READ_REGISTER_MULTIPLE;

	sCmdParams.bQueue = PH_OFF;

	sCmdParams.pTxDataBuff = pRegisters;
	sCmdParams.wTxDataLength = bNumOfRegisters;
	sCmdParams.pRxLength = &wRxLen;
	sCmdParams.ppRxBuffer = &pRxData;

	PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(pDataParams, &sCmdParams,
			PH_EXCHANGE_DEFAULT));


	if (status == PH_ERR_NCX3321_SUCCESS)
	{
		wRxLen = *sCmdParams.pRxLength;

		/* Validate the response length */
		if (wRxLen != bNumExpBytes)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_HAL);
		}
		*ppValues = *sCmdParams.ppRxBuffer;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteE2Prom(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      VAR(uint16, ANFCRL_VAR) wE2PromAddress,
                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataToWrite,
                      VAR(uint16, ANFCRL_VAR) wDataLength
											)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = { 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Check if the Register address is valid. */
			if (((wE2PromAddress + wDataLength) > PHHAL_HW_NCX3321_EEPROM_END_ADDRS) ||
				(wDataLength == 0U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = pDataToWrite;
			sCmdParams.wTxDataLength = wDataLength;

			gaInstrBuffer[0] = (uint8)wE2PromAddress;
			gaInstrBuffer[1] =  (uint8)(wE2PromAddress >> 8);
			sCmdParams.wAddnDataLen = 2U;
			sCmdParams.pAddnData = &gaInstrBuffer[0];

			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_WRITE_E2PROM;
            sCmdParams.pRxLength = &wRxLen;
            sCmdParams.ppRxBuffer = &pRxData;

            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_EXCHANGE_DEFAULT));
            break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadE2Prom(
                       P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                       VAR(uint16, ANFCRL_VAR) wE2PromAddress,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pReadData,
                       VAR(uint16, ANFCRL_VAR) wDataLength
										   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;

  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = { 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Check if the Register address is valid. */
			if (((wE2PromAddress + wDataLength) > PHHAL_HW_NCX3321_EEPROM_END_ADDRS) ||
				(pReadData == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}


			sCmdParams.bQueue = PH_OFF;

			gaInstrBuffer[bIndex++] = (uint8) wE2PromAddress ;
			gaInstrBuffer[bIndex++] = (uint8)(wE2PromAddress >> (8U));
			gaInstrBuffer[bIndex++] = (uint8) wDataLength;
			gaInstrBuffer[bIndex++] = (uint8) (wDataLength >> 8U);

			sCmdParams.pTxDataBuff = &gaInstrBuffer[0];
			sCmdParams.wTxDataLength = bIndex;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;

			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_READ_E2PROM;
            sCmdParams.ppRxBuffer = &pReadData;
            sCmdParams.pRxLength = &wRxLen;

            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_EXCHANGE_DEFAULT));
            break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_TransmitRFData(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint16, ANFCRL_VAR) wOption,
                        VAR(uint8, ANFCRL_VAR) bTxLastBits,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                        VAR(uint16, ANFCRL_VAR) wTxBufferLength
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Validate transmission buffer length
			* To validate bNumberOfValidBits indicate the exact data length to be transmitted.
			* */
			if (((pTxBuffer == NULL) && (wTxBufferLength != 0U) && ((wOption & PH_TRANSMIT_PREV_FRAME) == 0U))||
				(wTxBufferLength > PHHAL_HW_NCX3321_TX_DATA_MAX_LENGTH) ||
				(bTxLastBits > PHHAL_HW_NCX3321_MAX_NUM_OF_BITS_FOR_LAST_BYTE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			if ((0U == (wOption & (PH_TRANSMIT_LEAVE_BUFFER_BIT  | PH_TRANSMIT_PREV_FRAME))))
			{
				/* clear internal buffer if requested */
				pDataParams->wTxBufLen = 0U;
				pDataParams->wTxBufStartPos = 0U;
				pDataParams->wTxFwDataLen = 0U;
			}

			gaInstrBuffer[bIndex++] = bTxLastBits;
			gaInstrBuffer[bIndex++] = 0;

			sCmdParams.pAddnData = &gaInstrBuffer[0];
			sCmdParams.wAddnDataLen = bIndex;

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = pTxBuffer;
			sCmdParams.wTxDataLength = wTxBufferLength;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/* Command Type */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA;
			sCmdParams.pRxLength = &wRxLen;
			sCmdParams.ppRxBuffer = &pRxData;

			/* Send command */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
				pDataParams,
				&sCmdParams,
				wOption));

			break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RetrieveRFData(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) wTmpRxBufferLen = 0U;
  VAR(uint16, ANFCRL_VAR) wTmpRxBufferSize = 0U;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Validate input parameters. */
			if ((pRxBuffer == NULL) ||
				(pRxDataLength == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			(void) phhalHw_Ncx3321_Int_GetRxBuffer(pDataParams, &pTmpRxBuffer, &wTmpRxBufferLen, &wTmpRxBufferSize);

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = NULL;
			sCmdParams.wTxDataLength = 0u;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA;
            sCmdParams.ppRxBuffer = &pTmpRxBuffer;
            sCmdParams.pRxLength = &wRxLen;

            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_EXCHANGE_DEFAULT));

            if(status == PH_ERR_NCX3321_SUCCESS)
            {
                *pRxBuffer = *sCmdParams.ppRxBuffer;
                *pRxDataLength = *sCmdParams.pRxLength;
            }
            break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReceiveRFData(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint8, ANFCRL_VAR) bRespConfigMask,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuffer = NULL;
  VAR(uint8, ANFCRL_VAR) bInstrData = bRespConfigMask;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Validate input parameters. */
			if ((ppRxBuffer == NULL) ||
				(pRxDataLength == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = &bInstrData;
			sCmdParams.wTxDataLength = 1u;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_RECEIVE_RF_DATA;
            sCmdParams.pRxLength = &wRxLen;
            sCmdParams.ppRxBuffer = &pTmpRxBuffer;

            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_RECEIVE_DEFAULT));

            if(status == PH_ERR_NCX3321_SUCCESS)
            {
                if (ppRxBuffer != NULL)
                {
                    *ppRxBuffer = *sCmdParams.ppRxBuffer;
                }
                if (pRxDataLength != NULL)
                {
                    *pRxDataLength = *sCmdParams.pRxLength;
                }
            }

            break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}



FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ExchangeRFData(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint16, ANFCRL_VAR) wOption,
                        VAR(uint8, ANFCRL_VAR) bTxLastBits,
                        VAR(uint8, ANFCRL_VAR) bRespControl,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData,
                        VAR(uint16, ANFCRL_VAR) wTxDataLength,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxData,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Validate input parameters */
			if (((pTxData == NULL) && (wTxDataLength != 0U)) ||
				(wTxDataLength > PHHAL_HW_NCX3321_TX_DATA_MAX_LENGTH) ||
				(bTxLastBits > PHHAL_HW_NCX3321_MAX_NUM_OF_BITS_FOR_LAST_BYTE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = pTxData;
			sCmdParams.wTxDataLength = wTxDataLength;

			if ((0U == ((wOption & PH_EXCHANGE_LEAVE_BUFFER_BIT))))
			{
				/* clear internal buffer if requested */
				pDataParams->wTxBufLen = 0U;
				pDataParams->wTxBufStartPos = 0U;
				pDataParams->wTxFwDataLen = 0U;
			}

			gaInstrBuffer[bIndex++] = bTxLastBits;
			gaInstrBuffer[bIndex++] = bRespControl;

			sCmdParams.pAddnData = &gaInstrBuffer[0];
			sCmdParams.wAddnDataLen = bIndex;
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/* Command Type */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA;
			sCmdParams.pRxLength = &wRxLen;
			sCmdParams.ppRxBuffer = &pRxData;

			PH_CHECK_INPROCESS_FCT(status,  phhalHw_Ncx3321_InstMngr_HandleCmd(
				pDataParams,
				&sCmdParams,
				wOption));
			break;
	}

	if(status == PH_ERR_NCX3321_SUCCESS)
	{
		if (ppRxData != NULL)
		{
			*ppRxData = *sCmdParams.ppRxBuffer;
		}
		if (pRxDataLength != NULL)
		{
			*pRxDataLength = *sCmdParams.pRxLength;
		}
	}
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeStandby(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          VAR(uint8, ANFCRL_VAR) bConfigMask,
                          VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs
													)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			gaInstrBuffer[bIndex++] = bConfigMask;
			gaInstrBuffer[bIndex++] = (uint8)wWakeupCounterInMs;
			gaInstrBuffer[bIndex++] = (uint8)(wWakeupCounterInMs >> 8);

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = &gaInstrBuffer[0];
			sCmdParams.wTxDataLength = bIndex;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/* Command Type */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_STANDBY;
			sCmdParams.pRxLength = &wRxLen;
			sCmdParams.ppRxBuffer = &pRxData;

			/* Send command */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
				pDataParams,
				&sCmdParams,
				PH_EXCHANGE_DEFAULT));
			break;
	}

	if(status == PH_ERR_NCX3321_SUCCESS)
	{
		pDataParams->dwExpectedEvent = PH_NCX3321_EVT_BOOT;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LPCD_SetConfig(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint16, ANFCRL_VAR) wConfig,
                        VAR(uint32, ANFCRL_VAR) dwValue
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_NCX3321_SUCCESS;

	switch(wConfig)
	{

	case PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS:
	{
		/* Value should be greater than 3ms */
		if(dwValue >= 0x03U)
		{
			pDataParams->wLPCDWakeupCounterInMs = (uint16)dwValue;
		}
		else
		{
			pDataParams->wLPCDWakeupCounterInMs = 0x03U;
		}
	 }
	 break;

	case PHHAL_HW_CONFIG_LPCD_MODE:
		if((dwValue == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT) || (dwValue ==  PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN))
		{
			pDataParams->bLpcdMode = (uint8)dwValue;
		}
		else
		{
			statusTmp = PH_ERR_NCX3321_INVALID_PARAMETER;
		}
		break;

	case PHHAL_HW_CONFIG_LPCD_CONFIG:
		if ((dwValue <=  PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_LPCD) ||
			(dwValue == PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_CALIB))
		{
			pDataParams->bLpcdConfig = (uint8)dwValue;
		}
		else
		{
			statusTmp = PH_ERR_NCX3321_INVALID_PARAMETER;
		}
		break;

	case PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL:
		pDataParams->bLpcdWakeUpCtrl = (uint8)dwValue;
		break;

	case PHHAL_HW_CONFIG_LPCD_REF_VAL:
		pDataParams->dwLpcdRefVal = dwValue;
		break;

    case PHHAL_HW_CONFIG_LPCD_HFATT_VAL:
        pDataParams->bHFATTVal = (uint8)dwValue;
        break;

	default:
		statusTmp = PH_ERR_NCX3321_UNSUPPORTED_PARAMETER;
		break;
	}

	return PH_ADD_COMPCODE(statusTmp, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LPCD_GetConfig(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint16, ANFCRL_VAR) wConfig,
                        P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue
												)
{
	switch(wConfig)
	{
	case PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS:
		*pValue = pDataParams->wLPCDWakeupCounterInMs;
		break;

	case PHHAL_HW_CONFIG_LPCD_MODE:
		*pValue = pDataParams->bLpcdMode;
		break;

	case PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL:
		*pValue = pDataParams->bLpcdWakeUpCtrl;
		break;

	case PHHAL_HW_CONFIG_LPCD_REF_VAL:
		*pValue = pDataParams->dwLpcdRefVal;
		break;

	case PHHAL_HW_CONFIG_LPCD_RETRIEVE_EVENT_STATUS:
		*pValue = pDataParams->dwEventStatus;
		break;

    case PHHAL_HW_CONFIG_LPCD_HFATT_VAL:
        *pValue = pDataParams->bHFATTVal;
        break;

	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
	}

	return PH_ERR_NCX3321_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeLpcd(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint8, ANFCRL_VAR) bLpcdMode,
                        VAR(uint8, ANFCRL_VAR) bWakeUpCntrlHwLpcd,
                        VAR(uint32, ANFCRL_VAR) dwLpcdRefValue,
                        VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			gaInstrBuffer[bIndex++] = bLpcdMode;
			gaInstrBuffer[bIndex++] = bWakeUpCntrlHwLpcd;
			gaInstrBuffer[bIndex++] = (uint8) dwLpcdRefValue;
			gaInstrBuffer[bIndex++] = (uint8) (dwLpcdRefValue >> 8);
			gaInstrBuffer[bIndex++] = (uint8) (dwLpcdRefValue >> 16);
			gaInstrBuffer[bIndex++] = (uint8) (dwLpcdRefValue >> 24);
			gaInstrBuffer[bIndex++] = (uint8)wWakeupCounterInMs;
			gaInstrBuffer[bIndex++] = (uint8)(wWakeupCounterInMs >> 8);

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = &gaInstrBuffer[0];
			sCmdParams.wTxDataLength = bIndex;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/* Command Type */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_LPCD;
			sCmdParams.pRxLength = &wRxLen;
			sCmdParams.ppRxBuffer = &pRxData;

			/* Send command */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
				pDataParams,
				&sCmdParams,
				PH_EXCHANGE_DEFAULT));
			break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeAutocoll(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          VAR(uint8, ANFCRL_VAR) bRfTechnologyMask,
                          VAR(uint8, ANFCRL_VAR) bAutocollMode
													)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = {0U};
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[2] = {0U, 0U};
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
				|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	if(0U == bRfTechnologyMask)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
	}

	if (pDataParams->HwEventObj.bEventState == PH_TOOLS_EVENT_IDLE)
	{
		sCmdParams.bQueue = PH_OFF;

		aInstrBuffer[bIndex++] = bRfTechnologyMask;
		aInstrBuffer[bIndex++] = bAutocollMode;

		sCmdParams.pTxDataBuff = &aInstrBuffer[0];
		sCmdParams.wTxDataLength = bIndex;
	}
	/* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_AUTOCOLL;
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;

    PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
            pDataParams,
            &sCmdParams,
            PH_EXCHANGE_DEFAULT));

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeBootNormal(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
													)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[4] = {0};
	/* Check data parameters. */
	if ((pDataParams == NULL) ||
		(((pDataParams->wId) & PH_COMP_MASK) != PH_COMP_HAL) ||
		(((pDataParams->wId) & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}
	aCmd[0]  = PHHAL_HW_NCX3321_INT_SPI_WRITE;
	aCmd[1]  = 0x20;
	aCmd[2]  = 0x01;
	aCmd[3]  = 0x00;

	return phhalHw_Ncx3321_Send(pDataParams,&aCmd[0], 4, PH_ON);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeNormal(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
												)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[4] = {0};
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventReceived = 0x0U;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			aCmd[0]  = PHHAL_HW_NCX3321_INT_SPI_WRITE;
			aCmd[1]  = 0x20;
			aCmd[2]  = 0x00;
			aCmd[3]  = 0x00;

			PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Send(pDataParams,&aCmd[0], 4, PH_ON));
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/*Wait for event*/
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Int_EventWait(
						 pDataParams,
						 PH_NCX3321_EVT_IDLE | PH_NCX3321_EVT_GENERAL_ERROR,
						 PHHAL_HW_ABORT_EVT_TIMEOUT,
						 TRUE,
						 &dwEventReceived));
			break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

#ifdef NXPBUILD__PHPAL_MIFARE_SW
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_MifareAuthenticate(
                                                   P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
                                                   VAR(uint8, ANFCRL_VAR) bKeyType,
                                                   VAR(uint8, ANFCRL_VAR) bBlockNo,
                                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
                                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLenTmp;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferLength = 0;

    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aCmdBuffer[13];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_BUF aRspBuffer;
    VAR(uint32, ANFCRL_VAR) dwRegister;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = {0U};

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    /* Validate input parameters */
    if ((NULL == pKey) ||
        (NULL == pUid) ||
        ((bKeyType != PHHAL_HW_MFC_KEYA) && (bKeyType != PHHAL_HW_MFC_KEYB)))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Build the command frame */
    wBufferLength = 0U;

    /* Write Tx Data */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE;

    sCmdParams.bQueue = PH_OFF;

    /* Copy the data to be transmitted*/
    (void)memcpy(&aCmdBuffer[wBufferLength], pKey, PHHAL_HW_MFC_KEY_LENGTH);
    wBufferLength += PHHAL_HW_MFC_KEY_LENGTH;

    if(bKeyType == PHHAL_HW_MFC_KEYA)
    {
        aCmdBuffer[wBufferLength++] = PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE_KEY_TYPE_A;
    }
    else
    {
        aCmdBuffer[wBufferLength++] = PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE_KEY_TYPE_B;
    }

    aCmdBuffer[wBufferLength++] = bBlockNo;
    (void)memcpy(&aCmdBuffer[wBufferLength], pUid, PHHAL_HW_NCX3321_MFC_UID_LEN);
    wBufferLength += PHHAL_HW_NCX3321_MFC_UID_LEN;

    sCmdParams.pTxDataBuff = &aCmdBuffer[0];
    sCmdParams.wTxDataLength = wBufferLength;
    sCmdParams.ppRxBuffer = &aRspBuffer;
    sCmdParams.pRxLength = &wDataLenTmp;

    /* Send it to the chip */
    status =  phhalHw_Ncx3321_InstMngr_HandleCmd(
            pDataParams,
            &sCmdParams,
            PH_EXCHANGE_DEFAULT);

    /* Validate the response */
    if(PH_ERR_NCX3321_SUCCESS == status)
    {
        /* Check auth success */
        PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, SYSTEM_CONFIG, &dwRegister));
        if((0U == ((dwRegister & SYSTEM_CONFIG_MFC_CRYPTO_ON_MASK))))
        {
            status = PH_ERR_AUTH_ERROR;
            pDataParams->bMfcCryptoEnabled = PH_OFF;
        }
        else
        {
            pDataParams->bMfcCryptoEnabled = PH_ON;
        }
    }

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LoadRfConfiguration(
                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                          VAR(uint8, ANFCRL_VAR) bRfTxConfiguration,
                          VAR(uint8, ANFCRL_VAR) bRfRxConfiguration
													)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;

    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Check TX and RX configuration parameters. */
			if (((bRfTxConfiguration > PHHAL_HW_NCX3321_MAX_RF_TX_CONFIGURATION_INDEX) && (bRfTxConfiguration != 0xFFU)) ||
				((bRfRxConfiguration > 0x9DU) && (bRfRxConfiguration != 0xFFU)) ||
				(bRfRxConfiguration < 0x80U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* If "no change" needed for TX and RX configuration, return success. */
			if ((bRfTxConfiguration == 0xFFU) && (bRfRxConfiguration == 0xFFU))
			{
				return PH_ERR_NCX3321_SUCCESS;
			}

			sCmdParams.bQueue = PH_ON;

			/* Value */
			gaInstrBuffer[bIndex++] = bRfTxConfiguration;
			gaInstrBuffer[bIndex++] = bRfRxConfiguration;

			sCmdParams.pTxDataBuff = &gaInstrBuffer[0];
			sCmdParams.wTxDataLength = bIndex;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/* Command Type */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_LOAD_RF_CONFIGURATION;
			sCmdParams.pRxLength = &wRxLen;
			sCmdParams.ppRxBuffer = &pRxData;
			/* Send command */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
				pDataParams,
				&sCmdParams,
				PH_EXCHANGE_DEFAULT));
			break;
	}

	return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_UpdateRfConfiguration(
                            P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfiguration,
                            VAR(uint8, ANFCRL_VAR) bRfConfigurationSize
														)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;

  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Validate input parameters.
			* bRfConfigurationSize is not a multiple of PHHAL_HW_NCX3321_RF_CONFIGURATION_SIZE
			* bRfConfigurationSize is greater than PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE
			* */
			if ((NULL == pRfConfiguration) ||
				(bRfConfigurationSize > PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE) ||
				(0U != (bRfConfigurationSize % PHHAL_HW_NCX3321_RF_CONFIGURATION_SIZE)))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = pRfConfiguration;
			sCmdParams.wTxDataLength = bRfConfigurationSize;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_UPDATE_RF_CONFIGURATION;
            sCmdParams.pRxLength = &wRxLen;
            sCmdParams.ppRxBuffer = &pRxData;

            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_EXCHANGE_DEFAULT));
            break;
	}

	return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RetrieveRfConfiguration(
                            P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                            VAR(uint8, ANFCRL_VAR) bRfConfiguration,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfBuf,
                            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfBufSize
														)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Validate input parameters.
			* bRfRxConfiguration is greater than the maximum RF RX configuration
			* bRfRxConfiguration is not the PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX
			* */
			if (((bRfConfiguration < PHHAL_HW_NCX3321_MIN_RF_RX_CONFIGURATION_INDEX)
				&& (bRfConfiguration > PHHAL_HW_NCX3321_MAX_RF_TX_CONFIGURATION_INDEX)) ||
				(bRfConfiguration > PHHAL_HW_NCX3321_MAX_RF_RX_CONFIGURATION_INDEX) ||
				(*pRfConfBufSize < PHHAL_HW_NCX3321_MIN_RF_CONFIGURATION_BUFFER_SIZE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
			}

			sCmdParams.bQueue = PH_OFF;

			sCmdParams.pTxDataBuff = &bRfConfiguration;
			sCmdParams.wTxDataLength = 1U;
			sCmdParams.pAddnData = NULL;
			sCmdParams.wAddnDataLen = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			/* Build the command frame */
			sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_GET_RF_CONFIGURATION;
			sCmdParams.pRxLength = pRfConfBufSize;
			sCmdParams.ppRxBuffer = &pRfConfBuf;

			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
				pDataParams,
				&sCmdParams,
				PH_EXCHANGE_DEFAULT));
			break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RfOn(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bRfOnConfig
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;

  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	/* Validate RF ON parameter */
	if (bRfOnConfig > 3U)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
	}

	if(pDataParams->HwEventObj.bEventState == PH_TOOLS_EVENT_IDLE)
	{
		sCmdParams.bQueue = PH_OFF;

		/* Value */
		gaInstrBuffer[bIndex++] = bRfOnConfig;

		sCmdParams.pTxDataBuff = &gaInstrBuffer[0];
		sCmdParams.wTxDataLength = bIndex;
		sCmdParams.pAddnData = NULL;
		sCmdParams.wAddnDataLen = 0u;


	}
    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_FIELD_ON;
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;
    /* Send command */
    PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
            pDataParams,
            &sCmdParams,
            PH_EXCHANGE_DEFAULT));

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RfOff(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	if(pDataParams->HwEventObj.bEventState == PH_TOOLS_EVENT_IDLE)
    {
        sCmdParams.bQueue = PH_OFF;
        sCmdParams.wTxDataLength = 0u;
        sCmdParams.pTxDataBuff = NULL;
        sCmdParams.pAddnData = NULL;
        sCmdParams.wAddnDataLen = 0u;
    }
    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_FIELD_OFF;
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;
    /* Send command */
    PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
            pDataParams,
            &sCmdParams,
            PH_EXCHANGE_DEFAULT));

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ConfigureTestBusDigital(
                                                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                                        VAR(uint8, ANFCRL_VAR) bSignalIndex,
                                                        VAR(uint8, ANFCRL_VAR) bBitIndex,
                                                        VAR(uint8, ANFCRL_VAR) bPadIndex
                                                        )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[3U] = {0};
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) PH_MEMLOC_REM sCmdParams = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_CONFIGURE_TESTBUS_DIGITAL;

    sCmdParams.bQueue = PH_OFF;

    /* Value */
    aInstrBuffer[bIndex++] = bSignalIndex;
    aInstrBuffer[bIndex++] = bBitIndex;
    aInstrBuffer[bIndex++] = bPadIndex;

    sCmdParams.pTxDataBuff = &aInstrBuffer[0];
    sCmdParams.wTxDataLength = bIndex;
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;

    /* Send command */
    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ConfigureTestBusAnalog(
                                                       P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                                       VAR(uint8, ANFCRL_VAR) bConfig,
                                                       VAR(uint8, ANFCRL_VAR) bCombinedMode,
                                                       VAR(uint8, ANFCRL_VAR) bTBIndex0,
                                                       VAR(uint8, ANFCRL_VAR) bTBIndex1,
                                                       VAR(uint8, ANFCRL_VAR) bShiftIndex0,
                                                       VAR(uint8, ANFCRL_VAR) bShiftIndex1,
                                                       VAR(uint8, ANFCRL_VAR) bMask0,
                                                       VAR(uint8, ANFCRL_VAR) bMask1
                                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[8U] = {0};
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) PH_MEMLOC_REM sCmdParams = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /* Check data parameters. */
    if ((pDataParams == NULL) ||
        (((pDataParams->wId) & PH_COMP_MASK) != PH_COMP_HAL) ||
        (((pDataParams->wId) & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_CONFIGURE_TESTBUS_ANALOG;

    sCmdParams.bQueue = PH_OFF;

    /* Value */
    aInstrBuffer[bIndex++] = bConfig;
    aInstrBuffer[bIndex++] = bCombinedMode;
    aInstrBuffer[bIndex++] = bTBIndex0;
    aInstrBuffer[bIndex++] = bTBIndex1;
    aInstrBuffer[bIndex++] = bShiftIndex0;
    aInstrBuffer[bIndex++] = bShiftIndex1;
    aInstrBuffer[bIndex++] = bMask0;
    aInstrBuffer[bIndex++] = bMask1;

    sCmdParams.pTxDataBuff = &aInstrBuffer[0];
    sCmdParams.wTxDataLength = bIndex;
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;

    /* Send command */
    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsEnable(
                                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                          VAR(uint8, ANFCRL_VAR) bOption
                                          )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) PH_MEMLOC_REM sCmdParams = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    /* Validate Option parameter */
    if ((bOption != PH_OFF) && (bOption != PH_ON))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_CTS_ENABLE;

    sCmdParams.bQueue = PH_OFF;

    sCmdParams.pTxDataBuff = &bOption;
    sCmdParams.wTxDataLength = 0x01U;
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;

    /* Send command */
    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    if(status == PH_ERR_NCX3321_SUCCESS)
    {
    	pDataParams->dwExpectedEvent = PH_NCX3321_EVT_CTS;
    }
    return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsFastConfigEnable(
	P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	P2VAR(phhalHw_Ncx3321_Instr_CtsConfig_t, AUTOMATIC, ANFCRL_APPL_DATA) pCtsConfig
)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) PH_MEMLOC_REM sCmdParams = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

	/* Check data parameters. */
	if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
				|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

	/* Validate input parameter */
	if (pCtsConfig == NULL)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
	}

	/* Command Type */
	sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_CTS_FAST_CONFIG_ENABLE;

	sCmdParams.bQueue = PH_OFF;

	/* Value */
	sCmdParams.pTxDataBuff = (uint8 *) pCtsConfig;
	sCmdParams.wTxDataLength = (uint16)sizeof(phhalHw_Ncx3321_Instr_CtsConfig_t);
	sCmdParams.pRxLength = &wRxLen;
	sCmdParams.ppRxBuffer = &pRxData;

	/* Send command */
	status = phhalHw_Ncx3321_InstMngr_HandleCmd(
		pDataParams,&sCmdParams, PH_EXCHANGE_DEFAULT);

	return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsConfig(
                                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                          P2VAR(phhalHw_Ncx3321_Instr_CtsConfig_t, AUTOMATIC, ANFCRL_APPL_DATA) pCtsConfig
                                          )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) PH_MEMLOC_REM sCmdParams = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    /* Validate input parameter */
    if (pCtsConfig == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_CTS_CONFIGURE;

    sCmdParams.bQueue = PH_OFF;

    /* Value */
    sCmdParams.pTxDataBuff = (uint8 *) pCtsConfig;
    sCmdParams.wTxDataLength = (uint16)sizeof(phhalHw_Ncx3321_Instr_CtsConfig_t);
    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;

    /* Send command */
    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    return  PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsRetrieveLog(
                                               P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                               VAR(uint8, ANFCRL_VAR) bChunkSize,
                                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLogData,
                                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bLogDataSize
                                               )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    /* Validate input parameter */
    if ((pLogData == NULL) || (bLogDataSize == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
    }

    if (pDataParams->bCTSEvent == PH_OFF)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_NO_CTS_EVENT, PH_COMP_HAL);
    }
    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_CTS_RETRIEVE_LOG;

    sCmdParams.bQueue = PH_OFF;

    /* Value */
    sCmdParams.pTxDataBuff = &bChunkSize;
    sCmdParams.wTxDataLength = 0x01U;
    sCmdParams.ppRxBuffer = &pLogData;
    sCmdParams.pRxLength = &wRxLen;

    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    if ((status == PH_ERR_NCX3321_SUCCESS) || (status == PH_ERR_NCX3321_SUCCESS_CHAINING))
    {
        *bLogDataSize = (uint8) wRxLen;
    }

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_GetDieId(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDieIdValue)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams =
    { 0U };
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
            || ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    switch(pDataParams->HwEventObj.bEventState)
    {
        case PH_TOOLS_EVENT_IDLE:
            /* Validate input parameter */
            if (pDieIdValue == NULL)
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
            }
            /* Command Type */
            sCmdParams.bQueue = PH_OFF;
            sCmdParams.pTxDataBuff = NULL;
            /*no break*/
        case PH_TOOLS_EVENT_PENDING:
        case PH_TOOLS_EVENT_OCCUR:
            sCmdParams.pRxLength = &wRxLen;
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_GET_DIE_ID;
            sCmdParams.ppRxBuffer = &pDieIdValue;
            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_EXCHANGE_DEFAULT));
            if (wRxLen != 16U)
            {
                status = PH_ERR_LENGTH_ERROR;
            }
            break;
    }

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_GetVersion(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(phhalHw_Ncx3321_Version_t, AUTOMATIC, ANFCRL_APPL_DATA) pVersion)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
  VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = { 0U };
  VAR(uint8, ANFCRL_VAR) aVersionInfo[4] = { 0 };
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVersionInfo;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;

    pVersionInfo = &aVersionInfo[0];
    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
            || ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    switch(pDataParams->HwEventObj.bEventState)
    {
        case PH_TOOLS_EVENT_IDLE:
            /* Validate input parameter */
            if (pVersion == NULL)
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_PARAMETER, PH_COMP_HAL);
            }

            sCmdParams.bQueue = PH_OFF;
            sCmdParams.pTxDataBuff = NULL;
            /*no break*/
        case PH_TOOLS_EVENT_PENDING:
        case PH_TOOLS_EVENT_OCCUR:
            /* Command Type */
            sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_GET_VERSION;
            sCmdParams.ppRxBuffer = &pVersionInfo;
            sCmdParams.pRxLength = &wRxLen;
            PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_HandleCmd(
                    pDataParams,
                    &sCmdParams,
                    PH_EXCHANGE_DEFAULT));
            if (status == PH_ERR_NCX3321_SUCCESS)
            {
                pVersion->bHw_Version = aVersionInfo[0];
                pVersion->bROM_Version = aVersionInfo[1];
                pVersion->wFW_Version =  (uint16)aVersionInfo[2] | ((uint16)aVersionInfo[3] << 8);
            }
            break;
    }

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeDownload(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) sCmdParams = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;

    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;
    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_DOWNLOAD;
    sCmdParams.bQueue = PH_OFF;

    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_PrbsTest(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bPrbs_type)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aInstrBuffer[1] = {0};
    VAR(phhalHw_InstMngr_CmdParams_t, ANFCRL_VAR) PH_MEMLOC_REM sCmdParams = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxData = NULL;


    /* Check data parameters. */
    if ((pDataParams == NULL) || ((pDataParams->wId & PH_COMP_MASK) != PH_COMP_HAL)
    			|| ((pDataParams->wId & PH_COMPID_MASK) != PHHAL_HW_NCX3321_ID))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_NCX3321_INVALID_DATA_PARAMS, PH_COMP_HAL);
    }

    aInstrBuffer[bIndex++] = bPrbs_type;

    sCmdParams.pRxLength = &wRxLen;
    sCmdParams.ppRxBuffer = &pRxData;
    /* Command Type */
    sCmdParams.bCmd = PHHAL_HW_NCX3321_INSTR_PRBS_TEST;
    sCmdParams.bQueue = PH_OFF;
    sCmdParams.pTxDataBuff = &aInstrBuffer[0];
    sCmdParams.wTxDataLength = bIndex;

    status = phhalHw_Ncx3321_InstMngr_HandleCmd(
       pDataParams,
       &sCmdParams,
       PH_EXCHANGE_DEFAULT);

    return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef __cplusplus
}
#endif
