/*******************************************************************************
**  FILE-NAME: Dcm_Routine.h                                                  **
**                                                                            **
**  MODULE-NAME: AUTOSAR DCM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **                                                                **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Generation Tool Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_Dcm.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 * GENERATED ON: The time-stamp is removed
 */


#ifndef DCM_ROUTINE_H
#define DCM_ROUTINE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                             MACROS                                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Necessary in logic */
     
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)

#define DCM_ROUTINE_PACK_2BYTE_SIGNAL(Array, Index) \
        ((uint16) (((uint16) ((Array)[(Index) + (DCM_ONE)] << (DCM_EIGHT))) | (Array)[(Index)]))
   
#define DCM_ROUTINE_PACK_4BYTE_SIGNAL(Array, Index) \
        ((uint32) (((uint32) ((Array)[(Index) + (DCM_THREE)] << (DCM_TWENTYFOUR))) | \
        ((uint32) ((Array)[(Index) + (DCM_TWO)] << (DCM_SIXTEEN))) | \
        ((uint32) ((Array)[(Index) + (DCM_ONE)] << (DCM_EIGHT))) | \
        ((uint32) (Array)[(Index)])))
#else

#define DCM_ROUTINE_PACK_2BYTE_SIGNAL(Array, Index) \
        ((uint16) (((uint16) ((Array)[(Index) + (DCM_ONE)])) | (Array)[(Index)] << (DCM_EIGHT)))
   
#define DCM_ROUTINE_PACK_4BYTE_SIGNAL(Array, Index) \
        ((uint32) (((uint32) ((Array)[(Index) + (DCM_THREE)])) | \
        ((uint32) ((Array)[(Index) + (DCM_TWO)] << (DCM_EIGHT))) | \
        ((uint32) ((Array)[(Index) + (DCM_ONE)] << (DCM_SIXTEEN))) | \
        ((uint32) (Array)[(Index)] << (DCM_TWENTYFOUR))))     
#endif     

/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Necessary in logic */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)    
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRoutineControl(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

#if (DCM_AUTHENTICATION_SUPPORT == STD_ON)
static FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_RidCtrl_AuthValidate(
  uint8 ctrlType,
  uint16 routineId,
  Dcm_RoutineConfigType* routineCfg);
#endif
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_StartRoutineUnPackSignal(
  uint16 LusRIDIndex, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_StopRoutineUnPackSignal(
  uint16 LusRIDIndex, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ResultRoutineUnPackSignal(
  uint16 LusRIDIndex, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(Std_ReturnType, DCM_CODE) 
  Dcm_RequestResultRoutinePackSignal( 
  uint16 LusRIDIndex, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
  
#if(DCM_ROUTINE_START_OUTSIGNAL_CONFIGURED == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_StartRoutinePackSignal(
  uint16 LusRIDIndex, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_ROUTINE_STOP_OUTSIGNAL_CONFIGURED == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_StopRoutinePackSignal(
  uint16 LusRIDIndex, 
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

extern FUNC(void, DCM_CODE)Dcm_RoutineHandleResponse(uint8 LucStatus, 
  uint16 LusRIDIndex);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_RoutineSignalFunction(
  uint8 LucSubFunction, uint16 LusRoutineIdentifier);
  
#if(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
  extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DspHandleOBDRoutineControl
  (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

extern FUNC(void, DCM_CODE) Dcm_RoutineMainFunction(void);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_ROUTINE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
