/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Det_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Development Error Tracer                              **
**                                                                            **
**  PURPOSE   : Global variable definitions                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.1     07-Mar-2013   Nitin Kumar     Global variable                    **
**                                         Det_GusErrorCount has been removed.**
**                                         has been removed.                  **
** 1.0.0     01-Jan-2013   Autron          Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Det.h"                  /* Header file of DET */
#include "Det_Ram.h"              /* Det Ram header file */

/* polyspace-begin MISRA-C3:20.1 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                      Global Types                                          **
*******************************************************************************/
#if (DET_RAM_BUFFER == STD_ON)
#define DET_START_SEC_VAR_NO_INIT_16
#include "MemMap.h"

/* Global variable used to store index of array of structure */
VAR(uint16, DET_VAR_NOINIT) Det_GusErrorsBuffIndex;
#define DET_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"
#endif

#if (DET_RAM_BUFFER == STD_ON)
#define DET_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Global array of structure to store the development error parameters */
VAR(Det_ErrorType, DET_VAR_POWER_ON_INIT) Det_GaaErrors[DET_RAM_BUFFER_SIZE];
#define DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#define DET_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store status of Det */
VAR(boolean, DET_VAR_POWER_ON_INIT) Det_GblInitStatus;
#define DET_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* polyspace-end MISRA-C3:20.1 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
