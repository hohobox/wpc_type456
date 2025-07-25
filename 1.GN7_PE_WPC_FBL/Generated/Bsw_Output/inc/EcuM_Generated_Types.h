/*******************************************************************************
**  FILE-NAME : EcuM_Generated_Types.h                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 3.1.4                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_CanIf.arxml
 *                Configuration\ECU\Ecud_CanSM.arxml
 *                Configuration\ECU\Ecud_CanTp.arxml
 *                Configuration\ECU\Ecud_CanTrcv.arxml
 *                Configuration\ECU\Ecud_Com.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_CryIf.arxml
 *                Configuration\ECU\Ecud_Crypto_76_HaeModule.arxml
 *                Configuration\ECU\Ecud_Csm.arxml
 *                Configuration\ECU\Ecud_Dcm.arxml
 *                Configuration\ECU\Ecud_Det.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_EcuM.arxml
 *                Configuration\ECU\Ecud_Fota.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 *                Configuration\ECU\Ecud_WdgM.arxml
 *                Configuration\ECU\Mcal\Ecud_Can.arxml
 *                Configuration\ECU\Mcal\Ecud_Dio.arxml
 *                Configuration\ECU\Mcal\Ecud_Gpt.arxml
 *                Configuration\ECU\Mcal\Ecud_Mcu.arxml
 *                Configuration\ECU\Mcal\Ecud_Port.arxml
 *                Configuration\ECU\Mcal\Ecud_Spi.arxml
 *                Configuration\ECU\Mcal\Ecud_Wdg.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "Std_Types.h"
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "EcuM_Cfg.h"
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "Rte_EcuM_Type.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


typedef struct
{
  /* EcuMConfigConsistencyHash value */
  P2CONST (uint32, ECUM_CONST, ECUM_CONST) pEcuMConfigConsistencyHash;

  

  /* EcuMDefaultState */
  EcuM_StateType ddEcuMDefaultState;

  /* EcuMDefaultResetModeRef reference to EcuMResetMode */
  uint8 ucEcuMDefaultResetMode;

  /* EcuMDefaultSleepModeRef reference to EcuMSleepMode */
  uint8 ucEcuMDefaultSleepMode;

  /* ucLcfgHashArrayIndex */
  uint8 ucLcfgHashArrayIndex;
  
  /* Pointer to BswM config structure  */
  P2CONST (void, AUTOMATIC, ECUM_CONST) pBswMConfig;

}EcuM_ConfigType;

#define ECUM_START_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"
/* Structure for Config set */

/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EcuM_ConfigType, ECUM_CONST) EcuM_GaaConfig[];
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"

#define ECUM_START_SEC_CONST_32
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"
/* Structure for Hash value */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint32, ECUM_CONST) EcuM_GaaPBcfgHashValue[];

/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint32, ECUM_CONST) EcuM_GaaLcfgHashValue[];
#define ECUM_STOP_SEC_CONST_32
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* ECUM_GENERATED_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
