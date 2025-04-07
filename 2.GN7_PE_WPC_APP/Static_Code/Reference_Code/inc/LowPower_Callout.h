/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
#ifndef LOWPOWER_CALLOUT_H
#define LOWPOWER_CALLOUT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

#include "EcuM.h"
#include "SchM_EcuM.h"

#include "Icu.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define ECUM_WKSOURCE_NONE        0x00000000U

extern CONSTP2VAR(volatile Mcu_Cm4ScsRegType, AUTOMATIC, REGSPACE) EcuM_Cm4ScsRegBaseAddr;

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

FUNC(void, ECUM_CALLOUT_CODE) EcuM_H2LTransition_Callout_App(void);

FUNC(void, ECUM_CALLOUT_CODE) EcuM_H2LTransition_Callout_Swp(void);

FUNC(void, ECUM_CALLOUT_CODE) EcuM_L2HTransition_Callout_App(void);

FUNC(void, ECUM_CALLOUT_CODE) EcuM_L2HTransition_Callout_Swp(void);

FUNC(void, ECUM_CALLOUT_CODE) EcuM_Boot_Callout(void);

FUNC(void, ECUM_CALLOUT_CODE) IcuChannel_IGN1_Cbk(void);

FUNC(void, ECUM_CALLOUT_CODE) IcuChannel_BCAN_RX_Cbk(void);

FUNC(void, ECUM_CALLOUT_CODE) IcuChannel_LCAN_RX_Cbk(void);

void gs_EVTGEN_Active(void); // WPC_3F_02

#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
