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
*   @file    phNfcLib_156932.c
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

#include <ph_Status2.h>
#ifdef NXPBUILD__PH_NFCLIB_ISO_156932
#include "phNfcLib_Initialization2.h"
#include "phNfcLib_Int2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_156932.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_15693_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_15693_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_15693_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_15693_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_15693_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib_156932.h header file are of the same vendor */
#if (PHNFCLIB_15693_VENDOR_ID_C2 != PHNFCLIB_15693_VENDOR_ID)
    #error "phNfcLib_156932.c and phNfcLib_156932.h have different vendor ids"
#endif
/* Check if current file and phNfcLib_156932.h header file are of the same Autosar version */
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C2    != PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION2) || \
     (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C2    != PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION2) || \
     (PHNFCLIB_15693_AR_RELEASE_REVISION_VERSION_C2 != PHNFCLIB_15693_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phNfcLib_156932.c and phNfcLib_156932.h are different"
#endif
/* Check if current file and phNfcLib_156932.h header file are of the same Software version */
#if ((PHNFCLIB_15693_SW_MAJOR_VERSION_C2 != PHNFCLIB_15693_SW_MAJOR_VERSION2) || \
     (PHNFCLIB_15693_SW_MINOR_VERSION_C2 != PHNFCLIB_15693_SW_MINOR_VERSION2) || \
     (PHNFCLIB_15693_SW_PATCH_VERSION_C2 != PHNFCLIB_15693_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phNfcLib_156932.c and phNfcLib_156932.h are different"
#endif
#endif /* NXPBUILD__PH_NFCLIB_ISO_156932*/
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_NFCLIB_ISO_156932
#define PH_NFCLIB_15693_TIMEOUT_SHORT_US2    384U
#define PH_NFCLIB_15693_TIMEOUT_LONG_US2   20060U

#define PH_NFCLIB_15693_FLAGS_DSFID2    0x01U   /**< Response flag DSFID. */
#define PH_NFCLIB_15693_FLAGS_AFI2      0x02U   /**< Response flag AFI. */
#define PH_NFCLIB_15693_FLAGS_MEMSIZE2  0x04U   /**< Response flag MEMSIZE. */
#define PH_NFCLIB_15693_FLAGS_ICREF2    0x08U   /**< Response flag ICREF. */

#define PH_NFCLIB_15693_READ_SINGLE_BLOCK2                 0x20U    /**< ISO15693 read single block command. */
#define PH_NFCLIB_15693_WRITE_SINGLE_BLOCK2                0x21U    /**< ISO15693 write single block command. */
#define PH_NFCLIB_15693_LOCK_BLOCK2                        0x22U    /**< ISO15693 lock block command. */
#define PH_NFCLIB_15693_READ_MULTIPLE_BLOCKS2              0x23U    /**< ISO15693 read multiple blocks command. */
#define PH_NFCLIB_15693_WRITE_MULTIPLE_BLOCKS2             0x24U    /**< ISO15693 write multiple blocks command. */
#define PH_NFCLIB_15693_WRITE_AFI2                         0x27U    /**< ISO15693 write Application Family Identifier command. */
#define PH_NFCLIB_15693_LOCK_AFI2                          0x28U    /**< ISO15693 lock Application Family Identifier command. */
#define PH_NFCLIB_15693_WRITE_DSFID2                       0x29U    /**< ISO15693 write Data Storage Format IDentifier command. */
#define PH_NFCLIB_15693_LOCK_DSFID2                        0x2AU    /**< ISO15693 lock Data Storage Format IDentifier command. */
#define PH_NFCLIB_15693_GET_SYSTEM_INFO2                   0x2BU    /**< ISO15693 get system information command. */
#define PH_NFCLIB_15693_GET_MULTIPLE_BLOCK_SEC2            0x2CU    /**< ISO15693 get multiple block security status command. */

#define PH_NFCLIB_15693_EXTENDED_READ_SINGLE_BLOCK2        0x30U    /**< ISO15693 extended read single block command. */
#define PH_NFCLIB_15693_EXTENDED_WRITE_SINGLE_BLOCK2       0x31U    /**< ISO15693 extended write single block command. */
#define PH_NFCLIB_15693_EXTENDED_LOCK_BLOCK2               0x32U    /**< ISO15693 extended lock block command. */
#define PH_NFCLIB_15693_EXTENDED_READ_MULTIPLE_BLOCKS2     0x33U    /**< ISO15693 extended read multiple blocks command. */
#define PH_NFCLIB_15693_EXTENDED_WRITE_MULTIPLE_BLOCKS2    0x34U    /**< ISO15693 extended write multiple blocks command. */
#define PH_NFCLIB_15693_EXTENDED_GET_SYSTEM_INFO2          0x3BU    /**< ISO15693 extended get system information command. */
#define PH_NFCLIB_15693_EXTENDED_GET_MULTIPLE_BLOCK_SEC2   0x3CU    /**< ISO15693 extended get multiple block security status command. */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static VAR(phNfcLib_ISO15693_StateMachine_t2, AUTOMATIC) gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_InitState2;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static FUNC(phStatus_t2, ANFCRL_API) NfcLib_WriteAlikeHandling2(
	VAR(phStatus_t2, AUTOMATIC) wExchangeStatus2
);

FUNC(phStatus_t2, ANFCRL_API) phNfcLib_ISO15693_Transmit2(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer2,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength2)
{
	static VAR(phStatus_t2, AUTOMATIC) statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint8_t, AUTOMATIC) bCommand2[5];
	VAR(uint8_t, AUTOMATIC) bExpLength2 = 0U;

	switch(gphNfcLib_ISO15693_State2)
	{
		case eNfcLib_ISO15693_InitState2:
		(void)phpalSli15693_SetSerialNo2(&gphNfcLib_Params2.spalSli156932,
				((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bUid2,
				8);
		/*set the addressed bit */
		gphNfcLib_Params2.spalSli156932.bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;

		/*reset the selected bit */
		gphNfcLib_Params2.spalSli156932.bFlags2 = gphNfcLib_Params2.spalSli156932.bFlags2 &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_SELECTED2;

		/* Set Option bit */
		if (0u != (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2))
		{
			gphNfcLib_Params2.spalSli156932.bFlags2 |= PHPAL_SLI15693_FLAG_OPTION2;
		}
		/* Clear option bit */
		else
		{
			gphNfcLib_Params2.spalSli156932.bFlags2 = gphNfcLib_Params2.spalSli156932.bFlags2 &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION2;
		}

		gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_Timeout2;
		/*No break*/

		case eNfcLib_ISO15693_Timeout2:
		/* lOGIC depends upon the enum value please make sure whether the api needs PH_NFCLIB_15693_TIMEOUT_LONG_US2 or
		 * PH_NFCLIB_15693_TIMEOUT_SHORT_US2 before changing this
		 */
		switch(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bCommand2)
		{
			case ISO15693_NoCommand2:
			case ISO15693_ReadSingleBlock2:
			case ISO15693_Extended_ReadSingleBlock2:
			case ISO15693_ReadMultipleBlocks2:
			case ISO15693_Extended_ReadMultipleBlocks2:
			case ISO15693_GetSystemInformation2:
			case ISO15693_ExtendedGetSystemInformation2:
			case ISO15693_GetMultipleBlockSecurityStatus2:
			case ISO15693_Extended_GetMultipleBlockSecurityStatus2:
				/* Set short timeout. */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_SetConfig2(
						gphNfcLib_Params2.sDiscLoop.pHalDataParams2,
						PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
						PH_NFCLIB_15693_TIMEOUT_SHORT_US2));
				break;
			case ISO15693_WriteSingleBlock2:
			case ISO15693_Extended_WriteSingleBlock2:
			case ISO15693_WriteMultipleBlocks2:
			case ISO15693_Extended_WriteMultipleBlocks2:
			case ISO15693_LockBlock2:
			case ISO15693_Extended_LockBlock2:
			case ISO15693_WriteAFI2:
			case ISO15693_LockAFI2:
			case ISO15693_WriteDSFID2:
			case ISO15693_LockDSFID2:
				/* Set long timeout. */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_SetConfig2(
						gphNfcLib_Params2.sDiscLoop.pHalDataParams2,
						PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
						PH_NFCLIB_15693_TIMEOUT_LONG_US2));
				break;
		}
		PH_BREAK_ON_FAILURE2(statusTmp2);
		gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_IdleState2;
		/*No break*/

		case eNfcLib_ISO15693_IdleState2:
		switch(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bCommand2)
		{
			case ISO15693_ReadSingleBlock2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_READ_SINGLE_BLOCK2;
			bCommand2[1] = (uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_Extended_ReadSingleBlock2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_READ_SINGLE_BLOCK2;
			bCommand2[1] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2);
			bCommand2[2] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					3,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_ReadMultipleBlocks2:

			/* Number of wNumBlocks2 can't be zero */
			if (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 == 0U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 + ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2) >= 0x100U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_READ_MULTIPLE_BLOCKS2;
			bCommand2[1] = (uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2;
			bCommand2[2] =(uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					3,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_Extended_ReadMultipleBlocks2:

			/* Number of wNumBlocks2 can't be zero */
			if (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 == 0U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Check number of blocks doesn't exceed 256 */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 + ((uint32_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2))) >= 0x10000U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_READ_MULTIPLE_BLOCKS2;
			bCommand2[1] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2);
			bCommand2[2] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 >> 8U);
			bCommand2[3] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2);
			bCommand2[4] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					3,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_WriteSingleBlock2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_WRITE_SINGLE_BLOCK2;
			bCommand2[1] = (uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2;

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phpalSli15693_Exchange2(
							&gphNfcLib_Params2.spalSli156932,
							PH_EXCHANGE_BUFFER_FIRST2,
							bCommand2,
							2,
							NULL,
							NULL));

			/* Append given data */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_BUFFER_LAST2,
					((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.pBuffer2,
					wTxBufferLength2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_Extended_WriteSingleBlock2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_WRITE_SINGLE_BLOCK2;
			bCommand2[1] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2);
			bCommand2[2] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 >> 8U);

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phpalSli15693_Exchange2(
							&gphNfcLib_Params2.spalSli156932,
							PH_EXCHANGE_BUFFER_FIRST2,
							bCommand2,
							3,
							NULL,
							NULL));

			/* Append given data */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_BUFFER_LAST2,
					((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.pBuffer2,
					wTxBufferLength2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_WriteMultipleBlocks2:

			/* Number of wNumBlocks2 can't be zero */
			if (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 == 0U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 + ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2) >= 0x100U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_WRITE_MULTIPLE_BLOCKS2;
			bCommand2[1] = (uint8_t) ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2;
			bCommand2[2] =(uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phpalSli15693_Exchange2(
							&gphNfcLib_Params2.spalSli156932,
							PH_EXCHANGE_BUFFER_FIRST2,
							bCommand2,
							3,
							NULL,
							NULL));

			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_BUFFER_LAST2,
					((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.pBuffer2,
					wTxBufferLength2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_Extended_WriteMultipleBlocks2:

			/* Number of wNumBlocks2 can't be zero */
			if (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 == 0U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 + ((uint32_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2))) >= 0x10000U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_WRITE_MULTIPLE_BLOCKS2;
			bCommand2[1] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2);
			bCommand2[2] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 >> 8U);
			bCommand2[3] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2);
			bCommand2[4] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 >> 8U);

			/* Proceed with the command in lower layers */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phpalSli15693_Exchange2(
							&gphNfcLib_Params2.spalSli156932,
							PH_EXCHANGE_BUFFER_FIRST2,
							bCommand2,
							5,
							NULL,
							NULL));

			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_BUFFER_LAST2,
					((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.pBuffer2,
					wTxBufferLength2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_LockBlock2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_LOCK_BLOCK2;
			bCommand2[1] = (uint8_t) ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_Extended_LockBlock2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_LOCK_BLOCK2;
			bCommand2[1] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2);
			bCommand2[2] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					3,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_WriteAFI2:

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_WRITE_AFI2;
			bCommand2[1] = ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bAfi2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_LockAFI2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_LOCK_AFI2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					1,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_WriteDSFID2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_WRITE_DSFID2;
			bCommand2[1] = ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bDsfid2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					2,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);

			break;

			case ISO15693_LockDSFID2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_LOCK_DSFID2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					1,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_GetSystemInformation2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_GET_SYSTEM_INFO2;

			/* Clear Option bit */
			gphNfcLib_Params2.spalSli156932.bFlags2 = gphNfcLib_Params2.spalSli156932.bFlags2 &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					1,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_ExtendedGetSystemInformation2:
			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_GET_SYSTEM_INFO2;

			/* Clear Option bit */
			gphNfcLib_Params2.spalSli156932.bFlags2 = gphNfcLib_Params2.spalSli156932.bFlags2 &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					1,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_GetMultipleBlockSecurityStatus2:
			/* Number of wNumBlocks2 can't be zero */
			if (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 == 0U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Check number of blocks doesn't exceed 256 */
			if (((uint16_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 + ((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2) >= 0x100U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Clear Option bit */
			gphNfcLib_Params2.spalSli156932.bFlags2 = gphNfcLib_Params2.spalSli156932.bFlags2 &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION2;

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_GET_MULTIPLE_BLOCK_SEC2;
			bCommand2[1] = (uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2;
			bCommand2[2] = (uint8_t)((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					3,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			case ISO15693_Extended_GetMultipleBlockSecurityStatus2:

			/* Number of wNumBlocks2 can't be zero */
			if (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 == 0U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* adjust number of blocks. */
			--((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2;

			/* Check number of blocks doesn't exceed 256 */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 + ((uint32_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2))) >= 0x10000U)
			{
				return PH_ERR_INVALID_PARAMETER2;
			}

			/* Clear Option bit */
			gphNfcLib_Params2.spalSli156932.bFlags2 = gphNfcLib_Params2.spalSli156932.bFlags2 &(uint8_t)~(uint8_t)PHPAL_SLI15693_FLAG_OPTION2;

			/* Build command frame */
			bCommand2[0] = PH_NFCLIB_15693_EXTENDED_GET_MULTIPLE_BLOCK_SEC2;
			bCommand2[1] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2);
			bCommand2[2] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wBlockNumber2 >> 8U);
			bCommand2[3] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2);
			bCommand2[4] = (uint8_t)(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 >> 8U);

			/* Proceed with the command in lower layers */
			statusTmp2 = phpalSli15693_Exchange2(
					&gphNfcLib_Params2.spalSli156932,
					PH_EXCHANGE_DEFAULT2,
					bCommand2,
					5,
					&gphNfcLib_State2.pRxBuffer2,
					&gphNfcLib_State2.wRxLength2);
			break;

			default:
			statusTmp2 = PH_ERR_INVALID_PARAMETER2;
			break;
		}

		if (statusTmp2 == PH_STATUS_INPROCESS2)
		{
			gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_TransmitState2;
			return PH_STATUS_INPROCESS2;
		}
		break;
		case eNfcLib_ISO15693_TransmitState2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phpalSli15693_Exchange2(
						&gphNfcLib_Params2.spalSli156932,
						PH_EXCHANGE_DEFAULT2,
						bCommand2,
						5,
						&gphNfcLib_State2.pRxBuffer2,
						&gphNfcLib_State2.wRxLength2));

		gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_FinishState2;
		return PH_STATUS_INPROCESS2;

		case eNfcLib_ISO15693_FinishState2:
		switch(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bCommand2)
		{
			case ISO15693_ReadSingleBlock2:
			/* Length check */
			if (0u != (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2))
			{
				if (gphNfcLib_State2.wRxLength2 < 2U)
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			else
			{
				if (gphNfcLib_State2.wRxLength2 == 0U)
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			break;

			case ISO15693_Extended_ReadSingleBlock2:
			/* Length check */
			if (0u != (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2))
			{
				if (gphNfcLib_State2.wRxLength2 < (4u + 1U))
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			else
			{
				if (gphNfcLib_State2.wRxLength2 < 4U)
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			break;

			case ISO15693_ReadMultipleBlocks2:
			/* Length check */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				if (gphNfcLib_State2.wRxLength2 <((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 + 1U) * 2U))
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			else
			{
				if (gphNfcLib_State2.wRxLength2 <(((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 + 1U))
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			break;

			case ISO15693_Extended_ReadMultipleBlocks2:
			/* Length check */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				if (gphNfcLib_State2.wRxLength2 < ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 + 1U) * (4u + 1U)))
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}
			else
			{
				if (gphNfcLib_State2.wRxLength2 < ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 + 1U) * 4U))
				{
					statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				}
			}

			break;

			case ISO15693_WriteSingleBlock2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_Extended_WriteSingleBlock2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}

			break;

			case ISO15693_WriteMultipleBlocks2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_Extended_WriteMultipleBlocks2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_LockBlock2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_Extended_LockBlock2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_WriteAFI2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_LockAFI2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_WriteDSFID2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_LockDSFID2:
			/* Write-alike handling */
			if ((((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.bOption2) != 0U)
			{
				gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_WriteAlike2;
				return PH_STATUS_INPROCESS2;
			}
			break;

			case ISO15693_GetSystemInformation2:
			/* Check number of data received */
			if (gphNfcLib_State2.wRxLength2 == 0U)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				break;
			}

			/* Expected length is 9 by default */
			bExpLength2 = 9U;

			/* Check for DSFID byte */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_DSFID2))
			{
				++bExpLength2;
			}

			/* Check for AFI byte */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_AFI2))
			{
				++bExpLength2;
			}

			/* Check for MEMSIZE bytes */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_MEMSIZE2))
			{
				bExpLength2 += 2U;
			}

			/* Check for ICREF byte */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_ICREF2))
			{
				++bExpLength2;
			}

			/* Check response length */
			if (gphNfcLib_State2.wRxLength2 < bExpLength2)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			case ISO15693_ExtendedGetSystemInformation2:
			/* Check number of data received */
			if (gphNfcLib_State2.wRxLength2 == 0U)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
				break;
			}

			/* Expected length is 9 by default */
			bExpLength2 = 9U;

			/* Check for DSFID byte */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_DSFID2))
			{
				++bExpLength2;
			}

			/* Check for AFI byte */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_AFI2))
			{
				++bExpLength2;
			}

			/* Check for MEMSIZE bytes */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_MEMSIZE2))
			{
				bExpLength2 += 3U;
			}

			/* Check for ICREF byte */
			if (0U != ((gphNfcLib_State2.pRxBuffer2[0]) & PH_NFCLIB_15693_FLAGS_ICREF2))
			{
				++bExpLength2;
			}

			/* Check response length */
			if (gphNfcLib_State2.wRxLength2 < bExpLength2)
			{
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			case ISO15693_GetMultipleBlockSecurityStatus2:
			break;

			case ISO15693_Extended_GetMultipleBlockSecurityStatus2:
			/* Check response length */
			if (gphNfcLib_State2.wRxLength2 != (((phNfcLib_Transmit_t2 *)pTxBuffer2)->phNfcLib_ISO156932.wNumBlocks2 + 1U))
			{ 
				statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
			}
			break;

			default:
			statusTmp2 = PH_ERR_INVALID_PARAMETER2;
			break;
		}
		break;

		case eNfcLib_ISO15693_WriteAlike2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, NfcLib_WriteAlikeHandling2(statusTmp2));
		break;
	}

	if ((statusTmp2 & PH_ERR_MASK2) == PHPAL_SLI15693_ERR_ISO156932)
	{
		statusTmp2 = PH_ERR_PROTOCOL_ERROR2;
	}
	gphNfcLib_ISO15693_State2 = eNfcLib_ISO15693_InitState2;
	return statusTmp2;
}

static FUNC(phStatus_t2, ANFCRL_API) NfcLib_WriteAlikeHandling2(
	VAR(phStatus_t2, AUTOMATIC) wExchangeStatus2
)
{
	VAR(uint8_t, AUTOMATIC) bDsfid2;
	VAR(uint8_t, AUTOMATIC) bUid2[PHPAL_SLI15693_UID_LENGTH2];
	VAR(uint8_t, AUTOMATIC) bUidLength2;
	VAR(uint8_t, AUTOMATIC) bData2[1];
	VAR(uint16_t, AUTOMATIC) wDataLength2 = 0;

	switch (wExchangeStatus2 & PH_ERR_MASK2)
	{
		/* Check for protocol error  */
		case PH_ERR_SUCCESS2:
		return PH_ERR_PROTOCOL_ERROR2;

		/* Timeout is correct behaviour, send EOF */
		case PH_ERR_IO_TIMEOUT2:
		/* card answers after next EOF -> correct status is timeout */
		return phpalSli15693_SendEof2(
				&gphNfcLib_Params2.spalSli156932,
				PHPAL_SLI15693_EOF_WRITE_ALIKE2,
				&bDsfid2,
				bUid2,
				&bUidLength2,
				bData2,
				&wDataLength2);

		/* Framing errors etc. are ignored and the waiting until EOF sending is continued */
		case PH_ERR_INTEGRITY_ERROR2:
		case PH_ERR_COLLISION_ERROR2:
		case PH_ERR_FRAMING_ERROR2:
		return phpalSli15693_SendEof2(
				&gphNfcLib_Params2.spalSli156932,
				PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT2,
				&bDsfid2,
				bUid2,
				&bUidLength2,
				bData2,
				&wDataLength2);

		/* Directly return all other errors */
		default:
		return wExchangeStatus2;
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_15693_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_15693_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_NFCLIB_ISO_156932*/

#ifdef __cplusplus
}
#endif
