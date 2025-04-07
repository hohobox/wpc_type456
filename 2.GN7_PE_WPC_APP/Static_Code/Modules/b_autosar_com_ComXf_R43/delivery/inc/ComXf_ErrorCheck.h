/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE:           ComXf_ErrorCheck.h                                  **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file defines error macros definitions          **
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
** 1.0.2     13-Mar-2018   Chan Kim    #11951                                 **
** 1.0.4     13-Jul-2018   Chan Kim    #13396                                 **
** 1.0.7     07-Dec-2020   SM Kwon     #25706                                 **
*******************************************************************************/
#ifndef COMXF_ERRORCHECK_H
#define COMXF_ERRORCHECK_H

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/

/*******************************************************************************
**                             Version Information                            **
*******************************************************************************/

/*******************************************************************************
**                              Error Definitions                             **
*******************************************************************************/
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justified> No Impact of this rule violation) */

/* Error check for module initialization */
#define COMXF_MODULE_INIT_CHECK(Service_Id) \
  do \
  { \
    if((boolean) COMXF_CS_DEINIT == ComXf_Gbl_InitStatus) \
    { \
      (void)Det_ReportError(COMXF_MODULE_ID, COMXF_INSTANCE_ID, \
        (Service_Id), COMXF_E_UNINIT); \
      Lu8_ReturnStatus = (uint8) COMXF_E_SER_GENERIC_ERROR; \
    } \
  }while(0)

/* Error check for null pointer and buffer length check*/
#define COMXF_NULL_PTR_AND_BUFFERLENGTH_CHECK(Lu8_ReturnStatus, Argument1, \
  Argument2, Service_Id) \
  do \
  { \
    if(((uint8) E_OK == (Lu8_ReturnStatus)) && ((Argument1) == NULL_PTR) && \
      ((Argument2) == 0))\
    {\
      (void)Det_ReportError(COMXF_MODULE_ID, COMXF_INSTANCE_ID, \
        (Service_Id), COMXF_E_PARAM_POINTER); \
      (void)Det_ReportError(COMXF_MODULE_ID, COMXF_INSTANCE_ID, \
        (Service_Id), COMXF_E_PARAM); \
        (Lu8_ReturnStatus) = (uint8) COMXF_E_NO_DATA;\
    }\
  }while(0)
/* Error check for null pointer */
#define COMXF_NULL_POINTER_CHECK(Lu8_ReturnStatus, Argument, Service_Id) \
  do \
  { \
    if(((uint8) E_OK == (Lu8_ReturnStatus)) && ((Argument) == NULL_PTR)) \
    { \
      (void)Det_ReportError(COMXF_MODULE_ID, COMXF_INSTANCE_ID, \
        (Service_Id), COMXF_E_PARAM_POINTER); \
      (Lu8_ReturnStatus) = (uint8) COMXF_E_SER_GENERIC_ERROR; \
    } \
  }while(0)

/* Error check for buffer length */
#define COMXF_BUFFERLENGTH_CHECK(Lu8_ReturnStatus, Argument, Service_Id) \
  do \
  { \
    if(((uint8) E_OK == (Lu8_ReturnStatus)) && ((Argument) == 0)) \
    { \
      (void)Det_ReportError(COMXF_MODULE_ID, COMXF_INSTANCE_ID, \
        (Service_Id), COMXF_E_PARAM); \
      (Lu8_ReturnStatus) = (uint8) COMXF_E_SER_GENERIC_ERROR; \
    } \
  }while(0)

#define COMXF_GETVERSIONINFO_NULL_POINTER_CHECK( \
    Lu8_ReturnStatus, Argument, Service_Id) \
  do \
  { \
    if((VersionInfo == NULL_PTR)) \
    { \
      (void)Det_ReportError(COMXF_MODULE_ID, COMXF_INSTANCE_ID, \
      COMXF_GETVERSIONINFO_SERVICE_ID, COMXF_E_PARAM_POINTER); \
      (Lu8_ReturnStatus) = (uint8) COMXF_E_PARAM_POINTER; \
    } \
  }while(0)

/*******************************************************************************
**                              Type Definition                               **
*******************************************************************************/

/*******************************************************************************
**                         Global Variable Declaration                        **
*******************************************************************************/

/*******************************************************************************
**                             Function Declaration                           **
*******************************************************************************/

/* polyspace:end<MISRA-C:19.7:Not a defect:Justified> No Impact of this rule violation) */

#endif /* COMXF_ERRORCHECK_H */
/*******************************************************************************
**                                 End of file                                **
*******************************************************************************/
