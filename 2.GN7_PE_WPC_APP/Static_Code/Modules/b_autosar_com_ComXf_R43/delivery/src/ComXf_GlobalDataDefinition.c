/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE:           ComXf_GlobalDataDefinition.c                        **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain definitions of all the global     **
**                        variables.                                          **
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
** 1.0.5     26-Feb-2019   SM Kwon     Redmine #16011                         **
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/
/* Include for ComXf.h */
#include "ComXf.h"
/* Include for ComXf_Macros.h */
#include "ComXf_Macros.h"
/* Redmine #16011: Include header files for the extern declaration of ComXf_Gbl_InitStatus*/
#include "ComXf_Types.h"
#include "ComXf_Cfg.h"
#include "ComXf_GlobalDataDefinition.h"
/*******************************************************************************
**                            Type Definition                                 **
*******************************************************************************/

/*******************************************************************************
**                        Global Variable Declaration                         **
*******************************************************************************/

#define COMXF_START_SEC_VAR_INIT_BOOLEAN
#include "ComXf_MemMap.h"
/* Definition of the global Initialization status variable */
VAR(boolean, COMXF_VAR_INIT) ComXf_Gbl_InitStatus = COMXF_CS_DEINIT;
#define COMXF_STOP_SEC_VAR_INIT_BOOLEAN
#include "ComXf_MemMap.h"

/*******************************************************************************
**                            Function Declaration                            **
*******************************************************************************/

/*******************************************************************************
**                            Version Check                                   **
*******************************************************************************/

/*******************************************************************************
**                            Version Check                                   **
*******************************************************************************/

/*******************************************************************************
**                           Function Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
