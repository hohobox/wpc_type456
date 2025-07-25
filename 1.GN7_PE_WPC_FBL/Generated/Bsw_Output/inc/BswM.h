/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  FILE-NAME : BswM.h                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.8.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_BswM.arxml
 *                Configuration\ECU\Ecud_Com.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_EcuM.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef BSWM_H
#define BSWM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "BswM_Cfg.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Instance ID */
#define BSWM_INSTANCE_ID ((uint8)0x00u)

/* Service ID for BswM_Init */
#define BSWM_INIT_SID ((uint8)0x00u)

/* Service ID for BswM_GetVersionInfo */
#define BSWM_GETVERSIONINFO_SID ((uint8)0x01u)

/* Service ID for BswMGenericRequest */
#define BSWM_GENERIC_CURRENTSTATE_SID ((uint8)0x02u)

/* Service ID for BswM_MainFunction */
#define BSWM_MAINFUNCTION_SID ((uint8)0x03u)

/* Service ID for BswM_Deinit */
#define BSWM_DEINIT ((uint8)0x04u)

/* Service ID for BswM_ComM_CurrentMode */
#define BSWM_COMM_CURRENTMODE_SID ((uint8)0x0Eu)

/* Service ID for BswM_ComM_CurrentPNCMode */
#define BSWM_COMM_PNC_CURRENTMODE_SID ((uint8)0x15u)

/* Service ID for BswM_Dcm_CommunicationMode_CurrentState */
#define BSWM_DCM_REQUESTCOMMUNICATIONMODE_SID ((uint8)0x06u)

/* Service ID for BswM_CanSM_CurrentState */
#define BSWM_CANSM_CURRENTSTATE_SID ((uint8)0x05u)

/* Service ID for BswM_EthSM_CurrentState */
#define BSWM_ETHSM_CURRENTSTATE_SID ((uint8)0x0Du)

/* Service ID for BswM_FrSM_CurrentState */
#define BSWM_FRSM_CURRENTSTATE_SID ((uint8)0x0Cu)

/* Service ID for BswM_LinSM_CurrentState */
#define BSWM_LINSM_CURRENTSTATE_SID ((uint8)0x09u)

/* Service ID for BswM_EcuM_CurrentState */
#define BSWM_ECUM_CURRENTSTATE_SID ((uint8)0x0Fu)

/* Service ID for BswM_EcuM_CurrentWakeup */
#define BSWM_ECUM_CURRENTWAKEUP_SID ((uint8)0x10u)

/* Service ID for BswM_NvM_CurrentBlockMode */
#define BSWM_NVM_CURRENT_BLOCK_SID ((uint8)0x16u)

/* Service ID for BswM_NvM_CurrentJobMode */
#define BSWM_NVM_CURRENT_JOB_SID ((uint8)0x17u)

/* Service ID for BswM_LinSM_CurrentSchedule */
#define BSWM_LINSM_CURRENTSCHEDULE_SID ((uint8)0x0Au)

/* Service ID for BswM_LinTp_RequestMode */
#define BSWM_LINTP_REQUESTMODE_SID ((uint8)0x0Bu)

/* Service ID for BswM_WdgM_RequestPartitionReset */
#define BSWM_WDGM_REQUESTPARTITIONRESET_SID ((uint8)0x11u)

/* Service ID for BswM_Dcm_ApplicationUpdated */
#define BSWM_DCM_APPLICATIONUPDATED_SID ((uint8)0x14u)

/* Service ID for BswM_J1939DcmBroadcastStatus */
#define BSWM_J1939DCMBROADCASTSTATUS_SID ((uint8)0x1Bu)

/* Service ID for BswM_J1939Nm_StateChangeNotification */
#define BSWM_J1939NM_STATECHANGENOTIFICATION_SID ((uint8)0x18u)

/* Service ID for BswM_Sd_ClientServiceCurrentState */
#define BSWM_SD_CLIENTSERVICECURRENTSTATE_SID ((uint8)0x1Fu)

/* Service ID for BswM_Sd_EventHandlerCurrentState */
#define BSWM_SD_EVENTHANDLERCURRENTSTATE_SID ((uint8)0x20u)

/* Service ID for BswM_Sd_ConsumedEventGroupCurrentState */
#define BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_SID ((uint8)0x21u)

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* BswM Initialization Status */
#define BSWM_UNINITIALIZED                0x00u
#define BSWM_INITIALIZED                  0x01u

/* BswM Development error values */
#define BSWM_E_NO_INIT                    0x01u
#define BSWM_E_NULL_POINTER               0x02u
#define BSWM_E_INVALID_PAR                0x03u
#define BSWM_E_REQ_USER_OUT_OF_RANGE      0x04u
#define BSWM_E_REQ_MODE_OUT_OF_RANGE      0x05u
#define BSWM_E_PARAM_CONFIG               0x06u

/* polyspace-begin MISRA-C3:D4.9 [Justified:Low] "use function like-macro for reduce execution time and stack" */
#define BSWM_UNUSED(x)                    do { \
                                            if((uint32)(x) != (uint32)BSWM_ZERO) {} \
                                          } while(BSWM_ZERO)

#define BSWM_UNUSED_PTR(x)                do { \
                                            if((x) != NULL_PTR) {} \
                                          } while(BSWM_ZERO)
/* polyspace-end MISRA-C3:D4.9 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"

/* Extern for BswM_Init API */
extern FUNC(void, BSWM_CODE) BswM_Init
 (P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr);

/* Extern for BswM_Deinit API */
extern FUNC(void, BSWM_CODE) BswM_Deinit(void);

/* Extern for BswM_InitializeRulePreviousResult API */
extern FUNC(void, BSWM_CODE) BswM_InitializeRulePreviousResult
 (BswM_RuleIdType RuleId);

/* Extern for Generic Request API */
extern FUNC(void, BSWM_CODE) BswM_RequestMode
 (BswM_UserType requesting_user, BswM_ModeType requested_mode);



#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BSWM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
