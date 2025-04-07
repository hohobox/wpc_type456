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
#ifndef NML_H
#define NML_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_Types.h"
#include "Nml_Cfg.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/



/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

extern void Nml_Init(void);
extern void Nml_Main(void);
extern void Nml_Shutdown(void);
extern Nml_ErrorType              Nml_GetError(void);
extern Nml_LogCMCRamDataType      Nml_GetCMCData(void);
extern Nml_LogRVCCMRamDataType    Nml_GetRVCCMData(void);
extern Nml_TimeType               Nml_GetEAETData(void);
extern void                       Nml_GetLCMData(Nml_LogLCMType *LcmData);
#define NML_STOP_SEC_CODE
#include "MemMap.h"

#endif /* NML_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
