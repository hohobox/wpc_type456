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
**  SRC-MODULE: IoHwAb_DigInMC33972.h                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs                     **
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
** 1.15.0.2  09-Sep-2021   Yangjin        #31974                              **
** 1.8.1     08-May-2020   Yangjin        #23096                              **
** 1.0.2     26-Jul-2016   Jongyoung      #5219                               **
*******************************************************************************/

#ifndef IOHWAB_DIGINMC33972_H
#define IOHWAB_DIGINMC33972_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

/*******************************************************************************
**                      Global Data Constants                                 **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.5 [Justified:Low] "whether this macro is used depends on the configurations." */
#define SWITCH_STATUS_CMD                   0x00U
#define SETTINGS_CMD                        0x01U
#define WAKEUP_BIT_SP                       0x02U
#define WAKEUP_BIT_SG                       0x03U
#define METALLIC_CMD_SP                     0x04U
#define METALLIC_CMD_SG                     0x05U
#define ANALOG_CMD                          0x06U
#define WETTING_CURRENT_TIMER_CMD_SP        0x07U
#define WETTING_CURRENT_TIMER_CMD_SG        0x08U
#define TRI_STATE_CMD_SP                    0x09U
#define TRI_STATE_CMD_SG                    0x0AU
#define CALIBRATION_CMD                     0x0BU
#define SLEEP_CMD                           0x0CU
#define RESET_CMD                           0x7FU

#define ALL_BIT_CLEAR                       0x00U
#define ICU_NOT_USED_CHANNEL                0xFFU
/* polyspace-end MISRA-C3:2.5 [Justified:Low] "whether this macro is used depends on the configurations." */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IOHWAB_USE_DIG_IN == STD_ON)
#if (IOHWAB_USE_MC33972 == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_DigInMC33972Init(void);
extern FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_DigInMC33972Acq(void);
extern FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_DigInMC33972L2H(void);
extern FUNC(Std_ReturnType, IOHWAB_CODE)IoHwAb_DigInMC33972H2L(void);
extern FUNC(void, IOHWAB_CODE)IoHwAb_DigInMC33972IntermediateWakeUp(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_MC33972 == STD_ON) */
#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */

#endif /* IOHWAB_DIGINMC33972_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

