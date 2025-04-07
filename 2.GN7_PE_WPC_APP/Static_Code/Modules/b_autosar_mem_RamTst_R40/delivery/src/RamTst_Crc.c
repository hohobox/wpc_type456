/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: RamTst_Crc.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Ram Test Module                                               **
**                                                                            **
**  PURPOSE   : Implementation for CRC functions of RamTst Module             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date            By                  Description                  **
********************************************************************************
** 1.3.3     30-Dec-2021   JHLim      Redmine #33332                          **
** 1.3.2     30-Dec-2020   CY Song    RedMine #27378                          **
** 1.2.7     15-Nov-2015   CY Song    Redmine #6608                           **
** 1.2.5     16-May-2016   CY Song    RedMine #4902                           **
** 1.2.3     05-Oct-2015   CY Song    Correct Misra Rule Error                **
** 1.0.3     06-Dec-2013   CY Song        Modify CRC32 Compile Error          **
** 1.0.0     07-Jun-2013   CY Song          Initial Version                   **
*******************************************************************************/
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace:begin<RTE: NIV : Not a defect : Justify with annotations > Cannot initialize because of Application variable
polyspace:begin<RTE: IDP : Not a defect : Justify with annotations > configured memory access index
*/

/* polyspace-begin MISRA-C3:D4.14 [Justified:Low] "Value shall be cheched by user" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "RamTst.h"              /* Ram Test Module Header File */
#include "RamTst_Ram.h"          /* Ram Test Module Header File */
#include "RamTst_Crc.h"                     /* Crc Header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.1 [Not a defect:Low] "It is implemented according to autosar specification" */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define RAMTST_START_SEC_CODE
#include "MemMap.h"

#if(RAMTST_CRC_32_SUPPORT == STD_ON)
static FUNC(uint32, RAMTST_CODE) RamTst_CrcReflect(uint32 LulData,
  CONST(uint8, RAMTST_CONST) LucNbits);
#endif

#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : RamTst_CalculateCRC8                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns the 8 bit checksum calculated **
**                        by runtime method.                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RamTst_DataPtr, RamTst_Length                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 8 bit result of CRC calculation                     **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#if(RAMTST_CRC_8_SUPPORT == STD_ON)
#define RAMTST_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, RAMTST_CODE) RamTst_CalculateCRC8
(P2CONST(uint8, RAMTST_CONST, RAMTST_APPL_CONST)RamTst_DataPtr,
uint32 RamTst_Length, uint8 RamTst_CrcStartValue8,
                                                  boolean RamTst_CrcIsFirstCall)
{
  /* Pointer to data byte */
  P2CONST(uint8, RAMTST_CONST, RAMTST_CONST) LpDataPtr;
  /* Variable to hold CRC Length */
  uint32 LulCrcLen;
  /* Variable to hold data byte */
  uint8 LucByteDataWord;
  /* Start value CRC result */
  uint8 LucCrcRegister;
  /* Counter for Pointer Address */
  uint32 LulCount;
  /* Counter for no. of bits */
  uint8 LucLoopIndex;

  /* Local Copy of Length Parameter */
  LulCrcLen = RamTst_Length;

  /* Check if it is the first function call */
  if(RamTst_CrcIsFirstCall != (boolean)RAMTST_FALSE)
  {
    /* Initial value for 8bit */
    LucCrcRegister = RAMTST_CRC_INITIAL_VALUE8;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LucCrcRegister = (RamTst_CrcStartValue8 ^ RAMTST_CRC_XOR_OUT8);
  }
  /* Initialize count */
  LulCount = RAMTST_ZERO;
  /* Local copy of pointer to start of data */
  LpDataPtr = RamTst_DataPtr;
  /* Loop for no. of data bytes */
  while(LulCrcLen > (uint32)RAMTST_CRC_ZERO)
  {
    /* Copy the data byte into local variable */
    /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
    /* polyspace<MISRA-C:21.1:Not a defect:No action planned> Configured memory address  */
    LucByteDataWord = LpDataPtr[LulCount];
    /* Perform XOR of data byte with CRC result */
    LucCrcRegister = (LucCrcRegister ^ LucByteDataWord);
    /* Reinitialize Loop Index */
    LucLoopIndex = RAMTST_CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > RAMTST_CRC_ZERO)
    {
      /* Check if MSB is set */
      if(RAMTST_CRC_MSB8 == (LucCrcRegister & RAMTST_CRC_MSB8))
      {
        /* polyspace +3 MISRA-C3:D4.1 [Justified:Low] "Intended code" */
        LucCrcRegister =
                (((LucCrcRegister << (uint8)RAMTST_CRC_ONE) & RAMTST_MASK_ONE_BYTE) ^ RAMTST_CRC_POLY8);
      }
      else
      {
        /* If MSB is unset */
        LucCrcRegister = (LucCrcRegister << (uint8)RAMTST_CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > RAMTST_CRC_ZERO) */

    /* Decrement the count of the no. of bytes */
    LulCrcLen--;

    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)RAMTST_ZERO) */

  /* XOR final value with 0xFF */
  LucCrcRegister = (LucCrcRegister ^ RAMTST_CRC_XOR_OUT8);
  /* Return the CRC result */
  return (LucCrcRegister);
}
#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : RamTst_CalculateCRC8H2F                             **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This function returns the 8 bit checksum calculated **
**                        using polynomial 0x2F by runtime and table method.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Reentrant                                          **
**                                                                            **
** Input Parameters     : RamTst_DataPtr, RamTst_Length                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 8 bit result of CRC for polynomial calculation      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(RAMTST_CRC_8H2F_SUPPORT == STD_ON)
#define RAMTST_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, RAMTST_CODE) RamTst_CalculateCRC8H2F
(P2CONST(uint8, RAMTST_CONST, RAMTST_APPL_CONST)RamTst_DataPtr,
uint32 RamTst_Length, uint8 RamTst_CrcStartValue8H2F,
                                                 boolean RamTst_CrcIsFirstCall)
{
  /* Pointer to data byte */
  P2CONST(uint8, RAMTST_CONST, RAMTST_CONST) LpDataPtr;
  /* Variable to hold CRC Length */
  uint32 LulCrcLen;
  /* Variable to hold data byte */
  uint8 LucByteDataWord;
  /* Start value or Initial value of CRC result as passed by NVRAM Manager */
  uint8 LucCrcRegister;
  /* Counter for Pointer Address */
  uint32 LulCount;
  uint8 LucLoopIndex;

  /* Local Copy of Length Parameter */
  LulCrcLen = RamTst_Length;

  /* Check if it is the first function call */
  if(RamTst_CrcIsFirstCall == (boolean)RAMTST_CRC_TRUE)
  {
    /* Initial value for 8bit 0x2F */
    LucCrcRegister = RAMTST_CRC_INITIAL_VALUE8H2F;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LucCrcRegister = (RamTst_CrcStartValue8H2F ^ RAMTST_CRC_XOR_OUT8H2F);
  }
  /* Initialize count */
  LulCount = RAMTST_ZERO;
  /* Local copy of pointer to start of data */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
  LpDataPtr = RamTst_DataPtr;
  /* Loop for no. of data bytes */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
  while(LulCrcLen > (uint32)RAMTST_CRC_ZERO)
  {
    /* Copy the data byte into local variable */
    /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
    LucByteDataWord = LpDataPtr[LulCount];
    /* Perform XOR of data byte with CRC result */
    LucCrcRegister = (LucCrcRegister ^ LucByteDataWord);

    /* Reinitialize Loop Index */
    LucLoopIndex = RAMTST_CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > RAMTST_CRC_ZERO)
    {
      /* Check if MSB is set */
      if(RAMTST_CRC_MSB8 == (LucCrcRegister & RAMTST_CRC_MSB8))
      {
        /* polyspace +3 MISRA-C3:D4.1 [Justified:Low] "Intended code" */
        LucCrcRegister =
              (((LucCrcRegister << (uint8)RAMTST_CRC_ONE) & RAMTST_MASK_ONE_BYTE) ^ RAMTST_CRC_POLY8H2F);
      }
      else
      {
        /* If MSB is unset */
        LucCrcRegister = (LucCrcRegister << (uint8)RAMTST_CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > RAMTST_ZERO) */

    /* Decrement the count of the no. of bytes */
    LulCrcLen--;

    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)RAMTST_ZERO) */

  /* XOR final value with 0xFF */
  LucCrcRegister = (LucCrcRegister ^ RAMTST_CRC_XOR_OUT8H2F);
  /* Return the CRC result */
  return (LucCrcRegister);
}
#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : RamTst_CalculateCRC16                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns the 16 bit checksum calculated**
**                        by runtime and table based method.                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Reentrant                                          **
**                                                                            **
** Input Parameters     : RamTst_DataPtr, RamTst_Length                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 16 bit result of CRC calculation                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(RAMTST_CRC_16_SUPPORT == STD_ON)
#define RAMTST_START_SEC_CODE
#include "MemMap.h"
FUNC(uint16, RAMTST_CODE) RamTst_CalculateCRC16
  (P2CONST(uint8, RAMTST_CONST, RAMTST_APPL_CONST)RamTst_DataPtr,
  uint32 RamTst_Length, uint16 RamTst_CrcStartValue16,
                                                  boolean RamTst_CrcIsFirstCall)
{
  /* Pointer to hold data byte */
  P2CONST(uint8, RAMTST_CONST, RAMTST_CONST) LpDataPtr;

  /* object of type RamTst_Crc_Word16 to hold start value */
  RamTst_Crc_Word16 LunCrc16;

  /* Variable to hold CRC Length */
  uint32 LulCrcLen;

  /* Counter for array index */
  uint32 LulCount;

  /* object of type RamTst_Crc_Word16 to hold data byte */
  RamTst_Crc_Word16 LunNxtData;
  /* Counter for no. of bits */
  uint8 LucLoopIndex;

  LulCrcLen = RamTst_Length;

  /* Check if it is the first function call */
  if(RamTst_CrcIsFirstCall == (boolean)RAMTST_CRC_TRUE)
  {
    /* Initial value for 16bit */
    LunCrc16.WordReg16 = RAMTST_CRC_INITIAL_VALUE16;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LunCrc16.WordReg16 = RamTst_CrcStartValue16;
  }
  /* Initialize count */
  LulCount = RAMTST_ZERO;
  /* Local copy of pointer to start of data */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
  LpDataPtr = RamTst_DataPtr;
  /* Loop for no. of data bytes */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
  while(LulCrcLen > (uint32)RAMTST_CRC_ZERO)
  {
    /* Copy the data byte into MsByte */
    /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
    LunNxtData.MsByteForWord16 = LpDataPtr[LulCount];
    /* Pad zero into LsByte */
    LunNxtData.WordReg16 = (uint16)((uint16)(LunNxtData.MsByteForWord16) << RAMTST_EIGHT);
    /* Perform XOR of entire data byte with CRC result */
    LunCrc16.WordReg16 = (LunCrc16.WordReg16 ^ LunNxtData.WordReg16);

    /* Reinitialize Loop Index */
    LucLoopIndex = RAMTST_CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > RAMTST_CRC_ZERO)
    {
      /* Check if MSB is set */
      if(RAMTST_CRC_MSB16 == (LunCrc16.WordReg16 & RAMTST_CRC_MSB16))
      {
        /* polyspace +3 MISRA-C3:D4.1 [Justified:Low] "Intended code" */
        LunCrc16.WordReg16 = ((uint16)(LunCrc16.WordReg16 << (uint16)RAMTST_CRC_ONE) ^
          RAMTST_CRC_POLY16);
      }
      else
      {
        /* If MSB is unset */
        LunCrc16.WordReg16 = (LunCrc16.WordReg16 << (uint16)RAMTST_CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > RAMTST_CRC_ZERO) */

    /* Decrement the count of the no. of bytes */
    LulCrcLen--;
    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)RAMTST_CRC_ZERO) */

  /* Return the CRC result */
  return (LunCrc16.WordReg16);
}
#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : RamTst_CalculateCRC32                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns the 32 bit checksum calculated**
**                        by runtime method.                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RamTst_DataPtr, RamTst_Length                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 32 bit result of CRC calculation                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : RamTst_CrcReflect          **
*******************************************************************************/
#if(RAMTST_CRC_32_SUPPORT == STD_ON)
#define RAMTST_START_SEC_CODE
#include "MemMap.h"
FUNC(uint32, RAMTST_CODE) RamTst_CalculateCRC32
  (P2CONST(uint8, RAMTST_CONST, RAMTST_APPL_CONST)RamTst_DataPtr,
  uint32 RamTst_Length, uint32 RamTst_CrcStartValue32,
                                                  boolean RamTst_CrcIsFirstCall)
{
  /* Pointer to data byte */
  P2CONST(uint8, RAMTST_CONST, RAMTST_CONST) LpDataPtr;

  /* Create a object of type Crc_Dword32 */
  RamTst_Crc_Dword32 LunCrc32;

  /* Variable to hold CRC Length */
  uint32 LulCrcLen;

  /* Counter for array index */
  uint32 LulCount;
 
  /* Reflect data */
  uint32 LulReflectData;

  /* Create a object of type uint8 */
  uint8 LucByteData;

  /* Counter for no. of bits */
  uint8 LucLoopIndex;

  LulCrcLen = RamTst_Length;

  /* Check if it is the first function call */
  if(RamTst_CrcIsFirstCall == (boolean)RAMTST_CRC_TRUE)
  {
    /* Initial value for 32bit */
    LunCrc32.LongReg32 = RAMTST_CRC_INITIAL_VALUE32;
  }
  else
  {
    /* Initialize CRC result with previous result's reflected value */
    LunCrc32.LongReg32 = (uint32)RamTst_CrcReflect((RamTst_CrcStartValue32 ^ RAMTST_CRC_XOR_OUT32),
      RAMTST_CRC_THIRTYTWO);
  }
  /* Initialize count */
  LulCount = RAMTST_ZERO;
  /* Local copy of pointer to start of data */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
  LpDataPtr = RamTst_DataPtr;
  /* Loop for no. of data bytes */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "It shall be checked by user" */
  while(LulCrcLen > (uint32)RAMTST_CRC_ZERO)
  {
    /* Get next byte */
    LucByteData = LpDataPtr[LulCount];

    /* Call to Reflect input data around central bit */
    LulReflectData = (uint32)RamTst_CrcReflect(LucByteData, RAMTST_EIGHT);

    LunCrc32.LongReg32 = (LunCrc32.LongReg32 ^ (LulReflectData << RAMTST_TWENTYFOUR));
    /* Loop for Mod-2 division for each bit */
    LucLoopIndex = RAMTST_CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > RAMTST_CRC_ZERO)
    {
      /* Check if MSB is set */
      if(RAMTST_CRC_MS_BIT_LWORD ==
                                 (LunCrc32.LongReg32 & RAMTST_CRC_MS_BIT_LWORD))
      {
        /* polyspace +3 MISRA-C3:D4.1 [Justified:Low] "Intended code" */
        LunCrc32.LongReg32 =
                   ((LunCrc32.LongReg32 << RAMTST_CRC_ONE) ^ RAMTST_CRC_POLY32);
      }
      else
      {
        /* If MSB is unset */
        LunCrc32.LongReg32 = (LunCrc32.LongReg32 << RAMTST_CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > RAMTST_CRC_ZERO) */

    /* Decrement the count of the no. of bytes */
    LulCrcLen--;
    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)RAMTST_CRC_ZERO) */

  /* Reflect final checksum and XOR with 0xFFFFFFFFUL */
  LunCrc32.LongReg32 =
                    RamTst_CrcReflect(LunCrc32.LongReg32, RAMTST_CRC_THIRTYTWO);

  /* XOR final value with 0xFFFFFFFFUL */
  LunCrc32.LongReg32 = (LunCrc32.LongReg32 ^ RAMTST_CRC_XOR_OUT32);
  /* Return the reflected data */
  return (LunCrc32.LongReg32);
}
#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : RamTst_CrcReflect                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns the symmetric reflection      **
**                        of input.                                           **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LulData, LucNbits                                   **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LulReflection                                       **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(RAMTST_CRC_32_SUPPORT == STD_ON)
#define RAMTST_START_SEC_CODE
#include "MemMap.h"

static FUNC(uint32, RAMTST_CODE) RamTst_CrcReflect
  (uint32 LulData, CONST(uint8, RAMTST_CONST) LucNbits)
{
  /* Value of reflection */
  uint32 LulReflection;
  /* Value of MS bit */
  uint32 LulBit;
  /* Count of no. of bits */
  uint8 LucBitCount;

  uint32 LulSrcData = LulData;

  /* Initial value of reflection */
  LulReflection = (uint32)RAMTST_CRC_ZERO;
  /* Start of count */
  LucBitCount = RAMTST_CRC_ZERO;
  /* Check for no. of bits */
  if(LucNbits == RAMTST_CRC_EIGHT)
  {
    /* Set MS bit for one byte data  */
    LulBit = RAMTST_CRC_MSB8;
  }
  else
  {
    /* Set MS bit for Long word data */
    LulBit = RAMTST_CRC_MS_BIT_LWORD;
  }
  while(LucBitCount != LucNbits)
  {
    /* AND data with 0x01L to check if the LSB of data is set */
    if(0x1UL == (LulSrcData & 0x1UL))
    {
      /* Take mirror image of nth bit at bit position (Nbits-n) */
      LulReflection = LulReflection | LulBit;
    }
    /* Right shift by one bit */
    LulBit = LulBit >> RAMTST_CRC_ONE;
    LulSrcData = LulSrcData >> RAMTST_CRC_ONE;
    /* Increment bit count */
    LucBitCount++;
  }
  /* Return the reflected data */
  return (LulReflection);
}

#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
#endif


/* polyspace-end MISRA-C3:D4.14 [Justified:Low] "Value shall be cheched by user" */

/* polyspace-end MISRA-C3:20.1 [Not a defect:Low] "It is implemented according to autosar specification" */
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace:end<RTE: NIV : Not a defect : Justify with annotations > Cannot initialize because of Application variable
polyspace:end<RTE: IDP : Not a defect : Justify with annotations > configured memory access index
*/
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
