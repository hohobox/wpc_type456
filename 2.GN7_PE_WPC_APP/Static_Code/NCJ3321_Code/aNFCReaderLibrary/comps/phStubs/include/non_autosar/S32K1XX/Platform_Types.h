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
*   @file           Platform_Types.h
*   @implements     Platform_Types.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Platform dependent data type definitions.
*   @details AUTOSAR platform types header file. It contains all 
*            platform dependent types and symbols. Those types must be abstracted in order to 
*            become platform and compiler independent.
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
* @note         It is not allowed to add any extension to this file. Any extension invalidates the 
*               AUTOSAR conformity
*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Platform_Types_h_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for identifiers
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_VENDOR_ID                      43
/*
 * @violates @ref Platform_Types_h_REF_1 This is required as per autosar Requirement, 
 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       4
/*
 * @violates @ref Platform_Types_h_REF_1 This is required as per autosar Requirement, 
 */
#define PLATFORM_AR_RELEASE_MINOR_VERSION       3
/*
 * @violates @ref Platform_Types_h_REF_1 This is required as per autosar Requirement, 
 */
#define PLATFORM_AR_RELEASE_REVISION_VERSION    1
#define PLATFORM_SW_MAJOR_VERSION               1
#define PLATFORM_SW_MINOR_VERSION               0
#define PLATFORM_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          8bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_8 8

/**
* @brief          16bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_16 16

/**
* @brief          32bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_32 32

/**
* @brief          64bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_64 64

/**
* @brief          MSB First Processor
* @implements     CPU_BIT_ORDER_enumeration
*/
#define MSB_FIRST 0

/**
* @brief          LSB First Processor
* @implements     CPU_BIT_ORDER_enumeration
*/
#define LSB_FIRST 1

/**
* @brief          HIGH_BYTE_FIRST Processor
* @implements     CPU_BYTE_ORDER_enumeration
*/
#define HIGH_BYTE_FIRST 0

/** 
* @brief          LOW_BYTE_FIRST Processor
* @implements     CPU_BYTE_ORDER_enumeration
*/
#define LOW_BYTE_FIRST 1

/** 
* @brief          Processor type
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE (CPU_TYPE_64)    // CTY2B9
/**
* @brief          Bit order on register level.
* @implements     CPU_BIT_ORDER_enumeration
*/
#define CPU_BIT_ORDER (MSB_FIRST)

/** 
* @brief The byte order on memory level shall be indicated in the platform types header file using 
*        the symbol CPU_BYTE_ORDER.
* @implements     CPU_BYTE_ORDER_enumeration
*/
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)

#ifndef TRUE
    /** 
    * @brief Boolean true value
    * @implements TRUE_FALSE_enumeration
    */
    #define TRUE 1
#endif
#ifndef FALSE
    /** 
    * @brief Boolean false value
    * @implements TRUE_FALSE_enumeration
    */
    #define FALSE 0
#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
  
#if (CPU_TYPE == CPU_TYPE_64)
/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;

/** 
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_type
*/
typedef unsigned char uint8;

/** 
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 
*        16 bit
* @implements uint16_type
*/
typedef unsigned short uint16;

/** 
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 
*        32 bit
* @implements uint32_type
*/
typedef unsigned int uint32;

/** 
* @brief Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)-
*        64 bit
* 
*/
typedef unsigned long long uint64;

/** 
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 
*        7 bit + 1 sign bit 
* @implements sint8_type
*/
typedef signed char sint8;

/** 
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 
*        15 bit + 1 sign bit 
* @implements sint16_type
*/
typedef signed short sint16;

/** 
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 
*        31 bit + 1 sign bit 
* @implements sint32_type
*/
typedef signed int sint32;


/** 
* @brief Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF )- 
*        63 bit + 1 sign bit 
* 
*/
typedef signed long long sint64;


/** 
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_least_type
*/
typedef unsigned int uint8_least;

/** 
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) - 
*         16 bit
* @implements uint16_least_type
*/
typedef unsigned int uint16_least;

/** 
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 
*       (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_least_type
*/
typedef unsigned int uint32_least;

/** 
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127. 
*        At least 7 bit + 1 bit sign
* @implements sint8_least_type
*/
typedef signed int sint8_least;

/** 
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767. 
*        At least 15 bit + 1 bit sign
* @implements sint16_least_type
*/
typedef signed int sint16_least;

/** 
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647. 
*       At least 31 bit + 1 bit sign
* @implements sint32_least_type
*/
typedef signed int sint32_least;

/** 
* @brief 32bit long floating point data type
* @implements float32_type
*/
typedef float float32;

/** 
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_32)

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;


/** 
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_type
*/
typedef unsigned char uint8;

/** 
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 
*        16 bit
* @implements uint16_type
*/
typedef unsigned short uint16;

/** 
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 
*        32 bit
* @implements uint32_type
*/
typedef unsigned long uint32;

/** 
* @brief Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)-
*        64 bit
* 
*/
typedef unsigned long long uint64;


/** 
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 
*        7 bit + 1 sign bit 
* @implements sint8_type
*/
typedef signed char sint8;

/** 
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 
*        15 bit + 1 sign bit 
* @implements sint16_type
*/
typedef signed short sint16;

/** 
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 
*        31 bit + 1 sign bit 
* @implements sint32_type
*/
typedef signed long sint32;

/** 
* @brief Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF )- 
*        63 bit + 1 sign bit 
* 
*/
typedef signed long long sint64;

/** 
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_least_type
*/
typedef unsigned long uint8_least;

/** 
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) - 
*         16 bit
* @implements uint16_least_type
*/
typedef unsigned long uint16_least;

/** 
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 
*       (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_least_type
*/
typedef unsigned long uint32_least;

/** 
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127. 
*        At least 7 bit + 1 bit sign
* @implements sint8_least_type
*/
typedef signed long sint8_least;

/** 
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767. 
*        At least 15 bit + 1 bit sign
* @implements sint16_least_type
*/
typedef signed long sint16_least;

/** 
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647. 
*       At least 31 bit + 1 bit sign
* @implements sint32_least_type
*/
typedef signed long sint32_least;

/** 
* @brief 32bit long floating point data type
* @implements float32_type
*/
typedef float float32;

/** 
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef double float64;


#elif (CPU_TYPE == CPU_TYPE_16)

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;


/** 
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_type
*/
typedef unsigned char uint8;

/** 
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 
*        16 bit
* @implements uint16_type
*/
typedef unsigned short uint16;

/** 
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 
*        32 bit
* @implements uint32_type
*/
typedef unsigned long uint32;

/** 
* @brief Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)-
*        64 bit
* 
*/
typedef unsigned long long uint64;


/** 
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 
*        7 bit + 1 sign bit 
* @implements sint8_type
*/
typedef signed char sint8;

/** 
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 
*        15 bit + 1 sign bit 
* @implements sint16_type
*/
typedef signed short sint16;

/** 
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 
*        31 bit + 1 sign bit 
* @implements sint32_type
*/
typedef signed long sint32;

/** 
* @brief Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF )- 
*        63 bit + 1 sign bit 
* 
*/
typedef signed long long sint64;

/** 
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_least_type
*/
typedef unsigned long uint8_least;

/** 
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) - 
*         16 bit
* @implements uint16_least_type
*/
typedef unsigned long uint16_least;

/** 
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 
*       (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_least_type
*/
typedef unsigned long uint32_least;

/** 
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127. 
*        At least 7 bit + 1 bit sign
* @implements sint8_least_type
*/
typedef signed long sint8_least;

/** 
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767. 
*        At least 15 bit + 1 bit sign
* @implements sint16_least_type
*/
typedef signed long sint16_least;

/** 
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647. 
*       At least 31 bit + 1 bit sign
* @implements sint32_least_type
*/
typedef signed long sint32_least;

/** 
* @brief 32bit long floating point data type
* @implements float32_type
*/
typedef float float32;

/** 
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef double float64;

#endif


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


#endif /* #ifndef PLATFORM_TYPES_H */

/** @} */
