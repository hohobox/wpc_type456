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
**  SRC-MODULE: Os_Arch_MemPro.c                                              **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of memory protection specific functionality         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: Yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.4.0     04-Jun-2021    YH.Han        Redmine #29686                      **
** 2.0.0     16-JUN-2020    JH.Cho        Redmine #23917                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:begin<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:begin<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<MISRA-C3:5.4:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<MISRA-C3:11.3:Not a defect:Justify with annotations> Cast is needed for implementation */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<MISRA-C3:11.5:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<MISRA-C3:11.8:Not a defect:Justify with annotations> Cast is needed for implementation */
/* polyspace:begin<MISRA-C3:18.4:Not a defect:Justify with annotations> Operators on pointer is used for better performance */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#include "Os_kernel.h"
#endif
#include "Os_Arch_Interrupt.h"    /* Os Interrupt header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_MulticoreMessage.h"
#endif
#include "Os_Arch_Regs.h"
#include "Os_Arch_MemPro.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if(OS_MEMORY_PROTECTION == STD_ON)
#if(OS_APP_MEMBLK_CNT != OS_ZERO)
static FUNC(void, OS_CODE) Os_EnableMPU(void);
static FUNC(void, OS_CODE) Os_DisableMPU(void);
static FUNC(void, OS_CODE) Os_EnableMemBlock(ApplicationType LddAppId);
static FUNC(void, OS_CODE) Os_DisableMemBlock(ApplicationType LddAppId);
static FUNC(void, OS_CODE) Os_InitSpvsrMemBlock(void);
#endif
static FUNC(void, OS_CODE) Os_InitializeStackMemoryBlock(uint32 LulStackIndex);
static FUNC(os_cy_en_mpu_region_size_t, OS_CODE) Os_ConvMpuRegion(uint32 LulSize);
static FUNC(os_cy_en_mpu_status_t, OS_CODE) Os_SetMpuRegion(
                                                      const uint32 LuiRegionNumber, 
                                                      const uint32 LuiRegionBaseAddress, 
                                                      const uint32 LuiRegionSizeAndEnable);
#endif

/***************************************************************************//**
 * Function Name        : Os_DisableAppInterrupts
 *
 * Service ID           : NA
 *
 * Description          : This function is called to Disable All interrupts of
 *                        current application.
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            Application Application ID
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaISRPriority
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if((OS_CAT2_ISR_COUNT != OS_ZERO) && (OS_APPLICATION == STD_ON))
FUNC(void, OS_CODE) Os_DisableAppInterrupts (ApplicationType Application)
{
  P2CONST(Tdd_Os_ISRPriority, AUTOMATIC, OS_PRIVATE_CONST)LpISRPriority;
  uint32 LucCount;
  LucCount = Os_ISR_Count;

  while(LucCount != OS_ZERO)
  {
    LucCount--;
    /* Take a pointer to the structure */
    LpISRPriority = &Os_GaaISRPriority[LucCount];
    /* Check if the interrupt is category 2 and it belongs to current
      application */
    if((LpISRPriority->ucISRType == OS_CAT2_ISR) &&
                                        (LpISRPriority->ddAppId == Application))
    {
      Os_IntSetDisable((uint32)(LpISRPriority->pICRAddress)
                                                         - OS_ARM_M_IRQ_IPR_START);
    }
  }
}
#endif

/***************************************************************************//**
 * Function Name        : Os_EnableAppInterrupts
 *
 * Service ID           : NA
 *
 * Description          : This function is called to Enable All interrupts of
 *                        current application.
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaISRPriority, Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if((OS_CAT2_ISR_COUNT != OS_ZERO) && (OS_APPLICATION == STD_ON))
FUNC(void, OS_CODE) Os_EnableAppInterrupts (void)
{
  P2CONST(Tdd_Os_ISRPriority, AUTOMATIC, OS_PRIVATE_CONST)LpISRPriority;
  uint32 LucCount;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get the current core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  LucCount = Os_ISR_Count;
  while(LucCount != OS_ZERO)
  {
    LucCount--;
    /* Take a pointer to the structure */
    LpISRPriority = &Os_GaaISRPriority[LucCount];
    /* Check if the interrupt is category 2 and it belongs to current
      application */
    if((LpISRPriority->ucISRType == OS_CAT2_ISR) &&
                           (LpISRPriority->ddAppId == Os_GddAppId[OS_CORE_ID]))
    {
      Os_IntSetEnable((uint32)(LpISRPriority->pICRAddress) -
                                                           OS_ARM_M_IRQ_IPR_START);
    }
  }
}
#endif

/*******************************************************************************
 * Function             : Os_EnableMPU
 *
 * Service ID           : NA
 *
 * Description          : This function is used to enable or disable MPU
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             LblEnable : OS_TRUE - Enable, OS_FALSE - Disable
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if ((OS_MEMORY_PROTECTION == STD_ON) && (OS_APP_MEMBLK_CNT != OS_ZERO))
static FUNC(void, OS_CODE) Os_EnableMPU(void)
{
  /* Ensure all memory accesses are completed before new memory access is committed */
  __asm("DSB");

  /* Enable the MPU */
  OS_MPU.ulCtrl |= OS_MPU_CTRL_ENABLE_MSK;

  /* Ensure all memory accesses are completed before next instruction is executed */
  __asm("DSB");

  /* Flush the pipeline and ensure all previous instructions are completed before executing new instructions */
  __asm("ISB");
}
#endif

/*******************************************************************************
 * Function             : Os_DisableMPU
 *
 * Service ID           : NA
 *
 * Description          : This function is used to enable or disable MPU
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             LblEnable : OS_TRUE - Enable, OS_FALSE - Disable
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if ((OS_MEMORY_PROTECTION == STD_ON) && (OS_APP_MEMBLK_CNT != OS_ZERO))
static FUNC(void, OS_CODE) Os_DisableMPU(void)
{
  /* Ensure all memory accesses are completed before new memory access is committed */
  __asm("DSB");

  /* Disable the MPU */
  OS_MPU.ulCtrl &= (~OS_MPU_CTRL_ENABLE_MSK);

  /* Ensure all memory accesses are completed before next instruction is executed */
  __asm("DSB");

  /* Flush the pipeline and ensure all previous instructions are completed before executing new instructions */
  __asm("ISB");
}
#endif

/***************************************************************************//**
 * Function Name        : Os_EnableMemBlock
 *
 * Service ID           : NA
 *
 * Description          : This function enables the MPU regions belonging to an
 *                        OS-Application
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddAppId    Id of an OS-Application
 *                                    (range : 0 ~ OS_APPLICATION_COUNT - 1)
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticApplication, Os_GaaStaticMemBlock
 *
 *                        Function(s) invoked    : __DSB(), __ISB()
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if ((OS_MEMORY_PROTECTION == STD_ON) && (OS_APP_MEMBLK_CNT != OS_ZERO))
static FUNC(void, OS_CODE) Os_EnableMemBlock(ApplicationType LddAppId)
{
  volatile uint8 LucIndex;
  volatile uint8 LucCount;
  volatile uint8 LucMemBlkIdx;

  LucMemBlkIdx = Os_GaaStaticApplication[LddAppId].ucBaseMemBlockIndex;
  LucCount = Os_GaaStaticApplication[LddAppId].ucNoOfMemBlk;

  for(LucIndex = LucMemBlkIdx; LucIndex < (LucMemBlkIdx + LucCount); LucIndex++)
  {
    Os_SetMpuRegion(Os_GaaStaticMemBlock[LucIndex].ddRegionNumber, 
                    Os_GaaStaticMemBlock[LucIndex].ddRegionBaseAddress, 
                    Os_GaaStaticMemBlock[LucIndex].ddRegionSizeAndEnable);
  }
}
#endif

/***************************************************************************//**
 * Function Name        : Os_DisableMemBlock
 *
 * Service ID           : NA
 *
 * Description          : This function disables the MPU regions belonging to
 *                        an OS-Application
 *
  * Sync/Async          : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddAppId    Id of an OS-Application
 *                                    (range : 0 ~ OS_APPLICATION_COUNT - 1)
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticApplication, Os_GaaStaticMemBlock
 *
 *                        Function(s) invoked    : __DSB(), __ISB()
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if ((OS_MEMORY_PROTECTION == STD_ON) && (OS_APP_MEMBLK_CNT != OS_ZERO))
static FUNC(void, OS_CODE) Os_DisableMemBlock(ApplicationType LddAppId)
{
  volatile uint8 LucIndex;
  volatile uint8 LucCount;
  volatile uint8 LucMemBlkIdx;

  LucMemBlkIdx = Os_GaaStaticApplication[LddAppId].ucBaseMemBlockIndex;
  LucCount = Os_GaaStaticApplication[LddAppId].ucNoOfMemBlk;

  for(LucIndex = LucMemBlkIdx; LucIndex < (LucMemBlkIdx + LucCount); LucIndex++)
  {
    Os_SetMpuRegion(Os_GaaStaticMemBlock[LucIndex].ddRegionNumber, 
                    (Os_GaaStaticMemBlock[LucIndex].ddRegionBaseAddress), 
                    Os_GaaStaticMemBlock[LucIndex].ddRegionSizeAndEnable & (~OS_MPU_RASR_ENABLE_MSK));
  }
}
#endif

/*******************************************************************************
 * Function             : Os_InitializeStackMemoryBlock
 *
 * Service ID           : NA
 *
 * Description          : This function is used to initialize MPU region of
 *                        the stack memory.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LulStackIndex    Index of stack info array
 *
 * @return              : void
 *
 * @pre                 : Address must be aligned 32byte
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStack
 *
 *                        Function(s) invoked    :
 *                        Os_ConvMpuRegion(), Os_SetMpuRegion()
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if(OS_MEMORY_PROTECTION == STD_ON)
static FUNC(void, OS_CODE) Os_InitializeStackMemoryBlock(uint32 LulStackIndex)
{
  volatile Os_Reg32 LulRegionBaseAddress;
  volatile Os_Reg32 LulRegionSizeAndEnable;
  volatile os_cy_en_mpu_region_size_t LddRegSize;
  volatile uint32 LulStackSize;

  LulRegionBaseAddress = (Os_Reg32)Os_GaaStack[LulStackIndex].pStackArea;

  /* LulStackSize should be power of 2 */
  LulStackSize = Os_GaaStack[LulStackIndex].usStackSize * sizeof(Os_StackType);
  LddRegSize = Os_ConvMpuRegion(LulStackSize);

  LulRegionSizeAndEnable = ((uint32) LddRegSize |
                            (uint32) OS_CY_MPU_ACCESS_P_FULL_ACCESS |
                            (uint32) OS_CY_MPU_ATTR_NORM_MEM_WB |
                            (uint32) OS_CY_MPU_INST_ACCESS_DIS |
                            (uint32) 0x0 |
                            (uint32) OS_CY_MPU_ENABLE);

  Os_SetMpuRegion(OS_MPU_REGION_STACK, LulRegionBaseAddress, LulRegionSizeAndEnable);
}
#endif

/*******************************************************************************
 * Function             : Os_InitSpvsrMemBlock
 *
 * Service ID           : NA
 *
 * Description          : This service is used to Initialize and access
 *                        the supervisor memory block
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticMemBlock
 *
 *                        Function(s) invoked    :
 *                        Os_SetMpuRegion(), 
 *                        Os_EnableMPU(), Os_DisableMPU(), 
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if(OS_MEMORY_PROTECTION == STD_ON)
static FUNC(void, OS_CODE) Os_InitSpvsrMemBlock(void)
{
  volatile uint8 LucIdx;

  for (LucIdx = 0u; LucIdx < Os_MemBlk_Count; LucIdx++)
  {
    if (Os_GaaStaticMemBlock[LucIdx].blEnabledOnStart == TRUE)
    {
      Os_SetMpuRegion(Os_GaaStaticMemBlock[LucIdx].ddRegionNumber, 
                      Os_GaaStaticMemBlock[LucIdx].ddRegionBaseAddress, 
                      Os_GaaStaticMemBlock[LucIdx].ddRegionSizeAndEnable);
    }
  }
}
#endif /* #if(OS_MEMORY_PROTECTION == STD_ON) */

/*******************************************************************************
 * Function             : Os_HandleMemoryBlock
 *
 * Service ID           : NA
 *
 * Description          : This service switch memory blocks for non-trusted
 *                        OS-Application
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             LpStaticTask : Pointer of new Task struct
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticApplication, Os_GaaStaticMemBlock,
 *                        Os_GaaStack
 *
 *                        Function(s) invoked    :
 *                        Os_EnableMPU(),
 *                        Os_InitializeStackMemoryBlock()
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if(OS_MEMORY_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_HandleMemoryBlock(P2CONST(Tdd_Os_StaticTask,
                                              AUTOMATIC, OS_CONST) LpStaticTask)
{
  static uint32 LucPrevApp = OS_INVALID_VALUE;

  /* Disable MPU */
  Os_DisableMPU();

  if(LucPrevApp != LpStaticTask->ddAppId)
  {
    #if(OS_APP_MEMBLK_CNT != OS_ZERO)
    /* Clear the previously configured Memory Blocks */
    /* If current Application is non-trusted, disable used MPU regions */
    if (LucPrevApp < Os_Trusted_Start_Indx)
    {
      Os_DisableMemBlock(LucPrevApp);
    }

    /* Set the Memory Blocks for a newly executed Application */
    if (LpStaticTask->ddAppId < Os_Trusted_Start_Indx)
    {
      Os_EnableMemBlock(LpStaticTask->ddAppId);
    }
    #endif

    /* Update the application Id */
    LucPrevApp = LpStaticTask->ddAppId;
  }

  /* If LddNewAppId is INVALID_OSAPPLICATION, User Stack is used */
  if (LpStaticTask->ddAppId != (ApplicationType)INVALID_OSAPPLICATION)
  {
    /* Switch stack memory block */
    Os_InitializeStackMemoryBlock(LpStaticTask->ucStackIndex);
  }

  /* Enable MPU */                                
  Os_EnableMPU();
} /* End of Os_HandleMemoryBlock(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   * OS_CONST) LpStaticTask) */
#endif /* End of if ((OS_MEMORY_PROTECTION == STD_ON) && (OS_APP_MEMBLK_CNT !=
        *OS_ZERO)) */

/*******************************************************************************
 * Function             : Os_InitializeDedicatedMemBlock
 *
 * Service ID           : NA
 *
 * Description          : This function initializes dedicated memory blocks
 *                        during  StartOS
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddAppId
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_012}
 *
 * @ingroup               OS_CYTXXX_ESDD_008
 ******************************************************************************/
#if (OS_MEMORY_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_InitializeDedicatedMemBlock(void)
{
  #if(OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Initialize application id with invalid value */
  Os_GddAppId[OS_CORE_ID] = (ApplicationType)INVALID_OSAPPLICATION;

  /* Enable MPU */
  Os_DisableMPU();

  /* Ensure all memory accesses are completed before new memory access is committed */
  __asm("DSB");

  /* Enables the default memory map */
  OS_MPU.ulCtrl |= OS_MPU_CTRL_PRIVDEFENA_MSK;

  /* Ensure all memory accesses are completed before next instruction is executed */
  __asm("DSB");

  /* Flush the pipeline and ensure all previous instructions are completed before executing new instructions */
  __asm("ISB");  

  /* Initialize Supervisor Memory Block */
  Os_InitSpvsrMemBlock();

  /* Diable MPU */
  Os_EnableMPU();
}
#endif /* End of if (OS_MEMORY_PROTECTION == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_CheckMemoryAccessService
 *
 * Service ID           : NA
 *
 * Description          : This service returns the access rights of the Memory
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             LddTaskID    Task or CAT2 ISR reference
 *                                     (range : 0 ~ OS_TASK_COUNT
 *                                                  + OS_CAT2_ISR_COUNT
 *                                                  + OS_CORE_COUNT - 1)
 * @param[in]             LddStartAddr Start of memory area
 *                                     (range : 0u ~ 0xFFFFFFFFu)
 * @param[in]             LulSize      Size of memory area
 *                                     (range : 0u ~ 0xFFFFFFFFu)
 *
 * @return              : AccessType
 *                        - OS_READ_ONLY
 *                        - OS_READ_WRITE
 *                        - OS_EXECUTE
 *
 * @pre                 : LddTaskID should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticMemBlock, Os_GaaStaticApplication,
 *                        Os_GaaStaticTask, Os_GaaStack, Os_GulOsAppSPBtm,
 *                        Os_GulOsAppSPTop, Os_GulUserSPBtm, Os_GulUserSPTop
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_S32K14X_012}
 *
 * @ingroup               OS_S32K14X_ESDD_008
 ******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(AccessType, OS_CODE) Os_CheckMemoryAccessService(ObjectTypeType
         LddTaskID, MemoryStartAddressType LddStartAddr, MemorySizeType LulSize)
{
  P2CONST(Tdd_Os_Application, AUTOMATIC, OS_CONST) LpStaticApplication;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  uint32 LulStartAddr;
  AccessType LucReturnVal;
  uint32 LulStackTop;
  uint32 LulStackBtm;
  uint32 LulMpuRegionSize;
  uint32 LulBaseAddr;
  uint32 LulRegionAccess;
  uint8 LucIndex;
  uint8 LucCount;
  uint8 LucMemBlkIdx;

  LulStartAddr = (uint32)LddStartAddr;
  LucReturnVal = NO_ACCESS;

  LpStaticTask = &Os_GaaStaticTask[LddTaskID];
  /* polyspace<RTE:IDP: Not a defect : Justify with annotations > configured memory access index */
  LpStaticApplication = &Os_GaaStaticApplication[LpStaticTask->ddAppId];

  /* Check if the application is Trusted */
  /* polyspace<RTE:IDP: Not a defect : Justify with annotations > configured memory access index */
  if (LpStaticApplication->ucType != OS_TRUSTED)
  {
    /* Store the pointer to the stack area of the task in the local pointer */
    #if (OS_EVENT == STD_ON)
    if(LpStaticTask->usType == OS_TASK_EXTENDED)
    {
      /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
      /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Pointer arithmatic used to achieve better throughput. */
      LulStackBtm = (uint32)(&Os_GaaStack[LpStaticTask->ucStackIndex].pStackArea[Os_GaaStack[LpStaticTask->ucStackIndex].usStackSize]);
      /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Pointer arithmatic used to achieve better throughput. */
      /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
      LulStackTop = (uint32)Os_GaaStack[LpStaticTask->ucStackIndex].pStackArea;
    }
    else /* BASIC TASK, CAT2 ISR */
    #endif
    {
      if(LpStaticTask->ddTaskId != OS_CORE_ID)
      {
        LulStackBtm = Os_GulOsAppSPBtm[LpStaticTask->ddAppId];
        LulStackTop = Os_GulOsAppSPTop[LpStaticTask->ddAppId];
      }
      else
      {
        LulStackBtm = Os_GulUserSPBtm[OS_CORE_ID];
        LulStackTop = Os_GulUserSPTop[OS_CORE_ID];
      }
    }

    /* Check if the memory belongs to the stack area */
    if ((LulStartAddr >= LulStackTop) &&
                                       ((LulStartAddr + LulSize) < LulStackBtm))
    {
      /* Return Read Write access */
      LucReturnVal = OS_READ_WRITE;
    }
    /* Else check Application Memory Blocks */
    else
    {
      LucMemBlkIdx = LpStaticApplication->ucBaseMemBlockIndex;
      LucCount = LpStaticApplication->ucNoOfMemBlk;

      for (LucIndex = LucMemBlkIdx;
                               LucIndex < (LucMemBlkIdx + LucCount); LucIndex++)
      {
        LulBaseAddr = Os_GaaStaticMemBlock[LucIndex].ddRegionBaseAddress;
        /* MPU Region Size = 2^(x+1), x is a MPU region size bits */
        LulMpuRegionSize = Os_GaaStaticMemBlock[LucIndex].ddRegionSizeAndEnable;
        LulMpuRegionSize = (LulMpuRegionSize & OS_MPU_RASR_SIZE_MSK) >> 1;
        LulMpuRegionSize = (uint32)1 << (LulMpuRegionSize + 1u);
        /* Check if the memory belongs to the descriptor configured */
        if ((LulStartAddr >= LulBaseAddr) &&
                 ((LulStartAddr + LulSize) <= (LulBaseAddr + LulMpuRegionSize)))
        {
          LulRegionAccess = Os_GaaStaticMemBlock[LucIndex].ddRegionSizeAndEnable;
          LulRegionAccess &= OS_MPU_RASR_AP_MSK;
          if (LulRegionAccess == OS_CY_MPU_ACCESS_P_FULL_ACCESS)
          {
            LucReturnVal = OS_READ_WRITE;
          }
          else if ((LulRegionAccess == OS_CY_MPU_ACCESS_P_PRIV_RW_USER_RO) ||
                   (LulRegionAccess == OS_CY_MPU_ACCESS_P_RO))
          {
            LucReturnVal = OS_READ_ONLY;
          }
          else
          {
            /* continue loop */
          }
          if (LucReturnVal != NO_ACCESS)
          {
            break;
          }
        }
      }
    } /* End of else */
  } /* End of if (LpStaticApplication->ucType != OS_TRUSTED) */
  else
  {
    /* Return Full access */
    LucReturnVal = OS_READ_WRITE;
  }
  return (LucReturnVal);
} /* End of Os_CheckMemoryAccessService(ObjectTypeType LddTaskID,
   *MemoryStartAddressType LddStartAddr, MemorySizeType LulSize) */
#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

#if(OS_MEMORY_PROTECTION == STD_ON)
static FUNC(os_cy_en_mpu_region_size_t, OS_CODE) Os_ConvMpuRegion(uint32 LulSize)
{
  volatile os_cy_en_mpu_region_size_t LddRegSize = OS_CY_MPU_SIZE_2B;

  if (LulSize == 0x00000020u)
  {
    LddRegSize = OS_CY_MPU_SIZE_32B;
  }
  else if (LulSize == 0x00000040u)
  {
    LddRegSize = OS_CY_MPU_SIZE_64B;
  }
  else if (LulSize == 0x00000080u)
  {
    LddRegSize = OS_CY_MPU_SIZE_128B;
  }
  else if (LulSize == 0x00000100u)
  {
    LddRegSize = OS_CY_MPU_SIZE_256B;
  }
  else if (LulSize == 0x00000200u)
  {
    LddRegSize = OS_CY_MPU_SIZE_512B;
  }
  else if (LulSize == 0x00000400u)
  {
    LddRegSize = OS_CY_MPU_SIZE_1KB;
  }
  else if (LulSize == 0x00000800u)
  {
    LddRegSize = OS_CY_MPU_SIZE_2KB;
  }
  else if (LulSize == 0x00001000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_4KB;
  }
  else if (LulSize == 0x00002000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_8KB;
  }
  else if (LulSize == 0x00004000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_16KB;
  }
  else if (LulSize == 0x00008000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_32KB;
  }
  else if (LulSize == 0x00010000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_64KB;
  }
  else if (LulSize == 0x00020000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_128KB;
  }
  else if (LulSize == 0x00040000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_256KB;
  }
  else if (LulSize == 0x00080000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_512KB;
  }
  else if (LulSize == 0x00100000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_1MB;
  }
  else if (LulSize == 0x00200000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_2MB;
  }
  else if (LulSize == 0x00400000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_4MB;
  }
  else if (LulSize == 0x00800000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_8MB;
  }
  else if (LulSize == 0x01000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_16MB;
  }
  else if (LulSize == 0x02000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_32MB;
  }
  else if (LulSize == 0x04000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_64MB;
  }
  else if (LulSize == 0x08000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_128MB;
  }
  else if (LulSize == 0x10000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_256MB;
  }
  else if (LulSize == 0x20000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_512MB;
  }
  else if (LulSize == 0x40000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_1GB;
  }
  else if (LulSize == 0x80000000u)
  {
    LddRegSize = OS_CY_MPU_SIZE_2GB;
  }
  else
  {
    LddRegSize = OS_CY_MPU_SIZE_4GB;
  }

  return LddRegSize;
}

static FUNC(os_cy_en_mpu_status_t, OS_CODE) Os_SetMpuRegion(
                                                      const uint32 LuiRegionNumber, 
                                                      const uint32 LuiRegionBaseAddress, 
                                                      const uint32 LuiRegionSizeAndEnable)
{
  volatile os_cy_en_mpu_status_t LddReturnvalue = OS_CY_MPU_SUCCESS;

  if (OS_MPU.ulType == 0x0u)
  {
    LddReturnvalue = OS_CY_MPU_FAILURE;
  }

  if (LddReturnvalue == OS_CY_MPU_SUCCESS)
  {
    if (LuiRegionNumber >= OS_MPU_MAX_NUM)
    {
      LddReturnvalue = OS_CY_MPU_FAILURE;
    }
  }

  if (LddReturnvalue == OS_CY_MPU_SUCCESS)
  {
    /* polyspace:begin<MISRA-C3:D4.3:Not a defect:Justify with annotations> need to use assembly code */
    /* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> need to use assembly code */
    /* Ensure all memory accesses are completed before new memory access is committed */
    __asm("DMB");

    /* Select which MPU region to configure */
    OS_MPU.ulRnr = LuiRegionNumber;

    /* Configure  region  base  address register */
    /* VALID and REGION field of RBAR register will be 0 since this function sets RNR register manually. */
    OS_MPU.ulRbar = (LuiRegionBaseAddress & OS_MPU_RBAR_ADDR_MSK);

    /* Configure region attribute and size register */
    OS_MPU.ulRasr = LuiRegionSizeAndEnable;

    /* Ensure all memory accesses are completed before next instruction is executed */
    __asm("DSB");

    /* Flush the pipeline and ensure all previous instructions are completed before executing new instructions */
    __asm("ISB");
    /* polyspace:end<MISRA-C3:D4.3> */
    /* polyspace:end<MISRA-C3:1.1> */
  }

  return LddReturnvalue;
}
#endif
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END(MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:end<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:end<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<MISRA-C3:5.4:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<MISRA-C3:11.3:Not a defect:Justify with annotations> Cast is needed for implementation */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<MISRA-C3:11.5:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<MISRA-C3:11.8:Not a defect:Justify with annotations> Cast is needed for implementation */
/* polyspace:end<MISRA-C3:18.4:Not a defect:Justify with annotations> Operators on pointer is used for better performance */
/* polyspace:end<MISRA-C3:20.1:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
