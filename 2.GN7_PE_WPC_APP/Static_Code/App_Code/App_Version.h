/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_VERSION_H
#define  App_VERSION_H

#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일


/* 0108_14 */
typedef struct
{
  /* offset of Address
   *
   *   +----------------+-------------------+---------------+---------------------------------------------------+
   *   | magicNumber(4) | currentVersion(5) | reserved(247) |                 Reserved for FBL                  |
   *   +----------------+-------------------+---------------+---------------------------------------------------+
   *   |<------------0x100 (App Data)---------------------->|<---------------0x100 (FBL Note)------------------>|
   */
  /* Magic Number 4-byte*/
  uint32 magicNumber;
  /* Current Version 4-byte */
  /* uint32 currentVersion; */	/* WPC_2418_04 */
  uint8 currentVersion[5];		/* WPC_2418_04 */
  /* Reserved for write unit 248-byte */
  /* uint8 reserved_1[248]; */	/* WPC_2418_04 */
  uint8 reserved_1[247];		/* WPC_2418_04 */
  /* Magic Number 4-byte*/
  uint32 previousVersion; /* This is reserved area, not including the App*/
  /* crcInit 2-byte */
  uint16 crcInit; /* This is reserved area, not including the App*/
  /* crcVal 2-byte */
  uint16 crcVal; /* This is reserved area, not including the App*/
  /* Reserved for write unit 248-byte */
  uint8 reserved_2[248]; /* This is reserved area, not including the App*/
} SW_BlkFlashInfo;
/* 0108_14 */

extern const SW_BlkFlashInfo App_SoftwareVersionHeader;

#endif
