/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanTrcv_ModeCtrl.c                                            **
**                                                                            **
**  TARGET    : General CAN Transceiver                                       **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
**                                                                            **
**  PURPOSE   : Provision of Mode Change Functionality                        **
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
** 2.10.0    11-Nov-2023   Song Yu Bin    #42559,#42487                       **
** 2.9.7     17-Aug-2023   Song Yu Bin    #41231                              **
** 2.9.6     10-Jan-2023   Kim Min Uk     #38573                              **
** 2.9.5     18-Aug-2022   Hojin Seong    #37205                              **
** 2.9.4     08-Aug-2022   Kim Min Uk     #36455, #36293, #36981              **
** 2.9.1     30-Dec-2021   Lim Jong Sun   #33364                              **
** 2.9.0     06-Oct-2021   Lim Jong Sun   #32350                              **
** 2.8.0     08-Mar-2021   HieuTM8        #28372                              **
** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              **
** 2.6.1     30-Oct-2019   Lim Jong sun   #15680, #19927                      **
** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878, #14441, #14551              **
** 2.5.8     27-Feb-2019   Lim Jong Sun   #16239                              **
** 2.5.7     23-Aug-2017   Lim Jong Sun   #9642, #9658                        **
** 2.5.6     11-Aug-2017   Lim Jong Sun   #9477                               **
** 2.5.5     17-Jul-2017   Lim Jong Sun   #9247                               **
** 2.5.4     13-Jul-2017   Lim Jong Sun   #9199                               **
** 2.5.3     29-May-2017   Lim Jong Sun   #8679                               **
** 2.5.2     27-Arp-2017   Lim Jong Sun   #8357, #8358                        **
** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
** 2.4.1     01-Nov-2016   Lim Jong Sun   #6459, #6570, #6546                 **
** 2.4.0     21-Oct-2016   Lim Jong Sun   #6362                               **
** 2.3.2     31-Aug-2016   Lim Jong Sun   #5750, #5903                        **
** 2.3.1     09-Aug-2016   Lim Jong Sun   #4736, #4689, #5655                 **
** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #5277, #5333                 **
** 2.2.7     24-Feb-2015   Lim Jong Sun   #4252, #3781                        **
** 2.2.6     22-Feb-2015   Lim Jong Sun   #3781                               **
** 2.2.5     10-Nov-2015   Lim Jong Sun   #3402, #3453                        **
** 2.0.4     30-Jun-2015   Lim Jong Sun   #2814                               **
** 2.0.2     10-Mar-2015   Lim Jong Sun   #2287                               **
** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanTrcv_ModeCtrl.h"  /* CAN Transceiver Driver Mode Control header
                                  file */
#include "CanIf.h"             /* CAN Interface module header file */
#include "CanIf_Cbk.h"
#include "Dio.h"               /* Dio module header file */
#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
#include "Det.h"               /* Det Module header file */
#endif
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#include "Rte_CanTrcv.h"               /* Rte header file */
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define CANTRCV_MODECTRL_C_AR_RELEASE_MAJOR_VERSION    4
#define CANTRCV_MODECTRL_C_AR_RELEASE_MINOR_VERSION    0
#define CANTRCV_MODECTRL_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANTRCV_MODECTRL_C_SW_MAJOR_VERSION    2
#define CANTRCV_MODECTRL_C_SW_MINOR_VERSION    10

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CANTRCV_MODECTRL_AR_RELEASE_MAJOR_VERSION != \
  CANTRCV_MODECTRL_C_AR_RELEASE_MAJOR_VERSION)
  #error "CanTrcv_ModeCtrl.c : Mismatch in Specification Major Version"
#endif
#if (CANTRCV_MODECTRL_AR_RELEASE_MINOR_VERSION != \
  CANTRCV_MODECTRL_C_AR_RELEASE_MINOR_VERSION)
  #error "CanTrcv_ModeCtrl.c : Mismatch in Specification Minor Version"
#endif
#if (CANTRCV_MODECTRL_AR_RELEASE_REVISION_VERSION != \
  CANTRCV_MODECTRL_C_AR_RELEASE_REVISION_VERSION)
  #error "CanTrcv_ModeCtrl.c : Mismatch in Specification Revision Version"
#endif
#if (CANTRCV_MODECTRL_SW_MAJOR_VERSION != CANTRCV_MODECTRL_C_SW_MAJOR_VERSION)
  #error "CanTrcv_ModeCtrl.c : Mismatch in Software Major Version"
#endif
#if (CANTRCV_MODECTRL_SW_MINOR_VERSION != CANTRCV_MODECTRL_C_SW_MINOR_VERSION)
  #error "CanTrcv_ModeCtrl.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace:begin<RTE:UNR:Not a defect : No Action Planned> Because condition check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */

#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_Delay(volatile uint32 ticks);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_ArisuCan_RequestCanMode
  (CanTrcv_HwType LddCanTrcv, ArisuCan_SBCModeType LddMode);
static FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE)CanTrcv_ArisuCan_CheckCanMode
  (CanTrcv_HwType LddCanTrcv, ArisuCan_SBCModeType LddMode);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : CANTRCV_SETOPMODE_MACRO                             **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : This service sets the internal state of             **
**                        CAN Transceiver Driver to Normal or StandBy         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Transceiver, OpMode                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : The CAN Transceiver Driver must be initialized      **
**                                                                            **
** Remarks              : Global Variable(s)  : CanTrcv_GblInitStatus,        **
**                                           CanTrcv_GaaCanTrcvNetwork**
**                                              CanTrcv_GaaByteArray  **
**                        Function(s) invoked : Det_ReportError,              **
**                                              CanIf_TrcvModeIndication,     **
**                                              CanTrcv_NormalMode,           **
**                                              CanTrcv_StandbyMode           **
**                                              CanTrcv_SleepMode             **
*******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, CANTRCV_CODE) CANTRCV_SETOPMODE_MACRO
  (uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
  #if((CANTRCV_SLEEPINIT_PRESENT == STD_ON) || ((CANTRCV_TJA1145_PRESENT == STD_ON) && (STD_ON == CANTRCV_SPI_SUPPORT)) || (CANTRCV_ALLCHANNEL_USED == STD_OFF))
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST)
  LpCanTrcvNetwork;
  #endif
  #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
  uint8 LucCurrentOpMode;
  #endif
  Std_ReturnType LddReturnValue;
  CanTrcv_TrcvModeType LucCanTrcvModeSts;

  #if((CANTRCV_TJA1145_PRESENT == STD_ON) && (STD_ON == CANTRCV_SPI_SUPPORT))
  CanTrcv_UndervolType LddCheckUndervol = CANTRCV_NOUNDERVOL;
  #endif

  /* Initialize return value to E_OK */
  LddReturnValue = (Std_ReturnType)E_OK;

  #if((CANTRCV_TJA1145_PRESENT == STD_ON) && (STD_ON == CANTRCV_SPI_SUPPORT))
	  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[Transceiver];
	  if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145)
	  {
      LddCheckUndervol = CanTrcv_CheckUndervoltage(Transceiver);
            if(CANTRCV_NOUNDERVOL < LddCheckUndervol)
            {
              #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
                (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                  CANTRCV_SETOPMODE_SID, CANTRCV_E_TRCV_UNDERVOLTAGE);
              #endif
            }
	  }
  #endif

  
  #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Check whether the module is initialized */
  if (CANTRCV_UNINITIALIZED == CanTrcv_GblInitStatus)
  {
    /* Report to DET */
    (void)Det_ReportError (CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_SETOPMODE_SID, CANTRCV_E_UNINIT);
    /* Set the return value to E_NOT_OK */
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  /* Check whether network is out of range */
  if (CANTRCV_NUM_OF_NETWORKS <= Transceiver)
  {
    /* Report to DET */
    (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_SETOPMODE_SID, CANTRCV_E_INVALID_TRANSCEIVER);
    /* Set the return value to E_NOT_OK */
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }

  /* Check any DET error has occurred */
  if((Std_ReturnType)E_NOT_OK != LddReturnValue)
  #endif/* #if(CAN_DEV_ERROR_DETECT == STD_ON) */
  {


    /* Check if channel is used or not*/
    /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */      
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Generated array index in range" */
    #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
    /* Get the pointer to the structure of the requested network */
    LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[Transceiver];
    if(CANTRCV_TRUE == (boolean)(LpCanTrcvNetwork->blChannelUsed))
    #endif
    {
      (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
      #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
      /* Get the current operation mode of CanTrcv network */
      LucCurrentOpMode = (uint8)CanTrcv_GaaByteArray[Transceiver];
      /* Report to DET if invalid mode is requested */
      if(((uint8) CANTRCV_TRCVMODE_SLEEP == LucCurrentOpMode) &&
        ((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_STANDBY == OpMode))
      {
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
          CANTRCV_SETOPMODE_SID, CANTRCV_E_TRCV_NOT_NORMAL);
        /* Set the return value to E_NOT_OK */
        LddReturnValue = (uint8)E_NOT_OK;
      }
      /* Report to DET if current mode is not equal to standby and requested
         mode is in sleep */
      else if(((uint8)CANTRCV_TRCVMODE_NORMAL ==  LucCurrentOpMode) &&
        ((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_SLEEP == OpMode))
      {
        /* Report to DET */
        (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
          CANTRCV_SETOPMODE_SID, CANTRCV_E_TRCV_NOT_STANDBY);
        /* Set the return value to E_NOT_OK */
        LddReturnValue = (uint8)E_NOT_OK;
      }
      else
      #endif
      {
        if((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_NORMAL == OpMode)
        {
          /* Invoke the CanTrcv_NormalMode to set the Normal Mode */
          LucCanTrcvModeSts = CanTrcv_NormalMode(Transceiver);
        }
        #if((CANTRCV_STANDBYINIT_PRESENT == STD_ON) || (CANTRCV_SLEEPINIT_PRESENT == STD_ON))
        else if((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_STANDBY== OpMode)
        {
          /* Feature#1318 */
          /* MISRA 10.4 */
          #if(CANTRCV_SLEEPINIT_PRESENT == STD_ON)
          /* Get the pointer to the structure of the requested network */
          LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[Transceiver];
          if(LpCanTrcvNetwork->ddSleepModeUsed == CANTRCV_SLEEPMODE_UNUSED){
          /* Invoke the CanTrcv_StandbyMode to set the Standby Mode */
            LucCanTrcvModeSts = CanTrcv_StandbyMode(Transceiver);
          }else{
            LucCanTrcvModeSts = CanTrcv_SleepMode(Transceiver);
          }
          #else
          LucCanTrcvModeSts = CanTrcv_StandbyMode(Transceiver);
          #endif
        }
        #endif 
        #if(CANTRCV_SLEEPINIT_PRESENT == STD_ON)
        else if((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_SLEEP== OpMode)
        {
          /* Invoke the CanTrcv_SleepMode to set the Sleep Mode */
          /* CanSM don't set the Sleep Mode only StandbyMode */
          LucCanTrcvModeSts = CanTrcv_SleepMode(Transceiver);
        }
        #endif
        else
        {
          LucCanTrcvModeSts = OpMode;
        }
       
        /* Indicate mode change to CanIf */
        (void)CanIf_TrcvModeIndication(Transceiver, LucCanTrcvModeSts);
        
        if((LucCanTrcvModeSts == CANTRCV_TRCVMODE_NORMAL) || 
          (LucCanTrcvModeSts == CANTRCV_TRCVMODE_STANDBY) || 
          (LucCanTrcvModeSts == CANTRCV_TRCVMODE_SLEEP))
        {
          /* Set the Operational Mode of the requested network */
          CanTrcv_GaaByteArray[Transceiver] = LucCanTrcvModeSts;
        }
      }
      (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
    }
    #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
    /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */        
    #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
    else
    {
       /*Report a Development error If there is no/incorrect communication to
       the transceiver*/

       (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                              CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
      LddReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    #endif
    #endif
  } /* if(LddReturnValue != E_NOT_OK)*/
  return (LddReturnValue);/* Return Std_ReturnType */
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CANTRCV_GETOPMODE_MACRO                             **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : This service gets the actual Mode of CAN Transceiver**
**                        Driver                                              **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Transceiver                                         **
**                                                                            **
** Output Parameters    : OpMode                                              **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : The CAN Transceiver Driver must be initialized      **
**                                                                            **
** Remarks              : Global Variable(s)  : CanTrcv_GblInitStatus,        **
**                                           CanTrcv_GaaCanTrcvNetwork**
**                                              CanTrcv_GaaByteArray  **
**                        Function(s) invoked : Det_ReportError               **
*******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, CANTRCV_CODE)CANTRCV_GETOPMODE_MACRO
  (uint8 Transceiver, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC,
  CANTRCV_APPL_DATA)OpMode)
{
  #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST)
    LpCanTrcvNetwork;
  #endif
  
  Std_ReturnType LddReturnValue;
  
  /* Initialize return value to E_OK */
  LddReturnValue = (Std_ReturnType)E_OK;
  
  #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
  /* Get the pointer to the structure of the requested network */
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[Transceiver];
  #endif
  
  #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Check whether the module is Initialized */
  if (CANTRCV_UNINITIALIZED == CanTrcv_GblInitStatus)
  {
    /* Report to DET */
    (void)Det_ReportError (CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_GETOPMODE_SID, CANTRCV_E_UNINIT);
    /* Set the return value to E_NOT_OK  */
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  /* Check whether the Transceiver id is out of range */
  if(CANTRCV_NUM_OF_NETWORKS <= Transceiver)
  {
    /* Report to DET */
    (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_GETOPMODE_SID, CANTRCV_E_INVALID_TRANSCEIVER);
    /* Set the return value to E_NOT_OK */
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  /* Check for NULL POINTER */
  if(NULL_PTR == OpMode)
  {
    /* Report to DET */
    (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_GETOPMODE_SID, CANTRCV_E_PARAM_POINTER);
    /* Set the return value to E_NOT_OK */
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  /* Check whether any DET error has occurred */
  if((Std_ReturnType)E_NOT_OK != LddReturnValue)
  #endif /*   #if(CANTRCV_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if channel is used or not*/
    /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Generated array index in range" */
    #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
    if(CANTRCV_TRUE == (boolean)(LpCanTrcvNetwork->blChannelUsed))
    #endif
    {
      /* MISRA Rule         : 1.2
         Message            : Dereferencing pointer value that is apparently
                              NULL.
         Reason             : "OpMode" pointer is checked and verified when
                              DET is switched STD_ON.
         Verification       : However, the part of the code is
                              verified manually and it is not having
                              any impact on code.
      */
      /* Get the operational mode of CAN Transceiver Driver network */
      /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
      *OpMode = (CanTrcv_TrcvModeType)CanTrcv_GaaByteArray[Transceiver];

    }
    #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
    /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */        
    #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
    else
    {
       /*Report a Development error If there is no/incorrect communication to
       the transceiver*/

       (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                              CANTRCV_GETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
      LddReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    #endif
    #endif
  }

  return (LddReturnValue); /* Return Std_ReturnType */
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : CanTrcv_NormalMode                                    **
**                                                                            **
** Service ID         : Not Applicable                                        **
**                                                                            **
** Description        : This service initiates the transition to the Normal   **
**                      operating mode with complete functionality.           **
**                                                                            **
** Re-entrancy        : Non Re-entrant                                        **
**                                                                            **
** Input Parameters   : LucTransceiver                                        **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : CanTrcv_TrcvModeType                                  **
**                                                                            **
** Preconditions      : The CAN Transceiver Driver must be initialized.       **
**                                                                            **
** Remarks            : Global Variable(s)  :CanTrcv_GaaCanTrcvNetwork        **
**                      Function(s) invoked : Dio_WriteChannel                **
**                      CanIf_ConfirmPnAvailability
*******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"

FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_NormalMode(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  Dio_LevelType RetVal, RetVal1;
  CanTrcv_TrcvModeType LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
  #if(STD_ON == CANTRCV_SPI_SUPPORT)
  uint16 LusCanTrcvSpiSrcData = 0;
  uint16 LusCanTrcvSpiDestData = 0;
  uint16 LusCanTrcvSpiDestData1;
  CanTrcv_PnErrType LddCheckPnFlag = (CanTrcv_PnErrType)CANTRCV_NOERR;
  #endif

  /* Get the pointer to the structure of the requested network */
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];
  /* Feature#1318 */
  /* Check whether Transceiver Used 2pins STB, EN PINS*/
  /* polyspace +2 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Array index in range" */
  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1054)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1055)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1041A)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1043)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1463)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6254G)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6251G))
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* CANTRCV_TJA1054, CANTRCV_TJA1055, CANTRCV_TJA1041A,TLE6254_3G
    STB,EN Active High */
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    /* Check Hardware pin status */
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_HIGH) || (RetVal1 != STD_HIGH)){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  }
  
  #if(STD_ON == CANTRCV_TCAN1043A_PRESENT)
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1043A)
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* Invoke the Dio_WriteChannel to set the Enable pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    /* Check Hardware pin status */
    RetVal1 = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if(RetVal1 != STD_HIGH){
      /* Invoke the Dio_WriteChannel to set the Enable pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    }
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Check Hardware pin status */
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    if(RetVal != STD_LOW){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    }
    /* Invoke the Dio_WriteChannel to set the Enable pin to level-Low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    /* Check Hardware pin status */
    RetVal1 = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if( RetVal1 != STD_LOW){
      /* Invoke the Dio_WriteChannel to set the Enable pin to level-Low */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    }
    /*Delay for TCAN1043A 20 us*/
    CanTrcv_Delay(CANTRCV_TCAN1043A_WAIT_COUNT);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
    /* Invoke the Dio_WriteChannel to set the Enable pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    /* Check Hardware pin status */
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_HIGH) || (RetVal1 != STD_HIGH)){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
      /* Invoke the Dio_WriteChannel to set the Enable pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif

  #if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
  else if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN0)
          ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN1)
          ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN2)
          ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN3))
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

    if(ArisuCan_GddSBCModeSts != ARISUCAN_SBCMODE_NORMAL)
    {
      (void)CanTrcv_ArisuCan_SetMode(ARISUCAN_SBCMODE_NORMAL);
    }
        
    CanTrcv_ArisuCan_RequestCanMode
                  (LpCanTrcvNetwork->ddCanTrcvHwDev, ARISUCAN_SBCMODE_NORMAL);

   
    /* Check ARISU-CAN CanTrcv Mode */
    LddCanTrcvMode = CanTrcv_ArisuCan_CheckCanMode
      (LpCanTrcvNetwork->ddCanTrcvHwDev, ARISUCAN_SBCMODE_NORMAL);

    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  }
  #endif

  #if(STD_ON == CANTRCV_SPI_SUPPORT) 
  #if(STD_ON == CANTRCV_TJA1145_PRESENT) 
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145)
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    
    /* 0x01 SBC Mode Normal */
    LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_W | TJA1145_SBC_MODE_NORMAL);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* #15680 - 0x64 WAKE pin event clear */
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W | TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT | TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    
    #if (STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
    {
      /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
      LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_PNCOK_1_BIT | TJA1145_CAN_CONTROL_CPNC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

      LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);
      if(CANTRCV_NOERR < LddCheckPnFlag)
      {
        if(CANTRCV_PORERR < LddCheckPnFlag){
        #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
        (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
           CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
        #endif
        }else{
          /* Do Nothing */      
        }
      
        /* re-configuration */
        /* 0x01 SBC Mode Normal */
        LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_W | TJA1145_SBC_MODE_NORMAL);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /* #15680 - 0x64 WAKE pin event clear */
        LusCanTrcvSpiSrcData = (TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W | TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT | TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
         
        /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
        LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_PNCOK_1_BIT | TJA1145_CAN_CONTROL_CPNC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);
        if(CANTRCV_NOERR == LddCheckPnFlag){
          CanIf_ConfirmPnAvailability(LucTransceiver);
        }else{
          /* Do Nothing */
        }
        
      }else{
        CanIf_ConfirmPnAvailability(LucTransceiver);
      }
    }else{
      /* 0x20, CFDC=1, PNCOK=0, CPNC=0  Write*/
      LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);     
    }
    #else
    /* 0x20, CFDC=1, PNCOK=0, CPNC=0  Write*/
    LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  
    #endif

    /* 0x1*/
    LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  

    /* 0x20 */
    LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData1);
    
    if(TJA1145_SBC_MODE_NORMAL == (LusCanTrcvSpiDestData & TJA1145_SBC_MODE_NORMAL)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
    }else if(TJA1145_SBC_MODE_STANDBY == (LusCanTrcvSpiDestData & TJA1145_SBC_MODE_STANDBY)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;
    }else if(TJA1145_SBC_MODE_SLEEP == (LusCanTrcvSpiDestData & TJA1145_SBC_MODE_SLEEP)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_SLEEP;
    }else{
      /* Do Nothing */      
    }
    
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  }
  #endif
  #if(STD_ON == CANTRCV_TCAN1145_PRESENT)
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1145)
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    
    /* 0x10 Mode Control Normal */
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_NORMAL);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    
    /* 0x11 Clear Wake state pin */
    LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    
    #if (STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
    {
      /*0x47  SWCFG Set Selective Wake Configuration*/
      LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

      /*0X10 SW_EN Set Selective wake enable*/
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        
      LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);
      if(CANTRCV_NOERR < LddCheckPnFlag)
      {
        if(CANTRCV_PORERR < LddCheckPnFlag){
        #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
        (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
           CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
        #endif
        }else{
          /* Do Nothing */      
        }
        /* re-configuration */
        /* 0x10 Mode Control Normal */
        LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_NORMAL);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
            
        /* 0x11 Clear Wake state pin */
        LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /*0x47 SWCFG Set Selective Wake Configuration*/
        LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /*0x10 set SW_EN =1  */
        LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
       (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        if(CANTRCV_NOERR == LddCheckPnFlag){
          CanIf_ConfirmPnAvailability(LucTransceiver);
        }else{
          /* Do Nothing */
        }
      }
      else
      {
          CanIf_ConfirmPnAvailability(LucTransceiver);
      }
    }

    #endif
  
    /* 0x10 Mode Control Normal */
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* Retry write Normal mode*/
    if(TCAN1145_MODE_CNTRL_NORMAL != (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_NORMAL))
    {
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_NORMAL);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    }
    
    
    if(TCAN1145_MODE_CNTRL_NORMAL == (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_NORMAL)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
    }else if(TCAN1145_MODE_CNTRL_STANDBY == (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_STANDBY)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;
    }else if(TCAN1145_MODE_CNTRL_SLEEP == (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_SLEEP)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_SLEEP;
    }else{
      /* Do Nothing */      
    }

    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif
  #endif
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  else
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    /* CANTRCV_TJA1042, CANTRCV_TJA1050, CANTRCV_TJA1051, CANTRCV_TLE6251DS, 
       NCV7342, TLE6250G, CANTRCV_TLE7250G, CANTRCV_TJA1044, 
             CANTRCV_TCAN1044, CANTRCV_TCAN1057, CANTRCV_TJA1059 Active LOW */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    if((RetVal) != STD_LOW){
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  return LddCanTrcvMode;
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : CanTrcv_StandbyMode                                   **
**                                                                            **
** Service ID         : Not Applicable                                        **
**                                                                            **
** Description        : This service initiates the transition to the Standby  **
**                      operating mode with complete functionality.           **
**                                                                            **
** Re-entrancy        : Non Re-entrant                                        **
**                                                                            **
** Input Parameters   : LucTransceiver                                        **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : CanTrcv_TrcvModeType                                  **
**                                                                            **
** Preconditions      : The CAN Transceiver Driver must be initialized.       **
**                                                                            **
** Remarks            : Global Variable(s)  :CanTrcv_GaaCanTrcvNetwork        **
**                        Function(s) invoked : Dio_WriteChannel              **
*******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_StandbyMode(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST)
    LpCanTrcvNetwork;
  Dio_LevelType RetVal, RetVal1;
  #if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
  uint16 LusSpiSrcData;
  #endif
  #if(STD_ON == CANTRCV_SPI_SUPPORT)
  uint16 LusCanTrcvSpiSrcData = 0;
  uint16 LusCanTrcvSpiDestData = 0;
  CanTrcv_PnErrType LddCheckPnFlag = (CanTrcv_PnErrType)CANTRCV_NOERR;
  #endif
  CanTrcv_TrcvModeType LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;
  /* Get the pointer to the structure of the requested network */
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];
  /* Feature#1318 */
  /* Infineon Transceiver must not use StandByMode */
  /* 1 Pin control is required for control */
  /* polyspace +2 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Array index in range" */
  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1050)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1051)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6251DS)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1042)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6250G)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE7250G)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_NCV7342)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1044)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1059)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1044)
   ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1057))
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    if((RetVal!= STD_HIGH)){
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
  }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  /* 2 Pin control is required for control */
  /* polyspace +1 DEFECT:DEAD_CODE,USELESS_IF CERT-C:MSC12-C [Not a defect:Low] "Condition will be executed based on the configured values" */
  }else if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6251G)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1055)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1043)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1463)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1054)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6254G)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1041A)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1043A))
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* CanTrcv shoud need two h/w pins */
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);

    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_LOW) || (RetVal1 != STD_LOW)){
     /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
     Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
     /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
     Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
  else if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN0)
          ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN1)
          ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN2)
          ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_ARISU_CAN3))
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

    /* ARISU-CAN CanTrcv Mode Change */
    CanTrcv_ArisuCan_RequestCanMode
      (LpCanTrcvNetwork->ddCanTrcvHwDev, ARISUCAN_SBCMODE_STOP);  

    /* Check ARISU-CAN CanTrcv Mode */
    LddCanTrcvMode = CanTrcv_ArisuCan_CheckCanMode
      (LpCanTrcvNetwork->ddCanTrcvHwDev, ARISUCAN_SBCMODE_STOP);
      
    /*ARISU-CAN Wake Up Clear */
    LusSpiSrcData = ARISUCAN_WK_STAT_0_REG_W;
    (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

    /*ARISU-CAN Wake Up Clear */
    LusSpiSrcData = ARISUCAN_WK_STAT_2_REG_W;
    (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif

  #if(CANTRCV_TJA1145_PRESENT == STD_ON)
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145)
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    #if(STD_ON == CANTRCV_SPI_SUPPORT)

    /* 0x63 CLEAR CW flag - Remote Wake up*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

    /* 0x61 CLEAR PO flag */
    LusCanTrcvSpiSrcData = (TJA1145_SYS_EVENT_STS_REG_W | TJA1145_SYS_EVENT_STS_PO_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

    /* #15680 - 0x64 CLEAR WPR, WPF flag */
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W | TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT | TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    
    #if (STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
    {
      /* 0x20 Read PNCOK bit*/
      LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

      if(CANTRCV_FALSE == (LusCanTrcvSpiDestData & TJA1145_CAN_CONTROL_PNCOK_1_BIT))
      {
        /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
        LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_PNCOK_1_BIT | TJA1145_CAN_CONTROL_CPNC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
      }
      
      LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);
      
      if(CANTRCV_NOERR < LddCheckPnFlag){
        if(CANTRCV_PORERR < LddCheckPnFlag){
        #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
        (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
           CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
        #endif
        }
          /* re-configuration */
          /* 0x63 CLEAR CW flag - Remote Wake up*/
          LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
          (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

          /* 0x61 CLEAR PO flag */
          LusCanTrcvSpiSrcData = (TJA1145_SYS_EVENT_STS_REG_W | TJA1145_SYS_EVENT_STS_PO_CLEAR_BIT);
          (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

          /* #15680 - 0x64 CLEAR WPR, WPF flag */
          LusCanTrcvSpiSrcData = (TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W | TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT | TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT);
          (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        
          /* 0x20 Read PNCOK bit*/
          LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_R);
          (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
        
          if(CANTRCV_FALSE == (LusCanTrcvSpiDestData & TJA1145_CAN_CONTROL_PNCOK_1_BIT))
          {
            /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
            LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_PNCOK_1_BIT | TJA1145_CAN_CONTROL_CPNC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
            (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
          }  
        
      }else{
        /* Do Nothing */
      }
    }
    #endif
     
    /* 0x01, Standby Write*/
    LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_W | TJA1145_SBC_MODE_STANDBY);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    /* Force Stop on Standby Mode */

    /* Check Mode */
    LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  

    if(TJA1145_SBC_MODE_STANDBY == (LusCanTrcvSpiDestData & TJA1145_SBC_MODE_STANDBY)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;
    }else if(TJA1145_SBC_MODE_NORMAL == (LusCanTrcvSpiDestData & TJA1145_SBC_MODE_NORMAL)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
    }else if(TJA1145_SBC_MODE_SLEEP == (LusCanTrcvSpiDestData & TJA1145_SBC_MODE_SLEEP)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_SLEEP;
    }else{
      /* Do Nothing */      
    }
    
    #endif
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif

  #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1145)
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    #if(STD_ON == CANTRCV_SPI_SUPPORT)

    /* 0x52 clear PWRON bit*/
    LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_INT_2_PWRON_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x51 CANINT,LWU,WKERR,FRAME_OVF flag clear*/
    LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)|(LusCanTrcvSpiDestData & TCAN1145_INT_1_CLEAR_FLAG_BITMASK));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x11 Clear Wake state pin */
    LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);


    #if (STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
    {
      /*0x47 SWCFG Set Selective Wake Configuration*/
      LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      
      /*0x10 set SW_EN =1 */
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

      LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);
      if(CANTRCV_NOERR < LddCheckPnFlag)
      {
        if(CANTRCV_PORERR < LddCheckPnFlag){
        #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
        (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
           CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
        #endif
        }

        /* re-configuration */
        /*0x52 clear PWRON bit*/
        LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
       LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_INT_2_PWRON_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /* 0x51 CANINT,LWU,WKERR,FRAME_OVF flag clear*/
        LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)|(LusCanTrcvSpiDestData & TCAN1145_INT_1_CLEAR_FLAG_BITMASK));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /* 0x11 Clear Wake state pin */
        LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /*0x47 SWCFG Set Selective Wake Configuration*/
        LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /*0X10 SW_EN Set Selective wake enable*/
        LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
       (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      }
      else
      {
          /*Do nothing*/
      }

    }
    #endif
    /* 0x10 Mode Control Standby */
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_STANDBY);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x10 Mode Check */
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* Retry write Standby mode*/
    if(TCAN1145_MODE_CNTRL_STANDBY != (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_STANDBY))
    {
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_STANDBY);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    }
    
    if(TCAN1145_MODE_CNTRL_NORMAL == (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_NORMAL)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
    }else if(TCAN1145_MODE_CNTRL_STANDBY == (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_STANDBY)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;
    }else if(TCAN1145_MODE_CNTRL_SLEEP == (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_SLEEP)){
      LddCanTrcvMode = CANTRCV_TRCVMODE_SLEEP;
    }else{
      /* Do Nothing */      
    }
    #endif
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */ 
  else
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* CanTrcv shoud need two h/w pins */
    /* Step 1/2 - Power-on Standby */
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);

    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_HIGH) || (RetVal1 != STD_LOW)){
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    } 
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }

  return LddCanTrcvMode;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : CanTrcv_SleepMode                                     **
**                                                                            **
** Service ID         : Not Applicable                                        **
**                                                                            **
** Description        : This service initiates the transition to the Sleep    **
**                      operating mode with complete functionality.           **
**                                                                            **
** Re-entrancy        : Non Re-entrant                                        **
**                                                                            **
** Input Parameters   : LucTransceiver                                        **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : CanTrcv_TrcvModeType                                  **
**                                                                            **
** Preconditions      : The CAN Transceiver Driver must be initialized.       **
**                                                                            **
** Remarks            : Global Variable(s)  :CanTrcv_GaaCanTrcvNetwork**
**                        Function(s) invoked : Dio_WriteChannel              **
*******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_SleepMode(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST)
    LpCanTrcvNetwork;
  Dio_LevelType RetVal, RetVal1;
  #if(STD_ON == CANTRCV_SPI_SUPPORT)
  uint16 LusCanTrcvSpiSrcData = 0;
  uint16 LusCanTrcvSpiDestData = 0;
  CanTrcv_PnErrType LddCheckPnFlag = (CanTrcv_PnErrType)CANTRCV_NOERR;
  #endif
  
  /* CanSm doesn't use SleepMode in AUTOSAR Spec.(PN Not Supported) */
  CanTrcv_TrcvModeType LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;

  /* Feature#1318 */
  /* Step 1/2 - GotoSleep */
  /* Get the pointer to the structure of the requested network */
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];
  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  /* polyspace +3 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Array index in range" */
  /* polyspace +2 MISRA-C3:9.1, DEFECT:NON_INIT_PTR [Not a defect: Justified] "Calling function check the  LucTransceiver condition, so it will initialized LpCanTrcvNetwork by above code " */
  /* polyspace +1 DEFECT:DEAD_CODE,USELESS_IF CERT-C:MSC12-C [Not a defect:Low] "Condition will be executed based on the configured values" */
  if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1054)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1055)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6254G)
    ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TLE6251G))
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    /* #2287 Delay   */  
    CanTrcv_Delay(CANTRCV_WAIT_COUNT);  
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_LOW) || (RetVal1 != STD_HIGH)){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
        /* #2287 Delay   */  
      CanTrcv_Delay(CANTRCV_WAIT_COUNT);
    }
    /* Step 2/2 - Sleep */
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);

    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_LOW) || (RetVal1 != STD_LOW)){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  else if ((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1041A)
         ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1043)
         ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1463)
         ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1043A))
  {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    /* #2287 Delay   */  
    CanTrcv_Delay(CANTRCV_WAIT_COUNT);
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_LOW) || (RetVal1 != STD_HIGH)){
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_HIGH);
    /* #2287 Delay   */  
    CanTrcv_Delay(CANTRCV_WAIT_COUNT);  
    }
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #if(CANTRCV_TJA1145_PRESENT == STD_ON)
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145)
  {
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    
    #if(STD_ON == CANTRCV_SPI_SUPPORT)
    /* 0x63 CLEAR CW flag - Remote Wake up*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

    /* 0x61 CLEAR PO flag */
    LusCanTrcvSpiSrcData = (TJA1145_SYS_EVENT_STS_REG_W | TJA1145_SYS_EVENT_STS_PO_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

    /* #15680 - 0x64 CLEAR WPR, WPF flag */
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W | TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT | TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
    
    #if (STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
    {
      /* 0x20 Read PNCOK bit*/
      LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
      
      if(CANTRCV_FALSE == (LusCanTrcvSpiDestData & TJA1145_CAN_CONTROL_PNCOK_1_BIT))
      {
        /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
        LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_PNCOK_1_BIT | TJA1145_CAN_CONTROL_CPNC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
      }
      LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);    
      if(CANTRCV_NOERR < LddCheckPnFlag){
        if(CANTRCV_PORERR < LddCheckPnFlag){
          #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
          (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
             CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
          #endif       
        }
        /* re-configuration */
        /* 0x63 CLEAR CW flag - Remote Wake up*/
        LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

        /* 0x61 CLEAR PO flag */
        LusCanTrcvSpiSrcData = (TJA1145_SYS_EVENT_STS_REG_W | TJA1145_SYS_EVENT_STS_PO_CLEAR_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

        /* #15680 - 0x64 CLEAR WPR, WPF flag */
        LusCanTrcvSpiSrcData = (TJA1145_TRCV_WAKE_PIN_EVENT_STS_REG_W | TJA1145_TRCV_WAKE_PIN_WPR_CLEAR_BIT | TJA1145_TRCV_WAKE_PIN_WPF_CLEAR_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
       
        /* 0x20 Read PNCOK bit*/
        LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
        
        if(CANTRCV_FALSE == (LusCanTrcvSpiDestData & TJA1145_CAN_CONTROL_PNCOK_1_BIT))
        {
          /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
          LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_PNCOK_1_BIT | TJA1145_CAN_CONTROL_CPNC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
          (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
        }
    
      }else{
        /* Do Nothing */
      }
    }
    #endif
       
    /* 0x01, Standby Write*/
    LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_W | TJA1145_SBC_MODE_STANDBY);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x01, Sleep Write */
    LusCanTrcvSpiSrcData = (TJA1145_SBC_MODE_REG_W | TJA1145_SBC_MODE_SLEEP);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    #endif
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif
  
  #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
  else if(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1145)
  {

    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    #if(STD_ON == CANTRCV_SPI_SUPPORT)

    /* 0x52 clear PWRON bit*/
    LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_INT_2_PWRON_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x51 CANINT,LWU,WKERR,FRAME_OVF flag clear*/
    LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)|(LusCanTrcvSpiDestData & TCAN1145_INT_1_CLEAR_FLAG_BITMASK));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x11 Clear Wake state pin */
    LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    
    
    #if (STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
    {
      /*0x47 SWCFG Set Selective Wake Configuration*/
      LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

      /*0x10 set SW_EN =1 Selective Wake Enable */
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
 
      LddCheckPnFlag = CanTrcv_CheckPnFlags(LucTransceiver);
      if(CANTRCV_NOERR < LddCheckPnFlag)
      {
        if(CANTRCV_PORERR < LddCheckPnFlag){
        #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
        (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
           CANTRCV_SETOPMODE_SID, CANTRCV_E_NO_TRCV_CONTROL);
        #endif
        }

        /* re-configuration */
        /*0x52 clear PWRON bit*/
        LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_INT_2_PWRON_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /* 0x51 CANINT,LWU,WKERR,FRAME_OVF flag clear*/
        LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)|(LusCanTrcvSpiDestData & TCAN1145_INT_1_CLEAR_FLAG_BITMASK));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        
        /* 0x11 Clear Wake state pin */
        LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /*0x47 SWCFG Set Selective Wake Configuration*/
        LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        /*0X10 SW_EN Set Selective wake enable*/
        LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
       (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      }
      else
      {
          /*Do nothing*/
      }
    }
  
    #endif
	 /* 0x10 Mode Control Sleep */
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_SLEEP);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

   
   /* 0x10 Mode Check */
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* Retry write SLEEP mode*/
    if(TCAN1145_MODE_CNTRL_SLEEP != (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_SLEEP))
    {
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_W | (LusCanTrcvSpiDestData & TCAN1145_MODE_CNTRL_BITMASKS ) | TCAN1145_MODE_CNTRL_SLEEP);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    }
    
	
    #endif
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  #endif

 else
 {
    /* #3479 */
    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
    /* add for CANTRCV_TLE6251G */
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    /* #2287 Delay  (CANTRCV_TLE6251G 8 ~ 25 ~ 50 us) */  
    CanTrcv_Delay(CANTRCV_WAIT_COUNT);
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_HIGH) || (RetVal1 != STD_LOW)){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_HIGH);
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
        /* #2287 Delay   */  
      CanTrcv_Delay(CANTRCV_WAIT_COUNT);    
    }
    /* Step 2/2 - Sleep */
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
    /* Invoke the Dio_WriteChannel to set the Standby pin to level-low */
    Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    RetVal = Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin1);
    RetVal1= Dio_ReadChannel(LpCanTrcvNetwork->ddSelectPin2);
    if((RetVal != STD_LOW) || (RetVal1 != STD_LOW)){
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-Low */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin1), (Dio_LevelType)STD_LOW);
      /* Invoke the Dio_WriteChannel to set the Standby pin to level-High */
      Dio_WriteChannel((LpCanTrcvNetwork->ddSelectPin2), (Dio_LevelType)STD_LOW);
    }   
    /* #3479 */
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
  }
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */     
  return LddCanTrcvMode;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CanTrcv_Delay                               **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : MCU depedent Code                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_Delay(volatile uint32 ticks)
{
 /*Prevent for MISRA C:2012 17.8 */
 volatile uint32 Lddticks = ticks;

  while(CANTRCV_ZERO != Lddticks)
  {
    /* Decrement the counter value */
    Lddticks--;
  }

}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_SetMode                              **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        : Set SBC mode                                          **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : Mode                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData, ArisuCan_GddSBCMode          **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      Det_ReportError, ArisuCan_SendSPI                     **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_SetMode
  (ArisuCan_SBCModeType Mode)
{
  Std_ReturnType LddReturnValue = (Std_ReturnType)E_NOT_OK;
  CanTrcv_ArisuCanType LddReadData;
  uint16 LusSpiSrcData = CANTRCV_ZERO;
  uint16 LusModeSts = CANTRCV_ZERO;

  #if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
  /* Check input mode validation */
  if ((Mode != ARISUCAN_SBCMODE_INIT)
    && (Mode != ARISUCAN_SBCMODE_NORMAL)
    && (Mode != ARISUCAN_SBCMODE_STOP)
    && (Mode != ARISUCAN_SBCMODE_SLEEP)
    && (Mode != ARISUCAN_SBCMODE_RESTART))
  {
  }
  else
  #endif
  {

    LusSpiSrcData = ((uint16)((uint16)Mode << (uint16)ARISUCAN_M_S_CTRL_MODE_POS) \
      | (uint16)ARISUCAN_M_S_CTRL_REG_W);

    LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

    if(LddReturnValue == E_OK)
    {

      LddReturnValue = CanTrcv_ArisuCan_ReadStatus(ARISUCAN_M_S_CTRL_REG_R, &LddReadData);
      
     if(LddReturnValue == E_OK)
     {
       LusModeSts = ((LddReadData & ARISUCAN_M_S_CTRL_MODE_MASK) >> CANTRCV_SIX);
       /* polyspace +1 MISRA-C3:10.5 [Not a defect:Justified] "No Impact of this rule violation" */
       ArisuCan_GddSBCModeSts = (ArisuCan_SBCModeType)(LusModeSts);
     }
    }
  }

  return LddReturnValue;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_RequestCanMode                       **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        : Send SPI data                                         **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : SpiSrcData                                            **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : SpiDestData                                           **
**                                                                            **
** Return parameter   : Std_ReturnType                                        **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      Spi_SetupEB, Dio_WriteChannel, Spi_SyncTransmit,      **
**                      Det_ReportError                                       **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_ArisuCan_RequestCanMode
  (CanTrcv_HwType LddCanTrcv, ArisuCan_SBCModeType LddMode)
{
  P2CONST(ArisuCan_CanConfigType, AUTOMATIC, CANTRCV_CONST)
    LpCanCfg = NULL_PTR;
  uint16 LusSpiSrcData;
  LpCanCfg = &CanTrcv_GaaArisuCan[LddMode];
  switch(LddCanTrcv)
  {
    case CANTRCV_ARISU_CAN0:
      LusSpiSrcData = LpCanCfg->ddArisu_Can0_mode;
      LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) | 
      (uint16)(ARISUCAN_BUS_CTRL_0_REG_W));
      CanTrcv_GddArisuCanSts.ddArisu_Can0_mode = LpCanCfg->ddArisu_Can0_mode;
      CanTrcv_GddArisuChannelUsed.ddArisu_Can0_mode = ARISUCAN_CONFIGURE;
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      break;
      
    case CANTRCV_ARISU_CAN1:
      /* #5903 */
      CanTrcv_GddArisuCanSts.ddArisu_Can1_mode = LpCanCfg->ddArisu_Can1_mode;
      CanTrcv_GddArisuChannelUsed.ddArisu_Can1_mode = ARISUCAN_CONFIGURE;
      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if(LpCanCfg->ddArisu_Can2_mode == CANTRCV_UNUSED)
      {
        LusSpiSrcData = (uint16)((uint16)(LpCanCfg->ddArisu_Can1_mode) \
        |(uint16)((uint16)(ARISU_CANTRCV_OFF) << (uint16)(ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS)));
        LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) \
        | (uint16)(ARISUCAN_BUS_CTRL_2_REG_W));
      }else
      {          
        LusSpiSrcData = (uint16)((uint16)(CanTrcv_GddArisuCanSts.ddArisu_Can1_mode) \
        |(uint16)((uint16)(CanTrcv_GddArisuCanSts.ddArisu_Can2_mode) << (uint16)(ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS)));
        LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) \
        | (uint16)(ARISUCAN_BUS_CTRL_2_REG_W));
      }
      /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      break;
    case CANTRCV_ARISU_CAN2:
      /* #5903 */
      CanTrcv_GddArisuCanSts.ddArisu_Can2_mode = LpCanCfg->ddArisu_Can2_mode;
      CanTrcv_GddArisuChannelUsed.ddArisu_Can2_mode = ARISUCAN_CONFIGURE;
      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if(LpCanCfg->ddArisu_Can1_mode == CANTRCV_UNUSED)
      {
        LusSpiSrcData = (uint16)((uint16)(ARISU_CANTRCV_OFF) \
        |(uint16)((uint16)(LpCanCfg->ddArisu_Can2_mode) << (uint16)(ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS)));
        LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) \
        | (uint16)(ARISUCAN_BUS_CTRL_2_REG_W));
      }else
      { 
        /* polyspace +3 DEFECT:UINT_CONV_OVFL [Not a defect:Justified] "Result will be within range. It handled by generator" */
        LusSpiSrcData = (uint16)((uint16)(CanTrcv_GddArisuCanSts.ddArisu_Can1_mode) \
        |(uint16)((uint16)(CanTrcv_GddArisuCanSts.ddArisu_Can2_mode) << (uint16)(ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS)));
        LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) \
        | (uint16)(ARISUCAN_BUS_CTRL_2_REG_W));
      }
      /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      break;
    
    case CANTRCV_ARISU_CAN3:  
      LusSpiSrcData = LpCanCfg->ddArisu_Can3_mode;
      LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) | 
      (uint16)(ARISUCAN_BUS_CTRL_3_REG_W));
      CanTrcv_GddArisuCanSts.ddArisu_Can3_mode = LpCanCfg->ddArisu_Can3_mode;      
      CanTrcv_GddArisuChannelUsed.ddArisu_Can3_mode = ARISUCAN_CONFIGURE;
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      break;
      
    default:
      /*Do Nothing*/
      break;
  }
  
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name      : ArisuCan_SendSPI                                      **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        : Send SPI data                                         **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : SpiSrcData                                            **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : SpiDestData                                           **
**                                                                            **
** Return parameter   : Std_ReturnType                                        **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      Spi_SetupEB, Dio_WriteChannel, Spi_SyncTransmit,      **
**                      Det_ReportError                                       **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace +3 MISRA-C3:8.13 [Not a defect:Justified] "Not a defect" */
FUNC(Std_ReturnType, CANTRCV_CODE) ArisuCan_SendSPI(
  P2CONST(uint16, AUTOMATIC, CANTRCV_CONST) SpiSrcData,
  P2VAR(uint16, AUTOMATIC, CANTRCV_VAR) SpiDestData)
{
  Std_ReturnType LddReturnValue = (Std_ReturnType)E_OK;
  uint8 ucArisuRetryCount;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  uint8 ucCanTrcvNm;

  (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();


  if(ArisuCan_GucReadFlag == ARISUCAN_OK)
  {    
    ArisuCan_GucReadFlag = ARISUCAN_BUSY;  

    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

    /* ARISU_SPI_MAX_COUNT is 5 */
    ucArisuRetryCount = (uint8)ARISU_SPI_MAX_COUNT;

    for(ucCanTrcvNm = 0 ; ucCanTrcvNm < CANTRCV_NUM_OF_NETWORKS ; ucCanTrcvNm++)
    {
      LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[ucCanTrcvNm];
      /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if((LpCanTrcvNetwork->ddCanTrcvHwDev <= ARISUCAN_END_OFFSET)
      && (LpCanTrcvNetwork->ddCanTrcvHwDev >= ARISUCAN_START_OFFSET))
      {
        /* MISRA-C 13.6 */
        break;
      }
    }

    /* Retry to write arisu-can by spi */
    do
    {
      LddReturnValue = Spi_SetupEB(LpCanTrcvNetwork->ddSelectPin1,
        (const Spi_DataType*) SpiSrcData, (Spi_DataType*) SpiDestData, (Spi_NumberOfDataType)((Spi_NumberOfDataType)(~CanTrcv_GddSpiType)&(Spi_NumberOfDataType)CANTRCV_THREE));

      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if (LddReturnValue == (Std_ReturnType)E_OK)
      {

        if(LpCanTrcvNetwork->ddSelectPin3 != CANTRCV_UNUSED)
        {
          (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

          Dio_WriteChannel(LpCanTrcvNetwork->ddSelectPin3, (Dio_LevelType)STD_LOW);

          (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
        }
        
        LddReturnValue = Spi_SyncTransmit(LpCanTrcvNetwork->ddSelectPin2);

        if (LddReturnValue == (Std_ReturnType)E_OK)
        {
          ucArisuRetryCount = CANTRCV_ZERO;
        }else{
          if(ucArisuRetryCount != CANTRCV_ZERO)
          {
            ucArisuRetryCount--;
          }
        }
        
        if(LpCanTrcvNetwork->ddSelectPin3 != CANTRCV_UNUSED)
        {
          (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

          Dio_WriteChannel(LpCanTrcvNetwork->ddSelectPin3, (Dio_LevelType)STD_HIGH);

          (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
        }

      }else{
        if(ucArisuRetryCount != CANTRCV_ZERO)
        {
          ucArisuRetryCount--;
        }
      }
     /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */ 
    }while(ucArisuRetryCount != CANTRCV_ZERO);

    (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

    ArisuCan_GucReadFlag = ARISUCAN_OK;

    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  }else{
    (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  
  return LddReturnValue;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_GetMode                              **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        : Get SBC mode                                          **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : Mode                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : pMode                                                 **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData, ArisuCan_GddSBCMode          **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      Det_ReportError, ArisuCan_SendSPI                     **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_GetMode
   (ArisuCan_SBCModeType* pMode)
{
  /* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
  Std_ReturnType LddReturnValue = (Std_ReturnType)E_OK;

  uint16 LusSpiSrcData = ARISUCAN_M_S_CTRL_REG_R;
  uint16 LusModeStatus = CANTRCV_ZERO;


  #if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
  if (pMode == NULL_PTR)
  {
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  {
    LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData,
      &ArisuCan_GddSpiDestData);

    #if (CANTRCV_DEV_ERROR_DETECT == STD_ON)
    if (LddReturnValue != (Std_ReturnType)E_OK)
    {

    }
    else
    #endif
    {
      (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
      LusModeStatus = ((ArisuCan_GddSpiDestData & (uint16)ARISUCAN_M_S_CTRL_MODE_1_BIT)
        | (ArisuCan_GddSpiDestData & (uint16)ARISUCAN_M_S_CTRL_MODE_0_BIT))
        >> ARISUCAN_M_S_CTRL_MODE_POS;
      /* polyspace +1 MISRA-C3:10.5 [Not a defect:Justified] "No Impact of this rule violation" */
      ArisuCan_GddSBCMode = (ArisuCan_SBCModeType)LusModeStatus;

      {
        /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
        *pMode = (ArisuCan_SBCModeType)ArisuCan_GddSBCMode;
        /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
        if(NULL_PTR == pMode)
        {
          /* Set the return value to E_NOT_OK */
          LddReturnValue = (Std_ReturnType)E_NOT_OK;
        }
      }
      (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
    }
  }
  return LddReturnValue;
  /* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_CheckCanMode                         **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        : Check Can mode                                        **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : LddCanTrcv, LddMode                                   **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : pMode                                                 **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData, ArisuCan_GddSBCMode          **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      Det_ReportError, ArisuCan_SendSPI                     **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin MISRA-C3:10.5 [Not a defect:Justified] "No Impact of this rule violation" */
static FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_ArisuCan_CheckCanMode
 (CanTrcv_HwType LddCanTrcv, ArisuCan_SBCModeType LddMode)
{
  uint16 LusSpiSrcData;
  CanTrcv_TrcvModeType LddCanTrcvMode;
  ArisuCan_CANModeType LddCanMode;
  uint16 LusCanModeSts;
  P2CONST(ArisuCan_CanConfigType, AUTOMATIC, CANTRCV_CONST) LpCanCfg = NULL_PTR;
  
  
  if(LddMode == ARISUCAN_SBCMODE_NORMAL)
  {
    LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;
  }else{
    LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
  }
  
  LpCanCfg = &CanTrcv_GaaArisuCan[LddMode];
  
  #if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Check whether CanTrcv Id is out of range */
  if((CANTRCV_ARISU_CAN0 > LddCanTrcv) || (CANTRCV_ARISU_CAN3 < LddCanTrcv))
  {
    (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_SETOPMODE_SID, CANTRCV_E_INVALID_TRANSCEIVER);
  }
  #endif
   
  switch(LddCanTrcv)
  {
    case CANTRCV_ARISU_CAN0:
      LusSpiSrcData = (uint16)(ARISUCAN_BUS_CTRL_0_REG_R);
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      LusCanModeSts = (uint16)((ArisuCan_GddSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT);
      LusCanModeSts = (((uint16)LusCanModeSts & ARISUCAN_CAN_0_1_3_MASK));
      LddCanMode = (ArisuCan_CANModeType)LusCanModeSts;
      if(LddCanMode == (ArisuCan_CANModeType)(LpCanCfg->ddArisu_Can0_mode))
      {
        if(LddMode == ARISUCAN_SBCMODE_NORMAL)
        {
          LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
        }else{
          LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;   
        }        
      }      
      break;
      
    case CANTRCV_ARISU_CAN1:
      LusSpiSrcData = (uint16)(ARISUCAN_BUS_CTRL_2_REG_R);
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      LusCanModeSts = (uint16)((ArisuCan_GddSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT);
      LusCanModeSts = ((LusCanModeSts & ARISUCAN_CAN_0_1_3_MASK));
      LddCanMode = (ArisuCan_CANModeType)LusCanModeSts;
      if(LddCanMode == (ArisuCan_CANModeType)(LpCanCfg->ddArisu_Can1_mode))
      {
        if(LddMode == ARISUCAN_SBCMODE_NORMAL)
        {
          LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
        }else{
          LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;   
        } 
      } 
      break;
      
    case CANTRCV_ARISU_CAN2:
      LusSpiSrcData = (uint16)(ARISUCAN_BUS_CTRL_2_REG_R);
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      LusCanModeSts = (uint16)((ArisuCan_GddSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT);
      LusCanModeSts = ((LusCanModeSts & (uint16)ARISUCAN_CAN_2_MASK) >> CANTRCV_THREE);
      LddCanMode = (ArisuCan_CANModeType)LusCanModeSts;
      /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if(LddCanMode == (ArisuCan_CANModeType)(LpCanCfg->ddArisu_Can2_mode))
      {
        if(LddMode == ARISUCAN_SBCMODE_NORMAL)
        {
          LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
        }else{
          LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;   
        } 
      } 
      break;
      
    case CANTRCV_ARISU_CAN3:  
      LusSpiSrcData = (uint16)(ARISUCAN_BUS_CTRL_3_REG_R);    
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData );
      LusCanModeSts = (uint16)((ArisuCan_GddSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT);
      LusCanModeSts = ((LusCanModeSts & (uint16)ARISUCAN_CAN_0_1_3_MASK));
      LddCanMode = (ArisuCan_CANModeType)LusCanModeSts;
      /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if(LddCanMode == (ArisuCan_CANModeType)(LpCanCfg->ddArisu_Can3_mode))
      {
        if(LddMode == ARISUCAN_SBCMODE_NORMAL)
        {
          LddCanTrcvMode = CANTRCV_TRCVMODE_NORMAL;
        }else{
          LddCanTrcvMode = CANTRCV_TRCVMODE_STANDBY;   
        } 
      } 
      break;
      
    default:
      /*Do Nothing*/
      break;
  }
  
  return LddCanTrcvMode;
}
/* polyspace-end MISRA-C3:10.5 [Not a defect:Justified] "No Impact of this rule violation" */
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_PowerDownMode                        **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        :                                                       **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : Mode                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : pMode                                                 **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData, ArisuCan_GddSBCMode          **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      CanTrcv_ArisuCan_GetMode, CanTrcv_ArisuCan_SetMode    **
**                      CanTrcv_ArisuCan_RequestCanMode                       **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_PowerDownMode(void)
{

  P2CONST(ArisuCan_CanConfigType, AUTOMATIC, CANTRCV_CONST)
    LpCanPowerDownModeCfg = NULL_PTR;
  Std_ReturnType LddResult = (Std_ReturnType)E_OK;
  Std_ReturnType LddReturnValue = (Std_ReturnType)E_OK;
  uint16 LusSpiSrcData;
  uint16 LusSpiSrcData1;
  (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
  LpCanPowerDownModeCfg = &CanTrcv_GaaArisuCan[ARISUCAN_SBCMODE_SLEEP];

  
  /*SBC Mode Change to change ArisuCan CanTrcv Mode */  
  /* MISRA 16.10 */
  (void)CanTrcv_ArisuCan_SetMode(ARISUCAN_SBCMODE_NORMAL);

  /* ARISU-CAN0 */
  /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */ 
  if(LpCanPowerDownModeCfg->ddArisu_Can0_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData = LpCanPowerDownModeCfg->ddArisu_Can0_mode;
  }  
  LusSpiSrcData =  (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) | 
    (uint16)(ARISUCAN_BUS_CTRL_0_REG_W));
  LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
  if(LddReturnValue != (Std_ReturnType)E_OK)
  {
    LddResult = (Std_ReturnType)E_NOT_OK;
  }
  
  /* ARISU-CAN1 & ARISU-CAN2 */
  if(LpCanPowerDownModeCfg->ddArisu_Can1_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData = LpCanPowerDownModeCfg->ddArisu_Can1_mode;
  }

  if(LpCanPowerDownModeCfg->ddArisu_Can2_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData1 = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData1 = LpCanPowerDownModeCfg->ddArisu_Can2_mode;
  }  
  LusSpiSrcData = (uint16)(LusSpiSrcData |
  (uint16)((LusSpiSrcData1) << (uint16)(ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS)));
  LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_BUS_CTRL_2_REG_W));
  /* #5750 */
  LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  if(LddReturnValue != (Std_ReturnType)E_OK)
  {
    LddResult = (Std_ReturnType)E_NOT_OK;
  }  
  
  /* ARISU-CAN3 */
  if(LpCanPowerDownModeCfg->ddArisu_Can3_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData = LpCanPowerDownModeCfg->ddArisu_Can3_mode;
  }
  /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */ 
  LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) | 
    (uint16)(ARISUCAN_BUS_CTRL_3_REG_W));
  LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  if(LddReturnValue != (Std_ReturnType)E_OK)
  {
    LddResult = (Std_ReturnType)E_NOT_OK;
  }
 
  /*ARISU-CAN Wake Up Clear */
  LusSpiSrcData = ARISUCAN_WK_STAT_0_REG_W;
  LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  if(LddReturnValue != (Std_ReturnType)E_OK)
  {
    LddResult = (Std_ReturnType)E_NOT_OK;
  }

  /*ARISU-CAN Wake Up Clear */
  LusSpiSrcData = ARISUCAN_WK_STAT_2_REG_W;
  LddReturnValue = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  if(LddReturnValue != (Std_ReturnType)E_OK)
  {
    LddResult = (Std_ReturnType)E_NOT_OK;
  }

  
  /*SBC Mode Change a SBCMode for PowerDown */     
  LddReturnValue = CanTrcv_ArisuCan_SetMode(ARISUCAN_SBCMODE_SLEEP);

  if(LddReturnValue != (Std_ReturnType)E_OK)
  {
    LddResult = (Std_ReturnType)E_NOT_OK;
  }

  (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  return LddResult;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_ChangeStopMode                       **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        :                                                       **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : pMode                                                 **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSBCModeSts                                **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      CanTrcv_ArisuCan_ReadStatus, CanTrcv_ArisuCan_SetMode **
**                                                                            **
*******************************************************************************/
/* add logic code by #8357 */
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace +2 MISRA-C3:8.4 [Not a defect: Justified] "Function external linkage 
will be generated by RTE" */
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_ChangeStopMode(void)
{

  CanTrcv_ArisuCanType LddReadData;
  uint16 LusSpiSrcData;
  ArisuCan_CanConfigType LddCanTrcvConfigure;
  P2CONST(ArisuCan_CanConfigType, AUTOMATIC, CANTRCV_CONST) 
  LpCanCfgInit = NULL_PTR;
  P2CONST(ArisuCan_CanConfigType, AUTOMATIC, CANTRCV_CONST) 
  LpCanCfgStop = NULL_PTR;
  Std_ReturnType LddResult = (Std_ReturnType)E_NOT_OK;

  LpCanCfgInit = &CanTrcv_GaaArisuCan[ARISUCAN_SBCMODE_INIT];
  LpCanCfgStop = &CanTrcv_GaaArisuCan[ARISUCAN_SBCMODE_STOP];

  (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
  /* Check wheater Configure or UnConfigure */
  if(CanTrcv_GddArisuChannelUsed.ddArisu_Can0_mode == ARISUCAN_CONFIGURE)
  {
    LddCanTrcvConfigure.ddArisu_Can0_mode = LpCanCfgStop->ddArisu_Can0_mode;
  }else{
    LddCanTrcvConfigure.ddArisu_Can0_mode = LpCanCfgInit->ddArisu_Can0_mode;
  }

  if(CanTrcv_GddArisuChannelUsed.ddArisu_Can1_mode == ARISUCAN_CONFIGURE)
  {
    LddCanTrcvConfigure.ddArisu_Can1_mode = LpCanCfgStop->ddArisu_Can1_mode;
  }else{
    LddCanTrcvConfigure.ddArisu_Can1_mode = LpCanCfgInit->ddArisu_Can1_mode;
  }

  if(CanTrcv_GddArisuChannelUsed.ddArisu_Can2_mode == ARISUCAN_CONFIGURE)
  {
    LddCanTrcvConfigure.ddArisu_Can2_mode = LpCanCfgStop->ddArisu_Can2_mode;
  }else{
    LddCanTrcvConfigure.ddArisu_Can2_mode = LpCanCfgInit->ddArisu_Can2_mode;
  }

  if(CanTrcv_GddArisuChannelUsed.ddArisu_Can3_mode == ARISUCAN_CONFIGURE)
  {
    LddCanTrcvConfigure.ddArisu_Can3_mode = LpCanCfgStop->ddArisu_Can3_mode;
  }else{
    LddCanTrcvConfigure.ddArisu_Can3_mode = LpCanCfgInit->ddArisu_Can3_mode;
  }
  
  /* Check ready to go SBC MODE STOP */ 
  if((CanTrcv_GddArisuCanSts.ddArisu_Can0_mode != LddCanTrcvConfigure.ddArisu_Can0_mode)
  ||(CanTrcv_GddArisuCanSts.ddArisu_Can1_mode != LddCanTrcvConfigure.ddArisu_Can1_mode)
  ||(CanTrcv_GddArisuCanSts.ddArisu_Can2_mode != LddCanTrcvConfigure.ddArisu_Can2_mode)
  ||(CanTrcv_GddArisuCanSts.ddArisu_Can3_mode != LddCanTrcvConfigure.ddArisu_Can3_mode))
  {
    LddResult = (Std_ReturnType)ARISUCAN_E_NOT_OK_CANMODE;
    
  }else{ 
  
    (void)CanTrcv_ArisuCan_ReadStatus(ARISUCAN_M_S_CTRL_REG_R, &LddReadData);
    
    if(((LddReadData & ARISUCAN_M_S_CTRL_MODE_MASK) >> ARISUCAN_M_S_CTRL_MASK) == (CanTrcv_ArisuCanType)ARISUCAN_SBCMODE_NORMAL)
    {
      /* VBSENSE_DISABLE : Bit 1 */
      LusSpiSrcData = (uint16)((uint16)ARISUCAN_W_K_CTRL_0_VBSENSE01_CFG_BIT & ARISUCAN_W_K_CTRL_0_VBSENSE_DISABLE_BIT);
      LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
      (uint16)(ARISUCAN_WK_CTRL_0_REG_W));
      (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
    }
    
    /*ARISU-CAN Wake Up Clear */
    LusSpiSrcData = ARISUCAN_WK_STAT_0_REG_W;
    (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

    /*ARISU-CAN Wake Up Clear */
    LusSpiSrcData = ARISUCAN_WK_STAT_2_REG_W;
    (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
    
    LddResult = CanTrcv_ArisuCan_SetMode(ARISUCAN_SBCMODE_STOP);          
    
    if(LddResult == E_OK)
    {
      if(ArisuCan_GddSBCModeSts != (ArisuCan_SBCModeType)(ARISUCAN_SBCMODE_STOP))
      {
      
        LddResult = (Std_ReturnType)ARISUCAN_E_NOT_OK_SBCSTOP;
        
      }
    } 
  }
  
  /* delete logic code by #9199 */

  (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  return LddResult;

}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_GetInternalSBCMode                   **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        :                                                       **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : Mode                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : pMode                                                 **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData, ArisuCan_GddSBCMode          **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      CanTrcv_ArisuCan_GetMode, CanTrcv_ArisuCan_SetMode    **
**                      CanTrcv_ArisuCan_RequestCanMode                       **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(ArisuCan_SBCModeType, CANTRCV_CODE)CanTrcv_ArisuCan_GetInternalSBCMode(void)
{
  return ArisuCan_GddSBCModeSts;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_ReadStatus                           **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        :                                                       **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : Mode                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : pMode                                                 **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      ArisuCan_SendSPI                                      **
*******************************************************************************/
/* #5277 */
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace <MISRA-C3:8.7:Not a defect:Justified> Calling from RTE */
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_ReadStatus(
  CanTrcv_ArisuCanType Address,
  P2VAR(CanTrcv_ArisuCanType, AUTOMATIC, CANTRCV_VAR) Data)
{
  CanTrcv_ArisuCanType Ldd_Address = Address;
  /* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
  Std_ReturnType LddReturnValue = (Std_ReturnType)E_NOT_OK;
  uint16 LusSpiDestData = CANTRCV_ZERO;
  /* #6362 */
  (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

  if(NULL_PTR == Data)
  {
    /* Set the return value to E_NOT_OK */
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }else{
    LddReturnValue = ArisuCan_SendSPI((P2CONST(uint16, AUTOMATIC, CANTRCV_CONST))&Ldd_Address, (P2VAR(uint16, AUTOMATIC, CANTRCV_VAR))&LusSpiDestData);
    *Data = (CanTrcv_ArisuCanType)((LusSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT);
  }

  (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  return LddReturnValue;
  

  
  /* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_VbsenseEnable                        **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        :                                                       **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : Std_ReturnType                                        **
**                                                                            **
** Preconditions      : CANTRCV_ARISUCAN_SUPPORT == STD_ON                    **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData                               **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      CanTrcv_ArisuCan_ReadStatus, ArisuCan_SendSPI         **
**                                                                            **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace +2 MISRA-C3:8.4 [Not a defect: Justified] "Function external linkage 
will be generated by RTE" */
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_VbsenseEnable(void)
{

  CanTrcv_ArisuCanType LddReadData;
  uint16 LusSpiSrcData;
  Std_ReturnType LddResult = (Std_ReturnType)E_NOT_OK;

  (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

  /* VBSENSE_Enable : Bit 1 */
  LusSpiSrcData = (uint16)((uint16)ARISUCAN_W_K_CTRL_0_VBSENSE01_CFG_BIT | ARISUCAN_W_K_CTRL_0_VBSENSE_EN_BIT);
  LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_WK_CTRL_0_REG_W));
  LddResult = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
  if(LddResult == E_OK)
  {
    (void)CanTrcv_ArisuCan_ReadStatus(ARISUCAN_WK_CTRL_0_REG_R, &LddReadData);
    if((CanTrcv_ArisuCanType)CANTRCV_ZERO == (LddReadData & ARISUCAN_W_K_CTRL_0_VBSENSE_EN_BIT))
    {
      LddResult = (Std_ReturnType)E_NOT_OK;
    }
  }
  (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  return LddResult;

}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_ArisuCan_VbsenseDisable                       **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        :                                                       **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : Std_ReturnType                                        **
**                                                                            **
** Preconditions      : CANTRCV_ARISUCAN_SUPPORT == STD_ON                    **
**                                                                            **
** Remarks            : Global Variable(s) :                                  **
**                      ArisuCan_GddSpiDestData                               **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      CanTrcv_ArisuCan_ReadStatus, ArisuCan_SendSPI         **
**                                                                            **
*******************************************************************************/
#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace +2 MISRA-C3:8.4 [Not a defect: Justified] "Function external linkage 
will be generated by RTE" */
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_VbsenseDisable(void)
{

  CanTrcv_ArisuCanType LddReadData;
  uint16 LusSpiSrcData;
  Std_ReturnType LddResult = (Std_ReturnType)E_NOT_OK;

  (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();

  /* VBSENSE_Disable : Bit 0 */
  LusSpiSrcData = (uint16)((uint16)ARISUCAN_W_K_CTRL_0_VBSENSE01_CFG_BIT & ARISUCAN_W_K_CTRL_0_VBSENSE_DISABLE_BIT);
  LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_WK_CTRL_0_REG_W));
  LddResult = ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
  if(LddResult == E_OK)
  {
    (void)CanTrcv_ArisuCan_ReadStatus(ARISUCAN_WK_CTRL_0_REG_R, &LddReadData);
    if((CanTrcv_ArisuCanType)CANTRCV_ONE == (LddReadData & ARISUCAN_W_K_CTRL_0_VBSENSE_EN_BIT))
    {
      LddResult = (Std_ReturnType)E_NOT_OK;
    }
  }
  (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();

  return LddResult;

}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : CanTrcv_SendSPI                                       **
**                                                                            **
** Service ID         : N/A                                                   **
**                                                                            **
** Description        : Send SPI data                                         **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : SpiSrcData                                            **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : SpiDestData                                           **
**                                                                            **
** Return parameter   : Std_ReturnType                                        **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
**                      Spi_SetupEB, Dio_WriteChannel, Spi_SyncTransmit,      **
*******************************************************************************/
#if(STD_ON == CANTRCV_SPI_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
/* polyspace +4 MISRA-C3:8.13 [Not a defect:Justified] "Not a defect" */
FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_SendSPI(
  uint8 LucTransceiver,
  P2CONST(uint16, AUTOMATIC, CANTRCV_CONST) SpiSrcData,
  P2VAR(uint16, AUTOMATIC, CANTRCV_VAR) SpiDestData)
{
  Std_ReturnType LddReturnValue = (Std_ReturnType)E_OK;
  uint8 ucCanTrcvRetryCount;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
    
  /* ARISU_SPI_MAX_COUNT is 5 */
  ucCanTrcvRetryCount = (uint8)0x05;
  
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];


  do
  {
    #if(STD_ON == CANTRCV_MCAL_AR42_SUPPORT)
    /* polyspace +2 MISRA-C3:10.3 [Not a defect:Justified] "Not a defect" */
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Array index in range" */
    LddReturnValue = Spi_SetupEB(LpCanTrcvNetwork->ddSelectPin1,
      (const Spi_DataType*) SpiSrcData, (Spi_DataType*) SpiDestData, 1);
    #else
    LddReturnValue = Spi_SetupEB(LpCanTrcvNetwork->ddSelectPin1,
      (const Spi_DataType*) SpiSrcData, (Spi_DataType*) SpiDestData, (Spi_NumberOfDataType)((Spi_NumberOfDataType)(~CanTrcv_GddSpiType)&(Spi_NumberOfDataType)CANTRCV_THREE));

    #endif
    /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
    if (LddReturnValue == (Std_ReturnType)E_OK)
    {

      if(LpCanTrcvNetwork->ddSelectPin3 != CANTRCV_UNUSED)
      {
        (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
        
        Dio_WriteChannel(LpCanTrcvNetwork->ddSelectPin3, (Dio_LevelType)STD_LOW);

        (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
      }
      /* polyspace +1 MISRA-C3:10.3 [Not a defect:Justified] "Not a defect" */
      LddReturnValue = Spi_SyncTransmit(LpCanTrcvNetwork->ddSelectPin2);

      if (LddReturnValue == (Std_ReturnType)E_OK)
      {
        ucCanTrcvRetryCount = CANTRCV_ZERO;
      }else{
        if(ucCanTrcvRetryCount != CANTRCV_ZERO)
        {
          ucCanTrcvRetryCount--;
        }
      }
      
      if(LpCanTrcvNetwork->ddSelectPin3 != CANTRCV_UNUSED)
      {
        (void)SchM_Enter_CanTrcv_INTERRUPT_PROTECTION_AREA();
        
        Dio_WriteChannel(LpCanTrcvNetwork->ddSelectPin3, (Dio_LevelType)STD_HIGH);

        (void)SchM_Exit_CanTrcv_INTERRUPT_PROTECTION_AREA();
      }

    }else{
      if(ucCanTrcvRetryCount != CANTRCV_ZERO)
      {
        ucCanTrcvRetryCount--;
      }
    }
    /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
  }while(ucCanTrcvRetryCount != CANTRCV_ZERO);

  if(E_NOT_OK == LddReturnValue){
#if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
  (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
  CANTRCV_SETOPMODE_SID, CANTRCV_E_SPI_FAILED);
#endif
  }else{
   /* Do Nothing */
  }
  
  return LddReturnValue;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* polyspace:end<RTE:UNR:Not a defect : No Action Planned> Because condition check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
