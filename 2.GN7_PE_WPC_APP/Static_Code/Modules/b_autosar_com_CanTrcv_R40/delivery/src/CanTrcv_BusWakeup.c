/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_BusWakeup.c                                           **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Provision of Bus Wakeup control, Bus Wakeup status, Wakeup    **
 **            : polling Task and Call-back Notification                       **
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
 ** 2.10.1    19-Apr-2024   Kim Min Uk     #46132                              **
 ** 2.10.0    11-Nov-2023   Song Yu Bin    #42559                              **
 ** 2.9.4     08-Aug-2022   Kim Min Uk     #36455, #36293, #36981              ** 
 ** 2.9.2     30-Dec-2021   Lim Jong Sun   #33364, #33586                      **
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878, #13347                      **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4805                               **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

/*******************************************************************************
 **                      Include Section                                       **
 *******************************************************************************/
#include "CanTrcv_BusWakeup.h"  /* CAN Transceiver Driver Bus wakeup Control
                                   header file */
#include "CanTrcv.h"
#include "CanTrcv_ModeCtrl.h"
#include "CanIf.h"
#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
#include "Det.h"                /* DET module header file */
#endif

/*******************************************************************************
 **                      Version Information                                   **
 *******************************************************************************/
/* AUTOSAR specification version information */
#define CANTRCV_BUSWAKEUP_C_AR_RELEASE_MAJOR_VERSION    4
#define CANTRCV_BUSWAKEUP_C_AR_RELEASE_MINOR_VERSION    0
#define CANTRCV_BUSWAKEUP_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANTRCV_BUSWAKEUP_C_SW_MAJOR_VERSION    2
#define CANTRCV_BUSWAKEUP_C_SW_MINOR_VERSION    10

/*******************************************************************************
 **                      Version Check                                         **
 *******************************************************************************/
#if (CANTRCV_BUSWAKEUP_AR_RELEASE_MAJOR_VERSION != \
  CANTRCV_BUSWAKEUP_C_AR_RELEASE_MAJOR_VERSION)
#error "CanTrcv_BusWakeup.c : Mismatch in Specification Major Version"
#endif
#if (CANTRCV_BUSWAKEUP_AR_RELEASE_MINOR_VERSION != \
  CANTRCV_BUSWAKEUP_C_AR_RELEASE_MINOR_VERSION)
#error "CanTrcv_BusWakeup.c : Mismatch in Specification Minor Version"
#endif
#if (CANTRCV_BUSWAKEUP_AR_RELEASE_REVISION_VERSION != \
  CANTRCV_BUSWAKEUP_C_AR_RELEASE_REVISION_VERSION)
#error "CanTrcv_BusWakeup.c : Mismatch in Specification Revision Version"
#endif
#if (CANTRCV_BUSWAKEUP_SW_MAJOR_VERSION != CANTRCV_BUSWAKEUP_C_SW_MAJOR_VERSION)
#error "CanTrcv_BusWakeup.c : Mismatch in Software Major Version"
#endif
#if (CANTRCV_BUSWAKEUP_SW_MINOR_VERSION != CANTRCV_BUSWAKEUP_C_SW_MINOR_VERSION)
#error "CanTrcv_BusWakeup.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                      Global Data                                           **
 *******************************************************************************/

/*******************************************************************************
 **                      Function Definitions                                  **
 *******************************************************************************/

/*******************************************************************************
 ** Function Name        : CANTRCV_MAINFUNCTION_MACRO                          **
 **                                                                            **
 ** Service ID           : 0x06                                                **
 **                                                                            **
 ** Description          : This service polls the CAN Transceiver Driver in    **
 **                        StandBy or Sleep Mode for wakeup events.            **
 **                                                                            **
 ** Re-entrancy          : NA                                                  **
 **                                                                            **
 ** Input Parameters     : None                                                **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : The CAN Transceiver Driver must be initialized      **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GblInitStatus         **
 **                        Function(s) invoked : Det_ReportError               **
 *******************************************************************************/
#if(CANTRCV_MAINFUNCTION_USED == STD_ON)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace +2 MISRA-C3:8.4 [Not a defect: Justified] "Function external linkage 
will be generated based on Can_Trcv configurations" */
FUNC(void, CANTRCV_CODE) CANTRCV_MAINFUNCTION_MACRO(void) {
#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Check whether module is initialized */
  if (CANTRCV_UNINITIALIZED == CanTrcv_GblInitStatus) {
    /* Report to DET */
    (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
    CANTRCV_MAINFUNCTION_SID, CANTRCV_E_UNINIT);
  }
#endif /*  #if(STD_ON == CANTRCV_DEV_ERROR_DETECT) */
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
 ** Function Name        : CanTrcv_SetWakeupMode                               **
 **                                                                            **
 ** Service ID           : 0x05                                                **
 **                                                                            **
 ** Description          : This service enables, disables or clears wake-up    **
 **                        events of the Transceiver according to              **
 **                        TrcvWakeupMode.                                     **
 **                                                                            **
 ** Re-entrancy          : Reentrant for different transceivers                **
 **                                                                            **
 ** Input Parameters     : Transceiver, TrcvWakeupMode                         **
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
#if (STD_ON == CANTRCV_WAKEUP_SUPPORTED)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_SetWakeupMode
(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  CANTRCV_UNUSED_VAL(TrcvWakeupMode);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
 ** Function Name        : CanTrcv_CheckWakeFlag                               **
 **                                                                            **
 ** Service ID           : 0x0e                                                **
 **                                                                            **
 ** Description          : This service requests to check the status of the    **
 **                        wakeup flag from the transceiver hardware.          **
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
#if (((STD_ON == CANTRCV_WAKEUP_SUPPORTED) || (STD_ON == CANTRCV_PN_SUPPORTED)) && \
      (STD_ON == CANTRCV_SPI_SUPPORT))
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_CheckWakeFlag(uint8 Transceiver) {
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  Std_ReturnType LddReturnValue;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  /* Initialize return value to E_OK */
  LddReturnValue = (Std_ReturnType) E_OK;

#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Check whether network is out of range */
  if (CANTRCV_NUM_OF_NETWORKS <= Transceiver) {
  /* Report to DET */
    (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
    CANTRCV_SETOPMODE_SID, CANTRCV_E_INVALID_TRANSCEIVER);
  /* Set the return value to E_NOT_OK */
    LddReturnValue = (Std_ReturnType) E_NOT_OK;
  }
#endif
  /* Check any DET error has occurred */
  /* polyspace-begin MISRA-C3:14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if ((Std_ReturnType) E_NOT_OK != LddReturnValue) {
    /* Get the pointer to the structure of the requested network */
    LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[Transceiver];
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Generated array index in range" */

    #if(CANTRCV_TJA1145_PRESENT == STD_ON)
    if (LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145) {
      /* 0x63 Check CW flag*/
      LusCanTrcvSpiSrcData = TJA1145_TRCV_EVENT_STS_REG_R;
      (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      if ((LusCanTrcvSpiDestData & TJA1145_TRCV_EVENT_STS_CW_BITMAST) == CANTRCV_TRUE) 
      {
        LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W
            | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT
            | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT
            | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
        (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData,
            &LusCanTrcvSpiDestData);
      }
      CanIf_CheckTrcvWakeFlagIndication(Transceiver);
    }
    #endif

    #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
    if (LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1145) {
      /* 0x51 Check CANINT flag*/
      /* CANINT  flag is wakeup interrupt*/
      LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
      (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      if ((TCAN1145_INT_1_CANINT_REG & TCAN1145_INT_1_CANINT_REG) == CANTRCV_TRUE) 
      {
        /*Do Nothing*/
      }
      CanIf_CheckTrcvWakeFlagIndication(Transceiver);
    }
    #endif


    LddReturnValue = (Std_ReturnType) E_OK;
  }
  /* polyspace-end MISRA-C3:14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */

  return (LddReturnValue);

}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
 ** Function Name        : CanTrcv_ClearTrcvWufFlag                            **
 **                                                                            **
 ** Service ID           : 0x0a                                                **
 **                                                                            **
 ** Description          : This service Clears the WUF flag in the transceiver **
 **                        hardware. This API shall exist only if              **
 **                        CanTrcvHwPnSupport = TRUE                           **
 **                                                                            **
 ** Re-entrancy          : Reentrant for different transceivers                **
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
#if(((STD_ON == CANTRCV_WAKEUP_SUPPORTED) || (STD_ON == CANTRCV_PN_SUPPORTED)) && \
     (STD_ON == CANTRCV_SPI_SUPPORT))
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ClearTrcvWufFlag(
    uint8 Transceiver) {
  uint16 LusCanTrcvSpiSrcData = 0;
  uint16 LusCanTrcvSpiDestData = 0;

  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  /* Get the pointer to the structure of the requested network */
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[Transceiver];
  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Generated array index in range" */
  #if(CANTRCV_TJA1145_PRESENT == STD_ON)
  if (LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145) {
    /* 0x63 CLEAR CW flag*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W
        | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT
        | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT
        | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
    (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);
  } 
  else 
  {
    CANTRCV_UNUSED_VAL(Transceiver);
  }
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */

  /* 0x63 Check CW flag*/
  LusCanTrcvSpiSrcData = TJA1145_TRCV_EVENT_STS_REG_R;
  (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  if (CANTRCV_FALSE == (LusCanTrcvSpiDestData & TJA1145_TRCV_EVENT_STS_CW_BITMAST)) {
    CanIf_CheckTrcvWakeFlagIndication(Transceiver);
  }
  #endif

  #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
  if (LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1145) {
    /* 0x51 Clear CANINT flag*/
    /* CANINT  flag is wakeup interrupt*/
    LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
    (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData,&LusCanTrcvSpiDestData);

    LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)| (TCAN1145_INT_1_CANINT_CLEAR_BIT));
    (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);
  } 
  else 
  {
    CANTRCV_UNUSED_VAL(Transceiver);
  }
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */

  /* 0x51 Check CANINT flag*/
  LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
  (void)CanTrcv_SendSPI(Transceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  if (CANTRCV_FALSE == (LusCanTrcvSpiDestData & TCAN1145_INT_1_CANINT_REG)) {
    CanIf_CheckTrcvWakeFlagIndication(Transceiver);
  }
  #endif

  return ((Std_ReturnType) E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
 ** Function Name        : CanTrcv_CheckWakeup                                 **
 **                                                                            **
 ** Service ID           : 0x07                                                **
 **                                                                            **
 ** Description          : This is called by underlying CANIF in case a wake up**
 **                        interrupt is detected.                              **
 **                                                                            **
 ** Re-entrancy          : Reentrant                                           **
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
 **                                                                            **
 *******************************************************************************/
#if (STD_ON == CANTRCV_WAKEUP_SUPPORTED)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_CheckWakeup
(uint8 Transceiver)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
 ** Function Name        : CanTrcv_GetBusWuReason                              **
 **                                                                            **
 ** Service ID           : 0x03                                                **
 **                                                                            **
 ** Description          : This service Gets the wakeup reason for the         **
 **                        Transceiver and returns it in parameter Reason.     **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : Transceiver                                         **
 **                                                                            **
 ** Output Parameters    : reason                                              **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : None                          **
 **                                                                            **
 *******************************************************************************/
#if (STD_ON == CANTRCV_WAKEUP_SUPPORTED)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE)CanTrcv_GetBusWuReason
(uint8 Transceiver,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANTRCV_CONST)reason)
{
  CANTRCV_UNUSED_VAL(Transceiver);
  CANTRCV_UNUSED_PTR(reason);
  return((Std_ReturnType)E_OK);
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
 **                      End of File                                           **
 *******************************************************************************/
