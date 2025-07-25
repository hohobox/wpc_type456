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
*   @file    phalICode_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR phalICode_Int - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalICode ICode
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
#include <ph_RefDefs.h>
#include <phpalSli15693.h>
#include <phalICode.h>
#include <phTools.h>
#include "phalICode_Int.h"
#ifdef NXPBUILD__PH_CRYPTOSYM
#include <phKeyStore.h>
#include <phCryptoSym.h>
#include <phCryptoRng.h>
#endif /* NXPBUILD__PH_CRYPTOSYM */

#ifdef NXPBUILD__PHAL_ICODE
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalICode_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALICODE_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALICODE_INT_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHALICODE_INT_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHALICODE_INT_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHALICODE_INT_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHALICODE_INT_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHALICODE_INT_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalICode_Int.h header file are of the same vendor */
#if (PHALICODE_INT_VENDOR_ID_C != PHALICODE_INT_VENDOR_ID)
    #error "phalICode_Int.c and phalICode_Int.h have different vendor ids"
#endif
/* Check if current file and phalICode_Int.h header file are of the same Autosar version */
#if ((PHALICODE_INT_AR_RELEASE_MAJOR_VERSION_C    != PHALICODE_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHALICODE_INT_AR_RELEASE_MINOR_VERSION_C    != PHALICODE_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHALICODE_INT_AR_RELEASE_REVISION_VERSION_C != PHALICODE_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalICode_Int.c and phalICode_Int.h are different"
#endif
/* Check if current file and phalICode_Int.h header file are of the same Software version */
#if ((PHALICODE_INT_SW_MAJOR_VERSION_C != PHALICODE_INT_SW_MAJOR_VERSION) || \
     (PHALICODE_INT_SW_MINOR_VERSION_C != PHALICODE_INT_SW_MINOR_VERSION) || \
     (PHALICODE_INT_SW_PATCH_VERSION_C != PHALICODE_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalICode_Int.c and phalICode_Int.h are different"
#endif
#endif /* NXPBUILD__PHAL_ICODE */
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
#ifdef NXPBUILD__PHAL_ICODE
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHALICODE_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALICODE_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) gbBeginMultiBlocksRead = 0U;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHALICODE_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALICODE_INT_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHALICODE_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALICODE_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
 * Updates the Option value to the Flag's information byte. This is the 7th bit (as per ISO15693 notation) of
 * the Flag byte.
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : The option value to update.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF
 *                                  0x01:   PHAL_ICODE_OPTION_ON
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_SetOptionBit(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurFlag = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNewFlag = 0;

	/* Check if the Option Byte has a valid value. */
	if (bOption > PHAL_ICODE_OPTION_ON) {
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
	}

	/* Retrieve the flags byte */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phpalSli15693_GetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_FLAGS, &wCurFlag));

	/* Update Option bit with provided information. */
	if (bOption != PHAL_ICODE_OPTION_OFF) {
		wNewFlag = wCurFlag | PHPAL_SLI15693_FLAG_OPTION;
	}
	/* Clear option bit */
	else {
		wNewFlag = wCurFlag & (uint8) ~(uint8) PHPAL_SLI15693_FLAG_OPTION;
	}

	/* Update the Option bit in the Flag's byte. */
	if (wNewFlag != wCurFlag) {
		PH_CHECK_SUCCESS_FCT(wStatus,
				phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_FLAGS, wNewFlag));
	}

	return PH_ERR_SUCCESS;
}

/**
 * Sends an EOF information to the VICC based on the status received from the command being exchanged.
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      wExchangeStatus         : The status received from the last command exchange.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WriteAlikeHandling(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(phStatus_t, ANFCRL_VAR) wExchangeStatus) {
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDsfid = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUid[PHPAL_SLI15693_UID_LENGTH];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidLen = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aData[1];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen = 0;

	switch (wExchangeStatus & PH_ERR_MASK) {
	/* Check for protocol error.  */
	case PH_ERR_SUCCESS:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_ICODE);

		/* Timeout is correct behaviour, send EOF. */
	case PH_ERR_IO_TIMEOUT:
		/* card answers after next EOF -> correct status is timeout */
		return phpalSli15693_SendEof(pPalSli15693DataParams,
		PHPAL_SLI15693_EOF_WRITE_ALIKE, &bDsfid, bUid, &bUidLen, aData,
				&wDataLen);

		/* Framing errors etc. are ignored and the waiting until EOF sending is continued. */
	case PH_ERR_INTEGRITY_ERROR:
	case PH_ERR_COLLISION_ERROR:
	case PH_ERR_FRAMING_ERROR:
		return phpalSli15693_SendEof(pPalSli15693DataParams,
		PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT, &bDsfid, bUid, &bUidLen,
				aData, &wDataLen);

		/* Directly return all other errors */
	default:
		return wExchangeStatus;
	}
}

/**
 * Computes the custom error code for the ISO15693 specific error codes.
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      wStatus                 : The status of Pal exchange.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ComputeErrorCode(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(phStatus_t, ANFCRL_VAR) wStatus) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatusTmp = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wValue = 0;

	/* Update the temporary status variable. */
	wStatusTmp = wStatus;

	/*  Compute the custom error codes in case PAL returns an error. */
	if ((wStatus & PH_ERR_MASK) == PHPAL_SLI15693_ERR_ISO15693) {
		/* Get the error code from additional info. */
		PH_CHECK_SUCCESS_FCT(wStatusTmp,
				phpalSli15693_GetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_ADD_INFO, &wValue));

		/* Compute the custom code. */
		if ((wValue >= 0xA0U) && (wValue <= 0xDFU)) {
			/* Error mapping for error codes returned by Custom commands. */
			wStatusTmp = PHAL_ICODE_ERR_CUSTOM_COMMANDS_ERROR;
		}
		else
		{
			switch (wValue) {
			case PHAL_ICODE_RESP_ERR_COMMAND_NOT_SUPPORTED:
				wStatusTmp = PHAL_ICODE_ERR_COMMAND_NOT_SUPPORTED;
				break;
			case PHAL_ICODE_RESP_ERR_COMMAND_NOT_RECOGNIZED:
				wStatusTmp = PHAL_ICODE_ERR_COMMAND_NOT_RECOGNIZED;
				break;
			case PHAL_ICODE_RESP_ERR_COMMAND_OPTION_NOT_SUPPORTED:
				wStatusTmp = PHAL_ICODE_ERR_COMMAND_OPTION_NOT_SUPPORTED;
				break;
			case PHAL_ICODE_RESP_ERR_NO_INFORMATION:
				wStatusTmp = PHAL_ICODE_ERR_NO_INFORMATION;
				break;
			case PHAL_ICODE_RESP_ERR_BLOCK_NOT_AVAILABLE:
				wStatusTmp = PHAL_ICODE_ERR_BLOCK_NOT_AVAILABLE;
				break;
			case PHAL_ICODE_RESP_ERR_BLOCK_LOCKED:
				wStatusTmp = PHAL_ICODE_ERR_BLOCK_LOCKED;
				break;
			case PHAL_ICODE_RESP_ERR_CONTENT_CHANGE_FAILURE:
				wStatusTmp = PHAL_ICODE_ERR_CONTENT_CHANGE_FAILURE;
				break;
			case PHAL_ICODE_RESP_ERR_BLOCK_PROGRAMMING_FAILURE:
				wStatusTmp = PHAL_ICODE_ERR_BLOCK_PROGRAMMING_FAILURE;
				break;
			case PHAL_ICODE_RESP_ERR_BLOCK_NOT_LOCKED:
				wStatusTmp = PHAL_ICODE_ERR_BLOCK_NOT_LOCKED;
				break;
			case PHAL_ICODE_RESP_ERR_BLOCK_PROTECTED:
				wStatusTmp = PHAL_ICODE_ERR_BLOCK_PROTECTED;
				break;
			case PHAL_ICODE_RESP_ERR_GENERIC_CRYPTO_ERROR:
				wStatusTmp = PHAL_ICODE_ERR_GENERIC_CRYPTO_ERROR;
				break;

			default:
				wStatusTmp = PH_ERR_PROTOCOL_ERROR;
				break;
			}
		}

		/* Merge the status code with component code. */
		wStatusTmp = PH_ADD_COMPCODE(wStatusTmp, PH_COMP_AL_ICODE);
	}

	return wStatusTmp;
}

/**
 * Reverses the byte buffer.
 *
 * Input Parameters:
 *      pData                   : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      wLength                 : The length of bytes available in pData buffer.
 */
FUNC(void, ANFCRL_CODE) phalICode_Int_Reverse(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wLength) {
  VAR(uint8, ANFCRL_VAR) bTemp;

  VAR(uint8, ANFCRL_VAR) bLSB = 0;
  VAR(uint8, ANFCRL_VAR) bMSB = (uint8) (wLength - 1u);

	while (bLSB <= bMSB) {
		bTemp = pData[bLSB];
		pData[bLSB] = pData[bMSB];
		pData[bMSB] = bTemp;

		bLSB++;
		bMSB--;
	}
}

/*
 * Performs the reading data or status of multiple blocks.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bCmdCode                : Command code for the flavours of Multiple Block Read.
 *                                  0x23:   PHAL_ICODE_CMD_READ_MULTIPLE_BLOCKS
 *                                  0x2C:   PHAL_ICODE_CMD_GET_MULTIPLE_BLOCK_SECURITY_STATUS
 *                                  0x2D:   PHAL_ICODE_CMD_FAST_READ_MULTIPLE_BLOCKS
 *                                  0x33:   PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS
 *                                  0x3C:   PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS
 *                                  0x3D:   PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS
 *                                  0xB8:   PHAL_ICODE_CMD_GET_MULTIPLE_BLOCK_PROTECTION_STATUS
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available.)
 *      wBlockNo                : Block number from where the data to be read.
 *      wNumBlocks              : Total number of block to read.
 *
 * Output Parameters:
 *      pData                   : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ReadBlocks(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bCmdCode, VAR(uint8, ANFCRL_VAR) bEnableBuffering, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint16, ANFCRL_VAR) wBlockNo, VAR(uint16, ANFCRL_VAR) wNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[5] = {0};
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bcmdLen = 0;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0;

	/* This flag enables buffering of response data received from ICode tags. This is purely for applications that run on desktop.
	 * This flag by default be placed in preprocessor sections. Additionally the application has to enable a flag bEnableBuffering
	 * to make this chaining work.
	 *
	 * To disable this flag remove this macro from ProjectProperties-> C/C++ -> Preprocessor -> Preprocessor Definitions for both
	 * DEBUG and RELEASE configurations.
	 */
#ifdef PHAL_ICODE_ENABLE_CHAINING
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrBlocksToRead = 0;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrBlockNo = 0;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wMaxNoBlocks = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bAllBlocksRead = 0;
#endif /* PHAL_ICODE_ENABLE_CHAINING */

	wStatus = phhalHw_Exchange_GetStatus();
	if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
	{
		/* Set or clear the flags option bit indicated by bOption. */
		if (gbBeginMultiBlocksRead == 0U) {
			PH_CHECK_SUCCESS_FCT(wStatus,
					phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
			/* Reset command buffer and its length variable. */
			bcmdLen = 0;
			(void) memset(aCmdBuff, 0x00, (size_t) sizeof(aCmdBuff));
			/* Frame the initial command. */
			aCmdBuff[bcmdLen++] = bCmdCode;
			*pDataLen = 0U;
		}
#ifdef PHAL_ICODE_ENABLE_CHAINING
		/* Buffer the response data if Buffering flag is set. */
		if(0U != (bEnableBuffering))
		{
			/* Update the maximum number of blocks with respect to Option flag setting. The value for the blocks is fixed to 60 and 40 to avoid multiple
			* handling of different data in response. RD70x can respond with more amount of data but CM1 can not. So fixing the blocks count to a lower
			* value.
			*/
			if(gbBeginMultiBlocksRead == 0U)
			{
				wCurrBlocksToRead = 0U;
				wCurrBlockNo = 0U;
				wMaxNoBlocks = 0U;
				bAllBlocksRead = 0U;
				wMaxNoBlocks = (uint8) ((bOption != 0U) ? PHAL_ICODE_MAX_BLOCKS_CM1_OPTION_FLAG_SET : PHAL_ICODE_MAX_BLOCKS_CM1_OPTION_FLAG_NOT_SET);

				/* Blocks to read. */
				wCurrBlocksToRead = wMaxNoBlocks;

				/* Update the number of blocks to read if its less than the internal required one. */
				if(wNumBlocks < wMaxNoBlocks)
				{
					wCurrBlocksToRead = wNumBlocks;
					bAllBlocksRead = 1;
				}
			}
			/* Read the blocks. */
			/* Frame command information. */
			aCmdBuff[bcmdLen++] = (uint8) ((wCurrBlockNo + wBlockNo) & 0x00FFU);

			/* Add the next byte of block number for extended commands. */
			if((bCmdCode == PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS) || (bCmdCode == PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS) ||
					(bCmdCode == PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS))
			{
				aCmdBuff[bcmdLen++] = (uint8) (((wCurrBlockNo + wBlockNo) & 0xFF00U) >> 8U);
			}

			/* Adjust number of blocks. Adjustment is made because the User or the application will pass
			 * the number of blocks starting from 1 to N. But as per Iso15693 specification the number
			 * of blocks ranges from 0 - (N - 1).
			 */
			--wCurrBlocksToRead;

			/* Add number of blocks. */
			aCmdBuff[bcmdLen++] = (uint8) (wCurrBlocksToRead & 0x00FFU);

			/* Add the next byte of number of blocks for extended commands. */
			if((bCmdCode == PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS) || (bCmdCode == PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS) ||
					(bCmdCode == PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS))
			{
				aCmdBuff[bcmdLen++] = (uint8) ((wCurrBlocksToRead & 0xFF00U) >> 8U);
			}
		}
		else
#endif /* PHAL_ICODE_ENABLE_CHAINING */
		{
      /* To avoid build failures. */
			(void) bEnableBuffering;
			/* Adjust number of blocks. Adjustment is made because the User or the application will pass
			 * the number of blocks starting from 1 to N. But as per Iso15693 specification the number
			 * of blocks ranges from 0 - (N - 1).
			 */
			--wNumBlocks;

			/* Frame ReadMultipleBlock command information. */
			aCmdBuff[bcmdLen++] = (uint8) (wBlockNo & 0x00FFU);

			/* Add the next byte of block number for extended commands. */
			if ((bCmdCode == PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS)
					|| (bCmdCode
							== PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS)
					|| (bCmdCode
							== PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS)) {
				aCmdBuff[bcmdLen++] = (uint8) ((wBlockNo & 0xFF00U) >> 8U);
			}

			/* Add number of blocks. */
			aCmdBuff[bcmdLen++] = (uint8) (wNumBlocks & 0x00FFU);

			/* Add the next byte of number of blocks for extended commands. */
			if ((bCmdCode == PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS)
					|| (bCmdCode
							== PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS)
					|| (bCmdCode
							== PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS)) {
				aCmdBuff[bcmdLen++] = (uint8) ((wNumBlocks & 0xFF00U) >> 8U);
			}
		}
		gbBeginMultiBlocksRead = 1U;
	}
	/* Exchange the command information to PAL layer. */
	wStatus = phpalSli15693_Exchange(pPalSli15693DataParams,
	PH_EXCHANGE_DEFAULT, aCmdBuff, bcmdLen, &pResponse, &wRespLen);
	if (PH_STATUS_INPROCESS == wStatus) {
		return wStatus;
	}

	if (wStatus != 0U) {
		gbBeginMultiBlocksRead = 0;
		return phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
	}
#ifdef PHAL_ICODE_ENABLE_CHAINING
	if(0U != (bEnableBuffering))
	{
		/* Copy the received data to internal buffer. */
		if(wRespLen != 0U)
		{
			(void)phTools_memcpy(&pData[*pDataLen], pResponse, wRespLen);
		}
		*pDataLen += wRespLen;

		/* Update the variables to read the remaining data. */
		wCurrBlockNo += wMaxNoBlocks;

		/* Update the Current blocks to read. */
		wCurrBlocksToRead = wMaxNoBlocks;

		/* Reset the command buffer length. */
		bcmdLen = 1;

		/* Set the remaining blocks to read. */
		if((wNumBlocks - wCurrBlockNo) < wMaxNoBlocks)
		{
			wCurrBlocksToRead = (uint16) (wNumBlocks - wCurrBlockNo);
		}

		/* Set the flag to finish the loop. */
		switch(bCmdCode)
		{
			case PHAL_ICODE_CMD_READ_MULTIPLE_BLOCKS:
			case PHAL_ICODE_CMD_FAST_READ_MULTIPLE_BLOCKS:
			case PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS:
			case PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS:
			if((!(bOption > 0U) && ((wNumBlocks * 4U) == *pDataLen)) || ((bOption > 0U) && (((wNumBlocks * 4U) + wNumBlocks) == *pDataLen)))
			{
				bAllBlocksRead = 1U;
			}
			break;

			case PHAL_ICODE_CMD_GET_MULTIPLE_BLOCK_SECURITY_STATUS:
			case PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS:
			case PHAL_ICODE_CMD_GET_MULTIPLE_BLOCK_PROTECTION_STATUS:
			if(wNumBlocks == *pDataLen)
			{
				bAllBlocksRead = 1U;
			}
			break;
		}
		if(bAllBlocksRead == 0U)
		{
			return PH_STATUS_INPROCESS;
		}
	}
	else
#endif
	{
		/* Copy the received data to internal buffer. */
		(void) phTools_memcpy(pData, pResponse, wRespLen);
		*pDataLen = wRespLen;
	}
	gbBeginMultiBlocksRead = 0U;
	/* Compute the status code. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus));
	return PH_ERR_SUCCESS;
}

/*
 * Performs a Single block read command. When receiving the Read Single Block command, the VICC shall read the requested block and send
 * back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      bBlockNo                : Block number from where the data to be read.
 *
 * Output Parameters:
 *      ppData                  : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ReadSingleBlock(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[2] = {0U};

    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

    switch(pDataParams->bAlICodeStateMachineState)
    {
        case 0:
            wStatus = phhalHw_Exchange_GetStatus();
            if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
                /* Frame ReadSingleBlock command information. */
                aCmdBuff[0] = PHAL_ICODE_CMD_READ_SINGLE_BLOCK;
                aCmdBuff[1] = bBlockNo;

                /* Set or clear the flags option bit indicated by bOption. */
                PH_CHECK_FAILURE_FCT(wStatus,
                        phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
                pDataParams->bAlICodeStateMachineState = 1U;
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 2U;
            }
            return PH_STATUS_INPROCESS;
        case 1:
            /* Set short timeout. */
            PH_CHECK_INPROCESS_FCT(wStatus,
            phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
            PH_BREAK_ON_FAILURE(wStatus);
            pDataParams->bAlICodeStateMachineState = 2U;
            /* no break */
        case 2:
            /* Exchange the command information to PAL layer. */
            PH_CHECK_INPROCESS_FCT(wStatus,phpalSli15693_Exchange(pPalSli15693DataParams,
                        PH_EXCHANGE_DEFAULT, aCmdBuff, 2U, ppData, pDataLen));
            PH_BREAK_ON_FAILURE(wStatus);
            pDataParams->bAlICodeStateMachineState = 3U;
            /* no break */
        case 3:
            /* Compute the status code. */
            wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
            break;
    }
    aCmdBuff[0] = 0U;
    aCmdBuff[1] = 0U;
    pDataParams->bAlICodeStateMachineState = 0U;
    return wStatus;
}

/*
 * Performs a Single block write command. When receiving the Write single block command, the VICC shall write the requested block with the
 * data contained in the request and report the success of the operation in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON)
 * is set in the request, the VICC shall wait for the reception of an EOF from the VCD and upon such reception shall return its response.
 * If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its response when it has completed the write operation starting
 * after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon
 * detection of the rising edge of the EOF of the VCD request. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *      bBlockNo                : Block number to which the data should be written.
 *      pData                   : Information to be written to the specified block number.
 *      bDataLen                : Number of bytes to be written.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WriteSingleBlock(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint8, ANFCRL_VAR) bDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[2] = {0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

  switch(pDataParams->bAlICodeStateMachineState)
  {
      case 0U:
            wStatus = phhalHw_Exchange_GetStatus();
            if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
                /* Frame WriteSingleBlock command. */
                aCmdBuff[0] = PHAL_ICODE_CMD_WRITE_SINGLE_BLOCK;
                aCmdBuff[1] = bBlockNo;

                /* Set or clear the flags option bit indicated by bOption. */
                PH_CHECK_FAILURE_FCT(wStatus,
                        phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
                pDataParams->bAlICodeStateMachineState = 1U;
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 4U;
                return PH_STATUS_INPROCESS;
            }
            /* no break*/
      case 1U:
                /* Set long timeout. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig( pPalSli15693DataParams,
                                PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 2U;
                /* no break */
      case 2U:
                /* Buffer the command information to exchange buffer. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange( pPalSli15693DataParams,
                        PH_EXCHANGE_BUFFER_FIRST, aCmdBuff, 2U, NULL, NULL));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 3U;
                /* no break */
      case 3U:
                /* Buffer the data to exchange buffer and exchange the buffered information to PAL layer. */
                PH_CHECK_INPROCESS_FCT(wStatus,phpalSli15693_Exchange(pPalSli15693DataParams,
                        PH_EXCHANGE_BUFFER_LAST, pData, bDataLen, &pResponse, &wRespLen));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 4U;
                /* no break */
      case 4U:
            PH_CHECK_INPROCESS_FCT(wStatus,phpalSli15693_Exchange(pPalSli15693DataParams,
                    PH_EXCHANGE_DEFAULT, pData, bDataLen, &pResponse, &wRespLen));
            PH_BREAK_ON_FAILURE(wStatus);
            /* Write-alike handling */
            if (0U != (bOption))
            {
                pDataParams->bAlICodeStateMachineState = 5U;
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 6U;
                return PH_STATUS_INPROCESS;
            }
            /* no break */
      case 5U:
           PH_CHECK_INPROCESS_FCT(wStatus,phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
           PH_BREAK_ON_FAILURE(wStatus);
           pDataParams->bAlICodeStateMachineState = 6U;
           /* no break */
      case 6U:
          /* Compute the status code. */
          wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
          break;

  }
  pDataParams->bAlICodeStateMachineState = 0U;
  aCmdBuff[0] = 0U;
  aCmdBuff[1] = 0U;
  return wStatus;
}

/*
 * Performs a Lock block command. When receiving the Lock block command, the VICC shall lock permanently the requested block. If the
 * Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the VCD
 * and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 * (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *      bBlockNo                : Block number which should be locked.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_LockBlock(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[2] = {0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

    switch(pDataParams->bAlICodeStateMachineState)
    {
        case 0U:
                wStatus = phhalHw_Exchange_GetStatus();
                if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
                    /* Frame LockBlock command information. */
                    aCmdBuff[0] = PHAL_ICODE_CMD_LOCK_BLOCK;
                    aCmdBuff[1] = bBlockNo;

                    /* Set or clear the flags option bit indicated by bOption. */
                    PH_CHECK_FAILURE_FCT(wStatus,
                            phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
                    pDataParams->bAlICodeStateMachineState = 1U;
                }
                else
                {
                    pDataParams->bAlICodeStateMachineState = 2U;
                    return PH_STATUS_INPROCESS;
                }
                /* no break */
        case 1U:
                /* Set long timeout. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig( pPalSli15693DataParams,
                        PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 2U;
                /* no break */
        case 2U:
                /* Exchange the command information to PAL layer. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
                        PH_EXCHANGE_DEFAULT, aCmdBuff, 2U, &pResponse, &wRespLen));
				PH_BREAK_ON_FAILURE(wStatus);

                /* Write-alike handling */
                if (0U != (bOption))
                {
                    pDataParams->bAlICodeStateMachineState = 3U;
                }
                else
                {
                    pDataParams->bAlICodeStateMachineState = 4U;
                    return PH_STATUS_INPROCESS;
                }
                /* no break */
        case 3U:
                PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
				PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 5U;
                /* no break */
        case 4U:
                /* Compute the status code. */
                wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
                break;

    }
    pDataParams->bAlICodeStateMachineState = 0U;
    aCmdBuff[0] = 0U;
    aCmdBuff[1] = 0U;
	return wStatus;
}

/*
 * Performs a Multiple block read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s) and send
 * back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall
 * return only the block value. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      bBlockNo                : Block number from where the data to be read.
 *      bNumBlocks              : Total number of block to read.
 *
 * Output Parameters:
 *      pData                   : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ReadMultipleBlocks(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bEnableBuffering, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

  switch(pDataParams->bAlICodeStateMachineState)
  {
      case 0U:
            wStatus = phhalHw_Exchange_GetStatus();
            if ((gbBeginMultiBlocksRead == 0U)
                    && ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))) {
                /* Number of bNumBlocks can't be zero */
                if (bNumBlocks == 0U) {
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER,
                            PH_COMP_AL_ICODE);
                }

                /* Check number of blocks doesn't exceed 256. */
                if (((uint16) bBlockNo + bNumBlocks) > PHAL_ICODE_MAX_BLOCKS) {
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER,
                            PH_COMP_AL_ICODE);
                }

                /* Set short timeout. */
                PH_CHECK_INPROCESS_FCT(wStatus,
                        phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 1U;
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 1U;
            }
            /* no break */
      case 1U:
          /* Read the blocks. */
          PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_ReadBlocks( pPalSli15693DataParams,
          PHAL_ICODE_CMD_READ_MULTIPLE_BLOCKS, bEnableBuffering, bOption, bBlockNo, bNumBlocks, pData, pDataLen));
          break;

  }
  pDataParams->bAlICodeStateMachineState = 0U;
  return wStatus;
}

/*
 * Performs a WriteAFI command. When receiving the Write AFI request, the VICC shall write the  AFI value into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF
 * from the VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return its response when it has completed the write operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a
 * multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the
 * EOF of the VCD request.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *      bAfi                    : Value of Application Family Identifier.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WriteAFI(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bAfi) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuf[2];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;


  switch(pDataParams->bAlICodeStateMachineState)
  {
      case 0U:
            wStatus = phhalHw_Exchange_GetStatus();
            if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {

                /* Frame WriteAFI command information. */
                aCmdBuf[0] = PHAL_ICODE_CMD_WRITE_AFI;
                aCmdBuf[1] = bAfi;

                /* Set or clear the flags option bit indicated by bOption. */
                PH_CHECK_FAILURE_FCT(wStatus,
                        phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 2U;
                return PH_STATUS_INPROCESS;
            }
            /* no break */
      case 1U:
            /* Set long timeout. */
            PH_CHECK_INPROCESS_FCT(wStatus,
                  phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
            PH_BREAK_ON_FAILURE(wStatus);
            pDataParams->bAlICodeStateMachineState = 2U;
            /* no break */
      case 2U:
            /* Exchange the command information to PAL layer. */
            PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
                      PH_EXCHANGE_DEFAULT, aCmdBuf, 2, &pResponse, &wRespLen));
            PH_BREAK_ON_FAILURE(wStatus);

            /* Write-alike handling */
            if (0U != (bOption))
            {

                pDataParams->bAlICodeStateMachineState = 3U;
            }
            else
            {

                pDataParams->bAlICodeStateMachineState = 4U;
                return PH_STATUS_INPROCESS;
            }
            /* no break */
      case 3U:
            PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams,
                  wStatus));
            PH_BREAK_ON_FAILURE(wStatus);
            pDataParams->bAlICodeStateMachineState = 4U;
            /* no break */
      case 4U:
            /* Compute the status code. */
            wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);

  }
  aCmdBuf[0] = 0U;
  aCmdBuf[1] = 0U;
  pDataParams->bAlICodeStateMachineState = 0U;
  return wStatus;
}

/*
 * Performs a LockAFI command. When receiving the Lock AFI request, the VICC shall lock the AFI value permanently into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF
 * from the VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return its response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a
 * multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the
 * EOF of the VCD request.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_LockAFI(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams, VAR(uint8, ANFCRL_VAR) bOption) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

  switch(pDataParams->bAlICodeStateMachineState)
  {
          case 0U:
                wStatus = phhalHw_Exchange_GetStatus();
                if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {

                    /* Frame LockAFI command information. */
                    aCmdBuff[0] = PHAL_ICODE_CMD_LOCK_AFI;

                    /* Set or clear the flags option bit indicated by bOption. */
                    PH_CHECK_FAILURE_FCT(wStatus,
                            phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
                    pDataParams->bAlICodeStateMachineState = 1U;
                }
                else
                {
                    pDataParams->bAlICodeStateMachineState = 2U;
                    return PH_STATUS_INPROCESS;
                }
                /* no break */
          case 1U:
                /* Set long timeout. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig( pPalSli15693DataParams,
                      PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 2U;
                /* no break */
          case 2U:
                /* Exchange the command information to PAL layer. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
                          PH_EXCHANGE_DEFAULT, aCmdBuff, 1, &pResponse, &wRespLen));
                PH_BREAK_ON_FAILURE(wStatus);

                /* Write-alike handling */
                if (0U != (bOption))
                {
                    pDataParams->bAlICodeStateMachineState = 3U;
                }
                else
                {
                    pDataParams->bAlICodeStateMachineState = 4U;
                    return PH_STATUS_INPROCESS;
                }
                /* no break */
          case 3U:
                PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 4U;
                /* no break */
          case 4U:
                /* Compute the status code. */
                wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
                break;

  }
  aCmdBuff[0] = 0U;
  pDataParams->bAlICodeStateMachineState = 0U;
  return wStatus;
}

/*
 * Performs WriteDSFID command. When receiving the Write DSFID request, the VICC shall write the DSFID value into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF
 * from the VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return its response when it has completed the write operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a
 * multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the
 * EOF of the VCD request. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *      bDsfid          : Value of DSFID (data storage format identifier).
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WriteDSFID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bDsfid) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuf[2];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

  switch(pDataParams->bAlICodeStateMachineState)
  {
        case 0U:
            wStatus = phhalHw_Exchange_GetStatus();
            if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
                /* Frame WriteDSFID command information. */
                aCmdBuf[0] = PHAL_ICODE_CMD_WRITE_DSFID;
                aCmdBuf[1] = bDsfid;

                /* Set or clear the flags option bit indicated by bOption. */
                PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
                pDataParams->bAlICodeStateMachineState = 1U;
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 2U;
                return PH_STATUS_INPROCESS;
            }
            /* no break */
        case 1U:
            /* Set long timeout. */
            PH_CHECK_INPROCESS_FCT(wStatus,
                    phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
            PH_BREAK_ON_FAILURE(wStatus);
            pDataParams->bAlICodeStateMachineState = 2U;
            /* no break */
        case 2U:
            /* Exchange the command information to PAL layer. */
            PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
                                PH_EXCHANGE_DEFAULT, aCmdBuf, 2U, &pResponse, &wRespLen));
            PH_BREAK_ON_FAILURE(wStatus);

            /* Write-alike handling */
            if (0U != (bOption))
            {
                pDataParams->bAlICodeStateMachineState = 3U;
            }
            else
            {
                pDataParams->bAlICodeStateMachineState = 4U;
                return PH_STATUS_INPROCESS;
            }
            /* no break */
        case 3U:
            PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
            PH_BREAK_ON_FAILURE(wStatus);
            pDataParams->bAlICodeStateMachineState = 4U;
            /* no break */
        case 4U:
            /* Compute the status code. */
            wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
            break;

  }
  aCmdBuf[0] = 0U;
  aCmdBuf[1] = 0U;
  pDataParams->bAlICodeStateMachineState = 0U;
  return wStatus;
}

/*
 * Performs LockDSFID command. When receiving the Lock DSFID request, the VICC shall lock the DSFID value permanently into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us)
 * with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_LockDSFID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

  switch(pDataParams->bAlICodeStateMachineState)
  {
          case 0U:
                wStatus = phhalHw_Exchange_GetStatus();
                if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
                    /* Frame LockDSFID command information. */
                    aCmdBuff[0] = PHAL_ICODE_CMD_LOCK_DSFID;

                    /* Set or clear the flags option bit indicated by bOption. */
                    PH_CHECK_FAILURE_FCT(wStatus,
                            phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
                    pDataParams->bAlICodeStateMachineState = 1U;
                }
                else
                {
                    pDataParams->bAlICodeStateMachineState = 2U;
                    return PH_STATUS_INPROCESS;
                }
                /* no break */
          case 1U:
                /* Set long timeout. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig( pPalSli15693DataParams,
                        PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 2U;
                /* no break */
          case 2U:
                /* Exchange the command information to PAL layer. */
                PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
                        PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
                PH_BREAK_ON_FAILURE(wStatus);

                /* Write-alike handling */
                if (0U != (bOption))
                {
                    pDataParams->bAlICodeStateMachineState = 3U;
                }
                else
                {
                    pDataParams->bAlICodeStateMachineState = 4U;
                    return PH_STATUS_INPROCESS;
                }
                /* no break */
          case 3U:
                PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
                PH_BREAK_ON_FAILURE(wStatus);
                pDataParams->bAlICodeStateMachineState = 4U;
                /* no break */
          case 4U:
                /* Compute the status code. */
                wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
                break;

  }
  aCmdBuff[0] = 0U;
  pDataParams->bAlICodeStateMachineState = 0U;
  return wStatus;
}

/*
 * Performs GetSystemInformation command. This command allows for retrieving the system information value from the VICC.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Output Parameters:
 *      ppSystemInfo            : The system information of the VICC.
 *      pSystemInfoLen          : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_GetSystemInformation(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
				/* Frame GetSystemInformation command information. */
				aCmdBuff[0] = PHAL_ICODE_CMD_GET_SYSTEM_INFORMATION;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus,phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, ppSystemInfo, pSystemInfoLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
          case 3U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * Performs GetMultipleBlockSecurityStatus. When receiving the Get multiple block security status command, the VICC
 * shall send back the block security status.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bBlockNo                : Block number for which the status should be returned.
 *      bNoOfBlocks             : Number of blocks to be used for returning the status.
 *
 * Output Parameters:
 *      pStatus                 : The status of the block number mentioned in bBlockNo until bNoOfBlocks.
 *      pStatusLen              : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_GetMultipleBlockSecurityStatus(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams, VAR(uint8, ANFCRL_VAR) bEnableBuffering,
    VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNoOfBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pStatus,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((gbBeginMultiBlocksRead == 0U) &&
				((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)))
			{
				/* Number of bNoOfBlocks can't be zero */
				if (bNoOfBlocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				/* Check number of blocks doesn't exceed 256 */
				if (((uint16) bBlockNo + bNoOfBlocks) > PHAL_ICODE_MAX_BLOCKS)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig(pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_ReadBlocks(pPalSli15693DataParams,
					PHAL_ICODE_CMD_GET_MULTIPLE_BLOCK_SECURITY_STATUS, bEnableBuffering,
					PHAL_ICODE_OPTION_OFF, bBlockNo, bNoOfBlocks, pStatus, pStatusLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
          case 3U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs a Multiple block fast read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s) and
 * send back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall
 * return only the block value. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      bBlockNo                : Block number from where the data to be read.
 *      bNumBlocks              : Total number of block to read.
 *
 * Output Parameters:
 *      pData                   : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_FastReadMultipleBlocks(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
VAR(uint8, ANFCRL_VAR) bEnableBuffering, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOldRxDataRate = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxDataRate = 0U;
	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((gbBeginMultiBlocksRead == 0U) &&
				((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)))
			{
				/* Number of bNumBlocks can't be zero */
				if (bNumBlocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				/* Check number of blocks doesn't exceed 255. */
				if (((uint16) bBlockNo + bNumBlocks) > PHAL_ICODE_MAX_BLOCKS)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);

			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Find out the already set baud rate */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_GetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_RXDATARATE, &wOldRxDataRate));
			PH_BREAK_ON_FAILURE(wStatus);

			/* Configuring the baud rate based on b2 and b8 value */
			if ((pDataParams->bFlags & PHAL_ICODE_FLAG_DATA_RATE) > 0U)
			{
				if ((pDataParams->bFlags & PHAL_ICODE_FLAG_FAST_DATA_RATE) != 0U)
				{
					wRxDataRate = PHPAL_SLI15693_106KBPS_DATARATE;
				}
				else
				{
					wRxDataRate = PHPAL_SLI15693_26KBPS_DATARATE;
				}
			}
			else
			{
				if ((pDataParams->bFlags & PHAL_ICODE_FLAG_FAST_DATA_RATE) != 0U)
				{
					wRxDataRate = PHPAL_SLI15693_53KBPS_DATARATE;
				}
				else
				{
					wRxDataRate = PHPAL_SLI15693_212KBPS_DATARATE;
				}
			}

			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
			/* Set the baud rate. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_RXDATARATE, wRxDataRate));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* no break */
		case 4U:
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_ReadBlocks(pPalSli15693DataParams,
					PHAL_ICODE_CMD_FAST_READ_MULTIPLE_BLOCKS, bEnableBuffering, bOption,
					bBlockNo, bNumBlocks, pData, pDataLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 5U;
			/* no break */
		case 5U:
			/* Set the old rx baud rate again . */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig(pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_RXDATARATE, wOldRxDataRate));
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	wOldRxDataRate = 0U;
	wRxDataRate = 0U;
	return wStatus;
}

/**
 * \brief Performs a Extended Single block read command. When receiving the Extended Read Single Block command, the VICC shall read the
 * requested block and send back its value in the response. If a VICC supports Extended read single block command, it shall also support
 * Read single block command for the first 256 blocks of memory. If the Option_flag (bOption = #PHAL_ICODE_OPTION_ON) is set in the request,
 * the VICC shall return the block security status, followed by the block value. If it is not set (bOption = #PHAL_ICODE_OPTION_OFF), the
 * VICC shall return only the block value. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      wBlockNo                : Block number from where the data to be read.
 *
 * Output Parameters:
 *      ppData                  : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedReadSingleBlock(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint16, ANFCRL_VAR) wBlockNo, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[3] = {0U};

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Frame ExtendedReadSingleBlock command information. */
				aCmdBuff[0] = PHAL_ICODE_CMD_EXTENDED_READ_SINGLE_BLOCK;
				aCmdBuff[1] = (uint8) (wBlockNo & 0x00FFU);
				aCmdBuff[2] = (uint8) ((wBlockNo & 0xFF00U) >> 8U);

				/* Set or clear the flags option bit indicated by bOption. */
				PH_CHECK_FAILURE_FCT(wStatus,
				phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 3U, ppData, pDataLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;   
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	return wStatus;
}

/**
 * \brief Performs a Extended Single block Write command. When receiving the Extended write single block command, the VICC shall write the
 * requested block with the data contained in the request and report the success of the operation in the response. If a VICC supports
 * Extended write single block command, it shall also support Write single block command for the first 256 blocks of memory.
 *
 * If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its response when it has completed the write operation starting
 * after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon
 * detection of the rising edge of the EOF of the VCD request. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      wBlockNo                : Block number to which the data should be written.
 *      pData                   : Information to be written to the specified block number.
 *      bDataLen                : Number of bytes to be written.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedWriteSingleBlock(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint16, ANFCRL_VAR) wBlockNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint8, ANFCRL_VAR) bDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[3] = {0};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Frame ExtendedWriteSingleBlock command. */
				aCmdBuff[0] = PHAL_ICODE_CMD_EXTENDED_WRITE_SINGLE_BLOCK;
				aCmdBuff[1] = (uint8) (wBlockNo & 0x00FFU);
				aCmdBuff[2] = (uint8) ((wBlockNo & 0xFF00U) >> 8U);

				/* Set or clear the flags option bit indicated by bOption. */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Buffer the command information to exchange buffer. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_Exchange( pPalSli15693DataParams, PH_EXCHANGE_BUFFER_FIRST, aCmdBuff, 3U, NULL, NULL));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
			/* Buffer the data to exchange buffer and exchange the buffered information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			PH_EXCHANGE_BUFFER_LAST, pData, bDataLen, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* no break */
		case 4U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, pData, bDataLen, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			/* Write-alike handling */
			if (0U != (bOption))
			{
				pDataParams->bAlICodeStateMachineState = 5U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 6U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 5U:
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 6U;
			/* no break */
		case 6U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	return wStatus;
}

/*
 * Performs a Extended Lock block command. When receiving the Lock block command, the VICC shall lock permanently the requested
 * block. If a VICC supports Extended lock block command, it shall also support Lock block command for the first 256 blocks of memory.
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 * (302 us) with a total tolerance of 32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                                 starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                                 (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                                 of the rising edge of the EOF of the VCD request.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                                shall return its response.)
 *      wBlockNo                : Block number which should be locked.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedLockBlock(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint16, ANFCRL_VAR) wBlockNo)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[3] = {0};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Frame ExtendedLockBlock command information. */
				aCmdBuff[0] = PHAL_ICODE_CMD_EXTENDED_LOCK_BLOCK;
				aCmdBuff[1] = (uint8) (wBlockNo & 0x00FFU);
				aCmdBuff[2] = (uint8) ((wBlockNo & 0xFF00U) >> 8U);

				/* Set or clear the flags option bit indicated by bOption. */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_Exchange(pPalSli15693DataParams, PH_EXCHANGE_DEFAULT, aCmdBuff, 3U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);

			/* Write-alike handling */
			if (0U != (bOption))
			{
				pDataParams->bAlICodeStateMachineState = 3U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 3U:
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* no break */
		case 4U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	return wStatus;
}

/*
 * Performs a Extended Multiple block read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s)
 * and send back its value in the response. If a VICC supports Extended read multiple blocks command, it shall also support Read multiple blocks
 * command for the first 256 blocks of memory.
 *
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block security status, followed by the block
 * value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      wBlockNo                : Block number from where the data to be read.
 *      wNumBlocks              : Total number of block to read.
 *
 * Output Parameters:
 *      pData                   : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedReadMultipleBlocks(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams, VAR(uint8, ANFCRL_VAR) bEnableBuffering,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint16, ANFCRL_VAR) wBlockNo, VAR(uint16, ANFCRL_VAR) wNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((gbBeginMultiBlocksRead == 0U) &&
				((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)))
			{
				/* Number of bNumBlocks can't be zero */
				if (wNumBlocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				/* Check number of blocks doesn't exceed 512. */
				if (((uint16) wBlockNo + wNumBlocks) > PHAL_ICODE_MAX_BLOCKS_EXTENDED)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Read the blocks. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ReadBlocks( pPalSli15693DataParams, PHAL_ICODE_CMD_EXTENDED_READ_MULTIPLE_BLOCKS, bEnableBuffering,
					bOption, wBlockNo, wNumBlocks, pData, pDataLen));
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs ExtendedGetSystemInformation command. This command allows for retrieving the system information value
 * from the VICC and shall be supported by the VICC if extended memory or security functionalities are supported
 * by the VICC. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bInfoParams             : Extend Get System Information parameter request fields.
 *                                  0x10: PHAL_ICODE_INFO_PARAMS_REQUEST_DEFAULT
 *                                  0x01: PHAL_ICODE_INFO_PARAMS_REQUEST_DSFID
 *                                  0x02: PHAL_ICODE_INFO_PARAMS_REQUEST_AFI
 *                                  0x04: PHAL_ICODE_INFO_PARAMS_REQUEST_VICC_MEM_SIZE
 *                                  0x08: PHAL_ICODE_INFO_PARAMS_REQUEST_IC_REFERENCE
 *                                  0x10: PHAL_ICODE_INFO_PARAMS_REQUEST_MOI
 *                                  0x20: PHAL_ICODE_INFO_PARAMS_REQUEST_COMMAND_LIST
 *                                  0x50: PHAL_ICODE_INFO_PARAMS_REQUEST_CSI_INFORMATION
 *                                  0x80: PHAL_ICODE_INFO_PARAMS_REQUEST_EXT_GET_SYS_INFO
 *
 * Output Parameters:
 *      ppSystemInfo            : The system information of the VICC.
 *      pSystemInfoLen          : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedGetSystemInformation(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams, VAR(uint8, ANFCRL_VAR) bInfoParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[2]= {0U};

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Frame ExtendedGetSystemInformation command information. */
				aCmdBuff[0] = PHAL_ICODE_CMD_EXTENDED_GET_SYSTEM_INFORMATION;
				aCmdBuff[1] = bInfoParams;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
				phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 2U, ppSystemInfo, pSystemInfoLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs ExtendedGetMultipleBlockSecurityStatus. When receiving the Extended Get multiple block security status
 * command, the VICC shall send back the block security status. The blocks are numbered from 0000 to FFFF (0 - 512).
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      wBlockNo                : Block number for which the status should be returned.
 *      wNoOfBlocks             : Number of blocks to be used for returning the status.
 *
 * Output Parameters:
 *      pStatus             : The status of the block number mentioned in wBlockNo until wNoOfBlocks.
 *      pStatusLen              : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedGetMultipleBlockSecurityStatus(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
	VAR(uint8, ANFCRL_VAR) bEnableBuffering,
    VAR(uint16, ANFCRL_VAR) wBlockNo,
	VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pStatus,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((gbBeginMultiBlocksRead == 0U)
						&& ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)))
			{
				/* Number of bNoOfBlocks can't be zero */
				if (wNoOfBlocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				/* Check number of blocks doesn't exceed 512 */
				if (((uint16) wBlockNo + wNoOfBlocks) > PHAL_ICODE_MAX_BLOCKS_EXTENDED)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
		case 2U:
			/* Get the block status. */
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_ReadBlocks(pDataParams,
					PHAL_ICODE_CMD_EXTENDED_GET_MULTIPLE_BLOCK_SECURITY_STATUS, bEnableBuffering, PHAL_ICODE_OPTION_OFF,
					wBlockNo, wNoOfBlocks, pStatus, pStatusLen));
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs a Extended Multiple block fast read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s)
 * and send back its value in the response. If a VICC supports Extended read multiple blocks command, it shall also support Read multiple blocks
 * command for the first 256 blocks of memory.
 *
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block security status, followed by the block
 * value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bOption                 : Option flag.
 *                                  0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                                  0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      wBlockNo                : Block number from where the data to be read.
 *      wNumBlocks              : Total number of block to read.
 *
 * Output Parameters:
 *      pData                   : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen                : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ExtendedFastReadMultipleBlocks(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
	VAR(uint8, ANFCRL_VAR) bEnableBuffering,
    VAR(uint8, ANFCRL_VAR) bOption,
	VAR(uint16, ANFCRL_VAR) wBlockNo,
	VAR(uint16, ANFCRL_VAR) wNumBlocks,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOldRxDataRate = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxDataRate = 0U;

  	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;
  	switch(pDataParams->bAlICodeStateMachineState)
  	{
  	    case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((gbBeginMultiBlocksRead == 0U)
						&& ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)))
			{
				/* Number of bNumBlocks can't be zero */
				if (wNumBlocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}

				/* Check number of blocks doesn't exceed 512. */
				if (((uint16) wBlockNo + wNumBlocks) > PHAL_ICODE_MAX_BLOCKS_EXTENDED)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
				}
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
  	    case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
  	    case 2U:
			/* Getting and storing the old baud rate */
  	    	PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_GetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_RXDATARATE, &wOldRxDataRate));
  	    	PH_BREAK_ON_FAILURE(wStatus);

			/* Find out the baud rate based on the flag */
			if ((pDataParams->bFlags & PHAL_ICODE_FLAG_DATA_RATE) > 0U)
			{
				if ((pDataParams->bFlags & PHAL_ICODE_FLAG_FAST_DATA_RATE) != 0U)
				{
					wRxDataRate = PHPAL_SLI15693_106KBPS_DATARATE;
				}
				else
				{
					wRxDataRate = PHPAL_SLI15693_26KBPS_DATARATE;
				}
			}
			else
			{
				if ((pDataParams->bFlags & PHAL_ICODE_FLAG_FAST_DATA_RATE) != 0U)
				{
					wRxDataRate = PHPAL_SLI15693_53KBPS_DATARATE;
				}
				else
				{
					wRxDataRate = PHPAL_SLI15693_212KBPS_DATARATE;
				}
			}
			pDataParams->bAlICodeStateMachineState = 3U;
			/* No break */

  	    case 3U:
			/* Set the baud rate. */
  	    	PH_CHECK_INPROCESS_FCT(wStatus,phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_RXDATARATE, wRxDataRate));
  	    	PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* No break */
  	    case 4U:
  	    	/* Read the blocks. */
  	    	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_ReadBlocks(pDataParams,
  	    			PHAL_ICODE_CMD_EXTENDED_FAST_READ_MULTIPLE_BLOCKS, bEnableBuffering,
					bOption, wBlockNo, wNumBlocks, pData, pDataLen));
  	    	PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 5U;
			/* No break */
  	    case 5U:
  	    	/* Set the old rx baud rate again . */
  	    	PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
  	    			PHPAL_SLI15693_CONFIG_RXDATARATE, wOldRxDataRate));
  	    	break;
	}

  	pDataParams->bAlICodeStateMachineState = 0U;
  	wOldRxDataRate = 0U;
  	wRxDataRate = 0U;
	return wStatus;
}

/*
 * This command enables the EAS mode if the EAS mode is not locked. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword. This interface will be common
 * for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Options to be enabled or disabled. As per ISO15693 protocol
 *                                  0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                                  0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_SetEAS(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
	VAR(uint8, ANFCRL_VAR) bOption)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = { 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
	    case 0U:
	    	wStatus = phhalHw_Exchange_GetStatus();
	    	if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
	    	{
	    		/* Clear Option bit */
	    		PH_CHECK_SUCCESS_FCT(wStatus, phalICode_Int_SetOptionBit(pDataParams, bOption));
	    		aCmdBuff[0] = PHAL_ICODE_CMD_SET_EAS;
	    		pDataParams->bAlICodeStateMachineState = 1U;
	    	}
	    	else
	    	{
	    		pDataParams->bAlICodeStateMachineState = 2U;
	    		return PH_STATUS_INPROCESS;
	    	}
	    	/* No break */
	    case 1U:
	    	/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
	    case 2U:
	    	/* Exchange the command information to PAL layer. */
	    	PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pDataParams,
	    			PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
	    	PH_BREAK_ON_FAILURE(wStatus);

	    	/* Write-alike handling */
	    	if (0U != (bOption))
	    	{
	    		pDataParams->bAlICodeStateMachineState = 3U;
	    	}
	    	else
	    	{
	    		pDataParams->bAlICodeStateMachineState = 4U;
	    		return PH_STATUS_INPROCESS;
	    	}
	    	/* No break */
	    case 3U:
	    	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pDataParams, wStatus));
	    	PH_BREAK_ON_FAILURE(wStatus);
	    	pDataParams->bAlICodeStateMachineState = 4U;
	    	/* No break */
	    case 4U:
	    	/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pDataParams, wStatus);
			break;

	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * This command disables the EAS mode if the EAS mode is not locked. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword. This interface will be common
 * for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Options to be enabled or disabled. As per ISO15693 protocol
 *                                  0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                                  0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ResetEAS(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
	VAR(uint8, ANFCRL_VAR) bOption)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = { 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_RESET_EAS;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pDataParams, bOption));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pDataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			/* Write-alike handling */
			if (0U != (bOption))
			{
				pDataParams->bAlICodeStateMachineState = 3U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 3U:
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pDataParams, wStatus));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* No break */
		case 4U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pDataParams, wStatus);
			break;
	}
	aCmdBuff[0] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * This command locks the current state of the EAS mode and the EAS ID. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword. This interface will be common
 * for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Options to be enabled or disabled. As per ISO15693 protocol
 *                                  0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                                  0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_LockEAS(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
	VAR(uint8, ANFCRL_VAR) bOption)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = { 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_LOCK_EAS;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pDataParams, bOption));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US,PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pDataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			/* Write-alike handling */
			if (0U != (bOption))
			{
				pDataParams->bAlICodeStateMachineState = 3U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 3U:
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pDataParams, wStatus));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* no break */
		case 4U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pDataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * This command returns the EAS sequence if the EAS mode is enabled. This interface will be common
 * for Software and Sam_NonX layers.
 *
 * bOption disabled: bEasIdMaskLength and pEasIdValue are not transmitted, EAS Sequence is returned;
 * bOption enabled and bEasIdMaskLength = 0: EAS ID is returned;
 * bOption enabled and bEasIdMaskLength > 0: EAS Sequence is returned by ICs with matching pEasIdValue;
 *
 * If the EAS mode is disabled, the label remains silent.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Option flag;
 *                                  PHAL_ICODE_OPTION_OFF
 *                                      EAS ID mask length and EAS ID value shall not be transmitted.
 *                                      If the EAS mode is enabled, the EAS response is returned from the ICODE IC.
 *                                      This configuration is compliant with the EAS command of the ICODE IC
 *                                  PHAL_ICODE_OPTION_ON.
 *                                      Within the command the EAS ID mask length has to be transmitted to identify how
 *                                      many bits of the following EAS ID value are valid (multiple of 8-bits). Only those
 *                                      ICODE ICs will respond with the EAS sequence which have stored the corresponding
 *                                      data in the EAS ID configuration (selective EAS) and if the EAS Mode is set.
 *                                      If the EAS ID mask length is set to 0, the ICODE IC will answer with its EAS ID
 *      pEasIdValue             : EAS ID; 0, 8 or 16 bits; optional.
 *      bEasIdMaskLen           : 8 bits; optional.
 *
 * Input Parameters:
 *      ppEas                   : EAS ID (16 bits) or EAS Sequence (256 bits).
 *      pEasLen                 : Length of bytes available in ppEas buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_EASAlarm(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEasIdValue,
	VAR(uint8, ANFCRL_VAR) bEasIdMaskLen,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEas,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pEasLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[4] = { 0U };
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[wCmdLen++] = PHAL_ICODE_CMD_EAS_ALARM;

				/* Set or clear the flags option bit indicated by bOption. */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit(pDataParams, bOption));
				if (bOption != PHAL_ICODE_OPTION_OFF)
				{
					wCmdLen = 2U + (uint16) (((uint16) bEasIdMaskLen) >> 3U);
					aCmdBuff[1] = bEasIdMaskLen;
					(void) phTools_memcpy(&aCmdBuff[2], pEasIdValue,
							(size_t) wCmdLen - 2U);
				}
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
		/* No break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
		/* No break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pDataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, wCmdLen, ppEas, pEasLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* No break */
		case 3U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pDataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	wCmdLen = 0U;
	return wStatus;
}

/*
 * This command enables the password protection for EAS. The EAS password has to be transmitted before with
 * \ref phalICode_SetPassword.. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_PasswordProtectEAS(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = { 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_PASSWORD_PROTECT_EAS_AFI;

				/* Clear Option bit to protect the EAS password. */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* No break */
		case 3U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * This command enables the password protection for AFI. The AFI password has to be transmitted before with
 * \ref phalICode_SetPassword.. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_PasswordProtectAFI(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = { 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;
	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_PASSWORD_PROTECT_EAS_AFI;

				/* Set Option bit to protect the AFI password. */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit(pDataParams, PHAL_ICODE_OPTION_ON));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_SetConfig(pDataParams,
					PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* No break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pDataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* No break */
		case 3U:
			/* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pDataParams, wStatus);
			break;
	}

	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * With this command, a new EAS identifier is stored in the corresponding configuration memory. If the EAS mode
 * is password protected the EAS password has to be transmitted before with \ref phalICode_SetPassword. This interface
 * will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      pEasIdValue             : EAS ID; 16 bits.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WriteEASID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEasIdValue)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[3] = {0U};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_WRITE_EAS_ID;
				aCmdBuff[1] = pEasIdValue[0];
				aCmdBuff[2] = pEasIdValue[1];

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 3U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * On this command, the label will respond with it's EPC data. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Output Parameters:
 *      ppEpc                   : EPC data; 96 bits.
 *      pEpcLen                 : Length of bytes available in ppEpc buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ReadEPC(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEpc, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pEpcLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_READ_EPC;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Proceed with the command in lower layers */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, ppEpc, pEpcLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs GetNXPSystemInformation command. This command allows for retrieving the NXP system information value from the VICC.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Output Parameters:
 *      ppSystemInfo            : The NXP system information of the VICC.
 *      pSystemInfoLen          : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_GetNXPSystemInformation(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Frame GetNXPSystemInformation command information. */
				aCmdBuff[0] = PHAL_ICODE_CMD_GET_NXP_SYSTEM_INFORMATION;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, ppSystemInfo, pSystemInfoLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs a GetRandomNumber command. On this command, the label will respond with a random number.
 * The received random number shall be used to diversify the password for the \ref phalICode_SetPassword command.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Output Parameters:
 *      ppRnd                   : Random number; 16 bits.
 *      ppRnd                   : Number of bytes in ppRnd buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_GetRandomNumber(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRnd, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRndLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_GET_RANDOM_NUMBER;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
				PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, ppRnd, pRndLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs SetPassword command. With this command the different passwords can be transmitted to the label.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * This command has to be executed just once for the related passwords if the label is powered.
 *
 * \verbatim
 * [XOR password calculation example]
 * pXorPwd[0] = pPassword[0] ^ pRnd[0];
 * pXorPwd[1] = pPassword[1] ^ pRnd[1];
 * pXorPwd[2] = pPassword[2] ^ pRnd[0];
 * pXorPwd[3] = pPassword[3] ^ pRnd[1];
 * \endverbatim
 *
 * \b Remark: This command can only be executed in addressed or selected mode except of Privacy Password.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bPwdIdentifier          : Password Identifier.
 *                                  PHAL_ICODE_SET_PASSWORD_READ
 *                                  PHAL_ICODE_SET_PASSWORD_WRITE
 *                                  PHAL_ICODE_SET_PASSWORD_PRIVACY
 *                                  PHAL_ICODE_SET_PASSWORD_DESTROY
 *                                  PHAL_ICODE_SET_PASSWORD_EAS
 *      pXorPwd                 : XOR Password; 32 bits.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_SetPassword(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[6] = {0U};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_SET_PASSWORD;
				aCmdBuff[1] = bPwdIdentifier;
				(void) phTools_memcpy(&aCmdBuff[2], pXorPwd, 4U);

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
				PH_EXCHANGE_DEFAULT, aCmdBuff, 6U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	aCmdBuff[4] = 0U;
	aCmdBuff[5] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs WritePassword command. With this command, a new password is written into the related memory. Note that the
 * old password has to be transmitted before with \ref phalICode_SetPassword. The new password takes effect immediately which
 * means that the new password has to be transmitted with \ref phalICode_SetPassword to get access to protected blocks/pages.
 * \b Remark: This command can only be executed in addressed or selected mode.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bPwdIdentifier          : Password Identifier.
 *                                  PHAL_ICODE_SET_PASSWORD_READ
 *                                  PHAL_ICODE_SET_PASSWORD_WRITE
 *                                  PHAL_ICODE_SET_PASSWORD_PRIVACY
 *                                  PHAL_ICODE_SET_PASSWORD_DESTROY
 *                                  PHAL_ICODE_SET_PASSWORD_EAS
 *      pPwd                    : Plain Password; 32 bits
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WritePassword(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPwd)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[6] = {0U};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_WRITE_PASSWORD;
				aCmdBuff[1] = bPwdIdentifier;
				(void) phTools_memcpy(&aCmdBuff[2], pPwd, 4U);

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
				PH_EXCHANGE_DEFAULT, aCmdBuff, 6U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	aCmdBuff[4] = 0U;
	aCmdBuff[5] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs LockPassword command. This command locks the addressed password. Note that the addressed password
 * has to be transmitted before with \ref phalICode_SetPassword. A locked password can not be changed any longer.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bPwdIdentifier          : Password Identifier.
 *                                  PHAL_ICODE_SET_PASSWORD_READ
 *                                  PHAL_ICODE_SET_PASSWORD_WRITE
 *                                  PHAL_ICODE_SET_PASSWORD_PRIVACY
 *                                  PHAL_ICODE_SET_PASSWORD_DESTROY
 *                                  PHAL_ICODE_SET_PASSWORD_EAS
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_LockPassword(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[2] = {0};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_LOCK_PASSWORD;
				aCmdBuff[1] = bPwdIdentifier;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
				PH_EXCHANGE_DEFAULT, aCmdBuff, 2U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs Page protection command. This command changes the protection status of a page. Note that the related
 * passwords have to be transmitted before with \ref phalICode_SetPassword if the page is not public.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bPPAdd_PageNo           : Page number to be protected in case of products that do not have pages
 *                                characterized as high and Low.
 *                                Block number to be protected in case of products that have pages
 *                                characterized as high and Low.
 *      bProtectionStatus       : Protection status options for the products that do not have pages
 *                                characterized as high and Low.
 *                                  0x00: PHAL_ICODE_PROTECT_PAGE_PUBLIC
 *                                  0x01: PHAL_ICODE_PROTECT_PAGE_READ_WRITE_READ_PASSWORD
 *                                  0x10: PHAL_ICODE_PROTECT_PAGE_WRITE_PASSWORD
 *                                  0x11: PHAL_ICODE_PROTECT_PAGE_READ_WRITE_PASSWORD_SEPERATE
 *
 *                                Extended Protection status options for the products that have pages
 *                                characterized as high and Low.
 *                                  0x01: PHAL_ICODE_PROTECT_PAGE_READ_LOW
 *                                  0x02: PHAL_ICODE_PROTECT_PAGE_WRITE_LOW
 *                                  0x10: PHAL_ICODE_PROTECT_PAGE_READ_HIGH
 *                                  0x20: PHAL_ICODE_PROTECT_PAGE_WRITE_HIGH
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ProtectPage(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bPPAdd_PageNo, VAR(uint8, ANFCRL_VAR) bProtectionStatus)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[3] = {0};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;

	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_PROTECT_PAGE;
				aCmdBuff[1] = bPPAdd_PageNo;
				aCmdBuff[2] = bProtectionStatus;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus, phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));

				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(wStatus,
			phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
				PH_EXCHANGE_DEFAULT, aCmdBuff, 3U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}

	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Perform LockPageProtectionCondition command. This command permanently locks the protection status of a page.
 * Note that the related passwords have to be transmitted before with \ref phalICode_SetPassword if the page is
 * not public. This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bPageNo                 : Page number to be protected.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_LockPageProtectionCondition(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams, VAR(uint8, ANFCRL_VAR) bPageNo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[2] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;
	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_LOCK_PAGE_PROTECTION_CONDITION;
				aCmdBuff[1] = bPageNo;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
			    pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
	    case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
					PH_EXCHANGE_DEFAULT, aCmdBuff, 2U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
    aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	return wStatus;
}

/*
 * Perform GetMultipleBlockProtectionStatus command. This instructs the label to return the block protection
 * status of the requested blocks. This interface will be common for Software and Sam_NonX layers.
 *
 * Remark: If bBlockNo + bNoOfBlocks exceeds the total available number of user blocks, the number of received
 * status bytes is less than the requested number. This means that the last returned status byte corresponds to the
 * highest available user block.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bEnableBuffering        : Option for buffering the response data.
 *                                  0x00:   PHAL_ICODE_DISABLE (Option to disable the buffering of response data)
 *                                  0x01:   PHAL_ICODE_ENABLE (Option to enable the buffering of response data)
 *      bBlockNo                : First Block number.
 *      bNoOfBlocks             : Number of blocks.
 *
 * Output Parameters:
 *      pProtectionStates       : Protection states of requested blocks.
 *      pNumReceivedStates      : Number of received block protection states.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_GetMultipleBlockProtectionStatus(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams, VAR(uint8, ANFCRL_VAR) bEnableBuffering,
    VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNoOfBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProtectionStates,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumReceivedStates)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Number of bNoOfBlocks can't be zero */
				if (bNoOfBlocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER,
							PH_COMP_AL_ICODE);
				}

				/* Check number of blocks doesn't exceed 256 */
				if (((uint16)bBlockNo + bNoOfBlocks) > PHAL_ICODE_MAX_BLOCKS)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER,
							PH_COMP_AL_ICODE);
				}
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Get the blocks status. */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phalICode_Int_ReadBlocks( pPalSli15693DataParams, PHAL_ICODE_CMD_GET_MULTIPLE_BLOCK_PROTECTION_STATUS, bEnableBuffering,
					PHAL_ICODE_OPTION_OFF, bBlockNo, bNoOfBlocks, pProtectionStates, pNumReceivedStates));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	return wStatus;
}

/*
 * Performs Destroy command. This command permanently destroys the label. This interface will be common for Software and Sam_NonX layers.
 *
 * The Destroy password has to be transmitted before with \ref phalICode_SetPassword.
 * Remark: This command is irreversible and the label will never respond to any command again.
 * Remark: This command can only be executed in addressed or selected mode.
 *
 * Note: This command is not valid for ICode Dna product as the Destroy feature is part of Mutual
 * Authentication command (refer \ref phalICode_AuthenticateMAM).
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      pXorPwd                 : XOR Password; 32 bits. Pass the password for the ICODE products that supports and NULL
 *                                for the products that do not support.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_Destroy(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[5] = {0U};
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuffLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[bCmdBuffLen++] = PHAL_ICODE_CMD_DESTROY;

				/* For SLI-S and SLI-L, the Xor password is not required. */
				if (pXorPwd != NULL)
				{
					(void) phTools_memcpy(&aCmdBuff[1], pXorPwd, 4U);
					bCmdBuffLen += (uint8) 4U;
				}

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, bCmdBuffLen, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	bCmdBuffLen = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	aCmdBuff[4] = 0U;
	return wStatus;
}

/*
 * Performs EnablePrivacy command. This command instructs the label to enter privacy mode. This interface will be common
 * for Software and Sam_NonX layers.
 *
 * In privacy mode, the label will only respond to \ref phalSli_GetRandomNumber and \ref phalICode_SetPassword commands.
 * To get out of the privacy mode, the Privacy password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * Note: This command is not valid for ICode Dna product as the Destroy feature is part of Mutual
 * Authentication command (refer \ref phalICode_AuthenticateMAM).
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      pXorPwd                 : XOR Password; 32 bits. Pass the password for the ICODE products that supports and NULL
 *                                for the products that do not support.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_EnablePrivacy(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[5] = {0U};
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuffLen = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;
	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[bCmdBuffLen++] = PHAL_ICODE_CMD_ENABLE_PRIVACY;

				/* For SLI-S and SLI-L, the Xor password is not required. */
				if (pXorPwd != NULL)
				{
					(void) phTools_memcpy(&aCmdBuff[1], pXorPwd, 4U);
					bCmdBuffLen += (uint8) 4U;
				}

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
		    /* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, bCmdBuffLen, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	bCmdBuffLen = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	aCmdBuff[4] = 0U;
	return wStatus;
}

/*
 * Perform 64-BitPasswordProtection command. This instructs the label that both of the Read and Write passwords
 * are required for protected access. This interface will be common for Software and Sam_NonX layers.
 *
 * Note that both the Read and Write passwords have to be transmitted before with \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_64BitPasswordProtection(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;
	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_64_BIT_PASSWORD_PROTECTION;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
    pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * Performs ReadSignature command. On this command, the label will respond with the signature value.
 * This interface will be common for Software and Sam_NonX layers.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Output Parameters:
 *      ppSign                  : The originality signature returned by the VICC.
 *      ppSign                  : Length of originality signature buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ReadSignature(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSign, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSignLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};
	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				aCmdBuff[0] = PHAL_ICODE_CMD_READ_SIGNATURE;

				/* Clear Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command information to PAL layer */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, 1U, ppSign, pSignLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * Reads a multiple 4 byte(s) data from the mentioned configuration block address. Here the starting address of the
 * configuration block should be given in the parameter bBlockAddr and the number of blocks to read from the starting
 * block should be given in the parameter bNoOfBlocks.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bBlockAddr              : Configuration block address.
 *      bNoOfBlocks             : The n block(s) to read the configuration data.
 *
 * Output Parameters:
 *      ppData                  : Multiple of 4 (4u * No Of Blocks) byte(s) of data read from the mentioned
 *                                configuration block address.
 *      pDataLen                : Number of received configuration data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_ReadConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bBlockAddr, VAR(uint8, ANFCRL_VAR) bNoOfBlocks, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdLen = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[4] = {0U};
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;
	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Update Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			/* Clear the command buffer. */
			(void) memset(aCmdBuff, 0x00, (size_t) sizeof(aCmdBuff));
			/* Frame the command. */
			aCmdBuff[bCmdLen++] = PHAL_ICODE_CMD_READ_CONFIG;
			/* Append the block address. */
			aCmdBuff[bCmdLen++] = bBlockAddr;
			/* Append the no of blocks to read. */
			aCmdBuff[bCmdLen++] = bNoOfBlocks - 1U;
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, bCmdLen, ppData, pDataLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
		    wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	return wStatus;
}

/*
 * Writes a 4 byte data to the mentioned configuration block address.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption                 : Options to be enabled or disabled. As per ISO15693 protocol
 *                                  0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                                  0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *      bBlockAddr              : Configuration block address.
 *      pData                   : A 4 byte data to be written to the mentioned configuration block address.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_WriteConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockAddr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[7] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Update Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit(pPalSli15693DataParams, bOption));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			/* Clear the command buffer. */
			(void) memset(aCmdBuff, 0x00, (size_t) sizeof(aCmdBuff));
			/* Frame the command. */
			aCmdBuff[bCmdLen++] = PHAL_ICODE_CMD_WRITE_CONFIG;
			/* Append the block address. */
			aCmdBuff[bCmdLen++] = bBlockAddr;
			/* Append the block data. */
			(void) phTools_memcpy(&aCmdBuff[bCmdLen], pData, 4U);
			bCmdLen = bCmdLen + 4U;
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, bCmdLen, &pResponse, &wRespLen));
			/* Write-alike handling */
			if (0U != (bOption))
			{
				pDataParams->bAlICodeStateMachineState = 3U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 3U:
			PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_WriteAlikeHandling(pPalSli15693DataParams, wStatus));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 4U;
			/* no break */
		case 4U:
		    /* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
	pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	aCmdBuff[1] = 0U;
	aCmdBuff[2] = 0U;
	aCmdBuff[3] = 0U;
	aCmdBuff[4] = 0U;
	aCmdBuff[5] = 0U;
	aCmdBuff[6] = 0U;
	return wStatus;
}

/*
 * Enables the random ID generation in the tag. This interfaces is used to instruct the tag to generate
 * a random number in privacy mode.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_PickRandomID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmdBuff[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams = (phpalSli15693_Sw_DataParams_t*)pPalSli15693DataParams;

	switch(pDataParams->bAlICodeStateMachineState)
	{
		case 0U:
			wStatus = phhalHw_Exchange_GetStatus();
			if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS))
			{
				/* Update Option bit */
				PH_CHECK_FAILURE_FCT(wStatus,
						phalICode_Int_SetOptionBit( pPalSli15693DataParams, PHAL_ICODE_OPTION_OFF));
				pDataParams->bAlICodeStateMachineState = 1U;
			}
			else
			{
				pDataParams->bAlICodeStateMachineState = 2U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 1U:
			/* Set long timeout */
			PH_CHECK_INPROCESS_FCT(wStatus,
					phpalSli15693_SetConfig( pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			PH_BREAK_ON_FAILURE(wStatus);
			/* Clear the command buffer. */
			(void) memset(aCmdBuff, 0x00, (size_t) sizeof(aCmdBuff));
			/* Frame the command. */
			aCmdBuff[bCmdLen++] = PHAL_ICODE_CMD_PICK_RANDOM_ID;
			pDataParams->bAlICodeStateMachineState = 2U;
			/* no break */
		case 2U:
			/* Exchange the command. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalSli15693_Exchange(pPalSli15693DataParams,
			        PH_EXCHANGE_DEFAULT, aCmdBuff, bCmdLen, &pResponse, &wRespLen));
			PH_BREAK_ON_FAILURE(wStatus);
			pDataParams->bAlICodeStateMachineState = 3U;
			/* no break */
		case 3U:
		    /* Compute the status code. */
			wStatus = phalICode_Int_ComputeErrorCode(pPalSli15693DataParams, wStatus);
			break;
	}
    pDataParams->bAlICodeStateMachineState = 0U;
	aCmdBuff[0] = 0U;
	return wStatus;
}

/*
 * Get the type of Tag
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *
 * Output Parameters:
 *      pTagType                : The type of ICode tag.
 *                                  0xFFFF: PHAL_ICODE_TAG_TYPE_UNKNOWN
 *                                  0x0001: PHAL_ICODE_TAG_TYPE_ICODE_SLI
 *                                  0x0002: PHAL_ICODE_TAG_TYPE_ICODE_SLI_S
 *                                  0x0003: PHAL_ICODE_TAG_TYPE_ICODE_SLI_L
 *                                  0x5001: PHAL_ICODE_TAG_TYPE_ICODE_SLIX
 *                                  0x5002: PHAL_ICODE_TAG_TYPE_ICODE_SLIX_S
 *                                  0x5003: PHAL_ICODE_TAG_TYPE_ICODE_SLIX_L
 *                                  0x0801: PHAL_ICODE_TAG_TYPE_ICODE_SLI_X2
 *                                  0x1801: PHAL_ICODE_TAG_TYPE_ICODE_DNA
 *                                  0x5801: PHAL_ICODE_TAG_TYPE_ICODE_NTAG5_I2C
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Int_GetTagType(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTagType) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aUID[PHPAL_SLI15693_UID_LENGTH] = { 0 };
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidLen = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTagType;

	PH_CHECK_SUCCESS_FCT(wStatus,
			phpalSli15693_GetSerialNo(pPalSli15693DataParams, aUID, &bUidLen));

	/* Reverse the buffer. */
	phalICode_Int_Reverse(aUID, PHPAL_SLI15693_UID_LENGTH);

	/* Extract the tag type from the UID. */
	wTagType = (uint16) (((uint16) aUID[3] << 8U) | (aUID[2]));

	switch (wTagType) {
	case PHAL_ICODE_TAG_TYPE_ICODE_SLI:
		*pTagType = PHAL_ICODE_TAG_TYPE_ICODE_SLI;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_SLI_S:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_SLI_L:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_SLIX:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_SLIX_S:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_SLIX_L:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_SLI_X2:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_DNA:
		*pTagType = wTagType;
		break;

	case PHAL_ICODE_TAG_TYPE_ICODE_NTAG5_I2C:
		*pTagType = wTagType;
		break;

	default:
		*pTagType = PHAL_ICODE_TAG_TYPE_UNKNOWN;
		break;
	}

	return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHALICODE_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALICODE_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_ICODE */

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */
