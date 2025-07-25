/** \brief AUTOSAR Fls Flash Driver
 **
 ** This file contains the implementation of the AUTOSAR module Fls
 ** function Fls_SetMode.
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

#include <Fls_LibInterface.h>   /* Library interface header file */
#include <Fls_InternalLib.h>    /* Module internal API */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define FLS_START_SEC_CODE
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Fls_MemMap.h>

/** \brief Fls_SetModeLib
 **
 ** Sets the mode for the flash access to SLOW or FAST as given by the parameter.
 **
 ** \param[in]  Mode    mode to be switched to (SLOW, FAST)
 **
 ** \return     none
 */
FUNC(void, FLS_CODE) Fls_SetModeLib
(
    MemIf_ModeType Mode
)
{
    /* Fls004: check that driver is initialized -> FLS_E_UNINIT */
    if( Fls_DriverState == MEMIF_UNINIT )
    {
        /* report DET error */
        (void)Fls_ReportError( FLS_MODULE_ID,
                               FLS_INSTANCE_ID,
                               FLS_ID_SETMODE,
                               FLS_E_UNINIT );
    }
    else
    {
        /* enter exclusive area */
        Fls_EnterCritiSec();

        /* Fls156: check that driver is not BUSY -> FLS_E_BUSY */
        if( Fls_DriverState == MEMIF_BUSY )
        {
            /* exit exclusive area */
            Fls_ExitCritiSec();

            /* report DET error */
            (void)Fls_ReportError( FLS_MODULE_ID,
                                   FLS_INSTANCE_ID,
                                   FLS_ID_SETMODE,
                                   FLS_E_BUSY );
        }
        else
        {
            /* Fls155: set the flash driver mode to the given mode */
            Fls_Mode = Mode;

            /* exit exclusive area */
            Fls_ExitCritiSec();
        }
    }

    return;

}

/** \brief Fls_SetCycleModeLib
 **
 ** Sets the mode for the timeout checking to SLOW or FAST as given by the
 ** parameter.
 **
 ** \param[in]  Mode    mode to be switched to (SLOW, FAST)
 **
 ** \return     setting mode has been accepted/not been accepted
 ** \retval     E_NOT_OK         setting mode has not been accepted
 **             E_OK             setting mode has been accepted
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_SetCycleModeLib
(
    MemIf_ModeType Mode
)
{
    Std_ReturnType  Ret;            /* return value */

    /* Fls004: check that driver is initialized -> FLS_E_UNINIT */
    if( Fls_DriverState == MEMIF_UNINIT )
    {
        /* report DET error */
        (void)Fls_ReportError( FLS_MODULE_ID,
                               FLS_INSTANCE_ID,
                               FLS_ID_SETCYCLEMODE,
                               FLS_E_UNINIT );

        /* set E_NOT_OK for return value  */
        Ret = E_NOT_OK;
    }
    else
    {
        /* enter exclusive area */
        Fls_EnterCritiSec();

        /* Fls156: check that driver is not BUSY -> FLS_E_BUSY */
        if( Fls_DriverState == MEMIF_BUSY )
        {
            /* exit exclusive area */
            Fls_ExitCritiSec();

            /* report DET error */
            (void)Fls_ReportError( FLS_MODULE_ID,
                                   FLS_INSTANCE_ID,
                                   FLS_ID_SETCYCLEMODE,
                                   FLS_E_BUSY );

            /* set E_NOT_OK for return value  */
            Ret = E_NOT_OK;
        }
        else
        {
            Fls_CycleMode = Mode;

            /* exit exclusive area */
            Fls_ExitCritiSec();

            /* set E_OK for return value  */
            Ret = E_OK;
        }
    }

    return Ret;

}

#define FLS_STOP_SEC_CODE
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Fls_MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
