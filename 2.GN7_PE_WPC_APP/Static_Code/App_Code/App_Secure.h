/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_ConfigLock_H
#define  App_ConfigLock_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

#define cSecure_Init 			0u
#define cSecure_BootEnable 		1u
#define cSecure_ConfigLock 		2u
#define cSecure_Ng 				3u

extern uint8_t gs_Get_SecureMode_State(void);


#endif
