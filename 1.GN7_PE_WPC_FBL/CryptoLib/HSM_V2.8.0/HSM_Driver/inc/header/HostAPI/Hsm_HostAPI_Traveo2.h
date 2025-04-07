#ifndef HSM_HOSTAPI_TV2_H_
#define HSM_HOSTAPI_TV2_H_

#include "Hsm_Types.h"

#define OMEN_BANKINFO_TYPE_A        (0xD3ADFA11UL)
#define OMEN_BANKINFO_TYPE_B        (0x2E130DA7UL)

Std_ReturnType HSM_SetHsmHandlerIrqN(UINT8 irqN);
Std_ReturnType HSM_Sleep(void);
Std_ReturnType HSM_Wakeup(void);
Std_ReturnType HSM_SetWakeupTrigger(const UINT16 *list, UINT16 idxNum);
Std_ReturnType HSM_ClearWakeupTrigger(void);
BOOL HSM_IsSleepStatus(void);

Std_ReturnType HSM_RegSetConfigRegulator(UINT32 *sromApiResult, UINT32 regArg1, UINT32 regArg2);
Std_ReturnType HSM_RegSetSwitchOverRegulator(UINT32 *sromApiResult, UINT32 regArg1);
Std_ReturnType HSM_RegSetLoadRegulatorTrim(UINT32 *sromApiResult, UINT32 regArg1);

Std_ReturnType HSM_RegSet32Bit(UINT32 regAddr, UINT32 regValue);
Std_ReturnType HSM_RegGet32Bit(UINT32 *regValue, UINT32 regAddr);


/*      internal purpose only       */
Std_ReturnType HSM_BbmSetNextBootActiveBank(HSMAPI_OBJ_t *apiObj, UINT32 bankType);
Std_ReturnType HSM_BbmGetNextBootActiveBank(HSMAPI_OBJ_t *apiObj, UINT32 *bankType);


#endif
