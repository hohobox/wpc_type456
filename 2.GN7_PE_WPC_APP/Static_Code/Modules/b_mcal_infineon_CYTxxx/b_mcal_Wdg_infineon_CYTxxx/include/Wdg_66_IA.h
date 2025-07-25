
#ifndef WDG_66_IA_H
#define WDG_66_IA_H 1

/** \brief AUTOSAR Wdg Driver
 **
 ** This file contains or includes all external identifiers of
 ** the AUTOSAR module Wdg.
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

/*==================[inclusions]=============================================*/

#include <Wdg_66_IA_Types.h>
#include <Wdg_66_IA_Version.h>
#include <Wdg_66_IA_PBcfg.h>
#include <Wdg_66_IA_Api.h>

/*------------------[AUTOSAR configuration AR version number check]----------*/

#if !defined( WDG_66_IA_GEN_AR_RELEASE_MAJOR_VERSION)
#  error WDG_66_IA_GEN_AR_RELEASE_MAJOR_VERSION not defined
#elif !defined( WDG_66_IA_GEN_AR_RELEASE_MINOR_VERSION)
#  error WDG_66_IA_GEN_AR_RELEASE_MINOR_VERSION not defined
#elif !defined( WDG_66_IA_GEN_AR_RELEASE_REVISION_VERSION)
#  error WDG_66_IA_GEN_AR_RELEASE_REVISION_VERSION not defined
#endif

/*------------------[AUTOSAR configuration SW version number check]----------*/

#if !defined( WDG_66_IA_GEN_SW_MAJOR_VERSION)
#  error WDG_66_IA_GEN_SW_MAJOR_VERSION not defined
#elif !defined( WDG_66_IA_GEN_SW_MINOR_VERSION)
#  error WDG_66_IA_GEN_SW_MINOR_VERSION not defined
#elif !defined( WDG_66_IA_GEN_SW_PATCH_VERSION)
#  error WDG_66_IA_GEN_SW_PATCH_VERSION not defined
#elif ( ((WDG_66_IA_SW_MAJOR_VERSION) != (WDG_66_IA_GEN_SW_MAJOR_VERSION)) || \
        ((WDG_66_IA_SW_MINOR_VERSION) != (WDG_66_IA_GEN_SW_MINOR_VERSION)) )
#  error AUTOSAR WDG configuration AR version number mismatch
#endif

/*------------------[AUTOSAR configuration additional check]-----------------*/

#if !defined(WDG_66_IA_GEN_MODULE_ID)
#  error WDG_66_IA_GEN_MODULE_ID not defined
#elif !defined(WDG_66_IA_GEN_VENDOR_ID)
#  error WDG_66_IA_GEN_VENDOR_ID not defined
#elif !defined(WDG_66_IA_GEN_VENDOR_API_INFIX)
#  error WDG_66_IA_GEN_VENDOR_API_INFIX not defined
#endif

/*==================[macros]=================================================*/
/*==================[type definitions]=======================================*/
/*==================[external function declarations]=========================*/
/*==================[internal function declarations]=========================*/
/*==================[external constants]=====================================*/
/*==================[internal constants]=====================================*/
/*==================[external data]==========================================*/
/*==================[internal data]==========================================*/
/*==================[external function definitions]==========================*/
/*==================[internal function definitions]==========================*/

#endif /* if !defined( WDG_66_IA_H ) */
/*==================[end of file]============================================*/
