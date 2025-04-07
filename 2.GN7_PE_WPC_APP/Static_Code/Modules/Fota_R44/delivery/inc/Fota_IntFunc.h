/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FOTA_IntFunc.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   :                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.1.1.0   28-Jun-2024   KJShim       #CP44-9249, #CP44-8822, #CP44-7803    **
**                         KhanhHC      #CP44-8128, #CP44-9351                **
*******************************************************************************/
#ifndef FOTA_INTFUNC_H
#define FOTA_INTFUNC_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota_IntTypes.h"
/*******************************************************************************
**                     Macros                                                 **
*******************************************************************************/

/*******************************************************************************
**                     Global Data Types                                      **
*******************************************************************************/

/*******************************************************************************
**                     Global Data                                            **
*******************************************************************************/

/*******************************************************************************
**                     Function Prototypes                                    **
*******************************************************************************/

extern FUNC(boolean, FOTA_CODE) Fota_CheckMetadataArea(
  VAR(uint32, FOTA_VAR) metadataAddress);

extern FUNC(boolean, FOTA_CODE) Fota_CheckMetadataSize(
  VAR(uint32, FOTA_VAR) InMetadataSize);

extern FUNC(boolean, FOTA_CODE) Fota_CheckFwBlockArea(
  VAR(uint32, FOTA_VAR) firmwareBlkAddress);

extern FUNC(boolean, FOTA_CODE) Fota_CheckAddressIsSignatureArea(
  VAR(uint32, FOTA_VAR) signatureAddress);

extern FUNC(Fota_JobResultType, FOTA_CODE) Fota_GetVerifyJobResult(void);

extern FUNC(void, FOTA_CODE) Fota_SetVerifyJobResult(
  VAR(Fota_JobResultType, FOTA_VAR) Result);

extern FUNC(boolean, FOTA_CODE) Fota_CheckMetaWriteRequest(void);

extern FUNC(Std_ReturnType,FOTA_CODE) Fota_ValidateMemoryArea(
  VAR(uint8,AUTOMATIC) memoryArea
);

extern FUNC(Std_ReturnType,FOTA_CODE) Fota_GetMemInstanceBySwUnit(
  VAR(uint8,AUTOMATIC) swUnitId,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) PflsInstanceId);

extern FUNC(Std_ReturnType,FOTA_CODE) Fota_GetSoftwareModuleBlkBySwType(
  VAR(Fota_SoftwareType, AUTOMATIC) In_SwType,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) programmingSwUnitId);

#if (FOTA_MODE==FOTA_APP_MODE)
extern FUNC(Std_ReturnType,FOTA_CODE) Fota_GetSoftwareModuleBlkByRunArea(
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) programmingSwUnitId);
#endif

extern FUNC(Std_ReturnType, FOTA_CODE) Fota_GetSwUnitIdByLabel(
  VAR(uint16,AUTOMATIC) swUnitLabel,
  P2VAR(uint8, AUTOMATIC, FOTA_PRIVATE_DATA) programmingSwUnitId);

extern FUNC(Std_ReturnType,FOTA_CODE) Fota_ValidateAddressLengthAlignment(
  VAR(uint32, AUTOMATIC) startAddress,
  VAR(uint32, AUTOMATIC) eraseLen,
  VAR(Fota_AccessMemoryType, AUTOMATIC) accessType);

extern FUNC(Std_ReturnType, FOTA_CODE) Fota_MetaDataProcessing(
                                                 Fota_FlashWriteType *fotaWrite,
                                                 Fota_StateType fotaState);

extern FUNC(Std_ReturnType, FOTA_CODE) Fota_UserCallOutProcessing(
                                        Fota_FwBlockProcessingType *fwBlockPtr,
                                        Fota_StateType fotaState);

extern FUNC(void, FOTA_CODE) Fota_RequestSTDOrALTAccess(void);

extern FUNC(uint8, FOTA_CODE) Fota_FindSoftwareArea(
  VAR(Fota_SoftwareType, FOTA_VAR) softwareType);

#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(Std_ReturnType, FOTA_CODE) Fota_CheckNextSwUnitProgramming(
  uint8 *swUnitIndex, uint8 *recoverySwUnit,
  Fota_SvcOrVerifyKeyType optionCheck);
#endif

#if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
  (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(void, FOTA_CODE) Fota_CheckAllSwUnitVersionCheck(boolean *allSwUnitSvcAreGood);
#endif

#if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
  (FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(void, FOTA_CODE) Fota_SvcInitializeEraseRomSwUnit(uint8 *swUnitIndex);
#endif

#if ((FOTA_IMPLEMENTATION_RULE == FOTA_OTA_ES98765_02) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
FUNC(void, FOTA_CODE) Fota_ResetSvcResultAllSwUnit(Fota_FunctionType type,
  uint8 swUnitIndex);
#endif

#if (FOTA_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, FOTA_CODE) Fota_DetReportErr
(
  VAR(uint16, AUTOMATIC) ModuleId,
  VAR(uint8, AUTOMATIC) InstanceId,
  VAR(uint8, AUTOMATIC) ApiId,
  VAR(uint8, AUTOMATIC) ErrorId,
  VAR(uint8, AUTOMATIC) retVal
);
#endif
#endif /* FOTA_INTFUNC_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
