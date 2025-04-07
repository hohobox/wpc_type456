/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_Packing.h                                     **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file defines extern declarations of packing    **
**                        functions                                           **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
*******************************************************************************/
#ifndef COMXF_PACKING_H
#define COMXF_PACKING_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/
#include "TransformerTypes.h"
#include "Rte_Type.h"

/*******************************************************************************
**                             Version Information                            **
*******************************************************************************/

/*******************************************************************************
**                              MACRO Definition                              **
*******************************************************************************/

/*******************************************************************************
**                              Type Definition                               **
*******************************************************************************/

/*******************************************************************************
**                         Global Variable Declaration                        **
*******************************************************************************/

/*******************************************************************************
**                           Function Declaration                             **
*******************************************************************************/

/* extern declaration of ComXf_PackBoolean */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackBoolean(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  boolean dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack2ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack2ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  uint16 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack3ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack3ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  uint32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack4ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack4ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  uint32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_PackUint64ByteAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackUint64ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint64 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_PackFloat32ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackFloat32ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  float32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_PackFloat64ByteAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackFloat64ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  float64 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_Pack5ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack5ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack4ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack4ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack3ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack3ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack2ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack2ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint16 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack1ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack1ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint8 dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_PackArray */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackArray(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  P2CONST(void, AUTOMATIC, COMXF_CONST) dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_Pack5678ByteNotAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack5678ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint64 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_Pack9ByteNotAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Pack9ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint64 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_PackFloat32ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackFloat32ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  float32 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_PackFloat64ByteNotAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_PackFloat64ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  float64 dataElement, sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

#endif /* COMXF_PACKING_H */

/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
