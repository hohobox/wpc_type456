/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_Packing.c                                     **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file provides definitions of packing functions **
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
** 1.0.10    04-May-2021   PhucNHM     #28736                                 **
** 1.0.7     07-Dec-2020   SM Kwon     #25706                                 **
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/
/* Include for ComXf.h */
#include "ComXf.h"
/* Include for ComXf_Types.h */
#include "ComXf_Types.h"
/* Include for ComXf_Cfg.h */
#include "ComXf_Cfg.h"
/* Include for ComXf_GlobalDataDefinition.h */
#include "ComXf_GlobalDataDefinition.h"
/* Include for ComXf_Macros.h */
#include "ComXf_Macros.h"
/* Include for ComXf_Packing.h */
#include "ComXf_Packing.h"
/*******************************************************************************
**                            Type Definition                                 **
*******************************************************************************/
/* Word order definition */
#ifndef HIGH_WORD_FIRST
#define HIGH_WORD_FIRST         HIGH_BYTE_FIRST /* Big endian word ordering */
#endif
#ifndef LOW_WORD_FIRST
#define LOW_WORD_FIRST          LOW_BYTE_FIRST /* Little endian word ordering */
#endif
/*******************************************************************************
**                        Global Variable Declaration                         **
*******************************************************************************/

/*******************************************************************************
**                            Function Declaration                            **
*******************************************************************************/

/*******************************************************************************
**                            Version Check                                   **
*******************************************************************************/

/*******************************************************************************

**                             MISRA Exceptions                               **
********************************************************************************
** MISRA Rule No       : MISRA 2012 Rule 8.4, required                        **
** MISRA Rule          : external symbol defined without a prior declaration  **
** Functionality       : external symbol defined without a prior declaration  **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified that external symbol is      **
**                       defined                                              **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 19.2, advisory                       **
** MISRA Rule          : declaration of symbol with union based type          **
** Functionality       : ComXf_SigFloat32Type and ComXf_SigFloat64Type is used**
**                     : for accessing values                                 **
** Occurrences         : In ComXf_PackFloat64ByteAlign,                       **
**                     : ComXf_PackFloat64ByteNotAlign                        **
** Verification        : It is manually verified that union based type should **
**                       not create any problem                               **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 18.4, advisory                       **
** MISRA Rule          : pointer arithmetic other than array indexing used    **
** Functionality       : Lpt_buffer pointer is incrementing or decremented    **
**                     : using value                                          **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified that pointer should not      **
**                       overflow                                             **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 2.2, required                        **
** MISRA Rule          : Last value assigned to variable not used             **
** Functionality       : Previously assigned value to variable not used in the**
**                     : mentioned functions in Occurrences. As those are     **
**                     : accessed using pointers                              **
** Occurrences         : In ComXf_Pack5ByteNotAlign, ComXf_Pack9ByteNotAlign  **
** Verification        : It is manually verified last value assigned is used  **
**                       through pointer                                      **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 11.5, advisory                       **
** MISRA Rule          : conversion from pointer to void to pointer to other  **
**                     : type                                                 **
** Functionality       : void pointer dataElement is converted to uint8* type **
** Occurrences         : In ComXf_PackArray                                   **
** Verification        : It is manually verified that pointer should not      **
**                       create any problem                                   **
** Verification Method : Code review

** MISRA Rule No       : MISRA 2012 Rule 20.1, advisory                       **
** MISRA Rule          : declaration of 'ComXf_PackBoolean' before #include   **
** Functionality       : declaration of 'ComXf_PackBoolean' before #include   **
** Occurrences         : In ComXf_PackBoolean                                 **
** Verification        : It is manually verified declaration of               **
**                       ComXf_PackBoolean                                    **
** Verification Method : Code review                                          **

** MISRA Rule No       : info 766                                             **
** MISRA Rule          : Header files 1.ComXf_MemMap.h, 2.ComXf_Cfg.h,        **
**                     : 3.ComXf_GlobalDataDefinition.h not used in module    **
** Functionality       : 1.This file provides all the memory abstractions used**
**                     : in the COMXF Module                                  **
**                     : 2.This file shall contain the module/component       **
**                     : specific parameters                                  **
**                     : 3.This file has extern declaration of global         **
**                       variables                                            **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified                              **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 10.4, required                       **
** MISRA Rule          : Mismatched essential type categories for binary      **
**                       operator                                             **
** Functionality       : Mismatched essential type categories for binary      **
**                       operator                                             **
** Occurrences         : In ComXf_PackBoolean                                 **
** Verification        : It is manually verified that Mismatched of essential **
**                     : type categories for binary operator                  **

** MISRA Rule No       : MISRA 2012 Rule 10.1, required                       **
** MISRA Rule          : Undeteremined operand to operator '>>'               **
** Functionality       : Undeteremined operand to operator '>>'               **
** Occurrences         : In ComXf_PackBoolean                                 **
** Verification        : It is manually verified that Mismatched of essential **
**                     : type categories for binary operator                  **

** MISRA Rule No       : info 701                                             **
** MISRA Rule          : Shift left of signed quantity (int)                  **
** Functionality       : Shift left of signed quantity (int)                  **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified                              **
** Verification Method : Code review                                          **
*******************************************************************************/

/*******************************************************************************

**                             MISRA Exceptions                               **
********************************************************************************
** MISRA Rule No       : MISRA 2012 Rule 8.4, required                        **
** MISRA Rule          : external symbol defined without a prior declaration  **
** Functionality       : external symbol defined without a prior declaration  **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified that external symbol is      **
**                       defined                                              **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 19.2, advisory                       **
** MISRA Rule          : declaration of symbol with union based type          **
** Functionality       : ComXf_SigFloat32Type and ComXf_SigFloat64Type is used**
**                     : for accessing values                                 **
** Occurrences         : In ComXf_PackFloat64ByteAlign,                       **
**                     : ComXf_PackFloat64ByteNotAlign                        **
** Verification        : It is manually verified that union based type should **
**                       not create any problem                               **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 18.4, advisory                       **
** MISRA Rule          : pointer arithmetic other than array indexing used    **
** Functionality       : Lpt_buffer pointer is incrementing or decremented    **
**                     : using value                                          **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified that pointer should not      **
**                       overflow                                             **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 2.2, required                        **
** MISRA Rule          : Last value assigned to variable not used             **
** Functionality       : Previously assigned value to variable not used in the**
**                     : mentioned functions in Occurrences. As those are     **
**                     : accessed using pointers                              **
** Occurrences         : In ComXf_Pack5ByteNotAlign, ComXf_Pack9ByteNotAlign  **
** Verification        : It is manually verified last value assigned is used  **
**                       through pointer                                      **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 11.5, advisory                       **
** MISRA Rule          : conversion from pointer to void to pointer to other  **
**                     : type                                                 **
** Functionality       : void pointer dataElement is converted to uint8* type **
** Occurrences         : In ComXf_PackArray                                   **
** Verification        : It is manually verified that pointer should not      **
**                       create any problem                                   **
** Verification Method : Code review                                          **
*******************************************************************************/
/* polyspace-begin MISRA-C3:18.4 [Not a defect : Justified] "Decrement and Increment operator is used to achieve better throughput" */
/* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
/* polyspace-begin MISRA-C3:17.8 [Not a defect: Justified] "No Imapct of this rule violations" */

/*******************************************************************************
**                           Function Definitions                             **
*******************************************************************************/
/*=============================================================================*
** Service Name         : ComXf_PackBoolean                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack boolean type signal              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackBoolean(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  boolean dataElement)
{
  /*
   * Apply clear bit mask value to Rte buffer and clear boolean bit value
   * fields in the  buffer
   */
  *Lpt_buffer &= Lpst_PackSigType->u8_StartORClearBitMask;

  /* Check if value in the dataElement is one */
  if(dataElement != (boolean) COMXF_BOOLEAN_ZERO)
  {
    /*
     * Apply set bit mask value to Rte buffer and set boolean bit value
     * fields in the  buffer
     */
    *Lpt_buffer |= Lpst_PackSigType->u8_SetOREndMsk;
  }
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack2ByteAlign                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 2 byte aligned signal            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Ls8_ByteDirection, dataElement                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack2ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  uint16 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local pointer to signal */
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_SigBuff;

  /* Take a pointer to dataElement */
  Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &dataElement;

  /* Copy the data to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data to Rte buffer */
  Lpt_buffer[Ls8_bytePos]  = Lpt_SigBuff[COMXF_FIRST_BYTE];

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack3ByteAlign                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 3 byte aligned signal            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack3ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  uint32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local pointer to signal */
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_SigBuff;

  uint8 Lu8_NoOfBytes;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  /* Take a pointer to dataElement */
  Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &dataElement;

  /* If CPU is big endian then increment dataElement pointer */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  Lu8_NoOfBytes++;

  #endif /* #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Increment dataElement pointer */
  Lu8_NoOfBytes++;

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Increment dataElement pointer */
  Lu8_NoOfBytes++;

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack4ByteAlign                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 4 byte aligned signal            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
/* polyspace +1 MISRA-C3:8.7 [Not a defect: Justified] "Depends on configuration having external linkage" */
FUNC(void, COMXF_CODE) ComXf_Pack4ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  uint32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local pointer to signal */
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_SigBuff;

  /* Take a pointer to dataElement */
  Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &dataElement;

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  /* Increment or decrement pointer on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_FIRST_BYTE];

  /* Increment or decrement pointer on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_SECOND_BYTE];

  /* Increment or decrement pointer on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy data byte to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_THIRD_BYTE];
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_PackUint64ByteAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 5, 6, 7 or 8 byte aligned signals**
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackUint64ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint64 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;
  /* Local variable to check against the number of bytes */
  uint8 Lu8_NoOfBytes;

  /* Local pointer to signal */
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_SigBuff;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  /* This check is for polyspace work-around
   * This en_NoOfBytes variable associated to this function 
   * will always be generated with value in range [5..8] */
  if ((Lpst_PackSigType->en_NoOfBytes >= COMXF_FIVE_BYTE_SIZE) &&
    ((Lpst_PackSigType->en_NoOfBytes <= COMXF_EIGHT_BYTE_SIZE)))
  {
    /* Take a pointer to dataElement */
    Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &dataElement;

    do
    {
      /* Copy data byte to Rte buffer */
      Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

      /* Increment or decrement pointer on CPU endianness */
      Ls8_bytePos += Ls8_ByteDirection;;

      /* Increment the local variable */
      Lu8_NoOfBytes ++;

    }while(Lu8_NoOfBytes < (uint8)(Lpst_PackSigType->en_NoOfBytes));
  }
  else 
  {
    /* No action */
  }
}

#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_PackFloat32ByteAlign                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack float32 byte aligned type signal **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackFloat32ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  float32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Union to store signal data */
  ComXf_SigFloat32Type Lun_AppSigData;

  /* Copy the data from dataElement */
  Lun_AppSigData.f32_Float32Access = dataElement;

  /* API called for packing the data */
  ComXf_Pack4ByteAlign(Lpt_buffer, Lun_AppSigData.u32_Float32Access,
    Ls8_ByteDirection);
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_PackFloat64ByteAlign                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack float64 byte aligned type signal **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackFloat64ByteAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  float64 dataElement, sint8 Ls8_ByteDirection)
{
  /* Union to store signal data */
  ComXf_SigFloat64Type Lun_AppSigData;

  /* Copy the data from dataElement */
  Lun_AppSigData.f64_Float64Access = dataElement;

  /* API called for packing the data */
  ComXf_PackUint64ByteAlign(Lpt_buffer, Lpst_PackSigType,
    Lun_AppSigData.u64_Float64Access, Ls8_ByteDirection);
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_Pack1ByteNotAlign                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack single byte not aligned signal   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack1ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint8 dataElement)
{
  /*
   * Apply clear bit mask value to Rte buffer and clear boolean bit value
   * fields in the  buffer
   */
  *Lpt_buffer &= Lpst_PackSigType->u8_StartORClearBitMask;

  /* Shift the data to signal position */
  /* polyspace +2 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  /* polyspace +1 RTE:OVFL [Not a defect: Justified] "Overflow can not occur" */	
  dataElement <<= (uint8)Lpst_PackSigType->en_ShiftBits;

  /* Clear the unused data value from data element */
  dataElement &= (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

  /* Copy data byte to Rte buffer */
  *Lpt_buffer |= dataElement;

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack2ByteNotAlign                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack single byte not aligned signal   **
**                        spread across 2 bytes and 2 byte not aligned        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack2ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint16 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data value */
  uint8 Lu8_DestBuffData;

  /* Local uint32 variable to store the shifted data element */
  uint32 Lu32_DataElement;

  /* Local uint16 variable to store the shifted data element */
  uint16 Lu16_DataElement;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_SigBuff;

  /* Type casting dataElement to uint32 */
  Lu32_DataElement = (uint32)dataElement;

  /* Shift the data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu32_DataElement <<= (uint8)Lpst_PackSigType->en_ShiftBits;
  
  /* Convert the shifted data back to the original type uint16 */
  Lu16_DataElement = (uint16)Lu32_DataElement;

  /* Point the signal buffer to dataElement */
  Lpt_SigBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &Lu16_DataElement;

  /* Copy Rte buffer value to local variable */
  Lu8_DestBuffData = Lpt_buffer[Ls8_bytePos];

  /* Apply start mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_StartORClearBitMask);

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  Lpt_SigBuff[COMXF_ZEROTH_BYTE] &= (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy Rte buffer value to local variable */
  Lu8_DestBuffData = Lpt_buffer[Ls8_bytePos];

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)

  Lpt_SigBuff[COMXF_FIRST_BYTE] &= (uint8)(~(Lpst_PackSigType->u8_SetOREndMsk));

  #endif /* End of #if (CPU_BYTE_ORDER == LOW_WORD_FIRST) */

  /* Clear the data at signal position using end mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_SetOREndMsk);

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[COMXF_FIRST_BYTE];

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack3ByteNotAlign                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 2 byte not aligned signal spread **
**                        across 3 bytes and 3 byte not aligned               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack3ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data value */
  uint8 Lu8_DestBuffData;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_SigBuff;

  uint8 Lu8_NoOfBytes;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;  

  /* Shift the data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  dataElement <<= (uint8)(Lpst_PackSigType->en_ShiftBits);

  /* Point the signal buffer to dataElement */
  Lpt_SigBuff = (P2VAR(uint8, AUTOMATIC, COMXF_CONST)) &dataElement;

  /* Copy Rte buffer value to local variable */
  Lu8_DestBuffData = Lpt_buffer[Ls8_bytePos];

  /* Apply start mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_StartORClearBitMask);

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Increment signal buffer pointer */
  Lu8_NoOfBytes++;

  /* Apply clear mask */
  Lpt_SigBuff[Lu8_NoOfBytes] &= (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[Lu8_NoOfBytes];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Increment signal buffer pointer */
  Lu8_NoOfBytes++;

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Increment signal buffer pointer */
  Lu8_NoOfBytes++;

  /* Copy Rte buffer value to local variable */
  Lu8_DestBuffData = Lpt_buffer[Ls8_bytePos];

  /* Clear the data at signal position using start mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_SetOREndMsk);

  #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)

  /* Apply end mask */
  Lpt_SigBuff[Lu8_NoOfBytes] &= (uint8)(~(Lpst_PackSigType->u8_SetOREndMsk));

  #endif /* End of #if (CPU_BYTE_ORDER == LOW_WORD_FIRST) */

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[Lu8_NoOfBytes];

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack4ByteNotAlign                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 3 byte not aligned signal spread **
**                        across 4 bytes and 4 byte not aligned               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack4ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data value */
  uint8 Lu8_DestBuffData;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_SigBuff;

  /* Shift the data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  dataElement <<= (uint8)(Lpst_PackSigType->en_ShiftBits);

  /* Point the signal buffer to dataElement */
  Lpt_SigBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &dataElement;

  /* Copy Rte buffer value to local variable */
  Lu8_DestBuffData = Lpt_buffer[Ls8_bytePos];

  /* Clear the data at signal position using start mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_StartORClearBitMask);

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  Lpt_SigBuff[COMXF_ZEROTH_BYTE] &= (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_FIRST_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_SECOND_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy dataElement value to local variable */
  Lu8_DestBuffData = Lpt_buffer[Ls8_bytePos];

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)

  Lpt_SigBuff[COMXF_THIRD_BYTE] &= (uint8)(~(Lpst_PackSigType->u8_SetOREndMsk));

  #endif /* End of #if (CPU_BYTE_ORDER == LOW_WORD_FIRST) */

  /* Clear the data at signal position using end mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_SetOREndMsk);

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[COMXF_THIRD_BYTE];

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack5ByteNotAlign                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack uint32 bit not byte aligned      **
**                        signal and spread across 5 bytes                    **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
/* polyspace +1 MISRA-C3:8.7 [Not a defect: Justified] "Depends on configuration having external linkage" */
FUNC(void, COMXF_CODE) ComXf_Pack5ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data value */
  uint32 Lu32_dataElement;

  /* Local variable to store data value */
  uint8 Lu8_dataElement;

  /* Local variable to store data value */
  uint8 Lu8_DestBuffData;

  /* Local pointer to signal data */
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_SigBuff;

  /* Point the signal buffer to dataElement */
  Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &Lu32_dataElement;

  /* Store dataElement value */
  Lu32_dataElement = dataElement;

  /* polyspace-begin RTE:NIV [Not a defect: Justified] "Initialized Variable" */
  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Store dataElement higher byte value */	
  Lu8_dataElement = Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  /* Shift the higher data byte to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu8_dataElement >>= 
    (COMXF_SHIFT_BY_EIGHT - (uint8)(Lpst_PackSigType->en_ShiftBits));

  Lu8_dataElement &= (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

  #else

  /* Store dataElement higher byte value */	
  Lu8_dataElement = Lpt_SigBuff[COMXF_THIRD_BYTE];

  /* Shift the higher data byte to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu8_dataElement >>=
    ((uint8) COMXF_SHIFT_BY_EIGHT - (uint8)(Lpst_PackSigType->en_ShiftBits));

  Lu8_dataElement &= (uint8)(~(Lpst_PackSigType->u8_SetOREndMsk));
	
  #endif

  /* Shift the data to signal position */
  /* polyspace +1 MISRA-C3:2.2, DEFECT:USELESS_WRITE [Not a defect: Justified] "Lpt_SigBuff used the value indirectly" */
  Lu32_dataElement <<= (uint8)(Lpst_PackSigType->en_ShiftBits);

  /* #33356: */
  /* Point the signal buffer to dataElement */
  Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &Lu32_dataElement;

  /* Copy buffer value to local variable */
  Lu8_DestBuffData =  Lpt_buffer[Ls8_bytePos];

  /* Clear the data at signal position using start mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_StartORClearBitMask);

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lu8_dataElement;

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  #else

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[COMXF_ZEROTH_BYTE];

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_FIRST_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy dataElement value to Rte buffer */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_SECOND_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Check whether CPU is Big or Little Endian */
  #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)

  /* Increment or decrement pointer based on CPU endianness */
  Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_THIRD_BYTE];

  /* Increment or decrement pointer based on CPU endianness */
  Ls8_bytePos += Ls8_ByteDirection;;

  /* Copy buffer value to local variable */
  Lu8_DestBuffData =  Lpt_buffer[Ls8_bytePos];

  /* Clear the data at signal position using start mask */
  Lu8_DestBuffData &= (Lpst_PackSigType->u8_SetOREndMsk);

  /* Increment or decrement pointer based on CPU endianness */
  Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lu8_dataElement;

  #else

  /* Clear the data at signal position using end mask */
   Lpt_buffer[Ls8_bytePos] &= (Lpst_PackSigType->u8_SetOREndMsk);

  /* Increment or decrement pointer based on CPU endianness */
  Lpt_buffer[Ls8_bytePos] =  Lpt_buffer[Ls8_bytePos] | Lpt_SigBuff[COMXF_THIRD_BYTE];
  #endif /* End of #if (CPU_BYTE_ORDER == LOW_WORD_FIRST) */
  /* polyspace-end RTE:NIV [Not a defect: Justified] "Initialized Variable" */
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_PackArray                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack UINT8_N signal                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackArray(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  P2CONST(void, AUTOMATIC, COMXF_CONST) dataElement)
{
  /* Local reference to source buffer */
  P2CONST(uint8, AUTOMATIC, COM_CONST) Lpt_SigBuff;

  /* No of bytes of signal data */
  uint8 Lu8_SigBytesSize;

  /* Loop buffer index */
  uint8 Lu8_SigBytesIndex;

  /* Copy the Size of signal bytes */
  Lu8_SigBytesSize = (uint8)(Lpst_PackSigType->en_NoOfBytes);

  Lu8_SigBytesIndex = (uint8) COMXF_HEX_00;

  /* Copy the signal data pointer */
  Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST))(dataElement);

  /* Copy each byte of signal data to destination buffer */
  do
  {
    /* Copy data from signal buffer to destination buffer */
    Lpt_buffer[Lu8_SigBytesIndex] = Lpt_SigBuff[Lu8_SigBytesIndex];

    /* Point to next address */
    Lu8_SigBytesIndex++;

    /* Decrement loop count */
    Lu8_SigBytesSize--;

  }while(Lu8_SigBytesSize > (uint8) COMXF_HEX_00);
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_Pack9ByteNotAlign                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack uint64 byte not aligned          **
**                        signal spread across 9 bytes                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack9ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint64 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to to check against the number of bytes */
  uint8 Lu8_NoOfBytes;

  /* Local variable to store data value */
  uint64 Lu64_dataElement;

  /* Local variable to store data value */
  uint8 Lu8_dataElement;

  /* Local variable to store data value */
  uint8 Lu8_DestBuffData;

  /* Local pointer to signal data */
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_SigBuff;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  /* This check is for polyspace work-around
   * This en_NoOfBytes variable associated to this function 
   * will always be generated with value is 9 */
  if (Lpst_PackSigType->en_NoOfBytes == COMXF_NINE_BYTE_SIZE)
  {
    /* Store dataElement value */
    Lu64_dataElement = dataElement;

    /* Point the signal buffer to dataElement */
    Lpt_SigBuff = (P2CONST(uint8, AUTOMATIC, COMXF_CONST)) &Lu64_dataElement;
    
    /* Check whether CPU is Big or Little endian */
    #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

    /* Store dataElement higher byte value */
    Lu8_dataElement = Lpt_SigBuff[COMXF_ZEROTH_BYTE];

    /* Shift the higher data byte to signal position */
    Lu8_dataElement >>= 
      (COMXF_SHIFT_BY_EIGHT - (uint8)(Lpst_PackSigType->en_ShiftBits));

    Lu8_dataElement &= (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

    #else

    /* Store dataElement higher byte value */
    Lu8_dataElement = Lpt_SigBuff[(uint8)
      (Lpst_PackSigType->en_NoOfBytes) - (uint8) COMXF_SECOND_BYTE];

    /* Shift the higher data byte to signal position */
    Lu8_dataElement >>=
      ((uint8) COMXF_SHIFT_BY_EIGHT - (uint8)(Lpst_PackSigType->en_ShiftBits));

    Lu8_dataElement &= (uint8)(~(Lpst_PackSigType->u8_SetOREndMsk));
    #endif

    /* Shift the data to signal position */
    /* polyspace +1 MISRA-C3:2.2, DEFECT:USELESS_WRITE [Not a defect: Justified] "Lpt_SigBuff used the value indirectly" */
    Lu64_dataElement <<= (uint8)(Lpst_PackSigType->en_ShiftBits);

    /* Copy buffer value to local variable */
    Lu8_DestBuffData =  Lpt_buffer[Ls8_bytePos];

    /* Clear the data at signal position using start mask */
    Lu8_DestBuffData &= (Lpst_PackSigType->u8_StartORClearBitMask);

    /* Check whether CPU is Big or Little endian */
    #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

    /* Copy dataElement value to Rte buffer */
    Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lu8_dataElement;

    /* Increment or decrement pointer based on CPU endianness */
    Ls8_bytePos += Ls8_ByteDirection;;

    /* Copy dataElement value to Rte buffer */
    Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[COMXF_ZEROTH_BYTE];

    #else

    /* Copy dataElement value to Rte buffer */
    Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[COMXF_ZEROTH_BYTE];

    #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

    /* Increment or decrement pointer based on CPU endianness */
    Ls8_bytePos += Ls8_ByteDirection;;

    do
    {
      /* Increment the local variable */
      Lu8_NoOfBytes++;

      /* Copy dataElement value to Rte buffer */
      Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

      /* Increment or decrement pointer based on CPU endianness */
      Ls8_bytePos += Ls8_ByteDirection;;

    } while(Lu8_NoOfBytes <
        ((uint8)(Lpst_PackSigType->en_NoOfBytes) - (uint8) COMXF_THREE_BYTES));

    /* Check whether CPU is Big or Little Endian */
    #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)

    /* Increment or decrement pointer based on CPU endianness */
    Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[(uint8)
      (Lpst_PackSigType->en_NoOfBytes) - (uint8) COMXF_TWO_BYTES];

    /* Increment or decrement pointer based on CPU endianness */
    Ls8_bytePos += Ls8_ByteDirection;;

    /* Copy buffer value to local variable */
    Lu8_DestBuffData =  Lpt_buffer[Ls8_bytePos];

    /* Clear the data at signal position using start mask */
    Lu8_DestBuffData &= (Lpst_PackSigType->u8_SetOREndMsk);

    /* Increment or decrement pointer based on CPU endianness */
    Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lu8_dataElement;

    #else

    /* Clear the data at signal position using end mask */
     Lpt_buffer[Ls8_bytePos] &= (Lpst_PackSigType->u8_SetOREndMsk);

    /* Increment or decrement pointer based on CPU endianness */
    Lpt_buffer[Ls8_bytePos] =  Lpt_buffer[Ls8_bytePos] |
      Lpt_SigBuff[(uint8)(Lpst_PackSigType->en_NoOfBytes) - COMXF_TWO_BYTES];

    #endif /* End of #if (CPU_BYTE_ORDER == LOW_WORD_FIRST) */
  }
  else 
  {
    /* No action */
  }
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_Pack5678ByteNotAlign                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack 6,7, or 8 bytes not aligned      **
**                        signal spread across 6,7 or 8 bytes                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Pack5678ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  uint64 dataElement, sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to to check against the number of bytes */
  uint8 Lu8_NoOfBytes;

  /* Local variable to store data value */
  uint8 Lu8_DestBuffData;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_SigBuff;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  /* This check is for polyspace work-around
   * This en_NoOfBytes variable associated to this function 
   * will always be generated with value in range [5..8] */
  if ((Lpst_PackSigType->en_NoOfBytes >= COMXF_FIVE_BYTE_SIZE) &&
    ((Lpst_PackSigType->en_NoOfBytes <= COMXF_EIGHT_BYTE_SIZE)))
  {
    /* Shift the data to signal position */
    dataElement <<= (uint8)(Lpst_PackSigType->en_ShiftBits);

    /* Point the signal buffer to dataElement */
    Lpt_SigBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &dataElement;

    /* Copy Rte buffer value to local variable */
    Lu8_DestBuffData =  Lpt_buffer[Ls8_bytePos];

    /* Clear the data at signal position using start mask */
    Lu8_DestBuffData &= (Lpst_PackSigType->u8_StartORClearBitMask);

    /* Check whether CPU is Big or Little endian */
    #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

    Lpt_SigBuff[Lu8_NoOfBytes] &= 
      (uint8)(~(Lpst_PackSigType->u8_StartORClearBitMask));

    #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

    /* Copy dataElement value to Rte buffer */
    Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[Lu8_NoOfBytes];

    do
    {
      /* Increment the local variable */
      Lu8_NoOfBytes++;

      /* Increment or decrement pointer based on CPU endianness */
      Ls8_bytePos += Ls8_ByteDirection;;

      /* Copy dataElement value to Rte buffer */
      Lpt_buffer[Ls8_bytePos] = Lpt_SigBuff[Lu8_NoOfBytes];

    } while(Lu8_NoOfBytes <
        ((uint8)(Lpst_PackSigType->en_NoOfBytes) - (uint8) COMXF_TWO_BYTES));

    /* Increment or decrement pointer based on CPU endianness */
    Ls8_bytePos += Ls8_ByteDirection;;

    /* Copy dataElement value to local variable */
    Lu8_DestBuffData =  Lpt_buffer[Ls8_bytePos];

    /* Check whether CPU is Big or Little endian */
    #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)
    Lpt_SigBuff[(uint8)(Lpst_PackSigType->en_NoOfBytes) - (uint8)COMXF_FIRST_BYTE]
      &= (uint8)(~(Lpst_PackSigType->u8_SetOREndMsk));

    #endif /* End of #if (CPU_BYTE_ORDER == LOW_WORD_FIRST) */

    /* Clear the data at signal position using end mask */
    Lu8_DestBuffData &= (Lpst_PackSigType->u8_SetOREndMsk);

    /* Copy dataElement value to Rte buffer */
    Lpt_buffer[Ls8_bytePos] = Lu8_DestBuffData | Lpt_SigBuff[(uint8)
      (Lpst_PackSigType->en_NoOfBytes) - (uint8) COMXF_FIRST_BYTE];
  }
  else 
  {
    /* No action */
  }
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_PackFloat32ByteNotAlign                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack float32 byte not aligned         **
**                        type signal                                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackFloat32ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  float32 dataElement, sint8 Ls8_ByteDirection)
{
  /* Union to store signal data */
  ComXf_SigFloat32Type Lun_AppSigData;

  /* Copy the data from dataElement */
  Lun_AppSigData.f32_Float32Access = dataElement;

  /* API called for packing the data */
  ComXf_Pack5ByteNotAlign(Lpt_buffer, Lpst_PackSigType,
    Lun_AppSigData.u32_Float32Access, Ls8_ByteDirection);
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_PackFloat64ByteNotAlign                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will pack float64 byte not aligned         **
**                        type signal                                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_PackSigType, dataElement, Ls8_ByteDirection    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Lpt_buffer                                          **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_PackFloat64ByteNotAlign(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_buffer,
  P2CONST(ComXf_PackSigType, AUTOMATIC, COMXF_CONST) Lpst_PackSigType,
  float64 dataElement, sint8 Ls8_ByteDirection)
{
  /* Union to store signal data */
  ComXf_SigFloat64Type Lun_AppSigData;/* 9018,[MISRA 2012 Rule 19.2, advisory]*/

  /* Copy the data from dataElement */
  Lun_AppSigData.f64_Float64Access = dataElement;

  /* API called for packing the data */
  ComXf_Pack9ByteNotAlign(Lpt_buffer, Lpst_PackSigType,
    Lun_AppSigData.u64_Float64Access, Ls8_ByteDirection);
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/* polyspace-end MISRA-C3:17.8 [Not a defect: Justified] "No Imapct of this rule violations" */
/* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
/* polyspace-end MISRA-C3:18.4 [Not a defect: Justified] "Decrement and Increment operator is used to achieve better throughput" */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
