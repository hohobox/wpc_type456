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
*   @file    phNfcLib_15693.c
*   @version 1.0.0
*
*   @brief   AUTOSAR NfcLib_15693 - PAL API usage in common use cases.
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
#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
#include "phNfcLib_Initialization.h"
#include "phNfcLib_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_15693.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_15693_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_15693_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_15693_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_15693_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_15693_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib_15693.h header file are of the same vendor */
#if (PHNFCLIB_15693_VENDOR_ID_C != PHNFCLIB_15693_VENDOR_ID)
    #error "phNfcLib_15693.c and phNfcLib_15693.h have different vendor ids"
#endif
/* Check if current file and phNfcLib_15693.h header file are of the same Autosar version */
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C    != PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION) || \
     (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C    != PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION) || \
     (PHNFCLIB_15693_AR_RELEASE_REVISION_VERSION_C != PHNFCLIB_15693_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib_15693.c and phNfcLib_15693.h are different"
#endif
/* Check if current file and phNfcLib_15693.h header file are of the same Software version */
#if ((PHNFCLIB_15693_SW_MAJOR_VERSION_C != PHNFCLIB_15693_SW_MAJOR_VERSION) || \
     (PHNFCLIB_15693_SW_MINOR_VERSION_C != PHNFCLIB_15693_SW_MINOR_VERSION) || \
     (PHNFCLIB_15693_SW_PATCH_VERSION_C != PHNFCLIB_15693_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib_15693.c and phNfcLib_15693.h are different"
#endif
#endif /* NXPBUILD__PH_NFCLIB_ISO_15693*/
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
#define PH_NFCLIB_15693_TIMEOUT_SHORT_US    384U
#define PH_NFCLIB_15693_TIMEOUT_LONG_US   20060U

#define PH_NFCLIB_15693_FLAGS_DSFID    0x01U   /**< Response flag DSFID. */
#define PH_NFCLIB_15693_FLAGS_AFI      0x02U   /**< Response flag AFI. */
#define PH_NFCLIB_15693_FLAGS_MEMSIZE  0x04U   /**< Response flag MEMSIZE. */
#define PH_NFCLIB_15693_FLAGS_ICREF    0x08U   /**< Response flag ICREF. */

#define PH_NFCLIB_15693_READ_SINGLE_BLOCK                 0x20U    /**< ISO15693 read single block command. */
#define PH_NFCLIB_15693_WRITE_SINGLE_BLOCK                0x21U    /**< ISO15693 write single block command. */
#define PH_NFCLIB_15693_LOCK_BLOCK                        0x22U    /**< ISO15693 lock block command. */
#define PH_NFCLIB_15693_READ_MULTIPLE_BLOCKS              0x23U    /**< ISO15693 read multiple blocks command. */
#define PH_NFCLIB_15693_WRITE_MULTIPLE_BLOCKS             0x24U    /**< ISO15693 write multiple blocks command. */
#define PH_NFCLIB_15693_WRITE_AFI                         0x27U    /**< ISO15693 write Application Family Identifier command. */
#define PH_NFCLIB_15693_LOCK_AFI                          0x28U    /**< ISO15693 lock Application Family Identifier command. */
#define PH_NFCLIB_15693_WRITE_DSFID                       0x29U    /**< ISO15693 write Data Storage Format IDentifier command. */
#define PH_NFCLIB_15693_LOCK_DSFID                        0x2AU    /**< ISO15693 lock Data Storage Format IDentifier command. */
#define PH_NFCLIB_15693_GET_SYSTEM_INFO                   0x2BU    /**< ISO15693 get system information command. */
#define PH_NFCLIB_15693_GET_MULTIPLE_BLOCK_SEC            0x2CU    /**< ISO15693 get multiple block security status command. */

#define PH_NFCLIB_15693_EXTENDED_READ_SINGLE_BLOCK        0x30U    /**< ISO15693 extended read single block command. */
#define PH_NFCLIB_15693_EXTENDED_WRITE_SINGLE_BLOCK       0x31U    /**< ISO15693 extended write single block command. */
#define PH_NFCLIB_15693_EXTENDED_LOCK_BLOCK               0x32U    /**< ISO15693 extended lock block command. */
#define PH_NFCLIB_15693_EXTENDED_READ_MULTIPLE_BLOCKS     0x33U    /**< ISO15693 extended read multiple blocks command. */
#define PH_NFCLIB_15693_EXTENDED_WRITE_MULTIPLE_BLOCKS    0x34U    /**< ISO15693 extended write multiple blocks command. */
#define PH_NFCLIB_15693_EXTENDED_GET_SYSTEM_INFO          0x3BU    /**< ISO15693 extended get system information command. */
#define PH_NFCLIB_15693_EXTENDED_GET_MULTIPLE_BLOCK_SEC   0x3CU    /**< ISO15693 extended get multiple block security status command. */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static VAR(phNfcLib_ISO15693_StateMachine_t, AUTOMATIC) gphNfcLib_ISO15693_State = eNfcLib_ISO15693_InitState;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static FUNC(phStatus_t, ANFCRL_API) NfcLib_WriteAlikeHandling(
	VAR(phStatus_t, AUTOMATIC) wExchangeStatus
);

FUNC(phStatus_t, ANFCRL_API) phNfcLib_ISO15693_Transmit(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength)
{
	static VAR(phStatus_t, AUTOMATIC) statusTmp = PH_ERR_SUCCESS;
	VAR(uint8_t, AUTOMATIC) bCommand[5];
	VAR(uint8_t, AUTOMATIC) bExpLength = 0U;

	switch(gphNfcLib_ISO15693_State)
	{
		case eNfcLib_ISO15693_InitState:
		(void)phpalSli15693_SetSerialNo(&gphNfcLib_Params.spalSli15693,
				((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bUid,
				8);
		/*set the addressed bit */
		gphNfcLib_Params.spalSli15693.bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;

		/*reset the selected bit */
		gphNfcLib_Params.spalSli15693.bFlags = gphNfcLib_Params.spalSli15693.bFlags &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_SELECTED;

		/* Set Option bit */
		if (0u != (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption))
		{
			gphNfcLib_Params.spalSli15693.bFlags |= PHPAL_SLI15693_FLAG_OPTION;
		}
		/* Clear option bit */
		else
		{
			gphNfcLib_Params.spalSli15693.bFlags = gphNfcLib_Params.spalSli15693.bFlags &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION;
		}

		gphNfcLib_ISO15693_State = eNfcLib_ISO15693_Timeout;
		/*No break*/

		case eNfcLib_ISO15693_Timeout:
		/* lOGIC depends upon the enum value please make sure whether the api needs PH_NFCLIB_15693_TIMEOUT_LONG_US or
		 * PH_NFCLIB_15693_TIMEOUT_SHORT_US before changing this
		 */
		switch(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bCommand)
		{
			case ISO15693_NoCommand:
			case ISO15693_ReadSingleBlock:
			case ISO15693_Extended_ReadSingleBlock:
			case ISO15693_ReadMultipleBlocks:
			case ISO15693_Extended_ReadMultipleBlocks:
			case ISO15693_GetSystemInformation:
			case ISO15693_ExtendedGetSystemInformation:
			case ISO15693_GetMultipleBlockSecurityStatus:
			case ISO15693_Extended_GetMultipleBlockSecurityStatus:
				/* Set short timeout. */
				PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_SetConfig(
						gphNfcLib_Params.sDiscLoop.pHalDataParams,
						PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
						PH_NFCLIB_15693_TIMEOUT_SHORT_US));
				break;
			case ISO15693_WriteSingleBlock:
			case ISO15693_Extended_WriteSingleBlock:
			case ISO15693_WriteMultipleBlocks:
			case ISO15693_Extended_WriteMultipleBlocks:
			case ISO15693_LockBlock:
			case ISO15693_Extended_LockBlock:
			case ISO15693_WriteAFI:
			case ISO15693_LockAFI:
			case ISO15693_WriteDSFID:
			case ISO15693_LockDSFID:
				/* Set long timeout. */
				PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_SetConfig(
						gphNfcLib_Params.sDiscLoop.pHalDataParams,
						PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
						PH_NFCLIB_15693_TIMEOUT_LONG_US));
				break;
		}
		PH_BREAK_ON_FAILURE(statusTmp);
		gphNfcLib_ISO15693_State = eNfcLib_ISO15693_IdleState;
		/*No break*/

		case eNfcLib_ISO15693_IdleState:
		switch(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bCommand)
		{
			case ISO15693_ReadSingleBlock:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_READ_SINGLE_BLOCK;
			bCommand[1] = (uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					2,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_Extended_ReadSingleBlock:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_READ_SINGLE_BLOCK;
			bCommand[1] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber);
			bCommand[2] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					3,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_ReadMultipleBlocks:

			/* Number of wNumBlocks can't be zero */
			if (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks == 0U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber + ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks) >= 0x100U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_READ_MULTIPLE_BLOCKS;
			bCommand[1] = (uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber;
			bCommand[2] =(uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					3,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_Extended_ReadMultipleBlocks:

			/* Number of wNumBlocks can't be zero */
			if (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks == 0U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Check number of blocks doesn't exceed 256 */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber + ((uint32_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks))) >= 0x10000U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_READ_MULTIPLE_BLOCKS;
			bCommand[1] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber);
			bCommand[2] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber >> 8U);
			bCommand[3] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks);
			bCommand[4] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					3,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_WriteSingleBlock:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_WRITE_SINGLE_BLOCK;
			bCommand[1] = (uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber;

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT(statusTmp, phpalSli15693_Exchange(
							&gphNfcLib_Params.spalSli15693,
							PH_EXCHANGE_BUFFER_FIRST,
							bCommand,
							2,
							NULL,
							NULL));

			/* Append given data */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_BUFFER_LAST,
					((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.pBuffer,
					wTxBufferLength,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_Extended_WriteSingleBlock:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_WRITE_SINGLE_BLOCK;
			bCommand[1] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber);
			bCommand[2] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber >> 8U);

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT(statusTmp, phpalSli15693_Exchange(
							&gphNfcLib_Params.spalSli15693,
							PH_EXCHANGE_BUFFER_FIRST,
							bCommand,
							3,
							NULL,
							NULL));

			/* Append given data */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_BUFFER_LAST,
					((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.pBuffer,
					wTxBufferLength,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_WriteMultipleBlocks:

			/* Number of wNumBlocks can't be zero */
			if (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks == 0U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber + ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks) >= 0x100U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_WRITE_MULTIPLE_BLOCKS;
			bCommand[1] = (uint8_t) ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber;
			bCommand[2] =(uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT(statusTmp, phpalSli15693_Exchange(
							&gphNfcLib_Params.spalSli15693,
							PH_EXCHANGE_BUFFER_FIRST,
							bCommand,
							3,
							NULL,
							NULL));

			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_BUFFER_LAST,
					((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.pBuffer,
					wTxBufferLength,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_Extended_WriteMultipleBlocks:

			/* Number of wNumBlocks can't be zero */
			if (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks == 0U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber + ((uint32_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks))) >= 0x10000U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_WRITE_MULTIPLE_BLOCKS;
			bCommand[1] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber);
			bCommand[2] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber >> 8U);
			bCommand[3] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks);
			bCommand[4] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks >> 8U);

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT(statusTmp, phpalSli15693_Exchange(
							&gphNfcLib_Params.spalSli15693,
							PH_EXCHANGE_BUFFER_FIRST,
							bCommand,
							5,
							NULL,
							NULL));

			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_BUFFER_LAST,
					((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.pBuffer,
					wTxBufferLength,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_LockBlock:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_LOCK_BLOCK;
			bCommand[1] = (uint8_t) ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					2,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_Extended_LockBlock:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_LOCK_BLOCK;
			bCommand[1] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber);
			bCommand[2] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					3,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_WriteAFI:

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_WRITE_AFI;
			bCommand[1] = ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bAfi;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					2,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_LockAFI:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_LOCK_AFI;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					1,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_WriteDSFID:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_WRITE_DSFID;
			bCommand[1] = ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bDsfid;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					2,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);

			break;

			case ISO15693_LockDSFID:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_LOCK_DSFID;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					1,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_GetSystemInformation:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_GET_SYSTEM_INFO;

			/* Clear Option bit */
			gphNfcLib_Params.spalSli15693.bFlags = gphNfcLib_Params.spalSli15693.bFlags &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					1,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_ExtendedGetSystemInformation:
			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_GET_SYSTEM_INFO;

			/* Clear Option bit */
			gphNfcLib_Params.spalSli15693.bFlags = gphNfcLib_Params.spalSli15693.bFlags &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					1,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_GetMultipleBlockSecurityStatus:
			/* Number of wNumBlocks can't be zero */
			if (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks == 0U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber + ((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks) >= 0x100U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Clear Option bit */
			gphNfcLib_Params.spalSli15693.bFlags = gphNfcLib_Params.spalSli15693.bFlags &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION;

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_GET_MULTIPLE_BLOCK_SEC;
			bCommand[1] = (uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber;
			bCommand[2] = (uint8_t)((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					3,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			case ISO15693_Extended_GetMultipleBlockSecurityStatus:

			/* Number of wNumBlocks can't be zero */
			if (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks == 0U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks;

			/* Check number of blocks doesn't exceed 256 */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber + ((uint32_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks))) >= 0x10000U)
			{
				return PH_ERR_INVALID_PARAMETER;
			}

			/* Clear Option bit */
			gphNfcLib_Params.spalSli15693.bFlags = gphNfcLib_Params.spalSli15693.bFlags &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION;

			/* Build command frame */
			bCommand[0] = PH_NFCLIB_15693_EXTENDED_GET_MULTIPLE_BLOCK_SEC;
			bCommand[1] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber);
			bCommand[2] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wBlockNumber >> 8U);
			bCommand[3] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks);
			bCommand[4] = (uint8_t)(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp = phpalSli15693_Exchange(
					&gphNfcLib_Params.spalSli15693,
					PH_EXCHANGE_DEFAULT,
					bCommand,
					5,
					&gphNfcLib_State.pRxBuffer,
					&gphNfcLib_State.wRxLength);
			break;

			default:
			statusTmp = PH_ERR_INVALID_PARAMETER;
			break;
		}

		if (statusTmp == PH_STATUS_INPROCESS)
		{
			gphNfcLib_ISO15693_State = eNfcLib_ISO15693_TransmitState;
			return PH_STATUS_INPROCESS;
		}
		break;
		case eNfcLib_ISO15693_TransmitState:
		PH_CHECK_INPROCESS_FCT(statusTmp, phpalSli15693_Exchange(
						&gphNfcLib_Params.spalSli15693,
						PH_EXCHANGE_DEFAULT,
						bCommand,
						5,
						&gphNfcLib_State.pRxBuffer,
						&gphNfcLib_State.wRxLength));

		gphNfcLib_ISO15693_State = eNfcLib_ISO15693_FinishState;
		return PH_STATUS_INPROCESS;

		case eNfcLib_ISO15693_FinishState:
		switch(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bCommand)
		{
			case ISO15693_ReadSingleBlock:
			/* Length check */
			if (0u != (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption))
			{
				if (gphNfcLib_State.wRxLength < 2U)
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			else
			{
				if (gphNfcLib_State.wRxLength == 0U)
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			break;

			case ISO15693_Extended_ReadSingleBlock:
			/* Length check */
			if (0u != (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption))
			{
				if (gphNfcLib_State.wRxLength < (4u + 1U))
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			else
			{
				if (gphNfcLib_State.wRxLength < 4U)
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			break;

			case ISO15693_ReadMultipleBlocks:
			/* Length check */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				if (gphNfcLib_State.wRxLength <((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks + 1U) * 2U))
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			else
			{
				if (gphNfcLib_State.wRxLength <(((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks + 1U))
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			break;

			case ISO15693_Extended_ReadMultipleBlocks:
			/* Length check */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				if (gphNfcLib_State.wRxLength < ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks + 1U) * (4u + 1U)))
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}
			else
			{
				if (gphNfcLib_State.wRxLength < ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks + 1U) * 4U))
				{
					statusTmp = PH_ERR_PROTOCOL_ERROR;
				}
			}

			break;

			case ISO15693_WriteSingleBlock:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_Extended_WriteSingleBlock:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}

			break;

			case ISO15693_WriteMultipleBlocks:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_Extended_WriteMultipleBlocks:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_LockBlock:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_Extended_LockBlock:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_WriteAFI:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_LockAFI:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_WriteDSFID:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_LockDSFID:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.bOption) != 0U)
			{
				gphNfcLib_ISO15693_State = eNfcLib_ISO15693_WriteAlike;
				return PH_STATUS_INPROCESS;
			}
			break;

			case ISO15693_GetSystemInformation:
			/* Check number of data received */
			if (gphNfcLib_State.wRxLength == 0U)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
				break;
			}

			/* Expected length is 9 by default */
			bExpLength = 9U;

			/* Check for DSFID byte */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_DSFID))
			{
				++bExpLength;
			}

			/* Check for AFI byte */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_AFI))
			{
				++bExpLength;
			}

			/* Check for MEMSIZE bytes */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_MEMSIZE))
			{
				bExpLength += 2U;
			}

			/* Check for ICREF byte */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_ICREF))
			{
				++bExpLength;
			}

			/* Check response length */
			if (gphNfcLib_State.wRxLength < bExpLength)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			case ISO15693_ExtendedGetSystemInformation:
			/* Check number of data received */
			if (gphNfcLib_State.wRxLength == 0U)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
				break;
			}

			/* Expected length is 9 by default */
			bExpLength = 9U;

			/* Check for DSFID byte */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_DSFID))
			{
				++bExpLength;
			}

			/* Check for AFI byte */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_AFI))
			{
				++bExpLength;
			}

			/* Check for MEMSIZE bytes */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_MEMSIZE))
			{
				bExpLength += 3U;
			}

			/* Check for ICREF byte */
			if (0U != ((gphNfcLib_State.pRxBuffer[0]) & PH_NFCLIB_15693_FLAGS_ICREF))
			{
				++bExpLength;
			}

			/* Check response length */
			if (gphNfcLib_State.wRxLength < bExpLength)
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			case ISO15693_GetMultipleBlockSecurityStatus:
			break;

			case ISO15693_Extended_GetMultipleBlockSecurityStatus:
			/* Check response length */
			if (gphNfcLib_State.wRxLength != (((phNfcLib_Transmit_t *)pTxBuffer)->phNfcLib_ISO15693.wNumBlocks + 1U))
			{
				statusTmp = PH_ERR_PROTOCOL_ERROR;
			}
			break;

			default:
			statusTmp = PH_ERR_INVALID_PARAMETER;
			break;
		}
		break;

		case eNfcLib_ISO15693_WriteAlike:
		PH_CHECK_INPROCESS_FCT(statusTmp, NfcLib_WriteAlikeHandling(statusTmp));
		break;
	}

	if ((statusTmp & PH_ERR_MASK) == PHPAL_SLI15693_ERR_ISO15693)
	{
		statusTmp = PH_ERR_PROTOCOL_ERROR;
	}
	gphNfcLib_ISO15693_State = eNfcLib_ISO15693_InitState;
	return statusTmp;
}

static FUNC(phStatus_t, ANFCRL_API) NfcLib_WriteAlikeHandling(
	VAR(phStatus_t, AUTOMATIC) wExchangeStatus
)
{
	VAR(uint8_t, AUTOMATIC) bDsfid;
	VAR(uint8_t, AUTOMATIC) bUid[PHPAL_SLI15693_UID_LENGTH];
	VAR(uint8_t, AUTOMATIC) bUidLength;
	VAR(uint8_t, AUTOMATIC) bData[1];
	VAR(uint16_t, AUTOMATIC) wDataLength = 0;

	switch (wExchangeStatus & PH_ERR_MASK)
	{
		/* Check for protocol error  */
		case PH_ERR_SUCCESS:
		return PH_ERR_PROTOCOL_ERROR;

		/* Timeout is correct behaviour, send EOF */
		case PH_ERR_IO_TIMEOUT:
		/* card answers after next EOF -> correct status is timeout */
		return phpalSli15693_SendEof(
				&gphNfcLib_Params.spalSli15693,
				PHPAL_SLI15693_EOF_WRITE_ALIKE,
				&bDsfid,
				bUid,
				&bUidLength,
				bData,
				&wDataLength);

		/* Framing errors etc. are ignored and the waiting until EOF sending is continued */
		case PH_ERR_INTEGRITY_ERROR:
		case PH_ERR_COLLISION_ERROR:
		case PH_ERR_FRAMING_ERROR:
		return phpalSli15693_SendEof(
				&gphNfcLib_Params.spalSli15693,
				PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT,
				&bDsfid,
				bUid,
				&bUidLength,
				bData,
				&wDataLength);

		/* Directly return all other errors */
		default:
		return wExchangeStatus;
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_NFCLIB_ISO_15693*/

#ifdef __cplusplus
}
#endif
