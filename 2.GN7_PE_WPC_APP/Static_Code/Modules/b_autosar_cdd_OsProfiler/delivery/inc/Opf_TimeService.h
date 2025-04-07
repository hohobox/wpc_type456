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
**  SRC-MODULE: Opf_TimeService.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : OS Profiler                                                   **
**                                                                            **
**  PURPOSE   : Implementation of TimeService module                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.5.7.1   29-Jun-2022    HJ.Kim        CP44-390                            **
** 1.5.4     14-Dec-2021    YH.Han        Redmine #33448                      **
** 1.1.0     24-Nov-2016    SH.Yoo        Redmine #6755                       **
** 1.0.0     14-Jul-2016    SH.Yoo        Redmine #4024                       **
*******************************************************************************/

#ifndef OPF_TIMESERVICE_H
#define OPF_TIMESERVICE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Opf_Types.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
extern FUNC(OpfTickType, OPF_CODE) Opf_GetSystimeDiff(OpfTickType Ldd1stTick,
                                                        OpfTickType Ldd2ndTick);
extern FUNC(OpfTickType, OPF_CODE) Opf_GetSystimeSpan(void);
extern FUNC(OpfTickType, OPF_CODE) Opf_GetSavedSystimeSpan(void);
extern FUNC(OpfTickType, OPF_CODE) Opf_GetSavedSystime(void);
extern FUNC(void, OPF_CODE) Opf_SaveTimeStamp(void);

#endif /* OPF_TIMESERVICE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
