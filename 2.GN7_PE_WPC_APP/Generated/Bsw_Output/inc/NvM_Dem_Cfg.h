/*******************************************************************************
**  FILE-NAME: NvM_Dem_Cfg.h                                                  **
**                                                                            **
**  MODULE-NAME: AUTOSAR NVRAM Manager Module                                 **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.7.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_BswM.arxml
 *                Configuration\ECU\Ecud_Dem.arxml
 *                Configuration\ECU\Ecud_NvM.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Mcal\Ecud_Fee.arxml
 *                Configuration\ECU\Mcal\Ecud_Fls.arxml
 * GENERATED ON: The time-stamp is removed
 */

/*
polyspace-begin MISRA-C3:1.1 [Justified:Low] "No Impact of this rule violation (AUTOSAR Standard-NvM SWS Chap 5.1.2)"
*/

#ifndef NVM_DEM_CFG_H
#define NVM_DEM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define NVM_DEM_CFG_AR_RELEASE_MAJOR_VERSION               (4)
#define NVM_DEM_CFG_AR_RELEASE_MINOR_VERSION               (0)
#define NVM_DEM_CFG_AR_RELEASE_REVISION_VERSION            (3)
#define NVM_DEM_CFG_SW_MAJOR_VERSION                       (1)
#define NVM_DEM_CFG_SW_MINOR_VERSION                       (7)
#define NVM_DEM_CFG_SW_PATCH_VERSION                       (0)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Reference to the Dem Event */
#define NVM_E_INTEGRITY_FAILED              (DemConf_DemEventParameter_NVM_E_INTEGRITY_FAILED)

/* Reference to the Dem Event */
#define NVM_E_LOSS_OF_REDUNDANCY            (DemConf_DemEventParameter_NVM_E_LOSS_OF_REDUNDANCY)

/* Reference to the Dem Event */
#define NVM_E_QUEUE_OVERFLOW                (DemConf_DemEventParameter_NVM_E_QUEUE_OVERFLOW)

/* Reference to the Dem Event */
#define NVM_E_REQ_FAILED                    (DemConf_DemEventParameter_NVM_E_REQ_FAILED)

/* Reference to the Dem Event */
#define NVM_E_VERIFY_FAILED                 (DemConf_DemEventParameter_NVM_E_VERIFY_FAILED)

/* Reference to the Dem Event */
#define NVM_E_WRITE_PROTECTED               (DemConf_DemEventParameter_NVM_E_WRITE_PROTECTED)

/* Reference to the Dem Event */
#define NVM_E_WRONG_BLOCK_ID                (DemConf_DemEventParameter_NVM_E_WRONG_BLOCK_ID)


#endif /* NVM_DEM_CFG_H */

/*
polyspace-end MISRA-C3:1.1 [Justified:Low] "No Impact of this rule violation (AUTOSAR Standard-NvM SWS Chap 5.1.2)"
*/
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
