#ifndef DIO_DET_H
#define DIO_DET_H

/** \brief AUTOSAR Dio Dio Driver
 **
 ** This file contains development error processing macros
 ** used by the library.
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
#include <Std_Types.h>          /* AUTOSAR standard types */
#include <Dio_Cfg.h>         /* include generated configuration
                                with all symbolic names */
/*==================[macros]=================================================*/
#if !(defined DIO_DEV_ERROR_DETECT)
#error "DIO_DEV_ERROR_DETECT not set"
#endif
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>

#if (defined DIO_INSTANCE_ID_DET) /* to prevent double declaration */
#error DIO_INSTANCE_ID_DET already defined
#endif /* if (defined DIO_INSTANCE_ID_DET) */

/** \brief Dio instance id used for Det reports */
#define DIO_INSTANCE_ID_DET 0u

#endif
/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

#define DIO_START_SEC_CODE_ASIL_B
#include <Dio_MemMap.h>

/** \brief Dio_ReportDetError
 **
 ** This function reports an error to the error handler and
 ** optionally to the DET.
 **
 ** \param[in]  ApiId   Id of the service that detected the error.
 ** \param[in]  ErrorId Id of the error that was detected.
 **
 ** \retval     none
 */
extern FUNC(void, DIO_CODE) Dio_ReportDetError(
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) ErrorId
    );

#define DIO_STOP_SEC_CODE_ASIL_B
#include <Dio_MemMap.h>

/*==================[internal function definitions]==========================*/

#endif /* DIO_DET_H */
/*==================[end of file]============================================*/
