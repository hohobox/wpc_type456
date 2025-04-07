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
**  SRC-MODULE: Com_IpduGrp.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of start/stop of I-PDU group & deadline monitoring  **
**              system.                                                       **
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
** 2.9.2.2   28-Apr-2023   DH Choi     Internal Redmine #40498                **
** 2.9.2.0   23-Aug-2022   DH Choi     Internal Redmine #36994                **
** 2.9.0     30-Jun-2022   HT Kim      Internal Redmine #35740, #36472        **
** 2.7.5     27-Dec-2021   SM Kwon     Internal Redmine #33354                **
** 2.7.4     19-Aug-2021   SM Kwon     Internal Redmine #30917                **
** 2.7.3     12-Jul-2021   SM Kwon     Internal Redmine #30089, #30832        **
** 2.7.2     28-May-2021   SM Kwon     Internal Redmine #30001, #30039        **
** 2.7.1     07-Jan-2021   SM Kwon     Internal Redmine #27557                **
** 2.7.0     31-Dec-2020   SM Kwon     Internal Redmine #27040, #27452        **
** 2.6.0     10-Sep-2020   SM Kwon     Internal Redmine #25614                **
** 2.5.0     20-Feb-2020   SM Kwon     Internal Redmine #21472                **
** 2.4.2     09-Apr-2019   SM Kwon     Internal Redmine #16805                **
** 2.4.1     14-Mar-2019   SM Kwon     Internal Redmine #16344                **
** 2.4.0     25-Jan-2019   SM Kwon     Internal Redmine #14067, #14789        **
** 2.3.0     26-Jun-2018   SM Kwon     Internal Redmine #13012                **
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7525, #9740   **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807                 **
** 2.1.5     07-Oct-2016   Chan Kim    Internal Redmine #5874, #5909          **
** 2.1.4     19-Aug-2016   Chan Kim    Internal Redmine #5687, #5813          **
** 2.1.3     12-Jul-2016   Chan Kim    Internal Redmine #5479, #5550          **
** 2.1.1     20-Jun-2016   Chan Kim    Internal Redmine #5265                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.13    13-May-2016   Chan Kim    Internal Redmine #4908                 **
** 2.0.10    25-Feb-2016   Chan Kim    Internal Redmine #4250                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4158                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 2.0.2     18-Sep-2015   Chan Kim    Internal Redmine #3178                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463, #1204, #1632   **
** 1.0.12    26-May-2014   Chan Kim    Internal Redmine #883                  **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #729                  **
** 1.0.9     11-Feb-2014   Chan Kim    Internal Redmine #605                  **
** 1.0.0     29-Apr-2013   AUTOEVER    Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Com.h"          /* Com header file            */
#include "Com_Main.h"     /* Com Main header file       */
#include "Com_Error.h"    /* Com Error header file      */
#include "Com_IpduGrp.h"  /* Com Ipdu Group header file */
#include "SchM_Com.h"     /* SchM Com header file       */
#include "string.h"       /* memcpy()                   */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"          /* Det header file            */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_IPDUGRP_C_AR_RELEASE_MAJOR_VERSION  4
#define COM_IPDUGRP_C_AR_RELEASE_MINOR_VERSION   0
#define COM_IPDUGRP_C_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_IPDUGRP_C_SW_MAJOR_VERSION  2
#define COM_IPDUGRP_C_SW_MINOR_VERSION  9

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_IPDUGRP_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_IPDUGRP_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != \
  COM_IPDUGRP_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_IPDUGRP_C_SW_MAJOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_IPDUGRP_C_SW_MINOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Low> If-condition is changable depending on the configuration */
/* polyspace:begin<MISRA-C3:14.3:Not a defect:Low> If-condition is changable depending on the configuration */
/* polyspace:begin <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> configured memory access index */
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_StopIpduGroup(Com_IpduGroupIdType IpduGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_RX_IPDU_DM == STD_ON) || \
  (COM_RX_SIGNAL_UBDM == STD_ON) || \
  (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_EnableRxDM(Com_IpduGroupIdType IpduGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_StartIpduGroup(Com_IpduGroupIdType IpduGroupId,
                                                          boolean Initialize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_RX_IPDU_DM == STD_ON) || \
  (COM_RX_SIGNAL_UBDM == STD_ON) || \
  (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_DisableRxDM(Com_IpduGroupIdType IpduGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_StartTxIpdu                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function starts a Tx I-PDU                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU                       **
**                        Non-Reentrant for same I-PDU                        **
**                                                                            **
** Input Parameters     : IpduId, Initialize                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpduStatus        **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaFilterStatus        **
**                                                 Com_GaaTxMode              **  
**                                                 Com_GaaTxMDTimer           **
**                                                 Com_GaaTxPeriodicTimer     **
**                                                 Com_GaaTxPduInfoPtr        **
**                                                 Com_GaaTxIpduCounter       **
**                                                 Com_GaaTxIpduCountVal      **
**                                                 Com_GaaFilterOneEveryN     **
**                                                 Com_GaaTxReptTimer         **
**                                                 Com_GaaTxReptCount         **
**                                                 Com_GaaTxReptSubCount      **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxTPStatus          **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#if(COM_TX_IPDU_NOTINCL_COUNT > COM_MACRO_ZERO)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_StartTxIpdu(PduIdType IpduId, boolean Initialize)
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_StartTxIpdu(PduIdType IpduId, boolean Initialize)
#endif
{
  /* Pointer to Tx Ipdu */
  #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON) || (COM_TX_IPDU_TMS_EXPLICIT == STD_ON) || (COM_TX_IPDU_PT == STD_ON) \
  || (COM_TX_IPDU_DM == STD_ON) || (COM_TX_TP_SUPPORT == STD_ON) \
  || (COM_TX_IPDU_REPETITION == STD_ON) || (COM_TX_IPDU_COUNTER_ENABLED == STD_ON) \
  || (COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON) || (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) \
  || (COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON))
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu; 
  #endif
  #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
  boolean LblFilterResult;  
  #endif
  #if(COM_TX_IPDU_TMS_SIG_BASED == STD_ON)
  P2CONST(Com_TxIpduModeSel, AUTOMATIC, COM_CONST) LpTxModeSelect;
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpFilterStatus;
  uint8 LucFilterStatusIndex;
  #endif   
  #if(COM_TX_IPDU_TMS_SIG_BASED == STD_ON)
  uint8 LucFilterStsCount;
  #endif
  #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_PT == STD_ON) \
  ||(COM_TX_IPDU_DM == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
  /* Pointer to Tx mode structure */
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  #endif 
  #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
  P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter;
  #endif
  #if(COM_TX_IPDU_DM == STD_ON)  
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxModeTrue;
  #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxModeFalse;
  #endif
  #endif
  #if(COM_TX_TP_SUPPORT == STD_ON)    
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  PduIdType LddTxPduId = IpduId;

  #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON) || (COM_TX_IPDU_TMS_EXPLICIT == STD_ON) || (COM_TX_IPDU_PT == STD_ON) \
    || (COM_TX_IPDU_DM == STD_ON) || (COM_TX_TP_SUPPORT == STD_ON) \
    || (COM_TX_IPDU_REPETITION == STD_ON) || (COM_TX_IPDU_COUNTER_ENABLED == STD_ON) \
    || (COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON) || (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) \
    || (COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON))
  LpTxIpdu = &Com_GaaTxIpdu[LddTxPduId];
  #endif

  if(Com_GaaTxIpduStatus[LddTxPduId] == (uint16)COM_ZERO)
  {
    /* Check if initialization is equal to true then clear all bits */
    /* and Initialize Buffer */ 
    if(COM_TRUE == Initialize)
    {
      Com_GaaTxIpduStatusBit[LddTxPduId] &= (COM_TX_TMS_STATUS_MASK);

      #if(COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON)
      #if(COM_RAM8BIT_INIT == STD_ON)
      if(LpTxIpdu->usRamInit8BitSize > COM_ZERO)
      {
        memcpy(&Com_GaaRamInit8Bit[LpTxIpdu->ulRamInit8BitStartIdx], 
        &Com_GaaRamInit8BitCpy[LpTxIpdu->ulRamInit8BitStartIdx], LpTxIpdu->usRamInit8BitSize);
      }
      #endif

      #if(COM_RAM16BIT_INIT == STD_ON)
      if(LpTxIpdu->usRamInit16BitSize > COM_ZERO)
      {
        memcpy(&Com_GaaRamInit16Bit[LpTxIpdu->ulRamInit16BitStartIdx], 
          &Com_GaaRamInit16BitCpy[LpTxIpdu->ulRamInit16BitStartIdx], LpTxIpdu->usRamInit16BitSize);
      }
      #endif

      #if(COM_RAM32BIT_INIT == STD_ON)
      if(LpTxIpdu->usRamInit32BitSize > COM_ZERO)
      {
        memcpy(&Com_GaaRamInit32Bit[LpTxIpdu->ulRamInit32BitStartIdx], 
          &Com_GaaRamInit32BitCpy[LpTxIpdu->ulRamInit32BitStartIdx], LpTxIpdu->usRamInit32BitSize);
      }
      #endif
      #endif//(COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON)
    }
    else
    {
      Com_GaaTxIpduStatusBit[LddTxPduId] &= 
                                              ((COM_TX_TMS_STATUS_MASK) |
                                              (COM_TX_PT_STATUS_MASK) |
                                              (COM_TX_RETRY_STATUS_MASK));
    }

    #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT==STD_ON))
    LblFilterResult = COM_TRUE;

    #if(COM_TX_IPDU_TMS_EXPLICIT == STD_ON)
    if(LpTxIpdu->ucTxConfigExtn == COM_TRUE)
    {
      LblFilterResult = (boolean)(Com_GaaTxIpduStatusBit[LddTxPduId] & COM_TX_TMS_STATUS_MASK);
    }
      #endif
      
    #if(COM_TX_IPDU_TMS_SIG_BASED == STD_ON)
    if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) != COM_FALSE)
    {
      LblFilterResult = COM_FALSE;
      LpTxModeSelect = LpTxIpdu->pTxModeSelect;
      /* Get the pointer to filter status */
	  /* polyspace +1 RTE:IDP [Not a defect: Justify with annotations] "Configured memory access index" */	
      LucFilterStatusIndex = LpTxModeSelect->ucFilterStatusIndex;
      LpFilterStatus =
            &Com_GaaFilterStatus[LucFilterStatusIndex];
      /* Get the counter */
      LucFilterStsCount = LpTxModeSelect->ucFilterStatusCount;
      /* Loop for all the signals configured for filtering */
      do
      {
        /* Decrement the filter status count */
        LucFilterStsCount--;
        /* Check whether filter status is set to true */
        if(*LpFilterStatus != COM_ZERO)
        {
          /* Set filter status count to zero to break the loop */
          LucFilterStsCount = COM_ZERO;
          /* Set the return value to true */
          LblFilterResult = COM_TRUE;
    
        } /* if(*LpFilterStatus != COM_ZERO) */
         
        /* Increment the filter status pointer to point to n
           filter status area */
        LucFilterStatusIndex++;
        LpFilterStatus =
            &Com_GaaFilterStatus[LucFilterStatusIndex];         
      }while(LucFilterStsCount != COM_ZERO);
    }
    #endif

    #if(COM_TX_IPDU_PT == STD_ON) 
    if((Com_GaaTxIpduStatusBit[LddTxPduId]&COM_TX_TMS_STATUS_MASK) != LblFilterResult)
    {
      /* Get the pointer to Tx Mode */
      LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex]; 
        
      if(COM_FALSE == LblFilterResult)
      {
        LpTxMode = 
        &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
        +(PduIdType)COM_ONE];
      } 
      if(((LpTxMode->ucTxMode) <= COM_TX_MIXEDNTIMES_MODE) &&
                       ((LpTxMode->ucTxMode) != COM_TX_NONE_MODE))
      {
        #if(COM_INVALID_PERIODIC_TIMER_INDEX_EXIST == STD_ON)
        if(LpTxIpdu->ddTxPeriodicTimerIndex < COM_TX_PERIOD_TIMER_COUNT)
        #endif
        {
          /* Load the the periodic timer with offset value */
          Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] =
                                      (LpTxMode->usOffsetValue);
        }
      } /* Check whether Tx mode of the I-PDU is periodic or mixed */
    }
    #endif    

    Com_GaaTxIpduStatusBit[LddTxPduId] 
       &= (uint16)(~COM_TX_TMS_STATUS_MASK);
    Com_GaaTxIpduStatusBit[LddTxPduId] 
       |= LblFilterResult;
    #else
    Com_GaaTxIpduStatusBit[LddTxPduId] 
      |= (COM_TX_TMS_STATUS_MASK);          
    #endif
      
    if(COM_TRUE == Initialize)
    {
      #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_PT == STD_ON) \
      ||(COM_TX_IPDU_DM == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
      /* Get the pointer to Tx Mode */
      LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
      #endif  
      #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_PT == STD_ON)\
      ||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
      if(COM_FALSE == 
      (Com_GaaTxIpduStatusBit[LddTxPduId] & COM_TX_TMS_STATUS_MASK))
      {
        if((LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE) < COM_TX_MODE_COUNT){
        LpTxMode = 
        &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
        +(PduIdType)COM_ONE];
        }
      }
      #endif  
      #if (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
      #if (COM_MDT_NOT_CONFIGURED_EXIST == STD_ON)
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) 
        != COM_FALSE)
      #endif
      {
        #if (COM_MDT_NOT_CONFIGURED_EXIST == STD_ON)
        if(LpTxIpdu->ddTxMDTimerIndex < COM_TX_IPDU_MDT_COUNT)
        #endif
        {
          Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] = (uint16)COM_ZERO;
        }
      }
      #endif  
      #if((COM_TX_SIGNAL_UB == STD_ON) || \
                     (COM_TX_SIGGROUP_UB == STD_ON))
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_UB_CONFIG_MASK) != COM_FALSE)
      {
        Com_TxClearUpdateBit(LpTxIpdu,
               Com_GaaTxPduInfoPtr[LddTxPduId].SduDataPtr);
      }
      #endif
      #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
      if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
      {
        LpTxIpduCounter 
          = &Com_GaaTxIpduCounter[LpTxIpdu->ddTxIpduCounter];
        Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] &=
                 (uint8)(~(LpTxIpduCounter->ucTxIpduCntWrpMask));
       }
      #endif
      #if(COM_TX_IPDU_DM == STD_ON)
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
      {
        Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] = (uint16)COM_ZERO;
        if((((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) == COM_FALSE)
          #if(COM_TX_IPDU_TMS_EXPLICIT == STD_ON)
          ||(LpTxIpdu->ucTxConfigExtn == COM_FALSE)
          #endif
          )&& (LpTxMode->ucTxMode == COM_TX_NONE_MODE))
        {
           Com_GaaTxIpduStatusBit[LddTxPduId] 
              |= COM_TX_DM_STATUS_MASK;
        }
      }
      #endif  
      #if(COM_TX_IPDU_PT == STD_ON) 
      #if((COM_DIRECT_MESSAGE == STD_ON) || (COM_DIRECT_NTIMES_MESSAGE == STD_ON))
      if(((LpTxMode->ucTxMode) <= COM_TX_MIXEDNTIMES_MODE) &&
              ((LpTxMode->ucTxMode) != COM_TX_NONE_MODE))
      #endif
      {
        #if(COM_INVALID_PERIODIC_TIMER_INDEX_EXIST == STD_ON)
        if(LpTxIpdu->ddTxPeriodicTimerIndex < COM_TX_PERIOD_TIMER_COUNT)
        #endif
        {        
          /* Load the the periodic timer with offset value */
          Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] =
                            (LpTxMode->usOffsetValue);
        }
      } /* Check whether Tx mode of the I-PDU is periodic or mixed */
      #endif  
      #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON) && (COM_FILTER_ONEEVERYN == STD_ON))
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
        != COM_FALSE)
      {
        LucFilterStsCount = COM_NO_OF_FILTER_ONEVERYN;
        do
        {
          --LucFilterStsCount;
          if(Com_GaaFilterOneEveryN[LucFilterStsCount].ddComPduId ==
                                                          LddTxPduId)
          {
            #if(COM_RX_SIGNAL_FILTER == STD_ON)
            if(Com_GaaFilterOneEveryN[LucFilterStsCount].ucFltrStsMask
                                                           != COM_ZERO)
            #endif
            {
              *Com_GaaFilterOneEveryN[LucFilterStsCount].pCounter =
                                                               (uint16)COM_ZERO;
            }
          }
        }while(LucFilterStsCount != COM_ZERO);
      }
      #endif
    } /* if(Initialize == COM_TRUE) */

    #if(COM_TX_IPDU_DM == STD_ON)
    #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
    if((COM_FALSE == (LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK))
       ||(COM_FALSE == LpTxIpdu->ucTxConfigExtn))
    #endif
    {
      LpTxModeTrue = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
      #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
      LpTxModeFalse = LpTxModeTrue;
      #endif
      #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
      if((((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK)!= COM_ZERO)
         ||(LpTxIpdu->ucTxConfigExtn!=COM_FALSE))&& 
         ((Com_GaaTxIpduStatusBit[LddTxPduId]&COM_TX_TMS_STATUS_MASK) != COM_ZERO))
      { 
        LpTxModeFalse = 
        &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
        +(PduIdType)COM_ONE];    
      }
      #endif
      if((COM_TX_NONE_MODE == LpTxModeTrue->ucTxMode) &&
        (((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
        != COM_FALSE)
        #if(COM_TX_IPDU_TMS_EXPLICIT == STD_ON)
        ||(LpTxIpdu->ucTxConfigExtn != COM_FALSE)
        #endif
        ))
      {
        #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON)||(COM_TX_IPDU_TMS_EXPLICIT == STD_ON))
        if(COM_TX_NONE_MODE == LpTxModeFalse->ucTxMode)
        #endif
        {
          Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
          Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout 
          + (uint16)COM_ONE;
          /* Set Request bit */
          Com_GaaTxIpduStatusBit[LddTxPduId] 
            |= COM_TX_REQ_STATUS_MASK;
        }
      }
    }
    #endif

    #if(COM_TX_IPDU_REPETITION == STD_ON)
    if(LpTxIpdu->ddTxReptIndex < COM_TX_REPT_COUNT)
    { 
      Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] = (uint16)COM_ZERO;
      Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] = COM_ZERO;
      Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] = COM_ZERO;
    }
    #endif
    /* #1632 : Initialize TP status */
    #if(COM_TX_TP_SUPPORT == STD_ON)
    /* Get the pointer to Tx Ipdu */
    if(LpTxIpdu->ucTxTPRef != COM_INVALID_PARAM)
    {
      LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
      Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] &= 
                           (uint8)~(LpTxTPIpdu->ucTxTPStatusMask);
    }
    #endif
  }
  
  if((Com_GaaTxIpduStatus[LddTxPduId] < Com_GaaTxIpduNoOfGrp[LddTxPduId])
     || ((uint16)COM_ZERO == Com_GaaTxIpduNoOfGrp[LddTxPduId]))
  {
    Com_GaaTxIpduStatus[LddTxPduId]++;
  }
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_StartRxIpdu                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function starts Rx I-PDU                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU                       **
**                        Non-Reentrant for same I-PDU                        **
**                                                                            **
** Input Parameters     : IpduId, Initialize                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxIpduStatus        **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxTPStatus          **
**                                                 Com_GaaRxTPIpdu            **
**                                                 Com_GaaRamIpduRepliSts     **
**                                                 Com_GaaRxRepliCount        **
**                                                 Com_GaaRxIpduReplication   **
**                                                 Com_GaaRamIpduCounterSts   **
**                                                 Com_GaaRxIpduCountVal      **
**                                                 Com_GaaRxIpduCounter       **
**                                                 Com_GaaRxDmStatus          **
**                                                 Com_GaaRxDm                **
**                                                 Com_GaaRxDMTimer           **
**                                                 Com_GaaFilterOneEveryN     **
**                                                                            **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if(COM_RX_IPDU == STD_ON)
#if(COM_RX_IPDU_NOTINCL_COUNT > COM_MACRO_ZERO)	
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_StartRxIpdu(PduIdType IpduId, boolean Initialize)
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_StartRxIpdu(PduIdType IpduId, boolean Initialize)
#endif
{
  PduIdType LddRxPduId = IpduId;
  #if((COM_RX_IPDU_DM == STD_ON) || \
    (COM_RX_SIGNAL_UBDM == STD_ON) || \
    (COM_RX_SIGGROUP_UBDM == STD_ON) || \
    (COM_RX_IPDU_COUNTER_ENABLED == STD_ON) || \
    (COM_RX_TP_SUPPORT == STD_ON) || \
    (COM_RX_REPLICATION == STD_ON) || \
    (COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON))
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  #endif   
  #if((COM_FILTER_ONEEVERYN == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
  uint8 LucFilterStsCount;
  #endif
  #if((COM_RX_IPDU_DM == STD_ON) || \
    (COM_RX_SIGNAL_UBDM == STD_ON) || \
    (COM_RX_SIGGROUP_UBDM == STD_ON))
  P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm;
  PduIdType LddRxDmTimerIndex;
  uint8 LucCount;
  #endif  
  #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
  P2CONST(Com_RxIpduCounter, AUTOMATIC, COM_CONST) LpRxIpduCounter;
  #endif
  #if(COM_RX_REPLICATION == STD_ON)
  P2CONST(Com_RxIpduReplication, AUTOMATIC, COM_CONST) LpRxIpduRepli;
  #endif 
  #if(COM_RX_TP_SUPPORT == STD_ON)  
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #endif 

  if((uint16)COM_ZERO == Com_GaaRxIpduStatus[LddRxPduId])
  { 
    #if((COM_RX_IPDU_DM == STD_ON) || \
      (COM_RX_SIGNAL_UBDM == STD_ON) || \
      (COM_RX_SIGGROUP_UBDM == STD_ON) || \
      (COM_RX_IPDU_COUNTER_ENABLED == STD_ON) || \
      (COM_RX_TP_SUPPORT == STD_ON) || \
      (COM_RX_REPLICATION == STD_ON) || \
      (COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON))
    LpRxIpdu = &Com_GaaRxIpdu[LddRxPduId];
    #endif          

    if(COM_TRUE == Initialize)
    {
      /* Initialize Buffer */ 
      #if(COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON)
      #if(COM_RAM8BIT_INIT == STD_ON)
      memcpy(&Com_GaaRamInit8Bit[LpRxIpdu->ulRamInit8BitStartIdx], 
        &Com_GaaRamInit8BitCpy[LpRxIpdu->ulRamInit8BitStartIdx], LpRxIpdu->usRamInit8BitSize);
      #endif

      #if(COM_RAM16BIT_INIT == STD_ON)
      if(LpRxIpdu->usRamInit16BitSize > COM_ONE)
      {
        memcpy(&Com_GaaRamInit16Bit[LpRxIpdu->ulRamInit16BitStartIdx], 
          &Com_GaaRamInit16BitCpy[LpRxIpdu->ulRamInit16BitStartIdx], LpRxIpdu->usRamInit16BitSize);
      }
      #endif

      #if(COM_RAM32BIT_INIT == STD_ON)
      if(LpRxIpdu->usRamInit32BitSize > COM_ONE)
      {
        memcpy(&Com_GaaRamInit32Bit[LpRxIpdu->ulRamInit32BitStartIdx], 
          &Com_GaaRamInit32BitCpy[LpRxIpdu->ulRamInit32BitStartIdx], LpRxIpdu->usRamInit32BitSize);
      }
      #endif
      #endif//(COM_BUFFER_INITIATE_ON_PDU_START_TIME == STD_ON)
      
      #if((COM_FILTER_ONEEVERYN == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
      if(((Com_GaaRxIpdu[LddRxPduId].ucRxConfig &
        COM_RX_ONEVERYN_CONFIG_MASK) != COM_FALSE))
      {
        LucFilterStsCount = COM_NO_OF_FILTER_ONEVERYN;
        do
        {
          --LucFilterStsCount;
          #if(COM_TX_IPDU_TMS_SIG_BASED == STD_ON)
          if(Com_GaaFilterOneEveryN[LucFilterStsCount].ddComPduId ==
                                             LddRxPduId)
          #endif
          {
            #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON) \
            && (COM_NO_OF_FILTER_ONEVERYN > COM_MACRO_ZERO))
            if(COM_ZERO 
              == Com_GaaFilterOneEveryN[LucFilterStsCount].ucFltrStsMask)
            #endif
            {                 
              *Com_GaaFilterOneEveryN[LucFilterStsCount].pCounter 
                = (uint16)COM_ZERO;
            }
          }
        }while(LucFilterStsCount != COM_ZERO);
      }
      #endif
      #if((COM_RX_IPDU_DM == STD_ON) || \
        (COM_RX_SIGNAL_UBDM == STD_ON) || \
        (COM_RX_SIGGROUP_UBDM == STD_ON))
      if((Com_GaaRxIpdu[LddRxPduId].ucRxConfig & COM_RX_DM_CONFIG_MASK) != COM_FALSE)
      {
        if(((uint16)COM_ZERO == 
                    Com_GaaRxDmStatus[Com_GaaRxIpdu[LddRxPduId]
                    .ddRxIpduDmIndex]))
        {
          LddRxDmTimerIndex = LpRxIpdu->ddRxIpduDmIndex;
          LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
          LucCount = LpRxDm->ucRxDmCount;
          do
          {
            Com_GaaRxDMTimer[LddRxDmTimerIndex] 
              = LpRxDm->ulRxDmFirstTimeout;
            --LucCount;
            LddRxDmTimerIndex++;
            LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
          }while(LucCount != COM_ZERO);
        }
      }
      #endif
      
      #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
      if((LpRxIpdu->ddRxIpduCounter != COM_INVALID_RXID_PARAM))
      {
        LpRxIpduCounter 
          = &Com_GaaRxIpduCounter[LpRxIpdu->ddRxIpduCounter];
        Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData] &=
        (uint8)(~(LpRxIpduCounter->ucRxIpduCntWrpMask));
        Com_GaaRamIpduCounterSts[LpRxIpduCounter->ucIpduCnterStsIndex] &=
        (uint8)(~(LpRxIpduCounter->ucIpduCounterEnMask));
      }
      #endif
      
      #if(COM_RX_REPLICATION == STD_ON)
      if((LpRxIpdu->ucRxIpduRepliIndex != COM_INVALID_NONE))
      {
        LpRxIpduRepli 
          = &Com_GaaRxIpduReplication[LpRxIpdu->ucRxIpduRepliIndex];
        Com_GaaRxRepliCount[LpRxIpduRepli->ucIpduRepliCountIndex] &=
        (uint8)(~(uint8)((COM_REPLICATION_MASK <<
        (COM_EIGHT - (LpRxIpduRepli->ucIpduRepliCountShift)))));
        Com_GaaRamIpduRepliSts[LpRxIpduRepli->ucIpduRepliStsIndex] &=
        (uint8)(~(LpRxIpduRepli->ucIpduRepliEnMask));
      }
      #endif
    }
    /* #1632 : Initialize TP status */
    #if(COM_RX_TP_SUPPORT == STD_ON)
    /* Get the pointer to Rx Ipdu */
    if(LpRxIpdu->ucRxTPRef != COM_INVALID_PARAM)
    {
      /* Get the pointer to Rx TP structure */
      LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
      Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
        &= (uint8)(~(LpRxTPIpdu->ucRxTPStatusMask));
    }
    #endif          
  }
  if((Com_GaaRxIpduStatus[LddRxPduId] < Com_GaaRxIpduNoOfGrp[LddRxPduId])
    || ((uint16)COM_ZERO == Com_GaaRxIpduNoOfGrp[LddRxPduId]))
  {
    ++Com_GaaRxIpduStatus[LddRxPduId];
  }
  
  #if(COM_RX_IPDU_DM == STD_ON)
  if((Com_GaaRxIpdu[LddRxPduId].ucRxConfig & COM_RX_DM_CONFIG_MASK) != COM_FALSE)
  {
    if((Com_GaaRxDmStatus[Com_GaaRxIpdu[LddRxPduId]
      .ddRxIpduDmIndex] < Com_GaaRxIpduNoOfGrp[LddRxPduId])
      || ((uint16)COM_ZERO == Com_GaaRxIpduNoOfGrp[LddRxPduId]))
    {
      Com_GaaRxDmStatus[Com_GaaRxIpdu[LddRxPduId]
        .ddRxIpduDmIndex]++;
    }
  }
  #endif
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_StartIpduGroup                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function starts a pre-configured I-PDU group.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId, Initialize                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaIpduGroup           **
**                                                 Com_GaaIpduGrpEnStatus     **
**                                                 Com_GaaIpduGrpDmStatus     **
**                                                 Com_GaaTxIpduGroup         **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaRxIpduGroup         **
**                                                 Com_GaaRxIpduStatus        **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_StartIpduGroup(Com_IpduGroupIdType IpduGroupId,
  boolean Initialize)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  PduIdType LddPduIndex;
  PduIdType LddIpduHandleId;
  /* Local variable to store no. Of Ipdus */
  PduIdType LddNoOfIpdus;
  Com_IpduGroupIdType LddIpduGroupId;

  LddIpduGroupId = IpduGroupId;
  /* Get the pointer to the I-PDU group structure */
  LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
  /* Get the number of I-PDU Group */
  /* Enable Ipdu Group Status */
  Com_GaaIpduGrpEnStatus[LpIpduGroup->usGroupIndex] |=
                                             (LpIpduGroup->ucStatusMask);
  /* Enable Ipdu Group Status */
  Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] |=
                                             (LpIpduGroup->ucStatusMask);

  #if(COM_TX_IPDU == STD_ON)
  /* Get the number of Tx I-PDUs  */
  LddNoOfIpdus = (PduIdType) LpIpduGroup->ddNoOfTxIpdus;
  LddPduIndex = (PduIdType) LpIpduGroup->ddTxIpduIndex;

  /* Loop for all Tx PDUs belong to that group */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    --LddNoOfIpdus;
    LddIpduHandleId = (PduIdType)Com_GaaTxIpduGroup[LddPduIndex];
	LddPduIndex++;

    Com_StartTxIpdu(LddIpduHandleId, Initialize);    
  }
  #endif /* #if(COM_TX_IPDU == STD_ON) */

  #if(COM_RX_IPDU == STD_ON)
  /* Get the number of Tx I-PDUs  */
  LddNoOfIpdus = (PduIdType) LpIpduGroup->ddNoOfRxIpdus;
  /* Get the group index */
  LddPduIndex = (PduIdType) LpIpduGroup->ddRxIpduIndex;

  /* Loop for all Rx PDUs */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    --LddNoOfIpdus;
	LddIpduHandleId = (PduIdType)Com_GaaRxIpduGroup[LddPduIndex];	
	LddPduIndex++;
		
    Com_StartRxIpdu(LddIpduHandleId, Initialize);
  }
  #endif
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_StopIpduGroup                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Internal function stops a                      **
**                        pre-configured I-PDU group.                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaIpduGroup           **
**                                                 Com_GaaIpduGrpEnStatus     **
**                                                 Com_GaaTxIpduGroup         **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxIpduConfirm       **
**                                                 Com_GaaSigErrorCbk         **
**                                                 Com_GaaTxIpduCounter       **
**                                                 Com_GaaTxIpduCountVal      **
**                                                 Com_GaaRxIpduGroup         **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaIpduGrpDmStatus     **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxDmStatus          **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 pSigErrorCbk               **
**                                                 Com_TxZeroCounterUpdate()  **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_StopIpduGroup(Com_IpduGroupIdType IpduGroupId)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  #if(COM_TX_IPDU_ERRORNOTIFY == STD_ON)
  /* Pointer to Tx Ipdu confirm structure */
  P2CONST(Com_TxIpduConfirm, AUTOMATIC, COM_CONST) LpTxIpduConfirm;
  /* Pointer to signal error Call back structure */
  P2CONST(Com_SigErrorCbk, AUTOMATIC, COM_CONST) LpSigErrorCbk;
  #endif
  #if((COM_TX_IPDU_ERRORNOTIFY == STD_ON) || \
    (COM_TX_IPDU_COUNTER_ENABLED == STD_ON))
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  #endif
  #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
  P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter;
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
  uint8 LucTxIpduCntVal;  
  #endif
  /* Local variable to store no. Of Ipdus */
  PduIdType LddNoOfIpdus;
  /* Local variable to store Com Ipdu handle ID */

  PduIdType LddPduIndex;
  PduIdType LddIpduHandleId;
  #if(COM_TX_IPDU_ERRORNOTIFY == STD_ON)
  uint8 LddNoOfCount;
  Com_ErrCbkCountType LddSigErrorCbkIndex;
  #endif  
  /* Get the pointer to the I-PDU group structure */
  LpIpduGroup = &Com_GaaIpduGroup[IpduGroupId];
  /* Enable Ipdu Group Status */
  Com_GaaIpduGrpEnStatus[LpIpduGroup->usGroupIndex] &=
                                      (uint8)(~(LpIpduGroup->ucStatusMask));
  #if(COM_TX_IPDU == STD_ON)
  /* Get the number of Tx I-PDUs  */
  LddNoOfIpdus = (PduIdType) LpIpduGroup->ddNoOfTxIpdus;
  LddPduIndex = (PduIdType) LpIpduGroup->ddTxIpduIndex;
  /* Loop for all PDUs */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    --LddNoOfIpdus;
    LddIpduHandleId = (PduIdType)Com_GaaTxIpduGroup[LddPduIndex];
    LddPduIndex++;
    /* change the status */
	if((uint16)COM_ZERO < Com_GaaTxIpduStatus[LddIpduHandleId])
	{
      Com_GaaTxIpduStatus[LddIpduHandleId]--;
	}
	
    if((uint16)COM_ZERO == Com_GaaTxIpduStatus[LddIpduHandleId])
    {
      #if((COM_TX_IPDU_ERRORNOTIFY == STD_ON) || \
      (COM_TX_IPDU_COUNTER_ENABLED == STD_ON))
      /* Get the pointer to Tx Ipdu */
      LpTxIpdu = &Com_GaaTxIpdu[LddIpduHandleId];
      #endif
      #if(COM_TX_IPDU_ERRORNOTIFY == STD_ON)
      if((Com_GaaTxIpduStatusBit[LddIpduHandleId] &
                                     COM_TX_REQ_STATUS_MASK) != COM_FALSE)
      {            
        if(LpTxIpdu->ddTxPduConfirmIndex != COM_INVALID_TXID_PARAM)
        {
          /* Get the pointer to Tx Confirmation Structure */
          LpTxIpduConfirm =
                     &Com_GaaTxIpduConfirm[LpTxIpdu->ddTxPduConfirmIndex];
          /* Get the number of signals configured for call-back
             notification */
          LddNoOfCount = LpTxIpduConfirm->ucNoOfSigErrorCbk;
          /* Check whether number of signal call-back notification
          count is not equal to zero */
					/* polyspace<DEFECT:USELESS_IF : Not a defect: Justify with annotations> Condition will be executed based on the configured values */
          if(LddNoOfCount != COM_ZERO)
          {
            /* Get the pointer to SigErrorCbk structure */
            LddSigErrorCbkIndex = LpTxIpduConfirm->ddSigErrCbkIndex;
            LpSigErrorCbk = &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];

            SchM_Exit_Com_IPDU_GROUP_STATUS_PROTECTION();
            /* Loop for all the signals configured for timeout error
            notification */
            do
            {
              /* Invoke the error notification function  */
              (LpSigErrorCbk->pSigErrorCbk)();

              /* Get the pointer to n SigErrorCbk structure */
              LddSigErrorCbkIndex++;
              LpSigErrorCbk =
                 &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
              /* Decrement the signal error notification
              call-back count */
              LddNoOfCount--;
            }while(LddNoOfCount != COM_ZERO);
            SchM_Enter_Com_IPDU_GROUP_STATUS_PROTECTION();

          } /* Check whether number of error callback is configured */
        }
      } /* Check whether Tx Request bit is set to true */
      #endif /*#if(COM_TX_IPDU_ERRORNOTIFY == STD_ON))*/
      
      #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
      if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
      {
        /* Get the pointer to Tx I-PDU counter structure */
        LpTxIpduCounter = 
          &Com_GaaTxIpduCounter[LpTxIpdu->ddTxIpduCounter];
        Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] = 
              COM_ZERO;
        
        /* Get the pointer to TxPack structure */
        LpTxPack = &Com_GaaTxPack[LpTxIpduCounter->ddTxPackIndex];
        /* Get the present counter data */
        LucTxIpduCntVal = 
          Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData];
        
        /* Apply wrap around mask to the counter data */
        LucTxIpduCntVal &= LpTxIpduCounter->ucTxIpduCntWrpMask;
        
        /* Invoke write function to pack counter data to I-PDU buffer */
        (void)Com_PackRequestWrite(LpTxPack,
        (P2CONST(void, AUTOMATIC, COM_CONST))&LucTxIpduCntVal);
        
        /* Load present counter data in buffer */
        Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] = 
        LucTxIpduCntVal;
      }
      #endif
    }
  }
  #endif
  #if(COM_RX_IPDU == STD_ON)
  /* Get the number of Rx I-PDUs  */
  LddNoOfIpdus = (PduIdType) LpIpduGroup->ddNoOfRxIpdus;
  LddPduIndex = (PduIdType) LpIpduGroup->ddRxIpduIndex;
  /* Loop for all PDUs */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    LddIpduHandleId = (PduIdType)Com_GaaRxIpduGroup[LddPduIndex];
    --LddNoOfIpdus;
    LddPduIndex++;
    if((uint16)COM_ZERO < Com_GaaRxIpduStatus[LddIpduHandleId])
    {
      Com_GaaRxIpduStatus[LddIpduHandleId]--;
    }
  }
  #if((COM_RX_IPDU_DM == STD_ON) || \
      (COM_RX_SIGNAL_UBDM == STD_ON) || \
      (COM_RX_SIGGROUP_UBDM == STD_ON))
  /* Check whether requested I-PDU group is active for Deadline
     monitoring */
  if((Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] &
                              (LpIpduGroup->ucStatusMask)) != COM_FALSE)
  {
    /* Enable Ipdu Group Status */
    Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] &=
                                      (uint8)(~(LpIpduGroup->ucStatusMask));
    /* Get the number of Rx I-PDUs  */
    LddNoOfIpdus = (PduIdType) LpIpduGroup->ddNoOfRxIpdus;

    LddPduIndex = (PduIdType) LpIpduGroup->ddRxIpduIndex;
    /* Loop for all PDUs */
    while(LddNoOfIpdus != (PduIdType)COM_ZERO)
    {
      LddIpduHandleId = Com_GaaRxIpduGroup[LddPduIndex];
      --LddNoOfIpdus;
      LddPduIndex++;
      if((Com_GaaRxIpdu[LddIpduHandleId].ucRxConfig &
                                      COM_RX_DM_CONFIG_MASK) != COM_FALSE)
      {
        if((uint16) COM_ZERO < Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduHandleId].ddRxIpduDmIndex])
        {
          Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduHandleId].ddRxIpduDmIndex]--;
        }
      }
    }
  } /* Check whether deadline monitoring is active */
  #endif /* Dead line Monitoring */
  #endif
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_SetIpduGroup                                    **
**                                                                            **
** Service ID           : 0x1D                                                **
**                                                                            **
** Description          : This function will set and reset the bit position of**
**                        I-PDU group in the group vector groups.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : , ipduGroupId, bitVal                               **
**                                                                            **
** InOut parameter      : ipduGroupVector                                     **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaIpduGroup              **
**                        Function(s) invoked : Det_ReportError()             **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_SetIpduGroup(Com_IpduGroupVector
  ipduGroupVector, Com_IpduGroupIdType IpduGroupId, boolean bitval)
{
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue;
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SETIPDUGROUP);
  /* Check whether I-PDU group ID is out of range */
  COM_DET_IPDUGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_SETIPDUGROUP);
  /* Check whether ipduGroupVector is equal to NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_SETIPDUGROUP);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Get the pointer to I-PDU structure */
    LpIpduGroup = &Com_GaaIpduGroup[IpduGroupId];

    /* If bitval is true set ipduGroupVector */
	/* polyspace:begin<MISRA-C3:D4.14 :: Not a defect Justify with annotations> Array size is valid range*/
    if(COM_TRUE == bitval)
    {
      /* Set the bit of corresponding ipduGroupId in the ipduGroupVector */
      ipduGroupVector[LpIpduGroup->usGroupIndex] |= LpIpduGroup->ucStatusMask;
    }
    /* If bitval is false reset ipduGroupVector */
    else
    {
      /* Reset the bit of corresponding ipduGroupId in the ipduGroupVector */
      ipduGroupVector[LpIpduGroup->usGroupIndex] &=  
                                            (uint8)(~LpIpduGroup->ucStatusMask);
    }
	/* polyspace:end<MISRA-C3:D4.14 :: Not a defect Justify with annotations> Array size is valid range*/
  } /* if(LblDetErrFlag == COM_FALSE) */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_ClearIpduGroupVector                            **
**                                                                            **
** Service ID           : 0x1C                                                **
**                                                                            **
** Description          : This function sets all bits of the given            **
**                        ipduGroupVector to 0                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : ipduGroupVector                                     **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Det_ReportError()             **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_ClearIpduGroupVector(Com_IpduGroupVector
  ipduGroupVector)
{
  uint16 LusVectArrIndex;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue;
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_CLEARIPDUGROUPVECTOR);
  /* Check whether ipduGroupVector is equal to NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_CLEARIPDUGROUPVECTOR);

  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Set ipduGroupVector to Zero */
    for(LusVectArrIndex = COM_ZERO;
      LusVectArrIndex < COM_IPDU_GRP_VECTOR_SIZE; LusVectArrIndex++)
    {
      /* Initialize IpduGroupVector with Zero */
	  /* polyspace<MISRA-C3:D4.14::Not a defect Justify with annotations> Not a defect */
      ipduGroupVector[LusVectArrIndex] = COM_ZERO;
    }
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_IpduGroupControl                                **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function starts and stops pre-configured I-PDU **
**                        groups.                                             **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ipduGroupVector, initialize                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaIpduGroup              **
**                        Function(s) invoked : Det_ReportError()             **
**                                              Com_StartIpduGroup()          **
**                                              Com_StopIpduGroup()           **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
/* polyspace +3 MISRA-C3:8.13 [Not a Defect:Low] "Com_IpduGroupVector type is the prototype specified in the 
AUTOSAR specification. Part of the code is verfied manually and it has no impact" */
FUNC (void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector
  ipduGroupVector, boolean initialize)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  uint16 LusVectArrIndex;
  uint8 LucGrpStsByte;
  uint8 LucBitPosition;
  Com_IpduGroupIdType LddIpduGroupId;

  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_IPDUGROUPCONTROL);
  /* Check if the "Vector" is NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_IPDUGROUPCONTROL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    LusVectArrIndex = COM_ZERO;
    
    while(LusVectArrIndex < COM_IPDU_GRP_VECTOR_SIZE)
    {
      LucBitPosition = COM_ZERO;
      SchM_Enter_Com_IPDU_GROUP_STATUS_PROTECTION();
      /* Get the difference between the requested Ipdu group
         states and the current state*/
	  /* polyspace<MISRA-C3:D4.14 :: Not a defect Justify with annotations> Array size is valid range*/	 
      LucGrpStsByte = ipduGroupVector[LusVectArrIndex];
      /* Check if there is a change */
      while(LucBitPosition < COM_EIGHT)
      {
        /* Get the I-PDU group Id for which status is changed */
        LddIpduGroupId = (LusVectArrIndex * COM_EIGHT) + LucBitPosition;
        /* Check if the Group Id is valid */
        #if((COM_IPDUGROUP_COUNT % 8) != 0)
        if(LddIpduGroupId <= ((Com_IpduGroupIdType)COM_IPDUGROUP_COUNT - COM_ONE))
        #endif
        {
          /* Get the pointer to the I-PDU group structure */
          LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
          
          /* This check is useful in case of a "super" group Ipdu */
          /* If the group was disable earlier and is now enabled */
          if(COM_TRUE == (LucGrpStsByte & (COM_ONE)))
          {
            /* If the super group is enabled we have to enable all
            the groups contained */

            if((Com_GaaIpduGrpEnStatus[LpIpduGroup->usGroupIndex] &
                                  (LpIpduGroup->ucStatusMask)) == COM_FALSE)
            {
              Com_StartIpduGroup(LddIpduGroupId, initialize);
            }           
		
            LucGrpStsByte = LucGrpStsByte >> 1;
            LucBitPosition += 1;
          }
          else
          {
             /* stops only one Ipdu group since an Ipdu can be
             stopped only if it is stopped in all the Ipdu Groups
             it is contained in */
            if((Com_GaaIpduGrpEnStatus[LpIpduGroup->usGroupIndex] &
                                    (LpIpduGroup->ucStatusMask)) != COM_FALSE)
            {
              Com_StopIpduGroup(LddIpduGroupId);
            }
            LucGrpStsByte = LucGrpStsByte >> 1;
            LucBitPosition += 1;
          }
        }
        #if((COM_IPDUGROUP_COUNT % 8) != 0)
        else
        {
          /* Break out of the loop */
          LusVectArrIndex = COM_IPDU_GRP_VECTOR_SIZE;
          LucBitPosition = COM_EIGHT;
        }
        #endif
      }
      SchM_Exit_Com_IPDU_GROUP_STATUS_PROTECTION();
      LusVectArrIndex++;
    }
  }
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
/* polyspace +3 MISRA-C3:8.13 [Not a Defect:Low] "Com_IpduGroupVector type is the prototype specified in the 
AUTOSAR specification. Part of the code is verfied manually and it has no impact" */
FUNC (void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector
  ipduGroupVector, boolean initialize)
{
  COM_UNUSED_PTR(ipduGroupVector);
  COM_UNUSED(initialize);  
  /* #1204 : Dummy Function for integration with BswM Module */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_EnableRxDM                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function enables the reception deadline        **
**                        monitoring for the I-PDU(s) within the requested    **
**                        Rx I-PDU group.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :Com_GaaIpduGroup            **
**                                                Com_GaaIpduGrpDmStatus      **
**                                                Com_GaaRxIpduGroup          **
**                                                Com_GaaRxIpdu               **
**                                                Com_GaaRxDmStatus           **
**                                                Com_GaaRxDm                 **
**                                                Com_GaaRxDMTimer            **
**                        Function(s) invoked    :SchM_Enter_xxx()            **
**                                                SchM_Exit_xxx()             **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
     (COM_RX_SIGNAL_UBDM == STD_ON) || \
     (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_EnableRxDM(Com_IpduGroupIdType IpduGroupId)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  #if(COM_RX_IPDU_DM == STD_ON)
  /* Pointer to RxDm structure */
  P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm;
  #endif
  /* Local variable to store Com Ipdu handle ID */
  PduIdType LddIpduIndex;
  PduIdType LddPduIndex;
  /* Local variable to store no. Of Ipdus */
  PduIdType LddNoOfIpdus;
  #if(COM_RX_IPDU_DM == STD_ON)
  /* Local variable to store RxDm timer index*/
  PduIdType LddRxDmTimerIndex;
  /* Local variable to store count */
  uint8 LucCount;
  #endif

  Com_IpduGroupIdType LddIpduGroupId;

  LddIpduGroupId = IpduGroupId;
  /* Get the pointer to the I-PDU group structure */
  LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
    /* Check whether requested I-PDU group deadline monitoring is stopped */
    if(COM_FALSE == (Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] &
                                      (LpIpduGroup->ucStatusMask)))
    {
      /* Disable Ipdu Group Dm Status */
      Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] |=
                                                    (LpIpduGroup->ucStatusMask);
      /* Get the number of Rx I-PDUs  */
      LddNoOfIpdus = LpIpduGroup->ddNoOfRxIpdus;
      LddPduIndex = (LpIpduGroup->ddRxIpduIndex + LddNoOfIpdus) - 
      (PduIdType)COM_ONE;
      /* Loop for all PDUs */
      while(LddNoOfIpdus != (PduIdType)COM_ZERO)
      {
        LddIpduIndex = Com_GaaRxIpduGroup[LddPduIndex];

        if((Com_GaaRxIpdu[LddIpduIndex].ucRxConfig &
                                            COM_RX_DM_CONFIG_MASK) != COM_FALSE)
        {
          if(((uint16)COM_ZERO ==  
                Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex]))
          {
            LpRxIpdu = &Com_GaaRxIpdu[LddIpduIndex];
            #if(COM_RX_IPDU_DM == STD_ON)
            LddRxDmTimerIndex = LpRxIpdu->ddRxIpduDmIndex;
            if(LddRxDmTimerIndex != COM_INVALID_RXID_PARAM)
            {
              LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
              LucCount = LpRxDm->ucRxDmCount;
              do
              {
                #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
                SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
                #endif
                Com_GaaRxDMTimer[LddRxDmTimerIndex] = LpRxDm->ulRxDmFirstTimeout;
                #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
                SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
                #endif
                --LucCount;
                LddRxDmTimerIndex++;
                LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
              }while(LucCount != COM_ZERO);
              #endif
            }
          }
          if((Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex]
            .ddRxIpduDmIndex] < Com_GaaRxIpduNoOfGrp[LddIpduIndex])
            || ((uint16)COM_ZERO == Com_GaaRxIpduNoOfGrp[LddIpduIndex]))
          {
            Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex]++;
          }
        }
        LddNoOfIpdus--;
        if(LddPduIndex != COM_ZERO) 
        { 
          LddPduIndex--; 
        }    
      }
}
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_DisableRxDM                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function disables the reception deadline       **
**                        monitoring for the I-PDU(s) within the requested    **
**                        Rx I-PDU group.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaIpduGroup           **
**                                                 Com_GaaIpduGrpDmStatus     **
**                                                 Com_GaaRxIpduGroup         **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxDmStatus          **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
     (COM_RX_SIGNAL_UBDM == STD_ON) || \
     (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, COM_CODE) Com_DisableRxDM(Com_IpduGroupIdType IpduGroupId)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  /* Local variable to store Com Ipdu handle ID */
  PduIdType LddIpduIndex;
  PduIdType LddPduIndex;
  /* Local variable to store no Of Ipdus */
  PduIdType LddNoOfIpdus;
  {
    /* Get the pointer to the I-PDU group structure */
    LpIpduGroup = &Com_GaaIpduGroup[IpduGroupId];

    /* Check whether its parent Ipdu Group */
    if((Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] &
                                (LpIpduGroup->ucStatusMask)) != COM_FALSE)
    {
      /* Enable Ipdu Group Status */
      Com_GaaIpduGrpDmStatus[LpIpduGroup->usGroupIndex] &=
                                          (uint8)(~(LpIpduGroup->ucStatusMask));
      /* Get the number of Rx I-PDUs  */
      LddNoOfIpdus = LpIpduGroup->ddNoOfRxIpdus;
      LddPduIndex = (LpIpduGroup->ddRxIpduIndex + LddNoOfIpdus) 
      - (PduIdType)COM_ONE;
      /* Loop for all PDUs */
      while(LddNoOfIpdus != (PduIdType)COM_ZERO)
      {

        LddIpduIndex = Com_GaaRxIpduGroup[LddPduIndex];
        if((Com_GaaRxIpdu[LddIpduIndex].ucRxConfig &
                                          COM_RX_DM_CONFIG_MASK) != COM_FALSE)
        {
          if((uint16)COM_ZERO < Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex])
          {
            Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex]--;
          }
        }
        LddNoOfIpdus--;

        if(LddPduIndex != COM_ZERO) 
        { 
          LddPduIndex--; 
        }      
      }
    } /* Check whether deadline monitoring is active */
  } /* if(LucReturnValue == COM_FALSE) */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_ReceptionDMControl                              **
**                                                                            **
** Service ID           : 0x06                                                **
**                                                                            **
** Description          : This function enables or disables deadline          **
**                        monitoring for Rx I-PDUs in I-PDU Groups            **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ipduGroupVector                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Com_GaaIpduGroup               **
**                        Function(s) invoked :Det_ReportError()              **
**                                             Com_EnableRxDM()               **
**                                             Com_DisableRxDM()              **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
     (COM_RX_SIGNAL_UBDM == STD_ON) || \
     (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin DEFECT:DEAD_CODE [Not a defect:Low] "If-condition is changable depending on the configuration" */
/* polyspace-begin MISRA-C3:2.1 [Not a Defect:Low] "condition will be executed based on the configured values" */
/* polyspace +3 MISRA-C3:8.13 [Not a Defect:Low] "Com_IpduGroupVector type is the prototype specified in the 
AUTOSAR specification. Part of the code is verfied manually and it has no impact" */
FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector
  ipduGroupVector)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  uint16 LusVectArrIndex;
  uint8 LucGrpStsByte;
  uint8 LucBitPosition;
  Com_IpduGroupIdType LddIpduGroupId;

  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEPTIONDMCONTROL);
  /* Check if the "Vector" is NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_RECEPTIONDMCONTROL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    LusVectArrIndex = COM_ZERO;
    
    while(LusVectArrIndex < COM_IPDU_GRP_VECTOR_SIZE)
    {
      LucBitPosition = COM_ZERO;
      SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
      /* Get the difference between the requested Ipdu group
         states and the current state*/
	  /* polyspace<MISRA-C3:D4.14 :: Not a defect Justify with annotations> Array size is valid bounds*/		 
      LucGrpStsByte = ipduGroupVector[LusVectArrIndex];
      /* Check if there is a change */
      while(LucBitPosition < COM_EIGHT)
      {
        /* Get the I-PDU group Id for which status is changed */
        LddIpduGroupId = (LusVectArrIndex * COM_EIGHT) + LucBitPosition;
        /* Check if the Group Id is valid */
        /* polyspace MISRA-C3:2.1 [Not a defect Justified:Unset] "condition will be executed based on the configured values" */
        if(LddIpduGroupId <= (Com_IpduGroupIdType)(COM_IPDUGROUP_COUNT - COM_ONE))
        {
          /* Get the pointer to the I-PDU group structure */
          LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
          /* If the group was disable earlier and is now enabled */
          if(COM_TRUE == (LpIpduGroup->blRxDmEnabled))
          {
            if(COM_TRUE == (LucGrpStsByte & (COM_ONE)))
            {
              /* If the super group is enabled we have to enable all
              the groups contained */
              Com_EnableRxDM(LddIpduGroupId);
			  
              LucGrpStsByte = LucGrpStsByte >> 1;
              LucBitPosition += 1;
            }
            else
            {
               /* stops only one Ipdu group since an Ipdu can be
               stopped only if it is stopped in all the Ipdu Groups
               it is contained in */
              
              Com_DisableRxDM(LddIpduGroupId);
              LucGrpStsByte = LucGrpStsByte >> COM_ONE;
              LucBitPosition += COM_ONE;
            }
          }
          else
          {
            LucGrpStsByte = LucGrpStsByte >> COM_ONE;
            LucBitPosition += COM_ONE;
          }
        }
        else
        {
          /* Break out of the loop */
          LusVectArrIndex = COM_IPDU_GRP_VECTOR_SIZE;
          LucBitPosition = COM_EIGHT;
        }
      }
      SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
      LusVectArrIndex++;
    }
  }
}
/* polyspace-end MISRA-C3:2.1 [Not a Defect:Low] "condition will be executed based on the configured values" */
/* polyspace-end DEFECT:DEAD_CODE [Not a defect:Low] "If-condition is changable depending on the configuration" */

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
/* polyspace +3 MISRA-C3:8.13 [Not a Defect:Low] "Com_IpduGroupVector type is the prototype specified in the 
AUTOSAR specification. Part of the code is verfied manually and it has no impact" */
FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector
  ipduGroupVector)
{
  COM_UNUSED_PTR(ipduGroupVector);
  /* #1204 : Dummy Function for integration with BswM Module */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TxCounterUpdate                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        Updates counter value in the I-PDU buffer           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpTxIpduCounter                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaTxPack                 **
**                                              Com_GaaTxIpduCountVal         **
**                        Function(s) invoked : SchM_Enter_xxx()              **
**                                              SchM_Exit_xxx()               **
**                                              pWrFuncPtr                    **
*******************************************************************************/
#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON) 
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TxCounterUpdate
   (P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter)
{
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
  uint8 LucTxIpduCntVal;

  /* Get the pointer to TxPack structure */
  LpTxPack = &Com_GaaTxPack[LpTxIpduCounter->ddTxPackIndex];
  /* Get the present counter data */
  LucTxIpduCntVal = 
    Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData];
  /* Increment I-PDU count value */
  LucTxIpduCntVal++;
  /* Apply wrap around mask to the counter data */
  LucTxIpduCntVal &= LpTxIpduCounter->ucTxIpduCntWrpMask;

  /* Invoke write function to pack counter data to I-PDU buffer */
  (void)Com_PackRequestWrite(LpTxPack,
  (P2CONST(void, AUTOMATIC, COM_CONST)) &LucTxIpduCntVal);

  /* Enter protection area */
  SchM_Enter_Com_IPDU_COUNTER_PROTECTION();
  /* Load present counter data in buffer */
  Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] = 
  LucTxIpduCntVal;
  /* Exit Critical Area */
  SchM_Exit_Com_IPDU_COUNTER_PROTECTION();
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_RxFilterCalc                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        It validates filter value for all involved signals  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddIpduIndex, Initialize                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaRxIpdu                 **
**                                              Com_GaaFilterOneEveryN        **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#if((COM_FILTER_ONEEVERYN == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE)
              Com_RxFilterCalc(PduIdType LddIpduIndex, boolean Initialize)
{
  uint8 LucFilterStsCount;
	
  if(LddIpduIndex < COM_RX_IPDU_COUNT) 
  {
    if(((Com_GaaRxIpdu[LddIpduIndex].ucRxConfig &
      COM_RX_ONEVERYN_CONFIG_MASK) != COM_FALSE)
      && (COM_TRUE == Initialize))
    {
      LucFilterStsCount = COM_NO_OF_FILTER_ONEVERYN;
      do
      {
        --LucFilterStsCount;
          #if(COM_TX_IPDU_TMS_SIG_BASED == STD_ON)
        if(Com_GaaFilterOneEveryN[LucFilterStsCount].ddComPduId ==
                                                        LddIpduIndex)
        #endif
        {
          #if((COM_TX_IPDU_TMS_SIG_BASED == STD_ON) \
            && (COM_NO_OF_FILTER_ONEVERYN > COM_MACRO_ZERO))
          if(COM_ZERO == Com_GaaFilterOneEveryN[LucFilterStsCount].ucFltrStsMask)
          #endif
          {
         
            *Com_GaaFilterOneEveryN[LucFilterStsCount].pCounter = COM_ZERO;
          }
        }
      }while(LucFilterStsCount != COM_ZERO);
    }
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> As the accordance to the AUTOSAR 4.0.3 COM specification. */
/* polyspace:end<MISRA-C3:18.1:Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
/* polyspace:end<MISRA-C3:14.3:Not a defect:Low> If-condition is changable depending on the configuration */
/* polyspace:end<DEFECT:USELESS_IF:Not a defect:Low> If-condition is changable depending on the configuration */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
