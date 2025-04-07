/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_GlobalDataDefinition.h                        **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file has extern declaration of global variables**
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
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
** 1.0.1     09-Feb-2018   Chan Kim    #11566                                 **
** 1.0.7     07-Dec-2020   SM Kwon     #25706                                 **
*******************************************************************************/
#ifndef COMXF_GLOBALDATADEFINITION_H
#define COMXF_GLOBALDATADEFINITION_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/

/*******************************************************************************
**                             Version Information                            **
*******************************************************************************/

/*******************************************************************************
**                              MACRO Definition                              **
*******************************************************************************/

/*******************************************************************************
**                              Type Definition                               **
*******************************************************************************/

/*******************************************************************************
**                         Global Variable Declaration                        **
*******************************************************************************/
/* polyspace-begin MISRA-C3:8.11 [Not a defect: Justified] "No Impact of this rule violation(Array size will fixed in linking time)" */

/* extern declaration for the global Initialization status variable */
#define COMXF_START_SEC_VAR_INIT_BOOLEAN
#include "ComXf_MemMap.h"
extern VAR(boolean, COMXF_VAR_INIT) ComXf_Gbl_InitStatus;
#define COMXF_STOP_SEC_VAR_INIT_BOOLEAN
#include "ComXf_MemMap.h"

#if(COMXF_PRECOMPILE_PACK_INFO_COUNT > COMXF_ZERO)
/* extern declaration for the global signal data packing variable */
#define COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"
extern CONST(ComXf_PackSigType, COMXF_CONST) ComXf_Kast_SigPackInfo[];
#define COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"
#endif

#if(COMXF_PRECOMPILE_UNPACK_INFO_COUNT > COMXF_ZERO)
/* extern declaration for the global signal data unpacking variable */
#define COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"
extern CONST(ComXf_UnPackSigType, COMXF_CONST) ComXf_Kast_SigUnPackInfo[];
#define COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComXf_MemMap.h"
#endif
/* polyspace-end MISRA-C3:8.11 [Not a defect: Justified] "No Impact of this rule violation(Array size will fixed in linking time)" */
/*******************************************************************************
**                           Function Declaration                             **
*******************************************************************************/

#endif /* COMXF_GLOBALDATADEFINITION_H */

/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
