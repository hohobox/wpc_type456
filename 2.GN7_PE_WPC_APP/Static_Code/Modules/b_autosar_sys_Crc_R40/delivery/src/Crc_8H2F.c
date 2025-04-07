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
**  SRC-MODULE: Crc_8H2F.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation of 8-bit CRC functions with polynomial 0x2F    **
**              for Crc Library Module                                        **
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
** 1.3.5     03-May-2019   YJ Yun           Redmine #17358, #6718             **
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
** Function Name        : Crc_CalculateCRC8H2F                                **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This function returns the 8 bit checksum calculated **
**                        using polynomial 0x2F by runtime and table method.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : Crc_DataPtr, Crc_Length, Crc_StartValue8H2F,        **
**                        Crc_IsFirstCall                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 8 bit result of CRC for polynomial calculation      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Crc_GaaTable8H2F[]         **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if((CRC_8H2F_MODE == CRC_8H2F_RUNTIME) || (CRC_8H2F_MODE == CRC_8H2F_TABLE))

FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall)
{
#if(CRC_8H2F_MODE == CRC_8H2F_TABLE)
  /* Global look up table for 8 bit 0x2F polynomial table based CRC calculation */
  /* Explicit typecasting not added as it is not required */

  CONST(uint8, CRC_CONST) Crc_GaaTable8H2F[CRC_COUNT256] =
  {
    0x00U, 0x2FU, 0x5EU, 0x71U, 0xBCU, 0x93U, 0xE2U, 0xCDU, 0x57U, 0x78U, 0x09U, 0x26U, 0xEBU,
    0xC4U, 0xB5U, 0x9AU, 0xAEU, 0x81U, 0xF0U, 0xDFU, 0x12U, 0x3DU, 0x4CU, 0x63U, 0xF9U, 0xD6U,
    0xA7U, 0x88U, 0x45U, 0x6AU, 0x1BU, 0x34U, 0x73U, 0x5CU, 0x2DU, 0x02U, 0xCFU, 0xE0U, 0x91U,
    0xBEU, 0x24U, 0x0BU, 0x7AU, 0x55U, 0x98U, 0xB7U, 0xC6U, 0xE9U, 0xDDU, 0xF2U, 0x83U, 0xACU,
    0x61U, 0x4EU, 0x3FU, 0x10U, 0x8AU, 0xA5U, 0xD4U, 0xFBU, 0x36U, 0x19U, 0x68U, 0x47U, 0xE6U,
    0xC9U, 0xB8U, 0x97U, 0x5AU, 0x75U, 0x04U, 0x2BU, 0xB1U, 0x9EU, 0xEFU, 0xC0U, 0x0DU, 0x22U,
    0x53U, 0x7CU, 0x48U, 0x67U, 0x16U, 0x39U, 0xF4U, 0xDBU, 0xAAU, 0x85U, 0x1FU, 0x30U, 0x41U,
    0x6EU, 0xA3U, 0x8CU, 0xFDU, 0xD2U, 0x95U, 0xBAU, 0xCBU, 0xE4U, 0x29U, 0x06U, 0x77U, 0x58U,
    0xC2U, 0xEDU, 0x9CU, 0xB3U, 0x7EU, 0x51U, 0x20U, 0x0FU, 0x3BU, 0x14U, 0x65U, 0x4AU, 0x87U,
    0xA8U, 0xD9U, 0xF6U, 0x6CU, 0x43U, 0x32U, 0x1DU, 0xD0U, 0xFFU, 0x8EU, 0xA1U, 0xE3U, 0xCCU,
    0xBDU, 0x92U, 0x5FU, 0x70U, 0x01U, 0x2EU, 0xB4U, 0x9BU, 0xEAU, 0xC5U, 0x08U, 0x27U, 0x56U,
    0x79U, 0x4DU, 0x62U, 0x13U, 0x3CU, 0xF1U, 0xDEU, 0xAFU, 0x80U, 0x1AU, 0x35U, 0x44U, 0x6BU,
    0xA6U, 0x89U, 0xF8U, 0xD7U, 0x90U, 0xBFU, 0xCEU, 0xE1U, 0x2CU, 0x03U, 0x72U, 0x5DU, 0xC7U,
    0xE8U, 0x99U, 0xB6U, 0x7BU, 0x54U, 0x25U, 0x0AU, 0x3EU, 0x11U, 0x60U, 0x4FU, 0x82U, 0xADU,
    0xDCU, 0xF3U, 0x69U, 0x46U, 0x37U, 0x18U, 0xD5U, 0xFAU, 0x8BU, 0xA4U, 0x05U, 0x2AU, 0x5BU,
    0x74U, 0xB9U, 0x96U, 0xE7U, 0xC8U, 0x52U, 0x7DU, 0x0CU, 0x23U, 0xEEU, 0xC1U, 0xB0U, 0x9FU,
    0xABU, 0x84U, 0xF5U, 0xDAU, 0x17U, 0x38U, 0x49U, 0x66U, 0xFCU, 0xD3U, 0xA2U, 0x8DU, 0x40U,
    0x6FU, 0x1EU, 0x31U, 0x76U, 0x59U, 0x28U, 0x07U, 0xCAU, 0xE5U, 0x94U, 0xBBU, 0x21U, 0x0EU,
    0x7FU, 0x50U, 0x9DU, 0xB2U, 0xC3U, 0xECU, 0xD8U, 0xF7U, 0x86U, 0xA9U, 0x64U, 0x4BU, 0x3AU,
    0x15U, 0x8FU, 0xA0U, 0xD1U, 0xFEU, 0x33U, 0x1CU, 0x6DU, 0x42U
  };
  /* polyspace-end MISRA-C3:8.7 [Justified:Low] "Intended code" */
#endif /* End if(CRC_8H2F_MODE == CRC_8H2F_TABLE) */

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
  #if(CRC_8H2F_MODE == CRC_8H2F_RUNTIME)
  /* Counter for no. of bits */
  uint8 LucLoopIndex;
  #endif

  /* Local Copy of Length Parameter */
  LulCrcLen = Crc_Length;

  /* Check if it is the first function call */
  if(Crc_IsFirstCall == (boolean)CRC_TRUE)
  {
    /* Initial value for 8bit 0x2F */
    LucCrcRegister = CRC_INITIAL_VALUE8H2F;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LucCrcRegister = (Crc_StartValue8H2F ^ CRC_XOR_OUT8H2F);
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
    /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "This variable is passed by user" */
    LucNxtDataWord = LpDataPtr[LulCount];
    /* Perform XOR of data byte with CRC result */
    LucCrcRegister = (LucCrcRegister ^ LucNxtDataWord);
    #if(CRC_8H2F_MODE == CRC_8H2F_RUNTIME)
    /* Reinitialize Loop Index */
    LucLoopIndex = CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > (uint8)CRC_ZERO)
    {
      /* Check if MSB is set */
      if(CRC_MSB8 == (LucCrcRegister & CRC_MSB8))
      {
	/* polyspace +2 DEFECT:UINT_CONV_OVFL [Not a defect:Low] "Intended code" */
	/* polyspace +1 MISRA-C3:D4.1 [Not a defect:Low] "Intended code" */
        LucCrcRegister = ((uint8)((uint8)CRC_FF & (LucCrcRegister << (uint8)CRC_ONE)) ^ CRC_POLY8H2F);
      }
      else
      {
        /* If MSB is unset */
        LucCrcRegister = (LucCrcRegister << (uint8)CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > CRC_ZERO) */
    #else
    /* Fetch value from the Table */
    LucCrcRegister = Crc_GaaTable8H2F[LucCrcRegister];
    #endif /* End if(CRC_8H2F_MODE == CRC_8H2F_RUNTIME) */
    /* Decrement the count of the no. of bytes */
    LulCrcLen--;

    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)CRC_ZERO) */

  /* XOR final value with 0xFF */
  LucCrcRegister = (LucCrcRegister ^ CRC_XOR_OUT8H2F);
  /* Return the CRC result */
  return (LucCrcRegister);
}

#endif /* End if((CRC_8H2F_MODE == CRC_8H2F_RUNTIME) || (...)) */
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
