
/** \brief AUTOSAR SPI Driver
 **
 ** This file contains implementation of the ISR functions.
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

/* This include was moved before IF-statement, because of empty file in case 
  of SpiLevelDelivered equals 0! */
#include <Spi_Internal.h>         /* Module private API */


#include <Spi.h>
#include <Spi_ExternalInclude.h>
#include <Spi_Common.h>
#include <Spi_Hw.h>
#include <Spi_Cfg.h>
#include <Spi_Cfg_Der.h>

/*==================[macros]================================================*/
/* INVLID SCB */
#define SPI_SCB_INVALID   ((Spi_HWUnitType)255U)

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/
#define SPI_START_SEC_CODE_ASIL_B

#include <Spi_MemMap.h>

/** \brief Spi_Interrupt_SCB0_Internal
 **
 ** Internal Spi interrupt service routine for SCB0 .
 **
 */
static FUNC(void, SPI_CODE) Spi_Interrupt_SCB0_Internal(void);





#define SPI_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Spi_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include <Spi_MemMap.h>

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/


#define SPI_START_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Spi_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include <Spi_MemMap.h>

/** \brief Spi_Interrupt_SCB0_Cat1
 **
 ** Spi interrupt service routine (Cat 1):
 ** Entry point for interrupt vector 17.
 **
 */
ISR_NATIVE(Spi_Interrupt_SCB0_Cat1)
{

  Spi_Interrupt_SCB0_Internal();

} /* Spi_Interrupt_SCB0_Cat1 */

/** \brief Spi_Interrupt_SCB0_Cat2
 **
 ** Spi interrupt service routine (Cat 2):
 ** Entry point for interrupt vector 17.
 **
 */
ISR(Spi_Interrupt_SCB0_Cat2)
{
  Spi_Interrupt_SCB0_Internal();
} /* Spi_Interrupt_SCB0_Cat2 */




#define SPI_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Spi_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include <Spi_MemMap.h>

/*==================[internal function definitions]=========================*/

#define SPI_START_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Spi_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include <Spi_MemMap.h>


/** \brief Spi_Interrupt_SCB0_Internal
 **
 ** Internal Spi interrupt service routine for SCB0 .
 **
 */
static FUNC(void, SPI_CODE) Spi_Interrupt_SCB0_Internal(void)
{
  VAR(Spi_HwFactorType, AUTOMATIC) Factor;
  VAR(Spi_HWUnitType, AUTOMATIC)   HwUnitId = SPI_SCB0;
  volatile P2VAR(Spi_SCBRegsType, AUTOMATIC, REGSPACE) CurScbPtr;

  if ( FALSE == Spi_Cfg_CheckConfig(Spi_Current_ConfigPtr) )
  {
    HwUnitId = SPI_SCB_INVALID;
  }
  else
  {
    switch (Spi_Current_ConfigPtr->ConfigId)
    {
      case SPI_CONFIG : /* SpiDriver */
        break;
      default :
        /* Not entered here */
        HwUnitId = SPI_SCB_INVALID;
        break;
    }
  }

  if ( SPI_SCB_INVALID != HwUnitId )
  { /* Exist SCB */
    Factor = Spi_Hw_JudgeSCBFactor(HwUnitId);
    if (SPI_NOT_OK == Spi_Internal_InterruptHandler(Factor, HwUnitId))
    {
      /* clear interrupts flag */
      /* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4
          Justification: The hardware address is provided as integral type by configuration. 
                         However, the hardware access must be handled by using pointer. */
      /* PRQA S 303 1 */
      CurScbPtr = (volatile P2VAR(Spi_SCBRegsType, SPI_CONST, SPI_APPL_DATA))SPI_SCB0_BASE_ADDRESS;
      Spi_Hw_ClearAllIrqFactor(CurScbPtr);
    }
  }
  else
  { /* Invalid config pointer */
    /* clear interrupts flag */
    /* Deviation from MISRA-C:2004 rule 3.1, 11.3, MISRA-C:2012 Rule-11.4
     Justification: The hardware address is provided as integral type by configuration. 
                    However, the hardware access must be handled by using pointer. */
    /* PRQA S 303 1 */
    CurScbPtr = (volatile P2VAR(Spi_SCBRegsType, SPI_CONST, SPI_APPL_DATA))SPI_SCB0_BASE_ADDRESS;
    Spi_Hw_ClearAllIrqFactor(CurScbPtr);
    /* Report error */
    Spi_Com_DetReportError( SPI_API_ISR, SPI_E_PARAM_CONFIG );
  }
} /* Spi_Interrupt_SCB0_Internal */


#define SPI_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Spi_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include <Spi_MemMap.h>



/*==================[end of file]===========================================*/
