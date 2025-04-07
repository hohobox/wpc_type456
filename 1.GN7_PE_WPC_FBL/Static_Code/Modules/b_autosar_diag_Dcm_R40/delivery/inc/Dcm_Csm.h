/*******************************************************************************
**                                                                            **
** (C) 2021 HYUNDAI AUTOEVER Corp.                                            **
** Confidential Proprietary Information. Distribution Limited.                **
** This source code is permitted to be used only in projects contracted       **
** with Hyundai Autoever, and any other use is prohibited.                    **
** If you use it for other purposes or change the source code,                **
** you may take legal responsibility.                                         **
** In this case, There is no warranty and technical support.                  **
**                                                                            **
**  SRC-MODULE: Dcm_Csm.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_Csm                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.7.0        25-Jul-2022     Suyon Kim    #40261                           **
**                                                                            **
** 2.6.0        21-Sep-2022     LanhLT       Initial Version                  **
*******************************************************************************/

#ifndef DCM_CSM_H
#define DCM_CSM_H

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if ((DCM_AUTHENTICATION_SUPPORT == STD_ON) && (DCM_AUTHENTICATION_ES_SUPPORT == STD_OFF))
#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_CsmAsyncJobFinished(
  Csm_ResultType Result);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*DCM_AUTHENTICATION_SUPPORT == STD_ON*/

#endif

/*******************************************************************************
**                                End of File                                 **
*******************************************************************************/
