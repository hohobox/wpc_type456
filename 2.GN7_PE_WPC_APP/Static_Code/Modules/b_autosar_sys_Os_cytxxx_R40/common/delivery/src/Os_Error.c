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
**  SRC-MODULE: Os_Error.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Error functionality                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.4.2     14-Feb-2018    MJ.Woo        Redmine #10892                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #10100                      **
** 2.1.1     09-Jan-2017    MJ.Woo        Redmine #2696, #7199                **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    18-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.9     13-Oct-2014    MJ.Woo        Redmine #1412                       **
** 2.0.7     21-Jan-2014    MJ.Woo        TASK: xar~819, Redmine #558         **
** 2.0.4     14-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.2     03-Sep-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Definition.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Os_ErrorHook                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to service the error.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Error                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticAppHook, Os_GddAppId,                   **
**                        Os_GusCallevelCheck                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        ErrorHook(), LpAppErrorHook()                       **
*******************************************************************************/
#if ((OS_ERROR_HOOK == STD_ON) || (OS_APP_ERROR_HOOK == STD_ON))
FUNC(void, OS_CODE) Os_ErrorHook(StatusType Error)
{
  #if (OS_APP_ERROR_HOOK == STD_ON)
  P2FUNC(void, OS_VAR, LpAppErrorHook) (StatusType);
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check if status of Error hook is OS_FALSE */
  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((Os_GusCallevelCheck[OS_CORE_ID]&OS_CONTEXT_ERRORHOOK) == OS_ZERO)
  {
    /* Make status of Error hook to true */
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_ERRORHOOK;

    OS_SET_KERNEL_FLAG();
    #if (OS_ERROR_HOOK == STD_ON)
    /* Call ErrorHook function : Run in Supervisor mode */
    ErrorHook(Error);
    #endif
    #if (OS_APP_ERROR_HOOK == STD_ON)
    if( INVALID_OSAPPLICATION != Os_GddAppId[OS_CORE_ID] )
    {
      /* Save Application specific ErrorHook in a local */
      /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> Array is operated in predefined range */      
      LpAppErrorHook = Os_GaaStaticAppHook[Os_GddAppId[OS_CORE_ID]].pErrorHook;
      /* Check if Application specific ErrorHook is not a null pointer */
      if (LpAppErrorHook != NULL_PTR)
      {
        #if (OS_MEMORY_PROTECTION == STD_ON)
        /* Check if application is non-trusted */
        if (Os_GddAppId[OS_CORE_ID] < Os_Trusted_Start_Indx)
        {
          /* Invoke the application Specific ErrorHook */
          /* polyspace<RTE:COR:Not a defect:No Action Planned> function ptr points to a valid function and code is manually checked*/          
          LpAppErrorHook(Error);
        } /* End of if (Os_GaaStaticApplication[Os_GddAppId[OS_CORE_ID]].ucType ==
           *OS_NON_TRUSTED) */
        else
        #endif /* End of if (OS_MEMORY_PROTECTION == STD_ON) */
        {
          /* Invoke the application Specific ErrorHook */
          /* polyspace<RTE:COR:Not a defect:No Action Planned> function ptr points to a valid function and code is manually checked*/                      
          LpAppErrorHook(Error);
        }
      } /* End of if (LpAppErrorHook != NULL_PTR) */
    }
    #endif /* End of if (OS_APP_ERROR_HOOK == STD_ON) */
    OS_CLEAR_KERNEL_FLAG();

    /* Make status of Error hook to false */
    Os_GusCallevelCheck[OS_CORE_ID] &= (uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_ERRORHOOK);
  } /* End of if (Os_GusCallevelCheck... ) */
} /* End of Os_ErrorHook(StatusType Error) */
#endif /* End of if ((OS_ERROR_HOOK == STD_ON) || (OS_APP_ERROR_HOOK == STD_ON))
        **/

/*******************************************************************************
** Function Name        : Os_CheckObjIDError                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to check object ID          **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_APPLICATION == STD_ON)
FUNC(StatusType, OS_CODE) Os_CheckObjIDError(
                            ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  StatusType LenStatusReturn;

  /* Initialize the return */
  LenStatusReturn = E_OK;

  switch (ObjectType)
  {
    case OBJECT_ISR:
      OS_CHECK_ISR_ID_ERROR(ObjectID, &LenStatusReturn);
      break;

    #if (OS_ALARM == STD_ON)
    case OBJECT_ALARM:
      if((ObjectID) >= Os_Alarm_Count)
      {
        LenStatusReturn = E_OS_ID;
      }
    break;
    #endif

    #if (OS_RESOURCE == STD_ON)
    case OBJECT_RESOURCE:
      OS_CHECK_RESOURCE_ID_ERROR(ObjectID, &LenStatusReturn);
      break;
    #endif

    #if (OS_COUNTER == STD_ON)
    case OBJECT_COUNTER:
      OS_CHECK_COUNTER_ID_ERROR(ObjectID, &LenStatusReturn);
      break;
    #endif

    #if (OS_SCHEDTABLE == STD_ON)
    case OBJECT_SCHEDULETABLE:
      OS_CHECK_SCHEDTABLE_ID_ERROR(ObjectID, &LenStatusReturn);
      break;
    #endif

    default:
      /* do nothing */
      break;
  } /* End of switch (ObjectType) */

  return (LenStatusReturn);
}
#endif /* End of #if (OS_APPLICATION == STD_ON) */
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
