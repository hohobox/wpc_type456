/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE:                                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : BOOTLOADER                                                    **
**                                                                            **
**  PURPOSE   :                                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Revision History                               **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.1.6.0	   18-Feb-2025   KJShim       CP44-16439                          **
*******************************************************************************/

/*******************************************************************************
**                              Include Section                               **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.9 [Justified:Low] "Not a defect" */
#include "Fota_User_Callouts.h"
#include "Fota_Callout_Fixed.h"

#ifndef FOTA_INTEGRATION_SINGLEMEM_PLATFORM

#include "Fota_IntTypes.h"
#include "Fota_Globals.h"

#include "Fota_PflsInterface.h"
#include "Fota_NonMmuSubFunc.h"

#if (HWRESOURCE_FAMILY(HWRESOURCE_CYT2BXX)) || (HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX)) || \
    (HWRESOURCE_FAMILY(HWRESOURCE_CYT6BXX))
#include "arm_ghs.h"
#endif

/*******************************************************************************
**                             Macro Definition                               **
*******************************************************************************/

/*******************************************************************************
**                            Global Data Types                               **
*******************************************************************************/

/*******************************************************************************
**                              Global Data                                   **
*******************************************************************************/

/*******************************************************************************
**                          Function Definitions                              **
*******************************************************************************/
#if FOTA_BOOT_MANAGER_USED

/*******************************************************************************
** Function Name        : Fota_FlashInit                                      **
**                                                                            **
** Description          : Function Initializing Flash.                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
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
********************************************************************************/
static FUNC(void, FOTA_CODE) Fota_FlashInit(void)
{
#if (HWRESOURCE_FAMILY(HWRESOURCE_CYT2BXX)) || (HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX)) || \
    (HWRESOURCE_FAMILY(HWRESOURCE_CYT6BXX))
  /*Enable writting main flash*/
  FOTA_REG(FOTA_MAIN_FLASH_SAFETY) = 1U;
  /*Disables CM0 cache*/
  FOTA_REG(FOTA_FLASHC_CM0_CA_CTL0) &= ~FOTA_FLASHC_CM0_CA_CTL0_CA_EN_MASK; /* CA_EN = 0U */
  /*Invalidates the flash cache and buffer*/
  FOTA_REG(FOTA_FLASHC_FLASH_CMD) |= FOTA_FLASHC_FLASH_CMD_INV_MASK; /* INV = 1U */
  /* Setting the Silent mode for avoid bus error (Hard Fault) */
  FOTA_REG(FOTA_FLASHC_FLASH_CTL) &= ~FOTA_FLASHC_FLASH_CTL_MAIN_ERR_SILENT_MASK; /* MAIN_ERR_SILENT = 0UL */
#else

#endif
}

/*******************************************************************************
** Function Name        : Fota_PrepareForApplEntry                            **
**                                                                            **
** Description          : The Fota_PrepareForApplEntry API is called just     **
**                        before entering to valid application.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
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
FUNC(void, FOTA_CODE) Fota_PrepareForApplEntry(void)
{
  /* Initializing Flash. */
  /* polyspace-begin MISRA-C3:2.2 [Justified:Low] "if-condition depends on the MCU." */
  Fota_FlashInit();
  /* polyspace-end MISRA-C3:2.2 [Justified:Low] "if-condition depends on the MCU." */
  
#if (HWRESOURCE_FAMILY(HWRESOURCE_CYT2BXX)) || (HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX)) || \
    (HWRESOURCE_FAMILY(HWRESOURCE_CYT6BXX))
  /* Disable ECC ERROR Interrupt for Jump RTSW*/
  FOTA_REG(FOTA_FAULT_STRUCT3_MASK1) = 0x00000000UL;

  /* Set PRIMASK to 0 (Initial Value) for jump RTSW
   * Enable Interrupts(instruction is equivalent to writing a 0 into PRIMASK)
   * It should be located before Icu_SetMode(), because ICU ISR should be
   * executed before peripheral flag cleared by Icu_SetMode()
   */
  __CPS(__CPS_ENABLE, __CPS_I, __CPS_DEFAULT);
  __ISB();
#else

#endif
}

#endif /* FOTA_BOOT_MANAGER_USED */

#endif /* #ifndef FOTA_INTEGRATION_SINGLEMEM_PLATFORM */

#if (HWRESOURCE_FAMILY(HWRESOURCE_S32K31X))
FUNC (Fota_EccStatusType, FOTA_CODE) Fota_EccHandler
(
  VAR(uint32, AUTOMATIC) FaultAddress
)
{
  Fota_EccStatusType Ret_Ecc;

  #ifndef FOTA_INTEGRATION_SINGLEMEM_PLATFORM
  Std_ReturnType Ret_Offset;

  uint8 Lu8_AltAddress[FOTA_MCU_FOUR];
  uint8 Lu8_GetAltAddressFlag;
  uint8 Lu8_Index;
  uint8 blockIndex;
  uint32 Lu32_Length_Dummy;
  uint32 Lu32_AltAddress;
  uint32 Lu32_TargetAddress;
  uint32 Lu32_Offset;
  const Fota_SwModule* SwModulePtr;
  const Fota_TargetBlockType* TargetBlockTypePtr;
  const Fota_TargetBlockSwUnitType* TargetBlockSwUnitTypePtr;

  Ret_Ecc = FOTA_ECC_NONE;
  Lu32_Length_Dummy = FOTA_MCU_ONE;

  /* Loop Each SwUnit (Fota_Gast_SwUnitTable) */
  for(Lu8_Index = FOTA_MCU_ZERO; Lu8_Index < FOTA_NUM_OF_SWUNIT; Lu8_Index++)
  {
    Lu8_GetAltAddressFlag = E_NOT_OK;

    SwModulePtr = &Fota_Gast_SwUnitTable[Lu8_Index];
    TargetBlockTypePtr = SwModulePtr->TargetBlockInfoPtr;
    TargetBlockSwUnitTypePtr = TargetBlockTypePtr->TargetBlockSwUnitPtr;

    /* Loop Each TargetBlock of Each SwUnit (Fota_Gast_SwUnitTable) */
    for(blockIndex = FOTA_MCU_ZERO; blockIndex < TargetBlockTypePtr->NumOfBlock; blockIndex++)
    {
      /* BlockType : FIRMWARE, PARTITION_FLAG, SIGNATURE */
      if(TargetBlockSwUnitTypePtr[blockIndex].BlockType != FOTA_METADATA)
      {
        /* Get AltAddress to Calculate AltAddress Offset*/
        if(Lu8_GetAltAddressFlag == E_NOT_OK)
        {
          /* Find AltAddress only once for each SwUnit */
          Lu8_GetAltAddressFlag = E_OK;

          /* Pre-Job of Getting AltAddress Offset */
          /* TargetBlockSwUnitTypePtr[blockIndex].StartAddress to Lu8_AltAddress[0~3] */
          #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
          Lu8_AltAddress[FOTA_MCU_ZERO] = (uint8)(TargetBlockSwUnitTypePtr[blockIndex].StartAddress & FOTA_MCU_0xFF);
          Lu8_AltAddress[FOTA_MCU_ONE] = (uint8)((TargetBlockSwUnitTypePtr[blockIndex].StartAddress >> FOTA_MCU_EIGHT) & FOTA_MCU_0xFF);
          Lu8_AltAddress[FOTA_MCU_TWO] = (uint8)((TargetBlockSwUnitTypePtr[blockIndex].StartAddress >> FOTA_MCU_SIXTEEN) & FOTA_MCU_0xFF);
          Lu8_AltAddress[FOTA_MCU_THREE] = (uint8)((TargetBlockSwUnitTypePtr[blockIndex].StartAddress >> FOTA_MCU_TWENTYFOUR) & FOTA_MCU_0xFF);
          #else
          Lu8_AltAddress[FOTA_MCU_THREE] = (uint8)(TargetBlockSwUnitTypePtr[blockIndex].StartAddress & FOTA_MCU_0xFF);
          Lu8_AltAddress[FOTA_MCU_TWO] = (uint8)((TargetBlockSwUnitTypePtr[blockIndex].StartAddress >> FOTA_MCU_EIGHT) & FOTA_MCU_0xFF);
          Lu8_AltAddress[FOTA_MCU_ONE] = (uint8)((TargetBlockSwUnitTypePtr[blockIndex].StartAddress >> FOTA_MCU_SIXTEEN) & FOTA_MCU_0xFF);
          Lu8_AltAddress[FOTA_MCU_ZERO] = (uint8)((TargetBlockSwUnitTypePtr[blockIndex].StartAddress >> FOTA_MCU_TWENTYFOUR) & FOTA_MCU_0xFF);
          #endif

          /* Get AltAddress of current SwUnit */
          /* If AltAddress exists, Lu8_AltAddress will be converted to address of inactive bank */
          Ret_Offset = Mem_76_Pfls_HwSpecificService(SwModulePtr->PflsInstanceId, MEM_76_PFLS_GET_OFFSET_STD_ALT,Lu8_AltAddress, &Lu32_Length_Dummy);

          /* AltAddress Exists in current SwUnit */
          if(Ret_Offset == E_OK)
          {
            /* convert Lu8_AltAddress[0~3] to 32 bytes Address */
            #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
            Lu32_AltAddress = (uint32)(Lu8_AltAddress[FOTA_MCU_ZERO] & FOTA_MCU_0xFF) |
                              ((uint32)(Lu8_AltAddress[FOTA_MCU_ONE] & FOTA_MCU_0xFF) << FOTA_MCU_EIGHT) |
                              ((uint32)(Lu8_AltAddress[FOTA_MCU_TWO] & FOTA_MCU_0xFF) << FOTA_MCU_SIXTEEN) |
                              ((uint32)(Lu8_AltAddress[FOTA_MCU_THREE] & FOTA_MCU_0xFF) << FOTA_MCU_TWENTYFOUR);
            #else
            Lu32_AltAddress = (uint32)(Lu8_AltAddress[FOTA_MCU_THREE] & FOTA_MCU_0xFF) |
                              ((uint32)(Lu8_AltAddress[FOTA_MCU_TWO] & FOTA_MCU_0xFF) << FOTA_MCU_EIGHT) |
                              ((uint32)(Lu8_AltAddress[FOTA_MCU_ONE] & FOTA_MCU_0xFF) << FOTA_MCU_SIXTEEN) |
                              ((uint32)(Lu8_AltAddress[FOTA_MCU_ZERO] & FOTA_MCU_0xFF) << FOTA_MCU_TWENTYFOUR);
            #endif

            /* Get AltAddress OffSet : inactive bank address - active bank address */
            Lu32_Offset = Lu32_AltAddress - TargetBlockSwUnitTypePtr[blockIndex].StartAddress;

            /* Set Target Address */
            if((FaultAddress & Lu32_Offset) == Lu32_Offset) /* FaultAddress is in inactive bank */
            {
              Lu32_TargetAddress = FaultAddress - Lu32_Offset;
            }
            else /* FaultAddress is in active bank */
            {
              Lu32_TargetAddress = FaultAddress;
            }
          }
          else /* Ret_Offset != E_OK (No AltAddress Exists)*/
          {
            /* Set Target Address */
            Lu32_TargetAddress = FaultAddress;
          }
        }

        /* Check If TargetAddress is in Fota SwUnits' Address Range */
        if((Lu32_TargetAddress >= TargetBlockSwUnitTypePtr[blockIndex].StartAddress)
              && (Lu32_TargetAddress <= TargetBlockSwUnitTypePtr[blockIndex].EndAddress))
        {
          /* TargetAddress is in Fota SwUnits' address Range */
          /* return FOTA_ECC_FLAG to OsImp */
          Ret_Ecc = FOTA_ECC_FLAG;
          break;
        }
      }
    }
  }
  #else
  Ret_Ecc = FOTA_ECC_NONE;
  #endif
  return Ret_Ecc;
}
#endif /* HWRESOURCE_FAMILY(HWRESOURCE_S32K31X) */

/* polyspace-end MISRA-C3:20.9 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                             End of File                                    **
*******************************************************************************/
