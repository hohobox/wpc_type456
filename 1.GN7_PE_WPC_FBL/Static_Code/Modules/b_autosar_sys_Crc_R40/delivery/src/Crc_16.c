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
**  SRC-MODULE: Crc_16.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation of 16-bit CRC functions for Crc Library Module **
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
** Function Name        : Crc_CalculateCRC16                                  **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : This function returns the 16 bit checksum calculated**
**                        by runtime and table based method.                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : Crc_DataPtr, Crc_Length, Crc_StartValue16,          **
**                        Crc_IsFirstCall                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : 16 bit result of CRC calculation                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Crc_GaaTable16[]           **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if((CRC_16_MODE == CRC_16_RUNTIME) || (CRC_16_MODE == CRC_16_TABLE))

FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
  (P2CONST(uint8, CRC_CONST, CRC_APPL_CONST)Crc_DataPtr, uint32 Crc_Length,
  uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
{
  /* Global look up table for 16 bit table based CRC calculation */
  /* Explicit typecasting not added as it is not required */
#if (CRC_16_MODE == CRC_16_TABLE)
  CONST(uint16, CRC_CONST) Crc_GaaTable16[CRC_COUNT256] =
  {
    0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50A5U, 0x60C6U, 0x70E7U,
    0x8108U, 0x9129U, 0xA14AU, 0xB16BU, 0xC18CU, 0xD1ADU, 0xE1CEU, 0xF1EFU,
    0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52B5U, 0x4294U, 0x72F7U, 0x62D6U,
    0x9339U, 0x8318U, 0xB37BU, 0xA35AU, 0xD3BDU, 0xC39CU, 0xF3FFU, 0xE3DEU,
    0x2462U, 0x3443U, 0x0420U, 0x1401U, 0x64E6U, 0x74C7U, 0x44A4U, 0x5485U,
    0xA56AU, 0xB54BU, 0x8528U, 0x9509U, 0xE5EEU, 0xF5CFU, 0xC5ACU, 0xD58DU,
    0x3653U, 0x2672U, 0x1611U, 0x0630U, 0x76D7U, 0x66F6U, 0x5695U, 0x46B4U,
    0xB75BU, 0xA77AU, 0x9719U, 0x8738U, 0xF7DFU, 0xE7FEU, 0xD79DU, 0xC7BCU,
    0x48C4U, 0x58E5U, 0x6886U, 0x78A7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U,
    0xC9CCU, 0xD9EDU, 0xE98EU, 0xF9AFU, 0x8948U, 0x9969U, 0xA90AU, 0xB92BU,
    0x5AF5U, 0x4AD4U, 0x7AB7U, 0x6A96U, 0x1A71U, 0x0A50U, 0x3A33U, 0x2A12U,
    0xDBFDU, 0xCBDCU, 0xFBBFU, 0xEB9EU, 0x9B79U, 0x8B58U, 0xBB3BU, 0xAB1AU,
    0x6CA6U, 0x7C87U, 0x4CE4U, 0x5CC5U, 0x2C22U, 0x3C03U, 0x0C60U, 0x1C41U,
    0xEDAEU, 0xFD8FU, 0xCDECU, 0xDDCDU, 0xAD2AU, 0xBD0BU, 0x8D68U, 0x9D49U,
    0x7E97U, 0x6EB6U, 0x5ED5U, 0x4EF4U, 0x3E13U, 0x2E32U, 0x1E51U, 0x0E70U,
    0xFF9FU, 0xEFBEU, 0xDFDDU, 0xCFFCU, 0xBF1BU, 0xAF3AU, 0x9F59U, 0x8F78U,
    0x9188U, 0x81A9U, 0xB1CAU, 0xA1EBU, 0xD10CU, 0xC12DU, 0xF14EU, 0xE16FU,
    0x1080U, 0x00A1U, 0x30C2U, 0x20E3U, 0x5004U, 0x4025U, 0x7046U, 0x6067U,
    0x83B9U, 0x9398U, 0xA3FBU, 0xB3DAU, 0xC33DU, 0xD31CU, 0xE37FU, 0xF35EU,
    0x02B1U, 0x1290U, 0x22F3U, 0x32D2U, 0x4235U, 0x5214U, 0x6277U, 0x7256U,
    0xB5EAU, 0xA5CBU, 0x95A8U, 0x8589U, 0xF56EU, 0xE54FU, 0xD52CU, 0xC50DU,
    0x34E2U, 0x24C3U, 0x14A0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U,
    0xA7DBU, 0xB7FAU, 0x8799U, 0x97B8U, 0xE75FU, 0xF77EU, 0xC71DU, 0xD73CU,
    0x26D3U, 0x36F2U, 0x0691U, 0x16B0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U,
    0xD94CU, 0xC96DU, 0xF90EU, 0xE92FU, 0x99C8U, 0x89E9U, 0xB98AU, 0xA9ABU,
    0x5844U, 0x4865U, 0x7806U, 0x6827U, 0x18C0U, 0x08E1U, 0x3882U, 0x28A3U,
    0xCB7DU, 0xDB5CU, 0xEB3FU, 0xFB1EU, 0x8BF9U, 0x9BD8U, 0xABBBU, 0xBB9AU,
    0x4A75U, 0x5A54U, 0x6A37U, 0x7A16U, 0x0AF1U, 0x1AD0U, 0x2AB3U, 0x3A92U,
    0xFD2EU, 0xED0FU, 0xDD6CU, 0xCD4DU, 0xBDAAU, 0xAD8BU, 0x9DE8U, 0x8DC9U,
    0x7C26U, 0x6C07U, 0x5C64U, 0x4C45U, 0x3CA2U, 0x2C83U, 0x1CE0U, 0x0CC1U,
    0xEF1FU, 0xFF3EU, 0xCF5DU, 0xDF7CU, 0xAF9BU, 0xBFBAU, 0x8FD9U, 0x9FF8U,
    0x6E17U, 0x7E36U, 0x4E55U, 0x5E74U, 0x2E93U, 0x3EB2U, 0x0ED1U, 0x1EF0U
  };
#endif
  /* Pointer to hold data byte */
  P2CONST(uint8, CRC_CONST, CRC_CONST) LpDataPtr;

  /* Union object of type Crc_Word16 to hold start value */
  Crc_Word16 LunCrc16;

  /* Variable to hold CRC Length */
  uint32 LulCrcLen;
  
  /* Counter for array index */
  uint32 LulCount;

  #if(CRC_16_MODE == CRC_16_RUNTIME)

  /* Union object of type Crc_Word16 to hold data byte */
  Crc_Word16 LunNxtData;
  /* Counter for no. of bits */
  uint8 LucLoopIndex;
  #else
  /* Index of the Table */
  uint8 LucTableIndex;
  #endif /* End if(CRC_16_MODE == CRC_16_RUNTIME) */

  LulCrcLen = Crc_Length;

  /* Check if it is the first function call */
  if(Crc_IsFirstCall == (boolean)CRC_TRUE)
  {
    /* Initial value for 16bit */
    LunCrc16.WordReg16 = CRC_INITIAL_VALUE16;
  }
  else
  {
    /* Initialize CRC result  with previous result */
    LunCrc16.WordReg16 = Crc_StartValue16;
  }
  /* Initialize count */
  LulCount = (uint32)CRC_ZERO;
  /* Local copy of pointer to start of data */
  LpDataPtr = Crc_DataPtr;
  /* Loop for no. of data bytes */
  /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "This variable is passed by user" */
  while(LulCrcLen > (uint32)CRC_ZERO)
  {
    #if(CRC_16_MODE == CRC_16_RUNTIME)
    /* Copy the data byte into MsByte */
    /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "This variable is passed by user" */
    LunNxtData.Byte.MsByte = LpDataPtr[LulCount];
    /* Pad zero into LsByte */
    LunNxtData.Byte.LsByte = CRC_ZERO;
    /* Perform XOR of entire data byte with CRC result */
    LunCrc16.WordReg16 = (LunCrc16.WordReg16 ^ LunNxtData.WordReg16);
    /* Reinitialize Loop Index */
    LucLoopIndex = (uint8)CRC_EIGHT;
    /* Loop for 8 bits */
    while(LucLoopIndex > (uint8)CRC_ZERO)
    {
      /* Check if MSB is set */
      if(CRC_MSB16 == (LunCrc16.WordReg16 & CRC_MSB16))
      {
        LunCrc16.WordReg16 = ((uint16)(LunCrc16.WordReg16 << (uint16)CRC_ONE) ^
          CRC_POLY16);
      }
      else
      {
        /* If MSB is unset */
        LunCrc16.WordReg16 = (LunCrc16.WordReg16 << (uint16)CRC_ONE);
      }
      LucLoopIndex--;
    } /* End while(LucLoopIndex > CRC_ZERO) */
    #else
    /*
     * Get table index by accessing directly the MSB of the 16 bit register
     * simulating a right shift by 8 bits.
     */
    /* polyspace +2 MISRA-C3:D4.14 [Justified:Low] "This variable is passed by user" */
    LucTableIndex = (LunCrc16.Byte.MsByte ^ (LpDataPtr[LulCount]));

    /* Copy LSB into MSB for simulation of a left shift by 8 bits */
    LunCrc16.Byte.MsByte = LunCrc16.Byte.LsByte;

    /* Clear LSB for completing the left shift by 8 bits */
    LunCrc16.Byte.LsByte = CRC_ZERO;

    /* XOR Crc Register with precomputed table entry using the index */
    LunCrc16.WordReg16 = (LunCrc16.WordReg16 ^
      Crc_GaaTable16[LucTableIndex]);
    #endif /* End if(CRC_16_MODE == CRC_16_RUNTIME) */
    /* Decrement the count of the no. of bytes */
    LulCrcLen--;
    /* array index to next data byte */
    LulCount++;
  } /* End while(LulCrcLen > (uint32)CRC_ZERO) */

  /* Return the CRC result */
  return (LunCrc16.WordReg16);
}
#endif /* End if((CRC_16_MODE == CRC_16_RUNTIME) ||(CRC_16_MODE == ...) */

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
