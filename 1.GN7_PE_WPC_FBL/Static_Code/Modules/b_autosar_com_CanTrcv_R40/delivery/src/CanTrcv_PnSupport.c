/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_PnSupport.c                                           **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Provision of Initialization and Version check functionality   **
 **                                                                            **
 **  PLATFORM DEPENDANT [yes/no]: yes                                          **
 **                                                                            **
 **  TO BE CHANGED BY USER [yes/no]: no                                        **
 **                                                                            **
 *******************************************************************************/

/*******************************************************************************
 **                      Revision History                                      **
 ********************************************************************************
 ** Revision  Date          By             Description                         **
 ********************************************************************************
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878                              **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4805                               **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

/*******************************************************************************
 **                      Include Section                                       **
 *******************************************************************************/
#include "CanTrcv_PnSupport.h"  /* CAN Transceiver Driver Partial Network
                                 Support header file */
#include "CanTrcv.h"
/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR specification version information */
#define CANTRCV_PN_AR_RELEASE_MAJOR_VERSION    4
#define CANTRCV_PN_AR_RELEASE_MINOR_VERSION    0
#define CANTRCV_PN_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANTRCV_PN_SW_MAJOR_VERSION    2
#define CANTRCV_PN_SW_MINOR_VERSION    10
/*******************************************************************************
 **                      Version Check                                        **
 *******************************************************************************/

#if (CANTRCV_PN_AR_RELEASE_MAJOR_VERSION != \
  CANTRCV_PN_C_AR_RELEASE_MAJOR_VERSION)
#error "CanTrcv_PNSUPPORT.c : Mismatch in Specification Major Version"
#endif
#if (CANTRCV_PN_AR_RELEASE_MINOR_VERSION != \
  CANTRCV_PN_C_AR_RELEASE_MINOR_VERSION)
#error "CanTrcv_PNSUPPORT.c : Mismatch in Specification Minor Version"
#endif
#if (CANTRCV_PN_AR_RELEASE_REVISION_VERSION != \
  CANTRCV_PN_C_AR_RELEASE_REVISION_VERSION)
#error "CanTrcv_PNSUPPORT.c : Mismatch in Specification Revision Version"
#endif
#if (CANTRCV_PN_SW_MAJOR_VERSION != CANTRCV_PN_C_SW_MAJOR_VERSION)
#error "CanTrcv_PNSUPPORT.c : Mismatch in Software Major Version"
#endif
#if (CANTRCV_PN_SW_MINOR_VERSION != CANTRCV_PN_C_SW_MINOR_VERSION)
#error "CanTrcv_PNSUPPORT.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/

/*******************************************************************************
 **                      Function Definitions                                 **
 *******************************************************************************/
//#if (STD_ON == CANTRCV_PN_SUPPORTED)
#if 0 /* Not Supported */

/*******************************************************************************
 ** Function Name        : CanTrcv_GetTrcvSystemData                           **
 **                                                                            **
 ** Service ID           : 0x09                                                **
 **                                                                            **
 ** Description          : This service Reads the transceiver configuration/   **
 **                        status data and returns it through parameter        **
 **                        TrcvSysData. This API shall exist only if           **
 **                        CanTrcvHwPnSupport = TRUE                           **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : TrcvSysData                                         **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 **                                                                            **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_GetTrcvSystemData
(uint8 Transceiver, P2CONST(uint32, AUTOMATIC, CANTRCV_CONST)TrcvSysData)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  CANTRCV_UNUSED_PTR(TrcvSysData);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_ReadTrcvTimeoutFlag                         **
 **                                                                            **
 ** Service ID           : 0x0b                                                **
 **                                                                            **
 ** Description          : This service reads the status of the timeout flag   **
 **                        from the transceiver hardware. This API shall exist **
 **                        only if CanTrcvHwPnSupport = TRUE                   **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : Transceiver                                         **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ReadTrcvTimeoutFlag
(uint8 Transceiver,
    P2CONST(CanTrcv_TrcvFlagStateType, AUTOMATIC, CANTRCV_CONST)FlagState)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  CANTRCV_UNUSED_PTR(FlagState);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_ClearTrcvTimeoutFlag                        **
 **                                                                            **
 ** Service ID           : 0x0c                                                **
 **                                                                            **
 ** Description          : This service clears the status of the timeout flag  **
 **                        in the transceiver hardware. This API shall exist   **
 **                        only if CanTrcvHwPnSupport = TRUE.                  **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : Transceiver                                         **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ClearTrcvTimeoutFlag
(uint8 Transceiver)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_ReadTrcvSilenceFlag                         **
 **                                                                            **
 ** Service ID           : 0x0d                                                **
 **                                                                            **
 ** Description          : This service reads the status of the timeout flag   **
 **                        from the transceiver hardware. This API shall exist **
 **                        only if CanTrcvHwPnSupport = TRUE                   **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : Transceiver                                         **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ReadTrcvSilenceFlag
(uint8 Transceiver,
    P2CONST(CanTrcv_TrcvFlagStateType, AUTOMATIC, CANTRCV_CONST)FlagState)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  CANTRCV_UNUSED_PTR(FlagState);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_SetPNActivationState                        **
 **                                                                            **
 ** Service ID           : 0x0f                                                **
 **                                                                            **
 ** Description          : This service configures the wake-up of the          **
 **                        transceiver for Standby and Sleep Mode: Either the  **
 **                        CAN transceiver is woken up by a remote wake-up     **
 **                        pattern (standard CAN wake-up) or by the configured **
 **                        remote wake-up frame                                **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : ActivationState                                     **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_SetPNActivationState
(CanTrcv_PNActivationType ActivationState)
{
  CANTRCV_UNUSED_VAL(ActivationState);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_MainFunctionDiagnostics                     **
 **                                                                            **
 ** Service ID           : 0x08                                                **
 **                                                                            **
 ** Description          : This service Reads the transceiver diagnostic status**
 **                        periodically and sets product/development           **
 **                        accordingly.                                        **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : None                                                **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANTRCV_CODE) CanTrcv_MainFunctionDiagnostics(void)
{

}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
 **                      End of File                                          **
 *******************************************************************************/
