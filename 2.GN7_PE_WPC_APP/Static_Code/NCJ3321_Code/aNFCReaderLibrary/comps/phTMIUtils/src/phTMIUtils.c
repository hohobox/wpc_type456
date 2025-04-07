/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2022 - 2023
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
*   @file    phTMIUtils.c
*   @version 1.0.0
*
*   @brief   AUTOSAR TMIUtils - Common API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phTMIUtils TMI Utilities
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

#include <phTMIUtils.h>

#ifdef NXPBUILD__PH_TMIUTILS

#include <ph_Status.h>
#include <ph_RefDefs.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTMIUtils.c
* @implements     DESIGN001, DESIGN002
*/
#define PHTMIUTILS_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHTMIUTILS_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHTMIUTILS_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHTMIUTILS_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHTMIUTILS_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phTMIUtils.h header file are of the same vendor */
#if (PHTMIUTILS_VENDOR_ID_C != PHTMIUTILS_VENDOR_ID)
    #error "phTMIUtils.c and phTMIUtils.h have different vendor ids"
#endif
/* Check if current file and phTMIUtils.h header file are of the same Autosar version */
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C    != PHTMIUTILS_AR_RELEASE_MAJOR_VERSION) || \
     (PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C    != PHTMIUTILS_AR_RELEASE_MINOR_VERSION) || \
     (PHTMIUTILS_AR_RELEASE_REVISION_VERSION_C != PHTMIUTILS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phTMIUtils.c and phTMIUtils.h are different"
#endif
/* Check if current file and phTMIUtils.h header file are of the same Software version */
#if ((PHTMIUTILS_SW_MAJOR_VERSION_C != PHTMIUTILS_SW_MAJOR_VERSION) || \
     (PHTMIUTILS_SW_MINOR_VERSION_C != PHTMIUTILS_SW_MINOR_VERSION) || \
     (PHTMIUTILS_SW_PATCH_VERSION_C != PHTMIUTILS_SW_PATCH_VERSION))
    #error "Software Version Numbers of phTMIUtils.c and phTMIUtils.h are different"
#endif
#endif /* NXPBUILD__PH_TMIUTILS */
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
#ifdef NXPBUILD__PH_TMIUTILS
#define ANFCRL_START_SEC_CODE
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_Init(
                           P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMIBuffer,
                           VAR(uint32, ANFCRL_VAR) dwBufLen
                           )
{
    /* Check parameters */
    if ((pTMIBuffer == NULL) || (dwBufLen == 0U) || (pDataParams == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }
    pDataParams->pTMIBuffer = pTMIBuffer;
    pDataParams->dwTMIBufLen = dwBufLen;
    pDataParams->dwTMIbufIndex = 0;
    pDataParams->bTMIStatus = PH_OFF;
    pDataParams->dwOffsetInTMI = 0;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_ActivateTMICollection(
    P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption
    )
{
    if ((pDataParams == NULL) || (pDataParams->dwTMIBufLen == 0U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }

    switch (bOption)
    {
    case PH_TMIUTILS_DEACTIVATE_TMI:

        /* Deactivate TMI Collection */
        pDataParams->dwTMIBufLen = 0;
        pDataParams->dwOffsetInTMI = 0;
        pDataParams->bTMIStatus = PH_OFF;
        break;

    case PH_TMIUTILS_ACTIVATE_TMI:
    case PH_TMIUTILS_RESUME_TMI:

        /* Activate/Resume TMI collection */
        pDataParams->bTMIStatus = PH_ON;
        break;

    case PH_TMIUTILS_PAUSE_TMI:

        /* Pause TMI collection */
        pDataParams->bTMIStatus = PH_OFF;
        break;

    case PH_TMIUTILS_RESET_TMI:

        /* Reset TMI collection buffer index to 0 */
        pDataParams->dwTMIbufIndex = 0;
        pDataParams->dwOffsetInTMI = 0;
        break;

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);

    }
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_GetTMI(
                             P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                             P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTMIBuffer,
                             P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwTMILen
                             )
{
    /* Check parameters */
    if(pDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }

    *ppTMIBuffer = pDataParams->pTMIBuffer;
    *dwTMILen = pDataParams->dwTMIbufIndex;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_CollectTMI(
                                 P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint8, ANFCRL_VAR) bOption,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBuff,
                                 VAR(uint16, ANFCRL_VAR) wCmdLen,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                 VAR(uint32, ANFCRL_VAR) dwDataLen,
                                 VAR(uint16, ANFCRL_VAR) wBlockSize
                                 )
{
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTmp = 0;

    /* Parameter check */
    if ((pCmdBuff == NULL) || (pData == NULL) || (pDataParams == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }
    if ((pDataParams->dwTMIbufIndex + wCmdLen + (wBlockSize - (wCmdLen % wBlockSize)) + dwDataLen + (wBlockSize - (dwDataLen % wBlockSize))) > pDataParams->dwTMIBufLen)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_TMIUTILS);
    }

    if (0U != (wCmdLen))
    {
        /* Copy the command buffer */
        (void)memcpy(&pDataParams->pTMIBuffer[pDataParams->dwTMIbufIndex], pCmdBuff, wCmdLen);
        pDataParams->dwTMIbufIndex += wCmdLen;

        if ((0U != ((bOption & PH_TMIUTILS_ZEROPAD_CMDBUFF))) && ((pDataParams->dwTMIbufIndex % wBlockSize) != 0U))
        {
            /* Zero padding */
            (void)memset(&pDataParams->pTMIBuffer[pDataParams->dwTMIbufIndex], 0x00, (wBlockSize - (pDataParams->dwTMIbufIndex % wBlockSize)));
            pDataParams->dwTMIbufIndex += (wBlockSize - (pDataParams->dwTMIbufIndex % wBlockSize));
        }
    }
    if (0U != (bOption & PH_TMIUTILS_READ_INS))
    {
        if (0U != (pDataParams->dwOffsetInTMI))
        {
            /* Update the Length field Offset in pDataParams */
            dwTmp = pDataParams->pTMIBuffer[pDataParams->dwOffsetInTMI + 1U];
            dwTmp <<= 8U;
            dwTmp |= pDataParams->pTMIBuffer[pDataParams->dwOffsetInTMI];
            dwTmp += dwDataLen;
            pDataParams->pTMIBuffer[pDataParams->dwOffsetInTMI] = (uint8)dwTmp;
            pDataParams->pTMIBuffer[pDataParams->dwOffsetInTMI + 1U] = (uint8)(dwTmp >> 8U);
        }
        else
        {
            /* Store the Length field Offset in pDataParams */
            pDataParams->dwOffsetInTMI = (pDataParams->dwTMIbufIndex - 11u);
        }
    }

    if (0U != (dwDataLen))
    {
        /* Copy the command buffer */
        (void)memcpy(&pDataParams->pTMIBuffer[pDataParams->dwTMIbufIndex], pData, dwDataLen);
        pDataParams->dwTMIbufIndex += dwDataLen;

        if ((0U != ((bOption & PH_TMIUTILS_ZEROPAD_DATABUFF))) && ((pDataParams->dwTMIbufIndex % wBlockSize) != 0U))
        {
            /* Zero padding */
            (void)memset(&pDataParams->pTMIBuffer[pDataParams->dwTMIbufIndex], 0x00, (wBlockSize - (pDataParams->dwTMIbufIndex % wBlockSize)));
            pDataParams->dwTMIbufIndex += (wBlockSize - (pDataParams->dwTMIbufIndex % wBlockSize));
        }
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_SetConfig(
                                P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                VAR(uint32, ANFCRL_VAR) dwValue
                                )
{
    /* Parameter check */
    if(pDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }

    switch (wConfig)
    {
        case PH_TMIUTILS_TMI_OFFSET_LENGTH:
            pDataParams->dwOffsetInTMI  = dwValue;
            break;
        case PH_TMIUTILS_TMI_OFFSET_VALUE:
            pDataParams->pTMIBuffer[pDataParams->dwOffsetInTMI] = (uint8)dwValue;
            pDataParams->pTMIBuffer[pDataParams->dwOffsetInTMI + 1U] = (uint8)(dwValue >> 8U);
            break;
        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_GetConfig(
                                P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                )
{
    /* Parameter check */
    if(pDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }

    switch (wConfig)
    {
        case PH_TMIUTILS_TMI_STATUS:
            *pValue = pDataParams->bTMIStatus;
            break;
        case PH_TMIUTILS_TMI_OFFSET_LENGTH:
            *pValue = pDataParams->dwOffsetInTMI;
            break;
        case PH_TMIUTILS_TMI_BUFFER_INDEX:
            *pValue = pDataParams->dwTMIbufIndex;
            break;
        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_TMIUTILS);
    }

    return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_TMIUTILS */

#ifdef __cplusplus
}
#endif
