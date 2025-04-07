/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI MOTOR GROUP                                              **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: xxxxxxxxxxx.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Classic Platform Application                                  **
**                                                                            **
**  PURPOSE   : Log application for SWP                                       **
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
** X.X.X     DD-MM-YYYY    name.family name                                   **
** 0.0.1     29-Nov-2022    KC.Lim        xxxxxxxxxxxxxx                      **
*******************************************************************************/
#ifndef NML_LOG_H
#define NML_LOG_H



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == NML_USE)
extern void Nml_LogInit(void);
extern void Nml_LogFuncCMC(void);
extern void Nml_LogFuncRVCCM(uint8 chIndex, uint8 nmStateNotMatchedReason);
extern void Nml_LogFuncEAET(void);
extern void Nml_LogFuncLCM(uint8 chIndex);
void Nml_LogFuncWUSInternal(void);
#endif /* #if (STD_ON == NML_USE) */

/* stay function declaration for the convenience of Nml integration */
extern void Nml_LogFuncWUS(uint32 wakeupSource);

#define NML_STOP_SEC_CODE
#include "MemMap.h"

#endif /* NML_LOG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
