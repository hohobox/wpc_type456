/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/


// Common Util Module
#ifndef  APP_COMMON_H
#define  APP_COMMON_H

/***************************************************************************************************
    INCLUDE FILES
***************************************************************************************************/

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/
/* OsTask_ASW_10ms */
// Can Event Signal Clear Time
#define Par_CanAutoClearTime	    (120u / TIME_10MS)  // GN7.0B_05 // 40ms cycle * 3회

#define Par_AutoClearTime_10ms	(10u / TIME_10MS)  //
#define Par_AutoClearTime_20ms	(20u / TIME_10MS)  //
#define Par_AutoClearTime_50ms	(50u / TIME_10MS)  //
#define Par_AutoClearTime_100ms	(100u / TIME_10MS)  //
/* OsTask_ASW_10ms */

/* OsTask_ASW_5ms */
// Can Event Signal Clear Time
#define Par_CanAutoClearTime_Task5ms	(120u / TIME_5MS)  // GN7.0B_05 // 40ms cycle * 3회

#define Par_AutoClearTime_10ms_Task5ms	(10u / TIME_5MS) // OsTask_ASW_5ms
#define Par_AutoClearTime_20ms_Task5ms	(20u / TIME_5MS) // OsTask_ASW_5ms
#define Par_AutoClearTime_50ms_Task5ms	(50u / TIME_5MS) // OsTask_ASW_5ms
#define Par_AutoClearTime_100ms_Task5ms	(100u / TIME_5MS) // OsTask_ASW_5ms
/* OsTask_ASW_5ms */

/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/
typedef struct  // event 형 변수 선언시 사용할것
{

    uint8_t previous;
    uint8_t On_Event;
    uint8_t Off_Event;
    uint8_t Old;
    uint16_t Count;
} Event_t;


typedef struct
{                             	/* 타이머 데이터 구조체                               */
    uint8_t Running;          /* 타이머가 활성화 되었는지를 알려주는 프래그         */
    uint16_t Count;          /* 타이머의 현재 값 (카운트 UP)                     */
} Timer_t;





/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/



/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/
void gs_UpdateEvent(uint8_t current, Event_t *event);
void gs_EventMsgAutoClear(uint8_t *current, Event_t *event, uint16_t ClearTime);

void gs_StartTimer (Timer_t *pTimer);
void gs_ReStartTimer (Timer_t *pTimer);
void gs_CancelTimer (Timer_t *pTimer);
void gs_InitTimer (Timer_t *pTimer, uint8_t Timer_Cnt_Max);
void gs_UpdateTimer (Timer_t *pTimer, uint8_t Timer_Cnt_Max);
// uint8_t gs_HexToAscii(uint8_t hex);
#endif
