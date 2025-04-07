/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE:           ComXf_UnPacking.c                                   **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain function body for generic public  **
**                        API's.                                              **
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
** 1.0.5     26-Feb-2019   SM Kwon     Redmine #14504, #16011                 **
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
/* Include for ComXf_UnPacking.h */
#include "ComXf_UnPacking.h"
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
********************************************************************************
** MISRA Rule No       : MISRA 2012 Rule 19.2, advisory                       **
** MISRA Rule          : declaration of symbol with union based type          **
** Functionality       : ComXf_SigFloat32Type and ComXf_SigFloat64Type is used**
**                     : for accessing values                                 **
** Occurrences         : In ComXf_UnPackFloat64ByteAlign,                     **
**                     : ComXf_UnPackFloat64ByteNotAlign                      **
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

** MISRA Rule No       : Info 838                                             **
** MISRA Rule          : Previously assigned value to variable not used       **
** Functionality       : Previously assigned value to variable not used in the**
**                     : mentioned functions in Occurrences. As those are     **
**                     : accessed using pointers                              **
** Occurrences         : In ComXf_UnPack1ByteNotAlign,                        **
**                     : ComXf_UnPack5ByteNotAlign, ComXf_UnPack9ByteNotAlign **
** Verification        : It is manually verified Previously value assigned is **
**                       used through pointer                                 **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 11.5, advisory                       **
** MISRA Rule          : conversion from pointer to void to pointer to other  **
**                     : type                                                 **
** Functionality       : void pointer dataElement is converted to uint8 * type**
** Occurrences         : In ComXf_UnPackArray                                 **
** Verification        : It is manually verified that pointer should not      **
**                       create any problem                                   **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 20.1, advisory                       **
** MISRA Rule          : declaration of 'ComXf_UnPackBoolean' before #include **
** Functionality       : declaration of 'ComXf_UnPackBoolean' before #include **
** Occurrences         : In ComXf_UnPackBoolean                               **
** Verification        : declaration of ComXf_UnPackBoolean                   **
**                       create any problem                                   **
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
*******************************************************************************/

/*******************************************************************************

**                             MISRA Exceptions                               **
********************************************************************************
** MISRA Rule No       : MISRA 2012 Rule 19.2, advisory                       **
** MISRA Rule          : declaration of symbol with union based type          **
** Functionality       : ComXf_SigFloat32Type and ComXf_SigFloat64Type is used**
**                     : for accessing values                                 **
** Occurrences         : In ComXf_UnPackFloat64ByteAlign,                     **
**                     : ComXf_UnPackFloat64ByteNotAlign                      **
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

** MISRA Rule No       : Info 838                                             **
** MISRA Rule          : Previously assigned value to variable not used       **
** Functionality       : Previously assigned value to variable not used in the**
**                     : mentioned functions in Occurrences. As those are     **
**                     : accessed using pointers                              **
** Occurrences         : In ComXf_UnPack1ByteNotAlign,                        **
**                     : ComXf_UnPack5ByteNotAlign, ComXf_UnPack9ByteNotAlign **
** Verification        : It is manually verified Previously value assigned is **
**                       used through pointer                                 **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 11.5, advisory                       **
** MISRA Rule          : conversion from pointer to void to pointer to other  **
**                     : type                                                 **
** Functionality       : void pointer dataElement is converted to uint8 * type**
** Occurrences         : In ComXf_UnPackArray                                 **
** Verification        : It is manually verified that pointer should not      **
**                       create any problem                                   **
** Verification Method : Code review                                          **
*******************************************************************************/
/* polyspace-begin MISRA-C3:18.4 [Not a defect: Justified] "Decrement and Increment operator is used to achieve better throughput" */
/* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
/*******************************************************************************
**                           Function Definitions                             **
*******************************************************************************/
/*=============================================================================*
** Service Name         : ComXf_UnPackBoolean                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack boolean type signal            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(boolean, COMXF_CODE) ComXf_UnPackBoolean(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType)
{
  /* Local variable to store dataElement value */
  boolean Lbl_DataElement;

  /* Make Lbl_DataElement as false */
  Lbl_DataElement = COMXF_FALSE;

  /* Apply end mask and check for value as 1 */
  if((*Lpt_buffer & Lpst_UnPackSigType->u8_RxEndMsk) != (boolean) COMXF_FALSE)
  {
    /* Make Lbl_DataElement as true */
    Lbl_DataElement = COMXF_TRUE;
  }

  /* Return Lbl_DataElement value */
  return Lbl_DataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack2ByteAlign                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack byte aligned uint16 signal in  **
**                        to single byte                                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint16, COMXF_CODE) ComXf_UnPack2ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;
  
    /* Local variable to store data element value */
  uint16 Lu16_dataElement;  

  /* Local pointer to data element */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuff;

  /* Take a pointer to signal data element */
  Lpt_DataBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &Lu16_dataElement;

  /* Copy the data from input buffer */
  Lpt_DataBuff[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  /*
   * Increment or decrement data buffer pointer as per endianness
   * If CPU and Signal Endianness is same then it will be incremented otherwise
   * decremented
   */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from input buffer */
  Lpt_DataBuff[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Return value */
  return Lu16_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack3ByteAlign                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack 3 byte aligned signal          **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint32, COMXF_CODE) ComXf_UnPack3ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data element value */
  uint32 Lu32_dataElement;

  /* Local variable to store sign mask value */
  uint32 Lu32_SigSignMsk;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuff;

  Lu32_dataElement = (uint32) COMXF_HEX_00;

  /* Take a pointer to signal data */
  Lpt_DataBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &Lu32_dataElement;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_SECOND_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Take sign mask value into local variable  */
  Lu32_SigSignMsk = Lpst_UnPackSigType->u32_SigSignMsk;

  /* Check whether signal data is signed or unsigned */
  if ((Lu32_dataElement & Lu32_SigSignMsk) != (uint32) COMXF_NOT_SIGNED_SIGNAL)
  {
    /* Take signed value into Lpt_DataBuff */
    Lu32_dataElement |= Lu32_SigSignMsk;
  }

  /* Return Lu32_dataElement */
  return Lu32_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack4ByteAlign                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack 4 byte aligned signal          **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
/* polyspace +1 MISRA-C3:8.7 [Not a defect: Justified] "Depends on configuration having external linkage" */
FUNC(uint32, COMXF_CODE) ComXf_UnPack4ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data element value */
  uint32 Lu32_dataElement;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuff;

  /* Take a pointer to signal data */
  Lpt_DataBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &Lu32_dataElement;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_SECOND_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from Rte buffer */
  Lpt_DataBuff[COMXF_THIRD_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Return Lu32_DataElement */
  return Lu32_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPackUint64ByteAlign                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack 5,6,7 and 8 byte aligned       **
**                        signals                                             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint64                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint64, COMXF_CODE) ComXf_UnPackUint64ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to check against the number of bytes */
  uint8 Lu8_NoOfBytes;

  /* Local variable to store data element value */
  uint64 Lu64_dataElement;

  /* Local variable to store sign mask value */
  uint64 Lu64_SigSignMsk;

  /* Local pointer to signal */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuff;


  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  Lu64_dataElement = (uint64) COMXF_HEX_00;

  /* This check is for polyspace work-around
   * This en_NoOfBytes variable associated to this function 
   * will always be generated with value in range [5..8] */
  if ((Lpst_UnPackSigType->en_NoOfBytes >= COMXF_FIVE_BYTE_SIZE) &&
    ((Lpst_UnPackSigType->en_NoOfBytes <= COMXF_EIGHT_BYTE_SIZE)))
  {

    /* Take a pointer to signal data */
    Lpt_DataBuff = (P2VAR(uint8, AUTOMATIC, COMXF_VAR)) &Lu64_dataElement;

    do
    {
      /* Copy the data from Rte buffer */
      Lpt_DataBuff[Lu8_NoOfBytes] = Lpt_buffer[Ls8_bytePos];

      /* Increment or decrement data buffer pointer as per endianness */
      Ls8_bytePos += Ls8_ByteDirection;

      /* Increment the local variable */
      Lu8_NoOfBytes ++;

    }while(Lu8_NoOfBytes < (uint8)(Lpst_UnPackSigType->en_NoOfBytes));

    /* Take sign mask value into local variable  */
    Lu64_SigSignMsk = Lpst_UnPackSigType->u64_SigSignMsk;

    /* Check whether signal data is signed or unsigned */
    if ((Lu64_dataElement & Lu64_SigSignMsk) != (uint64) COMXF_NOT_SIGNED_SIGNAL)
    {
      /* Take signed value into Lpt_DataBuff */
      Lu64_dataElement |= Lu64_SigSignMsk;
    }
  }
  else 
  {
    /* No action */
  }
  /* Return Lu64_dataElement */
  return Lu64_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_UnPackFloat32ByteAlign                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack float32 byte aligned           **
**                        type signal                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : float32                                             **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(float32, COMXF_CODE) ComXf_UnPackFloat32ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  sint8 Ls8_ByteDirection)
{
  /* Union to store data */
  ComXf_SigFloat32Type Lun_AppSigData;

  /* Copy the unpacked data in the union */
  Lun_AppSigData.u32_Float32Access =
    ComXf_UnPack4ByteAlign(Lpt_buffer, Ls8_ByteDirection);

  /* Return union signal data */
  return Lun_AppSigData.f32_Float32Access;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPackFloat64ByteAlign                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack float64 byte aligned           **
**                        type signal                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : float64                                             **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(float64, COMXF_CODE) ComXf_UnPackFloat64ByteAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Union to store data */
  ComXf_SigFloat64Type Lun_AppSigData;

  /* Copy the unpacked data in the union */
  Lun_AppSigData.u64_Float64Access =
    ComXf_UnPackUint64ByteAlign(Lpt_buffer,
      Lpst_UnPackSigType, Ls8_ByteDirection);

  /* Return union signal data */
  return Lun_AppSigData.f64_Float64Access ;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_UnPack1ByteNotAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack single byte not aligned signal **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint8, COMXF_CODE) ComXf_UnPack1ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COM_CONST) Lpst_UnPackSigType)
{
  /* Local variable to store data element value */
  uint8 Lu8_DataElement;

  /* Local variable to store sign mask value */
  uint8 Lu8_SigSignMsk;

  Lu8_DataElement = *Lpt_buffer;

  /* Mask the Data with end mask to clear data other than signal data */
  Lu8_DataElement = Lu8_DataElement & (Lpst_UnPackSigType->u8_RxEndMsk);

  /* Shift the data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu8_DataElement = Lu8_DataElement >> (uint8)(Lpst_UnPackSigType->en_ShiftBits);

  /* Take sign mask value into local variable  */
  Lu8_SigSignMsk = (uint8) Lpst_UnPackSigType->u32_SigSignMsk;

  /* Check whether signal data is signed or unsigned */
  /* polyspace:begin <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
  if ((Lu8_DataElement & Lu8_SigSignMsk) != (uint8) COMXF_NOT_SIGNED_SIGNAL)
  {
    /* Take signed value into Lpt_DataBuff */
    Lu8_DataElement |= Lu8_SigSignMsk;
  }
  /* polyspace:end <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */

  /* Return Lu8_DataElement */
  return Lu8_DataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
/*=============================================================================*
** Service Name         : ComXf_UnPack2ByteNotAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack single byte spread across 2    **
**                        bytes and 2 byte not aligned                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint16, COMXF_CODE) ComXf_UnPack2ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data element value */
  uint16 Lu16_dataElement;

  /* Local variable to store sign mask value */
  uint16 Lu16_SigSignMsk;

  /* Local pointer to signal data */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuffer;

  Lu16_dataElement = (uint16) COMXF_HEX_00;

  /* Take a pointer to signal data */
  Lpt_DataBuffer = (P2VAR(uint8, AUTOMATIC, COM_VAR)) &Lu16_dataElement;

  /* Copy the data from Rte buffer */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy the data from Rte buffer */
  Lpt_DataBuffer[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Apply end mask and copy the data from Rte buffer */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] &= Lpst_UnPackSigType->u8_RxEndMsk;

  #else

  /* Apply end mask and copy the data from Rte buffer */
  Lpt_DataBuffer[COMXF_FIRST_BYTE] &= Lpst_UnPackSigType->u8_RxEndMsk;

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Shift data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu16_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);

  /* Take signed value into Lpt_DataBuff */
  Lu16_SigSignMsk = (uint16) Lpst_UnPackSigType->u32_SigSignMsk;

  /* Check whether signal data is signed or unsigned */
  if ((Lu16_dataElement& Lu16_SigSignMsk) != (uint16) COMXF_NOT_SIGNED_SIGNAL)
  {
    /* Take signed value into Lpt_DataBuff */
    Lu16_dataElement |= Lu16_SigSignMsk;
  }

  /* Return Lu16_dataElement */
  return Lu16_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack3ByteNotAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack 2 byte not aligned signal      **
**                        spread across 3 bytes and 3 byte not aligned        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint32, COMXF_CODE) ComXf_UnPack3ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data element value */
  uint32 Lu32_dataElement;

  /* Local variable to store sign mask value */
  uint32 Lu32_SigSignMsk;

  /* Local pointer to signal data */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuffer;

  Lu32_dataElement = (uint32) COMXF_HEX_00;

  /* Take a pointer to signal data */
  Lpt_DataBuffer = (P2VAR(uint8, AUTOMATIC, COM_VAR)) &Lu32_dataElement;

  /* Check whether CPU is Big or Little endian */
  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Increment signal data pointer */
  Lpt_DataBuffer++;

  /* Copy data from Rte buffer */
  *Lpt_DataBuffer = Lpt_buffer[Ls8_bytePos];

  /* Apply end mask to received signal data */
  *Lpt_DataBuffer &= Lpst_UnPackSigType->u8_RxEndMsk;

  /* Increment signal data pointer */
  Lpt_DataBuffer++;

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  *Lpt_DataBuffer = Lpt_buffer[Ls8_bytePos];

  /* Increment signal data pointer */
  Lpt_DataBuffer++;

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  *Lpt_DataBuffer = Lpt_buffer[Ls8_bytePos];

  /* Shift data to signal position */
  Lu32_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);

  #else

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_SECOND_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Apply end mask to received signal data */
  Lpt_DataBuffer[COMXF_SECOND_BYTE] &= Lpst_UnPackSigType->u8_RxEndMsk;

   /* Shift data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu32_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Take signed value into Lpt_DataBuff */
  Lu32_SigSignMsk = Lpst_UnPackSigType->u32_SigSignMsk;

  /* Check whether signal data is signed or unsigned */
  if ((Lu32_dataElement & Lu32_SigSignMsk) != (uint32) COMXF_NOT_SIGNED_SIGNAL)
  {
    /* Take signed value into Lpt_DataBuff */
    Lu32_dataElement |= Lu32_SigSignMsk;
  }

  /* Return Lu32_dataElement */
  return Lu32_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack4ByteNotAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack signal if signal is packed     **
**                        within 4 bytes.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint32, COMXF_CODE) ComXf_UnPack4ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data element value */
  uint32 Lu32_dataElement;

  /* Local variable to store sign mask value */
  uint32 Lu32_SigSignMsk;

  /* Local pointer to signal data */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuffer;

  Lu32_dataElement = (uint32) COMXF_HEX_00;

  /* Take a pointer to signal data */
  Lpt_DataBuffer = (P2VAR(uint8, AUTOMATIC, COM_VAR)) &Lu32_dataElement;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_SECOND_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_THIRD_BYTE] = Lpt_buffer[Ls8_bytePos];

  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Apply end mask to received signal data */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] &= Lpst_UnPackSigType->u8_RxEndMsk;

  #else
  /* Apply end mask to received signal data */
  Lpt_DataBuffer[COMXF_THIRD_BYTE] &= Lpst_UnPackSigType->u8_RxEndMsk;

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Shift data to signal position */
  /* polyspace +1 RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu32_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);

  /* Apply end mask to received signal data */
  Lu32_SigSignMsk = Lpst_UnPackSigType->u32_SigSignMsk;

  /* Check whether signal data is signed or unsigned */
  if ((Lu32_dataElement & Lu32_SigSignMsk) != (uint32) COMXF_NOT_SIGNED_SIGNAL)
  {
    /* Take signed value into Lpt_DataBuff */
    Lu32_dataElement |= Lu32_SigSignMsk;
  }

  /* Return Lu32_dataElement */
  return Lu32_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack5ByteNotAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack signal if signal is packed     **
**                        within 5 bytes.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint32                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
/* polyspace +1 MISRA-C3:8.7 [Not a defect: Justified] "Depends on configuration having external linkage" */
FUNC(uint32, COMXF_CODE) ComXf_UnPack5ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to store data element value */
  uint32 Lu32_dataElement;

  /* Local variable to store high byte data element value */
  uint32 Lu32_dataElementHighByte;

  /* Local variable to store sign mask value */
  uint32 Lu32_SigSignMsk;

  /* Local pointer to signal data */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuffer;

  Lu32_dataElement = (uint32) COMXF_HEX_00;

  /* Take a pointer to signal data */
  Lpt_DataBuffer = (P2VAR(uint8, AUTOMATIC, COM_VAR)) &Lu32_dataElement;

  #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

  /* Copy high byte of signal data from Rte buffer */
  Lu32_dataElementHighByte = Lpt_buffer[Ls8_bytePos];

  /* increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  #else

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

  #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_FIRST_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_SECOND_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy data from Rte buffer */
  Lpt_DataBuffer[COMXF_THIRD_BYTE] = Lpt_buffer[Ls8_bytePos];

  /* #333*/
  #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)
  /* Increment or decrement data buffer pointer as per endianness */
  Ls8_bytePos += Ls8_ByteDirection;

  /* Copy high byte of signal data */
  Lu32_dataElementHighByte = Lpt_buffer[Ls8_bytePos];

  #endif

  /* Apply end mask to received signal data */
  Lu32_dataElementHighByte &= Lpst_UnPackSigType->u8_RxEndMsk;

  /* Shift data to signal position */
  /* polyspace-begin RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */
  Lu32_dataElementHighByte <<= ((uint32)
    COMXF_SHIFT_BY_THIRTYTWO - (uint8)(Lpst_UnPackSigType->en_ShiftBits));

  /* Shift data to signal position */
  Lu32_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);	
  /* polyspace-end RTE:SHF [Not a defect: Justified] "Result value can not be outside its bounds" */

  /* Do ORing of high byte of signal data with remaining data */
  Lu32_dataElement = Lu32_dataElement | Lu32_dataElementHighByte;

  /* Apply end mask to received signal data */
  Lu32_SigSignMsk = Lpst_UnPackSigType->u32_SigSignMsk;

  /* Check whether signal data is signed or unsigned */
  if ((Lu32_dataElement & Lu32_SigSignMsk) != (uint32) COMXF_NOT_SIGNED_SIGNAL)
  {
    /* Take signed value into Lpt_DataBuff */
    Lu32_dataElement |= Lu32_SigSignMsk;
  }

  /* Return Lu32_dataElement */
  return Lu32_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPackArray                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack signal if signal type is array **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : dataElement                                         **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
/* #33357: Cert C EXP36-C : change dataElement type from "void pointer" to "uint8 pointer" as it is. */
FUNC(void, COMXF_CODE) ComXf_UnPackArray(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) dataElement)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local pointer to signal data buffer */
  P2VAR(uint8, AUTOMATIC, COM_VAR_NO_INIT) Lpt_SigBuffer;

  /* No of bytes of signal data */
  uint8 Lu8_SigBytesSize;

  /* Copy the Size of signal bytes */
  Lu8_SigBytesSize = (uint8)(Lpst_UnPackSigType->en_NoOfBytes);

  /* Take a pointer to signal data */
  /* polyspace<MISRA-C3:11.5:Not a defect:Low> It is manually verified that pointer should not create any problem */
  Lpt_SigBuffer = dataElement;
  /* Loop for signal size */
  do
  {
    /* Copy the data from signal buffer to application buffer */
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    *Lpt_SigBuffer = Lpt_buffer[Ls8_bytePos];

    /* Increment the application buffer pointer */
    Lpt_SigBuffer++;

    /* Increment the signal buffer pointer */
    Ls8_bytePos++;

    /* Decrement the signal size count */
    Lu8_SigBytesSize--;

  }while(Lu8_SigBytesSize != (uint8) COMXF_HEX_00);
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPack9ByteNotAlign                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack signal if signal is packed     **
**                        within 9 bytes.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint64                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint64, COMXF_CODE) ComXf_UnPack9ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to to check against the number of bytes */
  uint8 Lu8_NoOfBytes;

  /* Local variable to store data element value */
  uint64 Lu64_dataElement;

  /* Local variable to store high byte data element value */
  uint64 Lu64_dataElementHighByte;

  /* Local variable to store sign mask value */
  uint64 Lu64_SigSignMsk;

  /* Local pointer to signal data */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuffer;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  Lu64_dataElement = (uint64) COMXF_HEX_00;

  /* This check is for polyspace work-around
   * This en_NoOfBytes variable associated to this function 
   * will always be generated with value 9 */
  if (Lpst_UnPackSigType->en_NoOfBytes == COMXF_NINE_BYTE_SIZE)
  {
    /* Take a pointer to signal data */
    Lpt_DataBuffer = (P2VAR(uint8, AUTOMATIC, COM_VAR)) &Lu64_dataElement;

    #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

    /* Copy high byte of signal data from Rte buffer */
    Lu64_dataElementHighByte = Lpt_buffer[Ls8_bytePos];

    /* Increment or decrement data buffer pointer as per endianness */
    Ls8_bytePos += Ls8_ByteDirection;

    /* Copy data from Rte buffer */
    Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

    #else

    /* Copy data from Rte buffer */
    Lpt_DataBuffer[COMXF_ZEROTH_BYTE] = Lpt_buffer[Ls8_bytePos];

    #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

    /* Increment or decrement data buffer pointer as per endianness */
    Ls8_bytePos += Ls8_ByteDirection;

    do
    {
      /* Increment the local variable */
      Lu8_NoOfBytes++;

      /* Copy data from input buffer */
      Lpt_DataBuffer[Lu8_NoOfBytes] = Lpt_buffer[Ls8_bytePos];

      /* Increment or decrement data buffer pointer as per endianness */
      Ls8_bytePos += Ls8_ByteDirection;

    }while(Lu8_NoOfBytes <
      ((uint8)(Lpst_UnPackSigType->en_NoOfBytes) - (uint8) COMXF_TWO_BYTES));

    #if (CPU_BYTE_ORDER == LOW_WORD_FIRST)

    /* Copy high byte of signal data */
    Lu64_dataElementHighByte = Lpt_buffer[Ls8_bytePos];

    #endif

    /* Apply end mask to received signal data */
    Lu64_dataElementHighByte &= Lpst_UnPackSigType->u8_RxEndMsk;

    /* Shift data to start of low byte */
    Lu64_dataElementHighByte <<= ((uint8)COMXF_SHIFT_BY_EIGHT - (uint8)(Lpst_UnPackSigType->en_ShiftBits));
    
    /* Shift data to high byte position */
    Lu64_dataElementHighByte <<= (uint8)(COMXF_SEVEN_BYTE_SIZE)*(uint8)COMXF_SHIFT_BY_EIGHT;

    /* Shift data to signal position */
    Lu64_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);

    /* Do ORing of high byte of signal data with remaining data */
    Lu64_dataElement = Lu64_dataElement | Lu64_dataElementHighByte;

    /* Apply end mask to received signal data */
    Lu64_SigSignMsk = Lpst_UnPackSigType->u64_SigSignMsk;

    /* Check whether signal data is signed or unsigned */
    if ((Lu64_dataElement & Lu64_SigSignMsk) != (uint64) COMXF_NOT_SIGNED_SIGNAL)
    {
      /* Take signed value into Lpt_DataBuff */
      Lu64_dataElement |= Lu64_SigSignMsk;
    }
  }
  else 
  {
    /* No action */
  }
  /* Return Lu64_dataElement */
  return Lu64_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_UnPack5678ByteNotAlign                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack signal if signal is packed     **
**                        within 6,7 or 8 bytes.                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpt_buffer, Lpst_UnPackSigType, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint64                                              **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(uint64, COMXF_CODE) ComXf_UnPack5678ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Byte position of the destination buffer of packing */
  sint8 Ls8_bytePos = (sint8)COMXF_HEX_00;

  /* Local variable to to check against the number of bytes */
  uint8 Lu8_NoOfBytes;

  /* Local variable to store data element value */
  uint64 Lu64_dataElement;

  /* Local variable to store sign mask value */
  uint64 Lu64_SigSignMsk;

  /* Local pointer to signal data */
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) Lpt_DataBuffer;

  Lu8_NoOfBytes = (uint8) COMXF_HEX_00;

  Lu64_dataElement = (uint64) COMXF_HEX_00;

  /* This check is for polyspace work-around
   * This en_NoOfBytes variable associated to this function 
   * will always be generated with value in range [5..8] */
  if ((Lpst_UnPackSigType->en_NoOfBytes >= COMXF_FIVE_BYTE_SIZE) &&
    ((Lpst_UnPackSigType->en_NoOfBytes <= COMXF_EIGHT_BYTE_SIZE)))
  {
    /* Take a pointer to signal data */
    Lpt_DataBuffer = (P2VAR(uint8, AUTOMATIC, COM_VAR)) &Lu64_dataElement;

    do
    {
      /* Copy data from Rte buffer */
      Lpt_DataBuffer[Lu8_NoOfBytes] = Lpt_buffer[Ls8_bytePos];

      /* increment or decrement data buffer pointer as per endianness */
      Ls8_bytePos += Ls8_ByteDirection;

      /* Increment the local variable */
      Lu8_NoOfBytes++;

    }while(Lu8_NoOfBytes < (uint8)(Lpst_UnPackSigType->en_NoOfBytes));

    #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST)

    /* Apply end mask to received signal data */
    Lpt_DataBuffer[(uint8)(Lpst_UnPackSigType->en_NoOfBytes) - Lu8_NoOfBytes]
      &= Lpst_UnPackSigType->u8_RxEndMsk;

    #else
    /* Apply end mask to received signal data */
    Lpt_DataBuffer[Lu8_NoOfBytes - (uint8) COMXF_FIRST_BYTE]
      &= Lpst_UnPackSigType->u8_RxEndMsk;

    #endif /* End of #if (CPU_BYTE_ORDER == HIGH_WORD_FIRST) */

    /* Shift data to signal position */
    Lu64_dataElement >>= (uint8)(Lpst_UnPackSigType->en_ShiftBits);

    /* Apply end mask to received signal data */
    Lu64_SigSignMsk = Lpst_UnPackSigType->u64_SigSignMsk;

    /* Check whether signal data is signed or unsigned */
    if ((Lu64_dataElement & Lu64_SigSignMsk) != (uint64) COMXF_NOT_SIGNED_SIGNAL)
    {
      /* Take signed value into Lpt_DataBuff */
      Lu64_dataElement |= Lu64_SigSignMsk;
    }
  }
  else 
  {
    /* No action */
  }
  /* Return Lu64_dataElement */
  return Lu64_dataElement;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/*=============================================================================*
** Service Name         : ComXf_UnPackFloat32ByteNotAlign                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack float32 byte not aligned       **
**                        type signal                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : float32                                             **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(float32, COMXF_CODE) ComXf_UnPackFloat32ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Union to store data */
  ComXf_SigFloat32Type Lun_AppSigData;

  /* Copy the unpacked data in the union */
  Lun_AppSigData.u32_Float32Access =
    ComXf_UnPack5ByteNotAlign(Lpt_buffer,
      Lpst_UnPackSigType, Ls8_ByteDirection);

  /* Return union signal data */
  return Lun_AppSigData.f32_Float32Access;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_UnPackFloat64ByteNotAlign                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function will unpack float64 byte not aligned       **
**                        type signal                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Lpst_UnPackSigType, Lpt_buffer, Ls8_ByteDirection   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : float64                                             **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#if(COMXF_64BIT_DATATYPE_SUPPORT == STD_ON)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(float64, COMXF_CODE) ComXf_UnPackFloat64ByteNotAlign(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) Lpt_buffer,
  P2CONST(ComXf_UnPackSigType, AUTOMATIC, COMXF_CONST) Lpst_UnPackSigType,
  sint8 Ls8_ByteDirection)
{
  /* Union to store data */
  ComXf_SigFloat64Type Lun_AppSigData;

  /* Copy the unpacked data in the union */
  Lun_AppSigData.u64_Float64Access =
    ComXf_UnPack9ByteNotAlign(Lpt_buffer,
      Lpst_UnPackSigType, Ls8_ByteDirection);

  /* Return union signal data */
  return Lun_AppSigData.f64_Float64Access ;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif
/* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
/* polyspace-end MISRA-C3:18.4 [Not a defect: Justified] "Decrement and Increment operator is used to achieve better throughput" */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
