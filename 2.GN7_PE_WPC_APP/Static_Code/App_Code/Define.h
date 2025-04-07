/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2024 All Rights Reserved

***************************************************************************************************/

/* Common define header */
#ifndef		DEFINE_H
#define		DEFINE_H

#ifndef STOP
#define	STOP	        0U
#endif
#ifndef START
#define	START	        1U
#endif
/** redefine for easy to see in debugger */
typedef enum
{
    _STOP = STOP,
    _START = START
}STOP_START_t;

#ifndef OFF
#define	OFF	            0U
#endif
#ifndef ON
#define	ON	            1U
#endif
/** redefine for easy to see in debugger */
typedef enum
{
    _OFF = OFF,
    _ON = ON
}OFF_ON_t;


#ifndef NG
#define	NG	            0U
#endif
#ifndef OK
#define	OK	            1U
#endif
/** redefine for easy to see in debugger */
typedef enum
{
    _NG = NG,
    _OK = OK
}NG_OK_t;

#ifndef LOW
#define	LOW	            0U
#endif
#ifndef HIGH
#define	HIGH	        1U
#endif
/** redefine for easy to see in debugger */
typedef enum
{
    _LOW = LOW,
    _HIGH = HIGH
}LOW_HIGH_t;

#ifndef ENTRY
#define	ENTRY	        0U
#endif
#ifndef DURING
#define	DURING	        1U
#endif
#ifndef EXIT
#define	EXIT	        2U
#endif
typedef enum
{
    _ENTRY = ENTRY,
    _DURING = DURING,
    _EXIT = EXIT
}EN_DU_EX_t;


// 3 State flag
#ifndef DETECTED_DEFAULT
#define	DETECTED_DEFAULT    0U
#endif
#ifndef DETECTED_OFF
#define	DETECTED_OFF	    1U
#endif
#ifndef DETECTED_ON
#define	DETECTED_ON	        2U
#endif
#ifndef DETECTED_ERROR
#define	DETECTED_ERROR	    3U
#endif
/** redefine for easy to see in debugger */
typedef enum
{
    _DETECTED_DEFAULT = DETECTED_DEFAULT,
    _DETECTED_OFF = DETECTED_OFF,
    _DETECTED_ON = DETECTED_ON,
    _DETECTED_ERROR = DETECTED_ERROR,    
}TS_STATE_t;

// 함수 포인터 배열 선언
typedef void (*FunctionPtr)(int*);

#define TIME_5MS 		5u
#define TIME_10MS 		10u
#define TIME_100MS 		100u

#define MSB_MASK    0xFF00u
#define LSB_MASK    0x00FFu


#endif
