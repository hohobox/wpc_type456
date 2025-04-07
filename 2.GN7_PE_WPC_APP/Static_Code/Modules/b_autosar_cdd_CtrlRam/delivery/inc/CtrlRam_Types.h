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
**  SRC-MODULE: CtrlRam_Types.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CtrlRam Module                                        **
**                                                                            **
**  PURPOSE   : Watchdog Manager API Functionality                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By          Description                         **
********************************************************************************
** 1.0.8       04-Aug-2022  YH.Han        Redmine #36978                      **
** 1.0.0       25-Jan-2013                Initial version                     **
*******************************************************************************/

#ifndef CTRLRAM_TYPES_H
#define CTRLRAM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"                  /* Standard type header */
#include "Rte_CtrlRam.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define CTRLRAM_ONE     1

/*  TODO : Need to be Checked   */

typedef void(*T_PPROC_FAR)(void);

/* MACROS for Platform Architecture */
#define BIG_ENDIAN_PLATFORM           0
#define LITTLE_ENDIAN_PLATFORM        1

#ifndef NULL
#define NULL 0
#endif

#define PRIVATE_DATA static              /* static data definition */
//
#define PRIVATE_FCT static               /* private function definition */

#define RESET   0
#define E_SWP_CTRLRAM 0x200
#endif /* CTRLRAM_TYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
