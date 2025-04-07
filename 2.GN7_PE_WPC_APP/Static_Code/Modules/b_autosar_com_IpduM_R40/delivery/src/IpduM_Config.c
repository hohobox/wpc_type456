/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Config.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Global definitions                         **
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
** 2.0.4     21-Dec-2016   Chan Kim    Internal Redmine #7006                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM_PCTypes.h"
#include "IpduM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define IPDUM_CFG_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_CFG_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_CFG_C_AR_RELEASE_REVISION_VERSION 3

/* IPDUM software version information */
#define IPDUM_CFG_C_SW_MAJOR_VERSION            2
#define IPDUM_CFG_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != \
     IPDUM_CFG_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM_Ram.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != \
     IPDUM_CFG_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM_Ram.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_CFG_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM_Ram.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_CFG_C_SW_MAJOR_VERSION)
#error "IpduM_Ram.c : Mismatch in Software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_CFG_C_SW_MINOR_VERSION)
#error "IpduM_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      Variable for Library                                  **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)

#define IPDUM_START_SEC_CONST_16
#include "Memmap.h"
	CONST(uint16, IPDUM_CONST) IpduM_No_Of_Tx_Pathways = IPDUM_NO_OF_TX_PATHWAYS;
#define IPDUM_STOP_SEC_CONST_16
#include "Memmap.h"

#define IPDUM_START_SEC_CONST_16
#include "Memmap.h"
	CONST(uint16, IPDUM_CONST) IpduM_Tx_Pending_Flag_Bytes = IPDUM_TX_PENDING_FLAG_BYTES;
#define IPDUM_STOP_SEC_CONST_16
#include "Memmap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "Memmap.h"
#if(IPDUM_TX_IPDU == STD_ON)
	CONST(PduIdType, IPDUM_CONST) IpduM_Max_Tx_Pdu_ID = IPDUM_MAX_TX_PDU_ID;
#else
	CONST(PduIdType, IPDUM_CONST) IpduM_Max_Tx_Pdu_ID = IPDUM_ZERO;
#endif
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "Memmap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "Memmap.h"
#if(IPDUM_RX_IPDU == STD_ON)
	CONST(PduIdType, IPDUM_CONST) IpduM_Max_Rx_Pdu_ID = IPDUM_MAX_RX_PDU_ID;
#else
	CONST(PduIdType, IPDUM_CONST) IpduM_Max_Rx_Pdu_ID = IPDUM_ZERO;
#endif
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "Memmap.h"

#endif /*  #if (IPDUM_ENABLE == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

