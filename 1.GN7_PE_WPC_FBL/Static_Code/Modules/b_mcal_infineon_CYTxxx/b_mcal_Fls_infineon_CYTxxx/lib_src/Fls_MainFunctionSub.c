/** \brief AUTOSAR Fls Flash Driver
 **
 ** This file contains the implementation of Fls sub module function
 ** Fls_MainFunctionSub.
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
/* functions        */
/*==================*/

#define FLS_START_SEC_CODE
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Fls_MemMap.h>

/** \brief Fls_MainFunctionSub
**
** Periodic execution of HAL.
**
** \param[in] ConfigPtr        Configuration address
**
** \return     none
**
*/
FUNC(void, FLS_CODE) Fls_MainFunctionSub
(
 P2CONST(Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST) ConfigPtr
)
{
    FLS_UCHAR result;                   /* result of polling */
    FLS_ULONG polling_cnt;              /* counter for polling */
    FLS_ULONG polling_limit;            /* limit for polling */
    FLS_ULONG number_of_delay_loop;     /* number of delay loop for writing */
    FLS_ULONG written_size_limit;       /* limit of size for writing */
    FLS_ULONG prev_data_size;           /* previous remain size of writing */
    volatile FLS_ULONG counter;         /* counter of delay loop for writing */
    
    /* refresh external data */
    /* Deviation from MISRA-C:2004 rule 11.5, MISRA-C:2012 Rule-11.8.
       Justification: This implementation is intentional code because of
       refreshing variables. */
    /* PRQA S 311 2 */
    *((volatile FLS_ULONG *)&Fls_FMAPIIpcStruct) = Fls_FMAPIIpcStruct;
    *((volatile FLS_ULONG **)&Fls_FlashStatusAddr) = Fls_FlashStatusAddr;

    if( Fls_StateSub != Fls_StateSubMirror )
    {
        Fls_CancelSubSub();  /* cancel processing under operation */

        if( (Fls_JobresultSub == FLS_JOB_PENDING) || (Fls_JobresultSub == FLS_JOB_FAILED_UNWRITABLE) )
        {
            Fls_JobresultSub = FLS_JOB_FAILED;
        }
    }
    else
    {
        switch(Fls_StateSub)
        {
        case FLS_HAL_WRITE:
            
            if( Fls_JobresultSub == FLS_JOB_FAILED_NOTACQUIRE )
            {
                Fls_JobresultSub = FLS_JOB_PENDING;
                Fls_WriteFlashStart(); /* start writing flash memory */
                result = FLS_CONT;
            }
            else if( Fls_JobresultSub == FLS_JOB_OK )
            {
                /* write completion */
                result = FLS_OK;
            }
            else if( Fls_UseInterrupts == STD_OFF )
            {
                if( Fls_JobresultSub != FLS_JOB_FAILED_UNWRITABLE )
                {
                    polling_cnt = 0UL;
                    number_of_delay_loop = ConfigPtr->NumberOfDelayLoop;
                    if( number_of_delay_loop != 0xFFFFFFFFUL )
                    {
                        polling_limit = ( ( Fls_Mode == MEMIF_MODE_SLOW )? ConfigPtr->MaxWriteNormalMode: ConfigPtr->MaxWriteFastMode );
                        polling_limit >>= FLS_SHIFT_2BITS;
                        written_size_limit = 0UL;
                        prev_data_size = 0UL;
                    }
                    else
                    {
                        polling_limit = FLS_COUNT_MAX_SUB;
                        written_size_limit = ( ( Fls_Mode == MEMIF_MODE_SLOW )? ConfigPtr->MaxWriteNormalMode: ConfigPtr->MaxWriteFastMode );
                        prev_data_size = Fls_DataSize;
                    }
                    do
                    {
                        /* poll for write completion */
                        result = Fls_WriteFlashPolling();
                        if( result == FLS_CONT )
                        {
                            counter = ( number_of_delay_loop != 0xFFFFFFFFUL )? number_of_delay_loop: 0UL;
                            /* Deviation from MISRA-C:2004 rule 1.1, MISRA-C:2012 Dir-1.1.
                               Justification: If nesting is made shallow, readability may be reduced. */
                            /* PRQA S 715 10 */
                            while( counter > 0UL )
                            {
                                counter--;
                            }
                            if( number_of_delay_loop != 0xFFFFFFFFUL )
                            {
                                polling_cnt++;
                            }
                            else
                            {
                                if( ( prev_data_size - Fls_DataSize ) >= written_size_limit )
                                {
                                    polling_cnt = polling_limit;
                                }
                            }
                        }
                    }
                    while( ( result == FLS_CONT ) && ( polling_cnt < polling_limit ) );
                }
                else
                {
                    result = FLS_NG;
                }
            }
            else
            {
                switch(Fls_JobresultSub)
                {
                case FLS_JOB_FAILED:
                case FLS_JOB_FAILED_UNWRITABLE:
                    result = FLS_NG;
                    break;
                default:
                    result = FLS_CONT;
                    break;
                }
            }

            if( result != FLS_CONT )
            {
                /* end writing flash memory */
                Fls_WriteFlashFinal();
                
                FLS_STATESUB_SET(FLS_HAL_NOP)             /* set state */
                
                
                if( result == FLS_OK )
                {
                    Fls_JobresultSub = FLS_JOB_OK;
                }
                else
                {
                    if( Fls_JobresultSub != FLS_JOB_FAILED_UNWRITABLE )
                    {
                        Fls_JobresultSub = FLS_JOB_FAILED;
                    }
                }
            }
            break;
        case FLS_HAL_ERASE:
            
            if( Fls_JobresultSub == FLS_JOB_FAILED_NOTACQUIRE )
            {
                Fls_JobresultSub = FLS_JOB_PENDING;
                Fls_EraseFlashStart(); /* start erasing flash memory */
                result = FLS_CONT;
            }
            else if( Fls_UseInterrupts == STD_OFF )
            {
                if( Fls_JobresultSub != FLS_JOB_FAILED_UNWRITABLE )
                {
                    /* poll for erase completion */
                    result = Fls_EraseFlashPolling();
                }
                else
                {
                    result = FLS_NG;
                }
            }
            else
            {
                switch(Fls_JobresultSub)
                {
                case FLS_JOB_OK:
                    /* erase completion */
                    result = FLS_OK;
                    break;
                case FLS_JOB_FAILED:
                case FLS_JOB_FAILED_UNWRITABLE:
                    result = FLS_NG;
                    break;
                default:
                    result = FLS_CONT;
                    break;
                }
            }

            if( result != FLS_CONT )
            {
                /* end erasing flash memory */
                Fls_EraseFlashFinal();
                
                FLS_STATESUB_SET(FLS_HAL_NOP)             /* set state */
                
                
                if( result == FLS_OK )
                {
                    Fls_JobresultSub = FLS_JOB_OK;
                }
                else
                {
                    if( Fls_JobresultSub != FLS_JOB_FAILED_UNWRITABLE )
                    {
                        Fls_JobresultSub = FLS_JOB_FAILED;
                    }
                }
            }
            
            break;
        case FLS_HAL_BLANKCHECK:
            
            if( Fls_JobresultSub == FLS_JOB_FAILED_NOTACQUIRE )
            {
                Fls_JobresultSub = FLS_JOB_PENDING;
                Fls_BlankCheckFlashStart(); /* start checking blank flash memory */
                result = FLS_CONT;
            }
            else if( Fls_JobresultSub == FLS_JOB_OK )
            {
                /* blank check completion */
                result = FLS_OK;
            }
            else if( Fls_JobresultSub == FLS_JOB_FAILED_UNWRITABLE )
            {
                /* blank check failed */
                result = FLS_NG;
            }
            else
            {
                /* poll for blank check completion */
                result = Fls_BlankCheckFlashPolling();
            }

            if( result != FLS_CONT )
            {
                /* end checking blank flash memory */
                Fls_BlankCheckFlashFinal();
                
                FLS_STATESUB_SET(FLS_HAL_NOP)             /* set state */
                
                
                if( result == FLS_OK )
                {
                    Fls_JobresultSub = FLS_JOB_OK;
                }
                else
                {
                    Fls_JobresultSub = FLS_JOB_FAILED;
                }
            }
            break;
        case FLS_HAL_WRITE_WAIT:
            
            result = Fls_PollingFlash();
            
            if( ( result == FLS_HAL_NOP ) || ( result == FLS_HAL_MAX ) )
            {
                /* start writing flash memory */
                Fls_WriteFlashStart();
                
                FLS_STATESUB_SET(FLS_HAL_WRITE)           /* set state */
                
            }
            
            break;
        case FLS_HAL_ERASE_WAIT:
            
            result = Fls_PollingFlash();
            
            if( ( result == FLS_HAL_NOP ) || ( result == FLS_HAL_MAX ) )
            {
                /* start erasing flash memory */
                Fls_EraseFlashStart();
                
                FLS_STATESUB_SET(FLS_HAL_ERASE)           /* set state */
                
            }
            
            break;
        case FLS_HAL_BLANKCHECK_WAIT:
            
            result = Fls_PollingFlash();
            
            if( ( result == FLS_HAL_NOP ) || ( result == FLS_HAL_MAX ) )
            {
                /* start checking blank flash memory */
                Fls_BlankCheckFlashStart();
                
                FLS_STATESUB_SET(FLS_HAL_BLANKCHECK)           /* set state */
                
            }
            break;
        default: /* FLS_HAL_NOP */
            
            /* call Fls_CancelSub even in the state of no-operation. */
            /* if FMC is active, poll for completion */
            Fls_CancelSub();
            
            break;
        }
    }
    
    return;
}
#define FLS_STOP_SEC_CODE
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: This implementation is specified by AUTOSAR specification. */
/* PRQA S 5087 1 */
#include <Fls_MemMap.h>

/*==================[end of file]===========================================*/
