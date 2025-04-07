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
*   @file    phNfcLib_Felica.c
*   @version 1.0.0
*
*   @brief   AUTOSAR NfcLib_Felica - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup nfc_lib NXP NFC Library Top Level API
*   @ingroup grpsApi
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
#ifdef NXPBUILD__PH_NFCLIB_FELICA
#include "phNfcLib_Initialization.h"
#include "phNfcLib_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_Felica.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_FELICA_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_FELICA_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_FELICA_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_FELICA_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_FELICA_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib_Felica.h header file are of the same vendor */
#if (PHNFCLIB_FELICA_VENDOR_ID_C != PHNFCLIB_FELICA_VENDOR_ID)
    #error "phNfcLib_Felica.c and phNfcLib_Felica.h have different vendor ids"
#endif
/* Check if current file and phNfcLib_Felica.h header file are of the same Autosar version */
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C    != PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION) || \
     (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C    != PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION) || \
     (PHNFCLIB_FELICA_AR_RELEASE_REVISION_VERSION_C != PHNFCLIB_FELICA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib_Felica.c and phNfcLib_Felica.h are different"
#endif
/* Check if current file and phNfcLib_Felica.h header file are of the same Software version */
#if ((PHNFCLIB_FELICA_SW_MAJOR_VERSION_C != PHNFCLIB_FELICA_SW_MAJOR_VERSION) || \
     (PHNFCLIB_FELICA_SW_MINOR_VERSION_C != PHNFCLIB_FELICA_SW_MINOR_VERSION) || \
     (PHNFCLIB_FELICA_SW_PATCH_VERSION_C != PHNFCLIB_FELICA_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib_Felica.c and phNfcLib_Felica.h are different"
#endif
#endif /* NXPBUILD__PH_NFCLIB_FELICA*/
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_NFCLIB_FELICA
#define PH_NFCLIB_FELICA_REQC                             0x00U   /**< RequestC. */
#define PH_NFCLIB_FELICA_REQ_RESP                         0x04U   /**< Request Response. */
#define PH_NFCLIB_FELICA_REQ_SERVICE                      0x02U   /**< Request Service. */
#define PH_NFCLIB_FELICA_READ                             0x06U   /**< Read. */
#define PH_NFCLIB_FELICA_WRITE                            0x08U   /**< Write. */
#define PH_NFCLIB_FELICA_SEARCH_SERVICE                   0x0AU   /**< Search Service Code. */
#define PH_NFCLIB_FELICA_REQ_SYSTEM_CODE                  0x0CU   /**< Request System Code. */
#define PH_NFCLIB_FELICA_AUTH1                            0x10U   /**< Authentication1. */
#define PH_NFCLIB_FELICA_AUTH2                            0x12U   /**< Authentication2. */
#define PH_NFCLIB_FELICA_READ_SECF                        0x14U   /**< Read from secure file, DES encryption. */
#define PH_NFCLIB_FELICA_WRITE_SECF                       0x16U   /**< Write to secure file, DES encryption. */
#define PH_NFCLIB_FELICA_GET_SYS_STATUS                   0x38U   /**< Get System Status. */
#define PH_NFCLIB_FELICA_REQ_SPEC_VERSION                 0x3CU   /**< Request Specification Version. */
#define PH_NFCLIB_FELICA_RESET_MODE                       0x3EU   /**< Reset Mode to mode0. */
#define PH_NFCLIB_FELICA_REQ_SERVICE_V2                   0x32U   /**< Request Service V2. */
#define PH_NFCLIB_FELICA_AUTH1_V2                         0x40U   /**< Authentication1 V2. */
#define PH_NFCLIB_FELICA_AUTH2_V2                         0x42U   /**< Authentication2 V2. */
#define PH_NFCLIB_FELICA_READ_SECF_V2                     0x44U   /**< Read from secure file V2, AES encryption. */
#define PH_NFCLIB_FELICA_WRITE_SECF_V2                    0x46U   /**< Write to secure file V2, AES encryption. */
#define PH_NFCLIB_FELICA_UPDATE_RAND_ID                   0x4CU   /**< Update Random ID, AES encryption. */

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
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

VAR(phNfcLib_Felica_StateMachine_t, AUTOMATIC) gphNfcLib_Felica_State = eNfcLib_Felica_IdleState;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_API) phNfcLib_Felica_Transmit(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength)
{
	VAR(phStatus_t, AUTOMATIC) statusTmp = PH_ERR_SUCCESS;
	VAR(uint8_t, AUTOMATIC) bCommand[5];
	VAR(phNfcLib_Felica_t, AUTOMATIC) phNfcLib_Felica =
	((phNfcLib_Transmit_t *) pTxBuffer)->phNfcLib_Felica;

	switch (gphNfcLib_Felica_State)
	{
		case eNfcLib_Felica_IdleState:
		switch (phNfcLib_Felica.bCommand)
		{
			case Felica_RequestResponse:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_FELICA_REQ_RESP;

			/* Proceed with the command in lower layers */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_DEFAULT, 0, bCommand, 1,
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
			break;

			case Felica_RequestService:

			/* Parameter check */
			if (phNfcLib_Felica.bNumServices < 1U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}
			/* Build command frame */
			/* send the command frame fragmented as following:
			 First send [cmd][num_of_srvcs]
			 Then send the service code list in 2-byte chunks since a single service code element
			 consists of 2 bytes. */
			bCommand[0] = PH_NFCLIB_FELICA_REQ_SERVICE;
			bCommand[1] = phNfcLib_Felica.bNumServices;

			/* Exchange command ... */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_FIRST, phNfcLib_Felica.bNumServices,
					bCommand, 2, &gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... and the service code (or area code) list. */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_LAST, phNfcLib_Felica.bNumServices,
					phNfcLib_Felica.pServiceList,
					(phNfcLib_Felica.bNumServices) * 2U,
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
			break;

			case Felica_Read:

			/* check correct number of services / blocks */
			if ((phNfcLib_Felica.bNumServices < 1U)
					|| (phNfcLib_Felica.bNumBlocks < 1U))
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* check block list length against numblocks */
			if ((phNfcLib_Felica.bBlockListLength
							< (phNfcLib_Felica.bNumBlocks * 2U))
					|| (phNfcLib_Felica.bBlockListLength
							> (phNfcLib_Felica.bNumBlocks * 3U)))
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_FELICA_READ;
			bCommand[1] = phNfcLib_Felica.bNumServices;

			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_FIRST, phNfcLib_Felica.bNumBlocks,
					bCommand, 2u, &gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... the service code list ... */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_CONT, phNfcLib_Felica.bNumBlocks,
					phNfcLib_Felica.pServiceList,
					(uint16_t )(((uint16_t )phNfcLib_Felica.bNumServices) * 2U),
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... the number of blocks ... */
			bCommand[0] = phNfcLib_Felica.bNumBlocks;
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_CONT, phNfcLib_Felica.bNumBlocks,
					bCommand, 1u, &gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... and the block list. */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_LAST, phNfcLib_Felica.bNumBlocks,
					phNfcLib_Felica.pBlockList,
					phNfcLib_Felica.bBlockListLength,
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
			break;

			case Felica_Write:
			/* check correct number of services / blocks */
			if ((phNfcLib_Felica.bNumServices < 1U)
					|| (phNfcLib_Felica.bNumBlocks < 1U))
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* check block list length against numblocks */
			if ((phNfcLib_Felica.bBlockListLength
							< (phNfcLib_Felica.bNumBlocks * 2U))
					|| (phNfcLib_Felica.bBlockListLength
							> (phNfcLib_Felica.bNumBlocks * 3U)))
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_FELICA_WRITE;
			bCommand[1] = phNfcLib_Felica.bNumBlocks;

			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_FIRST, phNfcLib_Felica.bNumBlocks,
					bCommand, 2U, &gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... the service code list ... */
			statusTmp =
			phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_CONT, phNfcLib_Felica.bNumBlocks,
					phNfcLib_Felica.pServiceList,
					(uint16_t )(((uint16_t )phNfcLib_Felica.bNumServices)
							<< 1U), &gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			bCommand[0] = phNfcLib_Felica.bNumBlocks;

			/* ... the number of blocks ... */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_CONT, phNfcLib_Felica.bNumBlocks,
					bCommand, 1U, &gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... the block list ... */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_CONT, phNfcLib_Felica.bNumBlocks,
					phNfcLib_Felica.pBlockList,
					phNfcLib_Felica.bBlockListLength,
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);

			PH_CHECK_SUCCESS(statusTmp)
			;

			/* ... and the block data. */
			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_BUFFER_LAST, phNfcLib_Felica.bNumBlocks,
					phNfcLib_Felica.pBlockData,
					(uint16_t )(((uint16_t )phNfcLib_Felica.bNumBlocks) * 16U),
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
			break;

			case Felica_SearchService:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_FELICA_SEARCH_SERVICE;
			bCommand[1] = (uint8_t) (phNfcLib_Felica.wServiceIndex & 0xFFU);
			bCommand[2] = (uint8_t) (phNfcLib_Felica.wServiceIndex >> 8U);

			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_DEFAULT, 1U, bCommand, 3U,
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
			break;

			case Felica_RequestSystemCodes:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_FELICA_REQ_SYSTEM_CODE;

			statusTmp = phpalFelica_Exchange(&gphNfcLib_Params.spalFelica,
					PH_EXCHANGE_DEFAULT, 1U, bCommand, 1U,
					&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
			break;

			default:
			statusTmp = PH_ERR_INVALID_PARAMETER;
			break;
		}
		if (statusTmp == PH_STATUS_INPROCESS)
		{
			gphNfcLib_Felica_State = eNfcLib_Felica_TransmitState;
			return PH_STATUS_INPROCESS;
		}
		break;
		case eNfcLib_Felica_TransmitState:
		PH_CHECK_INPROCESS_FCT(statusTmp,
				phpalFelica_Exchange(&gphNfcLib_Params.spalFelica, PH_EXCHANGE_DEFAULT, 0U, bCommand, 3U, &gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength))
		;

		PH_BREAK_ON_FAILURE(statusTmp)
		;

		gphNfcLib_Felica_State = eNfcLib_Felica_FinishState;
		return PH_STATUS_INPROCESS;

		case eNfcLib_Felica_FinishState:
		switch (phNfcLib_Felica.bCommand)
		{
			case Felica_RequestResponse:
			/* Check the length */
			if (gphNfcLib_State.wRxLength != 1U)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			case Felica_RequestService:
			/* Check the length (number of services and service list)*/
			if ((gphNfcLib_State.wRxLength < 1U)
					|| (gphNfcLib_State.wRxLength
							!= ((((uint16_t) (gphNfcLib_State.pRxBuffer[0]))
											* 2U) + 1U)))
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			case Felica_Read:
			/* Check response. */
			/* Length: We expect:
			 Status flags:       2 bytes
			 Number of blocks:   1 byte
			 Block data:         16 x number of blocks bytes */

			/* at least 2 status bytes have to be in the rx buffer */
			if (gphNfcLib_State.wRxLength < 2U)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
				break;
			}

			/* on a felica error save the status flags */
			if (gphNfcLib_State.pRxBuffer[0] != 0U)
			{
				if (gphNfcLib_State.wRxLength != 2U)
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
					break;
				}
				gphNfcLib_State.wAdditionalInfo = ((uint16_t)gphNfcLib_State.pRxBuffer[0] << 8U) | (uint16_t)gphNfcLib_State.pRxBuffer[1];
				statusTmp = PHAL_FELICA_ERR_FELICA;
				break;
			}

			if (gphNfcLib_State.wRxLength
					!= (3u + (16u * ((uint16_t) (gphNfcLib_State.pRxBuffer[2])))))
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			case Felica_Write:
			/* We should have received 2 status bytes */
			if (gphNfcLib_State.wRxLength != 2U)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
				break;
			}

			/* save the status on an error */
			if (gphNfcLib_State.pRxBuffer[0] != 0U)
			{
				gphNfcLib_State.wAdditionalInfo = ((uint16_t)gphNfcLib_State.pRxBuffer[0] << 8U) | (uint16_t)gphNfcLib_State.pRxBuffer[1];
				statusTmp = PHAL_FELICA_ERR_FELICA;
			}
			break;

			case Felica_SearchService:
			if (gphNfcLib_State.wRxLength > 4U)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			case Felica_RequestSystemCodes:
			if (gphNfcLib_State.wRxLength
					!= (uint16_t) (((uint16_t) (gphNfcLib_State.pRxBuffer[0])
									* 2U) + 1U))
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;
			default:
			statusTmp = PH_ERR_INVALID_PARAMETER;
			break;
		}
	}

	if ((statusTmp & PH_ERR_MASK) == PHAL_FELICA_ERR_FELICA)
	{
		statusTmp = PH_ERR_PROTOCOL_ERROR;
	}

	gphNfcLib_Felica_State = eNfcLib_Felica_IdleState;
	return statusTmp;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_NFCLIB_FELICA*/

#ifdef __cplusplus
}
#endif
