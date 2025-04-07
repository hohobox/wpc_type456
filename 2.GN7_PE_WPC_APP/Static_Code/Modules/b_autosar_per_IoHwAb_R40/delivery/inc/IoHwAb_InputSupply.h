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
**  SRC-MODULE: IoHwAb_InputSupply.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for Input Supply                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By         Description                             **
********************************************************************************
** 1.15.0.2  09-Sep-2021   Yangjin    #31974                                  **
** 1.0.1     22-Jul-2016   Jongyoung  #5219                                   **
*******************************************************************************/

#ifndef IOHWAB_INPUTSUPPLY_H
#define IOHWAB_INPUTSUPPLY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IOHWAB_USE_IN_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_InputSupplyInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#if (IOHWAB_USE_DIG_IN == STD_ON)
#if (IOHWAB_USE_DIG_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_InputSupplyDigitalControl(
  boolean blHp, boolean blOn);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_SUP_SWT == STD_ON) */
#endif /* (IOHWAB_USE_DIG_IN == STD_ON)*/

#if (IOHWAB_USE_ANA_IN == STD_ON)
#if (IOHWAB_USE_ANA_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_InputSupplyAnalogControl(boolean blOn);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_SUP_SWT == STD_ON) */
#endif /* (IOHWAB_USE_ANA_IN == STD_ON)*/

#endif /* (IOHWAB_USE_IN_SUP_SWT == STD_ON) */

#endif /* IOHWAB_INPUTSUPPLY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
