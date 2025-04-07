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
**  SRC-MODULE: Os_Application.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of  Os-Application and Protection functionality.    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.15    12-Aug-2022    YH.Han        Redmine #37085                      **
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.8     25-Nov-2020    JH.Cho        Redmine #26808                      **
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.2     23-Apr-2019    MJ.Woo        Redmine #22921                      **
** 2.6.0     19-Mar-2019    SH.Yoo        Redmine #16219, #17076              **
** 2.5.0     26-Jun-2018    SH.Yoo        Redmine #12780, #13026              **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025                      **
** 2.4.2     20-Mar-2018    MJ.Woo        Redmine #10875                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #9937, #10100               **
** 2.4.0     14-Aug-2017    MJ.Woo        Redmine #9530                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #8276, #9148                **
** 2.3.0     23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.1.0     05-Oct-2016    SH.Yoo        Redmine #5866, #6071                **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.12    25-Apr-2016    JH.Lee        Redmine #4295                       **
** 2.0.11    16-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.10    09-Dec-2015    SH.Yoo        Redmine #2850                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.4     18-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.2     20-Aug-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.1     13-Aug-2013    DG.Lee        CR: xar~160, TASK: xar~655          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */
/* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Application.h"       /* Os Application header file */
#if (OS_TASK == STD_ON)
#include "Os_Task.h"              /* Os Task header File */
#endif
#if (OS_ALARM == STD_ON)
#include "Os_Alarm.h"             /* Os Alarm header File */
#endif
#include "Os_TimingProtection.h"  /* Os TimerProtection header file */
#if (OS_SCHEDTABLE == STD_ON)
#include "Os_SchedTable.h"
#endif
#include "Os_Resource.h"          /* Os Resource header file */
#include "Os_Multicore.h"
#if (OS_MULTICORE == STD_ON)
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_MulticoreMessage.h"
#endif
#include "Os_SystemCallTable.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define APPLICATION_TERMINATING \
                          ((ApplicationStateType)(0x80u|APPLICATION_TERMINATED))

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if (OS_SCALABILITY_CLASS >= OS_SC3)
static FUNC(ObjectAccessType, OS_CODE) Os_CheckObjectAccessService(
   ApplicationType ApplID, ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);
#endif
#if (OS_TRUSTED_FUNC_COUNT != OS_PRE_ZERO)
FUNC(StatusType, OS_CODE) Os_KernCallTrustedFunction( TrustedFunctionIndexType
                 FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#endif

/***************************************************************************//**
 * Function Name        : Os_KernGetApplicationID
 *
 * Service ID           : NA
 *
 * Description          : This Service returns the ID of running application
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : ApplicationType
 *                        - 0 ~ OS_APPLICATION_COUNT - 1 : No error
 *                        - INVALID_OSAPPLICATION : Interrupts are disabled
 *                          by user or it is called from wrong context
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if (OS_APPLICATION == STD_ON)
FUNC(ApplicationType, OS_CODE) Os_KernGetApplicationID(void)
{

  StatusType LenStatusReturn;
  ApplicationType LenApplicationType;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get Core Id*/
  OS_GET_CORE_ID(OS_CORE_ID);
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETAPPLICATIONID, LenStatusReturn);

  if(LenStatusReturn == E_OK)
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    LenApplicationType = Os_GddAppId[OS_CORE_ID];
  }
  else
  {
    LenApplicationType = INVALID_OSAPPLICATION;
  }

  return LenApplicationType;
} /* End of GetApplicationID(void) */
#endif /* End of #if (OS_APPLICATION == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernAllowAccess
 *
 * Service ID           : NA
 *
 * Description          : This Service checks if access is to be granted for
 *                        application
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : StatusType
 *                        - E_OK : No errors
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_STATE : The OS-Application of the caller is
 *                          in the wrong state
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaApplication, Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        Os_EnableAppInterrupts()
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(StatusType, OS_CODE) Os_KernAllowAccess(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  StatusType LenStatusReturn;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Set Return status to E_OK */
  LenStatusReturn = E_OK;
  /* Get Core Identifier */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(ALLOWACCESS, LenStatusReturn);
  /* Check if Application is already Accessible */
  OS_CHECK_APPLICATION_STATE(LenStatusReturn);
  if(LenStatusReturn == E_OK)
  {
    /* Update state with Accessible */
    Os_GaaApplication[Os_GddAppId[OS_CORE_ID]].ddState =
                                                       APPLICATION_ACCESSIBLE;
    #if (OS_CAT2_ISR_COUNT != OS_ZERO)
    /* Enable interrupts belonging to the application */
    Os_EnableAppInterrupts();
    #endif
  }
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store service Id of AllowAccess */
    OS_STORE_SERVICE(OSServiceId_AllowAccess);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif
  /* Return the Status */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of AllowAccess(void) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_KernGetApplicationState
 *
 * Service ID           : NA
 *
 * Description          : This Service is used to get the application state
 *                        from the given Application ID
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             Application    The OS-Application from which the
 *                                       state is requested
 *                                       (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[out]            Value          The current state of the application
 *                                       (range : APPLICATION_ACCESSIBLE,
 *                                                APPLICATION_RESTARTING,
 *                                                APPLICATION_TERMINATED)
 *
 * @return              : StatusType
 *                        - E_OK : No errors
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : <Application> is not valid
 *                        - E_OS_PARAM_POINTER : Value is a NULL_PTR
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaApplication
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(StatusType, OS_CODE) Os_KernGetApplicationState(
                     ApplicationType Application, ApplicationStateRefType Value)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Set Return status to E_OK */
  LenStatusReturn = E_OK;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETAPPLICATIONSTATE, LenStatusReturn);
  /* Check whether Application is greater than number of Application count */
  OS_CHECK_APPL_ID_ERROR(Application, LenStatusReturn);
  /* Check for NULL_PTR */
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  OS_CHECK_NULL_PTR(Value, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Check if new task belongs to same core */
    if (Os_GaaStaticApplication[Application].ddCoreID != OS_CORE_ID)
    {
      Os_SendGetApplicationState(Application, Value);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      Os_DoGetApplicationState(Application, Value);
    }
  }
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store service ID of GetApplicationState */
    OS_STORE_SERVICE(OSServiceId_GetApplicationState);
    /* Store the parameter 1 - Application */
    OS_STORE_PARAM1_APPLICATION(Application);
    /* Store the parameter 2 - Value */
    OS_STORE_PARAM2_APPVALUEREF(Value);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of GetApplicationState(ApplicationType Application,
   *ApplicationStateRefType Value) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_DoGetApplicationState
 *
 * Service ID           : NA
 *
 * Description          : This service returns the Applcation state
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             Application    The OS-Application from which the
 *                                       state is requested
 *                                       (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[out]            Value          The current state of the application
 *                                       (range : APPLICATION_ACCESSIBLE,
 *                                                APPLICATION_RESTARTING,
 *                                                APPLICATION_TERMINATED)
 *
 * @return              : void
 *
 * @pre                 : Application and Value should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaApplication
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(void, OS_CODE) Os_DoGetApplicationState(ApplicationType Application,
                                                  ApplicationStateRefType Value)
{
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
	*Value = Os_GaaApplication[Application].ddState & (ApplicationStateType)0x0F;
}
#endif

#if (OS_SAFETY_KERNEL != STD_ON)
/***************************************************************************//**
 * Function Name        : Os_KernCheckISRMemoryAccess
 *
 * Service ID           : NA
 *
 * Description          : This service checks if a memory region is write/
 *                        read/execute accessible and also returns information
 *                        if the memory region is part of the stack space.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             IsrID    CAT2 ISR reference
 *                                 (range : OS_TASK_COUNT + OS_CORE_COUNT ~
 *                                          OS_TASK_COUNT + OS_CORE_COUNT
 *                                          + OS_CAT2_ISR_COUNT - 1)
 * @param[in]             Address  Start of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 * @param[in]             Size     Size of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 *
 * @return              : AccessType
 *                        - OS_READ_ONLY
 *                        - OS_READ_WRITE
 *                        - OS_EXECUTE
 *                        - NO_ACCESS : Interrupts are disabled by user or
 *                                      It is called from wrong context or
 *                                      <IsrID> is not valid
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        Os_CheckMemoryAccessService
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(AccessType, OS_CODE) Os_KernCheckISRMemoryAccess(ISRType IsrID,
                            MemoryStartAddressType Address, MemorySizeType Size)
{
  AccessType LenAccessReturn;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LenStatusReturn = E_OK;
  LenAccessReturn = NO_ACCESS;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CHECKISRMEMORYACCESS, LenStatusReturn);
  /* Check whether IsrID is correct */
  OS_CHECK_ISR_ID_ERROR(IsrID, &LenStatusReturn);

  /* Check if LenAccessReturn is ACCESS */
  if (LenStatusReturn == E_OK)
  {
    /* Call Os_CheckMemoryAccessService */
    LenAccessReturn = Os_CheckMemoryAccessService((ObjectTypeType)IsrID,
                                                                 Address, Size);
  }
  /* Return the Status */
  return (LenAccessReturn);
} /* End of CheckISRMemoryAccess(ISRType IsrID, MemoryStartAddressType Address,
   *MemorySizeType Size) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_KernCheckTaskMemoryAccess
 *
 * Service ID           : OSServiceId_CheckTaskMemoryAccess
 *
 * Description          : This service checks if a memory region is write/
 *                        read/execute accessible and also returns information
 *                        if the memory region is part of the stack space.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             TaskID   Task reference
 *                                 (range : 0 ~ OS_TASK_COUNT
 *                                              + OS_CORE_COUNT - 1)
 * @param[in]             Address  Start of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 * @param[in]             Size     Size of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 *
 * @return              : AccessType
 *                        - OS_READ_ONLY
 *                        - OS_READ_WRITE
 *                        - OS_EXECUTE
 *                        - NO_ACCESS : Interrupts are disabled by user or
 *                                      It is called from wrong context or
 *                                      <TaskID> is not valid
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        Os_CheckMemoryAccessService
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(AccessType, OS_CODE) Os_KernCheckTaskMemoryAccess(TaskType TaskID,
                            MemoryStartAddressType Address, MemorySizeType Size)
{
  AccessType LenAccessReturn;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  LenStatusReturn = E_OK;
  LenAccessReturn = NO_ACCESS;
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CHECKTASKMEMORYACCESS, LenStatusReturn);
  /* Check whether TaskID is correct */
  OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn);

  /* Check if LenAccessReturn is ACCESS */
  if (LenStatusReturn == E_OK)
  {
    /* Call Os_CheckMemoryAccessService */
    LenAccessReturn = Os_CheckMemoryAccessService((ObjectTypeType)TaskID,
      Address, Size);
  }
  /* Return the Status */
  return (LenAccessReturn);
} /* End of CheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType
   *Address, MemorySizeType Size) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

#endif /* End of if (OS_SAFETY_KERNEL != STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernCheckObjectAccess
 *
 * Service ID           : NA
 *
 * Description          : This Service checks whether access can be granted
 *                        to the application for the specified Object
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             ApplID      OS-Application identifier
 *                                    (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[in]             ObjectType  Type of the following parameter
 *                                    (range : OBJECT_TASK, OBJECT_ISR,
 *                                     OBJECT_ALARM, OBJECT_RESOURCE,
 *                                     OBJECT_COUNTER, OBJECT_SCHEDULETABLE)
 * @param[in]             ObjectID    The object to be examined
 *                                    (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : ObjectAccessType
 *                        - ACCESS: If the ApplID has access to the object
 *                        - NO_ACCESS: If the ApplID has no access to the object
 *                                     or Interrupts are disabled by user or
 *                                     It is called from wrong context or
 *                                     <ApplID> or <ObjectType> is not valid
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        Os_CheckObjectAccessService
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(ObjectAccessType, OS_CODE) Os_KernCheckObjectAccess(ApplicationType ApplID,
                            ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  ObjectAccessType LenObjReturn;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Set Return status to ACCESS */
  LenObjReturn = NO_ACCESS;
  LenStatusReturn = E_OK;
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CHECKOBJECTACCESS, LenStatusReturn);
  /* Check whether Application is greater than number of Application count */
  OS_CHECK_OBJ_ACCESS_APPL_ID_ERROR(ApplID, LenStatusReturn);
  /* Check whether ObjectType is correct */
  OS_CHECK_OBJECT_TYPE_ERROR(ObjectType, LenStatusReturn);

  /* Check if LenStatusReturn is ACCESS or not */
  if (LenStatusReturn == E_OK)
  {
    /* Invoke Os_CheckObjectAccessService */
    LenObjReturn = Os_CheckObjectAccessService(ApplID, ObjectType, ObjectID);
  }
  /* Return the value */
  return (LenObjReturn);
} /* End of CheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType,
   *ObjectTypeIndex ObjectID) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_CheckObjectAccessService
 *
 * Service ID           : OSServiceId_CheckObjectAccess
 *
 * Description          : This Service checks whether access can be granted
 *                        to the application for the specified Object
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             ApplID      OS-Application identifier
 *                                    (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[in]             ObjectType  Type of the following parameter
 *                                    (range : OBJECT_TASK, OBJECT_ISR,
 *                                     OBJECT_ALARM, OBJECT_RESOURCE,
 *                                     OBJECT_COUNTER, OBJECT_SCHEDULETABLE)
 * @param[in]             ObjectID    The object to be examined
 *                                    (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : ObjectAccessType
 *                        - ACCESS: If the ApplID has access to the object
 *                        - NO_ACCESS: If the ApplID has no access to the object
 *                                     or <ObjectID> is not valid
 *
 * @pre                 : StartOS() function should be called,
 *                        ApplID and ObjectType should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticTask, Os_GaaStaticAlarm
 *                        Os_GaaResourceTable, Os_GaaStaticCounter
 *                        Os_GaaStaticSchedTable, Os_GaaStaticApplication
 *                        Os_GaaApplication
 *
 *                        Function(s) invoked    :
 *                        Os_CheckObjIDError()
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
static FUNC(ObjectAccessType, OS_CODE) Os_CheckObjectAccessService(
    ApplicationType ApplID, ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  P2CONST(Tdd_Os_Application, AUTOMATIC, OS_CONST) LpStaticApplication;
  StatusType LenStatusReturn;
  ObjectAccessType LenAccessReturn;
  uint32 LulMask;
  uint32 LulObjectMask;
  ApplicationType LddObjAppId;
  #if (OS_SCHEDTABLE == STD_ON)
  uint32 LddAlarmIndex;
  #endif
  LddObjAppId = OS_INVALID_VALUE;
  LenAccessReturn = NO_ACCESS;
  LenStatusReturn = E_OK;

  /* Check whether ObjectID is correct */
  if(ObjectType == OBJECT_TASK)
  {
    if(((ObjectID) >= (Os_Task_Count + Os_Core_Count))
                                                 || (ObjectID < Os_Core_Count))
    {
      LenStatusReturn = E_OS_ID;
    }
  }
  else
  {
    LenStatusReturn = Os_CheckObjIDError(ObjectType, ObjectID);
  }

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check if LenStatusReturn is ACCESS or not */
  if (LenStatusReturn == E_OK)
  {
    LpStaticApplication = &Os_GaaStaticApplication[ApplID];
    /* Even TRUSTED does not have access to all the objects as per OS448
     *   thus a check is not incorporated.*/
    /* Calculate Mask for the Application ID */
    LulMask = LpStaticApplication->usAppMask;

    switch (ObjectType)
    {
      #if (OS_TASK == STD_ON)
      case OBJECT_TASK:
        /* Get the ObjectMask in Local variable */
        LulObjectMask = Os_GaaStaticTask[ObjectID].ddAppAccesMask;
        /* Copy the AppId of the requested object in local */
        LddObjAppId = Os_GaaStaticTask[ObjectID].ddAppId;
        break;
      #endif /* End of if (OS_TASK == STD_ON) */

      #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
      case OBJECT_ISR: /* If the Type is ISR grant the access */
        LulObjectMask = OS_FULLACCESS;
        LddObjAppId = Os_GaaStaticTask[ObjectID].ddAppId;
        break;
      #endif

      #if (OS_ALARM == STD_ON)
      case OBJECT_ALARM:
        /* Get the ObjectMask in Local variable */
        LulObjectMask = Os_GaaStaticAlarm[ObjectID].ddAppAccesMask;
        /* Copy the AppId of the requested object in local */
        LddObjAppId = Os_GaaStaticAlarm[ObjectID].ddAppId;
        break;

      #endif /* End of if (OS_ALARM == STD_ON) */
      #if (OS_RESOURCE == STD_ON)
      case OBJECT_RESOURCE:
        /* Get the ObjectMask in Local variable*/
        LulObjectMask = Os_GaaResourceTable[ObjectID].ddAppAccesMask;
        /* Copy the AppId of the requested object in local */
        LddObjAppId = Os_GaaResourceTable[ObjectID].ddAppId;
        break;

      #endif /* End of if (OS_RESOURCE == STD_ON) */
      #if (OS_COUNTER == STD_ON)
      case OBJECT_COUNTER:
        /* Get the ObjectMask in Local variable */
        LulObjectMask = Os_GaaStaticCounter[ObjectID].ddAppAccesMask;
        /* Copy the AppId of the requested object in local */
        LddObjAppId = Os_GaaStaticCounter[ObjectID].ddAppId;
        break;

      #endif /* End of if (OS_COUNTER == STD_ON) */
      #if (OS_SCHEDTABLE == STD_ON)
      case OBJECT_SCHEDULETABLE:
        /* Get the index of the alarm structure */
        LddAlarmIndex = Os_GaaStaticSchedTable[ObjectID].ddAlarmIndex;
        /* Get the mask from the alarm structure in local
         *   variable */
        LulObjectMask = Os_GaaStaticAlarm[LddAlarmIndex].ddAppAccesMask;
        /* Copy the AppId of the requested object in local */
        LddObjAppId = Os_GaaStaticAlarm[LddAlarmIndex].ddAppId;
        break;

      #endif /* End of if (OS_SCHEDTABLE == STD_ON) */
      default:         LulObjectMask = OS_ZERO;
        break;
    } /* End of switch (ObjectType) */

    /* Check if Access can be granted */
    if (LddObjAppId == ApplID)
    {
        LenAccessReturn = ACCESS;
    }
    else if (((LulObjectMask & LulMask) != OS_FALSE) &&
        (Os_GaaApplication[LddObjAppId].ddState == APPLICATION_ACCESSIBLE))
    {
      /* Grant the access */
      LenAccessReturn = ACCESS;
    }
    else
    {
      /* Grant No Access */
      LenAccessReturn = NO_ACCESS;
    }
  } /* End of if (LenStatusReturn == ACCESS) */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  /* Return the value */
  return (LenAccessReturn);
} /* End of Os_CheckObjectAccessService(ApplicationType ApplID, ObjectTypeType
   *ObjectType, ObjectTypeIndex ObjectID) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_KernCheckObjectOwnership
 *
 * Service ID           : NA
 *
 * Description          : This Service returns owner of the Object
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             ObjectType  Type of the following parameter
 *                                    (range : OBJECT_TASK, OBJECT_ISR,
 *                                     OBJECT_ALARM, OBJECT_RESOURCE,
 *                                     OBJECT_COUNTER, OBJECT_SCHEDULETABLE)
 * @param[in]             ObjectID    The object to be examined
 *                                    (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : ApplicationType
 *                        - 0 ~ OS_APPLICATION_COUNT - 1
 *                        - INVALID_OSAPPLICATION :
 *                            Interrupts are disabled by user or
 *                            It is called from wrong context or
 *                            <ObjectType> is not valid
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticTask, Os_GaaStaticAlarm
 *                        Os_GaaResourceTable, Os_GaaStaticCounter
 *                        Os_GaaStaticSchedTable
 *
 *                        Function(s) invoked    :
 *                        Os_CheckObjIDError()
 ******************************************************************************/
#if (OS_APPLICATION == STD_ON)
FUNC(ApplicationType, OS_CODE) Os_KernCheckObjectOwnership(
                            ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  StatusType LenStatusReturn;
  ApplicationType LddApplicationID;
  #if (OS_SCHEDTABLE == STD_ON)
  uint32 LddAlarmIndex;
  #endif
  LenStatusReturn = E_OK;

  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Set Return status to Invalid OS-Application */
  LddApplicationID = INVALID_OSAPPLICATION;
  /* Check whether ObjectID is correct */
  if(ObjectType == OBJECT_TASK)
  {
    if(((ObjectID) >= (Os_Task_Count + Os_Core_Count))
                                                 || (ObjectID < Os_Core_Count))
    {
      LenStatusReturn = E_OS_ID;
    }
  }
  else
  {
    LenStatusReturn = Os_CheckObjIDError(ObjectType, ObjectID);
  }

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CHECKOBJECTOWNERSHIP, LenStatusReturn);
  /* Check whether ObjectType is correct */
  OS_CHECK_OBJECT_TYPE_ERROR(ObjectType, LenStatusReturn);
  /* Check if LenStatusReturn is E_OK or not */
  if(LenStatusReturn == E_OK)
  {
    switch (ObjectType)
    {
      case OBJECT_TASK:
      case OBJECT_ISR:
        /* Get the application Id from the structure */
        LddApplicationID = Os_GaaStaticTask[ObjectID].ddAppId;
        break;

        #if (OS_ALARM == STD_ON)
      case OBJECT_ALARM:
        /* Get the application Id from the structure */
        LddApplicationID = Os_GaaStaticAlarm[ObjectID].ddAppId;
        break;

        #endif /* End of if (OS_ALARM == STD_ON) */
        #if (OS_RESOURCE == STD_ON)
      case OBJECT_RESOURCE:
        /* Get the application Id from the structure */
        LddApplicationID = Os_GaaResourceTable[ObjectID].ddAppId;
        break;

        #endif /* End of if (OS_RESOURCE == STD_ON) */
        #if (OS_COUNTER == STD_ON)
      case OBJECT_COUNTER:
        /* Get the application Id from the structure */
        LddApplicationID = Os_GaaStaticCounter[ObjectID].ddAppId;
        break;

        #endif /* End of if (OS_COUNTER == STD_ON) */
        #if (OS_SCHEDTABLE == STD_ON)
      case OBJECT_SCHEDULETABLE:
        /* Get the Alarm index from the structure */
        LddAlarmIndex = Os_GaaStaticSchedTable[ObjectID].ddAlarmIndex;
        /* Get the application Id from the structure */
        LddApplicationID = Os_GaaStaticAlarm[LddAlarmIndex].ddAppId;
        break;

        #endif /* End of if (OS_SCHEDTABLE == STD_ON) */
      default:
        /* do nothing */
        break;
    } /* End of switch (ObjectType) */
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  return (LddApplicationID);
} /* End of CheckObjectOwnership(ObjectTypeType ObjectType, ObjectTypeIndex
   *ObjectID) */
#endif /* End of #if (OS_APPLICATION == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_DoTerminateApplication
 *
 * Service ID           : OSServiceId_TerminateApplication
 *
 * Description          : This Service Terminates the specified application
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             Application   The identifier of the OS-Application to
 *                                      be terminated. If the caller belongs to
 *                                      <Application> the call results in a self
 *                                      termination.
 *                                      (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[in]             RestartOption Either RESTART for doing a restart of
 *                                      the OS-Application or NO_RESTART if
 *                                      OS-Application shall not be restarted.
 *                                      (range : RESTART, NO_RESTART)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - OS_E_OK_AND_LOAD : Rescheduling is needed
 *                        - OS_E_OK_AND_SCHEDULE : RestartTask activated and
 *                                                 scheduling is needed
 *                        - E_OS_LIMIT : RestartTask already activated
 *
 * @pre                 : StartOS() function should be called,
 *                        <Application> should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GpStaticTask, Os_GaaApplication, Os_GpLinkTask
 *                        Os_GaaStaticTask, Os_GaaStaticApplication
 *                        Os_GaaTask, Os_GddAppId, Os_GusCallevelCheck,
 *                        Os_GulOsAppSP, Os_GulOsAppSPBtm
 *
 *                        Function(s) invoked    :
 *                        ReleaseSpinlock(), Os_KillTask(), Os_KillUsedCsa()
 *                        Os_ReleaseResourceService(), Os_RemoveAlarm()
 *                        Os_DisableAppInterrupts(), Os_StopSchedTabService()
 *                        Os_ActivateTaskService(), Os_KillIsr(), ShutdownOS()
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(StatusType, OS_CODE) Os_DoTerminateApplication(
                         ApplicationType Application, RestartType RestartOption)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if ((OS_ALARM == STD_ON)||(OS_SCHEDTABLE == STD_ON)||\
                                                    (OS_RESTART_TASK == STD_ON))
  P2CONST(Tdd_Os_Application, AUTOMATIC, OS_CONST) LpStaticApplication;
  #endif
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpPreviousLinkTask;
  #if (OS_ALARM == STD_ON)
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpApplAlarm;
  #endif
  #if (OS_SCHEDTABLE == STD_ON)
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  #if (OS_SCHEDTABLE == STD_ON)
  ScheduleTableType LddSchedTbleCount;
  #endif
  #if (OS_ALARM == STD_ON)
  AlarmType LddAlarmCount;
  #endif
  TaskType LddTaskCount;
  StatusType LenStatusReturn;

  LddTaskCount = Os_Task_Count;
  LenStatusReturn = E_OK;
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Update the status as TERMINATING(internal status) */
  Os_GaaApplication[Application].ddState = APPLICATION_TERMINATING;
  #if ((OS_ALARM == STD_ON)||(OS_SCHEDTABLE == STD_ON)||\
                                                    (OS_RESTART_TASK == STD_ON))
  LpStaticApplication = &Os_GaaStaticApplication[Application];
  #endif
  LpLinkTask = Os_GpLinkTask[OS_CORE_ID];

  LpPreviousLinkTask = NULL_PTR;

  do
  {
    /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    LpStaticTask = &Os_GaaStaticTask[LpLinkTask->ddTaskID];
    /* Check if the Task's APP ID matches the requested App ID */
    if (Application == LpStaticTask->ddAppId)
    {
      #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
      if (LpStaticTask->usType != OS_ISR2)
      #endif
      {
        #if (OS_RESOURCE == STD_ON)
        /* Release all the acquired resources */
        Os_ReleaseResourceService(LpStaticTask);
        #endif

        #if (OS_SPINLOCK == STD_ON)
        /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
        if ((LpStaticTask->pTask->ddSpinlock) != OS_ZERO)
        {
          do
          {
            /* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
            (void)ReleaseSpinlock(Os_GaaTask
                [Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock);
            /* polyspace:end<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
          } while (Os_GaaTask
              [Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock != OS_ZERO);
        }
        #endif /* End of if (OS_SPINLOCK == STD_ON) */

        /* Kill the Task */
        Os_KillTask(LpStaticTask);
        #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> coule be reached according to user configuration */
        Os_TaskKillHook(OS_CORE_ID, LpStaticTask->ddTaskId);
        /* polyspace:end<MISRA-C3:2.2> */
        #endif
      }
      #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
      else
      {
        /* Kill the ISR */
        Os_KillIsr(LpStaticTask);
	    #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> coule be reached according to user configuration */
		Os_IsrKillHook(OS_CORE_ID, LpStaticTask->ddTaskId);
        /* polyspace:end<MISRA-C3:2.2> */
		#endif
      }
      #endif

      /* update the link list */
      if (LpPreviousLinkTask != NULL_PTR)
      {
        /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
        LpPreviousLinkTask->pLinkList = LpLinkTask->pLinkList;
      }
    } /* End of if (Application == LpStaticTask->ddAppId) */
    else
    {
      if ((Os_GpLinkTask[OS_CORE_ID] != LpLinkTask) && (LpPreviousLinkTask == NULL_PTR))
      {
        Os_GpLinkTask[OS_CORE_ID] = LpLinkTask;
        /* Rescheduling is needed */
        LenStatusReturn = OS_E_OK_AND_LOAD;
      }
      LpPreviousLinkTask = LpLinkTask;
    }
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
    LpLinkTask = LpLinkTask->pLinkList;
  } while (LpLinkTask != NULL_PTR);

  /* Check if a task is NOT in SUSPENDED state */
  while (LddTaskCount != OS_ZERO)
  {
    LpStaticTask = &Os_GaaStaticTask[LddTaskCount];
    if (LpStaticTask->ddAppId == Application)
    {
      #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
      if (LpStaticTask->usType != OS_ISR2)
      #endif
      {
        /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
        if (LpStaticTask->pTask->ddState == WAITING)
        {
          /* Kill the Task */
          Os_KillTask(LpStaticTask);
          #if (OS_PROFILING_HOOK == STD_ON)
          /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> coule be reached according to user configuration */
          Os_TaskKillHook(OS_CORE_ID, LpStaticTask->ddTaskId);
          /* polyspace:end<MISRA-C3:2.2> */
          #endif
        }
      }
    }
    LddTaskCount--;
  }

  #if (OS_CAT2_ISR_COUNT != OS_ZERO)
  /* Disable ISR belonging to this application */
  Os_DisableAppInterrupts(Application);
  #endif
  #if (OS_ALARM == STD_ON)
  /* Count Alarms belonging to same application */
  LddAlarmCount = LpStaticApplication->ddNoOfAlarm;
  /* Point to the corresponding alarm of the application */
  LpApplAlarm = LpStaticApplication->pApplicationAlarm;
  /* Run through the while loop for all the alarms */
  while (LddAlarmCount != OS_ZERO)
  {
    /* Check if Alarm is in running state */
    /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    if (LpApplAlarm->ucAlarmState != OS_ALARM_SLEEP)
    {
      /* Remove alarm from the queue */
      Os_RemoveAlarm(LpApplAlarm);
      /* Change State alarm to SLEEP */
      LpApplAlarm->ucAlarmState = OS_ALARM_SLEEP;
    } /* End of if (LpApplAlarm->ucAlarmState != OS_ALARM_SLEEP) */
    /* Point to next Alarm */
    /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
    LpApplAlarm++;

    /* Decrement alarm count */
    LddAlarmCount--;
  }
  #endif /* End of if (OS_ALARM == STD_ON) */
  #if (OS_SCHEDTABLE == STD_ON)
  /* Count Schedule Tables belonging to same application */
  LddSchedTbleCount = LpStaticApplication->ddNoOfStaticSchedTable;
  /* Get the pointer to corresponding schedule table */
  LpSchedTable = LpStaticApplication->pApplicationScheTbl;
  /* Run through the while loop for all the Schedule Table */
  while (LddSchedTbleCount != OS_ZERO)
  {
    /* Invoke Os_StopSchedTabService */
    (void)Os_DoStopScheduleTable(LpSchedTable->ddSchedTableId, OS_FALSE);
    /* Point to next Schedule Table */
    LpSchedTable++;
    /* Decrement alarm count */
    LddSchedTbleCount--;
  }
  #endif /* End of if (OS_SCHEDTABLE == STD_ON) */

  /* Initialize OS Applicaiton Stack */
  Os_GulOsAppSP[Application] = Os_GulOsAppSPBtm[Application];
  /* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> It is necessary for 64bit data */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> This is intended to handle stack address  */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  *((Os_StackType*)(Os_GulOsAppSPTop[Application])) = OS_STACK_PATTERN;
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
  /* polyspace:end<CERT-C:INT36-C> */

  #if (OS_RESTART_TASK == STD_ON)

  /* Check if Restart Option is Restart */
  if (RestartOption == RESTART)
  {
    if (LpStaticApplication->pRestartTask != NULL_PTR)
    {
      /* Invoke Os_ActivatetaskService() to put the task in READY task list */
      LenStatusReturn |= Os_ActivateTaskService
                                            (LpStaticApplication->pRestartTask);
      /* Change state of Application to Restarting */
      Os_GaaApplication[Application].ddState = APPLICATION_RESTARTING;
    } /* End of if (LpStaticApplication->pRestartTask != NULL_PTR) */
    else
    {
      /* Invoke Shutdown as RestartTask is not configured */
      ShutdownOS(E_OS_PROTECTION_MEMORY); /* FIXME: OS244, OS557 review dglee */
    }
  } /* End of if (RestartOption == RESTART) */
  #else /* End of if (OS_RESTART_TASK == STD_ON) */
  /* polyspace<MISRA-C:14.2:Not a defect:Justify with annotations> This is used to explicit the non-using variable  */
  OS_UNUSED(RestartOption);
  #endif /* End of if (OS_RESTART_TASK == STD_ON) */
  #if(OS_ERROR_HOOK == STD_ON)
  /*
   * In case of Self termination from an Error hook, ErrorHook variable should
   * be reset in order to avoid call level errors in further API call
   */
  if ((Os_GddAppId[OS_CORE_ID] == Application) &&
      ((Os_GusCallevelCheck[OS_CORE_ID] & OS_CONTEXT_ERRORHOOK)
                                                            != (uint16)OS_ZERO))
  {
    Os_GusCallevelCheck[OS_CORE_ID] &= (uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_ERRORHOOK);
  }
  #endif

  /* polyspace<RTE: UNR : Not a defect : No Action Planned > This is for exceptional case. But this code has already been verified and no impact of this rule violation */
  if (Os_GaaApplication[Application].ddState != APPLICATION_RESTARTING)
  {	/* Update the status as TERMINATED */
    Os_GaaApplication[Application].ddState = APPLICATION_TERMINATED;
  }

  return (LenStatusReturn);
} /* End of Os_TerminateApplService(ApplicationType Application, RestartType
   *RestartOption) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_KernTerminateApplication
 *
 * Service ID           : NA
 *
 * Description          : This Service Terminates the specified application
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             Application   The identifier of the OS-Application to
 *                                      be terminated. If the caller belongs to
 *                                      <Application> the call results in a self
 *                                      termination.
 *                                      (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[in]             RestartOption Either RESTART for doing a restart of
 *                                      the OS-Application or NO_RESTART if
 *                                      OS-Application shall not be restarted.
 *                                      (range : RESTART, NO_RESTART)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : <Application> was not valid
 *                        - E_OS_VALUE : <RestartOption> was not valid
 *                        - E_OS_STATE : The state of <Application> does not
 *                                       allow terminating <Application>
 *                        - E_OS_LIMIT : RestartTask already activated
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GpStaticTask
 *
 *                        Function(s) invoked    :
 *                        Os_TerminateApplService(), Os_ScheduleService(),
 *                        Os_TaskPreemptionHook()
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(StatusType, OS_CODE) Os_KernTerminateApplication(
                         ApplicationType Application, RestartType RestartOption)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  /* Set Return status to E_OK */
  LenStatusReturn = E_OK;
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(TERMINATEAPPLICATION, LenStatusReturn);
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Check whether the call is for self termination from error hook*/
  OS_SELF_TERMINATION_CHECK(LenStatusReturn, Application);
  /* Check whether Application is greater than number of Application count */
  OS_CHECK_APPL_ID_ERROR(Application, LenStatusReturn);
  /* Check if Restart option is valid or not */
  OS_CHECK_RESTART_VALUE_ERROR(LenStatusReturn, RestartOption);
  /* Check if caller belongs to non trusted application */
  OS_CHECK_CALLER_APPLICATION_ERROR(Application, &LenStatusReturn);
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> status check */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> status check */
  /* Check if appllication is in TERMINATED state */
  OS_CHECK_APPL_TERMINATED_STATE_ERROR(Application, LenStatusReturn);
  /* Check if Caller has access to terminate the application */
  OS_CHECK_APPL_CALLER_ACCESS_ERROR(Application, LenStatusReturn);
  /* Check if appllication is in Restarted state */
  OS_CHECK_APPL_RESTART_STATE_ERROR(Application, LenStatusReturn, RestartOption);


  if ((LenStatusReturn == E_OK) &&
		  ((Os_GaaApplication[Application].ddState) != APPLICATION_TERMINATING))
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid value and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid value and verified manually */
    /* Check if new task belongs to same core */
    if (Os_GaaStaticApplication[Application].ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendActivateTask to schedule task on respective core */
      LenStatusReturn = Os_SendTerminateApplication(Application, RestartOption);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Invoke Os_TerminateApplService function */
      LenStatusReturn = Os_DoTerminateApplication(Application, RestartOption);
    }

    /* polyspace-begin<RTE:UNR:Not a Defect:Justify with annotations> do something according to status */
    if (LenStatusReturn >= OS_E_OK_AND_LOAD)
    {
      /* Load context */
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
      OS_RELOADCONTEXT();
    }
    /* polyspace:begin<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > It can be entered by preemtion */
    /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "It can be entered by preemtion" */
    else if (LenStatusReturn == OS_E_OK_AND_SCHEDULE)
    {
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = READY;
      #if (OS_PROFILING_HOOK == STD_ON)
      /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
      Os_TaskPreemptionHook(OS_CORE_ID, Os_GpStaticTask[OS_CORE_ID]->ddTaskId);
      #endif
      /* NOTE: Os_RunTask() separately executed later. */
      Os_ScheduleService();
      /* Save and load context */
      OS_SAVECONTEXT();
    }
    /* polyspace:end<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > It can be entered by preemtion */
    /* polyspace-end CERT-C:MSC12-C [Not a defect:Low] "It can be entered by preemtion" */
    else
    {
      /* do nothing */
    }
    /* polyspace-end<RTE:UNR> */
    /* polyspace:end<MISRA-C3:18.1> */

    /* Mask the Status Return value */
    LenStatusReturn &= OS_STATUS_MASK;

  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* Store service ID of TerminateApplication */
    OS_STORE_SERVICE(OSServiceId_TerminateApplication);
    /* Store the parameter 1 - Application */
    OS_STORE_PARAM1_APPLICATION(Application);
    /* Store the parameter 2 - RestartOption */
    OS_STORE_PARAM2_RESTARTOPTION(RestartOption);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */

  return (LenStatusReturn);
} /* End of TerminateApplication(ApplicationType Application, RestartType
   *RestartOption) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_KernCallTrustedFunction
 *
 * Service ID           : NA
 *
 * Description          : This service shall switch the processor into
 *                        privileged mode AND shall call the function
 *                        <FunctionIndex> out of a list of implementation
 *                        specific trusted functions
 *
 * Sync/Async           : Depends on called function. If called function is
 *                        synchronous then service is synchronous.
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             FunctionIndex  Index of the function to be called
 *                                       (range : 0 ~ OS_TRUSTED_FUNC_COUNT - 1)
 * @param[in]             FunctionParams Pointer to the parameters for the
 *                                       function - specified by the
 *                                       FunctionIndex - to be called.
 *                                       If no parameters are provided, a NULL
 *                                       pointer has to be passed.
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_SERVICEID : No function defined for this index
 *                        - E_OS_ACCESS : The Target trusted function is part of
 *                                        an OS-Application on another core
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddAppId, Os_GaaTrustedFunction
 *
 *                        Function(s) invoked    :
 *                        Os_DisableBudgetTimer(), Os_EnableBudgetTimer()
 *                        Os_DisableAppInterrupts(), Os_EnableAppInterrupts
 ******************************************************************************/
#if (OS_TRUSTED_FUNC_COUNT != OS_PRE_ZERO)
FUNC(StatusType, OS_CODE) Os_KernCallTrustedFunction( TrustedFunctionIndexType
                  FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  LenStatusReturn = E_OK;
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CALLTRUSTEDFUNCTION, LenStatusReturn);
  /* Check the index of trusted function */
  OS_CHECK_TRUSTED_FUNCTION_INDEX(FunctionIndex, LenStatusReturn);
  #if (OS_MULTICORE == STD_ON)
  /* Check trusted function is part of an OS-Application on another core */
  OS_CHECK_TRUSTED_FUNCTION_CORE(FunctionIndex, LenStatusReturn);
  #endif

  if (LenStatusReturn == E_OK)
  {
    Os_GaaApplication[Os_GddAppId[OS_CORE_ID]].ddState |= \
                                                APPLICATION_HAS_CALLTRUSTEDFUNC;
    #if (OS_TIMING_PROTECTION == STD_ON)
    /* Disable budget timer: OS565, OS564 */
    Os_GucDelayBudget[OS_CORE_ID]++;
    #endif
    #if(OS_CAT2_ISR_COUNT != OS_ZERO)
    Os_DisableAppInterrupts(Os_GddAppId[OS_CORE_ID]);
    #endif
    /* Invoking the trusted function based on the functionindex  */
    Os_GaaTrustedFunction[FunctionIndex].pTrustedFunc(FunctionParams);
    #if(OS_CAT2_ISR_COUNT != OS_ZERO)
    Os_EnableAppInterrupts();
    #endif
    #if (OS_TIMING_PROTECTION == STD_ON)
    /* Check if last call trusted function is remaining */
    if(Os_GucDelayBudget[OS_CORE_ID] == OS_ONE)
    {
      /* Set the variable to zero */
      Os_GucDelayBudget[OS_CORE_ID] = OS_ZERO;
      /* Enable budget timer: OS565, OS564 */
      Os_EnableBudgetTimer();
    }
    else
    {
      /* Decrement the variable */
      Os_GucDelayBudget[OS_CORE_ID]--;
    }
    #endif
    Os_GaaApplication[Os_GddAppId[OS_CORE_ID]].ddState &= \
                                               ~APPLICATION_HAS_CALLTRUSTEDFUNC;
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store the service ID of CallTrustedFunction */
    OS_STORE_SERVICE(OSServiceId_CallTrustedFunction);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif
  return (LenStatusReturn);
} /* End of CallTrustedFunction(TrustedFunctionIndexType FunctionIndex,
   *TrustedFunctionParameterRefType FunctionParams) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

/***************************************************************************//**
 * Function Name        : Os_KillTaskOrISR
 *
 * Service ID           : NA
 *
 * Description          : This service is used to terminate Task/ISR forcibly
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - OS_E_OK_AND_LOAD : Rescheduling is needed
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s) :
 *                        Os_GpLinkTask, Os_GaaTask, Os_GaaStaticTask
 *                        Os_GddFaultyTask
 *
 *                        Function(s) invoked    :
 *                        Os_KillTask(), Os_KillIsr(),
 *                        Os_ReleaseResourceService(), ReleaseSpinlock()
 ******************************************************************************/
#if (OS_PROTECTION_HOOK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KillTaskOrISR(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_TIMING_PROTECTION == STD_ON)
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpPreviousLinkTask;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  StatusType LenStatusReturn;
  TaskType LddFaultyTaskId;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  #if (OS_TIMING_PROTECTION == STD_ON)
  if (Os_GddFaultyTask[OS_CORE_ID] != INVALID_TASK)
  {
    /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    LddFaultyTaskId = Os_GddFaultyTask[OS_CORE_ID];
  }
  else
  #endif
  {
  	/* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    LddFaultyTaskId = Os_GpLinkTask[OS_CORE_ID]->ddTaskID;
  }
  /* polyspace:end<MISRA-C3:18.1> */

  #if (OS_TIMING_PROTECTION == STD_ON)
  LenStatusReturn = E_OK;
  #endif
  LpStaticTask = &Os_GaaStaticTask[LddFaultyTaskId];
  #if (OS_RESOURCE == STD_ON)
  Os_ReleaseResourceService(LpStaticTask);
  #endif
  #if (OS_SPINLOCK == STD_ON)
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((Os_GaaTask[LddFaultyTaskId].ddSpinlock) != OS_ZERO)
  {
    /* polyspace<RTE : NTL :Not a defect:Justify with annotations> Waiting until spinlock is released is intended instruction */
    do
    {
      (void)ReleaseSpinlock(Os_GaaTask[LddFaultyTaskId].ddSpinlock);
    } while (
      Os_GaaTask[LddFaultyTaskId].ddSpinlock != OS_ZERO);
  } /* End of if ((Os_GaaTask[LddFaultyTaskId].ddSpinlock)
     *!= OS_ZERO) */
  #endif /* End of if (OS_SPINLOCK == STD_ON) */

  /* If object to be killed is a Task */
  #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  if (LpStaticTask->usType != OS_ISR2)
  #endif
  {
    /* Kill the Task */
    Os_KillTask(LpStaticTask);
  } /* End of if (LpStaticTask->ucType != OS_ISR2) */
  #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
  else
  {
    Os_KillIsr(LpStaticTask);
  } /* End of else */
  #endif

  #if (OS_TIMING_PROTECTION == STD_ON)
  LpLinkTask = Os_GpLinkTask[OS_CORE_ID];
  LpPreviousLinkTask = NULL_PTR;

  /* Find killed Task/Isr and update LinkList */
  while (LpLinkTask != NULL_PTR)
  {
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
    /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
    if (LpLinkTask->ddTaskID == LddFaultyTaskId)
    {
      if (LpPreviousLinkTask == NULL_PTR)
      {
        /* Update Os_GpLinkTask with next task */
        /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
        Os_GpLinkTask[OS_CORE_ID] = LpLinkTask->pLinkList;
        LenStatusReturn = OS_E_OK_AND_LOAD;
      }
      else
      {
        /* Remove killed task in LinkList */
        /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
        LpPreviousLinkTask->pLinkList = LpLinkTask->pLinkList;
      }
      break;
    }
    else
    {
      LpPreviousLinkTask = LpLinkTask;
    }
    /* polyspace:end<MISRA-C3:18.1> */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpLinkTask = LpLinkTask->pLinkList;
  }
  #else
  /* Update Os_GpLinkTask with next task */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  Os_GpLinkTask[OS_CORE_ID] = Os_GpLinkTask[OS_CORE_ID]->pLinkList;
  LenStatusReturn = OS_E_OK_AND_LOAD;
  #endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

  return (LenStatusReturn);
} /* End of Os_KillTaskOrISR(void) */
#endif /* End of if (OS_PROTECTION_HOOK == STD_ON) */


#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<MISRA-C3:20.1> */
/* polyspace:end<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

