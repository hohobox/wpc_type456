/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Error.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : The file contains the Development Error Tracer code helping   **
**              to findout the error occurred within the CanIf module during  **
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
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.1    28-Dec-2021    Sj.Kim    #33378                                   **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.4    02-Apr-2021    Sj.Kim    #28280                                   **
** 2.7.1    25-Nov-2020    Sj.Kim    #26002                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.2    15-May-2020    Sj.Kim    #23352, #21882, #23360                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384                                   **
** 2.5.6    10-May-2018    Js.Lim    #12562                                   **
** 2.5.0    06-Dec-2016    Js.Lim    #7077                                    **
** 2.4.3    29-Nov-2016    Js.Lim    #6744                                    **
** 2.2.2    15-Mar-2016    Kt.Kim    #4386                                    **
** 2.2.1    13-Jun-2015    Kt.Kim    Improvement #2724                        **
** 2.2.0    02-Jul-2013    Kt.Kim    Lib-Build Support                        **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/
#ifndef CANIF_ERROR_H
#define CANIF_ERROR_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Cfg.h"                /* Configuration header file */
#include "CanIf_Types.h"              /* Header file for config Ptr type */
#include "CanIf.h"                    /* Header file for Fr Module */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_ERROR_AR_RELEASE_MAJOR_VERSION    ((uint8)4)
#define CANIF_ERROR_AR_RELEASE_MINOR_VERSION    ((uint8)0)
#define CANIF_ERROR_AR_RELEASE_REVISION_VERSION ((uint8)3)

/* Software Version Information */
#define CANIF_ERROR_SW_MAJOR_VERSION  ((uint8)3)
#define CANIF_ERROR_SW_MINOR_VERSION  ((uint8)2)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
/* This Error code is used when CanIf module is not initialized */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GlobalInitStatusError(
                          VAR(uint8, CANIF_VAR) ApiId);

/* This Error code is used when controller id has invalid Id */

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ControllerRangeError(
						  VAR(uint8, CANIF_VAR) ApiId, 
						  VAR(uint8, CANIF_VAR) ControllerId);


/* This Error code is used when controller Mode is invalid or out of defined
   values or CANIF_CS_UNINIT */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ControllerModeError(
						  VAR(uint8, CANIF_VAR) ApiId, 
#if (CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440)
	 VAR(Can_ControllerStateType, CANIF_VAR) ControllerMode);
#else
	 VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode);
#endif

#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
/* This Error code is used when Transceiver ID is not defined */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_InvalidTrcvIdError(
						  VAR(uint8, CANIF_VAR) ApiId, 
						  VAR(uint8, CANIF_VAR) TransceiverId);
#endif

/* This Error code is used when Transceiver ID is Invalid */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TrcvIdRangeError(
						   VAR(uint8, CANIF_VAR) ApiId, 
						   VAR(uint8, CANIF_VAR) TransceiverId);



/* This Error code is used when Pdu Mode is invalid */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_PduModeRequestError(
						   VAR(uint8, CANIF_VAR) ApiId, 
						   VAR(CanIf_PduSetModeType, CANIF_VAR) PduModeRequest);


/* This Error code is used TxPduId is out of range */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxIdRangeError(
						   VAR(uint8, CANIF_VAR) ApiId, 
						   VAR(PduIdType, CANIF_VAR) CanTxPduId);


/* This Error code is used Lpdu is out of range */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_LpduRangeError(
						   VAR(uint8, CANIF_VAR) ApiId, 
						   VAR(PduIdType, CANIF_VAR) CanTxPduId);

 #endif /* (STD_ON == CANIF_DEV_ERROR_DETECT) */
 
 #endif  /* CANIF_ERROR_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
