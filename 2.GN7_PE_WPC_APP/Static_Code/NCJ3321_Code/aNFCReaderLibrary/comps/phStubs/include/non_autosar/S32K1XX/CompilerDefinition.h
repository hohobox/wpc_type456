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
*   @file           CompilerDefinition.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction
*   @details The file Compiler.h provides macros for the encapsulation of definitions and
*            declarations.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup BASE_COMPONENT
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section CompilerDefinition_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section CompilerDefinition_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section CompilerDefinition_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initializer, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section CompilerDefinition_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section CompilerDefinition_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for identifiers.
* @section CompilerDefinition_h_REF_6
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance
* and case sensitivity are supported for external identifiers.
*/

#ifndef COMPILERDEFINITION_H
#define COMPILERDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILERDEFINITION_VENDOR_ID                      43
/*
 * @violates @ref CompilerDefinition_h_REF_5 This is required as per autosar Requirement,
 */
#define COMPILERDEFINITION_AR_RELEASE_MAJOR_VERSION       4
/*
 * @violates @ref CompilerDefinition_h_REF_5 This is required as per autosar Requirement,
 */
/** @violates @ref CompilerDefinition_h_REF_6 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers */
#define COMPILERDEFINITION_AR_RELEASE_MINOR_VERSION       3
/*
 * @violates @ref CompilerDefinition_h_REF_5 This is required as per autosar Requirement,
 */
/** @violates @ref CompilerDefinition_h_REF_6 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers */
#define COMPILERDEFINITION_AR_RELEASE_REVISION_VERSION    1
#define COMPILERDEFINITION_SW_MAJOR_VERSION               1
#define COMPILERDEFINITION_SW_MINOR_VERSION               0
#define COMPILERDEFINITION_SW_PATCH_VERSION               0
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef __ghs__
    /**
    * @brief Symbol required to be defined when GreenHills compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _GREENHILLS_C_S32K14x_
#endif
#ifdef __DCC__
    /**
    * @brief Symbol required to be defined when Diab compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _DIABDATA_C_S32K14x_
#endif
#ifdef __MWERKS__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _CODEWARRIOR_C_S32K14x_
#endif
#ifdef __CSMC__
    /**
    * @brief Symbol required to be defined when Cosmic compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
  #define _COSMIC_C_S32K14x_
#endif
#ifdef __GNUC__
           /**
        * @brief Symbol required to be defined when Linaro ARM compiler is used.
        */
        /*
        * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _LINARO_C_S32K14x_
 #endif      
#ifdef __CC_ARM 
        /**
        * @brief Symbol required to be defined when DS5 ARM compiler is used.
        */
        /*
        * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _ARM_DS5_C_S32K14x_     
#endif
#ifdef __ICCARM__ 
        /**
        * @brief Symbol required to be defined when IAR compiler is used.
        */
        /*
        * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _IAR_C_S32K14x_     
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILERDEFINITION_H */

/** @} */
