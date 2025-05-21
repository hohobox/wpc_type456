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
**  SRC-MODULE: Mem_76_Pfls_Cfg.c                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Memory Driver                                         **
**                                                                            **
**  PURPOSE   : Define configuration datas                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Framework version : 1.2.1                                                 **
**                                                                            **
**  Module version : 0.0.6.3                                                  **
**                                                                            **
**  Tool Version: 4.4.7                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
* INPUT FILE:      D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Mem_76_Pfls.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Mem_76_Pfls.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Generated\Bsw_Output\bswmd\Bswmd_Mem_76_Pfls.arxml
*                  D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Static_Code\Modules\Mem_R44\generator\Mem_76_Pfls_ECU_Configuration_PDF.arxml
* GENERATED ON: The time-stamp is removed
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Mem_76_Pfls.h"
#include "Mem_76_Pfls_Cfg.h"
#include "Mem_76_Pfls_Types.h"
#include "Mem_76_Pfls_Globals.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define MEM_76_PFLS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(Mem_76_Pfls_BurstSettingsType, MEM_76_PFLS_CONST) Mem_76_Pfls_BurstSettings[MEM_76_PFLS_NUMBER_OF_BURST_SETTINGS] = \
{

  /* MemInstance0_MemSectorBatch0_32KB */
  {
    /* Erase Burst Size */
    0x0UL,
    /* Read Burst Size */
    0x0UL,
    /* Write Burst Size */
    0x200UL
  },

  /* MemInstance1_MemSectorBatch1_32KB */
  {
    /* Erase Burst Size */
    0x0UL,
    /* Read Burst Size */
    0x0UL,
    /* Write Burst Size */
    0x200UL
  }

};
#define MEM_76_PFLS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (MEM_76_PFLS_PRE_CALLOUT_FUNCTION_SUPPORT == STD_ON)
#define MEM_76_PFLS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(Mem_76_Pfls_PreCalloutType, MEM_76_PFLS_CONST) Mem_76_Pfls_PreCallout[MEM_76_PFLS_NUMBER_OF_INSTANCES] = \
{
  /* MemInstance0 */
  {
    /* NumberOfPreCallout */
    1UL,
    /* PreCalloutInfo */
    {
      Mem_76_Pfls_FlashcMainFlashEnable_Callout
    }
  },
  /* MemInstance1 */
  {
    /* NumberOfPreCallout */
    1UL,
    /* PreCalloutInfo */
    {
      Mem_76_Pfls_FlashcMainFlashEnable_Callout
    }
  }
};
#define MEM_76_PFLS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#if (MEM_76_PFLS_POST_CALLOUT_FUNCTION_SUPPORT == STD_ON)
#define MEM_76_PFLS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(Mem_76_Pfls_PostCalloutType, MEM_76_PFLS_CONST) Mem_76_Pfls_PostCallout[MEM_76_PFLS_NUMBER_OF_INSTANCES] = \
{
  /* MemInstance0 */
  {
    /* NumberOfPostCallout */
    1UL,
    /* PostCalloutInfo */
    {
      Mem_76_Pfls_FlashcMainFlashDisable_Callout
    }
  },
  /* MemInstance1 */
  {
    /* NumberOfPostCallout */
    1UL,
    /* PostCalloutInfo */
    {
      Mem_76_Pfls_FlashcMainFlashDisable_Callout
    }
  }
};
#define MEM_76_PFLS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define MEM_76_PFLS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(Mem_76_Pfls_InstanceType, MEM_76_PFLS_CONST) Mem_76_Pfls_InstancesConfiguration[MEM_76_PFLS_NUMBER_OF_INSTANCES] = \
{

  /* MemInstance0 */
  {
    /* Number Of Sectors */
    1UL,
    /* Pre-Callout  Function  */
    &Mem_76_Pfls_PreCallout[0],
    /* Sector batches information */
    {
      /* MemInstance0_MemSectorBatch0_32KB */
      {
        /* Number of sectors */
        52UL,
        /* Erase sector size */
        0x8000UL,
        /* Read page size */
        1UL,
        /* Start address */
        0x10058000UL,
        /* End Address */
        270499839UL,
        /* Alt Start Address */
        0x12058000UL,
        /* Alt End Address   */
        304054271UL,
        /* Specified erase cycles */
        0xFFFFFFFFUL,
        /* Write page size */
        8UL,
        /* Burst settings structure */
        &Mem_76_Pfls_BurstSettings[0U]
      }

    },
    /* Post-Callout Function */
    &Mem_76_Pfls_PostCallout[0]
  },

  /* MemInstance1 */
  {
    /* Number Of Sectors */
    1UL,
    /* Pre-Callout  Function  */
    &Mem_76_Pfls_PreCallout[1],
    /* Sector batches information */
    {
      /* MemInstance1_MemSectorBatch1_32KB */
      {
        /* Number of sectors */
        6UL,
        /* Erase sector size */
        0x8000UL,
        /* Read page size */
        1UL,
        /* Start address */
        0x10028000UL,
        /* End Address */
        268795903UL,
        /* Alt Start Address */
        0x12028000UL,
        /* Alt End Address   */
        302350335UL,
        /* Specified erase cycles */
        0xFFFFFFFFUL,
        /* Write page size */
        8UL,
        /* Burst settings structure */
        &Mem_76_Pfls_BurstSettings[1U]
      }

    },
    /* Post-Callout Function */
    &Mem_76_Pfls_PostCallout[1]
  }

};
#define MEM_76_PFLS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
