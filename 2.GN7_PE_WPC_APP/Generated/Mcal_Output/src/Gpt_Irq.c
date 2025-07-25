/** \brief AUTOSAR Gpt GPT Driver
 **
 ** This file contains the implementation of the AUTOSAR module Gpt
 ** for interruptions.
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
#include <Os.h>
#include <Gpt.h>
#include <Gpt_External.h>
#include <Gpt_Controller.h>
#include <Gpt_Status.h>
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include <EcuM.h>
#endif

/*==================[macros]================================================*/
/*==================[type definitions]======================================*/
/*==================[external function declarations]========================*/
/*==================[internal function declarations]========================*/
/*==================[external constants]====================================*/
/*==================[internal constants]====================================*/
/*==================[external data]=========================================*/
/*==================[internal data]=========================================*/
/*==================[external function definitions]=========================*/
/* Interrupt service routines.
 *
 * These interrupt service routines are generated assuming that the driver
 * will be running under the AutosarOs. If this is not the case, an ISR
 * macro must be provided.
*/
#define GPT_START_SEC_CODE_ASIL_B
#include <Gpt_MemMap.h>

/** \brief GPT_Isr_Vector_303_Cat1()
 **
 ** Gpt interrupt service routine (Cat1):
 ** Entry point for TCPWM_0_3's interrupt vector 303.
 **
 */
ISR_NATIVE(GPT_Isr_Vector_303_Cat1)
{
/* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4.
   Justification: The hardware address is provided as integral type by configuration. However, the hardware access must be handled by using pointer. */
/* PRQA S 303 1 */
  Gpt_IsrVector_Internal(GPT_HWRESOURCE_0_3, GPT_HWRESR_0_3_BASE);
}

/** \brief GPT_Isr_Vector_303_Cat2()
 **
 ** Gpt interrupt service routine (Cat2):
 ** Entry point for TCPWM_0_3's interrupt vector 303.
 **
 */
ISR(GPT_Isr_Vector_303_Cat2)
{
/* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4.
   Justification: The hardware address is provided as integral type by configuration. However, the hardware access must be handled by using pointer. */
/* PRQA S 303 1 */
  Gpt_IsrVector_Internal(GPT_HWRESOURCE_0_3, GPT_HWRESR_0_3_BASE);
}

/** \brief GPT_Isr_Vector_307_Cat1()
 **
 ** Gpt interrupt service routine (Cat1):
 ** Entry point for TCPWM_0_7's interrupt vector 307.
 **
 */
ISR_NATIVE(GPT_Isr_Vector_307_Cat1)
{
/* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4.
   Justification: The hardware address is provided as integral type by configuration. However, the hardware access must be handled by using pointer. */
/* PRQA S 303 1 */
  Gpt_IsrVector_Internal(GPT_HWRESOURCE_0_7, GPT_HWRESR_0_7_BASE);
}

/** \brief GPT_Isr_Vector_307_Cat2()
 **
 ** Gpt interrupt service routine (Cat2):
 ** Entry point for TCPWM_0_7's interrupt vector 307.
 **
 */
ISR(GPT_Isr_Vector_307_Cat2)
{
/* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4.
   Justification: The hardware address is provided as integral type by configuration. However, the hardware access must be handled by using pointer. */
/* PRQA S 303 1 */
  Gpt_IsrVector_Internal(GPT_HWRESOURCE_0_7, GPT_HWRESR_0_7_BASE);
}

/** \brief GPT_Isr_Vector_310_Cat1()
 **
 ** Gpt interrupt service routine (Cat1):
 ** Entry point for TCPWM_0_10's interrupt vector 310.
 **
 */
ISR_NATIVE(GPT_Isr_Vector_310_Cat1)
{
/* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4.
   Justification: The hardware address is provided as integral type by configuration. However, the hardware access must be handled by using pointer. */
/* PRQA S 303 1 */
  Gpt_IsrVector_Internal(GPT_HWRESOURCE_0_10, GPT_HWRESR_0_10_BASE);
}

/** \brief GPT_Isr_Vector_310_Cat2()
 **
 ** Gpt interrupt service routine (Cat2):
 ** Entry point for TCPWM_0_10's interrupt vector 310.
 **
 */
ISR(GPT_Isr_Vector_310_Cat2)
{
/* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4.
   Justification: The hardware address is provided as integral type by configuration. However, the hardware access must be handled by using pointer. */
/* PRQA S 303 1 */
  Gpt_IsrVector_Internal(GPT_HWRESOURCE_0_10, GPT_HWRESR_0_10_BASE);
}

#define GPT_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Gpt_MemMap.h>
/*==================[internal function definitions]=========================*/
/*==================[end of file]===========================================*/
