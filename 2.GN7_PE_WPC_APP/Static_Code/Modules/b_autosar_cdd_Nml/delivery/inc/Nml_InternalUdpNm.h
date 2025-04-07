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
#ifndef NML_INTERNALUDPNM_H
#define NML_INTERNALUDPNM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nml_InternalIf.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Macro Definition                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define NML_START_SEC_VAR_CLEARED_8
#include "MemMap.h"


#define NML_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NML_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


#define NML_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define NML_START_SEC_CODE
#include "MemMap.h"

#if (STD_ON == NML_UDPNM_USED)
    extern void Nml_SetUdpNmChannelData(void);
    extern void Nml_GetUdpNmData(void);
    extern void Nml_ChkUdpNmState(void);
#endif /* #if (STD_ON == NML_UDPNM_USED) */


#define NML_STOP_SEC_CODE
#include "MemMap.h"


#endif /* NML_INTERNALUDPNM_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/