/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_Types.h                                       **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file defines the public types provided by      **
**                        AUTOSAR SWS.                                        **
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
** 1.0.7     07-Dec-2020   SM Kwon     #25706                                 **
** 1.0.10    04-May-2021   PhucNHM     #28736                                 **
*******************************************************************************/
#ifndef COMXF_TYPES_H
#define COMXF_TYPES_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/
#include "ComXf_Cfg.h"

/*******************************************************************************
**                             Version Information                            **
*******************************************************************************/

/*******************************************************************************
**                              MACRO Definition                              **
*******************************************************************************/

/*******************************************************************************
**                              Type Definition                               **
*******************************************************************************/
/* Enum represent number of bytes for a group signal */
typedef enum
{
  COMXF_ZERO_BYTE_SIZE = 0x00,
  COMXF_ONE_BYTE_SIZE,
  COMXF_TWO_BYTE_SIZE,
  COMXF_THREE_BYTE_SIZE,
  COMXF_FOUR_BYTE_SIZE,
  COMXF_FIVE_BYTE_SIZE,
  COMXF_SIX_BYTE_SIZE,
  COMXF_SEVEN_BYTE_SIZE,
  COMXF_EIGHT_BYTE_SIZE,
  COMXF_NINE_BYTE_SIZE
}ComXf_ByteSizeType;

/* Enum represent number of shifted bit for signal alignment */
typedef enum
{
  COMXF_BIT_ALIGNED = 0x00,
  COMXF_ONE_BIT_SHIFT,
  COMXF_TWO_BIT_SHIFT,
  COMXF_THREE_BIT_SHIFT,
  COMXF_FOUR_BIT_SHIFT,
  COMXF_FIVE_BIT_SHIFT,
  COMXF_SIX_BIT_SHIFT,
  COMXF_SEVEN_BIT_SHIFT
}ComXf_BitAlignType;

/* Packing information of Signal/Group Signal */
typedef struct 
{
  /* Shift bit to align the signal at actual start bit */
  ComXf_BitAlignType en_ShiftBits;

  /* Size of signal in bytes */
  ComXf_ByteSizeType en_NoOfBytes;

  /* Clear or Start bit mask for the signal data */
  uint8 u8_StartORClearBitMask;

  /* Set or End bit mask for the signal data */
  uint8 u8_SetOREndMsk;

}ComXf_PackSigType;

/* Unpacking information of Signal/Group Signal */
typedef struct 
{
  /* uint64 u64_SigSignMsk; */
  uint32 u64_SigSignMsk;

  /* uint32 u32_SigSignMsk; */
  uint32 u32_SigSignMsk;

  /* Shift bit to align the signal at actual start bit */
  ComXf_BitAlignType en_ShiftBits;

  /* Size of signal in bytes */
  ComXf_ByteSizeType en_NoOfBytes;

  /* End bit mask for the signal data */
  uint8 u8_RxEndMsk;

}ComXf_UnPackSigType;


/* polyspace-begin MISRA-C3:19.2 [Not a defect: Justified] "Union used for handling endian conversion" */
/* Union for 32 bit float */
typedef union 
{
  /* Access uint32 element */
  uint32 u32_Float32Access;

  /* Access float32 element */
  float32 f32_Float32Access;

}ComXf_SigFloat32Type;

/* Union for 64 bit float */
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
typedef union 
{
  /* Access uint64 element */
  uint64 u64_Float64Access;

  /* Access float64 element */
  float64 f64_Float64Access;

}ComXf_SigFloat64Type;
#endif

typedef signed int ComXf_PtrType;

/* polyspace-end MISRA-C3:19.2 [Not a defect: Justified] "Union used for handling endian conversion" */
/*******************************************************************************
**                         Global Variable Declaration                        **
*******************************************************************************/

/*******************************************************************************
**                             Function Declaration                           **
*******************************************************************************/

#endif /* COMXF_TYPES_H */
/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
