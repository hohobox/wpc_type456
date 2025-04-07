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
**  SRC-MODULE: Mem_76_Pfls_Cfg.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Memory Driver                                         **
**                                                                            **
**  PURPOSE   : Macro configuration datas                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Framework version : 1.1.6.2                                                **
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
* INPUT FILE:      Configuration\ECU\Ecud_Mem_76_Pfls.arxml     
*                  Generated\Bsw_Output\bswmd\Bswmd_Mem_76_Pfls.arxml
*                  Static_Code\Modules\Mem_R44\generator\Mem_76_Pfls_ECU_Configuration_PDF.arxml
* GENERATED ON: The time-stamp is removed
*/
#ifndef MEM_76_PFLS_CFG_H
#define MEM_76_PFLS_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Det.h"
#include "Mem_76_Pfls_User_Callouts.h"
#include "Fota.h"


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define    MEM_76_PFLS_AR_RELEASE_MAJOR_VERSION                  0x04U
#define    MEM_76_PFLS_AR_RELEASE_MINOR_VERSION                  0x04U
#define    MEM_76_PFLS_AR_RELEASE_REVISION_VERSION               0x00U
#define    MEM_76_PFLS_SW_MAJOR_VERSION                          0x00U
#define    MEM_76_PFLS_SW_MINOR_VERSION                          0x00U
#define    MEM_76_PFLS_SW_PATCH_VERSION                          0x01U
#define    MEM_76_PFLS_VENDOR_ID                                 0x004CU
#define    MEM_76_PFLS_MODULE_ID                                 0x005BU

/*******************************************************************************
**                      MCU supported list                                    **
*******************************************************************************/
#define    MEM_76_PFLS_MCU_CYT2B6X                       (0x01u)
#define    MEM_76_PFLS_MCU_CYT2B7X                       (0x02u)
#define    MEM_76_PFLS_MCU_CYT2B9X                       (0x03u)
#define    MEM_76_PFLS_MCU_CYT2BLX_CYT3BX_CYT4BBX        (0x04u)
#define    MEM_76_PFLS_MCU_CYT4BFX                       (0x05u)
#define    MEM_76_PFLS_MCU_CYT6BJX                       (0x06u)

/*******************************************************************************
**                      Pre-compile Options                                   **
*******************************************************************************/
/* To enable / disable development error detection */
#define    MEM_76_PFLS_DEV_ERROR_DETECT                  STD_ON
/* To disable / enable ECC of memory program flash */
#define    MEM_76_PFLS_DISABLE_ECC_TRAP                  STD_ON

/* To use / unuse nvm */
#define    MEM_76_PFLS_USE_NVM                           STD_OFF
/* To enable run flash operation in ram */
#define    MEM_76_PFLS_RAMCODE_USED                      STD_OFF

/* Erase value */
#define    MEM_76_PFLS_ERASE_VALUE                       (0x0000U)

/* Support MCU */
#define    MEM_76_PFLS_SUPPORT_MCU                       MEM_76_PFLS_MCU_CYT2BLX_CYT3BX_CYT4BBX

#define    MEM_76_PFLS_MAX_NUMBER_OF_SECTOR_PER_INSTANCE (1U)

/* Number of Mem instances */
#define    MEM_76_PFLS_NUMBER_OF_INSTANCES               (2U)

/* Number of burst settings */
#define    MEM_76_PFLS_NUMBER_OF_BURST_SETTINGS          (2U)

/* Number of sector settings */
#define    MEM_76_PFLS_NUMBER_OF_SECTOR_SETTINGS         (2U)

#define    MEM_76_PFLS_PRE_CALLOUT_FUNCTION_SUPPORT      STD_ON
#define    MEM_76_PFLS_MAX_NUMBER_OF_PRECALLOUT          (2U)

#define    MEM_76_PFLS_POST_CALLOUT_FUNCTION_SUPPORT     STD_ON
#define    MEM_76_PFLS_MAX_NUMBER_OF_POSTCALLOUT         (2U)

#define    MEM_76_PFLS_WDG_CALLOUT_FUNCTION_SUPPORT      STD_OFF






/* Instance Id configuration name */
#define    Mem_76_Pfls_Instance_Conf_MemInstance0        (0U)
#define    Mem_76_Pfls_Instance_Conf_MemInstance1        (1U)


#endif /* MEM_76_PFLS_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
