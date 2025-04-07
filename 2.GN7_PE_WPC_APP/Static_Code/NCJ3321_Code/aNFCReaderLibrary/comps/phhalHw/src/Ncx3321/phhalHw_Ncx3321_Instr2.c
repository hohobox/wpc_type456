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
*   @file    phhalHw_Ncx3321_Instr2.c
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
#include <ph_RefDefs2.h>
#include <ph_Status2.h>
#include <phhalHw2.h>
#include <phDriver2.h>
#include <phTools2.h>

#ifdef NXPBUILD__PHHAL_HW_NCX33212
#include "phhalHw_Ncx33212.h"
#include "phhalHw_Ncx3321_InstrMngr2.h"
#include <phhalHw_Ncx3321_Instr2.h>
#include "phhalHw_Ncx3321_Int2.h"
#include <phhalHw_Ncx3321_Reg2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Instr2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INSTR_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_Instr2.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INSTR_VENDOR_ID_C2 != PHHALHW_NCX3321_INSTR_VENDOR_ID2)
    #error "phhalHw_Ncx3321_Instr2.c and phhalHw_Ncx3321_Instr2.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_Instr2.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C2    != PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C2    != PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION_C2 != PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Instr2.c and phhalHw_Ncx3321_Instr2.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_Instr2.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION_C2 != PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION_C2 != PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION_C2 != PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phhalHw_Ncx3321_Instr2.c and phhalHw_Ncx3321_Instr2.h are different"
#endif
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
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
#ifdef NXPBUILD__PHHAL_HW_NCX33212
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) gaInstrBuffer2[16U] = {0};

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegister2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      VAR(uint8, ANFCRL_VAR) bRegister2,
                      VAR(uint32, ANFCRL_VAR) dwValue2
                                            )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
    { 0U };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[5] =
    { 0U };
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /*Check to ensure that the pointer is not equal null*/
    if(pDataParams2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    switch(pDataParams2->bRegisterOpState2)
    {
        case PHHAL_INSTR_STATE_CHECK_PARAM2 :
            /* Check data parameters. */
            if (((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
                    || ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
            }

            /* Check if the Register address is valid. */
            if (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS2)
            {
                if ((bRegister2 < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT2) || (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT2))
                {
                    return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
                }
            }

            /* Save set value of the CLIF_SS_TX1_RMCFG2 and CLIF_SS_TX2_RMCFG2 registers in case it is reset after LPCD */
            if(CLIF_SS_TX1_RMCFG2 == bRegister2)
            {
                pDataParams2->bSsTx1ConfigIsConfigured2 = 1U;
                pDataParams2->dwSetSsTx1ConfigValue2 = dwValue2;
            }

            if(CLIF_SS_TX2_RMCFG2 == bRegister2)
            {
                pDataParams2->bSsTx2ConfigIsConfigured2 = 1U;
                pDataParams2->dwSetSsTx2ConfigValue2 = dwValue2;
            }

            pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_SEND_CMD2;
            /* no break */
        case PHHAL_INSTR_STATE_SEND_CMD2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER2;

            sCmdParams2.bQueue2 = PH_ON2;

            /* Value */
            aInstrBuffer2[bIndex2++] = bRegister2;
            aInstrBuffer2[bIndex2++] = (uint8) (dwValue2 & 0xFFU);
            aInstrBuffer2[bIndex2++] = (uint8) ((dwValue2 >> 8U) & 0xFFU);
            aInstrBuffer2[bIndex2++] = (uint8) ((dwValue2 >> 16U) & 0xFFU);
            aInstrBuffer2[bIndex2++] = (uint8) ((dwValue2 >> 24U) & 0xFFU);

            sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
            sCmdParams2.wTxDataLength2 = bIndex2;
            sCmdParams2.pRxLength2 = &wRxLen2;
            sCmdParams2.ppRxBuffer2 = &pRxData2;
            /* Send command */
            PH_CHECK_INPROCESS_FCT2(status2,phhalHw_Ncx3321_InstMngr_HandleCmd2(pDataParams2, &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));
            break;
        default:
            status2 = PH_ERR_NCX3321_INTERNAL_ERROR2;
            break;
    }
    pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_CHECK_PARAM2;
    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterOrMask2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint8, ANFCRL_VAR) bRegister2,
                        VAR(uint32, ANFCRL_VAR) dwMask2
												)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
    { 0U };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[5] =
    { 0U };
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /*Check to ensure that the pointer is not equal null*/
    if(pDataParams2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    switch(pDataParams2->bRegisterOpState2)
	{
        case PHHAL_INSTR_STATE_CHECK_PARAM2 :
            /* Check data parameters. */
            if (((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
                    || ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
            }

            /* Check if the Register address is valid. */
            if (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS2)
            {
                if ((bRegister2 < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT2) || (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT2))
                {
                    return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
                }
            }

            pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_SEND_CMD2;
            /* no break */
        case PHHAL_INSTR_STATE_SEND_CMD2 :
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_OR_MASK2;

            sCmdParams2.bQueue2 = PH_ON2;

            /* Value */
            aInstrBuffer2[bIndex2++] = bRegister2;
            aInstrBuffer2[bIndex2++] = (uint8) (dwMask2 & 0xFFU);
            aInstrBuffer2[bIndex2++] = (uint8) ((dwMask2 >> 8U) & 0xFFU);
            aInstrBuffer2[bIndex2++] = (uint8) ((dwMask2 >> 16U) & 0xFFU);
            aInstrBuffer2[bIndex2++] = (uint8) ((dwMask2 >> 24U) & 0xFFU);

            sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
            sCmdParams2.wTxDataLength2 = bIndex2;
            sCmdParams2.pRxLength2 = &wRxLen2;
            sCmdParams2.ppRxBuffer2 = &pRxData2;

            /* Send command */
            PH_CHECK_INPROCESS_FCT2(status2,phhalHw_Ncx3321_InstMngr_HandleCmd2(pDataParams2, &sCmdParams2,
            		PH_EXCHANGE_DEFAULT2));
            break;
        default:
            status2 = PH_ERR_NCX3321_INTERNAL_ERROR2;
            break;
    }
    pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_CHECK_PARAM2;
    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          VAR(uint8, ANFCRL_VAR) bRegister2,
                          VAR(uint32, ANFCRL_VAR) dwMask2
													)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
	VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[5] =
	{ 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	/* Check if the Register address is valid. */
	if (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS2)
	{
		if ((bRegister2 < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT2) || (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT2))
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
		}
	}

	/* Command Type */
	sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_AND_MASK2;

	sCmdParams2.bQueue2 = PH_ON2;

	/* Value */
	aInstrBuffer2[bIndex2++] = bRegister2;
	aInstrBuffer2[bIndex2++] = (uint8) (dwMask2 & 0xFFU);
	aInstrBuffer2[bIndex2++] = (uint8) ((dwMask2 >> 8U) & 0xFFU);
	aInstrBuffer2[bIndex2++] = (uint8) ((dwMask2 >> 16U) & 0xFFU);
	aInstrBuffer2[bIndex2++] = (uint8) ((dwMask2 >> 24U) & 0xFFU);

	sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
	sCmdParams2.wTxDataLength2 = bIndex2;
	sCmdParams2.pRxLength2 = &wRxLen2;
	sCmdParams2.ppRxBuffer2 = &pRxData2;

	/* Send command */
	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(pDataParams2, &sCmdParams2,
			PH_EXCHANGE_DEFAULT2));

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRegTypeValueSets2,
                          VAR(uint16, ANFCRL_VAR) wSizeOfRegTypeValueSets2
													)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
	VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	/* Validate
	 * pRegTypeValueSets2
	 * wSizeOfRegTypeValueSets2
	 * wSizeOfRegTypeValueSets2 for modulus of 6. One set of write register is of 6 byte*/

	if ((NULL == pRegTypeValueSets2) || (wSizeOfRegTypeValueSets2 > PHHAL_HW_NCX3321_MAX_REGISTER_TYPE_VALUE_SET2)
			|| (wSizeOfRegTypeValueSets2 < PHHAL_HW_NCX3321_MIN_REGISTER_TYPE_VALUE_SET2)
			|| ((wSizeOfRegTypeValueSets2 % PHHAL_HW_NCX3321_MIN_REGISTER_TYPE_VALUE_SET2) != 0U))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
	}

	/* Build the command frame */
	sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_MULTIPLE2;

	sCmdParams2.bQueue2 = PH_OFF2;

	sCmdParams2.pTxDataBuff2 = pRegTypeValueSets2;
	sCmdParams2.wTxDataLength2 = wSizeOfRegTypeValueSets2;
	sCmdParams2.pRxLength2 = &wRxLen2;
	sCmdParams2.ppRxBuffer2 = &pRxData2;

	/* Send command */
	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(pDataParams2, &sCmdParams2,
			PH_EXCHANGE_DEFAULT2));

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadRegister2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      VAR(uint8, ANFCRL_VAR) bRegister2,
                      P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
											)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
	VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[1] =
	{ 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->bRegisterOpState2)
	{
		case PHHAL_INSTR_STATE_CHECK_PARAM2:
			/* Check if the Register address and input parameter is valid. */
			if (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS2)
			{
				if ((bRegister2 < (uint8)PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT2) || (bRegister2 > (uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT2))
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
				}
			}

			if (pValue2 == NULL)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_SEND_CMD2;
			return PH_STATUS_INPROCESS2;
			/* No break */

		case PHHAL_INSTR_STATE_SEND_CMD2:
			/* Command Type */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_READ_REGISTER2;

			sCmdParams2.bQueue2 = PH_OFF2;

			aInstrBuffer2[bIndex2++] = bRegister2;

			sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
			sCmdParams2.wTxDataLength2 = bIndex2;
			sCmdParams2.pRxLength2 = &wRxLen2;
			sCmdParams2.ppRxBuffer2 = &pRxData2;
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(pDataParams2, &sCmdParams2,
					PH_EXCHANGE_DEFAULT2));
			if (status2 == PH_ERR_NCX3321_SUCCESS2)
			{
				*pValue2 = pRxData2[0];
				*pValue2 |= (((uint32) pRxData2[1]) << 8U);
				*pValue2 |= (((uint32) pRxData2[2]) << 16U);
				*pValue2 |= (((uint32) pRxData2[3]) << 24U);
			}
			else
			{
				/* Do nothing */
			}
			break;

		default:
			status2 = PH_ERR_NCX3321_INTERNAL_ERROR2;
			break;
	}

	pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_CHECK_PARAM2;
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadRegisterMultiple2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRegisters2,
                          VAR(uint8, ANFCRL_VAR) bNumOfRegisters2,
                          P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppValues2
													)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNumExpBytes2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
	VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	/* Check input parameters. */
	if ((ppValues2 == NULL) || (pRegisters2 == NULL) || (bNumOfRegisters2 > ((uint8)PHHAL_HW_NCX3321_REG_END_ADDRESS2)))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
	}

	bNumExpBytes2 = bNumOfRegisters2 * PHHAL_HW_NCX3321_BYTES_PER_REGISTER2;
    /* Command Type */
	sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_READ_REGISTER_MULTIPLE2;

	sCmdParams2.bQueue2 = PH_OFF2;

	sCmdParams2.pTxDataBuff2 = pRegisters2;
	sCmdParams2.wTxDataLength2 = bNumOfRegisters2;
	sCmdParams2.pRxLength2 = &wRxLen2;
	sCmdParams2.ppRxBuffer2 = &pRxData2;

	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(pDataParams2, &sCmdParams2,
			PH_EXCHANGE_DEFAULT2));


	if (status2 == PH_ERR_NCX3321_SUCCESS2)
	{
		wRxLen2 = *sCmdParams2.pRxLength2;

		/* Validate the response length */
		if (wRxLen2 != bNumExpBytes2)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_HAL2);
		}
		*ppValues2 = *sCmdParams2.ppRxBuffer2;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteE2Prom2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      VAR(uint16, ANFCRL_VAR) wE2PromAddress2,
                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataToWrite2,
                      VAR(uint16, ANFCRL_VAR) wDataLength2
											)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = { 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Check if the Register address is valid. */
			if (((wE2PromAddress2 + wDataLength2) > PHHAL_HW_NCX3321_EEPROM_END_ADDRS2) ||
				(wDataLength2 == 0U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = pDataToWrite2;
			sCmdParams2.wTxDataLength2 = wDataLength2;

			gaInstrBuffer2[0] = (uint8)wE2PromAddress2;
			gaInstrBuffer2[1] =  (uint8)(wE2PromAddress2 >> 8);
			sCmdParams2.wAddnDataLen2 = 2U;
			sCmdParams2.pAddnData2 = &gaInstrBuffer2[0];

			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_WRITE_E2PROM2;
            sCmdParams2.pRxLength2 = &wRxLen2;
            sCmdParams2.ppRxBuffer2 = &pRxData2;

            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));
            break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadE2Prom2(
                       P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                       VAR(uint16, ANFCRL_VAR) wE2PromAddress2,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pReadData2,
                       VAR(uint16, ANFCRL_VAR) wDataLength2
										   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;

  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = { 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Check if the Register address is valid. */
			if (((wE2PromAddress2 + wDataLength2) > PHHAL_HW_NCX3321_EEPROM_END_ADDRS2) ||
				(pReadData2 == NULL))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}


			sCmdParams2.bQueue2 = PH_OFF2;

			gaInstrBuffer2[bIndex2++] = (uint8) wE2PromAddress2 ;
			gaInstrBuffer2[bIndex2++] = (uint8)(wE2PromAddress2 >> (8U));
			gaInstrBuffer2[bIndex2++] = (uint8) wDataLength2;
			gaInstrBuffer2[bIndex2++] = (uint8) (wDataLength2 >> 8U);

			sCmdParams2.pTxDataBuff2 = &gaInstrBuffer2[0];
			sCmdParams2.wTxDataLength2 = bIndex2;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;

			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_READ_E2PROM2;
            sCmdParams2.ppRxBuffer2 = &pReadData2;
            sCmdParams2.pRxLength2 = &wRxLen2;

            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));
            break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_TransmitRFData2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint16, ANFCRL_VAR) wOption2,
                        VAR(uint8, ANFCRL_VAR) bTxLastBits2,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                        VAR(uint16, ANFCRL_VAR) wTxBufferLength2
												)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Validate transmission buffer length
			* To validate bNumberOfValidBits indicate the exact data length to be transmitted.
			* */
			if (((pTxBuffer2 == NULL) && (wTxBufferLength2 != 0U) && ((wOption2 & PH_TRANSMIT_PREV_FRAME2) == 0U))||
				(wTxBufferLength2 > PHHAL_HW_NCX3321_TX_DATA_MAX_LENGTH2) ||
				(bTxLastBits2 > PHHAL_HW_NCX3321_MAX_NUM_OF_BITS_FOR_LAST_BYTE2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			if ((0U == (wOption2 & (PH_TRANSMIT_LEAVE_BUFFER_BIT2  | PH_TRANSMIT_PREV_FRAME2))))
			{
				/* clear internal buffer if requested */
				pDataParams2->wTxBufLen2 = 0U;
				pDataParams2->wTxBufStartPos2 = 0U;
				pDataParams2->wTxFwDataLen2 = 0U;
			}

			gaInstrBuffer2[bIndex2++] = bTxLastBits2;
			gaInstrBuffer2[bIndex2++] = 0;

			sCmdParams2.pAddnData2 = &gaInstrBuffer2[0];
			sCmdParams2.wAddnDataLen2 = bIndex2;

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = pTxBuffer2;
			sCmdParams2.wTxDataLength2 = wTxBufferLength2;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/* Command Type */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA2;
			sCmdParams2.pRxLength2 = &wRxLen2;
			sCmdParams2.ppRxBuffer2 = &pRxData2;

			/* Send command */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
				pDataParams2,
				&sCmdParams2,
				wOption2));

			break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RetrieveRFData2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength2
												)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuffer2 = NULL;
  VAR(uint16, ANFCRL_VAR) wTmpRxBufferLen2 = 0U;
  VAR(uint16, ANFCRL_VAR) wTmpRxBufferSize2 = 0U;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Validate input parameters. */
			if ((pRxBuffer2 == NULL) ||
				(pRxDataLength2 == NULL))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			(void) phhalHw_Ncx3321_Int_GetRxBuffer2(pDataParams2, &pTmpRxBuffer2, &wTmpRxBufferLen2, &wTmpRxBufferSize2);

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = NULL;
			sCmdParams2.wTxDataLength2 = 0u;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA2;
            sCmdParams2.ppRxBuffer2 = &pTmpRxBuffer2;
            sCmdParams2.pRxLength2 = &wRxLen2;

            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));

            if(status2 == PH_ERR_NCX3321_SUCCESS2)
            {
                *pRxBuffer2 = *sCmdParams2.ppRxBuffer2;
                *pRxDataLength2 = *sCmdParams2.pRxLength2;
            }
            break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReceiveRFData2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint8, ANFCRL_VAR) bRespConfigMask2,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength2
												)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuffer2 = NULL;
  VAR(uint8, ANFCRL_VAR) bInstrData = bRespConfigMask2;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Validate input parameters. */
			if ((ppRxBuffer2 == NULL) ||
				(pRxDataLength2 == NULL))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = &bInstrData;
			sCmdParams2.wTxDataLength2 = 1u;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_RECEIVE_RF_DATA2;
            sCmdParams2.pRxLength2 = &wRxLen2;
            sCmdParams2.ppRxBuffer2 = &pTmpRxBuffer2;

            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_RECEIVE_DEFAULT2));

            if(status2 == PH_ERR_NCX3321_SUCCESS2)
            {
                if (ppRxBuffer2 != NULL)
                {
                    *ppRxBuffer2 = *sCmdParams2.ppRxBuffer2;
                }
                if (pRxDataLength2 != NULL)
                {
                    *pRxDataLength2 = *sCmdParams2.pRxLength2;
                }
            }

            break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}



FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ExchangeRFData2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint16, ANFCRL_VAR) wOption2,
                        VAR(uint8, ANFCRL_VAR) bTxLastBits2,
                        VAR(uint8, ANFCRL_VAR) bRespControl2,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData2,
                        VAR(uint16, ANFCRL_VAR) wTxDataLength2,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxData2,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength2
												)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Validate input parameters */
			if (((pTxData2 == NULL) && (wTxDataLength2 != 0U)) ||
				(wTxDataLength2 > PHHAL_HW_NCX3321_TX_DATA_MAX_LENGTH2) ||
				(bTxLastBits2 > PHHAL_HW_NCX3321_MAX_NUM_OF_BITS_FOR_LAST_BYTE2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = pTxData2;
			sCmdParams2.wTxDataLength2 = wTxDataLength2;

			if ((0U == ((wOption2 & PH_EXCHANGE_LEAVE_BUFFER_BIT2))))
			{
				/* clear internal buffer if requested */
				pDataParams2->wTxBufLen2 = 0U;
				pDataParams2->wTxBufStartPos2 = 0U;
				pDataParams2->wTxFwDataLen2 = 0U;
			}

			gaInstrBuffer2[bIndex2++] = bTxLastBits2;
			gaInstrBuffer2[bIndex2++] = bRespControl2;

			sCmdParams2.pAddnData2 = &gaInstrBuffer2[0];
			sCmdParams2.wAddnDataLen2 = bIndex2;
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/* Command Type */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA2;
			sCmdParams2.pRxLength2 = &wRxLen2;
			sCmdParams2.ppRxBuffer2 = &pRxData2;

			PH_CHECK_INPROCESS_FCT2(status2,  phhalHw_Ncx3321_InstMngr_HandleCmd2(
				pDataParams2,
				&sCmdParams2,
				wOption2));
			break;
	}

	if(status2 == PH_ERR_NCX3321_SUCCESS2)
	{
		if (ppRxData2 != NULL)
		{
			*ppRxData2 = *sCmdParams2.ppRxBuffer2;
		}
		if (pRxDataLength2 != NULL)
		{
			*pRxDataLength2 = *sCmdParams2.pRxLength2;
		}
	}
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeStandby2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          VAR(uint8, ANFCRL_VAR) bConfigMask2,
                          VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs2
													)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			gaInstrBuffer2[bIndex2++] = bConfigMask2;
			gaInstrBuffer2[bIndex2++] = (uint8)wWakeupCounterInMs2;
			gaInstrBuffer2[bIndex2++] = (uint8)(wWakeupCounterInMs2 >> 8);

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = &gaInstrBuffer2[0];
			sCmdParams2.wTxDataLength2 = bIndex2;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/* Command Type */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_STANDBY2;
			sCmdParams2.pRxLength2 = &wRxLen2;
			sCmdParams2.ppRxBuffer2 = &pRxData2;

			/* Send command */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
				pDataParams2,
				&sCmdParams2,
				PH_EXCHANGE_DEFAULT2));
			break;
	}

	if(status2 == PH_ERR_NCX3321_SUCCESS2)
	{
		pDataParams2->dwExpectedEvent2 = PH_NCX3321_EVT_BOOT2;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LPCD_SetConfig2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint16, ANFCRL_VAR) wConfig2,
                        VAR(uint32, ANFCRL_VAR) dwValue2
												)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_NCX3321_SUCCESS2;

	switch(wConfig2)
	{

	case PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS2:
	{
		/* Value should be greater than 3ms */
		if(dwValue2 >= 0x03U)
		{
			pDataParams2->wLPCDWakeupCounterInMs2 = (uint16)dwValue2;
		}
		else
		{
			pDataParams2->wLPCDWakeupCounterInMs2 = 0x03U;
		}
	 }
	 break;

	case PHHAL_HW_CONFIG_LPCD_MODE2:
		if((dwValue2 == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT2) || (dwValue2 ==  PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN2))
		{
			pDataParams2->bLpcdMode2 = (uint8)dwValue2;
		}
		else
		{
			statusTmp2 = PH_ERR_NCX3321_INVALID_PARAMETER2;
		}
		break;

	case PHHAL_HW_CONFIG_LPCD_CONFIG2:
		if ((dwValue2 <=  PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_LPCD2) ||
			(dwValue2 == PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_CALIB2))
		{
			pDataParams2->bLpcdConfig2 = (uint8)dwValue2;
		}
		else
		{
			statusTmp2 = PH_ERR_NCX3321_INVALID_PARAMETER2;
		}
		break;

	case PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL2:
		pDataParams2->bLpcdWakeUpCtrl2 = (uint8)dwValue2;
		break;

	case PHHAL_HW_CONFIG_LPCD_REF_VAL2:
		pDataParams2->dwLpcdRefVal2 = dwValue2;
		break;

    case PHHAL_HW_CONFIG_LPCD_HFATT_VAL2:
        pDataParams2->bHFATTVal2 = (uint8)dwValue2;
        break;

	default:
		statusTmp2 = PH_ERR_NCX3321_UNSUPPORTED_PARAMETER2;
		break;
	}

	return PH_ADD_COMPCODE2(statusTmp2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LPCD_GetConfig2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint16, ANFCRL_VAR) wConfig2,
                        P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
												)
{
	switch(wConfig2)
	{
	case PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS2:
		*pValue2 = pDataParams2->wLPCDWakeupCounterInMs2;
		break;

	case PHHAL_HW_CONFIG_LPCD_MODE2:
		*pValue2 = pDataParams2->bLpcdMode2;
		break;

	case PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL2:
		*pValue2 = pDataParams2->bLpcdWakeUpCtrl2;
		break;

	case PHHAL_HW_CONFIG_LPCD_REF_VAL2:
		*pValue2 = pDataParams2->dwLpcdRefVal2;
		break;

	case PHHAL_HW_CONFIG_LPCD_RETRIEVE_EVENT_STATUS2:
		*pValue2 = pDataParams2->dwEventStatus2;
		break;

    case PHHAL_HW_CONFIG_LPCD_HFATT_VAL2:
        *pValue2 = pDataParams2->bHFATTVal2;
        break;

	default:
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);
	}

	return PH_ERR_NCX3321_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeLpcd2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint8, ANFCRL_VAR) bLpcdMode2,
                        VAR(uint8, ANFCRL_VAR) bWakeUpCntrlHwLpcd2,
                        VAR(uint32, ANFCRL_VAR) dwLpcdRefValue2,
                        VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs2
												)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			gaInstrBuffer2[bIndex2++] = bLpcdMode2;
			gaInstrBuffer2[bIndex2++] = bWakeUpCntrlHwLpcd2;
			gaInstrBuffer2[bIndex2++] = (uint8) dwLpcdRefValue2;
			gaInstrBuffer2[bIndex2++] = (uint8) (dwLpcdRefValue2 >> 8);
			gaInstrBuffer2[bIndex2++] = (uint8) (dwLpcdRefValue2 >> 16);
			gaInstrBuffer2[bIndex2++] = (uint8) (dwLpcdRefValue2 >> 24);
			gaInstrBuffer2[bIndex2++] = (uint8)wWakeupCounterInMs2;
			gaInstrBuffer2[bIndex2++] = (uint8)(wWakeupCounterInMs2 >> 8);

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = &gaInstrBuffer2[0];
			sCmdParams2.wTxDataLength2 = bIndex2;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/* Command Type */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_LPCD2;
			sCmdParams2.pRxLength2 = &wRxLen2;
			sCmdParams2.ppRxBuffer2 = &pRxData2;

			/* Send command */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
				pDataParams2,
				&sCmdParams2,
				PH_EXCHANGE_DEFAULT2));
			break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeAutocoll2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          VAR(uint8, ANFCRL_VAR) bRfTechnologyMask2,
                          VAR(uint8, ANFCRL_VAR) bAutocollMode2
													)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = {0U};
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[2] = {0U, 0U};
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
				|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	if(0U == bRfTechnologyMask2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
	}

	if (pDataParams2->HwEventObj2.bEventState2 == PH_TOOLS_EVENT_IDLE2)
	{
		sCmdParams2.bQueue2 = PH_OFF2;

		aInstrBuffer2[bIndex2++] = bRfTechnologyMask2;
		aInstrBuffer2[bIndex2++] = bAutocollMode2;

		sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
		sCmdParams2.wTxDataLength2 = bIndex2;
	}
	/* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_AUTOCOLL2;
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;

    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
            pDataParams2,
            &sCmdParams2,
            PH_EXCHANGE_DEFAULT2));

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeBootNormal2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
													)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[4] = {0};
	/* Check data parameters. */
	if ((pDataParams2 == NULL) ||
		(((pDataParams2->wId2) & PH_COMP_MASK2) != PH_COMP_HAL2) ||
		(((pDataParams2->wId2) & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}
	aCmd2[0]  = PHHAL_HW_NCX3321_INT_SPI_WRITE2;
	aCmd2[1]  = 0x20;
	aCmd2[2]  = 0x01;
	aCmd2[3]  = 0x00;

	return phhalHw_Ncx3321_Send2(pDataParams2,&aCmd2[0], 4, PH_ON2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeNormal2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
												)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[4] = {0};
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventReceived2 = 0x0U;

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			aCmd2[0]  = PHHAL_HW_NCX3321_INT_SPI_WRITE2;
			aCmd2[1]  = 0x20;
			aCmd2[2]  = 0x00;
			aCmd2[3]  = 0x00;

			PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Send2(pDataParams2,&aCmd2[0], 4, PH_ON2));
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/*Wait for event*/
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Int_EventWait2(
						 pDataParams2,
						 PH_NCX3321_EVT_IDLE2 | PH_NCX3321_EVT_GENERAL_ERROR2,
						 PHHAL_HW_ABORT_EVT_TIMEOUT2,
						 TRUE,
						 &dwEventReceived2));
			break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

#ifdef NXPBUILD__PHPAL_MIFARE_SW
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_MifareAuthenticate2(
                                                   P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey2,
                                                   VAR(uint8, ANFCRL_VAR) bKeyType2,
                                                   VAR(uint8, ANFCRL_VAR) bBlockNo2,
                                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2
                                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2;
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataLenTmp2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferLength2 = 0;

    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 aCmdBuffer2[13];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_BUF2 aRspBuffer2;
    VAR(uint32, ANFCRL_VAR) dwRegister2;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = {0U};

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    /* Validate input parameters */
    if ((NULL == pKey2) ||
        (NULL == pUid2) ||
        ((bKeyType2 != PHHAL_HW_MFC_KEYA2) && (bKeyType2 != PHHAL_HW_MFC_KEYB2)))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
    }

    /* Build the command frame */
    wBufferLength2 = 0U;

    /* Write Tx Data */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE2;

    sCmdParams2.bQueue2 = PH_OFF2;

    /* Copy the data to be transmitted*/
    (void)memcpy(&aCmdBuffer2[wBufferLength2], pKey2, PHHAL_HW_MFC_KEY_LENGTH2);
    wBufferLength2 += PHHAL_HW_MFC_KEY_LENGTH2;

    if(bKeyType2 == PHHAL_HW_MFC_KEYA2)
    {
        aCmdBuffer2[wBufferLength2++] = PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE_KEY_TYPE_A2;
    }
    else
    {
        aCmdBuffer2[wBufferLength2++] = PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE_KEY_TYPE_B2;
    }

    aCmdBuffer2[wBufferLength2++] = bBlockNo2;
    (void)memcpy(&aCmdBuffer2[wBufferLength2], pUid2, PHHAL_HW_NCX3321_MFC_UID_LEN2);
    wBufferLength2 += PHHAL_HW_NCX3321_MFC_UID_LEN2;

    sCmdParams2.pTxDataBuff2 = &aCmdBuffer2[0];
    sCmdParams2.wTxDataLength2 = wBufferLength2;
    sCmdParams2.ppRxBuffer2 = &aRspBuffer2;
    sCmdParams2.pRxLength2 = &wDataLenTmp2;

    /* Send it to the chip */
    status2 =  phhalHw_Ncx3321_InstMngr_HandleCmd2(
            pDataParams2,
            &sCmdParams2,
            PH_EXCHANGE_DEFAULT2);

    /* Validate the response */
    if(PH_ERR_NCX3321_SUCCESS2 == status2)
    {
        /* Check auth success */
        PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, SYSTEM_CONFIG2, &dwRegister2));
        if((0U == ((dwRegister2 & SYSTEM_CONFIG_MFC_CRYPTO_ON_MASK2))))
        {
            status2 = PH_ERR_AUTH_ERROR2;
            pDataParams2->bMfcCryptoEnabled2 = PH_OFF2;
        }
        else
        {
            pDataParams2->bMfcCryptoEnabled2 = PH_ON2;
        }
    }

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LoadRfConfiguration2(
                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                          VAR(uint8, ANFCRL_VAR) bRfTxConfiguration2,
                          VAR(uint8, ANFCRL_VAR) bRfRxConfiguration2
													)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;

    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Check TX and RX configuration parameters. */
			if (((bRfTxConfiguration2 > PHHAL_HW_NCX3321_MAX_RF_TX_CONFIGURATION_INDEX2) && (bRfTxConfiguration2 != 0xFFU)) ||
				((bRfRxConfiguration2 > 0x9DU) && (bRfRxConfiguration2 != 0xFFU)) ||
				(bRfRxConfiguration2 < 0x80U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* If "no change" needed for TX and RX configuration, return success. */
			if ((bRfTxConfiguration2 == 0xFFU) && (bRfRxConfiguration2 == 0xFFU))
			{
				return PH_ERR_NCX3321_SUCCESS2;
			}

			sCmdParams2.bQueue2 = PH_ON2;

			/* Value */
			gaInstrBuffer2[bIndex2++] = bRfTxConfiguration2;
			gaInstrBuffer2[bIndex2++] = bRfRxConfiguration2;

			sCmdParams2.pTxDataBuff2 = &gaInstrBuffer2[0];
			sCmdParams2.wTxDataLength2 = bIndex2;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/* Command Type */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_LOAD_RF_CONFIGURATION2;
			sCmdParams2.pRxLength2 = &wRxLen2;
			sCmdParams2.ppRxBuffer2 = &pRxData2;
			/* Send command */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
				pDataParams2,
				&sCmdParams2,
				PH_EXCHANGE_DEFAULT2));
			break;
	}

	return  PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_UpdateRfConfiguration2(
                            P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfiguration2,
                            VAR(uint8, ANFCRL_VAR) bRfConfigurationSize2
														)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;

  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Validate input parameters.
			* bRfConfigurationSize2 is not a multiple of PHHAL_HW_NCX3321_RF_CONFIGURATION_SIZE2
			* bRfConfigurationSize2 is greater than PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE2
			* */
			if ((NULL == pRfConfiguration2) ||
				(bRfConfigurationSize2 > PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE2) ||
				(0U != (bRfConfigurationSize2 % PHHAL_HW_NCX3321_RF_CONFIGURATION_SIZE2)))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = pRfConfiguration2;
			sCmdParams2.wTxDataLength2 = bRfConfigurationSize2;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_UPDATE_RF_CONFIGURATION2;
            sCmdParams2.pRxLength2 = &wRxLen2;
            sCmdParams2.ppRxBuffer2 = &pRxData2;

            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));
            break;
	}

	return  PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RetrieveRfConfiguration2(
                            P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                            VAR(uint8, ANFCRL_VAR) bRfConfiguration2,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfBuf2,
                            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfBufSize2
														)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Validate input parameters.
			* bRfRxConfiguration2 is greater than the maximum RF RX configuration
			* bRfRxConfiguration2 is not the PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX
			* */
			if (((bRfConfiguration2 < PHHAL_HW_NCX3321_MIN_RF_RX_CONFIGURATION_INDEX2)
				&& (bRfConfiguration2 > PHHAL_HW_NCX3321_MAX_RF_TX_CONFIGURATION_INDEX2)) ||
				(bRfConfiguration2 > PHHAL_HW_NCX3321_MAX_RF_RX_CONFIGURATION_INDEX2) ||
				(*pRfConfBufSize2 < PHHAL_HW_NCX3321_MIN_RF_CONFIGURATION_BUFFER_SIZE2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			sCmdParams2.bQueue2 = PH_OFF2;

			sCmdParams2.pTxDataBuff2 = &bRfConfiguration2;
			sCmdParams2.wTxDataLength2 = 1U;
			sCmdParams2.pAddnData2 = NULL;
			sCmdParams2.wAddnDataLen2 = 0u;
			/*no break*/

		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			/* Build the command frame */
			sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_GET_RF_CONFIGURATION2;
			sCmdParams2.pRxLength2 = pRfConfBufSize2;
			sCmdParams2.ppRxBuffer2 = &pRfConfBuf2;

			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
				pDataParams2,
				&sCmdParams2,
				PH_EXCHANGE_DEFAULT2));
			break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RfOn2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint8, ANFCRL_VAR) bRfOnConfig2
									)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;

  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	/* Validate RF ON parameter */
	if (bRfOnConfig2 > 3U)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
	}

	if(pDataParams2->HwEventObj2.bEventState2 == PH_TOOLS_EVENT_IDLE2)
	{
		sCmdParams2.bQueue2 = PH_OFF2;

		/* Value */
		gaInstrBuffer2[bIndex2++] = bRfOnConfig2;

		sCmdParams2.pTxDataBuff2 = &gaInstrBuffer2[0];
		sCmdParams2.wTxDataLength2 = bIndex2;
		sCmdParams2.pAddnData2 = NULL;
		sCmdParams2.wAddnDataLen2 = 0u;


	}
    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_FIELD_ON2;
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;
    /* Send command */
    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
            pDataParams2,
            &sCmdParams2,
            PH_EXCHANGE_DEFAULT2));

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RfOff2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
									)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
	{ 0U };

	/* Check data parameters. */
	if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

	if(pDataParams2->HwEventObj2.bEventState2 == PH_TOOLS_EVENT_IDLE2)
    {
        sCmdParams2.bQueue2 = PH_OFF2;
        sCmdParams2.wTxDataLength2 = 0u;
        sCmdParams2.pTxDataBuff2 = NULL;
        sCmdParams2.pAddnData2 = NULL;
        sCmdParams2.wAddnDataLen2 = 0u;
    }
    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_FIELD_OFF2;
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;
    /* Send command */
    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
            pDataParams2,
            &sCmdParams2,
            PH_EXCHANGE_DEFAULT2));

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ConfigureTestBusDigital2(
                                                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                                        VAR(uint8, ANFCRL_VAR) bSignalIndex2,
                                                        VAR(uint8, ANFCRL_VAR) bBitIndex2,
                                                        VAR(uint8, ANFCRL_VAR) bPadIndex2
                                                        )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[3U] = {0};
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) PH_MEMLOC_REM2 sCmdParams2 = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_CONFIGURE_TESTBUS_DIGITAL2;

    sCmdParams2.bQueue2 = PH_OFF2;

    /* Value */
    aInstrBuffer2[bIndex2++] = bSignalIndex2;
    aInstrBuffer2[bIndex2++] = bBitIndex2;
    aInstrBuffer2[bIndex2++] = bPadIndex2;

    sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
    sCmdParams2.wTxDataLength2 = bIndex2;
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;

    /* Send command */
    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    return  PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ConfigureTestBusAnalog2(
                                                       P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                                       VAR(uint8, ANFCRL_VAR) bConfig2,
                                                       VAR(uint8, ANFCRL_VAR) bCombinedMode2,
                                                       VAR(uint8, ANFCRL_VAR) bTBIndex02,
                                                       VAR(uint8, ANFCRL_VAR) bTBIndex12,
                                                       VAR(uint8, ANFCRL_VAR) bShiftIndex02,
                                                       VAR(uint8, ANFCRL_VAR) bShiftIndex12,
                                                       VAR(uint8, ANFCRL_VAR) bMask02,
                                                       VAR(uint8, ANFCRL_VAR) bMask12
                                                       )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[8U] = {0};
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) PH_MEMLOC_REM2 sCmdParams2 = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) ||
        (((pDataParams2->wId2) & PH_COMP_MASK2) != PH_COMP_HAL2) ||
        (((pDataParams2->wId2) & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_CONFIGURE_TESTBUS_ANALOG2;

    sCmdParams2.bQueue2 = PH_OFF2;

    /* Value */
    aInstrBuffer2[bIndex2++] = bConfig2;
    aInstrBuffer2[bIndex2++] = bCombinedMode2;
    aInstrBuffer2[bIndex2++] = bTBIndex02;
    aInstrBuffer2[bIndex2++] = bTBIndex12;
    aInstrBuffer2[bIndex2++] = bShiftIndex02;
    aInstrBuffer2[bIndex2++] = bShiftIndex12;
    aInstrBuffer2[bIndex2++] = bMask02;
    aInstrBuffer2[bIndex2++] = bMask12;

    sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
    sCmdParams2.wTxDataLength2 = bIndex2;
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;

    /* Send command */
    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    return  PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsEnable2(
                                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                          VAR(uint8, ANFCRL_VAR) bOption2
                                          )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) PH_MEMLOC_REM2 sCmdParams2 = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    /* Validate Option parameter */
    if ((bOption2 != PH_OFF2) && (bOption2 != PH_ON2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
    }

    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_CTS_ENABLE2;

    sCmdParams2.bQueue2 = PH_OFF2;

    sCmdParams2.pTxDataBuff2 = &bOption2;
    sCmdParams2.wTxDataLength2 = 0x01U;
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;

    /* Send command */
    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    if(status2 == PH_ERR_NCX3321_SUCCESS2)
    {
    	pDataParams2->dwExpectedEvent2 = PH_NCX3321_EVT_CTS2;
    }
    return  PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsConfig2(
                                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                          P2VAR(phhalHw_Ncx3321_Instr_CtsConfig_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCtsConfig2
                                          )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) PH_MEMLOC_REM2 sCmdParams2 = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    /* Validate input parameter */
    if (pCtsConfig2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
    }

    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_CTS_CONFIGURE2;

    sCmdParams2.bQueue2 = PH_OFF2;

    /* Value */
    sCmdParams2.pTxDataBuff2 = (uint8 *) pCtsConfig2;
    sCmdParams2.wTxDataLength2 = (uint16)sizeof(phhalHw_Ncx3321_Instr_CtsConfig_t2);
    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;

    /* Send command */
    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    return  PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsRetrieveLog2(
                                               P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                               VAR(uint8, ANFCRL_VAR) bChunkSize2,
                                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLogData2,
                                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bLogDataSize2
                                               )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    /* Validate input parameter */
    if ((pLogData2 == NULL) || (bLogDataSize2 == NULL))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
    }

    if (pDataParams2->bCTSEvent2 == PH_OFF2)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_NO_CTS_EVENT2, PH_COMP_HAL2);
    }
    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_CTS_RETRIEVE_LOG2;

    sCmdParams2.bQueue2 = PH_OFF2;

    /* Value */
    sCmdParams2.pTxDataBuff2 = &bChunkSize2;
    sCmdParams2.wTxDataLength2 = 0x01U;
    sCmdParams2.ppRxBuffer2 = &pLogData2;
    sCmdParams2.pRxLength2 = &wRxLen2;

    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    if ((status2 == PH_ERR_NCX3321_SUCCESS2) || (status2 == PH_ERR_NCX3321_SUCCESS_CHAINING2))
    {
        *bLogDataSize2 = (uint8) wRxLen2;
    }

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_GetDieId2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDieIdValue2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 =
    { 0U };
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
            || ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    switch(pDataParams2->HwEventObj2.bEventState2)
    {
        case PH_TOOLS_EVENT_IDLE2:
            /* Validate input parameter */
            if (pDieIdValue2 == NULL)
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
            }
            /* Command Type */
            sCmdParams2.bQueue2 = PH_OFF2;
            sCmdParams2.pTxDataBuff2 = NULL;
            /*no break*/
        case PH_TOOLS_EVENT_PENDING2:
        case PH_TOOLS_EVENT_OCCUR2:
            sCmdParams2.pRxLength2 = &wRxLen2;
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_GET_DIE_ID2;
            sCmdParams2.ppRxBuffer2 = &pDieIdValue2;
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));
            if (wRxLen2 != 16U)
            {
                status2 = PH_ERR_LENGTH_ERROR2;
            }
            break;
    }

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_GetVersion2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(phhalHw_Ncx3321_Version_t2, AUTOMATIC, ANFCRL_APPL_DATA) pVersion2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
  VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = { 0U };
  VAR(uint8, ANFCRL_VAR) aVersionInfo2[4] = { 0 };
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVersionInfo2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;

    pVersionInfo2 = &aVersionInfo2[0];
    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
            || ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    switch(pDataParams2->HwEventObj2.bEventState2)
    {
        case PH_TOOLS_EVENT_IDLE2:
            /* Validate input parameter */
            if (pVersion2 == NULL)
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_PARAMETER2, PH_COMP_HAL2);
            }

            sCmdParams2.bQueue2 = PH_OFF2;
            sCmdParams2.pTxDataBuff2 = NULL;
            /*no break*/
        case PH_TOOLS_EVENT_PENDING2:
        case PH_TOOLS_EVENT_OCCUR2:
            /* Command Type */
            sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_GET_VERSION2;
            sCmdParams2.ppRxBuffer2 = &pVersionInfo2;
            sCmdParams2.pRxLength2 = &wRxLen2;
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_HandleCmd2(
                    pDataParams2,
                    &sCmdParams2,
                    PH_EXCHANGE_DEFAULT2));
            if (status2 == PH_ERR_NCX3321_SUCCESS2)
            {
                pVersion2->bHw_Version2 = aVersionInfo2[0];
                pVersion2->bROM_Version2 = aVersionInfo2[1];
                pVersion2->wFW_Version2 =  (uint16)aVersionInfo2[2] | ((uint16)aVersionInfo2[3] << 8);
            }
            break;
    }

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeDownload2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) sCmdParams2 = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;

    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;
    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_DOWNLOAD2;
    sCmdParams2.bQueue2 = PH_OFF2;

    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Instr_PrbsTest2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint8, ANFCRL_VAR) bPrbs_type2)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aInstrBuffer2[1] = {0};
    VAR(phhalHw_InstMngr_CmdParams_t2, ANFCRL_VAR) PH_MEMLOC_REM2 sCmdParams2 = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxData2 = NULL;


    /* Check data parameters. */
    if ((pDataParams2 == NULL) || ((pDataParams2->wId2 & PH_COMP_MASK2) != PH_COMP_HAL2)
    			|| ((pDataParams2->wId2 & PH_COMPID_MASK2) != PHHAL_HW_NCX3321_ID2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_NCX3321_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
    }

    aInstrBuffer2[bIndex2++] = bPrbs_type2;

    sCmdParams2.pRxLength2 = &wRxLen2;
    sCmdParams2.ppRxBuffer2 = &pRxData2;
    /* Command Type */
    sCmdParams2.bCmd2 = PHHAL_HW_NCX3321_INSTR_PRBS_TEST2;
    sCmdParams2.bQueue2 = PH_OFF2;
    sCmdParams2.pTxDataBuff2 = &aInstrBuffer2[0];
    sCmdParams2.wTxDataLength2 = bIndex2;

    status2 = phhalHw_Ncx3321_InstMngr_HandleCmd2(
       pDataParams2,
       &sCmdParams2,
       PH_EXCHANGE_DEFAULT2);

    return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

#ifdef __cplusplus
}
#endif
