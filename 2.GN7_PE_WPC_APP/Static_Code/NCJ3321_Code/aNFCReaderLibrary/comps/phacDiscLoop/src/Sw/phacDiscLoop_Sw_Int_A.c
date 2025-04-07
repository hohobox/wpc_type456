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
*   @file    phacDiscLoop_Sw_Int_A.c
*   @version 1.0.0
*
*   @brief   AUTOSAR acDiscLoop - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phacDiscLoop Discovery Loop
*   @ingroup phac
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
#include <phacDiscLoop.h>
#include <phpalI14443p3a.h>
#include <phpalI14443p4a.h>
#include <phpalI14443p4.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#include "phacDiscLoop_Sw_Int.h"
#include "phacDiscLoop_Sw_Int_A.h"
 
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_A.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_A_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_A_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_A_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_A_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_A_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_A.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_A_VENDOR_ID_C != PHACDISCLOOP_SW_INT_A_VENDOR_ID)
    #error "phacDiscLoop_Sw_Int_A.c and phacDiscLoop_Sw_Int_A.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_A.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C    != PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C    != PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_A_AR_RELEASE_REVISION_VERSION_C != PHACDISCLOOP_SW_INT_A_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_A.c and phacDiscLoop_Sw_Int_A.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_A.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_A_SW_MAJOR_VERSION_C != PHACDISCLOOP_SW_INT_A_SW_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_A_SW_MINOR_VERSION_C != PHACDISCLOOP_SW_INT_A_SW_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_A_SW_PATCH_VERSION_C != PHACDISCLOOP_SW_INT_A_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_A.c and phacDiscLoop_Sw_Int_A.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
static CONST(uint8, ANFCRL_CONST) aCascadeCodes[] =
{
PHPAL_I14443P3A_CASCADE_LEVEL_1,
PHPAL_I14443P3A_CASCADE_LEVEL_2,
PHPAL_I14443P3A_CASCADE_LEVEL_3 };
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C== 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeA(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS)
    VAR(uint8, ANFCRL_VAR) bIndex = 0U;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;

    switch (pDataParams->bDiscLoopDetTechTypeAState)
    {
        case 0U:
            /* Reset total tags found */
            pDataParams->sTypeATargetInfo.bTotalTagsFound = 0;

            /* Reset Collision Bit for Type A*/
            pDataParams->bCollPend &= (uint8) ~(uint8) PHAC_DISCLOOP_POS_BIT_MASK_A;
            /* Reset the Sleep flag for Type 3 activation status */
            for (bIndex = 0U; bIndex < PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED; bIndex++)
            {
                /* Device is not in HLTA state */
                pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].bSleep = 0U;
                pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].bUidSize = 0U;
            }
            pDataParams->bDiscLoopDetTechTypeAState = 1U;
            /* no break */
        case 1U:
            /* sending the WakeUpA */
            PH_CHECK_INPROCESS_FCT(wStatus,
                    phpalI14443p3a_WakeUpA(pDataParams->pPal1443p3aDataParams,
                            pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aAtqa));

            if (0u != (phacDiscLoop_Sw_Int_IsValidPollStatus(wStatus)))
            {
                if ((wStatus & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
                {
                    pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_A;
                }
                else
                {
                    /* Do nothing */
                }
                pDataParams->bDiscLoopDetTechTypeAState = 3U;
                return PH_STATUS_INPROCESS;
            }
            else
            {
                pDataParams->bDiscLoopDetTechTypeAState = 0U;
                return wStatus;
            }
            /* No break */
        case 2U:
            PH_CHECK_INPROCESS_FCT(wStatus, phpalI14443p3a_HaltA(pDataParams->pPal1443p3aDataParams));
            pDataParams->bDiscLoopDetTechTypeAState = 0U;
            PH_CHECK_ABORT(wStatus);
            pDataParams->sTypeATargetInfo.bTotalTagsFound = 1;
            break;
        case 3U:
            PH_CHECK_INPROCESS_FCT(wStatus, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXWAIT_US, 500U));
            PH_BREAK_ON_FAILURE(wStatus);
            /* Send HALT, if we support NFC Activity 1.1 or if not in NFC mode */
            if (((pDataParams->bNfcActivityVersion == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_1)
                                && (pDataParams->bOpeMode == RD_LIB_MODE_NFC))
                                || (pDataParams->bOpeMode != RD_LIB_MODE_NFC))
            {
                /* Halt the detected cards. */
                pDataParams->bDiscLoopDetTechTypeAState = 2U;
                return PH_STATUS_INPROCESS;
            }
            pDataParams->sTypeATargetInfo.bTotalTagsFound = 1U;
            break;
        default:
            wStatus = PH_ERR_INTERNAL_ERROR;
            break;
    }
    pDataParams->bDiscLoopDetTechTypeAState = 0U;
    PH_CHECK_SUCCESS(wStatus);
    return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */
    PH_UNUSED_VARIABLE(pDataParams);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionA(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS)
    static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTypeANvbUid = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bDeviceCount = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bTypeATagIdx = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bCascadeCodeIdx= 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aTypeAUid[7] = { 0U };
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCollDetected = PH_OFF;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSetConfigDone = 0U;

    switch (pDataParams->bDiscLoopCollisionResolutionAState)
    {
        case CollisionResolutionA_Start:
            bDeviceCount = 0U;
            bTypeATagIdx = 0U;
            bCollDetected = PH_OFF;

            /* Collision_Pending = 1 and Device limit  = 0 */
            if((0U != ((pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_A))) && ((pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A] == 0x00U)))
            {
                pDataParams->sTypeATargetInfo.bTotalTagsFound = 0;
                return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
            }

            /* If supporting Activity 1.0, update status based on detection phase */
            if((pDataParams->bOpeMode == RD_LIB_MODE_NFC)
               && (pDataParams->bNfcActivityVersion == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_0))
            {
                /* Configure HW for the TypeA technology */
                PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(pDataParams->pHalDataParams, PHHAL_HW_CARDTYPE_ISO14443A));

                PH_CHECK_SUCCESS(status);

                if(0U != (pDataParams->sTypeATargetInfo.bTotalTagsFound))
                {
                    status = PH_ERR_SUCCESS;
                }

                if(0U != (pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_A))
                {
                    status = PH_ERR_COLLISION_ERROR;
                }
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_WakeUpA_End;
            }
            /*Symbol 0*/
            else
            {
                if(0U == bSetConfigDone)
                {
                    /* Apply Guard time. */
                    PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(
                        pDataParams->pHalDataParams,
                        PHHAL_HW_CONFIG_POLL_GUARD_TIME_US,
                        pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_A]));
                    bSetConfigDone = 1U;
                }

                if(1U == bSetConfigDone)
                {

                    /* Configure HW for the TypeA technology */
                    PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(
                        pDataParams->pHalDataParams,
                        PHHAL_HW_CARDTYPE_ISO14443A));
                    bSetConfigDone = 0U;
                    PH_BREAK_ON_FAILURE(status);
                    pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_WakeUpA_Run;
                }
            }

            /* Reset card detected count */
            pDataParams->sTypeATargetInfo.bTotalTagsFound = 0;
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_WakeUpA_Run:
            /* Send WakeUpA */
            PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_WakeUpA(
                                    pDataParams->pPal1443p3aDataParams,
                                    pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aAtqa));

            if ((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
            {
                /* In case of EMVCo, return Collision Pending status. */
                if(pDataParams->bOpeMode == RD_LIB_MODE_EMVCO)
                {
                    pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Start;
                    /* Report Error to Application and Application will perform PICC Reset */
                    return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_COLLISION_PENDING, PH_COMP_AC_DISCLOOP);
                }
                bCollDetected = PH_ON;
            }

            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Set_Txwait;
            return PH_STATUS_INPROCESS;
            /* no break */

        case CollisionResolutionA_Set_Txwait:
            PH_CHECK_INPROCESS_FCT(statusTmp,
                    phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXWAIT_US, 500U));

            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_WakeUpA_End;
            return PH_STATUS_INPROCESS;
            /* no break */
        case CollisionResolutionA_WakeUpA_End:
            /*Symbol 1*/
            if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
            {
                /* Device count = 0 and any Error */
                if(((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
                  && (pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A] == 0x00U))
                {
                    pDataParams->sTypeATargetInfo.bTotalTagsFound = 0;
                    pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_A;
                    break;
                }

                /*Symbol 1*/
                if ((status & PH_ERR_MASK) != PH_ERR_COLLISION_ERROR)
                {
                    pDataParams->bCollPend &= (uint8)~(uint8)PHAC_DISCLOOP_POS_BIT_MASK_A;
                    break;
                }
            }

            /*Symbol 3*/
            if(0U == (pDataParams->bUseAntiColl))
            {
                /*Symbol 25*/
                pDataParams->bCollPend |= (uint8)PHAC_DISCLOOP_POS_BIT_MASK_A;
                status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_COLLISION_PENDING, PH_COMP_AC_DISCLOOP);
                break;
            }
            if (bDeviceCount <= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A])
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Device_Loop;
            }
            else
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Finish;
            }
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_Device_Loop:
            if (bTypeATagIdx <= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A])
            {
                /*Symbol 5*/
                pDataParams->bCollPend &= (uint8)~(uint8)PHAC_DISCLOOP_POS_BIT_MASK_A;
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_CascadeCode_Loop;
                bCascadeCodeIdx = 0U;
                return PH_STATUS_INPROCESS;
            }

            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Device_Loop_Check;
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_CascadeCode_Loop:
            /*Symbol 5, 17*/
            bTypeANvbUid = 0U;
            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Anticollision_Loop;
            /* no break */

        case CollisionResolutionA_Anticollision_Loop:
            /* Anti-collision loop */
            if (bTypeANvbUid != 0x40U)
            {
                /*Symbol 6,7,8*/
                PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_Anticollision(
                        pDataParams->pPal1443p3aDataParams,
                        aCascadeCodes[bCascadeCodeIdx],      /* Cascade code */
                        aTypeAUid,                           /* Input UID */
                        bTypeANvbUid,                        /* UID len = 0 */
                        aTypeAUid,                           /* UID out */
                        &bTypeANvbUid                      /* UID out size */
                        ));
                /*Symbol 9, 14*/
                if ((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
                {
                    /*Symbol 10*/
                    pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_A;
                    if(bTypeATagIdx >= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A])
                    {
                        /*Symbol 11*/
                        status = PH_ERR_SUCCESS;
                        break;
                    }

                    /* Increment the number of valid bits and set the collision bit to one and handle based on Byte and Bit boundaries. */
                    if ((bTypeANvbUid & ((uint8)0x07U)) <  (uint8)7U)
                    {
                        bTypeANvbUid++;

                        /* Set collision bit to 1 to resolve tag with highest UID */
                        aTypeAUid[(uint8)((bTypeANvbUid & 0xF0U) >> 4U)] |= (uint8)(0x01U << ((bTypeANvbUid & ((uint8)0x07U)) - 1U));
                    }
                    else
                    {
                        bTypeANvbUid = (uint8)((((bTypeANvbUid & 0xF0U) >> 4U) + 1U) << 4U);

                        /* Set collision bit to 1 to resolve tag with highest UID */
                        aTypeAUid[(uint8)(((bTypeANvbUid & 0xF0U) >> 4U) - 1U)] |= (uint8)(0x80U);
                    }
                }
                else
                {
                    /* Check success */
                    /* Some error that can't be handled */
                    PH_BREAK_ON_FAILURE(status);
                }
                return PH_STATUS_INPROCESS;
            } /*End of if (bTypeANvbUid != 0x40U)*/

            /* Atqa(which indicates NFCID1 size) is invalid since collision is encountered while receiving Atqa */
            if (bCollDetected == PH_OFF)
            {
                /* EMVCO: case_id 302_10 */
                /*
                * Digital Proto: Article 4.7.2 and 4.7.2.4
                * ISO14443-3 Article 6.5.2.1
                * EMVCo article 5.4.2
                * So For Single UID Size The NFC Forum Device MUST set nfcid10 of a single-size NFCID1 and nfcid13
                * of a double-size NFCID1 to a value different from 88h.
                */
                if(((0U == ((pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_A))))
                   && ((((pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aAtqa[0] & 0xC0U) == 0x00U)
                   && (aCascadeCodes[bCascadeCodeIdx] == PHPAL_I14443P3A_CASCADE_LEVEL_1))
                   || (((pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aAtqa[0] & 0xC0U) == 0x40U)
                   && (aCascadeCodes[bCascadeCodeIdx] == PHPAL_I14443P3A_CASCADE_LEVEL_2)))
                   && (aTypeAUid[0] == 0x88U))
                {
                    status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AC_DISCLOOP);
                    break;
                }
            }
            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Select;
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_Select:
            /*symbol 15*/
            PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_Select(
                    pDataParams->pPal1443p3aDataParams,
                    aCascadeCodes[bCascadeCodeIdx],
                    aTypeAUid,
                    &pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aSak));

            if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
                /*Symbol 16*/
                if ((0U == (pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aSak & 0x04U)))
                {
                    /*UID Complete*/
                    pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_CascadeCode_Loop_End;
                    return PH_STATUS_INPROCESS;
                }
            }
            else
            {
                break;
            }

            bCascadeCodeIdx++;
            if (bCascadeCodeIdx < 3U)
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_CascadeCode_Loop;
            }
            else
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_CascadeCode_Loop_End;
            }
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_CascadeCode_Loop_End:
            /* If select was successful */
            /*Symbol 19*/
            status = phpalI14443p3a_GetSerialNo(
                pDataParams->pPal1443p3aDataParams,
                &pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aUid[0],
                &pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].bUidSize);

            PH_BREAK_ON_FAILURE(status);

            /*Symbol 18*/
            bTypeATagIdx++;

            /*Symbol 20*/
            if((0U != ((pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_A))) && (bTypeATagIdx < pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A]))
            {
                /* Symbol 21 */
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_HaltA;
            }
            else
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Finish;
            }
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_HaltA:
            PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_HaltA(pDataParams->pPal1443p3aDataParams));
            PH_BREAK_ON_FAILURE(status);
            /* Update the corresponding Layer 3 dataparam to indicate the Tag is in HALT State. */
            (pDataParams->sTypeATargetInfo).aTypeA_I3P3[bTypeATagIdx - (uint8)1U].bSleep = (uint8)1U;

            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_RequestA;
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_RequestA:
            /* Symbol 22 */
            PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_RequestA(
                    pDataParams->pPal1443p3aDataParams,
                    pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aAtqa));

            if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
                /*Symbol 4*/
                if(pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aAtqa[0] == 0x00U)
                {
                    /*Symbol 25*/
                    pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_A;
                    break;
                }
            }
            else if((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
            {
                /* More device to resolve */
                pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_A;
            }
            else
            {
                break;
            }
            pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Device_Loop_Check;
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_Device_Loop_Check:
            bDeviceCount++;
            if (bDeviceCount <= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A])
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Device_Loop;
            }
            else
            {
                pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Finish;
            }
            return PH_STATUS_INPROCESS;

        case CollisionResolutionA_Finish:
            pDataParams->sTypeATargetInfo.bTotalTagsFound = bTypeATagIdx;
            pDataParams->bNumOfCards = bTypeATagIdx;

            if(pDataParams->sTypeATargetInfo.bTotalTagsFound == 0U)
            {
                status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
            }
            else
            {
                status = PH_ERR_SUCCESS;
            }
            break;
        default:
            break;
    }
    pDataParams->bDiscLoopCollisionResolutionAState = CollisionResolutionA_Start;
    return status;
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */
    PH_UNUSED_VARIABLE(pDataParams);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateA(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bTypeATagIdx)
{
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS)
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aUid[10] = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidLen = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMoreCardsAvailable = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTagType = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bActiveDevice = 0U;
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCidEnabled = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCid = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNadSupported = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFwi = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFsdi = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFsci = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bEmdEnabled = 0U;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */

    if (pDataParams->bDiscLoopActivateAState == 0U)
    {
        bTagType = 0U;
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
        bEmdEnabled = 0U;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
        if ((bTypeATagIdx >= pDataParams->sTypeATargetInfo.bTotalTagsFound)
                || (bTypeATagIdx >= PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED))
        {
            /* Out of range or no such card found yet */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }

        if(pDataParams->sTypeATargetInfo.bTotalTagsFound > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED)
        {
            /* To fix coverity issue */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AC_DISCLOOP);
        }

        /* If it is Single device or selected device is at last position, In both case device is already active */
        if((pDataParams->sTypeATargetInfo.bTotalTagsFound <= PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED) && (pDataParams->sTypeATargetInfo.bTotalTagsFound > 1U)
                && (pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].bSleep == 1U)) /* Step 1 */
        {
            for (bIndex = 0; bIndex < pDataParams->sTypeATargetInfo.bTotalTagsFound; bIndex++)
            {
                /* Step 2 */
                if ((pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].bSleep == 0U)
                        && (bIndex != bTypeATagIdx))
                {
                    bActiveDevice = 1;
                    /* Update pDataParams to indicate that the tag will now be moved to IDLE state. */
                    pDataParams->sTypeATargetInfo.aTypeA_I3P3[bIndex].bSleep = 1U;
                }
            }
            if (bActiveDevice != 0U)
            {
                /* Step 3 of Activation flow */
                pDataParams->bDiscLoopActivateAState = 1U;
            }
            else
            {
                pDataParams->bDiscLoopActivateAState = 2U;
            }
        }
        else
        {
            pDataParams->bDiscLoopActivateAState = 3U;
        }
    }

    if (pDataParams->bDiscLoopActivateAState == 1U)
    {
        PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_HaltA(pDataParams->pPal1443p3aDataParams));
        if (status != PH_ERR_SUCCESS)
        {
            /* Halt A has failed, can't count this as detected tag */
            pDataParams->bDiscLoopActivateAState = 0U;
            return status;
        }
        pDataParams->bDiscLoopActivateAState = 2U;
    }

    if (pDataParams->bDiscLoopActivateAState == 2U)
    {
        /* Activate the card in sleep with given UID */
        PH_CHECK_INPROCESS_FCT(status,
                phpalI14443p3a_ActivateCard(pDataParams->pPal1443p3aDataParams,
                        ((pDataParams->sTypeATargetInfo).aTypeA_I3P3[bTypeATagIdx]).aUid,
                        ((pDataParams->sTypeATargetInfo).aTypeA_I3P3[bTypeATagIdx]).bUidSize, aUid,
                        &bUidLen,
                        &(((pDataParams->sTypeATargetInfo).aTypeA_I3P3[bTypeATagIdx]).aSak),
                        &bMoreCardsAvailable));
        if (status != PH_ERR_SUCCESS)
        {
            pDataParams->bDiscLoopActivateAState = 0U;
            return status;
        }

        pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].bSleep = 0U;
        pDataParams->bDiscLoopActivateAState = 3U;
        return PH_STATUS_INPROCESS;
    }

    if (pDataParams->bDiscLoopActivateAState == 3U)
    {
        bTagType = (pDataParams->sTypeATargetInfo.aTypeA_I3P3[bTypeATagIdx].aSak & 0x60U);
        bTagType = bTagType >> 5U;
        /* Type 4A */
        if (bTagType == PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK)
        {
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS)
            if(0U == bEmdEnabled)
            {
                /* Enable Emd Check */
            	PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_SET_EMD, PH_ON));
                if (status != PH_ERR_SUCCESS)
                {
                    pDataParams->bDiscLoopActivateAState = 0U;
                    return status;
                }
                bEmdEnabled = 1U;
                return PH_STATUS_INPROCESS;
            }

            PH_CHECK_INPROCESS_FCT(status,
                    phpalI14443p4a_ActivateCard(pDataParams->pPal1443p4aDataParams,
                            pDataParams->sTypeATargetInfo.sTypeA_I3P4.bFsdi,
                            pDataParams->sTypeATargetInfo.sTypeA_I3P4.bCid,
                            pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDri,
                            pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDsi,
                            pDataParams->sTypeATargetInfo.sTypeA_I3P4.pAts));
            bEmdEnabled = 0U;
            if (status != PH_ERR_SUCCESS)
            {
                pDataParams->bDiscLoopActivateAState = 0U;
                return status;
            }

            /* Retrieve 14443-4A protocol parameter */
            status = phpalI14443p4a_GetProtocolParams(pDataParams->pPal1443p4aDataParams,
                    &bCidEnabled, &bCid, &bNadSupported, &bFwi, &bFsdi, &bFsci);
            if (status != PH_ERR_SUCCESS)
            {
                pDataParams->bDiscLoopActivateAState = 0U;
                return status;
            }

            /* Set 14443-4 protocol parameter */
            status = phpalI14443p4_SetProtocol(pDataParams->pPal14443p4DataParams, bCidEnabled,
                    bCid, bNadSupported, pDataParams->sTypeATargetInfo.sTypeA_I3P4.bNad, bFwi,
                    bFsdi, bFsci);
            if (status != PH_ERR_SUCCESS)
            {
                pDataParams->bDiscLoopActivateAState = 0U;
                return status;
            }
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
            return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
        }
        pDataParams->bDiscLoopActivateAState = 4U;
        return PH_STATUS_INPROCESS;
    }

    if (pDataParams->bDiscLoopActivateAState == 4U)
    {
        /* Reset state machine in case of returning */
        pDataParams->bDiscLoopActivateAState = 0U;
        if (bTagType == PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK)
        {
            /* In case of EMVCo Profile*/
            if (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO)
            {
                /* Return to application with No device resolved; In EMVCo mode only Type-A ISO 14443-4 compliant cards should be activated. */
                return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
            }

            return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->bDiscLoopActivateAState = 5U;
    }

    if (pDataParams->bDiscLoopActivateAState == 5U)
    {
        /* Support for both Type 4A and NFC-DEP (Merged SAK) */
        if (bTagType == PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK)
        {
#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
            if (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO)
            {
                PH_CHECK_INPROCESS_FCT(status,
                        phpalI14443p4a_ActivateCard(pDataParams->pPal1443p4aDataParams,
                                pDataParams->sTypeATargetInfo.sTypeA_I3P4.bFsdi,
                                pDataParams->sTypeATargetInfo.sTypeA_I3P4.bCid,
                                pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDri,
                                pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDsi,
                                pDataParams->sTypeATargetInfo.sTypeA_I3P4.pAts));
                if (status != PH_ERR_SUCCESS)
                {
                    pDataParams->bDiscLoopActivateAState = 0U;
                    return status;
                }

                /* Retrieve 14443-4A protocol parameter */
                status = phpalI14443p4a_GetProtocolParams(pDataParams->pPal1443p4aDataParams,
                        &bCidEnabled, &bCid, &bNadSupported, &bFwi, &bFsdi, &bFsci);
                if (status != PH_ERR_SUCCESS)
                {
                    pDataParams->bDiscLoopActivateAState = 0U;
                    return status;
                }

                /* Set 14443-4 protocol parameter */
                status = phpalI14443p4_SetProtocol(pDataParams->pPal14443p4DataParams, bCidEnabled,
                        bCid, bNadSupported, pDataParams->sTypeATargetInfo.sTypeA_I3P4.bNad, bFwi,
                        bFsdi, bFsci);
                if (status != PH_ERR_SUCCESS)
                {
                    pDataParams->bDiscLoopActivateAState = 0U;
                    return status;
                }
            }
            else
#endif /*  NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
            {
                /* Return to application; application can decide what to send RATS or ATR */
                pDataParams->bDiscLoopActivateAState = 0U;
                return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_MERGED_SEL_RES_FOUND,
                        PH_COMP_AC_DISCLOOP);
            }
        }
    }

    pDataParams->bDiscLoopActivateAState = 0U;
    /* Case of EMVCo Profile and type 2 tag */
    if ((bTagType == PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK)
            && (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO))
    {
        /* Return to application with No device resolved; In EMVCo mode only Type-A ISO 14443-4 compliant cards should be activated. */
        return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
    }

    return PH_ERR_SUCCESS;
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(bTypeATagIdx);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C== 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef __cplusplus
}
#endif
