/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_CAN_RX_H
#define  App_CAN_RX_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

typedef enum
{
/* enum C_WPC_IndSyncVal */
	cIndSyncVal_Default,
	cIndSyncVal_Off,
	cIndSyncVal_1stSync,
	cIndSyncVal_2ndSync,
	cIndSyncVal_3rdSync,
	cIndSyncVal_ErrorOff,
	cIndSyncVal_ErrorOn,
	cIndSyncVal_Reserved
} WPCIndSynVal_STATE;


extern void gs_CAN_RX_L2H_Set(void);
extern void gs_CAN_RX_H2L_Set(void);


#endif
