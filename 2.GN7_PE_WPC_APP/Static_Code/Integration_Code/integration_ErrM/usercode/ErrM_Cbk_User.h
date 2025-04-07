


#ifndef ERRM_CBK_USER_H
#define ERRM_CBK_USER_H
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
//#include "Rte_SWC_ErrM.h"
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include "EcuInfo.h"

#if defined ( DEBUG_ErrM_Module_USE )

extern void gs_GetCpuLoad(void);

extern void gs_GetStackUsage(void);

extern void gs_GetOsError(void);

#endif

#endif
