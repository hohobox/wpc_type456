/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM.h                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Module Functions Declaration               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.1.0     19-May-2022   HM Shin     Internal Redmine #34769                **
** 2.0.5     07-Dec-2020   Jongsun Lim #27006                                 **
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #6788                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/
#ifndef IPDUM_H
#define IPDUM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"   /* Com Stack Types header file */
#include "IpduM_Cfg.h"        /* IpduM Configuration header file */
#include "SchM_IpduM.h"
#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
#include "Com.h"
#include "Com_Cbk.h"
#endif
#endif
#include "PduR.h"
#include "IpduM_Dbg.h"



/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define IPDUM_H_AR_RELEASE_MAJOR_VERSION             4
#define IPDUM_H_AR_RELEASE_MINOR_VERSION             0
#define IPDUM_H_AR_RELEASE_REVISION_VERSION          3

/* Software Version Information */
#define IPDUM_H_SW_MAJOR_VERSION                     2
#define IPDUM_H_SW_MINOR_VERSION                     1
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Service ID for IpduM_Init */
#define IPDUM_INIT_SID              0x00
/* Service ID for IpduM_GetVersionInfo */
#define IPDUM_GETVERSIONINFO_SID    0x01
/* Service ID for IpduM_Transmit */
#define IPDUM_TRANSMIT_SID          0x03
/* Service ID for IpduM_RxIndication */
#define IPDUM_RXINDICATION_SID      0x42
/* Service ID for IpduM_TxConfirmation */
#define IPDUM_TXCONFIRMATION_SID    0x40
/* Service ID for IpduM_TriggerTransmit */
#define IPDUM_TRIGGERTRANSMIT_SID   0x41
/* Service ID for Ipdum_MainFunction */
#define IPDUM_MAINFUNCTION_SID      0x10

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* API service called with wrong parameter */
#define IPDUM_E_PARAM               0x10
/* API service called with wrong Pointer */
#define IPDUM_E_PARAM_POINTER       0x11
/* API service used without module initialization */
#define IPDUM_E_UNINIT              0x20
/*******************************************************************************
**                      MACROs                                                **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define IPDUM_UNUSED(x)                            do { \
                                                      if((uint32)(x) != \
                                                      (uint32)IPDUM_ZERO) {} \
                                                    } while(0)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define IPDUM_UNUSED_PTR(x)                        do { \
                                                      if((x) != NULL_PTR) {} \
                                                    } while(0)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* Structure for initializing I-PDU group */
typedef struct
{
  uint8 ucDummy;
}IpduM_ConfigType;

#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_Init
  (P2CONST(IpduM_ConfigType, AUTOMATIC, IPDUM_CONST) config);
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_VERSION_INFO_API == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, IPDUM_VAR) versioninfo);
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_VERSION_INFO_API == STD_ON)*/

#if (IPDUM_TX_IPDU == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, IPDUM_CODE) IpduM_Transmit( PduIdType PdumTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr);
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_TX_IPDU == STD_ON)*/
#endif

#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_MainFunction(void);
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* IPDUM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
