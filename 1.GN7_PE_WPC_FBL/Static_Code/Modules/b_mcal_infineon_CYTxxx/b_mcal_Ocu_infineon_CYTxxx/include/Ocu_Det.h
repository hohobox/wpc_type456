#ifndef OCU_DET_H_INCLUDED
#define OCU_DET_H_INCLUDED

/** \brief AUTOSAR Ocu Driver
 **
 ** This file contains development error processing macros used by the library.
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
#include <Ocu_Cfg.h>     /* Generated OCU driver config */

#if OCU_DEV_ERROR_DETECT == STD_ON
#include <Det.h>         /* DET declaration */
#endif /* #if OCU_DEV_ERROR_DETECT == STD_ON */

/*==================[macros]=================================================*/
/** \brief DET instance ID for OCU module. */
#ifdef OCU_INSTANCE_ID_DET /* to prevent double declaration */
#  error OCU_INSTANCE_ID_DET already defined
#else
#  define OCU_INSTANCE_ID_DET 0U
#endif /* ifdef OCU_INSTANCE_ID_DET */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]==========================*/
#define OCU_START_SEC_CODE_ASIL_B
#include <Ocu_MemMap.h>

/** \brief Ocu_ReportError
 **
 ** Reports an error to the error handler and optionally to the DET.
 **
 ** \param [in] ErrorId  Error identifier.
 ** \param [in] ApiId    API identifier.
 **
 */
extern FUNC(void, OCU_CODE) Ocu_ReportError
(
  VAR(uint8, AUTOMATIC) ErrorId,
  VAR(uint8, AUTOMATIC) ApiId
);

#define OCU_STOP_SEC_CODE_ASIL_B
#include <Ocu_MemMap.h>

/*==================[internal function declarations]==========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /*!defined(OCU_DET_H_INCLUDED)*/
/*==================[end of file]===========================================*/
