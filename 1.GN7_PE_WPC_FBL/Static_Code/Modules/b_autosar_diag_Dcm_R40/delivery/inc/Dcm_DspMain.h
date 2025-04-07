/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspMain.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspMain                                      **
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
** 2.5.1.0   12-Aug-2020   LanhLT         Fix UNECE #35929                    **
**                                                                            **
** 2.3.2.0   05-Nov-2020   EunKyung Kim    #26432                             **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSPMAIN_H
#define DCM_DSPMAIN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* To update page */

extern FUNC(void, DCM_CODE) Dcm_DspUpdatePage(
  Dcm_MsgType PageBufPtr, Dcm_MsgLenType PageLen);

/* To process update page */
extern FUNC(void, DCM_CODE) Dcm_DspProcessUpdatePage(void);

extern FUNC(void, DCM_CODE) Dcm_DspCancelPagedBufferProcessing(void);
#endif
/* To provide confirmation */
extern FUNC(void, DCM_CODE) DspInternal_DcmConfirmation(
  Dcm_IdContextType LucIdContext, PduIdType LucDcmRxPduId,
  Dcm_ConfirmationStatusType LucStatus);
 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPMAIN_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
