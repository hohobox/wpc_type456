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
*   @file           Compiler.h
*   @implements     Compiler.h_Artifact
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
* @section Compiler_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section Compiler_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section Compiler_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initializer, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section Compiler_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section Compiler_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for identifiers.
*/

/**
* @file         Compiler.h
* @requirements COMPILER047
*/
#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Compiler_Cfg.h"
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILER_VENDOR_ID                      43
/*
 * @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement, 
 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION       4
/*
 * @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement, 
 */
#define COMPILER_AR_RELEASE_MINOR_VERSION       3
/*
 * @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement, 
 */
#define COMPILER_AR_RELEASE_REVISION_VERSION    1
#define COMPILER_SW_MAJOR_VERSION               1
#define COMPILER_SW_MINOR_VERSION               0
#define COMPILER_SW_PATCH_VERSION               0
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

/**
* @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration
*        of local pointers.
*/
#define AUTOMATIC

/**
* @brief The memory class TYPEDEF shall be provided as empty definition. This memory class shall be
*        used within type definitions, where no memory qualifier can be specified. This can be
*        necessary for defining pointer types, with e.g. P2VAR, where the macros require two
*        parameters. First parameter can be specified in the type definition (distance to the memory
*        location referenced by the pointer), but the second one (memory allocation of the pointer
*        itself) cannot be defined at this time. Hence memory class TYPEDEF shall be applied.
*/
#define TYPEDEF

/**
* @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero
*        definition.
*/
#define NULL_PTR ((void *)0)

/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __interrupt
#endif /* #ifdef _GREENHILLS_C_S32K14x_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE              __inline__

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline__

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __interrupt__
#endif /* #ifdef _DIABDATA_C_S32K14x_ */

/*************************************** CodeWarrior **********************************************/
#ifdef _CODEWARRIOR_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline

     /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __declspec(interrupt nowarn)
 #endif /* #ifdef _CODEWARRIOR_C_S32K14x_ */

/*************************************** Cosmic ***************************************************/
#ifdef _COSMIC_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE @inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static @inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC @interrupt
#endif /* #ifdef _COSMIC_C_S32K14x_ */
/*************************************** HighTec **********************************************/
#ifdef _HITECH_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

/**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
*/
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define INTERRUPT_FUNC      __attribute__((interrupt));
#endif /* #ifdef _HITECH_C_S32K14x_ */

/**************************************** Linaro *********************************************/
#ifdef _LINARO_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE                  inline __attribute__((always_inline))

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline __attribute__((always_inline))

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC     
#endif /* #ifdef _LINARO_C_S32K14x_ */
/**************************************** DS5 *************************************************/
#ifdef _ARM_DS5_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC
#endif /* #ifdef _ARM_DS5_C_S32K14x_ */

/**************************************** IAR *************************************************/
#ifdef _IAR_C_S32K14x_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC
#endif /* #ifdef _IAR_C_S32K14x_ */


/**
* @brief The compiler abstraction shall define the FUNC macro for the declaration and definition of
*        functions, that ensures correct syntax of function declarations as required by a specific
*        compiler.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FUNC(rettype, memclass) rettype

/**
* @brief The compiler abstraction shall define the P2VAR macro for the declaration and definition of
*        pointers in RAM, pointing to variables.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
* @brief The compiler abstraction shall define the P2CONST macro for the declaration and definition
*        of pointers in RAM pointing to constants.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

/**
* @brief The compiler abstraction shall define the CONSTP2VAR macro for the declaration and
*        definition of constant pointers accessing variables.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/**
* @brief The compiler abstraction shall define the CONSTP2CONST macro for the declaration and
*        definition of constant pointers accessing constants.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/**
* @brief The compiler abstraction shall define the P2FUNC macro for the type definition of pointers
*        to functions.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/**
* @brief The compiler abstraction shall define the CONST macro for the declaration and definition of
*        constants.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONST(consttype, memclass) const consttype

/**
* @brief The compiler abstraction shall define the VAR macro for the declaration and definition of
*        variables.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define VAR(vartype, memclass) vartype


/**
* @brief The compiler abstraction for const pointer to function.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, a constant, a parenthesised expression
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)


/**
* @brief The compiler abstraction shall define the FUNC_P2CONST macro for the declaration and 
* definition of functions returning a pointer to a constant
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, a constant, a parenthesised expression
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass

/**
* @brief The compiler abstraction shall define the FUNC_P2VAR macro for the declaration and 
* definition of functions returning a pointer to a variable.
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initializer, a constant, a parenthesised expression
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass
 
/*==================================================================================================
*                                             ENUMS
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

#endif /* #ifndef COMPILER_H */

/** @} */
