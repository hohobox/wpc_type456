/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : App_CtrlRam.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Sample code to an application user                            **
**                                                                            **
**  PURPOSE   : Provide an application user with callback function code       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 1.0.0      03-Feb-2017   Hyungho Lee   Initial Creation                    **
*******************************************************************************/

#include "CtrlRam.h"
#include "CtrlRam_Ram.h"           /* Module RAM header file */
#include "CtrlRam_Types.h"         /* Types header file */

#define CTRLRAM_START_SEC_CODE
#include "MemMap.h"
/* When Controlled Ram is cleared, CallBack Should be Invoked */
/* "CtrlRamConfigSet1_CB" is an example and can be changeable(or modified) by an user, based on CtrlRam block configuration */
void CtrlRamConfigSet1_CB(void)
{

}

#define CTRLRAM_STOP_SEC_CODE
#include "MemMap.h"
