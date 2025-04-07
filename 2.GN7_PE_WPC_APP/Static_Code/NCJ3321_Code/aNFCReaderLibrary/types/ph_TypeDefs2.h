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
*   @file    ph_Typedefs2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR TypeDefs - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup ph_Typedefs Type Definitions
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
#ifndef PH_TYPEDEFS2_H
#define PH_TYPEDEFS2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <Std_Types.h>
#ifdef linux
#include <sys/types.h>
#endif
#include <CDD_AnfcRL_Cfg.h>

#include <stdbool.h>    /* NIDEC_PORTING */

#if defined NXPBUILD__PH_DEBUG2
#include <stdio.h>
#endif /* NXPBUILD__PH_DEBUG2 */

#if defined(__GNUC__ ) /* Toolchain with StdInt */
    #include <stdint.h>
    #ifdef __CODE_RED
        #include <lpc_types.h>
    #endif
    #include <stdbool.h>
#elif defined(__ICCARM__)
    #include <intrinsics.h>
    #include <stdint.h>

#elif defined(__CC_ARM)
    #include <stdint.h>
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           ph_Typedefs2.h
* @implements     DESIGN001, DESIGN002
*/
#define PH_TYPEDEFS_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PH_TYPEDEFS_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PH_TYPEDEFS_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PH_TYPEDEFS_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PH_TYPEDEFS_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PH_TYPEDEFS_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PH_TYPEDEFS_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PH_TYPEDEFS_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PH_TYPEDEFS_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "ph_Typedefs2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PH_TYPEDEFS_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PH_TYPEDEFS_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PH_TYPEDEFS_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of ph_Typedefs2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PH_TYPEDEFS_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PH_TYPEDEFS_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PH_TYPEDEFS_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of ph_Typedefs2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup ph_Typedefs Type Definitions
* \ingroup phOthers
* \brief Contains definitions for types defined within NxpRdLib
* @{
*/
#if defined(__GNUC__ ) /* Toolchain with StdInt */
#elif defined(__ICCARM__)
#elif defined(__CC_ARM)
#else /* Toolchain not-with StdInt */

/* Enable/disable printf statements based on DTA_DEBUG macro */
#if defined NXPBUILD__PH_DEBUG2
#	define PRINT2(...)          printf(__VA_ARGS__) /**< PRQA S 1030. */
#else
#   define PRINT2(...)                              /**< PRQA S 1030. */
#endif

/**
* \name Boolean Types
*/
/*@{*/
#ifndef BOOL_DEFINED2
#    define BOOL_DEFINED2
#endif /* __BOOL_DEFINED2 */
/*@}*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* \name Unsigned Types
*/
/*@{*/
#ifndef __uint8_t_defined
/**
* \brief 8 bit unsigned integer
*/
typedef unsigned char uint8_t;	/* NIDEC_PORTING */
#endif /* __uint8_t_defined */

#ifndef __uint16_t_defined
/**
* \brief 16 bit unsigned integer
*/
typedef unsigned short uint16_t;	/* NIDEC_PORTING */
#endif /* __uint16_t_defined */

#ifndef __uint32_t_defined
/**
* \brief 32 bit and 64 bit unsigned integers
*/
typedef unsigned int uint32_t;	/* NIDEC_PORTING */
typedef unsigned long long uint64_t;
#endif /* __uint32_t_defined */

/**
* \name Signed Types
*/
/*@{*/
#ifndef __int8_t_defined
/**
* \brief 8 bit signed integer
*/
typedef signed char int8_t;	/* NIDEC_PORTING */
#endif /* __int8_t_defined */

#ifndef __int16_t_defined
/**
* \brief 16 bit signed integer
*/
typedef short int16_t;	/* NIDEC_PORTING */
#endif /* __int16_t_defined */

#ifndef __int32_t_defined
/**
* \brief 32 bit signed integer
*/
typedef int int32_t;	/* NIDEC_PORTING */
#endif /* __int32_t_defined */
/*@}*/

#endif  /* Toolchain with/not-with StdInt */

/**
* \name Floating-Point Types
*/
/*@{*/
#ifndef __float32_t_defined
/**
* \brief 32 bit floating point
*/
typedef float float32_t;
#endif /* __float32_t_defined */
/*@}*/

#ifndef __handle_defined
/**
*\brief Unsigned handle
*/
typedef uint32_t ph_NfcHandle;	/* NIDEC_PORTING */
#endif /* __handle_defined */
/*@}*/

/**
 * \brief Pointer to a 32 bits register
 */
typedef volatile uint32_t * pReg32_t2;	/* NIDEC_PORTING */

/**
* \name Other Types
*/
/*@{*/
/**
* \brief phcsBfl_Status_t is a signed short value, using the positive range.
*
* High byte: Category (group) Identifier.\n
* Low byte : Error Specifier.
*/
typedef uint16 phStatus_t2;

/* #ifndef NULL         */
/* #    define NULL 0   */
/* #endif               */
/*@}*/

/**
 * end of group ph_Typedefs Type Definitions
 * @}
 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */

#endif /* PH_TYPEDEFS2_H */
