/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf.h                                             **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file defines public function prototype.        **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
** 1.0.7     07-Dec-2020   SM Kwon     #25706                                 **
** 1.0.10    04-May-2021   PhucNHM     #28736                                 **
** 1.0.12    04-Jan-2022   SM Kwon     #33614                                 **
*******************************************************************************/
#ifndef COMXF_H
#define COMXF_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/
/* include Com Stack Types header file */
#include "ComStack_Types.h" 
/* include for TransformerTypes.h */
#include "TransformerTypes.h"
/* include for Rte_Type.h */
#include "Rte_Type.h"
/* include for ComXf_InternalAPIs.h */
#include "ComXf_APIs.h"
/* include for ComXf_Macros.h */
#include "ComXf_Macros.h"

/*******************************************************************************
**                             Version Information                            **
*******************************************************************************/
#define COMXF_AR_RELEASE_MAJOR_VERSION       4
#define COMXF_AR_RELEASE_MINOR_VERSION       3
#define COMXF_AR_RELEASE_REVISION_VERSION    0
#define COMXF_SW_MAJOR_VERSION               1
#define COMXF_SW_MINOR_VERSION               0
#define COMXF_SW_PATCH_VERSION               13

/*******************************************************************************
**                              MACRO Definition                              **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justified> use function like-macro for removing unused argument compiler warning */
#define COMXF_UNUSED(x)                           do { \
                                                    if((uint32)(x) != \
                                                    (uint32)COMXF_ZERO) {} \
                                                  } while(0)
  
/* polyspace<MISRA-C:19.7:Not a defect:Justified> use function like-macro for removing unused argument compiler warning */
#define COMXF_UNUSED_PTR(x)                       do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)

/*******************************************************************************
**                              Type Definition                               **
*******************************************************************************/
/* polyspace-begin MISRA-C3:D4.8 [Not a defect:Low] "No Impact of this rule violation" */
/* ComXf_ConfigType structure */
typedef struct 
{
  /* Unused variable created because of compilation issue */
  uint8 u8_UnUsed;

}ComXf_ConfigType;
/* polyspace-end MISRA-C3:D4.8 [Not a defect:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                         Global Variable Declaration                        **
*******************************************************************************/

/*******************************************************************************
**                           Function Declaration                             **
*******************************************************************************/
/* extern declaration of ComXf_Init */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_Init(
  P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_CONST) config);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_DeInit */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_DeInit(void);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/* extern declaration of ComXf_GetVersionInfo */
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_CODE) ComXf_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, COMXF_VAR) VersionInfo);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"


#endif /* COMXF_H */

/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
