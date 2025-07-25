/** \brief AUTOSAR Fee Flash EEPROM Emulation
 **
 ** This file defines the interface of the AUTOSAR module Fee.
 **
 ** Do not edit this file manually.
 ** Any change might compromise the safety integrity level of
 ** the software partition it is contained in.
 **
 ** Product: SW-FEE42-DRV
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

#ifndef FEE_VERSION_H_INCLUDED
#define FEE_VERSION_H_INCLUDED


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
/*!< */
#define FEE_VENDOR_ID  66U
/*!< */
#define FEE_MODULE_ID  21U
/*!< */
#define FEE_SW_MAJOR_VERSION  1U
/*!< */
#define FEE_SW_MINOR_VERSION  13U
/*!< */
#define FEE_SW_PATCH_VERSION  FEE_GEN_SW_PATCH_VERSION
/*!< */
#define FEE_AR_RELEASE_MAJOR_VERSION  4U
/*!< */
#define FEE_AR_RELEASE_MINOR_VERSION  2U
/*!< */
#define FEE_AR_RELEASE_REVISION_VERSION  2U

/**
 * Macro for checking the consistency of AUTOSAR Spec versions of the
 * different files of the module
 */
/* Deviation from MISRA-C:2004 rule 19.7, MISRA-C:2012 Dir-4.9
   Justification: This deviation is due to use of code block as macro function because of being used from pre-processor. */
/* PRQA S 3453 10 */
#define FEE_AR_VERSION_CHECK(                                                       \
    file_ar_release_major_version,                                                  \
    file_ar_release_minor_version,                                                  \
    file_ar_release_revision_version                                                \
    )                                                                               \
    (                                                                               \
        ((FEE_AR_RELEASE_MAJOR_VERSION) == (file_ar_release_major_version)) &&      \
        ((FEE_AR_RELEASE_MINOR_VERSION) == (file_ar_release_minor_version)) &&      \
        ((FEE_AR_RELEASE_REVISION_VERSION) == (file_ar_release_revision_version))   \
    )

/**
 * Macro for checking the consistency of the software versions of the
 * different files of the Fee module
 */
/* Deviation from MISRA-C:2004 rule 19.7, MISRA-C:2012 Dir-4.9
   Justification: This deviation is due to use of code block as macro function because of being used from pre-processor. */
/* PRQA S 3453 8 */
#define FEE_SW_VERSION_CHECK(                                  \
    file_sw_major_version,                                     \
    file_sw_minor_version                                      \
    )                                                          \
    (                                                          \
        ((FEE_SW_MAJOR_VERSION) == (file_sw_major_version)) && \
        ((FEE_SW_MINOR_VERSION) == (file_sw_minor_version))    \
    )

/**
 * Macro for checking the consistency of Module ID and Vendor ID
 */
/* Deviation from MISRA-C:2004 rule 19.7, MISRA-C:2012 Dir-4.9
   Justification: This deviation is due to use of code block as macro function because of being used from pre-processor. */
/* PRQA S 3453 7 */
#define FEE_EXTRA_CHECK(                       \
    module_id,vendor_id                        \
    )                                          \
    (                                          \
        ((FEE_MODULE_ID) == (module_id)) &&    \
        ((FEE_VENDOR_ID) == (vendor_id))       \
    )



/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/



#endif /*!defined(FEE_VERSION_H_INCLUDED)*/

