/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Rx.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Header file of CanIf_Rx.c                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 3.2.0    17-Jan-2025    Jh.Yang   #49837                                   **
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.1    25-Nov-2020    Sj.Kim    #26002                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.2    15-May-2020    Sj.Kim    #23352, #21882, #23360                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384                                   **
** 2.5.5    10-Jan-2018    Js.Lim    #11197                                   **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 1.0.1    13-Jun-2016    Kt.Kim    #5139                                    **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

#ifndef CANIF_RX_H
#define CANIF_RX_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Cbk.h"           /* Call-back header file */
#include "CanIf_Ram.h"           /* Ram header file */
#include "CanIf_PCTypes.h"       /* Pre-compile time header file */
#include "CanSM_Cbk.h"           /* CAN State Manager call back header file */
#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"          /* Call-back PduR header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"           /* Call-back CanTp header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"           /* Call-back CanNm header file */
#endif
#include "SchM_CanIf.h"          /* SchM CanIf Header file */
#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "CanIf_Error.h"         /* DET header file */
#endif
#if (STD_ON == CANIF_AUTOEVER_CANTRCV_SUPPORT)
#include "CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_EXTENAL_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"            /* CanTrcv header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_RX_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_RX_AR_RELEASE_MINOR_VERSION       0
#define CANIF_RX_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_RX_SW_MAJOR_VERSION    3
#define CANIF_RX_SW_MINOR_VERSION    2
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#endif  /*CANIF_RX_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
