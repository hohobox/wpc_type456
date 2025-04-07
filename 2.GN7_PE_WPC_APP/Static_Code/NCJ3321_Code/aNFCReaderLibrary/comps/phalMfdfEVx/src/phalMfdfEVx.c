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
*   @file    phalMfdfEVx.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdfEVx - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdfEVx MIFARE DESFire EVx
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

/***************************************************************************************START******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <phalMfdfEVx.h>
#include <ph_Status.h>
#include <ph_TypeDefs.h>

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
#include "Sw/phalMfdfEVx_Sw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdfEVx.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDFEVX_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALMFDFEVX_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDFEVX_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALMFDFEVX_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALMFDFEVX_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALMFDFEVX_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and PHALMFDFEVX.h header file are of the same vendor */
#if (PHALMFDFEVX_VENDOR_ID_C != PHALMFDFEVX_VENDOR_ID)
    #error "PHALMFDFEVX.c and PHALMFDFEVX.h have different vendor ids"
#endif
/* Check if current file and PHALMFDFEVX.h header file are of the same Autosar version */
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION_C    != PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION) || \
     (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION_C    != PHALMFDFEVX_AR_RELEASE_MINOR_VERSION) || \
     (PHALMFDFEVX_AR_RELEASE_REVISION_VERSION_C != PHALMFDFEVX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of PHALMFDFEVX.c and PHALMFDFEVX.h are different"
#endif
/* Check if current file and PHALMFDFEVX.h header file are of the same Software version */
#if ((PHALMFDFEVX_SW_MAJOR_VERSION_C != PHALMFDFEVX_SW_MAJOR_VERSION) || \
     (PHALMFDFEVX_SW_MINOR_VERSION_C != PHALMFDFEVX_SW_MINOR_VERSION) || \
     (PHALMFDFEVX_SW_PATCH_VERSION_C != PHALMFDFEVX_SW_PATCH_VERSION))
    #error "Software Version Numbers of PHALMFDFEVX.c and PHALMFDFEVX.h are different"
#endif
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */
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
#ifdef NXPBUILD__PHAL_MFDFEVX

#define ANFCRL_START_SEC_CODE
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/* MIFARE DESFire EVx secure messaging related commands. ------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Authenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bDivLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    }

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_Authenticate((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wKeyNo, wKeyVer,
                bKeyNoCard, pDivInput, bDivLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticateISO(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen)
{
    /**
    * The key type can be DES, 3DES, 3K3DES.
    * Random numbers can be 8 or 16 bytes long
    * Init vector can be 8 or 16 bytes long
    * Session key max size is 24 bytes if 3k3DES keys  are used.
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if (0U != (bDivLen)) PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_AuthenticateISO((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wKeyNo, wKeyVer,
                bKeyNoCard, pDivInput, bDivLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticateAES(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen)
{
    /**
    * The key type can be AES only.
    * Random numbers are 16 bytes long
    * Init vector is 16 bytes long
    * Session key size is 16 bytes.
    *
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if (0U != (bDivLen)) PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_AuthenticateAES((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wKeyNo, wKeyVer,
                bKeyNoCard, pDivInput, bDivLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticateEv2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFirstAuth, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer,
    VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen, VAR(uint8, ANFCRL_VAR) bLenPcdCapsIn, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bPcdCapsIn, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bPcdCapsOut,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bPdCapsOut)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if (0U != (bDivLen)) PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    if(0U != (bLenPcdCapsIn))  PH_ASSERT_NULL_PARAM(bPcdCapsIn, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_AuthenticateEv2((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bFirstAuth, wOption, wKeyNo, wKeyVer,
                bKeyNoCard, pDivInput, bDivLen, bLenPcdCapsIn, bPcdCapsIn, bPcdCapsOut, bPdCapsOut);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */



/* MIFARE DESFire EVX Memory and Configuration management commands. ------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_FreeMem(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMemInfo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pMemInfo, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_FreeMem((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pMemInfo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Format(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_Format((phalMfdfEVx_Sw_DataParams_t *) pDataParams);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SetConfiguration(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint8, ANFCRL_VAR) bOption,
		P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
		VAR(uint8, ANFCRL_VAR) bDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pData, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_SetConfiguration((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, pData, bDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetVersion(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVerInfo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pVerInfo, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetVersion((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pVerInfo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetCardUID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bExchangeOption, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCardUidLength = 0;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pUid, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetCardUID((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bExchangeOption, bOption, pUid, &bCardUidLength);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */



/* MIFARE DESFire EVX Key management commands. ---------------------------------------------------------------------------------------- */
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeKey(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wOldKeyNo, VAR(uint16, ANFCRL_VAR) wOldKeyVer, VAR(uint16, ANFCRL_VAR) wNewKeyNo,
    VAR(uint16, ANFCRL_VAR) wNewKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen)
{
    /**
    * This  function will handle all the three authentication modes: 0x0A, 1A and AA.
    * and all crypto modes i.e., DES, 3DES, 3K3DES, AES
    * The previous authentication status including key number and session key is
    * present in the params  structure.
    * Successful auth. with PICC master key is required if AID = 0x00 else
    * an auth. with the application master key is required.
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bDivLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    }

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ChangeKey((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wOldKeyNo, wOldKeyVer,
                wNewKeyNo, wNewKeyVer, bKeyNoCard, pDivInput, bDivLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SAM_NONX */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeKeyEv2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wOldKeyNo, VAR(uint16, ANFCRL_VAR) wOldKeyVer, VAR(uint16, ANFCRL_VAR) wNewKeyNo,
    VAR(uint16, ANFCRL_VAR) wNewKeyVer, VAR(uint8, ANFCRL_VAR) bKeySetNo, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if (0U != (bDivLen)) PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ChangeKeyEv2((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wOldKeyNo, wOldKeyVer,
                wNewKeyNo, wNewKeyVer, bKeySetNo, bKeyNoCard, pDivInput, bDivLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_InitializeKeySet(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySetNo, VAR(uint8, ANFCRL_VAR) bKeyType)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {

        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_InitializeKeySet((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bKeySetNo, bKeyType);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_FinalizeKeySet(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySetNo, VAR(uint8, ANFCRL_VAR) bKeySetVersion)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_FinalizeKeySet((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bKeySetNo, bKeySetVersion);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE)  phalMfdfEVx_RollKeySet(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySetNo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_RollKeySet((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bKeySetNo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetKeySettings(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySettings, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bRespLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pKeySettings, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetKeySettings((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pKeySettings, bRespLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeKeySettings(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySettings)
{
    /**
    * This  function will handle all the three authentication modes: 0x0A, 1A and AA.
    * and all crypto modes i.e., DES, 3DES, 3K3DES, AES
    * The previous authentication status including key number and session key is
    * present in the params  structure.
    * Successful auth. with PICC master key is required if AID = 0x00 else
    * an auth. with the application master key is required.
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ChangeKeySettings((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bKeySettings);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetKeyVersion(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeyNo, VAR(uint8, ANFCRL_VAR) bKeySetNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bRxLen)
{
    /**
    * This command can be issued without valid authentication
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pKeyVersion, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {

        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetKeyVersion((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bKeyNo, bKeySetNo,
                pKeyVersion, bRxLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */



/* MIFARE DESFire EVX Application management commands. -------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateApplication(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid, VAR(uint8, ANFCRL_VAR) bKeySettings1, VAR(uint8, ANFCRL_VAR) bKeySettings2,
    VAR(uint8, ANFCRL_VAR) bKeySettings3, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName, VAR(uint8, ANFCRL_VAR) bISODFNameLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if((bOption & 0x01u) > 0u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    if(bISODFNameLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pISODFName, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pAid, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateApplication((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, pAid, bKeySettings1,
                bKeySettings2, bKeySettings3, pKeySetValues, pISOFileId, pISODFName, bISODFNameLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DeleteApplication(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC, VAR(uint8, ANFCRL_VAR) bDAMMAC_Len)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAid, PH_COMP_AL_MFDFEVX);
    if( bDAMMAC_Len > 0u) {
    	PH_ASSERT_NULL_PARAM(pDAMMAC, PH_COMP_AL_MFDFEVX);
    }

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_DeleteApplication((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pAid, pDAMMAC, bDAMMAC_Len);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateDelegatedApplication(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamParams, VAR(uint8, ANFCRL_VAR) bKeySettings1,
    VAR(uint8, ANFCRL_VAR) bKeySettings2, VAR(uint8, ANFCRL_VAR) bKeySettings3, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName, VAR(uint8, ANFCRL_VAR) bISODFNameLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncK, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if((bOption & 0x01u) > 0u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    if(bISODFNameLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pISODFName, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pAid, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateDelegatedApplication((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, pAid,
                pDamParams, bKeySettings1, bKeySettings2, bKeySettings3, pKeySetValues, pISOFileId, pISODFName, bISODFNameLen,
                pEncK, pDAMMAC);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SelectApplication(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid2)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAid, PH_COMP_AL_MFDFEVX);
    if(bOption > 0u) {
    	PH_ASSERT_NULL_PARAM(pAid2, PH_COMP_AL_MFDFEVX);
    }

    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {

        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_SelectApplication((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, pAid, pAid2);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetApplicationIDs(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAidBuff, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumAIDs)
{
    /**
    A PICC can store any number of applications limited by the PICC memory.
    PICC will return AIDs (3 Bytes/AID) until the RxBuffer is full and intimates the
    application of RX_CHAINING. Remaining AIDs can be retrieved by sending 0xAF command.
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAidBuff, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pNumAIDs, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetApplicationIDs((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption,
                pAidBuff, pNumAIDs);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetDFNames(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFBuffer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFInfoLen)
{
    /*
    Returns AID(3B), FID(2B), DF-Name(1..16B) in one frame.
    */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDFBuffer, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDFInfoLen, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetDFNames((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, pDFBuffer, pDFInfoLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetDelegatedInfo(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMSlot, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamSlotVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pQuotaLimit,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFreeBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDAMSlot, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDamSlotVer, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pQuotaLimit, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pFreeBlocks, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAid, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetDelegatedInfo((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pDAMSlot, pDamSlotVer, pQuotaLimit,
                pFreeBlocks, pAid);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}




/* MIFARE DESFire EVX File management commands. --------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateStdDataFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, VAR(uint8, ANFCRL_VAR) bFileOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bOption == 0x01u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pFileSize, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {

        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateStdDataFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bFileNo,
                pISOFileId, bFileOption, pAccessRights, pFileSize);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateBackupDataFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, VAR(uint8, ANFCRL_VAR) bFileOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bOption == 1u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pFileSize, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateBackupDataFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bFileNo,
                pISOFileId, bFileOption, pAccessRights, pFileSize);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateValueFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo, VAR(uint8, ANFCRL_VAR) bCommSett, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLowerLmit,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUpperLmit, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue, VAR(uint8, ANFCRL_VAR) bLimitedCredit)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pLowerLmit, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pUpperLmit, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateValueFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bFileNo, bCommSett, pAccessRights,
                pLowerLmit, pUpperLmit, pValue, bLimitedCredit);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateLinearRecordFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, VAR(uint8, ANFCRL_VAR) bCommSett,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec)

{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bOption == 1u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRecordSize, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pMaxNoOfRec, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateLinearRecordFile((phalMfdfEVx_Sw_DataParams_t *)pDataParams, bOption,
                bFileNo, pISOFileId, bCommSett, pAccessRights, pRecordSize, pMaxNoOfRec);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateCyclicRecordFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, VAR(uint8, ANFCRL_VAR) bCommSett,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    if(bOption == 0x01u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pRecordSize, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pMaxNoOfRec, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateCyclicRecordFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption,
                bFileNo, pISOFileId, bCommSett, pAccessRights, pRecordSize, pMaxNoOfRec);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateTransactionMacFile(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wOption,
	VAR(uint8, ANFCRL_VAR) bFileNo,
	VAR(uint8, ANFCRL_VAR) bCommSett,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,
    VAR(uint16, ANFCRL_VAR) wKeyNo,
	VAR(uint8, ANFCRL_VAR) bKeyType,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bTMKey,
	VAR(uint8, ANFCRL_VAR) bTMKeyVer,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,
	VAR(uint8, ANFCRL_VAR) bDivInputLength)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(wOption);
    PH_UNUSED_VARIABLE(wKeyNo);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(bTMKey, PH_COMP_AL_MFDFEVX);
    if(bDivInputLength > 0u) {
    	PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    }

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateTransactionMacFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bFileNo,
                bCommSett, pAccessRights, bKeyType, bTMKey, bTMKeyVer);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DeleteFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_DeleteFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bFileNo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetFileIDs(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bNumFid)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pFid, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(bNumFid, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetFileIDs((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pFid, bNumFid);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetISOFileIDs(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFidBuffer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumFid)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pFidBuffer, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pNumFid, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetISOFileIDs((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pFidBuffer, pNumFid);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetFileSettings(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFSBuffer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bBufferLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pFSBuffer, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(bBufferLen, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetFileSettings((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bFileNo, pFSBuffer, bBufferLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetFileCounters(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileCounters, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetFileCounters((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bFileNo,
                pFileCounters, pRxLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeFileSettings(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, VAR(uint8, ANFCRL_VAR) bFileOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,
    VAR(uint8, ANFCRL_VAR) bAddInfoLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAddInfo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAccessRights, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAddInfo, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ChangeFileSettings((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bFileNo,
                bFileOption, pAccessRights, bAddInfoLen, pAddInfo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}




/* MIFARE DESFire EVX Data management commands. --------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ReadData(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bIns, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLength,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pOffset, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pLength, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(ppRxdata, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRxdataLen, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ReadData((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bIns, bFileNo,
                pOffset, pLength, ppRxdata, pRxdataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_WriteData(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bIns, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
#ifdef NXPBUILD__PH_LOG
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen;
#endif /*NXPBUILD__PH_LOG*/
#ifdef NXPBUILD__PH_LOG
    wDataLen = (uint16) pTxDataLen[1];
    wDataLen = wDataLen << 8;
    wDataLen |= pTxDataLen[0];
#endif /*NXPBUILD__PH_LOG*/

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pOffset, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pTxData, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pTxDataLen, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_WriteData((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bIns, bFileNo,
                pOffset, pTxData, pTxDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetValue(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetValue((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bFileNo, pValue);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Credit(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_Credit((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bFileNo, pValue);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Debit(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_Debit((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption, bFileNo, pValue);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_LimitedCredit(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_LimitedCredit((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption,
                bFileNo, pValue);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_WriteRecord(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bCommOption, 
	VAR(uint8, ANFCRL_VAR) bIns, 
	VAR(uint8, ANFCRL_VAR) bFileNo, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
#ifdef NXPBUILD__PH_LOG
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen;
#endif /*NXPBUILD__PH_LOG*/

#ifdef NXPBUILD__PH_LOG
    wDataLen = (uint16) pDataLen[1];
    wDataLen = wDataLen << 8;
    wDataLen |= pDataLen[0];
#endif /*NXPBUILD__PH_LOG*/

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pOffset, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pData, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDataLen, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_WriteRecord((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption, bIns, bFileNo, pOffset, pData, pDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ReadRecords(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bIns, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecCount,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecSize, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRecNo, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRecCount, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(ppRxdata, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRxdataLen, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRecSize, PH_COMP_AL_MFDFEVX);

    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ReadRecords((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption, bIns, bFileNo, pRecNo,
                pRecCount, pRecSize, ppRxdata, pRxdataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_UpdateRecord(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bIns, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
#ifdef NXPBUILD__PH_LOG
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen;
#endif /*NXPBUILD__PH_LOG*/
#ifdef NXPBUILD__PH_LOG
    wDataLen = (uint16) pDataLen[1];
    wDataLen = wDataLen << 8;
    wDataLen |= pDataLen[0];
#endif /*NXPBUILD__PH_LOG*/

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pOffset, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pData, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDataLen, PH_COMP_AL_MFDFEVX);

    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_UpdateRecord((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption, bIns,
                bFileNo, pRecNo, pOffset, pData, pDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ClearRecordFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ClearRecordFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bFileNo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}




/* MIFARE DESFire EVX Transaction management commands. -------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CommitTransaction(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMV)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if((bOption & 0x01u) > 0u)
    {
        PH_ASSERT_NULL_PARAM(pTMC, PH_COMP_AL_MFDFEVX);
        PH_ASSERT_NULL_PARAM(pTMV, PH_COMP_AL_MFDFEVX);
    }

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CommitTransaction((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption,
                pTMC, pTMV);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AbortTransaction(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_AbortTransaction((phalMfdfEVx_Sw_DataParams_t *) pDataParams);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CommitReaderID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMRI, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncTMRI)

{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pTMRI, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CommitReaderID((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pTMRI, pEncTMRI);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}




/* MIFARE DESFire EVX ISO7816-4 commands. ---------------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoSelectFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bSelector, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,
    VAR(uint8, ANFCRL_VAR) bDFnameLen, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFCI, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoSelectFile((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, bSelector,
                pFid, pDFname, bDFnameLen, bExtendedLenApdu, ppFCI, pwFCILen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoReadBinary(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint8, ANFCRL_VAR) bOffset, VAR(uint8, ANFCRL_VAR) bSfid, VAR(uint32, ANFCRL_VAR) dwBytesToRead,
    VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(ppRxBuffer, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pBytesRead, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoReadBinary((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, bOffset,
                bSfid, dwBytesToRead, bExtendedLenApdu, ppRxBuffer, pBytesRead);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoUpdateBinary(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, 
	VAR(uint8, ANFCRL_VAR) bOffset, 
	VAR(uint8, ANFCRL_VAR) bSfid, 
	VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    VAR(uint32, ANFCRL_VAR) dwDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pData, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoUpdateBinary((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOffset, bSfid,
                bExtendedLenApdu, pData, dwDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoReadRecords(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint8, ANFCRL_VAR) bRecNo, VAR(uint8, ANFCRL_VAR) bReadAllFromP1, VAR(uint8, ANFCRL_VAR) bSfid,
    VAR(uint32, ANFCRL_VAR) dwBytesToRead, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(ppRxBuffer, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pBytesRead, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoReadRecords((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, bRecNo, bReadAllFromP1,
                bSfid, dwBytesToRead, bExtendedLenApdu, ppRxBuffer, pBytesRead);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoAppendRecord(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, 
	VAR(uint8, ANFCRL_VAR) bSfid, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, 
	VAR(uint32, ANFCRL_VAR) dwDataLen, 
	VAR(uint8, ANFCRL_VAR) bExtendedLenApdu)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pData, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoAppendRecord((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bSfid, bExtendedLenApdu,
                pData, dwDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoUpdateRecord(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, 
	VAR(uint8, ANFCRL_VAR) bIns, 
	VAR(uint8, ANFCRL_VAR) bRecNo, 
	VAR(uint8, ANFCRL_VAR) bSfid, 
	VAR(uint8, ANFCRL_VAR) bRefCtrl, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    VAR(uint8, ANFCRL_VAR) bDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pData, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoUpdateRecord((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bIns, bRecNo,
                bSfid, bRefCtrl, pData, bDataLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoGetChallenge(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, VAR(uint32, ANFCRL_VAR) dwLe,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRPICC1)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pRPICC1, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoGetChallenge((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wKeyNo, wKeyVer, bExtendedLenApdu,
                dwLe, pRPICC1);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoExternalAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput, VAR(uint8, ANFCRL_VAR) bInputLen, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pInput, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoExternalAuthenticate((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pInput, bInputLen,
                bExtendedLenApdu, pDataOut, pOutLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoInternalAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput, VAR(uint8, ANFCRL_VAR) bInputLen, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pInput, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoInternalAuthenticate((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pInput, bInputLen,
                bExtendedLenApdu, pDataOut, pOutLen);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, VAR(uint8, ANFCRL_VAR) bIsPICCkey)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_IsoAuthenticate((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wKeyNo, wKeyVer,
                bKeyNoCard, bIsPICCkey);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVX Originality Check functions. ------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ReadSign(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bAddr, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pSignature)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pSignature, PH_COMP_AL_MFDFEVX);

    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return  PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ReadSign((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bAddr, pSignature);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}




/* MIFARE DESFire EVX MIFARE Classic contactless IC functions. ---------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateMFCMapping(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo, VAR(uint8, ANFCRL_VAR) bFileOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCBlockList,
    VAR(uint8, ANFCRL_VAR) bMFCBlocksLen, VAR(uint8, ANFCRL_VAR) bRestoreSource, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicense, VAR(uint8, ANFCRL_VAR) bMFCLicenseLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters. */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pMFCBlockList, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pMFCLicense, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pMFCLicenseMAC, PH_COMP_AL_MFDFEVX);

    /* Log the information. */

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CreateMFCMapping((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption, bFileNo, bFileOption, pMFCBlockList,
                bMFCBlocksLen, bRestoreSource, pMFCLicense, bMFCLicenseLen, pMFCLicenseMAC);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t,ANFCRL_CODE) phalMfdfEVx_RestoreTransfer(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, 
	VAR(uint8, ANFCRL_VAR) bCommOption, 
	VAR(uint8, ANFCRL_VAR) bTargetFileNo, 
	VAR(uint8, ANFCRL_VAR) bSourceFileNo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters. */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Log the information. */

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_RestoreTransfer((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bCommOption ,bTargetFileNo, bSourceFileNo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_RestrictMFCUpdate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCConfig, VAR(uint8, ANFCRL_VAR) bMFCConfigLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicense, VAR(uint8, ANFCRL_VAR) bMFCLicenseLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters. */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pMFCConfig, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pMFCLicense, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pMFCLicenseMAC, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_RestrictMFCUpdate((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, pMFCConfig,
                bMFCConfigLen, pMFCLicense, bMFCLicenseLen, pMFCLicenseMAC);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}




/* MIFARE DESFire EVX POST Delivery Configuration function. ---------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticatePDC(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bRfu, VAR(uint8, ANFCRL_VAR) bKeyNoCard, VAR(uint8, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer,
    VAR(uint8, ANFCRL_VAR) bUpgradeInfo)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_AuthenticatePDC((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bRfu, bKeyNoCard, (uint8)wKeyNo,
                wKeyVer, bUpgradeInfo);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    /* Resetting the state. */
    PH_CHECK_SUCCESS(phalMfdfEVx_ResetAuthentication(pDataParams));

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVX Miscellaneous functions. ----------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_MFDFEVX);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GetConfig((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_SetConfig((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wConfig, wValue);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ResetAuthentication(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ResetAuthentication((phalMfdfEVx_Sw_DataParams_t *) pDataParams);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GenerateDAMEncKey(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNoDAMEnc, VAR(uint16, ANFCRL_VAR) wKeyVerDAMEnc, VAR(uint16, ANFCRL_VAR) wKeyNoAppDAMDefault,
    VAR(uint16, ANFCRL_VAR) wKeyVerAppDAMDefault, VAR(uint8, ANFCRL_VAR) bAppDAMDefaultKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMEncKey)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDAMEncKey, PH_COMP_AL_MFDFEVX);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GenerateDAMEncKey((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wKeyNoDAMEnc, wKeyVerDAMEnc,
                wKeyNoAppDAMDefault, wKeyVerAppDAMDefault, bAppDAMDefaultKeyVer, pDAMEncKey);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GenerateDAMMAC(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint16, ANFCRL_VAR) wKeyNoDAMMAC, VAR(uint16, ANFCRL_VAR) wKeyVerDAMMAC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamParams, VAR(uint8, ANFCRL_VAR) bKeySettings1, VAR(uint8, ANFCRL_VAR) bKeySettings2, VAR(uint8, ANFCRL_VAR) bKeySettings3, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName, VAR(uint8, ANFCRL_VAR) bISODFNameLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncK, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAid, PH_COMP_AL_MFDFEVX);
    if((bOption & PHAL_MFDFEVX_GENERATE_DAMMAC_DELETE_APPLICATION) == 0u)
    {
    	PH_ASSERT_NULL_PARAM(pDamParams, PH_COMP_AL_MFDFEVX);
    }
    /* if((bKeySettings2 & PHAL_MFDFEVX_KEYSETT3_PRESENT) && (bKeySettings3 & PHAL_MFDFEVX_KEYSETVALUES_PRESENT))
        PH_ASSERT_NULL_PARAM (pKeySetValues); */
    if((bOption & 0x01U) > 0u) {
    	PH_ASSERT_NULL_PARAM(pISOFileId, PH_COMP_AL_MFDFEVX);
    }
    if((bOption & 0x02U) > 0u) {
    	PH_ASSERT_NULL_PARAM(pISODFName, PH_COMP_AL_MFDFEVX);
    }
    if((bOption & PHAL_MFDFEVX_GENERATE_DAMMAC_DELETE_APPLICATION) == 0u) {
        PH_ASSERT_NULL_PARAM(pEncK, PH_COMP_AL_MFDFEVX);
    }
    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GenerateDAMMAC((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bOption, wKeyNoDAMMAC, wKeyVerDAMMAC,
                pAid, pDamParams, bKeySettings1, bKeySettings2, bKeySettings3, pKeySetValues, pISOFileId, pISODFName, bISODFNameLen,
                pEncK, pDAMMAC);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GenerateDAMMACSetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNoDAMMAC, VAR(uint16, ANFCRL_VAR) wKeyVerDAMMAC, VAR(uint16, ANFCRL_VAR) wOldDFNameLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOldISODFName, VAR(uint16, ANFCRL_VAR) wNewDFNameLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewISODFName, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pOldISODFName, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pNewISODFName, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pDAMMAC, PH_COMP_AL_MFDFEVX);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_GenerateDAMMACSetConfig((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wKeyNoDAMMAC,
                wKeyVerDAMMAC, wOldDFNameLen, pOldISODFName, wNewDFNameLen, pNewISODFName, pDAMMAC);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CalculateTMV(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNoTMACKey, VAR(uint16, ANFCRL_VAR) wKeyVerTMACKey,
    VAR(uint16, ANFCRL_VAR) wRamKeyNo, VAR(uint16, ANFCRL_VAR) wRamKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
    VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMI, VAR(uint32, ANFCRL_VAR) dwTMILen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMV)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(wRamKeyNo);
    PH_UNUSED_VARIABLE(wRamKeyVer);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bDivInputLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pTMC, PH_COMP_AL_MFDFEVX);
    if(bUidLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pUid, PH_COMP_AL_MFDFEVX);
    }
    if(dwTMILen > 0u) {
    	PH_ASSERT_NULL_PARAM(pTMI, PH_COMP_AL_MFDFEVX);
    }

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CalculateTMV((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wKeyNoTMACKey, wKeyVerTMACKey, pDivInput,
                bDivInputLen, pTMC, pUid, bUidLen, pTMI, dwTMILen, pTMV);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DecryptReaderID(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNoTMACKey, VAR(uint16, ANFCRL_VAR) wKeyVerTMACKey,
    VAR(uint16, ANFCRL_VAR) wRamKeyNo, VAR(uint16, ANFCRL_VAR) wRamKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
    VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncTMRI, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMRIPrev)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(wRamKeyNo);
    PH_UNUSED_VARIABLE(wRamKeyVer);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    if(bDivInputLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pTMC, PH_COMP_AL_MFDFEVX);
    if(bUidLen > 0u) {
    	PH_ASSERT_NULL_PARAM(pUid, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_PARAM(pEncTMRI, PH_COMP_AL_MFDFEVX);

    /* Parameter validation */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_DecryptReaderID((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wKeyNoTMACKey, wKeyVerTMACKey, pDivInput,
                bDivInputLen, pTMC, pUid, bUidLen, pEncTMRI, pTMRIPrev);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ComputeMFCLicenseMAC(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wMFCLicenseMACKeyNo, VAR(uint16, ANFCRL_VAR) wMFCLicenseMACKeyVer,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput, VAR(uint16, ANFCRL_VAR) wInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters. */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_DATA_PARAM(pInput, PH_COMP_AL_MFDFEVX);
    if (wOption != 0xFFFFU) {
    	PH_ASSERT_NULL_DATA_PARAM(pDivInput, PH_COMP_AL_MFDFEVX);
    }
    PH_ASSERT_NULL_DATA_PARAM(pMFCLicenseMAC, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_ComputeMFCLicenseMAC((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wOption, wMFCLicenseMACKeyNo, wMFCLicenseMACKeyVer,
                pInput, wInputLen, pDivInput, bDivInputLen, pMFCLicenseMAC);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CalculateMACSDM(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSdmOption, VAR(uint16, ANFCRL_VAR) wSDMMacKeyNo, VAR(uint16, ANFCRL_VAR) wSDMMacKeyVer,
    VAR(uint16, ANFCRL_VAR) wRamKeyNo, VAR(uint16, ANFCRL_VAR) wRamKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData, VAR(uint16, ANFCRL_VAR) wInDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRespMac)
{

    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(wRamKeyNo);
    PH_UNUSED_VARIABLE(wRamKeyVer);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pInData, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_CalculateMACSDM((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bSdmOption, wSDMMacKeyNo,
                wSDMMacKeyVer, pUid, bUidLen, pSDMReadCtr, pInData, wInDataLen, pRespMac);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DecryptSDMENCFileData(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSdmOption, VAR(uint16, ANFCRL_VAR) wEncKeyNo, VAR(uint16, ANFCRL_VAR) wEncKeyVer,
    VAR(uint16, ANFCRL_VAR) wRamKeyNo, VAR(uint16, ANFCRL_VAR) wRamKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncdata,
    VAR(uint16, ANFCRL_VAR) wEncDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainData)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(wRamKeyNo);
    PH_UNUSED_VARIABLE(wRamKeyVer);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pSDMReadCtr, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pEncdata, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pUid, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_DecryptSDMENCFileData((phalMfdfEVx_Sw_DataParams_t *) pDataParams, bSdmOption, wEncKeyNo,
                wEncKeyVer, pUid, bUidLen, pSDMReadCtr, pEncdata, wEncDataLen, pPlainData);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DecryptSDMPICCData(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncdata, VAR(uint16, ANFCRL_VAR) wEncDataLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainData)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pEncdata, PH_COMP_AL_MFDFEVX);

    /* Component Code Validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_DecryptSDMPICCData((phalMfdfEVx_Sw_DataParams_t *) pDataParams, wKeyNo, wKeyVer,
                pEncdata, wEncDataLen, pPlainData);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SetVCAParams(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlVCADataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_MFDFEVX);
    PH_ASSERT_NULL_PARAM(pAlVCADataParams, PH_COMP_AL_MFDFEVX);

    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDFEVX)
    {
        return  PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        case PHAL_MFDFEVX_SW_ID:
            status = phalMfdfEVx_Sw_SetVCAParams((phalMfdfEVx_Sw_DataParams_t *) pDataParams, pAlVCADataParams);
            break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
            break;
    }

    return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDFEVX */

#ifdef __cplusplus
}
#endif
