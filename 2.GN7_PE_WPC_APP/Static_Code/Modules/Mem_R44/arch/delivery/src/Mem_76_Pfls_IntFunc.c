/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: Mem_76_Pfls_IntFunc.c                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Memory Driver                                         **
**                                                                            **
**  PURPOSE   :                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                        Description              **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Mem_76_Pfls_Cfg.h"
#include "Mem_76_Pfls_Types.h"
#include "Mem_76_Pfls_IntFunc.h"
#include "Mem_76_Pfls_Globals.h"
#include "Mem_76_Pfls_Regs.h"
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#include "SchM_Mem_76_Pfls.h"
#endif
/* polyspace-begin MISRA-C3:8.9,20.9 [Not a defect: Justify with annotations] "No Impact of this rule violation" */

/*******************************************************************************
**                         Macros                                             **
*******************************************************************************/
/* @Trace: Mem_76_Pfls_SUD_MACRO_005 */
#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT2B6X)
#define CY_FLASH_SM_DBM0_BASE           0x10038000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00010000UL
#define CY_FLASH_SM_SBM_BASE            0x10070000UL
#define CY_FLASH_SM_SBM_SIZE            0x00020000UL
#endif

#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT2B7X)
#define CY_FLASH_SM_DBM0_BASE           0x10078000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00010000UL
#define CY_FLASH_SM_SBM_BASE            0x100F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00020000UL
#endif

#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT2B9X)
#define CY_FLASH_SM_DBM0_BASE           0x100F8000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00010000UL
#define CY_FLASH_SM_SBM_BASE            0x101F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00020000UL
#endif

#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT2BLX_CYT3BX_CYT4BBX)
#define CY_FLASH_SM_DBM0_BASE           0x101F8000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00010000UL
#define CY_FLASH_SM_SBM_BASE            0x103F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00020000UL
#endif

#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT4BFX)
#define CY_FLASH_SM_DBM0_BASE           0x103F8000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00020000UL
#define CY_FLASH_SM_SBM_BASE            0x107F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00040000UL
#endif

#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT6BJX)
#define CY_FLASH_SM_DBM0_BASE           0x103F8000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00020000UL
#define CY_FLASH_SM_SBM_BASE            0x107F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00040000UL

#define CY_FLASH1_SM_DBM0_BASE          0x183F8000UL
#define CY_FLASH1_SM_DBM0_SIZE          0x00020000UL
#define CY_FLASH1_SM_DBM1_BASE          0x1A3F8000UL
#define CY_FLASH1_SM_DBM1_SIZE          0x00020000UL
#define CY_FLASH1_SM_SBM_BASE           0x187F0000UL
#define CY_FLASH1_SM_SBM_SIZE           0x00040000UL

#define CY_FLASH_ADDRESS_UPPER_8MB      0x18000000UL

#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
static Mem_76_Pfls_SwapStateType Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_INACTIVE;

static uint32 Mem_76_Pfls_ActiveBankType;

#define MEM_76_PFLS_START_SEC_CONST_32
#include "MemMap.h"


#define MEM_76_PFLS_STOP_SEC_CONST_32
#include "MemMap.h"


// allocate this variable in the SRAM, used to program of erase the flash
static Mem_76_Pfls_AddressType Mem_76_Pfls_GblSramScratchAddr[4U];


/*******************************************************************************
**                      Function Declaration                                  **
*******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Mem_76_Pfls_CalBankAddress                          **
**                                                                            **
** Description          : This function calculate B-bank address              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Address                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Mem_76_Pfls_AddressType                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 */
/* polyspace-begin MISRA-C3:2.7 [Justified:Low] "Not a defect" */
FUNC(Mem_76_Pfls_AddressType, MEM_76_PFLS_CODE) Mem_76_Pfls_CalBankAddress(\
  Mem_76_Pfls_InstanceIdType instanceId,
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address)
/* polyspace-end MISRA-C3:2.7 [Justified:Low] "Not a defect" */
{
  /* @Trace: Mem_76_Pfls_SUD_FUNC_086 */
  Mem_76_Pfls_AddressType targetAddress;

  targetAddress = Address;

  return targetAddress;
}

#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Mem_76_Pfls_InternalInitialize                      **
**                                                                            **
** Description          : The function aims to initialize Pflash for specific **
**                        MCU                                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : void                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14037 */
FUNC(void, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalInitialize(void)
{
  /* @Trace: Mem_76_Pfls_SUD_FUNC_067 */
  MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_RELEASE) = MEM_76_PFLS_VALUE_RELEASE_IPC_STRUCT;

  /* Enable the main flash embedded operation */
  MEM_76_PFLS_REG(MEM_76_PFLS_FLASHC_MAIN_FLASH_SAFETY)  = MEM_76_PFLS_ONE;
  
#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT6BJX)
  MEM_76_PFLS_REG(MEM_76_PFLS_FLASHC1_MAIN_FLASH_SAFETY) = MEM_76_PFLS_ONE;
#endif
  /* Store the SRAM address in IPC structure */
  /* polyspace +2 MISRA-C3:11.4 [Justified:Low] "The integer value represents the memory address. It should be casted to an address so that
    * the memory can be accessed through a pointer. The violation has no impact" */
  MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_DATA0) = (uint32)Mem_76_Pfls_GblSramScratchAddr;

}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Mem_76_Pfls_InternalRead                            **
**                                                                            **
** Description          : This function used to read data from memory to data **
**                        buffer using Flash register                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Address                                             **
**                        DataPtr                                             **
**                        Length                                              **
**                        BurstEnable                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Mem_76_Pfls_JobResultType                           **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_START_SEC_RAM_CODE
#else
#define MEM_76_PFLS_START_SEC_CODE
#endif
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 */
FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalRead(\
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) DataPtr, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) Length, \
  CONST(uint8, MEM_76_PFLS_CONST) BurstEnable)
{
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC)                        dataLength;
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr;
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC)                       memoryAddress;
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC)                     retVal;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_087 */ 
  if(NULL_PTR == DataPtr)
  {
    retVal = MEM_JOB_FAILED;
  }
  else
  {
    /* copy input */
    dataLength      = Length;
    memoryAddress   = Address;
    dataPtr         = DataPtr;

    /* Read from flash memory */
    while( MEM_76_PFLS_ZERO < dataLength )
    {
      /* get data from memory */
      /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
       * the register value can be read via the address" */
      * dataPtr = * (Mem_76_Pfls_DataType *) memoryAddress;
      /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
       * the register value can be read via the address" */
      /* point to the next address */
      dataPtr++;
      memoryAddress++;
      /* decrease data length */
      dataLength--;
    }
    retVal  = MEM_JOB_OK;
  }

  MEM_76_PFLS_UNUSED(BurstEnable);

  return retVal;
}

#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_STOP_SEC_RAM_CODE
#else
#define MEM_76_PFLS_STOP_SEC_CODE
#endif
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mem_76_Pfls_InternalErase                           **
**                                                                            **
** Description          : The function performs erase operation               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Address                                             **
**                        DataPtr                                             **
**                        Length                                              **
**                        BurstEnable                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Mem_76_Pfls_JobResultType                           **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_START_SEC_RAM_CODE
#else
#define MEM_76_PFLS_START_SEC_CODE
#endif
#include "MemMap.h"

/* polyspace-begin MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
/* @Trace: SRS_Mem_MemHwAb_14038 */
FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalErase(\
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) DataPtr, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) Length, \
  CONST(uint8, MEM_76_PFLS_CONST) BurstEnable)
/* polyspace-end MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
{
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC)                                  retVal;
  VAR(uint32, AUTOMATIC)                                                     eraseStatus;
  P2VAR(uint32, AUTOMATIC, MEM_76_PFLS_APPL_DATA)                            sRamAddress;
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC)                                    destAddress;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_088 */
  MEM_76_PFLS_UNUSED(Length);
  /* Release the IPC locks acquired if any */


  /* Load the SRAM address pointed by IPC structure */
  sRamAddress  = Mem_76_Pfls_GblSramScratchAddr;
  destAddress  = Address;

  /* Clear the SRAM memory */
  sRamAddress[MEM_76_PFLS_ZERO] = MEM_76_PFLS_ZERO;
  sRamAddress[MEM_76_PFLS_ONE] = MEM_76_PFLS_ZERO;

  MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT_ACQUIRE);

  if(MEM_76_PFLS_SUCCESS_MASK != (MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT_ACQUIRE)
        & MEM_76_PFLS_SUCCESS_MASK))
  {
#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT6BJX)
    if (destAddress >= CY_FLASH_ADDRESS_UPPER_8MB)
    {
      /* Write the erase opcode in the memory */
      sRamAddress[MEM_76_PFLS_ZERO] = (((uint32)MEM_76_PFLS_ERASE2_SECTOR_OPCODE << MEM_76_PFLS_OPCODE_BIT)
        | MEM_76_PFLS_BLOCKING);
    } 
    else 
#endif
    {
      /* Write the erase opcode in the memory */
      sRamAddress[MEM_76_PFLS_ZERO] = (((uint32)MEM_76_PFLS_ERASE_SECTOR_OPCODE << MEM_76_PFLS_OPCODE_BIT)
        | MEM_76_PFLS_BLOCKING);
    }

    sRamAddress[MEM_76_PFLS_ONE] = destAddress;

    /* Store the SRAM address in IPC structure */
    /* polyspace +2 MISRA-C3:11.4 [Justified:Low] "The integer value represents the memory address. It should be casted to an address so that
    * the memory can be accessed through a pointer. The violation has no impact" */
    MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_DATA0) = (uint32)Mem_76_Pfls_GblSramScratchAddr;
    /* Notify the flash driver */
    MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_NOTIFY) = MEM_76_PFLS_ONE;

    /* Wait for IPC structure to get locked */
    while(MEM_76_PFLS_ACQUIRED_MASK ==
      ((MEM_76_PFLS_REG(MEM_76_PFLS_STRUCT1_LOCK_STATUS) & MEM_76_PFLS_ACQUIRED_MASK)))
    {
      /*
      * Loop till IPC is acquired
      * If there is no IPC Aquire from M0+ Cypress ROM,
      * internal wdg reset will occurs
      */
      /*Wdg UnLock*/
      #if 0
      SRSS_WDG_LOCK->u2WDT_LOCK   = (uint8)1UL;
      SRSS_WDG_LOCK->u2WDT_LOCK   = (uint8)2UL;

      /* This resets the count value to zero */
      SRSS_WDG_SERVICE->u1SERVICE = (uint8)1UL;
      /*Wdg Lock*/
      SRSS_WDG_LOCK->u2WDT_LOCK   = (uint8)3UL;
      #endif
      /* @Trace: Mem_76_Pfls_SUD_MACRO_015 Mem_76_Pfls_SUD_MACRO_016 */
	    /* Watchdog trigger */  
      #if ((MEM_76_PFLS_RAMCODE_USED == STD_ON) && \
       (MEM_76_PFLS_WDG_CALLOUT_FUNCTION_SUPPORT == STD_ON))
      Mem_76_Pfls_WDTriggerFct();
      #endif
    }
  } /* End of If acquired */

  /* The result of SROM API calling is returned to the driver context */
  eraseStatus = sRamAddress[MEM_76_PFLS_ZERO];

  /* Check whether erase operation is successful */
  if(MEM_76_PFLS_ERASE_SUCCESS == eraseStatus)
  {
    retVal = MEM_JOB_OK;
  }
  else
  {
    retVal = MEM_JOB_FAILED;
  }


  return retVal;
}

#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_STOP_SEC_RAM_CODE
#else
#define MEM_76_PFLS_STOP_SEC_CODE
#endif
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Mem_76_Pfls_InternalWrite                           **
**                                                                            **
** Description          : The function performs write operation               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Address                                             **
**                        DataPtr                                             **
**                        Length                                              **
**                        BurstEnable                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : retVal                                              **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/

#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_START_SEC_RAM_CODE
#else
#define MEM_76_PFLS_START_SEC_CODE
#endif
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 */
FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_InternalWrite(\
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC) Address, \
  P2CONST(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_CONST) DataPtr, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) WriteNormalSize, \
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC) WriteBurstSize, \
  CONST(uint8, MEM_76_PFLS_CONST) BurstEnable)
{
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC)                                  retVal;
  VAR(Mem_76_Pfls_LengthType, AUTOMATIC)                                     length;
  VAR(uint32, AUTOMATIC)                                                     writeStatus;
  VAR(Mem_76_Pfls_AddressType, AUTOMATIC)                                    destTargetAddress;
  P2CONST(Mem_76_Pfls_AddressType, AUTOMATIC, MEM_76_PFLS_APPL_CONST)        srcDataPtr;
  P2VAR(Mem_76_Pfls_AddressType, AUTOMATIC, MEM_76_PFLS_APPL_DATA)           sRamAddress;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_092 */
  sRamAddress = Mem_76_Pfls_GblSramScratchAddr;
  
  if (BurstEnable == MEM_76_PFLS_TRUE)
  {
    length = WriteBurstSize;
  }
  else
  {
    length = WriteNormalSize;
  }
  

  destTargetAddress = Address;
  /* polyspace-begin MISRA-C3:11.3,11.8 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
   * the register value can be read via the address" */
  /* polyspace-begin CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
  srcDataPtr = (uint32 *)DataPtr;
  /* polyspace-end MISRA-C3:11.3,11.8 [Justified:Medium] "The integer value represents the register address. It should be casted to an address so that
   * the register value can be read via the address" */
  /* polyspace-end CERT-C:EXP39-C [Justified:Low] "This conversion is used for OSS. they are same type" */
  
  MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_RELEASE) = MEM_76_PFLS_VALUE_RELEASE_IPC_STRUCT;

  sRamAddress[MEM_76_PFLS_ZERO] = (uint32)MEM_76_PFLS_ZERO;
  sRamAddress[MEM_76_PFLS_ONE] = (uint32)MEM_76_PFLS_ZERO;
  sRamAddress[MEM_76_PFLS_TWO] = (uint32)MEM_76_PFLS_ZERO;
  sRamAddress[MEM_76_PFLS_THREE] = (uint32)MEM_76_PFLS_ZERO;
  MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT_ACQUIRE);
  if(MEM_76_PFLS_SUCCESS_MASK != (MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT_ACQUIRE)
        & MEM_76_PFLS_SUCCESS_MASK))
  {
#if (MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT6BJX)
    if (destTargetAddress >= CY_FLASH_ADDRESS_UPPER_8MB)
    {
      /* Store the program row opcode in SRAM */
      sRamAddress[MEM_76_PFLS_ZERO] = (uint32)((uint32)((uint32)MEM_76_PFLS_PROGRAM2_ROW_OPCODE
          << (uint32)MEM_76_PFLS_OPCODE_BIT) | (uint32)MEM_76_PFLS_SKIP_BLANK_CHECK
          | (uint32)MEM_76_PFLS_BLOCKING);
    }
    else
#endif
    {
      /* Store the program row opcode in SRAM */
      sRamAddress[MEM_76_PFLS_ZERO] = (uint32)((uint32)((uint32)MEM_76_PFLS_PROGRAM_ROW_OPCODE
          << (uint32)MEM_76_PFLS_OPCODE_BIT) | (uint32)MEM_76_PFLS_SKIP_BLANK_CHECK
          | (uint32)MEM_76_PFLS_BLOCKING);
    }
    if(length == MEM_76_PFLS_NUM_8)
    {
      sRamAddress[MEM_76_PFLS_ONE] = (uint32)MEM_76_PFLS_WRITE_8_CFG;
    }
    else if (length == MEM_76_PFLS_NUM_32)
    {
      sRamAddress[MEM_76_PFLS_ONE] = (uint32)MEM_76_PFLS_WRITE_32_CFG;
    }
    else if (length == MEM_76_PFLS_NUM_512)
    {
      sRamAddress[MEM_76_PFLS_ONE] = (uint32)MEM_76_PFLS_WRITE_512_CFG;
    }
    else
    {
      /* Do Nothing */
    }
    /* Store the destination address in SRAM */
    sRamAddress[MEM_76_PFLS_TWO] = (Mem_76_Pfls_AddressType)destTargetAddress;
    /* polyspace-begin MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
     * the register value can be read via the address" */
    sRamAddress[MEM_76_PFLS_THREE] = (Mem_76_Pfls_AddressType)srcDataPtr;
    /* Store the SRAM address in IPC structure */
    MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_DATA0) = (uint32)Mem_76_Pfls_GblSramScratchAddr;
    /* polyspace-end MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
     * the register value can be read via the address" */
    /* Notify the flash driver */
    MEM_76_PFLS_REG(MEM_76_PFLS_IPC_STRUCT1_NOTIFY) |= MEM_76_PFLS_ONE;

    /* Wait for IPC structure to get locked */
    while (MEM_76_PFLS_ACQUIRED_MASK ==
      ((MEM_76_PFLS_REG(MEM_76_PFLS_STRUCT1_LOCK_STATUS) & MEM_76_PFLS_ACQUIRED_MASK)))
    {
      /*
        * Loop till IPC is acquired
        * If there is no IPC Aquire from M0+ Cypress ROM,
        * internal wdg reset will occurs
        */
    }

  }
  writeStatus = sRamAddress[MEM_76_PFLS_ZERO];
  if (writeStatus == MEM_76_PFLS_WRITE_SUCCESS)
  {
    retVal = MEM_JOB_OK;
  }
  else
  {
    retVal = MEM_JOB_FAILED;
  }

  return retVal;
}
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_STOP_SEC_RAM_CODE
#else
#define MEM_76_PFLS_STOP_SEC_CODE
#endif
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Mem_76_Pfls_ToolBox_InternalActive                  **
**                                                                            **
** Description          : Function to Copy flash driver from ROM to RAM       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#if (MEM_76_PFLS_RAMCODE_USED == STD_ON)
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 SRS_Mem_MemHwAb_14039 SRS_Mem_MemHwAb_14056 */
/* Function to Copy Flash driver from ROM to RAM  */
FUNC(void, MEM_76_PFLS_CODE) Mem_76_Pfls_ToolBox_InternalActive(void)
{
  P2VAR(Mem_76_Pfls_AddressType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) DestAddr;
  P2VAR(Mem_76_Pfls_AddressType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) SrcAddr;
  VAR(uint32,AUTOMATIC) CopySize;
  VAR(uint32,AUTOMATIC) count;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_103 */
  /* polyspace-begin MISRA-C3:11.8 [Justified:Low]"Not a defect. Type cast for memcpy is safe" */
  /* get the start address of Flash driver Part that will be copied to RAM */
  SrcAddr = (Mem_76_Pfls_AddressType *)&__Mem_76_Pfls_RomStart;

  /* get the end address of Flash driver Part that will be copied to RAM */
  DestAddr = (Mem_76_Pfls_AddressType *)&__Mem_76_Pfls_RamCode;
  /* polyspace-end MISRA-C3:11.8 [Justified:Low]"Not a defect. Type cast for memcpy is safe" */

  /* Size of Flash driver part which will be copied to RAM */
  /* polyspace-begin MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
   * the register value can be read via the address" */
  CopySize = (uint32)&__Mem_76_Pfls_RomSize;
  /* polyspace-end MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
   * the register value can be read via the address" */

  /* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.1,11.4 [Justified:Low] "Copy a Part of Flash driver from ROM to RAM" */
  for (count = MEM_76_PFLS_ZERO;count < CopySize;count++)
  {
      DestAddr[count] = SrcAddr[count];
  }
  /* polyspace-end CERT-C:INT36-C, MISRA-C3:11.1,11.4 [Justified:Low] "Copy a Part of Flash driver from ROM to RAM" */
  Mem_76_Pfls_InternalReadRamFunction  = &Mem_76_Pfls_InternalRead;
  Mem_76_Pfls_InternalWriteRamFunction = &Mem_76_Pfls_InternalWrite;
  Mem_76_Pfls_InternalEraseRamFunction = &Mem_76_Pfls_InternalErase;

  #if (MEM_76_PFLS_WDG_CALLOUT_FUNCTION_SUPPORT == STD_ON)
  Mem_76_Pfls_WDTriggerFct             = MEM_76_PFLS_WDG_TRIGGER_CALLOUT_FUNCTION;
  #endif
}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Mem_76_Pfls_ActiveBankCheck                         **
**                                                                            **
** Description          : This function used to check active bank from pfls   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : instanceId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataPtr                                             **
**                        lengthPtr                                           **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
/* @Trace: SRS_Mem_MemHwAb_14038 SRS_Mem_MemHwAb_14039 SRS_Mem_MemHwAb_14056 */
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_ActiveBankCheck(\
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr)
{
  /* @Trace: Mem_76_Pfls_SUD_DATATYPE_009  */
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_077 */ 
  retVal = E_OK;

  if (MEM_76_PFLS_FLASH_MAP_MASK != (MEM_76_PFLS_REG(FLASHC_FLASH_CTL) &
                                                  MEM_76_PFLS_FLASH_MAP_MASK))
  {
    *dataPtr=(Mem_76_Pfls_DataType)MEM_76_PFLS_STD_BLOCK;
  }
  else
  {
    *dataPtr=(Mem_76_Pfls_DataType)MEM_76_PFLS_ALT_BLOCK;
  }
  *lengthPtr = (Mem_76_Pfls_LengthType)MEM_76_PFLS_ONE;

  return retVal;
}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mem_76_Pfls_DirectAddressAccess                     **
**                                                                            **
** Description          : This function used to access direct address         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataPtr                                             **
**                        lengthPtr                                           **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 SRS_Mem_MemHwAb_14039 SRS_Mem_MemHwAb_14056 */
FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_DirectAddressAccess(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr)
{
  /* @Trace: Mem_76_Pfls_SUD_DATATYPE_009  */
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  P2VAR(Mem_76_Pfls_InstanceInfoType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) instanceInforPtr;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_110 */
  retVal = E_OK;

  instanceInforPtr  = &Mem_76_Pfls_InstanceInfo[instanceId];

  instanceInforPtr->AltAddressAccess = FALSE;

  *dataPtr=(Mem_76_Pfls_DataType)instanceInforPtr->AltAddressAccess;
  *lengthPtr=sizeof(boolean);

  return retVal;
}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mem_76_Pfls_AltAddressAccess                        **
**                                                                            **
** Description          : This function used to access alt address            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataPtr                                             **
**                        lengthPtr                                           **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
/* @Trace: SRS_Mem_MemHwAb_14038 SRS_Mem_MemHwAb_14039 SRS_Mem_MemHwAb_14056 */
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_AltAddressAccess(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr)
{
  /* @Trace: Mem_76_Pfls_SUD_DATATYPE_009  */
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  P2VAR(Mem_76_Pfls_InstanceInfoType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) instanceInforPtr;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_111 */
  retVal = E_OK;

  instanceInforPtr  = &Mem_76_Pfls_InstanceInfo[instanceId];

  instanceInforPtr->AltAddressAccess = TRUE;

  *dataPtr=(Mem_76_Pfls_DataType)instanceInforPtr->AltAddressAccess;
  *lengthPtr=sizeof(boolean);

  return retVal;
}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mem_76_Pfls_SwapActive                              **
**                                                                            **
** Description          : This function used to request SwapActive to HSE     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : instanceId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataPtr                                             **
**                        lengthPtr                                           **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 SRS_Mem_MemHwAb_14039 SRS_Mem_MemHwAb_14056 */
/* polyspace-begin MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
FUNC(Std_ReturnType, MEM_76_PFLS_CODE) Mem_76_Pfls_SwapActive(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) instanceId, \
  P2VAR(Mem_76_Pfls_DataType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) dataPtr, \
  P2VAR(Mem_76_Pfls_LengthType, AUTOMATIC, MEM_76_PFLS_APPL_DATA) lengthPtr)
/* polyspace-end MISRA-C3:2.7,8.13 [Justified:Low] "Not a defect" */
{
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_112 */
  retVal = E_OK;

  Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_GET_ACTIVE_BANK;

  /* Set Job result */
  Mem_76_Pfls_InstanceInfo[instanceId].JobResult  = MEM_JOB_PENDING;
  /* Set current job */
  Mem_76_Pfls_InstanceInfo[instanceId].CurrentJob = MEM_76_PFLS_JOB_SWAP;

  return retVal;
}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mem_76_Pfls_JobSwapProcess                          **
**                                                                            **
** Description          : This function used to check result of Swap request  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : instanceId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CODE
#include "MemMap.h"
/* @Trace: SRS_Mem_MemHwAb_14038 */
/* polyspace-begin MISRA-C3:2.7 [Justified:Low] "Not a defect" */
FUNC(Mem_76_Pfls_JobResultType, MEM_76_PFLS_CODE) Mem_76_Pfls_JobSwapProcess(\
  VAR(Mem_76_Pfls_InstanceIdType, AUTOMATIC) InstanceId)
/* polyspace-end MISRA-C3:2.7 [Justified:Low] "Not a defect" */
{
  VAR(Mem_76_Pfls_JobResultType, AUTOMATIC) jobResult;
  VAR(Std_ReturnType, AUTOMATIC) retVal;
  static VAR(uint32, AUTOMATIC) bankType;
  static VAR(uint32, AUTOMATIC) maxWait;
  /* @Trace: Mem_76_Pfls_SUD_FUNC_072 */ 
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  retVal=E_NOT_OK;
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
  jobResult = MEM_JOB_FAILED;

  switch(Mem_76_Pfls_SwapState)
  {
    case MEM_76_PFLS_SWAP_INACTIVE:
      break;

    case MEM_76_PFLS_SWAP_GET_ACTIVE_BANK:
      jobResult = MEM_JOB_PENDING;
      retVal = Mem_76_Pfls_GetNextBootActiveBank_Callout(&Mem_76_Pfls_ActiveBankType);

      if(retVal==E_OK)
      {


        maxWait=0UL;
        bankType=0UL;
        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_GET_ACTIVE_BANK_CHK;
      }
      else
      {
        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
      }
      break;

    case MEM_76_PFLS_SWAP_GET_ACTIVE_BANK_CHK:
      jobResult = MEM_JOB_PENDING;
      retVal = Mem_76_Pfls_WaitObjResp_Callout();

      if(retVal==E_OK)
      {


        if((Mem_76_Pfls_ActiveBankType!=OMEN_BANKINFO_TYPE_A)&&(Mem_76_Pfls_ActiveBankType!=OMEN_BANKINFO_TYPE_B))
        {
          /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
          retVal=E_NOT_OK;
          /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "No Impact of this rule violation" */
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
        }
        else if(((MEM_76_PFLS_FLASH_MAP_MASK != (MEM_76_PFLS_REG(FLASHC_FLASH_CTL) & MEM_76_PFLS_FLASH_MAP_MASK)) && /* Active Bank A */
               (Mem_76_Pfls_ActiveBankType==OMEN_BANKINFO_TYPE_B)) ||                                                 /* Next Active Bank B */
                ((MEM_76_PFLS_FLASH_MAP_MASK == (MEM_76_PFLS_REG(FLASHC_FLASH_CTL) & MEM_76_PFLS_FLASH_MAP_MASK)) && /* Active Bank B */
               (Mem_76_Pfls_ActiveBankType==OMEN_BANKINFO_TYPE_A)))                                                  /* Next Active Bank A */
        {/* Already Swap request complete */
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_END;
        }
        else
        {
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_SET_ACTIVE_BANK;
        }
      }
      else
      {
        maxWait++;
        if(maxWait>MEM_76_PFLS_MAX_WAIT_CNT)
        {
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
        }
      }

      break;

    case MEM_76_PFLS_SWAP_SET_ACTIVE_BANK:
      jobResult = MEM_JOB_PENDING;
      if(Mem_76_Pfls_ActiveBankType==OMEN_BANKINFO_TYPE_A)
      {
        bankType=OMEN_BANKINFO_TYPE_B;
      }
      else
      {
        bankType=OMEN_BANKINFO_TYPE_A;
      }

      retVal = Mem_76_Pfls_SetNextBootActiveBank_Callout(bankType);

      if(retVal==E_OK)
      {


        maxWait=0UL;
        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_SET_ACTIVE_BANK_CHK;
      }
      else
      {
        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
      }
      break;

    case MEM_76_PFLS_SWAP_SET_ACTIVE_BANK_CHK:
      jobResult = MEM_JOB_PENDING;
      retVal = Mem_76_Pfls_WaitObjResp_Callout();

      if(retVal==E_OK)
      {


        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_NEXT_BANK_VERIFY;
      }
      else
      {
        maxWait++;
        if(maxWait>MEM_76_PFLS_MAX_WAIT_CNT)
        {
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
        }
      }
      break;
	  
    case MEM_76_PFLS_SWAP_NEXT_BANK_VERIFY:
      jobResult = MEM_JOB_PENDING;
      retVal = Mem_76_Pfls_GetNextBootActiveBank_Callout(&Mem_76_Pfls_ActiveBankType);
	  
      if(retVal==E_OK)
      {


        maxWait=0UL;
        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_NEXT_BANK_VERIFY_CHK;
      }
      else
      {
        Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
      }
      break;
	  
    case MEM_76_PFLS_SWAP_NEXT_BANK_VERIFY_CHK:
      jobResult = MEM_JOB_PENDING;
      retVal = Mem_76_Pfls_WaitObjResp_Callout();
	  
      if(retVal==E_OK)
      {


        if(Mem_76_Pfls_ActiveBankType==bankType)
        {
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_END;
        }
        else
        {
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
        }
      }
      else
      {
        maxWait++;
        if(maxWait>MEM_76_PFLS_MAX_WAIT_CNT)
        {
          Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_ERR;
        }
      }
	  
      break;

    case MEM_76_PFLS_SWAP_END:
      jobResult = MEM_JOB_OK;
      Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_INACTIVE;
      break;

    case MEM_76_PFLS_SWAP_ERR:
      jobResult = MEM_JOB_FAILED;
      Mem_76_Pfls_SwapState = MEM_76_PFLS_SWAP_INACTIVE;
      break;

    default:
      /* Do Nothing */
      break;
  }

  return jobResult;
}
#define MEM_76_PFLS_STOP_SEC_CODE
#include "MemMap.h"

/* polyspace-end MISRA-C3:8.9,20.9 [Not a defect: Justify with annotations] "No Impact of this rule violation" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
