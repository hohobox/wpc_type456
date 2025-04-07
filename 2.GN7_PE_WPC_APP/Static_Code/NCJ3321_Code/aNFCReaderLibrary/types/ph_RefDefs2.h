/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2021
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
*   @file    ph_RefDefs2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR RefDefs - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup ph_RefDefs Platform Definitions
*   @ingroup phothers
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
#ifndef PH_REFDEFS2_H
#define PH_REFDEFS2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ph_TypeDefs2.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           ph_RefDefs2.h
* @implements     DESIGN001, DESIGN002
*/
#define PH_REFDEFS_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PH_REFDEFS_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PH_REFDEFS_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PH_REFDEFS_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PH_REFDEFS_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PH_REFDEFS_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PH_REFDEFS_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PH_REFDEFS_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PH_REFDEFS_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "ph_RefDefs2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PH_REFDEFS_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PH_REFDEFS_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PH_REFDEFS_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of ph_RefDefs2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PH_REFDEFS_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PH_REFDEFS_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PH_REFDEFS_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of ph_RefDefs2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup ph_RefDefs Platform Definitions
* \ingroup phOthers
* \brief Platform depending definitions for memory location of variables.
*
* We distinguish between:
*   - BUFFERs   : Location of storage, usually mid-speed but max. RAM consumption,
*   - COUNTERs  : loop counters or frequently accessed variables, fast access,
*   - REMINDERs : variables holding status values or serving flow control purposes.
*
* If RCL is used on a microcontroller, an own REFDEF.H file must be generated where the
* RCL_MEMLOC_... definition must get according values. Default definitions are empty.
*
* Assignment Example: XDATA for #PH_MEMLOC_BUF2,
*                     IDATA for #PH_MEMLOC_COUNT2,
*                     EDATA for #PH_MEMLOC_REM2.
* @{
*/

/**
*  Space used for storage (e.g. buffers).
*/
#define PH_MEMLOC_BUF2   /* */

/**
* Space used for fast and frequent access e.g. counters, loop variables).
*/
#define PH_MEMLOC_COUNT2 /* */

/**
* Space used for control variables, these could be e.g. status values.
*/
#define PH_MEMLOC_REM2   /* */

/**
* Space used for constants, these could be e.g. lookup tables.
*/
#define PH_MEMLOC_CONST_ROM2 /* */

/**
* Macro for unused params in functions
*/
#define UNUSED2(param2) (void)(param2)

/**
 * end of group ph_RefDefs2 Platform Definitions
 * @}
 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */

#endif /*  PH_REFDEFS2_H */
