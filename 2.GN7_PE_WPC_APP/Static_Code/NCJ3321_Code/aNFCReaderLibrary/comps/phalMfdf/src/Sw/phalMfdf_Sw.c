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
*   @file    phalMfdf_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdf_Sw - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdf MIFARE DESFire (R)
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
#include <ph_TypeDefs.h>
#include <string.h>
#include <phTools.h>
#include <phKeyStore.h>

#ifdef NXPBUILD__PH_CRYPTOSYM
#include <phCryptoSym.h>
#endif /* NXPBUILD__PH_CRYPTOSYM */
#ifdef NXPBUILD__PH_CRYPTORNG
#include <phCryptoRng.h>
#endif /* NXPBUILD__PH_CRYPTORNG */

#ifdef NXPBUILD__PHAL_MFDF_SW

#include "../phalMfdf_Int.h"
#include "phalMfdf_Sw.h"
#include "phalMfdf_Sw_Int.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdf_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDF_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALMFDF_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDF_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALMFDF_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALMFDF_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALMFDF_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalMfdf_Sw.h header file are of the same vendor */
#if (PHALMFDF_SW_VENDOR_ID_C != PHALMFDF_SW_VENDOR_ID)
    #error "phalMfdf_Sw.c and phalMfdf_Sw.h have different vendor ids"
#endif
/* Check if current file and phalMfdf_Sw.h header file are of the same Autosar version */
#if ((PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION_C    != PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHALMFDF_SW_AR_RELEASE_MINOR_VERSION_C    != PHALMFDF_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHALMFDF_SW_AR_RELEASE_REVISION_VERSION_C != PHALMFDF_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdf_Sw.c and phalMfdf_Sw.h are different"
#endif
/* Check if current file and phalMfdf_Sw.h header file are of the same Software version */
#if ((PHALMFDF_SW_SW_MAJOR_VERSION_C != PHALMFDF_SW_SW_MAJOR_VERSION) || \
     (PHALMFDF_SW_SW_MINOR_VERSION_C != PHALMFDF_SW_SW_MINOR_VERSION) || \
     (PHALMFDF_SW_SW_PATCH_VERSION_C != PHALMFDF_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdf_Sw.c and phalMfdf_Sw.h are different"
#endif
#endif /* NXPBUILD__PHAL_MFDF_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_MFDF_SW
#define PH_CHECK_ERROR_UPDATE_STATE(status,stateVar,stateVal) 	if ((uint16)((status) & 0xFFU) != PH_ERR_SUCCESS) {stateVar = (stateVal); return (status);}
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALMFDF_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) bMfdfSwGetVersionState = 0u;
static VAR(uint8, ANFCRL_VAR) bMfdfSwSendDataToPICCState = 0u;
static VAR(uint8, ANFCRL_VAR) bMfdfSwGetDataState = 0u;
static VAR(uint8, ANFCRL_VAR) bMfdfSwWritePlainState = 0u;
static VAR(uint8, ANFCRL_VAR) bMfdfSwIsoReadState = 0u;
static VAR(uint8, ANFCRL_VAR) bMfdfSwSend7816ApduState = 0u;
static VAR(uint8, ANFCRL_VAR) bMfdfSwExchangeState = 0u;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALMFDF_SW_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDF_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Init(
                            P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                            VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsEnc,
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams,
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                            )
{
    /* data param check */
    if (sizeof(phalMfdf_Sw_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
    }
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pPalMifareDataParams);


    /* init private data */
    pDataParams->wId                    = PH_COMP_AL_MFDF | PHAL_MFDF_SW_ID;
    pDataParams->pPalMifareDataParams   = pPalMifareDataParams;
    pDataParams->pKeyStoreDataParams    = pKeyStoreDataParams;
    pDataParams->pCryptoDataParamsEnc   = pCryptoDataParamsEnc;
    pDataParams->pCryptoRngDataParams   = pCryptoRngDataParams;
    pDataParams->bLastBlockIndex        = 0;
    pDataParams->pHalDataParams  = pHalDataParams;
    /* 2 Byte CRC initial value in Authenticate mode. */
    pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;

    /* 4 Byte CRC initial value in 0x1A, 0xAA mode. */
    pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8;

    (void)memset(pDataParams->bSessionKey, 0x00, 24);
    pDataParams->bKeyNo = 0xFF; /* Set to invalid */
    (void)memset(pDataParams->bIv, 0x00, 16);
    (void)memset(pDataParams->pAid, 0x00, 3);
    pDataParams->bAuthMode = PHAL_MFDF_NOT_AUTHENTICATED; /* Set to invalid */
    pDataParams->bWrappedMode = 0x00; /* Set to FALSE */
    pDataParams->bCryptoMethod = 0xFF; /* No crypto just after init */
    pDataParams->wAdditionalInfo = 0x0000;
    pDataParams->wPayLoadLen = 0;

	bMfdfSwGetVersionState = 0u;
	bMfdfSwSendDataToPICCState = 0U;
	bMfdfSwGetDataState = 0U;
	bMfdfSwWritePlainState = 0u;
	bMfdfSwIsoReadState = 0U;
	bMfdfSwSend7816ApduState = 0u;
	bMfdfSwExchangeState = 0u;
    return PH_ERR_SUCCESS;
}


/**
* PICC level commands
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_CreateApplication(
    P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,
    VAR(uint8, ANFCRL_VAR) bKeySettings1,
    VAR(uint8, ANFCRL_VAR) bKeySettings2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,
    VAR(uint8, ANFCRL_VAR) bISODFNameLen
    )
{
    /*
    If (0U != (bKeySettings2 & 0x03U))== 00 [DES, 3DES] then pDataParams->bAuthMode can be either
    0x0A or 0x1A.
    If (0U != (bKeySettings2 & 0x03U))== 01 [3K3DES] then pDataParams->bAuthMode can only be 0x1A.
    If (0U != (bKeySettings2 & 0x03U))== 10 [AES] then pDataParams->bAuthMode can only be 0xAA.
    */
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[32];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0u;

    if ((bISODFNameLen > 16U) || (bOption > 0x03U) || (bOption == 0x02U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
    }


    if (bMfdfSwWritePlainState == 0u)
    {
    	wCmdLen = 0u;
		/* form the command */
		bCmdBuff[wCmdLen++] = PHAL_MFDF_CMD_CREATE_APPLN;

		(void)memcpy(&bCmdBuff[wCmdLen], pAid, 3);
		wCmdLen += 3U;

		bCmdBuff[wCmdLen++] = bKeySettings1;
		bCmdBuff[wCmdLen++] = bKeySettings2;

		if (0U != (bOption & 0x01U))
		{
			/* wISOFileId is present */
			bCmdBuff[wCmdLen++] = pISOFileId[0];
			bCmdBuff[wCmdLen++] = pISOFileId[1];
		}
		if (0U != (bOption & 0x02U))
		{
			/* pISODFName is present */
			(void)memcpy(&bCmdBuff[wCmdLen], pISODFName, bISODFNameLen);
			wCmdLen = wCmdLen + bISODFNameLen;
		}
    }

    return phalMfdf_Sw_Int_Write_Plain(
        pDataParams,
        bCmdBuff,
        wCmdLen,
        PHAL_MFDF_COMMUNICATION_PLAIN,
        NULL,
        0x0000
        );
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_SelectApplication(
    P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAppId
    )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[10] = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0u;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
    VAR(uint8, ANFCRL_VAR) exchangeState = GetAlMfdfExchangeState();

    if (exchangeState == 0u)
    {
		/* form the command */
		bCmdBuff[0] = PHAL_MFDF_CMD_SELECT_APPLN;
		(void)memcpy(&bCmdBuff[1], pAppId, PHAL_MFDF_DFAPPID_SIZE);
		wCmdLen = PHAL_MFDF_DFAPPID_SIZE + 1U;
    }
    /* Send the command */
    PH_CHECK_SUCCESS_FCT(status, phalMfdf_ExchangeCmd(
        pDataParams,
        pDataParams->pPalMifareDataParams,
        pDataParams->bWrappedMode,
        bCmdBuff,
        wCmdLen,
        &pRecv,
        &wRxlen
        ));
    /* Store the currently selected application Id */
    (void)memcpy(pDataParams->pAid, pAppId, 3);
    /* Select command never returns CMAC */
    return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_GetVersion(
                                  P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[20];
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0u;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0u;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxTotalLen = 0u;

	/* form the command */
	if (bMfdfSwGetVersionState == 0u)
	{
		wRxTotalLen = 0u;
		bMfdfSwGetVersionState = 1u;
	}
	if (bMfdfSwGetVersionState == 2u)
	{
		bCmdBuff[wCmdLen++] = PHAL_MFDF_RESP_ADDITIONAL_FRAME;
	}
	else
	{
		bCmdBuff[wCmdLen++] = PHAL_MFDF_CMD_GET_VERSION;
	}
	status = phalMfdf_Sw_Int_ReadData_Plain(pDataParams,
		PH_EXCHANGE_DEFAULT,
        bCmdBuff,
        wCmdLen,
        &pRecv,
        &wRxlen
        );
    if (status == PH_STATUS_INPROCESS)
	{
		return PH_STATUS_INPROCESS;
	}

    if ((wRxTotalLen + wRxlen) > 28U)
    {
        bMfdfSwGetVersionState = 0u;
        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
    }
    if(wRxlen > 0U)
    {
        (void)memcpy(&pResponse[wRxTotalLen], pRecv, (size_t)wRxlen);
        wRxTotalLen += wRxlen;
    }
    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
    {
    	bMfdfSwGetVersionState = 2u;
    	return PH_STATUS_INPROCESS;
    }
    bMfdfSwGetVersionState = 0u;
    if (wRxTotalLen != 28U)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
    }

    return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_CreateStdDataFile(
    P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,
    VAR(uint8, ANFCRL_VAR) bCommSett,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize
    )
{
    /*
    If (0U != (bKeySettings2 & 0x03U))== 00 [DES, 3DES] then pDataParams->bAuthMode can be either
    0x0A or 0x1A.
    If (0U != (bKeySettings2 & 0x03U))== 01 [3K3DES] then pDataParams->bAuthMode can only be 0x1A.
    If (0U != (bKeySettings2 & 0x03U))== 10 [AES] then pDataParams->bAuthMode can only be 0xAA.
    */
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[32];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0u;

    if ((bFileNo > 0x1fU) || (bOption > 0x01U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
    }


#if !defined (NXPBUILD__PH_NDA_MFDF)

    if (bCommSett != PHAL_MFDF_COMMUNICATION_PLAIN)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
    }

#endif /* NXPBUILD__PH_NDA_MFDF */

    if (bMfdfSwWritePlainState == 0u)
    {
    	wCmdLen = 0u;
		/* form the command */
		bCmdBuff[wCmdLen++] = PHAL_MFDF_CMD_CREATE_STD_DATAFILE;

		/* File Number */
		bCmdBuff[wCmdLen++] = bFileNo;

		/* Copy ISO Filed ID if present */
		if (bOption == 0x01U)
		{
			bCmdBuff[wCmdLen++] = pISOFileId[0];
			bCmdBuff[wCmdLen++] = pISOFileId[1];
		}

		/* Copy communication settings. communication settings in the first nibble so right shifting */
		bCmdBuff[wCmdLen++] = bCommSett >> 4U;

		/* Copy Access rights */
		bCmdBuff[wCmdLen++] = pAccessRights[0];
		bCmdBuff[wCmdLen++] = pAccessRights[1];

		/* Copy File size supplied by the user */
		(void)memcpy(&bCmdBuff[wCmdLen], pFileSize, 3);
		wCmdLen += 3U;
    }
    /* COMMUNICATION IS PLAIN */
    return phalMfdf_Sw_Int_Write_Plain(pDataParams,
        bCmdBuff,
        wCmdLen,
        PHAL_MFDF_COMMUNICATION_PLAIN,
        NULL,
        0x0000
        );
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_WriteData(
                                 P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint8, ANFCRL_VAR) bCommOption,
                                 VAR(uint8, ANFCRL_VAR) bFileNo,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen
                                 )
{
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[16];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen = 0u;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0u;

    if (bFileNo > 0x1fU)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
    }


#if !defined (NXPBUILD__PH_NDA_MFDF)

    if (bCommOption != PHAL_MFDF_COMMUNICATION_PLAIN)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_MFDF);
    }

#endif /* NXPBUILD__PH_NDA_MFDF */

    if (bMfdfSwWritePlainState == 0u)
    {
    	wCmdLen = 0u;
		/* form the command */
		bCmdBuff[wCmdLen++] = PHAL_MFDF_CMD_WRITE_DATA;
		bCmdBuff[wCmdLen++] = bFileNo;
		(void)memcpy(&bCmdBuff[wCmdLen], pOffset, 3u);
		wCmdLen += 3U;
		(void)memcpy(&bCmdBuff[wCmdLen], pDataLen, 3u);
		wCmdLen += 3U;

		/* Assuming here that the size can never go beyond FFFF.
		In fact it can never go beyond 8092 (1F9C) bytes */
		wDataLen = (uint16)pDataLen[1];
		wDataLen = wDataLen << 8U;
		wDataLen |= pDataLen[0];

		if (pDataParams->bAuthMode == PHAL_MFDF_NOT_AUTHENTICATED)
		{
			bCommOption = PHAL_MFDF_COMMUNICATION_PLAIN;
		}
    }

#if !defined (NXPBUILD__PH_NDA_MFDF)

	return phalMfdf_Sw_Int_Write_Plain(
		pDataParams,
		bCmdBuff,
		wCmdLen,
		bCommOption,
		pData,
		wDataLen
		);
#else
	PHAL_MFDF_UNUSED_VARIABLE(pData)
	PHAL_MFDF_UNUSED_VARIABLE(bCommOption)
	/* If control reaches here, it's a case of mismatch between NDA/NON NDA flavour */
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_MFDF);;
#endif /* NXPBUILD__PH_NDA_MFDF */
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_IsoSelectFile(
                                     P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint8, ANFCRL_VAR) bOption,
                                     VAR(uint8, ANFCRL_VAR) bSelector,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,
                                     VAR(uint8, ANFCRL_VAR) bDFnameLen,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRecv,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwRxlen
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bData[24];
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLc = 0u;


    if (bMfdfSwSend7816ApduState == 0u)
    {

		if (bDFnameLen > 16U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
		}
		if ((bOption != 0x00U) && (bOption != 0x0CU))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
		}

		switch(bSelector)
		{
		case 0x00:
		case 0x02:
			/* Selection by EF Id*/
			/* Send MSB first to card */
			bData[0] = pFid[1];
			bData[1] = pFid[0];
			bLc = 2;
			break;

		case 0x04:
			/* Selection by DF Name */
			(void)memcpy(bData, pDFname, bDFnameLen);
			bLc = bDFnameLen;
			break;

		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
		}
    }

    PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdf_Int_Send7816Apdu(
        pDataParams,
        pDataParams->pPalMifareDataParams,
        (bOption == 0x0CU) ? 0x01U : 0x03U,             /* As per Table 40-P2 in ISO/IEC FDIS 7816-4 */
        PHAL_MFDF_CMD_ISO7816_SELECT_FILE,
        bSelector,
        bOption,
        bLc,
        bData,
        0x00,
        ppRecv,
        pwRxlen));

    /* ISO wrapped mode is on */
    pDataParams->bWrappedMode = 1;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_IsoReadBinary(
                                     P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wOption,
                                     VAR(uint8, ANFCRL_VAR) bOffset,
                                     VAR(uint8, ANFCRL_VAR) bSfid,
                                     VAR(uint8, ANFCRL_VAR) bBytesToRead,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead
                                     )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bP1 = 0u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bP2 = 0u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLe = 0u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[8];
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0u;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    status = phhalHw_Exchange_GetStatus();

    if ((status == PH_ERR_SUCCESS) || (status == PH_ERR_IO_TIMEOUT))
    {

		if (wOption == PH_EXCHANGE_DEFAULT)
		{
			if (0U != (bSfid & 0x80U))
			{
				/* Short file id is supplied */
				if ((bSfid & 0x7FU) > 0x1FU)
				{
					/* Error condition */
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
				}
			}
			/* P1 and P2 code the offset */
			bP1 = bSfid;
			bP2 = bOffset;
			bLe = bBytesToRead;
			bCmdBuff[wCmdLen++] = 0x00; /* Class */
			bCmdBuff[wCmdLen++] = PHAL_MFDF_CMD_ISO7816_READ_BINARY; /* Ins */
			bCmdBuff[wCmdLen++] = bP1;
			bCmdBuff[wCmdLen++] = bP2;
			bCmdBuff[wCmdLen++] = bLe; /* Le */
		}
		else if (wOption == PH_EXCHANGE_RXCHAINING)
		{
			wCmdLen = 0u;
		}
		else
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
		}
    }

    return phalMfdf_Sw_Int_IsoRead(
        pDataParams,
        wOption,
        bCmdBuff,
        wCmdLen,
        ppRxBuffer,
        pBytesRead
        );
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_IsoUpdateBinary(
                                       P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint8, ANFCRL_VAR) bOffset,
                                       VAR(uint8, ANFCRL_VAR) bSfid,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                       VAR(uint8, ANFCRL_VAR) bDataLen
                                       )

{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bP1 = 0u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bP2 = 0u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLc = 0u;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    if (0U != (bSfid & 0x80U))
    {
        /* Short file id is supplied */
        if ((bSfid & 0x7FU) > 0x1FU)
        {
            /* Error condition */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDF);
        }
        bP2 = bOffset;
    }
    else
    {
        /* P1 and P2 code the offset */
        bP1 = bSfid;
        bP2 = bOffset;
    }

    bLc = bDataLen;
    status = phalMfdf_Int_Send7816Apdu(
        pDataParams,
        pDataParams->pPalMifareDataParams,
        0x01,
        PHAL_MFDF_CMD_ISO7816_UPDATE_BINARY,
        bP1,
        bP2,
        bLc,
        pData,
        0x00,
        NULL,
        NULL);


    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_GetConfig(
                                 P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wConfig,
                                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                 )
{
    switch (wConfig)
    {
    case PHAL_MFDF_ADDITIONAL_INFO:
        *pValue = pDataParams->wAdditionalInfo;
        break;

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_MFDF);
    }
    return PH_ERR_SUCCESS;
}
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_SetConfig(
                                 P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wConfig,
                                 VAR(uint16, ANFCRL_VAR) wValue
                                 )
{
    switch (wConfig)
    {
    case PHAL_MFDF_ADDITIONAL_INFO:
        pDataParams->wAdditionalInfo = wValue;
        break;

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_MFDF);
    }
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Int_GetData(
                                   P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wOption,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff,
                                   VAR(uint16, ANFCRL_VAR) wCmdLen,
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen
                                   )
{
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStatusByte = 0xFFU;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[10] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNextPos = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferSize = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackupBytes[3] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] = { PHAL_MFDF_WRAPPEDAPDU_CLA, 0x00U, PHAL_MFDF_WRAPPEDAPDU_P1, PHAL_MFDF_WRAPPEDAPDU_P2, 0x00U };
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpByte0 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpByte1 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpByte3 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBackUpLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;

	switch (bMfdfSwGetDataState)
	{
		case 0U:
			/* Status and two other bytes to be backed up before getting new frame of data */
			(void)memset(bBackupBytes, 0x00, 3U);

			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
				&wTmp
				));
			bMfdfSwGetDataState = 1U;
			/* No break */
		case 1U:
			if (0U != (pDataParams->bWrappedMode))
			{
				if (wCmdLen > PHAL_MFDF_MAXWRAPPEDAPDU_SIZE)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDF);
				}
				pApdu[1] = pSendBuff[0];  /* Desfire command code. */
				/* Encode APDU Length*/
				pApdu[4]= (uint8)wCmdLen - 1u; /* Set APDU Length. */

				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					(pApdu[4] == 0x00U) ? PH_EXCHANGE_DEFAULT : PH_EXCHANGE_BUFFER_FIRST,
					pApdu,
					PHAL_MFDF_WRAP_HDR_LEN,
					&pRecv,
					pRxlen
					));
				if ((pApdu[4] != 0x00U) && (statusTmp == PH_ERR_SUCCESS))
				{
					bMfdfSwGetDataState = 2U;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					status = statusTmp;
					bMfdfSwGetDataState = 4U;
					return PH_STATUS_INPROCESS;
				}
			}
			else
			{
				bMfdfSwGetDataState = 6U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&pSendBuff[1],
				wCmdLen - 1u,
				&pRecv,
				pRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwGetDataState = 3U;
			return PH_STATUS_INPROCESS;
		case 3U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				&pApdu[2],
				0x01,
				&pRecv,
				pRxlen
				));
			status = statusTmp;
			bMfdfSwGetDataState = 4U;
			return PH_STATUS_INPROCESS;
		case 4U:
			/* To handle the case where the card returns only status 91 and returns
			AF in the next frame */
			statusTmp = status;
			if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				if (((0U != (pDataParams->bWrappedMode)) && (*pRxlen == 2U)) ||
					((0U==(pDataParams->bWrappedMode)) && (*pRxlen == 1U)))
				{
					/* AF should always be accompanied by data. Otherwise
					it is a protocol error */
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
					break;
				}
				/* One more status byte to read from DesFire */
				bBackUpByte0 = pRecv[0];
				bBackUpByte1 = pRecv[1];
				wBackUpLen = *pRxlen;

				status = statusTmp;
				bMfdfSwGetDataState = 5U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				PH_BREAK_ON_FAILURE(statusTmp);
				bMfdfSwGetDataState = 7U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 5U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_RXCHAINING,
				&pApdu[2],
				0x01,
				&pRecv,
				pRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);

			/* Received length can be one or two Ex: 0x91 0xAF */
			if (*pRxlen == 2U)
			{
				pRecv[wBackUpLen] = pRecv[0];
				pRecv[wBackUpLen + 1U] = pRecv[1];
				bStatusByte = pRecv[1];
			}
			else if (*pRxlen == 1U)
			{
				bStatusByte = pRecv[0];
				pRecv[wBackUpLen] = bStatusByte;
			}
			else
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
				break;
			}

			*pRxlen = wBackUpLen + *pRxlen;

			/* Set back the backed up bytes */
			pRecv[0] = bBackUpByte0;
			pRecv[1] = bBackUpByte1;
			bMfdfSwGetDataState = 7U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 6U:
			/* Normal mode */
			if (wCmdLen > PHAL_MFDF_MAXDFAPDU_SIZE)
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDF);
				break;
			}

			/* Send this on L4 */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				wOption,
				pSendBuff,
				wCmdLen,
				&pRecv,
				pRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwGetDataState = 7U;
			return PH_STATUS_INPROCESS;
		case 7U:
			/* Storing the original pointer */
			*pResponse = pRecv;

			/* Status is 0xAF or Ox00? */
			if (*pRxlen > 0x0000U)
			{
				if (0U != (pDataParams->bWrappedMode))
				{
					bStatusByte = (*pResponse)[(*pRxlen) - 1U];
				}
				else
				{
					bStatusByte = (*pResponse)[wTmp];
				}
			}

			if (bStatusByte == PHAL_MFDF_RESP_ADDITIONAL_FRAME)
			{
				if (((pDataParams->bWrappedMode > 0U) && (*pRxlen == 2U)) ||
					((!(pDataParams->bWrappedMode > 0U)) && (*pRxlen == 1U)))
				{
					/* AF should always be accompanied by data. Otherwise
					it is a protocol error */
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
					break;
				}

				if (0U != (pDataParams->bWrappedMode))
				{
					/* Next position will ensure overwriting on the
					SW1SW2 received from previous command */
					wNextPos = (*pRxlen) - 2U;
					(void)memcpy(bBackupBytes, &(*pResponse)[wNextPos - 3u], 3U);
				}
				else
				{
					/* Backup the last byte */
					bBackUpByte3 = (*pResponse)[(*pRxlen - 1U)];
					(void)memcpy(bBackupBytes, &(*pResponse)[(*pRxlen - 3U)], 3U);
					wNextPos = (*pRxlen) - 1U;
				}

				PH_CHECK_FAILURE_FCT(statusTmp,phhalHw_GetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE,
					&wRxBufferSize
					));
			}
			bMfdfSwGetDataState = 8U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 8U:
			if(bStatusByte == PHAL_MFDF_RESP_ADDITIONAL_FRAME)
			{
				if (((pDataParams->bWrappedMode > 0U) && (*pRxlen == 2U)) ||
					((!(pDataParams->bWrappedMode > 0U)) && (*pRxlen == 1U)))
				{
					/* AF should always be accompanied by data. Otherwise
					it is a protocol error */
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
					break;
				}
				if ((wNextPos + PHAL_MFDF_MAX_FRAME_SIZE) >= wRxBufferSize)
				{
					/* Return 0xAF and let the caller recall the function with
					option = PH_EXCHANGE_RXCHAINING */
					/* Return the data accumulated till now and its length */
					if (0U != (pDataParams->bWrappedMode))
					{
						(*pRxlen) -= 2u;
					}
					else
					{
						(*pRxlen) -= 1u;
						(*pResponse)++;
					}
					return PH_ADD_COMPCODE_FIXED(PH_ERR_SUCCESS_CHAINING, PH_COMP_AL_MFDF);
				}
				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					wNextPos
					));
				bCmdBuff[0] = PHAL_MFDF_RESP_ADDITIONAL_FRAME;
				wCmdLen = 1;
				if ( 0U != (pDataParams->bWrappedMode) )
				{
					pApdu[1] = bCmdBuff[0];  /* MIFARE DESFire command code. */
					/* Encode APDU Length*/
					pApdu[4]= (uint8_t)wCmdLen - 1u; /* Set APDU Length. */
					bMfdfSwGetDataState = 9U;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					bMfdfSwGetDataState = 14U;
					return PH_STATUS_INPROCESS;
				}
			}
			else
			{
				bMfdfSwGetDataState = 16U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 9U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				(pApdu[4] == 0x00U) ? PH_EXCHANGE_DEFAULT : PH_EXCHANGE_BUFFER_FIRST,
				pApdu,
				PHAL_MFDF_WRAP_HDR_LEN,
				&pRecv,
				pRxlen
				));
			if ((pApdu[4] != 0x00U) && (statusTmp == PH_ERR_SUCCESS))
			{
				bMfdfSwGetDataState = 10U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				status = statusTmp;
				bMfdfSwGetDataState = 12U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 10U:
			wCmdLen = 1;
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				pRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwGetDataState = 11U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 11U:
			bCmdBuff[0] = 0x00U; /* Le */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				0x01,
				&pRecv,
				pRxlen
				));
			status = statusTmp;
			bMfdfSwGetDataState = 12U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 12U:
			statusTmp = status;
			/* To handle the case where the card returns only status 91 and returns
			AF in the next frame */
			if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				/* One or two more status bytes to read from MIFARE DESFire */
				bBackUpByte0 = pRecv[0];
				bBackUpByte1 = pRecv[1];
				wBackUpLen = *pRxlen;

				bMfdfSwGetDataState = 13U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				PH_BREAK_ON_FAILURE(statusTmp);
				bMfdfSwGetDataState = 15U;
				return PH_STATUS_INPROCESS;
			}
		case 13U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_RXCHAINING,
				&pApdu[2],
				0x01,
				&pRecv,
				pRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);

			/* Received length can be one or two Ex: 0x91 0xAF */
			if (*pRxlen == 2U)
			{
				pRecv[wBackUpLen] = pRecv[0];
				pRecv[wBackUpLen + 1U] = pRecv[1];
			}
			else if (*pRxlen == 1U)
			{
				bStatusByte = pRecv[0];
				pRecv[wBackUpLen] = bStatusByte;
			}
			else
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
			}

			*pRxlen = wBackUpLen + *pRxlen;

			/* Set back the backed up bytes */
			pRecv[0] = bBackUpByte0;
			pRecv[1] = bBackUpByte1;
			bMfdfSwGetDataState = 15U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 14U:
			/* Send this on L4 */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				wOption,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				pRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwGetDataState = 15U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 15U:
			/* Update wNextPos */
			if (0U != (pDataParams->bWrappedMode))
			{
				bStatusByte = (*pResponse)[(*pRxlen) - 1U];

				/* Putback the backed up bytes */
				(void)memcpy(&(*pResponse)[wNextPos - 3u], bBackupBytes, 3);

				wNextPos = (*pRxlen) - 2U;
				(void)memcpy(bBackupBytes, &(*pResponse)[wNextPos - 3u], 3);
			}
			else
			{
				bStatusByte = (*pResponse)[wNextPos];

				/* Put back the previously backedup byte */
				(*pResponse)[wNextPos] = bBackUpByte3;

				/* Putback the backed up bytes */
				(void)memcpy(&(*pResponse)[wNextPos - 2u], bBackupBytes, 3);

				wNextPos = (*pRxlen) - 1U;
				bBackUpByte3 = (*pResponse)[wNextPos];

				/* Backup 3 bytes. The nxt frame will overwrite these */
				(void)memcpy(bBackupBytes, &(*pResponse)[wNextPos - 2u], 3);
			}
			bMfdfSwGetDataState = 8U;
			return PH_STATUS_INPROCESS;
		case 16U:
			if (0U != (pDataParams->bWrappedMode))
			{
				(*pRxlen) -= 2u;
			}
			else
			{
				(*pRxlen) -= 1u;
				(*pResponse)++;
			}
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}
	bMfdfSwGetDataState = 0U;
	PH_CHECK_SUCCESS(statusTmp);
	status = PH_ERR_SUCCESS;
	for(uint8 i = 0U; i < 10U; i++)
	{
		bCmdBuff[i] = 0U;
	}
	wNextPos = 0U;
	wRxBufferSize = 0U;
	pApdu[0] = PHAL_MFDF_WRAPPEDAPDU_CLA;
	pApdu[1] = 0U;
	pApdu[2] = PHAL_MFDF_WRAPPEDAPDU_P1;
	pApdu[3] = PHAL_MFDF_WRAPPEDAPDU_P2;
	pApdu[4] = 0U;
	bBackUpByte0 = 0U;
	bBackUpByte1 = 0U;
	bBackUpByte3 = 0U;
	wBackUpLen = 0U;
	return phalMfdf_Int_ComputeErrorResponse(pDataParams, bStatusByte);
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Int_ReadData_Plain(
    P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen
    )
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM status = 0u;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0u;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;


    /* Send the command */
    status = phalMfdf_Sw_Int_GetData(
        pDataParams,
		bOption,
        bCmdBuff,
        wCmdLen,
        &pRecv,
        &wRxlen
        );

    if (status == PH_STATUS_INPROCESS)
	{
		return PH_STATUS_INPROCESS;
	}

    if (((status & PH_ERR_MASK) != PH_ERR_SUCCESS) &&
        ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
    {

        return status;
    }


    *ppRxdata = pRecv;
    *pRxdataLen = wRxlen;

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_SUCCESS_CHAINING, PH_COMP_AL_MFDF);;
    }

    return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Int_Write_Plain(
                                       P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
                                       VAR(uint16, ANFCRL_VAR) wCmdLen,
                                       VAR(uint8, ANFCRL_VAR) bCommOption,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                       VAR(uint16, ANFCRL_VAR) wDataLen
                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bWorkBuffer[32];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTotalLen = 0u;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;

	PHAL_MFDF_UNUSED_VARIABLE(bCommOption)

    if (bMfdfSwWritePlainState == 0u)
    {
		(void)memset(bWorkBuffer, 0x00, 16u);
		bMfdfSwWritePlainState = 1u;
#ifndef NXPBUILD__PH_NDA_MFDF
		wTotalLen = wDataLen;
#else
		wTotalLen = 0U;
#endif /* NXPBUILD__PH_NDA_MFDF */
    }
	if (wTotalLen == 0x0000U)
	{
		/* Single frame cmd without any data. Just send it */
		status = phalMfdf_ExchangeCmd(
			pDataParams,
			pDataParams->pPalMifareDataParams,
			pDataParams->bWrappedMode,
			bCmdBuff,
			wCmdLen,
			&pRecv,
			&wRxlen
			);
		if (status == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		bMfdfSwWritePlainState = 0u;
		if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
		{
			return PH_ADD_COMPCODE(status, PH_COMP_AL_MFDF);
		}

		/* TBD: SA */
		if (wRxlen > 32U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
		}

		if(wRxlen > 0U)
		{
			(void)memcpy(bWorkBuffer, pRecv,(size_t) wRxlen);
		}
	}
	else
	{
		/* Send command and data. Chain data to PICC */
		status = phalMfdf_Sw_Int_SendDataToPICC(
			pDataParams,
			bCmdBuff,
			wCmdLen,
			pData,
			wDataLen,
			bWorkBuffer,
			&wRxlen
			);
		if (status == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}
		bMfdfSwWritePlainState = 0u;
	}

	#ifndef NXPBUILD__PH_NDA_MFDF
		/* Should not get more bytes than the status bytes in case
		of no authentication */
		if (wRxlen > 0U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
		}

	#endif /* NXPBUILD__PH_NDA_MFDF */
    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Int_SendDataToPICC(
	P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmd,
	VAR(uint16, ANFCRL_VAR) wCmdLen,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
	VAR(uint16, ANFCRL_VAR) wDataLen,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen
	)
{
	/* Utility function to send encrypted data to PICC as and when it is available from SAM */
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStatusByte = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] =
	{PHAL_MFDF_WRAPPEDAPDU_CLA, 0x00U, PHAL_MFDF_WRAPPEDAPDU_P1, PHAL_MFDF_WRAPPEDAPDU_P2, 0x00U};
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM wCmdLenTmp = 0U;

	switch(bMfdfSwSendDataToPICCState)
	{
		case 0U:
			if (0U != (pDataParams->bWrappedMode))
			{
				wFrameLen = PHAL_MFDF_MAXWRAPPEDAPDU_SIZE;
			}
			else
			{
				wFrameLen = PHAL_MFDF_MAXDFAPDU_SIZE;
			}

			wCmdLenTmp = 0U;
			bStatusByte = 0U;
			/* Send the data to PICC */
			wIndex = 0;
			wTmp = wDataLen;
			bMfdfSwSendDataToPICCState = 1U;
			/* No break */
		case 1U:
			if(0U != wCmdLenTmp)
			{
				wCmdLen = wCmdLenTmp;
			}
			wLen = (wTmp < (wFrameLen - wCmdLen))? wTmp : (wFrameLen - wCmdLen);
			if (0U != (pDataParams->bWrappedMode))
			{
				pApdu[1] = pCmd[0]; /* MIFARE DESFire cmd code in INS */
				pApdu[4] = (uint8_t)(wCmdLen + wLen) - 0x01u;
				bMfdfSwSendDataToPICCState = 2U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				bMfdfSwSendDataToPICCState = 6U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				pApdu,
				PHAL_MFDF_WRAP_HDR_LEN,
				&pRecv,
				pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSendDataToPICCState = 3U;
			/* No break */
		case 3U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&pCmd[1],
				wCmdLen - 1u,
				&pRecv,
				pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSendDataToPICCState = 4U;
			/* No break */
		case 4U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT,
					&pData[wIndex],
					wLen,
					&pRecv,
					pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSendDataToPICCState = 5U;
			/* No break */
		case 5U:
			/* Le byte */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					&pApdu[2],
					0x01,
					&pRecv,
					pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSendDataToPICCState = 8U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 6U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_FIRST,
					pCmd,
					wCmdLen,
					&pRecv,
					pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSendDataToPICCState = 7U;
			/* No break */
		case 7U:
			PH_CHECK_SUCCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					&pData[wIndex],
					wLen,
					&pRecv,
					pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSendDataToPICCState = 8U;
			/* No break */
		case 8U:
			wIndex = wIndex + wLen;
			wTmp = wTmp - wLen;

			if (0U != (pDataParams->bWrappedMode))
			{
				if(((uint32_t)(*pRespLen)) > 2U)
				{
					(void)memcpy(pResp, pRecv, ((uint32_t)(*pRespLen) - 2U));
				}
				bStatusByte = pRecv[(*pRespLen) - 1U];
				(*pRespLen) -= 2u;
			}
			else
			{
				if(((uint32_t)(*pRespLen)) > 1U)
				{
					(void)memcpy(pResp, &pRecv[1], ((uint32_t)(*pRespLen) - 1U));
				}
				bStatusByte = pRecv[0];
				(*pRespLen) -= 1u;
			}

			if ((bStatusByte != PHAL_MFDF_RESP_ADDITIONAL_FRAME) &&
			(bStatusByte != PH_ERR_SUCCESS))
			{

				statusTmp = phalMfdf_Int_ComputeErrorResponse(pDataParams, bStatusByte);
				break;
			}

			/* Success returned even before writing all data? protocol error */
			if ((bStatusByte == PH_ERR_SUCCESS) && (wTmp != 0U))
			{

				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDF);
				break;
			}

			if(bStatusByte != 0x00U)
			{
				pCmd[0] = PHAL_MFDF_RESP_ADDITIONAL_FRAME;
				wCmdLenTmp = 1U;
			}

			if(0U != wTmp)
			{
				bMfdfSwSendDataToPICCState = 1U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Do nothing */
			}
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}

	wCmdLenTmp = 0U;
	wIndex = 0U;
	wTmp = 0U;
	wLen = 0U;
	pApdu[0] = PHAL_MFDF_WRAPPEDAPDU_CLA;
	pApdu[1] = 0U;
	pApdu[2] = PHAL_MFDF_WRAPPEDAPDU_P1;
	pApdu[3] = PHAL_MFDF_WRAPPEDAPDU_P2;
	pApdu[4] = 0U;
	pRecv = NULL;
	bMfdfSwSendDataToPICCState = 0U;
	PH_CHECK_SUCCESS(statusTmp);
	return phalMfdf_Int_ComputeErrorResponse(pDataParams, bStatusByte);
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Int_IsoRead(
	P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wOption,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
	VAR(uint16, ANFCRL_VAR) wCmdLen,
	P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead
	)
{
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferSize = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNextPos = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackupBytes[3] = {0U};

	switch (bMfdfSwIsoReadState)
	{
		case 0u:
			PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				wOption,
				bCmdBuff,
				wCmdLen,
				ppRxBuffer,
				pBytesRead
				));
			/* First put everything on the reader Rx buffer upto buffer size - 60 */

			pRecv = *ppRxBuffer;

			if ((status != PH_ERR_SUCCESS) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
				return status;
			}
			else
			{
				bMfdfSwIsoReadState = 1U;
			}
			/* No break */
		case 1u:
			if((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_GetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE,
						&wRxBufferSize
				));

				wNextPos = *pBytesRead;
				(void)memcpy(bBackupBytes, &pRecv[wNextPos - 3u], 3);

				if ((wNextPos + PHAL_MFDF_MAX_FRAME_SIZE) >= wRxBufferSize)
				{
					/* Calculate partical cmac if authenticated and return PH_ERR_SUCCESS_CHAINING */
					break;
				}

				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
						wNextPos
				));

				bMfdfSwIsoReadState = 2U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				bMfdfSwIsoReadState = 3U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_RXCHAINING,
				bCmdBuff,
				wCmdLen,
				ppRxBuffer,
				pBytesRead
			));
			/* Put back the backed up bytes */
			(void)memcpy(&pRecv[wNextPos - 3u], bBackupBytes, 3);

			if ((status != PH_ERR_SUCCESS) &&
				((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
				break;
			}
			else
			{
				bMfdfSwIsoReadState = 1U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 3U:
			if (status == PH_ERR_SUCCESS)
			{
				statusTmp = (*ppRxBuffer)[*pBytesRead - 2U]; /* SW1 */
				statusTmp = statusTmp << 8U; /* Shift SW1 to MSB */
				statusTmp |= (*ppRxBuffer)[*pBytesRead - 1U]; /* SW2 */

				if (pDataParams->bAuthMode == PHAL_MFDF_NOT_AUTHENTICATED)
				{
					*pBytesRead -= 2U;
					statusTmp = phalMfdf_Int_ComputeErrorResponse(pDataParams, statusTmp);
					break;
				}

				statusTmp = phalMfdf_Int_ComputeErrorResponse(pDataParams, statusTmp);
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			else
			{
				/* Do nothing */
			}
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}

	wRxBufferSize = 0U;
	wNextPos = 0U;
	pRecv = NULL;
	bBackupBytes[0] = 0U;
	bBackupBytes[1] = 0U;
	bBackupBytes[2] = 0U;
	bMfdfSwIsoReadState = 0U;
	PH_CHECK_SUCCESS(statusTmp);
	return PH_ADD_COMPCODE_FIXED(status, PH_COMP_AL_MFDF);
}

FUNC(uint8, ANFCRL_CODE)	GetAlMfdfExchangeState(void)
{
	return bMfdfSwExchangeState;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Int_ComputeErrorResponse(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wStatus
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

    switch (wStatus)
    {
    case PHAL_MFDF_RESP_OPERATION_OK:
    case PHAL_MFDF_ISO7816_SUCCESS:
        status = PH_ERR_SUCCESS;
        break;

    case PHAL_MFDF_RESP_NO_CHANGES:
        status = PHAL_MFDF_NO_CHANGES;
        break;

    case PHAL_MFDF_RESP_ERR_OUT_OF_EEPROM_ERROR:
        status = PHAL_MFDF_ERR_OUT_OF_EEPROM_ERROR;
        break;


    case PHAL_MFDF_RESP_ERR_PARAMETER_ERROR:
        status = PHAL_MFDF_ERR_PARAMETER_ERROR;
        break;


    case PHAL_MFDF_RESP_ERR_LENGTH_ERROR:
        status = PH_ERR_LENGTH_ERROR;
        break;

    case PHAL_MFDF_RESP_PERMISSION_DENIED:
        status = PHAL_MFDF_ERR_PERMISSION_DENIED;
        break;

    case PHAL_MFDF_RESP_APPLICATION_NOT_FOUND:
        status = PHAL_MFDF_ERR_APPLICATION_NOT_FOUND;
        break;


    case PHAL_MFDF_RESP_ADDITIONAL_FRAME:
        status = PH_ERR_SUCCESS_CHAINING;
        break;

    case PHAL_MFDF_RESP_ERR_BOUNDARY_ERROR:
        status = PHAL_MFDF_ERR_BOUNDARY_ERROR;
        break;

    case PHAL_MFDF_RESP_ERR_COMMAND_ABORTED:
        status = PHAL_MFDF_ERR_COMMAND_ABORTED;
        break;

    case PHAL_MFDF_RESP_ERR_COUNT:
        status = PHAL_MFDF_ERR_COUNT;
        break;

    case PHAL_MFDF_RESP_ERR_DUPLICATE:
        status = PHAL_MFDF_ERR_DUPLICATE;
        break;

    case PHAL_MFDF_RESP_ERR_FILE_NOT_FOUND:
        status = PHAL_MFDF_ERR_FILE_NOT_FOUND;
        break;

    case PHAL_MFDF_RESP_ERR_APPL_INTEGRITY_ERROR:
    case PHAL_MFDF_RESP_ERR_PICC_INTEGRITY:
    case PHAL_MFDF_RESP_ERR_EEPROM:
    case PHAL_MFDF_RESP_ERR_FILE_INTEGRITY:
    case PHAL_MFDF_RESP_ERR_PIC_DISABLED:
    case PHAL_MFDF_RESP_ILLEGAL_COMMAND_CODE:
        status = PHAL_MFDF_ERR_DF_GEN_ERROR;
        PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdf_SetConfig(
            pDataParams,
            PHAL_MFDF_ADDITIONAL_INFO,
            wStatus));
        break;

    case PHAL_MFDF_ISO7816_ERR_WRONG_LENGTH:
    case PHAL_MFDF_ISO7816_ERR_WRONG_LE:
    case PHAL_MFDF_ISO7816_ERR_FILE_NOT_FOUND:
    case PHAL_MFDF_ISO7816_ERR_WRONG_PARAMS:
    case PHAL_MFDF_ISO7816_ERR_WRONG_LC:
    case PHAL_MFDF_ISO7816_ERR_NO_PRECISE_DIAGNOSTICS:
    case PHAL_MFDF_ISO7816_ERR_EOF_REACHED:
    case PHAL_MFDF_ISO7816_ERR_FILE_ACCESS:
    case PHAL_MFDF_ISO7816_ERR_FILE_EMPTY:
    case PHAL_MFDF_ISO7816_ERR_MEMORY_FAILURE:
    case PHAL_MFDF_ISO7816_ERR_INCORRECT_PARAMS:
    case PHAL_MFDF_ISO7816_ERR_WRONG_CLA:
    case PHAL_MFDF_ISO7816_ERR_UNSUPPORTED_INS:
        status = PHAL_MFDF_ERR_DF_7816_GEN_ERROR;
        PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdf_SetConfig(
            pDataParams,
            PHAL_MFDF_ADDITIONAL_INFO,
            wStatus));
        break;

    default:
        status = PH_ERR_PROTOCOL_ERROR;
    }
    return PH_ADD_COMPCODE(status, PH_COMP_AL_MFDF);
}

/*
*
* Should take care of wrapping and unwrapping if ISO 7816 Wrapped mode
* Does not handle any chaining or CMAC generation/verification or encryption/decryption
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ExchangeCmd(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,
                                VAR(uint8, ANFCRL_VAR) bWrappedMode,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff,
                                VAR(uint16, ANFCRL_VAR) wCmdLen,
                                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppResponse,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen
                                )
{
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStatusByte = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] =
	{PHAL_MFDF_WRAPPEDAPDU_CLA, 0x00U, PHAL_MFDF_WRAPPEDAPDU_P1, PHAL_MFDF_WRAPPEDAPDU_P2, 0x00U};

	switch (bMfdfSwExchangeState)
	{
		case 0u:
			bStatusByte = 0U;
			if (0U != (bWrappedMode))
			{
				wFrameLen = PHAL_MFDF_MAXWRAPPEDAPDU_SIZE;
			}
			else
			{
				wFrameLen = PHAL_MFDF_MAXDFAPDU_SIZE;
			}

			if (wCmdLen > wFrameLen)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDF);
			}

			/* Send the data to PICC */
			if (0U != (bWrappedMode))
			{
				pApdu[1] = pSendBuff[0]; /* Desfire cmd code in INS */
				pApdu[4] = (uint8)(wCmdLen) - 0x01u;

				bMfdfSwExchangeState = 1U;
			}
			else
			{
				bMfdfSwExchangeState = 4U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 1u:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					(pApdu[4] == 0x00U) ? PH_EXCHANGE_DEFAULT : PH_EXCHANGE_BUFFER_FIRST,
					pApdu,
					PHAL_MFDF_WRAP_HDR_LEN,
					&pRecv,
					pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			if (pApdu[4] != 0x00U)
			{
				bMfdfSwExchangeState = 2U;
			}
			else
			{

			}
			/* No break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT,
					&pSendBuff[1],
					wCmdLen - 1u,
					&pRecv,
					pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwExchangeState = 3U;
			/* No break */
		case 3U:
			/* Le byte */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					&pApdu[2], /* Le is always zero in wrapped mode. */
					0x01,
					&pRecv,
					pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwExchangeState = 5U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 4U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					PH_EXCHANGE_DEFAULT,
					pSendBuff,
					wCmdLen,
					&pRecv,
					pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			/* No break */
		case 5U:
			if (0U != (bWrappedMode))
			{
				/* memcpy(pResponse, pRecv, (*pRxlen) - 2); PRQA S 3200 */
				*ppResponse = pRecv;
				wFrameLen = *pRxlen - 1U;
				bStatusByte = pRecv[wFrameLen];
				(*pRxlen) -= 2u;
			}
			else
			{
				/* memcpy(pResponse, &pRecv[1], (*pRxlen) - 1);  PRQA S 3200 */
				*ppResponse = &pRecv[1];
				bStatusByte = pRecv[0];
				(*pRxlen) -= 1u;
			}
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}

	pRecv = NULL;
	pApdu[0] = PHAL_MFDF_WRAPPEDAPDU_CLA;
	pApdu[1] = 0U;
	pApdu[2] = PHAL_MFDF_WRAPPEDAPDU_P1;
	pApdu[3] = PHAL_MFDF_WRAPPEDAPDU_P2;
	pApdu[4] = 0U;
	bMfdfSwExchangeState = 0U;
	PH_CHECK_SUCCESS(statusTmp);
	return phalMfdf_Int_ComputeErrorResponse(pDataParams, bStatusByte);
}

/*
* Should return SW1+SW2
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Int_Send7816Apdu(
								P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
								P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,
								VAR(uint8, ANFCRL_VAR) bOption,
								VAR(uint8, ANFCRL_VAR) bIns,
								VAR(uint8, ANFCRL_VAR) bP1,
								VAR(uint8, ANFCRL_VAR) bP2,
								VAR(uint8, ANFCRL_VAR) bLc,
								P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn,
								VAR(uint8, ANFCRL_VAR) bLe,
								P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut,
								P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen
								)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[20] = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;

	switch (bMfdfSwSend7816ApduState)
	{
		case 0u:
			bCmdBuff[wCmdLen++] = 0x00; /* Class is always 0x00 */
			bCmdBuff[wCmdLen++] = bIns;
			bCmdBuff[wCmdLen++] = bP1;
			bCmdBuff[wCmdLen++] = bP2;

			if (0U != (bOption & 0x01U))
			{
				bCmdBuff[wCmdLen++] = bLc;
			}
			bMfdfSwSend7816ApduState = 1U;
			/* No break */
		case 1U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_FIRST,
					bCmdBuff,
					wCmdLen,
					&pRecv,
					&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);
			if ((0U != ((bOption & 0x01U))) && (bLc > 0U))
			{
				bMfdfSwSend7816ApduState = 2U;
			}
			else
			{
				bMfdfSwSend7816ApduState = 3U;
				return PH_STATUS_INPROCESS;
			}
			/* No break */
		case 2U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT,
					pDataIn,
					bLc,
					&pRecv,
					&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);
			bMfdfSwSend7816ApduState = 3U;
			/* No break */
		case 3U:
			wCmdLen = 0;
			if (0U != (bOption & 0x02U))
			{
				bCmdBuff[wCmdLen++] = bLe;
			}
			bMfdfSwSend7816ApduState = 4U;
			/* No break */
		case 4U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					bCmdBuff,
					wCmdLen,
					&pRecv,
					&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);
			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];

			PH_CHECK_FAILURE_FCT(statusTmp, phalMfdf_Int_ComputeErrorResponse(pDataParams, statusTmp));

			if (pDataLen != NULL)
			{
				*pDataLen = wRxlen -2u;
			}

			if (ppDataOut != NULL)
			{
				*ppDataOut = pRecv;
			}
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}

	for(uint8 i = 0U; i < 20U; i++)
	{
		bCmdBuff[i] = 0U;
	}
	wCmdLen = 0U;
	pRecv = NULL;
	bMfdfSwSend7816ApduState = 0U;
	return statusTmp;
}


#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDF_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDF_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDF_SW */

#ifdef __cplusplus
}
#endif
