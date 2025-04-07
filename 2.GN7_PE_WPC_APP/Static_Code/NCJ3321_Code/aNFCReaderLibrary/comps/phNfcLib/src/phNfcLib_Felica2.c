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
*   @file    phNfcLib_Felica2.c
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

#include <ph_Status2.h>
#ifdef NXPBUILD__PH_NFCLIB_FELICA2
#include "phNfcLib_Initialization2.h"
#include "phNfcLib_Int2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_Felica2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_FELICA_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_FELICA_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_FELICA_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_FELICA_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_FELICA_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib_Felica2.h header file are of the same vendor */
#if (PHNFCLIB_FELICA_VENDOR_ID_C2 != PHNFCLIB_FELICA_VENDOR_ID2)
    #error "phNfcLib_Felica2.c and phNfcLib_Felica2.h have different vendor ids"
#endif
/* Check if current file and phNfcLib_Felica2.h header file are of the same Autosar version */
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C2    != PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION2) || \
     (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C2    != PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION2) || \
     (PHNFCLIB_FELICA_AR_RELEASE_REVISION_VERSION_C2 != PHNFCLIB_FELICA_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phNfcLib_Felica2.c and phNfcLib_Felica2.h are different"
#endif
/* Check if current file and phNfcLib_Felica2.h header file are of the same Software version */
#if ((PHNFCLIB_FELICA_SW_MAJOR_VERSION_C2 != PHNFCLIB_FELICA_SW_MAJOR_VERSION2) || \
     (PHNFCLIB_FELICA_SW_MINOR_VERSION_C2 != PHNFCLIB_FELICA_SW_MINOR_VERSION2) || \
     (PHNFCLIB_FELICA_SW_PATCH_VERSION_C2 != PHNFCLIB_FELICA_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phNfcLib_Felica2.c and phNfcLib_Felica2.h are different"
#endif
#endif /* NXPBUILD__PH_NFCLIB_FELICA2*/
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_NFCLIB_FELICA2
#define PH_NFCLIB_FELICA_REQC2                             0x00U   /**< RequestC. */
#define PH_NFCLIB_FELICA_REQ_RESP2                         0x04U   /**< Request Response. */
#define PH_NFCLIB_FELICA_REQ_SERVICE2                      0x02U   /**< Request Service. */
#define PH_NFCLIB_FELICA_READ2                             0x06U   /**< Read. */
#define PH_NFCLIB_FELICA_WRITE2                            0x08U   /**< Write. */
#define PH_NFCLIB_FELICA_SEARCH_SERVICE2                   0x0AU   /**< Search Service Code. */
#define PH_NFCLIB_FELICA_REQ_SYSTEM_CODE2                  0x0CU   /**< Request System Code. */
#define PH_NFCLIB_FELICA_AUTH12                            0x10U   /**< Authentication1. */
#define PH_NFCLIB_FELICA_AUTH22                            0x12U   /**< Authentication2. */
#define PH_NFCLIB_FELICA_READ_SECF2                        0x14U   /**< Read from secure file, DES encryption. */
#define PH_NFCLIB_FELICA_WRITE_SECF2                       0x16U   /**< Write to secure file, DES encryption. */
#define PH_NFCLIB_FELICA_GET_SYS_STATUS2                   0x38U   /**< Get System Status. */
#define PH_NFCLIB_FELICA_REQ_SPEC_VERSION2                 0x3CU   /**< Request Specification Version. */
#define PH_NFCLIB_FELICA_RESET_MODE2                       0x3EU   /**< Reset Mode to mode0. */
#define PH_NFCLIB_FELICA_REQ_SERVICE_V22                   0x32U   /**< Request Service V2. */
#define PH_NFCLIB_FELICA_AUTH1_V22                         0x40U   /**< Authentication1 V2. */
#define PH_NFCLIB_FELICA_AUTH2_V22                         0x42U   /**< Authentication2 V2. */
#define PH_NFCLIB_FELICA_READ_SECF_V22                     0x44U   /**< Read from secure file V2, AES encryption. */
#define PH_NFCLIB_FELICA_WRITE_SECF_V22                    0x46U   /**< Write to secure file V2, AES encryption. */
#define PH_NFCLIB_FELICA_UPDATE_RAND_ID2                   0x4CU   /**< Update Random ID, AES encryption. */

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
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

VAR(phNfcLib_Felica_StateMachine_t2, AUTOMATIC) gphNfcLib_Felica_State2 = eNfcLib_Felica_IdleState2;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Felica_Transmit2(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer2,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength2)
{
	VAR(phStatus_t2, AUTOMATIC) statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint8_t, AUTOMATIC) bCommand2[5];
	VAR(phNfcLib_Felica_t2, AUTOMATIC) phNfcLib_Felica2 =
	((phNfcLib_Transmit_t2 *) pTxBuffer2)->phNfcLib_Felica2;

	switch (gphNfcLib_Felica_State2)
	{
		case eNfcLib_Felica_IdleState2:
		switch (phNfcLib_Felica2.bCommand2)
		{
			case Felica_RequestResponse2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_FELICA_REQ_RESP2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_DEFAULT2, 0, bCommand2, 1,
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
			break;

			case Felica_RequestService2:

			/* Parameter check */
			if (phNfcLib_Felica2.bNumServices2 < 1U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}
			/* Build command frame */
			/* send the command frame fragmented as following:
			 First send [cmd][num_of_srvcs]
			 Then send the service code list in 2-byte chunks since a single service code element
			 consists of 2 bytes. */
			bCommand2[0] = PH_NFCLIB_FELICA_REQ_SERVICE2;
			bCommand2[1] = phNfcLib_Felica2.bNumServices2;

			/* Exchange command ... */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_FIRST2, phNfcLib_Felica2.bNumServices2,
					bCommand2, 2, &gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... and the service code (or area code) list. */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_LAST2, phNfcLib_Felica2.bNumServices2,
					phNfcLib_Felica2.pServiceList2,
					(phNfcLib_Felica2.bNumServices2) * 2U,
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
			break;

			case Felica_Read2:

			/* check correct number of services / blocks */
			if ((phNfcLib_Felica2.bNumServices2 < 1U)
					|| (phNfcLib_Felica2.bNumBlocks2 < 1U))
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* check block list length against numblocks */
			if ((phNfcLib_Felica2.bBlockListLength2
							< (phNfcLib_Felica2.bNumBlocks2 * 2U))
					|| (phNfcLib_Felica2.bBlockListLength2
							> (phNfcLib_Felica2.bNumBlocks2 * 3U)))
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_FELICA_READ2;
			bCommand2[1] = phNfcLib_Felica2.bNumServices2;

			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_FIRST2, phNfcLib_Felica2.bNumBlocks2,
					bCommand2, 2u, &gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... the service code list ... */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_CONT2, phNfcLib_Felica2.bNumBlocks2,
					phNfcLib_Felica2.pServiceList2,
					(uint16_t )(((uint16_t )phNfcLib_Felica2.bNumServices2) * 2U),
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... the number of blocks ... */
			bCommand2[0] = phNfcLib_Felica2.bNumBlocks2;
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_CONT2, phNfcLib_Felica2.bNumBlocks2,
					bCommand2, 1u, &gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... and the block list. */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_LAST2, phNfcLib_Felica2.bNumBlocks2,
					phNfcLib_Felica2.pBlockList2,
					phNfcLib_Felica2.bBlockListLength2,
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
			break;

			case Felica_Write2:
			/* check correct number of services / blocks */
			if ((phNfcLib_Felica2.bNumServices2 < 1U)
					|| (phNfcLib_Felica2.bNumBlocks2 < 1U))
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* check block list length against numblocks */
			if ((phNfcLib_Felica2.bBlockListLength2
							< (phNfcLib_Felica2.bNumBlocks2 * 2U))
					|| (phNfcLib_Felica2.bBlockListLength2
							> (phNfcLib_Felica2.bNumBlocks2 * 3U)))
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_FELICA_WRITE2;
			bCommand2[1] = phNfcLib_Felica2.bNumBlocks2;

			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_FIRST2, phNfcLib_Felica2.bNumBlocks2,
					bCommand2, 2U, &gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... the service code list ... */
			statusTmp2 =
			phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_CONT2, phNfcLib_Felica2.bNumBlocks2,
					phNfcLib_Felica2.pServiceList2,
					(uint16_t )(((uint16_t )phNfcLib_Felica2.bNumServices2)
							<< 1U), &gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			bCommand2[0] = phNfcLib_Felica2.bNumBlocks2;

			/* ... the number of blocks ... */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_CONT2, phNfcLib_Felica2.bNumBlocks2,
					bCommand2, 1U, &gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... the block list ... */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_CONT2, phNfcLib_Felica2.bNumBlocks2,
					phNfcLib_Felica2.pBlockList2,
					phNfcLib_Felica2.bBlockListLength2,
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);

			PH_CHECK_SUCCESS2(statusTmp2)
			;

			/* ... and the block data. */
			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_BUFFER_LAST2, phNfcLib_Felica2.bNumBlocks2,
					phNfcLib_Felica2.pBlockData2,
					(uint16_t )(((uint16_t )phNfcLib_Felica2.bNumBlocks2) * 16U),
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
			break;

			case Felica_SearchService2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_FELICA_SEARCH_SERVICE2;
			bCommand2[1] = (uint8_t) (phNfcLib_Felica2.wServiceIndex2 & 0xFFU);
			bCommand2[2] = (uint8_t) (phNfcLib_Felica2.wServiceIndex2 >> 8U);

			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_DEFAULT2, 1U, bCommand2, 3U,
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
			break;

			case Felica_RequestSystemCodes2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_FELICA_REQ_SYSTEM_CODE2;

			statusTmp2 = phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2,
					PH_EXCHANGE_DEFAULT2, 1U, bCommand2, 1U,
					&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
			break;

			default:
			statusTmp2 = PH_ERR_INVALID_PARAMETER2;
			break;
		}
		if (statusTmp2 == PH_STATUS_INPROCESS2)
		{
			gphNfcLib_Felica_State2 = eNfcLib_Felica_TransmitState2;
			return PH_STATUS_INPROCESS2;
		}
		break;
		case eNfcLib_Felica_TransmitState2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phpalFelica_Exchange2(&gphNfcLib_Params2.spalFelica2, PH_EXCHANGE_DEFAULT2, 0U, bCommand2, 3U, &gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2))
		;

		PH_BREAK_ON_FAILURE2(statusTmp2)
		;

		gphNfcLib_Felica_State2 = eNfcLib_Felica_FinishState2;
		return PH_STATUS_INPROCESS2;

		case eNfcLib_Felica_FinishState2:
		switch (phNfcLib_Felica2.bCommand2)
		{
			case Felica_RequestResponse2:
			/* Check the length */
			if (gphNfcLib_State2.wRxLength2 != 1U)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			case Felica_RequestService2:
			/* Check the length (number of services and service list)*/
			if ((gphNfcLib_State2.wRxLength2 < 1U)
					|| (gphNfcLib_State2.wRxLength2
							!= ((((uint16_t) (gphNfcLib_State2.pRxBuffer2[0]))
											* 2U) + 1U)))
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			case Felica_Read2:
			/* Check response. */
			/* Length: We expect:
			 Status flags:       2 bytes
			 Number of blocks:   1 byte
			 Block data:         16 x number of blocks bytes */

			/* at least 2 status bytes have to be in the rx buffer */
			if (gphNfcLib_State2.wRxLength2 < 2U)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				break;
			}

			/* on a felica error save the status flags */
			if (gphNfcLib_State2.pRxBuffer2[0] != 0U)
			{
				if (gphNfcLib_State2.wRxLength2 != 2U)
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
					break;
				}
				gphNfcLib_State2.wAdditionalInfo2 = ((uint16_t)gphNfcLib_State2.pRxBuffer2[0] << 8U) | (uint16_t)gphNfcLib_State2.pRxBuffer2[1];
				statusTmp2 = PHAL_FELICA_ERR_FELICA2;
				break;
			}

			if (gphNfcLib_State2.wRxLength2
					!= (3u + (16u * ((uint16_t) (gphNfcLib_State2.pRxBuffer2[2])))))
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			case Felica_Write2:
			/* We should have received 2 status bytes */
			if (gphNfcLib_State2.wRxLength2 != 2U)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				break;
			}

			/* save the status on an error */
			if (gphNfcLib_State2.pRxBuffer2[0] != 0U)
			{
				gphNfcLib_State2.wAdditionalInfo2 = ((uint16_t)gphNfcLib_State2.pRxBuffer2[0] << 8U) | (uint16_t)gphNfcLib_State2.pRxBuffer2[1];
				statusTmp2 = PHAL_FELICA_ERR_FELICA2;
			}
			break;

			case Felica_SearchService2:
			if (gphNfcLib_State2.wRxLength2 > 4U)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			case Felica_RequestSystemCodes2:
			if (gphNfcLib_State2.wRxLength2
					!= (uint16_t) (((uint16_t) (gphNfcLib_State2.pRxBuffer2[0])
									* 2U) + 1U))
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;
			default:
			statusTmp2 = PH_ERR_INVALID_PARAMETER2;
			break;
		}
	}

	if ((statusTmp2 & PH_ERR_MASK2) == PHAL_FELICA_ERR_FELICA2)
	{
		statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
	}

	gphNfcLib_Felica_State2 = eNfcLib_Felica_IdleState2;
	return statusTmp2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_FELICA_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_FELICA_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_NFCLIB_FELICA2*/

#ifdef __cplusplus
}
#endif
