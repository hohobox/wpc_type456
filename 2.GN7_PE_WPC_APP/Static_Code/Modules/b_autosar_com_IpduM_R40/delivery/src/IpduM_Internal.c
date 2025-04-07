/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Internal.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Internal process Functions                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.1.0     19-May-2022   HM Shin     Internal Redmine #34769                **
** 2.0.5     07-Dec-2020   Jongsun Lim #27006                                 **
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #5688, #6788, #6822   **
** 2.0.2     15-Jul-2016   Chan Kim    Internal Redmine #5563                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM_Internal.h"
#include "SchM_IpduM.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define IPDUM_INTERNAL_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_INTERNAL_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_INTERNAL_C_AR_RELEASE_REVISION_VERSION 3

/* IPDUM software version information */
#define IPDUM_INTERNAL_C_SW_MAJOR_VERSION            2
#define IPDUM_INTERNAL_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != \
     IPDUM_INTERNAL_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM_Internal.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != \
     IPDUM_INTERNAL_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM_Internal.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_INTERNAL_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM_Internal.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_INTERNAL_C_SW_MAJOR_VERSION)
#error "IpduM_Internal.c : Mismatch in Software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_INTERNAL_C_SW_MINOR_VERSION)
#error "IpduM_Internal.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)
/* polyspace:begin<MISRA-C3:20.7:Not a defect:Justify with annotations> No Impact of this rule violation*/
/* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> Pointer is not outside its bounds - Pointer is generated by Generator*/
/* polyspace:begin<MISRA-C3:17.8:Not a defect:Unset> operation do working correctly */ 
/* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Not a defect, Decrement and Increment operator is used to achieve better throughput */
/* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured  memory access index */
/*******************************************************************************
** Function Name        : IpduM_CopySegmentBit                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function copy the data from source I-PDU to    **
**                        destination I-PDU as per the configured segments.   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU                       **
**                                                                            **
** Input Parameters     : LpSegmentBitField, LpSduPtr and                     **
**                        LucNoOfSegmentBitField                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    :                            **
**                        SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA()        **
**                        SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA()         **
*******************************************************************************/
#if (IPDUM_SEGMENT_BITFIELD == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_CopySegmentBit(P2CONST(IpduM_Segment, AUTOMATIC,
    IPDUM_CONST) LpSegmentBitField, P2VAR(
    uint8, AUTOMATIC, IPDUM_VAR) LpSduPtr, uint8 LucNoOfSegmentBitField)
{
  P2CONST(uint8, AUTOMATIC, IPDUM_CONST) LpIpduMSourceBuffer;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) LpIpduMDestBuffer;
  uint8 LucSourceData;
  uint8 LucDestData;
  uint8 LucNoOfByte;

  while (((uint8)IPDUM_ZERO) != LucNoOfSegmentBitField)
  {
    /* Get the pointer to Source Buffer */
    LpIpduMSourceBuffer = &LpSduPtr[LpSegmentBitField->ucSourceOffSet];

    /* Get the pointer to IpduMDestination Buffer */
    LpIpduMDestBuffer = LpSegmentBitField->pIpduMDestBuffer;

    /* Get the data in a local register */
    LucSourceData = *LpIpduMSourceBuffer;

    /* Get the value by applying start mask */
    LucSourceData &= LpSegmentBitField->ucSourceStartMask;

    /* Enter critical area */
    SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA();

    /* Get the data into local variable */
    LucDestData = *LpIpduMDestBuffer;

    /*   MISRA Rule       : 12.7
     *   Message          : Bitwise operations on signed data
     *   Reason           : An Bitwise operations on signed data will
     *                      give implementation defined results.
     *   Verification     : However, part of the code
     *                      is verified manually and
     *                      it is not having any impact.
   */

    /* Clear the position */
    LucDestData &= (uint8)(~(LpSegmentBitField->ucSourceStartMask));

    /* Copy the source data to destination variable */
    LucDestData |= LucSourceData;

    /* Copy the data to destination pointer */
    *LpIpduMDestBuffer = LucDestData;

    /* Exit critical area */
    SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA();

    /* Get the number of data byte that needs to be copied */
    LucNoOfByte = LpSegmentBitField->ucNoOfByte - ((uint8)IPDUM_ONE);

    /* Check whether number of byte is equal to zero */
    if (((uint8)IPDUM_ZERO) != LucNoOfByte)
    {
      /* Increment Source Buffer pointer */

      /*   MISRA Rule         : 17.4
       *   Message            : Performing pointer arithmetic
       *   Reason             : Increment operator not used
       *                        to achieve better throughput.
       *   Verification       : However, part of the code
       *                        is verified manually and
       *                        it is not having any impact.
       */
      ++LpIpduMSourceBuffer;

      /* Increment Destination Buffer pointer */

      /*   MISRA Rule         : 17.4
       *   Message            : Performing pointer arithmetic
       *   Reason             : Increment operator not used
       *                        to achieve better throughput.
       *   Verification       : However, part of the code
       *                        is verified manually and
       *                        it is not having any impact.
       */
      ++LpIpduMDestBuffer;

      /* Enter critical area */
      SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA();
      while (((uint8)IPDUM_ONE) != LucNoOfByte)
      {
        /* Copy the data into destination buffer from source buffer */
        *LpIpduMDestBuffer = *LpIpduMSourceBuffer;

        /* Increment Source Buffer pointer */

        /*   MISRA Rule         : 17.4
         *   Message            : Performing pointer arithmetic
         *   Reason             : Increment operator not used
         *                        to achieve better throughput.
         *   Verification       : However, part of the code
         *                        is verified manually and
         *                        it is not having any impact.
         */
        ++LpIpduMSourceBuffer;

        /* Increment Destination Buffer Pointer */

        /*   MISRA Rule         : 17.4
         *   Message            : Performing pointer arithmetic
         *   Reason             : Increment operator not used
         *                        to achieve better throughput.
         *   Verification       : However, part of the code
         *                        is verified manually and
         *                        it is not having any impact.
         */
        ++LpIpduMDestBuffer;

        /* Decrement count by one */
        --LucNoOfByte;
      }

      /* Get the Source Buffer data into local variable */
      LucSourceData = *LpIpduMSourceBuffer;

      /* Get the End Mask value into local register */
      LucSourceData &= LpSegmentBitField->ucSourceEndMask;

      /* Get the data into local variable */
      LucDestData = *LpIpduMDestBuffer;

      /*   MISRA Rule         : 12.7
       *   Message            : Bitwise operations on signed data
       *   Reason             : An Bitwise operations on signed data will
       *                        give implementation defined results.
       *   Verification       : However, part of the code
       *                        is verified manually and
       *                        it is not having any impact.
       */

      /* Clear the bit position */
      LucDestData &= (uint8)(~(LpSegmentBitField->ucSourceEndMask));

      /* Copy the data */
      LucDestData |= LucSourceData;

      /* Copy the data to destination pointer */
      *LpIpduMDestBuffer = LucDestData;

      /* Exit critical area */
      SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA();
    }                             /* End of if(LucNoOfByte !=
                                 *((uint8)IPDUM_ZERO)) */

    /* Increment LpSegmentBitField structure */
    /*
     *   MISRA Rule         : 17.4
     *   Message            : Performing pointer arithmetic
     *   Reason             : Increment operator not used
     *                        to achieve better throughput.
     *   Verification       : However, part of the code
     *                        is verified manually and
     *                        it is not having any impact.
     */
    ++LpSegmentBitField;

    /* Decrement LucNoOfSegmentBitField by one */
    --LucNoOfSegmentBitField;
  }
}                                 /* End of IpduM_CopySegmentBit( */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON)*/
/*******************************************************************************
** Function Name        : IpduM_CopySegmentByte                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function copy the data from source I-PDU to    **
**                        destination I-PDU byet by byte                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU                       **
**                                                                            **
** Input Parameters     : LpDestBuffer, LpSduPointer                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    :                            **
**                        SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA(),       **
**                        SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA()         **
*******************************************************************************/
#if (IPDUM_SEGMENT_BITFIELD == STD_OFF)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_CopySegmentByte(P2CONST(IpduM_TxInIpdu, AUTOMATIC,
    IPDUM_CONST) LpTxInIpdu, P2CONST(
    PduInfoType, AUTOMATIC, IPDUM_CONST) LpSduPointer)
{
  P2CONST(uint8, AUTOMATIC, IPDUM_CONST) LpIpduMSrcBufer;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) LpIpduMDstBufer;

  /*Local variable for pdu length */
  PduLengthType LucPduLength;
  
  /* Get the pointer to Source Buffer */
  LpIpduMSrcBufer = LpSduPointer->SduDataPtr + LpTxInIpdu->ucSourceOffset;

  /* Get the pointer to IpduMDestination Buffer */
  LpIpduMDstBufer = LpTxInIpdu->pIpduMDestBuffer;

  /* Get the length of pdu */
  LucPduLength = LpTxInIpdu->ucPduLength;

  while (((uint8)IPDUM_ZERO) != LucPduLength)
  {
    SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA();

    /* Copy the data into destination buffer from source buffer */
    *LpIpduMDstBufer = *LpIpduMSrcBufer;

    /* Increment Source Buffer pointer */

    /*   MISRA Rule         : 17.4
     *   Message            : Performing pointer arithmetic
     *   Reason             : Increment operator not used
     *                        to achieve better throughput.
     *   Verification       : However, part of the code
     *                        is verified manually and
     *                        it is not having any impact.
     */
    SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA();
    ++LpIpduMSrcBufer;

    /* Increment Destination Buffer Pointer */

    /*   MISRA Rule         : 17.4
     *   Message            : Performing pointer arithmetic
     *   Reason             : Increment operator not used
     *                        to achieve better throughput.
     *   Verification       : However, part of the code
     *                        is verified manually and
     *                        it is not having any impact.
     */
    ++LpIpduMDstBufer;
    LucPduLength--;
  }
}                                 /* End of IpduM_CopySegmentByte( */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*#if (IPDUM_SEGMENT_BITFIELD == STD_OFF)*/
/*******************************************************************************
** Function Name        : IpduM_GetSelBitField                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function extracts the selector field value     **
**                        from an I-PDU.                                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU                       **
**                                                                            **
** Input Parameters     : LpSelBitField and LpDestBuffer                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LucSelBitValue                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/

#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, IPDUM_CODE) IpduM_GetSelBitField(P2CONST(IpduM_SelBitField,
    AUTOMATIC,
    IPDUM_CONST) LpSelBitField, P2CONST(
    uint8, AUTOMATIC, IPDUM_CONST) LpDestBuffer)
{
  uint8 LucSelBitValue;

  /* Get the pointer to selector bit field buffer */
  LpDestBuffer = LpDestBuffer + ((IpduM_PtrType)(LpSelBitField->ucOffSetValue));

  /* Get the value into local variable */
  LucSelBitValue = *LpDestBuffer;

  /* Remove unnecessary data from the selector field */
  LucSelBitValue &= LpSelBitField->ucStartMask;

  /* Shift the value to make it byte aligned */
  LucSelBitValue >>= LpSelBitField->ucNoOfShiftBits;

  /* Return Selector bit value */
  return (LucSelBitValue);
}                                 /* End of IpduM_GetSelBitField( */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : IpduM_BinarySearch                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function searches the given selector value in  **
**                        the existing list.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpIpdu, LucSize and LucSelectorValue                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : *LpIpduRetVal                                       **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if (IPDUM_BINARY_SEARCH == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST),
  IPDUM_CODE) IpduM_BinarySearch(P2CONST(IpduM_RxPduSegmentBitField,
    AUTOMATIC, IPDUM_CONST) LpIpdu, uint8 LucSize, uint8 LucSelectorValue)
{
  /* Local Structure to return the structure parameters*/
  P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST) LpIpduRetVal;
  uint8 LucSelBitField;
  uint8 LucLow;
  uint8 LucHigh;
  uint8 LucMid;

  /* Initialize LucHigh variable with number of List I-PDUs - 1 */
  LucHigh = LucSize - ((uint8)IPDUM_ONE);

  /* Initialize LucLow variable with one */
  LucLow = (uint8)IPDUM_ONE;

  /* Initialize return value with null pointer */
  LpIpduRetVal = NULL_PTR;

  /* Get the lower limit of Selector Bit Field Value */
  LucSelBitField = (LpIpdu->ucSelectorValue);

  /* Check whether search Selector Bit Field Value is in range */
  if ((LucSelectorValue >= LucSelBitField) &&
      (LucSelectorValue <= (LpIpdu[LucHigh].ucSelectorValue)))
  {
    /* Check whether requested Selector Bit Field Value is same as first
     *   Selector Bit Field Value of the list */
    if (LucSelectorValue != LucSelBitField)
    {
      do
      {
        /* Get the middle index number */
        LucMid = (LucHigh + LucLow) >> IPDUM_ONE;

        /* Get the Selector Bit Field Value of the mid Rx L-PDU */
        LucSelBitField = (LpIpdu[LucMid].ucSelectorValue);

        /* Compare Selector Bit Field Value with the requested one */
        if (LucSelBitField == LucSelectorValue)
        {
          /* Update the return pointer with the Rx L-PDU structure */
          LpIpduRetVal = &LpIpdu[LucMid];

          /* Set LucHigh to zero to break the loop */
          LucHigh = ((uint8)IPDUM_ZERO);
        }                         /* End of if(LucSelBitField ==
                                   *LucSelectorValue) */
        else
        {
          /* Compare the Selector Bit Field Value with the requested one */
          if (LucSelectorValue < LucSelBitField)
          {
            /*
             * If the priority is lower, update LucHigh
             * Get the pointer to selector bit field buffer
             */

            /* MISRA Rule   : 21.1
             * Message      : An integer expression with a value that is
             *                apparently negative is being converted to an
             *                unsigned type
             * Reason       : Value of LucMid will not be zero.
             * Verification : However, part of the code is verified manually and
             *                it is not having any impact.
             */
            LucHigh = LucMid - ((uint8)IPDUM_ONE);
          }                       /* End of if(LucSelectorValue <LucSelBitField)
                                   **/
          else
          {
            /* If the priority is higher, update LucLow */
            LucLow = LucMid + IPDUM_ONE;
          }
        }                         /* End of else */
      } while (LucLow <= LucHigh);
    }                             /* if(LucSelectorValue != LucSelBitField) */
    else
    {
      /* Update the return pointer with the actual Rx L-PDU structure */
      LpIpduRetVal = LpIpdu;
    }
  }                               /*
                                   * if(LucSelBitField != LucSelectorValue)
                                   * Return RxLpduRetVal pointer
                                   */
  return (LpIpduRetVal);
}                        /* End of
                         *IpduM_BinarySearch(P2CONST(IpduM_RxPduSegmentBitField,
                         **/

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (IPDUM_BINARY_SEARCH == STD_ON) */

/*******************************************************************************
** Function Name        : IpduM_LinearSearch                                  **
**                                                                            **
** Service ID           : Not applicable                                      **
**                                                                            **
** Description          : This function searches the given selector value in  **
**                        the existing list.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Reentrant but not for same Ipdu                     **
**                                                                            **
** Input Parameters     : LpIpdu, LucSize, LucSelectorValue                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : *LpIpduRetVal                                       **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if (IPDUM_LINEAR_SEARCH == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST),
  IPDUM_CODE) IpduM_LinearSearch(P2CONST(IpduM_RxPduSegmentBitField,
    AUTOMATIC, IPDUM_CONST) LpRxIpdu, uint8 LucSize, uint8 LucSelectorVal)
{
  /* Local Structure to return the structure parameters*/
  P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST) LpIpduReturnVal;
  LpIpduReturnVal = (IpduM_RxPduSegmentBitField*) NULL_PTR;

  /*Loop all the Rx L-PDUs for the requested CAN ID. */
  do
  {
    /* If the Selector Bit Field Value is found in database,
     *   >> set the flag
     *   >> break the loop
     */
    if (LpRxIpdu->ucSelectorValue == LucSelectorVal)
    {
      LpIpduReturnVal = LpRxIpdu;

      /* Set LucSize to zero to break the loop */
      LucSize = ((uint8)IPDUM_ONE);
    }                             /* End of if(LpRxIpdu->LucSelectorValue ==
                                   *ucSelectorVal) */

    /* Increment Rx L-PDU structure */

    /*   MISRA Rule         : 17.4
     *   Message            : Performing pointer arithmetic
     *   Reason             : Increment operator not used
     *                        to achieve better throughput.
     *   Verification       : However, part of the code
     *                        is verified manually and
     *                        it is not having any impact.
     */
    LpRxIpdu++;

    /* Decrement the size */
    LucSize--;
  } while (((uint8)IPDUM_ZERO) != LucSize);

  /* Return LpRxIpdu pointer */
  return (LpIpduReturnVal);
}                        /* End of
                         *IpduM_LinearSearch(P2CONST(IpduM_RxPduSegmentBitField,
                         **/

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (IPDUM_LINEAR_SEARCH == STD_ON) */

#endif /*#if (IPDUM_ENABLE == STD_ON)*/
/* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Not a defect, Decrement and Increment operator is used to achieve better throughput */
/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<MISRA-C3:17.8:Not a defect:Unset> operation do working correctly */ 
/* polyspace:end<MISRA-C3:18.1:Not a defect:Justify with annotations> Pointer is not outside its bounds - Pointer is generated by Generator*/
/* polyspace:end<MISRA-C3:20.7:Not a defect:Justify with annotations> No Impact of this rule violation*/
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

