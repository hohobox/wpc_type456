/** \brief Can_ModuleManager.c
 **
 ** Internal unit for functions related to the whole driver.
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

#include <Can_ModuleManager.h>
#include <Can_RegisterAbstraction.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

#define CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED

#include "Can_MemMap.h"

/** Status of the CAN module. */
static VAR(boolean, AUTOMATIC) Can_ModuleReady = FALSE;

#define CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Can_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include "Can_MemMap.h"

/*==================[external function definitions]=========================*/

#define CAN_START_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Can_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include "Can_MemMap.h"


/** \brief Can_ModuleGetReady
 **
 ** Returns the module status.
 **
 ** \return   true: The module is ready an initialized (state CAN_READY).
 **           false: The module is not yet initialized (state CAN_UNINIT).
 **
 */
FUNC(boolean, AUTOMATIC) Can_ModuleGetReady(void)
{
  return Can_ModuleReady;
}

/** \brief Can_ModuleGetVersionInfo
 **
 ** This function returns the version information of the library.
 **
 ** \param [out] VersionInfoPtr   Pointer to where to store the version information of
 **                               this module.
 **
 */
FUNC(void, AUTOMATIC) Can_ModuleGetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) VersionInfoPtr
)
{
  VersionInfoPtr->vendorID = CAN_VENDOR_ID; /* uint16 */
  VersionInfoPtr->moduleID = CAN_MODULE_ID; /* uint16 */
}

/** \brief Can_ModuleInit
 **
 ** Initializes the module.
 **
 */
FUNC(void, AUTOMATIC) Can_ModuleInit(void)
{
  /* Set module status. */
  Can_ModuleReady = TRUE;
}

/** \brief Can_ModuleDeInit
 **
 ** Deinitializes the module.
 **
 */
FUNC(void, AUTOMATIC) Can_ModuleDeInit(void)
{
  /* Deinit module status. */
  Can_ModuleReady = FALSE;
}

#define CAN_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 Rule 19.1, MISRA-C:2012 Rule-20.1.
   Justification: Can_MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include "Can_MemMap.h"


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
