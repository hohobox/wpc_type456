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
*   @file    phceT4T_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR CeT4T_Sw - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phceT4T NFC Forum Type 4A Card Emulation
*   @ingroup phce
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
#include <phpalI14443p4mC.h>

#ifdef NXPBUILD__PHCE_T4T_SW
#include "phceT4T_Sw.h"
#include "phceT4T_Sw_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phceT4T_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCET4T_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCET4T_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHCET4T_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHCET4T_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHCET4T_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHCET4T_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHCET4T_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phceT4T_Sw.h header file are of the same vendor */
#if (PHCET4T_SW_VENDOR_ID_C != PHCET4T_SW_VENDOR_ID)
    #error "phceT4T_Sw.c and phceT4T_Sw.h have different vendor ids"
#endif
/* Check if current file and PHCET4T_Sw.h header file are of the same Autosar version */
#if ((PHCET4T_SW_AR_RELEASE_MAJOR_VERSION_C    != PHCET4T_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHCET4T_SW_AR_RELEASE_MINOR_VERSION_C    != PHCET4T_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHCET4T_SW_AR_RELEASE_REVISION_VERSION_C != PHCET4T_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phceT4T_Sw.c and phceT4T_Sw.h are different"
#endif
/* Check if current file and PHCET4T_Sw.h header file are of the same Software version */
#if ((PHCET4T_SW_SW_MAJOR_VERSION_C != PHCET4T_SW_MAJOR_VERSION) || \
     (PHCET4T_SW_SW_MINOR_VERSION_C != PHCET4T_SW_MINOR_VERSION) || \
     (PHCET4T_SW_SW_PATCH_VERSION_C != PHCET4T_SW_PATCH_VERSION))
    #error "Software Version Numbers of phceT4T_Sw.c and phceT4T_Sw.h are different"
#endif
#endif /* NXPBUILD__PHCE_T4T_SW */
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
#ifdef NXPBUILD__PHCE_T4T_SW
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHCET4T_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(phceT4T_ActiveParams_t, ANFCRL_VAR) gceT4TActParams = {
		PHCET4T_INT_ACTIVE_IDLE,
		PH_RECEIVE_DEFAULT
};

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHCET4T_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_SW_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHCET4T_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Init(
              P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalI14443p4mCDataParams,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAppBuffer,
              VAR(uint16, ANFCRL_VAR) wAppBufferSize
							)
{
  VAR(phStatus_t, ANFCRL_VAR) status;

	/* Parameter check */
	if(sizeof(phceT4T_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_CE_T4T);
	}
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pPalI14443p4mCDataParams);

	/* Initialize data parameters */
	pDataParams->wId = PH_COMP_CE_T4T | PHCE_T4T_SW_ID;

	pDataParams->pPalI14443p4mCDataParams = pPalI14443p4mCDataParams;
	pDataParams->pAppBuffer               = pAppBuffer;
	pDataParams->wAppBufferSize           = wAppBufferSize;

#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
	pDataParams->bProprietaryFileCount    = 0u;
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */

	pDataParams->bHandleUpdateCmd         = PH_OFF;
	pDataParams->bSupportProprietaryCmd   = PH_OFF;

	/* Reset tag state */
	pDataParams->bTagState                = PHCE_T4T_STATE_NONE;

	/*Initial for Active function of phceT4T */
	gceT4TActParams.bActiveState = PHCET4T_INT_ACTIVE_IDLE;
	pDataParams->pceT4TActParams          = &gceT4TActParams;

	/* Reset data parameters with default values */
	PH_CHECK_SUCCESS_FCT(status, phceT4T_Sw_Reset(pDataParams));

	return phTools_EventCreate(&pDataParams->T4TEventObj, &phceT4T_Sw_Int_EventPoll, pDataParams);
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Reset(
              P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
							)
{
	/* If reset is called before NDEF file is set, do not reset tag state. */
	if(pDataParams->bTagState > PHCE_T4T_STATE_NDEF_FILE_CREATED)
	{
		pDataParams->bTagState = PHCE_T4T_STATE_NDEF_FILE_CREATED;
	}

	pDataParams->bRxOption              = 0u;
	pDataParams->pSelectedFile          = NULL;
	pDataParams->wSelectedFileId        = 0u;
	pDataParams->bFileWriteAccess       = 0u;
	pDataParams->dwFileOffset           = 0u;
	pDataParams->dwFileSize             = 0u;
	pDataParams->pSharedData            = NULL;
	pDataParams->wSharedDataLen         = 0u;
	pDataParams->wLc                    = 0u;
	pDataParams->wStatusWord            = 0u;
	pDataParams->wExitStatus            = 0u;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_SetElementaryFile(
                    P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bFileType,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFile,
                    VAR(uint16, ANFCRL_VAR) wFileId,
                    VAR(uint32, ANFCRL_VAR) dwFileSize,
                    VAR(uint32, ANFCRL_VAR) dwContentLen
										)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* Validate maximum size */
	if(((bFileType == PHCE_T4T_FILE_CC) || (bFileType == PHCE_T4T_FILE_PROPRIETARY))
	   && (dwFileSize > 0xFFFEU))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* NULL check */
	if(pFile == NULL)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Check file type and call corresponding internal function */
	if(bFileType == PHCE_T4T_FILE_CC)
	{
		PH_CHECK_SUCCESS_FCT(status, phceT4T_Sw_Int_SetCcFile(
			pDataParams,
			pFile,
			wFileId,
			(uint16)dwFileSize,
			(uint16)dwContentLen));
	}
	else if(bFileType == PHCE_T4T_FILE_NDEF)
	{
		PH_CHECK_SUCCESS_FCT(status, phceT4T_Sw_Int_SetNdefFile(
			pDataParams,
			pFile,
			wFileId,
			dwFileSize,
			dwContentLen));
	}

#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
	else if(bFileType == PHCE_T4T_FILE_PROPRIETARY)
	{
		PH_CHECK_SUCCESS_FCT(status, phceT4T_Sw_Int_SetProprietaryFile(
			pDataParams,
			pFile,
			wFileId,
			(uint16)dwFileSize,
			(uint16)dwContentLen));
	}
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */

	else
	{
		/* Unsupported elementary file type */
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_ProcessCmd(
                P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint16, ANFCRL_VAR) wOption,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                VAR(uint16, ANFCRL_VAR) wRxDataLen,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord,
                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTxData,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* Assign the default out Parameters */
	*ppTxData = NULL;
	*pTxDataLen = 0u;
	*pStatusWord = PHCE_T4T_ISO7816_NO_PRECISE_DIAGNOSIS;
	pDataParams->wStatusWord = *pStatusWord;

	/* Check State */
	if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_INCOMPATIBLE_FILE_STRUCT;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	/* Validate input data buffer */
	if(pRxData == NULL)
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
		*pStatusWord = pDataParams->wStatusWord;
		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	switch(wOption)
	{
	case PHCE_T4T_RXDEFAULT:
	case PHCE_T4T_RXCHAINING_BUFFER_FIRST:
	{
		/* Validate input data length */
		if((wRxDataLen < 4U))
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
			*pStatusWord = pDataParams->wStatusWord;
			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}

		/* Check for the Class Byte */
		if(pRxData[0] != 0x00U)
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_CLASS;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}

		/* Check for Instruction Byte */
		switch(pRxData[1])
		{
		case PHCE_T4T_INS_SELECT:
			/* Select file based on file ID */
			status = phceT4T_Sw_Int_Select(
				pDataParams,
				pRxData,
				wRxDataLen,
				pStatusWord);
			break;

		case PHCE_T4T_INS_READ:
			/* Read from file */
			status = phceT4T_Sw_Int_ReadBinary(
				pDataParams,
				pRxData,
				wRxDataLen,
				pStatusWord,
				ppTxData,
				pTxDataLen);
			break;

		case PHCE_T4T_INS_UPDATE:
			/* Update file */
			status = phceT4T_Sw_Int_UpdateBinary(
				pDataParams,
				wOption,
				pRxData,
				wRxDataLen,
				pStatusWord,
				ppTxData,
				pTxDataLen);
			break;

		default:
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_INSTRUCTION;
			*pStatusWord = pDataParams->wStatusWord;
			*ppTxData = pRxData;
			*pTxDataLen = wRxDataLen;

			status = (PH_CE_T4T_PROPRIETARY | PH_COMP_CE_T4T);
			break;
		}
	}
	break;

	case PHCE_T4T_RXCHAINING_BUFFER_CONT:
		if(pDataParams->bTagState == PHCE_T4T_STATE_FILE_UPDATE)
		{
			/* Check for the length error */
			if(!((wRxDataLen) <= pDataParams->wLc))
			{
				/* Change error code to length error */
				pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
				*pStatusWord = pDataParams->wStatusWord;
				return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
			}

			/* Update received data count */
			pDataParams->wLc = pDataParams->wLc - wRxDataLen;

			/* Update file if configured to */
			if(pDataParams->bHandleUpdateCmd == PH_ON)
			{
				phceT4T_Sw_Int_UpdateFile(
					pDataParams,
					pRxData,
					wRxDataLen);
			}
			else
			{
				*ppTxData = pRxData;
				*pTxDataLen = wRxDataLen;
			}

			/* Change Status to Success */
			pDataParams->bTagState = PHCE_T4T_STATE_FILE_UPDATE;
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
			*pStatusWord = pDataParams->wStatusWord;

			status = (PH_CE_T4T_UPDATE_BINARY | PH_COMP_CE_T4T);
		}
		else
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_INSTRUCTION;
			*pStatusWord = pDataParams->wStatusWord;
			*ppTxData = pRxData;
			*pTxDataLen = wRxDataLen;

			status = (PH_CE_T4T_PROPRIETARY | PH_COMP_CE_T4T);
		}
		break;

	case PHCE_T4T_RXCHAINING_BUFFER_LAST:
		if(pDataParams->bTagState == PHCE_T4T_STATE_FILE_UPDATE)
		{
			/* Check for the length error */
			if((wRxDataLen) != pDataParams->wLc)
			{
				/* Change error code to length error */
				pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
				*pStatusWord = pDataParams->wStatusWord;
				return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
			}

			pDataParams->wLc = pDataParams->wLc - wRxDataLen;

			/* Update file if configured to */
			if(pDataParams->bHandleUpdateCmd == PH_ON)
			{
				phceT4T_Sw_Int_UpdateFile(
					pDataParams,
					pRxData,
					wRxDataLen);
			}
			else
			{
				*ppTxData = pRxData;
				*pTxDataLen = wRxDataLen;
			}

			/* Change Status to Success */
			pDataParams->bTagState = PHCE_T4T_STATE_FILE_UPDATE;
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
			*pStatusWord = pDataParams->wStatusWord;

			status = (PH_CE_T4T_UPDATE_BINARY | PH_COMP_CE_T4T);
		}
		else
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_INSTRUCTION;
			*pStatusWord = pDataParams->wStatusWord;
			*ppTxData = pRxData;
			*pTxDataLen = wRxDataLen;

			status = (PH_CE_T4T_PROPRIETARY | PH_COMP_CE_T4T);
		}
		break;

	default:
		status = (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		break;
	}

	return (status);
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Activate(
                 P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
							   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	/* Call the actual activate implementation */
	PH_CHECK_INPROCESS_FCT(status, phceT4T_Sw_Int_Activate(pDataParams));

	/* Update exit status */
	pDataParams->wExitStatus = status;

	/* Set RX Data available event with error details */
	(void)phTools_EventPost(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_ERROR, NULL);

	/* Return error */
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_AppProcessCmd(
                  P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(phceT4T_AppCallback_t, ANFCRL_VAR) pAppCallback
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phTools_EventBits_t, ANFCRL_VAR) PH_MEMLOC_REM events = 0u;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_BUF pTxData;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxDataLen = 0u;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wStatusWord;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDataOffset = 0u;
	bool              PH_MEMLOC_REM bExitLoop = FALSE;

	/* Loop till aborted, DESELECTED or error */
	do
	{
		/* Wait for RX Data */
		PH_CHECK_SUCCESS_FCT(status, phTools_EventPend(&pDataParams->T4TEventObj, E_EVENT_OPT_PEND_SET_ANY, 0xFFFFFFFFU,
			(E_EVT_RXDATA_AVAILABLE | E_EVENT_ABORT | E_EVT_ERROR), &events));

		if((events & E_EVT_ERROR) == E_EVT_ERROR)
		{
			/* Clear event */
			PH_CHECK_SUCCESS_FCT(status,
					phTools_EventClear(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_ERROR, NULL));

			/* Exit on error */
			status = pDataParams->wExitStatus;

			/* Exit loop */
			break;
		}
		else if((events & E_EVT_RXDATA_AVAILABLE) == E_EVT_RXDATA_AVAILABLE)
		{
			/* Clear event */
			PH_CHECK_SUCCESS_FCT(status,
				phTools_EventClear(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_RXDATA_AVAILABLE, NULL));

			/* For UPDATE BINARY send only the data to be updated, not whole C-APDU */
			if(pDataParams->bTagState == PHCE_T4T_STATE_FILE_UPDATE)
			{
				/* Update the data offset */
				if((pDataParams->bRxOption == PHCE_T4T_RXCHAINING_BUFFER_CONT)
						|| (pDataParams->bRxOption == PHCE_T4T_RXCHAINING_BUFFER_LAST))
				{
					bDataOffset = 0u;
				}
				else
				{
					if(pDataParams->wLc > 0xFFU)
					{
						bDataOffset = 7u;
					}
					else
					{
						bDataOffset = 5u;
					}
				}
			}
			else
			{
				bDataOffset = 0u;
			}

			/* If application callback is not provided, handle internally. */
			if(pAppCallback == NULL)
			{
				/* Update file with RX Data */
				if(pDataParams->bTagState == PHCE_T4T_STATE_FILE_UPDATE)
				{
					phceT4T_Sw_Int_UpdateFile(
						pDataParams,
						&pDataParams->pSharedData[bDataOffset],
						((uint32)pDataParams->wSharedDataLen - (uint32)bDataOffset));

					/* For UPDATE BINARY, there is no TX data. */
					pDataParams->pSharedData = NULL;
					pDataParams->wSharedDataLen = 0u;

					/* Update status word */
					pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
				}
				else
				{
					/* For proprietary command send only Status Word */
					pDataParams->pSharedData = NULL;
					pDataParams->wSharedDataLen = 0u;

					/* Update status word */
					pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_INSTRUCTION;
				}
			}
			else
			{
				/* Call application callback */
				status = pAppCallback(
					pDataParams->bTagState,
					pDataParams->bRxOption,
					&pDataParams->pSharedData[bDataOffset],
					(pDataParams->wSharedDataLen - bDataOffset),
					&wStatusWord,
					&pTxData,
					&wTxDataLen);

				if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
				{
					/* Update file offset (for proprietary, callback shall handle) */
					if(pDataParams->bTagState == PHCE_T4T_STATE_FILE_UPDATE)
					{
						pDataParams->dwFileOffset += ((uint32)pDataParams->wSharedDataLen - (uint32)bDataOffset);
					}

					/* Update TX Data */
					pDataParams->pSharedData = pTxData;
					pDataParams->wSharedDataLen = wTxDataLen;

					/* Update status word */
					pDataParams->wStatusWord = wStatusWord;
				}
				else
				{
					/* Update TX Data */
					pDataParams->pSharedData = NULL;
					pDataParams->wSharedDataLen = 0u;

					/* Update status word */
					pDataParams->wStatusWord = wStatusWord;
				}
			}

			/* Set TX Data available event */
			PH_CHECK_SUCCESS_FCT(status,
				phTools_EventPost(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_TXDATA_AVAILABLE, NULL));
		}
		else
		{
			/* Aborted */
			status = (PH_ERR_ABORTED | PH_COMP_CE_T4T);

			/* Exit loop */
			bExitLoop = TRUE;
		}
	}
	while(bExitLoop == FALSE);

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_GetSelectedFileInfo(
                    P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pFileId,
                    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFile,
                    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pWriteAccess,
                    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pFileOffset
										)
{
	if(pDataParams->bTagState >= PHCE_T4T_STATE_FILE_SELECTED)
	{
		*pFileId      = pDataParams->wSelectedFileId;
		*ppFile       = pDataParams->pSelectedFile;
		*pFileSize    = pDataParams->dwFileSize;
		*pWriteAccess = pDataParams->bFileWriteAccess;
		*pFileOffset  = pDataParams->dwFileOffset;
	}
	else
	{
		return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_SetConfig(
                P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint16, ANFCRL_VAR) wConfig,
                VAR(uint16, ANFCRL_VAR) wValue
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	switch(wConfig)
	{
	case PHCE_T4T_CONFIG_HANDLE_UPDATEBINARY:
		if((wValue != PH_ON) && (wValue != PH_OFF))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		pDataParams->bHandleUpdateCmd = (uint8)wValue;
		break;

	case PHCE_T4T_CONFIG_RECEIVE_PROPRIETARY:
		if((wValue != PH_ON) && (wValue != PH_OFF))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		pDataParams->bSupportProprietaryCmd = (uint8)wValue;
		break;

	case PHCE_T4T_CONFIG_NDEF_FILE_ID:
		if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
		{
		   return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		/* Validate file ID */
		if((wValue == 0x0000U) || (wValue == 0xE102U) || (wValue == 0xE103U)
		   || (wValue == 0x3F00U) || (wValue == 0x3FFFU) || (wValue == 0xFFFFU))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		pDataParams->pCcFile[9]  = (uint8)((wValue & 0xFF00U) >> 8U);
		pDataParams->pCcFile[10] = (uint8)(wValue & 0xFFU);
		break;

	case PHCE_T4T_CONFIG_NDEF_FILE_READ_ACCESS:
		if(wValue != 0x00U)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		if(pDataParams->pCcFile[2] == 0x20U)
		{
			pDataParams->pCcFile[13] = (uint8)wValue;
		}
#ifdef NXPBUILD__PHCE_T4T_EXT_NDEF
		else
		{
			pDataParams->pCcFile[15] = (uint8)wValue;
		}
#endif /* NXPBUILD__PHCE_T4T_EXT_NDEF */
		break;

	case PHCE_T4T_CONFIG_NDEF_FILE_WRITE_ACCESS:
		if((wValue != 0x00U) && (wValue != 0xFFU))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		if(pDataParams->pCcFile[2] == 0x20U)
		{
			 pDataParams->pCcFile[14] = (uint8)wValue;
		}
#ifdef NXPBUILD__PHCE_T4T_EXT_NDEF
		else
		{
			pDataParams->pCcFile[16] = (uint8)wValue;
		}
#endif /* NXPBUILD__PHCE_T4T_EXT_NDEF */
		break;

	case PHCE_T4T_CONFIG_MLE:
		if(wValue < 0x000FU)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		if(pDataParams->bTagState < PHCE_T4T_STATE_CC_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		pDataParams->pCcFile[3] = (uint8)((wValue & 0xFF00U) >> 8U);
		pDataParams->pCcFile[4] = (uint8)(wValue & 0xFFU);
		break;

	case PHCE_T4T_CONFIG_MLC:
		if(wValue == 0x00U)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
		if(pDataParams->bTagState < PHCE_T4T_STATE_CC_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		pDataParams->pCcFile[5] = (uint8)((wValue & 0xFF00U) >> 8U);
		pDataParams->pCcFile[6] = (uint8)(wValue & 0xFFU);
		break;

	default:
		status = (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_GetConfig(
                P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint16, ANFCRL_VAR) wConfig,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	switch(wConfig)
	{
	case PHCE_T4T_CONFIG_HANDLE_UPDATEBINARY:
		*pValue = pDataParams->bHandleUpdateCmd;
		break;

	case PHCE_T4T_CONFIG_RECEIVE_PROPRIETARY:
		*pValue = pDataParams->bSupportProprietaryCmd;
		break;

	case PHCE_T4T_CONFIG_NDEF_FILE_ID:
		if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		*pValue = (uint16)((((uint16)pDataParams->pCcFile[9] << 8U) & 0xFF00U)
				  | (pDataParams->pCcFile[10]));
		break;

	case PHCE_T4T_CONFIG_NDEF_FILE_READ_ACCESS:
		if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		if(pDataParams->pCcFile[2] == 0x20U)
		{
			*pValue = pDataParams->pCcFile[13];
		}
#ifdef NXPBUILD__PHCE_T4T_EXT_NDEF
		else
		{
			 *pValue = pDataParams->pCcFile[15];
		}
#endif /* NXPBUILD__PHCE_T4T_EXT_NDEF */
		break;

	case PHCE_T4T_CONFIG_NDEF_FILE_WRITE_ACCESS:
		if(pDataParams->bTagState < PHCE_T4T_STATE_NDEF_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		if(pDataParams->pCcFile[2] == 0x20U)
		{
			*pValue = pDataParams->pCcFile[14];
		}
#ifdef NXPBUILD__PHCE_T4T_EXT_NDEF
		else
		{
			*pValue = pDataParams->pCcFile[16];
		}
#endif /* NXPBUILD__PHCE_T4T_EXT_NDEF */
		break;

	case PHCE_T4T_CONFIG_MLE:
		if(pDataParams->bTagState < PHCE_T4T_STATE_CC_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		*pValue = (uint16)((((uint16)pDataParams->pCcFile[3] << 8U) & 0xFF00U)
				  | (pDataParams->pCcFile[4]));
		break;

	case PHCE_T4T_CONFIG_MLC:
		if(pDataParams->bTagState < PHCE_T4T_STATE_CC_FILE_CREATED)
		{
			return (PH_CE_T4T_INVALID_STATE | PH_COMP_CE_T4T);
		}
		*pValue = (uint16)((((uint16)pDataParams->pCcFile[5] << 8U) & 0xFF00U)
				  | (pDataParams->pCcFile[6]));
		break;

	default:
		status = (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		break;
	}

	return status;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHCET4T_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHCE_T4T_SW */
#ifdef __cplusplus
}
#endif
