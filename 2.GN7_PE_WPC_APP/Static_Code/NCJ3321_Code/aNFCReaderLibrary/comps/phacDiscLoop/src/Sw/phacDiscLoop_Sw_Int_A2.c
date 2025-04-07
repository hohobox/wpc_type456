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
*   @file    phacDiscLoop_Sw_Int_A2.c
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
#include <ph_RefDefs2.h>
#include <phacDiscLoop2.h>
#include <phpalI14443p3a2.h>
#include <phpalI14443p4a2.h>
#include <phpalI14443p42.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop_Sw_Int2.h"
#include "phacDiscLoop_Sw_Int_A2.h"
 
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_A2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_A_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_A_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_A_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_A_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_A_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_A.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_A_VENDOR_ID_C2 != PHACDISCLOOP_SW_INT_A_VENDOR_ID2)
    #error "phacDiscLoop_Sw_Int_A2.c and phacDiscLoop_Sw_Int_A2.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_A.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_A_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_SW_INT_A_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_A2.c and phacDiscLoop_Sw_Int_A2.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_A.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_A_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_INT_A_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_A_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_INT_A_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_A_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_INT_A_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_A2.c and phacDiscLoop_Sw_Int_A2.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
static CONST(uint8, ANFCRL_CONST) aCascadeCodes2[] =
{
PHPAL_I14443P3A_CASCADE_LEVEL_12,
PHPAL_I14443P3A_CASCADE_LEVEL_22,
PHPAL_I14443P3A_CASCADE_LEVEL_32 };
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2== 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeA2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2)
    VAR(uint8, ANFCRL_VAR) bIndex2 = 0U;
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2 = PH_ERR_SUCCESS2;

    switch (pDataParams2->bDiscLoopDetTechTypeAState2)
    {
        case 0U:
            /* Reset total tags found */
            pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = 0;

            /* Reset Collision Bit for Type A*/
            pDataParams2->bCollPend2 &= (uint8) ~(uint8) PHAC_DISCLOOP_POS_BIT_MASK_A2;
            /* Reset the Sleep flag for Type 3 activation status2 */
            for (bIndex2 = 0U; bIndex2 < PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2; bIndex2++)
            {
                /* Device is not in HLTA state */
                pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bIndex2].bSleep2 = 0U;
                pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bIndex2].bUidSize2 = 0U;
            }
            pDataParams2->bDiscLoopDetTechTypeAState2 = 1U;
            /* no break */
        case 1U:
            /* sending the WakeUpA */
            PH_CHECK_INPROCESS_FCT2(wStatus2,
                    phpalI14443p3a_WakeUpA2(pDataParams2->pPal1443p3aDataParams2,
                            pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aAtqa2));

            if (0u != (phacDiscLoop_Sw_Int_IsValidPollStatus2(wStatus2)))
            {
                if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
                {
                    pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
                }
                else
                {
                    /* Do nothing */
                }
                pDataParams2->bDiscLoopDetTechTypeAState2 = 3U;
                return PH_STATUS_INPROCESS2;
            }
            else
            {
                pDataParams2->bDiscLoopDetTechTypeAState2 = 0U;
                return wStatus2;
            }
            /* No break */
        case 2U:
            PH_CHECK_INPROCESS_FCT2(wStatus2, phpalI14443p3a_HaltA2(pDataParams2->pPal1443p3aDataParams2));
            pDataParams2->bDiscLoopDetTechTypeAState2 = 0U;
            PH_CHECK_ABORT2(wStatus2);
            pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = 1;
            break;
        case 3U:
            PH_CHECK_INPROCESS_FCT2(wStatus2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXWAIT_US2, 500U));
            PH_BREAK_ON_FAILURE2(wStatus2);
            /* Send HALT, if we support NFC Activity 1.1 or if not in NFC mode */
            if (((pDataParams2->bNfcActivityVersion2 == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12)
                                && (pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2))
                                || (pDataParams2->bOpeMode2 != RD_LIB_MODE_NFC2))
            {
                /* Halt the detected cards. */
                pDataParams2->bDiscLoopDetTechTypeAState2 = 2U;
                return PH_STATUS_INPROCESS2;
            }
            pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = 1U;
            break;
        default:
            wStatus2 = PH_ERR_INTERNAL_ERROR2;
            break;
    }
    pDataParams2->bDiscLoopDetTechTypeAState2 = 0U;
    PH_CHECK_SUCCESS2(wStatus2);
    return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */
    PH_UNUSED_VARIABLE2(pDataParams2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionA2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2)
    static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTypeANvbUid2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bDeviceCount2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bTypeATagIdx2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bCascadeCodeIdx2= 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 aTypeAUid2[7] = { 0U };
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCollDetected2 = PH_OFF2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSetConfigDone2 = 0U;

    switch (pDataParams2->bDiscLoopCollisionResolutionAState2)
    {
        case CollisionResolutionA_Start2:
            bDeviceCount2 = 0U;
            bTypeATagIdx2 = 0U;
            bCollDetected2 = PH_OFF2;

            /* Collision_Pending = 1 and Device limit  = 0 */
            if((0U != ((pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_A2))) && ((pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2] == 0x00U)))
            {
                pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = 0;
                return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
            }

            /* If supporting Activity 1.0, update status2 based on detection phase */
            if((pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2)
               && (pDataParams2->bNfcActivityVersion2 == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02))
            {
                /* Configure HW for the TypeA technology */
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(pDataParams2->pHalDataParams2, PHHAL_HW_CARDTYPE_ISO14443A2));

                PH_CHECK_SUCCESS2(status2);

                if(0U != (pDataParams2->sTypeATargetInfo2.bTotalTagsFound2))
                {
                    status2 = PH_ERR_SUCCESS2;
                }

                if(0U != (pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_A2))
                {
                    status2 = PH_ERR_COLLISION_ERROR2;
                }
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_WakeUpA_End2;
            }
            /*Symbol 0*/
            else
            {
                if(0U == bSetConfigDone2)
                {
                    /* Apply Guard time. */
                    PH_CHECK_SUCCESS_FCT2(status2, phhalHw_SetConfig2(
                        pDataParams2->pHalDataParams2,
                        PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2,
                        pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_A2]));
                    bSetConfigDone2 = 1U;
                }

                if(1U == bSetConfigDone2)
                {

                    /* Configure HW for the TypeA technology */
                    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(
                        pDataParams2->pHalDataParams2,
                        PHHAL_HW_CARDTYPE_ISO14443A2));
                    bSetConfigDone2 = 0U;
                    PH_BREAK_ON_FAILURE2(status2);
                    pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_WakeUpA_Run2;
                }
            }

            /* Reset card detected count */
            pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = 0;
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_WakeUpA_Run2:
            /* Send WakeUpA */
            PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_WakeUpA2(
                                    pDataParams2->pPal1443p3aDataParams2,
                                    pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aAtqa2));

            if ((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
            {
                /* In case of EMVCo, return Collision Pending status2. */
                if(pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2)
                {
                    pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Start2;
                    /* Report Error to Application and Application will perform PICC Reset */
                    return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_COLLISION_PENDING2, PH_COMP_AC_DISCLOOP2);
                }
                bCollDetected2 = PH_ON2;
            }

            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Set_Txwait2;
            return PH_STATUS_INPROCESS2;
            /* no break */

        case CollisionResolutionA_Set_Txwait2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2,
                    phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXWAIT_US2, 500U));

            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_WakeUpA_End2;
            return PH_STATUS_INPROCESS2;
            /* no break */
        case CollisionResolutionA_WakeUpA_End2:
            /*Symbol 1*/
            if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
            {
                /* Device count = 0 and any Error */
                if(((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
                  && (pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2] == 0x00U))
                {
                    pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = 0;
                    pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
                    break;
                }

                /*Symbol 1*/
                if ((status2 & PH_ERR_MASK2) != PH_ERR_COLLISION_ERROR2)
                {
                    pDataParams2->bCollPend2 &= (uint8)~(uint8)PHAC_DISCLOOP_POS_BIT_MASK_A2;
                    break;
                }
            }

            /*Symbol 3*/
            if(0U == (pDataParams2->bUseAntiColl2))
            {
                /*Symbol 25*/
                pDataParams2->bCollPend2 |= (uint8)PHAC_DISCLOOP_POS_BIT_MASK_A2;
                status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_COLLISION_PENDING2, PH_COMP_AC_DISCLOOP2);
                break;
            }
            if (bDeviceCount2 <= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2])
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Device_Loop2;
            }
            else
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Finish2;
            }
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_Device_Loop2:
            if (bTypeATagIdx2 <= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2])
            {
                /*Symbol 5*/
                pDataParams2->bCollPend2 &= (uint8)~(uint8)PHAC_DISCLOOP_POS_BIT_MASK_A2;
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_CascadeCode_Loop2;
                bCascadeCodeIdx2 = 0U;
                return PH_STATUS_INPROCESS2;
            }

            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Device_Loop_Check2;
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_CascadeCode_Loop2:
            /*Symbol 5, 17*/
            bTypeANvbUid2 = 0U;
            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Anticollision_Loop2; /* no break */

        case CollisionResolutionA_Anticollision_Loop2:
            /* Anti-collision loop */
            if (bTypeANvbUid2 != 0x40U)
            {
                /*Symbol 6,7,8*/
                PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_Anticollision2(
                        pDataParams2->pPal1443p3aDataParams2,
                        aCascadeCodes2[bCascadeCodeIdx2],      /* Cascade code */
                        aTypeAUid2,                           /* Input UID */
                        bTypeANvbUid2,                        /* UID len = 0 */
                        aTypeAUid2,                           /* UID out */
                        &bTypeANvbUid2                      /* UID out size */
                        ));
                /*Symbol 9, 14*/
                if ((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
                {
                    /*Symbol 10*/
                    pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
                    if(bTypeATagIdx2 >= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2])
                    {
                        /*Symbol 11*/
                        status2 = PH_ERR_SUCCESS2;
                        break;
                    }

                    /* Increment the number of valid bits and set the collision bit to one and handle based on Byte and Bit boundaries. */
                    if ((bTypeANvbUid2 & ((uint8)0x07U)) <  (uint8)7U)
                    {
                        bTypeANvbUid2++;

                        /* Set collision bit to 1 to resolve tag with highest UID */
                        aTypeAUid2[(uint8)((bTypeANvbUid2 & 0xF0U) >> 4U)] |= (uint8)(0x01U << ((bTypeANvbUid2 & ((uint8)0x07U)) - 1U));
                    }
                    else
                    {
                        bTypeANvbUid2 = (uint8)((((bTypeANvbUid2 & 0xF0U) >> 4U) + 1U) << 4U);

                        /* Set collision bit to 1 to resolve tag with highest UID */
                        aTypeAUid2[(uint8)(((bTypeANvbUid2 & 0xF0U) >> 4U) - 1U)] |= (uint8)(0x80U);
                    }
                }
                else
                {
                    /* Check success */
                    /* Some error that can't be handled */
                    PH_BREAK_ON_FAILURE2(status2);
                }
                return PH_STATUS_INPROCESS2;
            } /*End of if (bTypeANvbUid2 != 0x40U)*/

            /* Atqa(which indicates NFCID1 size) is invalid since collision is encountered while receiving Atqa */
            if (bCollDetected2 == PH_OFF2)
            {
                /* EMVCO: case_id 302_10 */
                /*
                * Digital Proto: Article 4.7.2 and 4.7.2.4
                * ISO14443-3 Article 6.5.2.1
                * EMVCo article 5.4.2
                * So For Single UID Size The NFC Forum Device MUST set nfcid10 of a single-size NFCID1 and nfcid13
                * of a double-size NFCID1 to a value different from 88h.
                */
                if(((0U == ((pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_A2))))
                   && ((((pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aAtqa2[0] & 0xC0U) == 0x00U)
                   && (aCascadeCodes2[bCascadeCodeIdx2] == PHPAL_I14443P3A_CASCADE_LEVEL_12))
                   || (((pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aAtqa2[0] & 0xC0U) == 0x40U)
                   && (aCascadeCodes2[bCascadeCodeIdx2] == PHPAL_I14443P3A_CASCADE_LEVEL_22)))
                   && (aTypeAUid2[0] == 0x88U))
                {
                    status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_AC_DISCLOOP2);
                    break;
                }
            }
            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Select2;
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_Select2:
            /*symbol 15*/
            PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_Select2(
                    pDataParams2->pPal1443p3aDataParams2,
                    aCascadeCodes2[bCascadeCodeIdx2],
                    aTypeAUid2,
                    &pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aSak2));

            if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
            {
                /*Symbol 16*/
                if ((0U == (pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aSak2 & 0x04U)))
                {
                    /*UID Complete*/
                    pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_CascadeCode_Loop_End2;
                    return PH_STATUS_INPROCESS2;
                }
            }
            else
            {
                break;
            }

            bCascadeCodeIdx2++;
            if (bCascadeCodeIdx2 < 3U)
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_CascadeCode_Loop2;
            }
            else
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_CascadeCode_Loop_End2;
            }
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_CascadeCode_Loop_End2:
            /* If select was successful */
            /*Symbol 19*/
            status2 = phpalI14443p3a_GetSerialNo2(
                pDataParams2->pPal1443p3aDataParams2,
                &pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aUid2[0],
                &pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].bUidSize2);

            PH_BREAK_ON_FAILURE2(status2);

            /*Symbol 18*/
            bTypeATagIdx2++;

            /*Symbol 20*/
            if((0U != ((pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_A2))) && (bTypeATagIdx2 < pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2]))
            {
                /* Symbol 21 */
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_HaltA2;
            }
            else
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Finish2;
            }
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_HaltA2:
            PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_HaltA2(pDataParams2->pPal1443p3aDataParams2));
            PH_BREAK_ON_FAILURE2(status2);
            /* Update the corresponding Layer 3 dataparam to indicate the Tag is in HALT State. */
            (pDataParams2->sTypeATargetInfo2).aTypeA_I3P32[bTypeATagIdx2 - (uint8)1U].bSleep2 = (uint8)1U;

            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_RequestA2;
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_RequestA2:
            /* Symbol 22 */
            PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_RequestA2(
                    pDataParams2->pPal1443p3aDataParams2,
                    pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aAtqa2));

            if((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
            {
                /*Symbol 4*/
                if(pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aAtqa2[0] == 0x00U)
                {
                    /*Symbol 25*/
                    pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
                    break;
                }
            }
            else if((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
            {
                /* More device to resolve */
                pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
            }
            else
            {
                break;
            }
            pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Device_Loop_Check2;
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_Device_Loop_Check2:
            bDeviceCount2++;
            if (bDeviceCount2 <= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2])
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Device_Loop2;
            }
            else
            {
                pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Finish2;
            }
            return PH_STATUS_INPROCESS2;

        case CollisionResolutionA_Finish2:
            pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 = bTypeATagIdx2;
            pDataParams2->bNumOfCards2 = bTypeATagIdx2;

            if(pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 == 0U)
            {
                status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
            }
            else
            {
                status2 = PH_ERR_SUCCESS2;
            }
            break;
        default:
            break;
    }
    pDataParams2->bDiscLoopCollisionResolutionAState2 = CollisionResolutionA_Start2;
    return status2;
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */
    PH_UNUSED_VARIABLE2(pDataParams2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateA2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bTypeATagIdx2)
{
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2)
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 aUid2[10] = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUidLen2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bMoreCardsAvailable2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTagType2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bActiveDevice2 = 0U;
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCidEnabled2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCid2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNadSupported2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFwi2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFsdi2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFsci2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bEmdEnabled2 = 0U;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */

    if (pDataParams2->bDiscLoopActivateAState2 == 0U)
    {
        bTagType2 = 0U;
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
        bEmdEnabled2 = 0U;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
        if ((bTypeATagIdx2 >= pDataParams2->sTypeATargetInfo2.bTotalTagsFound2)
                || (bTypeATagIdx2 >= PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2))
        {
            /* Out of range or no such card found yet */
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }

        if(pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2)
        {
            /* To fix coverity issue */
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_AC_DISCLOOP2);
        }

        /* If it is Single device or selected device is at last position, In both case device is already active */
        if((pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 <= PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2) && (pDataParams2->sTypeATargetInfo2.bTotalTagsFound2 > 1U)
                && (pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].bSleep2 == 1U)) /* Step 1 */
        {
            for (bIndex2 = 0; bIndex2 < pDataParams2->sTypeATargetInfo2.bTotalTagsFound2; bIndex2++)
            {
                /* Step 2 */
                if ((pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bIndex2].bSleep2 == 0U)
                        && (bIndex2 != bTypeATagIdx2))
                {
                    bActiveDevice2 = 1;
                    /* Update pDataParams2 to indicate that the tag will now be moved to IDLE state. */
                    pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bIndex2].bSleep2 = 1U;
                }
            }
            if (bActiveDevice2 != 0U)
            {
                /* Step 3 of Activation flow */
                pDataParams2->bDiscLoopActivateAState2 = 1U;
            }
            else
            {
                pDataParams2->bDiscLoopActivateAState2 = 2U;
            }
        }
        else
        {
            pDataParams2->bDiscLoopActivateAState2 = 3U;
        }
    }

    if (pDataParams2->bDiscLoopActivateAState2 == 1U)
    {
        PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_HaltA2(pDataParams2->pPal1443p3aDataParams2));
        if (status2 != PH_ERR_SUCCESS2)
        {
            /* Halt A has failed, can't count this as detected tag */
            pDataParams2->bDiscLoopActivateAState2 = 0U;
            return status2;
        }
        pDataParams2->bDiscLoopActivateAState2 = 2U;
    }

    if (pDataParams2->bDiscLoopActivateAState2 == 2U)
    {
        /* Activate the card in sleep with given UID */
        PH_CHECK_INPROCESS_FCT2(status2,
                phpalI14443p3a_ActivateCard2(pDataParams2->pPal1443p3aDataParams2,
                        ((pDataParams2->sTypeATargetInfo2).aTypeA_I3P32[bTypeATagIdx2]).aUid2,
                        ((pDataParams2->sTypeATargetInfo2).aTypeA_I3P32[bTypeATagIdx2]).bUidSize2, aUid2,
                        &bUidLen2,
                        &(((pDataParams2->sTypeATargetInfo2).aTypeA_I3P32[bTypeATagIdx2]).aSak2),
                        &bMoreCardsAvailable2));
        if (status2 != PH_ERR_SUCCESS2)
        {
            pDataParams2->bDiscLoopActivateAState2 = 0U;
            return status2;
        }

        pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].bSleep2 = 0U;
        pDataParams2->bDiscLoopActivateAState2 = 3U;
        return PH_STATUS_INPROCESS2;
    }

    if (pDataParams2->bDiscLoopActivateAState2 == 3U)
    {
        bTagType2 = (pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[bTypeATagIdx2].aSak2 & 0x60U);
        bTagType2 = bTagType2 >> 5U;
        /* Type 4A */
        if (bTagType2 == PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK2)
        {
#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2)
            if(0U == bEmdEnabled2)
            {
                /* Enable Emd Check */
            	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_SET_EMD2, PH_ON2));
                if (status2 != PH_ERR_SUCCESS2)
                {
                    pDataParams2->bDiscLoopActivateAState2 = 0U;
                    return status2;
                }
                bEmdEnabled2 = 1U;
                return PH_STATUS_INPROCESS2;
            }

            PH_CHECK_INPROCESS_FCT2(status2,
                    phpalI14443p4a_ActivateCard2(pDataParams2->pPal1443p4aDataParams2,
                            pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bFsdi2,
                            pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bCid2,
                            pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDri2,
                            pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDsi2,
                            pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.pAts2));
            bEmdEnabled2 = 0U;
            if (status2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->bDiscLoopActivateAState2 = 0U;
                return status2;
            }

            /* Retrieve 14443-4A protocol parameter */
            status2 = phpalI14443p4a_GetProtocolParams2(pDataParams2->pPal1443p4aDataParams2,
                    &bCidEnabled2, &bCid2, &bNadSupported2, &bFwi2, &bFsdi2, &bFsci2);
            if (status2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->bDiscLoopActivateAState2 = 0U;
                return status2;
            }

            /* Set 14443-4 protocol parameter */
            status2 = phpalI14443p4_SetProtocol2(pDataParams2->pPal14443p4DataParams2, bCidEnabled2,
                    bCid2, bNadSupported2, pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bNad2, bFwi2,
                    bFsdi2, bFsci2);
            if (status2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->bDiscLoopActivateAState2 = 0U;
                return status2;
            }
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
            return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
        }
        pDataParams2->bDiscLoopActivateAState2 = 4U;
        return PH_STATUS_INPROCESS2;
    }

    if (pDataParams2->bDiscLoopActivateAState2 == 4U)
    {
        /* Reset state machine in case of returning */
        pDataParams2->bDiscLoopActivateAState2 = 0U;
        if (bTagType2 == PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK2)
        {
            /* In case of EMVCo Profile*/
            if (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2)
            {
                /* Return to application with No device resolved; In EMVCo mode only Type-A ISO 14443-4 compliant cards should be activated. */
                return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
            }

            return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->bDiscLoopActivateAState2 = 5U;
    }

    if (pDataParams2->bDiscLoopActivateAState2 == 5U)
    {
        /* Support for both Type 4A and NFC-DEP (Merged SAK) */
        if (bTagType2 == PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK2)
        {
#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
            if (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2)
            {
                PH_CHECK_INPROCESS_FCT2(status2,
                        phpalI14443p4a_ActivateCard2(pDataParams2->pPal1443p4aDataParams2,
                                pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bFsdi2,
                                pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bCid2,
                                pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDri2,
                                pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDsi2,
                                pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.pAts2));
                if (status2 != PH_ERR_SUCCESS2)
                {
                    pDataParams2->bDiscLoopActivateAState2 = 0U;
                    return status2;
                }

                /* Retrieve 14443-4A protocol parameter */
                status2 = phpalI14443p4a_GetProtocolParams2(pDataParams2->pPal1443p4aDataParams2,
                        &bCidEnabled2, &bCid2, &bNadSupported2, &bFwi2, &bFsdi2, &bFsci2);
                if (status2 != PH_ERR_SUCCESS2)
                {
                    pDataParams2->bDiscLoopActivateAState2 = 0U;
                    return status2;
                }

                /* Set 14443-4 protocol parameter */
                status2 = phpalI14443p4_SetProtocol2(pDataParams2->pPal14443p4DataParams2, bCidEnabled2,
                        bCid2, bNadSupported2, pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bNad2, bFwi2,
                        bFsdi2, bFsci2);
                if (status2 != PH_ERR_SUCCESS2)
                {
                    pDataParams2->bDiscLoopActivateAState2 = 0U;
                    return status2;
                }
            }
            else
#endif /*  NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
            {
                /* Return to application; application can decide what to send RATS or ATR */
                pDataParams2->bDiscLoopActivateAState2 = 0U;
                return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2,
                        PH_COMP_AC_DISCLOOP2);
            }
        }
    }

    pDataParams2->bDiscLoopActivateAState2 = 0U;
    /* Case of EMVCo Profile and type 2 tag */
    if ((bTagType2 == PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK2)
            && (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2))
    {
        /* Return to application with No device resolved; In EMVCo mode only Type-A ISO 14443-4 compliant cards should be activated. */
        return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
    }

    return PH_ERR_SUCCESS2;
#else /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */
    PH_UNUSED_VARIABLE2(pDataParams2);
    PH_UNUSED_VARIABLE2(bTypeATagIdx2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_A_AR_RELEASE_MINOR_VERSION_C2== 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif
