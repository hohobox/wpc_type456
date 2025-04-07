/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_WDT_H
#define  App_WDT_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

#define	cResetOpSta_Normal 			0u
#define	cResetOpSta_ResetComplete 	1u
#define	cResetOpSta_ResetFail 		2u
#define	cResetOpSta_RESERVED 		3u

#define	cResetPreWrng_NoWarning 	0u
#define	cResetPreWrng_Warning 		1u
#define	cResetPreWrng_RESERVED 	    2u
#define	cResetPreWrng_Invalid 		3u

#define	cResetReq_NoReq 			0u
#define	cResetReq_ResetReq 		    1u
#define	cResetReq_RESERVED 		    2u
#define	cResetReq_Invalid 			3u

#define	cPowerOffReq_OFF 			0u
#define	cPowerOffReq_ON_NonSleep 	1u
#define	cPowerOffReq_ON_NormalSleep 2u
#define	cPowerOffReq_Reserved 		3u


extern void gs_App_WDT_L2H_Set(void);
extern void gs_App_WDT_H2L_Set(void);


#endif
