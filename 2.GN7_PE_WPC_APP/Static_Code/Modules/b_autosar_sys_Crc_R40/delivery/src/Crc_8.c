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
**  SRC-MODULE: Crc_8.c                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation for 8-bit CRC functions of Crc Library Module  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.3.8     30-Dec-2021   JHLim            Redmine #33343                    **
** 1.3.6     30-Dec-2020   YJ Yun           Redmine 27373                     **
** 1.3.5    03-May-2019   YJ Yun           Redmine #17358, #6718              **
** 1.0.0     07-Feb-2013   CY Song          Initial Version                   **
*******************************************************************************/
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace:begin<RTE:IDP:Not a defect:Justify with annotations > parameter memory access index
*/

/* polyspace-begin MISRA-C3:20.1 [Not a defect:Low] No Impact of this rule violation */



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Crc.h"                     /* Crc Header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Crc_CalculateCRC8                                   **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : This function returns the 8 bit checksum calculated **
**                        by runtime and table based method.                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Crc_DataPtr, Crc_Length, Crc_StartValue8,           **
**                        Crc_IsFirstCall                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 8 bit result of CRC calculation                     **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Crc_GaaTable8[]               **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#if((CRC_8_MODE == CRC_8_RUNTIME) || (CRC_8_MODE == CRC_8_TABLE))
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint8 Crc_StartValue8, boolean Crc_IsFirstCall)
{
#if(CRC_8_MODE == CRC_8_TABLE)
  /* Global look up table for 8 bit table based CRC calculation */
  /* Explicit typecasting not added as it is not required */
  CONST(uint8, CRC_CONST) Crc_GaaTable8[CRC_COUNT256] =
  {
    0x00U, 0x1DU, 0x3AU, 0x27U, 0x74U, 0x69U, 0x4EU, 0x53U, 0xE8U, 0xF5U, 0xD2U, 0xCFU, 0x9CU,
    0x81U, 0xA6U, 0xBBU, 0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U, 0x83U, 0x9EU, 0x25U, 0x38U,
    0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U, 0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U,
    0xD4U, 0x6FU, 0x72U, 0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU, 0x4AU, 0x57U, 0x70U, 0x6DU,
    0x3EU, 0x23U, 0x04U, 0x19U, 0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU, 0xECU, 0xF1U, 0x13U,
    0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U, 0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U,
    0xB5U, 0xA8U, 0xDEU, 0xC3U, 0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU, 0x36U, 0x2BU, 0x0CU,
    0x11U, 0x42U, 0x5FU, 0x78U, 0x65U, 0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU, 0xDAU, 0xC7U,
    0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU, 0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU,
    0x30U, 0x17U, 0x0AU, 0xB1U, 0xACU, 0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U, 0x26U, 0x3BU,
    0x1CU, 0x01U, 0x52U, 0x4FU, 0x68U, 0x75U, 0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U, 0x80U,
    0x9DU, 0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U, 0x03U, 0x1EU, 0x39U, 0x24U,
    0x77U, 0x6AU, 0x4DU, 0x50U, 0xA1U, 0xBCU, 0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U, 0x49U,
    0x54U, 0x73U, 0x6EU, 0x3DU, 0x20U, 0x07U, 0x1AU, 0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U,
    0x22U, 0x3FU, 0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U, 0x35U, 0x28U, 0x0FU,
    0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U, 0xDDU, 0xC0U, 0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU,
    0xF8U, 0xE5U, 0xC2U, 0xDFU, 0x8CU, 0x91U, 0xB6U, 0xABU, 0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U,
    0x79U, 0x5EU, 0x43U, 0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U, 0x5AU, 0x47U,
    0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U, 0x7FU, 0x62U, 0x45U, 0x58U, 0x0BU, 0x16U, 0x31U,
    0x2CU, 0x97U, 0x8AU, 0xADU, 0xB0U, 0xE3U, 0xFEU, 0xD9U, 0xC4U
  };U
  /* polyspace-end MISRA-C3:8.7 [Justified:Low] "Intended code" */
#endif /* End if(CRC_8_MODE == CRC_8_TABLE) */

  /* Pointer to data byte */
  P2CONST(uint8, CRC_CONST, CRC_CONST) LpDataPtr;
  /* Variable to hold CRC Length */
  uint32 LulCrcLen;
  /* Variable to hold data byte */
  uint8 LucNxtDataWord;
  /* Start value or Initial value of CRC result as passed by NVRAM Manager */
  uint8 LucCrcRegister;
  /* Counter for array index */
  uint32 LulCount;
  #if(CRC_8_MODE == CRC_8_RUNTIME)
  /* Counter for no. of bits */
  uint8 LucLoopIndex;
  #endif

  /* Local Copy of Length Parameter */
  LulCrcLen = Crc_Length;

  /* Check if it is the first function call */
  if(Crc_IsFirstCall == (boolean)CRC_TRUE)
  {
    /* Initial value for 8bit */
    LucCrcRegister = CRC_INITIAL_VALUE8;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LucCrcRegister = (Crc_StartValue8 ^ CRC_XOR_OUT8);
  }
  /* Initialize count */
  LulCount = (uint32)CRC_ZERO;
  /* Local copy of pointer to start of data */
  LpDataPtr = Crc_DataPtr;
  /* Loop for no. of data bytes */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "This variable is passed by user" */
  while(LulCrcLen > (uint32)CRC_ZERO)
  {
    /* Copy the data byte into local variable */
    /* polyspace +5 MISRA-C3:D4.14 [Justified:Low] "This variable is passed by user" */
    /* polyspace +4 MISRA-C3:D4.1 [Justified:Low] "LpDataPtr is passed by caller " */
    /* polyspace +3 MISRA-C3:18.1 [Not a defect:Low] "LpDataPtr is passed by caller " */
    LucNxtDataWord = LpDataPtr[LulCount];
    /* Perform XOR of data byte with CRC result */
    LucCrcRegister = (LucCrcRegister ^ LucNxtDataWord);
    #if(CRC_8_MODE == CRC_8_RUNTIME)
    /* Reinitialize Loop Index */
    LucLoopIndex = (uint8)CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > (uint8)CRC_ZERO)
    {
      /* Check if MSB is set */
      if(CRC_MSB8 == (LucCrcRegister & CRC_MSB8))
      {
	    /* polyspace +2 DEFECT:UINT_CONV_OVFL [Not a defect:Low] "Intended code" */
	    /* polyspace +1 MISRA-C3:D4.1 [Not a defect:Low] "Intended code" */
        LucCrcRegister = ((uint8)((uint8)CRC_FF & (LucCrcRegister << (uint8)CRC_ONE)) ^ CRC_POLY8);
      }
      else
      {
        /* If MSB is unset */
        LucCrcRegister = (uint8)(LucCrcRegister << (uint8)CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > CRC_ZERO) */
    #else
    /* Fetch value from the Table */
    LucCrcRegister = Crc_GaaTable8[LucCrcRegister];
    #endif /* End if(CRC_8_MODE == CRC_8_RUNTIME) */
    /* Decrement the count of the no. of bytes */
    LulCrcLen--;

    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)CRC_ZERO) */

  /* XOR final value with 0xFF */
  LucCrcRegister = (LucCrcRegister ^ CRC_XOR_OUT8);
  /* Return the CRC result */
  return (LucCrcRegister);
}

#endif /* End if((CRC_8_MODE == CRC_8_RUNTIME) || (CRC_8_MODE == CRC_8_TABLE))*/

#define CRC_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace:end<RTE:IDP:Not a defect:Justify with annotations> parameter memory access index
*/
/* polyspace-end MISRA-C3:20.1 [Not a defect:Low] No Impact of this rule violation */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
