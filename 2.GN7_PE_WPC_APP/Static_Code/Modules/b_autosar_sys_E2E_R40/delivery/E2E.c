/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: E2E.c                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR E2E Module                                            **
**                                                                            **
**  PURPOSE   : To provide function definitions of E2E                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date           By              Description                        **
********************************************************************************
** 1.2.5    09-Aug-2022    Seungjin Noh    Change made as per #36855          **
** 1.2.4    23-Dec-2021    Gongbin Lim     Change made as per #33551          **
** 1.2.3    22-Jul-2020    Gongbin Lim     Change made as per #24829          **
** 1.2.2    24-Oct-2018    Gongbin Lim     Change made as per #14435          **
** 1.2.1    18-Jun-2018    Gongbin Lim     Change made as per #12704          **
** 1.2.0    22-Mar-2018    Gongbin Lim     Changes made as per #11718         **
** 1.1.3    07-Dec-2016    Seongmin Kim    Changes made as per #6490 and #6886**
** 1.1.2    04-Oct-2016    Seongmin Kim    Change made as per #6159           **
** 1.1.0    05-Apr-2016    Hoi-Min Kim     Changes made as per #3554, #4296,  **
**                         Seongmin Kim      and #4342                        **
** 1.0.0    02-Jul-2013    Hoi-Min Kim     Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include for E2E External API's */
#include "E2E.h"

/* Include file for version information */
#include "E2E_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define E2E_C_AR_RELEASE_MAJOR_VERSION            (4)
#define E2E_C_AR_RELEASE_MINOR_VERSION            (2)
#define E2E_C_AR_RELEASE_REVISION_VERSION         (2)

/* FILE VERSION INFORMATION */
#define E2E_C_SW_MAJOR_VERSION                    (1)
#define E2E_C_SW_MINOR_VERSION                    (2)
#define E2E_C_SW_PATCH_VERSION                    (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (E2E_AR_RELEASE_MAJOR_VERSION != E2E_C_AR_RELEASE_MAJOR_VERSION)
#error "E2E.c : Mismatch in Specification Major Version"
#endif

#if (E2E_AR_RELEASE_MINOR_VERSION != E2E_C_AR_RELEASE_MINOR_VERSION)
#error "E2E.c : Mismatch in Specification Minor Version"
#endif

#if (E2E_AR_RELEASE_REVISION_VERSION != E2E_C_AR_RELEASE_REVISION_VERSION)
#error "E2E.c : Mismatch in Specification Revision Version"
#endif

#if (E2E_SW_MAJOR_VERSION != E2E_C_SW_MAJOR_VERSION)
#error "E2E.c : Mismatch in Major Version"
#endif

#if (E2E_SW_MINOR_VERSION != E2E_C_SW_MINOR_VERSION)
#error "E2E.c : Mismatch in Minor Version"
#endif

#if (E2E_SW_PATCH_VERSION != E2E_C_SW_PATCH_VERSION)
#error "E2E.c : Mismatch in Patch Version"
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define E2E_START_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
** Function Name        : E2E_GetVersionInfo                                  **
**                                                                            **
** Service ID           : 0x14                                                **
**                                                                            **
** Description          : This function returns the version information of E2E**
**                        Routines module.                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : VersionInfo                                         **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
FUNC(void, E2E_CODE) E2E_GetVersionInfo (
  P2VAR(Std_VersionInfoType, AUTOMATIC, E2E_APPL_DATA) VersionInfo)
{
  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Argument is passed from caller  */
  if (NULL_PTR != VersionInfo)
  {
    /* Copy the vendor Id */
	/* polyspace<MISRA2012:D4.14:Not a defect:Justify with annotations> Validity is checked from AUTOSAR SPEC  */
    VersionInfo->vendorID = E2E_VENDOR_ID;

    /* Copy the module Id */
    VersionInfo->moduleID = E2E_MODULE_ID;

    /* Copy Software Major Version */
    VersionInfo->sw_major_version = (uint8)E2E_SW_MAJOR_VERSION;

    /* Copy Software Minor Version */
    VersionInfo->sw_minor_version = (uint8)E2E_SW_MINOR_VERSION;

    /* Copy Software Patch Version */
    VersionInfo->sw_patch_version = (uint8)E2E_SW_PATCH_VERSION;
  } /* End of if (NULL_PTR != VersionInfo) */

  /*
   * If the received VersionInfo pointer is NULL and shall return from the
   * E2E_GetVersionInfo API without performing any further functionality.
   */
} /* End of E2E_GetVersionInfo (Std_VersionInfoType *VersionInfo) */

/*******************************************************************************
** Function Name        : E2E_UpdateCounter                                   **
**                                                                            **
** Service ID           : 0x13                                                **
**                                                                            **
** Description          : This function returns the incremented sequence      **
**                        counter value.                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Counter                                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : NA                         **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_UpdateCounter (VAR(uint8, AUTOMATIC) Counter)
{
  /*
   * Increment the counter value take modoulus of 15 so that after 0xE counter
   * value becomes 0x00
   */
  return ((uint8)((Counter + E2E_ONE) % E2E_CNT_LIMIT));
} /* End of E2E_UpdateCounter (uint8 Counter) */

/*******************************************************************************
** Function Name        : E2E_CRC8u8                                          **
**                                                                            **
** Service ID           : 0x07                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_Data, E2E_StartValue                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8u8 (P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8u8;

  LucCrcValue8u8 = Crc_CalculateCRC8 (
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_Data, E2E_CRC_LENGTH_ONE,
    E2E_StartValue, E2E_FALSE);

  return (LucCrcValue8u8);
} /* End of E2E_CRC8u8 (uint8 E2E_Data, uint8 E2E_StartValue) */

/*******************************************************************************
** Function Name        : E2E_CRC8u16                                         **
**                                                                            **
** Service ID           : 0x08                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_Data, E2E_StartValue                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8u16 (P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8u16;

  LucCrcValue8u16 = Crc_CalculateCRC8 (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_Data, E2E_CRC_LENGTH_TWO,
    E2E_StartValue, E2E_FALSE);

  return (LucCrcValue8u16);
} /* End of E2E_CRC8u16 (uint16 E2E_Data, uint8 E2E_StartValue) */

/*******************************************************************************
** Function Name        : E2E_CRC8u32                                         **
**                                                                            **
** Service ID           : 0x09                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_Data, E2E_StartValue                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8u32 (P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8u32;

  LucCrcValue8u32 = Crc_CalculateCRC8 (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_Data, E2E_CRC_LENGTH_FOUR,
    E2E_StartValue, E2E_FALSE);

  return (LucCrcValue8u32);
} /* End of E2E_CRC8u32 (uint32 E2E_Data, uint8 E2E_StartValue) */

/*******************************************************************************
** Function Name        : E2E_CRC8u8Array                                     **
**                                                                            **
** Service ID           : 0x0A                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_DataPtr, E2E_ArrayLength, E2E_StartValue        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8u8Array (
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8u8Array;

  LucCrcValue8u8Array = Crc_CalculateCRC8 (E2E_DataPtr, E2E_ArrayLength,
    E2E_StartValue, E2E_FALSE);

  return (LucCrcValue8u8Array);
} /* End of E2E_CRC8u8Array (
   * P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
   * uint32 E2E_ArrayLength, uint8 E2E_StartValue)
   */

/*******************************************************************************
** Function Name        : E2E_CRC8u16Array                                    **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_DataPtr, E2E_ArrayLength, E2E_StartValue        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8u16Array (
  P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8u16Array;

  LucCrcValue8u16Array = Crc_CalculateCRC8 (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments defined in the AUTOSAR Specification. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_DataPtr,
    (uint32)(E2E_ArrayLength * E2E_CRC_LENGTH_TWO), E2E_StartValue, E2E_FALSE);

  return (LucCrcValue8u16Array);
} /* End of E2E_CRC8u16Array (
   * P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
   * uint32 E2E_ArrayLength, uint8 E2E_StartValue)
   */

/*******************************************************************************
** Function Name        : E2E_CRC8u32Array                                    **
**                                                                            **
** Service ID           : 0x0C                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_DataPtr, E2E_ArrayLength, E2E_StartValue        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8          **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8u32Array (
  P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8u32Array;

  LucCrcValue8u32Array = Crc_CalculateCRC8 (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments defined in the AUTOSAR Specification. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_DataPtr,
    (uint32)(E2E_ArrayLength * E2E_CRC_LENGTH_FOUR), E2E_StartValue, E2E_FALSE);

  return (LucCrcValue8u32Array);
} /* End of E2E_CRC8u32Array (
   * P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
   * uint32 E2E_ArrayLength, uint8 E2E_StartValue)
   */

/*******************************************************************************
** Function Name        : E2E_CRC8H2Fu8                                       **
**                                                                            **
** Service ID           : 0x0D                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_Data, E2E_StartValue                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu8 (P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8H2Fu8;

  LucCrcValue8H2Fu8 = Crc_CalculateCRC8H2F (
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_Data, E2E_CRC_LENGTH_ONE,
    E2E_StartValue, E2E_TRUE);

  return (LucCrcValue8H2Fu8);
} /* End of E2E_CRC8H2Fu8 (uint8 E2E_Data, uint8 E2E_StartValue) */

/*******************************************************************************
** Function Name        : E2E_CRC8H2Fu16                                      **
**                                                                            **
** Service ID           : 0x0E                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_Data, E2E_StartValue                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu16 (P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8H2Fu16;

  LucCrcValue8H2Fu16 = Crc_CalculateCRC8H2F (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments defined in the AUTOSAR Specification. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_Data, E2E_CRC_LENGTH_TWO,
    E2E_StartValue, E2E_TRUE);

  return (LucCrcValue8H2Fu16);
} /* End of E2E_CRC8H2Fu16 (uint16 E2E_Data, uint8 E2E_StartValue) */

/*******************************************************************************
** Function Name        : E2E_CRC8H2Fu32                                      **
**                                                                            **
** Service ID           : 0x0F                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_Data, E2E_StartValue                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu32 (P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_Data,
  VAR(uint8, AUTOMATIC)  E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8H2Fu32;

  LucCrcValue8H2Fu32 = Crc_CalculateCRC8H2F (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments defined in the AUTOSAR Specification. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_Data, E2E_CRC_LENGTH_FOUR,
    E2E_StartValue, E2E_TRUE);

  return (LucCrcValue8H2Fu32);
} /* End of E2E_CRC8H2Fu32 (uint32 E2E_Data, uint8 E2E_StartValue) */

/*******************************************************************************
** Function Name        : E2E_CRC8H2Fu8Array                                  **
**                                                                            **
** Service ID           : 0x10                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_DataPtr, E2E_ArrayLength, E2E_StartValue        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu8Array (
  P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8H2Fu8Array;

  LucCrcValue8H2Fu8Array = Crc_CalculateCRC8H2F (E2E_DataPtr,
    E2E_ArrayLength, E2E_StartValue, E2E_TRUE);

  return (LucCrcValue8H2Fu8Array);
} /* End of E2E_CRC8H2Fu8Array (
   * P2CONST(uint8, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
   * uint32 E2E_ArrayLength, uint8 E2E_StartValue)
   */

/*******************************************************************************
** Function Name        : E2E_CRC8H2Fu16Array                                 **
**                                                                            **
** Service ID           : 0x11                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_DataPtr, E2E_ArrayLength, E2E_StartValue        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu16Array (
  P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8H2Fu16Array;

  LucCrcValue8H2Fu16Array = Crc_CalculateCRC8H2F (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments defined in the AUTOSAR Specification. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_DataPtr,
    (uint32)(E2E_ArrayLength * E2E_CRC_LENGTH_TWO), E2E_StartValue, E2E_TRUE);

  return (LucCrcValue8H2Fu16Array);
} /* End of E2E_CRC8H2Fu16Array (P2CONST(uint16, AUTOMATIC, E2E_APPL_CONST)
   * E2E_DataPtr, uint32 E2E_ArrayLength, uint8 E2E_StartValue)
   */

/*******************************************************************************
** Function Name        : E2E_CRC8H2Fu32Array                                 **
**                                                                            **
** Service ID           : 0x12                                                **
**                                                                            **
** Description          : This function returns uint8                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : E2E_DataPtr, E2E_ArrayLength, E2E_StartValue        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return Value         : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : Crc_CalculateCRC8H2F       **
*******************************************************************************/
FUNC(uint8, E2E_CODE) E2E_CRC8H2Fu32Array (
  P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST) E2E_DataPtr,
  VAR(uint32, AUTOMATIC) E2E_ArrayLength, VAR(uint8, AUTOMATIC) E2E_StartValue)
{
  VAR(uint8, AUTOMATIC) LucCrcValue8H2Fu32Array;

  LucCrcValue8H2Fu32Array = Crc_CalculateCRC8H2F (
/* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> Pointer casting is used for matching function arguments defined in the AUTOSAR Specification. */
    (P2CONST(uint8, AUTOMATIC, E2E_CONST)) E2E_DataPtr,
    (uint32)(E2E_ArrayLength * E2E_CRC_LENGTH_FOUR), E2E_StartValue, E2E_TRUE);

  return (LucCrcValue8H2Fu32Array);
} /* End of E2E_CRC8H2Fu32Array (
   * P2CONST(uint32, AUTOMATIC, E2E_APPL_CONST)
   * E2E_DataPtr, uint32 E2E_ArrayLength, uint8 E2E_StartValue)
   */

#define E2E_STOP_SEC_CODE
/* polyspace<MISRA2012:20.1:Not a defect:Justify with annotations> Memory Mapping is AUTOSAR Standard  */
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

