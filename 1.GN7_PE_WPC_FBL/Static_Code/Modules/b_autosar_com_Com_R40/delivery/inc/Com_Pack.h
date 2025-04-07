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
**  SRC-MODULE: Com_Pack.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of pack functions.                   **
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
** 2.5.1     10-Sep-2020   SM Kwon     Internal Redmine #23914                **
** 2.4.0     29-Jan-2019   SM Kwon     Internal Redmine #14067                **
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7709, #7525          **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.17    27-Feb-2015   Chan Kim    Internal Redmine #2271                 **
** 1.0.11    03-Mar-2014   Chan Kim    Internal Redmine #642                  **
** 1.0.0     29-Apr-2013   AUTOEVER    Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef COM_PACK_H
#define COM_PACK_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_PACK_AR_RELEASE_MAJOR_VERSION  4
#define COM_PACK_AR_RELEASE_MINOR_VERSION  0
#define COM_PACK_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_PACK_SW_MAJOR_VERSION  2
#define COM_PACK_SW_MINOR_VERSION  9

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
extern FUNC(void, COM_CODE) Com_PackOneByte
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackBytes
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackFiveBytes
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackEightBytes
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackEightByteOrdering
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackNineBytes
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackNineByteOrdering
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackByteOrdering
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackFiveByteOrdering
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_PackNBytes
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Pack16bit
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Pack32bit
                 (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                       P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Write_8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
                P2VAR(void, AUTOMATIC, COM_VAR) LpDest, PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Write_16
  (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
  P2VAR(void, AUTOMATIC, COM_VAR) LpDest, PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Write_32
 (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
   P2VAR(void, AUTOMATIC, COM_VAR) LpDest, PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Write_64
 (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
  P2VAR(void, AUTOMATIC, COM_VAR) LpDest, PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Write_NBytes
  (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
   P2VAR(void, AUTOMATIC, COM_VAR) LpDest, PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_PackAndValidateSigGrp
(P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                      P2VAR (void, AUTOMATIC, COM_VAR) LpTargetDataPtr,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpMaskingDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_PackSigGrp
                      (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                      P2VAR (void, AUTOMATIC, COM_VAR) LpTargetDataPtr,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpMaskingDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"  

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_PackAndValidateSigGrpArray
(P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                      P2VAR (void, AUTOMATIC, COM_VAR) LpTargetDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"  

#if(COM_TX_SIGGROUP_ARR_GROUPSIG_TRIGONCHANGE == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_PackAndValidateGrpSigArray
(P2CONST(Com_TxSigGrp, AUTOMATIC, COM_CONST) LpTxSigGrp,
                      P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                      P2VAR (void, AUTOMATIC, COM_VAR) LpTargetDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_PackSigGrpArray
(P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
                      P2CONST (void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                      P2VAR (void, AUTOMATIC, COM_VAR) LpTargetDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"                

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Validate_NBytes
                           (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
                            P2VAR(void, AUTOMATIC, COM_VAR) LpTarget,
                            PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Validate_32
                           (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
                            P2VAR(void, AUTOMATIC, COM_VAR) LpTarget,
                            PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Validate_64
                           (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
                            P2VAR(void, AUTOMATIC, COM_VAR) LpTarget,
                            PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Validate_16
  (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
  P2VAR(void, AUTOMATIC, COM_VAR) LpTarget, PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_Validate_8
  (P2CONST(void, AUTOMATIC, COM_CONST) LpSource,
  P2VAR(void, AUTOMATIC, COM_VAR) LpTarget,
  PduLengthType LddSize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COM_PACK_H */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
