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
*   @file    phKeyStore_Ncx3320.c
*   @version 1.0.0
*
*   @brief   AUTOSAR KeyStore_Ncx3320 - API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phKeyStore KeyStore
*   @ingroup phcommon
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
#include <phhalHw.h>
#include <phKeyStore.h>

#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
#include "phKeyStore_Ncx3320.h"
#include "phKeyStore_Ncx3320_Int.h"
#include <phhalHw_Ncx3320_Reg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phKeyStore_Ncx3320.c
* @implements     DESIGN001, DESIGN002
*/
#define PHKEYSTORE_NCX3320_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHKEYSTORE_NCX3320_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHKEYSTORE_NCX3320_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHKEYSTORE_NCX3320_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHKEYSTORE_NCX3320_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHKEYSTORE_NCX3320_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHKEYSTORE_NCX3320_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phKeyStore_Ncx3320.h header file are of the same vendor */
#if (PHKEYSTORE_NCx3320_VENDOR_ID_C != PHKEYSTORE_NCx3320_VENDOR_ID)
    #error "phKeyStore_Ncx3320.c and phKeyStore_Ncx3320.h have different vendor ids"
#endif
/* Check if current file and phKeyStore_Ncx3320.h header file are of the same Autosar version */
#if ((PHKEYSTORE_NCX3320_AR_RELEASE_MAJOR_VERSION_C    != PHKEYSTORE_NCX3320_AR_RELEASE_MAJOR_VERSION) || \
     (PHKEYSTORE_NCX3320_AR_RELEASE_MINOR_VERSION_C    != PHKEYSTORE_NCX3320_AR_RELEASE_MINOR_VERSION) || \
     (PHKEYSTORE_NCX3320_AR_RELEASE_REVISION_VERSION_C != PHKEYSTORE_NCX3320_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phKeyStore_Ncx3320.c and phKeyStore_Ncx3320.h are different"
#endif
/* Check if current file and phKeyStore_Ncx3320.h header file are of the same Software version */
#if ((PHKEYSTORE_NCX3320_SW_MAJOR_VERSION_C != PHKEYSTORE_NCX3320_SW_MAJOR_VERSION) || \
     (PHKEYSTORE_NCX3320_SW_MINOR_VERSION_C != PHKEYSTORE_NCX3320_SW_MINOR_VERSION) || \
     (PHKEYSTORE_NCX3320_SW_PATCH_VERSION_C != PHKEYSTORE_NCX3320_SW_PATCH_VERSION))
    #error "Software Version Numbers of phKeyStore_Ncx3320.c and phKeyStore_Ncx3320.h are different"
#endif
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */
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
#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
#define ANFCRL_START_SEC_CODE
#if ((PHKEYSTORE_NCX3320_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHKEYSTORE_NCX3320_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_Init(
                                    P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                                    )
{
    /* pDataParams structure check */
    if (sizeof(phKeyStore_Ncx3320_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
    }
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pHalDataParams);

    /* Init private data */
    pDataParams->wId = PH_COMP_KEYSTORE| PH_KEYSTORE_NCx3320_ID;
    pDataParams->pHalDataParams = pHalDataParams;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_FormatKeyEntry(
    P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wNewKeyType
    )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF bKey[PH_KEYSTORE_KEY_TYPE_MIFARE_SIZE];

    /* clear key buffer */
    (void)memset(bKey, 0x00, PH_KEYSTORE_KEY_TYPE_MIFARE_SIZE);

    return phKeyStore_Ncx3320_SetKeyAtPos(pDataParams, wKeyNo, 0, wNewKeyType, bKey, 0);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_SetKey(
                                   P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wKeyNo,
                                   VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                   VAR(uint16, ANFCRL_VAR) wKeyType,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                   VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                   )
{
    UNUSED(wKeyVersion);
    return (phKeyStore_Ncx3320_SetKeyAtPos(pDataParams, wKeyNo, 0, wKeyType, pNewKey, wNewKeyVersion));
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_SetKeyAtPos(
                                        P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint16, ANFCRL_VAR) wKeyNo,
                                        VAR(uint16, ANFCRL_VAR) wPos,
                                        VAR(uint16, ANFCRL_VAR) wKeyType,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                        VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                        )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF bKeyNoInt;

    UNUSED(wPos);
    UNUSED(wNewKeyVersion);

    /* Check if wKeyNo is out of range */
    if (wKeyNo >= PH_KEYSTORE_NCx3320_NUM_KEYS)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* Retrieve Key type */
    switch(wKeyType)
    {
        /* MIFARE keys are the only supported keys */
        case PH_KEYSTORE_KEY_TYPE_MIFARE:

            /* prepare the command to be sent */
            bKeyNoInt = (uint8)(wKeyNo << 1U);

            PH_CHECK_INPROCESS_FCT(statusTmp, phKeyStore_Ncx3320_StoreKeyE2_Int(
                pDataParams,
                bKeyNoInt,
                pNewKey,
                2));
            PH_CHECK_SUCCESS(statusTmp);

            break;

    case PH_KEYSTORE_KEY_TYPE_AES128:
    case PH_KEYSTORE_KEY_TYPE_AES192:
    case PH_KEYSTORE_KEY_TYPE_AES256:
    case PH_KEYSTORE_KEY_TYPE_DES:
    case PH_KEYSTORE_KEY_TYPE_2K3DES:
    case PH_KEYSTORE_KEY_TYPE_3K3DES:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_SetKUC(
                                   P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wKeyNo,
                                   VAR(uint16, ANFCRL_VAR) wRefNoKUC
                                   )
{
    UNUSED(pDataParams);
    UNUSED(wKeyNo);
    UNUSED(wRefNoKUC);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_SetFullKeyEntry(
    P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wNoOfKeys,
    VAR(uint16, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wNewRefNoKUC,
    VAR(uint16, ANFCRL_VAR) wNewKeyType,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeys,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeyVersionList
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyVersion = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT i = 0;

    UNUSED(wNewRefNoKUC);
    UNUSED(pNewKeyVersionList);
    static VAR(uint8, ANFCRL_VAR) bSetFullKeyEntryState = PHKEYSTORE_NCX3320_IDLE;
    switch(bSetFullKeyEntryState)
    {
        case PHKEYSTORE_NCX3320_IDLE:
            i = 0;
            /* check wNoOfKeys */
            if (wNoOfKeys > PH_KEYSTORE_NCx3320_NUM_VERSIONS)
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
            }
            /* No break */
        case PHKEYSTORE_NCX3320_CMD1:
            if(i < wNoOfKeys)
            {
                bSetFullKeyEntryState = PHKEYSTORE_NCX3320_CMD2;
            }
            else
            {
                statusTmp = PH_ERR_SUCCESS;
                break;
            }
            /* No break */
        case PHKEYSTORE_NCX3320_CMD2:
            PH_CHECK_INPROCESS_FCT(statusTmp, phKeyStore_Ncx3320_SetKeyAtPos(pDataParams, wKeyNo,  i, wNewKeyType, &pNewKeys[(i*PH_KEYSTORE_KEY_TYPE_MIFARE_SIZE)], wKeyVersion));
            if(statusTmp == PH_ERR_SUCCESS)
            {
                i++;
                bSetFullKeyEntryState = PHKEYSTORE_NCX3320_CMD1;
                return PH_STATUS_INPROCESS;
            }
            break;

    }
    bSetFullKeyEntryState = PHKEYSTORE_NCX3320_IDLE;
    return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_GetKeyEntry(
                                        P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint16, ANFCRL_VAR) wKeyNo,
                                        VAR(uint16, ANFCRL_VAR) wKeyVersionBufSize,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersion,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersionLength,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                        )
{
    UNUSED(pDataParams);
    UNUSED(wKeyNo);
    UNUSED(wKeyVersionBufSize);
    UNUSED(wKeyVersion);
    UNUSED(wKeyVersionLength);
    UNUSED(pKeyType);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_GetKey(
                                   P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wKeyNo,
                                   VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                   VAR(uint8, ANFCRL_VAR) bKeyBufSize,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                   )
{
    UNUSED(pDataParams);
    UNUSED(wKeyNo);
    UNUSED(wKeyVersion);
    UNUSED(bKeyBufSize);
    UNUSED(pKey);
    UNUSED(pKeyType);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_SetConfig(
                                      P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wConfig,
                                      VAR(uint16, ANFCRL_VAR) wValue
                                      )
{
    UNUSED(pDataParams);
    UNUSED(wConfig);
    UNUSED(wValue);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_SetConfigStr(
    P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wConfig,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer,
    VAR(uint16, ANFCRL_VAR) wBufferLength
    )
{
    UNUSED(pDataParams);
    UNUSED(wConfig);
    UNUSED(pBuffer);
    UNUSED(wBufferLength);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_GetConfig(
                                      P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wConfig,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                      )
{
    UNUSED(pDataParams);
    UNUSED(wConfig);
    UNUSED(pValue);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_GetConfigStr(
    P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wConfig,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppBuffer,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBufferLength
    )
{
    UNUSED(pDataParams);
    UNUSED(wConfig);
    UNUSED(ppBuffer);
    UNUSED(pBufferLength);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_ChangeKUC(
                                      P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wRefNoKUC,
                                      VAR(uint32, ANFCRL_VAR) dwLimit
                                      )
{
    UNUSED(pDataParams);
    UNUSED(wRefNoKUC);
    UNUSED(dwLimit);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_GetKUC(
                                   P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wRefNoKUC,
                                   P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwLimit,
                                   P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwCurVal
                                   )
{
    UNUSED(pDataParams);
    UNUSED(wRefNoKUC);
    UNUSED(pdwLimit);
    UNUSED(pdwCurVal);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_StoreKeyE2_Int(
    P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bKeyNumber,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
    VAR(uint8, ANFCRL_VAR) bNumKeys
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRegValue;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT wIndex;
    static VAR(uint8, ANFCRL_VAR) bKeyStoreState = PHKEYSTORE_NCX3320_IDLE;

    switch(bKeyStoreState)
    {
        case PHKEYSTORE_NCX3320_IDLE:
            /* clear all IRQ0 flags */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
                pDataParams->pHalDataParams,
                PH_KEYSTORE_NCx3320_REG_IRQ0,
                (uint8)~(uint8)PH_KEYSTORE_NCx3320_BIT_IRQ_SET));

            /* clear all IRQ1 flags */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
                pDataParams->pHalDataParams,
                PH_KEYSTORE_NCx3320_REG_IRQ1,
                (uint8)~(uint8)PH_KEYSTORE_NCx3320_BIT_IRQ_SET));

            /* Stop an eventual previous Command (enter Idle state) */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(
                pDataParams->pHalDataParams,
                PH_KEYSTORE_NCx3320_REG_COMMAND,
                PH_KEYSTORE_NCx3320_CMD_IDLE
                ));

            /* Flush Ncx3320 fifo */
            /* Read FIFO Control register*/
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams->pHalDataParams, PH_KEYSTORE_NCx3320_REG_FIFOCONTROL, &bRegValue));

            /* Set FlushFifo bit */
            bRegValue |= PH_KEYSTORE_NCx3320_BIT_FLUSHFIFO;

            /* Write to FIFO Control register */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams->pHalDataParams, PH_KEYSTORE_NCx3320_REG_FIFOCONTROL, bRegValue));

            /* Write the Key number */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams->pHalDataParams, PH_KEYSTORE_NCx3320_REG_FIFODATA, bKeyNumber));

            /* Write each single key byte */
            for (wIndex = 0; wIndex < ((uint16)bNumKeys * PH_KEYSTORE_KEY_TYPE_MIFARE_SIZE); ++wIndex)
            {
                PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams->pHalDataParams, PH_KEYSTORE_NCx3320_REG_FIFODATA, pKey[wIndex]));
            }

            /* start the command */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_WriteRegister(pDataParams->pHalDataParams, PH_KEYSTORE_NCx3320_REG_COMMAND, PH_KEYSTORE_NCx3320_CMD_STOREKEYE2));
            bKeyStoreState = PHKEYSTORE_NCX3320_CMD1;
            /* No break */

        case PHKEYSTORE_NCX3320_CMD1:
            /* wait for the EE programming to be finished */
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Wait(pDataParams->pHalDataParams, PHHAL_HW_TIME_MILLISECONDS, (uint16)(PH_KEYSTORE_NCx3320_EEP_WR_TO_MS * (uint16)bNumKeys)));
            bKeyStoreState = PHKEYSTORE_NCX3320_IDLE;
            PH_BREAK_ON_FAILURE(statusTmp);
            /* read the error register */
            PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3320_ReadRegister(pDataParams->pHalDataParams, PHHAL_HW_NCx3320_REG_ERROR, &bRegValue));

            /* check for EEPROM error */
            if (0U != (bRegValue & PHHAL_HW_NCx3320_BIT_EE_ERR))
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_READ_WRITE_ERROR, PH_COMP_KEYSTORE);
            }
        }
    return statusTmp;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_NCX3320_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHKEYSTORE_NCX3320_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */

#ifdef __cplusplus
}
#endif
