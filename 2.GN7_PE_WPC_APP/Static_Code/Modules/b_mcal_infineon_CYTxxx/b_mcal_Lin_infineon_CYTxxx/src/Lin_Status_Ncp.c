/** \brief Lin_Status_Ncp.c
 **
 ** Configuration dependent status interface.
 ** Configurable status interface.
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
#include "Lin_LIf_Status_Li.h"
#include "Lin_LIf_State_Ncp.h"
#include "Lin_LIf_State_Li.h"
#include "Lin_LIf_Common_Ncp.h"
#include "Lin_LIf_Common_Cp.h"
#include "Lin_LIf_Common_Li.h"
#include "Lin_LIf_Operational_Li.h"
#include "Lin_Defines.h"
#include "Lin_Ncp_Common.h"

#include "Lin_Enable_Api.h"
#include "Lin_Ncp_Status_Ncp.h"

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define LIN_START_SEC_CODE_ASIL_B
#include "Lin_MemMap.h"

#if (LIN_VERSION_INFO_API == STD_ON)

/** \brief Lin_GetVersionInfo
 **
 ** Returns the version information of this module.
 **
 ** \param [out] versioninfo   pointer to version info instance
 **
 */
FUNC(void, AUTOMATIC) Lin_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) versioninfo
){
    if (versioninfo == NULL_PTR){
      Lin_ErrorWrapper( LIN_GETVERSIONINFO_API_ID, LIN_E_PARAM_POINTER );
    } else {
      Lin_GetVersionInfo_Internal(versioninfo);
      
      versioninfo -> sw_major_version = LIN_SW_MAJOR_VERSION;
      versioninfo -> sw_minor_version = LIN_SW_MINOR_VERSION;
      versioninfo -> sw_patch_version = LIN_SW_PATCH_VERSION_CFG;
    
    }
}

#endif /*#if (LIN_VERSION_INFO_API == STD_ON)*/

/** \brief Lin_CheckWakeup
 **
 ** This function checks if a wakeup has occurred on the addressed LIN channel. 
 **
 ** \return Acceptance status of wakeup check: E_OK or E_NOT_OK
 ** \param [in] Channel   channel id
 **
 */
FUNC(Std_ReturnType, AUTOMATIC) Lin_CheckWakeup
(
  VAR(uint8, AUTOMATIC) Channel
){
    uint8 ChannelIndex = Lin_GetChannelIndex ( Channel );
    boolean DetsPassed = TRUE;
    P2VAR(Lin_VarChType, AUTOMATIC, AUTOMATIC) Lin_VarChPtr;
    Std_ReturnType Std_Return = E_NOT_OK;

    if ( Lin_Var_ModuleStatusGet( ) != LIN_STATUS_MOD_INIT ){
      Lin_ErrorWrapper( LIN_CHECKWAKEUP_API_ID, LIN_E_UNINIT );
      DetsPassed = FALSE;
    }

    if ( ChannelIndex >= LIN_NUMBER_OF_CONFIGURED_CHANNELS ){
      Lin_ErrorWrapper( LIN_CHECKWAKEUP_API_ID, LIN_E_INVALID_CHANNEL );
      DetsPassed = FALSE;
    }

    if ( DetsPassed == TRUE ){
      Lin_VarChPtr = Lin_VarChGet( ChannelIndex );
      if ( Lin_VarChPtr -> Lin_ch_stimulation == LIN_INTERNAL_WAKEUP_BY_LINBUSSLAVE ){
        /* set wakeup event with wakeup source for specific channel */
        Lin_EcuMSetWakeupEventWrapper ( ChannelIndex );
        Lin_LinIfWakeupConfirmationWrapper ( ChannelIndex );
      }
      Std_Return = E_OK;
    }
    return Std_Return;
}

/** \brief Lin_GetStatus
 **
 ** Gets the status of the LIN driver.
 **
 ** \return Transmission status
 ** \param [in] Channel   channel id
 ** \param [inout] Lin_SduPtr   pointer to sdu
 **
 */
FUNC(Lin_StatusType, AUTOMATIC) Lin_GetStatus
(
  VAR(uint8, AUTOMATIC) Channel,
  P2VAR(P2VAR(uint8, AUTOMATIC, AUTOMATIC), AUTOMATIC, AUTOMATIC) Lin_SduPtr
){
    uint8 ChannelIndex = Lin_GetChannelIndex ( Channel );
    boolean DetsPassed = TRUE;
    P2VAR(Lin_VarChType, AUTOMATIC, AUTOMATIC) Lin_VarChPtr;
    Lin_StatusType Lin_Status = LIN_NOT_OK;
    Lin_VarCh_StatusType Lin_VarCh_Status;
    
    if ( Lin_Var_ModuleStatusGet( ) != LIN_STATUS_MOD_INIT ){
      Lin_ErrorWrapper( LIN_GETSTATUS_API_ID, LIN_E_UNINIT );
      DetsPassed = FALSE;
    }

    if ( ChannelIndex >= LIN_NUMBER_OF_CONFIGURED_CHANNELS ){
      Lin_ErrorWrapper( LIN_GETSTATUS_API_ID, LIN_E_INVALID_CHANNEL );
      DetsPassed = FALSE;
    }

    if ( Lin_SduPtr == NULL_PTR ){
      Lin_ErrorWrapper( LIN_GETSTATUS_API_ID, LIN_E_PARAM_POINTER );
      DetsPassed = FALSE;
    }

    if ( DetsPassed == TRUE ){
      Lin_VarCh_Status = Lin_GetStatus_Internal( ChannelIndex );
      Lin_VarChPtr = Lin_VarChGet( ChannelIndex );

      switch ( Lin_VarCh_Status ){
        case LIN_INTERNAL_TX_OK:
          Lin_Status = LIN_TX_OK;
          break;
        case LIN_INTERNAL_TX_BUSY:
          Lin_Status = LIN_TX_BUSY;
          break;
        case LIN_INTERNAL_TX_HEADER_ERROR:
          Lin_Status = LIN_TX_HEADER_ERROR;
          break;
        case LIN_INTERNAL_TX_ERROR:
          Lin_Status = LIN_TX_ERROR;
          break;
        /* If a frame has been received, copy data to upper layer. */
        case LIN_INTERNAL_RX_OK:
          *Lin_SduPtr = &(( Lin_VarChPtr -> Lin_ch_data )[LIN_DATA_START_INDEX]);
          Lin_Status = LIN_RX_OK;
          break;
        case LIN_INTERNAL_RX_BUSY:
          Lin_Status = LIN_RX_BUSY;
          break;
        case LIN_INTERNAL_RX_ERROR:
          Lin_Status = LIN_RX_ERROR;
          break;
        case LIN_INTERNAL_RX_NO_RESPONSE:
          Lin_Status = LIN_RX_NO_RESPONSE;
          break;
        case LIN_INTERNAL_OPERATIONAL:
          Lin_Status = LIN_OPERATIONAL;
          break;
        case LIN_INTERNAL_CH_SLEEP:
          Lin_Status = LIN_CH_SLEEP;
          break;
        case LIN_INTERNAL_CH_SLEEP_PENDING:
          Lin_Status = LIN_CH_SLEEP;
          /* set sleep status */
          Lin_GoToSleepInternal_Internal( ChannelIndex );
          /* enable wakeup-by-LinBusSlave interrupt. */
          Lin_EnableRxInterrupt_Internal( ChannelIndex );
          break;
        default:
          Lin_Status = LIN_NOT_OK;
          break;
      }
    }
    return Lin_Status;
}

/** \brief Lin_Init
 **
 ** Initializes the LIN module.
 **
 ** \param [in] Config   Lin configuration.
 **
 */
FUNC(void, AUTOMATIC) Lin_Init
(
  P2CONST(Lin_ConfigType, AUTOMATIC, AUTOMATIC) Config
){
    boolean DetsPassed = TRUE;

    if (Config != NULL_PTR){
      Lin_ErrorWrapper( LIN_INIT_API_ID, LIN_E_INVALID_POINTER );
      DetsPassed = FALSE;
    }

    if ( Lin_Var_ModuleStatusGet( ) == LIN_STATUS_MOD_INIT ){
      Lin_ErrorWrapper( LIN_INIT_API_ID, LIN_E_STATE_TRANSITION );
      DetsPassed = FALSE;
    }

    if ( DetsPassed == TRUE ){
      Lin_Init_Internal();
      /* set the module status to LIN_STATUS_MOD_INIT: */
      Lin_Var_ModuleStatusSet( LIN_STATUS_MOD_INIT ); 
    }
}

#if (LIN_DEINIT_API == STD_ON)
/** \brief Lin_DeInit
 **
 **  Deinitializes the LIN module.
 **
 ** \param [in] none.
 **
 */
FUNC(void, AUTOMATIC) Lin_DeInit 
(
 void
){
    boolean DetsPassed = TRUE;

    if ( Lin_Var_ModuleStatusGet( )!= LIN_STATUS_MOD_INIT ){
      Lin_ErrorWrapper( LIN_DEINIT_API_ID, LIN_E_STATE_TRANSITION );
      DetsPassed = FALSE;
    }

    if ( DetsPassed == TRUE ){
      /* set the module status to LIN_STATUS_MOD_UNINIT: */
      Lin_Var_ModuleStatusSet( LIN_STATUS_MOD_UNINIT ); 

      Lin_DeInit_Internal();
    }
}
#endif /*#if (LIN_DEINIT_API == STD_ON)*/

#define LIN_STOP_SEC_CODE_ASIL_B
/* Deviation from MISRA-C:2004 rule 19.1, MISRA-C:2012 Rule-20.1
   Justification: MemMap.h must be included in-line. */
/* PRQA S 5087 1 */
#include "Lin_MemMap.h"

/*==================[end of file]===========================================*/
