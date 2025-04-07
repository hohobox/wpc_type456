/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_ADC_H
#define  App_ADC_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/
// WPC_446_01 // 실측 전압으로 변경함 (5EA 샘플링 후 평균값 적용)
#define cSysBatValue_Low_Set_AD				(uint16_t)1629	/* 8.5V */
#define cSysBatValue_Low_Rst_AD				(uint16_t)1721	/* 9V */
#define cSysBatValue_High_Rst_AD			(uint16_t)3067	/* 16V */
#define cSysBatValue_High_Set_AD			(uint16_t)3164	/* 16.5V */

// WPC_446_01 // 실측 전압으로 변경함 (5EA 샘플링 후 평균값 적용)
#define cCanBatValue_Low_Set_AD				(uint16_t)1302	/* 6.8V */
#define cCanBatValue_Low_Rst_AD				(uint16_t)1341	/* 7V */
#define cCanBatValue_High_Rst_AD			(uint16_t)3454	/* 18V */
#define cCanBatValue_High_Set_AD			(uint16_t)3493	/* 18.2V */

#define cBAT_LOW_9V_AD                      (uint16_t)1721	/* 9V */

/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/




/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/


/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/

extern uint8_t gs_Get_ADC_IGN1_IN(void);


extern void gs_ADC_L2H_Set(void);
extern void gs_ADC_H2L_Set(void);
#endif
