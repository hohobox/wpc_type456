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
**  SRC-MODULE: Fota_MacUpdateMgr.c                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provide definition of FOTA function                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.0.0.0   31-Dec-2024   ThanhTVP2      #CP44-12051                         **
** 1.0.0     23-Oct-2023   Djlee          Initial version                     **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota_Types.h"
#include "Fota_IntFunc.h"
#include "Fota_Cfg.h"
#include "Fota_Globals.h"
#include "Fota_User_Callouts.h"
#include "Fota_MacUpdateMgr.h"

/* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

static Fota_MacUpdateStatType   rue_MacUpdateState    = FOTA_MACUPDATE_IDLE;
static Fota_JobResultType       rue_MacUpdateResult   = FOTA_JOB_FAILED;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define Fota_START_SEC_CODE
#include "Fota_MemMap.h"

static FUNC(void, FOTA_CODE)Fota_MacUpdateEnd_Cbk(void);
static FUNC(void, FOTA_CODE)Fota_MacUpdateErr_Cbk(void);

/*******************************************************************************
** Function Name        : Fota_MacUpdateRequest                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Request Mac Update operation                        **
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
** Remarks              : Global Variable(s)  :                               **
**                        rue_MacUpdateResult                                 **
**                        rue_MacUpdateState                                  **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

/* polyspace-begin MISRA-C3:2.7 [Justified:Low] "Parameter depends on the Configuration." */
FUNC(void, FOTA_CODE) Fota_MacUpdateRequest(void)
/* polyspace-end MISRA-C3:2.7 [Justified:Low] "Parameter depends on the Configuration." */
{
	/* @Trace: FOTA_SUD_API_00041 */
	rue_MacUpdateResult   = FOTA_JOB_PENDING;
	rue_MacUpdateState    = FOTA_MACUPDATE_START;
}

/*******************************************************************************
** Function Name        : Fota_MacUpdateResult                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : result check area sync operation                    **
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
** Return parameter     : Fota_JobResultType rue_MacUpdateResult              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        rue_MacUpdateResult                                 **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

FUNC(Fota_JobResultType, FOTA_CODE) Fota_MacUpdateResult(void)
{
	/* @Trace: FOTA_SUD_API_00042 */
	return rue_MacUpdateResult;
}

/*******************************************************************************
** Function Name        : Fota_MacUpdateEnd_Cbk                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : End result save                                     **
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
** Remarks              : Global Variable(s)  :                               **
**                        rue_MacUpdateState                                  **
**                        rue_MacUpdateResult                                 **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

static FUNC(void, FOTA_CODE) Fota_MacUpdateEnd_Cbk(void)
{
	/* @Trace: FOTA_SUD_API_00151 */
	rue_MacUpdateState  = FOTA_MACUPDATE_IDLE;
	rue_MacUpdateResult = FOTA_JOB_OK;
}
 
/*******************************************************************************
** Function Name        : Fota_MacUpdateErr_Cbk                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Err result save                                     **
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
** Remarks              : Global Variable(s)  :                               **
**                        rue_MacUpdateState                                  **
**                        rue_MacUpdateResult                                 **
**                        Function(s) invoked :                               **
**                        None                                                **
*******************************************************************************/

static FUNC(void, FOTA_CODE) Fota_MacUpdateErr_Cbk(void)
{
	/* @Trace: FOTA_SUD_API_00152 */
	rue_MacUpdateState  = FOTA_MACUPDATE_IDLE;
	rue_MacUpdateResult = FOTA_JOB_FAILED;
}

/*******************************************************************************
** Function Name        : Fota_MacUpdateMain                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Area Sync Main Function                             **
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
** Remarks              : Global Variable(s)  :                               **
**                        rue_MacUpdateState                                  **
**                        Function(s) invoked :                               **
**                        Fota_SecureBootMacUpdate                            **
**                        Fota_MacUpdateEnd_Cbk                               **
**                        Fota_MacUpdateErr_Cbk                               **
*******************************************************************************/
 
FUNC(void, FOTA_CODE) Fota_MacUpdateMain(void)
{
	Fota_JobResultType macUpdateResult;

    switch(rue_MacUpdateState)
    {
      case FOTA_MACUPDATE_IDLE:


      break;
	/* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_MACUPDATE_START:
	  	/* @Trace: FOTA_SUD_API_00150 */
        /* polyspace-begin DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        /* polyspace +1 MISRA-C3:10.5 [Not a defect:Low] "Have to casting to enum type" */
        macUpdateResult=(Fota_JobResultType)Fota_SecureBootMacUpdate();

    	  if (macUpdateResult==FOTA_JOB_OK)
    	  {
    		  rue_MacUpdateState=FOTA_MACUPDATE_END;
    	  }
    	  else if(macUpdateResult==FOTA_JOB_FAILED)
    	  {
    		  rue_MacUpdateState=FOTA_MACUPDATE_ERR;
    	  }
    	  else
    	  {
    	    /* Pending */
    	  }
        /* polyspace-end DEFECT:DEAD_CODE, MISRA-C3:14.3,2.1 [Justified:Low] "if-condition depends on the configuration." */
        /* polyspace-end MISRA-C3:10.5 [Not a defect:Low] "No Impact of this rule violation" */

      break;
	/* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_MACUPDATE_END:
		  /* @Trace: FOTA_SUD_API_00262 */
    	  Fota_MacUpdateEnd_Cbk();

      break;
/* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this state will be activated under specific conditions" */
      case FOTA_MACUPDATE_ERR:
	 /* polyspace +1 RTE:UNR [Not a defect:Low] "This section of code has been thoroughly verified and this condition will be activated under specific conditions" */
      default:
		  /* @Trace: FOTA_SUD_API_00263 */
    	  Fota_MacUpdateErr_Cbk();

      break;
    }
}
 
#define Fota_STOP_SEC_CODE
#include "Fota_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
