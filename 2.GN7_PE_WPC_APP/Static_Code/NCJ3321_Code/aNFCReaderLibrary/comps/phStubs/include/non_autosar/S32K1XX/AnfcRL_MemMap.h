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
*   @file           AnfcRL_MemMap.h
*   @implements     AnfcRL_MemMap.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR AnfcRL - Memory mapping specification.
*   @details This document specifies mechanisms for the mapping of code and data to specific
*            memory sections via memory mapping file. For many ECUs and microcontroller platforms
*            it is of utmost necessity to be able to map code, variables and constants module
*            wise to specific memory sections.
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup ANFCRLConfigAutosar
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
#ifndef ANFCRL_MEMMAP_H
#define ANFCRL_MEMMAP_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once. This violation is not fixed since the inclusion of
* MemMap.h is as per AUTOSAR requirement.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, Macro not referenced
* Macros which are not currently referenced in code but can be used in the
* future or by user.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
*@section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 20.5, use of '#undef' is discouraged
* This is needed to comply with AUTOSAR coding rules
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref AnfcRL_MemMap_h_REF_2 Precautions shall be taken in order
* to prevent the contents of a header being included twice.
*/
/* @violates @ref AnfcRL_MemMap_h_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Compiler.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the memory map header file and also in the
*       module's description file
*/
#define ANFCRL_MEMMAP_VENDOR_ID                    43
#define ANFCRL_MEMMAP_MODULE_ID                    255
#define ANFCRL_MEMMAP_AR_RELEASE_MAJOR_VERSION     4
#define ANFCRL_MEMMAP_AR_RELEASE_MINOR_VERSION     3
#define ANFCRL_MEMMAP_AR_RELEASE_REVISION_VERSION  1
#define ANFCRL_MEMMAP_SW_MAJOR_VERSION             1
#define ANFCRL_MEMMAP_SW_MINOR_VERSION             0
#define ANFCRL_MEMMAP_SW_PATCH_VERSION             0
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief Symbol used for checking correctness of the includes
*/
// #define MEMMAP_ERROR

#define AUTOSAR_OS_NOT_USED // NIDEC_Porting

#ifndef AUTOSAR_OS_NOT_USED
        #include <Os_memmap.h>
#endif
/**************************************************************************************************/
/********************************************* GREENHILLS *****************************************/
/**************************************************************************************************/
#ifdef _GREENHILLS_C_S32K14x_
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".anfcrl_text"
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".acanfcrl_code_rom"
    #pragma ghs inlineprologue
#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif
/**************************************************************************************************/
/********************************************* DIAB ***********************************************/
/**************************************************************************************************/
#elif defined(_DIABDATA_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CODE ".ramcode" far-absolute
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma section CODE
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* use code relative addressing mode to ensure Position-independent Code (PIC) */
    #pragma section CODE ".acanfcrl_code_rom" far-code

#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma section CODE
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif


#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data" ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif


#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".anfcrl_data_no_cacheable" ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif
/**************************************************************************************************/
/********************************************* CODEWARRIOR ****************************************/
/**************************************************************************************************/
#elif defined(_CODEWARRIOR_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG mcal_text
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG acanfcrl_code_rom
#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif
/**************************************************************************************************/
/********************************************* COSMIC *********************************************/
/**************************************************************************************************/
#elif defined(_COSMIC_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (mcal_text)
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (ramcode)
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (acanfcrlcode)
#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif
/**************************************************************************************************/
/********************************************* HighTec *********************************************/
/**************************************************************************************************/
#elif defined(_HITECH_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const_cfg" a
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const_cfg" a
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const_cfg" a
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const_cfg" a
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const" a
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const" a
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const" a
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const" a
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_const" a
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_text" avx
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode" avx
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".acanfcrl_code_rom" avx
#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_bss" awsB
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_bss" awsB
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_bss" awsB
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_bss" awsB
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_bss" awsB
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_bss_no_cacheable" awsB
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_data" aws
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_data" aws
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_data" aws
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_data" aws
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".anfcrl_data" aws
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif
/**************************************************************************************************/
/********************************************* Linaro *********************************************/
/**************************************************************************************************/
#elif defined(_LINARO_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
/**************************************************************************************************/
/********************************************* DS5 ************************************************/
/**************************************************************************************************/
#elif defined(_ARM_DS5_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".anfcrl_text"
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode"
#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".acanfcrl_code_rom"
#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif




/**************************************************************************************************/
/********************************************* IAR ************************************************/
/**************************************************************************************************/
#elif defined(_IAR_C_S32K14x_)
/**************************************** ANFCRL *******************************/
#ifdef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const_cfg"
#endif

#ifdef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_const"
#endif

#ifdef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".anfcrl_text"
#endif

#ifdef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode"

#endif

#ifdef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_RAMCODE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =

#endif

#ifdef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".acanfcrl_code_rom"

#endif

#ifdef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_CODE_AC
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =

#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_data"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif


#ifdef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_bss_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".anfcrl_data_no_cacheable"
#endif

#ifdef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file AnfcRL_MemMap.h
    * @violates @ref AnfcRL_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif
#endif
/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "MemMap.h, no valid memory mapping symbol defined."
#endif

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*ANFCRL_MEMMAP_H */
/**@}*/
