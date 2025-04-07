/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_Init.c                                                **
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
 ** 2.10.1    19-Apr-2024   Kim Min Uk     #46132                              **
 ** 2.10.0    11-Nov-2023   Song Yu Bin    #42559                              **
 ** 2.9.5     24-Aug-2022   Kim Min Uk     #37209                              **
 ** 2.9.4     08-Aug-2022   Kim Min Uk     #36455, #36293, #36981              **
 ** 2.9.1     30-Dec-2021   Lim Jong Sun   #33364                              **
 ** 2.9.0     06-Oct-2021   Lim Jong Sun   #32350                              **
 ** 2.8.0     26-Jul-2021   DuyNGB         #29232, #30945, #31384              **
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              **
 ** 2.6.1     30-Oct-2019   Lim Jong sun   #15680                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878, #13347, #14410, #14551      **
 **                                        #14538                              **
 ** 2.5.6     11-Aug-2017   Lim Jong Sun   #9477                               **
 ** 2.5.2     27-Apr-2017   Lim Jong Sun   #8371                               **
 ** 2.5.1     23-Mar-2017   Lim Jong Sun   #7882                               **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.1     01-Nov-2016   Lim Jong Sun   #6459, #6546                        **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.2     31-Aug-2016   Lim Jong Sun   #5748                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #4805                        **
 ** 2.2.5     22-Dec-2015   Lim Jong Sun   #3453, #2786, #3551                 **
 ** 2.0.3     29-Apr-2015   Lim Jong Sun   #2524                               **
 ** 2.0.2     10-Mar-2015   Lim Jong Sun   #2287                               **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

/*******************************************************************************
 **                      Include Section                                       **
 *******************************************************************************/
#include "CanTrcv_Init.h"       /* CAN Transceiver Driver Init header file */
#include "CanTrcv_ModeCtrl.h"   /* CAN Transceiver Mode Control header file */
#include "CanTrcv.h"
#include "Compiler.h"
#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
#include "Det.h"                /* DET module header file */
#endif
/*******************************************************************************
 **                      Version Information                                   **
 *******************************************************************************/
/* AUTOSAR specification version information */
#define CANTRCV_INIT_AR_RELEASE_MAJOR_VERSION    4
#define CANTRCV_INIT_AR_RELEASE_MINOR_VERSION    0
#define CANTRCV_INIT_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANTRCV_INIT_SW_MAJOR_VERSION    2
#define CANTRCV_INIT_SW_MINOR_VERSION    10

/*******************************************************************************
 **                      Version Check                                         **
 *******************************************************************************/

#if (CANTRCV_INIT_AR_RELEASE_MAJOR_VERSION != \
  CANTRCV_INIT_C_AR_RELEASE_MAJOR_VERSION)
#error "CanTrcv_Init.c : Mismatch in Specification Major Version"
#endif
#if (CANTRCV_INIT_AR_RELEASE_MINOR_VERSION != \
  CANTRCV_INIT_C_AR_RELEASE_MINOR_VERSION)
#error "CanTrcv_Init.c : Mismatch in Specification Minor Version"
#endif
#if (CANTRCV_INIT_AR_RELEASE_REVISION_VERSION != \
  CANTRCV_INIT_C_AR_RELEASE_REVISION_VERSION)
#error "CanTrcv_Init.c : Mismatch in Specification Revision Version"
#endif
#if (CANTRCV_INIT_SW_MAJOR_VERSION != CANTRCV_INIT_C_SW_MAJOR_VERSION)
#error "CanTrcv_Init.c : Mismatch in Software Major Version"
#endif
#if (CANTRCV_INIT_SW_MINOR_VERSION != CANTRCV_INIT_C_SW_MINOR_VERSION)
#error "CanTrcv_Init.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/

/*******************************************************************************
 **                      Function Definitions                                 **
 *******************************************************************************/
/* polyspace:begin<RTE:UNR:Not a defect : No Action Planned> Because condition check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
#if(STD_ON == CANTRCV_SPI_SUPPORT)
#if (STD_ON ==CANTRCV_TJA1145_PRESENT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_TJA1145_Init(uint8 LucCanTrcvChannel);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON ==CANTRCV_TCAN1145_PRESENT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_TCAN1145_Init(uint8 LucCanTrcvChannel);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"


#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_TCAN1145_CanBaudRateConfig(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif



#if((STD_ON == CANTRCV_SPI_SUPPORT) && (STD_ON == CANTRCV_PN_SUPPORTED))

#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_ClearPORFlag(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanTrcv_PnErrType, CANTRCV_CODE) CanTrcv_CheckSYSEFlag(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_ClearSYSEFlag(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanTrcv_PnErrType, CANTRCV_CODE) CanTrcv_CheckPORFlag(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#endif



/*******************************************************************************
 ** Function Name        : CANTRCV_INIT_MACRO                                  **
 **                                                                            **
 ** Service ID           : 0x00                                                **
 **                                                                            **
 ** Description          : This service sets the CAN Transceiver Driver mode   **
 **                        to either Normal or StandBy or Sleep Mode based on  **
 **              the configured initialization state                           **
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
 ** Remarks              : Global Variable(s)  : CanTrcv_GblInitStatus         **
 **                                              CanTrcv_GaaByteArray          **
 **                        Function(s) invoked : Det_ReportError,              **
 **                                              CanTrcv_NormalMode,           **
 **                                              CanTrcv_StadbyMode            **
 **                                              CanTrcv_SleepMode             **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"

FUNC(void,CANTRCV_CODE) CANTRCV_INIT_MACRO(P2CONST(CanTrcv_ConfigType,
    AUTOMATIC, CANTRCV_CONST)ConfigPtr)

{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  uint8 LucCanTrcvChannel;
  CanTrcv_TrcvModeType LddInitOpMode;

  #if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
  P2CONST(ArisuCan_CanConfigType, AUTOMATIC, CANTRCV_CONST) LpCanCfg = NULL_PTR;
  uint16 LusSpiSrcData;
  uint16 LusSpiSrcData1;
  #endif

  #if(STD_ON == CANTRCV_SPI_SUPPORT)
  CanTrcv_PnErrType LddCheckPnFlag = CANTRCV_NOERR;
  #if((CANTRCV_TJA1145_PRESENT == STD_ON) || (CANTRCV_TCAN1145_PRESENT ==STD_ON))
  CanTrcv_UndervolType LddCheckUndervol = CANTRCV_NOUNDERVOL;
  #endif
  #endif

  /* Set the network value to zero */
  LucCanTrcvChannel = CANTRCV_ZERO;
  /* Get the pointer to the structure of first network */
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[CANTRCV_ZERO];

  #if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
  LpCanCfg = &CanTrcv_GaaArisuCan[ARISUCAN_SBCMODE_INIT];
  #endif

  CANTRCV_UNUSED_PTR(ConfigPtr);
  /* Loop for initializing all the configured CAN Transceiver Driver networks */
  /* #7882 do ~ while --> while */
  while(CANTRCV_NUM_OF_NETWORKS > LucCanTrcvChannel)
  {
    /* Check if channel is used or not*/
    /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Array index in range" */
    #if (CANTRCV_ALLCHANNEL_USED == STD_OFF)
    if(CANTRCV_TRUE == LpCanTrcvNetwork->blChannelUsed)
    #endif
    {
      #if(STD_ON == CANTRCV_ARISUCAN_SUPPORT)
      /* ARISU-CAN Device is not needed to set init mode */
      /* WDG Driver do that by calling SPI API */
      if((LpCanTrcvNetwork->ddCanTrcvHwDev != CANTRCV_ARISU_CAN0)
      &&(LpCanTrcvNetwork->ddCanTrcvHwDev != CANTRCV_ARISU_CAN1)
      &&(LpCanTrcvNetwork->ddCanTrcvHwDev != CANTRCV_ARISU_CAN2)
      &&(LpCanTrcvNetwork->ddCanTrcvHwDev != CANTRCV_ARISU_CAN3))
      #endif
      { 
	      #if((CANTRCV_TJA1145_PRESENT ==STD_ON) ||(CANTRCV_TCAN1145_PRESENT ==STD_ON))
        switch(LpCanTrcvNetwork->ddCanTrcvHwDev){
          #if(CANTRCV_TJA1145_PRESENT == STD_ON)
          case CANTRCV_TJA1145:
            LddCheckUndervol = CanTrcv_CheckUndervoltage(LucCanTrcvChannel);
            if(CANTRCV_NOUNDERVOL < LddCheckUndervol)
            {
              #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
                (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                  CANTRCV_INIT_SID, CANTRCV_E_TRCV_UNDERVOLTAGE);
              #endif
            }

            (void)CanTrcv_TJA1145_Init(LucCanTrcvChannel);

            #if(STD_ON == CANTRCV_PN_SUPPORTED)
            if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
            {
              LddCheckPnFlag = CanTrcv_CheckPnFlags(LucCanTrcvChannel);
            
              if(CANTRCV_NOERR < LddCheckPnFlag){
                if(CANTRCV_PORERR < LddCheckPnFlag){
                  #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
                  (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                    CANTRCV_INIT_SID, CANTRCV_E_NO_TRCV_CONTROL);
                  #endif              
                }            
                (void)CanTrcv_TJA1145_Init(LucCanTrcvChannel);            
              }else{
              /* Do Nothing */
              }
            }
            #endif
            break;
          #endif

          #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
          case CANTRCV_TCAN1145:
            LddCheckUndervol = CanTrcv_CheckUndervoltage(LucCanTrcvChannel);

            if(CANTRCV_NOUNDERVOL < LddCheckUndervol)
            {
              #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
                (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                  CANTRCV_INIT_SID, CANTRCV_E_TRCV_UNDERVOLTAGE);
              #endif
            }

            (void)CanTrcv_TCAN1145_Init(LucCanTrcvChannel);

            #if(STD_ON == CANTRCV_PN_SUPPORTED)
            if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
            {
              LddCheckPnFlag = CanTrcv_CheckPnFlags(LucCanTrcvChannel);
            
              if(CANTRCV_NOERR < LddCheckPnFlag){
                if(CANTRCV_PORERR < LddCheckPnFlag){
                  #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
                  (void) Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
                      CANTRCV_INIT_SID, CANTRCV_E_NO_TRCV_CONTROL);
                  #endif              
                }            
                (void)CanTrcv_TCAN1145_Init(LucCanTrcvChannel);            
              }else{
                /* Do Nothing */
              }
            }
            #endif
            break;
          #endif
        
          default:
        #endif
            /* Copy the configured init state of Transceiver to Local variable */
            LddInitOpMode = LpCanTrcvNetwork->ddInitState;

            #if(CANTRCV_NORMALINIT_PRESENT == STD_ON)
            /* Check whether LddInitOpMode is Normal */
            if(CANTRCV_TRCVMODE_NORMAL == LddInitOpMode)
            {
              /* Invoke the function to set the CAN Transceiver Driver to Normal
              Mode*/
              (void)CanTrcv_NormalMode(LucCanTrcvChannel);
            }
            #endif
            #if(CANTRCV_STANDBYINIT_PRESENT == STD_ON)
            /* Check whether LddInitOpMode is standby */
            #if(CANTRCV_SLEEPINIT_PRESENT == STD_ON)
            if(CANTRCV_TRCVMODE_STANDBY == LddInitOpMode)
            #endif
            {
              /* Invoke the function to set the CAN Transceiver Driver to Standby
              Mode*/
              (void)CanTrcv_StandbyMode(LucCanTrcvChannel);
            }
            #endif
            #if(CANTRCV_SLEEPINIT_PRESENT == STD_ON)
            if(CANTRCV_TRCVMODE_SLEEP == LddInitOpMode)
            {
              (void)CanTrcv_SleepMode(LucCanTrcvChannel);
            } else {
              (void)CanTrcv_NormalMode(LucCanTrcvChannel);
            }
            #endif
            /* Set the Operational Mode of the requested network */
            CanTrcv_GaaByteArray[LucCanTrcvChannel] = LddInitOpMode;
			  #if((CANTRCV_TJA1145_PRESENT ==STD_ON) ||(CANTRCV_TCAN1145_PRESENT ==STD_ON))
            break;
        } 
		    #endif    
      }
    }
    
    #if(CANTRCV_ALLCHANNEL_USED == STD_OFF)
    /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */		
    #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
    else
    {
      /*Report a Development error If there is no/incorrect communication to
       the transceiver*/
      (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
      CANTRCV_INIT_SID, CANTRCV_E_NO_TRCV_CONTROL);
    }
    #endif
    #endif
  
    /* Increment the pointer for the network structure */
    LpCanTrcvNetwork++;
    /* Increment the network number */
    LucCanTrcvChannel++;
    
  }
  /* Check whether the network number is less than CANTRCV_NUM_OF_NETWORKS */

  /* ARISU-CAN Device's initial mode */
  #if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
  CanTrcv_GddArisuCanSts.ddArisu_Can0_mode = LpCanCfg->ddArisu_Can0_mode;
  CanTrcv_GddArisuCanSts.ddArisu_Can1_mode = LpCanCfg->ddArisu_Can1_mode;
  CanTrcv_GddArisuCanSts.ddArisu_Can2_mode = LpCanCfg->ddArisu_Can2_mode;
  CanTrcv_GddArisuCanSts.ddArisu_Can3_mode = LpCanCfg->ddArisu_Can3_mode;
  CanTrcv_GddArisuChannelUsed.ddArisu_Can0_mode = ARISUCAN_UNCONFIGURE;
  CanTrcv_GddArisuChannelUsed.ddArisu_Can1_mode = ARISUCAN_UNCONFIGURE;
  CanTrcv_GddArisuChannelUsed.ddArisu_Can2_mode = ARISUCAN_UNCONFIGURE;
  CanTrcv_GddArisuChannelUsed.ddArisu_Can3_mode = ARISUCAN_UNCONFIGURE;

  (void)CanTrcv_ArisuCan_SetMode(ARISUCAN_SBCMODE_NORMAL);

  ArisuCan_GucReadFlag = ARISUCAN_OK;
  /* Redmine #5748 */
  /* ARISU-CAN0 OFF */
  /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
  if(LpCanCfg->ddArisu_Can0_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData = (uint16)LpCanCfg->ddArisu_Can0_mode;
  }  
  LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_BUS_CTRL_0_REG_W));
  (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  /* ARISU-CAN1 & ARISU-CAN2 OFF */
  if(LpCanCfg->ddArisu_Can1_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData = (uint16)LpCanCfg->ddArisu_Can1_mode;
  }
  if(LpCanCfg->ddArisu_Can2_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData1 = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData1 = (uint16)LpCanCfg->ddArisu_Can2_mode;
  }  
  LusSpiSrcData = (uint16)(LusSpiSrcData |
  (uint16)((LusSpiSrcData1) << (uint16)(ARISUCAN_BUS_CTRL_CANTRCV_3_MODE_POS)));
  LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_BUS_CTRL_2_REG_W));
  (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  /*ARISU-CAN3 OFF */
  if(LpCanCfg->ddArisu_Can3_mode == CANTRCV_UNUSED)
  {
    LusSpiSrcData = (uint16)ARISU_CANTRCV_OFF;
  }else{
    LusSpiSrcData = (uint16)LpCanCfg->ddArisu_Can3_mode;
  }
  /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */  
  LusSpiSrcData = ((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_BUS_CTRL_3_REG_W));
  (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  /* VBENSE_CFG : 1, VBENSE_EN : 1 */
  LusSpiSrcData = (uint16)((uint16)ARISUCAN_W_K_CTRL_0_VBSENSE01_CFG_BIT | ARISUCAN_W_K_CTRL_0_VBSENSE_EN_BIT);
  LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
  (uint16)(ARISUCAN_WK_CTRL_0_REG_W));
  (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  /* #6309 */
  /* Read HW_CTRL_0 Register Value */
  LusSpiSrcData = (uint16)ARISUCAN_HW_CTRL_0_REG_R;
  (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);

  /* PWM_AUTO Function Support */
  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if(CanTrcv_GucArisuCanPwmAuto == STD_ON)
  {
    /* #6309 Write PWM_AUTO On Value */
    LusSpiSrcData = (ArisuCan_GddSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT;
    LusSpiSrcData = (uint16)((LusSpiSrcData |(uint16)ARISUCAN_H_W_CTRL_0_PWM_AUTO_1_BIT));
    LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
    (uint16)(ARISUCAN_HW_CTRL_0_REG_W));
    (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
  } else {
    /* #6309 Write PWM_AUTO Off Value */
    LusSpiSrcData = (ArisuCan_GddSpiDestData & ARISUCAN_DATAMASK) >> ARISUCAN_EIGHT;
    LusSpiSrcData = (uint16)((LusSpiSrcData &(uint16)ARISUCAN_H_W_CTRL_0_PWM_AUTO_0_BIT));
    LusSpiSrcData = (uint16)((uint16)((uint16)LusSpiSrcData << (uint16)ARISUCAN_BUS_CTRL_MODE_POS) |
    (uint16)(ARISUCAN_HW_CTRL_0_REG_W));
    (void)ArisuCan_SendSPI(&LusSpiSrcData, &ArisuCan_GddSpiDestData);
  } /* if(CanTrcv_GucArisuCanPwmAuto == CANTRCV_TRUE) */
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  #endif /* STD_ON == CANTRCV_ARISUCAN_SUPPORT */

  /* Initialize the module, if return value is E_NOT_OK */
  #if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Set the global variable for init status to uninitialized */
  CanTrcv_GblInitStatus = CANTRCV_INITIALIZED;
  #endif
}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CANTRCV_GETVERSIONINFO_MACRO                        **
 **                                                                            **
 ** Service ID           : 0x04                                                **
 **                                                                            **
 ** Description          : This service returns the version information of this**
 **                        module                                              **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : versioninfo                                         **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : None                          **
 **                        Function(s) invoked : Det_ReportError               **
 *******************************************************************************/
#if (STD_ON == CANTRCV_GET_VERSION_INFO)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANTRCV_CODE) CANTRCV_GETVERSIONINFO_MACRO(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTRCV_APPL_DATA)versioninfo)
{
#if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
  /* Check whether the versioninfo is equal to null pointer */
  if(NULL_PTR == versioninfo)
  {
    /* Report to DET */
    (void)Det_ReportError(CANTRCV_MODULE_ID, CANTRCV_INSTANCE_ID,
    CANTRCV_GETVERSIONINFO_SID, CANTRCV_E_PARAM_POINTER);
  }
  else
#endif /* #if (STD_ON == CANTRCV_DEV_ERROR_DETECT) */
  {
    /* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
    /* Copy the vendor Id */
    versioninfo->vendorID = CANTRCV_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = CANTRCV_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = (uint8)CANTRCV_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = (uint8)CANTRCV_SW_MINOR_VERSION;
    /* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
  }
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (CANTRCV_GET_VERSION_INFO == STD_ON) */



/*******************************************************************************
 ** Function Name        : CanTrcv_TJA1145_Init                                **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service sets TJA1145 Init Mode                 **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucCanTrcvChannel                                   **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                                              CanTrcv_GaaCanTrcvPnNetwork   **
 **                                           CanTrcv_GaaCanTrcvPnFrameDataMask**
 **                        Function(s) invoked : CanTrcv_SendSPI               **
 *******************************************************************************/
#if(STD_ON == CANTRCV_TJA1145_PRESENT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_TJA1145_Init(uint8 LucCanTrcvChannel) {

  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData;
  uint8 LucTransceiver;
#if (STD_ON == CANTRCV_PN_SUPPORTED)
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  P2CONST(CanTrcv_PnNetwork, AUTOMATIC, CANTRCV_CONST) LpCanTrcvPnNetwork;
  P2CONST(CanTrcv_PnDataMask, AUTOMATIC, CANTRCV_CONST) LpCanTrcvPnFrameDataMask;
  uint8 LucCanTrcvPnIdUp;
  uint8 LucCanTrcvPnIdDn;
  uint8 LucCanTrcvDlc;
#endif

  LucTransceiver = LucCanTrcvChannel;

  /* 0x61 CLEAR All flags */
  LusCanTrcvSpiSrcData = (TJA1145_SYS_EVENT_STS_REG_W
      | TJA1145_SYS_EVENT_STS_CLEAR_BIT);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
      &LusCanTrcvSpiDestData);

  /* #15680 - 0x4C WAKE pin event rising and falling edge enable */
  LusCanTrcvSpiSrcData = (TJA1145_WAKE_EVENT_CTRL_REG_W
      | TJA1145_WAKE_PIN_WPR_ENABLE | TJA1145_WAKE_PIN_WPF_ENABLE);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
      &LusCanTrcvSpiDestData);

#if(STD_ON == CANTRCV_PN_SUPPORTED)
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucCanTrcvChannel];

  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if (LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED){
  LpCanTrcvPnNetwork =
   &CanTrcv_GaaCanTrcvPnNetwork[LpCanTrcvNetwork->usCanTrcvPnChannel];
    /* PNDM bit '1' DLC check, PNDM bit '0' No DLC Check
     blPnDlcMatchingCondition is PNDM bit  */
    if ((LpCanTrcvPnNetwork->blPnDlcMatchingCondition) == CANTRCV_TRUE) {
      if ((LpCanTrcvPnNetwork->blPnCanIdExtended) == CANTRCV_TRUE) {
        LusCanTrcvSpiSrcData = (TJA1145_FRAME_CTRL_REG_W
            | TJA1145_FRAME_CTRL_IDE_1_BIT
            | TJA1145_FRAME_CTRL_PNDM_1_BIT
            | (uint16) LpCanTrcvPnNetwork->ucPnFrameDlc);
      } else {
        LusCanTrcvSpiSrcData = (TJA1145_FRAME_CTRL_REG_W
            | TJA1145_FRAME_CTRL_IDE_0_BIT
            | TJA1145_FRAME_CTRL_PNDM_1_BIT
            | (uint16) LpCanTrcvPnNetwork->ucPnFrameDlc);
      }
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      for (LucCanTrcvDlc = 0; LucCanTrcvDlc < LpCanTrcvPnNetwork->ucPnFrameDlc; LucCanTrcvDlc++) {
        LpCanTrcvPnFrameDataMask =
            &CanTrcv_GaaCanTrcvPnFrameDataMask[LpCanTrcvPnNetwork->ucCanTrcvPnFrameDataMaskIndex
                + LucCanTrcvDlc];
        LusCanTrcvSpiSrcData =
            ((TJA1145_DATA_MASK_DM0_REG_W + (uint16)((uint16)0x200 * LucCanTrcvDlc))
                | (uint16) (LpCanTrcvPnFrameDataMask->ucCanTrcvPnFrmaeDataMask));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
            &LusCanTrcvSpiDestData);
      }
    } else {
      if ((LpCanTrcvPnNetwork->blPnCanIdExtended) == CANTRCV_TRUE) {
        LusCanTrcvSpiSrcData = (TJA1145_FRAME_CTRL_REG_W
            | TJA1145_FRAME_CTRL_IDE_1_BIT
            | TJA1145_FRAME_CTRL_PNDM_0_BIT
            | (uint16) LpCanTrcvPnNetwork->ucPnFrameDlc);
      } else {
        LusCanTrcvSpiSrcData = (TJA1145_FRAME_CTRL_REG_W
            | TJA1145_FRAME_CTRL_IDE_0_BIT
            | TJA1145_FRAME_CTRL_PNDM_0_BIT
            | (uint16) LpCanTrcvPnNetwork->ucPnFrameDlc);
      }
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
    }
    if ((LpCanTrcvPnNetwork->blPnCanIdExtended) == CANTRCV_TRUE) {
      /* 0x2A, WUF ID2 Set*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_REGISTER3_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0xFF000000U) >> 24) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x29, WUF ID2 Set*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_REGISTER2_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x00FF0000) >> 16) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x28, WUF ID2 Set*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_REGISTER1_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x0000FF00) >> 8) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x27, WUF ID3 Set*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_REGISTER0_REG_W)
          | (uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x000000FF) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x2E, ID Mask0  Write*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_MASK3_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0xFF000000U) >> 24) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x2D, ID Mask1  Write*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_MASK2_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x00FF0000) >> 16) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x2C, ID Mask2  Write*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_MASK1_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x0000FF00) >> 8) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x2B, ID Mask3  Write*/
      LusCanTrcvSpiSrcData = ((TJA1145_ID_MASK0_REG_W)
          | (uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x000000FF) & (Can_IdType)0x00FF));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
    } else {
      /* 0x2A, WUF ID3 Set*/
      LucCanTrcvPnIdUp = (uint8)((LpCanTrcvPnNetwork->ddPnFrameCanId
          & (Can_IdType) 0xFF00) >> 0x8);
      LucCanTrcvPnIdDn = (uint8)((LpCanTrcvPnNetwork->ddPnFrameCanId
          & (Can_IdType) 0x00C0) >> 0x4);
      LusCanTrcvSpiSrcData = ((uint16)LucCanTrcvPnIdUp << 2)
          | ((uint16)LucCanTrcvPnIdDn >> 2);
      LusCanTrcvSpiSrcData = (TJA1145_ID_REGISTER3_REG_W
          | LusCanTrcvSpiSrcData);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x29, WUF ID2 Set*/
      LusCanTrcvSpiSrcData = (TJA1145_ID_REGISTER2_REG_W
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x00FF) << 2) & (Can_IdType)0xFC));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x2E, ID Mask2  Write*/
      LucCanTrcvPnIdUp = (uint8)((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
          & (Can_IdType) 0xFF00) >> 0x8);
      LucCanTrcvPnIdDn = (uint8)(( LpCanTrcvPnNetwork->ddPnFrameCanIdMask
          & (Can_IdType) 0x00C0) >> 0x4);
      LusCanTrcvSpiSrcData = ((uint16)LucCanTrcvPnIdUp << 2)
          | ((uint16)LucCanTrcvPnIdDn >> 2);
      LusCanTrcvSpiSrcData = (TJA1145_ID_MASK3_REG_W
          | LusCanTrcvSpiSrcData);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x2D, ID Mask3  Write*/
      LusCanTrcvSpiSrcData = (TJA1145_ID_MASK2_REG_W
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x00FF) << 2) & (Can_IdType)0xFC));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
    }

    /* 0x23, CWE = 1  Write*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_ENABLE_REG_W
        | TJA1145_TRCV_EVENT_ENABLE_CWE_1_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);

    /* 0x20, CFDC, PNCOK, CPNC = 1  Write*/
    LusCanTrcvSpiSrcData =
        (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT
            | TJA1145_CAN_CONTROL_PNCOK_1_BIT
            | TJA1145_CAN_CONTROL_CPNC_1_BIT
            | TJA1145_CAN_CONTROL_CMC_1_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);

    /* 0x63 CLEAR CW flag*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W
        | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT
        | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT
        | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);
  }else{ /* TJA1145 is not using partial network functionality */
    /* 0x23, CWE = 1  Write*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_ENABLE_REG_W | TJA1145_TRCV_EVENT_ENABLE_CWE_1_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x20, CFDC=1, PNCOK=0, CPNC=0  Write*/
    LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x63 CLEAR CW flag*/
    LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
  }
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
#else                 
  /* 0x23, CWE = 1  Write*/
  LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_ENABLE_REG_W | TJA1145_TRCV_EVENT_ENABLE_CWE_1_BIT);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  /* 0x20, CFDC=1, PNCOK=0, CPNC=0  Write*/
  LusCanTrcvSpiSrcData = (TJA1145_CAN_CONTROL_REG_W | TJA1145_CAN_CONTROL_CFDC_1_BIT | TJA1145_CAN_CONTROL_CMC_1_BIT);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  /* 0x63 CLEAR CW flag*/
  LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | TJA1145_TRCV_EVENT_STS_CW_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_CF_CLEAR_BIT | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
#endif

}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
 ** Function Name        : CanTrcv_TCAN1145_Init                               **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service sets TCAN1145 Init Mode                **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucCanTrcvChannel                                   **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                                              CanTrcv_GaaCanTrcvPnNetwork   **
 **                                           CanTrcv_GaaCanTrcvPnFrameDataMask**
 **                        Function(s) invoked : CanTrcv_SendSPI               **
 *******************************************************************************/
#if(STD_ON == CANTRCV_TCAN1145_PRESENT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_TCAN1145_Init(uint8 LucCanTrcvChannel) {

  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  uint8 LucTransceiver;
  #if (STD_ON == CANTRCV_PN_SUPPORTED)
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  P2CONST(CanTrcv_PnNetwork, AUTOMATIC, CANTRCV_CONST) LpCanTrcvPnNetwork;
  P2CONST(CanTrcv_PnDataMask, AUTOMATIC, CANTRCV_CONST) LpCanTrcvPnFrameDataMask;
  uint8 LucCanTrcvDlc;
  #endif
  LucTransceiver = LucCanTrcvChannel;
  (void)CanTrcv_TCAN1145_CanBaudRateConfig(LucTransceiver);
  /*Clear Flag*/
  /*PowerOn wake flag PWRON = 1 write */
  LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS )| TCAN1145_INT_2_PWRON_BIT));
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  /* CANINT,LWU,WKERR,FRAME_OVF clear (= 0)*/
  LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)|(LusCanTrcvSpiDestData & TCAN1145_INT_1_CLEAR_FLAG_BITMASK));
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);\

  /* INT2 Register Sleep mode Status flag clear.*/
  LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  LusCanTrcvSpiSrcData = ((TCAN1145_INT_2_REG_W )| (LusCanTrcvSpiDestData & TCAN1145_INT_2_SMS_REG_CLEAR_BIT));
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

  /* 0x11 Clear Wake state pin */
  LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_R);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
  LusCanTrcvSpiSrcData = (TCAN1145_WAKE_PIN_CONFIG_REG_W | (LusCanTrcvSpiDestData & TCAN1145_WAKE_PIN_CONFIG_CLEAR_BIT));
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);


  #if(STD_ON == CANTRCV_PN_SUPPORTED)
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucCanTrcvChannel];

  /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
  if (LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED){
  LpCanTrcvPnNetwork =
   &CanTrcv_GaaCanTrcvPnNetwork[LpCanTrcvNetwork->usCanTrcvPnChannel];
    /* blPnDlcMatchingCondition is DLC_MASK_ENABLE. */
    if ((LpCanTrcvPnNetwork->blPnDlcMatchingCondition) == CANTRCV_TRUE) 
    {
      if ((LpCanTrcvPnNetwork->blPnCanIdExtended) == CANTRCV_TRUE) {
        LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_W
            | TCAN1145_ID_MASK_DLC_MASK_ENABLE
            | ((uint16) LpCanTrcvPnNetwork->ucPnFrameDlc <<1));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);    

        /*IDE =1 write. Extended ID field */
        LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  
        LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_W | (LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_ID_REG3_IDE_1_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);    
          
      } else {
        LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_W
            | TCAN1145_ID_MASK_DLC_MASK_ENABLE
            | ((uint16) LpCanTrcvPnNetwork->ucPnFrameDlc <<1));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);    
        
        LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 

        LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG3_REG_W) | (LusCanTrcvSpiDestData & TCAN1145_ID_REG3_IDE_0_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  
      }

      for (LucCanTrcvDlc = 0; LucCanTrcvDlc < LpCanTrcvPnNetwork->ucPnFrameDlc; LucCanTrcvDlc++) {
        LpCanTrcvPnFrameDataMask =
            &CanTrcv_GaaCanTrcvPnFrameDataMask[LpCanTrcvPnNetwork->ucCanTrcvPnFrameDataMaskIndex
                + LucCanTrcvDlc];
        LusCanTrcvSpiSrcData =
            ((TCAN1145_DATA_y_REG_W + (uint16)((uint16)0x200 * (LpCanTrcvPnNetwork->ucPnFrameDlc- LpCanTrcvPnFrameDataMask->ucCanTrcvPnFrameDataMaskInd-1 )))
                | (uint16) (LpCanTrcvPnFrameDataMask->ucCanTrcvPnFrmaeDataMask));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
            &LusCanTrcvSpiDestData);
      }
    } 
    else 
    {
      if ((LpCanTrcvPnNetwork->blPnCanIdExtended) == CANTRCV_TRUE) {
        LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_W
            | (TCAN1145_ID_MASK_DLC_MASK_DISABLE
            & ((uint16) LpCanTrcvPnNetwork->ucPnFrameDlc <<1)));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);  

        LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);    

        LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_W | (LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_ID_REG3_IDE_1_BIT);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);    
          
      } else {
        LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_W
            | (TCAN1145_ID_MASK_DLC_MASK_DISABLE
            & ((uint16) LpCanTrcvPnNetwork->ucPnFrameDlc << 1)));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);    
        
        LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  


        LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG3_REG_W ) | (LusCanTrcvSpiDestData & TCAN1145_ID_REG3_IDE_0_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  
      }
    }

    if ((LpCanTrcvPnNetwork->blPnCanIdExtended) == CANTRCV_TRUE) {
      /* 0x32, WUF Extended ID bits 28:24 Set*/
      LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
           &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG3_REG_W) 
          | ((LusCanTrcvSpiDestData & TCAN1145_ID_REG3_REG_BITMASK) 
             | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId 
              & (Can_IdType) 0x1F000000U) >> 24))));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
      
      /* 0x33, WUF Extended ID bits 23:18 Set*/
      LusCanTrcvSpiSrcData = (TCAN1145_ID_REG4_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
           &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG4_REG_W)
          | ((LusCanTrcvSpiDestData & TCAN1145_ID_REG4_REG_BITMASK)
            | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x00FC0000U) >> 16))));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData); 
      
      /* 0x30, WUF Extended ID bits 17:10 Set*/
      LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG1_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x0003FC00U) >> 10)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x31, WUF Extended ID bits 9:2 Set*/
      LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG2_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x000003FCU) >> 2)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

       /* 0x32, WUF Extended ID bits 1:0 Set*/
       LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
           &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData = ((TCAN1145_ID_REG3_REG_W)
          | (LusCanTrcvSpiDestData & TCAN1145_ID_REG3_REG_EX_ID_BITMASK)
            |((uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x00000003U) << 6 )));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x37, ID Mask 28:21  Write*/
      LusCanTrcvSpiSrcData = ((TCAN1145_ID_MASK4_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
               & (Can_IdType) 0x1F700000U) >> 21)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x38, ID Mask 20:18  Write*/
      LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, 
          &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData = ((TCAN1145_ID_MASK_DLC_REG_W)
          | (LusCanTrcvSpiDestData & TCAN1145_ID_MASK_DLC_BITMASK)
            | ((uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x001C0000U) >> 13)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x34, ID Mask 17:16  Write*/
      LusCanTrcvSpiSrcData = ((TCAN1145_ID_MASK1_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x00030000U) >> 16)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x35, ID Mask 15:8  Write*/
      LusCanTrcvSpiSrcData = ((TCAN1145_ID_MASK2_REG_W)
          | (uint16) (((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x0000FF00) >> 8)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x36, ID Mask 7:0 Write*/
      LusCanTrcvSpiSrcData = ((TCAN1145_ID_MASK3_REG_W)
          | (uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanIdMask
              & (Can_IdType) 0x000000FF)));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
    } 
    else {
      /* 0x32, ID 10:6 Set*/
      LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData =((LusCanTrcvSpiDestData & TCAN1145_ID_REG3_REG_BITMASK)
         | (uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanId
              & (Can_IdType) 0x07C0) >> 6));
      LusCanTrcvSpiSrcData = (TCAN1145_ID_REG3_REG_W
          | LusCanTrcvSpiSrcData);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x33, ID 5:0 Set*/
      LusCanTrcvSpiSrcData = (TCAN1145_ID_REG4_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData =((uint16) (LpCanTrcvPnNetwork->ddPnFrameCanId & (Can_IdType) 0x003F)<<2 );

      LusCanTrcvSpiSrcData = (TCAN1145_ID_REG4_REG_W | (LusCanTrcvSpiDestData & TCAN1145_ID_REG4_REG_BITMASK) | LusCanTrcvSpiSrcData);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x37, ID Mask 10:3 Set*/
      LusCanTrcvSpiSrcData = (uint16) ((LpCanTrcvPnNetwork->ddPnFrameCanIdMask & (Can_IdType) 0x07F8) >> 3);
      LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK4_REG_W | LusCanTrcvSpiSrcData);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      /* 0x38, ID Mask 2:0 Set*/
      LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      LusCanTrcvSpiSrcData = ( (uint16) (LpCanTrcvPnNetwork->ddPnFrameCanIdMask & (Can_IdType) 0x0007) <<5 );

      LusCanTrcvSpiSrcData = (TCAN1145_ID_MASK_DLC_REG_W |(LusCanTrcvSpiDestData & TCAN1145_ID_MASK_DLC_BITMASK)  | (LusCanTrcvSpiSrcData ));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
    }   
    /*0x47  SWCFG =1 Set*/
    LusCanTrcvSpiSrcData = ( TCAN1145_CONFIG4_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_CONFIG4_SWCFG_REG_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /*0x10  SW_EN =1 Set*/
    LusCanTrcvSpiSrcData = ( TCAN1145_MODE_CNTRL_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    LusCanTrcvSpiSrcData = (TCAN1145_MODE_CNTRL_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_MODE_CNTRL_SW_EN_1_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

    /* 0x51 Clear CANINT flag*/
    /* CANINT  flag is wakeup interrupt*/
    LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
    (void)CanTrcv_SendSPI(LucTransceiver , &LusCanTrcvSpiSrcData,&LusCanTrcvSpiDestData);

    LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)| (TCAN1145_INT_1_CANINT_CLEAR_BIT));
    (void)CanTrcv_SendSPI(LucTransceiver , &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);
  }
  else
  { /* TCAN1145 is not using partial network functionality */ 

      /* 0x51 Clear CANINT flag*/
      /* CANINT  flag is wakeup interrupt*/
      LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,&LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)| (TCAN1145_INT_1_CANINT_CLEAR_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);
  }
  /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
#else                 


  /* 0x51 Clear CANINT flag*/
  LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,&LusCanTrcvSpiDestData);
  LusCanTrcvSpiSrcData = ((TCAN1145_INT_1_REG_W)| (TCAN1145_INT_1_CANINT_CLEAR_BIT));
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
      &LusCanTrcvSpiDestData);

#endif

}

#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(STD_ON == CANTRCV_TCAN1145_PRESENT)
/*******************************************************************************
 ** Function Name        : CanTrcv_TCAN1145_CanBaudRateConfig                  **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service configureation Can ,Can FD baudrate    **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : None                                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : CanTrcv_SendSPI               **
 **                                                                            **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_TCAN1145_CanBaudRateConfig(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];
 /* 0x44 set Can bus data rate */
  LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_R);
  (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,&LusCanTrcvSpiDestData);
  LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_W | (LusCanTrcvSpiDestData & TCAN1145_CONFIG1_CAN_DR_BITMASK ));
  
  switch(LpCanTrcvNetwork->usCanTrcvCanBaudRate)
  {
    case TCAN1145_CAN_DATARATE_50 :
      LusCanTrcvSpiSrcData = (LusCanTrcvSpiSrcData | TCAN1145_CONFIG1_CAN_DR_50_BIT);
      break;

    case TCAN1145_CAN_DATARATE_100 :
      LusCanTrcvSpiSrcData = (LusCanTrcvSpiSrcData | TCAN1145_CONFIG1_CAN_DR_100_BIT);
      break;

    case TCAN1145_CAN_DATARATE_125 :
      LusCanTrcvSpiSrcData = (LusCanTrcvSpiSrcData | TCAN1145_CONFIG1_CAN_DR_125_BIT);
      break;

    case TCAN1145_CAN_DATARATE_250 :
      LusCanTrcvSpiSrcData = (LusCanTrcvSpiSrcData | TCAN1145_CONFIG1_CAN_DR_250_BIT);
      break;

    case TCAN1145_CAN_DATARATE_1000 :
      LusCanTrcvSpiSrcData = (LusCanTrcvSpiSrcData | TCAN1145_CONFIG1_CAN_DR_1000_BIT);
      break;

    default:
      LusCanTrcvSpiSrcData = (LusCanTrcvSpiSrcData | TCAN1145_CONFIG1_CAN_DR_500_BIT);
      break;
  }

    (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,&LusCanTrcvSpiDestData);


  if(LpCanTrcvNetwork->usCanTrcvCanFdBaudRate != CANTRCV_CAN_DATARATE_INVALID)
  {
      
    if(LpCanTrcvNetwork->usCanTrcvCanFdBaudRate >= (CANTRCV_FIVE * (LpCanTrcvNetwork->usCanTrcvCanBaudRate)))
    {
      if(LpCanTrcvNetwork->usCanTrcvCanFdBaudRate <= (CANTRCV_TEN * (LpCanTrcvNetwork->usCanTrcvCanBaudRate)))
      {
        LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_R);
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
        LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_CONFIG1_FD_DR_BITMASK ) | TCAN1145_CONFIG1_FD_DR_4X_BIT));
        (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      }
    }
    else if(LpCanTrcvNetwork->usCanTrcvCanFdBaudRate <= (CANTRCV_FOUR * (LpCanTrcvNetwork->usCanTrcvCanBaudRate)))
    {
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_W | (LusCanTrcvSpiDestData & TCAN1145_CONFIG1_FD_DR_BITMASK));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    }
    else{
      /*do nothing*/
    }
    #if(STD_ON == CANTRCV_PN_SUPPORTED)
    if(LpCanTrcvNetwork->usCanTrcvPnChannel != CANTRCV_PNCHANNEL_UNUSED)
    {/* 0x44 set Can FD enable */
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG1_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS ) | TCAN1145_CONFIG1_SW_FD_PASSIVE));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
    }
    #endif
  }


}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif



#if((CANTRCV_TJA1145_PRESENT == STD_ON) || (CANTRCV_TCAN1145_PRESENT == STD_ON))
/*******************************************************************************
 ** Function Name        : CanTrcv_CheckUndervoltage                           **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service Check Transceiver sleep                **
 **                          from Undervoltage                                 **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : CanTrcv_UndervolType                                **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : CanTrcv_SendSPI               **
 **                                                                            **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(CanTrcv_UndervolType, CANTRCV_CODE) CanTrcv_CheckUndervoltage(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  CanTrcv_UndervolType LddResult = CANTRCV_NOUNDERVOL;
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];

  switch(LpCanTrcvNetwork->ddCanTrcvHwDev)
  {
    #if(CANTRCV_TJA1145_PRESENT == STD_ON)
    case CANTRCV_TJA1145 :
      LusCanTrcvSpiSrcData = (TJA1145_MAIN_STS_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);

     /*Check when TJA1145 force to Sleep Mode*/
      if((LusCanTrcvSpiDestData & TJA1145_MAIN_FSMS_REG_1_BIT) == CANTRCV_ZERO)
      {
          LddResult = CANTRCV_NOUNDERVOL;
      }
      else
      {
         LddResult = CANTRCV_UNDERVOL;		
      }
      break;
    #endif
    #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
    case CANTRCV_TCAN1145 :
      LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
        &LusCanTrcvSpiDestData);
      
     /*Check when TCAN1145 force to Sleep Mode*/
      if((LusCanTrcvSpiDestData & (TCAN1145_INT_2_UVSUP_BIT | TCAN1145_INT_2_UVIO_BIT | TCAN1145_INT_2_UVCC_BIT)) == CANTRCV_ZERO)
      {
          LddResult = CANTRCV_NOUNDERVOL;
      }
      else
      {
         LddResult = CANTRCV_UNDERVOL;		
      }
      break;
    #endif
    default :
      /*Do Nothing*/
      break;
  }

  return LddResult;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if(CANTRCV_TJA1145_PRESENT == STD_ON)*/


#if((STD_ON == CANTRCV_SPI_SUPPORT) && (STD_ON == CANTRCV_PN_SUPPORTED))

/*******************************************************************************
 ** Function Name        : CanTrcv_CheckPORFlag                                **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service check TJA1145 POR Event Flags to       **
 *                         Confirm CanTransceiver H/W Status                   **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : Std_ReturnType                                      **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : Det_ReportError,              **
 **                                              CanTrcv_SendSPI               **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanTrcv_PnErrType, CANTRCV_CODE) CanTrcv_CheckPORFlag(uint8 LucTransceiver)
{
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  CanTrcv_PnErrType LddResult = (CanTrcv_PnErrType) CANTRCV_NOERR;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];

  switch(LpCanTrcvNetwork->ddCanTrcvHwDev)
  {
    #if(CANTRCV_TJA1145_PRESENT == STD_ON)
    case CANTRCV_TJA1145 :
      /* 0x60 Check SYSE of Global event status register */
      LusCanTrcvSpiSrcData = (TJA1145_GBL_EVENT_STS_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      if ((LusCanTrcvSpiDestData & TJA1145_GBL_EVENT_STSE_ALLBITMASK) != CANTRCV_ZERO) {
        LddResult = (CanTrcv_PnErrType) CANTRCV_PORERR;
      } else {
        LddResult = (CanTrcv_PnErrType) CANTRCV_NOERR;
      }
	    break;
    #endif

    #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
    case CANTRCV_TCAN1145 :

      /* 0x52 Check PowerOn Interrupt Register */
      LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData,
          &LusCanTrcvSpiDestData);

      if ((LusCanTrcvSpiDestData & TCAN1145_INT_2_PWRON_BIT) != CANTRCV_ZERO) {
        LddResult = (CanTrcv_PnErrType) CANTRCV_NOERR;
      } else {
        LddResult = (CanTrcv_PnErrType) CANTRCV_PORERR;
      }

	    break;
    #endif
    default :
      /*Do Nothing*/
      break;
  }
  return LddResult;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_ClearPORFlag                                **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service clear TJA1145 POR Event Flags          **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : Std_ReturnType                                      **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : Det_ReportError,              **
 **                                              CanTrcv_SendSPI               **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_ClearPORFlag(uint8 LucTransceiver)
{
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];
  switch(LpCanTrcvNetwork->ddCanTrcvHwDev)
  {
    #if(CANTRCV_TJA1145_PRESENT == STD_ON)
    case CANTRCV_TJA1145 :
      /* 0x61 CLEAR PO flag - Clear SYSE*/
      LusCanTrcvSpiSrcData = (TJA1145_SYS_EVENT_STS_REG_W | TJA1145_SYS_EVENT_STS_CLEAR_BIT);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData); 
	    break;
    #endif
    #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
    case CANTRCV_TCAN1145 :
      /* 0x52 Clear PWRON flag*/
      LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      LusCanTrcvSpiSrcData = (TCAN1145_INT_2_REG_W | ((LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS) | TCAN1145_INT_2_PWRON_BIT));
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
	    break;
    #endif

   default :
    /*Do Nothing*/
    break;
  } 
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_CheckSYSEFlag                               **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service check TJA1145 SYS Error Event Flags to **
 *                         Confirm CanTransceiver H/W Status                   **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : Std_ReturnType                                      **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : Det_ReportError,              **
 **                                              CanTrcv_SendSPI               **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanTrcv_PnErrType, CANTRCV_CODE) CanTrcv_CheckSYSEFlag(uint8 LucTransceiver)
{
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  CanTrcv_PnErrType LddResult = (CanTrcv_PnErrType) CANTRCV_NOERR;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];

  
  switch(LpCanTrcvNetwork->ddCanTrcvHwDev)
  {
    #if(CANTRCV_TJA1145_PRESENT == STD_ON)
    case CANTRCV_TJA1145 :
      /* 0x22 Check CPNERR - Partial networking error detecting flag*/
      LusCanTrcvSpiSrcData = TJA1145_TRCV_STS_REG_R;
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the LusCanTrcvSpiDestData values" */
      if ((LusCanTrcvSpiDestData & TJA1145_TRCV_STS_CPNERR_1_BITMAKS) != CANTRCV_ZERO) 
      {
        LddResult = (CanTrcv_PnErrType) CANTRCV_SYSERR;
      } 
      else
      {
        LddResult = (CanTrcv_PnErrType) CANTRCV_NOERR;
      }
      /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the LusCanTrcvSpiDestData values" */
	    break;
    #endif
    #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
    case CANTRCV_TCAN1145 :
      /* 0x53 Check SWERR - Partial networking(selective wake) error detecting flag*/
      LusCanTrcvSpiSrcData = (TCAN1145_INT_3_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the LusCanTrcvSpiDestData values" */
      if ((LusCanTrcvSpiDestData & TCAN1145_INT_3_SWERR_BIT) != CANTRCV_ZERO) 
      {
        LddResult = (CanTrcv_PnErrType) CANTRCV_SYSERR;
      } 
      else
      {
        LddResult = (CanTrcv_PnErrType) CANTRCV_NOERR;
      }
      /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the LusCanTrcvSpiDestData values" */
	    break;
    #endif

   default : 
    /*Do Nothing*/
    break;
  }

  return LddResult;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_ClearSYSEFlag                               **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service clear TJA1145 SYS Error Event Flags    **
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : Std_ReturnType                                      **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : Det_ReportError,              **
 **                                              CanTrcv_SendSPI               **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANTRCV_CODE) CanTrcv_ClearSYSEFlag(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  uint16 LusCanTrcvSpiSrcData;
  uint16 LusCanTrcvSpiDestData = CANTRCV_ZERO;
  uint16 LusRegisterValue;
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];

  switch(LpCanTrcvNetwork->ddCanTrcvHwDev)
  {
    #if(CANTRCV_TJA1145_PRESENT == STD_ON)
    case CANTRCV_TJA1145 :

      /* PNFDE Regiseter of Transceiver event status register */
      LusCanTrcvSpiSrcData = TJA1145_TRCV_EVENT_STS_REG_R;
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      
      LusRegisterValue = (LusCanTrcvSpiDestData | TJA1145_TRCV_EVENT_STS_PNFDE_CLEAR_BIT);

      /* 0x63 Clear PNFDE - Partial networking frame detection error flag*/
      LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | LusRegisterValue);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

      /* PNCOK Regiseter of Can Control Register */
      LusCanTrcvSpiSrcData = TJA1145_CAN_CONTROL_REG_R;
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      
      LusRegisterValue = (LusCanTrcvSpiDestData | TJA1145_CAN_CONTROL_PNCOK_1_BIT);

      /* 0x20 Clear PNCOK - Can Control Register*/
      LusCanTrcvSpiSrcData = (TJA1145_TRCV_EVENT_STS_REG_W | LusRegisterValue);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);  
      break;
    #endif
    #if(CANTRCV_TCAN1145_PRESENT == STD_ON)
    case CANTRCV_TCAN1145 :
    
      /* 0x51 Clear FRAME_OVF flag */
      LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      
      LusRegisterValue = (LusCanTrcvSpiDestData & TCAN1145_INT_1_CLEAR_FRAME_OVF_BIT);

      LusCanTrcvSpiSrcData = (TCAN1145_INT_1_REG_W | LusRegisterValue);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);

        LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_R);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      
      LusRegisterValue = (LusCanTrcvSpiDestData & TCAN1145_REG_BITMASKS);

      LusCanTrcvSpiSrcData = (TCAN1145_CONFIG4_REG_W | LusRegisterValue | TCAN1145_CONFIG4_SWCFG_REG_BIT);
      (void)CanTrcv_SendSPI(LucTransceiver, &LusCanTrcvSpiSrcData, &LusCanTrcvSpiDestData);
      break;
    #endif
    default :
      /*Do Nothing*/
      break;
  }
   
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 ** Function Name        : CanTrcv_CheckPnFlags                                **
 **                                                                            **
 ** Service ID           : N/A                                                 **
 **                                                                            **
 ** Description          : This service check TJA1145 SYS Error Event Flags &  **
 **                      TJA1145 POR flag to Confirm CanTransceiver H/W Status **       
 **                                                                            **
 ** Re-entrancy          : Non Reentrant                                       **
 **                                                                            **
 ** Input Parameters     : LucTransceiver                                      **
 **                                                                            **
 ** Output Parameters    : None                                                **
 **                                                                            **
 ** Return parameter     : Std_ReturnType                                      **
 **                                                                            **
 ** Preconditions        : None                                                **
 **                                                                            **
 ** Remarks              : Global Variable(s)  : CanTrcv_GaaCanTrcvNetwork     **
 **                        Function(s) invoked : Det_ReportError,              **
 **                                              CanTrcv_SendSPI               **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
FUNC(CanTrcv_PnErrType, CANTRCV_CODE) CanTrcv_CheckPnFlags(uint8 LucTransceiver)
{
  P2CONST(CanTrcv_PnNetwork, AUTOMATIC, CANTRCV_CONST) LpCanTrcvPnNetwork;
  P2CONST(CanTrcv_Network, AUTOMATIC, CANTRCV_CONST) LpCanTrcvNetwork;
  CanTrcv_PnErrType LddSYSEResult = CANTRCV_NOERR;
  CanTrcv_PnErrType LddPORResult = CANTRCV_NOERR;
  CanTrcv_PnErrType LddResult = CANTRCV_NOERR;
  
  LpCanTrcvNetwork = &CanTrcv_GaaCanTrcvNetwork[LucTransceiver];
  if(LpCanTrcvNetwork->usCanTrcvPnChannel < CANTRCV_PNCHANNEL_UNUSED)
  {
    LpCanTrcvPnNetwork =
      &CanTrcv_GaaCanTrcvPnNetwork[LpCanTrcvNetwork->usCanTrcvPnChannel];
    if((LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TJA1145) ||(LpCanTrcvNetwork->ddCanTrcvHwDev == CANTRCV_TCAN1145) ){
      LddSYSEResult = CanTrcv_CheckSYSEFlag(LucTransceiver);
      /* blPowerOnFlag should be checked */
      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */	
      if(LpCanTrcvPnNetwork->blPowerOnFlag == 0){
        LddPORResult = CANTRCV_NOERR;
      }else{
        LddPORResult = CanTrcv_CheckPORFlag(LucTransceiver);
      }
      /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */	

      (void)CanTrcv_ClearPORFlag(LucTransceiver);
      (void)CanTrcv_ClearSYSEFlag(LucTransceiver);
    }

    /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the CanTrcv_CheckSYSEFlag return values" */	
    if((CANTRCV_NOERR != LddSYSEResult) && (CANTRCV_NOERR != LddPORResult)){
      LddResult = CANTRCV_SYSPORERR;
    }else if(CANTRCV_NOERR != LddSYSEResult){
      LddResult = CANTRCV_SYSERR;
    }else if(CANTRCV_NOERR != LddPORResult){
      LddResult = CANTRCV_PORERR;
    }else{
      LddResult = CANTRCV_NOERR;
    }
    /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the CanTrcv_CheckSYSEFlag return values" */
  }
  return LddResult;
}
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"


#endif /* #if((STD_ON == CANTRCV_SPI_SUPPORT) && (STD_ON == CANTRCV_PN_SUPPORTED)) */
/* polyspace:end<RTE:UNR:Not a defect : No Action Planned> Because condition check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
 **                      End of File                                           **
 *******************************************************************************/
