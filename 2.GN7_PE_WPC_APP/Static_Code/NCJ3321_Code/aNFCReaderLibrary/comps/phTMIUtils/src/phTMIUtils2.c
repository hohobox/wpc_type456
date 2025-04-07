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
*   @file    phTMIUtils2.c
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

#include <phTMIUtils2.h>

#ifdef NXPBUILD__PH_TMIUTILS2

#include <ph_Status2.h>
#include <ph_RefDefs2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTMIUtils2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHTMIUTILS_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHTMIUTILS_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHTMIUTILS_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHTMIUTILS_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHTMIUTILS_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phTMIUtils2.h header file are of the same vendor */
#if (PHTMIUTILS_VENDOR_ID_C2 != PHTMIUTILS_VENDOR_ID2)
    #error "phTMIUtils2.c and phTMIUtils2.h have different vendor ids"
#endif
/* Check if current file and phTMIUtils2.h header file are of the same Autosar version */
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C2    != PHTMIUTILS_AR_RELEASE_MAJOR_VERSION2) || \
     (PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C2    != PHTMIUTILS_AR_RELEASE_MINOR_VERSION2) || \
     (PHTMIUTILS_AR_RELEASE_REVISION_VERSION_C2 != PHTMIUTILS_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phTMIUtils2.c and phTMIUtils2.h are different"
#endif
/* Check if current file and phTMIUtils2.h header file are of the same Software version */
#if ((PHTMIUTILS_SW_MAJOR_VERSION_C2 != PHTMIUTILS_SW_MAJOR_VERSION2) || \
     (PHTMIUTILS_SW_MINOR_VERSION_C2 != PHTMIUTILS_SW_MINOR_VERSION2) || \
     (PHTMIUTILS_SW_PATCH_VERSION_C2 != PHTMIUTILS_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phTMIUtils2.c and phTMIUtils2.h are different"
#endif
#endif /* NXPBUILD__PH_TMIUTILS2 */
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
#ifdef NXPBUILD__PH_TMIUTILS2
#define ANFCRL_START_SEC_CODE
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phTMIUtils_Init2(
                           P2VAR(phTMIUtils_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMIBuffer2,
                           VAR(uint32, ANFCRL_VAR) dwBufLen2
                           )
{
    /* Check parameters */
    if ((pTMIBuffer2 == NULL) || (dwBufLen2 == 0U) || (pDataParams2 == NULL))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }
    pDataParams2->pTMIBuffer2 = pTMIBuffer2;
    pDataParams2->dwTMIBufLen2 = dwBufLen2;
    pDataParams2->dwTMIbufIndex2 = 0;
    pDataParams2->bTMIStatus2 = PH_OFF2;
    pDataParams2->dwOffsetInTMI2 = 0;

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTMIUtils_ActivateTMICollection2(
    P2VAR(phTMIUtils_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bOption2
    )
{
    if ((pDataParams2 == NULL) || (pDataParams2->dwTMIBufLen2 == 0U))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }

    switch (bOption2)
    {
    case PH_TMIUTILS_DEACTIVATE_TMI2:

        /* Deactivate TMI Collection */
        pDataParams2->dwTMIBufLen2 = 0;
        pDataParams2->dwOffsetInTMI2 = 0;
        pDataParams2->bTMIStatus2 = PH_OFF2;
        break;

    case PH_TMIUTILS_ACTIVATE_TMI2:
    case PH_TMIUTILS_RESUME_TMI2:

        /* Activate/Resume TMI collection */
        pDataParams2->bTMIStatus2 = PH_ON2;
        break;

    case PH_TMIUTILS_PAUSE_TMI2:

        /* Pause TMI collection */
        pDataParams2->bTMIStatus2 = PH_OFF2;
        break;

    case PH_TMIUTILS_RESET_TMI2:

        /* Reset TMI collection buffer index to 0 */
        pDataParams2->dwTMIbufIndex2 = 0;
        pDataParams2->dwOffsetInTMI2 = 0;
        break;

    default:
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);

    }
    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTMIUtils_GetTMI2(
                             P2VAR(phTMIUtils_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                             P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTMIBuffer2,
                             P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwTMILen2
                             )
{
    /* Check parameters */
    if(pDataParams2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }

    *ppTMIBuffer2 = pDataParams2->pTMIBuffer2;
    *dwTMILen2 = pDataParams2->dwTMIbufIndex2;

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTMIUtils_CollectTMI2(
                                 P2VAR(phTMIUtils_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                 VAR(uint8, ANFCRL_VAR) bOption2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBuff2,
                                 VAR(uint16, ANFCRL_VAR) wCmdLen2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                                 VAR(uint32, ANFCRL_VAR) dwDataLen2,
                                 VAR(uint16, ANFCRL_VAR) wBlockSize2
                                 )
{
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTmp2 = 0;

    /* Parameter check */
    if ((pCmdBuff2 == NULL) || (pData2 == NULL) || (pDataParams2 == NULL))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }
    if ((pDataParams2->dwTMIbufIndex2 + wCmdLen2 + (wBlockSize2 - (wCmdLen2 % wBlockSize2)) + dwDataLen2 + (wBlockSize2 - (dwDataLen2 % wBlockSize2))) > pDataParams2->dwTMIBufLen2)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_TMIUTILS2);
    }

    if (0U != (wCmdLen2))
    {
        /* Copy the command buffer */
        (void)memcpy(&pDataParams2->pTMIBuffer2[pDataParams2->dwTMIbufIndex2], pCmdBuff2, wCmdLen2);
        pDataParams2->dwTMIbufIndex2 += wCmdLen2;

        if ((0U != ((bOption2 & PH_TMIUTILS_ZEROPAD_CMDBUFF2))) && ((pDataParams2->dwTMIbufIndex2 % wBlockSize2) != 0U))
        {
            /* Zero padding */
            (void)memset(&pDataParams2->pTMIBuffer2[pDataParams2->dwTMIbufIndex2], 0x00, (wBlockSize2 - (pDataParams2->dwTMIbufIndex2 % wBlockSize2)));
            pDataParams2->dwTMIbufIndex2 += (wBlockSize2 - (pDataParams2->dwTMIbufIndex2 % wBlockSize2));
        }
    }
    if (0U != (bOption2 & PH_TMIUTILS_READ_INS2))
    {
        if (0U != (pDataParams2->dwOffsetInTMI2))
        {
            /* Update the Length field Offset in pDataParams2 */
            dwTmp2 = pDataParams2->pTMIBuffer2[pDataParams2->dwOffsetInTMI2 + 1U];
            dwTmp2 <<= 8U;
            dwTmp2 |= pDataParams2->pTMIBuffer2[pDataParams2->dwOffsetInTMI2];
            dwTmp2 += dwDataLen2;
            pDataParams2->pTMIBuffer2[pDataParams2->dwOffsetInTMI2] = (uint8)dwTmp2;
            pDataParams2->pTMIBuffer2[pDataParams2->dwOffsetInTMI2 + 1U] = (uint8)(dwTmp2 >> 8U);
        }
        else
        {
            /* Store the Length field Offset in pDataParams2 */
            pDataParams2->dwOffsetInTMI2 = (pDataParams2->dwTMIbufIndex2 - 11u);
        }
    }

    if (0U != (dwDataLen2))
    {
        /* Copy the command buffer */
        (void)memcpy(&pDataParams2->pTMIBuffer2[pDataParams2->dwTMIbufIndex2], pData2, dwDataLen2);
        pDataParams2->dwTMIbufIndex2 += dwDataLen2;

        if ((0U != ((bOption2 & PH_TMIUTILS_ZEROPAD_DATABUFF2))) && ((pDataParams2->dwTMIbufIndex2 % wBlockSize2) != 0U))
        {
            /* Zero padding */
            (void)memset(&pDataParams2->pTMIBuffer2[pDataParams2->dwTMIbufIndex2], 0x00, (wBlockSize2 - (pDataParams2->dwTMIbufIndex2 % wBlockSize2)));
            pDataParams2->dwTMIbufIndex2 += (wBlockSize2 - (pDataParams2->dwTMIbufIndex2 % wBlockSize2));
        }
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTMIUtils_SetConfig2(
                                P2VAR(phTMIUtils_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                VAR(uint16, ANFCRL_VAR) wConfig2,
                                VAR(uint32, ANFCRL_VAR) dwValue2
                                )
{
    /* Parameter check */
    if(pDataParams2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }

    switch (wConfig2)
    {
        case PH_TMIUTILS_TMI_OFFSET_LENGTH2:
            pDataParams2->dwOffsetInTMI2  = dwValue2;
            break;
        case PH_TMIUTILS_TMI_OFFSET_VALUE2:
            pDataParams2->pTMIBuffer2[pDataParams2->dwOffsetInTMI2] = (uint8)dwValue2;
            pDataParams2->pTMIBuffer2[pDataParams2->dwOffsetInTMI2 + 1U] = (uint8)(dwValue2 >> 8U);
            break;
        default:
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phTMIUtils_GetConfig2(
                                P2VAR(phTMIUtils_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                VAR(uint16, ANFCRL_VAR) wConfig2,
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                )
{
    /* Parameter check */
    if(pDataParams2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }

    switch (wConfig2)
    {
        case PH_TMIUTILS_TMI_STATUS2:
            *pValue2 = pDataParams2->bTMIStatus2;
            break;
        case PH_TMIUTILS_TMI_OFFSET_LENGTH2:
            *pValue2 = pDataParams2->dwOffsetInTMI2;
            break;
        case PH_TMIUTILS_TMI_BUFFER_INDEX2:
            *pValue2 = pDataParams2->dwTMIbufIndex2;
            break;
        default:
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_TMIUTILS2);
    }

    return PH_ERR_SUCCESS2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHTMIUTILS_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_TMIUTILS2 */

#ifdef __cplusplus
}
#endif
