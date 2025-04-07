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
*   @file    phalICode_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlICode - AL API usage in common use cases.
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
#include <ph_Status.h>
#include <ph_RefDefs.h>
#include <phpalSli15693.h>
#include <phalICode.h>

#ifdef NXPBUILD__PHAL_ICODE_SW

#include "phalICode_Sw.h"
#include "../phalICode_Int.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalICode_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALICODE_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALICODE_SW_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHALICODE_SW_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHALICODE_SW_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHALICODE_SW_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHALICODE_SW_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHALICODE_SW_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalICode_Sw.h header file are of the same vendor */
#if (PHALICODE_SW_VENDOR_ID_C != PHALICODE_SW_VENDOR_ID)
    #error "phalICode_Sw.c and phalICode_Sw.h have different vendor ids"
#endif
/* Check if current file and phalICode_Sw.h header file are of the same Autosar version */
#if ((PHALICODE_SW_AR_RELEASE_MAJOR_VERSION_C    != PHALICODE_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHALICODE_SW_AR_RELEASE_MINOR_VERSION_C    != PHALICODE_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHALICODE_SW_AR_RELEASE_REVISION_VERSION_C != PHALICODE_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalICode_Sw.c and phalICode_Sw.h are different"
#endif
/* Check if current file and phalICode_Sw.h header file are of the same Software version */
#if ((PHALICODE_SW_SW_MAJOR_VERSION_C != PHALICODE_SW_SW_MAJOR_VERSION) || \
     (PHALICODE_SW_SW_MINOR_VERSION_C != PHALICODE_SW_SW_MINOR_VERSION) || \
     (PHALICODE_SW_SW_PATCH_VERSION_C != PHALICODE_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalICode_Sw.c and phalICode_Sw.h are different"
#endif
#endif /* NXPBUILD__PHAL_ICODE_SW */
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
#ifdef NXPBUILD__PHAL_ICODE_SW
#define ANFCRL_START_SEC_CODE
#if ((PHALICODE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALICODE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/*
 * Initializes the Icode Software component.
 *
 * Input Parameters:
 *      pDataParams             : Pointer to this layer's parameter structure.
 *      wSizeOfDataParams       : Specifies the size of the data parameter structure.
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      pCryptoDataParams       : Pointer to the parameter structure of the underlying Crypto layer for encryption / Decryption.
 *      pCryptoRngDataParams    : Pointer to the parameter structure of the underlying Crypto layer for random number generation.
 *      pKeyStoreDataParams     : Pointer to the parameter structure of the underlying Keystore layer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_Init(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams,
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams) {
	/* Validate the parameters. */
	PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_ICODE);
	PH_ASSERT_NULL_PARAM(pPalSli15693DataParams, PH_COMP_AL_ICODE);

	/* Check the size. */
	if (sizeof(phalICode_Sw_DataParams_t) != wSizeOfDataParams) {
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_AL_ICODE);
	}

	/* Initialize the structure members. */
	pDataParams->wId = PH_COMP_AL_ICODE | PHAL_ICODE_SW_ID;
	pDataParams->pPalSli15693DataParams = pPalSli15693DataParams;
	pDataParams->pCryptoDataParams = pCryptoDataParams;
	pDataParams->pCryptoRngDataParams = pCryptoRngDataParams;
	pDataParams->pKeyStoreDataParams = pKeyStoreDataParams;
	pDataParams->bBuffering = PH_ON;

	/* Reset the random number buffer. */
	(void) memset(pDataParams->aRnd_Challenge, 0x00,
			PHAL_ICODE_RANDOM_NUMBER_SIZE);

	return PH_ERR_SUCCESS;
}

/*
 * Performs a Single block read command. When receiving the Read Single Block command, the VICC shall read the requested block and send
 * back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                              0x00:   PHAL_ICODE_OPTION_OFF
 *                              0x01:   PHAL_ICODE_OPTION_ON
 *                              0x00:   PHAL_ICODE_OPTION_DEFAULT
 *
 *                              If Option is OFF, block Security Status information is not available. Only block data is available.
 *                              Format will be 4 byte data.
 *                              If Option is ON, both block Security Status information and Block Data is available. Format of the
 *                              response will be Status, 4 byte data
 *      bBlockNo        : Block number from where the data to be read.
 *
 * Output Parameters:
 *      ppData          : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen        : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ReadSingleBlock(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

  PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ReadSingleBlock(pDataParams->pPalSli15693DataParams,
					bOption, bBlockNo, ppData, pDataLen));

	return wStatus;
}

/*
 * Performs a Single block write command. When receiving the Write single block command, the VICC shall write the requested block with the
 * data contained in the request and report the success of the operation in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON)
 * is set in the request, the VICC shall wait for the reception of an EOF from the VCD and upon such reception shall return its response.
 * If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its response when it has completed the write operation starting
 * after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon
 * detection of the rising edge of the EOF of the VCD request.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      bBlockNo        : Block number to which the data should be written.
 *      pData           : Information to be written to the specified block number.
 *      bDataLen        : Number of bytes to be written.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_WriteSingleBlock(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bBlockNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint8, ANFCRL_VAR) bDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

  PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_WriteSingleBlock(pDataParams->pPalSli15693DataParams,
					bOption, bBlockNo, pData, bDataLen));

	return wStatus;
}

/*
 * Performs a Lock block command. When receiving the Lock block command, the VICC shall lock permanently the requested block. If the
 * Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the VCD
 * and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 * (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      bBlockNo        : Block number which should be locked.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_LockBlock(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockNo) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

  PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_LockBlock(pDataParams->pPalSli15693DataParams,
					bOption, bBlockNo));

	return wStatus;
}

/*
 * Performs a Multiple block read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s) and send
 * back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall
 *  return only the block value.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      bBlockNo        : Block number from where the data to be read.
 *      bNumBlocks      : Total number of block to read.
 *
 * Output Parameters:
 *      pData           : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen        : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ReadMultipleBlocks(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

    PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ReadMultipleBlocks(
					pDataParams->pPalSli15693DataParams,
					pDataParams->bBuffering, bOption, bBlockNo, bNumBlocks,
					pData, pDataLen));

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
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      bAfi            : Value of Application Family Identifier.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_WriteAFI(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bAfi) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

    PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_WriteAFI(pDataParams->pPalSli15693DataParams, bOption,
					bAfi));

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
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_LockAFI(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

    PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_LockAFI(pDataParams->pPalSli15693DataParams, bOption));

	return wStatus;
}

/*
 * Performs WriteDSFID command. When receiving the Write DSFID request, the VICC shall write the DSFID value into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF
 * from the VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return its response when it has completed the write operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a
 * multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the
 * EOF of the VCD request.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      bDsfid          : Value of DSFID (data storage format identifier).
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_WriteDSFID(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bDsfid) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

    PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_WriteDSFID(pDataParams->pPalSli15693DataParams,
					bOption, bDsfid));

	return wStatus;
}

/*
 * Performs LockDSFID command. When receiving the Lock DSFID request, the VICC shall lock the DSFID value permanently into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us)
 * with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_LockDSFID(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

    PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_LockDSFID(pDataParams->pPalSli15693DataParams,
					bOption));

	return wStatus;
}

/*
 * Performs GetSystemInformation command. This command allows for retrieving the system information value from the VICC.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *
 * Output Parameters:
 *      ppSystemInfo    : The system information of the VICC.
 *      pSystemInfoLen  : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetSystemInformation(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_GetSystemInformation(
			pDataParams->pPalSli15693DataParams, ppSystemInfo,
			pSystemInfoLen));

	return wStatus;
}

/*
 * Performs GetMultipleBlockSecurityStatus. When receiving the Get multiple block security status command, the VICC
 * shall send back the block security status.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bBlockNo        : Block number for which the status should be returned.
 *      bNoOfBlocks     : Number of blocks to be used for returning the status.
 *
 * Output Parameters:
 *      pStatus         : The status of the block number mentioned in bBlockNo until bNoOfBlocks.
 *      pStatusLen      : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetMultipleBlockSecurityStatus(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNoOfBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pStatus,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_GetMultipleBlockSecurityStatus(
			pDataParams->pPalSli15693DataParams,
			pDataParams->bBuffering, bBlockNo, bNoOfBlocks, pStatus,
			pStatusLen));

	return wStatus;
}

/*
 * Performs a Multiple block fast read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s) and
 * send back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall
 * return only the block value.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      bBlockNo        : Block number from where the data to be read.
 *      bNumBlocks      : Total number of block to read.
 *
 * Output Parameters:
 *      pData           : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen        : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_FastReadMultipleBlocks(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bBlockNo, VAR(uint8, ANFCRL_VAR) bNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_FastReadMultipleBlocks(
			pDataParams->pPalSli15693DataParams,
			pDataParams->bBuffering, bOption, bBlockNo, bNumBlocks,
			pData, pDataLen));

	return wStatus;
}

/**
 * \brief Performs a Extended Single block read command. When receiving the Extended Read Single Block command, the VICC shall read the
 * requested block and send back its value in the response. If a VICC supports Extended read single block command, it shall also support
 * Read single block command for the first 256 blocks of memory. If the Option_flag (bOption = #PHAL_ICODE_OPTION_ON) is set in the request,
 * the VICC shall return the block security status, followed by the block value. If it is not set (bOption = #PHAL_ICODE_OPTION_OFF), the
 * VICC shall return only the block value.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                              0x00:   PHAL_ICODE_OPTION_OFF
 *                              0x01:   PHAL_ICODE_OPTION_ON
 *                              0x00:   PHAL_ICODE_OPTION_DEFAULT
 *
 *                              If Option is OFF, block Security Status information is not available. Only block data is available.
 *                              Format will be 4 byte data.
 *                              If Option is ON, both block Security Status information and Block Data is available. Format of the
 *                              response will be Status, 4 byte data
 *      wBlockNo        : Block number from where the data to be read.
 *
 * Output Parameters:
 *      ppData          : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen        : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedReadSingleBlock(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint16, ANFCRL_VAR) wBlockNo, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ExtendedReadSingleBlock(
			pDataParams->pPalSli15693DataParams, bOption, wBlockNo,
			ppData, pDataLen));

	return wStatus;
}

/**
 * \brief Performs a Extended Single block Write command. When receiving the Extended write single block command, the VICC shall write the
 * requested block with the data contained in the request and report the success of the operation in the response. If a VICC supports
 * Extended write single block command, it shall also support Write single block command for the first 256 blocks of memory.
 *
 * If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its response when it has completed the write operation starting
 * after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon
 * detection of the rising edge of the EOF of the VCD request.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the write operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      wBlockNo        : Block number to which the data should be written.
 *      pData           : Information to be written to the specified block number.
 *      bDataLen        : Number of bytes to be written.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedWriteSingleBlock(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint16, ANFCRL_VAR) wBlockNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint8, ANFCRL_VAR) bDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ExtendedWriteSingleBlock(
			pDataParams->pPalSli15693DataParams, bOption, wBlockNo,
			pData, bDataLen));

	return wStatus;
}

/*
 * Performs a Extended Lock block command. When receiving the Lock block command, the VICC shall lock permanently the requested
 * block. If a VICC supports Extended lock block command, it shall also support Lock block command for the first 256 blocks of memory.
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 * (302 us) with a total tolerance of 32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (The VICC shall return its response when it has completed the lock operation
 *                                                         starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 *                                                         (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection
 *                                                         of the rising edge of the EOF of the VCD request.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (The VICC shall wait for the reception of an EOF from the VCD and upon such reception
 *                                                        shall return its response.)
 *      wBlockNo        : Block number which should be locked.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedLockBlock(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint16, ANFCRL_VAR) wBlockNo)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ExtendedLockBlock(pDataParams->pPalSli15693DataParams,
			bOption,
			wBlockNo));

	return wStatus;
}

/*
 * Performs a Extended Multiple block read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s)
 * and send back its value in the response. If a VICC supports Extended read multiple blocks command, it shall also support Read multiple blocks
 * command for the first 256 blocks of memory.
 *
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block security status, followed by the block
 * value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      wBlockNo        : Block number from where the data to be read.
 *      wNumBlocks      : Total number of block to read.
 *
 * Output Parameters:
 *      pData           : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen        : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedReadMultipleBlocks(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint16, ANFCRL_VAR) wBlockNo, VAR(uint16, ANFCRL_VAR) wNumBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ExtendedReadMultipleBlocks(
			pDataParams->pPalSli15693DataParams,
			pDataParams->bBuffering, bOption, wBlockNo, wNumBlocks,
			pData, pDataLen));

	return wStatus;
}

/*
 * Performs ExtendedGetSystemInformation command. This command allows for retrieving the system information value
 * from the VICC and shall be supported by the VICC if extended memory or security functionalities are supported
 * by the VICC.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bInfoParams         : Extend Get System Information parameter request fields.
 *                              0x10: PHAL_ICODE_INFO_PARAMS_REQUEST_DEFAULT
 *                              0x01: PHAL_ICODE_INFO_PARAMS_REQUEST_DSFID
 *                              0x02: PHAL_ICODE_INFO_PARAMS_REQUEST_AFI
 *                              0x04: PHAL_ICODE_INFO_PARAMS_REQUEST_VICC_MEM_SIZE
 *                              0x08: PHAL_ICODE_INFO_PARAMS_REQUEST_IC_REFERENCE
 *                              0x10: PHAL_ICODE_INFO_PARAMS_REQUEST_MOI
 *                              0x20: PHAL_ICODE_INFO_PARAMS_REQUEST_COMMAND_LIST
 *                              0x50: PHAL_ICODE_INFO_PARAMS_REQUEST_CSI_INFORMATION
 *                              0x80: PHAL_ICODE_INFO_PARAMS_REQUEST_EXT_GET_SYS_INFO
 *
 * Output Parameters:
 *      ppSystemInfo        : The system information of the VICC.
 *      pSystemInfoLen      : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedGetSystemInformation(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bInfoParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ExtendedGetSystemInformation(
			pDataParams->pPalSli15693DataParams, bInfoParams,
			ppSystemInfo, pSystemInfoLen));

	return wStatus;
}

/*
 * Performs ExtendedGetMultipleBlockSecurityStatus. When receiving the Extended Get multiple block security status
 * command, the VICC shall send back the block security status. The blocks are numbered from 0000 to FFFF (0 - 65535).
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      wBlockNo        : Block number for which the status should be returned.
 *      wNoOfBlocks     : Number of blocks to be used for returning the status.
 *
 * Output Parameters:
 *      pStatus         : The status of the block number mentioned in wBlockNo until wNoOfBlocks.
 *      pStatusLen      : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedGetMultipleBlockSecurityStatus(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wBlockNo,
	VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pStatus,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus,phalICode_Int_ExtendedGetMultipleBlockSecurityStatus(pDataParams->pPalSli15693DataParams,
  					pDataParams->bBuffering, wBlockNo, wNoOfBlocks, pStatus, pStatusLen));
	return wStatus;
}

/*
 * Performs a Extended Multiple block fast read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s)
 * and send back its value in the response. If a VICC supports Extended read multiple blocks command, it shall also support Read multiple blocks
 * command for the first 256 blocks of memory.
 *
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block security status, followed by the block
 * value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *      bOption         : Option flag.
 *                          0x00:   PHAL_ICODE_OPTION_OFF (Block Security Status information is not available. Only block data is available.)
 *                          0x01:   PHAL_ICODE_OPTION_ON (Both Block Security Status information and Block Data is available. This will be
 *                                                        available in the first byte of ppData buffer.)
 *      wBlockNo        : Block number from where the data to be read.
 *      wNumBlocks      : Total number of block to read.
 *
 * Output Parameters:
 *      pData           : Information received from VICC in with respect to bOption parameter information.
 *      pDataLen        : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ExtendedFastReadMultipleBlocks(
    P2VAR(phalICode_Sw_DataParams_t,AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint16, ANFCRL_VAR) wBlockNo,
	VAR(uint16, ANFCRL_VAR) wNumBlocks,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_ExtendedFastReadMultipleBlocks(pDataParams->pPalSli15693DataParams,
					pDataParams->bBuffering, bOption, wBlockNo, wNumBlocks, pData, pDataLen));

	return wStatus;
}

/*
 * This command enables the EAS mode if the EAS mode is not locked. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pPalSli15693DataParams  : Pointer to the parameter structure of the underlying palSli15693 layer.
 *      bOption             : Options to be enabled or disabled. As per ISO15693 protocol
 *                              0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                              0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_SetEAS(
	P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_SetEAS(pDataParams->pPalSli15693DataParams, bOption));
	return wStatus;
}

/*
 * This command disables the EAS mode if the EAS mode is not locked. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bOption             : Options to be enabled or disabled. As per ISO15693 protocol
 *                              0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                              0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ResetEAS(
	P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus,phalICode_Int_ResetEAS(pDataParams->pPalSli15693DataParams,bOption));
	return wStatus;
}

/*
 * This command locks the current state of the EAS mode and the EAS ID. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bOption             : Options to be enabled or disabled. As per ISO15693 protocol
 *                              0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                              0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_LockEAS(
	P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_LockEAS(pDataParams->pPalSli15693DataParams, bOption));
	return wStatus;
}

/*
 * This command returns the EAS sequence if the EAS mode is enabled.
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
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bOption             : Option flag;
 *                              PHAL_ICODE_OPTION_OFF
 *                                  EAS ID mask length and EAS ID value shall not be transmitted.
 *                                  If the EAS mode is enabled, the EAS response is returned from the ICODE IC.
 *                                  This configuration is compliant with the EAS command of the ICODE IC
 *                              PHAL_ICODE_OPTION_ON.
 *                                  Within the command the EAS ID mask length has to be transmitted to identify how
 *                                  many bits of the following EAS ID value are valid (multiple of 8-bits). Only those
 *                                  ICODE ICs will respond with the EAS sequence which have stored the corresponding
 *                                  data in the EAS ID configuration (selective EAS) and if the EAS Mode is set.
 *                                  If the EAS ID mask length is set to 0, the ICODE IC will answer with its EAS ID
 *      pEasIdValue         : EAS ID; 0, 8 or 16 bits; optional.
 *      bEasIdMaskLen       : 8 bits; optional.
 *
 * Input Parameters:
 *      ppEas               : EAS ID (16 bits) or EAS Sequence (256 bits).
 *      pEasLen             : Length of bytes available in ppEas buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_EASAlarm(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEasIdValue,
	VAR(uint8, ANFCRL_VAR) bEasIdMaskLen,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEas,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pEasLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_EASAlarm(pDataParams->pPalSli15693DataParams, bOption,
					pEasIdValue, bEasIdMaskLen, ppEas, pEasLen));
	return wStatus;
}

/*
 * This command enables the password protection for EAS. The EAS password has to be transmitted before with
 * \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_PasswordProtectEAS(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_PasswordProtectEAS(pDataParams->pPalSli15693DataParams));
	return wStatus;
}

/*
 * This command enables the password protection for AFI. The AFI password has to be transmitted before with
 * \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_PasswordProtectAFI(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	PH_CHECK_INPROCESS_FCT(wStatus, phalICode_Int_PasswordProtectAFI(pDataParams->pPalSli15693DataParams));
	return wStatus;
}

/*
 * With this command, a new EAS identifier is stored in the corresponding configuration memory. If the EAS mode
 * is password protected the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      pEasIdValue         : EAS ID; 16 bits.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_WriteEASID(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEasIdValue)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_WriteEASID(pDataParams->pPalSli15693DataParams,
			pEasIdValue));

	return wStatus;
}

/*
 * On this command, the label will respond with it's EPC data.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Output Parameters:
 *      ppEpc               : EPC data; 96 bits.
 *      pEpcLen             : Length of bytes available in ppEpc buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ReadEPC(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEpc, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pEpcLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ReadEPC(pDataParams->pPalSli15693DataParams, ppEpc,
			pEpcLen));

	return wStatus;
}

/*
 * Performs GetNXPSystemInformation command. This command allows for retrieving the NXP system information value from the VICC.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams     : Pointer to this layer's parameter structure.
 *
 * Output Parameters:
 *      ppSystemInfo    : The NXP system information of the VICC.
 *      pSystemInfoLen  : Number of received data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetNXPSystemInformation(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen) {
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_GetNXPSystemInformation(
			pDataParams->pPalSli15693DataParams, ppSystemInfo,
			pSystemInfoLen));

	return wStatus;
}

/*
 * Performs a GetRandomNumber command. On this command, the label will respond with a random number.
 * The received random number shall be used to diversify the password for the \ref phalICode_SetPassword command.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Output Parameters:
 *      ppRnd               : Random number; 16 bits.
 *      ppRnd               : Number of bytes in ppRnd buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetRandomNumber(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRnd, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRndLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_GetRandomNumber(pDataParams->pPalSli15693DataParams,
			ppRnd, pRndLen));

	return wStatus;
}

/*
 * Performs SetPassword command. With this command the different passwords can be transmitted to the label.
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
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bPwdIdentifier      : Password Identifier.
 *                              PHAL_ICODE_SET_PASSWORD_READ
 *                              PHAL_ICODE_SET_PASSWORD_WRITE
 *                              PHAL_ICODE_SET_PASSWORD_PRIVACY
 *                              PHAL_ICODE_SET_PASSWORD_DESTROY
 *                              PHAL_ICODE_SET_PASSWORD_EAS
 *      pXorPwd             : XOR Password; 32 bits.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_SetPassword(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_SetPassword(pDataParams->pPalSli15693DataParams,
			bPwdIdentifier, pXorPwd));

	return wStatus;
}

/*
 * Performs WritePassword command. With this command, a new password is written into the related memory. Note that the
 * old password has to be transmitted before with \ref phalICode_SetPassword. The new password takes effect immediately which
 * means that the new password has to be transmitted with \ref phalICode_SetPassword to get access to protected blocks/pages.
 * \b Remark: This command can only be executed in addressed or selected mode.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bPwdIdentifier      : Password Identifier.
 *                              PHAL_ICODE_SET_PASSWORD_READ
 *                              PHAL_ICODE_SET_PASSWORD_WRITE
 *                              PHAL_ICODE_SET_PASSWORD_PRIVACY
 *                              PHAL_ICODE_SET_PASSWORD_DESTROY
 *                              PHAL_ICODE_SET_PASSWORD_EAS
 *      pPwd                : Plain Password; 32 bits
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_WritePassword(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPwd)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_WritePassword(pDataParams->pPalSli15693DataParams,
			bPwdIdentifier, pPwd));

	return wStatus;
}

/*
 * Performs LockPassword command. This command locks the addressed password. Note that the addressed password
 * has to be transmitted before with \ref phalICode_SetPassword. A locked password can not be changed any longer.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bPwdIdentifier      : Password Identifier.
 *                              PHAL_ICODE_SET_PASSWORD_READ
 *                              PHAL_ICODE_SET_PASSWORD_WRITE
 *                              PHAL_ICODE_SET_PASSWORD_PRIVACY
 *                              PHAL_ICODE_SET_PASSWORD_DESTROY
 *                              PHAL_ICODE_SET_PASSWORD_EAS
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_LockPassword(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_LockPassword(pDataParams->pPalSli15693DataParams,
			bPwdIdentifier));

	return wStatus;
}

/*
 * Performs Page protection command. This command changes the protection status of a page. Note that the related
 * passwords have to be transmitted before with \ref phalICode_SetPassword if the page is not public.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bPPAdd_PageNo       : Page number to be protected in case of products that do not have pages
 *                            characterized as high and Low.
 *                            Block number to be protected in case of products that have pages
 *                            characterized as high and Low.
 *      bProtectionStatus   : Protection status options for the products that do not have pages
 *                            characterized as high and Low.
 *                              0x00: PHAL_ICODE_PROTECT_PAGE_PUBLIC
 *                              0x01: PHAL_ICODE_PROTECT_PAGE_READ_WRITE_READ_PASSWORD
 *                              0x10: PHAL_ICODE_PROTECT_PAGE_WRITE_PASSWORD
 *                              0x11: PHAL_ICODE_PROTECT_PAGE_READ_WRITE_PASSWORD_SEPERATE
 *
 *                            Extended Protection status options for the products that have pages
 *                            characterized as high and Low.
 *                              0x01: PHAL_ICODE_PROTECT_PAGE_READ_LOW
 *                              0x02: PHAL_ICODE_PROTECT_PAGE_WRITE_LOW
 *                              0x10: PHAL_ICODE_PROTECT_PAGE_READ_HIGH
 *                              0x20: PHAL_ICODE_PROTECT_PAGE_WRITE_HIGH
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ProtectPage(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bPPAdd_PageNo, VAR(uint8, ANFCRL_VAR) bProtectionStatus)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
	phalICode_Int_ProtectPage(pDataParams->pPalSli15693DataParams,
			bPPAdd_PageNo, bProtectionStatus));

	return wStatus;
}

/*
 * Perform LockPageProtectionCondition command. This command permanently locks the protection status of a page.
 * Note that the related passwords have to be transmitted before with \ref phalICode_SetPassword if the page is
 * not public.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bPageNo             : Page number to be protected.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_LockPageProtectionCondition(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bPageNo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_LockPageProtectionCondition(
					pDataParams->pPalSli15693DataParams, bPageNo));

	return wStatus;
}

/*
 * Perform GetMultipleBlockProtectionStatus command. This instructs the label to return the block protection
 * status of the requested blocks.
 *
 * Remark: If bBlockNo + bNoOfBlocks exceeds the total available number of user blocks, the number of received
 * status bytes is less than the requested number. This means that the last returned status byte corresponds to the
 * highest available user block.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bBlockNo            : First Block number.
 *      bNoOfBlocks         : Number of blocks.
 *
 * Output Parameters:
 *      pProtectionStates   : Protection states of requested blocks.
 *      pNumReceivedStates  : Number of received block protection states.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetMultipleBlockProtectionStatus(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bBlockNo,
    VAR(uint8, ANFCRL_VAR) bNoOfBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProtectionStates,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumReceivedStates)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_GetMultipleBlockProtectionStatus(
					pDataParams->pPalSli15693DataParams,
					pDataParams->bBuffering, bBlockNo, bNoOfBlocks,
					pProtectionStates, pNumReceivedStates));

	return wStatus;
}

/*
 * Performs Destroy command. This command permanently destroys the label.
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
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      pXorPwd             : XOR Password; 32 bits. Pass the password for the ICODE products that supports and NULL
 *                            for the products that do not support.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_Destroy(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_Destroy(pDataParams->pPalSli15693DataParams, pXorPwd));

	return wStatus;
}

/*
 * Performs EnablePrivacy command. This command instructs the label to enter privacy mode.
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
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      pXorPwd             : XOR Password; 32 bits. Pass the password for the ICODE products that supports and NULL
 *                            for the products that do not support.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_EnablePrivacy(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_EnablePrivacy(pDataParams->pPalSli15693DataParams,
					pXorPwd));

	return wStatus;
}

/*
 * Perform 64-BitPasswordProtection command. This instructs the label that both of the Read and Write passwords
 * are required for protected access.
 *
 * Note that both the Read and Write passwords have to be transmitted before with \ref phalICode_SetPassword.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_64BitPasswordProtection(
    P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_64BitPasswordProtection(
					pDataParams->pPalSli15693DataParams));

	return wStatus;
}

/*
 * Performs ReadSignature command. On this command, the label will respond with the signature value.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Output Parameters:
 *      ppSign              : The originality signature returned by the VICC.
 *      ppSign              : Length of originality signature buffer.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ReadSignature(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSign, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSignLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ReadSignature(pDataParams->pPalSli15693DataParams,
					ppSign, pSignLen));

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
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bBlockAddr          : Configuration block address.
 *      bNoOfBlocks         : The n block(s) to read the configuration data.
 *
 * Output Parameters:
 *      ppData              : Multiple of 4 (4u * No Of Blocks) byte(s) of data read from the mentioned
 *                            configuration block address.
 *      pDataLen            : Number of received configuration data bytes.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_ReadConfig(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bBlockAddr, VAR(uint8, ANFCRL_VAR) bNoOfBlocks, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_ReadConfig(pDataParams->pPalSli15693DataParams,
					bBlockAddr, bNoOfBlocks, ppData, pDataLen));

	return wStatus;
}

/*
 * Writes a 4 byte data to the mentioned configuration block address.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      bOption             : Options to be enabled or disabled. As per ISO15693 protocol
 *                              0x00:   PHAL_ICODE_OPTION_OFF Disable option.
 *                              0x01:   PHAL_ICODE_OPTION_ON Enable option.
 *      bBlockAddr          : Configuration block address.
 *      pData               : A 4 byte data to be written to the mentioned configuration block address.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_WriteConfig(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bBlockAddr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_WriteConfig(pDataParams->pPalSli15693DataParams,
					bOption, bBlockAddr, pData));

	return wStatus;
}

/*
 * Enables the random ID generation in the tag. This interfaces is used to instruct the tag to generate
 * a random number in privacy mode.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          PH_STATUS_INPROCESS for on going operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_PickRandomID(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;

	PH_CHECK_INPROCESS_FCT(wStatus,
			phalICode_Int_PickRandomID(pDataParams->pPalSli15693DataParams));

	return wStatus;
}

/*
 * Get the configuration settings.
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      wConfig             : Configuration to read.
 *                              0x00: PHAL_ICODE_CONFIG_FLAGS
 *                              0x01: PHAL_ICODE_CONFIG_ADD_INFO
 *                              0x02: PHAL_ICODE_CONFIG_TIMEOUT_US
 *                              0x03: PHAL_ICODE_CONFIG_TIMEOUT_MS
 *                              0x04: PHAL_ICODE_CONFIG_ENABLE_BUFFERING
 *
 * Output Parameters:
 *      pValue              : The value for the mentioned configuration information in wConfig parameter.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetConfig(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0;

	/* Retrieve the configuration settings. */
	switch (wConfig) {
	case PHAL_ICODE_CONFIG_ENABLE_BUFFERING:
		*pValue = pDataParams->bBuffering;
		break;

	case PHAL_ICODE_CONFIG_FLAGS:
	case PHAL_ICODE_CONFIG_ADD_INFO:
	case PHAL_ICODE_CONFIG_TIMEOUT_US:
	case PHAL_ICODE_CONFIG_TIMEOUT_MS:
		PH_CHECK_SUCCESS_FCT(wStatus,
				phpalSli15693_GetConfig(pDataParams->pPalSli15693DataParams,
						wConfig, pValue))
		;
		break;

	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
	}

	return PH_ERR_SUCCESS;
}

/*
 * Set the configuration settings.
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *      wConfig             : Configuration to write.
 *                              0x00: PHAL_ICODE_CONFIG_FLAGS
 *                              0x04: PHAL_ICODE_CONFIG_ENABLE_BUFFERING
 *      wValue              : The value for the mentioned configuration information in wConfig parameter.
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_SetConfig(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0;

	/* Update the configuration settings. */
	switch (wConfig) {
	case PHAL_ICODE_CONFIG_ENABLE_BUFFERING:
		pDataParams->bBuffering = (uint8) wValue;
		PH_CHECK_SUCCESS_FCT(wStatus,
				phpalSli15693_SetConfig( pDataParams->pPalSli15693DataParams, PHPAL_SLI15693_CONFIG_ENABLE_BUFFERING, wValue))
		;
		break;

	case PHAL_ICODE_CONFIG_FLAGS:
		PH_CHECK_SUCCESS_FCT(wStatus,
				phpalSli15693_SetConfig(pDataParams->pPalSli15693DataParams,
						wConfig, wValue))
		;
		break;

	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_ICODE);
	}

	return PH_ERR_SUCCESS;
}

/*
 * Get the type of Tag
 *
 * Input Parameters:
 *      pDataParams         : Pointer to this layer's parameter structure.
 *
 * Output Parameters:
 *      pTagType            : The type of ICode tag.
 *                              0xFFFF: PHAL_ICODE_TAG_TYPE_UNKNOWN
 *                              0x0001: PHAL_ICODE_TAG_TYPE_ICODE_SLI
 *                              0x0002: PHAL_ICODE_TAG_TYPE_ICODE_SLI_S
 *                              0x0003: PHAL_ICODE_TAG_TYPE_ICODE_SLI_L
 *                              0x5001: PHAL_ICODE_TAG_TYPE_ICODE_SLIX
 *                              0x5002: PHAL_ICODE_TAG_TYPE_ICODE_SLIX_S
 *                              0x5003: PHAL_ICODE_TAG_TYPE_ICODE_SLIX_L
 *                              0x0801: PHAL_ICODE_TAG_TYPE_ICODE_SLI_X2
 *                              0x1801: PHAL_ICODE_TAG_TYPE_ICODE_DNA
 *                              0x5801: PHAL_ICODE_TAG_TYPE_ICODE_NTAG5_I2C
 *
 * Return:
 *          PH_ERR_SUCCESS for successful operation.
 *          Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_GetTagType(P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTagType) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0;

	PH_CHECK_SUCCESS_FCT(wStatus,
			phalICode_Int_GetTagType(pDataParams->pPalSli15693DataParams,
					pTagType));

	return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHALICODE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALICODE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_ICODE_SW */
#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */
