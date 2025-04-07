/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_UnPacking.h                                   **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file defines extern declarations of unpacking  **
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
** 1.0.11    27-Dec-2021   SMKwon      #33356                                 **
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
*******************************************************************************/
#ifndef COMXF_UNPACKING_H
#define COMXF_UNPACKING_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/


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

/* extern declaration of ComXf_UnPackBoolean */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(boolean, COMXF_CODE) ComXf_UnPackBoolean(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack2ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint16, COMXF_CODE) ComXf_UnPack2ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack3ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint32, COMXF_CODE) ComXf_UnPack3ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack4ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint32, COMXF_CODE) ComXf_UnPack4ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPackUint64ByteAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint64, COMXF_CODE) ComXf_UnPackUint64ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_UnPackFloat32ByteAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(float32, COMXF_CODE) ComXf_UnPackFloat32ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPackFloat64ByteAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(float64, COMXF_CODE) ComXf_UnPackFloat64ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_UnPack1ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_UnPack1ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack2ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint16, COMXF_CODE) ComXf_UnPack2ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack3ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint32, COMXF_CODE) ComXf_UnPack3ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack4ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint32, COMXF_CODE) ComXf_UnPack4ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack5ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint32, COMXF_CODE) ComXf_UnPack5ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPackArray */
/* #33357: Cert C EXP36-C : change dataElement type from "void pointer" to "uint8 pointer" as it is. */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_UnPackArray(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPack5678ByteNotAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint64, COMXF_CODE) ComXf_UnPack5678ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_UnPack9ByteNotAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint64, COMXF_CODE) ComXf_UnPack9ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

/* extern declaration of ComXf_UnPackFloat32ByteNotAlign */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(float32, COMXF_CODE) ComXf_UnPackFloat32ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_UnPackFloat64ByteNotAlign */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(float64, COMXF_CODE) ComXf_UnPackFloat64ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif

#endif /* COMXF_UNPACKING_H */

/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
