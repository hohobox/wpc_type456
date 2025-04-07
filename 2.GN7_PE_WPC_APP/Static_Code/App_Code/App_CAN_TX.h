/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_BCAN_TX_H
#define  App_BCAN_TX_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/


/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/
typedef enum
{
/* enum WPCIndCmdState */
	cIndCmdState_Default,
	cIndCmdState_ChrgOff,
	cIndCmdState_1stChrgFadeIn,
	cIndCmdState_1stChrgOn,
	cIndCmdState_2ndChrgFadeIn,
	cIndCmdState_2ndChrgOn,
	cIndCmdState_3rdChrgFadeIn,
	cIndCmdState_3rdChrgOn,
	cIndCmdState_ChrgFadeOut,
	cIndCmdState_ErrorFadeIn,
	cIndCmdState_ErrorOn,
	cIndCmdState_ErrorFadeOut
} WPCIndCmdState_STATE;


/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/


/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/
extern void gs_CAN_TX_L2H_Set(void);
extern void gs_CAN_TX_H2L_Set(void);

#endif
