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
*   @file    phalFelica_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlFelica - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalFelica Felica
*   @ingroup phalApplication
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
#include <phpalFelica.h>
#include <phalFelica.h>
#include <ph_RefDefs.h>
#include <phTools.h>
#include <phDriver.h>

#ifdef NXPBUILD__PHAL_FELICA_SW

#include "phalFelica_Sw.h"
#include <phCryptoSym.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalFelica_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALFELICA_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHALFELICA_SW_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHALFELICA_SW_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHALFELICA_SW_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHALFELICA_SW_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHALFELICA_SW_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalFelica_Sw.h header file are of the same vendor */
#if (PHALFELICA_SW_VENDOR_ID_C != PHALFELICA_SW_VENDOR_ID)
    #error "phalFelica_Sw.c and phalFelica_Sw.h have different vendor ids"
#endif
/* Check if current file and phalFelica_Sw.h header file are of the same Autosar version */
#if ((PHALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C    != PHALFELICA_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHALFELICA_SW_AR_RELEASE_MINOR_VERSION_C    != PHALFELICA_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHALFELICA_SW_AR_RELEASE_REVISION_VERSION_C != PHALFELICA_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalFelica_Sw.c and phalFelica_Sw.h are different"
#endif
/* Check if current file and phalFelica_Sw.h header file are of the same Software version */
#if ((PHALFELICA_SW_SW_MAJOR_VERSION_C != PHALFELICA_SW_SW_MAJOR_VERSION) || \
     (PHALFELICA_SW_SW_MINOR_VERSION_C != PHALFELICA_SW_SW_MINOR_VERSION) || \
     (PHALFELICA_SW_SW_PATCH_VERSION_C != PHALFELICA_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalFelica_Sw.c and phalFelica_Sw.h are different"
#endif
#endif /* NXPBUILD__PHAL_FELICA_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW
typedef enum {
	PHAL_FELICA_PROTECT_IDLE = 0,
	PHAL_FELICA_PROTECT_READ_MAC,
	PHAL_FELICA_PROTECT_READ_CARDKEY_VERSION,
	PHAL_FELICA_PROTECT_WRITE_CARDKEY_VERSION,
	PHAL_FELICA_PROTECT_WRITE_CARDKEY,
	PHAL_FELICA_PROTECT_AUTHENTICATE_CHECK,
	PHAL_FELICA_PROTECT_READ_ATTRIB,
	PHAL_FELICA_PROTECT_WRITE_ATTRIB,
	PHAL_FELICA_PROTECT_PREPARE_WRITE_MEM_CONFIG,
	PHAL_FELICA_PROTECT_WRITE_MEM_CONFIG,
} FELICA_PROTECT_StateType_t;

typedef enum {
	PHAL_FELICA_AUTHENTICATE_IDLE = 0,
	PHAL_FELICA_AUTHENTICATE_WRITE_RC_BLOCK,
	PHAL_FELICA_AUTHENTICATE_CREATE_SESSION_KEY,
	PHAL_FELICA_AUTHENTICATE_READ_MAC_ID_BLOCK,
	PHAL_FELICA_AUTHENTICATE_WRITE_STATE,
	PHAL_FELICA_AUTHENTICATE_READ_STATE,
} FELICA_AUTHENTICATE_StateType_t;

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

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_Init(
              P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelica_DataParams,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoSymDataParams
						  )
{
    /* parameter structure length check */
    if (sizeof(phalFelica_Sw_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
    }
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pPalFelica_DataParams);

	/* init private data */
	pDataParams->wId = PH_COMP_AL_FELICA | PHAL_FELICA_SW_ID;
	pDataParams->pPalFelicaDataParams = pPalFelica_DataParams;
	pDataParams->wAdditionalInfo = 0x0000;
	pDataParams->bAuthenticate = 0U;
	pDataParams->pCryptoSymDataParams = pCryptoSymDataParams;
	return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_RequestResponse(
    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMode
		)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[1] = {0};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0;

	/* Build the command frame */
	aCmd[0] = PHPAL_FELICA_SW_CMD_REQ_RESP;

	/* Exchange command */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_DEFAULT,
		0,
		aCmd,
		1,
		&pRxBuffer,
		&wRespLength));

	/* Check the length */
	if (wRespLength != 1U)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
	}

	/* Note: The IDm has already been checked by the phpalFelica_Exchange function. */
	/* Success */
	*pMode = pRxBuffer[0];
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_RequestService(
                    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bTxNumServices,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxServiceList,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumServices,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceList
										)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[2]={0};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp == PH_STATUS_INPROCESS)
	{
		PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
			pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			0U,
			aCmd,
			0U,
			&pRxBuffer,
			&wRespLength));
		/* Check the length (number of services and service list)*/
		if ((wRespLength < 1U) || (wRespLength != ((((uint16)(pRxBuffer[0])) * 2U) + 1U)))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
		}

		/* Success */
		*pRxNumServices = pRxBuffer[0];
		(void)phTools_memcpy(pRxServiceList, &pRxBuffer[1], (((uint32)*pRxNumServices) * 2U));
		return PH_ERR_SUCCESS;
	}
	/* Parameter check */
	if (bTxNumServices < 1U)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
	}

	/* Build the command frame */
	/* send the command frame fragmented as following:
	First send [cmd][num_of_srvcs]
	Then send the service code list in 2-byte chunks since a single service code element
	consists of 2 bytes. */
	aCmd[0] = PHPAL_FELICA_SW_CMD_REQ_SERVICE;
	aCmd[1] = bTxNumServices;

	/* Exchange command ... */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_FIRST,
		bTxNumServices,
		aCmd,
		2U,
		&pRxBuffer,
		&wRespLength));

	/* ... and the service code (or area code) list. */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_LAST,
		bTxNumServices,
		pTxServiceList,
		(uint16)(((uint16)bTxNumServices) * 2U),
		&pRxBuffer,
		&wRespLength));

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_Read(
                P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint8, ANFCRL_VAR) bNumServices,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList,
                VAR(uint8, ANFCRL_VAR) bTxNumBlocks,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList,
                VAR(uint8, ANFCRL_VAR) bBlockListLength,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumBlocks,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData
							  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[2]={0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp == PH_STATUS_INPROCESS)
	{
		PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
			pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			0U,
			aCmd,
			0U,
			&pRxBuffer,
			&wRespLength));
		/* Check response. */
		/* Length: We expect:
		Status flags:       2 bytes
		Number of blocks:   1 byte
		Block data:         16 x number of blocks bytes */

		/* at least 2 status bytes have to be in the rx buffer */
		if (wRespLength < 2U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
		}

		/* on a felica error save the status flags */
		if (pRxBuffer[0] != 0U)
		{
			if (wRespLength != 2U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
			}
			pDataParams->wAdditionalInfo = ((uint16)pRxBuffer[0] << 8U) | (uint16)pRxBuffer[1];
			return PH_ADD_COMPCODE_FIXED(PHAL_FELICA_ERR_FELICA, PH_COMP_AL_FELICA);
		}

		if (wRespLength != (3u + (16u * ((uint16)(pRxBuffer[2])))))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
		}

		*pRxNumBlocks = pRxBuffer[2];
		(void)phTools_memcpy(pBlockData, &pRxBuffer[3], 16U * ((uint32)bTxNumBlocks));
		return PH_ERR_SUCCESS;
	}

	/* check correct number of services / blocks */
	if ((bNumServices < 1U) || (bTxNumBlocks < 1U))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
	}

	/* check block list length against numblocks */
	if ((bBlockListLength < (bTxNumBlocks * 2U))  || (bBlockListLength > (bTxNumBlocks * 3U)))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
	}

	/* Exchange command and the number of services ... */
	aCmd[0] = PHPAL_FELICA_SW_CMD_READ;
	aCmd[1] = bNumServices;
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_FIRST,
		bTxNumBlocks,
		aCmd,
		2U,
		&pRxBuffer,
		&wRespLength));

	/* ... the service code list ... */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_CONT,
		bTxNumBlocks,
		pServiceList,
		(uint16)(((uint16)bNumServices) * 2U),
		&pRxBuffer,
		&wRespLength));

	/* ... the number of blocks ... */
	aCmd[0] = bTxNumBlocks;
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_CONT,
		bTxNumBlocks,
		aCmd,
		1U,
		&pRxBuffer,
		&wRespLength));

	/* ... and the block list. */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_LAST,
		bTxNumBlocks,
		pBlockList,
		bBlockListLength,
		&pRxBuffer,
		&wRespLength));

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_Write(
                 P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                 VAR(uint8, ANFCRL_VAR) bNumServices,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList,
                 VAR(uint8, ANFCRL_VAR) bNumBlocks,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList,
                 VAR(uint8, ANFCRL_VAR) bBlockListLength,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData
							   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[2]={0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp == PH_STATUS_INPROCESS)
	{
		PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
			pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			0U,
			aCmd,
			0U,
			&pRxBuffer,
			&wRespLength));
		/* We should have received 2 status bytes */
		if (wRespLength != 2U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
		}

		/* save the status on an error */
		if (pRxBuffer[0] != 0U)
		{
			pDataParams->wAdditionalInfo = ((uint16)pRxBuffer[0] << 8U) | (uint16)pRxBuffer[1];
			return PH_ADD_COMPCODE_FIXED(PHAL_FELICA_ERR_FELICA, PH_COMP_AL_FELICA);
		}
		return PH_ERR_SUCCESS;
	}
	/* check correct number of services / blocks */
	if ((bNumServices < 1U) || (bNumBlocks < 1U))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
	}

	/* check block list length against numblocks */
	if ((bBlockListLength < (bNumBlocks * 2U))  || (bBlockListLength > (bNumBlocks * 3U)))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
	}

	/* Exchange command and the number of services ... */
	aCmd[0] = PHPAL_FELICA_SW_CMD_WRITE;
	aCmd[1] = bNumServices;
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_FIRST,
		bNumBlocks,
		aCmd,
		2U,
		&pRxBuffer,
		&wRespLength));

	/* ... the service code list ... */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_CONT,
		bNumBlocks,
		pServiceList,
		(uint16)(((uint16)bNumServices)<<1U),
		&pRxBuffer,
		&wRespLength));

	aCmd[0] = bNumBlocks;

	/* ... the number of blocks ... */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_CONT,
		bNumBlocks,
		aCmd,
		1U,
		&pRxBuffer,
		&wRespLength));

	/* ... the block list ... */
	PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
		pDataParams->pPalFelicaDataParams,
		PH_EXCHANGE_BUFFER_CONT,
		bNumBlocks,
		pBlockList,
		bBlockListLength,
		&pRxBuffer,
		&wRespLength));

    /* ... and the block data. */
    PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
        pDataParams->pPalFelicaDataParams,
        PH_EXCHANGE_BUFFER_LAST,
        bNumBlocks,
        pBlockData,
        (uint16)(((uint16)bNumBlocks) * 16U),
        &pRxBuffer,
        &wRespLength));

    /* We should have received 2 status bytes */
    if (wRespLength != 2U)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
    }

    /* save the status on an error */
    if (pRxBuffer[0] != 0U)
    {
        pDataParams->wAdditionalInfo = ((uint16)pRxBuffer[0] << 8U) | (uint16)pRxBuffer[1];
        return PH_ADD_COMPCODE_FIXED(PHAL_FELICA_ERR_FELICA, PH_COMP_AL_FELICA);
    }

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_GetConfig(
                  P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wConfig,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
									)
{
	switch (wConfig)
	{
	case PHAL_FELICA_CONFIG_ADD_INFO:
		*pValue = pDataParams->wAdditionalInfo;
		break;
	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_FELICA);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_ActivateCard(
                  P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,
                  VAR(uint8, ANFCRL_VAR) bNumTimeSlots,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pIDmPMm = NULL;

	*pRxLength = 0;
	*pMoreCardsAvailable = 0;

	/* RequestC == ReqC command (not requesting the system code) */
	/* In the case of a collision repeat the ReqC up to 16 slots. */

	PH_CHECK_SUCCESS_FCT(status, phpalFelica_ActivateCard(
			pDataParams->pPalFelicaDataParams,
			pIDmPMm,
			0x00U,
			pSystemCode,
			bNumTimeSlots,
			pRxBuffer,
			pRxLength,
			pMoreCardsAvailable
			));

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_SearchService(
                    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) serviceIndex,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCode,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCount
										)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[3]={0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTempRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp == PH_STATUS_INPROCESS)
	{
		PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
			pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			0U,
			aCmd,
			0U,
			&pTempRxBuffer,
			&wRespLength));

		if (wRespLength > 4U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
		}
		phTools_memcpy(pRxServiceCode, pTempRxBuffer, wRespLength);
		*pRxServiceCount = (uint8)(wRespLength/2U);
		return PH_ERR_SUCCESS;
	}
	aCmd[0] = PHPAL_FELICA_SW_CMD_SEARCH_SERVICE;
	aCmd[1] = (uint8)(serviceIndex & 0xffU);
	aCmd[2] = (uint8)((uint16)serviceIndex >> 8U);
	statusTmp = phpalFelica_Exchange(pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			1U,
			aCmd,
			3U,
			&pTempRxBuffer,
			&wRespLength);
	return statusTmp;
}


FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_RequestSystemCodes(
                    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCodes,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCount
										)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[3]={0};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTempRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp == PH_STATUS_INPROCESS)
	{
    VAR(uint16, ANFCRL_VAR) i;
		PH_CHECK_SUCCESS_FCT(statusTmp, phpalFelica_Exchange(
			pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			0U,
			aCmd,
			0U,
			&pTempRxBuffer,
			&wRespLength));

		if (wRespLength != (uint16)(((uint16)(pTempRxBuffer[0])*2U) + 1U))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_FELICA);
		}

		*pRxSystemCount = pTempRxBuffer[0];
		pTempRxBuffer++;
		for(i = 0; i < *pRxSystemCount; i++)
		{
			pRxSystemCodes[i] = (uint16)((((uint16)pTempRxBuffer[i * 2U]) << 8U) | pTempRxBuffer[1U + (i * 2U)]);
		}
		return PH_ERR_SUCCESS;
	}
	aCmd[0] = PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE;
	statusTmp = phpalFelica_Exchange(pDataParams->pPalFelicaDataParams,
			PH_EXCHANGE_DEFAULT,
			1,
			aCmd,
			1,
			&pTempRxBuffer,
			&wRespLength);
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_ReadBlocks(
                P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks,
                VAR(uint8, ANFCRL_VAR) blockCount, /* max 8 blocks*/
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 * blockCount bytes*/
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) serviceList[2] = {0}, blockList[16] = {0};
  VAR(uint8, ANFCRL_VAR) i, rxNumBlocks = 0U;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp != PH_STATUS_INPROCESS)
	{
		if (blockCount > 8U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
		}
		serviceList[0] = 0x0BU;
		serviceList[1] = 0x00U;
		for(i = 0U; i < blockCount; i++)
		{
			blockList[i * 2U] = 0x80U;
			blockList[(i * 2U) + 1U] = blocks[i];
		}
	}
	return phalFelica_Sw_Read(pDataParams, 1U, serviceList, blockCount, blockList, 2U * blockCount, &rxNumBlocks, pBlockData);
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_WriteBlocks(
                P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks,
                VAR(uint8, ANFCRL_VAR) blockCount, /* max 8 blocks*/
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 * blockCount bytes */
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) serviceList[2] = {0U}, blockList[16] = {0U};
  VAR(uint8, ANFCRL_VAR) i;

	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp != PH_STATUS_INPROCESS)
	{
		if (blockCount > 8U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
		}
		serviceList[0] = 0x09U;
		serviceList[1] = 0x00U;
		for(i = 0U; i < blockCount; i++)
		{
			blockList[i * 2U] = 0x80U;
			blockList[(i * 2U) + 1U] = blocks[i];
		}
	}
	return phalFelica_Sw_Write(pDataParams, 1U, serviceList, blockCount, blockList, 2U * blockCount, pBlockData);
}

#ifdef NXPBUILD__PH_CRYPTOSYM

static FUNC(FELICA_CARD_TYPE_t ,ANFCRL_CODE) phalFelica_GetCardType(VAR(uint8, ANFCRL_VAR) ic_code)
{
	switch(ic_code)
	{
	case 0xF1U: /* "FeliCa Lite-S (RC-S966)", */
	case 0xF2U: /* "FeliCa Link (RC-S730) Lite-S Mode", */
		return PHAL_FELICA_CARD_LITE_S;
	case 0x00U: /* ("RC-S830",    8,  8),  # RC-S831/833 */
	case 0x01U: /* ("RC-S915",   12,  8),  # RC-S860/862/863/864/891 */
	case 0x02U: /* ("RC-S919",    1,  1),  # RC-S890 */
	case 0x08U: /* ("RC-S952",   12,  8), */
	case 0x09U: /* ("RC-S953",   12,  8), */
	case 0x0BU: /* ("RC-S???",    1,  1),  # new suica */
	case 0x0CU: /* ("RC-S954",   12,  8), */
	case 0x0DU: /* ("RC-S960",   12, 10),  # RC-S880/889 */
	case 0x20U: /* ("RC-S962",   12, 10),  # RC-S885/888/892/893 */
	case 0x32U: /* ("RC-SA00/1",  1,  1),  # AES chip */
	case 0x35U: /* ("RC-SA00/2",  1,  1), */
		return PHAL_FELICA_CARD_STANDARD;
	case 0x06U: /* ("1.0",       1,  1), */
	case 0x07U: /* ("1.0",       1,  1), */
	case 0x10U: /* ("2.0",       1,  1), */
	case 0x11U: /* ("2.0",       1,  1), */
	case 0x12U: /* ("2.0",       1,  1), */
	case 0x13U: /* ("2.0",       1,  1), */
	case 0x14U: /* ("3.0",       1,  1), */
	case 0x15U: /* ("3.0",       1,  1), */
	case 0x16U: /* ("3.0",       1,  1), */
	case 0x17U: /* ("3.0",       1,  1), */
	case 0x18U: /* ("3.0",       1,  1), */
	case 0x19U: /* ("3.0",       1,  1), */
	case 0x1AU: /* ("3.0",       1,  1), */
	case 0x1BU: /* ("3.0",       1,  1), */
	case 0x1CU: /* ("3.0",       1,  1), */
	case 0x1DU: /* ("3.0",       1,  1), */
	case 0x1EU: /* ("3.0",       1,  1), */
	case 0x1FU: /* ("3.0",       1,  1), */
		return PHAL_FELICA_CARD_MOBILE;
	case 0xF0U: /* "FeliCa Lite (RC-S965)", */
		return PHAL_FELICA_CARD_LITE;
	case 0xE0U: /* "FeliCa Plug (RC-S926)", */
	case 0xE1U: /* "FeliCa Link (RC-S730) Plug Mode", */
		return PHAL_FELICA_CARD_PLUG;
	}
	return PHAL_FELICA_CARD_UNKNOWN;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_ReadBlocksWithMac(
                P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks,
                VAR(uint8, ANFCRL_VAR) blockCount, /* max 7 blocks */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 * blockCount bytes */
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) tblocks[8] = {0U}, data[128], mac[16];
	if (pDataParams->bAuthenticate == 0U)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_AUTH_ERROR, PH_COMP_AL_FELICA);
	}
	statusTmp = phhalHw_Exchange_GetStatus();
	if(statusTmp != PH_STATUS_INPROCESS)
	{
		if (blockCount > 7U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
		}
		phTools_memcpy(tblocks, blocks, blockCount);
		tblocks[blockCount] = 0x81U;
	}
	statusTmp = phalFelica_ReadBlocks(pDataParams, tblocks, blockCount+1U, data);
	if(statusTmp != PH_ERR_SUCCESS)
	{
		return statusTmp;
	}
	statusTmp = phalFelica_Generate_Mac(pDataParams, data, 16U * blockCount, pDataParams->sk, pDataParams->iv, 0U, mac);
	if(statusTmp != PH_ERR_SUCCESS)
	{
		return statusTmp;
	}
	if (memcmp(mac, &data[16U * blockCount], 8U) != 0)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_KEY, PH_COMP_AL_FELICA);
	}
	phTools_memcpy(pBlockData, data, 16U * (uint32)blockCount);
	return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phalFelica_WriteBlockWithMac(
                P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint8, ANFCRL_VAR) block,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 bytes */
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = 0U;
  VAR(uint8, ANFCRL_VAR) tblocks[2] = {0}, data[24], nsk[16];
  static  VAR(uint8, ANFCRL_VAR) bWriteState = 0U, maca[16];

	if (pDataParams->bAuthenticate == 0U)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_AUTH_ERROR, PH_COMP_AL_FELICA);
	}
	statusTmp = phhalHw_Exchange_GetStatus();
	switch(bWriteState)
	{
	case 0U:
		tblocks[0] = 0x90U;
		statusTmp = phalFelica_ReadBlocks(pDataParams, tblocks, 1U, data); /* Read WCNT */
		if(statusTmp != PH_ERR_SUCCESS)
		{
			return statusTmp;
		}
		bWriteState = 1U;
		data[3] = 0U;
		data[4] = block;
		data[5] = 0U;
		data[6] = 0x91U;
		data[7] = 0U;
		phTools_memcpy(&data[8], pBlockData, 16U);
		/* flip session key sk */
		phTools_memcpy(nsk, &pDataParams->sk[8], 8U);
		phTools_memcpy(&nsk[8], pDataParams->sk, 8U);
		statusTmp = phalFelica_Generate_Mac(pDataParams, data, 24U, nsk, pDataParams->iv, 0U, maca);
		if(statusTmp != PH_ERR_SUCCESS)
		{
			return statusTmp;
		}
		/* copy WCNT */
		maca[8] = data[0];
		maca[9] = data[1];
		maca[10] = data[2];
		(void)memset(&maca[11], 0, 5U);
		return PH_STATUS_INPROCESS;
	case 1U:
		if(statusTmp != PH_STATUS_INPROCESS)
		{
			tblocks[0] = 0x91U;
			phTools_memcpy(data, pBlockData, 16U);
			phTools_memcpy(&data[16], maca, 8U);
		}
		statusTmp = phalFelica_WriteBlocks(pDataParams, tblocks, 1U, data); /* Write pBlockData with MACA */
		if(statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		bWriteState = 0U;
		break;
	}
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Generate_Mac(
    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) data,
    VAR(uint8, ANFCRL_VAR) datalen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) key,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) iv,
    VAR(uint8, ANFCRL_VAR) flip_key,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) mac)
{
/*    Data is first split into tuples of 8 character bytes, each */
/*    tuple then reversed and joined, finally all joined back to */
/*    one string that is then triple des encrypted with key and */
/*    initialization vector iv. If flip_key is True then the key */
/*    halfs will be exchanged (this is used to generate a mac for */
/*    write). The resulting mac is the last 8 bytes returned in */
/*    reversed order. */
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) nkey[16], ndata[24], tmac[24] = {0U}, i;

	if (((datalen % 8U) != 0U) || (datalen > 24U))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
	}
	if (flip_key != 0U)
	{
		phTools_memcpy(nkey, &key[8], 8U);
		phTools_memcpy(&nkey[8], key, 8U);
	}
	else
	{
		phTools_memcpy(nkey, key, 16U);
	}
	for(i = 0U; i < 8U; i++)
	{
		ndata[i] = data[7U-i];
		ndata[i+8U] = data[15U-i];
	}
	if (datalen == 24U)
	{
		for(i = 0U; i < 8U; i++)
		{
			ndata[i+16U] = data[23U-i];
		}
	}
	/* triple_des(nkey, CBC, bytes(iv)).encrypt(ndata)[:-9:-1] */
	PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(pDataParams->pCryptoSymDataParams, nkey, PH_CRYPTOSYM_KEY_TYPE_2K3DES));
	PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(pDataParams->pCryptoSymDataParams, iv, 8U));
	PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(pDataParams->pCryptoSymDataParams, PH_CRYPTOSYM_CIPHER_MODE_CBC, ndata, datalen, tmac));
	for(i = 0U; i < 8U; i++)
	{
		mac[i] = tmac[datalen-i-1U];
	}
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Protect(
            P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPassword,
            VAR(uint8, ANFCRL_VAR) bPassLength,
            VAR(uint8, ANFCRL_VAR) bProtectOptions,
            VAR(uint8, ANFCRL_VAR) bFromBlock
						)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM i;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wData, wProtectMask;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM mc[16], key[16], attribute_data[16], ckv[16], blocks[2];
  static VAR(FELICA_PROTECT_StateType_t, ANFCRL_VAR) cmdState = PHAL_FELICA_PROTECT_IDLE;
  static VAR(FELICA_CARD_TYPE_t, ANFCRL_VAR) cardType = PHAL_FELICA_CARD_STANDARD;
  P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelica;

	switch(cmdState)
	{
	case PHAL_FELICA_PROTECT_IDLE:
	case PHAL_FELICA_PROTECT_READ_MAC:
		if ((pPassword != NULL) && (bPassLength < 16U))
		{
			/* password must be at least 16 byte */
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
		}
		if (PHAL_FELICA_PROTECT_IDLE == cmdState)
		{
			pPalFelica = pDataParams->pPalFelicaDataParams;
			if (pPalFelica->bIDmPMmValid == 0U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
			}
			cmdState = PHAL_FELICA_PROTECT_READ_MAC;
			cardType = phalFelica_GetCardType(pPalFelica->aIDmPMm[9]);
			if ((cardType != PHAL_FELICA_CARD_LITE_S) && (cardType != PHAL_FELICA_CARD_LITE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
			}
		}
		/* The memory configuration block contains access permissions and NDEF compatibility information. */
		blocks[0] = 0x88U;
		statusTmp = phalFelica_ReadBlocks(pDataParams, blocks, 1U, mc);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		if (pPassword != NULL)
		{
			if (mc[2] != 0xFFU) /* system block protected, can't write key */
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
			}
			if (cardType == PHAL_FELICA_CARD_LITE_S)
			{
				if ((mc[5] & 1U) == 0U)
				{
					/* card key can not be changed */
					cmdState = PHAL_FELICA_PROTECT_IDLE;
					return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
				}
				if (pDataParams->bAuthenticate == 0U)
				{
					/* authentication required to change key */
					cmdState = PHAL_FELICA_PROTECT_IDLE;
					return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
				}
			}
		}
		if (((bProtectOptions & 4U) != 0U) && (pPassword == NULL))
		{
			cmdState = PHAL_FELICA_PROTECT_PREPARE_WRITE_MEM_CONFIG;
		}
		else
		{
			if (pPassword != NULL)
			{
				for(i = 0U; i < 8U; i++)
				{
					key[i] = pPassword[7U-i];
					key[i+8U] = pPassword[15U-i];
				}
			}
			else
			{
				(void)memset(key, 0, 16U);
			}
			if (cardType == PHAL_FELICA_CARD_LITE_S)
			{
				cmdState = PHAL_FELICA_PROTECT_READ_CARDKEY_VERSION;
			}
			else
			{
				cmdState = PHAL_FELICA_PROTECT_WRITE_CARDKEY;
			}
		}
		break;
	case PHAL_FELICA_PROTECT_READ_CARDKEY_VERSION:
		blocks[0] = 0x86U;
		statusTmp = phalFelica_ReadBlocks(pDataParams, blocks, 1U, ckv);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		ckv[0] += 1U;
		cmdState = PHAL_FELICA_PROTECT_WRITE_CARDKEY_VERSION;
		break;
	case PHAL_FELICA_PROTECT_WRITE_CARDKEY_VERSION:
		blocks[0] = 0x86U;
		statusTmp = phalFelica_WriteBlocks(pDataParams, blocks, 1U, ckv);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		cmdState = PHAL_FELICA_PROTECT_WRITE_CARDKEY;
		break;
	case PHAL_FELICA_PROTECT_WRITE_CARDKEY:
		blocks[0] = 0x87U;
		statusTmp = phalFelica_WriteBlocks(pDataParams, blocks, 1U, key);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		cmdState = PHAL_FELICA_PROTECT_AUTHENTICATE_CHECK;
		break;
	case PHAL_FELICA_PROTECT_AUTHENTICATE_CHECK:
		statusTmp = phalFelica_Authenticate(pDataParams, pPassword, bPassLength);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		if (bFromBlock == 0U) /* and self.ndef is not None: */
		{
			cmdState = PHAL_FELICA_PROTECT_READ_ATTRIB;
		}
		else
		{
			cmdState = PHAL_FELICA_PROTECT_PREPARE_WRITE_MEM_CONFIG;
		}
		break;
	case PHAL_FELICA_PROTECT_READ_ATTRIB:
		blocks[0] = 0x00U;
		statusTmp = phalFelica_ReadBlocks(pDataParams, blocks, 1U, attribute_data);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		attribute_data[10] = 0x00U;
		wData = 0U;
		for(i = 0U; i < 14U; i++)
		{
			wData += attribute_data[i];
		}
		attribute_data[14] = (uint8)(wData >> 8U);
		attribute_data[15] = (uint8)(wData);
		cmdState = PHAL_FELICA_PROTECT_WRITE_ATTRIB;
		break;
	case PHAL_FELICA_PROTECT_WRITE_ATTRIB:
		blocks[0] = 0x00U;
		statusTmp = phalFelica_WriteBlocks(pDataParams, blocks, 1U, attribute_data);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		if (statusTmp != PH_ERR_SUCCESS)
		{
			cmdState = PHAL_FELICA_PROTECT_IDLE;
			return statusTmp;
		}
		cmdState = PHAL_FELICA_PROTECT_PREPARE_WRITE_MEM_CONFIG;
		break;
	case PHAL_FELICA_PROTECT_PREPARE_WRITE_MEM_CONFIG:
		if (bFromBlock < 14U)
		{
			/*log.debug("write protect blocks {0}--13".protect_from) */
			wProtectMask = 0x7FFFU ^ (((uint16)1U << 14U) - ((uint16)1U << bFromBlock));
			if (cardType == PHAL_FELICA_CARD_LITE_S)
			{
				if(pPassword != NULL)
				{
					if ((bProtectOptions & 1U) != 0U) /* Read After Authenticate Protect */
					{
						/* Set Read After Authenticate (MC_SP_REG_R_RESTR) */
						mc[6] = (uint8)(wProtectMask >> 8U);
						mc[7] = (uint8)(wProtectMask);
					}
					/* Set Write After Authenticate (MC_SP_REG_W_RESTR) */
					mc[8] = (uint8)(wProtectMask >> 8U);
					mc[9] = (uint8)(wProtectMask);
					if ((bProtectOptions & 8U) != 0U)
					{
						/* Set Write With MAC (MC_SP_REG_W_MAC_A) */
						mc[10] = (uint8)(wProtectMask >> 8U);
						mc[11] = (uint8)(wProtectMask);
					}
				}
			}
			if ((bProtectOptions & 4U) != 0U)
			{
				/* Set Read only (RO) permission (MC_SP_REG_ALL_RW) */
				mc[0] = (uint8)(wProtectMask >> 8U);
				mc[1] = (uint8)(wProtectMask);
			}
		}
		if ((bProtectOptions & 2U) != 0U) /* protect system blocks to read only */
		{
			/* write protect system blocks 82,83,84,86,87, to read only */
			mc[2] = 0x00U;
			/* but allow write with mac to ck and ckv block */
			if (cardType == PHAL_FELICA_CARD_LITE_S)
			{
				mc[5] = 0x01U;
			}
		}
		cmdState = PHAL_FELICA_PROTECT_WRITE_MEM_CONFIG;
		break;
	case PHAL_FELICA_PROTECT_WRITE_MEM_CONFIG:
		blocks[0] = 0x88U;
		statusTmp = phalFelica_WriteBlocks(pDataParams, blocks, 1U, mc);
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			return statusTmp;
		}
		cmdState = PHAL_FELICA_PROTECT_IDLE;
		return statusTmp;
	}
	return PH_STATUS_INPROCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Authenticate(
                P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPassword, /* length >= 16 */
                VAR(uint8, ANFCRL_VAR) bPassLength
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  static VAR(FELICA_AUTHENTICATE_StateType_t, ANFCRL_VAR) cmdState = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM rc[16], rcw[16], key[16], sk[16], data[32], blocks[2];
  static VAR(FELICA_CARD_TYPE_t, ANFCRL_VAR) cardType = PHAL_FELICA_CARD_STANDARD;
  VAR(uint8, ANFCRL_VAR) iv[8], i;
  VAR(uint32, ANFCRL_VAR) iVal;
  P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelica;

	switch(cmdState)
	{
	case PHAL_FELICA_AUTHENTICATE_IDLE:
	case PHAL_FELICA_AUTHENTICATE_WRITE_RC_BLOCK:
		if (cmdState == PHAL_FELICA_AUTHENTICATE_IDLE)
		{
			if ((pPassword != NULL) && (bPassLength < 16U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_FELICA);
			}
			pDataParams->bAuthenticate = 0U;
			pPalFelica = pDataParams->pPalFelicaDataParams;
			if (pPalFelica->bIDmPMmValid == 0U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
			}
			cardType = phalFelica_GetCardType(pPalFelica->aIDmPMm[9]);
			if ((cardType != PHAL_FELICA_CARD_LITE_S) && (cardType != PHAL_FELICA_CARD_LITE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_FELICA);
			}
			if (pPassword != NULL)
			{
				phTools_memcpy(key, pPassword, 16U);
			}
			else
			{
				(void)memset(key, 0, 16U);
			}

			phTools_srand(phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS));
			for(i = 0U; i < 8U; i++)
			{
				iVal = phTools_rand();
				rc[i * 2U] = (uint8)iVal;
				rc[(i * 2U) + 1U] = (uint8)(iVal >>  8U);
			}
			for(i = 0U; i < 8U; i++)
			{
				rcw[i] = rc[7U-i];
				rcw[i+8U] = rc[15U-i];
			}
			cmdState = PHAL_FELICA_AUTHENTICATE_WRITE_RC_BLOCK;
		}
		blocks[0] = 0x80U;
		PH_CHECK_INPROCESS_FCT(statusTmp, phalFelica_WriteBlocks(pDataParams, blocks, 1U, rcw));
		PH_BREAK_ON_FAILURE(statusTmp);

		cmdState = PHAL_FELICA_AUTHENTICATE_CREATE_SESSION_KEY;
		return PH_STATUS_INPROCESS;

	case PHAL_FELICA_AUTHENTICATE_CREATE_SESSION_KEY:
		(void)memset(iv, 0, 8U);
		PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_LoadKeyDirect(pDataParams->pCryptoSymDataParams, key, PH_CRYPTOSYM_KEY_TYPE_2K3DES));
		PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_LoadIv(pDataParams->pCryptoSymDataParams, iv, 8));
		PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_Encrypt(pDataParams->pCryptoSymDataParams, PH_CRYPTOSYM_CIPHER_MODE_CBC, rc, 16U, sk));

		cmdState = PHAL_FELICA_AUTHENTICATE_READ_MAC_ID_BLOCK;
		return PH_STATUS_INPROCESS;

	case PHAL_FELICA_AUTHENTICATE_READ_MAC_ID_BLOCK:
		blocks[0] = 0x82U;
		blocks[1] = 0x81U;
		PH_CHECK_INPROCESS_FCT(statusTmp, phalFelica_ReadBlocks(pDataParams, blocks, 2U, data));
		PH_BREAK_ON_FAILURE(statusTmp);

		PH_CHECK_FAILURE_FCT(statusTmp, phalFelica_Generate_Mac(pDataParams, data, 16U, sk, rc, 0U, rcw));
		if (memcmp(&data[16], rcw, 8U) == 0)
		{
			pDataParams->bAuthenticate = 1U;
			phTools_memcpy(pDataParams->sk, sk, 16U);
			phTools_memcpy(pDataParams->iv, rc, 8U);
		}
		else
		{
			statusTmp = PH_ERR_AUTH_ERROR;
			break;
		}
		if (cardType == PHAL_FELICA_CARD_LITE_S)
		{
			cmdState = PHAL_FELICA_AUTHENTICATE_WRITE_STATE;
			(void)memset(data, 0, 16U);
			data[0] = 1U;
		}
		else
		{
			cmdState = PHAL_FELICA_AUTHENTICATE_IDLE;
		}
		return PH_STATUS_INPROCESS;

	case PHAL_FELICA_AUTHENTICATE_WRITE_STATE:
		PH_CHECK_INPROCESS_FCT(statusTmp, phalFelica_WriteBlockWithMac(pDataParams, 0x92U, data));
		PH_BREAK_ON_FAILURE(statusTmp);

		cmdState = PHAL_FELICA_AUTHENTICATE_READ_STATE;
		return PH_STATUS_INPROCESS;

	case PHAL_FELICA_AUTHENTICATE_READ_STATE:
		blocks[0] = 0x92U;
		PH_CHECK_INPROCESS_FCT(statusTmp, phalFelica_ReadBlocksWithMac(pDataParams, blocks, 1U, data));
		PH_BREAK_ON_FAILURE(statusTmp);

		if (data[0] == 0x01U)
		{
			/* mutual authentication completed */
			pDataParams->bAuthenticate = 1U;
			statusTmp = PH_ERR_SUCCESS;
		}
		else
		{
			pDataParams->bAuthenticate = 0U;
			statusTmp = PH_ERR_AUTH_ERROR;
		}
		break;
	}

	cmdState = PHAL_FELICA_AUTHENTICATE_IDLE;
	return statusTmp;
}
#endif


#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_FELICA_SW */
#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */
