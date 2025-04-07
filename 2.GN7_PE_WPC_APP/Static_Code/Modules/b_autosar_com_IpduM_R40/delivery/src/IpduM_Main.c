/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Main.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Main process Functions                     **
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
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define IPDUM_MAIN_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_MAIN_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_MAIN_C_AR_RELEASE_REVISION_VERSION 3

/* IPDUM software version information */
#define IPDUM_MAIN_C_SW_MAJOR_VERSION            2
#define IPDUM_MAIN_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != \
     IPDUM_MAIN_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM_Main.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != \
     IPDUM_MAIN_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM_Main.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_MAIN_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM_Main.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_MAIN_C_SW_MAJOR_VERSION)
#error "IpduM_Main.c : Mismatch in Software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_MAIN_C_SW_MINOR_VERSION)
#error "IpduM_Main.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : IpduM_MainFunction                                  **
**                                                                            **
** Service ID           : 0x10                                                **
**                                                                            **
** Description          : This function performs processing of                **
**                        TxConfirmation time observation                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
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
**                        IpduM_GblStatus, IpduM_GaaTxOutIpdu[]               **
**                        IpduM_No_Of_Tx_Pathways               **
**                        Function(s) invoked    :                            **
**                        SchM_Enter_IpduM_TX_STATUS_PROTECTION_AREA(),       **
**                        SchM_Exit_IpduM_TX_STATUS_PROTECTION_AREA(),        **
**                        Det_ReportError                                     **
*******************************************************************************/
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_MainFunction(void)
{
  #if (IPDUM_ENABLE == STD_ON)
  #if (IPDUM_TX_CONFIRMATION == STD_ON)

  /* Local pointer to point Pending flags*/
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) LpTxPendingFlag;

  /* Local pointer to point Timer count*/
  P2VAR(uint16, AUTOMATIC, IPDUM_VAR) LpTxTimeoutCounter;

  /* Local Structure pointer to point Tx structure */
  P2CONST(IpduM_TxOutIpdu, AUTOMATIC, IPDUM_CONST) LpTxOutIpdu;
  uint16_least LusNoOfTxIpdus;
  uint8 LucTxPendingFlag;
  PduIdType LddTxPduIdIndex;
  #if (IPDUM_DEV_ERROR_DETECT == STD_ON)

  if (IPDUM_UNINIT == IpduM_GblStatus)
  {
    /* report DET with IPDUM_E_UNINIT*/
    (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_ZERO,
      (uint8)IPDUM_MAINFUNCTION_SID, (uint8)IPDUM_E_UNINIT);
  }
  else
  #endif /* End of if (IPDUM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the number of Tx Pending Flag Bytes */
    LusNoOfTxIpdus = (uint16_least)IpduM_No_Of_Tx_Pathways;

    /* Get the pointer to First TxIpdu */
    LddTxPduIdIndex = (PduIdType)IPDUM_ZERO;
    LpTxOutIpdu = &IpduM_GaaTxOutIpdu[LddTxPduIdIndex];

    /* Loop for all Tx IPDUs */
    do
    {
      /* Get the pointer to fist Tx Pending Flag */
      LpTxPendingFlag = LpTxOutIpdu->pTxPendingFlag;

      /* Get the pointer to Tx Timeout Counter */
      LpTxTimeoutCounter = (LpTxOutIpdu->pTxTimeoutCounter);

      /* Get the status of pending flag into local variable */
      LucTxPendingFlag = ((*LpTxPendingFlag) & (LpTxOutIpdu->ucTxPendingMask));

      /* Loop for all Tx pending status flag */
      if (((uint8)IPDUM_ZERO) != LucTxPendingFlag)
      {
	      if(((uint16)IPDUM_ZERO) != LpTxOutIpdu->usTimeoutCount)
		    {	  
          /* Decrement counter by one */
          (*LpTxTimeoutCounter)--;
      	  /* Check whether timer value reaches to zero */
      	  if (((uint16)IPDUM_ZERO) == (*LpTxTimeoutCounter))
          {
            /* Enter critical area */
            SchM_Enter_IpduM_TX_STATUS_PROTECTION_AREA();

            /* Reset pending flag */
            *(LpTxOutIpdu->pTxPendingFlag) &=
             (uint8)(~(LpTxOutIpdu->ucTxPendingMask));

            /* Exit critical area */
            SchM_Exit_IpduM_TX_STATUS_PROTECTION_AREA();
          }                         /* End of if(*LpTxTimeoutCounter ==
                                   *((uint16)IPDUM_ZERO)) */
        }  
      }                           /* End of if(LucTxPendingFlag !=
                                   *((uint8)IPDUM_ZERO)) */

      /* Decrement counter by one */
      LusNoOfTxIpdus--;
      LddTxPduIdIndex++;
      LpTxOutIpdu = &IpduM_GaaTxOutIpdu[LddTxPduIdIndex];
    } while (((uint16_least)IPDUM_ZERO) != LusNoOfTxIpdus);
  }
  #endif /* (IPDUM_TX_CONFIRMATION == STD_ON) */
  #endif /*#if (IPDUM_ENABLE == STD_ON) */
}                                 /* End of IpduM_MainFunction(void) */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

