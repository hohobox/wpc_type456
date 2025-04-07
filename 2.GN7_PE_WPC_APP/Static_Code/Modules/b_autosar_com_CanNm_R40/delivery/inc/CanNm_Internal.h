/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanNm_Internal.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : Provision for CanNm Internal Function Header                  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date        By                Description                        **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

#ifndef CANNM_INTERNAL_H
#define CANNM_INTERNAL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_Ram.h"            /* CanNm RAM Header File */
#include "CanNm_PCTypes.h"        /* CanNm configuration header */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_INTERNAL_AR_RELEASE_MAJOR_VERSION         4
#define CANNM_INTERNAL_AR_RELEASE_MINOR_VERSION         0
#define CANNM_INTERNAL_AR_RELEASE_REVISION_VERSION      3

/* CANNM software version information */
#define CANNM_INTERNAL_SW_MAJOR_VERSION            2
#define CANNM_INTERNAL_SW_MINOR_VERSION            5
#define CANNM_INTERNAL_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Macroes                                               **
*******************************************************************************/

/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */

#ifndef P2P2VAR
#define P2P2VAR(ptrtype, memclass, ptrclass) ptrtype **
#endif

#ifndef P2P2CONST
#define P2P2CONST(ptrtype, memclass, ptrclass) const ptrtype **
#endif

/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define CANNM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANNM_CODE) CanNm_IntCollectTxData(uint32 LulCanNmChannelIndex);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntGetChannelIndexFromTransmitHandleId
  (PduIdType CanNmTransmitHandleId, P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntGetChannelIndexFromNmHandleId
  (NetworkHandleType NmHandleId, P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex);

extern FUNC(void, CANNM_CODE) CanNm_IntUpdateERA
  (uint32 LulCanNmChannelIndex, P2CONST(uint8, AUTOMATIC, CANNM_CONST) LaaPnInfo);

extern FUNC(void, CANNM_CODE) CanNm_IntUpdateEIRA
  (uint32 LulCanNmChannelIndex, P2CONST(uint8, AUTOMATIC, CANNM_CONST) LaaPnInfo);

extern FUNC(void, CANNM_CODE) CanNm_IntRequestBusSleepMode(uint32 LulCanNmChannelIndex);

extern FUNC(void, CANNM_CODE) CanNm_IntRequestPrepareBusSleepMode(uint32 LulCanNmChannelIndex);

extern FUNC(void, CANNM_CODE) CanNm_IntRequestReadySleepState(uint32 LulCanNmChannelIndex);

extern FUNC(void, CANNM_CODE) CanNm_IntRequestNormalOperationState(uint32 LulCanNmChannelIndex);

extern FUNC(void, CANNM_CODE) CanNm_IntRequestRepeatMessageState(uint32 LulCanNmChannelIndex);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntTransmit(uint32 LulCanNmChannelIndex);

extern FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntCanIfTransmit
  (uint32 LulCanNmChannelIndex);

extern FUNC(void, CANNM_CODE) CanNm_IntDetReportError
  (uint16 ModuleId, uint8 InstanceId, CANNM_SERVICE_ID ApiId, CANNM_ERROR_CODE ErrorId);

extern FUNC(boolean, CANNM_CODE) CanNm_IntNmPduTxEnabled(uint32 LulCanNmChannelIndex);

#define CANNM_STOP_SEC_CODE
#include "MemMap.h"



#endif /* CANNM_INTERNAL_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
