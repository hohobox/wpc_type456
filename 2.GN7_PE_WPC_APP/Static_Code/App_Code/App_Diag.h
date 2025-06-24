/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_DIAG_H
#define  App_DIAG_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

#define cDiag_Disable 	0u
#define cDiag_Enable 	1u

#define cLED_DUTY_100		10000u	// 100 * 100
#define cLED_DUTY_0			0u		// 0 * 100

#define cFAN_DUTY_50		5000u	// 50 * 100
#define cFAN_DUTY_0			0u		// 0 * 100

extern void gs_Diag_L2H_Set(void);
extern void gs_Diag_H2L_Set(void);


#endif
