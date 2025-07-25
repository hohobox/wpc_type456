/** \brief AUTOSAR Dio DIO Driver
 **
 ** This file contains Interface for calls to the Schedule Manager.
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
#include <Dio_SchM.h>          /* Defines interface of SchM function. */
#include <SchM_Dio.h>          /* Schedule Manager for DIO module */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/
#define DIO_START_SEC_CODE_ASIL_B
#include <Dio_MemMap.h>

/** \brief  Dio_EnterCriticalSection
 **
 ** This function is process of entering critical secttion.
 **
 ** \param[in]  none 
 ** \param[out] none 
 **
 ** \retval     none
 ** */
FUNC(void, DIO_CODE) Dio_EnterCriticalSection(void)
{
   /* lock interrupts: read-modify-store on most architectures */
   SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_0();
}


/** \brief  Dio_ExitCriticalSection
 **
 ** This function is process of exiting critical section.
 **
 ** \param[in]  none 
 ** \param[out] none 
 **
 ** \retval     none
 ** */
FUNC(void, DIO_CODE) Dio_ExitCriticalSection(void)
{
   /* exit critical section */
   SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_0();
}

#define DIO_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1
   Justification: In AUTOSAR specification, it is a necessary process. */
/* PRQA S 5087 1 */
#include <Dio_MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
