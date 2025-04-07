  /*******************************************************************************
  **                        File Generation Information                         **
  *******************************************************************************/

  /*
  * GENERATED ON : The time-stamp is removed
  */
#ifndef E2EXF_H
#define E2EXF_H

/*******************************************************************************
**                              Include Section                               **
*******************************************************************************/
/*******************Design ID : E2EXf_SDD_0004******************************/
#include "E2EXf_Cfg.h"
#include "E2EXf_Version.h"

/*******************************************************************************
**                             Precompile Macros                              **
*******************************************************************************/
#define INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_BCAN_WPC_FD_01_200MS_MSGGR_E2E_BCAN_WPC_FD_01_200MS      (E2EXF_INPLACE_FALSE)
#define INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_BCAN_WPC_FD_VCRM_01_00MS_MSGGR_E2E_BCAN_WPC_FD_VCRM_01_00MS      (E2EXF_INPLACE_FALSE)
#define INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_LCAN_L_WPC_FD_01_00MS_MSGGR_E2E_LCAN_L_WPC_FD_01_00MS      (E2EXF_INPLACE_FALSE)
#define INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_LCAN_L_WPC_FD_20_200MS_MSGGR_E2E_LCAN_L_WPC_FD_20_200MS      (E2EXF_INPLACE_FALSE)
#define INPLACE_E2EXF_INV_COM_COMISIGNALGROUP_MSGGR_E2E_LCAN_PDC_FD_15_300MS      (E2EXF_INPLACE_FALSE)
#define INPLACE_E2EXF_INV_APP_CAN_RX_GR_MSGGR_E2E_BCAN_PDC_FD_15_300MS_MSGGR_E2E_BCAN_PDC_FD_15_300MS      (E2EXF_INPLACE_FALSE)
#define INPLACE_E2EXF_APP_CAN_TX_GR_MSGGR_E2E_BCAN_WPC2_FD_01_200MS_MSGGR_E2E_BCAN_WPC2_FD_01_200MS      (E2EXF_INPLACE_FALSE)

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/************************ DET ERRORS: SWS_E2EXf_00137 *****************/
/* 
Error code if any other API service, except GetVersionInfo is called before
the transformer module was initialized with Init or after a call to DeInit
*/
/*********** Design ID : E2EXf_SDD_0009 *******************/
#define E2EXF_E_UNINIT                       0x01 

/* Error code if an invalid configuration set was selected */
/*********** Design ID : E2EXf_SDD_0009 *******************/
#define E2EXF_E_INIT_FAILED                  0x02

/* API service called with wrong parameter */
/*********** Design ID : E2EXf_SDD_0009 *******************/
#define E2EXF_E_PARAM                        0x03

/* API service called with invalid pointer */
/*********** Design ID : E2EXf_SDD_0009 *******************/
#define E2EXF_E_PARAM_POINTER                0x04

/*Extended Production Errors */
/*********** Design ID : E2EXf_SDD_0010 *******************/
#define E2EXF_E_MALFORMED_MESSAGE            0x09

/************* SID Codes for E2EXF      *********************/
/*********** Design ID : E2EXf_SDD_0005 *********************/
#define E2EXF_INIT_SID                       ((uint8)0x01)
#define E2EXF_DEINIT_SID                     ((uint8)0x02)
#define E2EXF_GETVERSIONINFO_SID             ((uint8)0x0)
#define E2EXF_TRANSFORMERID_SID              ((uint8)0x03)
#define E2EXF_INV_TRANSFORMERID_SID          ((uint8)0x04)

/************* E2EXF USED MACROS ********************************/
/********* Design ID : E2EXf_SDD_0005 ***************************/
#define E2EXF_PROFILEBEHAVIOR_PRE_R4_2       ((uint8)0x00)
#define E2EXF_PROFILEBEHAVIOR_R4_2           ((uint8)0x01)
#define E2EXF_TRUE                           ((boolean)0x1)
#define E2EXF_FALSE                          ((boolean)0x0)
#define E2EXF_INPLACE_TRUE                   (0x1)
#define E2EXF_INPLACE_FALSE                  (0x0)
#define E2EXF_DISABLEE2ECHECK_ON             ((uint8)0x1)
#define E2EXF_DISABLEE2ECHECK_OFF            ((uint8)0x0)
#define E2EXF_ZERO                           ((uint8)0)
#define E2EXF_ONE                            ((uint8)1)
#define E2EXF_EIGHT                          ((uint8)8)
#define E2EXF_FOUR                           ((uint8)4)
#define E2EXF_TWELVE                         ((uint8)12)
#define E2EXF_SIXTEEN                        ((uint8)16)
#define E2EXF_HIGH_NIBBLE_MASK               ((uint8)0xF0)
#define E2EXF_LOW_NIBBLE_MASK                ((uint8)0x0F)

#define E2EXF_E2E_P01_DATAID_BOTH            ((uint8)0)
#define E2EXF_E2E_P01_DATAID_ALT             ((uint8)1)
#define E2EXF_E2E_P01_DATAID_LOW             ((uint8)2)
#define E2EXF_E2E_P01_DATAID_NIBBLE          ((uint8)3)

#define E2EXF_E2E_P11_DATAID_BOTH            ((uint8)0)
#define E2EXF_E2E_P11_DATAID_NIBBLE          ((uint8)3)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function-like-Macro in E2EXf has already been verified and no impact of this rule violation  */
#define E2EXF_UNUSED_PTR(x)                  do { \
                                                  if((x) != NULL_PTR) {} \
                                                } while(0)

/* E2EXf return codes */
/*********** Design ID : E2EXf_SDD_0007 *******************/
#define E2EXF_E_OK                           ((uint8)0x00)

#define E_SAFETY_VALID_REP                   ((uint8)0x01)
#define E_SAFETY_VALID_SEQ                   ((uint8)0x02)
#define E_SAFETY_VALID_ERR                   ((uint8)0x03)
#define E_SAFETY_VALID_NND                   ((uint8)0x05)
#define E_SAFETY_NODATA_OK                   ((uint8)0x20)
#define E_SAFETY_NODATA_REP                  ((uint8)0x21)
#define E_SAFETY_NODATA_SEQ                  ((uint8)0x22)
#define E_SAFETY_NODATA_ERR                  ((uint8)0x23)
#define E_SAFETY_NODATA_NND                  ((uint8)0x25)
#define E_SAFETY_INIT_OK                     ((uint8)0x30)
#define E_SAFETY_INIT_REP                    ((uint8)0x31)
#define E_SAFETY_INIT_SEQ                    ((uint8)0x32)
#define E_SAFETY_INIT_ERR                    ((uint8)0x33)
#define E_SAFETY_INIT_NND                    ((uint8)0x35)
#define E_SAFETY_INVALID_OK                  ((uint8)0x40)
#define E_SAFETY_INVALID_REP                 ((uint8)0x41)
#define E_SAFETY_INVALID_SEQ                 ((uint8)0x42)
#define E_SAFETY_INVALID_ERR                 ((uint8)0x43)
#define E_SAFETY_INVALID_NND                 ((uint8)0x45)
#define E_SAFETY_SOFT_RUNTIMEERROR           ((uint8)0x77)
#define E_SAFETY_HARD_RUNTIMEERROR           ((uint8)0xFF)

/*------- Macro Declaration used for Encryption and Decryption --------------*/
#define E2EXF_GBLINITSTAT_INITIAL_VALUE   E2EXF_FALSE
/*
#define E2EXF_GBLINITSTAT_XOR1               (0x5AU)        0x5A,0x5AA5,0x5AA55AA5
#define E2EXF_GBLINITSTAT_XOR2               (0x96U)        0x96,0x9669,0x96699669
*/


/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function-like-Macro in E2EXf has already been verified and no impact of this rule violation  */
#define E2EXF_INV_RET_VALUE(SMState, CheckStatus) ((uint8)(((uint8)(((uint8)(E2EXF_LOW_NIBBLE_MASK & (SMState))) << \
E2EXF_FOUR)) | \
((uint8)((uint8)(E2EXF_LOW_NIBBLE_MASK & (CheckStatus))))))

/*
  SWS_E2EXf_00102 : In-place E2EXf_<transformerId> shall perform the
  following two precondition checks, without continuing further
  processing:
  1. (buffer == NULL && inputBufferLength != 0) ||
  (buffer != NULL && inputBufferLength <
  EndToEndTransformationDescription.upperHeaderBitsToShift/8u)
  2. bufferLength == NULL.
  If any of above conditions is TRUE, then the function shall
  return E_SAFETY_HARD_RUNTIMEERROR.
*/
#define E2EXF_INPLACE_PRECONDITIONS (! ((((NULL_PTR == buffer) && (E2EXF_ZERO != inputBufferLength)) || \
((NULL_PTR != buffer) && (inputBufferLength < \
(LusUpperHeaderBitsToShift/E2EXF_EIGHT)))) || \
(NULL_PTR == bufferLength)))

/*
  SWS_E2EXf_00105: In-place E2EXf_Inv_<transformerId> shall perform
  the following two precondition checks, without continuing further
  processing:
  1. (buffer == NULL && inputBufferLength != 0) ||
  (buffer != NULL && inputBufferLength <
  BufferProperties.headerLength/8u +
  EndToEndTransformationDescription.upperHeaderBitsToShift/8u)
  2. bufferLength == NULL.
  If any of above conditions is TRUE, then the function shall return
  E_SAFETY_HARD_RUNTIMEERROR.
*/
#define E2EXF_INV_INPLACE_PRECONDITIONS (! ((((NULL_PTR == buffer) && (E2EXF_ZERO != inputBufferLength)) || \
((NULL_PTR != buffer) && (inputBufferLength < \
((LusHeaderLength/E2EXF_EIGHT) + \
(LusUpperHeaderBitsToShift/E2EXF_EIGHT))))) || \
(NULL_PTR == bufferLength)))


/*
  SWS_E2EXf_00106 : Out-of-place E2EXf_<transformerId> shall perform the
  following three precondition checks, without continuing further
  processing:
  1. (inputBuffer == NULL && inputBufferLength != 0) ||
  (inputBuffer != NULL  && inputBufferLength <
  EndToEndTransformationDescription.upperHeaderBitsToShift/8u)
  2. bufferLength == NULL
  3. buffer == NULL
  If any of above conditions is TRUE, then the function shall return
  E_SAFETY_HARD_RUNTIMEERROR.
*/
#define E2EXF_OUTPLACE_PRECONDITIONS (! ((((NULL_PTR == inputBuffer) && \
(E2EXF_ZERO != inputBufferLength)) || ((NULL_PTR != inputBuffer) && \
(inputBufferLength < (LusUpperHeaderBitsToShift/E2EXF_EIGHT)))) || \
(NULL_PTR == bufferLength) || \
(NULL_PTR == buffer)))

/*
  SWS_E2EXf_00103: Out-of-place E2EXf_Inv_<transformerId> shall perform
  the  following three precondition checks, without continuing further
  processing:
  1. (inputBuffer == NULL && inputBufferLength != 0) ||
  (inputBuffer != NULL &&
  inputBufferLength < BufferProperties.headerLength/8u +
  EndToEndTransformationDescription.upperHeaderBitsToShift/8u)
  2. If (bufferLength == NULL)
  3. If (buffer == NULL).
  If any of above conditions is TRUE, then the function shall return
  E_SAFETY_HARD_RUNTIMEERROR.
*/
#define E2EXF_INV_OUTPLACE_PRECONDITIONS (! (((NULL_PTR == inputBuffer) && \
(E2EXF_ZERO != inputBufferLength )) || ((NULL_PTR != inputBuffer) && \
(inputBufferLength < ((LusHeaderLength/E2EXF_EIGHT) + \
(LusUpperHeaderBitsToShift/E2EXF_EIGHT)))) || \
(NULL_PTR == bufferLength) || \
(NULL_PTR == buffer)))


/*******************************************************************************
**                             Global Data Types                              **
*******************************************************************************/
/*********** Design ID : E2EXf_SDD_0006,E2EXf_SDD_0008 *******************/

//extern P2CONST(E2EXf_ConfigType,AUTOMATIC, E2EXF_CONST) E2EXf_GpCfgPtr;

//extern const E2E_SMConfigType E2EXf_GddSMCCP_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms;
//extern VAR(uint8, E2EXF_APPL_DATA) usPSW_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms[1];
//extern const E2E_SMConfigType E2EXf_GddSMCCP_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms;
//extern VAR(uint8, E2EXF_APPL_DATA) usPSW_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms[1];

/*******************************************************************************
**                         Configuration Set Handles                          **
*******************************************************************************/

/*******************************************************************************
**                            Function Prototypes                             **
*******************************************************************************/
//extern FUNC(void, E2EXF_CODE) E2EXf_GblInitStat_setData(
//VAR(boolean, E2EXF_APPL_DATA) blState);

extern FUNC(void, E2EXF_CODE) E2EXf_Init(
P2CONST(E2EXf_ConfigType, AUTOMATIC, E2EXF_APPL_DATA) config);

extern FUNC(void, E2EXF_CODE) E2EXf_DeInit(void);

/*******************Design ID : E2EXf_SDD_0037******************************/    
extern FUNC(void, E2EXF_CODE) E2EXf_GetVersionInfo(
P2VAR(Std_VersionInfoType,AUTOMATIC,E2EXF_APPL_DATA)VersionInfo);

extern FUNC(uint8, E2EXF_CODE) E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_01_200ms_MsgGr_E2E_BCAN_WPC_FD_01_200ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);
extern FUNC(uint8, E2EXF_CODE) E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms_MsgGr_E2E_BCAN_WPC_FD_VCRM_01_00ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);
extern FUNC(uint8, E2EXF_CODE) E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms_MsgGr_E2E_LCAN_L_WPC_FD_01_00ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);
extern FUNC(uint8, E2EXF_CODE) E2EXf_App_CAN_TX_Gr_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms_MsgGr_E2E_LCAN_L_WPC_FD_20_200ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);
extern FUNC(uint8, E2EXF_CODE) E2EXf_Inv_Com_ComISignalGroup_MsgGr_E2E_LCAN_PDC_FD_15_300ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);
extern FUNC(uint8, E2EXF_CODE) E2EXf_Inv_App_CAN_RX_Gr_MsgGr_E2E_BCAN_PDC_FD_15_300ms_MsgGr_E2E_BCAN_PDC_FD_15_300ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);
extern FUNC(uint8, E2EXF_CODE) E2EXf_App_CAN_TX_Gr_MsgGr_E2E_BCAN_WPC2_FD_01_200ms_MsgGr_E2E_BCAN_WPC2_FD_01_200ms(
  P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA)buffer,
  P2VAR(uint16, AUTOMATIC, E2EXF_APPL_DATA)bufferLength,
  P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA)inputBuffer,
  VAR(uint16, E2EXF_APPL_DATA)inputBufferLength);

#endif /* E2EXF_H */
/*******************************************************************************
**                                End of File                                 **
*******************************************************************************/
