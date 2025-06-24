/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/
#ifndef  App_NVM_H
#define  App_NVM_H

 
#include <stdint.h>         // uint8_t 선언 표준 헤더파일
#include <stdbool.h>        // bool 형 선언 표준 헤더파일
#include <stddef.h> // size_t 사용
#include "Define.h"
#include "App_Common.h"


/***************************************************************************************************
    GLOBAL DEFINES AND MACROS
***************************************************************************************************/

#define ECU_INFO_SIZE   17u
#define SERIAL_NUM_SIZE 15u     // spec max size 
#define QRCODE_SIZE     21u
#define WCT_VER_SIZE  3u

#define NVM_USER_RESERVED   8u		/* WPC_1904_02 */
#define PUBLICKEY_SIZE    260u		/* WPC_1908_01 */

// #define cNvm2BIdOffset	Rte_PDAV_NvMPS_NvMBlock_2BYTE_00_1			//건들지 말것. SWP의 Nv Block Base Number와 동일

#define PART_NUMBER_LENGTH 11  // "95560N1500\0" (10 chars + NULL)

#define cWPC_TYPE_Invalid       0u
#define cWPC_TYPE_1             1u
#define cWPC_TYPE_2             2u
#define cWPC_TYPE_3             3u
#define cWPC_TYPE_4             4u
#define cWPC_TYPE_5             5u
#define cWPC_TYPE_6             6u

#define cCOIL_NONE              0u
#define cCOIL_SINGLE            1u
#define cCOIL_DUAL              2u

#define cNFC_DISABLE            0u
#define cNFC_ENABLE             1u

#define cNAME_NONE              0u
#define cNAME_WPC               1u
#define cNAME_WPC2              2u
#define cNAME_RWPC              3u
#define cNAME_DWPC              4u

#define cCODE_NONE               0u
#define cCODE_GN7_PE             1u
#define cCODE_RX4_PE             2u
#define cCODE_MX5_PE             3u



/***************************************************************************************************
    GLOBAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

#define	NvM_BLK_ECU_INFO    0u
#define	NvM_BLK_SERIALNUM   1u



// NvMBlk1BInitVal[] 배열 순서와 동일하게 생성할것.
// 모빌젠 NvM 블럭 순서와 동일해야함
typedef enum
{
	BLK_NO_1B_ProfileGuestWPCUSM0,
    BLK_NO_1B_ProfileOneWPCUSM0,
    BLK_NO_1B_ProfileTwoWPCUSM0,
    BLK_NO_1B_ProfileThreeWPCUSM0,
    BLK_NO_1B_RWPCUSM0,
    BLK_NO_1B_ProfileGuestWPCUSM1,
    BLK_NO_1B_ProfileOneWPCUSM1,
    BLK_NO_1B_ProfileTwoWPCUSM1,
    BLK_NO_1B_ProfileThreeWPCUSM1,
    BLK_NO_1B_RWPCUSM1,
    BLK_NO_1B_AutoBrightSta,
    BLK_NO_1B_PDCReset,
    BLK_NO_1B_ANT_Calibration,
    BLK_NO_1B_B0BADisableCnt,
    BLK_NO_1B_WctReproRequest,
    BLK_NO_1B_Flag2,
    BLK_NO_1B_Flag3,
    BLK_NO_1B_Flag4,
    BLK_NO_1B_Flag5,
    BLK_NO_1B_Flag6,                    
	BLK_NO_1BYTE_MAX,
} NvM_BLK_1B_t;

typedef enum
{
	BLK_NO_ARR_ECU_Info,
    BLK_NO_ARR_SerialNum,
    BLK_NO_ARR_QRCode,
    BLK_NO_ARR_Var1,
    BLK_NO_ARR_Var2,
    BLK_NO_ARR_Var3,                 
	BLK_NO_ARRAY_MAX,
} NvM_BLK_ARRAY_t;

/* 0111_07 */
typedef struct {
    const char part_number[PART_NUMBER_LENGTH]; // 품번(예: "95560N1500")
    uint8_t vehicle_code;                      // Vehicle Code
    uint8_t nfc_status;                        // NFC 활성화 상태
    uint8_t wpc_type;                          // WPC 타입
    uint8_t coil_num;                          // 코일 개수 (SINGLE/DUAL)
    uint8_t wpc_name;                          // WPC Name
} part_number_info_t;


/***************************************************************************************************
    GLOBAL VARIABLE AND CONSTANTS DECLARATIONS
***************************************************************************************************/
extern const part_number_info_t part_number_db[];
extern const size_t part_number_count;
/* 0111_07 */
/***************************************************************************************************
    GLOBAL FUNCTION PROTOTYPES
***************************************************************************************************/

extern uint8_t NvMBlk_ECU_Info[ECU_INFO_SIZE];
extern uint8_t NvMBlk_SerialNum[SERIAL_NUM_SIZE];
extern uint8_t NvMBlk_QRCode[QRCODE_SIZE];
// extern uint8_t NvMBlk_WCT_SwVer[WCT_VER_SIZE];
/* NvM ram image buffer for 1byte blocks */
extern uint8_t NvMBlk_1B_Data[BLK_NO_1BYTE_MAX];

extern uint8_t NvMBlk_Array1[NVM_USER_RESERVED];	
extern uint8_t NvMBlk_Array2[NVM_USER_RESERVED];	
extern uint8_t NvMBlk_Array3[NVM_USER_RESERVED];	

extern uint8_t NvMBlk_PublicKeyForOEUK[PUBLICKEY_SIZE];	/* WPC_1908_01 */


// WPC_486_02
extern const uint8_t NvMBlk_1B_Init_0; // ProfileGuestWPCUSM0
extern const uint8_t NvMBlk_1B_Init_1; // ProfileOneWPCUSM0
extern const uint8_t NvMBlk_1B_Init_2; // ProfileTwoWPCUSM0
extern const uint8_t NvMBlk_1B_Init_3; // ProfileThreeWPCUSM0
extern const uint8_t NvMBlk_1B_Init_4; // RWPCUSM0

extern const uint8_t NvMBlk_1B_Init_5; // ProfileGuestWPCUSM1
extern const uint8_t NvMBlk_1B_Init_6; // ProfileOneWPCUSM1
extern const uint8_t NvMBlk_1B_Init_7; // ProfileTwoWPCUSM1
extern const uint8_t NvMBlk_1B_Init_8; // ProfileThreeWPCUSM1
extern const uint8_t NvMBlk_1B_Init_9; // RWPCUSM1

extern const uint8_t NvMBlk_1B_Init_10; // AutoBrightSta
extern const uint8_t NvMBlk_1B_Init_11; // PDCReset
extern const uint8_t NvMBlk_1B_Init_12; // ATN_Calibration
extern const uint8_t NvMBlk_1B_Init_13; // B0BADisableCnt
extern const uint8_t NvMBlk_1B_Init_14; // WctReproRequest

// 예비로 미리 할당해둠
extern const uint8_t NvMBlk_1B_Init_15; // Flag2
extern const uint8_t NvMBlk_1B_Init_16; // Flag3
extern const uint8_t NvMBlk_1B_Init_17; // Flag4
extern const uint8_t NvMBlk_1B_Init_18; // Flag5
extern const uint8_t NvMBlk_1B_Init_19; // Flag6

extern const uint8_t NvMBlkInitSting_ECUINFO[ECU_INFO_SIZE];
extern const uint8_t NvMBlkInitSting_SERNUMB[SERIAL_NUM_SIZE];
extern const uint8_t NvMBlkInitSting_QRCODE[QRCODE_SIZE];
//extern const uint8_t NvMBlkInitSting_WCTVER[WCT_VER_SIZE];

extern const uint8_t NvMBlkInitSting_Array1[NVM_USER_RESERVED];
extern const uint8_t NvMBlkInitSting_Array2[NVM_USER_RESERVED];
extern const uint8_t NvMBlkInitSting_Array3[NVM_USER_RESERVED];

// WPC_486_02

extern void gs_NvM_L2H_Set(void);
extern void gs_NvM_H2L_Set(void);
extern uint8_t gs_Get_NvM_WpcType(void);
extern uint8_t gs_Get_NvM_NfcOption(void);


#endif
