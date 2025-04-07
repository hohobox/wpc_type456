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
**  SRC-MODULE: Com_Invalid.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of Invalid functions.                **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.4.0     01-Feb-2019   SM Kwon     Internal Redmine #13931, #14067, #14469**
**                                     #14641, #14789, #15053, #15832         **
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7525                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 1.0.11    03-Mar-2014   Chan Kim    Internal Redmine #642                  **
** 1.0.0     29-Apr-2013   AUTOEVER    Initial Version                        **
*******************************************************************************/

#ifndef COM_INVALID_H
#define COM_INVALID_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_INVALID_AR_RELEASE_MAJOR_VERSION  4
#define COM_INVALID_AR_RELEASE_MINOR_VERSION  0
#define COM_INVALID_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_INVALID_SW_MAJOR_VERSION  2
#define COM_INVALID_SW_MINOR_VERSION  9

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**          Function Prototypes for Tx Signal                                 **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Invalid_8
          (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
           P2CONST(void, AUTOMATIC, COM_CONST) LpTarget, 
           PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Invalid_16
          (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
           P2CONST(void, AUTOMATIC, COM_CONST) LpTarget, 
           PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Invalid_32
          (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
           P2CONST(void, AUTOMATIC, COM_CONST) LpTarget, 
           PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Invalid_64
          (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
           P2CONST(void, AUTOMATIC, COM_CONST) LpTarget, 
           PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Invalid_NBytes
          (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
           P2CONST(void, AUTOMATIC, COM_CONST) LpTarget, 
           PduLengthType LddSize);

#define COM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COM_INVALID_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
