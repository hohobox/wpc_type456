/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/

#ifndef  CDD_WCT_H
#define  CDD_WCT_H

/***************************************************************************************************
    INCLUDE FILES
***************************************************************************************************/

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include "Define.h"
#include "App_Common.h"

#include "EcuInfo.h"


/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/



/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

/*======================================================*/
/*      WPC Device State (WCT22C3)                               */
/*======================================================*/
typedef enum
{
    D0,
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
    D1,
//#endif    
    Device_MAX
}Device_ENUM_t;

typedef enum
{   
    cChargeStop     = 0x01u,
    cChargeStart    = 0x02u,
    cObjectDetect   = 0x03u,
    cPhoneLeft      = 0x04u
} UartCmd_t;

typedef enum
{
	cWCT_Disable,
	cWCT_Enable,
    cWCT_ObjectDetection,
    cWCT_CardProtection,
    cWCT_ProhibitBlink,
    cWCT_Charge,
	cWCT_Phone_Left,
    cWCT_Repro,
} WCTStatus_t;


/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/
//<<이곳에 선언한 GLOBAL VARIABLES은 타 파일에서 본 헤더파일을 include 시에는 extern이 생략된 참조 변수 선언이 된다.>>
//<<컴파일러에 따라서 글로벌 변수를 .c 파일에 선언해야 하는 경우가 있으나 .h파일에서 extern 없이 선언 해도>>
//<<정상으로 컴파일 된다면 중복 작성을 피하기 위해서 .c 파일에서 선언하지 않는 것을 추천함>>

// extern FunctionPtr pRte_Read_R_WCT[];

/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/
//<< 이곳에 선언한 GLOBAL FUNCTION PROTOTYPES은 타 파일에서 본 헤더파일을 include 시에는 extern이 생략된 참조 함수 선언이 된다.>>


//<<함수 설명 주석 기입하지 않는다>>


extern void gs_App_WCT_L2H_Set(void);
extern void gs_App_WCT_H2L_Set(void);




#endif  // CDD_WCT_H
