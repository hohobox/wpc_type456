#ifndef GPT_VERSION_H
#define GPT_VERSION_H

/** \brief AUTOSAR Gpt GPT Driver
 **
 ** This file contains the declaration of the version of the
 ** AUTOSAR module Gpt.
 **
 ** Do not edit this file manually.
 ** Any change might compromise the safety integrity level of
 ** the software partition it is contained in.
 **
 ** Product: SW-MCAL42-DRV
 **
 ** (c) 2017-2022, Cypress Semiconductor Corporation (an Infineon company) or
 ** an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 ** This software, including source code, documentation and related materials
 ** ("Software") is owned by Cypress Semiconductor Corporation or one of
 ** its affiliates ("Cypress") and is protected by and subject to worldwide
 ** patent protection (United States and foreign), United States copyright laws
 ** and international treaty provisions.  Therefore, you may use this Software
 ** only as provided in the license agreement accompanying the software package
 ** from which you obtained this Software ("EULA").
 ** If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 ** non-transferable license to copy, modify,
 ** and compile the Software source code solely for use in connection
 ** with Cypress's integrated circuit products.
 ** Any reproduction, modification, translation, compilation,
 ** or representation of this Software except as specified above is prohibited
 ** without the express written permission of Cypress.
 ** Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 ** EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
 ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ** Cypress reserves the right to make changes to the Software without notice.
 ** Cypress does not assume any liability arising out of the application or
 ** use of the Software or any product or circuit described in the Software.
 ** Cypress does not authorize its products for use in any products
 ** where a malfunction or failure of the Cypress product may reasonably be
 ** expected to result in significant property damage,
 ** injury or death ("High Risk Product"). By including Cypress's product
 ** in a High Risk Product, the manufacturer of such system or application
 ** assumes all risk of such use and in doing so agrees to indemnify Cypress
 ** against all liability.
 */

/*==================[inclusions]============================================*/
#include <Std_Types.h>    /* AUTOSAR standard types */
#include <Gpt_Cfg.h>

/*==================[macros]================================================*/
/* Sanity checks */
#if defined(GPT_MODULE_ID)
#error "GPT_MODULE_ID is already defined"
#endif

#if defined(GPT_VENDOR_ID)
#error "GPT_VENDOR_ID is already defined"
#endif

#if defined(GPT_AR_RELEASE_MAJOR_VERSION)
#error "GPT_AR_RELEASE_MAJOR_VERSION is already defined"
#endif

#if defined(GPT_AR_RELEASE_MINOR_VERSION)
#error "GPT_AR_RELEASE_MINOR_VERSION is already defined"
#endif

#if defined(GPT_AR_RELEASE_REVISION_VERSION)
#error "GPT_AR_RELEASE_REVISION_VERSION is already defined"
#endif

#if defined(GPT_SW_MAJOR_VERSION)
#error "GPT_SW_MAJOR_VERSION is already defined"
#endif

#if defined(GPT_SW_MINOR_VERSION)
#error "GPT_SW_MINOR_VERSION is already defined"
#endif

#if defined(GPT_SW_PATCH_VERSION)
#error "GPT_SW_PATCH_VERSION is already defined"
#endif

/* Define the version info */ 
#define GPT_MODULE_ID                    100U
#define GPT_VENDOR_ID                    66U

#ifdef GPT_AR_RELEASE_MAJOR_VERSION /* to prevent double declaration */
#  error GPT_AR_RELEASE_MAJOR_VERSION already defined
#else
#define GPT_AR_RELEASE_MAJOR_VERSION     4U
#endif

#ifdef GPT_AR_RELEASE_MINOR_VERSION /* to prevent double declaration */
#  error GPT_AR_RELEASE_MINOR_VERSION already defined
#else
#define GPT_AR_RELEASE_MINOR_VERSION     2U
#endif

#ifdef GPT_AR_RELEASE_REVISION_VERSION /* to prevent double declaration */
#  error GPT_AR_RELEASE_REVISION_VERSION already defined
#else
#define GPT_AR_RELEASE_REVISION_VERSION  2U
#endif

#ifdef GPT_SW_MAJOR_VERSION /* to prevent double declaration */
#  error GPT_SW_MAJOR_VERSION already defined
#else
#define GPT_SW_MAJOR_VERSION             1U
#endif

#ifdef GPT_SW_MINOR_VERSION /* to prevent double declaration */
#  error GPT_SW_MINOR_VERSION already defined
#else
#define GPT_SW_MINOR_VERSION             13U
#endif

#ifdef GPT_SW_PATCH_VERSION /* to prevent double declaration */
#  error GPT_SW_PATCH_VERSION already defined
#else
#define GPT_SW_PATCH_VERSION             GPT_GEN_SW_PATCH_VERSION
#endif

/*==================[type definitions]======================================*/
/*==================[external function declarations]========================*/
/*==================[internal function declarations]========================*/
/*==================[external constants]====================================*/
/*==================[internal constants]====================================*/
/*==================[external data]=========================================*/
/*==================[internal data]=========================================*/
/*==================[external function definitions]=========================*/
/*==================[internal function definitions]=========================*/

#endif
/*==================[end of file]===========================================*/
