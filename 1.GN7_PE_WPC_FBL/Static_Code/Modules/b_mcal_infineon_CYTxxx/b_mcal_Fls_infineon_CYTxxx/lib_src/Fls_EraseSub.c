/** \brief AUTOSAR Fls Flash Driver
 **
 ** This file contains the implementation of Fls sub module function
 ** Fls_EraseSub.
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

/*========*/
/* Header */
/*========*/
#include <Fls_LibInterface.h>   /* Library interface header file */
#include <Fls_InternalLib.h>    /* Module internal API */     


/*==================*/
/* function         */
/*==================*/

#define FLS_START_SEC_CODE
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Fls_MemMap.h>

/** \brief Fls_EraseSub
**
** Request for erasing sector in flash memory.
**
** \param[in]  addr       start address to erase
** \param[in]  length     length in byte
**
** \return     result of request
** \retval     FLS_REQUEST_ACCEPT     accept request
** \retval     FLS_REQUEST_DECLINE    decline request
** \retval     FLS_PARAMETER_ERROR    parameter error 
** \retval     FLS_ACCESS_SIZE_ERROR  access size error
**
*/
FUNC(FLS_UCHAR, FLS_CODE) Fls_EraseSub
(
 P2VAR(FLS_UCHAR, AUTOMATIC, FLS_APPL_DATA) addr,
 FLS_ULONG length
)
{
    FLS_UCHAR retval;                   /* return value */
    
    /* Deviation from MISRA-C:2004 rule 11.4, MISRA-C:2012 Rule-11.3.
       Justification: This cast is needed for handling with 32-bit type address. */
    /* PRQA S 310,3305 1 */
    Fls_NowAddr     = (FLS_ULONG *)addr;
    Fls_ParamLength = length;
    
    Fls_JobresultSub = FLS_JOB_PENDING;
    
    if( Fls_GetStatusSub() == FLS_STATUS_IDLE )
    {
        FLS_STATESUB_SET(FLS_HAL_ERASE)               /* set state */
        
        Fls_EraseFlashStart();
    }
    else
    {
        FLS_STATESUB_SET(FLS_HAL_ERASE_WAIT)          /* set state */
    }
    
    retval = FLS_REQUEST_ACCEPT;   /* accept request */
    
    return retval;
}
#define FLS_STOP_SEC_CODE
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Fls_MemMap.h>

/*==================[end of file]===========================================*/
